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


addedProxy::addedProxy()
  : id_()
  , last_used_date_()
  , is_enabled_()
  , comment_()
  , proxy_()
{}

addedProxy::addedProxy(int32 id_, int32 last_used_date_, bool is_enabled_, string const &comment_, object_ptr<proxy> &&proxy_)
  : id_(id_)
  , last_used_date_(last_used_date_)
  , is_enabled_(is_enabled_)
  , comment_(comment_)
  , proxy_(std::move(proxy_))
{}

const std::int32_t addedProxy::ID;

void addedProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addedProxy");
    s.store_field("id", id_);
    s.store_field("last_used_date", last_used_date_);
    s.store_field("is_enabled", is_enabled_);
    s.store_field("comment", comment_);
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_class_end();
  }
}

addedReaction::addedReaction()
  : type_()
  , sender_id_()
  , is_outgoing_()
  , date_()
{}

addedReaction::addedReaction(object_ptr<ReactionType> &&type_, object_ptr<MessageSender> &&sender_id_, bool is_outgoing_, int32 date_)
  : type_(std::move(type_))
  , sender_id_(std::move(sender_id_))
  , is_outgoing_(is_outgoing_)
  , date_(date_)
{}

const std::int32_t addedReaction::ID;

void addedReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addedReaction");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

addedReactions::addedReactions()
  : total_count_()
  , reactions_()
  , next_offset_()
{}

addedReactions::addedReactions(int32 total_count_, array<object_ptr<addedReaction>> &&reactions_, string const &next_offset_)
  : total_count_(total_count_)
  , reactions_(std::move(reactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t addedReactions::ID;

void addedReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addedReactions");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

affiliateProgramInfo::affiliateProgramInfo()
  : parameters_()
  , end_date_()
  , daily_revenue_per_user_amount_()
{}

affiliateProgramInfo::affiliateProgramInfo(object_ptr<affiliateProgramParameters> &&parameters_, int32 end_date_, object_ptr<starAmount> &&daily_revenue_per_user_amount_)
  : parameters_(std::move(parameters_))
  , end_date_(end_date_)
  , daily_revenue_per_user_amount_(std::move(daily_revenue_per_user_amount_))
{}

const std::int32_t affiliateProgramInfo::ID;

void affiliateProgramInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateProgramInfo");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("end_date", end_date_);
    s.store_object_field("daily_revenue_per_user_amount", static_cast<const BaseObject *>(daily_revenue_per_user_amount_.get()));
    s.store_class_end();
  }
}

affiliateTypeCurrentUser::affiliateTypeCurrentUser() {
}

const std::int32_t affiliateTypeCurrentUser::ID;

void affiliateTypeCurrentUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateTypeCurrentUser");
    s.store_class_end();
  }
}

affiliateTypeBot::affiliateTypeBot()
  : user_id_()
{}

affiliateTypeBot::affiliateTypeBot(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t affiliateTypeBot::ID;

void affiliateTypeBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateTypeBot");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

affiliateTypeChannel::affiliateTypeChannel()
  : chat_id_()
{}

affiliateTypeChannel::affiliateTypeChannel(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t affiliateTypeChannel::ID;

void affiliateTypeChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateTypeChannel");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

areaPosition::areaPosition()
  : x_percentage_()
  , y_percentage_()
  , width_percentage_()
  , height_percentage_()
  , rotation_angle_()
  , corner_radius_percentage_()
{}

areaPosition::areaPosition(double x_percentage_, double y_percentage_, double width_percentage_, double height_percentage_, double rotation_angle_, double corner_radius_percentage_)
  : x_percentage_(x_percentage_)
  , y_percentage_(y_percentage_)
  , width_percentage_(width_percentage_)
  , height_percentage_(height_percentage_)
  , rotation_angle_(rotation_angle_)
  , corner_radius_percentage_(corner_radius_percentage_)
{}

const std::int32_t areaPosition::ID;

void areaPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "areaPosition");
    s.store_field("x_percentage", x_percentage_);
    s.store_field("y_percentage", y_percentage_);
    s.store_field("width_percentage", width_percentage_);
    s.store_field("height_percentage", height_percentage_);
    s.store_field("rotation_angle", rotation_angle_);
    s.store_field("corner_radius_percentage", corner_radius_percentage_);
    s.store_class_end();
  }
}

birthdate::birthdate()
  : day_()
  , month_()
  , year_()
{}

birthdate::birthdate(int32 day_, int32 month_, int32 year_)
  : day_(day_)
  , month_(month_)
  , year_(year_)
{}

const std::int32_t birthdate::ID;

void birthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "birthdate");
    s.store_field("day", day_);
    s.store_field("month", month_);
    s.store_field("year", year_);
    s.store_class_end();
  }
}

botCommand::botCommand()
  : command_()
  , description_()
  , is_ephemeral_()
{}

botCommand::botCommand(string const &command_, string const &description_, bool is_ephemeral_)
  : command_(command_)
  , description_(description_)
  , is_ephemeral_(is_ephemeral_)
{}

const std::int32_t botCommand::ID;

void botCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommand");
    s.store_field("command", command_);
    s.store_field("description", description_);
    s.store_field("is_ephemeral", is_ephemeral_);
    s.store_class_end();
  }
}

botMenuButton::botMenuButton()
  : text_()
  , url_()
{}

botMenuButton::botMenuButton(string const &text_, string const &url_)
  : text_(text_)
  , url_(url_)
{}

const std::int32_t botMenuButton::ID;

void botMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMenuButton");
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

businessBotManageBar::businessBotManageBar()
  : bot_user_id_()
  , manage_url_()
  , is_bot_paused_()
  , can_bot_reply_()
{}

businessBotManageBar::businessBotManageBar(int53 bot_user_id_, string const &manage_url_, bool is_bot_paused_, bool can_bot_reply_)
  : bot_user_id_(bot_user_id_)
  , manage_url_(manage_url_)
  , is_bot_paused_(is_bot_paused_)
  , can_bot_reply_(can_bot_reply_)
{}

const std::int32_t businessBotManageBar::ID;

void businessBotManageBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessBotManageBar");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("manage_url", manage_url_);
    s.store_field("is_bot_paused", is_bot_paused_);
    s.store_field("can_bot_reply", can_bot_reply_);
    s.store_class_end();
  }
}

businessConnectedBotInfo::businessConnectedBotInfo()
  : bot_()
  , connection_date_()
  , device_model_()
  , location_()
{}

businessConnectedBotInfo::businessConnectedBotInfo(object_ptr<businessConnectedBot> &&bot_, int32 connection_date_, string const &device_model_, string const &location_)
  : bot_(std::move(bot_))
  , connection_date_(connection_date_)
  , device_model_(device_model_)
  , location_(location_)
{}

const std::int32_t businessConnectedBotInfo::ID;

void businessConnectedBotInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessConnectedBotInfo");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("connection_date", connection_date_);
    s.store_field("device_model", device_model_);
    s.store_field("location", location_);
    s.store_class_end();
  }
}

businessOpeningHours::businessOpeningHours()
  : time_zone_id_()
  , opening_hours_()
{}

businessOpeningHours::businessOpeningHours(string const &time_zone_id_, array<object_ptr<businessOpeningHoursInterval>> &&opening_hours_)
  : time_zone_id_(time_zone_id_)
  , opening_hours_(std::move(opening_hours_))
{}

const std::int32_t businessOpeningHours::ID;

void businessOpeningHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessOpeningHours");
    s.store_field("time_zone_id", time_zone_id_);
    { s.store_vector_begin("opening_hours", opening_hours_.size()); for (const auto &_value : opening_hours_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessRecipients::businessRecipients()
  : chat_ids_()
  , excluded_chat_ids_()
  , select_existing_chats_()
  , select_new_chats_()
  , select_contacts_()
  , select_non_contacts_()
  , exclude_selected_()
{}

businessRecipients::businessRecipients(array<int53> &&chat_ids_, array<int53> &&excluded_chat_ids_, bool select_existing_chats_, bool select_new_chats_, bool select_contacts_, bool select_non_contacts_, bool exclude_selected_)
  : chat_ids_(std::move(chat_ids_))
  , excluded_chat_ids_(std::move(excluded_chat_ids_))
  , select_existing_chats_(select_existing_chats_)
  , select_new_chats_(select_new_chats_)
  , select_contacts_(select_contacts_)
  , select_non_contacts_(select_non_contacts_)
  , exclude_selected_(exclude_selected_)
{}

const std::int32_t businessRecipients::ID;

void businessRecipients::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessRecipients");
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("excluded_chat_ids", excluded_chat_ids_.size()); for (const auto &_value : excluded_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("select_existing_chats", select_existing_chats_);
    s.store_field("select_new_chats", select_new_chats_);
    s.store_field("select_contacts", select_contacts_);
    s.store_field("select_non_contacts", select_non_contacts_);
    s.store_field("exclude_selected", exclude_selected_);
    s.store_class_end();
  }
}

call::call()
  : id_()
  , unique_id_()
  , user_id_()
  , is_outgoing_()
  , is_video_()
  , state_()
{}

call::call(int32 id_, int64 unique_id_, int53 user_id_, bool is_outgoing_, bool is_video_, object_ptr<CallState> &&state_)
  : id_(id_)
  , unique_id_(unique_id_)
  , user_id_(user_id_)
  , is_outgoing_(is_outgoing_)
  , is_video_(is_video_)
  , state_(std::move(state_))
{}

const std::int32_t call::ID;

void call::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "call");
    s.store_field("id", id_);
    s.store_field("unique_id", unique_id_);
    s.store_field("user_id", user_id_);
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("is_video", is_video_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

callServer::callServer()
  : id_()
  , ip_address_()
  , ipv6_address_()
  , port_()
  , type_()
{}

callServer::callServer(int64 id_, string const &ip_address_, string const &ipv6_address_, int32 port_, object_ptr<CallServerType> &&type_)
  : id_(id_)
  , ip_address_(ip_address_)
  , ipv6_address_(ipv6_address_)
  , port_(port_)
  , type_(std::move(type_))
{}

const std::int32_t callServer::ID;

void callServer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callServer");
    s.store_field("id", id_);
    s.store_field("ip_address", ip_address_);
    s.store_field("ipv6_address", ipv6_address_);
    s.store_field("port", port_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

canTransferOwnershipResultOk::canTransferOwnershipResultOk() {
}

const std::int32_t canTransferOwnershipResultOk::ID;

void canTransferOwnershipResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultOk");
    s.store_class_end();
  }
}

canTransferOwnershipResultPasswordNeeded::canTransferOwnershipResultPasswordNeeded() {
}

const std::int32_t canTransferOwnershipResultPasswordNeeded::ID;

void canTransferOwnershipResultPasswordNeeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultPasswordNeeded");
    s.store_class_end();
  }
}

canTransferOwnershipResultPasswordTooFresh::canTransferOwnershipResultPasswordTooFresh()
  : retry_after_()
{}

canTransferOwnershipResultPasswordTooFresh::canTransferOwnershipResultPasswordTooFresh(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t canTransferOwnershipResultPasswordTooFresh::ID;

void canTransferOwnershipResultPasswordTooFresh::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultPasswordTooFresh");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

canTransferOwnershipResultSessionTooFresh::canTransferOwnershipResultSessionTooFresh()
  : retry_after_()
{}

canTransferOwnershipResultSessionTooFresh::canTransferOwnershipResultSessionTooFresh(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t canTransferOwnershipResultSessionTooFresh::ID;

void canTransferOwnershipResultSessionTooFresh::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultSessionTooFresh");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

chatAdministratorRights::chatAdministratorRights()
  : can_manage_chat_()
  , can_change_info_()
  , can_post_messages_()
  , can_edit_messages_()
  , can_delete_messages_()
  , can_invite_users_()
  , can_restrict_members_()
  , can_pin_messages_()
  , can_manage_topics_()
  , can_promote_members_()
  , can_manage_video_chats_()
  , can_post_stories_()
  , can_edit_stories_()
  , can_delete_stories_()
  , can_manage_direct_messages_()
  , can_manage_tags_()
  , can_send_welcome_messages_()
  , is_anonymous_()
{}

chatAdministratorRights::chatAdministratorRights(bool can_manage_chat_, bool can_change_info_, bool can_post_messages_, bool can_edit_messages_, bool can_delete_messages_, bool can_invite_users_, bool can_restrict_members_, bool can_pin_messages_, bool can_manage_topics_, bool can_promote_members_, bool can_manage_video_chats_, bool can_post_stories_, bool can_edit_stories_, bool can_delete_stories_, bool can_manage_direct_messages_, bool can_manage_tags_, bool can_send_welcome_messages_, bool is_anonymous_)
  : can_manage_chat_(can_manage_chat_)
  , can_change_info_(can_change_info_)
  , can_post_messages_(can_post_messages_)
  , can_edit_messages_(can_edit_messages_)
  , can_delete_messages_(can_delete_messages_)
  , can_invite_users_(can_invite_users_)
  , can_restrict_members_(can_restrict_members_)
  , can_pin_messages_(can_pin_messages_)
  , can_manage_topics_(can_manage_topics_)
  , can_promote_members_(can_promote_members_)
  , can_manage_video_chats_(can_manage_video_chats_)
  , can_post_stories_(can_post_stories_)
  , can_edit_stories_(can_edit_stories_)
  , can_delete_stories_(can_delete_stories_)
  , can_manage_direct_messages_(can_manage_direct_messages_)
  , can_manage_tags_(can_manage_tags_)
  , can_send_welcome_messages_(can_send_welcome_messages_)
  , is_anonymous_(is_anonymous_)
{}

const std::int32_t chatAdministratorRights::ID;

void chatAdministratorRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdministratorRights");
    s.store_field("can_manage_chat", can_manage_chat_);
    s.store_field("can_change_info", can_change_info_);
    s.store_field("can_post_messages", can_post_messages_);
    s.store_field("can_edit_messages", can_edit_messages_);
    s.store_field("can_delete_messages", can_delete_messages_);
    s.store_field("can_invite_users", can_invite_users_);
    s.store_field("can_restrict_members", can_restrict_members_);
    s.store_field("can_pin_messages", can_pin_messages_);
    s.store_field("can_manage_topics", can_manage_topics_);
    s.store_field("can_promote_members", can_promote_members_);
    s.store_field("can_manage_video_chats", can_manage_video_chats_);
    s.store_field("can_post_stories", can_post_stories_);
    s.store_field("can_edit_stories", can_edit_stories_);
    s.store_field("can_delete_stories", can_delete_stories_);
    s.store_field("can_manage_direct_messages", can_manage_direct_messages_);
    s.store_field("can_manage_tags", can_manage_tags_);
    s.store_field("can_send_welcome_messages", can_send_welcome_messages_);
    s.store_field("is_anonymous", is_anonymous_);
    s.store_class_end();
  }
}

chatBoostStatus::chatBoostStatus()
  : boost_url_()
  , applied_slot_ids_()
  , level_()
  , gift_code_boost_count_()
  , boost_count_()
  , current_level_boost_count_()
  , next_level_boost_count_()
  , premium_member_count_()
  , premium_member_percentage_()
  , prepaid_giveaways_()
{}

chatBoostStatus::chatBoostStatus(string const &boost_url_, array<int32> &&applied_slot_ids_, int32 level_, int32 gift_code_boost_count_, int32 boost_count_, int32 current_level_boost_count_, int32 next_level_boost_count_, int32 premium_member_count_, double premium_member_percentage_, array<object_ptr<prepaidGiveaway>> &&prepaid_giveaways_)
  : boost_url_(boost_url_)
  , applied_slot_ids_(std::move(applied_slot_ids_))
  , level_(level_)
  , gift_code_boost_count_(gift_code_boost_count_)
  , boost_count_(boost_count_)
  , current_level_boost_count_(current_level_boost_count_)
  , next_level_boost_count_(next_level_boost_count_)
  , premium_member_count_(premium_member_count_)
  , premium_member_percentage_(premium_member_percentage_)
  , prepaid_giveaways_(std::move(prepaid_giveaways_))
{}

const std::int32_t chatBoostStatus::ID;

void chatBoostStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostStatus");
    s.store_field("boost_url", boost_url_);
    { s.store_vector_begin("applied_slot_ids", applied_slot_ids_.size()); for (const auto &_value : applied_slot_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("level", level_);
    s.store_field("gift_code_boost_count", gift_code_boost_count_);
    s.store_field("boost_count", boost_count_);
    s.store_field("current_level_boost_count", current_level_boost_count_);
    s.store_field("next_level_boost_count", next_level_boost_count_);
    s.store_field("premium_member_count", premium_member_count_);
    s.store_field("premium_member_percentage", premium_member_percentage_);
    { s.store_vector_begin("prepaid_giveaways", prepaid_giveaways_.size()); for (const auto &_value : prepaid_giveaways_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatFolder::chatFolder()
  : name_()
  , icon_()
  , color_id_()
  , is_shareable_()
  , pinned_chat_ids_()
  , included_chat_ids_()
  , excluded_chat_ids_()
  , exclude_muted_()
  , exclude_read_()
  , exclude_archived_()
  , include_contacts_()
  , include_non_contacts_()
  , include_bots_()
  , include_groups_()
  , include_channels_()
{}

chatFolder::chatFolder(object_ptr<chatFolderName> &&name_, object_ptr<chatFolderIcon> &&icon_, int32 color_id_, bool is_shareable_, array<int53> &&pinned_chat_ids_, array<int53> &&included_chat_ids_, array<int53> &&excluded_chat_ids_, bool exclude_muted_, bool exclude_read_, bool exclude_archived_, bool include_contacts_, bool include_non_contacts_, bool include_bots_, bool include_groups_, bool include_channels_)
  : name_(std::move(name_))
  , icon_(std::move(icon_))
  , color_id_(color_id_)
  , is_shareable_(is_shareable_)
  , pinned_chat_ids_(std::move(pinned_chat_ids_))
  , included_chat_ids_(std::move(included_chat_ids_))
  , excluded_chat_ids_(std::move(excluded_chat_ids_))
  , exclude_muted_(exclude_muted_)
  , exclude_read_(exclude_read_)
  , exclude_archived_(exclude_archived_)
  , include_contacts_(include_contacts_)
  , include_non_contacts_(include_non_contacts_)
  , include_bots_(include_bots_)
  , include_groups_(include_groups_)
  , include_channels_(include_channels_)
{}

const std::int32_t chatFolder::ID;

void chatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolder");
    s.store_object_field("name", static_cast<const BaseObject *>(name_.get()));
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_field("color_id", color_id_);
    s.store_field("is_shareable", is_shareable_);
    { s.store_vector_begin("pinned_chat_ids", pinned_chat_ids_.size()); for (const auto &_value : pinned_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("included_chat_ids", included_chat_ids_.size()); for (const auto &_value : included_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("excluded_chat_ids", excluded_chat_ids_.size()); for (const auto &_value : excluded_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("exclude_muted", exclude_muted_);
    s.store_field("exclude_read", exclude_read_);
    s.store_field("exclude_archived", exclude_archived_);
    s.store_field("include_contacts", include_contacts_);
    s.store_field("include_non_contacts", include_non_contacts_);
    s.store_field("include_bots", include_bots_);
    s.store_field("include_groups", include_groups_);
    s.store_field("include_channels", include_channels_);
    s.store_class_end();
  }
}

chatInviteLink::chatInviteLink()
  : invite_link_()
  , name_()
  , creator_user_id_()
  , date_()
  , edit_date_()
  , expiration_date_()
  , subscription_pricing_()
  , member_limit_()
  , member_count_()
  , expired_member_count_()
  , pending_join_request_count_()
  , creates_join_request_()
  , is_primary_()
  , is_revoked_()
{}

chatInviteLink::chatInviteLink(string const &invite_link_, string const &name_, int53 creator_user_id_, int32 date_, int32 edit_date_, int32 expiration_date_, object_ptr<starSubscriptionPricing> &&subscription_pricing_, int32 member_limit_, int32 member_count_, int32 expired_member_count_, int32 pending_join_request_count_, bool creates_join_request_, bool is_primary_, bool is_revoked_)
  : invite_link_(invite_link_)
  , name_(name_)
  , creator_user_id_(creator_user_id_)
  , date_(date_)
  , edit_date_(edit_date_)
  , expiration_date_(expiration_date_)
  , subscription_pricing_(std::move(subscription_pricing_))
  , member_limit_(member_limit_)
  , member_count_(member_count_)
  , expired_member_count_(expired_member_count_)
  , pending_join_request_count_(pending_join_request_count_)
  , creates_join_request_(creates_join_request_)
  , is_primary_(is_primary_)
  , is_revoked_(is_revoked_)
{}

const std::int32_t chatInviteLink::ID;

void chatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    s.store_field("creator_user_id", creator_user_id_);
    s.store_field("date", date_);
    s.store_field("edit_date", edit_date_);
    s.store_field("expiration_date", expiration_date_);
    s.store_object_field("subscription_pricing", static_cast<const BaseObject *>(subscription_pricing_.get()));
    s.store_field("member_limit", member_limit_);
    s.store_field("member_count", member_count_);
    s.store_field("expired_member_count", expired_member_count_);
    s.store_field("pending_join_request_count", pending_join_request_count_);
    s.store_field("creates_join_request", creates_join_request_);
    s.store_field("is_primary", is_primary_);
    s.store_field("is_revoked", is_revoked_);
    s.store_class_end();
  }
}

chatInviteLinkSubscriptionInfo::chatInviteLinkSubscriptionInfo()
  : pricing_()
  , can_reuse_()
  , form_id_()
{}

chatInviteLinkSubscriptionInfo::chatInviteLinkSubscriptionInfo(object_ptr<starSubscriptionPricing> &&pricing_, bool can_reuse_, int64 form_id_)
  : pricing_(std::move(pricing_))
  , can_reuse_(can_reuse_)
  , form_id_(form_id_)
{}

const std::int32_t chatInviteLinkSubscriptionInfo::ID;

void chatInviteLinkSubscriptionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkSubscriptionInfo");
    s.store_object_field("pricing", static_cast<const BaseObject *>(pricing_.get()));
    s.store_field("can_reuse", can_reuse_);
    s.store_field("form_id", form_id_);
    s.store_class_end();
  }
}

chatJoinRequest::chatJoinRequest()
  : user_id_()
  , date_()
  , bio_()
{}

chatJoinRequest::chatJoinRequest(int53 user_id_, int32 date_, string const &bio_)
  : user_id_(user_id_)
  , date_(date_)
  , bio_(bio_)
{}

const std::int32_t chatJoinRequest::ID;

void chatJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequest");
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    s.store_field("bio", bio_);
    s.store_class_end();
  }
}

chatRevenueTransactionTypeUnsupported::chatRevenueTransactionTypeUnsupported() {
}

const std::int32_t chatRevenueTransactionTypeUnsupported::ID;

void chatRevenueTransactionTypeUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactionTypeUnsupported");
    s.store_class_end();
  }
}

chatRevenueTransactionTypeSponsoredMessageEarnings::chatRevenueTransactionTypeSponsoredMessageEarnings()
  : start_date_()
  , end_date_()
{}

chatRevenueTransactionTypeSponsoredMessageEarnings::chatRevenueTransactionTypeSponsoredMessageEarnings(int32 start_date_, int32 end_date_)
  : start_date_(start_date_)
  , end_date_(end_date_)
{}

const std::int32_t chatRevenueTransactionTypeSponsoredMessageEarnings::ID;

void chatRevenueTransactionTypeSponsoredMessageEarnings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactionTypeSponsoredMessageEarnings");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_class_end();
  }
}

chatRevenueTransactionTypeSuggestedPostEarnings::chatRevenueTransactionTypeSuggestedPostEarnings()
  : user_id_()
{}

chatRevenueTransactionTypeSuggestedPostEarnings::chatRevenueTransactionTypeSuggestedPostEarnings(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t chatRevenueTransactionTypeSuggestedPostEarnings::ID;

void chatRevenueTransactionTypeSuggestedPostEarnings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactionTypeSuggestedPostEarnings");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

chatRevenueTransactionTypeFragmentWithdrawal::chatRevenueTransactionTypeFragmentWithdrawal()
  : withdrawal_date_()
  , state_()
{}

chatRevenueTransactionTypeFragmentWithdrawal::chatRevenueTransactionTypeFragmentWithdrawal(int32 withdrawal_date_, object_ptr<RevenueWithdrawalState> &&state_)
  : withdrawal_date_(withdrawal_date_)
  , state_(std::move(state_))
{}

const std::int32_t chatRevenueTransactionTypeFragmentWithdrawal::ID;

void chatRevenueTransactionTypeFragmentWithdrawal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactionTypeFragmentWithdrawal");
    s.store_field("withdrawal_date", withdrawal_date_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

chatRevenueTransactionTypeFragmentRefund::chatRevenueTransactionTypeFragmentRefund()
  : refund_date_()
{}

chatRevenueTransactionTypeFragmentRefund::chatRevenueTransactionTypeFragmentRefund(int32 refund_date_)
  : refund_date_(refund_date_)
{}

const std::int32_t chatRevenueTransactionTypeFragmentRefund::ID;

void chatRevenueTransactionTypeFragmentRefund::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactionTypeFragmentRefund");
    s.store_field("refund_date", refund_date_);
    s.store_class_end();
  }
}

chatStatisticsMessageSenderInfo::chatStatisticsMessageSenderInfo()
  : user_id_()
  , sent_message_count_()
  , average_character_count_()
{}

chatStatisticsMessageSenderInfo::chatStatisticsMessageSenderInfo(int53 user_id_, int32 sent_message_count_, int32 average_character_count_)
  : user_id_(user_id_)
  , sent_message_count_(sent_message_count_)
  , average_character_count_(average_character_count_)
{}

const std::int32_t chatStatisticsMessageSenderInfo::ID;

void chatStatisticsMessageSenderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsMessageSenderInfo");
    s.store_field("user_id", user_id_);
    s.store_field("sent_message_count", sent_message_count_);
    s.store_field("average_character_count", average_character_count_);
    s.store_class_end();
  }
}

collectibleItemTypeUsername::collectibleItemTypeUsername()
  : username_()
{}

collectibleItemTypeUsername::collectibleItemTypeUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t collectibleItemTypeUsername::ID;

void collectibleItemTypeUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "collectibleItemTypeUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

collectibleItemTypePhoneNumber::collectibleItemTypePhoneNumber()
  : phone_number_()
{}

collectibleItemTypePhoneNumber::collectibleItemTypePhoneNumber(string const &phone_number_)
  : phone_number_(phone_number_)
{}

const std::int32_t collectibleItemTypePhoneNumber::ID;

void collectibleItemTypePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "collectibleItemTypePhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

communities::communities()
  : community_ids_()
{}

communities::communities(array<int53> &&community_ids_)
  : community_ids_(std::move(community_ids_))
{}

const std::int32_t communities::ID;

void communities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities");
    { s.store_vector_begin("community_ids", community_ids_.size()); for (const auto &_value : community_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

communityAddChatRequest::communityAddChatRequest()
  : chat_id_()
  , is_hidden_()
  , sender_user_id_()
  , date_()
{}

communityAddChatRequest::communityAddChatRequest(int53 chat_id_, bool is_hidden_, int53 sender_user_id_, int32 date_)
  : chat_id_(chat_id_)
  , is_hidden_(is_hidden_)
  , sender_user_id_(sender_user_id_)
  , date_(date_)
{}

const std::int32_t communityAddChatRequest::ID;

void communityAddChatRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityAddChatRequest");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_hidden", is_hidden_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

communityChat::communityChat()
  : chat_id_()
  , can_view_history_()
  , is_hidden_()
{}

communityChat::communityChat(int53 chat_id_, bool can_view_history_, bool is_hidden_)
  : chat_id_(chat_id_)
  , can_view_history_(can_view_history_)
  , is_hidden_(is_hidden_)
{}

const std::int32_t communityChat::ID;

void communityChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("can_view_history", can_view_history_);
    s.store_field("is_hidden", is_hidden_);
    s.store_class_end();
  }
}

connectionStateWaitingForNetwork::connectionStateWaitingForNetwork() {
}

const std::int32_t connectionStateWaitingForNetwork::ID;

void connectionStateWaitingForNetwork::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateWaitingForNetwork");
    s.store_class_end();
  }
}

connectionStateConnectingToProxy::connectionStateConnectingToProxy() {
}

const std::int32_t connectionStateConnectingToProxy::ID;

void connectionStateConnectingToProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateConnectingToProxy");
    s.store_class_end();
  }
}

connectionStateConnecting::connectionStateConnecting() {
}

const std::int32_t connectionStateConnecting::ID;

void connectionStateConnecting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateConnecting");
    s.store_class_end();
  }
}

connectionStateUpdating::connectionStateUpdating() {
}

const std::int32_t connectionStateUpdating::ID;

void connectionStateUpdating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateUpdating");
    s.store_class_end();
  }
}

connectionStateReady::connectionStateReady() {
}

const std::int32_t connectionStateReady::ID;

void connectionStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateReady");
    s.store_class_end();
  }
}

countries::countries()
  : countries_()
{}

countries::countries(array<object_ptr<countryInfo>> &&countries_)
  : countries_(std::move(countries_))
{}

const std::int32_t countries::ID;

void countries::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "countries");
    { s.store_vector_begin("countries", countries_.size()); for (const auto &_value : countries_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

currencyExchangeRate::currencyExchangeRate()
  : currency_()
  , rate_()
{}

currencyExchangeRate::currencyExchangeRate(string const &currency_, double rate_)
  : currency_(currency_)
  , rate_(rate_)
{}

const std::int32_t currencyExchangeRate::ID;

void currencyExchangeRate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "currencyExchangeRate");
    s.store_field("currency", currency_);
    s.store_field("rate", rate_);
    s.store_class_end();
  }
}

currencyExchangeRates::currencyExchangeRates()
  : rates_()
{}

currencyExchangeRates::currencyExchangeRates(array<object_ptr<currencyExchangeRate>> &&rates_)
  : rates_(std::move(rates_))
{}

const std::int32_t currencyExchangeRates::ID;

void currencyExchangeRates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "currencyExchangeRates");
    { s.store_vector_begin("rates", rates_.size()); for (const auto &_value : rates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

deepLinkInfo::deepLinkInfo()
  : text_()
  , need_update_application_()
{}

deepLinkInfo::deepLinkInfo(object_ptr<formattedText> &&text_, bool need_update_application_)
  : text_(std::move(text_))
  , need_update_application_(need_update_application_)
{}

const std::int32_t deepLinkInfo::ID;

void deepLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deepLinkInfo");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("need_update_application", need_update_application_);
    s.store_class_end();
  }
}

emojiChatTheme::emojiChatTheme()
  : name_()
  , light_settings_()
  , dark_settings_()
{}

emojiChatTheme::emojiChatTheme(string const &name_, object_ptr<themeSettings> &&light_settings_, object_ptr<themeSettings> &&dark_settings_)
  : name_(name_)
  , light_settings_(std::move(light_settings_))
  , dark_settings_(std::move(dark_settings_))
{}

const std::int32_t emojiChatTheme::ID;

void emojiChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiChatTheme");
    s.store_field("name", name_);
    s.store_object_field("light_settings", static_cast<const BaseObject *>(light_settings_.get()));
    s.store_object_field("dark_settings", static_cast<const BaseObject *>(dark_settings_.get()));
    s.store_class_end();
  }
}

emojiStatusTypeCustomEmoji::emojiStatusTypeCustomEmoji()
  : custom_emoji_id_()
{}

emojiStatusTypeCustomEmoji::emojiStatusTypeCustomEmoji(int64 custom_emoji_id_)
  : custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t emojiStatusTypeCustomEmoji::ID;

void emojiStatusTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatusTypeCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

emojiStatusTypeUpgradedGift::emojiStatusTypeUpgradedGift()
  : upgraded_gift_id_()
  , gift_title_()
  , gift_name_()
  , model_custom_emoji_id_()
  , symbol_custom_emoji_id_()
  , backdrop_colors_()
{}

emojiStatusTypeUpgradedGift::emojiStatusTypeUpgradedGift(int64 upgraded_gift_id_, string const &gift_title_, string const &gift_name_, int64 model_custom_emoji_id_, int64 symbol_custom_emoji_id_, object_ptr<upgradedGiftBackdropColors> &&backdrop_colors_)
  : upgraded_gift_id_(upgraded_gift_id_)
  , gift_title_(gift_title_)
  , gift_name_(gift_name_)
  , model_custom_emoji_id_(model_custom_emoji_id_)
  , symbol_custom_emoji_id_(symbol_custom_emoji_id_)
  , backdrop_colors_(std::move(backdrop_colors_))
{}

const std::int32_t emojiStatusTypeUpgradedGift::ID;

void emojiStatusTypeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatusTypeUpgradedGift");
    s.store_field("upgraded_gift_id", upgraded_gift_id_);
    s.store_field("gift_title", gift_title_);
    s.store_field("gift_name", gift_name_);
    s.store_field("model_custom_emoji_id", model_custom_emoji_id_);
    s.store_field("symbol_custom_emoji_id", symbol_custom_emoji_id_);
    s.store_object_field("backdrop_colors", static_cast<const BaseObject *>(backdrop_colors_.get()));
    s.store_class_end();
  }
}

gift::gift()
  : id_()
  , publisher_chat_id_()
  , sticker_()
  , star_count_()
  , default_sell_star_count_()
  , upgrade_star_count_()
  , upgrade_variant_count_()
  , has_colors_()
  , is_for_birthday_()
  , is_premium_()
  , auction_info_()
  , next_send_date_()
  , user_limits_()
  , overall_limits_()
  , background_()
  , first_send_date_()
  , last_send_date_()
{}

gift::gift(int64 id_, int53 publisher_chat_id_, object_ptr<sticker> &&sticker_, int53 star_count_, int53 default_sell_star_count_, int53 upgrade_star_count_, int32 upgrade_variant_count_, bool has_colors_, bool is_for_birthday_, bool is_premium_, object_ptr<giftAuction> &&auction_info_, int32 next_send_date_, object_ptr<giftPurchaseLimits> &&user_limits_, object_ptr<giftPurchaseLimits> &&overall_limits_, object_ptr<giftBackground> &&background_, int32 first_send_date_, int32 last_send_date_)
  : id_(id_)
  , publisher_chat_id_(publisher_chat_id_)
  , sticker_(std::move(sticker_))
  , star_count_(star_count_)
  , default_sell_star_count_(default_sell_star_count_)
  , upgrade_star_count_(upgrade_star_count_)
  , upgrade_variant_count_(upgrade_variant_count_)
  , has_colors_(has_colors_)
  , is_for_birthday_(is_for_birthday_)
  , is_premium_(is_premium_)
  , auction_info_(std::move(auction_info_))
  , next_send_date_(next_send_date_)
  , user_limits_(std::move(user_limits_))
  , overall_limits_(std::move(overall_limits_))
  , background_(std::move(background_))
  , first_send_date_(first_send_date_)
  , last_send_date_(last_send_date_)
{}

const std::int32_t gift::ID;

void gift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "gift");
    s.store_field("id", id_);
    s.store_field("publisher_chat_id", publisher_chat_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("star_count", star_count_);
    s.store_field("default_sell_star_count", default_sell_star_count_);
    s.store_field("upgrade_star_count", upgrade_star_count_);
    s.store_field("upgrade_variant_count", upgrade_variant_count_);
    s.store_field("has_colors", has_colors_);
    s.store_field("is_for_birthday", is_for_birthday_);
    s.store_field("is_premium", is_premium_);
    s.store_object_field("auction_info", static_cast<const BaseObject *>(auction_info_.get()));
    s.store_field("next_send_date", next_send_date_);
    s.store_object_field("user_limits", static_cast<const BaseObject *>(user_limits_.get()));
    s.store_object_field("overall_limits", static_cast<const BaseObject *>(overall_limits_.get()));
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_field("first_send_date", first_send_date_);
    s.store_field("last_send_date", last_send_date_);
    s.store_class_end();
  }
}

giftAuction::giftAuction()
  : id_()
  , gifts_per_round_()
  , start_date_()
{}

giftAuction::giftAuction(string const &id_, int32 gifts_per_round_, int32 start_date_)
  : id_(id_)
  , gifts_per_round_(gifts_per_round_)
  , start_date_(start_date_)
{}

const std::int32_t giftAuction::ID;

void giftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftAuction");
    s.store_field("id", id_);
    s.store_field("gifts_per_round", gifts_per_round_);
    s.store_field("start_date", start_date_);
    s.store_class_end();
  }
}

giftAuctionAcquiredGifts::giftAuctionAcquiredGifts()
  : gifts_()
{}

giftAuctionAcquiredGifts::giftAuctionAcquiredGifts(array<object_ptr<giftAuctionAcquiredGift>> &&gifts_)
  : gifts_(std::move(gifts_))
{}

const std::int32_t giftAuctionAcquiredGifts::ID;

void giftAuctionAcquiredGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftAuctionAcquiredGifts");
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

giftForResale::giftForResale()
  : gift_()
  , received_gift_id_()
{}

giftForResale::giftForResale(object_ptr<upgradedGift> &&gift_, string const &received_gift_id_)
  : gift_(std::move(gift_))
  , received_gift_id_(received_gift_id_)
{}

const std::int32_t giftForResale::ID;

void giftForResale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftForResale");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

importedContact::importedContact()
  : phone_number_()
  , first_name_()
  , last_name_()
  , note_()
{}

importedContact::importedContact(string const &phone_number_, string const &first_name_, string const &last_name_, object_ptr<formattedText> &&note_)
  : phone_number_(phone_number_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , note_(std::move(note_))
{}

const std::int32_t importedContact::ID;

void importedContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importedContact");
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_object_field("note", static_cast<const BaseObject *>(note_.get()));
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeUrl::inlineKeyboardButtonTypeUrl()
  : url_()
{}

inlineKeyboardButtonTypeUrl::inlineKeyboardButtonTypeUrl(string const &url_)
  : url_(url_)
{}

const std::int32_t inlineKeyboardButtonTypeUrl::ID;

void inlineKeyboardButtonTypeUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeLoginUrl::inlineKeyboardButtonTypeLoginUrl()
  : url_()
  , id_()
  , forward_text_()
{}

inlineKeyboardButtonTypeLoginUrl::inlineKeyboardButtonTypeLoginUrl(string const &url_, int53 id_, string const &forward_text_)
  : url_(url_)
  , id_(id_)
  , forward_text_(forward_text_)
{}

const std::int32_t inlineKeyboardButtonTypeLoginUrl::ID;

void inlineKeyboardButtonTypeLoginUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeLoginUrl");
    s.store_field("url", url_);
    s.store_field("id", id_);
    s.store_field("forward_text", forward_text_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeWebApp::inlineKeyboardButtonTypeWebApp()
  : url_()
{}

inlineKeyboardButtonTypeWebApp::inlineKeyboardButtonTypeWebApp(string const &url_)
  : url_(url_)
{}

const std::int32_t inlineKeyboardButtonTypeWebApp::ID;

void inlineKeyboardButtonTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeWebApp");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeCallback::inlineKeyboardButtonTypeCallback()
  : data_()
{}

inlineKeyboardButtonTypeCallback::inlineKeyboardButtonTypeCallback(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t inlineKeyboardButtonTypeCallback::ID;

void inlineKeyboardButtonTypeCallback::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeCallback");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeCallbackWithPassword::inlineKeyboardButtonTypeCallbackWithPassword()
  : data_()
{}

inlineKeyboardButtonTypeCallbackWithPassword::inlineKeyboardButtonTypeCallbackWithPassword(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t inlineKeyboardButtonTypeCallbackWithPassword::ID;

void inlineKeyboardButtonTypeCallbackWithPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeCallbackWithPassword");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeCallbackGame::inlineKeyboardButtonTypeCallbackGame() {
}

const std::int32_t inlineKeyboardButtonTypeCallbackGame::ID;

void inlineKeyboardButtonTypeCallbackGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeCallbackGame");
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeSwitchInline::inlineKeyboardButtonTypeSwitchInline()
  : query_()
  , target_chat_()
{}

inlineKeyboardButtonTypeSwitchInline::inlineKeyboardButtonTypeSwitchInline(string const &query_, object_ptr<TargetChat> &&target_chat_)
  : query_(query_)
  , target_chat_(std::move(target_chat_))
{}

const std::int32_t inlineKeyboardButtonTypeSwitchInline::ID;

void inlineKeyboardButtonTypeSwitchInline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeSwitchInline");
    s.store_field("query", query_);
    s.store_object_field("target_chat", static_cast<const BaseObject *>(target_chat_.get()));
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeBuy::inlineKeyboardButtonTypeBuy() {
}

const std::int32_t inlineKeyboardButtonTypeBuy::ID;

void inlineKeyboardButtonTypeBuy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeBuy");
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeUser::inlineKeyboardButtonTypeUser()
  : user_id_()
{}

inlineKeyboardButtonTypeUser::inlineKeyboardButtonTypeUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t inlineKeyboardButtonTypeUser::ID;

void inlineKeyboardButtonTypeUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeCopyText::inlineKeyboardButtonTypeCopyText()
  : text_()
{}

inlineKeyboardButtonTypeCopyText::inlineKeyboardButtonTypeCopyText(string const &text_)
  : text_(text_)
{}

const std::int32_t inlineKeyboardButtonTypeCopyText::ID;

void inlineKeyboardButtonTypeCopyText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeCopyText");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeDisabled::inlineKeyboardButtonTypeDisabled() {
}

const std::int32_t inlineKeyboardButtonTypeDisabled::ID;

void inlineKeyboardButtonTypeDisabled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeDisabled");
    s.store_class_end();
  }
}

inlineQueryResultArticle::inlineQueryResultArticle()
  : id_()
  , url_()
  , title_()
  , description_()
  , thumbnail_()
{}

inlineQueryResultArticle::inlineQueryResultArticle(string const &id_, string const &url_, string const &title_, string const &description_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , url_(url_)
  , title_(title_)
  , description_(description_)
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultArticle::ID;

void inlineQueryResultArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultArticle");
    s.store_field("id", id_);
    s.store_field("url", url_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultContact::inlineQueryResultContact()
  : id_()
  , contact_()
  , thumbnail_()
{}

inlineQueryResultContact::inlineQueryResultContact(string const &id_, object_ptr<contact> &&contact_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , contact_(std::move(contact_))
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultContact::ID;

void inlineQueryResultContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultContact");
    s.store_field("id", id_);
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultLocation::inlineQueryResultLocation()
  : id_()
  , location_()
  , title_()
  , thumbnail_()
{}

inlineQueryResultLocation::inlineQueryResultLocation(string const &id_, object_ptr<location> &&location_, string const &title_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , location_(std::move(location_))
  , title_(title_)
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultLocation::ID;

void inlineQueryResultLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultLocation");
    s.store_field("id", id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("title", title_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultVenue::inlineQueryResultVenue()
  : id_()
  , venue_()
  , thumbnail_()
{}

inlineQueryResultVenue::inlineQueryResultVenue(string const &id_, object_ptr<venue> &&venue_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , venue_(std::move(venue_))
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultVenue::ID;

void inlineQueryResultVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultVenue");
    s.store_field("id", id_);
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultGame::inlineQueryResultGame()
  : id_()
  , game_()
{}

inlineQueryResultGame::inlineQueryResultGame(string const &id_, object_ptr<game> &&game_)
  : id_(id_)
  , game_(std::move(game_))
{}

const std::int32_t inlineQueryResultGame::ID;

void inlineQueryResultGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultGame");
    s.store_field("id", id_);
    s.store_object_field("game", static_cast<const BaseObject *>(game_.get()));
    s.store_class_end();
  }
}

inlineQueryResultAnimation::inlineQueryResultAnimation()
  : id_()
  , animation_()
  , title_()
{}

inlineQueryResultAnimation::inlineQueryResultAnimation(string const &id_, object_ptr<animation> &&animation_, string const &title_)
  : id_(id_)
  , animation_(std::move(animation_))
  , title_(title_)
{}

const std::int32_t inlineQueryResultAnimation::ID;

void inlineQueryResultAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultAnimation");
    s.store_field("id", id_);
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

inlineQueryResultAudio::inlineQueryResultAudio()
  : id_()
  , audio_()
{}

inlineQueryResultAudio::inlineQueryResultAudio(string const &id_, object_ptr<audio> &&audio_)
  : id_(id_)
  , audio_(std::move(audio_))
{}

const std::int32_t inlineQueryResultAudio::ID;

void inlineQueryResultAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultAudio");
    s.store_field("id", id_);
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_class_end();
  }
}

inlineQueryResultDocument::inlineQueryResultDocument()
  : id_()
  , document_()
  , title_()
  , description_()
{}

inlineQueryResultDocument::inlineQueryResultDocument(string const &id_, object_ptr<document> &&document_, string const &title_, string const &description_)
  : id_(id_)
  , document_(std::move(document_))
  , title_(title_)
  , description_(description_)
{}

const std::int32_t inlineQueryResultDocument::ID;

void inlineQueryResultDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultDocument");
    s.store_field("id", id_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

inlineQueryResultPhoto::inlineQueryResultPhoto()
  : id_()
  , photo_()
  , title_()
  , description_()
{}

inlineQueryResultPhoto::inlineQueryResultPhoto(string const &id_, object_ptr<photo> &&photo_, string const &title_, string const &description_)
  : id_(id_)
  , photo_(std::move(photo_))
  , title_(title_)
  , description_(description_)
{}

const std::int32_t inlineQueryResultPhoto::ID;

void inlineQueryResultPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultPhoto");
    s.store_field("id", id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

inlineQueryResultSticker::inlineQueryResultSticker()
  : id_()
  , sticker_()
{}

inlineQueryResultSticker::inlineQueryResultSticker(string const &id_, object_ptr<sticker> &&sticker_)
  : id_(id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t inlineQueryResultSticker::ID;

void inlineQueryResultSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultSticker");
    s.store_field("id", id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

inlineQueryResultVideo::inlineQueryResultVideo()
  : id_()
  , video_()
  , title_()
  , description_()
{}

inlineQueryResultVideo::inlineQueryResultVideo(string const &id_, object_ptr<video> &&video_, string const &title_, string const &description_)
  : id_(id_)
  , video_(std::move(video_))
  , title_(title_)
  , description_(description_)
{}

const std::int32_t inlineQueryResultVideo::ID;

void inlineQueryResultVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultVideo");
    s.store_field("id", id_);
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

inlineQueryResultVoiceNote::inlineQueryResultVoiceNote()
  : id_()
  , voice_note_()
  , title_()
{}

inlineQueryResultVoiceNote::inlineQueryResultVoiceNote(string const &id_, object_ptr<voiceNote> &&voice_note_, string const &title_)
  : id_(id_)
  , voice_note_(std::move(voice_note_))
  , title_(title_)
{}

const std::int32_t inlineQueryResultVoiceNote::ID;

void inlineQueryResultVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultVoiceNote");
    s.store_field("id", id_);
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

inputChecklistTask::inputChecklistTask()
  : id_()
  , text_()
{}

inputChecklistTask::inputChecklistTask(int32 id_, object_ptr<formattedText> &&text_)
  : id_(id_)
  , text_(std::move(text_))
{}

const std::int32_t inputChecklistTask::ID;

void inputChecklistTask::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChecklistTask");
    s.store_field("id", id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

inputDocument::inputDocument()
  : document_()
  , thumbnail_()
  , disable_content_type_detection_()
{}

inputDocument::inputDocument(object_ptr<InputFile> &&document_, object_ptr<inputThumbnail> &&thumbnail_, bool disable_content_type_detection_)
  : document_(std::move(document_))
  , thumbnail_(std::move(thumbnail_))
  , disable_content_type_detection_(disable_content_type_detection_)
{}

const std::int32_t inputDocument::ID;

void inputDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("disable_content_type_detection", disable_content_type_detection_);
    s.store_class_end();
  }
}

inputPageBlockListItem::inputPageBlockListItem()
  : blocks_()
  , has_checkbox_()
  , is_checked_()
  , value_()
  , type_()
{}

inputPageBlockListItem::inputPageBlockListItem(array<object_ptr<InputPageBlock>> &&blocks_, bool has_checkbox_, bool is_checked_, int32 value_, string const &type_)
  : blocks_(std::move(blocks_))
  , has_checkbox_(has_checkbox_)
  , is_checked_(is_checked_)
  , value_(value_)
  , type_(type_)
{}

const std::int32_t inputPageBlockListItem::ID;

void inputPageBlockListItem::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockListItem");
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("has_checkbox", has_checkbox_);
    s.store_field("is_checked", is_checked_);
    s.store_field("value", value_);
    s.store_field("type", type_);
    s.store_class_end();
  }
}

inputVideoNote::inputVideoNote()
  : video_note_()
  , thumbnail_()
  , duration_()
  , length_()
{}

inputVideoNote::inputVideoNote(object_ptr<InputFile> &&video_note_, object_ptr<inputThumbnail> &&thumbnail_, int32 duration_, int32 length_)
  : video_note_(std::move(video_note_))
  , thumbnail_(std::move(thumbnail_))
  , duration_(duration_)
  , length_(length_)
{}

const std::int32_t inputVideoNote::ID;

void inputVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

linkPreviewAlbumMediaPhoto::linkPreviewAlbumMediaPhoto()
  : photo_()
{}

linkPreviewAlbumMediaPhoto::linkPreviewAlbumMediaPhoto(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewAlbumMediaPhoto::ID;

void linkPreviewAlbumMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewAlbumMediaPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewAlbumMediaVideo::linkPreviewAlbumMediaVideo()
  : video_()
{}

linkPreviewAlbumMediaVideo::linkPreviewAlbumMediaVideo(object_ptr<video> &&video_)
  : video_(std::move(video_))
{}

const std::int32_t linkPreviewAlbumMediaVideo::ID;

void linkPreviewAlbumMediaVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewAlbumMediaVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

liveStoryDonors::liveStoryDonors()
  : total_star_count_()
  , top_donors_()
{}

liveStoryDonors::liveStoryDonors(int53 total_star_count_, array<object_ptr<paidReactor>> &&top_donors_)
  : total_star_count_(total_star_count_)
  , top_donors_(std::move(top_donors_))
{}

const std::int32_t liveStoryDonors::ID;

void liveStoryDonors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liveStoryDonors");
    s.store_field("total_star_count", total_star_count_);
    { s.store_vector_begin("top_donors", top_donors_.size()); for (const auto &_value : top_donors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

localFile::localFile()
  : path_()
  , can_be_downloaded_()
  , can_be_deleted_()
  , is_downloading_active_()
  , is_downloading_completed_()
  , download_offset_()
  , downloaded_prefix_size_()
  , downloaded_size_()
{}

localFile::localFile(string const &path_, bool can_be_downloaded_, bool can_be_deleted_, bool is_downloading_active_, bool is_downloading_completed_, int53 download_offset_, int53 downloaded_prefix_size_, int53 downloaded_size_)
  : path_(path_)
  , can_be_downloaded_(can_be_downloaded_)
  , can_be_deleted_(can_be_deleted_)
  , is_downloading_active_(is_downloading_active_)
  , is_downloading_completed_(is_downloading_completed_)
  , download_offset_(download_offset_)
  , downloaded_prefix_size_(downloaded_prefix_size_)
  , downloaded_size_(downloaded_size_)
{}

const std::int32_t localFile::ID;

void localFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "localFile");
    s.store_field("path", path_);
    s.store_field("can_be_downloaded", can_be_downloaded_);
    s.store_field("can_be_deleted", can_be_deleted_);
    s.store_field("is_downloading_active", is_downloading_active_);
    s.store_field("is_downloading_completed", is_downloading_completed_);
    s.store_field("download_offset", download_offset_);
    s.store_field("downloaded_prefix_size", downloaded_prefix_size_);
    s.store_field("downloaded_size", downloaded_size_);
    s.store_class_end();
  }
}

logVerbosityLevel::logVerbosityLevel()
  : verbosity_level_()
{}

logVerbosityLevel::logVerbosityLevel(int32 verbosity_level_)
  : verbosity_level_(verbosity_level_)
{}

const std::int32_t logVerbosityLevel::ID;

void logVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logVerbosityLevel");
    s.store_field("verbosity_level", verbosity_level_);
    s.store_class_end();
  }
}

maskPointForehead::maskPointForehead() {
}

const std::int32_t maskPointForehead::ID;

void maskPointForehead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointForehead");
    s.store_class_end();
  }
}

maskPointEyes::maskPointEyes() {
}

const std::int32_t maskPointEyes::ID;

void maskPointEyes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointEyes");
    s.store_class_end();
  }
}

maskPointMouth::maskPointMouth() {
}

const std::int32_t maskPointMouth::ID;

void maskPointMouth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointMouth");
    s.store_class_end();
  }
}

maskPointChin::maskPointChin() {
}

const std::int32_t maskPointChin::ID;

void maskPointChin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointChin");
    s.store_class_end();
  }
}

messageLink::messageLink()
  : link_()
  , is_public_()
{}

messageLink::messageLink(string const &link_, bool is_public_)
  : link_(link_)
  , is_public_(is_public_)
{}

const std::int32_t messageLink::ID;

void messageLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageLink");
    s.store_field("link", link_);
    s.store_field("is_public", is_public_);
    s.store_class_end();
  }
}

messageProperties::messageProperties()
  : can_add_offer_()
  , can_add_tasks_()
  , can_be_approved_()
  , can_be_copied_()
  , can_be_copied_to_secret_chat_()
  , can_be_declined_()
  , can_be_deleted_only_for_self_()
  , can_be_deleted_for_all_users_()
  , can_be_edited_()
  , can_be_forwarded_()
  , can_be_paid_()
  , can_be_pinned_()
  , can_be_replied_()
  , can_be_replied_in_another_chat_()
  , can_be_saved_()
  , can_be_shared_in_story_()
  , can_delete_reactions_()
  , can_edit_media_()
  , can_edit_scheduling_state_()
  , can_edit_suggested_post_info_()
  , can_get_author_()
  , can_get_embedding_code_()
  , can_get_link_()
  , can_get_media_timestamp_links_()
  , can_get_message_thread_()
  , can_get_poll_vote_statistics_()
  , can_get_read_date_()
  , can_get_statistics_()
  , can_get_video_advertisements_()
  , can_get_viewers_()
  , can_mark_tasks_as_done_()
  , can_recognize_speech_()
  , can_report_chat_()
  , can_report_reactions_()
  , can_report_supergroup_spam_()
  , can_set_fact_check_()
  , custom_emoji_ids_()
  , has_protected_content_by_current_user_()
  , has_protected_content_by_other_user_()
  , need_show_statistics_()
{}

messageProperties::messageProperties(bool can_add_offer_, bool can_add_tasks_, bool can_be_approved_, bool can_be_copied_, bool can_be_copied_to_secret_chat_, bool can_be_declined_, bool can_be_deleted_only_for_self_, bool can_be_deleted_for_all_users_, bool can_be_edited_, bool can_be_forwarded_, bool can_be_paid_, bool can_be_pinned_, bool can_be_replied_, bool can_be_replied_in_another_chat_, bool can_be_saved_, bool can_be_shared_in_story_, bool can_delete_reactions_, bool can_edit_media_, bool can_edit_scheduling_state_, bool can_edit_suggested_post_info_, bool can_get_author_, bool can_get_embedding_code_, bool can_get_link_, bool can_get_media_timestamp_links_, bool can_get_message_thread_, bool can_get_poll_vote_statistics_, bool can_get_read_date_, bool can_get_statistics_, bool can_get_video_advertisements_, bool can_get_viewers_, bool can_mark_tasks_as_done_, bool can_recognize_speech_, bool can_report_chat_, bool can_report_reactions_, bool can_report_supergroup_spam_, bool can_set_fact_check_, array<int64> &&custom_emoji_ids_, bool has_protected_content_by_current_user_, bool has_protected_content_by_other_user_, bool need_show_statistics_)
  : can_add_offer_(can_add_offer_)
  , can_add_tasks_(can_add_tasks_)
  , can_be_approved_(can_be_approved_)
  , can_be_copied_(can_be_copied_)
  , can_be_copied_to_secret_chat_(can_be_copied_to_secret_chat_)
  , can_be_declined_(can_be_declined_)
  , can_be_deleted_only_for_self_(can_be_deleted_only_for_self_)
  , can_be_deleted_for_all_users_(can_be_deleted_for_all_users_)
  , can_be_edited_(can_be_edited_)
  , can_be_forwarded_(can_be_forwarded_)
  , can_be_paid_(can_be_paid_)
  , can_be_pinned_(can_be_pinned_)
  , can_be_replied_(can_be_replied_)
  , can_be_replied_in_another_chat_(can_be_replied_in_another_chat_)
  , can_be_saved_(can_be_saved_)
  , can_be_shared_in_story_(can_be_shared_in_story_)
  , can_delete_reactions_(can_delete_reactions_)
  , can_edit_media_(can_edit_media_)
  , can_edit_scheduling_state_(can_edit_scheduling_state_)
  , can_edit_suggested_post_info_(can_edit_suggested_post_info_)
  , can_get_author_(can_get_author_)
  , can_get_embedding_code_(can_get_embedding_code_)
  , can_get_link_(can_get_link_)
  , can_get_media_timestamp_links_(can_get_media_timestamp_links_)
  , can_get_message_thread_(can_get_message_thread_)
  , can_get_poll_vote_statistics_(can_get_poll_vote_statistics_)
  , can_get_read_date_(can_get_read_date_)
  , can_get_statistics_(can_get_statistics_)
  , can_get_video_advertisements_(can_get_video_advertisements_)
  , can_get_viewers_(can_get_viewers_)
  , can_mark_tasks_as_done_(can_mark_tasks_as_done_)
  , can_recognize_speech_(can_recognize_speech_)
  , can_report_chat_(can_report_chat_)
  , can_report_reactions_(can_report_reactions_)
  , can_report_supergroup_spam_(can_report_supergroup_spam_)
  , can_set_fact_check_(can_set_fact_check_)
  , custom_emoji_ids_(std::move(custom_emoji_ids_))
  , has_protected_content_by_current_user_(has_protected_content_by_current_user_)
  , has_protected_content_by_other_user_(has_protected_content_by_other_user_)
  , need_show_statistics_(need_show_statistics_)
{}

const std::int32_t messageProperties::ID;

void messageProperties::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageProperties");
    s.store_field("can_add_offer", can_add_offer_);
    s.store_field("can_add_tasks", can_add_tasks_);
    s.store_field("can_be_approved", can_be_approved_);
    s.store_field("can_be_copied", can_be_copied_);
    s.store_field("can_be_copied_to_secret_chat", can_be_copied_to_secret_chat_);
    s.store_field("can_be_declined", can_be_declined_);
    s.store_field("can_be_deleted_only_for_self", can_be_deleted_only_for_self_);
    s.store_field("can_be_deleted_for_all_users", can_be_deleted_for_all_users_);
    s.store_field("can_be_edited", can_be_edited_);
    s.store_field("can_be_forwarded", can_be_forwarded_);
    s.store_field("can_be_paid", can_be_paid_);
    s.store_field("can_be_pinned", can_be_pinned_);
    s.store_field("can_be_replied", can_be_replied_);
    s.store_field("can_be_replied_in_another_chat", can_be_replied_in_another_chat_);
    s.store_field("can_be_saved", can_be_saved_);
    s.store_field("can_be_shared_in_story", can_be_shared_in_story_);
    s.store_field("can_delete_reactions", can_delete_reactions_);
    s.store_field("can_edit_media", can_edit_media_);
    s.store_field("can_edit_scheduling_state", can_edit_scheduling_state_);
    s.store_field("can_edit_suggested_post_info", can_edit_suggested_post_info_);
    s.store_field("can_get_author", can_get_author_);
    s.store_field("can_get_embedding_code", can_get_embedding_code_);
    s.store_field("can_get_link", can_get_link_);
    s.store_field("can_get_media_timestamp_links", can_get_media_timestamp_links_);
    s.store_field("can_get_message_thread", can_get_message_thread_);
    s.store_field("can_get_poll_vote_statistics", can_get_poll_vote_statistics_);
    s.store_field("can_get_read_date", can_get_read_date_);
    s.store_field("can_get_statistics", can_get_statistics_);
    s.store_field("can_get_video_advertisements", can_get_video_advertisements_);
    s.store_field("can_get_viewers", can_get_viewers_);
    s.store_field("can_mark_tasks_as_done", can_mark_tasks_as_done_);
    s.store_field("can_recognize_speech", can_recognize_speech_);
    s.store_field("can_report_chat", can_report_chat_);
    s.store_field("can_report_reactions", can_report_reactions_);
    s.store_field("can_report_supergroup_spam", can_report_supergroup_spam_);
    s.store_field("can_set_fact_check", can_set_fact_check_);
    { s.store_vector_begin("custom_emoji_ids", custom_emoji_ids_.size()); for (const auto &_value : custom_emoji_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("has_protected_content_by_current_user", has_protected_content_by_current_user_);
    s.store_field("has_protected_content_by_other_user", has_protected_content_by_other_user_);
    s.store_field("need_show_statistics", need_show_statistics_);
    s.store_class_end();
  }
}

messageReplyInfo::messageReplyInfo()
  : reply_count_()
  , recent_replier_ids_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , last_message_id_()
{}

messageReplyInfo::messageReplyInfo(int32 reply_count_, array<object_ptr<MessageSender>> &&recent_replier_ids_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int53 last_message_id_)
  : reply_count_(reply_count_)
  , recent_replier_ids_(std::move(recent_replier_ids_))
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , last_message_id_(last_message_id_)
{}

const std::int32_t messageReplyInfo::ID;

void messageReplyInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplyInfo");
    s.store_field("reply_count", reply_count_);
    { s.store_vector_begin("recent_replier_ids", recent_replier_ids_.size()); for (const auto &_value : recent_replier_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_field("last_message_id", last_message_id_);
    s.store_class_end();
  }
}

messageSenders::messageSenders()
  : total_count_()
  , senders_()
{}

messageSenders::messageSenders(int32 total_count_, array<object_ptr<MessageSender>> &&senders_)
  : total_count_(total_count_)
  , senders_(std::move(senders_))
{}

const std::int32_t messageSenders::ID;

void messageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSenders");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("senders", senders_.size()); for (const auto &_value : senders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageThreadInfo::messageThreadInfo()
  : chat_id_()
  , message_thread_id_()
  , reply_info_()
  , unread_message_count_()
  , messages_()
  , draft_message_()
{}

messageThreadInfo::messageThreadInfo(int53 chat_id_, int53 message_thread_id_, object_ptr<messageReplyInfo> &&reply_info_, int32 unread_message_count_, array<object_ptr<message>> &&messages_, object_ptr<draftMessage> &&draft_message_)
  : chat_id_(chat_id_)
  , message_thread_id_(message_thread_id_)
  , reply_info_(std::move(reply_info_))
  , unread_message_count_(unread_message_count_)
  , messages_(std::move(messages_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t messageThreadInfo::ID;

void messageThreadInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageThreadInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_thread_id", message_thread_id_);
    s.store_object_field("reply_info", static_cast<const BaseObject *>(reply_info_.get()));
    s.store_field("unread_message_count", unread_message_count_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

ok::ok() {
}

const std::int32_t ok::ID;

void ok::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ok");
    s.store_class_end();
  }
}

onRampPaymentQuote::onRampPaymentQuote()
  : payment_method_()
  , expiration_date_()
  , base_currency_amount_()
  , cryptocurrency_amount_()
  , cryptocurrency_price_()
  , fee_amount_()
  , extra_fee_amount_()
  , network_fee_amount_()
  , total_amount_()
{}

onRampPaymentQuote::onRampPaymentQuote(string const &payment_method_, int32 expiration_date_, string const &base_currency_amount_, string const &cryptocurrency_amount_, string const &cryptocurrency_price_, string const &fee_amount_, string const &extra_fee_amount_, string const &network_fee_amount_, string const &total_amount_)
  : payment_method_(payment_method_)
  , expiration_date_(expiration_date_)
  , base_currency_amount_(base_currency_amount_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , cryptocurrency_price_(cryptocurrency_price_)
  , fee_amount_(fee_amount_)
  , extra_fee_amount_(extra_fee_amount_)
  , network_fee_amount_(network_fee_amount_)
  , total_amount_(total_amount_)
{}

const std::int32_t onRampPaymentQuote::ID;

void onRampPaymentQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onRampPaymentQuote");
    s.store_field("payment_method", payment_method_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("base_currency_amount", base_currency_amount_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_field("cryptocurrency_price", cryptocurrency_price_);
    s.store_field("fee_amount", fee_amount_);
    s.store_field("extra_fee_amount", extra_fee_amount_);
    s.store_field("network_fee_amount", network_fee_amount_);
    s.store_field("total_amount", total_amount_);
    s.store_class_end();
  }
}

passportElementErrorSourceUnspecified::passportElementErrorSourceUnspecified() {
}

const std::int32_t passportElementErrorSourceUnspecified::ID;

void passportElementErrorSourceUnspecified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceUnspecified");
    s.store_class_end();
  }
}

passportElementErrorSourceDataField::passportElementErrorSourceDataField()
  : field_name_()
{}

passportElementErrorSourceDataField::passportElementErrorSourceDataField(string const &field_name_)
  : field_name_(field_name_)
{}

const std::int32_t passportElementErrorSourceDataField::ID;

void passportElementErrorSourceDataField::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceDataField");
    s.store_field("field_name", field_name_);
    s.store_class_end();
  }
}

passportElementErrorSourceFrontSide::passportElementErrorSourceFrontSide() {
}

const std::int32_t passportElementErrorSourceFrontSide::ID;

void passportElementErrorSourceFrontSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceFrontSide");
    s.store_class_end();
  }
}

passportElementErrorSourceReverseSide::passportElementErrorSourceReverseSide() {
}

const std::int32_t passportElementErrorSourceReverseSide::ID;

void passportElementErrorSourceReverseSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceReverseSide");
    s.store_class_end();
  }
}

passportElementErrorSourceSelfie::passportElementErrorSourceSelfie() {
}

const std::int32_t passportElementErrorSourceSelfie::ID;

void passportElementErrorSourceSelfie::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceSelfie");
    s.store_class_end();
  }
}

passportElementErrorSourceTranslationFile::passportElementErrorSourceTranslationFile()
  : file_index_()
{}

passportElementErrorSourceTranslationFile::passportElementErrorSourceTranslationFile(int32 file_index_)
  : file_index_(file_index_)
{}

const std::int32_t passportElementErrorSourceTranslationFile::ID;

void passportElementErrorSourceTranslationFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceTranslationFile");
    s.store_field("file_index", file_index_);
    s.store_class_end();
  }
}

passportElementErrorSourceTranslationFiles::passportElementErrorSourceTranslationFiles() {
}

const std::int32_t passportElementErrorSourceTranslationFiles::ID;

void passportElementErrorSourceTranslationFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceTranslationFiles");
    s.store_class_end();
  }
}

passportElementErrorSourceFile::passportElementErrorSourceFile()
  : file_index_()
{}

passportElementErrorSourceFile::passportElementErrorSourceFile(int32 file_index_)
  : file_index_(file_index_)
{}

const std::int32_t passportElementErrorSourceFile::ID;

void passportElementErrorSourceFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceFile");
    s.store_field("file_index", file_index_);
    s.store_class_end();
  }
}

passportElementErrorSourceFiles::passportElementErrorSourceFiles() {
}

const std::int32_t passportElementErrorSourceFiles::ID;

void passportElementErrorSourceFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceFiles");
    s.store_class_end();
  }
}

paymentFormTypeRegular::paymentFormTypeRegular()
  : invoice_()
  , payment_provider_user_id_()
  , payment_provider_()
  , additional_payment_options_()
  , saved_order_info_()
  , saved_credentials_()
  , can_save_credentials_()
  , need_password_()
{}

paymentFormTypeRegular::paymentFormTypeRegular(object_ptr<invoice> &&invoice_, int53 payment_provider_user_id_, object_ptr<PaymentProvider> &&payment_provider_, array<object_ptr<paymentOption>> &&additional_payment_options_, object_ptr<orderInfo> &&saved_order_info_, array<object_ptr<savedCredentials>> &&saved_credentials_, bool can_save_credentials_, bool need_password_)
  : invoice_(std::move(invoice_))
  , payment_provider_user_id_(payment_provider_user_id_)
  , payment_provider_(std::move(payment_provider_))
  , additional_payment_options_(std::move(additional_payment_options_))
  , saved_order_info_(std::move(saved_order_info_))
  , saved_credentials_(std::move(saved_credentials_))
  , can_save_credentials_(can_save_credentials_)
  , need_password_(need_password_)
{}

const std::int32_t paymentFormTypeRegular::ID;

void paymentFormTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentFormTypeRegular");
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_field("payment_provider_user_id", payment_provider_user_id_);
    s.store_object_field("payment_provider", static_cast<const BaseObject *>(payment_provider_.get()));
    { s.store_vector_begin("additional_payment_options", additional_payment_options_.size()); for (const auto &_value : additional_payment_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("saved_order_info", static_cast<const BaseObject *>(saved_order_info_.get()));
    { s.store_vector_begin("saved_credentials", saved_credentials_.size()); for (const auto &_value : saved_credentials_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("can_save_credentials", can_save_credentials_);
    s.store_field("need_password", need_password_);
    s.store_class_end();
  }
}

paymentFormTypeStars::paymentFormTypeStars()
  : star_count_()
{}

paymentFormTypeStars::paymentFormTypeStars(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t paymentFormTypeStars::ID;

void paymentFormTypeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentFormTypeStars");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

paymentFormTypeStarSubscription::paymentFormTypeStarSubscription()
  : pricing_()
{}

paymentFormTypeStarSubscription::paymentFormTypeStarSubscription(object_ptr<starSubscriptionPricing> &&pricing_)
  : pricing_(std::move(pricing_))
{}

const std::int32_t paymentFormTypeStarSubscription::ID;

void paymentFormTypeStarSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentFormTypeStarSubscription");
    s.store_object_field("pricing", static_cast<const BaseObject *>(pricing_.get()));
    s.store_class_end();
  }
}

paymentOption::paymentOption()
  : title_()
  , url_()
{}

paymentOption::paymentOption(string const &title_, string const &url_)
  : title_(title_)
  , url_(url_)
{}

const std::int32_t paymentOption::ID;

void paymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentOption");
    s.store_field("title", title_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

poll::poll()
  : id_()
  , question_()
  , options_()
  , total_voter_count_()
  , recent_voter_ids_()
  , can_get_voters_()
  , can_see_results_()
  , is_anonymous_()
  , allows_multiple_answers_()
  , allows_revoting_()
  , members_only_()
  , country_codes_()
  , option_order_()
  , type_()
  , open_period_()
  , close_date_()
  , is_closed_()
  , vote_restriction_reason_()
{}

poll::poll(int64 id_, object_ptr<formattedText> &&question_, array<object_ptr<pollOption>> &&options_, int32 total_voter_count_, array<object_ptr<MessageSender>> &&recent_voter_ids_, bool can_get_voters_, bool can_see_results_, bool is_anonymous_, bool allows_multiple_answers_, bool allows_revoting_, bool members_only_, array<string> &&country_codes_, array<int32> &&option_order_, object_ptr<PollType> &&type_, int32 open_period_, int32 close_date_, bool is_closed_, object_ptr<PollVoteRestrictionReason> &&vote_restriction_reason_)
  : id_(id_)
  , question_(std::move(question_))
  , options_(std::move(options_))
  , total_voter_count_(total_voter_count_)
  , recent_voter_ids_(std::move(recent_voter_ids_))
  , can_get_voters_(can_get_voters_)
  , can_see_results_(can_see_results_)
  , is_anonymous_(is_anonymous_)
  , allows_multiple_answers_(allows_multiple_answers_)
  , allows_revoting_(allows_revoting_)
  , members_only_(members_only_)
  , country_codes_(std::move(country_codes_))
  , option_order_(std::move(option_order_))
  , type_(std::move(type_))
  , open_period_(open_period_)
  , close_date_(close_date_)
  , is_closed_(is_closed_)
  , vote_restriction_reason_(std::move(vote_restriction_reason_))
{}

const std::int32_t poll::ID;

void poll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "poll");
    s.store_field("id", id_);
    s.store_object_field("question", static_cast<const BaseObject *>(question_.get()));
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("total_voter_count", total_voter_count_);
    { s.store_vector_begin("recent_voter_ids", recent_voter_ids_.size()); for (const auto &_value : recent_voter_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("can_get_voters", can_get_voters_);
    s.store_field("can_see_results", can_see_results_);
    s.store_field("is_anonymous", is_anonymous_);
    s.store_field("allows_multiple_answers", allows_multiple_answers_);
    s.store_field("allows_revoting", allows_revoting_);
    s.store_field("members_only", members_only_);
    { s.store_vector_begin("country_codes", country_codes_.size()); for (const auto &_value : country_codes_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("option_order", option_order_.size()); for (const auto &_value : option_order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("open_period", open_period_);
    s.store_field("close_date", close_date_);
    s.store_field("is_closed", is_closed_);
    s.store_object_field("vote_restriction_reason", static_cast<const BaseObject *>(vote_restriction_reason_.get()));
    s.store_class_end();
  }
}

pollOptionProperties::pollOptionProperties()
  : can_be_deleted_()
  , can_be_replied_()
  , can_be_replied_in_another_chat_()
  , can_get_link_()
{}

pollOptionProperties::pollOptionProperties(bool can_be_deleted_, bool can_be_replied_, bool can_be_replied_in_another_chat_, bool can_get_link_)
  : can_be_deleted_(can_be_deleted_)
  , can_be_replied_(can_be_replied_)
  , can_be_replied_in_another_chat_(can_be_replied_in_another_chat_)
  , can_get_link_(can_get_link_)
{}

const std::int32_t pollOptionProperties::ID;

void pollOptionProperties::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollOptionProperties");
    s.store_field("can_be_deleted", can_be_deleted_);
    s.store_field("can_be_replied", can_be_replied_);
    s.store_field("can_be_replied_in_another_chat", can_be_replied_in_another_chat_);
    s.store_field("can_get_link", can_get_link_);
    s.store_class_end();
  }
}

premiumStoryFeaturePriorityOrder::premiumStoryFeaturePriorityOrder() {
}

const std::int32_t premiumStoryFeaturePriorityOrder::ID;

void premiumStoryFeaturePriorityOrder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeaturePriorityOrder");
    s.store_class_end();
  }
}

premiumStoryFeatureStealthMode::premiumStoryFeatureStealthMode() {
}

const std::int32_t premiumStoryFeatureStealthMode::ID;

void premiumStoryFeatureStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeatureStealthMode");
    s.store_class_end();
  }
}

premiumStoryFeaturePermanentViewsHistory::premiumStoryFeaturePermanentViewsHistory() {
}

const std::int32_t premiumStoryFeaturePermanentViewsHistory::ID;

void premiumStoryFeaturePermanentViewsHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeaturePermanentViewsHistory");
    s.store_class_end();
  }
}

premiumStoryFeatureCustomExpirationDuration::premiumStoryFeatureCustomExpirationDuration() {
}

const std::int32_t premiumStoryFeatureCustomExpirationDuration::ID;

void premiumStoryFeatureCustomExpirationDuration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeatureCustomExpirationDuration");
    s.store_class_end();
  }
}

premiumStoryFeatureSaveStories::premiumStoryFeatureSaveStories() {
}

const std::int32_t premiumStoryFeatureSaveStories::ID;

void premiumStoryFeatureSaveStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeatureSaveStories");
    s.store_class_end();
  }
}

premiumStoryFeatureLinksAndFormatting::premiumStoryFeatureLinksAndFormatting() {
}

const std::int32_t premiumStoryFeatureLinksAndFormatting::ID;

void premiumStoryFeatureLinksAndFormatting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeatureLinksAndFormatting");
    s.store_class_end();
  }
}

premiumStoryFeatureVideoQuality::premiumStoryFeatureVideoQuality() {
}

const std::int32_t premiumStoryFeatureVideoQuality::ID;

void premiumStoryFeatureVideoQuality::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeatureVideoQuality");
    s.store_class_end();
  }
}

profileAccentColors::profileAccentColors()
  : palette_colors_()
  , background_colors_()
  , story_colors_()
{}

profileAccentColors::profileAccentColors(array<int32> &&palette_colors_, array<int32> &&background_colors_, array<int32> &&story_colors_)
  : palette_colors_(std::move(palette_colors_))
  , background_colors_(std::move(background_colors_))
  , story_colors_(std::move(story_colors_))
{}

const std::int32_t profileAccentColors::ID;

void profileAccentColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileAccentColors");
    { s.store_vector_begin("palette_colors", palette_colors_.size()); for (const auto &_value : palette_colors_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("background_colors", background_colors_.size()); for (const auto &_value : background_colors_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("story_colors", story_colors_.size()); for (const auto &_value : story_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

profileShareThemeEmoji::profileShareThemeEmoji()
  : emojis_()
  , use_default_background_()
  , background_backdrop_id_()
{}

profileShareThemeEmoji::profileShareThemeEmoji(array<object_ptr<EmojiType>> &&emojis_, bool use_default_background_, int32 background_backdrop_id_)
  : emojis_(std::move(emojis_))
  , use_default_background_(use_default_background_)
  , background_backdrop_id_(background_backdrop_id_)
{}

const std::int32_t profileShareThemeEmoji::ID;

void profileShareThemeEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileShareThemeEmoji");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("use_default_background", use_default_background_);
    s.store_field("background_backdrop_id", background_backdrop_id_);
    s.store_class_end();
  }
}

profileShareThemeUpgradedGift::profileShareThemeUpgradedGift()
  : gift_()
{}

profileShareThemeUpgradedGift::profileShareThemeUpgradedGift(object_ptr<upgradedGift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t profileShareThemeUpgradedGift::ID;

void profileShareThemeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileShareThemeUpgradedGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

quickReplyMessage::quickReplyMessage()
  : id_()
  , sending_state_()
  , can_be_edited_()
  , reply_to_message_id_()
  , via_bot_user_id_()
  , media_album_id_()
  , content_()
  , reply_markup_()
{}

quickReplyMessage::quickReplyMessage(int53 id_, object_ptr<MessageSendingState> &&sending_state_, bool can_be_edited_, int53 reply_to_message_id_, int53 via_bot_user_id_, int64 media_album_id_, object_ptr<MessageContent> &&content_, object_ptr<ReplyMarkup> &&reply_markup_)
  : id_(id_)
  , sending_state_(std::move(sending_state_))
  , can_be_edited_(can_be_edited_)
  , reply_to_message_id_(reply_to_message_id_)
  , via_bot_user_id_(via_bot_user_id_)
  , media_album_id_(media_album_id_)
  , content_(std::move(content_))
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t quickReplyMessage::ID;

void quickReplyMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "quickReplyMessage");
    s.store_field("id", id_);
    s.store_object_field("sending_state", static_cast<const BaseObject *>(sending_state_.get()));
    s.store_field("can_be_edited", can_be_edited_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_field("via_bot_user_id", via_bot_user_id_);
    s.store_field("media_album_id", media_album_id_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

recommendedChatFolders::recommendedChatFolders()
  : chat_folders_()
{}

recommendedChatFolders::recommendedChatFolders(array<object_ptr<recommendedChatFolder>> &&chat_folders_)
  : chat_folders_(std::move(chat_folders_))
{}

const std::int32_t recommendedChatFolders::ID;

void recommendedChatFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recommendedChatFolders");
    { s.store_vector_begin("chat_folders", chat_folders_.size()); for (const auto &_value : chat_folders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportSponsoredResultOk::reportSponsoredResultOk() {
}

const std::int32_t reportSponsoredResultOk::ID;

void reportSponsoredResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredResultOk");
    s.store_class_end();
  }
}

reportSponsoredResultFailed::reportSponsoredResultFailed() {
}

const std::int32_t reportSponsoredResultFailed::ID;

void reportSponsoredResultFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredResultFailed");
    s.store_class_end();
  }
}

reportSponsoredResultOptionRequired::reportSponsoredResultOptionRequired()
  : title_()
  , options_()
{}

reportSponsoredResultOptionRequired::reportSponsoredResultOptionRequired(string const &title_, array<object_ptr<reportOption>> &&options_)
  : title_(title_)
  , options_(std::move(options_))
{}

const std::int32_t reportSponsoredResultOptionRequired::ID;

void reportSponsoredResultOptionRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredResultOptionRequired");
    s.store_field("title", title_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportSponsoredResultAdsHidden::reportSponsoredResultAdsHidden() {
}

const std::int32_t reportSponsoredResultAdsHidden::ID;

void reportSponsoredResultAdsHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredResultAdsHidden");
    s.store_class_end();
  }
}

reportSponsoredResultPremiumRequired::reportSponsoredResultPremiumRequired() {
}

const std::int32_t reportSponsoredResultPremiumRequired::ID;

void reportSponsoredResultPremiumRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredResultPremiumRequired");
    s.store_class_end();
  }
}

rtmpUrl::rtmpUrl()
  : url_()
  , stream_key_()
{}

rtmpUrl::rtmpUrl(string const &url_, string const &stream_key_)
  : url_(url_)
  , stream_key_(stream_key_)
{}

const std::int32_t rtmpUrl::ID;

void rtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "rtmpUrl");
    s.store_field("url", url_);
    s.store_field("stream_key", "[REDACTED]");
    s.store_class_end();
  }
}

sharedUser::sharedUser()
  : user_id_()
  , first_name_()
  , last_name_()
  , username_()
  , photo_()
{}

sharedUser::sharedUser(int53 user_id_, string const &first_name_, string const &last_name_, string const &username_, object_ptr<photo> &&photo_)
  : user_id_(user_id_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , username_(username_)
  , photo_(std::move(photo_))
{}

const std::int32_t sharedUser::ID;

void sharedUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sharedUser");
    s.store_field("user_id", user_id_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("username", username_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

starPaymentOption::starPaymentOption()
  : currency_()
  , amount_()
  , star_count_()
  , store_product_id_()
  , is_additional_()
{}

starPaymentOption::starPaymentOption(string const &currency_, int53 amount_, int53 star_count_, string const &store_product_id_, bool is_additional_)
  : currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
  , store_product_id_(store_product_id_)
  , is_additional_(is_additional_)
{}

const std::int32_t starPaymentOption::ID;

void starPaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starPaymentOption");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_field("store_product_id", store_product_id_);
    s.store_field("is_additional", is_additional_);
    s.store_class_end();
  }
}

starSubscription::starSubscription()
  : id_()
  , chat_id_()
  , expiration_date_()
  , is_canceled_()
  , is_expiring_()
  , pricing_()
  , type_()
{}

starSubscription::starSubscription(string const &id_, int53 chat_id_, int32 expiration_date_, bool is_canceled_, bool is_expiring_, object_ptr<starSubscriptionPricing> &&pricing_, object_ptr<StarSubscriptionType> &&type_)
  : id_(id_)
  , chat_id_(chat_id_)
  , expiration_date_(expiration_date_)
  , is_canceled_(is_canceled_)
  , is_expiring_(is_expiring_)
  , pricing_(std::move(pricing_))
  , type_(std::move(type_))
{}

const std::int32_t starSubscription::ID;

void starSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starSubscription");
    s.store_field("id", id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("is_canceled", is_canceled_);
    s.store_field("is_expiring", is_expiring_);
    s.store_object_field("pricing", static_cast<const BaseObject *>(pricing_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

starTransactions::starTransactions()
  : star_amount_()
  , transactions_()
  , next_offset_()
{}

starTransactions::starTransactions(object_ptr<starAmount> &&star_amount_, array<object_ptr<starTransaction>> &&transactions_, string const &next_offset_)
  : star_amount_(std::move(star_amount_))
  , transactions_(std::move(transactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t starTransactions::ID;

void starTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactions");
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    { s.store_vector_begin("transactions", transactions_.size()); for (const auto &_value : transactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

stickerSetInfo::stickerSetInfo()
  : id_()
  , title_()
  , name_()
  , thumbnail_()
  , thumbnail_outline_()
  , is_owned_()
  , is_installed_()
  , is_archived_()
  , is_official_()
  , sticker_type_()
  , needs_repainting_()
  , is_allowed_as_chat_emoji_status_()
  , is_viewed_()
  , size_()
  , covers_()
{}

stickerSetInfo::stickerSetInfo(int64 id_, string const &title_, string const &name_, object_ptr<thumbnail> &&thumbnail_, object_ptr<outline> &&thumbnail_outline_, bool is_owned_, bool is_installed_, bool is_archived_, bool is_official_, object_ptr<StickerType> &&sticker_type_, bool needs_repainting_, bool is_allowed_as_chat_emoji_status_, bool is_viewed_, int32 size_, array<object_ptr<sticker>> &&covers_)
  : id_(id_)
  , title_(title_)
  , name_(name_)
  , thumbnail_(std::move(thumbnail_))
  , thumbnail_outline_(std::move(thumbnail_outline_))
  , is_owned_(is_owned_)
  , is_installed_(is_installed_)
  , is_archived_(is_archived_)
  , is_official_(is_official_)
  , sticker_type_(std::move(sticker_type_))
  , needs_repainting_(needs_repainting_)
  , is_allowed_as_chat_emoji_status_(is_allowed_as_chat_emoji_status_)
  , is_viewed_(is_viewed_)
  , size_(size_)
  , covers_(std::move(covers_))
{}

const std::int32_t stickerSetInfo::ID;

void stickerSetInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSetInfo");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("name", name_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("thumbnail_outline", static_cast<const BaseObject *>(thumbnail_outline_.get()));
    s.store_field("is_owned", is_owned_);
    s.store_field("is_installed", is_installed_);
    s.store_field("is_archived", is_archived_);
    s.store_field("is_official", is_official_);
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("needs_repainting", needs_repainting_);
    s.store_field("is_allowed_as_chat_emoji_status", is_allowed_as_chat_emoji_status_);
    s.store_field("is_viewed", is_viewed_);
    s.store_field("size", size_);
    { s.store_vector_begin("covers", covers_.size()); for (const auto &_value : covers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyInteraction::storyInteraction()
  : actor_id_()
  , interaction_date_()
  , block_list_()
  , type_()
{}

storyInteraction::storyInteraction(object_ptr<MessageSender> &&actor_id_, int32 interaction_date_, object_ptr<BlockList> &&block_list_, object_ptr<StoryInteractionType> &&type_)
  : actor_id_(std::move(actor_id_))
  , interaction_date_(interaction_date_)
  , block_list_(std::move(block_list_))
  , type_(std::move(type_))
{}

const std::int32_t storyInteraction::ID;

void storyInteraction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteraction");
    s.store_object_field("actor_id", static_cast<const BaseObject *>(actor_id_.get()));
    s.store_field("interaction_date", interaction_date_);
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

storyInteractionTypeView::storyInteractionTypeView()
  : chosen_reaction_type_()
{}

storyInteractionTypeView::storyInteractionTypeView(object_ptr<ReactionType> &&chosen_reaction_type_)
  : chosen_reaction_type_(std::move(chosen_reaction_type_))
{}

const std::int32_t storyInteractionTypeView::ID;

void storyInteractionTypeView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteractionTypeView");
    s.store_object_field("chosen_reaction_type", static_cast<const BaseObject *>(chosen_reaction_type_.get()));
    s.store_class_end();
  }
}

storyInteractionTypeForward::storyInteractionTypeForward()
  : message_()
{}

storyInteractionTypeForward::storyInteractionTypeForward(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t storyInteractionTypeForward::ID;

void storyInteractionTypeForward::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteractionTypeForward");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

storyInteractionTypeRepost::storyInteractionTypeRepost()
  : story_()
{}

storyInteractionTypeRepost::storyInteractionTypeRepost(object_ptr<story> &&story_)
  : story_(std::move(story_))
{}

const std::int32_t storyInteractionTypeRepost::ID;

void storyInteractionTypeRepost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteractionTypeRepost");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

storyListMain::storyListMain() {
}

const std::int32_t storyListMain::ID;

void storyListMain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyListMain");
    s.store_class_end();
  }
}

storyListArchive::storyListArchive() {
}

const std::int32_t storyListArchive::ID;

void storyListArchive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyListArchive");
    s.store_class_end();
  }
}

testVectorString::testVectorString()
  : value_()
{}

testVectorString::testVectorString(array<string> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorString::ID;

void testVectorString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorString");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

textCompositionParameters::textCompositionParameters()
  : translate_to_language_code_()
  , style_name_()
  , add_emojis_()
  , fix_text_()
{}

textCompositionParameters::textCompositionParameters(string const &translate_to_language_code_, string const &style_name_, bool add_emojis_, bool fix_text_)
  : translate_to_language_code_(translate_to_language_code_)
  , style_name_(style_name_)
  , add_emojis_(add_emojis_)
  , fix_text_(fix_text_)
{}

const std::int32_t textCompositionParameters::ID;

void textCompositionParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textCompositionParameters");
    s.store_field("translate_to_language_code", translate_to_language_code_);
    s.store_field("style_name", style_name_);
    s.store_field("add_emojis", add_emojis_);
    s.store_field("fix_text", fix_text_);
    s.store_class_end();
  }
}

textRanges::textRanges()
  : ranges_()
{}

textRanges::textRanges(array<object_ptr<textRange>> &&ranges_)
  : ranges_(std::move(ranges_))
{}

const std::int32_t textRanges::ID;

void textRanges::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textRanges");
    { s.store_vector_begin("ranges", ranges_.size()); for (const auto &_value : ranges_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

thumbnailFormatJpeg::thumbnailFormatJpeg() {
}

const std::int32_t thumbnailFormatJpeg::ID;

void thumbnailFormatJpeg::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatJpeg");
    s.store_class_end();
  }
}

thumbnailFormatGif::thumbnailFormatGif() {
}

const std::int32_t thumbnailFormatGif::ID;

void thumbnailFormatGif::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatGif");
    s.store_class_end();
  }
}

thumbnailFormatMpeg4::thumbnailFormatMpeg4() {
}

const std::int32_t thumbnailFormatMpeg4::ID;

void thumbnailFormatMpeg4::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatMpeg4");
    s.store_class_end();
  }
}

thumbnailFormatPng::thumbnailFormatPng() {
}

const std::int32_t thumbnailFormatPng::ID;

void thumbnailFormatPng::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatPng");
    s.store_class_end();
  }
}

thumbnailFormatTgs::thumbnailFormatTgs() {
}

const std::int32_t thumbnailFormatTgs::ID;

void thumbnailFormatTgs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatTgs");
    s.store_class_end();
  }
}

thumbnailFormatWebm::thumbnailFormatWebm() {
}

const std::int32_t thumbnailFormatWebm::ID;

void thumbnailFormatWebm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatWebm");
    s.store_class_end();
  }
}

thumbnailFormatWebp::thumbnailFormatWebp() {
}

const std::int32_t thumbnailFormatWebp::ID;

void thumbnailFormatWebp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatWebp");
    s.store_class_end();
  }
}

tonTransaction::tonTransaction()
  : id_()
  , gram_amount_()
  , is_refund_()
  , date_()
  , type_()
{}

tonTransaction::tonTransaction(string const &id_, int53 gram_amount_, bool is_refund_, int32 date_, object_ptr<TonTransactionType> &&type_)
  : id_(id_)
  , gram_amount_(gram_amount_)
  , is_refund_(is_refund_)
  , date_(date_)
  , type_(std::move(type_))
{}

const std::int32_t tonTransaction::ID;

void tonTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransaction");
    s.store_field("id", id_);
    s.store_field("gram_amount", gram_amount_);
    s.store_field("is_refund", is_refund_);
    s.store_field("date", date_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

updateAuthorizationState::updateAuthorizationState()
  : authorization_state_()
{}

updateAuthorizationState::updateAuthorizationState(object_ptr<AuthorizationState> &&authorization_state_)
  : authorization_state_(std::move(authorization_state_))
{}

const std::int32_t updateAuthorizationState::ID;

void updateAuthorizationState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAuthorizationState");
    s.store_object_field("authorization_state", static_cast<const BaseObject *>(authorization_state_.get()));
    s.store_class_end();
  }
}

updateNewMessage::updateNewMessage()
  : message_()
{}

updateNewMessage::updateNewMessage(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t updateNewMessage::ID;

void updateNewMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateMessageSendAcknowledged::updateMessageSendAcknowledged()
  : chat_id_()
  , message_id_()
{}

updateMessageSendAcknowledged::updateMessageSendAcknowledged(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t updateMessageSendAcknowledged::ID;

void updateMessageSendAcknowledged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageSendAcknowledged");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

updateMessageSendSucceeded::updateMessageSendSucceeded()
  : message_()
  , old_message_id_()
{}

updateMessageSendSucceeded::updateMessageSendSucceeded(object_ptr<message> &&message_, int53 old_message_id_)
  : message_(std::move(message_))
  , old_message_id_(old_message_id_)
{}

const std::int32_t updateMessageSendSucceeded::ID;

void updateMessageSendSucceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageSendSucceeded");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("old_message_id", old_message_id_);
    s.store_class_end();
  }
}

updateMessageSendFailed::updateMessageSendFailed()
  : message_()
  , old_message_id_()
  , error_()
{}

updateMessageSendFailed::updateMessageSendFailed(object_ptr<message> &&message_, int53 old_message_id_, object_ptr<error> &&error_)
  : message_(std::move(message_))
  , old_message_id_(old_message_id_)
  , error_(std::move(error_))
{}

const std::int32_t updateMessageSendFailed::ID;

void updateMessageSendFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageSendFailed");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("old_message_id", old_message_id_);
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

updateMessageContent::updateMessageContent()
  : chat_id_()
  , message_id_()
  , new_content_()
{}

updateMessageContent::updateMessageContent(int53 chat_id_, int53 message_id_, object_ptr<MessageContent> &&new_content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , new_content_(std::move(new_content_))
{}

const std::int32_t updateMessageContent::ID;

void updateMessageContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("new_content", static_cast<const BaseObject *>(new_content_.get()));
    s.store_class_end();
  }
}

updateMessageEphemeralContent::updateMessageEphemeralContent()
  : chat_id_()
  , message_id_()
  , ephemeral_content_()
{}

updateMessageEphemeralContent::updateMessageEphemeralContent(int53 chat_id_, int53 message_id_, object_ptr<ephemeralMessageContent> &&ephemeral_content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , ephemeral_content_(std::move(ephemeral_content_))
{}

const std::int32_t updateMessageEphemeralContent::ID;

void updateMessageEphemeralContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageEphemeralContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("ephemeral_content", static_cast<const BaseObject *>(ephemeral_content_.get()));
    s.store_class_end();
  }
}

updateMessageEdited::updateMessageEdited()
  : chat_id_()
  , message_id_()
  , edit_date_()
  , reply_markup_()
{}

updateMessageEdited::updateMessageEdited(int53 chat_id_, int53 message_id_, int32 edit_date_, object_ptr<ReplyMarkup> &&reply_markup_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , edit_date_(edit_date_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t updateMessageEdited::ID;

void updateMessageEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageEdited");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("edit_date", edit_date_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

updateMessageIsPinned::updateMessageIsPinned()
  : chat_id_()
  , message_id_()
  , is_pinned_()
{}

updateMessageIsPinned::updateMessageIsPinned(int53 chat_id_, int53 message_id_, bool is_pinned_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t updateMessageIsPinned::ID;

void updateMessageIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageIsPinned");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

updateMessageInteractionInfo::updateMessageInteractionInfo()
  : chat_id_()
  , message_id_()
  , interaction_info_()
{}

updateMessageInteractionInfo::updateMessageInteractionInfo(int53 chat_id_, int53 message_id_, object_ptr<messageInteractionInfo> &&interaction_info_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , interaction_info_(std::move(interaction_info_))
{}

const std::int32_t updateMessageInteractionInfo::ID;

void updateMessageInteractionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageInteractionInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("interaction_info", static_cast<const BaseObject *>(interaction_info_.get()));
    s.store_class_end();
  }
}

updateMessageContentOpened::updateMessageContentOpened()
  : chat_id_()
  , message_id_()
{}

updateMessageContentOpened::updateMessageContentOpened(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t updateMessageContentOpened::ID;

void updateMessageContentOpened::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageContentOpened");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

updateMessageMentionRead::updateMessageMentionRead()
  : chat_id_()
  , message_id_()
  , unread_mention_count_()
{}

updateMessageMentionRead::updateMessageMentionRead(int53 chat_id_, int53 message_id_, int32 unread_mention_count_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , unread_mention_count_(unread_mention_count_)
{}

const std::int32_t updateMessageMentionRead::ID;

void updateMessageMentionRead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageMentionRead");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_class_end();
  }
}

updateMessageUnreadReactions::updateMessageUnreadReactions()
  : chat_id_()
  , message_id_()
  , unread_reactions_()
  , unread_reaction_count_()
{}

updateMessageUnreadReactions::updateMessageUnreadReactions(int53 chat_id_, int53 message_id_, array<object_ptr<unreadReaction>> &&unread_reactions_, int32 unread_reaction_count_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , unread_reactions_(std::move(unread_reactions_))
  , unread_reaction_count_(unread_reaction_count_)
{}

const std::int32_t updateMessageUnreadReactions::ID;

void updateMessageUnreadReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageUnreadReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("unread_reactions", unread_reactions_.size()); for (const auto &_value : unread_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_class_end();
  }
}

updateMessageContainsUnreadPollVotes::updateMessageContainsUnreadPollVotes()
  : chat_id_()
  , message_id_()
  , contains_unread_poll_votes_()
  , unread_poll_vote_count_()
{}

updateMessageContainsUnreadPollVotes::updateMessageContainsUnreadPollVotes(int53 chat_id_, int53 message_id_, bool contains_unread_poll_votes_, int32 unread_poll_vote_count_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , contains_unread_poll_votes_(contains_unread_poll_votes_)
  , unread_poll_vote_count_(unread_poll_vote_count_)
{}

const std::int32_t updateMessageContainsUnreadPollVotes::ID;

void updateMessageContainsUnreadPollVotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageContainsUnreadPollVotes");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("contains_unread_poll_votes", contains_unread_poll_votes_);
    s.store_field("unread_poll_vote_count", unread_poll_vote_count_);
    s.store_class_end();
  }
}

updateMessageFactCheck::updateMessageFactCheck()
  : chat_id_()
  , message_id_()
  , fact_check_()
{}

updateMessageFactCheck::updateMessageFactCheck(int53 chat_id_, int53 message_id_, object_ptr<factCheck> &&fact_check_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , fact_check_(std::move(fact_check_))
{}

const std::int32_t updateMessageFactCheck::ID;

void updateMessageFactCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageFactCheck");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("fact_check", static_cast<const BaseObject *>(fact_check_.get()));
    s.store_class_end();
  }
}

updateMessageSuggestedPostInfo::updateMessageSuggestedPostInfo()
  : chat_id_()
  , message_id_()
  , suggested_post_info_()
{}

updateMessageSuggestedPostInfo::updateMessageSuggestedPostInfo(int53 chat_id_, int53 message_id_, object_ptr<suggestedPostInfo> &&suggested_post_info_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , suggested_post_info_(std::move(suggested_post_info_))
{}

const std::int32_t updateMessageSuggestedPostInfo::ID;

void updateMessageSuggestedPostInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageSuggestedPostInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("suggested_post_info", static_cast<const BaseObject *>(suggested_post_info_.get()));
    s.store_class_end();
  }
}

updateMessageLiveLocationViewed::updateMessageLiveLocationViewed()
  : chat_id_()
  , message_id_()
{}

updateMessageLiveLocationViewed::updateMessageLiveLocationViewed(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t updateMessageLiveLocationViewed::ID;

void updateMessageLiveLocationViewed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageLiveLocationViewed");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

updateVideoPublished::updateVideoPublished()
  : chat_id_()
  , message_id_()
{}

updateVideoPublished::updateVideoPublished(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t updateVideoPublished::ID;

void updateVideoPublished::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateVideoPublished");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

updateNewChat::updateNewChat()
  : chat_()
{}

updateNewChat::updateNewChat(object_ptr<chat> &&chat_)
  : chat_(std::move(chat_))
{}

const std::int32_t updateNewChat::ID;

void updateNewChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewChat");
    s.store_object_field("chat", static_cast<const BaseObject *>(chat_.get()));
    s.store_class_end();
  }
}

updateChatTitle::updateChatTitle()
  : chat_id_()
  , title_()
{}

updateChatTitle::updateChatTitle(int53 chat_id_, string const &title_)
  : chat_id_(chat_id_)
  , title_(title_)
{}

const std::int32_t updateChatTitle::ID;

void updateChatTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatTitle");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

updateChatPhoto::updateChatPhoto()
  : chat_id_()
  , photo_()
{}

updateChatPhoto::updateChatPhoto(int53 chat_id_, object_ptr<chatPhotoInfo> &&photo_)
  : chat_id_(chat_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t updateChatPhoto::ID;

void updateChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPhoto");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

updateChatAccentColors::updateChatAccentColors()
  : chat_id_()
  , accent_color_id_()
  , background_custom_emoji_id_()
  , upgraded_gift_colors_()
  , profile_accent_color_id_()
  , profile_background_custom_emoji_id_()
{}

updateChatAccentColors::updateChatAccentColors(int53 chat_id_, int32 accent_color_id_, int64 background_custom_emoji_id_, object_ptr<upgradedGiftColors> &&upgraded_gift_colors_, int32 profile_accent_color_id_, int64 profile_background_custom_emoji_id_)
  : chat_id_(chat_id_)
  , accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
  , upgraded_gift_colors_(std::move(upgraded_gift_colors_))
  , profile_accent_color_id_(profile_accent_color_id_)
  , profile_background_custom_emoji_id_(profile_background_custom_emoji_id_)
{}

const std::int32_t updateChatAccentColors::ID;

void updateChatAccentColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatAccentColors");
    s.store_field("chat_id", chat_id_);
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_object_field("upgraded_gift_colors", static_cast<const BaseObject *>(upgraded_gift_colors_.get()));
    s.store_field("profile_accent_color_id", profile_accent_color_id_);
    s.store_field("profile_background_custom_emoji_id", profile_background_custom_emoji_id_);
    s.store_class_end();
  }
}

updateChatPermissions::updateChatPermissions()
  : chat_id_()
  , permissions_()
{}

updateChatPermissions::updateChatPermissions(int53 chat_id_, object_ptr<chatPermissions> &&permissions_)
  : chat_id_(chat_id_)
  , permissions_(std::move(permissions_))
{}

const std::int32_t updateChatPermissions::ID;

void updateChatPermissions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPermissions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_class_end();
  }
}

updateChatLastMessage::updateChatLastMessage()
  : chat_id_()
  , last_message_()
  , positions_()
{}

updateChatLastMessage::updateChatLastMessage(int53 chat_id_, object_ptr<message> &&last_message_, array<object_ptr<chatPosition>> &&positions_)
  : chat_id_(chat_id_)
  , last_message_(std::move(last_message_))
  , positions_(std::move(positions_))
{}

const std::int32_t updateChatLastMessage::ID;

void updateChatLastMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatLastMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateChatPosition::updateChatPosition()
  : chat_id_()
  , position_()
{}

updateChatPosition::updateChatPosition(int53 chat_id_, object_ptr<chatPosition> &&position_)
  : chat_id_(chat_id_)
  , position_(std::move(position_))
{}

const std::int32_t updateChatPosition::ID;

void updateChatPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPosition");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("position", static_cast<const BaseObject *>(position_.get()));
    s.store_class_end();
  }
}

updateChatAddedToList::updateChatAddedToList()
  : chat_id_()
  , chat_list_()
{}

updateChatAddedToList::updateChatAddedToList(int53 chat_id_, object_ptr<ChatList> &&chat_list_)
  : chat_id_(chat_id_)
  , chat_list_(std::move(chat_list_))
{}

const std::int32_t updateChatAddedToList::ID;

void updateChatAddedToList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatAddedToList");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_class_end();
  }
}

updateChatRemovedFromList::updateChatRemovedFromList()
  : chat_id_()
  , chat_list_()
{}

updateChatRemovedFromList::updateChatRemovedFromList(int53 chat_id_, object_ptr<ChatList> &&chat_list_)
  : chat_id_(chat_id_)
  , chat_list_(std::move(chat_list_))
{}

const std::int32_t updateChatRemovedFromList::ID;

void updateChatRemovedFromList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatRemovedFromList");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_class_end();
  }
}

updateChatReadInbox::updateChatReadInbox()
  : chat_id_()
  , last_read_inbox_message_id_()
  , unread_count_()
{}

updateChatReadInbox::updateChatReadInbox(int53 chat_id_, int53 last_read_inbox_message_id_, int32 unread_count_)
  : chat_id_(chat_id_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , unread_count_(unread_count_)
{}

const std::int32_t updateChatReadInbox::ID;

void updateChatReadInbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatReadInbox");
    s.store_field("chat_id", chat_id_);
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("unread_count", unread_count_);
    s.store_class_end();
  }
}

updateChatReadOutbox::updateChatReadOutbox()
  : chat_id_()
  , last_read_outbox_message_id_()
{}

updateChatReadOutbox::updateChatReadOutbox(int53 chat_id_, int53 last_read_outbox_message_id_)
  : chat_id_(chat_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
{}

const std::int32_t updateChatReadOutbox::ID;

void updateChatReadOutbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatReadOutbox");
    s.store_field("chat_id", chat_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_class_end();
  }
}

updateChatActionBar::updateChatActionBar()
  : chat_id_()
  , action_bar_()
{}

updateChatActionBar::updateChatActionBar(int53 chat_id_, object_ptr<ChatActionBar> &&action_bar_)
  : chat_id_(chat_id_)
  , action_bar_(std::move(action_bar_))
{}

const std::int32_t updateChatActionBar::ID;

void updateChatActionBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatActionBar");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("action_bar", static_cast<const BaseObject *>(action_bar_.get()));
    s.store_class_end();
  }
}

updateChatBusinessBotManageBar::updateChatBusinessBotManageBar()
  : chat_id_()
  , business_bot_manage_bar_()
{}

updateChatBusinessBotManageBar::updateChatBusinessBotManageBar(int53 chat_id_, object_ptr<businessBotManageBar> &&business_bot_manage_bar_)
  : chat_id_(chat_id_)
  , business_bot_manage_bar_(std::move(business_bot_manage_bar_))
{}

const std::int32_t updateChatBusinessBotManageBar::ID;

void updateChatBusinessBotManageBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatBusinessBotManageBar");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("business_bot_manage_bar", static_cast<const BaseObject *>(business_bot_manage_bar_.get()));
    s.store_class_end();
  }
}

updateChatAvailableReactions::updateChatAvailableReactions()
  : chat_id_()
  , available_reactions_()
{}

updateChatAvailableReactions::updateChatAvailableReactions(int53 chat_id_, object_ptr<ChatAvailableReactions> &&available_reactions_)
  : chat_id_(chat_id_)
  , available_reactions_(std::move(available_reactions_))
{}

const std::int32_t updateChatAvailableReactions::ID;

void updateChatAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatAvailableReactions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get()));
    s.store_class_end();
  }
}

updateChatDraftMessage::updateChatDraftMessage()
  : chat_id_()
  , draft_message_()
  , positions_()
{}

updateChatDraftMessage::updateChatDraftMessage(int53 chat_id_, object_ptr<draftMessage> &&draft_message_, array<object_ptr<chatPosition>> &&positions_)
  : chat_id_(chat_id_)
  , draft_message_(std::move(draft_message_))
  , positions_(std::move(positions_))
{}

const std::int32_t updateChatDraftMessage::ID;

void updateChatDraftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatDraftMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateChatTextCompositionParameters::updateChatTextCompositionParameters()
  : chat_id_()
  , text_composition_parameters_()
{}

updateChatTextCompositionParameters::updateChatTextCompositionParameters(int53 chat_id_, object_ptr<textCompositionParameters> &&text_composition_parameters_)
  : chat_id_(chat_id_)
  , text_composition_parameters_(std::move(text_composition_parameters_))
{}

const std::int32_t updateChatTextCompositionParameters::ID;

void updateChatTextCompositionParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatTextCompositionParameters");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("text_composition_parameters", static_cast<const BaseObject *>(text_composition_parameters_.get()));
    s.store_class_end();
  }
}

updateChatEmojiStatus::updateChatEmojiStatus()
  : chat_id_()
  , emoji_status_()
{}

updateChatEmojiStatus::updateChatEmojiStatus(int53 chat_id_, object_ptr<emojiStatus> &&emoji_status_)
  : chat_id_(chat_id_)
  , emoji_status_(std::move(emoji_status_))
{}

const std::int32_t updateChatEmojiStatus::ID;

void updateChatEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatEmojiStatus");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

updateChatMessageSender::updateChatMessageSender()
  : chat_id_()
  , message_sender_id_()
{}

updateChatMessageSender::updateChatMessageSender(int53 chat_id_, object_ptr<MessageSender> &&message_sender_id_)
  : chat_id_(chat_id_)
  , message_sender_id_(std::move(message_sender_id_))
{}

const std::int32_t updateChatMessageSender::ID;

void updateChatMessageSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatMessageSender");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    s.store_class_end();
  }
}

updateChatMessageAutoDeleteTime::updateChatMessageAutoDeleteTime()
  : chat_id_()
  , message_auto_delete_time_()
{}

updateChatMessageAutoDeleteTime::updateChatMessageAutoDeleteTime(int53 chat_id_, int32 message_auto_delete_time_)
  : chat_id_(chat_id_)
  , message_auto_delete_time_(message_auto_delete_time_)
{}

const std::int32_t updateChatMessageAutoDeleteTime::ID;

void updateChatMessageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatMessageAutoDeleteTime");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_class_end();
  }
}

updateChatNotificationSettings::updateChatNotificationSettings()
  : chat_id_()
  , notification_settings_()
{}

updateChatNotificationSettings::updateChatNotificationSettings(int53 chat_id_, object_ptr<chatNotificationSettings> &&notification_settings_)
  : chat_id_(chat_id_)
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t updateChatNotificationSettings::ID;

void updateChatNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatNotificationSettings");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

updateChatPendingJoinRequests::updateChatPendingJoinRequests()
  : chat_id_()
  , pending_join_requests_()
{}

updateChatPendingJoinRequests::updateChatPendingJoinRequests(int53 chat_id_, object_ptr<chatJoinRequestsInfo> &&pending_join_requests_)
  : chat_id_(chat_id_)
  , pending_join_requests_(std::move(pending_join_requests_))
{}

const std::int32_t updateChatPendingJoinRequests::ID;

void updateChatPendingJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPendingJoinRequests");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("pending_join_requests", static_cast<const BaseObject *>(pending_join_requests_.get()));
    s.store_class_end();
  }
}

updateChatReplyMarkup::updateChatReplyMarkup()
  : chat_id_()
  , reply_markup_message_()
{}

updateChatReplyMarkup::updateChatReplyMarkup(int53 chat_id_, object_ptr<message> &&reply_markup_message_)
  : chat_id_(chat_id_)
  , reply_markup_message_(std::move(reply_markup_message_))
{}

const std::int32_t updateChatReplyMarkup::ID;

void updateChatReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatReplyMarkup");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("reply_markup_message", static_cast<const BaseObject *>(reply_markup_message_.get()));
    s.store_class_end();
  }
}

updateChatBackground::updateChatBackground()
  : chat_id_()
  , background_()
{}

updateChatBackground::updateChatBackground(int53 chat_id_, object_ptr<chatBackground> &&background_)
  : chat_id_(chat_id_)
  , background_(std::move(background_))
{}

const std::int32_t updateChatBackground::ID;

void updateChatBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatBackground");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_class_end();
  }
}

updateChatTheme::updateChatTheme()
  : chat_id_()
  , theme_()
{}

updateChatTheme::updateChatTheme(int53 chat_id_, object_ptr<ChatTheme> &&theme_)
  : chat_id_(chat_id_)
  , theme_(std::move(theme_))
{}

const std::int32_t updateChatTheme::ID;

void updateChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatTheme");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

updateChatUnreadMentionCount::updateChatUnreadMentionCount()
  : chat_id_()
  , unread_mention_count_()
{}

updateChatUnreadMentionCount::updateChatUnreadMentionCount(int53 chat_id_, int32 unread_mention_count_)
  : chat_id_(chat_id_)
  , unread_mention_count_(unread_mention_count_)
{}

const std::int32_t updateChatUnreadMentionCount::ID;

void updateChatUnreadMentionCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatUnreadMentionCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_class_end();
  }
}

updateChatUnreadReactionCount::updateChatUnreadReactionCount()
  : chat_id_()
  , unread_reaction_count_()
{}

updateChatUnreadReactionCount::updateChatUnreadReactionCount(int53 chat_id_, int32 unread_reaction_count_)
  : chat_id_(chat_id_)
  , unread_reaction_count_(unread_reaction_count_)
{}

const std::int32_t updateChatUnreadReactionCount::ID;

void updateChatUnreadReactionCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatUnreadReactionCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_class_end();
  }
}

updateChatUnreadPollVoteCount::updateChatUnreadPollVoteCount()
  : chat_id_()
  , unread_poll_vote_count_()
{}

updateChatUnreadPollVoteCount::updateChatUnreadPollVoteCount(int53 chat_id_, int32 unread_poll_vote_count_)
  : chat_id_(chat_id_)
  , unread_poll_vote_count_(unread_poll_vote_count_)
{}

const std::int32_t updateChatUnreadPollVoteCount::ID;

void updateChatUnreadPollVoteCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatUnreadPollVoteCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("unread_poll_vote_count", unread_poll_vote_count_);
    s.store_class_end();
  }
}

updateChatVideoChat::updateChatVideoChat()
  : chat_id_()
  , video_chat_()
{}

updateChatVideoChat::updateChatVideoChat(int53 chat_id_, object_ptr<videoChat> &&video_chat_)
  : chat_id_(chat_id_)
  , video_chat_(std::move(video_chat_))
{}

const std::int32_t updateChatVideoChat::ID;

void updateChatVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatVideoChat");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("video_chat", static_cast<const BaseObject *>(video_chat_.get()));
    s.store_class_end();
  }
}

updateChatDefaultDisableNotification::updateChatDefaultDisableNotification()
  : chat_id_()
  , default_disable_notification_()
{}

updateChatDefaultDisableNotification::updateChatDefaultDisableNotification(int53 chat_id_, bool default_disable_notification_)
  : chat_id_(chat_id_)
  , default_disable_notification_(default_disable_notification_)
{}

const std::int32_t updateChatDefaultDisableNotification::ID;

void updateChatDefaultDisableNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatDefaultDisableNotification");
    s.store_field("chat_id", chat_id_);
    s.store_field("default_disable_notification", default_disable_notification_);
    s.store_class_end();
  }
}

updateChatHasProtectedContent::updateChatHasProtectedContent()
  : chat_id_()
  , has_protected_content_()
{}

updateChatHasProtectedContent::updateChatHasProtectedContent(int53 chat_id_, bool has_protected_content_)
  : chat_id_(chat_id_)
  , has_protected_content_(has_protected_content_)
{}

const std::int32_t updateChatHasProtectedContent::ID;

void updateChatHasProtectedContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatHasProtectedContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("has_protected_content", has_protected_content_);
    s.store_class_end();
  }
}

updateChatIsTranslatable::updateChatIsTranslatable()
  : chat_id_()
  , is_translatable_()
{}

updateChatIsTranslatable::updateChatIsTranslatable(int53 chat_id_, bool is_translatable_)
  : chat_id_(chat_id_)
  , is_translatable_(is_translatable_)
{}

const std::int32_t updateChatIsTranslatable::ID;

void updateChatIsTranslatable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatIsTranslatable");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_translatable", is_translatable_);
    s.store_class_end();
  }
}

updateChatIsMarkedAsUnread::updateChatIsMarkedAsUnread()
  : chat_id_()
  , is_marked_as_unread_()
{}

updateChatIsMarkedAsUnread::updateChatIsMarkedAsUnread(int53 chat_id_, bool is_marked_as_unread_)
  : chat_id_(chat_id_)
  , is_marked_as_unread_(is_marked_as_unread_)
{}

const std::int32_t updateChatIsMarkedAsUnread::ID;

void updateChatIsMarkedAsUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatIsMarkedAsUnread");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_class_end();
  }
}

updateChatViewAsTopics::updateChatViewAsTopics()
  : chat_id_()
  , view_as_topics_()
{}

updateChatViewAsTopics::updateChatViewAsTopics(int53 chat_id_, bool view_as_topics_)
  : chat_id_(chat_id_)
  , view_as_topics_(view_as_topics_)
{}

const std::int32_t updateChatViewAsTopics::ID;

void updateChatViewAsTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatViewAsTopics");
    s.store_field("chat_id", chat_id_);
    s.store_field("view_as_topics", view_as_topics_);
    s.store_class_end();
  }
}

updateChatBlockList::updateChatBlockList()
  : chat_id_()
  , block_list_()
{}

updateChatBlockList::updateChatBlockList(int53 chat_id_, object_ptr<BlockList> &&block_list_)
  : chat_id_(chat_id_)
  , block_list_(std::move(block_list_))
{}

const std::int32_t updateChatBlockList::ID;

void updateChatBlockList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatBlockList");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_class_end();
  }
}

updateChatHasScheduledMessages::updateChatHasScheduledMessages()
  : chat_id_()
  , has_scheduled_messages_()
{}

updateChatHasScheduledMessages::updateChatHasScheduledMessages(int53 chat_id_, bool has_scheduled_messages_)
  : chat_id_(chat_id_)
  , has_scheduled_messages_(has_scheduled_messages_)
{}

const std::int32_t updateChatHasScheduledMessages::ID;

void updateChatHasScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatHasScheduledMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("has_scheduled_messages", has_scheduled_messages_);
    s.store_class_end();
  }
}

updateChatHasWelcomeMessages::updateChatHasWelcomeMessages()
  : chat_id_()
  , has_welcome_messages_()
{}

updateChatHasWelcomeMessages::updateChatHasWelcomeMessages(int53 chat_id_, bool has_welcome_messages_)
  : chat_id_(chat_id_)
  , has_welcome_messages_(has_welcome_messages_)
{}

const std::int32_t updateChatHasWelcomeMessages::ID;

void updateChatHasWelcomeMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatHasWelcomeMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("has_welcome_messages", has_welcome_messages_);
    s.store_class_end();
  }
}

updateChatFolders::updateChatFolders()
  : chat_folders_()
  , main_chat_list_position_()
  , are_tags_enabled_()
{}

updateChatFolders::updateChatFolders(array<object_ptr<chatFolderInfo>> &&chat_folders_, int32 main_chat_list_position_, bool are_tags_enabled_)
  : chat_folders_(std::move(chat_folders_))
  , main_chat_list_position_(main_chat_list_position_)
  , are_tags_enabled_(are_tags_enabled_)
{}

const std::int32_t updateChatFolders::ID;

void updateChatFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatFolders");
    { s.store_vector_begin("chat_folders", chat_folders_.size()); for (const auto &_value : chat_folders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("main_chat_list_position", main_chat_list_position_);
    s.store_field("are_tags_enabled", are_tags_enabled_);
    s.store_class_end();
  }
}

updateChatOnlineMemberCount::updateChatOnlineMemberCount()
  : chat_id_()
  , online_member_count_()
{}

updateChatOnlineMemberCount::updateChatOnlineMemberCount(int53 chat_id_, int32 online_member_count_)
  : chat_id_(chat_id_)
  , online_member_count_(online_member_count_)
{}

const std::int32_t updateChatOnlineMemberCount::ID;

void updateChatOnlineMemberCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatOnlineMemberCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("online_member_count", online_member_count_);
    s.store_class_end();
  }
}

updateSavedMessagesTopic::updateSavedMessagesTopic()
  : topic_()
{}

updateSavedMessagesTopic::updateSavedMessagesTopic(object_ptr<savedMessagesTopic> &&topic_)
  : topic_(std::move(topic_))
{}

const std::int32_t updateSavedMessagesTopic::ID;

void updateSavedMessagesTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedMessagesTopic");
    s.store_object_field("topic", static_cast<const BaseObject *>(topic_.get()));
    s.store_class_end();
  }
}

updateSavedMessagesTopicCount::updateSavedMessagesTopicCount()
  : topic_count_()
{}

updateSavedMessagesTopicCount::updateSavedMessagesTopicCount(int32 topic_count_)
  : topic_count_(topic_count_)
{}

const std::int32_t updateSavedMessagesTopicCount::ID;

void updateSavedMessagesTopicCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedMessagesTopicCount");
    s.store_field("topic_count", topic_count_);
    s.store_class_end();
  }
}

updateDirectMessagesChatTopic::updateDirectMessagesChatTopic()
  : topic_()
{}

updateDirectMessagesChatTopic::updateDirectMessagesChatTopic(object_ptr<directMessagesChatTopic> &&topic_)
  : topic_(std::move(topic_))
{}

const std::int32_t updateDirectMessagesChatTopic::ID;

void updateDirectMessagesChatTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDirectMessagesChatTopic");
    s.store_object_field("topic", static_cast<const BaseObject *>(topic_.get()));
    s.store_class_end();
  }
}

updateTopicMessageCount::updateTopicMessageCount()
  : chat_id_()
  , topic_id_()
  , message_count_()
{}

updateTopicMessageCount::updateTopicMessageCount(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, int32 message_count_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , message_count_(message_count_)
{}

const std::int32_t updateTopicMessageCount::ID;

void updateTopicMessageCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTopicMessageCount");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_field("message_count", message_count_);
    s.store_class_end();
  }
}

updateQuickReplyShortcut::updateQuickReplyShortcut()
  : shortcut_()
{}

updateQuickReplyShortcut::updateQuickReplyShortcut(object_ptr<quickReplyShortcut> &&shortcut_)
  : shortcut_(std::move(shortcut_))
{}

const std::int32_t updateQuickReplyShortcut::ID;

void updateQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplyShortcut");
    s.store_object_field("shortcut", static_cast<const BaseObject *>(shortcut_.get()));
    s.store_class_end();
  }
}

updateQuickReplyShortcutDeleted::updateQuickReplyShortcutDeleted()
  : shortcut_id_()
{}

updateQuickReplyShortcutDeleted::updateQuickReplyShortcutDeleted(int32 shortcut_id_)
  : shortcut_id_(shortcut_id_)
{}

const std::int32_t updateQuickReplyShortcutDeleted::ID;

void updateQuickReplyShortcutDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplyShortcutDeleted");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

updateQuickReplyShortcuts::updateQuickReplyShortcuts()
  : shortcut_ids_()
{}

updateQuickReplyShortcuts::updateQuickReplyShortcuts(array<int32> &&shortcut_ids_)
  : shortcut_ids_(std::move(shortcut_ids_))
{}

const std::int32_t updateQuickReplyShortcuts::ID;

void updateQuickReplyShortcuts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplyShortcuts");
    { s.store_vector_begin("shortcut_ids", shortcut_ids_.size()); for (const auto &_value : shortcut_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateQuickReplyShortcutMessages::updateQuickReplyShortcutMessages()
  : shortcut_id_()
  , messages_()
{}

updateQuickReplyShortcutMessages::updateQuickReplyShortcutMessages(int32 shortcut_id_, array<object_ptr<quickReplyMessage>> &&messages_)
  : shortcut_id_(shortcut_id_)
  , messages_(std::move(messages_))
{}

const std::int32_t updateQuickReplyShortcutMessages::ID;

void updateQuickReplyShortcutMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplyShortcutMessages");
    s.store_field("shortcut_id", shortcut_id_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateChatWelcomeMessages::updateChatWelcomeMessages()
  : chat_id_()
  , messages_()
{}

updateChatWelcomeMessages::updateChatWelcomeMessages(int53 chat_id_, array<object_ptr<welcomeMessage>> &&messages_)
  : chat_id_(chat_id_)
  , messages_(std::move(messages_))
{}

const std::int32_t updateChatWelcomeMessages::ID;

void updateChatWelcomeMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatWelcomeMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateForumTopicInfo::updateForumTopicInfo()
  : info_()
{}

updateForumTopicInfo::updateForumTopicInfo(object_ptr<forumTopicInfo> &&info_)
  : info_(std::move(info_))
{}

const std::int32_t updateForumTopicInfo::ID;

void updateForumTopicInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateForumTopicInfo");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

updateForumTopic::updateForumTopic()
  : chat_id_()
  , forum_topic_id_()
  , is_pinned_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , unread_mention_count_()
  , unread_reaction_count_()
  , unread_poll_vote_count_()
  , notification_settings_()
  , draft_message_()
{}

updateForumTopic::updateForumTopic(int53 chat_id_, int32 forum_topic_id_, bool is_pinned_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int32 unread_mention_count_, int32 unread_reaction_count_, int32 unread_poll_vote_count_, object_ptr<chatNotificationSettings> &&notification_settings_, object_ptr<draftMessage> &&draft_message_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , is_pinned_(is_pinned_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , unread_mention_count_(unread_mention_count_)
  , unread_reaction_count_(unread_reaction_count_)
  , unread_poll_vote_count_(unread_poll_vote_count_)
  , notification_settings_(std::move(notification_settings_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t updateForumTopic::ID;

void updateForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateForumTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_field("unread_poll_vote_count", unread_poll_vote_count_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

updateScopeNotificationSettings::updateScopeNotificationSettings()
  : scope_()
  , notification_settings_()
{}

updateScopeNotificationSettings::updateScopeNotificationSettings(object_ptr<NotificationSettingsScope> &&scope_, object_ptr<scopeNotificationSettings> &&notification_settings_)
  : scope_(std::move(scope_))
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t updateScopeNotificationSettings::ID;

void updateScopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateScopeNotificationSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

updateReactionNotificationSettings::updateReactionNotificationSettings()
  : notification_settings_()
{}

updateReactionNotificationSettings::updateReactionNotificationSettings(object_ptr<reactionNotificationSettings> &&notification_settings_)
  : notification_settings_(std::move(notification_settings_))
{}

const std::int32_t updateReactionNotificationSettings::ID;

void updateReactionNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReactionNotificationSettings");
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

updateNotification::updateNotification()
  : notification_group_id_()
  , notification_()
{}

updateNotification::updateNotification(int32 notification_group_id_, object_ptr<notification> &&notification_)
  : notification_group_id_(notification_group_id_)
  , notification_(std::move(notification_))
{}

const std::int32_t updateNotification::ID;

void updateNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNotification");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_object_field("notification", static_cast<const BaseObject *>(notification_.get()));
    s.store_class_end();
  }
}

updateNotificationGroup::updateNotificationGroup()
  : notification_group_id_()
  , type_()
  , chat_id_()
  , notification_settings_chat_id_()
  , notification_sound_id_()
  , total_count_()
  , added_notifications_()
  , removed_notification_ids_()
{}

updateNotificationGroup::updateNotificationGroup(int32 notification_group_id_, object_ptr<NotificationGroupType> &&type_, int53 chat_id_, int53 notification_settings_chat_id_, int64 notification_sound_id_, int32 total_count_, array<object_ptr<notification>> &&added_notifications_, array<int32> &&removed_notification_ids_)
  : notification_group_id_(notification_group_id_)
  , type_(std::move(type_))
  , chat_id_(chat_id_)
  , notification_settings_chat_id_(notification_settings_chat_id_)
  , notification_sound_id_(notification_sound_id_)
  , total_count_(total_count_)
  , added_notifications_(std::move(added_notifications_))
  , removed_notification_ids_(std::move(removed_notification_ids_))
{}

const std::int32_t updateNotificationGroup::ID;

void updateNotificationGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNotificationGroup");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_field("notification_settings_chat_id", notification_settings_chat_id_);
    s.store_field("notification_sound_id", notification_sound_id_);
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("added_notifications", added_notifications_.size()); for (const auto &_value : added_notifications_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("removed_notification_ids", removed_notification_ids_.size()); for (const auto &_value : removed_notification_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateActiveNotifications::updateActiveNotifications()
  : groups_()
{}

updateActiveNotifications::updateActiveNotifications(array<object_ptr<notificationGroup>> &&groups_)
  : groups_(std::move(groups_))
{}

const std::int32_t updateActiveNotifications::ID;

void updateActiveNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateActiveNotifications");
    { s.store_vector_begin("groups", groups_.size()); for (const auto &_value : groups_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateHavePendingNotifications::updateHavePendingNotifications()
  : have_delayed_notifications_()
  , have_unreceived_notifications_()
{}

updateHavePendingNotifications::updateHavePendingNotifications(bool have_delayed_notifications_, bool have_unreceived_notifications_)
  : have_delayed_notifications_(have_delayed_notifications_)
  , have_unreceived_notifications_(have_unreceived_notifications_)
{}

const std::int32_t updateHavePendingNotifications::ID;

void updateHavePendingNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateHavePendingNotifications");
    s.store_field("have_delayed_notifications", have_delayed_notifications_);
    s.store_field("have_unreceived_notifications", have_unreceived_notifications_);
    s.store_class_end();
  }
}

updateDeleteMessages::updateDeleteMessages()
  : chat_id_()
  , message_ids_()
  , is_permanent_()
  , from_cache_()
{}

updateDeleteMessages::updateDeleteMessages(int53 chat_id_, array<int53> &&message_ids_, bool is_permanent_, bool from_cache_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
  , is_permanent_(is_permanent_)
  , from_cache_(from_cache_)
{}

const std::int32_t updateDeleteMessages::ID;

void updateDeleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("is_permanent", is_permanent_);
    s.store_field("from_cache", from_cache_);
    s.store_class_end();
  }
}

updateChatAction::updateChatAction()
  : chat_id_()
  , topic_id_()
  , sender_id_()
  , action_()
{}

updateChatAction::updateChatAction(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<MessageSender> &&sender_id_, object_ptr<ChatAction> &&action_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , sender_id_(std::move(sender_id_))
  , action_(std::move(action_))
{}

const std::int32_t updateChatAction::ID;

void updateChatAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatAction");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

updatePendingMessage::updatePendingMessage()
  : chat_id_()
  , forum_topic_id_()
  , draft_id_()
  , can_stop_()
  , keep_on_stop_()
  , content_()
{}

updatePendingMessage::updatePendingMessage(int53 chat_id_, int32 forum_topic_id_, int64 draft_id_, bool can_stop_, bool keep_on_stop_, object_ptr<MessageContent> &&content_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , draft_id_(draft_id_)
  , can_stop_(can_stop_)
  , keep_on_stop_(keep_on_stop_)
  , content_(std::move(content_))
{}

const std::int32_t updatePendingMessage::ID;

void updatePendingMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePendingMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("draft_id", draft_id_);
    s.store_field("can_stop", can_stop_);
    s.store_field("keep_on_stop", keep_on_stop_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

updateStopMessageDraft::updateStopMessageDraft()
  : chat_id_()
  , forum_topic_id_()
  , draft_id_()
{}

updateStopMessageDraft::updateStopMessageDraft(int53 chat_id_, int32 forum_topic_id_, int64 draft_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , draft_id_(draft_id_)
{}

const std::int32_t updateStopMessageDraft::ID;

void updateStopMessageDraft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStopMessageDraft");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("draft_id", draft_id_);
    s.store_class_end();
  }
}

updateCommunity::updateCommunity()
  : community_()
{}

updateCommunity::updateCommunity(object_ptr<community> &&community_)
  : community_(std::move(community_))
{}

const std::int32_t updateCommunity::ID;

void updateCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateCommunity");
    s.store_object_field("community", static_cast<const BaseObject *>(community_.get()));
    s.store_class_end();
  }
}

updateUserStatus::updateUserStatus()
  : user_id_()
  , status_()
{}

updateUserStatus::updateUserStatus(int53 user_id_, object_ptr<UserStatus> &&status_)
  : user_id_(user_id_)
  , status_(std::move(status_))
{}

const std::int32_t updateUserStatus::ID;

void updateUserStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserStatus");
    s.store_field("user_id", user_id_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

updateUser::updateUser()
  : user_()
{}

updateUser::updateUser(object_ptr<user> &&user_)
  : user_(std::move(user_))
{}

const std::int32_t updateUser::ID;

void updateUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUser");
    s.store_object_field("user", static_cast<const BaseObject *>(user_.get()));
    s.store_class_end();
  }
}

updateBasicGroup::updateBasicGroup()
  : basic_group_()
{}

updateBasicGroup::updateBasicGroup(object_ptr<basicGroup> &&basic_group_)
  : basic_group_(std::move(basic_group_))
{}

const std::int32_t updateBasicGroup::ID;

void updateBasicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBasicGroup");
    s.store_object_field("basic_group", static_cast<const BaseObject *>(basic_group_.get()));
    s.store_class_end();
  }
}

updateSupergroup::updateSupergroup()
  : supergroup_()
{}

updateSupergroup::updateSupergroup(object_ptr<supergroup> &&supergroup_)
  : supergroup_(std::move(supergroup_))
{}

const std::int32_t updateSupergroup::ID;

void updateSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSupergroup");
    s.store_object_field("supergroup", static_cast<const BaseObject *>(supergroup_.get()));
    s.store_class_end();
  }
}

updateSecretChat::updateSecretChat()
  : secret_chat_()
{}

updateSecretChat::updateSecretChat(object_ptr<secretChat> &&secret_chat_)
  : secret_chat_(std::move(secret_chat_))
{}

const std::int32_t updateSecretChat::ID;

void updateSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSecretChat");
    s.store_object_field("secret_chat", static_cast<const BaseObject *>(secret_chat_.get()));
    s.store_class_end();
  }
}

updateUserFullInfo::updateUserFullInfo()
  : user_id_()
  , user_full_info_()
{}

updateUserFullInfo::updateUserFullInfo(int53 user_id_, object_ptr<userFullInfo> &&user_full_info_)
  : user_id_(user_id_)
  , user_full_info_(std::move(user_full_info_))
{}

const std::int32_t updateUserFullInfo::ID;

void updateUserFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserFullInfo");
    s.store_field("user_id", user_id_);
    s.store_object_field("user_full_info", static_cast<const BaseObject *>(user_full_info_.get()));
    s.store_class_end();
  }
}

updateBasicGroupFullInfo::updateBasicGroupFullInfo()
  : basic_group_id_()
  , basic_group_full_info_()
{}

updateBasicGroupFullInfo::updateBasicGroupFullInfo(int53 basic_group_id_, object_ptr<basicGroupFullInfo> &&basic_group_full_info_)
  : basic_group_id_(basic_group_id_)
  , basic_group_full_info_(std::move(basic_group_full_info_))
{}

const std::int32_t updateBasicGroupFullInfo::ID;

void updateBasicGroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBasicGroupFullInfo");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_object_field("basic_group_full_info", static_cast<const BaseObject *>(basic_group_full_info_.get()));
    s.store_class_end();
  }
}

updateSupergroupFullInfo::updateSupergroupFullInfo()
  : supergroup_id_()
  , supergroup_full_info_()
{}

updateSupergroupFullInfo::updateSupergroupFullInfo(int53 supergroup_id_, object_ptr<supergroupFullInfo> &&supergroup_full_info_)
  : supergroup_id_(supergroup_id_)
  , supergroup_full_info_(std::move(supergroup_full_info_))
{}

const std::int32_t updateSupergroupFullInfo::ID;

void updateSupergroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSupergroupFullInfo");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_object_field("supergroup_full_info", static_cast<const BaseObject *>(supergroup_full_info_.get()));
    s.store_class_end();
  }
}

updateCommunityFullInfo::updateCommunityFullInfo()
  : community_id_()
  , community_full_info_()
{}

updateCommunityFullInfo::updateCommunityFullInfo(int53 community_id_, object_ptr<communityFullInfo> &&community_full_info_)
  : community_id_(community_id_)
  , community_full_info_(std::move(community_full_info_))
{}

const std::int32_t updateCommunityFullInfo::ID;

void updateCommunityFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateCommunityFullInfo");
    s.store_field("community_id", community_id_);
    s.store_object_field("community_full_info", static_cast<const BaseObject *>(community_full_info_.get()));
    s.store_class_end();
  }
}

updateServiceNotification::updateServiceNotification()
  : type_()
  , content_()
{}

updateServiceNotification::updateServiceNotification(string const &type_, object_ptr<MessageContent> &&content_)
  : type_(type_)
  , content_(std::move(content_))
{}

const std::int32_t updateServiceNotification::ID;

void updateServiceNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateServiceNotification");
    s.store_field("type", type_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

updateNewOauthRequest::updateNewOauthRequest()
  : domain_()
  , location_()
  , url_()
{}

updateNewOauthRequest::updateNewOauthRequest(string const &domain_, string const &location_, string const &url_)
  : domain_(domain_)
  , location_(location_)
  , url_(url_)
{}

const std::int32_t updateNewOauthRequest::ID;

void updateNewOauthRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewOauthRequest");
    s.store_field("domain", domain_);
    s.store_field("location", location_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

updateFile::updateFile()
  : file_()
{}

updateFile::updateFile(object_ptr<file> &&file_)
  : file_(std::move(file_))
{}

const std::int32_t updateFile::ID;

void updateFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFile");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

updateFileGenerationStart::updateFileGenerationStart()
  : generation_id_()
  , original_path_()
  , destination_path_()
  , conversion_()
{}

updateFileGenerationStart::updateFileGenerationStart(int64 generation_id_, string const &original_path_, string const &destination_path_, string const &conversion_)
  : generation_id_(generation_id_)
  , original_path_(original_path_)
  , destination_path_(destination_path_)
  , conversion_(conversion_)
{}

const std::int32_t updateFileGenerationStart::ID;

void updateFileGenerationStart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileGenerationStart");
    s.store_field("generation_id", generation_id_);
    s.store_field("original_path", original_path_);
    s.store_field("destination_path", destination_path_);
    s.store_field("conversion", conversion_);
    s.store_class_end();
  }
}

updateFileGenerationStop::updateFileGenerationStop()
  : generation_id_()
{}

updateFileGenerationStop::updateFileGenerationStop(int64 generation_id_)
  : generation_id_(generation_id_)
{}

const std::int32_t updateFileGenerationStop::ID;

void updateFileGenerationStop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileGenerationStop");
    s.store_field("generation_id", generation_id_);
    s.store_class_end();
  }
}

updateFileDownloads::updateFileDownloads()
  : total_size_()
  , total_count_()
  , downloaded_size_()
{}

updateFileDownloads::updateFileDownloads(int53 total_size_, int32 total_count_, int53 downloaded_size_)
  : total_size_(total_size_)
  , total_count_(total_count_)
  , downloaded_size_(downloaded_size_)
{}

const std::int32_t updateFileDownloads::ID;

void updateFileDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileDownloads");
    s.store_field("total_size", total_size_);
    s.store_field("total_count", total_count_);
    s.store_field("downloaded_size", downloaded_size_);
    s.store_class_end();
  }
}

updateFileAddedToDownloads::updateFileAddedToDownloads()
  : file_download_()
  , counts_()
{}

updateFileAddedToDownloads::updateFileAddedToDownloads(object_ptr<fileDownload> &&file_download_, object_ptr<downloadedFileCounts> &&counts_)
  : file_download_(std::move(file_download_))
  , counts_(std::move(counts_))
{}

const std::int32_t updateFileAddedToDownloads::ID;

void updateFileAddedToDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileAddedToDownloads");
    s.store_object_field("file_download", static_cast<const BaseObject *>(file_download_.get()));
    s.store_object_field("counts", static_cast<const BaseObject *>(counts_.get()));
    s.store_class_end();
  }
}

updateFileDownload::updateFileDownload()
  : file_id_()
  , complete_date_()
  , is_paused_()
  , counts_()
{}

updateFileDownload::updateFileDownload(int32 file_id_, int32 complete_date_, bool is_paused_, object_ptr<downloadedFileCounts> &&counts_)
  : file_id_(file_id_)
  , complete_date_(complete_date_)
  , is_paused_(is_paused_)
  , counts_(std::move(counts_))
{}

const std::int32_t updateFileDownload::ID;

void updateFileDownload::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileDownload");
    s.store_field("file_id", file_id_);
    s.store_field("complete_date", complete_date_);
    s.store_field("is_paused", is_paused_);
    s.store_object_field("counts", static_cast<const BaseObject *>(counts_.get()));
    s.store_class_end();
  }
}

updateFileRemovedFromDownloads::updateFileRemovedFromDownloads()
  : file_id_()
  , counts_()
{}

updateFileRemovedFromDownloads::updateFileRemovedFromDownloads(int32 file_id_, object_ptr<downloadedFileCounts> &&counts_)
  : file_id_(file_id_)
  , counts_(std::move(counts_))
{}

const std::int32_t updateFileRemovedFromDownloads::ID;

void updateFileRemovedFromDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileRemovedFromDownloads");
    s.store_field("file_id", file_id_);
    s.store_object_field("counts", static_cast<const BaseObject *>(counts_.get()));
    s.store_class_end();
  }
}

updateApplicationVerificationRequired::updateApplicationVerificationRequired()
  : verification_id_()
  , nonce_()
  , cloud_project_number_()
{}

updateApplicationVerificationRequired::updateApplicationVerificationRequired(int53 verification_id_, string const &nonce_, int64 cloud_project_number_)
  : verification_id_(verification_id_)
  , nonce_(nonce_)
  , cloud_project_number_(cloud_project_number_)
{}

const std::int32_t updateApplicationVerificationRequired::ID;

void updateApplicationVerificationRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateApplicationVerificationRequired");
    s.store_field("verification_id", verification_id_);
    s.store_field("nonce", nonce_);
    s.store_field("cloud_project_number", cloud_project_number_);
    s.store_class_end();
  }
}

updateApplicationRecaptchaVerificationRequired::updateApplicationRecaptchaVerificationRequired()
  : verification_id_()
  , action_()
  , recaptcha_key_id_()
{}

updateApplicationRecaptchaVerificationRequired::updateApplicationRecaptchaVerificationRequired(int53 verification_id_, string const &action_, string const &recaptcha_key_id_)
  : verification_id_(verification_id_)
  , action_(action_)
  , recaptcha_key_id_(recaptcha_key_id_)
{}

const std::int32_t updateApplicationRecaptchaVerificationRequired::ID;

void updateApplicationRecaptchaVerificationRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateApplicationRecaptchaVerificationRequired");
    s.store_field("verification_id", verification_id_);
    s.store_field("action", action_);
    s.store_field("recaptcha_key_id", recaptcha_key_id_);
    s.store_class_end();
  }
}

updateCall::updateCall()
  : call_()
{}

updateCall::updateCall(object_ptr<call> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t updateCall::ID;

void updateCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

updateGroupCall::updateGroupCall()
  : group_call_()
{}

updateGroupCall::updateGroupCall(object_ptr<groupCall> &&group_call_)
  : group_call_(std::move(group_call_))
{}

const std::int32_t updateGroupCall::ID;

void updateGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCall");
    s.store_object_field("group_call", static_cast<const BaseObject *>(group_call_.get()));
    s.store_class_end();
  }
}

updateGroupCallParticipant::updateGroupCallParticipant()
  : group_call_id_()
  , participant_()
{}

updateGroupCallParticipant::updateGroupCallParticipant(int32 group_call_id_, object_ptr<groupCallParticipant> &&participant_)
  : group_call_id_(group_call_id_)
  , participant_(std::move(participant_))
{}

const std::int32_t updateGroupCallParticipant::ID;

void updateGroupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallParticipant");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

updateGroupCallParticipants::updateGroupCallParticipants()
  : group_call_id_()
  , participant_user_ids_()
{}

updateGroupCallParticipants::updateGroupCallParticipants(int32 group_call_id_, array<int64> &&participant_user_ids_)
  : group_call_id_(group_call_id_)
  , participant_user_ids_(std::move(participant_user_ids_))
{}

const std::int32_t updateGroupCallParticipants::ID;

void updateGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallParticipants");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("participant_user_ids", participant_user_ids_.size()); for (const auto &_value : participant_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateGroupCallVerificationState::updateGroupCallVerificationState()
  : group_call_id_()
  , generation_()
  , emojis_()
{}

updateGroupCallVerificationState::updateGroupCallVerificationState(int32 group_call_id_, int32 generation_, array<string> &&emojis_)
  : group_call_id_(group_call_id_)
  , generation_(generation_)
  , emojis_(std::move(emojis_))
{}

const std::int32_t updateGroupCallVerificationState::ID;

void updateGroupCallVerificationState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallVerificationState");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("generation", generation_);
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateNewGroupCallMessage::updateNewGroupCallMessage()
  : group_call_id_()
  , message_()
{}

updateNewGroupCallMessage::updateNewGroupCallMessage(int32 group_call_id_, object_ptr<groupCallMessage> &&message_)
  : group_call_id_(group_call_id_)
  , message_(std::move(message_))
{}

const std::int32_t updateNewGroupCallMessage::ID;

void updateNewGroupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewGroupCallMessage");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateNewGroupCallPaidReaction::updateNewGroupCallPaidReaction()
  : group_call_id_()
  , sender_id_()
  , star_count_()
{}

updateNewGroupCallPaidReaction::updateNewGroupCallPaidReaction(int32 group_call_id_, object_ptr<MessageSender> &&sender_id_, int53 star_count_)
  : group_call_id_(group_call_id_)
  , sender_id_(std::move(sender_id_))
  , star_count_(star_count_)
{}

const std::int32_t updateNewGroupCallPaidReaction::ID;

void updateNewGroupCallPaidReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewGroupCallPaidReaction");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

updateGroupCallMessageSendFailed::updateGroupCallMessageSendFailed()
  : group_call_id_()
  , message_id_()
  , error_()
{}

updateGroupCallMessageSendFailed::updateGroupCallMessageSendFailed(int32 group_call_id_, int32 message_id_, object_ptr<error> &&error_)
  : group_call_id_(group_call_id_)
  , message_id_(message_id_)
  , error_(std::move(error_))
{}

const std::int32_t updateGroupCallMessageSendFailed::ID;

void updateGroupCallMessageSendFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallMessageSendFailed");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

updateGroupCallMessagesDeleted::updateGroupCallMessagesDeleted()
  : group_call_id_()
  , message_ids_()
{}

updateGroupCallMessagesDeleted::updateGroupCallMessagesDeleted(int32 group_call_id_, array<int32> &&message_ids_)
  : group_call_id_(group_call_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t updateGroupCallMessagesDeleted::ID;

void updateGroupCallMessagesDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallMessagesDeleted");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateLiveStoryTopDonors::updateLiveStoryTopDonors()
  : group_call_id_()
  , donors_()
{}

updateLiveStoryTopDonors::updateLiveStoryTopDonors(int32 group_call_id_, object_ptr<liveStoryDonors> &&donors_)
  : group_call_id_(group_call_id_)
  , donors_(std::move(donors_))
{}

const std::int32_t updateLiveStoryTopDonors::ID;

void updateLiveStoryTopDonors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateLiveStoryTopDonors");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("donors", static_cast<const BaseObject *>(donors_.get()));
    s.store_class_end();
  }
}

updateNewCallSignalingData::updateNewCallSignalingData()
  : call_id_()
  , data_()
{}

updateNewCallSignalingData::updateNewCallSignalingData(int32 call_id_, bytes const &data_)
  : call_id_(call_id_)
  , data_(std::move(data_))
{}

const std::int32_t updateNewCallSignalingData::ID;

void updateNewCallSignalingData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCallSignalingData");
    s.store_field("call_id", call_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

updateGiftAuctionState::updateGiftAuctionState()
  : state_()
{}

updateGiftAuctionState::updateGiftAuctionState(object_ptr<giftAuctionState> &&state_)
  : state_(std::move(state_))
{}

const std::int32_t updateGiftAuctionState::ID;

void updateGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGiftAuctionState");
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

updateActiveGiftAuctions::updateActiveGiftAuctions()
  : states_()
{}

updateActiveGiftAuctions::updateActiveGiftAuctions(array<object_ptr<giftAuctionState>> &&states_)
  : states_(std::move(states_))
{}

const std::int32_t updateActiveGiftAuctions::ID;

void updateActiveGiftAuctions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateActiveGiftAuctions");
    { s.store_vector_begin("states", states_.size()); for (const auto &_value : states_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateUserPrivacySettingRules::updateUserPrivacySettingRules()
  : setting_()
  , rules_()
{}

updateUserPrivacySettingRules::updateUserPrivacySettingRules(object_ptr<UserPrivacySetting> &&setting_, object_ptr<userPrivacySettingRules> &&rules_)
  : setting_(std::move(setting_))
  , rules_(std::move(rules_))
{}

const std::int32_t updateUserPrivacySettingRules::ID;

void updateUserPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserPrivacySettingRules");
    s.store_object_field("setting", static_cast<const BaseObject *>(setting_.get()));
    s.store_object_field("rules", static_cast<const BaseObject *>(rules_.get()));
    s.store_class_end();
  }
}

updateUnreadMessageCount::updateUnreadMessageCount()
  : chat_list_()
  , unread_count_()
  , unread_unmuted_count_()
{}

updateUnreadMessageCount::updateUnreadMessageCount(object_ptr<ChatList> &&chat_list_, int32 unread_count_, int32 unread_unmuted_count_)
  : chat_list_(std::move(chat_list_))
  , unread_count_(unread_count_)
  , unread_unmuted_count_(unread_unmuted_count_)
{}

const std::int32_t updateUnreadMessageCount::ID;

void updateUnreadMessageCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUnreadMessageCount");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_unmuted_count", unread_unmuted_count_);
    s.store_class_end();
  }
}

updateUnreadChatCount::updateUnreadChatCount()
  : chat_list_()
  , total_count_()
  , unread_count_()
  , unread_unmuted_count_()
  , marked_as_unread_count_()
  , marked_as_unread_unmuted_count_()
{}

updateUnreadChatCount::updateUnreadChatCount(object_ptr<ChatList> &&chat_list_, int32 total_count_, int32 unread_count_, int32 unread_unmuted_count_, int32 marked_as_unread_count_, int32 marked_as_unread_unmuted_count_)
  : chat_list_(std::move(chat_list_))
  , total_count_(total_count_)
  , unread_count_(unread_count_)
  , unread_unmuted_count_(unread_unmuted_count_)
  , marked_as_unread_count_(marked_as_unread_count_)
  , marked_as_unread_unmuted_count_(marked_as_unread_unmuted_count_)
{}

const std::int32_t updateUnreadChatCount::ID;

void updateUnreadChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUnreadChatCount");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("total_count", total_count_);
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_unmuted_count", unread_unmuted_count_);
    s.store_field("marked_as_unread_count", marked_as_unread_count_);
    s.store_field("marked_as_unread_unmuted_count", marked_as_unread_unmuted_count_);
    s.store_class_end();
  }
}

updateChatJoinResult::updateChatJoinResult()
  : query_id_()
  , chat_id_()
  , result_()
{}

updateChatJoinResult::updateChatJoinResult(int64 query_id_, int53 chat_id_, object_ptr<ChatJoinRequestResult> &&result_)
  : query_id_(query_id_)
  , chat_id_(chat_id_)
  , result_(std::move(result_))
{}

const std::int32_t updateChatJoinResult::ID;

void updateChatJoinResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatJoinResult");
    s.store_field("query_id", query_id_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_class_end();
  }
}

updateStory::updateStory()
  : story_()
{}

updateStory::updateStory(object_ptr<story> &&story_)
  : story_(std::move(story_))
{}

const std::int32_t updateStory::ID;

void updateStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStory");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

updateStoryDeleted::updateStoryDeleted()
  : story_poster_chat_id_()
  , story_id_()
{}

updateStoryDeleted::updateStoryDeleted(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t updateStoryDeleted::ID;

void updateStoryDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryDeleted");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

updateStoryPostSucceeded::updateStoryPostSucceeded()
  : story_()
  , old_story_id_()
{}

updateStoryPostSucceeded::updateStoryPostSucceeded(object_ptr<story> &&story_, int32 old_story_id_)
  : story_(std::move(story_))
  , old_story_id_(old_story_id_)
{}

const std::int32_t updateStoryPostSucceeded::ID;

void updateStoryPostSucceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryPostSucceeded");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_field("old_story_id", old_story_id_);
    s.store_class_end();
  }
}

updateStoryPostFailed::updateStoryPostFailed()
  : story_()
  , error_()
  , error_type_()
{}

updateStoryPostFailed::updateStoryPostFailed(object_ptr<story> &&story_, object_ptr<error> &&error_, object_ptr<CanPostStoryResult> &&error_type_)
  : story_(std::move(story_))
  , error_(std::move(error_))
  , error_type_(std::move(error_type_))
{}

const std::int32_t updateStoryPostFailed::ID;

void updateStoryPostFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryPostFailed");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_object_field("error_type", static_cast<const BaseObject *>(error_type_.get()));
    s.store_class_end();
  }
}

updateChatActiveStories::updateChatActiveStories()
  : active_stories_()
{}

updateChatActiveStories::updateChatActiveStories(object_ptr<chatActiveStories> &&active_stories_)
  : active_stories_(std::move(active_stories_))
{}

const std::int32_t updateChatActiveStories::ID;

void updateChatActiveStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatActiveStories");
    s.store_object_field("active_stories", static_cast<const BaseObject *>(active_stories_.get()));
    s.store_class_end();
  }
}

updateStoryListChatCount::updateStoryListChatCount()
  : story_list_()
  , chat_count_()
{}

updateStoryListChatCount::updateStoryListChatCount(object_ptr<StoryList> &&story_list_, int32 chat_count_)
  : story_list_(std::move(story_list_))
  , chat_count_(chat_count_)
{}

const std::int32_t updateStoryListChatCount::ID;

void updateStoryListChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryListChatCount");
    s.store_object_field("story_list", static_cast<const BaseObject *>(story_list_.get()));
    s.store_field("chat_count", chat_count_);
    s.store_class_end();
  }
}

updateStoryStealthMode::updateStoryStealthMode()
  : active_until_date_()
  , cooldown_until_date_()
{}

updateStoryStealthMode::updateStoryStealthMode(int32 active_until_date_, int32 cooldown_until_date_)
  : active_until_date_(active_until_date_)
  , cooldown_until_date_(cooldown_until_date_)
{}

const std::int32_t updateStoryStealthMode::ID;

void updateStoryStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryStealthMode");
    s.store_field("active_until_date", active_until_date_);
    s.store_field("cooldown_until_date", cooldown_until_date_);
    s.store_class_end();
  }
}

updateAllowedBotUsernamePremiumSuffixes::updateAllowedBotUsernamePremiumSuffixes()
  : suffixes_()
{}

updateAllowedBotUsernamePremiumSuffixes::updateAllowedBotUsernamePremiumSuffixes(array<string> &&suffixes_)
  : suffixes_(std::move(suffixes_))
{}

const std::int32_t updateAllowedBotUsernamePremiumSuffixes::ID;

void updateAllowedBotUsernamePremiumSuffixes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAllowedBotUsernamePremiumSuffixes");
    { s.store_vector_begin("suffixes", suffixes_.size()); for (const auto &_value : suffixes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateTrustedMiniAppBots::updateTrustedMiniAppBots()
  : bot_user_ids_()
{}

updateTrustedMiniAppBots::updateTrustedMiniAppBots(array<int53> &&bot_user_ids_)
  : bot_user_ids_(std::move(bot_user_ids_))
{}

const std::int32_t updateTrustedMiniAppBots::ID;

void updateTrustedMiniAppBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTrustedMiniAppBots");
    { s.store_vector_begin("bot_user_ids", bot_user_ids_.size()); for (const auto &_value : bot_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateOption::updateOption()
  : name_()
  , value_()
{}

updateOption::updateOption(string const &name_, object_ptr<OptionValue> &&value_)
  : name_(name_)
  , value_(std::move(value_))
{}

const std::int32_t updateOption::ID;

void updateOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateOption");
    s.store_field("name", name_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

updateStickerSet::updateStickerSet()
  : sticker_set_()
{}

updateStickerSet::updateStickerSet(object_ptr<stickerSet> &&sticker_set_)
  : sticker_set_(std::move(sticker_set_))
{}

const std::int32_t updateStickerSet::ID;

void updateStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStickerSet");
    s.store_object_field("sticker_set", static_cast<const BaseObject *>(sticker_set_.get()));
    s.store_class_end();
  }
}

updateInstalledStickerSets::updateInstalledStickerSets()
  : sticker_type_()
  , sticker_set_ids_()
{}

updateInstalledStickerSets::updateInstalledStickerSets(object_ptr<StickerType> &&sticker_type_, array<int64> &&sticker_set_ids_)
  : sticker_type_(std::move(sticker_type_))
  , sticker_set_ids_(std::move(sticker_set_ids_))
{}

const std::int32_t updateInstalledStickerSets::ID;

void updateInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateInstalledStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    { s.store_vector_begin("sticker_set_ids", sticker_set_ids_.size()); for (const auto &_value : sticker_set_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateTrendingStickerSets::updateTrendingStickerSets()
  : sticker_type_()
  , sticker_sets_()
{}

updateTrendingStickerSets::updateTrendingStickerSets(object_ptr<StickerType> &&sticker_type_, object_ptr<trendingStickerSets> &&sticker_sets_)
  : sticker_type_(std::move(sticker_type_))
  , sticker_sets_(std::move(sticker_sets_))
{}

const std::int32_t updateTrendingStickerSets::ID;

void updateTrendingStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTrendingStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_object_field("sticker_sets", static_cast<const BaseObject *>(sticker_sets_.get()));
    s.store_class_end();
  }
}

updateRecentStickers::updateRecentStickers()
  : is_attached_()
  , sticker_ids_()
{}

updateRecentStickers::updateRecentStickers(bool is_attached_, array<int32> &&sticker_ids_)
  : is_attached_(is_attached_)
  , sticker_ids_(std::move(sticker_ids_))
{}

const std::int32_t updateRecentStickers::ID;

void updateRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateRecentStickers");
    s.store_field("is_attached", is_attached_);
    { s.store_vector_begin("sticker_ids", sticker_ids_.size()); for (const auto &_value : sticker_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateFavoriteStickers::updateFavoriteStickers()
  : sticker_ids_()
{}

updateFavoriteStickers::updateFavoriteStickers(array<int32> &&sticker_ids_)
  : sticker_ids_(std::move(sticker_ids_))
{}

const std::int32_t updateFavoriteStickers::ID;

void updateFavoriteStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFavoriteStickers");
    { s.store_vector_begin("sticker_ids", sticker_ids_.size()); for (const auto &_value : sticker_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSavedAnimations::updateSavedAnimations()
  : animation_ids_()
{}

updateSavedAnimations::updateSavedAnimations(array<int32> &&animation_ids_)
  : animation_ids_(std::move(animation_ids_))
{}

const std::int32_t updateSavedAnimations::ID;

void updateSavedAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedAnimations");
    { s.store_vector_begin("animation_ids", animation_ids_.size()); for (const auto &_value : animation_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSavedNotificationSounds::updateSavedNotificationSounds()
  : notification_sound_ids_()
{}

updateSavedNotificationSounds::updateSavedNotificationSounds(array<int64> &&notification_sound_ids_)
  : notification_sound_ids_(std::move(notification_sound_ids_))
{}

const std::int32_t updateSavedNotificationSounds::ID;

void updateSavedNotificationSounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedNotificationSounds");
    { s.store_vector_begin("notification_sound_ids", notification_sound_ids_.size()); for (const auto &_value : notification_sound_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateDefaultBackground::updateDefaultBackground()
  : for_dark_theme_()
  , background_()
{}

updateDefaultBackground::updateDefaultBackground(bool for_dark_theme_, object_ptr<background> &&background_)
  : for_dark_theme_(for_dark_theme_)
  , background_(std::move(background_))
{}

const std::int32_t updateDefaultBackground::ID;

void updateDefaultBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDefaultBackground");
    s.store_field("for_dark_theme", for_dark_theme_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_class_end();
  }
}

updateEmojiChatThemes::updateEmojiChatThemes()
  : chat_themes_()
{}

updateEmojiChatThemes::updateEmojiChatThemes(array<object_ptr<emojiChatTheme>> &&chat_themes_)
  : chat_themes_(std::move(chat_themes_))
{}

const std::int32_t updateEmojiChatThemes::ID;

void updateEmojiChatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEmojiChatThemes");
    { s.store_vector_begin("chat_themes", chat_themes_.size()); for (const auto &_value : chat_themes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateAccentColors::updateAccentColors()
  : colors_()
  , available_accent_color_ids_()
{}

updateAccentColors::updateAccentColors(array<object_ptr<accentColor>> &&colors_, array<int32> &&available_accent_color_ids_)
  : colors_(std::move(colors_))
  , available_accent_color_ids_(std::move(available_accent_color_ids_))
{}

const std::int32_t updateAccentColors::ID;

void updateAccentColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAccentColors");
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("available_accent_color_ids", available_accent_color_ids_.size()); for (const auto &_value : available_accent_color_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateProfileAccentColors::updateProfileAccentColors()
  : colors_()
  , available_accent_color_ids_()
{}

updateProfileAccentColors::updateProfileAccentColors(array<object_ptr<profileAccentColor>> &&colors_, array<int32> &&available_accent_color_ids_)
  : colors_(std::move(colors_))
  , available_accent_color_ids_(std::move(available_accent_color_ids_))
{}

const std::int32_t updateProfileAccentColors::ID;

void updateProfileAccentColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateProfileAccentColors");
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("available_accent_color_ids", available_accent_color_ids_.size()); for (const auto &_value : available_accent_color_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateWebBrowserSettings::updateWebBrowserSettings()
  : settings_()
{}

updateWebBrowserSettings::updateWebBrowserSettings(object_ptr<webBrowserSettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t updateWebBrowserSettings::ID;

void updateWebBrowserSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebBrowserSettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

updateLanguagePackStrings::updateLanguagePackStrings()
  : localization_target_()
  , language_pack_id_()
  , strings_()
{}

updateLanguagePackStrings::updateLanguagePackStrings(string const &localization_target_, string const &language_pack_id_, array<object_ptr<languagePackString>> &&strings_)
  : localization_target_(localization_target_)
  , language_pack_id_(language_pack_id_)
  , strings_(std::move(strings_))
{}

const std::int32_t updateLanguagePackStrings::ID;

void updateLanguagePackStrings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateLanguagePackStrings");
    s.store_field("localization_target", localization_target_);
    s.store_field("language_pack_id", language_pack_id_);
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateConnectionState::updateConnectionState()
  : state_()
{}

updateConnectionState::updateConnectionState(object_ptr<ConnectionState> &&state_)
  : state_(std::move(state_))
{}

const std::int32_t updateConnectionState::ID;

void updateConnectionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateConnectionState");
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

updateWebProxyCarrierOpened::updateWebProxyCarrierOpened()
  : carrier_()
{}

updateWebProxyCarrierOpened::updateWebProxyCarrierOpened(object_ptr<webProxyCarrier> &&carrier_)
  : carrier_(std::move(carrier_))
{}

const std::int32_t updateWebProxyCarrierOpened::ID;

void updateWebProxyCarrierOpened::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebProxyCarrierOpened");
    s.store_object_field("carrier", static_cast<const BaseObject *>(carrier_.get()));
    s.store_class_end();
  }
}

updateWebProxyCarrierData::updateWebProxyCarrierData()
  : carrier_id_()
  , data_()
{}

updateWebProxyCarrierData::updateWebProxyCarrierData(int32 carrier_id_, bytes const &data_)
  : carrier_id_(carrier_id_)
  , data_(std::move(data_))
{}

const std::int32_t updateWebProxyCarrierData::ID;

void updateWebProxyCarrierData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebProxyCarrierData");
    s.store_field("carrier_id", carrier_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

updateWebProxyCarrierClosed::updateWebProxyCarrierClosed()
  : carrier_id_()
{}

updateWebProxyCarrierClosed::updateWebProxyCarrierClosed(int32 carrier_id_)
  : carrier_id_(carrier_id_)
{}

const std::int32_t updateWebProxyCarrierClosed::ID;

void updateWebProxyCarrierClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebProxyCarrierClosed");
    s.store_field("carrier_id", carrier_id_);
    s.store_class_end();
  }
}

updateFreezeState::updateFreezeState()
  : is_frozen_()
  , freezing_date_()
  , deletion_date_()
  , appeal_link_()
{}

updateFreezeState::updateFreezeState(bool is_frozen_, int32 freezing_date_, int32 deletion_date_, string const &appeal_link_)
  : is_frozen_(is_frozen_)
  , freezing_date_(freezing_date_)
  , deletion_date_(deletion_date_)
  , appeal_link_(appeal_link_)
{}

const std::int32_t updateFreezeState::ID;

void updateFreezeState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFreezeState");
    s.store_field("is_frozen", is_frozen_);
    s.store_field("freezing_date", freezing_date_);
    s.store_field("deletion_date", deletion_date_);
    s.store_field("appeal_link", appeal_link_);
    s.store_class_end();
  }
}

updateAgeVerificationParameters::updateAgeVerificationParameters()
  : parameters_()
{}

updateAgeVerificationParameters::updateAgeVerificationParameters(object_ptr<ageVerificationParameters> &&parameters_)
  : parameters_(std::move(parameters_))
{}

const std::int32_t updateAgeVerificationParameters::ID;

void updateAgeVerificationParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAgeVerificationParameters");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

updateTermsOfService::updateTermsOfService()
  : terms_of_service_id_()
  , terms_of_service_()
{}

updateTermsOfService::updateTermsOfService(string const &terms_of_service_id_, object_ptr<termsOfService> &&terms_of_service_)
  : terms_of_service_id_(terms_of_service_id_)
  , terms_of_service_(std::move(terms_of_service_))
{}

const std::int32_t updateTermsOfService::ID;

void updateTermsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTermsOfService");
    s.store_field("terms_of_service_id", terms_of_service_id_);
    s.store_object_field("terms_of_service", static_cast<const BaseObject *>(terms_of_service_.get()));
    s.store_class_end();
  }
}

updateUnconfirmedSession::updateUnconfirmedSession()
  : session_()
  , unconfirmed_session_count_()
{}

updateUnconfirmedSession::updateUnconfirmedSession(object_ptr<unconfirmedSession> &&session_, int32 unconfirmed_session_count_)
  : session_(std::move(session_))
  , unconfirmed_session_count_(unconfirmed_session_count_)
{}

const std::int32_t updateUnconfirmedSession::ID;

void updateUnconfirmedSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUnconfirmedSession");
    s.store_object_field("session", static_cast<const BaseObject *>(session_.get()));
    s.store_field("unconfirmed_session_count", unconfirmed_session_count_);
    s.store_class_end();
  }
}

updateAttachmentMenuBots::updateAttachmentMenuBots()
  : bots_()
{}

updateAttachmentMenuBots::updateAttachmentMenuBots(array<object_ptr<attachmentMenuBot>> &&bots_)
  : bots_(std::move(bots_))
{}

const std::int32_t updateAttachmentMenuBots::ID;

void updateAttachmentMenuBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAttachmentMenuBots");
    { s.store_vector_begin("bots", bots_.size()); for (const auto &_value : bots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateWebAppMessageSent::updateWebAppMessageSent()
  : web_app_launch_id_()
{}

updateWebAppMessageSent::updateWebAppMessageSent(int64 web_app_launch_id_)
  : web_app_launch_id_(web_app_launch_id_)
{}

const std::int32_t updateWebAppMessageSent::ID;

void updateWebAppMessageSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebAppMessageSent");
    s.store_field("web_app_launch_id", web_app_launch_id_);
    s.store_class_end();
  }
}

updateActiveEmojiReactions::updateActiveEmojiReactions()
  : emojis_()
{}

updateActiveEmojiReactions::updateActiveEmojiReactions(array<string> &&emojis_)
  : emojis_(std::move(emojis_))
{}

const std::int32_t updateActiveEmojiReactions::ID;

void updateActiveEmojiReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateActiveEmojiReactions");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateAvailableMessageEffects::updateAvailableMessageEffects()
  : reaction_effect_ids_()
  , sticker_effect_ids_()
{}

updateAvailableMessageEffects::updateAvailableMessageEffects(array<int64> &&reaction_effect_ids_, array<int64> &&sticker_effect_ids_)
  : reaction_effect_ids_(std::move(reaction_effect_ids_))
  , sticker_effect_ids_(std::move(sticker_effect_ids_))
{}

const std::int32_t updateAvailableMessageEffects::ID;

void updateAvailableMessageEffects::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAvailableMessageEffects");
    { s.store_vector_begin("reaction_effect_ids", reaction_effect_ids_.size()); for (const auto &_value : reaction_effect_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("sticker_effect_ids", sticker_effect_ids_.size()); for (const auto &_value : sticker_effect_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateDefaultReactionType::updateDefaultReactionType()
  : reaction_type_()
{}

updateDefaultReactionType::updateDefaultReactionType(object_ptr<ReactionType> &&reaction_type_)
  : reaction_type_(std::move(reaction_type_))
{}

const std::int32_t updateDefaultReactionType::ID;

void updateDefaultReactionType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDefaultReactionType");
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_class_end();
  }
}

updateDefaultPaidReactionType::updateDefaultPaidReactionType()
  : type_()
{}

updateDefaultPaidReactionType::updateDefaultPaidReactionType(object_ptr<PaidReactionType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t updateDefaultPaidReactionType::ID;

void updateDefaultPaidReactionType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDefaultPaidReactionType");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

updateSavedMessagesTags::updateSavedMessagesTags()
  : saved_messages_topic_id_()
  , tags_()
{}

updateSavedMessagesTags::updateSavedMessagesTags(int53 saved_messages_topic_id_, object_ptr<savedMessagesTags> &&tags_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , tags_(std::move(tags_))
{}

const std::int32_t updateSavedMessagesTags::ID;

void updateSavedMessagesTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedMessagesTags");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_object_field("tags", static_cast<const BaseObject *>(tags_.get()));
    s.store_class_end();
  }
}

updateActiveLiveLocationMessages::updateActiveLiveLocationMessages()
  : messages_()
{}

updateActiveLiveLocationMessages::updateActiveLiveLocationMessages(array<object_ptr<message>> &&messages_)
  : messages_(std::move(messages_))
{}

const std::int32_t updateActiveLiveLocationMessages::ID;

void updateActiveLiveLocationMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateActiveLiveLocationMessages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateOwnedStarCount::updateOwnedStarCount()
  : star_amount_()
{}

updateOwnedStarCount::updateOwnedStarCount(object_ptr<starAmount> &&star_amount_)
  : star_amount_(std::move(star_amount_))
{}

const std::int32_t updateOwnedStarCount::ID;

void updateOwnedStarCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateOwnedStarCount");
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    s.store_class_end();
  }
}

updateOwnedGramCount::updateOwnedGramCount()
  : gram_amount_()
{}

updateOwnedGramCount::updateOwnedGramCount(int53 gram_amount_)
  : gram_amount_(gram_amount_)
{}

const std::int32_t updateOwnedGramCount::ID;

void updateOwnedGramCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateOwnedGramCount");
    s.store_field("gram_amount", gram_amount_);
    s.store_class_end();
  }
}

updateTonWalletState::updateTonWalletState()
  : state_()
{}

updateTonWalletState::updateTonWalletState(object_ptr<tonWalletState> &&state_)
  : state_(std::move(state_))
{}

const std::int32_t updateTonWalletState::ID;

void updateTonWalletState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTonWalletState");
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

updateTonWalletGaslessTransfersInfo::updateTonWalletGaslessTransfersInfo()
  : info_()
{}

updateTonWalletGaslessTransfersInfo::updateTonWalletGaslessTransfersInfo(object_ptr<tonWalletGaslessTransfersInfo> &&info_)
  : info_(std::move(info_))
{}

const std::int32_t updateTonWalletGaslessTransfersInfo::ID;

void updateTonWalletGaslessTransfersInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTonWalletGaslessTransfersInfo");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

updateTonWalletTonConnectSession::updateTonWalletTonConnectSession()
  : session_()
{}

updateTonWalletTonConnectSession::updateTonWalletTonConnectSession(object_ptr<tonConnectSession> &&session_)
  : session_(std::move(session_))
{}

const std::int32_t updateTonWalletTonConnectSession::ID;

void updateTonWalletTonConnectSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTonWalletTonConnectSession");
    s.store_object_field("session", static_cast<const BaseObject *>(session_.get()));
    s.store_class_end();
  }
}

updateTonWalletTonConnectSessionDisconnectRequired::updateTonWalletTonConnectSessionDisconnectRequired()
  : session_ids_()
{}

updateTonWalletTonConnectSessionDisconnectRequired::updateTonWalletTonConnectSessionDisconnectRequired(array<int64> &&session_ids_)
  : session_ids_(std::move(session_ids_))
{}

const std::int32_t updateTonWalletTonConnectSessionDisconnectRequired::ID;

void updateTonWalletTonConnectSessionDisconnectRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTonWalletTonConnectSessionDisconnectRequired");
    { s.store_vector_begin("session_ids", session_ids_.size()); for (const auto &_value : session_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateChatRevenueAmount::updateChatRevenueAmount()
  : chat_id_()
  , revenue_amount_()
{}

updateChatRevenueAmount::updateChatRevenueAmount(int53 chat_id_, object_ptr<chatRevenueAmount> &&revenue_amount_)
  : chat_id_(chat_id_)
  , revenue_amount_(std::move(revenue_amount_))
{}

const std::int32_t updateChatRevenueAmount::ID;

void updateChatRevenueAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatRevenueAmount");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("revenue_amount", static_cast<const BaseObject *>(revenue_amount_.get()));
    s.store_class_end();
  }
}

updateStarRevenueStatus::updateStarRevenueStatus()
  : owner_id_()
  , status_()
{}

updateStarRevenueStatus::updateStarRevenueStatus(object_ptr<MessageSender> &&owner_id_, object_ptr<starRevenueStatus> &&status_)
  : owner_id_(std::move(owner_id_))
  , status_(std::move(status_))
{}

const std::int32_t updateStarRevenueStatus::ID;

void updateStarRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarRevenueStatus");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

updateGramRevenueStatus::updateGramRevenueStatus()
  : status_()
{}

updateGramRevenueStatus::updateGramRevenueStatus(object_ptr<gramRevenueStatus> &&status_)
  : status_(std::move(status_))
{}

const std::int32_t updateGramRevenueStatus::ID;

void updateGramRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGramRevenueStatus");
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

updateSpeechRecognitionTrial::updateSpeechRecognitionTrial()
  : max_media_duration_()
  , weekly_count_()
  , left_count_()
  , next_reset_date_()
{}

updateSpeechRecognitionTrial::updateSpeechRecognitionTrial(int32 max_media_duration_, int32 weekly_count_, int32 left_count_, int32 next_reset_date_)
  : max_media_duration_(max_media_duration_)
  , weekly_count_(weekly_count_)
  , left_count_(left_count_)
  , next_reset_date_(next_reset_date_)
{}

const std::int32_t updateSpeechRecognitionTrial::ID;

void updateSpeechRecognitionTrial::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSpeechRecognitionTrial");
    s.store_field("max_media_duration", max_media_duration_);
    s.store_field("weekly_count", weekly_count_);
    s.store_field("left_count", left_count_);
    s.store_field("next_reset_date", next_reset_date_);
    s.store_class_end();
  }
}

updateSpeechRecognitionInFile::updateSpeechRecognitionInFile()
  : recognition_id_()
  , partial_text_()
{}

updateSpeechRecognitionInFile::updateSpeechRecognitionInFile(int64 recognition_id_, string const &partial_text_)
  : recognition_id_(recognition_id_)
  , partial_text_(partial_text_)
{}

const std::int32_t updateSpeechRecognitionInFile::ID;

void updateSpeechRecognitionInFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSpeechRecognitionInFile");
    s.store_field("recognition_id", recognition_id_);
    s.store_field("partial_text", partial_text_);
    s.store_class_end();
  }
}

updateGroupCallMessageLevels::updateGroupCallMessageLevels()
  : levels_()
{}

updateGroupCallMessageLevels::updateGroupCallMessageLevels(array<object_ptr<groupCallMessageLevel>> &&levels_)
  : levels_(std::move(levels_))
{}

const std::int32_t updateGroupCallMessageLevels::ID;

void updateGroupCallMessageLevels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallMessageLevels");
    { s.store_vector_begin("levels", levels_.size()); for (const auto &_value : levels_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateDiceEmojis::updateDiceEmojis()
  : emojis_()
{}

updateDiceEmojis::updateDiceEmojis(array<string> &&emojis_)
  : emojis_(std::move(emojis_))
{}

const std::int32_t updateDiceEmojis::ID;

void updateDiceEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDiceEmojis");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateStakeDiceState::updateStakeDiceState()
  : state_()
{}

updateStakeDiceState::updateStakeDiceState(object_ptr<stakeDiceState> &&state_)
  : state_(std::move(state_))
{}

const std::int32_t updateStakeDiceState::ID;

void updateStakeDiceState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStakeDiceState");
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

updateAnimatedEmojiMessageClicked::updateAnimatedEmojiMessageClicked()
  : chat_id_()
  , message_id_()
  , sticker_()
{}

updateAnimatedEmojiMessageClicked::updateAnimatedEmojiMessageClicked(int53 chat_id_, int53 message_id_, object_ptr<sticker> &&sticker_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t updateAnimatedEmojiMessageClicked::ID;

void updateAnimatedEmojiMessageClicked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAnimatedEmojiMessageClicked");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

updateAnimationSearchParameters::updateAnimationSearchParameters()
  : provider_()
  , emojis_()
{}

updateAnimationSearchParameters::updateAnimationSearchParameters(string const &provider_, array<string> &&emojis_)
  : provider_(provider_)
  , emojis_(std::move(emojis_))
{}

const std::int32_t updateAnimationSearchParameters::ID;

void updateAnimationSearchParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAnimationSearchParameters");
    s.store_field("provider", provider_);
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateTextCompositionStyles::updateTextCompositionStyles()
  : styles_()
{}

updateTextCompositionStyles::updateTextCompositionStyles(array<object_ptr<textCompositionStyle>> &&styles_)
  : styles_(std::move(styles_))
{}

const std::int32_t updateTextCompositionStyles::ID;

void updateTextCompositionStyles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTextCompositionStyles");
    { s.store_vector_begin("styles", styles_.size()); for (const auto &_value : styles_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSuggestedActions::updateSuggestedActions()
  : added_actions_()
  , removed_actions_()
{}

updateSuggestedActions::updateSuggestedActions(array<object_ptr<SuggestedAction>> &&added_actions_, array<object_ptr<SuggestedAction>> &&removed_actions_)
  : added_actions_(std::move(added_actions_))
  , removed_actions_(std::move(removed_actions_))
{}

const std::int32_t updateSuggestedActions::ID;

void updateSuggestedActions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSuggestedActions");
    { s.store_vector_begin("added_actions", added_actions_.size()); for (const auto &_value : added_actions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("removed_actions", removed_actions_.size()); for (const auto &_value : removed_actions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSpeedLimitNotification::updateSpeedLimitNotification()
  : is_upload_()
{}

updateSpeedLimitNotification::updateSpeedLimitNotification(bool is_upload_)
  : is_upload_(is_upload_)
{}

const std::int32_t updateSpeedLimitNotification::ID;

void updateSpeedLimitNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSpeedLimitNotification");
    s.store_field("is_upload", is_upload_);
    s.store_class_end();
  }
}

updateContactCloseBirthdays::updateContactCloseBirthdays()
  : close_birthday_users_()
{}

updateContactCloseBirthdays::updateContactCloseBirthdays(array<object_ptr<closeBirthdayUser>> &&close_birthday_users_)
  : close_birthday_users_(std::move(close_birthday_users_))
{}

const std::int32_t updateContactCloseBirthdays::ID;

void updateContactCloseBirthdays::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateContactCloseBirthdays");
    { s.store_vector_begin("close_birthday_users", close_birthday_users_.size()); for (const auto &_value : close_birthday_users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateAutosaveSettings::updateAutosaveSettings()
  : scope_()
  , settings_()
{}

updateAutosaveSettings::updateAutosaveSettings(object_ptr<AutosaveSettingsScope> &&scope_, object_ptr<scopeAutosaveSettings> &&settings_)
  : scope_(std::move(scope_))
  , settings_(std::move(settings_))
{}

const std::int32_t updateAutosaveSettings::ID;

void updateAutosaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAutosaveSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

updateBusinessConnection::updateBusinessConnection()
  : connection_()
{}

updateBusinessConnection::updateBusinessConnection(object_ptr<businessConnection> &&connection_)
  : connection_(std::move(connection_))
{}

const std::int32_t updateBusinessConnection::ID;

void updateBusinessConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBusinessConnection");
    s.store_object_field("connection", static_cast<const BaseObject *>(connection_.get()));
    s.store_class_end();
  }
}

updateNewBusinessMessage::updateNewBusinessMessage()
  : connection_id_()
  , message_()
{}

updateNewBusinessMessage::updateNewBusinessMessage(string const &connection_id_, object_ptr<businessMessage> &&message_)
  : connection_id_(connection_id_)
  , message_(std::move(message_))
{}

const std::int32_t updateNewBusinessMessage::ID;

void updateNewBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewBusinessMessage");
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateBusinessMessageEdited::updateBusinessMessageEdited()
  : connection_id_()
  , message_()
{}

updateBusinessMessageEdited::updateBusinessMessageEdited(string const &connection_id_, object_ptr<businessMessage> &&message_)
  : connection_id_(connection_id_)
  , message_(std::move(message_))
{}

const std::int32_t updateBusinessMessageEdited::ID;

void updateBusinessMessageEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBusinessMessageEdited");
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateBusinessMessagesDeleted::updateBusinessMessagesDeleted()
  : connection_id_()
  , chat_id_()
  , message_ids_()
{}

updateBusinessMessagesDeleted::updateBusinessMessagesDeleted(string const &connection_id_, int53 chat_id_, array<int53> &&message_ids_)
  : connection_id_(connection_id_)
  , chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t updateBusinessMessagesDeleted::ID;

void updateBusinessMessagesDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBusinessMessagesDeleted");
    s.store_field("connection_id", connection_id_);
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateNewInlineQuery::updateNewInlineQuery()
  : id_()
  , sender_user_id_()
  , user_location_()
  , chat_type_()
  , query_()
  , offset_()
{}

updateNewInlineQuery::updateNewInlineQuery(int64 id_, int53 sender_user_id_, object_ptr<location> &&user_location_, object_ptr<ChatType> &&chat_type_, string const &query_, string const &offset_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , user_location_(std::move(user_location_))
  , chat_type_(std::move(chat_type_))
  , query_(query_)
  , offset_(offset_)
{}

const std::int32_t updateNewInlineQuery::ID;

void updateNewInlineQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewInlineQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_object_field("user_location", static_cast<const BaseObject *>(user_location_.get()));
    s.store_object_field("chat_type", static_cast<const BaseObject *>(chat_type_.get()));
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

updateNewChosenInlineResult::updateNewChosenInlineResult()
  : sender_user_id_()
  , user_location_()
  , query_()
  , result_id_()
  , inline_message_id_()
{}

updateNewChosenInlineResult::updateNewChosenInlineResult(int53 sender_user_id_, object_ptr<location> &&user_location_, string const &query_, string const &result_id_, string const &inline_message_id_)
  : sender_user_id_(sender_user_id_)
  , user_location_(std::move(user_location_))
  , query_(query_)
  , result_id_(result_id_)
  , inline_message_id_(inline_message_id_)
{}

const std::int32_t updateNewChosenInlineResult::ID;

void updateNewChosenInlineResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewChosenInlineResult");
    s.store_field("sender_user_id", sender_user_id_);
    s.store_object_field("user_location", static_cast<const BaseObject *>(user_location_.get()));
    s.store_field("query", query_);
    s.store_field("result_id", result_id_);
    s.store_field("inline_message_id", inline_message_id_);
    s.store_class_end();
  }
}

updateNewGuestQuery::updateNewGuestQuery()
  : id_()
  , message_()
  , reference_messages_()
{}

updateNewGuestQuery::updateNewGuestQuery(int64 id_, object_ptr<message> &&message_, array<object_ptr<message>> &&reference_messages_)
  : id_(id_)
  , message_(std::move(message_))
  , reference_messages_(std::move(reference_messages_))
{}

const std::int32_t updateNewGuestQuery::ID;

void updateNewGuestQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewGuestQuery");
    s.store_field("id", id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    { s.store_vector_begin("reference_messages", reference_messages_.size()); for (const auto &_value : reference_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateNewCallbackQuery::updateNewCallbackQuery()
  : id_()
  , sender_user_id_()
  , chat_id_()
  , message_id_()
  , chat_instance_()
  , payload_()
{}

updateNewCallbackQuery::updateNewCallbackQuery(int64 id_, int53 sender_user_id_, int53 chat_id_, int53 message_id_, int64 chat_instance_, object_ptr<CallbackQueryPayload> &&payload_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , chat_instance_(chat_instance_)
  , payload_(std::move(payload_))
{}

const std::int32_t updateNewCallbackQuery::ID;

void updateNewCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCallbackQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("chat_instance", chat_instance_);
    s.store_object_field("payload", static_cast<const BaseObject *>(payload_.get()));
    s.store_class_end();
  }
}

updateNewInlineCallbackQuery::updateNewInlineCallbackQuery()
  : id_()
  , sender_user_id_()
  , inline_message_id_()
  , chat_instance_()
  , payload_()
{}

updateNewInlineCallbackQuery::updateNewInlineCallbackQuery(int64 id_, int53 sender_user_id_, string const &inline_message_id_, int64 chat_instance_, object_ptr<CallbackQueryPayload> &&payload_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , inline_message_id_(inline_message_id_)
  , chat_instance_(chat_instance_)
  , payload_(std::move(payload_))
{}

const std::int32_t updateNewInlineCallbackQuery::ID;

void updateNewInlineCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewInlineCallbackQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("inline_message_id", inline_message_id_);
    s.store_field("chat_instance", chat_instance_);
    s.store_object_field("payload", static_cast<const BaseObject *>(payload_.get()));
    s.store_class_end();
  }
}

updateNewBusinessCallbackQuery::updateNewBusinessCallbackQuery()
  : id_()
  , sender_user_id_()
  , connection_id_()
  , message_()
  , chat_instance_()
  , payload_()
{}

updateNewBusinessCallbackQuery::updateNewBusinessCallbackQuery(int64 id_, int53 sender_user_id_, string const &connection_id_, object_ptr<businessMessage> &&message_, int64 chat_instance_, object_ptr<CallbackQueryPayload> &&payload_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , connection_id_(connection_id_)
  , message_(std::move(message_))
  , chat_instance_(chat_instance_)
  , payload_(std::move(payload_))
{}

const std::int32_t updateNewBusinessCallbackQuery::ID;

void updateNewBusinessCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewBusinessCallbackQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("chat_instance", chat_instance_);
    s.store_object_field("payload", static_cast<const BaseObject *>(payload_.get()));
    s.store_class_end();
  }
}

updateNewWidgetQuery::updateNewWidgetQuery()
  : id_()
  , sender_user_id_()
  , chat_id_()
  , message_id_()
  , chat_instance_()
  , chat_type_()
  , query_type_()
  , data_()
  , widget_id_()
  , wallet_card_()
{}

updateNewWidgetQuery::updateNewWidgetQuery(int64 id_, int53 sender_user_id_, int53 chat_id_, int53 message_id_, int64 chat_instance_, string const &chat_type_, object_ptr<WidgetQueryType> &&query_type_, bytes const &data_, int64 widget_id_, object_ptr<tonWalletCard> &&wallet_card_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , chat_instance_(chat_instance_)
  , chat_type_(chat_type_)
  , query_type_(std::move(query_type_))
  , data_(std::move(data_))
  , widget_id_(widget_id_)
  , wallet_card_(std::move(wallet_card_))
{}

const std::int32_t updateNewWidgetQuery::ID;

void updateNewWidgetQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewWidgetQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("chat_instance", chat_instance_);
    s.store_field("chat_type", chat_type_);
    s.store_object_field("query_type", static_cast<const BaseObject *>(query_type_.get()));
    s.store_bytes_field("data", data_);
    s.store_field("widget_id", widget_id_);
    s.store_object_field("wallet_card", static_cast<const BaseObject *>(wallet_card_.get()));
    s.store_class_end();
  }
}

updateNewInlineWidgetQuery::updateNewInlineWidgetQuery()
  : id_()
  , sender_user_id_()
  , inline_message_id_()
  , chat_instance_()
  , chat_type_()
  , query_type_()
  , data_()
  , widget_id_()
  , wallet_card_()
{}

updateNewInlineWidgetQuery::updateNewInlineWidgetQuery(int64 id_, int53 sender_user_id_, string const &inline_message_id_, int64 chat_instance_, string const &chat_type_, object_ptr<WidgetQueryType> &&query_type_, bytes const &data_, int64 widget_id_, object_ptr<tonWalletCard> &&wallet_card_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , inline_message_id_(inline_message_id_)
  , chat_instance_(chat_instance_)
  , chat_type_(chat_type_)
  , query_type_(std::move(query_type_))
  , data_(std::move(data_))
  , widget_id_(widget_id_)
  , wallet_card_(std::move(wallet_card_))
{}

const std::int32_t updateNewInlineWidgetQuery::ID;

void updateNewInlineWidgetQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewInlineWidgetQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("inline_message_id", inline_message_id_);
    s.store_field("chat_instance", chat_instance_);
    s.store_field("chat_type", chat_type_);
    s.store_object_field("query_type", static_cast<const BaseObject *>(query_type_.get()));
    s.store_bytes_field("data", data_);
    s.store_field("widget_id", widget_id_);
    s.store_object_field("wallet_card", static_cast<const BaseObject *>(wallet_card_.get()));
    s.store_class_end();
  }
}

updateNewWidgetCopyQuery::updateNewWidgetCopyQuery()
  : id_()
  , sender_user_id_()
  , query_type_()
  , data_()
  , widget_id_()
  , wallet_card_()
{}

updateNewWidgetCopyQuery::updateNewWidgetCopyQuery(int64 id_, int53 sender_user_id_, object_ptr<WidgetQueryType> &&query_type_, bytes const &data_, int64 widget_id_, object_ptr<tonWalletCard> &&wallet_card_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , query_type_(std::move(query_type_))
  , data_(std::move(data_))
  , widget_id_(widget_id_)
  , wallet_card_(std::move(wallet_card_))
{}

const std::int32_t updateNewWidgetCopyQuery::ID;

void updateNewWidgetCopyQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewWidgetCopyQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_object_field("query_type", static_cast<const BaseObject *>(query_type_.get()));
    s.store_bytes_field("data", data_);
    s.store_field("widget_id", widget_id_);
    s.store_object_field("wallet_card", static_cast<const BaseObject *>(wallet_card_.get()));
    s.store_class_end();
  }
}

updateNewShippingQuery::updateNewShippingQuery()
  : id_()
  , sender_user_id_()
  , invoice_payload_()
  , shipping_address_()
{}

updateNewShippingQuery::updateNewShippingQuery(int64 id_, int53 sender_user_id_, string const &invoice_payload_, object_ptr<address> &&shipping_address_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , invoice_payload_(invoice_payload_)
  , shipping_address_(std::move(shipping_address_))
{}

const std::int32_t updateNewShippingQuery::ID;

void updateNewShippingQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewShippingQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("invoice_payload", invoice_payload_);
    s.store_object_field("shipping_address", static_cast<const BaseObject *>(shipping_address_.get()));
    s.store_class_end();
  }
}

updateNewPreCheckoutQuery::updateNewPreCheckoutQuery()
  : id_()
  , sender_user_id_()
  , currency_()
  , total_amount_()
  , invoice_payload_()
  , shipping_option_id_()
  , order_info_()
{}

updateNewPreCheckoutQuery::updateNewPreCheckoutQuery(int64 id_, int53 sender_user_id_, string const &currency_, int53 total_amount_, bytes const &invoice_payload_, string const &shipping_option_id_, object_ptr<orderInfo> &&order_info_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , currency_(currency_)
  , total_amount_(total_amount_)
  , invoice_payload_(std::move(invoice_payload_))
  , shipping_option_id_(shipping_option_id_)
  , order_info_(std::move(order_info_))
{}

const std::int32_t updateNewPreCheckoutQuery::ID;

void updateNewPreCheckoutQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewPreCheckoutQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_field("shipping_option_id", shipping_option_id_);
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_class_end();
  }
}

updateNewCustomEvent::updateNewCustomEvent()
  : event_()
{}

updateNewCustomEvent::updateNewCustomEvent(string const &event_)
  : event_(event_)
{}

const std::int32_t updateNewCustomEvent::ID;

void updateNewCustomEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCustomEvent");
    s.store_field("event", event_);
    s.store_class_end();
  }
}

updateNewCustomQuery::updateNewCustomQuery()
  : id_()
  , data_()
  , timeout_()
{}

updateNewCustomQuery::updateNewCustomQuery(int64 id_, string const &data_, int32 timeout_)
  : id_(id_)
  , data_(data_)
  , timeout_(timeout_)
{}

const std::int32_t updateNewCustomQuery::ID;

void updateNewCustomQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCustomQuery");
    s.store_field("id", id_);
    s.store_field("data", data_);
    s.store_field("timeout", timeout_);
    s.store_class_end();
  }
}

updateUserSubscription::updateUserSubscription()
  : user_id_()
  , payload_()
  , is_canceled_()
  , is_restored_()
  , is_payment_failed_()
{}

updateUserSubscription::updateUserSubscription(int53 user_id_, string const &payload_, bool is_canceled_, bool is_restored_, bool is_payment_failed_)
  : user_id_(user_id_)
  , payload_(payload_)
  , is_canceled_(is_canceled_)
  , is_restored_(is_restored_)
  , is_payment_failed_(is_payment_failed_)
{}

const std::int32_t updateUserSubscription::ID;

void updateUserSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserSubscription");
    s.store_field("user_id", user_id_);
    s.store_field("payload", payload_);
    s.store_field("is_canceled", is_canceled_);
    s.store_field("is_restored", is_restored_);
    s.store_field("is_payment_failed", is_payment_failed_);
    s.store_class_end();
  }
}

updatePoll::updatePoll()
  : poll_()
{}

updatePoll::updatePoll(object_ptr<poll> &&poll_)
  : poll_(std::move(poll_))
{}

const std::int32_t updatePoll::ID;

void updatePoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePoll");
    s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get()));
    s.store_class_end();
  }
}

updatePollAnswer::updatePollAnswer()
  : poll_id_()
  , voter_id_()
  , option_ids_()
  , option_positions_()
{}

updatePollAnswer::updatePollAnswer(int64 poll_id_, object_ptr<MessageSender> &&voter_id_, array<string> &&option_ids_, array<int32> &&option_positions_)
  : poll_id_(poll_id_)
  , voter_id_(std::move(voter_id_))
  , option_ids_(std::move(option_ids_))
  , option_positions_(std::move(option_positions_))
{}

const std::int32_t updatePollAnswer::ID;

void updatePollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePollAnswer");
    s.store_field("poll_id", poll_id_);
    s.store_object_field("voter_id", static_cast<const BaseObject *>(voter_id_.get()));
    { s.store_vector_begin("option_ids", option_ids_.size()); for (const auto &_value : option_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("option_positions", option_positions_.size()); for (const auto &_value : option_positions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateManagedBot::updateManagedBot()
  : user_id_()
  , bot_user_id_()
{}

updateManagedBot::updateManagedBot(int53 user_id_, int53 bot_user_id_)
  : user_id_(user_id_)
  , bot_user_id_(bot_user_id_)
{}

const std::int32_t updateManagedBot::ID;

void updateManagedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateManagedBot");
    s.store_field("user_id", user_id_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

updateChatMember::updateChatMember()
  : chat_id_()
  , actor_user_id_()
  , date_()
  , invite_link_()
  , via_join_request_()
  , via_chat_folder_invite_link_()
  , old_chat_member_()
  , new_chat_member_()
{}

updateChatMember::updateChatMember(int53 chat_id_, int53 actor_user_id_, int32 date_, object_ptr<chatInviteLink> &&invite_link_, bool via_join_request_, bool via_chat_folder_invite_link_, object_ptr<chatMember> &&old_chat_member_, object_ptr<chatMember> &&new_chat_member_)
  : chat_id_(chat_id_)
  , actor_user_id_(actor_user_id_)
  , date_(date_)
  , invite_link_(std::move(invite_link_))
  , via_join_request_(via_join_request_)
  , via_chat_folder_invite_link_(via_chat_folder_invite_link_)
  , old_chat_member_(std::move(old_chat_member_))
  , new_chat_member_(std::move(new_chat_member_))
{}

const std::int32_t updateChatMember::ID;

void updateChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_field("actor_user_id", actor_user_id_);
    s.store_field("date", date_);
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_field("via_join_request", via_join_request_);
    s.store_field("via_chat_folder_invite_link", via_chat_folder_invite_link_);
    s.store_object_field("old_chat_member", static_cast<const BaseObject *>(old_chat_member_.get()));
    s.store_object_field("new_chat_member", static_cast<const BaseObject *>(new_chat_member_.get()));
    s.store_class_end();
  }
}

updateNewChatJoinRequest::updateNewChatJoinRequest()
  : chat_id_()
  , request_()
  , user_chat_id_()
  , invite_link_()
  , query_id_()
{}

updateNewChatJoinRequest::updateNewChatJoinRequest(int53 chat_id_, object_ptr<chatJoinRequest> &&request_, int53 user_chat_id_, object_ptr<chatInviteLink> &&invite_link_, int64 query_id_)
  : chat_id_(chat_id_)
  , request_(std::move(request_))
  , user_chat_id_(user_chat_id_)
  , invite_link_(std::move(invite_link_))
  , query_id_(query_id_)
{}

const std::int32_t updateNewChatJoinRequest::ID;

void updateNewChatJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewChatJoinRequest");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("request", static_cast<const BaseObject *>(request_.get()));
    s.store_field("user_chat_id", user_chat_id_);
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_field("query_id", query_id_);
    s.store_class_end();
  }
}

updateChatBoost::updateChatBoost()
  : chat_id_()
  , boost_()
{}

updateChatBoost::updateChatBoost(int53 chat_id_, object_ptr<chatBoost> &&boost_)
  : chat_id_(chat_id_)
  , boost_(std::move(boost_))
{}

const std::int32_t updateChatBoost::ID;

void updateChatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatBoost");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("boost", static_cast<const BaseObject *>(boost_.get()));
    s.store_class_end();
  }
}

updateMessageReaction::updateMessageReaction()
  : chat_id_()
  , message_id_()
  , actor_id_()
  , date_()
  , old_reaction_types_()
  , new_reaction_types_()
{}

updateMessageReaction::updateMessageReaction(int53 chat_id_, int53 message_id_, object_ptr<MessageSender> &&actor_id_, int32 date_, array<object_ptr<ReactionType>> &&old_reaction_types_, array<object_ptr<ReactionType>> &&new_reaction_types_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , actor_id_(std::move(actor_id_))
  , date_(date_)
  , old_reaction_types_(std::move(old_reaction_types_))
  , new_reaction_types_(std::move(new_reaction_types_))
{}

const std::int32_t updateMessageReaction::ID;

void updateMessageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageReaction");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("actor_id", static_cast<const BaseObject *>(actor_id_.get()));
    s.store_field("date", date_);
    { s.store_vector_begin("old_reaction_types", old_reaction_types_.size()); for (const auto &_value : old_reaction_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("new_reaction_types", new_reaction_types_.size()); for (const auto &_value : new_reaction_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateMessageReactions::updateMessageReactions()
  : chat_id_()
  , message_id_()
  , date_()
  , reactions_()
{}

updateMessageReactions::updateMessageReactions(int53 chat_id_, int53 message_id_, int32 date_, array<object_ptr<messageReaction>> &&reactions_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , date_(date_)
  , reactions_(std::move(reactions_))
{}

const std::int32_t updateMessageReactions::ID;

void updateMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("date", date_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updatePaidMediaPurchased::updatePaidMediaPurchased()
  : user_id_()
  , payload_()
{}

updatePaidMediaPurchased::updatePaidMediaPurchased(int53 user_id_, string const &payload_)
  : user_id_(user_id_)
  , payload_(payload_)
{}

const std::int32_t updatePaidMediaPurchased::ID;

void updatePaidMediaPurchased::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePaidMediaPurchased");
    s.store_field("user_id", user_id_);
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

upgradedGiftDepositInfo::upgradedGiftDepositInfo()
  : nft_address_()
  , payload_()
  , gram_amount_()
{}

upgradedGiftDepositInfo::upgradedGiftDepositInfo(string const &nft_address_, bytes const &payload_, int64 gram_amount_)
  : nft_address_(nft_address_)
  , payload_(std::move(payload_))
  , gram_amount_(gram_amount_)
{}

const std::int32_t upgradedGiftDepositInfo::ID;

void upgradedGiftDepositInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftDepositInfo");
    s.store_field("nft_address", nft_address_);
    s.store_bytes_field("payload", payload_);
    s.store_field("gram_amount", gram_amount_);
    s.store_class_end();
  }
}

acceptCall::acceptCall()
  : call_id_()
  , protocol_()
{}

acceptCall::acceptCall(int32 call_id_, object_ptr<callProtocol> &&protocol_)
  : call_id_(call_id_)
  , protocol_(std::move(protocol_))
{}

const std::int32_t acceptCall::ID;

void acceptCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "acceptCall");
    s.store_field("call_id", call_id_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

addBotSecondaryUsername::addBotSecondaryUsername()
  : bot_user_id_()
  , username_()
{}

addBotSecondaryUsername::addBotSecondaryUsername(int53 bot_user_id_, string const &username_)
  : bot_user_id_(bot_user_id_)
  , username_(username_)
{}

const std::int32_t addBotSecondaryUsername::ID;

void addBotSecondaryUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addBotSecondaryUsername");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("username", username_);
    s.store_class_end();
  }
}

addFileToDownloads::addFileToDownloads()
  : file_id_()
  , chat_id_()
  , message_id_()
  , priority_()
{}

addFileToDownloads::addFileToDownloads(int32 file_id_, int53 chat_id_, int53 message_id_, int32 priority_)
  : file_id_(file_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , priority_(priority_)
{}

const std::int32_t addFileToDownloads::ID;

void addFileToDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addFileToDownloads");
    s.store_field("file_id", file_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("priority", priority_);
    s.store_class_end();
  }
}

addSavedNotificationSound::addSavedNotificationSound()
  : sound_()
{}

addSavedNotificationSound::addSavedNotificationSound(object_ptr<InputFile> &&sound_)
  : sound_(std::move(sound_))
{}

const std::int32_t addSavedNotificationSound::ID;

void addSavedNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addSavedNotificationSound");
    s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get()));
    s.store_class_end();
  }
}

answerCallbackQuery::answerCallbackQuery()
  : callback_query_id_()
  , text_()
  , show_alert_()
  , url_()
  , cache_time_()
{}

answerCallbackQuery::answerCallbackQuery(int64 callback_query_id_, string const &text_, bool show_alert_, string const &url_, int32 cache_time_)
  : callback_query_id_(callback_query_id_)
  , text_(text_)
  , show_alert_(show_alert_)
  , url_(url_)
  , cache_time_(cache_time_)
{}

const std::int32_t answerCallbackQuery::ID;

void answerCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerCallbackQuery");
    s.store_field("callback_query_id", callback_query_id_);
    s.store_field("text", text_);
    s.store_field("show_alert", show_alert_);
    s.store_field("url", url_);
    s.store_field("cache_time", cache_time_);
    s.store_class_end();
  }
}

answerShippingQuery::answerShippingQuery()
  : shipping_query_id_()
  , shipping_options_()
  , error_message_()
{}

answerShippingQuery::answerShippingQuery(int64 shipping_query_id_, array<object_ptr<shippingOption>> &&shipping_options_, string const &error_message_)
  : shipping_query_id_(shipping_query_id_)
  , shipping_options_(std::move(shipping_options_))
  , error_message_(error_message_)
{}

const std::int32_t answerShippingQuery::ID;

void answerShippingQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerShippingQuery");
    s.store_field("shipping_query_id", shipping_query_id_);
    { s.store_vector_begin("shipping_options", shipping_options_.size()); for (const auto &_value : shipping_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

canPurchaseFromStore::canPurchaseFromStore()
  : purpose_()
{}

canPurchaseFromStore::canPurchaseFromStore(object_ptr<StorePaymentPurpose> &&purpose_)
  : purpose_(std::move(purpose_))
{}

const std::int32_t canPurchaseFromStore::ID;

void canPurchaseFromStore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPurchaseFromStore");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

canTransferOwnership::canTransferOwnership() {
}

const std::int32_t canTransferOwnership::ID;

void canTransferOwnership::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnership");
    s.store_class_end();
  }
}

cancelPreliminaryUploadFile::cancelPreliminaryUploadFile()
  : file_id_()
{}

cancelPreliminaryUploadFile::cancelPreliminaryUploadFile(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t cancelPreliminaryUploadFile::ID;

void cancelPreliminaryUploadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelPreliminaryUploadFile");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

checkAuthenticationPremiumPurchase::checkAuthenticationPremiumPurchase()
  : premium_day_count_()
  , currency_()
  , amount_()
{}

checkAuthenticationPremiumPurchase::checkAuthenticationPremiumPurchase(int32 premium_day_count_, string const &currency_, int53 amount_)
  : premium_day_count_(premium_day_count_)
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t checkAuthenticationPremiumPurchase::ID;

void checkAuthenticationPremiumPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationPremiumPurchase");
    s.store_field("premium_day_count", premium_day_count_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

checkOauthRequestMatchCode::checkOauthRequestMatchCode()
  : url_()
  , match_code_()
{}

checkOauthRequestMatchCode::checkOauthRequestMatchCode(string const &url_, string const &match_code_)
  : url_(url_)
  , match_code_(match_code_)
{}

const std::int32_t checkOauthRequestMatchCode::ID;

void checkOauthRequestMatchCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkOauthRequestMatchCode");
    s.store_field("url", url_);
    s.store_field("match_code", match_code_);
    s.store_class_end();
  }
}

checkStickerSetName::checkStickerSetName()
  : name_()
{}

checkStickerSetName::checkStickerSetName(string const &name_)
  : name_(name_)
{}

const std::int32_t checkStickerSetName::ID;

void checkStickerSetName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetName");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

clearRecentEmojiStatuses::clearRecentEmojiStatuses() {
}

const std::int32_t clearRecentEmojiStatuses::ID;

void clearRecentEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearRecentEmojiStatuses");
    s.store_class_end();
  }
}

close::close() {
}

const std::int32_t close::ID;

void close::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "close");
    s.store_class_end();
  }
}

composeRichMessageWithAi::composeRichMessageWithAi()
  : message_()
  , translate_to_language_code_()
  , style_name_()
  , custom_prompt_()
  , add_emojis_()
{}

composeRichMessageWithAi::composeRichMessageWithAi(object_ptr<inputRichMessage> &&message_, string const &translate_to_language_code_, string const &style_name_, string const &custom_prompt_, bool add_emojis_)
  : message_(std::move(message_))
  , translate_to_language_code_(translate_to_language_code_)
  , style_name_(style_name_)
  , custom_prompt_(custom_prompt_)
  , add_emojis_(add_emojis_)
{}

const std::int32_t composeRichMessageWithAi::ID;

void composeRichMessageWithAi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "composeRichMessageWithAi");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("translate_to_language_code", translate_to_language_code_);
    s.store_field("style_name", style_name_);
    s.store_field("custom_prompt", custom_prompt_);
    s.store_field("add_emojis", add_emojis_);
    s.store_class_end();
  }
}

composeTextWithAi::composeTextWithAi()
  : text_()
  , translate_to_language_code_()
  , style_name_()
  , add_emojis_()
{}

composeTextWithAi::composeTextWithAi(object_ptr<formattedText> &&text_, string const &translate_to_language_code_, string const &style_name_, bool add_emojis_)
  : text_(std::move(text_))
  , translate_to_language_code_(translate_to_language_code_)
  , style_name_(style_name_)
  , add_emojis_(add_emojis_)
{}

const std::int32_t composeTextWithAi::ID;

void composeTextWithAi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "composeTextWithAi");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("translate_to_language_code", translate_to_language_code_);
    s.store_field("style_name", style_name_);
    s.store_field("add_emojis", add_emojis_);
    s.store_class_end();
  }
}

createNewSecretChat::createNewSecretChat()
  : user_id_()
{}

createNewSecretChat::createNewSecretChat(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t createNewSecretChat::ID;

void createNewSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewSecretChat");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

deleteChat::deleteChat()
  : chat_id_()
{}

deleteChat::deleteChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t deleteChat::ID;

void deleteChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

deleteGiftCollection::deleteGiftCollection()
  : owner_id_()
  , collection_id_()
{}

deleteGiftCollection::deleteGiftCollection(object_ptr<MessageSender> &&owner_id_, int32 collection_id_)
  : owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
{}

const std::int32_t deleteGiftCollection::ID;

void deleteGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteGiftCollection");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    s.store_class_end();
  }
}

deletePassportElement::deletePassportElement()
  : type_()
{}

deletePassportElement::deletePassportElement(object_ptr<PassportElementType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t deletePassportElement::ID;

void deletePassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deletePassportElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

deleteTextCompositionStyle::deleteTextCompositionStyle()
  : name_()
{}

deleteTextCompositionStyle::deleteTextCompositionStyle(string const &name_)
  : name_(name_)
{}

const std::int32_t deleteTextCompositionStyle::ID;

void deleteTextCompositionStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteTextCompositionStyle");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

displayUpgradedGift::displayUpgradedGift()
  : owner_id_()
  , name_()
{}

displayUpgradedGift::displayUpgradedGift(object_ptr<MessageSender> &&owner_id_, string const &name_)
  : owner_id_(std::move(owner_id_))
  , name_(name_)
{}

const std::int32_t displayUpgradedGift::ID;

void displayUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "displayUpgradedGift");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("name", name_);
    s.store_class_end();
  }
}

editBusinessMessageText::editBusinessMessageText()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editBusinessMessageText::editBusinessMessageText(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editBusinessMessageText::ID;

void editBusinessMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageText");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editEphemeralMessage::editEphemeralMessage()
  : chat_id_()
  , receiver_user_id_()
  , ephemeral_message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editEphemeralMessage::editEphemeralMessage(int53 chat_id_, int53 receiver_user_id_, int32 ephemeral_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , receiver_user_id_(receiver_user_id_)
  , ephemeral_message_id_(ephemeral_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editEphemeralMessage::ID;

void editEphemeralMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editEphemeralMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("receiver_user_id", receiver_user_id_);
    s.store_field("ephemeral_message_id", ephemeral_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editStoryMusic::editStoryMusic()
  : story_poster_chat_id_()
  , story_id_()
  , music_()
{}

editStoryMusic::editStoryMusic(int53 story_poster_chat_id_, int32 story_id_, object_ptr<inputAudio> &&music_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , music_(std::move(music_))
{}

const std::int32_t editStoryMusic::ID;

void editStoryMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editStoryMusic");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_object_field("music", static_cast<const BaseObject *>(music_.get()));
    s.store_class_end();
  }
}

editTextCompositionStyle::editTextCompositionStyle()
  : name_()
  , title_()
  , custom_emoji_id_()
  , prompt_()
  , show_creator_()
{}

editTextCompositionStyle::editTextCompositionStyle(string const &name_, string const &title_, int64 custom_emoji_id_, string const &prompt_, bool show_creator_)
  : name_(name_)
  , title_(title_)
  , custom_emoji_id_(custom_emoji_id_)
  , prompt_(prompt_)
  , show_creator_(show_creator_)
{}

const std::int32_t editTextCompositionStyle::ID;

void editTextCompositionStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editTextCompositionStyle");
    s.store_field("name", name_);
    s.store_field("title", title_);
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_field("prompt", prompt_);
    s.store_field("show_creator", show_creator_);
    s.store_class_end();
  }
}

getAllStickerEmojis::getAllStickerEmojis()
  : sticker_type_()
  , query_()
  , chat_id_()
  , return_only_main_emoji_()
{}

getAllStickerEmojis::getAllStickerEmojis(object_ptr<StickerType> &&sticker_type_, string const &query_, int53 chat_id_, bool return_only_main_emoji_)
  : sticker_type_(std::move(sticker_type_))
  , query_(query_)
  , chat_id_(chat_id_)
  , return_only_main_emoji_(return_only_main_emoji_)
{}

const std::int32_t getAllStickerEmojis::ID;

void getAllStickerEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAllStickerEmojis");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("query", query_);
    s.store_field("chat_id", chat_id_);
    s.store_field("return_only_main_emoji", return_only_main_emoji_);
    s.store_class_end();
  }
}

getAnimatedEmoji::getAnimatedEmoji()
  : emoji_()
{}

getAnimatedEmoji::getAnimatedEmoji(string const &emoji_)
  : emoji_(emoji_)
{}

const std::int32_t getAnimatedEmoji::ID;

void getAnimatedEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAnimatedEmoji");
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

getAvailableGifts::getAvailableGifts() {
}

const std::int32_t getAvailableGifts::ID;

void getAvailableGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAvailableGifts");
    s.store_class_end();
  }
}

getBotSimilarBotCount::getBotSimilarBotCount()
  : bot_user_id_()
  , return_local_()
{}

getBotSimilarBotCount::getBotSimilarBotCount(int53 bot_user_id_, bool return_local_)
  : bot_user_id_(bot_user_id_)
  , return_local_(return_local_)
{}

const std::int32_t getBotSimilarBotCount::ID;

void getBotSimilarBotCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotSimilarBotCount");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("return_local", return_local_);
    s.store_class_end();
  }
}

getBotSimilarBots::getBotSimilarBots()
  : bot_user_id_()
{}

getBotSimilarBots::getBotSimilarBots(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t getBotSimilarBots::ID;

void getBotSimilarBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotSimilarBots");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

getChatBoostStatus::getChatBoostStatus()
  : chat_id_()
{}

getChatBoostStatus::getChatBoostStatus(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatBoostStatus::ID;

void getChatBoostStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoostStatus");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatFolderChatsToLeave::getChatFolderChatsToLeave()
  : chat_folder_id_()
{}

getChatFolderChatsToLeave::getChatFolderChatsToLeave(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t getChatFolderChatsToLeave::ID;

void getChatFolderChatsToLeave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolderChatsToLeave");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

getChatFolderNewChats::getChatFolderNewChats()
  : chat_folder_id_()
{}

getChatFolderNewChats::getChatFolderNewChats(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t getChatFolderNewChats::ID;

void getChatFolderNewChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolderNewChats");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

getChatMessageCalendar::getChatMessageCalendar()
  : chat_id_()
  , topic_id_()
  , filter_()
  , from_message_id_()
{}

getChatMessageCalendar::getChatMessageCalendar(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<SearchMessagesFilter> &&filter_, int53 from_message_id_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , filter_(std::move(filter_))
  , from_message_id_(from_message_id_)
{}

const std::int32_t getChatMessageCalendar::ID;

void getChatMessageCalendar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessageCalendar");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("from_message_id", from_message_id_);
    s.store_class_end();
  }
}

getChatMessagePosition::getChatMessagePosition()
  : chat_id_()
  , topic_id_()
  , filter_()
  , message_id_()
{}

getChatMessagePosition::getChatMessagePosition(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<SearchMessagesFilter> &&filter_, int53 message_id_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , filter_(std::move(filter_))
  , message_id_(message_id_)
{}

const std::int32_t getChatMessagePosition::ID;

void getChatMessagePosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessagePosition");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getChatNotificationSettingsExceptions::getChatNotificationSettingsExceptions()
  : scope_()
  , compare_sound_()
{}

getChatNotificationSettingsExceptions::getChatNotificationSettingsExceptions(object_ptr<NotificationSettingsScope> &&scope_, bool compare_sound_)
  : scope_(std::move(scope_))
  , compare_sound_(compare_sound_)
{}

const std::int32_t getChatNotificationSettingsExceptions::ID;

void getChatNotificationSettingsExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatNotificationSettingsExceptions");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("compare_sound", compare_sound_);
    s.store_class_end();
  }
}

getChatStoryAlbums::getChatStoryAlbums()
  : chat_id_()
{}

getChatStoryAlbums::getChatStoryAlbums(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatStoryAlbums::ID;

void getChatStoryAlbums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatStoryAlbums");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatStoryInteractions::getChatStoryInteractions()
  : story_poster_chat_id_()
  , story_id_()
  , reaction_type_()
  , prefer_forwards_()
  , offset_()
  , limit_()
{}

getChatStoryInteractions::getChatStoryInteractions(int53 story_poster_chat_id_, int32 story_id_, object_ptr<ReactionType> &&reaction_type_, bool prefer_forwards_, string const &offset_, int32 limit_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , reaction_type_(std::move(reaction_type_))
  , prefer_forwards_(prefer_forwards_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getChatStoryInteractions::ID;

void getChatStoryInteractions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatStoryInteractions");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("prefer_forwards", prefer_forwards_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getCurrencyExchangeRates::getCurrencyExchangeRates() {
}

const std::int32_t getCurrencyExchangeRates::ID;

void getCurrencyExchangeRates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCurrencyExchangeRates");
    s.store_class_end();
  }
}

getDefaultChatEmojiStatuses::getDefaultChatEmojiStatuses() {
}

const std::int32_t getDefaultChatEmojiStatuses::ID;

void getDefaultChatEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultChatEmojiStatuses");
    s.store_class_end();
  }
}

getFavoriteStickers::getFavoriteStickers() {
}

const std::int32_t getFavoriteStickers::ID;

void getFavoriteStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFavoriteStickers");
    s.store_class_end();
  }
}

getFileDownloadedPrefixSize::getFileDownloadedPrefixSize()
  : file_id_()
  , offset_()
{}

getFileDownloadedPrefixSize::getFileDownloadedPrefixSize(int32 file_id_, int53 offset_)
  : file_id_(file_id_)
  , offset_(offset_)
{}

const std::int32_t getFileDownloadedPrefixSize::ID;

void getFileDownloadedPrefixSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFileDownloadedPrefixSize");
    s.store_field("file_id", file_id_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

getInactiveSupergroupChats::getInactiveSupergroupChats() {
}

const std::int32_t getInactiveSupergroupChats::ID;

void getInactiveSupergroupChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInactiveSupergroupChats");
    s.store_class_end();
  }
}

getInlineGameHighScores::getInlineGameHighScores()
  : inline_message_id_()
  , user_id_()
{}

getInlineGameHighScores::getInlineGameHighScores(string const &inline_message_id_, int53 user_id_)
  : inline_message_id_(inline_message_id_)
  , user_id_(user_id_)
{}

const std::int32_t getInlineGameHighScores::ID;

void getInlineGameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInlineGameHighScores");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getInstalledStickerSets::getInstalledStickerSets()
  : sticker_type_()
{}

getInstalledStickerSets::getInstalledStickerSets(object_ptr<StickerType> &&sticker_type_)
  : sticker_type_(std::move(sticker_type_))
{}

const std::int32_t getInstalledStickerSets::ID;

void getInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInstalledStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_class_end();
  }
}

getLoginPasskeys::getLoginPasskeys() {
}

const std::int32_t getLoginPasskeys::ID;

void getLoginPasskeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLoginPasskeys");
    s.store_class_end();
  }
}

getMessage::getMessage()
  : chat_id_()
  , message_id_()
{}

getMessage::getMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessage::ID;

void getMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessageAuthor::getMessageAuthor()
  : chat_id_()
  , message_id_()
{}

getMessageAuthor::getMessageAuthor(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageAuthor::ID;

void getMessageAuthor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageAuthor");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessageImportConfirmationText::getMessageImportConfirmationText()
  : chat_id_()
{}

getMessageImportConfirmationText::getMessageImportConfirmationText(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getMessageImportConfirmationText::ID;

void getMessageImportConfirmationText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageImportConfirmationText");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getOwnedStickerSets::getOwnedStickerSets()
  : offset_sticker_set_id_()
  , limit_()
{}

getOwnedStickerSets::getOwnedStickerSets(int64 offset_sticker_set_id_, int32 limit_)
  : offset_sticker_set_id_(offset_sticker_set_id_)
  , limit_(limit_)
{}

const std::int32_t getOwnedStickerSets::ID;

void getOwnedStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOwnedStickerSets");
    s.store_field("offset_sticker_set_id", offset_sticker_set_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getPassportElement::getPassportElement()
  : type_()
  , password_()
{}

getPassportElement::getPassportElement(object_ptr<PassportElementType> &&type_, string const &password_)
  : type_(std::move(type_))
  , password_(password_)
{}

const std::int32_t getPassportElement::ID;

void getPassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPassportElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

getPremiumInfoSticker::getPremiumInfoSticker()
  : month_count_()
{}

getPremiumInfoSticker::getPremiumInfoSticker(int32 month_count_)
  : month_count_(month_count_)
{}

const std::int32_t getPremiumInfoSticker::ID;

void getPremiumInfoSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumInfoSticker");
    s.store_field("month_count", month_count_);
    s.store_class_end();
  }
}

getPremiumStickers::getPremiumStickers()
  : limit_()
{}

getPremiumStickers::getPremiumStickers(int32 limit_)
  : limit_(limit_)
{}

const std::int32_t getPremiumStickers::ID;

void getPremiumStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumStickers");
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getStakeDiceState::getStakeDiceState() {
}

const std::int32_t getStakeDiceState::ID;

void getStakeDiceState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStakeDiceState");
    s.store_class_end();
  }
}

getStarAdAccountUrl::getStarAdAccountUrl()
  : owner_id_()
{}

getStarAdAccountUrl::getStarAdAccountUrl(object_ptr<MessageSender> &&owner_id_)
  : owner_id_(std::move(owner_id_))
{}

const std::int32_t getStarAdAccountUrl::ID;

void getStarAdAccountUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarAdAccountUrl");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_class_end();
  }
}

getStickerSetName::getStickerSetName()
  : set_id_()
{}

getStickerSetName::getStickerSetName(int64 set_id_)
  : set_id_(set_id_)
{}

const std::int32_t getStickerSetName::ID;

void getStickerSetName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerSetName");
    s.store_field("set_id", set_id_);
    s.store_class_end();
  }
}

getStoryAlbumStories::getStoryAlbumStories()
  : chat_id_()
  , story_album_id_()
  , offset_()
  , limit_()
{}

getStoryAlbumStories::getStoryAlbumStories(int53 chat_id_, int32 story_album_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getStoryAlbumStories::ID;

void getStoryAlbumStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryAlbumStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getSuitablePersonalChats::getSuitablePersonalChats() {
}

const std::int32_t getSuitablePersonalChats::ID;

void getSuitablePersonalChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuitablePersonalChats");
    s.store_class_end();
  }
}

getTonWalletNfts::getTonWalletNfts()
  : offset_()
  , limit_()
{}

getTonWalletNfts::getTonWalletNfts(string const &offset_, int32 limit_)
  : offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getTonWalletNfts::ID;

void getTonWalletNfts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonWalletNfts");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getTrendingStickerSets::getTrendingStickerSets()
  : sticker_type_()
  , offset_()
  , limit_()
{}

getTrendingStickerSets::getTrendingStickerSets(object_ptr<StickerType> &&sticker_type_, int32 offset_, int32 limit_)
  : sticker_type_(std::move(sticker_type_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getTrendingStickerSets::ID;

void getTrendingStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTrendingStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getUserPrivacySettingRules::getUserPrivacySettingRules()
  : setting_()
{}

getUserPrivacySettingRules::getUserPrivacySettingRules(object_ptr<UserPrivacySetting> &&setting_)
  : setting_(std::move(setting_))
{}

const std::int32_t getUserPrivacySettingRules::ID;

void getUserPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserPrivacySettingRules");
    s.store_object_field("setting", static_cast<const BaseObject *>(setting_.get()));
    s.store_class_end();
  }
}

isProfileAudio::isProfileAudio()
  : file_id_()
{}

isProfileAudio::isProfileAudio(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t isProfileAudio::ID;

void isProfileAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "isProfileAudio");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

joinChatByInviteLink::joinChatByInviteLink()
  : invite_link_()
{}

joinChatByInviteLink::joinChatByInviteLink(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t joinChatByInviteLink::ID;

void joinChatByInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinChatByInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

leaveGroupCall::leaveGroupCall()
  : group_call_id_()
{}

leaveGroupCall::leaveGroupCall(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t leaveGroupCall::ID;

void leaveGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "leaveGroupCall");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

loadChatWelcomeMessages::loadChatWelcomeMessages()
  : chat_id_()
{}

loadChatWelcomeMessages::loadChatWelcomeMessages(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t loadChatWelcomeMessages::ID;

void loadChatWelcomeMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadChatWelcomeMessages");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

markChecklistTasksAsDone::markChecklistTasksAsDone()
  : chat_id_()
  , message_id_()
  , marked_as_done_task_ids_()
  , marked_as_not_done_task_ids_()
{}

markChecklistTasksAsDone::markChecklistTasksAsDone(int53 chat_id_, int53 message_id_, array<int32> &&marked_as_done_task_ids_, array<int32> &&marked_as_not_done_task_ids_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , marked_as_done_task_ids_(std::move(marked_as_done_task_ids_))
  , marked_as_not_done_task_ids_(std::move(marked_as_not_done_task_ids_))
{}

const std::int32_t markChecklistTasksAsDone::ID;

void markChecklistTasksAsDone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "markChecklistTasksAsDone");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("marked_as_done_task_ids", marked_as_done_task_ids_.size()); for (const auto &_value : marked_as_done_task_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("marked_as_not_done_task_ids", marked_as_not_done_task_ids_.size()); for (const auto &_value : marked_as_not_done_task_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

openWebApp::openWebApp()
  : chat_id_()
  , bot_user_id_()
  , url_()
  , topic_id_()
  , reply_to_()
  , parameters_()
{}

openWebApp::openWebApp(int53 chat_id_, int53 bot_user_id_, string const &url_, object_ptr<MessageTopic> &&topic_id_, object_ptr<InputMessageReplyTo> &&reply_to_, object_ptr<webAppOpenParameters> &&parameters_)
  : chat_id_(chat_id_)
  , bot_user_id_(bot_user_id_)
  , url_(url_)
  , topic_id_(std::move(topic_id_))
  , reply_to_(std::move(reply_to_))
  , parameters_(std::move(parameters_))
{}

const std::int32_t openWebApp::ID;

void openWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openWebApp");
    s.store_field("chat_id", chat_id_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("url", url_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

processCommunityAddChatRequests::processCommunityAddChatRequests()
  : community_id_()
  , approve_()
{}

processCommunityAddChatRequests::processCommunityAddChatRequests(int53 community_id_, bool approve_)
  : community_id_(community_id_)
  , approve_(approve_)
{}

const std::int32_t processCommunityAddChatRequests::ID;

void processCommunityAddChatRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processCommunityAddChatRequests");
    s.store_field("community_id", community_id_);
    s.store_field("approve", approve_);
    s.store_class_end();
  }
}

processPushNotification::processPushNotification()
  : payload_()
{}

processPushNotification::processPushNotification(string const &payload_)
  : payload_(payload_)
{}

const std::int32_t processPushNotification::ID;

void processPushNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processPushNotification");
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

readAllChatPollVotes::readAllChatPollVotes()
  : chat_id_()
{}

readAllChatPollVotes::readAllChatPollVotes(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t readAllChatPollVotes::ID;

void readAllChatPollVotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllChatPollVotes");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

readAllForumTopicReactions::readAllForumTopicReactions()
  : chat_id_()
  , forum_topic_id_()
{}

readAllForumTopicReactions::readAllForumTopicReactions(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t readAllForumTopicReactions::ID;

void readAllForumTopicReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllForumTopicReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

removeGiftCollectionGifts::removeGiftCollectionGifts()
  : owner_id_()
  , collection_id_()
  , received_gift_ids_()
{}

removeGiftCollectionGifts::removeGiftCollectionGifts(object_ptr<MessageSender> &&owner_id_, int32 collection_id_, array<string> &&received_gift_ids_)
  : owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
  , received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t removeGiftCollectionGifts::ID;

void removeGiftCollectionGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeGiftCollectionGifts");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

removeRecentSticker::removeRecentSticker()
  : is_attached_()
  , sticker_()
{}

removeRecentSticker::removeRecentSticker(bool is_attached_, object_ptr<InputFile> &&sticker_)
  : is_attached_(is_attached_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t removeRecentSticker::ID;

void removeRecentSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeRecentSticker");
    s.store_field("is_attached", is_attached_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

removeStickerFromSet::removeStickerFromSet()
  : sticker_()
{}

removeStickerFromSet::removeStickerFromSet(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t removeStickerFromSet::ID;

void removeStickerFromSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeStickerFromSet");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

reorderGiftCollectionGifts::reorderGiftCollectionGifts()
  : owner_id_()
  , collection_id_()
  , received_gift_ids_()
{}

reorderGiftCollectionGifts::reorderGiftCollectionGifts(object_ptr<MessageSender> &&owner_id_, int32 collection_id_, array<string> &&received_gift_ids_)
  : owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
  , received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t reorderGiftCollectionGifts::ID;

void reorderGiftCollectionGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderGiftCollectionGifts");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

replacePrimaryChatInviteLink::replacePrimaryChatInviteLink()
  : chat_id_()
{}

replacePrimaryChatInviteLink::replacePrimaryChatInviteLink(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t replacePrimaryChatInviteLink::ID;

void replacePrimaryChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replacePrimaryChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

reportChatPhoto::reportChatPhoto()
  : chat_id_()
  , file_id_()
  , reason_()
  , text_()
{}

reportChatPhoto::reportChatPhoto(int53 chat_id_, int32 file_id_, object_ptr<ReportReason> &&reason_, string const &text_)
  : chat_id_(chat_id_)
  , file_id_(file_id_)
  , reason_(std::move(reason_))
  , text_(text_)
{}

const std::int32_t reportChatPhoto::ID;

void reportChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatPhoto");
    s.store_field("chat_id", chat_id_);
    s.store_field("file_id", file_id_);
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("text", text_);
    s.store_class_end();
  }
}

reportMessageReactions::reportMessageReactions()
  : chat_id_()
  , message_id_()
  , sender_id_()
{}

reportMessageReactions::reportMessageReactions(int53 chat_id_, int53 message_id_, object_ptr<MessageSender> &&sender_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , sender_id_(std::move(sender_id_))
{}

const std::int32_t reportMessageReactions::ID;

void reportMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportMessageReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_class_end();
  }
}

savePreparedKeyboardButton::savePreparedKeyboardButton()
  : user_id_()
  , button_()
{}

savePreparedKeyboardButton::savePreparedKeyboardButton(int53 user_id_, object_ptr<keyboardButton> &&button_)
  : user_id_(user_id_)
  , button_(std::move(button_))
{}

const std::int32_t savePreparedKeyboardButton::ID;

void savePreparedKeyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savePreparedKeyboardButton");
    s.store_field("user_id", user_id_);
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    s.store_class_end();
  }
}

searchEmojis::searchEmojis()
  : text_()
  , input_language_codes_()
{}

searchEmojis::searchEmojis(string const &text_, array<string> &&input_language_codes_)
  : text_(text_)
  , input_language_codes_(std::move(input_language_codes_))
{}

const std::int32_t searchEmojis::ID;

void searchEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchEmojis");
    s.store_field("text", text_);
    { s.store_vector_begin("input_language_codes", input_language_codes_.size()); for (const auto &_value : input_language_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

searchRecentlyFoundChats::searchRecentlyFoundChats()
  : query_()
  , type_filter_()
  , limit_()
{}

searchRecentlyFoundChats::searchRecentlyFoundChats(string const &query_, object_ptr<SearchChatTypeFilter> &&type_filter_, int32 limit_)
  : query_(query_)
  , type_filter_(std::move(type_filter_))
  , limit_(limit_)
{}

const std::int32_t searchRecentlyFoundChats::ID;

void searchRecentlyFoundChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchRecentlyFoundChats");
    s.store_field("query", query_);
    s.store_object_field("type_filter", static_cast<const BaseObject *>(type_filter_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchTextCompositionStyle::searchTextCompositionStyle()
  : name_()
{}

searchTextCompositionStyle::searchTextCompositionStyle(string const &name_)
  : name_(name_)
{}

const std::int32_t searchTextCompositionStyle::ID;

void searchTextCompositionStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchTextCompositionStyle");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

sendBusinessMessageAlbum::sendBusinessMessageAlbum()
  : business_connection_id_()
  , chat_id_()
  , reply_to_()
  , disable_notification_()
  , protect_content_()
  , effect_id_()
  , input_message_contents_()
{}

sendBusinessMessageAlbum::sendBusinessMessageAlbum(string const &business_connection_id_, int53 chat_id_, object_ptr<InputMessageReplyTo> &&reply_to_, bool disable_notification_, bool protect_content_, int64 effect_id_, array<object_ptr<InputMessageContent>> &&input_message_contents_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , reply_to_(std::move(reply_to_))
  , disable_notification_(disable_notification_)
  , protect_content_(protect_content_)
  , effect_id_(effect_id_)
  , input_message_contents_(std::move(input_message_contents_))
{}

const std::int32_t sendBusinessMessageAlbum::ID;

void sendBusinessMessageAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendBusinessMessageAlbum");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_field("disable_notification", disable_notification_);
    s.store_field("protect_content", protect_content_);
    s.store_field("effect_id", effect_id_);
    { s.store_vector_begin("input_message_contents", input_message_contents_.size()); for (const auto &_value : input_message_contents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sendCustomRequest::sendCustomRequest()
  : method_()
  , parameters_()
{}

sendCustomRequest::sendCustomRequest(string const &method_, string const &parameters_)
  : method_(method_)
  , parameters_(parameters_)
{}

const std::int32_t sendCustomRequest::ID;

void sendCustomRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCustomRequest");
    s.store_field("method", method_);
    s.store_field("parameters", parameters_);
    s.store_class_end();
  }
}

sendMessageAlbum::sendMessageAlbum()
  : chat_id_()
  , topic_id_()
  , reply_to_()
  , options_()
  , input_message_contents_()
{}

sendMessageAlbum::sendMessageAlbum(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<InputMessageReplyTo> &&reply_to_, object_ptr<messageSendOptions> &&options_, array<object_ptr<InputMessageContent>> &&input_message_contents_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , reply_to_(std::move(reply_to_))
  , options_(std::move(options_))
  , input_message_contents_(std::move(input_message_contents_))
{}

const std::int32_t sendMessageAlbum::ID;

void sendMessageAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageAlbum");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    { s.store_vector_begin("input_message_contents", input_message_contents_.size()); for (const auto &_value : input_message_contents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sendPhoneNumberFirebaseSms::sendPhoneNumberFirebaseSms()
  : token_()
{}

sendPhoneNumberFirebaseSms::sendPhoneNumberFirebaseSms(string const &token_)
  : token_(token_)
{}

const std::int32_t sendPhoneNumberFirebaseSms::ID;

void sendPhoneNumberFirebaseSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPhoneNumberFirebaseSms");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

setAccentColor::setAccentColor()
  : accent_color_id_()
  , background_custom_emoji_id_()
{}

setAccentColor::setAccentColor(int32 accent_color_id_, int64 background_custom_emoji_id_)
  : accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
{}

const std::int32_t setAccentColor::ID;

void setAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAccentColor");
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_class_end();
  }
}

setAuthenticationEmailAddress::setAuthenticationEmailAddress()
  : email_address_()
{}

setAuthenticationEmailAddress::setAuthenticationEmailAddress(string const &email_address_)
  : email_address_(email_address_)
{}

const std::int32_t setAuthenticationEmailAddress::ID;

void setAuthenticationEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAuthenticationEmailAddress");
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

setBusinessAccountProfilePhoto::setBusinessAccountProfilePhoto()
  : business_connection_id_()
  , photo_()
  , is_public_()
{}

setBusinessAccountProfilePhoto::setBusinessAccountProfilePhoto(string const &business_connection_id_, object_ptr<InputChatPhoto> &&photo_, bool is_public_)
  : business_connection_id_(business_connection_id_)
  , photo_(std::move(photo_))
  , is_public_(is_public_)
{}

const std::int32_t setBusinessAccountProfilePhoto::ID;

void setBusinessAccountProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAccountProfilePhoto");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("is_public", is_public_);
    s.store_class_end();
  }
}

setBusinessConnectedBot::setBusinessConnectedBot()
  : bot_()
{}

setBusinessConnectedBot::setBusinessConnectedBot(object_ptr<businessConnectedBot> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t setBusinessConnectedBot::ID;

void setBusinessConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessConnectedBot");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

setBusinessMessageIsPinned::setBusinessMessageIsPinned()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , is_pinned_()
{}

setBusinessMessageIsPinned::setBusinessMessageIsPinned(string const &business_connection_id_, int53 chat_id_, int53 message_id_, bool is_pinned_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t setBusinessMessageIsPinned::ID;

void setBusinessMessageIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessMessageIsPinned");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

setChatDirectMessagesGroup::setChatDirectMessagesGroup()
  : chat_id_()
  , is_enabled_()
  , paid_message_star_count_()
{}

setChatDirectMessagesGroup::setChatDirectMessagesGroup(int53 chat_id_, bool is_enabled_, int53 paid_message_star_count_)
  : chat_id_(chat_id_)
  , is_enabled_(is_enabled_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t setChatDirectMessagesGroup::ID;

void setChatDirectMessagesGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatDirectMessagesGroup");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_enabled", is_enabled_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

setChatEmojiStatus::setChatEmojiStatus()
  : chat_id_()
  , emoji_status_()
{}

setChatEmojiStatus::setChatEmojiStatus(int53 chat_id_, object_ptr<emojiStatus> &&emoji_status_)
  : chat_id_(chat_id_)
  , emoji_status_(std::move(emoji_status_))
{}

const std::int32_t setChatEmojiStatus::ID;

void setChatEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatEmojiStatus");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

setChatPinnedStories::setChatPinnedStories()
  : chat_id_()
  , story_ids_()
{}

setChatPinnedStories::setChatPinnedStories(int53 chat_id_, array<int32> &&story_ids_)
  : chat_id_(chat_id_)
  , story_ids_(std::move(story_ids_))
{}

const std::int32_t setChatPinnedStories::ID;

void setChatPinnedStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatPinnedStories");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("story_ids", story_ids_.size()); for (const auto &_value : story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setCommands::setCommands()
  : scope_()
  , language_code_()
  , commands_()
{}

setCommands::setCommands(object_ptr<BotCommandScope> &&scope_, string const &language_code_, array<object_ptr<botCommand>> &&commands_)
  : scope_(std::move(scope_))
  , language_code_(language_code_)
  , commands_(std::move(commands_))
{}

const std::int32_t setCommands::ID;

void setCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("language_code", language_code_);
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

setInlineGameScore::setInlineGameScore()
  : inline_message_id_()
  , edit_message_()
  , user_id_()
  , score_()
  , force_()
{}

setInlineGameScore::setInlineGameScore(string const &inline_message_id_, bool edit_message_, int53 user_id_, int32 score_, bool force_)
  : inline_message_id_(inline_message_id_)
  , edit_message_(edit_message_)
  , user_id_(user_id_)
  , score_(score_)
  , force_(force_)
{}

const std::int32_t setInlineGameScore::ID;

void setInlineGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setInlineGameScore");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_field("edit_message", edit_message_);
    s.store_field("user_id", user_id_);
    s.store_field("score", score_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

setMenuButton::setMenuButton()
  : user_id_()
  , menu_button_()
{}

setMenuButton::setMenuButton(int53 user_id_, object_ptr<botMenuButton> &&menu_button_)
  : user_id_(user_id_)
  , menu_button_(std::move(menu_button_))
{}

const std::int32_t setMenuButton::ID;

void setMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMenuButton");
    s.store_field("user_id", user_id_);
    s.store_object_field("menu_button", static_cast<const BaseObject *>(menu_button_.get()));
    s.store_class_end();
  }
}

setProfilePhoto::setProfilePhoto()
  : photo_()
  , is_public_()
{}

setProfilePhoto::setProfilePhoto(object_ptr<InputChatPhoto> &&photo_, bool is_public_)
  : photo_(std::move(photo_))
  , is_public_(is_public_)
{}

const std::int32_t setProfilePhoto::ID;

void setProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setProfilePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("is_public", is_public_);
    s.store_class_end();
  }
}

setSupergroupCustomEmojiStickerSet::setSupergroupCustomEmojiStickerSet()
  : supergroup_id_()
  , custom_emoji_sticker_set_id_()
{}

setSupergroupCustomEmojiStickerSet::setSupergroupCustomEmojiStickerSet(int53 supergroup_id_, int64 custom_emoji_sticker_set_id_)
  : supergroup_id_(supergroup_id_)
  , custom_emoji_sticker_set_id_(custom_emoji_sticker_set_id_)
{}

const std::int32_t setSupergroupCustomEmojiStickerSet::ID;

void setSupergroupCustomEmojiStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupCustomEmojiStickerSet");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("custom_emoji_sticker_set_id", custom_emoji_sticker_set_id_);
    s.store_class_end();
  }
}

setTonWalletCardStickers::setTonWalletCardStickers()
  : stickers_()
  , background_nft_address_()
{}

setTonWalletCardStickers::setTonWalletCardStickers(array<object_ptr<inputTonWalletCardSticker>> &&stickers_, string const &background_nft_address_)
  : stickers_(std::move(stickers_))
  , background_nft_address_(background_nft_address_)
{}

const std::int32_t setTonWalletCardStickers::ID;

void setTonWalletCardStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setTonWalletCardStickers");
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("background_nft_address", background_nft_address_);
    s.store_class_end();
  }
}

setUserPrivacySettingRules::setUserPrivacySettingRules()
  : setting_()
  , rules_()
{}

setUserPrivacySettingRules::setUserPrivacySettingRules(object_ptr<UserPrivacySetting> &&setting_, object_ptr<userPrivacySettingRules> &&rules_)
  : setting_(std::move(setting_))
  , rules_(std::move(rules_))
{}

const std::int32_t setUserPrivacySettingRules::ID;

void setUserPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUserPrivacySettingRules");
    s.store_object_field("setting", static_cast<const BaseObject *>(setting_.get()));
    s.store_object_field("rules", static_cast<const BaseObject *>(rules_.get()));
    s.store_class_end();
  }
}

setVideoChatTitle::setVideoChatTitle()
  : group_call_id_()
  , title_()
{}

setVideoChatTitle::setVideoChatTitle(int32 group_call_id_, string const &title_)
  : group_call_id_(group_call_id_)
  , title_(title_)
{}

const std::int32_t setVideoChatTitle::ID;

void setVideoChatTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setVideoChatTitle");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

synchronizeLanguagePack::synchronizeLanguagePack()
  : language_pack_id_()
{}

synchronizeLanguagePack::synchronizeLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t synchronizeLanguagePack::ID;

void synchronizeLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "synchronizeLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

testCallVectorString::testCallVectorString()
  : x_()
{}

testCallVectorString::testCallVectorString(array<string> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorString::ID;

void testCallVectorString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorString");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

toggleBotIsAddedToAttachmentMenu::toggleBotIsAddedToAttachmentMenu()
  : bot_user_id_()
  , is_added_()
  , allow_write_access_()
{}

toggleBotIsAddedToAttachmentMenu::toggleBotIsAddedToAttachmentMenu(int53 bot_user_id_, bool is_added_, bool allow_write_access_)
  : bot_user_id_(bot_user_id_)
  , is_added_(is_added_)
  , allow_write_access_(allow_write_access_)
{}

const std::int32_t toggleBotIsAddedToAttachmentMenu::ID;

void toggleBotIsAddedToAttachmentMenu::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleBotIsAddedToAttachmentMenu");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("is_added", is_added_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_class_end();
  }
}

toggleChatViewAsTopics::toggleChatViewAsTopics()
  : chat_id_()
  , view_as_topics_()
{}

toggleChatViewAsTopics::toggleChatViewAsTopics(int53 chat_id_, bool view_as_topics_)
  : chat_id_(chat_id_)
  , view_as_topics_(view_as_topics_)
{}

const std::int32_t toggleChatViewAsTopics::ID;

void toggleChatViewAsTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatViewAsTopics");
    s.store_field("chat_id", chat_id_);
    s.store_field("view_as_topics", view_as_topics_);
    s.store_class_end();
  }
}

toggleCommunityAreChatsCollapsed::toggleCommunityAreChatsCollapsed()
  : community_id_()
  , are_chats_collapsed_()
{}

toggleCommunityAreChatsCollapsed::toggleCommunityAreChatsCollapsed(int53 community_id_, bool are_chats_collapsed_)
  : community_id_(community_id_)
  , are_chats_collapsed_(are_chats_collapsed_)
{}

const std::int32_t toggleCommunityAreChatsCollapsed::ID;

void toggleCommunityAreChatsCollapsed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleCommunityAreChatsCollapsed");
    s.store_field("community_id", community_id_);
    s.store_field("are_chats_collapsed", are_chats_collapsed_);
    s.store_class_end();
  }
}

toggleStoryIsPostedToChatPage::toggleStoryIsPostedToChatPage()
  : story_poster_chat_id_()
  , story_id_()
  , is_posted_to_chat_page_()
{}

toggleStoryIsPostedToChatPage::toggleStoryIsPostedToChatPage(int53 story_poster_chat_id_, int32 story_id_, bool is_posted_to_chat_page_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , is_posted_to_chat_page_(is_posted_to_chat_page_)
{}

const std::int32_t toggleStoryIsPostedToChatPage::ID;

void toggleStoryIsPostedToChatPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleStoryIsPostedToChatPage");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("is_posted_to_chat_page", is_posted_to_chat_page_);
    s.store_class_end();
  }
}

toggleSupergroupJoinToSendMessages::toggleSupergroupJoinToSendMessages()
  : supergroup_id_()
  , join_to_send_messages_()
{}

toggleSupergroupJoinToSendMessages::toggleSupergroupJoinToSendMessages(int53 supergroup_id_, bool join_to_send_messages_)
  : supergroup_id_(supergroup_id_)
  , join_to_send_messages_(join_to_send_messages_)
{}

const std::int32_t toggleSupergroupJoinToSendMessages::ID;

void toggleSupergroupJoinToSendMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupJoinToSendMessages");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("join_to_send_messages", join_to_send_messages_);
    s.store_class_end();
  }
}

toggleSupergroupSignMessages::toggleSupergroupSignMessages()
  : supergroup_id_()
  , sign_messages_()
  , show_message_sender_()
{}

toggleSupergroupSignMessages::toggleSupergroupSignMessages(int53 supergroup_id_, bool sign_messages_, bool show_message_sender_)
  : supergroup_id_(supergroup_id_)
  , sign_messages_(sign_messages_)
  , show_message_sender_(show_message_sender_)
{}

const std::int32_t toggleSupergroupSignMessages::ID;

void toggleSupergroupSignMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupSignMessages");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("sign_messages", sign_messages_);
    s.store_field("show_message_sender", show_message_sender_);
    s.store_class_end();
  }
}

translateMessageText::translateMessageText()
  : chat_id_()
  , message_id_()
  , to_language_code_()
  , tone_()
{}

translateMessageText::translateMessageText(int53 chat_id_, int53 message_id_, string const &to_language_code_, string const &tone_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , to_language_code_(to_language_code_)
  , tone_(tone_)
{}

const std::int32_t translateMessageText::ID;

void translateMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "translateMessageText");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("to_language_code", to_language_code_);
    s.store_field("tone", tone_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
