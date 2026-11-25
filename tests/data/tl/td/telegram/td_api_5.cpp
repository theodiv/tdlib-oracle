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


acceptedGiftTypes::acceptedGiftTypes()
  : unlimited_gifts_()
  , limited_gifts_()
  , upgraded_gifts_()
  , gifts_from_channels_()
  , premium_subscription_()
{}

acceptedGiftTypes::acceptedGiftTypes(bool unlimited_gifts_, bool limited_gifts_, bool upgraded_gifts_, bool gifts_from_channels_, bool premium_subscription_)
  : unlimited_gifts_(unlimited_gifts_)
  , limited_gifts_(limited_gifts_)
  , upgraded_gifts_(upgraded_gifts_)
  , gifts_from_channels_(gifts_from_channels_)
  , premium_subscription_(premium_subscription_)
{}

const std::int32_t acceptedGiftTypes::ID;

void acceptedGiftTypes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "acceptedGiftTypes");
    s.store_field("unlimited_gifts", unlimited_gifts_);
    s.store_field("limited_gifts", limited_gifts_);
    s.store_field("upgraded_gifts", upgraded_gifts_);
    s.store_field("gifts_from_channels", gifts_from_channels_);
    s.store_field("premium_subscription", premium_subscription_);
    s.store_class_end();
  }
}

affiliateProgramSortOrderProfitability::affiliateProgramSortOrderProfitability() {
}

const std::int32_t affiliateProgramSortOrderProfitability::ID;

void affiliateProgramSortOrderProfitability::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateProgramSortOrderProfitability");
    s.store_class_end();
  }
}

affiliateProgramSortOrderCreationDate::affiliateProgramSortOrderCreationDate() {
}

const std::int32_t affiliateProgramSortOrderCreationDate::ID;

void affiliateProgramSortOrderCreationDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateProgramSortOrderCreationDate");
    s.store_class_end();
  }
}

affiliateProgramSortOrderRevenue::affiliateProgramSortOrderRevenue() {
}

const std::int32_t affiliateProgramSortOrderRevenue::ID;

void affiliateProgramSortOrderRevenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateProgramSortOrderRevenue");
    s.store_class_end();
  }
}

auctionRound::auctionRound()
  : number_()
  , duration_()
  , extend_time_()
  , top_winner_count_()
{}

auctionRound::auctionRound(int32 number_, int32 duration_, int32 extend_time_, int32 top_winner_count_)
  : number_(number_)
  , duration_(duration_)
  , extend_time_(extend_time_)
  , top_winner_count_(top_winner_count_)
{}

const std::int32_t auctionRound::ID;

void auctionRound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auctionRound");
    s.store_field("number", number_);
    s.store_field("duration", duration_);
    s.store_field("extend_time", extend_time_);
    s.store_field("top_winner_count", top_winner_count_);
    s.store_class_end();
  }
}

autoDownloadSettings::autoDownloadSettings()
  : is_auto_download_enabled_()
  , max_photo_file_size_()
  , max_video_file_size_()
  , max_other_file_size_()
  , video_upload_bitrate_()
  , preload_large_videos_()
  , preload_next_audio_()
  , preload_stories_()
  , use_less_data_for_calls_()
{}

autoDownloadSettings::autoDownloadSettings(bool is_auto_download_enabled_, int32 max_photo_file_size_, int53 max_video_file_size_, int53 max_other_file_size_, int32 video_upload_bitrate_, bool preload_large_videos_, bool preload_next_audio_, bool preload_stories_, bool use_less_data_for_calls_)
  : is_auto_download_enabled_(is_auto_download_enabled_)
  , max_photo_file_size_(max_photo_file_size_)
  , max_video_file_size_(max_video_file_size_)
  , max_other_file_size_(max_other_file_size_)
  , video_upload_bitrate_(video_upload_bitrate_)
  , preload_large_videos_(preload_large_videos_)
  , preload_next_audio_(preload_next_audio_)
  , preload_stories_(preload_stories_)
  , use_less_data_for_calls_(use_less_data_for_calls_)
{}

const std::int32_t autoDownloadSettings::ID;

void autoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoDownloadSettings");
    s.store_field("is_auto_download_enabled", is_auto_download_enabled_);
    s.store_field("max_photo_file_size", max_photo_file_size_);
    s.store_field("max_video_file_size", max_video_file_size_);
    s.store_field("max_other_file_size", max_other_file_size_);
    s.store_field("video_upload_bitrate", video_upload_bitrate_);
    s.store_field("preload_large_videos", preload_large_videos_);
    s.store_field("preload_next_audio", preload_next_audio_);
    s.store_field("preload_stories", preload_stories_);
    s.store_field("use_less_data_for_calls", use_less_data_for_calls_);
    s.store_class_end();
  }
}

autosaveSettingsScopePrivateChats::autosaveSettingsScopePrivateChats() {
}

const std::int32_t autosaveSettingsScopePrivateChats::ID;

void autosaveSettingsScopePrivateChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettingsScopePrivateChats");
    s.store_class_end();
  }
}

autosaveSettingsScopeGroupChats::autosaveSettingsScopeGroupChats() {
}

const std::int32_t autosaveSettingsScopeGroupChats::ID;

void autosaveSettingsScopeGroupChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettingsScopeGroupChats");
    s.store_class_end();
  }
}

autosaveSettingsScopeChannelChats::autosaveSettingsScopeChannelChats() {
}

const std::int32_t autosaveSettingsScopeChannelChats::ID;

void autosaveSettingsScopeChannelChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettingsScopeChannelChats");
    s.store_class_end();
  }
}

autosaveSettingsScopeChat::autosaveSettingsScopeChat()
  : chat_id_()
{}

autosaveSettingsScopeChat::autosaveSettingsScopeChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t autosaveSettingsScopeChat::ID;

void autosaveSettingsScopeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettingsScopeChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

bankCardActionOpenUrl::bankCardActionOpenUrl()
  : text_()
  , url_()
{}

bankCardActionOpenUrl::bankCardActionOpenUrl(string const &text_, string const &url_)
  : text_(text_)
  , url_(url_)
{}

const std::int32_t bankCardActionOpenUrl::ID;

void bankCardActionOpenUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bankCardActionOpenUrl");
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

blockListMain::blockListMain() {
}

const std::int32_t blockListMain::ID;

void blockListMain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "blockListMain");
    s.store_class_end();
  }
}

blockListStories::blockListStories() {
}

const std::int32_t blockListStories::ID;

void blockListStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "blockListStories");
    s.store_class_end();
  }
}

botCommandScopeDefault::botCommandScopeDefault() {
}

const std::int32_t botCommandScopeDefault::ID;

void botCommandScopeDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeDefault");
    s.store_class_end();
  }
}

botCommandScopeAllPrivateChats::botCommandScopeAllPrivateChats() {
}

const std::int32_t botCommandScopeAllPrivateChats::ID;

void botCommandScopeAllPrivateChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeAllPrivateChats");
    s.store_class_end();
  }
}

botCommandScopeAllGroupChats::botCommandScopeAllGroupChats() {
}

const std::int32_t botCommandScopeAllGroupChats::ID;

void botCommandScopeAllGroupChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeAllGroupChats");
    s.store_class_end();
  }
}

botCommandScopeAllChatAdministrators::botCommandScopeAllChatAdministrators() {
}

const std::int32_t botCommandScopeAllChatAdministrators::ID;

void botCommandScopeAllChatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeAllChatAdministrators");
    s.store_class_end();
  }
}

botCommandScopeChat::botCommandScopeChat()
  : chat_id_()
{}

botCommandScopeChat::botCommandScopeChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t botCommandScopeChat::ID;

void botCommandScopeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

botCommandScopeChatAdministrators::botCommandScopeChatAdministrators()
  : chat_id_()
{}

botCommandScopeChatAdministrators::botCommandScopeChatAdministrators(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t botCommandScopeChatAdministrators::ID;

void botCommandScopeChatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChatAdministrators");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

botCommandScopeChatMember::botCommandScopeChatMember()
  : chat_id_()
  , user_id_()
{}

botCommandScopeChatMember::botCommandScopeChatMember(int53 chat_id_, int53 user_id_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
{}

const std::int32_t botCommandScopeChatMember::ID;

void botCommandScopeChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

botSettingIsInline::botSettingIsInline()
  : is_inline_()
{}

botSettingIsInline::botSettingIsInline(bool is_inline_)
  : is_inline_(is_inline_)
{}

const std::int32_t botSettingIsInline::ID;

void botSettingIsInline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingIsInline");
    s.store_field("is_inline", is_inline_);
    s.store_class_end();
  }
}

botSettingInlineQueryPlaceholder::botSettingInlineQueryPlaceholder()
  : placeholder_()
{}

botSettingInlineQueryPlaceholder::botSettingInlineQueryPlaceholder(string const &placeholder_)
  : placeholder_(placeholder_)
{}

const std::int32_t botSettingInlineQueryPlaceholder::ID;

void botSettingInlineQueryPlaceholder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingInlineQueryPlaceholder");
    s.store_field("placeholder", placeholder_);
    s.store_class_end();
  }
}

botSettingNeedLocation::botSettingNeedLocation()
  : need_location_()
{}

botSettingNeedLocation::botSettingNeedLocation(bool need_location_)
  : need_location_(need_location_)
{}

const std::int32_t botSettingNeedLocation::ID;

void botSettingNeedLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingNeedLocation");
    s.store_field("need_location", need_location_);
    s.store_class_end();
  }
}

botSettingInlineFeedback::botSettingInlineFeedback()
  : share_denominator_()
{}

botSettingInlineFeedback::botSettingInlineFeedback(int32 share_denominator_)
  : share_denominator_(share_denominator_)
{}

const std::int32_t botSettingInlineFeedback::ID;

void botSettingInlineFeedback::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingInlineFeedback");
    s.store_field("share_denominator", share_denominator_);
    s.store_class_end();
  }
}

botSettingCanJoinGroups::botSettingCanJoinGroups()
  : can_join_groups_()
{}

botSettingCanJoinGroups::botSettingCanJoinGroups(bool can_join_groups_)
  : can_join_groups_(can_join_groups_)
{}

const std::int32_t botSettingCanJoinGroups::ID;

void botSettingCanJoinGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingCanJoinGroups");
    s.store_field("can_join_groups", can_join_groups_);
    s.store_class_end();
  }
}

botSettingCanReadAllGroupMessages::botSettingCanReadAllGroupMessages()
  : can_read_all_group_messages_()
{}

botSettingCanReadAllGroupMessages::botSettingCanReadAllGroupMessages(bool can_read_all_group_messages_)
  : can_read_all_group_messages_(can_read_all_group_messages_)
{}

const std::int32_t botSettingCanReadAllGroupMessages::ID;

void botSettingCanReadAllGroupMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingCanReadAllGroupMessages");
    s.store_field("can_read_all_group_messages", can_read_all_group_messages_);
    s.store_class_end();
  }
}

botSettingCanConnectToBusiness::botSettingCanConnectToBusiness()
  : can_connect_to_business_()
{}

botSettingCanConnectToBusiness::botSettingCanConnectToBusiness(bool can_connect_to_business_)
  : can_connect_to_business_(can_connect_to_business_)
{}

const std::int32_t botSettingCanConnectToBusiness::ID;

void botSettingCanConnectToBusiness::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingCanConnectToBusiness");
    s.store_field("can_connect_to_business", can_connect_to_business_);
    s.store_class_end();
  }
}

botSettingCanManageBots::botSettingCanManageBots()
  : can_manage_bots_()
{}

botSettingCanManageBots::botSettingCanManageBots(bool can_manage_bots_)
  : can_manage_bots_(can_manage_bots_)
{}

const std::int32_t botSettingCanManageBots::ID;

void botSettingCanManageBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingCanManageBots");
    s.store_field("can_manage_bots", can_manage_bots_);
    s.store_class_end();
  }
}

botSettingSupportsGuestQueries::botSettingSupportsGuestQueries()
  : supports_guest_queries_()
{}

botSettingSupportsGuestQueries::botSettingSupportsGuestQueries(bool supports_guest_queries_)
  : supports_guest_queries_(supports_guest_queries_)
{}

const std::int32_t botSettingSupportsGuestQueries::ID;

void botSettingSupportsGuestQueries::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingSupportsGuestQueries");
    s.store_field("supports_guest_queries", supports_guest_queries_);
    s.store_class_end();
  }
}

botSettingIsGuard::botSettingIsGuard()
  : is_guard_()
{}

botSettingIsGuard::botSettingIsGuard(bool is_guard_)
  : is_guard_(is_guard_)
{}

const std::int32_t botSettingIsGuard::ID;

void botSettingIsGuard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingIsGuard");
    s.store_field("is_guard", is_guard_);
    s.store_class_end();
  }
}

botSettingHasTopics::botSettingHasTopics()
  : has_topics_()
{}

botSettingHasTopics::botSettingHasTopics(bool has_topics_)
  : has_topics_(has_topics_)
{}

const std::int32_t botSettingHasTopics::ID;

void botSettingHasTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingHasTopics");
    s.store_field("has_topics", has_topics_);
    s.store_class_end();
  }
}

botSettingAllowsUsersToCreateTopics::botSettingAllowsUsersToCreateTopics()
  : allows_users_to_create_topics_()
{}

botSettingAllowsUsersToCreateTopics::botSettingAllowsUsersToCreateTopics(bool allows_users_to_create_topics_)
  : allows_users_to_create_topics_(allows_users_to_create_topics_)
{}

const std::int32_t botSettingAllowsUsersToCreateTopics::ID;

void botSettingAllowsUsersToCreateTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingAllowsUsersToCreateTopics");
    s.store_field("allows_users_to_create_topics", allows_users_to_create_topics_);
    s.store_class_end();
  }
}

botSettingHasTopicSidebar::botSettingHasTopicSidebar()
  : has_topic_sidebar_()
{}

botSettingHasTopicSidebar::botSettingHasTopicSidebar(bool has_topic_sidebar_)
  : has_topic_sidebar_(has_topic_sidebar_)
{}

const std::int32_t botSettingHasTopicSidebar::ID;

void botSettingHasTopicSidebar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingHasTopicSidebar");
    s.store_field("has_topic_sidebar", has_topic_sidebar_);
    s.store_class_end();
  }
}

botSettingCanCommunicateWithBots::botSettingCanCommunicateWithBots()
  : can_communicate_with_bots_()
{}

botSettingCanCommunicateWithBots::botSettingCanCommunicateWithBots(bool can_communicate_with_bots_)
  : can_communicate_with_bots_(can_communicate_with_bots_)
{}

const std::int32_t botSettingCanCommunicateWithBots::ID;

void botSettingCanCommunicateWithBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingCanCommunicateWithBots");
    s.store_field("can_communicate_with_bots", can_communicate_with_bots_);
    s.store_class_end();
  }
}

botSettingCallbackQueryMode::botSettingCallbackQueryMode()
  : mode_()
{}

botSettingCallbackQueryMode::botSettingCallbackQueryMode(object_ptr<BotCallbackQueryMode> &&mode_)
  : mode_(std::move(mode_))
{}

const std::int32_t botSettingCallbackQueryMode::ID;

void botSettingCallbackQueryMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botSettingCallbackQueryMode");
    s.store_object_field("mode", static_cast<const BaseObject *>(mode_.get()));
    s.store_class_end();
  }
}

businessFeatureLocation::businessFeatureLocation() {
}

const std::int32_t businessFeatureLocation::ID;

void businessFeatureLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureLocation");
    s.store_class_end();
  }
}

businessFeatureOpeningHours::businessFeatureOpeningHours() {
}

const std::int32_t businessFeatureOpeningHours::ID;

void businessFeatureOpeningHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureOpeningHours");
    s.store_class_end();
  }
}

businessFeatureQuickReplies::businessFeatureQuickReplies() {
}

const std::int32_t businessFeatureQuickReplies::ID;

void businessFeatureQuickReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureQuickReplies");
    s.store_class_end();
  }
}

businessFeatureGreetingMessage::businessFeatureGreetingMessage() {
}

const std::int32_t businessFeatureGreetingMessage::ID;

void businessFeatureGreetingMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureGreetingMessage");
    s.store_class_end();
  }
}

businessFeatureAwayMessage::businessFeatureAwayMessage() {
}

const std::int32_t businessFeatureAwayMessage::ID;

void businessFeatureAwayMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureAwayMessage");
    s.store_class_end();
  }
}

businessFeatureAccountLinks::businessFeatureAccountLinks() {
}

const std::int32_t businessFeatureAccountLinks::ID;

void businessFeatureAccountLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureAccountLinks");
    s.store_class_end();
  }
}

businessFeatureStartPage::businessFeatureStartPage() {
}

const std::int32_t businessFeatureStartPage::ID;

void businessFeatureStartPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureStartPage");
    s.store_class_end();
  }
}

businessFeatureBots::businessFeatureBots() {
}

const std::int32_t businessFeatureBots::ID;

void businessFeatureBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureBots");
    s.store_class_end();
  }
}

businessFeatureEmojiStatus::businessFeatureEmojiStatus() {
}

const std::int32_t businessFeatureEmojiStatus::ID;

void businessFeatureEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureEmojiStatus");
    s.store_class_end();
  }
}

businessFeatureChatFolderTags::businessFeatureChatFolderTags() {
}

const std::int32_t businessFeatureChatFolderTags::ID;

void businessFeatureChatFolderTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureChatFolderTags");
    s.store_class_end();
  }
}

businessFeatureUpgradedStories::businessFeatureUpgradedStories() {
}

const std::int32_t businessFeatureUpgradedStories::ID;

void businessFeatureUpgradedStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureUpgradedStories");
    s.store_class_end();
  }
}

businessOpeningHoursInterval::businessOpeningHoursInterval()
  : start_minute_()
  , end_minute_()
{}

businessOpeningHoursInterval::businessOpeningHoursInterval(int32 start_minute_, int32 end_minute_)
  : start_minute_(start_minute_)
  , end_minute_(end_minute_)
{}

const std::int32_t businessOpeningHoursInterval::ID;

void businessOpeningHoursInterval::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessOpeningHoursInterval");
    s.store_field("start_minute", start_minute_);
    s.store_field("end_minute", end_minute_);
    s.store_class_end();
  }
}

callServerTypeTelegramReflector::callServerTypeTelegramReflector()
  : peer_tag_()
  , is_tcp_()
{}

callServerTypeTelegramReflector::callServerTypeTelegramReflector(bytes const &peer_tag_, bool is_tcp_)
  : peer_tag_(std::move(peer_tag_))
  , is_tcp_(is_tcp_)
{}

const std::int32_t callServerTypeTelegramReflector::ID;

void callServerTypeTelegramReflector::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callServerTypeTelegramReflector");
    s.store_bytes_field("peer_tag", peer_tag_);
    s.store_field("is_tcp", is_tcp_);
    s.store_class_end();
  }
}

callServerTypeWebrtc::callServerTypeWebrtc()
  : username_()
  , password_()
  , supports_turn_()
  , supports_stun_()
{}

callServerTypeWebrtc::callServerTypeWebrtc(string const &username_, string const &password_, bool supports_turn_, bool supports_stun_)
  : username_(username_)
  , password_(password_)
  , supports_turn_(supports_turn_)
  , supports_stun_(supports_stun_)
{}

const std::int32_t callServerTypeWebrtc::ID;

void callServerTypeWebrtc::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callServerTypeWebrtc");
    s.store_field("username", username_);
    s.store_field("password", "[REDACTED]");
    s.store_field("supports_turn", supports_turn_);
    s.store_field("supports_stun", supports_stun_);
    s.store_class_end();
  }
}

canSendMessageToUserResultOk::canSendMessageToUserResultOk() {
}

const std::int32_t canSendMessageToUserResultOk::ID;

void canSendMessageToUserResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendMessageToUserResultOk");
    s.store_class_end();
  }
}

canSendMessageToUserResultUserHasPaidMessages::canSendMessageToUserResultUserHasPaidMessages()
  : outgoing_paid_message_star_count_()
{}

canSendMessageToUserResultUserHasPaidMessages::canSendMessageToUserResultUserHasPaidMessages(int53 outgoing_paid_message_star_count_)
  : outgoing_paid_message_star_count_(outgoing_paid_message_star_count_)
{}

const std::int32_t canSendMessageToUserResultUserHasPaidMessages::ID;

void canSendMessageToUserResultUserHasPaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendMessageToUserResultUserHasPaidMessages");
    s.store_field("outgoing_paid_message_star_count", outgoing_paid_message_star_count_);
    s.store_class_end();
  }
}

canSendMessageToUserResultUserIsDeleted::canSendMessageToUserResultUserIsDeleted() {
}

const std::int32_t canSendMessageToUserResultUserIsDeleted::ID;

void canSendMessageToUserResultUserIsDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendMessageToUserResultUserIsDeleted");
    s.store_class_end();
  }
}

canSendMessageToUserResultUserRestrictsNewChats::canSendMessageToUserResultUserRestrictsNewChats() {
}

const std::int32_t canSendMessageToUserResultUserRestrictsNewChats::ID;

void canSendMessageToUserResultUserRestrictsNewChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendMessageToUserResultUserRestrictsNewChats");
    s.store_class_end();
  }
}

chatActiveStories::chatActiveStories()
  : chat_id_()
  , list_()
  , order_()
  , can_be_archived_()
  , max_read_story_id_()
  , stories_()
{}

chatActiveStories::chatActiveStories(int53 chat_id_, object_ptr<StoryList> &&list_, int53 order_, bool can_be_archived_, int32 max_read_story_id_, array<object_ptr<storyInfo>> &&stories_)
  : chat_id_(chat_id_)
  , list_(std::move(list_))
  , order_(order_)
  , can_be_archived_(can_be_archived_)
  , max_read_story_id_(max_read_story_id_)
  , stories_(std::move(stories_))
{}

const std::int32_t chatActiveStories::ID;

void chatActiveStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActiveStories");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("list", static_cast<const BaseObject *>(list_.get()));
    s.store_field("order", order_);
    s.store_field("can_be_archived", can_be_archived_);
    s.store_field("max_read_story_id", max_read_story_id_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatFolderInviteLink::chatFolderInviteLink()
  : invite_link_()
  , name_()
  , chat_ids_()
{}

chatFolderInviteLink::chatFolderInviteLink(string const &invite_link_, string const &name_, array<int53> &&chat_ids_)
  : invite_link_(invite_link_)
  , name_(name_)
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t chatFolderInviteLink::ID;

void chatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatInviteLinkCounts::chatInviteLinkCounts()
  : invite_link_counts_()
{}

chatInviteLinkCounts::chatInviteLinkCounts(array<object_ptr<chatInviteLinkCount>> &&invite_link_counts_)
  : invite_link_counts_(std::move(invite_link_counts_))
{}

const std::int32_t chatInviteLinkCounts::ID;

void chatInviteLinkCounts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkCounts");
    { s.store_vector_begin("invite_link_counts", invite_link_counts_.size()); for (const auto &_value : invite_link_counts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatPhotoStickerTypeRegularOrMask::chatPhotoStickerTypeRegularOrMask()
  : sticker_set_id_()
  , sticker_id_()
{}

chatPhotoStickerTypeRegularOrMask::chatPhotoStickerTypeRegularOrMask(int64 sticker_set_id_, int64 sticker_id_)
  : sticker_set_id_(sticker_set_id_)
  , sticker_id_(sticker_id_)
{}

const std::int32_t chatPhotoStickerTypeRegularOrMask::ID;

void chatPhotoStickerTypeRegularOrMask::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotoStickerTypeRegularOrMask");
    s.store_field("sticker_set_id", sticker_set_id_);
    s.store_field("sticker_id", sticker_id_);
    s.store_class_end();
  }
}

chatPhotoStickerTypeCustomEmoji::chatPhotoStickerTypeCustomEmoji()
  : custom_emoji_id_()
{}

chatPhotoStickerTypeCustomEmoji::chatPhotoStickerTypeCustomEmoji(int64 custom_emoji_id_)
  : custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t chatPhotoStickerTypeCustomEmoji::ID;

void chatPhotoStickerTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotoStickerTypeCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

chatRevenueStatistics::chatRevenueStatistics()
  : revenue_by_hour_graph_()
  , revenue_graph_()
  , revenue_amount_()
  , usd_rate_()
{}

chatRevenueStatistics::chatRevenueStatistics(object_ptr<StatisticalGraph> &&revenue_by_hour_graph_, object_ptr<StatisticalGraph> &&revenue_graph_, object_ptr<chatRevenueAmount> &&revenue_amount_, double usd_rate_)
  : revenue_by_hour_graph_(std::move(revenue_by_hour_graph_))
  , revenue_graph_(std::move(revenue_graph_))
  , revenue_amount_(std::move(revenue_amount_))
  , usd_rate_(usd_rate_)
{}

const std::int32_t chatRevenueStatistics::ID;

void chatRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueStatistics");
    s.store_object_field("revenue_by_hour_graph", static_cast<const BaseObject *>(revenue_by_hour_graph_.get()));
    s.store_object_field("revenue_graph", static_cast<const BaseObject *>(revenue_graph_.get()));
    s.store_object_field("revenue_amount", static_cast<const BaseObject *>(revenue_amount_.get()));
    s.store_field("usd_rate", usd_rate_);
    s.store_class_end();
  }
}

chatStatisticsAdministratorActionsInfo::chatStatisticsAdministratorActionsInfo()
  : user_id_()
  , deleted_message_count_()
  , banned_user_count_()
  , restricted_user_count_()
{}

chatStatisticsAdministratorActionsInfo::chatStatisticsAdministratorActionsInfo(int53 user_id_, int32 deleted_message_count_, int32 banned_user_count_, int32 restricted_user_count_)
  : user_id_(user_id_)
  , deleted_message_count_(deleted_message_count_)
  , banned_user_count_(banned_user_count_)
  , restricted_user_count_(restricted_user_count_)
{}

const std::int32_t chatStatisticsAdministratorActionsInfo::ID;

void chatStatisticsAdministratorActionsInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsAdministratorActionsInfo");
    s.store_field("user_id", user_id_);
    s.store_field("deleted_message_count", deleted_message_count_);
    s.store_field("banned_user_count", banned_user_count_);
    s.store_field("restricted_user_count", restricted_user_count_);
    s.store_class_end();
  }
}

checkChatUsernameResultOk::checkChatUsernameResultOk() {
}

const std::int32_t checkChatUsernameResultOk::ID;

void checkChatUsernameResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultOk");
    s.store_class_end();
  }
}

checkChatUsernameResultUsernameInvalid::checkChatUsernameResultUsernameInvalid() {
}

const std::int32_t checkChatUsernameResultUsernameInvalid::ID;

void checkChatUsernameResultUsernameInvalid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultUsernameInvalid");
    s.store_class_end();
  }
}

checkChatUsernameResultUsernameOccupied::checkChatUsernameResultUsernameOccupied() {
}

const std::int32_t checkChatUsernameResultUsernameOccupied::ID;

void checkChatUsernameResultUsernameOccupied::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultUsernameOccupied");
    s.store_class_end();
  }
}

checkChatUsernameResultUsernamePurchasable::checkChatUsernameResultUsernamePurchasable() {
}

const std::int32_t checkChatUsernameResultUsernamePurchasable::ID;

void checkChatUsernameResultUsernamePurchasable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultUsernamePurchasable");
    s.store_class_end();
  }
}

checkChatUsernameResultPublicChatsTooMany::checkChatUsernameResultPublicChatsTooMany() {
}

const std::int32_t checkChatUsernameResultPublicChatsTooMany::ID;

void checkChatUsernameResultPublicChatsTooMany::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultPublicChatsTooMany");
    s.store_class_end();
  }
}

checkChatUsernameResultPublicGroupsUnavailable::checkChatUsernameResultPublicGroupsUnavailable() {
}

const std::int32_t checkChatUsernameResultPublicGroupsUnavailable::ID;

void checkChatUsernameResultPublicGroupsUnavailable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultPublicGroupsUnavailable");
    s.store_class_end();
  }
}

communityAddChatRequests::communityAddChatRequests()
  : total_count_()
  , requests_()
  , next_offset_()
{}

communityAddChatRequests::communityAddChatRequests(int32 total_count_, array<object_ptr<communityAddChatRequest>> &&requests_, string const &next_offset_)
  : total_count_(total_count_)
  , requests_(std::move(requests_))
  , next_offset_(next_offset_)
{}

const std::int32_t communityAddChatRequests::ID;

void communityAddChatRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityAddChatRequests");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("requests", requests_.size()); for (const auto &_value : requests_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

data::data()
  : data_()
{}

data::data(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t data::ID;

void data::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "data");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

deviceTokenFirebaseCloudMessaging::deviceTokenFirebaseCloudMessaging()
  : token_()
  , encrypt_()
{}

deviceTokenFirebaseCloudMessaging::deviceTokenFirebaseCloudMessaging(string const &token_, bool encrypt_)
  : token_(token_)
  , encrypt_(encrypt_)
{}

const std::int32_t deviceTokenFirebaseCloudMessaging::ID;

void deviceTokenFirebaseCloudMessaging::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenFirebaseCloudMessaging");
    s.store_field("token", "[REDACTED]");
    s.store_field("encrypt", encrypt_);
    s.store_class_end();
  }
}

deviceTokenApplePush::deviceTokenApplePush()
  : device_token_()
  , is_app_sandbox_()
{}

deviceTokenApplePush::deviceTokenApplePush(string const &device_token_, bool is_app_sandbox_)
  : device_token_(device_token_)
  , is_app_sandbox_(is_app_sandbox_)
{}

const std::int32_t deviceTokenApplePush::ID;

void deviceTokenApplePush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenApplePush");
    s.store_field("device_token", "[REDACTED]");
    s.store_field("is_app_sandbox", is_app_sandbox_);
    s.store_class_end();
  }
}

deviceTokenApplePushVoIP::deviceTokenApplePushVoIP()
  : device_token_()
  , is_app_sandbox_()
  , encrypt_()
{}

deviceTokenApplePushVoIP::deviceTokenApplePushVoIP(string const &device_token_, bool is_app_sandbox_, bool encrypt_)
  : device_token_(device_token_)
  , is_app_sandbox_(is_app_sandbox_)
  , encrypt_(encrypt_)
{}

const std::int32_t deviceTokenApplePushVoIP::ID;

void deviceTokenApplePushVoIP::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenApplePushVoIP");
    s.store_field("device_token", "[REDACTED]");
    s.store_field("is_app_sandbox", is_app_sandbox_);
    s.store_field("encrypt", encrypt_);
    s.store_class_end();
  }
}

deviceTokenWindowsPush::deviceTokenWindowsPush()
  : access_token_()
{}

deviceTokenWindowsPush::deviceTokenWindowsPush(string const &access_token_)
  : access_token_(access_token_)
{}

const std::int32_t deviceTokenWindowsPush::ID;

void deviceTokenWindowsPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenWindowsPush");
    s.store_field("access_token", "[REDACTED]");
    s.store_class_end();
  }
}

deviceTokenMicrosoftPush::deviceTokenMicrosoftPush()
  : channel_uri_()
{}

deviceTokenMicrosoftPush::deviceTokenMicrosoftPush(string const &channel_uri_)
  : channel_uri_(channel_uri_)
{}

const std::int32_t deviceTokenMicrosoftPush::ID;

void deviceTokenMicrosoftPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenMicrosoftPush");
    s.store_field("channel_uri", channel_uri_);
    s.store_class_end();
  }
}

deviceTokenMicrosoftPushVoIP::deviceTokenMicrosoftPushVoIP()
  : channel_uri_()
{}

deviceTokenMicrosoftPushVoIP::deviceTokenMicrosoftPushVoIP(string const &channel_uri_)
  : channel_uri_(channel_uri_)
{}

const std::int32_t deviceTokenMicrosoftPushVoIP::ID;

void deviceTokenMicrosoftPushVoIP::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenMicrosoftPushVoIP");
    s.store_field("channel_uri", channel_uri_);
    s.store_class_end();
  }
}

deviceTokenWebPush::deviceTokenWebPush()
  : endpoint_()
  , p256dh_base64url_()
  , auth_base64url_()
{}

deviceTokenWebPush::deviceTokenWebPush(string const &endpoint_, string const &p256dh_base64url_, string const &auth_base64url_)
  : endpoint_(endpoint_)
  , p256dh_base64url_(p256dh_base64url_)
  , auth_base64url_(auth_base64url_)
{}

const std::int32_t deviceTokenWebPush::ID;

void deviceTokenWebPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenWebPush");
    s.store_field("endpoint", endpoint_);
    s.store_field("p256dh_base64url", p256dh_base64url_);
    s.store_field("auth_base64url", "[REDACTED]");
    s.store_class_end();
  }
}

deviceTokenSimplePush::deviceTokenSimplePush()
  : endpoint_()
{}

deviceTokenSimplePush::deviceTokenSimplePush(string const &endpoint_)
  : endpoint_(endpoint_)
{}

const std::int32_t deviceTokenSimplePush::ID;

void deviceTokenSimplePush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenSimplePush");
    s.store_field("endpoint", endpoint_);
    s.store_class_end();
  }
}

deviceTokenUbuntuPush::deviceTokenUbuntuPush()
  : token_()
{}

deviceTokenUbuntuPush::deviceTokenUbuntuPush(string const &token_)
  : token_(token_)
{}

const std::int32_t deviceTokenUbuntuPush::ID;

void deviceTokenUbuntuPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenUbuntuPush");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

deviceTokenBlackBerryPush::deviceTokenBlackBerryPush()
  : token_()
{}

deviceTokenBlackBerryPush::deviceTokenBlackBerryPush(string const &token_)
  : token_(token_)
{}

const std::int32_t deviceTokenBlackBerryPush::ID;

void deviceTokenBlackBerryPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenBlackBerryPush");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

deviceTokenTizenPush::deviceTokenTizenPush()
  : reg_id_()
{}

deviceTokenTizenPush::deviceTokenTizenPush(string const &reg_id_)
  : reg_id_(reg_id_)
{}

const std::int32_t deviceTokenTizenPush::ID;

void deviceTokenTizenPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenTizenPush");
    s.store_field("reg_id", reg_id_);
    s.store_class_end();
  }
}

deviceTokenHuaweiPush::deviceTokenHuaweiPush()
  : token_()
  , encrypt_()
{}

deviceTokenHuaweiPush::deviceTokenHuaweiPush(string const &token_, bool encrypt_)
  : token_(token_)
  , encrypt_(encrypt_)
{}

const std::int32_t deviceTokenHuaweiPush::ID;

void deviceTokenHuaweiPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenHuaweiPush");
    s.store_field("token", "[REDACTED]");
    s.store_field("encrypt", encrypt_);
    s.store_class_end();
  }
}

diffText::diffText()
  : text_()
  , entities_()
{}

diffText::diffText(string const &text_, array<object_ptr<diffEntity>> &&entities_)
  : text_(text_)
  , entities_(std::move(entities_))
{}

const std::int32_t diffText::ID;

void diffText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diffText");
    s.store_field("text", text_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

emojiCategory::emojiCategory()
  : name_()
  , icon_()
  , source_()
  , is_greeting_()
{}

emojiCategory::emojiCategory(string const &name_, object_ptr<sticker> &&icon_, object_ptr<EmojiCategorySource> &&source_, bool is_greeting_)
  : name_(name_)
  , icon_(std::move(icon_))
  , source_(std::move(source_))
  , is_greeting_(is_greeting_)
{}

const std::int32_t emojiCategory::ID;

void emojiCategory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategory");
    s.store_field("name", name_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("is_greeting", is_greeting_);
    s.store_class_end();
  }
}

game::game()
  : id_()
  , short_name_()
  , title_()
  , text_()
  , description_()
  , photo_()
  , animation_()
{}

game::game(int64 id_, string const &short_name_, string const &title_, object_ptr<formattedText> &&text_, string const &description_, object_ptr<photo> &&photo_, object_ptr<animation> &&animation_)
  : id_(id_)
  , short_name_(short_name_)
  , title_(title_)
  , text_(std::move(text_))
  , description_(description_)
  , photo_(std::move(photo_))
  , animation_(std::move(animation_))
{}

const std::int32_t game::ID;

void game::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "game");
    s.store_field("id", id_);
    s.store_field("short_name", short_name_);
    s.store_field("title", title_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

giftCollection::giftCollection()
  : id_()
  , name_()
  , icon_()
  , gift_count_()
{}

giftCollection::giftCollection(int32 id_, string const &name_, object_ptr<sticker> &&icon_, int32 gift_count_)
  : id_(id_)
  , name_(name_)
  , icon_(std::move(icon_))
  , gift_count_(gift_count_)
{}

const std::int32_t giftCollection::ID;

void giftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftCollection");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_field("gift_count", gift_count_);
    s.store_class_end();
  }
}

giftForResaleOrderPrice::giftForResaleOrderPrice() {
}

const std::int32_t giftForResaleOrderPrice::ID;

void giftForResaleOrderPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftForResaleOrderPrice");
    s.store_class_end();
  }
}

giftForResaleOrderPriceChangeDate::giftForResaleOrderPriceChangeDate() {
}

const std::int32_t giftForResaleOrderPriceChangeDate::ID;

void giftForResaleOrderPriceChangeDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftForResaleOrderPriceChangeDate");
    s.store_class_end();
  }
}

giftForResaleOrderNumber::giftForResaleOrderNumber() {
}

const std::int32_t giftForResaleOrderNumber::ID;

void giftForResaleOrderNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftForResaleOrderNumber");
    s.store_class_end();
  }
}

giftPurchaseLimits::giftPurchaseLimits()
  : total_count_()
  , remaining_count_()
{}

giftPurchaseLimits::giftPurchaseLimits(int32 total_count_, int32 remaining_count_)
  : total_count_(total_count_)
  , remaining_count_(remaining_count_)
{}

const std::int32_t giftPurchaseLimits::ID;

void giftPurchaseLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftPurchaseLimits");
    s.store_field("total_count", total_count_);
    s.store_field("remaining_count", remaining_count_);
    s.store_class_end();
  }
}

giftSettings::giftSettings()
  : show_gift_button_()
  , accepted_gift_types_()
{}

giftSettings::giftSettings(bool show_gift_button_, object_ptr<acceptedGiftTypes> &&accepted_gift_types_)
  : show_gift_button_(show_gift_button_)
  , accepted_gift_types_(std::move(accepted_gift_types_))
{}

const std::int32_t giftSettings::ID;

void giftSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftSettings");
    s.store_field("show_gift_button", show_gift_button_);
    s.store_object_field("accepted_gift_types", static_cast<const BaseObject *>(accepted_gift_types_.get()));
    s.store_class_end();
  }
}

giftUpgradePreview::giftUpgradePreview()
  : models_()
  , symbols_()
  , backdrops_()
  , prices_()
  , next_prices_()
{}

giftUpgradePreview::giftUpgradePreview(array<object_ptr<upgradedGiftModel>> &&models_, array<object_ptr<upgradedGiftSymbol>> &&symbols_, array<object_ptr<upgradedGiftBackdrop>> &&backdrops_, array<object_ptr<giftUpgradePrice>> &&prices_, array<object_ptr<giftUpgradePrice>> &&next_prices_)
  : models_(std::move(models_))
  , symbols_(std::move(symbols_))
  , backdrops_(std::move(backdrops_))
  , prices_(std::move(prices_))
  , next_prices_(std::move(next_prices_))
{}

const std::int32_t giftUpgradePreview::ID;

void giftUpgradePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftUpgradePreview");
    { s.store_vector_begin("models", models_.size()); for (const auto &_value : models_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("symbols", symbols_.size()); for (const auto &_value : symbols_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("backdrops", backdrops_.size()); for (const auto &_value : backdrops_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("prices", prices_.size()); for (const auto &_value : prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("next_prices", next_prices_.size()); for (const auto &_value : next_prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

giftsForResale::giftsForResale()
  : total_count_()
  , gifts_()
  , models_()
  , symbols_()
  , backdrops_()
  , next_offset_()
{}

giftsForResale::giftsForResale(int32 total_count_, array<object_ptr<giftForResale>> &&gifts_, array<object_ptr<upgradedGiftModelCount>> &&models_, array<object_ptr<upgradedGiftSymbolCount>> &&symbols_, array<object_ptr<upgradedGiftBackdropCount>> &&backdrops_, string const &next_offset_)
  : total_count_(total_count_)
  , gifts_(std::move(gifts_))
  , models_(std::move(models_))
  , symbols_(std::move(symbols_))
  , backdrops_(std::move(backdrops_))
  , next_offset_(next_offset_)
{}

const std::int32_t giftsForResale::ID;

void giftsForResale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftsForResale");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("models", models_.size()); for (const auto &_value : models_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("symbols", symbols_.size()); for (const auto &_value : symbols_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("backdrops", backdrops_.size()); for (const auto &_value : backdrops_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

giveawayParticipantStatusEligible::giveawayParticipantStatusEligible() {
}

const std::int32_t giveawayParticipantStatusEligible::ID;

void giveawayParticipantStatusEligible::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParticipantStatusEligible");
    s.store_class_end();
  }
}

giveawayParticipantStatusParticipating::giveawayParticipantStatusParticipating() {
}

const std::int32_t giveawayParticipantStatusParticipating::ID;

void giveawayParticipantStatusParticipating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParticipantStatusParticipating");
    s.store_class_end();
  }
}

giveawayParticipantStatusAlreadyWasMember::giveawayParticipantStatusAlreadyWasMember()
  : joined_chat_date_()
{}

giveawayParticipantStatusAlreadyWasMember::giveawayParticipantStatusAlreadyWasMember(int32 joined_chat_date_)
  : joined_chat_date_(joined_chat_date_)
{}

const std::int32_t giveawayParticipantStatusAlreadyWasMember::ID;

void giveawayParticipantStatusAlreadyWasMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParticipantStatusAlreadyWasMember");
    s.store_field("joined_chat_date", joined_chat_date_);
    s.store_class_end();
  }
}

giveawayParticipantStatusAdministrator::giveawayParticipantStatusAdministrator()
  : chat_id_()
{}

giveawayParticipantStatusAdministrator::giveawayParticipantStatusAdministrator(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t giveawayParticipantStatusAdministrator::ID;

void giveawayParticipantStatusAdministrator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParticipantStatusAdministrator");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

giveawayParticipantStatusDisallowedCountry::giveawayParticipantStatusDisallowedCountry()
  : user_country_code_()
{}

giveawayParticipantStatusDisallowedCountry::giveawayParticipantStatusDisallowedCountry(string const &user_country_code_)
  : user_country_code_(user_country_code_)
{}

const std::int32_t giveawayParticipantStatusDisallowedCountry::ID;

void giveawayParticipantStatusDisallowedCountry::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParticipantStatusDisallowedCountry");
    s.store_field("user_country_code", user_country_code_);
    s.store_class_end();
  }
}

httpUrl::httpUrl()
  : url_()
{}

httpUrl::httpUrl(string const &url_)
  : url_(url_)
{}

const std::int32_t httpUrl::ID;

void httpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "httpUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

importedContacts::importedContacts()
  : user_ids_()
  , importer_count_()
{}

importedContacts::importedContacts(array<int53> &&user_ids_, array<int32> &&importer_count_)
  : user_ids_(std::move(user_ids_))
  , importer_count_(std::move(importer_count_))
{}

const std::int32_t importedContacts::ID;

void importedContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importedContacts");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("importer_count", importer_count_.size()); for (const auto &_value : importer_count_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inlineButton::inlineButton()
  : text_()
  , style_()
  , type_()
{}

inlineButton::inlineButton(object_ptr<RichText> &&text_, object_ptr<ButtonStyle> &&style_, object_ptr<InlineKeyboardButtonType> &&type_)
  : text_(std::move(text_))
  , style_(std::move(style_))
  , type_(std::move(type_))
{}

const std::int32_t inlineButton::ID;

void inlineButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineButton");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("style", static_cast<const BaseObject *>(style_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

inlineQueryResultsButtonTypeStartBot::inlineQueryResultsButtonTypeStartBot()
  : parameter_()
{}

inlineQueryResultsButtonTypeStartBot::inlineQueryResultsButtonTypeStartBot(string const &parameter_)
  : parameter_(parameter_)
{}

const std::int32_t inlineQueryResultsButtonTypeStartBot::ID;

void inlineQueryResultsButtonTypeStartBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultsButtonTypeStartBot");
    s.store_field("parameter", parameter_);
    s.store_class_end();
  }
}

inlineQueryResultsButtonTypeWebApp::inlineQueryResultsButtonTypeWebApp()
  : url_()
{}

inlineQueryResultsButtonTypeWebApp::inlineQueryResultsButtonTypeWebApp(string const &url_)
  : url_(url_)
{}

const std::int32_t inlineQueryResultsButtonTypeWebApp::ID;

void inlineQueryResultsButtonTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultsButtonTypeWebApp");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inputCredentialsSaved::inputCredentialsSaved()
  : saved_credentials_id_()
{}

inputCredentialsSaved::inputCredentialsSaved(string const &saved_credentials_id_)
  : saved_credentials_id_(saved_credentials_id_)
{}

const std::int32_t inputCredentialsSaved::ID;

void inputCredentialsSaved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsSaved");
    s.store_field("saved_credentials_id", saved_credentials_id_);
    s.store_class_end();
  }
}

inputCredentialsNew::inputCredentialsNew()
  : data_()
  , allow_save_()
{}

inputCredentialsNew::inputCredentialsNew(string const &data_, bool allow_save_)
  : data_(data_)
  , allow_save_(allow_save_)
{}

const std::int32_t inputCredentialsNew::ID;

void inputCredentialsNew::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsNew");
    s.store_field("data", data_);
    s.store_field("allow_save", allow_save_);
    s.store_class_end();
  }
}

inputCredentialsApplePay::inputCredentialsApplePay()
  : data_()
{}

inputCredentialsApplePay::inputCredentialsApplePay(string const &data_)
  : data_(data_)
{}

const std::int32_t inputCredentialsApplePay::ID;

void inputCredentialsApplePay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsApplePay");
    s.store_field("data", data_);
    s.store_class_end();
  }
}

inputCredentialsGooglePay::inputCredentialsGooglePay()
  : data_()
{}

inputCredentialsGooglePay::inputCredentialsGooglePay(string const &data_)
  : data_(data_)
{}

const std::int32_t inputCredentialsGooglePay::ID;

void inputCredentialsGooglePay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsGooglePay");
    s.store_field("data", data_);
    s.store_class_end();
  }
}

inputTonWalletCardSticker::inputTonWalletCardSticker()
  : position_()
  , nft_address_()
{}

inputTonWalletCardSticker::inputTonWalletCardSticker(object_ptr<areaPosition> &&position_, string const &nft_address_)
  : position_(std::move(position_))
  , nft_address_(nft_address_)
{}

const std::int32_t inputTonWalletCardSticker::ID;

void inputTonWalletCardSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputTonWalletCardSticker");
    s.store_object_field("position", static_cast<const BaseObject *>(position_.get()));
    s.store_field("nft_address", nft_address_);
    s.store_class_end();
  }
}

invoice::invoice()
  : currency_()
  , price_parts_()
  , subscription_period_()
  , max_tip_amount_()
  , suggested_tip_amounts_()
  , recurring_payment_terms_of_service_url_()
  , terms_of_service_url_()
  , is_test_()
  , need_name_()
  , need_phone_number_()
  , need_email_address_()
  , need_shipping_address_()
  , send_phone_number_to_provider_()
  , send_email_address_to_provider_()
  , is_flexible_()
{}

invoice::invoice(string const &currency_, array<object_ptr<labeledPricePart>> &&price_parts_, int32 subscription_period_, int53 max_tip_amount_, array<int53> &&suggested_tip_amounts_, string const &recurring_payment_terms_of_service_url_, string const &terms_of_service_url_, bool is_test_, bool need_name_, bool need_phone_number_, bool need_email_address_, bool need_shipping_address_, bool send_phone_number_to_provider_, bool send_email_address_to_provider_, bool is_flexible_)
  : currency_(currency_)
  , price_parts_(std::move(price_parts_))
  , subscription_period_(subscription_period_)
  , max_tip_amount_(max_tip_amount_)
  , suggested_tip_amounts_(std::move(suggested_tip_amounts_))
  , recurring_payment_terms_of_service_url_(recurring_payment_terms_of_service_url_)
  , terms_of_service_url_(terms_of_service_url_)
  , is_test_(is_test_)
  , need_name_(need_name_)
  , need_phone_number_(need_phone_number_)
  , need_email_address_(need_email_address_)
  , need_shipping_address_(need_shipping_address_)
  , send_phone_number_to_provider_(send_phone_number_to_provider_)
  , send_email_address_to_provider_(send_email_address_to_provider_)
  , is_flexible_(is_flexible_)
{}

const std::int32_t invoice::ID;

void invoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invoice");
    s.store_field("currency", currency_);
    { s.store_vector_begin("price_parts", price_parts_.size()); for (const auto &_value : price_parts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("subscription_period", subscription_period_);
    s.store_field("max_tip_amount", max_tip_amount_);
    { s.store_vector_begin("suggested_tip_amounts", suggested_tip_amounts_.size()); for (const auto &_value : suggested_tip_amounts_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("recurring_payment_terms_of_service_url", recurring_payment_terms_of_service_url_);
    s.store_field("terms_of_service_url", terms_of_service_url_);
    s.store_field("is_test", is_test_);
    s.store_field("need_name", need_name_);
    s.store_field("need_phone_number", need_phone_number_);
    s.store_field("need_email_address", need_email_address_);
    s.store_field("need_shipping_address", need_shipping_address_);
    s.store_field("send_phone_number_to_provider", send_phone_number_to_provider_);
    s.store_field("send_email_address_to_provider", send_email_address_to_provider_);
    s.store_field("is_flexible", is_flexible_);
    s.store_class_end();
  }
}

linkPreviewOptions::linkPreviewOptions()
  : is_disabled_()
  , url_()
  , force_small_media_()
  , force_large_media_()
  , show_above_text_()
{}

linkPreviewOptions::linkPreviewOptions(bool is_disabled_, string const &url_, bool force_small_media_, bool force_large_media_, bool show_above_text_)
  : is_disabled_(is_disabled_)
  , url_(url_)
  , force_small_media_(force_small_media_)
  , force_large_media_(force_large_media_)
  , show_above_text_(show_above_text_)
{}

const std::int32_t linkPreviewOptions::ID;

void linkPreviewOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewOptions");
    s.store_field("is_disabled", is_disabled_);
    s.store_field("url", url_);
    s.store_field("force_small_media", force_small_media_);
    s.store_field("force_large_media", force_large_media_);
    s.store_field("show_above_text", show_above_text_);
    s.store_class_end();
  }
}

localizationTargetInfo::localizationTargetInfo()
  : language_packs_()
{}

localizationTargetInfo::localizationTargetInfo(array<object_ptr<languagePackInfo>> &&language_packs_)
  : language_packs_(std::move(language_packs_))
{}

const std::int32_t localizationTargetInfo::ID;

void localizationTargetInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "localizationTargetInfo");
    { s.store_vector_begin("language_packs", language_packs_.size()); for (const auto &_value : language_packs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

logTags::logTags()
  : tags_()
{}

logTags::logTags(array<string> &&tags_)
  : tags_(std::move(tags_))
{}

const std::int32_t logTags::ID;

void logTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logTags");
    { s.store_vector_begin("tags", tags_.size()); for (const auto &_value : tags_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageInteractionInfo::messageInteractionInfo()
  : view_count_()
  , forward_count_()
  , reply_info_()
  , reactions_()
{}

messageInteractionInfo::messageInteractionInfo(int32 view_count_, int32 forward_count_, object_ptr<messageReplyInfo> &&reply_info_, object_ptr<messageReactions> &&reactions_)
  : view_count_(view_count_)
  , forward_count_(forward_count_)
  , reply_info_(std::move(reply_info_))
  , reactions_(std::move(reactions_))
{}

const std::int32_t messageInteractionInfo::ID;

void messageInteractionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageInteractionInfo");
    s.store_field("view_count", view_count_);
    s.store_field("forward_count", forward_count_);
    s.store_object_field("reply_info", static_cast<const BaseObject *>(reply_info_.get()));
    s.store_object_field("reactions", static_cast<const BaseObject *>(reactions_.get()));
    s.store_class_end();
  }
}

messageOriginUser::messageOriginUser()
  : sender_user_id_()
{}

messageOriginUser::messageOriginUser(int53 sender_user_id_)
  : sender_user_id_(sender_user_id_)
{}

const std::int32_t messageOriginUser::ID;

void messageOriginUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageOriginUser");
    s.store_field("sender_user_id", sender_user_id_);
    s.store_class_end();
  }
}

messageOriginHiddenUser::messageOriginHiddenUser()
  : sender_name_()
{}

messageOriginHiddenUser::messageOriginHiddenUser(string const &sender_name_)
  : sender_name_(sender_name_)
{}

const std::int32_t messageOriginHiddenUser::ID;

void messageOriginHiddenUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageOriginHiddenUser");
    s.store_field("sender_name", sender_name_);
    s.store_class_end();
  }
}

messageOriginChat::messageOriginChat()
  : sender_chat_id_()
  , author_signature_()
{}

messageOriginChat::messageOriginChat(int53 sender_chat_id_, string const &author_signature_)
  : sender_chat_id_(sender_chat_id_)
  , author_signature_(author_signature_)
{}

const std::int32_t messageOriginChat::ID;

void messageOriginChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageOriginChat");
    s.store_field("sender_chat_id", sender_chat_id_);
    s.store_field("author_signature", author_signature_);
    s.store_class_end();
  }
}

messageOriginChannel::messageOriginChannel()
  : chat_id_()
  , message_id_()
  , author_signature_()
{}

messageOriginChannel::messageOriginChannel(int53 chat_id_, int53 message_id_, string const &author_signature_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , author_signature_(author_signature_)
{}

const std::int32_t messageOriginChannel::ID;

void messageOriginChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageOriginChannel");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("author_signature", author_signature_);
    s.store_class_end();
  }
}

messagePositions::messagePositions()
  : total_count_()
  , positions_()
{}

messagePositions::messagePositions(int32 total_count_, array<object_ptr<messagePosition>> &&positions_)
  : total_count_(total_count_)
  , positions_(std::move(positions_))
{}

const std::int32_t messagePositions::ID;

void messagePositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePositions");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageReactions::messageReactions()
  : reactions_()
  , are_tags_()
  , paid_reactors_()
  , can_get_added_reactions_()
{}

messageReactions::messageReactions(array<object_ptr<messageReaction>> &&reactions_, bool are_tags_, array<object_ptr<paidReactor>> &&paid_reactors_, bool can_get_added_reactions_)
  : reactions_(std::move(reactions_))
  , are_tags_(are_tags_)
  , paid_reactors_(std::move(paid_reactors_))
  , can_get_added_reactions_(can_get_added_reactions_)
{}

const std::int32_t messageReactions::ID;

void messageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReactions");
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("are_tags", are_tags_);
    { s.store_vector_begin("paid_reactors", paid_reactors_.size()); for (const auto &_value : paid_reactors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("can_get_added_reactions", can_get_added_reactions_);
    s.store_class_end();
  }
}

messageViewer::messageViewer()
  : user_id_()
  , view_date_()
{}

messageViewer::messageViewer(int53 user_id_, int32 view_date_)
  : user_id_(user_id_)
  , view_date_(view_date_)
{}

const std::int32_t messageViewer::ID;

void messageViewer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageViewer");
    s.store_field("user_id", user_id_);
    s.store_field("view_date", view_date_);
    s.store_class_end();
  }
}

paidMediaPreview::paidMediaPreview()
  : width_()
  , height_()
  , duration_()
  , minithumbnail_()
{}

paidMediaPreview::paidMediaPreview(int32 width_, int32 height_, int32 duration_, object_ptr<minithumbnail> &&minithumbnail_)
  : width_(width_)
  , height_(height_)
  , duration_(duration_)
  , minithumbnail_(std::move(minithumbnail_))
{}

const std::int32_t paidMediaPreview::ID;

void paidMediaPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidMediaPreview");
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("duration", duration_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_class_end();
  }
}

paidMediaPhoto::paidMediaPhoto()
  : photo_()
  , video_()
{}

paidMediaPhoto::paidMediaPhoto(object_ptr<photo> &&photo_, object_ptr<video> &&video_)
  : photo_(std::move(photo_))
  , video_(std::move(video_))
{}

const std::int32_t paidMediaPhoto::ID;

void paidMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidMediaPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

paidMediaVideo::paidMediaVideo()
  : video_()
  , cover_()
  , start_timestamp_()
{}

paidMediaVideo::paidMediaVideo(object_ptr<video> &&video_, object_ptr<photo> &&cover_, int32 start_timestamp_)
  : video_(std::move(video_))
  , cover_(std::move(cover_))
  , start_timestamp_(start_timestamp_)
{}

const std::int32_t paidMediaVideo::ID;

void paidMediaVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidMediaVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_field("start_timestamp", start_timestamp_);
    s.store_class_end();
  }
}

paidMediaUnsupported::paidMediaUnsupported() {
}

const std::int32_t paidMediaUnsupported::ID;

void paidMediaUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidMediaUnsupported");
    s.store_class_end();
  }
}

paymentReceipt::paymentReceipt()
  : product_info_()
  , date_()
  , seller_bot_user_id_()
  , type_()
{}

paymentReceipt::paymentReceipt(object_ptr<productInfo> &&product_info_, int32 date_, int53 seller_bot_user_id_, object_ptr<PaymentReceiptType> &&type_)
  : product_info_(std::move(product_info_))
  , date_(date_)
  , seller_bot_user_id_(seller_bot_user_id_)
  , type_(std::move(type_))
{}

const std::int32_t paymentReceipt::ID;

void paymentReceipt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentReceipt");
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_field("date", date_);
    s.store_field("seller_bot_user_id", seller_bot_user_id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

personalDetails::personalDetails()
  : first_name_()
  , middle_name_()
  , last_name_()
  , native_first_name_()
  , native_middle_name_()
  , native_last_name_()
  , birthdate_()
  , gender_()
  , country_code_()
  , residence_country_code_()
{}

personalDetails::personalDetails(string const &first_name_, string const &middle_name_, string const &last_name_, string const &native_first_name_, string const &native_middle_name_, string const &native_last_name_, object_ptr<date> &&birthdate_, string const &gender_, string const &country_code_, string const &residence_country_code_)
  : first_name_(first_name_)
  , middle_name_(middle_name_)
  , last_name_(last_name_)
  , native_first_name_(native_first_name_)
  , native_middle_name_(native_middle_name_)
  , native_last_name_(native_last_name_)
  , birthdate_(std::move(birthdate_))
  , gender_(gender_)
  , country_code_(country_code_)
  , residence_country_code_(residence_country_code_)
{}

const std::int32_t personalDetails::ID;

void personalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "personalDetails");
    s.store_field("first_name", first_name_);
    s.store_field("middle_name", middle_name_);
    s.store_field("last_name", last_name_);
    s.store_field("native_first_name", native_first_name_);
    s.store_field("native_middle_name", native_middle_name_);
    s.store_field("native_last_name", native_last_name_);
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_field("gender", gender_);
    s.store_field("country_code", country_code_);
    s.store_field("residence_country_code", residence_country_code_);
    s.store_class_end();
  }
}

premiumFeaturePromotionAnimation::premiumFeaturePromotionAnimation()
  : feature_()
  , animation_()
{}

premiumFeaturePromotionAnimation::premiumFeaturePromotionAnimation(object_ptr<PremiumFeature> &&feature_, object_ptr<animation> &&animation_)
  : feature_(std::move(feature_))
  , animation_(std::move(animation_))
{}

const std::int32_t premiumFeaturePromotionAnimation::ID;

void premiumFeaturePromotionAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeaturePromotionAnimation");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

profileShareThemeBackdrop::profileShareThemeBackdrop()
  : id_()
  , name_()
  , colors_()
{}

profileShareThemeBackdrop::profileShareThemeBackdrop(int32 id_, string const &name_, object_ptr<upgradedGiftBackdropColors> &&colors_)
  : id_(id_)
  , name_(name_)
  , colors_(std::move(colors_))
{}

const std::int32_t profileShareThemeBackdrop::ID;

void profileShareThemeBackdrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileShareThemeBackdrop");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_object_field("colors", static_cast<const BaseObject *>(colors_.get()));
    s.store_class_end();
  }
}

publicForwards::publicForwards()
  : total_count_()
  , forwards_()
  , next_offset_()
{}

publicForwards::publicForwards(int32 total_count_, array<object_ptr<PublicForward>> &&forwards_, string const &next_offset_)
  : total_count_(total_count_)
  , forwards_(std::move(forwards_))
  , next_offset_(next_offset_)
{}

const std::int32_t publicForwards::ID;

void publicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicForwards");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("forwards", forwards_.size()); for (const auto &_value : forwards_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

quickReplyShortcut::quickReplyShortcut()
  : id_()
  , name_()
  , first_message_()
  , message_count_()
{}

quickReplyShortcut::quickReplyShortcut(int32 id_, string const &name_, object_ptr<quickReplyMessage> &&first_message_, int32 message_count_)
  : id_(id_)
  , name_(name_)
  , first_message_(std::move(first_message_))
  , message_count_(message_count_)
{}

const std::int32_t quickReplyShortcut::ID;

void quickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "quickReplyShortcut");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_object_field("first_message", static_cast<const BaseObject *>(first_message_.get()));
    s.store_field("message_count", message_count_);
    s.store_class_end();
  }
}

reactionTypeEmoji::reactionTypeEmoji()
  : emoji_()
{}

reactionTypeEmoji::reactionTypeEmoji(string const &emoji_)
  : emoji_(emoji_)
{}

const std::int32_t reactionTypeEmoji::ID;

void reactionTypeEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionTypeEmoji");
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

reactionTypeCustomEmoji::reactionTypeCustomEmoji()
  : custom_emoji_id_()
{}

reactionTypeCustomEmoji::reactionTypeCustomEmoji(int64 custom_emoji_id_)
  : custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t reactionTypeCustomEmoji::ID;

void reactionTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionTypeCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

reactionTypePaid::reactionTypePaid() {
}

const std::int32_t reactionTypePaid::ID;

void reactionTypePaid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionTypePaid");
    s.store_class_end();
  }
}

recoveryEmailAddress::recoveryEmailAddress()
  : recovery_email_address_()
{}

recoveryEmailAddress::recoveryEmailAddress(string const &recovery_email_address_)
  : recovery_email_address_(recovery_email_address_)
{}

const std::int32_t recoveryEmailAddress::ID;

void recoveryEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recoveryEmailAddress");
    s.store_field("recovery_email_address", recovery_email_address_);
    s.store_class_end();
  }
}

savedMessagesTag::savedMessagesTag()
  : tag_()
  , label_()
  , count_()
{}

savedMessagesTag::savedMessagesTag(object_ptr<ReactionType> &&tag_, string const &label_, int32 count_)
  : tag_(std::move(tag_))
  , label_(label_)
  , count_(count_)
{}

const std::int32_t savedMessagesTag::ID;

void savedMessagesTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTag");
    s.store_object_field("tag", static_cast<const BaseObject *>(tag_.get()));
    s.store_field("label", label_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

savedMessagesTopicTypeMyNotes::savedMessagesTopicTypeMyNotes() {
}

const std::int32_t savedMessagesTopicTypeMyNotes::ID;

void savedMessagesTopicTypeMyNotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTopicTypeMyNotes");
    s.store_class_end();
  }
}

savedMessagesTopicTypeAuthorHidden::savedMessagesTopicTypeAuthorHidden() {
}

const std::int32_t savedMessagesTopicTypeAuthorHidden::ID;

void savedMessagesTopicTypeAuthorHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTopicTypeAuthorHidden");
    s.store_class_end();
  }
}

savedMessagesTopicTypeSavedFromChat::savedMessagesTopicTypeSavedFromChat()
  : chat_id_()
{}

savedMessagesTopicTypeSavedFromChat::savedMessagesTopicTypeSavedFromChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t savedMessagesTopicTypeSavedFromChat::ID;

void savedMessagesTopicTypeSavedFromChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTopicTypeSavedFromChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

scopeAutosaveSettings::scopeAutosaveSettings()
  : autosave_photos_()
  , autosave_videos_()
  , max_video_file_size_()
{}

scopeAutosaveSettings::scopeAutosaveSettings(bool autosave_photos_, bool autosave_videos_, int53 max_video_file_size_)
  : autosave_photos_(autosave_photos_)
  , autosave_videos_(autosave_videos_)
  , max_video_file_size_(max_video_file_size_)
{}

const std::int32_t scopeAutosaveSettings::ID;

void scopeAutosaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "scopeAutosaveSettings");
    s.store_field("autosave_photos", autosave_photos_);
    s.store_field("autosave_videos", autosave_videos_);
    s.store_field("max_video_file_size", max_video_file_size_);
    s.store_class_end();
  }
}

speechRecognitionModels::speechRecognitionModels()
  : models_()
  , language_detection_model_()
  , voice_activity_detection_model_()
{}

speechRecognitionModels::speechRecognitionModels(array<object_ptr<speechRecognitionModel>> &&models_, object_ptr<document> &&language_detection_model_, object_ptr<document> &&voice_activity_detection_model_)
  : models_(std::move(models_))
  , language_detection_model_(std::move(language_detection_model_))
  , voice_activity_detection_model_(std::move(voice_activity_detection_model_))
{}

const std::int32_t speechRecognitionModels::ID;

void speechRecognitionModels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "speechRecognitionModels");
    { s.store_vector_begin("models", models_.size()); for (const auto &_value : models_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("language_detection_model", static_cast<const BaseObject *>(language_detection_model_.get()));
    s.store_object_field("voice_activity_detection_model", static_cast<const BaseObject *>(voice_activity_detection_model_.get()));
    s.store_class_end();
  }
}

sponsoredMessage::sponsoredMessage()
  : message_id_()
  , is_recommended_()
  , can_be_reported_()
  , content_()
  , sponsor_()
  , title_()
  , button_text_()
  , accent_color_id_()
  , background_custom_emoji_id_()
  , additional_info_()
{}

sponsoredMessage::sponsoredMessage(int53 message_id_, bool is_recommended_, bool can_be_reported_, object_ptr<MessageContent> &&content_, object_ptr<advertisementSponsor> &&sponsor_, string const &title_, string const &button_text_, int32 accent_color_id_, int64 background_custom_emoji_id_, string const &additional_info_)
  : message_id_(message_id_)
  , is_recommended_(is_recommended_)
  , can_be_reported_(can_be_reported_)
  , content_(std::move(content_))
  , sponsor_(std::move(sponsor_))
  , title_(title_)
  , button_text_(button_text_)
  , accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
  , additional_info_(additional_info_)
{}

const std::int32_t sponsoredMessage::ID;

void sponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredMessage");
    s.store_field("message_id", message_id_);
    s.store_field("is_recommended", is_recommended_);
    s.store_field("can_be_reported", can_be_reported_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("sponsor", static_cast<const BaseObject *>(sponsor_.get()));
    s.store_field("title", title_);
    s.store_field("button_text", button_text_);
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_field("additional_info", additional_info_);
    s.store_class_end();
  }
}

startLiveStoryResultOk::startLiveStoryResultOk()
  : story_()
{}

startLiveStoryResultOk::startLiveStoryResultOk(object_ptr<story> &&story_)
  : story_(std::move(story_))
{}

const std::int32_t startLiveStoryResultOk::ID;

void startLiveStoryResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startLiveStoryResultOk");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

startLiveStoryResultFail::startLiveStoryResultFail()
  : error_type_()
{}

startLiveStoryResultFail::startLiveStoryResultFail(object_ptr<CanPostStoryResult> &&error_type_)
  : error_type_(std::move(error_type_))
{}

const std::int32_t startLiveStoryResultFail::ID;

void startLiveStoryResultFail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startLiveStoryResultFail");
    s.store_object_field("error_type", static_cast<const BaseObject *>(error_type_.get()));
    s.store_class_end();
  }
}

storePaymentPurposePremiumSubscription::storePaymentPurposePremiumSubscription()
  : is_restore_()
  , is_upgrade_()
{}

storePaymentPurposePremiumSubscription::storePaymentPurposePremiumSubscription(bool is_restore_, bool is_upgrade_)
  : is_restore_(is_restore_)
  , is_upgrade_(is_upgrade_)
{}

const std::int32_t storePaymentPurposePremiumSubscription::ID;

void storePaymentPurposePremiumSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposePremiumSubscription");
    s.store_field("is_restore", is_restore_);
    s.store_field("is_upgrade", is_upgrade_);
    s.store_class_end();
  }
}

storePaymentPurposePremiumGift::storePaymentPurposePremiumGift()
  : currency_()
  , amount_()
  , user_id_()
  , text_()
{}

storePaymentPurposePremiumGift::storePaymentPurposePremiumGift(string const &currency_, int53 amount_, int53 user_id_, object_ptr<formattedText> &&text_)
  : currency_(currency_)
  , amount_(amount_)
  , user_id_(user_id_)
  , text_(std::move(text_))
{}

const std::int32_t storePaymentPurposePremiumGift::ID;

void storePaymentPurposePremiumGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposePremiumGift");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("user_id", user_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

storePaymentPurposePremiumGiftCodes::storePaymentPurposePremiumGiftCodes()
  : boosted_chat_id_()
  , currency_()
  , amount_()
  , user_ids_()
  , text_()
{}

storePaymentPurposePremiumGiftCodes::storePaymentPurposePremiumGiftCodes(int53 boosted_chat_id_, string const &currency_, int53 amount_, array<int53> &&user_ids_, object_ptr<formattedText> &&text_)
  : boosted_chat_id_(boosted_chat_id_)
  , currency_(currency_)
  , amount_(amount_)
  , user_ids_(std::move(user_ids_))
  , text_(std::move(text_))
{}

const std::int32_t storePaymentPurposePremiumGiftCodes::ID;

void storePaymentPurposePremiumGiftCodes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposePremiumGiftCodes");
    s.store_field("boosted_chat_id", boosted_chat_id_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

storePaymentPurposePremiumGiveaway::storePaymentPurposePremiumGiveaway()
  : parameters_()
  , currency_()
  , amount_()
{}

storePaymentPurposePremiumGiveaway::storePaymentPurposePremiumGiveaway(object_ptr<giveawayParameters> &&parameters_, string const &currency_, int53 amount_)
  : parameters_(std::move(parameters_))
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t storePaymentPurposePremiumGiveaway::ID;

void storePaymentPurposePremiumGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposePremiumGiveaway");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

storePaymentPurposeStarGiveaway::storePaymentPurposeStarGiveaway()
  : parameters_()
  , currency_()
  , amount_()
  , winner_count_()
  , star_count_()
{}

storePaymentPurposeStarGiveaway::storePaymentPurposeStarGiveaway(object_ptr<giveawayParameters> &&parameters_, string const &currency_, int53 amount_, int32 winner_count_, int53 star_count_)
  : parameters_(std::move(parameters_))
  , currency_(currency_)
  , amount_(amount_)
  , winner_count_(winner_count_)
  , star_count_(star_count_)
{}

const std::int32_t storePaymentPurposeStarGiveaway::ID;

void storePaymentPurposeStarGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposeStarGiveaway");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("winner_count", winner_count_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

storePaymentPurposeStars::storePaymentPurposeStars()
  : currency_()
  , amount_()
  , star_count_()
  , chat_id_()
{}

storePaymentPurposeStars::storePaymentPurposeStars(string const &currency_, int53 amount_, int53 star_count_, int53 chat_id_)
  : currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
  , chat_id_(chat_id_)
{}

const std::int32_t storePaymentPurposeStars::ID;

void storePaymentPurposeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposeStars");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

storePaymentPurposeGiftedStars::storePaymentPurposeGiftedStars()
  : user_id_()
  , currency_()
  , amount_()
  , star_count_()
{}

storePaymentPurposeGiftedStars::storePaymentPurposeGiftedStars(int53 user_id_, string const &currency_, int53 amount_, int53 star_count_)
  : user_id_(user_id_)
  , currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
{}

const std::int32_t storePaymentPurposeGiftedStars::ID;

void storePaymentPurposeGiftedStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposeGiftedStars");
    s.store_field("user_id", user_id_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

storyAreaTypeLocation::storyAreaTypeLocation()
  : location_()
  , address_()
{}

storyAreaTypeLocation::storyAreaTypeLocation(object_ptr<location> &&location_, object_ptr<locationAddress> &&address_)
  : location_(std::move(location_))
  , address_(std::move(address_))
{}

const std::int32_t storyAreaTypeLocation::ID;

void storyAreaTypeLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_class_end();
  }
}

storyAreaTypeVenue::storyAreaTypeVenue()
  : venue_()
{}

storyAreaTypeVenue::storyAreaTypeVenue(object_ptr<venue> &&venue_)
  : venue_(std::move(venue_))
{}

const std::int32_t storyAreaTypeVenue::ID;

void storyAreaTypeVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeVenue");
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_class_end();
  }
}

storyAreaTypeSuggestedReaction::storyAreaTypeSuggestedReaction()
  : reaction_type_()
  , total_count_()
  , is_dark_()
  , is_flipped_()
{}

storyAreaTypeSuggestedReaction::storyAreaTypeSuggestedReaction(object_ptr<ReactionType> &&reaction_type_, int32 total_count_, bool is_dark_, bool is_flipped_)
  : reaction_type_(std::move(reaction_type_))
  , total_count_(total_count_)
  , is_dark_(is_dark_)
  , is_flipped_(is_flipped_)
{}

const std::int32_t storyAreaTypeSuggestedReaction::ID;

void storyAreaTypeSuggestedReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeSuggestedReaction");
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("total_count", total_count_);
    s.store_field("is_dark", is_dark_);
    s.store_field("is_flipped", is_flipped_);
    s.store_class_end();
  }
}

storyAreaTypeMessage::storyAreaTypeMessage()
  : chat_id_()
  , message_id_()
{}

storyAreaTypeMessage::storyAreaTypeMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t storyAreaTypeMessage::ID;

void storyAreaTypeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

storyAreaTypeLink::storyAreaTypeLink()
  : url_()
{}

storyAreaTypeLink::storyAreaTypeLink(string const &url_)
  : url_(url_)
{}

const std::int32_t storyAreaTypeLink::ID;

void storyAreaTypeLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeLink");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

storyAreaTypeWeather::storyAreaTypeWeather()
  : temperature_()
  , emoji_()
  , background_color_()
{}

storyAreaTypeWeather::storyAreaTypeWeather(double temperature_, string const &emoji_, int32 background_color_)
  : temperature_(temperature_)
  , emoji_(emoji_)
  , background_color_(background_color_)
{}

const std::int32_t storyAreaTypeWeather::ID;

void storyAreaTypeWeather::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeWeather");
    s.store_field("temperature", temperature_);
    s.store_field("emoji", emoji_);
    s.store_field("background_color", background_color_);
    s.store_class_end();
  }
}

storyAreaTypeUpgradedGift::storyAreaTypeUpgradedGift()
  : gift_name_()
{}

storyAreaTypeUpgradedGift::storyAreaTypeUpgradedGift(string const &gift_name_)
  : gift_name_(gift_name_)
{}

const std::int32_t storyAreaTypeUpgradedGift::ID;

void storyAreaTypeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeUpgradedGift");
    s.store_field("gift_name", gift_name_);
    s.store_class_end();
  }
}

storyInfo::storyInfo()
  : story_id_()
  , date_()
  , is_for_close_friends_()
  , is_live_()
{}

storyInfo::storyInfo(int32 story_id_, int32 date_, bool is_for_close_friends_, bool is_live_)
  : story_id_(story_id_)
  , date_(date_)
  , is_for_close_friends_(is_for_close_friends_)
  , is_live_(is_live_)
{}

const std::int32_t storyInfo::ID;

void storyInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInfo");
    s.store_field("story_id", story_id_);
    s.store_field("date", date_);
    s.store_field("is_for_close_friends", is_for_close_friends_);
    s.store_field("is_live", is_live_);
    s.store_class_end();
  }
}

suggestedPostPriceStar::suggestedPostPriceStar()
  : star_count_()
{}

suggestedPostPriceStar::suggestedPostPriceStar(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t suggestedPostPriceStar::ID;

void suggestedPostPriceStar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostPriceStar");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

suggestedPostPriceGram::suggestedPostPriceGram()
  : gram_cent_count_()
{}

suggestedPostPriceGram::suggestedPostPriceGram(int53 gram_cent_count_)
  : gram_cent_count_(gram_cent_count_)
{}

const std::int32_t suggestedPostPriceGram::ID;

void suggestedPostPriceGram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostPriceGram");
    s.store_field("gram_cent_count", gram_cent_count_);
    s.store_class_end();
  }
}

supergroupMembersFilterRecent::supergroupMembersFilterRecent() {
}

const std::int32_t supergroupMembersFilterRecent::ID;

void supergroupMembersFilterRecent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterRecent");
    s.store_class_end();
  }
}

supergroupMembersFilterContacts::supergroupMembersFilterContacts()
  : query_()
{}

supergroupMembersFilterContacts::supergroupMembersFilterContacts(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterContacts::ID;

void supergroupMembersFilterContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterContacts");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterAdministrators::supergroupMembersFilterAdministrators() {
}

const std::int32_t supergroupMembersFilterAdministrators::ID;

void supergroupMembersFilterAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterAdministrators");
    s.store_class_end();
  }
}

supergroupMembersFilterSearch::supergroupMembersFilterSearch()
  : query_()
{}

supergroupMembersFilterSearch::supergroupMembersFilterSearch(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterSearch::ID;

void supergroupMembersFilterSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterSearch");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterRestricted::supergroupMembersFilterRestricted()
  : query_()
{}

supergroupMembersFilterRestricted::supergroupMembersFilterRestricted(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterRestricted::ID;

void supergroupMembersFilterRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterRestricted");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterBanned::supergroupMembersFilterBanned()
  : query_()
{}

supergroupMembersFilterBanned::supergroupMembersFilterBanned(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterBanned::ID;

void supergroupMembersFilterBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterBanned");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterMention::supergroupMembersFilterMention()
  : query_()
  , topic_id_()
{}

supergroupMembersFilterMention::supergroupMembersFilterMention(string const &query_, object_ptr<MessageTopic> &&topic_id_)
  : query_(query_)
  , topic_id_(std::move(topic_id_))
{}

const std::int32_t supergroupMembersFilterMention::ID;

void supergroupMembersFilterMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterMention");
    s.store_field("query", query_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_class_end();
  }
}

supergroupMembersFilterBots::supergroupMembersFilterBots() {
}

const std::int32_t supergroupMembersFilterBots::ID;

void supergroupMembersFilterBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterBots");
    s.store_class_end();
  }
}

termsOfService::termsOfService()
  : text_()
  , min_user_age_()
  , show_popup_()
{}

termsOfService::termsOfService(object_ptr<formattedText> &&text_, int32 min_user_age_, bool show_popup_)
  : text_(std::move(text_))
  , min_user_age_(min_user_age_)
  , show_popup_(show_popup_)
{}

const std::int32_t termsOfService::ID;

void termsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "termsOfService");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("min_user_age", min_user_age_);
    s.store_field("show_popup", show_popup_);
    s.store_class_end();
  }
}

textEntity::textEntity()
  : offset_()
  , length_()
  , type_()
{}

textEntity::textEntity(int32 offset_, int32 length_, object_ptr<TextEntityType> &&type_)
  : offset_(offset_)
  , length_(length_)
  , type_(std::move(type_))
{}

const std::int32_t textEntity::ID;

void textEntity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntity");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

themeSettings::themeSettings()
  : base_theme_()
  , accent_color_()
  , background_()
  , outgoing_message_fill_()
  , animate_outgoing_message_fill_()
  , has_outgoing_message_accent_color_()
  , outgoing_message_accent_color_()
{}

themeSettings::themeSettings(object_ptr<BuiltInTheme> &&base_theme_, int32 accent_color_, object_ptr<background> &&background_, object_ptr<BackgroundFill> &&outgoing_message_fill_, bool animate_outgoing_message_fill_, bool has_outgoing_message_accent_color_, int32 outgoing_message_accent_color_)
  : base_theme_(std::move(base_theme_))
  , accent_color_(accent_color_)
  , background_(std::move(background_))
  , outgoing_message_fill_(std::move(outgoing_message_fill_))
  , animate_outgoing_message_fill_(animate_outgoing_message_fill_)
  , has_outgoing_message_accent_color_(has_outgoing_message_accent_color_)
  , outgoing_message_accent_color_(outgoing_message_accent_color_)
{}

const std::int32_t themeSettings::ID;

void themeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "themeSettings");
    s.store_object_field("base_theme", static_cast<const BaseObject *>(base_theme_.get()));
    s.store_field("accent_color", accent_color_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("outgoing_message_fill", static_cast<const BaseObject *>(outgoing_message_fill_.get()));
    s.store_field("animate_outgoing_message_fill", animate_outgoing_message_fill_);
    s.store_field("has_outgoing_message_accent_color", has_outgoing_message_accent_color_);
    s.store_field("outgoing_message_accent_color", outgoing_message_accent_color_);
    s.store_class_end();
  }
}

timeZones::timeZones()
  : time_zones_()
{}

timeZones::timeZones(array<object_ptr<timeZone>> &&time_zones_)
  : time_zones_(std::move(time_zones_))
{}

const std::int32_t timeZones::ID;

void timeZones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "timeZones");
    { s.store_vector_begin("time_zones", time_zones_.size()); for (const auto &_value : time_zones_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

tonCenterApiRequestTypeGet::tonCenterApiRequestTypeGet()
  : query_()
{}

tonCenterApiRequestTypeGet::tonCenterApiRequestTypeGet(string const &query_)
  : query_(query_)
{}

const std::int32_t tonCenterApiRequestTypeGet::ID;

void tonCenterApiRequestTypeGet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonCenterApiRequestTypeGet");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

tonCenterApiRequestTypePost::tonCenterApiRequestTypePost()
  : payload_()
{}

tonCenterApiRequestTypePost::tonCenterApiRequestTypePost(string const &payload_)
  : payload_(payload_)
{}

const std::int32_t tonCenterApiRequestTypePost::ID;

void tonCenterApiRequestTypePost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonCenterApiRequestTypePost");
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

tonConnectRequest::tonConnectRequest()
  : session_id_()
  , message_id_()
  , body_()
  , expiration_date_()
  , topic_()
  , trace_id_()
{}

tonConnectRequest::tonConnectRequest(int64 session_id_, int53 message_id_, bytes const &body_, int32 expiration_date_, string const &topic_, string const &trace_id_)
  : session_id_(session_id_)
  , message_id_(message_id_)
  , body_(std::move(body_))
  , expiration_date_(expiration_date_)
  , topic_(topic_)
  , trace_id_(trace_id_)
{}

const std::int32_t tonConnectRequest::ID;

void tonConnectRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectRequest");
    s.store_field("session_id", session_id_);
    s.store_field("message_id", message_id_);
    s.store_bytes_field("body", body_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("topic", topic_);
    s.store_field("trace_id", trace_id_);
    s.store_class_end();
  }
}

tonConnectRequests::tonConnectRequests()
  : session_()
  , requests_()
{}

tonConnectRequests::tonConnectRequests(object_ptr<tonConnectSession> &&session_, array<object_ptr<tonConnectRequest>> &&requests_)
  : session_(std::move(session_))
  , requests_(std::move(requests_))
{}

const std::int32_t tonConnectRequests::ID;

void tonConnectRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectRequests");
    s.store_object_field("session", static_cast<const BaseObject *>(session_.get()));
    { s.store_vector_begin("requests", requests_.size()); for (const auto &_value : requests_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

tonConnectSessionEventId::tonConnectSessionEventId()
  : event_id_()
{}

tonConnectSessionEventId::tonConnectSessionEventId(int64 event_id_)
  : event_id_(event_id_)
{}

const std::int32_t tonConnectSessionEventId::ID;

void tonConnectSessionEventId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectSessionEventId");
    s.store_field("event_id", event_id_);
    s.store_class_end();
  }
}

tonConnectSessionStatePending::tonConnectSessionStatePending() {
}

const std::int32_t tonConnectSessionStatePending::ID;

void tonConnectSessionStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectSessionStatePending");
    s.store_class_end();
  }
}

tonConnectSessionStateReady::tonConnectSessionStateReady() {
}

const std::int32_t tonConnectSessionStateReady::ID;

void tonConnectSessionStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectSessionStateReady");
    s.store_class_end();
  }
}

tonConnectSessionStateClosing::tonConnectSessionStateClosing() {
}

const std::int32_t tonConnectSessionStateClosing::ID;

void tonConnectSessionStateClosing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectSessionStateClosing");
    s.store_class_end();
  }
}

tonConnectSessionStateClosed::tonConnectSessionStateClosed() {
}

const std::int32_t tonConnectSessionStateClosed::ID;

void tonConnectSessionStateClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectSessionStateClosed");
    s.store_class_end();
  }
}

tonWalletMessage::tonWalletMessage()
  : destination_address_()
  , gram_amount_()
  , send_mode_()
  , body_()
  , initial_state_()
{}

tonWalletMessage::tonWalletMessage(string const &destination_address_, int64 gram_amount_, int32 send_mode_, bytes const &body_, object_ptr<tonSmartContractInitialState> &&initial_state_)
  : destination_address_(destination_address_)
  , gram_amount_(gram_amount_)
  , send_mode_(send_mode_)
  , body_(std::move(body_))
  , initial_state_(std::move(initial_state_))
{}

const std::int32_t tonWalletMessage::ID;

void tonWalletMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletMessage");
    s.store_field("destination_address", destination_address_);
    s.store_field("gram_amount", gram_amount_);
    s.store_field("send_mode", send_mode_);
    s.store_bytes_field("body", body_);
    s.store_object_field("initial_state", static_cast<const BaseObject *>(initial_state_.get()));
    s.store_class_end();
  }
}

tonWalletTransferResult::tonWalletTransferResult()
  : is_gasless_()
  , msg_hash_()
  , transaction_()
{}

tonWalletTransferResult::tonWalletTransferResult(bool is_gasless_, bytes const &msg_hash_, object_ptr<tonWalletTransaction> &&transaction_)
  : is_gasless_(is_gasless_)
  , msg_hash_(std::move(msg_hash_))
  , transaction_(std::move(transaction_))
{}

const std::int32_t tonWalletTransferResult::ID;

void tonWalletTransferResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransferResult");
    s.store_field("is_gasless", is_gasless_);
    s.store_bytes_field("msg_hash", msg_hash_);
    s.store_object_field("transaction", static_cast<const BaseObject *>(transaction_.get()));
    s.store_class_end();
  }
}

upgradedGiftAttributeRarityPerMille::upgradedGiftAttributeRarityPerMille()
  : per_mille_()
{}

upgradedGiftAttributeRarityPerMille::upgradedGiftAttributeRarityPerMille(int32 per_mille_)
  : per_mille_(per_mille_)
{}

const std::int32_t upgradedGiftAttributeRarityPerMille::ID;

void upgradedGiftAttributeRarityPerMille::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeRarityPerMille");
    s.store_field("per_mille", per_mille_);
    s.store_class_end();
  }
}

upgradedGiftAttributeRarityUncommon::upgradedGiftAttributeRarityUncommon() {
}

const std::int32_t upgradedGiftAttributeRarityUncommon::ID;

void upgradedGiftAttributeRarityUncommon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeRarityUncommon");
    s.store_class_end();
  }
}

upgradedGiftAttributeRarityRare::upgradedGiftAttributeRarityRare() {
}

const std::int32_t upgradedGiftAttributeRarityRare::ID;

void upgradedGiftAttributeRarityRare::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeRarityRare");
    s.store_class_end();
  }
}

upgradedGiftAttributeRarityEpic::upgradedGiftAttributeRarityEpic() {
}

const std::int32_t upgradedGiftAttributeRarityEpic::ID;

void upgradedGiftAttributeRarityEpic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeRarityEpic");
    s.store_class_end();
  }
}

upgradedGiftAttributeRarityLegendary::upgradedGiftAttributeRarityLegendary() {
}

const std::int32_t upgradedGiftAttributeRarityLegendary::ID;

void upgradedGiftAttributeRarityLegendary::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeRarityLegendary");
    s.store_class_end();
  }
}

userAuctionBid::userAuctionBid()
  : star_count_()
  , bid_date_()
  , next_bid_star_count_()
  , owner_id_()
  , was_returned_()
{}

userAuctionBid::userAuctionBid(int53 star_count_, int32 bid_date_, int53 next_bid_star_count_, object_ptr<MessageSender> &&owner_id_, bool was_returned_)
  : star_count_(star_count_)
  , bid_date_(bid_date_)
  , next_bid_star_count_(next_bid_star_count_)
  , owner_id_(std::move(owner_id_))
  , was_returned_(was_returned_)
{}

const std::int32_t userAuctionBid::ID;

void userAuctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userAuctionBid");
    s.store_field("star_count", star_count_);
    s.store_field("bid_date", bid_date_);
    s.store_field("next_bid_star_count", next_bid_star_count_);
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("was_returned", was_returned_);
    s.store_class_end();
  }
}

userPrivacySettingRules::userPrivacySettingRules()
  : rules_()
{}

userPrivacySettingRules::userPrivacySettingRules(array<object_ptr<UserPrivacySettingRule>> &&rules_)
  : rules_(std::move(rules_))
{}

const std::int32_t userPrivacySettingRules::ID;

void userPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRules");
    { s.store_vector_begin("rules", rules_.size()); for (const auto &_value : rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

userStatusEmpty::userStatusEmpty() {
}

const std::int32_t userStatusEmpty::ID;

void userStatusEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusEmpty");
    s.store_class_end();
  }
}

userStatusOnline::userStatusOnline()
  : expires_()
{}

userStatusOnline::userStatusOnline(int32 expires_)
  : expires_(expires_)
{}

const std::int32_t userStatusOnline::ID;

void userStatusOnline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusOnline");
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

userStatusOffline::userStatusOffline()
  : was_online_()
{}

userStatusOffline::userStatusOffline(int32 was_online_)
  : was_online_(was_online_)
{}

const std::int32_t userStatusOffline::ID;

void userStatusOffline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusOffline");
    s.store_field("was_online", was_online_);
    s.store_class_end();
  }
}

userStatusRecently::userStatusRecently()
  : by_my_privacy_settings_()
{}

userStatusRecently::userStatusRecently(bool by_my_privacy_settings_)
  : by_my_privacy_settings_(by_my_privacy_settings_)
{}

const std::int32_t userStatusRecently::ID;

void userStatusRecently::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusRecently");
    s.store_field("by_my_privacy_settings", by_my_privacy_settings_);
    s.store_class_end();
  }
}

userStatusLastWeek::userStatusLastWeek()
  : by_my_privacy_settings_()
{}

userStatusLastWeek::userStatusLastWeek(bool by_my_privacy_settings_)
  : by_my_privacy_settings_(by_my_privacy_settings_)
{}

const std::int32_t userStatusLastWeek::ID;

void userStatusLastWeek::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusLastWeek");
    s.store_field("by_my_privacy_settings", by_my_privacy_settings_);
    s.store_class_end();
  }
}

userStatusLastMonth::userStatusLastMonth()
  : by_my_privacy_settings_()
{}

userStatusLastMonth::userStatusLastMonth(bool by_my_privacy_settings_)
  : by_my_privacy_settings_(by_my_privacy_settings_)
{}

const std::int32_t userStatusLastMonth::ID;

void userStatusLastMonth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusLastMonth");
    s.store_field("by_my_privacy_settings", by_my_privacy_settings_);
    s.store_class_end();
  }
}

userTonWalletAddresses::userTonWalletAddresses()
  : addresses_()
{}

userTonWalletAddresses::userTonWalletAddresses(array<object_ptr<userTonWalletAddress>> &&addresses_)
  : addresses_(std::move(addresses_))
{}

const std::int32_t userTonWalletAddresses::ID;

void userTonWalletAddresses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTonWalletAddresses");
    { s.store_vector_begin("addresses", addresses_.size()); for (const auto &_value : addresses_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

video::video()
  : duration_()
  , width_()
  , height_()
  , file_name_()
  , mime_type_()
  , has_stickers_()
  , supports_streaming_()
  , minithumbnail_()
  , thumbnail_()
  , video_()
{}

video::video(int32 duration_, int32 width_, int32 height_, string const &file_name_, string const &mime_type_, bool has_stickers_, bool supports_streaming_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&video_)
  : duration_(duration_)
  , width_(width_)
  , height_(height_)
  , file_name_(file_name_)
  , mime_type_(mime_type_)
  , has_stickers_(has_stickers_)
  , supports_streaming_(supports_streaming_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , video_(std::move(video_))
{}

const std::int32_t video::ID;

void video::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "video");
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_field("has_stickers", has_stickers_);
    s.store_field("supports_streaming", supports_streaming_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

videoNote::videoNote()
  : duration_()
  , waveform_()
  , length_()
  , minithumbnail_()
  , thumbnail_()
  , speech_recognition_result_()
  , video_()
{}

videoNote::videoNote(int32 duration_, bytes const &waveform_, int32 length_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<SpeechRecognitionResult> &&speech_recognition_result_, object_ptr<file> &&video_)
  : duration_(duration_)
  , waveform_(std::move(waveform_))
  , length_(length_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , speech_recognition_result_(std::move(speech_recognition_result_))
  , video_(std::move(video_))
{}

const std::int32_t videoNote::ID;

void videoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoNote");
    s.store_field("duration", duration_);
    s.store_bytes_field("waveform", waveform_);
    s.store_field("length", length_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("speech_recognition_result", static_cast<const BaseObject *>(speech_recognition_result_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

webBrowserSettings::webBrowserSettings()
  : open_external_browser_()
  , external_exceptions_()
  , in_app_exceptions_()
  , display_close_button_()
{}

webBrowserSettings::webBrowserSettings(bool open_external_browser_, array<object_ptr<webDomainException>> &&external_exceptions_, array<object_ptr<webDomainException>> &&in_app_exceptions_, bool display_close_button_)
  : open_external_browser_(open_external_browser_)
  , external_exceptions_(std::move(external_exceptions_))
  , in_app_exceptions_(std::move(in_app_exceptions_))
  , display_close_button_(display_close_button_)
{}

const std::int32_t webBrowserSettings::ID;

void webBrowserSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webBrowserSettings");
    s.store_field("open_external_browser", open_external_browser_);
    { s.store_vector_begin("external_exceptions", external_exceptions_.size()); for (const auto &_value : external_exceptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("in_app_exceptions", in_app_exceptions_.size()); for (const auto &_value : in_app_exceptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("display_close_button", display_close_button_);
    s.store_class_end();
  }
}

webDomainException::webDomainException()
  : url_()
  , domain_()
  , title_()
  , favicon_custom_emoji_id_()
{}

webDomainException::webDomainException(string const &url_, string const &domain_, string const &title_, int64 favicon_custom_emoji_id_)
  : url_(url_)
  , domain_(domain_)
  , title_(title_)
  , favicon_custom_emoji_id_(favicon_custom_emoji_id_)
{}

const std::int32_t webDomainException::ID;

void webDomainException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webDomainException");
    s.store_field("url", url_);
    s.store_field("domain", domain_);
    s.store_field("title", title_);
    s.store_field("favicon_custom_emoji_id", favicon_custom_emoji_id_);
    s.store_class_end();
  }
}

addLogMessage::addLogMessage()
  : verbosity_level_()
  , text_()
{}

addLogMessage::addLogMessage(int32 verbosity_level_, string const &text_)
  : verbosity_level_(verbosity_level_)
  , text_(text_)
{}

const std::int32_t addLogMessage::ID;

void addLogMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addLogMessage");
    s.store_field("verbosity_level", verbosity_level_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

addLoginPasskey::addLoginPasskey()
  : client_data_()
  , attestation_object_()
{}

addLoginPasskey::addLoginPasskey(string const &client_data_, bytes const &attestation_object_)
  : client_data_(client_data_)
  , attestation_object_(std::move(attestation_object_))
{}

const std::int32_t addLoginPasskey::ID;

void addLoginPasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addLoginPasskey");
    s.store_field("client_data", client_data_);
    s.store_bytes_field("attestation_object", attestation_object_);
    s.store_class_end();
  }
}

addQuickReplyShortcutMessage::addQuickReplyShortcutMessage()
  : shortcut_name_()
  , reply_to_message_id_()
  , input_message_content_()
{}

addQuickReplyShortcutMessage::addQuickReplyShortcutMessage(string const &shortcut_name_, int53 reply_to_message_id_, object_ptr<InputMessageContent> &&input_message_content_)
  : shortcut_name_(shortcut_name_)
  , reply_to_message_id_(reply_to_message_id_)
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t addQuickReplyShortcutMessage::ID;

void addQuickReplyShortcutMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addQuickReplyShortcutMessage");
    s.store_field("shortcut_name", shortcut_name_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

addTextCompositionStyle::addTextCompositionStyle()
  : name_()
{}

addTextCompositionStyle::addTextCompositionStyle(string const &name_)
  : name_(name_)
{}

const std::int32_t addTextCompositionStyle::ID;

void addTextCompositionStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addTextCompositionStyle");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

answerChatJoinRequestQuery::answerChatJoinRequestQuery()
  : query_id_()
  , result_()
  , url_()
{}

answerChatJoinRequestQuery::answerChatJoinRequestQuery(int64 query_id_, object_ptr<ChatJoinRequestResult> &&result_, string const &url_)
  : query_id_(query_id_)
  , result_(std::move(result_))
  , url_(url_)
{}

const std::int32_t answerChatJoinRequestQuery::ID;

void answerChatJoinRequestQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerChatJoinRequestQuery");
    s.store_field("query_id", query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_field("url", url_);
    s.store_class_end();
  }
}

answerCustomQuery::answerCustomQuery()
  : custom_query_id_()
  , data_()
{}

answerCustomQuery::answerCustomQuery(int64 custom_query_id_, string const &data_)
  : custom_query_id_(custom_query_id_)
  , data_(data_)
{}

const std::int32_t answerCustomQuery::ID;

void answerCustomQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerCustomQuery");
    s.store_field("custom_query_id", custom_query_id_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

cancelDownloadFile::cancelDownloadFile()
  : file_id_()
  , only_if_pending_()
{}

cancelDownloadFile::cancelDownloadFile(int32 file_id_, bool only_if_pending_)
  : file_id_(file_id_)
  , only_if_pending_(only_if_pending_)
{}

const std::int32_t cancelDownloadFile::ID;

void cancelDownloadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelDownloadFile");
    s.store_field("file_id", file_id_);
    s.store_field("only_if_pending", only_if_pending_);
    s.store_class_end();
  }
}

cancelPasswordReset::cancelPasswordReset() {
}

const std::int32_t cancelPasswordReset::ID;

void cancelPasswordReset::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelPasswordReset");
    s.store_class_end();
  }
}

checkAuthenticationPasskey::checkAuthenticationPasskey()
  : credential_id_()
  , client_data_()
  , authenticator_data_()
  , signature_()
  , user_handle_()
{}

checkAuthenticationPasskey::checkAuthenticationPasskey(string const &credential_id_, string const &client_data_, bytes const &authenticator_data_, bytes const &signature_, bytes const &user_handle_)
  : credential_id_(credential_id_)
  , client_data_(client_data_)
  , authenticator_data_(std::move(authenticator_data_))
  , signature_(std::move(signature_))
  , user_handle_(std::move(user_handle_))
{}

const std::int32_t checkAuthenticationPasskey::ID;

void checkAuthenticationPasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationPasskey");
    s.store_field("credential_id", credential_id_);
    s.store_field("client_data", client_data_);
    s.store_bytes_field("authenticator_data", authenticator_data_);
    s.store_bytes_field("signature", signature_);
    s.store_bytes_field("user_handle", user_handle_);
    s.store_class_end();
  }
}

checkChatUsername::checkChatUsername()
  : chat_id_()
  , username_()
{}

checkChatUsername::checkChatUsername(int53 chat_id_, string const &username_)
  : chat_id_(chat_id_)
  , username_(username_)
{}

const std::int32_t checkChatUsername::ID;

void checkChatUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsername");
    s.store_field("chat_id", chat_id_);
    s.store_field("username", username_);
    s.store_class_end();
  }
}

checkEmailAddressVerificationCode::checkEmailAddressVerificationCode()
  : code_()
{}

checkEmailAddressVerificationCode::checkEmailAddressVerificationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkEmailAddressVerificationCode::ID;

void checkEmailAddressVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkEmailAddressVerificationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

closeSecretChat::closeSecretChat()
  : secret_chat_id_()
{}

closeSecretChat::closeSecretChat(int32 secret_chat_id_)
  : secret_chat_id_(secret_chat_id_)
{}

const std::int32_t closeSecretChat::ID;

void closeSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeSecretChat");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_class_end();
  }
}

closeStory::closeStory()
  : story_poster_chat_id_()
  , story_id_()
{}

closeStory::closeStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t closeStory::ID;

void closeStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

confirmSession::confirmSession()
  : session_id_()
{}

confirmSession::confirmSession(int64 session_id_)
  : session_id_(session_id_)
{}

const std::int32_t confirmSession::ID;

void confirmSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "confirmSession");
    s.store_field("session_id", session_id_);
    s.store_class_end();
  }
}

createRichMessageWithAi::createRichMessageWithAi()
  : prompt_()
  , language_code_()
  , add_emojis_()
{}

createRichMessageWithAi::createRichMessageWithAi(string const &prompt_, string const &language_code_, bool add_emojis_)
  : prompt_(prompt_)
  , language_code_(language_code_)
  , add_emojis_(add_emojis_)
{}

const std::int32_t createRichMessageWithAi::ID;

void createRichMessageWithAi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createRichMessageWithAi");
    s.store_field("prompt", prompt_);
    s.store_field("language_code", language_code_);
    s.store_field("add_emojis", add_emojis_);
    s.store_class_end();
  }
}

createSecretChat::createSecretChat()
  : secret_chat_id_()
{}

createSecretChat::createSecretChat(int32 secret_chat_id_)
  : secret_chat_id_(secret_chat_id_)
{}

const std::int32_t createSecretChat::ID;

void createSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createSecretChat");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_class_end();
  }
}

createTextCompositionStyle::createTextCompositionStyle()
  : title_()
  , custom_emoji_id_()
  , prompt_()
  , show_creator_()
{}

createTextCompositionStyle::createTextCompositionStyle(string const &title_, int64 custom_emoji_id_, string const &prompt_, bool show_creator_)
  : title_(title_)
  , custom_emoji_id_(custom_emoji_id_)
  , prompt_(prompt_)
  , show_creator_(show_creator_)
{}

const std::int32_t createTextCompositionStyle::ID;

void createTextCompositionStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createTextCompositionStyle");
    s.store_field("title", title_);
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_field("prompt", prompt_);
    s.store_field("show_creator", show_creator_);
    s.store_class_end();
  }
}

declineOauthRequest::declineOauthRequest()
  : url_()
{}

declineOauthRequest::declineOauthRequest(string const &url_)
  : url_(url_)
{}

const std::int32_t declineOauthRequest::ID;

void declineOauthRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "declineOauthRequest");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

decryptGroupCallData::decryptGroupCallData()
  : group_call_id_()
  , participant_id_()
  , data_channel_()
  , data_()
{}

decryptGroupCallData::decryptGroupCallData(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, object_ptr<GroupCallDataChannel> &&data_channel_, bytes const &data_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , data_channel_(std::move(data_channel_))
  , data_(std::move(data_))
{}

const std::int32_t decryptGroupCallData::ID;

void decryptGroupCallData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "decryptGroupCallData");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_object_field("data_channel", static_cast<const BaseObject *>(data_channel_.get()));
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

deleteBotSecondaryUsername::deleteBotSecondaryUsername()
  : bot_user_id_()
{}

deleteBotSecondaryUsername::deleteBotSecondaryUsername(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t deleteBotSecondaryUsername::ID;

void deleteBotSecondaryUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteBotSecondaryUsername");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

deleteChatFolderInviteLink::deleteChatFolderInviteLink()
  : chat_folder_id_()
  , invite_link_()
{}

deleteChatFolderInviteLink::deleteChatFolderInviteLink(int32 chat_folder_id_, string const &invite_link_)
  : chat_folder_id_(chat_folder_id_)
  , invite_link_(invite_link_)
{}

const std::int32_t deleteChatFolderInviteLink::ID;

void deleteChatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatFolderInviteLink");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

deleteFile::deleteFile()
  : file_id_()
{}

deleteFile::deleteFile(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t deleteFile::ID;

void deleteFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteFile");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

deletePollOption::deletePollOption()
  : chat_id_()
  , message_id_()
  , option_id_()
{}

deletePollOption::deletePollOption(int53 chat_id_, int53 message_id_, string const &option_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_id_(option_id_)
{}

const std::int32_t deletePollOption::ID;

void deletePollOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deletePollOption");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("option_id", option_id_);
    s.store_class_end();
  }
}

deleteSavedOrderInfo::deleteSavedOrderInfo() {
}

const std::int32_t deleteSavedOrderInfo::ID;

void deleteSavedOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteSavedOrderInfo");
    s.store_class_end();
  }
}

disableAllSupergroupUsernames::disableAllSupergroupUsernames()
  : supergroup_id_()
{}

disableAllSupergroupUsernames::disableAllSupergroupUsernames(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t disableAllSupergroupUsernames::ID;

void disableAllSupergroupUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disableAllSupergroupUsernames");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

disableProxy::disableProxy() {
}

const std::int32_t disableProxy::ID;

void disableProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disableProxy");
    s.store_class_end();
  }
}

enableTonWalletBackup::enableTonWalletBackup()
  : secret_phrase_()
  , proof_()
{}

enableTonWalletBackup::enableTonWalletBackup(string const &secret_phrase_, object_ptr<tonWalletOwnershipProof> &&proof_)
  : secret_phrase_(secret_phrase_)
  , proof_(std::move(proof_))
{}

const std::int32_t enableTonWalletBackup::ID;

void enableTonWalletBackup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "enableTonWalletBackup");
    s.store_field("secret_phrase", "[REDACTED]");
    s.store_object_field("proof", static_cast<const BaseObject *>(proof_.get()));
    s.store_class_end();
  }
}

getAuthenticationPasskeyParameters::getAuthenticationPasskeyParameters() {
}

const std::int32_t getAuthenticationPasskeyParameters::ID;

void getAuthenticationPasskeyParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAuthenticationPasskeyParameters");
    s.store_class_end();
  }
}

getAutoDownloadSettingsPresets::getAutoDownloadSettingsPresets() {
}

const std::int32_t getAutoDownloadSettingsPresets::ID;

void getAutoDownloadSettingsPresets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAutoDownloadSettingsPresets");
    s.store_class_end();
  }
}

getBotName::getBotName()
  : bot_user_id_()
  , language_code_()
{}

getBotName::getBotName(int53 bot_user_id_, string const &language_code_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
{}

const std::int32_t getBotName::ID;

void getBotName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotName");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getBusinessConnectedBot::getBusinessConnectedBot() {
}

const std::int32_t getBusinessConnectedBot::ID;

void getBusinessConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessConnectedBot");
    s.store_class_end();
  }
}

getChatArchivedStories::getChatArchivedStories()
  : chat_id_()
  , from_story_id_()
  , limit_()
{}

getChatArchivedStories::getChatArchivedStories(int53 chat_id_, int32 from_story_id_, int32 limit_)
  : chat_id_(chat_id_)
  , from_story_id_(from_story_id_)
  , limit_(limit_)
{}

const std::int32_t getChatArchivedStories::ID;

void getChatArchivedStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatArchivedStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("from_story_id", from_story_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatBoostLevelFeatures::getChatBoostLevelFeatures()
  : is_channel_()
  , level_()
{}

getChatBoostLevelFeatures::getChatBoostLevelFeatures(bool is_channel_, int32 level_)
  : is_channel_(is_channel_)
  , level_(level_)
{}

const std::int32_t getChatBoostLevelFeatures::ID;

void getChatBoostLevelFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoostLevelFeatures");
    s.store_field("is_channel", is_channel_);
    s.store_field("level", level_);
    s.store_class_end();
  }
}

getChatBoosts::getChatBoosts()
  : chat_id_()
  , only_gift_codes_()
  , offset_()
  , limit_()
{}

getChatBoosts::getChatBoosts(int53 chat_id_, bool only_gift_codes_, string const &offset_, int32 limit_)
  : chat_id_(chat_id_)
  , only_gift_codes_(only_gift_codes_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getChatBoosts::ID;

void getChatBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoosts");
    s.store_field("chat_id", chat_id_);
    s.store_field("only_gift_codes", only_gift_codes_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatFolder::getChatFolder()
  : chat_folder_id_()
{}

getChatFolder::getChatFolder(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t getChatFolder::ID;

void getChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolder");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

getChatFolderInviteLinks::getChatFolderInviteLinks()
  : chat_folder_id_()
{}

getChatFolderInviteLinks::getChatFolderInviteLinks(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t getChatFolderInviteLinks::ID;

void getChatFolderInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolderInviteLinks");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

getChatListsToAddChat::getChatListsToAddChat()
  : chat_id_()
{}

getChatListsToAddChat::getChatListsToAddChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatListsToAddChat::ID;

void getChatListsToAddChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatListsToAddChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatOwnerAfterLeaving::getChatOwnerAfterLeaving()
  : chat_id_()
{}

getChatOwnerAfterLeaving::getChatOwnerAfterLeaving(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatOwnerAfterLeaving::ID;

void getChatOwnerAfterLeaving::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatOwnerAfterLeaving");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatStatistics::getChatStatistics()
  : chat_id_()
  , is_dark_()
{}

getChatStatistics::getChatStatistics(int53 chat_id_, bool is_dark_)
  : chat_id_(chat_id_)
  , is_dark_(is_dark_)
{}

const std::int32_t getChatStatistics::ID;

void getChatStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatStatistics");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getCountryCode::getCountryCode() {
}

const std::int32_t getCountryCode::ID;

void getCountryCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCountryCode");
    s.store_class_end();
  }
}

getDirectMessagesChatTopicHistory::getDirectMessagesChatTopicHistory()
  : chat_id_()
  , topic_id_()
  , from_message_id_()
  , offset_()
  , limit_()
{}

getDirectMessagesChatTopicHistory::getDirectMessagesChatTopicHistory(int53 chat_id_, int53 topic_id_, int53 from_message_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getDirectMessagesChatTopicHistory::ID;

void getDirectMessagesChatTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDirectMessagesChatTopicHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getForumTopicPopularIcons::getForumTopicPopularIcons()
  : chat_id_()
{}

getForumTopicPopularIcons::getForumTopicPopularIcons(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getForumTopicPopularIcons::ID;

void getForumTopicPopularIcons::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getForumTopicPopularIcons");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getGiftAuctionState::getGiftAuctionState()
  : auction_id_()
{}

getGiftAuctionState::getGiftAuctionState(string const &auction_id_)
  : auction_id_(auction_id_)
{}

const std::int32_t getGiftAuctionState::ID;

void getGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftAuctionState");
    s.store_field("auction_id", auction_id_);
    s.store_class_end();
  }
}

getGiftMintingUrl::getGiftMintingUrl()
  : received_gift_id_()
{}

getGiftMintingUrl::getGiftMintingUrl(string const &received_gift_id_)
  : received_gift_id_(received_gift_id_)
{}

const std::int32_t getGiftMintingUrl::ID;

void getGiftMintingUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftMintingUrl");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

getGiftOnChainListingTransaction::getGiftOnChainListingTransaction()
  : gift_name_()
  , gram_amount_()
{}

getGiftOnChainListingTransaction::getGiftOnChainListingTransaction(string const &gift_name_, int64 gram_amount_)
  : gift_name_(gift_name_)
  , gram_amount_(gram_amount_)
{}

const std::int32_t getGiftOnChainListingTransaction::ID;

void getGiftOnChainListingTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftOnChainListingTransaction");
    s.store_field("gift_name", gift_name_);
    s.store_field("gram_amount", gram_amount_);
    s.store_class_end();
  }
}

getGramRevenueStatistics::getGramRevenueStatistics()
  : is_dark_()
{}

getGramRevenueStatistics::getGramRevenueStatistics(bool is_dark_)
  : is_dark_(is_dark_)
{}

const std::int32_t getGramRevenueStatistics::ID;

void getGramRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGramRevenueStatistics");
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getImportedContactCount::getImportedContactCount() {
}

const std::int32_t getImportedContactCount::ID;

void getImportedContactCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getImportedContactCount");
    s.store_class_end();
  }
}

getInternalLink::getInternalLink()
  : type_()
  , is_http_()
{}

getInternalLink::getInternalLink(object_ptr<InternalLinkType> &&type_, bool is_http_)
  : type_(std::move(type_))
  , is_http_(is_http_)
{}

const std::int32_t getInternalLink::ID;

void getInternalLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInternalLink");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("is_http", is_http_);
    s.store_class_end();
  }
}

getManagedBotAccessSettings::getManagedBotAccessSettings()
  : bot_user_id_()
{}

getManagedBotAccessSettings::getManagedBotAccessSettings(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t getManagedBotAccessSettings::ID;

void getManagedBotAccessSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getManagedBotAccessSettings");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

getMarkdownText::getMarkdownText()
  : text_()
{}

getMarkdownText::getMarkdownText(object_ptr<formattedText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t getMarkdownText::ID;

void getMarkdownText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMarkdownText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

getMessageLocally::getMessageLocally()
  : chat_id_()
  , message_id_()
{}

getMessageLocally::getMessageLocally(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageLocally::ID;

void getMessageLocally::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageLocally");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getPremiumGiftPaymentOptions::getPremiumGiftPaymentOptions() {
}

const std::int32_t getPremiumGiftPaymentOptions::ID;

void getPremiumGiftPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumGiftPaymentOptions");
    s.store_class_end();
  }
}

getPreparedInlineMessage::getPreparedInlineMessage()
  : bot_user_id_()
  , prepared_message_id_()
{}

getPreparedInlineMessage::getPreparedInlineMessage(int53 bot_user_id_, string const &prepared_message_id_)
  : bot_user_id_(bot_user_id_)
  , prepared_message_id_(prepared_message_id_)
{}

const std::int32_t getPreparedInlineMessage::ID;

void getPreparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPreparedInlineMessage");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("prepared_message_id", prepared_message_id_);
    s.store_class_end();
  }
}

getSavedMessagesTags::getSavedMessagesTags()
  : saved_messages_topic_id_()
{}

getSavedMessagesTags::getSavedMessagesTags(int53 saved_messages_topic_id_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
{}

const std::int32_t getSavedMessagesTags::ID;

void getSavedMessagesTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedMessagesTags");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_class_end();
  }
}

getSavedMessagesTopicMessageByDate::getSavedMessagesTopicMessageByDate()
  : saved_messages_topic_id_()
  , date_()
{}

getSavedMessagesTopicMessageByDate::getSavedMessagesTopicMessageByDate(int53 saved_messages_topic_id_, int32 date_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , date_(date_)
{}

const std::int32_t getSavedMessagesTopicMessageByDate::ID;

void getSavedMessagesTopicMessageByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedMessagesTopicMessageByDate");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

getSecretChat::getSecretChat()
  : secret_chat_id_()
{}

getSecretChat::getSecretChat(int32 secret_chat_id_)
  : secret_chat_id_(secret_chat_id_)
{}

const std::int32_t getSecretChat::ID;

void getSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSecretChat");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_class_end();
  }
}

getStarGiveawayPaymentOptions::getStarGiveawayPaymentOptions() {
}

const std::int32_t getStarGiveawayPaymentOptions::ID;

void getStarGiveawayPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarGiveawayPaymentOptions");
    s.store_class_end();
  }
}

getStarRevenueStatistics::getStarRevenueStatistics()
  : owner_id_()
  , is_dark_()
{}

getStarRevenueStatistics::getStarRevenueStatistics(object_ptr<MessageSender> &&owner_id_, bool is_dark_)
  : owner_id_(std::move(owner_id_))
  , is_dark_(is_dark_)
{}

const std::int32_t getStarRevenueStatistics::ID;

void getStarRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarRevenueStatistics");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getStarWithdrawalUrl::getStarWithdrawalUrl()
  : owner_id_()
  , star_count_()
  , password_()
{}

getStarWithdrawalUrl::getStarWithdrawalUrl(object_ptr<MessageSender> &&owner_id_, int53 star_count_, string const &password_)
  : owner_id_(std::move(owner_id_))
  , star_count_(star_count_)
  , password_(password_)
{}

const std::int32_t getStarWithdrawalUrl::ID;

void getStarWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarWithdrawalUrl");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("star_count", star_count_);
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

getStickerOutlineSvgPath::getStickerOutlineSvgPath()
  : sticker_file_id_()
  , for_animated_emoji_()
  , for_clicked_animated_emoji_message_()
{}

getStickerOutlineSvgPath::getStickerOutlineSvgPath(int32 sticker_file_id_, bool for_animated_emoji_, bool for_clicked_animated_emoji_message_)
  : sticker_file_id_(sticker_file_id_)
  , for_animated_emoji_(for_animated_emoji_)
  , for_clicked_animated_emoji_message_(for_clicked_animated_emoji_message_)
{}

const std::int32_t getStickerOutlineSvgPath::ID;

void getStickerOutlineSvgPath::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerOutlineSvgPath");
    s.store_field("sticker_file_id", sticker_file_id_);
    s.store_field("for_animated_emoji", for_animated_emoji_);
    s.store_field("for_clicked_animated_emoji_message", for_clicked_animated_emoji_message_);
    s.store_class_end();
  }
}

getTextCompositionStyleExample::getTextCompositionStyleExample()
  : name_()
  , example_number_()
{}

getTextCompositionStyleExample::getTextCompositionStyleExample(string const &name_, int32 example_number_)
  : name_(name_)
  , example_number_(example_number_)
{}

const std::int32_t getTextCompositionStyleExample::ID;

void getTextCompositionStyleExample::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTextCompositionStyleExample");
    s.store_field("name", name_);
    s.store_field("example_number", example_number_);
    s.store_class_end();
  }
}

getTextEmojiRanges::getTextEmojiRanges()
  : text_()
{}

getTextEmojiRanges::getTextEmojiRanges(string const &text_)
  : text_(text_)
{}

const std::int32_t getTextEmojiRanges::ID;

void getTextEmojiRanges::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTextEmojiRanges");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

getThemeParametersJsonString::getThemeParametersJsonString()
  : theme_()
{}

getThemeParametersJsonString::getThemeParametersJsonString(object_ptr<themeParameters> &&theme_)
  : theme_(std::move(theme_))
{}

const std::int32_t getThemeParametersJsonString::ID;

void getThemeParametersJsonString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getThemeParametersJsonString");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

getTonWalletTransactionByMsgHash::getTonWalletTransactionByMsgHash()
  : msg_hash_()
{}

getTonWalletTransactionByMsgHash::getTonWalletTransactionByMsgHash(string const &msg_hash_)
  : msg_hash_(msg_hash_)
{}

const std::int32_t getTonWalletTransactionByMsgHash::ID;

void getTonWalletTransactionByMsgHash::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonWalletTransactionByMsgHash");
    s.store_field("msg_hash", msg_hash_);
    s.store_class_end();
  }
}

getUpgradedGiftVariants::getUpgradedGiftVariants()
  : regular_gift_id_()
  , return_upgrade_models_()
  , return_craft_models_()
{}

getUpgradedGiftVariants::getUpgradedGiftVariants(int64 regular_gift_id_, bool return_upgrade_models_, bool return_craft_models_)
  : regular_gift_id_(regular_gift_id_)
  , return_upgrade_models_(return_upgrade_models_)
  , return_craft_models_(return_craft_models_)
{}

const std::int32_t getUpgradedGiftVariants::ID;

void getUpgradedGiftVariants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGiftVariants");
    s.store_field("regular_gift_id", regular_gift_id_);
    s.store_field("return_upgrade_models", return_upgrade_models_);
    s.store_field("return_craft_models", return_craft_models_);
    s.store_class_end();
  }
}

getUpgradedGiftsPromotionalAnimation::getUpgradedGiftsPromotionalAnimation() {
}

const std::int32_t getUpgradedGiftsPromotionalAnimation::ID;

void getUpgradedGiftsPromotionalAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGiftsPromotionalAnimation");
    s.store_class_end();
  }
}

getVideoMessageAdvertisements::getVideoMessageAdvertisements()
  : chat_id_()
  , message_id_()
{}

getVideoMessageAdvertisements::getVideoMessageAdvertisements(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getVideoMessageAdvertisements::ID;

void getVideoMessageAdvertisements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getVideoMessageAdvertisements");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getWebPageInstantView::getWebPageInstantView()
  : url_()
  , only_local_()
{}

getWebPageInstantView::getWebPageInstantView(string const &url_, bool only_local_)
  : url_(url_)
  , only_local_(only_local_)
{}

const std::int32_t getWebPageInstantView::ID;

void getWebPageInstantView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWebPageInstantView");
    s.store_field("url", url_);
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

inviteUsersToBot::inviteUsersToBot()
  : bot_user_id_()
  , user_ids_()
{}

inviteUsersToBot::inviteUsersToBot(int53 bot_user_id_, array<int53> &&user_ids_)
  : bot_user_id_(bot_user_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t inviteUsersToBot::ID;

void inviteUsersToBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteUsersToBot");
    s.store_field("bot_user_id", bot_user_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

joinVideoChat::joinVideoChat()
  : group_call_id_()
  , participant_id_()
  , join_parameters_()
  , invite_hash_()
{}

joinVideoChat::joinVideoChat(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, object_ptr<groupCallJoinParameters> &&join_parameters_, string const &invite_hash_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , join_parameters_(std::move(join_parameters_))
  , invite_hash_(invite_hash_)
{}

const std::int32_t joinVideoChat::ID;

void joinVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinVideoChat");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_object_field("join_parameters", static_cast<const BaseObject *>(join_parameters_.get()));
    s.store_field("invite_hash", invite_hash_);
    s.store_class_end();
  }
}

loadDirectMessagesChatTopics::loadDirectMessagesChatTopics()
  : chat_id_()
  , limit_()
{}

loadDirectMessagesChatTopics::loadDirectMessagesChatTopics(int53 chat_id_, int32 limit_)
  : chat_id_(chat_id_)
  , limit_(limit_)
{}

const std::int32_t loadDirectMessagesChatTopics::ID;

void loadDirectMessagesChatTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadDirectMessagesChatTopics");
    s.store_field("chat_id", chat_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

loadSavedMessagesTopics::loadSavedMessagesTopics()
  : limit_()
{}

loadSavedMessagesTopics::loadSavedMessagesTopics(int32 limit_)
  : limit_(limit_)
{}

const std::int32_t loadSavedMessagesTopics::ID;

void loadSavedMessagesTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadSavedMessagesTopics");
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

logOut::logOut() {
}

const std::int32_t logOut::ID;

void logOut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logOut");
    s.store_class_end();
  }
}

processChatJoinRequests::processChatJoinRequests()
  : chat_id_()
  , invite_link_()
  , approve_()
{}

processChatJoinRequests::processChatJoinRequests(int53 chat_id_, string const &invite_link_, bool approve_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , approve_(approve_)
{}

const std::int32_t processChatJoinRequests::ID;

void processChatJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processChatJoinRequests");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("approve", approve_);
    s.store_class_end();
  }
}

processCommunityAddChatRequest::processCommunityAddChatRequest()
  : community_id_()
  , chat_id_()
  , approve_()
{}

processCommunityAddChatRequest::processCommunityAddChatRequest(int53 community_id_, int53 chat_id_, bool approve_)
  : community_id_(community_id_)
  , chat_id_(chat_id_)
  , approve_(approve_)
{}

const std::int32_t processCommunityAddChatRequest::ID;

void processCommunityAddChatRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processCommunityAddChatRequest");
    s.store_field("community_id", community_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("approve", approve_);
    s.store_class_end();
  }
}

readAllForumTopicMentions::readAllForumTopicMentions()
  : chat_id_()
  , forum_topic_id_()
{}

readAllForumTopicMentions::readAllForumTopicMentions(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t readAllForumTopicMentions::ID;

void readAllForumTopicMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllForumTopicMentions");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

removeFavoriteSticker::removeFavoriteSticker()
  : sticker_()
{}

removeFavoriteSticker::removeFavoriteSticker(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t removeFavoriteSticker::ID;

void removeFavoriteSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeFavoriteSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

removeLoginPasskey::removeLoginPasskey()
  : passkey_id_()
{}

removeLoginPasskey::removeLoginPasskey(string const &passkey_id_)
  : passkey_id_(passkey_id_)
{}

const std::int32_t removeLoginPasskey::ID;

void removeLoginPasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeLoginPasskey");
    s.store_field("passkey_id", passkey_id_);
    s.store_class_end();
  }
}

removeSavedAnimation::removeSavedAnimation()
  : animation_()
{}

removeSavedAnimation::removeSavedAnimation(object_ptr<InputFile> &&animation_)
  : animation_(std::move(animation_))
{}

const std::int32_t removeSavedAnimation::ID;

void removeSavedAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeSavedAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

reorderActiveUsernames::reorderActiveUsernames()
  : usernames_()
{}

reorderActiveUsernames::reorderActiveUsernames(array<string> &&usernames_)
  : usernames_(std::move(usernames_))
{}

const std::int32_t reorderActiveUsernames::ID;

void reorderActiveUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderActiveUsernames");
    { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

replaceVideoChatRtmpUrl::replaceVideoChatRtmpUrl()
  : chat_id_()
{}

replaceVideoChatRtmpUrl::replaceVideoChatRtmpUrl(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t replaceVideoChatRtmpUrl::ID;

void replaceVideoChatRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replaceVideoChatRtmpUrl");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

requestQrCodeAuthentication::requestQrCodeAuthentication()
  : other_user_ids_()
{}

requestQrCodeAuthentication::requestQrCodeAuthentication(array<int53> &&other_user_ids_)
  : other_user_ids_(std::move(other_user_ids_))
{}

const std::int32_t requestQrCodeAuthentication::ID;

void requestQrCodeAuthentication::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestQrCodeAuthentication");
    { s.store_vector_begin("other_user_ids", other_user_ids_.size()); for (const auto &_value : other_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

resendLoginEmailAddressCode::resendLoginEmailAddressCode() {
}

const std::int32_t resendLoginEmailAddressCode::ID;

void resendLoginEmailAddressCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendLoginEmailAddressCode");
    s.store_class_end();
  }
}

resetInstalledBackgrounds::resetInstalledBackgrounds() {
}

const std::int32_t resetInstalledBackgrounds::ID;

void resetInstalledBackgrounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetInstalledBackgrounds");
    s.store_class_end();
  }
}

reuseStarSubscription::reuseStarSubscription()
  : subscription_id_()
{}

reuseStarSubscription::reuseStarSubscription(string const &subscription_id_)
  : subscription_id_(subscription_id_)
{}

const std::int32_t reuseStarSubscription::ID;

void reuseStarSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reuseStarSubscription");
    s.store_field("subscription_id", subscription_id_);
    s.store_class_end();
  }
}

searchPublicStoriesByTag::searchPublicStoriesByTag()
  : story_poster_chat_id_()
  , tag_()
  , offset_()
  , limit_()
{}

searchPublicStoriesByTag::searchPublicStoriesByTag(int53 story_poster_chat_id_, string const &tag_, string const &offset_, int32 limit_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , tag_(tag_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchPublicStoriesByTag::ID;

void searchPublicStoriesByTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicStoriesByTag");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("tag", tag_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchSavedMessages::searchSavedMessages()
  : saved_messages_topic_id_()
  , tag_()
  , query_()
  , from_message_id_()
  , offset_()
  , limit_()
{}

searchSavedMessages::searchSavedMessages(int53 saved_messages_topic_id_, object_ptr<ReactionType> &&tag_, string const &query_, int53 from_message_id_, int32 offset_, int32 limit_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , tag_(std::move(tag_))
  , query_(query_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchSavedMessages::ID;

void searchSavedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchSavedMessages");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_object_field("tag", static_cast<const BaseObject *>(tag_.get()));
    s.store_field("query", query_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchStickerSet::searchStickerSet()
  : name_()
  , ignore_cache_()
{}

searchStickerSet::searchStickerSet(string const &name_, bool ignore_cache_)
  : name_(name_)
  , ignore_cache_(ignore_cache_)
{}

const std::int32_t searchStickerSet::ID;

void searchStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchStickerSet");
    s.store_field("name", name_);
    s.store_field("ignore_cache", ignore_cache_);
    s.store_class_end();
  }
}

searchUserByToken::searchUserByToken()
  : token_()
{}

searchUserByToken::searchUserByToken(string const &token_)
  : token_(token_)
{}

const std::int32_t searchUserByToken::ID;

void searchUserByToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchUserByToken");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

sendCallLog::sendCallLog()
  : call_id_()
  , log_file_()
{}

sendCallLog::sendCallLog(object_ptr<InputCall> &&call_id_, object_ptr<InputFile> &&log_file_)
  : call_id_(std::move(call_id_))
  , log_file_(std::move(log_file_))
{}

const std::int32_t sendCallLog::ID;

void sendCallLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallLog");
    s.store_object_field("call_id", static_cast<const BaseObject *>(call_id_.get()));
    s.store_object_field("log_file", static_cast<const BaseObject *>(log_file_.get()));
    s.store_class_end();
  }
}

sendGroupCallMessage::sendGroupCallMessage()
  : group_call_id_()
  , text_()
  , paid_message_star_count_()
{}

sendGroupCallMessage::sendGroupCallMessage(int32 group_call_id_, object_ptr<formattedText> &&text_, int53 paid_message_star_count_)
  : group_call_id_(group_call_id_)
  , text_(std::move(text_))
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t sendGroupCallMessage::ID;

void sendGroupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendGroupCallMessage");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

sendTonCenterApiRequest::sendTonCenterApiRequest()
  : endpoint_()
  , type_()
{}

sendTonCenterApiRequest::sendTonCenterApiRequest(string const &endpoint_, object_ptr<TonCenterApiRequestType> &&type_)
  : endpoint_(endpoint_)
  , type_(std::move(type_))
{}

const std::int32_t sendTonCenterApiRequest::ID;

void sendTonCenterApiRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendTonCenterApiRequest");
    s.store_field("endpoint", endpoint_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

setAuthenticationPhoneNumber::setAuthenticationPhoneNumber()
  : phone_number_()
  , settings_()
{}

setAuthenticationPhoneNumber::setAuthenticationPhoneNumber(string const &phone_number_, object_ptr<phoneNumberAuthenticationSettings> &&settings_)
  : phone_number_(phone_number_)
  , settings_(std::move(settings_))
{}

const std::int32_t setAuthenticationPhoneNumber::ID;

void setAuthenticationPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAuthenticationPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setChatAvailableReactions::setChatAvailableReactions()
  : chat_id_()
  , available_reactions_()
{}

setChatAvailableReactions::setChatAvailableReactions(int53 chat_id_, object_ptr<ChatAvailableReactions> &&available_reactions_)
  : chat_id_(chat_id_)
  , available_reactions_(std::move(available_reactions_))
{}

const std::int32_t setChatAvailableReactions::ID;

void setChatAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatAvailableReactions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get()));
    s.store_class_end();
  }
}

setChatPaidMessageStarCount::setChatPaidMessageStarCount()
  : chat_id_()
  , paid_message_star_count_()
{}

setChatPaidMessageStarCount::setChatPaidMessageStarCount(int53 chat_id_, int53 paid_message_star_count_)
  : chat_id_(chat_id_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t setChatPaidMessageStarCount::ID;

void setChatPaidMessageStarCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatPaidMessageStarCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

setChatPhoto::setChatPhoto()
  : chat_id_()
  , photo_()
{}

setChatPhoto::setChatPhoto(int53 chat_id_, object_ptr<InputChatPhoto> &&photo_)
  : chat_id_(chat_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t setChatPhoto::ID;

void setChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatPhoto");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

setCommunityPermissions::setCommunityPermissions()
  : community_id_()
  , permissions_()
{}

setCommunityPermissions::setCommunityPermissions(int53 community_id_, object_ptr<communityPermissions> &&permissions_)
  : community_id_(community_id_)
  , permissions_(std::move(permissions_))
{}

const std::int32_t setCommunityPermissions::ID;

void setCommunityPermissions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCommunityPermissions");
    s.store_field("community_id", community_id_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_class_end();
  }
}

setCustomEmojiStickerSetThumbnail::setCustomEmojiStickerSetThumbnail()
  : name_()
  , custom_emoji_id_()
{}

setCustomEmojiStickerSetThumbnail::setCustomEmojiStickerSetThumbnail(string const &name_, int64 custom_emoji_id_)
  : name_(name_)
  , custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t setCustomEmojiStickerSetThumbnail::ID;

void setCustomEmojiStickerSetThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCustomEmojiStickerSetThumbnail");
    s.store_field("name", name_);
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

setCustomLanguagePack::setCustomLanguagePack()
  : info_()
  , strings_()
{}

setCustomLanguagePack::setCustomLanguagePack(object_ptr<languagePackInfo> &&info_, array<object_ptr<languagePackString>> &&strings_)
  : info_(std::move(info_))
  , strings_(std::move(strings_))
{}

const std::int32_t setCustomLanguagePack::ID;

void setCustomLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCustomLanguagePack");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

setCustomLanguagePackString::setCustomLanguagePackString()
  : language_pack_id_()
  , new_string_()
{}

setCustomLanguagePackString::setCustomLanguagePackString(string const &language_pack_id_, object_ptr<languagePackString> &&new_string_)
  : language_pack_id_(language_pack_id_)
  , new_string_(std::move(new_string_))
{}

const std::int32_t setCustomLanguagePackString::ID;

void setCustomLanguagePackString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCustomLanguagePackString");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_object_field("new_string", static_cast<const BaseObject *>(new_string_.get()));
    s.store_class_end();
  }
}

setGroupCallPaidMessageStarCount::setGroupCallPaidMessageStarCount()
  : group_call_id_()
  , paid_message_star_count_()
{}

setGroupCallPaidMessageStarCount::setGroupCallPaidMessageStarCount(int32 group_call_id_, int53 paid_message_star_count_)
  : group_call_id_(group_call_id_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t setGroupCallPaidMessageStarCount::ID;

void setGroupCallPaidMessageStarCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGroupCallPaidMessageStarCount");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

setMainProfileTab::setMainProfileTab()
  : main_profile_tab_()
{}

setMainProfileTab::setMainProfileTab(object_ptr<ProfileTab> &&main_profile_tab_)
  : main_profile_tab_(std::move(main_profile_tab_))
{}

const std::int32_t setMainProfileTab::ID;

void setMainProfileTab::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMainProfileTab");
    s.store_object_field("main_profile_tab", static_cast<const BaseObject *>(main_profile_tab_.get()));
    s.store_class_end();
  }
}

setPaidMessageReactionType::setPaidMessageReactionType()
  : chat_id_()
  , message_id_()
  , type_()
{}

setPaidMessageReactionType::setPaidMessageReactionType(int53 chat_id_, int53 message_id_, object_ptr<PaidReactionType> &&type_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , type_(std::move(type_))
{}

const std::int32_t setPaidMessageReactionType::ID;

void setPaidMessageReactionType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPaidMessageReactionType");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

setPassword::setPassword()
  : old_password_()
  , new_password_()
  , new_hint_()
  , set_recovery_email_address_()
  , new_recovery_email_address_()
{}

setPassword::setPassword(string const &old_password_, string const &new_password_, string const &new_hint_, bool set_recovery_email_address_, string const &new_recovery_email_address_)
  : old_password_(old_password_)
  , new_password_(new_password_)
  , new_hint_(new_hint_)
  , set_recovery_email_address_(set_recovery_email_address_)
  , new_recovery_email_address_(new_recovery_email_address_)
{}

const std::int32_t setPassword::ID;

void setPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPassword");
    s.store_field("old_password", "[REDACTED]");
    s.store_field("new_password", "[REDACTED]");
    s.store_field("new_hint", new_hint_);
    s.store_field("set_recovery_email_address", set_recovery_email_address_);
    s.store_field("new_recovery_email_address", new_recovery_email_address_);
    s.store_class_end();
  }
}

setReadDatePrivacySettings::setReadDatePrivacySettings()
  : settings_()
{}

setReadDatePrivacySettings::setReadDatePrivacySettings(object_ptr<readDatePrivacySettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t setReadDatePrivacySettings::ID;

void setReadDatePrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setReadDatePrivacySettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setScopeNotificationSettings::setScopeNotificationSettings()
  : scope_()
  , notification_settings_()
{}

setScopeNotificationSettings::setScopeNotificationSettings(object_ptr<NotificationSettingsScope> &&scope_, object_ptr<scopeNotificationSettings> &&notification_settings_)
  : scope_(std::move(scope_))
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t setScopeNotificationSettings::ID;

void setScopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setScopeNotificationSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

setStickerEmojis::setStickerEmojis()
  : sticker_()
  , emojis_()
{}

setStickerEmojis::setStickerEmojis(object_ptr<InputFile> &&sticker_, string const &emojis_)
  : sticker_(std::move(sticker_))
  , emojis_(emojis_)
{}

const std::int32_t setStickerEmojis::ID;

void setStickerEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerEmojis");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("emojis", emojis_);
    s.store_class_end();
  }
}

setUserNote::setUserNote()
  : user_id_()
  , note_()
{}

setUserNote::setUserNote(int53 user_id_, object_ptr<formattedText> &&note_)
  : user_id_(user_id_)
  , note_(std::move(note_))
{}

const std::int32_t setUserNote::ID;

void setUserNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUserNote");
    s.store_field("user_id", user_id_);
    s.store_object_field("note", static_cast<const BaseObject *>(note_.get()));
    s.store_class_end();
  }
}

setVideoChatDefaultParticipant::setVideoChatDefaultParticipant()
  : chat_id_()
  , default_participant_id_()
{}

setVideoChatDefaultParticipant::setVideoChatDefaultParticipant(int53 chat_id_, object_ptr<MessageSender> &&default_participant_id_)
  : chat_id_(chat_id_)
  , default_participant_id_(std::move(default_participant_id_))
{}

const std::int32_t setVideoChatDefaultParticipant::ID;

void setVideoChatDefaultParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setVideoChatDefaultParticipant");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("default_participant_id", static_cast<const BaseObject *>(default_participant_id_.get()));
    s.store_class_end();
  }
}

startLiveStory::startLiveStory()
  : chat_id_()
  , privacy_settings_()
  , protect_content_()
  , is_rtmp_stream_()
  , enable_messages_()
  , paid_message_star_count_()
{}

startLiveStory::startLiveStory(int53 chat_id_, object_ptr<StoryPrivacySettings> &&privacy_settings_, bool protect_content_, bool is_rtmp_stream_, bool enable_messages_, int53 paid_message_star_count_)
  : chat_id_(chat_id_)
  , privacy_settings_(std::move(privacy_settings_))
  , protect_content_(protect_content_)
  , is_rtmp_stream_(is_rtmp_stream_)
  , enable_messages_(enable_messages_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t startLiveStory::ID;

void startLiveStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startLiveStory");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("privacy_settings", static_cast<const BaseObject *>(privacy_settings_.get()));
    s.store_field("protect_content", protect_content_);
    s.store_field("is_rtmp_stream", is_rtmp_stream_);
    s.store_field("enable_messages", enable_messages_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

startScheduledVideoChat::startScheduledVideoChat()
  : group_call_id_()
{}

startScheduledVideoChat::startScheduledVideoChat(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t startScheduledVideoChat::ID;

void startScheduledVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startScheduledVideoChat");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

testCallString::testCallString()
  : x_()
{}

testCallString::testCallString(string const &x_)
  : x_(x_)
{}

const std::int32_t testCallString::ID;

void testCallString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallString");
    s.store_field("x", x_);
    s.store_class_end();
  }
}

testProxy::testProxy()
  : proxy_()
  , dc_id_()
  , timeout_()
{}

testProxy::testProxy(object_ptr<proxy> &&proxy_, int32 dc_id_, double timeout_)
  : proxy_(std::move(proxy_))
  , dc_id_(dc_id_)
  , timeout_(timeout_)
{}

const std::int32_t testProxy::ID;

void testProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testProxy");
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_field("dc_id", dc_id_);
    s.store_field("timeout", timeout_);
    s.store_class_end();
  }
}

toggleChatIsPinned::toggleChatIsPinned()
  : chat_list_()
  , chat_id_()
  , is_pinned_()
{}

toggleChatIsPinned::toggleChatIsPinned(object_ptr<ChatList> &&chat_list_, int53 chat_id_, bool is_pinned_)
  : chat_list_(std::move(chat_list_))
  , chat_id_(chat_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t toggleChatIsPinned::ID;

void toggleChatIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatIsPinned");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

toggleCommunityMemberIsBanned::toggleCommunityMemberIsBanned()
  : community_id_()
  , member_id_()
  , is_banned_()
{}

toggleCommunityMemberIsBanned::toggleCommunityMemberIsBanned(int53 community_id_, object_ptr<MessageSender> &&member_id_, bool is_banned_)
  : community_id_(community_id_)
  , member_id_(std::move(member_id_))
  , is_banned_(is_banned_)
{}

const std::int32_t toggleCommunityMemberIsBanned::ID;

void toggleCommunityMemberIsBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleCommunityMemberIsBanned");
    s.store_field("community_id", community_id_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_field("is_banned", is_banned_);
    s.store_class_end();
  }
}

toggleGroupCallParticipantIsHandRaised::toggleGroupCallParticipantIsHandRaised()
  : group_call_id_()
  , participant_id_()
  , is_hand_raised_()
{}

toggleGroupCallParticipantIsHandRaised::toggleGroupCallParticipantIsHandRaised(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, bool is_hand_raised_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , is_hand_raised_(is_hand_raised_)
{}

const std::int32_t toggleGroupCallParticipantIsHandRaised::ID;

void toggleGroupCallParticipantIsHandRaised::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallParticipantIsHandRaised");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_hand_raised", is_hand_raised_);
    s.store_class_end();
  }
}

toggleGroupCallScreenSharingIsPaused::toggleGroupCallScreenSharingIsPaused()
  : group_call_id_()
  , is_paused_()
{}

toggleGroupCallScreenSharingIsPaused::toggleGroupCallScreenSharingIsPaused(int32 group_call_id_, bool is_paused_)
  : group_call_id_(group_call_id_)
  , is_paused_(is_paused_)
{}

const std::int32_t toggleGroupCallScreenSharingIsPaused::ID;

void toggleGroupCallScreenSharingIsPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallScreenSharingIsPaused");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

toggleSupergroupCanHaveSponsoredMessages::toggleSupergroupCanHaveSponsoredMessages()
  : supergroup_id_()
  , can_have_sponsored_messages_()
{}

toggleSupergroupCanHaveSponsoredMessages::toggleSupergroupCanHaveSponsoredMessages(int53 supergroup_id_, bool can_have_sponsored_messages_)
  : supergroup_id_(supergroup_id_)
  , can_have_sponsored_messages_(can_have_sponsored_messages_)
{}

const std::int32_t toggleSupergroupCanHaveSponsoredMessages::ID;

void toggleSupergroupCanHaveSponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupCanHaveSponsoredMessages");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("can_have_sponsored_messages", can_have_sponsored_messages_);
    s.store_class_end();
  }
}

viewTrendingStickerSets::viewTrendingStickerSets()
  : sticker_set_ids_()
{}

viewTrendingStickerSets::viewTrendingStickerSets(array<int64> &&sticker_set_ids_)
  : sticker_set_ids_(std::move(sticker_set_ids_))
{}

const std::int32_t viewTrendingStickerSets::ID;

void viewTrendingStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewTrendingStickerSets");
    { s.store_vector_begin("sticker_set_ids", sticker_set_ids_.size()); for (const auto &_value : sticker_set_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
