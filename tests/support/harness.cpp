// Runs pinned TDLib functions on the requests that tests/support/harness.py sends.
//
// A request and a response are each a field count followed by that many fields, and a
// field is a 32-bit little-endian length followed by that many bytes. Each response is
// flushed before the next request is read, so a crash names the request that caused it.

#include "td/telegram/MessageEntity.h"
#include "td/telegram/misc.h"

#include "td/utils/logging.h"
#include "td/utils/Slice.h"
#include "td/utils/Status.h"
#include "td/utils/utf8.h"

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

namespace {

using Fields = std::vector<std::string>;

[[noreturn]] void fail(const char *reason) {
  std::fprintf(stderr, "harness: %s\n", reason);
  std::exit(2);
}

std::uint32_t decode_size(const unsigned char *bytes) {
  std::uint32_t size = 0;
  for (int i = 3; i >= 0; i--) {
    size = size << 8 | bytes[i];
  }
  return size;
}

std::uint32_t read_size() {
  unsigned char bytes[4];
  if (std::fread(bytes, 1, 4, stdin) != 4) {
    fail("a request ends early");
  }
  return decode_size(bytes);
}

// The input may end only between two requests.
bool read_request(Fields &request) {
  unsigned char bytes[4];
  auto read = std::fread(bytes, 1, 4, stdin);
  if (read == 0 && std::feof(stdin)) {
    return false;
  }
  if (read != 4) {
    fail("a request ends early");
  }
  request.assign(decode_size(bytes), std::string());
  for (auto &field : request) {
    field.resize(read_size());
    auto size = field.size();
    if (size != 0 && std::fread(&field[0], 1, size, stdin) != size) {
      fail("a request ends early");
    }
  }
  return true;
}

void write_size(std::size_t size) {
  auto value = static_cast<std::uint32_t>(size);
  unsigned char bytes[4];
  for (int i = 0; i < 4; i++) {
    bytes[i] = static_cast<unsigned char>(value >> (8 * i));
  }
  std::fwrite(bytes, 1, 4, stdout);
}

void write_response(const Fields &response) {
  write_size(response.size());
  for (auto &field : response) {
    write_size(field.size());
    std::fwrite(field.data(), 1, field.size(), stdout);
  }
  if (std::fflush(stdout) != 0) {
    fail("stdout is closed");
  }
}

std::size_t to_size(const std::string &field) {
  if (field.empty() || field.size() > 18) {
    fail("a number field holds no number");
  }
  std::size_t value = 0;
  for (auto c : field) {
    if (c < '0' || c > '9') {
      fail("a number field holds no number");
    }
    value = value * 10 + static_cast<std::size_t>(c - '0');
  }
  return value;
}

bool to_flag(const std::string &field) {
  if (field != "0" && field != "1") {
    fail("a flag field holds neither 0 nor 1");
  }
  return field == "1";
}

std::string from_flag(bool value) {
  return value ? "1" : "0";
}

void expect_fields(const Fields &request, std::size_t count) {
  if (request.size() != count) {
    fail("a request holds the wrong number of fields");
  }
}

Fields run(const std::string &function, const Fields &request) {
  if (function == "check_utf8") {
    expect_fields(request, 1);
    return {from_flag(td::check_utf8(request[0]))};
  }
  if (function == "utf8_length") {
    expect_fields(request, 1);
    return {std::to_string(td::utf8_length(request[0]))};
  }
  if (function == "utf8_truncate") {
    expect_fields(request, 2);
    return {td::utf8_truncate(td::Slice(request[0]), to_size(request[1])).str()};
  }
  if (function == "is_utf8_character_first_code_unit") {
    expect_fields(request, 1);
    if (request[0].size() != 1) {
      fail("a code unit field holds other than one byte");
    }
    auto c = static_cast<unsigned char>(request[0][0]);
    return {from_flag(td::is_utf8_character_first_code_unit(c))};
  }
  if (function == "clean_input_string") {
    expect_fields(request, 1);
    auto text = request[0];
    if (!td::clean_input_string(text)) {
      return {from_flag(false), std::string()};
    }
    return {from_flag(true), text};
  }
  if (function == "strip_empty_characters") {
    expect_fields(request, 3);
    auto max_length = to_size(request[1]);
    return {td::strip_empty_characters(request[0], max_length, to_flag(request[2]))};
  }
  if (function == "is_empty_string") {
    expect_fields(request, 1);
    return {from_flag(td::is_empty_string(request[0]))};
  }
  if (function == "fix_formatted_text") {
    expect_fields(request, 4);
    auto text = request[0];
    td::vector<td::MessageEntity> entities;
    auto allow_empty = to_flag(request[1]);
    auto allow_empty_string = to_flag(request[2]);
    auto skip_trim = to_flag(request[3]);
    // A bot skips media timestamps (td/telegram/MessageEntity.cpp,
    // get_formatted_text()). New entities are skipped too, as for a bot with more
    // than one session: they change no text, and a plain text has no entity for them
    // to split.
    auto status = td::fix_formatted_text(
        text, entities, allow_empty, allow_empty_string, true, true, true, skip_trim);
    if (status.is_error()) {
      return {std::to_string(status.code()), status.message().str(), std::string()};
    }
    return {"0", std::string(), text};
  }
  fail("no such function");
}

}  // namespace

int main(int argc, char **argv) {
  if (argc != 2) {
    fail("usage: harness <function>");
  }
  // The Bot API server logs at INFO for its in-memory log, whatever its verbosity
  // option (telegram-bot-api/telegram-bot-api.cpp, main()).
  SET_VERBOSITY_LEVEL(VERBOSITY_NAME(INFO));

  std::string function = argv[1];
  Fields request;
  while (read_request(request)) {
    write_response(run(function, request));
  }
}
