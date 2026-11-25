#include "telegram_api.h"

#include "td/tl/tl_object_parse.h"
#include "td/tl/tl_object_store.h"

#include "td/utils/common.h"
#include "td/utils/format.h"
#include "td/utils/logging.h"
#include "td/utils/SliceBuilder.h"
#include "td/utils/tl_parsers.h"
#include "td/utils/tl_storers.h"
#include "td/utils/TlStorerToString.h"

namespace td {
namespace telegram_api {


const std::int32_t accessPointRule::ID;

object_ptr<accessPointRule> accessPointRule::fetch(TlBufferParser &p) {
  return make_tl_object<accessPointRule>(p);
}

accessPointRule::accessPointRule(TlBufferParser &p)
  : phone_prefix_rules_(TlFetchString<string>::parse(p))
  , dc_id_(TlFetchInt::parse(p))
  , ips_(TlFetchVector<TlFetchObject<IpPort>>::parse(p))
{}

void accessPointRule::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accessPointRule");
    s.store_field("phone_prefix_rules", phone_prefix_rules_);
    s.store_field("dc_id", dc_id_);
    { s.store_vector_begin("ips", ips_.size()); for (const auto &_value : ips_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t attachMenuBotsBot::ID;

object_ptr<attachMenuBotsBot> attachMenuBotsBot::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuBotsBot>(p);
}

attachMenuBotsBot::attachMenuBotsBot(TlBufferParser &p)
  : bot_(TlFetchBoxed<TlFetchObject<attachMenuBot>, -653423106>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void attachMenuBotsBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBotsBot");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t botVerification::ID;

object_ptr<botVerification> botVerification::fetch(TlBufferParser &p) {
  return make_tl_object<botVerification>(p);
}

botVerification::botVerification(TlBufferParser &p)
  : bot_id_(TlFetchLong::parse(p))
  , icon_(TlFetchLong::parse(p))
  , description_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
{}

void botVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botVerification");
    s.store_field("bot_id", bot_id_);
    s.store_field("icon", icon_);
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_class_end();
  }
}

dcOption::dcOption()
  : flags_()
  , ipv6_()
  , media_only_()
  , tcpo_only_()
  , cdn_()
  , static_()
  , this_port_only_()
  , id_()
  , ip_address_()
  , port_()
  , secret_()
{}

const std::int32_t dcOption::ID;

object_ptr<dcOption> dcOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<dcOption> res = make_tl_object<dcOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->ipv6_ = (var0 & 1) != 0;
  res->media_only_ = (var0 & 2) != 0;
  res->tcpo_only_ = (var0 & 4) != 0;
  res->cdn_ = (var0 & 8) != 0;
  res->static_ = (var0 & 16) != 0;
  res->this_port_only_ = (var0 & 32) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->ip_address_ = TlFetchString<string>::parse(p);
  res->port_ = TlFetchInt::parse(p);
  if (var0 & 1024) { res->secret_ = TlFetchBytes<bytes>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void dcOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dcOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (ipv6_ << 0) | (media_only_ << 1) | (tcpo_only_ << 2) | (cdn_ << 3) | (static_ << 4) | (this_port_only_ << 5) | ((!secret_.empty()) << 10)));
    if (var0 & 1) { s.store_field("ipv6", true); }
    if (var0 & 2) { s.store_field("media_only", true); }
    if (var0 & 4) { s.store_field("tcpo_only", true); }
    if (var0 & 8) { s.store_field("cdn", true); }
    if (var0 & 16) { s.store_field("static", true); }
    if (var0 & 32) { s.store_field("this_port_only", true); }
    s.store_field("id", id_);
    s.store_field("ip_address", ip_address_);
    s.store_field("port", port_);
    if (var0 & 1024) { s.store_field("secret", "[REDACTED]"); }
    s.store_class_end();
  }
}

const std::int32_t dialogFilterSuggested::ID;

object_ptr<dialogFilterSuggested> dialogFilterSuggested::fetch(TlBufferParser &p) {
  return make_tl_object<dialogFilterSuggested>(p);
}

dialogFilterSuggested::dialogFilterSuggested(TlBufferParser &p)
  : filter_(TlFetchObject<DialogFilter>::parse(p))
  , description_(TlFetchString<string>::parse(p))
{}

void dialogFilterSuggested::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogFilterSuggested");
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("description", description_);
    s.store_class_end();
  }
}

object_ptr<DraftMessage> DraftMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case draftMessageEmpty::ID:
      return draftMessageEmpty::fetch(p);
    case draftMessage::ID:
      return draftMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

draftMessageEmpty::draftMessageEmpty()
  : flags_()
  , date_()
  , ai_style_()
{}

const std::int32_t draftMessageEmpty::ID;

object_ptr<DraftMessage> draftMessageEmpty::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<draftMessageEmpty> res = make_tl_object<draftMessageEmpty>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->date_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->ai_style_ = TlFetchBoxed<TlFetchObject<inputAiComposeStyle>, -1474231824>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void draftMessageEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessageEmpty");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((ai_style_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("date", date_); }
    if (var0 & 2) { s.store_object_field("ai_style", static_cast<const BaseObject *>(ai_style_.get())); }
    s.store_class_end();
  }
}

draftMessage::draftMessage()
  : flags_()
  , no_webpage_()
  , invert_media_()
  , reply_to_()
  , message_()
  , entities_()
  , media_()
  , date_()
  , effect_()
  , suggested_post_()
  , rich_message_()
  , ai_style_()
{}

const std::int32_t draftMessage::ID;

object_ptr<DraftMessage> draftMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<draftMessage> res = make_tl_object<draftMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->no_webpage_ = (var0 & 2) != 0;
  res->invert_media_ = (var0 & 64) != 0;
  if (var0 & 16) { res->reply_to_ = TlFetchObject<InputReplyTo>::parse(p); }
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 8) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 32) { res->media_ = TlFetchObject<InputMedia>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 128) { res->effect_ = TlFetchLong::parse(p); }
  if (var0 & 256) { res->suggested_post_ = TlFetchBoxed<TlFetchObject<suggestedPost>, 244201445>::parse(p); }
  if (var0 & 512) { res->rich_message_ = TlFetchBoxed<TlFetchObject<richMessage>, -1158439541>::parse(p); }
  if (var0 & 1024) { res->ai_style_ = TlFetchBoxed<TlFetchObject<inputAiComposeStyle>, -1474231824>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void draftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 6) | ((reply_to_ != nullptr) << 4) | ((!entities_.empty()) << 3) | ((media_ != nullptr) << 5) | ((suggested_post_ != nullptr) << 8) | ((rich_message_ != nullptr) << 9) | ((ai_style_ != nullptr) << 10)));
    if (var0 & 2) { s.store_field("no_webpage", true); }
    if (var0 & 64) { s.store_field("invert_media", true); }
    if (var0 & 16) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_field("message", message_);
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    s.store_field("date", date_);
    if (var0 & 128) { s.store_field("effect", effect_); }
    if (var0 & 256) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    if (var0 & 512) { s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get())); }
    if (var0 & 1024) { s.store_object_field("ai_style", static_cast<const BaseObject *>(ai_style_.get())); }
    s.store_class_end();
  }
}

const std::int32_t exportedMessageLink::ID;

object_ptr<exportedMessageLink> exportedMessageLink::fetch(TlBufferParser &p) {
  return make_tl_object<exportedMessageLink>(p);
}

exportedMessageLink::exportedMessageLink(TlBufferParser &p)
  : link_(TlFetchString<string>::parse(p))
  , html_(TlFetchString<string>::parse(p))
{}

void exportedMessageLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "exportedMessageLink");
    s.store_field("link", link_);
    s.store_field("html", html_);
    s.store_class_end();
  }
}

globalPrivacySettings::globalPrivacySettings()
  : flags_()
  , archive_and_mute_new_noncontact_peers_()
  , keep_archived_unmuted_()
  , keep_archived_folders_()
  , hide_read_marks_()
  , new_noncontact_peers_require_premium_()
  , display_gifts_button_()
  , noncontact_peers_paid_stars_()
  , disallowed_gifts_()
{}

globalPrivacySettings::globalPrivacySettings(int32 flags_, bool archive_and_mute_new_noncontact_peers_, bool keep_archived_unmuted_, bool keep_archived_folders_, bool hide_read_marks_, bool new_noncontact_peers_require_premium_, bool display_gifts_button_, int64 noncontact_peers_paid_stars_, object_ptr<disallowedGiftsSettings> &&disallowed_gifts_)
  : flags_(flags_)
  , archive_and_mute_new_noncontact_peers_(archive_and_mute_new_noncontact_peers_)
  , keep_archived_unmuted_(keep_archived_unmuted_)
  , keep_archived_folders_(keep_archived_folders_)
  , hide_read_marks_(hide_read_marks_)
  , new_noncontact_peers_require_premium_(new_noncontact_peers_require_premium_)
  , display_gifts_button_(display_gifts_button_)
  , noncontact_peers_paid_stars_(noncontact_peers_paid_stars_)
  , disallowed_gifts_(std::move(disallowed_gifts_))
{}

const std::int32_t globalPrivacySettings::ID;

object_ptr<globalPrivacySettings> globalPrivacySettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<globalPrivacySettings> res = make_tl_object<globalPrivacySettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->archive_and_mute_new_noncontact_peers_ = (var0 & 1) != 0;
  res->keep_archived_unmuted_ = (var0 & 2) != 0;
  res->keep_archived_folders_ = (var0 & 4) != 0;
  res->hide_read_marks_ = (var0 & 8) != 0;
  res->new_noncontact_peers_require_premium_ = (var0 & 16) != 0;
  res->display_gifts_button_ = (var0 & 128) != 0;
  if (var0 & 32) { res->noncontact_peers_paid_stars_ = TlFetchLong::parse(p); }
  if (var0 & 64) { res->disallowed_gifts_ = TlFetchBoxed<TlFetchObject<disallowedGiftsSettings>, 1911715524>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void globalPrivacySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (archive_and_mute_new_noncontact_peers_ << 0) | (keep_archived_unmuted_ << 1) | (keep_archived_folders_ << 2) | (hide_read_marks_ << 3) | (new_noncontact_peers_require_premium_ << 4) | (display_gifts_button_ << 7) | ((disallowed_gifts_ != nullptr) << 6)), s);
  if (var0 & 32) { TlStoreBinary::store(noncontact_peers_paid_stars_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreObject, 1911715524>::store(disallowed_gifts_, s); }
}

void globalPrivacySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (archive_and_mute_new_noncontact_peers_ << 0) | (keep_archived_unmuted_ << 1) | (keep_archived_folders_ << 2) | (hide_read_marks_ << 3) | (new_noncontact_peers_require_premium_ << 4) | (display_gifts_button_ << 7) | ((disallowed_gifts_ != nullptr) << 6)), s);
  if (var0 & 32) { TlStoreBinary::store(noncontact_peers_paid_stars_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreObject, 1911715524>::store(disallowed_gifts_, s); }
}

void globalPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "globalPrivacySettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (archive_and_mute_new_noncontact_peers_ << 0) | (keep_archived_unmuted_ << 1) | (keep_archived_folders_ << 2) | (hide_read_marks_ << 3) | (new_noncontact_peers_require_premium_ << 4) | (display_gifts_button_ << 7) | ((disallowed_gifts_ != nullptr) << 6)));
    if (var0 & 1) { s.store_field("archive_and_mute_new_noncontact_peers", true); }
    if (var0 & 2) { s.store_field("keep_archived_unmuted", true); }
    if (var0 & 4) { s.store_field("keep_archived_folders", true); }
    if (var0 & 8) { s.store_field("hide_read_marks", true); }
    if (var0 & 16) { s.store_field("new_noncontact_peers_require_premium", true); }
    if (var0 & 128) { s.store_field("display_gifts_button", true); }
    if (var0 & 32) { s.store_field("noncontact_peers_paid_stars", noncontact_peers_paid_stars_); }
    if (var0 & 64) { s.store_object_field("disallowed_gifts", static_cast<const BaseObject *>(disallowed_gifts_.get())); }
    s.store_class_end();
  }
}

inputAiComposeStyle::inputAiComposeStyle()
  : flags_()
  , emojify_()
  , proofread_()
  , tone_()
  , to_lang_()
{}

inputAiComposeStyle::inputAiComposeStyle(int32 flags_, bool emojify_, bool proofread_, object_ptr<InputAiComposeTone> &&tone_, string const &to_lang_)
  : flags_(flags_)
  , emojify_(emojify_)
  , proofread_(proofread_)
  , tone_(std::move(tone_))
  , to_lang_(to_lang_)
{}

const std::int32_t inputAiComposeStyle::ID;

object_ptr<inputAiComposeStyle> inputAiComposeStyle::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputAiComposeStyle> res = make_tl_object<inputAiComposeStyle>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->emojify_ = (var0 & 4) != 0;
  res->proofread_ = (var0 & 8) != 0;
  if (var0 & 1) { res->tone_ = TlFetchObject<InputAiComposeTone>::parse(p); }
  if (var0 & 2) { res->to_lang_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void inputAiComposeStyle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (emojify_ << 2) | (proofread_ << 3) | ((tone_ != nullptr) << 0) | ((!to_lang_.empty()) << 1)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s); }
  if (var0 & 2) { TlStoreString::store(to_lang_, s); }
}

void inputAiComposeStyle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (emojify_ << 2) | (proofread_ << 3) | ((tone_ != nullptr) << 0) | ((!to_lang_.empty()) << 1)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s); }
  if (var0 & 2) { TlStoreString::store(to_lang_, s); }
}

void inputAiComposeStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputAiComposeStyle");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (emojify_ << 2) | (proofread_ << 3) | ((tone_ != nullptr) << 0) | ((!to_lang_.empty()) << 1)));
    if (var0 & 4) { s.store_field("emojify", true); }
    if (var0 & 8) { s.store_field("proofread", true); }
    if (var0 & 1) { s.store_object_field("tone", static_cast<const BaseObject *>(tone_.get())); }
    if (var0 & 2) { s.store_field("to_lang", to_lang_); }
    s.store_class_end();
  }
}

inputAppEvent::inputAppEvent(double time_, string const &type_, int64 peer_, object_ptr<JSONValue> &&data_)
  : time_(time_)
  , type_(type_)
  , peer_(peer_)
  , data_(std::move(data_))
{}

const std::int32_t inputAppEvent::ID;

object_ptr<inputAppEvent> inputAppEvent::fetch(TlBufferParser &p) {
  return make_tl_object<inputAppEvent>(p);
}

inputAppEvent::inputAppEvent(TlBufferParser &p)
  : time_(TlFetchDouble::parse(p))
  , type_(TlFetchString<string>::parse(p))
  , peer_(TlFetchLong::parse(p))
  , data_(TlFetchObject<JSONValue>::parse(p))
{}

void inputAppEvent::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(time_, s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(data_, s);
}

void inputAppEvent::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(time_, s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(data_, s);
}

void inputAppEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputAppEvent");
    s.store_field("time", time_);
    s.store_field("type", type_);
    s.store_field("peer", peer_);
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_class_end();
  }
}

inputBusinessIntro::inputBusinessIntro(int32 flags_, string const &title_, string const &description_, object_ptr<InputDocument> &&sticker_)
  : flags_(flags_)
  , title_(title_)
  , description_(description_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t inputBusinessIntro::ID;

void inputBusinessIntro::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((sticker_ != nullptr) << 0)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s); }
}

void inputBusinessIntro::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((sticker_ != nullptr) << 0)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s); }
}

void inputBusinessIntro::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessIntro");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((sticker_ != nullptr) << 0)));
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get())); }
    s.store_class_end();
  }
}

object_ptr<InputFile> InputFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputFile::ID:
      return inputFile::fetch(p);
    case inputFileBig::ID:
      return inputFileBig::fetch(p);
    case inputFileStoryDocument::ID:
      return inputFileStoryDocument::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputFile::inputFile(int64 id_, int32 parts_, string const &name_, string const &md5_checksum_)
  : id_(id_)
  , parts_(parts_)
  , name_(name_)
  , md5_checksum_(md5_checksum_)
{}

const std::int32_t inputFile::ID;

object_ptr<InputFile> inputFile::fetch(TlBufferParser &p) {
  return make_tl_object<inputFile>(p);
}

inputFile::inputFile(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , parts_(TlFetchInt::parse(p))
  , name_(TlFetchString<string>::parse(p))
  , md5_checksum_(TlFetchString<string>::parse(p))
{}

void inputFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(name_, s);
  TlStoreString::store(md5_checksum_, s);
}

void inputFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(name_, s);
  TlStoreString::store(md5_checksum_, s);
}

void inputFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFile");
    s.store_field("id", id_);
    s.store_field("parts", parts_);
    s.store_field("name", name_);
    s.store_field("md5_checksum", md5_checksum_);
    s.store_class_end();
  }
}

inputFileBig::inputFileBig(int64 id_, int32 parts_, string const &name_)
  : id_(id_)
  , parts_(parts_)
  , name_(name_)
{}

const std::int32_t inputFileBig::ID;

object_ptr<InputFile> inputFileBig::fetch(TlBufferParser &p) {
  return make_tl_object<inputFileBig>(p);
}

inputFileBig::inputFileBig(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , parts_(TlFetchInt::parse(p))
  , name_(TlFetchString<string>::parse(p))
{}

void inputFileBig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(name_, s);
}

void inputFileBig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(name_, s);
}

void inputFileBig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileBig");
    s.store_field("id", id_);
    s.store_field("parts", parts_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

inputFileStoryDocument::inputFileStoryDocument(object_ptr<InputDocument> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t inputFileStoryDocument::ID;

object_ptr<InputFile> inputFileStoryDocument::fetch(TlBufferParser &p) {
  return make_tl_object<inputFileStoryDocument>(p);
}

inputFileStoryDocument::inputFileStoryDocument(TlBufferParser &p)
  : id_(TlFetchObject<InputDocument>::parse(p))
{}

void inputFileStoryDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputFileStoryDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputFileStoryDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileStoryDocument");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

object_ptr<InputGroupCall> InputGroupCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputGroupCall::ID:
      return inputGroupCall::fetch(p);
    case inputGroupCallSlug::ID:
      return inputGroupCallSlug::fetch(p);
    case inputGroupCallInviteMessage::ID:
      return inputGroupCallInviteMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputGroupCall::inputGroupCall(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputGroupCall::ID;

object_ptr<InputGroupCall> inputGroupCall::fetch(TlBufferParser &p) {
  return make_tl_object<inputGroupCall>(p);
}

inputGroupCall::inputGroupCall(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCall");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputGroupCallSlug::inputGroupCallSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputGroupCallSlug::ID;

object_ptr<InputGroupCall> inputGroupCallSlug::fetch(TlBufferParser &p) {
  return make_tl_object<inputGroupCallSlug>(p);
}

inputGroupCallSlug::inputGroupCallSlug(TlBufferParser &p)
  : slug_(TlFetchString<string>::parse(p))
{}

void inputGroupCallSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputGroupCallSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputGroupCallSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCallSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

inputGroupCallInviteMessage::inputGroupCallInviteMessage(int32 msg_id_)
  : msg_id_(msg_id_)
{}

const std::int32_t inputGroupCallInviteMessage::ID;

object_ptr<InputGroupCall> inputGroupCallInviteMessage::fetch(TlBufferParser &p) {
  return make_tl_object<inputGroupCallInviteMessage>(p);
}

inputGroupCallInviteMessage::inputGroupCallInviteMessage(TlBufferParser &p)
  : msg_id_(TlFetchInt::parse(p))
{}

void inputGroupCallInviteMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
}

void inputGroupCallInviteMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
}

void inputGroupCallInviteMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCallInviteMessage");
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

inputMessageID::inputMessageID(int32 id_)
  : id_(id_)
{}

const std::int32_t inputMessageID::ID;

void inputMessageID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputMessageID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputMessageID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageID");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputMessageReplyTo::inputMessageReplyTo(int32 id_)
  : id_(id_)
{}

const std::int32_t inputMessageReplyTo::ID;

void inputMessageReplyTo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputMessageReplyTo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputMessageReplyTo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageReplyTo");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

const std::int32_t inputMessagePinned::ID;

void inputMessagePinned::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagePinned::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagePinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagePinned");
    s.store_class_end();
  }
}

inputMessageCallbackQuery::inputMessageCallbackQuery(int32 id_, int64 query_id_)
  : id_(id_)
  , query_id_(query_id_)
{}

const std::int32_t inputMessageCallbackQuery::ID;

void inputMessageCallbackQuery::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(query_id_, s);
}

void inputMessageCallbackQuery::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(query_id_, s);
}

void inputMessageCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageCallbackQuery");
    s.store_field("id", id_);
    s.store_field("query_id", query_id_);
    s.store_class_end();
  }
}

inputPhoneCall::inputPhoneCall(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputPhoneCall::ID;

void inputPhoneCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPhoneCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPhoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhoneCall");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputStickerSetItem::inputStickerSetItem(int32 flags_, object_ptr<InputDocument> &&document_, string const &emoji_, object_ptr<maskCoords> &&mask_coords_, string const &keywords_)
  : flags_(flags_)
  , document_(std::move(document_))
  , emoji_(emoji_)
  , mask_coords_(std::move(mask_coords_))
  , keywords_(keywords_)
{}

const std::int32_t inputStickerSetItem::ID;

void inputStickerSetItem::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((mask_coords_ != nullptr) << 0) | ((!keywords_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreString::store(emoji_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
  if (var0 & 2) { TlStoreString::store(keywords_, s); }
}

void inputStickerSetItem::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((mask_coords_ != nullptr) << 0) | ((!keywords_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreString::store(emoji_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
  if (var0 & 2) { TlStoreString::store(keywords_, s); }
}

void inputStickerSetItem::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetItem");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((mask_coords_ != nullptr) << 0) | ((!keywords_.empty()) << 1)));
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_field("emoji", emoji_);
    if (var0 & 1) { s.store_object_field("mask_coords", static_cast<const BaseObject *>(mask_coords_.get())); }
    if (var0 & 2) { s.store_field("keywords", keywords_); }
    s.store_class_end();
  }
}

inputStickeredMediaPhoto::inputStickeredMediaPhoto(object_ptr<InputPhoto> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t inputStickeredMediaPhoto::ID;

void inputStickeredMediaPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputStickeredMediaPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputStickeredMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickeredMediaPhoto");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

inputStickeredMediaDocument::inputStickeredMediaDocument(object_ptr<InputDocument> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t inputStickeredMediaDocument::ID;

void inputStickeredMediaDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputStickeredMediaDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputStickeredMediaDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickeredMediaDocument");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

inputWebDocument::inputWebDocument(string const &url_, int32 size_, string const &mime_type_, array<object_ptr<DocumentAttribute>> &&attributes_)
  : url_(url_)
  , size_(size_)
  , mime_type_(mime_type_)
  , attributes_(std::move(attributes_))
{}

const std::int32_t inputWebDocument::ID;

object_ptr<inputWebDocument> inputWebDocument::fetch(TlBufferParser &p) {
  return make_tl_object<inputWebDocument>(p);
}

inputWebDocument::inputWebDocument(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , size_(TlFetchInt::parse(p))
  , mime_type_(TlFetchString<string>::parse(p))
  , attributes_(TlFetchBoxed<TlFetchVector<TlFetchObject<DocumentAttribute>>, 481674261>::parse(p))
{}

void inputWebDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void inputWebDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void inputWebDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWebDocument");
    s.store_field("url", url_);
    s.store_field("size", size_);
    s.store_field("mime_type", mime_type_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

jsonObjectValue::jsonObjectValue(string const &key_, object_ptr<JSONValue> &&value_)
  : key_(key_)
  , value_(std::move(value_))
{}

const std::int32_t jsonObjectValue::ID;

object_ptr<jsonObjectValue> jsonObjectValue::fetch(TlBufferParser &p) {
  return make_tl_object<jsonObjectValue>(p);
}

jsonObjectValue::jsonObjectValue(TlBufferParser &p)
  : key_(TlFetchString<string>::parse(p))
  , value_(TlFetchObject<JSONValue>::parse(p))
{}

void jsonObjectValue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(key_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(value_, s);
}

void jsonObjectValue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(key_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(value_, s);
}

void jsonObjectValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonObjectValue");
    s.store_field("key", key_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

pageRelatedArticle::pageRelatedArticle()
  : flags_()
  , url_()
  , webpage_id_()
  , title_()
  , description_()
  , photo_id_()
  , author_()
  , published_date_()
{}

pageRelatedArticle::pageRelatedArticle(int32 flags_, string const &url_, int64 webpage_id_, string const &title_, string const &description_, int64 photo_id_, string const &author_, int32 published_date_)
  : flags_(flags_)
  , url_(url_)
  , webpage_id_(webpage_id_)
  , title_(title_)
  , description_(description_)
  , photo_id_(photo_id_)
  , author_(author_)
  , published_date_(published_date_)
{}

const std::int32_t pageRelatedArticle::ID;

object_ptr<pageRelatedArticle> pageRelatedArticle::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageRelatedArticle> res = make_tl_object<pageRelatedArticle>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->url_ = TlFetchString<string>::parse(p);
  res->webpage_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->description_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->photo_id_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->author_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->published_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void pageRelatedArticle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 0) | ((!description_.empty()) << 1) | ((!author_.empty()) << 3)), s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(description_, s); }
  if (var0 & 4) { TlStoreBinary::store(photo_id_, s); }
  if (var0 & 8) { TlStoreString::store(author_, s); }
  if (var0 & 16) { TlStoreBinary::store(published_date_, s); }
}

void pageRelatedArticle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 0) | ((!description_.empty()) << 1) | ((!author_.empty()) << 3)), s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(description_, s); }
  if (var0 & 4) { TlStoreBinary::store(photo_id_, s); }
  if (var0 & 8) { TlStoreString::store(author_, s); }
  if (var0 & 16) { TlStoreBinary::store(published_date_, s); }
}

void pageRelatedArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageRelatedArticle");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 0) | ((!description_.empty()) << 1) | ((!author_.empty()) << 3)));
    s.store_field("url", url_);
    s.store_field("webpage_id", webpage_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("description", description_); }
    if (var0 & 4) { s.store_field("photo_id", photo_id_); }
    if (var0 & 8) { s.store_field("author", author_); }
    if (var0 & 16) { s.store_field("published_date", published_date_); }
    s.store_class_end();
  }
}

object_ptr<PrivacyKey> PrivacyKey::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case privacyKeyStatusTimestamp::ID:
      return privacyKeyStatusTimestamp::fetch(p);
    case privacyKeyChatInvite::ID:
      return privacyKeyChatInvite::fetch(p);
    case privacyKeyPhoneCall::ID:
      return privacyKeyPhoneCall::fetch(p);
    case privacyKeyPhoneP2P::ID:
      return privacyKeyPhoneP2P::fetch(p);
    case privacyKeyForwards::ID:
      return privacyKeyForwards::fetch(p);
    case privacyKeyProfilePhoto::ID:
      return privacyKeyProfilePhoto::fetch(p);
    case privacyKeyPhoneNumber::ID:
      return privacyKeyPhoneNumber::fetch(p);
    case privacyKeyAddedByPhone::ID:
      return privacyKeyAddedByPhone::fetch(p);
    case privacyKeyVoiceMessages::ID:
      return privacyKeyVoiceMessages::fetch(p);
    case privacyKeyAbout::ID:
      return privacyKeyAbout::fetch(p);
    case privacyKeyBirthday::ID:
      return privacyKeyBirthday::fetch(p);
    case privacyKeyStarGiftsAutoSave::ID:
      return privacyKeyStarGiftsAutoSave::fetch(p);
    case privacyKeyNoPaidMessages::ID:
      return privacyKeyNoPaidMessages::fetch(p);
    case privacyKeySavedMusic::ID:
      return privacyKeySavedMusic::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t privacyKeyStatusTimestamp::ID;

object_ptr<PrivacyKey> privacyKeyStatusTimestamp::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyStatusTimestamp>();
}

void privacyKeyStatusTimestamp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyStatusTimestamp");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyChatInvite::ID;

object_ptr<PrivacyKey> privacyKeyChatInvite::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyChatInvite>();
}

void privacyKeyChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyChatInvite");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyPhoneCall::ID;

object_ptr<PrivacyKey> privacyKeyPhoneCall::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyPhoneCall>();
}

void privacyKeyPhoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyPhoneCall");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyPhoneP2P::ID;

object_ptr<PrivacyKey> privacyKeyPhoneP2P::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyPhoneP2P>();
}

void privacyKeyPhoneP2P::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyPhoneP2P");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyForwards::ID;

object_ptr<PrivacyKey> privacyKeyForwards::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyForwards>();
}

void privacyKeyForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyForwards");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyProfilePhoto::ID;

object_ptr<PrivacyKey> privacyKeyProfilePhoto::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyProfilePhoto>();
}

void privacyKeyProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyProfilePhoto");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyPhoneNumber::ID;

object_ptr<PrivacyKey> privacyKeyPhoneNumber::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyPhoneNumber>();
}

void privacyKeyPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyPhoneNumber");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyAddedByPhone::ID;

object_ptr<PrivacyKey> privacyKeyAddedByPhone::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyAddedByPhone>();
}

void privacyKeyAddedByPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyAddedByPhone");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyVoiceMessages::ID;

object_ptr<PrivacyKey> privacyKeyVoiceMessages::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyVoiceMessages>();
}

void privacyKeyVoiceMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyVoiceMessages");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyAbout::ID;

object_ptr<PrivacyKey> privacyKeyAbout::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyAbout>();
}

void privacyKeyAbout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyAbout");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyBirthday::ID;

object_ptr<PrivacyKey> privacyKeyBirthday::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyBirthday>();
}

void privacyKeyBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyBirthday");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyStarGiftsAutoSave::ID;

object_ptr<PrivacyKey> privacyKeyStarGiftsAutoSave::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyStarGiftsAutoSave>();
}

void privacyKeyStarGiftsAutoSave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyStarGiftsAutoSave");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyNoPaidMessages::ID;

object_ptr<PrivacyKey> privacyKeyNoPaidMessages::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyNoPaidMessages>();
}

void privacyKeyNoPaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyNoPaidMessages");
    s.store_class_end();
  }
}

const std::int32_t privacyKeySavedMusic::ID;

object_ptr<PrivacyKey> privacyKeySavedMusic::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeySavedMusic>();
}

void privacyKeySavedMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeySavedMusic");
    s.store_class_end();
  }
}

const std::int32_t readParticipantDate::ID;

object_ptr<readParticipantDate> readParticipantDate::fetch(TlBufferParser &p) {
  return make_tl_object<readParticipantDate>(p);
}

readParticipantDate::readParticipantDate(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void readParticipantDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readParticipantDate");
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonSpam::ID;

void inputReportReasonSpam::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonSpam::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonSpam");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonViolence::ID;

void inputReportReasonViolence::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonViolence::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonViolence::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonViolence");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonPornography::ID;

void inputReportReasonPornography::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonPornography::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonPornography::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonPornography");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonChildAbuse::ID;

void inputReportReasonChildAbuse::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonChildAbuse::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonChildAbuse::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonChildAbuse");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonOther::ID;

void inputReportReasonOther::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonOther::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonOther::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonOther");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonCopyright::ID;

void inputReportReasonCopyright::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonCopyright::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonCopyright::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonCopyright");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonGeoIrrelevant::ID;

void inputReportReasonGeoIrrelevant::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonGeoIrrelevant::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonGeoIrrelevant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonGeoIrrelevant");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonFake::ID;

void inputReportReasonFake::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonFake::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonFake::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonFake");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonIllegalDrugs::ID;

void inputReportReasonIllegalDrugs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonIllegalDrugs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonIllegalDrugs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonIllegalDrugs");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonPersonalDetails::ID;

void inputReportReasonPersonalDetails::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonPersonalDetails::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonPersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonPersonalDetails");
    s.store_class_end();
  }
}

object_ptr<ReportResult> ReportResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case reportResultChooseOption::ID:
      return reportResultChooseOption::fetch(p);
    case reportResultAddComment::ID:
      return reportResultAddComment::fetch(p);
    case reportResultReported::ID:
      return reportResultReported::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t reportResultChooseOption::ID;

object_ptr<ReportResult> reportResultChooseOption::fetch(TlBufferParser &p) {
  return make_tl_object<reportResultChooseOption>(p);
}

reportResultChooseOption::reportResultChooseOption(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , options_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messageReportOption>, 2030298073>>, 481674261>::parse(p))
{}

void reportResultChooseOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportResultChooseOption");
    s.store_field("title", title_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportResultAddComment::reportResultAddComment()
  : flags_()
  , optional_()
  , option_()
{}

const std::int32_t reportResultAddComment::ID;

object_ptr<ReportResult> reportResultAddComment::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<reportResultAddComment> res = make_tl_object<reportResultAddComment>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->optional_ = (var0 & 1) != 0;
  res->option_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void reportResultAddComment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportResultAddComment");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (optional_ << 0)));
    if (var0 & 1) { s.store_field("optional", true); }
    s.store_bytes_field("option", option_);
    s.store_class_end();
  }
}

const std::int32_t reportResultReported::ID;

object_ptr<ReportResult> reportResultReported::fetch(TlBufferParser &p) {
  return make_tl_object<reportResultReported>();
}

void reportResultReported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportResultReported");
    s.store_class_end();
  }
}

object_ptr<RequirementToContact> RequirementToContact::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case requirementToContactEmpty::ID:
      return requirementToContactEmpty::fetch(p);
    case requirementToContactPremium::ID:
      return requirementToContactPremium::fetch(p);
    case requirementToContactPaidMessages::ID:
      return requirementToContactPaidMessages::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t requirementToContactEmpty::ID;

object_ptr<RequirementToContact> requirementToContactEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<requirementToContactEmpty>();
}

void requirementToContactEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requirementToContactEmpty");
    s.store_class_end();
  }
}

const std::int32_t requirementToContactPremium::ID;

object_ptr<RequirementToContact> requirementToContactPremium::fetch(TlBufferParser &p) {
  return make_tl_object<requirementToContactPremium>();
}

void requirementToContactPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requirementToContactPremium");
    s.store_class_end();
  }
}

const std::int32_t requirementToContactPaidMessages::ID;

object_ptr<RequirementToContact> requirementToContactPaidMessages::fetch(TlBufferParser &p) {
  return make_tl_object<requirementToContactPaidMessages>(p);
}

requirementToContactPaidMessages::requirementToContactPaidMessages(TlBufferParser &p)
  : stars_amount_(TlFetchLong::parse(p))
{}

void requirementToContactPaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requirementToContactPaidMessages");
    s.store_field("stars_amount", stars_amount_);
    s.store_class_end();
  }
}

const std::int32_t savedPhoneContact::ID;

object_ptr<savedPhoneContact> savedPhoneContact::fetch(TlBufferParser &p) {
  return make_tl_object<savedPhoneContact>(p);
}

savedPhoneContact::savedPhoneContact(TlBufferParser &p)
  : phone_(TlFetchString<string>::parse(p))
  , first_name_(TlFetchString<string>::parse(p))
  , last_name_(TlFetchString<string>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void savedPhoneContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedPhoneContact");
    s.store_field("phone", phone_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<SecurePasswordKdfAlgo> SecurePasswordKdfAlgo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case securePasswordKdfAlgoUnknown::ID:
      return securePasswordKdfAlgoUnknown::fetch(p);
    case securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::ID:
      return securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::fetch(p);
    case securePasswordKdfAlgoSHA512::ID:
      return securePasswordKdfAlgoSHA512::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t securePasswordKdfAlgoUnknown::ID;

object_ptr<SecurePasswordKdfAlgo> securePasswordKdfAlgoUnknown::fetch(TlBufferParser &p) {
  return make_tl_object<securePasswordKdfAlgoUnknown>();
}

void securePasswordKdfAlgoUnknown::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void securePasswordKdfAlgoUnknown::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void securePasswordKdfAlgoUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "securePasswordKdfAlgoUnknown");
    s.store_class_end();
  }
}

securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::securePasswordKdfAlgoPBKDF2HMACSHA512iter100000(bytes &&salt_)
  : salt_(std::move(salt_))
{}

const std::int32_t securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::ID;

object_ptr<SecurePasswordKdfAlgo> securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::fetch(TlBufferParser &p) {
  return make_tl_object<securePasswordKdfAlgoPBKDF2HMACSHA512iter100000>(p);
}

securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::securePasswordKdfAlgoPBKDF2HMACSHA512iter100000(TlBufferParser &p)
  : salt_(TlFetchBytes<bytes>::parse(p))
{}

void securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt_, s);
}

void securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt_, s);
}

void securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "securePasswordKdfAlgoPBKDF2HMACSHA512iter100000");
    s.store_bytes_field("salt", salt_);
    s.store_class_end();
  }
}

securePasswordKdfAlgoSHA512::securePasswordKdfAlgoSHA512(bytes &&salt_)
  : salt_(std::move(salt_))
{}

const std::int32_t securePasswordKdfAlgoSHA512::ID;

object_ptr<SecurePasswordKdfAlgo> securePasswordKdfAlgoSHA512::fetch(TlBufferParser &p) {
  return make_tl_object<securePasswordKdfAlgoSHA512>(p);
}

securePasswordKdfAlgoSHA512::securePasswordKdfAlgoSHA512(TlBufferParser &p)
  : salt_(TlFetchBytes<bytes>::parse(p))
{}

void securePasswordKdfAlgoSHA512::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt_, s);
}

void securePasswordKdfAlgoSHA512::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt_, s);
}

void securePasswordKdfAlgoSHA512::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "securePasswordKdfAlgoSHA512");
    s.store_bytes_field("salt", salt_);
    s.store_class_end();
  }
}

object_ptr<SecureRequiredType> SecureRequiredType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case secureRequiredType::ID:
      return secureRequiredType::fetch(p);
    case secureRequiredTypeOneOf::ID:
      return secureRequiredTypeOneOf::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

secureRequiredType::secureRequiredType()
  : flags_()
  , native_names_()
  , selfie_required_()
  , translation_required_()
  , type_()
{}

const std::int32_t secureRequiredType::ID;

object_ptr<SecureRequiredType> secureRequiredType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<secureRequiredType> res = make_tl_object<secureRequiredType>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->native_names_ = (var0 & 1) != 0;
  res->selfie_required_ = (var0 & 2) != 0;
  res->translation_required_ = (var0 & 4) != 0;
  res->type_ = TlFetchObject<SecureValueType>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void secureRequiredType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureRequiredType");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (native_names_ << 0) | (selfie_required_ << 1) | (translation_required_ << 2)));
    if (var0 & 1) { s.store_field("native_names", true); }
    if (var0 & 2) { s.store_field("selfie_required", true); }
    if (var0 & 4) { s.store_field("translation_required", true); }
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

const std::int32_t secureRequiredTypeOneOf::ID;

object_ptr<SecureRequiredType> secureRequiredTypeOneOf::fetch(TlBufferParser &p) {
  return make_tl_object<secureRequiredTypeOneOf>(p);
}

secureRequiredTypeOneOf::secureRequiredTypeOneOf(TlBufferParser &p)
  : types_(TlFetchBoxed<TlFetchVector<TlFetchObject<SecureRequiredType>>, 481674261>::parse(p))
{}

void secureRequiredTypeOneOf::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureRequiredTypeOneOf");
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<ShareTheme> ShareTheme::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case shareThemeDefault::ID:
      return shareThemeDefault::fetch(p);
    case shareThemeEmojiBackdrop::ID:
      return shareThemeEmojiBackdrop::fetch(p);
    case shareThemeGift::ID:
      return shareThemeGift::fetch(p);
    case inputShareThemeGift::ID:
      return inputShareThemeGift::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t shareThemeDefault::ID;

object_ptr<ShareTheme> shareThemeDefault::fetch(TlBufferParser &p) {
  return make_tl_object<shareThemeDefault>();
}

void shareThemeDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void shareThemeDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void shareThemeDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shareThemeDefault");
    s.store_class_end();
  }
}

shareThemeEmojiBackdrop::shareThemeEmojiBackdrop()
  : flags_()
  , backdrop_id_()
  , emojis_()
{}

shareThemeEmojiBackdrop::shareThemeEmojiBackdrop(int32 flags_, int32 backdrop_id_, array<object_ptr<Reaction>> &&emojis_)
  : flags_(flags_)
  , backdrop_id_(backdrop_id_)
  , emojis_(std::move(emojis_))
{}

const std::int32_t shareThemeEmojiBackdrop::ID;

object_ptr<ShareTheme> shareThemeEmojiBackdrop::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<shareThemeEmojiBackdrop> res = make_tl_object<shareThemeEmojiBackdrop>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->backdrop_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->emojis_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Reaction>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void shareThemeEmojiBackdrop::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!emojis_.empty()) << 1)), s);
  if (var0 & 1) { TlStoreBinary::store(backdrop_id_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(emojis_, s); }
}

void shareThemeEmojiBackdrop::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!emojis_.empty()) << 1)), s);
  if (var0 & 1) { TlStoreBinary::store(backdrop_id_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(emojis_, s); }
}

void shareThemeEmojiBackdrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shareThemeEmojiBackdrop");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!emojis_.empty()) << 1)));
    if (var0 & 1) { s.store_field("backdrop_id", backdrop_id_); }
    if (var0 & 2) { { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

shareThemeGift::shareThemeGift(object_ptr<StarGift> &&stargift_)
  : stargift_(std::move(stargift_))
{}

const std::int32_t shareThemeGift::ID;

object_ptr<ShareTheme> shareThemeGift::fetch(TlBufferParser &p) {
  return make_tl_object<shareThemeGift>(p);
}

shareThemeGift::shareThemeGift(TlBufferParser &p)
  : stargift_(TlFetchObject<StarGift>::parse(p))
{}

void shareThemeGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void shareThemeGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void shareThemeGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shareThemeGift");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

inputShareThemeGift::inputShareThemeGift(object_ptr<InputSavedStarGift> &&stargift_)
  : stargift_(std::move(stargift_))
{}

const std::int32_t inputShareThemeGift::ID;

object_ptr<ShareTheme> inputShareThemeGift::fetch(TlBufferParser &p) {
  return make_tl_object<inputShareThemeGift>(p);
}

inputShareThemeGift::inputShareThemeGift(TlBufferParser &p)
  : stargift_(TlFetchObject<InputSavedStarGift>::parse(p))
{}

void inputShareThemeGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void inputShareThemeGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void inputShareThemeGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputShareThemeGift");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

object_ptr<ShareThemeBackdrops> ShareThemeBackdrops::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case shareThemeBackdropsNotModified::ID:
      return shareThemeBackdropsNotModified::fetch(p);
    case shareThemeBackdrops::ID:
      return shareThemeBackdrops::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t shareThemeBackdropsNotModified::ID;

object_ptr<ShareThemeBackdrops> shareThemeBackdropsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<shareThemeBackdropsNotModified>();
}

void shareThemeBackdropsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shareThemeBackdropsNotModified");
    s.store_class_end();
  }
}

const std::int32_t shareThemeBackdrops::ID;

object_ptr<ShareThemeBackdrops> shareThemeBackdrops::fetch(TlBufferParser &p) {
  return make_tl_object<shareThemeBackdrops>(p);
}

shareThemeBackdrops::shareThemeBackdrops(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , backdrops_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<shareThemeBackdropOption>, 1170331218>>, 481674261>::parse(p))
{}

void shareThemeBackdrops::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shareThemeBackdrops");
    s.store_field("hash", hash_);
    { s.store_vector_begin("backdrops", backdrops_.size()); for (const auto &_value : backdrops_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t smsJob::ID;

object_ptr<smsJob> smsJob::fetch(TlBufferParser &p) {
  return make_tl_object<smsJob>(p);
}

smsJob::smsJob(TlBufferParser &p)
  : job_id_(TlFetchString<string>::parse(p))
  , phone_number_(TlFetchString<string>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void smsJob::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsJob");
    s.store_field("job_id", job_id_);
    s.store_field("phone_number", phone_number_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

object_ptr<StarGiftAttributeId> StarGiftAttributeId::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starGiftAttributeIdModel::ID:
      return starGiftAttributeIdModel::fetch(p);
    case starGiftAttributeIdPattern::ID:
      return starGiftAttributeIdPattern::fetch(p);
    case starGiftAttributeIdBackdrop::ID:
      return starGiftAttributeIdBackdrop::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

starGiftAttributeIdModel::starGiftAttributeIdModel(int64 document_id_)
  : document_id_(document_id_)
{}

const std::int32_t starGiftAttributeIdModel::ID;

object_ptr<StarGiftAttributeId> starGiftAttributeIdModel::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeIdModel>(p);
}

starGiftAttributeIdModel::starGiftAttributeIdModel(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
{}

void starGiftAttributeIdModel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void starGiftAttributeIdModel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void starGiftAttributeIdModel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeIdModel");
    s.store_field("document_id", document_id_);
    s.store_class_end();
  }
}

starGiftAttributeIdPattern::starGiftAttributeIdPattern(int64 document_id_)
  : document_id_(document_id_)
{}

const std::int32_t starGiftAttributeIdPattern::ID;

object_ptr<StarGiftAttributeId> starGiftAttributeIdPattern::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeIdPattern>(p);
}

starGiftAttributeIdPattern::starGiftAttributeIdPattern(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
{}

void starGiftAttributeIdPattern::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void starGiftAttributeIdPattern::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void starGiftAttributeIdPattern::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeIdPattern");
    s.store_field("document_id", document_id_);
    s.store_class_end();
  }
}

starGiftAttributeIdBackdrop::starGiftAttributeIdBackdrop(int32 backdrop_id_)
  : backdrop_id_(backdrop_id_)
{}

const std::int32_t starGiftAttributeIdBackdrop::ID;

object_ptr<StarGiftAttributeId> starGiftAttributeIdBackdrop::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeIdBackdrop>(p);
}

starGiftAttributeIdBackdrop::starGiftAttributeIdBackdrop(TlBufferParser &p)
  : backdrop_id_(TlFetchInt::parse(p))
{}

void starGiftAttributeIdBackdrop::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(backdrop_id_, s);
}

void starGiftAttributeIdBackdrop::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(backdrop_id_, s);
}

void starGiftAttributeIdBackdrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeIdBackdrop");
    s.store_field("backdrop_id", backdrop_id_);
    s.store_class_end();
  }
}

starsRating::starsRating()
  : flags_()
  , level_()
  , current_level_stars_()
  , stars_()
  , next_level_stars_()
{}

const std::int32_t starsRating::ID;

object_ptr<starsRating> starsRating::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsRating> res = make_tl_object<starsRating>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->level_ = TlFetchInt::parse(p);
  res->current_level_stars_ = TlFetchLong::parse(p);
  res->stars_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->next_level_stars_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsRating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsRating");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("level", level_);
    s.store_field("current_level_stars", current_level_stars_);
    s.store_field("stars", stars_);
    if (var0 & 1) { s.store_field("next_level_stars", next_level_stars_); }
    s.store_class_end();
  }
}

object_ptr<StoryReaction> StoryReaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case storyReaction::ID:
      return storyReaction::fetch(p);
    case storyReactionPublicForward::ID:
      return storyReactionPublicForward::fetch(p);
    case storyReactionPublicRepost::ID:
      return storyReactionPublicRepost::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t storyReaction::ID;

object_ptr<StoryReaction> storyReaction::fetch(TlBufferParser &p) {
  return make_tl_object<storyReaction>(p);
}

storyReaction::storyReaction(TlBufferParser &p)
  : peer_id_(TlFetchObject<Peer>::parse(p))
  , date_(TlFetchInt::parse(p))
  , reaction_(TlFetchObject<Reaction>::parse(p))
{}

void storyReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyReaction");
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_field("date", date_);
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

const std::int32_t storyReactionPublicForward::ID;

object_ptr<StoryReaction> storyReactionPublicForward::fetch(TlBufferParser &p) {
  return make_tl_object<storyReactionPublicForward>(p);
}

storyReactionPublicForward::storyReactionPublicForward(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void storyReactionPublicForward::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyReactionPublicForward");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t storyReactionPublicRepost::ID;

object_ptr<StoryReaction> storyReactionPublicRepost::fetch(TlBufferParser &p) {
  return make_tl_object<storyReactionPublicRepost>(p);
}

storyReactionPublicRepost::storyReactionPublicRepost(TlBufferParser &p)
  : peer_id_(TlFetchObject<Peer>::parse(p))
  , story_(TlFetchObject<StoryItem>::parse(p))
{}

void storyReactionPublicRepost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyReactionPublicRepost");
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

const std::int32_t timezone::ID;

object_ptr<timezone> timezone::fetch(TlBufferParser &p) {
  return make_tl_object<timezone>(p);
}

timezone::timezone(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , name_(TlFetchString<string>::parse(p))
  , utc_offset_(TlFetchInt::parse(p))
{}

void timezone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "timezone");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_field("utc_offset", utc_offset_);
    s.store_class_end();
  }
}

object_ptr<UrlAuthResult> UrlAuthResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case urlAuthResultRequest::ID:
      return urlAuthResultRequest::fetch(p);
    case urlAuthResultAccepted::ID:
      return urlAuthResultAccepted::fetch(p);
    case urlAuthResultDefault::ID:
      return urlAuthResultDefault::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

urlAuthResultRequest::urlAuthResultRequest()
  : flags_()
  , request_write_access_()
  , request_phone_number_()
  , match_codes_first_()
  , is_app_()
  , request_wallet_()
  , bot_()
  , domain_()
  , browser_()
  , platform_()
  , ip_()
  , region_()
  , match_codes_()
  , user_id_hint_()
  , verified_app_name_()
  , tc_session_id_()
  , tc_client_id_()
{}

const std::int32_t urlAuthResultRequest::ID;

object_ptr<UrlAuthResult> urlAuthResultRequest::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<urlAuthResultRequest> res = make_tl_object<urlAuthResultRequest>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->request_write_access_ = (var0 & 1) != 0;
  res->request_phone_number_ = (var0 & 2) != 0;
  res->match_codes_first_ = (var0 & 32) != 0;
  res->is_app_ = (var0 & 64) != 0;
  res->request_wallet_ = (var0 & 256) != 0;
  res->bot_ = TlFetchObject<User>::parse(p);
  res->domain_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->browser_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->platform_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->ip_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->region_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->match_codes_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p); }
  if (var0 & 16) { res->user_id_hint_ = TlFetchLong::parse(p); }
  if (var0 & 128) { res->verified_app_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 512) { res->tc_session_id_ = TlFetchLong::parse(p); }
  if (var0 & 1024) { res->tc_client_id_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void urlAuthResultRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "urlAuthResultRequest");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (request_write_access_ << 0) | (request_phone_number_ << 1) | (match_codes_first_ << 5) | (is_app_ << 6) | (request_wallet_ << 8) | ((!browser_.empty()) << 2) | ((!platform_.empty()) << 2) | ((!ip_.empty()) << 2) | ((!region_.empty()) << 2) | ((!match_codes_.empty()) << 3) | ((!verified_app_name_.empty()) << 7) | ((!tc_client_id_.empty()) << 10)));
    if (var0 & 1) { s.store_field("request_write_access", true); }
    if (var0 & 2) { s.store_field("request_phone_number", true); }
    if (var0 & 32) { s.store_field("match_codes_first", true); }
    if (var0 & 64) { s.store_field("is_app", true); }
    if (var0 & 256) { s.store_field("request_wallet", true); }
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("domain", domain_);
    if (var0 & 4) { s.store_field("browser", browser_); }
    if (var0 & 4) { s.store_field("platform", platform_); }
    if (var0 & 4) { s.store_field("ip", ip_); }
    if (var0 & 4) { s.store_field("region", region_); }
    if (var0 & 8) { { s.store_vector_begin("match_codes", match_codes_.size()); for (const auto &_value : match_codes_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("user_id_hint", user_id_hint_); }
    if (var0 & 128) { s.store_field("verified_app_name", verified_app_name_); }
    if (var0 & 512) { s.store_field("tc_session_id", tc_session_id_); }
    if (var0 & 1024) { s.store_field("tc_client_id", tc_client_id_); }
    s.store_class_end();
  }
}

urlAuthResultAccepted::urlAuthResultAccepted()
  : flags_()
  , url_()
{}

const std::int32_t urlAuthResultAccepted::ID;

object_ptr<UrlAuthResult> urlAuthResultAccepted::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<urlAuthResultAccepted> res = make_tl_object<urlAuthResultAccepted>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->url_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void urlAuthResultAccepted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "urlAuthResultAccepted");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!url_.empty()) << 0)));
    if (var0 & 1) { s.store_field("url", url_); }
    s.store_class_end();
  }
}

const std::int32_t urlAuthResultDefault::ID;

object_ptr<UrlAuthResult> urlAuthResultDefault::fetch(TlBufferParser &p) {
  return make_tl_object<urlAuthResultDefault>();
}

void urlAuthResultDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "urlAuthResultDefault");
    s.store_class_end();
  }
}

object_ptr<WallPaper> WallPaper::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case wallPaper::ID:
      return wallPaper::fetch(p);
    case wallPaperNoFile::ID:
      return wallPaperNoFile::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

wallPaper::wallPaper()
  : id_()
  , flags_()
  , creator_()
  , default_()
  , pattern_()
  , dark_()
  , access_hash_()
  , slug_()
  , document_()
  , settings_()
{}

wallPaper::wallPaper(int64 id_, int32 flags_, bool creator_, bool default_, bool pattern_, bool dark_, int64 access_hash_, string const &slug_, object_ptr<Document> &&document_, object_ptr<wallPaperSettings> &&settings_)
  : id_(id_)
  , flags_(flags_)
  , creator_(creator_)
  , default_(default_)
  , pattern_(pattern_)
  , dark_(dark_)
  , access_hash_(access_hash_)
  , slug_(slug_)
  , document_(std::move(document_))
  , settings_(std::move(settings_))
{}

const std::int32_t wallPaper::ID;

object_ptr<WallPaper> wallPaper::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<wallPaper> res = make_tl_object<wallPaper>();
  int32 var0;
  res->id_ = TlFetchLong::parse(p);
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->default_ = (var0 & 2) != 0;
  res->pattern_ = (var0 & 8) != 0;
  res->dark_ = (var0 & 16) != 0;
  res->access_hash_ = TlFetchLong::parse(p);
  res->slug_ = TlFetchString<string>::parse(p);
  res->document_ = TlFetchObject<Document>::parse(p);
  if (var0 & 4) { res->settings_ = TlFetchBoxed<TlFetchObject<wallPaperSettings>, 925826256>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void wallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (default_ << 1) | (pattern_ << 3) | (dark_ << 4) | ((settings_ != nullptr) << 2)), s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
}

void wallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (default_ << 1) | (pattern_ << 3) | (dark_ << 4) | ((settings_ != nullptr) << 2)), s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
}

void wallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallPaper");
  int32 var0;
    s.store_field("id", id_);
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | (default_ << 1) | (pattern_ << 3) | (dark_ << 4) | ((settings_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 2) { s.store_field("default", true); }
    if (var0 & 8) { s.store_field("pattern", true); }
    if (var0 & 16) { s.store_field("dark", true); }
    s.store_field("access_hash", access_hash_);
    s.store_field("slug", slug_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    if (var0 & 4) { s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get())); }
    s.store_class_end();
  }
}

wallPaperNoFile::wallPaperNoFile()
  : id_()
  , flags_()
  , default_()
  , dark_()
  , settings_()
{}

wallPaperNoFile::wallPaperNoFile(int64 id_, int32 flags_, bool default_, bool dark_, object_ptr<wallPaperSettings> &&settings_)
  : id_(id_)
  , flags_(flags_)
  , default_(default_)
  , dark_(dark_)
  , settings_(std::move(settings_))
{}

const std::int32_t wallPaperNoFile::ID;

object_ptr<WallPaper> wallPaperNoFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<wallPaperNoFile> res = make_tl_object<wallPaperNoFile>();
  int32 var0;
  res->id_ = TlFetchLong::parse(p);
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->default_ = (var0 & 2) != 0;
  res->dark_ = (var0 & 16) != 0;
  if (var0 & 4) { res->settings_ = TlFetchBoxed<TlFetchObject<wallPaperSettings>, 925826256>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void wallPaperNoFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (default_ << 1) | (dark_ << 4) | ((settings_ != nullptr) << 2)), s);
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
}

void wallPaperNoFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (default_ << 1) | (dark_ << 4) | ((settings_ != nullptr) << 2)), s);
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
}

void wallPaperNoFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallPaperNoFile");
  int32 var0;
    s.store_field("id", id_);
    s.store_field("flags", (var0 = flags_ | (default_ << 1) | (dark_ << 4) | ((settings_ != nullptr) << 2)));
    if (var0 & 2) { s.store_field("default", true); }
    if (var0 & 16) { s.store_field("dark", true); }
    if (var0 & 4) { s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get())); }
    s.store_class_end();
  }
}

account_passwordInputSettings::account_passwordInputSettings(int32 flags_, object_ptr<PasswordKdfAlgo> &&new_algo_, bytes &&new_password_hash_, string const &hint_, string const &email_, object_ptr<secureSecretSettings> &&new_secure_settings_)
  : flags_(flags_)
  , new_algo_(std::move(new_algo_))
  , new_password_hash_(std::move(new_password_hash_))
  , hint_(hint_)
  , email_(email_)
  , new_secure_settings_(std::move(new_secure_settings_))
{}

const std::int32_t account_passwordInputSettings::ID;

void account_passwordInputSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((new_algo_ != nullptr) << 0) | ((!new_password_hash_.empty()) << 0) | ((!hint_.empty()) << 0) | ((!email_.empty()) << 1) | ((new_secure_settings_ != nullptr) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(new_algo_, s); }
  if (var0 & 1) { TlStoreString::store(new_password_hash_, s); }
  if (var0 & 1) { TlStoreString::store(hint_, s); }
  if (var0 & 2) { TlStoreString::store(email_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 354925740>::store(new_secure_settings_, s); }
}

void account_passwordInputSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((new_algo_ != nullptr) << 0) | ((!new_password_hash_.empty()) << 0) | ((!hint_.empty()) << 0) | ((!email_.empty()) << 1) | ((new_secure_settings_ != nullptr) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(new_algo_, s); }
  if (var0 & 1) { TlStoreString::store(new_password_hash_, s); }
  if (var0 & 1) { TlStoreString::store(hint_, s); }
  if (var0 & 2) { TlStoreString::store(email_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 354925740>::store(new_secure_settings_, s); }
}

void account_passwordInputSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.passwordInputSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((new_algo_ != nullptr) << 0) | ((!new_password_hash_.empty()) << 0) | ((!hint_.empty()) << 0) | ((!email_.empty()) << 1) | ((new_secure_settings_ != nullptr) << 2)));
    if (var0 & 1) { s.store_object_field("new_algo", static_cast<const BaseObject *>(new_algo_.get())); }
    if (var0 & 1) { s.store_bytes_field("new_password_hash", new_password_hash_); }
    if (var0 & 1) { s.store_field("hint", hint_); }
    if (var0 & 2) { s.store_field("email", email_); }
    if (var0 & 4) { s.store_object_field("new_secure_settings", static_cast<const BaseObject *>(new_secure_settings_.get())); }
    s.store_class_end();
  }
}

object_ptr<auth_SentCode> auth_SentCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case auth_sentCode::ID:
      return auth_sentCode::fetch(p);
    case auth_sentCodeSuccess::ID:
      return auth_sentCodeSuccess::fetch(p);
    case auth_sentCodePaymentRequired::ID:
      return auth_sentCodePaymentRequired::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

auth_sentCode::auth_sentCode()
  : flags_()
  , type_()
  , phone_code_hash_()
  , next_type_()
  , timeout_()
{}

const std::int32_t auth_sentCode::ID;

object_ptr<auth_SentCode> auth_sentCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCode> res = make_tl_object<auth_sentCode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->type_ = TlFetchObject<auth_SentCodeType>::parse(p);
  res->phone_code_hash_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->next_type_ = TlFetchObject<auth_CodeType>::parse(p); }
  if (var0 & 4) { res->timeout_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((next_type_ != nullptr) << 1)));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("phone_code_hash", phone_code_hash_);
    if (var0 & 2) { s.store_object_field("next_type", static_cast<const BaseObject *>(next_type_.get())); }
    if (var0 & 4) { s.store_field("timeout", timeout_); }
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeSuccess::ID;

object_ptr<auth_SentCode> auth_sentCodeSuccess::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeSuccess>(p);
}

auth_sentCodeSuccess::auth_sentCodeSuccess(TlBufferParser &p)
  : authorization_(TlFetchObject<auth_Authorization>::parse(p))
{}

void auth_sentCodeSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeSuccess");
    s.store_object_field("authorization", static_cast<const BaseObject *>(authorization_.get()));
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodePaymentRequired::ID;

object_ptr<auth_SentCode> auth_sentCodePaymentRequired::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodePaymentRequired>(p);
}

auth_sentCodePaymentRequired::auth_sentCodePaymentRequired(TlBufferParser &p)
  : store_product_(TlFetchString<string>::parse(p))
  , phone_code_hash_(TlFetchString<string>::parse(p))
  , support_email_address_(TlFetchString<string>::parse(p))
  , support_email_subject_(TlFetchString<string>::parse(p))
  , premium_days_(TlFetchInt::parse(p))
  , currency_(TlFetchString<string>::parse(p))
  , amount_(TlFetchLong::parse(p))
{}

void auth_sentCodePaymentRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodePaymentRequired");
    s.store_field("store_product", store_product_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("support_email_address", support_email_address_);
    s.store_field("support_email_subject", support_email_subject_);
    s.store_field("premium_days", premium_days_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

const std::int32_t bots_botInfo::ID;

object_ptr<bots_botInfo> bots_botInfo::fetch(TlBufferParser &p) {
  return make_tl_object<bots_botInfo>(p);
}

bots_botInfo::bots_botInfo(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
  , about_(TlFetchString<string>::parse(p))
  , description_(TlFetchString<string>::parse(p))
{}

void bots_botInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.botInfo");
    s.store_field("name", name_);
    s.store_field("about", about_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

const std::int32_t bots_exportedBotToken::ID;

object_ptr<bots_exportedBotToken> bots_exportedBotToken::fetch(TlBufferParser &p) {
  return make_tl_object<bots_exportedBotToken>(p);
}

bots_exportedBotToken::bots_exportedBotToken(TlBufferParser &p)
  : token_(TlFetchString<string>::parse(p))
{}

void bots_exportedBotToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.exportedBotToken");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

object_ptr<ephemeral_WelcomeMessages> ephemeral_WelcomeMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case ephemeral_welcomeMessagesNotModified::ID:
      return ephemeral_welcomeMessagesNotModified::fetch(p);
    case ephemeral_welcomeMessages::ID:
      return ephemeral_welcomeMessages::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t ephemeral_welcomeMessagesNotModified::ID;

object_ptr<ephemeral_WelcomeMessages> ephemeral_welcomeMessagesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<ephemeral_welcomeMessagesNotModified>();
}

void ephemeral_welcomeMessagesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeral.welcomeMessagesNotModified");
    s.store_class_end();
  }
}

const std::int32_t ephemeral_welcomeMessages::ID;

object_ptr<ephemeral_WelcomeMessages> ephemeral_welcomeMessages::fetch(TlBufferParser &p) {
  return make_tl_object<ephemeral_welcomeMessages>(p);
}

ephemeral_welcomeMessages::ephemeral_welcomeMessages(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<ephemeralMessage>, -584597783>>, 481674261>::parse(p))
{}

void ephemeral_welcomeMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeral.welcomeMessages");
    s.store_field("hash", hash_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t help_configSimple::ID;

object_ptr<help_configSimple> help_configSimple::fetch(TlBufferParser &p) {
  return make_tl_object<help_configSimple>(p);
}

help_configSimple::help_configSimple(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , expires_(TlFetchInt::parse(p))
  , rules_(TlFetchVector<TlFetchBoxed<TlFetchObject<accessPointRule>, 1182381663>>::parse(p))
{}

void help_configSimple::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.configSimple");
    s.store_field("date", date_);
    s.store_field("expires", expires_);
    { s.store_vector_begin("rules", rules_.size()); for (const auto &_value : rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_AvailableReactions> messages_AvailableReactions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_availableReactionsNotModified::ID:
      return messages_availableReactionsNotModified::fetch(p);
    case messages_availableReactions::ID:
      return messages_availableReactions::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_availableReactionsNotModified::ID;

object_ptr<messages_AvailableReactions> messages_availableReactionsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_availableReactionsNotModified>();
}

void messages_availableReactionsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.availableReactionsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_availableReactions::ID;

object_ptr<messages_AvailableReactions> messages_availableReactions::fetch(TlBufferParser &p) {
  return make_tl_object<messages_availableReactions>(p);
}

messages_availableReactions::messages_availableReactions(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , reactions_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<availableReaction>, -1065882623>>, 481674261>::parse(p))
{}

void messages_availableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.availableReactions");
    s.store_field("hash", hash_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_composedMessageWithAI::messages_composedMessageWithAI()
  : flags_()
  , result_text_()
  , diff_text_()
{}

const std::int32_t messages_composedMessageWithAI::ID;

object_ptr<messages_composedMessageWithAI> messages_composedMessageWithAI::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_composedMessageWithAI> res = make_tl_object<messages_composedMessageWithAI>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->result_text_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 1) { res->diff_text_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_composedMessageWithAI::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.composedMessageWithAI");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((diff_text_ != nullptr) << 0)));
    s.store_object_field("result_text", static_cast<const BaseObject *>(result_text_.get()));
    if (var0 & 1) { s.store_object_field("diff_text", static_cast<const BaseObject *>(diff_text_.get())); }
    s.store_class_end();
  }
}

object_ptr<messages_EmojiGameInfo> messages_EmojiGameInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_emojiGameUnavailable::ID:
      return messages_emojiGameUnavailable::fetch(p);
    case messages_emojiGameDiceInfo::ID:
      return messages_emojiGameDiceInfo::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_emojiGameUnavailable::ID;

object_ptr<messages_EmojiGameInfo> messages_emojiGameUnavailable::fetch(TlBufferParser &p) {
  return make_tl_object<messages_emojiGameUnavailable>();
}

void messages_emojiGameUnavailable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.emojiGameUnavailable");
    s.store_class_end();
  }
}

messages_emojiGameDiceInfo::messages_emojiGameDiceInfo()
  : flags_()
  , game_hash_()
  , prev_stake_()
  , current_streak_()
  , params_()
  , plays_left_()
{}

const std::int32_t messages_emojiGameDiceInfo::ID;

object_ptr<messages_EmojiGameInfo> messages_emojiGameDiceInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_emojiGameDiceInfo> res = make_tl_object<messages_emojiGameDiceInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->game_hash_ = TlFetchString<string>::parse(p);
  res->prev_stake_ = TlFetchLong::parse(p);
  res->current_streak_ = TlFetchInt::parse(p);
  res->params_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  if (var0 & 1) { res->plays_left_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_emojiGameDiceInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.emojiGameDiceInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("game_hash", game_hash_);
    s.store_field("prev_stake", prev_stake_);
    s.store_field("current_streak", current_streak_);
    { s.store_vector_begin("params", params_.size()); for (const auto &_value : params_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("plays_left", plays_left_); }
    s.store_class_end();
  }
}

messages_emojiGameOutcome::messages_emojiGameOutcome(bytes &&seed_, int64 stake_ton_amount_, int64 ton_amount_)
  : seed_(std::move(seed_))
  , stake_ton_amount_(stake_ton_amount_)
  , ton_amount_(ton_amount_)
{}

const std::int32_t messages_emojiGameOutcome::ID;

object_ptr<messages_emojiGameOutcome> messages_emojiGameOutcome::fetch(TlBufferParser &p) {
  return make_tl_object<messages_emojiGameOutcome>(p);
}

messages_emojiGameOutcome::messages_emojiGameOutcome(TlBufferParser &p)
  : seed_(TlFetchBytes<bytes>::parse(p))
  , stake_ton_amount_(TlFetchLong::parse(p))
  , ton_amount_(TlFetchLong::parse(p))
{}

void messages_emojiGameOutcome::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(seed_, s);
  TlStoreBinary::store(stake_ton_amount_, s);
  TlStoreBinary::store(ton_amount_, s);
}

void messages_emojiGameOutcome::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(seed_, s);
  TlStoreBinary::store(stake_ton_amount_, s);
  TlStoreBinary::store(ton_amount_, s);
}

void messages_emojiGameOutcome::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.emojiGameOutcome");
    s.store_bytes_field("seed", seed_);
    s.store_field("stake_ton_amount", stake_ton_amount_);
    s.store_field("ton_amount", ton_amount_);
    s.store_class_end();
  }
}

object_ptr<messages_FoundStickerSets> messages_FoundStickerSets::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_foundStickerSetsNotModified::ID:
      return messages_foundStickerSetsNotModified::fetch(p);
    case messages_foundStickerSets::ID:
      return messages_foundStickerSets::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_foundStickerSetsNotModified::ID;

object_ptr<messages_FoundStickerSets> messages_foundStickerSetsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_foundStickerSetsNotModified>();
}

void messages_foundStickerSetsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.foundStickerSetsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_foundStickerSets::ID;

object_ptr<messages_FoundStickerSets> messages_foundStickerSets::fetch(TlBufferParser &p) {
  return make_tl_object<messages_foundStickerSets>(p);
}

messages_foundStickerSets::messages_foundStickerSets(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , sets_(TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p))
{}

void messages_foundStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.foundStickerSets");
    s.store_field("hash", hash_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_FoundStickers> messages_FoundStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_foundStickersNotModified::ID:
      return messages_foundStickersNotModified::fetch(p);
    case messages_foundStickers::ID:
      return messages_foundStickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messages_foundStickersNotModified::messages_foundStickersNotModified()
  : flags_()
  , next_offset_()
{}

const std::int32_t messages_foundStickersNotModified::ID;

object_ptr<messages_FoundStickers> messages_foundStickersNotModified::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_foundStickersNotModified> res = make_tl_object<messages_foundStickersNotModified>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->next_offset_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_foundStickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.foundStickersNotModified");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

messages_foundStickers::messages_foundStickers()
  : flags_()
  , next_offset_()
  , hash_()
  , stickers_()
{}

const std::int32_t messages_foundStickers::ID;

object_ptr<messages_FoundStickers> messages_foundStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_foundStickers> res = make_tl_object<messages_foundStickers>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->next_offset_ = TlFetchInt::parse(p); }
  res->hash_ = TlFetchLong::parse(p);
  res->stickers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_foundStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.foundStickers");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_field("hash", hash_);
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_historyImportParsed::messages_historyImportParsed()
  : flags_()
  , pm_()
  , group_()
  , title_()
{}

const std::int32_t messages_historyImportParsed::ID;

object_ptr<messages_historyImportParsed> messages_historyImportParsed::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_historyImportParsed> res = make_tl_object<messages_historyImportParsed>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pm_ = (var0 & 1) != 0;
  res->group_ = (var0 & 2) != 0;
  if (var0 & 4) { res->title_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_historyImportParsed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.historyImportParsed");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pm_ << 0) | (group_ << 1) | ((!title_.empty()) << 2)));
    if (var0 & 1) { s.store_field("pm", true); }
    if (var0 & 2) { s.store_field("group", true); }
    if (var0 & 4) { s.store_field("title", title_); }
    s.store_class_end();
  }
}

object_ptr<messages_StickerSetInstallResult> messages_StickerSetInstallResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_stickerSetInstallResultSuccess::ID:
      return messages_stickerSetInstallResultSuccess::fetch(p);
    case messages_stickerSetInstallResultArchive::ID:
      return messages_stickerSetInstallResultArchive::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_stickerSetInstallResultSuccess::ID;

object_ptr<messages_StickerSetInstallResult> messages_stickerSetInstallResultSuccess::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickerSetInstallResultSuccess>();
}

void messages_stickerSetInstallResultSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickerSetInstallResultSuccess");
    s.store_class_end();
  }
}

const std::int32_t messages_stickerSetInstallResultArchive::ID;

object_ptr<messages_StickerSetInstallResult> messages_stickerSetInstallResultArchive::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickerSetInstallResultArchive>(p);
}

messages_stickerSetInstallResultArchive::messages_stickerSetInstallResultArchive(TlBufferParser &p)
  : sets_(TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p))
{}

void messages_stickerSetInstallResultArchive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickerSetInstallResultArchive");
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<payments_StarGiftCollections> payments_StarGiftCollections::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_starGiftCollectionsNotModified::ID:
      return payments_starGiftCollectionsNotModified::fetch(p);
    case payments_starGiftCollections::ID:
      return payments_starGiftCollections::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t payments_starGiftCollectionsNotModified::ID;

object_ptr<payments_StarGiftCollections> payments_starGiftCollectionsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftCollectionsNotModified>();
}

void payments_starGiftCollectionsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftCollectionsNotModified");
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftCollections::ID;

object_ptr<payments_StarGiftCollections> payments_starGiftCollections::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftCollections>(p);
}

payments_starGiftCollections::payments_starGiftCollections(TlBufferParser &p)
  : collections_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftCollection>, -1653926992>>, 481674261>::parse(p))
{}

void payments_starGiftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftCollections");
    { s.store_vector_begin("collections", collections_.size()); for (const auto &_value : collections_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_starGiftOnchainOfferTxMessage::payments_starGiftOnchainOfferTxMessage()
  : flags_()
  , destination_()
  , value_()
  , mode_()
  , body_()
  , init_state_()
{}

const std::int32_t payments_starGiftOnchainOfferTxMessage::ID;

object_ptr<payments_starGiftOnchainOfferTxMessage> payments_starGiftOnchainOfferTxMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_starGiftOnchainOfferTxMessage> res = make_tl_object<payments_starGiftOnchainOfferTxMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->destination_ = TlFetchString<string>::parse(p);
  res->value_ = TlFetchLong::parse(p);
  res->mode_ = TlFetchInt::parse(p);
  res->body_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 1) { res->init_state_ = TlFetchBoxed<TlFetchObject<payments_starGiftOnchainOfferTxInitState>, 148300917>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_starGiftOnchainOfferTxMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftOnchainOfferTxMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((init_state_ != nullptr) << 0)));
    s.store_field("destination", destination_);
    s.store_field("value", value_);
    s.store_field("mode", mode_);
    s.store_bytes_field("body", body_);
    if (var0 & 1) { s.store_object_field("init_state", static_cast<const BaseObject *>(init_state_.get())); }
    s.store_class_end();
  }
}

const std::int32_t payments_starsRevenueWithdrawalUrl::ID;

object_ptr<payments_starsRevenueWithdrawalUrl> payments_starsRevenueWithdrawalUrl::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starsRevenueWithdrawalUrl>(p);
}

payments_starsRevenueWithdrawalUrl::payments_starsRevenueWithdrawalUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void payments_starsRevenueWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starsRevenueWithdrawalUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

premium_boostsStatus::premium_boostsStatus()
  : flags_()
  , my_boost_()
  , level_()
  , current_level_boosts_()
  , boosts_()
  , gift_boosts_()
  , next_level_boosts_()
  , premium_audience_()
  , boost_url_()
  , prepaid_giveaways_()
  , my_boost_slots_()
{}

const std::int32_t premium_boostsStatus::ID;

object_ptr<premium_boostsStatus> premium_boostsStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<premium_boostsStatus> res = make_tl_object<premium_boostsStatus>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->my_boost_ = (var0 & 4) != 0;
  res->level_ = TlFetchInt::parse(p);
  res->current_level_boosts_ = TlFetchInt::parse(p);
  res->boosts_ = TlFetchInt::parse(p);
  if (var0 & 16) { res->gift_boosts_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->next_level_boosts_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->premium_audience_ = TlFetchBoxed<TlFetchObject<statsPercentValue>, -875679776>::parse(p); }
  res->boost_url_ = TlFetchString<string>::parse(p);
  if (var0 & 8) { res->prepaid_giveaways_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PrepaidGiveaway>>, 481674261>::parse(p); }
  if (var0 & 4) { res->my_boost_slots_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void premium_boostsStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.boostsStatus");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (my_boost_ << 2) | ((premium_audience_ != nullptr) << 1) | ((!prepaid_giveaways_.empty()) << 3) | ((!my_boost_slots_.empty()) << 2)));
    if (var0 & 4) { s.store_field("my_boost", true); }
    s.store_field("level", level_);
    s.store_field("current_level_boosts", current_level_boosts_);
    s.store_field("boosts", boosts_);
    if (var0 & 16) { s.store_field("gift_boosts", gift_boosts_); }
    if (var0 & 1) { s.store_field("next_level_boosts", next_level_boosts_); }
    if (var0 & 2) { s.store_object_field("premium_audience", static_cast<const BaseObject *>(premium_audience_.get())); }
    s.store_field("boost_url", boost_url_);
    if (var0 & 8) { { s.store_vector_begin("prepaid_giveaways", prepaid_giveaways_.size()); for (const auto &_value : prepaid_giveaways_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("my_boost_slots", my_boost_slots_.size()); for (const auto &_value : my_boost_slots_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t stats_storyStats::ID;

object_ptr<stats_storyStats> stats_storyStats::fetch(TlBufferParser &p) {
  return make_tl_object<stats_storyStats>(p);
}

stats_storyStats::stats_storyStats(TlBufferParser &p)
  : views_graph_(TlFetchObject<StatsGraph>::parse(p))
  , reactions_by_emotion_graph_(TlFetchObject<StatsGraph>::parse(p))
{}

void stats_storyStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.storyStats");
    s.store_object_field("views_graph", static_cast<const BaseObject *>(views_graph_.get()));
    s.store_object_field("reactions_by_emotion_graph", static_cast<const BaseObject *>(reactions_by_emotion_graph_.get()));
    s.store_class_end();
  }
}

wallet_nftItem::wallet_nftItem()
  : flags_()
  , collection_address_()
  , address_()
  , owner_address_()
  , index_()
  , name_()
  , description_()
  , image_()
  , image_small_()
  , content_url_()
  , lottie_()
  , attributes_()
  , extra_()
  , gift_()
{}

const std::int32_t wallet_nftItem::ID;

object_ptr<wallet_nftItem> wallet_nftItem::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<wallet_nftItem> res = make_tl_object<wallet_nftItem>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->collection_address_ = TlFetchString<string>::parse(p); }
  res->address_ = TlFetchString<string>::parse(p);
  res->owner_address_ = TlFetchString<string>::parse(p);
  res->index_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->name_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->description_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->image_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 16) { res->image_small_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 32) { res->content_url_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 64) { res->lottie_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 128) { res->attributes_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<wallet_nftAttribute>, 1277096206>>, 481674261>::parse(p); }
  if (var0 & 256) { res->extra_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p); }
  if (var0 & 512) { res->gift_ = TlFetchObject<StarGift>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void wallet_nftItem::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.nftItem");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!collection_address_.empty()) << 0) | ((!name_.empty()) << 1) | ((!description_.empty()) << 2) | ((image_ != nullptr) << 3) | ((image_small_ != nullptr) << 4) | ((content_url_ != nullptr) << 5) | ((lottie_ != nullptr) << 6) | ((!attributes_.empty()) << 7) | ((extra_ != nullptr) << 8) | ((gift_ != nullptr) << 9)));
    if (var0 & 1) { s.store_field("collection_address", collection_address_); }
    s.store_field("address", address_);
    s.store_field("owner_address", owner_address_);
    s.store_field("index", index_);
    if (var0 & 2) { s.store_field("name", name_); }
    if (var0 & 4) { s.store_field("description", description_); }
    if (var0 & 8) { s.store_object_field("image", static_cast<const BaseObject *>(image_.get())); }
    if (var0 & 16) { s.store_object_field("image_small", static_cast<const BaseObject *>(image_small_.get())); }
    if (var0 & 32) { s.store_object_field("content_url", static_cast<const BaseObject *>(content_url_.get())); }
    if (var0 & 64) { s.store_object_field("lottie", static_cast<const BaseObject *>(lottie_.get())); }
    if (var0 & 128) { { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 256) { s.store_object_field("extra", static_cast<const BaseObject *>(extra_.get())); }
    if (var0 & 512) { s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get())); }
    s.store_class_end();
  }
}

const std::int32_t account_getAutoSaveSettings::ID;

void account_getAutoSaveSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1379156774);
}

void account_getAutoSaveSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1379156774);
}

void account_getAutoSaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAutoSaveSettings");
    s.store_class_end();
  }
}

account_getAutoSaveSettings::ReturnType account_getAutoSaveSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_autoSaveSettings>, 1279133341>::parse(p);
#undef FAIL
}

const std::int32_t account_getBusinessChatLinks::ID;

void account_getBusinessChatLinks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1869667809);
}

void account_getBusinessChatLinks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1869667809);
}

void account_getBusinessChatLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getBusinessChatLinks");
    s.store_class_end();
  }
}

account_getBusinessChatLinks::ReturnType account_getBusinessChatLinks::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_businessChatLinks>, -331111727>::parse(p);
#undef FAIL
}

account_getDefaultBackgroundEmojis::account_getDefaultBackgroundEmojis(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getDefaultBackgroundEmojis::ID;

void account_getDefaultBackgroundEmojis::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1509246514);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultBackgroundEmojis::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1509246514);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultBackgroundEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getDefaultBackgroundEmojis");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getDefaultBackgroundEmojis::ReturnType account_getDefaultBackgroundEmojis::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EmojiList>::parse(p);
#undef FAIL
}

const std::int32_t account_getGlobalPrivacySettings::ID;

void account_getGlobalPrivacySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-349483786);
}

void account_getGlobalPrivacySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-349483786);
}

void account_getGlobalPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getGlobalPrivacySettings");
    s.store_class_end();
  }
}

account_getGlobalPrivacySettings::ReturnType account_getGlobalPrivacySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<globalPrivacySettings>, -29248689>::parse(p);
#undef FAIL
}

const std::int32_t account_getPasskeys::ID;

void account_getPasskeys::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-367063982);
}

void account_getPasskeys::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-367063982);
}

void account_getPasskeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getPasskeys");
    s.store_class_end();
  }
}

account_getPasskeys::ReturnType account_getPasskeys::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_passkeys>, -119494116>::parse(p);
#undef FAIL
}

const std::int32_t account_getReactionsNotifySettings::ID;

void account_getReactionsNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(115172684);
}

void account_getReactionsNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(115172684);
}

void account_getReactionsNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getReactionsNotifySettings");
    s.store_class_end();
  }
}

account_getReactionsNotifySettings::ReturnType account_getReactionsNotifySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<reactionsNotifySettings>, 1910827608>::parse(p);
#undef FAIL
}

account_reportProfilePhoto::account_reportProfilePhoto(object_ptr<InputPeer> &&peer_, object_ptr<InputPhoto> &&photo_id_, object_ptr<ReportReason> &&reason_, string const &message_)
  : peer_(std::move(peer_))
  , photo_id_(std::move(photo_id_))
  , reason_(std::move(reason_))
  , message_(message_)
{}

const std::int32_t account_reportProfilePhoto::ID;

void account_reportProfilePhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-91437323);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreString::store(message_, s);
}

void account_reportProfilePhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-91437323);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreString::store(message_, s);
}

void account_reportProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.reportProfilePhoto");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("photo_id", static_cast<const BaseObject *>(photo_id_.get()));
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("message", message_);
    s.store_class_end();
  }
}

account_reportProfilePhoto::ReturnType account_reportProfilePhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_resetNotifySettings::ID;

void account_resetNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-612493497);
}

void account_resetNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-612493497);
}

void account_resetNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetNotifySettings");
    s.store_class_end();
  }
}

account_resetNotifySettings::ReturnType account_resetNotifySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_resetWallPapers::ID;

void account_resetWallPapers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1153722364);
}

void account_resetWallPapers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1153722364);
}

void account_resetWallPapers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetWallPapers");
    s.store_class_end();
  }
}

account_resetWallPapers::ReturnType account_resetWallPapers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_resolveBusinessChatLink::account_resolveBusinessChatLink(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t account_resolveBusinessChatLink::ID;

void account_resolveBusinessChatLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1418913262);
  TlStoreString::store(slug_, s);
}

void account_resolveBusinessChatLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1418913262);
  TlStoreString::store(slug_, s);
}

void account_resolveBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resolveBusinessChatLink");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

account_resolveBusinessChatLink::ReturnType account_resolveBusinessChatLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_resolvedBusinessChatLinks>, -1708937439>::parse(p);
#undef FAIL
}

account_sendChangePhoneCode::account_sendChangePhoneCode(string const &phone_number_, object_ptr<codeSettings> &&settings_)
  : phone_number_(phone_number_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_sendChangePhoneCode::ID;

void account_sendChangePhoneCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2108208411);
  TlStoreString::store(phone_number_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendChangePhoneCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2108208411);
  TlStoreString::store(phone_number_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendChangePhoneCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.sendChangePhoneCode");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_sendChangePhoneCode::ReturnType account_sendChangePhoneCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

account_updateBusinessLocation::account_updateBusinessLocation(int32 flags_, object_ptr<InputGeoPoint> &&geo_point_, string const &address_)
  : flags_(flags_)
  , geo_point_(std::move(geo_point_))
  , address_(address_)
{}

const std::int32_t account_updateBusinessLocation::ID;

void account_updateBusinessLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1637149926);
  TlStoreBinary::store((var0 = flags_ | ((geo_point_ != nullptr) << 1) | ((!address_.empty()) << 0)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  if (var0 & 1) { TlStoreString::store(address_, s); }
}

void account_updateBusinessLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1637149926);
  TlStoreBinary::store((var0 = flags_ | ((geo_point_ != nullptr) << 1) | ((!address_.empty()) << 0)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  if (var0 & 1) { TlStoreString::store(address_, s); }
}

void account_updateBusinessLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBusinessLocation");
    s.store_field("flags", (var0 = flags_ | ((geo_point_ != nullptr) << 1) | ((!address_.empty()) << 0)));
    if (var0 & 2) { s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get())); }
    if (var0 & 1) { s.store_field("address", address_); }
    s.store_class_end();
  }
}

account_updateBusinessLocation::ReturnType account_updateBusinessLocation::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_verifyEmail::account_verifyEmail(object_ptr<EmailVerifyPurpose> &&purpose_, object_ptr<EmailVerification> &&verification_)
  : purpose_(std::move(purpose_))
  , verification_(std::move(verification_))
{}

const std::int32_t account_verifyEmail::ID;

void account_verifyEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(53322959);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(verification_, s);
}

void account_verifyEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(53322959);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(verification_, s);
}

void account_verifyEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.verifyEmail");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_object_field("verification", static_cast<const BaseObject *>(verification_.get()));
    s.store_class_end();
  }
}

account_verifyEmail::ReturnType account_verifyEmail::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_EmailVerified>::parse(p);
#undef FAIL
}

aicompose_getTone::aicompose_getTone(object_ptr<InputAiComposeTone> &&tone_)
  : tone_(std::move(tone_))
{}

const std::int32_t aicompose_getTone::ID;

void aicompose_getTone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1293370877);
  TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s);
}

void aicompose_getTone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1293370877);
  TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s);
}

void aicompose_getTone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aicompose.getTone");
    s.store_object_field("tone", static_cast<const BaseObject *>(tone_.get()));
    s.store_class_end();
  }
}

aicompose_getTone::ReturnType aicompose_getTone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<aicompose_Tones>::parse(p);
#undef FAIL
}

auth_firebasePnvSignUp::auth_firebasePnvSignUp(int32 flags_, bool no_joined_notifications_, string const &first_name_, string const &last_name_)
  : flags_(flags_)
  , no_joined_notifications_(no_joined_notifications_)
  , first_name_(first_name_)
  , last_name_(last_name_)
{}

const std::int32_t auth_firebasePnvSignUp::ID;

void auth_firebasePnvSignUp::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2017422166);
  TlStoreBinary::store((var0 = flags_ | (no_joined_notifications_ << 0)), s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
}

void auth_firebasePnvSignUp::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2017422166);
  TlStoreBinary::store((var0 = flags_ | (no_joined_notifications_ << 0)), s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
}

void auth_firebasePnvSignUp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.firebasePnvSignUp");
    s.store_field("flags", (var0 = flags_ | (no_joined_notifications_ << 0)));
    if (var0 & 1) { s.store_field("no_joined_notifications", true); }
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_class_end();
  }
}

auth_firebasePnvSignUp::ReturnType auth_firebasePnvSignUp::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

auth_signIn::auth_signIn(int32 flags_, string const &phone_number_, string const &phone_code_hash_, string const &phone_code_, object_ptr<EmailVerification> &&email_verification_)
  : flags_(flags_)
  , phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , phone_code_(phone_code_)
  , email_verification_(std::move(email_verification_))
{}

const std::int32_t auth_signIn::ID;

void auth_signIn::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1923962543);
  TlStoreBinary::store((var0 = flags_ | ((!phone_code_.empty()) << 0) | ((email_verification_ != nullptr) << 1)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(phone_code_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(email_verification_, s); }
}

void auth_signIn::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1923962543);
  TlStoreBinary::store((var0 = flags_ | ((!phone_code_.empty()) << 0) | ((email_verification_ != nullptr) << 1)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(phone_code_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(email_verification_, s); }
}

void auth_signIn::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.signIn");
    s.store_field("flags", (var0 = flags_ | ((!phone_code_.empty()) << 0) | ((email_verification_ != nullptr) << 1)));
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    if (var0 & 1) { s.store_field("phone_code", "[REDACTED]"); }
    if (var0 & 2) { s.store_object_field("email_verification", static_cast<const BaseObject *>(email_verification_.get())); }
    s.store_class_end();
  }
}

auth_signIn::ReturnType auth_signIn::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

bots_editPreviewMedia::bots_editPreviewMedia(object_ptr<InputUser> &&bot_, string const &lang_code_, object_ptr<InputMedia> &&media_, object_ptr<InputMedia> &&new_media_)
  : bot_(std::move(bot_))
  , lang_code_(lang_code_)
  , media_(std::move(media_))
  , new_media_(std::move(new_media_))
{}

const std::int32_t bots_editPreviewMedia::ID;

void bots_editPreviewMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2061148049);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(new_media_, s);
}

void bots_editPreviewMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2061148049);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(new_media_, s);
}

void bots_editPreviewMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.editPreviewMedia");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("lang_code", lang_code_);
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_object_field("new_media", static_cast<const BaseObject *>(new_media_.get()));
    s.store_class_end();
  }
}

bots_editPreviewMedia::ReturnType bots_editPreviewMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<botPreviewMedia>, 602479523>::parse(p);
#undef FAIL
}

bots_getAccessSettings::bots_getAccessSettings(object_ptr<InputUser> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t bots_getAccessSettings::ID;

void bots_getAccessSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(557339555);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_getAccessSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(557339555);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_getAccessSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getAccessSettings");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

bots_getAccessSettings::ReturnType bots_getAccessSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<bots_accessSettings>, -585121901>::parse(p);
#undef FAIL
}

bots_setBotBroadcastDefaultAdminRights::bots_setBotBroadcastDefaultAdminRights(object_ptr<chatAdminRights> &&admin_rights_)
  : admin_rights_(std::move(admin_rights_))
{}

const std::int32_t bots_setBotBroadcastDefaultAdminRights::ID;

void bots_setBotBroadcastDefaultAdminRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2021942497);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
}

void bots_setBotBroadcastDefaultAdminRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2021942497);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
}

void bots_setBotBroadcastDefaultAdminRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setBotBroadcastDefaultAdminRights");
    s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get()));
    s.store_class_end();
  }
}

bots_setBotBroadcastDefaultAdminRights::ReturnType bots_setBotBroadcastDefaultAdminRights::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_setBotCommands::bots_setBotCommands(object_ptr<BotCommandScope> &&scope_, string const &lang_code_, array<object_ptr<botCommand>> &&commands_)
  : scope_(std::move(scope_))
  , lang_code_(lang_code_)
  , commands_(std::move(commands_))
{}

const std::int32_t bots_setBotCommands::ID;

void bots_setBotCommands::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(85399130);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1739401518>>, 481674261>::store(commands_, s);
}

void bots_setBotCommands::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(85399130);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1739401518>>, 481674261>::store(commands_, s);
}

void bots_setBotCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setBotCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("lang_code", lang_code_);
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

bots_setBotCommands::ReturnType bots_setBotCommands::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_setBotMenuButton::bots_setBotMenuButton(object_ptr<InputUser> &&user_id_, object_ptr<BotMenuButton> &&button_)
  : user_id_(std::move(user_id_))
  , button_(std::move(button_))
{}

const std::int32_t bots_setBotMenuButton::ID;

void bots_setBotMenuButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1157944655);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(button_, s);
}

void bots_setBotMenuButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1157944655);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(button_, s);
}

void bots_setBotMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setBotMenuButton");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    s.store_class_end();
  }
}

bots_setBotMenuButton::ReturnType bots_setBotMenuButton::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_updateStarRefProgram::bots_updateStarRefProgram(int32 flags_, object_ptr<InputUser> &&bot_, int32 commission_permille_, int32 duration_months_)
  : flags_(flags_)
  , bot_(std::move(bot_))
  , commission_permille_(commission_permille_)
  , duration_months_(duration_months_)
{}

const std::int32_t bots_updateStarRefProgram::ID;

void bots_updateStarRefProgram::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2005621427);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(commission_permille_, s);
  if (var0 & 1) { TlStoreBinary::store(duration_months_, s); }
}

void bots_updateStarRefProgram::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2005621427);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(commission_permille_, s);
  if (var0 & 1) { TlStoreBinary::store(duration_months_, s); }
}

void bots_updateStarRefProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.updateStarRefProgram");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("commission_permille", commission_permille_);
    if (var0 & 1) { s.store_field("duration_months", duration_months_); }
    s.store_class_end();
  }
}

bots_updateStarRefProgram::ReturnType bots_updateStarRefProgram::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<starRefProgram>, -586389774>::parse(p);
#undef FAIL
}

channels_checkSearchPostsFlood::channels_checkSearchPostsFlood(int32 flags_, string const &query_)
  : flags_(flags_)
  , query_(query_)
{}

const std::int32_t channels_checkSearchPostsFlood::ID;

void channels_checkSearchPostsFlood::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(576090389);
  TlStoreBinary::store((var0 = flags_ | ((!query_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(query_, s); }
}

void channels_checkSearchPostsFlood::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(576090389);
  TlStoreBinary::store((var0 = flags_ | ((!query_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(query_, s); }
}

void channels_checkSearchPostsFlood::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.checkSearchPostsFlood");
    s.store_field("flags", (var0 = flags_ | ((!query_.empty()) << 0)));
    if (var0 & 1) { s.store_field("query", query_); }
    s.store_class_end();
  }
}

channels_checkSearchPostsFlood::ReturnType channels_checkSearchPostsFlood::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<searchPostsFlood>, 1040931690>::parse(p);
#undef FAIL
}

channels_deactivateAllUsernames::channels_deactivateAllUsernames(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_deactivateAllUsernames::ID;

void channels_deactivateAllUsernames::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(170155475);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_deactivateAllUsernames::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(170155475);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_deactivateAllUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.deactivateAllUsernames");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_deactivateAllUsernames::ReturnType channels_deactivateAllUsernames::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_editLocation::channels_editLocation(object_ptr<InputChannel> &&channel_, object_ptr<InputGeoPoint> &&geo_point_, string const &address_)
  : channel_(std::move(channel_))
  , geo_point_(std::move(geo_point_))
  , address_(address_)
{}

const std::int32_t channels_editLocation::ID;

void channels_editLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1491484525);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(address_, s);
}

void channels_editLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1491484525);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(address_, s);
}

void channels_editLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.editLocation");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_field("address", address_);
    s.store_class_end();
  }
}

channels_editLocation::ReturnType channels_editLocation::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_editPhoto::channels_editPhoto(object_ptr<InputChannel> &&channel_, object_ptr<InputChatPhoto> &&photo_)
  : channel_(std::move(channel_))
  , photo_(std::move(photo_))
{}

const std::int32_t channels_editPhoto::ID;

void channels_editPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-248621111);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
}

void channels_editPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-248621111);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
}

void channels_editPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.editPhoto");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

channels_editPhoto::ReturnType channels_editPhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_getLeftChannels::channels_getLeftChannels(int32 offset_)
  : offset_(offset_)
{}

const std::int32_t channels_getLeftChannels::ID;

void channels_getLeftChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2092831552);
  TlStoreBinary::store(offset_, s);
}

void channels_getLeftChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2092831552);
  TlStoreBinary::store(offset_, s);
}

void channels_getLeftChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getLeftChannels");
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

channels_getLeftChannels::ReturnType channels_getLeftChannels::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

channels_toggleAntiSpam::channels_toggleAntiSpam(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_toggleAntiSpam::ID;

void channels_toggleAntiSpam::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1760814315);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleAntiSpam::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1760814315);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleAntiSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleAntiSpam");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_toggleAntiSpam::ReturnType channels_toggleAntiSpam::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_toggleForum::channels_toggleForum(object_ptr<InputChannel> &&channel_, bool enabled_, bool tabs_, bool sidebar_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
  , tabs_(tabs_)
  , sidebar_(sidebar_)
{}

const std::int32_t channels_toggleForum::ID;

void channels_toggleForum::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1567282348);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
  TlStoreBool::store(tabs_, s);
  TlStoreBool::store(sidebar_, s);
}

void channels_toggleForum::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1567282348);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
  TlStoreBool::store(tabs_, s);
  TlStoreBool::store(sidebar_, s);
}

void channels_toggleForum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleForum");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_field("tabs", tabs_);
    s.store_field("sidebar", sidebar_);
    s.store_class_end();
  }
}

channels_toggleForum::ReturnType channels_toggleForum::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_updateColor::channels_updateColor(int32 flags_, bool for_profile_, object_ptr<InputChannel> &&channel_, int32 color_, int64 background_emoji_id_)
  : flags_(flags_)
  , for_profile_(for_profile_)
  , channel_(std::move(channel_))
  , color_(color_)
  , background_emoji_id_(background_emoji_id_)
{}

const std::int32_t channels_updateColor::ID;

void channels_updateColor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-659933583);
  TlStoreBinary::store((var0 = flags_ | (for_profile_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  if (var0 & 4) { TlStoreBinary::store(color_, s); }
  if (var0 & 1) { TlStoreBinary::store(background_emoji_id_, s); }
}

void channels_updateColor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-659933583);
  TlStoreBinary::store((var0 = flags_ | (for_profile_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  if (var0 & 4) { TlStoreBinary::store(color_, s); }
  if (var0 & 1) { TlStoreBinary::store(background_emoji_id_, s); }
}

void channels_updateColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.updateColor");
    s.store_field("flags", (var0 = flags_ | (for_profile_ << 1)));
    if (var0 & 2) { s.store_field("for_profile", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    if (var0 & 4) { s.store_field("color", color_); }
    if (var0 & 1) { s.store_field("background_emoji_id", background_emoji_id_); }
    s.store_class_end();
  }
}

channels_updateColor::ReturnType channels_updateColor::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t communities_getJoinedCommunities::ID;

void communities_getJoinedCommunities::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1503401936);
}

void communities_getJoinedCommunities::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1503401936);
}

void communities_getJoinedCommunities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities.getJoinedCommunities");
    s.store_class_end();
  }
}

communities_getJoinedCommunities::ReturnType communities_getJoinedCommunities::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

contacts_exportNoPaidMessagesToken::contacts_exportNoPaidMessagesToken(int32 flags_, bool revoke_, bool temporary_)
  : flags_(flags_)
  , revoke_(revoke_)
  , temporary_(temporary_)
{}

const std::int32_t contacts_exportNoPaidMessagesToken::ID;

void contacts_exportNoPaidMessagesToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2084206930);
  TlStoreBinary::store((var0 = flags_ | (revoke_ << 0) | (temporary_ << 1)), s);
}

void contacts_exportNoPaidMessagesToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2084206930);
  TlStoreBinary::store((var0 = flags_ | (revoke_ << 0) | (temporary_ << 1)), s);
}

void contacts_exportNoPaidMessagesToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.exportNoPaidMessagesToken");
    s.store_field("flags", (var0 = flags_ | (revoke_ << 0) | (temporary_ << 1)));
    if (var0 & 1) { s.store_field("revoke", true); }
    if (var0 & 2) { s.store_field("temporary", true); }
    s.store_class_end();
  }
}

contacts_exportNoPaidMessagesToken::ReturnType contacts_exportNoPaidMessagesToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<exportedNoPaidMessagesToken>, 1767755842>::parse(p);
#undef FAIL
}

ephemeral_deleteAllWelcomeMessages::ephemeral_deleteAllWelcomeMessages(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t ephemeral_deleteAllWelcomeMessages::ID;

void ephemeral_deleteAllWelcomeMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1934595873);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void ephemeral_deleteAllWelcomeMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1934595873);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void ephemeral_deleteAllWelcomeMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeral.deleteAllWelcomeMessages");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

ephemeral_deleteAllWelcomeMessages::ReturnType ephemeral_deleteAllWelcomeMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

help_getPassportConfig::help_getPassportConfig(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t help_getPassportConfig::ID;

void help_getPassportConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-966677240);
  TlStoreBinary::store(hash_, s);
}

void help_getPassportConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-966677240);
  TlStoreBinary::store(hash_, s);
}

void help_getPassportConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getPassportConfig");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getPassportConfig::ReturnType help_getPassportConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_PassportConfig>::parse(p);
#undef FAIL
}

help_getPeerProfileColors::help_getPeerProfileColors(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t help_getPeerProfileColors::ID;

void help_getPeerProfileColors::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1412453891);
  TlStoreBinary::store(hash_, s);
}

void help_getPeerProfileColors::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1412453891);
  TlStoreBinary::store(hash_, s);
}

void help_getPeerProfileColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getPeerProfileColors");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getPeerProfileColors::ReturnType help_getPeerProfileColors::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_PeerColors>::parse(p);
#undef FAIL
}

const std::int32_t help_getPremiumPromo::ID;

void help_getPremiumPromo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1206152236);
}

void help_getPremiumPromo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1206152236);
}

void help_getPremiumPromo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getPremiumPromo");
    s.store_class_end();
  }
}

help_getPremiumPromo::ReturnType help_getPremiumPromo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_premiumPromo>, 1395946908>::parse(p);
#undef FAIL
}

const std::int32_t help_getSupport::ID;

void help_getSupport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1663104819);
}

void help_getSupport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1663104819);
}

void help_getSupport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getSupport");
    s.store_class_end();
  }
}

help_getSupport::ReturnType help_getSupport::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_support>, 398898678>::parse(p);
#undef FAIL
}

invokeWithBusinessConnectionPrefix::invokeWithBusinessConnectionPrefix(string const &connection_id_)
  : connection_id_(connection_id_)
{}

const std::int32_t invokeWithBusinessConnectionPrefix::ID;

void invokeWithBusinessConnectionPrefix::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-584540274);
  TlStoreString::store(connection_id_, s);
}

void invokeWithBusinessConnectionPrefix::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-584540274);
  TlStoreString::store(connection_id_, s);
}

void invokeWithBusinessConnectionPrefix::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invokeWithBusinessConnectionPrefix");
    s.store_field("connection_id", connection_id_);
    s.store_class_end();
  }
}

invokeWithBusinessConnectionPrefix::ReturnType invokeWithBusinessConnectionPrefix::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<error>, -994444869>::parse(p);
#undef FAIL
}

const std::int32_t messages_clearRecentReactions::ID;

void messages_clearRecentReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1644236876);
}

void messages_clearRecentReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1644236876);
}

void messages_clearRecentReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.clearRecentReactions");
    s.store_class_end();
  }
}

messages_clearRecentReactions::ReturnType messages_clearRecentReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_clickSponsoredMessage::messages_clickSponsoredMessage(int32 flags_, bool media_, bool fullscreen_, bytes &&random_id_)
  : flags_(flags_)
  , media_(media_)
  , fullscreen_(fullscreen_)
  , random_id_(std::move(random_id_))
{}

const std::int32_t messages_clickSponsoredMessage::ID;

void messages_clickSponsoredMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2110454402);
  TlStoreBinary::store((var0 = flags_ | (media_ << 0) | (fullscreen_ << 1)), s);
  TlStoreString::store(random_id_, s);
}

void messages_clickSponsoredMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2110454402);
  TlStoreBinary::store((var0 = flags_ | (media_ << 0) | (fullscreen_ << 1)), s);
  TlStoreString::store(random_id_, s);
}

void messages_clickSponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.clickSponsoredMessage");
    s.store_field("flags", (var0 = flags_ | (media_ << 0) | (fullscreen_ << 1)));
    if (var0 & 1) { s.store_field("media", true); }
    if (var0 & 2) { s.store_field("fullscreen", true); }
    s.store_bytes_field("random_id", random_id_);
    s.store_class_end();
  }
}

messages_clickSponsoredMessage::ReturnType messages_clickSponsoredMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_composeMessageWithAI::messages_composeMessageWithAI(int32 flags_, bool proofread_, bool emojify_, object_ptr<textWithEntities> &&text_, string const &translate_to_lang_, object_ptr<InputAiComposeTone> &&tone_)
  : flags_(flags_)
  , proofread_(proofread_)
  , emojify_(emojify_)
  , text_(std::move(text_))
  , translate_to_lang_(translate_to_lang_)
  , tone_(std::move(tone_))
{}

const std::int32_t messages_composeMessageWithAI::ID;

void messages_composeMessageWithAI::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-622017143);
  TlStoreBinary::store((var0 = flags_ | (proofread_ << 0) | (emojify_ << 3) | ((!translate_to_lang_.empty()) << 1) | ((tone_ != nullptr) << 2)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  if (var0 & 2) { TlStoreString::store(translate_to_lang_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s); }
}

void messages_composeMessageWithAI::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-622017143);
  TlStoreBinary::store((var0 = flags_ | (proofread_ << 0) | (emojify_ << 3) | ((!translate_to_lang_.empty()) << 1) | ((tone_ != nullptr) << 2)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  if (var0 & 2) { TlStoreString::store(translate_to_lang_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s); }
}

void messages_composeMessageWithAI::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.composeMessageWithAI");
    s.store_field("flags", (var0 = flags_ | (proofread_ << 0) | (emojify_ << 3) | ((!translate_to_lang_.empty()) << 1) | ((tone_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("proofread", true); }
    if (var0 & 8) { s.store_field("emojify", true); }
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    if (var0 & 2) { s.store_field("translate_to_lang", translate_to_lang_); }
    if (var0 & 4) { s.store_object_field("tone", static_cast<const BaseObject *>(tone_.get())); }
    s.store_class_end();
  }
}

messages_composeMessageWithAI::ReturnType messages_composeMessageWithAI::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_composedMessageWithAI>, -1864913414>::parse(p);
#undef FAIL
}

messages_deleteScheduledMessages::messages_deleteScheduledMessages(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_deleteScheduledMessages::ID;

void messages_deleteScheduledMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1504586518);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteScheduledMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1504586518);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteScheduledMessages");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_deleteScheduledMessages::ReturnType messages_deleteScheduledMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editChatParticipantRank::messages_editChatParticipantRank(object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&participant_, string const &rank_)
  : peer_(std::move(peer_))
  , participant_(std::move(participant_))
  , rank_(rank_)
{}

const std::int32_t messages_editChatParticipantRank::ID;

void messages_editChatParticipantRank::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1609616720);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreString::store(rank_, s);
}

void messages_editChatParticipantRank::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1609616720);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreString::store(rank_, s);
}

void messages_editChatParticipantRank::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatParticipantRank");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_field("rank", rank_);
    s.store_class_end();
  }
}

messages_editChatParticipantRank::ReturnType messages_editChatParticipantRank::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getEmojiStickerGroups::messages_getEmojiStickerGroups(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getEmojiStickerGroups::ID;

void messages_getEmojiStickerGroups::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(500711669);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStickerGroups::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(500711669);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStickerGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiStickerGroups");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getEmojiStickerGroups::ReturnType messages_getEmojiStickerGroups::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_EmojiGroups>::parse(p);
#undef FAIL
}

messages_getFeaturedEmojiStickers::messages_getFeaturedEmojiStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getFeaturedEmojiStickers::ID;

void messages_getFeaturedEmojiStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(248473398);
  TlStoreBinary::store(hash_, s);
}

void messages_getFeaturedEmojiStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(248473398);
  TlStoreBinary::store(hash_, s);
}

void messages_getFeaturedEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFeaturedEmojiStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getFeaturedEmojiStickers::ReturnType messages_getFeaturedEmojiStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FeaturedStickers>::parse(p);
#undef FAIL
}

messages_getInlineGameHighScores::messages_getInlineGameHighScores(object_ptr<InputBotInlineMessageID> &&id_, object_ptr<InputUser> &&user_id_)
  : id_(std::move(id_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t messages_getInlineGameHighScores::ID;

void messages_getInlineGameHighScores::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(258170395);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_getInlineGameHighScores::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(258170395);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_getInlineGameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getInlineGameHighScores");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

messages_getInlineGameHighScores::ReturnType messages_getInlineGameHighScores::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_highScores>, -1707344487>::parse(p);
#undef FAIL
}

messages_getRecentStickers::messages_getRecentStickers(int32 flags_, bool attached_, int64 hash_)
  : flags_(flags_)
  , attached_(attached_)
  , hash_(hash_)
{}

const std::int32_t messages_getRecentStickers::ID;

void messages_getRecentStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1649852357);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1649852357);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getRecentStickers");
    s.store_field("flags", (var0 = flags_ | (attached_ << 0)));
    if (var0 & 1) { s.store_field("attached", true); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getRecentStickers::ReturnType messages_getRecentStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_RecentStickers>::parse(p);
#undef FAIL
}

messages_getStickerSet::messages_getStickerSet(object_ptr<InputStickerSet> &&stickerset_, int32 hash_)
  : stickerset_(std::move(stickerset_))
  , hash_(hash_)
{}

const std::int32_t messages_getStickerSet::ID;

void messages_getStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-928977804);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-928977804);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getStickerSet::ReturnType messages_getStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

messages_getStickers::messages_getStickers(string const &emoticon_, int64 hash_)
  : emoticon_(emoticon_)
  , hash_(hash_)
{}

const std::int32_t messages_getStickers::ID;

void messages_getStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-710552671);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-710552671);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getStickers");
    s.store_field("emoticon", emoticon_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getStickers::ReturnType messages_getStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Stickers>::parse(p);
#undef FAIL
}

messages_getUnreadReactions::messages_getUnreadReactions(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, object_ptr<InputPeer> &&saved_peer_id_, int32 offset_id_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , saved_peer_id_(std::move(saved_peer_id_))
  , offset_id_(offset_id_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
{}

const std::int32_t messages_getUnreadReactions::ID;

void messages_getUnreadReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1115713364);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1115713364);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getUnreadReactions");
    s.store_field("flags", (var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_field("offset_id", offset_id_);
    s.store_field("add_offset", add_offset_);
    s.store_field("limit", limit_);
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_class_end();
  }
}

messages_getUnreadReactions::ReturnType messages_getUnreadReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getWidgetPublicData::messages_getWidgetPublicData(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 hash_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , hash_(hash_)
{}

const std::int32_t messages_getWidgetPublicData::ID;

void messages_getWidgetPublicData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1875194241);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getWidgetPublicData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1875194241);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getWidgetPublicData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getWidgetPublicData");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getWidgetPublicData::ReturnType messages_getWidgetPublicData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_WidgetPublicData>::parse(p);
#undef FAIL
}

messages_rateTranscribedAudio::messages_rateTranscribedAudio(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 transcription_id_, bool good_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , transcription_id_(transcription_id_)
  , good_(good_)
{}

const std::int32_t messages_rateTranscribedAudio::ID;

void messages_rateTranscribedAudio::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2132608815);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(transcription_id_, s);
  TlStoreBool::store(good_, s);
}

void messages_rateTranscribedAudio::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2132608815);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(transcription_id_, s);
  TlStoreBool::store(good_, s);
}

void messages_rateTranscribedAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.rateTranscribedAudio");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("transcription_id", transcription_id_);
    s.store_field("good", good_);
    s.store_class_end();
  }
}

messages_rateTranscribedAudio::ReturnType messages_rateTranscribedAudio::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_readMessageContents::messages_readMessageContents(array<int32> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t messages_readMessageContents::ID;

void messages_readMessageContents::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(916930423);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_readMessageContents::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(916930423);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_readMessageContents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readMessageContents");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_readMessageContents::ReturnType messages_readMessageContents::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedMessages>, -2066640507>::parse(p);
#undef FAIL
}

messages_reorderPinnedSavedDialogs::messages_reorderPinnedSavedDialogs(int32 flags_, bool force_, array<object_ptr<InputDialogPeer>> &&order_)
  : flags_(flags_)
  , force_(force_)
  , order_(std::move(order_))
{}

const std::int32_t messages_reorderPinnedSavedDialogs::ID;

void messages_reorderPinnedSavedDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1955502713);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void messages_reorderPinnedSavedDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1955502713);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void messages_reorderPinnedSavedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reorderPinnedSavedDialogs");
    s.store_field("flags", (var0 = flags_ | (force_ << 0)));
    if (var0 & 1) { s.store_field("force", true); }
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reorderPinnedSavedDialogs::ReturnType messages_reorderPinnedSavedDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_reportSponsoredMessage::messages_reportSponsoredMessage(bytes &&random_id_, bytes &&option_)
  : random_id_(std::move(random_id_))
  , option_(std::move(option_))
{}

const std::int32_t messages_reportSponsoredMessage::ID;

void messages_reportSponsoredMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(315355332);
  TlStoreString::store(random_id_, s);
  TlStoreString::store(option_, s);
}

void messages_reportSponsoredMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(315355332);
  TlStoreString::store(random_id_, s);
  TlStoreString::store(option_, s);
}

void messages_reportSponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportSponsoredMessage");
    s.store_bytes_field("random_id", random_id_);
    s.store_bytes_field("option", option_);
    s.store_class_end();
  }
}

messages_reportSponsoredMessage::ReturnType messages_reportSponsoredMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<channels_SponsoredMessageReportResult>::parse(p);
#undef FAIL
}

messages_saveGif::messages_saveGif(object_ptr<InputDocument> &&id_, bool unsave_)
  : id_(std::move(id_))
  , unsave_(unsave_)
{}

const std::int32_t messages_saveGif::ID;

void messages_saveGif::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(846868683);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void messages_saveGif::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(846868683);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void messages_saveGif::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.saveGif");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("unsave", unsave_);
    s.store_class_end();
  }
}

messages_saveGif::ReturnType messages_saveGif::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_saveRecentSticker::messages_saveRecentSticker(int32 flags_, bool attached_, object_ptr<InputDocument> &&id_, bool unsave_)
  : flags_(flags_)
  , attached_(attached_)
  , id_(std::move(id_))
  , unsave_(unsave_)
{}

const std::int32_t messages_saveRecentSticker::ID;

void messages_saveRecentSticker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(958863608);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void messages_saveRecentSticker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(958863608);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void messages_saveRecentSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.saveRecentSticker");
    s.store_field("flags", (var0 = flags_ | (attached_ << 0)));
    if (var0 & 1) { s.store_field("attached", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("unsave", unsave_);
    s.store_class_end();
  }
}

messages_saveRecentSticker::ReturnType messages_saveRecentSticker::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_search::messages_search(int32 flags_, object_ptr<InputPeer> &&peer_, string const &q_, object_ptr<InputPeer> &&from_id_, object_ptr<InputPeer> &&saved_peer_id_, array<object_ptr<Reaction>> &&saved_reaction_, int32 top_msg_id_, object_ptr<MessagesFilter> &&filter_, int32 min_date_, int32 max_date_, int32 offset_id_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_, int64 hash_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , q_(q_)
  , from_id_(std::move(from_id_))
  , saved_peer_id_(std::move(saved_peer_id_))
  , saved_reaction_(std::move(saved_reaction_))
  , top_msg_id_(top_msg_id_)
  , filter_(std::move(filter_))
  , min_date_(min_date_)
  , max_date_(max_date_)
  , offset_id_(offset_id_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
  , hash_(hash_)
{}

const std::int32_t messages_search::ID;

void messages_search::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(703497338);
  TlStoreBinary::store((var0 = flags_ | ((from_id_ != nullptr) << 0) | ((saved_peer_id_ != nullptr) << 2) | ((!saved_reaction_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(q_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(from_id_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(saved_reaction_, s); }
  if (var0 & 2) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(min_date_, s);
  TlStoreBinary::store(max_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_search::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(703497338);
  TlStoreBinary::store((var0 = flags_ | ((from_id_ != nullptr) << 0) | ((saved_peer_id_ != nullptr) << 2) | ((!saved_reaction_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(q_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(from_id_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(saved_reaction_, s); }
  if (var0 & 2) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(min_date_, s);
  TlStoreBinary::store(max_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_search::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.search");
    s.store_field("flags", (var0 = flags_ | ((from_id_ != nullptr) << 0) | ((saved_peer_id_ != nullptr) << 2) | ((!saved_reaction_.empty()) << 3)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("q", q_);
    if (var0 & 1) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 4) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    if (var0 & 8) { { s.store_vector_begin("saved_reaction", saved_reaction_.size()); for (const auto &_value : saved_reaction_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_field("offset_id", offset_id_);
    s.store_field("add_offset", add_offset_);
    s.store_field("limit", limit_);
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_search::ReturnType messages_search::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_searchSentMedia::messages_searchSentMedia(string const &q_, object_ptr<MessagesFilter> &&filter_, int32 limit_)
  : q_(q_)
  , filter_(std::move(filter_))
  , limit_(limit_)
{}

const std::int32_t messages_searchSentMedia::ID;

void messages_searchSentMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(276705696);
  TlStoreString::store(q_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_searchSentMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(276705696);
  TlStoreString::store(q_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_searchSentMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchSentMedia");
    s.store_field("q", q_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_searchSentMedia::ReturnType messages_searchSentMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_sendVote::messages_sendVote(object_ptr<InputPeer> &&peer_, int32 msg_id_, array<bytes> &&options_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , options_(std::move(options_))
{}

const std::int32_t messages_sendVote::ID;

void messages_sendVote::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(283795844);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(options_, s);
}

void messages_sendVote::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(283795844);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(options_, s);
}

void messages_sendVote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendVote");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_sendVote::ReturnType messages_sendVote::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setBotGuestChatResult::messages_setBotGuestChatResult(int64 query_id_, object_ptr<InputBotInlineResult> &&result_)
  : query_id_(query_id_)
  , result_(std::move(result_))
{}

const std::int32_t messages_setBotGuestChatResult::ID;

void messages_setBotGuestChatResult::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1192163613);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
}

void messages_setBotGuestChatResult::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1192163613);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
}

void messages_setBotGuestChatResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setBotGuestChatResult");
    s.store_field("query_id", query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_class_end();
  }
}

messages_setBotGuestChatResult::ReturnType messages_setBotGuestChatResult::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<InputBotInlineMessageID>::parse(p);
#undef FAIL
}

messages_setBotPrecheckoutResults::messages_setBotPrecheckoutResults(int32 flags_, bool success_, int64 query_id_, string const &error_)
  : flags_(flags_)
  , success_(success_)
  , query_id_(query_id_)
  , error_(error_)
{}

const std::int32_t messages_setBotPrecheckoutResults::ID;

void messages_setBotPrecheckoutResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(163765653);
  TlStoreBinary::store((var0 = flags_ | (success_ << 1) | ((!error_.empty()) << 0)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
}

void messages_setBotPrecheckoutResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(163765653);
  TlStoreBinary::store((var0 = flags_ | (success_ << 1) | ((!error_.empty()) << 0)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
}

void messages_setBotPrecheckoutResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setBotPrecheckoutResults");
    s.store_field("flags", (var0 = flags_ | (success_ << 1) | ((!error_.empty()) << 0)));
    if (var0 & 2) { s.store_field("success", true); }
    s.store_field("query_id", query_id_);
    if (var0 & 1) { s.store_field("error", error_); }
    s.store_class_end();
  }
}

messages_setBotPrecheckoutResults::ReturnType messages_setBotPrecheckoutResults::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_setDefaultHistoryTTL::messages_setDefaultHistoryTTL(int32 period_)
  : period_(period_)
{}

const std::int32_t messages_setDefaultHistoryTTL::ID;

void messages_setDefaultHistoryTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1632299963);
  TlStoreBinary::store(period_, s);
}

void messages_setDefaultHistoryTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1632299963);
  TlStoreBinary::store(period_, s);
}

void messages_setDefaultHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setDefaultHistoryTTL");
    s.store_field("period", period_);
    s.store_class_end();
  }
}

messages_setDefaultHistoryTTL::ReturnType messages_setDefaultHistoryTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_startHistoryImport::messages_startHistoryImport(object_ptr<InputPeer> &&peer_, int64 import_id_)
  : peer_(std::move(peer_))
  , import_id_(import_id_)
{}

const std::int32_t messages_startHistoryImport::ID;

void messages_startHistoryImport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1271008444);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(import_id_, s);
}

void messages_startHistoryImport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1271008444);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(import_id_, s);
}

void messages_startHistoryImport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.startHistoryImport");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("import_id", import_id_);
    s.store_class_end();
  }
}

messages_startHistoryImport::ReturnType messages_startHistoryImport::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_togglePeerTranslations::messages_togglePeerTranslations(int32 flags_, bool disabled_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , disabled_(disabled_)
  , peer_(std::move(peer_))
{}

const std::int32_t messages_togglePeerTranslations::ID;

void messages_togglePeerTranslations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-461589127);
  TlStoreBinary::store((var0 = flags_ | (disabled_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_togglePeerTranslations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-461589127);
  TlStoreBinary::store((var0 = flags_ | (disabled_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_togglePeerTranslations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.togglePeerTranslations");
    s.store_field("flags", (var0 = flags_ | (disabled_ << 0)));
    if (var0 & 1) { s.store_field("disabled", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_togglePeerTranslations::ReturnType messages_togglePeerTranslations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_uninstallStickerSet::messages_uninstallStickerSet(object_ptr<InputStickerSet> &&stickerset_)
  : stickerset_(std::move(stickerset_))
{}

const std::int32_t messages_uninstallStickerSet::ID;

void messages_uninstallStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-110209570);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void messages_uninstallStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-110209570);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void messages_uninstallStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.uninstallStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

messages_uninstallStickerSet::ReturnType messages_uninstallStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_getConnectedStarRefBots::payments_getConnectedStarRefBots(int32 flags_, object_ptr<InputPeer> &&peer_, int32 offset_date_, string const &offset_link_, int32 limit_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , offset_date_(offset_date_)
  , offset_link_(offset_link_)
  , limit_(limit_)
{}

const std::int32_t payments_getConnectedStarRefBots::ID;

void payments_getConnectedStarRefBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1483318611);
  TlStoreBinary::store((var0 = flags_ | ((!offset_link_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBinary::store(offset_date_, s); }
  if (var0 & 4) { TlStoreString::store(offset_link_, s); }
  TlStoreBinary::store(limit_, s);
}

void payments_getConnectedStarRefBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1483318611);
  TlStoreBinary::store((var0 = flags_ | ((!offset_link_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBinary::store(offset_date_, s); }
  if (var0 & 4) { TlStoreString::store(offset_link_, s); }
  TlStoreBinary::store(limit_, s);
}

void payments_getConnectedStarRefBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getConnectedStarRefBots");
    s.store_field("flags", (var0 = flags_ | ((!offset_link_.empty()) << 2)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 4) { s.store_field("offset_date", offset_date_); }
    if (var0 & 4) { s.store_field("offset_link", offset_link_); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getConnectedStarRefBots::ReturnType payments_getConnectedStarRefBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_connectedStarRefBots>, -1730811363>::parse(p);
#undef FAIL
}

const std::int32_t payments_getStarsTopupOptions::ID;

void payments_getStarsTopupOptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1072773165);
}

void payments_getStarsTopupOptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1072773165);
}

void payments_getStarsTopupOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsTopupOptions");
    s.store_class_end();
  }
}

payments_getStarsTopupOptions::ReturnType payments_getStarsTopupOptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsTopupOption>, 198776256>>, 481674261>::parse(p);
#undef FAIL
}

payments_launchPrepaidGiveaway::payments_launchPrepaidGiveaway(object_ptr<InputPeer> &&peer_, int64 giveaway_id_, object_ptr<InputStorePaymentPurpose> &&purpose_)
  : peer_(std::move(peer_))
  , giveaway_id_(giveaway_id_)
  , purpose_(std::move(purpose_))
{}

const std::int32_t payments_launchPrepaidGiveaway::ID;

void payments_launchPrepaidGiveaway::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1609928480);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(giveaway_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_launchPrepaidGiveaway::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1609928480);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(giveaway_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_launchPrepaidGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.launchPrepaidGiveaway");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("giveaway_id", giveaway_id_);
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

payments_launchPrepaidGiveaway::ReturnType payments_launchPrepaidGiveaway::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_withdrawStarsRevenueToWallet::payments_withdrawStarsRevenueToWallet(int32 flags_, bool ton_, object_ptr<InputPeer> &&peer_, int64 amount_, bytes &&tmp_password_)
  : flags_(flags_)
  , ton_(ton_)
  , peer_(std::move(peer_))
  , amount_(amount_)
  , tmp_password_(std::move(tmp_password_))
{}

const std::int32_t payments_withdrawStarsRevenueToWallet::ID;

void payments_withdrawStarsRevenueToWallet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1461184265);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreBinary::store(amount_, s); }
  TlStoreString::store(tmp_password_, s);
}

void payments_withdrawStarsRevenueToWallet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1461184265);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreBinary::store(amount_, s); }
  TlStoreString::store(tmp_password_, s);
}

void payments_withdrawStarsRevenueToWallet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.withdrawStarsRevenueToWallet");
    s.store_field("flags", (var0 = flags_ | (ton_ << 0)));
    if (var0 & 1) { s.store_field("ton", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_field("amount", amount_); }
    s.store_field("tmp_password", "[REDACTED]");
    s.store_class_end();
  }
}

payments_withdrawStarsRevenueToWallet::ReturnType payments_withdrawStarsRevenueToWallet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_editGroupCallTitle::phone_editGroupCallTitle(object_ptr<InputGroupCall> &&call_, string const &title_)
  : call_(std::move(call_))
  , title_(title_)
{}

const std::int32_t phone_editGroupCallTitle::ID;

void phone_editGroupCallTitle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(480685066);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(title_, s);
}

void phone_editGroupCallTitle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(480685066);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(title_, s);
}

void phone_editGroupCallTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.editGroupCallTitle");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

phone_editGroupCallTitle::ReturnType phone_editGroupCallTitle::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_getGroupCallStreamChannels::phone_getGroupCallStreamChannels(object_ptr<InputGroupCall> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t phone_getGroupCallStreamChannels::ID;

void phone_getGroupCallStreamChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(447879488);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_getGroupCallStreamChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(447879488);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_getGroupCallStreamChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCallStreamChannels");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_getGroupCallStreamChannels::ReturnType phone_getGroupCallStreamChannels::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_groupCallStreamChannels>, -790330702>::parse(p);
#undef FAIL
}

phone_receivedCall::phone_receivedCall(object_ptr<inputPhoneCall> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t phone_receivedCall::ID;

void phone_receivedCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(399855457);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
}

void phone_receivedCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(399855457);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
}

void phone_receivedCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.receivedCall");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

phone_receivedCall::ReturnType phone_receivedCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_saveCallDebug::phone_saveCallDebug(object_ptr<inputPhoneCall> &&peer_, object_ptr<dataJSON> &&debug_)
  : peer_(std::move(peer_))
  , debug_(std::move(debug_))
{}

const std::int32_t phone_saveCallDebug::ID;

void phone_saveCallDebug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(662363518);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(debug_, s);
}

void phone_saveCallDebug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(662363518);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(debug_, s);
}

void phone_saveCallDebug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.saveCallDebug");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("debug", static_cast<const BaseObject *>(debug_.get()));
    s.store_class_end();
  }
}

phone_saveCallDebug::ReturnType phone_saveCallDebug::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t premium_getMyBoosts::ID;

void premium_getMyBoosts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(199719754);
}

void premium_getMyBoosts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(199719754);
}

void premium_getMyBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.getMyBoosts");
    s.store_class_end();
  }
}

premium_getMyBoosts::ReturnType premium_getMyBoosts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<premium_myBoosts>, -1696454430>::parse(p);
#undef FAIL
}

stats_getPollStats::stats_getPollStats(int32 flags_, bool dark_, object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : flags_(flags_)
  , dark_(dark_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t stats_getPollStats::ID;

void stats_getPollStats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1031931288);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void stats_getPollStats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1031931288);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void stats_getPollStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getPollStats");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0)));
    if (var0 & 1) { s.store_field("dark", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

stats_getPollStats::ReturnType stats_getPollStats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_pollStats>, 697941741>::parse(p);
#undef FAIL
}

stats_getStoryStats::stats_getStoryStats(int32 flags_, bool dark_, object_ptr<InputPeer> &&peer_, int32 id_)
  : flags_(flags_)
  , dark_(dark_)
  , peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t stats_getStoryStats::ID;

void stats_getStoryStats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(927985472);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void stats_getStoryStats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(927985472);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void stats_getStoryStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getStoryStats");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0)));
    if (var0 & 1) { s.store_field("dark", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

stats_getStoryStats::ReturnType stats_getStoryStats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_storyStats>, 1355613820>::parse(p);
#undef FAIL
}

stories_incrementStoryViews::stories_incrementStoryViews(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t stories_incrementStoryViews::ID;

void stories_incrementStoryViews::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1308456197);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_incrementStoryViews::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1308456197);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_incrementStoryViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.incrementStoryViews");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_incrementStoryViews::ReturnType stories_incrementStoryViews::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stories_sendStory::stories_sendStory(int32 flags_, bool pinned_, bool noforwards_, bool fwd_modified_, object_ptr<InputPeer> &&peer_, object_ptr<InputMedia> &&media_, array<object_ptr<MediaArea>> &&media_areas_, string const &caption_, array<object_ptr<MessageEntity>> &&entities_, array<object_ptr<InputPrivacyRule>> &&privacy_rules_, int64 random_id_, int32 period_, object_ptr<InputPeer> &&fwd_from_id_, int32 fwd_from_story_, array<int32> &&albums_, object_ptr<InputDocument> &&music_)
  : flags_(flags_)
  , pinned_(pinned_)
  , noforwards_(noforwards_)
  , fwd_modified_(fwd_modified_)
  , peer_(std::move(peer_))
  , media_(std::move(media_))
  , media_areas_(std::move(media_areas_))
  , caption_(caption_)
  , entities_(std::move(entities_))
  , privacy_rules_(std::move(privacy_rules_))
  , random_id_(random_id_)
  , period_(period_)
  , fwd_from_id_(std::move(fwd_from_id_))
  , fwd_from_story_(fwd_from_story_)
  , albums_(std::move(albums_))
  , music_(std::move(music_))
{}

const std::int32_t stories_sendStory::ID;

void stories_sendStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1885443944);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (fwd_modified_ << 7) | ((!media_areas_.empty()) << 5) | ((!caption_.empty()) << 0) | ((!entities_.empty()) << 1) | ((fwd_from_id_ != nullptr) << 6) | ((!albums_.empty()) << 8) | ((music_ != nullptr) << 9)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  if (var0 & 32) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 8) { TlStoreBinary::store(period_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(fwd_from_id_, s); }
  if (var0 & 64) { TlStoreBinary::store(fwd_from_story_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(albums_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void stories_sendStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1885443944);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (fwd_modified_ << 7) | ((!media_areas_.empty()) << 5) | ((!caption_.empty()) << 0) | ((!entities_.empty()) << 1) | ((fwd_from_id_ != nullptr) << 6) | ((!albums_.empty()) << 8) | ((music_ != nullptr) << 9)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  if (var0 & 32) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 8) { TlStoreBinary::store(period_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(fwd_from_id_, s); }
  if (var0 & 64) { TlStoreBinary::store(fwd_from_story_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(albums_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void stories_sendStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.sendStory");
    s.store_field("flags", (var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (fwd_modified_ << 7) | ((!media_areas_.empty()) << 5) | ((!caption_.empty()) << 0) | ((!entities_.empty()) << 1) | ((fwd_from_id_ != nullptr) << 6) | ((!albums_.empty()) << 8) | ((music_ != nullptr) << 9)));
    if (var0 & 4) { s.store_field("pinned", true); }
    if (var0 & 16) { s.store_field("noforwards", true); }
    if (var0 & 128) { s.store_field("fwd_modified", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    if (var0 & 32) { { s.store_vector_begin("media_areas", media_areas_.size()); for (const auto &_value : media_areas_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1) { s.store_field("caption", caption_); }
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("privacy_rules", privacy_rules_.size()); for (const auto &_value : privacy_rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("random_id", random_id_);
    if (var0 & 8) { s.store_field("period", period_); }
    if (var0 & 64) { s.store_object_field("fwd_from_id", static_cast<const BaseObject *>(fwd_from_id_.get())); }
    if (var0 & 64) { s.store_field("fwd_from_story", fwd_from_story_); }
    if (var0 & 256) { { s.store_vector_begin("albums", albums_.size()); for (const auto &_value : albums_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 512) { s.store_object_field("music", static_cast<const BaseObject *>(music_.get())); }
    s.store_class_end();
  }
}

stories_sendStory::ReturnType stories_sendStory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

updates_getDifference::updates_getDifference(int32 flags_, int32 pts_, int32 pts_limit_, int32 pts_total_limit_, int32 date_, int32 qts_, int32 qts_limit_)
  : flags_(flags_)
  , pts_(pts_)
  , pts_limit_(pts_limit_)
  , pts_total_limit_(pts_total_limit_)
  , date_(date_)
  , qts_(qts_)
  , qts_limit_(qts_limit_)
{}

const std::int32_t updates_getDifference::ID;

void updates_getDifference::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(432207715);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(pts_, s);
  if (var0 & 2) { TlStoreBinary::store(pts_limit_, s); }
  if (var0 & 1) { TlStoreBinary::store(pts_total_limit_, s); }
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(qts_, s);
  if (var0 & 4) { TlStoreBinary::store(qts_limit_, s); }
}

void updates_getDifference::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(432207715);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(pts_, s);
  if (var0 & 2) { TlStoreBinary::store(pts_limit_, s); }
  if (var0 & 1) { TlStoreBinary::store(pts_total_limit_, s); }
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(qts_, s);
  if (var0 & 4) { TlStoreBinary::store(qts_limit_, s); }
}

void updates_getDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.getDifference");
    s.store_field("flags", (var0 = flags_));
    s.store_field("pts", pts_);
    if (var0 & 2) { s.store_field("pts_limit", pts_limit_); }
    if (var0 & 1) { s.store_field("pts_total_limit", pts_total_limit_); }
    s.store_field("date", date_);
    s.store_field("qts", qts_);
    if (var0 & 4) { s.store_field("qts_limit", qts_limit_); }
    s.store_class_end();
  }
}

updates_getDifference::ReturnType updates_getDifference::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<updates_Difference>::parse(p);
#undef FAIL
}

wallet_exportSecretPhrase::wallet_exportSecretPhrase(int32 flags_, object_ptr<InputCheckPasswordSRP> &&password_)
  : flags_(flags_)
  , password_(std::move(password_))
{}

const std::int32_t wallet_exportSecretPhrase::ID;

void wallet_exportSecretPhrase::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1871197780);
  TlStoreBinary::store((var0 = flags_ | ((password_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void wallet_exportSecretPhrase::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1871197780);
  TlStoreBinary::store((var0 = flags_ | ((password_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void wallet_exportSecretPhrase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.exportSecretPhrase");
    s.store_field("flags", (var0 = flags_ | ((password_ != nullptr) << 0)));
    if (var0 & 1) { s.store_field("password", "[REDACTED]"); }
    s.store_class_end();
  }
}

wallet_exportSecretPhrase::ReturnType wallet_exportSecretPhrase::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_secretPhraseParts>, -422514943>::parse(p);
#undef FAIL
}

wallet_fetchEncryptedSecretPhrasePart::wallet_fetchEncryptedSecretPhrasePart(string const &token_, bytes &&public_key_)
  : token_(token_)
  , public_key_(std::move(public_key_))
{}

const std::int32_t wallet_fetchEncryptedSecretPhrasePart::ID;

void wallet_fetchEncryptedSecretPhrasePart::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-180804145);
  TlStoreString::store(token_, s);
  TlStoreString::store(public_key_, s);
}

void wallet_fetchEncryptedSecretPhrasePart::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-180804145);
  TlStoreString::store(token_, s);
  TlStoreString::store(public_key_, s);
}

void wallet_fetchEncryptedSecretPhrasePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.fetchEncryptedSecretPhrasePart");
    s.store_field("token", "[REDACTED]");
    s.store_bytes_field("public_key", public_key_);
    s.store_class_end();
  }
}

wallet_fetchEncryptedSecretPhrasePart::ReturnType wallet_fetchEncryptedSecretPhrasePart::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_encryptedSecretPhrasePart>, 417867063>::parse(p);
#undef FAIL
}

wallet_getNfts::wallet_getNfts(string const &offset_, int32 limit_)
  : offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t wallet_getNfts::ID;

void wallet_getNfts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1944915036);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void wallet_getNfts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1944915036);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void wallet_getNfts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.getNfts");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

wallet_getNfts::ReturnType wallet_getNfts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_nftItems>, 2035107951>::parse(p);
#undef FAIL
}

wallet_setCardStickers::wallet_setCardStickers(int32 flags_, array<object_ptr<inputWalletCardSticker>> &&stickers_, string const &bg_nft_address_)
  : flags_(flags_)
  , stickers_(std::move(stickers_))
  , bg_nft_address_(bg_nft_address_)
{}

const std::int32_t wallet_setCardStickers::ID;

void wallet_setCardStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(109382060);
  TlStoreBinary::store((var0 = flags_ | ((!bg_nft_address_.empty()) << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1474250151>>, 481674261>::store(stickers_, s);
  if (var0 & 1) { TlStoreString::store(bg_nft_address_, s); }
}

void wallet_setCardStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(109382060);
  TlStoreBinary::store((var0 = flags_ | ((!bg_nft_address_.empty()) << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1474250151>>, 481674261>::store(stickers_, s);
  if (var0 & 1) { TlStoreString::store(bg_nft_address_, s); }
}

void wallet_setCardStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.setCardStickers");
    s.store_field("flags", (var0 = flags_ | ((!bg_nft_address_.empty()) << 0)));
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("bg_nft_address", bg_nft_address_); }
    s.store_class_end();
  }
}

wallet_setCardStickers::ReturnType wallet_setCardStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_card>, -1898953807>::parse(p);
#undef FAIL
}

wallet_tonConnectCreateSession::wallet_tonConnectCreateSession(string const &dapp_client_id_, string const &manifest_url_)
  : dapp_client_id_(dapp_client_id_)
  , manifest_url_(manifest_url_)
{}

const std::int32_t wallet_tonConnectCreateSession::ID;

void wallet_tonConnectCreateSession::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-862777274);
  TlStoreString::store(dapp_client_id_, s);
  TlStoreString::store(manifest_url_, s);
}

void wallet_tonConnectCreateSession::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-862777274);
  TlStoreString::store(dapp_client_id_, s);
  TlStoreString::store(manifest_url_, s);
}

void wallet_tonConnectCreateSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectCreateSession");
    s.store_field("dapp_client_id", dapp_client_id_);
    s.store_field("manifest_url", manifest_url_);
    s.store_class_end();
  }
}

wallet_tonConnectCreateSession::ReturnType wallet_tonConnectCreateSession::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<tonConnectSession>, 308631238>::parse(p);
#undef FAIL
}

const std::int32_t wallet_tonConnectGetSessions::ID;

void wallet_tonConnectGetSessions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1476414098);
}

void wallet_tonConnectGetSessions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1476414098);
}

void wallet_tonConnectGetSessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectGetSessions");
    s.store_class_end();
  }
}

wallet_tonConnectGetSessions::ReturnType wallet_tonConnectGetSessions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_tonConnectSessions>, 236939414>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
