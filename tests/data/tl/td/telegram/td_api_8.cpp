#include "td_api.h"

#include "td/utils/common.h"
#include "td/utils/format.h"
#include "td/utils/logging.h"
#include "td/utils/SliceBuilder.h"
#include "td/utils/tl_parsers.h"
#include "td/utils/tl_storers.h"
#include "td/utils/TlStorerToString.h"

namespace td {
namespace td_api {


accountInfo::accountInfo()
  : registration_month_()
  , registration_year_()
  , phone_number_country_code_()
  , last_name_change_date_()
  , last_photo_change_date_()
{}

accountInfo::accountInfo(int32 registration_month_, int32 registration_year_, string const &phone_number_country_code_, int32 last_name_change_date_, int32 last_photo_change_date_)
  : registration_month_(registration_month_)
  , registration_year_(registration_year_)
  , phone_number_country_code_(phone_number_country_code_)
  , last_name_change_date_(last_name_change_date_)
  , last_photo_change_date_(last_photo_change_date_)
{}

const std::int32_t accountInfo::ID;

void accountInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accountInfo");
    s.store_field("registration_month", registration_month_);
    s.store_field("registration_year", registration_year_);
    s.store_field("phone_number_country_code", phone_number_country_code_);
    s.store_field("last_name_change_date", last_name_change_date_);
    s.store_field("last_photo_change_date", last_photo_change_date_);
    s.store_class_end();
  }
}

affiliateProgramParameters::affiliateProgramParameters()
  : commission_per_mille_()
  , month_count_()
{}

affiliateProgramParameters::affiliateProgramParameters(int32 commission_per_mille_, int32 month_count_)
  : commission_per_mille_(commission_per_mille_)
  , month_count_(month_count_)
{}

const std::int32_t affiliateProgramParameters::ID;

void affiliateProgramParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateProgramParameters");
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_field("month_count", month_count_);
    s.store_class_end();
  }
}

animation::animation()
  : duration_()
  , width_()
  , height_()
  , file_name_()
  , mime_type_()
  , has_stickers_()
  , minithumbnail_()
  , thumbnail_()
  , animation_()
{}

animation::animation(int32 duration_, int32 width_, int32 height_, string const &file_name_, string const &mime_type_, bool has_stickers_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&animation_)
  : duration_(duration_)
  , width_(width_)
  , height_(height_)
  , file_name_(file_name_)
  , mime_type_(mime_type_)
  , has_stickers_(has_stickers_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , animation_(std::move(animation_))
{}

const std::int32_t animation::ID;

void animation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animation");
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_field("has_stickers", has_stickers_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

animations::animations()
  : animations_()
{}

animations::animations(array<object_ptr<animation>> &&animations_)
  : animations_(std::move(animations_))
{}

const std::int32_t animations::ID;

void animations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animations");
    { s.store_vector_begin("animations", animations_.size()); for (const auto &_value : animations_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

attachmentMenuBot::attachmentMenuBot()
  : bot_user_id_()
  , supports_self_chat_()
  , supports_user_chats_()
  , supports_bot_chats_()
  , supports_group_chats_()
  , supports_channel_chats_()
  , request_write_access_()
  , is_added_()
  , show_in_attachment_menu_()
  , show_in_side_menu_()
  , show_disclaimer_in_side_menu_()
  , name_()
  , name_color_()
  , default_icon_()
  , ios_static_icon_()
  , ios_animated_icon_()
  , ios_side_menu_icon_()
  , android_icon_()
  , android_side_menu_icon_()
  , macos_icon_()
  , macos_side_menu_icon_()
  , icon_color_()
  , web_app_placeholder_()
{}

attachmentMenuBot::attachmentMenuBot(int53 bot_user_id_, bool supports_self_chat_, bool supports_user_chats_, bool supports_bot_chats_, bool supports_group_chats_, bool supports_channel_chats_, bool request_write_access_, bool is_added_, bool show_in_attachment_menu_, bool show_in_side_menu_, bool show_disclaimer_in_side_menu_, string const &name_, object_ptr<attachmentMenuBotColor> &&name_color_, object_ptr<file> &&default_icon_, object_ptr<file> &&ios_static_icon_, object_ptr<file> &&ios_animated_icon_, object_ptr<file> &&ios_side_menu_icon_, object_ptr<file> &&android_icon_, object_ptr<file> &&android_side_menu_icon_, object_ptr<file> &&macos_icon_, object_ptr<file> &&macos_side_menu_icon_, object_ptr<attachmentMenuBotColor> &&icon_color_, object_ptr<file> &&web_app_placeholder_)
  : bot_user_id_(bot_user_id_)
  , supports_self_chat_(supports_self_chat_)
  , supports_user_chats_(supports_user_chats_)
  , supports_bot_chats_(supports_bot_chats_)
  , supports_group_chats_(supports_group_chats_)
  , supports_channel_chats_(supports_channel_chats_)
  , request_write_access_(request_write_access_)
  , is_added_(is_added_)
  , show_in_attachment_menu_(show_in_attachment_menu_)
  , show_in_side_menu_(show_in_side_menu_)
  , show_disclaimer_in_side_menu_(show_disclaimer_in_side_menu_)
  , name_(name_)
  , name_color_(std::move(name_color_))
  , default_icon_(std::move(default_icon_))
  , ios_static_icon_(std::move(ios_static_icon_))
  , ios_animated_icon_(std::move(ios_animated_icon_))
  , ios_side_menu_icon_(std::move(ios_side_menu_icon_))
  , android_icon_(std::move(android_icon_))
  , android_side_menu_icon_(std::move(android_side_menu_icon_))
  , macos_icon_(std::move(macos_icon_))
  , macos_side_menu_icon_(std::move(macos_side_menu_icon_))
  , icon_color_(std::move(icon_color_))
  , web_app_placeholder_(std::move(web_app_placeholder_))
{}

const std::int32_t attachmentMenuBot::ID;

void attachmentMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachmentMenuBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("supports_self_chat", supports_self_chat_);
    s.store_field("supports_user_chats", supports_user_chats_);
    s.store_field("supports_bot_chats", supports_bot_chats_);
    s.store_field("supports_group_chats", supports_group_chats_);
    s.store_field("supports_channel_chats", supports_channel_chats_);
    s.store_field("request_write_access", request_write_access_);
    s.store_field("is_added", is_added_);
    s.store_field("show_in_attachment_menu", show_in_attachment_menu_);
    s.store_field("show_in_side_menu", show_in_side_menu_);
    s.store_field("show_disclaimer_in_side_menu", show_disclaimer_in_side_menu_);
    s.store_field("name", name_);
    s.store_object_field("name_color", static_cast<const BaseObject *>(name_color_.get()));
    s.store_object_field("default_icon", static_cast<const BaseObject *>(default_icon_.get()));
    s.store_object_field("ios_static_icon", static_cast<const BaseObject *>(ios_static_icon_.get()));
    s.store_object_field("ios_animated_icon", static_cast<const BaseObject *>(ios_animated_icon_.get()));
    s.store_object_field("ios_side_menu_icon", static_cast<const BaseObject *>(ios_side_menu_icon_.get()));
    s.store_object_field("android_icon", static_cast<const BaseObject *>(android_icon_.get()));
    s.store_object_field("android_side_menu_icon", static_cast<const BaseObject *>(android_side_menu_icon_.get()));
    s.store_object_field("macos_icon", static_cast<const BaseObject *>(macos_icon_.get()));
    s.store_object_field("macos_side_menu_icon", static_cast<const BaseObject *>(macos_side_menu_icon_.get()));
    s.store_object_field("icon_color", static_cast<const BaseObject *>(icon_color_.get()));
    s.store_object_field("web_app_placeholder", static_cast<const BaseObject *>(web_app_placeholder_.get()));
    s.store_class_end();
  }
}

audios::audios()
  : total_count_()
  , audios_()
{}

audios::audios(int32 total_count_, array<object_ptr<audio>> &&audios_)
  : total_count_(total_count_)
  , audios_(std::move(audios_))
{}

const std::int32_t audios::ID;

void audios::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "audios");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("audios", audios_.size()); for (const auto &_value : audios_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessAwayMessageScheduleAlways::businessAwayMessageScheduleAlways() {
}

const std::int32_t businessAwayMessageScheduleAlways::ID;

void businessAwayMessageScheduleAlways::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleAlways");
    s.store_class_end();
  }
}

businessAwayMessageScheduleOutsideOfOpeningHours::businessAwayMessageScheduleOutsideOfOpeningHours() {
}

const std::int32_t businessAwayMessageScheduleOutsideOfOpeningHours::ID;

void businessAwayMessageScheduleOutsideOfOpeningHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleOutsideOfOpeningHours");
    s.store_class_end();
  }
}

businessAwayMessageScheduleCustom::businessAwayMessageScheduleCustom()
  : start_date_()
  , end_date_()
{}

businessAwayMessageScheduleCustom::businessAwayMessageScheduleCustom(int32 start_date_, int32 end_date_)
  : start_date_(start_date_)
  , end_date_(end_date_)
{}

const std::int32_t businessAwayMessageScheduleCustom::ID;

void businessAwayMessageScheduleCustom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleCustom");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_class_end();
  }
}

businessInfo::businessInfo()
  : location_()
  , opening_hours_()
  , local_opening_hours_()
  , next_open_in_()
  , next_close_in_()
  , greeting_message_settings_()
  , away_message_settings_()
  , start_page_()
{}

businessInfo::businessInfo(object_ptr<businessLocation> &&location_, object_ptr<businessOpeningHours> &&opening_hours_, object_ptr<businessOpeningHours> &&local_opening_hours_, int32 next_open_in_, int32 next_close_in_, object_ptr<businessGreetingMessageSettings> &&greeting_message_settings_, object_ptr<businessAwayMessageSettings> &&away_message_settings_, object_ptr<businessStartPage> &&start_page_)
  : location_(std::move(location_))
  , opening_hours_(std::move(opening_hours_))
  , local_opening_hours_(std::move(local_opening_hours_))
  , next_open_in_(next_open_in_)
  , next_close_in_(next_close_in_)
  , greeting_message_settings_(std::move(greeting_message_settings_))
  , away_message_settings_(std::move(away_message_settings_))
  , start_page_(std::move(start_page_))
{}

const std::int32_t businessInfo::ID;

void businessInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessInfo");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_object_field("opening_hours", static_cast<const BaseObject *>(opening_hours_.get()));
    s.store_object_field("local_opening_hours", static_cast<const BaseObject *>(local_opening_hours_.get()));
    s.store_field("next_open_in", next_open_in_);
    s.store_field("next_close_in", next_close_in_);
    s.store_object_field("greeting_message_settings", static_cast<const BaseObject *>(greeting_message_settings_.get()));
    s.store_object_field("away_message_settings", static_cast<const BaseObject *>(away_message_settings_.get()));
    s.store_object_field("start_page", static_cast<const BaseObject *>(start_page_.get()));
    s.store_class_end();
  }
}

businessMessage::businessMessage()
  : message_()
  , reply_to_message_()
{}

businessMessage::businessMessage(object_ptr<message> &&message_, object_ptr<message> &&reply_to_message_)
  : message_(std::move(message_))
  , reply_to_message_(std::move(reply_to_message_))
{}

const std::int32_t businessMessage::ID;

void businessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_object_field("reply_to_message", static_cast<const BaseObject *>(reply_to_message_.get()));
    s.store_class_end();
  }
}

chatEventMessageEdited::chatEventMessageEdited()
  : old_message_()
  , new_message_()
{}

chatEventMessageEdited::chatEventMessageEdited(object_ptr<message> &&old_message_, object_ptr<message> &&new_message_)
  : old_message_(std::move(old_message_))
  , new_message_(std::move(new_message_))
{}

const std::int32_t chatEventMessageEdited::ID;

void chatEventMessageEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageEdited");
    s.store_object_field("old_message", static_cast<const BaseObject *>(old_message_.get()));
    s.store_object_field("new_message", static_cast<const BaseObject *>(new_message_.get()));
    s.store_class_end();
  }
}

chatEventMessageDeleted::chatEventMessageDeleted()
  : message_()
  , can_report_anti_spam_false_positive_()
{}

chatEventMessageDeleted::chatEventMessageDeleted(object_ptr<message> &&message_, bool can_report_anti_spam_false_positive_)
  : message_(std::move(message_))
  , can_report_anti_spam_false_positive_(can_report_anti_spam_false_positive_)
{}

const std::int32_t chatEventMessageDeleted::ID;

void chatEventMessageDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageDeleted");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("can_report_anti_spam_false_positive", can_report_anti_spam_false_positive_);
    s.store_class_end();
  }
}

chatEventMessagePinned::chatEventMessagePinned()
  : message_()
{}

chatEventMessagePinned::chatEventMessagePinned(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t chatEventMessagePinned::ID;

void chatEventMessagePinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessagePinned");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

chatEventMessageUnpinned::chatEventMessageUnpinned()
  : message_()
{}

chatEventMessageUnpinned::chatEventMessageUnpinned(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t chatEventMessageUnpinned::ID;

void chatEventMessageUnpinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageUnpinned");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

chatEventPollStopped::chatEventPollStopped()
  : message_()
{}

chatEventPollStopped::chatEventPollStopped(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t chatEventPollStopped::ID;

void chatEventPollStopped::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventPollStopped");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

chatEventMemberJoined::chatEventMemberJoined() {
}

const std::int32_t chatEventMemberJoined::ID;

void chatEventMemberJoined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberJoined");
    s.store_class_end();
  }
}

chatEventMemberJoinedByInviteLink::chatEventMemberJoinedByInviteLink()
  : invite_link_()
  , via_chat_folder_invite_link_()
{}

chatEventMemberJoinedByInviteLink::chatEventMemberJoinedByInviteLink(object_ptr<chatInviteLink> &&invite_link_, bool via_chat_folder_invite_link_)
  : invite_link_(std::move(invite_link_))
  , via_chat_folder_invite_link_(via_chat_folder_invite_link_)
{}

const std::int32_t chatEventMemberJoinedByInviteLink::ID;

void chatEventMemberJoinedByInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberJoinedByInviteLink");
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_field("via_chat_folder_invite_link", via_chat_folder_invite_link_);
    s.store_class_end();
  }
}

chatEventMemberJoinedByRequest::chatEventMemberJoinedByRequest()
  : approver_user_id_()
  , invite_link_()
{}

chatEventMemberJoinedByRequest::chatEventMemberJoinedByRequest(int53 approver_user_id_, object_ptr<chatInviteLink> &&invite_link_)
  : approver_user_id_(approver_user_id_)
  , invite_link_(std::move(invite_link_))
{}

const std::int32_t chatEventMemberJoinedByRequest::ID;

void chatEventMemberJoinedByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberJoinedByRequest");
    s.store_field("approver_user_id", approver_user_id_);
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

chatEventMemberInvited::chatEventMemberInvited()
  : user_id_()
  , status_()
{}

chatEventMemberInvited::chatEventMemberInvited(int53 user_id_, object_ptr<ChatMemberStatus> &&status_)
  : user_id_(user_id_)
  , status_(std::move(status_))
{}

const std::int32_t chatEventMemberInvited::ID;

void chatEventMemberInvited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberInvited");
    s.store_field("user_id", user_id_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

chatEventMemberLeft::chatEventMemberLeft() {
}

const std::int32_t chatEventMemberLeft::ID;

void chatEventMemberLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberLeft");
    s.store_class_end();
  }
}

chatEventMemberPromoted::chatEventMemberPromoted()
  : user_id_()
  , old_status_()
  , new_status_()
{}

chatEventMemberPromoted::chatEventMemberPromoted(int53 user_id_, object_ptr<ChatMemberStatus> &&old_status_, object_ptr<ChatMemberStatus> &&new_status_)
  : user_id_(user_id_)
  , old_status_(std::move(old_status_))
  , new_status_(std::move(new_status_))
{}

const std::int32_t chatEventMemberPromoted::ID;

void chatEventMemberPromoted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberPromoted");
    s.store_field("user_id", user_id_);
    s.store_object_field("old_status", static_cast<const BaseObject *>(old_status_.get()));
    s.store_object_field("new_status", static_cast<const BaseObject *>(new_status_.get()));
    s.store_class_end();
  }
}

chatEventMemberRestricted::chatEventMemberRestricted()
  : member_id_()
  , old_status_()
  , new_status_()
{}

chatEventMemberRestricted::chatEventMemberRestricted(object_ptr<MessageSender> &&member_id_, object_ptr<ChatMemberStatus> &&old_status_, object_ptr<ChatMemberStatus> &&new_status_)
  : member_id_(std::move(member_id_))
  , old_status_(std::move(old_status_))
  , new_status_(std::move(new_status_))
{}

const std::int32_t chatEventMemberRestricted::ID;

void chatEventMemberRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberRestricted");
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_object_field("old_status", static_cast<const BaseObject *>(old_status_.get()));
    s.store_object_field("new_status", static_cast<const BaseObject *>(new_status_.get()));
    s.store_class_end();
  }
}

chatEventMemberTagChanged::chatEventMemberTagChanged()
  : user_id_()
  , old_tag_()
  , new_tag_()
{}

chatEventMemberTagChanged::chatEventMemberTagChanged(int53 user_id_, string const &old_tag_, string const &new_tag_)
  : user_id_(user_id_)
  , old_tag_(old_tag_)
  , new_tag_(new_tag_)
{}

const std::int32_t chatEventMemberTagChanged::ID;

void chatEventMemberTagChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberTagChanged");
    s.store_field("user_id", user_id_);
    s.store_field("old_tag", old_tag_);
    s.store_field("new_tag", new_tag_);
    s.store_class_end();
  }
}

chatEventMemberSubscriptionExtended::chatEventMemberSubscriptionExtended()
  : user_id_()
  , old_status_()
  , new_status_()
{}

chatEventMemberSubscriptionExtended::chatEventMemberSubscriptionExtended(int53 user_id_, object_ptr<ChatMemberStatus> &&old_status_, object_ptr<ChatMemberStatus> &&new_status_)
  : user_id_(user_id_)
  , old_status_(std::move(old_status_))
  , new_status_(std::move(new_status_))
{}

const std::int32_t chatEventMemberSubscriptionExtended::ID;

void chatEventMemberSubscriptionExtended::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberSubscriptionExtended");
    s.store_field("user_id", user_id_);
    s.store_object_field("old_status", static_cast<const BaseObject *>(old_status_.get()));
    s.store_object_field("new_status", static_cast<const BaseObject *>(new_status_.get()));
    s.store_class_end();
  }
}

chatEventAvailableReactionsChanged::chatEventAvailableReactionsChanged()
  : old_available_reactions_()
  , new_available_reactions_()
{}

chatEventAvailableReactionsChanged::chatEventAvailableReactionsChanged(object_ptr<ChatAvailableReactions> &&old_available_reactions_, object_ptr<ChatAvailableReactions> &&new_available_reactions_)
  : old_available_reactions_(std::move(old_available_reactions_))
  , new_available_reactions_(std::move(new_available_reactions_))
{}

const std::int32_t chatEventAvailableReactionsChanged::ID;

void chatEventAvailableReactionsChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventAvailableReactionsChanged");
    s.store_object_field("old_available_reactions", static_cast<const BaseObject *>(old_available_reactions_.get()));
    s.store_object_field("new_available_reactions", static_cast<const BaseObject *>(new_available_reactions_.get()));
    s.store_class_end();
  }
}

chatEventBackgroundChanged::chatEventBackgroundChanged()
  : old_background_()
  , new_background_()
{}

chatEventBackgroundChanged::chatEventBackgroundChanged(object_ptr<chatBackground> &&old_background_, object_ptr<chatBackground> &&new_background_)
  : old_background_(std::move(old_background_))
  , new_background_(std::move(new_background_))
{}

const std::int32_t chatEventBackgroundChanged::ID;

void chatEventBackgroundChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventBackgroundChanged");
    s.store_object_field("old_background", static_cast<const BaseObject *>(old_background_.get()));
    s.store_object_field("new_background", static_cast<const BaseObject *>(new_background_.get()));
    s.store_class_end();
  }
}

chatEventDescriptionChanged::chatEventDescriptionChanged()
  : old_description_()
  , new_description_()
{}

chatEventDescriptionChanged::chatEventDescriptionChanged(string const &old_description_, string const &new_description_)
  : old_description_(old_description_)
  , new_description_(new_description_)
{}

const std::int32_t chatEventDescriptionChanged::ID;

void chatEventDescriptionChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventDescriptionChanged");
    s.store_field("old_description", old_description_);
    s.store_field("new_description", new_description_);
    s.store_class_end();
  }
}

chatEventEmojiStatusChanged::chatEventEmojiStatusChanged()
  : old_emoji_status_()
  , new_emoji_status_()
{}

chatEventEmojiStatusChanged::chatEventEmojiStatusChanged(object_ptr<emojiStatus> &&old_emoji_status_, object_ptr<emojiStatus> &&new_emoji_status_)
  : old_emoji_status_(std::move(old_emoji_status_))
  , new_emoji_status_(std::move(new_emoji_status_))
{}

const std::int32_t chatEventEmojiStatusChanged::ID;

void chatEventEmojiStatusChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventEmojiStatusChanged");
    s.store_object_field("old_emoji_status", static_cast<const BaseObject *>(old_emoji_status_.get()));
    s.store_object_field("new_emoji_status", static_cast<const BaseObject *>(new_emoji_status_.get()));
    s.store_class_end();
  }
}

chatEventLinkedChatChanged::chatEventLinkedChatChanged()
  : old_linked_chat_id_()
  , new_linked_chat_id_()
{}

chatEventLinkedChatChanged::chatEventLinkedChatChanged(int53 old_linked_chat_id_, int53 new_linked_chat_id_)
  : old_linked_chat_id_(old_linked_chat_id_)
  , new_linked_chat_id_(new_linked_chat_id_)
{}

const std::int32_t chatEventLinkedChatChanged::ID;

void chatEventLinkedChatChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventLinkedChatChanged");
    s.store_field("old_linked_chat_id", old_linked_chat_id_);
    s.store_field("new_linked_chat_id", new_linked_chat_id_);
    s.store_class_end();
  }
}

chatEventLocationChanged::chatEventLocationChanged()
  : old_location_()
  , new_location_()
{}

chatEventLocationChanged::chatEventLocationChanged(object_ptr<chatLocation> &&old_location_, object_ptr<chatLocation> &&new_location_)
  : old_location_(std::move(old_location_))
  , new_location_(std::move(new_location_))
{}

const std::int32_t chatEventLocationChanged::ID;

void chatEventLocationChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventLocationChanged");
    s.store_object_field("old_location", static_cast<const BaseObject *>(old_location_.get()));
    s.store_object_field("new_location", static_cast<const BaseObject *>(new_location_.get()));
    s.store_class_end();
  }
}

chatEventMessageAutoDeleteTimeChanged::chatEventMessageAutoDeleteTimeChanged()
  : old_message_auto_delete_time_()
  , new_message_auto_delete_time_()
{}

chatEventMessageAutoDeleteTimeChanged::chatEventMessageAutoDeleteTimeChanged(int32 old_message_auto_delete_time_, int32 new_message_auto_delete_time_)
  : old_message_auto_delete_time_(old_message_auto_delete_time_)
  , new_message_auto_delete_time_(new_message_auto_delete_time_)
{}

const std::int32_t chatEventMessageAutoDeleteTimeChanged::ID;

void chatEventMessageAutoDeleteTimeChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageAutoDeleteTimeChanged");
    s.store_field("old_message_auto_delete_time", old_message_auto_delete_time_);
    s.store_field("new_message_auto_delete_time", new_message_auto_delete_time_);
    s.store_class_end();
  }
}

chatEventPermissionsChanged::chatEventPermissionsChanged()
  : old_permissions_()
  , new_permissions_()
{}

chatEventPermissionsChanged::chatEventPermissionsChanged(object_ptr<chatPermissions> &&old_permissions_, object_ptr<chatPermissions> &&new_permissions_)
  : old_permissions_(std::move(old_permissions_))
  , new_permissions_(std::move(new_permissions_))
{}

const std::int32_t chatEventPermissionsChanged::ID;

void chatEventPermissionsChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventPermissionsChanged");
    s.store_object_field("old_permissions", static_cast<const BaseObject *>(old_permissions_.get()));
    s.store_object_field("new_permissions", static_cast<const BaseObject *>(new_permissions_.get()));
    s.store_class_end();
  }
}

chatEventPhotoChanged::chatEventPhotoChanged()
  : old_photo_()
  , new_photo_()
{}

chatEventPhotoChanged::chatEventPhotoChanged(object_ptr<chatPhoto> &&old_photo_, object_ptr<chatPhoto> &&new_photo_)
  : old_photo_(std::move(old_photo_))
  , new_photo_(std::move(new_photo_))
{}

const std::int32_t chatEventPhotoChanged::ID;

void chatEventPhotoChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventPhotoChanged");
    s.store_object_field("old_photo", static_cast<const BaseObject *>(old_photo_.get()));
    s.store_object_field("new_photo", static_cast<const BaseObject *>(new_photo_.get()));
    s.store_class_end();
  }
}

chatEventSlowModeDelayChanged::chatEventSlowModeDelayChanged()
  : old_slow_mode_delay_()
  , new_slow_mode_delay_()
{}

chatEventSlowModeDelayChanged::chatEventSlowModeDelayChanged(int32 old_slow_mode_delay_, int32 new_slow_mode_delay_)
  : old_slow_mode_delay_(old_slow_mode_delay_)
  , new_slow_mode_delay_(new_slow_mode_delay_)
{}

const std::int32_t chatEventSlowModeDelayChanged::ID;

void chatEventSlowModeDelayChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventSlowModeDelayChanged");
    s.store_field("old_slow_mode_delay", old_slow_mode_delay_);
    s.store_field("new_slow_mode_delay", new_slow_mode_delay_);
    s.store_class_end();
  }
}

chatEventStickerSetChanged::chatEventStickerSetChanged()
  : old_sticker_set_id_()
  , new_sticker_set_id_()
{}

chatEventStickerSetChanged::chatEventStickerSetChanged(int64 old_sticker_set_id_, int64 new_sticker_set_id_)
  : old_sticker_set_id_(old_sticker_set_id_)
  , new_sticker_set_id_(new_sticker_set_id_)
{}

const std::int32_t chatEventStickerSetChanged::ID;

void chatEventStickerSetChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventStickerSetChanged");
    s.store_field("old_sticker_set_id", old_sticker_set_id_);
    s.store_field("new_sticker_set_id", new_sticker_set_id_);
    s.store_class_end();
  }
}

chatEventCustomEmojiStickerSetChanged::chatEventCustomEmojiStickerSetChanged()
  : old_sticker_set_id_()
  , new_sticker_set_id_()
{}

chatEventCustomEmojiStickerSetChanged::chatEventCustomEmojiStickerSetChanged(int64 old_sticker_set_id_, int64 new_sticker_set_id_)
  : old_sticker_set_id_(old_sticker_set_id_)
  , new_sticker_set_id_(new_sticker_set_id_)
{}

const std::int32_t chatEventCustomEmojiStickerSetChanged::ID;

void chatEventCustomEmojiStickerSetChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventCustomEmojiStickerSetChanged");
    s.store_field("old_sticker_set_id", old_sticker_set_id_);
    s.store_field("new_sticker_set_id", new_sticker_set_id_);
    s.store_class_end();
  }
}

chatEventTitleChanged::chatEventTitleChanged()
  : old_title_()
  , new_title_()
{}

chatEventTitleChanged::chatEventTitleChanged(string const &old_title_, string const &new_title_)
  : old_title_(old_title_)
  , new_title_(new_title_)
{}

const std::int32_t chatEventTitleChanged::ID;

void chatEventTitleChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventTitleChanged");
    s.store_field("old_title", old_title_);
    s.store_field("new_title", new_title_);
    s.store_class_end();
  }
}

chatEventUsernameChanged::chatEventUsernameChanged()
  : old_username_()
  , new_username_()
{}

chatEventUsernameChanged::chatEventUsernameChanged(string const &old_username_, string const &new_username_)
  : old_username_(old_username_)
  , new_username_(new_username_)
{}

const std::int32_t chatEventUsernameChanged::ID;

void chatEventUsernameChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventUsernameChanged");
    s.store_field("old_username", old_username_);
    s.store_field("new_username", new_username_);
    s.store_class_end();
  }
}

chatEventActiveUsernamesChanged::chatEventActiveUsernamesChanged()
  : old_usernames_()
  , new_usernames_()
{}

chatEventActiveUsernamesChanged::chatEventActiveUsernamesChanged(array<string> &&old_usernames_, array<string> &&new_usernames_)
  : old_usernames_(std::move(old_usernames_))
  , new_usernames_(std::move(new_usernames_))
{}

const std::int32_t chatEventActiveUsernamesChanged::ID;

void chatEventActiveUsernamesChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventActiveUsernamesChanged");
    { s.store_vector_begin("old_usernames", old_usernames_.size()); for (const auto &_value : old_usernames_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("new_usernames", new_usernames_.size()); for (const auto &_value : new_usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatEventAccentColorChanged::chatEventAccentColorChanged()
  : old_accent_color_id_()
  , old_background_custom_emoji_id_()
  , new_accent_color_id_()
  , new_background_custom_emoji_id_()
{}

chatEventAccentColorChanged::chatEventAccentColorChanged(int32 old_accent_color_id_, int64 old_background_custom_emoji_id_, int32 new_accent_color_id_, int64 new_background_custom_emoji_id_)
  : old_accent_color_id_(old_accent_color_id_)
  , old_background_custom_emoji_id_(old_background_custom_emoji_id_)
  , new_accent_color_id_(new_accent_color_id_)
  , new_background_custom_emoji_id_(new_background_custom_emoji_id_)
{}

const std::int32_t chatEventAccentColorChanged::ID;

void chatEventAccentColorChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventAccentColorChanged");
    s.store_field("old_accent_color_id", old_accent_color_id_);
    s.store_field("old_background_custom_emoji_id", old_background_custom_emoji_id_);
    s.store_field("new_accent_color_id", new_accent_color_id_);
    s.store_field("new_background_custom_emoji_id", new_background_custom_emoji_id_);
    s.store_class_end();
  }
}

chatEventProfileAccentColorChanged::chatEventProfileAccentColorChanged()
  : old_profile_accent_color_id_()
  , old_profile_background_custom_emoji_id_()
  , new_profile_accent_color_id_()
  , new_profile_background_custom_emoji_id_()
{}

chatEventProfileAccentColorChanged::chatEventProfileAccentColorChanged(int32 old_profile_accent_color_id_, int64 old_profile_background_custom_emoji_id_, int32 new_profile_accent_color_id_, int64 new_profile_background_custom_emoji_id_)
  : old_profile_accent_color_id_(old_profile_accent_color_id_)
  , old_profile_background_custom_emoji_id_(old_profile_background_custom_emoji_id_)
  , new_profile_accent_color_id_(new_profile_accent_color_id_)
  , new_profile_background_custom_emoji_id_(new_profile_background_custom_emoji_id_)
{}

const std::int32_t chatEventProfileAccentColorChanged::ID;

void chatEventProfileAccentColorChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventProfileAccentColorChanged");
    s.store_field("old_profile_accent_color_id", old_profile_accent_color_id_);
    s.store_field("old_profile_background_custom_emoji_id", old_profile_background_custom_emoji_id_);
    s.store_field("new_profile_accent_color_id", new_profile_accent_color_id_);
    s.store_field("new_profile_background_custom_emoji_id", new_profile_background_custom_emoji_id_);
    s.store_class_end();
  }
}

chatEventHasProtectedContentToggled::chatEventHasProtectedContentToggled()
  : has_protected_content_()
{}

chatEventHasProtectedContentToggled::chatEventHasProtectedContentToggled(bool has_protected_content_)
  : has_protected_content_(has_protected_content_)
{}

const std::int32_t chatEventHasProtectedContentToggled::ID;

void chatEventHasProtectedContentToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventHasProtectedContentToggled");
    s.store_field("has_protected_content", has_protected_content_);
    s.store_class_end();
  }
}

chatEventInvitesToggled::chatEventInvitesToggled()
  : can_invite_users_()
{}

chatEventInvitesToggled::chatEventInvitesToggled(bool can_invite_users_)
  : can_invite_users_(can_invite_users_)
{}

const std::int32_t chatEventInvitesToggled::ID;

void chatEventInvitesToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInvitesToggled");
    s.store_field("can_invite_users", can_invite_users_);
    s.store_class_end();
  }
}

chatEventIsAllHistoryAvailableToggled::chatEventIsAllHistoryAvailableToggled()
  : is_all_history_available_()
{}

chatEventIsAllHistoryAvailableToggled::chatEventIsAllHistoryAvailableToggled(bool is_all_history_available_)
  : is_all_history_available_(is_all_history_available_)
{}

const std::int32_t chatEventIsAllHistoryAvailableToggled::ID;

void chatEventIsAllHistoryAvailableToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventIsAllHistoryAvailableToggled");
    s.store_field("is_all_history_available", is_all_history_available_);
    s.store_class_end();
  }
}

chatEventHasAggressiveAntiSpamEnabledToggled::chatEventHasAggressiveAntiSpamEnabledToggled()
  : has_aggressive_anti_spam_enabled_()
{}

chatEventHasAggressiveAntiSpamEnabledToggled::chatEventHasAggressiveAntiSpamEnabledToggled(bool has_aggressive_anti_spam_enabled_)
  : has_aggressive_anti_spam_enabled_(has_aggressive_anti_spam_enabled_)
{}

const std::int32_t chatEventHasAggressiveAntiSpamEnabledToggled::ID;

void chatEventHasAggressiveAntiSpamEnabledToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventHasAggressiveAntiSpamEnabledToggled");
    s.store_field("has_aggressive_anti_spam_enabled", has_aggressive_anti_spam_enabled_);
    s.store_class_end();
  }
}

chatEventSignMessagesToggled::chatEventSignMessagesToggled()
  : sign_messages_()
{}

chatEventSignMessagesToggled::chatEventSignMessagesToggled(bool sign_messages_)
  : sign_messages_(sign_messages_)
{}

const std::int32_t chatEventSignMessagesToggled::ID;

void chatEventSignMessagesToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventSignMessagesToggled");
    s.store_field("sign_messages", sign_messages_);
    s.store_class_end();
  }
}

chatEventShowMessageSenderToggled::chatEventShowMessageSenderToggled()
  : show_message_sender_()
{}

chatEventShowMessageSenderToggled::chatEventShowMessageSenderToggled(bool show_message_sender_)
  : show_message_sender_(show_message_sender_)
{}

const std::int32_t chatEventShowMessageSenderToggled::ID;

void chatEventShowMessageSenderToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventShowMessageSenderToggled");
    s.store_field("show_message_sender", show_message_sender_);
    s.store_class_end();
  }
}

chatEventAutomaticTranslationToggled::chatEventAutomaticTranslationToggled()
  : has_automatic_translation_()
{}

chatEventAutomaticTranslationToggled::chatEventAutomaticTranslationToggled(bool has_automatic_translation_)
  : has_automatic_translation_(has_automatic_translation_)
{}

const std::int32_t chatEventAutomaticTranslationToggled::ID;

void chatEventAutomaticTranslationToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventAutomaticTranslationToggled");
    s.store_field("has_automatic_translation", has_automatic_translation_);
    s.store_class_end();
  }
}

chatEventInviteLinkEdited::chatEventInviteLinkEdited()
  : old_invite_link_()
  , new_invite_link_()
{}

chatEventInviteLinkEdited::chatEventInviteLinkEdited(object_ptr<chatInviteLink> &&old_invite_link_, object_ptr<chatInviteLink> &&new_invite_link_)
  : old_invite_link_(std::move(old_invite_link_))
  , new_invite_link_(std::move(new_invite_link_))
{}

const std::int32_t chatEventInviteLinkEdited::ID;

void chatEventInviteLinkEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInviteLinkEdited");
    s.store_object_field("old_invite_link", static_cast<const BaseObject *>(old_invite_link_.get()));
    s.store_object_field("new_invite_link", static_cast<const BaseObject *>(new_invite_link_.get()));
    s.store_class_end();
  }
}

chatEventInviteLinkRevoked::chatEventInviteLinkRevoked()
  : invite_link_()
{}

chatEventInviteLinkRevoked::chatEventInviteLinkRevoked(object_ptr<chatInviteLink> &&invite_link_)
  : invite_link_(std::move(invite_link_))
{}

const std::int32_t chatEventInviteLinkRevoked::ID;

void chatEventInviteLinkRevoked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInviteLinkRevoked");
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

chatEventInviteLinkDeleted::chatEventInviteLinkDeleted()
  : invite_link_()
{}

chatEventInviteLinkDeleted::chatEventInviteLinkDeleted(object_ptr<chatInviteLink> &&invite_link_)
  : invite_link_(std::move(invite_link_))
{}

const std::int32_t chatEventInviteLinkDeleted::ID;

void chatEventInviteLinkDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInviteLinkDeleted");
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

chatEventVideoChatCreated::chatEventVideoChatCreated()
  : group_call_id_()
{}

chatEventVideoChatCreated::chatEventVideoChatCreated(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t chatEventVideoChatCreated::ID;

void chatEventVideoChatCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatCreated");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

chatEventVideoChatEnded::chatEventVideoChatEnded()
  : group_call_id_()
{}

chatEventVideoChatEnded::chatEventVideoChatEnded(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t chatEventVideoChatEnded::ID;

void chatEventVideoChatEnded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatEnded");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

chatEventVideoChatMuteNewParticipantsToggled::chatEventVideoChatMuteNewParticipantsToggled()
  : mute_new_participants_()
{}

chatEventVideoChatMuteNewParticipantsToggled::chatEventVideoChatMuteNewParticipantsToggled(bool mute_new_participants_)
  : mute_new_participants_(mute_new_participants_)
{}

const std::int32_t chatEventVideoChatMuteNewParticipantsToggled::ID;

void chatEventVideoChatMuteNewParticipantsToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatMuteNewParticipantsToggled");
    s.store_field("mute_new_participants", mute_new_participants_);
    s.store_class_end();
  }
}

chatEventVideoChatParticipantIsMutedToggled::chatEventVideoChatParticipantIsMutedToggled()
  : participant_id_()
  , is_muted_()
{}

chatEventVideoChatParticipantIsMutedToggled::chatEventVideoChatParticipantIsMutedToggled(object_ptr<MessageSender> &&participant_id_, bool is_muted_)
  : participant_id_(std::move(participant_id_))
  , is_muted_(is_muted_)
{}

const std::int32_t chatEventVideoChatParticipantIsMutedToggled::ID;

void chatEventVideoChatParticipantIsMutedToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatParticipantIsMutedToggled");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_muted", is_muted_);
    s.store_class_end();
  }
}

chatEventVideoChatParticipantVolumeLevelChanged::chatEventVideoChatParticipantVolumeLevelChanged()
  : participant_id_()
  , volume_level_()
{}

chatEventVideoChatParticipantVolumeLevelChanged::chatEventVideoChatParticipantVolumeLevelChanged(object_ptr<MessageSender> &&participant_id_, int32 volume_level_)
  : participant_id_(std::move(participant_id_))
  , volume_level_(volume_level_)
{}

const std::int32_t chatEventVideoChatParticipantVolumeLevelChanged::ID;

void chatEventVideoChatParticipantVolumeLevelChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatParticipantVolumeLevelChanged");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("volume_level", volume_level_);
    s.store_class_end();
  }
}

chatEventIsForumToggled::chatEventIsForumToggled()
  : is_forum_()
{}

chatEventIsForumToggled::chatEventIsForumToggled(bool is_forum_)
  : is_forum_(is_forum_)
{}

const std::int32_t chatEventIsForumToggled::ID;

void chatEventIsForumToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventIsForumToggled");
    s.store_field("is_forum", is_forum_);
    s.store_class_end();
  }
}

chatEventForumTopicCreated::chatEventForumTopicCreated()
  : topic_info_()
{}

chatEventForumTopicCreated::chatEventForumTopicCreated(object_ptr<forumTopicInfo> &&topic_info_)
  : topic_info_(std::move(topic_info_))
{}

const std::int32_t chatEventForumTopicCreated::ID;

void chatEventForumTopicCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicCreated");
    s.store_object_field("topic_info", static_cast<const BaseObject *>(topic_info_.get()));
    s.store_class_end();
  }
}

chatEventForumTopicEdited::chatEventForumTopicEdited()
  : old_topic_info_()
  , new_topic_info_()
{}

chatEventForumTopicEdited::chatEventForumTopicEdited(object_ptr<forumTopicInfo> &&old_topic_info_, object_ptr<forumTopicInfo> &&new_topic_info_)
  : old_topic_info_(std::move(old_topic_info_))
  , new_topic_info_(std::move(new_topic_info_))
{}

const std::int32_t chatEventForumTopicEdited::ID;

void chatEventForumTopicEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicEdited");
    s.store_object_field("old_topic_info", static_cast<const BaseObject *>(old_topic_info_.get()));
    s.store_object_field("new_topic_info", static_cast<const BaseObject *>(new_topic_info_.get()));
    s.store_class_end();
  }
}

chatEventForumTopicToggleIsClosed::chatEventForumTopicToggleIsClosed()
  : topic_info_()
{}

chatEventForumTopicToggleIsClosed::chatEventForumTopicToggleIsClosed(object_ptr<forumTopicInfo> &&topic_info_)
  : topic_info_(std::move(topic_info_))
{}

const std::int32_t chatEventForumTopicToggleIsClosed::ID;

void chatEventForumTopicToggleIsClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicToggleIsClosed");
    s.store_object_field("topic_info", static_cast<const BaseObject *>(topic_info_.get()));
    s.store_class_end();
  }
}

chatEventForumTopicToggleIsHidden::chatEventForumTopicToggleIsHidden()
  : topic_info_()
{}

chatEventForumTopicToggleIsHidden::chatEventForumTopicToggleIsHidden(object_ptr<forumTopicInfo> &&topic_info_)
  : topic_info_(std::move(topic_info_))
{}

const std::int32_t chatEventForumTopicToggleIsHidden::ID;

void chatEventForumTopicToggleIsHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicToggleIsHidden");
    s.store_object_field("topic_info", static_cast<const BaseObject *>(topic_info_.get()));
    s.store_class_end();
  }
}

chatEventForumTopicDeleted::chatEventForumTopicDeleted()
  : topic_info_()
{}

chatEventForumTopicDeleted::chatEventForumTopicDeleted(object_ptr<forumTopicInfo> &&topic_info_)
  : topic_info_(std::move(topic_info_))
{}

const std::int32_t chatEventForumTopicDeleted::ID;

void chatEventForumTopicDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicDeleted");
    s.store_object_field("topic_info", static_cast<const BaseObject *>(topic_info_.get()));
    s.store_class_end();
  }
}

chatEventForumTopicPinned::chatEventForumTopicPinned()
  : old_topic_info_()
  , new_topic_info_()
{}

chatEventForumTopicPinned::chatEventForumTopicPinned(object_ptr<forumTopicInfo> &&old_topic_info_, object_ptr<forumTopicInfo> &&new_topic_info_)
  : old_topic_info_(std::move(old_topic_info_))
  , new_topic_info_(std::move(new_topic_info_))
{}

const std::int32_t chatEventForumTopicPinned::ID;

void chatEventForumTopicPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicPinned");
    s.store_object_field("old_topic_info", static_cast<const BaseObject *>(old_topic_info_.get()));
    s.store_object_field("new_topic_info", static_cast<const BaseObject *>(new_topic_info_.get()));
    s.store_class_end();
  }
}

chatInviteLinks::chatInviteLinks()
  : total_count_()
  , invite_links_()
{}

chatInviteLinks::chatInviteLinks(int32 total_count_, array<object_ptr<chatInviteLink>> &&invite_links_)
  : total_count_(total_count_)
  , invite_links_(std::move(invite_links_))
{}

const std::int32_t chatInviteLinks::ID;

void chatInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinks");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("invite_links", invite_links_.size()); for (const auto &_value : invite_links_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatPosition::chatPosition()
  : list_()
  , order_()
  , is_pinned_()
  , source_()
{}

chatPosition::chatPosition(object_ptr<ChatList> &&list_, int64 order_, bool is_pinned_, object_ptr<ChatSource> &&source_)
  : list_(std::move(list_))
  , order_(order_)
  , is_pinned_(is_pinned_)
  , source_(std::move(source_))
{}

const std::int32_t chatPosition::ID;

void chatPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPosition");
    s.store_object_field("list", static_cast<const BaseObject *>(list_.get()));
    s.store_field("order", order_);
    s.store_field("is_pinned", is_pinned_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

chatStatisticsInteractionInfo::chatStatisticsInteractionInfo()
  : object_type_()
  , view_count_()
  , forward_count_()
  , reaction_count_()
{}

chatStatisticsInteractionInfo::chatStatisticsInteractionInfo(object_ptr<ChatStatisticsObjectType> &&object_type_, int32 view_count_, int32 forward_count_, int32 reaction_count_)
  : object_type_(std::move(object_type_))
  , view_count_(view_count_)
  , forward_count_(forward_count_)
  , reaction_count_(reaction_count_)
{}

const std::int32_t chatStatisticsInteractionInfo::ID;

void chatStatisticsInteractionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsInteractionInfo");
    s.store_object_field("object_type", static_cast<const BaseObject *>(object_type_.get()));
    s.store_field("view_count", view_count_);
    s.store_field("forward_count", forward_count_);
    s.store_field("reaction_count", reaction_count_);
    s.store_class_end();
  }
}

checklistTask::checklistTask()
  : id_()
  , text_()
  , completed_by_()
  , completion_date_()
{}

checklistTask::checklistTask(int32 id_, object_ptr<formattedText> &&text_, object_ptr<MessageSender> &&completed_by_, int32 completion_date_)
  : id_(id_)
  , text_(std::move(text_))
  , completed_by_(std::move(completed_by_))
  , completion_date_(completion_date_)
{}

const std::int32_t checklistTask::ID;

void checklistTask::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checklistTask");
    s.store_field("id", id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("completed_by", static_cast<const BaseObject *>(completed_by_.get()));
    s.store_field("completion_date", completion_date_);
    s.store_class_end();
  }
}

collectibleItemInfo::collectibleItemInfo()
  : purchase_date_()
  , currency_()
  , amount_()
  , cryptocurrency_()
  , cryptocurrency_amount_()
  , url_()
{}

collectibleItemInfo::collectibleItemInfo(int32 purchase_date_, string const &currency_, int53 amount_, string const &cryptocurrency_, int64 cryptocurrency_amount_, string const &url_)
  : purchase_date_(purchase_date_)
  , currency_(currency_)
  , amount_(amount_)
  , cryptocurrency_(cryptocurrency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , url_(url_)
{}

const std::int32_t collectibleItemInfo::ID;

void collectibleItemInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "collectibleItemInfo");
    s.store_field("purchase_date", purchase_date_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

connectedWebsites::connectedWebsites()
  : websites_()
{}

connectedWebsites::connectedWebsites(array<object_ptr<connectedWebsite>> &&websites_)
  : websites_(std::move(websites_))
{}

const std::int32_t connectedWebsites::ID;

void connectedWebsites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedWebsites");
    { s.store_vector_begin("websites", websites_.size()); for (const auto &_value : websites_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

countryInfo::countryInfo()
  : country_code_()
  , name_()
  , english_name_()
  , flag_emoji_()
  , is_hidden_()
  , calling_codes_()
{}

countryInfo::countryInfo(string const &country_code_, string const &name_, string const &english_name_, string const &flag_emoji_, bool is_hidden_, array<string> &&calling_codes_)
  : country_code_(country_code_)
  , name_(name_)
  , english_name_(english_name_)
  , flag_emoji_(flag_emoji_)
  , is_hidden_(is_hidden_)
  , calling_codes_(std::move(calling_codes_))
{}

const std::int32_t countryInfo::ID;

void countryInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "countryInfo");
    s.store_field("country_code", country_code_);
    s.store_field("name", name_);
    s.store_field("english_name", english_name_);
    s.store_field("flag_emoji", flag_emoji_);
    s.store_field("is_hidden", is_hidden_);
    { s.store_vector_begin("calling_codes", calling_codes_.size()); for (const auto &_value : calling_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

downloadedFileCounts::downloadedFileCounts()
  : active_count_()
  , paused_count_()
  , completed_count_()
{}

downloadedFileCounts::downloadedFileCounts(int32 active_count_, int32 paused_count_, int32 completed_count_)
  : active_count_(active_count_)
  , paused_count_(paused_count_)
  , completed_count_(completed_count_)
{}

const std::int32_t downloadedFileCounts::ID;

void downloadedFileCounts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "downloadedFileCounts");
    s.store_field("active_count", active_count_);
    s.store_field("paused_count", paused_count_);
    s.store_field("completed_count", completed_count_);
    s.store_class_end();
  }
}

emojiCategorySourceSearch::emojiCategorySourceSearch()
  : emojis_()
{}

emojiCategorySourceSearch::emojiCategorySourceSearch(array<string> &&emojis_)
  : emojis_(std::move(emojis_))
{}

const std::int32_t emojiCategorySourceSearch::ID;

void emojiCategorySourceSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategorySourceSearch");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

emojiCategorySourcePremium::emojiCategorySourcePremium() {
}

const std::int32_t emojiCategorySourcePremium::ID;

void emojiCategorySourcePremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategorySourcePremium");
    s.store_class_end();
  }
}

giftAuctionAcquiredGift::giftAuctionAcquiredGift()
  : receiver_id_()
  , date_()
  , star_count_()
  , auction_round_number_()
  , auction_round_position_()
  , unique_gift_number_()
  , text_()
  , is_private_()
{}

giftAuctionAcquiredGift::giftAuctionAcquiredGift(object_ptr<MessageSender> &&receiver_id_, int32 date_, int53 star_count_, int32 auction_round_number_, int32 auction_round_position_, int32 unique_gift_number_, object_ptr<formattedText> &&text_, bool is_private_)
  : receiver_id_(std::move(receiver_id_))
  , date_(date_)
  , star_count_(star_count_)
  , auction_round_number_(auction_round_number_)
  , auction_round_position_(auction_round_position_)
  , unique_gift_number_(unique_gift_number_)
  , text_(std::move(text_))
  , is_private_(is_private_)
{}

const std::int32_t giftAuctionAcquiredGift::ID;

void giftAuctionAcquiredGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftAuctionAcquiredGift");
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_field("date", date_);
    s.store_field("star_count", star_count_);
    s.store_field("auction_round_number", auction_round_number_);
    s.store_field("auction_round_position", auction_round_position_);
    s.store_field("unique_gift_number", unique_gift_number_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_private", is_private_);
    s.store_class_end();
  }
}

giftCollections::giftCollections()
  : collections_()
{}

giftCollections::giftCollections(array<object_ptr<giftCollection>> &&collections_)
  : collections_(std::move(collections_))
{}

const std::int32_t giftCollections::ID;

void giftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftCollections");
    { s.store_vector_begin("collections", collections_.size()); for (const auto &_value : collections_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inlineQueryResultsButton::inlineQueryResultsButton()
  : text_()
  , type_()
{}

inlineQueryResultsButton::inlineQueryResultsButton(string const &text_, object_ptr<InlineQueryResultsButtonType> &&type_)
  : text_(text_)
  , type_(std::move(type_))
{}

const std::int32_t inlineQueryResultsButton::ID;

void inlineQueryResultsButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultsButton");
    s.store_field("text", text_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

inputMessageText::inputMessageText()
  : text_()
  , link_preview_options_()
  , clear_draft_()
{}

inputMessageText::inputMessageText(object_ptr<formattedText> &&text_, object_ptr<linkPreviewOptions> &&link_preview_options_, bool clear_draft_)
  : text_(std::move(text_))
  , link_preview_options_(std::move(link_preview_options_))
  , clear_draft_(clear_draft_)
{}

const std::int32_t inputMessageText::ID;

void inputMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("link_preview_options", static_cast<const BaseObject *>(link_preview_options_.get()));
    s.store_field("clear_draft", clear_draft_);
    s.store_class_end();
  }
}

inputMessageRichMessage::inputMessageRichMessage()
  : message_()
  , clear_draft_()
{}

inputMessageRichMessage::inputMessageRichMessage(object_ptr<inputRichMessage> &&message_, bool clear_draft_)
  : message_(std::move(message_))
  , clear_draft_(clear_draft_)
{}

const std::int32_t inputMessageRichMessage::ID;

void inputMessageRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageRichMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("clear_draft", clear_draft_);
    s.store_class_end();
  }
}

inputMessageAnimation::inputMessageAnimation()
  : animation_()
  , caption_()
  , show_caption_above_media_()
  , has_spoiler_()
{}

inputMessageAnimation::inputMessageAnimation(object_ptr<inputAnimation> &&animation_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, bool has_spoiler_)
  : animation_(std::move(animation_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t inputMessageAnimation::ID;

void inputMessageAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

inputMessageAudio::inputMessageAudio()
  : audio_()
  , caption_()
{}

inputMessageAudio::inputMessageAudio(object_ptr<inputAudio> &&audio_, object_ptr<formattedText> &&caption_)
  : audio_(std::move(audio_))
  , caption_(std::move(caption_))
{}

const std::int32_t inputMessageAudio::ID;

void inputMessageAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputMessageDocument::inputMessageDocument()
  : document_()
  , caption_()
{}

inputMessageDocument::inputMessageDocument(object_ptr<inputDocument> &&document_, object_ptr<formattedText> &&caption_)
  : document_(std::move(document_))
  , caption_(std::move(caption_))
{}

const std::int32_t inputMessageDocument::ID;

void inputMessageDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputMessagePaidMedia::inputMessagePaidMedia()
  : star_count_()
  , paid_media_()
  , caption_()
  , show_caption_above_media_()
  , payload_()
{}

inputMessagePaidMedia::inputMessagePaidMedia(int53 star_count_, array<object_ptr<inputPaidMedia>> &&paid_media_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, string const &payload_)
  : star_count_(star_count_)
  , paid_media_(std::move(paid_media_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , payload_(payload_)
{}

const std::int32_t inputMessagePaidMedia::ID;

void inputMessagePaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagePaidMedia");
    s.store_field("star_count", star_count_);
    { s.store_vector_begin("paid_media", paid_media_.size()); for (const auto &_value : paid_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

inputMessagePhoto::inputMessagePhoto()
  : photo_()
  , caption_()
  , show_caption_above_media_()
  , self_destruct_type_()
  , has_spoiler_()
{}

inputMessagePhoto::inputMessagePhoto(object_ptr<inputPhoto> &&photo_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, object_ptr<MessageSelfDestructType> &&self_destruct_type_, bool has_spoiler_)
  : photo_(std::move(photo_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , self_destruct_type_(std::move(self_destruct_type_))
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t inputMessagePhoto::ID;

void inputMessagePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

inputMessageSticker::inputMessageSticker()
  : sticker_()
  , emoji_()
{}

inputMessageSticker::inputMessageSticker(object_ptr<inputSticker> &&sticker_, string const &emoji_)
  : sticker_(std::move(sticker_))
  , emoji_(emoji_)
{}

const std::int32_t inputMessageSticker::ID;

void inputMessageSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

inputMessageVideo::inputMessageVideo()
  : video_()
  , caption_()
  , show_caption_above_media_()
  , self_destruct_type_()
  , has_spoiler_()
{}

inputMessageVideo::inputMessageVideo(object_ptr<inputVideo> &&video_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, object_ptr<MessageSelfDestructType> &&self_destruct_type_, bool has_spoiler_)
  : video_(std::move(video_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , self_destruct_type_(std::move(self_destruct_type_))
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t inputMessageVideo::ID;

void inputMessageVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

inputMessageVideoNote::inputMessageVideoNote()
  : video_note_()
  , self_destruct_type_()
{}

inputMessageVideoNote::inputMessageVideoNote(object_ptr<inputVideoNote> &&video_note_, object_ptr<MessageSelfDestructType> &&self_destruct_type_)
  : video_note_(std::move(video_note_))
  , self_destruct_type_(std::move(self_destruct_type_))
{}

const std::int32_t inputMessageVideoNote::ID;

void inputMessageVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_class_end();
  }
}

inputMessageVoiceNote::inputMessageVoiceNote()
  : voice_note_()
  , caption_()
  , self_destruct_type_()
{}

inputMessageVoiceNote::inputMessageVoiceNote(object_ptr<inputVoiceNote> &&voice_note_, object_ptr<formattedText> &&caption_, object_ptr<MessageSelfDestructType> &&self_destruct_type_)
  : voice_note_(std::move(voice_note_))
  , caption_(std::move(caption_))
  , self_destruct_type_(std::move(self_destruct_type_))
{}

const std::int32_t inputMessageVoiceNote::ID;

void inputMessageVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_class_end();
  }
}

inputMessageLiveLocation::inputMessageLiveLocation()
  : location_()
{}

inputMessageLiveLocation::inputMessageLiveLocation(object_ptr<liveLocation> &&location_)
  : location_(std::move(location_))
{}

const std::int32_t inputMessageLiveLocation::ID;

void inputMessageLiveLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageLiveLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

inputMessageLocation::inputMessageLocation()
  : location_()
{}

inputMessageLocation::inputMessageLocation(object_ptr<location> &&location_)
  : location_(std::move(location_))
{}

const std::int32_t inputMessageLocation::ID;

void inputMessageLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

inputMessageVenue::inputMessageVenue()
  : venue_()
{}

inputMessageVenue::inputMessageVenue(object_ptr<venue> &&venue_)
  : venue_(std::move(venue_))
{}

const std::int32_t inputMessageVenue::ID;

void inputMessageVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVenue");
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_class_end();
  }
}

inputMessageContact::inputMessageContact()
  : contact_()
{}

inputMessageContact::inputMessageContact(object_ptr<contact> &&contact_)
  : contact_(std::move(contact_))
{}

const std::int32_t inputMessageContact::ID;

void inputMessageContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageContact");
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_class_end();
  }
}

inputMessageDice::inputMessageDice()
  : emoji_()
  , clear_draft_()
{}

inputMessageDice::inputMessageDice(string const &emoji_, bool clear_draft_)
  : emoji_(emoji_)
  , clear_draft_(clear_draft_)
{}

const std::int32_t inputMessageDice::ID;

void inputMessageDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageDice");
    s.store_field("emoji", emoji_);
    s.store_field("clear_draft", clear_draft_);
    s.store_class_end();
  }
}

inputMessageGame::inputMessageGame()
  : bot_user_id_()
  , game_short_name_()
{}

inputMessageGame::inputMessageGame(int53 bot_user_id_, string const &game_short_name_)
  : bot_user_id_(bot_user_id_)
  , game_short_name_(game_short_name_)
{}

const std::int32_t inputMessageGame::ID;

void inputMessageGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageGame");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("game_short_name", game_short_name_);
    s.store_class_end();
  }
}

inputMessageInvoice::inputMessageInvoice()
  : invoice_()
  , title_()
  , description_()
  , photo_url_()
  , photo_size_()
  , photo_width_()
  , photo_height_()
  , payload_()
  , provider_token_()
  , provider_data_()
  , start_parameter_()
  , paid_media_()
  , paid_media_caption_()
{}

inputMessageInvoice::inputMessageInvoice(object_ptr<invoice> &&invoice_, string const &title_, string const &description_, string const &photo_url_, int32 photo_size_, int32 photo_width_, int32 photo_height_, bytes const &payload_, string const &provider_token_, string const &provider_data_, string const &start_parameter_, object_ptr<inputPaidMedia> &&paid_media_, object_ptr<formattedText> &&paid_media_caption_)
  : invoice_(std::move(invoice_))
  , title_(title_)
  , description_(description_)
  , photo_url_(photo_url_)
  , photo_size_(photo_size_)
  , photo_width_(photo_width_)
  , photo_height_(photo_height_)
  , payload_(std::move(payload_))
  , provider_token_(provider_token_)
  , provider_data_(provider_data_)
  , start_parameter_(start_parameter_)
  , paid_media_(std::move(paid_media_))
  , paid_media_caption_(std::move(paid_media_caption_))
{}

const std::int32_t inputMessageInvoice::ID;

void inputMessageInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageInvoice");
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("photo_url", photo_url_);
    s.store_field("photo_size", photo_size_);
    s.store_field("photo_width", photo_width_);
    s.store_field("photo_height", photo_height_);
    s.store_bytes_field("payload", payload_);
    s.store_field("provider_token", "[REDACTED]");
    s.store_field("provider_data", provider_data_);
    s.store_field("start_parameter", start_parameter_);
    s.store_object_field("paid_media", static_cast<const BaseObject *>(paid_media_.get()));
    s.store_object_field("paid_media_caption", static_cast<const BaseObject *>(paid_media_caption_.get()));
    s.store_class_end();
  }
}

inputMessagePoll::inputMessagePoll()
  : question_()
  , options_()
  , description_()
  , media_()
  , is_anonymous_()
  , allows_multiple_answers_()
  , allows_revoting_()
  , members_only_()
  , country_codes_()
  , shuffle_options_()
  , hide_results_until_closes_()
  , type_()
  , open_period_()
  , close_date_()
  , is_closed_()
{}

inputMessagePoll::inputMessagePoll(object_ptr<formattedText> &&question_, array<object_ptr<inputPollOption>> &&options_, object_ptr<formattedText> &&description_, object_ptr<InputPollMedia> &&media_, bool is_anonymous_, bool allows_multiple_answers_, bool allows_revoting_, bool members_only_, array<string> &&country_codes_, bool shuffle_options_, bool hide_results_until_closes_, object_ptr<InputPollType> &&type_, int32 open_period_, int32 close_date_, bool is_closed_)
  : question_(std::move(question_))
  , options_(std::move(options_))
  , description_(std::move(description_))
  , media_(std::move(media_))
  , is_anonymous_(is_anonymous_)
  , allows_multiple_answers_(allows_multiple_answers_)
  , allows_revoting_(allows_revoting_)
  , members_only_(members_only_)
  , country_codes_(std::move(country_codes_))
  , shuffle_options_(shuffle_options_)
  , hide_results_until_closes_(hide_results_until_closes_)
  , type_(std::move(type_))
  , open_period_(open_period_)
  , close_date_(close_date_)
  , is_closed_(is_closed_)
{}

const std::int32_t inputMessagePoll::ID;

void inputMessagePoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagePoll");
    s.store_object_field("question", static_cast<const BaseObject *>(question_.get()));
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_field("is_anonymous", is_anonymous_);
    s.store_field("allows_multiple_answers", allows_multiple_answers_);
    s.store_field("allows_revoting", allows_revoting_);
    s.store_field("members_only", members_only_);
    { s.store_vector_begin("country_codes", country_codes_.size()); for (const auto &_value : country_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("shuffle_options", shuffle_options_);
    s.store_field("hide_results_until_closes", hide_results_until_closes_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("open_period", open_period_);
    s.store_field("close_date", close_date_);
    s.store_field("is_closed", is_closed_);
    s.store_class_end();
  }
}

inputMessageStakeDice::inputMessageStakeDice()
  : state_hash_()
  , stake_gram_amount_()
  , clear_draft_()
{}

inputMessageStakeDice::inputMessageStakeDice(string const &state_hash_, int53 stake_gram_amount_, bool clear_draft_)
  : state_hash_(state_hash_)
  , stake_gram_amount_(stake_gram_amount_)
  , clear_draft_(clear_draft_)
{}

const std::int32_t inputMessageStakeDice::ID;

void inputMessageStakeDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageStakeDice");
    s.store_field("state_hash", state_hash_);
    s.store_field("stake_gram_amount", stake_gram_amount_);
    s.store_field("clear_draft", clear_draft_);
    s.store_class_end();
  }
}

inputMessageStory::inputMessageStory()
  : story_poster_chat_id_()
  , story_id_()
{}

inputMessageStory::inputMessageStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t inputMessageStory::ID;

void inputMessageStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

inputMessageChecklist::inputMessageChecklist()
  : checklist_()
{}

inputMessageChecklist::inputMessageChecklist(object_ptr<inputChecklist> &&checklist_)
  : checklist_(std::move(checklist_))
{}

const std::int32_t inputMessageChecklist::ID;

void inputMessageChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageChecklist");
    s.store_object_field("checklist", static_cast<const BaseObject *>(checklist_.get()));
    s.store_class_end();
  }
}

inputMessageWidget::inputMessageWidget()
  : width_()
  , height_()
  , html_()
  , public_data_()
  , chat_data_()
  , caption_()
  , show_caption_above_media_()
  , allow_queries_()
  , is_shared_()
{}

inputMessageWidget::inputMessageWidget(int32 width_, int32 height_, string const &html_, string const &public_data_, string const &chat_data_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, bool allow_queries_, bool is_shared_)
  : width_(width_)
  , height_(height_)
  , html_(html_)
  , public_data_(public_data_)
  , chat_data_(chat_data_)
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , allow_queries_(allow_queries_)
  , is_shared_(is_shared_)
{}

const std::int32_t inputMessageWidget::ID;

void inputMessageWidget::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageWidget");
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("html", html_);
    s.store_field("public_data", public_data_);
    s.store_field("chat_data", chat_data_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("allow_queries", allow_queries_);
    s.store_field("is_shared", is_shared_);
    s.store_class_end();
  }
}

inputMessageSharedWidget::inputMessageSharedWidget()
  : widget_id_()
  , chat_data_()
  , caption_()
  , show_caption_above_media_()
{}

inputMessageSharedWidget::inputMessageSharedWidget(int64 widget_id_, string const &chat_data_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_)
  : widget_id_(widget_id_)
  , chat_data_(chat_data_)
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
{}

const std::int32_t inputMessageSharedWidget::ID;

void inputMessageSharedWidget::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageSharedWidget");
    s.store_field("widget_id", widget_id_);
    s.store_field("chat_data", chat_data_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_class_end();
  }
}

inputMessageForwarded::inputMessageForwarded()
  : from_chat_id_()
  , message_id_()
  , in_game_share_()
  , replace_video_start_timestamp_()
  , new_video_start_timestamp_()
  , copy_options_()
{}

inputMessageForwarded::inputMessageForwarded(int53 from_chat_id_, int53 message_id_, bool in_game_share_, bool replace_video_start_timestamp_, int32 new_video_start_timestamp_, object_ptr<messageCopyOptions> &&copy_options_)
  : from_chat_id_(from_chat_id_)
  , message_id_(message_id_)
  , in_game_share_(in_game_share_)
  , replace_video_start_timestamp_(replace_video_start_timestamp_)
  , new_video_start_timestamp_(new_video_start_timestamp_)
  , copy_options_(std::move(copy_options_))
{}

const std::int32_t inputMessageForwarded::ID;

void inputMessageForwarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageForwarded");
    s.store_field("from_chat_id", from_chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("in_game_share", in_game_share_);
    s.store_field("replace_video_start_timestamp", replace_video_start_timestamp_);
    s.store_field("new_video_start_timestamp", new_video_start_timestamp_);
    s.store_object_field("copy_options", static_cast<const BaseObject *>(copy_options_.get()));
    s.store_class_end();
  }
}

inputPaidMedia::inputPaidMedia()
  : type_()
  , media_()
  , thumbnail_()
  , added_sticker_file_ids_()
  , width_()
  , height_()
{}

inputPaidMedia::inputPaidMedia(object_ptr<InputPaidMediaType> &&type_, object_ptr<InputFile> &&media_, object_ptr<inputThumbnail> &&thumbnail_, array<int32> &&added_sticker_file_ids_, int32 width_, int32 height_)
  : type_(std::move(type_))
  , media_(std::move(media_))
  , thumbnail_(std::move(thumbnail_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , width_(width_)
  , height_(height_)
{}

const std::int32_t inputPaidMedia::ID;

void inputPaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaidMedia");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceUnspecified::inputPassportElementErrorSourceUnspecified()
  : element_hash_()
{}

inputPassportElementErrorSourceUnspecified::inputPassportElementErrorSourceUnspecified(bytes const &element_hash_)
  : element_hash_(std::move(element_hash_))
{}

const std::int32_t inputPassportElementErrorSourceUnspecified::ID;

void inputPassportElementErrorSourceUnspecified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceUnspecified");
    s.store_bytes_field("element_hash", element_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceDataField::inputPassportElementErrorSourceDataField()
  : field_name_()
  , data_hash_()
{}

inputPassportElementErrorSourceDataField::inputPassportElementErrorSourceDataField(string const &field_name_, bytes const &data_hash_)
  : field_name_(field_name_)
  , data_hash_(std::move(data_hash_))
{}

const std::int32_t inputPassportElementErrorSourceDataField::ID;

void inputPassportElementErrorSourceDataField::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceDataField");
    s.store_field("field_name", field_name_);
    s.store_bytes_field("data_hash", data_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceFrontSide::inputPassportElementErrorSourceFrontSide()
  : file_hash_()
{}

inputPassportElementErrorSourceFrontSide::inputPassportElementErrorSourceFrontSide(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceFrontSide::ID;

void inputPassportElementErrorSourceFrontSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceFrontSide");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceReverseSide::inputPassportElementErrorSourceReverseSide()
  : file_hash_()
{}

inputPassportElementErrorSourceReverseSide::inputPassportElementErrorSourceReverseSide(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceReverseSide::ID;

void inputPassportElementErrorSourceReverseSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceReverseSide");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceSelfie::inputPassportElementErrorSourceSelfie()
  : file_hash_()
{}

inputPassportElementErrorSourceSelfie::inputPassportElementErrorSourceSelfie(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceSelfie::ID;

void inputPassportElementErrorSourceSelfie::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceSelfie");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceTranslationFile::inputPassportElementErrorSourceTranslationFile()
  : file_hash_()
{}

inputPassportElementErrorSourceTranslationFile::inputPassportElementErrorSourceTranslationFile(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceTranslationFile::ID;

void inputPassportElementErrorSourceTranslationFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceTranslationFile");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceTranslationFiles::inputPassportElementErrorSourceTranslationFiles()
  : file_hashes_()
{}

inputPassportElementErrorSourceTranslationFiles::inputPassportElementErrorSourceTranslationFiles(array<bytes> &&file_hashes_)
  : file_hashes_(std::move(file_hashes_))
{}

const std::int32_t inputPassportElementErrorSourceTranslationFiles::ID;

void inputPassportElementErrorSourceTranslationFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceTranslationFiles");
    { s.store_vector_begin("file_hashes", file_hashes_.size()); for (const auto &_value : file_hashes_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPassportElementErrorSourceFile::inputPassportElementErrorSourceFile()
  : file_hash_()
{}

inputPassportElementErrorSourceFile::inputPassportElementErrorSourceFile(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceFile::ID;

void inputPassportElementErrorSourceFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceFile");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceFiles::inputPassportElementErrorSourceFiles()
  : file_hashes_()
{}

inputPassportElementErrorSourceFiles::inputPassportElementErrorSourceFiles(array<bytes> &&file_hashes_)
  : file_hashes_(std::move(file_hashes_))
{}

const std::int32_t inputPassportElementErrorSourceFiles::ID;

void inputPassportElementErrorSourceFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceFiles");
    { s.store_vector_begin("file_hashes", file_hashes_.size()); for (const auto &_value : file_hashes_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputProfileShareThemeEmoji::inputProfileShareThemeEmoji()
  : emojis_()
  , use_default_background_()
  , background_backdrop_id_()
{}

inputProfileShareThemeEmoji::inputProfileShareThemeEmoji(array<object_ptr<EmojiType>> &&emojis_, bool use_default_background_, int32 background_backdrop_id_)
  : emojis_(std::move(emojis_))
  , use_default_background_(use_default_background_)
  , background_backdrop_id_(background_backdrop_id_)
{}

const std::int32_t inputProfileShareThemeEmoji::ID;

void inputProfileShareThemeEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputProfileShareThemeEmoji");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("use_default_background", use_default_background_);
    s.store_field("background_backdrop_id", background_backdrop_id_);
    s.store_class_end();
  }
}

inputProfileShareThemeUpgradedGift::inputProfileShareThemeUpgradedGift()
  : received_gift_id_()
{}

inputProfileShareThemeUpgradedGift::inputProfileShareThemeUpgradedGift(string const &received_gift_id_)
  : received_gift_id_(received_gift_id_)
{}

const std::int32_t inputProfileShareThemeUpgradedGift::ID;

void inputProfileShareThemeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputProfileShareThemeUpgradedGift");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

inputTextQuote::inputTextQuote()
  : text_()
  , rich_texts_()
  , position_()
{}

inputTextQuote::inputTextQuote(object_ptr<formattedText> &&text_, array<object_ptr<RichText>> &&rich_texts_, int32 position_)
  : text_(std::move(text_))
  , rich_texts_(std::move(rich_texts_))
  , position_(position_)
{}

const std::int32_t inputTextQuote::ID;

void inputTextQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputTextQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    { s.store_vector_begin("rich_texts", rich_texts_.size()); for (const auto &_value : rich_texts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("position", position_);
    s.store_class_end();
  }
}

inviteGroupCallParticipantResultUserPrivacyRestricted::inviteGroupCallParticipantResultUserPrivacyRestricted() {
}

const std::int32_t inviteGroupCallParticipantResultUserPrivacyRestricted::ID;

void inviteGroupCallParticipantResultUserPrivacyRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteGroupCallParticipantResultUserPrivacyRestricted");
    s.store_class_end();
  }
}

inviteGroupCallParticipantResultUserAlreadyParticipant::inviteGroupCallParticipantResultUserAlreadyParticipant() {
}

const std::int32_t inviteGroupCallParticipantResultUserAlreadyParticipant::ID;

void inviteGroupCallParticipantResultUserAlreadyParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteGroupCallParticipantResultUserAlreadyParticipant");
    s.store_class_end();
  }
}

inviteGroupCallParticipantResultUserWasBanned::inviteGroupCallParticipantResultUserWasBanned() {
}

const std::int32_t inviteGroupCallParticipantResultUserWasBanned::ID;

void inviteGroupCallParticipantResultUserWasBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteGroupCallParticipantResultUserWasBanned");
    s.store_class_end();
  }
}

inviteGroupCallParticipantResultSuccess::inviteGroupCallParticipantResultSuccess()
  : chat_id_()
  , message_id_()
{}

inviteGroupCallParticipantResultSuccess::inviteGroupCallParticipantResultSuccess(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t inviteGroupCallParticipantResultSuccess::ID;

void inviteGroupCallParticipantResultSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteGroupCallParticipantResultSuccess");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

inviteLinkChatTypeBasicGroup::inviteLinkChatTypeBasicGroup() {
}

const std::int32_t inviteLinkChatTypeBasicGroup::ID;

void inviteLinkChatTypeBasicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteLinkChatTypeBasicGroup");
    s.store_class_end();
  }
}

inviteLinkChatTypeSupergroup::inviteLinkChatTypeSupergroup() {
}

const std::int32_t inviteLinkChatTypeSupergroup::ID;

void inviteLinkChatTypeSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteLinkChatTypeSupergroup");
    s.store_class_end();
  }
}

inviteLinkChatTypeChannel::inviteLinkChatTypeChannel() {
}

const std::int32_t inviteLinkChatTypeChannel::ID;

void inviteLinkChatTypeChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteLinkChatTypeChannel");
    s.store_class_end();
  }
}

languagePackString::languagePackString()
  : key_()
  , value_()
{}

languagePackString::languagePackString(string const &key_, object_ptr<LanguagePackStringValue> &&value_)
  : key_(key_)
  , value_(std::move(value_))
{}

const std::int32_t languagePackString::ID;

void languagePackString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackString");
    s.store_field("key", key_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

liveLocation::liveLocation()
  : location_()
  , live_period_()
  , heading_()
  , proximity_alert_radius_()
{}

liveLocation::liveLocation(object_ptr<location> &&location_, int32 live_period_, int32 heading_, int32 proximity_alert_radius_)
  : location_(std::move(location_))
  , live_period_(live_period_)
  , heading_(heading_)
  , proximity_alert_radius_(proximity_alert_radius_)
{}

const std::int32_t liveLocation::ID;

void liveLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liveLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("live_period", live_period_);
    s.store_field("heading", heading_);
    s.store_field("proximity_alert_radius", proximity_alert_radius_);
    s.store_class_end();
  }
}

mainWebApp::mainWebApp()
  : url_()
  , mode_()
{}

mainWebApp::mainWebApp(object_ptr<webAppUrl> &&url_, object_ptr<WebAppOpenMode> &&mode_)
  : url_(std::move(url_))
  , mode_(std::move(mode_))
{}

const std::int32_t mainWebApp::ID;

void mainWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mainWebApp");
    s.store_object_field("url", static_cast<const BaseObject *>(url_.get()));
    s.store_object_field("mode", static_cast<const BaseObject *>(mode_.get()));
    s.store_class_end();
  }
}

messageAutoDeleteTime::messageAutoDeleteTime()
  : time_()
{}

messageAutoDeleteTime::messageAutoDeleteTime(int32 time_)
  : time_(time_)
{}

const std::int32_t messageAutoDeleteTime::ID;

void messageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageAutoDeleteTime");
    s.store_field("time", time_);
    s.store_class_end();
  }
}

messageCalendar::messageCalendar()
  : total_count_()
  , days_()
{}

messageCalendar::messageCalendar(int32 total_count_, array<object_ptr<messageCalendarDay>> &&days_)
  : total_count_(total_count_)
  , days_(std::move(days_))
{}

const std::int32_t messageCalendar::ID;

void messageCalendar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCalendar");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("days", days_.size()); for (const auto &_value : days_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messagePosition::messagePosition()
  : position_()
  , message_id_()
  , date_()
{}

messagePosition::messagePosition(int32 position_, int53 message_id_, int32 date_)
  : position_(position_)
  , message_id_(message_id_)
  , date_(date_)
{}

const std::int32_t messagePosition::ID;

void messagePosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePosition");
    s.store_field("position", position_);
    s.store_field("message_id", message_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

messageSchedulingStateSendAtDate::messageSchedulingStateSendAtDate()
  : send_date_()
  , repeat_period_()
{}

messageSchedulingStateSendAtDate::messageSchedulingStateSendAtDate(int32 send_date_, int32 repeat_period_)
  : send_date_(send_date_)
  , repeat_period_(repeat_period_)
{}

const std::int32_t messageSchedulingStateSendAtDate::ID;

void messageSchedulingStateSendAtDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSchedulingStateSendAtDate");
    s.store_field("send_date", send_date_);
    s.store_field("repeat_period", repeat_period_);
    s.store_class_end();
  }
}

messageSchedulingStateSendWhenOnline::messageSchedulingStateSendWhenOnline() {
}

const std::int32_t messageSchedulingStateSendWhenOnline::ID;

void messageSchedulingStateSendWhenOnline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSchedulingStateSendWhenOnline");
    s.store_class_end();
  }
}

messageSchedulingStateSendWhenVideoProcessed::messageSchedulingStateSendWhenVideoProcessed()
  : send_date_()
{}

messageSchedulingStateSendWhenVideoProcessed::messageSchedulingStateSendWhenVideoProcessed(int32 send_date_)
  : send_date_(send_date_)
{}

const std::int32_t messageSchedulingStateSendWhenVideoProcessed::ID;

void messageSchedulingStateSendWhenVideoProcessed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSchedulingStateSendWhenVideoProcessed");
    s.store_field("send_date", send_date_);
    s.store_class_end();
  }
}

messageSendOptions::messageSendOptions()
  : suggested_post_info_()
  , disable_notification_()
  , from_background_()
  , protect_content_()
  , allow_paid_broadcast_()
  , paid_message_star_count_()
  , update_order_of_installed_sticker_sets_()
  , scheduling_state_()
  , effect_id_()
  , sending_id_()
  , only_preview_()
{}

messageSendOptions::messageSendOptions(object_ptr<inputSuggestedPostInfo> &&suggested_post_info_, bool disable_notification_, bool from_background_, bool protect_content_, bool allow_paid_broadcast_, int53 paid_message_star_count_, bool update_order_of_installed_sticker_sets_, object_ptr<MessageSchedulingState> &&scheduling_state_, int64 effect_id_, int32 sending_id_, bool only_preview_)
  : suggested_post_info_(std::move(suggested_post_info_))
  , disable_notification_(disable_notification_)
  , from_background_(from_background_)
  , protect_content_(protect_content_)
  , allow_paid_broadcast_(allow_paid_broadcast_)
  , paid_message_star_count_(paid_message_star_count_)
  , update_order_of_installed_sticker_sets_(update_order_of_installed_sticker_sets_)
  , scheduling_state_(std::move(scheduling_state_))
  , effect_id_(effect_id_)
  , sending_id_(sending_id_)
  , only_preview_(only_preview_)
{}

const std::int32_t messageSendOptions::ID;

void messageSendOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSendOptions");
    s.store_object_field("suggested_post_info", static_cast<const BaseObject *>(suggested_post_info_.get()));
    s.store_field("disable_notification", disable_notification_);
    s.store_field("from_background", from_background_);
    s.store_field("protect_content", protect_content_);
    s.store_field("allow_paid_broadcast", allow_paid_broadcast_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_field("update_order_of_installed_sticker_sets", update_order_of_installed_sticker_sets_);
    s.store_object_field("scheduling_state", static_cast<const BaseObject *>(scheduling_state_.get()));
    s.store_field("effect_id", effect_id_);
    s.store_field("sending_id", sending_id_);
    s.store_field("only_preview", only_preview_);
    s.store_class_end();
  }
}

notificationGroupTypeMessages::notificationGroupTypeMessages() {
}

const std::int32_t notificationGroupTypeMessages::ID;

void notificationGroupTypeMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeMessages");
    s.store_class_end();
  }
}

notificationGroupTypeMentions::notificationGroupTypeMentions() {
}

const std::int32_t notificationGroupTypeMentions::ID;

void notificationGroupTypeMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeMentions");
    s.store_class_end();
  }
}

notificationGroupTypeSecretChat::notificationGroupTypeSecretChat() {
}

const std::int32_t notificationGroupTypeSecretChat::ID;

void notificationGroupTypeSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeSecretChat");
    s.store_class_end();
  }
}

notificationGroupTypeCalls::notificationGroupTypeCalls() {
}

const std::int32_t notificationGroupTypeCalls::ID;

void notificationGroupTypeCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeCalls");
    s.store_class_end();
  }
}

notificationSound::notificationSound()
  : id_()
  , duration_()
  , date_()
  , title_()
  , data_()
  , sound_()
{}

notificationSound::notificationSound(int64 id_, int32 duration_, int32 date_, string const &title_, string const &data_, object_ptr<file> &&sound_)
  : id_(id_)
  , duration_(duration_)
  , date_(date_)
  , title_(title_)
  , data_(data_)
  , sound_(std::move(sound_))
{}

const std::int32_t notificationSound::ID;

void notificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSound");
    s.store_field("id", id_);
    s.store_field("duration", duration_);
    s.store_field("date", date_);
    s.store_field("title", title_);
    s.store_field("data", data_);
    s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get()));
    s.store_class_end();
  }
}

onRampProviders::onRampProviders()
  : providers_()
{}

onRampProviders::onRampProviders(array<object_ptr<onRampProvider>> &&providers_)
  : providers_(std::move(providers_))
{}

const std::int32_t onRampProviders::ID;

void onRampProviders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onRampProviders");
    { s.store_vector_begin("providers", providers_.size()); for (const auto &_value : providers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

optionValueBoolean::optionValueBoolean()
  : value_()
{}

optionValueBoolean::optionValueBoolean(bool value_)
  : value_(value_)
{}

const std::int32_t optionValueBoolean::ID;

void optionValueBoolean::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueBoolean");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

optionValueEmpty::optionValueEmpty() {
}

const std::int32_t optionValueEmpty::ID;

void optionValueEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueEmpty");
    s.store_class_end();
  }
}

optionValueInteger::optionValueInteger()
  : value_()
{}

optionValueInteger::optionValueInteger(int64 value_)
  : value_(value_)
{}

const std::int32_t optionValueInteger::ID;

void optionValueInteger::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueInteger");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

optionValueString::optionValueString()
  : value_()
{}

optionValueString::optionValueString(string const &value_)
  : value_(value_)
{}

const std::int32_t optionValueString::ID;

void optionValueString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueString");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

pageBlockTableCell::pageBlockTableCell()
  : text_()
  , is_header_()
  , colspan_()
  , rowspan_()
  , align_()
  , valign_()
{}

pageBlockTableCell::pageBlockTableCell(object_ptr<RichText> &&text_, bool is_header_, int32 colspan_, int32 rowspan_, object_ptr<PageBlockHorizontalAlignment> &&align_, object_ptr<PageBlockVerticalAlignment> &&valign_)
  : text_(std::move(text_))
  , is_header_(is_header_)
  , colspan_(colspan_)
  , rowspan_(rowspan_)
  , align_(std::move(align_))
  , valign_(std::move(valign_))
{}

const std::int32_t pageBlockTableCell::ID;

void pageBlockTableCell::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTableCell");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_header", is_header_);
    s.store_field("colspan", colspan_);
    s.store_field("rowspan", rowspan_);
    s.store_object_field("align", static_cast<const BaseObject *>(align_.get()));
    s.store_object_field("valign", static_cast<const BaseObject *>(valign_.get()));
    s.store_class_end();
  }
}

paidReactor::paidReactor()
  : sender_id_()
  , star_count_()
  , is_top_()
  , is_me_()
  , is_anonymous_()
{}

paidReactor::paidReactor(object_ptr<MessageSender> &&sender_id_, int53 star_count_, bool is_top_, bool is_me_, bool is_anonymous_)
  : sender_id_(std::move(sender_id_))
  , star_count_(star_count_)
  , is_top_(is_top_)
  , is_me_(is_me_)
  , is_anonymous_(is_anonymous_)
{}

const std::int32_t paidReactor::ID;

void paidReactor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactor");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("star_count", star_count_);
    s.store_field("is_top", is_top_);
    s.store_field("is_me", is_me_);
    s.store_field("is_anonymous", is_anonymous_);
    s.store_class_end();
  }
}

passportElementError::passportElementError()
  : type_()
  , message_()
  , source_()
{}

passportElementError::passportElementError(object_ptr<PassportElementType> &&type_, string const &message_, object_ptr<PassportElementErrorSource> &&source_)
  : type_(std::move(type_))
  , message_(message_)
  , source_(std::move(source_))
{}

const std::int32_t passportElementError::ID;

void passportElementError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementError");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("message", message_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

passportElementTypePersonalDetails::passportElementTypePersonalDetails() {
}

const std::int32_t passportElementTypePersonalDetails::ID;

void passportElementTypePersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePersonalDetails");
    s.store_class_end();
  }
}

passportElementTypePassport::passportElementTypePassport() {
}

const std::int32_t passportElementTypePassport::ID;

void passportElementTypePassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePassport");
    s.store_class_end();
  }
}

passportElementTypeDriverLicense::passportElementTypeDriverLicense() {
}

const std::int32_t passportElementTypeDriverLicense::ID;

void passportElementTypeDriverLicense::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeDriverLicense");
    s.store_class_end();
  }
}

passportElementTypeIdentityCard::passportElementTypeIdentityCard() {
}

const std::int32_t passportElementTypeIdentityCard::ID;

void passportElementTypeIdentityCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeIdentityCard");
    s.store_class_end();
  }
}

passportElementTypeInternalPassport::passportElementTypeInternalPassport() {
}

const std::int32_t passportElementTypeInternalPassport::ID;

void passportElementTypeInternalPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeInternalPassport");
    s.store_class_end();
  }
}

passportElementTypeAddress::passportElementTypeAddress() {
}

const std::int32_t passportElementTypeAddress::ID;

void passportElementTypeAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeAddress");
    s.store_class_end();
  }
}

passportElementTypeUtilityBill::passportElementTypeUtilityBill() {
}

const std::int32_t passportElementTypeUtilityBill::ID;

void passportElementTypeUtilityBill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeUtilityBill");
    s.store_class_end();
  }
}

passportElementTypeBankStatement::passportElementTypeBankStatement() {
}

const std::int32_t passportElementTypeBankStatement::ID;

void passportElementTypeBankStatement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeBankStatement");
    s.store_class_end();
  }
}

passportElementTypeRentalAgreement::passportElementTypeRentalAgreement() {
}

const std::int32_t passportElementTypeRentalAgreement::ID;

void passportElementTypeRentalAgreement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeRentalAgreement");
    s.store_class_end();
  }
}

passportElementTypePassportRegistration::passportElementTypePassportRegistration() {
}

const std::int32_t passportElementTypePassportRegistration::ID;

void passportElementTypePassportRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePassportRegistration");
    s.store_class_end();
  }
}

passportElementTypeTemporaryRegistration::passportElementTypeTemporaryRegistration() {
}

const std::int32_t passportElementTypeTemporaryRegistration::ID;

void passportElementTypeTemporaryRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeTemporaryRegistration");
    s.store_class_end();
  }
}

passportElementTypePhoneNumber::passportElementTypePhoneNumber() {
}

const std::int32_t passportElementTypePhoneNumber::ID;

void passportElementTypePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePhoneNumber");
    s.store_class_end();
  }
}

passportElementTypeEmailAddress::passportElementTypeEmailAddress() {
}

const std::int32_t passportElementTypeEmailAddress::ID;

void passportElementTypeEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeEmailAddress");
    s.store_class_end();
  }
}

paymentForm::paymentForm()
  : id_()
  , type_()
  , seller_bot_user_id_()
  , product_info_()
{}

paymentForm::paymentForm(int64 id_, object_ptr<PaymentFormType> &&type_, int53 seller_bot_user_id_, object_ptr<productInfo> &&product_info_)
  : id_(id_)
  , type_(std::move(type_))
  , seller_bot_user_id_(seller_bot_user_id_)
  , product_info_(std::move(product_info_))
{}

const std::int32_t paymentForm::ID;

void paymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentForm");
    s.store_field("id", id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("seller_bot_user_id", seller_bot_user_id_);
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_class_end();
  }
}

phoneNumberCodeTypeChange::phoneNumberCodeTypeChange() {
}

const std::int32_t phoneNumberCodeTypeChange::ID;

void phoneNumberCodeTypeChange::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberCodeTypeChange");
    s.store_class_end();
  }
}

phoneNumberCodeTypeVerify::phoneNumberCodeTypeVerify() {
}

const std::int32_t phoneNumberCodeTypeVerify::ID;

void phoneNumberCodeTypeVerify::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberCodeTypeVerify");
    s.store_class_end();
  }
}

phoneNumberCodeTypeConfirmOwnership::phoneNumberCodeTypeConfirmOwnership()
  : hash_()
{}

phoneNumberCodeTypeConfirmOwnership::phoneNumberCodeTypeConfirmOwnership(string const &hash_)
  : hash_(hash_)
{}

const std::int32_t phoneNumberCodeTypeConfirmOwnership::ID;

void phoneNumberCodeTypeConfirmOwnership::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberCodeTypeConfirmOwnership");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

pollVoteRestrictionReasonClosed::pollVoteRestrictionReasonClosed() {
}

const std::int32_t pollVoteRestrictionReasonClosed::ID;

void pollVoteRestrictionReasonClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollVoteRestrictionReasonClosed");
    s.store_class_end();
  }
}

pollVoteRestrictionReasonYetUnsent::pollVoteRestrictionReasonYetUnsent() {
}

const std::int32_t pollVoteRestrictionReasonYetUnsent::ID;

void pollVoteRestrictionReasonYetUnsent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollVoteRestrictionReasonYetUnsent");
    s.store_class_end();
  }
}

pollVoteRestrictionReasonScheduled::pollVoteRestrictionReasonScheduled() {
}

const std::int32_t pollVoteRestrictionReasonScheduled::ID;

void pollVoteRestrictionReasonScheduled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollVoteRestrictionReasonScheduled");
    s.store_class_end();
  }
}

pollVoteRestrictionReasonCountryRestricted::pollVoteRestrictionReasonCountryRestricted()
  : country_code_()
{}

pollVoteRestrictionReasonCountryRestricted::pollVoteRestrictionReasonCountryRestricted(string const &country_code_)
  : country_code_(country_code_)
{}

const std::int32_t pollVoteRestrictionReasonCountryRestricted::ID;

void pollVoteRestrictionReasonCountryRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollVoteRestrictionReasonCountryRestricted");
    s.store_field("country_code", country_code_);
    s.store_class_end();
  }
}

pollVoteRestrictionReasonMembershipRequired::pollVoteRestrictionReasonMembershipRequired()
  : chat_id_()
{}

pollVoteRestrictionReasonMembershipRequired::pollVoteRestrictionReasonMembershipRequired(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t pollVoteRestrictionReasonMembershipRequired::ID;

void pollVoteRestrictionReasonMembershipRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollVoteRestrictionReasonMembershipRequired");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

pollVoteRestrictionReasonOther::pollVoteRestrictionReasonOther() {
}

const std::int32_t pollVoteRestrictionReasonOther::ID;

void pollVoteRestrictionReasonOther::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollVoteRestrictionReasonOther");
    s.store_class_end();
  }
}

richTextPlain::richTextPlain()
  : text_()
{}

richTextPlain::richTextPlain(string const &text_)
  : text_(text_)
{}

const std::int32_t richTextPlain::ID;

void richTextPlain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextPlain");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

richTextBold::richTextBold()
  : text_()
{}

richTextBold::richTextBold(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextBold::ID;

void richTextBold::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextBold");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextItalic::richTextItalic()
  : text_()
{}

richTextItalic::richTextItalic(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextItalic::ID;

void richTextItalic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextItalic");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextUnderline::richTextUnderline()
  : text_()
{}

richTextUnderline::richTextUnderline(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextUnderline::ID;

void richTextUnderline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextUnderline");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextStrikethrough::richTextStrikethrough()
  : text_()
{}

richTextStrikethrough::richTextStrikethrough(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextStrikethrough::ID;

void richTextStrikethrough::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextStrikethrough");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextSpoiler::richTextSpoiler()
  : text_()
{}

richTextSpoiler::richTextSpoiler(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextSpoiler::ID;

void richTextSpoiler::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextSpoiler");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextSubscript::richTextSubscript()
  : text_()
{}

richTextSubscript::richTextSubscript(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextSubscript::ID;

void richTextSubscript::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextSubscript");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextSuperscript::richTextSuperscript()
  : text_()
{}

richTextSuperscript::richTextSuperscript(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextSuperscript::ID;

void richTextSuperscript::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextSuperscript");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextMarked::richTextMarked()
  : text_()
{}

richTextMarked::richTextMarked(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextMarked::ID;

void richTextMarked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextMarked");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextDateTime::richTextDateTime()
  : text_()
  , unix_time_()
  , formatting_type_()
{}

richTextDateTime::richTextDateTime(object_ptr<RichText> &&text_, int32 unix_time_, object_ptr<DateTimeFormattingType> &&formatting_type_)
  : text_(std::move(text_))
  , unix_time_(unix_time_)
  , formatting_type_(std::move(formatting_type_))
{}

const std::int32_t richTextDateTime::ID;

void richTextDateTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextDateTime");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("unix_time", unix_time_);
    s.store_object_field("formatting_type", static_cast<const BaseObject *>(formatting_type_.get()));
    s.store_class_end();
  }
}

richTextMention::richTextMention()
  : text_()
  , username_()
{}

richTextMention::richTextMention(object_ptr<RichText> &&text_, string const &username_)
  : text_(std::move(text_))
  , username_(username_)
{}

const std::int32_t richTextMention::ID;

void richTextMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextMention");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("username", username_);
    s.store_class_end();
  }
}

richTextHashtag::richTextHashtag()
  : text_()
  , hashtag_()
{}

richTextHashtag::richTextHashtag(object_ptr<RichText> &&text_, string const &hashtag_)
  : text_(std::move(text_))
  , hashtag_(hashtag_)
{}

const std::int32_t richTextHashtag::ID;

void richTextHashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextHashtag");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("hashtag", hashtag_);
    s.store_class_end();
  }
}

richTextCashtag::richTextCashtag()
  : text_()
  , cashtag_()
{}

richTextCashtag::richTextCashtag(object_ptr<RichText> &&text_, string const &cashtag_)
  : text_(std::move(text_))
  , cashtag_(cashtag_)
{}

const std::int32_t richTextCashtag::ID;

void richTextCashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextCashtag");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("cashtag", cashtag_);
    s.store_class_end();
  }
}

richTextBankCardNumber::richTextBankCardNumber()
  : text_()
  , bank_card_number_()
{}

richTextBankCardNumber::richTextBankCardNumber(object_ptr<RichText> &&text_, string const &bank_card_number_)
  : text_(std::move(text_))
  , bank_card_number_(bank_card_number_)
{}

const std::int32_t richTextBankCardNumber::ID;

void richTextBankCardNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextBankCardNumber");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("bank_card_number", bank_card_number_);
    s.store_class_end();
  }
}

richTextTonAddress::richTextTonAddress()
  : text_()
  , address_()
{}

richTextTonAddress::richTextTonAddress(object_ptr<RichText> &&text_, string const &address_)
  : text_(std::move(text_))
  , address_(address_)
{}

const std::int32_t richTextTonAddress::ID;

void richTextTonAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextTonAddress");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("address", address_);
    s.store_class_end();
  }
}

richTextBotCommand::richTextBotCommand()
  : text_()
  , bot_command_()
{}

richTextBotCommand::richTextBotCommand(object_ptr<RichText> &&text_, string const &bot_command_)
  : text_(std::move(text_))
  , bot_command_(bot_command_)
{}

const std::int32_t richTextBotCommand::ID;

void richTextBotCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextBotCommand");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("bot_command", bot_command_);
    s.store_class_end();
  }
}

richTextFixed::richTextFixed()
  : text_()
{}

richTextFixed::richTextFixed(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextFixed::ID;

void richTextFixed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextFixed");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextMentionName::richTextMentionName()
  : text_()
  , user_id_()
{}

richTextMentionName::richTextMentionName(object_ptr<RichText> &&text_, int53 user_id_)
  : text_(std::move(text_))
  , user_id_(user_id_)
{}

const std::int32_t richTextMentionName::ID;

void richTextMentionName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextMentionName");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

richTextUrl::richTextUrl()
  : text_()
  , url_()
  , is_cached_()
{}

richTextUrl::richTextUrl(object_ptr<RichText> &&text_, string const &url_, bool is_cached_)
  : text_(std::move(text_))
  , url_(url_)
  , is_cached_(is_cached_)
{}

const std::int32_t richTextUrl::ID;

void richTextUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextUrl");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("url", url_);
    s.store_field("is_cached", is_cached_);
    s.store_class_end();
  }
}

richTextEmailAddress::richTextEmailAddress()
  : text_()
  , email_address_()
{}

richTextEmailAddress::richTextEmailAddress(object_ptr<RichText> &&text_, string const &email_address_)
  : text_(std::move(text_))
  , email_address_(email_address_)
{}

const std::int32_t richTextEmailAddress::ID;

void richTextEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextEmailAddress");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

richTextPhoneNumber::richTextPhoneNumber()
  : text_()
  , phone_number_()
{}

richTextPhoneNumber::richTextPhoneNumber(object_ptr<RichText> &&text_, string const &phone_number_)
  : text_(std::move(text_))
  , phone_number_(phone_number_)
{}

const std::int32_t richTextPhoneNumber::ID;

void richTextPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextPhoneNumber");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

richTextCustomEmoji::richTextCustomEmoji()
  : custom_emoji_id_()
  , alternative_text_()
{}

richTextCustomEmoji::richTextCustomEmoji(int64 custom_emoji_id_, string const &alternative_text_)
  : custom_emoji_id_(custom_emoji_id_)
  , alternative_text_(alternative_text_)
{}

const std::int32_t richTextCustomEmoji::ID;

void richTextCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_field("alternative_text", alternative_text_);
    s.store_class_end();
  }
}

richTextIcon::richTextIcon()
  : document_()
  , width_()
  , height_()
{}

richTextIcon::richTextIcon(object_ptr<document> &&document_, int32 width_, int32 height_)
  : document_(std::move(document_))
  , width_(width_)
  , height_(height_)
{}

const std::int32_t richTextIcon::ID;

void richTextIcon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextIcon");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

richTextMathematicalExpression::richTextMathematicalExpression()
  : expression_()
{}

richTextMathematicalExpression::richTextMathematicalExpression(string const &expression_)
  : expression_(expression_)
{}

const std::int32_t richTextMathematicalExpression::ID;

void richTextMathematicalExpression::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextMathematicalExpression");
    s.store_field("expression", expression_);
    s.store_class_end();
  }
}

richTextButton::richTextButton()
  : button_()
{}

richTextButton::richTextButton(object_ptr<inlineButton> &&button_)
  : button_(std::move(button_))
{}

const std::int32_t richTextButton::ID;

void richTextButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextButton");
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    s.store_class_end();
  }
}

richTextDiff::richTextDiff()
  : text_()
  , old_text_()
{}

richTextDiff::richTextDiff(object_ptr<RichText> &&text_, object_ptr<RichText> &&old_text_)
  : text_(std::move(text_))
  , old_text_(std::move(old_text_))
{}

const std::int32_t richTextDiff::ID;

void richTextDiff::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextDiff");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("old_text", static_cast<const BaseObject *>(old_text_.get()));
    s.store_class_end();
  }
}

richTextReference::richTextReference()
  : name_()
  , text_()
{}

richTextReference::richTextReference(string const &name_, object_ptr<RichText> &&text_)
  : name_(name_)
  , text_(std::move(text_))
{}

const std::int32_t richTextReference::ID;

void richTextReference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextReference");
    s.store_field("name", name_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextReferenceLink::richTextReferenceLink()
  : text_()
  , reference_name_()
  , url_()
{}

richTextReferenceLink::richTextReferenceLink(object_ptr<RichText> &&text_, string const &reference_name_, string const &url_)
  : text_(std::move(text_))
  , reference_name_(reference_name_)
  , url_(url_)
{}

const std::int32_t richTextReferenceLink::ID;

void richTextReferenceLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextReferenceLink");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("reference_name", reference_name_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

richTextAnchor::richTextAnchor()
  : name_()
{}

richTextAnchor::richTextAnchor(string const &name_)
  : name_(name_)
{}

const std::int32_t richTextAnchor::ID;

void richTextAnchor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextAnchor");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

richTextAnchorLink::richTextAnchorLink()
  : text_()
  , anchor_name_()
  , url_()
{}

richTextAnchorLink::richTextAnchorLink(object_ptr<RichText> &&text_, string const &anchor_name_, string const &url_)
  : text_(std::move(text_))
  , anchor_name_(anchor_name_)
  , url_(url_)
{}

const std::int32_t richTextAnchorLink::ID;

void richTextAnchorLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextAnchorLink");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("anchor_name", anchor_name_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

richTexts::richTexts()
  : texts_()
{}

richTexts::richTexts(array<object_ptr<RichText>> &&texts_)
  : texts_(std::move(texts_))
{}

const std::int32_t richTexts::ID;

void richTexts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTexts");
    { s.store_vector_begin("texts", texts_.size()); for (const auto &_value : texts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

savedMessagesTags::savedMessagesTags()
  : tags_()
{}

savedMessagesTags::savedMessagesTags(array<object_ptr<savedMessagesTag>> &&tags_)
  : tags_(std::move(tags_))
{}

const std::int32_t savedMessagesTags::ID;

void savedMessagesTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTags");
    { s.store_vector_begin("tags", tags_.size()); for (const auto &_value : tags_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

savedMessagesTopic::savedMessagesTopic()
  : id_()
  , type_()
  , is_pinned_()
  , order_()
  , last_message_()
  , draft_message_()
{}

savedMessagesTopic::savedMessagesTopic(int53 id_, object_ptr<SavedMessagesTopicType> &&type_, bool is_pinned_, int64 order_, object_ptr<message> &&last_message_, object_ptr<draftMessage> &&draft_message_)
  : id_(id_)
  , type_(std::move(type_))
  , is_pinned_(is_pinned_)
  , order_(order_)
  , last_message_(std::move(last_message_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t savedMessagesTopic::ID;

void savedMessagesTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTopic");
    s.store_field("id", id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_field("order", order_);
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

searchMessagesFilterEmpty::searchMessagesFilterEmpty() {
}

const std::int32_t searchMessagesFilterEmpty::ID;

void searchMessagesFilterEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterEmpty");
    s.store_class_end();
  }
}

searchMessagesFilterAnimation::searchMessagesFilterAnimation() {
}

const std::int32_t searchMessagesFilterAnimation::ID;

void searchMessagesFilterAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterAnimation");
    s.store_class_end();
  }
}

searchMessagesFilterAudio::searchMessagesFilterAudio() {
}

const std::int32_t searchMessagesFilterAudio::ID;

void searchMessagesFilterAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterAudio");
    s.store_class_end();
  }
}

searchMessagesFilterDocument::searchMessagesFilterDocument() {
}

const std::int32_t searchMessagesFilterDocument::ID;

void searchMessagesFilterDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterDocument");
    s.store_class_end();
  }
}

searchMessagesFilterPhoto::searchMessagesFilterPhoto() {
}

const std::int32_t searchMessagesFilterPhoto::ID;

void searchMessagesFilterPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterPhoto");
    s.store_class_end();
  }
}

searchMessagesFilterPoll::searchMessagesFilterPoll() {
}

const std::int32_t searchMessagesFilterPoll::ID;

void searchMessagesFilterPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterPoll");
    s.store_class_end();
  }
}

searchMessagesFilterVideo::searchMessagesFilterVideo() {
}

const std::int32_t searchMessagesFilterVideo::ID;

void searchMessagesFilterVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVideo");
    s.store_class_end();
  }
}

searchMessagesFilterVoiceNote::searchMessagesFilterVoiceNote() {
}

const std::int32_t searchMessagesFilterVoiceNote::ID;

void searchMessagesFilterVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVoiceNote");
    s.store_class_end();
  }
}

searchMessagesFilterPhotoAndVideo::searchMessagesFilterPhotoAndVideo() {
}

const std::int32_t searchMessagesFilterPhotoAndVideo::ID;

void searchMessagesFilterPhotoAndVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterPhotoAndVideo");
    s.store_class_end();
  }
}

searchMessagesFilterUrl::searchMessagesFilterUrl() {
}

const std::int32_t searchMessagesFilterUrl::ID;

void searchMessagesFilterUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterUrl");
    s.store_class_end();
  }
}

searchMessagesFilterChatPhoto::searchMessagesFilterChatPhoto() {
}

const std::int32_t searchMessagesFilterChatPhoto::ID;

void searchMessagesFilterChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterChatPhoto");
    s.store_class_end();
  }
}

searchMessagesFilterVideoNote::searchMessagesFilterVideoNote() {
}

const std::int32_t searchMessagesFilterVideoNote::ID;

void searchMessagesFilterVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVideoNote");
    s.store_class_end();
  }
}

searchMessagesFilterVoiceAndVideoNote::searchMessagesFilterVoiceAndVideoNote() {
}

const std::int32_t searchMessagesFilterVoiceAndVideoNote::ID;

void searchMessagesFilterVoiceAndVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVoiceAndVideoNote");
    s.store_class_end();
  }
}

searchMessagesFilterMention::searchMessagesFilterMention() {
}

const std::int32_t searchMessagesFilterMention::ID;

void searchMessagesFilterMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterMention");
    s.store_class_end();
  }
}

searchMessagesFilterUnreadMention::searchMessagesFilterUnreadMention() {
}

const std::int32_t searchMessagesFilterUnreadMention::ID;

void searchMessagesFilterUnreadMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterUnreadMention");
    s.store_class_end();
  }
}

searchMessagesFilterUnreadReaction::searchMessagesFilterUnreadReaction() {
}

const std::int32_t searchMessagesFilterUnreadReaction::ID;

void searchMessagesFilterUnreadReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterUnreadReaction");
    s.store_class_end();
  }
}

searchMessagesFilterUnreadPollVote::searchMessagesFilterUnreadPollVote() {
}

const std::int32_t searchMessagesFilterUnreadPollVote::ID;

void searchMessagesFilterUnreadPollVote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterUnreadPollVote");
    s.store_class_end();
  }
}

searchMessagesFilterFailedToSend::searchMessagesFilterFailedToSend() {
}

const std::int32_t searchMessagesFilterFailedToSend::ID;

void searchMessagesFilterFailedToSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterFailedToSend");
    s.store_class_end();
  }
}

searchMessagesFilterPinned::searchMessagesFilterPinned() {
}

const std::int32_t searchMessagesFilterPinned::ID;

void searchMessagesFilterPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterPinned");
    s.store_class_end();
  }
}

session::session()
  : id_()
  , is_current_()
  , is_password_pending_()
  , is_unconfirmed_()
  , can_accept_secret_chats_()
  , can_accept_calls_()
  , device_type_()
  , api_id_()
  , application_name_()
  , application_version_()
  , is_official_application_()
  , device_model_()
  , platform_()
  , system_version_()
  , log_in_date_()
  , last_active_date_()
  , ip_address_()
  , location_()
{}

session::session(int64 id_, bool is_current_, bool is_password_pending_, bool is_unconfirmed_, bool can_accept_secret_chats_, bool can_accept_calls_, object_ptr<SessionDeviceType> &&device_type_, int32 api_id_, string const &application_name_, string const &application_version_, bool is_official_application_, string const &device_model_, string const &platform_, string const &system_version_, int32 log_in_date_, int32 last_active_date_, string const &ip_address_, string const &location_)
  : id_(id_)
  , is_current_(is_current_)
  , is_password_pending_(is_password_pending_)
  , is_unconfirmed_(is_unconfirmed_)
  , can_accept_secret_chats_(can_accept_secret_chats_)
  , can_accept_calls_(can_accept_calls_)
  , device_type_(std::move(device_type_))
  , api_id_(api_id_)
  , application_name_(application_name_)
  , application_version_(application_version_)
  , is_official_application_(is_official_application_)
  , device_model_(device_model_)
  , platform_(platform_)
  , system_version_(system_version_)
  , log_in_date_(log_in_date_)
  , last_active_date_(last_active_date_)
  , ip_address_(ip_address_)
  , location_(location_)
{}

const std::int32_t session::ID;

void session::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "session");
    s.store_field("id", id_);
    s.store_field("is_current", is_current_);
    s.store_field("is_password_pending", is_password_pending_);
    s.store_field("is_unconfirmed", is_unconfirmed_);
    s.store_field("can_accept_secret_chats", can_accept_secret_chats_);
    s.store_field("can_accept_calls", can_accept_calls_);
    s.store_object_field("device_type", static_cast<const BaseObject *>(device_type_.get()));
    s.store_field("api_id", api_id_);
    s.store_field("application_name", application_name_);
    s.store_field("application_version", application_version_);
    s.store_field("is_official_application", is_official_application_);
    s.store_field("device_model", device_model_);
    s.store_field("platform", platform_);
    s.store_field("system_version", system_version_);
    s.store_field("log_in_date", log_in_date_);
    s.store_field("last_active_date", last_active_date_);
    s.store_field("ip_address", ip_address_);
    s.store_field("location", location_);
    s.store_class_end();
  }
}

speechRecognitionResultPending::speechRecognitionResultPending()
  : partial_text_()
{}

speechRecognitionResultPending::speechRecognitionResultPending(string const &partial_text_)
  : partial_text_(partial_text_)
{}

const std::int32_t speechRecognitionResultPending::ID;

void speechRecognitionResultPending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "speechRecognitionResultPending");
    s.store_field("partial_text", partial_text_);
    s.store_class_end();
  }
}

speechRecognitionResultText::speechRecognitionResultText()
  : text_()
{}

speechRecognitionResultText::speechRecognitionResultText(string const &text_)
  : text_(text_)
{}

const std::int32_t speechRecognitionResultText::ID;

void speechRecognitionResultText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "speechRecognitionResultText");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

speechRecognitionResultError::speechRecognitionResultError()
  : error_()
{}

speechRecognitionResultError::speechRecognitionResultError(object_ptr<error> &&error_)
  : error_(std::move(error_))
{}

const std::int32_t speechRecognitionResultError::ID;

void speechRecognitionResultError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "speechRecognitionResultError");
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

starRevenueStatistics::starRevenueStatistics()
  : revenue_by_day_graph_()
  , status_()
  , usd_rate_()
{}

starRevenueStatistics::starRevenueStatistics(object_ptr<StatisticalGraph> &&revenue_by_day_graph_, object_ptr<starRevenueStatus> &&status_, double usd_rate_)
  : revenue_by_day_graph_(std::move(revenue_by_day_graph_))
  , status_(std::move(status_))
  , usd_rate_(usd_rate_)
{}

const std::int32_t starRevenueStatistics::ID;

void starRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starRevenueStatistics");
    s.store_object_field("revenue_by_day_graph", static_cast<const BaseObject *>(revenue_by_day_graph_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("usd_rate", usd_rate_);
    s.store_class_end();
  }
}

starSubscriptionPricing::starSubscriptionPricing()
  : period_()
  , star_count_()
{}

starSubscriptionPricing::starSubscriptionPricing(int32 period_, int53 star_count_)
  : period_(period_)
  , star_count_(star_count_)
{}

const std::int32_t starSubscriptionPricing::ID;

void starSubscriptionPricing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starSubscriptionPricing");
    s.store_field("period", period_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

statisticalGraphData::statisticalGraphData()
  : json_data_()
  , zoom_token_()
{}

statisticalGraphData::statisticalGraphData(string const &json_data_, string const &zoom_token_)
  : json_data_(json_data_)
  , zoom_token_(zoom_token_)
{}

const std::int32_t statisticalGraphData::ID;

void statisticalGraphData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalGraphData");
    s.store_field("json_data", json_data_);
    s.store_field("zoom_token", "[REDACTED]");
    s.store_class_end();
  }
}

statisticalGraphAsync::statisticalGraphAsync()
  : token_()
{}

statisticalGraphAsync::statisticalGraphAsync(string const &token_)
  : token_(token_)
{}

const std::int32_t statisticalGraphAsync::ID;

void statisticalGraphAsync::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalGraphAsync");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

statisticalGraphError::statisticalGraphError()
  : error_message_()
{}

statisticalGraphError::statisticalGraphError(string const &error_message_)
  : error_message_(error_message_)
{}

const std::int32_t statisticalGraphError::ID;

void statisticalGraphError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalGraphError");
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

stickerFullTypeRegular::stickerFullTypeRegular()
  : premium_animation_()
{}

stickerFullTypeRegular::stickerFullTypeRegular(object_ptr<file> &&premium_animation_)
  : premium_animation_(std::move(premium_animation_))
{}

const std::int32_t stickerFullTypeRegular::ID;

void stickerFullTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFullTypeRegular");
    s.store_object_field("premium_animation", static_cast<const BaseObject *>(premium_animation_.get()));
    s.store_class_end();
  }
}

stickerFullTypeMask::stickerFullTypeMask()
  : mask_position_()
{}

stickerFullTypeMask::stickerFullTypeMask(object_ptr<maskPosition> &&mask_position_)
  : mask_position_(std::move(mask_position_))
{}

const std::int32_t stickerFullTypeMask::ID;

void stickerFullTypeMask::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFullTypeMask");
    s.store_object_field("mask_position", static_cast<const BaseObject *>(mask_position_.get()));
    s.store_class_end();
  }
}

stickerFullTypeCustomEmoji::stickerFullTypeCustomEmoji()
  : custom_emoji_id_()
  , needs_repainting_()
{}

stickerFullTypeCustomEmoji::stickerFullTypeCustomEmoji(int64 custom_emoji_id_, bool needs_repainting_)
  : custom_emoji_id_(custom_emoji_id_)
  , needs_repainting_(needs_repainting_)
{}

const std::int32_t stickerFullTypeCustomEmoji::ID;

void stickerFullTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFullTypeCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_field("needs_repainting", needs_repainting_);
    s.store_class_end();
  }
}

storageStatistics::storageStatistics()
  : size_()
  , count_()
  , by_chat_()
{}

storageStatistics::storageStatistics(int53 size_, int32 count_, array<object_ptr<storageStatisticsByChat>> &&by_chat_)
  : size_(size_)
  , count_(count_)
  , by_chat_(std::move(by_chat_))
{}

const std::int32_t storageStatistics::ID;

void storageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatistics");
    s.store_field("size", size_);
    s.store_field("count", count_);
    { s.store_vector_begin("by_chat", by_chat_.size()); for (const auto &_value : by_chat_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories::stories()
  : total_count_()
  , stories_()
  , pinned_story_ids_()
{}

stories::stories(int32 total_count_, array<object_ptr<story>> &&stories_, array<int32> &&pinned_story_ids_)
  : total_count_(total_count_)
  , stories_(std::move(stories_))
  , pinned_story_ids_(std::move(pinned_story_ids_))
{}

const std::int32_t stories::ID;

void stories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("pinned_story_ids", pinned_story_ids_.size()); for (const auto &_value : pinned_story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

supergroupFullInfo::supergroupFullInfo()
  : photo_()
  , community_id_()
  , description_()
  , member_count_()
  , administrator_count_()
  , restricted_count_()
  , banned_count_()
  , linked_chat_id_()
  , direct_messages_chat_id_()
  , slow_mode_delay_()
  , slow_mode_delay_expires_in_()
  , can_enable_paid_messages_()
  , can_enable_paid_reaction_()
  , can_get_members_()
  , has_hidden_members_()
  , can_hide_members_()
  , can_set_sticker_set_()
  , can_set_location_()
  , can_get_statistics_()
  , can_get_revenue_statistics_()
  , can_get_star_revenue_statistics_()
  , can_send_gift_()
  , can_toggle_aggressive_anti_spam_()
  , is_all_history_available_()
  , can_have_sponsored_messages_()
  , has_aggressive_anti_spam_enabled_()
  , has_paid_media_allowed_()
  , has_pinned_stories_()
  , gift_count_()
  , my_boost_count_()
  , unrestrict_boost_count_()
  , outgoing_paid_message_star_count_()
  , sticker_set_id_()
  , custom_emoji_sticker_set_id_()
  , location_()
  , invite_link_()
  , guard_bot_user_id_()
  , bot_commands_()
  , bot_verification_()
  , main_profile_tab_()
  , share_theme_()
  , upgraded_from_basic_group_id_()
  , upgraded_from_max_message_id_()
{}

supergroupFullInfo::supergroupFullInfo(object_ptr<chatPhoto> &&photo_, int53 community_id_, string const &description_, int32 member_count_, int32 administrator_count_, int32 restricted_count_, int32 banned_count_, int53 linked_chat_id_, int53 direct_messages_chat_id_, int32 slow_mode_delay_, double slow_mode_delay_expires_in_, bool can_enable_paid_messages_, bool can_enable_paid_reaction_, bool can_get_members_, bool has_hidden_members_, bool can_hide_members_, bool can_set_sticker_set_, bool can_set_location_, bool can_get_statistics_, bool can_get_revenue_statistics_, bool can_get_star_revenue_statistics_, bool can_send_gift_, bool can_toggle_aggressive_anti_spam_, bool is_all_history_available_, bool can_have_sponsored_messages_, bool has_aggressive_anti_spam_enabled_, bool has_paid_media_allowed_, bool has_pinned_stories_, int32 gift_count_, int32 my_boost_count_, int32 unrestrict_boost_count_, int53 outgoing_paid_message_star_count_, int64 sticker_set_id_, int64 custom_emoji_sticker_set_id_, object_ptr<chatLocation> &&location_, object_ptr<chatInviteLink> &&invite_link_, int53 guard_bot_user_id_, array<object_ptr<botCommands>> &&bot_commands_, object_ptr<botVerification> &&bot_verification_, object_ptr<ProfileTab> &&main_profile_tab_, object_ptr<ProfileShareTheme> &&share_theme_, int53 upgraded_from_basic_group_id_, int53 upgraded_from_max_message_id_)
  : photo_(std::move(photo_))
  , community_id_(community_id_)
  , description_(description_)
  , member_count_(member_count_)
  , administrator_count_(administrator_count_)
  , restricted_count_(restricted_count_)
  , banned_count_(banned_count_)
  , linked_chat_id_(linked_chat_id_)
  , direct_messages_chat_id_(direct_messages_chat_id_)
  , slow_mode_delay_(slow_mode_delay_)
  , slow_mode_delay_expires_in_(slow_mode_delay_expires_in_)
  , can_enable_paid_messages_(can_enable_paid_messages_)
  , can_enable_paid_reaction_(can_enable_paid_reaction_)
  , can_get_members_(can_get_members_)
  , has_hidden_members_(has_hidden_members_)
  , can_hide_members_(can_hide_members_)
  , can_set_sticker_set_(can_set_sticker_set_)
  , can_set_location_(can_set_location_)
  , can_get_statistics_(can_get_statistics_)
  , can_get_revenue_statistics_(can_get_revenue_statistics_)
  , can_get_star_revenue_statistics_(can_get_star_revenue_statistics_)
  , can_send_gift_(can_send_gift_)
  , can_toggle_aggressive_anti_spam_(can_toggle_aggressive_anti_spam_)
  , is_all_history_available_(is_all_history_available_)
  , can_have_sponsored_messages_(can_have_sponsored_messages_)
  , has_aggressive_anti_spam_enabled_(has_aggressive_anti_spam_enabled_)
  , has_paid_media_allowed_(has_paid_media_allowed_)
  , has_pinned_stories_(has_pinned_stories_)
  , gift_count_(gift_count_)
  , my_boost_count_(my_boost_count_)
  , unrestrict_boost_count_(unrestrict_boost_count_)
  , outgoing_paid_message_star_count_(outgoing_paid_message_star_count_)
  , sticker_set_id_(sticker_set_id_)
  , custom_emoji_sticker_set_id_(custom_emoji_sticker_set_id_)
  , location_(std::move(location_))
  , invite_link_(std::move(invite_link_))
  , guard_bot_user_id_(guard_bot_user_id_)
  , bot_commands_(std::move(bot_commands_))
  , bot_verification_(std::move(bot_verification_))
  , main_profile_tab_(std::move(main_profile_tab_))
  , share_theme_(std::move(share_theme_))
  , upgraded_from_basic_group_id_(upgraded_from_basic_group_id_)
  , upgraded_from_max_message_id_(upgraded_from_max_message_id_)
{}

const std::int32_t supergroupFullInfo::ID;

void supergroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupFullInfo");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("community_id", community_id_);
    s.store_field("description", description_);
    s.store_field("member_count", member_count_);
    s.store_field("administrator_count", administrator_count_);
    s.store_field("restricted_count", restricted_count_);
    s.store_field("banned_count", banned_count_);
    s.store_field("linked_chat_id", linked_chat_id_);
    s.store_field("direct_messages_chat_id", direct_messages_chat_id_);
    s.store_field("slow_mode_delay", slow_mode_delay_);
    s.store_field("slow_mode_delay_expires_in", slow_mode_delay_expires_in_);
    s.store_field("can_enable_paid_messages", can_enable_paid_messages_);
    s.store_field("can_enable_paid_reaction", can_enable_paid_reaction_);
    s.store_field("can_get_members", can_get_members_);
    s.store_field("has_hidden_members", has_hidden_members_);
    s.store_field("can_hide_members", can_hide_members_);
    s.store_field("can_set_sticker_set", can_set_sticker_set_);
    s.store_field("can_set_location", can_set_location_);
    s.store_field("can_get_statistics", can_get_statistics_);
    s.store_field("can_get_revenue_statistics", can_get_revenue_statistics_);
    s.store_field("can_get_star_revenue_statistics", can_get_star_revenue_statistics_);
    s.store_field("can_send_gift", can_send_gift_);
    s.store_field("can_toggle_aggressive_anti_spam", can_toggle_aggressive_anti_spam_);
    s.store_field("is_all_history_available", is_all_history_available_);
    s.store_field("can_have_sponsored_messages", can_have_sponsored_messages_);
    s.store_field("has_aggressive_anti_spam_enabled", has_aggressive_anti_spam_enabled_);
    s.store_field("has_paid_media_allowed", has_paid_media_allowed_);
    s.store_field("has_pinned_stories", has_pinned_stories_);
    s.store_field("gift_count", gift_count_);
    s.store_field("my_boost_count", my_boost_count_);
    s.store_field("unrestrict_boost_count", unrestrict_boost_count_);
    s.store_field("outgoing_paid_message_star_count", outgoing_paid_message_star_count_);
    s.store_field("sticker_set_id", sticker_set_id_);
    s.store_field("custom_emoji_sticker_set_id", custom_emoji_sticker_set_id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_field("guard_bot_user_id", guard_bot_user_id_);
    { s.store_vector_begin("bot_commands", bot_commands_.size()); for (const auto &_value : bot_commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("bot_verification", static_cast<const BaseObject *>(bot_verification_.get()));
    s.store_object_field("main_profile_tab", static_cast<const BaseObject *>(main_profile_tab_.get()));
    s.store_object_field("share_theme", static_cast<const BaseObject *>(share_theme_.get()));
    s.store_field("upgraded_from_basic_group_id", upgraded_from_basic_group_id_);
    s.store_field("upgraded_from_max_message_id", upgraded_from_max_message_id_);
    s.store_class_end();
  }
}

tMeUrl::tMeUrl()
  : url_()
  , type_()
{}

tMeUrl::tMeUrl(string const &url_, object_ptr<TMeUrlType> &&type_)
  : url_(url_)
  , type_(std::move(type_))
{}

const std::int32_t tMeUrl::ID;

void tMeUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrl");
    s.store_field("url", url_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

testBytes::testBytes()
  : value_()
{}

testBytes::testBytes(bytes const &value_)
  : value_(std::move(value_))
{}

const std::int32_t testBytes::ID;

void testBytes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testBytes");
    s.store_bytes_field("value", value_);
    s.store_class_end();
  }
}

testVectorIntObject::testVectorIntObject()
  : value_()
{}

testVectorIntObject::testVectorIntObject(array<object_ptr<testInt>> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorIntObject::ID;

void testVectorIntObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorIntObject");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

text::text()
  : text_()
{}

text::text(string const &text_)
  : text_(text_)
{}

const std::int32_t text::ID;

void text::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "text");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

textCompositionStyle::textCompositionStyle()
  : name_()
  , custom_emoji_id_()
  , title_()
  , is_custom_()
  , is_creator_()
  , install_count_()
  , prompt_()
  , creator_user_id_()
  , english_example_()
{}

textCompositionStyle::textCompositionStyle(string const &name_, int64 custom_emoji_id_, string const &title_, bool is_custom_, bool is_creator_, int32 install_count_, string const &prompt_, int53 creator_user_id_, object_ptr<textCompositionStyleExample> &&english_example_)
  : name_(name_)
  , custom_emoji_id_(custom_emoji_id_)
  , title_(title_)
  , is_custom_(is_custom_)
  , is_creator_(is_creator_)
  , install_count_(install_count_)
  , prompt_(prompt_)
  , creator_user_id_(creator_user_id_)
  , english_example_(std::move(english_example_))
{}

const std::int32_t textCompositionStyle::ID;

void textCompositionStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textCompositionStyle");
    s.store_field("name", name_);
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_field("title", title_);
    s.store_field("is_custom", is_custom_);
    s.store_field("is_creator", is_creator_);
    s.store_field("install_count", install_count_);
    s.store_field("prompt", prompt_);
    s.store_field("creator_user_id", creator_user_id_);
    s.store_object_field("english_example", static_cast<const BaseObject *>(english_example_.get()));
    s.store_class_end();
  }
}

tonConnectChallenge::tonConnectChallenge()
  : challenge_()
  , event_id_()
{}

tonConnectChallenge::tonConnectChallenge(bytes const &challenge_, int64 event_id_)
  : challenge_(std::move(challenge_))
  , event_id_(event_id_)
{}

const std::int32_t tonConnectChallenge::ID;

void tonConnectChallenge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectChallenge");
    s.store_bytes_field("challenge", challenge_);
    s.store_field("event_id", event_id_);
    s.store_class_end();
  }
}

tonConnectConnectRequest::tonConnectConnectRequest()
  : manifest_url_()
  , items_()
{}

tonConnectConnectRequest::tonConnectConnectRequest(string const &manifest_url_, array<object_ptr<TonConnectConnectItem>> &&items_)
  : manifest_url_(manifest_url_)
  , items_(std::move(items_))
{}

const std::int32_t tonConnectConnectRequest::ID;

void tonConnectConnectRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectConnectRequest");
    s.store_field("manifest_url", manifest_url_);
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

tonWalletState::tonWalletState()
  : address_()
  , public_key_()
  , gram_amount_()
  , is_being_created_()
  , is_backup_enabled_()
  , can_enable_backup_()
  , can_export_phrase_()
{}

tonWalletState::tonWalletState(string const &address_, bytes const &public_key_, int64 gram_amount_, bool is_being_created_, bool is_backup_enabled_, bool can_enable_backup_, bool can_export_phrase_)
  : address_(address_)
  , public_key_(std::move(public_key_))
  , gram_amount_(gram_amount_)
  , is_being_created_(is_being_created_)
  , is_backup_enabled_(is_backup_enabled_)
  , can_enable_backup_(can_enable_backup_)
  , can_export_phrase_(can_export_phrase_)
{}

const std::int32_t tonWalletState::ID;

void tonWalletState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletState");
    s.store_field("address", address_);
    s.store_bytes_field("public_key", public_key_);
    s.store_field("gram_amount", gram_amount_);
    s.store_field("is_being_created", is_being_created_);
    s.store_field("is_backup_enabled", is_backup_enabled_);
    s.store_field("can_enable_backup", can_enable_backup_);
    s.store_field("can_export_phrase", can_export_phrase_);
    s.store_class_end();
  }
}

tonWalletTransferReceiverUser::tonWalletTransferReceiverUser()
  : username_()
{}

tonWalletTransferReceiverUser::tonWalletTransferReceiverUser(string const &username_)
  : username_(username_)
{}

const std::int32_t tonWalletTransferReceiverUser::ID;

void tonWalletTransferReceiverUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransferReceiverUser");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

tonWalletTransferReceiverAddress::tonWalletTransferReceiverAddress()
  : address_()
{}

tonWalletTransferReceiverAddress::tonWalletTransferReceiverAddress(string const &address_)
  : address_(address_)
{}

const std::int32_t tonWalletTransferReceiverAddress::ID;

void tonWalletTransferReceiverAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransferReceiverAddress");
    s.store_field("address", address_);
    s.store_class_end();
  }
}

upgradedGiftBackdrop::upgradedGiftBackdrop()
  : id_()
  , name_()
  , colors_()
  , rarity_()
{}

upgradedGiftBackdrop::upgradedGiftBackdrop(int32 id_, string const &name_, object_ptr<upgradedGiftBackdropColors> &&colors_, object_ptr<UpgradedGiftAttributeRarity> &&rarity_)
  : id_(id_)
  , name_(name_)
  , colors_(std::move(colors_))
  , rarity_(std::move(rarity_))
{}

const std::int32_t upgradedGiftBackdrop::ID;

void upgradedGiftBackdrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftBackdrop");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_object_field("colors", static_cast<const BaseObject *>(colors_.get()));
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_class_end();
  }
}

upgradedGiftBackdropColors::upgradedGiftBackdropColors()
  : center_color_()
  , edge_color_()
  , symbol_color_()
  , text_color_()
{}

upgradedGiftBackdropColors::upgradedGiftBackdropColors(int32 center_color_, int32 edge_color_, int32 symbol_color_, int32 text_color_)
  : center_color_(center_color_)
  , edge_color_(edge_color_)
  , symbol_color_(symbol_color_)
  , text_color_(text_color_)
{}

const std::int32_t upgradedGiftBackdropColors::ID;

void upgradedGiftBackdropColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftBackdropColors");
    s.store_field("center_color", center_color_);
    s.store_field("edge_color", edge_color_);
    s.store_field("symbol_color", symbol_color_);
    s.store_field("text_color", text_color_);
    s.store_class_end();
  }
}

upgradedGiftSymbol::upgradedGiftSymbol()
  : name_()
  , sticker_()
  , rarity_()
{}

upgradedGiftSymbol::upgradedGiftSymbol(string const &name_, object_ptr<sticker> &&sticker_, object_ptr<UpgradedGiftAttributeRarity> &&rarity_)
  : name_(name_)
  , sticker_(std::move(sticker_))
  , rarity_(std::move(rarity_))
{}

const std::int32_t upgradedGiftSymbol::ID;

void upgradedGiftSymbol::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftSymbol");
    s.store_field("name", name_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_class_end();
  }
}

userLink::userLink()
  : url_()
  , expires_in_()
  , can_get_permanent_link_()
{}

userLink::userLink(string const &url_, int32 expires_in_, bool can_get_permanent_link_)
  : url_(url_)
  , expires_in_(expires_in_)
  , can_get_permanent_link_(can_get_permanent_link_)
{}

const std::int32_t userLink::ID;

void userLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userLink");
    s.store_field("url", url_);
    s.store_field("expires_in", expires_in_);
    s.store_field("can_get_permanent_link", can_get_permanent_link_);
    s.store_class_end();
  }
}

userPrivacySettingShowStatus::userPrivacySettingShowStatus() {
}

const std::int32_t userPrivacySettingShowStatus::ID;

void userPrivacySettingShowStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowStatus");
    s.store_class_end();
  }
}

userPrivacySettingShowProfilePhoto::userPrivacySettingShowProfilePhoto() {
}

const std::int32_t userPrivacySettingShowProfilePhoto::ID;

void userPrivacySettingShowProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowProfilePhoto");
    s.store_class_end();
  }
}

userPrivacySettingShowLinkInForwardedMessages::userPrivacySettingShowLinkInForwardedMessages() {
}

const std::int32_t userPrivacySettingShowLinkInForwardedMessages::ID;

void userPrivacySettingShowLinkInForwardedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowLinkInForwardedMessages");
    s.store_class_end();
  }
}

userPrivacySettingShowPhoneNumber::userPrivacySettingShowPhoneNumber() {
}

const std::int32_t userPrivacySettingShowPhoneNumber::ID;

void userPrivacySettingShowPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowPhoneNumber");
    s.store_class_end();
  }
}

userPrivacySettingShowBio::userPrivacySettingShowBio() {
}

const std::int32_t userPrivacySettingShowBio::ID;

void userPrivacySettingShowBio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowBio");
    s.store_class_end();
  }
}

userPrivacySettingShowBirthdate::userPrivacySettingShowBirthdate() {
}

const std::int32_t userPrivacySettingShowBirthdate::ID;

void userPrivacySettingShowBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowBirthdate");
    s.store_class_end();
  }
}

userPrivacySettingShowProfileAudio::userPrivacySettingShowProfileAudio() {
}

const std::int32_t userPrivacySettingShowProfileAudio::ID;

void userPrivacySettingShowProfileAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowProfileAudio");
    s.store_class_end();
  }
}

userPrivacySettingAllowChatInvites::userPrivacySettingAllowChatInvites() {
}

const std::int32_t userPrivacySettingAllowChatInvites::ID;

void userPrivacySettingAllowChatInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowChatInvites");
    s.store_class_end();
  }
}

userPrivacySettingAllowCalls::userPrivacySettingAllowCalls() {
}

const std::int32_t userPrivacySettingAllowCalls::ID;

void userPrivacySettingAllowCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowCalls");
    s.store_class_end();
  }
}

userPrivacySettingAllowPeerToPeerCalls::userPrivacySettingAllowPeerToPeerCalls() {
}

const std::int32_t userPrivacySettingAllowPeerToPeerCalls::ID;

void userPrivacySettingAllowPeerToPeerCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowPeerToPeerCalls");
    s.store_class_end();
  }
}

userPrivacySettingAllowFindingByPhoneNumber::userPrivacySettingAllowFindingByPhoneNumber() {
}

const std::int32_t userPrivacySettingAllowFindingByPhoneNumber::ID;

void userPrivacySettingAllowFindingByPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowFindingByPhoneNumber");
    s.store_class_end();
  }
}

userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages::userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages() {
}

const std::int32_t userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages::ID;

void userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages");
    s.store_class_end();
  }
}

userPrivacySettingAutosaveGifts::userPrivacySettingAutosaveGifts() {
}

const std::int32_t userPrivacySettingAutosaveGifts::ID;

void userPrivacySettingAutosaveGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAutosaveGifts");
    s.store_class_end();
  }
}

userPrivacySettingAllowUnpaidMessages::userPrivacySettingAllowUnpaidMessages() {
}

const std::int32_t userPrivacySettingAllowUnpaidMessages::ID;

void userPrivacySettingAllowUnpaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowUnpaidMessages");
    s.store_class_end();
  }
}

videoChat::videoChat()
  : group_call_id_()
  , has_participants_()
  , default_participant_id_()
{}

videoChat::videoChat(int32 group_call_id_, bool has_participants_, object_ptr<MessageSender> &&default_participant_id_)
  : group_call_id_(group_call_id_)
  , has_participants_(has_participants_)
  , default_participant_id_(std::move(default_participant_id_))
{}

const std::int32_t videoChat::ID;

void videoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoChat");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("has_participants", has_participants_);
    s.store_object_field("default_participant_id", static_cast<const BaseObject *>(default_participant_id_.get()));
    s.store_class_end();
  }
}

webAppInfo::webAppInfo()
  : launch_id_()
  , url_()
{}

webAppInfo::webAppInfo(int64 launch_id_, object_ptr<webAppUrl> &&url_)
  : launch_id_(launch_id_)
  , url_(std::move(url_))
{}

const std::int32_t webAppInfo::ID;

void webAppInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppInfo");
    s.store_field("launch_id", launch_id_);
    s.store_object_field("url", static_cast<const BaseObject *>(url_.get()));
    s.store_class_end();
  }
}

webAppOpenParameters::webAppOpenParameters()
  : theme_()
  , application_name_()
  , mode_()
{}

webAppOpenParameters::webAppOpenParameters(object_ptr<themeParameters> &&theme_, string const &application_name_, object_ptr<WebAppOpenMode> &&mode_)
  : theme_(std::move(theme_))
  , application_name_(application_name_)
  , mode_(std::move(mode_))
{}

const std::int32_t webAppOpenParameters::ID;

void webAppOpenParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppOpenParameters");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_field("application_name", application_name_);
    s.store_object_field("mode", static_cast<const BaseObject *>(mode_.get()));
    s.store_class_end();
  }
}

acceptOauthRequest::acceptOauthRequest()
  : url_()
  , match_code_()
  , allow_write_access_()
  , allow_phone_number_access_()
  , ton_connect_connect_data_()
{}

acceptOauthRequest::acceptOauthRequest(string const &url_, string const &match_code_, bool allow_write_access_, bool allow_phone_number_access_, object_ptr<tonConnectConnectData> &&ton_connect_connect_data_)
  : url_(url_)
  , match_code_(match_code_)
  , allow_write_access_(allow_write_access_)
  , allow_phone_number_access_(allow_phone_number_access_)
  , ton_connect_connect_data_(std::move(ton_connect_connect_data_))
{}

const std::int32_t acceptOauthRequest::ID;

void acceptOauthRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "acceptOauthRequest");
    s.store_field("url", url_);
    s.store_field("match_code", match_code_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_field("allow_phone_number_access", allow_phone_number_access_);
    s.store_object_field("ton_connect_connect_data", static_cast<const BaseObject *>(ton_connect_connect_data_.get()));
    s.store_class_end();
  }
}

addProfileAudio::addProfileAudio()
  : audio_()
{}

addProfileAudio::addProfileAudio(object_ptr<inputAudio> &&audio_)
  : audio_(std::move(audio_))
{}

const std::int32_t addProfileAudio::ID;

void addProfileAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addProfileAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_class_end();
  }
}

banGroupCallParticipants::banGroupCallParticipants()
  : group_call_id_()
  , user_ids_()
{}

banGroupCallParticipants::banGroupCallParticipants(int32 group_call_id_, array<int64> &&user_ids_)
  : group_call_id_(group_call_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t banGroupCallParticipants::ID;

void banGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "banGroupCallParticipants");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

checkAuthenticationCode::checkAuthenticationCode()
  : code_()
{}

checkAuthenticationCode::checkAuthenticationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkAuthenticationCode::ID;

void checkAuthenticationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

checkAuthenticationEmailCode::checkAuthenticationEmailCode()
  : code_()
{}

checkAuthenticationEmailCode::checkAuthenticationEmailCode(object_ptr<EmailAddressAuthentication> &&code_)
  : code_(std::move(code_))
{}

const std::int32_t checkAuthenticationEmailCode::ID;

void checkAuthenticationEmailCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationEmailCode");
    s.store_object_field("code", static_cast<const BaseObject *>(code_.get()));
    s.store_class_end();
  }
}

checkChatFolderInviteLink::checkChatFolderInviteLink()
  : invite_link_()
{}

checkChatFolderInviteLink::checkChatFolderInviteLink(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t checkChatFolderInviteLink::ID;

void checkChatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatFolderInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

checkPremiumGiftCode::checkPremiumGiftCode()
  : code_()
{}

checkPremiumGiftCode::checkPremiumGiftCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkPremiumGiftCode::ID;

void checkPremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkPremiumGiftCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

cleanFileName::cleanFileName()
  : file_name_()
{}

cleanFileName::cleanFileName(string const &file_name_)
  : file_name_(file_name_)
{}

const std::int32_t cleanFileName::ID;

void cleanFileName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cleanFileName");
    s.store_field("file_name", file_name_);
    s.store_class_end();
  }
}

clickVideoMessageAdvertisement::clickVideoMessageAdvertisement()
  : advertisement_unique_id_()
{}

clickVideoMessageAdvertisement::clickVideoMessageAdvertisement(int53 advertisement_unique_id_)
  : advertisement_unique_id_(advertisement_unique_id_)
{}

const std::int32_t clickVideoMessageAdvertisement::ID;

void clickVideoMessageAdvertisement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clickVideoMessageAdvertisement");
    s.store_field("advertisement_unique_id", advertisement_unique_id_);
    s.store_class_end();
  }
}

confirmQrCodeAuthentication::confirmQrCodeAuthentication()
  : link_()
{}

confirmQrCodeAuthentication::confirmQrCodeAuthentication(string const &link_)
  : link_(link_)
{}

const std::int32_t confirmQrCodeAuthentication::ID;

void confirmQrCodeAuthentication::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "confirmQrCodeAuthentication");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

createBasicGroupChat::createBasicGroupChat()
  : basic_group_id_()
  , force_()
{}

createBasicGroupChat::createBasicGroupChat(int53 basic_group_id_, bool force_)
  : basic_group_id_(basic_group_id_)
  , force_(force_)
{}

const std::int32_t createBasicGroupChat::ID;

void createBasicGroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createBasicGroupChat");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

createChatInviteLink::createChatInviteLink()
  : chat_id_()
  , name_()
  , expiration_date_()
  , member_limit_()
  , creates_join_request_()
{}

createChatInviteLink::createChatInviteLink(int53 chat_id_, string const &name_, int32 expiration_date_, int32 member_limit_, bool creates_join_request_)
  : chat_id_(chat_id_)
  , name_(name_)
  , expiration_date_(expiration_date_)
  , member_limit_(member_limit_)
  , creates_join_request_(creates_join_request_)
{}

const std::int32_t createChatInviteLink::ID;

void createChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("name", name_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("member_limit", member_limit_);
    s.store_field("creates_join_request", creates_join_request_);
    s.store_class_end();
  }
}

createGroupCall::createGroupCall()
  : join_parameters_()
{}

createGroupCall::createGroupCall(object_ptr<groupCallJoinParameters> &&join_parameters_)
  : join_parameters_(std::move(join_parameters_))
{}

const std::int32_t createGroupCall::ID;

void createGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createGroupCall");
    s.store_object_field("join_parameters", static_cast<const BaseObject *>(join_parameters_.get()));
    s.store_class_end();
  }
}

createNewSupergroupChat::createNewSupergroupChat()
  : title_()
  , is_forum_()
  , is_channel_()
  , description_()
  , location_()
  , message_auto_delete_time_()
  , for_import_()
{}

createNewSupergroupChat::createNewSupergroupChat(string const &title_, bool is_forum_, bool is_channel_, string const &description_, object_ptr<chatLocation> &&location_, int32 message_auto_delete_time_, bool for_import_)
  : title_(title_)
  , is_forum_(is_forum_)
  , is_channel_(is_channel_)
  , description_(description_)
  , location_(std::move(location_))
  , message_auto_delete_time_(message_auto_delete_time_)
  , for_import_(for_import_)
{}

const std::int32_t createNewSupergroupChat::ID;

void createNewSupergroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewSupergroupChat");
    s.store_field("title", title_);
    s.store_field("is_forum", is_forum_);
    s.store_field("is_channel", is_channel_);
    s.store_field("description", description_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_field("for_import", for_import_);
    s.store_class_end();
  }
}

createUserTonWallet::createUserTonWallet()
  : user_id_()
{}

createUserTonWallet::createUserTonWallet(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t createUserTonWallet::ID;

void createUserTonWallet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createUserTonWallet");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

deleteAllChatWelcomeMessages::deleteAllChatWelcomeMessages()
  : chat_id_()
{}

deleteAllChatWelcomeMessages::deleteAllChatWelcomeMessages(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t deleteAllChatWelcomeMessages::ID;

void deleteAllChatWelcomeMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteAllChatWelcomeMessages");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

deleteAllRevokedChatInviteLinks::deleteAllRevokedChatInviteLinks()
  : chat_id_()
  , creator_user_id_()
{}

deleteAllRevokedChatInviteLinks::deleteAllRevokedChatInviteLinks(int53 chat_id_, int53 creator_user_id_)
  : chat_id_(chat_id_)
  , creator_user_id_(creator_user_id_)
{}

const std::int32_t deleteAllRevokedChatInviteLinks::ID;

void deleteAllRevokedChatInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteAllRevokedChatInviteLinks");
    s.store_field("chat_id", chat_id_);
    s.store_field("creator_user_id", creator_user_id_);
    s.store_class_end();
  }
}

deleteBusinessChatLink::deleteBusinessChatLink()
  : link_()
{}

deleteBusinessChatLink::deleteBusinessChatLink(string const &link_)
  : link_(link_)
{}

const std::int32_t deleteBusinessChatLink::ID;

void deleteBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteBusinessChatLink");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

editBusinessChatLink::editBusinessChatLink()
  : link_()
  , link_info_()
{}

editBusinessChatLink::editBusinessChatLink(string const &link_, object_ptr<inputBusinessChatLink> &&link_info_)
  : link_(link_)
  , link_info_(std::move(link_info_))
{}

const std::int32_t editBusinessChatLink::ID;

void editBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessChatLink");
    s.store_field("link", link_);
    s.store_object_field("link_info", static_cast<const BaseObject *>(link_info_.get()));
    s.store_class_end();
  }
}

editChatFolderInviteLink::editChatFolderInviteLink()
  : chat_folder_id_()
  , invite_link_()
  , name_()
  , chat_ids_()
{}

editChatFolderInviteLink::editChatFolderInviteLink(int32 chat_folder_id_, string const &invite_link_, string const &name_, array<int53> &&chat_ids_)
  : chat_folder_id_(chat_folder_id_)
  , invite_link_(invite_link_)
  , name_(name_)
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t editChatFolderInviteLink::ID;

void editChatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editChatFolderInviteLink");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

editForumTopic::editForumTopic()
  : chat_id_()
  , forum_topic_id_()
  , name_()
  , edit_icon_custom_emoji_()
  , icon_custom_emoji_id_()
{}

editForumTopic::editForumTopic(int53 chat_id_, int32 forum_topic_id_, string const &name_, bool edit_icon_custom_emoji_, int64 icon_custom_emoji_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , name_(name_)
  , edit_icon_custom_emoji_(edit_icon_custom_emoji_)
  , icon_custom_emoji_id_(icon_custom_emoji_id_)
{}

const std::int32_t editForumTopic::ID;

void editForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editForumTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("name", name_);
    s.store_field("edit_icon_custom_emoji", edit_icon_custom_emoji_);
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_class_end();
  }
}

editInlineMessageText::editInlineMessageText()
  : inline_message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editInlineMessageText::editInlineMessageText(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editInlineMessageText::ID;

void editInlineMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageText");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editMessageCaption::editMessageCaption()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , caption_()
  , show_caption_above_media_()
{}

editMessageCaption::editMessageCaption(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
{}

const std::int32_t editMessageCaption::ID;

void editMessageCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageCaption");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_class_end();
  }
}

editMessageReplyMarkup::editMessageReplyMarkup()
  : chat_id_()
  , message_id_()
  , reply_markup_()
{}

editMessageReplyMarkup::editMessageReplyMarkup(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t editMessageReplyMarkup::ID;

void editMessageReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageReplyMarkup");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

editWidgetData::editWidgetData()
  : widget_id_()
  , public_data_()
  , cache_time_()
{}

editWidgetData::editWidgetData(int64 widget_id_, string const &public_data_, int32 cache_time_)
  : widget_id_(widget_id_)
  , public_data_(public_data_)
  , cache_time_(cache_time_)
{}

const std::int32_t editWidgetData::ID;

void editWidgetData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editWidgetData");
    s.store_field("widget_id", widget_id_);
    s.store_field("public_data", public_data_);
    s.store_field("cache_time", cache_time_);
    s.store_class_end();
  }
}

forwardMessages::forwardMessages()
  : chat_id_()
  , topic_id_()
  , from_chat_id_()
  , message_ids_()
  , options_()
  , send_copy_()
  , remove_caption_()
{}

forwardMessages::forwardMessages(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, int53 from_chat_id_, array<int53> &&message_ids_, object_ptr<messageSendOptions> &&options_, bool send_copy_, bool remove_caption_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , from_chat_id_(from_chat_id_)
  , message_ids_(std::move(message_ids_))
  , options_(std::move(options_))
  , send_copy_(send_copy_)
  , remove_caption_(remove_caption_)
{}

const std::int32_t forwardMessages::ID;

void forwardMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forwardMessages");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_field("from_chat_id", from_chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_field("send_copy", send_copy_);
    s.store_field("remove_caption", remove_caption_);
    s.store_class_end();
  }
}

getAttachmentMenuBot::getAttachmentMenuBot()
  : bot_user_id_()
{}

getAttachmentMenuBot::getAttachmentMenuBot(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t getAttachmentMenuBot::ID;

void getAttachmentMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAttachmentMenuBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

getBackgroundUrl::getBackgroundUrl()
  : name_()
  , type_()
{}

getBackgroundUrl::getBackgroundUrl(string const &name_, object_ptr<BackgroundType> &&type_)
  : name_(name_)
  , type_(std::move(type_))
{}

const std::int32_t getBackgroundUrl::ID;

void getBackgroundUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBackgroundUrl");
    s.store_field("name", name_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

getBankCardInfo::getBankCardInfo()
  : bank_card_number_()
{}

getBankCardInfo::getBankCardInfo(string const &bank_card_number_)
  : bank_card_number_(bank_card_number_)
{}

const std::int32_t getBankCardInfo::ID;

void getBankCardInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBankCardInfo");
    s.store_field("bank_card_number", bank_card_number_);
    s.store_class_end();
  }
}

getBlockedMessageSenders::getBlockedMessageSenders()
  : block_list_()
  , offset_()
  , limit_()
{}

getBlockedMessageSenders::getBlockedMessageSenders(object_ptr<BlockList> &&block_list_, int32 offset_, int32 limit_)
  : block_list_(std::move(block_list_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getBlockedMessageSenders::ID;

void getBlockedMessageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBlockedMessageSenders");
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getBusinessAccountStarAmount::getBusinessAccountStarAmount()
  : business_connection_id_()
{}

getBusinessAccountStarAmount::getBusinessAccountStarAmount(string const &business_connection_id_)
  : business_connection_id_(business_connection_id_)
{}

const std::int32_t getBusinessAccountStarAmount::ID;

void getBusinessAccountStarAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessAccountStarAmount");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_class_end();
  }
}

getCallbackQueryAnswer::getCallbackQueryAnswer()
  : chat_id_()
  , message_id_()
  , payload_()
{}

getCallbackQueryAnswer::getCallbackQueryAnswer(int53 chat_id_, int53 message_id_, object_ptr<CallbackQueryPayload> &&payload_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , payload_(std::move(payload_))
{}

const std::int32_t getCallbackQueryAnswer::ID;

void getCallbackQueryAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCallbackQueryAnswer");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("payload", static_cast<const BaseObject *>(payload_.get()));
    s.store_class_end();
  }
}

getChatMessageByDate::getChatMessageByDate()
  : chat_id_()
  , date_()
{}

getChatMessageByDate::getChatMessageByDate(int53 chat_id_, int32 date_)
  : chat_id_(chat_id_)
  , date_(date_)
{}

const std::int32_t getChatMessageByDate::ID;

void getChatMessageByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessageByDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

getChatSimilarChats::getChatSimilarChats()
  : chat_id_()
{}

getChatSimilarChats::getChatSimilarChats(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatSimilarChats::ID;

void getChatSimilarChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatSimilarChats");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChats::getChats()
  : chat_list_()
  , limit_()
{}

getChats::getChats(object_ptr<ChatList> &&chat_list_, int32 limit_)
  : chat_list_(std::move(chat_list_))
  , limit_(limit_)
{}

const std::int32_t getChats::ID;

void getChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChats");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getCountries::getCountries() {
}

const std::int32_t getCountries::ID;

void getCountries::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCountries");
    s.store_class_end();
  }
}

getDirectMessagesChatTopic::getDirectMessagesChatTopic()
  : chat_id_()
  , topic_id_()
{}

getDirectMessagesChatTopic::getDirectMessagesChatTopic(int53 chat_id_, int53 topic_id_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
{}

const std::int32_t getDirectMessagesChatTopic::ID;

void getDirectMessagesChatTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDirectMessagesChatTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

getDirectMessagesChatTopicMessageByDate::getDirectMessagesChatTopicMessageByDate()
  : chat_id_()
  , topic_id_()
  , date_()
{}

getDirectMessagesChatTopicMessageByDate::getDirectMessagesChatTopicMessageByDate(int53 chat_id_, int53 topic_id_, int32 date_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
  , date_(date_)
{}

const std::int32_t getDirectMessagesChatTopicMessageByDate::ID;

void getDirectMessagesChatTopicMessageByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDirectMessagesChatTopicMessageByDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

getEmojiCategories::getEmojiCategories()
  : type_()
{}

getEmojiCategories::getEmojiCategories(object_ptr<EmojiCategoryType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t getEmojiCategories::ID;

void getEmojiCategories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getEmojiCategories");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

getForumTopic::getForumTopic()
  : chat_id_()
  , forum_topic_id_()
{}

getForumTopic::getForumTopic(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t getForumTopic::ID;

void getForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getForumTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

getForumTopicDefaultIcons::getForumTopicDefaultIcons() {
}

const std::int32_t getForumTopicDefaultIcons::ID;

void getForumTopicDefaultIcons::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getForumTopicDefaultIcons");
    s.store_class_end();
  }
}

getForumTopicHistory::getForumTopicHistory()
  : chat_id_()
  , forum_topic_id_()
  , from_message_id_()
  , offset_()
  , limit_()
{}

getForumTopicHistory::getForumTopicHistory(int53 chat_id_, int32 forum_topic_id_, int53 from_message_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getForumTopicHistory::ID;

void getForumTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getForumTopicHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getGroupCallParticipants::getGroupCallParticipants()
  : input_group_call_()
  , limit_()
{}

getGroupCallParticipants::getGroupCallParticipants(object_ptr<InputGroupCall> &&input_group_call_, int32 limit_)
  : input_group_call_(std::move(input_group_call_))
  , limit_(limit_)
{}

const std::int32_t getGroupCallParticipants::ID;

void getGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCallParticipants");
    s.store_object_field("input_group_call", static_cast<const BaseObject *>(input_group_call_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getGroupsInCommon::getGroupsInCommon()
  : user_id_()
  , offset_chat_id_()
  , limit_()
{}

getGroupsInCommon::getGroupsInCommon(int53 user_id_, int53 offset_chat_id_, int32 limit_)
  : user_id_(user_id_)
  , offset_chat_id_(offset_chat_id_)
  , limit_(limit_)
{}

const std::int32_t getGroupsInCommon::ID;

void getGroupsInCommon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupsInCommon");
    s.store_field("user_id", user_id_);
    s.store_field("offset_chat_id", offset_chat_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getInlineQueryResults::getInlineQueryResults()
  : bot_user_id_()
  , chat_id_()
  , user_location_()
  , query_()
  , offset_()
{}

getInlineQueryResults::getInlineQueryResults(int53 bot_user_id_, int53 chat_id_, object_ptr<location> &&user_location_, string const &query_, string const &offset_)
  : bot_user_id_(bot_user_id_)
  , chat_id_(chat_id_)
  , user_location_(std::move(user_location_))
  , query_(query_)
  , offset_(offset_)
{}

const std::int32_t getInlineQueryResults::ID;

void getInlineQueryResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInlineQueryResults");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("user_location", static_cast<const BaseObject *>(user_location_.get()));
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

getJsonString::getJsonString()
  : json_value_()
{}

getJsonString::getJsonString(object_ptr<JsonValue> &&json_value_)
  : json_value_(std::move(json_value_))
{}

const std::int32_t getJsonString::ID;

void getJsonString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getJsonString");
    s.store_object_field("json_value", static_cast<const BaseObject *>(json_value_.get()));
    s.store_class_end();
  }
}

getMainWebApp::getMainWebApp()
  : chat_id_()
  , bot_user_id_()
  , start_parameter_()
  , parameters_()
{}

getMainWebApp::getMainWebApp(int53 chat_id_, int53 bot_user_id_, string const &start_parameter_, object_ptr<webAppOpenParameters> &&parameters_)
  : chat_id_(chat_id_)
  , bot_user_id_(bot_user_id_)
  , start_parameter_(start_parameter_)
  , parameters_(std::move(parameters_))
{}

const std::int32_t getMainWebApp::ID;

void getMainWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMainWebApp");
    s.store_field("chat_id", chat_id_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("start_parameter", start_parameter_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

getMe::getMe() {
}

const std::int32_t getMe::ID;

void getMe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMe");
    s.store_class_end();
  }
}

getMessageStatistics::getMessageStatistics()
  : chat_id_()
  , message_id_()
  , is_dark_()
{}

getMessageStatistics::getMessageStatistics(int53 chat_id_, int53 message_id_, bool is_dark_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_dark_(is_dark_)
{}

const std::int32_t getMessageStatistics::ID;

void getMessageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageStatistics");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getPersonalChatHistory::getPersonalChatHistory()
  : user_id_()
  , limit_()
{}

getPersonalChatHistory::getPersonalChatHistory(int53 user_id_, int32 limit_)
  : user_id_(user_id_)
  , limit_(limit_)
{}

const std::int32_t getPersonalChatHistory::ID;

void getPersonalChatHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPersonalChatHistory");
    s.store_field("user_id", user_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getProfileShareThemeBackdrops::getProfileShareThemeBackdrops() {
}

const std::int32_t getProfileShareThemeBackdrops::ID;

void getProfileShareThemeBackdrops::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getProfileShareThemeBackdrops");
    s.store_class_end();
  }
}

getPushReceiverId::getPushReceiverId()
  : payload_()
{}

getPushReceiverId::getPushReceiverId(string const &payload_)
  : payload_(payload_)
{}

const std::int32_t getPushReceiverId::ID;

void getPushReceiverId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPushReceiverId");
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

getReadDatePrivacySettings::getReadDatePrivacySettings() {
}

const std::int32_t getReadDatePrivacySettings::ID;

void getReadDatePrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getReadDatePrivacySettings");
    s.store_class_end();
  }
}

getStorageStatisticsFast::getStorageStatisticsFast() {
}

const std::int32_t getStorageStatisticsFast::ID;

void getStorageStatisticsFast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStorageStatisticsFast");
    s.store_class_end();
  }
}

getTonConnectSessions::getTonConnectSessions() {
}

const std::int32_t getTonConnectSessions::ID;

void getTonConnectSessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonConnectSessions");
    s.store_class_end();
  }
}

getWebAppLinkUrl::getWebAppLinkUrl()
  : chat_id_()
  , bot_user_id_()
  , web_app_short_name_()
  , start_parameter_()
  , allow_write_access_()
  , parameters_()
{}

getWebAppLinkUrl::getWebAppLinkUrl(int53 chat_id_, int53 bot_user_id_, string const &web_app_short_name_, string const &start_parameter_, bool allow_write_access_, object_ptr<webAppOpenParameters> &&parameters_)
  : chat_id_(chat_id_)
  , bot_user_id_(bot_user_id_)
  , web_app_short_name_(web_app_short_name_)
  , start_parameter_(start_parameter_)
  , allow_write_access_(allow_write_access_)
  , parameters_(std::move(parameters_))
{}

const std::int32_t getWebAppLinkUrl::ID;

void getWebAppLinkUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWebAppLinkUrl");
    s.store_field("chat_id", chat_id_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("web_app_short_name", web_app_short_name_);
    s.store_field("start_parameter", start_parameter_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

getWidgetPublicData::getWidgetPublicData()
  : chat_id_()
  , message_id_()
{}

getWidgetPublicData::getWidgetPublicData(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getWidgetPublicData::ID;

void getWidgetPublicData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWidgetPublicData");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

isLoginEmailAddressRequired::isLoginEmailAddressRequired() {
}

const std::int32_t isLoginEmailAddressRequired::ID;

void isLoginEmailAddressRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "isLoginEmailAddressRequired");
    s.store_class_end();
  }
}

joinChat::joinChat()
  : chat_id_()
{}

joinChat::joinChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t joinChat::ID;

void joinChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

loadActiveStories::loadActiveStories()
  : story_list_()
{}

loadActiveStories::loadActiveStories(object_ptr<StoryList> &&story_list_)
  : story_list_(std::move(story_list_))
{}

const std::int32_t loadActiveStories::ID;

void loadActiveStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadActiveStories");
    s.store_object_field("story_list", static_cast<const BaseObject *>(story_list_.get()));
    s.store_class_end();
  }
}

loadChats::loadChats()
  : chat_list_()
  , limit_()
{}

loadChats::loadChats(object_ptr<ChatList> &&chat_list_, int32 limit_)
  : chat_list_(std::move(chat_list_))
  , limit_(limit_)
{}

const std::int32_t loadChats::ID;

void loadChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadChats");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

loadGroupCallParticipants::loadGroupCallParticipants()
  : group_call_id_()
  , limit_()
{}

loadGroupCallParticipants::loadGroupCallParticipants(int32 group_call_id_, int32 limit_)
  : group_call_id_(group_call_id_)
  , limit_(limit_)
{}

const std::int32_t loadGroupCallParticipants::ID;

void loadGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadGroupCallParticipants");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

loadQuickReplyShortcutMessages::loadQuickReplyShortcutMessages()
  : shortcut_id_()
{}

loadQuickReplyShortcutMessages::loadQuickReplyShortcutMessages(int32 shortcut_id_)
  : shortcut_id_(shortcut_id_)
{}

const std::int32_t loadQuickReplyShortcutMessages::ID;

void loadQuickReplyShortcutMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadQuickReplyShortcutMessages");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

openChat::openChat()
  : chat_id_()
{}

openChat::openChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t openChat::ID;

void openChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

openGiftAuction::openGiftAuction()
  : gift_id_()
{}

openGiftAuction::openGiftAuction(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t openGiftAuction::ID;

void openGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openGiftAuction");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

openSponsoredChat::openSponsoredChat()
  : sponsored_chat_unique_id_()
{}

openSponsoredChat::openSponsoredChat(int53 sponsored_chat_unique_id_)
  : sponsored_chat_unique_id_(sponsored_chat_unique_id_)
{}

const std::int32_t openSponsoredChat::ID;

void openSponsoredChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openSponsoredChat");
    s.store_field("sponsored_chat_unique_id", sponsored_chat_unique_id_);
    s.store_class_end();
  }
}

openStory::openStory()
  : story_poster_chat_id_()
  , story_id_()
{}

openStory::openStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t openStory::ID;

void openStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

parseMarkdown::parseMarkdown()
  : text_()
{}

parseMarkdown::parseMarkdown(object_ptr<formattedText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t parseMarkdown::ID;

void parseMarkdown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "parseMarkdown");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

recognizeSpeechInFile::recognizeSpeechInFile()
  : audio_file_()
  , recognition_id_()
{}

recognizeSpeechInFile::recognizeSpeechInFile(object_ptr<InputFile> &&audio_file_, int64 recognition_id_)
  : audio_file_(std::move(audio_file_))
  , recognition_id_(recognition_id_)
{}

const std::int32_t recognizeSpeechInFile::ID;

void recognizeSpeechInFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recognizeSpeechInFile");
    s.store_object_field("audio_file", static_cast<const BaseObject *>(audio_file_.get()));
    s.store_field("recognition_id", recognition_id_);
    s.store_class_end();
  }
}

registerUser::registerUser()
  : first_name_()
  , last_name_()
  , disable_notification_()
{}

registerUser::registerUser(string const &first_name_, string const &last_name_, bool disable_notification_)
  : first_name_(first_name_)
  , last_name_(last_name_)
  , disable_notification_(disable_notification_)
{}

const std::int32_t registerUser::ID;

void registerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "registerUser");
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("disable_notification", disable_notification_);
    s.store_class_end();
  }
}

removePendingLiveStoryReactions::removePendingLiveStoryReactions()
  : group_call_id_()
{}

removePendingLiveStoryReactions::removePendingLiveStoryReactions(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t removePendingLiveStoryReactions::ID;

void removePendingLiveStoryReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removePendingLiveStoryReactions");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

removeRecentHashtag::removeRecentHashtag()
  : hashtag_()
{}

removeRecentHashtag::removeRecentHashtag(string const &hashtag_)
  : hashtag_(hashtag_)
{}

const std::int32_t removeRecentHashtag::ID;

void removeRecentHashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeRecentHashtag");
    s.store_field("hashtag", hashtag_);
    s.store_class_end();
  }
}

reorderBotActiveUsernames::reorderBotActiveUsernames()
  : bot_user_id_()
  , usernames_()
{}

reorderBotActiveUsernames::reorderBotActiveUsernames(int53 bot_user_id_, array<string> &&usernames_)
  : bot_user_id_(bot_user_id_)
  , usernames_(std::move(usernames_))
{}

const std::int32_t reorderBotActiveUsernames::ID;

void reorderBotActiveUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderBotActiveUsernames");
    s.store_field("bot_user_id", bot_user_id_);
    { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

resendAuthenticationCode::resendAuthenticationCode()
  : reason_()
{}

resendAuthenticationCode::resendAuthenticationCode(object_ptr<ResendCodeReason> &&reason_)
  : reason_(std::move(reason_))
{}

const std::int32_t resendAuthenticationCode::ID;

void resendAuthenticationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendAuthenticationCode");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

revokeChatInviteLink::revokeChatInviteLink()
  : chat_id_()
  , invite_link_()
{}

revokeChatInviteLink::revokeChatInviteLink(int53 chat_id_, string const &invite_link_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
{}

const std::int32_t revokeChatInviteLink::ID;

void revokeChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revokeChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

searchChatAffiliateProgram::searchChatAffiliateProgram()
  : username_()
  , referrer_()
{}

searchChatAffiliateProgram::searchChatAffiliateProgram(string const &username_, string const &referrer_)
  : username_(username_)
  , referrer_(referrer_)
{}

const std::int32_t searchChatAffiliateProgram::ID;

void searchChatAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatAffiliateProgram");
    s.store_field("username", username_);
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

searchChatsOnServer::searchChatsOnServer()
  : query_()
  , type_filter_()
  , limit_()
{}

searchChatsOnServer::searchChatsOnServer(string const &query_, object_ptr<SearchChatTypeFilter> &&type_filter_, int32 limit_)
  : query_(query_)
  , type_filter_(std::move(type_filter_))
  , limit_(limit_)
{}

const std::int32_t searchChatsOnServer::ID;

void searchChatsOnServer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatsOnServer");
    s.store_field("query", query_);
    s.store_object_field("type_filter", static_cast<const BaseObject *>(type_filter_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchFileDownloads::searchFileDownloads()
  : query_()
  , only_active_()
  , only_completed_()
  , offset_()
  , limit_()
{}

searchFileDownloads::searchFileDownloads(string const &query_, bool only_active_, bool only_completed_, string const &offset_, int32 limit_)
  : query_(query_)
  , only_active_(only_active_)
  , only_completed_(only_completed_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchFileDownloads::ID;

void searchFileDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchFileDownloads");
    s.store_field("query", query_);
    s.store_field("only_active", only_active_);
    s.store_field("only_completed", only_completed_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchGiftsForResale::searchGiftsForResale()
  : gift_id_()
  , order_()
  , for_crafting_()
  , for_stars_()
  , attributes_()
  , offset_()
  , limit_()
{}

searchGiftsForResale::searchGiftsForResale(int64 gift_id_, object_ptr<GiftForResaleOrder> &&order_, bool for_crafting_, bool for_stars_, array<object_ptr<UpgradedGiftAttributeId>> &&attributes_, string const &offset_, int32 limit_)
  : gift_id_(gift_id_)
  , order_(std::move(order_))
  , for_crafting_(for_crafting_)
  , for_stars_(for_stars_)
  , attributes_(std::move(attributes_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchGiftsForResale::ID;

void searchGiftsForResale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchGiftsForResale");
    s.store_field("gift_id", gift_id_);
    s.store_object_field("order", static_cast<const BaseObject *>(order_.get()));
    s.store_field("for_crafting", for_crafting_);
    s.store_field("for_stars", for_stars_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchPublicMessagesByTag::searchPublicMessagesByTag()
  : tag_()
  , offset_()
  , limit_()
{}

searchPublicMessagesByTag::searchPublicMessagesByTag(string const &tag_, string const &offset_, int32 limit_)
  : tag_(tag_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchPublicMessagesByTag::ID;

void searchPublicMessagesByTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicMessagesByTag");
    s.store_field("tag", tag_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchWebApp::searchWebApp()
  : bot_user_id_()
  , web_app_short_name_()
{}

searchWebApp::searchWebApp(int53 bot_user_id_, string const &web_app_short_name_)
  : bot_user_id_(bot_user_id_)
  , web_app_short_name_(web_app_short_name_)
{}

const std::int32_t searchWebApp::ID;

void searchWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchWebApp");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("web_app_short_name", web_app_short_name_);
    s.store_class_end();
  }
}

sendAuthenticationFirebaseSms::sendAuthenticationFirebaseSms()
  : token_()
{}

sendAuthenticationFirebaseSms::sendAuthenticationFirebaseSms(string const &token_)
  : token_(token_)
{}

const std::int32_t sendAuthenticationFirebaseSms::ID;

void sendAuthenticationFirebaseSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendAuthenticationFirebaseSms");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

sendCallDebugInformation::sendCallDebugInformation()
  : call_id_()
  , debug_information_()
{}

sendCallDebugInformation::sendCallDebugInformation(object_ptr<InputCall> &&call_id_, string const &debug_information_)
  : call_id_(std::move(call_id_))
  , debug_information_(debug_information_)
{}

const std::int32_t sendCallDebugInformation::ID;

void sendCallDebugInformation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallDebugInformation");
    s.store_object_field("call_id", static_cast<const BaseObject *>(call_id_.get()));
    s.store_field("debug_information", debug_information_);
    s.store_class_end();
  }
}

sendMessage::sendMessage()
  : chat_id_()
  , topic_id_()
  , reply_to_()
  , options_()
  , reply_markup_()
  , input_message_content_()
{}

sendMessage::sendMessage(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<InputMessageReplyTo> &&reply_to_, object_ptr<messageSendOptions> &&options_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , reply_to_(std::move(reply_to_))
  , options_(std::move(options_))
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t sendMessage::ID;

void sendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

sendPhoneNumberCode::sendPhoneNumberCode()
  : phone_number_()
  , settings_()
  , type_()
{}

sendPhoneNumberCode::sendPhoneNumberCode(string const &phone_number_, object_ptr<phoneNumberAuthenticationSettings> &&settings_, object_ptr<PhoneNumberCodeType> &&type_)
  : phone_number_(phone_number_)
  , settings_(std::move(settings_))
  , type_(std::move(type_))
{}

const std::int32_t sendPhoneNumberCode::ID;

void sendPhoneNumberCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPhoneNumberCode");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

setAuthenticationPremiumPurchaseTransaction::setAuthenticationPremiumPurchaseTransaction()
  : transaction_()
  , is_restore_()
  , premium_day_count_()
  , currency_()
  , amount_()
{}

setAuthenticationPremiumPurchaseTransaction::setAuthenticationPremiumPurchaseTransaction(object_ptr<StoreTransaction> &&transaction_, bool is_restore_, int32 premium_day_count_, string const &currency_, int53 amount_)
  : transaction_(std::move(transaction_))
  , is_restore_(is_restore_)
  , premium_day_count_(premium_day_count_)
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t setAuthenticationPremiumPurchaseTransaction::ID;

void setAuthenticationPremiumPurchaseTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAuthenticationPremiumPurchaseTransaction");
    s.store_object_field("transaction", static_cast<const BaseObject *>(transaction_.get()));
    s.store_field("is_restore", is_restore_);
    s.store_field("premium_day_count", premium_day_count_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

setBotProfilePhoto::setBotProfilePhoto()
  : bot_user_id_()
  , photo_()
{}

setBotProfilePhoto::setBotProfilePhoto(int53 bot_user_id_, object_ptr<InputChatPhoto> &&photo_)
  : bot_user_id_(bot_user_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t setBotProfilePhoto::ID;

void setBotProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotProfilePhoto");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

setBotUpdatesStatus::setBotUpdatesStatus()
  : pending_update_count_()
  , error_message_()
{}

setBotUpdatesStatus::setBotUpdatesStatus(int32 pending_update_count_, string const &error_message_)
  : pending_update_count_(pending_update_count_)
  , error_message_(error_message_)
{}

const std::int32_t setBotUpdatesStatus::ID;

void setBotUpdatesStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotUpdatesStatus");
    s.store_field("pending_update_count", pending_update_count_);
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

setBusinessAccountBio::setBusinessAccountBio()
  : business_connection_id_()
  , bio_()
{}

setBusinessAccountBio::setBusinessAccountBio(string const &business_connection_id_, string const &bio_)
  : business_connection_id_(business_connection_id_)
  , bio_(bio_)
{}

const std::int32_t setBusinessAccountBio::ID;

void setBusinessAccountBio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAccountBio");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("bio", bio_);
    s.store_class_end();
  }
}

setChatAccentColor::setChatAccentColor()
  : chat_id_()
  , accent_color_id_()
  , background_custom_emoji_id_()
{}

setChatAccentColor::setChatAccentColor(int53 chat_id_, int32 accent_color_id_, int64 background_custom_emoji_id_)
  : chat_id_(chat_id_)
  , accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
{}

const std::int32_t setChatAccentColor::ID;

void setChatAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatAccentColor");
    s.store_field("chat_id", chat_id_);
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_class_end();
  }
}

setChatClientData::setChatClientData()
  : chat_id_()
  , client_data_()
{}

setChatClientData::setChatClientData(int53 chat_id_, string const &client_data_)
  : chat_id_(chat_id_)
  , client_data_(client_data_)
{}

const std::int32_t setChatClientData::ID;

void setChatClientData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatClientData");
    s.store_field("chat_id", chat_id_);
    s.store_field("client_data", client_data_);
    s.store_class_end();
  }
}

setChatDraftMessage::setChatDraftMessage()
  : chat_id_()
  , topic_id_()
  , draft_message_()
{}

setChatDraftMessage::setChatDraftMessage(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<draftMessage> &&draft_message_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t setChatDraftMessage::ID;

void setChatDraftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatDraftMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

setChatLocation::setChatLocation()
  : chat_id_()
  , location_()
{}

setChatLocation::setChatLocation(int53 chat_id_, object_ptr<chatLocation> &&location_)
  : chat_id_(chat_id_)
  , location_(std::move(location_))
{}

const std::int32_t setChatLocation::ID;

void setChatLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatLocation");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

setChatMemberStatus::setChatMemberStatus()
  : chat_id_()
  , member_id_()
  , status_()
{}

setChatMemberStatus::setChatMemberStatus(int53 chat_id_, object_ptr<MessageSender> &&member_id_, object_ptr<ChatMemberStatus> &&status_)
  : chat_id_(chat_id_)
  , member_id_(std::move(member_id_))
  , status_(std::move(status_))
{}

const std::int32_t setChatMemberStatus::ID;

void setChatMemberStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatMemberStatus");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

setChatTitle::setChatTitle()
  : chat_id_()
  , title_()
{}

setChatTitle::setChatTitle(int53 chat_id_, string const &title_)
  : chat_id_(chat_id_)
  , title_(title_)
{}

const std::int32_t setChatTitle::ID;

void setChatTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatTitle");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

setEmojiStatus::setEmojiStatus()
  : emoji_status_()
{}

setEmojiStatus::setEmojiStatus(object_ptr<emojiStatus> &&emoji_status_)
  : emoji_status_(std::move(emoji_status_))
{}

const std::int32_t setEmojiStatus::ID;

void setEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setEmojiStatus");
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

setGiftCollectionName::setGiftCollectionName()
  : owner_id_()
  , collection_id_()
  , name_()
{}

setGiftCollectionName::setGiftCollectionName(object_ptr<MessageSender> &&owner_id_, int32 collection_id_, string const &name_)
  : owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
  , name_(name_)
{}

const std::int32_t setGiftCollectionName::ID;

void setGiftCollectionName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGiftCollectionName");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

setName::setName()
  : first_name_()
  , last_name_()
{}

setName::setName(string const &first_name_, string const &last_name_)
  : first_name_(first_name_)
  , last_name_(last_name_)
{}

const std::int32_t setName::ID;

void setName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setName");
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_class_end();
  }
}

setPersonalChat::setPersonalChat()
  : chat_id_()
{}

setPersonalChat::setPersonalChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t setPersonalChat::ID;

void setPersonalChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPersonalChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

setProfileShareTheme::setProfileShareTheme()
  : chat_id_()
  , theme_()
{}

setProfileShareTheme::setProfileShareTheme(int53 chat_id_, object_ptr<InputProfileShareTheme> &&theme_)
  : chat_id_(chat_id_)
  , theme_(std::move(theme_))
{}

const std::int32_t setProfileShareTheme::ID;

void setProfileShareTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setProfileShareTheme");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

setQuickReplyShortcutName::setQuickReplyShortcutName()
  : shortcut_id_()
  , name_()
{}

setQuickReplyShortcutName::setQuickReplyShortcutName(int32 shortcut_id_, string const &name_)
  : shortcut_id_(shortcut_id_)
  , name_(name_)
{}

const std::int32_t setQuickReplyShortcutName::ID;

void setQuickReplyShortcutName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setQuickReplyShortcutName");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

setRecoveryEmailAddress::setRecoveryEmailAddress()
  : password_()
  , new_recovery_email_address_()
{}

setRecoveryEmailAddress::setRecoveryEmailAddress(string const &password_, string const &new_recovery_email_address_)
  : password_(password_)
  , new_recovery_email_address_(new_recovery_email_address_)
{}

const std::int32_t setRecoveryEmailAddress::ID;

void setRecoveryEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setRecoveryEmailAddress");
    s.store_field("password", "[REDACTED]");
    s.store_field("new_recovery_email_address", new_recovery_email_address_);
    s.store_class_end();
  }
}

setStoryAlbumName::setStoryAlbumName()
  : chat_id_()
  , story_album_id_()
  , name_()
{}

setStoryAlbumName::setStoryAlbumName(int53 chat_id_, int32 story_album_id_, string const &name_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
  , name_(name_)
{}

const std::int32_t setStoryAlbumName::ID;

void setStoryAlbumName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStoryAlbumName");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

setSupergroupMainProfileTab::setSupergroupMainProfileTab()
  : supergroup_id_()
  , main_profile_tab_()
{}

setSupergroupMainProfileTab::setSupergroupMainProfileTab(int53 supergroup_id_, object_ptr<ProfileTab> &&main_profile_tab_)
  : supergroup_id_(supergroup_id_)
  , main_profile_tab_(std::move(main_profile_tab_))
{}

const std::int32_t setSupergroupMainProfileTab::ID;

void setSupergroupMainProfileTab::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupMainProfileTab");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_object_field("main_profile_tab", static_cast<const BaseObject *>(main_profile_tab_.get()));
    s.store_class_end();
  }
}

setSupergroupUnrestrictBoostCount::setSupergroupUnrestrictBoostCount()
  : supergroup_id_()
  , unrestrict_boost_count_()
{}

setSupergroupUnrestrictBoostCount::setSupergroupUnrestrictBoostCount(int53 supergroup_id_, int32 unrestrict_boost_count_)
  : supergroup_id_(supergroup_id_)
  , unrestrict_boost_count_(unrestrict_boost_count_)
{}

const std::int32_t setSupergroupUnrestrictBoostCount::ID;

void setSupergroupUnrestrictBoostCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupUnrestrictBoostCount");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("unrestrict_boost_count", unrestrict_boost_count_);
    s.store_class_end();
  }
}

setTonConnectSessionWalletClientId::setTonConnectSessionWalletClientId()
  : session_id_()
  , wallet_client_id_()
{}

setTonConnectSessionWalletClientId::setTonConnectSessionWalletClientId(int64 session_id_, string const &wallet_client_id_)
  : session_id_(session_id_)
  , wallet_client_id_(wallet_client_id_)
{}

const std::int32_t setTonConnectSessionWalletClientId::ID;

void setTonConnectSessionWalletClientId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setTonConnectSessionWalletClientId");
    s.store_field("session_id", session_id_);
    s.store_field("wallet_client_id", wallet_client_id_);
    s.store_class_end();
  }
}

sharePhoneNumber::sharePhoneNumber()
  : user_id_()
{}

sharePhoneNumber::sharePhoneNumber(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t sharePhoneNumber::ID;

void sharePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sharePhoneNumber");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

stopBusinessPoll::stopBusinessPoll()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
{}

stopBusinessPoll::stopBusinessPoll(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t stopBusinessPoll::ID;

void stopBusinessPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stopBusinessPoll");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

toggleGeneralForumTopicIsHidden::toggleGeneralForumTopicIsHidden()
  : chat_id_()
  , is_hidden_()
{}

toggleGeneralForumTopicIsHidden::toggleGeneralForumTopicIsHidden(int53 chat_id_, bool is_hidden_)
  : chat_id_(chat_id_)
  , is_hidden_(is_hidden_)
{}

const std::int32_t toggleGeneralForumTopicIsHidden::ID;

void toggleGeneralForumTopicIsHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGeneralForumTopicIsHidden");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_hidden", is_hidden_);
    s.store_class_end();
  }
}

toggleGiftIsSaved::toggleGiftIsSaved()
  : received_gift_id_()
  , is_saved_()
{}

toggleGiftIsSaved::toggleGiftIsSaved(string const &received_gift_id_, bool is_saved_)
  : received_gift_id_(received_gift_id_)
  , is_saved_(is_saved_)
{}

const std::int32_t toggleGiftIsSaved::ID;

void toggleGiftIsSaved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGiftIsSaved");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_field("is_saved", is_saved_);
    s.store_class_end();
  }
}

toggleGroupCallIsMyVideoPaused::toggleGroupCallIsMyVideoPaused()
  : group_call_id_()
  , is_my_video_paused_()
{}

toggleGroupCallIsMyVideoPaused::toggleGroupCallIsMyVideoPaused(int32 group_call_id_, bool is_my_video_paused_)
  : group_call_id_(group_call_id_)
  , is_my_video_paused_(is_my_video_paused_)
{}

const std::int32_t toggleGroupCallIsMyVideoPaused::ID;

void toggleGroupCallIsMyVideoPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallIsMyVideoPaused");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("is_my_video_paused", is_my_video_paused_);
    s.store_class_end();
  }
}

toggleGroupCallParticipantIsMuted::toggleGroupCallParticipantIsMuted()
  : group_call_id_()
  , participant_id_()
  , is_muted_()
{}

toggleGroupCallParticipantIsMuted::toggleGroupCallParticipantIsMuted(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, bool is_muted_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , is_muted_(is_muted_)
{}

const std::int32_t toggleGroupCallParticipantIsMuted::ID;

void toggleGroupCallParticipantIsMuted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallParticipantIsMuted");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_muted", is_muted_);
    s.store_class_end();
  }
}

unpinAllChatMessages::unpinAllChatMessages()
  : chat_id_()
{}

unpinAllChatMessages::unpinAllChatMessages(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t unpinAllChatMessages::ID;

void unpinAllChatMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unpinAllChatMessages");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
