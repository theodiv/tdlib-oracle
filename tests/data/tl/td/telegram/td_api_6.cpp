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


availableGift::availableGift()
  : gift_()
  , resale_count_()
  , min_resale_star_count_()
  , title_()
{}

availableGift::availableGift(object_ptr<gift> &&gift_, int32 resale_count_, int53 min_resale_star_count_, string const &title_)
  : gift_(std::move(gift_))
  , resale_count_(resale_count_)
  , min_resale_star_count_(min_resale_star_count_)
  , title_(title_)
{}

const std::int32_t availableGift::ID;

void availableGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("resale_count", resale_count_);
    s.store_field("min_resale_star_count", min_resale_star_count_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

availableGifts::availableGifts()
  : gifts_()
{}

availableGifts::availableGifts(array<object_ptr<availableGift>> &&gifts_)
  : gifts_(std::move(gifts_))
{}

const std::int32_t availableGifts::ID;

void availableGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableGifts");
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

botWriteAccessAllowReasonConnectedWebsite::botWriteAccessAllowReasonConnectedWebsite()
  : domain_name_()
{}

botWriteAccessAllowReasonConnectedWebsite::botWriteAccessAllowReasonConnectedWebsite(string const &domain_name_)
  : domain_name_(domain_name_)
{}

const std::int32_t botWriteAccessAllowReasonConnectedWebsite::ID;

void botWriteAccessAllowReasonConnectedWebsite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botWriteAccessAllowReasonConnectedWebsite");
    s.store_field("domain_name", domain_name_);
    s.store_class_end();
  }
}

botWriteAccessAllowReasonAddedToAttachmentMenu::botWriteAccessAllowReasonAddedToAttachmentMenu() {
}

const std::int32_t botWriteAccessAllowReasonAddedToAttachmentMenu::ID;

void botWriteAccessAllowReasonAddedToAttachmentMenu::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botWriteAccessAllowReasonAddedToAttachmentMenu");
    s.store_class_end();
  }
}

botWriteAccessAllowReasonLaunchedWebApp::botWriteAccessAllowReasonLaunchedWebApp()
  : web_app_()
{}

botWriteAccessAllowReasonLaunchedWebApp::botWriteAccessAllowReasonLaunchedWebApp(object_ptr<webApp> &&web_app_)
  : web_app_(std::move(web_app_))
{}

const std::int32_t botWriteAccessAllowReasonLaunchedWebApp::ID;

void botWriteAccessAllowReasonLaunchedWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botWriteAccessAllowReasonLaunchedWebApp");
    s.store_object_field("web_app", static_cast<const BaseObject *>(web_app_.get()));
    s.store_class_end();
  }
}

botWriteAccessAllowReasonAcceptedRequest::botWriteAccessAllowReasonAcceptedRequest() {
}

const std::int32_t botWriteAccessAllowReasonAcceptedRequest::ID;

void botWriteAccessAllowReasonAcceptedRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botWriteAccessAllowReasonAcceptedRequest");
    s.store_class_end();
  }
}

builtInThemeClassic::builtInThemeClassic() {
}

const std::int32_t builtInThemeClassic::ID;

void builtInThemeClassic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "builtInThemeClassic");
    s.store_class_end();
  }
}

builtInThemeDay::builtInThemeDay() {
}

const std::int32_t builtInThemeDay::ID;

void builtInThemeDay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "builtInThemeDay");
    s.store_class_end();
  }
}

builtInThemeNight::builtInThemeNight() {
}

const std::int32_t builtInThemeNight::ID;

void builtInThemeNight::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "builtInThemeNight");
    s.store_class_end();
  }
}

builtInThemeTinted::builtInThemeTinted() {
}

const std::int32_t builtInThemeTinted::ID;

void builtInThemeTinted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "builtInThemeTinted");
    s.store_class_end();
  }
}

builtInThemeArctic::builtInThemeArctic() {
}

const std::int32_t builtInThemeArctic::ID;

void builtInThemeArctic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "builtInThemeArctic");
    s.store_class_end();
  }
}

businessChatLinkInfo::businessChatLinkInfo()
  : chat_id_()
  , text_()
{}

businessChatLinkInfo::businessChatLinkInfo(int53 chat_id_, object_ptr<formattedText> &&text_)
  : chat_id_(chat_id_)
  , text_(std::move(text_))
{}

const std::int32_t businessChatLinkInfo::ID;

void businessChatLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessChatLinkInfo");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

businessConnectedBot::businessConnectedBot()
  : bot_user_id_()
  , recipients_()
  , rights_()
{}

businessConnectedBot::businessConnectedBot(int53 bot_user_id_, object_ptr<businessRecipients> &&recipients_, object_ptr<businessBotRights> &&rights_)
  : bot_user_id_(bot_user_id_)
  , recipients_(std::move(recipients_))
  , rights_(std::move(rights_))
{}

const std::int32_t businessConnectedBot::ID;

void businessConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessConnectedBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get()));
    s.store_class_end();
  }
}

canPostStoryResultOk::canPostStoryResultOk()
  : story_count_()
{}

canPostStoryResultOk::canPostStoryResultOk(int32 story_count_)
  : story_count_(story_count_)
{}

const std::int32_t canPostStoryResultOk::ID;

void canPostStoryResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultOk");
    s.store_field("story_count", story_count_);
    s.store_class_end();
  }
}

canPostStoryResultPremiumNeeded::canPostStoryResultPremiumNeeded() {
}

const std::int32_t canPostStoryResultPremiumNeeded::ID;

void canPostStoryResultPremiumNeeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultPremiumNeeded");
    s.store_class_end();
  }
}

canPostStoryResultBoostNeeded::canPostStoryResultBoostNeeded() {
}

const std::int32_t canPostStoryResultBoostNeeded::ID;

void canPostStoryResultBoostNeeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultBoostNeeded");
    s.store_class_end();
  }
}

canPostStoryResultActiveStoryLimitExceeded::canPostStoryResultActiveStoryLimitExceeded() {
}

const std::int32_t canPostStoryResultActiveStoryLimitExceeded::ID;

void canPostStoryResultActiveStoryLimitExceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultActiveStoryLimitExceeded");
    s.store_class_end();
  }
}

canPostStoryResultWeeklyLimitExceeded::canPostStoryResultWeeklyLimitExceeded()
  : retry_after_()
{}

canPostStoryResultWeeklyLimitExceeded::canPostStoryResultWeeklyLimitExceeded(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t canPostStoryResultWeeklyLimitExceeded::ID;

void canPostStoryResultWeeklyLimitExceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultWeeklyLimitExceeded");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

canPostStoryResultMonthlyLimitExceeded::canPostStoryResultMonthlyLimitExceeded()
  : retry_after_()
{}

canPostStoryResultMonthlyLimitExceeded::canPostStoryResultMonthlyLimitExceeded(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t canPostStoryResultMonthlyLimitExceeded::ID;

void canPostStoryResultMonthlyLimitExceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultMonthlyLimitExceeded");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

canPostStoryResultLiveStoryIsActive::canPostStoryResultLiveStoryIsActive()
  : story_id_()
{}

canPostStoryResultLiveStoryIsActive::canPostStoryResultLiveStoryIsActive(int32 story_id_)
  : story_id_(story_id_)
{}

const std::int32_t canPostStoryResultLiveStoryIsActive::ID;

void canPostStoryResultLiveStoryIsActive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultLiveStoryIsActive");
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

chatActionBarReportSpam::chatActionBarReportSpam()
  : can_unarchive_()
{}

chatActionBarReportSpam::chatActionBarReportSpam(bool can_unarchive_)
  : can_unarchive_(can_unarchive_)
{}

const std::int32_t chatActionBarReportSpam::ID;

void chatActionBarReportSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarReportSpam");
    s.store_field("can_unarchive", can_unarchive_);
    s.store_class_end();
  }
}

chatActionBarInviteMembers::chatActionBarInviteMembers() {
}

const std::int32_t chatActionBarInviteMembers::ID;

void chatActionBarInviteMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarInviteMembers");
    s.store_class_end();
  }
}

chatActionBarReportAddBlock::chatActionBarReportAddBlock()
  : can_unarchive_()
  , account_info_()
{}

chatActionBarReportAddBlock::chatActionBarReportAddBlock(bool can_unarchive_, object_ptr<accountInfo> &&account_info_)
  : can_unarchive_(can_unarchive_)
  , account_info_(std::move(account_info_))
{}

const std::int32_t chatActionBarReportAddBlock::ID;

void chatActionBarReportAddBlock::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarReportAddBlock");
    s.store_field("can_unarchive", can_unarchive_);
    s.store_object_field("account_info", static_cast<const BaseObject *>(account_info_.get()));
    s.store_class_end();
  }
}

chatActionBarAddContact::chatActionBarAddContact() {
}

const std::int32_t chatActionBarAddContact::ID;

void chatActionBarAddContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarAddContact");
    s.store_class_end();
  }
}

chatActionBarSharePhoneNumber::chatActionBarSharePhoneNumber() {
}

const std::int32_t chatActionBarSharePhoneNumber::ID;

void chatActionBarSharePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarSharePhoneNumber");
    s.store_class_end();
  }
}

chatActionBarJoinRequest::chatActionBarJoinRequest()
  : title_()
  , is_channel_()
  , request_date_()
{}

chatActionBarJoinRequest::chatActionBarJoinRequest(string const &title_, bool is_channel_, int32 request_date_)
  : title_(title_)
  , is_channel_(is_channel_)
  , request_date_(request_date_)
{}

const std::int32_t chatActionBarJoinRequest::ID;

void chatActionBarJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarJoinRequest");
    s.store_field("title", title_);
    s.store_field("is_channel", is_channel_);
    s.store_field("request_date", request_date_);
    s.store_class_end();
  }
}

chatBoostLevelFeatures::chatBoostLevelFeatures()
  : level_()
  , story_per_day_count_()
  , custom_emoji_reaction_count_()
  , title_color_count_()
  , profile_accent_color_count_()
  , can_set_profile_background_custom_emoji_()
  , accent_color_count_()
  , can_set_background_custom_emoji_()
  , can_set_emoji_status_()
  , chat_theme_background_count_()
  , can_set_custom_background_()
  , can_set_custom_emoji_sticker_set_()
  , can_enable_automatic_translation_()
  , can_recognize_speech_()
  , can_disable_sponsored_messages_()
{}

chatBoostLevelFeatures::chatBoostLevelFeatures(int32 level_, int32 story_per_day_count_, int32 custom_emoji_reaction_count_, int32 title_color_count_, int32 profile_accent_color_count_, bool can_set_profile_background_custom_emoji_, int32 accent_color_count_, bool can_set_background_custom_emoji_, bool can_set_emoji_status_, int32 chat_theme_background_count_, bool can_set_custom_background_, bool can_set_custom_emoji_sticker_set_, bool can_enable_automatic_translation_, bool can_recognize_speech_, bool can_disable_sponsored_messages_)
  : level_(level_)
  , story_per_day_count_(story_per_day_count_)
  , custom_emoji_reaction_count_(custom_emoji_reaction_count_)
  , title_color_count_(title_color_count_)
  , profile_accent_color_count_(profile_accent_color_count_)
  , can_set_profile_background_custom_emoji_(can_set_profile_background_custom_emoji_)
  , accent_color_count_(accent_color_count_)
  , can_set_background_custom_emoji_(can_set_background_custom_emoji_)
  , can_set_emoji_status_(can_set_emoji_status_)
  , chat_theme_background_count_(chat_theme_background_count_)
  , can_set_custom_background_(can_set_custom_background_)
  , can_set_custom_emoji_sticker_set_(can_set_custom_emoji_sticker_set_)
  , can_enable_automatic_translation_(can_enable_automatic_translation_)
  , can_recognize_speech_(can_recognize_speech_)
  , can_disable_sponsored_messages_(can_disable_sponsored_messages_)
{}

const std::int32_t chatBoostLevelFeatures::ID;

void chatBoostLevelFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostLevelFeatures");
    s.store_field("level", level_);
    s.store_field("story_per_day_count", story_per_day_count_);
    s.store_field("custom_emoji_reaction_count", custom_emoji_reaction_count_);
    s.store_field("title_color_count", title_color_count_);
    s.store_field("profile_accent_color_count", profile_accent_color_count_);
    s.store_field("can_set_profile_background_custom_emoji", can_set_profile_background_custom_emoji_);
    s.store_field("accent_color_count", accent_color_count_);
    s.store_field("can_set_background_custom_emoji", can_set_background_custom_emoji_);
    s.store_field("can_set_emoji_status", can_set_emoji_status_);
    s.store_field("chat_theme_background_count", chat_theme_background_count_);
    s.store_field("can_set_custom_background", can_set_custom_background_);
    s.store_field("can_set_custom_emoji_sticker_set", can_set_custom_emoji_sticker_set_);
    s.store_field("can_enable_automatic_translation", can_enable_automatic_translation_);
    s.store_field("can_recognize_speech", can_recognize_speech_);
    s.store_field("can_disable_sponsored_messages", can_disable_sponsored_messages_);
    s.store_class_end();
  }
}

chatFolderInviteLinks::chatFolderInviteLinks()
  : invite_links_()
{}

chatFolderInviteLinks::chatFolderInviteLinks(array<object_ptr<chatFolderInviteLink>> &&invite_links_)
  : invite_links_(std::move(invite_links_))
{}

const std::int32_t chatFolderInviteLinks::ID;

void chatFolderInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderInviteLinks");
    { s.store_vector_begin("invite_links", invite_links_.size()); for (const auto &_value : invite_links_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatJoinResultSuccess::chatJoinResultSuccess()
  : chat_id_()
{}

chatJoinResultSuccess::chatJoinResultSuccess(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t chatJoinResultSuccess::ID;

void chatJoinResultSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinResultSuccess");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

chatJoinResultRequestSent::chatJoinResultRequestSent() {
}

const std::int32_t chatJoinResultRequestSent::ID;

void chatJoinResultRequestSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinResultRequestSent");
    s.store_class_end();
  }
}

chatJoinResultGuardBotApprovalRequired::chatJoinResultGuardBotApprovalRequired()
  : bot_user_id_()
  , query_id_()
{}

chatJoinResultGuardBotApprovalRequired::chatJoinResultGuardBotApprovalRequired(int53 bot_user_id_, int64 query_id_)
  : bot_user_id_(bot_user_id_)
  , query_id_(query_id_)
{}

const std::int32_t chatJoinResultGuardBotApprovalRequired::ID;

void chatJoinResultGuardBotApprovalRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinResultGuardBotApprovalRequired");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("query_id", query_id_);
    s.store_class_end();
  }
}

chatJoinResultDeclined::chatJoinResultDeclined() {
}

const std::int32_t chatJoinResultDeclined::ID;

void chatJoinResultDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinResultDeclined");
    s.store_class_end();
  }
}

chatPhotos::chatPhotos()
  : total_count_()
  , photos_()
{}

chatPhotos::chatPhotos(int32 total_count_, array<object_ptr<chatPhoto>> &&photos_)
  : total_count_(total_count_)
  , photos_(std::move(photos_))
{}

const std::int32_t chatPhotos::ID;

void chatPhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotos");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("photos", photos_.size()); for (const auto &_value : photos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatRevenueAmount::chatRevenueAmount()
  : cryptocurrency_()
  , total_amount_()
  , balance_amount_()
  , available_amount_()
  , withdrawal_enabled_()
{}

chatRevenueAmount::chatRevenueAmount(string const &cryptocurrency_, int64 total_amount_, int64 balance_amount_, int64 available_amount_, bool withdrawal_enabled_)
  : cryptocurrency_(cryptocurrency_)
  , total_amount_(total_amount_)
  , balance_amount_(balance_amount_)
  , available_amount_(available_amount_)
  , withdrawal_enabled_(withdrawal_enabled_)
{}

const std::int32_t chatRevenueAmount::ID;

void chatRevenueAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueAmount");
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("balance_amount", balance_amount_);
    s.store_field("available_amount", available_amount_);
    s.store_field("withdrawal_enabled", withdrawal_enabled_);
    s.store_class_end();
  }
}

checkStickerSetNameResultOk::checkStickerSetNameResultOk() {
}

const std::int32_t checkStickerSetNameResultOk::ID;

void checkStickerSetNameResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetNameResultOk");
    s.store_class_end();
  }
}

checkStickerSetNameResultNameInvalid::checkStickerSetNameResultNameInvalid() {
}

const std::int32_t checkStickerSetNameResultNameInvalid::ID;

void checkStickerSetNameResultNameInvalid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetNameResultNameInvalid");
    s.store_class_end();
  }
}

checkStickerSetNameResultNameOccupied::checkStickerSetNameResultNameOccupied() {
}

const std::int32_t checkStickerSetNameResultNameOccupied::ID;

void checkStickerSetNameResultNameOccupied::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetNameResultNameOccupied");
    s.store_class_end();
  }
}

community::community()
  : id_()
  , have_access_()
  , name_()
  , photo_()
  , date_()
  , status_()
  , permissions_()
  , are_chats_collapsed_()
{}

community::community(int53 id_, bool have_access_, string const &name_, object_ptr<chatPhotoInfo> &&photo_, int32 date_, object_ptr<CommunityMemberStatus> &&status_, object_ptr<communityPermissions> &&permissions_, bool are_chats_collapsed_)
  : id_(id_)
  , have_access_(have_access_)
  , name_(name_)
  , photo_(std::move(photo_))
  , date_(date_)
  , status_(std::move(status_))
  , permissions_(std::move(permissions_))
  , are_chats_collapsed_(are_chats_collapsed_)
{}

const std::int32_t community::ID;

void community::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "community");
    s.store_field("id", id_);
    s.store_field("have_access", have_access_);
    s.store_field("name", name_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("date", date_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_field("are_chats_collapsed", are_chats_collapsed_);
    s.store_class_end();
  }
}

communityMemberStatusCreator::communityMemberStatusCreator() {
}

const std::int32_t communityMemberStatusCreator::ID;

void communityMemberStatusCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityMemberStatusCreator");
    s.store_class_end();
  }
}

communityMemberStatusAdministrator::communityMemberStatusAdministrator()
  : can_be_edited_()
  , rights_()
{}

communityMemberStatusAdministrator::communityMemberStatusAdministrator(bool can_be_edited_, object_ptr<communityAdministratorRights> &&rights_)
  : can_be_edited_(can_be_edited_)
  , rights_(std::move(rights_))
{}

const std::int32_t communityMemberStatusAdministrator::ID;

void communityMemberStatusAdministrator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityMemberStatusAdministrator");
    s.store_field("can_be_edited", can_be_edited_);
    s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get()));
    s.store_class_end();
  }
}

communityMemberStatusMember::communityMemberStatusMember() {
}

const std::int32_t communityMemberStatusMember::ID;

void communityMemberStatusMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityMemberStatusMember");
    s.store_class_end();
  }
}

communityMemberStatusLeft::communityMemberStatusLeft() {
}

const std::int32_t communityMemberStatusLeft::ID;

void communityMemberStatusLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityMemberStatusLeft");
    s.store_class_end();
  }
}

communityMemberStatusBanned::communityMemberStatusBanned() {
}

const std::int32_t communityMemberStatusBanned::ID;

void communityMemberStatusBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityMemberStatusBanned");
    s.store_class_end();
  }
}

customRequestResult::customRequestResult()
  : result_()
{}

customRequestResult::customRequestResult(string const &result_)
  : result_(result_)
{}

const std::int32_t customRequestResult::ID;

void customRequestResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "customRequestResult");
    s.store_field("result", result_);
    s.store_class_end();
  }
}

datedFile::datedFile()
  : file_()
  , date_()
{}

datedFile::datedFile(object_ptr<file> &&file_, int32 date_)
  : file_(std::move(file_))
  , date_(date_)
{}

const std::int32_t datedFile::ID;

void datedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "datedFile");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

emailAddressAuthenticationCodeInfo::emailAddressAuthenticationCodeInfo()
  : email_address_pattern_()
  , length_()
{}

emailAddressAuthenticationCodeInfo::emailAddressAuthenticationCodeInfo(string const &email_address_pattern_, int32 length_)
  : email_address_pattern_(email_address_pattern_)
  , length_(length_)
{}

const std::int32_t emailAddressAuthenticationCodeInfo::ID;

void emailAddressAuthenticationCodeInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressAuthenticationCodeInfo");
    s.store_field("email_address_pattern", email_address_pattern_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

emojiStatus::emojiStatus()
  : type_()
  , expiration_date_()
{}

emojiStatus::emojiStatus(object_ptr<EmojiStatusType> &&type_, int32 expiration_date_)
  : type_(std::move(type_))
  , expiration_date_(expiration_date_)
{}

const std::int32_t emojiStatus::ID;

void emojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatus");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("expiration_date", expiration_date_);
    s.store_class_end();
  }
}

firebaseDeviceVerificationParametersSafetyNet::firebaseDeviceVerificationParametersSafetyNet()
  : nonce_()
{}

firebaseDeviceVerificationParametersSafetyNet::firebaseDeviceVerificationParametersSafetyNet(bytes const &nonce_)
  : nonce_(std::move(nonce_))
{}

const std::int32_t firebaseDeviceVerificationParametersSafetyNet::ID;

void firebaseDeviceVerificationParametersSafetyNet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "firebaseDeviceVerificationParametersSafetyNet");
    s.store_bytes_field("nonce", nonce_);
    s.store_class_end();
  }
}

firebaseDeviceVerificationParametersPlayIntegrity::firebaseDeviceVerificationParametersPlayIntegrity()
  : nonce_()
  , cloud_project_number_()
{}

firebaseDeviceVerificationParametersPlayIntegrity::firebaseDeviceVerificationParametersPlayIntegrity(string const &nonce_, int64 cloud_project_number_)
  : nonce_(nonce_)
  , cloud_project_number_(cloud_project_number_)
{}

const std::int32_t firebaseDeviceVerificationParametersPlayIntegrity::ID;

void firebaseDeviceVerificationParametersPlayIntegrity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "firebaseDeviceVerificationParametersPlayIntegrity");
    s.store_field("nonce", nonce_);
    s.store_field("cloud_project_number", cloud_project_number_);
    s.store_class_end();
  }
}

foundAffiliateProgram::foundAffiliateProgram()
  : bot_user_id_()
  , info_()
{}

foundAffiliateProgram::foundAffiliateProgram(int53 bot_user_id_, object_ptr<affiliateProgramInfo> &&info_)
  : bot_user_id_(bot_user_id_)
  , info_(std::move(info_))
{}

const std::int32_t foundAffiliateProgram::ID;

void foundAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundAffiliateProgram");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

foundPositions::foundPositions()
  : total_count_()
  , positions_()
{}

foundPositions::foundPositions(int32 total_count_, array<int32> &&positions_)
  : total_count_(total_count_)
  , positions_(std::move(positions_))
{}

const std::int32_t foundPositions::ID;

void foundPositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundPositions");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

foundWebApp::foundWebApp()
  : web_app_()
  , request_write_access_()
  , skip_confirmation_()
{}

foundWebApp::foundWebApp(object_ptr<webApp> &&web_app_, bool request_write_access_, bool skip_confirmation_)
  : web_app_(std::move(web_app_))
  , request_write_access_(request_write_access_)
  , skip_confirmation_(skip_confirmation_)
{}

const std::int32_t foundWebApp::ID;

void foundWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundWebApp");
    s.store_object_field("web_app", static_cast<const BaseObject *>(web_app_.get()));
    s.store_field("request_write_access", request_write_access_);
    s.store_field("skip_confirmation", skip_confirmation_);
    s.store_class_end();
  }
}

giftPurchaseOfferStatePending::giftPurchaseOfferStatePending() {
}

const std::int32_t giftPurchaseOfferStatePending::ID;

void giftPurchaseOfferStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftPurchaseOfferStatePending");
    s.store_class_end();
  }
}

giftPurchaseOfferStateAccepted::giftPurchaseOfferStateAccepted() {
}

const std::int32_t giftPurchaseOfferStateAccepted::ID;

void giftPurchaseOfferStateAccepted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftPurchaseOfferStateAccepted");
    s.store_class_end();
  }
}

giftPurchaseOfferStateRejected::giftPurchaseOfferStateRejected() {
}

const std::int32_t giftPurchaseOfferStateRejected::ID;

void giftPurchaseOfferStateRejected::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftPurchaseOfferStateRejected");
    s.store_class_end();
  }
}

groupCallMessageLevel::groupCallMessageLevel()
  : min_star_count_()
  , pin_duration_()
  , max_text_length_()
  , max_custom_emoji_count_()
  , first_color_()
  , second_color_()
  , background_color_()
{}

groupCallMessageLevel::groupCallMessageLevel(int53 min_star_count_, int32 pin_duration_, int32 max_text_length_, int32 max_custom_emoji_count_, int32 first_color_, int32 second_color_, int32 background_color_)
  : min_star_count_(min_star_count_)
  , pin_duration_(pin_duration_)
  , max_text_length_(max_text_length_)
  , max_custom_emoji_count_(max_custom_emoji_count_)
  , first_color_(first_color_)
  , second_color_(second_color_)
  , background_color_(background_color_)
{}

const std::int32_t groupCallMessageLevel::ID;

void groupCallMessageLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallMessageLevel");
    s.store_field("min_star_count", min_star_count_);
    s.store_field("pin_duration", pin_duration_);
    s.store_field("max_text_length", max_text_length_);
    s.store_field("max_custom_emoji_count", max_custom_emoji_count_);
    s.store_field("first_color", first_color_);
    s.store_field("second_color", second_color_);
    s.store_field("background_color", background_color_);
    s.store_class_end();
  }
}

groupCallRecentSpeaker::groupCallRecentSpeaker()
  : participant_id_()
  , is_speaking_()
{}

groupCallRecentSpeaker::groupCallRecentSpeaker(object_ptr<MessageSender> &&participant_id_, bool is_speaking_)
  : participant_id_(std::move(participant_id_))
  , is_speaking_(is_speaking_)
{}

const std::int32_t groupCallRecentSpeaker::ID;

void groupCallRecentSpeaker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallRecentSpeaker");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_speaking", is_speaking_);
    s.store_class_end();
  }
}

groupCallVideoQualityThumbnail::groupCallVideoQualityThumbnail() {
}

const std::int32_t groupCallVideoQualityThumbnail::ID;

void groupCallVideoQualityThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoQualityThumbnail");
    s.store_class_end();
  }
}

groupCallVideoQualityMedium::groupCallVideoQualityMedium() {
}

const std::int32_t groupCallVideoQualityMedium::ID;

void groupCallVideoQualityMedium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoQualityMedium");
    s.store_class_end();
  }
}

groupCallVideoQualityFull::groupCallVideoQualityFull() {
}

const std::int32_t groupCallVideoQualityFull::ID;

void groupCallVideoQualityFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoQualityFull");
    s.store_class_end();
  }
}

inputInvoiceMessage::inputInvoiceMessage()
  : chat_id_()
  , message_id_()
{}

inputInvoiceMessage::inputInvoiceMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t inputInvoiceMessage::ID;

void inputInvoiceMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

inputInvoiceName::inputInvoiceName()
  : name_()
{}

inputInvoiceName::inputInvoiceName(string const &name_)
  : name_(name_)
{}

const std::int32_t inputInvoiceName::ID;

void inputInvoiceName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceName");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

inputInvoiceTelegram::inputInvoiceTelegram()
  : purpose_()
{}

inputInvoiceTelegram::inputInvoiceTelegram(object_ptr<TelegramPaymentPurpose> &&purpose_)
  : purpose_(std::move(purpose_))
{}

const std::int32_t inputInvoiceTelegram::ID;

void inputInvoiceTelegram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceTelegram");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

inputPageBlockSectionHeading::inputPageBlockSectionHeading()
  : text_()
  , size_()
{}

inputPageBlockSectionHeading::inputPageBlockSectionHeading(object_ptr<RichText> &&text_, int32 size_)
  : text_(std::move(text_))
  , size_(size_)
{}

const std::int32_t inputPageBlockSectionHeading::ID;

void inputPageBlockSectionHeading::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockSectionHeading");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("size", size_);
    s.store_class_end();
  }
}

inputPageBlockParagraph::inputPageBlockParagraph()
  : text_()
{}

inputPageBlockParagraph::inputPageBlockParagraph(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t inputPageBlockParagraph::ID;

void inputPageBlockParagraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockParagraph");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

inputPageBlockPreformatted::inputPageBlockPreformatted()
  : text_()
  , language_()
{}

inputPageBlockPreformatted::inputPageBlockPreformatted(object_ptr<RichText> &&text_, string const &language_)
  : text_(std::move(text_))
  , language_(language_)
{}

const std::int32_t inputPageBlockPreformatted::ID;

void inputPageBlockPreformatted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockPreformatted");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("language", language_);
    s.store_class_end();
  }
}

inputPageBlockFooter::inputPageBlockFooter()
  : footer_()
{}

inputPageBlockFooter::inputPageBlockFooter(object_ptr<RichText> &&footer_)
  : footer_(std::move(footer_))
{}

const std::int32_t inputPageBlockFooter::ID;

void inputPageBlockFooter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockFooter");
    s.store_object_field("footer", static_cast<const BaseObject *>(footer_.get()));
    s.store_class_end();
  }
}

inputPageBlockThinking::inputPageBlockThinking()
  : text_()
{}

inputPageBlockThinking::inputPageBlockThinking(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t inputPageBlockThinking::ID;

void inputPageBlockThinking::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockThinking");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

inputPageBlockDivider::inputPageBlockDivider() {
}

const std::int32_t inputPageBlockDivider::ID;

void inputPageBlockDivider::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockDivider");
    s.store_class_end();
  }
}

inputPageBlockMathematicalExpression::inputPageBlockMathematicalExpression()
  : expression_()
{}

inputPageBlockMathematicalExpression::inputPageBlockMathematicalExpression(string const &expression_)
  : expression_(expression_)
{}

const std::int32_t inputPageBlockMathematicalExpression::ID;

void inputPageBlockMathematicalExpression::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockMathematicalExpression");
    s.store_field("expression", expression_);
    s.store_class_end();
  }
}

inputPageBlockAnchor::inputPageBlockAnchor()
  : name_()
{}

inputPageBlockAnchor::inputPageBlockAnchor(string const &name_)
  : name_(name_)
{}

const std::int32_t inputPageBlockAnchor::ID;

void inputPageBlockAnchor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockAnchor");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

inputPageBlockList::inputPageBlockList()
  : items_()
{}

inputPageBlockList::inputPageBlockList(array<object_ptr<inputPageBlockListItem>> &&items_)
  : items_(std::move(items_))
{}

const std::int32_t inputPageBlockList::ID;

void inputPageBlockList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockList");
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPageBlockBlockQuote::inputPageBlockBlockQuote()
  : blocks_()
  , credit_()
{}

inputPageBlockBlockQuote::inputPageBlockBlockQuote(array<object_ptr<InputPageBlock>> &&blocks_, object_ptr<RichText> &&credit_)
  : blocks_(std::move(blocks_))
  , credit_(std::move(credit_))
{}

const std::int32_t inputPageBlockBlockQuote::ID;

void inputPageBlockBlockQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockBlockQuote");
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

inputPageBlockExpandableBlockQuote::inputPageBlockExpandableBlockQuote()
  : text_()
  , credit_()
{}

inputPageBlockExpandableBlockQuote::inputPageBlockExpandableBlockQuote(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t inputPageBlockExpandableBlockQuote::ID;

void inputPageBlockExpandableBlockQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockExpandableBlockQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

inputPageBlockPullQuote::inputPageBlockPullQuote()
  : text_()
  , credit_()
{}

inputPageBlockPullQuote::inputPageBlockPullQuote(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t inputPageBlockPullQuote::ID;

void inputPageBlockPullQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockPullQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

inputPageBlockAnimation::inputPageBlockAnimation()
  : animation_()
  , caption_()
  , has_spoiler_()
{}

inputPageBlockAnimation::inputPageBlockAnimation(object_ptr<inputAnimation> &&animation_, object_ptr<pageBlockCaption> &&caption_, bool has_spoiler_)
  : animation_(std::move(animation_))
  , caption_(std::move(caption_))
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t inputPageBlockAnimation::ID;

void inputPageBlockAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

inputPageBlockAudio::inputPageBlockAudio()
  : audio_()
  , caption_()
{}

inputPageBlockAudio::inputPageBlockAudio(object_ptr<inputAudio> &&audio_, object_ptr<pageBlockCaption> &&caption_)
  : audio_(std::move(audio_))
  , caption_(std::move(caption_))
{}

const std::int32_t inputPageBlockAudio::ID;

void inputPageBlockAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputPageBlockDocument::inputPageBlockDocument()
  : document_()
  , caption_()
{}

inputPageBlockDocument::inputPageBlockDocument(object_ptr<inputDocument> &&document_, object_ptr<pageBlockCaption> &&caption_)
  : document_(std::move(document_))
  , caption_(std::move(caption_))
{}

const std::int32_t inputPageBlockDocument::ID;

void inputPageBlockDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputPageBlockPhoto::inputPageBlockPhoto()
  : photo_()
  , caption_()
  , has_spoiler_()
{}

inputPageBlockPhoto::inputPageBlockPhoto(object_ptr<inputPhoto> &&photo_, object_ptr<pageBlockCaption> &&caption_, bool has_spoiler_)
  : photo_(std::move(photo_))
  , caption_(std::move(caption_))
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t inputPageBlockPhoto::ID;

void inputPageBlockPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

inputPageBlockVideo::inputPageBlockVideo()
  : video_()
  , caption_()
  , has_spoiler_()
{}

inputPageBlockVideo::inputPageBlockVideo(object_ptr<inputVideo> &&video_, object_ptr<pageBlockCaption> &&caption_, bool has_spoiler_)
  : video_(std::move(video_))
  , caption_(std::move(caption_))
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t inputPageBlockVideo::ID;

void inputPageBlockVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

inputPageBlockVoiceNote::inputPageBlockVoiceNote()
  : voice_note_()
  , caption_()
{}

inputPageBlockVoiceNote::inputPageBlockVoiceNote(object_ptr<inputVoiceNote> &&voice_note_, object_ptr<pageBlockCaption> &&caption_)
  : voice_note_(std::move(voice_note_))
  , caption_(std::move(caption_))
{}

const std::int32_t inputPageBlockVoiceNote::ID;

void inputPageBlockVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputPageBlockCollage::inputPageBlockCollage()
  : blocks_()
  , caption_()
{}

inputPageBlockCollage::inputPageBlockCollage(array<object_ptr<InputPageBlock>> &&blocks_, object_ptr<pageBlockCaption> &&caption_)
  : blocks_(std::move(blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t inputPageBlockCollage::ID;

void inputPageBlockCollage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockCollage");
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputPageBlockSlideshow::inputPageBlockSlideshow()
  : blocks_()
  , caption_()
{}

inputPageBlockSlideshow::inputPageBlockSlideshow(array<object_ptr<InputPageBlock>> &&blocks_, object_ptr<pageBlockCaption> &&caption_)
  : blocks_(std::move(blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t inputPageBlockSlideshow::ID;

void inputPageBlockSlideshow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockSlideshow");
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputPageBlockTable::inputPageBlockTable()
  : caption_()
  , cells_()
  , is_bordered_()
  , is_striped_()
  , is_compact_()
{}

inputPageBlockTable::inputPageBlockTable(object_ptr<RichText> &&caption_, array<array<object_ptr<pageBlockTableCell>>> &&cells_, bool is_bordered_, bool is_striped_, bool is_compact_)
  : caption_(std::move(caption_))
  , cells_(std::move(cells_))
  , is_bordered_(is_bordered_)
  , is_striped_(is_striped_)
  , is_compact_(is_compact_)
{}

const std::int32_t inputPageBlockTable::ID;

void inputPageBlockTable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockTable");
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    { s.store_vector_begin("cells", cells_.size()); for (const auto &_value : cells_) { { s.store_vector_begin("", _value.size()); for (const auto &_value2 : _value) { s.store_object_field("", static_cast<const BaseObject *>(_value2.get())); } s.store_class_end(); } } s.store_class_end(); }
    s.store_field("is_bordered", is_bordered_);
    s.store_field("is_striped", is_striped_);
    s.store_field("is_compact", is_compact_);
    s.store_class_end();
  }
}

inputPageBlockDetails::inputPageBlockDetails()
  : header_()
  , blocks_()
  , is_open_()
{}

inputPageBlockDetails::inputPageBlockDetails(object_ptr<RichText> &&header_, array<object_ptr<InputPageBlock>> &&blocks_, bool is_open_)
  : header_(std::move(header_))
  , blocks_(std::move(blocks_))
  , is_open_(is_open_)
{}

const std::int32_t inputPageBlockDetails::ID;

void inputPageBlockDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockDetails");
    s.store_object_field("header", static_cast<const BaseObject *>(header_.get()));
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_open", is_open_);
    s.store_class_end();
  }
}

inputPageBlockMap::inputPageBlockMap()
  : location_()
  , zoom_()
  , width_()
  , height_()
  , caption_()
{}

inputPageBlockMap::inputPageBlockMap(object_ptr<location> &&location_, int32 zoom_, int32 width_, int32 height_, object_ptr<pageBlockCaption> &&caption_)
  : location_(std::move(location_))
  , zoom_(zoom_)
  , width_(width_)
  , height_(height_)
  , caption_(std::move(caption_))
{}

const std::int32_t inputPageBlockMap::ID;

void inputPageBlockMap::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockMap");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("zoom", zoom_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputPageBlockButtonRow::inputPageBlockButtonRow()
  : buttons_()
  , align_()
{}

inputPageBlockButtonRow::inputPageBlockButtonRow(array<object_ptr<inlineButton>> &&buttons_, object_ptr<PageBlockHorizontalAlignment> &&align_)
  : buttons_(std::move(buttons_))
  , align_(std::move(align_))
{}

const std::int32_t inputPageBlockButtonRow::ID;

void inputPageBlockButtonRow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPageBlockButtonRow");
    { s.store_vector_begin("buttons", buttons_.size()); for (const auto &_value : buttons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("align", static_cast<const BaseObject *>(align_.get()));
    s.store_class_end();
  }
}

inputSuggestedPostInfo::inputSuggestedPostInfo()
  : price_()
  , send_date_()
{}

inputSuggestedPostInfo::inputSuggestedPostInfo(object_ptr<SuggestedPostPrice> &&price_, int32 send_date_)
  : price_(std::move(price_))
  , send_date_(send_date_)
{}

const std::int32_t inputSuggestedPostInfo::ID;

void inputSuggestedPostInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSuggestedPostInfo");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("send_date", send_date_);
    s.store_class_end();
  }
}

languagePackStrings::languagePackStrings()
  : strings_()
{}

languagePackStrings::languagePackStrings(array<object_ptr<languagePackString>> &&strings_)
  : strings_(std::move(strings_))
{}

const std::int32_t languagePackStrings::ID;

void languagePackStrings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStrings");
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

linkPreviewTypeAlbum::linkPreviewTypeAlbum()
  : media_()
  , caption_()
{}

linkPreviewTypeAlbum::linkPreviewTypeAlbum(array<object_ptr<LinkPreviewAlbumMedia>> &&media_, string const &caption_)
  : media_(std::move(media_))
  , caption_(caption_)
{}

const std::int32_t linkPreviewTypeAlbum::ID;

void linkPreviewTypeAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeAlbum");
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("caption", caption_);
    s.store_class_end();
  }
}

linkPreviewTypeAnimation::linkPreviewTypeAnimation()
  : animation_()
{}

linkPreviewTypeAnimation::linkPreviewTypeAnimation(object_ptr<animation> &&animation_)
  : animation_(std::move(animation_))
{}

const std::int32_t linkPreviewTypeAnimation::ID;

void linkPreviewTypeAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeApp::linkPreviewTypeApp()
  : photo_()
{}

linkPreviewTypeApp::linkPreviewTypeApp(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeApp::ID;

void linkPreviewTypeApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeApp");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeArticle::linkPreviewTypeArticle()
  : photo_()
{}

linkPreviewTypeArticle::linkPreviewTypeArticle(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeArticle::ID;

void linkPreviewTypeArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeArticle");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeAudio::linkPreviewTypeAudio()
  : audio_()
{}

linkPreviewTypeAudio::linkPreviewTypeAudio(object_ptr<audio> &&audio_)
  : audio_(std::move(audio_))
{}

const std::int32_t linkPreviewTypeAudio::ID;

void linkPreviewTypeAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeBackground::linkPreviewTypeBackground()
  : document_()
  , background_type_()
{}

linkPreviewTypeBackground::linkPreviewTypeBackground(object_ptr<document> &&document_, object_ptr<BackgroundType> &&background_type_)
  : document_(std::move(document_))
  , background_type_(std::move(background_type_))
{}

const std::int32_t linkPreviewTypeBackground::ID;

void linkPreviewTypeBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeBackground");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("background_type", static_cast<const BaseObject *>(background_type_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeChannelBoost::linkPreviewTypeChannelBoost()
  : photo_()
{}

linkPreviewTypeChannelBoost::linkPreviewTypeChannelBoost(object_ptr<chatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeChannelBoost::ID;

void linkPreviewTypeChannelBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeChannelBoost");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeChat::linkPreviewTypeChat()
  : type_()
  , photo_()
  , creates_join_request_()
{}

linkPreviewTypeChat::linkPreviewTypeChat(object_ptr<InviteLinkChatType> &&type_, object_ptr<chatPhoto> &&photo_, bool creates_join_request_)
  : type_(std::move(type_))
  , photo_(std::move(photo_))
  , creates_join_request_(creates_join_request_)
{}

const std::int32_t linkPreviewTypeChat::ID;

void linkPreviewTypeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeChat");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("creates_join_request", creates_join_request_);
    s.store_class_end();
  }
}

linkPreviewTypeDirectMessagesChat::linkPreviewTypeDirectMessagesChat()
  : photo_()
{}

linkPreviewTypeDirectMessagesChat::linkPreviewTypeDirectMessagesChat(object_ptr<chatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeDirectMessagesChat::ID;

void linkPreviewTypeDirectMessagesChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeDirectMessagesChat");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeDocument::linkPreviewTypeDocument()
  : document_()
{}

linkPreviewTypeDocument::linkPreviewTypeDocument(object_ptr<document> &&document_)
  : document_(std::move(document_))
{}

const std::int32_t linkPreviewTypeDocument::ID;

void linkPreviewTypeDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeEmbeddedAnimationPlayer::linkPreviewTypeEmbeddedAnimationPlayer()
  : url_()
  , animation_()
  , thumbnail_()
  , duration_()
  , width_()
  , height_()
{}

linkPreviewTypeEmbeddedAnimationPlayer::linkPreviewTypeEmbeddedAnimationPlayer(string const &url_, object_ptr<animation> &&animation_, object_ptr<photo> &&thumbnail_, int32 duration_, int32 width_, int32 height_)
  : url_(url_)
  , animation_(std::move(animation_))
  , thumbnail_(std::move(thumbnail_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
{}

const std::int32_t linkPreviewTypeEmbeddedAnimationPlayer::ID;

void linkPreviewTypeEmbeddedAnimationPlayer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeEmbeddedAnimationPlayer");
    s.store_field("url", url_);
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

linkPreviewTypeEmbeddedAudioPlayer::linkPreviewTypeEmbeddedAudioPlayer()
  : url_()
  , audio_()
  , thumbnail_()
  , duration_()
  , width_()
  , height_()
{}

linkPreviewTypeEmbeddedAudioPlayer::linkPreviewTypeEmbeddedAudioPlayer(string const &url_, object_ptr<audio> &&audio_, object_ptr<photo> &&thumbnail_, int32 duration_, int32 width_, int32 height_)
  : url_(url_)
  , audio_(std::move(audio_))
  , thumbnail_(std::move(thumbnail_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
{}

const std::int32_t linkPreviewTypeEmbeddedAudioPlayer::ID;

void linkPreviewTypeEmbeddedAudioPlayer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeEmbeddedAudioPlayer");
    s.store_field("url", url_);
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

linkPreviewTypeEmbeddedVideoPlayer::linkPreviewTypeEmbeddedVideoPlayer()
  : url_()
  , video_()
  , thumbnail_()
  , duration_()
  , width_()
  , height_()
{}

linkPreviewTypeEmbeddedVideoPlayer::linkPreviewTypeEmbeddedVideoPlayer(string const &url_, object_ptr<video> &&video_, object_ptr<photo> &&thumbnail_, int32 duration_, int32 width_, int32 height_)
  : url_(url_)
  , video_(std::move(video_))
  , thumbnail_(std::move(thumbnail_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
{}

const std::int32_t linkPreviewTypeEmbeddedVideoPlayer::ID;

void linkPreviewTypeEmbeddedVideoPlayer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeEmbeddedVideoPlayer");
    s.store_field("url", url_);
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

linkPreviewTypeExternalAudio::linkPreviewTypeExternalAudio()
  : url_()
  , mime_type_()
  , duration_()
{}

linkPreviewTypeExternalAudio::linkPreviewTypeExternalAudio(string const &url_, string const &mime_type_, int32 duration_)
  : url_(url_)
  , mime_type_(mime_type_)
  , duration_(duration_)
{}

const std::int32_t linkPreviewTypeExternalAudio::ID;

void linkPreviewTypeExternalAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeExternalAudio");
    s.store_field("url", url_);
    s.store_field("mime_type", mime_type_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

linkPreviewTypeExternalVideo::linkPreviewTypeExternalVideo()
  : url_()
  , mime_type_()
  , width_()
  , height_()
  , duration_()
{}

linkPreviewTypeExternalVideo::linkPreviewTypeExternalVideo(string const &url_, string const &mime_type_, int32 width_, int32 height_, int32 duration_)
  : url_(url_)
  , mime_type_(mime_type_)
  , width_(width_)
  , height_(height_)
  , duration_(duration_)
{}

const std::int32_t linkPreviewTypeExternalVideo::ID;

void linkPreviewTypeExternalVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeExternalVideo");
    s.store_field("url", url_);
    s.store_field("mime_type", mime_type_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

linkPreviewTypeGiftAuction::linkPreviewTypeGiftAuction()
  : gift_()
  , auction_end_date_()
{}

linkPreviewTypeGiftAuction::linkPreviewTypeGiftAuction(object_ptr<gift> &&gift_, int32 auction_end_date_)
  : gift_(std::move(gift_))
  , auction_end_date_(auction_end_date_)
{}

const std::int32_t linkPreviewTypeGiftAuction::ID;

void linkPreviewTypeGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeGiftAuction");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("auction_end_date", auction_end_date_);
    s.store_class_end();
  }
}

linkPreviewTypeGiftCollection::linkPreviewTypeGiftCollection()
  : icons_()
{}

linkPreviewTypeGiftCollection::linkPreviewTypeGiftCollection(array<object_ptr<sticker>> &&icons_)
  : icons_(std::move(icons_))
{}

const std::int32_t linkPreviewTypeGiftCollection::ID;

void linkPreviewTypeGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeGiftCollection");
    { s.store_vector_begin("icons", icons_.size()); for (const auto &_value : icons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

linkPreviewTypeGroupCall::linkPreviewTypeGroupCall() {
}

const std::int32_t linkPreviewTypeGroupCall::ID;

void linkPreviewTypeGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeGroupCall");
    s.store_class_end();
  }
}

linkPreviewTypeInvoice::linkPreviewTypeInvoice() {
}

const std::int32_t linkPreviewTypeInvoice::ID;

void linkPreviewTypeInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeInvoice");
    s.store_class_end();
  }
}

linkPreviewTypeLiveStory::linkPreviewTypeLiveStory()
  : story_poster_chat_id_()
  , story_id_()
{}

linkPreviewTypeLiveStory::linkPreviewTypeLiveStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t linkPreviewTypeLiveStory::ID;

void linkPreviewTypeLiveStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeLiveStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

linkPreviewTypeMessage::linkPreviewTypeMessage() {
}

const std::int32_t linkPreviewTypeMessage::ID;

void linkPreviewTypeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeMessage");
    s.store_class_end();
  }
}

linkPreviewTypePhoto::linkPreviewTypePhoto()
  : photo_()
{}

linkPreviewTypePhoto::linkPreviewTypePhoto(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypePhoto::ID;

void linkPreviewTypePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypePremiumGiftCode::linkPreviewTypePremiumGiftCode() {
}

const std::int32_t linkPreviewTypePremiumGiftCode::ID;

void linkPreviewTypePremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypePremiumGiftCode");
    s.store_class_end();
  }
}

linkPreviewTypeRequestManagedBot::linkPreviewTypeRequestManagedBot() {
}

const std::int32_t linkPreviewTypeRequestManagedBot::ID;

void linkPreviewTypeRequestManagedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeRequestManagedBot");
    s.store_class_end();
  }
}

linkPreviewTypeShareableChatFolder::linkPreviewTypeShareableChatFolder() {
}

const std::int32_t linkPreviewTypeShareableChatFolder::ID;

void linkPreviewTypeShareableChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeShareableChatFolder");
    s.store_class_end();
  }
}

linkPreviewTypeSticker::linkPreviewTypeSticker()
  : sticker_()
{}

linkPreviewTypeSticker::linkPreviewTypeSticker(object_ptr<sticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t linkPreviewTypeSticker::ID;

void linkPreviewTypeSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeStickerSet::linkPreviewTypeStickerSet()
  : stickers_()
{}

linkPreviewTypeStickerSet::linkPreviewTypeStickerSet(array<object_ptr<sticker>> &&stickers_)
  : stickers_(std::move(stickers_))
{}

const std::int32_t linkPreviewTypeStickerSet::ID;

void linkPreviewTypeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeStickerSet");
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

linkPreviewTypeStory::linkPreviewTypeStory()
  : story_poster_chat_id_()
  , story_id_()
{}

linkPreviewTypeStory::linkPreviewTypeStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t linkPreviewTypeStory::ID;

void linkPreviewTypeStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

linkPreviewTypeStoryAlbum::linkPreviewTypeStoryAlbum()
  : photo_icon_()
  , video_icon_()
{}

linkPreviewTypeStoryAlbum::linkPreviewTypeStoryAlbum(object_ptr<photo> &&photo_icon_, object_ptr<video> &&video_icon_)
  : photo_icon_(std::move(photo_icon_))
  , video_icon_(std::move(video_icon_))
{}

const std::int32_t linkPreviewTypeStoryAlbum::ID;

void linkPreviewTypeStoryAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeStoryAlbum");
    s.store_object_field("photo_icon", static_cast<const BaseObject *>(photo_icon_.get()));
    s.store_object_field("video_icon", static_cast<const BaseObject *>(video_icon_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeSupergroupBoost::linkPreviewTypeSupergroupBoost()
  : photo_()
{}

linkPreviewTypeSupergroupBoost::linkPreviewTypeSupergroupBoost(object_ptr<chatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeSupergroupBoost::ID;

void linkPreviewTypeSupergroupBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeSupergroupBoost");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeTextCompositionStyle::linkPreviewTypeTextCompositionStyle()
  : custom_emoji_id_()
{}

linkPreviewTypeTextCompositionStyle::linkPreviewTypeTextCompositionStyle(int64 custom_emoji_id_)
  : custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t linkPreviewTypeTextCompositionStyle::ID;

void linkPreviewTypeTextCompositionStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeTextCompositionStyle");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

linkPreviewTypeTheme::linkPreviewTypeTheme()
  : documents_()
  , settings_()
{}

linkPreviewTypeTheme::linkPreviewTypeTheme(array<object_ptr<document>> &&documents_, object_ptr<themeSettings> &&settings_)
  : documents_(std::move(documents_))
  , settings_(std::move(settings_))
{}

const std::int32_t linkPreviewTypeTheme::ID;

void linkPreviewTypeTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeTheme");
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeUnsupported::linkPreviewTypeUnsupported() {
}

const std::int32_t linkPreviewTypeUnsupported::ID;

void linkPreviewTypeUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeUnsupported");
    s.store_class_end();
  }
}

linkPreviewTypeUpgradedGift::linkPreviewTypeUpgradedGift()
  : gift_()
{}

linkPreviewTypeUpgradedGift::linkPreviewTypeUpgradedGift(object_ptr<upgradedGift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t linkPreviewTypeUpgradedGift::ID;

void linkPreviewTypeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeUpgradedGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeUser::linkPreviewTypeUser()
  : photo_()
  , is_bot_()
{}

linkPreviewTypeUser::linkPreviewTypeUser(object_ptr<chatPhoto> &&photo_, bool is_bot_)
  : photo_(std::move(photo_))
  , is_bot_(is_bot_)
{}

const std::int32_t linkPreviewTypeUser::ID;

void linkPreviewTypeUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeUser");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("is_bot", is_bot_);
    s.store_class_end();
  }
}

linkPreviewTypeVideo::linkPreviewTypeVideo()
  : video_()
  , cover_()
  , start_timestamp_()
{}

linkPreviewTypeVideo::linkPreviewTypeVideo(object_ptr<video> &&video_, object_ptr<photo> &&cover_, int32 start_timestamp_)
  : video_(std::move(video_))
  , cover_(std::move(cover_))
  , start_timestamp_(start_timestamp_)
{}

const std::int32_t linkPreviewTypeVideo::ID;

void linkPreviewTypeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_field("start_timestamp", start_timestamp_);
    s.store_class_end();
  }
}

linkPreviewTypeVideoChat::linkPreviewTypeVideoChat()
  : photo_()
  , is_live_stream_()
  , joins_as_speaker_()
{}

linkPreviewTypeVideoChat::linkPreviewTypeVideoChat(object_ptr<chatPhoto> &&photo_, bool is_live_stream_, bool joins_as_speaker_)
  : photo_(std::move(photo_))
  , is_live_stream_(is_live_stream_)
  , joins_as_speaker_(joins_as_speaker_)
{}

const std::int32_t linkPreviewTypeVideoChat::ID;

void linkPreviewTypeVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeVideoChat");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("is_live_stream", is_live_stream_);
    s.store_field("joins_as_speaker", joins_as_speaker_);
    s.store_class_end();
  }
}

linkPreviewTypeVideoNote::linkPreviewTypeVideoNote()
  : video_note_()
{}

linkPreviewTypeVideoNote::linkPreviewTypeVideoNote(object_ptr<videoNote> &&video_note_)
  : video_note_(std::move(video_note_))
{}

const std::int32_t linkPreviewTypeVideoNote::ID;

void linkPreviewTypeVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeVoiceNote::linkPreviewTypeVoiceNote()
  : voice_note_()
{}

linkPreviewTypeVoiceNote::linkPreviewTypeVoiceNote(object_ptr<voiceNote> &&voice_note_)
  : voice_note_(std::move(voice_note_))
{}

const std::int32_t linkPreviewTypeVoiceNote::ID;

void linkPreviewTypeVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeWebApp::linkPreviewTypeWebApp()
  : photo_()
{}

linkPreviewTypeWebApp::linkPreviewTypeWebApp(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeWebApp::ID;

void linkPreviewTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeWebApp");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

location::location()
  : latitude_()
  , longitude_()
  , horizontal_accuracy_()
{}

location::location(double latitude_, double longitude_, double horizontal_accuracy_)
  : latitude_(latitude_)
  , longitude_(longitude_)
  , horizontal_accuracy_(horizontal_accuracy_)
{}

const std::int32_t location::ID;

void location::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "location");
    s.store_field("latitude", latitude_);
    s.store_field("longitude", longitude_);
    s.store_field("horizontal_accuracy", horizontal_accuracy_);
    s.store_class_end();
  }
}

messageReaction::messageReaction()
  : type_()
  , total_count_()
  , is_chosen_()
  , used_sender_id_()
  , recent_sender_ids_()
{}

messageReaction::messageReaction(object_ptr<ReactionType> &&type_, int32 total_count_, bool is_chosen_, object_ptr<MessageSender> &&used_sender_id_, array<object_ptr<MessageSender>> &&recent_sender_ids_)
  : type_(std::move(type_))
  , total_count_(total_count_)
  , is_chosen_(is_chosen_)
  , used_sender_id_(std::move(used_sender_id_))
  , recent_sender_ids_(std::move(recent_sender_ids_))
{}

const std::int32_t messageReaction::ID;

void messageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReaction");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("total_count", total_count_);
    s.store_field("is_chosen", is_chosen_);
    s.store_object_field("used_sender_id", static_cast<const BaseObject *>(used_sender_id_.get()));
    { s.store_vector_begin("recent_sender_ids", recent_sender_ids_.size()); for (const auto &_value : recent_sender_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageSelfDestructTypeTimer::messageSelfDestructTypeTimer()
  : self_destruct_time_()
{}

messageSelfDestructTypeTimer::messageSelfDestructTypeTimer(int32 self_destruct_time_)
  : self_destruct_time_(self_destruct_time_)
{}

const std::int32_t messageSelfDestructTypeTimer::ID;

void messageSelfDestructTypeTimer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSelfDestructTypeTimer");
    s.store_field("self_destruct_time", self_destruct_time_);
    s.store_class_end();
  }
}

messageSelfDestructTypeImmediately::messageSelfDestructTypeImmediately() {
}

const std::int32_t messageSelfDestructTypeImmediately::ID;

void messageSelfDestructTypeImmediately::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSelfDestructTypeImmediately");
    s.store_class_end();
  }
}

messages::messages()
  : total_count_()
  , messages_()
{}

messages::messages(int32 total_count_, array<object_ptr<message>> &&messages_)
  : total_count_(total_count_)
  , messages_(std::move(messages_))
{}

const std::int32_t messages::ID;

void messages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

networkTypeNone::networkTypeNone() {
}

const std::int32_t networkTypeNone::ID;

void networkTypeNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeNone");
    s.store_class_end();
  }
}

networkTypeMobile::networkTypeMobile() {
}

const std::int32_t networkTypeMobile::ID;

void networkTypeMobile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeMobile");
    s.store_class_end();
  }
}

networkTypeMobileRoaming::networkTypeMobileRoaming() {
}

const std::int32_t networkTypeMobileRoaming::ID;

void networkTypeMobileRoaming::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeMobileRoaming");
    s.store_class_end();
  }
}

networkTypeWiFi::networkTypeWiFi() {
}

const std::int32_t networkTypeWiFi::ID;

void networkTypeWiFi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeWiFi");
    s.store_class_end();
  }
}

networkTypeOther::networkTypeOther() {
}

const std::int32_t networkTypeOther::ID;

void networkTypeOther::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeOther");
    s.store_class_end();
  }
}

newSticker::newSticker()
  : sticker_()
  , format_()
  , emojis_()
  , mask_position_()
  , keywords_()
{}

newSticker::newSticker(object_ptr<InputFile> &&sticker_, object_ptr<StickerFormat> &&format_, string const &emojis_, object_ptr<maskPosition> &&mask_position_, array<string> &&keywords_)
  : sticker_(std::move(sticker_))
  , format_(std::move(format_))
  , emojis_(emojis_)
  , mask_position_(std::move(mask_position_))
  , keywords_(std::move(keywords_))
{}

const std::int32_t newSticker::ID;

void newSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "newSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("format", static_cast<const BaseObject *>(format_.get()));
    s.store_field("emojis", emojis_);
    s.store_object_field("mask_position", static_cast<const BaseObject *>(mask_position_.get()));
    { s.store_vector_begin("keywords", keywords_.size()); for (const auto &_value : keywords_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockListItem::pageBlockListItem()
  : label_()
  , blocks_()
  , has_checkbox_()
  , is_checked_()
  , value_()
  , type_()
{}

pageBlockListItem::pageBlockListItem(string const &label_, array<object_ptr<PageBlock>> &&blocks_, bool has_checkbox_, bool is_checked_, int32 value_, string const &type_)
  : label_(label_)
  , blocks_(std::move(blocks_))
  , has_checkbox_(has_checkbox_)
  , is_checked_(is_checked_)
  , value_(value_)
  , type_(type_)
{}

const std::int32_t pageBlockListItem::ID;

void pageBlockListItem::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockListItem");
    s.store_field("label", label_);
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("has_checkbox", has_checkbox_);
    s.store_field("is_checked", is_checked_);
    s.store_field("value", value_);
    s.store_field("type", type_);
    s.store_class_end();
  }
}

pageBlockRelatedArticle::pageBlockRelatedArticle()
  : url_()
  , title_()
  , description_()
  , photo_()
  , author_()
  , publish_date_()
{}

pageBlockRelatedArticle::pageBlockRelatedArticle(string const &url_, string const &title_, string const &description_, object_ptr<photo> &&photo_, string const &author_, int32 publish_date_)
  : url_(url_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , author_(author_)
  , publish_date_(publish_date_)
{}

const std::int32_t pageBlockRelatedArticle::ID;

void pageBlockRelatedArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockRelatedArticle");
    s.store_field("url", url_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("author", author_);
    s.store_field("publish_date", publish_date_);
    s.store_class_end();
  }
}

paymentReceiptTypeRegular::paymentReceiptTypeRegular()
  : payment_provider_user_id_()
  , invoice_()
  , order_info_()
  , shipping_option_()
  , credentials_title_()
  , tip_amount_()
{}

paymentReceiptTypeRegular::paymentReceiptTypeRegular(int53 payment_provider_user_id_, object_ptr<invoice> &&invoice_, object_ptr<orderInfo> &&order_info_, object_ptr<shippingOption> &&shipping_option_, string const &credentials_title_, int53 tip_amount_)
  : payment_provider_user_id_(payment_provider_user_id_)
  , invoice_(std::move(invoice_))
  , order_info_(std::move(order_info_))
  , shipping_option_(std::move(shipping_option_))
  , credentials_title_(credentials_title_)
  , tip_amount_(tip_amount_)
{}

const std::int32_t paymentReceiptTypeRegular::ID;

void paymentReceiptTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentReceiptTypeRegular");
    s.store_field("payment_provider_user_id", payment_provider_user_id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_object_field("shipping_option", static_cast<const BaseObject *>(shipping_option_.get()));
    s.store_field("credentials_title", credentials_title_);
    s.store_field("tip_amount", tip_amount_);
    s.store_class_end();
  }
}

paymentReceiptTypeStars::paymentReceiptTypeStars()
  : star_count_()
  , transaction_id_()
{}

paymentReceiptTypeStars::paymentReceiptTypeStars(int53 star_count_, string const &transaction_id_)
  : star_count_(star_count_)
  , transaction_id_(transaction_id_)
{}

const std::int32_t paymentReceiptTypeStars::ID;

void paymentReceiptTypeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentReceiptTypeStars");
    s.store_field("star_count", star_count_);
    s.store_field("transaction_id", transaction_id_);
    s.store_class_end();
  }
}

phoneNumberInfo::phoneNumberInfo()
  : country_()
  , country_calling_code_()
  , formatted_phone_number_()
  , is_anonymous_()
{}

phoneNumberInfo::phoneNumberInfo(object_ptr<countryInfo> &&country_, string const &country_calling_code_, string const &formatted_phone_number_, bool is_anonymous_)
  : country_(std::move(country_))
  , country_calling_code_(country_calling_code_)
  , formatted_phone_number_(formatted_phone_number_)
  , is_anonymous_(is_anonymous_)
{}

const std::int32_t phoneNumberInfo::ID;

void phoneNumberInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberInfo");
    s.store_object_field("country", static_cast<const BaseObject *>(country_.get()));
    s.store_field("country_calling_code", country_calling_code_);
    s.store_field("formatted_phone_number", formatted_phone_number_);
    s.store_field("is_anonymous", is_anonymous_);
    s.store_class_end();
  }
}

photoSize::photoSize()
  : type_()
  , photo_()
  , width_()
  , height_()
  , progressive_sizes_()
{}

photoSize::photoSize(string const &type_, object_ptr<file> &&photo_, int32 width_, int32 height_, array<int32> &&progressive_sizes_)
  : type_(type_)
  , photo_(std::move(photo_))
  , width_(width_)
  , height_(height_)
  , progressive_sizes_(std::move(progressive_sizes_))
{}

const std::int32_t photoSize::ID;

void photoSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoSize");
    s.store_field("type", type_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    { s.store_vector_begin("progressive_sizes", progressive_sizes_.size()); for (const auto &_value : progressive_sizes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

pollMediaAnimation::pollMediaAnimation()
  : animation_()
{}

pollMediaAnimation::pollMediaAnimation(object_ptr<animation> &&animation_)
  : animation_(std::move(animation_))
{}

const std::int32_t pollMediaAnimation::ID;

void pollMediaAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollMediaAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

pollMediaAudio::pollMediaAudio()
  : audio_()
{}

pollMediaAudio::pollMediaAudio(object_ptr<audio> &&audio_)
  : audio_(std::move(audio_))
{}

const std::int32_t pollMediaAudio::ID;

void pollMediaAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollMediaAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_class_end();
  }
}

pollMediaDocument::pollMediaDocument()
  : document_()
{}

pollMediaDocument::pollMediaDocument(object_ptr<document> &&document_)
  : document_(std::move(document_))
{}

const std::int32_t pollMediaDocument::ID;

void pollMediaDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollMediaDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_class_end();
  }
}

pollMediaLink::pollMediaLink()
  : url_()
  , link_preview_()
{}

pollMediaLink::pollMediaLink(string const &url_, object_ptr<linkPreview> &&link_preview_)
  : url_(url_)
  , link_preview_(std::move(link_preview_))
{}

const std::int32_t pollMediaLink::ID;

void pollMediaLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollMediaLink");
    s.store_field("url", url_);
    s.store_object_field("link_preview", static_cast<const BaseObject *>(link_preview_.get()));
    s.store_class_end();
  }
}

pollMediaLocation::pollMediaLocation()
  : location_()
{}

pollMediaLocation::pollMediaLocation(object_ptr<location> &&location_)
  : location_(std::move(location_))
{}

const std::int32_t pollMediaLocation::ID;

void pollMediaLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollMediaLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

pollMediaPhoto::pollMediaPhoto()
  : photo_()
  , video_()
{}

pollMediaPhoto::pollMediaPhoto(object_ptr<photo> &&photo_, object_ptr<video> &&video_)
  : photo_(std::move(photo_))
  , video_(std::move(video_))
{}

const std::int32_t pollMediaPhoto::ID;

void pollMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollMediaPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

pollMediaSticker::pollMediaSticker()
  : sticker_()
{}

pollMediaSticker::pollMediaSticker(object_ptr<sticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t pollMediaSticker::ID;

void pollMediaSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollMediaSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

pollMediaVenue::pollMediaVenue()
  : venue_()
{}

pollMediaVenue::pollMediaVenue(object_ptr<venue> &&venue_)
  : venue_(std::move(venue_))
{}

const std::int32_t pollMediaVenue::ID;

void pollMediaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollMediaVenue");
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_class_end();
  }
}

pollMediaVideo::pollMediaVideo()
  : video_()
  , alternative_videos_()
  , storyboards_()
  , cover_()
  , start_timestamp_()
{}

pollMediaVideo::pollMediaVideo(object_ptr<video> &&video_, array<object_ptr<alternativeVideo>> &&alternative_videos_, array<object_ptr<videoStoryboard>> &&storyboards_, object_ptr<photo> &&cover_, int32 start_timestamp_)
  : video_(std::move(video_))
  , alternative_videos_(std::move(alternative_videos_))
  , storyboards_(std::move(storyboards_))
  , cover_(std::move(cover_))
  , start_timestamp_(start_timestamp_)
{}

const std::int32_t pollMediaVideo::ID;

void pollMediaVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollMediaVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    { s.store_vector_begin("alternative_videos", alternative_videos_.size()); for (const auto &_value : alternative_videos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("storyboards", storyboards_.size()); for (const auto &_value : storyboards_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_field("start_timestamp", start_timestamp_);
    s.store_class_end();
  }
}

premiumLimit::premiumLimit()
  : type_()
  , default_value_()
  , premium_value_()
{}

premiumLimit::premiumLimit(object_ptr<PremiumLimitType> &&type_, int32 default_value_, int32 premium_value_)
  : type_(std::move(type_))
  , default_value_(default_value_)
  , premium_value_(premium_value_)
{}

const std::int32_t premiumLimit::ID;

void premiumLimit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimit");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("default_value", default_value_);
    s.store_field("premium_value", premium_value_);
    s.store_class_end();
  }
}

premiumPaymentOption::premiumPaymentOption()
  : currency_()
  , amount_()
  , discount_percentage_()
  , month_count_()
  , store_product_id_()
  , payment_link_()
{}

premiumPaymentOption::premiumPaymentOption(string const &currency_, int53 amount_, int32 discount_percentage_, int32 month_count_, string const &store_product_id_, object_ptr<InternalLinkType> &&payment_link_)
  : currency_(currency_)
  , amount_(amount_)
  , discount_percentage_(discount_percentage_)
  , month_count_(month_count_)
  , store_product_id_(store_product_id_)
  , payment_link_(std::move(payment_link_))
{}

const std::int32_t premiumPaymentOption::ID;

void premiumPaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumPaymentOption");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("discount_percentage", discount_percentage_);
    s.store_field("month_count", month_count_);
    s.store_field("store_product_id", store_product_id_);
    s.store_object_field("payment_link", static_cast<const BaseObject *>(payment_link_.get()));
    s.store_class_end();
  }
}

prepaidGiveaway::prepaidGiveaway()
  : id_()
  , winner_count_()
  , prize_()
  , boost_count_()
  , payment_date_()
{}

prepaidGiveaway::prepaidGiveaway(int64 id_, int32 winner_count_, object_ptr<GiveawayPrize> &&prize_, int32 boost_count_, int32 payment_date_)
  : id_(id_)
  , winner_count_(winner_count_)
  , prize_(std::move(prize_))
  , boost_count_(boost_count_)
  , payment_date_(payment_date_)
{}

const std::int32_t prepaidGiveaway::ID;

void prepaidGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "prepaidGiveaway");
    s.store_field("id", id_);
    s.store_field("winner_count", winner_count_);
    s.store_object_field("prize", static_cast<const BaseObject *>(prize_.get()));
    s.store_field("boost_count", boost_count_);
    s.store_field("payment_date", payment_date_);
    s.store_class_end();
  }
}

preparedInlineMessage::preparedInlineMessage()
  : inline_query_id_()
  , result_()
  , chat_types_()
{}

preparedInlineMessage::preparedInlineMessage(int64 inline_query_id_, object_ptr<InlineQueryResult> &&result_, object_ptr<targetChatTypes> &&chat_types_)
  : inline_query_id_(inline_query_id_)
  , result_(std::move(result_))
  , chat_types_(std::move(chat_types_))
{}

const std::int32_t preparedInlineMessage::ID;

void preparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "preparedInlineMessage");
    s.store_field("inline_query_id", inline_query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_object_field("chat_types", static_cast<const BaseObject *>(chat_types_.get()));
    s.store_class_end();
  }
}

profileShareThemeBackdrops::profileShareThemeBackdrops()
  : backdrops_()
{}

profileShareThemeBackdrops::profileShareThemeBackdrops(array<object_ptr<profileShareThemeBackdrop>> &&backdrops_)
  : backdrops_(std::move(backdrops_))
{}

const std::int32_t profileShareThemeBackdrops::ID;

void profileShareThemeBackdrops::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileShareThemeBackdrops");
    { s.store_vector_begin("backdrops", backdrops_.size()); for (const auto &_value : backdrops_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reactionNotificationSourceNone::reactionNotificationSourceNone() {
}

const std::int32_t reactionNotificationSourceNone::ID;

void reactionNotificationSourceNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationSourceNone");
    s.store_class_end();
  }
}

reactionNotificationSourceContacts::reactionNotificationSourceContacts() {
}

const std::int32_t reactionNotificationSourceContacts::ID;

void reactionNotificationSourceContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationSourceContacts");
    s.store_class_end();
  }
}

reactionNotificationSourceAll::reactionNotificationSourceAll() {
}

const std::int32_t reactionNotificationSourceAll::ID;

void reactionNotificationSourceAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationSourceAll");
    s.store_class_end();
  }
}

reactionUnavailabilityReasonAnonymousAdministrator::reactionUnavailabilityReasonAnonymousAdministrator() {
}

const std::int32_t reactionUnavailabilityReasonAnonymousAdministrator::ID;

void reactionUnavailabilityReasonAnonymousAdministrator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionUnavailabilityReasonAnonymousAdministrator");
    s.store_class_end();
  }
}

reactionUnavailabilityReasonGuest::reactionUnavailabilityReasonGuest() {
}

const std::int32_t reactionUnavailabilityReasonGuest::ID;

void reactionUnavailabilityReasonGuest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionUnavailabilityReasonGuest");
    s.store_class_end();
  }
}

reactionUnavailabilityReasonRestricted::reactionUnavailabilityReasonRestricted() {
}

const std::int32_t reactionUnavailabilityReasonRestricted::ID;

void reactionUnavailabilityReasonRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionUnavailabilityReasonRestricted");
    s.store_class_end();
  }
}

readDatePrivacySettings::readDatePrivacySettings()
  : show_read_date_()
{}

readDatePrivacySettings::readDatePrivacySettings(bool show_read_date_)
  : show_read_date_(show_read_date_)
{}

const std::int32_t readDatePrivacySettings::ID;

void readDatePrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readDatePrivacySettings");
    s.store_field("show_read_date", show_read_date_);
    s.store_class_end();
  }
}

recommendedChatFolder::recommendedChatFolder()
  : folder_()
  , description_()
{}

recommendedChatFolder::recommendedChatFolder(object_ptr<chatFolder> &&folder_, string const &description_)
  : folder_(std::move(folder_))
  , description_(description_)
{}

const std::int32_t recommendedChatFolder::ID;

void recommendedChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recommendedChatFolder");
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_field("description", description_);
    s.store_class_end();
  }
}

replyMarkupRemoveKeyboard::replyMarkupRemoveKeyboard()
  : is_personal_()
{}

replyMarkupRemoveKeyboard::replyMarkupRemoveKeyboard(bool is_personal_)
  : is_personal_(is_personal_)
{}

const std::int32_t replyMarkupRemoveKeyboard::ID;

void replyMarkupRemoveKeyboard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupRemoveKeyboard");
    s.store_field("is_personal", is_personal_);
    s.store_class_end();
  }
}

replyMarkupForceReply::replyMarkupForceReply()
  : is_personal_()
  , input_field_placeholder_()
{}

replyMarkupForceReply::replyMarkupForceReply(bool is_personal_, string const &input_field_placeholder_)
  : is_personal_(is_personal_)
  , input_field_placeholder_(input_field_placeholder_)
{}

const std::int32_t replyMarkupForceReply::ID;

void replyMarkupForceReply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupForceReply");
    s.store_field("is_personal", is_personal_);
    s.store_field("input_field_placeholder", input_field_placeholder_);
    s.store_class_end();
  }
}

replyMarkupShowKeyboard::replyMarkupShowKeyboard()
  : rows_()
  , is_persistent_()
  , resize_keyboard_()
  , one_time_()
  , is_personal_()
  , force_reply_()
  , input_field_placeholder_()
{}

replyMarkupShowKeyboard::replyMarkupShowKeyboard(array<array<object_ptr<keyboardButton>>> &&rows_, bool is_persistent_, bool resize_keyboard_, bool one_time_, bool is_personal_, bool force_reply_, string const &input_field_placeholder_)
  : rows_(std::move(rows_))
  , is_persistent_(is_persistent_)
  , resize_keyboard_(resize_keyboard_)
  , one_time_(one_time_)
  , is_personal_(is_personal_)
  , force_reply_(force_reply_)
  , input_field_placeholder_(input_field_placeholder_)
{}

const std::int32_t replyMarkupShowKeyboard::ID;

void replyMarkupShowKeyboard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupShowKeyboard");
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { { s.store_vector_begin("", _value.size()); for (const auto &_value2 : _value) { s.store_object_field("", static_cast<const BaseObject *>(_value2.get())); } s.store_class_end(); } } s.store_class_end(); }
    s.store_field("is_persistent", is_persistent_);
    s.store_field("resize_keyboard", resize_keyboard_);
    s.store_field("one_time", one_time_);
    s.store_field("is_personal", is_personal_);
    s.store_field("force_reply", force_reply_);
    s.store_field("input_field_placeholder", input_field_placeholder_);
    s.store_class_end();
  }
}

replyMarkupInlineKeyboard::replyMarkupInlineKeyboard()
  : rows_()
  , force_reply_()
{}

replyMarkupInlineKeyboard::replyMarkupInlineKeyboard(array<array<object_ptr<inlineKeyboardButton>>> &&rows_, bool force_reply_)
  : rows_(std::move(rows_))
  , force_reply_(force_reply_)
{}

const std::int32_t replyMarkupInlineKeyboard::ID;

void replyMarkupInlineKeyboard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupInlineKeyboard");
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { { s.store_vector_begin("", _value.size()); for (const auto &_value2 : _value) { s.store_object_field("", static_cast<const BaseObject *>(_value2.get())); } s.store_class_end(); } } s.store_class_end(); }
    s.store_field("force_reply", force_reply_);
    s.store_class_end();
  }
}

reportStoryResultOk::reportStoryResultOk() {
}

const std::int32_t reportStoryResultOk::ID;

void reportStoryResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportStoryResultOk");
    s.store_class_end();
  }
}

reportStoryResultOptionRequired::reportStoryResultOptionRequired()
  : title_()
  , options_()
{}

reportStoryResultOptionRequired::reportStoryResultOptionRequired(string const &title_, array<object_ptr<reportOption>> &&options_)
  : title_(title_)
  , options_(std::move(options_))
{}

const std::int32_t reportStoryResultOptionRequired::ID;

void reportStoryResultOptionRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportStoryResultOptionRequired");
    s.store_field("title", title_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportStoryResultTextRequired::reportStoryResultTextRequired()
  : option_id_()
  , is_optional_()
{}

reportStoryResultTextRequired::reportStoryResultTextRequired(bytes const &option_id_, bool is_optional_)
  : option_id_(std::move(option_id_))
  , is_optional_(is_optional_)
{}

const std::int32_t reportStoryResultTextRequired::ID;

void reportStoryResultTextRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportStoryResultTextRequired");
    s.store_bytes_field("option_id", option_id_);
    s.store_field("is_optional", is_optional_);
    s.store_class_end();
  }
}

resendCodeReasonUserRequest::resendCodeReasonUserRequest() {
}

const std::int32_t resendCodeReasonUserRequest::ID;

void resendCodeReasonUserRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendCodeReasonUserRequest");
    s.store_class_end();
  }
}

resendCodeReasonVerificationFailed::resendCodeReasonVerificationFailed()
  : error_message_()
{}

resendCodeReasonVerificationFailed::resendCodeReasonVerificationFailed(string const &error_message_)
  : error_message_(error_message_)
{}

const std::int32_t resendCodeReasonVerificationFailed::ID;

void resendCodeReasonVerificationFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendCodeReasonVerificationFailed");
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

starRevenueStatus::starRevenueStatus()
  : total_amount_()
  , current_amount_()
  , available_amount_()
  , withdrawal_enabled_()
  , next_withdrawal_in_()
{}

starRevenueStatus::starRevenueStatus(object_ptr<starAmount> &&total_amount_, object_ptr<starAmount> &&current_amount_, object_ptr<starAmount> &&available_amount_, bool withdrawal_enabled_, int32 next_withdrawal_in_)
  : total_amount_(std::move(total_amount_))
  , current_amount_(std::move(current_amount_))
  , available_amount_(std::move(available_amount_))
  , withdrawal_enabled_(withdrawal_enabled_)
  , next_withdrawal_in_(next_withdrawal_in_)
{}

const std::int32_t starRevenueStatus::ID;

void starRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starRevenueStatus");
    s.store_object_field("total_amount", static_cast<const BaseObject *>(total_amount_.get()));
    s.store_object_field("current_amount", static_cast<const BaseObject *>(current_amount_.get()));
    s.store_object_field("available_amount", static_cast<const BaseObject *>(available_amount_.get()));
    s.store_field("withdrawal_enabled", withdrawal_enabled_);
    s.store_field("next_withdrawal_in", next_withdrawal_in_);
    s.store_class_end();
  }
}

storyAlbums::storyAlbums()
  : albums_()
{}

storyAlbums::storyAlbums(array<object_ptr<storyAlbum>> &&albums_)
  : albums_(std::move(albums_))
{}

const std::int32_t storyAlbums::ID;

void storyAlbums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAlbums");
    { s.store_vector_begin("albums", albums_.size()); for (const auto &_value : albums_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyFullId::storyFullId()
  : poster_chat_id_()
  , story_id_()
{}

storyFullId::storyFullId(int53 poster_chat_id_, int32 story_id_)
  : poster_chat_id_(poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t storyFullId::ID;

void storyFullId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyFullId");
    s.store_field("poster_chat_id", poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

temporaryPasswordState::temporaryPasswordState()
  : has_password_()
  , valid_for_()
{}

temporaryPasswordState::temporaryPasswordState(bool has_password_, int32 valid_for_)
  : has_password_(has_password_)
  , valid_for_(valid_for_)
{}

const std::int32_t temporaryPasswordState::ID;

void temporaryPasswordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "temporaryPasswordState");
    s.store_field("has_password", has_password_);
    s.store_field("valid_for", valid_for_);
    s.store_class_end();
  }
}

testString::testString()
  : value_()
{}

testString::testString(string const &value_)
  : value_(value_)
{}

const std::int32_t testString::ID;

void testString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testString");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

textRange::textRange()
  : offset_()
  , length_()
{}

textRange::textRange(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t textRange::ID;

void textRange::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textRange");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

tonConnectConnectData::tonConnectConnectData()
  : session_id_()
  , challenge_answer_()
  , body_()
  , proof_()
{}

tonConnectConnectData::tonConnectConnectData(int64 session_id_, bytes const &challenge_answer_, bytes const &body_, object_ptr<tonWalletOwnershipProof> &&proof_)
  : session_id_(session_id_)
  , challenge_answer_(std::move(challenge_answer_))
  , body_(std::move(body_))
  , proof_(std::move(proof_))
{}

const std::int32_t tonConnectConnectData::ID;

void tonConnectConnectData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectConnectData");
    s.store_field("session_id", session_id_);
    s.store_bytes_field("challenge_answer", challenge_answer_);
    s.store_bytes_field("body", body_);
    s.store_object_field("proof", static_cast<const BaseObject *>(proof_.get()));
    s.store_class_end();
  }
}

tonTransactionTypeFragmentDeposit::tonTransactionTypeFragmentDeposit()
  : is_gift_()
  , sticker_()
{}

tonTransactionTypeFragmentDeposit::tonTransactionTypeFragmentDeposit(bool is_gift_, object_ptr<sticker> &&sticker_)
  : is_gift_(is_gift_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t tonTransactionTypeFragmentDeposit::ID;

void tonTransactionTypeFragmentDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeFragmentDeposit");
    s.store_field("is_gift", is_gift_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

tonTransactionTypeFragmentWithdrawal::tonTransactionTypeFragmentWithdrawal()
  : withdrawal_state_()
{}

tonTransactionTypeFragmentWithdrawal::tonTransactionTypeFragmentWithdrawal(object_ptr<RevenueWithdrawalState> &&withdrawal_state_)
  : withdrawal_state_(std::move(withdrawal_state_))
{}

const std::int32_t tonTransactionTypeFragmentWithdrawal::ID;

void tonTransactionTypeFragmentWithdrawal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeFragmentWithdrawal");
    s.store_object_field("withdrawal_state", static_cast<const BaseObject *>(withdrawal_state_.get()));
    s.store_class_end();
  }
}

tonTransactionTypeSuggestedPostPayment::tonTransactionTypeSuggestedPostPayment()
  : chat_id_()
{}

tonTransactionTypeSuggestedPostPayment::tonTransactionTypeSuggestedPostPayment(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t tonTransactionTypeSuggestedPostPayment::ID;

void tonTransactionTypeSuggestedPostPayment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeSuggestedPostPayment");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

tonTransactionTypeGiftPurchaseOffer::tonTransactionTypeGiftPurchaseOffer()
  : gift_()
{}

tonTransactionTypeGiftPurchaseOffer::tonTransactionTypeGiftPurchaseOffer(object_ptr<upgradedGift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t tonTransactionTypeGiftPurchaseOffer::ID;

void tonTransactionTypeGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeGiftPurchaseOffer");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

tonTransactionTypeUpgradedGiftPurchase::tonTransactionTypeUpgradedGiftPurchase()
  : user_id_()
  , gift_()
{}

tonTransactionTypeUpgradedGiftPurchase::tonTransactionTypeUpgradedGiftPurchase(int53 user_id_, object_ptr<upgradedGift> &&gift_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
{}

const std::int32_t tonTransactionTypeUpgradedGiftPurchase::ID;

void tonTransactionTypeUpgradedGiftPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeUpgradedGiftPurchase");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

tonTransactionTypeUpgradedGiftSale::tonTransactionTypeUpgradedGiftSale()
  : user_id_()
  , gift_()
  , commission_per_mille_()
  , commission_gram_amount_()
  , via_offer_()
{}

tonTransactionTypeUpgradedGiftSale::tonTransactionTypeUpgradedGiftSale(int53 user_id_, object_ptr<upgradedGift> &&gift_, int32 commission_per_mille_, int53 commission_gram_amount_, bool via_offer_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
  , commission_per_mille_(commission_per_mille_)
  , commission_gram_amount_(commission_gram_amount_)
  , via_offer_(via_offer_)
{}

const std::int32_t tonTransactionTypeUpgradedGiftSale::ID;

void tonTransactionTypeUpgradedGiftSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeUpgradedGiftSale");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_field("commission_gram_amount", commission_gram_amount_);
    s.store_field("via_offer", via_offer_);
    s.store_class_end();
  }
}

tonTransactionTypeStakeDiceStake::tonTransactionTypeStakeDiceStake() {
}

const std::int32_t tonTransactionTypeStakeDiceStake::ID;

void tonTransactionTypeStakeDiceStake::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeStakeDiceStake");
    s.store_class_end();
  }
}

tonTransactionTypeStakeDicePayout::tonTransactionTypeStakeDicePayout() {
}

const std::int32_t tonTransactionTypeStakeDicePayout::ID;

void tonTransactionTypeStakeDicePayout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeStakeDicePayout");
    s.store_class_end();
  }
}

tonTransactionTypeUnsupported::tonTransactionTypeUnsupported() {
}

const std::int32_t tonTransactionTypeUnsupported::ID;

void tonTransactionTypeUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeUnsupported");
    s.store_class_end();
  }
}

tonWalletSecretPhrase::tonWalletSecretPhrase()
  : secret_phrase_()
{}

tonWalletSecretPhrase::tonWalletSecretPhrase(string const &secret_phrase_)
  : secret_phrase_(secret_phrase_)
{}

const std::int32_t tonWalletSecretPhrase::ID;

void tonWalletSecretPhrase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletSecretPhrase");
    s.store_field("secret_phrase", "[REDACTED]");
    s.store_class_end();
  }
}

tonWalletTransactionTypeOnRampDeposit::tonWalletTransactionTypeOnRampDeposit()
  : amount_()
  , provider_name_()
{}

tonWalletTransactionTypeOnRampDeposit::tonWalletTransactionTypeOnRampDeposit(int64 amount_, string const &provider_name_)
  : amount_(amount_)
  , provider_name_(provider_name_)
{}

const std::int32_t tonWalletTransactionTypeOnRampDeposit::ID;

void tonWalletTransactionTypeOnRampDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransactionTypeOnRampDeposit");
    s.store_field("amount", amount_);
    s.store_field("provider_name", provider_name_);
    s.store_class_end();
  }
}

tonWalletTransactionTypeTransfer::tonWalletTransactionTypeTransfer()
  : amount_()
  , is_gasless_()
  , comment_()
  , is_comment_encrypted_()
{}

tonWalletTransactionTypeTransfer::tonWalletTransactionTypeTransfer(int64 amount_, bool is_gasless_, string const &comment_, bool is_comment_encrypted_)
  : amount_(amount_)
  , is_gasless_(is_gasless_)
  , comment_(comment_)
  , is_comment_encrypted_(is_comment_encrypted_)
{}

const std::int32_t tonWalletTransactionTypeTransfer::ID;

void tonWalletTransactionTypeTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransactionTypeTransfer");
    s.store_field("amount", amount_);
    s.store_field("is_gasless", is_gasless_);
    s.store_field("comment", comment_);
    s.store_field("is_comment_encrypted", is_comment_encrypted_);
    s.store_class_end();
  }
}

tonWalletTransactionTypeNftTransfer::tonWalletTransactionTypeNftTransfer()
  : nft_()
  , is_outgoing_()
  , comment_()
  , is_comment_encrypted_()
{}

tonWalletTransactionTypeNftTransfer::tonWalletTransactionTypeNftTransfer(object_ptr<tonNft> &&nft_, bool is_outgoing_, string const &comment_, bool is_comment_encrypted_)
  : nft_(std::move(nft_))
  , is_outgoing_(is_outgoing_)
  , comment_(comment_)
  , is_comment_encrypted_(is_comment_encrypted_)
{}

const std::int32_t tonWalletTransactionTypeNftTransfer::ID;

void tonWalletTransactionTypeNftTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransactionTypeNftTransfer");
    s.store_object_field("nft", static_cast<const BaseObject *>(nft_.get()));
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("comment", comment_);
    s.store_field("is_comment_encrypted", is_comment_encrypted_);
    s.store_class_end();
  }
}

tonWalletTransactionTypeTelegramGiftTransfer::tonWalletTransactionTypeTelegramGiftTransfer()
  : nft_()
  , is_outgoing_()
  , is_saved_()
{}

tonWalletTransactionTypeTelegramGiftTransfer::tonWalletTransactionTypeTelegramGiftTransfer(object_ptr<tonNft> &&nft_, bool is_outgoing_, bool is_saved_)
  : nft_(std::move(nft_))
  , is_outgoing_(is_outgoing_)
  , is_saved_(is_saved_)
{}

const std::int32_t tonWalletTransactionTypeTelegramGiftTransfer::ID;

void tonWalletTransactionTypeTelegramGiftTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransactionTypeTelegramGiftTransfer");
    s.store_object_field("nft", static_cast<const BaseObject *>(nft_.get()));
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("is_saved", is_saved_);
    s.store_class_end();
  }
}

tonWalletTransactionTypeKeyChange::tonWalletTransactionTypeKeyChange() {
}

const std::int32_t tonWalletTransactionTypeKeyChange::ID;

void tonWalletTransactionTypeKeyChange::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransactionTypeKeyChange");
    s.store_class_end();
  }
}

upgradedGiftAttributeIdModel::upgradedGiftAttributeIdModel()
  : sticker_id_()
{}

upgradedGiftAttributeIdModel::upgradedGiftAttributeIdModel(int64 sticker_id_)
  : sticker_id_(sticker_id_)
{}

const std::int32_t upgradedGiftAttributeIdModel::ID;

void upgradedGiftAttributeIdModel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeIdModel");
    s.store_field("sticker_id", sticker_id_);
    s.store_class_end();
  }
}

upgradedGiftAttributeIdSymbol::upgradedGiftAttributeIdSymbol()
  : sticker_id_()
{}

upgradedGiftAttributeIdSymbol::upgradedGiftAttributeIdSymbol(int64 sticker_id_)
  : sticker_id_(sticker_id_)
{}

const std::int32_t upgradedGiftAttributeIdSymbol::ID;

void upgradedGiftAttributeIdSymbol::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeIdSymbol");
    s.store_field("sticker_id", sticker_id_);
    s.store_class_end();
  }
}

upgradedGiftAttributeIdBackdrop::upgradedGiftAttributeIdBackdrop()
  : backdrop_id_()
{}

upgradedGiftAttributeIdBackdrop::upgradedGiftAttributeIdBackdrop(int32 backdrop_id_)
  : backdrop_id_(backdrop_id_)
{}

const std::int32_t upgradedGiftAttributeIdBackdrop::ID;

void upgradedGiftAttributeIdBackdrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeIdBackdrop");
    s.store_field("backdrop_id", backdrop_id_);
    s.store_class_end();
  }
}

upgradedGiftValueInfo::upgradedGiftValueInfo()
  : currency_()
  , value_()
  , is_value_average_()
  , initial_sale_date_()
  , initial_sale_star_count_()
  , initial_sale_price_()
  , last_sale_date_()
  , last_sale_price_()
  , is_last_sale_on_fragment_()
  , minimum_price_()
  , average_sale_price_()
  , telegram_listed_gift_count_()
  , fragment_listed_gift_count_()
  , fragment_url_()
{}

upgradedGiftValueInfo::upgradedGiftValueInfo(string const &currency_, int53 value_, bool is_value_average_, int32 initial_sale_date_, int53 initial_sale_star_count_, int53 initial_sale_price_, int32 last_sale_date_, int53 last_sale_price_, bool is_last_sale_on_fragment_, int53 minimum_price_, int53 average_sale_price_, int32 telegram_listed_gift_count_, int32 fragment_listed_gift_count_, string const &fragment_url_)
  : currency_(currency_)
  , value_(value_)
  , is_value_average_(is_value_average_)
  , initial_sale_date_(initial_sale_date_)
  , initial_sale_star_count_(initial_sale_star_count_)
  , initial_sale_price_(initial_sale_price_)
  , last_sale_date_(last_sale_date_)
  , last_sale_price_(last_sale_price_)
  , is_last_sale_on_fragment_(is_last_sale_on_fragment_)
  , minimum_price_(minimum_price_)
  , average_sale_price_(average_sale_price_)
  , telegram_listed_gift_count_(telegram_listed_gift_count_)
  , fragment_listed_gift_count_(fragment_listed_gift_count_)
  , fragment_url_(fragment_url_)
{}

const std::int32_t upgradedGiftValueInfo::ID;

void upgradedGiftValueInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftValueInfo");
    s.store_field("currency", currency_);
    s.store_field("value", value_);
    s.store_field("is_value_average", is_value_average_);
    s.store_field("initial_sale_date", initial_sale_date_);
    s.store_field("initial_sale_star_count", initial_sale_star_count_);
    s.store_field("initial_sale_price", initial_sale_price_);
    s.store_field("last_sale_date", last_sale_date_);
    s.store_field("last_sale_price", last_sale_price_);
    s.store_field("is_last_sale_on_fragment", is_last_sale_on_fragment_);
    s.store_field("minimum_price", minimum_price_);
    s.store_field("average_sale_price", average_sale_price_);
    s.store_field("telegram_listed_gift_count", telegram_listed_gift_count_);
    s.store_field("fragment_listed_gift_count", fragment_listed_gift_count_);
    s.store_field("fragment_url", fragment_url_);
    s.store_class_end();
  }
}

userFullInfo::userFullInfo()
  : personal_photo_()
  , photo_()
  , public_photo_()
  , community_id_()
  , block_list_()
  , can_be_called_()
  , supports_video_calls_()
  , has_private_calls_()
  , has_private_forwards_()
  , has_restricted_voice_and_video_note_messages_()
  , has_posted_to_profile_stories_()
  , has_sponsored_messages_enabled_()
  , need_phone_number_privacy_exception_()
  , set_chat_background_()
  , uses_unofficial_app_()
  , bio_()
  , birthdate_()
  , personal_chat_id_()
  , gift_count_()
  , group_in_common_count_()
  , incoming_paid_message_star_count_()
  , outgoing_paid_message_star_count_()
  , gift_settings_()
  , bot_verification_()
  , main_profile_tab_()
  , first_profile_audio_()
  , rating_()
  , pending_rating_()
  , pending_rating_date_()
  , note_()
  , ton_wallet_card_()
  , share_theme_()
  , business_info_()
  , bot_info_()
{}

userFullInfo::userFullInfo(object_ptr<chatPhoto> &&personal_photo_, object_ptr<chatPhoto> &&photo_, object_ptr<chatPhoto> &&public_photo_, int53 community_id_, object_ptr<BlockList> &&block_list_, bool can_be_called_, bool supports_video_calls_, bool has_private_calls_, bool has_private_forwards_, bool has_restricted_voice_and_video_note_messages_, bool has_posted_to_profile_stories_, bool has_sponsored_messages_enabled_, bool need_phone_number_privacy_exception_, bool set_chat_background_, bool uses_unofficial_app_, object_ptr<formattedText> &&bio_, object_ptr<birthdate> &&birthdate_, int53 personal_chat_id_, int32 gift_count_, int32 group_in_common_count_, int53 incoming_paid_message_star_count_, int53 outgoing_paid_message_star_count_, object_ptr<giftSettings> &&gift_settings_, object_ptr<botVerification> &&bot_verification_, object_ptr<ProfileTab> &&main_profile_tab_, object_ptr<audio> &&first_profile_audio_, object_ptr<userRating> &&rating_, object_ptr<userRating> &&pending_rating_, int32 pending_rating_date_, object_ptr<formattedText> &&note_, object_ptr<tonWalletCard> &&ton_wallet_card_, object_ptr<ProfileShareTheme> &&share_theme_, object_ptr<businessInfo> &&business_info_, object_ptr<botInfo> &&bot_info_)
  : personal_photo_(std::move(personal_photo_))
  , photo_(std::move(photo_))
  , public_photo_(std::move(public_photo_))
  , community_id_(community_id_)
  , block_list_(std::move(block_list_))
  , can_be_called_(can_be_called_)
  , supports_video_calls_(supports_video_calls_)
  , has_private_calls_(has_private_calls_)
  , has_private_forwards_(has_private_forwards_)
  , has_restricted_voice_and_video_note_messages_(has_restricted_voice_and_video_note_messages_)
  , has_posted_to_profile_stories_(has_posted_to_profile_stories_)
  , has_sponsored_messages_enabled_(has_sponsored_messages_enabled_)
  , need_phone_number_privacy_exception_(need_phone_number_privacy_exception_)
  , set_chat_background_(set_chat_background_)
  , uses_unofficial_app_(uses_unofficial_app_)
  , bio_(std::move(bio_))
  , birthdate_(std::move(birthdate_))
  , personal_chat_id_(personal_chat_id_)
  , gift_count_(gift_count_)
  , group_in_common_count_(group_in_common_count_)
  , incoming_paid_message_star_count_(incoming_paid_message_star_count_)
  , outgoing_paid_message_star_count_(outgoing_paid_message_star_count_)
  , gift_settings_(std::move(gift_settings_))
  , bot_verification_(std::move(bot_verification_))
  , main_profile_tab_(std::move(main_profile_tab_))
  , first_profile_audio_(std::move(first_profile_audio_))
  , rating_(std::move(rating_))
  , pending_rating_(std::move(pending_rating_))
  , pending_rating_date_(pending_rating_date_)
  , note_(std::move(note_))
  , ton_wallet_card_(std::move(ton_wallet_card_))
  , share_theme_(std::move(share_theme_))
  , business_info_(std::move(business_info_))
  , bot_info_(std::move(bot_info_))
{}

const std::int32_t userFullInfo::ID;

void userFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userFullInfo");
    s.store_object_field("personal_photo", static_cast<const BaseObject *>(personal_photo_.get()));
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("public_photo", static_cast<const BaseObject *>(public_photo_.get()));
    s.store_field("community_id", community_id_);
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_field("can_be_called", can_be_called_);
    s.store_field("supports_video_calls", supports_video_calls_);
    s.store_field("has_private_calls", has_private_calls_);
    s.store_field("has_private_forwards", has_private_forwards_);
    s.store_field("has_restricted_voice_and_video_note_messages", has_restricted_voice_and_video_note_messages_);
    s.store_field("has_posted_to_profile_stories", has_posted_to_profile_stories_);
    s.store_field("has_sponsored_messages_enabled", has_sponsored_messages_enabled_);
    s.store_field("need_phone_number_privacy_exception", need_phone_number_privacy_exception_);
    s.store_field("set_chat_background", set_chat_background_);
    s.store_field("uses_unofficial_app", uses_unofficial_app_);
    s.store_object_field("bio", static_cast<const BaseObject *>(bio_.get()));
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_field("personal_chat_id", personal_chat_id_);
    s.store_field("gift_count", gift_count_);
    s.store_field("group_in_common_count", group_in_common_count_);
    s.store_field("incoming_paid_message_star_count", incoming_paid_message_star_count_);
    s.store_field("outgoing_paid_message_star_count", outgoing_paid_message_star_count_);
    s.store_object_field("gift_settings", static_cast<const BaseObject *>(gift_settings_.get()));
    s.store_object_field("bot_verification", static_cast<const BaseObject *>(bot_verification_.get()));
    s.store_object_field("main_profile_tab", static_cast<const BaseObject *>(main_profile_tab_.get()));
    s.store_object_field("first_profile_audio", static_cast<const BaseObject *>(first_profile_audio_.get()));
    s.store_object_field("rating", static_cast<const BaseObject *>(rating_.get()));
    s.store_object_field("pending_rating", static_cast<const BaseObject *>(pending_rating_.get()));
    s.store_field("pending_rating_date", pending_rating_date_);
    s.store_object_field("note", static_cast<const BaseObject *>(note_.get()));
    s.store_object_field("ton_wallet_card", static_cast<const BaseObject *>(ton_wallet_card_.get()));
    s.store_object_field("share_theme", static_cast<const BaseObject *>(share_theme_.get()));
    s.store_object_field("business_info", static_cast<const BaseObject *>(business_info_.get()));
    s.store_object_field("bot_info", static_cast<const BaseObject *>(bot_info_.get()));
    s.store_class_end();
  }
}

venue::venue()
  : location_()
  , title_()
  , address_()
  , provider_()
  , id_()
  , type_()
{}

venue::venue(object_ptr<location> &&location_, string const &title_, string const &address_, string const &provider_, string const &id_, string const &type_)
  : location_(std::move(location_))
  , title_(title_)
  , address_(address_)
  , provider_(provider_)
  , id_(id_)
  , type_(type_)
{}

const std::int32_t venue::ID;

void venue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "venue");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("id", id_);
    s.store_field("type", type_);
    s.store_class_end();
  }
}

videoMessageAdvertisement::videoMessageAdvertisement()
  : unique_id_()
  , text_()
  , min_display_duration_()
  , max_display_duration_()
  , can_be_reported_()
  , sponsor_()
  , title_()
  , additional_info_()
{}

videoMessageAdvertisement::videoMessageAdvertisement(int53 unique_id_, string const &text_, int32 min_display_duration_, int32 max_display_duration_, bool can_be_reported_, object_ptr<advertisementSponsor> &&sponsor_, string const &title_, string const &additional_info_)
  : unique_id_(unique_id_)
  , text_(text_)
  , min_display_duration_(min_display_duration_)
  , max_display_duration_(max_display_duration_)
  , can_be_reported_(can_be_reported_)
  , sponsor_(std::move(sponsor_))
  , title_(title_)
  , additional_info_(additional_info_)
{}

const std::int32_t videoMessageAdvertisement::ID;

void videoMessageAdvertisement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoMessageAdvertisement");
    s.store_field("unique_id", unique_id_);
    s.store_field("text", text_);
    s.store_field("min_display_duration", min_display_duration_);
    s.store_field("max_display_duration", max_display_duration_);
    s.store_field("can_be_reported", can_be_reported_);
    s.store_object_field("sponsor", static_cast<const BaseObject *>(sponsor_.get()));
    s.store_field("title", title_);
    s.store_field("additional_info", additional_info_);
    s.store_class_end();
  }
}

videoStoryboard::videoStoryboard()
  : storyboard_file_()
  , width_()
  , height_()
  , map_file_()
{}

videoStoryboard::videoStoryboard(object_ptr<file> &&storyboard_file_, int32 width_, int32 height_, object_ptr<file> &&map_file_)
  : storyboard_file_(std::move(storyboard_file_))
  , width_(width_)
  , height_(height_)
  , map_file_(std::move(map_file_))
{}

const std::int32_t videoStoryboard::ID;

void videoStoryboard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoStoryboard");
    s.store_object_field("storyboard_file", static_cast<const BaseObject *>(storyboard_file_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("map_file", static_cast<const BaseObject *>(map_file_.get()));
    s.store_class_end();
  }
}

webProxyCarrier::webProxyCarrier()
  : id_()
  , proxy_id_()
  , url_()
  , origin_()
  , path_prefix_()
  , bridge_object_name_()
  , is_temporary_()
{}

webProxyCarrier::webProxyCarrier(int32 id_, int32 proxy_id_, string const &url_, string const &origin_, string const &path_prefix_, string const &bridge_object_name_, bool is_temporary_)
  : id_(id_)
  , proxy_id_(proxy_id_)
  , url_(url_)
  , origin_(origin_)
  , path_prefix_(path_prefix_)
  , bridge_object_name_(bridge_object_name_)
  , is_temporary_(is_temporary_)
{}

const std::int32_t webProxyCarrier::ID;

void webProxyCarrier::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webProxyCarrier");
    s.store_field("id", id_);
    s.store_field("proxy_id", proxy_id_);
    s.store_field("url", url_);
    s.store_field("origin", origin_);
    s.store_field("path_prefix", path_prefix_);
    s.store_field("bridge_object_name", bridge_object_name_);
    s.store_field("is_temporary", is_temporary_);
    s.store_class_end();
  }
}

acceptTermsOfService::acceptTermsOfService()
  : terms_of_service_id_()
{}

acceptTermsOfService::acceptTermsOfService(string const &terms_of_service_id_)
  : terms_of_service_id_(terms_of_service_id_)
{}

const std::int32_t acceptTermsOfService::ID;

void acceptTermsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "acceptTermsOfService");
    s.store_field("terms_of_service_id", terms_of_service_id_);
    s.store_class_end();
  }
}

addChatWelcomeMessage::addChatWelcomeMessage()
  : chat_id_()
  , input_message_content_()
{}

addChatWelcomeMessage::addChatWelcomeMessage(int53 chat_id_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t addChatWelcomeMessage::ID;

void addChatWelcomeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatWelcomeMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

allowUnpaidMessagesFromUser::allowUnpaidMessagesFromUser()
  : user_id_()
  , refund_payments_()
{}

allowUnpaidMessagesFromUser::allowUnpaidMessagesFromUser(int53 user_id_, bool refund_payments_)
  : user_id_(user_id_)
  , refund_payments_(refund_payments_)
{}

const std::int32_t allowUnpaidMessagesFromUser::ID;

void allowUnpaidMessagesFromUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "allowUnpaidMessagesFromUser");
    s.store_field("user_id", user_id_);
    s.store_field("refund_payments", refund_payments_);
    s.store_class_end();
  }
}

canSendMessageToUser::canSendMessageToUser()
  : user_id_()
  , only_local_()
{}

canSendMessageToUser::canSendMessageToUser(int53 user_id_, bool only_local_)
  : user_id_(user_id_)
  , only_local_(only_local_)
{}

const std::int32_t canSendMessageToUser::ID;

void canSendMessageToUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendMessageToUser");
    s.store_field("user_id", user_id_);
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

clearAllDraftMessages::clearAllDraftMessages()
  : exclude_secret_chats_()
{}

clearAllDraftMessages::clearAllDraftMessages(bool exclude_secret_chats_)
  : exclude_secret_chats_(exclude_secret_chats_)
{}

const std::int32_t clearAllDraftMessages::ID;

void clearAllDraftMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearAllDraftMessages");
    s.store_field("exclude_secret_chats", exclude_secret_chats_);
    s.store_class_end();
  }
}

commitPendingLiveStoryReactions::commitPendingLiveStoryReactions()
  : group_call_id_()
{}

commitPendingLiveStoryReactions::commitPendingLiveStoryReactions(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t commitPendingLiveStoryReactions::ID;

void commitPendingLiveStoryReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "commitPendingLiveStoryReactions");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

createForumTopic::createForumTopic()
  : chat_id_()
  , name_()
  , is_name_implicit_()
  , icon_()
{}

createForumTopic::createForumTopic(int53 chat_id_, string const &name_, bool is_name_implicit_, object_ptr<forumTopicIcon> &&icon_)
  : chat_id_(chat_id_)
  , name_(name_)
  , is_name_implicit_(is_name_implicit_)
  , icon_(std::move(icon_))
{}

const std::int32_t createForumTopic::ID;

void createForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createForumTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("name", name_);
    s.store_field("is_name_implicit", is_name_implicit_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_class_end();
  }
}

createPrivateChat::createPrivateChat()
  : user_id_()
  , force_()
{}

createPrivateChat::createPrivateChat(int53 user_id_, bool force_)
  : user_id_(user_id_)
  , force_(force_)
{}

const std::int32_t createPrivateChat::ID;

void createPrivateChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createPrivateChat");
    s.store_field("user_id", user_id_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

declineGroupCallInvitation::declineGroupCallInvitation()
  : chat_id_()
  , message_id_()
{}

declineGroupCallInvitation::declineGroupCallInvitation(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t declineGroupCallInvitation::ID;

void declineGroupCallInvitation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "declineGroupCallInvitation");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

deleteAccount::deleteAccount()
  : reason_()
  , password_()
{}

deleteAccount::deleteAccount(string const &reason_, string const &password_)
  : reason_(reason_)
  , password_(password_)
{}

const std::int32_t deleteAccount::ID;

void deleteAccount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteAccount");
    s.store_field("reason", reason_);
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

deleteBusinessMessages::deleteBusinessMessages()
  : business_connection_id_()
  , message_ids_()
{}

deleteBusinessMessages::deleteBusinessMessages(string const &business_connection_id_, array<int53> &&message_ids_)
  : business_connection_id_(business_connection_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t deleteBusinessMessages::ID;

void deleteBusinessMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteBusinessMessages");
    s.store_field("business_connection_id", business_connection_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

deleteChatMessagesByDate::deleteChatMessagesByDate()
  : chat_id_()
  , min_date_()
  , max_date_()
  , revoke_()
{}

deleteChatMessagesByDate::deleteChatMessagesByDate(int53 chat_id_, int32 min_date_, int32 max_date_, bool revoke_)
  : chat_id_(chat_id_)
  , min_date_(min_date_)
  , max_date_(max_date_)
  , revoke_(revoke_)
{}

const std::int32_t deleteChatMessagesByDate::ID;

void deleteChatMessagesByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatMessagesByDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

deleteChatReplyMarkup::deleteChatReplyMarkup()
  : chat_id_()
  , message_id_()
{}

deleteChatReplyMarkup::deleteChatReplyMarkup(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t deleteChatReplyMarkup::ID;

void deleteChatReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatReplyMarkup");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

deleteCommunity::deleteCommunity()
  : community_id_()
{}

deleteCommunity::deleteCommunity(int53 community_id_)
  : community_id_(community_id_)
{}

const std::int32_t deleteCommunity::ID;

void deleteCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteCommunity");
    s.store_field("community_id", community_id_);
    s.store_class_end();
  }
}

deleteDirectMessagesChatTopicMessagesByDate::deleteDirectMessagesChatTopicMessagesByDate()
  : chat_id_()
  , topic_id_()
  , min_date_()
  , max_date_()
{}

deleteDirectMessagesChatTopicMessagesByDate::deleteDirectMessagesChatTopicMessagesByDate(int53 chat_id_, int53 topic_id_, int32 min_date_, int32 max_date_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
  , min_date_(min_date_)
  , max_date_(max_date_)
{}

const std::int32_t deleteDirectMessagesChatTopicMessagesByDate::ID;

void deleteDirectMessagesChatTopicMessagesByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteDirectMessagesChatTopicMessagesByDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_class_end();
  }
}

deleteEphemeralMessage::deleteEphemeralMessage()
  : chat_id_()
  , receiver_user_id_()
  , ephemeral_message_id_()
{}

deleteEphemeralMessage::deleteEphemeralMessage(int53 chat_id_, int53 receiver_user_id_, int32 ephemeral_message_id_)
  : chat_id_(chat_id_)
  , receiver_user_id_(receiver_user_id_)
  , ephemeral_message_id_(ephemeral_message_id_)
{}

const std::int32_t deleteEphemeralMessage::ID;

void deleteEphemeralMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteEphemeralMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("receiver_user_id", receiver_user_id_);
    s.store_field("ephemeral_message_id", ephemeral_message_id_);
    s.store_class_end();
  }
}

deleteForumTopic::deleteForumTopic()
  : chat_id_()
  , forum_topic_id_()
{}

deleteForumTopic::deleteForumTopic(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t deleteForumTopic::ID;

void deleteForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteForumTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

deleteQuickReplyShortcutMessages::deleteQuickReplyShortcutMessages()
  : shortcut_id_()
  , message_ids_()
{}

deleteQuickReplyShortcutMessages::deleteQuickReplyShortcutMessages(int32 shortcut_id_, array<int53> &&message_ids_)
  : shortcut_id_(shortcut_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t deleteQuickReplyShortcutMessages::ID;

void deleteQuickReplyShortcutMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteQuickReplyShortcutMessages");
    s.store_field("shortcut_id", shortcut_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

disconnectWebsite::disconnectWebsite()
  : website_id_()
{}

disconnectWebsite::disconnectWebsite(int64 website_id_)
  : website_id_(website_id_)
{}

const std::int32_t disconnectWebsite::ID;

void disconnectWebsite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disconnectWebsite");
    s.store_field("website_id", website_id_);
    s.store_class_end();
  }
}

dropGiftOriginalDetails::dropGiftOriginalDetails()
  : received_gift_id_()
  , star_count_()
{}

dropGiftOriginalDetails::dropGiftOriginalDetails(string const &received_gift_id_, int53 star_count_)
  : received_gift_id_(received_gift_id_)
  , star_count_(star_count_)
{}

const std::int32_t dropGiftOriginalDetails::ID;

void dropGiftOriginalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dropGiftOriginalDetails");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

editBusinessMessageChecklist::editBusinessMessageChecklist()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
  , checklist_()
{}

editBusinessMessageChecklist::editBusinessMessageChecklist(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<inputChecklist> &&checklist_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , checklist_(std::move(checklist_))
{}

const std::int32_t editBusinessMessageChecklist::ID;

void editBusinessMessageChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageChecklist");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("checklist", static_cast<const BaseObject *>(checklist_.get()));
    s.store_class_end();
  }
}

editChatFolder::editChatFolder()
  : chat_folder_id_()
  , folder_()
{}

editChatFolder::editChatFolder(int32 chat_folder_id_, object_ptr<chatFolder> &&folder_)
  : chat_folder_id_(chat_folder_id_)
  , folder_(std::move(folder_))
{}

const std::int32_t editChatFolder::ID;

void editChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editChatFolder");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_class_end();
  }
}

editInlineMessageCaption::editInlineMessageCaption()
  : inline_message_id_()
  , reply_markup_()
  , caption_()
  , show_caption_above_media_()
{}

editInlineMessageCaption::editInlineMessageCaption(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
{}

const std::int32_t editInlineMessageCaption::ID;

void editInlineMessageCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageCaption");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_class_end();
  }
}

editMessageChecklist::editMessageChecklist()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , checklist_()
{}

editMessageChecklist::editMessageChecklist(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<inputChecklist> &&checklist_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , checklist_(std::move(checklist_))
{}

const std::int32_t editMessageChecklist::ID;

void editMessageChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageChecklist");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("checklist", static_cast<const BaseObject *>(checklist_.get()));
    s.store_class_end();
  }
}

editMessageMedia::editMessageMedia()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editMessageMedia::editMessageMedia(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editMessageMedia::ID;

void editMessageMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageMedia");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editMessageText::editMessageText()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editMessageText::editMessageText(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editMessageText::ID;

void editMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageText");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

endGroupCallScreenSharing::endGroupCallScreenSharing()
  : group_call_id_()
{}

endGroupCallScreenSharing::endGroupCallScreenSharing(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t endGroupCallScreenSharing::ID;

void endGroupCallScreenSharing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "endGroupCallScreenSharing");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

fixRecognizedTextWithAi::fixRecognizedTextWithAi()
  : text_()
{}

fixRecognizedTextWithAi::fixRecognizedTextWithAi(object_ptr<formattedText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t fixRecognizedTextWithAi::ID;

void fixRecognizedTextWithAi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fixRecognizedTextWithAi");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

fixTextWithAi::fixTextWithAi()
  : text_()
{}

fixTextWithAi::fixTextWithAi(object_ptr<formattedText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t fixTextWithAi::ID;

void fixTextWithAi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fixTextWithAi");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

getAllPassportElements::getAllPassportElements()
  : password_()
{}

getAllPassportElements::getAllPassportElements(string const &password_)
  : password_(password_)
{}

const std::int32_t getAllPassportElements::ID;

void getAllPassportElements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAllPassportElements");
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

getAttachedStickerSets::getAttachedStickerSets()
  : file_id_()
{}

getAttachedStickerSets::getAttachedStickerSets(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t getAttachedStickerSets::ID;

void getAttachedStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAttachedStickerSets");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

getBasicGroup::getBasicGroup()
  : basic_group_id_()
{}

getBasicGroup::getBasicGroup(int53 basic_group_id_)
  : basic_group_id_(basic_group_id_)
{}

const std::int32_t getBasicGroup::ID;

void getBasicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBasicGroup");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

getBasicGroupFullInfo::getBasicGroupFullInfo()
  : basic_group_id_()
{}

getBasicGroupFullInfo::getBasicGroupFullInfo(int53 basic_group_id_)
  : basic_group_id_(basic_group_id_)
{}

const std::int32_t getBasicGroupFullInfo::ID;

void getBasicGroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBasicGroupFullInfo");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

getBotMediaPreviewInfo::getBotMediaPreviewInfo()
  : bot_user_id_()
  , language_code_()
{}

getBotMediaPreviewInfo::getBotMediaPreviewInfo(int53 bot_user_id_, string const &language_code_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
{}

const std::int32_t getBotMediaPreviewInfo::ID;

void getBotMediaPreviewInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotMediaPreviewInfo");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getChatActiveStories::getChatActiveStories()
  : chat_id_()
{}

getChatActiveStories::getChatActiveStories(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatActiveStories::ID;

void getChatActiveStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatActiveStories");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatAvailablePaidMessageReactionSenders::getChatAvailablePaidMessageReactionSenders()
  : chat_id_()
{}

getChatAvailablePaidMessageReactionSenders::getChatAvailablePaidMessageReactionSenders(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatAvailablePaidMessageReactionSenders::ID;

void getChatAvailablePaidMessageReactionSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatAvailablePaidMessageReactionSenders");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatInviteLinkCounts::getChatInviteLinkCounts()
  : chat_id_()
{}

getChatInviteLinkCounts::getChatInviteLinkCounts(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatInviteLinkCounts::ID;

void getChatInviteLinkCounts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLinkCounts");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatRevenueStatistics::getChatRevenueStatistics()
  : chat_id_()
  , is_dark_()
{}

getChatRevenueStatistics::getChatRevenueStatistics(int53 chat_id_, bool is_dark_)
  : chat_id_(chat_id_)
  , is_dark_(is_dark_)
{}

const std::int32_t getChatRevenueStatistics::ID;

void getChatRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatRevenueStatistics");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getChatScheduledMessages::getChatScheduledMessages()
  : chat_id_()
{}

getChatScheduledMessages::getChatScheduledMessages(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatScheduledMessages::ID;

void getChatScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatScheduledMessages");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getCountryFlagEmoji::getCountryFlagEmoji()
  : country_code_()
{}

getCountryFlagEmoji::getCountryFlagEmoji(string const &country_code_)
  : country_code_(country_code_)
{}

const std::int32_t getCountryFlagEmoji::ID;

void getCountryFlagEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCountryFlagEmoji");
    s.store_field("country_code", country_code_);
    s.store_class_end();
  }
}

getCurrentState::getCurrentState() {
}

const std::int32_t getCurrentState::ID;

void getCurrentState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCurrentState");
    s.store_class_end();
  }
}

getDirectMessagesChatTopicRevenue::getDirectMessagesChatTopicRevenue()
  : chat_id_()
  , topic_id_()
{}

getDirectMessagesChatTopicRevenue::getDirectMessagesChatTopicRevenue(int53 chat_id_, int53 topic_id_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
{}

const std::int32_t getDirectMessagesChatTopicRevenue::ID;

void getDirectMessagesChatTopicRevenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDirectMessagesChatTopicRevenue");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

getExternalLink::getExternalLink()
  : link_()
  , allow_write_access_()
{}

getExternalLink::getExternalLink(string const &link_, bool allow_write_access_)
  : link_(link_)
  , allow_write_access_(allow_write_access_)
{}

const std::int32_t getExternalLink::ID;

void getExternalLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getExternalLink");
    s.store_field("link", link_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_class_end();
  }
}

getFileExtension::getFileExtension()
  : mime_type_()
{}

getFileExtension::getFileExtension(string const &mime_type_)
  : mime_type_(mime_type_)
{}

const std::int32_t getFileExtension::ID;

void getFileExtension::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFileExtension");
    s.store_field("mime_type", mime_type_);
    s.store_class_end();
  }
}

getGiveawayInfo::getGiveawayInfo()
  : chat_id_()
  , message_id_()
{}

getGiveawayInfo::getGiveawayInfo(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getGiveawayInfo::ID;

void getGiveawayInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiveawayInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getInternalLinkType::getInternalLinkType()
  : link_()
{}

getInternalLinkType::getInternalLinkType(string const &link_)
  : link_(link_)
{}

const std::int32_t getInternalLinkType::ID;

void getInternalLinkType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInternalLinkType");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

getLinkWebBrowserType::getLinkWebBrowserType()
  : link_()
{}

getLinkWebBrowserType::getLinkWebBrowserType(string const &link_)
  : link_(link_)
{}

const std::int32_t getLinkWebBrowserType::ID;

void getLinkWebBrowserType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLinkWebBrowserType");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

getLiveStoryAvailableMessageSenders::getLiveStoryAvailableMessageSenders()
  : group_call_id_()
{}

getLiveStoryAvailableMessageSenders::getLiveStoryAvailableMessageSenders(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getLiveStoryAvailableMessageSenders::ID;

void getLiveStoryAvailableMessageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLiveStoryAvailableMessageSenders");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getLocalizationTargetInfo::getLocalizationTargetInfo()
  : only_local_()
{}

getLocalizationTargetInfo::getLocalizationTargetInfo(bool only_local_)
  : only_local_(only_local_)
{}

const std::int32_t getLocalizationTargetInfo::ID;

void getLocalizationTargetInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLocalizationTargetInfo");
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

getMessageAvailableReactions::getMessageAvailableReactions()
  : chat_id_()
  , message_id_()
  , row_size_()
{}

getMessageAvailableReactions::getMessageAvailableReactions(int53 chat_id_, int53 message_id_, int32 row_size_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , row_size_(row_size_)
{}

const std::int32_t getMessageAvailableReactions::ID;

void getMessageAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageAvailableReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("row_size", row_size_);
    s.store_class_end();
  }
}

getMessageLink::getMessageLink()
  : chat_id_()
  , message_id_()
  , media_timestamp_()
  , checklist_task_id_()
  , poll_option_id_()
  , for_album_()
  , in_message_thread_()
{}

getMessageLink::getMessageLink(int53 chat_id_, int53 message_id_, int32 media_timestamp_, int32 checklist_task_id_, string const &poll_option_id_, bool for_album_, bool in_message_thread_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , media_timestamp_(media_timestamp_)
  , checklist_task_id_(checklist_task_id_)
  , poll_option_id_(poll_option_id_)
  , for_album_(for_album_)
  , in_message_thread_(in_message_thread_)
{}

const std::int32_t getMessageLink::ID;

void getMessageLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("media_timestamp", media_timestamp_);
    s.store_field("checklist_task_id", checklist_task_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_field("for_album", for_album_);
    s.store_field("in_message_thread", in_message_thread_);
    s.store_class_end();
  }
}

getMessageThreadHistory::getMessageThreadHistory()
  : chat_id_()
  , message_id_()
  , from_message_id_()
  , offset_()
  , limit_()
{}

getMessageThreadHistory::getMessageThreadHistory(int53 chat_id_, int53 message_id_, int53 from_message_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getMessageThreadHistory::ID;

void getMessageThreadHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageThreadHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getOwnedBots::getOwnedBots() {
}

const std::int32_t getOwnedBots::ID;

void getOwnedBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOwnedBots");
    s.store_class_end();
  }
}

getPollVoteStatistics::getPollVoteStatistics()
  : chat_id_()
  , message_id_()
  , is_dark_()
{}

getPollVoteStatistics::getPollVoteStatistics(int53 chat_id_, int53 message_id_, bool is_dark_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_dark_(is_dark_)
{}

const std::int32_t getPollVoteStatistics::ID;

void getPollVoteStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPollVoteStatistics");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getPremiumFeatures::getPremiumFeatures()
  : source_()
{}

getPremiumFeatures::getPremiumFeatures(object_ptr<PremiumSource> &&source_)
  : source_(std::move(source_))
{}

const std::int32_t getPremiumFeatures::ID;

void getPremiumFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumFeatures");
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

getRecentStickers::getRecentStickers()
  : is_attached_()
{}

getRecentStickers::getRecentStickers(bool is_attached_)
  : is_attached_(is_attached_)
{}

const std::int32_t getRecentStickers::ID;

void getRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentStickers");
    s.store_field("is_attached", is_attached_);
    s.store_class_end();
  }
}

getRepliedMessage::getRepliedMessage()
  : chat_id_()
  , message_id_()
{}

getRepliedMessage::getRepliedMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getRepliedMessage::ID;

void getRepliedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRepliedMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getSavedOrderInfo::getSavedOrderInfo() {
}

const std::int32_t getSavedOrderInfo::ID;

void getSavedOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedOrderInfo");
    s.store_class_end();
  }
}

getStarTransactions::getStarTransactions()
  : owner_id_()
  , subscription_id_()
  , direction_()
  , offset_()
  , limit_()
{}

getStarTransactions::getStarTransactions(object_ptr<MessageSender> &&owner_id_, string const &subscription_id_, object_ptr<TransactionDirection> &&direction_, string const &offset_, int32 limit_)
  : owner_id_(std::move(owner_id_))
  , subscription_id_(subscription_id_)
  , direction_(std::move(direction_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getStarTransactions::ID;

void getStarTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarTransactions");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("subscription_id", subscription_id_);
    s.store_object_field("direction", static_cast<const BaseObject *>(direction_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getStickers::getStickers()
  : sticker_type_()
  , query_()
  , limit_()
  , chat_id_()
{}

getStickers::getStickers(object_ptr<StickerType> &&sticker_type_, string const &query_, int32 limit_, int53 chat_id_)
  : sticker_type_(std::move(sticker_type_))
  , query_(query_)
  , limit_(limit_)
  , chat_id_(chat_id_)
{}

const std::int32_t getStickers::ID;

void getStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickers");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getStoryPublicForwards::getStoryPublicForwards()
  : story_poster_chat_id_()
  , story_id_()
  , offset_()
  , limit_()
{}

getStoryPublicForwards::getStoryPublicForwards(int53 story_poster_chat_id_, int32 story_id_, string const &offset_, int32 limit_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getStoryPublicForwards::ID;

void getStoryPublicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryPublicForwards");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getSupergroup::getSupergroup()
  : supergroup_id_()
{}

getSupergroup::getSupergroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t getSupergroup::ID;

void getSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupergroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

getSupportName::getSupportName() {
}

const std::int32_t getSupportName::ID;

void getSupportName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupportName");
    s.store_class_end();
  }
}

getTimeZones::getTimeZones() {
}

const std::int32_t getTimeZones::ID;

void getTimeZones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTimeZones");
    s.store_class_end();
  }
}

getTonConnectDAppPendingRequests::getTonConnectDAppPendingRequests()
  : dapp_client_id_()
{}

getTonConnectDAppPendingRequests::getTonConnectDAppPendingRequests(string const &dapp_client_id_)
  : dapp_client_id_(dapp_client_id_)
{}

const std::int32_t getTonConnectDAppPendingRequests::ID;

void getTonConnectDAppPendingRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonConnectDAppPendingRequests");
    s.store_field("dapp_client_id", dapp_client_id_);
    s.store_class_end();
  }
}

getTonWalletOwnershipProofChallenge::getTonWalletOwnershipProofChallenge() {
}

const std::int32_t getTonWalletOwnershipProofChallenge::ID;

void getTonWalletOwnershipProofChallenge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonWalletOwnershipProofChallenge");
    s.store_class_end();
  }
}

getTonWalletSecretPhrase::getTonWalletSecretPhrase()
  : password_()
{}

getTonWalletSecretPhrase::getTonWalletSecretPhrase(string const &password_)
  : password_(password_)
{}

const std::int32_t getTonWalletSecretPhrase::ID;

void getTonWalletSecretPhrase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonWalletSecretPhrase");
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

hideSuggestedAction::hideSuggestedAction()
  : action_()
{}

hideSuggestedAction::hideSuggestedAction(object_ptr<SuggestedAction> &&action_)
  : action_(std::move(action_))
{}

const std::int32_t hideSuggestedAction::ID;

void hideSuggestedAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "hideSuggestedAction");
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

pingProxy::pingProxy()
  : proxy_()
{}

pingProxy::pingProxy(object_ptr<proxy> &&proxy_)
  : proxy_(std::move(proxy_))
{}

const std::int32_t pingProxy::ID;

void pingProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pingProxy");
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_class_end();
  }
}

preliminaryUploadFile::preliminaryUploadFile()
  : file_()
  , file_type_()
  , priority_()
{}

preliminaryUploadFile::preliminaryUploadFile(object_ptr<InputFile> &&file_, object_ptr<FileType> &&file_type_, int32 priority_)
  : file_(std::move(file_))
  , file_type_(std::move(file_type_))
  , priority_(priority_)
{}

const std::int32_t preliminaryUploadFile::ID;

void preliminaryUploadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "preliminaryUploadFile");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_field("priority", priority_);
    s.store_class_end();
  }
}

refundStarPayment::refundStarPayment()
  : user_id_()
  , telegram_payment_charge_id_()
{}

refundStarPayment::refundStarPayment(int53 user_id_, string const &telegram_payment_charge_id_)
  : user_id_(user_id_)
  , telegram_payment_charge_id_(telegram_payment_charge_id_)
{}

const std::int32_t refundStarPayment::ID;

void refundStarPayment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "refundStarPayment");
    s.store_field("user_id", user_id_);
    s.store_field("telegram_payment_charge_id", telegram_payment_charge_id_);
    s.store_class_end();
  }
}

removeAllWebBrowserSettingsExceptions::removeAllWebBrowserSettingsExceptions() {
}

const std::int32_t removeAllWebBrowserSettingsExceptions::ID;

void removeAllWebBrowserSettingsExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeAllWebBrowserSettingsExceptions");
    s.store_class_end();
  }
}

removeChatActionBar::removeChatActionBar()
  : chat_id_()
{}

removeChatActionBar::removeChatActionBar(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t removeChatActionBar::ID;

void removeChatActionBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeChatActionBar");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removeCommunityChat::removeCommunityChat()
  : community_id_()
  , chat_id_()
{}

removeCommunityChat::removeCommunityChat(int53 community_id_, int53 chat_id_)
  : community_id_(community_id_)
  , chat_id_(chat_id_)
{}

const std::int32_t removeCommunityChat::ID;

void removeCommunityChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeCommunityChat");
    s.store_field("community_id", community_id_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removeStoryAlbumStories::removeStoryAlbumStories()
  : chat_id_()
  , story_album_id_()
  , story_ids_()
{}

removeStoryAlbumStories::removeStoryAlbumStories(int53 chat_id_, int32 story_album_id_, array<int32> &&story_ids_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
  , story_ids_(std::move(story_ids_))
{}

const std::int32_t removeStoryAlbumStories::ID;

void removeStoryAlbumStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeStoryAlbumStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    { s.store_vector_begin("story_ids", story_ids_.size()); for (const auto &_value : story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

replaceStickerInSet::replaceStickerInSet()
  : user_id_()
  , name_()
  , old_sticker_()
  , new_sticker_()
{}

replaceStickerInSet::replaceStickerInSet(int53 user_id_, string const &name_, object_ptr<InputFile> &&old_sticker_, object_ptr<newSticker> &&new_sticker_)
  : user_id_(user_id_)
  , name_(name_)
  , old_sticker_(std::move(old_sticker_))
  , new_sticker_(std::move(new_sticker_))
{}

const std::int32_t replaceStickerInSet::ID;

void replaceStickerInSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replaceStickerInSet");
    s.store_field("user_id", user_id_);
    s.store_field("name", name_);
    s.store_object_field("old_sticker", static_cast<const BaseObject *>(old_sticker_.get()));
    s.store_object_field("new_sticker", static_cast<const BaseObject *>(new_sticker_.get()));
    s.store_class_end();
  }
}

reportChat::reportChat()
  : chat_id_()
  , option_id_()
  , message_ids_()
  , text_()
{}

reportChat::reportChat(int53 chat_id_, bytes const &option_id_, array<int53> &&message_ids_, string const &text_)
  : chat_id_(chat_id_)
  , option_id_(std::move(option_id_))
  , message_ids_(std::move(message_ids_))
  , text_(text_)
{}

const std::int32_t reportChat::ID;

void reportChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChat");
    s.store_field("chat_id", chat_id_);
    s.store_bytes_field("option_id", option_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

reportStory::reportStory()
  : story_poster_chat_id_()
  , story_id_()
  , option_id_()
  , text_()
{}

reportStory::reportStory(int53 story_poster_chat_id_, int32 story_id_, bytes const &option_id_, string const &text_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , option_id_(std::move(option_id_))
  , text_(text_)
{}

const std::int32_t reportStory::ID;

void reportStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_bytes_field("option_id", option_id_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

reportSupergroupSpam::reportSupergroupSpam()
  : supergroup_id_()
  , message_ids_()
{}

reportSupergroupSpam::reportSupergroupSpam(int53 supergroup_id_, array<int53> &&message_ids_)
  : supergroup_id_(supergroup_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t reportSupergroupSpam::ID;

void reportSupergroupSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSupergroupSpam");
    s.store_field("supergroup_id", supergroup_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

resendMessages::resendMessages()
  : chat_id_()
  , message_ids_()
  , quote_()
  , paid_message_star_count_()
{}

resendMessages::resendMessages(int53 chat_id_, array<int53> &&message_ids_, object_ptr<inputTextQuote> &&quote_, int53 paid_message_star_count_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
  , quote_(std::move(quote_))
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t resendMessages::ID;

void resendMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("quote", static_cast<const BaseObject *>(quote_.get()));
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

savePreparedInlineMessage::savePreparedInlineMessage()
  : user_id_()
  , result_()
  , chat_types_()
{}

savePreparedInlineMessage::savePreparedInlineMessage(int53 user_id_, object_ptr<InputInlineQueryResult> &&result_, object_ptr<targetChatTypes> &&chat_types_)
  : user_id_(user_id_)
  , result_(std::move(result_))
  , chat_types_(std::move(chat_types_))
{}

const std::int32_t savePreparedInlineMessage::ID;

void savePreparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savePreparedInlineMessage");
    s.store_field("user_id", user_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_object_field("chat_types", static_cast<const BaseObject *>(chat_types_.get()));
    s.store_class_end();
  }
}

searchCallMessages::searchCallMessages()
  : offset_()
  , limit_()
  , only_missed_()
{}

searchCallMessages::searchCallMessages(string const &offset_, int32 limit_, bool only_missed_)
  : offset_(offset_)
  , limit_(limit_)
  , only_missed_(only_missed_)
{}

const std::int32_t searchCallMessages::ID;

void searchCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchCallMessages");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("only_missed", only_missed_);
    s.store_class_end();
  }
}

searchChatMessages::searchChatMessages()
  : chat_id_()
  , topic_id_()
  , query_()
  , sender_id_()
  , from_message_id_()
  , offset_()
  , limit_()
  , filter_()
{}

searchChatMessages::searchChatMessages(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, string const &query_, object_ptr<MessageSender> &&sender_id_, int53 from_message_id_, int32 offset_, int32 limit_, object_ptr<SearchMessagesFilter> &&filter_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , query_(query_)
  , sender_id_(std::move(sender_id_))
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
  , filter_(std::move(filter_))
{}

const std::int32_t searchChatMessages::ID;

void searchChatMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatMessages");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_field("query", query_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_class_end();
  }
}

searchChatRecentLocationMessages::searchChatRecentLocationMessages()
  : chat_id_()
  , limit_()
{}

searchChatRecentLocationMessages::searchChatRecentLocationMessages(int53 chat_id_, int32 limit_)
  : chat_id_(chat_id_)
  , limit_(limit_)
{}

const std::int32_t searchChatRecentLocationMessages::ID;

void searchChatRecentLocationMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatRecentLocationMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchStickerSets::searchStickerSets()
  : sticker_type_()
  , query_()
{}

searchStickerSets::searchStickerSets(object_ptr<StickerType> &&sticker_type_, string const &query_)
  : sticker_type_(std::move(sticker_type_))
  , query_(query_)
{}

const std::int32_t searchStickerSets::ID;

void searchStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("query", query_);
    s.store_class_end();
  }
}

sendChatAction::sendChatAction()
  : chat_id_()
  , topic_id_()
  , business_connection_id_()
  , action_()
{}

sendChatAction::sendChatAction(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, string const &business_connection_id_, object_ptr<ChatAction> &&action_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , business_connection_id_(business_connection_id_)
  , action_(std::move(action_))
{}

const std::int32_t sendChatAction::ID;

void sendChatAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendChatAction");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_field("business_connection_id", business_connection_id_);
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

sendTonConnectSessionConnectResult::sendTonConnectSessionConnectResult()
  : session_id_()
  , challenge_answer_()
  , is_error_()
  , body_()
  , trace_id_()
{}

sendTonConnectSessionConnectResult::sendTonConnectSessionConnectResult(int64 session_id_, bytes const &challenge_answer_, bool is_error_, bytes const &body_, string const &trace_id_)
  : session_id_(session_id_)
  , challenge_answer_(std::move(challenge_answer_))
  , is_error_(is_error_)
  , body_(std::move(body_))
  , trace_id_(trace_id_)
{}

const std::int32_t sendTonConnectSessionConnectResult::ID;

void sendTonConnectSessionConnectResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendTonConnectSessionConnectResult");
    s.store_field("session_id", session_id_);
    s.store_bytes_field("challenge_answer", challenge_answer_);
    s.store_field("is_error", is_error_);
    s.store_bytes_field("body", body_);
    s.store_field("trace_id", trace_id_);
    s.store_class_end();
  }
}

setAlarm::setAlarm()
  : seconds_()
{}

setAlarm::setAlarm(double seconds_)
  : seconds_(seconds_)
{}

const std::int32_t setAlarm::ID;

void setAlarm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAlarm");
    s.store_field("seconds", seconds_);
    s.store_class_end();
  }
}

setApplicationVerificationToken::setApplicationVerificationToken()
  : verification_id_()
  , token_()
{}

setApplicationVerificationToken::setApplicationVerificationToken(int53 verification_id_, string const &token_)
  : verification_id_(verification_id_)
  , token_(token_)
{}

const std::int32_t setApplicationVerificationToken::ID;

void setApplicationVerificationToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setApplicationVerificationToken");
    s.store_field("verification_id", verification_id_);
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

setBusinessAccountUsername::setBusinessAccountUsername()
  : business_connection_id_()
  , username_()
{}

setBusinessAccountUsername::setBusinessAccountUsername(string const &business_connection_id_, string const &username_)
  : business_connection_id_(business_connection_id_)
  , username_(username_)
{}

const std::int32_t setBusinessAccountUsername::ID;

void setBusinessAccountUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAccountUsername");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("username", username_);
    s.store_class_end();
  }
}

setBusinessOpeningHours::setBusinessOpeningHours()
  : opening_hours_()
{}

setBusinessOpeningHours::setBusinessOpeningHours(object_ptr<businessOpeningHours> &&opening_hours_)
  : opening_hours_(std::move(opening_hours_))
{}

const std::int32_t setBusinessOpeningHours::ID;

void setBusinessOpeningHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessOpeningHours");
    s.store_object_field("opening_hours", static_cast<const BaseObject *>(opening_hours_.get()));
    s.store_class_end();
  }
}

setChatActiveStoriesList::setChatActiveStoriesList()
  : chat_id_()
  , story_list_()
{}

setChatActiveStoriesList::setChatActiveStoriesList(int53 chat_id_, object_ptr<StoryList> &&story_list_)
  : chat_id_(chat_id_)
  , story_list_(std::move(story_list_))
{}

const std::int32_t setChatActiveStoriesList::ID;

void setChatActiveStoriesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatActiveStoriesList");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("story_list", static_cast<const BaseObject *>(story_list_.get()));
    s.store_class_end();
  }
}

setChatDescription::setChatDescription()
  : chat_id_()
  , description_()
{}

setChatDescription::setChatDescription(int53 chat_id_, string const &description_)
  : chat_id_(chat_id_)
  , description_(description_)
{}

const std::int32_t setChatDescription::ID;

void setChatDescription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatDescription");
    s.store_field("chat_id", chat_id_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

setChatDiscussionGroup::setChatDiscussionGroup()
  : chat_id_()
  , discussion_chat_id_()
{}

setChatDiscussionGroup::setChatDiscussionGroup(int53 chat_id_, int53 discussion_chat_id_)
  : chat_id_(chat_id_)
  , discussion_chat_id_(discussion_chat_id_)
{}

const std::int32_t setChatDiscussionGroup::ID;

void setChatDiscussionGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatDiscussionGroup");
    s.store_field("chat_id", chat_id_);
    s.store_field("discussion_chat_id", discussion_chat_id_);
    s.store_class_end();
  }
}

setDefaultBackground::setDefaultBackground()
  : background_()
  , type_()
  , for_dark_theme_()
{}

setDefaultBackground::setDefaultBackground(object_ptr<InputBackground> &&background_, object_ptr<BackgroundType> &&type_, bool for_dark_theme_)
  : background_(std::move(background_))
  , type_(std::move(type_))
  , for_dark_theme_(for_dark_theme_)
{}

const std::int32_t setDefaultBackground::ID;

void setDefaultBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultBackground");
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("for_dark_theme", for_dark_theme_);
    s.store_class_end();
  }
}

setGameScore::setGameScore()
  : chat_id_()
  , message_id_()
  , edit_message_()
  , user_id_()
  , score_()
  , force_()
{}

setGameScore::setGameScore(int53 chat_id_, int53 message_id_, bool edit_message_, int53 user_id_, int32 score_, bool force_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , edit_message_(edit_message_)
  , user_id_(user_id_)
  , score_(score_)
  , force_(force_)
{}

const std::int32_t setGameScore::ID;

void setGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGameScore");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("edit_message", edit_message_);
    s.store_field("user_id", user_id_);
    s.store_field("score", score_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

setLogVerbosityLevel::setLogVerbosityLevel()
  : new_verbosity_level_()
{}

setLogVerbosityLevel::setLogVerbosityLevel(int32 new_verbosity_level_)
  : new_verbosity_level_(new_verbosity_level_)
{}

const std::int32_t setLogVerbosityLevel::ID;

void setLogVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLogVerbosityLevel");
    s.store_field("new_verbosity_level", new_verbosity_level_);
    s.store_class_end();
  }
}

setMessageReactions::setMessageReactions()
  : chat_id_()
  , message_id_()
  , reaction_types_()
  , is_big_()
{}

setMessageReactions::setMessageReactions(int53 chat_id_, int53 message_id_, array<object_ptr<ReactionType>> &&reaction_types_, bool is_big_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reaction_types_(std::move(reaction_types_))
  , is_big_(is_big_)
{}

const std::int32_t setMessageReactions::ID;

void setMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMessageReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("reaction_types", reaction_types_.size()); for (const auto &_value : reaction_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_big", is_big_);
    s.store_class_end();
  }
}

setMessageSenderBotVerification::setMessageSenderBotVerification()
  : bot_user_id_()
  , verified_id_()
  , custom_description_()
{}

setMessageSenderBotVerification::setMessageSenderBotVerification(int53 bot_user_id_, object_ptr<MessageSender> &&verified_id_, object_ptr<formattedText> &&custom_description_)
  : bot_user_id_(bot_user_id_)
  , verified_id_(std::move(verified_id_))
  , custom_description_(std::move(custom_description_))
{}

const std::int32_t setMessageSenderBotVerification::ID;

void setMessageSenderBotVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMessageSenderBotVerification");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("verified_id", static_cast<const BaseObject *>(verified_id_.get()));
    s.store_object_field("custom_description", static_cast<const BaseObject *>(custom_description_.get()));
    s.store_class_end();
  }
}

setReactionNotificationSettings::setReactionNotificationSettings()
  : notification_settings_()
{}

setReactionNotificationSettings::setReactionNotificationSettings(object_ptr<reactionNotificationSettings> &&notification_settings_)
  : notification_settings_(std::move(notification_settings_))
{}

const std::int32_t setReactionNotificationSettings::ID;

void setReactionNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setReactionNotificationSettings");
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

setSavedMessagesTagLabel::setSavedMessagesTagLabel()
  : tag_()
  , label_()
{}

setSavedMessagesTagLabel::setSavedMessagesTagLabel(object_ptr<ReactionType> &&tag_, string const &label_)
  : tag_(std::move(tag_))
  , label_(label_)
{}

const std::int32_t setSavedMessagesTagLabel::ID;

void setSavedMessagesTagLabel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSavedMessagesTagLabel");
    s.store_object_field("tag", static_cast<const BaseObject *>(tag_.get()));
    s.store_field("label", label_);
    s.store_class_end();
  }
}

setStickerSetTitle::setStickerSetTitle()
  : name_()
  , title_()
{}

setStickerSetTitle::setStickerSetTitle(string const &name_, string const &title_)
  : name_(name_)
  , title_(title_)
{}

const std::int32_t setStickerSetTitle::ID;

void setStickerSetTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerSetTitle");
    s.store_field("name", name_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

setStoryPrivacySettings::setStoryPrivacySettings()
  : story_id_()
  , privacy_settings_()
{}

setStoryPrivacySettings::setStoryPrivacySettings(int32 story_id_, object_ptr<StoryPrivacySettings> &&privacy_settings_)
  : story_id_(story_id_)
  , privacy_settings_(std::move(privacy_settings_))
{}

const std::int32_t setStoryPrivacySettings::ID;

void setStoryPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStoryPrivacySettings");
    s.store_field("story_id", story_id_);
    s.store_object_field("privacy_settings", static_cast<const BaseObject *>(privacy_settings_.get()));
    s.store_class_end();
  }
}

setUserEmojiStatus::setUserEmojiStatus()
  : user_id_()
  , emoji_status_()
{}

setUserEmojiStatus::setUserEmojiStatus(int53 user_id_, object_ptr<emojiStatus> &&emoji_status_)
  : user_id_(user_id_)
  , emoji_status_(std::move(emoji_status_))
{}

const std::int32_t setUserEmojiStatus::ID;

void setUserEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUserEmojiStatus");
    s.store_field("user_id", user_id_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

stopPendingMessage::stopPendingMessage()
  : chat_id_()
  , topic_id_()
  , draft_id_()
{}

stopPendingMessage::stopPendingMessage(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, int64 draft_id_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , draft_id_(draft_id_)
{}

const std::int32_t stopPendingMessage::ID;

void stopPendingMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stopPendingMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_field("draft_id", draft_id_);
    s.store_class_end();
  }
}

suggestUserProfilePhoto::suggestUserProfilePhoto()
  : user_id_()
  , photo_()
{}

suggestUserProfilePhoto::suggestUserProfilePhoto(int53 user_id_, object_ptr<InputChatPhoto> &&photo_)
  : user_id_(user_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t suggestUserProfilePhoto::ID;

void suggestUserProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestUserProfilePhoto");
    s.store_field("user_id", user_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

testCallVectorIntObject::testCallVectorIntObject()
  : x_()
{}

testCallVectorIntObject::testCallVectorIntObject(array<object_ptr<testInt>> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorIntObject::ID;

void testCallVectorIntObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorIntObject");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

toggleBusinessConnectedBotChatIsPaused::toggleBusinessConnectedBotChatIsPaused()
  : chat_id_()
  , is_paused_()
{}

toggleBusinessConnectedBotChatIsPaused::toggleBusinessConnectedBotChatIsPaused(int53 chat_id_, bool is_paused_)
  : chat_id_(chat_id_)
  , is_paused_(is_paused_)
{}

const std::int32_t toggleBusinessConnectedBotChatIsPaused::ID;

void toggleBusinessConnectedBotChatIsPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleBusinessConnectedBotChatIsPaused");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

toggleGroupCallAreMessagesAllowed::toggleGroupCallAreMessagesAllowed()
  : group_call_id_()
  , are_messages_allowed_()
{}

toggleGroupCallAreMessagesAllowed::toggleGroupCallAreMessagesAllowed(int32 group_call_id_, bool are_messages_allowed_)
  : group_call_id_(group_call_id_)
  , are_messages_allowed_(are_messages_allowed_)
{}

const std::int32_t toggleGroupCallAreMessagesAllowed::ID;

void toggleGroupCallAreMessagesAllowed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallAreMessagesAllowed");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("are_messages_allowed", are_messages_allowed_);
    s.store_class_end();
  }
}

toggleSavedMessagesTopicIsPinned::toggleSavedMessagesTopicIsPinned()
  : saved_messages_topic_id_()
  , is_pinned_()
{}

toggleSavedMessagesTopicIsPinned::toggleSavedMessagesTopicIsPinned(int53 saved_messages_topic_id_, bool is_pinned_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t toggleSavedMessagesTopicIsPinned::ID;

void toggleSavedMessagesTopicIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSavedMessagesTopicIsPinned");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

toggleSupergroupHasAggressiveAntiSpamEnabled::toggleSupergroupHasAggressiveAntiSpamEnabled()
  : supergroup_id_()
  , has_aggressive_anti_spam_enabled_()
{}

toggleSupergroupHasAggressiveAntiSpamEnabled::toggleSupergroupHasAggressiveAntiSpamEnabled(int53 supergroup_id_, bool has_aggressive_anti_spam_enabled_)
  : supergroup_id_(supergroup_id_)
  , has_aggressive_anti_spam_enabled_(has_aggressive_anti_spam_enabled_)
{}

const std::int32_t toggleSupergroupHasAggressiveAntiSpamEnabled::ID;

void toggleSupergroupHasAggressiveAntiSpamEnabled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupHasAggressiveAntiSpamEnabled");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("has_aggressive_anti_spam_enabled", has_aggressive_anti_spam_enabled_);
    s.store_class_end();
  }
}

toggleSupergroupHasAutomaticTranslation::toggleSupergroupHasAutomaticTranslation()
  : supergroup_id_()
  , has_automatic_translation_()
{}

toggleSupergroupHasAutomaticTranslation::toggleSupergroupHasAutomaticTranslation(int53 supergroup_id_, bool has_automatic_translation_)
  : supergroup_id_(supergroup_id_)
  , has_automatic_translation_(has_automatic_translation_)
{}

const std::int32_t toggleSupergroupHasAutomaticTranslation::ID;

void toggleSupergroupHasAutomaticTranslation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupHasAutomaticTranslation");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("has_automatic_translation", has_automatic_translation_);
    s.store_class_end();
  }
}

toggleSupergroupHasHiddenMembers::toggleSupergroupHasHiddenMembers()
  : supergroup_id_()
  , has_hidden_members_()
{}

toggleSupergroupHasHiddenMembers::toggleSupergroupHasHiddenMembers(int53 supergroup_id_, bool has_hidden_members_)
  : supergroup_id_(supergroup_id_)
  , has_hidden_members_(has_hidden_members_)
{}

const std::int32_t toggleSupergroupHasHiddenMembers::ID;

void toggleSupergroupHasHiddenMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupHasHiddenMembers");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("has_hidden_members", has_hidden_members_);
    s.store_class_end();
  }
}

toggleSupergroupIsBroadcastGroup::toggleSupergroupIsBroadcastGroup()
  : supergroup_id_()
{}

toggleSupergroupIsBroadcastGroup::toggleSupergroupIsBroadcastGroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t toggleSupergroupIsBroadcastGroup::ID;

void toggleSupergroupIsBroadcastGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupIsBroadcastGroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

viewPremiumFeature::viewPremiumFeature()
  : feature_()
{}

viewPremiumFeature::viewPremiumFeature(object_ptr<PremiumFeature> &&feature_)
  : feature_(std::move(feature_))
{}

const std::int32_t viewPremiumFeature::ID;

void viewPremiumFeature::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewPremiumFeature");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_class_end();
  }
}

viewSponsoredChat::viewSponsoredChat()
  : sponsored_chat_unique_id_()
{}

viewSponsoredChat::viewSponsoredChat(int53 sponsored_chat_unique_id_)
  : sponsored_chat_unique_id_(sponsored_chat_unique_id_)
{}

const std::int32_t viewSponsoredChat::ID;

void viewSponsoredChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewSponsoredChat");
    s.store_field("sponsored_chat_unique_id", sponsored_chat_unique_id_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
