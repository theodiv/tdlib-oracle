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


const std::int32_t aiComposeToneExample::ID;

object_ptr<aiComposeToneExample> aiComposeToneExample::fetch(TlBufferParser &p) {
  return make_tl_object<aiComposeToneExample>(p);
}

aiComposeToneExample::aiComposeToneExample(TlBufferParser &p)
  : from_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
  , to_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
{}

void aiComposeToneExample::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aiComposeToneExample");
    s.store_object_field("from", static_cast<const BaseObject *>(from_.get()));
    s.store_object_field("to", static_cast<const BaseObject *>(to_.get()));
    s.store_class_end();
  }
}

const std::int32_t attachMenuBotIconColor::ID;

object_ptr<attachMenuBotIconColor> attachMenuBotIconColor::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuBotIconColor>(p);
}

attachMenuBotIconColor::attachMenuBotIconColor(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
  , color_(TlFetchInt::parse(p))
{}

void attachMenuBotIconColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBotIconColor");
    s.store_field("name", name_);
    s.store_field("color", color_);
    s.store_class_end();
  }
}

object_ptr<AttachMenuBots> AttachMenuBots::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case attachMenuBotsNotModified::ID:
      return attachMenuBotsNotModified::fetch(p);
    case attachMenuBots::ID:
      return attachMenuBots::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t attachMenuBotsNotModified::ID;

object_ptr<AttachMenuBots> attachMenuBotsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuBotsNotModified>();
}

void attachMenuBotsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBotsNotModified");
    s.store_class_end();
  }
}

const std::int32_t attachMenuBots::ID;

object_ptr<AttachMenuBots> attachMenuBots::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuBots>(p);
}

attachMenuBots::attachMenuBots(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , bots_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<attachMenuBot>, -653423106>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void attachMenuBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBots");
    s.store_field("hash", hash_);
    { s.store_vector_begin("bots", bots_.size()); for (const auto &_value : bots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

birthday::birthday()
  : flags_()
  , day_()
  , month_()
  , year_()
{}

birthday::birthday(int32 flags_, int32 day_, int32 month_, int32 year_)
  : flags_(flags_)
  , day_(day_)
  , month_(month_)
  , year_(year_)
{}

const std::int32_t birthday::ID;

object_ptr<birthday> birthday::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<birthday> res = make_tl_object<birthday>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->day_ = TlFetchInt::parse(p);
  res->month_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->year_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void birthday::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(day_, s);
  TlStoreBinary::store(month_, s);
  if (var0 & 1) { TlStoreBinary::store(year_, s); }
}

void birthday::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(day_, s);
  TlStoreBinary::store(month_, s);
  if (var0 & 1) { TlStoreBinary::store(year_, s); }
}

void birthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "birthday");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("day", day_);
    s.store_field("month", month_);
    if (var0 & 1) { s.store_field("year", year_); }
    s.store_class_end();
  }
}

businessChatLink::businessChatLink()
  : flags_()
  , link_()
  , message_()
  , entities_()
  , title_()
  , views_()
{}

const std::int32_t businessChatLink::ID;

object_ptr<businessChatLink> businessChatLink::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessChatLink> res = make_tl_object<businessChatLink>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->link_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 2) { res->title_ = TlFetchString<string>::parse(p); }
  res->views_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessChatLink");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!entities_.empty()) << 0) | ((!title_.empty()) << 1)));
    s.store_field("link", link_);
    s.store_field("message", message_);
    if (var0 & 1) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("title", title_); }
    s.store_field("views", views_);
    s.store_class_end();
  }
}

businessLocation::businessLocation()
  : flags_()
  , geo_point_()
  , address_()
{}

const std::int32_t businessLocation::ID;

object_ptr<businessLocation> businessLocation::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessLocation> res = make_tl_object<businessLocation>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->geo_point_ = TlFetchObject<GeoPoint>::parse(p); }
  res->address_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessLocation");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((geo_point_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get())); }
    s.store_field("address", address_);
    s.store_class_end();
  }
}

businessWeeklyOpen::businessWeeklyOpen(int32 start_minute_, int32 end_minute_)
  : start_minute_(start_minute_)
  , end_minute_(end_minute_)
{}

const std::int32_t businessWeeklyOpen::ID;

object_ptr<businessWeeklyOpen> businessWeeklyOpen::fetch(TlBufferParser &p) {
  return make_tl_object<businessWeeklyOpen>(p);
}

businessWeeklyOpen::businessWeeklyOpen(TlBufferParser &p)
  : start_minute_(TlFetchInt::parse(p))
  , end_minute_(TlFetchInt::parse(p))
{}

void businessWeeklyOpen::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(start_minute_, s);
  TlStoreBinary::store(end_minute_, s);
}

void businessWeeklyOpen::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(start_minute_, s);
  TlStoreBinary::store(end_minute_, s);
}

void businessWeeklyOpen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessWeeklyOpen");
    s.store_field("start_minute", start_minute_);
    s.store_field("end_minute", end_minute_);
    s.store_class_end();
  }
}

object_ptr<ButtonType> ButtonType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case buttonTypeDefault::ID:
      return buttonTypeDefault::fetch(p);
    case buttonTypeRequestPhone::ID:
      return buttonTypeRequestPhone::fetch(p);
    case buttonTypeRequestGeoLocation::ID:
      return buttonTypeRequestGeoLocation::fetch(p);
    case buttonTypeRequestPoll::ID:
      return buttonTypeRequestPoll::fetch(p);
    case buttonTypeRequestPeer::ID:
      return buttonTypeRequestPeer::fetch(p);
    case inputButtonTypeRequestPeer::ID:
      return inputButtonTypeRequestPeer::fetch(p);
    case buttonTypeSimpleWebView::ID:
      return buttonTypeSimpleWebView::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t buttonTypeDefault::ID;

object_ptr<ButtonType> buttonTypeDefault::fetch(TlBufferParser &p) {
  return make_tl_object<buttonTypeDefault>();
}

void buttonTypeDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void buttonTypeDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void buttonTypeDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonTypeDefault");
    s.store_class_end();
  }
}

const std::int32_t buttonTypeRequestPhone::ID;

object_ptr<ButtonType> buttonTypeRequestPhone::fetch(TlBufferParser &p) {
  return make_tl_object<buttonTypeRequestPhone>();
}

void buttonTypeRequestPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void buttonTypeRequestPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void buttonTypeRequestPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonTypeRequestPhone");
    s.store_class_end();
  }
}

const std::int32_t buttonTypeRequestGeoLocation::ID;

object_ptr<ButtonType> buttonTypeRequestGeoLocation::fetch(TlBufferParser &p) {
  return make_tl_object<buttonTypeRequestGeoLocation>();
}

void buttonTypeRequestGeoLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void buttonTypeRequestGeoLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void buttonTypeRequestGeoLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonTypeRequestGeoLocation");
    s.store_class_end();
  }
}

buttonTypeRequestPoll::buttonTypeRequestPoll()
  : flags_()
  , quiz_()
{}

buttonTypeRequestPoll::buttonTypeRequestPoll(int32 flags_, bool quiz_)
  : flags_(flags_)
  , quiz_(quiz_)
{}

const std::int32_t buttonTypeRequestPoll::ID;

object_ptr<ButtonType> buttonTypeRequestPoll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<buttonTypeRequestPoll> res = make_tl_object<buttonTypeRequestPoll>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->quiz_ = TlFetchBool::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void buttonTypeRequestPoll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBool::store(quiz_, s); }
}

void buttonTypeRequestPoll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBool::store(quiz_, s); }
}

void buttonTypeRequestPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonTypeRequestPoll");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("quiz", quiz_); }
    s.store_class_end();
  }
}

buttonTypeRequestPeer::buttonTypeRequestPeer()
  : flags_()
  , button_id_()
  , peer_type_()
  , max_quantity_()
{}

buttonTypeRequestPeer::buttonTypeRequestPeer(int32 flags_, int32 button_id_, object_ptr<RequestPeerType> &&peer_type_, int32 max_quantity_)
  : flags_(flags_)
  , button_id_(button_id_)
  , peer_type_(std::move(peer_type_))
  , max_quantity_(max_quantity_)
{}

const std::int32_t buttonTypeRequestPeer::ID;

object_ptr<ButtonType> buttonTypeRequestPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<buttonTypeRequestPeer> res = make_tl_object<buttonTypeRequestPeer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->button_id_ = TlFetchInt::parse(p);
  res->peer_type_ = TlFetchObject<RequestPeerType>::parse(p);
  res->max_quantity_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void buttonTypeRequestPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_type_, s);
  TlStoreBinary::store(max_quantity_, s);
}

void buttonTypeRequestPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_type_, s);
  TlStoreBinary::store(max_quantity_, s);
}

void buttonTypeRequestPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonTypeRequestPeer");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("button_id", button_id_);
    s.store_object_field("peer_type", static_cast<const BaseObject *>(peer_type_.get()));
    s.store_field("max_quantity", max_quantity_);
    s.store_class_end();
  }
}

inputButtonTypeRequestPeer::inputButtonTypeRequestPeer()
  : flags_()
  , name_requested_()
  , username_requested_()
  , photo_requested_()
  , button_id_()
  , peer_type_()
  , max_quantity_()
{}

inputButtonTypeRequestPeer::inputButtonTypeRequestPeer(int32 flags_, bool name_requested_, bool username_requested_, bool photo_requested_, int32 button_id_, object_ptr<RequestPeerType> &&peer_type_, int32 max_quantity_)
  : flags_(flags_)
  , name_requested_(name_requested_)
  , username_requested_(username_requested_)
  , photo_requested_(photo_requested_)
  , button_id_(button_id_)
  , peer_type_(std::move(peer_type_))
  , max_quantity_(max_quantity_)
{}

const std::int32_t inputButtonTypeRequestPeer::ID;

object_ptr<ButtonType> inputButtonTypeRequestPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputButtonTypeRequestPeer> res = make_tl_object<inputButtonTypeRequestPeer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->name_requested_ = (var0 & 1) != 0;
  res->username_requested_ = (var0 & 2) != 0;
  res->photo_requested_ = (var0 & 4) != 0;
  res->button_id_ = TlFetchInt::parse(p);
  res->peer_type_ = TlFetchObject<RequestPeerType>::parse(p);
  res->max_quantity_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputButtonTypeRequestPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (name_requested_ << 0) | (username_requested_ << 1) | (photo_requested_ << 2)), s);
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_type_, s);
  TlStoreBinary::store(max_quantity_, s);
}

void inputButtonTypeRequestPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (name_requested_ << 0) | (username_requested_ << 1) | (photo_requested_ << 2)), s);
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_type_, s);
  TlStoreBinary::store(max_quantity_, s);
}

void inputButtonTypeRequestPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputButtonTypeRequestPeer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (name_requested_ << 0) | (username_requested_ << 1) | (photo_requested_ << 2)));
    if (var0 & 1) { s.store_field("name_requested", true); }
    if (var0 & 2) { s.store_field("username_requested", true); }
    if (var0 & 4) { s.store_field("photo_requested", true); }
    s.store_field("button_id", button_id_);
    s.store_object_field("peer_type", static_cast<const BaseObject *>(peer_type_.get()));
    s.store_field("max_quantity", max_quantity_);
    s.store_class_end();
  }
}

buttonTypeSimpleWebView::buttonTypeSimpleWebView(string const &url_)
  : url_(url_)
{}

const std::int32_t buttonTypeSimpleWebView::ID;

object_ptr<ButtonType> buttonTypeSimpleWebView::fetch(TlBufferParser &p) {
  return make_tl_object<buttonTypeSimpleWebView>(p);
}

buttonTypeSimpleWebView::buttonTypeSimpleWebView(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void buttonTypeSimpleWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
}

void buttonTypeSimpleWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
}

void buttonTypeSimpleWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonTypeSimpleWebView");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

object_ptr<ChannelLocation> ChannelLocation::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case channelLocationEmpty::ID:
      return channelLocationEmpty::fetch(p);
    case channelLocation::ID:
      return channelLocation::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t channelLocationEmpty::ID;

object_ptr<ChannelLocation> channelLocationEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<channelLocationEmpty>();
}

void channelLocationEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelLocationEmpty");
    s.store_class_end();
  }
}

const std::int32_t channelLocation::ID;

object_ptr<ChannelLocation> channelLocation::fetch(TlBufferParser &p) {
  return make_tl_object<channelLocation>(p);
}

channelLocation::channelLocation(TlBufferParser &p)
  : geo_point_(TlFetchObject<GeoPoint>::parse(p))
  , address_(TlFetchString<string>::parse(p))
{}

void channelLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelLocation");
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_field("address", address_);
    s.store_class_end();
  }
}

const std::int32_t chatAdminWithInvites::ID;

object_ptr<chatAdminWithInvites> chatAdminWithInvites::fetch(TlBufferParser &p) {
  return make_tl_object<chatAdminWithInvites>(p);
}

chatAdminWithInvites::chatAdminWithInvites(TlBufferParser &p)
  : admin_id_(TlFetchLong::parse(p))
  , invites_count_(TlFetchInt::parse(p))
  , revoked_invites_count_(TlFetchInt::parse(p))
{}

void chatAdminWithInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdminWithInvites");
    s.store_field("admin_id", admin_id_);
    s.store_field("invites_count", invites_count_);
    s.store_field("revoked_invites_count", revoked_invites_count_);
    s.store_class_end();
  }
}

object_ptr<ChatReactions> ChatReactions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatReactionsNone::ID:
      return chatReactionsNone::fetch(p);
    case chatReactionsAll::ID:
      return chatReactionsAll::fetch(p);
    case chatReactionsSome::ID:
      return chatReactionsSome::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t chatReactionsNone::ID;

object_ptr<ChatReactions> chatReactionsNone::fetch(TlBufferParser &p) {
  return make_tl_object<chatReactionsNone>();
}

void chatReactionsNone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void chatReactionsNone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void chatReactionsNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReactionsNone");
    s.store_class_end();
  }
}

chatReactionsAll::chatReactionsAll()
  : flags_()
  , allow_custom_()
{}

chatReactionsAll::chatReactionsAll(int32 flags_, bool allow_custom_)
  : flags_(flags_)
  , allow_custom_(allow_custom_)
{}

const std::int32_t chatReactionsAll::ID;

object_ptr<ChatReactions> chatReactionsAll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatReactionsAll> res = make_tl_object<chatReactionsAll>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->allow_custom_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatReactionsAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_custom_ << 0)), s);
}

void chatReactionsAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_custom_ << 0)), s);
}

void chatReactionsAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReactionsAll");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (allow_custom_ << 0)));
    if (var0 & 1) { s.store_field("allow_custom", true); }
    s.store_class_end();
  }
}

chatReactionsSome::chatReactionsSome(array<object_ptr<Reaction>> &&reactions_)
  : reactions_(std::move(reactions_))
{}

const std::int32_t chatReactionsSome::ID;

object_ptr<ChatReactions> chatReactionsSome::fetch(TlBufferParser &p) {
  return make_tl_object<chatReactionsSome>(p);
}

chatReactionsSome::chatReactionsSome(TlBufferParser &p)
  : reactions_(TlFetchBoxed<TlFetchVector<TlFetchObject<Reaction>>, 481674261>::parse(p))
{}

void chatReactionsSome::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(reactions_, s);
}

void chatReactionsSome::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(reactions_, s);
}

void chatReactionsSome::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReactionsSome");
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

connectedBotStarRef::connectedBotStarRef()
  : flags_()
  , revoked_()
  , url_()
  , date_()
  , bot_id_()
  , commission_permille_()
  , duration_months_()
  , participants_()
  , revenue_()
{}

const std::int32_t connectedBotStarRef::ID;

object_ptr<connectedBotStarRef> connectedBotStarRef::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<connectedBotStarRef> res = make_tl_object<connectedBotStarRef>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->revoked_ = (var0 & 2) != 0;
  res->url_ = TlFetchString<string>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->bot_id_ = TlFetchLong::parse(p);
  res->commission_permille_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->duration_months_ = TlFetchInt::parse(p); }
  res->participants_ = TlFetchLong::parse(p);
  res->revenue_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void connectedBotStarRef::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedBotStarRef");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (revoked_ << 1)));
    if (var0 & 2) { s.store_field("revoked", true); }
    s.store_field("url", url_);
    s.store_field("date", date_);
    s.store_field("bot_id", bot_id_);
    s.store_field("commission_permille", commission_permille_);
    if (var0 & 1) { s.store_field("duration_months", duration_months_); }
    s.store_field("participants", participants_);
    s.store_field("revenue", revenue_);
    s.store_class_end();
  }
}

const std::int32_t contact::ID;

object_ptr<contact> contact::fetch(TlBufferParser &p) {
  return make_tl_object<contact>(p);
}

contact::contact(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , mutual_(TlFetchBool::parse(p))
{}

void contact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contact");
    s.store_field("user_id", user_id_);
    s.store_field("mutual", mutual_);
    s.store_class_end();
  }
}

const std::int32_t currencyRate::ID;

object_ptr<currencyRate> currencyRate::fetch(TlBufferParser &p) {
  return make_tl_object<currencyRate>(p);
}

currencyRate::currencyRate(TlBufferParser &p)
  : currency_(TlFetchString<string>::parse(p))
  , rate_(TlFetchDouble::parse(p))
{}

void currencyRate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "currencyRate");
    s.store_field("currency", currency_);
    s.store_field("rate", rate_);
    s.store_class_end();
  }
}

object_ptr<Document> Document::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case documentEmpty::ID:
      return documentEmpty::fetch(p);
    case document::ID:
      return document::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

documentEmpty::documentEmpty(int64 id_)
  : id_(id_)
{}

const std::int32_t documentEmpty::ID;

object_ptr<Document> documentEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<documentEmpty>(p);
}

documentEmpty::documentEmpty(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void documentEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void documentEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void documentEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

document::document()
  : flags_()
  , id_()
  , access_hash_()
  , file_reference_()
  , date_()
  , mime_type_()
  , size_()
  , thumbs_()
  , video_thumbs_()
  , dc_id_()
  , attributes_()
{}

document::document(int32 flags_, int64 id_, int64 access_hash_, bytes &&file_reference_, int32 date_, string const &mime_type_, int64 size_, array<object_ptr<PhotoSize>> &&thumbs_, array<object_ptr<VideoSize>> &&video_thumbs_, int32 dc_id_, array<object_ptr<DocumentAttribute>> &&attributes_)
  : flags_(flags_)
  , id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
  , date_(date_)
  , mime_type_(mime_type_)
  , size_(size_)
  , thumbs_(std::move(thumbs_))
  , video_thumbs_(std::move(video_thumbs_))
  , dc_id_(dc_id_)
  , attributes_(std::move(attributes_))
{}

const std::int32_t document::ID;

object_ptr<Document> document::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<document> res = make_tl_object<document>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->file_reference_ = TlFetchBytes<bytes>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->mime_type_ = TlFetchString<string>::parse(p);
  res->size_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->thumbs_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PhotoSize>>, 481674261>::parse(p); }
  if (var0 & 2) { res->video_thumbs_ = TlFetchBoxed<TlFetchVector<TlFetchObject<VideoSize>>, 481674261>::parse(p); }
  res->dc_id_ = TlFetchInt::parse(p);
  res->attributes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<DocumentAttribute>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void document::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!thumbs_.empty()) << 0) | ((!video_thumbs_.empty()) << 1)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(date_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBinary::store(size_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(thumbs_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(video_thumbs_, s); }
  TlStoreBinary::store(dc_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void document::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!thumbs_.empty()) << 0) | ((!video_thumbs_.empty()) << 1)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(date_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBinary::store(size_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(thumbs_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(video_thumbs_, s); }
  TlStoreBinary::store(dc_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void document::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "document");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!thumbs_.empty()) << 0) | ((!video_thumbs_.empty()) << 1)));
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_field("date", date_);
    s.store_field("mime_type", mime_type_);
    s.store_field("size", size_);
    if (var0 & 1) { { s.store_vector_begin("thumbs", thumbs_.size()); for (const auto &_value : thumbs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { { s.store_vector_begin("video_thumbs", video_thumbs_.size()); for (const auto &_value : video_thumbs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("dc_id", dc_id_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<EmojiGroup> EmojiGroup::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case emojiGroup::ID:
      return emojiGroup::fetch(p);
    case emojiGroupGreeting::ID:
      return emojiGroupGreeting::fetch(p);
    case emojiGroupPremium::ID:
      return emojiGroupPremium::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t emojiGroup::ID;

object_ptr<EmojiGroup> emojiGroup::fetch(TlBufferParser &p) {
  return make_tl_object<emojiGroup>(p);
}

emojiGroup::emojiGroup(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , icon_emoji_id_(TlFetchLong::parse(p))
  , emoticons_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void emojiGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiGroup");
    s.store_field("title", title_);
    s.store_field("icon_emoji_id", icon_emoji_id_);
    { s.store_vector_begin("emoticons", emoticons_.size()); for (const auto &_value : emoticons_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t emojiGroupGreeting::ID;

object_ptr<EmojiGroup> emojiGroupGreeting::fetch(TlBufferParser &p) {
  return make_tl_object<emojiGroupGreeting>(p);
}

emojiGroupGreeting::emojiGroupGreeting(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , icon_emoji_id_(TlFetchLong::parse(p))
  , emoticons_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void emojiGroupGreeting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiGroupGreeting");
    s.store_field("title", title_);
    s.store_field("icon_emoji_id", icon_emoji_id_);
    { s.store_vector_begin("emoticons", emoticons_.size()); for (const auto &_value : emoticons_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t emojiGroupPremium::ID;

object_ptr<EmojiGroup> emojiGroupPremium::fetch(TlBufferParser &p) {
  return make_tl_object<emojiGroupPremium>(p);
}

emojiGroupPremium::emojiGroupPremium(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , icon_emoji_id_(TlFetchLong::parse(p))
{}

void emojiGroupPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiGroupPremium");
    s.store_field("title", title_);
    s.store_field("icon_emoji_id", icon_emoji_id_);
    s.store_class_end();
  }
}

object_ptr<ExportedChatInvite> ExportedChatInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatInviteExported::ID:
      return chatInviteExported::fetch(p);
    case chatInvitePublicJoinRequests::ID:
      return chatInvitePublicJoinRequests::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

chatInviteExported::chatInviteExported()
  : flags_()
  , revoked_()
  , permanent_()
  , request_needed_()
  , link_()
  , admin_id_()
  , date_()
  , start_date_()
  , expire_date_()
  , usage_limit_()
  , usage_()
  , requested_()
  , subscription_expired_()
  , title_()
  , subscription_pricing_()
{}

const std::int32_t chatInviteExported::ID;

object_ptr<ExportedChatInvite> chatInviteExported::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatInviteExported> res = make_tl_object<chatInviteExported>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->revoked_ = (var0 & 1) != 0;
  res->permanent_ = (var0 & 32) != 0;
  res->request_needed_ = (var0 & 64) != 0;
  res->link_ = TlFetchString<string>::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 16) { res->start_date_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->expire_date_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->usage_limit_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->usage_ = TlFetchInt::parse(p); }
  if (var0 & 128) { res->requested_ = TlFetchInt::parse(p); }
  if (var0 & 1024) { res->subscription_expired_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 512) { res->subscription_pricing_ = TlFetchBoxed<TlFetchObject<starsSubscriptionPricing>, 88173912>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatInviteExported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteExported");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (revoked_ << 0) | (permanent_ << 5) | (request_needed_ << 6) | ((!title_.empty()) << 8) | ((subscription_pricing_ != nullptr) << 9)));
    if (var0 & 1) { s.store_field("revoked", true); }
    if (var0 & 32) { s.store_field("permanent", true); }
    if (var0 & 64) { s.store_field("request_needed", true); }
    s.store_field("link", link_);
    s.store_field("admin_id", admin_id_);
    s.store_field("date", date_);
    if (var0 & 16) { s.store_field("start_date", start_date_); }
    if (var0 & 2) { s.store_field("expire_date", expire_date_); }
    if (var0 & 4) { s.store_field("usage_limit", usage_limit_); }
    if (var0 & 8) { s.store_field("usage", usage_); }
    if (var0 & 128) { s.store_field("requested", requested_); }
    if (var0 & 1024) { s.store_field("subscription_expired", subscription_expired_); }
    if (var0 & 256) { s.store_field("title", title_); }
    if (var0 & 512) { s.store_object_field("subscription_pricing", static_cast<const BaseObject *>(subscription_pricing_.get())); }
    s.store_class_end();
  }
}

const std::int32_t chatInvitePublicJoinRequests::ID;

object_ptr<ExportedChatInvite> chatInvitePublicJoinRequests::fetch(TlBufferParser &p) {
  return make_tl_object<chatInvitePublicJoinRequests>();
}

void chatInvitePublicJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInvitePublicJoinRequests");
    s.store_class_end();
  }
}

const std::int32_t exportedStoryLink::ID;

object_ptr<exportedStoryLink> exportedStoryLink::fetch(TlBufferParser &p) {
  return make_tl_object<exportedStoryLink>(p);
}

exportedStoryLink::exportedStoryLink(TlBufferParser &p)
  : link_(TlFetchString<string>::parse(p))
{}

void exportedStoryLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "exportedStoryLink");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

const std::int32_t groupCallParticipantVideoSourceGroup::ID;

object_ptr<groupCallParticipantVideoSourceGroup> groupCallParticipantVideoSourceGroup::fetch(TlBufferParser &p) {
  return make_tl_object<groupCallParticipantVideoSourceGroup>(p);
}

groupCallParticipantVideoSourceGroup::groupCallParticipantVideoSourceGroup(TlBufferParser &p)
  : semantics_(TlFetchString<string>::parse(p))
  , sources_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void groupCallParticipantVideoSourceGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipantVideoSourceGroup");
    s.store_field("semantics", semantics_);
    { s.store_vector_begin("sources", sources_.size()); for (const auto &_value : sources_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputCollectibleUsername::inputCollectibleUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t inputCollectibleUsername::ID;

void inputCollectibleUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(username_, s);
}

void inputCollectibleUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(username_, s);
}

void inputCollectibleUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCollectibleUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

inputCollectiblePhone::inputCollectiblePhone(string const &phone_)
  : phone_(phone_)
{}

const std::int32_t inputCollectiblePhone::ID;

void inputCollectiblePhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_, s);
}

void inputCollectiblePhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_, s);
}

void inputCollectiblePhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCollectiblePhone");
    s.store_field("phone", phone_);
    s.store_class_end();
  }
}

inputEncryptedChat::inputEncryptedChat(int32 chat_id_, int64 access_hash_)
  : chat_id_(chat_id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputEncryptedChat::ID;

void inputEncryptedChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

object_ptr<InputGame> InputGame::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputGameID::ID:
      return inputGameID::fetch(p);
    case inputGameShortName::ID:
      return inputGameShortName::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputGameID::inputGameID(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputGameID::ID;

object_ptr<InputGame> inputGameID::fetch(TlBufferParser &p) {
  return make_tl_object<inputGameID>(p);
}

inputGameID::inputGameID(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputGameID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputGameID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputGameID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGameID");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputGameShortName::inputGameShortName(object_ptr<InputUser> &&bot_id_, string const &short_name_)
  : bot_id_(std::move(bot_id_))
  , short_name_(short_name_)
{}

const std::int32_t inputGameShortName::ID;

object_ptr<InputGame> inputGameShortName::fetch(TlBufferParser &p) {
  return make_tl_object<inputGameShortName>(p);
}

inputGameShortName::inputGameShortName(TlBufferParser &p)
  : bot_id_(TlFetchObject<InputUser>::parse(p))
  , short_name_(TlFetchString<string>::parse(p))
{}

void inputGameShortName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_id_, s);
  TlStoreString::store(short_name_, s);
}

void inputGameShortName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_id_, s);
  TlStoreString::store(short_name_, s);
}

void inputGameShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGameShortName");
    s.store_object_field("bot_id", static_cast<const BaseObject *>(bot_id_.get()));
    s.store_field("short_name", short_name_);
    s.store_class_end();
  }
}

inputNotifyPeer::inputNotifyPeer(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t inputNotifyPeer::ID;

void inputNotifyPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void inputNotifyPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void inputNotifyPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputNotifyPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

const std::int32_t inputNotifyUsers::ID;

void inputNotifyUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputNotifyUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputNotifyUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputNotifyUsers");
    s.store_class_end();
  }
}

const std::int32_t inputNotifyChats::ID;

void inputNotifyChats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputNotifyChats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputNotifyChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputNotifyChats");
    s.store_class_end();
  }
}

const std::int32_t inputNotifyBroadcasts::ID;

void inputNotifyBroadcasts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputNotifyBroadcasts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputNotifyBroadcasts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputNotifyBroadcasts");
    s.store_class_end();
  }
}

inputNotifyForumTopic::inputNotifyForumTopic(object_ptr<InputPeer> &&peer_, int32 top_msg_id_)
  : peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
{}

const std::int32_t inputNotifyForumTopic::ID;

void inputNotifyForumTopic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(top_msg_id_, s);
}

void inputNotifyForumTopic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(top_msg_id_, s);
}

void inputNotifyForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputNotifyForumTopic");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_msg_id", top_msg_id_);
    s.store_class_end();
  }
}

inputNotifyCommunity::inputNotifyCommunity(object_ptr<InputChannel> &&community_)
  : community_(std::move(community_))
{}

const std::int32_t inputNotifyCommunity::ID;

void inputNotifyCommunity::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
}

void inputNotifyCommunity::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
}

void inputNotifyCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputNotifyCommunity");
    s.store_object_field("community", static_cast<const BaseObject *>(community_.get()));
    s.store_class_end();
  }
}

object_ptr<InputRichMessage> InputRichMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputRichMessage::ID:
      return inputRichMessage::fetch(p);
    case inputRichMessageHTML::ID:
      return inputRichMessageHTML::fetch(p);
    case inputRichMessageMarkdown::ID:
      return inputRichMessageMarkdown::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputRichMessage::inputRichMessage()
  : flags_()
  , rtl_()
  , noautolink_()
  , blocks_()
  , photos_()
  , documents_()
  , users_()
{}

inputRichMessage::inputRichMessage(int32 flags_, bool rtl_, bool noautolink_, array<object_ptr<PageBlock>> &&blocks_, array<object_ptr<InputPhoto>> &&photos_, array<object_ptr<InputDocument>> &&documents_, array<object_ptr<InputUser>> &&users_)
  : flags_(flags_)
  , rtl_(rtl_)
  , noautolink_(noautolink_)
  , blocks_(std::move(blocks_))
  , photos_(std::move(photos_))
  , documents_(std::move(documents_))
  , users_(std::move(users_))
{}

const std::int32_t inputRichMessage::ID;

object_ptr<InputRichMessage> inputRichMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputRichMessage> res = make_tl_object<inputRichMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->rtl_ = (var0 & 1) != 0;
  res->noautolink_ = (var0 & 2) != 0;
  res->blocks_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p);
  if (var0 & 4) { res->photos_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputPhoto>>, 481674261>::parse(p); }
  if (var0 & 8) { res->documents_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputDocument>>, 481674261>::parse(p); }
  if (var0 & 16) { res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputUser>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputRichMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtl_ << 0) | (noautolink_ << 1) | ((!photos_.empty()) << 2) | ((!documents_.empty()) << 3) | ((!users_.empty()) << 4)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(photos_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s); }
}

void inputRichMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtl_ << 0) | (noautolink_ << 1) | ((!photos_.empty()) << 2) | ((!documents_.empty()) << 3) | ((!users_.empty()) << 4)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(photos_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s); }
}

void inputRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputRichMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (rtl_ << 0) | (noautolink_ << 1) | ((!photos_.empty()) << 2) | ((!documents_.empty()) << 3) | ((!users_.empty()) << 4)));
    if (var0 & 1) { s.store_field("rtl", true); }
    if (var0 & 2) { s.store_field("noautolink", true); }
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 4) { { s.store_vector_begin("photos", photos_.size()); for (const auto &_value : photos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 8) { { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

inputRichMessageHTML::inputRichMessageHTML()
  : flags_()
  , rtl_()
  , noautolink_()
  , html_()
  , files_()
{}

inputRichMessageHTML::inputRichMessageHTML(int32 flags_, bool rtl_, bool noautolink_, string const &html_, array<object_ptr<InputRichFile>> &&files_)
  : flags_(flags_)
  , rtl_(rtl_)
  , noautolink_(noautolink_)
  , html_(html_)
  , files_(std::move(files_))
{}

const std::int32_t inputRichMessageHTML::ID;

object_ptr<InputRichMessage> inputRichMessageHTML::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputRichMessageHTML> res = make_tl_object<inputRichMessageHTML>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->rtl_ = (var0 & 1) != 0;
  res->noautolink_ = (var0 & 2) != 0;
  res->html_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->files_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputRichFile>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputRichMessageHTML::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtl_ << 0) | (noautolink_ << 1) | ((!files_.empty()) << 2)), s);
  TlStoreString::store(html_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(files_, s); }
}

void inputRichMessageHTML::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtl_ << 0) | (noautolink_ << 1) | ((!files_.empty()) << 2)), s);
  TlStoreString::store(html_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(files_, s); }
}

void inputRichMessageHTML::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputRichMessageHTML");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (rtl_ << 0) | (noautolink_ << 1) | ((!files_.empty()) << 2)));
    if (var0 & 1) { s.store_field("rtl", true); }
    if (var0 & 2) { s.store_field("noautolink", true); }
    s.store_field("html", html_);
    if (var0 & 4) { { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

inputRichMessageMarkdown::inputRichMessageMarkdown()
  : flags_()
  , rtl_()
  , noautolink_()
  , markdown_()
  , files_()
{}

inputRichMessageMarkdown::inputRichMessageMarkdown(int32 flags_, bool rtl_, bool noautolink_, string const &markdown_, array<object_ptr<InputRichFile>> &&files_)
  : flags_(flags_)
  , rtl_(rtl_)
  , noautolink_(noautolink_)
  , markdown_(markdown_)
  , files_(std::move(files_))
{}

const std::int32_t inputRichMessageMarkdown::ID;

object_ptr<InputRichMessage> inputRichMessageMarkdown::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputRichMessageMarkdown> res = make_tl_object<inputRichMessageMarkdown>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->rtl_ = (var0 & 1) != 0;
  res->noautolink_ = (var0 & 2) != 0;
  res->markdown_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->files_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputRichFile>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputRichMessageMarkdown::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtl_ << 0) | (noautolink_ << 1) | ((!files_.empty()) << 2)), s);
  TlStoreString::store(markdown_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(files_, s); }
}

void inputRichMessageMarkdown::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtl_ << 0) | (noautolink_ << 1) | ((!files_.empty()) << 2)), s);
  TlStoreString::store(markdown_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(files_, s); }
}

void inputRichMessageMarkdown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputRichMessageMarkdown");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (rtl_ << 0) | (noautolink_ << 1) | ((!files_.empty()) << 2)));
    if (var0 & 1) { s.store_field("rtl", true); }
    if (var0 & 2) { s.store_field("noautolink", true); }
    s.store_field("markdown", markdown_);
    if (var0 & 4) { { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

object_ptr<IpPort> IpPort::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case ipPort::ID:
      return ipPort::fetch(p);
    case ipPortSecret::ID:
      return ipPortSecret::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t ipPort::ID;

object_ptr<IpPort> ipPort::fetch(TlBufferParser &p) {
  return make_tl_object<ipPort>(p);
}

ipPort::ipPort(TlBufferParser &p)
  : ipv4_(TlFetchInt::parse(p))
  , port_(TlFetchInt::parse(p))
{}

void ipPort::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ipPort");
    s.store_field("ipv4", ipv4_);
    s.store_field("port", port_);
    s.store_class_end();
  }
}

const std::int32_t ipPortSecret::ID;

object_ptr<IpPort> ipPortSecret::fetch(TlBufferParser &p) {
  return make_tl_object<ipPortSecret>(p);
}

ipPortSecret::ipPortSecret(TlBufferParser &p)
  : ipv4_(TlFetchInt::parse(p))
  , port_(TlFetchInt::parse(p))
  , secret_(TlFetchBytes<bytes>::parse(p))
{}

void ipPortSecret::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ipPortSecret");
    s.store_field("ipv4", ipv4_);
    s.store_field("port", port_);
    s.store_field("secret", "[REDACTED]");
    s.store_class_end();
  }
}

object_ptr<JoinChatBotResult> JoinChatBotResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case joinChatBotResultApproved::ID:
      return joinChatBotResultApproved::fetch(p);
    case joinChatBotResultDeclined::ID:
      return joinChatBotResultDeclined::fetch(p);
    case joinChatBotResultQueued::ID:
      return joinChatBotResultQueued::fetch(p);
    case joinChatBotResultWebView::ID:
      return joinChatBotResultWebView::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t joinChatBotResultApproved::ID;

object_ptr<JoinChatBotResult> joinChatBotResultApproved::fetch(TlBufferParser &p) {
  return make_tl_object<joinChatBotResultApproved>();
}

void joinChatBotResultApproved::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void joinChatBotResultApproved::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void joinChatBotResultApproved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinChatBotResultApproved");
    s.store_class_end();
  }
}

const std::int32_t joinChatBotResultDeclined::ID;

object_ptr<JoinChatBotResult> joinChatBotResultDeclined::fetch(TlBufferParser &p) {
  return make_tl_object<joinChatBotResultDeclined>();
}

void joinChatBotResultDeclined::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void joinChatBotResultDeclined::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void joinChatBotResultDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinChatBotResultDeclined");
    s.store_class_end();
  }
}

const std::int32_t joinChatBotResultQueued::ID;

object_ptr<JoinChatBotResult> joinChatBotResultQueued::fetch(TlBufferParser &p) {
  return make_tl_object<joinChatBotResultQueued>();
}

void joinChatBotResultQueued::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void joinChatBotResultQueued::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void joinChatBotResultQueued::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinChatBotResultQueued");
    s.store_class_end();
  }
}

joinChatBotResultWebView::joinChatBotResultWebView(string const &url_)
  : url_(url_)
{}

const std::int32_t joinChatBotResultWebView::ID;

object_ptr<JoinChatBotResult> joinChatBotResultWebView::fetch(TlBufferParser &p) {
  return make_tl_object<joinChatBotResultWebView>(p);
}

joinChatBotResultWebView::joinChatBotResultWebView(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void joinChatBotResultWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
}

void joinChatBotResultWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
}

void joinChatBotResultWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinChatBotResultWebView");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

langPackLanguage::langPackLanguage()
  : flags_()
  , official_()
  , rtl_()
  , beta_()
  , name_()
  , native_name_()
  , lang_code_()
  , base_lang_code_()
  , plural_code_()
  , strings_count_()
  , translated_count_()
  , translations_url_()
{}

const std::int32_t langPackLanguage::ID;

object_ptr<langPackLanguage> langPackLanguage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<langPackLanguage> res = make_tl_object<langPackLanguage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->official_ = (var0 & 1) != 0;
  res->rtl_ = (var0 & 4) != 0;
  res->beta_ = (var0 & 8) != 0;
  res->name_ = TlFetchString<string>::parse(p);
  res->native_name_ = TlFetchString<string>::parse(p);
  res->lang_code_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->base_lang_code_ = TlFetchString<string>::parse(p); }
  res->plural_code_ = TlFetchString<string>::parse(p);
  res->strings_count_ = TlFetchInt::parse(p);
  res->translated_count_ = TlFetchInt::parse(p);
  res->translations_url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void langPackLanguage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langPackLanguage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (official_ << 0) | (rtl_ << 2) | (beta_ << 3) | ((!base_lang_code_.empty()) << 1)));
    if (var0 & 1) { s.store_field("official", true); }
    if (var0 & 4) { s.store_field("rtl", true); }
    if (var0 & 8) { s.store_field("beta", true); }
    s.store_field("name", name_);
    s.store_field("native_name", native_name_);
    s.store_field("lang_code", lang_code_);
    if (var0 & 2) { s.store_field("base_lang_code", base_lang_code_); }
    s.store_field("plural_code", plural_code_);
    s.store_field("strings_count", strings_count_);
    s.store_field("translated_count", translated_count_);
    s.store_field("translations_url", translations_url_);
    s.store_class_end();
  }
}

object_ptr<LangPackString> LangPackString::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case langPackString::ID:
      return langPackString::fetch(p);
    case langPackStringPluralized::ID:
      return langPackStringPluralized::fetch(p);
    case langPackStringDeleted::ID:
      return langPackStringDeleted::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

langPackString::langPackString(string const &key_, string const &value_)
  : key_(key_)
  , value_(value_)
{}

const std::int32_t langPackString::ID;

object_ptr<LangPackString> langPackString::fetch(TlBufferParser &p) {
  return make_tl_object<langPackString>(p);
}

langPackString::langPackString(TlBufferParser &p)
  : key_(TlFetchString<string>::parse(p))
  , value_(TlFetchString<string>::parse(p))
{}

void langPackString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langPackString");
    s.store_field("key", key_);
    s.store_field("value", value_);
    s.store_class_end();
  }
}

langPackStringPluralized::langPackStringPluralized()
  : flags_()
  , key_()
  , zero_value_()
  , one_value_()
  , two_value_()
  , few_value_()
  , many_value_()
  , other_value_()
{}

langPackStringPluralized::langPackStringPluralized(int32 flags_, string const &key_, string const &zero_value_, string const &one_value_, string const &two_value_, string const &few_value_, string const &many_value_, string const &other_value_)
  : flags_(flags_)
  , key_(key_)
  , zero_value_(zero_value_)
  , one_value_(one_value_)
  , two_value_(two_value_)
  , few_value_(few_value_)
  , many_value_(many_value_)
  , other_value_(other_value_)
{}

const std::int32_t langPackStringPluralized::ID;

object_ptr<LangPackString> langPackStringPluralized::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<langPackStringPluralized> res = make_tl_object<langPackStringPluralized>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->key_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->zero_value_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->one_value_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->two_value_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->few_value_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->many_value_ = TlFetchString<string>::parse(p); }
  res->other_value_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void langPackStringPluralized::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langPackStringPluralized");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!zero_value_.empty()) << 0) | ((!one_value_.empty()) << 1) | ((!two_value_.empty()) << 2) | ((!few_value_.empty()) << 3) | ((!many_value_.empty()) << 4)));
    s.store_field("key", key_);
    if (var0 & 1) { s.store_field("zero_value", zero_value_); }
    if (var0 & 2) { s.store_field("one_value", one_value_); }
    if (var0 & 4) { s.store_field("two_value", two_value_); }
    if (var0 & 8) { s.store_field("few_value", few_value_); }
    if (var0 & 16) { s.store_field("many_value", many_value_); }
    s.store_field("other_value", other_value_);
    s.store_class_end();
  }
}

langPackStringDeleted::langPackStringDeleted(string const &key_)
  : key_(key_)
{}

const std::int32_t langPackStringDeleted::ID;

object_ptr<LangPackString> langPackStringDeleted::fetch(TlBufferParser &p) {
  return make_tl_object<langPackStringDeleted>(p);
}

langPackStringDeleted::langPackStringDeleted(TlBufferParser &p)
  : key_(TlFetchString<string>::parse(p))
{}

void langPackStringDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langPackStringDeleted");
    s.store_field("key", key_);
    s.store_class_end();
  }
}

maskCoords::maskCoords(int32 n_, double x_, double y_, double zoom_)
  : n_(n_)
  , x_(x_)
  , y_(y_)
  , zoom_(zoom_)
{}

const std::int32_t maskCoords::ID;

object_ptr<maskCoords> maskCoords::fetch(TlBufferParser &p) {
  return make_tl_object<maskCoords>(p);
}

maskCoords::maskCoords(TlBufferParser &p)
  : n_(TlFetchInt::parse(p))
  , x_(TlFetchDouble::parse(p))
  , y_(TlFetchDouble::parse(p))
  , zoom_(TlFetchDouble::parse(p))
{}

void maskCoords::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(n_, s);
  TlStoreBinary::store(x_, s);
  TlStoreBinary::store(y_, s);
  TlStoreBinary::store(zoom_, s);
}

void maskCoords::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(n_, s);
  TlStoreBinary::store(x_, s);
  TlStoreBinary::store(y_, s);
  TlStoreBinary::store(zoom_, s);
}

void maskCoords::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskCoords");
    s.store_field("n", n_);
    s.store_field("x", x_);
    s.store_field("y", y_);
    s.store_field("zoom", zoom_);
    s.store_class_end();
  }
}

object_ptr<MessageEntity> MessageEntity::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messageEntityUnknown::ID:
      return messageEntityUnknown::fetch(p);
    case messageEntityMention::ID:
      return messageEntityMention::fetch(p);
    case messageEntityHashtag::ID:
      return messageEntityHashtag::fetch(p);
    case messageEntityBotCommand::ID:
      return messageEntityBotCommand::fetch(p);
    case messageEntityUrl::ID:
      return messageEntityUrl::fetch(p);
    case messageEntityEmail::ID:
      return messageEntityEmail::fetch(p);
    case messageEntityBold::ID:
      return messageEntityBold::fetch(p);
    case messageEntityItalic::ID:
      return messageEntityItalic::fetch(p);
    case messageEntityCode::ID:
      return messageEntityCode::fetch(p);
    case messageEntityPre::ID:
      return messageEntityPre::fetch(p);
    case messageEntityTextUrl::ID:
      return messageEntityTextUrl::fetch(p);
    case messageEntityMentionName::ID:
      return messageEntityMentionName::fetch(p);
    case inputMessageEntityMentionName::ID:
      return inputMessageEntityMentionName::fetch(p);
    case messageEntityPhone::ID:
      return messageEntityPhone::fetch(p);
    case messageEntityCashtag::ID:
      return messageEntityCashtag::fetch(p);
    case messageEntityUnderline::ID:
      return messageEntityUnderline::fetch(p);
    case messageEntityStrike::ID:
      return messageEntityStrike::fetch(p);
    case messageEntityBankCard::ID:
      return messageEntityBankCard::fetch(p);
    case messageEntitySpoiler::ID:
      return messageEntitySpoiler::fetch(p);
    case messageEntityCustomEmoji::ID:
      return messageEntityCustomEmoji::fetch(p);
    case messageEntityBlockquote::ID:
      return messageEntityBlockquote::fetch(p);
    case messageEntityFormattedDate::ID:
      return messageEntityFormattedDate::fetch(p);
    case messageEntityDiffInsert::ID:
      return messageEntityDiffInsert::fetch(p);
    case messageEntityDiffReplace::ID:
      return messageEntityDiffReplace::fetch(p);
    case messageEntityDiffDelete::ID:
      return messageEntityDiffDelete::fetch(p);
    case messageEntityTonAddress::ID:
      return messageEntityTonAddress::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messageEntityUnknown::messageEntityUnknown(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityUnknown::ID;

object_ptr<MessageEntity> messageEntityUnknown::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityUnknown>(p);
}

messageEntityUnknown::messageEntityUnknown(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityUnknown::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUnknown::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityUnknown");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityMention::messageEntityMention(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityMention::ID;

object_ptr<MessageEntity> messageEntityMention::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityMention>(p);
}

messageEntityMention::messageEntityMention(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityMention::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityMention::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityMention");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityHashtag::messageEntityHashtag(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityHashtag::ID;

object_ptr<MessageEntity> messageEntityHashtag::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityHashtag>(p);
}

messageEntityHashtag::messageEntityHashtag(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityHashtag::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityHashtag::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityHashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityHashtag");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityBotCommand::messageEntityBotCommand(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityBotCommand::ID;

object_ptr<MessageEntity> messageEntityBotCommand::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityBotCommand>(p);
}

messageEntityBotCommand::messageEntityBotCommand(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityBotCommand::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBotCommand::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBotCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityBotCommand");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityUrl::messageEntityUrl(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityUrl::ID;

object_ptr<MessageEntity> messageEntityUrl::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityUrl>(p);
}

messageEntityUrl::messageEntityUrl(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityUrl");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityEmail::messageEntityEmail(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityEmail::ID;

object_ptr<MessageEntity> messageEntityEmail::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityEmail>(p);
}

messageEntityEmail::messageEntityEmail(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityEmail");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityBold::messageEntityBold(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityBold::ID;

object_ptr<MessageEntity> messageEntityBold::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityBold>(p);
}

messageEntityBold::messageEntityBold(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityBold::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBold::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBold::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityBold");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityItalic::messageEntityItalic(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityItalic::ID;

object_ptr<MessageEntity> messageEntityItalic::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityItalic>(p);
}

messageEntityItalic::messageEntityItalic(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityItalic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityItalic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityItalic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityItalic");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityCode::messageEntityCode(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityCode::ID;

object_ptr<MessageEntity> messageEntityCode::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityCode>(p);
}

messageEntityCode::messageEntityCode(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityCode");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityPre::messageEntityPre(int32 offset_, int32 length_, string const &language_)
  : offset_(offset_)
  , length_(length_)
  , language_(language_)
{}

const std::int32_t messageEntityPre::ID;

object_ptr<MessageEntity> messageEntityPre::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityPre>(p);
}

messageEntityPre::messageEntityPre(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , language_(TlFetchString<string>::parse(p))
{}

void messageEntityPre::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(language_, s);
}

void messageEntityPre::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(language_, s);
}

void messageEntityPre::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityPre");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("language", language_);
    s.store_class_end();
  }
}

messageEntityTextUrl::messageEntityTextUrl(int32 offset_, int32 length_, string const &url_)
  : offset_(offset_)
  , length_(length_)
  , url_(url_)
{}

const std::int32_t messageEntityTextUrl::ID;

object_ptr<MessageEntity> messageEntityTextUrl::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityTextUrl>(p);
}

messageEntityTextUrl::messageEntityTextUrl(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void messageEntityTextUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(url_, s);
}

void messageEntityTextUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(url_, s);
}

void messageEntityTextUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityTextUrl");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

messageEntityMentionName::messageEntityMentionName(int32 offset_, int32 length_, int64 user_id_)
  : offset_(offset_)
  , length_(length_)
  , user_id_(user_id_)
{}

const std::int32_t messageEntityMentionName::ID;

object_ptr<MessageEntity> messageEntityMentionName::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityMentionName>(p);
}

messageEntityMentionName::messageEntityMentionName(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , user_id_(TlFetchLong::parse(p))
{}

void messageEntityMentionName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(user_id_, s);
}

void messageEntityMentionName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(user_id_, s);
}

void messageEntityMentionName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityMentionName");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

inputMessageEntityMentionName::inputMessageEntityMentionName(int32 offset_, int32 length_, object_ptr<InputUser> &&user_id_)
  : offset_(offset_)
  , length_(length_)
  , user_id_(std::move(user_id_))
{}

const std::int32_t inputMessageEntityMentionName::ID;

object_ptr<MessageEntity> inputMessageEntityMentionName::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessageEntityMentionName>(p);
}

inputMessageEntityMentionName::inputMessageEntityMentionName(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , user_id_(TlFetchObject<InputUser>::parse(p))
{}

void inputMessageEntityMentionName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void inputMessageEntityMentionName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void inputMessageEntityMentionName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageEntityMentionName");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

messageEntityPhone::messageEntityPhone(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityPhone::ID;

object_ptr<MessageEntity> messageEntityPhone::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityPhone>(p);
}

messageEntityPhone::messageEntityPhone(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityPhone");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityCashtag::messageEntityCashtag(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityCashtag::ID;

object_ptr<MessageEntity> messageEntityCashtag::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityCashtag>(p);
}

messageEntityCashtag::messageEntityCashtag(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityCashtag::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityCashtag::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityCashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityCashtag");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityUnderline::messageEntityUnderline(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityUnderline::ID;

object_ptr<MessageEntity> messageEntityUnderline::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityUnderline>(p);
}

messageEntityUnderline::messageEntityUnderline(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityUnderline::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUnderline::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUnderline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityUnderline");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityStrike::messageEntityStrike(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityStrike::ID;

object_ptr<MessageEntity> messageEntityStrike::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityStrike>(p);
}

messageEntityStrike::messageEntityStrike(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityStrike::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityStrike::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityStrike::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityStrike");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityBankCard::messageEntityBankCard(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityBankCard::ID;

object_ptr<MessageEntity> messageEntityBankCard::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityBankCard>(p);
}

messageEntityBankCard::messageEntityBankCard(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityBankCard::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBankCard::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBankCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityBankCard");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntitySpoiler::messageEntitySpoiler(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntitySpoiler::ID;

object_ptr<MessageEntity> messageEntitySpoiler::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntitySpoiler>(p);
}

messageEntitySpoiler::messageEntitySpoiler(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntitySpoiler::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntitySpoiler::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntitySpoiler::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntitySpoiler");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityCustomEmoji::messageEntityCustomEmoji(int32 offset_, int32 length_, int64 document_id_)
  : offset_(offset_)
  , length_(length_)
  , document_id_(document_id_)
{}

const std::int32_t messageEntityCustomEmoji::ID;

object_ptr<MessageEntity> messageEntityCustomEmoji::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityCustomEmoji>(p);
}

messageEntityCustomEmoji::messageEntityCustomEmoji(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , document_id_(TlFetchLong::parse(p))
{}

void messageEntityCustomEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(document_id_, s);
}

void messageEntityCustomEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(document_id_, s);
}

void messageEntityCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityCustomEmoji");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("document_id", document_id_);
    s.store_class_end();
  }
}

messageEntityBlockquote::messageEntityBlockquote()
  : flags_()
  , collapsed_()
  , offset_()
  , length_()
{}

messageEntityBlockquote::messageEntityBlockquote(int32 flags_, bool collapsed_, int32 offset_, int32 length_)
  : flags_(flags_)
  , collapsed_(collapsed_)
  , offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityBlockquote::ID;

object_ptr<MessageEntity> messageEntityBlockquote::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageEntityBlockquote> res = make_tl_object<messageEntityBlockquote>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collapsed_ = (var0 & 1) != 0;
  res->offset_ = TlFetchInt::parse(p);
  res->length_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageEntityBlockquote::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (collapsed_ << 0)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBlockquote::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (collapsed_ << 0)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBlockquote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityBlockquote");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (collapsed_ << 0)));
    if (var0 & 1) { s.store_field("collapsed", true); }
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityFormattedDate::messageEntityFormattedDate()
  : flags_()
  , relative_()
  , short_time_()
  , long_time_()
  , short_date_()
  , long_date_()
  , day_of_week_()
  , offset_()
  , length_()
  , date_()
{}

messageEntityFormattedDate::messageEntityFormattedDate(int32 flags_, bool relative_, bool short_time_, bool long_time_, bool short_date_, bool long_date_, bool day_of_week_, int32 offset_, int32 length_, int32 date_)
  : flags_(flags_)
  , relative_(relative_)
  , short_time_(short_time_)
  , long_time_(long_time_)
  , short_date_(short_date_)
  , long_date_(long_date_)
  , day_of_week_(day_of_week_)
  , offset_(offset_)
  , length_(length_)
  , date_(date_)
{}

const std::int32_t messageEntityFormattedDate::ID;

object_ptr<MessageEntity> messageEntityFormattedDate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageEntityFormattedDate> res = make_tl_object<messageEntityFormattedDate>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->relative_ = (var0 & 1) != 0;
  res->short_time_ = (var0 & 2) != 0;
  res->long_time_ = (var0 & 4) != 0;
  res->short_date_ = (var0 & 8) != 0;
  res->long_date_ = (var0 & 16) != 0;
  res->day_of_week_ = (var0 & 32) != 0;
  res->offset_ = TlFetchInt::parse(p);
  res->length_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageEntityFormattedDate::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (relative_ << 0) | (short_time_ << 1) | (long_time_ << 2) | (short_date_ << 3) | (long_date_ << 4) | (day_of_week_ << 5)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(date_, s);
}

void messageEntityFormattedDate::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (relative_ << 0) | (short_time_ << 1) | (long_time_ << 2) | (short_date_ << 3) | (long_date_ << 4) | (day_of_week_ << 5)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(date_, s);
}

void messageEntityFormattedDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityFormattedDate");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (relative_ << 0) | (short_time_ << 1) | (long_time_ << 2) | (short_date_ << 3) | (long_date_ << 4) | (day_of_week_ << 5)));
    if (var0 & 1) { s.store_field("relative", true); }
    if (var0 & 2) { s.store_field("short_time", true); }
    if (var0 & 4) { s.store_field("long_time", true); }
    if (var0 & 8) { s.store_field("short_date", true); }
    if (var0 & 16) { s.store_field("long_date", true); }
    if (var0 & 32) { s.store_field("day_of_week", true); }
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

messageEntityDiffInsert::messageEntityDiffInsert(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityDiffInsert::ID;

object_ptr<MessageEntity> messageEntityDiffInsert::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityDiffInsert>(p);
}

messageEntityDiffInsert::messageEntityDiffInsert(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityDiffInsert::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityDiffInsert::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityDiffInsert::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityDiffInsert");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityDiffReplace::messageEntityDiffReplace(int32 offset_, int32 length_, string const &old_text_)
  : offset_(offset_)
  , length_(length_)
  , old_text_(old_text_)
{}

const std::int32_t messageEntityDiffReplace::ID;

object_ptr<MessageEntity> messageEntityDiffReplace::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityDiffReplace>(p);
}

messageEntityDiffReplace::messageEntityDiffReplace(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , old_text_(TlFetchString<string>::parse(p))
{}

void messageEntityDiffReplace::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(old_text_, s);
}

void messageEntityDiffReplace::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(old_text_, s);
}

void messageEntityDiffReplace::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityDiffReplace");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("old_text", old_text_);
    s.store_class_end();
  }
}

messageEntityDiffDelete::messageEntityDiffDelete(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityDiffDelete::ID;

object_ptr<MessageEntity> messageEntityDiffDelete::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityDiffDelete>(p);
}

messageEntityDiffDelete::messageEntityDiffDelete(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityDiffDelete::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityDiffDelete::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityDiffDelete::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityDiffDelete");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityTonAddress::messageEntityTonAddress(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityTonAddress::ID;

object_ptr<MessageEntity> messageEntityTonAddress::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityTonAddress>(p);
}

messageEntityTonAddress::messageEntityTonAddress(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityTonAddress::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityTonAddress::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityTonAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityTonAddress");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

missingInvitee::missingInvitee()
  : flags_()
  , premium_would_allow_invite_()
  , premium_required_for_pm_()
  , user_id_()
{}

const std::int32_t missingInvitee::ID;

object_ptr<missingInvitee> missingInvitee::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<missingInvitee> res = make_tl_object<missingInvitee>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->premium_would_allow_invite_ = (var0 & 1) != 0;
  res->premium_required_for_pm_ = (var0 & 2) != 0;
  res->user_id_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void missingInvitee::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "missingInvitee");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (premium_would_allow_invite_ << 0) | (premium_required_for_pm_ << 1)));
    if (var0 & 1) { s.store_field("premium_would_allow_invite", true); }
    if (var0 & 2) { s.store_field("premium_required_for_pm", true); }
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

myBoost::myBoost()
  : flags_()
  , slot_()
  , peer_()
  , date_()
  , expires_()
  , cooldown_until_date_()
{}

const std::int32_t myBoost::ID;

object_ptr<myBoost> myBoost::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<myBoost> res = make_tl_object<myBoost>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->slot_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->expires_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->cooldown_until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void myBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "myBoost");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((peer_ != nullptr) << 0)));
    s.store_field("slot", slot_);
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_field("date", date_);
    s.store_field("expires", expires_);
    if (var0 & 2) { s.store_field("cooldown_until_date", cooldown_until_date_); }
    s.store_class_end();
  }
}

object_ptr<NotifyPeer> NotifyPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case notifyPeer::ID:
      return notifyPeer::fetch(p);
    case notifyUsers::ID:
      return notifyUsers::fetch(p);
    case notifyChats::ID:
      return notifyChats::fetch(p);
    case notifyBroadcasts::ID:
      return notifyBroadcasts::fetch(p);
    case notifyForumTopic::ID:
      return notifyForumTopic::fetch(p);
    case notifyCommunity::ID:
      return notifyCommunity::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t notifyPeer::ID;

object_ptr<NotifyPeer> notifyPeer::fetch(TlBufferParser &p) {
  return make_tl_object<notifyPeer>(p);
}

notifyPeer::notifyPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
{}

void notifyPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notifyPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

const std::int32_t notifyUsers::ID;

object_ptr<NotifyPeer> notifyUsers::fetch(TlBufferParser &p) {
  return make_tl_object<notifyUsers>();
}

void notifyUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notifyUsers");
    s.store_class_end();
  }
}

const std::int32_t notifyChats::ID;

object_ptr<NotifyPeer> notifyChats::fetch(TlBufferParser &p) {
  return make_tl_object<notifyChats>();
}

void notifyChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notifyChats");
    s.store_class_end();
  }
}

const std::int32_t notifyBroadcasts::ID;

object_ptr<NotifyPeer> notifyBroadcasts::fetch(TlBufferParser &p) {
  return make_tl_object<notifyBroadcasts>();
}

void notifyBroadcasts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notifyBroadcasts");
    s.store_class_end();
  }
}

const std::int32_t notifyForumTopic::ID;

object_ptr<NotifyPeer> notifyForumTopic::fetch(TlBufferParser &p) {
  return make_tl_object<notifyForumTopic>(p);
}

notifyForumTopic::notifyForumTopic(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , top_msg_id_(TlFetchInt::parse(p))
{}

void notifyForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notifyForumTopic");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_msg_id", top_msg_id_);
    s.store_class_end();
  }
}

const std::int32_t notifyCommunity::ID;

object_ptr<NotifyPeer> notifyCommunity::fetch(TlBufferParser &p) {
  return make_tl_object<notifyCommunity>(p);
}

notifyCommunity::notifyCommunity(TlBufferParser &p)
  : community_id_(TlFetchLong::parse(p))
{}

void notifyCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notifyCommunity");
    s.store_field("community_id", community_id_);
    s.store_class_end();
  }
}

object_ptr<PageBlock> PageBlock::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case pageBlockUnsupported::ID:
      return pageBlockUnsupported::fetch(p);
    case pageBlockTitle::ID:
      return pageBlockTitle::fetch(p);
    case pageBlockSubtitle::ID:
      return pageBlockSubtitle::fetch(p);
    case pageBlockAuthorDate::ID:
      return pageBlockAuthorDate::fetch(p);
    case pageBlockHeader::ID:
      return pageBlockHeader::fetch(p);
    case pageBlockSubheader::ID:
      return pageBlockSubheader::fetch(p);
    case pageBlockParagraph::ID:
      return pageBlockParagraph::fetch(p);
    case pageBlockPreformatted::ID:
      return pageBlockPreformatted::fetch(p);
    case pageBlockFooter::ID:
      return pageBlockFooter::fetch(p);
    case pageBlockDivider::ID:
      return pageBlockDivider::fetch(p);
    case pageBlockAnchor::ID:
      return pageBlockAnchor::fetch(p);
    case pageBlockList::ID:
      return pageBlockList::fetch(p);
    case pageBlockBlockquote::ID:
      return pageBlockBlockquote::fetch(p);
    case pageBlockPullquote::ID:
      return pageBlockPullquote::fetch(p);
    case pageBlockPhoto::ID:
      return pageBlockPhoto::fetch(p);
    case pageBlockVideo::ID:
      return pageBlockVideo::fetch(p);
    case pageBlockCover::ID:
      return pageBlockCover::fetch(p);
    case pageBlockEmbed::ID:
      return pageBlockEmbed::fetch(p);
    case pageBlockEmbedPost::ID:
      return pageBlockEmbedPost::fetch(p);
    case pageBlockCollage::ID:
      return pageBlockCollage::fetch(p);
    case pageBlockSlideshow::ID:
      return pageBlockSlideshow::fetch(p);
    case pageBlockChannel::ID:
      return pageBlockChannel::fetch(p);
    case pageBlockAudio::ID:
      return pageBlockAudio::fetch(p);
    case pageBlockKicker::ID:
      return pageBlockKicker::fetch(p);
    case pageBlockTable::ID:
      return pageBlockTable::fetch(p);
    case pageBlockOrderedList::ID:
      return pageBlockOrderedList::fetch(p);
    case pageBlockDetails::ID:
      return pageBlockDetails::fetch(p);
    case pageBlockRelatedArticles::ID:
      return pageBlockRelatedArticles::fetch(p);
    case pageBlockMap::ID:
      return pageBlockMap::fetch(p);
    case pageBlockHeading1::ID:
      return pageBlockHeading1::fetch(p);
    case pageBlockHeading2::ID:
      return pageBlockHeading2::fetch(p);
    case pageBlockHeading3::ID:
      return pageBlockHeading3::fetch(p);
    case pageBlockHeading4::ID:
      return pageBlockHeading4::fetch(p);
    case pageBlockHeading5::ID:
      return pageBlockHeading5::fetch(p);
    case pageBlockHeading6::ID:
      return pageBlockHeading6::fetch(p);
    case pageBlockMath::ID:
      return pageBlockMath::fetch(p);
    case pageBlockThinking::ID:
      return pageBlockThinking::fetch(p);
    case inputPageBlockMap::ID:
      return inputPageBlockMap::fetch(p);
    case pageBlockBlockquoteBlocks::ID:
      return pageBlockBlockquoteBlocks::fetch(p);
    case pageBlockButtonRow::ID:
      return pageBlockButtonRow::fetch(p);
    case pageBlockDocument::ID:
      return pageBlockDocument::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t pageBlockUnsupported::ID;

object_ptr<PageBlock> pageBlockUnsupported::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockUnsupported>();
}

void pageBlockUnsupported::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void pageBlockUnsupported::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void pageBlockUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockUnsupported");
    s.store_class_end();
  }
}

pageBlockTitle::pageBlockTitle(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockTitle::ID;

object_ptr<PageBlock> pageBlockTitle::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockTitle>(p);
}

pageBlockTitle::pageBlockTitle(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockTitle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockTitle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTitle");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockSubtitle::pageBlockSubtitle(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockSubtitle::ID;

object_ptr<PageBlock> pageBlockSubtitle::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockSubtitle>(p);
}

pageBlockSubtitle::pageBlockSubtitle(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockSubtitle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockSubtitle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockSubtitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSubtitle");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockAuthorDate::pageBlockAuthorDate(object_ptr<RichText> &&author_, int32 published_date_)
  : author_(std::move(author_))
  , published_date_(published_date_)
{}

const std::int32_t pageBlockAuthorDate::ID;

object_ptr<PageBlock> pageBlockAuthorDate::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockAuthorDate>(p);
}

pageBlockAuthorDate::pageBlockAuthorDate(TlBufferParser &p)
  : author_(TlFetchObject<RichText>::parse(p))
  , published_date_(TlFetchInt::parse(p))
{}

void pageBlockAuthorDate::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(author_, s);
  TlStoreBinary::store(published_date_, s);
}

void pageBlockAuthorDate::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(author_, s);
  TlStoreBinary::store(published_date_, s);
}

void pageBlockAuthorDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAuthorDate");
    s.store_object_field("author", static_cast<const BaseObject *>(author_.get()));
    s.store_field("published_date", published_date_);
    s.store_class_end();
  }
}

pageBlockHeader::pageBlockHeader(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockHeader::ID;

object_ptr<PageBlock> pageBlockHeader::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockHeader>(p);
}

pageBlockHeader::pageBlockHeader(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockHeader::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeader::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHeader");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockSubheader::pageBlockSubheader(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockSubheader::ID;

object_ptr<PageBlock> pageBlockSubheader::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockSubheader>(p);
}

pageBlockSubheader::pageBlockSubheader(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockSubheader::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockSubheader::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockSubheader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSubheader");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockParagraph::pageBlockParagraph(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockParagraph::ID;

object_ptr<PageBlock> pageBlockParagraph::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockParagraph>(p);
}

pageBlockParagraph::pageBlockParagraph(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockParagraph::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockParagraph::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockParagraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockParagraph");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockPreformatted::pageBlockPreformatted(object_ptr<RichText> &&text_, string const &language_)
  : text_(std::move(text_))
  , language_(language_)
{}

const std::int32_t pageBlockPreformatted::ID;

object_ptr<PageBlock> pageBlockPreformatted::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockPreformatted>(p);
}

pageBlockPreformatted::pageBlockPreformatted(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , language_(TlFetchString<string>::parse(p))
{}

void pageBlockPreformatted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(language_, s);
}

void pageBlockPreformatted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(language_, s);
}

void pageBlockPreformatted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPreformatted");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("language", language_);
    s.store_class_end();
  }
}

pageBlockFooter::pageBlockFooter(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockFooter::ID;

object_ptr<PageBlock> pageBlockFooter::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockFooter>(p);
}

pageBlockFooter::pageBlockFooter(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockFooter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockFooter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockFooter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockFooter");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

const std::int32_t pageBlockDivider::ID;

object_ptr<PageBlock> pageBlockDivider::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockDivider>();
}

void pageBlockDivider::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void pageBlockDivider::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void pageBlockDivider::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDivider");
    s.store_class_end();
  }
}

pageBlockAnchor::pageBlockAnchor(string const &name_)
  : name_(name_)
{}

const std::int32_t pageBlockAnchor::ID;

object_ptr<PageBlock> pageBlockAnchor::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockAnchor>(p);
}

pageBlockAnchor::pageBlockAnchor(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
{}

void pageBlockAnchor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
}

void pageBlockAnchor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
}

void pageBlockAnchor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAnchor");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

pageBlockList::pageBlockList(array<object_ptr<PageListItem>> &&items_)
  : items_(std::move(items_))
{}

const std::int32_t pageBlockList::ID;

object_ptr<PageBlock> pageBlockList::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockList>(p);
}

pageBlockList::pageBlockList(TlBufferParser &p)
  : items_(TlFetchBoxed<TlFetchVector<TlFetchObject<PageListItem>>, 481674261>::parse(p))
{}

void pageBlockList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
}

void pageBlockList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
}

void pageBlockList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockList");
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockBlockquote::pageBlockBlockquote()
  : flags_()
  , collapsed_()
  , text_()
  , caption_()
{}

pageBlockBlockquote::pageBlockBlockquote(int32 flags_, bool collapsed_, object_ptr<RichText> &&text_, object_ptr<RichText> &&caption_)
  : flags_(flags_)
  , collapsed_(collapsed_)
  , text_(std::move(text_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockBlockquote::ID;

object_ptr<PageBlock> pageBlockBlockquote::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockBlockquote> res = make_tl_object<pageBlockBlockquote>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collapsed_ = (var0 & 1) != 0;
  res->text_ = TlFetchObject<RichText>::parse(p);
  res->caption_ = TlFetchObject<RichText>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockBlockquote::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (collapsed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(caption_, s);
}

void pageBlockBlockquote::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (collapsed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(caption_, s);
}

void pageBlockBlockquote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockBlockquote");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (collapsed_ << 0)));
    if (var0 & 1) { s.store_field("collapsed", true); }
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockPullquote::pageBlockPullquote(object_ptr<RichText> &&text_, object_ptr<RichText> &&caption_)
  : text_(std::move(text_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockPullquote::ID;

object_ptr<PageBlock> pageBlockPullquote::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockPullquote>(p);
}

pageBlockPullquote::pageBlockPullquote(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , caption_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockPullquote::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(caption_, s);
}

void pageBlockPullquote::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(caption_, s);
}

void pageBlockPullquote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPullquote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockPhoto::pageBlockPhoto()
  : flags_()
  , spoiler_()
  , photo_id_()
  , caption_()
  , url_()
  , webpage_id_()
{}

pageBlockPhoto::pageBlockPhoto(int32 flags_, bool spoiler_, int64 photo_id_, object_ptr<pageCaption> &&caption_, string const &url_, int64 webpage_id_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , photo_id_(photo_id_)
  , caption_(std::move(caption_))
  , url_(url_)
  , webpage_id_(webpage_id_)
{}

const std::int32_t pageBlockPhoto::ID;

object_ptr<PageBlock> pageBlockPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockPhoto> res = make_tl_object<pageBlockPhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 2) != 0;
  res->photo_id_ = TlFetchLong::parse(p);
  res->caption_ = TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p);
  if (var0 & 1) { res->url_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->webpage_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1) | ((!url_.empty()) << 0)), s);
  TlStoreBinary::store(photo_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
  if (var0 & 1) { TlStoreBinary::store(webpage_id_, s); }
}

void pageBlockPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1) | ((!url_.empty()) << 0)), s);
  TlStoreBinary::store(photo_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
  if (var0 & 1) { TlStoreBinary::store(webpage_id_, s); }
}

void pageBlockPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 1) | ((!url_.empty()) << 0)));
    if (var0 & 2) { s.store_field("spoiler", true); }
    s.store_field("photo_id", photo_id_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    if (var0 & 1) { s.store_field("url", url_); }
    if (var0 & 1) { s.store_field("webpage_id", webpage_id_); }
    s.store_class_end();
  }
}

pageBlockVideo::pageBlockVideo()
  : flags_()
  , autoplay_()
  , loop_()
  , spoiler_()
  , video_id_()
  , caption_()
{}

pageBlockVideo::pageBlockVideo(int32 flags_, bool autoplay_, bool loop_, bool spoiler_, int64 video_id_, object_ptr<pageCaption> &&caption_)
  : flags_(flags_)
  , autoplay_(autoplay_)
  , loop_(loop_)
  , spoiler_(spoiler_)
  , video_id_(video_id_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockVideo::ID;

object_ptr<PageBlock> pageBlockVideo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockVideo> res = make_tl_object<pageBlockVideo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->autoplay_ = (var0 & 1) != 0;
  res->loop_ = (var0 & 2) != 0;
  res->spoiler_ = (var0 & 4) != 0;
  res->video_id_ = TlFetchLong::parse(p);
  res->caption_ = TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockVideo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (autoplay_ << 0) | (loop_ << 1) | (spoiler_ << 2)), s);
  TlStoreBinary::store(video_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockVideo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (autoplay_ << 0) | (loop_ << 1) | (spoiler_ << 2)), s);
  TlStoreBinary::store(video_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVideo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (autoplay_ << 0) | (loop_ << 1) | (spoiler_ << 2)));
    if (var0 & 1) { s.store_field("autoplay", true); }
    if (var0 & 2) { s.store_field("loop", true); }
    if (var0 & 4) { s.store_field("spoiler", true); }
    s.store_field("video_id", video_id_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockCover::pageBlockCover(object_ptr<PageBlock> &&cover_)
  : cover_(std::move(cover_))
{}

const std::int32_t pageBlockCover::ID;

object_ptr<PageBlock> pageBlockCover::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockCover>(p);
}

pageBlockCover::pageBlockCover(TlBufferParser &p)
  : cover_(TlFetchObject<PageBlock>::parse(p))
{}

void pageBlockCover::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(cover_, s);
}

void pageBlockCover::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(cover_, s);
}

void pageBlockCover::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCover");
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_class_end();
  }
}

pageBlockEmbed::pageBlockEmbed()
  : flags_()
  , full_width_()
  , allow_scrolling_()
  , url_()
  , html_()
  , poster_photo_id_()
  , w_()
  , h_()
  , caption_()
{}

pageBlockEmbed::pageBlockEmbed(int32 flags_, bool full_width_, bool allow_scrolling_, string const &url_, string const &html_, int64 poster_photo_id_, int32 w_, int32 h_, object_ptr<pageCaption> &&caption_)
  : flags_(flags_)
  , full_width_(full_width_)
  , allow_scrolling_(allow_scrolling_)
  , url_(url_)
  , html_(html_)
  , poster_photo_id_(poster_photo_id_)
  , w_(w_)
  , h_(h_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockEmbed::ID;

object_ptr<PageBlock> pageBlockEmbed::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockEmbed> res = make_tl_object<pageBlockEmbed>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->full_width_ = (var0 & 1) != 0;
  res->allow_scrolling_ = (var0 & 8) != 0;
  if (var0 & 2) { res->url_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->html_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->poster_photo_id_ = TlFetchLong::parse(p); }
  if (var0 & 32) { res->w_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->h_ = TlFetchInt::parse(p); }
  res->caption_ = TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockEmbed::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (full_width_ << 0) | (allow_scrolling_ << 3) | ((!url_.empty()) << 1) | ((!html_.empty()) << 2)), s);
  if (var0 & 2) { TlStoreString::store(url_, s); }
  if (var0 & 4) { TlStoreString::store(html_, s); }
  if (var0 & 16) { TlStoreBinary::store(poster_photo_id_, s); }
  if (var0 & 32) { TlStoreBinary::store(w_, s); }
  if (var0 & 32) { TlStoreBinary::store(h_, s); }
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockEmbed::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (full_width_ << 0) | (allow_scrolling_ << 3) | ((!url_.empty()) << 1) | ((!html_.empty()) << 2)), s);
  if (var0 & 2) { TlStoreString::store(url_, s); }
  if (var0 & 4) { TlStoreString::store(html_, s); }
  if (var0 & 16) { TlStoreBinary::store(poster_photo_id_, s); }
  if (var0 & 32) { TlStoreBinary::store(w_, s); }
  if (var0 & 32) { TlStoreBinary::store(h_, s); }
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockEmbed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockEmbed");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (full_width_ << 0) | (allow_scrolling_ << 3) | ((!url_.empty()) << 1) | ((!html_.empty()) << 2)));
    if (var0 & 1) { s.store_field("full_width", true); }
    if (var0 & 8) { s.store_field("allow_scrolling", true); }
    if (var0 & 2) { s.store_field("url", url_); }
    if (var0 & 4) { s.store_field("html", html_); }
    if (var0 & 16) { s.store_field("poster_photo_id", poster_photo_id_); }
    if (var0 & 32) { s.store_field("w", w_); }
    if (var0 & 32) { s.store_field("h", h_); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockEmbedPost::pageBlockEmbedPost(string const &url_, int64 webpage_id_, int64 author_photo_id_, string const &author_, int32 date_, array<object_ptr<PageBlock>> &&blocks_, object_ptr<pageCaption> &&caption_)
  : url_(url_)
  , webpage_id_(webpage_id_)
  , author_photo_id_(author_photo_id_)
  , author_(author_)
  , date_(date_)
  , blocks_(std::move(blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockEmbedPost::ID;

object_ptr<PageBlock> pageBlockEmbedPost::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockEmbedPost>(p);
}

pageBlockEmbedPost::pageBlockEmbedPost(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , webpage_id_(TlFetchLong::parse(p))
  , author_photo_id_(TlFetchLong::parse(p))
  , author_(TlFetchString<string>::parse(p))
  , date_(TlFetchInt::parse(p))
  , blocks_(TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void pageBlockEmbedPost::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
  TlStoreBinary::store(author_photo_id_, s);
  TlStoreString::store(author_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockEmbedPost::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
  TlStoreBinary::store(author_photo_id_, s);
  TlStoreString::store(author_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockEmbedPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockEmbedPost");
    s.store_field("url", url_);
    s.store_field("webpage_id", webpage_id_);
    s.store_field("author_photo_id", author_photo_id_);
    s.store_field("author", author_);
    s.store_field("date", date_);
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockCollage::pageBlockCollage(array<object_ptr<PageBlock>> &&items_, object_ptr<pageCaption> &&caption_)
  : items_(std::move(items_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockCollage::ID;

object_ptr<PageBlock> pageBlockCollage::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockCollage>(p);
}

pageBlockCollage::pageBlockCollage(TlBufferParser &p)
  : items_(TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void pageBlockCollage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockCollage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockCollage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCollage");
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockSlideshow::pageBlockSlideshow(array<object_ptr<PageBlock>> &&items_, object_ptr<pageCaption> &&caption_)
  : items_(std::move(items_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockSlideshow::ID;

object_ptr<PageBlock> pageBlockSlideshow::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockSlideshow>(p);
}

pageBlockSlideshow::pageBlockSlideshow(TlBufferParser &p)
  : items_(TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void pageBlockSlideshow::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockSlideshow::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockSlideshow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSlideshow");
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockChannel::pageBlockChannel(object_ptr<Chat> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t pageBlockChannel::ID;

object_ptr<PageBlock> pageBlockChannel::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockChannel>(p);
}

pageBlockChannel::pageBlockChannel(TlBufferParser &p)
  : channel_(TlFetchObject<Chat>::parse(p))
{}

void pageBlockChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void pageBlockChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void pageBlockChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

pageBlockAudio::pageBlockAudio(int64 audio_id_, object_ptr<pageCaption> &&caption_)
  : audio_id_(audio_id_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockAudio::ID;

object_ptr<PageBlock> pageBlockAudio::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockAudio>(p);
}

pageBlockAudio::pageBlockAudio(TlBufferParser &p)
  : audio_id_(TlFetchLong::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void pageBlockAudio::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(audio_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockAudio::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(audio_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAudio");
    s.store_field("audio_id", audio_id_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockKicker::pageBlockKicker(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockKicker::ID;

object_ptr<PageBlock> pageBlockKicker::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockKicker>(p);
}

pageBlockKicker::pageBlockKicker(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockKicker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockKicker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockKicker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockKicker");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockTable::pageBlockTable()
  : flags_()
  , bordered_()
  , striped_()
  , compact_()
  , title_()
  , rows_()
{}

pageBlockTable::pageBlockTable(int32 flags_, bool bordered_, bool striped_, bool compact_, object_ptr<RichText> &&title_, array<object_ptr<pageTableRow>> &&rows_)
  : flags_(flags_)
  , bordered_(bordered_)
  , striped_(striped_)
  , compact_(compact_)
  , title_(std::move(title_))
  , rows_(std::move(rows_))
{}

const std::int32_t pageBlockTable::ID;

object_ptr<PageBlock> pageBlockTable::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockTable> res = make_tl_object<pageBlockTable>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bordered_ = (var0 & 1) != 0;
  res->striped_ = (var0 & 2) != 0;
  res->compact_ = (var0 & 4) != 0;
  res->title_ = TlFetchObject<RichText>::parse(p);
  res->rows_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<pageTableRow>, -524237339>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockTable::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bordered_ << 0) | (striped_ << 1) | (compact_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -524237339>>, 481674261>::store(rows_, s);
}

void pageBlockTable::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bordered_ << 0) | (striped_ << 1) | (compact_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -524237339>>, 481674261>::store(rows_, s);
}

void pageBlockTable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTable");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (bordered_ << 0) | (striped_ << 1) | (compact_ << 2)));
    if (var0 & 1) { s.store_field("bordered", true); }
    if (var0 & 2) { s.store_field("striped", true); }
    if (var0 & 4) { s.store_field("compact", true); }
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockOrderedList::pageBlockOrderedList()
  : flags_()
  , reversed_()
  , items_()
  , start_()
  , type_()
{}

pageBlockOrderedList::pageBlockOrderedList(int32 flags_, bool reversed_, array<object_ptr<PageListOrderedItem>> &&items_, int32 start_, string const &type_)
  : flags_(flags_)
  , reversed_(reversed_)
  , items_(std::move(items_))
  , start_(start_)
  , type_(type_)
{}

const std::int32_t pageBlockOrderedList::ID;

object_ptr<PageBlock> pageBlockOrderedList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockOrderedList> res = make_tl_object<pageBlockOrderedList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->reversed_ = (var0 & 4) != 0;
  res->items_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PageListOrderedItem>>, 481674261>::parse(p);
  if (var0 & 1) { res->start_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->type_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockOrderedList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (reversed_ << 2) | ((!type_.empty()) << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
  if (var0 & 1) { TlStoreBinary::store(start_, s); }
  if (var0 & 2) { TlStoreString::store(type_, s); }
}

void pageBlockOrderedList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (reversed_ << 2) | ((!type_.empty()) << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
  if (var0 & 1) { TlStoreBinary::store(start_, s); }
  if (var0 & 2) { TlStoreString::store(type_, s); }
}

void pageBlockOrderedList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockOrderedList");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (reversed_ << 2) | ((!type_.empty()) << 1)));
    if (var0 & 4) { s.store_field("reversed", true); }
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("start", start_); }
    if (var0 & 2) { s.store_field("type", type_); }
    s.store_class_end();
  }
}

pageBlockDetails::pageBlockDetails()
  : flags_()
  , open_()
  , blocks_()
  , title_()
{}

pageBlockDetails::pageBlockDetails(int32 flags_, bool open_, array<object_ptr<PageBlock>> &&blocks_, object_ptr<RichText> &&title_)
  : flags_(flags_)
  , open_(open_)
  , blocks_(std::move(blocks_))
  , title_(std::move(title_))
{}

const std::int32_t pageBlockDetails::ID;

object_ptr<PageBlock> pageBlockDetails::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockDetails> res = make_tl_object<pageBlockDetails>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->open_ = (var0 & 1) != 0;
  res->blocks_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p);
  res->title_ = TlFetchObject<RichText>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockDetails::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (open_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
}

void pageBlockDetails::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (open_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
}

void pageBlockDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDetails");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (open_ << 0)));
    if (var0 & 1) { s.store_field("open", true); }
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    s.store_class_end();
  }
}

pageBlockRelatedArticles::pageBlockRelatedArticles(object_ptr<RichText> &&title_, array<object_ptr<pageRelatedArticle>> &&articles_)
  : title_(std::move(title_))
  , articles_(std::move(articles_))
{}

const std::int32_t pageBlockRelatedArticles::ID;

object_ptr<PageBlock> pageBlockRelatedArticles::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockRelatedArticles>(p);
}

pageBlockRelatedArticles::pageBlockRelatedArticles(TlBufferParser &p)
  : title_(TlFetchObject<RichText>::parse(p))
  , articles_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<pageRelatedArticle>, -1282352120>>, 481674261>::parse(p))
{}

void pageBlockRelatedArticles::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1282352120>>, 481674261>::store(articles_, s);
}

void pageBlockRelatedArticles::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1282352120>>, 481674261>::store(articles_, s);
}

void pageBlockRelatedArticles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockRelatedArticles");
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    { s.store_vector_begin("articles", articles_.size()); for (const auto &_value : articles_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockMap::pageBlockMap(object_ptr<GeoPoint> &&geo_, int32 zoom_, int32 w_, int32 h_, object_ptr<pageCaption> &&caption_)
  : geo_(std::move(geo_))
  , zoom_(zoom_)
  , w_(w_)
  , h_(h_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockMap::ID;

object_ptr<PageBlock> pageBlockMap::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockMap>(p);
}

pageBlockMap::pageBlockMap(TlBufferParser &p)
  : geo_(TlFetchObject<GeoPoint>::parse(p))
  , zoom_(TlFetchInt::parse(p))
  , w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void pageBlockMap::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreBinary::store(zoom_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockMap::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreBinary::store(zoom_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockMap::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockMap");
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    s.store_field("zoom", zoom_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockHeading1::pageBlockHeading1(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockHeading1::ID;

object_ptr<PageBlock> pageBlockHeading1::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockHeading1>(p);
}

pageBlockHeading1::pageBlockHeading1(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockHeading1::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading1::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading1::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHeading1");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockHeading2::pageBlockHeading2(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockHeading2::ID;

object_ptr<PageBlock> pageBlockHeading2::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockHeading2>(p);
}

pageBlockHeading2::pageBlockHeading2(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockHeading2::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading2::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading2::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHeading2");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockHeading3::pageBlockHeading3(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockHeading3::ID;

object_ptr<PageBlock> pageBlockHeading3::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockHeading3>(p);
}

pageBlockHeading3::pageBlockHeading3(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockHeading3::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading3::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading3::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHeading3");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockHeading4::pageBlockHeading4(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockHeading4::ID;

object_ptr<PageBlock> pageBlockHeading4::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockHeading4>(p);
}

pageBlockHeading4::pageBlockHeading4(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockHeading4::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading4::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading4::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHeading4");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockHeading5::pageBlockHeading5(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockHeading5::ID;

object_ptr<PageBlock> pageBlockHeading5::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockHeading5>(p);
}

pageBlockHeading5::pageBlockHeading5(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockHeading5::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading5::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading5::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHeading5");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockHeading6::pageBlockHeading6(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockHeading6::ID;

object_ptr<PageBlock> pageBlockHeading6::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockHeading6>(p);
}

pageBlockHeading6::pageBlockHeading6(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockHeading6::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading6::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeading6::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHeading6");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockMath::pageBlockMath(string const &source_)
  : source_(source_)
{}

const std::int32_t pageBlockMath::ID;

object_ptr<PageBlock> pageBlockMath::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockMath>(p);
}

pageBlockMath::pageBlockMath(TlBufferParser &p)
  : source_(TlFetchString<string>::parse(p))
{}

void pageBlockMath::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(source_, s);
}

void pageBlockMath::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(source_, s);
}

void pageBlockMath::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockMath");
    s.store_field("source", source_);
    s.store_class_end();
  }
}

pageBlockThinking::pageBlockThinking(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockThinking::ID;

object_ptr<PageBlock> pageBlockThinking::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockThinking>(p);
}

pageBlockThinking::pageBlockThinking(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockThinking::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockThinking::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockThinking::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockThinking");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

inputPageBlockMap::inputPageBlockMap(object_ptr<InputGeoPoint> &&geo_, int32 zoom_, int32 w_, int32 h_, object_ptr<pageCaption> &&caption_)
  : geo_(std::move(geo_))
  , zoom_(zoom_)
  , w_(w_)
  , h_(h_)
  , caption_(std::move(caption_))
{}

const std::int32_t inputPageBlockMap::ID;

object_ptr<PageBlock> inputPageBlockMap::fetch(TlBufferParser &p) {
  return make_tl_object<inputPageBlockMap>(p);
}

inputPageBlockMap::inputPageBlockMap(TlBufferParser &p)
  : geo_(TlFetchObject<InputGeoPoint>::parse(p))
  , zoom_(TlFetchInt::parse(p))
  , w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void inputPageBlockMap::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreBinary::store(zoom_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void inputPageBlockMap::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreBinary::store(zoom_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void inputPageBlockMap::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockMap");
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    s.store_field("zoom", zoom_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockBlockquoteBlocks::pageBlockBlockquoteBlocks()
  : flags_()
  , collapsed_()
  , blocks_()
  , caption_()
{}

pageBlockBlockquoteBlocks::pageBlockBlockquoteBlocks(int32 flags_, bool collapsed_, array<object_ptr<PageBlock>> &&blocks_, object_ptr<RichText> &&caption_)
  : flags_(flags_)
  , collapsed_(collapsed_)
  , blocks_(std::move(blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockBlockquoteBlocks::ID;

object_ptr<PageBlock> pageBlockBlockquoteBlocks::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockBlockquoteBlocks> res = make_tl_object<pageBlockBlockquoteBlocks>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collapsed_ = (var0 & 1) != 0;
  res->blocks_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p);
  res->caption_ = TlFetchObject<RichText>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockBlockquoteBlocks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (collapsed_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(caption_, s);
}

void pageBlockBlockquoteBlocks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (collapsed_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(caption_, s);
}

void pageBlockBlockquoteBlocks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockBlockquoteBlocks");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (collapsed_ << 0)));
    if (var0 & 1) { s.store_field("collapsed", true); }
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockButtonRow::pageBlockButtonRow()
  : flags_()
  , align_left_()
  , align_center_()
  , align_right_()
  , buttons_()
{}

pageBlockButtonRow::pageBlockButtonRow(int32 flags_, bool align_left_, bool align_center_, bool align_right_, array<object_ptr<pageButton>> &&buttons_)
  : flags_(flags_)
  , align_left_(align_left_)
  , align_center_(align_center_)
  , align_right_(align_right_)
  , buttons_(std::move(buttons_))
{}

const std::int32_t pageBlockButtonRow::ID;

object_ptr<PageBlock> pageBlockButtonRow::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockButtonRow> res = make_tl_object<pageBlockButtonRow>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->align_left_ = (var0 & 1) != 0;
  res->align_center_ = (var0 & 2) != 0;
  res->align_right_ = (var0 & 4) != 0;
  res->buttons_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<pageButton>, 1764381832>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockButtonRow::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (align_left_ << 0) | (align_center_ << 1) | (align_right_ << 2)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1764381832>>, 481674261>::store(buttons_, s);
}

void pageBlockButtonRow::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (align_left_ << 0) | (align_center_ << 1) | (align_right_ << 2)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1764381832>>, 481674261>::store(buttons_, s);
}

void pageBlockButtonRow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockButtonRow");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (align_left_ << 0) | (align_center_ << 1) | (align_right_ << 2)));
    if (var0 & 1) { s.store_field("align_left", true); }
    if (var0 & 2) { s.store_field("align_center", true); }
    if (var0 & 4) { s.store_field("align_right", true); }
    { s.store_vector_begin("buttons", buttons_.size()); for (const auto &_value : buttons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockDocument::pageBlockDocument(int64 document_id_, object_ptr<pageCaption> &&caption_)
  : document_id_(document_id_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockDocument::ID;

object_ptr<PageBlock> pageBlockDocument::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockDocument>(p);
}

pageBlockDocument::pageBlockDocument(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void pageBlockDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDocument");
    s.store_field("document_id", document_id_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

object_ptr<PageListItem> PageListItem::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case pageListItemText::ID:
      return pageListItemText::fetch(p);
    case pageListItemBlocks::ID:
      return pageListItemBlocks::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

pageListItemText::pageListItemText()
  : flags_()
  , checkbox_()
  , checked_()
  , text_()
{}

pageListItemText::pageListItemText(int32 flags_, bool checkbox_, bool checked_, object_ptr<RichText> &&text_)
  : flags_(flags_)
  , checkbox_(checkbox_)
  , checked_(checked_)
  , text_(std::move(text_))
{}

const std::int32_t pageListItemText::ID;

object_ptr<PageListItem> pageListItemText::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageListItemText> res = make_tl_object<pageListItemText>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->checkbox_ = (var0 & 1) != 0;
  res->checked_ = (var0 & 2) != 0;
  res->text_ = TlFetchObject<RichText>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageListItemText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (checkbox_ << 0) | (checked_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageListItemText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (checkbox_ << 0) | (checked_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageListItemText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageListItemText");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (checkbox_ << 0) | (checked_ << 1)));
    if (var0 & 1) { s.store_field("checkbox", true); }
    if (var0 & 2) { s.store_field("checked", true); }
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageListItemBlocks::pageListItemBlocks()
  : flags_()
  , checkbox_()
  , checked_()
  , blocks_()
{}

pageListItemBlocks::pageListItemBlocks(int32 flags_, bool checkbox_, bool checked_, array<object_ptr<PageBlock>> &&blocks_)
  : flags_(flags_)
  , checkbox_(checkbox_)
  , checked_(checked_)
  , blocks_(std::move(blocks_))
{}

const std::int32_t pageListItemBlocks::ID;

object_ptr<PageListItem> pageListItemBlocks::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageListItemBlocks> res = make_tl_object<pageListItemBlocks>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->checkbox_ = (var0 & 1) != 0;
  res->checked_ = (var0 & 2) != 0;
  res->blocks_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageListItemBlocks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (checkbox_ << 0) | (checked_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
}

void pageListItemBlocks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (checkbox_ << 0) | (checked_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
}

void pageListItemBlocks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageListItemBlocks");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (checkbox_ << 0) | (checked_ << 1)));
    if (var0 & 1) { s.store_field("checkbox", true); }
    if (var0 & 2) { s.store_field("checked", true); }
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

paymentRequestedInfo::paymentRequestedInfo()
  : flags_()
  , name_()
  , phone_()
  , email_()
  , shipping_address_()
{}

paymentRequestedInfo::paymentRequestedInfo(int32 flags_, string const &name_, string const &phone_, string const &email_, object_ptr<postAddress> &&shipping_address_)
  : flags_(flags_)
  , name_(name_)
  , phone_(phone_)
  , email_(email_)
  , shipping_address_(std::move(shipping_address_))
{}

const std::int32_t paymentRequestedInfo::ID;

object_ptr<paymentRequestedInfo> paymentRequestedInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<paymentRequestedInfo> res = make_tl_object<paymentRequestedInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->name_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->phone_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->email_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->shipping_address_ = TlFetchBoxed<TlFetchObject<postAddress>, 512535275>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void paymentRequestedInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!name_.empty()) << 0) | ((!phone_.empty()) << 1) | ((!email_.empty()) << 2) | ((shipping_address_ != nullptr) << 3)), s);
  if (var0 & 1) { TlStoreString::store(name_, s); }
  if (var0 & 2) { TlStoreString::store(phone_, s); }
  if (var0 & 4) { TlStoreString::store(email_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 512535275>::store(shipping_address_, s); }
}

void paymentRequestedInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!name_.empty()) << 0) | ((!phone_.empty()) << 1) | ((!email_.empty()) << 2) | ((shipping_address_ != nullptr) << 3)), s);
  if (var0 & 1) { TlStoreString::store(name_, s); }
  if (var0 & 2) { TlStoreString::store(phone_, s); }
  if (var0 & 4) { TlStoreString::store(email_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 512535275>::store(shipping_address_, s); }
}

void paymentRequestedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentRequestedInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!name_.empty()) << 0) | ((!phone_.empty()) << 1) | ((!email_.empty()) << 2) | ((shipping_address_ != nullptr) << 3)));
    if (var0 & 1) { s.store_field("name", name_); }
    if (var0 & 2) { s.store_field("phone", phone_); }
    if (var0 & 4) { s.store_field("email", email_); }
    if (var0 & 8) { s.store_object_field("shipping_address", static_cast<const BaseObject *>(shipping_address_.get())); }
    s.store_class_end();
  }
}

object_ptr<PhoneCall> PhoneCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case phoneCallEmpty::ID:
      return phoneCallEmpty::fetch(p);
    case phoneCallWaiting::ID:
      return phoneCallWaiting::fetch(p);
    case phoneCallRequested::ID:
      return phoneCallRequested::fetch(p);
    case phoneCallAccepted::ID:
      return phoneCallAccepted::fetch(p);
    case phoneCall::ID:
      return phoneCall::fetch(p);
    case phoneCallDiscarded::ID:
      return phoneCallDiscarded::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t phoneCallEmpty::ID;

object_ptr<PhoneCall> phoneCallEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallEmpty>(p);
}

phoneCallEmpty::phoneCallEmpty(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void phoneCallEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

phoneCallWaiting::phoneCallWaiting()
  : flags_()
  , video_()
  , id_()
  , access_hash_()
  , date_()
  , admin_id_()
  , participant_id_()
  , protocol_()
  , receive_date_()
{}

const std::int32_t phoneCallWaiting::ID;

object_ptr<PhoneCall> phoneCallWaiting::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCallWaiting> res = make_tl_object<phoneCallWaiting>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->video_ = (var0 & 64) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->participant_id_ = TlFetchLong::parse(p);
  res->protocol_ = TlFetchBoxed<TlFetchObject<phoneCallProtocol>, -58224696>::parse(p);
  if (var0 & 1) { res->receive_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneCallWaiting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallWaiting");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (video_ << 6)));
    if (var0 & 64) { s.store_field("video", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    if (var0 & 1) { s.store_field("receive_date", receive_date_); }
    s.store_class_end();
  }
}

phoneCallRequested::phoneCallRequested()
  : flags_()
  , video_()
  , id_()
  , access_hash_()
  , date_()
  , admin_id_()
  , participant_id_()
  , g_a_hash_()
  , protocol_()
{}

const std::int32_t phoneCallRequested::ID;

object_ptr<PhoneCall> phoneCallRequested::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCallRequested> res = make_tl_object<phoneCallRequested>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->video_ = (var0 & 64) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->participant_id_ = TlFetchLong::parse(p);
  res->g_a_hash_ = TlFetchBytes<bytes>::parse(p);
  res->protocol_ = TlFetchBoxed<TlFetchObject<phoneCallProtocol>, -58224696>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneCallRequested::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallRequested");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (video_ << 6)));
    if (var0 & 64) { s.store_field("video", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_bytes_field("g_a_hash", g_a_hash_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

phoneCallAccepted::phoneCallAccepted()
  : flags_()
  , video_()
  , id_()
  , access_hash_()
  , date_()
  , admin_id_()
  , participant_id_()
  , g_b_()
  , protocol_()
{}

const std::int32_t phoneCallAccepted::ID;

object_ptr<PhoneCall> phoneCallAccepted::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCallAccepted> res = make_tl_object<phoneCallAccepted>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->video_ = (var0 & 64) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->participant_id_ = TlFetchLong::parse(p);
  res->g_b_ = TlFetchBytes<bytes>::parse(p);
  res->protocol_ = TlFetchBoxed<TlFetchObject<phoneCallProtocol>, -58224696>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneCallAccepted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallAccepted");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (video_ << 6)));
    if (var0 & 64) { s.store_field("video", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_bytes_field("g_b", g_b_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

phoneCall::phoneCall()
  : flags_()
  , p2p_allowed_()
  , video_()
  , conference_supported_()
  , id_()
  , access_hash_()
  , date_()
  , admin_id_()
  , participant_id_()
  , g_a_or_b_()
  , key_fingerprint_()
  , protocol_()
  , connections_()
  , start_date_()
  , custom_parameters_()
{}

const std::int32_t phoneCall::ID;

object_ptr<PhoneCall> phoneCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCall> res = make_tl_object<phoneCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->p2p_allowed_ = (var0 & 32) != 0;
  res->video_ = (var0 & 64) != 0;
  res->conference_supported_ = (var0 & 256) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->participant_id_ = TlFetchLong::parse(p);
  res->g_a_or_b_ = TlFetchBytes<bytes>::parse(p);
  res->key_fingerprint_ = TlFetchLong::parse(p);
  res->protocol_ = TlFetchBoxed<TlFetchObject<phoneCallProtocol>, -58224696>::parse(p);
  res->connections_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PhoneConnection>>, 481674261>::parse(p);
  res->start_date_ = TlFetchInt::parse(p);
  if (var0 & 128) { res->custom_parameters_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (p2p_allowed_ << 5) | (video_ << 6) | (conference_supported_ << 8) | ((custom_parameters_ != nullptr) << 7)));
    if (var0 & 32) { s.store_field("p2p_allowed", true); }
    if (var0 & 64) { s.store_field("video", true); }
    if (var0 & 256) { s.store_field("conference_supported", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_bytes_field("g_a_or_b", g_a_or_b_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    { s.store_vector_begin("connections", connections_.size()); for (const auto &_value : connections_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("start_date", start_date_);
    if (var0 & 128) { s.store_object_field("custom_parameters", static_cast<const BaseObject *>(custom_parameters_.get())); }
    s.store_class_end();
  }
}

phoneCallDiscarded::phoneCallDiscarded()
  : flags_()
  , need_rating_()
  , need_debug_()
  , video_()
  , id_()
  , reason_()
  , duration_()
{}

const std::int32_t phoneCallDiscarded::ID;

object_ptr<PhoneCall> phoneCallDiscarded::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCallDiscarded> res = make_tl_object<phoneCallDiscarded>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->need_rating_ = (var0 & 4) != 0;
  res->need_debug_ = (var0 & 8) != 0;
  res->video_ = (var0 & 64) != 0;
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->reason_ = TlFetchObject<PhoneCallDiscardReason>::parse(p); }
  if (var0 & 2) { res->duration_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneCallDiscarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscarded");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (need_rating_ << 2) | (need_debug_ << 3) | (video_ << 6) | ((reason_ != nullptr) << 0)));
    if (var0 & 4) { s.store_field("need_rating", true); }
    if (var0 & 8) { s.store_field("need_debug", true); }
    if (var0 & 64) { s.store_field("video", true); }
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get())); }
    if (var0 & 2) { s.store_field("duration", duration_); }
    s.store_class_end();
  }
}

object_ptr<PhoneConnection> PhoneConnection::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case phoneConnection::ID:
      return phoneConnection::fetch(p);
    case phoneConnectionWebrtc::ID:
      return phoneConnectionWebrtc::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

phoneConnection::phoneConnection()
  : flags_()
  , tcp_()
  , id_()
  , ip_()
  , ipv6_()
  , port_()
  , peer_tag_()
{}

const std::int32_t phoneConnection::ID;

object_ptr<PhoneConnection> phoneConnection::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneConnection> res = make_tl_object<phoneConnection>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->tcp_ = (var0 & 1) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->ip_ = TlFetchString<string>::parse(p);
  res->ipv6_ = TlFetchString<string>::parse(p);
  res->port_ = TlFetchInt::parse(p);
  res->peer_tag_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneConnection");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (tcp_ << 0)));
    if (var0 & 1) { s.store_field("tcp", true); }
    s.store_field("id", id_);
    s.store_field("ip", ip_);
    s.store_field("ipv6", ipv6_);
    s.store_field("port", port_);
    s.store_bytes_field("peer_tag", peer_tag_);
    s.store_class_end();
  }
}

phoneConnectionWebrtc::phoneConnectionWebrtc()
  : flags_()
  , turn_()
  , stun_()
  , id_()
  , ip_()
  , ipv6_()
  , port_()
  , username_()
  , password_()
{}

const std::int32_t phoneConnectionWebrtc::ID;

object_ptr<PhoneConnection> phoneConnectionWebrtc::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneConnectionWebrtc> res = make_tl_object<phoneConnectionWebrtc>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->turn_ = (var0 & 1) != 0;
  res->stun_ = (var0 & 2) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->ip_ = TlFetchString<string>::parse(p);
  res->ipv6_ = TlFetchString<string>::parse(p);
  res->port_ = TlFetchInt::parse(p);
  res->username_ = TlFetchString<string>::parse(p);
  res->password_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneConnectionWebrtc::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneConnectionWebrtc");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (turn_ << 0) | (stun_ << 1)));
    if (var0 & 1) { s.store_field("turn", true); }
    if (var0 & 2) { s.store_field("stun", true); }
    s.store_field("id", id_);
    s.store_field("ip", ip_);
    s.store_field("ipv6", ipv6_);
    s.store_field("port", port_);
    s.store_field("username", username_);
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

object_ptr<PrepaidGiveaway> PrepaidGiveaway::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case prepaidGiveaway::ID:
      return prepaidGiveaway::fetch(p);
    case prepaidStarsGiveaway::ID:
      return prepaidStarsGiveaway::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t prepaidGiveaway::ID;

object_ptr<PrepaidGiveaway> prepaidGiveaway::fetch(TlBufferParser &p) {
  return make_tl_object<prepaidGiveaway>(p);
}

prepaidGiveaway::prepaidGiveaway(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , months_(TlFetchInt::parse(p))
  , quantity_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void prepaidGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "prepaidGiveaway");
    s.store_field("id", id_);
    s.store_field("months", months_);
    s.store_field("quantity", quantity_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t prepaidStarsGiveaway::ID;

object_ptr<PrepaidGiveaway> prepaidStarsGiveaway::fetch(TlBufferParser &p) {
  return make_tl_object<prepaidStarsGiveaway>(p);
}

prepaidStarsGiveaway::prepaidStarsGiveaway(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , stars_(TlFetchLong::parse(p))
  , quantity_(TlFetchInt::parse(p))
  , boosts_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void prepaidStarsGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "prepaidStarsGiveaway");
    s.store_field("id", id_);
    s.store_field("stars", stars_);
    s.store_field("quantity", quantity_);
    s.store_field("boosts", boosts_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<Reaction> Reaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case reactionEmpty::ID:
      return reactionEmpty::fetch(p);
    case reactionEmoji::ID:
      return reactionEmoji::fetch(p);
    case reactionCustomEmoji::ID:
      return reactionCustomEmoji::fetch(p);
    case reactionPaid::ID:
      return reactionPaid::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t reactionEmpty::ID;

object_ptr<Reaction> reactionEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<reactionEmpty>();
}

void reactionEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void reactionEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void reactionEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionEmpty");
    s.store_class_end();
  }
}

reactionEmoji::reactionEmoji(string const &emoticon_)
  : emoticon_(emoticon_)
{}

const std::int32_t reactionEmoji::ID;

object_ptr<Reaction> reactionEmoji::fetch(TlBufferParser &p) {
  return make_tl_object<reactionEmoji>(p);
}

reactionEmoji::reactionEmoji(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
{}

void reactionEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void reactionEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void reactionEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionEmoji");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

reactionCustomEmoji::reactionCustomEmoji(int64 document_id_)
  : document_id_(document_id_)
{}

const std::int32_t reactionCustomEmoji::ID;

object_ptr<Reaction> reactionCustomEmoji::fetch(TlBufferParser &p) {
  return make_tl_object<reactionCustomEmoji>(p);
}

reactionCustomEmoji::reactionCustomEmoji(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
{}

void reactionCustomEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void reactionCustomEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void reactionCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionCustomEmoji");
    s.store_field("document_id", document_id_);
    s.store_class_end();
  }
}

const std::int32_t reactionPaid::ID;

object_ptr<Reaction> reactionPaid::fetch(TlBufferParser &p) {
  return make_tl_object<reactionPaid>();
}

void reactionPaid::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void reactionPaid::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void reactionPaid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionPaid");
    s.store_class_end();
  }
}

reactionsNotifySettings::reactionsNotifySettings()
  : flags_()
  , messages_notify_from_()
  , stories_notify_from_()
  , poll_votes_notify_from_()
  , sound_()
  , show_previews_()
{}

reactionsNotifySettings::reactionsNotifySettings(int32 flags_, object_ptr<ReactionNotificationsFrom> &&messages_notify_from_, object_ptr<ReactionNotificationsFrom> &&stories_notify_from_, object_ptr<ReactionNotificationsFrom> &&poll_votes_notify_from_, object_ptr<NotificationSound> &&sound_, bool show_previews_)
  : flags_(flags_)
  , messages_notify_from_(std::move(messages_notify_from_))
  , stories_notify_from_(std::move(stories_notify_from_))
  , poll_votes_notify_from_(std::move(poll_votes_notify_from_))
  , sound_(std::move(sound_))
  , show_previews_(show_previews_)
{}

const std::int32_t reactionsNotifySettings::ID;

object_ptr<reactionsNotifySettings> reactionsNotifySettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<reactionsNotifySettings> res = make_tl_object<reactionsNotifySettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->messages_notify_from_ = TlFetchObject<ReactionNotificationsFrom>::parse(p); }
  if (var0 & 2) { res->stories_notify_from_ = TlFetchObject<ReactionNotificationsFrom>::parse(p); }
  if (var0 & 4) { res->poll_votes_notify_from_ = TlFetchObject<ReactionNotificationsFrom>::parse(p); }
  res->sound_ = TlFetchObject<NotificationSound>::parse(p);
  res->show_previews_ = TlFetchBool::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void reactionsNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((messages_notify_from_ != nullptr) << 0) | ((stories_notify_from_ != nullptr) << 1) | ((poll_votes_notify_from_ != nullptr) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(messages_notify_from_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(stories_notify_from_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(poll_votes_notify_from_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(sound_, s);
  TlStoreBool::store(show_previews_, s);
}

void reactionsNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((messages_notify_from_ != nullptr) << 0) | ((stories_notify_from_ != nullptr) << 1) | ((poll_votes_notify_from_ != nullptr) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(messages_notify_from_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(stories_notify_from_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(poll_votes_notify_from_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(sound_, s);
  TlStoreBool::store(show_previews_, s);
}

void reactionsNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionsNotifySettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((messages_notify_from_ != nullptr) << 0) | ((stories_notify_from_ != nullptr) << 1) | ((poll_votes_notify_from_ != nullptr) << 2)));
    if (var0 & 1) { s.store_object_field("messages_notify_from", static_cast<const BaseObject *>(messages_notify_from_.get())); }
    if (var0 & 2) { s.store_object_field("stories_notify_from", static_cast<const BaseObject *>(stories_notify_from_.get())); }
    if (var0 & 4) { s.store_object_field("poll_votes_notify_from", static_cast<const BaseObject *>(poll_votes_notify_from_.get())); }
    s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get()));
    s.store_field("show_previews", show_previews_);
    s.store_class_end();
  }
}

object_ptr<RequestPeerType> RequestPeerType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case requestPeerTypeUser::ID:
      return requestPeerTypeUser::fetch(p);
    case requestPeerTypeChat::ID:
      return requestPeerTypeChat::fetch(p);
    case requestPeerTypeBroadcast::ID:
      return requestPeerTypeBroadcast::fetch(p);
    case requestPeerTypeCreateBot::ID:
      return requestPeerTypeCreateBot::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

requestPeerTypeUser::requestPeerTypeUser()
  : flags_()
  , bot_()
  , premium_()
{}

requestPeerTypeUser::requestPeerTypeUser(int32 flags_, bool bot_, bool premium_)
  : flags_(flags_)
  , bot_(bot_)
  , premium_(premium_)
{}

const std::int32_t requestPeerTypeUser::ID;

object_ptr<RequestPeerType> requestPeerTypeUser::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestPeerTypeUser> res = make_tl_object<requestPeerTypeUser>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->bot_ = TlFetchBool::parse(p); }
  if (var0 & 2) { res->premium_ = TlFetchBool::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestPeerTypeUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBool::store(bot_, s); }
  if (var0 & 2) { TlStoreBool::store(premium_, s); }
}

void requestPeerTypeUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBool::store(bot_, s); }
  if (var0 & 2) { TlStoreBool::store(premium_, s); }
}

void requestPeerTypeUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestPeerTypeUser");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("bot", bot_); }
    if (var0 & 2) { s.store_field("premium", premium_); }
    s.store_class_end();
  }
}

requestPeerTypeChat::requestPeerTypeChat()
  : flags_()
  , creator_()
  , bot_participant_()
  , has_username_()
  , forum_()
  , user_admin_rights_()
  , bot_admin_rights_()
{}

requestPeerTypeChat::requestPeerTypeChat(int32 flags_, bool creator_, bool bot_participant_, bool has_username_, bool forum_, object_ptr<chatAdminRights> &&user_admin_rights_, object_ptr<chatAdminRights> &&bot_admin_rights_)
  : flags_(flags_)
  , creator_(creator_)
  , bot_participant_(bot_participant_)
  , has_username_(has_username_)
  , forum_(forum_)
  , user_admin_rights_(std::move(user_admin_rights_))
  , bot_admin_rights_(std::move(bot_admin_rights_))
{}

const std::int32_t requestPeerTypeChat::ID;

object_ptr<RequestPeerType> requestPeerTypeChat::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestPeerTypeChat> res = make_tl_object<requestPeerTypeChat>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->bot_participant_ = (var0 & 32) != 0;
  if (var0 & 8) { res->has_username_ = TlFetchBool::parse(p); }
  if (var0 & 16) { res->forum_ = TlFetchBool::parse(p); }
  if (var0 & 2) { res->user_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 4) { res->bot_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestPeerTypeChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (bot_participant_ << 5) | ((user_admin_rights_ != nullptr) << 1) | ((bot_admin_rights_ != nullptr) << 2)), s);
  if (var0 & 8) { TlStoreBool::store(has_username_, s); }
  if (var0 & 16) { TlStoreBool::store(forum_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1605510357>::store(user_admin_rights_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1605510357>::store(bot_admin_rights_, s); }
}

void requestPeerTypeChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (bot_participant_ << 5) | ((user_admin_rights_ != nullptr) << 1) | ((bot_admin_rights_ != nullptr) << 2)), s);
  if (var0 & 8) { TlStoreBool::store(has_username_, s); }
  if (var0 & 16) { TlStoreBool::store(forum_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1605510357>::store(user_admin_rights_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1605510357>::store(bot_admin_rights_, s); }
}

void requestPeerTypeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestPeerTypeChat");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | (bot_participant_ << 5) | ((user_admin_rights_ != nullptr) << 1) | ((bot_admin_rights_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 32) { s.store_field("bot_participant", true); }
    if (var0 & 8) { s.store_field("has_username", has_username_); }
    if (var0 & 16) { s.store_field("forum", forum_); }
    if (var0 & 2) { s.store_object_field("user_admin_rights", static_cast<const BaseObject *>(user_admin_rights_.get())); }
    if (var0 & 4) { s.store_object_field("bot_admin_rights", static_cast<const BaseObject *>(bot_admin_rights_.get())); }
    s.store_class_end();
  }
}

requestPeerTypeBroadcast::requestPeerTypeBroadcast()
  : flags_()
  , creator_()
  , has_username_()
  , user_admin_rights_()
  , bot_admin_rights_()
{}

requestPeerTypeBroadcast::requestPeerTypeBroadcast(int32 flags_, bool creator_, bool has_username_, object_ptr<chatAdminRights> &&user_admin_rights_, object_ptr<chatAdminRights> &&bot_admin_rights_)
  : flags_(flags_)
  , creator_(creator_)
  , has_username_(has_username_)
  , user_admin_rights_(std::move(user_admin_rights_))
  , bot_admin_rights_(std::move(bot_admin_rights_))
{}

const std::int32_t requestPeerTypeBroadcast::ID;

object_ptr<RequestPeerType> requestPeerTypeBroadcast::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestPeerTypeBroadcast> res = make_tl_object<requestPeerTypeBroadcast>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  if (var0 & 8) { res->has_username_ = TlFetchBool::parse(p); }
  if (var0 & 2) { res->user_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 4) { res->bot_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestPeerTypeBroadcast::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | ((user_admin_rights_ != nullptr) << 1) | ((bot_admin_rights_ != nullptr) << 2)), s);
  if (var0 & 8) { TlStoreBool::store(has_username_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1605510357>::store(user_admin_rights_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1605510357>::store(bot_admin_rights_, s); }
}

void requestPeerTypeBroadcast::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | ((user_admin_rights_ != nullptr) << 1) | ((bot_admin_rights_ != nullptr) << 2)), s);
  if (var0 & 8) { TlStoreBool::store(has_username_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1605510357>::store(user_admin_rights_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1605510357>::store(bot_admin_rights_, s); }
}

void requestPeerTypeBroadcast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestPeerTypeBroadcast");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | ((user_admin_rights_ != nullptr) << 1) | ((bot_admin_rights_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 8) { s.store_field("has_username", has_username_); }
    if (var0 & 2) { s.store_object_field("user_admin_rights", static_cast<const BaseObject *>(user_admin_rights_.get())); }
    if (var0 & 4) { s.store_object_field("bot_admin_rights", static_cast<const BaseObject *>(bot_admin_rights_.get())); }
    s.store_class_end();
  }
}

requestPeerTypeCreateBot::requestPeerTypeCreateBot()
  : flags_()
  , bot_managed_()
  , suggested_name_()
  , suggested_username_()
{}

requestPeerTypeCreateBot::requestPeerTypeCreateBot(int32 flags_, bool bot_managed_, string const &suggested_name_, string const &suggested_username_)
  : flags_(flags_)
  , bot_managed_(bot_managed_)
  , suggested_name_(suggested_name_)
  , suggested_username_(suggested_username_)
{}

const std::int32_t requestPeerTypeCreateBot::ID;

object_ptr<RequestPeerType> requestPeerTypeCreateBot::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestPeerTypeCreateBot> res = make_tl_object<requestPeerTypeCreateBot>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bot_managed_ = (var0 & 1) != 0;
  if (var0 & 2) { res->suggested_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->suggested_username_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestPeerTypeCreateBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bot_managed_ << 0) | ((!suggested_name_.empty()) << 1) | ((!suggested_username_.empty()) << 2)), s);
  if (var0 & 2) { TlStoreString::store(suggested_name_, s); }
  if (var0 & 4) { TlStoreString::store(suggested_username_, s); }
}

void requestPeerTypeCreateBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bot_managed_ << 0) | ((!suggested_name_.empty()) << 1) | ((!suggested_username_.empty()) << 2)), s);
  if (var0 & 2) { TlStoreString::store(suggested_name_, s); }
  if (var0 & 4) { TlStoreString::store(suggested_username_, s); }
}

void requestPeerTypeCreateBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestPeerTypeCreateBot");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (bot_managed_ << 0) | ((!suggested_name_.empty()) << 1) | ((!suggested_username_.empty()) << 2)));
    if (var0 & 1) { s.store_field("bot_managed", true); }
    if (var0 & 2) { s.store_field("suggested_name", suggested_name_); }
    if (var0 & 4) { s.store_field("suggested_username", suggested_username_); }
    s.store_class_end();
  }
}

object_ptr<RequestedPeer> RequestedPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case requestedPeerUser::ID:
      return requestedPeerUser::fetch(p);
    case requestedPeerChat::ID:
      return requestedPeerChat::fetch(p);
    case requestedPeerChannel::ID:
      return requestedPeerChannel::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

requestedPeerUser::requestedPeerUser()
  : flags_()
  , user_id_()
  , first_name_()
  , last_name_()
  , username_()
  , photo_()
{}

const std::int32_t requestedPeerUser::ID;

object_ptr<RequestedPeer> requestedPeerUser::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestedPeerUser> res = make_tl_object<requestedPeerUser>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->first_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->last_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->username_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestedPeerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestedPeerUser");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!first_name_.empty()) << 0) | ((!last_name_.empty()) << 0) | ((!username_.empty()) << 1) | ((photo_ != nullptr) << 2)));
    s.store_field("user_id", user_id_);
    if (var0 & 1) { s.store_field("first_name", first_name_); }
    if (var0 & 1) { s.store_field("last_name", last_name_); }
    if (var0 & 2) { s.store_field("username", username_); }
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_class_end();
  }
}

requestedPeerChat::requestedPeerChat()
  : flags_()
  , chat_id_()
  , title_()
  , photo_()
{}

const std::int32_t requestedPeerChat::ID;

object_ptr<RequestedPeer> requestedPeerChat::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestedPeerChat> res = make_tl_object<requestedPeerChat>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->chat_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestedPeerChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestedPeerChat");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 0) | ((photo_ != nullptr) << 2)));
    s.store_field("chat_id", chat_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_class_end();
  }
}

requestedPeerChannel::requestedPeerChannel()
  : flags_()
  , channel_id_()
  , title_()
  , username_()
  , photo_()
{}

const std::int32_t requestedPeerChannel::ID;

object_ptr<RequestedPeer> requestedPeerChannel::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestedPeerChannel> res = make_tl_object<requestedPeerChannel>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->username_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestedPeerChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestedPeerChannel");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 0) | ((!username_.empty()) << 1) | ((photo_ != nullptr) << 2)));
    s.store_field("channel_id", channel_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("username", username_); }
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_class_end();
  }
}

object_ptr<SavedDialog> SavedDialog::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case savedDialog::ID:
      return savedDialog::fetch(p);
    case monoForumDialog::ID:
      return monoForumDialog::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

savedDialog::savedDialog()
  : flags_()
  , pinned_()
  , peer_()
  , top_message_()
{}

const std::int32_t savedDialog::ID;

object_ptr<SavedDialog> savedDialog::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<savedDialog> res = make_tl_object<savedDialog>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 4) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->top_message_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void savedDialog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedDialog");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 2)));
    if (var0 & 4) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_message", top_message_);
    s.store_class_end();
  }
}

monoForumDialog::monoForumDialog()
  : flags_()
  , unread_mark_()
  , nopaid_messages_exception_()
  , peer_()
  , top_message_()
  , read_inbox_max_id_()
  , read_outbox_max_id_()
  , unread_count_()
  , unread_reactions_count_()
  , draft_()
{}

const std::int32_t monoForumDialog::ID;

object_ptr<SavedDialog> monoForumDialog::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<monoForumDialog> res = make_tl_object<monoForumDialog>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->unread_mark_ = (var0 & 8) != 0;
  res->nopaid_messages_exception_ = (var0 & 16) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->top_message_ = TlFetchInt::parse(p);
  res->read_inbox_max_id_ = TlFetchInt::parse(p);
  res->read_outbox_max_id_ = TlFetchInt::parse(p);
  res->unread_count_ = TlFetchInt::parse(p);
  res->unread_reactions_count_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->draft_ = TlFetchObject<DraftMessage>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void monoForumDialog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "monoForumDialog");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (unread_mark_ << 3) | (nopaid_messages_exception_ << 4) | ((draft_ != nullptr) << 1)));
    if (var0 & 8) { s.store_field("unread_mark", true); }
    if (var0 & 16) { s.store_field("nopaid_messages_exception", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_message", top_message_);
    s.store_field("read_inbox_max_id", read_inbox_max_id_);
    s.store_field("read_outbox_max_id", read_outbox_max_id_);
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_reactions_count", unread_reactions_count_);
    if (var0 & 2) { s.store_object_field("draft", static_cast<const BaseObject *>(draft_.get())); }
    s.store_class_end();
  }
}

secureData::secureData(bytes &&data_, bytes &&data_hash_, bytes &&secret_)
  : data_(std::move(data_))
  , data_hash_(std::move(data_hash_))
  , secret_(std::move(secret_))
{}

const std::int32_t secureData::ID;

object_ptr<secureData> secureData::fetch(TlBufferParser &p) {
  return make_tl_object<secureData>(p);
}

secureData::secureData(TlBufferParser &p)
  : data_(TlFetchBytes<bytes>::parse(p))
  , data_hash_(TlFetchBytes<bytes>::parse(p))
  , secret_(TlFetchBytes<bytes>::parse(p))
{}

void secureData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
  TlStoreString::store(data_hash_, s);
  TlStoreString::store(secret_, s);
}

void secureData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
  TlStoreString::store(data_hash_, s);
  TlStoreString::store(secret_, s);
}

void secureData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureData");
    s.store_bytes_field("data", data_);
    s.store_bytes_field("data_hash", data_hash_);
    s.store_field("secret", "[REDACTED]");
    s.store_class_end();
  }
}

object_ptr<SecureValueType> SecureValueType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case secureValueTypePersonalDetails::ID:
      return secureValueTypePersonalDetails::fetch(p);
    case secureValueTypePassport::ID:
      return secureValueTypePassport::fetch(p);
    case secureValueTypeDriverLicense::ID:
      return secureValueTypeDriverLicense::fetch(p);
    case secureValueTypeIdentityCard::ID:
      return secureValueTypeIdentityCard::fetch(p);
    case secureValueTypeInternalPassport::ID:
      return secureValueTypeInternalPassport::fetch(p);
    case secureValueTypeAddress::ID:
      return secureValueTypeAddress::fetch(p);
    case secureValueTypeUtilityBill::ID:
      return secureValueTypeUtilityBill::fetch(p);
    case secureValueTypeBankStatement::ID:
      return secureValueTypeBankStatement::fetch(p);
    case secureValueTypeRentalAgreement::ID:
      return secureValueTypeRentalAgreement::fetch(p);
    case secureValueTypePassportRegistration::ID:
      return secureValueTypePassportRegistration::fetch(p);
    case secureValueTypeTemporaryRegistration::ID:
      return secureValueTypeTemporaryRegistration::fetch(p);
    case secureValueTypePhone::ID:
      return secureValueTypePhone::fetch(p);
    case secureValueTypeEmail::ID:
      return secureValueTypeEmail::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t secureValueTypePersonalDetails::ID;

object_ptr<SecureValueType> secureValueTypePersonalDetails::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypePersonalDetails>();
}

void secureValueTypePersonalDetails::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypePersonalDetails::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypePersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypePersonalDetails");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypePassport::ID;

object_ptr<SecureValueType> secureValueTypePassport::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypePassport>();
}

void secureValueTypePassport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypePassport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypePassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypePassport");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeDriverLicense::ID;

object_ptr<SecureValueType> secureValueTypeDriverLicense::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeDriverLicense>();
}

void secureValueTypeDriverLicense::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeDriverLicense::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeDriverLicense::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeDriverLicense");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeIdentityCard::ID;

object_ptr<SecureValueType> secureValueTypeIdentityCard::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeIdentityCard>();
}

void secureValueTypeIdentityCard::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeIdentityCard::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeIdentityCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeIdentityCard");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeInternalPassport::ID;

object_ptr<SecureValueType> secureValueTypeInternalPassport::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeInternalPassport>();
}

void secureValueTypeInternalPassport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeInternalPassport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeInternalPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeInternalPassport");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeAddress::ID;

object_ptr<SecureValueType> secureValueTypeAddress::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeAddress>();
}

void secureValueTypeAddress::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeAddress::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeAddress");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeUtilityBill::ID;

object_ptr<SecureValueType> secureValueTypeUtilityBill::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeUtilityBill>();
}

void secureValueTypeUtilityBill::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeUtilityBill::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeUtilityBill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeUtilityBill");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeBankStatement::ID;

object_ptr<SecureValueType> secureValueTypeBankStatement::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeBankStatement>();
}

void secureValueTypeBankStatement::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeBankStatement::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeBankStatement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeBankStatement");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeRentalAgreement::ID;

object_ptr<SecureValueType> secureValueTypeRentalAgreement::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeRentalAgreement>();
}

void secureValueTypeRentalAgreement::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeRentalAgreement::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeRentalAgreement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeRentalAgreement");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypePassportRegistration::ID;

object_ptr<SecureValueType> secureValueTypePassportRegistration::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypePassportRegistration>();
}

void secureValueTypePassportRegistration::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypePassportRegistration::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypePassportRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypePassportRegistration");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeTemporaryRegistration::ID;

object_ptr<SecureValueType> secureValueTypeTemporaryRegistration::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeTemporaryRegistration>();
}

void secureValueTypeTemporaryRegistration::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeTemporaryRegistration::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeTemporaryRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeTemporaryRegistration");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypePhone::ID;

object_ptr<SecureValueType> secureValueTypePhone::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypePhone>();
}

void secureValueTypePhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypePhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypePhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypePhone");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeEmail::ID;

object_ptr<SecureValueType> secureValueTypeEmail::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeEmail>();
}

void secureValueTypeEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeEmail");
    s.store_class_end();
  }
}

object_ptr<StarGift> StarGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starGift::ID:
      return starGift::fetch(p);
    case starGiftUnique::ID:
      return starGiftUnique::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

starGift::starGift()
  : flags_()
  , limited_()
  , sold_out_()
  , birthday_()
  , require_premium_()
  , limited_per_user_()
  , peer_color_available_()
  , auction_()
  , id_()
  , sticker_()
  , stars_()
  , availability_remains_()
  , availability_total_()
  , availability_resale_()
  , convert_stars_()
  , first_sale_date_()
  , last_sale_date_()
  , upgrade_stars_()
  , resell_min_stars_()
  , title_()
  , released_by_()
  , per_user_total_()
  , per_user_remains_()
  , locked_until_date_()
  , auction_slug_()
  , gifts_per_round_()
  , auction_start_date_()
  , upgrade_variants_()
  , background_()
{}

starGift::starGift(int32 flags_, bool limited_, bool sold_out_, bool birthday_, bool require_premium_, bool limited_per_user_, bool peer_color_available_, bool auction_, int64 id_, object_ptr<Document> &&sticker_, int64 stars_, int32 availability_remains_, int32 availability_total_, int64 availability_resale_, int64 convert_stars_, int32 first_sale_date_, int32 last_sale_date_, int64 upgrade_stars_, int64 resell_min_stars_, string const &title_, object_ptr<Peer> &&released_by_, int32 per_user_total_, int32 per_user_remains_, int32 locked_until_date_, string const &auction_slug_, int32 gifts_per_round_, int32 auction_start_date_, int32 upgrade_variants_, object_ptr<starGiftBackground> &&background_)
  : flags_(flags_)
  , limited_(limited_)
  , sold_out_(sold_out_)
  , birthday_(birthday_)
  , require_premium_(require_premium_)
  , limited_per_user_(limited_per_user_)
  , peer_color_available_(peer_color_available_)
  , auction_(auction_)
  , id_(id_)
  , sticker_(std::move(sticker_))
  , stars_(stars_)
  , availability_remains_(availability_remains_)
  , availability_total_(availability_total_)
  , availability_resale_(availability_resale_)
  , convert_stars_(convert_stars_)
  , first_sale_date_(first_sale_date_)
  , last_sale_date_(last_sale_date_)
  , upgrade_stars_(upgrade_stars_)
  , resell_min_stars_(resell_min_stars_)
  , title_(title_)
  , released_by_(std::move(released_by_))
  , per_user_total_(per_user_total_)
  , per_user_remains_(per_user_remains_)
  , locked_until_date_(locked_until_date_)
  , auction_slug_(auction_slug_)
  , gifts_per_round_(gifts_per_round_)
  , auction_start_date_(auction_start_date_)
  , upgrade_variants_(upgrade_variants_)
  , background_(std::move(background_))
{}

const std::int32_t starGift::ID;

object_ptr<StarGift> starGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGift> res = make_tl_object<starGift>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->limited_ = (var0 & 1) != 0;
  res->sold_out_ = (var0 & 2) != 0;
  res->birthday_ = (var0 & 4) != 0;
  res->require_premium_ = (var0 & 128) != 0;
  res->limited_per_user_ = (var0 & 256) != 0;
  res->peer_color_available_ = (var0 & 1024) != 0;
  res->auction_ = (var0 & 2048) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->sticker_ = TlFetchObject<Document>::parse(p);
  res->stars_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->availability_remains_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->availability_total_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->availability_resale_ = TlFetchLong::parse(p); }
  res->convert_stars_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->first_sale_date_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->last_sale_date_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->upgrade_stars_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->resell_min_stars_ = TlFetchLong::parse(p); }
  if (var0 & 32) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 64) { res->released_by_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 256) { res->per_user_total_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->per_user_remains_ = TlFetchInt::parse(p); }
  if (var0 & 512) { res->locked_until_date_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->auction_slug_ = TlFetchString<string>::parse(p); }
  if (var0 & 2048) { res->gifts_per_round_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->auction_start_date_ = TlFetchInt::parse(p); }
  if (var0 & 4096) { res->upgrade_variants_ = TlFetchInt::parse(p); }
  if (var0 & 8192) { res->background_ = TlFetchBoxed<TlFetchObject<starGiftBackground>, -1342872680>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void starGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (limited_ << 0) | (sold_out_ << 1) | (birthday_ << 2) | (require_premium_ << 7) | (limited_per_user_ << 8) | (peer_color_available_ << 10) | (auction_ << 11) | ((!title_.empty()) << 5) | ((released_by_ != nullptr) << 6) | ((!auction_slug_.empty()) << 11) | ((background_ != nullptr) << 13)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBinary::store(stars_, s);
  if (var0 & 1) { TlStoreBinary::store(availability_remains_, s); }
  if (var0 & 1) { TlStoreBinary::store(availability_total_, s); }
  if (var0 & 16) { TlStoreBinary::store(availability_resale_, s); }
  TlStoreBinary::store(convert_stars_, s);
  if (var0 & 2) { TlStoreBinary::store(first_sale_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(last_sale_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(upgrade_stars_, s); }
  if (var0 & 16) { TlStoreBinary::store(resell_min_stars_, s); }
  if (var0 & 32) { TlStoreString::store(title_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(released_by_, s); }
  if (var0 & 256) { TlStoreBinary::store(per_user_total_, s); }
  if (var0 & 256) { TlStoreBinary::store(per_user_remains_, s); }
  if (var0 & 512) { TlStoreBinary::store(locked_until_date_, s); }
  if (var0 & 2048) { TlStoreString::store(auction_slug_, s); }
  if (var0 & 2048) { TlStoreBinary::store(gifts_per_round_, s); }
  if (var0 & 2048) { TlStoreBinary::store(auction_start_date_, s); }
  if (var0 & 4096) { TlStoreBinary::store(upgrade_variants_, s); }
  if (var0 & 8192) { TlStoreBoxed<TlStoreObject, -1342872680>::store(background_, s); }
}

void starGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (limited_ << 0) | (sold_out_ << 1) | (birthday_ << 2) | (require_premium_ << 7) | (limited_per_user_ << 8) | (peer_color_available_ << 10) | (auction_ << 11) | ((!title_.empty()) << 5) | ((released_by_ != nullptr) << 6) | ((!auction_slug_.empty()) << 11) | ((background_ != nullptr) << 13)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBinary::store(stars_, s);
  if (var0 & 1) { TlStoreBinary::store(availability_remains_, s); }
  if (var0 & 1) { TlStoreBinary::store(availability_total_, s); }
  if (var0 & 16) { TlStoreBinary::store(availability_resale_, s); }
  TlStoreBinary::store(convert_stars_, s);
  if (var0 & 2) { TlStoreBinary::store(first_sale_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(last_sale_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(upgrade_stars_, s); }
  if (var0 & 16) { TlStoreBinary::store(resell_min_stars_, s); }
  if (var0 & 32) { TlStoreString::store(title_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(released_by_, s); }
  if (var0 & 256) { TlStoreBinary::store(per_user_total_, s); }
  if (var0 & 256) { TlStoreBinary::store(per_user_remains_, s); }
  if (var0 & 512) { TlStoreBinary::store(locked_until_date_, s); }
  if (var0 & 2048) { TlStoreString::store(auction_slug_, s); }
  if (var0 & 2048) { TlStoreBinary::store(gifts_per_round_, s); }
  if (var0 & 2048) { TlStoreBinary::store(auction_start_date_, s); }
  if (var0 & 4096) { TlStoreBinary::store(upgrade_variants_, s); }
  if (var0 & 8192) { TlStoreBoxed<TlStoreObject, -1342872680>::store(background_, s); }
}

void starGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGift");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (limited_ << 0) | (sold_out_ << 1) | (birthday_ << 2) | (require_premium_ << 7) | (limited_per_user_ << 8) | (peer_color_available_ << 10) | (auction_ << 11) | ((!title_.empty()) << 5) | ((released_by_ != nullptr) << 6) | ((!auction_slug_.empty()) << 11) | ((background_ != nullptr) << 13)));
    if (var0 & 1) { s.store_field("limited", true); }
    if (var0 & 2) { s.store_field("sold_out", true); }
    if (var0 & 4) { s.store_field("birthday", true); }
    if (var0 & 128) { s.store_field("require_premium", true); }
    if (var0 & 256) { s.store_field("limited_per_user", true); }
    if (var0 & 1024) { s.store_field("peer_color_available", true); }
    if (var0 & 2048) { s.store_field("auction", true); }
    s.store_field("id", id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("stars", stars_);
    if (var0 & 1) { s.store_field("availability_remains", availability_remains_); }
    if (var0 & 1) { s.store_field("availability_total", availability_total_); }
    if (var0 & 16) { s.store_field("availability_resale", availability_resale_); }
    s.store_field("convert_stars", convert_stars_);
    if (var0 & 2) { s.store_field("first_sale_date", first_sale_date_); }
    if (var0 & 2) { s.store_field("last_sale_date", last_sale_date_); }
    if (var0 & 8) { s.store_field("upgrade_stars", upgrade_stars_); }
    if (var0 & 16) { s.store_field("resell_min_stars", resell_min_stars_); }
    if (var0 & 32) { s.store_field("title", title_); }
    if (var0 & 64) { s.store_object_field("released_by", static_cast<const BaseObject *>(released_by_.get())); }
    if (var0 & 256) { s.store_field("per_user_total", per_user_total_); }
    if (var0 & 256) { s.store_field("per_user_remains", per_user_remains_); }
    if (var0 & 512) { s.store_field("locked_until_date", locked_until_date_); }
    if (var0 & 2048) { s.store_field("auction_slug", auction_slug_); }
    if (var0 & 2048) { s.store_field("gifts_per_round", gifts_per_round_); }
    if (var0 & 2048) { s.store_field("auction_start_date", auction_start_date_); }
    if (var0 & 4096) { s.store_field("upgrade_variants", upgrade_variants_); }
    if (var0 & 8192) { s.store_object_field("background", static_cast<const BaseObject *>(background_.get())); }
    s.store_class_end();
  }
}

starGiftUnique::starGiftUnique()
  : flags_()
  , require_premium_()
  , resale_ton_only_()
  , theme_available_()
  , burned_()
  , crafted_()
  , onchain_sale_()
  , fixed_sale_()
  , my_sale_()
  , offer_min_amount_()
  , fee_bps_()
  , id_()
  , gift_id_()
  , title_()
  , slug_()
  , num_()
  , owner_id_()
  , owner_name_()
  , owner_address_()
  , attributes_()
  , availability_issued_()
  , availability_total_()
  , gift_address_()
  , resell_amount_()
  , released_by_()
  , value_amount_()
  , value_currency_()
  , value_usd_amount_()
  , theme_peer_()
  , peer_color_()
  , host_id_()
  , offer_min_stars_()
  , craft_chance_permille_()
{}

starGiftUnique::starGiftUnique(int32 flags_, bool require_premium_, bool resale_ton_only_, bool theme_available_, bool burned_, bool crafted_, bool onchain_sale_, bool fixed_sale_, bool my_sale_, int64 offer_min_amount_, int32 fee_bps_, int64 id_, int64 gift_id_, string const &title_, string const &slug_, int32 num_, object_ptr<Peer> &&owner_id_, string const &owner_name_, string const &owner_address_, array<object_ptr<StarGiftAttribute>> &&attributes_, int32 availability_issued_, int32 availability_total_, string const &gift_address_, array<object_ptr<StarsAmount>> &&resell_amount_, object_ptr<Peer> &&released_by_, int64 value_amount_, string const &value_currency_, int64 value_usd_amount_, object_ptr<Peer> &&theme_peer_, object_ptr<PeerColor> &&peer_color_, object_ptr<Peer> &&host_id_, int32 offer_min_stars_, int32 craft_chance_permille_)
  : flags_(flags_)
  , require_premium_(require_premium_)
  , resale_ton_only_(resale_ton_only_)
  , theme_available_(theme_available_)
  , burned_(burned_)
  , crafted_(crafted_)
  , onchain_sale_(onchain_sale_)
  , fixed_sale_(fixed_sale_)
  , my_sale_(my_sale_)
  , offer_min_amount_(offer_min_amount_)
  , fee_bps_(fee_bps_)
  , id_(id_)
  , gift_id_(gift_id_)
  , title_(title_)
  , slug_(slug_)
  , num_(num_)
  , owner_id_(std::move(owner_id_))
  , owner_name_(owner_name_)
  , owner_address_(owner_address_)
  , attributes_(std::move(attributes_))
  , availability_issued_(availability_issued_)
  , availability_total_(availability_total_)
  , gift_address_(gift_address_)
  , resell_amount_(std::move(resell_amount_))
  , released_by_(std::move(released_by_))
  , value_amount_(value_amount_)
  , value_currency_(value_currency_)
  , value_usd_amount_(value_usd_amount_)
  , theme_peer_(std::move(theme_peer_))
  , peer_color_(std::move(peer_color_))
  , host_id_(std::move(host_id_))
  , offer_min_stars_(offer_min_stars_)
  , craft_chance_permille_(craft_chance_permille_)
{}

const std::int32_t starGiftUnique::ID;

object_ptr<StarGift> starGiftUnique::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftUnique> res = make_tl_object<starGiftUnique>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->require_premium_ = (var0 & 64) != 0;
  res->resale_ton_only_ = (var0 & 128) != 0;
  res->theme_available_ = (var0 & 512) != 0;
  res->burned_ = (var0 & 16384) != 0;
  res->crafted_ = (var0 & 32768) != 0;
  res->onchain_sale_ = (var0 & 131072) != 0;
  res->fixed_sale_ = (var0 & 524288) != 0;
  res->my_sale_ = (var0 & 2097152) != 0;
  if (var0 & 262144) { res->offer_min_amount_ = TlFetchLong::parse(p); }
  if (var0 & 1048576) { res->fee_bps_ = TlFetchInt::parse(p); }
  res->id_ = TlFetchLong::parse(p);
  res->gift_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->slug_ = TlFetchString<string>::parse(p);
  res->num_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->owner_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2) { res->owner_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->owner_address_ = TlFetchString<string>::parse(p); }
  res->attributes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StarGiftAttribute>>, 481674261>::parse(p);
  res->availability_issued_ = TlFetchInt::parse(p);
  res->availability_total_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->gift_address_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->resell_amount_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StarsAmount>>, 481674261>::parse(p); }
  if (var0 & 32) { res->released_by_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 256) { res->value_amount_ = TlFetchLong::parse(p); }
  if (var0 & 256) { res->value_currency_ = TlFetchString<string>::parse(p); }
  if (var0 & 256) { res->value_usd_amount_ = TlFetchLong::parse(p); }
  if (var0 & 1024) { res->theme_peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2048) { res->peer_color_ = TlFetchObject<PeerColor>::parse(p); }
  if (var0 & 4096) { res->host_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 8192) { res->offer_min_stars_ = TlFetchInt::parse(p); }
  if (var0 & 65536) { res->craft_chance_permille_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void starGiftUnique::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (require_premium_ << 6) | (resale_ton_only_ << 7) | (theme_available_ << 9) | (burned_ << 14) | (crafted_ << 15) | (onchain_sale_ << 17) | (fixed_sale_ << 19) | (my_sale_ << 21) | ((owner_id_ != nullptr) << 0) | ((!owner_name_.empty()) << 1) | ((!owner_address_.empty()) << 2) | ((!gift_address_.empty()) << 3) | ((!resell_amount_.empty()) << 4) | ((released_by_ != nullptr) << 5) | ((!value_currency_.empty()) << 8) | ((theme_peer_ != nullptr) << 10) | ((peer_color_ != nullptr) << 11) | ((host_id_ != nullptr) << 12)), s);
  if (var0 & 262144) { TlStoreBinary::store(offer_min_amount_, s); }
  if (var0 & 1048576) { TlStoreBinary::store(fee_bps_, s); }
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(gift_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(num_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(owner_id_, s); }
  if (var0 & 2) { TlStoreString::store(owner_name_, s); }
  if (var0 & 4) { TlStoreString::store(owner_address_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
  TlStoreBinary::store(availability_issued_, s);
  TlStoreBinary::store(availability_total_, s);
  if (var0 & 8) { TlStoreString::store(gift_address_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(resell_amount_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(released_by_, s); }
  if (var0 & 256) { TlStoreBinary::store(value_amount_, s); }
  if (var0 & 256) { TlStoreString::store(value_currency_, s); }
  if (var0 & 256) { TlStoreBinary::store(value_usd_amount_, s); }
  if (var0 & 1024) { TlStoreBoxedUnknown<TlStoreObject>::store(theme_peer_, s); }
  if (var0 & 2048) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_color_, s); }
  if (var0 & 4096) { TlStoreBoxedUnknown<TlStoreObject>::store(host_id_, s); }
  if (var0 & 8192) { TlStoreBinary::store(offer_min_stars_, s); }
  if (var0 & 65536) { TlStoreBinary::store(craft_chance_permille_, s); }
}

void starGiftUnique::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (require_premium_ << 6) | (resale_ton_only_ << 7) | (theme_available_ << 9) | (burned_ << 14) | (crafted_ << 15) | (onchain_sale_ << 17) | (fixed_sale_ << 19) | (my_sale_ << 21) | ((owner_id_ != nullptr) << 0) | ((!owner_name_.empty()) << 1) | ((!owner_address_.empty()) << 2) | ((!gift_address_.empty()) << 3) | ((!resell_amount_.empty()) << 4) | ((released_by_ != nullptr) << 5) | ((!value_currency_.empty()) << 8) | ((theme_peer_ != nullptr) << 10) | ((peer_color_ != nullptr) << 11) | ((host_id_ != nullptr) << 12)), s);
  if (var0 & 262144) { TlStoreBinary::store(offer_min_amount_, s); }
  if (var0 & 1048576) { TlStoreBinary::store(fee_bps_, s); }
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(gift_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(num_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(owner_id_, s); }
  if (var0 & 2) { TlStoreString::store(owner_name_, s); }
  if (var0 & 4) { TlStoreString::store(owner_address_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
  TlStoreBinary::store(availability_issued_, s);
  TlStoreBinary::store(availability_total_, s);
  if (var0 & 8) { TlStoreString::store(gift_address_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(resell_amount_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(released_by_, s); }
  if (var0 & 256) { TlStoreBinary::store(value_amount_, s); }
  if (var0 & 256) { TlStoreString::store(value_currency_, s); }
  if (var0 & 256) { TlStoreBinary::store(value_usd_amount_, s); }
  if (var0 & 1024) { TlStoreBoxedUnknown<TlStoreObject>::store(theme_peer_, s); }
  if (var0 & 2048) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_color_, s); }
  if (var0 & 4096) { TlStoreBoxedUnknown<TlStoreObject>::store(host_id_, s); }
  if (var0 & 8192) { TlStoreBinary::store(offer_min_stars_, s); }
  if (var0 & 65536) { TlStoreBinary::store(craft_chance_permille_, s); }
}

void starGiftUnique::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftUnique");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (require_premium_ << 6) | (resale_ton_only_ << 7) | (theme_available_ << 9) | (burned_ << 14) | (crafted_ << 15) | (onchain_sale_ << 17) | (fixed_sale_ << 19) | (my_sale_ << 21) | ((owner_id_ != nullptr) << 0) | ((!owner_name_.empty()) << 1) | ((!owner_address_.empty()) << 2) | ((!gift_address_.empty()) << 3) | ((!resell_amount_.empty()) << 4) | ((released_by_ != nullptr) << 5) | ((!value_currency_.empty()) << 8) | ((theme_peer_ != nullptr) << 10) | ((peer_color_ != nullptr) << 11) | ((host_id_ != nullptr) << 12)));
    if (var0 & 64) { s.store_field("require_premium", true); }
    if (var0 & 128) { s.store_field("resale_ton_only", true); }
    if (var0 & 512) { s.store_field("theme_available", true); }
    if (var0 & 16384) { s.store_field("burned", true); }
    if (var0 & 32768) { s.store_field("crafted", true); }
    if (var0 & 131072) { s.store_field("onchain_sale", true); }
    if (var0 & 524288) { s.store_field("fixed_sale", true); }
    if (var0 & 2097152) { s.store_field("my_sale", true); }
    if (var0 & 262144) { s.store_field("offer_min_amount", offer_min_amount_); }
    if (var0 & 1048576) { s.store_field("fee_bps", fee_bps_); }
    s.store_field("id", id_);
    s.store_field("gift_id", gift_id_);
    s.store_field("title", title_);
    s.store_field("slug", slug_);
    s.store_field("num", num_);
    if (var0 & 1) { s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get())); }
    if (var0 & 2) { s.store_field("owner_name", owner_name_); }
    if (var0 & 4) { s.store_field("owner_address", owner_address_); }
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("availability_issued", availability_issued_);
    s.store_field("availability_total", availability_total_);
    if (var0 & 8) { s.store_field("gift_address", gift_address_); }
    if (var0 & 16) { { s.store_vector_begin("resell_amount", resell_amount_.size()); for (const auto &_value : resell_amount_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32) { s.store_object_field("released_by", static_cast<const BaseObject *>(released_by_.get())); }
    if (var0 & 256) { s.store_field("value_amount", value_amount_); }
    if (var0 & 256) { s.store_field("value_currency", value_currency_); }
    if (var0 & 256) { s.store_field("value_usd_amount", value_usd_amount_); }
    if (var0 & 1024) { s.store_object_field("theme_peer", static_cast<const BaseObject *>(theme_peer_.get())); }
    if (var0 & 2048) { s.store_object_field("peer_color", static_cast<const BaseObject *>(peer_color_.get())); }
    if (var0 & 4096) { s.store_object_field("host_id", static_cast<const BaseObject *>(host_id_.get())); }
    if (var0 & 8192) { s.store_field("offer_min_stars", offer_min_stars_); }
    if (var0 & 65536) { s.store_field("craft_chance_permille", craft_chance_permille_); }
    s.store_class_end();
  }
}

starsSubscription::starsSubscription()
  : flags_()
  , canceled_()
  , can_refulfill_()
  , missing_balance_()
  , bot_canceled_()
  , id_()
  , peer_()
  , until_date_()
  , pricing_()
  , chat_invite_hash_()
  , title_()
  , photo_()
  , invoice_slug_()
{}

const std::int32_t starsSubscription::ID;

object_ptr<starsSubscription> starsSubscription::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsSubscription> res = make_tl_object<starsSubscription>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->canceled_ = (var0 & 1) != 0;
  res->can_refulfill_ = (var0 & 2) != 0;
  res->missing_balance_ = (var0 & 4) != 0;
  res->bot_canceled_ = (var0 & 128) != 0;
  res->id_ = TlFetchString<string>::parse(p);
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->until_date_ = TlFetchInt::parse(p);
  res->pricing_ = TlFetchBoxed<TlFetchObject<starsSubscriptionPricing>, 88173912>::parse(p);
  if (var0 & 8) { res->chat_invite_hash_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 32) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 64) { res->invoice_slug_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsSubscription");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (canceled_ << 0) | (can_refulfill_ << 1) | (missing_balance_ << 2) | (bot_canceled_ << 7) | ((!chat_invite_hash_.empty()) << 3) | ((!title_.empty()) << 4) | ((photo_ != nullptr) << 5) | ((!invoice_slug_.empty()) << 6)));
    if (var0 & 1) { s.store_field("canceled", true); }
    if (var0 & 2) { s.store_field("can_refulfill", true); }
    if (var0 & 4) { s.store_field("missing_balance", true); }
    if (var0 & 128) { s.store_field("bot_canceled", true); }
    s.store_field("id", id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("until_date", until_date_);
    s.store_object_field("pricing", static_cast<const BaseObject *>(pricing_.get()));
    if (var0 & 8) { s.store_field("chat_invite_hash", chat_invite_hash_); }
    if (var0 & 16) { s.store_field("title", title_); }
    if (var0 & 32) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 64) { s.store_field("invoice_slug", invoice_slug_); }
    s.store_class_end();
  }
}

object_ptr<StarsTransactionPeer> StarsTransactionPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starsTransactionPeerUnsupported::ID:
      return starsTransactionPeerUnsupported::fetch(p);
    case starsTransactionPeerAppStore::ID:
      return starsTransactionPeerAppStore::fetch(p);
    case starsTransactionPeerPlayMarket::ID:
      return starsTransactionPeerPlayMarket::fetch(p);
    case starsTransactionPeerPremiumBot::ID:
      return starsTransactionPeerPremiumBot::fetch(p);
    case starsTransactionPeerFragment::ID:
      return starsTransactionPeerFragment::fetch(p);
    case starsTransactionPeer::ID:
      return starsTransactionPeer::fetch(p);
    case starsTransactionPeerAds::ID:
      return starsTransactionPeerAds::fetch(p);
    case starsTransactionPeerAPI::ID:
      return starsTransactionPeerAPI::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t starsTransactionPeerUnsupported::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerUnsupported::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerUnsupported>();
}

void starsTransactionPeerUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerUnsupported");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerAppStore::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerAppStore::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerAppStore>();
}

void starsTransactionPeerAppStore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerAppStore");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerPlayMarket::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerPlayMarket::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerPlayMarket>();
}

void starsTransactionPeerPlayMarket::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerPlayMarket");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerPremiumBot::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerPremiumBot::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerPremiumBot>();
}

void starsTransactionPeerPremiumBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerPremiumBot");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerFragment::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerFragment::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerFragment>();
}

void starsTransactionPeerFragment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerFragment");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeer::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeer::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeer>(p);
}

starsTransactionPeer::starsTransactionPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
{}

void starsTransactionPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerAds::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerAds::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerAds>();
}

void starsTransactionPeerAds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerAds");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerAPI::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerAPI::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerAPI>();
}

void starsTransactionPeerAPI::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerAPI");
    s.store_class_end();
  }
}

const std::int32_t statsDateRangeDays::ID;

object_ptr<statsDateRangeDays> statsDateRangeDays::fetch(TlBufferParser &p) {
  return make_tl_object<statsDateRangeDays>(p);
}

statsDateRangeDays::statsDateRangeDays(TlBufferParser &p)
  : min_date_(TlFetchInt::parse(p))
  , max_date_(TlFetchInt::parse(p))
{}

void statsDateRangeDays::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsDateRangeDays");
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_class_end();
  }
}

const std::int32_t statsURL::ID;

void statsURL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsURL");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

storyAlbum::storyAlbum()
  : flags_()
  , album_id_()
  , title_()
  , icon_photo_()
  , icon_video_()
{}

const std::int32_t storyAlbum::ID;

object_ptr<storyAlbum> storyAlbum::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyAlbum> res = make_tl_object<storyAlbum>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->album_id_ = TlFetchInt::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->icon_photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 2) { res->icon_video_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void storyAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAlbum");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((icon_photo_ != nullptr) << 0) | ((icon_video_ != nullptr) << 1)));
    s.store_field("album_id", album_id_);
    s.store_field("title", title_);
    if (var0 & 1) { s.store_object_field("icon_photo", static_cast<const BaseObject *>(icon_photo_.get())); }
    if (var0 & 2) { s.store_object_field("icon_video", static_cast<const BaseObject *>(icon_video_.get())); }
    s.store_class_end();
  }
}

todoItem::todoItem(int32 id_, object_ptr<textWithEntities> &&title_)
  : id_(id_)
  , title_(std::move(title_))
{}

const std::int32_t todoItem::ID;

object_ptr<todoItem> todoItem::fetch(TlBufferParser &p) {
  return make_tl_object<todoItem>(p);
}

todoItem::todoItem(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , title_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
{}

void todoItem::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
}

void todoItem::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
}

void todoItem::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "todoItem");
    s.store_field("id", id_);
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    s.store_class_end();
  }
}

todoList::todoList()
  : flags_()
  , others_can_append_()
  , others_can_complete_()
  , title_()
  , list_()
{}

todoList::todoList(int32 flags_, bool others_can_append_, bool others_can_complete_, object_ptr<textWithEntities> &&title_, array<object_ptr<todoItem>> &&list_)
  : flags_(flags_)
  , others_can_append_(others_can_append_)
  , others_can_complete_(others_can_complete_)
  , title_(std::move(title_))
  , list_(std::move(list_))
{}

const std::int32_t todoList::ID;

object_ptr<todoList> todoList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<todoList> res = make_tl_object<todoList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->others_can_append_ = (var0 & 1) != 0;
  res->others_can_complete_ = (var0 & 2) != 0;
  res->title_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  res->list_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<todoItem>, -878074577>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void todoList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (others_can_append_ << 0) | (others_can_complete_ << 1)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -878074577>>, 481674261>::store(list_, s);
}

void todoList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (others_can_append_ << 0) | (others_can_complete_ << 1)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -878074577>>, 481674261>::store(list_, s);
}

void todoList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "todoList");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (others_can_append_ << 0) | (others_can_complete_ << 1)));
    if (var0 & 1) { s.store_field("others_can_append", true); }
    if (var0 & 2) { s.store_field("others_can_complete", true); }
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    { s.store_vector_begin("list", list_.size()); for (const auto &_value : list_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<User> User::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case userEmpty::ID:
      return userEmpty::fetch(p);
    case user::ID:
      return user::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t userEmpty::ID;

object_ptr<User> userEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<userEmpty>(p);
}

userEmpty::userEmpty(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void userEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

user::user()
  : flags_()
  , self_()
  , contact_()
  , mutual_contact_()
  , deleted_()
  , bot_()
  , bot_chat_history_()
  , bot_nochats_()
  , verified_()
  , restricted_()
  , min_()
  , bot_inline_geo_()
  , support_()
  , scam_()
  , apply_min_photo_()
  , fake_()
  , bot_attach_menu_()
  , premium_()
  , attach_menu_enabled_()
  , flags2_()
  , bot_can_edit_()
  , close_friend_()
  , stories_hidden_()
  , stories_unavailable_()
  , contact_require_premium_()
  , bot_business_()
  , bot_has_main_app_()
  , bot_forum_view_()
  , bot_forum_can_manage_topics_()
  , bot_can_manage_bots_()
  , bot_guestchat_()
  , bot_guard_()
  , bot_forum_sidebar_()
  , id_()
  , access_hash_()
  , first_name_()
  , last_name_()
  , username_()
  , phone_()
  , photo_()
  , status_()
  , bot_info_version_()
  , restriction_reason_()
  , bot_inline_placeholder_()
  , lang_code_()
  , emoji_status_()
  , usernames_()
  , stories_max_id_()
  , color_()
  , profile_color_()
  , bot_active_users_()
  , bot_verification_icon_()
  , send_paid_messages_stars_()
  , linked_community_id_()
{}

user::user(int32 flags_, bool self_, bool contact_, bool mutual_contact_, bool deleted_, bool bot_, bool bot_chat_history_, bool bot_nochats_, bool verified_, bool restricted_, bool min_, bool bot_inline_geo_, bool support_, bool scam_, bool apply_min_photo_, bool fake_, bool bot_attach_menu_, bool premium_, bool attach_menu_enabled_, int32 flags2_, bool bot_can_edit_, bool close_friend_, bool stories_hidden_, bool stories_unavailable_, bool contact_require_premium_, bool bot_business_, bool bot_has_main_app_, bool bot_forum_view_, bool bot_forum_can_manage_topics_, bool bot_can_manage_bots_, bool bot_guestchat_, bool bot_guard_, bool bot_forum_sidebar_, int64 id_, int64 access_hash_, string const &first_name_, string const &last_name_, string const &username_, string const &phone_, object_ptr<UserProfilePhoto> &&photo_, object_ptr<UserStatus> &&status_, int32 bot_info_version_, array<object_ptr<restrictionReason>> &&restriction_reason_, string const &bot_inline_placeholder_, string const &lang_code_, object_ptr<EmojiStatus> &&emoji_status_, array<object_ptr<username>> &&usernames_, object_ptr<recentStory> &&stories_max_id_, object_ptr<PeerColor> &&color_, object_ptr<PeerColor> &&profile_color_, int32 bot_active_users_, int64 bot_verification_icon_, int64 send_paid_messages_stars_, int64 linked_community_id_)
  : flags_(flags_)
  , self_(self_)
  , contact_(contact_)
  , mutual_contact_(mutual_contact_)
  , deleted_(deleted_)
  , bot_(bot_)
  , bot_chat_history_(bot_chat_history_)
  , bot_nochats_(bot_nochats_)
  , verified_(verified_)
  , restricted_(restricted_)
  , min_(min_)
  , bot_inline_geo_(bot_inline_geo_)
  , support_(support_)
  , scam_(scam_)
  , apply_min_photo_(apply_min_photo_)
  , fake_(fake_)
  , bot_attach_menu_(bot_attach_menu_)
  , premium_(premium_)
  , attach_menu_enabled_(attach_menu_enabled_)
  , flags2_(flags2_)
  , bot_can_edit_(bot_can_edit_)
  , close_friend_(close_friend_)
  , stories_hidden_(stories_hidden_)
  , stories_unavailable_(stories_unavailable_)
  , contact_require_premium_(contact_require_premium_)
  , bot_business_(bot_business_)
  , bot_has_main_app_(bot_has_main_app_)
  , bot_forum_view_(bot_forum_view_)
  , bot_forum_can_manage_topics_(bot_forum_can_manage_topics_)
  , bot_can_manage_bots_(bot_can_manage_bots_)
  , bot_guestchat_(bot_guestchat_)
  , bot_guard_(bot_guard_)
  , bot_forum_sidebar_(bot_forum_sidebar_)
  , id_(id_)
  , access_hash_(access_hash_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , username_(username_)
  , phone_(phone_)
  , photo_(std::move(photo_))
  , status_(std::move(status_))
  , bot_info_version_(bot_info_version_)
  , restriction_reason_(std::move(restriction_reason_))
  , bot_inline_placeholder_(bot_inline_placeholder_)
  , lang_code_(lang_code_)
  , emoji_status_(std::move(emoji_status_))
  , usernames_(std::move(usernames_))
  , stories_max_id_(std::move(stories_max_id_))
  , color_(std::move(color_))
  , profile_color_(std::move(profile_color_))
  , bot_active_users_(bot_active_users_)
  , bot_verification_icon_(bot_verification_icon_)
  , send_paid_messages_stars_(send_paid_messages_stars_)
  , linked_community_id_(linked_community_id_)
{}

const std::int32_t user::ID;

object_ptr<User> user::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<user> res = make_tl_object<user>();
  int32 var0;
  int32 var1;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->self_ = (var0 & 1024) != 0;
  res->contact_ = (var0 & 2048) != 0;
  res->mutual_contact_ = (var0 & 4096) != 0;
  res->deleted_ = (var0 & 8192) != 0;
  res->bot_ = (var0 & 16384) != 0;
  res->bot_chat_history_ = (var0 & 32768) != 0;
  res->bot_nochats_ = (var0 & 65536) != 0;
  res->verified_ = (var0 & 131072) != 0;
  res->restricted_ = (var0 & 262144) != 0;
  res->min_ = (var0 & 1048576) != 0;
  res->bot_inline_geo_ = (var0 & 2097152) != 0;
  res->support_ = (var0 & 8388608) != 0;
  res->scam_ = (var0 & 16777216) != 0;
  res->apply_min_photo_ = (var0 & 33554432) != 0;
  res->fake_ = (var0 & 67108864) != 0;
  res->bot_attach_menu_ = (var0 & 134217728) != 0;
  res->premium_ = (var0 & 268435456) != 0;
  res->attach_menu_enabled_ = (var0 & 536870912) != 0;
  if ((var1 = res->flags2_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bot_can_edit_ = (var1 & 2) != 0;
  res->close_friend_ = (var1 & 4) != 0;
  res->stories_hidden_ = (var1 & 8) != 0;
  res->stories_unavailable_ = (var1 & 16) != 0;
  res->contact_require_premium_ = (var1 & 1024) != 0;
  res->bot_business_ = (var1 & 2048) != 0;
  res->bot_has_main_app_ = (var1 & 8192) != 0;
  res->bot_forum_view_ = (var1 & 65536) != 0;
  res->bot_forum_can_manage_topics_ = (var1 & 131072) != 0;
  res->bot_can_manage_bots_ = (var1 & 262144) != 0;
  res->bot_guestchat_ = (var1 & 524288) != 0;
  res->bot_guard_ = (var1 & 1048576) != 0;
  res->bot_forum_sidebar_ = (var1 & 4194304) != 0;
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->access_hash_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->first_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->last_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->username_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->phone_ = TlFetchString<string>::parse(p); }
  if (var0 & 32) { res->photo_ = TlFetchObject<UserProfilePhoto>::parse(p); }
  if (var0 & 64) { res->status_ = TlFetchObject<UserStatus>::parse(p); }
  if (var0 & 16384) { res->bot_info_version_ = TlFetchInt::parse(p); }
  if (var0 & 262144) { res->restriction_reason_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<restrictionReason>, -797791052>>, 481674261>::parse(p); }
  if (var0 & 524288) { res->bot_inline_placeholder_ = TlFetchString<string>::parse(p); }
  if (var0 & 4194304) { res->lang_code_ = TlFetchString<string>::parse(p); }
  if (var0 & 1073741824) { res->emoji_status_ = TlFetchObject<EmojiStatus>::parse(p); }
  if (var1 & 1) { res->usernames_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<username>, -1274595769>>, 481674261>::parse(p); }
  if (var1 & 32) { res->stories_max_id_ = TlFetchBoxed<TlFetchObject<recentStory>, 1897752877>::parse(p); }
  if (var1 & 256) { res->color_ = TlFetchObject<PeerColor>::parse(p); }
  if (var1 & 512) { res->profile_color_ = TlFetchObject<PeerColor>::parse(p); }
  if (var1 & 4096) { res->bot_active_users_ = TlFetchInt::parse(p); }
  if (var1 & 16384) { res->bot_verification_icon_ = TlFetchLong::parse(p); }
  if (var1 & 32768) { res->send_paid_messages_stars_ = TlFetchLong::parse(p); }
  if (var1 & 2097152) { res->linked_community_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void user::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "user");
  int32 var0;
  int32 var1;
    s.store_field("flags", (var0 = flags_ | (self_ << 10) | (contact_ << 11) | (mutual_contact_ << 12) | (deleted_ << 13) | (bot_ << 14) | (bot_chat_history_ << 15) | (bot_nochats_ << 16) | (verified_ << 17) | (restricted_ << 18) | (min_ << 20) | (bot_inline_geo_ << 21) | (support_ << 23) | (scam_ << 24) | (apply_min_photo_ << 25) | (fake_ << 26) | (bot_attach_menu_ << 27) | (premium_ << 28) | (attach_menu_enabled_ << 29) | ((!first_name_.empty()) << 1) | ((!last_name_.empty()) << 2) | ((!username_.empty()) << 3) | ((!phone_.empty()) << 4) | ((photo_ != nullptr) << 5) | ((status_ != nullptr) << 6) | ((!restriction_reason_.empty()) << 18) | ((!bot_inline_placeholder_.empty()) << 19) | ((!lang_code_.empty()) << 22) | ((emoji_status_ != nullptr) << 30)));
    if (var0 & 1024) { s.store_field("self", true); }
    if (var0 & 2048) { s.store_field("contact", true); }
    if (var0 & 4096) { s.store_field("mutual_contact", true); }
    if (var0 & 8192) { s.store_field("deleted", true); }
    if (var0 & 16384) { s.store_field("bot", true); }
    if (var0 & 32768) { s.store_field("bot_chat_history", true); }
    if (var0 & 65536) { s.store_field("bot_nochats", true); }
    if (var0 & 131072) { s.store_field("verified", true); }
    if (var0 & 262144) { s.store_field("restricted", true); }
    if (var0 & 1048576) { s.store_field("min", true); }
    if (var0 & 2097152) { s.store_field("bot_inline_geo", true); }
    if (var0 & 8388608) { s.store_field("support", true); }
    if (var0 & 16777216) { s.store_field("scam", true); }
    if (var0 & 33554432) { s.store_field("apply_min_photo", true); }
    if (var0 & 67108864) { s.store_field("fake", true); }
    if (var0 & 134217728) { s.store_field("bot_attach_menu", true); }
    if (var0 & 268435456) { s.store_field("premium", true); }
    if (var0 & 536870912) { s.store_field("attach_menu_enabled", true); }
    s.store_field("flags2", (var1 = flags2_ | (bot_can_edit_ << 1) | (close_friend_ << 2) | (stories_hidden_ << 3) | (stories_unavailable_ << 4) | (contact_require_premium_ << 10) | (bot_business_ << 11) | (bot_has_main_app_ << 13) | (bot_forum_view_ << 16) | (bot_forum_can_manage_topics_ << 17) | (bot_can_manage_bots_ << 18) | (bot_guestchat_ << 19) | (bot_guard_ << 20) | (bot_forum_sidebar_ << 22) | ((!usernames_.empty()) << 0) | ((stories_max_id_ != nullptr) << 5) | ((color_ != nullptr) << 8) | ((profile_color_ != nullptr) << 9)));
    if (var1 & 2) { s.store_field("bot_can_edit", true); }
    if (var1 & 4) { s.store_field("close_friend", true); }
    if (var1 & 8) { s.store_field("stories_hidden", true); }
    if (var1 & 16) { s.store_field("stories_unavailable", true); }
    if (var1 & 1024) { s.store_field("contact_require_premium", true); }
    if (var1 & 2048) { s.store_field("bot_business", true); }
    if (var1 & 8192) { s.store_field("bot_has_main_app", true); }
    if (var1 & 65536) { s.store_field("bot_forum_view", true); }
    if (var1 & 131072) { s.store_field("bot_forum_can_manage_topics", true); }
    if (var1 & 262144) { s.store_field("bot_can_manage_bots", true); }
    if (var1 & 524288) { s.store_field("bot_guestchat", true); }
    if (var1 & 1048576) { s.store_field("bot_guard", true); }
    if (var1 & 4194304) { s.store_field("bot_forum_sidebar", true); }
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("access_hash", access_hash_); }
    if (var0 & 2) { s.store_field("first_name", first_name_); }
    if (var0 & 4) { s.store_field("last_name", last_name_); }
    if (var0 & 8) { s.store_field("username", username_); }
    if (var0 & 16) { s.store_field("phone", phone_); }
    if (var0 & 32) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 64) { s.store_object_field("status", static_cast<const BaseObject *>(status_.get())); }
    if (var0 & 16384) { s.store_field("bot_info_version", bot_info_version_); }
    if (var0 & 262144) { { s.store_vector_begin("restriction_reason", restriction_reason_.size()); for (const auto &_value : restriction_reason_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 524288) { s.store_field("bot_inline_placeholder", bot_inline_placeholder_); }
    if (var0 & 4194304) { s.store_field("lang_code", lang_code_); }
    if (var0 & 1073741824) { s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get())); }
    if (var1 & 1) { { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var1 & 32) { s.store_object_field("stories_max_id", static_cast<const BaseObject *>(stories_max_id_.get())); }
    if (var1 & 256) { s.store_object_field("color", static_cast<const BaseObject *>(color_.get())); }
    if (var1 & 512) { s.store_object_field("profile_color", static_cast<const BaseObject *>(profile_color_.get())); }
    if (var1 & 4096) { s.store_field("bot_active_users", bot_active_users_); }
    if (var1 & 16384) { s.store_field("bot_verification_icon", bot_verification_icon_); }
    if (var1 & 32768) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    if (var1 & 2097152) { s.store_field("linked_community_id", linked_community_id_); }
    s.store_class_end();
  }
}

wallPaperSettings::wallPaperSettings()
  : flags_()
  , blur_()
  , motion_()
  , background_color_()
  , second_background_color_()
  , third_background_color_()
  , fourth_background_color_()
  , intensity_()
  , rotation_()
  , emoticon_()
{}

wallPaperSettings::wallPaperSettings(int32 flags_, bool blur_, bool motion_, int32 background_color_, int32 second_background_color_, int32 third_background_color_, int32 fourth_background_color_, int32 intensity_, int32 rotation_, string const &emoticon_)
  : flags_(flags_)
  , blur_(blur_)
  , motion_(motion_)
  , background_color_(background_color_)
  , second_background_color_(second_background_color_)
  , third_background_color_(third_background_color_)
  , fourth_background_color_(fourth_background_color_)
  , intensity_(intensity_)
  , rotation_(rotation_)
  , emoticon_(emoticon_)
{}

const std::int32_t wallPaperSettings::ID;

object_ptr<wallPaperSettings> wallPaperSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<wallPaperSettings> res = make_tl_object<wallPaperSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blur_ = (var0 & 2) != 0;
  res->motion_ = (var0 & 4) != 0;
  if (var0 & 1) { res->background_color_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->second_background_color_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->third_background_color_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->fourth_background_color_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->intensity_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->rotation_ = TlFetchInt::parse(p); }
  if (var0 & 128) { res->emoticon_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void wallPaperSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (blur_ << 1) | (motion_ << 2) | ((!emoticon_.empty()) << 7)), s);
  if (var0 & 1) { TlStoreBinary::store(background_color_, s); }
  if (var0 & 16) { TlStoreBinary::store(second_background_color_, s); }
  if (var0 & 32) { TlStoreBinary::store(third_background_color_, s); }
  if (var0 & 64) { TlStoreBinary::store(fourth_background_color_, s); }
  if (var0 & 8) { TlStoreBinary::store(intensity_, s); }
  if (var0 & 16) { TlStoreBinary::store(rotation_, s); }
  if (var0 & 128) { TlStoreString::store(emoticon_, s); }
}

void wallPaperSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (blur_ << 1) | (motion_ << 2) | ((!emoticon_.empty()) << 7)), s);
  if (var0 & 1) { TlStoreBinary::store(background_color_, s); }
  if (var0 & 16) { TlStoreBinary::store(second_background_color_, s); }
  if (var0 & 32) { TlStoreBinary::store(third_background_color_, s); }
  if (var0 & 64) { TlStoreBinary::store(fourth_background_color_, s); }
  if (var0 & 8) { TlStoreBinary::store(intensity_, s); }
  if (var0 & 16) { TlStoreBinary::store(rotation_, s); }
  if (var0 & 128) { TlStoreString::store(emoticon_, s); }
}

void wallPaperSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallPaperSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (blur_ << 1) | (motion_ << 2) | ((!emoticon_.empty()) << 7)));
    if (var0 & 2) { s.store_field("blur", true); }
    if (var0 & 4) { s.store_field("motion", true); }
    if (var0 & 1) { s.store_field("background_color", background_color_); }
    if (var0 & 16) { s.store_field("second_background_color", second_background_color_); }
    if (var0 & 32) { s.store_field("third_background_color", third_background_color_); }
    if (var0 & 64) { s.store_field("fourth_background_color", fourth_background_color_); }
    if (var0 & 8) { s.store_field("intensity", intensity_); }
    if (var0 & 16) { s.store_field("rotation", rotation_); }
    if (var0 & 128) { s.store_field("emoticon", emoticon_); }
    s.store_class_end();
  }
}

webViewResultUrl::webViewResultUrl()
  : flags_()
  , fullsize_()
  , fullscreen_()
  , same_origin_()
  , query_id_()
  , url_()
{}

const std::int32_t webViewResultUrl::ID;

object_ptr<webViewResultUrl> webViewResultUrl::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webViewResultUrl> res = make_tl_object<webViewResultUrl>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->fullsize_ = (var0 & 2) != 0;
  res->fullscreen_ = (var0 & 4) != 0;
  res->same_origin_ = (var0 & 8) != 0;
  if (var0 & 1) { res->query_id_ = TlFetchLong::parse(p); }
  res->url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void webViewResultUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webViewResultUrl");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (fullsize_ << 1) | (fullscreen_ << 2) | (same_origin_ << 3)));
    if (var0 & 2) { s.store_field("fullsize", true); }
    if (var0 & 4) { s.store_field("fullscreen", true); }
    if (var0 & 8) { s.store_field("same_origin", true); }
    if (var0 & 1) { s.store_field("query_id", query_id_); }
    s.store_field("url", url_);
    s.store_class_end();
  }
}

const std::int32_t account_businessChatLinks::ID;

object_ptr<account_businessChatLinks> account_businessChatLinks::fetch(TlBufferParser &p) {
  return make_tl_object<account_businessChatLinks>(p);
}

account_businessChatLinks::account_businessChatLinks(TlBufferParser &p)
  : links_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<businessChatLink>, -1263638929>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void account_businessChatLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.businessChatLinks");
    { s.store_vector_begin("links", links_.size()); for (const auto &_value : links_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<account_ChatThemes> account_ChatThemes::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_chatThemesNotModified::ID:
      return account_chatThemesNotModified::fetch(p);
    case account_chatThemes::ID:
      return account_chatThemes::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_chatThemesNotModified::ID;

object_ptr<account_ChatThemes> account_chatThemesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_chatThemesNotModified>();
}

void account_chatThemesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.chatThemesNotModified");
    s.store_class_end();
  }
}

account_chatThemes::account_chatThemes()
  : flags_()
  , hash_()
  , themes_()
  , chats_()
  , users_()
  , next_offset_()
{}

const std::int32_t account_chatThemes::ID;

object_ptr<account_ChatThemes> account_chatThemes::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_chatThemes> res = make_tl_object<account_chatThemes>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->hash_ = TlFetchLong::parse(p);
  res->themes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ChatTheme>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void account_chatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.chatThemes");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("hash", hash_);
    { s.store_vector_begin("themes", themes_.size()); for (const auto &_value : themes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

const std::int32_t account_takeout::ID;

object_ptr<account_takeout> account_takeout::fetch(TlBufferParser &p) {
  return make_tl_object<account_takeout>(p);
}

account_takeout::account_takeout(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void account_takeout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.takeout");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

contacts_contactBirthdays::contacts_contactBirthdays(array<object_ptr<contactBirthday>> &&contacts_, array<object_ptr<User>> &&users_)
  : contacts_(std::move(contacts_))
  , users_(std::move(users_))
{}

const std::int32_t contacts_contactBirthdays::ID;

object_ptr<contacts_contactBirthdays> contacts_contactBirthdays::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_contactBirthdays>(p);
}

contacts_contactBirthdays::contacts_contactBirthdays(TlBufferParser &p)
  : contacts_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<contactBirthday>, 496600883>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_contactBirthdays::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.contactBirthdays");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t help_inviteText::ID;

object_ptr<help_inviteText> help_inviteText::fetch(TlBufferParser &p) {
  return make_tl_object<help_inviteText>(p);
}

help_inviteText::help_inviteText(TlBufferParser &p)
  : message_(TlFetchString<string>::parse(p))
{}

void help_inviteText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.inviteText");
    s.store_field("message", message_);
    s.store_class_end();
  }
}

object_ptr<help_TermsOfServiceUpdate> help_TermsOfServiceUpdate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_termsOfServiceUpdateEmpty::ID:
      return help_termsOfServiceUpdateEmpty::fetch(p);
    case help_termsOfServiceUpdate::ID:
      return help_termsOfServiceUpdate::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_termsOfServiceUpdateEmpty::ID;

object_ptr<help_TermsOfServiceUpdate> help_termsOfServiceUpdateEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<help_termsOfServiceUpdateEmpty>(p);
}

help_termsOfServiceUpdateEmpty::help_termsOfServiceUpdateEmpty(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
{}

void help_termsOfServiceUpdateEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.termsOfServiceUpdateEmpty");
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

const std::int32_t help_termsOfServiceUpdate::ID;

object_ptr<help_TermsOfServiceUpdate> help_termsOfServiceUpdate::fetch(TlBufferParser &p) {
  return make_tl_object<help_termsOfServiceUpdate>(p);
}

help_termsOfServiceUpdate::help_termsOfServiceUpdate(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
  , terms_of_service_(TlFetchBoxed<TlFetchObject<help_termsOfService>, 2013922064>::parse(p))
{}

void help_termsOfServiceUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.termsOfServiceUpdate");
    s.store_field("expires", expires_);
    s.store_object_field("terms_of_service", static_cast<const BaseObject *>(terms_of_service_.get()));
    s.store_class_end();
  }
}

object_ptr<help_TimezonesList> help_TimezonesList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_timezonesListNotModified::ID:
      return help_timezonesListNotModified::fetch(p);
    case help_timezonesList::ID:
      return help_timezonesList::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_timezonesListNotModified::ID;

object_ptr<help_TimezonesList> help_timezonesListNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<help_timezonesListNotModified>();
}

void help_timezonesListNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.timezonesListNotModified");
    s.store_class_end();
  }
}

const std::int32_t help_timezonesList::ID;

object_ptr<help_TimezonesList> help_timezonesList::fetch(TlBufferParser &p) {
  return make_tl_object<help_timezonesList>(p);
}

help_timezonesList::help_timezonesList(TlBufferParser &p)
  : timezones_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<timezone>, -7173643>>, 481674261>::parse(p))
  , hash_(TlFetchInt::parse(p))
{}

void help_timezonesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.timezonesList");
    { s.store_vector_begin("timezones", timezones_.size()); for (const auto &_value : timezones_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

const std::int32_t messages_affectedFoundMessages::ID;

object_ptr<messages_affectedFoundMessages> messages_affectedFoundMessages::fetch(TlBufferParser &p) {
  return make_tl_object<messages_affectedFoundMessages>(p);
}

messages_affectedFoundMessages::messages_affectedFoundMessages(TlBufferParser &p)
  : pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
  , offset_(TlFetchInt::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void messages_affectedFoundMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.affectedFoundMessages");
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_field("offset", offset_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_botWidgetQueryAnswer::messages_botWidgetQueryAnswer()
  : flags_()
  , result_()
{}

const std::int32_t messages_botWidgetQueryAnswer::ID;

object_ptr<messages_botWidgetQueryAnswer> messages_botWidgetQueryAnswer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_botWidgetQueryAnswer> res = make_tl_object<messages_botWidgetQueryAnswer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->result_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_botWidgetQueryAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.botWidgetQueryAnswer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!result_.empty()) << 0)));
    if (var0 & 1) { s.store_field("result", result_); }
    s.store_class_end();
  }
}

const std::int32_t messages_chatFull::ID;

object_ptr<messages_chatFull> messages_chatFull::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chatFull>(p);
}

messages_chatFull::messages_chatFull(TlBufferParser &p)
  : full_chat_(TlFetchObject<ChatFull>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_chatFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chatFull");
    s.store_object_field("full_chat", static_cast<const BaseObject *>(full_chat_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_discussionMessage::messages_discussionMessage()
  : flags_()
  , messages_()
  , max_id_()
  , read_inbox_max_id_()
  , read_outbox_max_id_()
  , unread_count_()
  , chats_()
  , users_()
{}

const std::int32_t messages_discussionMessage::ID;

object_ptr<messages_discussionMessage> messages_discussionMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_discussionMessage> res = make_tl_object<messages_discussionMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  if (var0 & 1) { res->max_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->read_inbox_max_id_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->read_outbox_max_id_ = TlFetchInt::parse(p); }
  res->unread_count_ = TlFetchInt::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_discussionMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.discussionMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("max_id", max_id_); }
    if (var0 & 2) { s.store_field("read_inbox_max_id", read_inbox_max_id_); }
    if (var0 & 4) { s.store_field("read_outbox_max_id", read_outbox_max_id_); }
    s.store_field("unread_count", unread_count_);
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_invitedUsers::ID;

object_ptr<messages_invitedUsers> messages_invitedUsers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_invitedUsers>(p);
}

messages_invitedUsers::messages_invitedUsers(TlBufferParser &p)
  : updates_(TlFetchObject<Updates>::parse(p))
  , missing_invitees_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<missingInvitee>, 1653379620>>, 481674261>::parse(p))
{}

void messages_invitedUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.invitedUsers");
    s.store_object_field("updates", static_cast<const BaseObject *>(updates_.get()));
    { s.store_vector_begin("missing_invitees", missing_invitees_.size()); for (const auto &_value : missing_invitees_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_messageViews::ID;

object_ptr<messages_messageViews> messages_messageViews::fetch(TlBufferParser &p) {
  return make_tl_object<messages_messageViews>(p);
}

messages_messageViews::messages_messageViews(TlBufferParser &p)
  : views_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messageViews>, 1163625789>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_messageViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messageViews");
    { s.store_vector_begin("views", views_.size()); for (const auto &_value : views_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_QuickReplies> messages_QuickReplies::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_quickReplies::ID:
      return messages_quickReplies::fetch(p);
    case messages_quickRepliesNotModified::ID:
      return messages_quickRepliesNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_quickReplies::ID;

object_ptr<messages_QuickReplies> messages_quickReplies::fetch(TlBufferParser &p) {
  return make_tl_object<messages_quickReplies>(p);
}

messages_quickReplies::messages_quickReplies(TlBufferParser &p)
  : quick_replies_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<quickReply>, 110563371>>, 481674261>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_quickReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.quickReplies");
    { s.store_vector_begin("quick_replies", quick_replies_.size()); for (const auto &_value : quick_replies_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_quickRepliesNotModified::ID;

object_ptr<messages_QuickReplies> messages_quickRepliesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_quickRepliesNotModified>();
}

void messages_quickRepliesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.quickRepliesNotModified");
    s.store_class_end();
  }
}

object_ptr<messages_StickerSet> messages_StickerSet::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_stickerSet::ID:
      return messages_stickerSet::fetch(p);
    case messages_stickerSetNotModified::ID:
      return messages_stickerSetNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messages_stickerSet::messages_stickerSet(object_ptr<stickerSet> &&set_, array<object_ptr<stickerPack>> &&packs_, array<object_ptr<stickerKeyword>> &&keywords_, array<object_ptr<Document>> &&documents_)
  : set_(std::move(set_))
  , packs_(std::move(packs_))
  , keywords_(std::move(keywords_))
  , documents_(std::move(documents_))
{}

const std::int32_t messages_stickerSet::ID;

object_ptr<messages_StickerSet> messages_stickerSet::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickerSet>(p);
}

messages_stickerSet::messages_stickerSet(TlBufferParser &p)
  : set_(TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p))
  , packs_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerPack>, 313694676>>, 481674261>::parse(p))
  , keywords_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerKeyword>, -50416996>>, 481674261>::parse(p))
  , documents_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void messages_stickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickerSet");
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    { s.store_vector_begin("packs", packs_.size()); for (const auto &_value : packs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("keywords", keywords_.size()); for (const auto &_value : keywords_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_stickerSetNotModified::ID;

object_ptr<messages_StickerSet> messages_stickerSetNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickerSetNotModified>();
}

void messages_stickerSetNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickerSetNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_webPagePreview::ID;

object_ptr<messages_webPagePreview> messages_webPagePreview::fetch(TlBufferParser &p) {
  return make_tl_object<messages_webPagePreview>(p);
}

messages_webPagePreview::messages_webPagePreview(TlBufferParser &p)
  : media_(TlFetchObject<MessageMedia>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_webPagePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.webPagePreview");
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_exportedInvoice::ID;

object_ptr<payments_exportedInvoice> payments_exportedInvoice::fetch(TlBufferParser &p) {
  return make_tl_object<payments_exportedInvoice>(p);
}

payments_exportedInvoice::payments_exportedInvoice(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void payments_exportedInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.exportedInvoice");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

object_ptr<payments_PaymentResult> payments_PaymentResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_paymentResult::ID:
      return payments_paymentResult::fetch(p);
    case payments_paymentVerificationNeeded::ID:
      return payments_paymentVerificationNeeded::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t payments_paymentResult::ID;

object_ptr<payments_PaymentResult> payments_paymentResult::fetch(TlBufferParser &p) {
  return make_tl_object<payments_paymentResult>(p);
}

payments_paymentResult::payments_paymentResult(TlBufferParser &p)
  : updates_(TlFetchObject<Updates>::parse(p))
{}

void payments_paymentResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentResult");
    s.store_object_field("updates", static_cast<const BaseObject *>(updates_.get()));
    s.store_class_end();
  }
}

const std::int32_t payments_paymentVerificationNeeded::ID;

object_ptr<payments_PaymentResult> payments_paymentVerificationNeeded::fetch(TlBufferParser &p) {
  return make_tl_object<payments_paymentVerificationNeeded>(p);
}

payments_paymentVerificationNeeded::payments_paymentVerificationNeeded(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void payments_paymentVerificationNeeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentVerificationNeeded");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

payments_uniqueStarGiftValueInfo::payments_uniqueStarGiftValueInfo()
  : flags_()
  , last_sale_on_fragment_()
  , value_is_average_()
  , currency_()
  , value_()
  , initial_sale_date_()
  , initial_sale_stars_()
  , initial_sale_price_()
  , last_sale_date_()
  , last_sale_price_()
  , floor_price_()
  , average_price_()
  , listed_count_()
  , fragment_listed_count_()
  , fragment_listed_url_()
{}

const std::int32_t payments_uniqueStarGiftValueInfo::ID;

object_ptr<payments_uniqueStarGiftValueInfo> payments_uniqueStarGiftValueInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_uniqueStarGiftValueInfo> res = make_tl_object<payments_uniqueStarGiftValueInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->last_sale_on_fragment_ = (var0 & 2) != 0;
  res->value_is_average_ = (var0 & 64) != 0;
  res->currency_ = TlFetchString<string>::parse(p);
  res->value_ = TlFetchLong::parse(p);
  res->initial_sale_date_ = TlFetchInt::parse(p);
  res->initial_sale_stars_ = TlFetchLong::parse(p);
  res->initial_sale_price_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->last_sale_date_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->last_sale_price_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->floor_price_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->average_price_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->listed_count_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->fragment_listed_count_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->fragment_listed_url_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_uniqueStarGiftValueInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.uniqueStarGiftValueInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (last_sale_on_fragment_ << 1) | (value_is_average_ << 6) | ((!fragment_listed_url_.empty()) << 5)));
    if (var0 & 2) { s.store_field("last_sale_on_fragment", true); }
    if (var0 & 64) { s.store_field("value_is_average", true); }
    s.store_field("currency", currency_);
    s.store_field("value", value_);
    s.store_field("initial_sale_date", initial_sale_date_);
    s.store_field("initial_sale_stars", initial_sale_stars_);
    s.store_field("initial_sale_price", initial_sale_price_);
    if (var0 & 1) { s.store_field("last_sale_date", last_sale_date_); }
    if (var0 & 1) { s.store_field("last_sale_price", last_sale_price_); }
    if (var0 & 4) { s.store_field("floor_price", floor_price_); }
    if (var0 & 8) { s.store_field("average_price", average_price_); }
    if (var0 & 16) { s.store_field("listed_count", listed_count_); }
    if (var0 & 32) { s.store_field("fragment_listed_count", fragment_listed_count_); }
    if (var0 & 32) { s.store_field("fragment_listed_url", fragment_listed_url_); }
    s.store_class_end();
  }
}

const std::int32_t phone_groupCallStars::ID;

object_ptr<phone_groupCallStars> phone_groupCallStars::fetch(TlBufferParser &p) {
  return make_tl_object<phone_groupCallStars>(p);
}

phone_groupCallStars::phone_groupCallStars(TlBufferParser &p)
  : total_stars_(TlFetchLong::parse(p))
  , top_donors_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallDonor>, -297595771>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void phone_groupCallStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.groupCallStars");
    s.store_field("total_stars", total_stars_);
    { s.store_vector_begin("top_donors", top_donors_.size()); for (const auto &_value : top_donors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

phone_groupParticipants::phone_groupParticipants(int32 count_, array<object_ptr<groupCallParticipant>> &&participants_, string const &next_offset_, array<object_ptr<Chat>> &&chats_, array<object_ptr<User>> &&users_, int32 version_)
  : count_(count_)
  , participants_(std::move(participants_))
  , next_offset_(next_offset_)
  , chats_(std::move(chats_))
  , users_(std::move(users_))
  , version_(version_)
{}

const std::int32_t phone_groupParticipants::ID;

object_ptr<phone_groupParticipants> phone_groupParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<phone_groupParticipants>(p);
}

phone_groupParticipants::phone_groupParticipants(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , participants_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>>, 481674261>::parse(p))
  , next_offset_(TlFetchString<string>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void phone_groupParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.groupParticipants");
    s.store_field("count", count_);
    { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("version", version_);
    s.store_class_end();
  }
}

const std::int32_t phone_joinAsPeers::ID;

object_ptr<phone_joinAsPeers> phone_joinAsPeers::fetch(TlBufferParser &p) {
  return make_tl_object<phone_joinAsPeers>(p);
}

phone_joinAsPeers::phone_joinAsPeers(TlBufferParser &p)
  : peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void phone_joinAsPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.joinAsPeers");
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t phone_phoneCall::ID;

object_ptr<phone_phoneCall> phone_phoneCall::fetch(TlBufferParser &p) {
  return make_tl_object<phone_phoneCall>(p);
}

phone_phoneCall::phone_phoneCall(TlBufferParser &p)
  : phone_call_(TlFetchObject<PhoneCall>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void phone_phoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.phoneCall");
    s.store_object_field("phone_call", static_cast<const BaseObject *>(phone_call_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_stories::stories_stories()
  : flags_()
  , count_()
  , stories_()
  , pinned_to_top_()
  , chats_()
  , users_()
{}

const std::int32_t stories_stories::ID;

object_ptr<stories_stories> stories_stories::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_stories> res = make_tl_object<stories_stories>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->stories_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StoryItem>>, 481674261>::parse(p);
  if (var0 & 1) { res->pinned_to_top_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stories_stories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.stories");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!pinned_to_top_.empty()) << 0)));
    s.store_field("count", count_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { { s.store_vector_begin("pinned_to_top", pinned_to_top_.size()); for (const auto &_value : pinned_to_top_) { s.store_field("", _value); } s.store_class_end(); } }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updates_state::ID;

object_ptr<updates_state> updates_state::fetch(TlBufferParser &p) {
  return make_tl_object<updates_state>(p);
}

updates_state::updates_state(TlBufferParser &p)
  : pts_(TlFetchInt::parse(p))
  , qts_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , seq_(TlFetchInt::parse(p))
  , unread_count_(TlFetchInt::parse(p))
{}

void updates_state::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.state");
    s.store_field("pts", pts_);
    s.store_field("qts", qts_);
    s.store_field("date", date_);
    s.store_field("seq", seq_);
    s.store_field("unread_count", unread_count_);
    s.store_class_end();
  }
}

const std::int32_t wallet_holderDc::ID;

object_ptr<wallet_holderDc> wallet_holderDc::fetch(TlBufferParser &p) {
  return make_tl_object<wallet_holderDc>(p);
}

wallet_holderDc::wallet_holderDc(TlBufferParser &p)
  : dc_(TlFetchInt::parse(p))
  , public_key_(TlFetchBytes<bytes>::parse(p))
{}

void wallet_holderDc::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.holderDc");
    s.store_field("dc", dc_);
    s.store_bytes_field("public_key", public_key_);
    s.store_class_end();
  }
}

account_changeAuthorizationSettings::account_changeAuthorizationSettings(int32 flags_, bool confirmed_, int64 hash_, bool encrypted_requests_disabled_, bool call_requests_disabled_)
  : flags_(flags_)
  , confirmed_(confirmed_)
  , hash_(hash_)
  , encrypted_requests_disabled_(encrypted_requests_disabled_)
  , call_requests_disabled_(call_requests_disabled_)
{}

const std::int32_t account_changeAuthorizationSettings::ID;

void account_changeAuthorizationSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1089766498);
  TlStoreBinary::store((var0 = flags_ | (confirmed_ << 3)), s);
  TlStoreBinary::store(hash_, s);
  if (var0 & 1) { TlStoreBool::store(encrypted_requests_disabled_, s); }
  if (var0 & 2) { TlStoreBool::store(call_requests_disabled_, s); }
}

void account_changeAuthorizationSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1089766498);
  TlStoreBinary::store((var0 = flags_ | (confirmed_ << 3)), s);
  TlStoreBinary::store(hash_, s);
  if (var0 & 1) { TlStoreBool::store(encrypted_requests_disabled_, s); }
  if (var0 & 2) { TlStoreBool::store(call_requests_disabled_, s); }
}

void account_changeAuthorizationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.changeAuthorizationSettings");
    s.store_field("flags", (var0 = flags_ | (confirmed_ << 3)));
    if (var0 & 8) { s.store_field("confirmed", true); }
    s.store_field("hash", hash_);
    if (var0 & 1) { s.store_field("encrypted_requests_disabled", encrypted_requests_disabled_); }
    if (var0 & 2) { s.store_field("call_requests_disabled", call_requests_disabled_); }
    s.store_class_end();
  }
}

account_changeAuthorizationSettings::ReturnType account_changeAuthorizationSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_clearRecentEmojiStatuses::ID;

void account_clearRecentEmojiStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(404757166);
}

void account_clearRecentEmojiStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(404757166);
}

void account_clearRecentEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.clearRecentEmojiStatuses");
    s.store_class_end();
  }
}

account_clearRecentEmojiStatuses::ReturnType account_clearRecentEmojiStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_finishTakeoutSession::account_finishTakeoutSession(int32 flags_, bool success_)
  : flags_(flags_)
  , success_(success_)
{}

const std::int32_t account_finishTakeoutSession::ID;

void account_finishTakeoutSession::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(489050862);
  TlStoreBinary::store((var0 = flags_ | (success_ << 0)), s);
}

void account_finishTakeoutSession::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(489050862);
  TlStoreBinary::store((var0 = flags_ | (success_ << 0)), s);
}

void account_finishTakeoutSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.finishTakeoutSession");
    s.store_field("flags", (var0 = flags_ | (success_ << 0)));
    if (var0 & 1) { s.store_field("success", true); }
    s.store_class_end();
  }
}

account_finishTakeoutSession::ReturnType account_finishTakeoutSession::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_getAccountTTL::ID;

void account_getAccountTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(150761757);
}

void account_getAccountTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(150761757);
}

void account_getAccountTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAccountTTL");
    s.store_class_end();
  }
}

account_getAccountTTL::ReturnType account_getAccountTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<accountDaysTTL>, -1194283041>::parse(p);
#undef FAIL
}

const std::int32_t account_getContactSignUpNotification::ID;

void account_getContactSignUpNotification::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1626880216);
}

void account_getContactSignUpNotification::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1626880216);
}

void account_getContactSignUpNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getContactSignUpNotification");
    s.store_class_end();
  }
}

account_getContactSignUpNotification::ReturnType account_getContactSignUpNotification::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_getThemes::account_getThemes(string const &format_, int64 hash_)
  : format_(format_)
  , hash_(hash_)
{}

const std::int32_t account_getThemes::ID;

void account_getThemes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1913054296);
  TlStoreString::store(format_, s);
  TlStoreBinary::store(hash_, s);
}

void account_getThemes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1913054296);
  TlStoreString::store(format_, s);
  TlStoreBinary::store(hash_, s);
}

void account_getThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getThemes");
    s.store_field("format", format_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getThemes::ReturnType account_getThemes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_Themes>::parse(p);
#undef FAIL
}

const std::int32_t account_resendPasswordEmail::ID;

void account_resendPasswordEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2055154197);
}

void account_resendPasswordEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2055154197);
}

void account_resendPasswordEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resendPasswordEmail");
    s.store_class_end();
  }
}

account_resendPasswordEmail::ReturnType account_resendPasswordEmail::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_setContactSignUpNotification::account_setContactSignUpNotification(bool silent_)
  : silent_(silent_)
{}

const std::int32_t account_setContactSignUpNotification::ID;

void account_setContactSignUpNotification::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-806076575);
  TlStoreBool::store(silent_, s);
}

void account_setContactSignUpNotification::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-806076575);
  TlStoreBool::store(silent_, s);
}

void account_setContactSignUpNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setContactSignUpNotification");
    s.store_field("silent", silent_);
    s.store_class_end();
  }
}

account_setContactSignUpNotification::ReturnType account_setContactSignUpNotification::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_setPrivacy::account_setPrivacy(object_ptr<InputPrivacyKey> &&key_, array<object_ptr<InputPrivacyRule>> &&rules_)
  : key_(std::move(key_))
  , rules_(std::move(rules_))
{}

const std::int32_t account_setPrivacy::ID;

void account_setPrivacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-906486552);
  TlStoreBoxedUnknown<TlStoreObject>::store(key_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(rules_, s);
}

void account_setPrivacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-906486552);
  TlStoreBoxedUnknown<TlStoreObject>::store(key_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(rules_, s);
}

void account_setPrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setPrivacy");
    s.store_object_field("key", static_cast<const BaseObject *>(key_.get()));
    { s.store_vector_begin("rules", rules_.size()); for (const auto &_value : rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_setPrivacy::ReturnType account_setPrivacy::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_privacyRules>, 1352683077>::parse(p);
#undef FAIL
}

account_toggleConnectedBotPaused::account_toggleConnectedBotPaused(object_ptr<InputPeer> &&peer_, bool paused_)
  : peer_(std::move(peer_))
  , paused_(paused_)
{}

const std::int32_t account_toggleConnectedBotPaused::ID;

void account_toggleConnectedBotPaused::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1684934807);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(paused_, s);
}

void account_toggleConnectedBotPaused::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1684934807);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(paused_, s);
}

void account_toggleConnectedBotPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.toggleConnectedBotPaused");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("paused", paused_);
    s.store_class_end();
  }
}

account_toggleConnectedBotPaused::ReturnType account_toggleConnectedBotPaused::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_toggleNoPaidMessagesException::account_toggleNoPaidMessagesException(int32 flags_, bool refund_charged_, bool require_payment_, object_ptr<InputPeer> &&parent_peer_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , refund_charged_(refund_charged_)
  , require_payment_(require_payment_)
  , parent_peer_(std::move(parent_peer_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t account_toggleNoPaidMessagesException::ID;

void account_toggleNoPaidMessagesException::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-30483850);
  TlStoreBinary::store((var0 = flags_ | (refund_charged_ << 0) | (require_payment_ << 2) | ((parent_peer_ != nullptr) << 1)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void account_toggleNoPaidMessagesException::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-30483850);
  TlStoreBinary::store((var0 = flags_ | (refund_charged_ << 0) | (require_payment_ << 2) | ((parent_peer_ != nullptr) << 1)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void account_toggleNoPaidMessagesException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.toggleNoPaidMessagesException");
    s.store_field("flags", (var0 = flags_ | (refund_charged_ << 0) | (require_payment_ << 2) | ((parent_peer_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("refund_charged", true); }
    if (var0 & 4) { s.store_field("require_payment", true); }
    if (var0 & 2) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

account_toggleNoPaidMessagesException::ReturnType account_toggleNoPaidMessagesException::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateStatus::account_updateStatus(bool offline_)
  : offline_(offline_)
{}

const std::int32_t account_updateStatus::ID;

void account_updateStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1713919532);
  TlStoreBool::store(offline_, s);
}

void account_updateStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1713919532);
  TlStoreBool::store(offline_, s);
}

void account_updateStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateStatus");
    s.store_field("offline", offline_);
    s.store_class_end();
  }
}

account_updateStatus::ReturnType account_updateStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

aicompose_getToneExample::aicompose_getToneExample(object_ptr<InputAiComposeTone> &&tone_, int32 num_)
  : tone_(std::move(tone_))
  , num_(num_)
{}

const std::int32_t aicompose_getToneExample::ID;

void aicompose_getToneExample::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-776688876);
  TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s);
  TlStoreBinary::store(num_, s);
}

void aicompose_getToneExample::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-776688876);
  TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s);
  TlStoreBinary::store(num_, s);
}

void aicompose_getToneExample::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aicompose.getToneExample");
    s.store_object_field("tone", static_cast<const BaseObject *>(tone_.get()));
    s.store_field("num", num_);
    s.store_class_end();
  }
}

aicompose_getToneExample::ReturnType aicompose_getToneExample::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<aiComposeToneExample>, -237623060>::parse(p);
#undef FAIL
}

aicompose_setChatStyle::aicompose_setChatStyle(int32 flags_, object_ptr<InputPeer> &&peer_, object_ptr<inputAiComposeStyle> &&style_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , style_(std::move(style_))
{}

const std::int32_t aicompose_setChatStyle::ID;

void aicompose_setChatStyle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1570322880);
  TlStoreBinary::store((var0 = flags_ | ((style_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1474231824>::store(style_, s); }
}

void aicompose_setChatStyle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1570322880);
  TlStoreBinary::store((var0 = flags_ | ((style_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1474231824>::store(style_, s); }
}

void aicompose_setChatStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aicompose.setChatStyle");
    s.store_field("flags", (var0 = flags_ | ((style_ != nullptr) << 0)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_class_end();
  }
}

aicompose_setChatStyle::ReturnType aicompose_setChatStyle::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_checkPassword::auth_checkPassword(object_ptr<InputCheckPasswordSRP> &&password_)
  : password_(std::move(password_))
{}

const std::int32_t auth_checkPassword::ID;

void auth_checkPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-779399914);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void auth_checkPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-779399914);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void auth_checkPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.checkPassword");
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

auth_checkPassword::ReturnType auth_checkPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

bots_createBot::bots_createBot(int32 flags_, bool via_deeplink_, string const &name_, string const &username_, object_ptr<InputUser> &&manager_id_)
  : flags_(flags_)
  , via_deeplink_(via_deeplink_)
  , name_(name_)
  , username_(username_)
  , manager_id_(std::move(manager_id_))
{}

const std::int32_t bots_createBot::ID;

void bots_createBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-441352405);
  TlStoreBinary::store((var0 = flags_ | (via_deeplink_ << 0)), s);
  TlStoreString::store(name_, s);
  TlStoreString::store(username_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(manager_id_, s);
}

void bots_createBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-441352405);
  TlStoreBinary::store((var0 = flags_ | (via_deeplink_ << 0)), s);
  TlStoreString::store(name_, s);
  TlStoreString::store(username_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(manager_id_, s);
}

void bots_createBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.createBot");
    s.store_field("flags", (var0 = flags_ | (via_deeplink_ << 0)));
    if (var0 & 1) { s.store_field("via_deeplink", true); }
    s.store_field("name", name_);
    s.store_field("username", username_);
    s.store_object_field("manager_id", static_cast<const BaseObject *>(manager_id_.get()));
    s.store_class_end();
  }
}

bots_createBot::ReturnType bots_createBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

bots_setJoinChatResults::bots_setJoinChatResults(int64 query_id_, object_ptr<JoinChatBotResult> &&result_)
  : query_id_(query_id_)
  , result_(std::move(result_))
{}

const std::int32_t bots_setJoinChatResults::ID;

void bots_setJoinChatResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-417708016);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
}

void bots_setJoinChatResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-417708016);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
}

void bots_setJoinChatResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setJoinChatResults");
    s.store_field("query_id", query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_class_end();
  }
}

bots_setJoinChatResults::ReturnType bots_setJoinChatResults::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_toggleUserEmojiStatusPermission::bots_toggleUserEmojiStatusPermission(object_ptr<InputUser> &&bot_, bool enabled_)
  : bot_(std::move(bot_))
  , enabled_(enabled_)
{}

const std::int32_t bots_toggleUserEmojiStatusPermission::ID;

void bots_toggleUserEmojiStatusPermission::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(115237778);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(enabled_, s);
}

void bots_toggleUserEmojiStatusPermission::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(115237778);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(enabled_, s);
}

void bots_toggleUserEmojiStatusPermission::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.toggleUserEmojiStatusPermission");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

bots_toggleUserEmojiStatusPermission::ReturnType bots_toggleUserEmojiStatusPermission::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_setMainProfileTab::channels_setMainProfileTab(object_ptr<InputChannel> &&channel_, object_ptr<ProfileTab> &&tab_)
  : channel_(std::move(channel_))
  , tab_(std::move(tab_))
{}

const std::int32_t channels_setMainProfileTab::ID;

void channels_setMainProfileTab::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(897842353);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(tab_, s);
}

void channels_setMainProfileTab::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(897842353);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(tab_, s);
}

void channels_setMainProfileTab::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.setMainProfileTab");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("tab", static_cast<const BaseObject *>(tab_.get()));
    s.store_class_end();
  }
}

channels_setMainProfileTab::ReturnType channels_setMainProfileTab::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_toggleJoinRequest::channels_toggleJoinRequest(int32 flags_, bool apply_to_invites_, object_ptr<InputChannel> &&channel_, bool enabled_, object_ptr<InputUser> &&guard_bot_)
  : flags_(flags_)
  , apply_to_invites_(apply_to_invites_)
  , channel_(std::move(channel_))
  , enabled_(enabled_)
  , guard_bot_(std::move(guard_bot_))
{}

const std::int32_t channels_toggleJoinRequest::ID;

void channels_toggleJoinRequest::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(248260120);
  TlStoreBinary::store((var0 = flags_ | (apply_to_invites_ << 1) | ((guard_bot_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(guard_bot_, s); }
}

void channels_toggleJoinRequest::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(248260120);
  TlStoreBinary::store((var0 = flags_ | (apply_to_invites_ << 1) | ((guard_bot_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(guard_bot_, s); }
}

void channels_toggleJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleJoinRequest");
    s.store_field("flags", (var0 = flags_ | (apply_to_invites_ << 1) | ((guard_bot_ != nullptr) << 0)));
    if (var0 & 2) { s.store_field("apply_to_invites", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    if (var0 & 1) { s.store_object_field("guard_bot", static_cast<const BaseObject *>(guard_bot_.get())); }
    s.store_class_end();
  }
}

channels_toggleJoinRequest::ReturnType channels_toggleJoinRequest::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_toggleJoinToSend::channels_toggleJoinToSend(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_toggleJoinToSend::ID;

void channels_toggleJoinToSend::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-456419968);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleJoinToSend::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-456419968);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleJoinToSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleJoinToSend");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_toggleJoinToSend::ReturnType channels_toggleJoinToSend::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

chatlists_joinChatlistUpdates::chatlists_joinChatlistUpdates(object_ptr<inputChatlistDialogFilter> &&chatlist_, array<object_ptr<InputPeer>> &&peers_)
  : chatlist_(std::move(chatlist_))
  , peers_(std::move(peers_))
{}

const std::int32_t chatlists_joinChatlistUpdates::ID;

void chatlists_joinChatlistUpdates::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-527828747);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_joinChatlistUpdates::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-527828747);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_joinChatlistUpdates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.joinChatlistUpdates");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatlists_joinChatlistUpdates::ReturnType chatlists_joinChatlistUpdates::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

communities_create::communities_create(int32 flags_, bool hidden_, string const &title_, string const &about_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , hidden_(hidden_)
  , title_(title_)
  , about_(about_)
  , peer_(std::move(peer_))
{}

const std::int32_t communities_create::ID;

void communities_create::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1506256404);
  TlStoreBinary::store((var0 = flags_ | (hidden_ << 1) | ((!about_.empty()) << 0)), s);
  TlStoreString::store(title_, s);
  if (var0 & 1) { TlStoreString::store(about_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void communities_create::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1506256404);
  TlStoreBinary::store((var0 = flags_ | (hidden_ << 1) | ((!about_.empty()) << 0)), s);
  TlStoreString::store(title_, s);
  if (var0 & 1) { TlStoreString::store(about_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void communities_create::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities.create");
    s.store_field("flags", (var0 = flags_ | (hidden_ << 1) | ((!about_.empty()) << 0)));
    if (var0 & 2) { s.store_field("hidden", true); }
    s.store_field("title", title_);
    if (var0 & 1) { s.store_field("about", about_); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

communities_create::ReturnType communities_create::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

communities_togglePeerLinkRequestApproval::communities_togglePeerLinkRequestApproval(int32 flags_, bool reject_, object_ptr<InputChannel> &&community_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , reject_(reject_)
  , community_(std::move(community_))
  , peer_(std::move(peer_))
{}

const std::int32_t communities_togglePeerLinkRequestApproval::ID;

void communities_togglePeerLinkRequestApproval::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1937630808);
  TlStoreBinary::store((var0 = flags_ | (reject_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void communities_togglePeerLinkRequestApproval::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1937630808);
  TlStoreBinary::store((var0 = flags_ | (reject_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void communities_togglePeerLinkRequestApproval::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities.togglePeerLinkRequestApproval");
    s.store_field("flags", (var0 = flags_ | (reject_ << 0)));
    if (var0 & 1) { s.store_field("reject", true); }
    s.store_object_field("community", static_cast<const BaseObject *>(community_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

communities_togglePeerLinkRequestApproval::ReturnType communities_togglePeerLinkRequestApproval::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

contacts_getBlocked::contacts_getBlocked(int32 flags_, bool my_stories_from_, int32 offset_, int32 limit_)
  : flags_(flags_)
  , my_stories_from_(my_stories_from_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t contacts_getBlocked::ID;

void contacts_getBlocked::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1702457472);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_getBlocked::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1702457472);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_getBlocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getBlocked");
    s.store_field("flags", (var0 = flags_ | (my_stories_from_ << 0)));
    if (var0 & 1) { s.store_field("my_stories_from", true); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

contacts_getBlocked::ReturnType contacts_getBlocked::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<contacts_Blocked>::parse(p);
#undef FAIL
}

contacts_getLocated::contacts_getLocated(int32 flags_, bool background_, object_ptr<InputGeoPoint> &&geo_point_, int32 self_expires_)
  : flags_(flags_)
  , background_(background_)
  , geo_point_(std::move(geo_point_))
  , self_expires_(self_expires_)
{}

const std::int32_t contacts_getLocated::ID;

void contacts_getLocated::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-750207932);
  TlStoreBinary::store((var0 = flags_ | (background_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 1) { TlStoreBinary::store(self_expires_, s); }
}

void contacts_getLocated::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-750207932);
  TlStoreBinary::store((var0 = flags_ | (background_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 1) { TlStoreBinary::store(self_expires_, s); }
}

void contacts_getLocated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getLocated");
    s.store_field("flags", (var0 = flags_ | (background_ << 1)));
    if (var0 & 2) { s.store_field("background", true); }
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    if (var0 & 1) { s.store_field("self_expires", self_expires_); }
    s.store_class_end();
  }
}

contacts_getLocated::ReturnType contacts_getLocated::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t contacts_getSaved::ID;

void contacts_getSaved::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2098076769);
}

void contacts_getSaved::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2098076769);
}

void contacts_getSaved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getSaved");
    s.store_class_end();
  }
}

contacts_getSaved::ReturnType contacts_getSaved::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<savedPhoneContact>, 289586518>>, 481674261>::parse(p);
#undef FAIL
}

contacts_setBlocked::contacts_setBlocked(int32 flags_, bool my_stories_from_, array<object_ptr<InputPeer>> &&id_, int32 limit_)
  : flags_(flags_)
  , my_stories_from_(my_stories_from_)
  , id_(std::move(id_))
  , limit_(limit_)
{}

const std::int32_t contacts_setBlocked::ID;

void contacts_setBlocked::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1798939530);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_setBlocked::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1798939530);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_setBlocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.setBlocked");
    s.store_field("flags", (var0 = flags_ | (my_stories_from_ << 0)));
    if (var0 & 1) { s.store_field("my_stories_from", true); }
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

contacts_setBlocked::ReturnType contacts_setBlocked::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

ephemeral_reportMessage::ephemeral_reportMessage(object_ptr<InputPeer> &&peer_, int32 id_, bytes &&option_, string const &message_)
  : peer_(std::move(peer_))
  , id_(id_)
  , option_(std::move(option_))
  , message_(message_)
{}

const std::int32_t ephemeral_reportMessage::ID;

void ephemeral_reportMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2029718849);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(option_, s);
  TlStoreString::store(message_, s);
}

void ephemeral_reportMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2029718849);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(option_, s);
  TlStoreString::store(message_, s);
}

void ephemeral_reportMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeral.reportMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_bytes_field("option", option_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

ephemeral_reportMessage::ReturnType ephemeral_reportMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<ReportResult>::parse(p);
#undef FAIL
}

help_getAppConfig::help_getAppConfig(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t help_getAppConfig::ID;

void help_getAppConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1642330196);
  TlStoreBinary::store(hash_, s);
}

void help_getAppConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1642330196);
  TlStoreBinary::store(hash_, s);
}

void help_getAppConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getAppConfig");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getAppConfig::ReturnType help_getAppConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_AppConfig>::parse(p);
#undef FAIL
}

invokeWithApnsSecretPrefix::invokeWithApnsSecretPrefix(string const &nonce_, string const &secret_)
  : nonce_(nonce_)
  , secret_(secret_)
{}

const std::int32_t invokeWithApnsSecretPrefix::ID;

void invokeWithApnsSecretPrefix::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(229528824);
  TlStoreString::store(nonce_, s);
  TlStoreString::store(secret_, s);
}

void invokeWithApnsSecretPrefix::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(229528824);
  TlStoreString::store(nonce_, s);
  TlStoreString::store(secret_, s);
}

void invokeWithApnsSecretPrefix::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invokeWithApnsSecretPrefix");
    s.store_field("nonce", nonce_);
    s.store_field("secret", "[REDACTED]");
    s.store_class_end();
  }
}

invokeWithApnsSecretPrefix::ReturnType invokeWithApnsSecretPrefix::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<error>, -994444869>::parse(p);
#undef FAIL
}

langpack_getLanguages::langpack_getLanguages(string const &lang_pack_)
  : lang_pack_(lang_pack_)
{}

const std::int32_t langpack_getLanguages::ID;

void langpack_getLanguages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1120311183);
  TlStoreString::store(lang_pack_, s);
}

void langpack_getLanguages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1120311183);
  TlStoreString::store(lang_pack_, s);
}

void langpack_getLanguages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langpack.getLanguages");
    s.store_field("lang_pack", lang_pack_);
    s.store_class_end();
  }
}

langpack_getLanguages::ReturnType langpack_getLanguages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<langPackLanguage>, -288727837>>, 481674261>::parse(p);
#undef FAIL
}

messages_checkHistoryImport::messages_checkHistoryImport(string const &import_head_)
  : import_head_(import_head_)
{}

const std::int32_t messages_checkHistoryImport::ID;

void messages_checkHistoryImport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1140726259);
  TlStoreString::store(import_head_, s);
}

void messages_checkHistoryImport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1140726259);
  TlStoreString::store(import_head_, s);
}

void messages_checkHistoryImport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkHistoryImport");
    s.store_field("import_head", import_head_);
    s.store_class_end();
  }
}

messages_checkHistoryImport::ReturnType messages_checkHistoryImport::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_historyImportParsed>, 1578088377>::parse(p);
#undef FAIL
}

messages_checkHistoryImportPeer::messages_checkHistoryImportPeer(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_checkHistoryImportPeer::ID;

void messages_checkHistoryImportPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1573261059);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_checkHistoryImportPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1573261059);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_checkHistoryImportPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkHistoryImportPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_checkHistoryImportPeer::ReturnType messages_checkHistoryImportPeer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_checkedHistoryImportPeer>, -1571952873>::parse(p);
#undef FAIL
}

messages_deleteQuickReplyShortcut::messages_deleteQuickReplyShortcut(int32 shortcut_id_)
  : shortcut_id_(shortcut_id_)
{}

const std::int32_t messages_deleteQuickReplyShortcut::ID;

void messages_deleteQuickReplyShortcut::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1019234112);
  TlStoreBinary::store(shortcut_id_, s);
}

void messages_deleteQuickReplyShortcut::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1019234112);
  TlStoreBinary::store(shortcut_id_, s);
}

void messages_deleteQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteQuickReplyShortcut");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

messages_deleteQuickReplyShortcut::ReturnType messages_deleteQuickReplyShortcut::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_editQuickReplyShortcut::messages_editQuickReplyShortcut(int32 shortcut_id_, string const &shortcut_)
  : shortcut_id_(shortcut_id_)
  , shortcut_(shortcut_)
{}

const std::int32_t messages_editQuickReplyShortcut::ID;

void messages_editQuickReplyShortcut::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1543519471);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreString::store(shortcut_, s);
}

void messages_editQuickReplyShortcut::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1543519471);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreString::store(shortcut_, s);
}

void messages_editQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editQuickReplyShortcut");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_field("shortcut", shortcut_);
    s.store_class_end();
  }
}

messages_editQuickReplyShortcut::ReturnType messages_editQuickReplyShortcut::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_getArchivedStickers::messages_getArchivedStickers(int32 flags_, bool masks_, bool emojis_, int64 offset_id_, int32 limit_)
  : flags_(flags_)
  , masks_(masks_)
  , emojis_(emojis_)
  , offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t messages_getArchivedStickers::ID;

void messages_getArchivedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1475442322);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 1)), s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getArchivedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1475442322);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 1)), s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getArchivedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getArchivedStickers");
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 1)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 2) { s.store_field("emojis", true); }
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getArchivedStickers::ReturnType messages_getArchivedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_archivedStickers>, 1338747336>::parse(p);
#undef FAIL
}

messages_getAttachMenuBot::messages_getAttachMenuBot(object_ptr<InputUser> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t messages_getAttachMenuBot::ID;

void messages_getAttachMenuBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1998676370);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void messages_getAttachMenuBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1998676370);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void messages_getAttachMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAttachMenuBot");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

messages_getAttachMenuBot::ReturnType messages_getAttachMenuBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<attachMenuBotsBot>, -1816172929>::parse(p);
#undef FAIL
}

messages_getAttachedStickers::messages_getAttachedStickers(object_ptr<InputStickeredMedia> &&media_)
  : media_(std::move(media_))
{}

const std::int32_t messages_getAttachedStickers::ID;

void messages_getAttachedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-866424884);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_getAttachedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-866424884);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_getAttachedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAttachedStickers");
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

messages_getAttachedStickers::ReturnType messages_getAttachedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p);
#undef FAIL
}

messages_getAvailableEffects::messages_getAvailableEffects(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getAvailableEffects::ID;

void messages_getAvailableEffects::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-559805895);
  TlStoreBinary::store(hash_, s);
}

void messages_getAvailableEffects::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-559805895);
  TlStoreBinary::store(hash_, s);
}

void messages_getAvailableEffects::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAvailableEffects");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getAvailableEffects::ReturnType messages_getAvailableEffects::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_AvailableEffects>::parse(p);
#undef FAIL
}

messages_getBotCallbackAnswer::messages_getBotCallbackAnswer(int32 flags_, bool game_, object_ptr<InputPeer> &&peer_, int32 msg_id_, bytes &&data_, object_ptr<InputCheckPasswordSRP> &&password_)
  : flags_(flags_)
  , game_(game_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , data_(std::move(data_))
  , password_(std::move(password_))
{}

const std::int32_t messages_getBotCallbackAnswer::ID;

void messages_getBotCallbackAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1824339449);
  TlStoreBinary::store((var0 = flags_ | (game_ << 1) | ((!data_.empty()) << 0) | ((password_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreString::store(data_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void messages_getBotCallbackAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1824339449);
  TlStoreBinary::store((var0 = flags_ | (game_ << 1) | ((!data_.empty()) << 0) | ((password_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreString::store(data_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void messages_getBotCallbackAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getBotCallbackAnswer");
    s.store_field("flags", (var0 = flags_ | (game_ << 1) | ((!data_.empty()) << 0) | ((password_ != nullptr) << 2)));
    if (var0 & 2) { s.store_field("game", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    if (var0 & 1) { s.store_bytes_field("data", data_); }
    if (var0 & 4) { s.store_field("password", "[REDACTED]"); }
    s.store_class_end();
  }
}

messages_getBotCallbackAnswer::ReturnType messages_getBotCallbackAnswer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_botCallbackAnswer>, 911761060>::parse(p);
#undef FAIL
}

messages_getCustomEmojiDocuments::messages_getCustomEmojiDocuments(array<int64> &&document_id_)
  : document_id_(std::move(document_id_))
{}

const std::int32_t messages_getCustomEmojiDocuments::ID;

void messages_getCustomEmojiDocuments::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-643100844);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(document_id_, s);
}

void messages_getCustomEmojiDocuments::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-643100844);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(document_id_, s);
}

void messages_getCustomEmojiDocuments::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getCustomEmojiDocuments");
    { s.store_vector_begin("document_id", document_id_.size()); for (const auto &_value : document_id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getCustomEmojiDocuments::ReturnType messages_getCustomEmojiDocuments::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p);
#undef FAIL
}

messages_getEmojiKeywordsLanguages::messages_getEmojiKeywordsLanguages(array<string> &&lang_codes_)
  : lang_codes_(std::move(lang_codes_))
{}

const std::int32_t messages_getEmojiKeywordsLanguages::ID;

void messages_getEmojiKeywordsLanguages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1318675378);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(lang_codes_, s);
}

void messages_getEmojiKeywordsLanguages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1318675378);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(lang_codes_, s);
}

void messages_getEmojiKeywordsLanguages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiKeywordsLanguages");
    { s.store_vector_begin("lang_codes", lang_codes_.size()); for (const auto &_value : lang_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getEmojiKeywordsLanguages::ReturnType messages_getEmojiKeywordsLanguages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<emojiLanguage>, -1275374751>>, 481674261>::parse(p);
#undef FAIL
}

messages_getExtendedMedia::messages_getExtendedMedia(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_getExtendedMedia::ID;

void messages_getExtendedMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2064119788);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getExtendedMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2064119788);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getExtendedMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getExtendedMedia");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getExtendedMedia::ReturnType messages_getExtendedMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getMessagesReactions::messages_getMessagesReactions(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_getMessagesReactions::ID;

void messages_getMessagesReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1950707482);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getMessagesReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1950707482);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getMessagesReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessagesReactions");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getMessagesReactions::ReturnType messages_getMessagesReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getOutboxReadDate::messages_getOutboxReadDate(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_getOutboxReadDate::ID;

void messages_getOutboxReadDate::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1941176739);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getOutboxReadDate::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1941176739);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getOutboxReadDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getOutboxReadDate");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

messages_getOutboxReadDate::ReturnType messages_getOutboxReadDate::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<outboxReadDate>, 1001931436>::parse(p);
#undef FAIL
}

messages_getQuickReplies::messages_getQuickReplies(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getQuickReplies::ID;

void messages_getQuickReplies::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-729550168);
  TlStoreBinary::store(hash_, s);
}

void messages_getQuickReplies::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-729550168);
  TlStoreBinary::store(hash_, s);
}

void messages_getQuickReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getQuickReplies");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getQuickReplies::ReturnType messages_getQuickReplies::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_QuickReplies>::parse(p);
#undef FAIL
}

messages_getRecentLocations::messages_getRecentLocations(object_ptr<InputPeer> &&peer_, int32 limit_, int64 hash_)
  : peer_(std::move(peer_))
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getRecentLocations::ID;

void messages_getRecentLocations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1881817312);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentLocations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1881817312);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentLocations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getRecentLocations");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getRecentLocations::ReturnType messages_getRecentLocations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getRichMessage::messages_getRichMessage(object_ptr<InputPeer> &&peer_, int32 id_)
  : peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t messages_getRichMessage::ID;

void messages_getRichMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1343580623);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void messages_getRichMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1343580623);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void messages_getRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getRichMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

messages_getRichMessage::ReturnType messages_getRichMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getSavedReactionTags::messages_getSavedReactionTags(int32 flags_, object_ptr<InputPeer> &&peer_, int64 hash_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , hash_(hash_)
{}

const std::int32_t messages_getSavedReactionTags::ID;

void messages_getSavedReactionTags::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(909631579);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedReactionTags::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(909631579);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedReactionTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSavedReactionTags");
    s.store_field("flags", (var0 = flags_ | ((peer_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getSavedReactionTags::ReturnType messages_getSavedReactionTags::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SavedReactionTags>::parse(p);
#undef FAIL
}

messages_receivedQueue::messages_receivedQueue(int32 max_qts_)
  : max_qts_(max_qts_)
{}

const std::int32_t messages_receivedQueue::ID;

void messages_receivedQueue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1436924774);
  TlStoreBinary::store(max_qts_, s);
}

void messages_receivedQueue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1436924774);
  TlStoreBinary::store(max_qts_, s);
}

void messages_receivedQueue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.receivedQueue");
    s.store_field("max_qts", max_qts_);
    s.store_class_end();
  }
}

messages_receivedQueue::ReturnType messages_receivedQueue::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
#undef FAIL
}

messages_requestMainWebView::messages_requestMainWebView(int32 flags_, bool compact_, bool fullscreen_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&bot_, string const &start_param_, object_ptr<dataJSON> &&theme_params_, string const &platform_)
  : flags_(flags_)
  , compact_(compact_)
  , fullscreen_(fullscreen_)
  , peer_(std::move(peer_))
  , bot_(std::move(bot_))
  , start_param_(start_param_)
  , theme_params_(std::move(theme_params_))
  , platform_(platform_)
{}

const std::int32_t messages_requestMainWebView::ID;

void messages_requestMainWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-908059013);
  TlStoreBinary::store((var0 = flags_ | (compact_ << 7) | (fullscreen_ << 8) | ((!start_param_.empty()) << 1) | ((theme_params_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestMainWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-908059013);
  TlStoreBinary::store((var0 = flags_ | (compact_ << 7) | (fullscreen_ << 8) | ((!start_param_.empty()) << 1) | ((theme_params_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestMainWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestMainWebView");
    s.store_field("flags", (var0 = flags_ | (compact_ << 7) | (fullscreen_ << 8) | ((!start_param_.empty()) << 1) | ((theme_params_ != nullptr) << 0)));
    if (var0 & 128) { s.store_field("compact", true); }
    if (var0 & 256) { s.store_field("fullscreen", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    if (var0 & 2) { s.store_field("start_param", start_param_); }
    if (var0 & 1) { s.store_object_field("theme_params", static_cast<const BaseObject *>(theme_params_.get())); }
    s.store_field("platform", platform_);
    s.store_class_end();
  }
}

messages_requestMainWebView::ReturnType messages_requestMainWebView::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<webViewResultUrl>, 1294139288>::parse(p);
#undef FAIL
}

messages_saveDraft::messages_saveDraft(int32 flags_, bool no_webpage_, bool invert_media_, object_ptr<InputReplyTo> &&reply_to_, object_ptr<InputPeer> &&peer_, string const &message_, array<object_ptr<MessageEntity>> &&entities_, object_ptr<InputMedia> &&media_, int64 effect_, object_ptr<suggestedPost> &&suggested_post_, object_ptr<InputRichMessage> &&rich_message_)
  : flags_(flags_)
  , no_webpage_(no_webpage_)
  , invert_media_(invert_media_)
  , reply_to_(std::move(reply_to_))
  , peer_(std::move(peer_))
  , message_(message_)
  , entities_(std::move(entities_))
  , media_(std::move(media_))
  , effect_(effect_)
  , suggested_post_(std::move(suggested_post_))
  , rich_message_(std::move(rich_message_))
{}

const std::int32_t messages_saveDraft::ID;

void messages_saveDraft::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1391484580);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 6) | ((reply_to_ != nullptr) << 4) | ((!entities_.empty()) << 3) | ((media_ != nullptr) << 5) | ((suggested_post_ != nullptr) << 8) | ((rich_message_ != nullptr) << 9)), s);
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(message_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 128) { TlStoreBinary::store(effect_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
}

void messages_saveDraft::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1391484580);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 6) | ((reply_to_ != nullptr) << 4) | ((!entities_.empty()) << 3) | ((media_ != nullptr) << 5) | ((suggested_post_ != nullptr) << 8) | ((rich_message_ != nullptr) << 9)), s);
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(message_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 128) { TlStoreBinary::store(effect_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
}

void messages_saveDraft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.saveDraft");
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 6) | ((reply_to_ != nullptr) << 4) | ((!entities_.empty()) << 3) | ((media_ != nullptr) << 5) | ((suggested_post_ != nullptr) << 8) | ((rich_message_ != nullptr) << 9)));
    if (var0 & 2) { s.store_field("no_webpage", true); }
    if (var0 & 64) { s.store_field("invert_media", true); }
    if (var0 & 16) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("message", message_);
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 128) { s.store_field("effect", effect_); }
    if (var0 & 256) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    if (var0 & 512) { s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get())); }
    s.store_class_end();
  }
}

messages_saveDraft::ReturnType messages_saveDraft::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_sendReaction::messages_sendReaction(int32 flags_, bool big_, bool add_to_recent_, object_ptr<InputPeer> &&peer_, int32 msg_id_, array<object_ptr<Reaction>> &&reaction_)
  : flags_(flags_)
  , big_(big_)
  , add_to_recent_(add_to_recent_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , reaction_(std::move(reaction_))
{}

const std::int32_t messages_sendReaction::ID;

void messages_sendReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-754091820);
  TlStoreBinary::store((var0 = flags_ | (big_ << 1) | (add_to_recent_ << 2) | ((!reaction_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(reaction_, s); }
}

void messages_sendReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-754091820);
  TlStoreBinary::store((var0 = flags_ | (big_ << 1) | (add_to_recent_ << 2) | ((!reaction_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(reaction_, s); }
}

void messages_sendReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendReaction");
    s.store_field("flags", (var0 = flags_ | (big_ << 1) | (add_to_recent_ << 2) | ((!reaction_.empty()) << 0)));
    if (var0 & 2) { s.store_field("big", true); }
    if (var0 & 4) { s.store_field("add_to_recent", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    if (var0 & 1) { { s.store_vector_begin("reaction", reaction_.size()); for (const auto &_value : reaction_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messages_sendReaction::ReturnType messages_sendReaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setDefaultReaction::messages_setDefaultReaction(object_ptr<Reaction> &&reaction_)
  : reaction_(std::move(reaction_))
{}

const std::int32_t messages_setDefaultReaction::ID;

void messages_setDefaultReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1330094102);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void messages_setDefaultReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1330094102);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void messages_setDefaultReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setDefaultReaction");
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

messages_setDefaultReaction::ReturnType messages_setDefaultReaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_setGameScore::messages_setGameScore(int32 flags_, bool edit_message_, bool force_, object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<InputUser> &&user_id_, int32 score_)
  : flags_(flags_)
  , edit_message_(edit_message_)
  , force_(force_)
  , peer_(std::move(peer_))
  , id_(id_)
  , user_id_(std::move(user_id_))
  , score_(score_)
{}

const std::int32_t messages_setGameScore::ID;

void messages_setGameScore::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1896289088);
  TlStoreBinary::store((var0 = flags_ | (edit_message_ << 0) | (force_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(score_, s);
}

void messages_setGameScore::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1896289088);
  TlStoreBinary::store((var0 = flags_ | (edit_message_ << 0) | (force_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(score_, s);
}

void messages_setGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setGameScore");
    s.store_field("flags", (var0 = flags_ | (edit_message_ << 0) | (force_ << 1)));
    if (var0 & 1) { s.store_field("edit_message", true); }
    if (var0 & 2) { s.store_field("force", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("score", score_);
    s.store_class_end();
  }
}

messages_setGameScore::ReturnType messages_setGameScore::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setInlineGameScore::messages_setInlineGameScore(int32 flags_, bool edit_message_, bool force_, object_ptr<InputBotInlineMessageID> &&id_, object_ptr<InputUser> &&user_id_, int32 score_)
  : flags_(flags_)
  , edit_message_(edit_message_)
  , force_(force_)
  , id_(std::move(id_))
  , user_id_(std::move(user_id_))
  , score_(score_)
{}

const std::int32_t messages_setInlineGameScore::ID;

void messages_setInlineGameScore::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(363700068);
  TlStoreBinary::store((var0 = flags_ | (edit_message_ << 0) | (force_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(score_, s);
}

void messages_setInlineGameScore::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(363700068);
  TlStoreBinary::store((var0 = flags_ | (edit_message_ << 0) | (force_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(score_, s);
}

void messages_setInlineGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setInlineGameScore");
    s.store_field("flags", (var0 = flags_ | (edit_message_ << 0) | (force_ << 1)));
    if (var0 & 1) { s.store_field("edit_message", true); }
    if (var0 & 2) { s.store_field("force", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("score", score_);
    s.store_class_end();
  }
}

messages_setInlineGameScore::ReturnType messages_setInlineGameScore::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_summarizeText::messages_summarizeText(int32 flags_, object_ptr<InputPeer> &&peer_, int32 id_, string const &to_lang_, string const &tone_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , to_lang_(to_lang_)
  , tone_(tone_)
{}

const std::int32_t messages_summarizeText::ID;

void messages_summarizeText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1413754042);
  TlStoreBinary::store((var0 = flags_ | ((!to_lang_.empty()) << 0) | ((!tone_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(to_lang_, s); }
  if (var0 & 4) { TlStoreString::store(tone_, s); }
}

void messages_summarizeText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1413754042);
  TlStoreBinary::store((var0 = flags_ | ((!to_lang_.empty()) << 0) | ((!tone_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(to_lang_, s); }
  if (var0 & 4) { TlStoreString::store(tone_, s); }
}

void messages_summarizeText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.summarizeText");
    s.store_field("flags", (var0 = flags_ | ((!to_lang_.empty()) << 0) | ((!tone_.empty()) << 2)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("to_lang", to_lang_); }
    if (var0 & 4) { s.store_field("tone", tone_); }
    s.store_class_end();
  }
}

messages_summarizeText::ReturnType messages_summarizeText::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
#undef FAIL
}

messages_toggleSavedDialogPin::messages_toggleSavedDialogPin(int32 flags_, bool pinned_, object_ptr<InputDialogPeer> &&peer_)
  : flags_(flags_)
  , pinned_(pinned_)
  , peer_(std::move(peer_))
{}

const std::int32_t messages_toggleSavedDialogPin::ID;

void messages_toggleSavedDialogPin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1400783906);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_toggleSavedDialogPin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1400783906);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_toggleSavedDialogPin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleSavedDialogPin");
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_toggleSavedDialogPin::ReturnType messages_toggleSavedDialogPin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_updateDialogFilter::messages_updateDialogFilter(int32 flags_, int32 id_, object_ptr<DialogFilter> &&filter_)
  : flags_(flags_)
  , id_(id_)
  , filter_(std::move(filter_))
{}

const std::int32_t messages_updateDialogFilter::ID;

void messages_updateDialogFilter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(450142282);
  TlStoreBinary::store((var0 = flags_ | ((filter_ != nullptr) << 0)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s); }
}

void messages_updateDialogFilter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(450142282);
  TlStoreBinary::store((var0 = flags_ | ((filter_ != nullptr) << 0)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s); }
}

void messages_updateDialogFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.updateDialogFilter");
    s.store_field("flags", (var0 = flags_ | ((filter_ != nullptr) << 0)));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get())); }
    s.store_class_end();
  }
}

messages_updateDialogFilter::ReturnType messages_updateDialogFilter::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_acceptStarGiftOnchainOffer::payments_acceptStarGiftOnchainOffer(int32 offer_msg_id_)
  : offer_msg_id_(offer_msg_id_)
{}

const std::int32_t payments_acceptStarGiftOnchainOffer::ID;

void payments_acceptStarGiftOnchainOffer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-71655714);
  TlStoreBinary::store(offer_msg_id_, s);
}

void payments_acceptStarGiftOnchainOffer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-71655714);
  TlStoreBinary::store(offer_msg_id_, s);
}

void payments_acceptStarGiftOnchainOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.acceptStarGiftOnchainOffer");
    s.store_field("offer_msg_id", offer_msg_id_);
    s.store_class_end();
  }
}

payments_acceptStarGiftOnchainOffer::ReturnType payments_acceptStarGiftOnchainOffer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftOnchainOfferTx>, -27885105>::parse(p);
#undef FAIL
}

payments_assignPlayMarketTransaction::payments_assignPlayMarketTransaction(object_ptr<dataJSON> &&receipt_, object_ptr<InputStorePaymentPurpose> &&purpose_)
  : receipt_(std::move(receipt_))
  , purpose_(std::move(purpose_))
{}

const std::int32_t payments_assignPlayMarketTransaction::ID;

void payments_assignPlayMarketTransaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-537046829);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(receipt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_assignPlayMarketTransaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-537046829);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(receipt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_assignPlayMarketTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.assignPlayMarketTransaction");
    s.store_object_field("receipt", static_cast<const BaseObject *>(receipt_.get()));
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

payments_assignPlayMarketTransaction::ReturnType payments_assignPlayMarketTransaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_clearSavedInfo::payments_clearSavedInfo(int32 flags_, bool credentials_, bool info_)
  : flags_(flags_)
  , credentials_(credentials_)
  , info_(info_)
{}

const std::int32_t payments_clearSavedInfo::ID;

void payments_clearSavedInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-667062079);
  TlStoreBinary::store((var0 = flags_ | (credentials_ << 0) | (info_ << 1)), s);
}

void payments_clearSavedInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-667062079);
  TlStoreBinary::store((var0 = flags_ | (credentials_ << 0) | (info_ << 1)), s);
}

void payments_clearSavedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.clearSavedInfo");
    s.store_field("flags", (var0 = flags_ | (credentials_ << 0) | (info_ << 1)));
    if (var0 & 1) { s.store_field("credentials", true); }
    if (var0 & 2) { s.store_field("info", true); }
    s.store_class_end();
  }
}

payments_clearSavedInfo::ReturnType payments_clearSavedInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_craftStarGift::payments_craftStarGift(array<object_ptr<InputSavedStarGift>> &&stargift_)
  : stargift_(std::move(stargift_))
{}

const std::int32_t payments_craftStarGift::ID;

void payments_craftStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1325832113);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_craftStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1325832113);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_craftStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.craftStarGift");
    { s.store_vector_begin("stargift", stargift_.size()); for (const auto &_value : stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_craftStarGift::ReturnType payments_craftStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_deleteStarGift::payments_deleteStarGift(object_ptr<InputSavedStarGift> &&stargift_)
  : stargift_(std::move(stargift_))
{}

const std::int32_t payments_deleteStarGift::ID;

void payments_deleteStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1020983466);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_deleteStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1020983466);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_deleteStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.deleteStarGift");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

payments_deleteStarGift::ReturnType payments_deleteStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_deleteStarGiftCollection::payments_deleteStarGiftCollection(object_ptr<InputPeer> &&peer_, int32 collection_id_)
  : peer_(std::move(peer_))
  , collection_id_(collection_id_)
{}

const std::int32_t payments_deleteStarGiftCollection::ID;

void payments_deleteStarGiftCollection::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1386854168);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(collection_id_, s);
}

void payments_deleteStarGiftCollection::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1386854168);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(collection_id_, s);
}

void payments_deleteStarGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.deleteStarGiftCollection");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("collection_id", collection_id_);
    s.store_class_end();
  }
}

payments_deleteStarGiftCollection::ReturnType payments_deleteStarGiftCollection::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_getGiveawayInfo::payments_getGiveawayInfo(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t payments_getGiveawayInfo::ID;

void payments_getGiveawayInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-198994907);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void payments_getGiveawayInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-198994907);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void payments_getGiveawayInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getGiveawayInfo");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

payments_getGiveawayInfo::ReturnType payments_getGiveawayInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_GiveawayInfo>::parse(p);
#undef FAIL
}

payments_getStarsGiftOptions::payments_getStarsGiftOptions(int32 flags_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , user_id_(std::move(user_id_))
{}

const std::int32_t payments_getStarsGiftOptions::ID;

void payments_getStarsGiftOptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-741774392);
  TlStoreBinary::store((var0 = flags_ | ((user_id_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s); }
}

void payments_getStarsGiftOptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-741774392);
  TlStoreBinary::store((var0 = flags_ | ((user_id_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s); }
}

void payments_getStarsGiftOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsGiftOptions");
    s.store_field("flags", (var0 = flags_ | ((user_id_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get())); }
    s.store_class_end();
  }
}

payments_getStarsGiftOptions::ReturnType payments_getStarsGiftOptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsGiftOption>, 1577421297>>, 481674261>::parse(p);
#undef FAIL
}

payments_getStarsRevenueStats::payments_getStarsRevenueStats(int32 flags_, bool dark_, bool ton_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , dark_(dark_)
  , ton_(ton_)
  , peer_(std::move(peer_))
{}

const std::int32_t payments_getStarsRevenueStats::ID;

void payments_getStarsRevenueStats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-652215594);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0) | (ton_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsRevenueStats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-652215594);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0) | (ton_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsRevenueStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsRevenueStats");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0) | (ton_ << 1)));
    if (var0 & 1) { s.store_field("dark", true); }
    if (var0 & 2) { s.store_field("ton", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

payments_getStarsRevenueStats::ReturnType payments_getStarsRevenueStats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsRevenueStats>, 1814066038>::parse(p);
#undef FAIL
}

payments_reorderStarGiftCollections::payments_reorderStarGiftCollections(object_ptr<InputPeer> &&peer_, array<int32> &&order_)
  : peer_(std::move(peer_))
  , order_(std::move(order_))
{}

const std::int32_t payments_reorderStarGiftCollections::ID;

void payments_reorderStarGiftCollections::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1020594996);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void payments_reorderStarGiftCollections::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1020594996);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void payments_reorderStarGiftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.reorderStarGiftCollections");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_reorderStarGiftCollections::ReturnType payments_reorderStarGiftCollections::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_updateStarGiftPrice::payments_updateStarGiftPrice(object_ptr<InputSavedStarGift> &&stargift_, object_ptr<StarsAmount> &&resell_amount_)
  : stargift_(std::move(stargift_))
  , resell_amount_(std::move(resell_amount_))
{}

const std::int32_t payments_updateStarGiftPrice::ID;

void payments_updateStarGiftPrice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-306287413);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(resell_amount_, s);
}

void payments_updateStarGiftPrice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-306287413);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(resell_amount_, s);
}

void payments_updateStarGiftPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.updateStarGiftPrice");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_object_field("resell_amount", static_cast<const BaseObject *>(resell_amount_.get()));
    s.store_class_end();
  }
}

payments_updateStarGiftPrice::ReturnType payments_updateStarGiftPrice::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_getGroupCallChainBlocks::phone_getGroupCallChainBlocks(object_ptr<InputGroupCall> &&call_, int32 sub_chain_id_, int32 offset_, int32 limit_)
  : call_(std::move(call_))
  , sub_chain_id_(sub_chain_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t phone_getGroupCallChainBlocks::ID;

void phone_getGroupCallChainBlocks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-291534682);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(sub_chain_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupCallChainBlocks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-291534682);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(sub_chain_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupCallChainBlocks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCallChainBlocks");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("sub_chain_id", sub_chain_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

phone_getGroupCallChainBlocks::ReturnType phone_getGroupCallChainBlocks::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_joinGroupCallPresentation::phone_joinGroupCallPresentation(object_ptr<InputGroupCall> &&call_, object_ptr<dataJSON> &&params_)
  : call_(std::move(call_))
  , params_(std::move(params_))
{}

const std::int32_t phone_joinGroupCallPresentation::ID;

void phone_joinGroupCallPresentation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-873829436);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void phone_joinGroupCallPresentation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-873829436);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void phone_joinGroupCallPresentation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.joinGroupCallPresentation");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("params", static_cast<const BaseObject *>(params_.get()));
    s.store_class_end();
  }
}

phone_joinGroupCallPresentation::ReturnType phone_joinGroupCallPresentation::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_leaveGroupCall::phone_leaveGroupCall(object_ptr<InputGroupCall> &&call_, int32 source_)
  : call_(std::move(call_))
  , source_(source_)
{}

const std::int32_t phone_leaveGroupCall::ID;

void phone_leaveGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1342404601);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(source_, s);
}

void phone_leaveGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1342404601);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(source_, s);
}

void phone_leaveGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.leaveGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("source", source_);
    s.store_class_end();
  }
}

phone_leaveGroupCall::ReturnType phone_leaveGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_leaveGroupCallPresentation::phone_leaveGroupCallPresentation(object_ptr<InputGroupCall> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t phone_leaveGroupCallPresentation::ID;

void phone_leaveGroupCallPresentation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(475058500);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_leaveGroupCallPresentation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(475058500);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_leaveGroupCallPresentation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.leaveGroupCallPresentation");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_leaveGroupCallPresentation::ReturnType phone_leaveGroupCallPresentation::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

photos_deletePhotos::photos_deletePhotos(array<object_ptr<InputPhoto>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t photos_deletePhotos::ID;

void photos_deletePhotos::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2016444625);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void photos_deletePhotos::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2016444625);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void photos_deletePhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.deletePhotos");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

photos_deletePhotos::ReturnType photos_deletePhotos::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
#undef FAIL
}

stickers_createStickerSet::stickers_createStickerSet(int32 flags_, bool masks_, bool emojis_, bool text_color_, object_ptr<InputUser> &&user_id_, string const &title_, string const &short_name_, object_ptr<InputDocument> &&thumb_, array<object_ptr<inputStickerSetItem>> &&stickers_, string const &software_)
  : flags_(flags_)
  , masks_(masks_)
  , emojis_(emojis_)
  , text_color_(text_color_)
  , user_id_(std::move(user_id_))
  , title_(title_)
  , short_name_(short_name_)
  , thumb_(std::move(thumb_))
  , stickers_(std::move(stickers_))
  , software_(software_)
{}

const std::int32_t stickers_createStickerSet::ID;

void stickers_createStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1876841625);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 5) | (text_color_ << 6) | ((thumb_ != nullptr) << 2) | ((!software_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(short_name_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 853188252>>, 481674261>::store(stickers_, s);
  if (var0 & 8) { TlStoreString::store(software_, s); }
}

void stickers_createStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1876841625);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 5) | (text_color_ << 6) | ((thumb_ != nullptr) << 2) | ((!software_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(short_name_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 853188252>>, 481674261>::store(stickers_, s);
  if (var0 & 8) { TlStoreString::store(software_, s); }
}

void stickers_createStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.createStickerSet");
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 5) | (text_color_ << 6) | ((thumb_ != nullptr) << 2) | ((!software_.empty()) << 3)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 32) { s.store_field("emojis", true); }
    if (var0 & 64) { s.store_field("text_color", true); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("title", title_);
    s.store_field("short_name", short_name_);
    if (var0 & 4) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 8) { s.store_field("software", software_); }
    s.store_class_end();
  }
}

stickers_createStickerSet::ReturnType stickers_createStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stories_deleteAlbum::stories_deleteAlbum(object_ptr<InputPeer> &&peer_, int32 album_id_)
  : peer_(std::move(peer_))
  , album_id_(album_id_)
{}

const std::int32_t stories_deleteAlbum::ID;

void stories_deleteAlbum::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1925949744);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
}

void stories_deleteAlbum::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1925949744);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
}

void stories_deleteAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.deleteAlbum");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("album_id", album_id_);
    s.store_class_end();
  }
}

stories_deleteAlbum::ReturnType stories_deleteAlbum::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stories_readStories::stories_readStories(object_ptr<InputPeer> &&peer_, int32 max_id_)
  : peer_(std::move(peer_))
  , max_id_(max_id_)
{}

const std::int32_t stories_readStories::ID;

void stories_readStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1521034552);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void stories_readStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1521034552);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void stories_readStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.readStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

stories_readStories::ReturnType stories_readStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
#undef FAIL
}

stories_reorderAlbums::stories_reorderAlbums(object_ptr<InputPeer> &&peer_, array<int32> &&order_)
  : peer_(std::move(peer_))
  , order_(std::move(order_))
{}

const std::int32_t stories_reorderAlbums::ID;

void stories_reorderAlbums::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2060059687);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void stories_reorderAlbums::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2060059687);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void stories_reorderAlbums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.reorderAlbums");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_reorderAlbums::ReturnType stories_reorderAlbums::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stories_sendReaction::stories_sendReaction(int32 flags_, bool add_to_recent_, object_ptr<InputPeer> &&peer_, int32 story_id_, object_ptr<Reaction> &&reaction_)
  : flags_(flags_)
  , add_to_recent_(add_to_recent_)
  , peer_(std::move(peer_))
  , story_id_(story_id_)
  , reaction_(std::move(reaction_))
{}

const std::int32_t stories_sendReaction::ID;

void stories_sendReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2144810674);
  TlStoreBinary::store((var0 = flags_ | (add_to_recent_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(story_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void stories_sendReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2144810674);
  TlStoreBinary::store((var0 = flags_ | (add_to_recent_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(story_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void stories_sendReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.sendReaction");
    s.store_field("flags", (var0 = flags_ | (add_to_recent_ << 0)));
    if (var0 & 1) { s.store_field("add_to_recent", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("story_id", story_id_);
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

stories_sendReaction::ReturnType stories_sendReaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

users_getSavedMusic::users_getSavedMusic(object_ptr<InputUser> &&id_, int32 offset_, int32 limit_, int64 hash_)
  : id_(std::move(id_))
  , offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t users_getSavedMusic::ID;

void users_getSavedMusic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2022539235);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void users_getSavedMusic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2022539235);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void users_getSavedMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.getSavedMusic");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

users_getSavedMusic::ReturnType users_getSavedMusic::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<users_SavedMusic>::parse(p);
#undef FAIL
}

wallet_disableBackup::wallet_disableBackup(int32 flags_, object_ptr<InputCheckPasswordSRP> &&password_, bytes &&new_public_key_, object_ptr<walletOwnershipProof> &&proof_)
  : flags_(flags_)
  , password_(std::move(password_))
  , new_public_key_(std::move(new_public_key_))
  , proof_(std::move(proof_))
{}

const std::int32_t wallet_disableBackup::ID;

void wallet_disableBackup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(185331930);
  TlStoreBinary::store((var0 = flags_ | ((password_ != nullptr) << 0) | ((!new_public_key_.empty()) << 1) | ((proof_ != nullptr) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
  if (var0 & 2) { TlStoreString::store(new_public_key_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1622985485>::store(proof_, s); }
}

void wallet_disableBackup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(185331930);
  TlStoreBinary::store((var0 = flags_ | ((password_ != nullptr) << 0) | ((!new_public_key_.empty()) << 1) | ((proof_ != nullptr) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
  if (var0 & 2) { TlStoreString::store(new_public_key_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1622985485>::store(proof_, s); }
}

void wallet_disableBackup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.disableBackup");
    s.store_field("flags", (var0 = flags_ | ((password_ != nullptr) << 0) | ((!new_public_key_.empty()) << 1) | ((proof_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("password", "[REDACTED]"); }
    if (var0 & 2) { s.store_bytes_field("new_public_key", new_public_key_); }
    if (var0 & 4) { s.store_object_field("proof", static_cast<const BaseObject *>(proof_.get())); }
    s.store_class_end();
  }
}

wallet_disableBackup::ReturnType wallet_disableBackup::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<WalletState>::parse(p);
#undef FAIL
}

const std::int32_t wallet_getBackupHolderDcs::ID;

void wallet_getBackupHolderDcs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-780544876);
}

void wallet_getBackupHolderDcs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-780544876);
}

void wallet_getBackupHolderDcs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.getBackupHolderDcs");
    s.store_class_end();
  }
}

wallet_getBackupHolderDcs::ReturnType wallet_getBackupHolderDcs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<wallet_holderDc>, -103410961>>, 481674261>::parse(p);
#undef FAIL
}

wallet_replaceWallet::wallet_replaceWallet(int32 flags_, object_ptr<InputWalletReplacement> &&wallet_, object_ptr<InputCheckPasswordSRP> &&password_)
  : flags_(flags_)
  , wallet_(std::move(wallet_))
  , password_(std::move(password_))
{}

const std::int32_t wallet_replaceWallet::ID;

void wallet_replaceWallet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-658034964);
  TlStoreBinary::store((var0 = flags_ | ((password_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallet_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void wallet_replaceWallet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-658034964);
  TlStoreBinary::store((var0 = flags_ | ((password_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallet_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void wallet_replaceWallet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.replaceWallet");
    s.store_field("flags", (var0 = flags_ | ((password_ != nullptr) << 0)));
    s.store_object_field("wallet", static_cast<const BaseObject *>(wallet_.get()));
    if (var0 & 1) { s.store_field("password", "[REDACTED]"); }
    s.store_class_end();
  }
}

wallet_replaceWallet::ReturnType wallet_replaceWallet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<WalletState>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
