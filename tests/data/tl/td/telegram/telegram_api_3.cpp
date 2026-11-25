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


attachMenuBot::attachMenuBot()
  : flags_()
  , inactive_()
  , has_settings_()
  , request_write_access_()
  , show_in_attach_menu_()
  , show_in_side_menu_()
  , side_menu_disclaimer_needed_()
  , bot_id_()
  , short_name_()
  , peer_types_()
  , icons_()
{}

const std::int32_t attachMenuBot::ID;

object_ptr<attachMenuBot> attachMenuBot::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<attachMenuBot> res = make_tl_object<attachMenuBot>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inactive_ = (var0 & 1) != 0;
  res->has_settings_ = (var0 & 2) != 0;
  res->request_write_access_ = (var0 & 4) != 0;
  res->show_in_attach_menu_ = (var0 & 8) != 0;
  res->show_in_side_menu_ = (var0 & 16) != 0;
  res->side_menu_disclaimer_needed_ = (var0 & 32) != 0;
  res->bot_id_ = TlFetchLong::parse(p);
  res->short_name_ = TlFetchString<string>::parse(p);
  if (var0 & 8) { res->peer_types_ = TlFetchBoxed<TlFetchVector<TlFetchObject<AttachMenuPeerType>>, 481674261>::parse(p); }
  res->icons_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<attachMenuBotIcon>, -1297663893>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void attachMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBot");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inactive_ << 0) | (has_settings_ << 1) | (request_write_access_ << 2) | (show_in_attach_menu_ << 3) | (show_in_side_menu_ << 4) | (side_menu_disclaimer_needed_ << 5) | ((!peer_types_.empty()) << 3)));
    if (var0 & 1) { s.store_field("inactive", true); }
    if (var0 & 2) { s.store_field("has_settings", true); }
    if (var0 & 4) { s.store_field("request_write_access", true); }
    if (var0 & 8) { s.store_field("show_in_attach_menu", true); }
    if (var0 & 16) { s.store_field("show_in_side_menu", true); }
    if (var0 & 32) { s.store_field("side_menu_disclaimer_needed", true); }
    s.store_field("bot_id", bot_id_);
    s.store_field("short_name", short_name_);
    if (var0 & 8) { { s.store_vector_begin("peer_types", peer_types_.size()); for (const auto &_value : peer_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("icons", icons_.size()); for (const auto &_value : icons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessBotRecipients::businessBotRecipients()
  : flags_()
  , existing_chats_()
  , new_chats_()
  , contacts_()
  , non_contacts_()
  , exclude_selected_()
  , users_()
  , exclude_users_()
{}

const std::int32_t businessBotRecipients::ID;

object_ptr<businessBotRecipients> businessBotRecipients::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessBotRecipients> res = make_tl_object<businessBotRecipients>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->existing_chats_ = (var0 & 1) != 0;
  res->new_chats_ = (var0 & 2) != 0;
  res->contacts_ = (var0 & 4) != 0;
  res->non_contacts_ = (var0 & 8) != 0;
  res->exclude_selected_ = (var0 & 32) != 0;
  if (var0 & 16) { res->users_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (var0 & 64) { res->exclude_users_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessBotRecipients::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessBotRecipients");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5) | ((!users_.empty()) << 4) | ((!exclude_users_.empty()) << 6)));
    if (var0 & 1) { s.store_field("existing_chats", true); }
    if (var0 & 2) { s.store_field("new_chats", true); }
    if (var0 & 4) { s.store_field("contacts", true); }
    if (var0 & 8) { s.store_field("non_contacts", true); }
    if (var0 & 32) { s.store_field("exclude_selected", true); }
    if (var0 & 16) { { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 64) { { s.store_vector_begin("exclude_users", exclude_users_.size()); for (const auto &_value : exclude_users_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t businessGreetingMessage::ID;

object_ptr<businessGreetingMessage> businessGreetingMessage::fetch(TlBufferParser &p) {
  return make_tl_object<businessGreetingMessage>(p);
}

businessGreetingMessage::businessGreetingMessage(TlBufferParser &p)
  : shortcut_id_(TlFetchInt::parse(p))
  , recipients_(TlFetchBoxed<TlFetchObject<businessRecipients>, 554733559>::parse(p))
  , no_activity_days_(TlFetchInt::parse(p))
{}

void businessGreetingMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessGreetingMessage");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_field("no_activity_days", no_activity_days_);
    s.store_class_end();
  }
}

const std::int32_t channelMessagesFilterEmpty::ID;

void channelMessagesFilterEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void channelMessagesFilterEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void channelMessagesFilterEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelMessagesFilterEmpty");
    s.store_class_end();
  }
}

channelMessagesFilter::channelMessagesFilter(int32 flags_, bool exclude_new_messages_, array<object_ptr<messageRange>> &&ranges_)
  : flags_(flags_)
  , exclude_new_messages_(exclude_new_messages_)
  , ranges_(std::move(ranges_))
{}

const std::int32_t channelMessagesFilter::ID;

void channelMessagesFilter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (exclude_new_messages_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 182649427>>, 481674261>::store(ranges_, s);
}

void channelMessagesFilter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (exclude_new_messages_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 182649427>>, 481674261>::store(ranges_, s);
}

void channelMessagesFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelMessagesFilter");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (exclude_new_messages_ << 1)));
    if (var0 & 2) { s.store_field("exclude_new_messages", true); }
    { s.store_vector_begin("ranges", ranges_.size()); for (const auto &_value : ranges_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<ChatFull> ChatFull::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatFull::ID:
      return chatFull::fetch(p);
    case channelFull::ID:
      return channelFull::fetch(p);
    case communityFull::ID:
      return communityFull::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

chatFull::chatFull()
  : flags_()
  , can_set_username_()
  , has_scheduled_()
  , translations_disabled_()
  , has_welcome_messages_()
  , id_()
  , about_()
  , participants_()
  , chat_photo_()
  , notify_settings_()
  , exported_invite_()
  , bot_info_()
  , pinned_msg_id_()
  , folder_id_()
  , call_()
  , ttl_period_()
  , groupcall_default_join_as_()
  , theme_emoticon_()
  , requests_pending_()
  , recent_requesters_()
  , available_reactions_()
  , reactions_limit_()
{}

const std::int32_t chatFull::ID;

object_ptr<ChatFull> chatFull::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatFull> res = make_tl_object<chatFull>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_set_username_ = (var0 & 128) != 0;
  res->has_scheduled_ = (var0 & 256) != 0;
  res->translations_disabled_ = (var0 & 524288) != 0;
  res->has_welcome_messages_ = (var0 & 2097152) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->about_ = TlFetchString<string>::parse(p);
  res->participants_ = TlFetchObject<ChatParticipants>::parse(p);
  if (var0 & 4) { res->chat_photo_ = TlFetchObject<Photo>::parse(p); }
  res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
  if (var0 & 8192) { res->exported_invite_ = TlFetchObject<ExportedChatInvite>::parse(p); }
  if (var0 & 8) { res->bot_info_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botInfo>, 1300890265>>, 481674261>::parse(p); }
  if (var0 & 64) { res->pinned_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->folder_id_ = TlFetchInt::parse(p); }
  if (var0 & 4096) { res->call_ = TlFetchObject<InputGroupCall>::parse(p); }
  if (var0 & 16384) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (var0 & 32768) { res->groupcall_default_join_as_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 65536) { res->theme_emoticon_ = TlFetchString<string>::parse(p); }
  if (var0 & 131072) { res->requests_pending_ = TlFetchInt::parse(p); }
  if (var0 & 131072) { res->recent_requesters_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (var0 & 262144) { res->available_reactions_ = TlFetchObject<ChatReactions>::parse(p); }
  if (var0 & 1048576) { res->reactions_limit_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFull");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_set_username_ << 7) | (has_scheduled_ << 8) | (translations_disabled_ << 19) | (has_welcome_messages_ << 21) | ((chat_photo_ != nullptr) << 2) | ((exported_invite_ != nullptr) << 13) | ((!bot_info_.empty()) << 3) | ((call_ != nullptr) << 12) | ((groupcall_default_join_as_ != nullptr) << 15) | ((!theme_emoticon_.empty()) << 16) | ((!recent_requesters_.empty()) << 17) | ((available_reactions_ != nullptr) << 18)));
    if (var0 & 128) { s.store_field("can_set_username", true); }
    if (var0 & 256) { s.store_field("has_scheduled", true); }
    if (var0 & 524288) { s.store_field("translations_disabled", true); }
    if (var0 & 2097152) { s.store_field("has_welcome_messages", true); }
    s.store_field("id", id_);
    s.store_field("about", about_);
    s.store_object_field("participants", static_cast<const BaseObject *>(participants_.get()));
    if (var0 & 4) { s.store_object_field("chat_photo", static_cast<const BaseObject *>(chat_photo_.get())); }
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    if (var0 & 8192) { s.store_object_field("exported_invite", static_cast<const BaseObject *>(exported_invite_.get())); }
    if (var0 & 8) { { s.store_vector_begin("bot_info", bot_info_.size()); for (const auto &_value : bot_info_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 64) { s.store_field("pinned_msg_id", pinned_msg_id_); }
    if (var0 & 2048) { s.store_field("folder_id", folder_id_); }
    if (var0 & 4096) { s.store_object_field("call", static_cast<const BaseObject *>(call_.get())); }
    if (var0 & 16384) { s.store_field("ttl_period", ttl_period_); }
    if (var0 & 32768) { s.store_object_field("groupcall_default_join_as", static_cast<const BaseObject *>(groupcall_default_join_as_.get())); }
    if (var0 & 65536) { s.store_field("theme_emoticon", theme_emoticon_); }
    if (var0 & 131072) { s.store_field("requests_pending", requests_pending_); }
    if (var0 & 131072) { { s.store_vector_begin("recent_requesters", recent_requesters_.size()); for (const auto &_value : recent_requesters_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 262144) { s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get())); }
    if (var0 & 1048576) { s.store_field("reactions_limit", reactions_limit_); }
    s.store_class_end();
  }
}

channelFull::channelFull()
  : flags_()
  , can_view_participants_()
  , can_set_username_()
  , can_set_stickers_()
  , hidden_prehistory_()
  , can_set_location_()
  , has_scheduled_()
  , can_view_stats_()
  , blocked_()
  , flags2_()
  , can_delete_channel_()
  , antispam_()
  , participants_hidden_()
  , translations_disabled_()
  , stories_pinned_available_()
  , view_forum_as_messages_()
  , restricted_sponsored_()
  , can_view_revenue_()
  , paid_media_allowed_()
  , can_view_stars_revenue_()
  , paid_reactions_available_()
  , stargifts_available_()
  , paid_messages_available_()
  , has_welcome_messages_()
  , id_()
  , about_()
  , participants_count_()
  , admins_count_()
  , kicked_count_()
  , banned_count_()
  , online_count_()
  , read_inbox_max_id_()
  , read_outbox_max_id_()
  , unread_count_()
  , chat_photo_()
  , notify_settings_()
  , exported_invite_()
  , bot_info_()
  , migrated_from_chat_id_()
  , migrated_from_max_id_()
  , pinned_msg_id_()
  , stickerset_()
  , available_min_id_()
  , folder_id_()
  , linked_chat_id_()
  , location_()
  , slowmode_seconds_()
  , slowmode_next_send_date_()
  , stats_dc_()
  , pts_()
  , call_()
  , ttl_period_()
  , pending_suggestions_()
  , groupcall_default_join_as_()
  , theme_emoticon_()
  , requests_pending_()
  , recent_requesters_()
  , default_send_as_()
  , available_reactions_()
  , reactions_limit_()
  , stories_()
  , wallpaper_()
  , boosts_applied_()
  , boosts_unrestrict_()
  , emojiset_()
  , bot_verification_()
  , stargifts_count_()
  , send_paid_messages_stars_()
  , main_tab_()
  , guard_bot_id_()
  , share_theme_()
{}

const std::int32_t channelFull::ID;

object_ptr<ChatFull> channelFull::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelFull> res = make_tl_object<channelFull>();
  int32 var0;
  int32 var1;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_view_participants_ = (var0 & 8) != 0;
  res->can_set_username_ = (var0 & 64) != 0;
  res->can_set_stickers_ = (var0 & 128) != 0;
  res->hidden_prehistory_ = (var0 & 1024) != 0;
  res->can_set_location_ = (var0 & 65536) != 0;
  res->has_scheduled_ = (var0 & 524288) != 0;
  res->can_view_stats_ = (var0 & 1048576) != 0;
  res->blocked_ = (var0 & 4194304) != 0;
  if ((var1 = res->flags2_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_delete_channel_ = (var1 & 1) != 0;
  res->antispam_ = (var1 & 2) != 0;
  res->participants_hidden_ = (var1 & 4) != 0;
  res->translations_disabled_ = (var1 & 8) != 0;
  res->stories_pinned_available_ = (var1 & 32) != 0;
  res->view_forum_as_messages_ = (var1 & 64) != 0;
  res->restricted_sponsored_ = (var1 & 2048) != 0;
  res->can_view_revenue_ = (var1 & 4096) != 0;
  res->paid_media_allowed_ = (var1 & 16384) != 0;
  res->can_view_stars_revenue_ = (var1 & 32768) != 0;
  res->paid_reactions_available_ = (var1 & 65536) != 0;
  res->stargifts_available_ = (var1 & 524288) != 0;
  res->paid_messages_available_ = (var1 & 1048576) != 0;
  res->has_welcome_messages_ = (var1 & 16777216) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->about_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->participants_count_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->admins_count_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->kicked_count_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->banned_count_ = TlFetchInt::parse(p); }
  if (var0 & 8192) { res->online_count_ = TlFetchInt::parse(p); }
  res->read_inbox_max_id_ = TlFetchInt::parse(p);
  res->read_outbox_max_id_ = TlFetchInt::parse(p);
  res->unread_count_ = TlFetchInt::parse(p);
  res->chat_photo_ = TlFetchObject<Photo>::parse(p);
  res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
  if (var0 & 8388608) { res->exported_invite_ = TlFetchObject<ExportedChatInvite>::parse(p); }
  res->bot_info_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botInfo>, 1300890265>>, 481674261>::parse(p);
  if (var0 & 16) { res->migrated_from_chat_id_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->migrated_from_max_id_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->pinned_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->stickerset_ = TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p); }
  if (var0 & 512) { res->available_min_id_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->folder_id_ = TlFetchInt::parse(p); }
  if (var0 & 16384) { res->linked_chat_id_ = TlFetchLong::parse(p); }
  if (var0 & 32768) { res->location_ = TlFetchObject<ChannelLocation>::parse(p); }
  if (var0 & 131072) { res->slowmode_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 262144) { res->slowmode_next_send_date_ = TlFetchInt::parse(p); }
  if (var0 & 4096) { res->stats_dc_ = TlFetchInt::parse(p); }
  res->pts_ = TlFetchInt::parse(p);
  if (var0 & 2097152) { res->call_ = TlFetchObject<InputGroupCall>::parse(p); }
  if (var0 & 16777216) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (var0 & 33554432) { res->pending_suggestions_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p); }
  if (var0 & 67108864) { res->groupcall_default_join_as_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 134217728) { res->theme_emoticon_ = TlFetchString<string>::parse(p); }
  if (var0 & 268435456) { res->requests_pending_ = TlFetchInt::parse(p); }
  if (var0 & 268435456) { res->recent_requesters_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (var0 & 536870912) { res->default_send_as_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 1073741824) { res->available_reactions_ = TlFetchObject<ChatReactions>::parse(p); }
  if (var1 & 8192) { res->reactions_limit_ = TlFetchInt::parse(p); }
  if (var1 & 16) { res->stories_ = TlFetchBoxed<TlFetchObject<peerStories>, -1707742823>::parse(p); }
  if (var1 & 128) { res->wallpaper_ = TlFetchObject<WallPaper>::parse(p); }
  if (var1 & 256) { res->boosts_applied_ = TlFetchInt::parse(p); }
  if (var1 & 512) { res->boosts_unrestrict_ = TlFetchInt::parse(p); }
  if (var1 & 1024) { res->emojiset_ = TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p); }
  if (var1 & 131072) { res->bot_verification_ = TlFetchBoxed<TlFetchObject<botVerification>, -147976487>::parse(p); }
  if (var1 & 262144) { res->stargifts_count_ = TlFetchInt::parse(p); }
  if (var1 & 2097152) { res->send_paid_messages_stars_ = TlFetchLong::parse(p); }
  if (var1 & 4194304) { res->main_tab_ = TlFetchObject<ProfileTab>::parse(p); }
  if (var1 & 8388608) { res->guard_bot_id_ = TlFetchLong::parse(p); }
  if (var1 & 33554432) { res->share_theme_ = TlFetchObject<ShareTheme>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelFull");
  int32 var0;
  int32 var1;
    s.store_field("flags", (var0 = flags_ | (can_view_participants_ << 3) | (can_set_username_ << 6) | (can_set_stickers_ << 7) | (hidden_prehistory_ << 10) | (can_set_location_ << 16) | (has_scheduled_ << 19) | (can_view_stats_ << 20) | (blocked_ << 22) | ((exported_invite_ != nullptr) << 23) | ((stickerset_ != nullptr) << 8) | ((location_ != nullptr) << 15) | ((call_ != nullptr) << 21) | ((!pending_suggestions_.empty()) << 25) | ((groupcall_default_join_as_ != nullptr) << 26) | ((!theme_emoticon_.empty()) << 27) | ((!recent_requesters_.empty()) << 28) | ((default_send_as_ != nullptr) << 29) | ((available_reactions_ != nullptr) << 30)));
    if (var0 & 8) { s.store_field("can_view_participants", true); }
    if (var0 & 64) { s.store_field("can_set_username", true); }
    if (var0 & 128) { s.store_field("can_set_stickers", true); }
    if (var0 & 1024) { s.store_field("hidden_prehistory", true); }
    if (var0 & 65536) { s.store_field("can_set_location", true); }
    if (var0 & 524288) { s.store_field("has_scheduled", true); }
    if (var0 & 1048576) { s.store_field("can_view_stats", true); }
    if (var0 & 4194304) { s.store_field("blocked", true); }
    s.store_field("flags2", (var1 = flags2_ | (can_delete_channel_ << 0) | (antispam_ << 1) | (participants_hidden_ << 2) | (translations_disabled_ << 3) | (stories_pinned_available_ << 5) | (view_forum_as_messages_ << 6) | (restricted_sponsored_ << 11) | (can_view_revenue_ << 12) | (paid_media_allowed_ << 14) | (can_view_stars_revenue_ << 15) | (paid_reactions_available_ << 16) | (stargifts_available_ << 19) | (paid_messages_available_ << 20) | (has_welcome_messages_ << 24) | ((stories_ != nullptr) << 4) | ((wallpaper_ != nullptr) << 7) | ((emojiset_ != nullptr) << 10) | ((bot_verification_ != nullptr) << 17) | ((main_tab_ != nullptr) << 22) | ((share_theme_ != nullptr) << 25)));
    if (var1 & 1) { s.store_field("can_delete_channel", true); }
    if (var1 & 2) { s.store_field("antispam", true); }
    if (var1 & 4) { s.store_field("participants_hidden", true); }
    if (var1 & 8) { s.store_field("translations_disabled", true); }
    if (var1 & 32) { s.store_field("stories_pinned_available", true); }
    if (var1 & 64) { s.store_field("view_forum_as_messages", true); }
    if (var1 & 2048) { s.store_field("restricted_sponsored", true); }
    if (var1 & 4096) { s.store_field("can_view_revenue", true); }
    if (var1 & 16384) { s.store_field("paid_media_allowed", true); }
    if (var1 & 32768) { s.store_field("can_view_stars_revenue", true); }
    if (var1 & 65536) { s.store_field("paid_reactions_available", true); }
    if (var1 & 524288) { s.store_field("stargifts_available", true); }
    if (var1 & 1048576) { s.store_field("paid_messages_available", true); }
    if (var1 & 16777216) { s.store_field("has_welcome_messages", true); }
    s.store_field("id", id_);
    s.store_field("about", about_);
    if (var0 & 1) { s.store_field("participants_count", participants_count_); }
    if (var0 & 2) { s.store_field("admins_count", admins_count_); }
    if (var0 & 4) { s.store_field("kicked_count", kicked_count_); }
    if (var0 & 4) { s.store_field("banned_count", banned_count_); }
    if (var0 & 8192) { s.store_field("online_count", online_count_); }
    s.store_field("read_inbox_max_id", read_inbox_max_id_);
    s.store_field("read_outbox_max_id", read_outbox_max_id_);
    s.store_field("unread_count", unread_count_);
    s.store_object_field("chat_photo", static_cast<const BaseObject *>(chat_photo_.get()));
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    if (var0 & 8388608) { s.store_object_field("exported_invite", static_cast<const BaseObject *>(exported_invite_.get())); }
    { s.store_vector_begin("bot_info", bot_info_.size()); for (const auto &_value : bot_info_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 16) { s.store_field("migrated_from_chat_id", migrated_from_chat_id_); }
    if (var0 & 16) { s.store_field("migrated_from_max_id", migrated_from_max_id_); }
    if (var0 & 32) { s.store_field("pinned_msg_id", pinned_msg_id_); }
    if (var0 & 256) { s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get())); }
    if (var0 & 512) { s.store_field("available_min_id", available_min_id_); }
    if (var0 & 2048) { s.store_field("folder_id", folder_id_); }
    if (var0 & 16384) { s.store_field("linked_chat_id", linked_chat_id_); }
    if (var0 & 32768) { s.store_object_field("location", static_cast<const BaseObject *>(location_.get())); }
    if (var0 & 131072) { s.store_field("slowmode_seconds", slowmode_seconds_); }
    if (var0 & 262144) { s.store_field("slowmode_next_send_date", slowmode_next_send_date_); }
    if (var0 & 4096) { s.store_field("stats_dc", stats_dc_); }
    s.store_field("pts", pts_);
    if (var0 & 2097152) { s.store_object_field("call", static_cast<const BaseObject *>(call_.get())); }
    if (var0 & 16777216) { s.store_field("ttl_period", ttl_period_); }
    if (var0 & 33554432) { { s.store_vector_begin("pending_suggestions", pending_suggestions_.size()); for (const auto &_value : pending_suggestions_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 67108864) { s.store_object_field("groupcall_default_join_as", static_cast<const BaseObject *>(groupcall_default_join_as_.get())); }
    if (var0 & 134217728) { s.store_field("theme_emoticon", theme_emoticon_); }
    if (var0 & 268435456) { s.store_field("requests_pending", requests_pending_); }
    if (var0 & 268435456) { { s.store_vector_begin("recent_requesters", recent_requesters_.size()); for (const auto &_value : recent_requesters_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 536870912) { s.store_object_field("default_send_as", static_cast<const BaseObject *>(default_send_as_.get())); }
    if (var0 & 1073741824) { s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get())); }
    if (var1 & 8192) { s.store_field("reactions_limit", reactions_limit_); }
    if (var1 & 16) { s.store_object_field("stories", static_cast<const BaseObject *>(stories_.get())); }
    if (var1 & 128) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    if (var1 & 256) { s.store_field("boosts_applied", boosts_applied_); }
    if (var1 & 512) { s.store_field("boosts_unrestrict", boosts_unrestrict_); }
    if (var1 & 1024) { s.store_object_field("emojiset", static_cast<const BaseObject *>(emojiset_.get())); }
    if (var1 & 131072) { s.store_object_field("bot_verification", static_cast<const BaseObject *>(bot_verification_.get())); }
    if (var1 & 262144) { s.store_field("stargifts_count", stargifts_count_); }
    if (var1 & 2097152) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    if (var1 & 4194304) { s.store_object_field("main_tab", static_cast<const BaseObject *>(main_tab_.get())); }
    if (var1 & 8388608) { s.store_field("guard_bot_id", guard_bot_id_); }
    if (var1 & 33554432) { s.store_object_field("share_theme", static_cast<const BaseObject *>(share_theme_.get())); }
    s.store_class_end();
  }
}

communityFull::communityFull()
  : flags_()
  , id_()
  , about_()
  , chat_photo_()
  , linked_peers_()
  , notify_settings_()
  , admins_count_()
  , kicked_count_()
  , peer_link_requests_pending_()
{}

const std::int32_t communityFull::ID;

object_ptr<ChatFull> communityFull::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<communityFull> res = make_tl_object<communityFull>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  res->about_ = TlFetchString<string>::parse(p);
  res->chat_photo_ = TlFetchObject<Photo>::parse(p);
  res->linked_peers_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<communityPeer>, 1981030077>>, 481674261>::parse(p);
  if (var0 & 8) { res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p); }
  if (var0 & 2) { res->admins_count_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->kicked_count_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->peer_link_requests_pending_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void communityFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityFull");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((notify_settings_ != nullptr) << 3)));
    s.store_field("id", id_);
    s.store_field("about", about_);
    s.store_object_field("chat_photo", static_cast<const BaseObject *>(chat_photo_.get()));
    { s.store_vector_begin("linked_peers", linked_peers_.size()); for (const auto &_value : linked_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 8) { s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get())); }
    if (var0 & 2) { s.store_field("admins_count", admins_count_); }
    if (var0 & 4) { s.store_field("kicked_count", kicked_count_); }
    if (var0 & 1) { s.store_field("peer_link_requests_pending", peer_link_requests_pending_); }
    s.store_class_end();
  }
}

object_ptr<DialogFilter> DialogFilter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case dialogFilter::ID:
      return dialogFilter::fetch(p);
    case dialogFilterDefault::ID:
      return dialogFilterDefault::fetch(p);
    case dialogFilterChatlist::ID:
      return dialogFilterChatlist::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

dialogFilter::dialogFilter()
  : flags_()
  , contacts_()
  , non_contacts_()
  , groups_()
  , broadcasts_()
  , bots_()
  , exclude_muted_()
  , exclude_read_()
  , exclude_archived_()
  , title_noanimate_()
  , id_()
  , title_()
  , emoticon_()
  , color_()
  , pinned_peers_()
  , include_peers_()
  , exclude_peers_()
{}

dialogFilter::dialogFilter(int32 flags_, bool contacts_, bool non_contacts_, bool groups_, bool broadcasts_, bool bots_, bool exclude_muted_, bool exclude_read_, bool exclude_archived_, bool title_noanimate_, int32 id_, object_ptr<textWithEntities> &&title_, string const &emoticon_, int32 color_, array<object_ptr<InputPeer>> &&pinned_peers_, array<object_ptr<InputPeer>> &&include_peers_, array<object_ptr<InputPeer>> &&exclude_peers_)
  : flags_(flags_)
  , contacts_(contacts_)
  , non_contacts_(non_contacts_)
  , groups_(groups_)
  , broadcasts_(broadcasts_)
  , bots_(bots_)
  , exclude_muted_(exclude_muted_)
  , exclude_read_(exclude_read_)
  , exclude_archived_(exclude_archived_)
  , title_noanimate_(title_noanimate_)
  , id_(id_)
  , title_(std::move(title_))
  , emoticon_(emoticon_)
  , color_(color_)
  , pinned_peers_(std::move(pinned_peers_))
  , include_peers_(std::move(include_peers_))
  , exclude_peers_(std::move(exclude_peers_))
{}

const std::int32_t dialogFilter::ID;

object_ptr<DialogFilter> dialogFilter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<dialogFilter> res = make_tl_object<dialogFilter>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->contacts_ = (var0 & 1) != 0;
  res->non_contacts_ = (var0 & 2) != 0;
  res->groups_ = (var0 & 4) != 0;
  res->broadcasts_ = (var0 & 8) != 0;
  res->bots_ = (var0 & 16) != 0;
  res->exclude_muted_ = (var0 & 2048) != 0;
  res->exclude_read_ = (var0 & 4096) != 0;
  res->exclude_archived_ = (var0 & 8192) != 0;
  res->title_noanimate_ = (var0 & 268435456) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->title_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 33554432) { res->emoticon_ = TlFetchString<string>::parse(p); }
  if (var0 & 134217728) { res->color_ = TlFetchInt::parse(p); }
  res->pinned_peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputPeer>>, 481674261>::parse(p);
  res->include_peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputPeer>>, 481674261>::parse(p);
  res->exclude_peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputPeer>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void dialogFilter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (contacts_ << 0) | (non_contacts_ << 1) | (groups_ << 2) | (broadcasts_ << 3) | (bots_ << 4) | (exclude_muted_ << 11) | (exclude_read_ << 12) | (exclude_archived_ << 13) | (title_noanimate_ << 28) | ((!emoticon_.empty()) << 25)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  if (var0 & 33554432) { TlStoreString::store(emoticon_, s); }
  if (var0 & 134217728) { TlStoreBinary::store(color_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(pinned_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(include_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(exclude_peers_, s);
}

void dialogFilter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (contacts_ << 0) | (non_contacts_ << 1) | (groups_ << 2) | (broadcasts_ << 3) | (bots_ << 4) | (exclude_muted_ << 11) | (exclude_read_ << 12) | (exclude_archived_ << 13) | (title_noanimate_ << 28) | ((!emoticon_.empty()) << 25)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  if (var0 & 33554432) { TlStoreString::store(emoticon_, s); }
  if (var0 & 134217728) { TlStoreBinary::store(color_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(pinned_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(include_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(exclude_peers_, s);
}

void dialogFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogFilter");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (contacts_ << 0) | (non_contacts_ << 1) | (groups_ << 2) | (broadcasts_ << 3) | (bots_ << 4) | (exclude_muted_ << 11) | (exclude_read_ << 12) | (exclude_archived_ << 13) | (title_noanimate_ << 28) | ((!emoticon_.empty()) << 25)));
    if (var0 & 1) { s.store_field("contacts", true); }
    if (var0 & 2) { s.store_field("non_contacts", true); }
    if (var0 & 4) { s.store_field("groups", true); }
    if (var0 & 8) { s.store_field("broadcasts", true); }
    if (var0 & 16) { s.store_field("bots", true); }
    if (var0 & 2048) { s.store_field("exclude_muted", true); }
    if (var0 & 4096) { s.store_field("exclude_read", true); }
    if (var0 & 8192) { s.store_field("exclude_archived", true); }
    if (var0 & 268435456) { s.store_field("title_noanimate", true); }
    s.store_field("id", id_);
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    if (var0 & 33554432) { s.store_field("emoticon", emoticon_); }
    if (var0 & 134217728) { s.store_field("color", color_); }
    { s.store_vector_begin("pinned_peers", pinned_peers_.size()); for (const auto &_value : pinned_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("include_peers", include_peers_.size()); for (const auto &_value : include_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("exclude_peers", exclude_peers_.size()); for (const auto &_value : exclude_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t dialogFilterDefault::ID;

object_ptr<DialogFilter> dialogFilterDefault::fetch(TlBufferParser &p) {
  return make_tl_object<dialogFilterDefault>();
}

void dialogFilterDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void dialogFilterDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void dialogFilterDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogFilterDefault");
    s.store_class_end();
  }
}

dialogFilterChatlist::dialogFilterChatlist()
  : flags_()
  , has_my_invites_()
  , title_noanimate_()
  , id_()
  , title_()
  , emoticon_()
  , color_()
  , pinned_peers_()
  , include_peers_()
{}

dialogFilterChatlist::dialogFilterChatlist(int32 flags_, bool has_my_invites_, bool title_noanimate_, int32 id_, object_ptr<textWithEntities> &&title_, string const &emoticon_, int32 color_, array<object_ptr<InputPeer>> &&pinned_peers_, array<object_ptr<InputPeer>> &&include_peers_)
  : flags_(flags_)
  , has_my_invites_(has_my_invites_)
  , title_noanimate_(title_noanimate_)
  , id_(id_)
  , title_(std::move(title_))
  , emoticon_(emoticon_)
  , color_(color_)
  , pinned_peers_(std::move(pinned_peers_))
  , include_peers_(std::move(include_peers_))
{}

const std::int32_t dialogFilterChatlist::ID;

object_ptr<DialogFilter> dialogFilterChatlist::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<dialogFilterChatlist> res = make_tl_object<dialogFilterChatlist>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_my_invites_ = (var0 & 67108864) != 0;
  res->title_noanimate_ = (var0 & 268435456) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->title_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 33554432) { res->emoticon_ = TlFetchString<string>::parse(p); }
  if (var0 & 134217728) { res->color_ = TlFetchInt::parse(p); }
  res->pinned_peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputPeer>>, 481674261>::parse(p);
  res->include_peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputPeer>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void dialogFilterChatlist::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_my_invites_ << 26) | (title_noanimate_ << 28) | ((!emoticon_.empty()) << 25)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  if (var0 & 33554432) { TlStoreString::store(emoticon_, s); }
  if (var0 & 134217728) { TlStoreBinary::store(color_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(pinned_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(include_peers_, s);
}

void dialogFilterChatlist::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_my_invites_ << 26) | (title_noanimate_ << 28) | ((!emoticon_.empty()) << 25)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  if (var0 & 33554432) { TlStoreString::store(emoticon_, s); }
  if (var0 & 134217728) { TlStoreBinary::store(color_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(pinned_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(include_peers_, s);
}

void dialogFilterChatlist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogFilterChatlist");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_my_invites_ << 26) | (title_noanimate_ << 28) | ((!emoticon_.empty()) << 25)));
    if (var0 & 67108864) { s.store_field("has_my_invites", true); }
    if (var0 & 268435456) { s.store_field("title_noanimate", true); }
    s.store_field("id", id_);
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    if (var0 & 33554432) { s.store_field("emoticon", emoticon_); }
    if (var0 & 134217728) { s.store_field("color", color_); }
    { s.store_vector_begin("pinned_peers", pinned_peers_.size()); for (const auto &_value : pinned_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("include_peers", include_peers_.size()); for (const auto &_value : include_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<EncryptedFile> EncryptedFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case encryptedFileEmpty::ID:
      return encryptedFileEmpty::fetch(p);
    case encryptedFile::ID:
      return encryptedFile::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t encryptedFileEmpty::ID;

object_ptr<EncryptedFile> encryptedFileEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedFileEmpty>();
}

void encryptedFileEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedFileEmpty");
    s.store_class_end();
  }
}

const std::int32_t encryptedFile::ID;

object_ptr<EncryptedFile> encryptedFile::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedFile>(p);
}

encryptedFile::encryptedFile(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , size_(TlFetchLong::parse(p))
  , dc_id_(TlFetchInt::parse(p))
  , key_fingerprint_(TlFetchInt::parse(p))
{}

void encryptedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedFile");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("size", size_);
    s.store_field("dc_id", dc_id_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_class_end();
  }
}

object_ptr<EncryptedMessage> EncryptedMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case encryptedMessage::ID:
      return encryptedMessage::fetch(p);
    case encryptedMessageService::ID:
      return encryptedMessageService::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t encryptedMessage::ID;

object_ptr<EncryptedMessage> encryptedMessage::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedMessage>(p);
}

encryptedMessage::encryptedMessage(TlBufferParser &p)
  : random_id_(TlFetchLong::parse(p))
  , chat_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
  , file_(TlFetchObject<EncryptedFile>::parse(p))
{}

void encryptedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedMessage");
    s.store_field("random_id", random_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("date", date_);
    s.store_bytes_field("bytes", bytes_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

const std::int32_t encryptedMessageService::ID;

object_ptr<EncryptedMessage> encryptedMessageService::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedMessageService>(p);
}

encryptedMessageService::encryptedMessageService(TlBufferParser &p)
  : random_id_(TlFetchLong::parse(p))
  , chat_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void encryptedMessageService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedMessageService");
    s.store_field("random_id", random_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("date", date_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

exportedNoPaidMessagesToken::exportedNoPaidMessagesToken()
  : flags_()
  , token_()
  , url_()
  , expires_()
{}

const std::int32_t exportedNoPaidMessagesToken::ID;

object_ptr<exportedNoPaidMessagesToken> exportedNoPaidMessagesToken::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<exportedNoPaidMessagesToken> res = make_tl_object<exportedNoPaidMessagesToken>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->token_ = TlFetchString<string>::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->expires_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void exportedNoPaidMessagesToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "exportedNoPaidMessagesToken");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("token", "[REDACTED]");
    s.store_field("url", url_);
    if (var0 & 1) { s.store_field("expires", expires_); }
    s.store_class_end();
  }
}

folder::folder()
  : flags_()
  , autofill_new_broadcasts_()
  , autofill_public_groups_()
  , autofill_new_correspondents_()
  , id_()
  , title_()
  , photo_()
{}

const std::int32_t folder::ID;

object_ptr<folder> folder::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<folder> res = make_tl_object<folder>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->autofill_new_broadcasts_ = (var0 & 1) != 0;
  res->autofill_public_groups_ = (var0 & 2) != 0;
  res->autofill_new_correspondents_ = (var0 & 4) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 8) { res->photo_ = TlFetchObject<ChatPhoto>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void folder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "folder");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (autofill_new_broadcasts_ << 0) | (autofill_public_groups_ << 1) | (autofill_new_correspondents_ << 2) | ((photo_ != nullptr) << 3)));
    if (var0 & 1) { s.store_field("autofill_new_broadcasts", true); }
    if (var0 & 2) { s.store_field("autofill_public_groups", true); }
    if (var0 & 4) { s.store_field("autofill_new_correspondents", true); }
    s.store_field("id", id_);
    s.store_field("title", title_);
    if (var0 & 8) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_class_end();
  }
}

object_ptr<ForumTopic> ForumTopic::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case forumTopicDeleted::ID:
      return forumTopicDeleted::fetch(p);
    case forumTopic::ID:
      return forumTopic::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t forumTopicDeleted::ID;

object_ptr<ForumTopic> forumTopicDeleted::fetch(TlBufferParser &p) {
  return make_tl_object<forumTopicDeleted>(p);
}

forumTopicDeleted::forumTopicDeleted(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
{}

void forumTopicDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopicDeleted");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

forumTopic::forumTopic()
  : flags_()
  , my_()
  , closed_()
  , pinned_()
  , short_()
  , hidden_()
  , title_missing_()
  , id_()
  , date_()
  , peer_()
  , title_()
  , icon_color_()
  , icon_emoji_id_()
  , top_message_()
  , read_inbox_max_id_()
  , read_outbox_max_id_()
  , unread_count_()
  , unread_mentions_count_()
  , unread_reactions_count_()
  , unread_poll_votes_count_()
  , from_id_()
  , notify_settings_()
  , draft_()
{}

const std::int32_t forumTopic::ID;

object_ptr<ForumTopic> forumTopic::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<forumTopic> res = make_tl_object<forumTopic>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->my_ = (var0 & 2) != 0;
  res->closed_ = (var0 & 4) != 0;
  res->pinned_ = (var0 & 8) != 0;
  res->short_ = (var0 & 32) != 0;
  res->hidden_ = (var0 & 64) != 0;
  res->title_missing_ = (var0 & 128) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->icon_color_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->icon_emoji_id_ = TlFetchLong::parse(p); }
  res->top_message_ = TlFetchInt::parse(p);
  res->read_inbox_max_id_ = TlFetchInt::parse(p);
  res->read_outbox_max_id_ = TlFetchInt::parse(p);
  res->unread_count_ = TlFetchInt::parse(p);
  res->unread_mentions_count_ = TlFetchInt::parse(p);
  res->unread_reactions_count_ = TlFetchInt::parse(p);
  res->unread_poll_votes_count_ = TlFetchInt::parse(p);
  res->from_id_ = TlFetchObject<Peer>::parse(p);
  res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
  if (var0 & 16) { res->draft_ = TlFetchObject<DraftMessage>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void forumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopic");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (my_ << 1) | (closed_ << 2) | (pinned_ << 3) | (short_ << 5) | (hidden_ << 6) | (title_missing_ << 7) | ((draft_ != nullptr) << 4)));
    if (var0 & 2) { s.store_field("my", true); }
    if (var0 & 4) { s.store_field("closed", true); }
    if (var0 & 8) { s.store_field("pinned", true); }
    if (var0 & 32) { s.store_field("short", true); }
    if (var0 & 64) { s.store_field("hidden", true); }
    if (var0 & 128) { s.store_field("title_missing", true); }
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("title", title_);
    s.store_field("icon_color", icon_color_);
    if (var0 & 1) { s.store_field("icon_emoji_id", icon_emoji_id_); }
    s.store_field("top_message", top_message_);
    s.store_field("read_inbox_max_id", read_inbox_max_id_);
    s.store_field("read_outbox_max_id", read_outbox_max_id_);
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_mentions_count", unread_mentions_count_);
    s.store_field("unread_reactions_count", unread_reactions_count_);
    s.store_field("unread_poll_votes_count", unread_poll_votes_count_);
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    if (var0 & 16) { s.store_object_field("draft", static_cast<const BaseObject *>(draft_.get())); }
    s.store_class_end();
  }
}

object_ptr<GeoPoint> GeoPoint::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case geoPointEmpty::ID:
      return geoPointEmpty::fetch(p);
    case geoPoint::ID:
      return geoPoint::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t geoPointEmpty::ID;

object_ptr<GeoPoint> geoPointEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<geoPointEmpty>();
}

void geoPointEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void geoPointEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void geoPointEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "geoPointEmpty");
    s.store_class_end();
  }
}

geoPoint::geoPoint()
  : flags_()
  , long_()
  , lat_()
  , access_hash_()
  , accuracy_radius_()
{}

geoPoint::geoPoint(int32 flags_, double long_, double lat_, int64 access_hash_, int32 accuracy_radius_)
  : flags_(flags_)
  , long_(long_)
  , lat_(lat_)
  , access_hash_(access_hash_)
  , accuracy_radius_(accuracy_radius_)
{}

const std::int32_t geoPoint::ID;

object_ptr<GeoPoint> geoPoint::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<geoPoint> res = make_tl_object<geoPoint>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->long_ = TlFetchDouble::parse(p);
  res->lat_ = TlFetchDouble::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->accuracy_radius_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void geoPoint::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(long_, s);
  TlStoreBinary::store(lat_, s);
  TlStoreBinary::store(access_hash_, s);
  if (var0 & 1) { TlStoreBinary::store(accuracy_radius_, s); }
}

void geoPoint::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(long_, s);
  TlStoreBinary::store(lat_, s);
  TlStoreBinary::store(access_hash_, s);
  if (var0 & 1) { TlStoreBinary::store(accuracy_radius_, s); }
}

void geoPoint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "geoPoint");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("long", long_);
    s.store_field("lat", lat_);
    s.store_field("access_hash", access_hash_);
    if (var0 & 1) { s.store_field("accuracy_radius", accuracy_radius_); }
    s.store_class_end();
  }
}

object_ptr<GroupCall> GroupCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case groupCallDiscarded::ID:
      return groupCallDiscarded::fetch(p);
    case groupCall::ID:
      return groupCall::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t groupCallDiscarded::ID;

object_ptr<GroupCall> groupCallDiscarded::fetch(TlBufferParser &p) {
  return make_tl_object<groupCallDiscarded>(p);
}

groupCallDiscarded::groupCallDiscarded(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , duration_(TlFetchInt::parse(p))
{}

void groupCallDiscarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallDiscarded");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

groupCall::groupCall()
  : flags_()
  , join_muted_()
  , can_change_join_muted_()
  , join_date_asc_()
  , schedule_start_subscribed_()
  , can_start_video_()
  , record_video_active_()
  , rtmp_stream_()
  , listeners_hidden_()
  , conference_()
  , creator_()
  , messages_enabled_()
  , can_change_messages_enabled_()
  , min_()
  , id_()
  , access_hash_()
  , participants_count_()
  , title_()
  , stream_dc_id_()
  , record_start_date_()
  , schedule_date_()
  , unmuted_video_count_()
  , unmuted_video_limit_()
  , version_()
  , invite_link_()
  , send_paid_messages_stars_()
  , default_send_as_()
{}

const std::int32_t groupCall::ID;

object_ptr<GroupCall> groupCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<groupCall> res = make_tl_object<groupCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->join_muted_ = (var0 & 2) != 0;
  res->can_change_join_muted_ = (var0 & 4) != 0;
  res->join_date_asc_ = (var0 & 64) != 0;
  res->schedule_start_subscribed_ = (var0 & 256) != 0;
  res->can_start_video_ = (var0 & 512) != 0;
  res->record_video_active_ = (var0 & 2048) != 0;
  res->rtmp_stream_ = (var0 & 4096) != 0;
  res->listeners_hidden_ = (var0 & 8192) != 0;
  res->conference_ = (var0 & 16384) != 0;
  res->creator_ = (var0 & 32768) != 0;
  res->messages_enabled_ = (var0 & 131072) != 0;
  res->can_change_messages_enabled_ = (var0 & 262144) != 0;
  res->min_ = (var0 & 524288) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->participants_count_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->stream_dc_id_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->record_start_date_ = TlFetchInt::parse(p); }
  if (var0 & 128) { res->schedule_date_ = TlFetchInt::parse(p); }
  if (var0 & 1024) { res->unmuted_video_count_ = TlFetchInt::parse(p); }
  res->unmuted_video_limit_ = TlFetchInt::parse(p);
  res->version_ = TlFetchInt::parse(p);
  if (var0 & 65536) { res->invite_link_ = TlFetchString<string>::parse(p); }
  if (var0 & 1048576) { res->send_paid_messages_stars_ = TlFetchLong::parse(p); }
  if (var0 & 2097152) { res->default_send_as_ = TlFetchObject<Peer>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void groupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (join_muted_ << 1) | (can_change_join_muted_ << 2) | (join_date_asc_ << 6) | (schedule_start_subscribed_ << 8) | (can_start_video_ << 9) | (record_video_active_ << 11) | (rtmp_stream_ << 12) | (listeners_hidden_ << 13) | (conference_ << 14) | (creator_ << 15) | (messages_enabled_ << 17) | (can_change_messages_enabled_ << 18) | (min_ << 19) | ((!title_.empty()) << 3) | ((!invite_link_.empty()) << 16) | ((default_send_as_ != nullptr) << 21)));
    if (var0 & 2) { s.store_field("join_muted", true); }
    if (var0 & 4) { s.store_field("can_change_join_muted", true); }
    if (var0 & 64) { s.store_field("join_date_asc", true); }
    if (var0 & 256) { s.store_field("schedule_start_subscribed", true); }
    if (var0 & 512) { s.store_field("can_start_video", true); }
    if (var0 & 2048) { s.store_field("record_video_active", true); }
    if (var0 & 4096) { s.store_field("rtmp_stream", true); }
    if (var0 & 8192) { s.store_field("listeners_hidden", true); }
    if (var0 & 16384) { s.store_field("conference", true); }
    if (var0 & 32768) { s.store_field("creator", true); }
    if (var0 & 131072) { s.store_field("messages_enabled", true); }
    if (var0 & 262144) { s.store_field("can_change_messages_enabled", true); }
    if (var0 & 524288) { s.store_field("min", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("participants_count", participants_count_);
    if (var0 & 8) { s.store_field("title", title_); }
    if (var0 & 16) { s.store_field("stream_dc_id", stream_dc_id_); }
    if (var0 & 32) { s.store_field("record_start_date", record_start_date_); }
    if (var0 & 128) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 1024) { s.store_field("unmuted_video_count", unmuted_video_count_); }
    s.store_field("unmuted_video_limit", unmuted_video_limit_);
    s.store_field("version", version_);
    if (var0 & 65536) { s.store_field("invite_link", invite_link_); }
    if (var0 & 1048576) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    if (var0 & 2097152) { s.store_object_field("default_send_as", static_cast<const BaseObject *>(default_send_as_.get())); }
    s.store_class_end();
  }
}

const std::int32_t groupCallStreamChannel::ID;

object_ptr<groupCallStreamChannel> groupCallStreamChannel::fetch(TlBufferParser &p) {
  return make_tl_object<groupCallStreamChannel>(p);
}

groupCallStreamChannel::groupCallStreamChannel(TlBufferParser &p)
  : channel_(TlFetchInt::parse(p))
  , scale_(TlFetchInt::parse(p))
  , last_timestamp_ms_(TlFetchLong::parse(p))
{}

void groupCallStreamChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallStreamChannel");
    s.store_field("channel", channel_);
    s.store_field("scale", scale_);
    s.store_field("last_timestamp_ms", last_timestamp_ms_);
    s.store_class_end();
  }
}

object_ptr<InputAiComposeTone> InputAiComposeTone::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputAiComposeToneDefault::ID:
      return inputAiComposeToneDefault::fetch(p);
    case inputAiComposeToneID::ID:
      return inputAiComposeToneID::fetch(p);
    case inputAiComposeToneSlug::ID:
      return inputAiComposeToneSlug::fetch(p);
    case inputAiComposeToneSingleUse::ID:
      return inputAiComposeToneSingleUse::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputAiComposeToneDefault::inputAiComposeToneDefault(string const &tone_)
  : tone_(tone_)
{}

const std::int32_t inputAiComposeToneDefault::ID;

object_ptr<InputAiComposeTone> inputAiComposeToneDefault::fetch(TlBufferParser &p) {
  return make_tl_object<inputAiComposeToneDefault>(p);
}

inputAiComposeToneDefault::inputAiComposeToneDefault(TlBufferParser &p)
  : tone_(TlFetchString<string>::parse(p))
{}

void inputAiComposeToneDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(tone_, s);
}

void inputAiComposeToneDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(tone_, s);
}

void inputAiComposeToneDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputAiComposeToneDefault");
    s.store_field("tone", tone_);
    s.store_class_end();
  }
}

inputAiComposeToneID::inputAiComposeToneID(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputAiComposeToneID::ID;

object_ptr<InputAiComposeTone> inputAiComposeToneID::fetch(TlBufferParser &p) {
  return make_tl_object<inputAiComposeToneID>(p);
}

inputAiComposeToneID::inputAiComposeToneID(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputAiComposeToneID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputAiComposeToneID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputAiComposeToneID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputAiComposeToneID");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputAiComposeToneSlug::inputAiComposeToneSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputAiComposeToneSlug::ID;

object_ptr<InputAiComposeTone> inputAiComposeToneSlug::fetch(TlBufferParser &p) {
  return make_tl_object<inputAiComposeToneSlug>(p);
}

inputAiComposeToneSlug::inputAiComposeToneSlug(TlBufferParser &p)
  : slug_(TlFetchString<string>::parse(p))
{}

void inputAiComposeToneSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputAiComposeToneSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputAiComposeToneSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputAiComposeToneSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

inputAiComposeToneSingleUse::inputAiComposeToneSingleUse(string const &custom_prompt_)
  : custom_prompt_(custom_prompt_)
{}

const std::int32_t inputAiComposeToneSingleUse::ID;

object_ptr<InputAiComposeTone> inputAiComposeToneSingleUse::fetch(TlBufferParser &p) {
  return make_tl_object<inputAiComposeToneSingleUse>(p);
}

inputAiComposeToneSingleUse::inputAiComposeToneSingleUse(TlBufferParser &p)
  : custom_prompt_(TlFetchString<string>::parse(p))
{}

void inputAiComposeToneSingleUse::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(custom_prompt_, s);
}

void inputAiComposeToneSingleUse::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(custom_prompt_, s);
}

void inputAiComposeToneSingleUse::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputAiComposeToneSingleUse");
    s.store_field("custom_prompt", custom_prompt_);
    s.store_class_end();
  }
}

object_ptr<InputBotInlineMessageID> InputBotInlineMessageID::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputBotInlineMessageID::ID:
      return inputBotInlineMessageID::fetch(p);
    case inputBotInlineMessageID64::ID:
      return inputBotInlineMessageID64::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputBotInlineMessageID::inputBotInlineMessageID(int32 dc_id_, int64 id_, int64 access_hash_)
  : dc_id_(dc_id_)
  , id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputBotInlineMessageID::ID;

object_ptr<InputBotInlineMessageID> inputBotInlineMessageID::fetch(TlBufferParser &p) {
  return make_tl_object<inputBotInlineMessageID>(p);
}

inputBotInlineMessageID::inputBotInlineMessageID(TlBufferParser &p)
  : dc_id_(TlFetchInt::parse(p))
  , id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputBotInlineMessageID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(dc_id_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotInlineMessageID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(dc_id_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotInlineMessageID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageID");
    s.store_field("dc_id", dc_id_);
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputBotInlineMessageID64::inputBotInlineMessageID64(int32 dc_id_, int64 owner_id_, int32 id_, int64 access_hash_)
  : dc_id_(dc_id_)
  , owner_id_(owner_id_)
  , id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputBotInlineMessageID64::ID;

object_ptr<InputBotInlineMessageID> inputBotInlineMessageID64::fetch(TlBufferParser &p) {
  return make_tl_object<inputBotInlineMessageID64>(p);
}

inputBotInlineMessageID64::inputBotInlineMessageID64(TlBufferParser &p)
  : dc_id_(TlFetchInt::parse(p))
  , owner_id_(TlFetchLong::parse(p))
  , id_(TlFetchInt::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputBotInlineMessageID64::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(dc_id_, s);
  TlStoreBinary::store(owner_id_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotInlineMessageID64::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(dc_id_, s);
  TlStoreBinary::store(owner_id_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotInlineMessageID64::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageID64");
    s.store_field("dc_id", dc_id_);
    s.store_field("owner_id", owner_id_);
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputBusinessAwayMessage::inputBusinessAwayMessage(int32 flags_, bool offline_only_, int32 shortcut_id_, object_ptr<BusinessAwayMessageSchedule> &&schedule_, object_ptr<inputBusinessRecipients> &&recipients_)
  : flags_(flags_)
  , offline_only_(offline_only_)
  , shortcut_id_(shortcut_id_)
  , schedule_(std::move(schedule_))
  , recipients_(std::move(recipients_))
{}

const std::int32_t inputBusinessAwayMessage::ID;

void inputBusinessAwayMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (offline_only_ << 0)), s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(schedule_, s);
  TlStoreBoxed<TlStoreObject, 1871393450>::store(recipients_, s);
}

void inputBusinessAwayMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (offline_only_ << 0)), s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(schedule_, s);
  TlStoreBoxed<TlStoreObject, 1871393450>::store(recipients_, s);
}

void inputBusinessAwayMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessAwayMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (offline_only_ << 0)));
    if (var0 & 1) { s.store_field("offline_only", true); }
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("schedule", static_cast<const BaseObject *>(schedule_.get()));
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_class_end();
  }
}

object_ptr<InputChannel> InputChannel::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputChannelEmpty::ID:
      return inputChannelEmpty::fetch(p);
    case inputChannel::ID:
      return inputChannel::fetch(p);
    case inputChannelFromMessage::ID:
      return inputChannelFromMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputChannelEmpty::ID;

object_ptr<InputChannel> inputChannelEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputChannelEmpty>();
}

void inputChannelEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputChannelEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputChannelEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChannelEmpty");
    s.store_class_end();
  }
}

inputChannel::inputChannel(int64 channel_id_, int64 access_hash_)
  : channel_id_(channel_id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputChannel::ID;

object_ptr<InputChannel> inputChannel::fetch(TlBufferParser &p) {
  return make_tl_object<inputChannel>(p);
}

inputChannel::inputChannel(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChannel");
    s.store_field("channel_id", channel_id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputChannelFromMessage::inputChannelFromMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 channel_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , channel_id_(channel_id_)
{}

const std::int32_t inputChannelFromMessage::ID;

object_ptr<InputChannel> inputChannelFromMessage::fetch(TlBufferParser &p) {
  return make_tl_object<inputChannelFromMessage>(p);
}

inputChannelFromMessage::inputChannelFromMessage(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , channel_id_(TlFetchLong::parse(p))
{}

void inputChannelFromMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(channel_id_, s);
}

void inputChannelFromMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(channel_id_, s);
}

void inputChannelFromMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChannelFromMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("channel_id", channel_id_);
    s.store_class_end();
  }
}

inputPhoneContact::inputPhoneContact(int32 flags_, int64 client_id_, string const &phone_, string const &first_name_, string const &last_name_, object_ptr<textWithEntities> &&note_)
  : flags_(flags_)
  , client_id_(client_id_)
  , phone_(phone_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , note_(std::move(note_))
{}

const std::int32_t inputPhoneContact::ID;

void inputPhoneContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((note_ != nullptr) << 0)), s);
  TlStoreBinary::store(client_id_, s);
  TlStoreString::store(phone_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s); }
}

void inputPhoneContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((note_ != nullptr) << 0)), s);
  TlStoreBinary::store(client_id_, s);
  TlStoreString::store(phone_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s); }
}

void inputPhoneContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhoneContact");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((note_ != nullptr) << 0)));
    s.store_field("client_id", client_id_);
    s.store_field("phone", phone_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    if (var0 & 1) { s.store_object_field("note", static_cast<const BaseObject *>(note_.get())); }
    s.store_class_end();
  }
}

inputMessageReadMetric::inputMessageReadMetric(int32 msg_id_, int64 view_id_, int32 time_in_view_ms_, int32 active_time_in_view_ms_, int32 height_to_viewport_ratio_permille_, int32 seen_range_ratio_permille_)
  : msg_id_(msg_id_)
  , view_id_(view_id_)
  , time_in_view_ms_(time_in_view_ms_)
  , active_time_in_view_ms_(active_time_in_view_ms_)
  , height_to_viewport_ratio_permille_(height_to_viewport_ratio_permille_)
  , seen_range_ratio_permille_(seen_range_ratio_permille_)
{}

const std::int32_t inputMessageReadMetric::ID;

void inputMessageReadMetric::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(view_id_, s);
  TlStoreBinary::store(time_in_view_ms_, s);
  TlStoreBinary::store(active_time_in_view_ms_, s);
  TlStoreBinary::store(height_to_viewport_ratio_permille_, s);
  TlStoreBinary::store(seen_range_ratio_permille_, s);
}

void inputMessageReadMetric::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(view_id_, s);
  TlStoreBinary::store(time_in_view_ms_, s);
  TlStoreBinary::store(active_time_in_view_ms_, s);
  TlStoreBinary::store(height_to_viewport_ratio_permille_, s);
  TlStoreBinary::store(seen_range_ratio_permille_, s);
}

void inputMessageReadMetric::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageReadMetric");
    s.store_field("msg_id", msg_id_);
    s.store_field("view_id", view_id_);
    s.store_field("time_in_view_ms", time_in_view_ms_);
    s.store_field("active_time_in_view_ms", active_time_in_view_ms_);
    s.store_field("height_to_viewport_ratio_permille", height_to_viewport_ratio_permille_);
    s.store_field("seen_range_ratio_permille", seen_range_ratio_permille_);
    s.store_class_end();
  }
}

inputPasskeyCredentialPublicKey::inputPasskeyCredentialPublicKey(string const &id_, string const &raw_id_, object_ptr<InputPasskeyResponse> &&response_)
  : id_(id_)
  , raw_id_(raw_id_)
  , response_(std::move(response_))
{}

const std::int32_t inputPasskeyCredentialPublicKey::ID;

void inputPasskeyCredentialPublicKey::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(raw_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(response_, s);
}

void inputPasskeyCredentialPublicKey::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(raw_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(response_, s);
}

void inputPasskeyCredentialPublicKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPasskeyCredentialPublicKey");
    s.store_field("id", id_);
    s.store_field("raw_id", raw_id_);
    s.store_object_field("response", static_cast<const BaseObject *>(response_.get()));
    s.store_class_end();
  }
}

inputPeerNotifySettings::inputPeerNotifySettings(int32 flags_, bool show_previews_, bool silent_, int32 mute_until_, object_ptr<NotificationSound> &&sound_, bool stories_muted_, bool stories_hide_sender_, object_ptr<NotificationSound> &&stories_sound_)
  : flags_(flags_)
  , show_previews_(show_previews_)
  , silent_(silent_)
  , mute_until_(mute_until_)
  , sound_(std::move(sound_))
  , stories_muted_(stories_muted_)
  , stories_hide_sender_(stories_hide_sender_)
  , stories_sound_(std::move(stories_sound_))
{}

const std::int32_t inputPeerNotifySettings::ID;

void inputPeerNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((sound_ != nullptr) << 3) | ((stories_sound_ != nullptr) << 8)), s);
  if (var0 & 1) { TlStoreBool::store(show_previews_, s); }
  if (var0 & 2) { TlStoreBool::store(silent_, s); }
  if (var0 & 4) { TlStoreBinary::store(mute_until_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(sound_, s); }
  if (var0 & 64) { TlStoreBool::store(stories_muted_, s); }
  if (var0 & 128) { TlStoreBool::store(stories_hide_sender_, s); }
  if (var0 & 256) { TlStoreBoxedUnknown<TlStoreObject>::store(stories_sound_, s); }
}

void inputPeerNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((sound_ != nullptr) << 3) | ((stories_sound_ != nullptr) << 8)), s);
  if (var0 & 1) { TlStoreBool::store(show_previews_, s); }
  if (var0 & 2) { TlStoreBool::store(silent_, s); }
  if (var0 & 4) { TlStoreBinary::store(mute_until_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(sound_, s); }
  if (var0 & 64) { TlStoreBool::store(stories_muted_, s); }
  if (var0 & 128) { TlStoreBool::store(stories_hide_sender_, s); }
  if (var0 & 256) { TlStoreBoxedUnknown<TlStoreObject>::store(stories_sound_, s); }
}

void inputPeerNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerNotifySettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((sound_ != nullptr) << 3) | ((stories_sound_ != nullptr) << 8)));
    if (var0 & 1) { s.store_field("show_previews", show_previews_); }
    if (var0 & 2) { s.store_field("silent", silent_); }
    if (var0 & 4) { s.store_field("mute_until", mute_until_); }
    if (var0 & 8) { s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get())); }
    if (var0 & 64) { s.store_field("stories_muted", stories_muted_); }
    if (var0 & 128) { s.store_field("stories_hide_sender", stories_hide_sender_); }
    if (var0 & 256) { s.store_object_field("stories_sound", static_cast<const BaseObject *>(stories_sound_.get())); }
    s.store_class_end();
  }
}

inputTheme::inputTheme(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputTheme::ID;

void inputTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputTheme");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputThemeSlug::inputThemeSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputThemeSlug::ID;

void inputThemeSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputThemeSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputThemeSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputThemeSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

inputTonConnectOauthSession::inputTonConnectOauthSession(int64 session_id_, bytes &&challenge_answer_, bytes &&body_, object_ptr<walletOwnershipProof> &&proof_)
  : session_id_(session_id_)
  , challenge_answer_(std::move(challenge_answer_))
  , body_(std::move(body_))
  , proof_(std::move(proof_))
{}

const std::int32_t inputTonConnectOauthSession::ID;

void inputTonConnectOauthSession::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(session_id_, s);
  TlStoreString::store(challenge_answer_, s);
  TlStoreString::store(body_, s);
  TlStoreBoxed<TlStoreObject, 1622985485>::store(proof_, s);
}

void inputTonConnectOauthSession::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(session_id_, s);
  TlStoreString::store(challenge_answer_, s);
  TlStoreString::store(body_, s);
  TlStoreBoxed<TlStoreObject, 1622985485>::store(proof_, s);
}

void inputTonConnectOauthSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputTonConnectOauthSession");
    s.store_field("session_id", session_id_);
    s.store_bytes_field("challenge_answer", challenge_answer_);
    s.store_bytes_field("body", body_);
    s.store_object_field("proof", static_cast<const BaseObject *>(proof_.get()));
    s.store_class_end();
  }
}

const std::int32_t inputWalletNew::ID;

void inputWalletNew::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputWalletNew::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputWalletNew::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWalletNew");
    s.store_class_end();
  }
}

inputWalletImported::inputWalletImported(int32 flags_, bytes &&public_key_, bytes &&anchor_public_key_, object_ptr<walletOwnershipProof> &&proof_)
  : flags_(flags_)
  , public_key_(std::move(public_key_))
  , anchor_public_key_(std::move(anchor_public_key_))
  , proof_(std::move(proof_))
{}

const std::int32_t inputWalletImported::ID;

void inputWalletImported::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!anchor_public_key_.empty()) << 0)), s);
  TlStoreString::store(public_key_, s);
  if (var0 & 1) { TlStoreString::store(anchor_public_key_, s); }
  TlStoreBoxed<TlStoreObject, 1622985485>::store(proof_, s);
}

void inputWalletImported::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!anchor_public_key_.empty()) << 0)), s);
  TlStoreString::store(public_key_, s);
  if (var0 & 1) { TlStoreString::store(anchor_public_key_, s); }
  TlStoreBoxed<TlStoreObject, 1622985485>::store(proof_, s);
}

void inputWalletImported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWalletImported");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!anchor_public_key_.empty()) << 0)));
    s.store_bytes_field("public_key", public_key_);
    if (var0 & 1) { s.store_bytes_field("anchor_public_key", anchor_public_key_); }
    s.store_object_field("proof", static_cast<const BaseObject *>(proof_.get()));
    s.store_class_end();
  }
}

keyboardInlineButtonRow::keyboardInlineButtonRow(array<object_ptr<keyboardInlineButton>> &&buttons_)
  : buttons_(std::move(buttons_))
{}

const std::int32_t keyboardInlineButtonRow::ID;

object_ptr<keyboardInlineButtonRow> keyboardInlineButtonRow::fetch(TlBufferParser &p) {
  return make_tl_object<keyboardInlineButtonRow>(p);
}

keyboardInlineButtonRow::keyboardInlineButtonRow(TlBufferParser &p)
  : buttons_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<keyboardInlineButton>, 297902882>>, 481674261>::parse(p))
{}

void keyboardInlineButtonRow::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 297902882>>, 481674261>::store(buttons_, s);
}

void keyboardInlineButtonRow::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 297902882>>, 481674261>::store(buttons_, s);
}

void keyboardInlineButtonRow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardInlineButtonRow");
    { s.store_vector_begin("buttons", buttons_.size()); for (const auto &_value : buttons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

labeledPrice::labeledPrice(string const &label_, int64 amount_)
  : label_(label_)
  , amount_(amount_)
{}

const std::int32_t labeledPrice::ID;

object_ptr<labeledPrice> labeledPrice::fetch(TlBufferParser &p) {
  return make_tl_object<labeledPrice>(p);
}

labeledPrice::labeledPrice(TlBufferParser &p)
  : label_(TlFetchString<string>::parse(p))
  , amount_(TlFetchLong::parse(p))
{}

void labeledPrice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(label_, s);
  TlStoreBinary::store(amount_, s);
}

void labeledPrice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(label_, s);
  TlStoreBinary::store(amount_, s);
}

void labeledPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "labeledPrice");
    s.store_field("label", label_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

object_ptr<MessageReplyHeader> MessageReplyHeader::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messageReplyHeader::ID:
      return messageReplyHeader::fetch(p);
    case messageReplyStoryHeader::ID:
      return messageReplyStoryHeader::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messageReplyHeader::messageReplyHeader()
  : flags_()
  , reply_to_scheduled_()
  , forum_topic_()
  , quote_()
  , reply_to_ephemeral_()
  , reply_to_msg_id_()
  , reply_to_peer_id_()
  , reply_from_()
  , reply_media_()
  , reply_to_top_id_()
  , quote_text_()
  , quote_entities_()
  , quote_offset_()
  , todo_item_id_()
  , poll_option_()
  , quote_rich_()
{}

const std::int32_t messageReplyHeader::ID;

object_ptr<MessageReplyHeader> messageReplyHeader::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageReplyHeader> res = make_tl_object<messageReplyHeader>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->reply_to_scheduled_ = (var0 & 4) != 0;
  res->forum_topic_ = (var0 & 8) != 0;
  res->quote_ = (var0 & 512) != 0;
  res->reply_to_ephemeral_ = (var0 & 8192) != 0;
  if (var0 & 16) { res->reply_to_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->reply_to_peer_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 32) { res->reply_from_ = TlFetchBoxed<TlFetchObject<messageFwdHeader>, 1313731771>::parse(p); }
  if (var0 & 256) { res->reply_media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (var0 & 2) { res->reply_to_top_id_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->quote_text_ = TlFetchString<string>::parse(p); }
  if (var0 & 128) { res->quote_entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 1024) { res->quote_offset_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->todo_item_id_ = TlFetchInt::parse(p); }
  if (var0 & 4096) { res->poll_option_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 16384) { res->quote_rich_ = TlFetchBoxed<TlFetchVector<TlFetchObject<RichText>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageReplyHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplyHeader");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (reply_to_scheduled_ << 2) | (forum_topic_ << 3) | (quote_ << 9) | (reply_to_ephemeral_ << 13) | ((reply_to_peer_id_ != nullptr) << 0) | ((reply_from_ != nullptr) << 5) | ((reply_media_ != nullptr) << 8) | ((!quote_text_.empty()) << 6) | ((!quote_entities_.empty()) << 7) | ((!poll_option_.empty()) << 12) | ((!quote_rich_.empty()) << 14)));
    if (var0 & 4) { s.store_field("reply_to_scheduled", true); }
    if (var0 & 8) { s.store_field("forum_topic", true); }
    if (var0 & 512) { s.store_field("quote", true); }
    if (var0 & 8192) { s.store_field("reply_to_ephemeral", true); }
    if (var0 & 16) { s.store_field("reply_to_msg_id", reply_to_msg_id_); }
    if (var0 & 1) { s.store_object_field("reply_to_peer_id", static_cast<const BaseObject *>(reply_to_peer_id_.get())); }
    if (var0 & 32) { s.store_object_field("reply_from", static_cast<const BaseObject *>(reply_from_.get())); }
    if (var0 & 256) { s.store_object_field("reply_media", static_cast<const BaseObject *>(reply_media_.get())); }
    if (var0 & 2) { s.store_field("reply_to_top_id", reply_to_top_id_); }
    if (var0 & 64) { s.store_field("quote_text", quote_text_); }
    if (var0 & 128) { { s.store_vector_begin("quote_entities", quote_entities_.size()); for (const auto &_value : quote_entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1024) { s.store_field("quote_offset", quote_offset_); }
    if (var0 & 2048) { s.store_field("todo_item_id", todo_item_id_); }
    if (var0 & 4096) { s.store_bytes_field("poll_option", poll_option_); }
    if (var0 & 16384) { { s.store_vector_begin("quote_rich", quote_rich_.size()); for (const auto &_value : quote_rich_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t messageReplyStoryHeader::ID;

object_ptr<MessageReplyHeader> messageReplyStoryHeader::fetch(TlBufferParser &p) {
  return make_tl_object<messageReplyStoryHeader>(p);
}

messageReplyStoryHeader::messageReplyStoryHeader(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , story_id_(TlFetchInt::parse(p))
{}

void messageReplyStoryHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplyStoryHeader");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

const std::int32_t messageReportOption::ID;

object_ptr<messageReportOption> messageReportOption::fetch(TlBufferParser &p) {
  return make_tl_object<messageReportOption>(p);
}

messageReportOption::messageReportOption(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , option_(TlFetchBytes<bytes>::parse(p))
{}

void messageReportOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReportOption");
    s.store_field("text", text_);
    s.store_bytes_field("option", option_);
    s.store_class_end();
  }
}

const std::int32_t nearestDc::ID;

object_ptr<nearestDc> nearestDc::fetch(TlBufferParser &p) {
  return make_tl_object<nearestDc>(p);
}

nearestDc::nearestDc(TlBufferParser &p)
  : country_(TlFetchString<string>::parse(p))
  , this_dc_(TlFetchInt::parse(p))
  , nearest_dc_(TlFetchInt::parse(p))
{}

void nearestDc::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "nearestDc");
    s.store_field("country", country_);
    s.store_field("this_dc", this_dc_);
    s.store_field("nearest_dc", nearest_dc_);
    s.store_class_end();
  }
}

const std::int32_t paymentSavedCredentialsCard::ID;

object_ptr<paymentSavedCredentialsCard> paymentSavedCredentialsCard::fetch(TlBufferParser &p) {
  return make_tl_object<paymentSavedCredentialsCard>(p);
}

paymentSavedCredentialsCard::paymentSavedCredentialsCard(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , title_(TlFetchString<string>::parse(p))
{}

void paymentSavedCredentialsCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentSavedCredentialsCard");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

phoneCallProtocol::phoneCallProtocol()
  : flags_()
  , udp_p2p_()
  , udp_reflector_()
  , min_layer_()
  , max_layer_()
  , library_versions_()
{}

phoneCallProtocol::phoneCallProtocol(int32 flags_, bool udp_p2p_, bool udp_reflector_, int32 min_layer_, int32 max_layer_, array<string> &&library_versions_)
  : flags_(flags_)
  , udp_p2p_(udp_p2p_)
  , udp_reflector_(udp_reflector_)
  , min_layer_(min_layer_)
  , max_layer_(max_layer_)
  , library_versions_(std::move(library_versions_))
{}

const std::int32_t phoneCallProtocol::ID;

object_ptr<phoneCallProtocol> phoneCallProtocol::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCallProtocol> res = make_tl_object<phoneCallProtocol>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->udp_p2p_ = (var0 & 1) != 0;
  res->udp_reflector_ = (var0 & 2) != 0;
  res->min_layer_ = TlFetchInt::parse(p);
  res->max_layer_ = TlFetchInt::parse(p);
  res->library_versions_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void phoneCallProtocol::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (udp_p2p_ << 0) | (udp_reflector_ << 1)), s);
  TlStoreBinary::store(min_layer_, s);
  TlStoreBinary::store(max_layer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(library_versions_, s);
}

void phoneCallProtocol::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (udp_p2p_ << 0) | (udp_reflector_ << 1)), s);
  TlStoreBinary::store(min_layer_, s);
  TlStoreBinary::store(max_layer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(library_versions_, s);
}

void phoneCallProtocol::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallProtocol");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (udp_p2p_ << 0) | (udp_reflector_ << 1)));
    if (var0 & 1) { s.store_field("udp_p2p", true); }
    if (var0 & 2) { s.store_field("udp_reflector", true); }
    s.store_field("min_layer", min_layer_);
    s.store_field("max_layer", max_layer_);
    { s.store_vector_begin("library_versions", library_versions_.size()); for (const auto &_value : library_versions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<PollAnswer> PollAnswer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case pollAnswer::ID:
      return pollAnswer::fetch(p);
    case inputPollAnswer::ID:
      return inputPollAnswer::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

pollAnswer::pollAnswer()
  : flags_()
  , text_()
  , option_()
  , media_()
  , added_by_()
  , date_()
{}

pollAnswer::pollAnswer(int32 flags_, object_ptr<textWithEntities> &&text_, bytes &&option_, object_ptr<MessageMedia> &&media_, object_ptr<Peer> &&added_by_, int32 date_)
  : flags_(flags_)
  , text_(std::move(text_))
  , option_(std::move(option_))
  , media_(std::move(media_))
  , added_by_(std::move(added_by_))
  , date_(date_)
{}

const std::int32_t pollAnswer::ID;

object_ptr<PollAnswer> pollAnswer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pollAnswer> res = make_tl_object<pollAnswer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->text_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  res->option_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 1) { res->media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (var0 & 2) { res->added_by_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2) { res->date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pollAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((media_ != nullptr) << 0) | ((added_by_ != nullptr) << 1)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  TlStoreString::store(option_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(added_by_, s); }
  if (var0 & 2) { TlStoreBinary::store(date_, s); }
}

void pollAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((media_ != nullptr) << 0) | ((added_by_ != nullptr) << 1)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  TlStoreString::store(option_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(added_by_, s); }
  if (var0 & 2) { TlStoreBinary::store(date_, s); }
}

void pollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollAnswer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((media_ != nullptr) << 0) | ((added_by_ != nullptr) << 1)));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_bytes_field("option", option_);
    if (var0 & 1) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 2) { s.store_object_field("added_by", static_cast<const BaseObject *>(added_by_.get())); }
    if (var0 & 2) { s.store_field("date", date_); }
    s.store_class_end();
  }
}

inputPollAnswer::inputPollAnswer()
  : flags_()
  , text_()
  , media_()
{}

inputPollAnswer::inputPollAnswer(int32 flags_, object_ptr<textWithEntities> &&text_, object_ptr<InputMedia> &&media_)
  : flags_(flags_)
  , text_(std::move(text_))
  , media_(std::move(media_))
{}

const std::int32_t inputPollAnswer::ID;

object_ptr<PollAnswer> inputPollAnswer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputPollAnswer> res = make_tl_object<inputPollAnswer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->text_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 1) { res->media_ = TlFetchObject<InputMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputPollAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((media_ != nullptr) << 0)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
}

void inputPollAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((media_ != nullptr) << 0)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
}

void inputPollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollAnswer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((media_ != nullptr) << 0)));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    if (var0 & 1) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    s.store_class_end();
  }
}

object_ptr<PublicForward> PublicForward::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case publicForwardMessage::ID:
      return publicForwardMessage::fetch(p);
    case publicForwardStory::ID:
      return publicForwardStory::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t publicForwardMessage::ID;

object_ptr<PublicForward> publicForwardMessage::fetch(TlBufferParser &p) {
  return make_tl_object<publicForwardMessage>(p);
}

publicForwardMessage::publicForwardMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void publicForwardMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicForwardMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t publicForwardStory::ID;

object_ptr<PublicForward> publicForwardStory::fetch(TlBufferParser &p) {
  return make_tl_object<publicForwardStory>(p);
}

publicForwardStory::publicForwardStory(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , story_(TlFetchObject<StoryItem>::parse(p))
{}

void publicForwardStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicForwardStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

richMessage::richMessage()
  : flags_()
  , rtl_()
  , part_()
  , blocks_()
  , photos_()
  , documents_()
{}

richMessage::richMessage(int32 flags_, bool rtl_, bool part_, array<object_ptr<PageBlock>> &&blocks_, array<object_ptr<Photo>> &&photos_, array<object_ptr<Document>> &&documents_)
  : flags_(flags_)
  , rtl_(rtl_)
  , part_(part_)
  , blocks_(std::move(blocks_))
  , photos_(std::move(photos_))
  , documents_(std::move(documents_))
{}

const std::int32_t richMessage::ID;

object_ptr<richMessage> richMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<richMessage> res = make_tl_object<richMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->rtl_ = (var0 & 1) != 0;
  res->part_ = (var0 & 2) != 0;
  res->blocks_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p);
  res->photos_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Photo>>, 481674261>::parse(p);
  res->documents_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void richMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtl_ << 0) | (part_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(photos_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s);
}

void richMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtl_ << 0) | (part_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(photos_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s);
}

void richMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (rtl_ << 0) | (part_ << 1)));
    if (var0 & 1) { s.store_field("rtl", true); }
    if (var0 & 2) { s.store_field("part", true); }
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("photos", photos_.size()); for (const auto &_value : photos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t searchResultPosition::ID;

object_ptr<searchResultPosition> searchResultPosition::fetch(TlBufferParser &p) {
  return make_tl_object<searchResultPosition>(p);
}

searchResultPosition::searchResultPosition(TlBufferParser &p)
  : msg_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , offset_(TlFetchInt::parse(p))
{}

void searchResultPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchResultPosition");
    s.store_field("msg_id", msg_id_);
    s.store_field("date", date_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

secureSecretSettings::secureSecretSettings(object_ptr<SecurePasswordKdfAlgo> &&secure_algo_, bytes &&secure_secret_, int64 secure_secret_id_)
  : secure_algo_(std::move(secure_algo_))
  , secure_secret_(std::move(secure_secret_))
  , secure_secret_id_(secure_secret_id_)
{}

const std::int32_t secureSecretSettings::ID;

object_ptr<secureSecretSettings> secureSecretSettings::fetch(TlBufferParser &p) {
  return make_tl_object<secureSecretSettings>(p);
}

secureSecretSettings::secureSecretSettings(TlBufferParser &p)
  : secure_algo_(TlFetchObject<SecurePasswordKdfAlgo>::parse(p))
  , secure_secret_(TlFetchBytes<bytes>::parse(p))
  , secure_secret_id_(TlFetchLong::parse(p))
{}

void secureSecretSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(secure_algo_, s);
  TlStoreString::store(secure_secret_, s);
  TlStoreBinary::store(secure_secret_id_, s);
}

void secureSecretSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(secure_algo_, s);
  TlStoreString::store(secure_secret_, s);
  TlStoreBinary::store(secure_secret_id_, s);
}

void secureSecretSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureSecretSettings");
    s.store_object_field("secure_algo", static_cast<const BaseObject *>(secure_algo_.get()));
    s.store_field("secure_secret", "[REDACTED]");
    s.store_field("secure_secret_id", secure_secret_id_);
    s.store_class_end();
  }
}

shippingOption::shippingOption(string const &id_, string const &title_, array<object_ptr<labeledPrice>> &&prices_)
  : id_(id_)
  , title_(title_)
  , prices_(std::move(prices_))
{}

const std::int32_t shippingOption::ID;

object_ptr<shippingOption> shippingOption::fetch(TlBufferParser &p) {
  return make_tl_object<shippingOption>(p);
}

shippingOption::shippingOption(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , title_(TlFetchString<string>::parse(p))
  , prices_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<labeledPrice>, -886477832>>, 481674261>::parse(p))
{}

void shippingOption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -886477832>>, 481674261>::store(prices_, s);
}

void shippingOption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -886477832>>, 481674261>::store(prices_, s);
}

void shippingOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shippingOption");
    s.store_field("id", id_);
    s.store_field("title", title_);
    { s.store_vector_begin("prices", prices_.size()); for (const auto &_value : prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<StarsAmount> StarsAmount::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starsAmount::ID:
      return starsAmount::fetch(p);
    case starsTonAmount::ID:
      return starsTonAmount::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

starsAmount::starsAmount(int64 amount_, int32 nanos_)
  : amount_(amount_)
  , nanos_(nanos_)
{}

const std::int32_t starsAmount::ID;

object_ptr<StarsAmount> starsAmount::fetch(TlBufferParser &p) {
  return make_tl_object<starsAmount>(p);
}

starsAmount::starsAmount(TlBufferParser &p)
  : amount_(TlFetchLong::parse(p))
  , nanos_(TlFetchInt::parse(p))
{}

void starsAmount::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(amount_, s);
  TlStoreBinary::store(nanos_, s);
}

void starsAmount::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(amount_, s);
  TlStoreBinary::store(nanos_, s);
}

void starsAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsAmount");
    s.store_field("amount", amount_);
    s.store_field("nanos", nanos_);
    s.store_class_end();
  }
}

starsTonAmount::starsTonAmount(int64 amount_)
  : amount_(amount_)
{}

const std::int32_t starsTonAmount::ID;

object_ptr<StarsAmount> starsTonAmount::fetch(TlBufferParser &p) {
  return make_tl_object<starsTonAmount>(p);
}

starsTonAmount::starsTonAmount(TlBufferParser &p)
  : amount_(TlFetchLong::parse(p))
{}

void starsTonAmount::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(amount_, s);
}

void starsTonAmount::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(amount_, s);
}

void starsTonAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTonAmount");
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

starsGiveawayWinnersOption::starsGiveawayWinnersOption()
  : flags_()
  , default_()
  , users_()
  , per_user_stars_()
{}

const std::int32_t starsGiveawayWinnersOption::ID;

object_ptr<starsGiveawayWinnersOption> starsGiveawayWinnersOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsGiveawayWinnersOption> res = make_tl_object<starsGiveawayWinnersOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->default_ = (var0 & 1) != 0;
  res->users_ = TlFetchInt::parse(p);
  res->per_user_stars_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsGiveawayWinnersOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsGiveawayWinnersOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (default_ << 0)));
    if (var0 & 1) { s.store_field("default", true); }
    s.store_field("users", users_);
    s.store_field("per_user_stars", per_user_stars_);
    s.store_class_end();
  }
}

object_ptr<StickerSetCovered> StickerSetCovered::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case stickerSetCovered::ID:
      return stickerSetCovered::fetch(p);
    case stickerSetMultiCovered::ID:
      return stickerSetMultiCovered::fetch(p);
    case stickerSetFullCovered::ID:
      return stickerSetFullCovered::fetch(p);
    case stickerSetNoCovered::ID:
      return stickerSetNoCovered::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t stickerSetCovered::ID;

object_ptr<StickerSetCovered> stickerSetCovered::fetch(TlBufferParser &p) {
  return make_tl_object<stickerSetCovered>(p);
}

stickerSetCovered::stickerSetCovered(TlBufferParser &p)
  : set_(TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p))
  , cover_(TlFetchObject<Document>::parse(p))
{}

void stickerSetCovered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSetCovered");
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_class_end();
  }
}

const std::int32_t stickerSetMultiCovered::ID;

object_ptr<StickerSetCovered> stickerSetMultiCovered::fetch(TlBufferParser &p) {
  return make_tl_object<stickerSetMultiCovered>(p);
}

stickerSetMultiCovered::stickerSetMultiCovered(TlBufferParser &p)
  : set_(TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p))
  , covers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void stickerSetMultiCovered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSetMultiCovered");
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    { s.store_vector_begin("covers", covers_.size()); for (const auto &_value : covers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stickerSetFullCovered::ID;

object_ptr<StickerSetCovered> stickerSetFullCovered::fetch(TlBufferParser &p) {
  return make_tl_object<stickerSetFullCovered>(p);
}

stickerSetFullCovered::stickerSetFullCovered(TlBufferParser &p)
  : set_(TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p))
  , packs_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerPack>, 313694676>>, 481674261>::parse(p))
  , keywords_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerKeyword>, -50416996>>, 481674261>::parse(p))
  , documents_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void stickerSetFullCovered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSetFullCovered");
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    { s.store_vector_begin("packs", packs_.size()); for (const auto &_value : packs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("keywords", keywords_.size()); for (const auto &_value : keywords_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stickerSetNoCovered::ID;

object_ptr<StickerSetCovered> stickerSetNoCovered::fetch(TlBufferParser &p) {
  return make_tl_object<stickerSetNoCovered>(p);
}

stickerSetNoCovered::stickerSetNoCovered(TlBufferParser &p)
  : set_(TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p))
{}

void stickerSetNoCovered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSetNoCovered");
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    s.store_class_end();
  }
}

storyViews::storyViews()
  : flags_()
  , has_viewers_()
  , views_count_()
  , forwards_count_()
  , reactions_()
  , reactions_count_()
  , recent_viewers_()
{}

storyViews::storyViews(int32 flags_, bool has_viewers_, int32 views_count_, int32 forwards_count_, array<object_ptr<reactionCount>> &&reactions_, int32 reactions_count_, array<int64> &&recent_viewers_)
  : flags_(flags_)
  , has_viewers_(has_viewers_)
  , views_count_(views_count_)
  , forwards_count_(forwards_count_)
  , reactions_(std::move(reactions_))
  , reactions_count_(reactions_count_)
  , recent_viewers_(std::move(recent_viewers_))
{}

const std::int32_t storyViews::ID;

object_ptr<storyViews> storyViews::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyViews> res = make_tl_object<storyViews>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_viewers_ = (var0 & 2) != 0;
  res->views_count_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->forwards_count_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->reactions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<reactionCount>, -1546531968>>, 481674261>::parse(p); }
  if (var0 & 16) { res->reactions_count_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->recent_viewers_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void storyViews::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_viewers_ << 1) | ((!reactions_.empty()) << 3) | ((!recent_viewers_.empty()) << 0)), s);
  TlStoreBinary::store(views_count_, s);
  if (var0 & 4) { TlStoreBinary::store(forwards_count_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1546531968>>, 481674261>::store(reactions_, s); }
  if (var0 & 16) { TlStoreBinary::store(reactions_count_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(recent_viewers_, s); }
}

void storyViews::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_viewers_ << 1) | ((!reactions_.empty()) << 3) | ((!recent_viewers_.empty()) << 0)), s);
  TlStoreBinary::store(views_count_, s);
  if (var0 & 4) { TlStoreBinary::store(forwards_count_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1546531968>>, 481674261>::store(reactions_, s); }
  if (var0 & 16) { TlStoreBinary::store(reactions_count_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(recent_viewers_, s); }
}

void storyViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyViews");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_viewers_ << 1) | ((!reactions_.empty()) << 3) | ((!recent_viewers_.empty()) << 0)));
    if (var0 & 2) { s.store_field("has_viewers", true); }
    s.store_field("views_count", views_count_);
    if (var0 & 4) { s.store_field("forwards_count", forwards_count_); }
    if (var0 & 8) { { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("reactions_count", reactions_count_); }
    if (var0 & 1) { { s.store_vector_begin("recent_viewers", recent_viewers_.size()); for (const auto &_value : recent_viewers_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

todoCompletion::todoCompletion(int32 id_, object_ptr<Peer> &&completed_by_, int32 date_)
  : id_(id_)
  , completed_by_(std::move(completed_by_))
  , date_(date_)
{}

const std::int32_t todoCompletion::ID;

object_ptr<todoCompletion> todoCompletion::fetch(TlBufferParser &p) {
  return make_tl_object<todoCompletion>(p);
}

todoCompletion::todoCompletion(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , completed_by_(TlFetchObject<Peer>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void todoCompletion::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(completed_by_, s);
  TlStoreBinary::store(date_, s);
}

void todoCompletion::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(completed_by_, s);
  TlStoreBinary::store(date_, s);
}

void todoCompletion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "todoCompletion");
    s.store_field("id", id_);
    s.store_object_field("completed_by", static_cast<const BaseObject *>(completed_by_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

tonConnectManifest::tonConnectManifest()
  : flags_()
  , url_()
  , name_()
  , icon_()
{}

const std::int32_t tonConnectManifest::ID;

object_ptr<tonConnectManifest> tonConnectManifest::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<tonConnectManifest> res = make_tl_object<tonConnectManifest>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->url_ = TlFetchString<string>::parse(p);
  res->name_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->icon_ = TlFetchObject<WebDocument>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void tonConnectManifest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectManifest");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((icon_ != nullptr) << 0)));
    s.store_field("url", url_);
    s.store_field("name", name_);
    if (var0 & 1) { s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get())); }
    s.store_class_end();
  }
}

object_ptr<VideoSize> VideoSize::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case videoSize::ID:
      return videoSize::fetch(p);
    case videoSizeEmojiMarkup::ID:
      return videoSizeEmojiMarkup::fetch(p);
    case videoSizeStickerMarkup::ID:
      return videoSizeStickerMarkup::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

videoSize::videoSize()
  : flags_()
  , type_()
  , w_()
  , h_()
  , size_()
  , video_start_ts_()
{}

videoSize::videoSize(int32 flags_, string const &type_, int32 w_, int32 h_, int32 size_, double video_start_ts_)
  : flags_(flags_)
  , type_(type_)
  , w_(w_)
  , h_(h_)
  , size_(size_)
  , video_start_ts_(video_start_ts_)
{}

const std::int32_t videoSize::ID;

object_ptr<VideoSize> videoSize::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<videoSize> res = make_tl_object<videoSize>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->type_ = TlFetchString<string>::parse(p);
  res->w_ = TlFetchInt::parse(p);
  res->h_ = TlFetchInt::parse(p);
  res->size_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->video_start_ts_ = TlFetchDouble::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void videoSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(size_, s);
  if (var0 & 1) { TlStoreBinary::store(video_start_ts_, s); }
}

void videoSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(size_, s);
  if (var0 & 1) { TlStoreBinary::store(video_start_ts_, s); }
}

void videoSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoSize");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("type", type_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_field("size", size_);
    if (var0 & 1) { s.store_field("video_start_ts", video_start_ts_); }
    s.store_class_end();
  }
}

videoSizeEmojiMarkup::videoSizeEmojiMarkup(int64 emoji_id_, array<int32> &&background_colors_)
  : emoji_id_(emoji_id_)
  , background_colors_(std::move(background_colors_))
{}

const std::int32_t videoSizeEmojiMarkup::ID;

object_ptr<VideoSize> videoSizeEmojiMarkup::fetch(TlBufferParser &p) {
  return make_tl_object<videoSizeEmojiMarkup>(p);
}

videoSizeEmojiMarkup::videoSizeEmojiMarkup(TlBufferParser &p)
  : emoji_id_(TlFetchLong::parse(p))
  , background_colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void videoSizeEmojiMarkup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(emoji_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(background_colors_, s);
}

void videoSizeEmojiMarkup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(emoji_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(background_colors_, s);
}

void videoSizeEmojiMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoSizeEmojiMarkup");
    s.store_field("emoji_id", emoji_id_);
    { s.store_vector_begin("background_colors", background_colors_.size()); for (const auto &_value : background_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

videoSizeStickerMarkup::videoSizeStickerMarkup(object_ptr<InputStickerSet> &&stickerset_, int64 sticker_id_, array<int32> &&background_colors_)
  : stickerset_(std::move(stickerset_))
  , sticker_id_(sticker_id_)
  , background_colors_(std::move(background_colors_))
{}

const std::int32_t videoSizeStickerMarkup::ID;

object_ptr<VideoSize> videoSizeStickerMarkup::fetch(TlBufferParser &p) {
  return make_tl_object<videoSizeStickerMarkup>(p);
}

videoSizeStickerMarkup::videoSizeStickerMarkup(TlBufferParser &p)
  : stickerset_(TlFetchObject<InputStickerSet>::parse(p))
  , sticker_id_(TlFetchLong::parse(p))
  , background_colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void videoSizeStickerMarkup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(sticker_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(background_colors_, s);
}

void videoSizeStickerMarkup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(sticker_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(background_colors_, s);
}

void videoSizeStickerMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoSizeStickerMarkup");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("sticker_id", sticker_id_);
    { s.store_vector_begin("background_colors", background_colors_.size()); for (const auto &_value : background_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

walletOwnershipProof::walletOwnershipProof(int32 timestamp_, bytes &&signature_)
  : timestamp_(timestamp_)
  , signature_(std::move(signature_))
{}

const std::int32_t walletOwnershipProof::ID;

void walletOwnershipProof::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(timestamp_, s);
  TlStoreString::store(signature_, s);
}

void walletOwnershipProof::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(timestamp_, s);
  TlStoreString::store(signature_, s);
}

void walletOwnershipProof::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletOwnershipProof");
    s.store_field("timestamp", timestamp_);
    s.store_bytes_field("signature", signature_);
    s.store_class_end();
  }
}

walletTransaction::walletTransaction()
  : flags_()
  , incoming_()
  , gasless_()
  , failed_()
  , key_change_()
  , comment_encrypted_()
  , suspected_spam_()
  , id_()
  , amount_()
  , fee_()
  , date_()
  , peer_()
  , comment_()
  , tx_hash_()
  , nft_()
{}

const std::int32_t walletTransaction::ID;

object_ptr<walletTransaction> walletTransaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletTransaction> res = make_tl_object<walletTransaction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->incoming_ = (var0 & 1) != 0;
  res->gasless_ = (var0 & 2) != 0;
  res->failed_ = (var0 & 4) != 0;
  res->key_change_ = (var0 & 32) != 0;
  res->comment_encrypted_ = (var0 & 64) != 0;
  res->suspected_spam_ = (var0 & 256) != 0;
  res->id_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->fee_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->peer_ = TlFetchObject<WalletTransactionPeer>::parse(p);
  if (var0 & 8) { res->comment_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->tx_hash_ = TlFetchString<string>::parse(p); }
  if (var0 & 128) { res->nft_ = TlFetchBoxed<TlFetchObject<wallet_nftItem>, 389937907>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void walletTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletTransaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (incoming_ << 0) | (gasless_ << 1) | (failed_ << 2) | (key_change_ << 5) | (comment_encrypted_ << 6) | (suspected_spam_ << 8) | ((!comment_.empty()) << 3) | ((!tx_hash_.empty()) << 4) | ((nft_ != nullptr) << 7)));
    if (var0 & 1) { s.store_field("incoming", true); }
    if (var0 & 2) { s.store_field("gasless", true); }
    if (var0 & 4) { s.store_field("failed", true); }
    if (var0 & 32) { s.store_field("key_change", true); }
    if (var0 & 64) { s.store_field("comment_encrypted", true); }
    if (var0 & 256) { s.store_field("suspected_spam", true); }
    s.store_field("id", id_);
    s.store_field("amount", amount_);
    s.store_field("fee", fee_);
    s.store_field("date", date_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 8) { s.store_field("comment", comment_); }
    if (var0 & 16) { s.store_field("tx_hash", tx_hash_); }
    if (var0 & 128) { s.store_object_field("nft", static_cast<const BaseObject *>(nft_.get())); }
    s.store_class_end();
  }
}

object_ptr<WebDocument> WebDocument::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case webDocument::ID:
      return webDocument::fetch(p);
    case webDocumentNoProxy::ID:
      return webDocumentNoProxy::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

webDocument::webDocument(string const &url_, int64 access_hash_, int32 size_, string const &mime_type_, array<object_ptr<DocumentAttribute>> &&attributes_)
  : url_(url_)
  , access_hash_(access_hash_)
  , size_(size_)
  , mime_type_(mime_type_)
  , attributes_(std::move(attributes_))
{}

const std::int32_t webDocument::ID;

object_ptr<WebDocument> webDocument::fetch(TlBufferParser &p) {
  return make_tl_object<webDocument>(p);
}

webDocument::webDocument(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , size_(TlFetchInt::parse(p))
  , mime_type_(TlFetchString<string>::parse(p))
  , attributes_(TlFetchBoxed<TlFetchVector<TlFetchObject<DocumentAttribute>>, 481674261>::parse(p))
{}

void webDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void webDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void webDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webDocument");
    s.store_field("url", url_);
    s.store_field("access_hash", access_hash_);
    s.store_field("size", size_);
    s.store_field("mime_type", mime_type_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

webDocumentNoProxy::webDocumentNoProxy(string const &url_, int32 size_, string const &mime_type_, array<object_ptr<DocumentAttribute>> &&attributes_)
  : url_(url_)
  , size_(size_)
  , mime_type_(mime_type_)
  , attributes_(std::move(attributes_))
{}

const std::int32_t webDocumentNoProxy::ID;

object_ptr<WebDocument> webDocumentNoProxy::fetch(TlBufferParser &p) {
  return make_tl_object<webDocumentNoProxy>(p);
}

webDocumentNoProxy::webDocumentNoProxy(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , size_(TlFetchInt::parse(p))
  , mime_type_(TlFetchString<string>::parse(p))
  , attributes_(TlFetchBoxed<TlFetchVector<TlFetchObject<DocumentAttribute>>, 481674261>::parse(p))
{}

void webDocumentNoProxy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void webDocumentNoProxy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void webDocumentNoProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webDocumentNoProxy");
    s.store_field("url", url_);
    s.store_field("size", size_);
    s.store_field("mime_type", mime_type_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

webViewMessageSent::webViewMessageSent()
  : flags_()
  , msg_id_()
{}

const std::int32_t webViewMessageSent::ID;

object_ptr<webViewMessageSent> webViewMessageSent::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webViewMessageSent> res = make_tl_object<webViewMessageSent>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->msg_id_ = TlFetchObject<InputBotInlineMessageID>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void webViewMessageSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webViewMessageSent");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((msg_id_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("msg_id", static_cast<const BaseObject *>(msg_id_.get())); }
    s.store_class_end();
  }
}

const std::int32_t account_autoDownloadSettings::ID;

object_ptr<account_autoDownloadSettings> account_autoDownloadSettings::fetch(TlBufferParser &p) {
  return make_tl_object<account_autoDownloadSettings>(p);
}

account_autoDownloadSettings::account_autoDownloadSettings(TlBufferParser &p)
  : low_(TlFetchBoxed<TlFetchObject<autoDownloadSettings>, -1163561432>::parse(p))
  , medium_(TlFetchBoxed<TlFetchObject<autoDownloadSettings>, -1163561432>::parse(p))
  , high_(TlFetchBoxed<TlFetchObject<autoDownloadSettings>, -1163561432>::parse(p))
{}

void account_autoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.autoDownloadSettings");
    s.store_object_field("low", static_cast<const BaseObject *>(low_.get()));
    s.store_object_field("medium", static_cast<const BaseObject *>(medium_.get()));
    s.store_object_field("high", static_cast<const BaseObject *>(high_.get()));
    s.store_class_end();
  }
}

const std::int32_t account_tmpPassword::ID;

object_ptr<account_tmpPassword> account_tmpPassword::fetch(TlBufferParser &p) {
  return make_tl_object<account_tmpPassword>(p);
}

account_tmpPassword::account_tmpPassword(TlBufferParser &p)
  : tmp_password_(TlFetchBytes<bytes>::parse(p))
  , valid_until_(TlFetchInt::parse(p))
{}

void account_tmpPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.tmpPassword");
    s.store_field("tmp_password", "[REDACTED]");
    s.store_field("valid_until", valid_until_);
    s.store_class_end();
  }
}

object_ptr<account_WallPapers> account_WallPapers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_wallPapersNotModified::ID:
      return account_wallPapersNotModified::fetch(p);
    case account_wallPapers::ID:
      return account_wallPapers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_wallPapersNotModified::ID;

object_ptr<account_WallPapers> account_wallPapersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_wallPapersNotModified>();
}

void account_wallPapersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.wallPapersNotModified");
    s.store_class_end();
  }
}

const std::int32_t account_wallPapers::ID;

object_ptr<account_WallPapers> account_wallPapers::fetch(TlBufferParser &p) {
  return make_tl_object<account_wallPapers>(p);
}

account_wallPapers::account_wallPapers(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , wallpapers_(TlFetchBoxed<TlFetchVector<TlFetchObject<WallPaper>>, 481674261>::parse(p))
{}

void account_wallPapers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.wallPapers");
    s.store_field("hash", hash_);
    { s.store_vector_begin("wallpapers", wallpapers_.size()); for (const auto &_value : wallpapers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t auth_passwordRecovery::ID;

object_ptr<auth_passwordRecovery> auth_passwordRecovery::fetch(TlBufferParser &p) {
  return make_tl_object<auth_passwordRecovery>(p);
}

auth_passwordRecovery::auth_passwordRecovery(TlBufferParser &p)
  : email_pattern_(TlFetchString<string>::parse(p))
{}

void auth_passwordRecovery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.passwordRecovery");
    s.store_field("email_pattern", email_pattern_);
    s.store_class_end();
  }
}

object_ptr<auth_SentCodeType> auth_SentCodeType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case auth_sentCodeTypeApp::ID:
      return auth_sentCodeTypeApp::fetch(p);
    case auth_sentCodeTypeSms::ID:
      return auth_sentCodeTypeSms::fetch(p);
    case auth_sentCodeTypeCall::ID:
      return auth_sentCodeTypeCall::fetch(p);
    case auth_sentCodeTypeFlashCall::ID:
      return auth_sentCodeTypeFlashCall::fetch(p);
    case auth_sentCodeTypeMissedCall::ID:
      return auth_sentCodeTypeMissedCall::fetch(p);
    case auth_sentCodeTypeEmailCode::ID:
      return auth_sentCodeTypeEmailCode::fetch(p);
    case auth_sentCodeTypeSetUpEmailRequired::ID:
      return auth_sentCodeTypeSetUpEmailRequired::fetch(p);
    case auth_sentCodeTypeFragmentSms::ID:
      return auth_sentCodeTypeFragmentSms::fetch(p);
    case auth_sentCodeTypeFirebaseSms::ID:
      return auth_sentCodeTypeFirebaseSms::fetch(p);
    case auth_sentCodeTypeSmsWord::ID:
      return auth_sentCodeTypeSmsWord::fetch(p);
    case auth_sentCodeTypeSmsPhrase::ID:
      return auth_sentCodeTypeSmsPhrase::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t auth_sentCodeTypeApp::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeApp::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeApp>(p);
}

auth_sentCodeTypeApp::auth_sentCodeTypeApp(TlBufferParser &p)
  : length_(TlFetchInt::parse(p))
{}

void auth_sentCodeTypeApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeApp");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeTypeSms::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeSms::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeSms>(p);
}

auth_sentCodeTypeSms::auth_sentCodeTypeSms(TlBufferParser &p)
  : length_(TlFetchInt::parse(p))
{}

void auth_sentCodeTypeSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeSms");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeTypeCall::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeCall>(p);
}

auth_sentCodeTypeCall::auth_sentCodeTypeCall(TlBufferParser &p)
  : length_(TlFetchInt::parse(p))
{}

void auth_sentCodeTypeCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeCall");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeTypeFlashCall::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeFlashCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeFlashCall>(p);
}

auth_sentCodeTypeFlashCall::auth_sentCodeTypeFlashCall(TlBufferParser &p)
  : pattern_(TlFetchString<string>::parse(p))
{}

void auth_sentCodeTypeFlashCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeFlashCall");
    s.store_field("pattern", pattern_);
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeTypeMissedCall::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeMissedCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeMissedCall>(p);
}

auth_sentCodeTypeMissedCall::auth_sentCodeTypeMissedCall(TlBufferParser &p)
  : prefix_(TlFetchString<string>::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void auth_sentCodeTypeMissedCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeMissedCall");
    s.store_field("prefix", prefix_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

auth_sentCodeTypeEmailCode::auth_sentCodeTypeEmailCode()
  : flags_()
  , apple_signin_allowed_()
  , google_signin_allowed_()
  , email_pattern_()
  , length_()
  , reset_available_period_()
  , reset_pending_date_()
{}

const std::int32_t auth_sentCodeTypeEmailCode::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeEmailCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCodeTypeEmailCode> res = make_tl_object<auth_sentCodeTypeEmailCode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->apple_signin_allowed_ = (var0 & 1) != 0;
  res->google_signin_allowed_ = (var0 & 2) != 0;
  res->email_pattern_ = TlFetchString<string>::parse(p);
  res->length_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->reset_available_period_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->reset_pending_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCodeTypeEmailCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeEmailCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (apple_signin_allowed_ << 0) | (google_signin_allowed_ << 1)));
    if (var0 & 1) { s.store_field("apple_signin_allowed", true); }
    if (var0 & 2) { s.store_field("google_signin_allowed", true); }
    s.store_field("email_pattern", email_pattern_);
    s.store_field("length", length_);
    if (var0 & 8) { s.store_field("reset_available_period", reset_available_period_); }
    if (var0 & 16) { s.store_field("reset_pending_date", reset_pending_date_); }
    s.store_class_end();
  }
}

auth_sentCodeTypeSetUpEmailRequired::auth_sentCodeTypeSetUpEmailRequired()
  : flags_()
  , apple_signin_allowed_()
  , google_signin_allowed_()
{}

const std::int32_t auth_sentCodeTypeSetUpEmailRequired::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeSetUpEmailRequired::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCodeTypeSetUpEmailRequired> res = make_tl_object<auth_sentCodeTypeSetUpEmailRequired>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->apple_signin_allowed_ = (var0 & 1) != 0;
  res->google_signin_allowed_ = (var0 & 2) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCodeTypeSetUpEmailRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeSetUpEmailRequired");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (apple_signin_allowed_ << 0) | (google_signin_allowed_ << 1)));
    if (var0 & 1) { s.store_field("apple_signin_allowed", true); }
    if (var0 & 2) { s.store_field("google_signin_allowed", true); }
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeTypeFragmentSms::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeFragmentSms::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeFragmentSms>(p);
}

auth_sentCodeTypeFragmentSms::auth_sentCodeTypeFragmentSms(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void auth_sentCodeTypeFragmentSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeFragmentSms");
    s.store_field("url", url_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

auth_sentCodeTypeFirebaseSms::auth_sentCodeTypeFirebaseSms()
  : flags_()
  , nonce_()
  , play_integrity_project_id_()
  , play_integrity_nonce_()
  , receipt_()
  , push_timeout_()
  , length_()
{}

const std::int32_t auth_sentCodeTypeFirebaseSms::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeFirebaseSms::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCodeTypeFirebaseSms> res = make_tl_object<auth_sentCodeTypeFirebaseSms>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->nonce_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 4) { res->play_integrity_project_id_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->play_integrity_nonce_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 2) { res->receipt_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->push_timeout_ = TlFetchInt::parse(p); }
  res->length_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCodeTypeFirebaseSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeFirebaseSms");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!nonce_.empty()) << 0) | ((!play_integrity_nonce_.empty()) << 2) | ((!receipt_.empty()) << 1)));
    if (var0 & 1) { s.store_bytes_field("nonce", nonce_); }
    if (var0 & 4) { s.store_field("play_integrity_project_id", play_integrity_project_id_); }
    if (var0 & 4) { s.store_bytes_field("play_integrity_nonce", play_integrity_nonce_); }
    if (var0 & 2) { s.store_field("receipt", receipt_); }
    if (var0 & 2) { s.store_field("push_timeout", push_timeout_); }
    s.store_field("length", length_);
    s.store_class_end();
  }
}

auth_sentCodeTypeSmsWord::auth_sentCodeTypeSmsWord()
  : flags_()
  , beginning_()
{}

const std::int32_t auth_sentCodeTypeSmsWord::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeSmsWord::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCodeTypeSmsWord> res = make_tl_object<auth_sentCodeTypeSmsWord>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->beginning_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCodeTypeSmsWord::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeSmsWord");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!beginning_.empty()) << 0)));
    if (var0 & 1) { s.store_field("beginning", beginning_); }
    s.store_class_end();
  }
}

auth_sentCodeTypeSmsPhrase::auth_sentCodeTypeSmsPhrase()
  : flags_()
  , beginning_()
{}

const std::int32_t auth_sentCodeTypeSmsPhrase::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeSmsPhrase::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCodeTypeSmsPhrase> res = make_tl_object<auth_sentCodeTypeSmsPhrase>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->beginning_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCodeTypeSmsPhrase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeSmsPhrase");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!beginning_.empty()) << 0)));
    if (var0 & 1) { s.store_field("beginning", beginning_); }
    s.store_class_end();
  }
}

object_ptr<contacts_Blocked> contacts_Blocked::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case contacts_blocked::ID:
      return contacts_blocked::fetch(p);
    case contacts_blockedSlice::ID:
      return contacts_blockedSlice::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t contacts_blocked::ID;

object_ptr<contacts_Blocked> contacts_blocked::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_blocked>(p);
}

contacts_blocked::contacts_blocked(TlBufferParser &p)
  : blocked_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<peerBlocked>, -386039788>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_blocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.blocked");
    { s.store_vector_begin("blocked", blocked_.size()); for (const auto &_value : blocked_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t contacts_blockedSlice::ID;

object_ptr<contacts_Blocked> contacts_blockedSlice::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_blockedSlice>(p);
}

contacts_blockedSlice::contacts_blockedSlice(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , blocked_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<peerBlocked>, -386039788>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_blockedSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.blockedSlice");
    s.store_field("count", count_);
    { s.store_vector_begin("blocked", blocked_.size()); for (const auto &_value : blocked_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t contacts_resolvedPeer::ID;

object_ptr<contacts_resolvedPeer> contacts_resolvedPeer::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_resolvedPeer>(p);
}

contacts_resolvedPeer::contacts_resolvedPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_resolvedPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.resolvedPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<help_AppConfig> help_AppConfig::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_appConfigNotModified::ID:
      return help_appConfigNotModified::fetch(p);
    case help_appConfig::ID:
      return help_appConfig::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_appConfigNotModified::ID;

object_ptr<help_AppConfig> help_appConfigNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<help_appConfigNotModified>();
}

void help_appConfigNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.appConfigNotModified");
    s.store_class_end();
  }
}

const std::int32_t help_appConfig::ID;

object_ptr<help_AppConfig> help_appConfig::fetch(TlBufferParser &p) {
  return make_tl_object<help_appConfig>(p);
}

help_appConfig::help_appConfig(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , config_(TlFetchObject<JSONValue>::parse(p))
{}

void help_appConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.appConfig");
    s.store_field("hash", hash_);
    s.store_object_field("config", static_cast<const BaseObject *>(config_.get()));
    s.store_class_end();
  }
}

help_peerColorOption::help_peerColorOption()
  : flags_()
  , hidden_()
  , color_id_()
  , colors_()
  , dark_colors_()
  , channel_min_level_()
  , group_min_level_()
{}

const std::int32_t help_peerColorOption::ID;

object_ptr<help_peerColorOption> help_peerColorOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_peerColorOption> res = make_tl_object<help_peerColorOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->hidden_ = (var0 & 1) != 0;
  res->color_id_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->colors_ = TlFetchObject<help_PeerColorSet>::parse(p); }
  if (var0 & 4) { res->dark_colors_ = TlFetchObject<help_PeerColorSet>::parse(p); }
  if (var0 & 8) { res->channel_min_level_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->group_min_level_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void help_peerColorOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.peerColorOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (hidden_ << 0) | ((colors_ != nullptr) << 1) | ((dark_colors_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("hidden", true); }
    s.store_field("color_id", color_id_);
    if (var0 & 2) { s.store_object_field("colors", static_cast<const BaseObject *>(colors_.get())); }
    if (var0 & 4) { s.store_object_field("dark_colors", static_cast<const BaseObject *>(dark_colors_.get())); }
    if (var0 & 8) { s.store_field("channel_min_level", channel_min_level_); }
    if (var0 & 16) { s.store_field("group_min_level", group_min_level_); }
    s.store_class_end();
  }
}

object_ptr<help_PeerColorSet> help_PeerColorSet::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_peerColorSet::ID:
      return help_peerColorSet::fetch(p);
    case help_peerColorProfileSet::ID:
      return help_peerColorProfileSet::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_peerColorSet::ID;

object_ptr<help_PeerColorSet> help_peerColorSet::fetch(TlBufferParser &p) {
  return make_tl_object<help_peerColorSet>(p);
}

help_peerColorSet::help_peerColorSet(TlBufferParser &p)
  : colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void help_peerColorSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.peerColorSet");
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t help_peerColorProfileSet::ID;

object_ptr<help_PeerColorSet> help_peerColorProfileSet::fetch(TlBufferParser &p) {
  return make_tl_object<help_peerColorProfileSet>(p);
}

help_peerColorProfileSet::help_peerColorProfileSet(TlBufferParser &p)
  : palette_colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , bg_colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , story_colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void help_peerColorProfileSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.peerColorProfileSet");
    { s.store_vector_begin("palette_colors", palette_colors_.size()); for (const auto &_value : palette_colors_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("bg_colors", bg_colors_.size()); for (const auto &_value : bg_colors_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("story_colors", story_colors_.size()); for (const auto &_value : story_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_chatInviteImporters::ID;

object_ptr<messages_chatInviteImporters> messages_chatInviteImporters::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chatInviteImporters>(p);
}

messages_chatInviteImporters::messages_chatInviteImporters(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , importers_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<chatInviteImporter>, -1940201511>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_chatInviteImporters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chatInviteImporters");
    s.store_field("count", count_);
    { s.store_vector_begin("importers", importers_.size()); for (const auto &_value : importers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_ExportedChatInvite> messages_ExportedChatInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_exportedChatInvite::ID:
      return messages_exportedChatInvite::fetch(p);
    case messages_exportedChatInviteReplaced::ID:
      return messages_exportedChatInviteReplaced::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_exportedChatInvite::ID;

object_ptr<messages_ExportedChatInvite> messages_exportedChatInvite::fetch(TlBufferParser &p) {
  return make_tl_object<messages_exportedChatInvite>(p);
}

messages_exportedChatInvite::messages_exportedChatInvite(TlBufferParser &p)
  : invite_(TlFetchObject<ExportedChatInvite>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_exportedChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.exportedChatInvite");
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_exportedChatInviteReplaced::ID;

object_ptr<messages_ExportedChatInvite> messages_exportedChatInviteReplaced::fetch(TlBufferParser &p) {
  return make_tl_object<messages_exportedChatInviteReplaced>(p);
}

messages_exportedChatInviteReplaced::messages_exportedChatInviteReplaced(TlBufferParser &p)
  : invite_(TlFetchObject<ExportedChatInvite>::parse(p))
  , new_invite_(TlFetchObject<ExportedChatInvite>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_exportedChatInviteReplaced::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.exportedChatInviteReplaced");
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_object_field("new_invite", static_cast<const BaseObject *>(new_invite_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_Messages> messages_Messages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_messages::ID:
      return messages_messages::fetch(p);
    case messages_messagesSlice::ID:
      return messages_messagesSlice::fetch(p);
    case messages_channelMessages::ID:
      return messages_channelMessages::fetch(p);
    case messages_messagesNotModified::ID:
      return messages_messagesNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_messages::ID;

object_ptr<messages_Messages> messages_messages::fetch(TlBufferParser &p) {
  return make_tl_object<messages_messages>(p);
}

messages_messages::messages_messages(TlBufferParser &p)
  : messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , topics_(TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_messages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_messagesSlice::messages_messagesSlice()
  : flags_()
  , inexact_()
  , count_()
  , next_rate_()
  , offset_id_offset_()
  , search_flood_()
  , messages_()
  , topics_()
  , chats_()
  , users_()
{}

const std::int32_t messages_messagesSlice::ID;

object_ptr<messages_Messages> messages_messagesSlice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_messagesSlice> res = make_tl_object<messages_messagesSlice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inexact_ = (var0 & 2) != 0;
  res->count_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->next_rate_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->offset_id_offset_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->search_flood_ = TlFetchBoxed<TlFetchObject<searchPostsFlood>, 1040931690>::parse(p); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_messagesSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messagesSlice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inexact_ << 1) | ((search_flood_ != nullptr) << 3)));
    if (var0 & 2) { s.store_field("inexact", true); }
    s.store_field("count", count_);
    if (var0 & 1) { s.store_field("next_rate", next_rate_); }
    if (var0 & 4) { s.store_field("offset_id_offset", offset_id_offset_); }
    if (var0 & 8) { s.store_object_field("search_flood", static_cast<const BaseObject *>(search_flood_.get())); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_channelMessages::messages_channelMessages()
  : flags_()
  , inexact_()
  , pts_()
  , count_()
  , offset_id_offset_()
  , messages_()
  , topics_()
  , chats_()
  , users_()
{}

const std::int32_t messages_channelMessages::ID;

object_ptr<messages_Messages> messages_channelMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_channelMessages> res = make_tl_object<messages_channelMessages>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inexact_ = (var0 & 2) != 0;
  res->pts_ = TlFetchInt::parse(p);
  res->count_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->offset_id_offset_ = TlFetchInt::parse(p); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_channelMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.channelMessages");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inexact_ << 1)));
    if (var0 & 2) { s.store_field("inexact", true); }
    s.store_field("pts", pts_);
    s.store_field("count", count_);
    if (var0 & 4) { s.store_field("offset_id_offset", offset_id_offset_); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_messagesNotModified::ID;

object_ptr<messages_Messages> messages_messagesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_messagesNotModified>(p);
}

messages_messagesNotModified::messages_messagesNotModified(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
{}

void messages_messagesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messagesNotModified");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

const std::int32_t messages_myStickers::ID;

object_ptr<messages_myStickers> messages_myStickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_myStickers>(p);
}

messages_myStickers::messages_myStickers(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , sets_(TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p))
{}

void messages_myStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.myStickers");
    s.store_field("count", count_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_Reactions> messages_Reactions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_reactionsNotModified::ID:
      return messages_reactionsNotModified::fetch(p);
    case messages_reactions::ID:
      return messages_reactions::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_reactionsNotModified::ID;

object_ptr<messages_Reactions> messages_reactionsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_reactionsNotModified>();
}

void messages_reactionsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reactionsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_reactions::ID;

object_ptr<messages_Reactions> messages_reactions::fetch(TlBufferParser &p) {
  return make_tl_object<messages_reactions>(p);
}

messages_reactions::messages_reactions(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , reactions_(TlFetchBoxed<TlFetchVector<TlFetchObject<Reaction>>, 481674261>::parse(p))
{}

void messages_reactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reactions");
    s.store_field("hash", hash_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_translatedRichMessage::ID;

object_ptr<messages_translatedRichMessage> messages_translatedRichMessage::fetch(TlBufferParser &p) {
  return make_tl_object<messages_translatedRichMessage>(p);
}

messages_translatedRichMessage::messages_translatedRichMessage(TlBufferParser &p)
  : result_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<richMessage>, -1158439541>>, 481674261>::parse(p))
{}

void messages_translatedRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.translatedRichMessage");
    { s.store_vector_begin("result", result_.size()); for (const auto &_value : result_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_WidgetPublicData> messages_WidgetPublicData::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_widgetPublicDataNotModified::ID:
      return messages_widgetPublicDataNotModified::fetch(p);
    case messages_widgetPublicData::ID:
      return messages_widgetPublicData::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_widgetPublicDataNotModified::ID;

object_ptr<messages_WidgetPublicData> messages_widgetPublicDataNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_widgetPublicDataNotModified>(p);
}

messages_widgetPublicDataNotModified::messages_widgetPublicDataNotModified(TlBufferParser &p)
  : period_(TlFetchInt::parse(p))
{}

void messages_widgetPublicDataNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.widgetPublicDataNotModified");
    s.store_field("period", period_);
    s.store_class_end();
  }
}

const std::int32_t messages_widgetPublicData::ID;

object_ptr<messages_WidgetPublicData> messages_widgetPublicData::fetch(TlBufferParser &p) {
  return make_tl_object<messages_widgetPublicData>(p);
}

messages_widgetPublicData::messages_widgetPublicData(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , data_(TlFetchString<string>::parse(p))
  , period_(TlFetchInt::parse(p))
{}

void messages_widgetPublicData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.widgetPublicData");
    s.store_field("hash", hash_);
    s.store_field("data", data_);
    s.store_field("period", period_);
    s.store_class_end();
  }
}

payments_checkedGiftCode::payments_checkedGiftCode()
  : flags_()
  , via_giveaway_()
  , from_id_()
  , giveaway_msg_id_()
  , to_id_()
  , date_()
  , days_()
  , used_date_()
  , chats_()
  , users_()
{}

const std::int32_t payments_checkedGiftCode::ID;

object_ptr<payments_checkedGiftCode> payments_checkedGiftCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_checkedGiftCode> res = make_tl_object<payments_checkedGiftCode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_giveaway_ = (var0 & 4) != 0;
  if (var0 & 16) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 8) { res->giveaway_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->to_id_ = TlFetchLong::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->days_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->used_date_ = TlFetchInt::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_checkedGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.checkedGiftCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_giveaway_ << 2) | ((from_id_ != nullptr) << 4)));
    if (var0 & 4) { s.store_field("via_giveaway", true); }
    if (var0 & 16) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 8) { s.store_field("giveaway_msg_id", giveaway_msg_id_); }
    if (var0 & 1) { s.store_field("to_id", to_id_); }
    s.store_field("date", date_);
    s.store_field("days", days_);
    if (var0 & 2) { s.store_field("used_date", used_date_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftUpgradePreview::ID;

object_ptr<payments_starGiftUpgradePreview> payments_starGiftUpgradePreview::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftUpgradePreview>(p);
}

payments_starGiftUpgradePreview::payments_starGiftUpgradePreview(TlBufferParser &p)
  : sample_attributes_(TlFetchBoxed<TlFetchVector<TlFetchObject<StarGiftAttribute>>, 481674261>::parse(p))
  , prices_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftUpgradePrice>, -1712704739>>, 481674261>::parse(p))
  , next_prices_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftUpgradePrice>, -1712704739>>, 481674261>::parse(p))
{}

void payments_starGiftUpgradePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftUpgradePreview");
    { s.store_vector_begin("sample_attributes", sample_attributes_.size()); for (const auto &_value : sample_attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("prices", prices_.size()); for (const auto &_value : prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("next_prices", next_prices_.size()); for (const auto &_value : next_prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stats_pollStats::ID;

object_ptr<stats_pollStats> stats_pollStats::fetch(TlBufferParser &p) {
  return make_tl_object<stats_pollStats>(p);
}

stats_pollStats::stats_pollStats(TlBufferParser &p)
  : votes_graph_(TlFetchObject<StatsGraph>::parse(p))
{}

void stats_pollStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.pollStats");
    s.store_object_field("votes_graph", static_cast<const BaseObject *>(votes_graph_.get()));
    s.store_class_end();
  }
}

object_ptr<stories_Albums> stories_Albums::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case stories_albumsNotModified::ID:
      return stories_albumsNotModified::fetch(p);
    case stories_albums::ID:
      return stories_albums::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t stories_albumsNotModified::ID;

object_ptr<stories_Albums> stories_albumsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<stories_albumsNotModified>();
}

void stories_albumsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.albumsNotModified");
    s.store_class_end();
  }
}

const std::int32_t stories_albums::ID;

object_ptr<stories_Albums> stories_albums::fetch(TlBufferParser &p) {
  return make_tl_object<stories_albums>(p);
}

stories_albums::stories_albums(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , albums_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<storyAlbum>, -1826262950>>, 481674261>::parse(p))
{}

void stories_albums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.albums");
    s.store_field("hash", hash_);
    { s.store_vector_begin("albums", albums_.size()); for (const auto &_value : albums_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<stories_AllStories> stories_AllStories::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case stories_allStoriesNotModified::ID:
      return stories_allStoriesNotModified::fetch(p);
    case stories_allStories::ID:
      return stories_allStories::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

stories_allStoriesNotModified::stories_allStoriesNotModified()
  : flags_()
  , state_()
  , stealth_mode_()
{}

const std::int32_t stories_allStoriesNotModified::ID;

object_ptr<stories_AllStories> stories_allStoriesNotModified::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_allStoriesNotModified> res = make_tl_object<stories_allStoriesNotModified>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->state_ = TlFetchString<string>::parse(p);
  res->stealth_mode_ = TlFetchBoxed<TlFetchObject<storiesStealthMode>, 1898850301>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void stories_allStoriesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.allStoriesNotModified");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("state", state_);
    s.store_object_field("stealth_mode", static_cast<const BaseObject *>(stealth_mode_.get()));
    s.store_class_end();
  }
}

stories_allStories::stories_allStories()
  : flags_()
  , has_more_()
  , count_()
  , state_()
  , peer_stories_()
  , chats_()
  , users_()
  , stealth_mode_()
{}

const std::int32_t stories_allStories::ID;

object_ptr<stories_AllStories> stories_allStories::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_allStories> res = make_tl_object<stories_allStories>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_more_ = (var0 & 1) != 0;
  res->count_ = TlFetchInt::parse(p);
  res->state_ = TlFetchString<string>::parse(p);
  res->peer_stories_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<peerStories>, -1707742823>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  res->stealth_mode_ = TlFetchBoxed<TlFetchObject<storiesStealthMode>, 1898850301>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void stories_allStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.allStories");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_more_ << 0)));
    if (var0 & 1) { s.store_field("has_more", true); }
    s.store_field("count", count_);
    s.store_field("state", state_);
    { s.store_vector_begin("peer_stories", peer_stories_.size()); for (const auto &_value : peer_stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("stealth_mode", static_cast<const BaseObject *>(stealth_mode_.get()));
    s.store_class_end();
  }
}

const std::int32_t stories_storyViews::ID;

object_ptr<stories_storyViews> stories_storyViews::fetch(TlBufferParser &p) {
  return make_tl_object<stories_storyViews>(p);
}

stories_storyViews::stories_storyViews(TlBufferParser &p)
  : views_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<storyViews>, -1923523370>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void stories_storyViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.storyViews");
    { s.store_vector_begin("views", views_.size()); for (const auto &_value : views_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t wallet_tonConnectSessions::ID;

object_ptr<wallet_tonConnectSessions> wallet_tonConnectSessions::fetch(TlBufferParser &p) {
  return make_tl_object<wallet_tonConnectSessions>(p);
}

wallet_tonConnectSessions::wallet_tonConnectSessions(TlBufferParser &p)
  : sessions_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<tonConnectSession>, 308631238>>, 481674261>::parse(p))
{}

void wallet_tonConnectSessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectSessions");
    { s.store_vector_begin("sessions", sessions_.size()); for (const auto &_value : sessions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t wallet_userAddresses::ID;

object_ptr<wallet_userAddresses> wallet_userAddresses::fetch(TlBufferParser &p) {
  return make_tl_object<wallet_userAddresses>(p);
}

wallet_userAddresses::wallet_userAddresses(TlBufferParser &p)
  : addresses_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<walletUserAddress>, -25628980>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void wallet_userAddresses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.userAddresses");
    { s.store_vector_begin("addresses", addresses_.size()); for (const auto &_value : addresses_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_deleteAccount::account_deleteAccount(int32 flags_, string const &reason_, object_ptr<InputCheckPasswordSRP> &&password_)
  : flags_(flags_)
  , reason_(reason_)
  , password_(std::move(password_))
{}

const std::int32_t account_deleteAccount::ID;

void account_deleteAccount::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1564422284);
  TlStoreBinary::store((var0 = flags_ | ((password_ != nullptr) << 0)), s);
  TlStoreString::store(reason_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void account_deleteAccount::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1564422284);
  TlStoreBinary::store((var0 = flags_ | ((password_ != nullptr) << 0)), s);
  TlStoreString::store(reason_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void account_deleteAccount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.deleteAccount");
    s.store_field("flags", (var0 = flags_ | ((password_ != nullptr) << 0)));
    s.store_field("reason", reason_);
    if (var0 & 1) { s.store_field("password", "[REDACTED]"); }
    s.store_class_end();
  }
}

account_deleteAccount::ReturnType account_deleteAccount::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_deletePasskey::account_deletePasskey(string const &id_)
  : id_(id_)
{}

const std::int32_t account_deletePasskey::ID;

void account_deletePasskey::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-172665281);
  TlStoreString::store(id_, s);
}

void account_deletePasskey::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-172665281);
  TlStoreString::store(id_, s);
}

void account_deletePasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.deletePasskey");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

account_deletePasskey::ReturnType account_deletePasskey::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_deleteWebBrowserSettingsExceptions::ID;

void account_deleteWebBrowserSettingsExceptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2036304291);
}

void account_deleteWebBrowserSettingsExceptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2036304291);
}

void account_deleteWebBrowserSettingsExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.deleteWebBrowserSettingsExceptions");
    s.store_class_end();
  }
}

account_deleteWebBrowserSettingsExceptions::ReturnType account_deleteWebBrowserSettingsExceptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_WebBrowserSettings>::parse(p);
#undef FAIL
}

account_getCollectibleEmojiStatuses::account_getCollectibleEmojiStatuses(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getCollectibleEmojiStatuses::ID;

void account_getCollectibleEmojiStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(779830595);
  TlStoreBinary::store(hash_, s);
}

void account_getCollectibleEmojiStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(779830595);
  TlStoreBinary::store(hash_, s);
}

void account_getCollectibleEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getCollectibleEmojiStatuses");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getCollectibleEmojiStatuses::ReturnType account_getCollectibleEmojiStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_EmojiStatuses>::parse(p);
#undef FAIL
}

const std::int32_t account_getConnectedBots::ID;

void account_getConnectedBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1319421967);
}

void account_getConnectedBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1319421967);
}

void account_getConnectedBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getConnectedBots");
    s.store_class_end();
  }
}

account_getConnectedBots::ReturnType account_getConnectedBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_connectedBots>, 400029819>::parse(p);
#undef FAIL
}

account_getDefaultGroupPhotoEmojis::account_getDefaultGroupPhotoEmojis(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getDefaultGroupPhotoEmojis::ID;

void account_getDefaultGroupPhotoEmojis::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1856479058);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultGroupPhotoEmojis::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1856479058);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultGroupPhotoEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getDefaultGroupPhotoEmojis");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getDefaultGroupPhotoEmojis::ReturnType account_getDefaultGroupPhotoEmojis::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EmojiList>::parse(p);
#undef FAIL
}

const std::int32_t account_getPassword::ID;

void account_getPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1418342645);
}

void account_getPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1418342645);
}

void account_getPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getPassword");
    s.store_class_end();
  }
}

account_getPassword::ReturnType account_getPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_password>, -1787080453>::parse(p);
#undef FAIL
}

account_getSavedRingtones::account_getSavedRingtones(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getSavedRingtones::ID;

void account_getSavedRingtones::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-510647672);
  TlStoreBinary::store(hash_, s);
}

void account_getSavedRingtones::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-510647672);
  TlStoreBinary::store(hash_, s);
}

void account_getSavedRingtones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getSavedRingtones");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getSavedRingtones::ReturnType account_getSavedRingtones::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_SavedRingtones>::parse(p);
#undef FAIL
}

account_getSecureValue::account_getSecureValue(array<object_ptr<SecureValueType>> &&types_)
  : types_(std::move(types_))
{}

const std::int32_t account_getSecureValue::ID;

void account_getSecureValue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1936088002);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(types_, s);
}

void account_getSecureValue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1936088002);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(types_, s);
}

void account_getSecureValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getSecureValue");
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_getSecureValue::ReturnType account_getSecureValue::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<secureValue>, 411017418>>, 481674261>::parse(p);
#undef FAIL
}

account_getUniqueGiftChatThemes::account_getUniqueGiftChatThemes(string const &offset_, int32 limit_, int64 hash_)
  : offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t account_getUniqueGiftChatThemes::ID;

void account_getUniqueGiftChatThemes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-466818615);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void account_getUniqueGiftChatThemes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-466818615);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void account_getUniqueGiftChatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getUniqueGiftChatThemes");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getUniqueGiftChatThemes::ReturnType account_getUniqueGiftChatThemes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_ChatThemes>::parse(p);
#undef FAIL
}

account_invalidateSignInCodes::account_invalidateSignInCodes(array<string> &&codes_)
  : codes_(std::move(codes_))
{}

const std::int32_t account_invalidateSignInCodes::ID;

void account_invalidateSignInCodes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-896866118);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(codes_, s);
}

void account_invalidateSignInCodes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-896866118);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(codes_, s);
}

void account_invalidateSignInCodes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.invalidateSignInCodes");
    s.store_field("codes", "[REDACTED]");
    s.store_class_end();
  }
}

account_invalidateSignInCodes::ReturnType account_invalidateSignInCodes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_saveAutoDownloadSettings::account_saveAutoDownloadSettings(int32 flags_, bool low_, bool high_, object_ptr<autoDownloadSettings> &&settings_)
  : flags_(flags_)
  , low_(low_)
  , high_(high_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_saveAutoDownloadSettings::ID;

void account_saveAutoDownloadSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1995661875);
  TlStoreBinary::store((var0 = flags_ | (low_ << 0) | (high_ << 1)), s);
  TlStoreBoxed<TlStoreObject, -1163561432>::store(settings_, s);
}

void account_saveAutoDownloadSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1995661875);
  TlStoreBinary::store((var0 = flags_ | (low_ << 0) | (high_ << 1)), s);
  TlStoreBoxed<TlStoreObject, -1163561432>::store(settings_, s);
}

void account_saveAutoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveAutoDownloadSettings");
    s.store_field("flags", (var0 = flags_ | (low_ << 0) | (high_ << 1)));
    if (var0 & 1) { s.store_field("low", true); }
    if (var0 & 2) { s.store_field("high", true); }
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_saveAutoDownloadSettings::ReturnType account_saveAutoDownloadSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_saveAutoSaveSettings::account_saveAutoSaveSettings(int32 flags_, bool users_, bool chats_, bool broadcasts_, object_ptr<InputPeer> &&peer_, object_ptr<autoSaveSettings> &&settings_)
  : flags_(flags_)
  , users_(users_)
  , chats_(chats_)
  , broadcasts_(broadcasts_)
  , peer_(std::move(peer_))
  , settings_(std::move(settings_))
{}

const std::int32_t account_saveAutoSaveSettings::ID;

void account_saveAutoSaveSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-694451359);
  TlStoreBinary::store((var0 = flags_ | (users_ << 0) | (chats_ << 1) | (broadcasts_ << 2) | ((peer_ != nullptr) << 3)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBoxed<TlStoreObject, -934791986>::store(settings_, s);
}

void account_saveAutoSaveSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-694451359);
  TlStoreBinary::store((var0 = flags_ | (users_ << 0) | (chats_ << 1) | (broadcasts_ << 2) | ((peer_ != nullptr) << 3)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBoxed<TlStoreObject, -934791986>::store(settings_, s);
}

void account_saveAutoSaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveAutoSaveSettings");
    s.store_field("flags", (var0 = flags_ | (users_ << 0) | (chats_ << 1) | (broadcasts_ << 2) | ((peer_ != nullptr) << 3)));
    if (var0 & 1) { s.store_field("users", true); }
    if (var0 & 2) { s.store_field("chats", true); }
    if (var0 & 4) { s.store_field("broadcasts", true); }
    if (var0 & 8) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_saveAutoSaveSettings::ReturnType account_saveAutoSaveSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_setContentSettings::account_setContentSettings(int32 flags_, bool sensitive_enabled_)
  : flags_(flags_)
  , sensitive_enabled_(sensitive_enabled_)
{}

const std::int32_t account_setContentSettings::ID;

void account_setContentSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1250643605);
  TlStoreBinary::store((var0 = flags_ | (sensitive_enabled_ << 0)), s);
}

void account_setContentSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1250643605);
  TlStoreBinary::store((var0 = flags_ | (sensitive_enabled_ << 0)), s);
}

void account_setContentSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setContentSettings");
    s.store_field("flags", (var0 = flags_ | (sensitive_enabled_ << 0)));
    if (var0 & 1) { s.store_field("sensitive_enabled", true); }
    s.store_class_end();
  }
}

account_setContentSettings::ReturnType account_setContentSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updatePasswordSettings::account_updatePasswordSettings(object_ptr<InputCheckPasswordSRP> &&password_, object_ptr<account_passwordInputSettings> &&new_settings_)
  : password_(std::move(password_))
  , new_settings_(std::move(new_settings_))
{}

const std::int32_t account_updatePasswordSettings::ID;

void account_updatePasswordSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1516564433);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
  TlStoreBoxed<TlStoreObject, -1036572727>::store(new_settings_, s);
}

void account_updatePasswordSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1516564433);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
  TlStoreBoxed<TlStoreObject, -1036572727>::store(new_settings_, s);
}

void account_updatePasswordSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updatePasswordSettings");
    s.store_field("password", "[REDACTED]");
    s.store_object_field("new_settings", static_cast<const BaseObject *>(new_settings_.get()));
    s.store_class_end();
  }
}

account_updatePasswordSettings::ReturnType account_updatePasswordSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

aicompose_getTones::aicompose_getTones(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t aicompose_getTones::ID;

void aicompose_getTones::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1412066815);
  TlStoreBinary::store(hash_, s);
}

void aicompose_getTones::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1412066815);
  TlStoreBinary::store(hash_, s);
}

void aicompose_getTones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aicompose.getTones");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

aicompose_getTones::ReturnType aicompose_getTones::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<aicompose_Tones>::parse(p);
#undef FAIL
}

auth_cancelCode::auth_cancelCode(string const &phone_number_, string const &phone_code_hash_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
{}

const std::int32_t auth_cancelCode::ID;

void auth_cancelCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(520357240);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void auth_cancelCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(520357240);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void auth_cancelCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.cancelCode");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_class_end();
  }
}

auth_cancelCode::ReturnType auth_cancelCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_reorderPreviewMedias::bots_reorderPreviewMedias(object_ptr<InputUser> &&bot_, string const &lang_code_, array<object_ptr<InputMedia>> &&order_)
  : bot_(std::move(bot_))
  , lang_code_(lang_code_)
  , order_(std::move(order_))
{}

const std::int32_t bots_reorderPreviewMedias::ID;

void bots_reorderPreviewMedias::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1238895702);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void bots_reorderPreviewMedias::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1238895702);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void bots_reorderPreviewMedias::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.reorderPreviewMedias");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("lang_code", lang_code_);
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

bots_reorderPreviewMedias::ReturnType bots_reorderPreviewMedias::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_sendCustomRequest::bots_sendCustomRequest(string const &custom_method_, object_ptr<dataJSON> &&params_)
  : custom_method_(custom_method_)
  , params_(std::move(params_))
{}

const std::int32_t bots_sendCustomRequest::ID;

void bots_sendCustomRequest::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1440257555);
  TlStoreString::store(custom_method_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void bots_sendCustomRequest::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1440257555);
  TlStoreString::store(custom_method_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void bots_sendCustomRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.sendCustomRequest");
    s.store_field("custom_method", custom_method_);
    s.store_object_field("params", static_cast<const BaseObject *>(params_.get()));
    s.store_class_end();
  }
}

bots_sendCustomRequest::ReturnType bots_sendCustomRequest::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
#undef FAIL
}

channels_getChannelRecommendations::channels_getChannelRecommendations(int32 flags_, object_ptr<InputChannel> &&channel_)
  : flags_(flags_)
  , channel_(std::move(channel_))
{}

const std::int32_t channels_getChannelRecommendations::ID;

void channels_getChannelRecommendations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(631707458);
  TlStoreBinary::store((var0 = flags_ | ((channel_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s); }
}

void channels_getChannelRecommendations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(631707458);
  TlStoreBinary::store((var0 = flags_ | ((channel_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s); }
}

void channels_getChannelRecommendations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getChannelRecommendations");
    s.store_field("flags", (var0 = flags_ | ((channel_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get())); }
    s.store_class_end();
  }
}

channels_getChannelRecommendations::ReturnType channels_getChannelRecommendations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

channels_getFullChannel::channels_getFullChannel(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_getFullChannel::ID;

void channels_getFullChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(141781513);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_getFullChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(141781513);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_getFullChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getFullChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_getFullChannel::ReturnType channels_getFullChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_chatFull>, -438840932>::parse(p);
#undef FAIL
}

channels_readMessageContents::channels_readMessageContents(object_ptr<InputChannel> &&channel_, array<int32> &&id_)
  : channel_(std::move(channel_))
  , id_(std::move(id_))
{}

const std::int32_t channels_readMessageContents::ID;

void channels_readMessageContents::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-357180360);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_readMessageContents::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-357180360);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_readMessageContents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.readMessageContents");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_readMessageContents::ReturnType channels_readMessageContents::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_reportSpam::channels_reportSpam(object_ptr<InputChannel> &&channel_, object_ptr<InputPeer> &&participant_, array<int32> &&id_)
  : channel_(std::move(channel_))
  , participant_(std::move(participant_))
  , id_(std::move(id_))
{}

const std::int32_t channels_reportSpam::ID;

void channels_reportSpam::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-196443371);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_reportSpam::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-196443371);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_reportSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.reportSpam");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_reportSpam::ReturnType channels_reportSpam::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_searchPosts::channels_searchPosts(int32 flags_, string const &hashtag_, string const &query_, int32 offset_rate_, object_ptr<InputPeer> &&offset_peer_, int32 offset_id_, int32 limit_, int64 allow_paid_stars_)
  : flags_(flags_)
  , hashtag_(hashtag_)
  , query_(query_)
  , offset_rate_(offset_rate_)
  , offset_peer_(std::move(offset_peer_))
  , offset_id_(offset_id_)
  , limit_(limit_)
  , allow_paid_stars_(allow_paid_stars_)
{}

const std::int32_t channels_searchPosts::ID;

void channels_searchPosts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-221973939);
  TlStoreBinary::store((var0 = flags_ | ((!hashtag_.empty()) << 0) | ((!query_.empty()) << 1)), s);
  if (var0 & 1) { TlStoreString::store(hashtag_, s); }
  if (var0 & 2) { TlStoreString::store(query_, s); }
  TlStoreBinary::store(offset_rate_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
  if (var0 & 4) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void channels_searchPosts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-221973939);
  TlStoreBinary::store((var0 = flags_ | ((!hashtag_.empty()) << 0) | ((!query_.empty()) << 1)), s);
  if (var0 & 1) { TlStoreString::store(hashtag_, s); }
  if (var0 & 2) { TlStoreString::store(query_, s); }
  TlStoreBinary::store(offset_rate_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
  if (var0 & 4) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void channels_searchPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.searchPosts");
    s.store_field("flags", (var0 = flags_ | ((!hashtag_.empty()) << 0) | ((!query_.empty()) << 1)));
    if (var0 & 1) { s.store_field("hashtag", hashtag_); }
    if (var0 & 2) { s.store_field("query", query_); }
    s.store_field("offset_rate", offset_rate_);
    s.store_object_field("offset_peer", static_cast<const BaseObject *>(offset_peer_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    if (var0 & 4) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    s.store_class_end();
  }
}

channels_searchPosts::ReturnType channels_searchPosts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

channels_setStickers::channels_setStickers(object_ptr<InputChannel> &&channel_, object_ptr<InputStickerSet> &&stickerset_)
  : channel_(std::move(channel_))
  , stickerset_(std::move(stickerset_))
{}

const std::int32_t channels_setStickers::ID;

void channels_setStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-359881479);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void channels_setStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-359881479);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void channels_setStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.setStickers");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

channels_setStickers::ReturnType channels_setStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_toggleSlowMode::channels_toggleSlowMode(object_ptr<InputChannel> &&channel_, int32 seconds_)
  : channel_(std::move(channel_))
  , seconds_(seconds_)
{}

const std::int32_t channels_toggleSlowMode::ID;

void channels_toggleSlowMode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-304832784);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(seconds_, s);
}

void channels_toggleSlowMode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-304832784);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(seconds_, s);
}

void channels_toggleSlowMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleSlowMode");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("seconds", seconds_);
    s.store_class_end();
  }
}

channels_toggleSlowMode::ReturnType channels_toggleSlowMode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_updatePaidMessagesPrice::channels_updatePaidMessagesPrice(int32 flags_, bool broadcast_messages_allowed_, object_ptr<InputChannel> &&channel_, int64 send_paid_messages_stars_)
  : flags_(flags_)
  , broadcast_messages_allowed_(broadcast_messages_allowed_)
  , channel_(std::move(channel_))
  , send_paid_messages_stars_(send_paid_messages_stars_)
{}

const std::int32_t channels_updatePaidMessagesPrice::ID;

void channels_updatePaidMessagesPrice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1259483771);
  TlStoreBinary::store((var0 = flags_ | (broadcast_messages_allowed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(send_paid_messages_stars_, s);
}

void channels_updatePaidMessagesPrice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1259483771);
  TlStoreBinary::store((var0 = flags_ | (broadcast_messages_allowed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(send_paid_messages_stars_, s);
}

void channels_updatePaidMessagesPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.updatePaidMessagesPrice");
    s.store_field("flags", (var0 = flags_ | (broadcast_messages_allowed_ << 0)));
    if (var0 & 1) { s.store_field("broadcast_messages_allowed", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("send_paid_messages_stars", send_paid_messages_stars_);
    s.store_class_end();
  }
}

channels_updatePaidMessagesPrice::ReturnType channels_updatePaidMessagesPrice::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

chatlists_getChatlistUpdates::chatlists_getChatlistUpdates(object_ptr<inputChatlistDialogFilter> &&chatlist_)
  : chatlist_(std::move(chatlist_))
{}

const std::int32_t chatlists_getChatlistUpdates::ID;

void chatlists_getChatlistUpdates::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1992190687);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getChatlistUpdates::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1992190687);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getChatlistUpdates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.getChatlistUpdates");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_class_end();
  }
}

chatlists_getChatlistUpdates::ReturnType chatlists_getChatlistUpdates::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<chatlists_chatlistUpdates>, -1816295539>::parse(p);
#undef FAIL
}

contacts_editCloseFriends::contacts_editCloseFriends(array<int64> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t contacts_editCloseFriends::ID;

void contacts_editCloseFriends::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1167653392);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void contacts_editCloseFriends::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1167653392);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void contacts_editCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.editCloseFriends");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

contacts_editCloseFriends::ReturnType contacts_editCloseFriends::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t contacts_getBirthdays::ID;

void contacts_getBirthdays::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-621959068);
}

void contacts_getBirthdays::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-621959068);
}

void contacts_getBirthdays::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getBirthdays");
    s.store_class_end();
  }
}

contacts_getBirthdays::ReturnType contacts_getBirthdays::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<contacts_contactBirthdays>, 290452237>::parse(p);
#undef FAIL
}

contacts_getContacts::contacts_getContacts(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t contacts_getContacts::ID;

void contacts_getContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1574346258);
  TlStoreBinary::store(hash_, s);
}

void contacts_getContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1574346258);
  TlStoreBinary::store(hash_, s);
}

void contacts_getContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getContacts");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

contacts_getContacts::ReturnType contacts_getContacts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<contacts_Contacts>::parse(p);
#undef FAIL
}

ephemeral_getCallbackAnswer::ephemeral_getCallbackAnswer(int32 flags_, object_ptr<InputPeer> &&peer_, int32 id_, bytes &&data_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , data_(std::move(data_))
{}

const std::int32_t ephemeral_getCallbackAnswer::ID;

void ephemeral_getCallbackAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1067738312);
  TlStoreBinary::store((var0 = flags_ | ((!data_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 2) { TlStoreString::store(data_, s); }
}

void ephemeral_getCallbackAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1067738312);
  TlStoreBinary::store((var0 = flags_ | ((!data_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 2) { TlStoreString::store(data_, s); }
}

void ephemeral_getCallbackAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeral.getCallbackAnswer");
    s.store_field("flags", (var0 = flags_ | ((!data_.empty()) << 1)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 2) { s.store_bytes_field("data", data_); }
    s.store_class_end();
  }
}

ephemeral_getCallbackAnswer::ReturnType ephemeral_getCallbackAnswer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_botCallbackAnswer>, 911761060>::parse(p);
#undef FAIL
}

const std::int32_t help_getSupportName::ID;

void help_getSupportName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-748624084);
}

void help_getSupportName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-748624084);
}

void help_getSupportName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getSupportName");
    s.store_class_end();
  }
}

help_getSupportName::ReturnType help_getSupportName::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_supportName>, -1945767479>::parse(p);
#undef FAIL
}

help_hidePromoData::help_hidePromoData(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t help_hidePromoData::ID;

void help_hidePromoData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(505748629);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void help_hidePromoData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(505748629);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void help_hidePromoData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.hidePromoData");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

help_hidePromoData::ReturnType help_hidePromoData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deleteMessages::messages_deleteMessages(int32 flags_, bool revoke_, array<int32> &&id_)
  : flags_(flags_)
  , revoke_(revoke_)
  , id_(std::move(id_))
{}

const std::int32_t messages_deleteMessages::ID;

void messages_deleteMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-443640366);
  TlStoreBinary::store((var0 = flags_ | (revoke_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-443640366);
  TlStoreBinary::store((var0 = flags_ | (revoke_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteMessages");
    s.store_field("flags", (var0 = flags_ | (revoke_ << 0)));
    if (var0 & 1) { s.store_field("revoke", true); }
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_deleteMessages::ReturnType messages_deleteMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedMessages>, -2066640507>::parse(p);
#undef FAIL
}

messages_deleteSavedHistory::messages_deleteSavedHistory(int32 flags_, object_ptr<InputPeer> &&parent_peer_, object_ptr<InputPeer> &&peer_, int32 max_id_, int32 min_date_, int32 max_date_)
  : flags_(flags_)
  , parent_peer_(std::move(parent_peer_))
  , peer_(std::move(peer_))
  , max_id_(max_id_)
  , min_date_(min_date_)
  , max_date_(max_date_)
{}

const std::int32_t messages_deleteSavedHistory::ID;

void messages_deleteSavedHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1304758367);
  TlStoreBinary::store((var0 = flags_ | ((parent_peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
  if (var0 & 4) { TlStoreBinary::store(min_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(max_date_, s); }
}

void messages_deleteSavedHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1304758367);
  TlStoreBinary::store((var0 = flags_ | ((parent_peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
  if (var0 & 4) { TlStoreBinary::store(min_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(max_date_, s); }
}

void messages_deleteSavedHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteSavedHistory");
    s.store_field("flags", (var0 = flags_ | ((parent_peer_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    if (var0 & 4) { s.store_field("min_date", min_date_); }
    if (var0 & 8) { s.store_field("max_date", max_date_); }
    s.store_class_end();
  }
}

messages_deleteSavedHistory::ReturnType messages_deleteSavedHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_editMessageWidgetData::messages_editMessageWidgetData(int32 flags_, object_ptr<InputPeer> &&peer_, int32 id_, string const &public_data_, string const &chat_data_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , public_data_(public_data_)
  , chat_data_(chat_data_)
{}

const std::int32_t messages_editMessageWidgetData::ID;

void messages_editMessageWidgetData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-165364706);
  TlStoreBinary::store((var0 = flags_ | ((!public_data_.empty()) << 0) | ((!chat_data_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(public_data_, s); }
  if (var0 & 2) { TlStoreString::store(chat_data_, s); }
}

void messages_editMessageWidgetData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-165364706);
  TlStoreBinary::store((var0 = flags_ | ((!public_data_.empty()) << 0) | ((!chat_data_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(public_data_, s); }
  if (var0 & 2) { TlStoreString::store(chat_data_, s); }
}

void messages_editMessageWidgetData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editMessageWidgetData");
    s.store_field("flags", (var0 = flags_ | ((!public_data_.empty()) << 0) | ((!chat_data_.empty()) << 1)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("public_data", public_data_); }
    if (var0 & 2) { s.store_field("chat_data", chat_data_); }
    s.store_class_end();
  }
}

messages_editMessageWidgetData::ReturnType messages_editMessageWidgetData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_forwardMessages::messages_forwardMessages(int32 flags_, bool silent_, bool background_, bool with_my_score_, bool drop_author_, bool drop_media_captions_, bool noforwards_, bool allow_paid_floodskip_, bool from_ephemeral_, object_ptr<InputPeer> &&from_peer_, array<int32> &&id_, array<int64> &&random_id_, object_ptr<InputPeer> &&to_peer_, int32 top_msg_id_, object_ptr<InputReplyTo> &&reply_to_, int32 schedule_date_, int32 schedule_repeat_period_, object_ptr<InputPeer> &&send_as_, object_ptr<InputQuickReplyShortcut> &&quick_reply_shortcut_, int64 effect_, int32 video_timestamp_, int64 allow_paid_stars_, object_ptr<suggestedPost> &&suggested_post_)
  : flags_(flags_)
  , silent_(silent_)
  , background_(background_)
  , with_my_score_(with_my_score_)
  , drop_author_(drop_author_)
  , drop_media_captions_(drop_media_captions_)
  , noforwards_(noforwards_)
  , allow_paid_floodskip_(allow_paid_floodskip_)
  , from_ephemeral_(from_ephemeral_)
  , from_peer_(std::move(from_peer_))
  , id_(std::move(id_))
  , random_id_(std::move(random_id_))
  , to_peer_(std::move(to_peer_))
  , top_msg_id_(top_msg_id_)
  , reply_to_(std::move(reply_to_))
  , schedule_date_(schedule_date_)
  , schedule_repeat_period_(schedule_repeat_period_)
  , send_as_(std::move(send_as_))
  , quick_reply_shortcut_(std::move(quick_reply_shortcut_))
  , effect_(effect_)
  , video_timestamp_(video_timestamp_)
  , allow_paid_stars_(allow_paid_stars_)
  , suggested_post_(std::move(suggested_post_))
{}

const std::int32_t messages_forwardMessages::ID;

void messages_forwardMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(326126204);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (with_my_score_ << 8) | (drop_author_ << 11) | (drop_media_captions_ << 12) | (noforwards_ << 14) | (allow_paid_floodskip_ << 19) | (from_ephemeral_ << 25) | ((reply_to_ != nullptr) << 22) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17) | ((suggested_post_ != nullptr) << 23)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(from_peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(random_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_peer_, s);
  if (var0 & 512) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 4194304) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 1048576) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 8388608) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_forwardMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(326126204);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (with_my_score_ << 8) | (drop_author_ << 11) | (drop_media_captions_ << 12) | (noforwards_ << 14) | (allow_paid_floodskip_ << 19) | (from_ephemeral_ << 25) | ((reply_to_ != nullptr) << 22) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17) | ((suggested_post_ != nullptr) << 23)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(from_peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(random_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_peer_, s);
  if (var0 & 512) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 4194304) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 1048576) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 8388608) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_forwardMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.forwardMessages");
    s.store_field("flags", (var0 = flags_ | (silent_ << 5) | (background_ << 6) | (with_my_score_ << 8) | (drop_author_ << 11) | (drop_media_captions_ << 12) | (noforwards_ << 14) | (allow_paid_floodskip_ << 19) | (from_ephemeral_ << 25) | ((reply_to_ != nullptr) << 22) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17) | ((suggested_post_ != nullptr) << 23)));
    if (var0 & 32) { s.store_field("silent", true); }
    if (var0 & 64) { s.store_field("background", true); }
    if (var0 & 256) { s.store_field("with_my_score", true); }
    if (var0 & 2048) { s.store_field("drop_author", true); }
    if (var0 & 4096) { s.store_field("drop_media_captions", true); }
    if (var0 & 16384) { s.store_field("noforwards", true); }
    if (var0 & 524288) { s.store_field("allow_paid_floodskip", true); }
    if (var0 & 33554432) { s.store_field("from_ephemeral", true); }
    s.store_object_field("from_peer", static_cast<const BaseObject *>(from_peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("random_id", random_id_.size()); for (const auto &_value : random_id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("to_peer", static_cast<const BaseObject *>(to_peer_.get()));
    if (var0 & 512) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 4194304) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    if (var0 & 1024) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 16777216) { s.store_field("schedule_repeat_period", schedule_repeat_period_); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    if (var0 & 131072) { s.store_object_field("quick_reply_shortcut", static_cast<const BaseObject *>(quick_reply_shortcut_.get())); }
    if (var0 & 262144) { s.store_field("effect", effect_); }
    if (var0 & 1048576) { s.store_field("video_timestamp", video_timestamp_); }
    if (var0 & 2097152) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    if (var0 & 8388608) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    s.store_class_end();
  }
}

messages_forwardMessages::ReturnType messages_forwardMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getAllStickers::messages_getAllStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getAllStickers::ID;

void messages_getAllStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1197432408);
  TlStoreBinary::store(hash_, s);
}

void messages_getAllStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1197432408);
  TlStoreBinary::store(hash_, s);
}

void messages_getAllStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAllStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getAllStickers::ReturnType messages_getAllStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_AllStickers>::parse(p);
#undef FAIL
}

messages_getBotWidgetQueryAnswer::messages_getBotWidgetQueryAnswer(object_ptr<InputPeer> &&peer_, int32 msg_id_, object_ptr<WidgetQueryType> &&query_type_, bytes &&data_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , query_type_(std::move(query_type_))
  , data_(std::move(data_))
{}

const std::int32_t messages_getBotWidgetQueryAnswer::ID;

void messages_getBotWidgetQueryAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1549075833);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(query_type_, s);
  TlStoreString::store(data_, s);
}

void messages_getBotWidgetQueryAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1549075833);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(query_type_, s);
  TlStoreString::store(data_, s);
}

void messages_getBotWidgetQueryAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getBotWidgetQueryAnswer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_object_field("query_type", static_cast<const BaseObject *>(query_type_.get()));
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

messages_getBotWidgetQueryAnswer::ReturnType messages_getBotWidgetQueryAnswer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_botWidgetQueryAnswer>, -1783156701>::parse(p);
#undef FAIL
}

messages_getChatInviteImporters::messages_getChatInviteImporters(int32 flags_, bool requested_, bool subscription_expired_, object_ptr<InputPeer> &&peer_, string const &link_, string const &q_, int32 offset_date_, object_ptr<InputUser> &&offset_user_, int32 limit_)
  : flags_(flags_)
  , requested_(requested_)
  , subscription_expired_(subscription_expired_)
  , peer_(std::move(peer_))
  , link_(link_)
  , q_(q_)
  , offset_date_(offset_date_)
  , offset_user_(std::move(offset_user_))
  , limit_(limit_)
{}

const std::int32_t messages_getChatInviteImporters::ID;

void messages_getChatInviteImporters::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-553329330);
  TlStoreBinary::store((var0 = flags_ | (requested_ << 0) | (subscription_expired_ << 3) | ((!link_.empty()) << 1) | ((!q_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(link_, s); }
  if (var0 & 4) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_user_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getChatInviteImporters::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-553329330);
  TlStoreBinary::store((var0 = flags_ | (requested_ << 0) | (subscription_expired_ << 3) | ((!link_.empty()) << 1) | ((!q_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(link_, s); }
  if (var0 & 4) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_user_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getChatInviteImporters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getChatInviteImporters");
    s.store_field("flags", (var0 = flags_ | (requested_ << 0) | (subscription_expired_ << 3) | ((!link_.empty()) << 1) | ((!q_.empty()) << 2)));
    if (var0 & 1) { s.store_field("requested", true); }
    if (var0 & 8) { s.store_field("subscription_expired", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_field("link", link_); }
    if (var0 & 4) { s.store_field("q", q_); }
    s.store_field("offset_date", offset_date_);
    s.store_object_field("offset_user", static_cast<const BaseObject *>(offset_user_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getChatInviteImporters::ReturnType messages_getChatInviteImporters::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_chatInviteImporters>, -2118733814>::parse(p);
#undef FAIL
}

messages_getDhConfig::messages_getDhConfig(int32 version_, int32 random_length_)
  : version_(version_)
  , random_length_(random_length_)
{}

const std::int32_t messages_getDhConfig::ID;

void messages_getDhConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(651135312);
  TlStoreBinary::store(version_, s);
  TlStoreBinary::store(random_length_, s);
}

void messages_getDhConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(651135312);
  TlStoreBinary::store(version_, s);
  TlStoreBinary::store(random_length_, s);
}

void messages_getDhConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDhConfig");
    s.store_field("version", version_);
    s.store_field("random_length", random_length_);
    s.store_class_end();
  }
}

messages_getDhConfig::ReturnType messages_getDhConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_DhConfig>::parse(p);
#undef FAIL
}

messages_getDialogs::messages_getDialogs(int32 flags_, bool exclude_pinned_, int32 folder_id_, int32 offset_date_, int32 offset_id_, object_ptr<InputPeer> &&offset_peer_, int32 limit_, int64 hash_)
  : flags_(flags_)
  , exclude_pinned_(exclude_pinned_)
  , folder_id_(folder_id_)
  , offset_date_(offset_date_)
  , offset_id_(offset_id_)
  , offset_peer_(std::move(offset_peer_))
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getDialogs::ID;

void messages_getDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1594569905);
  TlStoreBinary::store((var0 = flags_ | (exclude_pinned_ << 0)), s);
  if (var0 & 2) { TlStoreBinary::store(folder_id_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1594569905);
  TlStoreBinary::store((var0 = flags_ | (exclude_pinned_ << 0)), s);
  if (var0 & 2) { TlStoreBinary::store(folder_id_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDialogs");
    s.store_field("flags", (var0 = flags_ | (exclude_pinned_ << 0)));
    if (var0 & 1) { s.store_field("exclude_pinned", true); }
    if (var0 & 2) { s.store_field("folder_id", folder_id_); }
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_id", offset_id_);
    s.store_object_field("offset_peer", static_cast<const BaseObject *>(offset_peer_.get()));
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getDialogs::ReturnType messages_getDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Dialogs>::parse(p);
#undef FAIL
}

messages_getDocumentByHash::messages_getDocumentByHash(bytes &&sha256_, int64 size_, string const &mime_type_)
  : sha256_(std::move(sha256_))
  , size_(size_)
  , mime_type_(mime_type_)
{}

const std::int32_t messages_getDocumentByHash::ID;

void messages_getDocumentByHash::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1309538785);
  TlStoreString::store(sha256_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
}

void messages_getDocumentByHash::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1309538785);
  TlStoreString::store(sha256_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
}

void messages_getDocumentByHash::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDocumentByHash");
    s.store_bytes_field("sha256", sha256_);
    s.store_field("size", size_);
    s.store_field("mime_type", mime_type_);
    s.store_class_end();
  }
}

messages_getDocumentByHash::ReturnType messages_getDocumentByHash::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Document>::parse(p);
#undef FAIL
}

messages_getFactCheck::messages_getFactCheck(object_ptr<InputPeer> &&peer_, array<int32> &&msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(std::move(msg_id_))
{}

const std::int32_t messages_getFactCheck::ID;

void messages_getFactCheck::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1177696786);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(msg_id_, s);
}

void messages_getFactCheck::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1177696786);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(msg_id_, s);
}

void messages_getFactCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFactCheck");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("msg_id", msg_id_.size()); for (const auto &_value : msg_id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getFactCheck::ReturnType messages_getFactCheck::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<factCheck>, -1197736753>>, 481674261>::parse(p);
#undef FAIL
}

messages_getMyStickers::messages_getMyStickers(int64 offset_id_, int32 limit_)
  : offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t messages_getMyStickers::ID;

void messages_getMyStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-793386500);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getMyStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-793386500);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getMyStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMyStickers");
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getMyStickers::ReturnType messages_getMyStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_myStickers>, -83926371>::parse(p);
#undef FAIL
}

const std::int32_t messages_getPaidReactionPrivacy::ID;

void messages_getPaidReactionPrivacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1193563562);
}

void messages_getPaidReactionPrivacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1193563562);
}

void messages_getPaidReactionPrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPaidReactionPrivacy");
    s.store_class_end();
  }
}

messages_getPaidReactionPrivacy::ReturnType messages_getPaidReactionPrivacy::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_installStickerSet::messages_installStickerSet(object_ptr<InputStickerSet> &&stickerset_, bool archived_)
  : stickerset_(std::move(stickerset_))
  , archived_(archived_)
{}

const std::int32_t messages_installStickerSet::ID;

void messages_installStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-946871200);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBool::store(archived_, s);
}

void messages_installStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-946871200);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBool::store(archived_, s);
}

void messages_installStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.installStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("archived", archived_);
    s.store_class_end();
  }
}

messages_installStickerSet::ReturnType messages_installStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSetInstallResult>::parse(p);
#undef FAIL
}

messages_readMentions::messages_readMentions(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
{}

const std::int32_t messages_readMentions::ID;

void messages_readMentions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(921026381);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
}

void messages_readMentions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(921026381);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
}

void messages_readMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readMentions");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_class_end();
  }
}

messages_readMentions::ReturnType messages_readMentions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_reorderPinnedForumTopics::messages_reorderPinnedForumTopics(int32 flags_, bool force_, object_ptr<InputPeer> &&peer_, array<int32> &&order_)
  : flags_(flags_)
  , force_(force_)
  , peer_(std::move(peer_))
  , order_(std::move(order_))
{}

const std::int32_t messages_reorderPinnedForumTopics::ID;

void messages_reorderPinnedForumTopics::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(242762224);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderPinnedForumTopics::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(242762224);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderPinnedForumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reorderPinnedForumTopics");
    s.store_field("flags", (var0 = flags_ | (force_ << 0)));
    if (var0 & 1) { s.store_field("force", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reorderPinnedForumTopics::ReturnType messages_reorderPinnedForumTopics::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_reportMusicListen::messages_reportMusicListen(object_ptr<InputDocument> &&id_, int32 listened_duration_)
  : id_(std::move(id_))
  , listened_duration_(listened_duration_)
{}

const std::int32_t messages_reportMusicListen::ID;

void messages_reportMusicListen::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-574826471);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBinary::store(listened_duration_, s);
}

void messages_reportMusicListen::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-574826471);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBinary::store(listened_duration_, s);
}

void messages_reportMusicListen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportMusicListen");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("listened_duration", listened_duration_);
    s.store_class_end();
  }
}

messages_reportMusicListen::ReturnType messages_reportMusicListen::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_requestAppWebView::messages_requestAppWebView(int32 flags_, bool write_allowed_, bool compact_, bool fullscreen_, object_ptr<InputPeer> &&peer_, object_ptr<InputBotApp> &&app_, string const &start_param_, object_ptr<dataJSON> &&theme_params_, string const &platform_)
  : flags_(flags_)
  , write_allowed_(write_allowed_)
  , compact_(compact_)
  , fullscreen_(fullscreen_)
  , peer_(std::move(peer_))
  , app_(std::move(app_))
  , start_param_(start_param_)
  , theme_params_(std::move(theme_params_))
  , platform_(platform_)
{}

const std::int32_t messages_requestAppWebView::ID;

void messages_requestAppWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1398901710);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0) | (compact_ << 7) | (fullscreen_ << 8) | ((!start_param_.empty()) << 1) | ((theme_params_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(app_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestAppWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1398901710);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0) | (compact_ << 7) | (fullscreen_ << 8) | ((!start_param_.empty()) << 1) | ((theme_params_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(app_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestAppWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestAppWebView");
    s.store_field("flags", (var0 = flags_ | (write_allowed_ << 0) | (compact_ << 7) | (fullscreen_ << 8) | ((!start_param_.empty()) << 1) | ((theme_params_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("write_allowed", true); }
    if (var0 & 128) { s.store_field("compact", true); }
    if (var0 & 256) { s.store_field("fullscreen", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("app", static_cast<const BaseObject *>(app_.get()));
    if (var0 & 2) { s.store_field("start_param", start_param_); }
    if (var0 & 4) { s.store_object_field("theme_params", static_cast<const BaseObject *>(theme_params_.get())); }
    s.store_field("platform", platform_);
    s.store_class_end();
  }
}

messages_requestAppWebView::ReturnType messages_requestAppWebView::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<webViewResultUrl>, 1294139288>::parse(p);
#undef FAIL
}

messages_requestWebView::messages_requestWebView(int32 flags_, bool from_bot_menu_, bool silent_, bool compact_, bool fullscreen_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&bot_, string const &url_, string const &start_param_, object_ptr<dataJSON> &&theme_params_, string const &platform_, object_ptr<InputReplyTo> &&reply_to_, object_ptr<InputPeer> &&send_as_)
  : flags_(flags_)
  , from_bot_menu_(from_bot_menu_)
  , silent_(silent_)
  , compact_(compact_)
  , fullscreen_(fullscreen_)
  , peer_(std::move(peer_))
  , bot_(std::move(bot_))
  , url_(url_)
  , start_param_(start_param_)
  , theme_params_(std::move(theme_params_))
  , platform_(platform_)
  , reply_to_(std::move(reply_to_))
  , send_as_(std::move(send_as_))
{}

const std::int32_t messages_requestWebView::ID;

void messages_requestWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(647873217);
  TlStoreBinary::store((var0 = flags_ | (from_bot_menu_ << 4) | (silent_ << 5) | (compact_ << 7) | (fullscreen_ << 8) | ((!url_.empty()) << 1) | ((!start_param_.empty()) << 3) | ((theme_params_ != nullptr) << 2) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 2) { TlStoreString::store(url_, s); }
  if (var0 & 8) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_requestWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(647873217);
  TlStoreBinary::store((var0 = flags_ | (from_bot_menu_ << 4) | (silent_ << 5) | (compact_ << 7) | (fullscreen_ << 8) | ((!url_.empty()) << 1) | ((!start_param_.empty()) << 3) | ((theme_params_ != nullptr) << 2) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 2) { TlStoreString::store(url_, s); }
  if (var0 & 8) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_requestWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestWebView");
    s.store_field("flags", (var0 = flags_ | (from_bot_menu_ << 4) | (silent_ << 5) | (compact_ << 7) | (fullscreen_ << 8) | ((!url_.empty()) << 1) | ((!start_param_.empty()) << 3) | ((theme_params_ != nullptr) << 2) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13)));
    if (var0 & 16) { s.store_field("from_bot_menu", true); }
    if (var0 & 32) { s.store_field("silent", true); }
    if (var0 & 128) { s.store_field("compact", true); }
    if (var0 & 256) { s.store_field("fullscreen", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    if (var0 & 2) { s.store_field("url", url_); }
    if (var0 & 8) { s.store_field("start_param", start_param_); }
    if (var0 & 4) { s.store_object_field("theme_params", static_cast<const BaseObject *>(theme_params_.get())); }
    s.store_field("platform", platform_);
    if (var0 & 1) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    s.store_class_end();
  }
}

messages_requestWebView::ReturnType messages_requestWebView::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<webViewResultUrl>, 1294139288>::parse(p);
#undef FAIL
}

messages_searchGlobal::messages_searchGlobal(int32 flags_, bool broadcasts_only_, bool groups_only_, bool users_only_, int32 folder_id_, object_ptr<InputChannel> &&community_, string const &q_, object_ptr<MessagesFilter> &&filter_, int32 min_date_, int32 max_date_, int32 offset_rate_, object_ptr<InputPeer> &&offset_peer_, int32 offset_id_, int32 limit_)
  : flags_(flags_)
  , broadcasts_only_(broadcasts_only_)
  , groups_only_(groups_only_)
  , users_only_(users_only_)
  , folder_id_(folder_id_)
  , community_(std::move(community_))
  , q_(q_)
  , filter_(std::move(filter_))
  , min_date_(min_date_)
  , max_date_(max_date_)
  , offset_rate_(offset_rate_)
  , offset_peer_(std::move(offset_peer_))
  , offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t messages_searchGlobal::ID;

void messages_searchGlobal::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1629922364);
  TlStoreBinary::store((var0 = flags_ | (broadcasts_only_ << 1) | (groups_only_ << 2) | (users_only_ << 3) | ((community_ != nullptr) << 4)), s);
  if (var0 & 1) { TlStoreBinary::store(folder_id_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(community_, s); }
  TlStoreString::store(q_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(min_date_, s);
  TlStoreBinary::store(max_date_, s);
  TlStoreBinary::store(offset_rate_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_searchGlobal::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1629922364);
  TlStoreBinary::store((var0 = flags_ | (broadcasts_only_ << 1) | (groups_only_ << 2) | (users_only_ << 3) | ((community_ != nullptr) << 4)), s);
  if (var0 & 1) { TlStoreBinary::store(folder_id_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(community_, s); }
  TlStoreString::store(q_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(min_date_, s);
  TlStoreBinary::store(max_date_, s);
  TlStoreBinary::store(offset_rate_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_searchGlobal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchGlobal");
    s.store_field("flags", (var0 = flags_ | (broadcasts_only_ << 1) | (groups_only_ << 2) | (users_only_ << 3) | ((community_ != nullptr) << 4)));
    if (var0 & 2) { s.store_field("broadcasts_only", true); }
    if (var0 & 4) { s.store_field("groups_only", true); }
    if (var0 & 8) { s.store_field("users_only", true); }
    if (var0 & 1) { s.store_field("folder_id", folder_id_); }
    if (var0 & 16) { s.store_object_field("community", static_cast<const BaseObject *>(community_.get())); }
    s.store_field("q", q_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_field("offset_rate", offset_rate_);
    s.store_object_field("offset_peer", static_cast<const BaseObject *>(offset_peer_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_searchGlobal::ReturnType messages_searchGlobal::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_sendMedia::messages_sendMedia(int32 flags_, bool silent_, bool background_, bool clear_draft_, bool noforwards_, bool update_stickersets_order_, bool invert_media_, bool allow_paid_floodskip_, object_ptr<InputPeer> &&peer_, object_ptr<InputReplyTo> &&reply_to_, object_ptr<InputMedia> &&media_, string const &message_, int64 random_id_, object_ptr<ReplyMarkup> &&reply_markup_, array<object_ptr<MessageEntity>> &&entities_, int32 schedule_date_, int32 schedule_repeat_period_, object_ptr<InputPeer> &&send_as_, object_ptr<InputQuickReplyShortcut> &&quick_reply_shortcut_, int64 effect_, int64 allow_paid_stars_, object_ptr<suggestedPost> &&suggested_post_)
  : flags_(flags_)
  , silent_(silent_)
  , background_(background_)
  , clear_draft_(clear_draft_)
  , noforwards_(noforwards_)
  , update_stickersets_order_(update_stickersets_order_)
  , invert_media_(invert_media_)
  , allow_paid_floodskip_(allow_paid_floodskip_)
  , peer_(std::move(peer_))
  , reply_to_(std::move(reply_to_))
  , media_(std::move(media_))
  , message_(message_)
  , random_id_(random_id_)
  , reply_markup_(std::move(reply_markup_))
  , entities_(std::move(entities_))
  , schedule_date_(schedule_date_)
  , schedule_repeat_period_(schedule_repeat_period_)
  , send_as_(std::move(send_as_))
  , quick_reply_shortcut_(std::move(quick_reply_shortcut_))
  , effect_(effect_)
  , allow_paid_stars_(allow_paid_stars_)
  , suggested_post_(std::move(suggested_post_))
{}

const std::int32_t messages_sendMedia::ID;

void messages_sendMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(53536639);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19) | ((reply_to_ != nullptr) << 0) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17) | ((suggested_post_ != nullptr) << 22)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreString::store(message_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 4194304) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_sendMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(53536639);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19) | ((reply_to_ != nullptr) << 0) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17) | ((suggested_post_ != nullptr) << 22)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreString::store(message_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 4194304) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_sendMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendMedia");
    s.store_field("flags", (var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19) | ((reply_to_ != nullptr) << 0) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17) | ((suggested_post_ != nullptr) << 22)));
    if (var0 & 32) { s.store_field("silent", true); }
    if (var0 & 64) { s.store_field("background", true); }
    if (var0 & 128) { s.store_field("clear_draft", true); }
    if (var0 & 16384) { s.store_field("noforwards", true); }
    if (var0 & 32768) { s.store_field("update_stickersets_order", true); }
    if (var0 & 65536) { s.store_field("invert_media", true); }
    if (var0 & 524288) { s.store_field("allow_paid_floodskip", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_field("message", message_);
    s.store_field("random_id", random_id_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1024) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 16777216) { s.store_field("schedule_repeat_period", schedule_repeat_period_); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    if (var0 & 131072) { s.store_object_field("quick_reply_shortcut", static_cast<const BaseObject *>(quick_reply_shortcut_.get())); }
    if (var0 & 262144) { s.store_field("effect", effect_); }
    if (var0 & 2097152) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    if (var0 & 4194304) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    s.store_class_end();
  }
}

messages_sendMedia::ReturnType messages_sendMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setEncryptedTyping::messages_setEncryptedTyping(object_ptr<inputEncryptedChat> &&peer_, bool typing_)
  : peer_(std::move(peer_))
  , typing_(typing_)
{}

const std::int32_t messages_setEncryptedTyping::ID;

void messages_setEncryptedTyping::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2031374829);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBool::store(typing_, s);
}

void messages_setEncryptedTyping::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2031374829);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBool::store(typing_, s);
}

void messages_setEncryptedTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setEncryptedTyping");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("typing", typing_);
    s.store_class_end();
  }
}

messages_setEncryptedTyping::ReturnType messages_setEncryptedTyping::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_setHistoryTTL::messages_setHistoryTTL(object_ptr<InputPeer> &&peer_, int32 period_)
  : peer_(std::move(peer_))
  , period_(period_)
{}

const std::int32_t messages_setHistoryTTL::ID;

void messages_setHistoryTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1207017500);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(period_, s);
}

void messages_setHistoryTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1207017500);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(period_, s);
}

void messages_setHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setHistoryTTL");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("period", period_);
    s.store_class_end();
  }
}

messages_setHistoryTTL::ReturnType messages_setHistoryTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_translateRichMessage::messages_translateRichMessage(int32 flags_, object_ptr<InputPeer> &&peer_, array<int32> &&id_, array<object_ptr<InputRichMessage>> &&text_, string const &to_lang_, string const &tone_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(std::move(id_))
  , text_(std::move(text_))
  , to_lang_(to_lang_)
  , tone_(tone_)
{}

const std::int32_t messages_translateRichMessage::ID;

void messages_translateRichMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(441720836);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0) | ((!id_.empty()) << 0) | ((!text_.empty()) << 1) | ((!tone_.empty()) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(text_, s); }
  TlStoreString::store(to_lang_, s);
  if (var0 & 4) { TlStoreString::store(tone_, s); }
}

void messages_translateRichMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(441720836);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0) | ((!id_.empty()) << 0) | ((!text_.empty()) << 1) | ((!tone_.empty()) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(text_, s); }
  TlStoreString::store(to_lang_, s);
  if (var0 & 4) { TlStoreString::store(tone_, s); }
}

void messages_translateRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.translateRichMessage");
    s.store_field("flags", (var0 = flags_ | ((peer_ != nullptr) << 0) | ((!id_.empty()) << 0) | ((!text_.empty()) << 1) | ((!tone_.empty()) << 2)));
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 1) { { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 2) { { s.store_vector_begin("text", text_.size()); for (const auto &_value : text_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("to_lang", to_lang_);
    if (var0 & 4) { s.store_field("tone", tone_); }
    s.store_class_end();
  }
}

messages_translateRichMessage::ReturnType messages_translateRichMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_translatedRichMessage>, 1107532175>::parse(p);
#undef FAIL
}

messages_uploadEncryptedFile::messages_uploadEncryptedFile(object_ptr<inputEncryptedChat> &&peer_, object_ptr<InputEncryptedFile> &&file_)
  : peer_(std::move(peer_))
  , file_(std::move(file_))
{}

const std::int32_t messages_uploadEncryptedFile::ID;

void messages_uploadEncryptedFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1347929239);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void messages_uploadEncryptedFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1347929239);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void messages_uploadEncryptedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.uploadEncryptedFile");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

messages_uploadEncryptedFile::ReturnType messages_uploadEncryptedFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EncryptedFile>::parse(p);
#undef FAIL
}

messages_viewSponsoredMessage::messages_viewSponsoredMessage(bytes &&random_id_)
  : random_id_(std::move(random_id_))
{}

const std::int32_t messages_viewSponsoredMessage::ID;

void messages_viewSponsoredMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(647902787);
  TlStoreString::store(random_id_, s);
}

void messages_viewSponsoredMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(647902787);
  TlStoreString::store(random_id_, s);
}

void messages_viewSponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.viewSponsoredMessage");
    s.store_bytes_field("random_id", random_id_);
    s.store_class_end();
  }
}

messages_viewSponsoredMessage::ReturnType messages_viewSponsoredMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_buyStarGiftOnchain::payments_buyStarGiftOnchain(int32 flags_, bool show_name_, string const &slug_, int64 expected_amount_, object_ptr<InputPeer> &&peer_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , show_name_(show_name_)
  , slug_(slug_)
  , expected_amount_(expected_amount_)
  , peer_(std::move(peer_))
  , message_(std::move(message_))
{}

const std::int32_t payments_buyStarGiftOnchain::ID;

void payments_buyStarGiftOnchain::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1551278953);
  TlStoreBinary::store((var0 = flags_ | (show_name_ << 2) | ((peer_ != nullptr) << 0) | ((message_ != nullptr) << 1)), s);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(expected_amount_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void payments_buyStarGiftOnchain::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1551278953);
  TlStoreBinary::store((var0 = flags_ | (show_name_ << 2) | ((peer_ != nullptr) << 0) | ((message_ != nullptr) << 1)), s);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(expected_amount_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void payments_buyStarGiftOnchain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.buyStarGiftOnchain");
    s.store_field("flags", (var0 = flags_ | (show_name_ << 2) | ((peer_ != nullptr) << 0) | ((message_ != nullptr) << 1)));
    if (var0 & 4) { s.store_field("show_name", true); }
    s.store_field("slug", slug_);
    s.store_field("expected_amount", expected_amount_);
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

payments_buyStarGiftOnchain::ReturnType payments_buyStarGiftOnchain::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_StarGiftOnchainSalePayload>::parse(p);
#undef FAIL
}

payments_editConnectedStarRefBot::payments_editConnectedStarRefBot(int32 flags_, bool revoked_, object_ptr<InputPeer> &&peer_, string const &link_)
  : flags_(flags_)
  , revoked_(revoked_)
  , peer_(std::move(peer_))
  , link_(link_)
{}

const std::int32_t payments_editConnectedStarRefBot::ID;

void payments_editConnectedStarRefBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-453204829);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void payments_editConnectedStarRefBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-453204829);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void payments_editConnectedStarRefBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.editConnectedStarRefBot");
    s.store_field("flags", (var0 = flags_ | (revoked_ << 0)));
    if (var0 & 1) { s.store_field("revoked", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("link", link_);
    s.store_class_end();
  }
}

payments_editConnectedStarRefBot::ReturnType payments_editConnectedStarRefBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_connectedStarRefBots>, -1730811363>::parse(p);
#undef FAIL
}

payments_getOnrampAvailability::payments_getOnrampAvailability(int32 flags_, string const &provider_, string const &crypto_currency_, string const &base_currency_)
  : flags_(flags_)
  , provider_(provider_)
  , crypto_currency_(crypto_currency_)
  , base_currency_(base_currency_)
{}

const std::int32_t payments_getOnrampAvailability::ID;

void payments_getOnrampAvailability::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(784505169);
  TlStoreBinary::store((var0 = flags_ | ((!base_currency_.empty()) << 0)), s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(crypto_currency_, s);
  if (var0 & 1) { TlStoreString::store(base_currency_, s); }
}

void payments_getOnrampAvailability::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(784505169);
  TlStoreBinary::store((var0 = flags_ | ((!base_currency_.empty()) << 0)), s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(crypto_currency_, s);
  if (var0 & 1) { TlStoreString::store(base_currency_, s); }
}

void payments_getOnrampAvailability::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getOnrampAvailability");
    s.store_field("flags", (var0 = flags_ | ((!base_currency_.empty()) << 0)));
    s.store_field("provider", provider_);
    s.store_field("crypto_currency", crypto_currency_);
    if (var0 & 1) { s.store_field("base_currency", base_currency_); }
    s.store_class_end();
  }
}

payments_getOnrampAvailability::ReturnType payments_getOnrampAvailability::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<onrampAvailability>, -104314509>::parse(p);
#undef FAIL
}

payments_getPremiumGiftCodeOptions::payments_getPremiumGiftCodeOptions(int32 flags_, object_ptr<InputPeer> &&boost_peer_)
  : flags_(flags_)
  , boost_peer_(std::move(boost_peer_))
{}

const std::int32_t payments_getPremiumGiftCodeOptions::ID;

void payments_getPremiumGiftCodeOptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(660060756);
  TlStoreBinary::store((var0 = flags_ | ((boost_peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s); }
}

void payments_getPremiumGiftCodeOptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(660060756);
  TlStoreBinary::store((var0 = flags_ | ((boost_peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s); }
}

void payments_getPremiumGiftCodeOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getPremiumGiftCodeOptions");
    s.store_field("flags", (var0 = flags_ | ((boost_peer_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get())); }
    s.store_class_end();
  }
}

payments_getPremiumGiftCodeOptions::ReturnType payments_getPremiumGiftCodeOptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<premiumGiftCodeOption>, 629052971>>, 481674261>::parse(p);
#undef FAIL
}

const std::int32_t payments_getSavedInfo::ID;

void payments_getSavedInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(578650699);
}

void payments_getSavedInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(578650699);
}

void payments_getSavedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getSavedInfo");
    s.store_class_end();
  }
}

payments_getSavedInfo::ReturnType payments_getSavedInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_savedInfo>, -74456004>::parse(p);
#undef FAIL
}

payments_getSavedStarGifts::payments_getSavedStarGifts(int32 flags_, bool exclude_unsaved_, bool exclude_saved_, bool exclude_unlimited_, bool exclude_unique_, bool sort_by_value_, bool exclude_upgradable_, bool exclude_unupgradable_, bool peer_color_available_, bool exclude_hosted_, object_ptr<InputPeer> &&peer_, int32 collection_id_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , exclude_unsaved_(exclude_unsaved_)
  , exclude_saved_(exclude_saved_)
  , exclude_unlimited_(exclude_unlimited_)
  , exclude_unique_(exclude_unique_)
  , sort_by_value_(sort_by_value_)
  , exclude_upgradable_(exclude_upgradable_)
  , exclude_unupgradable_(exclude_unupgradable_)
  , peer_color_available_(peer_color_available_)
  , exclude_hosted_(exclude_hosted_)
  , peer_(std::move(peer_))
  , collection_id_(collection_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t payments_getSavedStarGifts::ID;

void payments_getSavedStarGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1558583959);
  TlStoreBinary::store((var0 = flags_ | (exclude_unsaved_ << 0) | (exclude_saved_ << 1) | (exclude_unlimited_ << 2) | (exclude_unique_ << 4) | (sort_by_value_ << 5) | (exclude_upgradable_ << 7) | (exclude_unupgradable_ << 8) | (peer_color_available_ << 9) | (exclude_hosted_ << 10)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 64) { TlStoreBinary::store(collection_id_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getSavedStarGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1558583959);
  TlStoreBinary::store((var0 = flags_ | (exclude_unsaved_ << 0) | (exclude_saved_ << 1) | (exclude_unlimited_ << 2) | (exclude_unique_ << 4) | (sort_by_value_ << 5) | (exclude_upgradable_ << 7) | (exclude_unupgradable_ << 8) | (peer_color_available_ << 9) | (exclude_hosted_ << 10)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 64) { TlStoreBinary::store(collection_id_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getSavedStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getSavedStarGifts");
    s.store_field("flags", (var0 = flags_ | (exclude_unsaved_ << 0) | (exclude_saved_ << 1) | (exclude_unlimited_ << 2) | (exclude_unique_ << 4) | (sort_by_value_ << 5) | (exclude_upgradable_ << 7) | (exclude_unupgradable_ << 8) | (peer_color_available_ << 9) | (exclude_hosted_ << 10)));
    if (var0 & 1) { s.store_field("exclude_unsaved", true); }
    if (var0 & 2) { s.store_field("exclude_saved", true); }
    if (var0 & 4) { s.store_field("exclude_unlimited", true); }
    if (var0 & 16) { s.store_field("exclude_unique", true); }
    if (var0 & 32) { s.store_field("sort_by_value", true); }
    if (var0 & 128) { s.store_field("exclude_upgradable", true); }
    if (var0 & 256) { s.store_field("exclude_unupgradable", true); }
    if (var0 & 512) { s.store_field("peer_color_available", true); }
    if (var0 & 1024) { s.store_field("exclude_hosted", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 64) { s.store_field("collection_id", collection_id_); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getSavedStarGifts::ReturnType payments_getSavedStarGifts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_savedStarGifts>, -1779201615>::parse(p);
#undef FAIL
}

payments_getStarGiftActiveAuctions::payments_getStarGiftActiveAuctions(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t payments_getStarGiftActiveAuctions::ID;

void payments_getStarGiftActiveAuctions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1513074355);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGiftActiveAuctions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1513074355);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGiftActiveAuctions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftActiveAuctions");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

payments_getStarGiftActiveAuctions::ReturnType payments_getStarGiftActiveAuctions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_StarGiftActiveAuctions>::parse(p);
#undef FAIL
}

payments_saveStarGift::payments_saveStarGift(int32 flags_, bool unsave_, object_ptr<InputSavedStarGift> &&stargift_)
  : flags_(flags_)
  , unsave_(unsave_)
  , stargift_(std::move(stargift_))
{}

const std::int32_t payments_saveStarGift::ID;

void payments_saveStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(707422588);
  TlStoreBinary::store((var0 = flags_ | (unsave_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_saveStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(707422588);
  TlStoreBinary::store((var0 = flags_ | (unsave_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_saveStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.saveStarGift");
    s.store_field("flags", (var0 = flags_ | (unsave_ << 0)));
    if (var0 & 1) { s.store_field("unsave", true); }
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

payments_saveStarGift::ReturnType payments_saveStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_upgradeStarGift::payments_upgradeStarGift(int32 flags_, bool keep_original_details_, object_ptr<InputSavedStarGift> &&stargift_)
  : flags_(flags_)
  , keep_original_details_(keep_original_details_)
  , stargift_(std::move(stargift_))
{}

const std::int32_t payments_upgradeStarGift::ID;

void payments_upgradeStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1361648395);
  TlStoreBinary::store((var0 = flags_ | (keep_original_details_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_upgradeStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1361648395);
  TlStoreBinary::store((var0 = flags_ | (keep_original_details_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_upgradeStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.upgradeStarGift");
    s.store_field("flags", (var0 = flags_ | (keep_original_details_ << 0)));
    if (var0 & 1) { s.store_field("keep_original_details", true); }
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

payments_upgradeStarGift::ReturnType payments_upgradeStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_acceptCall::phone_acceptCall(object_ptr<inputPhoneCall> &&peer_, bytes &&g_b_, object_ptr<phoneCallProtocol> &&protocol_)
  : peer_(std::move(peer_))
  , g_b_(std::move(g_b_))
  , protocol_(std::move(protocol_))
{}

const std::int32_t phone_acceptCall::ID;

void phone_acceptCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1003664544);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(g_b_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_acceptCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1003664544);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(g_b_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_acceptCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.acceptCall");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_bytes_field("g_b", g_b_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

phone_acceptCall::ReturnType phone_acceptCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_phoneCall>, -326966976>::parse(p);
#undef FAIL
}

phone_checkGroupCall::phone_checkGroupCall(object_ptr<InputGroupCall> &&call_, array<int32> &&sources_)
  : call_(std::move(call_))
  , sources_(std::move(sources_))
{}

const std::int32_t phone_checkGroupCall::ID;

void phone_checkGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1248003721);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sources_, s);
}

void phone_checkGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1248003721);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sources_, s);
}

void phone_checkGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.checkGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("sources", sources_.size()); for (const auto &_value : sources_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

phone_checkGroupCall::ReturnType phone_checkGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
#undef FAIL
}

phone_confirmCall::phone_confirmCall(object_ptr<inputPhoneCall> &&peer_, bytes &&g_a_, int64 key_fingerprint_, object_ptr<phoneCallProtocol> &&protocol_)
  : peer_(std::move(peer_))
  , g_a_(std::move(g_a_))
  , key_fingerprint_(key_fingerprint_)
  , protocol_(std::move(protocol_))
{}

const std::int32_t phone_confirmCall::ID;

void phone_confirmCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(788404002);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(g_a_, s);
  TlStoreBinary::store(key_fingerprint_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_confirmCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(788404002);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(g_a_, s);
  TlStoreBinary::store(key_fingerprint_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_confirmCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.confirmCall");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_bytes_field("g_a", g_a_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

phone_confirmCall::ReturnType phone_confirmCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_phoneCall>, -326966976>::parse(p);
#undef FAIL
}

phone_deleteGroupCallParticipantMessages::phone_deleteGroupCallParticipantMessages(int32 flags_, bool report_spam_, object_ptr<InputGroupCall> &&call_, object_ptr<InputPeer> &&participant_)
  : flags_(flags_)
  , report_spam_(report_spam_)
  , call_(std::move(call_))
  , participant_(std::move(participant_))
{}

const std::int32_t phone_deleteGroupCallParticipantMessages::ID;

void phone_deleteGroupCallParticipantMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(499117216);
  TlStoreBinary::store((var0 = flags_ | (report_spam_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void phone_deleteGroupCallParticipantMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(499117216);
  TlStoreBinary::store((var0 = flags_ | (report_spam_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void phone_deleteGroupCallParticipantMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.deleteGroupCallParticipantMessages");
    s.store_field("flags", (var0 = flags_ | (report_spam_ << 0)));
    if (var0 & 1) { s.store_field("report_spam", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

phone_deleteGroupCallParticipantMessages::ReturnType phone_deleteGroupCallParticipantMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_getGroupCallStreamRtmpUrl::phone_getGroupCallStreamRtmpUrl(int32 flags_, bool live_story_, object_ptr<InputPeer> &&peer_, bool revoke_)
  : flags_(flags_)
  , live_story_(live_story_)
  , peer_(std::move(peer_))
  , revoke_(revoke_)
{}

const std::int32_t phone_getGroupCallStreamRtmpUrl::ID;

void phone_getGroupCallStreamRtmpUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1525991226);
  TlStoreBinary::store((var0 = flags_ | (live_story_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(revoke_, s);
}

void phone_getGroupCallStreamRtmpUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1525991226);
  TlStoreBinary::store((var0 = flags_ | (live_story_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(revoke_, s);
}

void phone_getGroupCallStreamRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCallStreamRtmpUrl");
    s.store_field("flags", (var0 = flags_ | (live_story_ << 0)));
    if (var0 & 1) { s.store_field("live_story", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

phone_getGroupCallStreamRtmpUrl::ReturnType phone_getGroupCallStreamRtmpUrl::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_groupCallStreamRtmpUrl>, 767505458>::parse(p);
#undef FAIL
}

phone_startScheduledGroupCall::phone_startScheduledGroupCall(object_ptr<InputGroupCall> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t phone_startScheduledGroupCall::ID;

void phone_startScheduledGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1451287362);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_startScheduledGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1451287362);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_startScheduledGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.startScheduledGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_startScheduledGroupCall::ReturnType phone_startScheduledGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_toggleGroupCallStartSubscription::phone_toggleGroupCallStartSubscription(object_ptr<InputGroupCall> &&call_, bool subscribed_)
  : call_(std::move(call_))
  , subscribed_(subscribed_)
{}

const std::int32_t phone_toggleGroupCallStartSubscription::ID;

void phone_toggleGroupCallStartSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(563885286);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBool::store(subscribed_, s);
}

void phone_toggleGroupCallStartSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(563885286);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBool::store(subscribed_, s);
}

void phone_toggleGroupCallStartSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.toggleGroupCallStartSubscription");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("subscribed", subscribed_);
    s.store_class_end();
  }
}

phone_toggleGroupCallStartSubscription::ReturnType phone_toggleGroupCallStartSubscription::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

photos_getUserPhotos::photos_getUserPhotos(object_ptr<InputUser> &&user_id_, int32 offset_, int64 max_id_, int32 limit_)
  : user_id_(std::move(user_id_))
  , offset_(offset_)
  , max_id_(max_id_)
  , limit_(limit_)
{}

const std::int32_t photos_getUserPhotos::ID;

void photos_getUserPhotos::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1848823128);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(limit_, s);
}

void photos_getUserPhotos::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1848823128);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(limit_, s);
}

void photos_getUserPhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.getUserPhotos");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("offset", offset_);
    s.store_field("max_id", max_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

photos_getUserPhotos::ReturnType photos_getUserPhotos::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<photos_Photos>::parse(p);
#undef FAIL
}

const std::int32_t smsjobs_isEligibleToJoin::ID;

void smsjobs_isEligibleToJoin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(249313744);
}

void smsjobs_isEligibleToJoin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(249313744);
}

void smsjobs_isEligibleToJoin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.isEligibleToJoin");
    s.store_class_end();
  }
}

smsjobs_isEligibleToJoin::ReturnType smsjobs_isEligibleToJoin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<smsjobs_eligibleToJoin>, -594852657>::parse(p);
#undef FAIL
}

smsjobs_updateSettings::smsjobs_updateSettings(int32 flags_, bool allow_international_)
  : flags_(flags_)
  , allow_international_(allow_international_)
{}

const std::int32_t smsjobs_updateSettings::ID;

void smsjobs_updateSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(155164863);
  TlStoreBinary::store((var0 = flags_ | (allow_international_ << 0)), s);
}

void smsjobs_updateSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(155164863);
  TlStoreBinary::store((var0 = flags_ | (allow_international_ << 0)), s);
}

void smsjobs_updateSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.updateSettings");
    s.store_field("flags", (var0 = flags_ | (allow_international_ << 0)));
    if (var0 & 1) { s.store_field("allow_international", true); }
    s.store_class_end();
  }
}

smsjobs_updateSettings::ReturnType smsjobs_updateSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stories_canSendStory::stories_canSendStory(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t stories_canSendStory::ID;

void stories_canSendStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(820732912);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void stories_canSendStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(820732912);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void stories_canSendStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.canSendStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

stories_canSendStory::ReturnType stories_canSendStory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_canSendStoryCount>, -1014513586>::parse(p);
#undef FAIL
}

stories_exportStoryLink::stories_exportStoryLink(object_ptr<InputPeer> &&peer_, int32 id_)
  : peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t stories_exportStoryLink::ID;

void stories_exportStoryLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2072899360);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void stories_exportStoryLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2072899360);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void stories_exportStoryLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.exportStoryLink");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

stories_exportStoryLink::ReturnType stories_exportStoryLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<exportedStoryLink>, 1070138683>::parse(p);
#undef FAIL
}

const std::int32_t stories_getChatsToSend::ID;

void stories_getChatsToSend::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1519744160);
}

void stories_getChatsToSend::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1519744160);
}

void stories_getChatsToSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getChatsToSend");
    s.store_class_end();
  }
}

stories_getChatsToSend::ReturnType stories_getChatsToSend::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

stories_togglePinned::stories_togglePinned(object_ptr<InputPeer> &&peer_, array<int32> &&id_, bool pinned_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
  , pinned_(pinned_)
{}

const std::int32_t stories_togglePinned::ID;

void stories_togglePinned::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1703566865);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBool::store(pinned_, s);
}

void stories_togglePinned::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1703566865);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBool::store(pinned_, s);
}

void stories_togglePinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.togglePinned");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pinned", pinned_);
    s.store_class_end();
  }
}

stories_togglePinned::ReturnType stories_togglePinned::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
#undef FAIL
}

stories_updateAlbum::stories_updateAlbum(int32 flags_, object_ptr<InputPeer> &&peer_, int32 album_id_, string const &title_, array<int32> &&delete_stories_, array<int32> &&add_stories_, array<int32> &&order_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , album_id_(album_id_)
  , title_(title_)
  , delete_stories_(std::move(delete_stories_))
  , add_stories_(std::move(add_stories_))
  , order_(std::move(order_))
{}

const std::int32_t stories_updateAlbum::ID;

void stories_updateAlbum::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1582455222);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 0) | ((!delete_stories_.empty()) << 1) | ((!add_stories_.empty()) << 2) | ((!order_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(delete_stories_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(add_stories_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s); }
}

void stories_updateAlbum::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1582455222);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 0) | ((!delete_stories_.empty()) << 1) | ((!add_stories_.empty()) << 2) | ((!order_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(delete_stories_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(add_stories_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s); }
}

void stories_updateAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.updateAlbum");
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 0) | ((!delete_stories_.empty()) << 1) | ((!add_stories_.empty()) << 2) | ((!order_.empty()) << 3)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("album_id", album_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { { s.store_vector_begin("delete_stories", delete_stories_.size()); for (const auto &_value : delete_stories_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("add_stories", add_stories_.size()); for (const auto &_value : add_stories_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 8) { { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

stories_updateAlbum::ReturnType stories_updateAlbum::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<storyAlbum>, -1826262950>::parse(p);
#undef FAIL
}

const std::int32_t test_parseInputAppEvent::ID;

void test_parseInputAppEvent::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1156741135);
}

void test_parseInputAppEvent::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1156741135);
}

void test_parseInputAppEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "test.parseInputAppEvent");
    s.store_class_end();
  }
}

test_parseInputAppEvent::ReturnType test_parseInputAppEvent::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<inputAppEvent>, 488313413>::parse(p);
#undef FAIL
}

updates_getChannelDifference::updates_getChannelDifference(int32 flags_, bool force_, object_ptr<InputChannel> &&channel_, object_ptr<ChannelMessagesFilter> &&filter_, int32 pts_, int32 limit_)
  : flags_(flags_)
  , force_(force_)
  , channel_(std::move(channel_))
  , filter_(std::move(filter_))
  , pts_(pts_)
  , limit_(limit_)
{}

const std::int32_t updates_getChannelDifference::ID;

void updates_getChannelDifference::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(51854712);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(pts_, s);
  TlStoreBinary::store(limit_, s);
}

void updates_getChannelDifference::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(51854712);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(pts_, s);
  TlStoreBinary::store(limit_, s);
}

void updates_getChannelDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.getChannelDifference");
    s.store_field("flags", (var0 = flags_ | (force_ << 0)));
    if (var0 & 1) { s.store_field("force", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("pts", pts_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

updates_getChannelDifference::ReturnType updates_getChannelDifference::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<updates_ChannelDifference>::parse(p);
#undef FAIL
}

upload_getCdnFileHashes::upload_getCdnFileHashes(bytes &&file_token_, int64 offset_)
  : file_token_(std::move(file_token_))
  , offset_(offset_)
{}

const std::int32_t upload_getCdnFileHashes::ID;

void upload_getCdnFileHashes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1847836879);
  TlStoreString::store(file_token_, s);
  TlStoreBinary::store(offset_, s);
}

void upload_getCdnFileHashes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1847836879);
  TlStoreString::store(file_token_, s);
  TlStoreBinary::store(offset_, s);
}

void upload_getCdnFileHashes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.getCdnFileHashes");
    s.store_field("file_token", "[REDACTED]");
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

upload_getCdnFileHashes::ReturnType upload_getCdnFileHashes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<fileHash>, -207944868>>, 481674261>::parse(p);
#undef FAIL
}

upload_getFile::upload_getFile(int32 flags_, bool precise_, bool cdn_supported_, object_ptr<InputFileLocation> &&location_, int64 offset_, int32 limit_)
  : flags_(flags_)
  , precise_(precise_)
  , cdn_supported_(cdn_supported_)
  , location_(std::move(location_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t upload_getFile::ID;

void upload_getFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1101843010);
  TlStoreBinary::store((var0 = flags_ | (precise_ << 0) | (cdn_supported_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1101843010);
  TlStoreBinary::store((var0 = flags_ | (precise_ << 0) | (cdn_supported_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.getFile");
    s.store_field("flags", (var0 = flags_ | (precise_ << 0) | (cdn_supported_ << 1)));
    if (var0 & 1) { s.store_field("precise", true); }
    if (var0 & 2) { s.store_field("cdn_supported", true); }
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

upload_getFile::ReturnType upload_getFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<upload_File>::parse(p);
#undef FAIL
}

upload_getWebFile::upload_getWebFile(object_ptr<InputWebFileLocation> &&location_, int32 offset_, int32 limit_)
  : location_(std::move(location_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t upload_getWebFile::ID;

void upload_getWebFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(619086221);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getWebFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(619086221);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getWebFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.getWebFile");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

upload_getWebFile::ReturnType upload_getWebFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<upload_webFile>, 568808380>::parse(p);
#undef FAIL
}

users_getSavedMusicByID::users_getSavedMusicByID(object_ptr<InputUser> &&id_, array<object_ptr<InputDocument>> &&documents_)
  : id_(std::move(id_))
  , documents_(std::move(documents_))
{}

const std::int32_t users_getSavedMusicByID::ID;

void users_getSavedMusicByID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1970513129);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s);
}

void users_getSavedMusicByID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1970513129);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s);
}

void users_getSavedMusicByID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.getSavedMusicByID");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

users_getSavedMusicByID::ReturnType users_getSavedMusicByID::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<users_SavedMusic>::parse(p);
#undef FAIL
}

users_getUsers::users_getUsers(array<object_ptr<InputUser>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t users_getUsers::ID;

void users_getUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(227648840);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void users_getUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(227648840);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void users_getUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.getUsers");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

users_getUsers::ReturnType users_getUsers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
#undef FAIL
}

wallet_tonConnectClaimRequest::wallet_tonConnectClaimRequest(int32 flags_, bool declined_, int64 session_id_, int32 msg_id_, string const &app_request_id_, bytes &&challenge_answer_)
  : flags_(flags_)
  , declined_(declined_)
  , session_id_(session_id_)
  , msg_id_(msg_id_)
  , app_request_id_(app_request_id_)
  , challenge_answer_(std::move(challenge_answer_))
{}

const std::int32_t wallet_tonConnectClaimRequest::ID;

void wallet_tonConnectClaimRequest::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1723169601);
  TlStoreBinary::store((var0 = flags_ | (declined_ << 1) | ((!challenge_answer_.empty()) << 0)), s);
  TlStoreBinary::store(session_id_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(app_request_id_, s);
  if (var0 & 1) { TlStoreString::store(challenge_answer_, s); }
}

void wallet_tonConnectClaimRequest::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1723169601);
  TlStoreBinary::store((var0 = flags_ | (declined_ << 1) | ((!challenge_answer_.empty()) << 0)), s);
  TlStoreBinary::store(session_id_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(app_request_id_, s);
  if (var0 & 1) { TlStoreString::store(challenge_answer_, s); }
}

void wallet_tonConnectClaimRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectClaimRequest");
    s.store_field("flags", (var0 = flags_ | (declined_ << 1) | ((!challenge_answer_.empty()) << 0)));
    if (var0 & 2) { s.store_field("declined", true); }
    s.store_field("session_id", session_id_);
    s.store_field("msg_id", msg_id_);
    s.store_field("app_request_id", app_request_id_);
    if (var0 & 1) { s.store_bytes_field("challenge_answer", challenge_answer_); }
    s.store_class_end();
  }
}

wallet_tonConnectClaimRequest::ReturnType wallet_tonConnectClaimRequest::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
