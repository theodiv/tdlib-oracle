// Runs pinned TDLib functions on the requests that tests/support/harness.py sends.
//
// A request and a response are each a field count followed by that many fields, and a
// field is a 32-bit little-endian length followed by that many bytes. Each response is
// flushed before the next request is read, so a crash names the request that caused it.
//
// MessageEntity.cpp is compiled here, as part of this file, instead of on its own, so
// that the functions it keeps static are in reach.

#include "td/telegram/MessageEntity.cpp"

#include "td/telegram/CustomEmojiId.h"
#include "td/telegram/FormattedDate.h"
#include "td/telegram/MessageEntity.h"
#include "td/telegram/misc.h"
#include "td/telegram/TonWalletManager.h"
#include "td/telegram/UserId.h"

#include "td/utils/base64.h"
#include "td/utils/logging.h"
#include "td/utils/Slice.h"
#include "td/utils/SliceBuilder.h"
#include "td/utils/Status.h"
#include "td/utils/unicode.h"
#include "td/utils/utf8.h"

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <limits>
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

// Reads a decimal number with an optional minus sign, which must lie within [min, max].
td::int64 to_integer(const std::string &field, td::int64 min, td::int64 max) {
  bool is_negative = !field.empty() && field[0] == '-';
  auto magnitude = static_cast<td::int64>(to_size(is_negative ? field.substr(1) : field));
  auto value = is_negative ? -magnitude : magnitude;
  if (value < min || value > max) {
    fail("a number field holds a number out of range");
  }
  return value;
}

td::int32 to_int32(const std::string &field) {
  return static_cast<td::int32>(
      to_integer(field, std::numeric_limits<td::int32>::min(), std::numeric_limits<td::int32>::max()));
}

td::int64 to_int64(const std::string &field) {
  return to_integer(field, std::numeric_limits<td::int64>::min(), std::numeric_limits<td::int64>::max());
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

// Reads the entities that fill a request from field `first` on, 8 fields each: the type,
// offset, length, argument, user ID, custom emoji ID, date, and date flags.
td::vector<td::MessageEntity> read_entities(const Fields &request, std::size_t first) {
  if (request.size() < first || (request.size() - first) % 8 != 0) {
    fail("a request holds the wrong number of fields");
  }
  td::vector<td::MessageEntity> entities;
  for (auto i = first; i < request.size(); i += 8) {
    auto type = to_integer(request[i], 0, static_cast<td::int64>(td::MessageEntity::Type::Size) - 1);
    td::MessageEntity entity(static_cast<td::MessageEntity::Type>(type), to_int32(request[i + 1]),
                             to_int32(request[i + 2]), request[i + 3]);
    entity.user_id = td::UserId(to_int64(request[i + 4]));
    entity.custom_emoji_id = td::CustomEmojiId(to_int64(request[i + 5]));
    entity.date = td::FormattedDate(to_int32(request[i + 6]), to_int32(request[i + 7]));
    entities.push_back(std::move(entity));
  }
  return entities;
}

// Writes each entity as 7 fields: the type, offset, length, argument, user ID, custom
// emoji ID, and the date as FormattedDate prints it, since it keeps its flags private.
void write_entities(Fields &response, const td::vector<td::MessageEntity> &entities) {
  for (auto &entity : entities) {
    response.push_back(std::to_string(static_cast<td::int32>(entity.type)));
    response.push_back(std::to_string(entity.offset));
    response.push_back(std::to_string(entity.length));
    response.push_back(entity.argument);
    response.push_back(std::to_string(entity.user_id.get()));
    response.push_back(std::to_string(entity.custom_emoji_id.get()));
    response.push_back(PSTRING() << entity.date);
  }
}

// Writes each slice of `text` as 2 fields: where it begins and where it ends, in bytes.
void write_slices(Fields &response, td::Slice text, const td::vector<td::Slice> &slices) {
  for (auto slice : slices) {
    response.push_back(std::to_string(slice.begin() - text.begin()));
    response.push_back(std::to_string(slice.end() - text.begin()));
  }
}

// Answers a request for one of the functions that find a kind of entity in a text.
Fields run_find(td::vector<td::Slice> (*find_f)(td::Slice), const Fields &request) {
  expect_fields(request, 1);
  Fields response;
  write_slices(response, request[0], find_f(request[0]));
  return response;
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
  if (function == "utf8_utf16_length") {
    expect_fields(request, 1);
    return {std::to_string(td::utf8_utf16_length(request[0]))};
  }
  if (function == "replace_offending_characters") {
    expect_fields(request, 1);
    auto text = request[0];
    td::replace_offending_characters(text);
    return {text};
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
  if (function == "sort_entities") {
    auto entities = read_entities(request, 1);
    if (!request[0].empty()) {
      fail("sort_entities takes no text");
    }
    td::sort_entities(entities);
    Fields response;
    write_entities(response, entities);
    return response;
  }
  if (function == "fix_formatted_text") {
    auto entities = read_entities(request, 6);
    auto text = request[0];
    auto allow_empty = to_flag(request[1]);
    auto allow_empty_string = to_flag(request[2]);
    auto skip_new_entities = to_flag(request[3]);
    auto skip_bot_commands = to_flag(request[4]);
    auto skip_trim = to_flag(request[5]);
    // A bot skips media timestamps (td/telegram/MessageEntity.cpp,
    // get_formatted_text()).
    auto status = td::fix_formatted_text(text, entities, allow_empty, allow_empty_string, skip_new_entities,
                                         skip_bot_commands, true, skip_trim);
    if (status.is_error()) {
      return {std::to_string(status.code()), status.message().str(), std::string()};
    }
    Fields response{"0", std::string(), text};
    write_entities(response, entities);
    return response;
  }
  if (function == "get_unicode_simple_category") {
    expect_fields(request, 2);
    auto code = static_cast<td::uint32>(to_size(request[1]));
    return {std::to_string(static_cast<int>(td::get_unicode_simple_category(code)))};
  }
  if (function == "unicode_to_lower") {
    expect_fields(request, 2);
    auto code = static_cast<td::uint32>(to_size(request[1]));
    return {std::to_string(td::unicode_to_lower(code))};
  }
  if (function == "next_utf8_unsafe") {
    expect_fields(request, 2);
    auto pos = to_size(request[1]);
    if (pos > request[0].size()) {
      fail("a position lies past the end of its text");
    }
    // At the end, the character read is the string terminator.
    auto begin = reinterpret_cast<const unsigned char *>(request[0].c_str());
    td::uint32 code = 0;
    auto next = td::next_utf8_unsafe(begin + pos, &code);
    return {std::to_string(next - begin), std::to_string(code)};
  }
  if (function == "prev_utf8_unsafe") {
    expect_fields(request, 2);
    auto pos = to_size(request[1]);
    if (pos == 0 || pos > request[0].size()) {
      fail("a position lies at the start of its text or past its end");
    }
    auto begin = reinterpret_cast<const unsigned char *>(request[0].c_str());
    return {std::to_string(td::prev_utf8_unsafe(begin + pos) - begin)};
  }
  if (function == "utf8_substr") {
    expect_fields(request, 2);
    return {td::utf8_substr(td::Slice(request[0]), to_size(request[1])).str()};
  }
  if (function == "utf8_to_lower") {
    expect_fields(request, 1);
    return {td::utf8_to_lower(request[0])};
  }
  if (function == "is_base64any_character") {
    expect_fields(request, 1);
    if (request[0].size() != 1) {
      fail("a code unit field holds other than one byte");
    }
    return {from_flag(td::is_base64any_character(request[0][0]))};
  }
  if (function == "check_ton_address") {
    expect_fields(request, 1);
    auto status = td::TonWalletManager::check_ton_address(request[0]);
    if (status.is_error()) {
      return {std::to_string(status.code()), status.message().str()};
    }
    return {"0", std::string()};
  }
  if (function == "find_mentions") {
    return run_find(td::find_mentions, request);
  }
  if (function == "find_bot_commands") {
    return run_find(td::find_bot_commands, request);
  }
  if (function == "find_hashtags") {
    return run_find(td::find_hashtags, request);
  }
  if (function == "find_cashtags") {
    return run_find(td::find_cashtags, request);
  }
  if (function == "find_bank_card_numbers") {
    return run_find(td::find_bank_card_numbers, request);
  }
  if (function == "find_ton_addresses") {
    return run_find(td::find_ton_addresses, request);
  }
  if (function == "find_tg_urls") {
    return run_find(td::find_tg_urls, request);
  }
  if (function == "find_urls") {
    expect_fields(request, 1);
    td::Slice text = request[0];
    Fields response;
    for (auto &url : td::find_urls(text)) {
      write_slices(response, text, {url.first});
      response.push_back(from_flag(url.second));
    }
    return response;
  }
  if (function == "is_email_address") {
    expect_fields(request, 1);
    return {from_flag(td::is_email_address(request[0]))};
  }
  if (function == "find_entities") {
    expect_fields(request, 2);
    // A bot skips media timestamps (td/telegram/MessageEntity.cpp,
    // get_formatted_text()).
    Fields response;
    write_entities(response, td::find_entities(request[0], to_flag(request[1]), true));
    return response;
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
