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


botBusinessConnection::botBusinessConnection()
  : flags_()
  , disabled_()
  , connection_id_()
  , user_id_()
  , dc_id_()
  , date_()
  , rights_()
{}

const std::int32_t botBusinessConnection::ID;

object_ptr<botBusinessConnection> botBusinessConnection::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botBusinessConnection> res = make_tl_object<botBusinessConnection>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->disabled_ = (var0 & 2) != 0;
  res->connection_id_ = TlFetchString<string>::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->dc_id_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->rights_ = TlFetchBoxed<TlFetchObject<businessBotRights>, -1604170505>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void botBusinessConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botBusinessConnection");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (disabled_ << 1) | ((rights_ != nullptr) << 2)));
    if (var0 & 2) { s.store_field("disabled", true); }
    s.store_field("connection_id", connection_id_);
    s.store_field("user_id", user_id_);
    s.store_field("dc_id", dc_id_);
    s.store_field("date", date_);
    if (var0 & 4) { s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get())); }
    s.store_class_end();
  }
}

botInfo::botInfo()
  : flags_()
  , has_preview_medias_()
  , user_id_()
  , description_()
  , description_photo_()
  , description_document_()
  , commands_()
  , menu_button_()
  , privacy_policy_url_()
  , app_settings_()
  , verifier_settings_()
{}

const std::int32_t botInfo::ID;

object_ptr<botInfo> botInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInfo> res = make_tl_object<botInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_preview_medias_ = (var0 & 64) != 0;
  if (var0 & 1) { res->user_id_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->description_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->description_photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 32) { res->description_document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 4) { res->commands_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botCommand>, -1739401518>>, 481674261>::parse(p); }
  if (var0 & 8) { res->menu_button_ = TlFetchObject<BotMenuButton>::parse(p); }
  if (var0 & 128) { res->privacy_policy_url_ = TlFetchString<string>::parse(p); }
  if (var0 & 256) { res->app_settings_ = TlFetchBoxed<TlFetchObject<botAppSettings>, -912582320>::parse(p); }
  if (var0 & 512) { res->verifier_settings_ = TlFetchBoxed<TlFetchObject<botVerifierSettings>, -1591021569>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void botInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_preview_medias_ << 6) | ((!description_.empty()) << 1) | ((description_photo_ != nullptr) << 4) | ((description_document_ != nullptr) << 5) | ((!commands_.empty()) << 2) | ((menu_button_ != nullptr) << 3) | ((!privacy_policy_url_.empty()) << 7) | ((app_settings_ != nullptr) << 8) | ((verifier_settings_ != nullptr) << 9)));
    if (var0 & 64) { s.store_field("has_preview_medias", true); }
    if (var0 & 1) { s.store_field("user_id", user_id_); }
    if (var0 & 2) { s.store_field("description", description_); }
    if (var0 & 16) { s.store_object_field("description_photo", static_cast<const BaseObject *>(description_photo_.get())); }
    if (var0 & 32) { s.store_object_field("description_document", static_cast<const BaseObject *>(description_document_.get())); }
    if (var0 & 4) { { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 8) { s.store_object_field("menu_button", static_cast<const BaseObject *>(menu_button_.get())); }
    if (var0 & 128) { s.store_field("privacy_policy_url", privacy_policy_url_); }
    if (var0 & 256) { s.store_object_field("app_settings", static_cast<const BaseObject *>(app_settings_.get())); }
    if (var0 & 512) { s.store_object_field("verifier_settings", static_cast<const BaseObject *>(verifier_settings_.get())); }
    s.store_class_end();
  }
}

businessBotRights::businessBotRights()
  : flags_()
  , reply_()
  , read_messages_()
  , delete_sent_messages_()
  , delete_received_messages_()
  , edit_name_()
  , edit_bio_()
  , edit_profile_photo_()
  , edit_username_()
  , view_gifts_()
  , sell_gifts_()
  , change_gift_settings_()
  , transfer_and_upgrade_gifts_()
  , transfer_stars_()
  , manage_stories_()
{}

businessBotRights::businessBotRights(int32 flags_, bool reply_, bool read_messages_, bool delete_sent_messages_, bool delete_received_messages_, bool edit_name_, bool edit_bio_, bool edit_profile_photo_, bool edit_username_, bool view_gifts_, bool sell_gifts_, bool change_gift_settings_, bool transfer_and_upgrade_gifts_, bool transfer_stars_, bool manage_stories_)
  : flags_(flags_)
  , reply_(reply_)
  , read_messages_(read_messages_)
  , delete_sent_messages_(delete_sent_messages_)
  , delete_received_messages_(delete_received_messages_)
  , edit_name_(edit_name_)
  , edit_bio_(edit_bio_)
  , edit_profile_photo_(edit_profile_photo_)
  , edit_username_(edit_username_)
  , view_gifts_(view_gifts_)
  , sell_gifts_(sell_gifts_)
  , change_gift_settings_(change_gift_settings_)
  , transfer_and_upgrade_gifts_(transfer_and_upgrade_gifts_)
  , transfer_stars_(transfer_stars_)
  , manage_stories_(manage_stories_)
{}

const std::int32_t businessBotRights::ID;

object_ptr<businessBotRights> businessBotRights::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessBotRights> res = make_tl_object<businessBotRights>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->reply_ = (var0 & 1) != 0;
  res->read_messages_ = (var0 & 2) != 0;
  res->delete_sent_messages_ = (var0 & 4) != 0;
  res->delete_received_messages_ = (var0 & 8) != 0;
  res->edit_name_ = (var0 & 16) != 0;
  res->edit_bio_ = (var0 & 32) != 0;
  res->edit_profile_photo_ = (var0 & 64) != 0;
  res->edit_username_ = (var0 & 128) != 0;
  res->view_gifts_ = (var0 & 256) != 0;
  res->sell_gifts_ = (var0 & 512) != 0;
  res->change_gift_settings_ = (var0 & 1024) != 0;
  res->transfer_and_upgrade_gifts_ = (var0 & 2048) != 0;
  res->transfer_stars_ = (var0 & 4096) != 0;
  res->manage_stories_ = (var0 & 8192) != 0;
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessBotRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (reply_ << 0) | (read_messages_ << 1) | (delete_sent_messages_ << 2) | (delete_received_messages_ << 3) | (edit_name_ << 4) | (edit_bio_ << 5) | (edit_profile_photo_ << 6) | (edit_username_ << 7) | (view_gifts_ << 8) | (sell_gifts_ << 9) | (change_gift_settings_ << 10) | (transfer_and_upgrade_gifts_ << 11) | (transfer_stars_ << 12) | (manage_stories_ << 13)), s);
}

void businessBotRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (reply_ << 0) | (read_messages_ << 1) | (delete_sent_messages_ << 2) | (delete_received_messages_ << 3) | (edit_name_ << 4) | (edit_bio_ << 5) | (edit_profile_photo_ << 6) | (edit_username_ << 7) | (view_gifts_ << 8) | (sell_gifts_ << 9) | (change_gift_settings_ << 10) | (transfer_and_upgrade_gifts_ << 11) | (transfer_stars_ << 12) | (manage_stories_ << 13)), s);
}

void businessBotRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessBotRights");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (reply_ << 0) | (read_messages_ << 1) | (delete_sent_messages_ << 2) | (delete_received_messages_ << 3) | (edit_name_ << 4) | (edit_bio_ << 5) | (edit_profile_photo_ << 6) | (edit_username_ << 7) | (view_gifts_ << 8) | (sell_gifts_ << 9) | (change_gift_settings_ << 10) | (transfer_and_upgrade_gifts_ << 11) | (transfer_stars_ << 12) | (manage_stories_ << 13)));
    if (var0 & 1) { s.store_field("reply", true); }
    if (var0 & 2) { s.store_field("read_messages", true); }
    if (var0 & 4) { s.store_field("delete_sent_messages", true); }
    if (var0 & 8) { s.store_field("delete_received_messages", true); }
    if (var0 & 16) { s.store_field("edit_name", true); }
    if (var0 & 32) { s.store_field("edit_bio", true); }
    if (var0 & 64) { s.store_field("edit_profile_photo", true); }
    if (var0 & 128) { s.store_field("edit_username", true); }
    if (var0 & 256) { s.store_field("view_gifts", true); }
    if (var0 & 512) { s.store_field("sell_gifts", true); }
    if (var0 & 1024) { s.store_field("change_gift_settings", true); }
    if (var0 & 2048) { s.store_field("transfer_and_upgrade_gifts", true); }
    if (var0 & 4096) { s.store_field("transfer_stars", true); }
    if (var0 & 8192) { s.store_field("manage_stories", true); }
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEvent::ID;

object_ptr<channelAdminLogEvent> channelAdminLogEvent::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEvent>(p);
}

channelAdminLogEvent::channelAdminLogEvent(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , action_(TlFetchObject<ChannelAdminLogEventAction>::parse(p))
{}

void channelAdminLogEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEvent");
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_field("user_id", user_id_);
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

object_ptr<ChatInvite> ChatInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatInviteAlready::ID:
      return chatInviteAlready::fetch(p);
    case chatInvite::ID:
      return chatInvite::fetch(p);
    case chatInvitePeek::ID:
      return chatInvitePeek::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t chatInviteAlready::ID;

object_ptr<ChatInvite> chatInviteAlready::fetch(TlBufferParser &p) {
  return make_tl_object<chatInviteAlready>(p);
}

chatInviteAlready::chatInviteAlready(TlBufferParser &p)
  : chat_(TlFetchObject<Chat>::parse(p))
{}

void chatInviteAlready::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteAlready");
    s.store_object_field("chat", static_cast<const BaseObject *>(chat_.get()));
    s.store_class_end();
  }
}

chatInvite::chatInvite()
  : flags_()
  , channel_()
  , broadcast_()
  , public_()
  , megagroup_()
  , request_needed_()
  , verified_()
  , scam_()
  , fake_()
  , can_refulfill_subscription_()
  , title_()
  , about_()
  , photo_()
  , participants_count_()
  , participants_()
  , color_()
  , subscription_pricing_()
  , subscription_form_id_()
  , bot_verification_()
{}

const std::int32_t chatInvite::ID;

object_ptr<ChatInvite> chatInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatInvite> res = make_tl_object<chatInvite>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_ = (var0 & 1) != 0;
  res->broadcast_ = (var0 & 2) != 0;
  res->public_ = (var0 & 4) != 0;
  res->megagroup_ = (var0 & 8) != 0;
  res->request_needed_ = (var0 & 64) != 0;
  res->verified_ = (var0 & 128) != 0;
  res->scam_ = (var0 & 256) != 0;
  res->fake_ = (var0 & 512) != 0;
  res->can_refulfill_subscription_ = (var0 & 2048) != 0;
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 32) { res->about_ = TlFetchString<string>::parse(p); }
  res->photo_ = TlFetchObject<Photo>::parse(p);
  res->participants_count_ = TlFetchInt::parse(p);
  if (var0 & 16) { res->participants_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p); }
  res->color_ = TlFetchInt::parse(p);
  if (var0 & 1024) { res->subscription_pricing_ = TlFetchBoxed<TlFetchObject<starsSubscriptionPricing>, 88173912>::parse(p); }
  if (var0 & 4096) { res->subscription_form_id_ = TlFetchLong::parse(p); }
  if (var0 & 8192) { res->bot_verification_ = TlFetchBoxed<TlFetchObject<botVerification>, -147976487>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInvite");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (channel_ << 0) | (broadcast_ << 1) | (public_ << 2) | (megagroup_ << 3) | (request_needed_ << 6) | (verified_ << 7) | (scam_ << 8) | (fake_ << 9) | (can_refulfill_subscription_ << 11) | ((!about_.empty()) << 5) | ((!participants_.empty()) << 4) | ((subscription_pricing_ != nullptr) << 10) | ((bot_verification_ != nullptr) << 13)));
    if (var0 & 1) { s.store_field("channel", true); }
    if (var0 & 2) { s.store_field("broadcast", true); }
    if (var0 & 4) { s.store_field("public", true); }
    if (var0 & 8) { s.store_field("megagroup", true); }
    if (var0 & 64) { s.store_field("request_needed", true); }
    if (var0 & 128) { s.store_field("verified", true); }
    if (var0 & 256) { s.store_field("scam", true); }
    if (var0 & 512) { s.store_field("fake", true); }
    if (var0 & 2048) { s.store_field("can_refulfill_subscription", true); }
    s.store_field("title", title_);
    if (var0 & 32) { s.store_field("about", about_); }
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("participants_count", participants_count_);
    if (var0 & 16) { { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("color", color_);
    if (var0 & 1024) { s.store_object_field("subscription_pricing", static_cast<const BaseObject *>(subscription_pricing_.get())); }
    if (var0 & 4096) { s.store_field("subscription_form_id", subscription_form_id_); }
    if (var0 & 8192) { s.store_object_field("bot_verification", static_cast<const BaseObject *>(bot_verification_.get())); }
    s.store_class_end();
  }
}

const std::int32_t chatInvitePeek::ID;

object_ptr<ChatInvite> chatInvitePeek::fetch(TlBufferParser &p) {
  return make_tl_object<chatInvitePeek>(p);
}

chatInvitePeek::chatInvitePeek(TlBufferParser &p)
  : chat_(TlFetchObject<Chat>::parse(p))
  , expires_(TlFetchInt::parse(p))
{}

void chatInvitePeek::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInvitePeek");
    s.store_object_field("chat", static_cast<const BaseObject *>(chat_.get()));
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

object_ptr<ChatTheme> ChatTheme::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatTheme::ID:
      return chatTheme::fetch(p);
    case chatThemeUniqueGift::ID:
      return chatThemeUniqueGift::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t chatTheme::ID;

object_ptr<ChatTheme> chatTheme::fetch(TlBufferParser &p) {
  return make_tl_object<chatTheme>(p);
}

chatTheme::chatTheme(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
{}

void chatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTheme");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

const std::int32_t chatThemeUniqueGift::ID;

object_ptr<ChatTheme> chatThemeUniqueGift::fetch(TlBufferParser &p) {
  return make_tl_object<chatThemeUniqueGift>(p);
}

chatThemeUniqueGift::chatThemeUniqueGift(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
  , theme_settings_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<themeSettings>, -94849324>>, 481674261>::parse(p))
{}

void chatThemeUniqueGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatThemeUniqueGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    { s.store_vector_begin("theme_settings", theme_settings_.size()); for (const auto &_value : theme_settings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<Dialog> Dialog::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case dialog::ID:
      return dialog::fetch(p);
    case dialogFolder::ID:
      return dialogFolder::fetch(p);
    case dialogCommunity::ID:
      return dialogCommunity::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

dialog::dialog()
  : flags_()
  , pinned_()
  , unread_mark_()
  , view_forum_as_messages_()
  , peer_()
  , top_message_()
  , read_inbox_max_id_()
  , read_outbox_max_id_()
  , unread_count_()
  , unread_mentions_count_()
  , unread_reactions_count_()
  , unread_poll_votes_count_()
  , notify_settings_()
  , pts_()
  , draft_()
  , folder_id_()
  , ttl_period_()
{}

const std::int32_t dialog::ID;

object_ptr<Dialog> dialog::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<dialog> res = make_tl_object<dialog>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 4) != 0;
  res->unread_mark_ = (var0 & 8) != 0;
  res->view_forum_as_messages_ = (var0 & 64) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->top_message_ = TlFetchInt::parse(p);
  res->read_inbox_max_id_ = TlFetchInt::parse(p);
  res->read_outbox_max_id_ = TlFetchInt::parse(p);
  res->unread_count_ = TlFetchInt::parse(p);
  res->unread_mentions_count_ = TlFetchInt::parse(p);
  res->unread_reactions_count_ = TlFetchInt::parse(p);
  res->unread_poll_votes_count_ = TlFetchInt::parse(p);
  res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
  if (var0 & 1) { res->pts_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->draft_ = TlFetchObject<DraftMessage>::parse(p); }
  if (var0 & 16) { res->folder_id_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void dialog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialog");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 2) | (unread_mark_ << 3) | (view_forum_as_messages_ << 6) | ((draft_ != nullptr) << 1)));
    if (var0 & 4) { s.store_field("pinned", true); }
    if (var0 & 8) { s.store_field("unread_mark", true); }
    if (var0 & 64) { s.store_field("view_forum_as_messages", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_message", top_message_);
    s.store_field("read_inbox_max_id", read_inbox_max_id_);
    s.store_field("read_outbox_max_id", read_outbox_max_id_);
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_mentions_count", unread_mentions_count_);
    s.store_field("unread_reactions_count", unread_reactions_count_);
    s.store_field("unread_poll_votes_count", unread_poll_votes_count_);
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    if (var0 & 1) { s.store_field("pts", pts_); }
    if (var0 & 2) { s.store_object_field("draft", static_cast<const BaseObject *>(draft_.get())); }
    if (var0 & 16) { s.store_field("folder_id", folder_id_); }
    if (var0 & 32) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

dialogFolder::dialogFolder()
  : flags_()
  , pinned_()
  , folder_()
  , peer_()
  , top_message_()
  , unread_muted_peers_count_()
  , unread_unmuted_peers_count_()
  , unread_muted_messages_count_()
  , unread_unmuted_messages_count_()
{}

const std::int32_t dialogFolder::ID;

object_ptr<Dialog> dialogFolder::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<dialogFolder> res = make_tl_object<dialogFolder>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 4) != 0;
  res->folder_ = TlFetchBoxed<TlFetchObject<folder>, -11252123>::parse(p);
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->top_message_ = TlFetchInt::parse(p);
  res->unread_muted_peers_count_ = TlFetchInt::parse(p);
  res->unread_unmuted_peers_count_ = TlFetchInt::parse(p);
  res->unread_muted_messages_count_ = TlFetchInt::parse(p);
  res->unread_unmuted_messages_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void dialogFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogFolder");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 2)));
    if (var0 & 4) { s.store_field("pinned", true); }
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_message", top_message_);
    s.store_field("unread_muted_peers_count", unread_muted_peers_count_);
    s.store_field("unread_unmuted_peers_count", unread_unmuted_peers_count_);
    s.store_field("unread_muted_messages_count", unread_muted_messages_count_);
    s.store_field("unread_unmuted_messages_count", unread_unmuted_messages_count_);
    s.store_class_end();
  }
}

dialogCommunity::dialogCommunity()
  : flags_()
  , pinned_()
  , community_id_()
  , notify_settings_()
{}

const std::int32_t dialogCommunity::ID;

object_ptr<Dialog> dialogCommunity::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<dialogCommunity> res = make_tl_object<dialogCommunity>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 4) != 0;
  res->community_id_ = TlFetchLong::parse(p);
  res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void dialogCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogCommunity");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 2)));
    if (var0 & 4) { s.store_field("pinned", true); }
    s.store_field("community_id", community_id_);
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    s.store_class_end();
  }
}

const std::int32_t emojiKeywordsDifference::ID;

object_ptr<emojiKeywordsDifference> emojiKeywordsDifference::fetch(TlBufferParser &p) {
  return make_tl_object<emojiKeywordsDifference>(p);
}

emojiKeywordsDifference::emojiKeywordsDifference(TlBufferParser &p)
  : lang_code_(TlFetchString<string>::parse(p))
  , from_version_(TlFetchInt::parse(p))
  , version_(TlFetchInt::parse(p))
  , keywords_(TlFetchBoxed<TlFetchVector<TlFetchObject<EmojiKeyword>>, 481674261>::parse(p))
{}

void emojiKeywordsDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiKeywordsDifference");
    s.store_field("lang_code", lang_code_);
    s.store_field("from_version", from_version_);
    s.store_field("version", version_);
    { s.store_vector_begin("keywords", keywords_.size()); for (const auto &_value : keywords_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<EmojiList> EmojiList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case emojiListNotModified::ID:
      return emojiListNotModified::fetch(p);
    case emojiList::ID:
      return emojiList::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t emojiListNotModified::ID;

object_ptr<EmojiList> emojiListNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<emojiListNotModified>();
}

void emojiListNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiListNotModified");
    s.store_class_end();
  }
}

const std::int32_t emojiList::ID;

object_ptr<EmojiList> emojiList::fetch(TlBufferParser &p) {
  return make_tl_object<emojiList>(p);
}

emojiList::emojiList(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , document_id_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void emojiList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiList");
    s.store_field("hash", hash_);
    { s.store_vector_begin("document_id", document_id_.size()); for (const auto &_value : document_id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

ephemeralMessage::ephemeralMessage()
  : flags_()
  , out_()
  , welcome_template_()
  , invert_media_()
  , noforwards_()
  , id_()
  , from_id_()
  , peer_id_()
  , receiver_id_()
  , top_msg_id_()
  , date_()
  , message_()
  , entities_()
  , media_()
  , reply_markup_()
  , reply_to_()
  , rich_message_()
  , chat_instance_()
  , anchor_msg_id_()
{}

const std::int32_t ephemeralMessage::ID;

object_ptr<ephemeralMessage> ephemeralMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<ephemeralMessage> res = make_tl_object<ephemeralMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->out_ = (var0 & 1) != 0;
  res->welcome_template_ = (var0 & 32) != 0;
  res->invert_media_ = (var0 & 128) != 0;
  res->noforwards_ = (var0 & 4096) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->from_id_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 512) { res->peer_id_ = TlFetchObject<Peer>::parse(p); }
  res->receiver_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->top_msg_id_ = TlFetchInt::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 8) { res->media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (var0 & 16) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (var0 & 64) { res->reply_to_ = TlFetchObject<MessageReplyHeader>::parse(p); }
  if (var0 & 256) { res->rich_message_ = TlFetchBoxed<TlFetchObject<richMessage>, -1158439541>::parse(p); }
  if (var0 & 1024) { res->chat_instance_ = TlFetchLong::parse(p); }
  if (var0 & 2048) { res->anchor_msg_id_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void ephemeralMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeralMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (out_ << 0) | (welcome_template_ << 5) | (invert_media_ << 7) | (noforwards_ << 12) | ((peer_id_ != nullptr) << 9) | ((!entities_.empty()) << 2) | ((media_ != nullptr) << 3) | ((reply_markup_ != nullptr) << 4) | ((reply_to_ != nullptr) << 6) | ((rich_message_ != nullptr) << 8)));
    if (var0 & 1) { s.store_field("out", true); }
    if (var0 & 32) { s.store_field("welcome_template", true); }
    if (var0 & 128) { s.store_field("invert_media", true); }
    if (var0 & 4096) { s.store_field("noforwards", true); }
    s.store_field("id", id_);
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    if (var0 & 512) { s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get())); }
    s.store_field("receiver_id", receiver_id_);
    if (var0 & 2) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_field("date", date_);
    s.store_field("message", message_);
    if (var0 & 4) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 8) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 16) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 64) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    if (var0 & 256) { s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get())); }
    if (var0 & 1024) { s.store_field("chat_instance", chat_instance_); }
    if (var0 & 2048) { s.store_field("anchor_msg_id", anchor_msg_id_); }
    s.store_class_end();
  }
}

factCheck::factCheck()
  : flags_()
  , need_check_()
  , country_()
  , text_()
  , hash_()
{}

const std::int32_t factCheck::ID;

object_ptr<factCheck> factCheck::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<factCheck> res = make_tl_object<factCheck>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->need_check_ = (var0 & 1) != 0;
  if (var0 & 2) { res->country_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->text_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  res->hash_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void factCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "factCheck");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (need_check_ << 0) | ((!country_.empty()) << 1) | ((text_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("need_check", true); }
    if (var0 & 2) { s.store_field("country", country_); }
    if (var0 & 2) { s.store_object_field("text", static_cast<const BaseObject *>(text_.get())); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

groupCallMessage::groupCallMessage()
  : flags_()
  , from_admin_()
  , id_()
  , from_id_()
  , date_()
  , message_()
  , paid_message_stars_()
{}

const std::int32_t groupCallMessage::ID;

object_ptr<groupCallMessage> groupCallMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<groupCallMessage> res = make_tl_object<groupCallMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->from_admin_ = (var0 & 2) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->from_id_ = TlFetchObject<Peer>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 1) { res->paid_message_stars_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void groupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (from_admin_ << 1)));
    if (var0 & 2) { s.store_field("from_admin", true); }
    s.store_field("id", id_);
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_field("date", date_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    if (var0 & 1) { s.store_field("paid_message_stars", paid_message_stars_); }
    s.store_class_end();
  }
}

const std::int32_t highScore::ID;

object_ptr<highScore> highScore::fetch(TlBufferParser &p) {
  return make_tl_object<highScore>(p);
}

highScore::highScore(TlBufferParser &p)
  : pos_(TlFetchInt::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , score_(TlFetchInt::parse(p))
{}

void highScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "highScore");
    s.store_field("pos", pos_);
    s.store_field("user_id", user_id_);
    s.store_field("score", score_);
    s.store_class_end();
  }
}

inlineBotSwitchPM::inlineBotSwitchPM(string const &text_, string const &start_param_)
  : text_(text_)
  , start_param_(start_param_)
{}

const std::int32_t inlineBotSwitchPM::ID;

object_ptr<inlineBotSwitchPM> inlineBotSwitchPM::fetch(TlBufferParser &p) {
  return make_tl_object<inlineBotSwitchPM>(p);
}

inlineBotSwitchPM::inlineBotSwitchPM(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , start_param_(TlFetchString<string>::parse(p))
{}

void inlineBotSwitchPM::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(start_param_, s);
}

void inlineBotSwitchPM::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(start_param_, s);
}

void inlineBotSwitchPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineBotSwitchPM");
    s.store_field("text", text_);
    s.store_field("start_param", start_param_);
    s.store_class_end();
  }
}

object_ptr<InlineQueryPeerType> InlineQueryPeerType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inlineQueryPeerTypeSameBotPM::ID:
      return inlineQueryPeerTypeSameBotPM::fetch(p);
    case inlineQueryPeerTypePM::ID:
      return inlineQueryPeerTypePM::fetch(p);
    case inlineQueryPeerTypeChat::ID:
      return inlineQueryPeerTypeChat::fetch(p);
    case inlineQueryPeerTypeMegagroup::ID:
      return inlineQueryPeerTypeMegagroup::fetch(p);
    case inlineQueryPeerTypeBroadcast::ID:
      return inlineQueryPeerTypeBroadcast::fetch(p);
    case inlineQueryPeerTypeBotPM::ID:
      return inlineQueryPeerTypeBotPM::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inlineQueryPeerTypeSameBotPM::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypeSameBotPM::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypeSameBotPM>();
}

void inlineQueryPeerTypeSameBotPM::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeSameBotPM::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeSameBotPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypeSameBotPM");
    s.store_class_end();
  }
}

const std::int32_t inlineQueryPeerTypePM::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypePM::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypePM>();
}

void inlineQueryPeerTypePM::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypePM::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypePM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypePM");
    s.store_class_end();
  }
}

const std::int32_t inlineQueryPeerTypeChat::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypeChat::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypeChat>();
}

void inlineQueryPeerTypeChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypeChat");
    s.store_class_end();
  }
}

const std::int32_t inlineQueryPeerTypeMegagroup::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypeMegagroup::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypeMegagroup>();
}

void inlineQueryPeerTypeMegagroup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeMegagroup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeMegagroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypeMegagroup");
    s.store_class_end();
  }
}

const std::int32_t inlineQueryPeerTypeBroadcast::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypeBroadcast::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypeBroadcast>();
}

void inlineQueryPeerTypeBroadcast::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeBroadcast::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeBroadcast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypeBroadcast");
    s.store_class_end();
  }
}

const std::int32_t inlineQueryPeerTypeBotPM::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypeBotPM::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypeBotPM>();
}

void inlineQueryPeerTypeBotPM::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeBotPM::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeBotPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypeBotPM");
    s.store_class_end();
  }
}

inputBusinessChatLink::inputBusinessChatLink(int32 flags_, string const &message_, array<object_ptr<MessageEntity>> &&entities_, string const &title_)
  : flags_(flags_)
  , message_(message_)
  , entities_(std::move(entities_))
  , title_(title_)
{}

const std::int32_t inputBusinessChatLink::ID;

void inputBusinessChatLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!entities_.empty()) << 0) | ((!title_.empty()) << 1)), s);
  TlStoreString::store(message_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
}

void inputBusinessChatLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!entities_.empty()) << 0) | ((!title_.empty()) << 1)), s);
  TlStoreString::store(message_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
}

void inputBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessChatLink");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!entities_.empty()) << 0) | ((!title_.empty()) << 1)));
    s.store_field("message", message_);
    if (var0 & 1) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("title", title_); }
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueAllowContacts::ID;

void inputPrivacyValueAllowContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowContacts");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueAllowAll::ID;

void inputPrivacyValueAllowAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowAll");
    s.store_class_end();
  }
}

inputPrivacyValueAllowUsers::inputPrivacyValueAllowUsers(array<object_ptr<InputUser>> &&users_)
  : users_(std::move(users_))
{}

const std::int32_t inputPrivacyValueAllowUsers::ID;

void inputPrivacyValueAllowUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void inputPrivacyValueAllowUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void inputPrivacyValueAllowUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowUsers");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueDisallowContacts::ID;

void inputPrivacyValueDisallowContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueDisallowContacts");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueDisallowAll::ID;

void inputPrivacyValueDisallowAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueDisallowAll");
    s.store_class_end();
  }
}

inputPrivacyValueDisallowUsers::inputPrivacyValueDisallowUsers(array<object_ptr<InputUser>> &&users_)
  : users_(std::move(users_))
{}

const std::int32_t inputPrivacyValueDisallowUsers::ID;

void inputPrivacyValueDisallowUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void inputPrivacyValueDisallowUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void inputPrivacyValueDisallowUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueDisallowUsers");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPrivacyValueAllowChatParticipants::inputPrivacyValueAllowChatParticipants(array<int64> &&chats_)
  : chats_(std::move(chats_))
{}

const std::int32_t inputPrivacyValueAllowChatParticipants::ID;

void inputPrivacyValueAllowChatParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void inputPrivacyValueAllowChatParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void inputPrivacyValueAllowChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowChatParticipants");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPrivacyValueDisallowChatParticipants::inputPrivacyValueDisallowChatParticipants(array<int64> &&chats_)
  : chats_(std::move(chats_))
{}

const std::int32_t inputPrivacyValueDisallowChatParticipants::ID;

void inputPrivacyValueDisallowChatParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void inputPrivacyValueDisallowChatParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void inputPrivacyValueDisallowChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueDisallowChatParticipants");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueAllowCloseFriends::ID;

void inputPrivacyValueAllowCloseFriends::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowCloseFriends::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowCloseFriends");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueAllowPremium::ID;

void inputPrivacyValueAllowPremium::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowPremium::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowPremium");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueAllowBots::ID;

void inputPrivacyValueAllowBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowBots");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueDisallowBots::ID;

void inputPrivacyValueDisallowBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueDisallowBots");
    s.store_class_end();
  }
}

object_ptr<InputSavedStarGift> InputSavedStarGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputSavedStarGiftUser::ID:
      return inputSavedStarGiftUser::fetch(p);
    case inputSavedStarGiftChat::ID:
      return inputSavedStarGiftChat::fetch(p);
    case inputSavedStarGiftSlug::ID:
      return inputSavedStarGiftSlug::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputSavedStarGiftUser::inputSavedStarGiftUser(int32 msg_id_)
  : msg_id_(msg_id_)
{}

const std::int32_t inputSavedStarGiftUser::ID;

object_ptr<InputSavedStarGift> inputSavedStarGiftUser::fetch(TlBufferParser &p) {
  return make_tl_object<inputSavedStarGiftUser>(p);
}

inputSavedStarGiftUser::inputSavedStarGiftUser(TlBufferParser &p)
  : msg_id_(TlFetchInt::parse(p))
{}

void inputSavedStarGiftUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
}

void inputSavedStarGiftUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
}

void inputSavedStarGiftUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSavedStarGiftUser");
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

inputSavedStarGiftChat::inputSavedStarGiftChat(object_ptr<InputPeer> &&peer_, int64 saved_id_)
  : peer_(std::move(peer_))
  , saved_id_(saved_id_)
{}

const std::int32_t inputSavedStarGiftChat::ID;

object_ptr<InputSavedStarGift> inputSavedStarGiftChat::fetch(TlBufferParser &p) {
  return make_tl_object<inputSavedStarGiftChat>(p);
}

inputSavedStarGiftChat::inputSavedStarGiftChat(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , saved_id_(TlFetchLong::parse(p))
{}

void inputSavedStarGiftChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(saved_id_, s);
}

void inputSavedStarGiftChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(saved_id_, s);
}

void inputSavedStarGiftChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSavedStarGiftChat");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("saved_id", saved_id_);
    s.store_class_end();
  }
}

inputSavedStarGiftSlug::inputSavedStarGiftSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputSavedStarGiftSlug::ID;

object_ptr<InputSavedStarGift> inputSavedStarGiftSlug::fetch(TlBufferParser &p) {
  return make_tl_object<inputSavedStarGiftSlug>(p);
}

inputSavedStarGiftSlug::inputSavedStarGiftSlug(TlBufferParser &p)
  : slug_(TlFetchString<string>::parse(p))
{}

void inputSavedStarGiftSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputSavedStarGiftSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputSavedStarGiftSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSavedStarGiftSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

inputThemeSettings::inputThemeSettings(int32 flags_, bool message_colors_animated_, object_ptr<BaseTheme> &&base_theme_, int32 accent_color_, int32 outbox_accent_color_, array<int32> &&message_colors_, object_ptr<InputWallPaper> &&wallpaper_, object_ptr<wallPaperSettings> &&wallpaper_settings_)
  : flags_(flags_)
  , message_colors_animated_(message_colors_animated_)
  , base_theme_(std::move(base_theme_))
  , accent_color_(accent_color_)
  , outbox_accent_color_(outbox_accent_color_)
  , message_colors_(std::move(message_colors_))
  , wallpaper_(std::move(wallpaper_))
  , wallpaper_settings_(std::move(wallpaper_settings_))
{}

const std::int32_t inputThemeSettings::ID;

void inputThemeSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (message_colors_animated_ << 2) | ((!message_colors_.empty()) << 0) | ((wallpaper_ != nullptr) << 1) | ((wallpaper_settings_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s);
  TlStoreBinary::store(accent_color_, s);
  if (var0 & 8) { TlStoreBinary::store(outbox_accent_color_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(message_colors_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 925826256>::store(wallpaper_settings_, s); }
}

void inputThemeSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (message_colors_animated_ << 2) | ((!message_colors_.empty()) << 0) | ((wallpaper_ != nullptr) << 1) | ((wallpaper_settings_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s);
  TlStoreBinary::store(accent_color_, s);
  if (var0 & 8) { TlStoreBinary::store(outbox_accent_color_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(message_colors_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 925826256>::store(wallpaper_settings_, s); }
}

void inputThemeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputThemeSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (message_colors_animated_ << 2) | ((!message_colors_.empty()) << 0) | ((wallpaper_ != nullptr) << 1) | ((wallpaper_settings_ != nullptr) << 1)));
    if (var0 & 4) { s.store_field("message_colors_animated", true); }
    s.store_object_field("base_theme", static_cast<const BaseObject *>(base_theme_.get()));
    s.store_field("accent_color", accent_color_);
    if (var0 & 8) { s.store_field("outbox_accent_color", outbox_accent_color_); }
    if (var0 & 1) { { s.store_vector_begin("message_colors", message_colors_.size()); for (const auto &_value : message_colors_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 2) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    if (var0 & 2) { s.store_object_field("wallpaper_settings", static_cast<const BaseObject *>(wallpaper_settings_.get())); }
    s.store_class_end();
  }
}

inputWallPaper::inputWallPaper(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputWallPaper::ID;

void inputWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWallPaper");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputWallPaperSlug::inputWallPaperSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputWallPaperSlug::ID;

void inputWallPaperSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputWallPaperSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputWallPaperSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWallPaperSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

inputWallPaperNoFile::inputWallPaperNoFile(int64 id_)
  : id_(id_)
{}

const std::int32_t inputWallPaperNoFile::ID;

void inputWallPaperNoFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputWallPaperNoFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputWallPaperNoFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWallPaperNoFile");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

keyboardButtonRow::keyboardButtonRow(array<object_ptr<keyboardButton>> &&buttons_)
  : buttons_(std::move(buttons_))
{}

const std::int32_t keyboardButtonRow::ID;

object_ptr<keyboardButtonRow> keyboardButtonRow::fetch(TlBufferParser &p) {
  return make_tl_object<keyboardButtonRow>(p);
}

keyboardButtonRow::keyboardButtonRow(TlBufferParser &p)
  : buttons_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<keyboardButton>, 795322159>>, 481674261>::parse(p))
{}

void keyboardButtonRow::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 795322159>>, 481674261>::store(buttons_, s);
}

void keyboardButtonRow::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 795322159>>, 481674261>::store(buttons_, s);
}

void keyboardButtonRow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonRow");
    { s.store_vector_begin("buttons", buttons_.size()); for (const auto &_value : buttons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<MessageExtendedMedia> MessageExtendedMedia::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messageExtendedMediaPreview::ID:
      return messageExtendedMediaPreview::fetch(p);
    case messageExtendedMedia::ID:
      return messageExtendedMedia::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messageExtendedMediaPreview::messageExtendedMediaPreview()
  : flags_()
  , w_()
  , h_()
  , thumb_()
  , video_duration_()
{}

messageExtendedMediaPreview::messageExtendedMediaPreview(int32 flags_, int32 w_, int32 h_, object_ptr<PhotoSize> &&thumb_, int32 video_duration_)
  : flags_(flags_)
  , w_(w_)
  , h_(h_)
  , thumb_(std::move(thumb_))
  , video_duration_(video_duration_)
{}

const std::int32_t messageExtendedMediaPreview::ID;

object_ptr<MessageExtendedMedia> messageExtendedMediaPreview::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageExtendedMediaPreview> res = make_tl_object<messageExtendedMediaPreview>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->w_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->h_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->thumb_ = TlFetchObject<PhotoSize>::parse(p); }
  if (var0 & 4) { res->video_duration_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageExtendedMediaPreview::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((thumb_ != nullptr) << 1)), s);
  if (var0 & 1) { TlStoreBinary::store(w_, s); }
  if (var0 & 1) { TlStoreBinary::store(h_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_duration_, s); }
}

void messageExtendedMediaPreview::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((thumb_ != nullptr) << 1)), s);
  if (var0 & 1) { TlStoreBinary::store(w_, s); }
  if (var0 & 1) { TlStoreBinary::store(h_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_duration_, s); }
}

void messageExtendedMediaPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExtendedMediaPreview");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((thumb_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("w", w_); }
    if (var0 & 1) { s.store_field("h", h_); }
    if (var0 & 2) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    if (var0 & 4) { s.store_field("video_duration", video_duration_); }
    s.store_class_end();
  }
}

messageExtendedMedia::messageExtendedMedia(object_ptr<MessageMedia> &&media_)
  : media_(std::move(media_))
{}

const std::int32_t messageExtendedMedia::ID;

object_ptr<MessageExtendedMedia> messageExtendedMedia::fetch(TlBufferParser &p) {
  return make_tl_object<messageExtendedMedia>(p);
}

messageExtendedMedia::messageExtendedMedia(TlBufferParser &p)
  : media_(TlFetchObject<MessageMedia>::parse(p))
{}

void messageExtendedMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messageExtendedMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messageExtendedMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExtendedMedia");
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

messageRange::messageRange(int32 min_id_, int32 max_id_)
  : min_id_(min_id_)
  , max_id_(max_id_)
{}

const std::int32_t messageRange::ID;

object_ptr<messageRange> messageRange::fetch(TlBufferParser &p) {
  return make_tl_object<messageRange>(p);
}

messageRange::messageRange(TlBufferParser &p)
  : min_id_(TlFetchInt::parse(p))
  , max_id_(TlFetchInt::parse(p))
{}

void messageRange::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(max_id_, s);
}

void messageRange::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(max_id_, s);
}

void messageRange::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageRange");
    s.store_field("min_id", min_id_);
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

messageReplies::messageReplies()
  : flags_()
  , comments_()
  , replies_()
  , replies_pts_()
  , recent_repliers_()
  , channel_id_()
  , max_id_()
  , read_max_id_()
{}

const std::int32_t messageReplies::ID;

object_ptr<messageReplies> messageReplies::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageReplies> res = make_tl_object<messageReplies>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->comments_ = (var0 & 1) != 0;
  res->replies_ = TlFetchInt::parse(p);
  res->replies_pts_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->recent_repliers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p); }
  if (var0 & 1) { res->channel_id_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->max_id_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->read_max_id_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messageReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplies");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (comments_ << 0) | ((!recent_repliers_.empty()) << 1)));
    if (var0 & 1) { s.store_field("comments", true); }
    s.store_field("replies", replies_);
    s.store_field("replies_pts", replies_pts_);
    if (var0 & 2) { { s.store_vector_begin("recent_repliers", recent_repliers_.size()); for (const auto &_value : recent_repliers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1) { s.store_field("channel_id", channel_id_); }
    if (var0 & 4) { s.store_field("max_id", max_id_); }
    if (var0 & 8) { s.store_field("read_max_id", read_max_id_); }
    s.store_class_end();
  }
}

page::page()
  : flags_()
  , part_()
  , rtl_()
  , v2_()
  , url_()
  , blocks_()
  , photos_()
  , documents_()
  , views_()
{}

page::page(int32 flags_, bool part_, bool rtl_, bool v2_, string const &url_, array<object_ptr<PageBlock>> &&blocks_, array<object_ptr<Photo>> &&photos_, array<object_ptr<Document>> &&documents_, int32 views_)
  : flags_(flags_)
  , part_(part_)
  , rtl_(rtl_)
  , v2_(v2_)
  , url_(url_)
  , blocks_(std::move(blocks_))
  , photos_(std::move(photos_))
  , documents_(std::move(documents_))
  , views_(views_)
{}

const std::int32_t page::ID;

object_ptr<page> page::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<page> res = make_tl_object<page>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->part_ = (var0 & 1) != 0;
  res->rtl_ = (var0 & 2) != 0;
  res->v2_ = (var0 & 4) != 0;
  res->url_ = TlFetchString<string>::parse(p);
  res->blocks_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p);
  res->photos_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Photo>>, 481674261>::parse(p);
  res->documents_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p);
  if (var0 & 8) { res->views_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void page::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (part_ << 0) | (rtl_ << 1) | (v2_ << 2)), s);
  TlStoreString::store(url_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(photos_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s);
  if (var0 & 8) { TlStoreBinary::store(views_, s); }
}

void page::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (part_ << 0) | (rtl_ << 1) | (v2_ << 2)), s);
  TlStoreString::store(url_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(photos_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s);
  if (var0 & 8) { TlStoreBinary::store(views_, s); }
}

void page::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "page");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (part_ << 0) | (rtl_ << 1) | (v2_ << 2)));
    if (var0 & 1) { s.store_field("part", true); }
    if (var0 & 2) { s.store_field("rtl", true); }
    if (var0 & 4) { s.store_field("v2", true); }
    s.store_field("url", url_);
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("photos", photos_.size()); for (const auto &_value : photos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 8) { s.store_field("views", views_); }
    s.store_class_end();
  }
}

object_ptr<PasswordKdfAlgo> PasswordKdfAlgo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case passwordKdfAlgoUnknown::ID:
      return passwordKdfAlgoUnknown::fetch(p);
    case passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::ID:
      return passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t passwordKdfAlgoUnknown::ID;

object_ptr<PasswordKdfAlgo> passwordKdfAlgoUnknown::fetch(TlBufferParser &p) {
  return make_tl_object<passwordKdfAlgoUnknown>();
}

void passwordKdfAlgoUnknown::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void passwordKdfAlgoUnknown::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void passwordKdfAlgoUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passwordKdfAlgoUnknown");
    s.store_class_end();
  }
}

passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow(bytes &&salt1_, bytes &&salt2_, int32 g_, bytes &&p_)
  : salt1_(std::move(salt1_))
  , salt2_(std::move(salt2_))
  , g_(g_)
  , p_(std::move(p_))
{}

const std::int32_t passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::ID;

object_ptr<PasswordKdfAlgo> passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::fetch(TlBufferParser &p) {
  return make_tl_object<passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow>(p);
}

passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow(TlBufferParser &p)
  : salt1_(TlFetchBytes<bytes>::parse(p))
  , salt2_(TlFetchBytes<bytes>::parse(p))
  , g_(TlFetchInt::parse(p))
  , p_(TlFetchBytes<bytes>::parse(p))
{}

void passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt1_, s);
  TlStoreString::store(salt2_, s);
  TlStoreBinary::store(g_, s);
  TlStoreString::store(p_, s);
}

void passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt1_, s);
  TlStoreString::store(salt2_, s);
  TlStoreBinary::store(g_, s);
  TlStoreString::store(p_, s);
}

void passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow");
    s.store_bytes_field("salt1", salt1_);
    s.store_bytes_field("salt2", salt2_);
    s.store_field("g", g_);
    s.store_bytes_field("p", p_);
    s.store_class_end();
  }
}

object_ptr<Peer> Peer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case peerUser::ID:
      return peerUser::fetch(p);
    case peerChat::ID:
      return peerChat::fetch(p);
    case peerChannel::ID:
      return peerChannel::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

peerUser::peerUser(int64 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t peerUser::ID;

object_ptr<Peer> peerUser::fetch(TlBufferParser &p) {
  return make_tl_object<peerUser>(p);
}

peerUser::peerUser(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
{}

void peerUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
}

void peerUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
}

void peerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

peerChat::peerChat(int64 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t peerChat::ID;

object_ptr<Peer> peerChat::fetch(TlBufferParser &p) {
  return make_tl_object<peerChat>(p);
}

peerChat::peerChat(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
{}

void peerChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
}

void peerChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
}

void peerChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

peerChannel::peerChannel(int64 channel_id_)
  : channel_id_(channel_id_)
{}

const std::int32_t peerChannel::ID;

object_ptr<Peer> peerChannel::fetch(TlBufferParser &p) {
  return make_tl_object<peerChannel>(p);
}

peerChannel::peerChannel(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
{}

void peerChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
}

void peerChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
}

void peerChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerChannel");
    s.store_field("channel_id", channel_id_);
    s.store_class_end();
  }
}

premiumSubscriptionOption::premiumSubscriptionOption()
  : flags_()
  , current_()
  , can_purchase_upgrade_()
  , transaction_()
  , months_()
  , currency_()
  , amount_()
  , bot_url_()
  , store_product_()
{}

const std::int32_t premiumSubscriptionOption::ID;

object_ptr<premiumSubscriptionOption> premiumSubscriptionOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<premiumSubscriptionOption> res = make_tl_object<premiumSubscriptionOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->current_ = (var0 & 2) != 0;
  res->can_purchase_upgrade_ = (var0 & 4) != 0;
  if (var0 & 8) { res->transaction_ = TlFetchString<string>::parse(p); }
  res->months_ = TlFetchInt::parse(p);
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->bot_url_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->store_product_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void premiumSubscriptionOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSubscriptionOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (current_ << 1) | (can_purchase_upgrade_ << 2) | ((!transaction_.empty()) << 3) | ((!store_product_.empty()) << 0)));
    if (var0 & 2) { s.store_field("current", true); }
    if (var0 & 4) { s.store_field("can_purchase_upgrade", true); }
    if (var0 & 8) { s.store_field("transaction", transaction_); }
    s.store_field("months", months_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("bot_url", bot_url_);
    if (var0 & 1) { s.store_field("store_product", store_product_); }
    s.store_class_end();
  }
}

richButtonStyle::richButtonStyle()
  : flags_()
  , bg_primary_()
  , bg_danger_()
  , bg_success_()
  , link_()
{}

richButtonStyle::richButtonStyle(int32 flags_, bool bg_primary_, bool bg_danger_, bool bg_success_, bool link_)
  : flags_(flags_)
  , bg_primary_(bg_primary_)
  , bg_danger_(bg_danger_)
  , bg_success_(bg_success_)
  , link_(link_)
{}

const std::int32_t richButtonStyle::ID;

object_ptr<richButtonStyle> richButtonStyle::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<richButtonStyle> res = make_tl_object<richButtonStyle>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bg_primary_ = (var0 & 1) != 0;
  res->bg_danger_ = (var0 & 2) != 0;
  res->bg_success_ = (var0 & 4) != 0;
  res->link_ = (var0 & 8) != 0;
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void richButtonStyle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bg_primary_ << 0) | (bg_danger_ << 1) | (bg_success_ << 2) | (link_ << 3)), s);
}

void richButtonStyle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bg_primary_ << 0) | (bg_danger_ << 1) | (bg_success_ << 2) | (link_ << 3)), s);
}

void richButtonStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richButtonStyle");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (bg_primary_ << 0) | (bg_danger_ << 1) | (bg_success_ << 2) | (link_ << 3)));
    if (var0 & 1) { s.store_field("bg_primary", true); }
    if (var0 & 2) { s.store_field("bg_danger", true); }
    if (var0 & 4) { s.store_field("bg_success", true); }
    if (var0 & 8) { s.store_field("link", true); }
    s.store_class_end();
  }
}

searchPostsFlood::searchPostsFlood()
  : flags_()
  , query_is_free_()
  , total_daily_()
  , remains_()
  , wait_till_()
  , stars_amount_()
{}

const std::int32_t searchPostsFlood::ID;

object_ptr<searchPostsFlood> searchPostsFlood::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<searchPostsFlood> res = make_tl_object<searchPostsFlood>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_is_free_ = (var0 & 1) != 0;
  res->total_daily_ = TlFetchInt::parse(p);
  res->remains_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->wait_till_ = TlFetchInt::parse(p); }
  res->stars_amount_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void searchPostsFlood::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPostsFlood");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (query_is_free_ << 0)));
    if (var0 & 1) { s.store_field("query_is_free", true); }
    s.store_field("total_daily", total_daily_);
    s.store_field("remains", remains_);
    if (var0 & 2) { s.store_field("wait_till", wait_till_); }
    s.store_field("stars_amount", stars_amount_);
    s.store_class_end();
  }
}

secureValueHash::secureValueHash(object_ptr<SecureValueType> &&type_, bytes &&hash_)
  : type_(std::move(type_))
  , hash_(std::move(hash_))
{}

const std::int32_t secureValueHash::ID;

void secureValueHash::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(hash_, s);
}

void secureValueHash::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(hash_, s);
}

void secureValueHash::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueHash");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("hash", hash_);
    s.store_class_end();
  }
}

sendAsPeer::sendAsPeer()
  : flags_()
  , premium_required_()
  , peer_()
{}

const std::int32_t sendAsPeer::ID;

object_ptr<sendAsPeer> sendAsPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<sendAsPeer> res = make_tl_object<sendAsPeer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->premium_required_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void sendAsPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendAsPeer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (premium_required_ << 0)));
    if (var0 & 1) { s.store_field("premium_required", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

object_ptr<StarGiftAuctionRound> StarGiftAuctionRound::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starGiftAuctionRound::ID:
      return starGiftAuctionRound::fetch(p);
    case starGiftAuctionRoundExtendable::ID:
      return starGiftAuctionRoundExtendable::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t starGiftAuctionRound::ID;

object_ptr<StarGiftAuctionRound> starGiftAuctionRound::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAuctionRound>(p);
}

starGiftAuctionRound::starGiftAuctionRound(TlBufferParser &p)
  : num_(TlFetchInt::parse(p))
  , duration_(TlFetchInt::parse(p))
{}

void starGiftAuctionRound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionRound");
    s.store_field("num", num_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

const std::int32_t starGiftAuctionRoundExtendable::ID;

object_ptr<StarGiftAuctionRound> starGiftAuctionRoundExtendable::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAuctionRoundExtendable>(p);
}

starGiftAuctionRoundExtendable::starGiftAuctionRoundExtendable(TlBufferParser &p)
  : num_(TlFetchInt::parse(p))
  , duration_(TlFetchInt::parse(p))
  , extend_top_(TlFetchInt::parse(p))
  , extend_window_(TlFetchInt::parse(p))
{}

void starGiftAuctionRoundExtendable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionRoundExtendable");
    s.store_field("num", num_);
    s.store_field("duration", duration_);
    s.store_field("extend_top", extend_top_);
    s.store_field("extend_window", extend_window_);
    s.store_class_end();
  }
}

starsRevenueStatus::starsRevenueStatus()
  : flags_()
  , withdrawal_enabled_()
  , current_balance_()
  , available_balance_()
  , overall_revenue_()
  , next_withdrawal_at_()
{}

const std::int32_t starsRevenueStatus::ID;

object_ptr<starsRevenueStatus> starsRevenueStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsRevenueStatus> res = make_tl_object<starsRevenueStatus>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->withdrawal_enabled_ = (var0 & 1) != 0;
  res->current_balance_ = TlFetchObject<StarsAmount>::parse(p);
  res->available_balance_ = TlFetchObject<StarsAmount>::parse(p);
  res->overall_revenue_ = TlFetchObject<StarsAmount>::parse(p);
  if (var0 & 2) { res->next_withdrawal_at_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsRevenueStatus");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (withdrawal_enabled_ << 0)));
    if (var0 & 1) { s.store_field("withdrawal_enabled", true); }
    s.store_object_field("current_balance", static_cast<const BaseObject *>(current_balance_.get()));
    s.store_object_field("available_balance", static_cast<const BaseObject *>(available_balance_.get()));
    s.store_object_field("overall_revenue", static_cast<const BaseObject *>(overall_revenue_.get()));
    if (var0 & 2) { s.store_field("next_withdrawal_at", next_withdrawal_at_); }
    s.store_class_end();
  }
}

const std::int32_t statsPercentValue::ID;

object_ptr<statsPercentValue> statsPercentValue::fetch(TlBufferParser &p) {
  return make_tl_object<statsPercentValue>(p);
}

statsPercentValue::statsPercentValue(TlBufferParser &p)
  : part_(TlFetchDouble::parse(p))
  , total_(TlFetchDouble::parse(p))
{}

void statsPercentValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsPercentValue");
    s.store_field("part", part_);
    s.store_field("total", total_);
    s.store_class_end();
  }
}

textWithEntities::textWithEntities(string const &text_, array<object_ptr<MessageEntity>> &&entities_)
  : text_(text_)
  , entities_(std::move(entities_))
{}

const std::int32_t textWithEntities::ID;

object_ptr<textWithEntities> textWithEntities::fetch(TlBufferParser &p) {
  return make_tl_object<textWithEntities>(p);
}

textWithEntities::textWithEntities(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , entities_(TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p))
{}

void textWithEntities::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s);
}

void textWithEntities::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s);
}

void textWithEntities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textWithEntities");
    s.store_field("text", text_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<WalletOnchainGiftAction> WalletOnchainGiftAction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case walletOnchainGiftActionBuy::ID:
      return walletOnchainGiftActionBuy::fetch(p);
    case walletOnchainGiftActionDelist::ID:
      return walletOnchainGiftActionDelist::fetch(p);
    case walletOnchainGiftActionChangePrice::ID:
      return walletOnchainGiftActionChangePrice::fetch(p);
    case walletOnchainGiftActionOfferCreate::ID:
      return walletOnchainGiftActionOfferCreate::fetch(p);
    case walletOnchainGiftActionOfferAccept::ID:
      return walletOnchainGiftActionOfferAccept::fetch(p);
    case walletOnchainGiftActionOfferCancel::ID:
      return walletOnchainGiftActionOfferCancel::fetch(p);
    case walletOnchainGiftActionOfferDecline::ID:
      return walletOnchainGiftActionOfferDecline::fetch(p);
    case walletOnchainGiftActionOfferExpire::ID:
      return walletOnchainGiftActionOfferExpire::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t walletOnchainGiftActionBuy::ID;

object_ptr<WalletOnchainGiftAction> walletOnchainGiftActionBuy::fetch(TlBufferParser &p) {
  return make_tl_object<walletOnchainGiftActionBuy>();
}

void walletOnchainGiftActionBuy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletOnchainGiftActionBuy");
    s.store_class_end();
  }
}

const std::int32_t walletOnchainGiftActionDelist::ID;

object_ptr<WalletOnchainGiftAction> walletOnchainGiftActionDelist::fetch(TlBufferParser &p) {
  return make_tl_object<walletOnchainGiftActionDelist>();
}

void walletOnchainGiftActionDelist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletOnchainGiftActionDelist");
    s.store_class_end();
  }
}

walletOnchainGiftActionChangePrice::walletOnchainGiftActionChangePrice()
  : flags_()
  , old_price_()
  , new_price_()
{}

const std::int32_t walletOnchainGiftActionChangePrice::ID;

object_ptr<WalletOnchainGiftAction> walletOnchainGiftActionChangePrice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletOnchainGiftActionChangePrice> res = make_tl_object<walletOnchainGiftActionChangePrice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->old_price_ = TlFetchLong::parse(p); }
  res->new_price_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletOnchainGiftActionChangePrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletOnchainGiftActionChangePrice");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("old_price", old_price_); }
    s.store_field("new_price", new_price_);
    s.store_class_end();
  }
}

walletOnchainGiftActionOfferCreate::walletOnchainGiftActionOfferCreate()
  : flags_()
  , offer_address_()
  , counterparty_address_()
  , price_()
  , amount_()
  , service_fee_()
  , expires_at_()
{}

const std::int32_t walletOnchainGiftActionOfferCreate::ID;

object_ptr<WalletOnchainGiftAction> walletOnchainGiftActionOfferCreate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletOnchainGiftActionOfferCreate> res = make_tl_object<walletOnchainGiftActionOfferCreate>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->offer_address_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->counterparty_address_ = TlFetchString<string>::parse(p); }
  res->price_ = TlFetchLong::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->service_fee_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->expires_at_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletOnchainGiftActionOfferCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletOnchainGiftActionOfferCreate");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!counterparty_address_.empty()) << 0)));
    s.store_field("offer_address", offer_address_);
    if (var0 & 1) { s.store_field("counterparty_address", counterparty_address_); }
    s.store_field("price", price_);
    s.store_field("amount", amount_);
    s.store_field("service_fee", service_fee_);
    if (var0 & 2) { s.store_field("expires_at", expires_at_); }
    s.store_class_end();
  }
}

walletOnchainGiftActionOfferAccept::walletOnchainGiftActionOfferAccept()
  : flags_()
  , buyer_()
  , offer_address_()
  , counterparty_address_()
  , price_()
  , service_fee_()
{}

const std::int32_t walletOnchainGiftActionOfferAccept::ID;

object_ptr<WalletOnchainGiftAction> walletOnchainGiftActionOfferAccept::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletOnchainGiftActionOfferAccept> res = make_tl_object<walletOnchainGiftActionOfferAccept>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->buyer_ = (var0 & 1) != 0;
  res->offer_address_ = TlFetchString<string>::parse(p);
  res->counterparty_address_ = TlFetchString<string>::parse(p);
  res->price_ = TlFetchLong::parse(p);
  res->service_fee_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletOnchainGiftActionOfferAccept::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletOnchainGiftActionOfferAccept");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (buyer_ << 0)));
    if (var0 & 1) { s.store_field("buyer", true); }
    s.store_field("offer_address", offer_address_);
    s.store_field("counterparty_address", counterparty_address_);
    s.store_field("price", price_);
    s.store_field("service_fee", service_fee_);
    s.store_class_end();
  }
}

walletOnchainGiftActionOfferCancel::walletOnchainGiftActionOfferCancel()
  : flags_()
  , offer_address_()
  , counterparty_address_()
  , price_()
  , refund_amount_()
  , fine_()
{}

const std::int32_t walletOnchainGiftActionOfferCancel::ID;

object_ptr<WalletOnchainGiftAction> walletOnchainGiftActionOfferCancel::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletOnchainGiftActionOfferCancel> res = make_tl_object<walletOnchainGiftActionOfferCancel>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->offer_address_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->counterparty_address_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->price_ = TlFetchLong::parse(p); }
  res->refund_amount_ = TlFetchLong::parse(p);
  if (var0 & 4) { res->fine_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletOnchainGiftActionOfferCancel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletOnchainGiftActionOfferCancel");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!counterparty_address_.empty()) << 0)));
    s.store_field("offer_address", offer_address_);
    if (var0 & 1) { s.store_field("counterparty_address", counterparty_address_); }
    if (var0 & 2) { s.store_field("price", price_); }
    s.store_field("refund_amount", refund_amount_);
    if (var0 & 4) { s.store_field("fine", fine_); }
    s.store_class_end();
  }
}

walletOnchainGiftActionOfferDecline::walletOnchainGiftActionOfferDecline()
  : flags_()
  , offer_address_()
  , counterparty_address_()
  , price_()
  , refund_amount_()
{}

const std::int32_t walletOnchainGiftActionOfferDecline::ID;

object_ptr<WalletOnchainGiftAction> walletOnchainGiftActionOfferDecline::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletOnchainGiftActionOfferDecline> res = make_tl_object<walletOnchainGiftActionOfferDecline>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->offer_address_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->counterparty_address_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->price_ = TlFetchLong::parse(p); }
  res->refund_amount_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletOnchainGiftActionOfferDecline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletOnchainGiftActionOfferDecline");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!counterparty_address_.empty()) << 0)));
    s.store_field("offer_address", offer_address_);
    if (var0 & 1) { s.store_field("counterparty_address", counterparty_address_); }
    if (var0 & 2) { s.store_field("price", price_); }
    s.store_field("refund_amount", refund_amount_);
    s.store_class_end();
  }
}

walletOnchainGiftActionOfferExpire::walletOnchainGiftActionOfferExpire()
  : flags_()
  , offer_address_()
  , counterparty_address_()
  , price_()
  , refund_amount_()
{}

const std::int32_t walletOnchainGiftActionOfferExpire::ID;

object_ptr<WalletOnchainGiftAction> walletOnchainGiftActionOfferExpire::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletOnchainGiftActionOfferExpire> res = make_tl_object<walletOnchainGiftActionOfferExpire>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->offer_address_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->counterparty_address_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->price_ = TlFetchLong::parse(p); }
  res->refund_amount_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletOnchainGiftActionOfferExpire::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletOnchainGiftActionOfferExpire");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!counterparty_address_.empty()) << 0)));
    s.store_field("offer_address", offer_address_);
    if (var0 & 1) { s.store_field("counterparty_address", counterparty_address_); }
    if (var0 & 2) { s.store_field("price", price_); }
    s.store_field("refund_amount", refund_amount_);
    s.store_class_end();
  }
}

object_ptr<WalletState> WalletState::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case walletStateEmpty::ID:
      return walletStateEmpty::fetch(p);
    case walletState::ID:
      return walletState::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

walletStateEmpty::walletStateEmpty()
  : flags_()
  , creating_()
{}

const std::int32_t walletStateEmpty::ID;

object_ptr<WalletState> walletStateEmpty::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletStateEmpty> res = make_tl_object<walletStateEmpty>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creating_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletStateEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletStateEmpty");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (creating_ << 0)));
    if (var0 & 1) { s.store_field("creating", true); }
    s.store_class_end();
  }
}

walletState::walletState()
  : flags_()
  , backup_enabled_()
  , can_export_phrase_()
  , can_enable_backup_()
  , address_()
  , public_key_()
  , balance_()
{}

const std::int32_t walletState::ID;

object_ptr<WalletState> walletState::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletState> res = make_tl_object<walletState>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->backup_enabled_ = (var0 & 1) != 0;
  res->can_export_phrase_ = (var0 & 2) != 0;
  res->can_enable_backup_ = (var0 & 4) != 0;
  res->address_ = TlFetchString<string>::parse(p);
  res->public_key_ = TlFetchBytes<bytes>::parse(p);
  res->balance_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletState");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (backup_enabled_ << 0) | (can_export_phrase_ << 1) | (can_enable_backup_ << 2)));
    if (var0 & 1) { s.store_field("backup_enabled", true); }
    if (var0 & 2) { s.store_field("can_export_phrase", true); }
    if (var0 & 4) { s.store_field("can_enable_backup", true); }
    s.store_field("address", address_);
    s.store_bytes_field("public_key", public_key_);
    s.store_field("balance", balance_);
    s.store_class_end();
  }
}

const std::int32_t webAuthorization::ID;

object_ptr<webAuthorization> webAuthorization::fetch(TlBufferParser &p) {
  return make_tl_object<webAuthorization>(p);
}

webAuthorization::webAuthorization(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , bot_id_(TlFetchLong::parse(p))
  , domain_(TlFetchString<string>::parse(p))
  , browser_(TlFetchString<string>::parse(p))
  , platform_(TlFetchString<string>::parse(p))
  , date_created_(TlFetchInt::parse(p))
  , date_active_(TlFetchInt::parse(p))
  , ip_(TlFetchString<string>::parse(p))
  , region_(TlFetchString<string>::parse(p))
{}

void webAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAuthorization");
    s.store_field("hash", hash_);
    s.store_field("bot_id", bot_id_);
    s.store_field("domain", domain_);
    s.store_field("browser", browser_);
    s.store_field("platform", platform_);
    s.store_field("date_created", date_created_);
    s.store_field("date_active", date_active_);
    s.store_field("ip", ip_);
    s.store_field("region", region_);
    s.store_class_end();
  }
}

const std::int32_t account_passkeyRegistrationOptions::ID;

object_ptr<account_passkeyRegistrationOptions> account_passkeyRegistrationOptions::fetch(TlBufferParser &p) {
  return make_tl_object<account_passkeyRegistrationOptions>(p);
}

account_passkeyRegistrationOptions::account_passkeyRegistrationOptions(TlBufferParser &p)
  : options_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void account_passkeyRegistrationOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.passkeyRegistrationOptions");
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_class_end();
  }
}

object_ptr<account_SavedRingtones> account_SavedRingtones::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_savedRingtonesNotModified::ID:
      return account_savedRingtonesNotModified::fetch(p);
    case account_savedRingtones::ID:
      return account_savedRingtones::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_savedRingtonesNotModified::ID;

object_ptr<account_SavedRingtones> account_savedRingtonesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedRingtonesNotModified>();
}

void account_savedRingtonesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedRingtonesNotModified");
    s.store_class_end();
  }
}

const std::int32_t account_savedRingtones::ID;

object_ptr<account_SavedRingtones> account_savedRingtones::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedRingtones>(p);
}

account_savedRingtones::account_savedRingtones(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , ringtones_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void account_savedRingtones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedRingtones");
    s.store_field("hash", hash_);
    { s.store_vector_begin("ringtones", ringtones_.size()); for (const auto &_value : ringtones_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t account_webAuthorizations::ID;

object_ptr<account_webAuthorizations> account_webAuthorizations::fetch(TlBufferParser &p) {
  return make_tl_object<account_webAuthorizations>(p);
}

account_webAuthorizations::account_webAuthorizations(TlBufferParser &p)
  : authorizations_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<webAuthorization>, -1493633966>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void account_webAuthorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.webAuthorizations");
    { s.store_vector_begin("authorizations", authorizations_.size()); for (const auto &_value : authorizations_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

auth_loggedOut::auth_loggedOut()
  : flags_()
  , future_auth_token_()
{}

const std::int32_t auth_loggedOut::ID;

object_ptr<auth_loggedOut> auth_loggedOut::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_loggedOut> res = make_tl_object<auth_loggedOut>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->future_auth_token_ = TlFetchBytes<bytes>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void auth_loggedOut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.loggedOut");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!future_auth_token_.empty()) << 0)));
    if (var0 & 1) { s.store_field("future_auth_token", "[REDACTED]"); }
    s.store_class_end();
  }
}

object_ptr<auth_LoginToken> auth_LoginToken::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case auth_loginToken::ID:
      return auth_loginToken::fetch(p);
    case auth_loginTokenMigrateTo::ID:
      return auth_loginTokenMigrateTo::fetch(p);
    case auth_loginTokenSuccess::ID:
      return auth_loginTokenSuccess::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t auth_loginToken::ID;

object_ptr<auth_LoginToken> auth_loginToken::fetch(TlBufferParser &p) {
  return make_tl_object<auth_loginToken>(p);
}

auth_loginToken::auth_loginToken(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
  , token_(TlFetchBytes<bytes>::parse(p))
{}

void auth_loginToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.loginToken");
    s.store_field("expires", expires_);
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

const std::int32_t auth_loginTokenMigrateTo::ID;

object_ptr<auth_LoginToken> auth_loginTokenMigrateTo::fetch(TlBufferParser &p) {
  return make_tl_object<auth_loginTokenMigrateTo>(p);
}

auth_loginTokenMigrateTo::auth_loginTokenMigrateTo(TlBufferParser &p)
  : dc_id_(TlFetchInt::parse(p))
  , token_(TlFetchBytes<bytes>::parse(p))
{}

void auth_loginTokenMigrateTo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.loginTokenMigrateTo");
    s.store_field("dc_id", dc_id_);
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

const std::int32_t auth_loginTokenSuccess::ID;

object_ptr<auth_LoginToken> auth_loginTokenSuccess::fetch(TlBufferParser &p) {
  return make_tl_object<auth_loginTokenSuccess>(p);
}

auth_loginTokenSuccess::auth_loginTokenSuccess(TlBufferParser &p)
  : authorization_(TlFetchObject<auth_Authorization>::parse(p))
{}

void auth_loginTokenSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.loginTokenSuccess");
    s.store_object_field("authorization", static_cast<const BaseObject *>(authorization_.get()));
    s.store_class_end();
  }
}

object_ptr<channels_ChannelParticipants> channels_ChannelParticipants::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case channels_channelParticipants::ID:
      return channels_channelParticipants::fetch(p);
    case channels_channelParticipantsNotModified::ID:
      return channels_channelParticipantsNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t channels_channelParticipants::ID;

object_ptr<channels_ChannelParticipants> channels_channelParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<channels_channelParticipants>(p);
}

channels_channelParticipants::channels_channelParticipants(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , participants_(TlFetchBoxed<TlFetchVector<TlFetchObject<ChannelParticipant>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void channels_channelParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.channelParticipants");
    s.store_field("count", count_);
    { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t channels_channelParticipantsNotModified::ID;

object_ptr<channels_ChannelParticipants> channels_channelParticipantsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<channels_channelParticipantsNotModified>();
}

void channels_channelParticipantsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.channelParticipantsNotModified");
    s.store_class_end();
  }
}

const std::int32_t channels_sendAsPeers::ID;

object_ptr<channels_sendAsPeers> channels_sendAsPeers::fetch(TlBufferParser &p) {
  return make_tl_object<channels_sendAsPeers>(p);
}

channels_sendAsPeers::channels_sendAsPeers(TlBufferParser &p)
  : peers_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<sendAsPeer>, -1206095820>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void channels_sendAsPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.sendAsPeers");
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t chatlists_chatlistUpdates::ID;

object_ptr<chatlists_chatlistUpdates> chatlists_chatlistUpdates::fetch(TlBufferParser &p) {
  return make_tl_object<chatlists_chatlistUpdates>(p);
}

chatlists_chatlistUpdates::chatlists_chatlistUpdates(TlBufferParser &p)
  : missing_peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void chatlists_chatlistUpdates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.chatlistUpdates");
    { s.store_vector_begin("missing_peers", missing_peers_.size()); for (const auto &_value : missing_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t chatlists_exportedChatlistInvite::ID;

object_ptr<chatlists_exportedChatlistInvite> chatlists_exportedChatlistInvite::fetch(TlBufferParser &p) {
  return make_tl_object<chatlists_exportedChatlistInvite>(p);
}

chatlists_exportedChatlistInvite::chatlists_exportedChatlistInvite(TlBufferParser &p)
  : filter_(TlFetchObject<DialogFilter>::parse(p))
  , invite_(TlFetchBoxed<TlFetchObject<exportedChatlistInvite>, 206668204>::parse(p))
{}

void chatlists_exportedChatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.exportedChatlistInvite");
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_class_end();
  }
}

object_ptr<help_PassportConfig> help_PassportConfig::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_passportConfigNotModified::ID:
      return help_passportConfigNotModified::fetch(p);
    case help_passportConfig::ID:
      return help_passportConfig::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_passportConfigNotModified::ID;

object_ptr<help_PassportConfig> help_passportConfigNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<help_passportConfigNotModified>();
}

void help_passportConfigNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.passportConfigNotModified");
    s.store_class_end();
  }
}

const std::int32_t help_passportConfig::ID;

object_ptr<help_PassportConfig> help_passportConfig::fetch(TlBufferParser &p) {
  return make_tl_object<help_passportConfig>(p);
}

help_passportConfig::help_passportConfig(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , countries_langs_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void help_passportConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.passportConfig");
    s.store_field("hash", hash_);
    s.store_object_field("countries_langs", static_cast<const BaseObject *>(countries_langs_.get()));
    s.store_class_end();
  }
}

object_ptr<help_PromoData> help_PromoData::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_promoDataEmpty::ID:
      return help_promoDataEmpty::fetch(p);
    case help_promoData::ID:
      return help_promoData::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_promoDataEmpty::ID;

object_ptr<help_PromoData> help_promoDataEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<help_promoDataEmpty>(p);
}

help_promoDataEmpty::help_promoDataEmpty(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
{}

void help_promoDataEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.promoDataEmpty");
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

help_promoData::help_promoData()
  : flags_()
  , proxy_()
  , expires_()
  , peer_()
  , psa_type_()
  , psa_message_()
  , pending_suggestions_()
  , dismissed_suggestions_()
  , custom_pending_suggestion_()
  , chats_()
  , users_()
{}

const std::int32_t help_promoData::ID;

object_ptr<help_PromoData> help_promoData::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_promoData> res = make_tl_object<help_promoData>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->proxy_ = (var0 & 1) != 0;
  res->expires_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2) { res->psa_type_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->psa_message_ = TlFetchString<string>::parse(p); }
  res->pending_suggestions_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p);
  res->dismissed_suggestions_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p);
  if (var0 & 16) { res->custom_pending_suggestion_ = TlFetchBoxed<TlFetchObject<pendingSuggestion>, -404214254>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void help_promoData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.promoData");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (proxy_ << 0) | ((peer_ != nullptr) << 3) | ((!psa_type_.empty()) << 1) | ((!psa_message_.empty()) << 2) | ((custom_pending_suggestion_ != nullptr) << 4)));
    if (var0 & 1) { s.store_field("proxy", true); }
    s.store_field("expires", expires_);
    if (var0 & 8) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 2) { s.store_field("psa_type", psa_type_); }
    if (var0 & 4) { s.store_field("psa_message", psa_message_); }
    { s.store_vector_begin("pending_suggestions", pending_suggestions_.size()); for (const auto &_value : pending_suggestions_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("dismissed_suggestions", dismissed_suggestions_.size()); for (const auto &_value : dismissed_suggestions_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 16) { s.store_object_field("custom_pending_suggestion", static_cast<const BaseObject *>(custom_pending_suggestion_.get())); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t help_recentMeUrls::ID;

object_ptr<help_recentMeUrls> help_recentMeUrls::fetch(TlBufferParser &p) {
  return make_tl_object<help_recentMeUrls>(p);
}

help_recentMeUrls::help_recentMeUrls(TlBufferParser &p)
  : urls_(TlFetchBoxed<TlFetchVector<TlFetchObject<RecentMeUrl>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void help_recentMeUrls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.recentMeUrls");
    { s.store_vector_begin("urls", urls_.size()); for (const auto &_value : urls_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_affectedHistory::ID;

object_ptr<messages_affectedHistory> messages_affectedHistory::fetch(TlBufferParser &p) {
  return make_tl_object<messages_affectedHistory>(p);
}

messages_affectedHistory::messages_affectedHistory(TlBufferParser &p)
  : pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
  , offset_(TlFetchInt::parse(p))
{}

void messages_affectedHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.affectedHistory");
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

const std::int32_t messages_affectedMessages::ID;

object_ptr<messages_affectedMessages> messages_affectedMessages::fetch(TlBufferParser &p) {
  return make_tl_object<messages_affectedMessages>(p);
}

messages_affectedMessages::messages_affectedMessages(TlBufferParser &p)
  : pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void messages_affectedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.affectedMessages");
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

object_ptr<messages_AllStickers> messages_AllStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_allStickersNotModified::ID:
      return messages_allStickersNotModified::fetch(p);
    case messages_allStickers::ID:
      return messages_allStickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_allStickersNotModified::ID;

object_ptr<messages_AllStickers> messages_allStickersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_allStickersNotModified>();
}

void messages_allStickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.allStickersNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_allStickers::ID;

object_ptr<messages_AllStickers> messages_allStickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_allStickers>(p);
}

messages_allStickers::messages_allStickers(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , sets_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>>, 481674261>::parse(p))
{}

void messages_allStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.allStickers");
    s.store_field("hash", hash_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_FeaturedStickers> messages_FeaturedStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_featuredStickersNotModified::ID:
      return messages_featuredStickersNotModified::fetch(p);
    case messages_featuredStickers::ID:
      return messages_featuredStickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_featuredStickersNotModified::ID;

object_ptr<messages_FeaturedStickers> messages_featuredStickersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_featuredStickersNotModified>(p);
}

messages_featuredStickersNotModified::messages_featuredStickersNotModified(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
{}

void messages_featuredStickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.featuredStickersNotModified");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

messages_featuredStickers::messages_featuredStickers()
  : flags_()
  , premium_()
  , hash_()
  , count_()
  , sets_()
  , unread_()
{}

const std::int32_t messages_featuredStickers::ID;

object_ptr<messages_FeaturedStickers> messages_featuredStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_featuredStickers> res = make_tl_object<messages_featuredStickers>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->premium_ = (var0 & 1) != 0;
  res->hash_ = TlFetchLong::parse(p);
  res->count_ = TlFetchInt::parse(p);
  res->sets_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p);
  res->unread_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_featuredStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.featuredStickers");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (premium_ << 0)));
    if (var0 & 1) { s.store_field("premium", true); }
    s.store_field("hash", hash_);
    s.store_field("count", count_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("unread", unread_.size()); for (const auto &_value : unread_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_historyImport::ID;

object_ptr<messages_historyImport> messages_historyImport::fetch(TlBufferParser &p) {
  return make_tl_object<messages_historyImport>(p);
}

messages_historyImport::messages_historyImport(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void messages_historyImport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.historyImport");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

object_ptr<messages_SavedDialogs> messages_SavedDialogs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_savedDialogs::ID:
      return messages_savedDialogs::fetch(p);
    case messages_savedDialogsSlice::ID:
      return messages_savedDialogsSlice::fetch(p);
    case messages_savedDialogsNotModified::ID:
      return messages_savedDialogsNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_savedDialogs::ID;

object_ptr<messages_SavedDialogs> messages_savedDialogs::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedDialogs>(p);
}

messages_savedDialogs::messages_savedDialogs(TlBufferParser &p)
  : dialogs_(TlFetchBoxed<TlFetchVector<TlFetchObject<SavedDialog>>, 481674261>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_savedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedDialogs");
    { s.store_vector_begin("dialogs", dialogs_.size()); for (const auto &_value : dialogs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_savedDialogsSlice::ID;

object_ptr<messages_SavedDialogs> messages_savedDialogsSlice::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedDialogsSlice>(p);
}

messages_savedDialogsSlice::messages_savedDialogsSlice(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , dialogs_(TlFetchBoxed<TlFetchVector<TlFetchObject<SavedDialog>>, 481674261>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_savedDialogsSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedDialogsSlice");
    s.store_field("count", count_);
    { s.store_vector_begin("dialogs", dialogs_.size()); for (const auto &_value : dialogs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_savedDialogsNotModified::ID;

object_ptr<messages_SavedDialogs> messages_savedDialogsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedDialogsNotModified>(p);
}

messages_savedDialogsNotModified::messages_savedDialogsNotModified(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
{}

void messages_savedDialogsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedDialogsNotModified");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

messages_searchCounter::messages_searchCounter()
  : flags_()
  , inexact_()
  , filter_()
  , count_()
{}

const std::int32_t messages_searchCounter::ID;

object_ptr<messages_searchCounter> messages_searchCounter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_searchCounter> res = make_tl_object<messages_searchCounter>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inexact_ = (var0 & 2) != 0;
  res->filter_ = TlFetchObject<MessagesFilter>::parse(p);
  res->count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_searchCounter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchCounter");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inexact_ << 1)));
    if (var0 & 2) { s.store_field("inexact", true); }
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("count", count_);
    s.store_class_end();
  }
}

messages_searchResultsCalendar::messages_searchResultsCalendar()
  : flags_()
  , inexact_()
  , count_()
  , min_date_()
  , min_msg_id_()
  , offset_id_offset_()
  , periods_()
  , messages_()
  , chats_()
  , users_()
{}

const std::int32_t messages_searchResultsCalendar::ID;

object_ptr<messages_searchResultsCalendar> messages_searchResultsCalendar::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_searchResultsCalendar> res = make_tl_object<messages_searchResultsCalendar>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inexact_ = (var0 & 1) != 0;
  res->count_ = TlFetchInt::parse(p);
  res->min_date_ = TlFetchInt::parse(p);
  res->min_msg_id_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->offset_id_offset_ = TlFetchInt::parse(p); }
  res->periods_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<searchResultsCalendarPeriod>, -911191137>>, 481674261>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_searchResultsCalendar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchResultsCalendar");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inexact_ << 0)));
    if (var0 & 1) { s.store_field("inexact", true); }
    s.store_field("count", count_);
    s.store_field("min_date", min_date_);
    s.store_field("min_msg_id", min_msg_id_);
    if (var0 & 2) { s.store_field("offset_id_offset", offset_id_offset_); }
    { s.store_vector_begin("periods", periods_.size()); for (const auto &_value : periods_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_bankCardData::ID;

object_ptr<payments_bankCardData> payments_bankCardData::fetch(TlBufferParser &p) {
  return make_tl_object<payments_bankCardData>(p);
}

payments_bankCardData::payments_bankCardData(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , open_urls_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<bankCardOpenUrl>, -177732982>>, 481674261>::parse(p))
{}

void payments_bankCardData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.bankCardData");
    s.store_field("title", title_);
    { s.store_vector_begin("open_urls", open_urls_.size()); for (const auto &_value : open_urls_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_uniqueStarGift::ID;

object_ptr<payments_uniqueStarGift> payments_uniqueStarGift::fetch(TlBufferParser &p) {
  return make_tl_object<payments_uniqueStarGift>(p);
}

payments_uniqueStarGift::payments_uniqueStarGift(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void payments_uniqueStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.uniqueStarGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stats_megagroupStats::ID;

object_ptr<stats_megagroupStats> stats_megagroupStats::fetch(TlBufferParser &p) {
  return make_tl_object<stats_megagroupStats>(p);
}

stats_megagroupStats::stats_megagroupStats(TlBufferParser &p)
  : period_(TlFetchBoxed<TlFetchObject<statsDateRangeDays>, -1237848657>::parse(p))
  , members_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , messages_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , viewers_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , posters_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , growth_graph_(TlFetchObject<StatsGraph>::parse(p))
  , members_graph_(TlFetchObject<StatsGraph>::parse(p))
  , new_members_by_source_graph_(TlFetchObject<StatsGraph>::parse(p))
  , languages_graph_(TlFetchObject<StatsGraph>::parse(p))
  , messages_graph_(TlFetchObject<StatsGraph>::parse(p))
  , actions_graph_(TlFetchObject<StatsGraph>::parse(p))
  , top_hours_graph_(TlFetchObject<StatsGraph>::parse(p))
  , weekdays_graph_(TlFetchObject<StatsGraph>::parse(p))
  , top_posters_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<statsGroupTopPoster>, -1660637285>>, 481674261>::parse(p))
  , top_admins_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<statsGroupTopAdmin>, -682079097>>, 481674261>::parse(p))
  , top_inviters_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<statsGroupTopInviter>, 1398765469>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void stats_megagroupStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.megagroupStats");
    s.store_object_field("period", static_cast<const BaseObject *>(period_.get()));
    s.store_object_field("members", static_cast<const BaseObject *>(members_.get()));
    s.store_object_field("messages", static_cast<const BaseObject *>(messages_.get()));
    s.store_object_field("viewers", static_cast<const BaseObject *>(viewers_.get()));
    s.store_object_field("posters", static_cast<const BaseObject *>(posters_.get()));
    s.store_object_field("growth_graph", static_cast<const BaseObject *>(growth_graph_.get()));
    s.store_object_field("members_graph", static_cast<const BaseObject *>(members_graph_.get()));
    s.store_object_field("new_members_by_source_graph", static_cast<const BaseObject *>(new_members_by_source_graph_.get()));
    s.store_object_field("languages_graph", static_cast<const BaseObject *>(languages_graph_.get()));
    s.store_object_field("messages_graph", static_cast<const BaseObject *>(messages_graph_.get()));
    s.store_object_field("actions_graph", static_cast<const BaseObject *>(actions_graph_.get()));
    s.store_object_field("top_hours_graph", static_cast<const BaseObject *>(top_hours_graph_.get()));
    s.store_object_field("weekdays_graph", static_cast<const BaseObject *>(weekdays_graph_.get()));
    { s.store_vector_begin("top_posters", top_posters_.size()); for (const auto &_value : top_posters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_admins", top_admins_.size()); for (const auto &_value : top_admins_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_inviters", top_inviters_.size()); for (const auto &_value : top_inviters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t toncenter_streamingUrl::ID;

object_ptr<toncenter_streamingUrl> toncenter_streamingUrl::fetch(TlBufferParser &p) {
  return make_tl_object<toncenter_streamingUrl>(p);
}

toncenter_streamingUrl::toncenter_streamingUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , expires_(TlFetchInt::parse(p))
{}

void toncenter_streamingUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toncenter.streamingUrl");
    s.store_field("url", url_);
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

const std::int32_t wallet_tonConnectChallenge::ID;

object_ptr<wallet_tonConnectChallenge> wallet_tonConnectChallenge::fetch(TlBufferParser &p) {
  return make_tl_object<wallet_tonConnectChallenge>(p);
}

wallet_tonConnectChallenge::wallet_tonConnectChallenge(TlBufferParser &p)
  : challenge_(TlFetchBytes<bytes>::parse(p))
  , event_id_(TlFetchLong::parse(p))
{}

void wallet_tonConnectChallenge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectChallenge");
    s.store_bytes_field("challenge", challenge_);
    s.store_field("event_id", event_id_);
    s.store_class_end();
  }
}

account_createBusinessChatLink::account_createBusinessChatLink(object_ptr<inputBusinessChatLink> &&link_)
  : link_(std::move(link_))
{}

const std::int32_t account_createBusinessChatLink::ID;

void account_createBusinessChatLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2007898482);
  TlStoreBoxed<TlStoreObject, 292003751>::store(link_, s);
}

void account_createBusinessChatLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2007898482);
  TlStoreBoxed<TlStoreObject, 292003751>::store(link_, s);
}

void account_createBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.createBusinessChatLink");
    s.store_object_field("link", static_cast<const BaseObject *>(link_.get()));
    s.store_class_end();
  }
}

account_createBusinessChatLink::ReturnType account_createBusinessChatLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<businessChatLink>, -1263638929>::parse(p);
#undef FAIL
}

account_getMultiWallPapers::account_getMultiWallPapers(array<object_ptr<InputWallPaper>> &&wallpapers_)
  : wallpapers_(std::move(wallpapers_))
{}

const std::int32_t account_getMultiWallPapers::ID;

void account_getMultiWallPapers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1705865692);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(wallpapers_, s);
}

void account_getMultiWallPapers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1705865692);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(wallpapers_, s);
}

void account_getMultiWallPapers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getMultiWallPapers");
    { s.store_vector_begin("wallpapers", wallpapers_.size()); for (const auto &_value : wallpapers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_getMultiWallPapers::ReturnType account_getMultiWallPapers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<WallPaper>>, 481674261>::parse(p);
#undef FAIL
}

account_getTheme::account_getTheme(string const &format_, object_ptr<InputTheme> &&theme_)
  : format_(format_)
  , theme_(std::move(theme_))
{}

const std::int32_t account_getTheme::ID;

void account_getTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(978872812);
  TlStoreString::store(format_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
}

void account_getTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(978872812);
  TlStoreString::store(format_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
}

void account_getTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getTheme");
    s.store_field("format", format_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

account_getTheme::ReturnType account_getTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<theme>, -1609668650>::parse(p);
#undef FAIL
}

const std::int32_t account_resetPassword::ID;

void account_resetPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1828139493);
}

void account_resetPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1828139493);
}

void account_resetPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetPassword");
    s.store_class_end();
  }
}

account_resetPassword::ReturnType account_resetPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_ResetPasswordResult>::parse(p);
#undef FAIL
}

account_sendConfirmPhoneCode::account_sendConfirmPhoneCode(string const &hash_, object_ptr<codeSettings> &&settings_)
  : hash_(hash_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_sendConfirmPhoneCode::ID;

void account_sendConfirmPhoneCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(457157256);
  TlStoreString::store(hash_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendConfirmPhoneCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(457157256);
  TlStoreString::store(hash_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendConfirmPhoneCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.sendConfirmPhoneCode");
    s.store_field("hash", hash_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_sendConfirmPhoneCode::ReturnType account_sendConfirmPhoneCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

account_updateBusinessWorkHours::account_updateBusinessWorkHours(int32 flags_, object_ptr<businessWorkHours> &&business_work_hours_)
  : flags_(flags_)
  , business_work_hours_(std::move(business_work_hours_))
{}

const std::int32_t account_updateBusinessWorkHours::ID;

void account_updateBusinessWorkHours::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1258348646);
  TlStoreBinary::store((var0 = flags_ | ((business_work_hours_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1936543592>::store(business_work_hours_, s); }
}

void account_updateBusinessWorkHours::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1258348646);
  TlStoreBinary::store((var0 = flags_ | ((business_work_hours_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1936543592>::store(business_work_hours_, s); }
}

void account_updateBusinessWorkHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBusinessWorkHours");
    s.store_field("flags", (var0 = flags_ | ((business_work_hours_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("business_work_hours", static_cast<const BaseObject *>(business_work_hours_.get())); }
    s.store_class_end();
  }
}

account_updateBusinessWorkHours::ReturnType account_updateBusinessWorkHours::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateColor::account_updateColor(int32 flags_, bool for_profile_, object_ptr<PeerColor> &&color_)
  : flags_(flags_)
  , for_profile_(for_profile_)
  , color_(std::move(color_))
{}

const std::int32_t account_updateColor::ID;

void account_updateColor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1749885262);
  TlStoreBinary::store((var0 = flags_ | (for_profile_ << 1) | ((color_ != nullptr) << 2)), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(color_, s); }
}

void account_updateColor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1749885262);
  TlStoreBinary::store((var0 = flags_ | (for_profile_ << 1) | ((color_ != nullptr) << 2)), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(color_, s); }
}

void account_updateColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateColor");
    s.store_field("flags", (var0 = flags_ | (for_profile_ << 1) | ((color_ != nullptr) << 2)));
    if (var0 & 2) { s.store_field("for_profile", true); }
    if (var0 & 4) { s.store_object_field("color", static_cast<const BaseObject *>(color_.get())); }
    s.store_class_end();
  }
}

account_updateColor::ReturnType account_updateColor::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updatePersonalChannel::account_updatePersonalChannel(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t account_updatePersonalChannel::ID;

void account_updatePersonalChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-649919008);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void account_updatePersonalChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-649919008);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void account_updatePersonalChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updatePersonalChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

account_updatePersonalChannel::ReturnType account_updatePersonalChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_verifyPhone::account_verifyPhone(string const &phone_number_, string const &phone_code_hash_, string const &phone_code_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , phone_code_(phone_code_)
{}

const std::int32_t account_verifyPhone::ID;

void account_verifyPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1305716726);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_verifyPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1305716726);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_verifyPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.verifyPhone");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("phone_code", "[REDACTED]");
    s.store_class_end();
  }
}

account_verifyPhone::ReturnType account_verifyPhone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_exportAuthorization::auth_exportAuthorization(int32 dc_id_)
  : dc_id_(dc_id_)
{}

const std::int32_t auth_exportAuthorization::ID;

void auth_exportAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-440401971);
  TlStoreBinary::store(dc_id_, s);
}

void auth_exportAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-440401971);
  TlStoreBinary::store(dc_id_, s);
}

void auth_exportAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.exportAuthorization");
    s.store_field("dc_id", dc_id_);
    s.store_class_end();
  }
}

auth_exportAuthorization::ReturnType auth_exportAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<auth_exportedAuthorization>, -1271602504>::parse(p);
#undef FAIL
}

auth_initPasskeyLogin::auth_initPasskeyLogin(int32 api_id_, string const &api_hash_)
  : api_id_(api_id_)
  , api_hash_(api_hash_)
{}

const std::int32_t auth_initPasskeyLogin::ID;

void auth_initPasskeyLogin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1368051895);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
}

void auth_initPasskeyLogin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1368051895);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
}

void auth_initPasskeyLogin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.initPasskeyLogin");
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", "[REDACTED]");
    s.store_class_end();
  }
}

auth_initPasskeyLogin::ReturnType auth_initPasskeyLogin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<auth_passkeyLoginOptions>, -503089271>::parse(p);
#undef FAIL
}

auth_resendCode::auth_resendCode(int32 flags_, string const &phone_number_, string const &phone_code_hash_, string const &reason_)
  : flags_(flags_)
  , phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , reason_(reason_)
{}

const std::int32_t auth_resendCode::ID;

void auth_resendCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-890997469);
  TlStoreBinary::store((var0 = flags_ | ((!reason_.empty()) << 0)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(reason_, s); }
}

void auth_resendCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-890997469);
  TlStoreBinary::store((var0 = flags_ | ((!reason_.empty()) << 0)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(reason_, s); }
}

void auth_resendCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.resendCode");
    s.store_field("flags", (var0 = flags_ | ((!reason_.empty()) << 0)));
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    if (var0 & 1) { s.store_field("reason", reason_); }
    s.store_class_end();
  }
}

auth_resendCode::ReturnType auth_resendCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

auth_resetLoginEmail::auth_resetLoginEmail(string const &phone_number_, string const &phone_code_hash_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
{}

const std::int32_t auth_resetLoginEmail::ID;

void auth_resetLoginEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2123760019);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void auth_resetLoginEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2123760019);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void auth_resetLoginEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.resetLoginEmail");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_class_end();
  }
}

auth_resetLoginEmail::ReturnType auth_resetLoginEmail::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

bots_addUsername::bots_addUsername(object_ptr<InputUser> &&bot_, string const &username_)
  : bot_(std::move(bot_))
  , username_(username_)
{}

const std::int32_t bots_addUsername::ID;

void bots_addUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(889307274);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(username_, s);
}

void bots_addUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(889307274);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(username_, s);
}

void bots_addUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.addUsername");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("username", username_);
    s.store_class_end();
  }
}

bots_addUsername::ReturnType bots_addUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_canSendMessage::bots_canSendMessage(object_ptr<InputUser> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t bots_canSendMessage::ID;

void bots_canSendMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(324662502);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_canSendMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(324662502);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_canSendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.canSendMessage");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

bots_canSendMessage::ReturnType bots_canSendMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_getBotCommands::bots_getBotCommands(object_ptr<BotCommandScope> &&scope_, string const &lang_code_)
  : scope_(std::move(scope_))
  , lang_code_(lang_code_)
{}

const std::int32_t bots_getBotCommands::ID;

void bots_getBotCommands::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-481554986);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_getBotCommands::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-481554986);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_getBotCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getBotCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

bots_getBotCommands::ReturnType bots_getBotCommands::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botCommand>, -1739401518>>, 481674261>::parse(p);
#undef FAIL
}

bots_getRequestedWebViewButton::bots_getRequestedWebViewButton(object_ptr<InputUser> &&bot_, string const &webapp_req_id_)
  : bot_(std::move(bot_))
  , webapp_req_id_(webapp_req_id_)
{}

const std::int32_t bots_getRequestedWebViewButton::ID;

void bots_getRequestedWebViewButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1088047117);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(webapp_req_id_, s);
}

void bots_getRequestedWebViewButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1088047117);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(webapp_req_id_, s);
}

void bots_getRequestedWebViewButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getRequestedWebViewButton");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("webapp_req_id", webapp_req_id_);
    s.store_class_end();
  }
}

bots_getRequestedWebViewButton::ReturnType bots_getRequestedWebViewButton::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<keyboardButton>, 795322159>::parse(p);
#undef FAIL
}

bots_resetBotCommands::bots_resetBotCommands(object_ptr<BotCommandScope> &&scope_, string const &lang_code_)
  : scope_(std::move(scope_))
  , lang_code_(lang_code_)
{}

const std::int32_t bots_resetBotCommands::ID;

void bots_resetBotCommands::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1032708345);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_resetBotCommands::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1032708345);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_resetBotCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.resetBotCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

bots_resetBotCommands::ReturnType bots_resetBotCommands::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_createChannel::channels_createChannel(int32 flags_, bool broadcast_, bool megagroup_, bool for_import_, bool forum_, string const &title_, string const &about_, object_ptr<InputGeoPoint> &&geo_point_, string const &address_, int32 ttl_period_)
  : flags_(flags_)
  , broadcast_(broadcast_)
  , megagroup_(megagroup_)
  , for_import_(for_import_)
  , forum_(forum_)
  , title_(title_)
  , about_(about_)
  , geo_point_(std::move(geo_point_))
  , address_(address_)
  , ttl_period_(ttl_period_)
{}

const std::int32_t channels_createChannel::ID;

void channels_createChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1862244601);
  TlStoreBinary::store((var0 = flags_ | (broadcast_ << 0) | (megagroup_ << 1) | (for_import_ << 3) | (forum_ << 5) | ((geo_point_ != nullptr) << 2) | ((!address_.empty()) << 2)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(about_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  if (var0 & 4) { TlStoreString::store(address_, s); }
  if (var0 & 16) { TlStoreBinary::store(ttl_period_, s); }
}

void channels_createChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1862244601);
  TlStoreBinary::store((var0 = flags_ | (broadcast_ << 0) | (megagroup_ << 1) | (for_import_ << 3) | (forum_ << 5) | ((geo_point_ != nullptr) << 2) | ((!address_.empty()) << 2)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(about_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  if (var0 & 4) { TlStoreString::store(address_, s); }
  if (var0 & 16) { TlStoreBinary::store(ttl_period_, s); }
}

void channels_createChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.createChannel");
    s.store_field("flags", (var0 = flags_ | (broadcast_ << 0) | (megagroup_ << 1) | (for_import_ << 3) | (forum_ << 5) | ((geo_point_ != nullptr) << 2) | ((!address_.empty()) << 2)));
    if (var0 & 1) { s.store_field("broadcast", true); }
    if (var0 & 2) { s.store_field("megagroup", true); }
    if (var0 & 8) { s.store_field("for_import", true); }
    if (var0 & 32) { s.store_field("forum", true); }
    s.store_field("title", title_);
    s.store_field("about", about_);
    if (var0 & 4) { s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get())); }
    if (var0 & 4) { s.store_field("address", address_); }
    if (var0 & 16) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

channels_createChannel::ReturnType channels_createChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_editAdmin::channels_editAdmin(int32 flags_, object_ptr<InputChannel> &&channel_, object_ptr<InputUser> &&user_id_, object_ptr<chatAdminRights> &&admin_rights_, string const &rank_)
  : flags_(flags_)
  , channel_(std::move(channel_))
  , user_id_(std::move(user_id_))
  , admin_rights_(std::move(admin_rights_))
  , rank_(rank_)
{}

const std::int32_t channels_editAdmin::ID;

void channels_editAdmin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1701270168);
  TlStoreBinary::store((var0 = flags_ | ((!rank_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
  if (var0 & 1) { TlStoreString::store(rank_, s); }
}

void channels_editAdmin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1701270168);
  TlStoreBinary::store((var0 = flags_ | ((!rank_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
  if (var0 & 1) { TlStoreString::store(rank_, s); }
}

void channels_editAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.editAdmin");
    s.store_field("flags", (var0 = flags_ | ((!rank_.empty()) << 0)));
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get()));
    if (var0 & 1) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

channels_editAdmin::ReturnType channels_editAdmin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_inviteToChannel::channels_inviteToChannel(object_ptr<InputChannel> &&channel_, array<object_ptr<InputUser>> &&users_)
  : channel_(std::move(channel_))
  , users_(std::move(users_))
{}

const std::int32_t channels_inviteToChannel::ID;

void channels_inviteToChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-907854508);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void channels_inviteToChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-907854508);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void channels_inviteToChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.inviteToChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_inviteToChannel::ReturnType channels_inviteToChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_invitedUsers>, 2136862630>::parse(p);
#undef FAIL
}

channels_leaveChannel::channels_leaveChannel(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_leaveChannel::ID;

void channels_leaveChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-130635115);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_leaveChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-130635115);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_leaveChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.leaveChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_leaveChannel::ReturnType channels_leaveChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

chatlists_editExportedInvite::chatlists_editExportedInvite(int32 flags_, object_ptr<inputChatlistDialogFilter> &&chatlist_, string const &slug_, string const &title_, array<object_ptr<InputPeer>> &&peers_)
  : flags_(flags_)
  , chatlist_(std::move(chatlist_))
  , slug_(slug_)
  , title_(title_)
  , peers_(std::move(peers_))
{}

const std::int32_t chatlists_editExportedInvite::ID;

void chatlists_editExportedInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1698543165);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 1) | ((!peers_.empty()) << 2)), s);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(slug_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s); }
}

void chatlists_editExportedInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1698543165);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 1) | ((!peers_.empty()) << 2)), s);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(slug_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s); }
}

void chatlists_editExportedInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.editExportedInvite");
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 1) | ((!peers_.empty()) << 2)));
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_field("slug", slug_);
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 4) { { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

chatlists_editExportedInvite::ReturnType chatlists_editExportedInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<exportedChatlistInvite>, 206668204>::parse(p);
#undef FAIL
}

chatlists_leaveChatlist::chatlists_leaveChatlist(object_ptr<inputChatlistDialogFilter> &&chatlist_, array<object_ptr<InputPeer>> &&peers_)
  : chatlist_(std::move(chatlist_))
  , peers_(std::move(peers_))
{}

const std::int32_t chatlists_leaveChatlist::ID;

void chatlists_leaveChatlist::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1962598714);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_leaveChatlist::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1962598714);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_leaveChatlist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.leaveChatlist");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatlists_leaveChatlist::ReturnType chatlists_leaveChatlist::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

contacts_addContact::contacts_addContact(int32 flags_, bool add_phone_privacy_exception_, object_ptr<InputUser> &&id_, string const &first_name_, string const &last_name_, string const &phone_, object_ptr<textWithEntities> &&note_)
  : flags_(flags_)
  , add_phone_privacy_exception_(add_phone_privacy_exception_)
  , id_(std::move(id_))
  , first_name_(first_name_)
  , last_name_(last_name_)
  , phone_(phone_)
  , note_(std::move(note_))
{}

const std::int32_t contacts_addContact::ID;

void contacts_addContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-642109868);
  TlStoreBinary::store((var0 = flags_ | (add_phone_privacy_exception_ << 0) | ((note_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(phone_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s); }
}

void contacts_addContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-642109868);
  TlStoreBinary::store((var0 = flags_ | (add_phone_privacy_exception_ << 0) | ((note_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(phone_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s); }
}

void contacts_addContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.addContact");
    s.store_field("flags", (var0 = flags_ | (add_phone_privacy_exception_ << 0) | ((note_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("add_phone_privacy_exception", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("phone", phone_);
    if (var0 & 2) { s.store_object_field("note", static_cast<const BaseObject *>(note_.get())); }
    s.store_class_end();
  }
}

contacts_addContact::ReturnType contacts_addContact::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

contacts_block::contacts_block(int32 flags_, bool my_stories_from_, object_ptr<InputPeer> &&id_)
  : flags_(flags_)
  , my_stories_from_(my_stories_from_)
  , id_(std::move(id_))
{}

const std::int32_t contacts_block::ID;

void contacts_block::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(774801204);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_block::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(774801204);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_block::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.block");
    s.store_field("flags", (var0 = flags_ | (my_stories_from_ << 0)));
    if (var0 & 1) { s.store_field("my_stories_from", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

contacts_block::ReturnType contacts_block::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

contacts_importNoPaidMessagesToken::contacts_importNoPaidMessagesToken(object_ptr<InputUser> &&user_id_, string const &token_)
  : user_id_(std::move(user_id_))
  , token_(token_)
{}

const std::int32_t contacts_importNoPaidMessagesToken::ID;

void contacts_importNoPaidMessagesToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(900187850);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(token_, s);
}

void contacts_importNoPaidMessagesToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(900187850);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(token_, s);
}

void contacts_importNoPaidMessagesToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.importNoPaidMessagesToken");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

contacts_importNoPaidMessagesToken::ReturnType contacts_importNoPaidMessagesToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

const std::int32_t contacts_resetSaved::ID;

void contacts_resetSaved::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2020263951);
}

void contacts_resetSaved::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2020263951);
}

void contacts_resetSaved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.resetSaved");
    s.store_class_end();
  }
}

contacts_resetSaved::ReturnType contacts_resetSaved::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

folders_editPeerFolders::folders_editPeerFolders(array<object_ptr<inputFolderPeer>> &&folder_peers_)
  : folder_peers_(std::move(folder_peers_))
{}

const std::int32_t folders_editPeerFolders::ID;

void folders_editPeerFolders::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1749536939);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -70073706>>, 481674261>::store(folder_peers_, s);
}

void folders_editPeerFolders::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1749536939);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -70073706>>, 481674261>::store(folder_peers_, s);
}

void folders_editPeerFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "folders.editPeerFolders");
    { s.store_vector_begin("folder_peers", folder_peers_.size()); for (const auto &_value : folder_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

folders_editPeerFolders::ReturnType folders_editPeerFolders::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t help_getConfig::ID;

void help_getConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-990308245);
}

void help_getConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-990308245);
}

void help_getConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getConfig");
    s.store_class_end();
  }
}

help_getConfig::ReturnType help_getConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<config>, -870702050>::parse(p);
#undef FAIL
}

const std::int32_t help_getInviteText::ID;

void help_getInviteText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1295590211);
}

void help_getInviteText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1295590211);
}

void help_getInviteText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getInviteText");
    s.store_class_end();
  }
}

help_getInviteText::ReturnType help_getInviteText::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_inviteText>, 415997816>::parse(p);
#undef FAIL
}

const std::int32_t help_getNearestDc::ID;

void help_getNearestDc::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(531836966);
}

void help_getNearestDc::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(531836966);
}

void help_getNearestDc::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getNearestDc");
    s.store_class_end();
  }
}

help_getNearestDc::ReturnType help_getNearestDc::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<nearestDc>, -1910892683>::parse(p);
#undef FAIL
}

help_getRecentMeUrls::help_getRecentMeUrls(string const &referer_)
  : referer_(referer_)
{}

const std::int32_t help_getRecentMeUrls::ID;

void help_getRecentMeUrls::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1036054804);
  TlStoreString::store(referer_, s);
}

void help_getRecentMeUrls::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1036054804);
  TlStoreString::store(referer_, s);
}

void help_getRecentMeUrls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getRecentMeUrls");
    s.store_field("referer", referer_);
    s.store_class_end();
  }
}

help_getRecentMeUrls::ReturnType help_getRecentMeUrls::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_recentMeUrls>, 235081943>::parse(p);
#undef FAIL
}

help_saveAppLog::help_saveAppLog(array<object_ptr<inputAppEvent>> &&events_)
  : events_(std::move(events_))
{}

const std::int32_t help_saveAppLog::ID;

void help_saveAppLog::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1862465352);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 488313413>>, 481674261>::store(events_, s);
}

void help_saveAppLog::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1862465352);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 488313413>>, 481674261>::store(events_, s);
}

void help_saveAppLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.saveAppLog");
    { s.store_vector_begin("events", events_.size()); for (const auto &_value : events_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

help_saveAppLog::ReturnType help_saveAppLog::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_checkQuickReplyShortcut::messages_checkQuickReplyShortcut(string const &shortcut_)
  : shortcut_(shortcut_)
{}

const std::int32_t messages_checkQuickReplyShortcut::ID;

void messages_checkQuickReplyShortcut::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-237962285);
  TlStoreString::store(shortcut_, s);
}

void messages_checkQuickReplyShortcut::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-237962285);
  TlStoreString::store(shortcut_, s);
}

void messages_checkQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkQuickReplyShortcut");
    s.store_field("shortcut", shortcut_);
    s.store_class_end();
  }
}

messages_checkQuickReplyShortcut::ReturnType messages_checkQuickReplyShortcut::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_createChat::messages_createChat(int32 flags_, array<object_ptr<InputUser>> &&users_, string const &title_, int32 ttl_period_)
  : flags_(flags_)
  , users_(std::move(users_))
  , title_(title_)
  , ttl_period_(ttl_period_)
{}

const std::int32_t messages_createChat::ID;

void messages_createChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1831936556);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
  TlStoreString::store(title_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_period_, s); }
}

void messages_createChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1831936556);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
  TlStoreString::store(title_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_period_, s); }
}

void messages_createChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.createChat");
    s.store_field("flags", (var0 = flags_));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("title", title_);
    if (var0 & 1) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

messages_createChat::ReturnType messages_createChat::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_invitedUsers>, 2136862630>::parse(p);
#undef FAIL
}

const std::int32_t messages_getAllDrafts::ID;

void messages_getAllDrafts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1782549861);
}

void messages_getAllDrafts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1782549861);
}

void messages_getAllDrafts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAllDrafts");
    s.store_class_end();
  }
}

messages_getAllDrafts::ReturnType messages_getAllDrafts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getAvailableReactions::messages_getAvailableReactions(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getAvailableReactions::ID;

void messages_getAvailableReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(417243308);
  TlStoreBinary::store(hash_, s);
}

void messages_getAvailableReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(417243308);
  TlStoreBinary::store(hash_, s);
}

void messages_getAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAvailableReactions");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getAvailableReactions::ReturnType messages_getAvailableReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_AvailableReactions>::parse(p);
#undef FAIL
}

const std::int32_t messages_getDialogFilters::ID;

void messages_getDialogFilters::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-271283063);
}

void messages_getDialogFilters::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-271283063);
}

void messages_getDialogFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDialogFilters");
    s.store_class_end();
  }
}

messages_getDialogFilters::ReturnType messages_getDialogFilters::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_dialogFilters>, 718878489>::parse(p);
#undef FAIL
}

messages_getEmojiGroups::messages_getEmojiGroups(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getEmojiGroups::ID;

void messages_getEmojiGroups::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1955122779);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiGroups::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1955122779);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiGroups");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getEmojiGroups::ReturnType messages_getEmojiGroups::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_EmojiGroups>::parse(p);
#undef FAIL
}

messages_getFullChat::messages_getFullChat(int64 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t messages_getFullChat::ID;

void messages_getFullChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1364194508);
  TlStoreBinary::store(chat_id_, s);
}

void messages_getFullChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1364194508);
  TlStoreBinary::store(chat_id_, s);
}

void messages_getFullChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFullChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

messages_getFullChat::ReturnType messages_getFullChat::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_chatFull>, -438840932>::parse(p);
#undef FAIL
}

messages_getMessageReactionsList::messages_getMessageReactionsList(int32 flags_, object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<Reaction> &&reaction_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , reaction_(std::move(reaction_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t messages_getMessageReactionsList::ID;

void messages_getMessageReactionsList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1176190792);
  TlStoreBinary::store((var0 = flags_ | ((reaction_ != nullptr) << 0) | ((!offset_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getMessageReactionsList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1176190792);
  TlStoreBinary::store((var0 = flags_ | ((reaction_ != nullptr) << 0) | ((!offset_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getMessageReactionsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessageReactionsList");
    s.store_field("flags", (var0 = flags_ | ((reaction_ != nullptr) << 0) | ((!offset_.empty()) << 1)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get())); }
    if (var0 & 2) { s.store_field("offset", offset_); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getMessageReactionsList::ReturnType messages_getMessageReactionsList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_messageReactionsList>, 834488621>::parse(p);
#undef FAIL
}

messages_getOnlines::messages_getOnlines(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_getOnlines::ID;

void messages_getOnlines::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1848369232);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getOnlines::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1848369232);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getOnlines::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getOnlines");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_getOnlines::ReturnType messages_getOnlines::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<chatOnlines>, -264117680>::parse(p);
#undef FAIL
}

messages_getPinnedDialogs::messages_getPinnedDialogs(int32 folder_id_)
  : folder_id_(folder_id_)
{}

const std::int32_t messages_getPinnedDialogs::ID;

void messages_getPinnedDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-692498958);
  TlStoreBinary::store(folder_id_, s);
}

void messages_getPinnedDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-692498958);
  TlStoreBinary::store(folder_id_, s);
}

void messages_getPinnedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPinnedDialogs");
    s.store_field("folder_id", folder_id_);
    s.store_class_end();
  }
}

messages_getPinnedDialogs::ReturnType messages_getPinnedDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_peerDialogs>, -1488325659>::parse(p);
#undef FAIL
}

messages_getPollResults::messages_getPollResults(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 poll_hash_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , poll_hash_(poll_hash_)
{}

const std::int32_t messages_getPollResults::ID;

void messages_getPollResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-308026565);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(poll_hash_, s);
}

void messages_getPollResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-308026565);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(poll_hash_, s);
}

void messages_getPollResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPollResults");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("poll_hash", poll_hash_);
    s.store_class_end();
  }
}

messages_getPollResults::ReturnType messages_getPollResults::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getPollVotes::messages_getPollVotes(int32 flags_, object_ptr<InputPeer> &&peer_, int32 id_, bytes &&option_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , option_(std::move(option_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t messages_getPollVotes::ID;

void messages_getPollVotes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1200736242);
  TlStoreBinary::store((var0 = flags_ | ((!option_.empty()) << 0) | ((!offset_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(option_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getPollVotes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1200736242);
  TlStoreBinary::store((var0 = flags_ | ((!option_.empty()) << 0) | ((!offset_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(option_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getPollVotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPollVotes");
    s.store_field("flags", (var0 = flags_ | ((!option_.empty()) << 0) | ((!offset_.empty()) << 1)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_bytes_field("option", option_); }
    if (var0 & 2) { s.store_field("offset", offset_); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getPollVotes::ReturnType messages_getPollVotes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_votesList>, 1218005070>::parse(p);
#undef FAIL
}

messages_getTopReactions::messages_getTopReactions(int32 limit_, int64 hash_)
  : limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getTopReactions::ID;

void messages_getTopReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1149164102);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getTopReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1149164102);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getTopReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getTopReactions");
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getTopReactions::ReturnType messages_getTopReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Reactions>::parse(p);
#undef FAIL
}

messages_getWebPage::messages_getWebPage(string const &url_, int32 hash_)
  : url_(url_)
  , hash_(hash_)
{}

const std::int32_t messages_getWebPage::ID;

void messages_getWebPage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1919511901);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getWebPage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1919511901);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getWebPage");
    s.store_field("url", url_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getWebPage::ReturnType messages_getWebPage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_webPage>, -44166467>::parse(p);
#undef FAIL
}

messages_markDialogUnread::messages_markDialogUnread(int32 flags_, bool unread_, object_ptr<InputPeer> &&parent_peer_, object_ptr<InputDialogPeer> &&peer_)
  : flags_(flags_)
  , unread_(unread_)
  , parent_peer_(std::move(parent_peer_))
  , peer_(std::move(peer_))
{}

const std::int32_t messages_markDialogUnread::ID;

void messages_markDialogUnread::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1940912392);
  TlStoreBinary::store((var0 = flags_ | (unread_ << 0) | ((parent_peer_ != nullptr) << 1)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_markDialogUnread::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1940912392);
  TlStoreBinary::store((var0 = flags_ | (unread_ << 0) | ((parent_peer_ != nullptr) << 1)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_markDialogUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.markDialogUnread");
    s.store_field("flags", (var0 = flags_ | (unread_ << 0) | ((parent_peer_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("unread", true); }
    if (var0 & 2) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_markDialogUnread::ReturnType messages_markDialogUnread::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_readEncryptedHistory::messages_readEncryptedHistory(object_ptr<inputEncryptedChat> &&peer_, int32 max_date_)
  : peer_(std::move(peer_))
  , max_date_(max_date_)
{}

const std::int32_t messages_readEncryptedHistory::ID;

void messages_readEncryptedHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2135648522);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(max_date_, s);
}

void messages_readEncryptedHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2135648522);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(max_date_, s);
}

void messages_readEncryptedHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readEncryptedHistory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_date", max_date_);
    s.store_class_end();
  }
}

messages_readEncryptedHistory::ReturnType messages_readEncryptedHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_readPollVotes::messages_readPollVotes(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
{}

const std::int32_t messages_readPollVotes::ID;

void messages_readPollVotes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(388019416);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
}

void messages_readPollVotes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(388019416);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
}

void messages_readPollVotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readPollVotes");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_class_end();
  }
}

messages_readPollVotes::ReturnType messages_readPollVotes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_reportReaction::messages_reportReaction(object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<InputPeer> &&reaction_peer_)
  : peer_(std::move(peer_))
  , id_(id_)
  , reaction_peer_(std::move(reaction_peer_))
{}

const std::int32_t messages_reportReaction::ID;

void messages_reportReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1063567478);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_peer_, s);
}

void messages_reportReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1063567478);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_peer_, s);
}

void messages_reportReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportReaction");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_object_field("reaction_peer", static_cast<const BaseObject *>(reaction_peer_.get()));
    s.store_class_end();
  }
}

messages_reportReaction::ReturnType messages_reportReaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_reportSpam::messages_reportSpam(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_reportSpam::ID;

void messages_reportSpam::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-820669733);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_reportSpam::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-820669733);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_reportSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportSpam");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_reportSpam::ReturnType messages_reportSpam::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_requestEncryption::messages_requestEncryption(object_ptr<InputUser> &&user_id_, int32 random_id_, bytes &&g_a_)
  : user_id_(std::move(user_id_))
  , random_id_(random_id_)
  , g_a_(std::move(g_a_))
{}

const std::int32_t messages_requestEncryption::ID;

void messages_requestEncryption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-162681021);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(g_a_, s);
}

void messages_requestEncryption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-162681021);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(g_a_, s);
}

void messages_requestEncryption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestEncryption");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("random_id", random_id_);
    s.store_bytes_field("g_a", g_a_);
    s.store_class_end();
  }
}

messages_requestEncryption::ReturnType messages_requestEncryption::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EncryptedChat>::parse(p);
#undef FAIL
}

messages_saveDefaultSendAs::messages_saveDefaultSendAs(object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&send_as_)
  : peer_(std::move(peer_))
  , send_as_(std::move(send_as_))
{}

const std::int32_t messages_saveDefaultSendAs::ID;

void messages_saveDefaultSendAs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-855777386);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s);
}

void messages_saveDefaultSendAs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-855777386);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s);
}

void messages_saveDefaultSendAs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.saveDefaultSendAs");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get()));
    s.store_class_end();
  }
}

messages_saveDefaultSendAs::ReturnType messages_saveDefaultSendAs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_sendScreenshotNotification::messages_sendScreenshotNotification(object_ptr<InputPeer> &&peer_, object_ptr<InputReplyTo> &&reply_to_, int64 random_id_)
  : peer_(std::move(peer_))
  , reply_to_(std::move(reply_to_))
  , random_id_(random_id_)
{}

const std::int32_t messages_sendScreenshotNotification::ID;

void messages_sendScreenshotNotification::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1589618665);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s);
  TlStoreBinary::store(random_id_, s);
}

void messages_sendScreenshotNotification::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1589618665);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s);
  TlStoreBinary::store(random_id_, s);
}

void messages_sendScreenshotNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendScreenshotNotification");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_field("random_id", random_id_);
    s.store_class_end();
  }
}

messages_sendScreenshotNotification::ReturnType messages_sendScreenshotNotification::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setBotShippingResults::messages_setBotShippingResults(int32 flags_, int64 query_id_, string const &error_, array<object_ptr<shippingOption>> &&shipping_options_)
  : flags_(flags_)
  , query_id_(query_id_)
  , error_(error_)
  , shipping_options_(std::move(shipping_options_))
{}

const std::int32_t messages_setBotShippingResults::ID;

void messages_setBotShippingResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-436833542);
  TlStoreBinary::store((var0 = flags_ | ((!error_.empty()) << 0) | ((!shipping_options_.empty()) << 1)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1239335713>>, 481674261>::store(shipping_options_, s); }
}

void messages_setBotShippingResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-436833542);
  TlStoreBinary::store((var0 = flags_ | ((!error_.empty()) << 0) | ((!shipping_options_.empty()) << 1)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1239335713>>, 481674261>::store(shipping_options_, s); }
}

void messages_setBotShippingResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setBotShippingResults");
    s.store_field("flags", (var0 = flags_ | ((!error_.empty()) << 0) | ((!shipping_options_.empty()) << 1)));
    s.store_field("query_id", query_id_);
    if (var0 & 1) { s.store_field("error", error_); }
    if (var0 & 2) { { s.store_vector_begin("shipping_options", shipping_options_.size()); for (const auto &_value : shipping_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messages_setBotShippingResults::ReturnType messages_setBotShippingResults::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_unpinAllMessages::messages_unpinAllMessages(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, object_ptr<InputPeer> &&saved_peer_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , saved_peer_id_(std::move(saved_peer_id_))
{}

const std::int32_t messages_unpinAllMessages::ID;

void messages_unpinAllMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(103667527);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
}

void messages_unpinAllMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(103667527);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
}

void messages_unpinAllMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.unpinAllMessages");
    s.store_field("flags", (var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_class_end();
  }
}

messages_unpinAllMessages::ReturnType messages_unpinAllMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_updateDialogFiltersOrder::messages_updateDialogFiltersOrder(array<int32> &&order_)
  : order_(std::move(order_))
{}

const std::int32_t messages_updateDialogFiltersOrder::ID;

void messages_updateDialogFiltersOrder::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-983318044);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_updateDialogFiltersOrder::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-983318044);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_updateDialogFiltersOrder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.updateDialogFiltersOrder");
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_updateDialogFiltersOrder::ReturnType messages_updateDialogFiltersOrder::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_updatePinnedMessage::messages_updatePinnedMessage(int32 flags_, bool silent_, bool unpin_, bool pm_oneside_, object_ptr<InputPeer> &&peer_, int32 id_)
  : flags_(flags_)
  , silent_(silent_)
  , unpin_(unpin_)
  , pm_oneside_(pm_oneside_)
  , peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t messages_updatePinnedMessage::ID;

void messages_updatePinnedMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-760547348);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0) | (unpin_ << 1) | (pm_oneside_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void messages_updatePinnedMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-760547348);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0) | (unpin_ << 1) | (pm_oneside_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void messages_updatePinnedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.updatePinnedMessage");
    s.store_field("flags", (var0 = flags_ | (silent_ << 0) | (unpin_ << 1) | (pm_oneside_ << 2)));
    if (var0 & 1) { s.store_field("silent", true); }
    if (var0 & 2) { s.store_field("unpin", true); }
    if (var0 & 4) { s.store_field("pm_oneside", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

messages_updatePinnedMessage::ReturnType messages_updatePinnedMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_botCancelStarsSubscription::payments_botCancelStarsSubscription(int32 flags_, bool restore_, object_ptr<InputUser> &&user_id_, string const &charge_id_)
  : flags_(flags_)
  , restore_(restore_)
  , user_id_(std::move(user_id_))
  , charge_id_(charge_id_)
{}

const std::int32_t payments_botCancelStarsSubscription::ID;

void payments_botCancelStarsSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1845102114);
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(charge_id_, s);
}

void payments_botCancelStarsSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1845102114);
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(charge_id_, s);
}

void payments_botCancelStarsSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.botCancelStarsSubscription");
    s.store_field("flags", (var0 = flags_ | (restore_ << 0)));
    if (var0 & 1) { s.store_field("restore", true); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("charge_id", charge_id_);
    s.store_class_end();
  }
}

payments_botCancelStarsSubscription::ReturnType payments_botCancelStarsSubscription::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_depositStarGift::payments_depositStarGift(int32 flags_, bool hide_sender_, object_ptr<InputPeer> &&peer_, string const &slug_)
  : flags_(flags_)
  , hide_sender_(hide_sender_)
  , peer_(std::move(peer_))
  , slug_(slug_)
{}

const std::int32_t payments_depositStarGift::ID;

void payments_depositStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1063064929);
  TlStoreBinary::store((var0 = flags_ | (hide_sender_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(slug_, s);
}

void payments_depositStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1063064929);
  TlStoreBinary::store((var0 = flags_ | (hide_sender_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(slug_, s);
}

void payments_depositStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.depositStarGift");
    s.store_field("flags", (var0 = flags_ | (hide_sender_ << 0)));
    if (var0 & 1) { s.store_field("hide_sender", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

payments_depositStarGift::ReturnType payments_depositStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftDepositPayload>, 1918612715>::parse(p);
#undef FAIL
}

payments_getOnrampBaseCurrencies::payments_getOnrampBaseCurrencies(string const &provider_, string const &crypto_currency_)
  : provider_(provider_)
  , crypto_currency_(crypto_currency_)
{}

const std::int32_t payments_getOnrampBaseCurrencies::ID;

void payments_getOnrampBaseCurrencies::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(478932467);
  TlStoreString::store(provider_, s);
  TlStoreString::store(crypto_currency_, s);
}

void payments_getOnrampBaseCurrencies::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(478932467);
  TlStoreString::store(provider_, s);
  TlStoreString::store(crypto_currency_, s);
}

void payments_getOnrampBaseCurrencies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getOnrampBaseCurrencies");
    s.store_field("provider", provider_);
    s.store_field("crypto_currency", crypto_currency_);
    s.store_class_end();
  }
}

payments_getOnrampBaseCurrencies::ReturnType payments_getOnrampBaseCurrencies::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p);
#undef FAIL
}

payments_getResaleStarGifts::payments_getResaleStarGifts(int32 flags_, bool sort_by_price_, bool sort_by_num_, bool for_craft_, bool stars_only_, bool ton_only_, bool fragment_only_, int64 attributes_hash_, int64 gift_id_, array<object_ptr<StarGiftAttributeId>> &&attributes_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , sort_by_price_(sort_by_price_)
  , sort_by_num_(sort_by_num_)
  , for_craft_(for_craft_)
  , stars_only_(stars_only_)
  , ton_only_(ton_only_)
  , fragment_only_(fragment_only_)
  , attributes_hash_(attributes_hash_)
  , gift_id_(gift_id_)
  , attributes_(std::move(attributes_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t payments_getResaleStarGifts::ID;

void payments_getResaleStarGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2053087798);
  TlStoreBinary::store((var0 = flags_ | (sort_by_price_ << 1) | (sort_by_num_ << 2) | (for_craft_ << 4) | (stars_only_ << 5) | (ton_only_ << 6) | (fragment_only_ << 7) | ((!attributes_.empty()) << 3)), s);
  if (var0 & 1) { TlStoreBinary::store(attributes_hash_, s); }
  TlStoreBinary::store(gift_id_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getResaleStarGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2053087798);
  TlStoreBinary::store((var0 = flags_ | (sort_by_price_ << 1) | (sort_by_num_ << 2) | (for_craft_ << 4) | (stars_only_ << 5) | (ton_only_ << 6) | (fragment_only_ << 7) | ((!attributes_.empty()) << 3)), s);
  if (var0 & 1) { TlStoreBinary::store(attributes_hash_, s); }
  TlStoreBinary::store(gift_id_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getResaleStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getResaleStarGifts");
    s.store_field("flags", (var0 = flags_ | (sort_by_price_ << 1) | (sort_by_num_ << 2) | (for_craft_ << 4) | (stars_only_ << 5) | (ton_only_ << 6) | (fragment_only_ << 7) | ((!attributes_.empty()) << 3)));
    if (var0 & 2) { s.store_field("sort_by_price", true); }
    if (var0 & 4) { s.store_field("sort_by_num", true); }
    if (var0 & 16) { s.store_field("for_craft", true); }
    if (var0 & 32) { s.store_field("stars_only", true); }
    if (var0 & 64) { s.store_field("ton_only", true); }
    if (var0 & 128) { s.store_field("fragment_only", true); }
    if (var0 & 1) { s.store_field("attributes_hash", attributes_hash_); }
    s.store_field("gift_id", gift_id_);
    if (var0 & 8) { { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getResaleStarGifts::ReturnType payments_getResaleStarGifts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_resaleStarGifts>, -1803939105>::parse(p);
#undef FAIL
}

payments_getStarGiftWithdrawalUrl::payments_getStarGiftWithdrawalUrl(int32 flags_, object_ptr<InputSavedStarGift> &&stargift_, bytes &&tmp_password_)
  : flags_(flags_)
  , stargift_(std::move(stargift_))
  , tmp_password_(std::move(tmp_password_))
{}

const std::int32_t payments_getStarGiftWithdrawalUrl::ID;

void payments_getStarGiftWithdrawalUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-926252677);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreString::store(tmp_password_, s);
}

void payments_getStarGiftWithdrawalUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-926252677);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreString::store(tmp_password_, s);
}

void payments_getStarGiftWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftWithdrawalUrl");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_field("tmp_password", "[REDACTED]");
    s.store_class_end();
  }
}

payments_getStarGiftWithdrawalUrl::ReturnType payments_getStarGiftWithdrawalUrl::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftWithdrawalUrl>, -2069218660>::parse(p);
#undef FAIL
}

payments_getSuggestedStarRefBots::payments_getSuggestedStarRefBots(int32 flags_, bool order_by_revenue_, bool order_by_date_, object_ptr<InputPeer> &&peer_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , order_by_revenue_(order_by_revenue_)
  , order_by_date_(order_by_date_)
  , peer_(std::move(peer_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t payments_getSuggestedStarRefBots::ID;

void payments_getSuggestedStarRefBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(225134839);
  TlStoreBinary::store((var0 = flags_ | (order_by_revenue_ << 0) | (order_by_date_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getSuggestedStarRefBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(225134839);
  TlStoreBinary::store((var0 = flags_ | (order_by_revenue_ << 0) | (order_by_date_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getSuggestedStarRefBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getSuggestedStarRefBots");
    s.store_field("flags", (var0 = flags_ | (order_by_revenue_ << 0) | (order_by_date_ << 1)));
    if (var0 & 1) { s.store_field("order_by_revenue", true); }
    if (var0 & 2) { s.store_field("order_by_date", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getSuggestedStarRefBots::ReturnType payments_getSuggestedStarRefBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_suggestedStarRefBots>, -1261053863>::parse(p);
#undef FAIL
}

payments_refundStarsCharge::payments_refundStarsCharge(object_ptr<InputUser> &&user_id_, string const &charge_id_)
  : user_id_(std::move(user_id_))
  , charge_id_(charge_id_)
{}

const std::int32_t payments_refundStarsCharge::ID;

void payments_refundStarsCharge::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(632196938);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(charge_id_, s);
}

void payments_refundStarsCharge::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(632196938);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(charge_id_, s);
}

void payments_refundStarsCharge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.refundStarsCharge");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("charge_id", charge_id_);
    s.store_class_end();
  }
}

payments_refundStarsCharge::ReturnType payments_refundStarsCharge::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_resolveStarGiftOffer::payments_resolveStarGiftOffer(int32 flags_, bool decline_, int32 offer_msg_id_)
  : flags_(flags_)
  , decline_(decline_)
  , offer_msg_id_(offer_msg_id_)
{}

const std::int32_t payments_resolveStarGiftOffer::ID;

void payments_resolveStarGiftOffer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-372344804);
  TlStoreBinary::store((var0 = flags_ | (decline_ << 0)), s);
  TlStoreBinary::store(offer_msg_id_, s);
}

void payments_resolveStarGiftOffer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-372344804);
  TlStoreBinary::store((var0 = flags_ | (decline_ << 0)), s);
  TlStoreBinary::store(offer_msg_id_, s);
}

void payments_resolveStarGiftOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.resolveStarGiftOffer");
    s.store_field("flags", (var0 = flags_ | (decline_ << 0)));
    if (var0 & 1) { s.store_field("decline", true); }
    s.store_field("offer_msg_id", offer_msg_id_);
    s.store_class_end();
  }
}

payments_resolveStarGiftOffer::ReturnType payments_resolveStarGiftOffer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_sendStarGiftOffer::payments_sendStarGiftOffer(int32 flags_, object_ptr<InputPeer> &&peer_, string const &slug_, object_ptr<StarsAmount> &&price_, int32 duration_, int64 random_id_, int64 allow_paid_stars_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , slug_(slug_)
  , price_(std::move(price_))
  , duration_(duration_)
  , random_id_(random_id_)
  , allow_paid_stars_(allow_paid_stars_)
{}

const std::int32_t payments_sendStarGiftOffer::ID;

void payments_sendStarGiftOffer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1883739327);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(price_, s);
  TlStoreBinary::store(duration_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void payments_sendStarGiftOffer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1883739327);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(price_, s);
  TlStoreBinary::store(duration_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void payments_sendStarGiftOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.sendStarGiftOffer");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("slug", slug_);
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("duration", duration_);
    s.store_field("random_id", random_id_);
    if (var0 & 1) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    s.store_class_end();
  }
}

payments_sendStarGiftOffer::ReturnType payments_sendStarGiftOffer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_sendStarsForm::payments_sendStarsForm(int64 form_id_, object_ptr<InputInvoice> &&invoice_)
  : form_id_(form_id_)
  , invoice_(std::move(invoice_))
{}

const std::int32_t payments_sendStarsForm::ID;

void payments_sendStarsForm::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2040056084);
  TlStoreBinary::store(form_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
}

void payments_sendStarsForm::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2040056084);
  TlStoreBinary::store(form_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
}

void payments_sendStarsForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.sendStarsForm");
    s.store_field("form_id", form_id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_class_end();
  }
}

payments_sendStarsForm::ReturnType payments_sendStarsForm::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_PaymentResult>::parse(p);
#undef FAIL
}

payments_validateRequestedInfo::payments_validateRequestedInfo(int32 flags_, bool save_, object_ptr<InputInvoice> &&invoice_, object_ptr<paymentRequestedInfo> &&info_)
  : flags_(flags_)
  , save_(save_)
  , invoice_(std::move(invoice_))
  , info_(std::move(info_))
{}

const std::int32_t payments_validateRequestedInfo::ID;

void payments_validateRequestedInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1228345045);
  TlStoreBinary::store((var0 = flags_ | (save_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  TlStoreBoxed<TlStoreObject, -1868808300>::store(info_, s);
}

void payments_validateRequestedInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1228345045);
  TlStoreBinary::store((var0 = flags_ | (save_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  TlStoreBoxed<TlStoreObject, -1868808300>::store(info_, s);
}

void payments_validateRequestedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.validateRequestedInfo");
    s.store_field("flags", (var0 = flags_ | (save_ << 0)));
    if (var0 & 1) { s.store_field("save", true); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

payments_validateRequestedInfo::ReturnType payments_validateRequestedInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_validatedRequestedInfo>, -784000893>::parse(p);
#undef FAIL
}

phone_createGroupCall::phone_createGroupCall(int32 flags_, bool rtmp_stream_, object_ptr<InputPeer> &&peer_, int32 random_id_, string const &title_, int32 schedule_date_)
  : flags_(flags_)
  , rtmp_stream_(rtmp_stream_)
  , peer_(std::move(peer_))
  , random_id_(random_id_)
  , title_(title_)
  , schedule_date_(schedule_date_)
{}

const std::int32_t phone_createGroupCall::ID;

void phone_createGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1221445336);
  TlStoreBinary::store((var0 = flags_ | (rtmp_stream_ << 2) | ((!title_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBinary::store(schedule_date_, s); }
}

void phone_createGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1221445336);
  TlStoreBinary::store((var0 = flags_ | (rtmp_stream_ << 2) | ((!title_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBinary::store(schedule_date_, s); }
}

void phone_createGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.createGroupCall");
    s.store_field("flags", (var0 = flags_ | (rtmp_stream_ << 2) | ((!title_.empty()) << 0)));
    if (var0 & 4) { s.store_field("rtmp_stream", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("random_id", random_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("schedule_date", schedule_date_); }
    s.store_class_end();
  }
}

phone_createGroupCall::ReturnType phone_createGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_inviteConferenceCallParticipant::phone_inviteConferenceCallParticipant(int32 flags_, bool video_, object_ptr<InputGroupCall> &&call_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , video_(video_)
  , call_(std::move(call_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t phone_inviteConferenceCallParticipant::ID;

void phone_inviteConferenceCallParticipant::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1124981115);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void phone_inviteConferenceCallParticipant::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1124981115);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void phone_inviteConferenceCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.inviteConferenceCallParticipant");
    s.store_field("flags", (var0 = flags_ | (video_ << 0)));
    if (var0 & 1) { s.store_field("video", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

phone_inviteConferenceCallParticipant::ReturnType phone_inviteConferenceCallParticipant::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

premium_getUserBoosts::premium_getUserBoosts(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&user_id_)
  : peer_(std::move(peer_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t premium_getUserBoosts::ID;

void premium_getUserBoosts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(965037343);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void premium_getUserBoosts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(965037343);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void premium_getUserBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.getUserBoosts");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

premium_getUserBoosts::ReturnType premium_getUserBoosts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<premium_boostsList>, -2030542532>::parse(p);
#undef FAIL
}

const std::int32_t smsjobs_join::ID;

void smsjobs_join::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1488007635);
}

void smsjobs_join::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1488007635);
}

void smsjobs_join::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.join");
    s.store_class_end();
  }
}

smsjobs_join::ReturnType smsjobs_join::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stickers_replaceSticker::stickers_replaceSticker(object_ptr<InputDocument> &&sticker_, object_ptr<inputStickerSetItem> &&new_sticker_)
  : sticker_(std::move(sticker_))
  , new_sticker_(std::move(new_sticker_))
{}

const std::int32_t stickers_replaceSticker::ID;

void stickers_replaceSticker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1184253338);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBoxed<TlStoreObject, 853188252>::store(new_sticker_, s);
}

void stickers_replaceSticker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1184253338);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBoxed<TlStoreObject, 853188252>::store(new_sticker_, s);
}

void stickers_replaceSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.replaceSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("new_sticker", static_cast<const BaseObject *>(new_sticker_.get()));
    s.store_class_end();
  }
}

stickers_replaceSticker::ReturnType stickers_replaceSticker::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

const std::int32_t stories_getAllReadPeerStories::ID;

void stories_getAllReadPeerStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1688541191);
}

void stories_getAllReadPeerStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1688541191);
}

void stories_getAllReadPeerStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getAllReadPeerStories");
    s.store_class_end();
  }
}

stories_getAllReadPeerStories::ReturnType stories_getAllReadPeerStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

upload_saveBigFilePart::upload_saveBigFilePart(int64 file_id_, int32 file_part_, int32 file_total_parts_, bytes &&bytes_)
  : file_id_(file_id_)
  , file_part_(file_part_)
  , file_total_parts_(file_total_parts_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t upload_saveBigFilePart::ID;

void upload_saveBigFilePart::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-562337987);
  TlStoreBinary::store(file_id_, s);
  TlStoreBinary::store(file_part_, s);
  TlStoreBinary::store(file_total_parts_, s);
  TlStoreString::store(bytes_, s);
}

void upload_saveBigFilePart::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-562337987);
  TlStoreBinary::store(file_id_, s);
  TlStoreBinary::store(file_part_, s);
  TlStoreBinary::store(file_total_parts_, s);
  TlStoreString::store(bytes_, s);
}

void upload_saveBigFilePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.saveBigFilePart");
    s.store_field("file_id", file_id_);
    s.store_field("file_part", file_part_);
    s.store_field("file_total_parts", file_total_parts_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

upload_saveBigFilePart::ReturnType upload_saveBigFilePart::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t wallet_getExistingWaltBalance::ID;

void wallet_getExistingWaltBalance::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1763656544);
}

void wallet_getExistingWaltBalance::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1763656544);
}

void wallet_getExistingWaltBalance::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.getExistingWaltBalance");
    s.store_class_end();
  }
}

wallet_getExistingWaltBalance::ReturnType wallet_getExistingWaltBalance::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_existingBalance>, -1108800883>::parse(p);
#undef FAIL
}

wallet_getTransactions::wallet_getTransactions(int32 flags_, bool inbound_, bool outbound_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , inbound_(inbound_)
  , outbound_(outbound_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t wallet_getTransactions::ID;

void wallet_getTransactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1467807101);
  TlStoreBinary::store((var0 = flags_ | (inbound_ << 0) | (outbound_ << 1)), s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void wallet_getTransactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1467807101);
  TlStoreBinary::store((var0 = flags_ | (inbound_ << 0) | (outbound_ << 1)), s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void wallet_getTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.getTransactions");
    s.store_field("flags", (var0 = flags_ | (inbound_ << 0) | (outbound_ << 1)));
    if (var0 & 1) { s.store_field("inbound", true); }
    if (var0 & 2) { s.store_field("outbound", true); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

wallet_getTransactions::ReturnType wallet_getTransactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_transactions>, 1126356389>::parse(p);
#undef FAIL
}

wallet_tonConnectSubmitConnectResult::wallet_tonConnectSubmitConnectResult(int32 flags_, bool error_, int64 session_id_, bytes &&challenge_answer_, bytes &&body_, string const &trace_id_)
  : flags_(flags_)
  , error_(error_)
  , session_id_(session_id_)
  , challenge_answer_(std::move(challenge_answer_))
  , body_(std::move(body_))
  , trace_id_(trace_id_)
{}

const std::int32_t wallet_tonConnectSubmitConnectResult::ID;

void wallet_tonConnectSubmitConnectResult::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1027602567);
  TlStoreBinary::store((var0 = flags_ | (error_ << 0) | ((!trace_id_.empty()) << 1)), s);
  TlStoreBinary::store(session_id_, s);
  TlStoreString::store(challenge_answer_, s);
  TlStoreString::store(body_, s);
  if (var0 & 2) { TlStoreString::store(trace_id_, s); }
}

void wallet_tonConnectSubmitConnectResult::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1027602567);
  TlStoreBinary::store((var0 = flags_ | (error_ << 0) | ((!trace_id_.empty()) << 1)), s);
  TlStoreBinary::store(session_id_, s);
  TlStoreString::store(challenge_answer_, s);
  TlStoreString::store(body_, s);
  if (var0 & 2) { TlStoreString::store(trace_id_, s); }
}

void wallet_tonConnectSubmitConnectResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectSubmitConnectResult");
    s.store_field("flags", (var0 = flags_ | (error_ << 0) | ((!trace_id_.empty()) << 1)));
    if (var0 & 1) { s.store_field("error", true); }
    s.store_field("session_id", session_id_);
    s.store_bytes_field("challenge_answer", challenge_answer_);
    s.store_bytes_field("body", body_);
    if (var0 & 2) { s.store_field("trace_id", trace_id_); }
    s.store_class_end();
  }
}

wallet_tonConnectSubmitConnectResult::ReturnType wallet_tonConnectSubmitConnectResult::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

wallet_tonConnectSubmitResponse::wallet_tonConnectSubmitResponse(int32 flags_, int64 session_id_, int32 msg_id_, bytes &&body_, string const &trace_id_)
  : flags_(flags_)
  , session_id_(session_id_)
  , msg_id_(msg_id_)
  , body_(std::move(body_))
  , trace_id_(trace_id_)
{}

const std::int32_t wallet_tonConnectSubmitResponse::ID;

void wallet_tonConnectSubmitResponse::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-87655108);
  TlStoreBinary::store((var0 = flags_ | ((!trace_id_.empty()) << 0)), s);
  TlStoreBinary::store(session_id_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(body_, s);
  if (var0 & 1) { TlStoreString::store(trace_id_, s); }
}

void wallet_tonConnectSubmitResponse::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-87655108);
  TlStoreBinary::store((var0 = flags_ | ((!trace_id_.empty()) << 0)), s);
  TlStoreBinary::store(session_id_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(body_, s);
  if (var0 & 1) { TlStoreString::store(trace_id_, s); }
}

void wallet_tonConnectSubmitResponse::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectSubmitResponse");
    s.store_field("flags", (var0 = flags_ | ((!trace_id_.empty()) << 0)));
    s.store_field("session_id", session_id_);
    s.store_field("msg_id", msg_id_);
    s.store_bytes_field("body", body_);
    if (var0 & 1) { s.store_field("trace_id", trace_id_); }
    s.store_class_end();
  }
}

wallet_tonConnectSubmitResponse::ReturnType wallet_tonConnectSubmitResponse::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
