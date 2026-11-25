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


advertisementSponsor::advertisementSponsor()
  : url_()
  , photo_()
  , info_()
{}

advertisementSponsor::advertisementSponsor(string const &url_, object_ptr<photo> &&photo_, string const &info_)
  : url_(url_)
  , photo_(std::move(photo_))
  , info_(info_)
{}

const std::int32_t advertisementSponsor::ID;

void advertisementSponsor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "advertisementSponsor");
    s.store_field("url", url_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("info", info_);
    s.store_class_end();
  }
}

authenticationCodeInfo::authenticationCodeInfo()
  : phone_number_()
  , type_()
  , next_type_()
  , timeout_()
{}

authenticationCodeInfo::authenticationCodeInfo(string const &phone_number_, object_ptr<AuthenticationCodeType> &&type_, object_ptr<AuthenticationCodeType> &&next_type_, int32 timeout_)
  : phone_number_(phone_number_)
  , type_(std::move(type_))
  , next_type_(std::move(next_type_))
  , timeout_(timeout_)
{}

const std::int32_t authenticationCodeInfo::ID;

void authenticationCodeInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeInfo");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("next_type", static_cast<const BaseObject *>(next_type_.get()));
    s.store_field("timeout", timeout_);
    s.store_class_end();
  }
}

autoDownloadSettingsPresets::autoDownloadSettingsPresets()
  : low_()
  , medium_()
  , high_()
{}

autoDownloadSettingsPresets::autoDownloadSettingsPresets(object_ptr<autoDownloadSettings> &&low_, object_ptr<autoDownloadSettings> &&medium_, object_ptr<autoDownloadSettings> &&high_)
  : low_(std::move(low_))
  , medium_(std::move(medium_))
  , high_(std::move(high_))
{}

const std::int32_t autoDownloadSettingsPresets::ID;

void autoDownloadSettingsPresets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoDownloadSettingsPresets");
    s.store_object_field("low", static_cast<const BaseObject *>(low_.get()));
    s.store_object_field("medium", static_cast<const BaseObject *>(medium_.get()));
    s.store_object_field("high", static_cast<const BaseObject *>(high_.get()));
    s.store_class_end();
  }
}

autosaveSettings::autosaveSettings()
  : private_chat_settings_()
  , group_settings_()
  , channel_settings_()
  , exceptions_()
{}

autosaveSettings::autosaveSettings(object_ptr<scopeAutosaveSettings> &&private_chat_settings_, object_ptr<scopeAutosaveSettings> &&group_settings_, object_ptr<scopeAutosaveSettings> &&channel_settings_, array<object_ptr<autosaveSettingsException>> &&exceptions_)
  : private_chat_settings_(std::move(private_chat_settings_))
  , group_settings_(std::move(group_settings_))
  , channel_settings_(std::move(channel_settings_))
  , exceptions_(std::move(exceptions_))
{}

const std::int32_t autosaveSettings::ID;

void autosaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettings");
    s.store_object_field("private_chat_settings", static_cast<const BaseObject *>(private_chat_settings_.get()));
    s.store_object_field("group_settings", static_cast<const BaseObject *>(group_settings_.get()));
    s.store_object_field("channel_settings", static_cast<const BaseObject *>(channel_settings_.get()));
    { s.store_vector_begin("exceptions", exceptions_.size()); for (const auto &_value : exceptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

backgrounds::backgrounds()
  : backgrounds_()
{}

backgrounds::backgrounds(array<object_ptr<background>> &&backgrounds_)
  : backgrounds_(std::move(backgrounds_))
{}

const std::int32_t backgrounds::ID;

void backgrounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgrounds");
    { s.store_vector_begin("backgrounds", backgrounds_.size()); for (const auto &_value : backgrounds_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

botVerification::botVerification()
  : bot_user_id_()
  , icon_custom_emoji_id_()
  , custom_description_()
{}

botVerification::botVerification(int53 bot_user_id_, int64 icon_custom_emoji_id_, object_ptr<formattedText> &&custom_description_)
  : bot_user_id_(bot_user_id_)
  , icon_custom_emoji_id_(icon_custom_emoji_id_)
  , custom_description_(std::move(custom_description_))
{}

const std::int32_t botVerification::ID;

void botVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botVerification");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_object_field("custom_description", static_cast<const BaseObject *>(custom_description_.get()));
    s.store_class_end();
  }
}

businessConnection::businessConnection()
  : id_()
  , user_id_()
  , user_chat_id_()
  , date_()
  , rights_()
  , is_enabled_()
{}

businessConnection::businessConnection(string const &id_, int53 user_id_, int53 user_chat_id_, int32 date_, object_ptr<businessBotRights> &&rights_, bool is_enabled_)
  : id_(id_)
  , user_id_(user_id_)
  , user_chat_id_(user_chat_id_)
  , date_(date_)
  , rights_(std::move(rights_))
  , is_enabled_(is_enabled_)
{}

const std::int32_t businessConnection::ID;

void businessConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessConnection");
    s.store_field("id", id_);
    s.store_field("user_id", user_id_);
    s.store_field("user_chat_id", user_chat_id_);
    s.store_field("date", date_);
    s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get()));
    s.store_field("is_enabled", is_enabled_);
    s.store_class_end();
  }
}

callbackQueryPayloadData::callbackQueryPayloadData()
  : data_()
{}

callbackQueryPayloadData::callbackQueryPayloadData(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t callbackQueryPayloadData::ID;

void callbackQueryPayloadData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryPayloadData");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

callbackQueryPayloadDataWithPassword::callbackQueryPayloadDataWithPassword()
  : password_()
  , data_()
{}

callbackQueryPayloadDataWithPassword::callbackQueryPayloadDataWithPassword(string const &password_, bytes const &data_)
  : password_(password_)
  , data_(std::move(data_))
{}

const std::int32_t callbackQueryPayloadDataWithPassword::ID;

void callbackQueryPayloadDataWithPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryPayloadDataWithPassword");
    s.store_field("password", "[REDACTED]");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

callbackQueryPayloadGame::callbackQueryPayloadGame()
  : game_short_name_()
{}

callbackQueryPayloadGame::callbackQueryPayloadGame(string const &game_short_name_)
  : game_short_name_(game_short_name_)
{}

const std::int32_t callbackQueryPayloadGame::ID;

void callbackQueryPayloadGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryPayloadGame");
    s.store_field("game_short_name", game_short_name_);
    s.store_class_end();
  }
}

chatAdministrator::chatAdministrator()
  : user_id_()
  , custom_title_()
  , is_owner_()
  , can_be_edited_()
{}

chatAdministrator::chatAdministrator(int53 user_id_, string const &custom_title_, bool is_owner_, bool can_be_edited_)
  : user_id_(user_id_)
  , custom_title_(custom_title_)
  , is_owner_(is_owner_)
  , can_be_edited_(can_be_edited_)
{}

const std::int32_t chatAdministrator::ID;

void chatAdministrator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdministrator");
    s.store_field("user_id", user_id_);
    s.store_field("custom_title", custom_title_);
    s.store_field("is_owner", is_owner_);
    s.store_field("can_be_edited", can_be_edited_);
    s.store_class_end();
  }
}

chatAvailableReactionsAll::chatAvailableReactionsAll()
  : max_reaction_count_()
{}

chatAvailableReactionsAll::chatAvailableReactionsAll(int32 max_reaction_count_)
  : max_reaction_count_(max_reaction_count_)
{}

const std::int32_t chatAvailableReactionsAll::ID;

void chatAvailableReactionsAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAvailableReactionsAll");
    s.store_field("max_reaction_count", max_reaction_count_);
    s.store_class_end();
  }
}

chatAvailableReactionsSome::chatAvailableReactionsSome()
  : reactions_()
  , max_reaction_count_()
{}

chatAvailableReactionsSome::chatAvailableReactionsSome(array<object_ptr<ReactionType>> &&reactions_, int32 max_reaction_count_)
  : reactions_(std::move(reactions_))
  , max_reaction_count_(max_reaction_count_)
{}

const std::int32_t chatAvailableReactionsSome::ID;

void chatAvailableReactionsSome::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAvailableReactionsSome");
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("max_reaction_count", max_reaction_count_);
    s.store_class_end();
  }
}

chatBackground::chatBackground()
  : background_()
  , dark_theme_dimming_()
{}

chatBackground::chatBackground(object_ptr<background> &&background_, int32 dark_theme_dimming_)
  : background_(std::move(background_))
  , dark_theme_dimming_(dark_theme_dimming_)
{}

const std::int32_t chatBackground::ID;

void chatBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBackground");
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_field("dark_theme_dimming", dark_theme_dimming_);
    s.store_class_end();
  }
}

chatBoostFeatures::chatBoostFeatures()
  : features_()
  , min_profile_background_custom_emoji_boost_level_()
  , min_background_custom_emoji_boost_level_()
  , min_emoji_status_boost_level_()
  , min_chat_theme_background_boost_level_()
  , min_custom_background_boost_level_()
  , min_custom_emoji_sticker_set_boost_level_()
  , min_automatic_translation_boost_level_()
  , min_speech_recognition_boost_level_()
  , min_sponsored_message_disable_boost_level_()
{}

chatBoostFeatures::chatBoostFeatures(array<object_ptr<chatBoostLevelFeatures>> &&features_, int32 min_profile_background_custom_emoji_boost_level_, int32 min_background_custom_emoji_boost_level_, int32 min_emoji_status_boost_level_, int32 min_chat_theme_background_boost_level_, int32 min_custom_background_boost_level_, int32 min_custom_emoji_sticker_set_boost_level_, int32 min_automatic_translation_boost_level_, int32 min_speech_recognition_boost_level_, int32 min_sponsored_message_disable_boost_level_)
  : features_(std::move(features_))
  , min_profile_background_custom_emoji_boost_level_(min_profile_background_custom_emoji_boost_level_)
  , min_background_custom_emoji_boost_level_(min_background_custom_emoji_boost_level_)
  , min_emoji_status_boost_level_(min_emoji_status_boost_level_)
  , min_chat_theme_background_boost_level_(min_chat_theme_background_boost_level_)
  , min_custom_background_boost_level_(min_custom_background_boost_level_)
  , min_custom_emoji_sticker_set_boost_level_(min_custom_emoji_sticker_set_boost_level_)
  , min_automatic_translation_boost_level_(min_automatic_translation_boost_level_)
  , min_speech_recognition_boost_level_(min_speech_recognition_boost_level_)
  , min_sponsored_message_disable_boost_level_(min_sponsored_message_disable_boost_level_)
{}

const std::int32_t chatBoostFeatures::ID;

void chatBoostFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostFeatures");
    { s.store_vector_begin("features", features_.size()); for (const auto &_value : features_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("min_profile_background_custom_emoji_boost_level", min_profile_background_custom_emoji_boost_level_);
    s.store_field("min_background_custom_emoji_boost_level", min_background_custom_emoji_boost_level_);
    s.store_field("min_emoji_status_boost_level", min_emoji_status_boost_level_);
    s.store_field("min_chat_theme_background_boost_level", min_chat_theme_background_boost_level_);
    s.store_field("min_custom_background_boost_level", min_custom_background_boost_level_);
    s.store_field("min_custom_emoji_sticker_set_boost_level", min_custom_emoji_sticker_set_boost_level_);
    s.store_field("min_automatic_translation_boost_level", min_automatic_translation_boost_level_);
    s.store_field("min_speech_recognition_boost_level", min_speech_recognition_boost_level_);
    s.store_field("min_sponsored_message_disable_boost_level", min_sponsored_message_disable_boost_level_);
    s.store_class_end();
  }
}

chatEventLogFilters::chatEventLogFilters()
  : message_edits_()
  , message_deletions_()
  , message_pins_()
  , member_joins_()
  , member_leaves_()
  , member_invites_()
  , member_promotions_()
  , member_restrictions_()
  , member_tag_changes_()
  , info_changes_()
  , setting_changes_()
  , invite_link_changes_()
  , video_chat_changes_()
  , forum_changes_()
  , subscription_extensions_()
{}

chatEventLogFilters::chatEventLogFilters(bool message_edits_, bool message_deletions_, bool message_pins_, bool member_joins_, bool member_leaves_, bool member_invites_, bool member_promotions_, bool member_restrictions_, bool member_tag_changes_, bool info_changes_, bool setting_changes_, bool invite_link_changes_, bool video_chat_changes_, bool forum_changes_, bool subscription_extensions_)
  : message_edits_(message_edits_)
  , message_deletions_(message_deletions_)
  , message_pins_(message_pins_)
  , member_joins_(member_joins_)
  , member_leaves_(member_leaves_)
  , member_invites_(member_invites_)
  , member_promotions_(member_promotions_)
  , member_restrictions_(member_restrictions_)
  , member_tag_changes_(member_tag_changes_)
  , info_changes_(info_changes_)
  , setting_changes_(setting_changes_)
  , invite_link_changes_(invite_link_changes_)
  , video_chat_changes_(video_chat_changes_)
  , forum_changes_(forum_changes_)
  , subscription_extensions_(subscription_extensions_)
{}

const std::int32_t chatEventLogFilters::ID;

void chatEventLogFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventLogFilters");
    s.store_field("message_edits", message_edits_);
    s.store_field("message_deletions", message_deletions_);
    s.store_field("message_pins", message_pins_);
    s.store_field("member_joins", member_joins_);
    s.store_field("member_leaves", member_leaves_);
    s.store_field("member_invites", member_invites_);
    s.store_field("member_promotions", member_promotions_);
    s.store_field("member_restrictions", member_restrictions_);
    s.store_field("member_tag_changes", member_tag_changes_);
    s.store_field("info_changes", info_changes_);
    s.store_field("setting_changes", setting_changes_);
    s.store_field("invite_link_changes", invite_link_changes_);
    s.store_field("video_chat_changes", video_chat_changes_);
    s.store_field("forum_changes", forum_changes_);
    s.store_field("subscription_extensions", subscription_extensions_);
    s.store_class_end();
  }
}

chatFolderInfo::chatFolderInfo()
  : id_()
  , name_()
  , icon_()
  , color_id_()
  , is_shareable_()
  , has_my_invite_links_()
{}

chatFolderInfo::chatFolderInfo(int32 id_, object_ptr<chatFolderName> &&name_, object_ptr<chatFolderIcon> &&icon_, int32 color_id_, bool is_shareable_, bool has_my_invite_links_)
  : id_(id_)
  , name_(std::move(name_))
  , icon_(std::move(icon_))
  , color_id_(color_id_)
  , is_shareable_(is_shareable_)
  , has_my_invite_links_(has_my_invite_links_)
{}

const std::int32_t chatFolderInfo::ID;

void chatFolderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderInfo");
    s.store_field("id", id_);
    s.store_object_field("name", static_cast<const BaseObject *>(name_.get()));
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_field("color_id", color_id_);
    s.store_field("is_shareable", is_shareable_);
    s.store_field("has_my_invite_links", has_my_invite_links_);
    s.store_class_end();
  }
}

chatInviteLinkCount::chatInviteLinkCount()
  : user_id_()
  , invite_link_count_()
  , revoked_invite_link_count_()
{}

chatInviteLinkCount::chatInviteLinkCount(int53 user_id_, int32 invite_link_count_, int32 revoked_invite_link_count_)
  : user_id_(user_id_)
  , invite_link_count_(invite_link_count_)
  , revoked_invite_link_count_(revoked_invite_link_count_)
{}

const std::int32_t chatInviteLinkCount::ID;

void chatInviteLinkCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkCount");
    s.store_field("user_id", user_id_);
    s.store_field("invite_link_count", invite_link_count_);
    s.store_field("revoked_invite_link_count", revoked_invite_link_count_);
    s.store_class_end();
  }
}

chatInviteLinkInfo::chatInviteLinkInfo()
  : chat_id_()
  , accessible_for_()
  , type_()
  , title_()
  , photo_()
  , accent_color_id_()
  , description_()
  , member_count_()
  , member_user_ids_()
  , subscription_info_()
  , creates_join_request_()
  , is_public_()
  , verification_status_()
{}

chatInviteLinkInfo::chatInviteLinkInfo(int53 chat_id_, int32 accessible_for_, object_ptr<InviteLinkChatType> &&type_, string const &title_, object_ptr<chatPhotoInfo> &&photo_, int32 accent_color_id_, string const &description_, int32 member_count_, array<int53> &&member_user_ids_, object_ptr<chatInviteLinkSubscriptionInfo> &&subscription_info_, bool creates_join_request_, bool is_public_, object_ptr<verificationStatus> &&verification_status_)
  : chat_id_(chat_id_)
  , accessible_for_(accessible_for_)
  , type_(std::move(type_))
  , title_(title_)
  , photo_(std::move(photo_))
  , accent_color_id_(accent_color_id_)
  , description_(description_)
  , member_count_(member_count_)
  , member_user_ids_(std::move(member_user_ids_))
  , subscription_info_(std::move(subscription_info_))
  , creates_join_request_(creates_join_request_)
  , is_public_(is_public_)
  , verification_status_(std::move(verification_status_))
{}

const std::int32_t chatInviteLinkInfo::ID;

void chatInviteLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("accessible_for", accessible_for_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("description", description_);
    s.store_field("member_count", member_count_);
    { s.store_vector_begin("member_user_ids", member_user_ids_.size()); for (const auto &_value : member_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("subscription_info", static_cast<const BaseObject *>(subscription_info_.get()));
    s.store_field("creates_join_request", creates_join_request_);
    s.store_field("is_public", is_public_);
    s.store_object_field("verification_status", static_cast<const BaseObject *>(verification_status_.get()));
    s.store_class_end();
  }
}

chatListMain::chatListMain() {
}

const std::int32_t chatListMain::ID;

void chatListMain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatListMain");
    s.store_class_end();
  }
}

chatListArchive::chatListArchive() {
}

const std::int32_t chatListArchive::ID;

void chatListArchive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatListArchive");
    s.store_class_end();
  }
}

chatListFolder::chatListFolder()
  : chat_folder_id_()
{}

chatListFolder::chatListFolder(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t chatListFolder::ID;

void chatListFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatListFolder");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

chatLocation::chatLocation()
  : location_()
  , address_()
{}

chatLocation::chatLocation(object_ptr<location> &&location_, string const &address_)
  : location_(std::move(location_))
  , address_(address_)
{}

const std::int32_t chatLocation::ID;

void chatLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("address", address_);
    s.store_class_end();
  }
}

chatMember::chatMember()
  : member_id_()
  , tag_()
  , inviter_user_id_()
  , joined_chat_date_()
  , status_()
{}

chatMember::chatMember(object_ptr<MessageSender> &&member_id_, string const &tag_, int53 inviter_user_id_, int32 joined_chat_date_, object_ptr<ChatMemberStatus> &&status_)
  : member_id_(std::move(member_id_))
  , tag_(tag_)
  , inviter_user_id_(inviter_user_id_)
  , joined_chat_date_(joined_chat_date_)
  , status_(std::move(status_))
{}

const std::int32_t chatMember::ID;

void chatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMember");
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_field("tag", tag_);
    s.store_field("inviter_user_id", inviter_user_id_);
    s.store_field("joined_chat_date", joined_chat_date_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

communityAdministratorRights::communityAdministratorRights()
  : can_manage_community_()
  , can_change_info_()
  , can_edit_chat_list_()
  , can_promote_members_()
  , can_ban_members_()
{}

communityAdministratorRights::communityAdministratorRights(bool can_manage_community_, bool can_change_info_, bool can_edit_chat_list_, bool can_promote_members_, bool can_ban_members_)
  : can_manage_community_(can_manage_community_)
  , can_change_info_(can_change_info_)
  , can_edit_chat_list_(can_edit_chat_list_)
  , can_promote_members_(can_promote_members_)
  , can_ban_members_(can_ban_members_)
{}

const std::int32_t communityAdministratorRights::ID;

void communityAdministratorRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityAdministratorRights");
    s.store_field("can_manage_community", can_manage_community_);
    s.store_field("can_change_info", can_change_info_);
    s.store_field("can_edit_chat_list", can_edit_chat_list_);
    s.store_field("can_promote_members", can_promote_members_);
    s.store_field("can_ban_members", can_ban_members_);
    s.store_class_end();
  }
}

connectedWebsite::connectedWebsite()
  : id_()
  , domain_name_()
  , bot_user_id_()
  , browser_()
  , platform_()
  , log_in_date_()
  , last_active_date_()
  , ip_address_()
  , location_()
{}

connectedWebsite::connectedWebsite(int64 id_, string const &domain_name_, int53 bot_user_id_, string const &browser_, string const &platform_, int32 log_in_date_, int32 last_active_date_, string const &ip_address_, string const &location_)
  : id_(id_)
  , domain_name_(domain_name_)
  , bot_user_id_(bot_user_id_)
  , browser_(browser_)
  , platform_(platform_)
  , log_in_date_(log_in_date_)
  , last_active_date_(last_active_date_)
  , ip_address_(ip_address_)
  , location_(location_)
{}

const std::int32_t connectedWebsite::ID;

void connectedWebsite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedWebsite");
    s.store_field("id", id_);
    s.store_field("domain_name", domain_name_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("browser", browser_);
    s.store_field("platform", platform_);
    s.store_field("log_in_date", log_in_date_);
    s.store_field("last_active_date", last_active_date_);
    s.store_field("ip_address", ip_address_);
    s.store_field("location", location_);
    s.store_class_end();
  }
}

count::count()
  : count_()
{}

count::count(int32 count_)
  : count_(count_)
{}

const std::int32_t count::ID;

void count::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "count");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

diffEntityTypeInsert::diffEntityTypeInsert() {
}

const std::int32_t diffEntityTypeInsert::ID;

void diffEntityTypeInsert::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diffEntityTypeInsert");
    s.store_class_end();
  }
}

diffEntityTypeReplace::diffEntityTypeReplace()
  : old_text_()
{}

diffEntityTypeReplace::diffEntityTypeReplace(string const &old_text_)
  : old_text_(old_text_)
{}

const std::int32_t diffEntityTypeReplace::ID;

void diffEntityTypeReplace::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diffEntityTypeReplace");
    s.store_field("old_text", old_text_);
    s.store_class_end();
  }
}

diffEntityTypeDelete::diffEntityTypeDelete() {
}

const std::int32_t diffEntityTypeDelete::ID;

void diffEntityTypeDelete::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diffEntityTypeDelete");
    s.store_class_end();
  }
}

failedToAddMember::failedToAddMember()
  : user_id_()
  , premium_would_allow_invite_()
  , premium_required_to_send_messages_()
{}

failedToAddMember::failedToAddMember(int53 user_id_, bool premium_would_allow_invite_, bool premium_required_to_send_messages_)
  : user_id_(user_id_)
  , premium_would_allow_invite_(premium_would_allow_invite_)
  , premium_required_to_send_messages_(premium_required_to_send_messages_)
{}

const std::int32_t failedToAddMember::ID;

void failedToAddMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "failedToAddMember");
    s.store_field("user_id", user_id_);
    s.store_field("premium_would_allow_invite", premium_would_allow_invite_);
    s.store_field("premium_required_to_send_messages", premium_required_to_send_messages_);
    s.store_class_end();
  }
}

foundAffiliatePrograms::foundAffiliatePrograms()
  : total_count_()
  , programs_()
  , next_offset_()
{}

foundAffiliatePrograms::foundAffiliatePrograms(int32 total_count_, array<object_ptr<foundAffiliateProgram>> &&programs_, string const &next_offset_)
  : total_count_(total_count_)
  , programs_(std::move(programs_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundAffiliatePrograms::ID;

void foundAffiliatePrograms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundAffiliatePrograms");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("programs", programs_.size()); for (const auto &_value : programs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

foundChatBoosts::foundChatBoosts()
  : total_count_()
  , boosts_()
  , next_offset_()
{}

foundChatBoosts::foundChatBoosts(int32 total_count_, array<object_ptr<chatBoost>> &&boosts_, string const &next_offset_)
  : total_count_(total_count_)
  , boosts_(std::move(boosts_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundChatBoosts::ID;

void foundChatBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundChatBoosts");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("boosts", boosts_.size()); for (const auto &_value : boosts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

giftResaleParameters::giftResaleParameters()
  : star_count_()
  , gram_cent_count_()
  , gram_amount_()
  , gram_only_()
  , is_fixed_on_chain_()
  , can_be_managed_()
{}

giftResaleParameters::giftResaleParameters(int53 star_count_, int53 gram_cent_count_, int64 gram_amount_, bool gram_only_, bool is_fixed_on_chain_, bool can_be_managed_)
  : star_count_(star_count_)
  , gram_cent_count_(gram_cent_count_)
  , gram_amount_(gram_amount_)
  , gram_only_(gram_only_)
  , is_fixed_on_chain_(is_fixed_on_chain_)
  , can_be_managed_(can_be_managed_)
{}

const std::int32_t giftResaleParameters::ID;

void giftResaleParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftResaleParameters");
    s.store_field("star_count", star_count_);
    s.store_field("gram_cent_count", gram_cent_count_);
    s.store_field("gram_amount", gram_amount_);
    s.store_field("gram_only", gram_only_);
    s.store_field("is_fixed_on_chain", is_fixed_on_chain_);
    s.store_field("can_be_managed", can_be_managed_);
    s.store_class_end();
  }
}

giftResalePriceStar::giftResalePriceStar()
  : star_count_()
{}

giftResalePriceStar::giftResalePriceStar(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t giftResalePriceStar::ID;

void giftResalePriceStar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftResalePriceStar");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

giftResalePriceGram::giftResalePriceGram()
  : gram_cent_count_()
{}

giftResalePriceGram::giftResalePriceGram(int53 gram_cent_count_)
  : gram_cent_count_(gram_cent_count_)
{}

const std::int32_t giftResalePriceGram::ID;

void giftResalePriceGram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftResalePriceGram");
    s.store_field("gram_cent_count", gram_cent_count_);
    s.store_class_end();
  }
}

gramRevenueStatus::gramRevenueStatus()
  : total_amount_()
  , balance_amount_()
  , available_amount_()
  , withdrawal_enabled_()
{}

gramRevenueStatus::gramRevenueStatus(int64 total_amount_, int64 balance_amount_, int64 available_amount_, bool withdrawal_enabled_)
  : total_amount_(total_amount_)
  , balance_amount_(balance_amount_)
  , available_amount_(available_amount_)
  , withdrawal_enabled_(withdrawal_enabled_)
{}

const std::int32_t gramRevenueStatus::ID;

void gramRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "gramRevenueStatus");
    s.store_field("total_amount", total_amount_);
    s.store_field("balance_amount", balance_amount_);
    s.store_field("available_amount", available_amount_);
    s.store_field("withdrawal_enabled", withdrawal_enabled_);
    s.store_class_end();
  }
}

groupCallDataChannelMain::groupCallDataChannelMain() {
}

const std::int32_t groupCallDataChannelMain::ID;

void groupCallDataChannelMain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallDataChannelMain");
    s.store_class_end();
  }
}

groupCallDataChannelScreenSharing::groupCallDataChannelScreenSharing() {
}

const std::int32_t groupCallDataChannelScreenSharing::ID;

void groupCallDataChannelScreenSharing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallDataChannelScreenSharing");
    s.store_class_end();
  }
}

groupCallId::groupCallId()
  : id_()
{}

groupCallId::groupCallId(int32 id_)
  : id_(id_)
{}

const std::int32_t groupCallId::ID;

void groupCallId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

groupCallStream::groupCallStream()
  : channel_id_()
  , scale_()
  , time_offset_()
{}

groupCallStream::groupCallStream(int32 channel_id_, int32 scale_, int53 time_offset_)
  : channel_id_(channel_id_)
  , scale_(scale_)
  , time_offset_(time_offset_)
{}

const std::int32_t groupCallStream::ID;

void groupCallStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallStream");
    s.store_field("channel_id", channel_id_);
    s.store_field("scale", scale_);
    s.store_field("time_offset", time_offset_);
    s.store_class_end();
  }
}

hashtags::hashtags()
  : hashtags_()
{}

hashtags::hashtags(array<string> &&hashtags_)
  : hashtags_(std::move(hashtags_))
{}

const std::int32_t hashtags::ID;

void hashtags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "hashtags");
    { s.store_vector_begin("hashtags", hashtags_.size()); for (const auto &_value : hashtags_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inlineQueryResults::inlineQueryResults()
  : inline_query_id_()
  , button_()
  , results_()
  , next_offset_()
{}

inlineQueryResults::inlineQueryResults(int64 inline_query_id_, object_ptr<inlineQueryResultsButton> &&button_, array<object_ptr<InlineQueryResult>> &&results_, string const &next_offset_)
  : inline_query_id_(inline_query_id_)
  , button_(std::move(button_))
  , results_(std::move(results_))
  , next_offset_(next_offset_)
{}

const std::int32_t inlineQueryResults::ID;

void inlineQueryResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResults");
    s.store_field("inline_query_id", inline_query_id_);
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

inputFileId::inputFileId()
  : id_()
{}

inputFileId::inputFileId(int32 id_)
  : id_(id_)
{}

const std::int32_t inputFileId::ID;

void inputFileId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputFileRemote::inputFileRemote()
  : id_()
{}

inputFileRemote::inputFileRemote(string const &id_)
  : id_(id_)
{}

const std::int32_t inputFileRemote::ID;

void inputFileRemote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileRemote");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputFileLocal::inputFileLocal()
  : path_()
{}

inputFileLocal::inputFileLocal(string const &path_)
  : path_(path_)
{}

const std::int32_t inputFileLocal::ID;

void inputFileLocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileLocal");
    s.store_field("path", path_);
    s.store_class_end();
  }
}

inputFileGenerated::inputFileGenerated()
  : original_path_()
  , conversion_()
  , expected_size_()
{}

inputFileGenerated::inputFileGenerated(string const &original_path_, string const &conversion_, int53 expected_size_)
  : original_path_(original_path_)
  , conversion_(conversion_)
  , expected_size_(expected_size_)
{}

const std::int32_t inputFileGenerated::ID;

void inputFileGenerated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileGenerated");
    s.store_field("original_path", original_path_);
    s.store_field("conversion", conversion_);
    s.store_field("expected_size", expected_size_);
    s.store_class_end();
  }
}

inputGroupCallLink::inputGroupCallLink()
  : link_()
{}

inputGroupCallLink::inputGroupCallLink(string const &link_)
  : link_(link_)
{}

const std::int32_t inputGroupCallLink::ID;

void inputGroupCallLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCallLink");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

inputGroupCallMessage::inputGroupCallMessage()
  : chat_id_()
  , message_id_()
{}

inputGroupCallMessage::inputGroupCallMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t inputGroupCallMessage::ID;

void inputGroupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCallMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

inputRichMessageMedia::inputRichMessageMedia()
  : id_()
  , media_()
{}

inputRichMessageMedia::inputRichMessageMedia(string const &id_, object_ptr<InputMessageContent> &&media_)
  : id_(id_)
  , media_(std::move(media_))
{}

const std::int32_t inputRichMessageMedia::ID;

void inputRichMessageMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputRichMessageMedia");
    s.store_field("id", id_);
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

inputStoryArea::inputStoryArea()
  : position_()
  , type_()
{}

inputStoryArea::inputStoryArea(object_ptr<areaPosition> &&position_, object_ptr<InputStoryAreaType> &&type_)
  : position_(std::move(position_))
  , type_(std::move(type_))
{}

const std::int32_t inputStoryArea::ID;

void inputStoryArea::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryArea");
    s.store_object_field("position", static_cast<const BaseObject *>(position_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

jsonValueNull::jsonValueNull() {
}

const std::int32_t jsonValueNull::ID;

void jsonValueNull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueNull");
    s.store_class_end();
  }
}

jsonValueBoolean::jsonValueBoolean()
  : value_()
{}

jsonValueBoolean::jsonValueBoolean(bool value_)
  : value_(value_)
{}

const std::int32_t jsonValueBoolean::ID;

void jsonValueBoolean::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueBoolean");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonValueNumber::jsonValueNumber()
  : value_()
{}

jsonValueNumber::jsonValueNumber(double value_)
  : value_(value_)
{}

const std::int32_t jsonValueNumber::ID;

void jsonValueNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueNumber");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonValueString::jsonValueString()
  : value_()
{}

jsonValueString::jsonValueString(string const &value_)
  : value_(value_)
{}

const std::int32_t jsonValueString::ID;

void jsonValueString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueString");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonValueArray::jsonValueArray()
  : values_()
{}

jsonValueArray::jsonValueArray(array<object_ptr<JsonValue>> &&values_)
  : values_(std::move(values_))
{}

const std::int32_t jsonValueArray::ID;

void jsonValueArray::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueArray");
    { s.store_vector_begin("values", values_.size()); for (const auto &_value : values_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

jsonValueObject::jsonValueObject()
  : members_()
{}

jsonValueObject::jsonValueObject(array<object_ptr<jsonObjectMember>> &&members_)
  : members_(std::move(members_))
{}

const std::int32_t jsonValueObject::ID;

void jsonValueObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueObject");
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

languagePackStringValueOrdinary::languagePackStringValueOrdinary()
  : value_()
{}

languagePackStringValueOrdinary::languagePackStringValueOrdinary(string const &value_)
  : value_(value_)
{}

const std::int32_t languagePackStringValueOrdinary::ID;

void languagePackStringValueOrdinary::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStringValueOrdinary");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

languagePackStringValuePluralized::languagePackStringValuePluralized()
  : zero_value_()
  , one_value_()
  , two_value_()
  , few_value_()
  , many_value_()
  , other_value_()
{}

languagePackStringValuePluralized::languagePackStringValuePluralized(string const &zero_value_, string const &one_value_, string const &two_value_, string const &few_value_, string const &many_value_, string const &other_value_)
  : zero_value_(zero_value_)
  , one_value_(one_value_)
  , two_value_(two_value_)
  , few_value_(few_value_)
  , many_value_(many_value_)
  , other_value_(other_value_)
{}

const std::int32_t languagePackStringValuePluralized::ID;

void languagePackStringValuePluralized::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStringValuePluralized");
    s.store_field("zero_value", zero_value_);
    s.store_field("one_value", one_value_);
    s.store_field("two_value", two_value_);
    s.store_field("few_value", few_value_);
    s.store_field("many_value", many_value_);
    s.store_field("other_value", other_value_);
    s.store_class_end();
  }
}

languagePackStringValueDeleted::languagePackStringValueDeleted() {
}

const std::int32_t languagePackStringValueDeleted::ID;

void languagePackStringValueDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStringValueDeleted");
    s.store_class_end();
  }
}

message::message()
  : id_()
  , sender_id_()
  , receiver_id_()
  , chat_id_()
  , sending_state_()
  , scheduling_state_()
  , is_outgoing_()
  , is_pinned_()
  , is_from_offline_()
  , can_be_saved_()
  , has_timestamped_media_()
  , is_channel_post_()
  , is_paid_star_suggested_post_()
  , is_paid_gram_suggested_post_()
  , contains_unread_mention_()
  , contains_unread_poll_votes_()
  , date_()
  , edit_date_()
  , forward_info_()
  , import_info_()
  , interaction_info_()
  , unread_reactions_()
  , fact_check_()
  , suggested_post_info_()
  , reply_to_()
  , topic_id_()
  , self_destruct_type_()
  , self_destruct_in_()
  , auto_delete_in_()
  , via_bot_user_id_()
  , guest_bot_caller_id_()
  , sender_business_bot_user_id_()
  , sender_boost_count_()
  , sender_tag_()
  , paid_message_star_count_()
  , author_signature_()
  , media_album_id_()
  , effect_id_()
  , restriction_info_()
  , summary_language_code_()
  , content_()
  , ephemeral_content_()
  , reply_markup_()
  , ephemeral_message_id_()
  , chat_instance_()
{}

message::message(int53 id_, object_ptr<MessageSender> &&sender_id_, object_ptr<MessageSender> &&receiver_id_, int53 chat_id_, object_ptr<MessageSendingState> &&sending_state_, object_ptr<MessageSchedulingState> &&scheduling_state_, bool is_outgoing_, bool is_pinned_, bool is_from_offline_, bool can_be_saved_, bool has_timestamped_media_, bool is_channel_post_, bool is_paid_star_suggested_post_, bool is_paid_gram_suggested_post_, bool contains_unread_mention_, bool contains_unread_poll_votes_, int32 date_, int32 edit_date_, object_ptr<messageForwardInfo> &&forward_info_, object_ptr<messageImportInfo> &&import_info_, object_ptr<messageInteractionInfo> &&interaction_info_, array<object_ptr<unreadReaction>> &&unread_reactions_, object_ptr<factCheck> &&fact_check_, object_ptr<suggestedPostInfo> &&suggested_post_info_, object_ptr<MessageReplyTo> &&reply_to_, object_ptr<MessageTopic> &&topic_id_, object_ptr<MessageSelfDestructType> &&self_destruct_type_, double self_destruct_in_, double auto_delete_in_, int53 via_bot_user_id_, object_ptr<MessageSender> &&guest_bot_caller_id_, int53 sender_business_bot_user_id_, int32 sender_boost_count_, string const &sender_tag_, int53 paid_message_star_count_, string const &author_signature_, int64 media_album_id_, int64 effect_id_, object_ptr<restrictionInfo> &&restriction_info_, string const &summary_language_code_, object_ptr<MessageContent> &&content_, object_ptr<ephemeralMessageContent> &&ephemeral_content_, object_ptr<ReplyMarkup> &&reply_markup_, int32 ephemeral_message_id_, int64 chat_instance_)
  : id_(id_)
  , sender_id_(std::move(sender_id_))
  , receiver_id_(std::move(receiver_id_))
  , chat_id_(chat_id_)
  , sending_state_(std::move(sending_state_))
  , scheduling_state_(std::move(scheduling_state_))
  , is_outgoing_(is_outgoing_)
  , is_pinned_(is_pinned_)
  , is_from_offline_(is_from_offline_)
  , can_be_saved_(can_be_saved_)
  , has_timestamped_media_(has_timestamped_media_)
  , is_channel_post_(is_channel_post_)
  , is_paid_star_suggested_post_(is_paid_star_suggested_post_)
  , is_paid_gram_suggested_post_(is_paid_gram_suggested_post_)
  , contains_unread_mention_(contains_unread_mention_)
  , contains_unread_poll_votes_(contains_unread_poll_votes_)
  , date_(date_)
  , edit_date_(edit_date_)
  , forward_info_(std::move(forward_info_))
  , import_info_(std::move(import_info_))
  , interaction_info_(std::move(interaction_info_))
  , unread_reactions_(std::move(unread_reactions_))
  , fact_check_(std::move(fact_check_))
  , suggested_post_info_(std::move(suggested_post_info_))
  , reply_to_(std::move(reply_to_))
  , topic_id_(std::move(topic_id_))
  , self_destruct_type_(std::move(self_destruct_type_))
  , self_destruct_in_(self_destruct_in_)
  , auto_delete_in_(auto_delete_in_)
  , via_bot_user_id_(via_bot_user_id_)
  , guest_bot_caller_id_(std::move(guest_bot_caller_id_))
  , sender_business_bot_user_id_(sender_business_bot_user_id_)
  , sender_boost_count_(sender_boost_count_)
  , sender_tag_(sender_tag_)
  , paid_message_star_count_(paid_message_star_count_)
  , author_signature_(author_signature_)
  , media_album_id_(media_album_id_)
  , effect_id_(effect_id_)
  , restriction_info_(std::move(restriction_info_))
  , summary_language_code_(summary_language_code_)
  , content_(std::move(content_))
  , ephemeral_content_(std::move(ephemeral_content_))
  , reply_markup_(std::move(reply_markup_))
  , ephemeral_message_id_(ephemeral_message_id_)
  , chat_instance_(chat_instance_)
{}

const std::int32_t message::ID;

void message::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "message");
    s.store_field("id", id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_object_field("sending_state", static_cast<const BaseObject *>(sending_state_.get()));
    s.store_object_field("scheduling_state", static_cast<const BaseObject *>(scheduling_state_.get()));
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("is_pinned", is_pinned_);
    s.store_field("is_from_offline", is_from_offline_);
    s.store_field("can_be_saved", can_be_saved_);
    s.store_field("has_timestamped_media", has_timestamped_media_);
    s.store_field("is_channel_post", is_channel_post_);
    s.store_field("is_paid_star_suggested_post", is_paid_star_suggested_post_);
    s.store_field("is_paid_gram_suggested_post", is_paid_gram_suggested_post_);
    s.store_field("contains_unread_mention", contains_unread_mention_);
    s.store_field("contains_unread_poll_votes", contains_unread_poll_votes_);
    s.store_field("date", date_);
    s.store_field("edit_date", edit_date_);
    s.store_object_field("forward_info", static_cast<const BaseObject *>(forward_info_.get()));
    s.store_object_field("import_info", static_cast<const BaseObject *>(import_info_.get()));
    s.store_object_field("interaction_info", static_cast<const BaseObject *>(interaction_info_.get()));
    { s.store_vector_begin("unread_reactions", unread_reactions_.size()); for (const auto &_value : unread_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("fact_check", static_cast<const BaseObject *>(fact_check_.get()));
    s.store_object_field("suggested_post_info", static_cast<const BaseObject *>(suggested_post_info_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_field("self_destruct_in", self_destruct_in_);
    s.store_field("auto_delete_in", auto_delete_in_);
    s.store_field("via_bot_user_id", via_bot_user_id_);
    s.store_object_field("guest_bot_caller_id", static_cast<const BaseObject *>(guest_bot_caller_id_.get()));
    s.store_field("sender_business_bot_user_id", sender_business_bot_user_id_);
    s.store_field("sender_boost_count", sender_boost_count_);
    s.store_field("sender_tag", sender_tag_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_field("author_signature", author_signature_);
    s.store_field("media_album_id", media_album_id_);
    s.store_field("effect_id", effect_id_);
    s.store_object_field("restriction_info", static_cast<const BaseObject *>(restriction_info_.get()));
    s.store_field("summary_language_code", summary_language_code_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("ephemeral_content", static_cast<const BaseObject *>(ephemeral_content_.get()));
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_field("ephemeral_message_id", ephemeral_message_id_);
    s.store_field("chat_instance", chat_instance_);
    s.store_class_end();
  }
}

messageStatistics::messageStatistics()
  : message_interaction_graph_()
  , message_reaction_graph_()
{}

messageStatistics::messageStatistics(object_ptr<StatisticalGraph> &&message_interaction_graph_, object_ptr<StatisticalGraph> &&message_reaction_graph_)
  : message_interaction_graph_(std::move(message_interaction_graph_))
  , message_reaction_graph_(std::move(message_reaction_graph_))
{}

const std::int32_t messageStatistics::ID;

void messageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageStatistics");
    s.store_object_field("message_interaction_graph", static_cast<const BaseObject *>(message_interaction_graph_.get()));
    s.store_object_field("message_reaction_graph", static_cast<const BaseObject *>(message_reaction_graph_.get()));
    s.store_class_end();
  }
}

messageViewers::messageViewers()
  : viewers_()
{}

messageViewers::messageViewers(array<object_ptr<messageViewer>> &&viewers_)
  : viewers_(std::move(viewers_))
{}

const std::int32_t messageViewers::ID;

void messageViewers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageViewers");
    { s.store_vector_begin("viewers", viewers_.size()); for (const auto &_value : viewers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

networkStatisticsEntryFile::networkStatisticsEntryFile()
  : file_type_()
  , network_type_()
  , sent_bytes_()
  , received_bytes_()
{}

networkStatisticsEntryFile::networkStatisticsEntryFile(object_ptr<FileType> &&file_type_, object_ptr<NetworkType> &&network_type_, int53 sent_bytes_, int53 received_bytes_)
  : file_type_(std::move(file_type_))
  , network_type_(std::move(network_type_))
  , sent_bytes_(sent_bytes_)
  , received_bytes_(received_bytes_)
{}

const std::int32_t networkStatisticsEntryFile::ID;

void networkStatisticsEntryFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkStatisticsEntryFile");
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_object_field("network_type", static_cast<const BaseObject *>(network_type_.get()));
    s.store_field("sent_bytes", sent_bytes_);
    s.store_field("received_bytes", received_bytes_);
    s.store_class_end();
  }
}

networkStatisticsEntryCall::networkStatisticsEntryCall()
  : network_type_()
  , sent_bytes_()
  , received_bytes_()
  , duration_()
{}

networkStatisticsEntryCall::networkStatisticsEntryCall(object_ptr<NetworkType> &&network_type_, int53 sent_bytes_, int53 received_bytes_, double duration_)
  : network_type_(std::move(network_type_))
  , sent_bytes_(sent_bytes_)
  , received_bytes_(received_bytes_)
  , duration_(duration_)
{}

const std::int32_t networkStatisticsEntryCall::ID;

void networkStatisticsEntryCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkStatisticsEntryCall");
    s.store_object_field("network_type", static_cast<const BaseObject *>(network_type_.get()));
    s.store_field("sent_bytes", sent_bytes_);
    s.store_field("received_bytes", received_bytes_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

notificationGroup::notificationGroup()
  : id_()
  , type_()
  , chat_id_()
  , total_count_()
  , notifications_()
{}

notificationGroup::notificationGroup(int32 id_, object_ptr<NotificationGroupType> &&type_, int53 chat_id_, int32 total_count_, array<object_ptr<notification>> &&notifications_)
  : id_(id_)
  , type_(std::move(type_))
  , chat_id_(chat_id_)
  , total_count_(total_count_)
  , notifications_(std::move(notifications_))
{}

const std::int32_t notificationGroup::ID;

void notificationGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroup");
    s.store_field("id", id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("notifications", notifications_.size()); for (const auto &_value : notifications_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

notificationTypeNewMessage::notificationTypeNewMessage()
  : message_()
  , show_preview_()
{}

notificationTypeNewMessage::notificationTypeNewMessage(object_ptr<message> &&message_, bool show_preview_)
  : message_(std::move(message_))
  , show_preview_(show_preview_)
{}

const std::int32_t notificationTypeNewMessage::ID;

void notificationTypeNewMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("show_preview", show_preview_);
    s.store_class_end();
  }
}

notificationTypeNewSecretChat::notificationTypeNewSecretChat() {
}

const std::int32_t notificationTypeNewSecretChat::ID;

void notificationTypeNewSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewSecretChat");
    s.store_class_end();
  }
}

notificationTypeNewCall::notificationTypeNewCall()
  : call_id_()
{}

notificationTypeNewCall::notificationTypeNewCall(int32 call_id_)
  : call_id_(call_id_)
{}

const std::int32_t notificationTypeNewCall::ID;

void notificationTypeNewCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewCall");
    s.store_field("call_id", call_id_);
    s.store_class_end();
  }
}

notificationTypeNewPushMessage::notificationTypeNewPushMessage()
  : message_id_()
  , sender_id_()
  , sender_name_()
  , is_outgoing_()
  , content_()
{}

notificationTypeNewPushMessage::notificationTypeNewPushMessage(int53 message_id_, object_ptr<MessageSender> &&sender_id_, string const &sender_name_, bool is_outgoing_, object_ptr<PushMessageContent> &&content_)
  : message_id_(message_id_)
  , sender_id_(std::move(sender_id_))
  , sender_name_(sender_name_)
  , is_outgoing_(is_outgoing_)
  , content_(std::move(content_))
{}

const std::int32_t notificationTypeNewPushMessage::ID;

void notificationTypeNewPushMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewPushMessage");
    s.store_field("message_id", message_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("sender_name", sender_name_);
    s.store_field("is_outgoing", is_outgoing_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

onRampPaymentSession::onRampPaymentSession()
  : session_id_()
  , expiration_date_()
  , url_()
{}

onRampPaymentSession::onRampPaymentSession(string const &session_id_, int32 expiration_date_, string const &url_)
  : session_id_(session_id_)
  , expiration_date_(expiration_date_)
  , url_(url_)
{}

const std::int32_t onRampPaymentSession::ID;

void onRampPaymentSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onRampPaymentSession");
    s.store_field("session_id", session_id_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

pageBlockCaption::pageBlockCaption()
  : text_()
  , credit_()
{}

pageBlockCaption::pageBlockCaption(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageBlockCaption::ID;

void pageBlockCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCaption");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

pollTypeRegular::pollTypeRegular() {
}

const std::int32_t pollTypeRegular::ID;

void pollTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollTypeRegular");
    s.store_class_end();
  }
}

pollTypeQuiz::pollTypeQuiz()
  : correct_option_ids_()
  , explanation_()
  , explanation_media_()
{}

pollTypeQuiz::pollTypeQuiz(array<int32> &&correct_option_ids_, object_ptr<formattedText> &&explanation_, object_ptr<PollMedia> &&explanation_media_)
  : correct_option_ids_(std::move(correct_option_ids_))
  , explanation_(std::move(explanation_))
  , explanation_media_(std::move(explanation_media_))
{}

const std::int32_t pollTypeQuiz::ID;

void pollTypeQuiz::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollTypeQuiz");
    { s.store_vector_begin("correct_option_ids", correct_option_ids_.size()); for (const auto &_value : correct_option_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("explanation", static_cast<const BaseObject *>(explanation_.get()));
    s.store_object_field("explanation_media", static_cast<const BaseObject *>(explanation_media_.get()));
    s.store_class_end();
  }
}

premiumFeatureIncreasedLimits::premiumFeatureIncreasedLimits() {
}

const std::int32_t premiumFeatureIncreasedLimits::ID;

void premiumFeatureIncreasedLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureIncreasedLimits");
    s.store_class_end();
  }
}

premiumFeatureIncreasedUploadFileSize::premiumFeatureIncreasedUploadFileSize() {
}

const std::int32_t premiumFeatureIncreasedUploadFileSize::ID;

void premiumFeatureIncreasedUploadFileSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureIncreasedUploadFileSize");
    s.store_class_end();
  }
}

premiumFeatureImprovedDownloadSpeed::premiumFeatureImprovedDownloadSpeed() {
}

const std::int32_t premiumFeatureImprovedDownloadSpeed::ID;

void premiumFeatureImprovedDownloadSpeed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureImprovedDownloadSpeed");
    s.store_class_end();
  }
}

premiumFeatureVoiceRecognition::premiumFeatureVoiceRecognition() {
}

const std::int32_t premiumFeatureVoiceRecognition::ID;

void premiumFeatureVoiceRecognition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureVoiceRecognition");
    s.store_class_end();
  }
}

premiumFeatureDisabledAds::premiumFeatureDisabledAds() {
}

const std::int32_t premiumFeatureDisabledAds::ID;

void premiumFeatureDisabledAds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureDisabledAds");
    s.store_class_end();
  }
}

premiumFeatureUniqueReactions::premiumFeatureUniqueReactions() {
}

const std::int32_t premiumFeatureUniqueReactions::ID;

void premiumFeatureUniqueReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureUniqueReactions");
    s.store_class_end();
  }
}

premiumFeatureUniqueStickers::premiumFeatureUniqueStickers() {
}

const std::int32_t premiumFeatureUniqueStickers::ID;

void premiumFeatureUniqueStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureUniqueStickers");
    s.store_class_end();
  }
}

premiumFeatureCustomEmoji::premiumFeatureCustomEmoji() {
}

const std::int32_t premiumFeatureCustomEmoji::ID;

void premiumFeatureCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureCustomEmoji");
    s.store_class_end();
  }
}

premiumFeatureAdvancedChatManagement::premiumFeatureAdvancedChatManagement() {
}

const std::int32_t premiumFeatureAdvancedChatManagement::ID;

void premiumFeatureAdvancedChatManagement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureAdvancedChatManagement");
    s.store_class_end();
  }
}

premiumFeatureProfileBadge::premiumFeatureProfileBadge() {
}

const std::int32_t premiumFeatureProfileBadge::ID;

void premiumFeatureProfileBadge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureProfileBadge");
    s.store_class_end();
  }
}

premiumFeatureEmojiStatus::premiumFeatureEmojiStatus() {
}

const std::int32_t premiumFeatureEmojiStatus::ID;

void premiumFeatureEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureEmojiStatus");
    s.store_class_end();
  }
}

premiumFeatureAnimatedProfilePhoto::premiumFeatureAnimatedProfilePhoto() {
}

const std::int32_t premiumFeatureAnimatedProfilePhoto::ID;

void premiumFeatureAnimatedProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureAnimatedProfilePhoto");
    s.store_class_end();
  }
}

premiumFeatureForumTopicIcon::premiumFeatureForumTopicIcon() {
}

const std::int32_t premiumFeatureForumTopicIcon::ID;

void premiumFeatureForumTopicIcon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureForumTopicIcon");
    s.store_class_end();
  }
}

premiumFeatureAppIcons::premiumFeatureAppIcons() {
}

const std::int32_t premiumFeatureAppIcons::ID;

void premiumFeatureAppIcons::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureAppIcons");
    s.store_class_end();
  }
}

premiumFeatureRealTimeChatTranslation::premiumFeatureRealTimeChatTranslation() {
}

const std::int32_t premiumFeatureRealTimeChatTranslation::ID;

void premiumFeatureRealTimeChatTranslation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureRealTimeChatTranslation");
    s.store_class_end();
  }
}

premiumFeatureUpgradedStories::premiumFeatureUpgradedStories() {
}

const std::int32_t premiumFeatureUpgradedStories::ID;

void premiumFeatureUpgradedStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureUpgradedStories");
    s.store_class_end();
  }
}

premiumFeatureChatBoost::premiumFeatureChatBoost() {
}

const std::int32_t premiumFeatureChatBoost::ID;

void premiumFeatureChatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureChatBoost");
    s.store_class_end();
  }
}

premiumFeatureAccentColor::premiumFeatureAccentColor() {
}

const std::int32_t premiumFeatureAccentColor::ID;

void premiumFeatureAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureAccentColor");
    s.store_class_end();
  }
}

premiumFeatureBackgroundForBoth::premiumFeatureBackgroundForBoth() {
}

const std::int32_t premiumFeatureBackgroundForBoth::ID;

void premiumFeatureBackgroundForBoth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureBackgroundForBoth");
    s.store_class_end();
  }
}

premiumFeatureSavedMessagesTags::premiumFeatureSavedMessagesTags() {
}

const std::int32_t premiumFeatureSavedMessagesTags::ID;

void premiumFeatureSavedMessagesTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureSavedMessagesTags");
    s.store_class_end();
  }
}

premiumFeatureMessagePrivacy::premiumFeatureMessagePrivacy() {
}

const std::int32_t premiumFeatureMessagePrivacy::ID;

void premiumFeatureMessagePrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureMessagePrivacy");
    s.store_class_end();
  }
}

premiumFeatureLastSeenTimes::premiumFeatureLastSeenTimes() {
}

const std::int32_t premiumFeatureLastSeenTimes::ID;

void premiumFeatureLastSeenTimes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureLastSeenTimes");
    s.store_class_end();
  }
}

premiumFeatureBusiness::premiumFeatureBusiness() {
}

const std::int32_t premiumFeatureBusiness::ID;

void premiumFeatureBusiness::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureBusiness");
    s.store_class_end();
  }
}

premiumFeatureMessageEffects::premiumFeatureMessageEffects() {
}

const std::int32_t premiumFeatureMessageEffects::ID;

void premiumFeatureMessageEffects::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureMessageEffects");
    s.store_class_end();
  }
}

premiumFeatureChecklists::premiumFeatureChecklists() {
}

const std::int32_t premiumFeatureChecklists::ID;

void premiumFeatureChecklists::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureChecklists");
    s.store_class_end();
  }
}

premiumFeaturePaidMessages::premiumFeaturePaidMessages() {
}

const std::int32_t premiumFeaturePaidMessages::ID;

void premiumFeaturePaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeaturePaidMessages");
    s.store_class_end();
  }
}

premiumFeatureProtectPrivateChatContent::premiumFeatureProtectPrivateChatContent() {
}

const std::int32_t premiumFeatureProtectPrivateChatContent::ID;

void premiumFeatureProtectPrivateChatContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureProtectPrivateChatContent");
    s.store_class_end();
  }
}

premiumFeatureTextComposition::premiumFeatureTextComposition() {
}

const std::int32_t premiumFeatureTextComposition::ID;

void premiumFeatureTextComposition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureTextComposition");
    s.store_class_end();
  }
}

premiumFeatureRichMessages::premiumFeatureRichMessages() {
}

const std::int32_t premiumFeatureRichMessages::ID;

void premiumFeatureRichMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureRichMessages");
    s.store_class_end();
  }
}

premiumFeatures::premiumFeatures()
  : features_()
  , limits_()
  , payment_link_()
{}

premiumFeatures::premiumFeatures(array<object_ptr<PremiumFeature>> &&features_, array<object_ptr<premiumLimit>> &&limits_, object_ptr<InternalLinkType> &&payment_link_)
  : features_(std::move(features_))
  , limits_(std::move(limits_))
  , payment_link_(std::move(payment_link_))
{}

const std::int32_t premiumFeatures::ID;

void premiumFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatures");
    { s.store_vector_begin("features", features_.size()); for (const auto &_value : features_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("limits", limits_.size()); for (const auto &_value : limits_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("payment_link", static_cast<const BaseObject *>(payment_link_.get()));
    s.store_class_end();
  }
}

premiumGiftCodeInfo::premiumGiftCodeInfo()
  : creator_id_()
  , creation_date_()
  , is_from_giveaway_()
  , giveaway_message_id_()
  , month_count_()
  , day_count_()
  , user_id_()
  , use_date_()
{}

premiumGiftCodeInfo::premiumGiftCodeInfo(object_ptr<MessageSender> &&creator_id_, int32 creation_date_, bool is_from_giveaway_, int53 giveaway_message_id_, int32 month_count_, int32 day_count_, int53 user_id_, int32 use_date_)
  : creator_id_(std::move(creator_id_))
  , creation_date_(creation_date_)
  , is_from_giveaway_(is_from_giveaway_)
  , giveaway_message_id_(giveaway_message_id_)
  , month_count_(month_count_)
  , day_count_(day_count_)
  , user_id_(user_id_)
  , use_date_(use_date_)
{}

const std::int32_t premiumGiftCodeInfo::ID;

void premiumGiftCodeInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiftCodeInfo");
    s.store_object_field("creator_id", static_cast<const BaseObject *>(creator_id_.get()));
    s.store_field("creation_date", creation_date_);
    s.store_field("is_from_giveaway", is_from_giveaway_);
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_field("month_count", month_count_);
    s.store_field("day_count", day_count_);
    s.store_field("user_id", user_id_);
    s.store_field("use_date", use_date_);
    s.store_class_end();
  }
}

premiumState::premiumState()
  : state_()
  , payment_options_()
  , animations_()
  , business_animations_()
{}

premiumState::premiumState(object_ptr<formattedText> &&state_, array<object_ptr<premiumStatePaymentOption>> &&payment_options_, array<object_ptr<premiumFeaturePromotionAnimation>> &&animations_, array<object_ptr<businessFeaturePromotionAnimation>> &&business_animations_)
  : state_(std::move(state_))
  , payment_options_(std::move(payment_options_))
  , animations_(std::move(animations_))
  , business_animations_(std::move(business_animations_))
{}

const std::int32_t premiumState::ID;

void premiumState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumState");
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    { s.store_vector_begin("payment_options", payment_options_.size()); for (const auto &_value : payment_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("animations", animations_.size()); for (const auto &_value : animations_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("business_animations", business_animations_.size()); for (const auto &_value : business_animations_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

preparedInlineMessageId::preparedInlineMessageId()
  : id_()
  , expiration_date_()
{}

preparedInlineMessageId::preparedInlineMessageId(string const &id_, int32 expiration_date_)
  : id_(id_)
  , expiration_date_(expiration_date_)
{}

const std::int32_t preparedInlineMessageId::ID;

void preparedInlineMessageId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "preparedInlineMessageId");
    s.store_field("id", id_);
    s.store_field("expiration_date", expiration_date_);
    s.store_class_end();
  }
}

proxyTypeSocks5::proxyTypeSocks5()
  : username_()
  , password_()
{}

proxyTypeSocks5::proxyTypeSocks5(string const &username_, string const &password_)
  : username_(username_)
  , password_(password_)
{}

const std::int32_t proxyTypeSocks5::ID;

void proxyTypeSocks5::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxyTypeSocks5");
    s.store_field("username", username_);
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

proxyTypeHttp::proxyTypeHttp()
  : username_()
  , password_()
  , http_only_()
{}

proxyTypeHttp::proxyTypeHttp(string const &username_, string const &password_, bool http_only_)
  : username_(username_)
  , password_(password_)
  , http_only_(http_only_)
{}

const std::int32_t proxyTypeHttp::ID;

void proxyTypeHttp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxyTypeHttp");
    s.store_field("username", username_);
    s.store_field("password", "[REDACTED]");
    s.store_field("http_only", http_only_);
    s.store_class_end();
  }
}

proxyTypeMtproto::proxyTypeMtproto()
  : secret_()
{}

proxyTypeMtproto::proxyTypeMtproto(string const &secret_)
  : secret_(secret_)
{}

const std::int32_t proxyTypeMtproto::ID;

void proxyTypeMtproto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxyTypeMtproto");
    s.store_field("secret", "[REDACTED]");
    s.store_class_end();
  }
}

proxyTypeWeb::proxyTypeWeb()
  : path_()
  , secret_()
{}

proxyTypeWeb::proxyTypeWeb(string const &path_, string const &secret_)
  : path_(path_)
  , secret_(secret_)
{}

const std::int32_t proxyTypeWeb::ID;

void proxyTypeWeb::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxyTypeWeb");
    s.store_field("path", path_);
    s.store_field("secret", "[REDACTED]");
    s.store_class_end();
  }
}

pushMessageContentHidden::pushMessageContentHidden()
  : is_pinned_()
{}

pushMessageContentHidden::pushMessageContentHidden(bool is_pinned_)
  : is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentHidden::ID;

void pushMessageContentHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentHidden");
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentAnimation::pushMessageContentAnimation()
  : animation_()
  , caption_()
  , is_pinned_()
{}

pushMessageContentAnimation::pushMessageContentAnimation(object_ptr<animation> &&animation_, string const &caption_, bool is_pinned_)
  : animation_(std::move(animation_))
  , caption_(caption_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentAnimation::ID;

void pushMessageContentAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_field("caption", caption_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentAudio::pushMessageContentAudio()
  : audio_()
  , is_pinned_()
{}

pushMessageContentAudio::pushMessageContentAudio(object_ptr<audio> &&audio_, bool is_pinned_)
  : audio_(std::move(audio_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentAudio::ID;

void pushMessageContentAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentContact::pushMessageContentContact()
  : name_()
  , is_pinned_()
{}

pushMessageContentContact::pushMessageContentContact(string const &name_, bool is_pinned_)
  : name_(name_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentContact::ID;

void pushMessageContentContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentContact");
    s.store_field("name", name_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentContactRegistered::pushMessageContentContactRegistered()
  : as_premium_account_()
{}

pushMessageContentContactRegistered::pushMessageContentContactRegistered(bool as_premium_account_)
  : as_premium_account_(as_premium_account_)
{}

const std::int32_t pushMessageContentContactRegistered::ID;

void pushMessageContentContactRegistered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentContactRegistered");
    s.store_field("as_premium_account", as_premium_account_);
    s.store_class_end();
  }
}

pushMessageContentDocument::pushMessageContentDocument()
  : document_()
  , is_pinned_()
{}

pushMessageContentDocument::pushMessageContentDocument(object_ptr<document> &&document_, bool is_pinned_)
  : document_(std::move(document_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentDocument::ID;

void pushMessageContentDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentGame::pushMessageContentGame()
  : title_()
  , is_pinned_()
{}

pushMessageContentGame::pushMessageContentGame(string const &title_, bool is_pinned_)
  : title_(title_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentGame::ID;

void pushMessageContentGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentGame");
    s.store_field("title", title_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentGameScore::pushMessageContentGameScore()
  : title_()
  , score_()
  , is_pinned_()
{}

pushMessageContentGameScore::pushMessageContentGameScore(string const &title_, int32 score_, bool is_pinned_)
  : title_(title_)
  , score_(score_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentGameScore::ID;

void pushMessageContentGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentGameScore");
    s.store_field("title", title_);
    s.store_field("score", score_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentInvoice::pushMessageContentInvoice()
  : price_()
  , is_pinned_()
{}

pushMessageContentInvoice::pushMessageContentInvoice(string const &price_, bool is_pinned_)
  : price_(price_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentInvoice::ID;

void pushMessageContentInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentInvoice");
    s.store_field("price", price_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentLocation::pushMessageContentLocation()
  : is_live_()
  , is_pinned_()
{}

pushMessageContentLocation::pushMessageContentLocation(bool is_live_, bool is_pinned_)
  : is_live_(is_live_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentLocation::ID;

void pushMessageContentLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentLocation");
    s.store_field("is_live", is_live_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentPaidMedia::pushMessageContentPaidMedia()
  : star_count_()
  , is_pinned_()
{}

pushMessageContentPaidMedia::pushMessageContentPaidMedia(int53 star_count_, bool is_pinned_)
  : star_count_(star_count_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentPaidMedia::ID;

void pushMessageContentPaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPaidMedia");
    s.store_field("star_count", star_count_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentPhoto::pushMessageContentPhoto()
  : photo_()
  , caption_()
  , is_secret_()
  , is_pinned_()
{}

pushMessageContentPhoto::pushMessageContentPhoto(object_ptr<photo> &&photo_, string const &caption_, bool is_secret_, bool is_pinned_)
  : photo_(std::move(photo_))
  , caption_(caption_)
  , is_secret_(is_secret_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentPhoto::ID;

void pushMessageContentPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("caption", caption_);
    s.store_field("is_secret", is_secret_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentPoll::pushMessageContentPoll()
  : question_()
  , is_regular_()
  , is_pinned_()
{}

pushMessageContentPoll::pushMessageContentPoll(string const &question_, bool is_regular_, bool is_pinned_)
  : question_(question_)
  , is_regular_(is_regular_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentPoll::ID;

void pushMessageContentPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPoll");
    s.store_field("question", question_);
    s.store_field("is_regular", is_regular_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentPremiumGiftCode::pushMessageContentPremiumGiftCode()
  : month_count_()
{}

pushMessageContentPremiumGiftCode::pushMessageContentPremiumGiftCode(int32 month_count_)
  : month_count_(month_count_)
{}

const std::int32_t pushMessageContentPremiumGiftCode::ID;

void pushMessageContentPremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPremiumGiftCode");
    s.store_field("month_count", month_count_);
    s.store_class_end();
  }
}

pushMessageContentGiveaway::pushMessageContentGiveaway()
  : winner_count_()
  , prize_()
  , is_pinned_()
{}

pushMessageContentGiveaway::pushMessageContentGiveaway(int32 winner_count_, object_ptr<GiveawayPrize> &&prize_, bool is_pinned_)
  : winner_count_(winner_count_)
  , prize_(std::move(prize_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentGiveaway::ID;

void pushMessageContentGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentGiveaway");
    s.store_field("winner_count", winner_count_);
    s.store_object_field("prize", static_cast<const BaseObject *>(prize_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentTonWalletTransfer::pushMessageContentTonWalletTransfer()
  : sender_user_id_()
  , amount_()
  , comment_()
{}

pushMessageContentTonWalletTransfer::pushMessageContentTonWalletTransfer(int53 sender_user_id_, string const &amount_, string const &comment_)
  : sender_user_id_(sender_user_id_)
  , amount_(amount_)
  , comment_(comment_)
{}

const std::int32_t pushMessageContentTonWalletTransfer::ID;

void pushMessageContentTonWalletTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentTonWalletTransfer");
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("amount", amount_);
    s.store_field("comment", comment_);
    s.store_class_end();
  }
}

pushMessageContentTonConnectRequest::pushMessageContentTonConnectRequest()
  : dapp_name_()
{}

pushMessageContentTonConnectRequest::pushMessageContentTonConnectRequest(string const &dapp_name_)
  : dapp_name_(dapp_name_)
{}

const std::int32_t pushMessageContentTonConnectRequest::ID;

void pushMessageContentTonConnectRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentTonConnectRequest");
    s.store_field("dapp_name", dapp_name_);
    s.store_class_end();
  }
}

pushMessageContentGift::pushMessageContentGift()
  : star_count_()
  , is_prepaid_upgrade_()
{}

pushMessageContentGift::pushMessageContentGift(int53 star_count_, bool is_prepaid_upgrade_)
  : star_count_(star_count_)
  , is_prepaid_upgrade_(is_prepaid_upgrade_)
{}

const std::int32_t pushMessageContentGift::ID;

void pushMessageContentGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentGift");
    s.store_field("star_count", star_count_);
    s.store_field("is_prepaid_upgrade", is_prepaid_upgrade_);
    s.store_class_end();
  }
}

pushMessageContentUpgradedGift::pushMessageContentUpgradedGift()
  : is_upgrade_()
  , is_prepaid_upgrade_()
{}

pushMessageContentUpgradedGift::pushMessageContentUpgradedGift(bool is_upgrade_, bool is_prepaid_upgrade_)
  : is_upgrade_(is_upgrade_)
  , is_prepaid_upgrade_(is_prepaid_upgrade_)
{}

const std::int32_t pushMessageContentUpgradedGift::ID;

void pushMessageContentUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentUpgradedGift");
    s.store_field("is_upgrade", is_upgrade_);
    s.store_field("is_prepaid_upgrade", is_prepaid_upgrade_);
    s.store_class_end();
  }
}

pushMessageContentScreenshotTaken::pushMessageContentScreenshotTaken() {
}

const std::int32_t pushMessageContentScreenshotTaken::ID;

void pushMessageContentScreenshotTaken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentScreenshotTaken");
    s.store_class_end();
  }
}

pushMessageContentSticker::pushMessageContentSticker()
  : sticker_()
  , emoji_()
  , is_pinned_()
{}

pushMessageContentSticker::pushMessageContentSticker(object_ptr<sticker> &&sticker_, string const &emoji_, bool is_pinned_)
  : sticker_(std::move(sticker_))
  , emoji_(emoji_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentSticker::ID;

void pushMessageContentSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("emoji", emoji_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentStory::pushMessageContentStory()
  : is_mention_()
  , is_pinned_()
{}

pushMessageContentStory::pushMessageContentStory(bool is_mention_, bool is_pinned_)
  : is_mention_(is_mention_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentStory::ID;

void pushMessageContentStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentStory");
    s.store_field("is_mention", is_mention_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentText::pushMessageContentText()
  : text_()
  , is_pinned_()
{}

pushMessageContentText::pushMessageContentText(string const &text_, bool is_pinned_)
  : text_(text_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentText::ID;

void pushMessageContentText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentText");
    s.store_field("text", text_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentChecklist::pushMessageContentChecklist()
  : title_()
  , is_pinned_()
{}

pushMessageContentChecklist::pushMessageContentChecklist(string const &title_, bool is_pinned_)
  : title_(title_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentChecklist::ID;

void pushMessageContentChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChecklist");
    s.store_field("title", title_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentVideo::pushMessageContentVideo()
  : video_()
  , caption_()
  , is_secret_()
  , is_pinned_()
{}

pushMessageContentVideo::pushMessageContentVideo(object_ptr<video> &&video_, string const &caption_, bool is_secret_, bool is_pinned_)
  : video_(std::move(video_))
  , caption_(caption_)
  , is_secret_(is_secret_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentVideo::ID;

void pushMessageContentVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_field("caption", caption_);
    s.store_field("is_secret", is_secret_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentVideoNote::pushMessageContentVideoNote()
  : video_note_()
  , is_pinned_()
{}

pushMessageContentVideoNote::pushMessageContentVideoNote(object_ptr<videoNote> &&video_note_, bool is_pinned_)
  : video_note_(std::move(video_note_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentVideoNote::ID;

void pushMessageContentVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentVoiceNote::pushMessageContentVoiceNote()
  : voice_note_()
  , is_pinned_()
{}

pushMessageContentVoiceNote::pushMessageContentVoiceNote(object_ptr<voiceNote> &&voice_note_, bool is_pinned_)
  : voice_note_(std::move(voice_note_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentVoiceNote::ID;

void pushMessageContentVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentBasicGroupChatCreate::pushMessageContentBasicGroupChatCreate() {
}

const std::int32_t pushMessageContentBasicGroupChatCreate::ID;

void pushMessageContentBasicGroupChatCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentBasicGroupChatCreate");
    s.store_class_end();
  }
}

pushMessageContentVideoChatStarted::pushMessageContentVideoChatStarted() {
}

const std::int32_t pushMessageContentVideoChatStarted::ID;

void pushMessageContentVideoChatStarted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVideoChatStarted");
    s.store_class_end();
  }
}

pushMessageContentVideoChatEnded::pushMessageContentVideoChatEnded() {
}

const std::int32_t pushMessageContentVideoChatEnded::ID;

void pushMessageContentVideoChatEnded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVideoChatEnded");
    s.store_class_end();
  }
}

pushMessageContentInviteVideoChatParticipants::pushMessageContentInviteVideoChatParticipants()
  : is_current_user_()
{}

pushMessageContentInviteVideoChatParticipants::pushMessageContentInviteVideoChatParticipants(bool is_current_user_)
  : is_current_user_(is_current_user_)
{}

const std::int32_t pushMessageContentInviteVideoChatParticipants::ID;

void pushMessageContentInviteVideoChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentInviteVideoChatParticipants");
    s.store_field("is_current_user", is_current_user_);
    s.store_class_end();
  }
}

pushMessageContentChatAddMembers::pushMessageContentChatAddMembers()
  : member_name_()
  , is_current_user_()
  , is_returned_()
{}

pushMessageContentChatAddMembers::pushMessageContentChatAddMembers(string const &member_name_, bool is_current_user_, bool is_returned_)
  : member_name_(member_name_)
  , is_current_user_(is_current_user_)
  , is_returned_(is_returned_)
{}

const std::int32_t pushMessageContentChatAddMembers::ID;

void pushMessageContentChatAddMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatAddMembers");
    s.store_field("member_name", member_name_);
    s.store_field("is_current_user", is_current_user_);
    s.store_field("is_returned", is_returned_);
    s.store_class_end();
  }
}

pushMessageContentChatChangePhoto::pushMessageContentChatChangePhoto() {
}

const std::int32_t pushMessageContentChatChangePhoto::ID;

void pushMessageContentChatChangePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatChangePhoto");
    s.store_class_end();
  }
}

pushMessageContentChatChangeTitle::pushMessageContentChatChangeTitle()
  : title_()
{}

pushMessageContentChatChangeTitle::pushMessageContentChatChangeTitle(string const &title_)
  : title_(title_)
{}

const std::int32_t pushMessageContentChatChangeTitle::ID;

void pushMessageContentChatChangeTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatChangeTitle");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

pushMessageContentChatSetBackground::pushMessageContentChatSetBackground()
  : is_same_()
{}

pushMessageContentChatSetBackground::pushMessageContentChatSetBackground(bool is_same_)
  : is_same_(is_same_)
{}

const std::int32_t pushMessageContentChatSetBackground::ID;

void pushMessageContentChatSetBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatSetBackground");
    s.store_field("is_same", is_same_);
    s.store_class_end();
  }
}

pushMessageContentChatSetTheme::pushMessageContentChatSetTheme()
  : name_()
{}

pushMessageContentChatSetTheme::pushMessageContentChatSetTheme(string const &name_)
  : name_(name_)
{}

const std::int32_t pushMessageContentChatSetTheme::ID;

void pushMessageContentChatSetTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatSetTheme");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

pushMessageContentChatDeleteMember::pushMessageContentChatDeleteMember()
  : member_name_()
  , is_current_user_()
  , is_left_()
{}

pushMessageContentChatDeleteMember::pushMessageContentChatDeleteMember(string const &member_name_, bool is_current_user_, bool is_left_)
  : member_name_(member_name_)
  , is_current_user_(is_current_user_)
  , is_left_(is_left_)
{}

const std::int32_t pushMessageContentChatDeleteMember::ID;

void pushMessageContentChatDeleteMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatDeleteMember");
    s.store_field("member_name", member_name_);
    s.store_field("is_current_user", is_current_user_);
    s.store_field("is_left", is_left_);
    s.store_class_end();
  }
}

pushMessageContentChatJoinByLink::pushMessageContentChatJoinByLink() {
}

const std::int32_t pushMessageContentChatJoinByLink::ID;

void pushMessageContentChatJoinByLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatJoinByLink");
    s.store_class_end();
  }
}

pushMessageContentChatJoinByRequest::pushMessageContentChatJoinByRequest() {
}

const std::int32_t pushMessageContentChatJoinByRequest::ID;

void pushMessageContentChatJoinByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatJoinByRequest");
    s.store_class_end();
  }
}

pushMessageContentRecurringPayment::pushMessageContentRecurringPayment()
  : amount_()
{}

pushMessageContentRecurringPayment::pushMessageContentRecurringPayment(string const &amount_)
  : amount_(amount_)
{}

const std::int32_t pushMessageContentRecurringPayment::ID;

void pushMessageContentRecurringPayment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentRecurringPayment");
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

pushMessageContentSuggestProfilePhoto::pushMessageContentSuggestProfilePhoto() {
}

const std::int32_t pushMessageContentSuggestProfilePhoto::ID;

void pushMessageContentSuggestProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentSuggestProfilePhoto");
    s.store_class_end();
  }
}

pushMessageContentSuggestBirthdate::pushMessageContentSuggestBirthdate() {
}

const std::int32_t pushMessageContentSuggestBirthdate::ID;

void pushMessageContentSuggestBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentSuggestBirthdate");
    s.store_class_end();
  }
}

pushMessageContentProximityAlertTriggered::pushMessageContentProximityAlertTriggered()
  : distance_()
{}

pushMessageContentProximityAlertTriggered::pushMessageContentProximityAlertTriggered(int32 distance_)
  : distance_(distance_)
{}

const std::int32_t pushMessageContentProximityAlertTriggered::ID;

void pushMessageContentProximityAlertTriggered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentProximityAlertTriggered");
    s.store_field("distance", distance_);
    s.store_class_end();
  }
}

pushMessageContentChecklistTasksAdded::pushMessageContentChecklistTasksAdded()
  : task_count_()
{}

pushMessageContentChecklistTasksAdded::pushMessageContentChecklistTasksAdded(int32 task_count_)
  : task_count_(task_count_)
{}

const std::int32_t pushMessageContentChecklistTasksAdded::ID;

void pushMessageContentChecklistTasksAdded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChecklistTasksAdded");
    s.store_field("task_count", task_count_);
    s.store_class_end();
  }
}

pushMessageContentChecklistTasksDone::pushMessageContentChecklistTasksDone()
  : task_count_()
{}

pushMessageContentChecklistTasksDone::pushMessageContentChecklistTasksDone(int32 task_count_)
  : task_count_(task_count_)
{}

const std::int32_t pushMessageContentChecklistTasksDone::ID;

void pushMessageContentChecklistTasksDone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChecklistTasksDone");
    s.store_field("task_count", task_count_);
    s.store_class_end();
  }
}

pushMessageContentPollOptionAdded::pushMessageContentPollOptionAdded()
  : text_()
{}

pushMessageContentPollOptionAdded::pushMessageContentPollOptionAdded(string const &text_)
  : text_(text_)
{}

const std::int32_t pushMessageContentPollOptionAdded::ID;

void pushMessageContentPollOptionAdded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPollOptionAdded");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

pushMessageContentMessageForwards::pushMessageContentMessageForwards()
  : total_count_()
{}

pushMessageContentMessageForwards::pushMessageContentMessageForwards(int32 total_count_)
  : total_count_(total_count_)
{}

const std::int32_t pushMessageContentMessageForwards::ID;

void pushMessageContentMessageForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentMessageForwards");
    s.store_field("total_count", total_count_);
    s.store_class_end();
  }
}

pushMessageContentMediaAlbum::pushMessageContentMediaAlbum()
  : total_count_()
  , has_photos_()
  , has_videos_()
  , has_audios_()
  , has_documents_()
{}

pushMessageContentMediaAlbum::pushMessageContentMediaAlbum(int32 total_count_, bool has_photos_, bool has_videos_, bool has_audios_, bool has_documents_)
  : total_count_(total_count_)
  , has_photos_(has_photos_)
  , has_videos_(has_videos_)
  , has_audios_(has_audios_)
  , has_documents_(has_documents_)
{}

const std::int32_t pushMessageContentMediaAlbum::ID;

void pushMessageContentMediaAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentMediaAlbum");
    s.store_field("total_count", total_count_);
    s.store_field("has_photos", has_photos_);
    s.store_field("has_videos", has_videos_);
    s.store_field("has_audios", has_audios_);
    s.store_field("has_documents", has_documents_);
    s.store_class_end();
  }
}

reportChatResultOk::reportChatResultOk() {
}

const std::int32_t reportChatResultOk::ID;

void reportChatResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatResultOk");
    s.store_class_end();
  }
}

reportChatResultOptionRequired::reportChatResultOptionRequired()
  : title_()
  , options_()
{}

reportChatResultOptionRequired::reportChatResultOptionRequired(string const &title_, array<object_ptr<reportOption>> &&options_)
  : title_(title_)
  , options_(std::move(options_))
{}

const std::int32_t reportChatResultOptionRequired::ID;

void reportChatResultOptionRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatResultOptionRequired");
    s.store_field("title", title_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportChatResultTextRequired::reportChatResultTextRequired()
  : option_id_()
  , is_optional_()
{}

reportChatResultTextRequired::reportChatResultTextRequired(bytes const &option_id_, bool is_optional_)
  : option_id_(std::move(option_id_))
  , is_optional_(is_optional_)
{}

const std::int32_t reportChatResultTextRequired::ID;

void reportChatResultTextRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatResultTextRequired");
    s.store_bytes_field("option_id", option_id_);
    s.store_field("is_optional", is_optional_);
    s.store_class_end();
  }
}

reportChatResultMessagesRequired::reportChatResultMessagesRequired() {
}

const std::int32_t reportChatResultMessagesRequired::ID;

void reportChatResultMessagesRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatResultMessagesRequired");
    s.store_class_end();
  }
}

reportReasonSpam::reportReasonSpam() {
}

const std::int32_t reportReasonSpam::ID;

void reportReasonSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonSpam");
    s.store_class_end();
  }
}

reportReasonViolence::reportReasonViolence() {
}

const std::int32_t reportReasonViolence::ID;

void reportReasonViolence::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonViolence");
    s.store_class_end();
  }
}

reportReasonPornography::reportReasonPornography() {
}

const std::int32_t reportReasonPornography::ID;

void reportReasonPornography::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonPornography");
    s.store_class_end();
  }
}

reportReasonChildAbuse::reportReasonChildAbuse() {
}

const std::int32_t reportReasonChildAbuse::ID;

void reportReasonChildAbuse::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonChildAbuse");
    s.store_class_end();
  }
}

reportReasonCopyright::reportReasonCopyright() {
}

const std::int32_t reportReasonCopyright::ID;

void reportReasonCopyright::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonCopyright");
    s.store_class_end();
  }
}

reportReasonUnrelatedLocation::reportReasonUnrelatedLocation() {
}

const std::int32_t reportReasonUnrelatedLocation::ID;

void reportReasonUnrelatedLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonUnrelatedLocation");
    s.store_class_end();
  }
}

reportReasonFake::reportReasonFake() {
}

const std::int32_t reportReasonFake::ID;

void reportReasonFake::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonFake");
    s.store_class_end();
  }
}

reportReasonIllegalDrugs::reportReasonIllegalDrugs() {
}

const std::int32_t reportReasonIllegalDrugs::ID;

void reportReasonIllegalDrugs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonIllegalDrugs");
    s.store_class_end();
  }
}

reportReasonPersonalDetails::reportReasonPersonalDetails() {
}

const std::int32_t reportReasonPersonalDetails::ID;

void reportReasonPersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonPersonalDetails");
    s.store_class_end();
  }
}

reportReasonCustom::reportReasonCustom() {
}

const std::int32_t reportReasonCustom::ID;

void reportReasonCustom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonCustom");
    s.store_class_end();
  }
}

revenueWithdrawalStatePending::revenueWithdrawalStatePending() {
}

const std::int32_t revenueWithdrawalStatePending::ID;

void revenueWithdrawalStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revenueWithdrawalStatePending");
    s.store_class_end();
  }
}

revenueWithdrawalStateSucceeded::revenueWithdrawalStateSucceeded()
  : date_()
  , url_()
{}

revenueWithdrawalStateSucceeded::revenueWithdrawalStateSucceeded(int32 date_, string const &url_)
  : date_(date_)
  , url_(url_)
{}

const std::int32_t revenueWithdrawalStateSucceeded::ID;

void revenueWithdrawalStateSucceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revenueWithdrawalStateSucceeded");
    s.store_field("date", date_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

revenueWithdrawalStateFailed::revenueWithdrawalStateFailed() {
}

const std::int32_t revenueWithdrawalStateFailed::ID;

void revenueWithdrawalStateFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revenueWithdrawalStateFailed");
    s.store_class_end();
  }
}

secretChat::secretChat()
  : id_()
  , user_id_()
  , state_()
  , is_outbound_()
  , key_hash_()
  , layer_()
{}

secretChat::secretChat(int32 id_, int53 user_id_, object_ptr<SecretChatState> &&state_, bool is_outbound_, bytes const &key_hash_, int32 layer_)
  : id_(id_)
  , user_id_(user_id_)
  , state_(std::move(state_))
  , is_outbound_(is_outbound_)
  , key_hash_(std::move(key_hash_))
  , layer_(layer_)
{}

const std::int32_t secretChat::ID;

void secretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChat");
    s.store_field("id", id_);
    s.store_field("user_id", user_id_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_field("is_outbound", is_outbound_);
    s.store_bytes_field("key_hash", key_hash_);
    s.store_field("layer", layer_);
    s.store_class_end();
  }
}

starGiveawayPaymentOption::starGiveawayPaymentOption()
  : currency_()
  , amount_()
  , star_count_()
  , store_product_id_()
  , yearly_boost_count_()
  , winner_options_()
  , is_default_()
  , is_additional_()
{}

starGiveawayPaymentOption::starGiveawayPaymentOption(string const &currency_, int53 amount_, int53 star_count_, string const &store_product_id_, int32 yearly_boost_count_, array<object_ptr<starGiveawayWinnerOption>> &&winner_options_, bool is_default_, bool is_additional_)
  : currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
  , store_product_id_(store_product_id_)
  , yearly_boost_count_(yearly_boost_count_)
  , winner_options_(std::move(winner_options_))
  , is_default_(is_default_)
  , is_additional_(is_additional_)
{}

const std::int32_t starGiveawayPaymentOption::ID;

void starGiveawayPaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiveawayPaymentOption");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_field("store_product_id", store_product_id_);
    s.store_field("yearly_boost_count", yearly_boost_count_);
    { s.store_vector_begin("winner_options", winner_options_.size()); for (const auto &_value : winner_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_default", is_default_);
    s.store_field("is_additional", is_additional_);
    s.store_class_end();
  }
}

starPaymentOptions::starPaymentOptions()
  : options_()
{}

starPaymentOptions::starPaymentOptions(array<object_ptr<starPaymentOption>> &&options_)
  : options_(std::move(options_))
{}

const std::int32_t starPaymentOptions::ID;

void starPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starPaymentOptions");
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stickerSets::stickerSets()
  : total_count_()
  , sets_()
{}

stickerSets::stickerSets(int32 total_count_, array<object_ptr<stickerSetInfo>> &&sets_)
  : total_count_(total_count_)
  , sets_(std::move(sets_))
{}

const std::int32_t stickerSets::ID;

void stickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSets");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storageStatisticsByFileType::storageStatisticsByFileType()
  : file_type_()
  , size_()
  , count_()
{}

storageStatisticsByFileType::storageStatisticsByFileType(object_ptr<FileType> &&file_type_, int53 size_, int32 count_)
  : file_type_(std::move(file_type_))
  , size_(size_)
  , count_(count_)
{}

const std::int32_t storageStatisticsByFileType::ID;

void storageStatisticsByFileType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatisticsByFileType");
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_field("size", size_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

storyInteractionInfo::storyInteractionInfo()
  : view_count_()
  , forward_count_()
  , reaction_count_()
  , recent_viewer_user_ids_()
{}

storyInteractionInfo::storyInteractionInfo(int32 view_count_, int32 forward_count_, int32 reaction_count_, array<int53> &&recent_viewer_user_ids_)
  : view_count_(view_count_)
  , forward_count_(forward_count_)
  , reaction_count_(reaction_count_)
  , recent_viewer_user_ids_(std::move(recent_viewer_user_ids_))
{}

const std::int32_t storyInteractionInfo::ID;

void storyInteractionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteractionInfo");
    s.store_field("view_count", view_count_);
    s.store_field("forward_count", forward_count_);
    s.store_field("reaction_count", reaction_count_);
    { s.store_vector_begin("recent_viewer_user_ids", recent_viewer_user_ids_.size()); for (const auto &_value : recent_viewer_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyInteractions::storyInteractions()
  : total_count_()
  , total_forward_count_()
  , total_reaction_count_()
  , interactions_()
  , next_offset_()
{}

storyInteractions::storyInteractions(int32 total_count_, int32 total_forward_count_, int32 total_reaction_count_, array<object_ptr<storyInteraction>> &&interactions_, string const &next_offset_)
  : total_count_(total_count_)
  , total_forward_count_(total_forward_count_)
  , total_reaction_count_(total_reaction_count_)
  , interactions_(std::move(interactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t storyInteractions::ID;

void storyInteractions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteractions");
    s.store_field("total_count", total_count_);
    s.store_field("total_forward_count", total_forward_count_);
    s.store_field("total_reaction_count", total_reaction_count_);
    { s.store_vector_begin("interactions", interactions_.size()); for (const auto &_value : interactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

storyStatistics::storyStatistics()
  : story_interaction_graph_()
  , story_reaction_graph_()
{}

storyStatistics::storyStatistics(object_ptr<StatisticalGraph> &&story_interaction_graph_, object_ptr<StatisticalGraph> &&story_reaction_graph_)
  : story_interaction_graph_(std::move(story_interaction_graph_))
  , story_reaction_graph_(std::move(story_reaction_graph_))
{}

const std::int32_t storyStatistics::ID;

void storyStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyStatistics");
    s.store_object_field("story_interaction_graph", static_cast<const BaseObject *>(story_interaction_graph_.get()));
    s.store_object_field("story_reaction_graph", static_cast<const BaseObject *>(story_reaction_graph_.get()));
    s.store_class_end();
  }
}

suggestedPostInfo::suggestedPostInfo()
  : price_()
  , send_date_()
  , state_()
  , can_be_approved_()
  , can_be_declined_()
{}

suggestedPostInfo::suggestedPostInfo(object_ptr<SuggestedPostPrice> &&price_, int32 send_date_, object_ptr<SuggestedPostState> &&state_, bool can_be_approved_, bool can_be_declined_)
  : price_(std::move(price_))
  , send_date_(send_date_)
  , state_(std::move(state_))
  , can_be_approved_(can_be_approved_)
  , can_be_declined_(can_be_declined_)
{}

const std::int32_t suggestedPostInfo::ID;

void suggestedPostInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostInfo");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("send_date", send_date_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_field("can_be_approved", can_be_approved_);
    s.store_field("can_be_declined", can_be_declined_);
    s.store_class_end();
  }
}

tMeUrls::tMeUrls()
  : urls_()
{}

tMeUrls::tMeUrls(array<object_ptr<tMeUrl>> &&urls_)
  : urls_(std::move(urls_))
{}

const std::int32_t tMeUrls::ID;

void tMeUrls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrls");
    { s.store_vector_begin("urls", urls_.size()); for (const auto &_value : urls_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

targetChatCurrent::targetChatCurrent() {
}

const std::int32_t targetChatCurrent::ID;

void targetChatCurrent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "targetChatCurrent");
    s.store_class_end();
  }
}

targetChatChosen::targetChatChosen()
  : types_()
{}

targetChatChosen::targetChatChosen(object_ptr<targetChatTypes> &&types_)
  : types_(std::move(types_))
{}

const std::int32_t targetChatChosen::ID;

void targetChatChosen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "targetChatChosen");
    s.store_object_field("types", static_cast<const BaseObject *>(types_.get()));
    s.store_class_end();
  }
}

targetChatInternalLink::targetChatInternalLink()
  : link_()
{}

targetChatInternalLink::targetChatInternalLink(object_ptr<InternalLinkType> &&link_)
  : link_(std::move(link_))
{}

const std::int32_t targetChatInternalLink::ID;

void targetChatInternalLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "targetChatInternalLink");
    s.store_object_field("link", static_cast<const BaseObject *>(link_.get()));
    s.store_class_end();
  }
}

telegramPaymentPurposePremiumGift::telegramPaymentPurposePremiumGift()
  : currency_()
  , amount_()
  , user_id_()
  , month_count_()
  , text_()
{}

telegramPaymentPurposePremiumGift::telegramPaymentPurposePremiumGift(string const &currency_, int53 amount_, int53 user_id_, int32 month_count_, object_ptr<formattedText> &&text_)
  : currency_(currency_)
  , amount_(amount_)
  , user_id_(user_id_)
  , month_count_(month_count_)
  , text_(std::move(text_))
{}

const std::int32_t telegramPaymentPurposePremiumGift::ID;

void telegramPaymentPurposePremiumGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposePremiumGift");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("user_id", user_id_);
    s.store_field("month_count", month_count_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

telegramPaymentPurposePremiumGiftCodes::telegramPaymentPurposePremiumGiftCodes()
  : boosted_chat_id_()
  , currency_()
  , amount_()
  , user_ids_()
  , month_count_()
  , text_()
{}

telegramPaymentPurposePremiumGiftCodes::telegramPaymentPurposePremiumGiftCodes(int53 boosted_chat_id_, string const &currency_, int53 amount_, array<int53> &&user_ids_, int32 month_count_, object_ptr<formattedText> &&text_)
  : boosted_chat_id_(boosted_chat_id_)
  , currency_(currency_)
  , amount_(amount_)
  , user_ids_(std::move(user_ids_))
  , month_count_(month_count_)
  , text_(std::move(text_))
{}

const std::int32_t telegramPaymentPurposePremiumGiftCodes::ID;

void telegramPaymentPurposePremiumGiftCodes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposePremiumGiftCodes");
    s.store_field("boosted_chat_id", boosted_chat_id_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("month_count", month_count_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

telegramPaymentPurposePremiumGiveaway::telegramPaymentPurposePremiumGiveaway()
  : parameters_()
  , currency_()
  , amount_()
  , winner_count_()
  , month_count_()
{}

telegramPaymentPurposePremiumGiveaway::telegramPaymentPurposePremiumGiveaway(object_ptr<giveawayParameters> &&parameters_, string const &currency_, int53 amount_, int32 winner_count_, int32 month_count_)
  : parameters_(std::move(parameters_))
  , currency_(currency_)
  , amount_(amount_)
  , winner_count_(winner_count_)
  , month_count_(month_count_)
{}

const std::int32_t telegramPaymentPurposePremiumGiveaway::ID;

void telegramPaymentPurposePremiumGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposePremiumGiveaway");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("winner_count", winner_count_);
    s.store_field("month_count", month_count_);
    s.store_class_end();
  }
}

telegramPaymentPurposeStars::telegramPaymentPurposeStars()
  : currency_()
  , amount_()
  , star_count_()
  , chat_id_()
{}

telegramPaymentPurposeStars::telegramPaymentPurposeStars(string const &currency_, int53 amount_, int53 star_count_, int53 chat_id_)
  : currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
  , chat_id_(chat_id_)
{}

const std::int32_t telegramPaymentPurposeStars::ID;

void telegramPaymentPurposeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposeStars");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

telegramPaymentPurposeGiftedStars::telegramPaymentPurposeGiftedStars()
  : user_id_()
  , currency_()
  , amount_()
  , star_count_()
{}

telegramPaymentPurposeGiftedStars::telegramPaymentPurposeGiftedStars(int53 user_id_, string const &currency_, int53 amount_, int53 star_count_)
  : user_id_(user_id_)
  , currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
{}

const std::int32_t telegramPaymentPurposeGiftedStars::ID;

void telegramPaymentPurposeGiftedStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposeGiftedStars");
    s.store_field("user_id", user_id_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

telegramPaymentPurposeStarGiveaway::telegramPaymentPurposeStarGiveaway()
  : parameters_()
  , currency_()
  , amount_()
  , winner_count_()
  , star_count_()
{}

telegramPaymentPurposeStarGiveaway::telegramPaymentPurposeStarGiveaway(object_ptr<giveawayParameters> &&parameters_, string const &currency_, int53 amount_, int32 winner_count_, int53 star_count_)
  : parameters_(std::move(parameters_))
  , currency_(currency_)
  , amount_(amount_)
  , winner_count_(winner_count_)
  , star_count_(star_count_)
{}

const std::int32_t telegramPaymentPurposeStarGiveaway::ID;

void telegramPaymentPurposeStarGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposeStarGiveaway");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("winner_count", winner_count_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

telegramPaymentPurposeJoinChat::telegramPaymentPurposeJoinChat()
  : invite_link_()
{}

telegramPaymentPurposeJoinChat::telegramPaymentPurposeJoinChat(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t telegramPaymentPurposeJoinChat::ID;

void telegramPaymentPurposeJoinChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposeJoinChat");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

textCompositionStyleExample::textCompositionStyleExample()
  : source_text_()
  , result_text_()
{}

textCompositionStyleExample::textCompositionStyleExample(object_ptr<formattedText> &&source_text_, object_ptr<formattedText> &&result_text_)
  : source_text_(std::move(source_text_))
  , result_text_(std::move(result_text_))
{}

const std::int32_t textCompositionStyleExample::ID;

void textCompositionStyleExample::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textCompositionStyleExample");
    s.store_object_field("source_text", static_cast<const BaseObject *>(source_text_.get()));
    s.store_object_field("result_text", static_cast<const BaseObject *>(result_text_.get()));
    s.store_class_end();
  }
}

tonWalletOwnershipProofChallenge::tonWalletOwnershipProofChallenge()
  : payload_()
  , domain_()
{}

tonWalletOwnershipProofChallenge::tonWalletOwnershipProofChallenge(string const &payload_, string const &domain_)
  : payload_(payload_)
  , domain_(domain_)
{}

const std::int32_t tonWalletOwnershipProofChallenge::ID;

void tonWalletOwnershipProofChallenge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletOwnershipProofChallenge");
    s.store_field("payload", payload_);
    s.store_field("domain", domain_);
    s.store_class_end();
  }
}

tonWalletTransactionStateSucceeded::tonWalletTransactionStateSucceeded()
  : tx_hash_()
{}

tonWalletTransactionStateSucceeded::tonWalletTransactionStateSucceeded(string const &tx_hash_)
  : tx_hash_(tx_hash_)
{}

const std::int32_t tonWalletTransactionStateSucceeded::ID;

void tonWalletTransactionStateSucceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransactionStateSucceeded");
    s.store_field("tx_hash", tx_hash_);
    s.store_class_end();
  }
}

tonWalletTransactionStateFailed::tonWalletTransactionStateFailed() {
}

const std::int32_t tonWalletTransactionStateFailed::ID;

void tonWalletTransactionStateFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransactionStateFailed");
    s.store_class_end();
  }
}

unconfirmedSession::unconfirmedSession()
  : type_()
  , date_()
  , device_model_()
  , location_()
{}

unconfirmedSession::unconfirmedSession(object_ptr<SessionType> &&type_, int32 date_, string const &device_model_, string const &location_)
  : type_(std::move(type_))
  , date_(date_)
  , device_model_(device_model_)
  , location_(location_)
{}

const std::int32_t unconfirmedSession::ID;

void unconfirmedSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unconfirmedSession");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("date", date_);
    s.store_field("device_model", device_model_);
    s.store_field("location", location_);
    s.store_class_end();
  }
}

upgradedGiftModel::upgradedGiftModel()
  : name_()
  , sticker_()
  , rarity_()
  , is_crafted_()
{}

upgradedGiftModel::upgradedGiftModel(string const &name_, object_ptr<sticker> &&sticker_, object_ptr<UpgradedGiftAttributeRarity> &&rarity_, bool is_crafted_)
  : name_(name_)
  , sticker_(std::move(sticker_))
  , rarity_(std::move(rarity_))
  , is_crafted_(is_crafted_)
{}

const std::int32_t upgradedGiftModel::ID;

void upgradedGiftModel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftModel");
    s.store_field("name", name_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_field("is_crafted", is_crafted_);
    s.store_class_end();
  }
}

upgradedGiftModelCount::upgradedGiftModelCount()
  : model_()
  , total_count_()
{}

upgradedGiftModelCount::upgradedGiftModelCount(object_ptr<upgradedGiftModel> &&model_, int32 total_count_)
  : model_(std::move(model_))
  , total_count_(total_count_)
{}

const std::int32_t upgradedGiftModelCount::ID;

void upgradedGiftModelCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftModelCount");
    s.store_object_field("model", static_cast<const BaseObject *>(model_.get()));
    s.store_field("total_count", total_count_);
    s.store_class_end();
  }
}

upgradedGiftOriginalDetails::upgradedGiftOriginalDetails()
  : sender_id_()
  , receiver_id_()
  , text_()
  , date_()
{}

upgradedGiftOriginalDetails::upgradedGiftOriginalDetails(object_ptr<MessageSender> &&sender_id_, object_ptr<MessageSender> &&receiver_id_, object_ptr<formattedText> &&text_, int32 date_)
  : sender_id_(std::move(sender_id_))
  , receiver_id_(std::move(receiver_id_))
  , text_(std::move(text_))
  , date_(date_)
{}

const std::int32_t upgradedGiftOriginalDetails::ID;

void upgradedGiftOriginalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginalDetails");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowAll::userPrivacySettingRuleAllowAll() {
}

const std::int32_t userPrivacySettingRuleAllowAll::ID;

void userPrivacySettingRuleAllowAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowAll");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowContacts::userPrivacySettingRuleAllowContacts() {
}

const std::int32_t userPrivacySettingRuleAllowContacts::ID;

void userPrivacySettingRuleAllowContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowContacts");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowBots::userPrivacySettingRuleAllowBots() {
}

const std::int32_t userPrivacySettingRuleAllowBots::ID;

void userPrivacySettingRuleAllowBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowBots");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowPremiumUsers::userPrivacySettingRuleAllowPremiumUsers() {
}

const std::int32_t userPrivacySettingRuleAllowPremiumUsers::ID;

void userPrivacySettingRuleAllowPremiumUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowPremiumUsers");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowUsers::userPrivacySettingRuleAllowUsers()
  : user_ids_()
{}

userPrivacySettingRuleAllowUsers::userPrivacySettingRuleAllowUsers(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t userPrivacySettingRuleAllowUsers::ID;

void userPrivacySettingRuleAllowUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowUsers");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowChatMembers::userPrivacySettingRuleAllowChatMembers()
  : chat_ids_()
{}

userPrivacySettingRuleAllowChatMembers::userPrivacySettingRuleAllowChatMembers(array<int53> &&chat_ids_)
  : chat_ids_(std::move(chat_ids_))
{}

const std::int32_t userPrivacySettingRuleAllowChatMembers::ID;

void userPrivacySettingRuleAllowChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowChatMembers");
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictAll::userPrivacySettingRuleRestrictAll() {
}

const std::int32_t userPrivacySettingRuleRestrictAll::ID;

void userPrivacySettingRuleRestrictAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictAll");
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictContacts::userPrivacySettingRuleRestrictContacts() {
}

const std::int32_t userPrivacySettingRuleRestrictContacts::ID;

void userPrivacySettingRuleRestrictContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictContacts");
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictBots::userPrivacySettingRuleRestrictBots() {
}

const std::int32_t userPrivacySettingRuleRestrictBots::ID;

void userPrivacySettingRuleRestrictBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictBots");
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictUsers::userPrivacySettingRuleRestrictUsers()
  : user_ids_()
{}

userPrivacySettingRuleRestrictUsers::userPrivacySettingRuleRestrictUsers(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t userPrivacySettingRuleRestrictUsers::ID;

void userPrivacySettingRuleRestrictUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictUsers");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictChatMembers::userPrivacySettingRuleRestrictChatMembers()
  : chat_ids_()
{}

userPrivacySettingRuleRestrictChatMembers::userPrivacySettingRuleRestrictChatMembers(array<int53> &&chat_ids_)
  : chat_ids_(std::move(chat_ids_))
{}

const std::int32_t userPrivacySettingRuleRestrictChatMembers::ID;

void userPrivacySettingRuleRestrictChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictChatMembers");
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userRating::userRating()
  : level_()
  , is_maximum_level_reached_()
  , rating_()
  , current_level_rating_()
  , next_level_rating_()
{}

userRating::userRating(int32 level_, bool is_maximum_level_reached_, int53 rating_, int53 current_level_rating_, int53 next_level_rating_)
  : level_(level_)
  , is_maximum_level_reached_(is_maximum_level_reached_)
  , rating_(rating_)
  , current_level_rating_(current_level_rating_)
  , next_level_rating_(next_level_rating_)
{}

const std::int32_t userRating::ID;

void userRating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userRating");
    s.store_field("level", level_);
    s.store_field("is_maximum_level_reached", is_maximum_level_reached_);
    s.store_field("rating", rating_);
    s.store_field("current_level_rating", current_level_rating_);
    s.store_field("next_level_rating", next_level_rating_);
    s.store_class_end();
  }
}

usernames::usernames()
  : active_usernames_()
  , disabled_usernames_()
  , editable_username_()
  , collectible_usernames_()
  , secondary_username_()
{}

usernames::usernames(array<string> &&active_usernames_, array<string> &&disabled_usernames_, string const &editable_username_, array<string> &&collectible_usernames_, string const &secondary_username_)
  : active_usernames_(std::move(active_usernames_))
  , disabled_usernames_(std::move(disabled_usernames_))
  , editable_username_(editable_username_)
  , collectible_usernames_(std::move(collectible_usernames_))
  , secondary_username_(secondary_username_)
{}

const std::int32_t usernames::ID;

void usernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "usernames");
    { s.store_vector_begin("active_usernames", active_usernames_.size()); for (const auto &_value : active_usernames_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("disabled_usernames", disabled_usernames_.size()); for (const auto &_value : disabled_usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("editable_username", editable_username_);
    { s.store_vector_begin("collectible_usernames", collectible_usernames_.size()); for (const auto &_value : collectible_usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("secondary_username", secondary_username_);
    s.store_class_end();
  }
}

vectorPathCommandLine::vectorPathCommandLine()
  : end_point_()
{}

vectorPathCommandLine::vectorPathCommandLine(object_ptr<point> &&end_point_)
  : end_point_(std::move(end_point_))
{}

const std::int32_t vectorPathCommandLine::ID;

void vectorPathCommandLine::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "vectorPathCommandLine");
    s.store_object_field("end_point", static_cast<const BaseObject *>(end_point_.get()));
    s.store_class_end();
  }
}

vectorPathCommandCubicBezierCurve::vectorPathCommandCubicBezierCurve()
  : start_control_point_()
  , end_control_point_()
  , end_point_()
{}

vectorPathCommandCubicBezierCurve::vectorPathCommandCubicBezierCurve(object_ptr<point> &&start_control_point_, object_ptr<point> &&end_control_point_, object_ptr<point> &&end_point_)
  : start_control_point_(std::move(start_control_point_))
  , end_control_point_(std::move(end_control_point_))
  , end_point_(std::move(end_point_))
{}

const std::int32_t vectorPathCommandCubicBezierCurve::ID;

void vectorPathCommandCubicBezierCurve::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "vectorPathCommandCubicBezierCurve");
    s.store_object_field("start_control_point", static_cast<const BaseObject *>(start_control_point_.get()));
    s.store_object_field("end_control_point", static_cast<const BaseObject *>(end_control_point_.get()));
    s.store_object_field("end_point", static_cast<const BaseObject *>(end_point_.get()));
    s.store_class_end();
  }
}

webPageInstantView::webPageInstantView()
  : blocks_()
  , view_count_()
  , version_()
  , is_rtl_()
  , is_full_()
  , feedback_link_()
{}

webPageInstantView::webPageInstantView(array<object_ptr<PageBlock>> &&blocks_, int32 view_count_, int32 version_, bool is_rtl_, bool is_full_, object_ptr<InternalLinkType> &&feedback_link_)
  : blocks_(std::move(blocks_))
  , view_count_(view_count_)
  , version_(version_)
  , is_rtl_(is_rtl_)
  , is_full_(is_full_)
  , feedback_link_(std::move(feedback_link_))
{}

const std::int32_t webPageInstantView::ID;

void webPageInstantView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageInstantView");
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("view_count", view_count_);
    s.store_field("version", version_);
    s.store_field("is_rtl", is_rtl_);
    s.store_field("is_full", is_full_);
    s.store_object_field("feedback_link", static_cast<const BaseObject *>(feedback_link_.get()));
    s.store_class_end();
  }
}

activateStoryStealthMode::activateStoryStealthMode() {
}

const std::int32_t activateStoryStealthMode::ID;

void activateStoryStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "activateStoryStealthMode");
    s.store_class_end();
  }
}

addQuickReplyShortcutMessageAlbum::addQuickReplyShortcutMessageAlbum()
  : shortcut_name_()
  , reply_to_message_id_()
  , input_message_contents_()
{}

addQuickReplyShortcutMessageAlbum::addQuickReplyShortcutMessageAlbum(string const &shortcut_name_, int53 reply_to_message_id_, array<object_ptr<InputMessageContent>> &&input_message_contents_)
  : shortcut_name_(shortcut_name_)
  , reply_to_message_id_(reply_to_message_id_)
  , input_message_contents_(std::move(input_message_contents_))
{}

const std::int32_t addQuickReplyShortcutMessageAlbum::ID;

void addQuickReplyShortcutMessageAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addQuickReplyShortcutMessageAlbum");
    s.store_field("shortcut_name", shortcut_name_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    { s.store_vector_begin("input_message_contents", input_message_contents_.size()); for (const auto &_value : input_message_contents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

addStoryAlbumStories::addStoryAlbumStories()
  : chat_id_()
  , story_album_id_()
  , story_ids_()
{}

addStoryAlbumStories::addStoryAlbumStories(int53 chat_id_, int32 story_album_id_, array<int32> &&story_ids_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
  , story_ids_(std::move(story_ids_))
{}

const std::int32_t addStoryAlbumStories::ID;

void addStoryAlbumStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addStoryAlbumStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    { s.store_vector_begin("story_ids", story_ids_.size()); for (const auto &_value : story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

answerWebAppQuery::answerWebAppQuery()
  : web_app_query_id_()
  , result_()
{}

answerWebAppQuery::answerWebAppQuery(string const &web_app_query_id_, object_ptr<InputInlineQueryResult> &&result_)
  : web_app_query_id_(web_app_query_id_)
  , result_(std::move(result_))
{}

const std::int32_t answerWebAppQuery::ID;

void answerWebAppQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerWebAppQuery");
    s.store_field("web_app_query_id", web_app_query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_class_end();
  }
}

approveSuggestedPost::approveSuggestedPost()
  : chat_id_()
  , message_id_()
  , send_date_()
{}

approveSuggestedPost::approveSuggestedPost(int53 chat_id_, int53 message_id_, int32 send_date_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , send_date_(send_date_)
{}

const std::int32_t approveSuggestedPost::ID;

void approveSuggestedPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "approveSuggestedPost");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("send_date", send_date_);
    s.store_class_end();
  }
}

checkAuthenticationBotToken::checkAuthenticationBotToken()
  : token_()
{}

checkAuthenticationBotToken::checkAuthenticationBotToken(string const &token_)
  : token_(token_)
{}

const std::int32_t checkAuthenticationBotToken::ID;

void checkAuthenticationBotToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationBotToken");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

checkAuthenticationPassword::checkAuthenticationPassword()
  : password_()
{}

checkAuthenticationPassword::checkAuthenticationPassword(string const &password_)
  : password_(password_)
{}

const std::int32_t checkAuthenticationPassword::ID;

void checkAuthenticationPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationPassword");
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

checkAuthenticationWebToken::checkAuthenticationWebToken()
  : token_()
  , dc_id_()
{}

checkAuthenticationWebToken::checkAuthenticationWebToken(string const &token_, int32 dc_id_)
  : token_(token_)
  , dc_id_(dc_id_)
{}

const std::int32_t checkAuthenticationWebToken::ID;

void checkAuthenticationWebToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationWebToken");
    s.store_field("token", "[REDACTED]");
    s.store_field("dc_id", dc_id_);
    s.store_class_end();
  }
}

checkRecoveryEmailAddressCode::checkRecoveryEmailAddressCode()
  : code_()
{}

checkRecoveryEmailAddressCode::checkRecoveryEmailAddressCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkRecoveryEmailAddressCode::ID;

void checkRecoveryEmailAddressCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkRecoveryEmailAddressCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

checkWebAppFileDownload::checkWebAppFileDownload()
  : bot_user_id_()
  , file_name_()
  , url_()
{}

checkWebAppFileDownload::checkWebAppFileDownload(int53 bot_user_id_, string const &file_name_, string const &url_)
  : bot_user_id_(bot_user_id_)
  , file_name_(file_name_)
  , url_(url_)
{}

const std::int32_t checkWebAppFileDownload::ID;

void checkWebAppFileDownload::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkWebAppFileDownload");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("file_name", file_name_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

clickAnimatedEmojiMessage::clickAnimatedEmojiMessage()
  : chat_id_()
  , message_id_()
{}

clickAnimatedEmojiMessage::clickAnimatedEmojiMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t clickAnimatedEmojiMessage::ID;

void clickAnimatedEmojiMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clickAnimatedEmojiMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

deleteAllRecentMessageReactionsFromSender::deleteAllRecentMessageReactionsFromSender()
  : chat_id_()
  , sender_id_()
{}

deleteAllRecentMessageReactionsFromSender::deleteAllRecentMessageReactionsFromSender(int53 chat_id_, object_ptr<MessageSender> &&sender_id_)
  : chat_id_(chat_id_)
  , sender_id_(std::move(sender_id_))
{}

const std::int32_t deleteAllRecentMessageReactionsFromSender::ID;

void deleteAllRecentMessageReactionsFromSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteAllRecentMessageReactionsFromSender");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_class_end();
  }
}

deleteBusinessConnectedBot::deleteBusinessConnectedBot()
  : bot_user_id_()
{}

deleteBusinessConnectedBot::deleteBusinessConnectedBot(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t deleteBusinessConnectedBot::ID;

void deleteBusinessConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteBusinessConnectedBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

deleteBusinessStory::deleteBusinessStory()
  : business_connection_id_()
  , story_id_()
{}

deleteBusinessStory::deleteBusinessStory(string const &business_connection_id_, int32 story_id_)
  : business_connection_id_(business_connection_id_)
  , story_id_(story_id_)
{}

const std::int32_t deleteBusinessStory::ID;

void deleteBusinessStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteBusinessStory");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

deleteChatFolder::deleteChatFolder()
  : chat_folder_id_()
  , leave_chat_ids_()
{}

deleteChatFolder::deleteChatFolder(int32 chat_folder_id_, array<int53> &&leave_chat_ids_)
  : chat_folder_id_(chat_folder_id_)
  , leave_chat_ids_(std::move(leave_chat_ids_))
{}

const std::int32_t deleteChatFolder::ID;

void deleteChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatFolder");
    s.store_field("chat_folder_id", chat_folder_id_);
    { s.store_vector_begin("leave_chat_ids", leave_chat_ids_.size()); for (const auto &_value : leave_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

deleteDefaultBackground::deleteDefaultBackground()
  : for_dark_theme_()
{}

deleteDefaultBackground::deleteDefaultBackground(bool for_dark_theme_)
  : for_dark_theme_(for_dark_theme_)
{}

const std::int32_t deleteDefaultBackground::ID;

void deleteDefaultBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteDefaultBackground");
    s.store_field("for_dark_theme", for_dark_theme_);
    s.store_class_end();
  }
}

deleteMessages::deleteMessages()
  : chat_id_()
  , message_ids_()
  , revoke_()
{}

deleteMessages::deleteMessages(int53 chat_id_, array<int53> &&message_ids_, bool revoke_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
  , revoke_(revoke_)
{}

const std::int32_t deleteMessages::ID;

void deleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

deleteRevokedChatInviteLink::deleteRevokedChatInviteLink()
  : chat_id_()
  , invite_link_()
{}

deleteRevokedChatInviteLink::deleteRevokedChatInviteLink(int53 chat_id_, string const &invite_link_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
{}

const std::int32_t deleteRevokedChatInviteLink::ID;

void deleteRevokedChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteRevokedChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

deleteStickerSet::deleteStickerSet()
  : name_()
{}

deleteStickerSet::deleteStickerSet(string const &name_)
  : name_(name_)
{}

const std::int32_t deleteStickerSet::ID;

void deleteStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteStickerSet");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

destroy::destroy() {
}

const std::int32_t destroy::ID;

void destroy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "destroy");
    s.store_class_end();
  }
}

editBotMediaPreview::editBotMediaPreview()
  : bot_user_id_()
  , language_code_()
  , file_id_()
  , content_()
{}

editBotMediaPreview::editBotMediaPreview(int53 bot_user_id_, string const &language_code_, int32 file_id_, object_ptr<InputStoryContent> &&content_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , file_id_(file_id_)
  , content_(std::move(content_))
{}

const std::int32_t editBotMediaPreview::ID;

void editBotMediaPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBotMediaPreview");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_field("file_id", file_id_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

editBusinessMessageCaption::editBusinessMessageCaption()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
  , caption_()
  , show_caption_above_media_()
{}

editBusinessMessageCaption::editBusinessMessageCaption(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
{}

const std::int32_t editBusinessMessageCaption::ID;

void editBusinessMessageCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageCaption");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_class_end();
  }
}

editBusinessMessageMedia::editBusinessMessageMedia()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editBusinessMessageMedia::editBusinessMessageMedia(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editBusinessMessageMedia::ID;

void editBusinessMessageMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageMedia");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editStarSubscription::editStarSubscription()
  : subscription_id_()
  , is_canceled_()
{}

editStarSubscription::editStarSubscription(string const &subscription_id_, bool is_canceled_)
  : subscription_id_(subscription_id_)
  , is_canceled_(is_canceled_)
{}

const std::int32_t editStarSubscription::ID;

void editStarSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editStarSubscription");
    s.store_field("subscription_id", subscription_id_);
    s.store_field("is_canceled", is_canceled_);
    s.store_class_end();
  }
}

editStory::editStory()
  : story_poster_chat_id_()
  , story_id_()
  , content_()
  , areas_()
  , caption_()
{}

editStory::editStory(int53 story_poster_chat_id_, int32 story_id_, object_ptr<InputStoryContent> &&content_, object_ptr<inputStoryAreas> &&areas_, object_ptr<formattedText> &&caption_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , content_(std::move(content_))
  , areas_(std::move(areas_))
  , caption_(std::move(caption_))
{}

const std::int32_t editStory::ID;

void editStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("areas", static_cast<const BaseObject *>(areas_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

editUserStarSubscription::editUserStarSubscription()
  : user_id_()
  , telegram_payment_charge_id_()
  , is_canceled_()
{}

editUserStarSubscription::editUserStarSubscription(int53 user_id_, string const &telegram_payment_charge_id_, bool is_canceled_)
  : user_id_(user_id_)
  , telegram_payment_charge_id_(telegram_payment_charge_id_)
  , is_canceled_(is_canceled_)
{}

const std::int32_t editUserStarSubscription::ID;

void editUserStarSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editUserStarSubscription");
    s.store_field("user_id", user_id_);
    s.store_field("telegram_payment_charge_id", telegram_payment_charge_id_);
    s.store_field("is_canceled", is_canceled_);
    s.store_class_end();
  }
}

endGroupCall::endGroupCall()
  : group_call_id_()
{}

endGroupCall::endGroupCall(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t endGroupCall::ID;

void endGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "endGroupCall");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getActiveSessions::getActiveSessions() {
}

const std::int32_t getActiveSessions::ID;

void getActiveSessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getActiveSessions");
    s.store_class_end();
  }
}

getBotMediaPreviews::getBotMediaPreviews()
  : bot_user_id_()
{}

getBotMediaPreviews::getBotMediaPreviews(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t getBotMediaPreviews::ID;

void getBotMediaPreviews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotMediaPreviews");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

getBusinessChatLinks::getBusinessChatLinks() {
}

const std::int32_t getBusinessChatLinks::ID;

void getBusinessChatLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessChatLinks");
    s.store_class_end();
  }
}

getBusinessConnection::getBusinessConnection()
  : connection_id_()
{}

getBusinessConnection::getBusinessConnection(string const &connection_id_)
  : connection_id_(connection_id_)
{}

const std::int32_t getBusinessConnection::ID;

void getBusinessConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessConnection");
    s.store_field("connection_id", connection_id_);
    s.store_class_end();
  }
}

getChatEventLog::getChatEventLog()
  : chat_id_()
  , query_()
  , from_event_id_()
  , limit_()
  , filters_()
  , user_ids_()
{}

getChatEventLog::getChatEventLog(int53 chat_id_, string const &query_, int64 from_event_id_, int32 limit_, object_ptr<chatEventLogFilters> &&filters_, array<int53> &&user_ids_)
  : chat_id_(chat_id_)
  , query_(query_)
  , from_event_id_(from_event_id_)
  , limit_(limit_)
  , filters_(std::move(filters_))
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t getChatEventLog::ID;

void getChatEventLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatEventLog");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_field("from_event_id", from_event_id_);
    s.store_field("limit", limit_);
    s.store_object_field("filters", static_cast<const BaseObject *>(filters_.get()));
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getChatPinnedMessage::getChatPinnedMessage()
  : chat_id_()
{}

getChatPinnedMessage::getChatPinnedMessage(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatPinnedMessage::ID;

void getChatPinnedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatPinnedMessage");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatPostedToChatPageStories::getChatPostedToChatPageStories()
  : chat_id_()
  , from_story_id_()
  , limit_()
{}

getChatPostedToChatPageStories::getChatPostedToChatPageStories(int53 chat_id_, int32 from_story_id_, int32 limit_)
  : chat_id_(chat_id_)
  , from_story_id_(from_story_id_)
  , limit_(limit_)
{}

const std::int32_t getChatPostedToChatPageStories::ID;

void getChatPostedToChatPageStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatPostedToChatPageStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("from_story_id", from_story_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatSimilarChatCount::getChatSimilarChatCount()
  : chat_id_()
  , return_local_()
{}

getChatSimilarChatCount::getChatSimilarChatCount(int53 chat_id_, bool return_local_)
  : chat_id_(chat_id_)
  , return_local_(return_local_)
{}

const std::int32_t getChatSimilarChatCount::ID;

void getChatSimilarChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatSimilarChatCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("return_local", return_local_);
    s.store_class_end();
  }
}

getCustomEmojiStickers::getCustomEmojiStickers()
  : custom_emoji_ids_()
{}

getCustomEmojiStickers::getCustomEmojiStickers(array<int64> &&custom_emoji_ids_)
  : custom_emoji_ids_(std::move(custom_emoji_ids_))
{}

const std::int32_t getCustomEmojiStickers::ID;

void getCustomEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCustomEmojiStickers");
    { s.store_vector_begin("custom_emoji_ids", custom_emoji_ids_.size()); for (const auto &_value : custom_emoji_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getGroupCallStreams::getGroupCallStreams()
  : group_call_id_()
{}

getGroupCallStreams::getGroupCallStreams(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getGroupCallStreams::ID;

void getGroupCallStreams::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCallStreams");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getInstalledBackgrounds::getInstalledBackgrounds()
  : for_dark_theme_()
{}

getInstalledBackgrounds::getInstalledBackgrounds(bool for_dark_theme_)
  : for_dark_theme_(for_dark_theme_)
{}

const std::int32_t getInstalledBackgrounds::ID;

void getInstalledBackgrounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInstalledBackgrounds");
    s.store_field("for_dark_theme", for_dark_theme_);
    s.store_class_end();
  }
}

getJsonValue::getJsonValue()
  : json_()
{}

getJsonValue::getJsonValue(string const &json_)
  : json_(json_)
{}

const std::int32_t getJsonValue::ID;

void getJsonValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getJsonValue");
    s.store_field("json", json_);
    s.store_class_end();
  }
}

getLinkPreview::getLinkPreview()
  : text_()
  , link_preview_options_()
{}

getLinkPreview::getLinkPreview(object_ptr<formattedText> &&text_, object_ptr<linkPreviewOptions> &&link_preview_options_)
  : text_(std::move(text_))
  , link_preview_options_(std::move(link_preview_options_))
{}

const std::int32_t getLinkPreview::ID;

void getLinkPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLinkPreview");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("link_preview_options", static_cast<const BaseObject *>(link_preview_options_.get()));
    s.store_class_end();
  }
}

getMessageEffect::getMessageEffect()
  : effect_id_()
{}

getMessageEffect::getMessageEffect(int64 effect_id_)
  : effect_id_(effect_id_)
{}

const std::int32_t getMessageEffect::ID;

void getMessageEffect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageEffect");
    s.store_field("effect_id", effect_id_);
    s.store_class_end();
  }
}

getMessageThread::getMessageThread()
  : chat_id_()
  , message_id_()
{}

getMessageThread::getMessageThread(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageThread::ID;

void getMessageThread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageThread");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getOnRampPaymentLimits::getOnRampPaymentLimits()
  : provider_id_()
  , cryptocurrency_()
  , base_currency_()
  , payment_method_name_()
{}

getOnRampPaymentLimits::getOnRampPaymentLimits(string const &provider_id_, string const &cryptocurrency_, string const &base_currency_, string const &payment_method_name_)
  : provider_id_(provider_id_)
  , cryptocurrency_(cryptocurrency_)
  , base_currency_(base_currency_)
  , payment_method_name_(payment_method_name_)
{}

const std::int32_t getOnRampPaymentLimits::ID;

void getOnRampPaymentLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOnRampPaymentLimits");
    s.store_field("provider_id", provider_id_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("base_currency", base_currency_);
    s.store_field("payment_method_name", payment_method_name_);
    s.store_class_end();
  }
}

getPasswordState::getPasswordState() {
}

const std::int32_t getPasswordState::ID;

void getPasswordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPasswordState");
    s.store_class_end();
  }
}

getPhoneNumberInfo::getPhoneNumberInfo()
  : phone_number_prefix_()
{}

getPhoneNumberInfo::getPhoneNumberInfo(string const &phone_number_prefix_)
  : phone_number_prefix_(phone_number_prefix_)
{}

const std::int32_t getPhoneNumberInfo::ID;

void getPhoneNumberInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPhoneNumberInfo");
    s.store_field("phone_number_prefix", phone_number_prefix_);
    s.store_class_end();
  }
}

getPremiumStickerExamples::getPremiumStickerExamples() {
}

const std::int32_t getPremiumStickerExamples::ID;

void getPremiumStickerExamples::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumStickerExamples");
    s.store_class_end();
  }
}

getSavedNotificationSound::getSavedNotificationSound()
  : notification_sound_id_()
{}

getSavedNotificationSound::getSavedNotificationSound(int64 notification_sound_id_)
  : notification_sound_id_(notification_sound_id_)
{}

const std::int32_t getSavedNotificationSound::ID;

void getSavedNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedNotificationSound");
    s.store_field("notification_sound_id", notification_sound_id_);
    s.store_class_end();
  }
}

getStickerEmojis::getStickerEmojis()
  : sticker_()
{}

getStickerEmojis::getStickerEmojis(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t getStickerEmojis::ID;

void getStickerEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerEmojis");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

getStory::getStory()
  : story_poster_chat_id_()
  , story_id_()
  , only_local_()
{}

getStory::getStory(int53 story_poster_chat_id_, int32 story_id_, bool only_local_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , only_local_(only_local_)
{}

const std::int32_t getStory::ID;

void getStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

getStoryInteractions::getStoryInteractions()
  : story_id_()
  , query_()
  , only_contacts_()
  , prefer_forwards_()
  , prefer_with_reaction_()
  , offset_()
  , limit_()
{}

getStoryInteractions::getStoryInteractions(int32 story_id_, string const &query_, bool only_contacts_, bool prefer_forwards_, bool prefer_with_reaction_, string const &offset_, int32 limit_)
  : story_id_(story_id_)
  , query_(query_)
  , only_contacts_(only_contacts_)
  , prefer_forwards_(prefer_forwards_)
  , prefer_with_reaction_(prefer_with_reaction_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getStoryInteractions::ID;

void getStoryInteractions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryInteractions");
    s.store_field("story_id", story_id_);
    s.store_field("query", query_);
    s.store_field("only_contacts", only_contacts_);
    s.store_field("prefer_forwards", prefer_forwards_);
    s.store_field("prefer_with_reaction", prefer_with_reaction_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getStoryStatistics::getStoryStatistics()
  : chat_id_()
  , story_id_()
  , is_dark_()
{}

getStoryStatistics::getStoryStatistics(int53 chat_id_, int32 story_id_, bool is_dark_)
  : chat_id_(chat_id_)
  , story_id_(story_id_)
  , is_dark_(is_dark_)
{}

const std::int32_t getStoryStatistics::ID;

void getStoryStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryStatistics");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getTonConnectSessionPendingRequests::getTonConnectSessionPendingRequests()
  : session_id_()
{}

getTonConnectSessionPendingRequests::getTonConnectSessionPendingRequests(int64 session_id_)
  : session_id_(session_id_)
{}

const std::int32_t getTonConnectSessionPendingRequests::ID;

void getTonConnectSessionPendingRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonConnectSessionPendingRequests");
    s.store_field("session_id", session_id_);
    s.store_class_end();
  }
}

getTonWalletCardBackgroundGiftCollectionNames::getTonWalletCardBackgroundGiftCollectionNames() {
}

const std::int32_t getTonWalletCardBackgroundGiftCollectionNames::ID;

void getTonWalletCardBackgroundGiftCollectionNames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonWalletCardBackgroundGiftCollectionNames");
    s.store_class_end();
  }
}

getTopChats::getTopChats()
  : category_()
  , limit_()
{}

getTopChats::getTopChats(object_ptr<TopChatCategory> &&category_, int32 limit_)
  : category_(std::move(category_))
  , limit_(limit_)
{}

const std::int32_t getTopChats::ID;

void getTopChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTopChats");
    s.store_object_field("category", static_cast<const BaseObject *>(category_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getUpgradedGiftEmojiStatuses::getUpgradedGiftEmojiStatuses() {
}

const std::int32_t getUpgradedGiftEmojiStatuses::ID;

void getUpgradedGiftEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGiftEmojiStatuses");
    s.store_class_end();
  }
}

getUpgradedGiftValueInfo::getUpgradedGiftValueInfo()
  : name_()
{}

getUpgradedGiftValueInfo::getUpgradedGiftValueInfo(string const &name_)
  : name_(name_)
{}

const std::int32_t getUpgradedGiftValueInfo::ID;

void getUpgradedGiftValueInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGiftValueInfo");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

getUser::getUser()
  : user_id_()
{}

getUser::getUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getUser::ID;

void getUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getWebAppPlaceholder::getWebAppPlaceholder()
  : bot_user_id_()
{}

getWebAppPlaceholder::getWebAppPlaceholder(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t getWebAppPlaceholder::ID;

void getWebAppPlaceholder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWebAppPlaceholder");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

hideContactCloseBirthdays::hideContactCloseBirthdays() {
}

const std::int32_t hideContactCloseBirthdays::ID;

void hideContactCloseBirthdays::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "hideContactCloseBirthdays");
    s.store_class_end();
  }
}

joinLiveStory::joinLiveStory()
  : group_call_id_()
  , join_parameters_()
{}

joinLiveStory::joinLiveStory(int32 group_call_id_, object_ptr<groupCallJoinParameters> &&join_parameters_)
  : group_call_id_(group_call_id_)
  , join_parameters_(std::move(join_parameters_))
{}

const std::int32_t joinLiveStory::ID;

void joinLiveStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinLiveStory");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("join_parameters", static_cast<const BaseObject *>(join_parameters_.get()));
    s.store_class_end();
  }
}

launchPrepaidGiveaway::launchPrepaidGiveaway()
  : giveaway_id_()
  , parameters_()
  , winner_count_()
  , star_count_()
{}

launchPrepaidGiveaway::launchPrepaidGiveaway(int64 giveaway_id_, object_ptr<giveawayParameters> &&parameters_, int32 winner_count_, int53 star_count_)
  : giveaway_id_(giveaway_id_)
  , parameters_(std::move(parameters_))
  , winner_count_(winner_count_)
  , star_count_(star_count_)
{}

const std::int32_t launchPrepaidGiveaway::ID;

void launchPrepaidGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "launchPrepaidGiveaway");
    s.store_field("giveaway_id", giveaway_id_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("winner_count", winner_count_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

loadTonWalletGaslessTransfersInfo::loadTonWalletGaslessTransfersInfo() {
}

const std::int32_t loadTonWalletGaslessTransfersInfo::ID;

void loadTonWalletGaslessTransfersInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadTonWalletGaslessTransfersInfo");
    s.store_class_end();
  }
}

loadTonWalletState::loadTonWalletState() {
}

const std::int32_t loadTonWalletState::ID;

void loadTonWalletState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadTonWalletState");
    s.store_class_end();
  }
}

readAllForumTopicPollVotes::readAllForumTopicPollVotes()
  : chat_id_()
  , forum_topic_id_()
{}

readAllForumTopicPollVotes::readAllForumTopicPollVotes(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t readAllForumTopicPollVotes::ID;

void readAllForumTopicPollVotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllForumTopicPollVotes");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

recoverPassword::recoverPassword()
  : recovery_code_()
  , new_password_()
  , new_hint_()
{}

recoverPassword::recoverPassword(string const &recovery_code_, string const &new_password_, string const &new_hint_)
  : recovery_code_(recovery_code_)
  , new_password_(new_password_)
  , new_hint_(new_hint_)
{}

const std::int32_t recoverPassword::ID;

void recoverPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recoverPassword");
    s.store_field("recovery_code", "[REDACTED]");
    s.store_field("new_password", "[REDACTED]");
    s.store_field("new_hint", new_hint_);
    s.store_class_end();
  }
}

removeMessageReaction::removeMessageReaction()
  : chat_id_()
  , message_id_()
  , reaction_type_()
{}

removeMessageReaction::removeMessageReaction(int53 chat_id_, int53 message_id_, object_ptr<ReactionType> &&reaction_type_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reaction_type_(std::move(reaction_type_))
{}

const std::int32_t removeMessageReaction::ID;

void removeMessageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeMessageReaction");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_class_end();
  }
}

replaceTonWallet::replaceTonWallet()
  : password_()
  , anchor_public_key_()
  , proof_()
{}

replaceTonWallet::replaceTonWallet(string const &password_, bytes const &anchor_public_key_, object_ptr<tonWalletOwnershipProof> &&proof_)
  : password_(password_)
  , anchor_public_key_(std::move(anchor_public_key_))
  , proof_(std::move(proof_))
{}

const std::int32_t replaceTonWallet::ID;

void replaceTonWallet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replaceTonWallet");
    s.store_field("password", "[REDACTED]");
    s.store_bytes_field("anchor_public_key", anchor_public_key_);
    s.store_object_field("proof", static_cast<const BaseObject *>(proof_.get()));
    s.store_class_end();
  }
}

reportSupergroupAntiSpamFalsePositive::reportSupergroupAntiSpamFalsePositive()
  : supergroup_id_()
  , message_id_()
{}

reportSupergroupAntiSpamFalsePositive::reportSupergroupAntiSpamFalsePositive(int53 supergroup_id_, int53 message_id_)
  : supergroup_id_(supergroup_id_)
  , message_id_(message_id_)
{}

const std::int32_t reportSupergroupAntiSpamFalsePositive::ID;

void reportSupergroupAntiSpamFalsePositive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSupergroupAntiSpamFalsePositive");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

resetPassword::resetPassword() {
}

const std::int32_t resetPassword::ID;

void resetPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPassword");
    s.store_class_end();
  }
}

searchAffiliatePrograms::searchAffiliatePrograms()
  : affiliate_()
  , sort_order_()
  , offset_()
  , limit_()
{}

searchAffiliatePrograms::searchAffiliatePrograms(object_ptr<AffiliateType> &&affiliate_, object_ptr<AffiliateProgramSortOrder> &&sort_order_, string const &offset_, int32 limit_)
  : affiliate_(std::move(affiliate_))
  , sort_order_(std::move(sort_order_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchAffiliatePrograms::ID;

void searchAffiliatePrograms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchAffiliatePrograms");
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_object_field("sort_order", static_cast<const BaseObject *>(sort_order_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchChatMembers::searchChatMembers()
  : chat_id_()
  , query_()
  , limit_()
  , filter_()
{}

searchChatMembers::searchChatMembers(int53 chat_id_, string const &query_, int32 limit_, object_ptr<ChatMembersFilter> &&filter_)
  : chat_id_(chat_id_)
  , query_(query_)
  , limit_(limit_)
  , filter_(std::move(filter_))
{}

const std::int32_t searchChatMembers::ID;

void searchChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatMembers");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_class_end();
  }
}

searchOutgoingDocumentMessages::searchOutgoingDocumentMessages()
  : query_()
  , limit_()
{}

searchOutgoingDocumentMessages::searchOutgoingDocumentMessages(string const &query_, int32 limit_)
  : query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchOutgoingDocumentMessages::ID;

void searchOutgoingDocumentMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchOutgoingDocumentMessages");
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchPublicPosts::searchPublicPosts()
  : query_()
  , offset_()
  , limit_()
  , star_count_()
{}

searchPublicPosts::searchPublicPosts(string const &query_, string const &offset_, int32 limit_, int53 star_count_)
  : query_(query_)
  , offset_(offset_)
  , limit_(limit_)
  , star_count_(star_count_)
{}

const std::int32_t searchPublicPosts::ID;

void searchPublicPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicPosts");
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

searchPublicStoriesByLocation::searchPublicStoriesByLocation()
  : address_()
  , offset_()
  , limit_()
{}

searchPublicStoriesByLocation::searchPublicStoriesByLocation(object_ptr<locationAddress> &&address_, string const &offset_, int32 limit_)
  : address_(std::move(address_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchPublicStoriesByLocation::ID;

void searchPublicStoriesByLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicStoriesByLocation");
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

sendBotStartMessage::sendBotStartMessage()
  : bot_user_id_()
  , chat_id_()
  , parameter_()
{}

sendBotStartMessage::sendBotStartMessage(int53 bot_user_id_, int53 chat_id_, string const &parameter_)
  : bot_user_id_(bot_user_id_)
  , chat_id_(chat_id_)
  , parameter_(parameter_)
{}

const std::int32_t sendBotStartMessage::ID;

void sendBotStartMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendBotStartMessage");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("parameter", parameter_);
    s.store_class_end();
  }
}

sendEphemeralMessage::sendEphemeralMessage()
  : chat_id_()
  , topic_id_()
  , receiver_user_id_()
  , callback_query_id_()
  , replace_callback_query_message_()
  , reply_to_()
  , protect_content_()
  , sending_id_()
  , only_preview_()
  , reply_markup_()
  , input_message_content_()
{}

sendEphemeralMessage::sendEphemeralMessage(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, int53 receiver_user_id_, int64 callback_query_id_, bool replace_callback_query_message_, object_ptr<InputMessageReplyTo> &&reply_to_, bool protect_content_, int32 sending_id_, bool only_preview_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , receiver_user_id_(receiver_user_id_)
  , callback_query_id_(callback_query_id_)
  , replace_callback_query_message_(replace_callback_query_message_)
  , reply_to_(std::move(reply_to_))
  , protect_content_(protect_content_)
  , sending_id_(sending_id_)
  , only_preview_(only_preview_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t sendEphemeralMessage::ID;

void sendEphemeralMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendEphemeralMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_field("receiver_user_id", receiver_user_id_);
    s.store_field("callback_query_id", callback_query_id_);
    s.store_field("replace_callback_query_message", replace_callback_query_message_);
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_field("protect_content", protect_content_);
    s.store_field("sending_id", sending_id_);
    s.store_field("only_preview", only_preview_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

sendGiftPurchaseOffer::sendGiftPurchaseOffer()
  : owner_id_()
  , gift_name_()
  , price_()
  , duration_()
  , paid_message_star_count_()
{}

sendGiftPurchaseOffer::sendGiftPurchaseOffer(object_ptr<MessageSender> &&owner_id_, string const &gift_name_, object_ptr<GiftResalePrice> &&price_, int32 duration_, int53 paid_message_star_count_)
  : owner_id_(std::move(owner_id_))
  , gift_name_(gift_name_)
  , price_(std::move(price_))
  , duration_(duration_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t sendGiftPurchaseOffer::ID;

void sendGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendGiftPurchaseOffer");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("gift_name", gift_name_);
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("duration", duration_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

sendQuickReplyShortcutMessages::sendQuickReplyShortcutMessages()
  : chat_id_()
  , shortcut_id_()
  , sending_id_()
{}

sendQuickReplyShortcutMessages::sendQuickReplyShortcutMessages(int53 chat_id_, int32 shortcut_id_, int32 sending_id_)
  : chat_id_(chat_id_)
  , shortcut_id_(shortcut_id_)
  , sending_id_(sending_id_)
{}

const std::int32_t sendQuickReplyShortcutMessages::ID;

void sendQuickReplyShortcutMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendQuickReplyShortcutMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("shortcut_id", shortcut_id_);
    s.store_field("sending_id", sending_id_);
    s.store_class_end();
  }
}

sendTextMessageDraft::sendTextMessageDraft()
  : chat_id_()
  , forum_topic_id_()
  , draft_id_()
  , can_stop_()
  , keep_on_stop_()
  , text_()
{}

sendTextMessageDraft::sendTextMessageDraft(int53 chat_id_, int32 forum_topic_id_, int64 draft_id_, bool can_stop_, bool keep_on_stop_, object_ptr<formattedText> &&text_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , draft_id_(draft_id_)
  , can_stop_(can_stop_)
  , keep_on_stop_(keep_on_stop_)
  , text_(std::move(text_))
{}

const std::int32_t sendTextMessageDraft::ID;

void sendTextMessageDraft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendTextMessageDraft");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("draft_id", draft_id_);
    s.store_field("can_stop", can_stop_);
    s.store_field("keep_on_stop", keep_on_stop_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

sendWebAppCustomRequest::sendWebAppCustomRequest()
  : bot_user_id_()
  , method_()
  , parameters_()
{}

sendWebAppCustomRequest::sendWebAppCustomRequest(int53 bot_user_id_, string const &method_, string const &parameters_)
  : bot_user_id_(bot_user_id_)
  , method_(method_)
  , parameters_(parameters_)
{}

const std::int32_t sendWebAppCustomRequest::ID;

void sendWebAppCustomRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendWebAppCustomRequest");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("method", method_);
    s.store_field("parameters", parameters_);
    s.store_class_end();
  }
}

sendWebAppData::sendWebAppData()
  : bot_user_id_()
  , button_text_()
  , data_()
{}

sendWebAppData::sendWebAppData(int53 bot_user_id_, string const &button_text_, string const &data_)
  : bot_user_id_(bot_user_id_)
  , button_text_(button_text_)
  , data_(data_)
{}

const std::int32_t sendWebAppData::ID;

void sendWebAppData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendWebAppData");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("button_text", button_text_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

setArchiveChatListSettings::setArchiveChatListSettings()
  : settings_()
{}

setArchiveChatListSettings::setArchiveChatListSettings(object_ptr<archiveChatListSettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t setArchiveChatListSettings::ID;

void setArchiveChatListSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setArchiveChatListSettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setBotInfoDescription::setBotInfoDescription()
  : bot_user_id_()
  , language_code_()
  , description_()
{}

setBotInfoDescription::setBotInfoDescription(int53 bot_user_id_, string const &language_code_, string const &description_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , description_(description_)
{}

const std::int32_t setBotInfoDescription::ID;

void setBotInfoDescription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotInfoDescription");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

setChatMessageSender::setChatMessageSender()
  : chat_id_()
  , message_sender_id_()
{}

setChatMessageSender::setChatMessageSender(int53 chat_id_, object_ptr<MessageSender> &&message_sender_id_)
  : chat_id_(chat_id_)
  , message_sender_id_(std::move(message_sender_id_))
{}

const std::int32_t setChatMessageSender::ID;

void setChatMessageSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatMessageSender");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    s.store_class_end();
  }
}

setChatProfileAccentColor::setChatProfileAccentColor()
  : chat_id_()
  , profile_accent_color_id_()
  , profile_background_custom_emoji_id_()
{}

setChatProfileAccentColor::setChatProfileAccentColor(int53 chat_id_, int32 profile_accent_color_id_, int64 profile_background_custom_emoji_id_)
  : chat_id_(chat_id_)
  , profile_accent_color_id_(profile_accent_color_id_)
  , profile_background_custom_emoji_id_(profile_background_custom_emoji_id_)
{}

const std::int32_t setChatProfileAccentColor::ID;

void setChatProfileAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatProfileAccentColor");
    s.store_field("chat_id", chat_id_);
    s.store_field("profile_accent_color_id", profile_accent_color_id_);
    s.store_field("profile_background_custom_emoji_id", profile_background_custom_emoji_id_);
    s.store_class_end();
  }
}

setCommunityNotificationSettings::setCommunityNotificationSettings()
  : community_id_()
  , notification_settings_()
{}

setCommunityNotificationSettings::setCommunityNotificationSettings(int53 community_id_, object_ptr<chatNotificationSettings> &&notification_settings_)
  : community_id_(community_id_)
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t setCommunityNotificationSettings::ID;

void setCommunityNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCommunityNotificationSettings");
    s.store_field("community_id", community_id_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

setDatabaseEncryptionKey::setDatabaseEncryptionKey()
  : new_encryption_key_()
{}

setDatabaseEncryptionKey::setDatabaseEncryptionKey(bytes const &new_encryption_key_)
  : new_encryption_key_(std::move(new_encryption_key_))
{}

const std::int32_t setDatabaseEncryptionKey::ID;

void setDatabaseEncryptionKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDatabaseEncryptionKey");
    s.store_field("new_encryption_key", "[REDACTED]");
    s.store_class_end();
  }
}

setDefaultGroupAdministratorRights::setDefaultGroupAdministratorRights()
  : default_group_administrator_rights_()
{}

setDefaultGroupAdministratorRights::setDefaultGroupAdministratorRights(object_ptr<chatAdministratorRights> &&default_group_administrator_rights_)
  : default_group_administrator_rights_(std::move(default_group_administrator_rights_))
{}

const std::int32_t setDefaultGroupAdministratorRights::ID;

void setDefaultGroupAdministratorRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultGroupAdministratorRights");
    s.store_object_field("default_group_administrator_rights", static_cast<const BaseObject *>(default_group_administrator_rights_.get()));
    s.store_class_end();
  }
}

setGiftSettings::setGiftSettings()
  : settings_()
{}

setGiftSettings::setGiftSettings(object_ptr<giftSettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t setGiftSettings::ID;

void setGiftSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGiftSettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setLogStream::setLogStream()
  : log_stream_()
{}

setLogStream::setLogStream(object_ptr<LogStream> &&log_stream_)
  : log_stream_(std::move(log_stream_))
{}

const std::int32_t setLogStream::ID;

void setLogStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLogStream");
    s.store_object_field("log_stream", static_cast<const BaseObject *>(log_stream_.get()));
    s.store_class_end();
  }
}

setNewChatPrivacySettings::setNewChatPrivacySettings()
  : settings_()
{}

setNewChatPrivacySettings::setNewChatPrivacySettings(object_ptr<newChatPrivacySettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t setNewChatPrivacySettings::ID;

void setNewChatPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setNewChatPrivacySettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setPinnedChats::setPinnedChats()
  : chat_list_()
  , chat_ids_()
{}

setPinnedChats::setPinnedChats(object_ptr<ChatList> &&chat_list_, array<int53> &&chat_ids_)
  : chat_list_(std::move(chat_list_))
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t setPinnedChats::ID;

void setPinnedChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPinnedChats");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setPollAnswer::setPollAnswer()
  : chat_id_()
  , message_id_()
  , option_ids_()
{}

setPollAnswer::setPollAnswer(int53 chat_id_, int53 message_id_, array<int32> &&option_ids_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_ids_(std::move(option_ids_))
{}

const std::int32_t setPollAnswer::ID;

void setPollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPollAnswer");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("option_ids", option_ids_.size()); for (const auto &_value : option_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setProfileAudioPosition::setProfileAudioPosition()
  : file_id_()
  , after_file_id_()
{}

setProfileAudioPosition::setProfileAudioPosition(int32 file_id_, int32 after_file_id_)
  : file_id_(file_id_)
  , after_file_id_(after_file_id_)
{}

const std::int32_t setProfileAudioPosition::ID;

void setProfileAudioPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setProfileAudioPosition");
    s.store_field("file_id", file_id_);
    s.store_field("after_file_id", after_file_id_);
    s.store_class_end();
  }
}

setUpgradedGiftColors::setUpgradedGiftColors()
  : upgraded_gift_colors_id_()
{}

setUpgradedGiftColors::setUpgradedGiftColors(int64 upgraded_gift_colors_id_)
  : upgraded_gift_colors_id_(upgraded_gift_colors_id_)
{}

const std::int32_t setUpgradedGiftColors::ID;

void setUpgradedGiftColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUpgradedGiftColors");
    s.store_field("upgraded_gift_colors_id", upgraded_gift_colors_id_);
    s.store_class_end();
  }
}

setUserPersonalProfilePhoto::setUserPersonalProfilePhoto()
  : user_id_()
  , photo_()
{}

setUserPersonalProfilePhoto::setUserPersonalProfilePhoto(int53 user_id_, object_ptr<InputChatPhoto> &&photo_)
  : user_id_(user_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t setUserPersonalProfilePhoto::ID;

void setUserPersonalProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUserPersonalProfilePhoto");
    s.store_field("user_id", user_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

setUserSupportInfo::setUserSupportInfo()
  : user_id_()
  , message_()
{}

setUserSupportInfo::setUserSupportInfo(int53 user_id_, object_ptr<formattedText> &&message_)
  : user_id_(user_id_)
  , message_(std::move(message_))
{}

const std::int32_t setUserSupportInfo::ID;

void setUserSupportInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUserSupportInfo");
    s.store_field("user_id", user_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

shareChatWithBot::shareChatWithBot()
  : source_()
  , button_id_()
  , shared_chat_id_()
  , only_check_()
{}

shareChatWithBot::shareChatWithBot(object_ptr<KeyboardButtonSource> &&source_, int32 button_id_, int53 shared_chat_id_, bool only_check_)
  : source_(std::move(source_))
  , button_id_(button_id_)
  , shared_chat_id_(shared_chat_id_)
  , only_check_(only_check_)
{}

const std::int32_t shareChatWithBot::ID;

void shareChatWithBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shareChatWithBot");
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("button_id", button_id_);
    s.store_field("shared_chat_id", shared_chat_id_);
    s.store_field("only_check", only_check_);
    s.store_class_end();
  }
}

startGroupCallScreenSharing::startGroupCallScreenSharing()
  : group_call_id_()
  , audio_source_id_()
  , payload_()
{}

startGroupCallScreenSharing::startGroupCallScreenSharing(int32 group_call_id_, int32 audio_source_id_, string const &payload_)
  : group_call_id_(group_call_id_)
  , audio_source_id_(audio_source_id_)
  , payload_(payload_)
{}

const std::int32_t startGroupCallScreenSharing::ID;

void startGroupCallScreenSharing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startGroupCallScreenSharing");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("audio_source_id", audio_source_id_);
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

terminateAllOtherSessions::terminateAllOtherSessions() {
}

const std::int32_t terminateAllOtherSessions::ID;

void terminateAllOtherSessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "terminateAllOtherSessions");
    s.store_class_end();
  }
}

testCallEmpty::testCallEmpty() {
}

const std::int32_t testCallEmpty::ID;

void testCallEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallEmpty");
    s.store_class_end();
  }
}

testGetDifference::testGetDifference() {
}

const std::int32_t testGetDifference::ID;

void testGetDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testGetDifference");
    s.store_class_end();
  }
}

testSquareInt::testSquareInt()
  : x_()
{}

testSquareInt::testSquareInt(int32 x_)
  : x_(x_)
{}

const std::int32_t testSquareInt::ID;

void testSquareInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testSquareInt");
    s.store_field("x", x_);
    s.store_class_end();
  }
}

translateRichMessage::translateRichMessage()
  : message_()
  , to_language_code_()
  , tone_()
{}

translateRichMessage::translateRichMessage(object_ptr<inputRichMessage> &&message_, string const &to_language_code_, string const &tone_)
  : message_(std::move(message_))
  , to_language_code_(to_language_code_)
  , tone_(tone_)
{}

const std::int32_t translateRichMessage::ID;

void translateRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "translateRichMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("to_language_code", to_language_code_);
    s.store_field("tone", tone_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
