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


availableEffect::availableEffect()
  : flags_()
  , premium_required_()
  , id_()
  , emoticon_()
  , static_icon_id_()
  , effect_sticker_id_()
  , effect_animation_id_()
{}

const std::int32_t availableEffect::ID;

object_ptr<availableEffect> availableEffect::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<availableEffect> res = make_tl_object<availableEffect>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->premium_required_ = (var0 & 4) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->emoticon_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->static_icon_id_ = TlFetchLong::parse(p); }
  res->effect_sticker_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->effect_animation_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void availableEffect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableEffect");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (premium_required_ << 2)));
    if (var0 & 4) { s.store_field("premium_required", true); }
    s.store_field("id", id_);
    s.store_field("emoticon", emoticon_);
    if (var0 & 1) { s.store_field("static_icon_id", static_icon_id_); }
    s.store_field("effect_sticker_id", effect_sticker_id_);
    if (var0 & 2) { s.store_field("effect_animation_id", effect_animation_id_); }
    s.store_class_end();
  }
}

botAppSettings::botAppSettings()
  : flags_()
  , placeholder_path_()
  , background_color_()
  , background_dark_color_()
  , header_color_()
  , header_dark_color_()
{}

const std::int32_t botAppSettings::ID;

object_ptr<botAppSettings> botAppSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botAppSettings> res = make_tl_object<botAppSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->placeholder_path_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 2) { res->background_color_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->background_dark_color_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->header_color_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->header_dark_color_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void botAppSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botAppSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!placeholder_path_.empty()) << 0)));
    if (var0 & 1) { s.store_bytes_field("placeholder_path", placeholder_path_); }
    if (var0 & 2) { s.store_field("background_color", background_color_); }
    if (var0 & 4) { s.store_field("background_dark_color", background_dark_color_); }
    if (var0 & 8) { s.store_field("header_color", header_color_); }
    if (var0 & 16) { s.store_field("header_dark_color", header_dark_color_); }
    s.store_class_end();
  }
}

botCommand::botCommand()
  : flags_()
  , ephemeral_()
  , command_()
  , description_()
{}

botCommand::botCommand(int32 flags_, bool ephemeral_, string const &command_, string const &description_)
  : flags_(flags_)
  , ephemeral_(ephemeral_)
  , command_(command_)
  , description_(description_)
{}

const std::int32_t botCommand::ID;

object_ptr<botCommand> botCommand::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botCommand> res = make_tl_object<botCommand>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->ephemeral_ = (var0 & 1) != 0;
  res->command_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void botCommand::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (ephemeral_ << 0)), s);
  TlStoreString::store(command_, s);
  TlStoreString::store(description_, s);
}

void botCommand::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (ephemeral_ << 0)), s);
  TlStoreString::store(command_, s);
  TlStoreString::store(description_, s);
}

void botCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommand");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (ephemeral_ << 0)));
    if (var0 & 1) { s.store_field("ephemeral", true); }
    s.store_field("command", command_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

businessRecipients::businessRecipients()
  : flags_()
  , existing_chats_()
  , new_chats_()
  , contacts_()
  , non_contacts_()
  , exclude_selected_()
  , users_()
{}

const std::int32_t businessRecipients::ID;

object_ptr<businessRecipients> businessRecipients::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessRecipients> res = make_tl_object<businessRecipients>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->existing_chats_ = (var0 & 1) != 0;
  res->new_chats_ = (var0 & 2) != 0;
  res->contacts_ = (var0 & 4) != 0;
  res->non_contacts_ = (var0 & 8) != 0;
  res->exclude_selected_ = (var0 & 32) != 0;
  if (var0 & 16) { res->users_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessRecipients::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessRecipients");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5) | ((!users_.empty()) << 4)));
    if (var0 & 1) { s.store_field("existing_chats", true); }
    if (var0 & 2) { s.store_field("new_chats", true); }
    if (var0 & 4) { s.store_field("contacts", true); }
    if (var0 & 8) { s.store_field("non_contacts", true); }
    if (var0 & 32) { s.store_field("exclude_selected", true); }
    if (var0 & 16) { { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

chatAdminRights::chatAdminRights()
  : flags_()
  , change_info_()
  , post_messages_()
  , edit_messages_()
  , delete_messages_()
  , ban_users_()
  , invite_users_()
  , pin_messages_()
  , add_admins_()
  , anonymous_()
  , manage_call_()
  , other_()
  , manage_topics_()
  , post_stories_()
  , edit_stories_()
  , delete_stories_()
  , manage_direct_messages_()
  , manage_ranks_()
  , manage_linked_peers_()
  , manage_welcome_messages_()
{}

chatAdminRights::chatAdminRights(int32 flags_, bool change_info_, bool post_messages_, bool edit_messages_, bool delete_messages_, bool ban_users_, bool invite_users_, bool pin_messages_, bool add_admins_, bool anonymous_, bool manage_call_, bool other_, bool manage_topics_, bool post_stories_, bool edit_stories_, bool delete_stories_, bool manage_direct_messages_, bool manage_ranks_, bool manage_linked_peers_, bool manage_welcome_messages_)
  : flags_(flags_)
  , change_info_(change_info_)
  , post_messages_(post_messages_)
  , edit_messages_(edit_messages_)
  , delete_messages_(delete_messages_)
  , ban_users_(ban_users_)
  , invite_users_(invite_users_)
  , pin_messages_(pin_messages_)
  , add_admins_(add_admins_)
  , anonymous_(anonymous_)
  , manage_call_(manage_call_)
  , other_(other_)
  , manage_topics_(manage_topics_)
  , post_stories_(post_stories_)
  , edit_stories_(edit_stories_)
  , delete_stories_(delete_stories_)
  , manage_direct_messages_(manage_direct_messages_)
  , manage_ranks_(manage_ranks_)
  , manage_linked_peers_(manage_linked_peers_)
  , manage_welcome_messages_(manage_welcome_messages_)
{}

const std::int32_t chatAdminRights::ID;

object_ptr<chatAdminRights> chatAdminRights::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatAdminRights> res = make_tl_object<chatAdminRights>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->change_info_ = (var0 & 1) != 0;
  res->post_messages_ = (var0 & 2) != 0;
  res->edit_messages_ = (var0 & 4) != 0;
  res->delete_messages_ = (var0 & 8) != 0;
  res->ban_users_ = (var0 & 16) != 0;
  res->invite_users_ = (var0 & 32) != 0;
  res->pin_messages_ = (var0 & 128) != 0;
  res->add_admins_ = (var0 & 512) != 0;
  res->anonymous_ = (var0 & 1024) != 0;
  res->manage_call_ = (var0 & 2048) != 0;
  res->other_ = (var0 & 4096) != 0;
  res->manage_topics_ = (var0 & 8192) != 0;
  res->post_stories_ = (var0 & 16384) != 0;
  res->edit_stories_ = (var0 & 32768) != 0;
  res->delete_stories_ = (var0 & 65536) != 0;
  res->manage_direct_messages_ = (var0 & 131072) != 0;
  res->manage_ranks_ = (var0 & 262144) != 0;
  res->manage_linked_peers_ = (var0 & 524288) != 0;
  res->manage_welcome_messages_ = (var0 & 1048576) != 0;
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void chatAdminRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (change_info_ << 0) | (post_messages_ << 1) | (edit_messages_ << 2) | (delete_messages_ << 3) | (ban_users_ << 4) | (invite_users_ << 5) | (pin_messages_ << 7) | (add_admins_ << 9) | (anonymous_ << 10) | (manage_call_ << 11) | (other_ << 12) | (manage_topics_ << 13) | (post_stories_ << 14) | (edit_stories_ << 15) | (delete_stories_ << 16) | (manage_direct_messages_ << 17) | (manage_ranks_ << 18) | (manage_linked_peers_ << 19) | (manage_welcome_messages_ << 20)), s);
}

void chatAdminRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (change_info_ << 0) | (post_messages_ << 1) | (edit_messages_ << 2) | (delete_messages_ << 3) | (ban_users_ << 4) | (invite_users_ << 5) | (pin_messages_ << 7) | (add_admins_ << 9) | (anonymous_ << 10) | (manage_call_ << 11) | (other_ << 12) | (manage_topics_ << 13) | (post_stories_ << 14) | (edit_stories_ << 15) | (delete_stories_ << 16) | (manage_direct_messages_ << 17) | (manage_ranks_ << 18) | (manage_linked_peers_ << 19) | (manage_welcome_messages_ << 20)), s);
}

void chatAdminRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdminRights");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (change_info_ << 0) | (post_messages_ << 1) | (edit_messages_ << 2) | (delete_messages_ << 3) | (ban_users_ << 4) | (invite_users_ << 5) | (pin_messages_ << 7) | (add_admins_ << 9) | (anonymous_ << 10) | (manage_call_ << 11) | (other_ << 12) | (manage_topics_ << 13) | (post_stories_ << 14) | (edit_stories_ << 15) | (delete_stories_ << 16) | (manage_direct_messages_ << 17) | (manage_ranks_ << 18) | (manage_linked_peers_ << 19) | (manage_welcome_messages_ << 20)));
    if (var0 & 1) { s.store_field("change_info", true); }
    if (var0 & 2) { s.store_field("post_messages", true); }
    if (var0 & 4) { s.store_field("edit_messages", true); }
    if (var0 & 8) { s.store_field("delete_messages", true); }
    if (var0 & 16) { s.store_field("ban_users", true); }
    if (var0 & 32) { s.store_field("invite_users", true); }
    if (var0 & 128) { s.store_field("pin_messages", true); }
    if (var0 & 512) { s.store_field("add_admins", true); }
    if (var0 & 1024) { s.store_field("anonymous", true); }
    if (var0 & 2048) { s.store_field("manage_call", true); }
    if (var0 & 4096) { s.store_field("other", true); }
    if (var0 & 8192) { s.store_field("manage_topics", true); }
    if (var0 & 16384) { s.store_field("post_stories", true); }
    if (var0 & 32768) { s.store_field("edit_stories", true); }
    if (var0 & 65536) { s.store_field("delete_stories", true); }
    if (var0 & 131072) { s.store_field("manage_direct_messages", true); }
    if (var0 & 262144) { s.store_field("manage_ranks", true); }
    if (var0 & 524288) { s.store_field("manage_linked_peers", true); }
    if (var0 & 1048576) { s.store_field("manage_welcome_messages", true); }
    s.store_class_end();
  }
}

const std::int32_t chatOnlines::ID;

object_ptr<chatOnlines> chatOnlines::fetch(TlBufferParser &p) {
  return make_tl_object<chatOnlines>(p);
}

chatOnlines::chatOnlines(TlBufferParser &p)
  : onlines_(TlFetchInt::parse(p))
{}

void chatOnlines::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatOnlines");
    s.store_field("onlines", onlines_);
    s.store_class_end();
  }
}

object_ptr<ChatParticipants> ChatParticipants::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatParticipantsForbidden::ID:
      return chatParticipantsForbidden::fetch(p);
    case chatParticipants::ID:
      return chatParticipants::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

chatParticipantsForbidden::chatParticipantsForbidden()
  : flags_()
  , chat_id_()
  , self_participant_()
{}

const std::int32_t chatParticipantsForbidden::ID;

object_ptr<ChatParticipants> chatParticipantsForbidden::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatParticipantsForbidden> res = make_tl_object<chatParticipantsForbidden>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->chat_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->self_participant_ = TlFetchObject<ChatParticipant>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatParticipantsForbidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatParticipantsForbidden");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((self_participant_ != nullptr) << 0)));
    s.store_field("chat_id", chat_id_);
    if (var0 & 1) { s.store_object_field("self_participant", static_cast<const BaseObject *>(self_participant_.get())); }
    s.store_class_end();
  }
}

const std::int32_t chatParticipants::ID;

object_ptr<ChatParticipants> chatParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<chatParticipants>(p);
}

chatParticipants::chatParticipants(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , participants_(TlFetchBoxed<TlFetchVector<TlFetchObject<ChatParticipant>>, 481674261>::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void chatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatParticipants");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("version", version_);
    s.store_class_end();
  }
}

communityPeerRequest::communityPeerRequest()
  : flags_()
  , visible_()
  , peer_()
  , requested_by_()
  , date_()
{}

const std::int32_t communityPeerRequest::ID;

object_ptr<communityPeerRequest> communityPeerRequest::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<communityPeerRequest> res = make_tl_object<communityPeerRequest>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->visible_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->requested_by_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void communityPeerRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityPeerRequest");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (visible_ << 0)));
    if (var0 & 1) { s.store_field("visible", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("requested_by", requested_by_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<DialogPeer> DialogPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case dialogPeer::ID:
      return dialogPeer::fetch(p);
    case dialogPeerFolder::ID:
      return dialogPeerFolder::fetch(p);
    case dialogPeerCommunity::ID:
      return dialogPeerCommunity::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t dialogPeer::ID;

object_ptr<DialogPeer> dialogPeer::fetch(TlBufferParser &p) {
  return make_tl_object<dialogPeer>(p);
}

dialogPeer::dialogPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
{}

void dialogPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

const std::int32_t dialogPeerFolder::ID;

object_ptr<DialogPeer> dialogPeerFolder::fetch(TlBufferParser &p) {
  return make_tl_object<dialogPeerFolder>(p);
}

dialogPeerFolder::dialogPeerFolder(TlBufferParser &p)
  : folder_id_(TlFetchInt::parse(p))
{}

void dialogPeerFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogPeerFolder");
    s.store_field("folder_id", folder_id_);
    s.store_class_end();
  }
}

const std::int32_t dialogPeerCommunity::ID;

object_ptr<DialogPeer> dialogPeerCommunity::fetch(TlBufferParser &p) {
  return make_tl_object<dialogPeerCommunity>(p);
}

dialogPeerCommunity::dialogPeerCommunity(TlBufferParser &p)
  : community_id_(TlFetchLong::parse(p))
{}

void dialogPeerCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogPeerCommunity");
    s.store_field("community_id", community_id_);
    s.store_class_end();
  }
}

disallowedGiftsSettings::disallowedGiftsSettings()
  : flags_()
  , disallow_unlimited_stargifts_()
  , disallow_limited_stargifts_()
  , disallow_unique_stargifts_()
  , disallow_premium_gifts_()
  , disallow_stargifts_from_channels_()
{}

disallowedGiftsSettings::disallowedGiftsSettings(int32 flags_, bool disallow_unlimited_stargifts_, bool disallow_limited_stargifts_, bool disallow_unique_stargifts_, bool disallow_premium_gifts_, bool disallow_stargifts_from_channels_)
  : flags_(flags_)
  , disallow_unlimited_stargifts_(disallow_unlimited_stargifts_)
  , disallow_limited_stargifts_(disallow_limited_stargifts_)
  , disallow_unique_stargifts_(disallow_unique_stargifts_)
  , disallow_premium_gifts_(disallow_premium_gifts_)
  , disallow_stargifts_from_channels_(disallow_stargifts_from_channels_)
{}

const std::int32_t disallowedGiftsSettings::ID;

object_ptr<disallowedGiftsSettings> disallowedGiftsSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<disallowedGiftsSettings> res = make_tl_object<disallowedGiftsSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->disallow_unlimited_stargifts_ = (var0 & 1) != 0;
  res->disallow_limited_stargifts_ = (var0 & 2) != 0;
  res->disallow_unique_stargifts_ = (var0 & 4) != 0;
  res->disallow_premium_gifts_ = (var0 & 8) != 0;
  res->disallow_stargifts_from_channels_ = (var0 & 16) != 0;
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void disallowedGiftsSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (disallow_unlimited_stargifts_ << 0) | (disallow_limited_stargifts_ << 1) | (disallow_unique_stargifts_ << 2) | (disallow_premium_gifts_ << 3) | (disallow_stargifts_from_channels_ << 4)), s);
}

void disallowedGiftsSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (disallow_unlimited_stargifts_ << 0) | (disallow_limited_stargifts_ << 1) | (disallow_unique_stargifts_ << 2) | (disallow_premium_gifts_ << 3) | (disallow_stargifts_from_channels_ << 4)), s);
}

void disallowedGiftsSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disallowedGiftsSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (disallow_unlimited_stargifts_ << 0) | (disallow_limited_stargifts_ << 1) | (disallow_unique_stargifts_ << 2) | (disallow_premium_gifts_ << 3) | (disallow_stargifts_from_channels_ << 4)));
    if (var0 & 1) { s.store_field("disallow_unlimited_stargifts", true); }
    if (var0 & 2) { s.store_field("disallow_limited_stargifts", true); }
    if (var0 & 4) { s.store_field("disallow_unique_stargifts", true); }
    if (var0 & 8) { s.store_field("disallow_premium_gifts", true); }
    if (var0 & 16) { s.store_field("disallow_stargifts_from_channels", true); }
    s.store_class_end();
  }
}

emailVerifyPurposeLoginSetup::emailVerifyPurposeLoginSetup(string const &phone_number_, string const &phone_code_hash_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
{}

const std::int32_t emailVerifyPurposeLoginSetup::ID;

void emailVerifyPurposeLoginSetup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void emailVerifyPurposeLoginSetup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void emailVerifyPurposeLoginSetup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerifyPurposeLoginSetup");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_class_end();
  }
}

const std::int32_t emailVerifyPurposeLoginChange::ID;

void emailVerifyPurposeLoginChange::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void emailVerifyPurposeLoginChange::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void emailVerifyPurposeLoginChange::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerifyPurposeLoginChange");
    s.store_class_end();
  }
}

const std::int32_t emailVerifyPurposePassport::ID;

void emailVerifyPurposePassport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void emailVerifyPurposePassport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void emailVerifyPurposePassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerifyPurposePassport");
    s.store_class_end();
  }
}

object_ptr<EmojiStatus> EmojiStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case emojiStatusEmpty::ID:
      return emojiStatusEmpty::fetch(p);
    case emojiStatus::ID:
      return emojiStatus::fetch(p);
    case emojiStatusCollectible::ID:
      return emojiStatusCollectible::fetch(p);
    case inputEmojiStatusCollectible::ID:
      return inputEmojiStatusCollectible::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t emojiStatusEmpty::ID;

object_ptr<EmojiStatus> emojiStatusEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<emojiStatusEmpty>();
}

void emojiStatusEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void emojiStatusEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void emojiStatusEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatusEmpty");
    s.store_class_end();
  }
}

emojiStatus::emojiStatus()
  : flags_()
  , document_id_()
  , until_()
{}

emojiStatus::emojiStatus(int32 flags_, int64 document_id_, int32 until_)
  : flags_(flags_)
  , document_id_(document_id_)
  , until_(until_)
{}

const std::int32_t emojiStatus::ID;

object_ptr<EmojiStatus> emojiStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<emojiStatus> res = make_tl_object<emojiStatus>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->document_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->until_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void emojiStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(document_id_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void emojiStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(document_id_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void emojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatus");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("document_id", document_id_);
    if (var0 & 1) { s.store_field("until", until_); }
    s.store_class_end();
  }
}

emojiStatusCollectible::emojiStatusCollectible()
  : flags_()
  , collectible_id_()
  , document_id_()
  , title_()
  , slug_()
  , pattern_document_id_()
  , center_color_()
  , edge_color_()
  , pattern_color_()
  , text_color_()
  , until_()
{}

emojiStatusCollectible::emojiStatusCollectible(int32 flags_, int64 collectible_id_, int64 document_id_, string const &title_, string const &slug_, int64 pattern_document_id_, int32 center_color_, int32 edge_color_, int32 pattern_color_, int32 text_color_, int32 until_)
  : flags_(flags_)
  , collectible_id_(collectible_id_)
  , document_id_(document_id_)
  , title_(title_)
  , slug_(slug_)
  , pattern_document_id_(pattern_document_id_)
  , center_color_(center_color_)
  , edge_color_(edge_color_)
  , pattern_color_(pattern_color_)
  , text_color_(text_color_)
  , until_(until_)
{}

const std::int32_t emojiStatusCollectible::ID;

object_ptr<EmojiStatus> emojiStatusCollectible::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<emojiStatusCollectible> res = make_tl_object<emojiStatusCollectible>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collectible_id_ = TlFetchLong::parse(p);
  res->document_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->slug_ = TlFetchString<string>::parse(p);
  res->pattern_document_id_ = TlFetchLong::parse(p);
  res->center_color_ = TlFetchInt::parse(p);
  res->edge_color_ = TlFetchInt::parse(p);
  res->pattern_color_ = TlFetchInt::parse(p);
  res->text_color_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->until_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void emojiStatusCollectible::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(collectible_id_, s);
  TlStoreBinary::store(document_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(pattern_document_id_, s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(pattern_color_, s);
  TlStoreBinary::store(text_color_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void emojiStatusCollectible::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(collectible_id_, s);
  TlStoreBinary::store(document_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(pattern_document_id_, s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(pattern_color_, s);
  TlStoreBinary::store(text_color_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void emojiStatusCollectible::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatusCollectible");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("collectible_id", collectible_id_);
    s.store_field("document_id", document_id_);
    s.store_field("title", title_);
    s.store_field("slug", slug_);
    s.store_field("pattern_document_id", pattern_document_id_);
    s.store_field("center_color", center_color_);
    s.store_field("edge_color", edge_color_);
    s.store_field("pattern_color", pattern_color_);
    s.store_field("text_color", text_color_);
    if (var0 & 1) { s.store_field("until", until_); }
    s.store_class_end();
  }
}

inputEmojiStatusCollectible::inputEmojiStatusCollectible()
  : flags_()
  , collectible_id_()
  , until_()
{}

inputEmojiStatusCollectible::inputEmojiStatusCollectible(int32 flags_, int64 collectible_id_, int32 until_)
  : flags_(flags_)
  , collectible_id_(collectible_id_)
  , until_(until_)
{}

const std::int32_t inputEmojiStatusCollectible::ID;

object_ptr<EmojiStatus> inputEmojiStatusCollectible::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputEmojiStatusCollectible> res = make_tl_object<inputEmojiStatusCollectible>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collectible_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->until_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputEmojiStatusCollectible::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(collectible_id_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void inputEmojiStatusCollectible::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(collectible_id_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void inputEmojiStatusCollectible::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEmojiStatusCollectible");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("collectible_id", collectible_id_);
    if (var0 & 1) { s.store_field("until", until_); }
    s.store_class_end();
  }
}

const std::int32_t folderPeer::ID;

object_ptr<folderPeer> folderPeer::fetch(TlBufferParser &p) {
  return make_tl_object<folderPeer>(p);
}

folderPeer::folderPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , folder_id_(TlFetchInt::parse(p))
{}

void folderPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "folderPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("folder_id", folder_id_);
    s.store_class_end();
  }
}

geoPointAddress::geoPointAddress()
  : flags_()
  , country_iso2_()
  , state_()
  , city_()
  , street_()
{}

geoPointAddress::geoPointAddress(int32 flags_, string const &country_iso2_, string const &state_, string const &city_, string const &street_)
  : flags_(flags_)
  , country_iso2_(country_iso2_)
  , state_(state_)
  , city_(city_)
  , street_(street_)
{}

const std::int32_t geoPointAddress::ID;

object_ptr<geoPointAddress> geoPointAddress::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<geoPointAddress> res = make_tl_object<geoPointAddress>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->country_iso2_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->state_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->city_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->street_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void geoPointAddress::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!state_.empty()) << 0) | ((!city_.empty()) << 1) | ((!street_.empty()) << 2)), s);
  TlStoreString::store(country_iso2_, s);
  if (var0 & 1) { TlStoreString::store(state_, s); }
  if (var0 & 2) { TlStoreString::store(city_, s); }
  if (var0 & 4) { TlStoreString::store(street_, s); }
}

void geoPointAddress::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!state_.empty()) << 0) | ((!city_.empty()) << 1) | ((!street_.empty()) << 2)), s);
  TlStoreString::store(country_iso2_, s);
  if (var0 & 1) { TlStoreString::store(state_, s); }
  if (var0 & 2) { TlStoreString::store(city_, s); }
  if (var0 & 4) { TlStoreString::store(street_, s); }
}

void geoPointAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "geoPointAddress");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!state_.empty()) << 0) | ((!city_.empty()) << 1) | ((!street_.empty()) << 2)));
    s.store_field("country_iso2", country_iso2_);
    if (var0 & 1) { s.store_field("state", state_); }
    if (var0 & 2) { s.store_field("city", city_); }
    if (var0 & 4) { s.store_field("street", street_); }
    s.store_class_end();
  }
}

const std::int32_t importedContact::ID;

object_ptr<importedContact> importedContact::fetch(TlBufferParser &p) {
  return make_tl_object<importedContact>(p);
}

importedContact::importedContact(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , client_id_(TlFetchLong::parse(p))
{}

void importedContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importedContact");
    s.store_field("user_id", user_id_);
    s.store_field("client_id", client_id_);
    s.store_class_end();
  }
}

inputStarGiftAuction::inputStarGiftAuction(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t inputStarGiftAuction::ID;

void inputStarGiftAuction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(gift_id_, s);
}

void inputStarGiftAuction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(gift_id_, s);
}

void inputStarGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStarGiftAuction");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

inputStarGiftAuctionSlug::inputStarGiftAuctionSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputStarGiftAuctionSlug::ID;

void inputStarGiftAuctionSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputStarGiftAuctionSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputStarGiftAuctionSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStarGiftAuctionSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

inputStarsTransaction::inputStarsTransaction(int32 flags_, bool refund_, string const &id_)
  : flags_(flags_)
  , refund_(refund_)
  , id_(id_)
{}

const std::int32_t inputStarsTransaction::ID;

void inputStarsTransaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (refund_ << 0)), s);
  TlStoreString::store(id_, s);
}

void inputStarsTransaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (refund_ << 0)), s);
  TlStoreString::store(id_, s);
}

void inputStarsTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStarsTransaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (refund_ << 0)));
    if (var0 & 1) { s.store_field("refund", true); }
    s.store_field("id", id_);
    s.store_class_end();
  }
}

messageReactor::messageReactor()
  : flags_()
  , top_()
  , my_()
  , anonymous_()
  , peer_id_()
  , count_()
{}

const std::int32_t messageReactor::ID;

object_ptr<messageReactor> messageReactor::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageReactor> res = make_tl_object<messageReactor>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->top_ = (var0 & 1) != 0;
  res->my_ = (var0 & 2) != 0;
  res->anonymous_ = (var0 & 4) != 0;
  if (var0 & 8) { res->peer_id_ = TlFetchObject<Peer>::parse(p); }
  res->count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messageReactor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReactor");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (top_ << 0) | (my_ << 1) | (anonymous_ << 2) | ((peer_id_ != nullptr) << 3)));
    if (var0 & 1) { s.store_field("top", true); }
    if (var0 & 2) { s.store_field("my", true); }
    if (var0 & 4) { s.store_field("anonymous", true); }
    if (var0 & 8) { s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get())); }
    s.store_field("count", count_);
    s.store_class_end();
  }
}

object_ptr<NotificationSound> NotificationSound::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case notificationSoundDefault::ID:
      return notificationSoundDefault::fetch(p);
    case notificationSoundNone::ID:
      return notificationSoundNone::fetch(p);
    case notificationSoundLocal::ID:
      return notificationSoundLocal::fetch(p);
    case notificationSoundRingtone::ID:
      return notificationSoundRingtone::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t notificationSoundDefault::ID;

object_ptr<NotificationSound> notificationSoundDefault::fetch(TlBufferParser &p) {
  return make_tl_object<notificationSoundDefault>();
}

void notificationSoundDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void notificationSoundDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void notificationSoundDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSoundDefault");
    s.store_class_end();
  }
}

const std::int32_t notificationSoundNone::ID;

object_ptr<NotificationSound> notificationSoundNone::fetch(TlBufferParser &p) {
  return make_tl_object<notificationSoundNone>();
}

void notificationSoundNone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void notificationSoundNone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void notificationSoundNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSoundNone");
    s.store_class_end();
  }
}

notificationSoundLocal::notificationSoundLocal(string const &title_, string const &data_)
  : title_(title_)
  , data_(data_)
{}

const std::int32_t notificationSoundLocal::ID;

object_ptr<NotificationSound> notificationSoundLocal::fetch(TlBufferParser &p) {
  return make_tl_object<notificationSoundLocal>(p);
}

notificationSoundLocal::notificationSoundLocal(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , data_(TlFetchString<string>::parse(p))
{}

void notificationSoundLocal::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(title_, s);
  TlStoreString::store(data_, s);
}

void notificationSoundLocal::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(title_, s);
  TlStoreString::store(data_, s);
}

void notificationSoundLocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSoundLocal");
    s.store_field("title", title_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

notificationSoundRingtone::notificationSoundRingtone(int64 id_)
  : id_(id_)
{}

const std::int32_t notificationSoundRingtone::ID;

object_ptr<NotificationSound> notificationSoundRingtone::fetch(TlBufferParser &p) {
  return make_tl_object<notificationSoundRingtone>(p);
}

notificationSoundRingtone::notificationSoundRingtone(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void notificationSoundRingtone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void notificationSoundRingtone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void notificationSoundRingtone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSoundRingtone");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

pageButton::pageButton()
  : flags_()
  , text_()
  , type_()
  , style_()
{}

pageButton::pageButton(int32 flags_, object_ptr<RichText> &&text_, object_ptr<InlineButtonType> &&type_, object_ptr<richButtonStyle> &&style_)
  : flags_(flags_)
  , text_(std::move(text_))
  , type_(std::move(type_))
  , style_(std::move(style_))
{}

const std::int32_t pageButton::ID;

object_ptr<pageButton> pageButton::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageButton> res = make_tl_object<pageButton>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->text_ = TlFetchObject<RichText>::parse(p);
  res->type_ = TlFetchObject<InlineButtonType>::parse(p);
  if (var0 & 1) { res->style_ = TlFetchBoxed<TlFetchObject<richButtonStyle>, 63312061>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void pageButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((style_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 63312061>::store(style_, s); }
}

void pageButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((style_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 63312061>::store(style_, s); }
}

void pageButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageButton");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((style_ != nullptr) << 0)));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    if (var0 & 1) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_class_end();
  }
}

pageTableRow::pageTableRow(array<object_ptr<pageTableCell>> &&cells_)
  : cells_(std::move(cells_))
{}

const std::int32_t pageTableRow::ID;

object_ptr<pageTableRow> pageTableRow::fetch(TlBufferParser &p) {
  return make_tl_object<pageTableRow>(p);
}

pageTableRow::pageTableRow(TlBufferParser &p)
  : cells_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<pageTableCell>, 878078826>>, 481674261>::parse(p))
{}

void pageTableRow::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 878078826>>, 481674261>::store(cells_, s);
}

void pageTableRow::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 878078826>>, 481674261>::store(cells_, s);
}

void pageTableRow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageTableRow");
    { s.store_vector_begin("cells", cells_.size()); for (const auto &_value : cells_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

poll::poll()
  : id_()
  , flags_()
  , closed_()
  , public_voters_()
  , multiple_choice_()
  , quiz_()
  , open_answers_()
  , revoting_disabled_()
  , shuffle_answers_()
  , hide_results_until_close_()
  , creator_()
  , subscribers_only_()
  , question_()
  , answers_()
  , close_period_()
  , close_date_()
  , countries_iso2_()
  , hash_()
{}

poll::poll(int64 id_, int32 flags_, bool closed_, bool public_voters_, bool multiple_choice_, bool quiz_, bool open_answers_, bool revoting_disabled_, bool shuffle_answers_, bool hide_results_until_close_, bool creator_, bool subscribers_only_, object_ptr<textWithEntities> &&question_, array<object_ptr<PollAnswer>> &&answers_, int32 close_period_, int32 close_date_, array<string> &&countries_iso2_, int64 hash_)
  : id_(id_)
  , flags_(flags_)
  , closed_(closed_)
  , public_voters_(public_voters_)
  , multiple_choice_(multiple_choice_)
  , quiz_(quiz_)
  , open_answers_(open_answers_)
  , revoting_disabled_(revoting_disabled_)
  , shuffle_answers_(shuffle_answers_)
  , hide_results_until_close_(hide_results_until_close_)
  , creator_(creator_)
  , subscribers_only_(subscribers_only_)
  , question_(std::move(question_))
  , answers_(std::move(answers_))
  , close_period_(close_period_)
  , close_date_(close_date_)
  , countries_iso2_(std::move(countries_iso2_))
  , hash_(hash_)
{}

const std::int32_t poll::ID;

object_ptr<poll> poll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<poll> res = make_tl_object<poll>();
  int32 var0;
  res->id_ = TlFetchLong::parse(p);
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->closed_ = (var0 & 1) != 0;
  res->public_voters_ = (var0 & 2) != 0;
  res->multiple_choice_ = (var0 & 4) != 0;
  res->quiz_ = (var0 & 8) != 0;
  res->open_answers_ = (var0 & 64) != 0;
  res->revoting_disabled_ = (var0 & 128) != 0;
  res->shuffle_answers_ = (var0 & 256) != 0;
  res->hide_results_until_close_ = (var0 & 512) != 0;
  res->creator_ = (var0 & 1024) != 0;
  res->subscribers_only_ = (var0 & 2048) != 0;
  res->question_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  res->answers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PollAnswer>>, 481674261>::parse(p);
  if (var0 & 16) { res->close_period_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->close_date_ = TlFetchInt::parse(p); }
  if (var0 & 4096) { res->countries_iso2_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p); }
  res->hash_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void poll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (closed_ << 0) | (public_voters_ << 1) | (multiple_choice_ << 2) | (quiz_ << 3) | (open_answers_ << 6) | (revoting_disabled_ << 7) | (shuffle_answers_ << 8) | (hide_results_until_close_ << 9) | (creator_ << 10) | (subscribers_only_ << 11) | ((!countries_iso2_.empty()) << 12)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(question_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(answers_, s);
  if (var0 & 16) { TlStoreBinary::store(close_period_, s); }
  if (var0 & 32) { TlStoreBinary::store(close_date_, s); }
  if (var0 & 4096) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  TlStoreBinary::store(hash_, s);
}

void poll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (closed_ << 0) | (public_voters_ << 1) | (multiple_choice_ << 2) | (quiz_ << 3) | (open_answers_ << 6) | (revoting_disabled_ << 7) | (shuffle_answers_ << 8) | (hide_results_until_close_ << 9) | (creator_ << 10) | (subscribers_only_ << 11) | ((!countries_iso2_.empty()) << 12)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(question_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(answers_, s);
  if (var0 & 16) { TlStoreBinary::store(close_period_, s); }
  if (var0 & 32) { TlStoreBinary::store(close_date_, s); }
  if (var0 & 4096) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  TlStoreBinary::store(hash_, s);
}

void poll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "poll");
  int32 var0;
    s.store_field("id", id_);
    s.store_field("flags", (var0 = flags_ | (closed_ << 0) | (public_voters_ << 1) | (multiple_choice_ << 2) | (quiz_ << 3) | (open_answers_ << 6) | (revoting_disabled_ << 7) | (shuffle_answers_ << 8) | (hide_results_until_close_ << 9) | (creator_ << 10) | (subscribers_only_ << 11) | ((!countries_iso2_.empty()) << 12)));
    if (var0 & 1) { s.store_field("closed", true); }
    if (var0 & 2) { s.store_field("public_voters", true); }
    if (var0 & 4) { s.store_field("multiple_choice", true); }
    if (var0 & 8) { s.store_field("quiz", true); }
    if (var0 & 64) { s.store_field("open_answers", true); }
    if (var0 & 128) { s.store_field("revoting_disabled", true); }
    if (var0 & 256) { s.store_field("shuffle_answers", true); }
    if (var0 & 512) { s.store_field("hide_results_until_close", true); }
    if (var0 & 1024) { s.store_field("creator", true); }
    if (var0 & 2048) { s.store_field("subscribers_only", true); }
    s.store_object_field("question", static_cast<const BaseObject *>(question_.get()));
    { s.store_vector_begin("answers", answers_.size()); for (const auto &_value : answers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 16) { s.store_field("close_period", close_period_); }
    if (var0 & 32) { s.store_field("close_date", close_date_); }
    if (var0 & 4096) { { s.store_vector_begin("countries_iso2", countries_iso2_.size()); for (const auto &_value : countries_iso2_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

restrictionReason::restrictionReason(string const &platform_, string const &reason_, string const &text_)
  : platform_(platform_)
  , reason_(reason_)
  , text_(text_)
{}

const std::int32_t restrictionReason::ID;

object_ptr<restrictionReason> restrictionReason::fetch(TlBufferParser &p) {
  return make_tl_object<restrictionReason>(p);
}

restrictionReason::restrictionReason(TlBufferParser &p)
  : platform_(TlFetchString<string>::parse(p))
  , reason_(TlFetchString<string>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void restrictionReason::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(platform_, s);
  TlStoreString::store(reason_, s);
  TlStoreString::store(text_, s);
}

void restrictionReason::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(platform_, s);
  TlStoreString::store(reason_, s);
  TlStoreString::store(text_, s);
}

void restrictionReason::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "restrictionReason");
    s.store_field("platform", platform_);
    s.store_field("reason", reason_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

object_ptr<StarGiftAuctionState> StarGiftAuctionState::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starGiftAuctionStateNotModified::ID:
      return starGiftAuctionStateNotModified::fetch(p);
    case starGiftAuctionState::ID:
      return starGiftAuctionState::fetch(p);
    case starGiftAuctionStateFinished::ID:
      return starGiftAuctionStateFinished::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t starGiftAuctionStateNotModified::ID;

object_ptr<StarGiftAuctionState> starGiftAuctionStateNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAuctionStateNotModified>();
}

void starGiftAuctionStateNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionStateNotModified");
    s.store_class_end();
  }
}

const std::int32_t starGiftAuctionState::ID;

object_ptr<StarGiftAuctionState> starGiftAuctionState::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAuctionState>(p);
}

starGiftAuctionState::starGiftAuctionState(TlBufferParser &p)
  : version_(TlFetchInt::parse(p))
  , start_date_(TlFetchInt::parse(p))
  , end_date_(TlFetchInt::parse(p))
  , min_bid_amount_(TlFetchLong::parse(p))
  , bid_levels_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<auctionBidLevel>, 822231244>>, 481674261>::parse(p))
  , top_bidders_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
  , next_round_at_(TlFetchInt::parse(p))
  , last_gift_num_(TlFetchInt::parse(p))
  , gifts_left_(TlFetchInt::parse(p))
  , current_round_(TlFetchInt::parse(p))
  , total_rounds_(TlFetchInt::parse(p))
  , rounds_(TlFetchBoxed<TlFetchVector<TlFetchObject<StarGiftAuctionRound>>, 481674261>::parse(p))
{}

void starGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionState");
    s.store_field("version", version_);
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_field("min_bid_amount", min_bid_amount_);
    { s.store_vector_begin("bid_levels", bid_levels_.size()); for (const auto &_value : bid_levels_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_bidders", top_bidders_.size()); for (const auto &_value : top_bidders_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("next_round_at", next_round_at_);
    s.store_field("last_gift_num", last_gift_num_);
    s.store_field("gifts_left", gifts_left_);
    s.store_field("current_round", current_round_);
    s.store_field("total_rounds", total_rounds_);
    { s.store_vector_begin("rounds", rounds_.size()); for (const auto &_value : rounds_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starGiftAuctionStateFinished::starGiftAuctionStateFinished()
  : flags_()
  , start_date_()
  , end_date_()
  , average_price_()
  , listed_count_()
  , fragment_listed_count_()
  , fragment_listed_url_()
{}

const std::int32_t starGiftAuctionStateFinished::ID;

object_ptr<StarGiftAuctionState> starGiftAuctionStateFinished::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftAuctionStateFinished> res = make_tl_object<starGiftAuctionStateFinished>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->start_date_ = TlFetchInt::parse(p);
  res->end_date_ = TlFetchInt::parse(p);
  res->average_price_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->listed_count_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->fragment_listed_count_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->fragment_listed_url_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void starGiftAuctionStateFinished::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionStateFinished");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!fragment_listed_url_.empty()) << 1)));
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_field("average_price", average_price_);
    if (var0 & 1) { s.store_field("listed_count", listed_count_); }
    if (var0 & 2) { s.store_field("fragment_listed_count", fragment_listed_count_); }
    if (var0 & 2) { s.store_field("fragment_listed_url", fragment_listed_url_); }
    s.store_class_end();
  }
}

starGiftCollection::starGiftCollection()
  : flags_()
  , collection_id_()
  , title_()
  , icon_()
  , gifts_count_()
  , hash_()
{}

const std::int32_t starGiftCollection::ID;

object_ptr<starGiftCollection> starGiftCollection::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftCollection> res = make_tl_object<starGiftCollection>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collection_id_ = TlFetchInt::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->icon_ = TlFetchObject<Document>::parse(p); }
  res->gifts_count_ = TlFetchInt::parse(p);
  res->hash_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftCollection");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((icon_ != nullptr) << 0)));
    s.store_field("collection_id", collection_id_);
    s.store_field("title", title_);
    if (var0 & 1) { s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get())); }
    s.store_field("gifts_count", gifts_count_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

starsTransaction::starsTransaction()
  : flags_()
  , refund_()
  , pending_()
  , failed_()
  , gift_()
  , reaction_()
  , stargift_upgrade_()
  , business_transfer_()
  , stargift_resale_()
  , posts_search_()
  , stargift_prepaid_upgrade_()
  , stargift_drop_original_details_()
  , phonegroup_message_()
  , stargift_auction_bid_()
  , offer_()
  , id_()
  , amount_()
  , date_()
  , peer_()
  , title_()
  , description_()
  , photo_()
  , transaction_date_()
  , transaction_url_()
  , bot_payload_()
  , msg_id_()
  , extended_media_()
  , subscription_period_()
  , giveaway_post_id_()
  , stargift_()
  , floodskip_number_()
  , starref_commission_permille_()
  , starref_peer_()
  , starref_amount_()
  , paid_messages_()
  , premium_gift_months_()
  , ads_proceeds_from_date_()
  , ads_proceeds_to_date_()
{}

const std::int32_t starsTransaction::ID;

object_ptr<starsTransaction> starsTransaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsTransaction> res = make_tl_object<starsTransaction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->refund_ = (var0 & 8) != 0;
  res->pending_ = (var0 & 16) != 0;
  res->failed_ = (var0 & 64) != 0;
  res->gift_ = (var0 & 1024) != 0;
  res->reaction_ = (var0 & 2048) != 0;
  res->stargift_upgrade_ = (var0 & 262144) != 0;
  res->business_transfer_ = (var0 & 2097152) != 0;
  res->stargift_resale_ = (var0 & 4194304) != 0;
  res->posts_search_ = (var0 & 16777216) != 0;
  res->stargift_prepaid_upgrade_ = (var0 & 33554432) != 0;
  res->stargift_drop_original_details_ = (var0 & 67108864) != 0;
  res->phonegroup_message_ = (var0 & 134217728) != 0;
  res->stargift_auction_bid_ = (var0 & 268435456) != 0;
  res->offer_ = (var0 & 536870912) != 0;
  res->id_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchObject<StarsAmount>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->peer_ = TlFetchObject<StarsTransactionPeer>::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->description_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 32) { res->transaction_date_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->transaction_url_ = TlFetchString<string>::parse(p); }
  if (var0 & 128) { res->bot_payload_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 256) { res->msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 512) { res->extended_media_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageMedia>>, 481674261>::parse(p); }
  if (var0 & 4096) { res->subscription_period_ = TlFetchInt::parse(p); }
  if (var0 & 8192) { res->giveaway_post_id_ = TlFetchInt::parse(p); }
  if (var0 & 16384) { res->stargift_ = TlFetchObject<StarGift>::parse(p); }
  if (var0 & 32768) { res->floodskip_number_ = TlFetchInt::parse(p); }
  if (var0 & 65536) { res->starref_commission_permille_ = TlFetchInt::parse(p); }
  if (var0 & 131072) { res->starref_peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 131072) { res->starref_amount_ = TlFetchObject<StarsAmount>::parse(p); }
  if (var0 & 524288) { res->paid_messages_ = TlFetchInt::parse(p); }
  if (var0 & 1048576) { res->premium_gift_months_ = TlFetchInt::parse(p); }
  if (var0 & 8388608) { res->ads_proceeds_from_date_ = TlFetchInt::parse(p); }
  if (var0 & 8388608) { res->ads_proceeds_to_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (refund_ << 3) | (pending_ << 4) | (failed_ << 6) | (gift_ << 10) | (reaction_ << 11) | (stargift_upgrade_ << 18) | (business_transfer_ << 21) | (stargift_resale_ << 22) | (posts_search_ << 24) | (stargift_prepaid_upgrade_ << 25) | (stargift_drop_original_details_ << 26) | (phonegroup_message_ << 27) | (stargift_auction_bid_ << 28) | (offer_ << 29) | ((!title_.empty()) << 0) | ((!description_.empty()) << 1) | ((photo_ != nullptr) << 2) | ((!transaction_url_.empty()) << 5) | ((!bot_payload_.empty()) << 7) | ((!extended_media_.empty()) << 9) | ((stargift_ != nullptr) << 14) | ((starref_peer_ != nullptr) << 17) | ((starref_amount_ != nullptr) << 17)));
    if (var0 & 8) { s.store_field("refund", true); }
    if (var0 & 16) { s.store_field("pending", true); }
    if (var0 & 64) { s.store_field("failed", true); }
    if (var0 & 1024) { s.store_field("gift", true); }
    if (var0 & 2048) { s.store_field("reaction", true); }
    if (var0 & 262144) { s.store_field("stargift_upgrade", true); }
    if (var0 & 2097152) { s.store_field("business_transfer", true); }
    if (var0 & 4194304) { s.store_field("stargift_resale", true); }
    if (var0 & 16777216) { s.store_field("posts_search", true); }
    if (var0 & 33554432) { s.store_field("stargift_prepaid_upgrade", true); }
    if (var0 & 67108864) { s.store_field("stargift_drop_original_details", true); }
    if (var0 & 134217728) { s.store_field("phonegroup_message", true); }
    if (var0 & 268435456) { s.store_field("stargift_auction_bid", true); }
    if (var0 & 536870912) { s.store_field("offer", true); }
    s.store_field("id", id_);
    s.store_object_field("amount", static_cast<const BaseObject *>(amount_.get()));
    s.store_field("date", date_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("description", description_); }
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 32) { s.store_field("transaction_date", transaction_date_); }
    if (var0 & 32) { s.store_field("transaction_url", transaction_url_); }
    if (var0 & 128) { s.store_bytes_field("bot_payload", bot_payload_); }
    if (var0 & 256) { s.store_field("msg_id", msg_id_); }
    if (var0 & 512) { { s.store_vector_begin("extended_media", extended_media_.size()); for (const auto &_value : extended_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4096) { s.store_field("subscription_period", subscription_period_); }
    if (var0 & 8192) { s.store_field("giveaway_post_id", giveaway_post_id_); }
    if (var0 & 16384) { s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get())); }
    if (var0 & 32768) { s.store_field("floodskip_number", floodskip_number_); }
    if (var0 & 65536) { s.store_field("starref_commission_permille", starref_commission_permille_); }
    if (var0 & 131072) { s.store_object_field("starref_peer", static_cast<const BaseObject *>(starref_peer_.get())); }
    if (var0 & 131072) { s.store_object_field("starref_amount", static_cast<const BaseObject *>(starref_amount_.get())); }
    if (var0 & 524288) { s.store_field("paid_messages", paid_messages_); }
    if (var0 & 1048576) { s.store_field("premium_gift_months", premium_gift_months_); }
    if (var0 & 8388608) { s.store_field("ads_proceeds_from_date", ads_proceeds_from_date_); }
    if (var0 & 8388608) { s.store_field("ads_proceeds_to_date", ads_proceeds_to_date_); }
    s.store_class_end();
  }
}

object_ptr<StatsGraph> StatsGraph::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case statsGraphAsync::ID:
      return statsGraphAsync::fetch(p);
    case statsGraphError::ID:
      return statsGraphError::fetch(p);
    case statsGraph::ID:
      return statsGraph::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t statsGraphAsync::ID;

object_ptr<StatsGraph> statsGraphAsync::fetch(TlBufferParser &p) {
  return make_tl_object<statsGraphAsync>(p);
}

statsGraphAsync::statsGraphAsync(TlBufferParser &p)
  : token_(TlFetchString<string>::parse(p))
{}

void statsGraphAsync::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGraphAsync");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

statsGraphError::statsGraphError(string const &error_)
  : error_(error_)
{}

const std::int32_t statsGraphError::ID;

object_ptr<StatsGraph> statsGraphError::fetch(TlBufferParser &p) {
  return make_tl_object<statsGraphError>(p);
}

statsGraphError::statsGraphError(TlBufferParser &p)
  : error_(TlFetchString<string>::parse(p))
{}

void statsGraphError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGraphError");
    s.store_field("error", error_);
    s.store_class_end();
  }
}

statsGraph::statsGraph()
  : flags_()
  , json_()
  , zoom_token_()
{}

const std::int32_t statsGraph::ID;

object_ptr<StatsGraph> statsGraph::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<statsGraph> res = make_tl_object<statsGraph>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->json_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
  if (var0 & 1) { res->zoom_token_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void statsGraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGraph");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!zoom_token_.empty()) << 0)));
    s.store_object_field("json", static_cast<const BaseObject *>(json_.get()));
    if (var0 & 1) { s.store_field("zoom_token", "[REDACTED]"); }
    s.store_class_end();
  }
}

const std::int32_t stickerPack::ID;

object_ptr<stickerPack> stickerPack::fetch(TlBufferParser &p) {
  return make_tl_object<stickerPack>(p);
}

stickerPack::stickerPack(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
  , documents_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void stickerPack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerPack");
    s.store_field("emoticon", emoticon_);
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

storiesStealthMode::storiesStealthMode()
  : flags_()
  , active_until_date_()
  , cooldown_until_date_()
{}

const std::int32_t storiesStealthMode::ID;

object_ptr<storiesStealthMode> storiesStealthMode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storiesStealthMode> res = make_tl_object<storiesStealthMode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->active_until_date_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->cooldown_until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void storiesStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storiesStealthMode");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("active_until_date", active_until_date_); }
    if (var0 & 2) { s.store_field("cooldown_until_date", cooldown_until_date_); }
    s.store_class_end();
  }
}

const std::int32_t topPeer::ID;

object_ptr<topPeer> topPeer::fetch(TlBufferParser &p) {
  return make_tl_object<topPeer>(p);
}

topPeer::topPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , rating_(TlFetchDouble::parse(p))
{}

void topPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("rating", rating_);
    s.store_class_end();
  }
}

object_ptr<Update> Update::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case updateNewMessage::ID:
      return updateNewMessage::fetch(p);
    case updateMessageID::ID:
      return updateMessageID::fetch(p);
    case updateDeleteMessages::ID:
      return updateDeleteMessages::fetch(p);
    case updateUserTyping::ID:
      return updateUserTyping::fetch(p);
    case updateChatUserTyping::ID:
      return updateChatUserTyping::fetch(p);
    case updateChatParticipants::ID:
      return updateChatParticipants::fetch(p);
    case updateUserStatus::ID:
      return updateUserStatus::fetch(p);
    case updateUserName::ID:
      return updateUserName::fetch(p);
    case updateNewAuthorization::ID:
      return updateNewAuthorization::fetch(p);
    case updateNewEncryptedMessage::ID:
      return updateNewEncryptedMessage::fetch(p);
    case updateEncryptedChatTyping::ID:
      return updateEncryptedChatTyping::fetch(p);
    case updateEncryption::ID:
      return updateEncryption::fetch(p);
    case updateEncryptedMessagesRead::ID:
      return updateEncryptedMessagesRead::fetch(p);
    case updateChatParticipantAdd::ID:
      return updateChatParticipantAdd::fetch(p);
    case updateChatParticipantDelete::ID:
      return updateChatParticipantDelete::fetch(p);
    case updateDcOptions::ID:
      return updateDcOptions::fetch(p);
    case updateNotifySettings::ID:
      return updateNotifySettings::fetch(p);
    case updateServiceNotification::ID:
      return updateServiceNotification::fetch(p);
    case updatePrivacy::ID:
      return updatePrivacy::fetch(p);
    case updateUserPhone::ID:
      return updateUserPhone::fetch(p);
    case updateReadHistoryInbox::ID:
      return updateReadHistoryInbox::fetch(p);
    case updateReadHistoryOutbox::ID:
      return updateReadHistoryOutbox::fetch(p);
    case updateWebPage::ID:
      return updateWebPage::fetch(p);
    case updateReadMessagesContents::ID:
      return updateReadMessagesContents::fetch(p);
    case updateChannelTooLong::ID:
      return updateChannelTooLong::fetch(p);
    case updateChannel::ID:
      return updateChannel::fetch(p);
    case updateNewChannelMessage::ID:
      return updateNewChannelMessage::fetch(p);
    case updateReadChannelInbox::ID:
      return updateReadChannelInbox::fetch(p);
    case updateDeleteChannelMessages::ID:
      return updateDeleteChannelMessages::fetch(p);
    case updateChannelMessageViews::ID:
      return updateChannelMessageViews::fetch(p);
    case updateChatParticipantAdmin::ID:
      return updateChatParticipantAdmin::fetch(p);
    case updateNewStickerSet::ID:
      return updateNewStickerSet::fetch(p);
    case updateStickerSetsOrder::ID:
      return updateStickerSetsOrder::fetch(p);
    case updateStickerSets::ID:
      return updateStickerSets::fetch(p);
    case updateSavedGifs::ID:
      return updateSavedGifs::fetch(p);
    case updateBotInlineQuery::ID:
      return updateBotInlineQuery::fetch(p);
    case updateBotInlineSend::ID:
      return updateBotInlineSend::fetch(p);
    case updateEditChannelMessage::ID:
      return updateEditChannelMessage::fetch(p);
    case updateBotCallbackQuery::ID:
      return updateBotCallbackQuery::fetch(p);
    case updateEditMessage::ID:
      return updateEditMessage::fetch(p);
    case updateInlineBotCallbackQuery::ID:
      return updateInlineBotCallbackQuery::fetch(p);
    case updateReadChannelOutbox::ID:
      return updateReadChannelOutbox::fetch(p);
    case updateDraftMessage::ID:
      return updateDraftMessage::fetch(p);
    case updateReadFeaturedStickers::ID:
      return updateReadFeaturedStickers::fetch(p);
    case updateRecentStickers::ID:
      return updateRecentStickers::fetch(p);
    case updateConfig::ID:
      return updateConfig::fetch(p);
    case updatePtsChanged::ID:
      return updatePtsChanged::fetch(p);
    case updateChannelWebPage::ID:
      return updateChannelWebPage::fetch(p);
    case updateDialogPinned::ID:
      return updateDialogPinned::fetch(p);
    case updatePinnedDialogs::ID:
      return updatePinnedDialogs::fetch(p);
    case updateBotWebhookJSON::ID:
      return updateBotWebhookJSON::fetch(p);
    case updateBotWebhookJSONQuery::ID:
      return updateBotWebhookJSONQuery::fetch(p);
    case updateBotShippingQuery::ID:
      return updateBotShippingQuery::fetch(p);
    case updateBotPrecheckoutQuery::ID:
      return updateBotPrecheckoutQuery::fetch(p);
    case updatePhoneCall::ID:
      return updatePhoneCall::fetch(p);
    case updateLangPackTooLong::ID:
      return updateLangPackTooLong::fetch(p);
    case updateLangPack::ID:
      return updateLangPack::fetch(p);
    case updateFavedStickers::ID:
      return updateFavedStickers::fetch(p);
    case updateChannelReadMessagesContents::ID:
      return updateChannelReadMessagesContents::fetch(p);
    case updateContactsReset::ID:
      return updateContactsReset::fetch(p);
    case updateChannelAvailableMessages::ID:
      return updateChannelAvailableMessages::fetch(p);
    case updateDialogUnreadMark::ID:
      return updateDialogUnreadMark::fetch(p);
    case updateMessagePoll::ID:
      return updateMessagePoll::fetch(p);
    case updateChatDefaultBannedRights::ID:
      return updateChatDefaultBannedRights::fetch(p);
    case updateFolderPeers::ID:
      return updateFolderPeers::fetch(p);
    case updatePeerSettings::ID:
      return updatePeerSettings::fetch(p);
    case updatePeerLocated::ID:
      return updatePeerLocated::fetch(p);
    case updateNewScheduledMessage::ID:
      return updateNewScheduledMessage::fetch(p);
    case updateDeleteScheduledMessages::ID:
      return updateDeleteScheduledMessages::fetch(p);
    case updateTheme::ID:
      return updateTheme::fetch(p);
    case updateGeoLiveViewed::ID:
      return updateGeoLiveViewed::fetch(p);
    case updateLoginToken::ID:
      return updateLoginToken::fetch(p);
    case updateMessagePollVote::ID:
      return updateMessagePollVote::fetch(p);
    case updateDialogFilter::ID:
      return updateDialogFilter::fetch(p);
    case updateDialogFilterOrder::ID:
      return updateDialogFilterOrder::fetch(p);
    case updateDialogFilters::ID:
      return updateDialogFilters::fetch(p);
    case updatePhoneCallSignalingData::ID:
      return updatePhoneCallSignalingData::fetch(p);
    case updateChannelMessageForwards::ID:
      return updateChannelMessageForwards::fetch(p);
    case updateReadChannelDiscussionInbox::ID:
      return updateReadChannelDiscussionInbox::fetch(p);
    case updateReadChannelDiscussionOutbox::ID:
      return updateReadChannelDiscussionOutbox::fetch(p);
    case updatePeerBlocked::ID:
      return updatePeerBlocked::fetch(p);
    case updateChannelUserTyping::ID:
      return updateChannelUserTyping::fetch(p);
    case updatePinnedMessages::ID:
      return updatePinnedMessages::fetch(p);
    case updatePinnedChannelMessages::ID:
      return updatePinnedChannelMessages::fetch(p);
    case updateChat::ID:
      return updateChat::fetch(p);
    case updateGroupCallParticipants::ID:
      return updateGroupCallParticipants::fetch(p);
    case updateGroupCall::ID:
      return updateGroupCall::fetch(p);
    case updatePeerHistoryTTL::ID:
      return updatePeerHistoryTTL::fetch(p);
    case updateChatParticipant::ID:
      return updateChatParticipant::fetch(p);
    case updateChannelParticipant::ID:
      return updateChannelParticipant::fetch(p);
    case updateBotStopped::ID:
      return updateBotStopped::fetch(p);
    case updateGroupCallConnection::ID:
      return updateGroupCallConnection::fetch(p);
    case updateBotCommands::ID:
      return updateBotCommands::fetch(p);
    case updatePendingJoinRequests::ID:
      return updatePendingJoinRequests::fetch(p);
    case updateBotChatInviteRequester::ID:
      return updateBotChatInviteRequester::fetch(p);
    case updateMessageReactions::ID:
      return updateMessageReactions::fetch(p);
    case updateAttachMenuBots::ID:
      return updateAttachMenuBots::fetch(p);
    case updateWebViewResultSent::ID:
      return updateWebViewResultSent::fetch(p);
    case updateBotMenuButton::ID:
      return updateBotMenuButton::fetch(p);
    case updateSavedRingtones::ID:
      return updateSavedRingtones::fetch(p);
    case updateTranscribedAudio::ID:
      return updateTranscribedAudio::fetch(p);
    case updateReadFeaturedEmojiStickers::ID:
      return updateReadFeaturedEmojiStickers::fetch(p);
    case updateUserEmojiStatus::ID:
      return updateUserEmojiStatus::fetch(p);
    case updateRecentEmojiStatuses::ID:
      return updateRecentEmojiStatuses::fetch(p);
    case updateRecentReactions::ID:
      return updateRecentReactions::fetch(p);
    case updateMoveStickerSetToTop::ID:
      return updateMoveStickerSetToTop::fetch(p);
    case updateMessageExtendedMedia::ID:
      return updateMessageExtendedMedia::fetch(p);
    case updateUser::ID:
      return updateUser::fetch(p);
    case updateAutoSaveSettings::ID:
      return updateAutoSaveSettings::fetch(p);
    case updateStory::ID:
      return updateStory::fetch(p);
    case updateReadStories::ID:
      return updateReadStories::fetch(p);
    case updateStoryID::ID:
      return updateStoryID::fetch(p);
    case updateStoriesStealthMode::ID:
      return updateStoriesStealthMode::fetch(p);
    case updateSentStoryReaction::ID:
      return updateSentStoryReaction::fetch(p);
    case updateBotChatBoost::ID:
      return updateBotChatBoost::fetch(p);
    case updateChannelViewForumAsMessages::ID:
      return updateChannelViewForumAsMessages::fetch(p);
    case updatePeerWallpaper::ID:
      return updatePeerWallpaper::fetch(p);
    case updateBotMessageReaction::ID:
      return updateBotMessageReaction::fetch(p);
    case updateBotMessageReactions::ID:
      return updateBotMessageReactions::fetch(p);
    case updateSavedDialogPinned::ID:
      return updateSavedDialogPinned::fetch(p);
    case updatePinnedSavedDialogs::ID:
      return updatePinnedSavedDialogs::fetch(p);
    case updateSavedReactionTags::ID:
      return updateSavedReactionTags::fetch(p);
    case updateSmsJob::ID:
      return updateSmsJob::fetch(p);
    case updateQuickReplies::ID:
      return updateQuickReplies::fetch(p);
    case updateNewQuickReply::ID:
      return updateNewQuickReply::fetch(p);
    case updateDeleteQuickReply::ID:
      return updateDeleteQuickReply::fetch(p);
    case updateQuickReplyMessage::ID:
      return updateQuickReplyMessage::fetch(p);
    case updateDeleteQuickReplyMessages::ID:
      return updateDeleteQuickReplyMessages::fetch(p);
    case updateBotBusinessConnect::ID:
      return updateBotBusinessConnect::fetch(p);
    case updateBotNewBusinessMessage::ID:
      return updateBotNewBusinessMessage::fetch(p);
    case updateBotEditBusinessMessage::ID:
      return updateBotEditBusinessMessage::fetch(p);
    case updateBotDeleteBusinessMessage::ID:
      return updateBotDeleteBusinessMessage::fetch(p);
    case updateNewStoryReaction::ID:
      return updateNewStoryReaction::fetch(p);
    case updateStarsBalance::ID:
      return updateStarsBalance::fetch(p);
    case updateBusinessBotCallbackQuery::ID:
      return updateBusinessBotCallbackQuery::fetch(p);
    case updateStarsRevenueStatus::ID:
      return updateStarsRevenueStatus::fetch(p);
    case updateBotPurchasedPaidMedia::ID:
      return updateBotPurchasedPaidMedia::fetch(p);
    case updatePaidReactionPrivacy::ID:
      return updatePaidReactionPrivacy::fetch(p);
    case updateSentPhoneCode::ID:
      return updateSentPhoneCode::fetch(p);
    case updateGroupCallChainBlocks::ID:
      return updateGroupCallChainBlocks::fetch(p);
    case updateReadMonoForumInbox::ID:
      return updateReadMonoForumInbox::fetch(p);
    case updateReadMonoForumOutbox::ID:
      return updateReadMonoForumOutbox::fetch(p);
    case updateMonoForumNoPaidException::ID:
      return updateMonoForumNoPaidException::fetch(p);
    case updateGroupCallMessage::ID:
      return updateGroupCallMessage::fetch(p);
    case updateGroupCallEncryptedMessage::ID:
      return updateGroupCallEncryptedMessage::fetch(p);
    case updatePinnedForumTopic::ID:
      return updatePinnedForumTopic::fetch(p);
    case updatePinnedForumTopics::ID:
      return updatePinnedForumTopics::fetch(p);
    case updateDeleteGroupCallMessages::ID:
      return updateDeleteGroupCallMessages::fetch(p);
    case updateStarGiftAuctionState::ID:
      return updateStarGiftAuctionState::fetch(p);
    case updateStarGiftAuctionUserState::ID:
      return updateStarGiftAuctionUserState::fetch(p);
    case updateEmojiGameInfo::ID:
      return updateEmojiGameInfo::fetch(p);
    case updateStarGiftCraftFail::ID:
      return updateStarGiftCraftFail::fetch(p);
    case updateChatParticipantRank::ID:
      return updateChatParticipantRank::fetch(p);
    case updateManagedBot::ID:
      return updateManagedBot::fetch(p);
    case updateBotGuestChatQuery::ID:
      return updateBotGuestChatQuery::fetch(p);
    case updateAiComposeTones::ID:
      return updateAiComposeTones::fetch(p);
    case updateJoinChatWebViewDecision::ID:
      return updateJoinChatWebViewDecision::fetch(p);
    case updateNewBotConnection::ID:
      return updateNewBotConnection::fetch(p);
    case updateWebBrowserSettings::ID:
      return updateWebBrowserSettings::fetch(p);
    case updateWebBrowserException::ID:
      return updateWebBrowserException::fetch(p);
    case updateNewEphemeralMessage::ID:
      return updateNewEphemeralMessage::fetch(p);
    case updateDeleteEphemeralMessages::ID:
      return updateDeleteEphemeralMessages::fetch(p);
    case updateEditEphemeralMessage::ID:
      return updateEditEphemeralMessage::fetch(p);
    case updateEphemeralBotCallbackQuery::ID:
      return updateEphemeralBotCallbackQuery::fetch(p);
    case updateBotStarsSubscription::ID:
      return updateBotStarsSubscription::fetch(p);
    case updateWalletState::ID:
      return updateWalletState::fetch(p);
    case updateSentWalletTransaction::ID:
      return updateSentWalletTransaction::fetch(p);
    case updateWalletGaslessInfo::ID:
      return updateWalletGaslessInfo::fetch(p);
    case updateWalletTonConnectSession::ID:
      return updateWalletTonConnectSession::fetch(p);
    case updateWalletTonConnectPendingDisconnect::ID:
      return updateWalletTonConnectPendingDisconnect::fetch(p);
    case updateEditForumTopic::ID:
      return updateEditForumTopic::fetch(p);
    case updateBotWidgetQuery::ID:
      return updateBotWidgetQuery::fetch(p);
    case updateInlineBotWidgetQuery::ID:
      return updateInlineBotWidgetQuery::fetch(p);
    case updateBotWidgetCopyQuery::ID:
      return updateBotWidgetCopyQuery::fetch(p);
    case updateMessageWidgetData::ID:
      return updateMessageWidgetData::fetch(p);
    case updateTranscribedAudioFile::ID:
      return updateTranscribedAudioFile::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

updateNewMessage::updateNewMessage(object_ptr<Message> &&message_, int32 pts_, int32 pts_count_)
  : message_(std::move(message_))
  , pts_(pts_)
  , pts_count_(pts_count_)
{}

const std::int32_t updateNewMessage::ID;

object_ptr<Update> updateNewMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewMessage>(p);
}

updateNewMessage::updateNewMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateNewMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updateMessageID::ID;

object_ptr<Update> updateMessageID::fetch(TlBufferParser &p) {
  return make_tl_object<updateMessageID>(p);
}

updateMessageID::updateMessageID(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , random_id_(TlFetchLong::parse(p))
{}

void updateMessageID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageID");
    s.store_field("id", id_);
    s.store_field("random_id", random_id_);
    s.store_class_end();
  }
}

updateDeleteMessages::updateDeleteMessages(array<int32> &&messages_, int32 pts_, int32 pts_count_)
  : messages_(std::move(messages_))
  , pts_(pts_)
  , pts_count_(pts_count_)
{}

const std::int32_t updateDeleteMessages::ID;

object_ptr<Update> updateDeleteMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateDeleteMessages>(p);
}

updateDeleteMessages::updateDeleteMessages(TlBufferParser &p)
  : messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateDeleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteMessages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateUserTyping::updateUserTyping()
  : flags_()
  , user_id_()
  , top_msg_id_()
  , action_()
{}

const std::int32_t updateUserTyping::ID;

object_ptr<Update> updateUserTyping::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateUserTyping> res = make_tl_object<updateUserTyping>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  res->action_ = TlFetchObject<SendMessageAction>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateUserTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserTyping");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("user_id", user_id_);
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateChatUserTyping::ID;

object_ptr<Update> updateChatUserTyping::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatUserTyping>(p);
}

updateChatUserTyping::updateChatUserTyping(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , from_id_(TlFetchObject<Peer>::parse(p))
  , action_(TlFetchObject<SendMessageAction>::parse(p))
{}

void updateChatUserTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatUserTyping");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateChatParticipants::ID;

object_ptr<Update> updateChatParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatParticipants>(p);
}

updateChatParticipants::updateChatParticipants(TlBufferParser &p)
  : participants_(TlFetchObject<ChatParticipants>::parse(p))
{}

void updateChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipants");
    s.store_object_field("participants", static_cast<const BaseObject *>(participants_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateUserStatus::ID;

object_ptr<Update> updateUserStatus::fetch(TlBufferParser &p) {
  return make_tl_object<updateUserStatus>(p);
}

updateUserStatus::updateUserStatus(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , status_(TlFetchObject<UserStatus>::parse(p))
{}

void updateUserStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserStatus");
    s.store_field("user_id", user_id_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateUserName::ID;

object_ptr<Update> updateUserName::fetch(TlBufferParser &p) {
  return make_tl_object<updateUserName>(p);
}

updateUserName::updateUserName(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , first_name_(TlFetchString<string>::parse(p))
  , last_name_(TlFetchString<string>::parse(p))
  , usernames_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<username>, -1274595769>>, 481674261>::parse(p))
{}

void updateUserName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserName");
    s.store_field("user_id", user_id_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateNewAuthorization::updateNewAuthorization()
  : flags_()
  , unconfirmed_()
  , hash_()
  , date_()
  , device_()
  , location_()
{}

const std::int32_t updateNewAuthorization::ID;

object_ptr<Update> updateNewAuthorization::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateNewAuthorization> res = make_tl_object<updateNewAuthorization>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->unconfirmed_ = (var0 & 1) != 0;
  res->hash_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->date_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->device_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->location_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateNewAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewAuthorization");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (unconfirmed_ << 0) | ((!device_.empty()) << 0) | ((!location_.empty()) << 0)));
    if (var0 & 1) { s.store_field("unconfirmed", true); }
    s.store_field("hash", hash_);
    if (var0 & 1) { s.store_field("date", date_); }
    if (var0 & 1) { s.store_field("device", device_); }
    if (var0 & 1) { s.store_field("location", location_); }
    s.store_class_end();
  }
}

const std::int32_t updateNewEncryptedMessage::ID;

object_ptr<Update> updateNewEncryptedMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewEncryptedMessage>(p);
}

updateNewEncryptedMessage::updateNewEncryptedMessage(TlBufferParser &p)
  : message_(TlFetchObject<EncryptedMessage>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateNewEncryptedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewEncryptedMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateEncryptedChatTyping::ID;

object_ptr<Update> updateEncryptedChatTyping::fetch(TlBufferParser &p) {
  return make_tl_object<updateEncryptedChatTyping>(p);
}

updateEncryptedChatTyping::updateEncryptedChatTyping(TlBufferParser &p)
  : chat_id_(TlFetchInt::parse(p))
{}

void updateEncryptedChatTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEncryptedChatTyping");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

const std::int32_t updateEncryption::ID;

object_ptr<Update> updateEncryption::fetch(TlBufferParser &p) {
  return make_tl_object<updateEncryption>(p);
}

updateEncryption::updateEncryption(TlBufferParser &p)
  : chat_(TlFetchObject<EncryptedChat>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void updateEncryption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEncryption");
    s.store_object_field("chat", static_cast<const BaseObject *>(chat_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t updateEncryptedMessagesRead::ID;

object_ptr<Update> updateEncryptedMessagesRead::fetch(TlBufferParser &p) {
  return make_tl_object<updateEncryptedMessagesRead>(p);
}

updateEncryptedMessagesRead::updateEncryptedMessagesRead(TlBufferParser &p)
  : chat_id_(TlFetchInt::parse(p))
  , max_date_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void updateEncryptedMessagesRead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEncryptedMessagesRead");
    s.store_field("chat_id", chat_id_);
    s.store_field("max_date", max_date_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t updateChatParticipantAdd::ID;

object_ptr<Update> updateChatParticipantAdd::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatParticipantAdd>(p);
}

updateChatParticipantAdd::updateChatParticipantAdd(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , inviter_id_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateChatParticipantAdd::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipantAdd");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("inviter_id", inviter_id_);
    s.store_field("date", date_);
    s.store_field("version", version_);
    s.store_class_end();
  }
}

const std::int32_t updateChatParticipantDelete::ID;

object_ptr<Update> updateChatParticipantDelete::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatParticipantDelete>(p);
}

updateChatParticipantDelete::updateChatParticipantDelete(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateChatParticipantDelete::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipantDelete");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("version", version_);
    s.store_class_end();
  }
}

const std::int32_t updateDcOptions::ID;

object_ptr<Update> updateDcOptions::fetch(TlBufferParser &p) {
  return make_tl_object<updateDcOptions>(p);
}

updateDcOptions::updateDcOptions(TlBufferParser &p)
  : dc_options_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<dcOption>, 414687501>>, 481674261>::parse(p))
{}

void updateDcOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDcOptions");
    { s.store_vector_begin("dc_options", dc_options_.size()); for (const auto &_value : dc_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateNotifySettings::ID;

object_ptr<Update> updateNotifySettings::fetch(TlBufferParser &p) {
  return make_tl_object<updateNotifySettings>(p);
}

updateNotifySettings::updateNotifySettings(TlBufferParser &p)
  : peer_(TlFetchObject<NotifyPeer>::parse(p))
  , notify_settings_(TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p))
{}

void updateNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNotifySettings");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    s.store_class_end();
  }
}

updateServiceNotification::updateServiceNotification()
  : flags_()
  , popup_()
  , invert_media_()
  , inbox_date_()
  , type_()
  , message_()
  , media_()
  , entities_()
{}

updateServiceNotification::updateServiceNotification(int32 flags_, bool popup_, bool invert_media_, int32 inbox_date_, string const &type_, string const &message_, object_ptr<MessageMedia> &&media_, array<object_ptr<MessageEntity>> &&entities_)
  : flags_(flags_)
  , popup_(popup_)
  , invert_media_(invert_media_)
  , inbox_date_(inbox_date_)
  , type_(type_)
  , message_(message_)
  , media_(std::move(media_))
  , entities_(std::move(entities_))
{}

const std::int32_t updateServiceNotification::ID;

object_ptr<Update> updateServiceNotification::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateServiceNotification> res = make_tl_object<updateServiceNotification>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->popup_ = (var0 & 1) != 0;
  res->invert_media_ = (var0 & 4) != 0;
  if (var0 & 2) { res->inbox_date_ = TlFetchInt::parse(p); }
  res->type_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  res->media_ = TlFetchObject<MessageMedia>::parse(p);
  res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateServiceNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateServiceNotification");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (popup_ << 0) | (invert_media_ << 2)));
    if (var0 & 1) { s.store_field("popup", true); }
    if (var0 & 4) { s.store_field("invert_media", true); }
    if (var0 & 2) { s.store_field("inbox_date", inbox_date_); }
    s.store_field("type", type_);
    s.store_field("message", message_);
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updatePrivacy::ID;

object_ptr<Update> updatePrivacy::fetch(TlBufferParser &p) {
  return make_tl_object<updatePrivacy>(p);
}

updatePrivacy::updatePrivacy(TlBufferParser &p)
  : key_(TlFetchObject<PrivacyKey>::parse(p))
  , rules_(TlFetchBoxed<TlFetchVector<TlFetchObject<PrivacyRule>>, 481674261>::parse(p))
{}

void updatePrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePrivacy");
    s.store_object_field("key", static_cast<const BaseObject *>(key_.get()));
    { s.store_vector_begin("rules", rules_.size()); for (const auto &_value : rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateUserPhone::ID;

object_ptr<Update> updateUserPhone::fetch(TlBufferParser &p) {
  return make_tl_object<updateUserPhone>(p);
}

updateUserPhone::updateUserPhone(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , phone_(TlFetchString<string>::parse(p))
{}

void updateUserPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserPhone");
    s.store_field("user_id", user_id_);
    s.store_field("phone", phone_);
    s.store_class_end();
  }
}

updateReadHistoryInbox::updateReadHistoryInbox()
  : flags_()
  , folder_id_()
  , peer_()
  , top_msg_id_()
  , max_id_()
  , still_unread_count_()
  , pts_()
  , pts_count_()
{}

const std::int32_t updateReadHistoryInbox::ID;

object_ptr<Update> updateReadHistoryInbox::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateReadHistoryInbox> res = make_tl_object<updateReadHistoryInbox>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->folder_id_ = TlFetchInt::parse(p); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 2) { res->top_msg_id_ = TlFetchInt::parse(p); }
  res->max_id_ = TlFetchInt::parse(p);
  res->still_unread_count_ = TlFetchInt::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateReadHistoryInbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadHistoryInbox");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("folder_id", folder_id_); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_field("max_id", max_id_);
    s.store_field("still_unread_count", still_unread_count_);
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updateReadHistoryOutbox::ID;

object_ptr<Update> updateReadHistoryOutbox::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadHistoryOutbox>(p);
}

updateReadHistoryOutbox::updateReadHistoryOutbox(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , max_id_(TlFetchInt::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateReadHistoryOutbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadHistoryOutbox");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updateWebPage::ID;

object_ptr<Update> updateWebPage::fetch(TlBufferParser &p) {
  return make_tl_object<updateWebPage>(p);
}

updateWebPage::updateWebPage(TlBufferParser &p)
  : webpage_(TlFetchObject<WebPage>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebPage");
    s.store_object_field("webpage", static_cast<const BaseObject *>(webpage_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateReadMessagesContents::updateReadMessagesContents()
  : flags_()
  , messages_()
  , pts_()
  , pts_count_()
  , date_()
{}

const std::int32_t updateReadMessagesContents::ID;

object_ptr<Update> updateReadMessagesContents::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateReadMessagesContents> res = make_tl_object<updateReadMessagesContents>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateReadMessagesContents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadMessagesContents");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    if (var0 & 1) { s.store_field("date", date_); }
    s.store_class_end();
  }
}

updateChannelTooLong::updateChannelTooLong()
  : flags_()
  , channel_id_()
  , pts_()
  , last_msg_id_()
  , last_msg_date_()
{}

updateChannelTooLong::updateChannelTooLong(int32 flags_, int64 channel_id_, int32 pts_, int32 last_msg_id_, int32 last_msg_date_)
  : flags_(flags_)
  , channel_id_(channel_id_)
  , pts_(pts_)
  , last_msg_id_(last_msg_id_)
  , last_msg_date_(last_msg_date_)
{}

const std::int32_t updateChannelTooLong::ID;

object_ptr<Update> updateChannelTooLong::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateChannelTooLong> res = make_tl_object<updateChannelTooLong>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->pts_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->last_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->last_msg_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateChannelTooLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelTooLong");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("channel_id", channel_id_);
    if (var0 & 1) { s.store_field("pts", pts_); }
    if (var0 & 2) { s.store_field("last_msg_id", last_msg_id_); }
    if (var0 & 2) { s.store_field("last_msg_date", last_msg_date_); }
    s.store_class_end();
  }
}

const std::int32_t updateChannel::ID;

object_ptr<Update> updateChannel::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannel>(p);
}

updateChannel::updateChannel(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
{}

void updateChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannel");
    s.store_field("channel_id", channel_id_);
    s.store_class_end();
  }
}

const std::int32_t updateNewChannelMessage::ID;

object_ptr<Update> updateNewChannelMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewChannelMessage>(p);
}

updateNewChannelMessage::updateNewChannelMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateNewChannelMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewChannelMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateReadChannelInbox::updateReadChannelInbox()
  : flags_()
  , folder_id_()
  , channel_id_()
  , max_id_()
  , still_unread_count_()
  , pts_()
{}

const std::int32_t updateReadChannelInbox::ID;

object_ptr<Update> updateReadChannelInbox::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateReadChannelInbox> res = make_tl_object<updateReadChannelInbox>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->folder_id_ = TlFetchInt::parse(p); }
  res->channel_id_ = TlFetchLong::parse(p);
  res->max_id_ = TlFetchInt::parse(p);
  res->still_unread_count_ = TlFetchInt::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateReadChannelInbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadChannelInbox");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("folder_id", folder_id_); }
    s.store_field("channel_id", channel_id_);
    s.store_field("max_id", max_id_);
    s.store_field("still_unread_count", still_unread_count_);
    s.store_field("pts", pts_);
    s.store_class_end();
  }
}

const std::int32_t updateDeleteChannelMessages::ID;

object_ptr<Update> updateDeleteChannelMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateDeleteChannelMessages>(p);
}

updateDeleteChannelMessages::updateDeleteChannelMessages(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateDeleteChannelMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteChannelMessages");
    s.store_field("channel_id", channel_id_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updateChannelMessageViews::ID;

object_ptr<Update> updateChannelMessageViews::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannelMessageViews>(p);
}

updateChannelMessageViews::updateChannelMessageViews(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , id_(TlFetchInt::parse(p))
  , views_(TlFetchInt::parse(p))
{}

void updateChannelMessageViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelMessageViews");
    s.store_field("channel_id", channel_id_);
    s.store_field("id", id_);
    s.store_field("views", views_);
    s.store_class_end();
  }
}

const std::int32_t updateChatParticipantAdmin::ID;

object_ptr<Update> updateChatParticipantAdmin::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatParticipantAdmin>(p);
}

updateChatParticipantAdmin::updateChatParticipantAdmin(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , is_admin_(TlFetchBool::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateChatParticipantAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipantAdmin");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("is_admin", is_admin_);
    s.store_field("version", version_);
    s.store_class_end();
  }
}

const std::int32_t updateNewStickerSet::ID;

object_ptr<Update> updateNewStickerSet::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewStickerSet>(p);
}

updateNewStickerSet::updateNewStickerSet(TlBufferParser &p)
  : stickerset_(TlFetchObject<messages_StickerSet>::parse(p))
{}

void updateNewStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

updateStickerSetsOrder::updateStickerSetsOrder()
  : flags_()
  , masks_()
  , emojis_()
  , order_()
{}

const std::int32_t updateStickerSetsOrder::ID;

object_ptr<Update> updateStickerSetsOrder::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateStickerSetsOrder> res = make_tl_object<updateStickerSetsOrder>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->masks_ = (var0 & 1) != 0;
  res->emojis_ = (var0 & 2) != 0;
  res->order_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateStickerSetsOrder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStickerSetsOrder");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 1)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 2) { s.store_field("emojis", true); }
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateStickerSets::updateStickerSets()
  : flags_()
  , masks_()
  , emojis_()
{}

const std::int32_t updateStickerSets::ID;

object_ptr<Update> updateStickerSets::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateStickerSets> res = make_tl_object<updateStickerSets>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->masks_ = (var0 & 1) != 0;
  res->emojis_ = (var0 & 2) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStickerSets");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 1)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 2) { s.store_field("emojis", true); }
    s.store_class_end();
  }
}

const std::int32_t updateSavedGifs::ID;

object_ptr<Update> updateSavedGifs::fetch(TlBufferParser &p) {
  return make_tl_object<updateSavedGifs>();
}

void updateSavedGifs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedGifs");
    s.store_class_end();
  }
}

updateBotInlineQuery::updateBotInlineQuery()
  : flags_()
  , query_id_()
  , user_id_()
  , query_()
  , geo_()
  , peer_type_()
  , offset_()
{}

const std::int32_t updateBotInlineQuery::ID;

object_ptr<Update> updateBotInlineQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotInlineQuery> res = make_tl_object<updateBotInlineQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->query_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->geo_ = TlFetchObject<GeoPoint>::parse(p); }
  if (var0 & 2) { res->peer_type_ = TlFetchObject<InlineQueryPeerType>::parse(p); }
  res->offset_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotInlineQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotInlineQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((geo_ != nullptr) << 0) | ((peer_type_ != nullptr) << 1)));
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_field("query", query_);
    if (var0 & 1) { s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get())); }
    if (var0 & 2) { s.store_object_field("peer_type", static_cast<const BaseObject *>(peer_type_.get())); }
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

updateBotInlineSend::updateBotInlineSend()
  : flags_()
  , user_id_()
  , query_()
  , geo_()
  , id_()
  , msg_id_()
{}

const std::int32_t updateBotInlineSend::ID;

object_ptr<Update> updateBotInlineSend::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotInlineSend> res = make_tl_object<updateBotInlineSend>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  res->query_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->geo_ = TlFetchObject<GeoPoint>::parse(p); }
  res->id_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->msg_id_ = TlFetchObject<InputBotInlineMessageID>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotInlineSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotInlineSend");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((geo_ != nullptr) << 0) | ((msg_id_ != nullptr) << 1)));
    s.store_field("user_id", user_id_);
    s.store_field("query", query_);
    if (var0 & 1) { s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get())); }
    s.store_field("id", id_);
    if (var0 & 2) { s.store_object_field("msg_id", static_cast<const BaseObject *>(msg_id_.get())); }
    s.store_class_end();
  }
}

updateEditChannelMessage::updateEditChannelMessage(object_ptr<Message> &&message_, int32 pts_, int32 pts_count_)
  : message_(std::move(message_))
  , pts_(pts_)
  , pts_count_(pts_count_)
{}

const std::int32_t updateEditChannelMessage::ID;

object_ptr<Update> updateEditChannelMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateEditChannelMessage>(p);
}

updateEditChannelMessage::updateEditChannelMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateEditChannelMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEditChannelMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateBotCallbackQuery::updateBotCallbackQuery()
  : flags_()
  , query_id_()
  , user_id_()
  , peer_()
  , msg_id_()
  , chat_instance_()
  , data_()
  , game_short_name_()
{}

const std::int32_t updateBotCallbackQuery::ID;

object_ptr<Update> updateBotCallbackQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotCallbackQuery> res = make_tl_object<updateBotCallbackQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->msg_id_ = TlFetchInt::parse(p);
  res->chat_instance_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->data_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 2) { res->game_short_name_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotCallbackQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!data_.empty()) << 0) | ((!game_short_name_.empty()) << 1)));
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("chat_instance", chat_instance_);
    if (var0 & 1) { s.store_bytes_field("data", data_); }
    if (var0 & 2) { s.store_field("game_short_name", game_short_name_); }
    s.store_class_end();
  }
}

const std::int32_t updateEditMessage::ID;

object_ptr<Update> updateEditMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateEditMessage>(p);
}

updateEditMessage::updateEditMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateEditMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEditMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateInlineBotCallbackQuery::updateInlineBotCallbackQuery()
  : flags_()
  , query_id_()
  , user_id_()
  , msg_id_()
  , chat_instance_()
  , data_()
  , game_short_name_()
{}

const std::int32_t updateInlineBotCallbackQuery::ID;

object_ptr<Update> updateInlineBotCallbackQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateInlineBotCallbackQuery> res = make_tl_object<updateInlineBotCallbackQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->msg_id_ = TlFetchObject<InputBotInlineMessageID>::parse(p);
  res->chat_instance_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->data_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 2) { res->game_short_name_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateInlineBotCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateInlineBotCallbackQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!data_.empty()) << 0) | ((!game_short_name_.empty()) << 1)));
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_object_field("msg_id", static_cast<const BaseObject *>(msg_id_.get()));
    s.store_field("chat_instance", chat_instance_);
    if (var0 & 1) { s.store_bytes_field("data", data_); }
    if (var0 & 2) { s.store_field("game_short_name", game_short_name_); }
    s.store_class_end();
  }
}

const std::int32_t updateReadChannelOutbox::ID;

object_ptr<Update> updateReadChannelOutbox::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadChannelOutbox>(p);
}

updateReadChannelOutbox::updateReadChannelOutbox(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , max_id_(TlFetchInt::parse(p))
{}

void updateReadChannelOutbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadChannelOutbox");
    s.store_field("channel_id", channel_id_);
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

updateDraftMessage::updateDraftMessage()
  : flags_()
  , peer_()
  , top_msg_id_()
  , saved_peer_id_()
  , draft_()
{}

const std::int32_t updateDraftMessage::ID;

object_ptr<Update> updateDraftMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateDraftMessage> res = make_tl_object<updateDraftMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  res->draft_ = TlFetchObject<DraftMessage>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateDraftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDraftMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_object_field("draft", static_cast<const BaseObject *>(draft_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateReadFeaturedStickers::ID;

object_ptr<Update> updateReadFeaturedStickers::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadFeaturedStickers>();
}

void updateReadFeaturedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadFeaturedStickers");
    s.store_class_end();
  }
}

const std::int32_t updateRecentStickers::ID;

object_ptr<Update> updateRecentStickers::fetch(TlBufferParser &p) {
  return make_tl_object<updateRecentStickers>();
}

void updateRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateRecentStickers");
    s.store_class_end();
  }
}

const std::int32_t updateConfig::ID;

object_ptr<Update> updateConfig::fetch(TlBufferParser &p) {
  return make_tl_object<updateConfig>();
}

void updateConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateConfig");
    s.store_class_end();
  }
}

const std::int32_t updatePtsChanged::ID;

object_ptr<Update> updatePtsChanged::fetch(TlBufferParser &p) {
  return make_tl_object<updatePtsChanged>();
}

void updatePtsChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePtsChanged");
    s.store_class_end();
  }
}

const std::int32_t updateChannelWebPage::ID;

object_ptr<Update> updateChannelWebPage::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannelWebPage>(p);
}

updateChannelWebPage::updateChannelWebPage(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , webpage_(TlFetchObject<WebPage>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateChannelWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelWebPage");
    s.store_field("channel_id", channel_id_);
    s.store_object_field("webpage", static_cast<const BaseObject *>(webpage_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateDialogPinned::updateDialogPinned()
  : flags_()
  , pinned_()
  , folder_id_()
  , peer_()
{}

const std::int32_t updateDialogPinned::ID;

object_ptr<Update> updateDialogPinned::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateDialogPinned> res = make_tl_object<updateDialogPinned>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 1) != 0;
  if (var0 & 2) { res->folder_id_ = TlFetchInt::parse(p); }
  res->peer_ = TlFetchObject<DialogPeer>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateDialogPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDialogPinned");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    if (var0 & 2) { s.store_field("folder_id", folder_id_); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

updatePinnedDialogs::updatePinnedDialogs()
  : flags_()
  , folder_id_()
  , order_()
{}

const std::int32_t updatePinnedDialogs::ID;

object_ptr<Update> updatePinnedDialogs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedDialogs> res = make_tl_object<updatePinnedDialogs>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 2) { res->folder_id_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->order_ = TlFetchBoxed<TlFetchVector<TlFetchObject<DialogPeer>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedDialogs");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!order_.empty()) << 0)));
    if (var0 & 2) { s.store_field("folder_id", folder_id_); }
    if (var0 & 1) { { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t updateBotWebhookJSON::ID;

object_ptr<Update> updateBotWebhookJSON::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotWebhookJSON>(p);
}

updateBotWebhookJSON::updateBotWebhookJSON(TlBufferParser &p)
  : data_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void updateBotWebhookJSON::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotWebhookJSON");
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateBotWebhookJSONQuery::ID;

object_ptr<Update> updateBotWebhookJSONQuery::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotWebhookJSONQuery>(p);
}

updateBotWebhookJSONQuery::updateBotWebhookJSONQuery(TlBufferParser &p)
  : query_id_(TlFetchLong::parse(p))
  , data_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
  , timeout_(TlFetchInt::parse(p))
{}

void updateBotWebhookJSONQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotWebhookJSONQuery");
    s.store_field("query_id", query_id_);
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_field("timeout", timeout_);
    s.store_class_end();
  }
}

const std::int32_t updateBotShippingQuery::ID;

object_ptr<Update> updateBotShippingQuery::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotShippingQuery>(p);
}

updateBotShippingQuery::updateBotShippingQuery(TlBufferParser &p)
  : query_id_(TlFetchLong::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , payload_(TlFetchBytes<bytes>::parse(p))
  , shipping_address_(TlFetchBoxed<TlFetchObject<postAddress>, 512535275>::parse(p))
{}

void updateBotShippingQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotShippingQuery");
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_bytes_field("payload", payload_);
    s.store_object_field("shipping_address", static_cast<const BaseObject *>(shipping_address_.get()));
    s.store_class_end();
  }
}

updateBotPrecheckoutQuery::updateBotPrecheckoutQuery()
  : flags_()
  , query_id_()
  , user_id_()
  , payload_()
  , info_()
  , shipping_option_id_()
  , currency_()
  , total_amount_()
{}

const std::int32_t updateBotPrecheckoutQuery::ID;

object_ptr<Update> updateBotPrecheckoutQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotPrecheckoutQuery> res = make_tl_object<updateBotPrecheckoutQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->payload_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 1) { res->info_ = TlFetchBoxed<TlFetchObject<paymentRequestedInfo>, -1868808300>::parse(p); }
  if (var0 & 2) { res->shipping_option_id_ = TlFetchString<string>::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotPrecheckoutQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotPrecheckoutQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((info_ != nullptr) << 0) | ((!shipping_option_id_.empty()) << 1)));
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_bytes_field("payload", payload_);
    if (var0 & 1) { s.store_object_field("info", static_cast<const BaseObject *>(info_.get())); }
    if (var0 & 2) { s.store_field("shipping_option_id", shipping_option_id_); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_class_end();
  }
}

const std::int32_t updatePhoneCall::ID;

object_ptr<Update> updatePhoneCall::fetch(TlBufferParser &p) {
  return make_tl_object<updatePhoneCall>(p);
}

updatePhoneCall::updatePhoneCall(TlBufferParser &p)
  : phone_call_(TlFetchObject<PhoneCall>::parse(p))
{}

void updatePhoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePhoneCall");
    s.store_object_field("phone_call", static_cast<const BaseObject *>(phone_call_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateLangPackTooLong::ID;

object_ptr<Update> updateLangPackTooLong::fetch(TlBufferParser &p) {
  return make_tl_object<updateLangPackTooLong>(p);
}

updateLangPackTooLong::updateLangPackTooLong(TlBufferParser &p)
  : lang_code_(TlFetchString<string>::parse(p))
{}

void updateLangPackTooLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateLangPackTooLong");
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

const std::int32_t updateLangPack::ID;

object_ptr<Update> updateLangPack::fetch(TlBufferParser &p) {
  return make_tl_object<updateLangPack>(p);
}

updateLangPack::updateLangPack(TlBufferParser &p)
  : difference_(TlFetchBoxed<TlFetchObject<langPackDifference>, -209337866>::parse(p))
{}

void updateLangPack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateLangPack");
    s.store_object_field("difference", static_cast<const BaseObject *>(difference_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateFavedStickers::ID;

object_ptr<Update> updateFavedStickers::fetch(TlBufferParser &p) {
  return make_tl_object<updateFavedStickers>();
}

void updateFavedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFavedStickers");
    s.store_class_end();
  }
}

updateChannelReadMessagesContents::updateChannelReadMessagesContents()
  : flags_()
  , channel_id_()
  , top_msg_id_()
  , saved_peer_id_()
  , messages_()
{}

const std::int32_t updateChannelReadMessagesContents::ID;

object_ptr<Update> updateChannelReadMessagesContents::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateChannelReadMessagesContents> res = make_tl_object<updateChannelReadMessagesContents>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateChannelReadMessagesContents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelReadMessagesContents");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)));
    s.store_field("channel_id", channel_id_);
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateContactsReset::ID;

object_ptr<Update> updateContactsReset::fetch(TlBufferParser &p) {
  return make_tl_object<updateContactsReset>();
}

void updateContactsReset::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateContactsReset");
    s.store_class_end();
  }
}

const std::int32_t updateChannelAvailableMessages::ID;

object_ptr<Update> updateChannelAvailableMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannelAvailableMessages>(p);
}

updateChannelAvailableMessages::updateChannelAvailableMessages(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , available_min_id_(TlFetchInt::parse(p))
{}

void updateChannelAvailableMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelAvailableMessages");
    s.store_field("channel_id", channel_id_);
    s.store_field("available_min_id", available_min_id_);
    s.store_class_end();
  }
}

updateDialogUnreadMark::updateDialogUnreadMark()
  : flags_()
  , unread_()
  , peer_()
  , saved_peer_id_()
{}

const std::int32_t updateDialogUnreadMark::ID;

object_ptr<Update> updateDialogUnreadMark::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateDialogUnreadMark> res = make_tl_object<updateDialogUnreadMark>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->unread_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<DialogPeer>::parse(p);
  if (var0 & 2) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateDialogUnreadMark::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDialogUnreadMark");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (unread_ << 0) | ((saved_peer_id_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("unread", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_class_end();
  }
}

updateMessagePoll::updateMessagePoll()
  : flags_()
  , peer_()
  , msg_id_()
  , top_msg_id_()
  , poll_id_()
  , poll_()
  , results_()
{}

const std::int32_t updateMessagePoll::ID;

object_ptr<Update> updateMessagePoll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateMessagePoll> res = make_tl_object<updateMessagePoll>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 2) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2) { res->msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->top_msg_id_ = TlFetchInt::parse(p); }
  res->poll_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->poll_ = TlFetchBoxed<TlFetchObject<poll>, -1771164225>::parse(p); }
  res->results_ = TlFetchBoxed<TlFetchObject<pollResults>, -1166298786>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateMessagePoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessagePoll");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((peer_ != nullptr) << 1) | ((poll_ != nullptr) << 0)));
    if (var0 & 2) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 2) { s.store_field("msg_id", msg_id_); }
    if (var0 & 4) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_field("poll_id", poll_id_);
    if (var0 & 1) { s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get())); }
    s.store_object_field("results", static_cast<const BaseObject *>(results_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateChatDefaultBannedRights::ID;

object_ptr<Update> updateChatDefaultBannedRights::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatDefaultBannedRights>(p);
}

updateChatDefaultBannedRights::updateChatDefaultBannedRights(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , default_banned_rights_(TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateChatDefaultBannedRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatDefaultBannedRights");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("default_banned_rights", static_cast<const BaseObject *>(default_banned_rights_.get()));
    s.store_field("version", version_);
    s.store_class_end();
  }
}

const std::int32_t updateFolderPeers::ID;

object_ptr<Update> updateFolderPeers::fetch(TlBufferParser &p) {
  return make_tl_object<updateFolderPeers>(p);
}

updateFolderPeers::updateFolderPeers(TlBufferParser &p)
  : folder_peers_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<folderPeer>, -373643672>>, 481674261>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateFolderPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFolderPeers");
    { s.store_vector_begin("folder_peers", folder_peers_.size()); for (const auto &_value : folder_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updatePeerSettings::ID;

object_ptr<Update> updatePeerSettings::fetch(TlBufferParser &p) {
  return make_tl_object<updatePeerSettings>(p);
}

updatePeerSettings::updatePeerSettings(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , settings_(TlFetchBoxed<TlFetchObject<peerSettings>, 608290891>::parse(p))
{}

void updatePeerSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePeerSettings");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

const std::int32_t updatePeerLocated::ID;

object_ptr<Update> updatePeerLocated::fetch(TlBufferParser &p) {
  return make_tl_object<updatePeerLocated>(p);
}

updatePeerLocated::updatePeerLocated(TlBufferParser &p)
  : peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<PeerLocated>>, 481674261>::parse(p))
{}

void updatePeerLocated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePeerLocated");
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateNewScheduledMessage::ID;

object_ptr<Update> updateNewScheduledMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewScheduledMessage>(p);
}

updateNewScheduledMessage::updateNewScheduledMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void updateNewScheduledMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewScheduledMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateDeleteScheduledMessages::updateDeleteScheduledMessages()
  : flags_()
  , peer_()
  , messages_()
  , sent_messages_()
{}

const std::int32_t updateDeleteScheduledMessages::ID;

object_ptr<Update> updateDeleteScheduledMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateDeleteScheduledMessages> res = make_tl_object<updateDeleteScheduledMessages>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  if (var0 & 1) { res->sent_messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateDeleteScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteScheduledMessages");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!sent_messages_.empty()) << 0)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 1) { { s.store_vector_begin("sent_messages", sent_messages_.size()); for (const auto &_value : sent_messages_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t updateTheme::ID;

object_ptr<Update> updateTheme::fetch(TlBufferParser &p) {
  return make_tl_object<updateTheme>(p);
}

updateTheme::updateTheme(TlBufferParser &p)
  : theme_(TlFetchBoxed<TlFetchObject<theme>, -1609668650>::parse(p))
{}

void updateTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTheme");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateGeoLiveViewed::ID;

object_ptr<Update> updateGeoLiveViewed::fetch(TlBufferParser &p) {
  return make_tl_object<updateGeoLiveViewed>(p);
}

updateGeoLiveViewed::updateGeoLiveViewed(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
{}

void updateGeoLiveViewed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGeoLiveViewed");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

const std::int32_t updateLoginToken::ID;

object_ptr<Update> updateLoginToken::fetch(TlBufferParser &p) {
  return make_tl_object<updateLoginToken>();
}

void updateLoginToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateLoginToken");
    s.store_class_end();
  }
}

const std::int32_t updateMessagePollVote::ID;

object_ptr<Update> updateMessagePollVote::fetch(TlBufferParser &p) {
  return make_tl_object<updateMessagePollVote>(p);
}

updateMessagePollVote::updateMessagePollVote(TlBufferParser &p)
  : poll_id_(TlFetchLong::parse(p))
  , peer_(TlFetchObject<Peer>::parse(p))
  , options_(TlFetchBoxed<TlFetchVector<TlFetchBytes<bytes>>, 481674261>::parse(p))
  , positions_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateMessagePollVote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessagePollVote");
    s.store_field("poll_id", poll_id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateDialogFilter::updateDialogFilter()
  : flags_()
  , id_()
  , filter_()
{}

const std::int32_t updateDialogFilter::ID;

object_ptr<Update> updateDialogFilter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateDialogFilter> res = make_tl_object<updateDialogFilter>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->filter_ = TlFetchObject<DialogFilter>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateDialogFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDialogFilter");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((filter_ != nullptr) << 0)));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get())); }
    s.store_class_end();
  }
}

const std::int32_t updateDialogFilterOrder::ID;

object_ptr<Update> updateDialogFilterOrder::fetch(TlBufferParser &p) {
  return make_tl_object<updateDialogFilterOrder>(p);
}

updateDialogFilterOrder::updateDialogFilterOrder(TlBufferParser &p)
  : order_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void updateDialogFilterOrder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDialogFilterOrder");
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateDialogFilters::ID;

object_ptr<Update> updateDialogFilters::fetch(TlBufferParser &p) {
  return make_tl_object<updateDialogFilters>();
}

void updateDialogFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDialogFilters");
    s.store_class_end();
  }
}

const std::int32_t updatePhoneCallSignalingData::ID;

object_ptr<Update> updatePhoneCallSignalingData::fetch(TlBufferParser &p) {
  return make_tl_object<updatePhoneCallSignalingData>(p);
}

updatePhoneCallSignalingData::updatePhoneCallSignalingData(TlBufferParser &p)
  : phone_call_id_(TlFetchLong::parse(p))
  , data_(TlFetchBytes<bytes>::parse(p))
{}

void updatePhoneCallSignalingData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePhoneCallSignalingData");
    s.store_field("phone_call_id", phone_call_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

const std::int32_t updateChannelMessageForwards::ID;

object_ptr<Update> updateChannelMessageForwards::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannelMessageForwards>(p);
}

updateChannelMessageForwards::updateChannelMessageForwards(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , id_(TlFetchInt::parse(p))
  , forwards_(TlFetchInt::parse(p))
{}

void updateChannelMessageForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelMessageForwards");
    s.store_field("channel_id", channel_id_);
    s.store_field("id", id_);
    s.store_field("forwards", forwards_);
    s.store_class_end();
  }
}

updateReadChannelDiscussionInbox::updateReadChannelDiscussionInbox()
  : flags_()
  , channel_id_()
  , top_msg_id_()
  , read_max_id_()
  , broadcast_id_()
  , broadcast_post_()
{}

const std::int32_t updateReadChannelDiscussionInbox::ID;

object_ptr<Update> updateReadChannelDiscussionInbox::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateReadChannelDiscussionInbox> res = make_tl_object<updateReadChannelDiscussionInbox>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_id_ = TlFetchLong::parse(p);
  res->top_msg_id_ = TlFetchInt::parse(p);
  res->read_max_id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->broadcast_id_ = TlFetchLong::parse(p); }
  if (var0 & 1) { res->broadcast_post_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateReadChannelDiscussionInbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadChannelDiscussionInbox");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("channel_id", channel_id_);
    s.store_field("top_msg_id", top_msg_id_);
    s.store_field("read_max_id", read_max_id_);
    if (var0 & 1) { s.store_field("broadcast_id", broadcast_id_); }
    if (var0 & 1) { s.store_field("broadcast_post", broadcast_post_); }
    s.store_class_end();
  }
}

const std::int32_t updateReadChannelDiscussionOutbox::ID;

object_ptr<Update> updateReadChannelDiscussionOutbox::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadChannelDiscussionOutbox>(p);
}

updateReadChannelDiscussionOutbox::updateReadChannelDiscussionOutbox(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , top_msg_id_(TlFetchInt::parse(p))
  , read_max_id_(TlFetchInt::parse(p))
{}

void updateReadChannelDiscussionOutbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadChannelDiscussionOutbox");
    s.store_field("channel_id", channel_id_);
    s.store_field("top_msg_id", top_msg_id_);
    s.store_field("read_max_id", read_max_id_);
    s.store_class_end();
  }
}

updatePeerBlocked::updatePeerBlocked()
  : flags_()
  , blocked_()
  , blocked_my_stories_from_()
  , peer_id_()
{}

const std::int32_t updatePeerBlocked::ID;

object_ptr<Update> updatePeerBlocked::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePeerBlocked> res = make_tl_object<updatePeerBlocked>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blocked_ = (var0 & 1) != 0;
  res->blocked_my_stories_from_ = (var0 & 2) != 0;
  res->peer_id_ = TlFetchObject<Peer>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePeerBlocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePeerBlocked");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (blocked_ << 0) | (blocked_my_stories_from_ << 1)));
    if (var0 & 1) { s.store_field("blocked", true); }
    if (var0 & 2) { s.store_field("blocked_my_stories_from", true); }
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_class_end();
  }
}

updateChannelUserTyping::updateChannelUserTyping()
  : flags_()
  , channel_id_()
  , top_msg_id_()
  , from_id_()
  , action_()
{}

const std::int32_t updateChannelUserTyping::ID;

object_ptr<Update> updateChannelUserTyping::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateChannelUserTyping> res = make_tl_object<updateChannelUserTyping>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  res->from_id_ = TlFetchObject<Peer>::parse(p);
  res->action_ = TlFetchObject<SendMessageAction>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateChannelUserTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelUserTyping");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("channel_id", channel_id_);
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

updatePinnedMessages::updatePinnedMessages()
  : flags_()
  , pinned_()
  , peer_()
  , messages_()
  , pts_()
  , pts_count_()
{}

const std::int32_t updatePinnedMessages::ID;

object_ptr<Update> updatePinnedMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedMessages> res = make_tl_object<updatePinnedMessages>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedMessages");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updatePinnedChannelMessages::updatePinnedChannelMessages()
  : flags_()
  , pinned_()
  , channel_id_()
  , messages_()
  , pts_()
  , pts_count_()
{}

const std::int32_t updatePinnedChannelMessages::ID;

object_ptr<Update> updatePinnedChannelMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedChannelMessages> res = make_tl_object<updatePinnedChannelMessages>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 1) != 0;
  res->channel_id_ = TlFetchLong::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedChannelMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedChannelMessages");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_field("channel_id", channel_id_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updateChat::ID;

object_ptr<Update> updateChat::fetch(TlBufferParser &p) {
  return make_tl_object<updateChat>(p);
}

updateChat::updateChat(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
{}

void updateChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

const std::int32_t updateGroupCallParticipants::ID;

object_ptr<Update> updateGroupCallParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<updateGroupCallParticipants>(p);
}

updateGroupCallParticipants::updateGroupCallParticipants(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , participants_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>>, 481674261>::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallParticipants");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("version", version_);
    s.store_class_end();
  }
}

updateGroupCall::updateGroupCall()
  : flags_()
  , live_story_()
  , peer_()
  , call_()
{}

const std::int32_t updateGroupCall::ID;

object_ptr<Update> updateGroupCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateGroupCall> res = make_tl_object<updateGroupCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->live_story_ = (var0 & 4) != 0;
  if (var0 & 2) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  res->call_ = TlFetchObject<GroupCall>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (live_story_ << 2) | ((peer_ != nullptr) << 1)));
    if (var0 & 4) { s.store_field("live_story", true); }
    if (var0 & 2) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

updatePeerHistoryTTL::updatePeerHistoryTTL()
  : flags_()
  , peer_()
  , ttl_period_()
{}

const std::int32_t updatePeerHistoryTTL::ID;

object_ptr<Update> updatePeerHistoryTTL::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePeerHistoryTTL> res = make_tl_object<updatePeerHistoryTTL>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePeerHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePeerHistoryTTL");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

updateChatParticipant::updateChatParticipant()
  : flags_()
  , chat_id_()
  , date_()
  , actor_id_()
  , user_id_()
  , prev_participant_()
  , new_participant_()
  , invite_()
  , qts_()
{}

const std::int32_t updateChatParticipant::ID;

object_ptr<Update> updateChatParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateChatParticipant> res = make_tl_object<updateChatParticipant>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->chat_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->actor_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->prev_participant_ = TlFetchObject<ChatParticipant>::parse(p); }
  if (var0 & 2) { res->new_participant_ = TlFetchObject<ChatParticipant>::parse(p); }
  if (var0 & 4) { res->invite_ = TlFetchObject<ExportedChatInvite>::parse(p); }
  res->qts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateChatParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipant");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((prev_participant_ != nullptr) << 0) | ((new_participant_ != nullptr) << 1) | ((invite_ != nullptr) << 2)));
    s.store_field("chat_id", chat_id_);
    s.store_field("date", date_);
    s.store_field("actor_id", actor_id_);
    s.store_field("user_id", user_id_);
    if (var0 & 1) { s.store_object_field("prev_participant", static_cast<const BaseObject *>(prev_participant_.get())); }
    if (var0 & 2) { s.store_object_field("new_participant", static_cast<const BaseObject *>(new_participant_.get())); }
    if (var0 & 4) { s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get())); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateChannelParticipant::updateChannelParticipant()
  : flags_()
  , via_chatlist_()
  , channel_id_()
  , date_()
  , actor_id_()
  , user_id_()
  , prev_participant_()
  , new_participant_()
  , invite_()
  , qts_()
{}

const std::int32_t updateChannelParticipant::ID;

object_ptr<Update> updateChannelParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateChannelParticipant> res = make_tl_object<updateChannelParticipant>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_chatlist_ = (var0 & 8) != 0;
  res->channel_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->actor_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->prev_participant_ = TlFetchObject<ChannelParticipant>::parse(p); }
  if (var0 & 2) { res->new_participant_ = TlFetchObject<ChannelParticipant>::parse(p); }
  if (var0 & 4) { res->invite_ = TlFetchObject<ExportedChatInvite>::parse(p); }
  res->qts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateChannelParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelParticipant");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_chatlist_ << 3) | ((prev_participant_ != nullptr) << 0) | ((new_participant_ != nullptr) << 1) | ((invite_ != nullptr) << 2)));
    if (var0 & 8) { s.store_field("via_chatlist", true); }
    s.store_field("channel_id", channel_id_);
    s.store_field("date", date_);
    s.store_field("actor_id", actor_id_);
    s.store_field("user_id", user_id_);
    if (var0 & 1) { s.store_object_field("prev_participant", static_cast<const BaseObject *>(prev_participant_.get())); }
    if (var0 & 2) { s.store_object_field("new_participant", static_cast<const BaseObject *>(new_participant_.get())); }
    if (var0 & 4) { s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get())); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateBotStopped::ID;

object_ptr<Update> updateBotStopped::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotStopped>(p);
}

updateBotStopped::updateBotStopped(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
  , stopped_(TlFetchBool::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotStopped::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotStopped");
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    s.store_field("stopped", stopped_);
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateGroupCallConnection::updateGroupCallConnection()
  : flags_()
  , presentation_()
  , params_()
{}

const std::int32_t updateGroupCallConnection::ID;

object_ptr<Update> updateGroupCallConnection::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateGroupCallConnection> res = make_tl_object<updateGroupCallConnection>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->presentation_ = (var0 & 1) != 0;
  res->params_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateGroupCallConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallConnection");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (presentation_ << 0)));
    if (var0 & 1) { s.store_field("presentation", true); }
    s.store_object_field("params", static_cast<const BaseObject *>(params_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateBotCommands::ID;

object_ptr<Update> updateBotCommands::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotCommands>(p);
}

updateBotCommands::updateBotCommands(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , bot_id_(TlFetchLong::parse(p))
  , commands_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botCommand>, -1739401518>>, 481674261>::parse(p))
{}

void updateBotCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotCommands");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("bot_id", bot_id_);
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updatePendingJoinRequests::ID;

object_ptr<Update> updatePendingJoinRequests::fetch(TlBufferParser &p) {
  return make_tl_object<updatePendingJoinRequests>(p);
}

updatePendingJoinRequests::updatePendingJoinRequests(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , requests_pending_(TlFetchInt::parse(p))
  , recent_requesters_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void updatePendingJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePendingJoinRequests");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("requests_pending", requests_pending_);
    { s.store_vector_begin("recent_requesters", recent_requesters_.size()); for (const auto &_value : recent_requesters_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateBotChatInviteRequester::updateBotChatInviteRequester()
  : flags_()
  , peer_()
  , date_()
  , user_id_()
  , about_()
  , invite_()
  , qts_()
  , query_id_()
{}

const std::int32_t updateBotChatInviteRequester::ID;

object_ptr<Update> updateBotChatInviteRequester::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotChatInviteRequester> res = make_tl_object<updateBotChatInviteRequester>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->about_ = TlFetchString<string>::parse(p);
  res->invite_ = TlFetchObject<ExportedChatInvite>::parse(p);
  res->qts_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->query_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotChatInviteRequester::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotChatInviteRequester");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("date", date_);
    s.store_field("user_id", user_id_);
    s.store_field("about", about_);
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_field("qts", qts_);
    if (var0 & 1) { s.store_field("query_id", query_id_); }
    s.store_class_end();
  }
}

updateMessageReactions::updateMessageReactions()
  : flags_()
  , peer_()
  , msg_id_()
  , top_msg_id_()
  , saved_peer_id_()
  , reactions_()
{}

const std::int32_t updateMessageReactions::ID;

object_ptr<Update> updateMessageReactions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateMessageReactions> res = make_tl_object<updateMessageReactions>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->msg_id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  res->reactions_ = TlFetchBoxed<TlFetchObject<messageReactions>, 171155211>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageReactions");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_object_field("reactions", static_cast<const BaseObject *>(reactions_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateAttachMenuBots::ID;

object_ptr<Update> updateAttachMenuBots::fetch(TlBufferParser &p) {
  return make_tl_object<updateAttachMenuBots>();
}

void updateAttachMenuBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAttachMenuBots");
    s.store_class_end();
  }
}

const std::int32_t updateWebViewResultSent::ID;

object_ptr<Update> updateWebViewResultSent::fetch(TlBufferParser &p) {
  return make_tl_object<updateWebViewResultSent>(p);
}

updateWebViewResultSent::updateWebViewResultSent(TlBufferParser &p)
  : query_id_(TlFetchLong::parse(p))
{}

void updateWebViewResultSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebViewResultSent");
    s.store_field("query_id", query_id_);
    s.store_class_end();
  }
}

const std::int32_t updateBotMenuButton::ID;

object_ptr<Update> updateBotMenuButton::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotMenuButton>(p);
}

updateBotMenuButton::updateBotMenuButton(TlBufferParser &p)
  : bot_id_(TlFetchLong::parse(p))
  , button_(TlFetchObject<BotMenuButton>::parse(p))
{}

void updateBotMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotMenuButton");
    s.store_field("bot_id", bot_id_);
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateSavedRingtones::ID;

object_ptr<Update> updateSavedRingtones::fetch(TlBufferParser &p) {
  return make_tl_object<updateSavedRingtones>();
}

void updateSavedRingtones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedRingtones");
    s.store_class_end();
  }
}

updateTranscribedAudio::updateTranscribedAudio()
  : flags_()
  , pending_()
  , peer_()
  , msg_id_()
  , transcription_id_()
  , text_()
{}

const std::int32_t updateTranscribedAudio::ID;

object_ptr<Update> updateTranscribedAudio::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateTranscribedAudio> res = make_tl_object<updateTranscribedAudio>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pending_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->msg_id_ = TlFetchInt::parse(p);
  res->transcription_id_ = TlFetchLong::parse(p);
  res->text_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateTranscribedAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTranscribedAudio");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pending_ << 0)));
    if (var0 & 1) { s.store_field("pending", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("transcription_id", transcription_id_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

const std::int32_t updateReadFeaturedEmojiStickers::ID;

object_ptr<Update> updateReadFeaturedEmojiStickers::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadFeaturedEmojiStickers>();
}

void updateReadFeaturedEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadFeaturedEmojiStickers");
    s.store_class_end();
  }
}

const std::int32_t updateUserEmojiStatus::ID;

object_ptr<Update> updateUserEmojiStatus::fetch(TlBufferParser &p) {
  return make_tl_object<updateUserEmojiStatus>(p);
}

updateUserEmojiStatus::updateUserEmojiStatus(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , emoji_status_(TlFetchObject<EmojiStatus>::parse(p))
{}

void updateUserEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserEmojiStatus");
    s.store_field("user_id", user_id_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateRecentEmojiStatuses::ID;

object_ptr<Update> updateRecentEmojiStatuses::fetch(TlBufferParser &p) {
  return make_tl_object<updateRecentEmojiStatuses>();
}

void updateRecentEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateRecentEmojiStatuses");
    s.store_class_end();
  }
}

const std::int32_t updateRecentReactions::ID;

object_ptr<Update> updateRecentReactions::fetch(TlBufferParser &p) {
  return make_tl_object<updateRecentReactions>();
}

void updateRecentReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateRecentReactions");
    s.store_class_end();
  }
}

updateMoveStickerSetToTop::updateMoveStickerSetToTop()
  : flags_()
  , masks_()
  , emojis_()
  , stickerset_()
{}

const std::int32_t updateMoveStickerSetToTop::ID;

object_ptr<Update> updateMoveStickerSetToTop::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateMoveStickerSetToTop> res = make_tl_object<updateMoveStickerSetToTop>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->masks_ = (var0 & 1) != 0;
  res->emojis_ = (var0 & 2) != 0;
  res->stickerset_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateMoveStickerSetToTop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMoveStickerSetToTop");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 1)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 2) { s.store_field("emojis", true); }
    s.store_field("stickerset", stickerset_);
    s.store_class_end();
  }
}

const std::int32_t updateMessageExtendedMedia::ID;

object_ptr<Update> updateMessageExtendedMedia::fetch(TlBufferParser &p) {
  return make_tl_object<updateMessageExtendedMedia>(p);
}

updateMessageExtendedMedia::updateMessageExtendedMedia(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , extended_media_(TlFetchBoxed<TlFetchVector<TlFetchObject<MessageExtendedMedia>>, 481674261>::parse(p))
{}

void updateMessageExtendedMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageExtendedMedia");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    { s.store_vector_begin("extended_media", extended_media_.size()); for (const auto &_value : extended_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateUser::ID;

object_ptr<Update> updateUser::fetch(TlBufferParser &p) {
  return make_tl_object<updateUser>(p);
}

updateUser::updateUser(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
{}

void updateUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

const std::int32_t updateAutoSaveSettings::ID;

object_ptr<Update> updateAutoSaveSettings::fetch(TlBufferParser &p) {
  return make_tl_object<updateAutoSaveSettings>();
}

void updateAutoSaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAutoSaveSettings");
    s.store_class_end();
  }
}

const std::int32_t updateStory::ID;

object_ptr<Update> updateStory::fetch(TlBufferParser &p) {
  return make_tl_object<updateStory>(p);
}

updateStory::updateStory(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , story_(TlFetchObject<StoryItem>::parse(p))
{}

void updateStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateReadStories::ID;

object_ptr<Update> updateReadStories::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadStories>(p);
}

updateReadStories::updateReadStories(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , max_id_(TlFetchInt::parse(p))
{}

void updateReadStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

const std::int32_t updateStoryID::ID;

object_ptr<Update> updateStoryID::fetch(TlBufferParser &p) {
  return make_tl_object<updateStoryID>(p);
}

updateStoryID::updateStoryID(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , random_id_(TlFetchLong::parse(p))
{}

void updateStoryID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryID");
    s.store_field("id", id_);
    s.store_field("random_id", random_id_);
    s.store_class_end();
  }
}

const std::int32_t updateStoriesStealthMode::ID;

object_ptr<Update> updateStoriesStealthMode::fetch(TlBufferParser &p) {
  return make_tl_object<updateStoriesStealthMode>(p);
}

updateStoriesStealthMode::updateStoriesStealthMode(TlBufferParser &p)
  : stealth_mode_(TlFetchBoxed<TlFetchObject<storiesStealthMode>, 1898850301>::parse(p))
{}

void updateStoriesStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoriesStealthMode");
    s.store_object_field("stealth_mode", static_cast<const BaseObject *>(stealth_mode_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateSentStoryReaction::ID;

object_ptr<Update> updateSentStoryReaction::fetch(TlBufferParser &p) {
  return make_tl_object<updateSentStoryReaction>(p);
}

updateSentStoryReaction::updateSentStoryReaction(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , story_id_(TlFetchInt::parse(p))
  , reaction_(TlFetchObject<Reaction>::parse(p))
{}

void updateSentStoryReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSentStoryReaction");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("story_id", story_id_);
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateBotChatBoost::ID;

object_ptr<Update> updateBotChatBoost::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotChatBoost>(p);
}

updateBotChatBoost::updateBotChatBoost(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , boost_(TlFetchBoxed<TlFetchObject<boost>, 1262359766>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotChatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotChatBoost");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("boost", static_cast<const BaseObject *>(boost_.get()));
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateChannelViewForumAsMessages::ID;

object_ptr<Update> updateChannelViewForumAsMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannelViewForumAsMessages>(p);
}

updateChannelViewForumAsMessages::updateChannelViewForumAsMessages(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , enabled_(TlFetchBool::parse(p))
{}

void updateChannelViewForumAsMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelViewForumAsMessages");
    s.store_field("channel_id", channel_id_);
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

updatePeerWallpaper::updatePeerWallpaper()
  : flags_()
  , wallpaper_overridden_()
  , peer_()
  , wallpaper_()
{}

const std::int32_t updatePeerWallpaper::ID;

object_ptr<Update> updatePeerWallpaper::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePeerWallpaper> res = make_tl_object<updatePeerWallpaper>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->wallpaper_overridden_ = (var0 & 2) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->wallpaper_ = TlFetchObject<WallPaper>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePeerWallpaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePeerWallpaper");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (wallpaper_overridden_ << 1) | ((wallpaper_ != nullptr) << 0)));
    if (var0 & 2) { s.store_field("wallpaper_overridden", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    s.store_class_end();
  }
}

const std::int32_t updateBotMessageReaction::ID;

object_ptr<Update> updateBotMessageReaction::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotMessageReaction>(p);
}

updateBotMessageReaction::updateBotMessageReaction(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , actor_(TlFetchObject<Peer>::parse(p))
  , old_reactions_(TlFetchBoxed<TlFetchVector<TlFetchObject<Reaction>>, 481674261>::parse(p))
  , new_reactions_(TlFetchBoxed<TlFetchVector<TlFetchObject<Reaction>>, 481674261>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotMessageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotMessageReaction");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("date", date_);
    s.store_object_field("actor", static_cast<const BaseObject *>(actor_.get()));
    { s.store_vector_begin("old_reactions", old_reactions_.size()); for (const auto &_value : old_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("new_reactions", new_reactions_.size()); for (const auto &_value : new_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateBotMessageReactions::ID;

object_ptr<Update> updateBotMessageReactions::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotMessageReactions>(p);
}

updateBotMessageReactions::updateBotMessageReactions(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , reactions_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<reactionCount>, -1546531968>>, 481674261>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotMessageReactions");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("date", date_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateSavedDialogPinned::updateSavedDialogPinned()
  : flags_()
  , pinned_()
  , peer_()
{}

const std::int32_t updateSavedDialogPinned::ID;

object_ptr<Update> updateSavedDialogPinned::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateSavedDialogPinned> res = make_tl_object<updateSavedDialogPinned>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<DialogPeer>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateSavedDialogPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedDialogPinned");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

updatePinnedSavedDialogs::updatePinnedSavedDialogs()
  : flags_()
  , order_()
{}

const std::int32_t updatePinnedSavedDialogs::ID;

object_ptr<Update> updatePinnedSavedDialogs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedSavedDialogs> res = make_tl_object<updatePinnedSavedDialogs>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->order_ = TlFetchBoxed<TlFetchVector<TlFetchObject<DialogPeer>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedSavedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedSavedDialogs");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!order_.empty()) << 0)));
    if (var0 & 1) { { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t updateSavedReactionTags::ID;

object_ptr<Update> updateSavedReactionTags::fetch(TlBufferParser &p) {
  return make_tl_object<updateSavedReactionTags>();
}

void updateSavedReactionTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedReactionTags");
    s.store_class_end();
  }
}

const std::int32_t updateSmsJob::ID;

object_ptr<Update> updateSmsJob::fetch(TlBufferParser &p) {
  return make_tl_object<updateSmsJob>(p);
}

updateSmsJob::updateSmsJob(TlBufferParser &p)
  : job_id_(TlFetchString<string>::parse(p))
{}

void updateSmsJob::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSmsJob");
    s.store_field("job_id", job_id_);
    s.store_class_end();
  }
}

const std::int32_t updateQuickReplies::ID;

object_ptr<Update> updateQuickReplies::fetch(TlBufferParser &p) {
  return make_tl_object<updateQuickReplies>(p);
}

updateQuickReplies::updateQuickReplies(TlBufferParser &p)
  : quick_replies_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<quickReply>, 110563371>>, 481674261>::parse(p))
{}

void updateQuickReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplies");
    { s.store_vector_begin("quick_replies", quick_replies_.size()); for (const auto &_value : quick_replies_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateNewQuickReply::ID;

object_ptr<Update> updateNewQuickReply::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewQuickReply>(p);
}

updateNewQuickReply::updateNewQuickReply(TlBufferParser &p)
  : quick_reply_(TlFetchBoxed<TlFetchObject<quickReply>, 110563371>::parse(p))
{}

void updateNewQuickReply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewQuickReply");
    s.store_object_field("quick_reply", static_cast<const BaseObject *>(quick_reply_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateDeleteQuickReply::ID;

object_ptr<Update> updateDeleteQuickReply::fetch(TlBufferParser &p) {
  return make_tl_object<updateDeleteQuickReply>(p);
}

updateDeleteQuickReply::updateDeleteQuickReply(TlBufferParser &p)
  : shortcut_id_(TlFetchInt::parse(p))
{}

void updateDeleteQuickReply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteQuickReply");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

const std::int32_t updateQuickReplyMessage::ID;

object_ptr<Update> updateQuickReplyMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateQuickReplyMessage>(p);
}

updateQuickReplyMessage::updateQuickReplyMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void updateQuickReplyMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplyMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateDeleteQuickReplyMessages::ID;

object_ptr<Update> updateDeleteQuickReplyMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateDeleteQuickReplyMessages>(p);
}

updateDeleteQuickReplyMessages::updateDeleteQuickReplyMessages(TlBufferParser &p)
  : shortcut_id_(TlFetchInt::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void updateDeleteQuickReplyMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteQuickReplyMessages");
    s.store_field("shortcut_id", shortcut_id_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateBotBusinessConnect::ID;

object_ptr<Update> updateBotBusinessConnect::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotBusinessConnect>(p);
}

updateBotBusinessConnect::updateBotBusinessConnect(TlBufferParser &p)
  : connection_(TlFetchBoxed<TlFetchObject<botBusinessConnection>, -1892371723>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotBusinessConnect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotBusinessConnect");
    s.store_object_field("connection", static_cast<const BaseObject *>(connection_.get()));
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateBotNewBusinessMessage::updateBotNewBusinessMessage()
  : flags_()
  , connection_id_()
  , message_()
  , reply_to_message_()
  , qts_()
{}

const std::int32_t updateBotNewBusinessMessage::ID;

object_ptr<Update> updateBotNewBusinessMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotNewBusinessMessage> res = make_tl_object<updateBotNewBusinessMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->connection_id_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchObject<Message>::parse(p);
  if (var0 & 1) { res->reply_to_message_ = TlFetchObject<Message>::parse(p); }
  res->qts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotNewBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotNewBusinessMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_to_message_ != nullptr) << 0)));
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    if (var0 & 1) { s.store_object_field("reply_to_message", static_cast<const BaseObject *>(reply_to_message_.get())); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateBotEditBusinessMessage::updateBotEditBusinessMessage()
  : flags_()
  , connection_id_()
  , message_()
  , reply_to_message_()
  , qts_()
{}

const std::int32_t updateBotEditBusinessMessage::ID;

object_ptr<Update> updateBotEditBusinessMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotEditBusinessMessage> res = make_tl_object<updateBotEditBusinessMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->connection_id_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchObject<Message>::parse(p);
  if (var0 & 1) { res->reply_to_message_ = TlFetchObject<Message>::parse(p); }
  res->qts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotEditBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotEditBusinessMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_to_message_ != nullptr) << 0)));
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    if (var0 & 1) { s.store_object_field("reply_to_message", static_cast<const BaseObject *>(reply_to_message_.get())); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateBotDeleteBusinessMessage::ID;

object_ptr<Update> updateBotDeleteBusinessMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotDeleteBusinessMessage>(p);
}

updateBotDeleteBusinessMessage::updateBotDeleteBusinessMessage(TlBufferParser &p)
  : connection_id_(TlFetchString<string>::parse(p))
  , peer_(TlFetchObject<Peer>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotDeleteBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotDeleteBusinessMessage");
    s.store_field("connection_id", connection_id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateNewStoryReaction::ID;

object_ptr<Update> updateNewStoryReaction::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewStoryReaction>(p);
}

updateNewStoryReaction::updateNewStoryReaction(TlBufferParser &p)
  : story_id_(TlFetchInt::parse(p))
  , peer_(TlFetchObject<Peer>::parse(p))
  , reaction_(TlFetchObject<Reaction>::parse(p))
{}

void updateNewStoryReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewStoryReaction");
    s.store_field("story_id", story_id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateStarsBalance::ID;

object_ptr<Update> updateStarsBalance::fetch(TlBufferParser &p) {
  return make_tl_object<updateStarsBalance>(p);
}

updateStarsBalance::updateStarsBalance(TlBufferParser &p)
  : balance_(TlFetchObject<StarsAmount>::parse(p))
{}

void updateStarsBalance::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarsBalance");
    s.store_object_field("balance", static_cast<const BaseObject *>(balance_.get()));
    s.store_class_end();
  }
}

updateBusinessBotCallbackQuery::updateBusinessBotCallbackQuery()
  : flags_()
  , query_id_()
  , user_id_()
  , connection_id_()
  , message_()
  , reply_to_message_()
  , chat_instance_()
  , data_()
{}

const std::int32_t updateBusinessBotCallbackQuery::ID;

object_ptr<Update> updateBusinessBotCallbackQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBusinessBotCallbackQuery> res = make_tl_object<updateBusinessBotCallbackQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->connection_id_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchObject<Message>::parse(p);
  if (var0 & 4) { res->reply_to_message_ = TlFetchObject<Message>::parse(p); }
  res->chat_instance_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->data_ = TlFetchBytes<bytes>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBusinessBotCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBusinessBotCallbackQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_to_message_ != nullptr) << 2) | ((!data_.empty()) << 0)));
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    if (var0 & 4) { s.store_object_field("reply_to_message", static_cast<const BaseObject *>(reply_to_message_.get())); }
    s.store_field("chat_instance", chat_instance_);
    if (var0 & 1) { s.store_bytes_field("data", data_); }
    s.store_class_end();
  }
}

const std::int32_t updateStarsRevenueStatus::ID;

object_ptr<Update> updateStarsRevenueStatus::fetch(TlBufferParser &p) {
  return make_tl_object<updateStarsRevenueStatus>(p);
}

updateStarsRevenueStatus::updateStarsRevenueStatus(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , status_(TlFetchBoxed<TlFetchObject<starsRevenueStatus>, -21080943>::parse(p))
{}

void updateStarsRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarsRevenueStatus");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateBotPurchasedPaidMedia::ID;

object_ptr<Update> updateBotPurchasedPaidMedia::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotPurchasedPaidMedia>(p);
}

updateBotPurchasedPaidMedia::updateBotPurchasedPaidMedia(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , payload_(TlFetchString<string>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotPurchasedPaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotPurchasedPaidMedia");
    s.store_field("user_id", user_id_);
    s.store_field("payload", payload_);
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updatePaidReactionPrivacy::ID;

object_ptr<Update> updatePaidReactionPrivacy::fetch(TlBufferParser &p) {
  return make_tl_object<updatePaidReactionPrivacy>(p);
}

updatePaidReactionPrivacy::updatePaidReactionPrivacy(TlBufferParser &p)
  : private_(TlFetchObject<PaidReactionPrivacy>::parse(p))
{}

void updatePaidReactionPrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePaidReactionPrivacy");
    s.store_object_field("private", static_cast<const BaseObject *>(private_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateSentPhoneCode::ID;

object_ptr<Update> updateSentPhoneCode::fetch(TlBufferParser &p) {
  return make_tl_object<updateSentPhoneCode>(p);
}

updateSentPhoneCode::updateSentPhoneCode(TlBufferParser &p)
  : sent_code_(TlFetchObject<auth_SentCode>::parse(p))
{}

void updateSentPhoneCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSentPhoneCode");
    s.store_object_field("sent_code", static_cast<const BaseObject *>(sent_code_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateGroupCallChainBlocks::ID;

object_ptr<Update> updateGroupCallChainBlocks::fetch(TlBufferParser &p) {
  return make_tl_object<updateGroupCallChainBlocks>(p);
}

updateGroupCallChainBlocks::updateGroupCallChainBlocks(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , sub_chain_id_(TlFetchInt::parse(p))
  , blocks_(TlFetchBoxed<TlFetchVector<TlFetchBytes<bytes>>, 481674261>::parse(p))
  , next_offset_(TlFetchInt::parse(p))
{}

void updateGroupCallChainBlocks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallChainBlocks");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("sub_chain_id", sub_chain_id_);
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

const std::int32_t updateReadMonoForumInbox::ID;

object_ptr<Update> updateReadMonoForumInbox::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadMonoForumInbox>(p);
}

updateReadMonoForumInbox::updateReadMonoForumInbox(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , saved_peer_id_(TlFetchObject<Peer>::parse(p))
  , read_max_id_(TlFetchInt::parse(p))
{}

void updateReadMonoForumInbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadMonoForumInbox");
    s.store_field("channel_id", channel_id_);
    s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get()));
    s.store_field("read_max_id", read_max_id_);
    s.store_class_end();
  }
}

const std::int32_t updateReadMonoForumOutbox::ID;

object_ptr<Update> updateReadMonoForumOutbox::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadMonoForumOutbox>(p);
}

updateReadMonoForumOutbox::updateReadMonoForumOutbox(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , saved_peer_id_(TlFetchObject<Peer>::parse(p))
  , read_max_id_(TlFetchInt::parse(p))
{}

void updateReadMonoForumOutbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadMonoForumOutbox");
    s.store_field("channel_id", channel_id_);
    s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get()));
    s.store_field("read_max_id", read_max_id_);
    s.store_class_end();
  }
}

updateMonoForumNoPaidException::updateMonoForumNoPaidException()
  : flags_()
  , exception_()
  , channel_id_()
  , saved_peer_id_()
{}

const std::int32_t updateMonoForumNoPaidException::ID;

object_ptr<Update> updateMonoForumNoPaidException::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateMonoForumNoPaidException> res = make_tl_object<updateMonoForumNoPaidException>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->exception_ = (var0 & 1) != 0;
  res->channel_id_ = TlFetchLong::parse(p);
  res->saved_peer_id_ = TlFetchObject<Peer>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateMonoForumNoPaidException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMonoForumNoPaidException");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (exception_ << 0)));
    if (var0 & 1) { s.store_field("exception", true); }
    s.store_field("channel_id", channel_id_);
    s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateGroupCallMessage::ID;

object_ptr<Update> updateGroupCallMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateGroupCallMessage>(p);
}

updateGroupCallMessage::updateGroupCallMessage(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , message_(TlFetchBoxed<TlFetchObject<groupCallMessage>, 445316222>::parse(p))
{}

void updateGroupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallMessage");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateGroupCallEncryptedMessage::ID;

object_ptr<Update> updateGroupCallEncryptedMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateGroupCallEncryptedMessage>(p);
}

updateGroupCallEncryptedMessage::updateGroupCallEncryptedMessage(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , from_id_(TlFetchObject<Peer>::parse(p))
  , encrypted_message_(TlFetchBytes<bytes>::parse(p))
{}

void updateGroupCallEncryptedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallEncryptedMessage");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_bytes_field("encrypted_message", encrypted_message_);
    s.store_class_end();
  }
}

updatePinnedForumTopic::updatePinnedForumTopic()
  : flags_()
  , pinned_()
  , peer_()
  , topic_id_()
{}

const std::int32_t updatePinnedForumTopic::ID;

object_ptr<Update> updatePinnedForumTopic::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedForumTopic> res = make_tl_object<updatePinnedForumTopic>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->topic_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedForumTopic");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

updatePinnedForumTopics::updatePinnedForumTopics()
  : flags_()
  , peer_()
  , order_()
{}

const std::int32_t updatePinnedForumTopics::ID;

object_ptr<Update> updatePinnedForumTopics::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedForumTopics> res = make_tl_object<updatePinnedForumTopics>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->order_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedForumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedForumTopics");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!order_.empty()) << 0)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t updateDeleteGroupCallMessages::ID;

object_ptr<Update> updateDeleteGroupCallMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateDeleteGroupCallMessages>(p);
}

updateDeleteGroupCallMessages::updateDeleteGroupCallMessages(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void updateDeleteGroupCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteGroupCallMessages");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateStarGiftAuctionState::ID;

object_ptr<Update> updateStarGiftAuctionState::fetch(TlBufferParser &p) {
  return make_tl_object<updateStarGiftAuctionState>(p);
}

updateStarGiftAuctionState::updateStarGiftAuctionState(TlBufferParser &p)
  : gift_id_(TlFetchLong::parse(p))
  , state_(TlFetchObject<StarGiftAuctionState>::parse(p))
{}

void updateStarGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarGiftAuctionState");
    s.store_field("gift_id", gift_id_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateStarGiftAuctionUserState::ID;

object_ptr<Update> updateStarGiftAuctionUserState::fetch(TlBufferParser &p) {
  return make_tl_object<updateStarGiftAuctionUserState>(p);
}

updateStarGiftAuctionUserState::updateStarGiftAuctionUserState(TlBufferParser &p)
  : gift_id_(TlFetchLong::parse(p))
  , user_state_(TlFetchBoxed<TlFetchObject<starGiftAuctionUserState>, 787403204>::parse(p))
{}

void updateStarGiftAuctionUserState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarGiftAuctionUserState");
    s.store_field("gift_id", gift_id_);
    s.store_object_field("user_state", static_cast<const BaseObject *>(user_state_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateEmojiGameInfo::ID;

object_ptr<Update> updateEmojiGameInfo::fetch(TlBufferParser &p) {
  return make_tl_object<updateEmojiGameInfo>(p);
}

updateEmojiGameInfo::updateEmojiGameInfo(TlBufferParser &p)
  : info_(TlFetchObject<messages_EmojiGameInfo>::parse(p))
{}

void updateEmojiGameInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEmojiGameInfo");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateStarGiftCraftFail::ID;

object_ptr<Update> updateStarGiftCraftFail::fetch(TlBufferParser &p) {
  return make_tl_object<updateStarGiftCraftFail>();
}

void updateStarGiftCraftFail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarGiftCraftFail");
    s.store_class_end();
  }
}

const std::int32_t updateChatParticipantRank::ID;

object_ptr<Update> updateChatParticipantRank::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatParticipantRank>(p);
}

updateChatParticipantRank::updateChatParticipantRank(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , rank_(TlFetchString<string>::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateChatParticipantRank::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipantRank");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("rank", rank_);
    s.store_field("version", version_);
    s.store_class_end();
  }
}

const std::int32_t updateManagedBot::ID;

object_ptr<Update> updateManagedBot::fetch(TlBufferParser &p) {
  return make_tl_object<updateManagedBot>(p);
}

updateManagedBot::updateManagedBot(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , bot_id_(TlFetchLong::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateManagedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateManagedBot");
    s.store_field("user_id", user_id_);
    s.store_field("bot_id", bot_id_);
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateBotGuestChatQuery::updateBotGuestChatQuery()
  : flags_()
  , query_id_()
  , message_()
  , reference_messages_()
  , qts_()
{}

const std::int32_t updateBotGuestChatQuery::ID;

object_ptr<Update> updateBotGuestChatQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotGuestChatQuery> res = make_tl_object<updateBotGuestChatQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->message_ = TlFetchObject<Message>::parse(p);
  if (var0 & 1) { res->reference_messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p); }
  res->qts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotGuestChatQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotGuestChatQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!reference_messages_.empty()) << 0)));
    s.store_field("query_id", query_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    if (var0 & 1) { { s.store_vector_begin("reference_messages", reference_messages_.size()); for (const auto &_value : reference_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateAiComposeTones::ID;

object_ptr<Update> updateAiComposeTones::fetch(TlBufferParser &p) {
  return make_tl_object<updateAiComposeTones>();
}

void updateAiComposeTones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAiComposeTones");
    s.store_class_end();
  }
}

const std::int32_t updateJoinChatWebViewDecision::ID;

object_ptr<Update> updateJoinChatWebViewDecision::fetch(TlBufferParser &p) {
  return make_tl_object<updateJoinChatWebViewDecision>(p);
}

updateJoinChatWebViewDecision::updateJoinChatWebViewDecision(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , query_id_(TlFetchLong::parse(p))
  , result_(TlFetchObject<JoinChatBotResult>::parse(p))
{}

void updateJoinChatWebViewDecision::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateJoinChatWebViewDecision");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("query_id", query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_class_end();
  }
}

updateNewBotConnection::updateNewBotConnection()
  : flags_()
  , confirmed_()
  , bot_id_()
  , date_()
  , device_()
  , location_()
{}

const std::int32_t updateNewBotConnection::ID;

object_ptr<Update> updateNewBotConnection::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateNewBotConnection> res = make_tl_object<updateNewBotConnection>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->confirmed_ = (var0 & 1) != 0;
  res->bot_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->date_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->device_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->location_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateNewBotConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewBotConnection");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (confirmed_ << 0) | ((!device_.empty()) << 1) | ((!location_.empty()) << 1)));
    if (var0 & 1) { s.store_field("confirmed", true); }
    s.store_field("bot_id", bot_id_);
    if (var0 & 2) { s.store_field("date", date_); }
    if (var0 & 2) { s.store_field("device", device_); }
    if (var0 & 2) { s.store_field("location", location_); }
    s.store_class_end();
  }
}

updateWebBrowserSettings::updateWebBrowserSettings()
  : flags_()
  , open_external_browser_()
  , display_close_button_()
{}

const std::int32_t updateWebBrowserSettings::ID;

object_ptr<Update> updateWebBrowserSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateWebBrowserSettings> res = make_tl_object<updateWebBrowserSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->open_external_browser_ = (var0 & 1) != 0;
  res->display_close_button_ = (var0 & 2) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateWebBrowserSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebBrowserSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (open_external_browser_ << 0) | (display_close_button_ << 1)));
    if (var0 & 1) { s.store_field("open_external_browser", true); }
    if (var0 & 2) { s.store_field("display_close_button", true); }
    s.store_class_end();
  }
}

updateWebBrowserException::updateWebBrowserException()
  : flags_()
  , delete_()
  , open_external_browser_()
  , exception_()
{}

const std::int32_t updateWebBrowserException::ID;

object_ptr<Update> updateWebBrowserException::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateWebBrowserException> res = make_tl_object<updateWebBrowserException>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->delete_ = (var0 & 2) != 0;
  if (var0 & 1) { res->open_external_browser_ = TlFetchBool::parse(p); }
  res->exception_ = TlFetchBoxed<TlFetchObject<webDomainException>, -1824741993>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateWebBrowserException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebBrowserException");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (delete_ << 1)));
    if (var0 & 2) { s.store_field("delete", true); }
    if (var0 & 1) { s.store_field("open_external_browser", open_external_browser_); }
    s.store_object_field("exception", static_cast<const BaseObject *>(exception_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateNewEphemeralMessage::ID;

object_ptr<Update> updateNewEphemeralMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewEphemeralMessage>(p);
}

updateNewEphemeralMessage::updateNewEphemeralMessage(TlBufferParser &p)
  : message_(TlFetchBoxed<TlFetchObject<ephemeralMessage>, -584597783>::parse(p))
{}

void updateNewEphemeralMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewEphemeralMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateDeleteEphemeralMessages::ID;

object_ptr<Update> updateDeleteEphemeralMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateDeleteEphemeralMessages>(p);
}

updateDeleteEphemeralMessages::updateDeleteEphemeralMessages(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , ids_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void updateDeleteEphemeralMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteEphemeralMessages");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("ids", ids_.size()); for (const auto &_value : ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateEditEphemeralMessage::ID;

object_ptr<Update> updateEditEphemeralMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateEditEphemeralMessage>(p);
}

updateEditEphemeralMessage::updateEditEphemeralMessage(TlBufferParser &p)
  : message_(TlFetchBoxed<TlFetchObject<ephemeralMessage>, -584597783>::parse(p))
{}

void updateEditEphemeralMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEditEphemeralMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateEphemeralBotCallbackQuery::updateEphemeralBotCallbackQuery()
  : flags_()
  , query_id_()
  , user_id_()
  , peer_()
  , msg_id_()
  , data_()
  , chat_instance_()
  , message_()
{}

const std::int32_t updateEphemeralBotCallbackQuery::ID;

object_ptr<Update> updateEphemeralBotCallbackQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateEphemeralBotCallbackQuery> res = make_tl_object<updateEphemeralBotCallbackQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  res->msg_id_ = TlFetchInt::parse(p);
  res->data_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 2) { res->chat_instance_ = TlFetchLong::parse(p); }
  res->message_ = TlFetchBoxed<TlFetchObject<ephemeralMessage>, -584597783>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateEphemeralBotCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEphemeralBotCallbackQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((peer_ != nullptr) << 0)));
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_field("msg_id", msg_id_);
    s.store_bytes_field("data", data_);
    if (var0 & 2) { s.store_field("chat_instance", chat_instance_); }
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateBotStarsSubscription::updateBotStarsSubscription()
  : flags_()
  , canceled_()
  , payment_failed_()
  , restored_()
  , user_id_()
  , payload_()
  , qts_()
{}

const std::int32_t updateBotStarsSubscription::ID;

object_ptr<Update> updateBotStarsSubscription::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotStarsSubscription> res = make_tl_object<updateBotStarsSubscription>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->canceled_ = (var0 & 1) != 0;
  res->payment_failed_ = (var0 & 2) != 0;
  res->restored_ = (var0 & 4) != 0;
  res->user_id_ = TlFetchLong::parse(p);
  res->payload_ = TlFetchBytes<bytes>::parse(p);
  res->qts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotStarsSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotStarsSubscription");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (canceled_ << 0) | (payment_failed_ << 1) | (restored_ << 2)));
    if (var0 & 1) { s.store_field("canceled", true); }
    if (var0 & 2) { s.store_field("payment_failed", true); }
    if (var0 & 4) { s.store_field("restored", true); }
    s.store_field("user_id", user_id_);
    s.store_bytes_field("payload", payload_);
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateWalletState::ID;

object_ptr<Update> updateWalletState::fetch(TlBufferParser &p) {
  return make_tl_object<updateWalletState>(p);
}

updateWalletState::updateWalletState(TlBufferParser &p)
  : state_(TlFetchObject<WalletState>::parse(p))
{}

void updateWalletState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWalletState");
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

updateSentWalletTransaction::updateSentWalletTransaction()
  : flags_()
  , gasless_()
  , msg_hash_()
  , transaction_()
{}

const std::int32_t updateSentWalletTransaction::ID;

object_ptr<Update> updateSentWalletTransaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateSentWalletTransaction> res = make_tl_object<updateSentWalletTransaction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->gasless_ = (var0 & 1) != 0;
  res->msg_hash_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->transaction_ = TlFetchBoxed<TlFetchObject<walletTransaction>, -1792163517>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateSentWalletTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSentWalletTransaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (gasless_ << 0) | ((transaction_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("gasless", true); }
    s.store_field("msg_hash", msg_hash_);
    if (var0 & 2) { s.store_object_field("transaction", static_cast<const BaseObject *>(transaction_.get())); }
    s.store_class_end();
  }
}

updateWalletGaslessInfo::updateWalletGaslessInfo()
  : flags_()
  , available_()
  , left_()
  , reset_at_()
  , min_amount_()
  , relayer_address_()
{}

const std::int32_t updateWalletGaslessInfo::ID;

object_ptr<Update> updateWalletGaslessInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateWalletGaslessInfo> res = make_tl_object<updateWalletGaslessInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->available_ = (var0 & 1) != 0;
  res->left_ = TlFetchInt::parse(p);
  res->reset_at_ = TlFetchInt::parse(p);
  res->min_amount_ = TlFetchLong::parse(p);
  res->relayer_address_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateWalletGaslessInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWalletGaslessInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (available_ << 0)));
    if (var0 & 1) { s.store_field("available", true); }
    s.store_field("left", left_);
    s.store_field("reset_at", reset_at_);
    s.store_field("min_amount", min_amount_);
    s.store_field("relayer_address", relayer_address_);
    s.store_class_end();
  }
}

const std::int32_t updateWalletTonConnectSession::ID;

object_ptr<Update> updateWalletTonConnectSession::fetch(TlBufferParser &p) {
  return make_tl_object<updateWalletTonConnectSession>(p);
}

updateWalletTonConnectSession::updateWalletTonConnectSession(TlBufferParser &p)
  : session_(TlFetchBoxed<TlFetchObject<tonConnectSession>, 308631238>::parse(p))
{}

void updateWalletTonConnectSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWalletTonConnectSession");
    s.store_object_field("session", static_cast<const BaseObject *>(session_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateWalletTonConnectPendingDisconnect::ID;

object_ptr<Update> updateWalletTonConnectPendingDisconnect::fetch(TlBufferParser &p) {
  return make_tl_object<updateWalletTonConnectPendingDisconnect>(p);
}

updateWalletTonConnectPendingDisconnect::updateWalletTonConnectPendingDisconnect(TlBufferParser &p)
  : session_ids_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void updateWalletTonConnectPendingDisconnect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWalletTonConnectPendingDisconnect");
    { s.store_vector_begin("session_ids", session_ids_.size()); for (const auto &_value : session_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateEditForumTopic::updateEditForumTopic()
  : flags_()
  , peer_()
  , topic_id_()
  , title_()
  , icon_emoji_id_()
  , closed_()
  , hidden_()
{}

const std::int32_t updateEditForumTopic::ID;

object_ptr<Update> updateEditForumTopic::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateEditForumTopic> res = make_tl_object<updateEditForumTopic>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->topic_id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->icon_emoji_id_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->closed_ = TlFetchBool::parse(p); }
  if (var0 & 8) { res->hidden_ = TlFetchBool::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateEditForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEditForumTopic");
  int32 var0;
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

updateBotWidgetQuery::updateBotWidgetQuery()
  : flags_()
  , query_id_()
  , query_type_()
  , user_id_()
  , peer_()
  , msg_id_()
  , chat_instance_()
  , chat_type_()
  , data_()
  , widget_id_()
  , wallet_card_()
{}

const std::int32_t updateBotWidgetQuery::ID;

object_ptr<Update> updateBotWidgetQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotWidgetQuery> res = make_tl_object<updateBotWidgetQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->query_type_ = TlFetchObject<WidgetQueryType>::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->msg_id_ = TlFetchInt::parse(p);
  res->chat_instance_ = TlFetchLong::parse(p);
  res->chat_type_ = TlFetchString<string>::parse(p);
  res->data_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 1) { res->widget_id_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->wallet_card_ = TlFetchBoxed<TlFetchObject<wallet_card>, -1898953807>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotWidgetQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotWidgetQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((wallet_card_ != nullptr) << 1)));
    s.store_field("query_id", query_id_);
    s.store_object_field("query_type", static_cast<const BaseObject *>(query_type_.get()));
    s.store_field("user_id", user_id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("chat_instance", chat_instance_);
    s.store_field("chat_type", chat_type_);
    s.store_bytes_field("data", data_);
    if (var0 & 1) { s.store_field("widget_id", widget_id_); }
    if (var0 & 2) { s.store_object_field("wallet_card", static_cast<const BaseObject *>(wallet_card_.get())); }
    s.store_class_end();
  }
}

updateInlineBotWidgetQuery::updateInlineBotWidgetQuery()
  : flags_()
  , query_id_()
  , query_type_()
  , user_id_()
  , inline_message_id_()
  , chat_instance_()
  , chat_type_()
  , data_()
  , widget_id_()
  , wallet_card_()
{}

const std::int32_t updateInlineBotWidgetQuery::ID;

object_ptr<Update> updateInlineBotWidgetQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateInlineBotWidgetQuery> res = make_tl_object<updateInlineBotWidgetQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->query_type_ = TlFetchObject<WidgetQueryType>::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->inline_message_id_ = TlFetchObject<InputBotInlineMessageID>::parse(p);
  res->chat_instance_ = TlFetchLong::parse(p);
  res->chat_type_ = TlFetchString<string>::parse(p);
  res->data_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 1) { res->widget_id_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->wallet_card_ = TlFetchBoxed<TlFetchObject<wallet_card>, -1898953807>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateInlineBotWidgetQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateInlineBotWidgetQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((wallet_card_ != nullptr) << 1)));
    s.store_field("query_id", query_id_);
    s.store_object_field("query_type", static_cast<const BaseObject *>(query_type_.get()));
    s.store_field("user_id", user_id_);
    s.store_object_field("inline_message_id", static_cast<const BaseObject *>(inline_message_id_.get()));
    s.store_field("chat_instance", chat_instance_);
    s.store_field("chat_type", chat_type_);
    s.store_bytes_field("data", data_);
    if (var0 & 1) { s.store_field("widget_id", widget_id_); }
    if (var0 & 2) { s.store_object_field("wallet_card", static_cast<const BaseObject *>(wallet_card_.get())); }
    s.store_class_end();
  }
}

updateBotWidgetCopyQuery::updateBotWidgetCopyQuery()
  : flags_()
  , query_id_()
  , query_type_()
  , user_id_()
  , data_()
  , widget_id_()
  , wallet_card_()
{}

const std::int32_t updateBotWidgetCopyQuery::ID;

object_ptr<Update> updateBotWidgetCopyQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotWidgetCopyQuery> res = make_tl_object<updateBotWidgetCopyQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->query_type_ = TlFetchObject<WidgetQueryType>::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->data_ = TlFetchBytes<bytes>::parse(p);
  res->widget_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->wallet_card_ = TlFetchBoxed<TlFetchObject<wallet_card>, -1898953807>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotWidgetCopyQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotWidgetCopyQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((wallet_card_ != nullptr) << 1)));
    s.store_field("query_id", query_id_);
    s.store_object_field("query_type", static_cast<const BaseObject *>(query_type_.get()));
    s.store_field("user_id", user_id_);
    s.store_bytes_field("data", data_);
    s.store_field("widget_id", widget_id_);
    if (var0 & 2) { s.store_object_field("wallet_card", static_cast<const BaseObject *>(wallet_card_.get())); }
    s.store_class_end();
  }
}

updateMessageWidgetData::updateMessageWidgetData()
  : flags_()
  , peer_()
  , msg_id_()
  , public_data_()
  , public_data_hash_()
  , chat_data_()
  , pts_()
  , pts_count_()
{}

const std::int32_t updateMessageWidgetData::ID;

object_ptr<Update> updateMessageWidgetData::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateMessageWidgetData> res = make_tl_object<updateMessageWidgetData>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->msg_id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->public_data_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->public_data_hash_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->chat_data_ = TlFetchString<string>::parse(p); }
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateMessageWidgetData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageWidgetData");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!public_data_.empty()) << 0) | ((!chat_data_.empty()) << 1)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    if (var0 & 1) { s.store_field("public_data", public_data_); }
    if (var0 & 1) { s.store_field("public_data_hash", public_data_hash_); }
    if (var0 & 2) { s.store_field("chat_data", chat_data_); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateTranscribedAudioFile::updateTranscribedAudioFile()
  : flags_()
  , pending_()
  , transcription_id_()
  , text_()
{}

const std::int32_t updateTranscribedAudioFile::ID;

object_ptr<Update> updateTranscribedAudioFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateTranscribedAudioFile> res = make_tl_object<updateTranscribedAudioFile>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pending_ = (var0 & 1) != 0;
  res->transcription_id_ = TlFetchLong::parse(p);
  res->text_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateTranscribedAudioFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTranscribedAudioFile");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pending_ << 0)));
    if (var0 & 1) { s.store_field("pending", true); }
    s.store_field("transcription_id", transcription_id_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

object_ptr<Updates> Updates::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case updatesTooLong::ID:
      return updatesTooLong::fetch(p);
    case updateShortMessage::ID:
      return updateShortMessage::fetch(p);
    case updateShortChatMessage::ID:
      return updateShortChatMessage::fetch(p);
    case updateShort::ID:
      return updateShort::fetch(p);
    case updatesCombined::ID:
      return updatesCombined::fetch(p);
    case updates::ID:
      return updates::fetch(p);
    case updateShortSentMessage::ID:
      return updateShortSentMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t updatesTooLong::ID;

object_ptr<Updates> updatesTooLong::fetch(TlBufferParser &p) {
  return make_tl_object<updatesTooLong>();
}

void updatesTooLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatesTooLong");
    s.store_class_end();
  }
}

updateShortMessage::updateShortMessage()
  : flags_()
  , out_()
  , mentioned_()
  , media_unread_()
  , silent_()
  , id_()
  , user_id_()
  , message_()
  , pts_()
  , pts_count_()
  , date_()
  , fwd_from_()
  , via_bot_id_()
  , reply_to_()
  , entities_()
  , ttl_period_()
{}

const std::int32_t updateShortMessage::ID;

object_ptr<Updates> updateShortMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateShortMessage> res = make_tl_object<updateShortMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->out_ = (var0 & 2) != 0;
  res->mentioned_ = (var0 & 16) != 0;
  res->media_unread_ = (var0 & 32) != 0;
  res->silent_ = (var0 & 8192) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->fwd_from_ = TlFetchBoxed<TlFetchObject<messageFwdHeader>, 1313731771>::parse(p); }
  if (var0 & 2048) { res->via_bot_id_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->reply_to_ = TlFetchObject<MessageReplyHeader>::parse(p); }
  if (var0 & 128) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 33554432) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateShortMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateShortMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (out_ << 1) | (mentioned_ << 4) | (media_unread_ << 5) | (silent_ << 13) | ((fwd_from_ != nullptr) << 2) | ((reply_to_ != nullptr) << 3) | ((!entities_.empty()) << 7)));
    if (var0 & 2) { s.store_field("out", true); }
    if (var0 & 16) { s.store_field("mentioned", true); }
    if (var0 & 32) { s.store_field("media_unread", true); }
    if (var0 & 8192) { s.store_field("silent", true); }
    s.store_field("id", id_);
    s.store_field("user_id", user_id_);
    s.store_field("message", message_);
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_field("date", date_);
    if (var0 & 4) { s.store_object_field("fwd_from", static_cast<const BaseObject *>(fwd_from_.get())); }
    if (var0 & 2048) { s.store_field("via_bot_id", via_bot_id_); }
    if (var0 & 8) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    if (var0 & 128) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 33554432) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

updateShortChatMessage::updateShortChatMessage()
  : flags_()
  , out_()
  , mentioned_()
  , media_unread_()
  , silent_()
  , id_()
  , from_id_()
  , chat_id_()
  , message_()
  , pts_()
  , pts_count_()
  , date_()
  , fwd_from_()
  , via_bot_id_()
  , reply_to_()
  , entities_()
  , ttl_period_()
{}

const std::int32_t updateShortChatMessage::ID;

object_ptr<Updates> updateShortChatMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateShortChatMessage> res = make_tl_object<updateShortChatMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->out_ = (var0 & 2) != 0;
  res->mentioned_ = (var0 & 16) != 0;
  res->media_unread_ = (var0 & 32) != 0;
  res->silent_ = (var0 & 8192) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->from_id_ = TlFetchLong::parse(p);
  res->chat_id_ = TlFetchLong::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->fwd_from_ = TlFetchBoxed<TlFetchObject<messageFwdHeader>, 1313731771>::parse(p); }
  if (var0 & 2048) { res->via_bot_id_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->reply_to_ = TlFetchObject<MessageReplyHeader>::parse(p); }
  if (var0 & 128) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 33554432) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateShortChatMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateShortChatMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (out_ << 1) | (mentioned_ << 4) | (media_unread_ << 5) | (silent_ << 13) | ((fwd_from_ != nullptr) << 2) | ((reply_to_ != nullptr) << 3) | ((!entities_.empty()) << 7)));
    if (var0 & 2) { s.store_field("out", true); }
    if (var0 & 16) { s.store_field("mentioned", true); }
    if (var0 & 32) { s.store_field("media_unread", true); }
    if (var0 & 8192) { s.store_field("silent", true); }
    s.store_field("id", id_);
    s.store_field("from_id", from_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message", message_);
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_field("date", date_);
    if (var0 & 4) { s.store_object_field("fwd_from", static_cast<const BaseObject *>(fwd_from_.get())); }
    if (var0 & 2048) { s.store_field("via_bot_id", via_bot_id_); }
    if (var0 & 8) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    if (var0 & 128) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 33554432) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

const std::int32_t updateShort::ID;

object_ptr<Updates> updateShort::fetch(TlBufferParser &p) {
  return make_tl_object<updateShort>(p);
}

updateShort::updateShort(TlBufferParser &p)
  : update_(TlFetchObject<Update>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void updateShort::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateShort");
    s.store_object_field("update", static_cast<const BaseObject *>(update_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t updatesCombined::ID;

object_ptr<Updates> updatesCombined::fetch(TlBufferParser &p) {
  return make_tl_object<updatesCombined>(p);
}

updatesCombined::updatesCombined(TlBufferParser &p)
  : updates_(TlFetchBoxed<TlFetchVector<TlFetchObject<Update>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , date_(TlFetchInt::parse(p))
  , seq_start_(TlFetchInt::parse(p))
  , seq_(TlFetchInt::parse(p))
{}

void updatesCombined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatesCombined");
    { s.store_vector_begin("updates", updates_.size()); for (const auto &_value : updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("date", date_);
    s.store_field("seq_start", seq_start_);
    s.store_field("seq", seq_);
    s.store_class_end();
  }
}

updates::updates()
  : updates_()
  , users_()
  , chats_()
  , date_()
  , seq_()
{}

const std::int32_t updates::ID;

object_ptr<Updates> updates::fetch(TlBufferParser &p) {
  return make_tl_object<updates>(p);
}

updates::updates(TlBufferParser &p)
  : updates_(TlFetchBoxed<TlFetchVector<TlFetchObject<Update>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , date_(TlFetchInt::parse(p))
  , seq_(TlFetchInt::parse(p))
{}

void updates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates");
    { s.store_vector_begin("updates", updates_.size()); for (const auto &_value : updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("date", date_);
    s.store_field("seq", seq_);
    s.store_class_end();
  }
}

updateShortSentMessage::updateShortSentMessage()
  : flags_()
  , out_()
  , id_()
  , pts_()
  , pts_count_()
  , date_()
  , media_()
  , entities_()
  , ttl_period_()
{}

const std::int32_t updateShortSentMessage::ID;

object_ptr<Updates> updateShortSentMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateShortSentMessage> res = make_tl_object<updateShortSentMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->out_ = (var0 & 2) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 512) { res->media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (var0 & 128) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 33554432) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateShortSentMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateShortSentMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (out_ << 1) | ((media_ != nullptr) << 9) | ((!entities_.empty()) << 7)));
    if (var0 & 2) { s.store_field("out", true); }
    s.store_field("id", id_);
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_field("date", date_);
    if (var0 & 512) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 128) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 33554432) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

userFull::userFull()
  : flags_()
  , blocked_()
  , phone_calls_available_()
  , phone_calls_private_()
  , can_pin_message_()
  , has_scheduled_()
  , video_calls_available_()
  , voice_messages_forbidden_()
  , translations_disabled_()
  , stories_pinned_available_()
  , blocked_my_stories_from_()
  , wallpaper_overridden_()
  , contact_require_premium_()
  , read_dates_private_()
  , flags2_()
  , sponsored_enabled_()
  , can_view_revenue_()
  , bot_can_manage_emoji_status_()
  , display_gifts_button_()
  , noforwards_my_enabled_()
  , noforwards_peer_enabled_()
  , unofficial_security_risk_()
  , id_()
  , about_()
  , settings_()
  , personal_photo_()
  , profile_photo_()
  , fallback_photo_()
  , notify_settings_()
  , bot_info_()
  , pinned_msg_id_()
  , common_chats_count_()
  , folder_id_()
  , ttl_period_()
  , theme_()
  , private_forward_name_()
  , bot_group_admin_rights_()
  , bot_broadcast_admin_rights_()
  , wallpaper_()
  , stories_()
  , business_work_hours_()
  , business_location_()
  , business_greeting_message_()
  , business_away_message_()
  , business_intro_()
  , birthday_()
  , personal_channel_id_()
  , personal_channel_message_()
  , stargifts_count_()
  , starref_program_()
  , bot_verification_()
  , send_paid_messages_stars_()
  , disallowed_gifts_()
  , stars_rating_()
  , stars_my_pending_rating_()
  , stars_my_pending_rating_date_()
  , main_tab_()
  , saved_music_()
  , note_()
  , bot_manager_id_()
  , wallet_card_()
  , share_theme_()
{}

const std::int32_t userFull::ID;

object_ptr<userFull> userFull::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<userFull> res = make_tl_object<userFull>();
  int32 var0;
  int32 var1;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blocked_ = (var0 & 1) != 0;
  res->phone_calls_available_ = (var0 & 16) != 0;
  res->phone_calls_private_ = (var0 & 32) != 0;
  res->can_pin_message_ = (var0 & 128) != 0;
  res->has_scheduled_ = (var0 & 4096) != 0;
  res->video_calls_available_ = (var0 & 8192) != 0;
  res->voice_messages_forbidden_ = (var0 & 1048576) != 0;
  res->translations_disabled_ = (var0 & 8388608) != 0;
  res->stories_pinned_available_ = (var0 & 67108864) != 0;
  res->blocked_my_stories_from_ = (var0 & 134217728) != 0;
  res->wallpaper_overridden_ = (var0 & 268435456) != 0;
  res->contact_require_premium_ = (var0 & 536870912) != 0;
  res->read_dates_private_ = (var0 & 1073741824) != 0;
  if ((var1 = res->flags2_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->sponsored_enabled_ = (var1 & 128) != 0;
  res->can_view_revenue_ = (var1 & 512) != 0;
  res->bot_can_manage_emoji_status_ = (var1 & 1024) != 0;
  res->display_gifts_button_ = (var1 & 65536) != 0;
  res->noforwards_my_enabled_ = (var1 & 8388608) != 0;
  res->noforwards_peer_enabled_ = (var1 & 16777216) != 0;
  res->unofficial_security_risk_ = (var1 & 67108864) != 0;
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->about_ = TlFetchString<string>::parse(p); }
  res->settings_ = TlFetchBoxed<TlFetchObject<peerSettings>, 608290891>::parse(p);
  if (var0 & 2097152) { res->personal_photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 4) { res->profile_photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 4194304) { res->fallback_photo_ = TlFetchObject<Photo>::parse(p); }
  res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
  if (var0 & 8) { res->bot_info_ = TlFetchBoxed<TlFetchObject<botInfo>, 1300890265>::parse(p); }
  if (var0 & 64) { res->pinned_msg_id_ = TlFetchInt::parse(p); }
  res->common_chats_count_ = TlFetchInt::parse(p);
  if (var0 & 2048) { res->folder_id_ = TlFetchInt::parse(p); }
  if (var0 & 16384) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (var0 & 32768) { res->theme_ = TlFetchObject<ChatTheme>::parse(p); }
  if (var0 & 65536) { res->private_forward_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 131072) { res->bot_group_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 262144) { res->bot_broadcast_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 16777216) { res->wallpaper_ = TlFetchObject<WallPaper>::parse(p); }
  if (var0 & 33554432) { res->stories_ = TlFetchBoxed<TlFetchObject<peerStories>, -1707742823>::parse(p); }
  if (var1 & 1) { res->business_work_hours_ = TlFetchBoxed<TlFetchObject<businessWorkHours>, -1936543592>::parse(p); }
  if (var1 & 2) { res->business_location_ = TlFetchBoxed<TlFetchObject<businessLocation>, -1403249929>::parse(p); }
  if (var1 & 4) { res->business_greeting_message_ = TlFetchBoxed<TlFetchObject<businessGreetingMessage>, -451302485>::parse(p); }
  if (var1 & 8) { res->business_away_message_ = TlFetchBoxed<TlFetchObject<businessAwayMessage>, -283809188>::parse(p); }
  if (var1 & 16) { res->business_intro_ = TlFetchBoxed<TlFetchObject<businessIntro>, 1510606445>::parse(p); }
  if (var1 & 32) { res->birthday_ = TlFetchBoxed<TlFetchObject<birthday>, 1821253126>::parse(p); }
  if (var1 & 64) { res->personal_channel_id_ = TlFetchLong::parse(p); }
  if (var1 & 64) { res->personal_channel_message_ = TlFetchInt::parse(p); }
  if (var1 & 256) { res->stargifts_count_ = TlFetchInt::parse(p); }
  if (var1 & 2048) { res->starref_program_ = TlFetchBoxed<TlFetchObject<starRefProgram>, -586389774>::parse(p); }
  if (var1 & 4096) { res->bot_verification_ = TlFetchBoxed<TlFetchObject<botVerification>, -147976487>::parse(p); }
  if (var1 & 16384) { res->send_paid_messages_stars_ = TlFetchLong::parse(p); }
  if (var1 & 32768) { res->disallowed_gifts_ = TlFetchBoxed<TlFetchObject<disallowedGiftsSettings>, 1911715524>::parse(p); }
  if (var1 & 131072) { res->stars_rating_ = TlFetchBoxed<TlFetchObject<starsRating>, 453922567>::parse(p); }
  if (var1 & 262144) { res->stars_my_pending_rating_ = TlFetchBoxed<TlFetchObject<starsRating>, 453922567>::parse(p); }
  if (var1 & 262144) { res->stars_my_pending_rating_date_ = TlFetchInt::parse(p); }
  if (var1 & 1048576) { res->main_tab_ = TlFetchObject<ProfileTab>::parse(p); }
  if (var1 & 2097152) { res->saved_music_ = TlFetchObject<Document>::parse(p); }
  if (var1 & 4194304) { res->note_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (var1 & 33554432) { res->bot_manager_id_ = TlFetchLong::parse(p); }
  if (var1 & 524288) { res->wallet_card_ = TlFetchBoxed<TlFetchObject<wallet_card>, -1898953807>::parse(p); }
  if (var1 & 134217728) { res->share_theme_ = TlFetchObject<ShareTheme>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void userFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userFull");
  int32 var0;
  int32 var1;
    s.store_field("flags", (var0 = flags_ | (blocked_ << 0) | (phone_calls_available_ << 4) | (phone_calls_private_ << 5) | (can_pin_message_ << 7) | (has_scheduled_ << 12) | (video_calls_available_ << 13) | (voice_messages_forbidden_ << 20) | (translations_disabled_ << 23) | (stories_pinned_available_ << 26) | (blocked_my_stories_from_ << 27) | (wallpaper_overridden_ << 28) | (contact_require_premium_ << 29) | (read_dates_private_ << 30) | ((!about_.empty()) << 1) | ((personal_photo_ != nullptr) << 21) | ((profile_photo_ != nullptr) << 2) | ((fallback_photo_ != nullptr) << 22) | ((bot_info_ != nullptr) << 3) | ((theme_ != nullptr) << 15) | ((!private_forward_name_.empty()) << 16) | ((bot_group_admin_rights_ != nullptr) << 17) | ((bot_broadcast_admin_rights_ != nullptr) << 18) | ((wallpaper_ != nullptr) << 24) | ((stories_ != nullptr) << 25)));
    if (var0 & 1) { s.store_field("blocked", true); }
    if (var0 & 16) { s.store_field("phone_calls_available", true); }
    if (var0 & 32) { s.store_field("phone_calls_private", true); }
    if (var0 & 128) { s.store_field("can_pin_message", true); }
    if (var0 & 4096) { s.store_field("has_scheduled", true); }
    if (var0 & 8192) { s.store_field("video_calls_available", true); }
    if (var0 & 1048576) { s.store_field("voice_messages_forbidden", true); }
    if (var0 & 8388608) { s.store_field("translations_disabled", true); }
    if (var0 & 67108864) { s.store_field("stories_pinned_available", true); }
    if (var0 & 134217728) { s.store_field("blocked_my_stories_from", true); }
    if (var0 & 268435456) { s.store_field("wallpaper_overridden", true); }
    if (var0 & 536870912) { s.store_field("contact_require_premium", true); }
    if (var0 & 1073741824) { s.store_field("read_dates_private", true); }
    s.store_field("flags2", (var1 = flags2_ | (sponsored_enabled_ << 7) | (can_view_revenue_ << 9) | (bot_can_manage_emoji_status_ << 10) | (display_gifts_button_ << 16) | (noforwards_my_enabled_ << 23) | (noforwards_peer_enabled_ << 24) | (unofficial_security_risk_ << 26) | ((business_work_hours_ != nullptr) << 0) | ((business_location_ != nullptr) << 1) | ((business_greeting_message_ != nullptr) << 2) | ((business_away_message_ != nullptr) << 3) | ((business_intro_ != nullptr) << 4) | ((birthday_ != nullptr) << 5) | ((starref_program_ != nullptr) << 11) | ((bot_verification_ != nullptr) << 12) | ((disallowed_gifts_ != nullptr) << 15) | ((stars_rating_ != nullptr) << 17) | ((stars_my_pending_rating_ != nullptr) << 18) | ((main_tab_ != nullptr) << 20) | ((saved_music_ != nullptr) << 21) | ((note_ != nullptr) << 22) | ((wallet_card_ != nullptr) << 19) | ((share_theme_ != nullptr) << 27)));
    if (var1 & 128) { s.store_field("sponsored_enabled", true); }
    if (var1 & 512) { s.store_field("can_view_revenue", true); }
    if (var1 & 1024) { s.store_field("bot_can_manage_emoji_status", true); }
    if (var1 & 65536) { s.store_field("display_gifts_button", true); }
    if (var1 & 8388608) { s.store_field("noforwards_my_enabled", true); }
    if (var1 & 16777216) { s.store_field("noforwards_peer_enabled", true); }
    if (var1 & 67108864) { s.store_field("unofficial_security_risk", true); }
    s.store_field("id", id_);
    if (var0 & 2) { s.store_field("about", about_); }
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    if (var0 & 2097152) { s.store_object_field("personal_photo", static_cast<const BaseObject *>(personal_photo_.get())); }
    if (var0 & 4) { s.store_object_field("profile_photo", static_cast<const BaseObject *>(profile_photo_.get())); }
    if (var0 & 4194304) { s.store_object_field("fallback_photo", static_cast<const BaseObject *>(fallback_photo_.get())); }
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    if (var0 & 8) { s.store_object_field("bot_info", static_cast<const BaseObject *>(bot_info_.get())); }
    if (var0 & 64) { s.store_field("pinned_msg_id", pinned_msg_id_); }
    s.store_field("common_chats_count", common_chats_count_);
    if (var0 & 2048) { s.store_field("folder_id", folder_id_); }
    if (var0 & 16384) { s.store_field("ttl_period", ttl_period_); }
    if (var0 & 32768) { s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get())); }
    if (var0 & 65536) { s.store_field("private_forward_name", private_forward_name_); }
    if (var0 & 131072) { s.store_object_field("bot_group_admin_rights", static_cast<const BaseObject *>(bot_group_admin_rights_.get())); }
    if (var0 & 262144) { s.store_object_field("bot_broadcast_admin_rights", static_cast<const BaseObject *>(bot_broadcast_admin_rights_.get())); }
    if (var0 & 16777216) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    if (var0 & 33554432) { s.store_object_field("stories", static_cast<const BaseObject *>(stories_.get())); }
    if (var1 & 1) { s.store_object_field("business_work_hours", static_cast<const BaseObject *>(business_work_hours_.get())); }
    if (var1 & 2) { s.store_object_field("business_location", static_cast<const BaseObject *>(business_location_.get())); }
    if (var1 & 4) { s.store_object_field("business_greeting_message", static_cast<const BaseObject *>(business_greeting_message_.get())); }
    if (var1 & 8) { s.store_object_field("business_away_message", static_cast<const BaseObject *>(business_away_message_.get())); }
    if (var1 & 16) { s.store_object_field("business_intro", static_cast<const BaseObject *>(business_intro_.get())); }
    if (var1 & 32) { s.store_object_field("birthday", static_cast<const BaseObject *>(birthday_.get())); }
    if (var1 & 64) { s.store_field("personal_channel_id", personal_channel_id_); }
    if (var1 & 64) { s.store_field("personal_channel_message", personal_channel_message_); }
    if (var1 & 256) { s.store_field("stargifts_count", stargifts_count_); }
    if (var1 & 2048) { s.store_object_field("starref_program", static_cast<const BaseObject *>(starref_program_.get())); }
    if (var1 & 4096) { s.store_object_field("bot_verification", static_cast<const BaseObject *>(bot_verification_.get())); }
    if (var1 & 16384) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    if (var1 & 32768) { s.store_object_field("disallowed_gifts", static_cast<const BaseObject *>(disallowed_gifts_.get())); }
    if (var1 & 131072) { s.store_object_field("stars_rating", static_cast<const BaseObject *>(stars_rating_.get())); }
    if (var1 & 262144) { s.store_object_field("stars_my_pending_rating", static_cast<const BaseObject *>(stars_my_pending_rating_.get())); }
    if (var1 & 262144) { s.store_field("stars_my_pending_rating_date", stars_my_pending_rating_date_); }
    if (var1 & 1048576) { s.store_object_field("main_tab", static_cast<const BaseObject *>(main_tab_.get())); }
    if (var1 & 2097152) { s.store_object_field("saved_music", static_cast<const BaseObject *>(saved_music_.get())); }
    if (var1 & 4194304) { s.store_object_field("note", static_cast<const BaseObject *>(note_.get())); }
    if (var1 & 33554432) { s.store_field("bot_manager_id", bot_manager_id_); }
    if (var1 & 524288) { s.store_object_field("wallet_card", static_cast<const BaseObject *>(wallet_card_.get())); }
    if (var1 & 134217728) { s.store_object_field("share_theme", static_cast<const BaseObject *>(share_theme_.get())); }
    s.store_class_end();
  }
}

userWallet::userWallet()
  : flags_()
  , address_()
  , balance_()
  , public_key_()
  , state_init_()
{}

userWallet::userWallet(int32 flags_, string const &address_, int64 balance_, bytes &&public_key_, bytes &&state_init_)
  : flags_(flags_)
  , address_(address_)
  , balance_(balance_)
  , public_key_(std::move(public_key_))
  , state_init_(std::move(state_init_))
{}

const std::int32_t userWallet::ID;

object_ptr<userWallet> userWallet::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<userWallet> res = make_tl_object<userWallet>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->address_ = TlFetchString<string>::parse(p);
  res->balance_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->public_key_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 1) { res->state_init_ = TlFetchBytes<bytes>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void userWallet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!public_key_.empty()) << 0) | ((!state_init_.empty()) << 0)), s);
  TlStoreString::store(address_, s);
  TlStoreBinary::store(balance_, s);
  if (var0 & 1) { TlStoreString::store(public_key_, s); }
  if (var0 & 1) { TlStoreString::store(state_init_, s); }
}

void userWallet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!public_key_.empty()) << 0) | ((!state_init_.empty()) << 0)), s);
  TlStoreString::store(address_, s);
  TlStoreBinary::store(balance_, s);
  if (var0 & 1) { TlStoreString::store(public_key_, s); }
  if (var0 & 1) { TlStoreString::store(state_init_, s); }
}

void userWallet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userWallet");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!public_key_.empty()) << 0) | ((!state_init_.empty()) << 0)));
    s.store_field("address", address_);
    s.store_field("balance", balance_);
    if (var0 & 1) { s.store_bytes_field("public_key", public_key_); }
    if (var0 & 1) { s.store_bytes_field("state_init", state_init_); }
    s.store_class_end();
  }
}

const std::int32_t account_authorizations::ID;

object_ptr<account_authorizations> account_authorizations::fetch(TlBufferParser &p) {
  return make_tl_object<account_authorizations>(p);
}

account_authorizations::account_authorizations(TlBufferParser &p)
  : authorization_ttl_days_(TlFetchInt::parse(p))
  , authorizations_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<authorization>, -1392388579>>, 481674261>::parse(p))
{}

void account_authorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.authorizations");
    s.store_field("authorization_ttl_days", authorization_ttl_days_);
    { s.store_vector_begin("authorizations", authorizations_.size()); for (const auto &_value : authorizations_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<account_EmailVerified> account_EmailVerified::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_emailVerified::ID:
      return account_emailVerified::fetch(p);
    case account_emailVerifiedLogin::ID:
      return account_emailVerifiedLogin::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_emailVerified::ID;

object_ptr<account_EmailVerified> account_emailVerified::fetch(TlBufferParser &p) {
  return make_tl_object<account_emailVerified>(p);
}

account_emailVerified::account_emailVerified(TlBufferParser &p)
  : email_(TlFetchString<string>::parse(p))
{}

void account_emailVerified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.emailVerified");
    s.store_field("email", email_);
    s.store_class_end();
  }
}

const std::int32_t account_emailVerifiedLogin::ID;

object_ptr<account_EmailVerified> account_emailVerifiedLogin::fetch(TlBufferParser &p) {
  return make_tl_object<account_emailVerifiedLogin>(p);
}

account_emailVerifiedLogin::account_emailVerifiedLogin(TlBufferParser &p)
  : email_(TlFetchString<string>::parse(p))
  , sent_code_(TlFetchObject<auth_SentCode>::parse(p))
{}

void account_emailVerifiedLogin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.emailVerifiedLogin");
    s.store_field("email", email_);
    s.store_object_field("sent_code", static_cast<const BaseObject *>(sent_code_.get()));
    s.store_class_end();
  }
}

account_passwordSettings::account_passwordSettings()
  : flags_()
  , email_()
  , secure_settings_()
{}

const std::int32_t account_passwordSettings::ID;

object_ptr<account_passwordSettings> account_passwordSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_passwordSettings> res = make_tl_object<account_passwordSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->email_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->secure_settings_ = TlFetchBoxed<TlFetchObject<secureSecretSettings>, 354925740>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void account_passwordSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.passwordSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!email_.empty()) << 0) | ((secure_settings_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("email", email_); }
    if (var0 & 2) { s.store_object_field("secure_settings", static_cast<const BaseObject *>(secure_settings_.get())); }
    s.store_class_end();
  }
}

object_ptr<account_SavedRingtone> account_SavedRingtone::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_savedRingtone::ID:
      return account_savedRingtone::fetch(p);
    case account_savedRingtoneConverted::ID:
      return account_savedRingtoneConverted::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_savedRingtone::ID;

object_ptr<account_SavedRingtone> account_savedRingtone::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedRingtone>();
}

void account_savedRingtone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedRingtone");
    s.store_class_end();
  }
}

const std::int32_t account_savedRingtoneConverted::ID;

object_ptr<account_SavedRingtone> account_savedRingtoneConverted::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedRingtoneConverted>(p);
}

account_savedRingtoneConverted::account_savedRingtoneConverted(TlBufferParser &p)
  : document_(TlFetchObject<Document>::parse(p))
{}

void account_savedRingtoneConverted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedRingtoneConverted");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_class_end();
  }
}

object_ptr<auth_Authorization> auth_Authorization::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case auth_authorization::ID:
      return auth_authorization::fetch(p);
    case auth_authorizationSignUpRequired::ID:
      return auth_authorizationSignUpRequired::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

auth_authorization::auth_authorization()
  : flags_()
  , setup_password_required_()
  , otherwise_relogin_days_()
  , tmp_sessions_()
  , future_auth_token_()
  , user_()
{}

const std::int32_t auth_authorization::ID;

object_ptr<auth_Authorization> auth_authorization::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_authorization> res = make_tl_object<auth_authorization>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->setup_password_required_ = (var0 & 2) != 0;
  if (var0 & 2) { res->otherwise_relogin_days_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->tmp_sessions_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->future_auth_token_ = TlFetchBytes<bytes>::parse(p); }
  res->user_ = TlFetchObject<User>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_authorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.authorization");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (setup_password_required_ << 1) | ((!future_auth_token_.empty()) << 2)));
    if (var0 & 2) { s.store_field("setup_password_required", true); }
    if (var0 & 2) { s.store_field("otherwise_relogin_days", otherwise_relogin_days_); }
    if (var0 & 1) { s.store_field("tmp_sessions", tmp_sessions_); }
    if (var0 & 4) { s.store_field("future_auth_token", "[REDACTED]"); }
    s.store_object_field("user", static_cast<const BaseObject *>(user_.get()));
    s.store_class_end();
  }
}

auth_authorizationSignUpRequired::auth_authorizationSignUpRequired()
  : flags_()
  , terms_of_service_()
{}

const std::int32_t auth_authorizationSignUpRequired::ID;

object_ptr<auth_Authorization> auth_authorizationSignUpRequired::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_authorizationSignUpRequired> res = make_tl_object<auth_authorizationSignUpRequired>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->terms_of_service_ = TlFetchBoxed<TlFetchObject<help_termsOfService>, 2013922064>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_authorizationSignUpRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.authorizationSignUpRequired");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((terms_of_service_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("terms_of_service", static_cast<const BaseObject *>(terms_of_service_.get())); }
    s.store_class_end();
  }
}

object_ptr<auth_CodeType> auth_CodeType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case auth_codeTypeSms::ID:
      return auth_codeTypeSms::fetch(p);
    case auth_codeTypeCall::ID:
      return auth_codeTypeCall::fetch(p);
    case auth_codeTypeFlashCall::ID:
      return auth_codeTypeFlashCall::fetch(p);
    case auth_codeTypeMissedCall::ID:
      return auth_codeTypeMissedCall::fetch(p);
    case auth_codeTypeFragmentSms::ID:
      return auth_codeTypeFragmentSms::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t auth_codeTypeSms::ID;

object_ptr<auth_CodeType> auth_codeTypeSms::fetch(TlBufferParser &p) {
  return make_tl_object<auth_codeTypeSms>();
}

void auth_codeTypeSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.codeTypeSms");
    s.store_class_end();
  }
}

const std::int32_t auth_codeTypeCall::ID;

object_ptr<auth_CodeType> auth_codeTypeCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_codeTypeCall>();
}

void auth_codeTypeCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.codeTypeCall");
    s.store_class_end();
  }
}

const std::int32_t auth_codeTypeFlashCall::ID;

object_ptr<auth_CodeType> auth_codeTypeFlashCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_codeTypeFlashCall>();
}

void auth_codeTypeFlashCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.codeTypeFlashCall");
    s.store_class_end();
  }
}

const std::int32_t auth_codeTypeMissedCall::ID;

object_ptr<auth_CodeType> auth_codeTypeMissedCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_codeTypeMissedCall>();
}

void auth_codeTypeMissedCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.codeTypeMissedCall");
    s.store_class_end();
  }
}

const std::int32_t auth_codeTypeFragmentSms::ID;

object_ptr<auth_CodeType> auth_codeTypeFragmentSms::fetch(TlBufferParser &p) {
  return make_tl_object<auth_codeTypeFragmentSms>();
}

void auth_codeTypeFragmentSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.codeTypeFragmentSms");
    s.store_class_end();
  }
}

const std::int32_t auth_exportedAuthorization::ID;

object_ptr<auth_exportedAuthorization> auth_exportedAuthorization::fetch(TlBufferParser &p) {
  return make_tl_object<auth_exportedAuthorization>(p);
}

auth_exportedAuthorization::auth_exportedAuthorization(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void auth_exportedAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.exportedAuthorization");
    s.store_field("id", id_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

const std::int32_t auth_passkeyLoginOptions::ID;

object_ptr<auth_passkeyLoginOptions> auth_passkeyLoginOptions::fetch(TlBufferParser &p) {
  return make_tl_object<auth_passkeyLoginOptions>(p);
}

auth_passkeyLoginOptions::auth_passkeyLoginOptions(TlBufferParser &p)
  : options_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void auth_passkeyLoginOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.passkeyLoginOptions");
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_class_end();
  }
}

const std::int32_t channels_channelParticipant::ID;

object_ptr<channels_channelParticipant> channels_channelParticipant::fetch(TlBufferParser &p) {
  return make_tl_object<channels_channelParticipant>(p);
}

channels_channelParticipant::channels_channelParticipant(TlBufferParser &p)
  : participant_(TlFetchObject<ChannelParticipant>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void channels_channelParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.channelParticipant");
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<help_DeepLinkInfo> help_DeepLinkInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_deepLinkInfoEmpty::ID:
      return help_deepLinkInfoEmpty::fetch(p);
    case help_deepLinkInfo::ID:
      return help_deepLinkInfo::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_deepLinkInfoEmpty::ID;

object_ptr<help_DeepLinkInfo> help_deepLinkInfoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<help_deepLinkInfoEmpty>();
}

void help_deepLinkInfoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.deepLinkInfoEmpty");
    s.store_class_end();
  }
}

help_deepLinkInfo::help_deepLinkInfo()
  : flags_()
  , update_app_()
  , message_()
  , entities_()
{}

const std::int32_t help_deepLinkInfo::ID;

object_ptr<help_DeepLinkInfo> help_deepLinkInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_deepLinkInfo> res = make_tl_object<help_deepLinkInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->update_app_ = (var0 & 1) != 0;
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void help_deepLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.deepLinkInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (update_app_ << 0) | ((!entities_.empty()) << 1)));
    if (var0 & 1) { s.store_field("update_app", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t help_support::ID;

object_ptr<help_support> help_support::fetch(TlBufferParser &p) {
  return make_tl_object<help_support>(p);
}

help_support::help_support(TlBufferParser &p)
  : phone_number_(TlFetchString<string>::parse(p))
  , user_(TlFetchObject<User>::parse(p))
{}

void help_support::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.support");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("user", static_cast<const BaseObject *>(user_.get()));
    s.store_class_end();
  }
}

messages_botResults::messages_botResults()
  : flags_()
  , gallery_()
  , query_id_()
  , next_offset_()
  , switch_pm_()
  , switch_webview_()
  , results_()
  , cache_time_()
  , users_()
{}

const std::int32_t messages_botResults::ID;

object_ptr<messages_botResults> messages_botResults::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_botResults> res = make_tl_object<messages_botResults>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->gallery_ = (var0 & 1) != 0;
  res->query_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->switch_pm_ = TlFetchBoxed<TlFetchObject<inlineBotSwitchPM>, 1008755359>::parse(p); }
  if (var0 & 8) { res->switch_webview_ = TlFetchBoxed<TlFetchObject<inlineBotWebView>, -1250781739>::parse(p); }
  res->results_ = TlFetchBoxed<TlFetchVector<TlFetchObject<BotInlineResult>>, 481674261>::parse(p);
  res->cache_time_ = TlFetchInt::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_botResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.botResults");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (gallery_ << 0) | ((!next_offset_.empty()) << 1) | ((switch_pm_ != nullptr) << 2) | ((switch_webview_ != nullptr) << 3)));
    if (var0 & 1) { s.store_field("gallery", true); }
    s.store_field("query_id", query_id_);
    if (var0 & 2) { s.store_field("next_offset", next_offset_); }
    if (var0 & 4) { s.store_object_field("switch_pm", static_cast<const BaseObject *>(switch_pm_.get())); }
    if (var0 & 8) { s.store_object_field("switch_webview", static_cast<const BaseObject *>(switch_webview_.get())); }
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("cache_time", cache_time_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_chatAdminsWithInvites::ID;

object_ptr<messages_chatAdminsWithInvites> messages_chatAdminsWithInvites::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chatAdminsWithInvites>(p);
}

messages_chatAdminsWithInvites::messages_chatAdminsWithInvites(TlBufferParser &p)
  : admins_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<chatAdminWithInvites>, -219353309>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_chatAdminsWithInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chatAdminsWithInvites");
    { s.store_vector_begin("admins", admins_.size()); for (const auto &_value : admins_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_SavedGifs> messages_SavedGifs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_savedGifsNotModified::ID:
      return messages_savedGifsNotModified::fetch(p);
    case messages_savedGifs::ID:
      return messages_savedGifs::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_savedGifsNotModified::ID;

object_ptr<messages_SavedGifs> messages_savedGifsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedGifsNotModified>();
}

void messages_savedGifsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedGifsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_savedGifs::ID;

object_ptr<messages_SavedGifs> messages_savedGifs::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedGifs>(p);
}

messages_savedGifs::messages_savedGifs(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , gifs_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void messages_savedGifs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedGifs");
    s.store_field("hash", hash_);
    { s.store_vector_begin("gifs", gifs_.size()); for (const auto &_value : gifs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_SentEncryptedMessage> messages_SentEncryptedMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_sentEncryptedMessage::ID:
      return messages_sentEncryptedMessage::fetch(p);
    case messages_sentEncryptedFile::ID:
      return messages_sentEncryptedFile::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_sentEncryptedMessage::ID;

object_ptr<messages_SentEncryptedMessage> messages_sentEncryptedMessage::fetch(TlBufferParser &p) {
  return make_tl_object<messages_sentEncryptedMessage>(p);
}

messages_sentEncryptedMessage::messages_sentEncryptedMessage(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
{}

void messages_sentEncryptedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sentEncryptedMessage");
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t messages_sentEncryptedFile::ID;

object_ptr<messages_SentEncryptedMessage> messages_sentEncryptedFile::fetch(TlBufferParser &p) {
  return make_tl_object<messages_sentEncryptedFile>(p);
}

messages_sentEncryptedFile::messages_sentEncryptedFile(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , file_(TlFetchObject<EncryptedFile>::parse(p))
{}

void messages_sentEncryptedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sentEncryptedFile");
    s.store_field("date", date_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

messages_transcribedAudio::messages_transcribedAudio()
  : flags_()
  , pending_()
  , transcription_id_()
  , text_()
  , trial_remains_num_()
  , trial_remains_until_date_()
{}

const std::int32_t messages_transcribedAudio::ID;

object_ptr<messages_transcribedAudio> messages_transcribedAudio::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_transcribedAudio> res = make_tl_object<messages_transcribedAudio>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pending_ = (var0 & 1) != 0;
  res->transcription_id_ = TlFetchLong::parse(p);
  res->text_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->trial_remains_num_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->trial_remains_until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_transcribedAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.transcribedAudio");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pending_ << 0)));
    if (var0 & 1) { s.store_field("pending", true); }
    s.store_field("transcription_id", transcription_id_);
    s.store_field("text", text_);
    if (var0 & 2) { s.store_field("trial_remains_num", trial_remains_num_); }
    if (var0 & 2) { s.store_field("trial_remains_until_date", trial_remains_until_date_); }
    s.store_class_end();
  }
}

object_ptr<payments_PaymentForm> payments_PaymentForm::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_paymentForm::ID:
      return payments_paymentForm::fetch(p);
    case payments_paymentFormStars::ID:
      return payments_paymentFormStars::fetch(p);
    case payments_paymentFormStarGift::ID:
      return payments_paymentFormStarGift::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

payments_paymentForm::payments_paymentForm()
  : flags_()
  , can_save_credentials_()
  , password_missing_()
  , form_id_()
  , bot_id_()
  , title_()
  , description_()
  , photo_()
  , invoice_()
  , provider_id_()
  , url_()
  , native_provider_()
  , native_params_()
  , additional_methods_()
  , saved_info_()
  , saved_credentials_()
  , users_()
{}

const std::int32_t payments_paymentForm::ID;

object_ptr<payments_PaymentForm> payments_paymentForm::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_paymentForm> res = make_tl_object<payments_paymentForm>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_save_credentials_ = (var0 & 4) != 0;
  res->password_missing_ = (var0 & 8) != 0;
  res->form_id_ = TlFetchLong::parse(p);
  res->bot_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 32) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  res->invoice_ = TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p);
  res->provider_id_ = TlFetchLong::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  if (var0 & 16) { res->native_provider_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->native_params_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p); }
  if (var0 & 64) { res->additional_methods_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<paymentFormMethod>, -1996951013>>, 481674261>::parse(p); }
  if (var0 & 1) { res->saved_info_ = TlFetchBoxed<TlFetchObject<paymentRequestedInfo>, -1868808300>::parse(p); }
  if (var0 & 2) { res->saved_credentials_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<paymentSavedCredentialsCard>, -842892769>>, 481674261>::parse(p); }
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_paymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentForm");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_save_credentials_ << 2) | (password_missing_ << 3) | ((photo_ != nullptr) << 5) | ((!native_provider_.empty()) << 4) | ((native_params_ != nullptr) << 4) | ((!additional_methods_.empty()) << 6) | ((saved_info_ != nullptr) << 0) | ((!saved_credentials_.empty()) << 1)));
    if (var0 & 4) { s.store_field("can_save_credentials", true); }
    if (var0 & 8) { s.store_field("password_missing", true); }
    s.store_field("form_id", form_id_);
    s.store_field("bot_id", bot_id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 32) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_field("provider_id", provider_id_);
    s.store_field("url", url_);
    if (var0 & 16) { s.store_field("native_provider", native_provider_); }
    if (var0 & 16) { s.store_object_field("native_params", static_cast<const BaseObject *>(native_params_.get())); }
    if (var0 & 64) { { s.store_vector_begin("additional_methods", additional_methods_.size()); for (const auto &_value : additional_methods_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1) { s.store_object_field("saved_info", static_cast<const BaseObject *>(saved_info_.get())); }
    if (var0 & 2) { { s.store_vector_begin("saved_credentials", saved_credentials_.size()); for (const auto &_value : saved_credentials_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_paymentFormStars::payments_paymentFormStars()
  : flags_()
  , form_id_()
  , bot_id_()
  , title_()
  , description_()
  , photo_()
  , invoice_()
  , users_()
{}

const std::int32_t payments_paymentFormStars::ID;

object_ptr<payments_PaymentForm> payments_paymentFormStars::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_paymentFormStars> res = make_tl_object<payments_paymentFormStars>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->form_id_ = TlFetchLong::parse(p);
  res->bot_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 32) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  res->invoice_ = TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_paymentFormStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentFormStars");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((photo_ != nullptr) << 5)));
    s.store_field("form_id", form_id_);
    s.store_field("bot_id", bot_id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 32) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_paymentFormStarGift::ID;

object_ptr<payments_PaymentForm> payments_paymentFormStarGift::fetch(TlBufferParser &p) {
  return make_tl_object<payments_paymentFormStarGift>(p);
}

payments_paymentFormStarGift::payments_paymentFormStarGift(TlBufferParser &p)
  : form_id_(TlFetchLong::parse(p))
  , invoice_(TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p))
{}

void payments_paymentFormStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentFormStarGift");
    s.store_field("form_id", form_id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_class_end();
  }
}

payments_resaleStarGifts::payments_resaleStarGifts()
  : flags_()
  , count_()
  , gifts_()
  , next_offset_()
  , attributes_()
  , attributes_hash_()
  , chats_()
  , counters_()
  , users_()
{}

const std::int32_t payments_resaleStarGifts::ID;

object_ptr<payments_resaleStarGifts> payments_resaleStarGifts::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_resaleStarGifts> res = make_tl_object<payments_resaleStarGifts>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->gifts_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StarGift>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->attributes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StarGiftAttribute>>, 481674261>::parse(p); }
  if (var0 & 2) { res->attributes_hash_ = TlFetchLong::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  if (var0 & 4) { res->counters_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftAttributeCounter>, 783398488>>, 481674261>::parse(p); }
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_resaleStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.resaleStarGifts");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0) | ((!attributes_.empty()) << 1) | ((!counters_.empty()) << 2)));
    s.store_field("count", count_);
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    if (var0 & 2) { { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("attributes_hash", attributes_hash_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 4) { { s.store_vector_begin("counters", counters_.size()); for (const auto &_value : counters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftAuctionState::ID;

object_ptr<payments_starGiftAuctionState> payments_starGiftAuctionState::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftAuctionState>(p);
}

payments_starGiftAuctionState::payments_starGiftAuctionState(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
  , state_(TlFetchObject<StarGiftAuctionState>::parse(p))
  , user_state_(TlFetchBoxed<TlFetchObject<starGiftAuctionUserState>, 787403204>::parse(p))
  , timeout_(TlFetchInt::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
{}

void payments_starGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftAuctionState");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_object_field("user_state", static_cast<const BaseObject *>(user_state_.get()));
    s.store_field("timeout", timeout_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_starsRevenueStats::payments_starsRevenueStats()
  : flags_()
  , top_hours_graph_()
  , revenue_graph_()
  , status_()
  , usd_rate_()
{}

const std::int32_t payments_starsRevenueStats::ID;

object_ptr<payments_starsRevenueStats> payments_starsRevenueStats::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_starsRevenueStats> res = make_tl_object<payments_starsRevenueStats>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->top_hours_graph_ = TlFetchObject<StatsGraph>::parse(p); }
  res->revenue_graph_ = TlFetchObject<StatsGraph>::parse(p);
  res->status_ = TlFetchBoxed<TlFetchObject<starsRevenueStatus>, -21080943>::parse(p);
  res->usd_rate_ = TlFetchDouble::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_starsRevenueStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starsRevenueStats");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((top_hours_graph_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("top_hours_graph", static_cast<const BaseObject *>(top_hours_graph_.get())); }
    s.store_object_field("revenue_graph", static_cast<const BaseObject *>(revenue_graph_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("usd_rate", usd_rate_);
    s.store_class_end();
  }
}

const std::int32_t phone_groupCallStreamRtmpUrl::ID;

object_ptr<phone_groupCallStreamRtmpUrl> phone_groupCallStreamRtmpUrl::fetch(TlBufferParser &p) {
  return make_tl_object<phone_groupCallStreamRtmpUrl>(p);
}

phone_groupCallStreamRtmpUrl::phone_groupCallStreamRtmpUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , key_(TlFetchString<string>::parse(p))
{}

void phone_groupCallStreamRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.groupCallStreamRtmpUrl");
    s.store_field("url", url_);
    s.store_field("key", key_);
    s.store_class_end();
  }
}

object_ptr<photos_Photos> photos_Photos::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case photos_photos::ID:
      return photos_photos::fetch(p);
    case photos_photosSlice::ID:
      return photos_photosSlice::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t photos_photos::ID;

object_ptr<photos_Photos> photos_photos::fetch(TlBufferParser &p) {
  return make_tl_object<photos_photos>(p);
}

photos_photos::photos_photos(TlBufferParser &p)
  : photos_(TlFetchBoxed<TlFetchVector<TlFetchObject<Photo>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void photos_photos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.photos");
    { s.store_vector_begin("photos", photos_.size()); for (const auto &_value : photos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t photos_photosSlice::ID;

object_ptr<photos_Photos> photos_photosSlice::fetch(TlBufferParser &p) {
  return make_tl_object<photos_photosSlice>(p);
}

photos_photosSlice::photos_photosSlice(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , photos_(TlFetchBoxed<TlFetchVector<TlFetchObject<Photo>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void photos_photosSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.photosSlice");
    s.store_field("count", count_);
    { s.store_vector_begin("photos", photos_.size()); for (const auto &_value : photos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t premium_myBoosts::ID;

object_ptr<premium_myBoosts> premium_myBoosts::fetch(TlBufferParser &p) {
  return make_tl_object<premium_myBoosts>(p);
}

premium_myBoosts::premium_myBoosts(TlBufferParser &p)
  : my_boosts_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<myBoost>, -1001897636>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void premium_myBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.myBoosts");
    { s.store_vector_begin("my_boosts", my_boosts_.size()); for (const auto &_value : my_boosts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t smsjobs_eligibleToJoin::ID;

object_ptr<smsjobs_eligibleToJoin> smsjobs_eligibleToJoin::fetch(TlBufferParser &p) {
  return make_tl_object<smsjobs_eligibleToJoin>(p);
}

smsjobs_eligibleToJoin::smsjobs_eligibleToJoin(TlBufferParser &p)
  : terms_url_(TlFetchString<string>::parse(p))
  , monthly_sent_sms_(TlFetchInt::parse(p))
{}

void smsjobs_eligibleToJoin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.eligibleToJoin");
    s.store_field("terms_url", terms_url_);
    s.store_field("monthly_sent_sms", monthly_sent_sms_);
    s.store_class_end();
  }
}

const std::int32_t stats_broadcastStats::ID;

object_ptr<stats_broadcastStats> stats_broadcastStats::fetch(TlBufferParser &p) {
  return make_tl_object<stats_broadcastStats>(p);
}

stats_broadcastStats::stats_broadcastStats(TlBufferParser &p)
  : period_(TlFetchBoxed<TlFetchObject<statsDateRangeDays>, -1237848657>::parse(p))
  , followers_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , views_per_post_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , shares_per_post_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , reactions_per_post_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , views_per_story_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , shares_per_story_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , reactions_per_story_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , enabled_notifications_(TlFetchBoxed<TlFetchObject<statsPercentValue>, -875679776>::parse(p))
  , growth_graph_(TlFetchObject<StatsGraph>::parse(p))
  , followers_graph_(TlFetchObject<StatsGraph>::parse(p))
  , mute_graph_(TlFetchObject<StatsGraph>::parse(p))
  , top_hours_graph_(TlFetchObject<StatsGraph>::parse(p))
  , interactions_graph_(TlFetchObject<StatsGraph>::parse(p))
  , iv_interactions_graph_(TlFetchObject<StatsGraph>::parse(p))
  , views_by_source_graph_(TlFetchObject<StatsGraph>::parse(p))
  , new_followers_by_source_graph_(TlFetchObject<StatsGraph>::parse(p))
  , languages_graph_(TlFetchObject<StatsGraph>::parse(p))
  , reactions_by_emotion_graph_(TlFetchObject<StatsGraph>::parse(p))
  , story_interactions_graph_(TlFetchObject<StatsGraph>::parse(p))
  , story_reactions_by_emotion_graph_(TlFetchObject<StatsGraph>::parse(p))
  , recent_posts_interactions_(TlFetchBoxed<TlFetchVector<TlFetchObject<PostInteractionCounters>>, 481674261>::parse(p))
{}

void stats_broadcastStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.broadcastStats");
    s.store_object_field("period", static_cast<const BaseObject *>(period_.get()));
    s.store_object_field("followers", static_cast<const BaseObject *>(followers_.get()));
    s.store_object_field("views_per_post", static_cast<const BaseObject *>(views_per_post_.get()));
    s.store_object_field("shares_per_post", static_cast<const BaseObject *>(shares_per_post_.get()));
    s.store_object_field("reactions_per_post", static_cast<const BaseObject *>(reactions_per_post_.get()));
    s.store_object_field("views_per_story", static_cast<const BaseObject *>(views_per_story_.get()));
    s.store_object_field("shares_per_story", static_cast<const BaseObject *>(shares_per_story_.get()));
    s.store_object_field("reactions_per_story", static_cast<const BaseObject *>(reactions_per_story_.get()));
    s.store_object_field("enabled_notifications", static_cast<const BaseObject *>(enabled_notifications_.get()));
    s.store_object_field("growth_graph", static_cast<const BaseObject *>(growth_graph_.get()));
    s.store_object_field("followers_graph", static_cast<const BaseObject *>(followers_graph_.get()));
    s.store_object_field("mute_graph", static_cast<const BaseObject *>(mute_graph_.get()));
    s.store_object_field("top_hours_graph", static_cast<const BaseObject *>(top_hours_graph_.get()));
    s.store_object_field("interactions_graph", static_cast<const BaseObject *>(interactions_graph_.get()));
    s.store_object_field("iv_interactions_graph", static_cast<const BaseObject *>(iv_interactions_graph_.get()));
    s.store_object_field("views_by_source_graph", static_cast<const BaseObject *>(views_by_source_graph_.get()));
    s.store_object_field("new_followers_by_source_graph", static_cast<const BaseObject *>(new_followers_by_source_graph_.get()));
    s.store_object_field("languages_graph", static_cast<const BaseObject *>(languages_graph_.get()));
    s.store_object_field("reactions_by_emotion_graph", static_cast<const BaseObject *>(reactions_by_emotion_graph_.get()));
    s.store_object_field("story_interactions_graph", static_cast<const BaseObject *>(story_interactions_graph_.get()));
    s.store_object_field("story_reactions_by_emotion_graph", static_cast<const BaseObject *>(story_reactions_by_emotion_graph_.get()));
    { s.store_vector_begin("recent_posts_interactions", recent_posts_interactions_.size()); for (const auto &_value : recent_posts_interactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stickers_suggestedShortName::ID;

object_ptr<stickers_suggestedShortName> stickers_suggestedShortName::fetch(TlBufferParser &p) {
  return make_tl_object<stickers_suggestedShortName>(p);
}

stickers_suggestedShortName::stickers_suggestedShortName(TlBufferParser &p)
  : short_name_(TlFetchString<string>::parse(p))
{}

void stickers_suggestedShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.suggestedShortName");
    s.store_field("short_name", short_name_);
    s.store_class_end();
  }
}

const std::int32_t stories_peerStories::ID;

object_ptr<stories_peerStories> stories_peerStories::fetch(TlBufferParser &p) {
  return make_tl_object<stories_peerStories>(p);
}

stories_peerStories::stories_peerStories(TlBufferParser &p)
  : stories_(TlFetchBoxed<TlFetchObject<peerStories>, -1707742823>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void stories_peerStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.peerStories");
    s.store_object_field("stories", static_cast<const BaseObject *>(stories_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

wallet_existingBalance::wallet_existingBalance()
  : flags_()
  , has_balance_()
  , url_()
{}

const std::int32_t wallet_existingBalance::ID;

object_ptr<wallet_existingBalance> wallet_existingBalance::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<wallet_existingBalance> res = make_tl_object<wallet_existingBalance>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_balance_ = (var0 & 1) != 0;
  res->url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void wallet_existingBalance::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.existingBalance");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_balance_ << 0)));
    if (var0 & 1) { s.store_field("has_balance", true); }
    s.store_field("url", url_);
    s.store_class_end();
  }
}

wallet_nftItems::wallet_nftItems()
  : flags_()
  , items_()
  , next_offset_()
{}

const std::int32_t wallet_nftItems::ID;

object_ptr<wallet_nftItems> wallet_nftItems::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<wallet_nftItems> res = make_tl_object<wallet_nftItems>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->items_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<wallet_nftItem>, 389937907>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void wallet_nftItems::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.nftItems");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

const std::int32_t account_cancelPasswordEmail::ID;

void account_cancelPasswordEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1043606090);
}

void account_cancelPasswordEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1043606090);
}

void account_cancelPasswordEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.cancelPasswordEmail");
    s.store_class_end();
  }
}

account_cancelPasswordEmail::ReturnType account_cancelPasswordEmail::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_deleteAutoSaveExceptions::ID;

void account_deleteAutoSaveExceptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1404829728);
}

void account_deleteAutoSaveExceptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1404829728);
}

void account_deleteAutoSaveExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.deleteAutoSaveExceptions");
    s.store_class_end();
  }
}

account_deleteAutoSaveExceptions::ReturnType account_deleteAutoSaveExceptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_deleteBusinessChatLink::account_deleteBusinessChatLink(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t account_deleteBusinessChatLink::ID;

void account_deleteBusinessChatLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1611085428);
  TlStoreString::store(slug_, s);
}

void account_deleteBusinessChatLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1611085428);
  TlStoreString::store(slug_, s);
}

void account_deleteBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.deleteBusinessChatLink");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

account_deleteBusinessChatLink::ReturnType account_deleteBusinessChatLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_getBotBusinessConnection::account_getBotBusinessConnection(string const &connection_id_)
  : connection_id_(connection_id_)
{}

const std::int32_t account_getBotBusinessConnection::ID;

void account_getBotBusinessConnection::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1990746736);
  TlStoreString::store(connection_id_, s);
}

void account_getBotBusinessConnection::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1990746736);
  TlStoreString::store(connection_id_, s);
}

void account_getBotBusinessConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getBotBusinessConnection");
    s.store_field("connection_id", connection_id_);
    s.store_class_end();
  }
}

account_getBotBusinessConnection::ReturnType account_getBotBusinessConnection::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

account_getDefaultEmojiStatuses::account_getDefaultEmojiStatuses(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getDefaultEmojiStatuses::ID;

void account_getDefaultEmojiStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-696962170);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultEmojiStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-696962170);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getDefaultEmojiStatuses");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getDefaultEmojiStatuses::ReturnType account_getDefaultEmojiStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_EmojiStatuses>::parse(p);
#undef FAIL
}

account_getDefaultProfilePhotoEmojis::account_getDefaultProfilePhotoEmojis(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getDefaultProfilePhotoEmojis::ID;

void account_getDefaultProfilePhotoEmojis::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-495647960);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultProfilePhotoEmojis::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-495647960);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultProfilePhotoEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getDefaultProfilePhotoEmojis");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getDefaultProfilePhotoEmojis::ReturnType account_getDefaultProfilePhotoEmojis::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EmojiList>::parse(p);
#undef FAIL
}

account_getNotifyExceptions::account_getNotifyExceptions(int32 flags_, bool compare_sound_, bool compare_stories_, object_ptr<InputNotifyPeer> &&peer_)
  : flags_(flags_)
  , compare_sound_(compare_sound_)
  , compare_stories_(compare_stories_)
  , peer_(std::move(peer_))
{}

const std::int32_t account_getNotifyExceptions::ID;

void account_getNotifyExceptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1398240377);
  TlStoreBinary::store((var0 = flags_ | (compare_sound_ << 1) | (compare_stories_ << 2) | ((peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
}

void account_getNotifyExceptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1398240377);
  TlStoreBinary::store((var0 = flags_ | (compare_sound_ << 1) | (compare_stories_ << 2) | ((peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
}

void account_getNotifyExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getNotifyExceptions");
    s.store_field("flags", (var0 = flags_ | (compare_sound_ << 1) | (compare_stories_ << 2) | ((peer_ != nullptr) << 0)));
    if (var0 & 2) { s.store_field("compare_sound", true); }
    if (var0 & 4) { s.store_field("compare_stories", true); }
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_class_end();
  }
}

account_getNotifyExceptions::ReturnType account_getNotifyExceptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

account_getPaidMessagesRevenue::account_getPaidMessagesRevenue(int32 flags_, object_ptr<InputPeer> &&parent_peer_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , parent_peer_(std::move(parent_peer_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t account_getPaidMessagesRevenue::ID;

void account_getPaidMessagesRevenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(431639143);
  TlStoreBinary::store((var0 = flags_ | ((parent_peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void account_getPaidMessagesRevenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(431639143);
  TlStoreBinary::store((var0 = flags_ | ((parent_peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void account_getPaidMessagesRevenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getPaidMessagesRevenue");
    s.store_field("flags", (var0 = flags_ | ((parent_peer_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

account_getPaidMessagesRevenue::ReturnType account_getPaidMessagesRevenue::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_paidMessagesRevenue>, 504403720>::parse(p);
#undef FAIL
}

account_getPrivacy::account_getPrivacy(object_ptr<InputPrivacyKey> &&key_)
  : key_(std::move(key_))
{}

const std::int32_t account_getPrivacy::ID;

void account_getPrivacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-623130288);
  TlStoreBoxedUnknown<TlStoreObject>::store(key_, s);
}

void account_getPrivacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-623130288);
  TlStoreBoxedUnknown<TlStoreObject>::store(key_, s);
}

void account_getPrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getPrivacy");
    s.store_object_field("key", static_cast<const BaseObject *>(key_.get()));
    s.store_class_end();
  }
}

account_getPrivacy::ReturnType account_getPrivacy::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_privacyRules>, 1352683077>::parse(p);
#undef FAIL
}

account_getRecentEmojiStatuses::account_getRecentEmojiStatuses(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getRecentEmojiStatuses::ID;

void account_getRecentEmojiStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(257392901);
  TlStoreBinary::store(hash_, s);
}

void account_getRecentEmojiStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(257392901);
  TlStoreBinary::store(hash_, s);
}

void account_getRecentEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getRecentEmojiStatuses");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getRecentEmojiStatuses::ReturnType account_getRecentEmojiStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_EmojiStatuses>::parse(p);
#undef FAIL
}

account_registerDevice::account_registerDevice(int32 flags_, bool no_muted_, int32 token_type_, string const &token_, bool app_sandbox_, bytes &&secret_, array<int64> &&other_uids_)
  : flags_(flags_)
  , no_muted_(no_muted_)
  , token_type_(token_type_)
  , token_(token_)
  , app_sandbox_(app_sandbox_)
  , secret_(std::move(secret_))
  , other_uids_(std::move(other_uids_))
{}

const std::int32_t account_registerDevice::ID;

void account_registerDevice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-326762118);
  TlStoreBinary::store((var0 = flags_ | (no_muted_ << 0)), s);
  TlStoreBinary::store(token_type_, s);
  TlStoreString::store(token_, s);
  TlStoreBool::store(app_sandbox_, s);
  TlStoreString::store(secret_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(other_uids_, s);
}

void account_registerDevice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-326762118);
  TlStoreBinary::store((var0 = flags_ | (no_muted_ << 0)), s);
  TlStoreBinary::store(token_type_, s);
  TlStoreString::store(token_, s);
  TlStoreBool::store(app_sandbox_, s);
  TlStoreString::store(secret_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(other_uids_, s);
}

void account_registerDevice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.registerDevice");
    s.store_field("flags", (var0 = flags_ | (no_muted_ << 0)));
    if (var0 & 1) { s.store_field("no_muted", true); }
    s.store_field("token_type", token_type_);
    s.store_field("token", "[REDACTED]");
    s.store_field("app_sandbox", app_sandbox_);
    s.store_field("secret", "[REDACTED]");
    { s.store_vector_begin("other_uids", other_uids_.size()); for (const auto &_value : other_uids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_registerDevice::ReturnType account_registerDevice::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_resetAuthorization::account_resetAuthorization(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_resetAuthorization::ID;

void account_resetAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-545786948);
  TlStoreBinary::store(hash_, s);
}

void account_resetAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-545786948);
  TlStoreBinary::store(hash_, s);
}

void account_resetAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetAuthorization");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_resetAuthorization::ReturnType account_resetAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_setMainProfileTab::account_setMainProfileTab(object_ptr<ProfileTab> &&tab_)
  : tab_(std::move(tab_))
{}

const std::int32_t account_setMainProfileTab::ID;

void account_setMainProfileTab::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1575909552);
  TlStoreBoxedUnknown<TlStoreObject>::store(tab_, s);
}

void account_setMainProfileTab::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1575909552);
  TlStoreBoxedUnknown<TlStoreObject>::store(tab_, s);
}

void account_setMainProfileTab::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setMainProfileTab");
    s.store_object_field("tab", static_cast<const BaseObject *>(tab_.get()));
    s.store_class_end();
  }
}

account_setMainProfileTab::ReturnType account_setMainProfileTab::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_setReactionsNotifySettings::account_setReactionsNotifySettings(object_ptr<reactionsNotifySettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t account_setReactionsNotifySettings::ID;

void account_setReactionsNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(829220168);
  TlStoreBoxed<TlStoreObject, 1910827608>::store(settings_, s);
}

void account_setReactionsNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(829220168);
  TlStoreBoxed<TlStoreObject, 1910827608>::store(settings_, s);
}

void account_setReactionsNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setReactionsNotifySettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_setReactionsNotifySettings::ReturnType account_setReactionsNotifySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<reactionsNotifySettings>, 1910827608>::parse(p);
#undef FAIL
}

account_updateNotifySettings::account_updateNotifySettings(object_ptr<InputNotifyPeer> &&peer_, object_ptr<inputPeerNotifySettings> &&settings_)
  : peer_(std::move(peer_))
  , settings_(std::move(settings_))
{}

const std::int32_t account_updateNotifySettings::ID;

void account_updateNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2067899501);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, -892638494>::store(settings_, s);
}

void account_updateNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2067899501);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, -892638494>::store(settings_, s);
}

void account_updateNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateNotifySettings");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_updateNotifySettings::ReturnType account_updateNotifySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_uploadWallPaper::account_uploadWallPaper(int32 flags_, bool for_chat_, object_ptr<InputFile> &&file_, string const &mime_type_, object_ptr<wallPaperSettings> &&settings_)
  : flags_(flags_)
  , for_chat_(for_chat_)
  , file_(std::move(file_))
  , mime_type_(mime_type_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_uploadWallPaper::ID;

void account_uploadWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-476410109);
  TlStoreBinary::store((var0 = flags_ | (for_chat_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_uploadWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-476410109);
  TlStoreBinary::store((var0 = flags_ | (for_chat_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_uploadWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.uploadWallPaper");
    s.store_field("flags", (var0 = flags_ | (for_chat_ << 0)));
    if (var0 & 1) { s.store_field("for_chat", true); }
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("mime_type", mime_type_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_uploadWallPaper::ReturnType account_uploadWallPaper::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<WallPaper>::parse(p);
#undef FAIL
}

auth_exportLoginToken::auth_exportLoginToken(int32 api_id_, string const &api_hash_, array<int64> &&except_ids_)
  : api_id_(api_id_)
  , api_hash_(api_hash_)
  , except_ids_(std::move(except_ids_))
{}

const std::int32_t auth_exportLoginToken::ID;

void auth_exportLoginToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1210022402);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(except_ids_, s);
}

void auth_exportLoginToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1210022402);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(except_ids_, s);
}

void auth_exportLoginToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.exportLoginToken");
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", "[REDACTED]");
    { s.store_vector_begin("except_ids", except_ids_.size()); for (const auto &_value : except_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

auth_exportLoginToken::ReturnType auth_exportLoginToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_LoginToken>::parse(p);
#undef FAIL
}

auth_importAuthorization::auth_importAuthorization(int64 id_, bytes &&bytes_)
  : id_(id_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t auth_importAuthorization::ID;

void auth_importAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1518699091);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(bytes_, s);
}

void auth_importAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1518699091);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(bytes_, s);
}

void auth_importAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.importAuthorization");
    s.store_field("id", id_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

auth_importAuthorization::ReturnType auth_importAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

bots_getPopularAppBots::bots_getPopularAppBots(string const &offset_, int32 limit_)
  : offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t bots_getPopularAppBots::ID;

void bots_getPopularAppBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1034878574);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void bots_getPopularAppBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1034878574);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void bots_getPopularAppBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getPopularAppBots");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

bots_getPopularAppBots::ReturnType bots_getPopularAppBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<bots_popularAppBots>, 428978491>::parse(p);
#undef FAIL
}

bots_getPreviewInfo::bots_getPreviewInfo(object_ptr<InputUser> &&bot_, string const &lang_code_)
  : bot_(std::move(bot_))
  , lang_code_(lang_code_)
{}

const std::int32_t bots_getPreviewInfo::ID;

void bots_getPreviewInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1111143341);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_getPreviewInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1111143341);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_getPreviewInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getPreviewInfo");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

bots_getPreviewInfo::ReturnType bots_getPreviewInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<bots_previewInfo>, 212278628>::parse(p);
#undef FAIL
}

bots_reorderUsernames::bots_reorderUsernames(object_ptr<InputUser> &&bot_, array<string> &&order_)
  : bot_(std::move(bot_))
  , order_(std::move(order_))
{}

const std::int32_t bots_reorderUsernames::ID;

void bots_reorderUsernames::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1760972350);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void bots_reorderUsernames::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1760972350);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void bots_reorderUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.reorderUsernames");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

bots_reorderUsernames::ReturnType bots_reorderUsernames::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_setBotSettings::bots_setBotSettings(int32 flags_, object_ptr<InputUser> &&bot_, bool inline_mode_, string const &inline_placeholder_, bool inline_geo_, int32 inline_feedback_, bool nochats_, bool chat_history_, bool business_, bool can_manage_bots_, bool guestchat_, bool guard_, bool forum_view_, bool forum_can_manage_topics_, bool forum_sidebar_, bool bot_to_bot_communication_mode_, string const &callback_mode_)
  : flags_(flags_)
  , bot_(std::move(bot_))
  , inline_mode_(inline_mode_)
  , inline_placeholder_(inline_placeholder_)
  , inline_geo_(inline_geo_)
  , inline_feedback_(inline_feedback_)
  , nochats_(nochats_)
  , chat_history_(chat_history_)
  , business_(business_)
  , can_manage_bots_(can_manage_bots_)
  , guestchat_(guestchat_)
  , guard_(guard_)
  , forum_view_(forum_view_)
  , forum_can_manage_topics_(forum_can_manage_topics_)
  , forum_sidebar_(forum_sidebar_)
  , bot_to_bot_communication_mode_(bot_to_bot_communication_mode_)
  , callback_mode_(callback_mode_)
{}

const std::int32_t bots_setBotSettings::ID;

void bots_setBotSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2093007050);
  TlStoreBinary::store((var0 = flags_ | ((bot_ != nullptr) << 0) | ((!inline_placeholder_.empty()) << 2) | ((!callback_mode_.empty()) << 15)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  if (var0 & 2) { TlStoreBool::store(inline_mode_, s); }
  if (var0 & 4) { TlStoreString::store(inline_placeholder_, s); }
  if (var0 & 8) { TlStoreBool::store(inline_geo_, s); }
  if (var0 & 16) { TlStoreBinary::store(inline_feedback_, s); }
  if (var0 & 32) { TlStoreBool::store(nochats_, s); }
  if (var0 & 64) { TlStoreBool::store(chat_history_, s); }
  if (var0 & 128) { TlStoreBool::store(business_, s); }
  if (var0 & 256) { TlStoreBool::store(can_manage_bots_, s); }
  if (var0 & 512) { TlStoreBool::store(guestchat_, s); }
  if (var0 & 1024) { TlStoreBool::store(guard_, s); }
  if (var0 & 2048) { TlStoreBool::store(forum_view_, s); }
  if (var0 & 4096) { TlStoreBool::store(forum_can_manage_topics_, s); }
  if (var0 & 8192) { TlStoreBool::store(forum_sidebar_, s); }
  if (var0 & 16384) { TlStoreBool::store(bot_to_bot_communication_mode_, s); }
  if (var0 & 32768) { TlStoreString::store(callback_mode_, s); }
}

void bots_setBotSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2093007050);
  TlStoreBinary::store((var0 = flags_ | ((bot_ != nullptr) << 0) | ((!inline_placeholder_.empty()) << 2) | ((!callback_mode_.empty()) << 15)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  if (var0 & 2) { TlStoreBool::store(inline_mode_, s); }
  if (var0 & 4) { TlStoreString::store(inline_placeholder_, s); }
  if (var0 & 8) { TlStoreBool::store(inline_geo_, s); }
  if (var0 & 16) { TlStoreBinary::store(inline_feedback_, s); }
  if (var0 & 32) { TlStoreBool::store(nochats_, s); }
  if (var0 & 64) { TlStoreBool::store(chat_history_, s); }
  if (var0 & 128) { TlStoreBool::store(business_, s); }
  if (var0 & 256) { TlStoreBool::store(can_manage_bots_, s); }
  if (var0 & 512) { TlStoreBool::store(guestchat_, s); }
  if (var0 & 1024) { TlStoreBool::store(guard_, s); }
  if (var0 & 2048) { TlStoreBool::store(forum_view_, s); }
  if (var0 & 4096) { TlStoreBool::store(forum_can_manage_topics_, s); }
  if (var0 & 8192) { TlStoreBool::store(forum_sidebar_, s); }
  if (var0 & 16384) { TlStoreBool::store(bot_to_bot_communication_mode_, s); }
  if (var0 & 32768) { TlStoreString::store(callback_mode_, s); }
}

void bots_setBotSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setBotSettings");
    s.store_field("flags", (var0 = flags_ | ((bot_ != nullptr) << 0) | ((!inline_placeholder_.empty()) << 2) | ((!callback_mode_.empty()) << 15)));
    if (var0 & 1) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    if (var0 & 2) { s.store_field("inline_mode", inline_mode_); }
    if (var0 & 4) { s.store_field("inline_placeholder", inline_placeholder_); }
    if (var0 & 8) { s.store_field("inline_geo", inline_geo_); }
    if (var0 & 16) { s.store_field("inline_feedback", inline_feedback_); }
    if (var0 & 32) { s.store_field("nochats", nochats_); }
    if (var0 & 64) { s.store_field("chat_history", chat_history_); }
    if (var0 & 128) { s.store_field("business", business_); }
    if (var0 & 256) { s.store_field("can_manage_bots", can_manage_bots_); }
    if (var0 & 512) { s.store_field("guestchat", guestchat_); }
    if (var0 & 1024) { s.store_field("guard", guard_); }
    if (var0 & 2048) { s.store_field("forum_view", forum_view_); }
    if (var0 & 4096) { s.store_field("forum_can_manage_topics", forum_can_manage_topics_); }
    if (var0 & 8192) { s.store_field("forum_sidebar", forum_sidebar_); }
    if (var0 & 16384) { s.store_field("bot_to_bot_communication_mode", bot_to_bot_communication_mode_); }
    if (var0 & 32768) { s.store_field("callback_mode", callback_mode_); }
    s.store_class_end();
  }
}

bots_setBotSettings::ReturnType bots_setBotSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

channels_checkUsername::channels_checkUsername(object_ptr<InputChannel> &&channel_, string const &username_)
  : channel_(std::move(channel_))
  , username_(username_)
{}

const std::int32_t channels_checkUsername::ID;

void channels_checkUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(283557164);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
}

void channels_checkUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(283557164);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
}

void channels_checkUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.checkUsername");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("username", username_);
    s.store_class_end();
  }
}

channels_checkUsername::ReturnType channels_checkUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_getChannels::channels_getChannels(array<object_ptr<InputChannel>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t channels_getChannels::ID;

void channels_getChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(176122811);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void channels_getChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(176122811);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void channels_getChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getChannels");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_getChannels::ReturnType channels_getChannels::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

const std::int32_t channels_getGroupsForDiscussion::ID;

void channels_getGroupsForDiscussion::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-170208392);
}

void channels_getGroupsForDiscussion::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-170208392);
}

void channels_getGroupsForDiscussion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getGroupsForDiscussion");
    s.store_class_end();
  }
}

channels_getGroupsForDiscussion::ReturnType channels_getGroupsForDiscussion::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

channels_getSendAs::channels_getSendAs(int32 flags_, bool for_paid_reactions_, bool for_live_stories_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , for_paid_reactions_(for_paid_reactions_)
  , for_live_stories_(for_live_stories_)
  , peer_(std::move(peer_))
{}

const std::int32_t channels_getSendAs::ID;

void channels_getSendAs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-410672065);
  TlStoreBinary::store((var0 = flags_ | (for_paid_reactions_ << 0) | (for_live_stories_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void channels_getSendAs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-410672065);
  TlStoreBinary::store((var0 = flags_ | (for_paid_reactions_ << 0) | (for_live_stories_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void channels_getSendAs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getSendAs");
    s.store_field("flags", (var0 = flags_ | (for_paid_reactions_ << 0) | (for_live_stories_ << 1)));
    if (var0 & 1) { s.store_field("for_paid_reactions", true); }
    if (var0 & 2) { s.store_field("for_live_stories", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

channels_getSendAs::ReturnType channels_getSendAs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<channels_sendAsPeers>, -191450938>::parse(p);
#undef FAIL
}

channels_reorderUsernames::channels_reorderUsernames(object_ptr<InputChannel> &&channel_, array<string> &&order_)
  : channel_(std::move(channel_))
  , order_(std::move(order_))
{}

const std::int32_t channels_reorderUsernames::ID;

void channels_reorderUsernames::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1268978403);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void channels_reorderUsernames::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1268978403);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void channels_reorderUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.reorderUsernames");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_reorderUsernames::ReturnType channels_reorderUsernames::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_reportAntiSpamFalsePositive::channels_reportAntiSpamFalsePositive(object_ptr<InputChannel> &&channel_, int32 msg_id_)
  : channel_(std::move(channel_))
  , msg_id_(msg_id_)
{}

const std::int32_t channels_reportAntiSpamFalsePositive::ID;

void channels_reportAntiSpamFalsePositive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1471109485);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void channels_reportAntiSpamFalsePositive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1471109485);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void channels_reportAntiSpamFalsePositive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.reportAntiSpamFalsePositive");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

channels_reportAntiSpamFalsePositive::ReturnType channels_reportAntiSpamFalsePositive::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_restrictSponsoredMessages::channels_restrictSponsoredMessages(object_ptr<InputChannel> &&channel_, bool restricted_)
  : channel_(std::move(channel_))
  , restricted_(restricted_)
{}

const std::int32_t channels_restrictSponsoredMessages::ID;

void channels_restrictSponsoredMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1696000743);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(restricted_, s);
}

void channels_restrictSponsoredMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1696000743);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(restricted_, s);
}

void channels_restrictSponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.restrictSponsoredMessages");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("restricted", restricted_);
    s.store_class_end();
  }
}

channels_restrictSponsoredMessages::ReturnType channels_restrictSponsoredMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_setBoostsToUnblockRestrictions::channels_setBoostsToUnblockRestrictions(object_ptr<InputChannel> &&channel_, int32 boosts_)
  : channel_(std::move(channel_))
  , boosts_(boosts_)
{}

const std::int32_t channels_setBoostsToUnblockRestrictions::ID;

void channels_setBoostsToUnblockRestrictions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1388733202);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(boosts_, s);
}

void channels_setBoostsToUnblockRestrictions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1388733202);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(boosts_, s);
}

void channels_setBoostsToUnblockRestrictions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.setBoostsToUnblockRestrictions");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("boosts", boosts_);
    s.store_class_end();
  }
}

channels_setBoostsToUnblockRestrictions::ReturnType channels_setBoostsToUnblockRestrictions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_toggleParticipantsHidden::channels_toggleParticipantsHidden(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_toggleParticipantsHidden::ID;

void channels_toggleParticipantsHidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1785624660);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleParticipantsHidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1785624660);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleParticipantsHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleParticipantsHidden");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_toggleParticipantsHidden::ReturnType channels_toggleParticipantsHidden::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_toggleUsername::channels_toggleUsername(object_ptr<InputChannel> &&channel_, string const &username_, bool active_)
  : channel_(std::move(channel_))
  , username_(username_)
  , active_(active_)
{}

const std::int32_t channels_toggleUsername::ID;

void channels_toggleUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1358053637);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void channels_toggleUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1358053637);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void channels_toggleUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleUsername");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("username", username_);
    s.store_field("active", active_);
    s.store_class_end();
  }
}

channels_toggleUsername::ReturnType channels_toggleUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_updateUsername::channels_updateUsername(object_ptr<InputChannel> &&channel_, string const &username_)
  : channel_(std::move(channel_))
  , username_(username_)
{}

const std::int32_t channels_updateUsername::ID;

void channels_updateUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(890549214);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
}

void channels_updateUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(890549214);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
}

void channels_updateUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.updateUsername");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("username", username_);
    s.store_class_end();
  }
}

channels_updateUsername::ReturnType channels_updateUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

chatlists_exportChatlistInvite::chatlists_exportChatlistInvite(object_ptr<inputChatlistDialogFilter> &&chatlist_, string const &title_, array<object_ptr<InputPeer>> &&peers_)
  : chatlist_(std::move(chatlist_))
  , title_(title_)
  , peers_(std::move(peers_))
{}

const std::int32_t chatlists_exportChatlistInvite::ID;

void chatlists_exportChatlistInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2072885362);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_exportChatlistInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2072885362);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_exportChatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.exportChatlistInvite");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_field("title", title_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatlists_exportChatlistInvite::ReturnType chatlists_exportChatlistInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<chatlists_exportedChatlistInvite>, 283567014>::parse(p);
#undef FAIL
}

contacts_deleteByPhones::contacts_deleteByPhones(array<string> &&phones_)
  : phones_(std::move(phones_))
{}

const std::int32_t contacts_deleteByPhones::ID;

void contacts_deleteByPhones::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(269745566);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(phones_, s);
}

void contacts_deleteByPhones::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(269745566);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(phones_, s);
}

void contacts_deleteByPhones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.deleteByPhones");
    { s.store_vector_begin("phones", phones_.size()); for (const auto &_value : phones_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

contacts_deleteByPhones::ReturnType contacts_deleteByPhones::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t contacts_getStatuses::ID;

void contacts_getStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-995929106);
}

void contacts_getStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-995929106);
}

void contacts_getStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getStatuses");
    s.store_class_end();
  }
}

contacts_getStatuses::ReturnType contacts_getStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<contactStatus>, 383348795>>, 481674261>::parse(p);
#undef FAIL
}

contacts_getTopPeers::contacts_getTopPeers(int32 flags_, bool correspondents_, bool bots_pm_, bool bots_inline_, bool phone_calls_, bool forward_users_, bool forward_chats_, bool groups_, bool channels_, bool bots_app_, bool bots_guestchat_, int32 offset_, int32 limit_, int64 hash_)
  : flags_(flags_)
  , correspondents_(correspondents_)
  , bots_pm_(bots_pm_)
  , bots_inline_(bots_inline_)
  , phone_calls_(phone_calls_)
  , forward_users_(forward_users_)
  , forward_chats_(forward_chats_)
  , groups_(groups_)
  , channels_(channels_)
  , bots_app_(bots_app_)
  , bots_guestchat_(bots_guestchat_)
  , offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t contacts_getTopPeers::ID;

void contacts_getTopPeers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1758168906);
  TlStoreBinary::store((var0 = flags_ | (correspondents_ << 0) | (bots_pm_ << 1) | (bots_inline_ << 2) | (phone_calls_ << 3) | (forward_users_ << 4) | (forward_chats_ << 5) | (groups_ << 10) | (channels_ << 15) | (bots_app_ << 16) | (bots_guestchat_ << 17)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void contacts_getTopPeers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1758168906);
  TlStoreBinary::store((var0 = flags_ | (correspondents_ << 0) | (bots_pm_ << 1) | (bots_inline_ << 2) | (phone_calls_ << 3) | (forward_users_ << 4) | (forward_chats_ << 5) | (groups_ << 10) | (channels_ << 15) | (bots_app_ << 16) | (bots_guestchat_ << 17)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void contacts_getTopPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getTopPeers");
    s.store_field("flags", (var0 = flags_ | (correspondents_ << 0) | (bots_pm_ << 1) | (bots_inline_ << 2) | (phone_calls_ << 3) | (forward_users_ << 4) | (forward_chats_ << 5) | (groups_ << 10) | (channels_ << 15) | (bots_app_ << 16) | (bots_guestchat_ << 17)));
    if (var0 & 1) { s.store_field("correspondents", true); }
    if (var0 & 2) { s.store_field("bots_pm", true); }
    if (var0 & 4) { s.store_field("bots_inline", true); }
    if (var0 & 8) { s.store_field("phone_calls", true); }
    if (var0 & 16) { s.store_field("forward_users", true); }
    if (var0 & 32) { s.store_field("forward_chats", true); }
    if (var0 & 1024) { s.store_field("groups", true); }
    if (var0 & 32768) { s.store_field("channels", true); }
    if (var0 & 65536) { s.store_field("bots_app", true); }
    if (var0 & 131072) { s.store_field("bots_guestchat", true); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

contacts_getTopPeers::ReturnType contacts_getTopPeers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<contacts_TopPeers>::parse(p);
#undef FAIL
}

contacts_importContactToken::contacts_importContactToken(string const &token_)
  : token_(token_)
{}

const std::int32_t contacts_importContactToken::ID;

void contacts_importContactToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(318789512);
  TlStoreString::store(token_, s);
}

void contacts_importContactToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(318789512);
  TlStoreString::store(token_, s);
}

void contacts_importContactToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.importContactToken");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

contacts_importContactToken::ReturnType contacts_importContactToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

contacts_search::contacts_search(int32 flags_, bool broadcasts_, bool bots_, string const &q_, int32 limit_)
  : flags_(flags_)
  , broadcasts_(broadcasts_)
  , bots_(bots_)
  , q_(q_)
  , limit_(limit_)
{}

const std::int32_t contacts_search::ID;

void contacts_search::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(99978511);
  TlStoreBinary::store((var0 = flags_ | (broadcasts_ << 0) | (bots_ << 1)), s);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_search::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(99978511);
  TlStoreBinary::store((var0 = flags_ | (broadcasts_ << 0) | (bots_ << 1)), s);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_search::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.search");
    s.store_field("flags", (var0 = flags_ | (broadcasts_ << 0) | (bots_ << 1)));
    if (var0 & 1) { s.store_field("broadcasts", true); }
    if (var0 & 2) { s.store_field("bots", true); }
    s.store_field("q", q_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

contacts_search::ReturnType contacts_search::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<contacts_found>, -1290580579>::parse(p);
#undef FAIL
}

help_acceptTermsOfService::help_acceptTermsOfService(object_ptr<dataJSON> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t help_acceptTermsOfService::ID;

void help_acceptTermsOfService::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-294455398);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(id_, s);
}

void help_acceptTermsOfService::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-294455398);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(id_, s);
}

void help_acceptTermsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.acceptTermsOfService");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

help_acceptTermsOfService::ReturnType help_acceptTermsOfService::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t help_getCdnConfig::ID;

void help_getCdnConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1375900482);
}

void help_getCdnConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1375900482);
}

void help_getCdnConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getCdnConfig");
    s.store_class_end();
  }
}

help_getCdnConfig::ReturnType help_getCdnConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<cdnConfig>, 1462101002>::parse(p);
#undef FAIL
}

const std::int32_t help_getTermsOfServiceUpdate::ID;

void help_getTermsOfServiceUpdate::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(749019089);
}

void help_getTermsOfServiceUpdate::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(749019089);
}

void help_getTermsOfServiceUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getTermsOfServiceUpdate");
    s.store_class_end();
  }
}

help_getTermsOfServiceUpdate::ReturnType help_getTermsOfServiceUpdate::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_TermsOfServiceUpdate>::parse(p);
#undef FAIL
}

help_getUserInfo::help_getUserInfo(object_ptr<InputUser> &&user_id_)
  : user_id_(std::move(user_id_))
{}

const std::int32_t help_getUserInfo::ID;

void help_getUserInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(59377875);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void help_getUserInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(59377875);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void help_getUserInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getUserInfo");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

help_getUserInfo::ReturnType help_getUserInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_UserInfo>::parse(p);
#undef FAIL
}

invokeWithGooglePlayIntegrityPrefix::invokeWithGooglePlayIntegrityPrefix(string const &nonce_, string const &token_)
  : nonce_(nonce_)
  , token_(token_)
{}

const std::int32_t invokeWithGooglePlayIntegrityPrefix::ID;

void invokeWithGooglePlayIntegrityPrefix::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(502868356);
  TlStoreString::store(nonce_, s);
  TlStoreString::store(token_, s);
}

void invokeWithGooglePlayIntegrityPrefix::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(502868356);
  TlStoreString::store(nonce_, s);
  TlStoreString::store(token_, s);
}

void invokeWithGooglePlayIntegrityPrefix::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invokeWithGooglePlayIntegrityPrefix");
    s.store_field("nonce", nonce_);
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

invokeWithGooglePlayIntegrityPrefix::ReturnType invokeWithGooglePlayIntegrityPrefix::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<error>, -994444869>::parse(p);
#undef FAIL
}

langpack_getLangPack::langpack_getLangPack(string const &lang_pack_, string const &lang_code_)
  : lang_pack_(lang_pack_)
  , lang_code_(lang_code_)
{}

const std::int32_t langpack_getLangPack::ID;

void langpack_getLangPack::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-219008246);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
}

void langpack_getLangPack::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-219008246);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
}

void langpack_getLangPack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langpack.getLangPack");
    s.store_field("lang_pack", lang_pack_);
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

langpack_getLangPack::ReturnType langpack_getLangPack::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<langPackDifference>, -209337866>::parse(p);
#undef FAIL
}

messages_acceptEncryption::messages_acceptEncryption(object_ptr<inputEncryptedChat> &&peer_, bytes &&g_b_, int64 key_fingerprint_)
  : peer_(std::move(peer_))
  , g_b_(std::move(g_b_))
  , key_fingerprint_(key_fingerprint_)
{}

const std::int32_t messages_acceptEncryption::ID;

void messages_acceptEncryption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1035731989);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreString::store(g_b_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void messages_acceptEncryption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1035731989);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreString::store(g_b_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void messages_acceptEncryption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.acceptEncryption");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_bytes_field("g_b", g_b_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_class_end();
  }
}

messages_acceptEncryption::ReturnType messages_acceptEncryption::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EncryptedChat>::parse(p);
#undef FAIL
}

const std::int32_t messages_clearAllDrafts::ID;

void messages_clearAllDrafts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2119757468);
}

void messages_clearAllDrafts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2119757468);
}

void messages_clearAllDrafts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.clearAllDrafts");
    s.store_class_end();
  }
}

messages_clearAllDrafts::ReturnType messages_clearAllDrafts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_createForumTopic::messages_createForumTopic(int32 flags_, bool title_missing_, object_ptr<InputPeer> &&peer_, string const &title_, int32 icon_color_, int64 icon_emoji_id_, int64 random_id_, object_ptr<InputPeer> &&send_as_)
  : flags_(flags_)
  , title_missing_(title_missing_)
  , peer_(std::move(peer_))
  , title_(title_)
  , icon_color_(icon_color_)
  , icon_emoji_id_(icon_emoji_id_)
  , random_id_(random_id_)
  , send_as_(std::move(send_as_))
{}

const std::int32_t messages_createForumTopic::ID;

void messages_createForumTopic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(798540757);
  TlStoreBinary::store((var0 = flags_ | (title_missing_ << 4) | ((send_as_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  if (var0 & 1) { TlStoreBinary::store(icon_color_, s); }
  if (var0 & 8) { TlStoreBinary::store(icon_emoji_id_, s); }
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_createForumTopic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(798540757);
  TlStoreBinary::store((var0 = flags_ | (title_missing_ << 4) | ((send_as_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  if (var0 & 1) { TlStoreBinary::store(icon_color_, s); }
  if (var0 & 8) { TlStoreBinary::store(icon_emoji_id_, s); }
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_createForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.createForumTopic");
    s.store_field("flags", (var0 = flags_ | (title_missing_ << 4) | ((send_as_ != nullptr) << 2)));
    if (var0 & 16) { s.store_field("title_missing", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("title", title_);
    if (var0 & 1) { s.store_field("icon_color", icon_color_); }
    if (var0 & 8) { s.store_field("icon_emoji_id", icon_emoji_id_); }
    s.store_field("random_id", random_id_);
    if (var0 & 4) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    s.store_class_end();
  }
}

messages_createForumTopic::ReturnType messages_createForumTopic::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_deleteChatUser::messages_deleteChatUser(int32 flags_, bool revoke_history_, int64 chat_id_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , revoke_history_(revoke_history_)
  , chat_id_(chat_id_)
  , user_id_(std::move(user_id_))
{}

const std::int32_t messages_deleteChatUser::ID;

void messages_deleteChatUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1575461717);
  TlStoreBinary::store((var0 = flags_ | (revoke_history_ << 0)), s);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_deleteChatUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1575461717);
  TlStoreBinary::store((var0 = flags_ | (revoke_history_ << 0)), s);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_deleteChatUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteChatUser");
    s.store_field("flags", (var0 = flags_ | (revoke_history_ << 0)));
    if (var0 & 1) { s.store_field("revoke_history", true); }
    s.store_field("chat_id", chat_id_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

messages_deleteChatUser::ReturnType messages_deleteChatUser::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_deleteParticipantReaction::messages_deleteParticipantReaction(object_ptr<InputPeer> &&peer_, int32 msg_id_, object_ptr<InputPeer> &&participant_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , participant_(std::move(participant_))
{}

const std::int32_t messages_deleteParticipantReaction::ID;

void messages_deleteParticipantReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-474482644);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void messages_deleteParticipantReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-474482644);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void messages_deleteParticipantReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteParticipantReaction");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

messages_deleteParticipantReaction::ReturnType messages_deleteParticipantReaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_deletePhoneCallHistory::messages_deletePhoneCallHistory(int32 flags_, bool revoke_)
  : flags_(flags_)
  , revoke_(revoke_)
{}

const std::int32_t messages_deletePhoneCallHistory::ID;

void messages_deletePhoneCallHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-104078327);
  TlStoreBinary::store((var0 = flags_ | (revoke_ << 0)), s);
}

void messages_deletePhoneCallHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-104078327);
  TlStoreBinary::store((var0 = flags_ | (revoke_ << 0)), s);
}

void messages_deletePhoneCallHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deletePhoneCallHistory");
    s.store_field("flags", (var0 = flags_ | (revoke_ << 0)));
    if (var0 & 1) { s.store_field("revoke", true); }
    s.store_class_end();
  }
}

messages_deletePhoneCallHistory::ReturnType messages_deletePhoneCallHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedFoundMessages>, -275956116>::parse(p);
#undef FAIL
}

messages_deletePollAnswer::messages_deletePollAnswer(object_ptr<InputPeer> &&peer_, int32 msg_id_, bytes &&option_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , option_(std::move(option_))
{}

const std::int32_t messages_deletePollAnswer::ID;

void messages_deletePollAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1400568411);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(option_, s);
}

void messages_deletePollAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1400568411);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(option_, s);
}

void messages_deletePollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deletePollAnswer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_bytes_field("option", option_);
    s.store_class_end();
  }
}

messages_deletePollAnswer::ReturnType messages_deletePollAnswer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_deleteQuickReplyMessages::messages_deleteQuickReplyMessages(int32 shortcut_id_, array<int32> &&id_)
  : shortcut_id_(shortcut_id_)
  , id_(std::move(id_))
{}

const std::int32_t messages_deleteQuickReplyMessages::ID;

void messages_deleteQuickReplyMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-519706352);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteQuickReplyMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-519706352);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteQuickReplyMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteQuickReplyMessages");
    s.store_field("shortcut_id", shortcut_id_);
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_deleteQuickReplyMessages::ReturnType messages_deleteQuickReplyMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_deleteRevokedExportedChatInvites::messages_deleteRevokedExportedChatInvites(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&admin_id_)
  : peer_(std::move(peer_))
  , admin_id_(std::move(admin_id_))
{}

const std::int32_t messages_deleteRevokedExportedChatInvites::ID;

void messages_deleteRevokedExportedChatInvites::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1452833749);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(admin_id_, s);
}

void messages_deleteRevokedExportedChatInvites::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1452833749);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(admin_id_, s);
}

void messages_deleteRevokedExportedChatInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteRevokedExportedChatInvites");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("admin_id", static_cast<const BaseObject *>(admin_id_.get()));
    s.store_class_end();
  }
}

messages_deleteRevokedExportedChatInvites::ReturnType messages_deleteRevokedExportedChatInvites::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_editInlineBotMessageWidgetData::messages_editInlineBotMessageWidgetData(int32 flags_, object_ptr<InputBotInlineMessageID> &&id_, string const &public_data_, string const &chat_data_)
  : flags_(flags_)
  , id_(std::move(id_))
  , public_data_(public_data_)
  , chat_data_(chat_data_)
{}

const std::int32_t messages_editInlineBotMessageWidgetData::ID;

void messages_editInlineBotMessageWidgetData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1670827563);
  TlStoreBinary::store((var0 = flags_ | ((!public_data_.empty()) << 0) | ((!chat_data_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 1) { TlStoreString::store(public_data_, s); }
  if (var0 & 2) { TlStoreString::store(chat_data_, s); }
}

void messages_editInlineBotMessageWidgetData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1670827563);
  TlStoreBinary::store((var0 = flags_ | ((!public_data_.empty()) << 0) | ((!chat_data_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 1) { TlStoreString::store(public_data_, s); }
  if (var0 & 2) { TlStoreString::store(chat_data_, s); }
}

void messages_editInlineBotMessageWidgetData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editInlineBotMessageWidgetData");
    s.store_field("flags", (var0 = flags_ | ((!public_data_.empty()) << 0) | ((!chat_data_.empty()) << 1)));
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    if (var0 & 1) { s.store_field("public_data", public_data_); }
    if (var0 & 2) { s.store_field("chat_data", chat_data_); }
    s.store_class_end();
  }
}

messages_editInlineBotMessageWidgetData::ReturnType messages_editInlineBotMessageWidgetData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_getBotApp::messages_getBotApp(object_ptr<InputBotApp> &&app_, int64 hash_)
  : app_(std::move(app_))
  , hash_(hash_)
{}

const std::int32_t messages_getBotApp::ID;

void messages_getBotApp::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(889046467);
  TlStoreBoxedUnknown<TlStoreObject>::store(app_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getBotApp::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(889046467);
  TlStoreBoxedUnknown<TlStoreObject>::store(app_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getBotApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getBotApp");
    s.store_object_field("app", static_cast<const BaseObject *>(app_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getBotApp::ReturnType messages_getBotApp::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_botApp>, -347034123>::parse(p);
#undef FAIL
}

messages_getDiscussionMessage::messages_getDiscussionMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_getDiscussionMessage::ID;

void messages_getDiscussionMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1147761405);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getDiscussionMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1147761405);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getDiscussionMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDiscussionMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

messages_getDiscussionMessage::ReturnType messages_getDiscussionMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_discussionMessage>, -1506535550>::parse(p);
#undef FAIL
}

messages_getEmojiStatusGroups::messages_getEmojiStatusGroups(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getEmojiStatusGroups::ID;

void messages_getEmojiStatusGroups::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(785209037);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStatusGroups::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(785209037);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStatusGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiStatusGroups");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getEmojiStatusGroups::ReturnType messages_getEmojiStatusGroups::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_EmojiGroups>::parse(p);
#undef FAIL
}

messages_getEmojiURL::messages_getEmojiURL(string const &lang_code_)
  : lang_code_(lang_code_)
{}

const std::int32_t messages_getEmojiURL::ID;

void messages_getEmojiURL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-709817306);
  TlStoreString::store(lang_code_, s);
}

void messages_getEmojiURL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-709817306);
  TlStoreString::store(lang_code_, s);
}

void messages_getEmojiURL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiURL");
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

messages_getEmojiURL::ReturnType messages_getEmojiURL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<emojiURL>, -1519029347>::parse(p);
#undef FAIL
}

messages_getInlineBotResults::messages_getInlineBotResults(int32 flags_, object_ptr<InputUser> &&bot_, object_ptr<InputPeer> &&peer_, object_ptr<InputGeoPoint> &&geo_point_, string const &query_, string const &offset_)
  : flags_(flags_)
  , bot_(std::move(bot_))
  , peer_(std::move(peer_))
  , geo_point_(std::move(geo_point_))
  , query_(query_)
  , offset_(offset_)
{}

const std::int32_t messages_getInlineBotResults::ID;

void messages_getInlineBotResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1364105629);
  TlStoreBinary::store((var0 = flags_ | ((geo_point_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  TlStoreString::store(query_, s);
  TlStoreString::store(offset_, s);
}

void messages_getInlineBotResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1364105629);
  TlStoreBinary::store((var0 = flags_ | ((geo_point_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  TlStoreString::store(query_, s);
  TlStoreString::store(offset_, s);
}

void messages_getInlineBotResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getInlineBotResults");
    s.store_field("flags", (var0 = flags_ | ((geo_point_ != nullptr) << 0)));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get())); }
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

messages_getInlineBotResults::ReturnType messages_getInlineBotResults::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_botResults>, -534646026>::parse(p);
#undef FAIL
}

messages_getSavedGifs::messages_getSavedGifs(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getSavedGifs::ID;

void messages_getSavedGifs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1559270965);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedGifs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1559270965);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedGifs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSavedGifs");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getSavedGifs::ReturnType messages_getSavedGifs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SavedGifs>::parse(p);
#undef FAIL
}

messages_hideAllChatJoinRequests::messages_hideAllChatJoinRequests(int32 flags_, bool approved_, object_ptr<InputPeer> &&peer_, string const &link_)
  : flags_(flags_)
  , approved_(approved_)
  , peer_(std::move(peer_))
  , link_(link_)
{}

const std::int32_t messages_hideAllChatJoinRequests::ID;

void messages_hideAllChatJoinRequests::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-528091926);
  TlStoreBinary::store((var0 = flags_ | (approved_ << 0) | ((!link_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(link_, s); }
}

void messages_hideAllChatJoinRequests::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-528091926);
  TlStoreBinary::store((var0 = flags_ | (approved_ << 0) | ((!link_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(link_, s); }
}

void messages_hideAllChatJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.hideAllChatJoinRequests");
    s.store_field("flags", (var0 = flags_ | (approved_ << 0) | ((!link_.empty()) << 1)));
    if (var0 & 1) { s.store_field("approved", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_field("link", link_); }
    s.store_class_end();
  }
}

messages_hideAllChatJoinRequests::ReturnType messages_hideAllChatJoinRequests::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_prolongWebView::messages_prolongWebView(int32 flags_, bool silent_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&bot_, int64 query_id_, object_ptr<InputReplyTo> &&reply_to_, object_ptr<InputPeer> &&send_as_)
  : flags_(flags_)
  , silent_(silent_)
  , peer_(std::move(peer_))
  , bot_(std::move(bot_))
  , query_id_(query_id_)
  , reply_to_(std::move(reply_to_))
  , send_as_(std::move(send_as_))
{}

const std::int32_t messages_prolongWebView::ID;

void messages_prolongWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1328014717);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_prolongWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1328014717);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_prolongWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.prolongWebView");
    s.store_field("flags", (var0 = flags_ | (silent_ << 5) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13)));
    if (var0 & 32) { s.store_field("silent", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("query_id", query_id_);
    if (var0 & 1) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    s.store_class_end();
  }
}

messages_prolongWebView::ReturnType messages_prolongWebView::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_readHistory::messages_readHistory(object_ptr<InputPeer> &&peer_, int32 max_id_)
  : peer_(std::move(peer_))
  , max_id_(max_id_)
{}

const std::int32_t messages_readHistory::ID;

void messages_readHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(238054714);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void messages_readHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(238054714);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void messages_readHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readHistory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

messages_readHistory::ReturnType messages_readHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedMessages>, -2066640507>::parse(p);
#undef FAIL
}

messages_readReactions::messages_readReactions(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, object_ptr<InputPeer> &&saved_peer_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , saved_peer_id_(std::move(saved_peer_id_))
{}

const std::int32_t messages_readReactions::ID;

void messages_readReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1631301741);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
}

void messages_readReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1631301741);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
}

void messages_readReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readReactions");
    s.store_field("flags", (var0 = flags_ | ((saved_peer_id_ != nullptr) << 1)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_class_end();
  }
}

messages_readReactions::ReturnType messages_readReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_reportMessagesDelivery::messages_reportMessagesDelivery(int32 flags_, bool push_, object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : flags_(flags_)
  , push_(push_)
  , peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_reportMessagesDelivery::ID;

void messages_reportMessagesDelivery::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1517122453);
  TlStoreBinary::store((var0 = flags_ | (push_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_reportMessagesDelivery::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1517122453);
  TlStoreBinary::store((var0 = flags_ | (push_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_reportMessagesDelivery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportMessagesDelivery");
    s.store_field("flags", (var0 = flags_ | (push_ << 0)));
    if (var0 & 1) { s.store_field("push", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reportMessagesDelivery::ReturnType messages_reportMessagesDelivery::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_requestChatJoinWebView::messages_requestChatJoinWebView(int32 flags_, int64 query_id_, object_ptr<dataJSON> &&theme_params_, string const &platform_)
  : flags_(flags_)
  , query_id_(query_id_)
  , theme_params_(std::move(theme_params_))
  , platform_(platform_)
{}

const std::int32_t messages_requestChatJoinWebView::ID;

void messages_requestChatJoinWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1163991431);
  TlStoreBinary::store((var0 = flags_ | ((theme_params_ != nullptr) << 0)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestChatJoinWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1163991431);
  TlStoreBinary::store((var0 = flags_ | ((theme_params_ != nullptr) << 0)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestChatJoinWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestChatJoinWebView");
    s.store_field("flags", (var0 = flags_ | ((theme_params_ != nullptr) << 0)));
    s.store_field("query_id", query_id_);
    if (var0 & 1) { s.store_object_field("theme_params", static_cast<const BaseObject *>(theme_params_.get())); }
    s.store_field("platform", platform_);
    s.store_class_end();
  }
}

messages_requestChatJoinWebView::ReturnType messages_requestChatJoinWebView::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<webViewResultUrl>, 1294139288>::parse(p);
#undef FAIL
}

messages_searchEmojiStickerSets::messages_searchEmojiStickerSets(int32 flags_, bool exclude_featured_, string const &q_, int64 hash_)
  : flags_(flags_)
  , exclude_featured_(exclude_featured_)
  , q_(q_)
  , hash_(hash_)
{}

const std::int32_t messages_searchEmojiStickerSets::ID;

void messages_searchEmojiStickerSets::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1833678516);
  TlStoreBinary::store((var0 = flags_ | (exclude_featured_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchEmojiStickerSets::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1833678516);
  TlStoreBinary::store((var0 = flags_ | (exclude_featured_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchEmojiStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchEmojiStickerSets");
    s.store_field("flags", (var0 = flags_ | (exclude_featured_ << 0)));
    if (var0 & 1) { s.store_field("exclude_featured", true); }
    s.store_field("q", q_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_searchEmojiStickerSets::ReturnType messages_searchEmojiStickerSets::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FoundStickerSets>::parse(p);
#undef FAIL
}

messages_sendInlineBotResult::messages_sendInlineBotResult(int32 flags_, bool silent_, bool background_, bool clear_draft_, bool hide_via_, object_ptr<InputPeer> &&peer_, object_ptr<InputReplyTo> &&reply_to_, int64 random_id_, int64 query_id_, string const &id_, int32 schedule_date_, object_ptr<InputPeer> &&send_as_, object_ptr<InputQuickReplyShortcut> &&quick_reply_shortcut_, int64 allow_paid_stars_)
  : flags_(flags_)
  , silent_(silent_)
  , background_(background_)
  , clear_draft_(clear_draft_)
  , hide_via_(hide_via_)
  , peer_(std::move(peer_))
  , reply_to_(std::move(reply_to_))
  , random_id_(random_id_)
  , query_id_(query_id_)
  , id_(id_)
  , schedule_date_(schedule_date_)
  , send_as_(std::move(send_as_))
  , quick_reply_shortcut_(std::move(quick_reply_shortcut_))
  , allow_paid_stars_(allow_paid_stars_)
{}

const std::int32_t messages_sendInlineBotResult::ID;

void messages_sendInlineBotResult::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1060145594);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (hide_via_ << 11) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(id_, s);
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void messages_sendInlineBotResult::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1060145594);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (hide_via_ << 11) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(id_, s);
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void messages_sendInlineBotResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendInlineBotResult");
    s.store_field("flags", (var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (hide_via_ << 11) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17)));
    if (var0 & 32) { s.store_field("silent", true); }
    if (var0 & 64) { s.store_field("background", true); }
    if (var0 & 128) { s.store_field("clear_draft", true); }
    if (var0 & 2048) { s.store_field("hide_via", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_field("random_id", random_id_);
    s.store_field("query_id", query_id_);
    s.store_field("id", id_);
    if (var0 & 1024) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    if (var0 & 131072) { s.store_object_field("quick_reply_shortcut", static_cast<const BaseObject *>(quick_reply_shortcut_.get())); }
    if (var0 & 2097152) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    s.store_class_end();
  }
}

messages_sendInlineBotResult::ReturnType messages_sendInlineBotResult::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_sendMultiMedia::messages_sendMultiMedia(int32 flags_, bool silent_, bool background_, bool clear_draft_, bool noforwards_, bool update_stickersets_order_, bool invert_media_, bool allow_paid_floodskip_, object_ptr<InputPeer> &&peer_, object_ptr<InputReplyTo> &&reply_to_, array<object_ptr<inputSingleMedia>> &&multi_media_, int32 schedule_date_, object_ptr<InputPeer> &&send_as_, object_ptr<InputQuickReplyShortcut> &&quick_reply_shortcut_, int64 effect_, int64 allow_paid_stars_)
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
  , multi_media_(std::move(multi_media_))
  , schedule_date_(schedule_date_)
  , send_as_(std::move(send_as_))
  , quick_reply_shortcut_(std::move(quick_reply_shortcut_))
  , effect_(effect_)
  , allow_paid_stars_(allow_paid_stars_)
{}

const std::int32_t messages_sendMultiMedia::ID;

void messages_sendMultiMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(469278068);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 482797855>>, 481674261>::store(multi_media_, s);
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void messages_sendMultiMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(469278068);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 482797855>>, 481674261>::store(multi_media_, s);
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void messages_sendMultiMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendMultiMedia");
    s.store_field("flags", (var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19) | ((reply_to_ != nullptr) << 0) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17)));
    if (var0 & 32) { s.store_field("silent", true); }
    if (var0 & 64) { s.store_field("background", true); }
    if (var0 & 128) { s.store_field("clear_draft", true); }
    if (var0 & 16384) { s.store_field("noforwards", true); }
    if (var0 & 32768) { s.store_field("update_stickersets_order", true); }
    if (var0 & 65536) { s.store_field("invert_media", true); }
    if (var0 & 524288) { s.store_field("allow_paid_floodskip", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    { s.store_vector_begin("multi_media", multi_media_.size()); for (const auto &_value : multi_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1024) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    if (var0 & 131072) { s.store_object_field("quick_reply_shortcut", static_cast<const BaseObject *>(quick_reply_shortcut_.get())); }
    if (var0 & 262144) { s.store_field("effect", effect_); }
    if (var0 & 2097152) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    s.store_class_end();
  }
}

messages_sendMultiMedia::ReturnType messages_sendMultiMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setTyping::messages_setTyping(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, object_ptr<SendMessageAction> &&action_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , action_(std::move(action_))
{}

const std::int32_t messages_setTyping::ID;

void messages_setTyping::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1486110434);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(action_, s);
}

void messages_setTyping::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1486110434);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(action_, s);
}

void messages_setTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setTyping");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

messages_setTyping::ReturnType messages_setTyping::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_applyGiftCode::payments_applyGiftCode(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t payments_applyGiftCode::ID;

void payments_applyGiftCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-152934316);
  TlStoreString::store(slug_, s);
}

void payments_applyGiftCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-152934316);
  TlStoreString::store(slug_, s);
}

void payments_applyGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.applyGiftCode");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

payments_applyGiftCode::ReturnType payments_applyGiftCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_changeStarsSubscription::payments_changeStarsSubscription(int32 flags_, object_ptr<InputPeer> &&peer_, string const &subscription_id_, bool canceled_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , subscription_id_(subscription_id_)
  , canceled_(canceled_)
{}

const std::int32_t payments_changeStarsSubscription::ID;

void payments_changeStarsSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-948500360);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(subscription_id_, s);
  if (var0 & 1) { TlStoreBool::store(canceled_, s); }
}

void payments_changeStarsSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-948500360);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(subscription_id_, s);
  if (var0 & 1) { TlStoreBool::store(canceled_, s); }
}

void payments_changeStarsSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.changeStarsSubscription");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("subscription_id", subscription_id_);
    if (var0 & 1) { s.store_field("canceled", canceled_); }
    s.store_class_end();
  }
}

payments_changeStarsSubscription::ReturnType payments_changeStarsSubscription::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_displayStarGift::payments_displayStarGift(int32 flags_, object_ptr<InputPeer> &&peer_, string const &slug_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , slug_(slug_)
{}

const std::int32_t payments_displayStarGift::ID;

void payments_displayStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1252389118);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreString::store(slug_, s);
}

void payments_displayStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1252389118);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreString::store(slug_, s);
}

void payments_displayStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.displayStarGift");
    s.store_field("flags", (var0 = flags_ | ((peer_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

payments_displayStarGift::ReturnType payments_displayStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_getBankCardData::payments_getBankCardData(string const &number_)
  : number_(number_)
{}

const std::int32_t payments_getBankCardData::ID;

void payments_getBankCardData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(779736953);
  TlStoreString::store(number_, s);
}

void payments_getBankCardData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(779736953);
  TlStoreString::store(number_, s);
}

void payments_getBankCardData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getBankCardData");
    s.store_field("number", number_);
    s.store_class_end();
  }
}

payments_getBankCardData::ReturnType payments_getBankCardData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_bankCardData>, 1042605427>::parse(p);
#undef FAIL
}

payments_getCraftStarGifts::payments_getCraftStarGifts(int64 gift_id_, string const &offset_, int32 limit_)
  : gift_id_(gift_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t payments_getCraftStarGifts::ID;

void payments_getCraftStarGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-49947392);
  TlStoreBinary::store(gift_id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getCraftStarGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-49947392);
  TlStoreBinary::store(gift_id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getCraftStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getCraftStarGifts");
    s.store_field("gift_id", gift_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getCraftStarGifts::ReturnType payments_getCraftStarGifts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_savedStarGifts>, -1779201615>::parse(p);
#undef FAIL
}

payments_sendPaymentForm::payments_sendPaymentForm(int32 flags_, int64 form_id_, object_ptr<InputInvoice> &&invoice_, string const &requested_info_id_, string const &shipping_option_id_, object_ptr<InputPaymentCredentials> &&credentials_, int64 tip_amount_)
  : flags_(flags_)
  , form_id_(form_id_)
  , invoice_(std::move(invoice_))
  , requested_info_id_(requested_info_id_)
  , shipping_option_id_(shipping_option_id_)
  , credentials_(std::move(credentials_))
  , tip_amount_(tip_amount_)
{}

const std::int32_t payments_sendPaymentForm::ID;

void payments_sendPaymentForm::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(755192367);
  TlStoreBinary::store((var0 = flags_ | ((!requested_info_id_.empty()) << 0) | ((!shipping_option_id_.empty()) << 1)), s);
  TlStoreBinary::store(form_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  if (var0 & 1) { TlStoreString::store(requested_info_id_, s); }
  if (var0 & 2) { TlStoreString::store(shipping_option_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(credentials_, s);
  if (var0 & 4) { TlStoreBinary::store(tip_amount_, s); }
}

void payments_sendPaymentForm::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(755192367);
  TlStoreBinary::store((var0 = flags_ | ((!requested_info_id_.empty()) << 0) | ((!shipping_option_id_.empty()) << 1)), s);
  TlStoreBinary::store(form_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  if (var0 & 1) { TlStoreString::store(requested_info_id_, s); }
  if (var0 & 2) { TlStoreString::store(shipping_option_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(credentials_, s);
  if (var0 & 4) { TlStoreBinary::store(tip_amount_, s); }
}

void payments_sendPaymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.sendPaymentForm");
    s.store_field("flags", (var0 = flags_ | ((!requested_info_id_.empty()) << 0) | ((!shipping_option_id_.empty()) << 1)));
    s.store_field("form_id", form_id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    if (var0 & 1) { s.store_field("requested_info_id", requested_info_id_); }
    if (var0 & 2) { s.store_field("shipping_option_id", shipping_option_id_); }
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    if (var0 & 4) { s.store_field("tip_amount", tip_amount_); }
    s.store_class_end();
  }
}

payments_sendPaymentForm::ReturnType payments_sendPaymentForm::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_PaymentResult>::parse(p);
#undef FAIL
}

payments_toggleChatStarGiftNotifications::payments_toggleChatStarGiftNotifications(int32 flags_, bool enabled_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , enabled_(enabled_)
  , peer_(std::move(peer_))
{}

const std::int32_t payments_toggleChatStarGiftNotifications::ID;

void payments_toggleChatStarGiftNotifications::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1626009505);
  TlStoreBinary::store((var0 = flags_ | (enabled_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_toggleChatStarGiftNotifications::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1626009505);
  TlStoreBinary::store((var0 = flags_ | (enabled_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_toggleChatStarGiftNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.toggleChatStarGiftNotifications");
    s.store_field("flags", (var0 = flags_ | (enabled_ << 0)));
    if (var0 & 1) { s.store_field("enabled", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

payments_toggleChatStarGiftNotifications::ReturnType payments_toggleChatStarGiftNotifications::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_createConferenceCall::phone_createConferenceCall(int32 flags_, bool muted_, bool video_stopped_, bool join_, int32 random_id_, UInt256 const &public_key_, bytes &&block_, object_ptr<dataJSON> &&params_)
  : flags_(flags_)
  , muted_(muted_)
  , video_stopped_(video_stopped_)
  , join_(join_)
  , random_id_(random_id_)
  , public_key_(public_key_)
  , block_(std::move(block_))
  , params_(std::move(params_))
{}

const std::int32_t phone_createConferenceCall::ID;

void phone_createConferenceCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2097431739);
  TlStoreBinary::store((var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2) | (join_ << 3) | ((!block_.empty()) << 3) | ((params_ != nullptr) << 3)), s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 8) { TlStoreBinary::store(public_key_, s); }
  if (var0 & 8) { TlStoreString::store(block_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s); }
}

void phone_createConferenceCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2097431739);
  TlStoreBinary::store((var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2) | (join_ << 3) | ((!block_.empty()) << 3) | ((params_ != nullptr) << 3)), s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 8) { TlStoreBinary::store(public_key_, s); }
  if (var0 & 8) { TlStoreString::store(block_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s); }
}

void phone_createConferenceCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.createConferenceCall");
    s.store_field("flags", (var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2) | (join_ << 3) | ((!block_.empty()) << 3) | ((params_ != nullptr) << 3)));
    if (var0 & 1) { s.store_field("muted", true); }
    if (var0 & 4) { s.store_field("video_stopped", true); }
    if (var0 & 8) { s.store_field("join", true); }
    s.store_field("random_id", random_id_);
    if (var0 & 8) { s.store_field("public_key", public_key_); }
    if (var0 & 8) { s.store_bytes_field("block", block_); }
    if (var0 & 8) { s.store_object_field("params", static_cast<const BaseObject *>(params_.get())); }
    s.store_class_end();
  }
}

phone_createConferenceCall::ReturnType phone_createConferenceCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_saveDefaultSendAs::phone_saveDefaultSendAs(object_ptr<InputGroupCall> &&call_, object_ptr<InputPeer> &&send_as_)
  : call_(std::move(call_))
  , send_as_(std::move(send_as_))
{}

const std::int32_t phone_saveDefaultSendAs::ID;

void phone_saveDefaultSendAs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1097313745);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s);
}

void phone_saveDefaultSendAs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1097313745);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s);
}

void phone_saveDefaultSendAs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.saveDefaultSendAs");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get()));
    s.store_class_end();
  }
}

phone_saveDefaultSendAs::ReturnType phone_saveDefaultSendAs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

photos_uploadProfilePhoto::photos_uploadProfilePhoto(int32 flags_, bool fallback_, object_ptr<InputUser> &&bot_, object_ptr<InputFile> &&file_, object_ptr<InputFile> &&video_, double video_start_ts_, object_ptr<VideoSize> &&video_emoji_markup_)
  : flags_(flags_)
  , fallback_(fallback_)
  , bot_(std::move(bot_))
  , file_(std::move(file_))
  , video_(std::move(video_))
  , video_start_ts_(video_start_ts_)
  , video_emoji_markup_(std::move(video_emoji_markup_))
{}

const std::int32_t photos_uploadProfilePhoto::ID;

void photos_uploadProfilePhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(59286453);
  TlStoreBinary::store((var0 = flags_ | (fallback_ << 3) | ((bot_ != nullptr) << 5) | ((file_ != nullptr) << 0) | ((video_ != nullptr) << 1) | ((video_emoji_markup_ != nullptr) << 4)), s);
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void photos_uploadProfilePhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(59286453);
  TlStoreBinary::store((var0 = flags_ | (fallback_ << 3) | ((bot_ != nullptr) << 5) | ((file_ != nullptr) << 0) | ((video_ != nullptr) << 1) | ((video_emoji_markup_ != nullptr) << 4)), s);
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void photos_uploadProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.uploadProfilePhoto");
    s.store_field("flags", (var0 = flags_ | (fallback_ << 3) | ((bot_ != nullptr) << 5) | ((file_ != nullptr) << 0) | ((video_ != nullptr) << 1) | ((video_emoji_markup_ != nullptr) << 4)));
    if (var0 & 8) { s.store_field("fallback", true); }
    if (var0 & 32) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    if (var0 & 1) { s.store_object_field("file", static_cast<const BaseObject *>(file_.get())); }
    if (var0 & 2) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    if (var0 & 4) { s.store_field("video_start_ts", video_start_ts_); }
    if (var0 & 16) { s.store_object_field("video_emoji_markup", static_cast<const BaseObject *>(video_emoji_markup_.get())); }
    s.store_class_end();
  }
}

photos_uploadProfilePhoto::ReturnType photos_uploadProfilePhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<photos_photo>, 539045032>::parse(p);
#undef FAIL
}

premium_applyBoost::premium_applyBoost(int32 flags_, array<int32> &&slots_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , slots_(std::move(slots_))
  , peer_(std::move(peer_))
{}

const std::int32_t premium_applyBoost::ID;

void premium_applyBoost::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1803396934);
  TlStoreBinary::store((var0 = flags_ | ((!slots_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(slots_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void premium_applyBoost::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1803396934);
  TlStoreBinary::store((var0 = flags_ | ((!slots_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(slots_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void premium_applyBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.applyBoost");
    s.store_field("flags", (var0 = flags_ | ((!slots_.empty()) << 0)));
    if (var0 & 1) { { s.store_vector_begin("slots", slots_.size()); for (const auto &_value : slots_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

premium_applyBoost::ReturnType premium_applyBoost::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<premium_myBoosts>, -1696454430>::parse(p);
#undef FAIL
}

smsjobs_getSmsJob::smsjobs_getSmsJob(string const &job_id_)
  : job_id_(job_id_)
{}

const std::int32_t smsjobs_getSmsJob::ID;

void smsjobs_getSmsJob::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2005766191);
  TlStoreString::store(job_id_, s);
}

void smsjobs_getSmsJob::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2005766191);
  TlStoreString::store(job_id_, s);
}

void smsjobs_getSmsJob::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.getSmsJob");
    s.store_field("job_id", job_id_);
    s.store_class_end();
  }
}

smsjobs_getSmsJob::ReturnType smsjobs_getSmsJob::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<smsJob>, -425595208>::parse(p);
#undef FAIL
}

stats_getMessageStats::stats_getMessageStats(int32 flags_, bool dark_, object_ptr<InputChannel> &&channel_, int32 msg_id_)
  : flags_(flags_)
  , dark_(dark_)
  , channel_(std::move(channel_))
  , msg_id_(msg_id_)
{}

const std::int32_t stats_getMessageStats::ID;

void stats_getMessageStats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1226791947);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void stats_getMessageStats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1226791947);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void stats_getMessageStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getMessageStats");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0)));
    if (var0 & 1) { s.store_field("dark", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

stats_getMessageStats::ReturnType stats_getMessageStats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_messageStats>, 2145983508>::parse(p);
#undef FAIL
}

stats_getStoryPublicForwards::stats_getStoryPublicForwards(object_ptr<InputPeer> &&peer_, int32 id_, string const &offset_, int32 limit_)
  : peer_(std::move(peer_))
  , id_(id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stats_getStoryPublicForwards::ID;

void stats_getStoryPublicForwards::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1505526026);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stats_getStoryPublicForwards::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1505526026);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stats_getStoryPublicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getStoryPublicForwards");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stats_getStoryPublicForwards::ReturnType stats_getStoryPublicForwards::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_publicForwards>, -1828487648>::parse(p);
#undef FAIL
}

stickers_changeSticker::stickers_changeSticker(int32 flags_, object_ptr<InputDocument> &&sticker_, string const &emoji_, object_ptr<maskCoords> &&mask_coords_, string const &keywords_)
  : flags_(flags_)
  , sticker_(std::move(sticker_))
  , emoji_(emoji_)
  , mask_coords_(std::move(mask_coords_))
  , keywords_(keywords_)
{}

const std::int32_t stickers_changeSticker::ID;

void stickers_changeSticker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-179077444);
  TlStoreBinary::store((var0 = flags_ | ((!emoji_.empty()) << 0) | ((mask_coords_ != nullptr) << 1) | ((!keywords_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  if (var0 & 1) { TlStoreString::store(emoji_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
  if (var0 & 4) { TlStoreString::store(keywords_, s); }
}

void stickers_changeSticker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-179077444);
  TlStoreBinary::store((var0 = flags_ | ((!emoji_.empty()) << 0) | ((mask_coords_ != nullptr) << 1) | ((!keywords_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  if (var0 & 1) { TlStoreString::store(emoji_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
  if (var0 & 4) { TlStoreString::store(keywords_, s); }
}

void stickers_changeSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.changeSticker");
    s.store_field("flags", (var0 = flags_ | ((!emoji_.empty()) << 0) | ((mask_coords_ != nullptr) << 1) | ((!keywords_.empty()) << 2)));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    if (var0 & 1) { s.store_field("emoji", emoji_); }
    if (var0 & 2) { s.store_object_field("mask_coords", static_cast<const BaseObject *>(mask_coords_.get())); }
    if (var0 & 4) { s.store_field("keywords", keywords_); }
    s.store_class_end();
  }
}

stickers_changeSticker::ReturnType stickers_changeSticker::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stickers_setStickerSetThumb::stickers_setStickerSetThumb(int32 flags_, object_ptr<InputStickerSet> &&stickerset_, object_ptr<InputDocument> &&thumb_, int64 thumb_document_id_)
  : flags_(flags_)
  , stickerset_(std::move(stickerset_))
  , thumb_(std::move(thumb_))
  , thumb_document_id_(thumb_document_id_)
{}

const std::int32_t stickers_setStickerSetThumb::ID;

void stickers_setStickerSetThumb::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1486204014);
  TlStoreBinary::store((var0 = flags_ | ((thumb_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  if (var0 & 2) { TlStoreBinary::store(thumb_document_id_, s); }
}

void stickers_setStickerSetThumb::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1486204014);
  TlStoreBinary::store((var0 = flags_ | ((thumb_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  if (var0 & 2) { TlStoreBinary::store(thumb_document_id_, s); }
}

void stickers_setStickerSetThumb::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.setStickerSetThumb");
    s.store_field("flags", (var0 = flags_ | ((thumb_ != nullptr) << 0)));
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    if (var0 & 1) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    if (var0 & 2) { s.store_field("thumb_document_id", thumb_document_id_); }
    s.store_class_end();
  }
}

stickers_setStickerSetThumb::ReturnType stickers_setStickerSetThumb::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stickers_suggestShortName::stickers_suggestShortName(string const &title_)
  : title_(title_)
{}

const std::int32_t stickers_suggestShortName::ID;

void stickers_suggestShortName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1303364867);
  TlStoreString::store(title_, s);
}

void stickers_suggestShortName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1303364867);
  TlStoreString::store(title_, s);
}

void stickers_suggestShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.suggestShortName");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

stickers_suggestShortName::ReturnType stickers_suggestShortName::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stickers_suggestedShortName>, -2046910401>::parse(p);
#undef FAIL
}

stories_report::stories_report(object_ptr<InputPeer> &&peer_, array<int32> &&id_, bytes &&option_, string const &message_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
  , option_(std::move(option_))
  , message_(message_)
{}

const std::int32_t stories_report::ID;

void stories_report::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(433646405);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreString::store(option_, s);
  TlStoreString::store(message_, s);
}

void stories_report::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(433646405);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreString::store(option_, s);
  TlStoreString::store(message_, s);
}

void stories_report::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.report");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_bytes_field("option", option_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

stories_report::ReturnType stories_report::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<ReportResult>::parse(p);
#undef FAIL
}

stories_toggleAllStoriesHidden::stories_toggleAllStoriesHidden(bool hidden_)
  : hidden_(hidden_)
{}

const std::int32_t stories_toggleAllStoriesHidden::ID;

void stories_toggleAllStoriesHidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2082822084);
  TlStoreBool::store(hidden_, s);
}

void stories_toggleAllStoriesHidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2082822084);
  TlStoreBool::store(hidden_, s);
}

void stories_toggleAllStoriesHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.toggleAllStoriesHidden");
    s.store_field("hidden", hidden_);
    s.store_class_end();
  }
}

stories_toggleAllStoriesHidden::ReturnType stories_toggleAllStoriesHidden::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

upload_getCdnFile::upload_getCdnFile(bytes &&file_token_, int64 offset_, int32 limit_)
  : file_token_(std::move(file_token_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t upload_getCdnFile::ID;

void upload_getCdnFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(962554330);
  TlStoreString::store(file_token_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getCdnFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(962554330);
  TlStoreString::store(file_token_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getCdnFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.getCdnFile");
    s.store_field("file_token", "[REDACTED]");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

upload_getCdnFile::ReturnType upload_getCdnFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<upload_CdnFile>::parse(p);
#undef FAIL
}

upload_getFileHashes::upload_getFileHashes(object_ptr<InputFileLocation> &&location_, int64 offset_)
  : location_(std::move(location_))
  , offset_(offset_)
{}

const std::int32_t upload_getFileHashes::ID;

void upload_getFileHashes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1856595926);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
}

void upload_getFileHashes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1856595926);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
}

void upload_getFileHashes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.getFileHashes");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

upload_getFileHashes::ReturnType upload_getFileHashes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<fileHash>, -207944868>>, 481674261>::parse(p);
#undef FAIL
}

upload_saveFilePart::upload_saveFilePart(int64 file_id_, int32 file_part_, bytes &&bytes_)
  : file_id_(file_id_)
  , file_part_(file_part_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t upload_saveFilePart::ID;

void upload_saveFilePart::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1291540959);
  TlStoreBinary::store(file_id_, s);
  TlStoreBinary::store(file_part_, s);
  TlStoreString::store(bytes_, s);
}

void upload_saveFilePart::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1291540959);
  TlStoreBinary::store(file_id_, s);
  TlStoreBinary::store(file_part_, s);
  TlStoreString::store(bytes_, s);
}

void upload_saveFilePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.saveFilePart");
    s.store_field("file_id", file_id_);
    s.store_field("file_part", file_part_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

upload_saveFilePart::ReturnType upload_saveFilePart::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t wallet_getState::ID;

void wallet_getState::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1417432262);
}

void wallet_getState::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1417432262);
}

void wallet_getState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.getState");
    s.store_class_end();
  }
}

wallet_getState::ReturnType wallet_getState::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<WalletState>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
