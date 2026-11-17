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


attachMenuBotIcon::attachMenuBotIcon()
  : flags_()
  , name_()
  , icon_()
  , colors_()
{}

const std::int32_t attachMenuBotIcon::ID;

object_ptr<attachMenuBotIcon> attachMenuBotIcon::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<attachMenuBotIcon> res = make_tl_object<attachMenuBotIcon>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->name_ = TlFetchString<string>::parse(p);
  res->icon_ = TlFetchObject<Document>::parse(p);
  if (var0 & 1) { res->colors_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<attachMenuBotIconColor>, 1165423600>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void attachMenuBotIcon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBotIcon");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!colors_.empty()) << 0)));
    s.store_field("name", name_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    if (var0 & 1) { { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t auctionBidLevel::ID;

object_ptr<auctionBidLevel> auctionBidLevel::fetch(TlBufferParser &p) {
  return make_tl_object<auctionBidLevel>(p);
}

auctionBidLevel::auctionBidLevel(TlBufferParser &p)
  : pos_(TlFetchInt::parse(p))
  , amount_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void auctionBidLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auctionBidLevel");
    s.store_field("pos", pos_);
    s.store_field("amount", amount_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<BotInlineMessage> BotInlineMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case botInlineMessageMediaAuto::ID:
      return botInlineMessageMediaAuto::fetch(p);
    case botInlineMessageText::ID:
      return botInlineMessageText::fetch(p);
    case botInlineMessageMediaGeo::ID:
      return botInlineMessageMediaGeo::fetch(p);
    case botInlineMessageMediaVenue::ID:
      return botInlineMessageMediaVenue::fetch(p);
    case botInlineMessageMediaContact::ID:
      return botInlineMessageMediaContact::fetch(p);
    case botInlineMessageMediaInvoice::ID:
      return botInlineMessageMediaInvoice::fetch(p);
    case botInlineMessageMediaWebPage::ID:
      return botInlineMessageMediaWebPage::fetch(p);
    case botInlineMessageRichMessage::ID:
      return botInlineMessageRichMessage::fetch(p);
    case botInlineMessageWidget::ID:
      return botInlineMessageWidget::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

botInlineMessageMediaAuto::botInlineMessageMediaAuto()
  : flags_()
  , invert_media_()
  , message_()
  , entities_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaAuto::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaAuto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaAuto> res = make_tl_object<botInlineMessageMediaAuto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->invert_media_ = (var0 & 8) != 0;
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaAuto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaAuto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 3) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)));
    if (var0 & 8) { s.store_field("invert_media", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageText::botInlineMessageText()
  : flags_()
  , no_webpage_()
  , invert_media_()
  , message_()
  , entities_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageText::ID;

object_ptr<BotInlineMessage> botInlineMessageText::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageText> res = make_tl_object<botInlineMessageText>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->no_webpage_ = (var0 & 1) != 0;
  res->invert_media_ = (var0 & 8) != 0;
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageText");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 0) | (invert_media_ << 3) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("no_webpage", true); }
    if (var0 & 8) { s.store_field("invert_media", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageMediaGeo::botInlineMessageMediaGeo()
  : flags_()
  , geo_()
  , heading_()
  , period_()
  , proximity_notification_radius_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaGeo::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaGeo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaGeo> res = make_tl_object<botInlineMessageMediaGeo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->geo_ = TlFetchObject<GeoPoint>::parse(p);
  if (var0 & 1) { res->heading_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->period_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->proximity_notification_radius_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaGeo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaGeo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_markup_ != nullptr) << 2)));
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    if (var0 & 1) { s.store_field("heading", heading_); }
    if (var0 & 2) { s.store_field("period", period_); }
    if (var0 & 8) { s.store_field("proximity_notification_radius", proximity_notification_radius_); }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageMediaVenue::botInlineMessageMediaVenue()
  : flags_()
  , geo_()
  , title_()
  , address_()
  , provider_()
  , venue_id_()
  , venue_type_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaVenue::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaVenue::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaVenue> res = make_tl_object<botInlineMessageMediaVenue>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->geo_ = TlFetchObject<GeoPoint>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->address_ = TlFetchString<string>::parse(p);
  res->provider_ = TlFetchString<string>::parse(p);
  res->venue_id_ = TlFetchString<string>::parse(p);
  res->venue_type_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaVenue");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_markup_ != nullptr) << 2)));
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("venue_type", venue_type_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageMediaContact::botInlineMessageMediaContact()
  : flags_()
  , phone_number_()
  , first_name_()
  , last_name_()
  , vcard_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaContact::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaContact::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaContact> res = make_tl_object<botInlineMessageMediaContact>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->phone_number_ = TlFetchString<string>::parse(p);
  res->first_name_ = TlFetchString<string>::parse(p);
  res->last_name_ = TlFetchString<string>::parse(p);
  res->vcard_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaContact");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_markup_ != nullptr) << 2)));
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("vcard", vcard_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageMediaInvoice::botInlineMessageMediaInvoice()
  : flags_()
  , shipping_address_requested_()
  , test_()
  , title_()
  , description_()
  , photo_()
  , currency_()
  , total_amount_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaInvoice::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaInvoice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaInvoice> res = make_tl_object<botInlineMessageMediaInvoice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->shipping_address_requested_ = (var0 & 2) != 0;
  res->test_ = (var0 & 8) != 0;
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaInvoice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (shipping_address_requested_ << 1) | (test_ << 3) | ((photo_ != nullptr) << 0) | ((reply_markup_ != nullptr) << 2)));
    if (var0 & 2) { s.store_field("shipping_address_requested", true); }
    if (var0 & 8) { s.store_field("test", true); }
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageMediaWebPage::botInlineMessageMediaWebPage()
  : flags_()
  , invert_media_()
  , force_large_media_()
  , force_small_media_()
  , manual_()
  , safe_()
  , message_()
  , entities_()
  , url_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaWebPage::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaWebPage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaWebPage> res = make_tl_object<botInlineMessageMediaWebPage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->invert_media_ = (var0 & 8) != 0;
  res->force_large_media_ = (var0 & 16) != 0;
  res->force_small_media_ = (var0 & 32) != 0;
  res->manual_ = (var0 & 128) != 0;
  res->safe_ = (var0 & 256) != 0;
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  res->url_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaWebPage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 3) | (force_large_media_ << 4) | (force_small_media_ << 5) | (manual_ << 7) | (safe_ << 8) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)));
    if (var0 & 8) { s.store_field("invert_media", true); }
    if (var0 & 16) { s.store_field("force_large_media", true); }
    if (var0 & 32) { s.store_field("force_small_media", true); }
    if (var0 & 128) { s.store_field("manual", true); }
    if (var0 & 256) { s.store_field("safe", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("url", url_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageRichMessage::botInlineMessageRichMessage()
  : flags_()
  , reply_markup_()
  , rich_message_()
{}

const std::int32_t botInlineMessageRichMessage::ID;

object_ptr<BotInlineMessage> botInlineMessageRichMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageRichMessage> res = make_tl_object<botInlineMessageRichMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  res->rich_message_ = TlFetchBoxed<TlFetchObject<richMessage>, -1158439541>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageRichMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_markup_ != nullptr) << 2)));
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get()));
    s.store_class_end();
  }
}

botInlineMessageWidget::botInlineMessageWidget()
  : flags_()
  , invert_media_()
  , width_()
  , height_()
  , payload_()
  , public_data_()
  , public_data_hash_()
  , chat_data_()
  , reply_markup_()
  , widget_id_()
  , message_()
  , entities_()
{}

const std::int32_t botInlineMessageWidget::ID;

object_ptr<BotInlineMessage> botInlineMessageWidget::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageWidget> res = make_tl_object<botInlineMessageWidget>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->invert_media_ = (var0 & 32) != 0;
  res->width_ = TlFetchInt::parse(p);
  res->height_ = TlFetchInt::parse(p);
  res->payload_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 1) { res->public_data_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->public_data_hash_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->chat_data_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (var0 & 8) { res->widget_id_ = TlFetchLong::parse(p); }
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 16) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageWidget::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageWidget");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 5) | ((!public_data_.empty()) << 0) | ((!chat_data_.empty()) << 1) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 4)));
    if (var0 & 32) { s.store_field("invert_media", true); }
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_bytes_field("payload", payload_);
    if (var0 & 1) { s.store_field("public_data", public_data_); }
    if (var0 & 1) { s.store_field("public_data_hash", public_data_hash_); }
    if (var0 & 2) { s.store_field("chat_data", chat_data_); }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 8) { s.store_field("widget_id", widget_id_); }
    s.store_field("message", message_);
    if (var0 & 16) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

object_ptr<BotMenuButton> BotMenuButton::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case botMenuButtonDefault::ID:
      return botMenuButtonDefault::fetch(p);
    case botMenuButtonCommands::ID:
      return botMenuButtonCommands::fetch(p);
    case botMenuButton::ID:
      return botMenuButton::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t botMenuButtonDefault::ID;

object_ptr<BotMenuButton> botMenuButtonDefault::fetch(TlBufferParser &p) {
  return make_tl_object<botMenuButtonDefault>();
}

void botMenuButtonDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botMenuButtonDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botMenuButtonDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMenuButtonDefault");
    s.store_class_end();
  }
}

const std::int32_t botMenuButtonCommands::ID;

object_ptr<BotMenuButton> botMenuButtonCommands::fetch(TlBufferParser &p) {
  return make_tl_object<botMenuButtonCommands>();
}

void botMenuButtonCommands::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botMenuButtonCommands::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botMenuButtonCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMenuButtonCommands");
    s.store_class_end();
  }
}

botMenuButton::botMenuButton(string const &text_, string const &url_)
  : text_(text_)
  , url_(url_)
{}

const std::int32_t botMenuButton::ID;

object_ptr<BotMenuButton> botMenuButton::fetch(TlBufferParser &p) {
  return make_tl_object<botMenuButton>(p);
}

botMenuButton::botMenuButton(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void botMenuButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void botMenuButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void botMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMenuButton");
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

const std::int32_t botPreviewMedia::ID;

object_ptr<botPreviewMedia> botPreviewMedia::fetch(TlBufferParser &p) {
  return make_tl_object<botPreviewMedia>(p);
}

botPreviewMedia::botPreviewMedia(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , media_(TlFetchObject<MessageMedia>::parse(p))
{}

void botPreviewMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botPreviewMedia");
    s.store_field("date", date_);
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

businessIntro::businessIntro()
  : flags_()
  , title_()
  , description_()
  , sticker_()
{}

const std::int32_t businessIntro::ID;

object_ptr<businessIntro> businessIntro::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessIntro> res = make_tl_object<businessIntro>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->sticker_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessIntro::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessIntro");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((sticker_ != nullptr) << 0)));
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get())); }
    s.store_class_end();
  }
}

object_ptr<ChannelAdminLogEventAction> ChannelAdminLogEventAction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case channelAdminLogEventActionChangeTitle::ID:
      return channelAdminLogEventActionChangeTitle::fetch(p);
    case channelAdminLogEventActionChangeAbout::ID:
      return channelAdminLogEventActionChangeAbout::fetch(p);
    case channelAdminLogEventActionChangeUsername::ID:
      return channelAdminLogEventActionChangeUsername::fetch(p);
    case channelAdminLogEventActionChangePhoto::ID:
      return channelAdminLogEventActionChangePhoto::fetch(p);
    case channelAdminLogEventActionToggleInvites::ID:
      return channelAdminLogEventActionToggleInvites::fetch(p);
    case channelAdminLogEventActionToggleSignatures::ID:
      return channelAdminLogEventActionToggleSignatures::fetch(p);
    case channelAdminLogEventActionUpdatePinned::ID:
      return channelAdminLogEventActionUpdatePinned::fetch(p);
    case channelAdminLogEventActionEditMessage::ID:
      return channelAdminLogEventActionEditMessage::fetch(p);
    case channelAdminLogEventActionDeleteMessage::ID:
      return channelAdminLogEventActionDeleteMessage::fetch(p);
    case channelAdminLogEventActionParticipantJoin::ID:
      return channelAdminLogEventActionParticipantJoin::fetch(p);
    case channelAdminLogEventActionParticipantLeave::ID:
      return channelAdminLogEventActionParticipantLeave::fetch(p);
    case channelAdminLogEventActionParticipantInvite::ID:
      return channelAdminLogEventActionParticipantInvite::fetch(p);
    case channelAdminLogEventActionParticipantToggleBan::ID:
      return channelAdminLogEventActionParticipantToggleBan::fetch(p);
    case channelAdminLogEventActionParticipantToggleAdmin::ID:
      return channelAdminLogEventActionParticipantToggleAdmin::fetch(p);
    case channelAdminLogEventActionChangeStickerSet::ID:
      return channelAdminLogEventActionChangeStickerSet::fetch(p);
    case channelAdminLogEventActionTogglePreHistoryHidden::ID:
      return channelAdminLogEventActionTogglePreHistoryHidden::fetch(p);
    case channelAdminLogEventActionDefaultBannedRights::ID:
      return channelAdminLogEventActionDefaultBannedRights::fetch(p);
    case channelAdminLogEventActionStopPoll::ID:
      return channelAdminLogEventActionStopPoll::fetch(p);
    case channelAdminLogEventActionChangeLinkedChat::ID:
      return channelAdminLogEventActionChangeLinkedChat::fetch(p);
    case channelAdminLogEventActionChangeLocation::ID:
      return channelAdminLogEventActionChangeLocation::fetch(p);
    case channelAdminLogEventActionToggleSlowMode::ID:
      return channelAdminLogEventActionToggleSlowMode::fetch(p);
    case channelAdminLogEventActionStartGroupCall::ID:
      return channelAdminLogEventActionStartGroupCall::fetch(p);
    case channelAdminLogEventActionDiscardGroupCall::ID:
      return channelAdminLogEventActionDiscardGroupCall::fetch(p);
    case channelAdminLogEventActionParticipantMute::ID:
      return channelAdminLogEventActionParticipantMute::fetch(p);
    case channelAdminLogEventActionParticipantUnmute::ID:
      return channelAdminLogEventActionParticipantUnmute::fetch(p);
    case channelAdminLogEventActionToggleGroupCallSetting::ID:
      return channelAdminLogEventActionToggleGroupCallSetting::fetch(p);
    case channelAdminLogEventActionParticipantJoinByInvite::ID:
      return channelAdminLogEventActionParticipantJoinByInvite::fetch(p);
    case channelAdminLogEventActionExportedInviteDelete::ID:
      return channelAdminLogEventActionExportedInviteDelete::fetch(p);
    case channelAdminLogEventActionExportedInviteRevoke::ID:
      return channelAdminLogEventActionExportedInviteRevoke::fetch(p);
    case channelAdminLogEventActionExportedInviteEdit::ID:
      return channelAdminLogEventActionExportedInviteEdit::fetch(p);
    case channelAdminLogEventActionParticipantVolume::ID:
      return channelAdminLogEventActionParticipantVolume::fetch(p);
    case channelAdminLogEventActionChangeHistoryTTL::ID:
      return channelAdminLogEventActionChangeHistoryTTL::fetch(p);
    case channelAdminLogEventActionParticipantJoinByRequest::ID:
      return channelAdminLogEventActionParticipantJoinByRequest::fetch(p);
    case channelAdminLogEventActionToggleNoForwards::ID:
      return channelAdminLogEventActionToggleNoForwards::fetch(p);
    case channelAdminLogEventActionSendMessage::ID:
      return channelAdminLogEventActionSendMessage::fetch(p);
    case channelAdminLogEventActionChangeAvailableReactions::ID:
      return channelAdminLogEventActionChangeAvailableReactions::fetch(p);
    case channelAdminLogEventActionChangeUsernames::ID:
      return channelAdminLogEventActionChangeUsernames::fetch(p);
    case channelAdminLogEventActionToggleForum::ID:
      return channelAdminLogEventActionToggleForum::fetch(p);
    case channelAdminLogEventActionCreateTopic::ID:
      return channelAdminLogEventActionCreateTopic::fetch(p);
    case channelAdminLogEventActionEditTopic::ID:
      return channelAdminLogEventActionEditTopic::fetch(p);
    case channelAdminLogEventActionDeleteTopic::ID:
      return channelAdminLogEventActionDeleteTopic::fetch(p);
    case channelAdminLogEventActionPinTopic::ID:
      return channelAdminLogEventActionPinTopic::fetch(p);
    case channelAdminLogEventActionToggleAntiSpam::ID:
      return channelAdminLogEventActionToggleAntiSpam::fetch(p);
    case channelAdminLogEventActionChangePeerColor::ID:
      return channelAdminLogEventActionChangePeerColor::fetch(p);
    case channelAdminLogEventActionChangeProfilePeerColor::ID:
      return channelAdminLogEventActionChangeProfilePeerColor::fetch(p);
    case channelAdminLogEventActionChangeWallpaper::ID:
      return channelAdminLogEventActionChangeWallpaper::fetch(p);
    case channelAdminLogEventActionChangeEmojiStatus::ID:
      return channelAdminLogEventActionChangeEmojiStatus::fetch(p);
    case channelAdminLogEventActionChangeEmojiStickerSet::ID:
      return channelAdminLogEventActionChangeEmojiStickerSet::fetch(p);
    case channelAdminLogEventActionToggleSignatureProfiles::ID:
      return channelAdminLogEventActionToggleSignatureProfiles::fetch(p);
    case channelAdminLogEventActionParticipantSubExtend::ID:
      return channelAdminLogEventActionParticipantSubExtend::fetch(p);
    case channelAdminLogEventActionToggleAutotranslation::ID:
      return channelAdminLogEventActionToggleAutotranslation::fetch(p);
    case channelAdminLogEventActionParticipantEditRank::ID:
      return channelAdminLogEventActionParticipantEditRank::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t channelAdminLogEventActionChangeTitle::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeTitle::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeTitle>(p);
}

channelAdminLogEventActionChangeTitle::channelAdminLogEventActionChangeTitle(TlBufferParser &p)
  : prev_value_(TlFetchString<string>::parse(p))
  , new_value_(TlFetchString<string>::parse(p))
{}

void channelAdminLogEventActionChangeTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeTitle");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeAbout::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeAbout::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeAbout>(p);
}

channelAdminLogEventActionChangeAbout::channelAdminLogEventActionChangeAbout(TlBufferParser &p)
  : prev_value_(TlFetchString<string>::parse(p))
  , new_value_(TlFetchString<string>::parse(p))
{}

void channelAdminLogEventActionChangeAbout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeAbout");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeUsername::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeUsername::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeUsername>(p);
}

channelAdminLogEventActionChangeUsername::channelAdminLogEventActionChangeUsername(TlBufferParser &p)
  : prev_value_(TlFetchString<string>::parse(p))
  , new_value_(TlFetchString<string>::parse(p))
{}

void channelAdminLogEventActionChangeUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeUsername");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangePhoto::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangePhoto::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangePhoto>(p);
}

channelAdminLogEventActionChangePhoto::channelAdminLogEventActionChangePhoto(TlBufferParser &p)
  : prev_photo_(TlFetchObject<Photo>::parse(p))
  , new_photo_(TlFetchObject<Photo>::parse(p))
{}

void channelAdminLogEventActionChangePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangePhoto");
    s.store_object_field("prev_photo", static_cast<const BaseObject *>(prev_photo_.get()));
    s.store_object_field("new_photo", static_cast<const BaseObject *>(new_photo_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleInvites::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleInvites::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleInvites>(p);
}

channelAdminLogEventActionToggleInvites::channelAdminLogEventActionToggleInvites(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleInvites");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleSignatures::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleSignatures::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleSignatures>(p);
}

channelAdminLogEventActionToggleSignatures::channelAdminLogEventActionToggleSignatures(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleSignatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleSignatures");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionUpdatePinned::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionUpdatePinned::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionUpdatePinned>(p);
}

channelAdminLogEventActionUpdatePinned::channelAdminLogEventActionUpdatePinned(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void channelAdminLogEventActionUpdatePinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionUpdatePinned");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionEditMessage::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionEditMessage::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionEditMessage>(p);
}

channelAdminLogEventActionEditMessage::channelAdminLogEventActionEditMessage(TlBufferParser &p)
  : prev_message_(TlFetchObject<Message>::parse(p))
  , new_message_(TlFetchObject<Message>::parse(p))
{}

void channelAdminLogEventActionEditMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionEditMessage");
    s.store_object_field("prev_message", static_cast<const BaseObject *>(prev_message_.get()));
    s.store_object_field("new_message", static_cast<const BaseObject *>(new_message_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionDeleteMessage::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionDeleteMessage::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionDeleteMessage>(p);
}

channelAdminLogEventActionDeleteMessage::channelAdminLogEventActionDeleteMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void channelAdminLogEventActionDeleteMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionDeleteMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantJoin::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantJoin::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantJoin>();
}

void channelAdminLogEventActionParticipantJoin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantJoin");
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantLeave::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantLeave::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantLeave>();
}

void channelAdminLogEventActionParticipantLeave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantLeave");
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantInvite::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantInvite::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantInvite>(p);
}

channelAdminLogEventActionParticipantInvite::channelAdminLogEventActionParticipantInvite(TlBufferParser &p)
  : participant_(TlFetchObject<ChannelParticipant>::parse(p))
{}

void channelAdminLogEventActionParticipantInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantInvite");
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantToggleBan::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantToggleBan::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantToggleBan>(p);
}

channelAdminLogEventActionParticipantToggleBan::channelAdminLogEventActionParticipantToggleBan(TlBufferParser &p)
  : prev_participant_(TlFetchObject<ChannelParticipant>::parse(p))
  , new_participant_(TlFetchObject<ChannelParticipant>::parse(p))
{}

void channelAdminLogEventActionParticipantToggleBan::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantToggleBan");
    s.store_object_field("prev_participant", static_cast<const BaseObject *>(prev_participant_.get()));
    s.store_object_field("new_participant", static_cast<const BaseObject *>(new_participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantToggleAdmin::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantToggleAdmin::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantToggleAdmin>(p);
}

channelAdminLogEventActionParticipantToggleAdmin::channelAdminLogEventActionParticipantToggleAdmin(TlBufferParser &p)
  : prev_participant_(TlFetchObject<ChannelParticipant>::parse(p))
  , new_participant_(TlFetchObject<ChannelParticipant>::parse(p))
{}

void channelAdminLogEventActionParticipantToggleAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantToggleAdmin");
    s.store_object_field("prev_participant", static_cast<const BaseObject *>(prev_participant_.get()));
    s.store_object_field("new_participant", static_cast<const BaseObject *>(new_participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeStickerSet::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeStickerSet::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeStickerSet>(p);
}

channelAdminLogEventActionChangeStickerSet::channelAdminLogEventActionChangeStickerSet(TlBufferParser &p)
  : prev_stickerset_(TlFetchObject<InputStickerSet>::parse(p))
  , new_stickerset_(TlFetchObject<InputStickerSet>::parse(p))
{}

void channelAdminLogEventActionChangeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeStickerSet");
    s.store_object_field("prev_stickerset", static_cast<const BaseObject *>(prev_stickerset_.get()));
    s.store_object_field("new_stickerset", static_cast<const BaseObject *>(new_stickerset_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionTogglePreHistoryHidden::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionTogglePreHistoryHidden::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionTogglePreHistoryHidden>(p);
}

channelAdminLogEventActionTogglePreHistoryHidden::channelAdminLogEventActionTogglePreHistoryHidden(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionTogglePreHistoryHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionTogglePreHistoryHidden");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionDefaultBannedRights::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionDefaultBannedRights::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionDefaultBannedRights>(p);
}

channelAdminLogEventActionDefaultBannedRights::channelAdminLogEventActionDefaultBannedRights(TlBufferParser &p)
  : prev_banned_rights_(TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p))
  , new_banned_rights_(TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p))
{}

void channelAdminLogEventActionDefaultBannedRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionDefaultBannedRights");
    s.store_object_field("prev_banned_rights", static_cast<const BaseObject *>(prev_banned_rights_.get()));
    s.store_object_field("new_banned_rights", static_cast<const BaseObject *>(new_banned_rights_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionStopPoll::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionStopPoll::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionStopPoll>(p);
}

channelAdminLogEventActionStopPoll::channelAdminLogEventActionStopPoll(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void channelAdminLogEventActionStopPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionStopPoll");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeLinkedChat::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeLinkedChat::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeLinkedChat>(p);
}

channelAdminLogEventActionChangeLinkedChat::channelAdminLogEventActionChangeLinkedChat(TlBufferParser &p)
  : prev_value_(TlFetchLong::parse(p))
  , new_value_(TlFetchLong::parse(p))
{}

void channelAdminLogEventActionChangeLinkedChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeLinkedChat");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeLocation::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeLocation::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeLocation>(p);
}

channelAdminLogEventActionChangeLocation::channelAdminLogEventActionChangeLocation(TlBufferParser &p)
  : prev_value_(TlFetchObject<ChannelLocation>::parse(p))
  , new_value_(TlFetchObject<ChannelLocation>::parse(p))
{}

void channelAdminLogEventActionChangeLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeLocation");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleSlowMode::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleSlowMode::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleSlowMode>(p);
}

channelAdminLogEventActionToggleSlowMode::channelAdminLogEventActionToggleSlowMode(TlBufferParser &p)
  : prev_value_(TlFetchInt::parse(p))
  , new_value_(TlFetchInt::parse(p))
{}

void channelAdminLogEventActionToggleSlowMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleSlowMode");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionStartGroupCall::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionStartGroupCall::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionStartGroupCall>(p);
}

channelAdminLogEventActionStartGroupCall::channelAdminLogEventActionStartGroupCall(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
{}

void channelAdminLogEventActionStartGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionStartGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionDiscardGroupCall::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionDiscardGroupCall::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionDiscardGroupCall>(p);
}

channelAdminLogEventActionDiscardGroupCall::channelAdminLogEventActionDiscardGroupCall(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
{}

void channelAdminLogEventActionDiscardGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionDiscardGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantMute::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantMute::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantMute>(p);
}

channelAdminLogEventActionParticipantMute::channelAdminLogEventActionParticipantMute(TlBufferParser &p)
  : participant_(TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>::parse(p))
{}

void channelAdminLogEventActionParticipantMute::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantMute");
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantUnmute::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantUnmute::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantUnmute>(p);
}

channelAdminLogEventActionParticipantUnmute::channelAdminLogEventActionParticipantUnmute(TlBufferParser &p)
  : participant_(TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>::parse(p))
{}

void channelAdminLogEventActionParticipantUnmute::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantUnmute");
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleGroupCallSetting::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleGroupCallSetting::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleGroupCallSetting>(p);
}

channelAdminLogEventActionToggleGroupCallSetting::channelAdminLogEventActionToggleGroupCallSetting(TlBufferParser &p)
  : join_muted_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleGroupCallSetting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleGroupCallSetting");
    s.store_field("join_muted", join_muted_);
    s.store_class_end();
  }
}

channelAdminLogEventActionParticipantJoinByInvite::channelAdminLogEventActionParticipantJoinByInvite()
  : flags_()
  , via_chatlist_()
  , invite_()
{}

const std::int32_t channelAdminLogEventActionParticipantJoinByInvite::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantJoinByInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelAdminLogEventActionParticipantJoinByInvite> res = make_tl_object<channelAdminLogEventActionParticipantJoinByInvite>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_chatlist_ = (var0 & 1) != 0;
  res->invite_ = TlFetchObject<ExportedChatInvite>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelAdminLogEventActionParticipantJoinByInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantJoinByInvite");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_chatlist_ << 0)));
    if (var0 & 1) { s.store_field("via_chatlist", true); }
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionExportedInviteDelete::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionExportedInviteDelete::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionExportedInviteDelete>(p);
}

channelAdminLogEventActionExportedInviteDelete::channelAdminLogEventActionExportedInviteDelete(TlBufferParser &p)
  : invite_(TlFetchObject<ExportedChatInvite>::parse(p))
{}

void channelAdminLogEventActionExportedInviteDelete::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionExportedInviteDelete");
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionExportedInviteRevoke::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionExportedInviteRevoke::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionExportedInviteRevoke>(p);
}

channelAdminLogEventActionExportedInviteRevoke::channelAdminLogEventActionExportedInviteRevoke(TlBufferParser &p)
  : invite_(TlFetchObject<ExportedChatInvite>::parse(p))
{}

void channelAdminLogEventActionExportedInviteRevoke::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionExportedInviteRevoke");
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionExportedInviteEdit::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionExportedInviteEdit::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionExportedInviteEdit>(p);
}

channelAdminLogEventActionExportedInviteEdit::channelAdminLogEventActionExportedInviteEdit(TlBufferParser &p)
  : prev_invite_(TlFetchObject<ExportedChatInvite>::parse(p))
  , new_invite_(TlFetchObject<ExportedChatInvite>::parse(p))
{}

void channelAdminLogEventActionExportedInviteEdit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionExportedInviteEdit");
    s.store_object_field("prev_invite", static_cast<const BaseObject *>(prev_invite_.get()));
    s.store_object_field("new_invite", static_cast<const BaseObject *>(new_invite_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantVolume::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantVolume::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantVolume>(p);
}

channelAdminLogEventActionParticipantVolume::channelAdminLogEventActionParticipantVolume(TlBufferParser &p)
  : participant_(TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>::parse(p))
{}

void channelAdminLogEventActionParticipantVolume::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantVolume");
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeHistoryTTL::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeHistoryTTL::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeHistoryTTL>(p);
}

channelAdminLogEventActionChangeHistoryTTL::channelAdminLogEventActionChangeHistoryTTL(TlBufferParser &p)
  : prev_value_(TlFetchInt::parse(p))
  , new_value_(TlFetchInt::parse(p))
{}

void channelAdminLogEventActionChangeHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeHistoryTTL");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantJoinByRequest::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantJoinByRequest::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantJoinByRequest>(p);
}

channelAdminLogEventActionParticipantJoinByRequest::channelAdminLogEventActionParticipantJoinByRequest(TlBufferParser &p)
  : invite_(TlFetchObject<ExportedChatInvite>::parse(p))
  , approved_by_(TlFetchLong::parse(p))
{}

void channelAdminLogEventActionParticipantJoinByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantJoinByRequest");
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_field("approved_by", approved_by_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleNoForwards::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleNoForwards::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleNoForwards>(p);
}

channelAdminLogEventActionToggleNoForwards::channelAdminLogEventActionToggleNoForwards(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleNoForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleNoForwards");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionSendMessage::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionSendMessage::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionSendMessage>(p);
}

channelAdminLogEventActionSendMessage::channelAdminLogEventActionSendMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void channelAdminLogEventActionSendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionSendMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeAvailableReactions::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeAvailableReactions::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeAvailableReactions>(p);
}

channelAdminLogEventActionChangeAvailableReactions::channelAdminLogEventActionChangeAvailableReactions(TlBufferParser &p)
  : prev_value_(TlFetchObject<ChatReactions>::parse(p))
  , new_value_(TlFetchObject<ChatReactions>::parse(p))
{}

void channelAdminLogEventActionChangeAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeAvailableReactions");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeUsernames::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeUsernames::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeUsernames>(p);
}

channelAdminLogEventActionChangeUsernames::channelAdminLogEventActionChangeUsernames(TlBufferParser &p)
  : prev_value_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
  , new_value_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void channelAdminLogEventActionChangeUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeUsernames");
    { s.store_vector_begin("prev_value", prev_value_.size()); for (const auto &_value : prev_value_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("new_value", new_value_.size()); for (const auto &_value : new_value_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleForum::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleForum::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleForum>(p);
}

channelAdminLogEventActionToggleForum::channelAdminLogEventActionToggleForum(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleForum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleForum");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionCreateTopic::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionCreateTopic::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionCreateTopic>(p);
}

channelAdminLogEventActionCreateTopic::channelAdminLogEventActionCreateTopic(TlBufferParser &p)
  : topic_(TlFetchObject<ForumTopic>::parse(p))
{}

void channelAdminLogEventActionCreateTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionCreateTopic");
    s.store_object_field("topic", static_cast<const BaseObject *>(topic_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionEditTopic::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionEditTopic::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionEditTopic>(p);
}

channelAdminLogEventActionEditTopic::channelAdminLogEventActionEditTopic(TlBufferParser &p)
  : prev_topic_(TlFetchObject<ForumTopic>::parse(p))
  , new_topic_(TlFetchObject<ForumTopic>::parse(p))
{}

void channelAdminLogEventActionEditTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionEditTopic");
    s.store_object_field("prev_topic", static_cast<const BaseObject *>(prev_topic_.get()));
    s.store_object_field("new_topic", static_cast<const BaseObject *>(new_topic_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionDeleteTopic::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionDeleteTopic::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionDeleteTopic>(p);
}

channelAdminLogEventActionDeleteTopic::channelAdminLogEventActionDeleteTopic(TlBufferParser &p)
  : topic_(TlFetchObject<ForumTopic>::parse(p))
{}

void channelAdminLogEventActionDeleteTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionDeleteTopic");
    s.store_object_field("topic", static_cast<const BaseObject *>(topic_.get()));
    s.store_class_end();
  }
}

channelAdminLogEventActionPinTopic::channelAdminLogEventActionPinTopic()
  : flags_()
  , prev_topic_()
  , new_topic_()
{}

const std::int32_t channelAdminLogEventActionPinTopic::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionPinTopic::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelAdminLogEventActionPinTopic> res = make_tl_object<channelAdminLogEventActionPinTopic>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->prev_topic_ = TlFetchObject<ForumTopic>::parse(p); }
  if (var0 & 2) { res->new_topic_ = TlFetchObject<ForumTopic>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelAdminLogEventActionPinTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionPinTopic");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((prev_topic_ != nullptr) << 0) | ((new_topic_ != nullptr) << 1)));
    if (var0 & 1) { s.store_object_field("prev_topic", static_cast<const BaseObject *>(prev_topic_.get())); }
    if (var0 & 2) { s.store_object_field("new_topic", static_cast<const BaseObject *>(new_topic_.get())); }
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleAntiSpam::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleAntiSpam::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleAntiSpam>(p);
}

channelAdminLogEventActionToggleAntiSpam::channelAdminLogEventActionToggleAntiSpam(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleAntiSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleAntiSpam");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangePeerColor::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangePeerColor::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangePeerColor>(p);
}

channelAdminLogEventActionChangePeerColor::channelAdminLogEventActionChangePeerColor(TlBufferParser &p)
  : prev_value_(TlFetchObject<PeerColor>::parse(p))
  , new_value_(TlFetchObject<PeerColor>::parse(p))
{}

void channelAdminLogEventActionChangePeerColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangePeerColor");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeProfilePeerColor::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeProfilePeerColor::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeProfilePeerColor>(p);
}

channelAdminLogEventActionChangeProfilePeerColor::channelAdminLogEventActionChangeProfilePeerColor(TlBufferParser &p)
  : prev_value_(TlFetchObject<PeerColor>::parse(p))
  , new_value_(TlFetchObject<PeerColor>::parse(p))
{}

void channelAdminLogEventActionChangeProfilePeerColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeProfilePeerColor");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeWallpaper::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeWallpaper::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeWallpaper>(p);
}

channelAdminLogEventActionChangeWallpaper::channelAdminLogEventActionChangeWallpaper(TlBufferParser &p)
  : prev_value_(TlFetchObject<WallPaper>::parse(p))
  , new_value_(TlFetchObject<WallPaper>::parse(p))
{}

void channelAdminLogEventActionChangeWallpaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeWallpaper");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeEmojiStatus::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeEmojiStatus::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeEmojiStatus>(p);
}

channelAdminLogEventActionChangeEmojiStatus::channelAdminLogEventActionChangeEmojiStatus(TlBufferParser &p)
  : prev_value_(TlFetchObject<EmojiStatus>::parse(p))
  , new_value_(TlFetchObject<EmojiStatus>::parse(p))
{}

void channelAdminLogEventActionChangeEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeEmojiStatus");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeEmojiStickerSet::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeEmojiStickerSet::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeEmojiStickerSet>(p);
}

channelAdminLogEventActionChangeEmojiStickerSet::channelAdminLogEventActionChangeEmojiStickerSet(TlBufferParser &p)
  : prev_stickerset_(TlFetchObject<InputStickerSet>::parse(p))
  , new_stickerset_(TlFetchObject<InputStickerSet>::parse(p))
{}

void channelAdminLogEventActionChangeEmojiStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeEmojiStickerSet");
    s.store_object_field("prev_stickerset", static_cast<const BaseObject *>(prev_stickerset_.get()));
    s.store_object_field("new_stickerset", static_cast<const BaseObject *>(new_stickerset_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleSignatureProfiles::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleSignatureProfiles::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleSignatureProfiles>(p);
}

channelAdminLogEventActionToggleSignatureProfiles::channelAdminLogEventActionToggleSignatureProfiles(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleSignatureProfiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleSignatureProfiles");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantSubExtend::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantSubExtend::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantSubExtend>(p);
}

channelAdminLogEventActionParticipantSubExtend::channelAdminLogEventActionParticipantSubExtend(TlBufferParser &p)
  : prev_participant_(TlFetchObject<ChannelParticipant>::parse(p))
  , new_participant_(TlFetchObject<ChannelParticipant>::parse(p))
{}

void channelAdminLogEventActionParticipantSubExtend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantSubExtend");
    s.store_object_field("prev_participant", static_cast<const BaseObject *>(prev_participant_.get()));
    s.store_object_field("new_participant", static_cast<const BaseObject *>(new_participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleAutotranslation::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleAutotranslation::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleAutotranslation>(p);
}

channelAdminLogEventActionToggleAutotranslation::channelAdminLogEventActionToggleAutotranslation(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleAutotranslation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleAutotranslation");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantEditRank::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantEditRank::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantEditRank>(p);
}

channelAdminLogEventActionParticipantEditRank::channelAdminLogEventActionParticipantEditRank(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , prev_rank_(TlFetchString<string>::parse(p))
  , new_rank_(TlFetchString<string>::parse(p))
{}

void channelAdminLogEventActionParticipantEditRank::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantEditRank");
    s.store_field("user_id", user_id_);
    s.store_field("prev_rank", prev_rank_);
    s.store_field("new_rank", new_rank_);
    s.store_class_end();
  }
}

object_ptr<ChatParticipant> ChatParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatParticipant::ID:
      return chatParticipant::fetch(p);
    case chatParticipantCreator::ID:
      return chatParticipantCreator::fetch(p);
    case chatParticipantAdmin::ID:
      return chatParticipantAdmin::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

chatParticipant::chatParticipant()
  : flags_()
  , user_id_()
  , inviter_id_()
  , date_()
  , rank_()
{}

const std::int32_t chatParticipant::ID;

object_ptr<ChatParticipant> chatParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatParticipant> res = make_tl_object<chatParticipant>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  res->inviter_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatParticipant");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!rank_.empty()) << 0)));
    s.store_field("user_id", user_id_);
    s.store_field("inviter_id", inviter_id_);
    s.store_field("date", date_);
    if (var0 & 1) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

chatParticipantCreator::chatParticipantCreator()
  : flags_()
  , user_id_()
  , rank_()
{}

const std::int32_t chatParticipantCreator::ID;

object_ptr<ChatParticipant> chatParticipantCreator::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatParticipantCreator> res = make_tl_object<chatParticipantCreator>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatParticipantCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatParticipantCreator");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!rank_.empty()) << 0)));
    s.store_field("user_id", user_id_);
    if (var0 & 1) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

chatParticipantAdmin::chatParticipantAdmin()
  : flags_()
  , user_id_()
  , inviter_id_()
  , date_()
  , rank_()
{}

const std::int32_t chatParticipantAdmin::ID;

object_ptr<ChatParticipant> chatParticipantAdmin::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatParticipantAdmin> res = make_tl_object<chatParticipantAdmin>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  res->inviter_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatParticipantAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatParticipantAdmin");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!rank_.empty()) << 0)));
    s.store_field("user_id", user_id_);
    s.store_field("inviter_id", inviter_id_);
    s.store_field("date", date_);
    if (var0 & 1) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

object_ptr<ChatPhoto> ChatPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatPhotoEmpty::ID:
      return chatPhotoEmpty::fetch(p);
    case chatPhoto::ID:
      return chatPhoto::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t chatPhotoEmpty::ID;

object_ptr<ChatPhoto> chatPhotoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<chatPhotoEmpty>();
}

void chatPhotoEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void chatPhotoEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void chatPhotoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotoEmpty");
    s.store_class_end();
  }
}

chatPhoto::chatPhoto()
  : flags_()
  , has_video_()
  , photo_id_()
  , stripped_thumb_()
  , dc_id_()
{}

chatPhoto::chatPhoto(int32 flags_, bool has_video_, int64 photo_id_, bytes &&stripped_thumb_, int32 dc_id_)
  : flags_(flags_)
  , has_video_(has_video_)
  , photo_id_(photo_id_)
  , stripped_thumb_(std::move(stripped_thumb_))
  , dc_id_(dc_id_)
{}

const std::int32_t chatPhoto::ID;

object_ptr<ChatPhoto> chatPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatPhoto> res = make_tl_object<chatPhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_video_ = (var0 & 1) != 0;
  res->photo_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->stripped_thumb_ = TlFetchBytes<bytes>::parse(p); }
  res->dc_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_video_ << 0) | ((!stripped_thumb_.empty()) << 1)), s);
  TlStoreBinary::store(photo_id_, s);
  if (var0 & 2) { TlStoreString::store(stripped_thumb_, s); }
  TlStoreBinary::store(dc_id_, s);
}

void chatPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_video_ << 0) | ((!stripped_thumb_.empty()) << 1)), s);
  TlStoreBinary::store(photo_id_, s);
  if (var0 & 2) { TlStoreString::store(stripped_thumb_, s); }
  TlStoreBinary::store(dc_id_, s);
}

void chatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_video_ << 0) | ((!stripped_thumb_.empty()) << 1)));
    if (var0 & 1) { s.store_field("has_video", true); }
    s.store_field("photo_id", photo_id_);
    if (var0 & 2) { s.store_bytes_field("stripped_thumb", stripped_thumb_); }
    s.store_field("dc_id", dc_id_);
    s.store_class_end();
  }
}

communityPeer::communityPeer()
  : flags_()
  , can_view_history_()
  , visible_()
  , peer_()
{}

const std::int32_t communityPeer::ID;

object_ptr<communityPeer> communityPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<communityPeer> res = make_tl_object<communityPeer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_view_history_ = (var0 & 4) != 0;
  if (var0 & 1) { res->visible_ = TlFetchBool::parse(p); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void communityPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityPeer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_view_history_ << 2)));
    if (var0 & 4) { s.store_field("can_view_history", true); }
    if (var0 & 1) { s.store_field("visible", visible_); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

connectedBot::connectedBot()
  : flags_()
  , bot_id_()
  , recipients_()
  , rights_()
  , device_()
  , date_()
  , location_()
{}

const std::int32_t connectedBot::ID;

object_ptr<connectedBot> connectedBot::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<connectedBot> res = make_tl_object<connectedBot>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bot_id_ = TlFetchLong::parse(p);
  res->recipients_ = TlFetchBoxed<TlFetchObject<businessBotRecipients>, -1198722189>::parse(p);
  res->rights_ = TlFetchBoxed<TlFetchObject<businessBotRights>, -1604170505>::parse(p);
  if (var0 & 1) { res->device_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->date_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->location_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void connectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedBot");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!device_.empty()) << 0) | ((!location_.empty()) << 2)));
    s.store_field("bot_id", bot_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get()));
    if (var0 & 1) { s.store_field("device", device_); }
    if (var0 & 2) { s.store_field("date", date_); }
    if (var0 & 4) { s.store_field("location", location_); }
    s.store_class_end();
  }
}

const std::int32_t emojiURL::ID;

object_ptr<emojiURL> emojiURL::fetch(TlBufferParser &p) {
  return make_tl_object<emojiURL>(p);
}

emojiURL::emojiURL(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void emojiURL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiURL");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inlineBotWebView::inlineBotWebView(string const &text_, string const &url_)
  : text_(text_)
  , url_(url_)
{}

const std::int32_t inlineBotWebView::ID;

object_ptr<inlineBotWebView> inlineBotWebView::fetch(TlBufferParser &p) {
  return make_tl_object<inlineBotWebView>(p);
}

inlineBotWebView::inlineBotWebView(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void inlineBotWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void inlineBotWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void inlineBotWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineBotWebView");
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inputBusinessRecipients::inputBusinessRecipients(int32 flags_, bool existing_chats_, bool new_chats_, bool contacts_, bool non_contacts_, bool exclude_selected_, array<object_ptr<InputUser>> &&users_)
  : flags_(flags_)
  , existing_chats_(existing_chats_)
  , new_chats_(new_chats_)
  , contacts_(contacts_)
  , non_contacts_(non_contacts_)
  , exclude_selected_(exclude_selected_)
  , users_(std::move(users_))
{}

const std::int32_t inputBusinessRecipients::ID;

void inputBusinessRecipients::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5) | ((!users_.empty()) << 4)), s);
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s); }
}

void inputBusinessRecipients::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5) | ((!users_.empty()) << 4)), s);
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s); }
}

void inputBusinessRecipients::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessRecipients");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5) | ((!users_.empty()) << 4)));
    if (var0 & 1) { s.store_field("existing_chats", true); }
    if (var0 & 2) { s.store_field("new_chats", true); }
    if (var0 & 4) { s.store_field("contacts", true); }
    if (var0 & 8) { s.store_field("non_contacts", true); }
    if (var0 & 32) { s.store_field("exclude_selected", true); }
    if (var0 & 16) { { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

inputChatlistDialogFilter::inputChatlistDialogFilter(int32 filter_id_)
  : filter_id_(filter_id_)
{}

const std::int32_t inputChatlistDialogFilter::ID;

void inputChatlistDialogFilter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(filter_id_, s);
}

void inputChatlistDialogFilter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(filter_id_, s);
}

void inputChatlistDialogFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatlistDialogFilter");
    s.store_field("filter_id", filter_id_);
    s.store_class_end();
  }
}

const std::int32_t inputEncryptedFileEmpty::ID;

void inputEncryptedFileEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputEncryptedFileEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputEncryptedFileEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedFileEmpty");
    s.store_class_end();
  }
}

inputEncryptedFileUploaded::inputEncryptedFileUploaded(int64 id_, int32 parts_, string const &md5_checksum_, int32 key_fingerprint_)
  : id_(id_)
  , parts_(parts_)
  , md5_checksum_(md5_checksum_)
  , key_fingerprint_(key_fingerprint_)
{}

const std::int32_t inputEncryptedFileUploaded::ID;

void inputEncryptedFileUploaded::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(md5_checksum_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void inputEncryptedFileUploaded::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(md5_checksum_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void inputEncryptedFileUploaded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedFileUploaded");
    s.store_field("id", id_);
    s.store_field("parts", parts_);
    s.store_field("md5_checksum", md5_checksum_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_class_end();
  }
}

inputEncryptedFile::inputEncryptedFile(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputEncryptedFile::ID;

void inputEncryptedFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedFile");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputEncryptedFileBigUploaded::inputEncryptedFileBigUploaded(int64 id_, int32 parts_, int32 key_fingerprint_)
  : id_(id_)
  , parts_(parts_)
  , key_fingerprint_(key_fingerprint_)
{}

const std::int32_t inputEncryptedFileBigUploaded::ID;

void inputEncryptedFileBigUploaded::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void inputEncryptedFileBigUploaded::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void inputEncryptedFileBigUploaded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedFileBigUploaded");
    s.store_field("id", id_);
    s.store_field("parts", parts_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_class_end();
  }
}

inputFolderPeer::inputFolderPeer(object_ptr<InputPeer> &&peer_, int32 folder_id_)
  : peer_(std::move(peer_))
  , folder_id_(folder_id_)
{}

const std::int32_t inputFolderPeer::ID;

void inputFolderPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(folder_id_, s);
}

void inputFolderPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(folder_id_, s);
}

void inputFolderPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFolderPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("folder_id", folder_id_);
    s.store_class_end();
  }
}

inputInvoiceMessage::inputInvoiceMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t inputInvoiceMessage::ID;

void inputInvoiceMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void inputInvoiceMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void inputInvoiceMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

inputInvoiceSlug::inputInvoiceSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputInvoiceSlug::ID;

void inputInvoiceSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputInvoiceSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputInvoiceSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

inputInvoicePremiumGiftCode::inputInvoicePremiumGiftCode(object_ptr<InputStorePaymentPurpose> &&purpose_, object_ptr<premiumGiftCodeOption> &&option_)
  : purpose_(std::move(purpose_))
  , option_(std::move(option_))
{}

const std::int32_t inputInvoicePremiumGiftCode::ID;

void inputInvoicePremiumGiftCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreBoxed<TlStoreObject, 629052971>::store(option_, s);
}

void inputInvoicePremiumGiftCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreBoxed<TlStoreObject, 629052971>::store(option_, s);
}

void inputInvoicePremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoicePremiumGiftCode");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_object_field("option", static_cast<const BaseObject *>(option_.get()));
    s.store_class_end();
  }
}

inputInvoiceStars::inputInvoiceStars(object_ptr<InputStorePaymentPurpose> &&purpose_)
  : purpose_(std::move(purpose_))
{}

const std::int32_t inputInvoiceStars::ID;

void inputInvoiceStars::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void inputInvoiceStars::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void inputInvoiceStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStars");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

inputInvoiceChatInviteSubscription::inputInvoiceChatInviteSubscription(string const &hash_)
  : hash_(hash_)
{}

const std::int32_t inputInvoiceChatInviteSubscription::ID;

void inputInvoiceChatInviteSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(hash_, s);
}

void inputInvoiceChatInviteSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(hash_, s);
}

void inputInvoiceChatInviteSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceChatInviteSubscription");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

inputInvoiceStarGift::inputInvoiceStarGift(int32 flags_, bool hide_name_, bool include_upgrade_, object_ptr<InputPeer> &&peer_, int64 gift_id_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , hide_name_(hide_name_)
  , include_upgrade_(include_upgrade_)
  , peer_(std::move(peer_))
  , gift_id_(gift_id_)
  , message_(std::move(message_))
{}

const std::int32_t inputInvoiceStarGift::ID;

void inputInvoiceStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (hide_name_ << 0) | (include_upgrade_ << 2) | ((message_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(gift_id_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoiceStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (hide_name_ << 0) | (include_upgrade_ << 2) | ((message_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(gift_id_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoiceStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGift");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (hide_name_ << 0) | (include_upgrade_ << 2) | ((message_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("hide_name", true); }
    if (var0 & 4) { s.store_field("include_upgrade", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("gift_id", gift_id_);
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

inputInvoiceStarGiftUpgrade::inputInvoiceStarGiftUpgrade(int32 flags_, bool keep_original_details_, object_ptr<InputSavedStarGift> &&stargift_)
  : flags_(flags_)
  , keep_original_details_(keep_original_details_)
  , stargift_(std::move(stargift_))
{}

const std::int32_t inputInvoiceStarGiftUpgrade::ID;

void inputInvoiceStarGiftUpgrade::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (keep_original_details_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void inputInvoiceStarGiftUpgrade::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (keep_original_details_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void inputInvoiceStarGiftUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftUpgrade");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (keep_original_details_ << 0)));
    if (var0 & 1) { s.store_field("keep_original_details", true); }
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

inputInvoiceStarGiftTransfer::inputInvoiceStarGiftTransfer(object_ptr<InputSavedStarGift> &&stargift_, object_ptr<InputPeer> &&to_id_)
  : stargift_(std::move(stargift_))
  , to_id_(std::move(to_id_))
{}

const std::int32_t inputInvoiceStarGiftTransfer::ID;

void inputInvoiceStarGiftTransfer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
}

void inputInvoiceStarGiftTransfer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
}

void inputInvoiceStarGiftTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftTransfer");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_object_field("to_id", static_cast<const BaseObject *>(to_id_.get()));
    s.store_class_end();
  }
}

inputInvoicePremiumGiftStars::inputInvoicePremiumGiftStars(int32 flags_, object_ptr<InputUser> &&user_id_, int32 months_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , user_id_(std::move(user_id_))
  , months_(months_)
  , message_(std::move(message_))
{}

const std::int32_t inputInvoicePremiumGiftStars::ID;

void inputInvoicePremiumGiftStars::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((message_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(months_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoicePremiumGiftStars::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((message_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(months_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoicePremiumGiftStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoicePremiumGiftStars");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((message_ != nullptr) << 0)));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("months", months_);
    if (var0 & 1) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

inputInvoiceBusinessBotTransferStars::inputInvoiceBusinessBotTransferStars(object_ptr<InputUser> &&bot_, int64 stars_)
  : bot_(std::move(bot_))
  , stars_(stars_)
{}

const std::int32_t inputInvoiceBusinessBotTransferStars::ID;

void inputInvoiceBusinessBotTransferStars::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(stars_, s);
}

void inputInvoiceBusinessBotTransferStars::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(stars_, s);
}

void inputInvoiceBusinessBotTransferStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceBusinessBotTransferStars");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("stars", stars_);
    s.store_class_end();
  }
}

inputInvoiceStarGiftResale::inputInvoiceStarGiftResale(int32 flags_, bool ton_, bool show_name_, string const &slug_, object_ptr<InputPeer> &&to_id_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , ton_(ton_)
  , show_name_(show_name_)
  , slug_(slug_)
  , to_id_(std::move(to_id_))
  , message_(std::move(message_))
{}

const std::int32_t inputInvoiceStarGiftResale::ID;

void inputInvoiceStarGiftResale::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0) | (show_name_ << 2) | ((message_ != nullptr) << 1)), s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoiceStarGiftResale::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0) | (show_name_ << 2) | ((message_ != nullptr) << 1)), s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoiceStarGiftResale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftResale");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (ton_ << 0) | (show_name_ << 2) | ((message_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("ton", true); }
    if (var0 & 4) { s.store_field("show_name", true); }
    s.store_field("slug", slug_);
    s.store_object_field("to_id", static_cast<const BaseObject *>(to_id_.get()));
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

inputInvoiceStarGiftPrepaidUpgrade::inputInvoiceStarGiftPrepaidUpgrade(object_ptr<InputPeer> &&peer_, string const &hash_)
  : peer_(std::move(peer_))
  , hash_(hash_)
{}

const std::int32_t inputInvoiceStarGiftPrepaidUpgrade::ID;

void inputInvoiceStarGiftPrepaidUpgrade::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(hash_, s);
}

void inputInvoiceStarGiftPrepaidUpgrade::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(hash_, s);
}

void inputInvoiceStarGiftPrepaidUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftPrepaidUpgrade");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

inputInvoicePremiumAuthCode::inputInvoicePremiumAuthCode(object_ptr<InputStorePaymentPurpose> &&purpose_)
  : purpose_(std::move(purpose_))
{}

const std::int32_t inputInvoicePremiumAuthCode::ID;

void inputInvoicePremiumAuthCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void inputInvoicePremiumAuthCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void inputInvoicePremiumAuthCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoicePremiumAuthCode");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

inputInvoiceStarGiftDropOriginalDetails::inputInvoiceStarGiftDropOriginalDetails(object_ptr<InputSavedStarGift> &&stargift_)
  : stargift_(std::move(stargift_))
{}

const std::int32_t inputInvoiceStarGiftDropOriginalDetails::ID;

void inputInvoiceStarGiftDropOriginalDetails::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void inputInvoiceStarGiftDropOriginalDetails::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void inputInvoiceStarGiftDropOriginalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftDropOriginalDetails");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

inputInvoiceStarGiftAuctionBid::inputInvoiceStarGiftAuctionBid(int32 flags_, bool hide_name_, bool update_bid_, object_ptr<InputPeer> &&peer_, int64 gift_id_, int64 bid_amount_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , hide_name_(hide_name_)
  , update_bid_(update_bid_)
  , peer_(std::move(peer_))
  , gift_id_(gift_id_)
  , bid_amount_(bid_amount_)
  , message_(std::move(message_))
{}

const std::int32_t inputInvoiceStarGiftAuctionBid::ID;

void inputInvoiceStarGiftAuctionBid::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (hide_name_ << 0) | (update_bid_ << 2) | ((peer_ != nullptr) << 3) | ((message_ != nullptr) << 1)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBinary::store(gift_id_, s);
  TlStoreBinary::store(bid_amount_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoiceStarGiftAuctionBid::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (hide_name_ << 0) | (update_bid_ << 2) | ((peer_ != nullptr) << 3) | ((message_ != nullptr) << 1)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBinary::store(gift_id_, s);
  TlStoreBinary::store(bid_amount_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoiceStarGiftAuctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftAuctionBid");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (hide_name_ << 0) | (update_bid_ << 2) | ((peer_ != nullptr) << 3) | ((message_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("hide_name", true); }
    if (var0 & 4) { s.store_field("update_bid", true); }
    if (var0 & 8) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_field("gift_id", gift_id_);
    s.store_field("bid_amount", bid_amount_);
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

object_ptr<InputMedia> InputMedia::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputMediaEmpty::ID:
      return inputMediaEmpty::fetch(p);
    case inputMediaUploadedPhoto::ID:
      return inputMediaUploadedPhoto::fetch(p);
    case inputMediaPhoto::ID:
      return inputMediaPhoto::fetch(p);
    case inputMediaGeoPoint::ID:
      return inputMediaGeoPoint::fetch(p);
    case inputMediaContact::ID:
      return inputMediaContact::fetch(p);
    case inputMediaUploadedDocument::ID:
      return inputMediaUploadedDocument::fetch(p);
    case inputMediaDocument::ID:
      return inputMediaDocument::fetch(p);
    case inputMediaVenue::ID:
      return inputMediaVenue::fetch(p);
    case inputMediaPhotoExternal::ID:
      return inputMediaPhotoExternal::fetch(p);
    case inputMediaDocumentExternal::ID:
      return inputMediaDocumentExternal::fetch(p);
    case inputMediaGame::ID:
      return inputMediaGame::fetch(p);
    case inputMediaInvoice::ID:
      return inputMediaInvoice::fetch(p);
    case inputMediaGeoLive::ID:
      return inputMediaGeoLive::fetch(p);
    case inputMediaPoll::ID:
      return inputMediaPoll::fetch(p);
    case inputMediaDice::ID:
      return inputMediaDice::fetch(p);
    case inputMediaStory::ID:
      return inputMediaStory::fetch(p);
    case inputMediaWebPage::ID:
      return inputMediaWebPage::fetch(p);
    case inputMediaPaidMedia::ID:
      return inputMediaPaidMedia::fetch(p);
    case inputMediaTodo::ID:
      return inputMediaTodo::fetch(p);
    case inputMediaStakeDice::ID:
      return inputMediaStakeDice::fetch(p);
    case inputMediaWidget::ID:
      return inputMediaWidget::fetch(p);
    case inputMediaWidgetId::ID:
      return inputMediaWidgetId::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputMediaEmpty::ID;

object_ptr<InputMedia> inputMediaEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaEmpty>();
}

void inputMediaEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMediaEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMediaEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaEmpty");
    s.store_class_end();
  }
}

inputMediaUploadedPhoto::inputMediaUploadedPhoto()
  : flags_()
  , spoiler_()
  , live_photo_()
  , file_()
  , stickers_()
  , ttl_seconds_()
  , video_()
{}

inputMediaUploadedPhoto::inputMediaUploadedPhoto(int32 flags_, bool spoiler_, bool live_photo_, object_ptr<InputFile> &&file_, array<object_ptr<InputDocument>> &&stickers_, int32 ttl_seconds_, object_ptr<InputDocument> &&video_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , live_photo_(live_photo_)
  , file_(std::move(file_))
  , stickers_(std::move(stickers_))
  , ttl_seconds_(ttl_seconds_)
  , video_(std::move(video_))
{}

const std::int32_t inputMediaUploadedPhoto::ID;

object_ptr<InputMedia> inputMediaUploadedPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaUploadedPhoto> res = make_tl_object<inputMediaUploadedPhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 4) != 0;
  res->live_photo_ = (var0 & 8) != 0;
  res->file_ = TlFetchObject<InputFile>::parse(p);
  if (var0 & 1) { res->stickers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputDocument>>, 481674261>::parse(p); }
  if (var0 & 2) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->video_ = TlFetchObject<InputDocument>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaUploadedPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 2) | (live_photo_ << 3) | ((!stickers_.empty()) << 0) | ((video_ != nullptr) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s); }
  if (var0 & 2) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void inputMediaUploadedPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 2) | (live_photo_ << 3) | ((!stickers_.empty()) << 0) | ((video_ != nullptr) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s); }
  if (var0 & 2) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void inputMediaUploadedPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaUploadedPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 2) | (live_photo_ << 3) | ((!stickers_.empty()) << 0) | ((video_ != nullptr) << 3)));
    if (var0 & 4) { s.store_field("spoiler", true); }
    if (var0 & 8) { s.store_field("live_photo", true); }
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    if (var0 & 1) { { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("ttl_seconds", ttl_seconds_); }
    if (var0 & 8) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    s.store_class_end();
  }
}

inputMediaPhoto::inputMediaPhoto()
  : flags_()
  , spoiler_()
  , live_photo_()
  , id_()
  , ttl_seconds_()
  , video_()
{}

inputMediaPhoto::inputMediaPhoto(int32 flags_, bool spoiler_, bool live_photo_, object_ptr<InputPhoto> &&id_, int32 ttl_seconds_, object_ptr<InputDocument> &&video_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , live_photo_(live_photo_)
  , id_(std::move(id_))
  , ttl_seconds_(ttl_seconds_)
  , video_(std::move(video_))
{}

const std::int32_t inputMediaPhoto::ID;

object_ptr<InputMedia> inputMediaPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaPhoto> res = make_tl_object<inputMediaPhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 2) != 0;
  res->live_photo_ = (var0 & 4) != 0;
  res->id_ = TlFetchObject<InputPhoto>::parse(p);
  if (var0 & 1) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->video_ = TlFetchObject<InputDocument>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1) | (live_photo_ << 2) | ((video_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void inputMediaPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1) | (live_photo_ << 2) | ((video_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void inputMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 1) | (live_photo_ << 2) | ((video_ != nullptr) << 2)));
    if (var0 & 2) { s.store_field("spoiler", true); }
    if (var0 & 4) { s.store_field("live_photo", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    if (var0 & 1) { s.store_field("ttl_seconds", ttl_seconds_); }
    if (var0 & 4) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    s.store_class_end();
  }
}

inputMediaGeoPoint::inputMediaGeoPoint(object_ptr<InputGeoPoint> &&geo_point_)
  : geo_point_(std::move(geo_point_))
{}

const std::int32_t inputMediaGeoPoint::ID;

object_ptr<InputMedia> inputMediaGeoPoint::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaGeoPoint>(p);
}

inputMediaGeoPoint::inputMediaGeoPoint(TlBufferParser &p)
  : geo_point_(TlFetchObject<InputGeoPoint>::parse(p))
{}

void inputMediaGeoPoint::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
}

void inputMediaGeoPoint::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
}

void inputMediaGeoPoint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaGeoPoint");
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_class_end();
  }
}

inputMediaContact::inputMediaContact(string const &phone_number_, string const &first_name_, string const &last_name_, string const &vcard_)
  : phone_number_(phone_number_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , vcard_(vcard_)
{}

const std::int32_t inputMediaContact::ID;

object_ptr<InputMedia> inputMediaContact::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaContact>(p);
}

inputMediaContact::inputMediaContact(TlBufferParser &p)
  : phone_number_(TlFetchString<string>::parse(p))
  , first_name_(TlFetchString<string>::parse(p))
  , last_name_(TlFetchString<string>::parse(p))
  , vcard_(TlFetchString<string>::parse(p))
{}

void inputMediaContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
}

void inputMediaContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
}

void inputMediaContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaContact");
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("vcard", vcard_);
    s.store_class_end();
  }
}

inputMediaUploadedDocument::inputMediaUploadedDocument()
  : flags_()
  , nosound_video_()
  , force_file_()
  , spoiler_()
  , file_()
  , thumb_()
  , mime_type_()
  , attributes_()
  , stickers_()
  , video_cover_()
  , video_timestamp_()
  , ttl_seconds_()
{}

inputMediaUploadedDocument::inputMediaUploadedDocument(int32 flags_, bool nosound_video_, bool force_file_, bool spoiler_, object_ptr<InputFile> &&file_, object_ptr<InputFile> &&thumb_, string const &mime_type_, array<object_ptr<DocumentAttribute>> &&attributes_, array<object_ptr<InputDocument>> &&stickers_, object_ptr<InputPhoto> &&video_cover_, int32 video_timestamp_, int32 ttl_seconds_)
  : flags_(flags_)
  , nosound_video_(nosound_video_)
  , force_file_(force_file_)
  , spoiler_(spoiler_)
  , file_(std::move(file_))
  , thumb_(std::move(thumb_))
  , mime_type_(mime_type_)
  , attributes_(std::move(attributes_))
  , stickers_(std::move(stickers_))
  , video_cover_(std::move(video_cover_))
  , video_timestamp_(video_timestamp_)
  , ttl_seconds_(ttl_seconds_)
{}

const std::int32_t inputMediaUploadedDocument::ID;

object_ptr<InputMedia> inputMediaUploadedDocument::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaUploadedDocument> res = make_tl_object<inputMediaUploadedDocument>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->nosound_video_ = (var0 & 8) != 0;
  res->force_file_ = (var0 & 16) != 0;
  res->spoiler_ = (var0 & 32) != 0;
  res->file_ = TlFetchObject<InputFile>::parse(p);
  if (var0 & 4) { res->thumb_ = TlFetchObject<InputFile>::parse(p); }
  res->mime_type_ = TlFetchString<string>::parse(p);
  res->attributes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<DocumentAttribute>>, 481674261>::parse(p);
  if (var0 & 1) { res->stickers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputDocument>>, 481674261>::parse(p); }
  if (var0 & 64) { res->video_cover_ = TlFetchObject<InputPhoto>::parse(p); }
  if (var0 & 128) { res->video_timestamp_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaUploadedDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (nosound_video_ << 3) | (force_file_ << 4) | (spoiler_ << 5) | ((thumb_ != nullptr) << 2) | ((!stickers_.empty()) << 0) | ((video_cover_ != nullptr) << 6)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 128) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 2) { TlStoreBinary::store(ttl_seconds_, s); }
}

void inputMediaUploadedDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (nosound_video_ << 3) | (force_file_ << 4) | (spoiler_ << 5) | ((thumb_ != nullptr) << 2) | ((!stickers_.empty()) << 0) | ((video_cover_ != nullptr) << 6)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 128) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 2) { TlStoreBinary::store(ttl_seconds_, s); }
}

void inputMediaUploadedDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaUploadedDocument");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (nosound_video_ << 3) | (force_file_ << 4) | (spoiler_ << 5) | ((thumb_ != nullptr) << 2) | ((!stickers_.empty()) << 0) | ((video_cover_ != nullptr) << 6)));
    if (var0 & 8) { s.store_field("nosound_video", true); }
    if (var0 & 16) { s.store_field("force_file", true); }
    if (var0 & 32) { s.store_field("spoiler", true); }
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    if (var0 & 4) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    s.store_field("mime_type", mime_type_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 64) { s.store_object_field("video_cover", static_cast<const BaseObject *>(video_cover_.get())); }
    if (var0 & 128) { s.store_field("video_timestamp", video_timestamp_); }
    if (var0 & 2) { s.store_field("ttl_seconds", ttl_seconds_); }
    s.store_class_end();
  }
}

inputMediaDocument::inputMediaDocument()
  : flags_()
  , spoiler_()
  , id_()
  , video_cover_()
  , video_timestamp_()
  , ttl_seconds_()
  , query_()
{}

inputMediaDocument::inputMediaDocument(int32 flags_, bool spoiler_, object_ptr<InputDocument> &&id_, object_ptr<InputPhoto> &&video_cover_, int32 video_timestamp_, int32 ttl_seconds_, string const &query_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , id_(std::move(id_))
  , video_cover_(std::move(video_cover_))
  , video_timestamp_(video_timestamp_)
  , ttl_seconds_(ttl_seconds_)
  , query_(query_)
{}

const std::int32_t inputMediaDocument::ID;

object_ptr<InputMedia> inputMediaDocument::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaDocument> res = make_tl_object<inputMediaDocument>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 4) != 0;
  res->id_ = TlFetchObject<InputDocument>::parse(p);
  if (var0 & 8) { res->video_cover_ = TlFetchObject<InputPhoto>::parse(p); }
  if (var0 & 16) { res->video_timestamp_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->query_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 2) | ((video_cover_ != nullptr) << 3) | ((!query_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 16) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 2) { TlStoreString::store(query_, s); }
}

void inputMediaDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 2) | ((video_cover_ != nullptr) << 3) | ((!query_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 16) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 2) { TlStoreString::store(query_, s); }
}

void inputMediaDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaDocument");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 2) | ((video_cover_ != nullptr) << 3) | ((!query_.empty()) << 1)));
    if (var0 & 4) { s.store_field("spoiler", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    if (var0 & 8) { s.store_object_field("video_cover", static_cast<const BaseObject *>(video_cover_.get())); }
    if (var0 & 16) { s.store_field("video_timestamp", video_timestamp_); }
    if (var0 & 1) { s.store_field("ttl_seconds", ttl_seconds_); }
    if (var0 & 2) { s.store_field("query", query_); }
    s.store_class_end();
  }
}

inputMediaVenue::inputMediaVenue(object_ptr<InputGeoPoint> &&geo_point_, string const &title_, string const &address_, string const &provider_, string const &venue_id_, string const &venue_type_)
  : geo_point_(std::move(geo_point_))
  , title_(title_)
  , address_(address_)
  , provider_(provider_)
  , venue_id_(venue_id_)
  , venue_type_(venue_type_)
{}

const std::int32_t inputMediaVenue::ID;

object_ptr<InputMedia> inputMediaVenue::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaVenue>(p);
}

inputMediaVenue::inputMediaVenue(TlBufferParser &p)
  : geo_point_(TlFetchObject<InputGeoPoint>::parse(p))
  , title_(TlFetchString<string>::parse(p))
  , address_(TlFetchString<string>::parse(p))
  , provider_(TlFetchString<string>::parse(p))
  , venue_id_(TlFetchString<string>::parse(p))
  , venue_type_(TlFetchString<string>::parse(p))
{}

void inputMediaVenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void inputMediaVenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void inputMediaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaVenue");
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("venue_type", venue_type_);
    s.store_class_end();
  }
}

inputMediaPhotoExternal::inputMediaPhotoExternal()
  : flags_()
  , spoiler_()
  , url_()
  , ttl_seconds_()
{}

inputMediaPhotoExternal::inputMediaPhotoExternal(int32 flags_, bool spoiler_, string const &url_, int32 ttl_seconds_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , url_(url_)
  , ttl_seconds_(ttl_seconds_)
{}

const std::int32_t inputMediaPhotoExternal::ID;

object_ptr<InputMedia> inputMediaPhotoExternal::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaPhotoExternal> res = make_tl_object<inputMediaPhotoExternal>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 2) != 0;
  res->url_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaPhotoExternal::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1)), s);
  TlStoreString::store(url_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
}

void inputMediaPhotoExternal::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1)), s);
  TlStoreString::store(url_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
}

void inputMediaPhotoExternal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaPhotoExternal");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 1)));
    if (var0 & 2) { s.store_field("spoiler", true); }
    s.store_field("url", url_);
    if (var0 & 1) { s.store_field("ttl_seconds", ttl_seconds_); }
    s.store_class_end();
  }
}

inputMediaDocumentExternal::inputMediaDocumentExternal()
  : flags_()
  , spoiler_()
  , url_()
  , ttl_seconds_()
  , video_cover_()
  , video_timestamp_()
{}

inputMediaDocumentExternal::inputMediaDocumentExternal(int32 flags_, bool spoiler_, string const &url_, int32 ttl_seconds_, object_ptr<InputPhoto> &&video_cover_, int32 video_timestamp_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , url_(url_)
  , ttl_seconds_(ttl_seconds_)
  , video_cover_(std::move(video_cover_))
  , video_timestamp_(video_timestamp_)
{}

const std::int32_t inputMediaDocumentExternal::ID;

object_ptr<InputMedia> inputMediaDocumentExternal::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaDocumentExternal> res = make_tl_object<inputMediaDocumentExternal>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 2) != 0;
  res->url_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->video_cover_ = TlFetchObject<InputPhoto>::parse(p); }
  if (var0 & 8) { res->video_timestamp_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaDocumentExternal::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1) | ((video_cover_ != nullptr) << 2)), s);
  TlStoreString::store(url_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 8) { TlStoreBinary::store(video_timestamp_, s); }
}

void inputMediaDocumentExternal::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1) | ((video_cover_ != nullptr) << 2)), s);
  TlStoreString::store(url_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 8) { TlStoreBinary::store(video_timestamp_, s); }
}

void inputMediaDocumentExternal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaDocumentExternal");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 1) | ((video_cover_ != nullptr) << 2)));
    if (var0 & 2) { s.store_field("spoiler", true); }
    s.store_field("url", url_);
    if (var0 & 1) { s.store_field("ttl_seconds", ttl_seconds_); }
    if (var0 & 4) { s.store_object_field("video_cover", static_cast<const BaseObject *>(video_cover_.get())); }
    if (var0 & 8) { s.store_field("video_timestamp", video_timestamp_); }
    s.store_class_end();
  }
}

inputMediaGame::inputMediaGame(object_ptr<InputGame> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t inputMediaGame::ID;

object_ptr<InputMedia> inputMediaGame::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaGame>(p);
}

inputMediaGame::inputMediaGame(TlBufferParser &p)
  : id_(TlFetchObject<InputGame>::parse(p))
{}

void inputMediaGame::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputMediaGame::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputMediaGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaGame");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

inputMediaInvoice::inputMediaInvoice()
  : flags_()
  , title_()
  , description_()
  , photo_()
  , invoice_()
  , payload_()
  , provider_()
  , provider_data_()
  , start_param_()
  , extended_media_()
{}

inputMediaInvoice::inputMediaInvoice(int32 flags_, string const &title_, string const &description_, object_ptr<inputWebDocument> &&photo_, object_ptr<invoice> &&invoice_, bytes &&payload_, string const &provider_, object_ptr<dataJSON> &&provider_data_, string const &start_param_, object_ptr<InputMedia> &&extended_media_)
  : flags_(flags_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , invoice_(std::move(invoice_))
  , payload_(std::move(payload_))
  , provider_(provider_)
  , provider_data_(std::move(provider_data_))
  , start_param_(start_param_)
  , extended_media_(std::move(extended_media_))
{}

const std::int32_t inputMediaInvoice::ID;

object_ptr<InputMedia> inputMediaInvoice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaInvoice> res = make_tl_object<inputMediaInvoice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->photo_ = TlFetchBoxed<TlFetchObject<inputWebDocument>, -1678949555>::parse(p); }
  res->invoice_ = TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p);
  res->payload_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 8) { res->provider_ = TlFetchString<string>::parse(p); }
  res->provider_data_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
  if (var0 & 2) { res->start_param_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->extended_media_ = TlFetchObject<InputMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaInvoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((photo_ != nullptr) << 0) | ((!provider_.empty()) << 3) | ((!start_param_.empty()) << 1) | ((extended_media_ != nullptr) << 2)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1678949555>::store(photo_, s); }
  TlStoreBoxed<TlStoreObject, 77522308>::store(invoice_, s);
  TlStoreString::store(payload_, s);
  if (var0 & 8) { TlStoreString::store(provider_, s); }
  TlStoreBoxed<TlStoreObject, 2104790276>::store(provider_data_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(extended_media_, s); }
}

void inputMediaInvoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((photo_ != nullptr) << 0) | ((!provider_.empty()) << 3) | ((!start_param_.empty()) << 1) | ((extended_media_ != nullptr) << 2)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1678949555>::store(photo_, s); }
  TlStoreBoxed<TlStoreObject, 77522308>::store(invoice_, s);
  TlStoreString::store(payload_, s);
  if (var0 & 8) { TlStoreString::store(provider_, s); }
  TlStoreBoxed<TlStoreObject, 2104790276>::store(provider_data_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(extended_media_, s); }
}

void inputMediaInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaInvoice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((photo_ != nullptr) << 0) | ((!provider_.empty()) << 3) | ((!start_param_.empty()) << 1) | ((extended_media_ != nullptr) << 2)));
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_bytes_field("payload", payload_);
    if (var0 & 8) { s.store_field("provider", provider_); }
    s.store_object_field("provider_data", static_cast<const BaseObject *>(provider_data_.get()));
    if (var0 & 2) { s.store_field("start_param", start_param_); }
    if (var0 & 4) { s.store_object_field("extended_media", static_cast<const BaseObject *>(extended_media_.get())); }
    s.store_class_end();
  }
}

inputMediaGeoLive::inputMediaGeoLive()
  : flags_()
  , stopped_()
  , geo_point_()
  , heading_()
  , period_()
  , proximity_notification_radius_()
{}

inputMediaGeoLive::inputMediaGeoLive(int32 flags_, bool stopped_, object_ptr<InputGeoPoint> &&geo_point_, int32 heading_, int32 period_, int32 proximity_notification_radius_)
  : flags_(flags_)
  , stopped_(stopped_)
  , geo_point_(std::move(geo_point_))
  , heading_(heading_)
  , period_(period_)
  , proximity_notification_radius_(proximity_notification_radius_)
{}

const std::int32_t inputMediaGeoLive::ID;

object_ptr<InputMedia> inputMediaGeoLive::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaGeoLive> res = make_tl_object<inputMediaGeoLive>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->stopped_ = (var0 & 1) != 0;
  res->geo_point_ = TlFetchObject<InputGeoPoint>::parse(p);
  if (var0 & 4) { res->heading_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->period_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->proximity_notification_radius_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaGeoLive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (stopped_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 4) { TlStoreBinary::store(heading_, s); }
  if (var0 & 2) { TlStoreBinary::store(period_, s); }
  if (var0 & 8) { TlStoreBinary::store(proximity_notification_radius_, s); }
}

void inputMediaGeoLive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (stopped_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 4) { TlStoreBinary::store(heading_, s); }
  if (var0 & 2) { TlStoreBinary::store(period_, s); }
  if (var0 & 8) { TlStoreBinary::store(proximity_notification_radius_, s); }
}

void inputMediaGeoLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaGeoLive");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (stopped_ << 0)));
    if (var0 & 1) { s.store_field("stopped", true); }
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    if (var0 & 4) { s.store_field("heading", heading_); }
    if (var0 & 2) { s.store_field("period", period_); }
    if (var0 & 8) { s.store_field("proximity_notification_radius", proximity_notification_radius_); }
    s.store_class_end();
  }
}

inputMediaPoll::inputMediaPoll()
  : flags_()
  , poll_()
  , correct_answers_()
  , attached_media_()
  , solution_()
  , solution_entities_()
  , solution_media_()
{}

inputMediaPoll::inputMediaPoll(int32 flags_, object_ptr<poll> &&poll_, array<int32> &&correct_answers_, object_ptr<InputMedia> &&attached_media_, string const &solution_, array<object_ptr<MessageEntity>> &&solution_entities_, object_ptr<InputMedia> &&solution_media_)
  : flags_(flags_)
  , poll_(std::move(poll_))
  , correct_answers_(std::move(correct_answers_))
  , attached_media_(std::move(attached_media_))
  , solution_(solution_)
  , solution_entities_(std::move(solution_entities_))
  , solution_media_(std::move(solution_media_))
{}

const std::int32_t inputMediaPoll::ID;

object_ptr<InputMedia> inputMediaPoll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaPoll> res = make_tl_object<inputMediaPoll>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->poll_ = TlFetchBoxed<TlFetchObject<poll>, -1771164225>::parse(p);
  if (var0 & 1) { res->correct_answers_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (var0 & 8) { res->attached_media_ = TlFetchObject<InputMedia>::parse(p); }
  if (var0 & 2) { res->solution_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->solution_entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 4) { res->solution_media_ = TlFetchObject<InputMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaPoll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!correct_answers_.empty()) << 0) | ((attached_media_ != nullptr) << 3) | ((!solution_.empty()) << 1) | ((!solution_entities_.empty()) << 1) | ((solution_media_ != nullptr) << 2)), s);
  TlStoreBoxed<TlStoreObject, -1771164225>::store(poll_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(correct_answers_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(attached_media_, s); }
  if (var0 & 2) { TlStoreString::store(solution_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(solution_entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(solution_media_, s); }
}

void inputMediaPoll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!correct_answers_.empty()) << 0) | ((attached_media_ != nullptr) << 3) | ((!solution_.empty()) << 1) | ((!solution_entities_.empty()) << 1) | ((solution_media_ != nullptr) << 2)), s);
  TlStoreBoxed<TlStoreObject, -1771164225>::store(poll_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(correct_answers_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(attached_media_, s); }
  if (var0 & 2) { TlStoreString::store(solution_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(solution_entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(solution_media_, s); }
}

void inputMediaPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaPoll");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!correct_answers_.empty()) << 0) | ((attached_media_ != nullptr) << 3) | ((!solution_.empty()) << 1) | ((!solution_entities_.empty()) << 1) | ((solution_media_ != nullptr) << 2)));
    s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get()));
    if (var0 & 1) { { s.store_vector_begin("correct_answers", correct_answers_.size()); for (const auto &_value : correct_answers_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 8) { s.store_object_field("attached_media", static_cast<const BaseObject *>(attached_media_.get())); }
    if (var0 & 2) { s.store_field("solution", solution_); }
    if (var0 & 2) { { s.store_vector_begin("solution_entities", solution_entities_.size()); for (const auto &_value : solution_entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_object_field("solution_media", static_cast<const BaseObject *>(solution_media_.get())); }
    s.store_class_end();
  }
}

inputMediaDice::inputMediaDice(string const &emoticon_)
  : emoticon_(emoticon_)
{}

const std::int32_t inputMediaDice::ID;

object_ptr<InputMedia> inputMediaDice::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaDice>(p);
}

inputMediaDice::inputMediaDice(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
{}

void inputMediaDice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputMediaDice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputMediaDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaDice");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

inputMediaStory::inputMediaStory(object_ptr<InputPeer> &&peer_, int32 id_)
  : peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t inputMediaStory::ID;

object_ptr<InputMedia> inputMediaStory::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaStory>(p);
}

inputMediaStory::inputMediaStory(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , id_(TlFetchInt::parse(p))
{}

void inputMediaStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void inputMediaStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void inputMediaStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputMediaWebPage::inputMediaWebPage()
  : flags_()
  , force_large_media_()
  , force_small_media_()
  , optional_()
  , url_()
{}

inputMediaWebPage::inputMediaWebPage(int32 flags_, bool force_large_media_, bool force_small_media_, bool optional_, string const &url_)
  : flags_(flags_)
  , force_large_media_(force_large_media_)
  , force_small_media_(force_small_media_)
  , optional_(optional_)
  , url_(url_)
{}

const std::int32_t inputMediaWebPage::ID;

object_ptr<InputMedia> inputMediaWebPage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaWebPage> res = make_tl_object<inputMediaWebPage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->force_large_media_ = (var0 & 1) != 0;
  res->force_small_media_ = (var0 & 2) != 0;
  res->optional_ = (var0 & 4) != 0;
  res->url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaWebPage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (optional_ << 2)), s);
  TlStoreString::store(url_, s);
}

void inputMediaWebPage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (optional_ << 2)), s);
  TlStoreString::store(url_, s);
}

void inputMediaWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaWebPage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (optional_ << 2)));
    if (var0 & 1) { s.store_field("force_large_media", true); }
    if (var0 & 2) { s.store_field("force_small_media", true); }
    if (var0 & 4) { s.store_field("optional", true); }
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inputMediaPaidMedia::inputMediaPaidMedia()
  : flags_()
  , stars_amount_()
  , extended_media_()
  , payload_()
{}

inputMediaPaidMedia::inputMediaPaidMedia(int32 flags_, int64 stars_amount_, array<object_ptr<InputMedia>> &&extended_media_, string const &payload_)
  : flags_(flags_)
  , stars_amount_(stars_amount_)
  , extended_media_(std::move(extended_media_))
  , payload_(payload_)
{}

const std::int32_t inputMediaPaidMedia::ID;

object_ptr<InputMedia> inputMediaPaidMedia::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaPaidMedia> res = make_tl_object<inputMediaPaidMedia>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->stars_amount_ = TlFetchLong::parse(p);
  res->extended_media_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputMedia>>, 481674261>::parse(p);
  if (var0 & 1) { res->payload_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaPaidMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!payload_.empty()) << 0)), s);
  TlStoreBinary::store(stars_amount_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(extended_media_, s);
  if (var0 & 1) { TlStoreString::store(payload_, s); }
}

void inputMediaPaidMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!payload_.empty()) << 0)), s);
  TlStoreBinary::store(stars_amount_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(extended_media_, s);
  if (var0 & 1) { TlStoreString::store(payload_, s); }
}

void inputMediaPaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaPaidMedia");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!payload_.empty()) << 0)));
    s.store_field("stars_amount", stars_amount_);
    { s.store_vector_begin("extended_media", extended_media_.size()); for (const auto &_value : extended_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("payload", payload_); }
    s.store_class_end();
  }
}

inputMediaTodo::inputMediaTodo(object_ptr<todoList> &&todo_)
  : todo_(std::move(todo_))
{}

const std::int32_t inputMediaTodo::ID;

object_ptr<InputMedia> inputMediaTodo::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaTodo>(p);
}

inputMediaTodo::inputMediaTodo(TlBufferParser &p)
  : todo_(TlFetchBoxed<TlFetchObject<todoList>, 1236871718>::parse(p))
{}

void inputMediaTodo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 1236871718>::store(todo_, s);
}

void inputMediaTodo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 1236871718>::store(todo_, s);
}

void inputMediaTodo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaTodo");
    s.store_object_field("todo", static_cast<const BaseObject *>(todo_.get()));
    s.store_class_end();
  }
}

inputMediaStakeDice::inputMediaStakeDice(string const &game_hash_, int64 ton_amount_, bytes &&client_seed_)
  : game_hash_(game_hash_)
  , ton_amount_(ton_amount_)
  , client_seed_(std::move(client_seed_))
{}

const std::int32_t inputMediaStakeDice::ID;

object_ptr<InputMedia> inputMediaStakeDice::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaStakeDice>(p);
}

inputMediaStakeDice::inputMediaStakeDice(TlBufferParser &p)
  : game_hash_(TlFetchString<string>::parse(p))
  , ton_amount_(TlFetchLong::parse(p))
  , client_seed_(TlFetchBytes<bytes>::parse(p))
{}

void inputMediaStakeDice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(game_hash_, s);
  TlStoreBinary::store(ton_amount_, s);
  TlStoreString::store(client_seed_, s);
}

void inputMediaStakeDice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(game_hash_, s);
  TlStoreBinary::store(ton_amount_, s);
  TlStoreString::store(client_seed_, s);
}

void inputMediaStakeDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaStakeDice");
    s.store_field("game_hash", game_hash_);
    s.store_field("ton_amount", ton_amount_);
    s.store_bytes_field("client_seed", client_seed_);
    s.store_class_end();
  }
}

inputMediaWidget::inputMediaWidget()
  : flags_()
  , allow_queries_()
  , shared_widget_()
  , width_()
  , height_()
  , html_()
  , public_data_()
  , chat_data_()
{}

inputMediaWidget::inputMediaWidget(int32 flags_, bool allow_queries_, bool shared_widget_, int32 width_, int32 height_, string const &html_, string const &public_data_, string const &chat_data_)
  : flags_(flags_)
  , allow_queries_(allow_queries_)
  , shared_widget_(shared_widget_)
  , width_(width_)
  , height_(height_)
  , html_(html_)
  , public_data_(public_data_)
  , chat_data_(chat_data_)
{}

const std::int32_t inputMediaWidget::ID;

object_ptr<InputMedia> inputMediaWidget::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaWidget> res = make_tl_object<inputMediaWidget>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->allow_queries_ = (var0 & 1) != 0;
  res->shared_widget_ = (var0 & 2) != 0;
  res->width_ = TlFetchInt::parse(p);
  res->height_ = TlFetchInt::parse(p);
  res->html_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->public_data_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->chat_data_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaWidget::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_queries_ << 0) | (shared_widget_ << 1) | ((!public_data_.empty()) << 2) | ((!chat_data_.empty()) << 3)), s);
  TlStoreBinary::store(width_, s);
  TlStoreBinary::store(height_, s);
  TlStoreString::store(html_, s);
  if (var0 & 4) { TlStoreString::store(public_data_, s); }
  if (var0 & 8) { TlStoreString::store(chat_data_, s); }
}

void inputMediaWidget::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_queries_ << 0) | (shared_widget_ << 1) | ((!public_data_.empty()) << 2) | ((!chat_data_.empty()) << 3)), s);
  TlStoreBinary::store(width_, s);
  TlStoreBinary::store(height_, s);
  TlStoreString::store(html_, s);
  if (var0 & 4) { TlStoreString::store(public_data_, s); }
  if (var0 & 8) { TlStoreString::store(chat_data_, s); }
}

void inputMediaWidget::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaWidget");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (allow_queries_ << 0) | (shared_widget_ << 1) | ((!public_data_.empty()) << 2) | ((!chat_data_.empty()) << 3)));
    if (var0 & 1) { s.store_field("allow_queries", true); }
    if (var0 & 2) { s.store_field("shared_widget", true); }
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("html", html_);
    if (var0 & 4) { s.store_field("public_data", public_data_); }
    if (var0 & 8) { s.store_field("chat_data", chat_data_); }
    s.store_class_end();
  }
}

inputMediaWidgetId::inputMediaWidgetId()
  : flags_()
  , widget_id_()
  , chat_data_()
{}

inputMediaWidgetId::inputMediaWidgetId(int32 flags_, int64 widget_id_, string const &chat_data_)
  : flags_(flags_)
  , widget_id_(widget_id_)
  , chat_data_(chat_data_)
{}

const std::int32_t inputMediaWidgetId::ID;

object_ptr<InputMedia> inputMediaWidgetId::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaWidgetId> res = make_tl_object<inputMediaWidgetId>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->widget_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->chat_data_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaWidgetId::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!chat_data_.empty()) << 0)), s);
  TlStoreBinary::store(widget_id_, s);
  if (var0 & 1) { TlStoreString::store(chat_data_, s); }
}

void inputMediaWidgetId::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!chat_data_.empty()) << 0)), s);
  TlStoreBinary::store(widget_id_, s);
  if (var0 & 1) { TlStoreString::store(chat_data_, s); }
}

void inputMediaWidgetId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaWidgetId");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!chat_data_.empty()) << 0)));
    s.store_field("widget_id", widget_id_);
    if (var0 & 1) { s.store_field("chat_data", chat_data_); }
    s.store_class_end();
  }
}

object_ptr<InputPhoto> InputPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputPhotoEmpty::ID:
      return inputPhotoEmpty::fetch(p);
    case inputPhoto::ID:
      return inputPhoto::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputPhotoEmpty::ID;

object_ptr<InputPhoto> inputPhotoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputPhotoEmpty>();
}

void inputPhotoEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPhotoEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPhotoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhotoEmpty");
    s.store_class_end();
  }
}

inputPhoto::inputPhoto(int64 id_, int64 access_hash_, bytes &&file_reference_)
  : id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
{}

const std::int32_t inputPhoto::ID;

object_ptr<InputPhoto> inputPhoto::fetch(TlBufferParser &p) {
  return make_tl_object<inputPhoto>(p);
}

inputPhoto::inputPhoto(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , file_reference_(TlFetchBytes<bytes>::parse(p))
{}

void inputPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
}

void inputPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
}

void inputPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhoto");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_class_end();
  }
}

inputWebFileLocation::inputWebFileLocation(string const &url_, int64 access_hash_)
  : url_(url_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputWebFileLocation::ID;

void inputWebFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputWebFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputWebFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWebFileLocation");
    s.store_field("url", url_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputWebFileGeoPointLocation::inputWebFileGeoPointLocation(object_ptr<InputGeoPoint> &&geo_point_, int64 access_hash_, int32 w_, int32 h_, int32 zoom_, int32 scale_)
  : geo_point_(std::move(geo_point_))
  , access_hash_(access_hash_)
  , w_(w_)
  , h_(h_)
  , zoom_(zoom_)
  , scale_(scale_)
{}

const std::int32_t inputWebFileGeoPointLocation::ID;

void inputWebFileGeoPointLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(zoom_, s);
  TlStoreBinary::store(scale_, s);
}

void inputWebFileGeoPointLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(zoom_, s);
  TlStoreBinary::store(scale_, s);
}

void inputWebFileGeoPointLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWebFileGeoPointLocation");
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_field("access_hash", access_hash_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_field("zoom", zoom_);
    s.store_field("scale", scale_);
    s.store_class_end();
  }
}

inputWebFileAudioAlbumThumbLocation::inputWebFileAudioAlbumThumbLocation(int32 flags_, bool small_, object_ptr<InputDocument> &&document_, string const &title_, string const &performer_)
  : flags_(flags_)
  , small_(small_)
  , document_(std::move(document_))
  , title_(title_)
  , performer_(performer_)
{}

const std::int32_t inputWebFileAudioAlbumThumbLocation::ID;

void inputWebFileAudioAlbumThumbLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (small_ << 2) | ((document_ != nullptr) << 0) | ((!title_.empty()) << 1) | ((!performer_.empty()) << 1)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(performer_, s); }
}

void inputWebFileAudioAlbumThumbLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (small_ << 2) | ((document_ != nullptr) << 0) | ((!title_.empty()) << 1) | ((!performer_.empty()) << 1)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(performer_, s); }
}

void inputWebFileAudioAlbumThumbLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWebFileAudioAlbumThumbLocation");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (small_ << 2) | ((document_ != nullptr) << 0) | ((!title_.empty()) << 1) | ((!performer_.empty()) << 1)));
    if (var0 & 4) { s.store_field("small", true); }
    if (var0 & 1) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("performer", performer_); }
    s.store_class_end();
  }
}

object_ptr<JSONValue> JSONValue::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case jsonNull::ID:
      return jsonNull::fetch(p);
    case jsonBool::ID:
      return jsonBool::fetch(p);
    case jsonNumber::ID:
      return jsonNumber::fetch(p);
    case jsonString::ID:
      return jsonString::fetch(p);
    case jsonArray::ID:
      return jsonArray::fetch(p);
    case jsonObject::ID:
      return jsonObject::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t jsonNull::ID;

object_ptr<JSONValue> jsonNull::fetch(TlBufferParser &p) {
  return make_tl_object<jsonNull>();
}

void jsonNull::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void jsonNull::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void jsonNull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonNull");
    s.store_class_end();
  }
}

jsonBool::jsonBool(bool value_)
  : value_(value_)
{}

const std::int32_t jsonBool::ID;

object_ptr<JSONValue> jsonBool::fetch(TlBufferParser &p) {
  return make_tl_object<jsonBool>(p);
}

jsonBool::jsonBool(TlBufferParser &p)
  : value_(TlFetchBool::parse(p))
{}

void jsonBool::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBool::store(value_, s);
}

void jsonBool::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBool::store(value_, s);
}

void jsonBool::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonBool");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonNumber::jsonNumber(double value_)
  : value_(value_)
{}

const std::int32_t jsonNumber::ID;

object_ptr<JSONValue> jsonNumber::fetch(TlBufferParser &p) {
  return make_tl_object<jsonNumber>(p);
}

jsonNumber::jsonNumber(TlBufferParser &p)
  : value_(TlFetchDouble::parse(p))
{}

void jsonNumber::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(value_, s);
}

void jsonNumber::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(value_, s);
}

void jsonNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonNumber");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonString::jsonString(string const &value_)
  : value_(value_)
{}

const std::int32_t jsonString::ID;

object_ptr<JSONValue> jsonString::fetch(TlBufferParser &p) {
  return make_tl_object<jsonString>(p);
}

jsonString::jsonString(TlBufferParser &p)
  : value_(TlFetchString<string>::parse(p))
{}

void jsonString::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(value_, s);
}

void jsonString::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(value_, s);
}

void jsonString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonString");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonArray::jsonArray(array<object_ptr<JSONValue>> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t jsonArray::ID;

object_ptr<JSONValue> jsonArray::fetch(TlBufferParser &p) {
  return make_tl_object<jsonArray>(p);
}

jsonArray::jsonArray(TlBufferParser &p)
  : value_(TlFetchBoxed<TlFetchVector<TlFetchObject<JSONValue>>, 481674261>::parse(p))
{}

void jsonArray::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(value_, s);
}

void jsonArray::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(value_, s);
}

void jsonArray::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonArray");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

jsonObject::jsonObject(array<object_ptr<jsonObjectValue>> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t jsonObject::ID;

object_ptr<JSONValue> jsonObject::fetch(TlBufferParser &p) {
  return make_tl_object<jsonObject>(p);
}

jsonObject::jsonObject(TlBufferParser &p)
  : value_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<jsonObjectValue>, -1059185703>>, 481674261>::parse(p))
{}

void jsonObject::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1059185703>>, 481674261>::store(value_, s);
}

void jsonObject::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1059185703>>, 481674261>::store(value_, s);
}

void jsonObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonObject");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t langPackDifference::ID;

object_ptr<langPackDifference> langPackDifference::fetch(TlBufferParser &p) {
  return make_tl_object<langPackDifference>(p);
}

langPackDifference::langPackDifference(TlBufferParser &p)
  : lang_code_(TlFetchString<string>::parse(p))
  , from_version_(TlFetchInt::parse(p))
  , version_(TlFetchInt::parse(p))
  , strings_(TlFetchBoxed<TlFetchVector<TlFetchObject<LangPackString>>, 481674261>::parse(p))
{}

void langPackDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langPackDifference");
    s.store_field("lang_code", lang_code_);
    s.store_field("from_version", from_version_);
    s.store_field("version", version_);
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<Message> Message::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messageEmpty::ID:
      return messageEmpty::fetch(p);
    case message::ID:
      return message::fetch(p);
    case messageService::ID:
      return messageService::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messageEmpty::messageEmpty()
  : flags_()
  , id_()
  , peer_id_()
{}

const std::int32_t messageEmpty::ID;

object_ptr<Message> messageEmpty::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageEmpty> res = make_tl_object<messageEmpty>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->peer_id_ = TlFetchObject<Peer>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEmpty");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((peer_id_ != nullptr) << 0)));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get())); }
    s.store_class_end();
  }
}

message::message()
  : flags_()
  , out_()
  , mentioned_()
  , media_unread_()
  , silent_()
  , post_()
  , from_scheduled_()
  , legacy_()
  , edit_hide_()
  , pinned_()
  , noforwards_()
  , invert_media_()
  , flags2_()
  , offline_()
  , video_processing_pending_()
  , paid_suggested_post_stars_()
  , paid_suggested_post_ton_()
  , id_()
  , from_id_()
  , from_boosts_applied_()
  , from_rank_()
  , peer_id_()
  , saved_peer_id_()
  , fwd_from_()
  , via_bot_id_()
  , via_business_bot_id_()
  , guestchat_via_from_()
  , reply_to_()
  , date_()
  , message_()
  , media_()
  , reply_markup_()
  , entities_()
  , views_()
  , forwards_()
  , replies_()
  , edit_date_()
  , post_author_()
  , grouped_id_()
  , reactions_()
  , restriction_reason_()
  , ttl_period_()
  , quick_reply_shortcut_id_()
  , effect_()
  , factcheck_()
  , report_delivery_until_date_()
  , paid_message_stars_()
  , suggested_post_()
  , schedule_repeat_period_()
  , summary_from_language_()
  , rich_message_()
{}

message::message(int32 flags_, bool out_, bool mentioned_, bool media_unread_, bool silent_, bool post_, bool from_scheduled_, bool legacy_, bool edit_hide_, bool pinned_, bool noforwards_, bool invert_media_, int32 flags2_, bool offline_, bool video_processing_pending_, bool paid_suggested_post_stars_, bool paid_suggested_post_ton_, int32 id_, object_ptr<Peer> &&from_id_, int32 from_boosts_applied_, string const &from_rank_, object_ptr<Peer> &&peer_id_, object_ptr<Peer> &&saved_peer_id_, object_ptr<messageFwdHeader> &&fwd_from_, int64 via_bot_id_, int64 via_business_bot_id_, object_ptr<Peer> &&guestchat_via_from_, object_ptr<MessageReplyHeader> &&reply_to_, int32 date_, string const &message_, object_ptr<MessageMedia> &&media_, object_ptr<ReplyMarkup> &&reply_markup_, array<object_ptr<MessageEntity>> &&entities_, int32 views_, int32 forwards_, object_ptr<messageReplies> &&replies_, int32 edit_date_, string const &post_author_, int64 grouped_id_, object_ptr<messageReactions> &&reactions_, array<object_ptr<restrictionReason>> &&restriction_reason_, int32 ttl_period_, int32 quick_reply_shortcut_id_, int64 effect_, object_ptr<factCheck> &&factcheck_, int32 report_delivery_until_date_, int64 paid_message_stars_, object_ptr<suggestedPost> &&suggested_post_, int32 schedule_repeat_period_, string const &summary_from_language_, object_ptr<richMessage> &&rich_message_)
  : flags_(flags_)
  , out_(out_)
  , mentioned_(mentioned_)
  , media_unread_(media_unread_)
  , silent_(silent_)
  , post_(post_)
  , from_scheduled_(from_scheduled_)
  , legacy_(legacy_)
  , edit_hide_(edit_hide_)
  , pinned_(pinned_)
  , noforwards_(noforwards_)
  , invert_media_(invert_media_)
  , flags2_(flags2_)
  , offline_(offline_)
  , video_processing_pending_(video_processing_pending_)
  , paid_suggested_post_stars_(paid_suggested_post_stars_)
  , paid_suggested_post_ton_(paid_suggested_post_ton_)
  , id_(id_)
  , from_id_(std::move(from_id_))
  , from_boosts_applied_(from_boosts_applied_)
  , from_rank_(from_rank_)
  , peer_id_(std::move(peer_id_))
  , saved_peer_id_(std::move(saved_peer_id_))
  , fwd_from_(std::move(fwd_from_))
  , via_bot_id_(via_bot_id_)
  , via_business_bot_id_(via_business_bot_id_)
  , guestchat_via_from_(std::move(guestchat_via_from_))
  , reply_to_(std::move(reply_to_))
  , date_(date_)
  , message_(message_)
  , media_(std::move(media_))
  , reply_markup_(std::move(reply_markup_))
  , entities_(std::move(entities_))
  , views_(views_)
  , forwards_(forwards_)
  , replies_(std::move(replies_))
  , edit_date_(edit_date_)
  , post_author_(post_author_)
  , grouped_id_(grouped_id_)
  , reactions_(std::move(reactions_))
  , restriction_reason_(std::move(restriction_reason_))
  , ttl_period_(ttl_period_)
  , quick_reply_shortcut_id_(quick_reply_shortcut_id_)
  , effect_(effect_)
  , factcheck_(std::move(factcheck_))
  , report_delivery_until_date_(report_delivery_until_date_)
  , paid_message_stars_(paid_message_stars_)
  , suggested_post_(std::move(suggested_post_))
  , schedule_repeat_period_(schedule_repeat_period_)
  , summary_from_language_(summary_from_language_)
  , rich_message_(std::move(rich_message_))
{}

const std::int32_t message::ID;

object_ptr<Message> message::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<message> res = make_tl_object<message>();
  int32 var0;
  int32 var1;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->out_ = (var0 & 2) != 0;
  res->mentioned_ = (var0 & 16) != 0;
  res->media_unread_ = (var0 & 32) != 0;
  res->silent_ = (var0 & 8192) != 0;
  res->post_ = (var0 & 16384) != 0;
  res->from_scheduled_ = (var0 & 262144) != 0;
  res->legacy_ = (var0 & 524288) != 0;
  res->edit_hide_ = (var0 & 2097152) != 0;
  res->pinned_ = (var0 & 16777216) != 0;
  res->noforwards_ = (var0 & 67108864) != 0;
  res->invert_media_ = (var0 & 134217728) != 0;
  if ((var1 = res->flags2_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->offline_ = (var1 & 2) != 0;
  res->video_processing_pending_ = (var1 & 16) != 0;
  res->paid_suggested_post_stars_ = (var1 & 256) != 0;
  res->paid_suggested_post_ton_ = (var1 & 512) != 0;
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 256) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 536870912) { res->from_boosts_applied_ = TlFetchInt::parse(p); }
  if (var1 & 4096) { res->from_rank_ = TlFetchString<string>::parse(p); }
  res->peer_id_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 268435456) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 4) { res->fwd_from_ = TlFetchBoxed<TlFetchObject<messageFwdHeader>, 1313731771>::parse(p); }
  if (var0 & 2048) { res->via_bot_id_ = TlFetchLong::parse(p); }
  if (var1 & 1) { res->via_business_bot_id_ = TlFetchLong::parse(p); }
  if (var1 & 524288) { res->guestchat_via_from_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 8) { res->reply_to_ = TlFetchObject<MessageReplyHeader>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 512) { res->media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (var0 & 64) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (var0 & 128) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 1024) { res->views_ = TlFetchInt::parse(p); }
  if (var0 & 1024) { res->forwards_ = TlFetchInt::parse(p); }
  if (var0 & 8388608) { res->replies_ = TlFetchBoxed<TlFetchObject<messageReplies>, -2083123262>::parse(p); }
  if (var0 & 32768) { res->edit_date_ = TlFetchInt::parse(p); }
  if (var0 & 65536) { res->post_author_ = TlFetchString<string>::parse(p); }
  if (var0 & 131072) { res->grouped_id_ = TlFetchLong::parse(p); }
  if (var0 & 1048576) { res->reactions_ = TlFetchBoxed<TlFetchObject<messageReactions>, 171155211>::parse(p); }
  if (var0 & 4194304) { res->restriction_reason_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<restrictionReason>, -797791052>>, 481674261>::parse(p); }
  if (var0 & 33554432) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (var0 & 1073741824) { res->quick_reply_shortcut_id_ = TlFetchInt::parse(p); }
  if (var1 & 4) { res->effect_ = TlFetchLong::parse(p); }
  if (var1 & 8) { res->factcheck_ = TlFetchBoxed<TlFetchObject<factCheck>, -1197736753>::parse(p); }
  if (var1 & 32) { res->report_delivery_until_date_ = TlFetchInt::parse(p); }
  if (var1 & 64) { res->paid_message_stars_ = TlFetchLong::parse(p); }
  if (var1 & 128) { res->suggested_post_ = TlFetchBoxed<TlFetchObject<suggestedPost>, 244201445>::parse(p); }
  if (var1 & 1024) { res->schedule_repeat_period_ = TlFetchInt::parse(p); }
  if (var1 & 2048) { res->summary_from_language_ = TlFetchString<string>::parse(p); }
  if (var1 & 8192) { res->rich_message_ = TlFetchBoxed<TlFetchObject<richMessage>, -1158439541>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void message::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "message");
  int32 var0;
  int32 var1;
    s.store_field("flags", (var0 = flags_ | (out_ << 1) | (mentioned_ << 4) | (media_unread_ << 5) | (silent_ << 13) | (post_ << 14) | (from_scheduled_ << 18) | (legacy_ << 19) | (edit_hide_ << 21) | (pinned_ << 24) | (noforwards_ << 26) | (invert_media_ << 27) | ((from_id_ != nullptr) << 8) | ((saved_peer_id_ != nullptr) << 28) | ((fwd_from_ != nullptr) << 2) | ((reply_to_ != nullptr) << 3) | ((media_ != nullptr) << 9) | ((reply_markup_ != nullptr) << 6) | ((!entities_.empty()) << 7) | ((replies_ != nullptr) << 23) | ((!post_author_.empty()) << 16) | ((reactions_ != nullptr) << 20) | ((!restriction_reason_.empty()) << 22)));
    if (var0 & 2) { s.store_field("out", true); }
    if (var0 & 16) { s.store_field("mentioned", true); }
    if (var0 & 32) { s.store_field("media_unread", true); }
    if (var0 & 8192) { s.store_field("silent", true); }
    if (var0 & 16384) { s.store_field("post", true); }
    if (var0 & 262144) { s.store_field("from_scheduled", true); }
    if (var0 & 524288) { s.store_field("legacy", true); }
    if (var0 & 2097152) { s.store_field("edit_hide", true); }
    if (var0 & 16777216) { s.store_field("pinned", true); }
    if (var0 & 67108864) { s.store_field("noforwards", true); }
    if (var0 & 134217728) { s.store_field("invert_media", true); }
    s.store_field("flags2", (var1 = flags2_ | (offline_ << 1) | (video_processing_pending_ << 4) | (paid_suggested_post_stars_ << 8) | (paid_suggested_post_ton_ << 9) | ((!from_rank_.empty()) << 12) | ((guestchat_via_from_ != nullptr) << 19) | ((factcheck_ != nullptr) << 3) | ((suggested_post_ != nullptr) << 7) | ((!summary_from_language_.empty()) << 11) | ((rich_message_ != nullptr) << 13)));
    if (var1 & 2) { s.store_field("offline", true); }
    if (var1 & 16) { s.store_field("video_processing_pending", true); }
    if (var1 & 256) { s.store_field("paid_suggested_post_stars", true); }
    if (var1 & 512) { s.store_field("paid_suggested_post_ton", true); }
    s.store_field("id", id_);
    if (var0 & 256) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 536870912) { s.store_field("from_boosts_applied", from_boosts_applied_); }
    if (var1 & 4096) { s.store_field("from_rank", from_rank_); }
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    if (var0 & 268435456) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    if (var0 & 4) { s.store_object_field("fwd_from", static_cast<const BaseObject *>(fwd_from_.get())); }
    if (var0 & 2048) { s.store_field("via_bot_id", via_bot_id_); }
    if (var1 & 1) { s.store_field("via_business_bot_id", via_business_bot_id_); }
    if (var1 & 524288) { s.store_object_field("guestchat_via_from", static_cast<const BaseObject *>(guestchat_via_from_.get())); }
    if (var0 & 8) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_field("date", date_);
    s.store_field("message", message_);
    if (var0 & 512) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 64) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 128) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1024) { s.store_field("views", views_); }
    if (var0 & 1024) { s.store_field("forwards", forwards_); }
    if (var0 & 8388608) { s.store_object_field("replies", static_cast<const BaseObject *>(replies_.get())); }
    if (var0 & 32768) { s.store_field("edit_date", edit_date_); }
    if (var0 & 65536) { s.store_field("post_author", post_author_); }
    if (var0 & 131072) { s.store_field("grouped_id", grouped_id_); }
    if (var0 & 1048576) { s.store_object_field("reactions", static_cast<const BaseObject *>(reactions_.get())); }
    if (var0 & 4194304) { { s.store_vector_begin("restriction_reason", restriction_reason_.size()); for (const auto &_value : restriction_reason_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 33554432) { s.store_field("ttl_period", ttl_period_); }
    if (var0 & 1073741824) { s.store_field("quick_reply_shortcut_id", quick_reply_shortcut_id_); }
    if (var1 & 4) { s.store_field("effect", effect_); }
    if (var1 & 8) { s.store_object_field("factcheck", static_cast<const BaseObject *>(factcheck_.get())); }
    if (var1 & 32) { s.store_field("report_delivery_until_date", report_delivery_until_date_); }
    if (var1 & 64) { s.store_field("paid_message_stars", paid_message_stars_); }
    if (var1 & 128) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    if (var1 & 1024) { s.store_field("schedule_repeat_period", schedule_repeat_period_); }
    if (var1 & 2048) { s.store_field("summary_from_language", summary_from_language_); }
    if (var1 & 8192) { s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get())); }
    s.store_class_end();
  }
}

messageService::messageService()
  : flags_()
  , out_()
  , mentioned_()
  , media_unread_()
  , reactions_are_possible_()
  , silent_()
  , post_()
  , legacy_()
  , id_()
  , from_id_()
  , peer_id_()
  , saved_peer_id_()
  , reply_to_()
  , date_()
  , action_()
  , reactions_()
  , ttl_period_()
{}

const std::int32_t messageService::ID;

object_ptr<Message> messageService::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageService> res = make_tl_object<messageService>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->out_ = (var0 & 2) != 0;
  res->mentioned_ = (var0 & 16) != 0;
  res->media_unread_ = (var0 & 32) != 0;
  res->reactions_are_possible_ = (var0 & 512) != 0;
  res->silent_ = (var0 & 8192) != 0;
  res->post_ = (var0 & 16384) != 0;
  res->legacy_ = (var0 & 524288) != 0;
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 256) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  res->peer_id_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 268435456) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 8) { res->reply_to_ = TlFetchObject<MessageReplyHeader>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->action_ = TlFetchObject<MessageAction>::parse(p);
  if (var0 & 1048576) { res->reactions_ = TlFetchBoxed<TlFetchObject<messageReactions>, 171155211>::parse(p); }
  if (var0 & 33554432) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageService");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (out_ << 1) | (mentioned_ << 4) | (media_unread_ << 5) | (reactions_are_possible_ << 9) | (silent_ << 13) | (post_ << 14) | (legacy_ << 19) | ((from_id_ != nullptr) << 8) | ((saved_peer_id_ != nullptr) << 28) | ((reply_to_ != nullptr) << 3) | ((reactions_ != nullptr) << 20)));
    if (var0 & 2) { s.store_field("out", true); }
    if (var0 & 16) { s.store_field("mentioned", true); }
    if (var0 & 32) { s.store_field("media_unread", true); }
    if (var0 & 512) { s.store_field("reactions_are_possible", true); }
    if (var0 & 8192) { s.store_field("silent", true); }
    if (var0 & 16384) { s.store_field("post", true); }
    if (var0 & 524288) { s.store_field("legacy", true); }
    s.store_field("id", id_);
    if (var0 & 256) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    if (var0 & 268435456) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    if (var0 & 8) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_field("date", date_);
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    if (var0 & 1048576) { s.store_object_field("reactions", static_cast<const BaseObject *>(reactions_.get())); }
    if (var0 & 33554432) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

messageViews::messageViews()
  : flags_()
  , views_()
  , forwards_()
  , replies_()
{}

const std::int32_t messageViews::ID;

object_ptr<messageViews> messageViews::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageViews> res = make_tl_object<messageViews>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->views_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->forwards_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->replies_ = TlFetchBoxed<TlFetchObject<messageReplies>, -2083123262>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messageViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageViews");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((replies_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("views", views_); }
    if (var0 & 2) { s.store_field("forwards", forwards_); }
    if (var0 & 4) { s.store_object_field("replies", static_cast<const BaseObject *>(replies_.get())); }
    s.store_class_end();
  }
}

const std::int32_t outboxReadDate::ID;

object_ptr<outboxReadDate> outboxReadDate::fetch(TlBufferParser &p) {
  return make_tl_object<outboxReadDate>(p);
}

outboxReadDate::outboxReadDate(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
{}

void outboxReadDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "outboxReadDate");
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<PhotoSize> PhotoSize::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case photoSizeEmpty::ID:
      return photoSizeEmpty::fetch(p);
    case photoSize::ID:
      return photoSize::fetch(p);
    case photoCachedSize::ID:
      return photoCachedSize::fetch(p);
    case photoStrippedSize::ID:
      return photoStrippedSize::fetch(p);
    case photoSizeProgressive::ID:
      return photoSizeProgressive::fetch(p);
    case photoPathSize::ID:
      return photoPathSize::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

photoSizeEmpty::photoSizeEmpty(string const &type_)
  : type_(type_)
{}

const std::int32_t photoSizeEmpty::ID;

object_ptr<PhotoSize> photoSizeEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<photoSizeEmpty>(p);
}

photoSizeEmpty::photoSizeEmpty(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
{}

void photoSizeEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
}

void photoSizeEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
}

void photoSizeEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoSizeEmpty");
    s.store_field("type", type_);
    s.store_class_end();
  }
}

photoSize::photoSize(string const &type_, int32 w_, int32 h_, int32 size_)
  : type_(type_)
  , w_(w_)
  , h_(h_)
  , size_(size_)
{}

const std::int32_t photoSize::ID;

object_ptr<PhotoSize> photoSize::fetch(TlBufferParser &p) {
  return make_tl_object<photoSize>(p);
}

photoSize::photoSize(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
  , w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
  , size_(TlFetchInt::parse(p))
{}

void photoSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(size_, s);
}

void photoSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(size_, s);
}

void photoSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoSize");
    s.store_field("type", type_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_field("size", size_);
    s.store_class_end();
  }
}

photoCachedSize::photoCachedSize(string const &type_, int32 w_, int32 h_, bytes &&bytes_)
  : type_(type_)
  , w_(w_)
  , h_(h_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t photoCachedSize::ID;

object_ptr<PhotoSize> photoCachedSize::fetch(TlBufferParser &p) {
  return make_tl_object<photoCachedSize>(p);
}

photoCachedSize::photoCachedSize(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
  , w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void photoCachedSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreString::store(bytes_, s);
}

void photoCachedSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreString::store(bytes_, s);
}

void photoCachedSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoCachedSize");
    s.store_field("type", type_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

photoStrippedSize::photoStrippedSize(string const &type_, bytes &&bytes_)
  : type_(type_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t photoStrippedSize::ID;

object_ptr<PhotoSize> photoStrippedSize::fetch(TlBufferParser &p) {
  return make_tl_object<photoStrippedSize>(p);
}

photoStrippedSize::photoStrippedSize(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void photoStrippedSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreString::store(bytes_, s);
}

void photoStrippedSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreString::store(bytes_, s);
}

void photoStrippedSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoStrippedSize");
    s.store_field("type", type_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

photoSizeProgressive::photoSizeProgressive(string const &type_, int32 w_, int32 h_, array<int32> &&sizes_)
  : type_(type_)
  , w_(w_)
  , h_(h_)
  , sizes_(std::move(sizes_))
{}

const std::int32_t photoSizeProgressive::ID;

object_ptr<PhotoSize> photoSizeProgressive::fetch(TlBufferParser &p) {
  return make_tl_object<photoSizeProgressive>(p);
}

photoSizeProgressive::photoSizeProgressive(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
  , w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
  , sizes_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void photoSizeProgressive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sizes_, s);
}

void photoSizeProgressive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sizes_, s);
}

void photoSizeProgressive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoSizeProgressive");
    s.store_field("type", type_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    { s.store_vector_begin("sizes", sizes_.size()); for (const auto &_value : sizes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

photoPathSize::photoPathSize(string const &type_, bytes &&bytes_)
  : type_(type_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t photoPathSize::ID;

object_ptr<PhotoSize> photoPathSize::fetch(TlBufferParser &p) {
  return make_tl_object<photoPathSize>(p);
}

photoPathSize::photoPathSize(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void photoPathSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreString::store(bytes_, s);
}

void photoPathSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreString::store(bytes_, s);
}

void photoPathSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoPathSize");
    s.store_field("type", type_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

pollAnswerVoters::pollAnswerVoters()
  : flags_()
  , chosen_()
  , correct_()
  , option_()
  , voters_()
  , recent_voters_()
{}

pollAnswerVoters::pollAnswerVoters(int32 flags_, bool chosen_, bool correct_, bytes &&option_, int32 voters_, array<object_ptr<Peer>> &&recent_voters_)
  : flags_(flags_)
  , chosen_(chosen_)
  , correct_(correct_)
  , option_(std::move(option_))
  , voters_(voters_)
  , recent_voters_(std::move(recent_voters_))
{}

const std::int32_t pollAnswerVoters::ID;

object_ptr<pollAnswerVoters> pollAnswerVoters::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pollAnswerVoters> res = make_tl_object<pollAnswerVoters>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->chosen_ = (var0 & 1) != 0;
  res->correct_ = (var0 & 2) != 0;
  res->option_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 4) { res->voters_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->recent_voters_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void pollAnswerVoters::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (chosen_ << 0) | (correct_ << 1) | ((!recent_voters_.empty()) << 2)), s);
  TlStoreString::store(option_, s);
  if (var0 & 4) { TlStoreBinary::store(voters_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(recent_voters_, s); }
}

void pollAnswerVoters::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (chosen_ << 0) | (correct_ << 1) | ((!recent_voters_.empty()) << 2)), s);
  TlStoreString::store(option_, s);
  if (var0 & 4) { TlStoreBinary::store(voters_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(recent_voters_, s); }
}

void pollAnswerVoters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollAnswerVoters");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (chosen_ << 0) | (correct_ << 1) | ((!recent_voters_.empty()) << 2)));
    if (var0 & 1) { s.store_field("chosen", true); }
    if (var0 & 2) { s.store_field("correct", true); }
    s.store_bytes_field("option", option_);
    if (var0 & 4) { s.store_field("voters", voters_); }
    if (var0 & 4) { { s.store_vector_begin("recent_voters", recent_voters_.size()); for (const auto &_value : recent_voters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

object_ptr<RecentMeUrl> RecentMeUrl::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case recentMeUrlUnknown::ID:
      return recentMeUrlUnknown::fetch(p);
    case recentMeUrlUser::ID:
      return recentMeUrlUser::fetch(p);
    case recentMeUrlChat::ID:
      return recentMeUrlChat::fetch(p);
    case recentMeUrlChatInvite::ID:
      return recentMeUrlChatInvite::fetch(p);
    case recentMeUrlStickerSet::ID:
      return recentMeUrlStickerSet::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t recentMeUrlUnknown::ID;

object_ptr<RecentMeUrl> recentMeUrlUnknown::fetch(TlBufferParser &p) {
  return make_tl_object<recentMeUrlUnknown>(p);
}

recentMeUrlUnknown::recentMeUrlUnknown(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void recentMeUrlUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentMeUrlUnknown");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

const std::int32_t recentMeUrlUser::ID;

object_ptr<RecentMeUrl> recentMeUrlUser::fetch(TlBufferParser &p) {
  return make_tl_object<recentMeUrlUser>(p);
}

recentMeUrlUser::recentMeUrlUser(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , user_id_(TlFetchLong::parse(p))
{}

void recentMeUrlUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentMeUrlUser");
    s.store_field("url", url_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

const std::int32_t recentMeUrlChat::ID;

object_ptr<RecentMeUrl> recentMeUrlChat::fetch(TlBufferParser &p) {
  return make_tl_object<recentMeUrlChat>(p);
}

recentMeUrlChat::recentMeUrlChat(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , chat_id_(TlFetchLong::parse(p))
{}

void recentMeUrlChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentMeUrlChat");
    s.store_field("url", url_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

const std::int32_t recentMeUrlChatInvite::ID;

object_ptr<RecentMeUrl> recentMeUrlChatInvite::fetch(TlBufferParser &p) {
  return make_tl_object<recentMeUrlChatInvite>(p);
}

recentMeUrlChatInvite::recentMeUrlChatInvite(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , chat_invite_(TlFetchObject<ChatInvite>::parse(p))
{}

void recentMeUrlChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentMeUrlChatInvite");
    s.store_field("url", url_);
    s.store_object_field("chat_invite", static_cast<const BaseObject *>(chat_invite_.get()));
    s.store_class_end();
  }
}

const std::int32_t recentMeUrlStickerSet::ID;

object_ptr<RecentMeUrl> recentMeUrlStickerSet::fetch(TlBufferParser &p) {
  return make_tl_object<recentMeUrlStickerSet>(p);
}

recentMeUrlStickerSet::recentMeUrlStickerSet(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , set_(TlFetchObject<StickerSetCovered>::parse(p))
{}

void recentMeUrlStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentMeUrlStickerSet");
    s.store_field("url", url_);
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    s.store_class_end();
  }
}

object_ptr<ReplyMarkup> ReplyMarkup::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case replyKeyboardHide::ID:
      return replyKeyboardHide::fetch(p);
    case replyKeyboardForceReply::ID:
      return replyKeyboardForceReply::fetch(p);
    case replyKeyboardMarkup::ID:
      return replyKeyboardMarkup::fetch(p);
    case replyInlineMarkup::ID:
      return replyInlineMarkup::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

replyKeyboardHide::replyKeyboardHide()
  : flags_()
  , selective_()
{}

replyKeyboardHide::replyKeyboardHide(int32 flags_, bool selective_)
  : flags_(flags_)
  , selective_(selective_)
{}

const std::int32_t replyKeyboardHide::ID;

object_ptr<ReplyMarkup> replyKeyboardHide::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<replyKeyboardHide> res = make_tl_object<replyKeyboardHide>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->selective_ = (var0 & 4) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void replyKeyboardHide::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (selective_ << 2)), s);
}

void replyKeyboardHide::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (selective_ << 2)), s);
}

void replyKeyboardHide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyKeyboardHide");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (selective_ << 2)));
    if (var0 & 4) { s.store_field("selective", true); }
    s.store_class_end();
  }
}

replyKeyboardForceReply::replyKeyboardForceReply()
  : flags_()
  , single_use_()
  , selective_()
  , placeholder_()
{}

replyKeyboardForceReply::replyKeyboardForceReply(int32 flags_, bool single_use_, bool selective_, string const &placeholder_)
  : flags_(flags_)
  , single_use_(single_use_)
  , selective_(selective_)
  , placeholder_(placeholder_)
{}

const std::int32_t replyKeyboardForceReply::ID;

object_ptr<ReplyMarkup> replyKeyboardForceReply::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<replyKeyboardForceReply> res = make_tl_object<replyKeyboardForceReply>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->single_use_ = (var0 & 2) != 0;
  res->selective_ = (var0 & 4) != 0;
  if (var0 & 8) { res->placeholder_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void replyKeyboardForceReply::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (single_use_ << 1) | (selective_ << 2) | ((!placeholder_.empty()) << 3)), s);
  if (var0 & 8) { TlStoreString::store(placeholder_, s); }
}

void replyKeyboardForceReply::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (single_use_ << 1) | (selective_ << 2) | ((!placeholder_.empty()) << 3)), s);
  if (var0 & 8) { TlStoreString::store(placeholder_, s); }
}

void replyKeyboardForceReply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyKeyboardForceReply");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (single_use_ << 1) | (selective_ << 2) | ((!placeholder_.empty()) << 3)));
    if (var0 & 2) { s.store_field("single_use", true); }
    if (var0 & 4) { s.store_field("selective", true); }
    if (var0 & 8) { s.store_field("placeholder", placeholder_); }
    s.store_class_end();
  }
}

replyKeyboardMarkup::replyKeyboardMarkup()
  : flags_()
  , resize_()
  , single_use_()
  , selective_()
  , persistent_()
  , force_reply_()
  , rows_()
  , placeholder_()
{}

replyKeyboardMarkup::replyKeyboardMarkup(int32 flags_, bool resize_, bool single_use_, bool selective_, bool persistent_, bool force_reply_, array<object_ptr<keyboardButtonRow>> &&rows_, string const &placeholder_)
  : flags_(flags_)
  , resize_(resize_)
  , single_use_(single_use_)
  , selective_(selective_)
  , persistent_(persistent_)
  , force_reply_(force_reply_)
  , rows_(std::move(rows_))
  , placeholder_(placeholder_)
{}

const std::int32_t replyKeyboardMarkup::ID;

object_ptr<ReplyMarkup> replyKeyboardMarkup::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<replyKeyboardMarkup> res = make_tl_object<replyKeyboardMarkup>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->resize_ = (var0 & 1) != 0;
  res->single_use_ = (var0 & 2) != 0;
  res->selective_ = (var0 & 4) != 0;
  res->persistent_ = (var0 & 16) != 0;
  res->force_reply_ = (var0 & 32) != 0;
  res->rows_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<keyboardButtonRow>, 2002815875>>, 481674261>::parse(p);
  if (var0 & 8) { res->placeholder_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void replyKeyboardMarkup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (resize_ << 0) | (single_use_ << 1) | (selective_ << 2) | (persistent_ << 4) | (force_reply_ << 5) | ((!placeholder_.empty()) << 3)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 2002815875>>, 481674261>::store(rows_, s);
  if (var0 & 8) { TlStoreString::store(placeholder_, s); }
}

void replyKeyboardMarkup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (resize_ << 0) | (single_use_ << 1) | (selective_ << 2) | (persistent_ << 4) | (force_reply_ << 5) | ((!placeholder_.empty()) << 3)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 2002815875>>, 481674261>::store(rows_, s);
  if (var0 & 8) { TlStoreString::store(placeholder_, s); }
}

void replyKeyboardMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyKeyboardMarkup");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (resize_ << 0) | (single_use_ << 1) | (selective_ << 2) | (persistent_ << 4) | (force_reply_ << 5) | ((!placeholder_.empty()) << 3)));
    if (var0 & 1) { s.store_field("resize", true); }
    if (var0 & 2) { s.store_field("single_use", true); }
    if (var0 & 4) { s.store_field("selective", true); }
    if (var0 & 16) { s.store_field("persistent", true); }
    if (var0 & 32) { s.store_field("force_reply", true); }
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 8) { s.store_field("placeholder", placeholder_); }
    s.store_class_end();
  }
}

replyInlineMarkup::replyInlineMarkup()
  : flags_()
  , force_reply_()
  , rows_()
{}

replyInlineMarkup::replyInlineMarkup(int32 flags_, bool force_reply_, array<object_ptr<keyboardInlineButtonRow>> &&rows_)
  : flags_(flags_)
  , force_reply_(force_reply_)
  , rows_(std::move(rows_))
{}

const std::int32_t replyInlineMarkup::ID;

object_ptr<ReplyMarkup> replyInlineMarkup::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<replyInlineMarkup> res = make_tl_object<replyInlineMarkup>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->force_reply_ = (var0 & 32) != 0;
  res->rows_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<keyboardInlineButtonRow>, 423758582>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void replyInlineMarkup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (force_reply_ << 5)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 423758582>>, 481674261>::store(rows_, s);
}

void replyInlineMarkup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (force_reply_ << 5)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 423758582>>, 481674261>::store(rows_, s);
}

void replyInlineMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyInlineMarkup");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (force_reply_ << 5)));
    if (var0 & 32) { s.store_field("force_reply", true); }
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<SecureValueError> SecureValueError::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case secureValueErrorData::ID:
      return secureValueErrorData::fetch(p);
    case secureValueErrorFrontSide::ID:
      return secureValueErrorFrontSide::fetch(p);
    case secureValueErrorReverseSide::ID:
      return secureValueErrorReverseSide::fetch(p);
    case secureValueErrorSelfie::ID:
      return secureValueErrorSelfie::fetch(p);
    case secureValueErrorFile::ID:
      return secureValueErrorFile::fetch(p);
    case secureValueErrorFiles::ID:
      return secureValueErrorFiles::fetch(p);
    case secureValueError::ID:
      return secureValueError::fetch(p);
    case secureValueErrorTranslationFile::ID:
      return secureValueErrorTranslationFile::fetch(p);
    case secureValueErrorTranslationFiles::ID:
      return secureValueErrorTranslationFiles::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

secureValueErrorData::secureValueErrorData(object_ptr<SecureValueType> &&type_, bytes &&data_hash_, string const &field_, string const &text_)
  : type_(std::move(type_))
  , data_hash_(std::move(data_hash_))
  , field_(field_)
  , text_(text_)
{}

const std::int32_t secureValueErrorData::ID;

object_ptr<SecureValueError> secureValueErrorData::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorData>(p);
}

secureValueErrorData::secureValueErrorData(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , data_hash_(TlFetchBytes<bytes>::parse(p))
  , field_(TlFetchString<string>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(data_hash_, s);
  TlStoreString::store(field_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(data_hash_, s);
  TlStoreString::store(field_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorData");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("data_hash", data_hash_);
    s.store_field("field", field_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorFrontSide::secureValueErrorFrontSide(object_ptr<SecureValueType> &&type_, bytes &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorFrontSide::ID;

object_ptr<SecureValueError> secureValueErrorFrontSide::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorFrontSide>(p);
}

secureValueErrorFrontSide::secureValueErrorFrontSide(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorFrontSide::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFrontSide::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFrontSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorFrontSide");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorReverseSide::secureValueErrorReverseSide(object_ptr<SecureValueType> &&type_, bytes &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorReverseSide::ID;

object_ptr<SecureValueError> secureValueErrorReverseSide::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorReverseSide>(p);
}

secureValueErrorReverseSide::secureValueErrorReverseSide(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorReverseSide::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorReverseSide::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorReverseSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorReverseSide");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorSelfie::secureValueErrorSelfie(object_ptr<SecureValueType> &&type_, bytes &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorSelfie::ID;

object_ptr<SecureValueError> secureValueErrorSelfie::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorSelfie>(p);
}

secureValueErrorSelfie::secureValueErrorSelfie(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorSelfie::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorSelfie::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorSelfie::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorSelfie");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorFile::secureValueErrorFile(object_ptr<SecureValueType> &&type_, bytes &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorFile::ID;

object_ptr<SecureValueError> secureValueErrorFile::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorFile>(p);
}

secureValueErrorFile::secureValueErrorFile(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorFile");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorFiles::secureValueErrorFiles(object_ptr<SecureValueType> &&type_, array<bytes> &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorFiles::ID;

object_ptr<SecureValueError> secureValueErrorFiles::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorFiles>(p);
}

secureValueErrorFiles::secureValueErrorFiles(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBoxed<TlFetchVector<TlFetchBytes<bytes>>, 481674261>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorFiles::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFiles::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorFiles");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    { s.store_vector_begin("file_hash", file_hash_.size()); for (const auto &_value : file_hash_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueError::secureValueError(object_ptr<SecureValueType> &&type_, bytes &&hash_, string const &text_)
  : type_(std::move(type_))
  , hash_(std::move(hash_))
  , text_(text_)
{}

const std::int32_t secureValueError::ID;

object_ptr<SecureValueError> secureValueError::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueError>(p);
}

secureValueError::secureValueError(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueError::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueError::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueError");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("hash", hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorTranslationFile::secureValueErrorTranslationFile(object_ptr<SecureValueType> &&type_, bytes &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorTranslationFile::ID;

object_ptr<SecureValueError> secureValueErrorTranslationFile::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorTranslationFile>(p);
}

secureValueErrorTranslationFile::secureValueErrorTranslationFile(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorTranslationFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorTranslationFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorTranslationFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorTranslationFile");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorTranslationFiles::secureValueErrorTranslationFiles(object_ptr<SecureValueType> &&type_, array<bytes> &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorTranslationFiles::ID;

object_ptr<SecureValueError> secureValueErrorTranslationFiles::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorTranslationFiles>(p);
}

secureValueErrorTranslationFiles::secureValueErrorTranslationFiles(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBoxed<TlFetchVector<TlFetchBytes<bytes>>, 481674261>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorTranslationFiles::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorTranslationFiles::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorTranslationFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorTranslationFiles");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    { s.store_vector_begin("file_hash", file_hash_.size()); for (const auto &_value : file_hash_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

const std::int32_t sponsoredMessageReportOption::ID;

object_ptr<sponsoredMessageReportOption> sponsoredMessageReportOption::fetch(TlBufferParser &p) {
  return make_tl_object<sponsoredMessageReportOption>(p);
}

sponsoredMessageReportOption::sponsoredMessageReportOption(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , option_(TlFetchBytes<bytes>::parse(p))
{}

void sponsoredMessageReportOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredMessageReportOption");
    s.store_field("text", text_);
    s.store_bytes_field("option", option_);
    s.store_class_end();
  }
}

starsSubscriptionPricing::starsSubscriptionPricing(int32 period_, int64 amount_)
  : period_(period_)
  , amount_(amount_)
{}

const std::int32_t starsSubscriptionPricing::ID;

object_ptr<starsSubscriptionPricing> starsSubscriptionPricing::fetch(TlBufferParser &p) {
  return make_tl_object<starsSubscriptionPricing>(p);
}

starsSubscriptionPricing::starsSubscriptionPricing(TlBufferParser &p)
  : period_(TlFetchInt::parse(p))
  , amount_(TlFetchLong::parse(p))
{}

void starsSubscriptionPricing::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(period_, s);
  TlStoreBinary::store(amount_, s);
}

void starsSubscriptionPricing::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(period_, s);
  TlStoreBinary::store(amount_, s);
}

void starsSubscriptionPricing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsSubscriptionPricing");
    s.store_field("period", period_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

starsTopupOption::starsTopupOption()
  : flags_()
  , extended_()
  , stars_()
  , store_product_()
  , currency_()
  , amount_()
{}

const std::int32_t starsTopupOption::ID;

object_ptr<starsTopupOption> starsTopupOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsTopupOption> res = make_tl_object<starsTopupOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->extended_ = (var0 & 2) != 0;
  res->stars_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->store_product_ = TlFetchString<string>::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsTopupOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTopupOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (extended_ << 1) | ((!store_product_.empty()) << 0)));
    if (var0 & 2) { s.store_field("extended", true); }
    s.store_field("stars", stars_);
    if (var0 & 1) { s.store_field("store_product", store_product_); }
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

const std::int32_t statsGroupTopAdmin::ID;

object_ptr<statsGroupTopAdmin> statsGroupTopAdmin::fetch(TlBufferParser &p) {
  return make_tl_object<statsGroupTopAdmin>(p);
}

statsGroupTopAdmin::statsGroupTopAdmin(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , deleted_(TlFetchInt::parse(p))
  , kicked_(TlFetchInt::parse(p))
  , banned_(TlFetchInt::parse(p))
{}

void statsGroupTopAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGroupTopAdmin");
    s.store_field("user_id", user_id_);
    s.store_field("deleted", deleted_);
    s.store_field("kicked", kicked_);
    s.store_field("banned", banned_);
    s.store_class_end();
  }
}

const std::int32_t statsGroupTopPoster::ID;

object_ptr<statsGroupTopPoster> statsGroupTopPoster::fetch(TlBufferParser &p) {
  return make_tl_object<statsGroupTopPoster>(p);
}

statsGroupTopPoster::statsGroupTopPoster(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , messages_(TlFetchInt::parse(p))
  , avg_chars_(TlFetchInt::parse(p))
{}

void statsGroupTopPoster::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGroupTopPoster");
    s.store_field("user_id", user_id_);
    s.store_field("messages", messages_);
    s.store_field("avg_chars", avg_chars_);
    s.store_class_end();
  }
}

suggestedPost::suggestedPost()
  : flags_()
  , accepted_()
  , rejected_()
  , price_()
  , schedule_date_()
{}

suggestedPost::suggestedPost(int32 flags_, bool accepted_, bool rejected_, object_ptr<StarsAmount> &&price_, int32 schedule_date_)
  : flags_(flags_)
  , accepted_(accepted_)
  , rejected_(rejected_)
  , price_(std::move(price_))
  , schedule_date_(schedule_date_)
{}

const std::int32_t suggestedPost::ID;

object_ptr<suggestedPost> suggestedPost::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<suggestedPost> res = make_tl_object<suggestedPost>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->accepted_ = (var0 & 2) != 0;
  res->rejected_ = (var0 & 4) != 0;
  if (var0 & 8) { res->price_ = TlFetchObject<StarsAmount>::parse(p); }
  if (var0 & 1) { res->schedule_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void suggestedPost::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (accepted_ << 1) | (rejected_ << 2) | ((price_ != nullptr) << 3)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(price_, s); }
  if (var0 & 1) { TlStoreBinary::store(schedule_date_, s); }
}

void suggestedPost::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (accepted_ << 1) | (rejected_ << 2) | ((price_ != nullptr) << 3)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(price_, s); }
  if (var0 & 1) { TlStoreBinary::store(schedule_date_, s); }
}

void suggestedPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPost");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (accepted_ << 1) | (rejected_ << 2) | ((price_ != nullptr) << 3)));
    if (var0 & 2) { s.store_field("accepted", true); }
    if (var0 & 4) { s.store_field("rejected", true); }
    if (var0 & 8) { s.store_object_field("price", static_cast<const BaseObject *>(price_.get())); }
    if (var0 & 1) { s.store_field("schedule_date", schedule_date_); }
    s.store_class_end();
  }
}

username::username()
  : flags_()
  , editable_()
  , active_()
  , deletable_()
  , expired_()
  , username_()
{}

username::username(int32 flags_, bool editable_, bool active_, bool deletable_, bool expired_, string const &username_)
  : flags_(flags_)
  , editable_(editable_)
  , active_(active_)
  , deletable_(deletable_)
  , expired_(expired_)
  , username_(username_)
{}

const std::int32_t username::ID;

object_ptr<username> username::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<username> res = make_tl_object<username>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->editable_ = (var0 & 1) != 0;
  res->active_ = (var0 & 2) != 0;
  res->deletable_ = (var0 & 4) != 0;
  res->expired_ = (var0 & 8) != 0;
  res->username_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void username::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (editable_ << 0) | (active_ << 1) | (deletable_ << 2) | (expired_ << 3)), s);
  TlStoreString::store(username_, s);
}

void username::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (editable_ << 0) | (active_ << 1) | (deletable_ << 2) | (expired_ << 3)), s);
  TlStoreString::store(username_, s);
}

void username::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "username");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (editable_ << 0) | (active_ << 1) | (deletable_ << 2) | (expired_ << 3)));
    if (var0 & 1) { s.store_field("editable", true); }
    if (var0 & 2) { s.store_field("active", true); }
    if (var0 & 4) { s.store_field("deletable", true); }
    if (var0 & 8) { s.store_field("expired", true); }
    s.store_field("username", username_);
    s.store_class_end();
  }
}

const std::int32_t account_paidMessagesRevenue::ID;

object_ptr<account_paidMessagesRevenue> account_paidMessagesRevenue::fetch(TlBufferParser &p) {
  return make_tl_object<account_paidMessagesRevenue>(p);
}

account_paidMessagesRevenue::account_paidMessagesRevenue(TlBufferParser &p)
  : stars_amount_(TlFetchLong::parse(p))
{}

void account_paidMessagesRevenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.paidMessagesRevenue");
    s.store_field("stars_amount", stars_amount_);
    s.store_class_end();
  }
}

const std::int32_t account_passkeys::ID;

object_ptr<account_passkeys> account_passkeys::fetch(TlBufferParser &p) {
  return make_tl_object<account_passkeys>(p);
}

account_passkeys::account_passkeys(TlBufferParser &p)
  : passkeys_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<passkey>, -1738457409>>, 481674261>::parse(p))
{}

void account_passkeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.passkeys");
    { s.store_vector_begin("passkeys", passkeys_.size()); for (const auto &_value : passkeys_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<account_Themes> account_Themes::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_themesNotModified::ID:
      return account_themesNotModified::fetch(p);
    case account_themes::ID:
      return account_themes::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_themesNotModified::ID;

object_ptr<account_Themes> account_themesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_themesNotModified>();
}

void account_themesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.themesNotModified");
    s.store_class_end();
  }
}

const std::int32_t account_themes::ID;

object_ptr<account_Themes> account_themes::fetch(TlBufferParser &p) {
  return make_tl_object<account_themes>(p);
}

account_themes::account_themes(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , themes_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<theme>, -1609668650>>, 481674261>::parse(p))
{}

void account_themes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.themes");
    s.store_field("hash", hash_);
    { s.store_vector_begin("themes", themes_.size()); for (const auto &_value : themes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t communities_participantJoinedChats::ID;

object_ptr<communities_participantJoinedChats> communities_participantJoinedChats::fetch(TlBufferParser &p) {
  return make_tl_object<communities_participantJoinedChats>(p);
}

communities_participantJoinedChats::communities_participantJoinedChats(TlBufferParser &p)
  : creator_chat_ids_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
  , joined_chat_ids_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void communities_participantJoinedChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities.participantJoinedChats");
    { s.store_vector_begin("creator_chat_ids", creator_chat_ids_.size()); for (const auto &_value : creator_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("joined_chat_ids", joined_chat_ids_.size()); for (const auto &_value : joined_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<contacts_Contacts> contacts_Contacts::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case contacts_contactsNotModified::ID:
      return contacts_contactsNotModified::fetch(p);
    case contacts_contacts::ID:
      return contacts_contacts::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t contacts_contactsNotModified::ID;

object_ptr<contacts_Contacts> contacts_contactsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_contactsNotModified>();
}

void contacts_contactsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.contactsNotModified");
    s.store_class_end();
  }
}

const std::int32_t contacts_contacts::ID;

object_ptr<contacts_Contacts> contacts_contacts::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_contacts>(p);
}

contacts_contacts::contacts_contacts(TlBufferParser &p)
  : contacts_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<contact>, 341499403>>, 481674261>::parse(p))
  , saved_count_(TlFetchInt::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_contacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.contacts");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("saved_count", saved_count_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t contacts_found::ID;

object_ptr<contacts_found> contacts_found::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_found>(p);
}

contacts_found::contacts_found(TlBufferParser &p)
  : my_results_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , results_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_found::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.found");
    { s.store_vector_begin("my_results", my_results_.size()); for (const auto &_value : my_results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<contacts_SponsoredPeers> contacts_SponsoredPeers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case contacts_sponsoredPeersEmpty::ID:
      return contacts_sponsoredPeersEmpty::fetch(p);
    case contacts_sponsoredPeers::ID:
      return contacts_sponsoredPeers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t contacts_sponsoredPeersEmpty::ID;

object_ptr<contacts_SponsoredPeers> contacts_sponsoredPeersEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_sponsoredPeersEmpty>();
}

void contacts_sponsoredPeersEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.sponsoredPeersEmpty");
    s.store_class_end();
  }
}

const std::int32_t contacts_sponsoredPeers::ID;

object_ptr<contacts_SponsoredPeers> contacts_sponsoredPeers::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_sponsoredPeers>(p);
}

contacts_sponsoredPeers::contacts_sponsoredPeers(TlBufferParser &p)
  : peers_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<sponsoredPeer>, -963180333>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_sponsoredPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.sponsoredPeers");
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t fragment_collectibleInfo::ID;

object_ptr<fragment_collectibleInfo> fragment_collectibleInfo::fetch(TlBufferParser &p) {
  return make_tl_object<fragment_collectibleInfo>(p);
}

fragment_collectibleInfo::fragment_collectibleInfo(TlBufferParser &p)
  : purchase_date_(TlFetchInt::parse(p))
  , currency_(TlFetchString<string>::parse(p))
  , amount_(TlFetchLong::parse(p))
  , crypto_currency_(TlFetchString<string>::parse(p))
  , crypto_amount_(TlFetchLong::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void fragment_collectibleInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fragment.collectibleInfo");
    s.store_field("purchase_date", purchase_date_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("crypto_currency", crypto_currency_);
    s.store_field("crypto_amount", crypto_amount_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

help_country::help_country()
  : flags_()
  , hidden_()
  , iso2_()
  , default_name_()
  , name_()
  , country_codes_()
{}

const std::int32_t help_country::ID;

object_ptr<help_country> help_country::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_country> res = make_tl_object<help_country>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->hidden_ = (var0 & 1) != 0;
  res->iso2_ = TlFetchString<string>::parse(p);
  res->default_name_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->name_ = TlFetchString<string>::parse(p); }
  res->country_codes_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<help_countryCode>, 1107543535>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void help_country::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.country");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (hidden_ << 0) | ((!name_.empty()) << 1)));
    if (var0 & 1) { s.store_field("hidden", true); }
    s.store_field("iso2", iso2_);
    s.store_field("default_name", default_name_);
    if (var0 & 2) { s.store_field("name", name_); }
    { s.store_vector_begin("country_codes", country_codes_.size()); for (const auto &_value : country_codes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<help_PeerColors> help_PeerColors::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_peerColorsNotModified::ID:
      return help_peerColorsNotModified::fetch(p);
    case help_peerColors::ID:
      return help_peerColors::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_peerColorsNotModified::ID;

object_ptr<help_PeerColors> help_peerColorsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<help_peerColorsNotModified>();
}

void help_peerColorsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.peerColorsNotModified");
    s.store_class_end();
  }
}

const std::int32_t help_peerColors::ID;

object_ptr<help_PeerColors> help_peerColors::fetch(TlBufferParser &p) {
  return make_tl_object<help_peerColors>(p);
}

help_peerColors::help_peerColors(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , colors_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<help_peerColorOption>, -1377014082>>, 481674261>::parse(p))
{}

void help_peerColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.peerColors");
    s.store_field("hash", hash_);
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

help_termsOfService::help_termsOfService()
  : flags_()
  , popup_()
  , id_()
  , text_()
  , entities_()
  , min_age_confirm_()
{}

const std::int32_t help_termsOfService::ID;

object_ptr<help_termsOfService> help_termsOfService::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_termsOfService> res = make_tl_object<help_termsOfService>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->popup_ = (var0 & 1) != 0;
  res->id_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
  res->text_ = TlFetchString<string>::parse(p);
  res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p);
  if (var0 & 2) { res->min_age_confirm_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void help_termsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.termsOfService");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (popup_ << 0)));
    if (var0 & 1) { s.store_field("popup", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("text", text_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 2) { s.store_field("min_age_confirm", min_age_confirm_); }
    s.store_class_end();
  }
}

object_ptr<messages_FavedStickers> messages_FavedStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_favedStickersNotModified::ID:
      return messages_favedStickersNotModified::fetch(p);
    case messages_favedStickers::ID:
      return messages_favedStickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_favedStickersNotModified::ID;

object_ptr<messages_FavedStickers> messages_favedStickersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_favedStickersNotModified>();
}

void messages_favedStickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.favedStickersNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_favedStickers::ID;

object_ptr<messages_FavedStickers> messages_favedStickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_favedStickers>(p);
}

messages_favedStickers::messages_favedStickers(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , packs_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerPack>, 313694676>>, 481674261>::parse(p))
  , stickers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void messages_favedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.favedStickers");
    s.store_field("hash", hash_);
    { s.store_vector_begin("packs", packs_.size()); for (const auto &_value : packs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_messageReactionsList::messages_messageReactionsList()
  : flags_()
  , count_()
  , reactions_()
  , chats_()
  , users_()
  , next_offset_()
{}

const std::int32_t messages_messageReactionsList::ID;

object_ptr<messages_messageReactionsList> messages_messageReactionsList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_messageReactionsList> res = make_tl_object<messages_messageReactionsList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->reactions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messagePeerReaction>, -1938180548>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_messageReactionsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messageReactionsList");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("count", count_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

const std::int32_t messages_peerSettings::ID;

object_ptr<messages_peerSettings> messages_peerSettings::fetch(TlBufferParser &p) {
  return make_tl_object<messages_peerSettings>(p);
}

messages_peerSettings::messages_peerSettings(TlBufferParser &p)
  : settings_(TlFetchBoxed<TlFetchObject<peerSettings>, -193510921>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_peerSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.peerSettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_preparedInlineMessage::ID;

object_ptr<messages_preparedInlineMessage> messages_preparedInlineMessage::fetch(TlBufferParser &p) {
  return make_tl_object<messages_preparedInlineMessage>(p);
}

messages_preparedInlineMessage::messages_preparedInlineMessage(TlBufferParser &p)
  : query_id_(TlFetchLong::parse(p))
  , result_(TlFetchObject<BotInlineResult>::parse(p))
  , peer_types_(TlFetchBoxed<TlFetchVector<TlFetchObject<InlineQueryPeerType>>, 481674261>::parse(p))
  , cache_time_(TlFetchInt::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_preparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.preparedInlineMessage");
    s.store_field("query_id", query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    { s.store_vector_begin("peer_types", peer_types_.size()); for (const auto &_value : peer_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("cache_time", cache_time_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_Stickers> messages_Stickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_stickersNotModified::ID:
      return messages_stickersNotModified::fetch(p);
    case messages_stickers::ID:
      return messages_stickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_stickersNotModified::ID;

object_ptr<messages_Stickers> messages_stickersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickersNotModified>();
}

void messages_stickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickersNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_stickers::ID;

object_ptr<messages_Stickers> messages_stickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickers>(p);
}

messages_stickers::messages_stickers(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , stickers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void messages_stickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickers");
    s.store_field("hash", hash_);
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<payments_CheckCanSendGiftResult> payments_CheckCanSendGiftResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_checkCanSendGiftResultOk::ID:
      return payments_checkCanSendGiftResultOk::fetch(p);
    case payments_checkCanSendGiftResultFail::ID:
      return payments_checkCanSendGiftResultFail::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t payments_checkCanSendGiftResultOk::ID;

object_ptr<payments_CheckCanSendGiftResult> payments_checkCanSendGiftResultOk::fetch(TlBufferParser &p) {
  return make_tl_object<payments_checkCanSendGiftResultOk>();
}

void payments_checkCanSendGiftResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.checkCanSendGiftResultOk");
    s.store_class_end();
  }
}

const std::int32_t payments_checkCanSendGiftResultFail::ID;

object_ptr<payments_CheckCanSendGiftResult> payments_checkCanSendGiftResultFail::fetch(TlBufferParser &p) {
  return make_tl_object<payments_checkCanSendGiftResultFail>(p);
}

payments_checkCanSendGiftResultFail::payments_checkCanSendGiftResultFail(TlBufferParser &p)
  : reason_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
{}

void payments_checkCanSendGiftResultFail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.checkCanSendGiftResultFail");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

object_ptr<payments_PaymentReceipt> payments_PaymentReceipt::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_paymentReceipt::ID:
      return payments_paymentReceipt::fetch(p);
    case payments_paymentReceiptStars::ID:
      return payments_paymentReceiptStars::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

payments_paymentReceipt::payments_paymentReceipt()
  : flags_()
  , date_()
  , bot_id_()
  , provider_id_()
  , title_()
  , description_()
  , photo_()
  , invoice_()
  , info_()
  , shipping_()
  , tip_amount_()
  , currency_()
  , total_amount_()
  , credentials_title_()
  , users_()
{}

const std::int32_t payments_paymentReceipt::ID;

object_ptr<payments_PaymentReceipt> payments_paymentReceipt::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_paymentReceipt> res = make_tl_object<payments_paymentReceipt>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->date_ = TlFetchInt::parse(p);
  res->bot_id_ = TlFetchLong::parse(p);
  res->provider_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  res->invoice_ = TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p);
  if (var0 & 1) { res->info_ = TlFetchBoxed<TlFetchObject<paymentRequestedInfo>, -1868808300>::parse(p); }
  if (var0 & 2) { res->shipping_ = TlFetchBoxed<TlFetchObject<shippingOption>, -1239335713>::parse(p); }
  if (var0 & 8) { res->tip_amount_ = TlFetchLong::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  res->credentials_title_ = TlFetchString<string>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_paymentReceipt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentReceipt");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((photo_ != nullptr) << 2) | ((info_ != nullptr) << 0) | ((shipping_ != nullptr) << 1)));
    s.store_field("date", date_);
    s.store_field("bot_id", bot_id_);
    s.store_field("provider_id", provider_id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    if (var0 & 1) { s.store_object_field("info", static_cast<const BaseObject *>(info_.get())); }
    if (var0 & 2) { s.store_object_field("shipping", static_cast<const BaseObject *>(shipping_.get())); }
    if (var0 & 8) { s.store_field("tip_amount", tip_amount_); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("credentials_title", credentials_title_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_paymentReceiptStars::payments_paymentReceiptStars()
  : flags_()
  , date_()
  , bot_id_()
  , title_()
  , description_()
  , photo_()
  , invoice_()
  , currency_()
  , total_amount_()
  , transaction_id_()
  , users_()
{}

const std::int32_t payments_paymentReceiptStars::ID;

object_ptr<payments_PaymentReceipt> payments_paymentReceiptStars::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_paymentReceiptStars> res = make_tl_object<payments_paymentReceiptStars>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->date_ = TlFetchInt::parse(p);
  res->bot_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  res->invoice_ = TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p);
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  res->transaction_id_ = TlFetchString<string>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_paymentReceiptStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentReceiptStars");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((photo_ != nullptr) << 2)));
    s.store_field("date", date_);
    s.store_field("bot_id", bot_id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("transaction_id", transaction_id_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftAuctionAcquiredGifts::ID;

object_ptr<payments_starGiftAuctionAcquiredGifts> payments_starGiftAuctionAcquiredGifts::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftAuctionAcquiredGifts>(p);
}

payments_starGiftAuctionAcquiredGifts::payments_starGiftAuctionAcquiredGifts(TlBufferParser &p)
  : gifts_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftAuctionAcquiredGift>, 1118831432>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
{}

void payments_starGiftAuctionAcquiredGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftAuctionAcquiredGifts");
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftUpgradeAttributes::ID;

object_ptr<payments_starGiftUpgradeAttributes> payments_starGiftUpgradeAttributes::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftUpgradeAttributes>(p);
}

payments_starGiftUpgradeAttributes::payments_starGiftUpgradeAttributes(TlBufferParser &p)
  : attributes_(TlFetchBoxed<TlFetchVector<TlFetchObject<StarGiftAttribute>>, 481674261>::parse(p))
{}

void payments_starGiftUpgradeAttributes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftUpgradeAttributes");
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t photos_photo::ID;

object_ptr<photos_photo> photos_photo::fetch(TlBufferParser &p) {
  return make_tl_object<photos_photo>(p);
}

photos_photo::photos_photo(TlBufferParser &p)
  : photo_(TlFetchObject<Photo>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void photos_photo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.photo");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stats_messageStats::ID;

object_ptr<stats_messageStats> stats_messageStats::fetch(TlBufferParser &p) {
  return make_tl_object<stats_messageStats>(p);
}

stats_messageStats::stats_messageStats(TlBufferParser &p)
  : views_graph_(TlFetchObject<StatsGraph>::parse(p))
  , reactions_by_emotion_graph_(TlFetchObject<StatsGraph>::parse(p))
{}

void stats_messageStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.messageStats");
    s.store_object_field("views_graph", static_cast<const BaseObject *>(views_graph_.get()));
    s.store_object_field("reactions_by_emotion_graph", static_cast<const BaseObject *>(reactions_by_emotion_graph_.get()));
    s.store_class_end();
  }
}

stories_foundStories::stories_foundStories()
  : flags_()
  , count_()
  , stories_()
  , next_offset_()
  , chats_()
  , users_()
{}

const std::int32_t stories_foundStories::ID;

object_ptr<stories_foundStories> stories_foundStories::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_foundStories> res = make_tl_object<stories_foundStories>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->stories_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<foundStory>, -394605632>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stories_foundStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.foundStories");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("count", count_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t users_userFull::ID;

object_ptr<users_userFull> users_userFull::fetch(TlBufferParser &p) {
  return make_tl_object<users_userFull>(p);
}

users_userFull::users_userFull(TlBufferParser &p)
  : full_user_(TlFetchBoxed<TlFetchObject<userFull>, -1190384899>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void users_userFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.userFull");
    s.store_object_field("full_user", static_cast<const BaseObject *>(full_user_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t wallet_cardSticker::ID;

object_ptr<wallet_cardSticker> wallet_cardSticker::fetch(TlBufferParser &p) {
  return make_tl_object<wallet_cardSticker>(p);
}

wallet_cardSticker::wallet_cardSticker(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , nft_(TlFetchBoxed<TlFetchObject<wallet_nftItem>, 389937907>::parse(p))
{}

void wallet_cardSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.cardSticker");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_object_field("nft", static_cast<const BaseObject *>(nft_.get()));
    s.store_class_end();
  }
}

account_confirmPhone::account_confirmPhone(string const &phone_code_hash_, string const &phone_code_)
  : phone_code_hash_(phone_code_hash_)
  , phone_code_(phone_code_)
{}

const std::int32_t account_confirmPhone::ID;

void account_confirmPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1596029123);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_confirmPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1596029123);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_confirmPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.confirmPhone");
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("phone_code", "[REDACTED]");
    s.store_class_end();
  }
}

account_confirmPhone::ReturnType account_confirmPhone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_createTheme::account_createTheme(int32 flags_, string const &slug_, string const &title_, object_ptr<InputDocument> &&document_, array<object_ptr<inputThemeSettings>> &&settings_)
  : flags_(flags_)
  , slug_(slug_)
  , title_(title_)
  , document_(std::move(document_))
  , settings_(std::move(settings_))
{}

const std::int32_t account_createTheme::ID;

void account_createTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1697530880);
  TlStoreBinary::store((var0 = flags_ | ((document_ != nullptr) << 2) | ((!settings_.empty()) << 3)), s);
  TlStoreString::store(slug_, s);
  TlStoreString::store(title_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1881255857>>, 481674261>::store(settings_, s); }
}

void account_createTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1697530880);
  TlStoreBinary::store((var0 = flags_ | ((document_ != nullptr) << 2) | ((!settings_.empty()) << 3)), s);
  TlStoreString::store(slug_, s);
  TlStoreString::store(title_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1881255857>>, 481674261>::store(settings_, s); }
}

void account_createTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.createTheme");
    s.store_field("flags", (var0 = flags_ | ((document_ != nullptr) << 2) | ((!settings_.empty()) << 3)));
    s.store_field("slug", slug_);
    s.store_field("title", title_);
    if (var0 & 4) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 8) { { s.store_vector_begin("settings", settings_.size()); for (const auto &_value : settings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

account_createTheme::ReturnType account_createTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<theme>, -1609668650>::parse(p);
#undef FAIL
}

account_getSavedMusicIds::account_getSavedMusicIds(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getSavedMusicIds::ID;

void account_getSavedMusicIds::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-526557265);
  TlStoreBinary::store(hash_, s);
}

void account_getSavedMusicIds::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-526557265);
  TlStoreBinary::store(hash_, s);
}

void account_getSavedMusicIds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getSavedMusicIds");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getSavedMusicIds::ReturnType account_getSavedMusicIds::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_SavedMusicIds>::parse(p);
#undef FAIL
}

const std::int32_t account_initPasskeyRegistration::ID;

void account_initPasskeyRegistration::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1117079528);
}

void account_initPasskeyRegistration::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1117079528);
}

void account_initPasskeyRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.initPasskeyRegistration");
    s.store_class_end();
  }
}

account_initPasskeyRegistration::ReturnType account_initPasskeyRegistration::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_passkeyRegistrationOptions>, -513057567>::parse(p);
#undef FAIL
}

account_registerPasskey::account_registerPasskey(object_ptr<inputPasskeyCredentialPublicKey> &&credential_)
  : credential_(std::move(credential_))
{}

const std::int32_t account_registerPasskey::ID;

void account_registerPasskey::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1437867990);
  TlStoreBoxed<TlStoreObject, 1009235855>::store(credential_, s);
}

void account_registerPasskey::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1437867990);
  TlStoreBoxed<TlStoreObject, 1009235855>::store(credential_, s);
}

void account_registerPasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.registerPasskey");
    s.store_object_field("credential", static_cast<const BaseObject *>(credential_.get()));
    s.store_class_end();
  }
}

account_registerPasskey::ReturnType account_registerPasskey::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<passkey>, -1738457409>::parse(p);
#undef FAIL
}

account_saveMusic::account_saveMusic(int32 flags_, bool unsave_, object_ptr<InputDocument> &&id_, object_ptr<InputDocument> &&after_id_)
  : flags_(flags_)
  , unsave_(unsave_)
  , id_(std::move(id_))
  , after_id_(std::move(after_id_))
{}

const std::int32_t account_saveMusic::ID;

void account_saveMusic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1301859671);
  TlStoreBinary::store((var0 = flags_ | (unsave_ << 0) | ((after_id_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(after_id_, s); }
}

void account_saveMusic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1301859671);
  TlStoreBinary::store((var0 = flags_ | (unsave_ << 0) | ((after_id_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(after_id_, s); }
}

void account_saveMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveMusic");
    s.store_field("flags", (var0 = flags_ | (unsave_ << 0) | ((after_id_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("unsave", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    if (var0 & 2) { s.store_object_field("after_id", static_cast<const BaseObject *>(after_id_.get())); }
    s.store_class_end();
  }
}

account_saveMusic::ReturnType account_saveMusic::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_setAuthorizationTTL::account_setAuthorizationTTL(int32 authorization_ttl_days_)
  : authorization_ttl_days_(authorization_ttl_days_)
{}

const std::int32_t account_setAuthorizationTTL::ID;

void account_setAuthorizationTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1081501024);
  TlStoreBinary::store(authorization_ttl_days_, s);
}

void account_setAuthorizationTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1081501024);
  TlStoreBinary::store(authorization_ttl_days_, s);
}

void account_setAuthorizationTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setAuthorizationTTL");
    s.store_field("authorization_ttl_days", authorization_ttl_days_);
    s.store_class_end();
  }
}

account_setAuthorizationTTL::ReturnType account_setAuthorizationTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_unregisterDevice::account_unregisterDevice(int32 token_type_, string const &token_, array<int64> &&other_uids_)
  : token_type_(token_type_)
  , token_(token_)
  , other_uids_(std::move(other_uids_))
{}

const std::int32_t account_unregisterDevice::ID;

void account_unregisterDevice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1779249670);
  TlStoreBinary::store(token_type_, s);
  TlStoreString::store(token_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(other_uids_, s);
}

void account_unregisterDevice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1779249670);
  TlStoreBinary::store(token_type_, s);
  TlStoreString::store(token_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(other_uids_, s);
}

void account_unregisterDevice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.unregisterDevice");
    s.store_field("token_type", token_type_);
    s.store_field("token", "[REDACTED]");
    { s.store_vector_begin("other_uids", other_uids_.size()); for (const auto &_value : other_uids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_unregisterDevice::ReturnType account_unregisterDevice::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateBusinessAwayMessage::account_updateBusinessAwayMessage(int32 flags_, object_ptr<inputBusinessAwayMessage> &&message_)
  : flags_(flags_)
  , message_(std::move(message_))
{}

const std::int32_t account_updateBusinessAwayMessage::ID;

void account_updateBusinessAwayMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1570078811);
  TlStoreBinary::store((var0 = flags_ | ((message_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -2094959136>::store(message_, s); }
}

void account_updateBusinessAwayMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1570078811);
  TlStoreBinary::store((var0 = flags_ | ((message_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -2094959136>::store(message_, s); }
}

void account_updateBusinessAwayMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBusinessAwayMessage");
    s.store_field("flags", (var0 = flags_ | ((message_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

account_updateBusinessAwayMessage::ReturnType account_updateBusinessAwayMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateDeviceLocked::account_updateDeviceLocked(int32 period_)
  : period_(period_)
{}

const std::int32_t account_updateDeviceLocked::ID;

void account_updateDeviceLocked::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(954152242);
  TlStoreBinary::store(period_, s);
}

void account_updateDeviceLocked::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(954152242);
  TlStoreBinary::store(period_, s);
}

void account_updateDeviceLocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateDeviceLocked");
    s.store_field("period", period_);
    s.store_class_end();
  }
}

account_updateDeviceLocked::ReturnType account_updateDeviceLocked::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_acceptLoginToken::auth_acceptLoginToken(bytes &&token_)
  : token_(std::move(token_))
{}

const std::int32_t auth_acceptLoginToken::ID;

void auth_acceptLoginToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-392909491);
  TlStoreString::store(token_, s);
}

void auth_acceptLoginToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-392909491);
  TlStoreString::store(token_, s);
}

void auth_acceptLoginToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.acceptLoginToken");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

auth_acceptLoginToken::ReturnType auth_acceptLoginToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<authorization>, -1392388579>::parse(p);
#undef FAIL
}

auth_requestFirebaseSms::auth_requestFirebaseSms(int32 flags_, string const &phone_number_, string const &phone_code_hash_, string const &safety_net_token_, string const &play_integrity_token_, string const &ios_push_secret_)
  : flags_(flags_)
  , phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , safety_net_token_(safety_net_token_)
  , play_integrity_token_(play_integrity_token_)
  , ios_push_secret_(ios_push_secret_)
{}

const std::int32_t auth_requestFirebaseSms::ID;

void auth_requestFirebaseSms::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1908857314);
  TlStoreBinary::store((var0 = flags_ | ((!safety_net_token_.empty()) << 0) | ((!play_integrity_token_.empty()) << 2) | ((!ios_push_secret_.empty()) << 1)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(safety_net_token_, s); }
  if (var0 & 4) { TlStoreString::store(play_integrity_token_, s); }
  if (var0 & 2) { TlStoreString::store(ios_push_secret_, s); }
}

void auth_requestFirebaseSms::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1908857314);
  TlStoreBinary::store((var0 = flags_ | ((!safety_net_token_.empty()) << 0) | ((!play_integrity_token_.empty()) << 2) | ((!ios_push_secret_.empty()) << 1)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(safety_net_token_, s); }
  if (var0 & 4) { TlStoreString::store(play_integrity_token_, s); }
  if (var0 & 2) { TlStoreString::store(ios_push_secret_, s); }
}

void auth_requestFirebaseSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.requestFirebaseSms");
    s.store_field("flags", (var0 = flags_ | ((!safety_net_token_.empty()) << 0) | ((!play_integrity_token_.empty()) << 2) | ((!ios_push_secret_.empty()) << 1)));
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    if (var0 & 1) { s.store_field("safety_net_token", "[REDACTED]"); }
    if (var0 & 4) { s.store_field("play_integrity_token", "[REDACTED]"); }
    if (var0 & 2) { s.store_field("ios_push_secret", "[REDACTED]"); }
    s.store_class_end();
  }
}

auth_requestFirebaseSms::ReturnType auth_requestFirebaseSms::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_signUp::auth_signUp(int32 flags_, bool no_joined_notifications_, string const &phone_number_, string const &phone_code_hash_, string const &first_name_, string const &last_name_)
  : flags_(flags_)
  , no_joined_notifications_(no_joined_notifications_)
  , phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , first_name_(first_name_)
  , last_name_(last_name_)
{}

const std::int32_t auth_signUp::ID;

void auth_signUp::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1429752041);
  TlStoreBinary::store((var0 = flags_ | (no_joined_notifications_ << 0)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
}

void auth_signUp::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1429752041);
  TlStoreBinary::store((var0 = flags_ | (no_joined_notifications_ << 0)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
}

void auth_signUp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.signUp");
    s.store_field("flags", (var0 = flags_ | (no_joined_notifications_ << 0)));
    if (var0 & 1) { s.store_field("no_joined_notifications", true); }
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_class_end();
  }
}

auth_signUp::ReturnType auth_signUp::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

bots_checkDownloadFileParams::bots_checkDownloadFileParams(object_ptr<InputUser> &&bot_, string const &file_name_, string const &url_)
  : bot_(std::move(bot_))
  , file_name_(file_name_)
  , url_(url_)
{}

const std::int32_t bots_checkDownloadFileParams::ID;

void bots_checkDownloadFileParams::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1342666121);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(file_name_, s);
  TlStoreString::store(url_, s);
}

void bots_checkDownloadFileParams::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1342666121);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(file_name_, s);
  TlStoreString::store(url_, s);
}

void bots_checkDownloadFileParams::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.checkDownloadFileParams");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("file_name", file_name_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

bots_checkDownloadFileParams::ReturnType bots_checkDownloadFileParams::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_getBotInfo::bots_getBotInfo(int32 flags_, object_ptr<InputUser> &&bot_, string const &lang_code_)
  : flags_(flags_)
  , bot_(std::move(bot_))
  , lang_code_(lang_code_)
{}

const std::int32_t bots_getBotInfo::ID;

void bots_getBotInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-589753091);
  TlStoreBinary::store((var0 = flags_ | ((bot_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreString::store(lang_code_, s);
}

void bots_getBotInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-589753091);
  TlStoreBinary::store((var0 = flags_ | ((bot_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreString::store(lang_code_, s);
}

void bots_getBotInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getBotInfo");
    s.store_field("flags", (var0 = flags_ | ((bot_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

bots_getBotInfo::ReturnType bots_getBotInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<bots_botInfo>, -391678544>::parse(p);
#undef FAIL
}

bots_getBotMenuButton::bots_getBotMenuButton(object_ptr<InputUser> &&user_id_)
  : user_id_(std::move(user_id_))
{}

const std::int32_t bots_getBotMenuButton::ID;

void bots_getBotMenuButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1671369944);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void bots_getBotMenuButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1671369944);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void bots_getBotMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getBotMenuButton");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

bots_getBotMenuButton::ReturnType bots_getBotMenuButton::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<BotMenuButton>::parse(p);
#undef FAIL
}

bots_getBotRecommendations::bots_getBotRecommendations(object_ptr<InputUser> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t bots_getBotRecommendations::ID;

void bots_getBotRecommendations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1581840363);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_getBotRecommendations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1581840363);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_getBotRecommendations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getBotRecommendations");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

bots_getBotRecommendations::ReturnType bots_getBotRecommendations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<users_Users>::parse(p);
#undef FAIL
}

bots_toggleUsername::bots_toggleUsername(object_ptr<InputUser> &&bot_, string const &username_, bool active_)
  : bot_(std::move(bot_))
  , username_(username_)
  , active_(active_)
{}

const std::int32_t bots_toggleUsername::ID;

void bots_toggleUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(87861619);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void bots_toggleUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(87861619);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void bots_toggleUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.toggleUsername");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("username", username_);
    s.store_field("active", active_);
    s.store_class_end();
  }
}

bots_toggleUsername::ReturnType bots_toggleUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_convertToGigagroup::channels_convertToGigagroup(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_convertToGigagroup::ID;

void channels_convertToGigagroup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(187239529);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_convertToGigagroup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(187239529);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_convertToGigagroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.convertToGigagroup");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_convertToGigagroup::ReturnType channels_convertToGigagroup::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t channels_getInactiveChannels::ID;

void channels_getInactiveChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(300429806);
}

void channels_getInactiveChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(300429806);
}

void channels_getInactiveChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getInactiveChannels");
    s.store_class_end();
  }
}

channels_getInactiveChannels::ReturnType channels_getInactiveChannels::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_inactiveChats>, -1456996667>::parse(p);
#undef FAIL
}

channels_getParticipant::channels_getParticipant(object_ptr<InputChannel> &&channel_, object_ptr<InputPeer> &&participant_)
  : channel_(std::move(channel_))
  , participant_(std::move(participant_))
{}

const std::int32_t channels_getParticipant::ID;

void channels_getParticipant::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1599378234);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void channels_getParticipant::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1599378234);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void channels_getParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getParticipant");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

channels_getParticipant::ReturnType channels_getParticipant::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<channels_channelParticipant>, -541588713>::parse(p);
#undef FAIL
}

channels_setDiscussionGroup::channels_setDiscussionGroup(object_ptr<InputChannel> &&broadcast_, object_ptr<InputChannel> &&group_)
  : broadcast_(std::move(broadcast_))
  , group_(std::move(group_))
{}

const std::int32_t channels_setDiscussionGroup::ID;

void channels_setDiscussionGroup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1079520178);
  TlStoreBoxedUnknown<TlStoreObject>::store(broadcast_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(group_, s);
}

void channels_setDiscussionGroup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1079520178);
  TlStoreBoxedUnknown<TlStoreObject>::store(broadcast_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(group_, s);
}

void channels_setDiscussionGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.setDiscussionGroup");
    s.store_object_field("broadcast", static_cast<const BaseObject *>(broadcast_.get()));
    s.store_object_field("group", static_cast<const BaseObject *>(group_.get()));
    s.store_class_end();
  }
}

channels_setDiscussionGroup::ReturnType channels_setDiscussionGroup::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

communities_toggleCommunityCollapsedInDialogs::communities_toggleCommunityCollapsedInDialogs(int32 flags_, bool collapsed_, object_ptr<InputChannel> &&community_)
  : flags_(flags_)
  , collapsed_(collapsed_)
  , community_(std::move(community_))
{}

const std::int32_t communities_toggleCommunityCollapsedInDialogs::ID;

void communities_toggleCommunityCollapsedInDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-681122838);
  TlStoreBinary::store((var0 = flags_ | (collapsed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
}

void communities_toggleCommunityCollapsedInDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-681122838);
  TlStoreBinary::store((var0 = flags_ | (collapsed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
}

void communities_toggleCommunityCollapsedInDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities.toggleCommunityCollapsedInDialogs");
    s.store_field("flags", (var0 = flags_ | (collapsed_ << 0)));
    if (var0 & 1) { s.store_field("collapsed", true); }
    s.store_object_field("community", static_cast<const BaseObject *>(community_.get()));
    s.store_class_end();
  }
}

communities_toggleCommunityCollapsedInDialogs::ReturnType communities_toggleCommunityCollapsedInDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

contacts_getSponsoredPeers::contacts_getSponsoredPeers(string const &q_)
  : q_(q_)
{}

const std::int32_t contacts_getSponsoredPeers::ID;

void contacts_getSponsoredPeers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1228356717);
  TlStoreString::store(q_, s);
}

void contacts_getSponsoredPeers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1228356717);
  TlStoreString::store(q_, s);
}

void contacts_getSponsoredPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getSponsoredPeers");
    s.store_field("q", q_);
    s.store_class_end();
  }
}

contacts_getSponsoredPeers::ReturnType contacts_getSponsoredPeers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<contacts_SponsoredPeers>::parse(p);
#undef FAIL
}

contacts_importContacts::contacts_importContacts(array<object_ptr<inputPhoneContact>> &&contacts_)
  : contacts_(std::move(contacts_))
{}

const std::int32_t contacts_importContacts::ID;

void contacts_importContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(746589157);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1780335806>>, 481674261>::store(contacts_, s);
}

void contacts_importContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(746589157);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1780335806>>, 481674261>::store(contacts_, s);
}

void contacts_importContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.importContacts");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

contacts_importContacts::ReturnType contacts_importContacts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<contacts_importedContacts>, 2010127419>::parse(p);
#undef FAIL
}

contacts_toggleTopPeers::contacts_toggleTopPeers(bool enabled_)
  : enabled_(enabled_)
{}

const std::int32_t contacts_toggleTopPeers::ID;

void contacts_toggleTopPeers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2062238246);
  TlStoreBool::store(enabled_, s);
}

void contacts_toggleTopPeers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2062238246);
  TlStoreBool::store(enabled_, s);
}

void contacts_toggleTopPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.toggleTopPeers");
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

contacts_toggleTopPeers::ReturnType contacts_toggleTopPeers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

ephemeral_deleteMessage::ephemeral_deleteMessage(int32 flags_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&receiver_id_, int32 id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , receiver_id_(std::move(receiver_id_))
  , id_(id_)
{}

const std::int32_t ephemeral_deleteMessage::ID;

void ephemeral_deleteMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1829312617);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(receiver_id_, s);
  TlStoreBinary::store(id_, s);
}

void ephemeral_deleteMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1829312617);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(receiver_id_, s);
  TlStoreBinary::store(id_, s);
}

void ephemeral_deleteMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeral.deleteMessage");
    s.store_field("flags", (var0 = flags_ | ((peer_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

ephemeral_deleteMessage::ReturnType ephemeral_deleteMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

ephemeral_sendMessage::ephemeral_sendMessage(int32 flags_, bool invert_media_, bool welcome_, bool anchor_, bool noforwards_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&receiver_id_, int64 query_id_, string const &message_, array<object_ptr<MessageEntity>> &&entities_, object_ptr<InputMedia> &&media_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputRichMessage> &&rich_message_, int64 random_id_, object_ptr<InputReplyTo> &&reply_to_)
  : flags_(flags_)
  , invert_media_(invert_media_)
  , welcome_(welcome_)
  , anchor_(anchor_)
  , noforwards_(noforwards_)
  , peer_(std::move(peer_))
  , receiver_id_(std::move(receiver_id_))
  , query_id_(query_id_)
  , message_(message_)
  , entities_(std::move(entities_))
  , media_(std::move(media_))
  , reply_markup_(std::move(reply_markup_))
  , rich_message_(std::move(rich_message_))
  , random_id_(random_id_)
  , reply_to_(std::move(reply_to_))
{}

const std::int32_t ephemeral_sendMessage::ID;

void ephemeral_sendMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1165140171);
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 6) | (welcome_ << 7) | (anchor_ << 9) | (noforwards_ << 10) | ((peer_ != nullptr) << 8) | ((!entities_.empty()) << 1) | ((media_ != nullptr) << 2) | ((reply_markup_ != nullptr) << 3) | ((rich_message_ != nullptr) << 4) | ((reply_to_ != nullptr) << 5)), s);
  if (var0 & 256) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(receiver_id_, s);
  if (var0 & 1) { TlStoreBinary::store(query_id_, s); }
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
  TlStoreBinary::store(random_id_, s);
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
}

void ephemeral_sendMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1165140171);
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 6) | (welcome_ << 7) | (anchor_ << 9) | (noforwards_ << 10) | ((peer_ != nullptr) << 8) | ((!entities_.empty()) << 1) | ((media_ != nullptr) << 2) | ((reply_markup_ != nullptr) << 3) | ((rich_message_ != nullptr) << 4) | ((reply_to_ != nullptr) << 5)), s);
  if (var0 & 256) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(receiver_id_, s);
  if (var0 & 1) { TlStoreBinary::store(query_id_, s); }
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
  TlStoreBinary::store(random_id_, s);
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
}

void ephemeral_sendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeral.sendMessage");
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 6) | (welcome_ << 7) | (anchor_ << 9) | (noforwards_ << 10) | ((peer_ != nullptr) << 8) | ((!entities_.empty()) << 1) | ((media_ != nullptr) << 2) | ((reply_markup_ != nullptr) << 3) | ((rich_message_ != nullptr) << 4) | ((reply_to_ != nullptr) << 5)));
    if (var0 & 64) { s.store_field("invert_media", true); }
    if (var0 & 128) { s.store_field("welcome", true); }
    if (var0 & 512) { s.store_field("anchor", true); }
    if (var0 & 1024) { s.store_field("noforwards", true); }
    if (var0 & 256) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    if (var0 & 1) { s.store_field("query_id", query_id_); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 8) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 16) { s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get())); }
    s.store_field("random_id", random_id_);
    if (var0 & 32) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_class_end();
  }
}

ephemeral_sendMessage::ReturnType ephemeral_sendMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

invokeWithReCaptchaPrefix::invokeWithReCaptchaPrefix(string const &token_)
  : token_(token_)
{}

const std::int32_t invokeWithReCaptchaPrefix::ID;

void invokeWithReCaptchaPrefix::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1380249708);
  TlStoreString::store(token_, s);
}

void invokeWithReCaptchaPrefix::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1380249708);
  TlStoreString::store(token_, s);
}

void invokeWithReCaptchaPrefix::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invokeWithReCaptchaPrefix");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

invokeWithReCaptchaPrefix::ReturnType invokeWithReCaptchaPrefix::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<error>, -994444869>::parse(p);
#undef FAIL
}

messages_addPollAnswer::messages_addPollAnswer(object_ptr<InputPeer> &&peer_, int32 msg_id_, object_ptr<PollAnswer> &&answer_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , answer_(std::move(answer_))
{}

const std::int32_t messages_addPollAnswer::ID;

void messages_addPollAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(431770477);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(answer_, s);
}

void messages_addPollAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(431770477);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(answer_, s);
}

void messages_addPollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.addPollAnswer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_object_field("answer", static_cast<const BaseObject *>(answer_.get()));
    s.store_class_end();
  }
}

messages_addPollAnswer::ReturnType messages_addPollAnswer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_deleteTopicHistory::messages_deleteTopicHistory(object_ptr<InputPeer> &&peer_, int32 top_msg_id_)
  : peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
{}

const std::int32_t messages_deleteTopicHistory::ID;

void messages_deleteTopicHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-763269360);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(top_msg_id_, s);
}

void messages_deleteTopicHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-763269360);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(top_msg_id_, s);
}

void messages_deleteTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteTopicHistory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_msg_id", top_msg_id_);
    s.store_class_end();
  }
}

messages_deleteTopicHistory::ReturnType messages_deleteTopicHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_editChatCreator::messages_editChatCreator(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&user_id_, object_ptr<InputCheckPasswordSRP> &&password_)
  : peer_(std::move(peer_))
  , user_id_(std::move(user_id_))
  , password_(std::move(password_))
{}

const std::int32_t messages_editChatCreator::ID;

void messages_editChatCreator::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-146556841);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void messages_editChatCreator::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-146556841);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void messages_editChatCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatCreator");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

messages_editChatCreator::ReturnType messages_editChatCreator::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editFactCheck::messages_editFactCheck(object_ptr<InputPeer> &&peer_, int32 msg_id_, object_ptr<textWithEntities> &&text_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , text_(std::move(text_))
{}

const std::int32_t messages_editFactCheck::ID;

void messages_editFactCheck::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(92925557);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
}

void messages_editFactCheck::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(92925557);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
}

void messages_editFactCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editFactCheck");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

messages_editFactCheck::ReturnType messages_editFactCheck::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editForumTopic::messages_editForumTopic(int32 flags_, object_ptr<InputPeer> &&peer_, int32 topic_id_, string const &title_, int64 icon_emoji_id_, bool closed_, bool hidden_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , topic_id_(topic_id_)
  , title_(title_)
  , icon_emoji_id_(icon_emoji_id_)
  , closed_(closed_)
  , hidden_(hidden_)
{}

const std::int32_t messages_editForumTopic::ID;

void messages_editForumTopic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-825487052);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(topic_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBinary::store(icon_emoji_id_, s); }
  if (var0 & 4) { TlStoreBool::store(closed_, s); }
  if (var0 & 8) { TlStoreBool::store(hidden_, s); }
}

void messages_editForumTopic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-825487052);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(topic_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBinary::store(icon_emoji_id_, s); }
  if (var0 & 4) { TlStoreBool::store(closed_, s); }
  if (var0 & 8) { TlStoreBool::store(hidden_, s); }
}

void messages_editForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editForumTopic");
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 0)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("topic_id", topic_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("icon_emoji_id", icon_emoji_id_); }
    if (var0 & 4) { s.store_field("closed", closed_); }
    if (var0 & 8) { s.store_field("hidden", hidden_); }
    s.store_class_end();
  }
}

messages_editForumTopic::ReturnType messages_editForumTopic::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editWidgetData::messages_editWidgetData(int32 flags_, int64 widget_id_, string const &public_data_, int32 cache_time_)
  : flags_(flags_)
  , widget_id_(widget_id_)
  , public_data_(public_data_)
  , cache_time_(cache_time_)
{}

const std::int32_t messages_editWidgetData::ID;

void messages_editWidgetData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-356301888);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(widget_id_, s);
  TlStoreString::store(public_data_, s);
  if (var0 & 1) { TlStoreBinary::store(cache_time_, s); }
}

void messages_editWidgetData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-356301888);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(widget_id_, s);
  TlStoreString::store(public_data_, s);
  if (var0 & 1) { TlStoreBinary::store(cache_time_, s); }
}

void messages_editWidgetData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editWidgetData");
    s.store_field("flags", (var0 = flags_));
    s.store_field("widget_id", widget_id_);
    s.store_field("public_data", public_data_);
    if (var0 & 1) { s.store_field("cache_time", cache_time_); }
    s.store_class_end();
  }
}

messages_editWidgetData::ReturnType messages_editWidgetData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_faveSticker::messages_faveSticker(object_ptr<InputDocument> &&id_, bool unfave_)
  : id_(std::move(id_))
  , unfave_(unfave_)
{}

const std::int32_t messages_faveSticker::ID;

void messages_faveSticker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1174420133);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unfave_, s);
}

void messages_faveSticker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1174420133);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unfave_, s);
}

void messages_faveSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.faveSticker");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("unfave", unfave_);
    s.store_class_end();
  }
}

messages_faveSticker::ReturnType messages_faveSticker::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_getEmojiProfilePhotoGroups::messages_getEmojiProfilePhotoGroups(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getEmojiProfilePhotoGroups::ID;

void messages_getEmojiProfilePhotoGroups::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(564480243);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiProfilePhotoGroups::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(564480243);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiProfilePhotoGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiProfilePhotoGroups");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getEmojiProfilePhotoGroups::ReturnType messages_getEmojiProfilePhotoGroups::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_EmojiGroups>::parse(p);
#undef FAIL
}

messages_getFavedStickers::messages_getFavedStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getFavedStickers::ID;

void messages_getFavedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(82946729);
  TlStoreBinary::store(hash_, s);
}

void messages_getFavedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(82946729);
  TlStoreBinary::store(hash_, s);
}

void messages_getFavedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFavedStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getFavedStickers::ReturnType messages_getFavedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FavedStickers>::parse(p);
#undef FAIL
}

messages_getForumTopics::messages_getForumTopics(int32 flags_, object_ptr<InputPeer> &&peer_, string const &q_, int32 offset_date_, int32 offset_id_, int32 offset_topic_, int32 limit_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , q_(q_)
  , offset_date_(offset_date_)
  , offset_id_(offset_id_)
  , offset_topic_(offset_topic_)
  , limit_(limit_)
{}

const std::int32_t messages_getForumTopics::ID;

void messages_getForumTopics::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1000635391);
  TlStoreBinary::store((var0 = flags_ | ((!q_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_topic_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getForumTopics::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1000635391);
  TlStoreBinary::store((var0 = flags_ | ((!q_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_topic_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getForumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getForumTopics");
    s.store_field("flags", (var0 = flags_ | ((!q_.empty()) << 0)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("q", q_); }
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_id", offset_id_);
    s.store_field("offset_topic", offset_topic_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getForumTopics::ReturnType messages_getForumTopics::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_forumTopics>, 913709011>::parse(p);
#undef FAIL
}

messages_getFutureChatCreatorAfterLeave::messages_getFutureChatCreatorAfterLeave(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_getFutureChatCreatorAfterLeave::ID;

void messages_getFutureChatCreatorAfterLeave::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(998051494);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getFutureChatCreatorAfterLeave::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(998051494);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getFutureChatCreatorAfterLeave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFutureChatCreatorAfterLeave");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_getFutureChatCreatorAfterLeave::ReturnType messages_getFutureChatCreatorAfterLeave::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

messages_getReplies::messages_getReplies(object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 offset_id_, int32 offset_date_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_, int64 hash_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , offset_id_(offset_id_)
  , offset_date_(offset_date_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
  , hash_(hash_)
{}

const std::int32_t messages_getReplies::ID;

void messages_getReplies::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(584962828);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getReplies::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(584962828);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getReplies");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("offset_id", offset_id_);
    s.store_field("offset_date", offset_date_);
    s.store_field("add_offset", add_offset_);
    s.store_field("limit", limit_);
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getReplies::ReturnType messages_getReplies::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getSavedDialogs::messages_getSavedDialogs(int32 flags_, bool exclude_pinned_, object_ptr<InputPeer> &&parent_peer_, int32 offset_date_, int32 offset_id_, object_ptr<InputPeer> &&offset_peer_, int32 limit_, int64 hash_)
  : flags_(flags_)
  , exclude_pinned_(exclude_pinned_)
  , parent_peer_(std::move(parent_peer_))
  , offset_date_(offset_date_)
  , offset_id_(offset_id_)
  , offset_peer_(std::move(offset_peer_))
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getSavedDialogs::ID;

void messages_getSavedDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(512883865);
  TlStoreBinary::store((var0 = flags_ | (exclude_pinned_ << 0) | ((parent_peer_ != nullptr) << 1)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(512883865);
  TlStoreBinary::store((var0 = flags_ | (exclude_pinned_ << 0) | ((parent_peer_ != nullptr) << 1)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSavedDialogs");
    s.store_field("flags", (var0 = flags_ | (exclude_pinned_ << 0) | ((parent_peer_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("exclude_pinned", true); }
    if (var0 & 2) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_id", offset_id_);
    s.store_object_field("offset_peer", static_cast<const BaseObject *>(offset_peer_.get()));
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getSavedDialogs::ReturnType messages_getSavedDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SavedDialogs>::parse(p);
#undef FAIL
}

messages_getSearchResultsCalendar::messages_getSearchResultsCalendar(int32 flags_, object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&saved_peer_id_, object_ptr<MessagesFilter> &&filter_, int32 offset_id_, int32 offset_date_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , saved_peer_id_(std::move(saved_peer_id_))
  , filter_(std::move(filter_))
  , offset_id_(offset_id_)
  , offset_date_(offset_date_)
{}

const std::int32_t messages_getSearchResultsCalendar::ID;

void messages_getSearchResultsCalendar::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1789130429);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
}

void messages_getSearchResultsCalendar::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1789130429);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
}

void messages_getSearchResultsCalendar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSearchResultsCalendar");
    s.store_field("flags", (var0 = flags_ | ((saved_peer_id_ != nullptr) << 2)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 4) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("offset_date", offset_date_);
    s.store_class_end();
  }
}

messages_getSearchResultsCalendar::ReturnType messages_getSearchResultsCalendar::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_searchResultsCalendar>, 343859772>::parse(p);
#undef FAIL
}

messages_getShareThemeBackdrops::messages_getShareThemeBackdrops(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getShareThemeBackdrops::ID;

void messages_getShareThemeBackdrops::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-195453198);
  TlStoreBinary::store(hash_, s);
}

void messages_getShareThemeBackdrops::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-195453198);
  TlStoreBinary::store(hash_, s);
}

void messages_getShareThemeBackdrops::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getShareThemeBackdrops");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getShareThemeBackdrops::ReturnType messages_getShareThemeBackdrops::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<ShareThemeBackdrops>::parse(p);
#undef FAIL
}

messages_getUnreadMentions::messages_getUnreadMentions(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, int32 offset_id_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , offset_id_(offset_id_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
{}

const std::int32_t messages_getUnreadMentions::ID;

void messages_getUnreadMentions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-251140208);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadMentions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-251140208);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getUnreadMentions");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_field("offset_id", offset_id_);
    s.store_field("add_offset", add_offset_);
    s.store_field("limit", limit_);
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_class_end();
  }
}

messages_getUnreadMentions::ReturnType messages_getUnreadMentions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getUnreadPollVotes::messages_getUnreadPollVotes(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, int32 offset_id_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , offset_id_(offset_id_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
{}

const std::int32_t messages_getUnreadPollVotes::ID;

void messages_getUnreadPollVotes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1126722802);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadPollVotes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1126722802);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadPollVotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getUnreadPollVotes");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_field("offset_id", offset_id_);
    s.store_field("add_offset", add_offset_);
    s.store_field("limit", limit_);
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_class_end();
  }
}

messages_getUnreadPollVotes::ReturnType messages_getUnreadPollVotes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_importChatInvite::messages_importChatInvite(string const &hash_)
  : hash_(hash_)
{}

const std::int32_t messages_importChatInvite::ID;

void messages_importChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-560905362);
  TlStoreString::store(hash_, s);
}

void messages_importChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-560905362);
  TlStoreString::store(hash_, s);
}

void messages_importChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.importChatInvite");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_importChatInvite::ReturnType messages_importChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_ChatInviteJoinResult>::parse(p);
#undef FAIL
}

messages_readSavedHistory::messages_readSavedHistory(object_ptr<InputPeer> &&parent_peer_, object_ptr<InputPeer> &&peer_, int32 max_id_)
  : parent_peer_(std::move(parent_peer_))
  , peer_(std::move(peer_))
  , max_id_(max_id_)
{}

const std::int32_t messages_readSavedHistory::ID;

void messages_readSavedHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1169540261);
  TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void messages_readSavedHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1169540261);
  TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void messages_readSavedHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readSavedHistory");
    s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

messages_readSavedHistory::ReturnType messages_readSavedHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_reorderPinnedDialogs::messages_reorderPinnedDialogs(int32 flags_, bool force_, int32 folder_id_, array<object_ptr<InputDialogPeer>> &&order_)
  : flags_(flags_)
  , force_(force_)
  , folder_id_(folder_id_)
  , order_(std::move(order_))
{}

const std::int32_t messages_reorderPinnedDialogs::ID;

void messages_reorderPinnedDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(991616823);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBinary::store(folder_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void messages_reorderPinnedDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(991616823);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBinary::store(folder_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void messages_reorderPinnedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reorderPinnedDialogs");
    s.store_field("flags", (var0 = flags_ | (force_ << 0)));
    if (var0 & 1) { s.store_field("force", true); }
    s.store_field("folder_id", folder_id_);
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reorderPinnedDialogs::ReturnType messages_reorderPinnedDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_reportEncryptedSpam::messages_reportEncryptedSpam(object_ptr<inputEncryptedChat> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_reportEncryptedSpam::ID;

void messages_reportEncryptedSpam::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1259113487);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
}

void messages_reportEncryptedSpam::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1259113487);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
}

void messages_reportEncryptedSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportEncryptedSpam");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_reportEncryptedSpam::ReturnType messages_reportEncryptedSpam::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_reportReadMetrics::messages_reportReadMetrics(object_ptr<InputPeer> &&peer_, array<object_ptr<inputMessageReadMetric>> &&metrics_)
  : peer_(std::move(peer_))
  , metrics_(std::move(metrics_))
{}

const std::int32_t messages_reportReadMetrics::ID;

void messages_reportReadMetrics::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1080542694);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1076577429>>, 481674261>::store(metrics_, s);
}

void messages_reportReadMetrics::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1080542694);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1076577429>>, 481674261>::store(metrics_, s);
}

void messages_reportReadMetrics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportReadMetrics");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("metrics", metrics_.size()); for (const auto &_value : metrics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reportReadMetrics::ReturnType messages_reportReadMetrics::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_requestUrlAuth::messages_requestUrlAuth(int32 flags_, object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 button_id_, string const &url_, string const &in_app_origin_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , button_id_(button_id_)
  , url_(url_)
  , in_app_origin_(in_app_origin_)
{}

const std::int32_t messages_requestUrlAuth::ID;

void messages_requestUrlAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1991456356);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 1) | ((!url_.empty()) << 2) | ((!in_app_origin_.empty()) << 3)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 2) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreBinary::store(button_id_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  if (var0 & 8) { TlStoreString::store(in_app_origin_, s); }
}

void messages_requestUrlAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1991456356);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 1) | ((!url_.empty()) << 2) | ((!in_app_origin_.empty()) << 3)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 2) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreBinary::store(button_id_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  if (var0 & 8) { TlStoreString::store(in_app_origin_, s); }
}

void messages_requestUrlAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestUrlAuth");
    s.store_field("flags", (var0 = flags_ | ((peer_ != nullptr) << 1) | ((!url_.empty()) << 2) | ((!in_app_origin_.empty()) << 3)));
    if (var0 & 2) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 2) { s.store_field("msg_id", msg_id_); }
    if (var0 & 2) { s.store_field("button_id", button_id_); }
    if (var0 & 4) { s.store_field("url", url_); }
    if (var0 & 8) { s.store_field("in_app_origin", in_app_origin_); }
    s.store_class_end();
  }
}

messages_requestUrlAuth::ReturnType messages_requestUrlAuth::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<UrlAuthResult>::parse(p);
#undef FAIL
}

messages_toggleSuggestedPostApproval::messages_toggleSuggestedPostApproval(int32 flags_, bool reject_, object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 schedule_date_, string const &reject_comment_)
  : flags_(flags_)
  , reject_(reject_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , schedule_date_(schedule_date_)
  , reject_comment_(reject_comment_)
{}

const std::int32_t messages_toggleSuggestedPostApproval::ID;

void messages_toggleSuggestedPostApproval::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2130229924);
  TlStoreBinary::store((var0 = flags_ | (reject_ << 1) | ((!reject_comment_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 4) { TlStoreString::store(reject_comment_, s); }
}

void messages_toggleSuggestedPostApproval::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2130229924);
  TlStoreBinary::store((var0 = flags_ | (reject_ << 1) | ((!reject_comment_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 4) { TlStoreString::store(reject_comment_, s); }
}

void messages_toggleSuggestedPostApproval::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleSuggestedPostApproval");
    s.store_field("flags", (var0 = flags_ | (reject_ << 1) | ((!reject_comment_.empty()) << 2)));
    if (var0 & 2) { s.store_field("reject", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    if (var0 & 1) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 4) { s.store_field("reject_comment", reject_comment_); }
    s.store_class_end();
  }
}

messages_toggleSuggestedPostApproval::ReturnType messages_toggleSuggestedPostApproval::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_uploadImportedMedia::messages_uploadImportedMedia(object_ptr<InputPeer> &&peer_, int64 import_id_, string const &file_name_, object_ptr<InputMedia> &&media_)
  : peer_(std::move(peer_))
  , import_id_(import_id_)
  , file_name_(file_name_)
  , media_(std::move(media_))
{}

const std::int32_t messages_uploadImportedMedia::ID;

void messages_uploadImportedMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(713433234);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(import_id_, s);
  TlStoreString::store(file_name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_uploadImportedMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(713433234);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(import_id_, s);
  TlStoreString::store(file_name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_uploadImportedMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.uploadImportedMedia");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("import_id", import_id_);
    s.store_field("file_name", file_name_);
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

messages_uploadImportedMedia::ReturnType messages_uploadImportedMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<MessageMedia>::parse(p);
#undef FAIL
}

messages_uploadMedia::messages_uploadMedia(int32 flags_, string const &business_connection_id_, object_ptr<InputPeer> &&peer_, object_ptr<InputMedia> &&media_)
  : flags_(flags_)
  , business_connection_id_(business_connection_id_)
  , peer_(std::move(peer_))
  , media_(std::move(media_))
{}

const std::int32_t messages_uploadMedia::ID;

void messages_uploadMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(345405816);
  TlStoreBinary::store((var0 = flags_ | ((!business_connection_id_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(business_connection_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_uploadMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(345405816);
  TlStoreBinary::store((var0 = flags_ | ((!business_connection_id_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(business_connection_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_uploadMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.uploadMedia");
    s.store_field("flags", (var0 = flags_ | ((!business_connection_id_.empty()) << 0)));
    if (var0 & 1) { s.store_field("business_connection_id", business_connection_id_); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

messages_uploadMedia::ReturnType messages_uploadMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<MessageMedia>::parse(p);
#undef FAIL
}

payments_connectStarRefBot::payments_connectStarRefBot(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&bot_)
  : peer_(std::move(peer_))
  , bot_(std::move(bot_))
{}

const std::int32_t payments_connectStarRefBot::ID;

void payments_connectStarRefBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2127901834);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void payments_connectStarRefBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2127901834);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void payments_connectStarRefBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.connectStarRefBot");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

payments_connectStarRefBot::ReturnType payments_connectStarRefBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_connectedStarRefBots>, -1730811363>::parse(p);
#undef FAIL
}

payments_getStarGiftCollections::payments_getStarGiftCollections(object_ptr<InputPeer> &&peer_, int64 hash_)
  : peer_(std::move(peer_))
  , hash_(hash_)
{}

const std::int32_t payments_getStarGiftCollections::ID;

void payments_getStarGiftCollections::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1743023651);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGiftCollections::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1743023651);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGiftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftCollections");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

payments_getStarGiftCollections::ReturnType payments_getStarGiftCollections::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_StarGiftCollections>::parse(p);
#undef FAIL
}

payments_updateStarGiftCollection::payments_updateStarGiftCollection(int32 flags_, object_ptr<InputPeer> &&peer_, int32 collection_id_, string const &title_, array<object_ptr<InputSavedStarGift>> &&delete_stargift_, array<object_ptr<InputSavedStarGift>> &&add_stargift_, array<object_ptr<InputSavedStarGift>> &&order_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , collection_id_(collection_id_)
  , title_(title_)
  , delete_stargift_(std::move(delete_stargift_))
  , add_stargift_(std::move(add_stargift_))
  , order_(std::move(order_))
{}

const std::int32_t payments_updateStarGiftCollection::ID;

void payments_updateStarGiftCollection::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1339932391);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 0) | ((!delete_stargift_.empty()) << 1) | ((!add_stargift_.empty()) << 2) | ((!order_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(collection_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(delete_stargift_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(add_stargift_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s); }
}

void payments_updateStarGiftCollection::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1339932391);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 0) | ((!delete_stargift_.empty()) << 1) | ((!add_stargift_.empty()) << 2) | ((!order_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(collection_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(delete_stargift_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(add_stargift_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s); }
}

void payments_updateStarGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.updateStarGiftCollection");
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 0) | ((!delete_stargift_.empty()) << 1) | ((!add_stargift_.empty()) << 2) | ((!order_.empty()) << 3)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("collection_id", collection_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { { s.store_vector_begin("delete_stargift", delete_stargift_.size()); for (const auto &_value : delete_stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("add_stargift", add_stargift_.size()); for (const auto &_value : add_stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 8) { { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

payments_updateStarGiftCollection::ReturnType payments_updateStarGiftCollection::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<starGiftCollection>, -1653926992>::parse(p);
#undef FAIL
}

payments_withdrawStarGift::payments_withdrawStarGift(int32 flags_, bool keep_on_profile_, object_ptr<InputSavedStarGift> &&stargift_, bytes &&tmp_password_)
  : flags_(flags_)
  , keep_on_profile_(keep_on_profile_)
  , stargift_(std::move(stargift_))
  , tmp_password_(std::move(tmp_password_))
{}

const std::int32_t payments_withdrawStarGift::ID;

void payments_withdrawStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-333434706);
  TlStoreBinary::store((var0 = flags_ | (keep_on_profile_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreString::store(tmp_password_, s);
}

void payments_withdrawStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-333434706);
  TlStoreBinary::store((var0 = flags_ | (keep_on_profile_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreString::store(tmp_password_, s);
}

void payments_withdrawStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.withdrawStarGift");
    s.store_field("flags", (var0 = flags_ | (keep_on_profile_ << 0)));
    if (var0 & 1) { s.store_field("keep_on_profile", true); }
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_field("tmp_password", "[REDACTED]");
    s.store_class_end();
  }
}

payments_withdrawStarGift::ReturnType payments_withdrawStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_deleteConferenceCallParticipants::phone_deleteConferenceCallParticipants(int32 flags_, bool only_left_, bool kick_, object_ptr<InputGroupCall> &&call_, array<int64> &&ids_, bytes &&block_)
  : flags_(flags_)
  , only_left_(only_left_)
  , kick_(kick_)
  , call_(std::move(call_))
  , ids_(std::move(ids_))
  , block_(std::move(block_))
{}

const std::int32_t phone_deleteConferenceCallParticipants::ID;

void phone_deleteConferenceCallParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1935276763);
  TlStoreBinary::store((var0 = flags_ | (only_left_ << 0) | (kick_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(ids_, s);
  TlStoreString::store(block_, s);
}

void phone_deleteConferenceCallParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1935276763);
  TlStoreBinary::store((var0 = flags_ | (only_left_ << 0) | (kick_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(ids_, s);
  TlStoreString::store(block_, s);
}

void phone_deleteConferenceCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.deleteConferenceCallParticipants");
    s.store_field("flags", (var0 = flags_ | (only_left_ << 0) | (kick_ << 1)));
    if (var0 & 1) { s.store_field("only_left", true); }
    if (var0 & 2) { s.store_field("kick", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("ids", ids_.size()); for (const auto &_value : ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_bytes_field("block", block_);
    s.store_class_end();
  }
}

phone_deleteConferenceCallParticipants::ReturnType phone_deleteConferenceCallParticipants::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t phone_getCallConfig::ID;

void phone_getCallConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1430593449);
}

void phone_getCallConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1430593449);
}

void phone_getCallConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getCallConfig");
    s.store_class_end();
  }
}

phone_getCallConfig::ReturnType phone_getCallConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
#undef FAIL
}

phone_getGroupCall::phone_getGroupCall(object_ptr<InputGroupCall> &&call_, int32 limit_)
  : call_(std::move(call_))
  , limit_(limit_)
{}

const std::int32_t phone_getGroupCall::ID;

void phone_getGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(68699611);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(68699611);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

phone_getGroupCall::ReturnType phone_getGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_groupCall>, -1636664659>::parse(p);
#undef FAIL
}

phone_getGroupCallJoinAs::phone_getGroupCallJoinAs(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t phone_getGroupCallJoinAs::ID;

void phone_getGroupCallJoinAs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-277077702);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void phone_getGroupCallJoinAs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-277077702);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void phone_getGroupCallJoinAs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCallJoinAs");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

phone_getGroupCallJoinAs::ReturnType phone_getGroupCallJoinAs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_joinAsPeers>, -1343921601>::parse(p);
#undef FAIL
}

phone_joinGroupCall::phone_joinGroupCall(int32 flags_, bool muted_, bool video_stopped_, object_ptr<InputGroupCall> &&call_, object_ptr<InputPeer> &&join_as_, string const &invite_hash_, UInt256 const &public_key_, bytes &&block_, object_ptr<dataJSON> &&params_)
  : flags_(flags_)
  , muted_(muted_)
  , video_stopped_(video_stopped_)
  , call_(std::move(call_))
  , join_as_(std::move(join_as_))
  , invite_hash_(invite_hash_)
  , public_key_(public_key_)
  , block_(std::move(block_))
  , params_(std::move(params_))
{}

const std::int32_t phone_joinGroupCall::ID;

void phone_joinGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1883951017);
  TlStoreBinary::store((var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2) | ((!invite_hash_.empty()) << 1) | ((!block_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(join_as_, s);
  if (var0 & 2) { TlStoreString::store(invite_hash_, s); }
  if (var0 & 8) { TlStoreBinary::store(public_key_, s); }
  if (var0 & 8) { TlStoreString::store(block_, s); }
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void phone_joinGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1883951017);
  TlStoreBinary::store((var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2) | ((!invite_hash_.empty()) << 1) | ((!block_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(join_as_, s);
  if (var0 & 2) { TlStoreString::store(invite_hash_, s); }
  if (var0 & 8) { TlStoreBinary::store(public_key_, s); }
  if (var0 & 8) { TlStoreString::store(block_, s); }
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void phone_joinGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.joinGroupCall");
    s.store_field("flags", (var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2) | ((!invite_hash_.empty()) << 1) | ((!block_.empty()) << 3)));
    if (var0 & 1) { s.store_field("muted", true); }
    if (var0 & 4) { s.store_field("video_stopped", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("join_as", static_cast<const BaseObject *>(join_as_.get()));
    if (var0 & 2) { s.store_field("invite_hash", invite_hash_); }
    if (var0 & 8) { s.store_field("public_key", public_key_); }
    if (var0 & 8) { s.store_bytes_field("block", block_); }
    s.store_object_field("params", static_cast<const BaseObject *>(params_.get()));
    s.store_class_end();
  }
}

phone_joinGroupCall::ReturnType phone_joinGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_toggleGroupCallSettings::phone_toggleGroupCallSettings(int32 flags_, bool reset_invite_hash_, object_ptr<InputGroupCall> &&call_, bool join_muted_, bool messages_enabled_, int64 send_paid_messages_stars_)
  : flags_(flags_)
  , reset_invite_hash_(reset_invite_hash_)
  , call_(std::move(call_))
  , join_muted_(join_muted_)
  , messages_enabled_(messages_enabled_)
  , send_paid_messages_stars_(send_paid_messages_stars_)
{}

const std::int32_t phone_toggleGroupCallSettings::ID;

void phone_toggleGroupCallSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1757179150);
  TlStoreBinary::store((var0 = flags_ | (reset_invite_hash_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  if (var0 & 1) { TlStoreBool::store(join_muted_, s); }
  if (var0 & 4) { TlStoreBool::store(messages_enabled_, s); }
  if (var0 & 8) { TlStoreBinary::store(send_paid_messages_stars_, s); }
}

void phone_toggleGroupCallSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1757179150);
  TlStoreBinary::store((var0 = flags_ | (reset_invite_hash_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  if (var0 & 1) { TlStoreBool::store(join_muted_, s); }
  if (var0 & 4) { TlStoreBool::store(messages_enabled_, s); }
  if (var0 & 8) { TlStoreBinary::store(send_paid_messages_stars_, s); }
}

void phone_toggleGroupCallSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.toggleGroupCallSettings");
    s.store_field("flags", (var0 = flags_ | (reset_invite_hash_ << 1)));
    if (var0 & 2) { s.store_field("reset_invite_hash", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    if (var0 & 1) { s.store_field("join_muted", join_muted_); }
    if (var0 & 4) { s.store_field("messages_enabled", messages_enabled_); }
    if (var0 & 8) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    s.store_class_end();
  }
}

phone_toggleGroupCallSettings::ReturnType phone_toggleGroupCallSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

photos_updateProfilePhoto::photos_updateProfilePhoto(int32 flags_, bool fallback_, object_ptr<InputUser> &&bot_, object_ptr<InputPhoto> &&id_)
  : flags_(flags_)
  , fallback_(fallback_)
  , bot_(std::move(bot_))
  , id_(std::move(id_))
{}

const std::int32_t photos_updateProfilePhoto::ID;

void photos_updateProfilePhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(166207545);
  TlStoreBinary::store((var0 = flags_ | (fallback_ << 0) | ((bot_ != nullptr) << 1)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void photos_updateProfilePhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(166207545);
  TlStoreBinary::store((var0 = flags_ | (fallback_ << 0) | ((bot_ != nullptr) << 1)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void photos_updateProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.updateProfilePhoto");
    s.store_field("flags", (var0 = flags_ | (fallback_ << 0) | ((bot_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("fallback", true); }
    if (var0 & 2) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

photos_updateProfilePhoto::ReturnType photos_updateProfilePhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<photos_photo>, 539045032>::parse(p);
#undef FAIL
}

photos_uploadContactProfilePhoto::photos_uploadContactProfilePhoto(int32 flags_, bool suggest_, bool save_, object_ptr<InputUser> &&user_id_, object_ptr<InputFile> &&file_, object_ptr<InputFile> &&video_, double video_start_ts_, object_ptr<VideoSize> &&video_emoji_markup_)
  : flags_(flags_)
  , suggest_(suggest_)
  , save_(save_)
  , user_id_(std::move(user_id_))
  , file_(std::move(file_))
  , video_(std::move(video_))
  , video_start_ts_(video_start_ts_)
  , video_emoji_markup_(std::move(video_emoji_markup_))
{}

const std::int32_t photos_uploadContactProfilePhoto::ID;

void photos_uploadContactProfilePhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-515093903);
  TlStoreBinary::store((var0 = flags_ | (suggest_ << 3) | (save_ << 4) | ((file_ != nullptr) << 0) | ((video_ != nullptr) << 1) | ((video_emoji_markup_ != nullptr) << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void photos_uploadContactProfilePhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-515093903);
  TlStoreBinary::store((var0 = flags_ | (suggest_ << 3) | (save_ << 4) | ((file_ != nullptr) << 0) | ((video_ != nullptr) << 1) | ((video_emoji_markup_ != nullptr) << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void photos_uploadContactProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.uploadContactProfilePhoto");
    s.store_field("flags", (var0 = flags_ | (suggest_ << 3) | (save_ << 4) | ((file_ != nullptr) << 0) | ((video_ != nullptr) << 1) | ((video_emoji_markup_ != nullptr) << 5)));
    if (var0 & 8) { s.store_field("suggest", true); }
    if (var0 & 16) { s.store_field("save", true); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    if (var0 & 1) { s.store_object_field("file", static_cast<const BaseObject *>(file_.get())); }
    if (var0 & 2) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    if (var0 & 4) { s.store_field("video_start_ts", video_start_ts_); }
    if (var0 & 32) { s.store_object_field("video_emoji_markup", static_cast<const BaseObject *>(video_emoji_markup_.get())); }
    s.store_class_end();
  }
}

photos_uploadContactProfilePhoto::ReturnType photos_uploadContactProfilePhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<photos_photo>, 539045032>::parse(p);
#undef FAIL
}

stats_getMegagroupStats::stats_getMegagroupStats(int32 flags_, bool dark_, object_ptr<InputChannel> &&channel_)
  : flags_(flags_)
  , dark_(dark_)
  , channel_(std::move(channel_))
{}

const std::int32_t stats_getMegagroupStats::ID;

void stats_getMegagroupStats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-589330937);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void stats_getMegagroupStats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-589330937);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void stats_getMegagroupStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getMegagroupStats");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0)));
    if (var0 & 1) { s.store_field("dark", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

stats_getMegagroupStats::ReturnType stats_getMegagroupStats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_megagroupStats>, -276825834>::parse(p);
#undef FAIL
}

stats_getMessagePublicForwards::stats_getMessagePublicForwards(object_ptr<InputChannel> &&channel_, int32 msg_id_, string const &offset_, int32 limit_)
  : channel_(std::move(channel_))
  , msg_id_(msg_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stats_getMessagePublicForwards::ID;

void stats_getMessagePublicForwards::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1595212100);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stats_getMessagePublicForwards::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1595212100);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stats_getMessagePublicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getMessagePublicForwards");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stats_getMessagePublicForwards::ReturnType stats_getMessagePublicForwards::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_publicForwards>, -1828487648>::parse(p);
#undef FAIL
}

stickers_checkShortName::stickers_checkShortName(string const &short_name_)
  : short_name_(short_name_)
{}

const std::int32_t stickers_checkShortName::ID;

void stickers_checkShortName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(676017721);
  TlStoreString::store(short_name_, s);
}

void stickers_checkShortName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(676017721);
  TlStoreString::store(short_name_, s);
}

void stickers_checkShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.checkShortName");
    s.store_field("short_name", short_name_);
    s.store_class_end();
  }
}

stickers_checkShortName::ReturnType stickers_checkShortName::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stories_activateStealthMode::stories_activateStealthMode(int32 flags_, bool past_, bool future_)
  : flags_(flags_)
  , past_(past_)
  , future_(future_)
{}

const std::int32_t stories_activateStealthMode::ID;

void stories_activateStealthMode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1471926630);
  TlStoreBinary::store((var0 = flags_ | (past_ << 0) | (future_ << 1)), s);
}

void stories_activateStealthMode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1471926630);
  TlStoreBinary::store((var0 = flags_ | (past_ << 0) | (future_ << 1)), s);
}

void stories_activateStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.activateStealthMode");
    s.store_field("flags", (var0 = flags_ | (past_ << 0) | (future_ << 1)));
    if (var0 & 1) { s.store_field("past", true); }
    if (var0 & 2) { s.store_field("future", true); }
    s.store_class_end();
  }
}

stories_activateStealthMode::ReturnType stories_activateStealthMode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

stories_getStoriesArchive::stories_getStoriesArchive(object_ptr<InputPeer> &&peer_, int32 offset_id_, int32 limit_)
  : peer_(std::move(peer_))
  , offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t stories_getStoriesArchive::ID;

void stories_getStoriesArchive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1271586794);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getStoriesArchive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1271586794);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getStoriesArchive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getStoriesArchive");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_getStoriesArchive::ReturnType stories_getStoriesArchive::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_stories>, 1673780490>::parse(p);
#undef FAIL
}

stories_getStoriesViews::stories_getStoriesViews(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t stories_getStoriesViews::ID;

void stories_getStoriesViews::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(685862088);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_getStoriesViews::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(685862088);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_getStoriesViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getStoriesViews");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_getStoriesViews::ReturnType stories_getStoriesViews::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_storyViews>, -560009955>::parse(p);
#undef FAIL
}

stories_startLive::stories_startLive(int32 flags_, bool pinned_, bool noforwards_, bool rtmp_stream_, object_ptr<InputPeer> &&peer_, string const &caption_, array<object_ptr<MessageEntity>> &&entities_, array<object_ptr<InputPrivacyRule>> &&privacy_rules_, int64 random_id_, bool messages_enabled_, int64 send_paid_messages_stars_)
  : flags_(flags_)
  , pinned_(pinned_)
  , noforwards_(noforwards_)
  , rtmp_stream_(rtmp_stream_)
  , peer_(std::move(peer_))
  , caption_(caption_)
  , entities_(std::move(entities_))
  , privacy_rules_(std::move(privacy_rules_))
  , random_id_(random_id_)
  , messages_enabled_(messages_enabled_)
  , send_paid_messages_stars_(send_paid_messages_stars_)
{}

const std::int32_t stories_startLive::ID;

void stories_startLive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-798372642);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (rtmp_stream_ << 5) | ((!caption_.empty()) << 0) | ((!entities_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 64) { TlStoreBool::store(messages_enabled_, s); }
  if (var0 & 128) { TlStoreBinary::store(send_paid_messages_stars_, s); }
}

void stories_startLive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-798372642);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (rtmp_stream_ << 5) | ((!caption_.empty()) << 0) | ((!entities_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 64) { TlStoreBool::store(messages_enabled_, s); }
  if (var0 & 128) { TlStoreBinary::store(send_paid_messages_stars_, s); }
}

void stories_startLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.startLive");
    s.store_field("flags", (var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (rtmp_stream_ << 5) | ((!caption_.empty()) << 0) | ((!entities_.empty()) << 1)));
    if (var0 & 4) { s.store_field("pinned", true); }
    if (var0 & 16) { s.store_field("noforwards", true); }
    if (var0 & 32) { s.store_field("rtmp_stream", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("caption", caption_); }
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("privacy_rules", privacy_rules_.size()); for (const auto &_value : privacy_rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("random_id", random_id_);
    if (var0 & 64) { s.store_field("messages_enabled", messages_enabled_); }
    if (var0 & 128) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    s.store_class_end();
  }
}

stories_startLive::ReturnType stories_startLive::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

users_getRequirementsToContact::users_getRequirementsToContact(array<object_ptr<InputUser>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t users_getRequirementsToContact::ID;

void users_getRequirementsToContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-660962397);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void users_getRequirementsToContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-660962397);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void users_getRequirementsToContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.getRequirementsToContact");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

users_getRequirementsToContact::ReturnType users_getRequirementsToContact::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<RequirementToContact>>, 481674261>::parse(p);
#undef FAIL
}

wallet_getTransactionsByIDs::wallet_getTransactionsByIDs(array<string> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t wallet_getTransactionsByIDs::ID;

void wallet_getTransactionsByIDs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2128811338);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(id_, s);
}

void wallet_getTransactionsByIDs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2128811338);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(id_, s);
}

void wallet_getTransactionsByIDs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.getTransactionsByIDs");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

wallet_getTransactionsByIDs::ReturnType wallet_getTransactionsByIDs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_transactions>, 1126356389>::parse(p);
#undef FAIL
}

wallet_tonConnectCloseSession::wallet_tonConnectCloseSession(int32 flags_, int64 session_id_, bytes &&body_)
  : flags_(flags_)
  , session_id_(session_id_)
  , body_(std::move(body_))
{}

const std::int32_t wallet_tonConnectCloseSession::ID;

void wallet_tonConnectCloseSession::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-700489266);
  TlStoreBinary::store((var0 = flags_ | ((!body_.empty()) << 0)), s);
  TlStoreBinary::store(session_id_, s);
  if (var0 & 1) { TlStoreString::store(body_, s); }
}

void wallet_tonConnectCloseSession::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-700489266);
  TlStoreBinary::store((var0 = flags_ | ((!body_.empty()) << 0)), s);
  TlStoreBinary::store(session_id_, s);
  if (var0 & 1) { TlStoreString::store(body_, s); }
}

void wallet_tonConnectCloseSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectCloseSession");
    s.store_field("flags", (var0 = flags_ | ((!body_.empty()) << 0)));
    s.store_field("session_id", session_id_);
    if (var0 & 1) { s.store_bytes_field("body", body_); }
    s.store_class_end();
  }
}

wallet_tonConnectCloseSession::ReturnType wallet_tonConnectCloseSession::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
