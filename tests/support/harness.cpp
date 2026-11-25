// Runs pinned TDLib functions on the requests that tests/support/harness.py sends.
//
// A request and a response are each a field count followed by that many fields, and a
// field is a 32-bit little-endian length followed by that many bytes. Each response is
// flushed before the next request is read, so a crash names the request that caused it.

#include "td/telegram/CustomEmojiId.h"
#include "td/telegram/FormattedDate.h"
#include "td/telegram/LinkManager.h"
#include "td/telegram/MessageEntity.h"
#include "td/telegram/misc.h"
#include "td/telegram/SynchronousRequests.h"
#include "td/telegram/td_api.h"
#include "td/telegram/telegram_api.h"
#include "td/telegram/TonWalletManager.h"
#include "td/telegram/UserId.h"
#include "td/telegram/UserManager.h"

#include "td/utils/algorithm.h"
#include "td/utils/base64.h"
#include "td/utils/crypto.h"
#include "td/utils/HttpUrl.h"
#include "td/utils/logging.h"
#include "td/utils/misc.h"
#include "td/utils/Parser.h"
#include "td/utils/port/IPAddress.h"
#include "td/utils/Slice.h"
#include "td/utils/SliceBuilder.h"
#include "td/utils/Status.h"
#include "td/utils/unicode.h"
#include "td/utils/utf8.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <string>
#include <vector>

namespace td {

// get_input_message_entities() and the overload of get_message_entities() for the
// entities Telegram returns call nothing else of a user manager, so these two functions
// alone of UserManager.cpp are defined here.

// A bot names a user it has not met by the user's ID alone
// (td/telegram/UserManager.cpp, UserManager::get_input_user()).
telegram_api::object_ptr<telegram_api::InputUser> UserManager::get_input_user_force(UserId user_id) const {
  return telegram_api::make_object<telegram_api::inputUser>(user_id.get(), 0);
}

// TDLib keeps a mention it reads back only for a user it has met, and the port reads
// each mention as for such a user, which leaves its survival to Telegram's backend.
bool UserManager::have_min_user(UserId /*user_id*/) const {
  return true;
}

// td/telegram/MessageEntity.cpp defines this overload, and no header declares it.
vector<MessageEntity> get_message_entities(const UserManager *user_manager,
                                           vector<tl_object_ptr<telegram_api::MessageEntity>> &&server_entities,
                                           const char *source);

}  // namespace td

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

// Reads a request of one field that holds one byte.
char read_code_unit(const Fields &request) {
  expect_fields(request, 1);
  if (request[0].size() != 1) {
    fail("a code unit field holds other than one byte");
  }
  return request[0][0];
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

// The user manager the conversions to and from Telegram's objects are given:
// get_input_user_force() and have_min_user(), the functions they call, read no member,
// so storage of the class's size stands in for an object never built.
alignas(td::UserManager) unsigned char user_manager_storage[sizeof(td::UserManager)];

const td::UserManager *bot_user_manager() {
  return reinterpret_cast<const td::UserManager *>(user_manager_storage);
}

// Reads a precision of a date or a time from its name, "" standing for none at all.
td::td_api::object_ptr<td::td_api::DateTimePartPrecision> read_precision(const std::string &field) {
  if (field.empty()) {
    return nullptr;
  }
  if (field == "none") {
    return td::td_api::make_object<td::td_api::dateTimePartPrecisionNone>();
  }
  if (field == "short") {
    return td::td_api::make_object<td::td_api::dateTimePartPrecisionShort>();
  }
  if (field == "long") {
    return td::td_api::make_object<td::td_api::dateTimePartPrecisionLong>();
  }
  fail("a precision field names no precision");
}

std::string write_precision(const td::td_api::DateTimePartPrecision *precision) {
  if (precision == nullptr) {
    return std::string();
  }
  switch (precision->get_id()) {
    case td::td_api::dateTimePartPrecisionNone::ID:
      return "none";
    case td::td_api::dateTimePartPrecisionShort::ID:
      return "short";
    case td::td_api::dateTimePartPrecisionLong::ID:
      return "long";
    default:
      fail("a precision has no name");
  }
}

// Reads a date format from the 4 fields from `first` on: the formatting type,
// "relative", "absolute", or "" for none; the precisions of the time and of the date;
// and whether the day of the week shows.
td::td_api::object_ptr<td::td_api::DateTimeFormattingType> read_formatting_type(const Fields &request,
                                                                                 std::size_t first) {
  const auto &kind = request[first];
  if (kind.empty()) {
    return nullptr;
  }
  if (kind == "relative") {
    return td::td_api::make_object<td::td_api::dateTimeFormattingTypeRelative>();
  }
  if (kind == "absolute") {
    return td::td_api::make_object<td::td_api::dateTimeFormattingTypeAbsolute>(
        read_precision(request[first + 1]), read_precision(request[first + 2]), to_flag(request[first + 3]));
  }
  fail("a formatting type field names no type");
}

void write_formatting_type(Fields &response, const td::td_api::DateTimeFormattingType *type) {
  if (type == nullptr) {
    response.insert(response.end(), {std::string(), std::string(), std::string(), from_flag(false)});
    return;
  }
  if (type->get_id() == td::td_api::dateTimeFormattingTypeRelative::ID) {
    response.insert(response.end(), {"relative", std::string(), std::string(), from_flag(false)});
    return;
  }
  auto absolute = static_cast<const td::td_api::dateTimeFormattingTypeAbsolute *>(type);
  response.insert(response.end(), {"absolute", write_precision(absolute->time_precision_.get()),
                                   write_precision(absolute->date_precision_.get()),
                                   from_flag(absolute->show_day_of_week_)});
}

// Reads the API objects of the entities that fill a request from field `first` on, 9
// fields each: the constructor of the type, "null" for a null type, or "" for a null
// entity; the offset and length; the language or link; the user ID, custom emoji ID,
// media timestamp, or Unix time; and the date format, as read_formatting_type() reads
// it.
td::vector<td::td_api::object_ptr<td::td_api::textEntity>> read_text_entities(const Fields &request,
                                                                              std::size_t first) {
  if (request.size() < first || (request.size() - first) % 9 != 0) {
    fail("a request holds the wrong number of fields");
  }
  td::vector<td::td_api::object_ptr<td::td_api::textEntity>> entities;
  for (auto i = first; i < request.size(); i += 9) {
    const auto &name = request[i];
    if (name.empty()) {
      entities.push_back(nullptr);
      continue;
    }
    const auto &text = request[i + 3];
    const auto &number = request[i + 4];
    td::td_api::object_ptr<td::td_api::TextEntityType> type;
    if (name == "null") {
    } else if (name == "textEntityTypeMention") {
      type = td::td_api::make_object<td::td_api::textEntityTypeMention>();
    } else if (name == "textEntityTypeHashtag") {
      type = td::td_api::make_object<td::td_api::textEntityTypeHashtag>();
    } else if (name == "textEntityTypeCashtag") {
      type = td::td_api::make_object<td::td_api::textEntityTypeCashtag>();
    } else if (name == "textEntityTypeBotCommand") {
      type = td::td_api::make_object<td::td_api::textEntityTypeBotCommand>();
    } else if (name == "textEntityTypeUrl") {
      type = td::td_api::make_object<td::td_api::textEntityTypeUrl>();
    } else if (name == "textEntityTypeEmailAddress") {
      type = td::td_api::make_object<td::td_api::textEntityTypeEmailAddress>();
    } else if (name == "textEntityTypePhoneNumber") {
      type = td::td_api::make_object<td::td_api::textEntityTypePhoneNumber>();
    } else if (name == "textEntityTypeBankCardNumber") {
      type = td::td_api::make_object<td::td_api::textEntityTypeBankCardNumber>();
    } else if (name == "textEntityTypeTonAddress") {
      type = td::td_api::make_object<td::td_api::textEntityTypeTonAddress>();
    } else if (name == "textEntityTypeBold") {
      type = td::td_api::make_object<td::td_api::textEntityTypeBold>();
    } else if (name == "textEntityTypeItalic") {
      type = td::td_api::make_object<td::td_api::textEntityTypeItalic>();
    } else if (name == "textEntityTypeUnderline") {
      type = td::td_api::make_object<td::td_api::textEntityTypeUnderline>();
    } else if (name == "textEntityTypeStrikethrough") {
      type = td::td_api::make_object<td::td_api::textEntityTypeStrikethrough>();
    } else if (name == "textEntityTypeSpoiler") {
      type = td::td_api::make_object<td::td_api::textEntityTypeSpoiler>();
    } else if (name == "textEntityTypeCode") {
      type = td::td_api::make_object<td::td_api::textEntityTypeCode>();
    } else if (name == "textEntityTypePre") {
      type = td::td_api::make_object<td::td_api::textEntityTypePre>();
    } else if (name == "textEntityTypePreCode") {
      type = td::td_api::make_object<td::td_api::textEntityTypePreCode>(text);
    } else if (name == "textEntityTypeBlockQuote") {
      type = td::td_api::make_object<td::td_api::textEntityTypeBlockQuote>();
    } else if (name == "textEntityTypeExpandableBlockQuote") {
      type = td::td_api::make_object<td::td_api::textEntityTypeExpandableBlockQuote>();
    } else if (name == "textEntityTypeTextUrl") {
      type = td::td_api::make_object<td::td_api::textEntityTypeTextUrl>(text);
    } else if (name == "textEntityTypeMentionName") {
      type = td::td_api::make_object<td::td_api::textEntityTypeMentionName>(to_int64(number));
    } else if (name == "textEntityTypeCustomEmoji") {
      type = td::td_api::make_object<td::td_api::textEntityTypeCustomEmoji>(to_int64(number));
    } else if (name == "textEntityTypeMediaTimestamp") {
      type = td::td_api::make_object<td::td_api::textEntityTypeMediaTimestamp>(to_int32(number));
    } else if (name == "textEntityTypeDateTime") {
      type = td::td_api::make_object<td::td_api::textEntityTypeDateTime>(to_int32(number),
                                                                         read_formatting_type(request, i + 5));
    } else {
      fail("an entity type field names no type");
    }
    auto offset = to_int32(request[i + 1]);
    auto length = to_int32(request[i + 2]);
    entities.push_back(td::td_api::make_object<td::td_api::textEntity>(offset, length, std::move(type)));
  }
  return entities;
}

// Writes the API object of each entity as 9 fields, as read_text_entities() reads them.
void write_text_entities(Fields &response, const td::vector<td::td_api::object_ptr<td::td_api::textEntity>> &entities) {
  for (auto &entity : entities) {
    if (entity == nullptr || entity->type_ == nullptr) {
      fail("an entity to write is null or has a null type");
    }
    std::string name;
    std::string text;
    td::int64 number = 0;
    const td::td_api::DateTimeFormattingType *formatting_type = nullptr;
    auto *type = entity->type_.get();
    switch (type->get_id()) {
      case td::td_api::textEntityTypeMention::ID:
        name = "textEntityTypeMention";
        break;
      case td::td_api::textEntityTypeHashtag::ID:
        name = "textEntityTypeHashtag";
        break;
      case td::td_api::textEntityTypeCashtag::ID:
        name = "textEntityTypeCashtag";
        break;
      case td::td_api::textEntityTypeBotCommand::ID:
        name = "textEntityTypeBotCommand";
        break;
      case td::td_api::textEntityTypeUrl::ID:
        name = "textEntityTypeUrl";
        break;
      case td::td_api::textEntityTypeEmailAddress::ID:
        name = "textEntityTypeEmailAddress";
        break;
      case td::td_api::textEntityTypePhoneNumber::ID:
        name = "textEntityTypePhoneNumber";
        break;
      case td::td_api::textEntityTypeBankCardNumber::ID:
        name = "textEntityTypeBankCardNumber";
        break;
      case td::td_api::textEntityTypeTonAddress::ID:
        name = "textEntityTypeTonAddress";
        break;
      case td::td_api::textEntityTypeBold::ID:
        name = "textEntityTypeBold";
        break;
      case td::td_api::textEntityTypeItalic::ID:
        name = "textEntityTypeItalic";
        break;
      case td::td_api::textEntityTypeUnderline::ID:
        name = "textEntityTypeUnderline";
        break;
      case td::td_api::textEntityTypeStrikethrough::ID:
        name = "textEntityTypeStrikethrough";
        break;
      case td::td_api::textEntityTypeSpoiler::ID:
        name = "textEntityTypeSpoiler";
        break;
      case td::td_api::textEntityTypeCode::ID:
        name = "textEntityTypeCode";
        break;
      case td::td_api::textEntityTypePre::ID:
        name = "textEntityTypePre";
        break;
      case td::td_api::textEntityTypePreCode::ID:
        name = "textEntityTypePreCode";
        text = static_cast<const td::td_api::textEntityTypePreCode *>(type)->language_;
        break;
      case td::td_api::textEntityTypeBlockQuote::ID:
        name = "textEntityTypeBlockQuote";
        break;
      case td::td_api::textEntityTypeExpandableBlockQuote::ID:
        name = "textEntityTypeExpandableBlockQuote";
        break;
      case td::td_api::textEntityTypeTextUrl::ID:
        name = "textEntityTypeTextUrl";
        text = static_cast<const td::td_api::textEntityTypeTextUrl *>(type)->url_;
        break;
      case td::td_api::textEntityTypeMentionName::ID:
        name = "textEntityTypeMentionName";
        number = static_cast<const td::td_api::textEntityTypeMentionName *>(type)->user_id_;
        break;
      case td::td_api::textEntityTypeCustomEmoji::ID:
        name = "textEntityTypeCustomEmoji";
        number = static_cast<const td::td_api::textEntityTypeCustomEmoji *>(type)->custom_emoji_id_;
        break;
      case td::td_api::textEntityTypeMediaTimestamp::ID:
        name = "textEntityTypeMediaTimestamp";
        number = static_cast<const td::td_api::textEntityTypeMediaTimestamp *>(type)->media_timestamp_;
        break;
      case td::td_api::textEntityTypeDateTime::ID: {
        auto date_time = static_cast<const td::td_api::textEntityTypeDateTime *>(type);
        name = "textEntityTypeDateTime";
        number = date_time->unix_time_;
        formatting_type = date_time->formatting_type_.get();
        break;
      }
      default:
        fail("an entity type has no name");
    }
    response.insert(response.end(), {name, std::to_string(entity->offset_), std::to_string(entity->length_), text,
                                     std::to_string(number)});
    write_formatting_type(response, formatting_type);
  }
}

// Writes each entity TDLib sends as 6 fields: its constructor, offset, and length; its
// language or link; the user it mentions, the custom emoji it shows, or its date; and
// whether a blockquote is collapsed, or the parts a date shows, as FormattedDate's
// flags.
void write_input_message_entities(
    Fields &response, const td::vector<td::telegram_api::object_ptr<td::telegram_api::MessageEntity>> &entities) {
  auto write = [&response](const char *name, td::int32 offset, td::int32 length, const std::string &text,
                           td::int64 number, td::int32 flags) {
    response.insert(response.end(), {name, std::to_string(offset), std::to_string(length), text, std::to_string(number),
                                     std::to_string(flags)});
  };
  for (auto &entity : entities) {
    switch (entity->get_id()) {
      case td::telegram_api::messageEntityBold::ID: {
        auto e = static_cast<const td::telegram_api::messageEntityBold *>(entity.get());
        write("messageEntityBold", e->offset_, e->length_, std::string(), 0, 0);
        break;
      }
      case td::telegram_api::messageEntityItalic::ID: {
        auto e = static_cast<const td::telegram_api::messageEntityItalic *>(entity.get());
        write("messageEntityItalic", e->offset_, e->length_, std::string(), 0, 0);
        break;
      }
      case td::telegram_api::messageEntityUnderline::ID: {
        auto e = static_cast<const td::telegram_api::messageEntityUnderline *>(entity.get());
        write("messageEntityUnderline", e->offset_, e->length_, std::string(), 0, 0);
        break;
      }
      case td::telegram_api::messageEntityStrike::ID: {
        auto e = static_cast<const td::telegram_api::messageEntityStrike *>(entity.get());
        write("messageEntityStrike", e->offset_, e->length_, std::string(), 0, 0);
        break;
      }
      case td::telegram_api::messageEntitySpoiler::ID: {
        auto e = static_cast<const td::telegram_api::messageEntitySpoiler *>(entity.get());
        write("messageEntitySpoiler", e->offset_, e->length_, std::string(), 0, 0);
        break;
      }
      case td::telegram_api::messageEntityCode::ID: {
        auto e = static_cast<const td::telegram_api::messageEntityCode *>(entity.get());
        write("messageEntityCode", e->offset_, e->length_, std::string(), 0, 0);
        break;
      }
      case td::telegram_api::messageEntityPre::ID: {
        auto e = static_cast<const td::telegram_api::messageEntityPre *>(entity.get());
        write("messageEntityPre", e->offset_, e->length_, e->language_, 0, 0);
        break;
      }
      case td::telegram_api::messageEntityTextUrl::ID: {
        auto e = static_cast<const td::telegram_api::messageEntityTextUrl *>(entity.get());
        write("messageEntityTextUrl", e->offset_, e->length_, e->url_, 0, 0);
        break;
      }
      case td::telegram_api::inputMessageEntityMentionName::ID: {
        auto e = static_cast<const td::telegram_api::inputMessageEntityMentionName *>(entity.get());
        if (e->user_id_ == nullptr || e->user_id_->get_id() != td::telegram_api::inputUser::ID) {
          fail("a mention names its user other than by ID");
        }
        auto user_id = static_cast<const td::telegram_api::inputUser *>(e->user_id_.get())->user_id_;
        write("inputMessageEntityMentionName", e->offset_, e->length_, std::string(), user_id, 0);
        break;
      }
      case td::telegram_api::messageEntityCustomEmoji::ID: {
        auto e = static_cast<const td::telegram_api::messageEntityCustomEmoji *>(entity.get());
        write("messageEntityCustomEmoji", e->offset_, e->length_, std::string(), e->document_id_, 0);
        break;
      }
      case td::telegram_api::messageEntityBlockquote::ID: {
        auto e = static_cast<const td::telegram_api::messageEntityBlockquote *>(entity.get());
        write("messageEntityBlockquote", e->offset_, e->length_, std::string(), 0, e->collapsed_ ? 1 : 0);
        break;
      }
      case td::telegram_api::messageEntityFormattedDate::ID: {
        auto e = static_cast<const td::telegram_api::messageEntityFormattedDate *>(entity.get());
        td::int32 flags = (e->relative_ ? 1 : 0) | (e->short_time_ ? 2 : 0) | (e->long_time_ ? 4 : 0) |
                          (e->short_date_ ? 8 : 0) | (e->long_date_ ? 16 : 0) | (e->day_of_week_ ? 32 : 0);
        write("messageEntityFormattedDate", e->offset_, e->length_, std::string(), e->date_, flags);
        break;
      }
      default:
        fail("a sent entity has no name");
    }
  }
}

// Reads the entities that fill a request from field `first` on, in the 6 fields that
// write_input_message_entities() writes an entity in; a mention is the
// messageEntityMentionName that Telegram returns, which names its user by ID alone.
td::vector<td::telegram_api::object_ptr<td::telegram_api::MessageEntity>> read_server_entities(const Fields &request,
                                                                                               std::size_t first) {
  if (request.size() < first || (request.size() - first) % 6 != 0) {
    fail("a request holds the wrong number of fields");
  }
  td::vector<td::telegram_api::object_ptr<td::telegram_api::MessageEntity>> entities;
  for (auto i = first; i < request.size(); i += 6) {
    auto &name = request[i];
    auto offset = to_int32(request[i + 1]);
    auto length = to_int32(request[i + 2]);
    auto &text = request[i + 3];
    auto number = to_int64(request[i + 4]);
    auto flags = to_int32(request[i + 5]);
    if (name == "messageEntityBold") {
      entities.push_back(td::telegram_api::make_object<td::telegram_api::messageEntityBold>(offset, length));
    } else if (name == "messageEntityItalic") {
      entities.push_back(td::telegram_api::make_object<td::telegram_api::messageEntityItalic>(offset, length));
    } else if (name == "messageEntityUnderline") {
      entities.push_back(td::telegram_api::make_object<td::telegram_api::messageEntityUnderline>(offset, length));
    } else if (name == "messageEntityStrike") {
      entities.push_back(td::telegram_api::make_object<td::telegram_api::messageEntityStrike>(offset, length));
    } else if (name == "messageEntitySpoiler") {
      entities.push_back(td::telegram_api::make_object<td::telegram_api::messageEntitySpoiler>(offset, length));
    } else if (name == "messageEntityCode") {
      entities.push_back(td::telegram_api::make_object<td::telegram_api::messageEntityCode>(offset, length));
    } else if (name == "messageEntityPre") {
      entities.push_back(td::telegram_api::make_object<td::telegram_api::messageEntityPre>(offset, length, text));
    } else if (name == "messageEntityTextUrl") {
      entities.push_back(td::telegram_api::make_object<td::telegram_api::messageEntityTextUrl>(offset, length, text));
    } else if (name == "messageEntityMentionName") {
      entities.push_back(
          td::telegram_api::make_object<td::telegram_api::messageEntityMentionName>(offset, length, number));
    } else if (name == "messageEntityCustomEmoji") {
      entities.push_back(
          td::telegram_api::make_object<td::telegram_api::messageEntityCustomEmoji>(offset, length, number));
    } else if (name == "messageEntityBlockquote") {
      entities.push_back(
          td::telegram_api::make_object<td::telegram_api::messageEntityBlockquote>(0, flags != 0, offset, length));
    } else if (name == "messageEntityFormattedDate") {
      entities.push_back(td::telegram_api::make_object<td::telegram_api::messageEntityFormattedDate>(
          0, (flags & 1) != 0, (flags & 2) != 0, (flags & 4) != 0, (flags & 8) != 0, (flags & 16) != 0,
          (flags & 32) != 0, offset, length, to_int32(request[i + 4])));
    } else {
      fail("a server entity has no name the harness reads");
    }
  }
  return entities;
}

// Reads the parse mode of a parseTextEntities request from the 2 fields from `first`
// on: 0 for none, 1 for HTML, or 2 for Markdown, then the version of Markdown.
td::td_api::object_ptr<td::td_api::TextParseMode> read_parse_mode(const Fields &request, std::size_t first) {
  switch (to_size(request[first])) {
    case 0:
      return nullptr;
    case 1:
      return td::td_api::make_object<td::td_api::textParseModeHTML>();
    case 2:
      return td::td_api::make_object<td::td_api::textParseModeMarkdown>(to_int32(request[first + 1]));
    default:
      fail("a parse mode field names no parse mode");
  }
}

// Reads the parse mode a bot names by its index among none, HTML, Markdown, and
// MarkdownV2, as the object Client::get_formatted_text() makes for it.
td::td_api::object_ptr<td::td_api::TextParseMode> read_bot_parse_mode(const std::string &field) {
  switch (to_size(field)) {
    case 0:
      return nullptr;
    case 1:
      return td::td_api::make_object<td::td_api::textParseModeHTML>();
    case 2:
      return td::td_api::make_object<td::td_api::textParseModeMarkdown>(1);
    case 3:
      return td::td_api::make_object<td::td_api::textParseModeMarkdown>(2);
    default:
      fail("a parse mode field names no parse mode");
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

// Answers a request for a base64 decoder: whether it decodes the text, the code and
// message of its error if not, and the bytes it decodes if so.
Fields run_base64_decode(td::Result<td::string> (*decode_f)(td::Slice), const Fields &request) {
  expect_fields(request, 1);
  auto r_decoded = decode_f(request[0]);
  if (r_decoded.is_error()) {
    return {from_flag(false), std::to_string(r_decoded.error().code()), r_decoded.error().message().str(),
            std::string()};
  }
  return {from_flag(true), "0", std::string(), r_decoded.move_as_ok()};
}

// Answers a request for to_integer<T>(): the number it reads from the text.
template <class T>
Fields run_to_integer(const Fields &request) {
  expect_fields(request, 1);
  return {std::to_string(td::to_integer<T>(request[0]))};
}

// Answers a request for to_integer_safe<T>(): whether it reads a number from the text,
// and the number.
template <class T>
Fields run_to_integer_safe(const Fields &request) {
  expect_fields(request, 1);
  auto r_value = td::to_integer_safe<T>(request[0]);
  if (r_value.is_error()) {
    return {from_flag(false), std::string()};
  }
  return {from_flag(true), std::to_string(r_value.ok())};
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
    auto c = static_cast<unsigned char>(read_code_unit(request));
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
  if (function == "remove_empty_entities") {
    auto entities = read_entities(request, 1);
    if (!request[0].empty()) {
      fail("remove_empty_entities takes no text");
    }
    td::remove_empty_entities(entities);
    Fields response;
    write_entities(response, entities);
    return response;
  }
  if (function == "fix_entities") {
    auto entities = read_entities(request, 1);
    if (!request[0].empty()) {
      fail("fix_entities takes no text");
    }
    td::fix_entities(entities);
    Fields response;
    write_entities(response, entities);
    return response;
  }
  if (function == "is_valid_user_id") {
    expect_fields(request, 2);
    return {from_flag(td::UserId(to_int64(request[1])).is_valid())};
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
  if (function == "append_utf8_character") {
    expect_fields(request, 2);
    auto text = request[0];
    td::append_utf8_character(text, static_cast<td::uint32>(to_size(request[1])));
    return {text};
  }
  if (function == "to_integer<int32>") {
    return run_to_integer<td::int32>(request);
  }
  if (function == "to_integer<int64>") {
    return run_to_integer<td::int64>(request);
  }
  if (function == "to_integer_safe<int32>") {
    return run_to_integer_safe<td::int32>(request);
  }
  if (function == "to_integer_safe<int64>") {
    return run_to_integer_safe<td::int64>(request);
  }
  if (function == "is_space") {
    return {from_flag(td::is_space(read_code_unit(request)))};
  }
  if (function == "is_alpha") {
    return {from_flag(td::is_alpha(read_code_unit(request)))};
  }
  if (function == "is_digit") {
    return {from_flag(td::is_digit(read_code_unit(request)))};
  }
  if (function == "is_alnum") {
    return {from_flag(td::is_alnum(read_code_unit(request)))};
  }
  if (function == "is_hex_digit") {
    return {from_flag(td::is_hex_digit(read_code_unit(request)))};
  }
  if (function == "hex_to_int") {
    return {std::to_string(td::hex_to_int(read_code_unit(request)))};
  }
  if (function == "to_lower") {
    return {std::string(1, td::to_lower(read_code_unit(request)))};
  }
  if (function == "trim") {
    expect_fields(request, 1);
    return {td::trim(td::Slice(request[0])).str()};
  }
  if (function == "read_till_nofail") {
    expect_fields(request, 3);
    // The characters that parse_url() reads till (tdutils/td/utils/HttpUrl.cpp,
    // parse_url()), by the index the request gives.
    static const char *const CHARACTER_SETS[] = {":/?#@[]", "/?#"};
    auto character_set = to_size(request[1]);
    if (character_set >= 2) {
      fail("a character set field names no set");
    }
    td::Slice text = request[0];
    // A position past the end stands for the end, so a request stays valid as its
    // text shrinks.
    auto pos = std::min(to_size(request[2]), text.size());
    td::ConstParser parser(text.substr(pos));
    auto slice = parser.read_till_nofail(td::Slice(CHARACTER_SETS[character_set]));
    return {std::to_string(slice.begin() - text.begin()), std::to_string(slice.end() - text.begin())};
  }
  if (function == "base64_decode") {
    return run_base64_decode(td::base64_decode, request);
  }
  if (function == "base64url_decode") {
    return run_base64_decode(td::base64url_decode, request);
  }
  if (function == "is_base64any_character") {
    return {from_flag(td::is_base64any_character(read_code_unit(request)))};
  }
  if (function == "crc16") {
    expect_fields(request, 1);
    return {std::to_string(td::crc16(request[0]))};
  }
  if (function == "combine") {
    expect_fields(request, 1);
    // The text holds the elements of the destination, a '|', then those of the source,
    // one byte each; without a '|', the source is empty.
    const auto &text = request[0];
    auto separator = std::min(text.find('|'), text.size());
    std::vector<char> destination(text.begin(), text.begin() + separator);
    std::vector<char> source(text.begin() + std::min(separator + 1, text.size()), text.end());
    td::combine(destination, std::move(source));
    return {std::string(destination.begin(), destination.end())};
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
  if (function == "init_ipv6_port") {
    expect_fields(request, 1);
    // parse_url() passes port 1 (tdutils/td/utils/HttpUrl.cpp).
    td::IPAddress ip_address;
    return {from_flag(ip_address.init_ipv6_port(request[0], 1).is_ok())};
  }
  if (function == "parse_url") {
    expect_fields(request, 1);
    auto r_url = td::parse_url(request[0]);
    if (r_url.is_error()) {
      return {from_flag(false), std::to_string(r_url.error().code()), r_url.error().message().str()};
    }
    auto url = r_url.move_as_ok();
    return {from_flag(true),
            std::to_string(static_cast<int>(url.protocol_)),
            url.userinfo_,
            url.host_,
            from_flag(url.is_ipv6_),
            std::to_string(url.specified_port_),
            std::to_string(url.port_),
            url.query_,
            url.get_url()};
  }
  if (function == "check_link") {
    expect_fields(request, 1);
    auto r_link = td::LinkManager::check_link(request[0]);
    if (r_link.is_error()) {
      return {std::to_string(r_link.error().code()), r_link.error().message().str(), std::string()};
    }
    return {"0", std::string(), r_link.move_as_ok()};
  }
  if (function == "get_checked_link") {
    expect_fields(request, 1);
    return {td::LinkManager::get_checked_link(request[0])};
  }
  if (function == "get_link_user_id") {
    expect_fields(request, 1);
    return {std::to_string(td::LinkManager::get_link_user_id(request[0]).get())};
  }
  if (function == "get_link_custom_emoji_id") {
    expect_fields(request, 1);
    auto r_custom_emoji_id = td::LinkManager::get_link_custom_emoji_id(request[0]);
    if (r_custom_emoji_id.is_error()) {
      return {std::to_string(r_custom_emoji_id.error().code()), r_custom_emoji_id.error().message().str(),
              std::string()};
    }
    return {"0", std::string(), std::to_string(r_custom_emoji_id.ok().get())};
  }
  if (function == "get_link_formatted_date") {
    expect_fields(request, 1);
    auto r_date = td::LinkManager::get_link_formatted_date(request[0]);
    if (r_date.is_error()) {
      return {std::to_string(r_date.error().code()), r_date.error().message().str(), std::string()};
    }
    return {"0", std::string(), PSTRING() << r_date.ok()};
  }
  if (function == "operator<<(MessageEntity::Type)") {
    expect_fields(request, 2);
    auto type = to_integer(request[1], 0, static_cast<td::int64>(td::MessageEntity::Type::Size) - 1);
    return {PSTRING() << static_cast<td::MessageEntity::Type>(type)};
  }
  if (function == "parse_markdown") {
    expect_fields(request, 1);
    auto text = request[0];
    auto r_entities = td::parse_markdown(text);
    if (r_entities.is_error()) {
      return {std::to_string(r_entities.error().code()), r_entities.error().message().str(), std::string()};
    }
    Fields response{"0", std::string(), text};
    write_entities(response, r_entities.ok());
    return response;
  }
  if (function == "parse_markdown_v2") {
    expect_fields(request, 1);
    auto text = request[0];
    auto r_entities = td::parse_markdown_v2(text);
    if (r_entities.is_error()) {
      return {std::to_string(r_entities.error().code()), r_entities.error().message().str(), std::string()};
    }
    Fields response{"0", std::string(), text};
    write_entities(response, r_entities.ok());
    return response;
  }
  if (function == "get_formatted_date") {
    expect_fields(request, 2);
    auto r_date = td::FormattedDate::get_formatted_date(to_int32(request[1]), request[0]);
    if (r_date.is_error()) {
      return {std::to_string(r_date.error().code()), r_date.error().message().str(), std::string()};
    }
    return {"0", std::string(), PSTRING() << r_date.ok()};
  }
  if (function == "parse_html") {
    expect_fields(request, 1);
    auto text = request[0];
    auto r_entities = td::parse_html(text);
    if (r_entities.is_error()) {
      return {std::to_string(r_entities.error().code()), r_entities.error().message().str(), std::string()};
    }
    Fields response{"0", std::string(), text};
    write_entities(response, r_entities.ok());
    return response;
  }
  if (function == "get_text_entities_object") {
    auto entities = read_entities(request, 1);
    if (!request[0].empty()) {
      fail("get_text_entities_object takes no text");
    }
    // As SynchronousRequests::do_request() calls it for parseTextEntities.
    Fields response;
    write_text_entities(response, td::get_text_entities_object(nullptr, entities, false, -1));
    return response;
  }
  if (function == "get_message_entities") {
    auto input_entities = read_text_entities(request, 1);
    if (!request[0].empty()) {
      fail("get_message_entities takes no text");
    }
    // Without a user manager, which a mention of a valid user passes as a bot's does.
    auto r_entities = td::get_message_entities(nullptr, std::move(input_entities), false);
    if (r_entities.is_error()) {
      return {std::to_string(r_entities.error().code()), r_entities.error().message().str()};
    }
    Fields response{"0", std::string()};
    write_entities(response, r_entities.ok());
    return response;
  }
  if (function == "get_message_entities(telegram_api)") {
    auto server_entities = read_server_entities(request, 1);
    if (!request[0].empty()) {
      fail("get_message_entities(telegram_api) takes no text");
    }
    Fields response;
    write_entities(response, td::get_message_entities(bot_user_manager(), std::move(server_entities), "harness"));
    return response;
  }
  if (function == "get_input_message_entities") {
    auto entities = read_entities(request, 1);
    if (!request[0].empty()) {
      fail("get_input_message_entities takes no text");
    }
    Fields response;
    write_input_message_entities(response, td::get_input_message_entities(bot_user_manager(), entities, "harness"));
    return response;
  }
  if (function == "run_request") {
    expect_fields(request, 3);
    // A parseTextEntities request for the text, in the parse mode the next fields name.
    auto result = td::SynchronousRequests::run_request(
        td::td_api::make_object<td::td_api::parseTextEntities>(request[0], read_parse_mode(request, 1)));
    if (result->get_id() == td::td_api::error::ID) {
      auto error = td::move_tl_object_as<td::td_api::error>(result);
      return {std::to_string(error->code_), error->message_, std::string()};
    }
    auto text = td::move_tl_object_as<td::td_api::formattedText>(result);
    Fields response{"0", std::string(), text->text_};
    write_text_entities(response, text->entities_);
    return response;
  }
  if (function == "send_message") {
    expect_fields(request, 3);
    // A bot's message text, through the pinned calls that the Bot API server and TDLib
    // make for it: a parseTextEntities request in the parse mode the bot names, or
    // none; the fixing of get_formatted_text(const Td *td, ...), which finds entities
    // of its own for a bot with one session and none for more; the length check of
    // create_input_message_content(); and the entities SendMessageQuery::send() sends.
    auto text = request[0];
    td::vector<td::td_api::object_ptr<td::td_api::textEntity>> text_entities;
    auto parse_mode = read_bot_parse_mode(request[1]);
    if (parse_mode != nullptr) {
      auto result = td::SynchronousRequests::run_request(
          td::td_api::make_object<td::td_api::parseTextEntities>(text, std::move(parse_mode)));
      if (result->get_id() == td::td_api::error::ID) {
        auto error = td::move_tl_object_as<td::td_api::error>(result);
        return {std::to_string(error->code_), error->message_, std::string()};
      }
      auto formatted_text = td::move_tl_object_as<td::td_api::formattedText>(result);
      text = std::move(formatted_text->text_);
      text_entities = std::move(formatted_text->entities_);
    }
    // A bot's user manager lets any valid user be named, and the parser names no other,
    // so no user manager checks them here.
    auto r_entities = td::get_message_entities(nullptr, std::move(text_entities), false);
    if (r_entities.is_error()) {
      return {std::to_string(r_entities.error().code()), r_entities.error().message().str(), std::string()};
    }
    auto entities = r_entities.move_as_ok();
    // A bot's chat is valid, so need_always_skip_bot_commands() is false, and the Bot API
    // server never sets the always_parse_markdown option.
    auto skip_new_entities = to_flag(request[2]);
    auto status =
        td::fix_formatted_text(text, entities, false, false, skip_new_entities, skip_new_entities, true, false);
    if (status.is_error()) {
      return {std::to_string(status.code()), status.message().str(), std::string()};
    }
    // remove_unallowed_entities() needs a Td, and it removes nothing from a bot's text. The
    // limit is the default of message_text_length_max (td/telegram/OptionManager.cpp,
    // OptionManager::OptionManager()).
    if (td::utf8_length(text) > 4096) {
      return {"400", "Message is too long", std::string()};
    }
    Fields response{"0", std::string(), text};
    write_input_message_entities(response, td::get_input_message_entities(bot_user_manager(), entities, "harness"));
    return response;
  }
  if (function == "get_formatted_date(td_api)") {
    expect_fields(request, 6);
    // The date, then the date format as read_formatting_type() reads it, by the index
    // of each value: no type, "relative", or "absolute"; no precision, "none", "short",
    // or "long"; and whether the day of the week shows.
    static const char *const TYPES[] = {"", "relative", "absolute"};
    static const char *const PRECISIONS[] = {"", "none", "short", "long"};
    auto type = to_size(request[2]);
    auto time_precision = to_size(request[3]);
    auto date_precision = to_size(request[4]);
    if (type >= 3 || time_precision >= 4 || date_precision >= 4) {
      fail("a date format field names no value");
    }
    Fields format{TYPES[type], PRECISIONS[time_precision], PRECISIONS[date_precision], request[5]};
    auto r_date = td::FormattedDate::get_formatted_date(to_int32(request[1]), read_formatting_type(format, 0));
    if (r_date.is_error()) {
      return {std::to_string(r_date.error().code()), r_date.error().message().str(), std::string()};
    }
    return {"0", std::string(), PSTRING() << r_date.ok()};
  }
  if (function == "get_date_time_formatting_type_object") {
    expect_fields(request, 2);
    // FormattedDate keeps its flags private, so its constructor for tests sets them.
    td::FormattedDate date(1, to_int32(request[1]));
    Fields response;
    write_formatting_type(response, date.get_date_time_formatting_type_object().get());
    return response;
  }
  fail("no such function");
}

// run_request() logs each request and its answer at INFO, the level the Bot API server
// logs at, which would add both to stderr for every request; warnings and errors still
// reach it.
class QuietLog final : public td::LogInterface {
 public:
  void do_append(int log_level, td::CSlice slice) final {
    if (log_level <= VERBOSITY_NAME(WARNING)) {
      td::default_log_interface->do_append(log_level, slice);
    }
  }
};

}  // namespace

int main(int argc, char **argv) {
  if (argc != 2) {
    fail("usage: harness <function>");
  }
  // The Bot API server logs at INFO for its in-memory log, whatever its verbosity
  // option (telegram-bot-api/telegram-bot-api.cpp, main()).
  SET_VERBOSITY_LEVEL(VERBOSITY_NAME(INFO));
  static QuietLog quiet_log;
  td::log_interface = &quiet_log;

  std::string function = argv[1];
  Fields request;
  while (read_request(request)) {
    write_response(run(function, request));
  }
}
