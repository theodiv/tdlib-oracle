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


ageVerificationParameters::ageVerificationParameters()
  : min_age_()
  , verification_bot_username_()
  , country_()
{}

ageVerificationParameters::ageVerificationParameters(int32 min_age_, string const &verification_bot_username_, string const &country_)
  : min_age_(min_age_)
  , verification_bot_username_(verification_bot_username_)
  , country_(country_)
{}

const std::int32_t ageVerificationParameters::ID;

void ageVerificationParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ageVerificationParameters");
    s.store_field("min_age", min_age_);
    s.store_field("verification_bot_username", verification_bot_username_);
    s.store_field("country", country_);
    s.store_class_end();
  }
}

alternativeVideo::alternativeVideo()
  : id_()
  , width_()
  , height_()
  , codec_()
  , hls_file_()
  , video_()
{}

alternativeVideo::alternativeVideo(int64 id_, int32 width_, int32 height_, string const &codec_, object_ptr<file> &&hls_file_, object_ptr<file> &&video_)
  : id_(id_)
  , width_(width_)
  , height_(height_)
  , codec_(codec_)
  , hls_file_(std::move(hls_file_))
  , video_(std::move(video_))
{}

const std::int32_t alternativeVideo::ID;

void alternativeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "alternativeVideo");
    s.store_field("id", id_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("codec", codec_);
    s.store_object_field("hls_file", static_cast<const BaseObject *>(hls_file_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

autosaveSettingsException::autosaveSettingsException()
  : chat_id_()
  , settings_()
{}

autosaveSettingsException::autosaveSettingsException(int53 chat_id_, object_ptr<scopeAutosaveSettings> &&settings_)
  : chat_id_(chat_id_)
  , settings_(std::move(settings_))
{}

const std::int32_t autosaveSettingsException::ID;

void autosaveSettingsException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettingsException");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

basicGroup::basicGroup()
  : id_()
  , member_count_()
  , status_()
  , is_active_()
  , upgraded_to_supergroup_id_()
{}

basicGroup::basicGroup(int53 id_, int32 member_count_, object_ptr<ChatMemberStatus> &&status_, bool is_active_, int53 upgraded_to_supergroup_id_)
  : id_(id_)
  , member_count_(member_count_)
  , status_(std::move(status_))
  , is_active_(is_active_)
  , upgraded_to_supergroup_id_(upgraded_to_supergroup_id_)
{}

const std::int32_t basicGroup::ID;

void basicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "basicGroup");
    s.store_field("id", id_);
    s.store_field("member_count", member_count_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("is_active", is_active_);
    s.store_field("upgraded_to_supergroup_id", upgraded_to_supergroup_id_);
    s.store_class_end();
  }
}

botAccessSettings::botAccessSettings()
  : is_restricted_()
  , added_user_ids_()
{}

botAccessSettings::botAccessSettings(bool is_restricted_, array<int53> &&added_user_ids_)
  : is_restricted_(is_restricted_)
  , added_user_ids_(std::move(added_user_ids_))
{}

const std::int32_t botAccessSettings::ID;

void botAccessSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botAccessSettings");
    s.store_field("is_restricted", is_restricted_);
    { s.store_vector_begin("added_user_ids", added_user_ids_.size()); for (const auto &_value : added_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

botMediaPreviewInfo::botMediaPreviewInfo()
  : previews_()
  , language_codes_()
{}

botMediaPreviewInfo::botMediaPreviewInfo(array<object_ptr<botMediaPreview>> &&previews_, array<string> &&language_codes_)
  : previews_(std::move(previews_))
  , language_codes_(std::move(language_codes_))
{}

const std::int32_t botMediaPreviewInfo::ID;

void botMediaPreviewInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMediaPreviewInfo");
    { s.store_vector_begin("previews", previews_.size()); for (const auto &_value : previews_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("language_codes", language_codes_.size()); for (const auto &_value : language_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessAwayMessageSettings::businessAwayMessageSettings()
  : shortcut_id_()
  , recipients_()
  , schedule_()
  , offline_only_()
{}

businessAwayMessageSettings::businessAwayMessageSettings(int32 shortcut_id_, object_ptr<businessRecipients> &&recipients_, object_ptr<BusinessAwayMessageSchedule> &&schedule_, bool offline_only_)
  : shortcut_id_(shortcut_id_)
  , recipients_(std::move(recipients_))
  , schedule_(std::move(schedule_))
  , offline_only_(offline_only_)
{}

const std::int32_t businessAwayMessageSettings::ID;

void businessAwayMessageSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageSettings");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_object_field("schedule", static_cast<const BaseObject *>(schedule_.get()));
    s.store_field("offline_only", offline_only_);
    s.store_class_end();
  }
}

callId::callId()
  : id_()
{}

callId::callId(int32 id_)
  : id_(id_)
{}

const std::int32_t callId::ID;

void callId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

callProtocol::callProtocol()
  : udp_p2p_()
  , udp_reflector_()
  , min_layer_()
  , max_layer_()
  , library_versions_()
{}

callProtocol::callProtocol(bool udp_p2p_, bool udp_reflector_, int32 min_layer_, int32 max_layer_, array<string> &&library_versions_)
  : udp_p2p_(udp_p2p_)
  , udp_reflector_(udp_reflector_)
  , min_layer_(min_layer_)
  , max_layer_(max_layer_)
  , library_versions_(std::move(library_versions_))
{}

const std::int32_t callProtocol::ID;

void callProtocol::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProtocol");
    s.store_field("udp_p2p", udp_p2p_);
    s.store_field("udp_reflector", udp_reflector_);
    s.store_field("min_layer", min_layer_);
    s.store_field("max_layer", max_layer_);
    { s.store_vector_begin("library_versions", library_versions_.size()); for (const auto &_value : library_versions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatActionTyping::chatActionTyping() {
}

const std::int32_t chatActionTyping::ID;

void chatActionTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionTyping");
    s.store_class_end();
  }
}

chatActionRecordingVideo::chatActionRecordingVideo() {
}

const std::int32_t chatActionRecordingVideo::ID;

void chatActionRecordingVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionRecordingVideo");
    s.store_class_end();
  }
}

chatActionUploadingVideo::chatActionUploadingVideo()
  : progress_()
{}

chatActionUploadingVideo::chatActionUploadingVideo(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingVideo::ID;

void chatActionUploadingVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingVideo");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionRecordingVoiceNote::chatActionRecordingVoiceNote() {
}

const std::int32_t chatActionRecordingVoiceNote::ID;

void chatActionRecordingVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionRecordingVoiceNote");
    s.store_class_end();
  }
}

chatActionUploadingVoiceNote::chatActionUploadingVoiceNote()
  : progress_()
{}

chatActionUploadingVoiceNote::chatActionUploadingVoiceNote(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingVoiceNote::ID;

void chatActionUploadingVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingVoiceNote");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionUploadingPhoto::chatActionUploadingPhoto()
  : progress_()
{}

chatActionUploadingPhoto::chatActionUploadingPhoto(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingPhoto::ID;

void chatActionUploadingPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingPhoto");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionUploadingDocument::chatActionUploadingDocument()
  : progress_()
{}

chatActionUploadingDocument::chatActionUploadingDocument(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingDocument::ID;

void chatActionUploadingDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingDocument");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionChoosingSticker::chatActionChoosingSticker() {
}

const std::int32_t chatActionChoosingSticker::ID;

void chatActionChoosingSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionChoosingSticker");
    s.store_class_end();
  }
}

chatActionChoosingLocation::chatActionChoosingLocation() {
}

const std::int32_t chatActionChoosingLocation::ID;

void chatActionChoosingLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionChoosingLocation");
    s.store_class_end();
  }
}

chatActionChoosingContact::chatActionChoosingContact() {
}

const std::int32_t chatActionChoosingContact::ID;

void chatActionChoosingContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionChoosingContact");
    s.store_class_end();
  }
}

chatActionStartPlayingGame::chatActionStartPlayingGame() {
}

const std::int32_t chatActionStartPlayingGame::ID;

void chatActionStartPlayingGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionStartPlayingGame");
    s.store_class_end();
  }
}

chatActionRecordingVideoNote::chatActionRecordingVideoNote() {
}

const std::int32_t chatActionRecordingVideoNote::ID;

void chatActionRecordingVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionRecordingVideoNote");
    s.store_class_end();
  }
}

chatActionUploadingVideoNote::chatActionUploadingVideoNote()
  : progress_()
{}

chatActionUploadingVideoNote::chatActionUploadingVideoNote(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingVideoNote::ID;

void chatActionUploadingVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingVideoNote");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionWatchingAnimations::chatActionWatchingAnimations()
  : emoji_()
{}

chatActionWatchingAnimations::chatActionWatchingAnimations(string const &emoji_)
  : emoji_(emoji_)
{}

const std::int32_t chatActionWatchingAnimations::ID;

void chatActionWatchingAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionWatchingAnimations");
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

chatActionCancel::chatActionCancel() {
}

const std::int32_t chatActionCancel::ID;

void chatActionCancel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionCancel");
    s.store_class_end();
  }
}

chatBoostLink::chatBoostLink()
  : link_()
  , is_public_()
{}

chatBoostLink::chatBoostLink(string const &link_, bool is_public_)
  : link_(link_)
  , is_public_(is_public_)
{}

const std::int32_t chatBoostLink::ID;

void chatBoostLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostLink");
    s.store_field("link", link_);
    s.store_field("is_public", is_public_);
    s.store_class_end();
  }
}

chatMembers::chatMembers()
  : total_count_()
  , members_()
{}

chatMembers::chatMembers(int32 total_count_, array<object_ptr<chatMember>> &&members_)
  : total_count_(total_count_)
  , members_(std::move(members_))
{}

const std::int32_t chatMembers::ID;

void chatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembers");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatPhotoInfo::chatPhotoInfo()
  : small_()
  , big_()
  , minithumbnail_()
  , has_animation_()
  , is_personal_()
{}

chatPhotoInfo::chatPhotoInfo(object_ptr<file> &&small_, object_ptr<file> &&big_, object_ptr<minithumbnail> &&minithumbnail_, bool has_animation_, bool is_personal_)
  : small_(std::move(small_))
  , big_(std::move(big_))
  , minithumbnail_(std::move(minithumbnail_))
  , has_animation_(has_animation_)
  , is_personal_(is_personal_)
{}

const std::int32_t chatPhotoInfo::ID;

void chatPhotoInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotoInfo");
    s.store_object_field("small", static_cast<const BaseObject *>(small_.get()));
    s.store_object_field("big", static_cast<const BaseObject *>(big_.get()));
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_field("has_animation", has_animation_);
    s.store_field("is_personal", is_personal_);
    s.store_class_end();
  }
}

chatRevenueTransactions::chatRevenueTransactions()
  : gram_amount_()
  , transactions_()
  , next_offset_()
{}

chatRevenueTransactions::chatRevenueTransactions(int53 gram_amount_, array<object_ptr<chatRevenueTransaction>> &&transactions_, string const &next_offset_)
  : gram_amount_(gram_amount_)
  , transactions_(std::move(transactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t chatRevenueTransactions::ID;

void chatRevenueTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactions");
    s.store_field("gram_amount", gram_amount_);
    { s.store_vector_begin("transactions", transactions_.size()); for (const auto &_value : transactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

chatStatisticsObjectTypeMessage::chatStatisticsObjectTypeMessage()
  : message_id_()
{}

chatStatisticsObjectTypeMessage::chatStatisticsObjectTypeMessage(int53 message_id_)
  : message_id_(message_id_)
{}

const std::int32_t chatStatisticsObjectTypeMessage::ID;

void chatStatisticsObjectTypeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsObjectTypeMessage");
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

chatStatisticsObjectTypeStory::chatStatisticsObjectTypeStory()
  : story_id_()
{}

chatStatisticsObjectTypeStory::chatStatisticsObjectTypeStory(int32 story_id_)
  : story_id_(story_id_)
{}

const std::int32_t chatStatisticsObjectTypeStory::ID;

void chatStatisticsObjectTypeStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsObjectTypeStory");
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

chatTypePrivate::chatTypePrivate()
  : user_id_()
{}

chatTypePrivate::chatTypePrivate(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t chatTypePrivate::ID;

void chatTypePrivate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypePrivate");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

chatTypeBasicGroup::chatTypeBasicGroup()
  : basic_group_id_()
{}

chatTypeBasicGroup::chatTypeBasicGroup(int53 basic_group_id_)
  : basic_group_id_(basic_group_id_)
{}

const std::int32_t chatTypeBasicGroup::ID;

void chatTypeBasicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypeBasicGroup");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

chatTypeSupergroup::chatTypeSupergroup()
  : supergroup_id_()
  , is_channel_()
{}

chatTypeSupergroup::chatTypeSupergroup(int53 supergroup_id_, bool is_channel_)
  : supergroup_id_(supergroup_id_)
  , is_channel_(is_channel_)
{}

const std::int32_t chatTypeSupergroup::ID;

void chatTypeSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypeSupergroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("is_channel", is_channel_);
    s.store_class_end();
  }
}

chatTypeSecret::chatTypeSecret()
  : secret_chat_id_()
  , user_id_()
{}

chatTypeSecret::chatTypeSecret(int32 secret_chat_id_, int53 user_id_)
  : secret_chat_id_(secret_chat_id_)
  , user_id_(user_id_)
{}

const std::int32_t chatTypeSecret::ID;

void chatTypeSecret::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypeSecret");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

communityId::communityId()
  : id_()
{}

communityId::communityId(int53 id_)
  : id_(id_)
{}

const std::int32_t communityId::ID;

void communityId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

craftGiftResultSuccess::craftGiftResultSuccess()
  : gift_()
  , received_gift_id_()
{}

craftGiftResultSuccess::craftGiftResultSuccess(object_ptr<upgradedGift> &&gift_, string const &received_gift_id_)
  : gift_(std::move(gift_))
  , received_gift_id_(received_gift_id_)
{}

const std::int32_t craftGiftResultSuccess::ID;

void craftGiftResultSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "craftGiftResultSuccess");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

craftGiftResultTooEarly::craftGiftResultTooEarly()
  : retry_after_()
{}

craftGiftResultTooEarly::craftGiftResultTooEarly(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t craftGiftResultTooEarly::ID;

void craftGiftResultTooEarly::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "craftGiftResultTooEarly");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

craftGiftResultInvalidGift::craftGiftResultInvalidGift() {
}

const std::int32_t craftGiftResultInvalidGift::ID;

void craftGiftResultInvalidGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "craftGiftResultInvalidGift");
    s.store_class_end();
  }
}

craftGiftResultFail::craftGiftResultFail() {
}

const std::int32_t craftGiftResultFail::ID;

void craftGiftResultFail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "craftGiftResultFail");
    s.store_class_end();
  }
}

draftMessage::draftMessage()
  : reply_to_()
  , date_()
  , content_()
  , effect_id_()
  , suggested_post_info_()
{}

draftMessage::draftMessage(object_ptr<InputMessageReplyTo> &&reply_to_, int32 date_, object_ptr<DraftMessageContent> &&content_, int64 effect_id_, object_ptr<inputSuggestedPostInfo> &&suggested_post_info_)
  : reply_to_(std::move(reply_to_))
  , date_(date_)
  , content_(std::move(content_))
  , effect_id_(effect_id_)
  , suggested_post_info_(std::move(suggested_post_info_))
{}

const std::int32_t draftMessage::ID;

void draftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessage");
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_field("date", date_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_field("effect_id", effect_id_);
    s.store_object_field("suggested_post_info", static_cast<const BaseObject *>(suggested_post_info_.get()));
    s.store_class_end();
  }
}

emojiCategories::emojiCategories()
  : categories_()
{}

emojiCategories::emojiCategories(array<object_ptr<emojiCategory>> &&categories_)
  : categories_(std::move(categories_))
{}

const std::int32_t emojiCategories::ID;

void emojiCategories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategories");
    { s.store_vector_begin("categories", categories_.size()); for (const auto &_value : categories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

emojiCategoryTypeDefault::emojiCategoryTypeDefault() {
}

const std::int32_t emojiCategoryTypeDefault::ID;

void emojiCategoryTypeDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategoryTypeDefault");
    s.store_class_end();
  }
}

emojiCategoryTypeRegularStickers::emojiCategoryTypeRegularStickers() {
}

const std::int32_t emojiCategoryTypeRegularStickers::ID;

void emojiCategoryTypeRegularStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategoryTypeRegularStickers");
    s.store_class_end();
  }
}

emojiCategoryTypeEmojiStatus::emojiCategoryTypeEmojiStatus() {
}

const std::int32_t emojiCategoryTypeEmojiStatus::ID;

void emojiCategoryTypeEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategoryTypeEmojiStatus");
    s.store_class_end();
  }
}

emojiCategoryTypeChatPhoto::emojiCategoryTypeChatPhoto() {
}

const std::int32_t emojiCategoryTypeChatPhoto::ID;

void emojiCategoryTypeChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategoryTypeChatPhoto");
    s.store_class_end();
  }
}

emojiKeyword::emojiKeyword()
  : emoji_()
  , keyword_()
{}

emojiKeyword::emojiKeyword(string const &emoji_, string const &keyword_)
  : emoji_(emoji_)
  , keyword_(keyword_)
{}

const std::int32_t emojiKeyword::ID;

void emojiKeyword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiKeyword");
    s.store_field("emoji", emoji_);
    s.store_field("keyword", keyword_);
    s.store_class_end();
  }
}

emojiReaction::emojiReaction()
  : emoji_()
  , title_()
  , is_active_()
  , static_icon_()
  , appear_animation_()
  , select_animation_()
  , activate_animation_()
  , effect_animation_()
  , around_animation_()
  , center_animation_()
{}

emojiReaction::emojiReaction(string const &emoji_, string const &title_, bool is_active_, object_ptr<sticker> &&static_icon_, object_ptr<sticker> &&appear_animation_, object_ptr<sticker> &&select_animation_, object_ptr<sticker> &&activate_animation_, object_ptr<sticker> &&effect_animation_, object_ptr<sticker> &&around_animation_, object_ptr<sticker> &&center_animation_)
  : emoji_(emoji_)
  , title_(title_)
  , is_active_(is_active_)
  , static_icon_(std::move(static_icon_))
  , appear_animation_(std::move(appear_animation_))
  , select_animation_(std::move(select_animation_))
  , activate_animation_(std::move(activate_animation_))
  , effect_animation_(std::move(effect_animation_))
  , around_animation_(std::move(around_animation_))
  , center_animation_(std::move(center_animation_))
{}

const std::int32_t emojiReaction::ID;

void emojiReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiReaction");
    s.store_field("emoji", emoji_);
    s.store_field("title", title_);
    s.store_field("is_active", is_active_);
    s.store_object_field("static_icon", static_cast<const BaseObject *>(static_icon_.get()));
    s.store_object_field("appear_animation", static_cast<const BaseObject *>(appear_animation_.get()));
    s.store_object_field("select_animation", static_cast<const BaseObject *>(select_animation_.get()));
    s.store_object_field("activate_animation", static_cast<const BaseObject *>(activate_animation_.get()));
    s.store_object_field("effect_animation", static_cast<const BaseObject *>(effect_animation_.get()));
    s.store_object_field("around_animation", static_cast<const BaseObject *>(around_animation_.get()));
    s.store_object_field("center_animation", static_cast<const BaseObject *>(center_animation_.get()));
    s.store_class_end();
  }
}

emojiStatuses::emojiStatuses()
  : emoji_statuses_()
{}

emojiStatuses::emojiStatuses(array<object_ptr<emojiStatus>> &&emoji_statuses_)
  : emoji_statuses_(std::move(emoji_statuses_))
{}

const std::int32_t emojiStatuses::ID;

void emojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatuses");
    { s.store_vector_begin("emoji_statuses", emoji_statuses_.size()); for (const auto &_value : emoji_statuses_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

ephemeralMessageContent::ephemeralMessageContent()
  : can_be_saved_()
  , has_timestamped_media_()
  , content_()
  , reply_markup_()
{}

ephemeralMessageContent::ephemeralMessageContent(bool can_be_saved_, bool has_timestamped_media_, object_ptr<MessageContent> &&content_, object_ptr<ReplyMarkup> &&reply_markup_)
  : can_be_saved_(can_be_saved_)
  , has_timestamped_media_(has_timestamped_media_)
  , content_(std::move(content_))
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t ephemeralMessageContent::ID;

void ephemeralMessageContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeralMessageContent");
    s.store_field("can_be_saved", can_be_saved_);
    s.store_field("has_timestamped_media", has_timestamped_media_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

fileDownloadedPrefixSize::fileDownloadedPrefixSize()
  : size_()
{}

fileDownloadedPrefixSize::fileDownloadedPrefixSize(int53 size_)
  : size_(size_)
{}

const std::int32_t fileDownloadedPrefixSize::ID;

void fileDownloadedPrefixSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileDownloadedPrefixSize");
    s.store_field("size", size_);
    s.store_class_end();
  }
}

fixedText::fixedText()
  : text_()
  , diff_text_()
{}

fixedText::fixedText(object_ptr<formattedText> &&text_, object_ptr<diffText> &&diff_text_)
  : text_(std::move(text_))
  , diff_text_(std::move(diff_text_))
{}

const std::int32_t fixedText::ID;

void fixedText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fixedText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("diff_text", static_cast<const BaseObject *>(diff_text_.get()));
    s.store_class_end();
  }
}

formattedText::formattedText()
  : text_()
  , entities_()
{}

formattedText::formattedText(string const &text_, array<object_ptr<textEntity>> &&entities_)
  : text_(text_)
  , entities_(std::move(entities_))
{}

const std::int32_t formattedText::ID;

void formattedText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "formattedText");
    s.store_field("text", text_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

forumTopicInfo::forumTopicInfo()
  : chat_id_()
  , forum_topic_id_()
  , name_()
  , icon_()
  , creation_date_()
  , creator_id_()
  , is_general_()
  , is_outgoing_()
  , is_closed_()
  , is_hidden_()
  , is_name_implicit_()
{}

forumTopicInfo::forumTopicInfo(int53 chat_id_, int32 forum_topic_id_, string const &name_, object_ptr<forumTopicIcon> &&icon_, int32 creation_date_, object_ptr<MessageSender> &&creator_id_, bool is_general_, bool is_outgoing_, bool is_closed_, bool is_hidden_, bool is_name_implicit_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , name_(name_)
  , icon_(std::move(icon_))
  , creation_date_(creation_date_)
  , creator_id_(std::move(creator_id_))
  , is_general_(is_general_)
  , is_outgoing_(is_outgoing_)
  , is_closed_(is_closed_)
  , is_hidden_(is_hidden_)
  , is_name_implicit_(is_name_implicit_)
{}

const std::int32_t forumTopicInfo::ID;

void forumTopicInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopicInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("name", name_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_field("creation_date", creation_date_);
    s.store_object_field("creator_id", static_cast<const BaseObject *>(creator_id_.get()));
    s.store_field("is_general", is_general_);
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("is_closed", is_closed_);
    s.store_field("is_hidden", is_hidden_);
    s.store_field("is_name_implicit", is_name_implicit_);
    s.store_class_end();
  }
}

foundChatMessages::foundChatMessages()
  : total_count_()
  , messages_()
  , next_from_message_id_()
{}

foundChatMessages::foundChatMessages(int32 total_count_, array<object_ptr<message>> &&messages_, int53 next_from_message_id_)
  : total_count_(total_count_)
  , messages_(std::move(messages_))
  , next_from_message_id_(next_from_message_id_)
{}

const std::int32_t foundChatMessages::ID;

void foundChatMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundChatMessages");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_from_message_id", next_from_message_id_);
    s.store_class_end();
  }
}

foundFileDownloads::foundFileDownloads()
  : total_counts_()
  , files_()
  , next_offset_()
{}

foundFileDownloads::foundFileDownloads(object_ptr<downloadedFileCounts> &&total_counts_, array<object_ptr<fileDownload>> &&files_, string const &next_offset_)
  : total_counts_(std::move(total_counts_))
  , files_(std::move(files_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundFileDownloads::ID;

void foundFileDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundFileDownloads");
    s.store_object_field("total_counts", static_cast<const BaseObject *>(total_counts_.get()));
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

giftAuctionState::giftAuctionState()
  : gift_()
  , state_()
{}

giftAuctionState::giftAuctionState(object_ptr<gift> &&gift_, object_ptr<AuctionState> &&state_)
  : gift_(std::move(gift_))
  , state_(std::move(state_))
{}

const std::int32_t giftAuctionState::ID;

void giftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftAuctionState");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

giftOnChainPurchaseOfferStatePending::giftOnChainPurchaseOfferStatePending() {
}

const std::int32_t giftOnChainPurchaseOfferStatePending::ID;

void giftOnChainPurchaseOfferStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftOnChainPurchaseOfferStatePending");
    s.store_class_end();
  }
}

giftOnChainPurchaseOfferStateSettled::giftOnChainPurchaseOfferStateSettled() {
}

const std::int32_t giftOnChainPurchaseOfferStateSettled::ID;

void giftOnChainPurchaseOfferStateSettled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftOnChainPurchaseOfferStateSettled");
    s.store_class_end();
  }
}

giftOnChainPurchaseOfferStateAccepted::giftOnChainPurchaseOfferStateAccepted() {
}

const std::int32_t giftOnChainPurchaseOfferStateAccepted::ID;

void giftOnChainPurchaseOfferStateAccepted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftOnChainPurchaseOfferStateAccepted");
    s.store_class_end();
  }
}

giftOnChainPurchaseOfferStateCanceling::giftOnChainPurchaseOfferStateCanceling() {
}

const std::int32_t giftOnChainPurchaseOfferStateCanceling::ID;

void giftOnChainPurchaseOfferStateCanceling::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftOnChainPurchaseOfferStateCanceling");
    s.store_class_end();
  }
}

giftOnChainPurchaseOfferStateDeclined::giftOnChainPurchaseOfferStateDeclined()
  : refund_amount_()
{}

giftOnChainPurchaseOfferStateDeclined::giftOnChainPurchaseOfferStateDeclined(int64 refund_amount_)
  : refund_amount_(refund_amount_)
{}

const std::int32_t giftOnChainPurchaseOfferStateDeclined::ID;

void giftOnChainPurchaseOfferStateDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftOnChainPurchaseOfferStateDeclined");
    s.store_field("refund_amount", refund_amount_);
    s.store_class_end();
  }
}

giftOnChainPurchaseOfferStateCanceled::giftOnChainPurchaseOfferStateCanceled()
  : refund_amount_()
  , fine_amount_()
{}

giftOnChainPurchaseOfferStateCanceled::giftOnChainPurchaseOfferStateCanceled(int64 refund_amount_, int64 fine_amount_)
  : refund_amount_(refund_amount_)
  , fine_amount_(fine_amount_)
{}

const std::int32_t giftOnChainPurchaseOfferStateCanceled::ID;

void giftOnChainPurchaseOfferStateCanceled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftOnChainPurchaseOfferStateCanceled");
    s.store_field("refund_amount", refund_amount_);
    s.store_field("fine_amount", fine_amount_);
    s.store_class_end();
  }
}

giftOnChainPurchaseOfferStateExpired::giftOnChainPurchaseOfferStateExpired()
  : refund_amount_()
{}

giftOnChainPurchaseOfferStateExpired::giftOnChainPurchaseOfferStateExpired(int64 refund_amount_)
  : refund_amount_(refund_amount_)
{}

const std::int32_t giftOnChainPurchaseOfferStateExpired::ID;

void giftOnChainPurchaseOfferStateExpired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftOnChainPurchaseOfferStateExpired");
    s.store_field("refund_amount", refund_amount_);
    s.store_class_end();
  }
}

giftOnChainPurchaseOfferTransaction::giftOnChainPurchaseOfferTransaction()
  : offer_address_()
  , expiration_date_()
  , message_()
  , gasless_message_()
  , rent_budget_amount_()
  , execution_allowance_amount_()
  , forward_amount_()
  , fine_amount_()
{}

giftOnChainPurchaseOfferTransaction::giftOnChainPurchaseOfferTransaction(string const &offer_address_, int32 expiration_date_, object_ptr<tonWalletMessage> &&message_, object_ptr<tonWalletMessage> &&gasless_message_, int64 rent_budget_amount_, int64 execution_allowance_amount_, int64 forward_amount_, int64 fine_amount_)
  : offer_address_(offer_address_)
  , expiration_date_(expiration_date_)
  , message_(std::move(message_))
  , gasless_message_(std::move(gasless_message_))
  , rent_budget_amount_(rent_budget_amount_)
  , execution_allowance_amount_(execution_allowance_amount_)
  , forward_amount_(forward_amount_)
  , fine_amount_(fine_amount_)
{}

const std::int32_t giftOnChainPurchaseOfferTransaction::ID;

void giftOnChainPurchaseOfferTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftOnChainPurchaseOfferTransaction");
    s.store_field("offer_address", offer_address_);
    s.store_field("expiration_date", expiration_date_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_object_field("gasless_message", static_cast<const BaseObject *>(gasless_message_.get()));
    s.store_field("rent_budget_amount", rent_budget_amount_);
    s.store_field("execution_allowance_amount", execution_allowance_amount_);
    s.store_field("forward_amount", forward_amount_);
    s.store_field("fine_amount", fine_amount_);
    s.store_class_end();
  }
}

giftOnChainSaleTransactionFragment::giftOnChainSaleTransactionFragment()
  : nft_address_()
  , payload_()
  , gram_amount_()
  , is_gasless_transfer_available_()
{}

giftOnChainSaleTransactionFragment::giftOnChainSaleTransactionFragment(string const &nft_address_, bytes const &payload_, int64 gram_amount_, bool is_gasless_transfer_available_)
  : nft_address_(nft_address_)
  , payload_(std::move(payload_))
  , gram_amount_(gram_amount_)
  , is_gasless_transfer_available_(is_gasless_transfer_available_)
{}

const std::int32_t giftOnChainSaleTransactionFragment::ID;

void giftOnChainSaleTransactionFragment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftOnChainSaleTransactionFragment");
    s.store_field("nft_address", nft_address_);
    s.store_bytes_field("payload", payload_);
    s.store_field("gram_amount", gram_amount_);
    s.store_field("is_gasless_transfer_available", is_gasless_transfer_available_);
    s.store_class_end();
  }
}

giftOnChainSaleTransactionFixedPrice::giftOnChainSaleTransactionFixedPrice()
  : sale_address_()
  , messages_()
  , gasless_messages_()
{}

giftOnChainSaleTransactionFixedPrice::giftOnChainSaleTransactionFixedPrice(string const &sale_address_, array<object_ptr<tonWalletMessage>> &&messages_, array<object_ptr<tonWalletMessage>> &&gasless_messages_)
  : sale_address_(sale_address_)
  , messages_(std::move(messages_))
  , gasless_messages_(std::move(gasless_messages_))
{}

const std::int32_t giftOnChainSaleTransactionFixedPrice::ID;

void giftOnChainSaleTransactionFixedPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftOnChainSaleTransactionFixedPrice");
    s.store_field("sale_address", sale_address_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("gasless_messages", gasless_messages_.size()); for (const auto &_value : gasless_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

groupCallVideoSourceGroup::groupCallVideoSourceGroup()
  : semantics_()
  , source_ids_()
{}

groupCallVideoSourceGroup::groupCallVideoSourceGroup(string const &semantics_, array<int32> &&source_ids_)
  : semantics_(semantics_)
  , source_ids_(std::move(source_ids_))
{}

const std::int32_t groupCallVideoSourceGroup::ID;

void groupCallVideoSourceGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoSourceGroup");
    s.store_field("semantics", semantics_);
    { s.store_vector_begin("source_ids", source_ids_.size()); for (const auto &_value : source_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPassportElementError::inputPassportElementError()
  : type_()
  , message_()
  , source_()
{}

inputPassportElementError::inputPassportElementError(object_ptr<PassportElementType> &&type_, string const &message_, object_ptr<InputPassportElementErrorSource> &&source_)
  : type_(std::move(type_))
  , message_(message_)
  , source_(std::move(source_))
{}

const std::int32_t inputPassportElementError::ID;

void inputPassportElementError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementError");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("message", message_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

inputSticker::inputSticker()
  : sticker_()
  , thumbnail_()
  , width_()
  , height_()
{}

inputSticker::inputSticker(object_ptr<InputFile> &&sticker_, object_ptr<inputThumbnail> &&thumbnail_, int32 width_, int32 height_)
  : sticker_(std::move(sticker_))
  , thumbnail_(std::move(thumbnail_))
  , width_(width_)
  , height_(height_)
{}

const std::int32_t inputSticker::ID;

void inputSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

labeledPricePart::labeledPricePart()
  : label_()
  , amount_()
{}

labeledPricePart::labeledPricePart(string const &label_, int53 amount_)
  : label_(label_)
  , amount_(amount_)
{}

const std::int32_t labeledPricePart::ID;

void labeledPricePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "labeledPricePart");
    s.store_field("label", label_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

loginUrlInfoOpen::loginUrlInfoOpen()
  : url_()
  , skip_confirmation_()
{}

loginUrlInfoOpen::loginUrlInfoOpen(string const &url_, bool skip_confirmation_)
  : url_(url_)
  , skip_confirmation_(skip_confirmation_)
{}

const std::int32_t loginUrlInfoOpen::ID;

void loginUrlInfoOpen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loginUrlInfoOpen");
    s.store_field("url", url_);
    s.store_field("skip_confirmation", skip_confirmation_);
    s.store_class_end();
  }
}

loginUrlInfoRequestConfirmation::loginUrlInfoRequestConfirmation()
  : url_()
  , domain_()
  , bot_user_id_()
  , request_write_access_()
{}

loginUrlInfoRequestConfirmation::loginUrlInfoRequestConfirmation(string const &url_, string const &domain_, int53 bot_user_id_, bool request_write_access_)
  : url_(url_)
  , domain_(domain_)
  , bot_user_id_(bot_user_id_)
  , request_write_access_(request_write_access_)
{}

const std::int32_t loginUrlInfoRequestConfirmation::ID;

void loginUrlInfoRequestConfirmation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loginUrlInfoRequestConfirmation");
    s.store_field("url", url_);
    s.store_field("domain", domain_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("request_write_access", request_write_access_);
    s.store_class_end();
  }
}

messageText::messageText()
  : text_()
  , link_preview_()
  , link_preview_options_()
{}

messageText::messageText(object_ptr<formattedText> &&text_, object_ptr<linkPreview> &&link_preview_, object_ptr<linkPreviewOptions> &&link_preview_options_)
  : text_(std::move(text_))
  , link_preview_(std::move(link_preview_))
  , link_preview_options_(std::move(link_preview_options_))
{}

const std::int32_t messageText::ID;

void messageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("link_preview", static_cast<const BaseObject *>(link_preview_.get()));
    s.store_object_field("link_preview_options", static_cast<const BaseObject *>(link_preview_options_.get()));
    s.store_class_end();
  }
}

messageRichMessage::messageRichMessage()
  : message_()
{}

messageRichMessage::messageRichMessage(object_ptr<richMessage> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t messageRichMessage::ID;

void messageRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageRichMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

messageAnimation::messageAnimation()
  : animation_()
  , caption_()
  , show_caption_above_media_()
  , has_spoiler_()
  , is_secret_()
{}

messageAnimation::messageAnimation(object_ptr<animation> &&animation_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, bool has_spoiler_, bool is_secret_)
  : animation_(std::move(animation_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , has_spoiler_(has_spoiler_)
  , is_secret_(is_secret_)
{}

const std::int32_t messageAnimation::ID;

void messageAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("has_spoiler", has_spoiler_);
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageAudio::messageAudio()
  : audio_()
  , caption_()
{}

messageAudio::messageAudio(object_ptr<audio> &&audio_, object_ptr<formattedText> &&caption_)
  : audio_(std::move(audio_))
  , caption_(std::move(caption_))
{}

const std::int32_t messageAudio::ID;

void messageAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

messageDocument::messageDocument()
  : document_()
  , caption_()
{}

messageDocument::messageDocument(object_ptr<document> &&document_, object_ptr<formattedText> &&caption_)
  : document_(std::move(document_))
  , caption_(std::move(caption_))
{}

const std::int32_t messageDocument::ID;

void messageDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

messagePaidMedia::messagePaidMedia()
  : star_count_()
  , media_()
  , caption_()
  , show_caption_above_media_()
{}

messagePaidMedia::messagePaidMedia(int53 star_count_, array<object_ptr<PaidMedia>> &&media_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_)
  : star_count_(star_count_)
  , media_(std::move(media_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
{}

const std::int32_t messagePaidMedia::ID;

void messagePaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaidMedia");
    s.store_field("star_count", star_count_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_class_end();
  }
}

messagePhoto::messagePhoto()
  : photo_()
  , video_()
  , caption_()
  , show_caption_above_media_()
  , has_spoiler_()
  , is_secret_()
{}

messagePhoto::messagePhoto(object_ptr<photo> &&photo_, object_ptr<video> &&video_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, bool has_spoiler_, bool is_secret_)
  : photo_(std::move(photo_))
  , video_(std::move(video_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , has_spoiler_(has_spoiler_)
  , is_secret_(is_secret_)
{}

const std::int32_t messagePhoto::ID;

void messagePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("has_spoiler", has_spoiler_);
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageSticker::messageSticker()
  : sticker_()
  , is_premium_()
{}

messageSticker::messageSticker(object_ptr<sticker> &&sticker_, bool is_premium_)
  : sticker_(std::move(sticker_))
  , is_premium_(is_premium_)
{}

const std::int32_t messageSticker::ID;

void messageSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("is_premium", is_premium_);
    s.store_class_end();
  }
}

messageVideo::messageVideo()
  : video_()
  , alternative_videos_()
  , storyboards_()
  , cover_()
  , start_timestamp_()
  , caption_()
  , show_caption_above_media_()
  , has_spoiler_()
  , is_secret_()
{}

messageVideo::messageVideo(object_ptr<video> &&video_, array<object_ptr<alternativeVideo>> &&alternative_videos_, array<object_ptr<videoStoryboard>> &&storyboards_, object_ptr<photo> &&cover_, int32 start_timestamp_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, bool has_spoiler_, bool is_secret_)
  : video_(std::move(video_))
  , alternative_videos_(std::move(alternative_videos_))
  , storyboards_(std::move(storyboards_))
  , cover_(std::move(cover_))
  , start_timestamp_(start_timestamp_)
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , has_spoiler_(has_spoiler_)
  , is_secret_(is_secret_)
{}

const std::int32_t messageVideo::ID;

void messageVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    { s.store_vector_begin("alternative_videos", alternative_videos_.size()); for (const auto &_value : alternative_videos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("storyboards", storyboards_.size()); for (const auto &_value : storyboards_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_field("start_timestamp", start_timestamp_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("has_spoiler", has_spoiler_);
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageVideoNote::messageVideoNote()
  : video_note_()
  , is_viewed_()
  , is_secret_()
{}

messageVideoNote::messageVideoNote(object_ptr<videoNote> &&video_note_, bool is_viewed_, bool is_secret_)
  : video_note_(std::move(video_note_))
  , is_viewed_(is_viewed_)
  , is_secret_(is_secret_)
{}

const std::int32_t messageVideoNote::ID;

void messageVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_field("is_viewed", is_viewed_);
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageVoiceNote::messageVoiceNote()
  : voice_note_()
  , caption_()
  , is_listened_()
{}

messageVoiceNote::messageVoiceNote(object_ptr<voiceNote> &&voice_note_, object_ptr<formattedText> &&caption_, bool is_listened_)
  : voice_note_(std::move(voice_note_))
  , caption_(std::move(caption_))
  , is_listened_(is_listened_)
{}

const std::int32_t messageVoiceNote::ID;

void messageVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("is_listened", is_listened_);
    s.store_class_end();
  }
}

messageExpiredPhoto::messageExpiredPhoto() {
}

const std::int32_t messageExpiredPhoto::ID;

void messageExpiredPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExpiredPhoto");
    s.store_class_end();
  }
}

messageExpiredVideo::messageExpiredVideo() {
}

const std::int32_t messageExpiredVideo::ID;

void messageExpiredVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExpiredVideo");
    s.store_class_end();
  }
}

messageExpiredVideoNote::messageExpiredVideoNote() {
}

const std::int32_t messageExpiredVideoNote::ID;

void messageExpiredVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExpiredVideoNote");
    s.store_class_end();
  }
}

messageExpiredVoiceNote::messageExpiredVoiceNote() {
}

const std::int32_t messageExpiredVoiceNote::ID;

void messageExpiredVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExpiredVoiceNote");
    s.store_class_end();
  }
}

messageLiveLocation::messageLiveLocation()
  : location_()
  , expires_in_()
{}

messageLiveLocation::messageLiveLocation(object_ptr<liveLocation> &&location_, int32 expires_in_)
  : location_(std::move(location_))
  , expires_in_(expires_in_)
{}

const std::int32_t messageLiveLocation::ID;

void messageLiveLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageLiveLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("expires_in", expires_in_);
    s.store_class_end();
  }
}

messageLocation::messageLocation()
  : location_()
{}

messageLocation::messageLocation(object_ptr<location> &&location_)
  : location_(std::move(location_))
{}

const std::int32_t messageLocation::ID;

void messageLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

messageVenue::messageVenue()
  : venue_()
{}

messageVenue::messageVenue(object_ptr<venue> &&venue_)
  : venue_(std::move(venue_))
{}

const std::int32_t messageVenue::ID;

void messageVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVenue");
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_class_end();
  }
}

messageContact::messageContact()
  : contact_()
{}

messageContact::messageContact(object_ptr<contact> &&contact_)
  : contact_(std::move(contact_))
{}

const std::int32_t messageContact::ID;

void messageContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageContact");
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_class_end();
  }
}

messageAnimatedEmoji::messageAnimatedEmoji()
  : animated_emoji_()
  , emoji_()
{}

messageAnimatedEmoji::messageAnimatedEmoji(object_ptr<animatedEmoji> &&animated_emoji_, string const &emoji_)
  : animated_emoji_(std::move(animated_emoji_))
  , emoji_(emoji_)
{}

const std::int32_t messageAnimatedEmoji::ID;

void messageAnimatedEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageAnimatedEmoji");
    s.store_object_field("animated_emoji", static_cast<const BaseObject *>(animated_emoji_.get()));
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

messageDice::messageDice()
  : initial_state_()
  , final_state_()
  , emoji_()
  , value_()
  , success_animation_frame_number_()
{}

messageDice::messageDice(object_ptr<DiceStickers> &&initial_state_, object_ptr<DiceStickers> &&final_state_, string const &emoji_, int32 value_, int32 success_animation_frame_number_)
  : initial_state_(std::move(initial_state_))
  , final_state_(std::move(final_state_))
  , emoji_(emoji_)
  , value_(value_)
  , success_animation_frame_number_(success_animation_frame_number_)
{}

const std::int32_t messageDice::ID;

void messageDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageDice");
    s.store_object_field("initial_state", static_cast<const BaseObject *>(initial_state_.get()));
    s.store_object_field("final_state", static_cast<const BaseObject *>(final_state_.get()));
    s.store_field("emoji", emoji_);
    s.store_field("value", value_);
    s.store_field("success_animation_frame_number", success_animation_frame_number_);
    s.store_class_end();
  }
}

messageGame::messageGame()
  : game_()
{}

messageGame::messageGame(object_ptr<game> &&game_)
  : game_(std::move(game_))
{}

const std::int32_t messageGame::ID;

void messageGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGame");
    s.store_object_field("game", static_cast<const BaseObject *>(game_.get()));
    s.store_class_end();
  }
}

messagePoll::messagePoll()
  : poll_()
  , description_()
  , media_()
  , can_add_option_()
{}

messagePoll::messagePoll(object_ptr<poll> &&poll_, object_ptr<formattedText> &&description_, object_ptr<PollMedia> &&media_, bool can_add_option_)
  : poll_(std::move(poll_))
  , description_(std::move(description_))
  , media_(std::move(media_))
  , can_add_option_(can_add_option_)
{}

const std::int32_t messagePoll::ID;

void messagePoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePoll");
    s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get()));
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_field("can_add_option", can_add_option_);
    s.store_class_end();
  }
}

messageStakeDice::messageStakeDice()
  : initial_state_()
  , final_state_()
  , value_()
  , stake_gram_amount_()
  , prize_gram_amount_()
{}

messageStakeDice::messageStakeDice(object_ptr<DiceStickers> &&initial_state_, object_ptr<DiceStickers> &&final_state_, int32 value_, int53 stake_gram_amount_, int53 prize_gram_amount_)
  : initial_state_(std::move(initial_state_))
  , final_state_(std::move(final_state_))
  , value_(value_)
  , stake_gram_amount_(stake_gram_amount_)
  , prize_gram_amount_(prize_gram_amount_)
{}

const std::int32_t messageStakeDice::ID;

void messageStakeDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageStakeDice");
    s.store_object_field("initial_state", static_cast<const BaseObject *>(initial_state_.get()));
    s.store_object_field("final_state", static_cast<const BaseObject *>(final_state_.get()));
    s.store_field("value", value_);
    s.store_field("stake_gram_amount", stake_gram_amount_);
    s.store_field("prize_gram_amount", prize_gram_amount_);
    s.store_class_end();
  }
}

messageStory::messageStory()
  : story_poster_chat_id_()
  , story_id_()
  , via_mention_()
{}

messageStory::messageStory(int53 story_poster_chat_id_, int32 story_id_, bool via_mention_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , via_mention_(via_mention_)
{}

const std::int32_t messageStory::ID;

void messageStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("via_mention", via_mention_);
    s.store_class_end();
  }
}

messageWidget::messageWidget()
  : width_()
  , height_()
  , html_()
  , public_data_()
  , chat_data_()
  , widget_id_()
  , caption_()
  , show_caption_above_media_()
  , is_copy_()
  , can_send_queries_()
  , can_send_background_queries_()
{}

messageWidget::messageWidget(int32 width_, int32 height_, string const &html_, string const &public_data_, string const &chat_data_, int64 widget_id_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, bool is_copy_, bool can_send_queries_, bool can_send_background_queries_)
  : width_(width_)
  , height_(height_)
  , html_(html_)
  , public_data_(public_data_)
  , chat_data_(chat_data_)
  , widget_id_(widget_id_)
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , is_copy_(is_copy_)
  , can_send_queries_(can_send_queries_)
  , can_send_background_queries_(can_send_background_queries_)
{}

const std::int32_t messageWidget::ID;

void messageWidget::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageWidget");
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("html", html_);
    s.store_field("public_data", public_data_);
    s.store_field("chat_data", chat_data_);
    s.store_field("widget_id", widget_id_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("is_copy", is_copy_);
    s.store_field("can_send_queries", can_send_queries_);
    s.store_field("can_send_background_queries", can_send_background_queries_);
    s.store_class_end();
  }
}

messageChecklist::messageChecklist()
  : list_()
{}

messageChecklist::messageChecklist(object_ptr<checklist> &&list_)
  : list_(std::move(list_))
{}

const std::int32_t messageChecklist::ID;

void messageChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChecklist");
    s.store_object_field("list", static_cast<const BaseObject *>(list_.get()));
    s.store_class_end();
  }
}

messageInvoice::messageInvoice()
  : product_info_()
  , currency_()
  , total_amount_()
  , start_parameter_()
  , is_test_()
  , need_shipping_address_()
  , receipt_message_id_()
  , paid_media_()
  , paid_media_caption_()
{}

messageInvoice::messageInvoice(object_ptr<productInfo> &&product_info_, string const &currency_, int53 total_amount_, string const &start_parameter_, bool is_test_, bool need_shipping_address_, int53 receipt_message_id_, object_ptr<PaidMedia> &&paid_media_, object_ptr<formattedText> &&paid_media_caption_)
  : product_info_(std::move(product_info_))
  , currency_(currency_)
  , total_amount_(total_amount_)
  , start_parameter_(start_parameter_)
  , is_test_(is_test_)
  , need_shipping_address_(need_shipping_address_)
  , receipt_message_id_(receipt_message_id_)
  , paid_media_(std::move(paid_media_))
  , paid_media_caption_(std::move(paid_media_caption_))
{}

const std::int32_t messageInvoice::ID;

void messageInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageInvoice");
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("start_parameter", start_parameter_);
    s.store_field("is_test", is_test_);
    s.store_field("need_shipping_address", need_shipping_address_);
    s.store_field("receipt_message_id", receipt_message_id_);
    s.store_object_field("paid_media", static_cast<const BaseObject *>(paid_media_.get()));
    s.store_object_field("paid_media_caption", static_cast<const BaseObject *>(paid_media_caption_.get()));
    s.store_class_end();
  }
}

messageCall::messageCall()
  : unique_id_()
  , is_video_()
  , discard_reason_()
  , duration_()
{}

messageCall::messageCall(int64 unique_id_, bool is_video_, object_ptr<CallDiscardReason> &&discard_reason_, int32 duration_)
  : unique_id_(unique_id_)
  , is_video_(is_video_)
  , discard_reason_(std::move(discard_reason_))
  , duration_(duration_)
{}

const std::int32_t messageCall::ID;

void messageCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCall");
    s.store_field("unique_id", unique_id_);
    s.store_field("is_video", is_video_);
    s.store_object_field("discard_reason", static_cast<const BaseObject *>(discard_reason_.get()));
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

messageGroupCall::messageGroupCall()
  : unique_id_()
  , is_active_()
  , was_missed_()
  , is_video_()
  , duration_()
  , other_participant_ids_()
{}

messageGroupCall::messageGroupCall(int64 unique_id_, bool is_active_, bool was_missed_, bool is_video_, int32 duration_, array<object_ptr<MessageSender>> &&other_participant_ids_)
  : unique_id_(unique_id_)
  , is_active_(is_active_)
  , was_missed_(was_missed_)
  , is_video_(is_video_)
  , duration_(duration_)
  , other_participant_ids_(std::move(other_participant_ids_))
{}

const std::int32_t messageGroupCall::ID;

void messageGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGroupCall");
    s.store_field("unique_id", unique_id_);
    s.store_field("is_active", is_active_);
    s.store_field("was_missed", was_missed_);
    s.store_field("is_video", is_video_);
    s.store_field("duration", duration_);
    { s.store_vector_begin("other_participant_ids", other_participant_ids_.size()); for (const auto &_value : other_participant_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageVideoChatScheduled::messageVideoChatScheduled()
  : group_call_id_()
  , start_date_()
{}

messageVideoChatScheduled::messageVideoChatScheduled(int32 group_call_id_, int32 start_date_)
  : group_call_id_(group_call_id_)
  , start_date_(start_date_)
{}

const std::int32_t messageVideoChatScheduled::ID;

void messageVideoChatScheduled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoChatScheduled");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("start_date", start_date_);
    s.store_class_end();
  }
}

messageVideoChatStarted::messageVideoChatStarted()
  : group_call_id_()
{}

messageVideoChatStarted::messageVideoChatStarted(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t messageVideoChatStarted::ID;

void messageVideoChatStarted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoChatStarted");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

messageVideoChatEnded::messageVideoChatEnded()
  : duration_()
{}

messageVideoChatEnded::messageVideoChatEnded(int32 duration_)
  : duration_(duration_)
{}

const std::int32_t messageVideoChatEnded::ID;

void messageVideoChatEnded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoChatEnded");
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

messageInviteVideoChatParticipants::messageInviteVideoChatParticipants()
  : group_call_id_()
  , user_ids_()
{}

messageInviteVideoChatParticipants::messageInviteVideoChatParticipants(int32 group_call_id_, array<int53> &&user_ids_)
  : group_call_id_(group_call_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t messageInviteVideoChatParticipants::ID;

void messageInviteVideoChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageInviteVideoChatParticipants");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messagePollOptionAdded::messagePollOptionAdded()
  : poll_message_id_()
  , option_id_()
  , text_()
{}

messagePollOptionAdded::messagePollOptionAdded(int53 poll_message_id_, string const &option_id_, object_ptr<formattedText> &&text_)
  : poll_message_id_(poll_message_id_)
  , option_id_(option_id_)
  , text_(std::move(text_))
{}

const std::int32_t messagePollOptionAdded::ID;

void messagePollOptionAdded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePollOptionAdded");
    s.store_field("poll_message_id", poll_message_id_);
    s.store_field("option_id", option_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

messagePollOptionDeleted::messagePollOptionDeleted()
  : poll_message_id_()
  , option_id_()
  , text_()
{}

messagePollOptionDeleted::messagePollOptionDeleted(int53 poll_message_id_, string const &option_id_, object_ptr<formattedText> &&text_)
  : poll_message_id_(poll_message_id_)
  , option_id_(option_id_)
  , text_(std::move(text_))
{}

const std::int32_t messagePollOptionDeleted::ID;

void messagePollOptionDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePollOptionDeleted");
    s.store_field("poll_message_id", poll_message_id_);
    s.store_field("option_id", option_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

messageBasicGroupChatCreate::messageBasicGroupChatCreate()
  : title_()
  , member_user_ids_()
{}

messageBasicGroupChatCreate::messageBasicGroupChatCreate(string const &title_, array<int53> &&member_user_ids_)
  : title_(title_)
  , member_user_ids_(std::move(member_user_ids_))
{}

const std::int32_t messageBasicGroupChatCreate::ID;

void messageBasicGroupChatCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageBasicGroupChatCreate");
    s.store_field("title", title_);
    { s.store_vector_begin("member_user_ids", member_user_ids_.size()); for (const auto &_value : member_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageSupergroupChatCreate::messageSupergroupChatCreate()
  : title_()
{}

messageSupergroupChatCreate::messageSupergroupChatCreate(string const &title_)
  : title_(title_)
{}

const std::int32_t messageSupergroupChatCreate::ID;

void messageSupergroupChatCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSupergroupChatCreate");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

messageChatChangeTitle::messageChatChangeTitle()
  : title_()
{}

messageChatChangeTitle::messageChatChangeTitle(string const &title_)
  : title_(title_)
{}

const std::int32_t messageChatChangeTitle::ID;

void messageChatChangeTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatChangeTitle");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

messageChatChangePhoto::messageChatChangePhoto()
  : photo_()
{}

messageChatChangePhoto::messageChatChangePhoto(object_ptr<chatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t messageChatChangePhoto::ID;

void messageChatChangePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatChangePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

messageChatDeletePhoto::messageChatDeletePhoto() {
}

const std::int32_t messageChatDeletePhoto::ID;

void messageChatDeletePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatDeletePhoto");
    s.store_class_end();
  }
}

messageChatOwnerLeft::messageChatOwnerLeft()
  : new_owner_user_id_()
{}

messageChatOwnerLeft::messageChatOwnerLeft(int53 new_owner_user_id_)
  : new_owner_user_id_(new_owner_user_id_)
{}

const std::int32_t messageChatOwnerLeft::ID;

void messageChatOwnerLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatOwnerLeft");
    s.store_field("new_owner_user_id", new_owner_user_id_);
    s.store_class_end();
  }
}

messageChatOwnerChanged::messageChatOwnerChanged()
  : new_owner_user_id_()
{}

messageChatOwnerChanged::messageChatOwnerChanged(int53 new_owner_user_id_)
  : new_owner_user_id_(new_owner_user_id_)
{}

const std::int32_t messageChatOwnerChanged::ID;

void messageChatOwnerChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatOwnerChanged");
    s.store_field("new_owner_user_id", new_owner_user_id_);
    s.store_class_end();
  }
}

messageChatHasProtectedContentToggled::messageChatHasProtectedContentToggled()
  : request_message_id_()
  , old_has_protected_content_()
  , new_has_protected_content_()
{}

messageChatHasProtectedContentToggled::messageChatHasProtectedContentToggled(int53 request_message_id_, bool old_has_protected_content_, bool new_has_protected_content_)
  : request_message_id_(request_message_id_)
  , old_has_protected_content_(old_has_protected_content_)
  , new_has_protected_content_(new_has_protected_content_)
{}

const std::int32_t messageChatHasProtectedContentToggled::ID;

void messageChatHasProtectedContentToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatHasProtectedContentToggled");
    s.store_field("request_message_id", request_message_id_);
    s.store_field("old_has_protected_content", old_has_protected_content_);
    s.store_field("new_has_protected_content", new_has_protected_content_);
    s.store_class_end();
  }
}

messageChatHasProtectedContentDisableRequested::messageChatHasProtectedContentDisableRequested()
  : is_expired_()
{}

messageChatHasProtectedContentDisableRequested::messageChatHasProtectedContentDisableRequested(bool is_expired_)
  : is_expired_(is_expired_)
{}

const std::int32_t messageChatHasProtectedContentDisableRequested::ID;

void messageChatHasProtectedContentDisableRequested::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatHasProtectedContentDisableRequested");
    s.store_field("is_expired", is_expired_);
    s.store_class_end();
  }
}

messageChatAddMembers::messageChatAddMembers()
  : member_user_ids_()
{}

messageChatAddMembers::messageChatAddMembers(array<int53> &&member_user_ids_)
  : member_user_ids_(std::move(member_user_ids_))
{}

const std::int32_t messageChatAddMembers::ID;

void messageChatAddMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatAddMembers");
    { s.store_vector_begin("member_user_ids", member_user_ids_.size()); for (const auto &_value : member_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageChatJoinByLink::messageChatJoinByLink() {
}

const std::int32_t messageChatJoinByLink::ID;

void messageChatJoinByLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatJoinByLink");
    s.store_class_end();
  }
}

messageChatJoinByRequest::messageChatJoinByRequest() {
}

const std::int32_t messageChatJoinByRequest::ID;

void messageChatJoinByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatJoinByRequest");
    s.store_class_end();
  }
}

messageChatJoinFromCommunity::messageChatJoinFromCommunity()
  : community_id_()
{}

messageChatJoinFromCommunity::messageChatJoinFromCommunity(int53 community_id_)
  : community_id_(community_id_)
{}

const std::int32_t messageChatJoinFromCommunity::ID;

void messageChatJoinFromCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatJoinFromCommunity");
    s.store_field("community_id", community_id_);
    s.store_class_end();
  }
}

messageChatDeleteMember::messageChatDeleteMember()
  : user_id_()
{}

messageChatDeleteMember::messageChatDeleteMember(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t messageChatDeleteMember::ID;

void messageChatDeleteMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatDeleteMember");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

messageChatAddedToCommunity::messageChatAddedToCommunity()
  : community_id_()
{}

messageChatAddedToCommunity::messageChatAddedToCommunity(int53 community_id_)
  : community_id_(community_id_)
{}

const std::int32_t messageChatAddedToCommunity::ID;

void messageChatAddedToCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatAddedToCommunity");
    s.store_field("community_id", community_id_);
    s.store_class_end();
  }
}

messageChatRemovedFromCommunity::messageChatRemovedFromCommunity() {
}

const std::int32_t messageChatRemovedFromCommunity::ID;

void messageChatRemovedFromCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatRemovedFromCommunity");
    s.store_class_end();
  }
}

messageChatUpgradeTo::messageChatUpgradeTo()
  : supergroup_id_()
{}

messageChatUpgradeTo::messageChatUpgradeTo(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t messageChatUpgradeTo::ID;

void messageChatUpgradeTo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatUpgradeTo");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

messageChatUpgradeFrom::messageChatUpgradeFrom()
  : title_()
  , basic_group_id_()
{}

messageChatUpgradeFrom::messageChatUpgradeFrom(string const &title_, int53 basic_group_id_)
  : title_(title_)
  , basic_group_id_(basic_group_id_)
{}

const std::int32_t messageChatUpgradeFrom::ID;

void messageChatUpgradeFrom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatUpgradeFrom");
    s.store_field("title", title_);
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

messagePinMessage::messagePinMessage()
  : message_id_()
{}

messagePinMessage::messagePinMessage(int53 message_id_)
  : message_id_(message_id_)
{}

const std::int32_t messagePinMessage::ID;

void messagePinMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePinMessage");
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

messageScreenshotTaken::messageScreenshotTaken() {
}

const std::int32_t messageScreenshotTaken::ID;

void messageScreenshotTaken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageScreenshotTaken");
    s.store_class_end();
  }
}

messageChatSetBackground::messageChatSetBackground()
  : old_background_message_id_()
  , background_()
  , only_for_self_()
{}

messageChatSetBackground::messageChatSetBackground(int53 old_background_message_id_, object_ptr<chatBackground> &&background_, bool only_for_self_)
  : old_background_message_id_(old_background_message_id_)
  , background_(std::move(background_))
  , only_for_self_(only_for_self_)
{}

const std::int32_t messageChatSetBackground::ID;

void messageChatSetBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatSetBackground");
    s.store_field("old_background_message_id", old_background_message_id_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_field("only_for_self", only_for_self_);
    s.store_class_end();
  }
}

messageChatSetTheme::messageChatSetTheme()
  : theme_()
{}

messageChatSetTheme::messageChatSetTheme(object_ptr<ChatTheme> &&theme_)
  : theme_(std::move(theme_))
{}

const std::int32_t messageChatSetTheme::ID;

void messageChatSetTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatSetTheme");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

messageChatSetMessageAutoDeleteTime::messageChatSetMessageAutoDeleteTime()
  : message_auto_delete_time_()
  , from_user_id_()
{}

messageChatSetMessageAutoDeleteTime::messageChatSetMessageAutoDeleteTime(int32 message_auto_delete_time_, int53 from_user_id_)
  : message_auto_delete_time_(message_auto_delete_time_)
  , from_user_id_(from_user_id_)
{}

const std::int32_t messageChatSetMessageAutoDeleteTime::ID;

void messageChatSetMessageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatSetMessageAutoDeleteTime");
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_field("from_user_id", from_user_id_);
    s.store_class_end();
  }
}

messageChatBoost::messageChatBoost()
  : boost_count_()
{}

messageChatBoost::messageChatBoost(int32 boost_count_)
  : boost_count_(boost_count_)
{}

const std::int32_t messageChatBoost::ID;

void messageChatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatBoost");
    s.store_field("boost_count", boost_count_);
    s.store_class_end();
  }
}

messageForumTopicCreated::messageForumTopicCreated()
  : name_()
  , is_name_implicit_()
  , icon_()
{}

messageForumTopicCreated::messageForumTopicCreated(string const &name_, bool is_name_implicit_, object_ptr<forumTopicIcon> &&icon_)
  : name_(name_)
  , is_name_implicit_(is_name_implicit_)
  , icon_(std::move(icon_))
{}

const std::int32_t messageForumTopicCreated::ID;

void messageForumTopicCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForumTopicCreated");
    s.store_field("name", name_);
    s.store_field("is_name_implicit", is_name_implicit_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_class_end();
  }
}

messageForumTopicEdited::messageForumTopicEdited()
  : name_()
  , edit_icon_custom_emoji_id_()
  , icon_custom_emoji_id_()
{}

messageForumTopicEdited::messageForumTopicEdited(string const &name_, bool edit_icon_custom_emoji_id_, int64 icon_custom_emoji_id_)
  : name_(name_)
  , edit_icon_custom_emoji_id_(edit_icon_custom_emoji_id_)
  , icon_custom_emoji_id_(icon_custom_emoji_id_)
{}

const std::int32_t messageForumTopicEdited::ID;

void messageForumTopicEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForumTopicEdited");
    s.store_field("name", name_);
    s.store_field("edit_icon_custom_emoji_id", edit_icon_custom_emoji_id_);
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_class_end();
  }
}

messageForumTopicIsClosedToggled::messageForumTopicIsClosedToggled()
  : is_closed_()
{}

messageForumTopicIsClosedToggled::messageForumTopicIsClosedToggled(bool is_closed_)
  : is_closed_(is_closed_)
{}

const std::int32_t messageForumTopicIsClosedToggled::ID;

void messageForumTopicIsClosedToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForumTopicIsClosedToggled");
    s.store_field("is_closed", is_closed_);
    s.store_class_end();
  }
}

messageForumTopicIsHiddenToggled::messageForumTopicIsHiddenToggled()
  : is_hidden_()
{}

messageForumTopicIsHiddenToggled::messageForumTopicIsHiddenToggled(bool is_hidden_)
  : is_hidden_(is_hidden_)
{}

const std::int32_t messageForumTopicIsHiddenToggled::ID;

void messageForumTopicIsHiddenToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForumTopicIsHiddenToggled");
    s.store_field("is_hidden", is_hidden_);
    s.store_class_end();
  }
}

messageSuggestProfilePhoto::messageSuggestProfilePhoto()
  : photo_()
{}

messageSuggestProfilePhoto::messageSuggestProfilePhoto(object_ptr<chatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t messageSuggestProfilePhoto::ID;

void messageSuggestProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestProfilePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

messageSuggestBirthdate::messageSuggestBirthdate()
  : birthdate_()
{}

messageSuggestBirthdate::messageSuggestBirthdate(object_ptr<birthdate> &&birthdate_)
  : birthdate_(std::move(birthdate_))
{}

const std::int32_t messageSuggestBirthdate::ID;

void messageSuggestBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestBirthdate");
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_class_end();
  }
}

messageCustomServiceAction::messageCustomServiceAction()
  : text_()
{}

messageCustomServiceAction::messageCustomServiceAction(string const &text_)
  : text_(text_)
{}

const std::int32_t messageCustomServiceAction::ID;

void messageCustomServiceAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCustomServiceAction");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

messageGameScore::messageGameScore()
  : game_message_id_()
  , game_id_()
  , score_()
{}

messageGameScore::messageGameScore(int53 game_message_id_, int64 game_id_, int32 score_)
  : game_message_id_(game_message_id_)
  , game_id_(game_id_)
  , score_(score_)
{}

const std::int32_t messageGameScore::ID;

void messageGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGameScore");
    s.store_field("game_message_id", game_message_id_);
    s.store_field("game_id", game_id_);
    s.store_field("score", score_);
    s.store_class_end();
  }
}

messageManagedBotCreated::messageManagedBotCreated()
  : bot_user_id_()
  , manager_bot_user_id_()
{}

messageManagedBotCreated::messageManagedBotCreated(int53 bot_user_id_, int53 manager_bot_user_id_)
  : bot_user_id_(bot_user_id_)
  , manager_bot_user_id_(manager_bot_user_id_)
{}

const std::int32_t messageManagedBotCreated::ID;

void messageManagedBotCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageManagedBotCreated");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("manager_bot_user_id", manager_bot_user_id_);
    s.store_class_end();
  }
}

messageBotInvite::messageBotInvite()
  : inviter_user_id_()
{}

messageBotInvite::messageBotInvite(int53 inviter_user_id_)
  : inviter_user_id_(inviter_user_id_)
{}

const std::int32_t messageBotInvite::ID;

void messageBotInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageBotInvite");
    s.store_field("inviter_user_id", inviter_user_id_);
    s.store_class_end();
  }
}

messagePaymentSuccessful::messagePaymentSuccessful()
  : invoice_chat_id_()
  , invoice_message_id_()
  , currency_()
  , total_amount_()
  , subscription_until_date_()
  , is_recurring_()
  , is_first_recurring_()
  , invoice_name_()
{}

messagePaymentSuccessful::messagePaymentSuccessful(int53 invoice_chat_id_, int53 invoice_message_id_, string const &currency_, int53 total_amount_, int32 subscription_until_date_, bool is_recurring_, bool is_first_recurring_, string const &invoice_name_)
  : invoice_chat_id_(invoice_chat_id_)
  , invoice_message_id_(invoice_message_id_)
  , currency_(currency_)
  , total_amount_(total_amount_)
  , subscription_until_date_(subscription_until_date_)
  , is_recurring_(is_recurring_)
  , is_first_recurring_(is_first_recurring_)
  , invoice_name_(invoice_name_)
{}

const std::int32_t messagePaymentSuccessful::ID;

void messagePaymentSuccessful::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaymentSuccessful");
    s.store_field("invoice_chat_id", invoice_chat_id_);
    s.store_field("invoice_message_id", invoice_message_id_);
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("subscription_until_date", subscription_until_date_);
    s.store_field("is_recurring", is_recurring_);
    s.store_field("is_first_recurring", is_first_recurring_);
    s.store_field("invoice_name", invoice_name_);
    s.store_class_end();
  }
}

messagePaymentSuccessfulBot::messagePaymentSuccessfulBot()
  : currency_()
  , total_amount_()
  , subscription_until_date_()
  , is_recurring_()
  , is_first_recurring_()
  , invoice_payload_()
  , shipping_option_id_()
  , order_info_()
  , telegram_payment_charge_id_()
  , provider_payment_charge_id_()
{}

messagePaymentSuccessfulBot::messagePaymentSuccessfulBot(string const &currency_, int53 total_amount_, int32 subscription_until_date_, bool is_recurring_, bool is_first_recurring_, bytes const &invoice_payload_, string const &shipping_option_id_, object_ptr<orderInfo> &&order_info_, string const &telegram_payment_charge_id_, string const &provider_payment_charge_id_)
  : currency_(currency_)
  , total_amount_(total_amount_)
  , subscription_until_date_(subscription_until_date_)
  , is_recurring_(is_recurring_)
  , is_first_recurring_(is_first_recurring_)
  , invoice_payload_(std::move(invoice_payload_))
  , shipping_option_id_(shipping_option_id_)
  , order_info_(std::move(order_info_))
  , telegram_payment_charge_id_(telegram_payment_charge_id_)
  , provider_payment_charge_id_(provider_payment_charge_id_)
{}

const std::int32_t messagePaymentSuccessfulBot::ID;

void messagePaymentSuccessfulBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaymentSuccessfulBot");
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("subscription_until_date", subscription_until_date_);
    s.store_field("is_recurring", is_recurring_);
    s.store_field("is_first_recurring", is_first_recurring_);
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_field("shipping_option_id", shipping_option_id_);
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_field("telegram_payment_charge_id", telegram_payment_charge_id_);
    s.store_field("provider_payment_charge_id", provider_payment_charge_id_);
    s.store_class_end();
  }
}

messagePaymentRefunded::messagePaymentRefunded()
  : owner_id_()
  , currency_()
  , total_amount_()
  , invoice_payload_()
  , telegram_payment_charge_id_()
  , provider_payment_charge_id_()
{}

messagePaymentRefunded::messagePaymentRefunded(object_ptr<MessageSender> &&owner_id_, string const &currency_, int53 total_amount_, bytes const &invoice_payload_, string const &telegram_payment_charge_id_, string const &provider_payment_charge_id_)
  : owner_id_(std::move(owner_id_))
  , currency_(currency_)
  , total_amount_(total_amount_)
  , invoice_payload_(std::move(invoice_payload_))
  , telegram_payment_charge_id_(telegram_payment_charge_id_)
  , provider_payment_charge_id_(provider_payment_charge_id_)
{}

const std::int32_t messagePaymentRefunded::ID;

void messagePaymentRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaymentRefunded");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_field("telegram_payment_charge_id", telegram_payment_charge_id_);
    s.store_field("provider_payment_charge_id", provider_payment_charge_id_);
    s.store_class_end();
  }
}

messageGiftedPremium::messageGiftedPremium()
  : gifter_user_id_()
  , receiver_user_id_()
  , text_()
  , currency_()
  , amount_()
  , cryptocurrency_()
  , cryptocurrency_amount_()
  , month_count_()
  , day_count_()
  , sticker_()
{}

messageGiftedPremium::messageGiftedPremium(int53 gifter_user_id_, int53 receiver_user_id_, object_ptr<formattedText> &&text_, string const &currency_, int53 amount_, string const &cryptocurrency_, int64 cryptocurrency_amount_, int32 month_count_, int32 day_count_, object_ptr<sticker> &&sticker_)
  : gifter_user_id_(gifter_user_id_)
  , receiver_user_id_(receiver_user_id_)
  , text_(std::move(text_))
  , currency_(currency_)
  , amount_(amount_)
  , cryptocurrency_(cryptocurrency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , month_count_(month_count_)
  , day_count_(day_count_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t messageGiftedPremium::ID;

void messageGiftedPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiftedPremium");
    s.store_field("gifter_user_id", gifter_user_id_);
    s.store_field("receiver_user_id", receiver_user_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_field("month_count", month_count_);
    s.store_field("day_count", day_count_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messagePremiumGiftCode::messagePremiumGiftCode()
  : creator_id_()
  , text_()
  , is_from_giveaway_()
  , is_unclaimed_()
  , currency_()
  , amount_()
  , cryptocurrency_()
  , cryptocurrency_amount_()
  , month_count_()
  , day_count_()
  , sticker_()
  , code_()
{}

messagePremiumGiftCode::messagePremiumGiftCode(object_ptr<MessageSender> &&creator_id_, object_ptr<formattedText> &&text_, bool is_from_giveaway_, bool is_unclaimed_, string const &currency_, int53 amount_, string const &cryptocurrency_, int64 cryptocurrency_amount_, int32 month_count_, int32 day_count_, object_ptr<sticker> &&sticker_, string const &code_)
  : creator_id_(std::move(creator_id_))
  , text_(std::move(text_))
  , is_from_giveaway_(is_from_giveaway_)
  , is_unclaimed_(is_unclaimed_)
  , currency_(currency_)
  , amount_(amount_)
  , cryptocurrency_(cryptocurrency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , month_count_(month_count_)
  , day_count_(day_count_)
  , sticker_(std::move(sticker_))
  , code_(code_)
{}

const std::int32_t messagePremiumGiftCode::ID;

void messagePremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePremiumGiftCode");
    s.store_object_field("creator_id", static_cast<const BaseObject *>(creator_id_.get()));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_from_giveaway", is_from_giveaway_);
    s.store_field("is_unclaimed", is_unclaimed_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_field("month_count", month_count_);
    s.store_field("day_count", day_count_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("code", code_);
    s.store_class_end();
  }
}

messageGiveawayCreated::messageGiveawayCreated()
  : star_count_()
{}

messageGiveawayCreated::messageGiveawayCreated(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t messageGiveawayCreated::ID;

void messageGiveawayCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiveawayCreated");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

messageGiveaway::messageGiveaway()
  : parameters_()
  , winner_count_()
  , prize_()
  , sticker_()
{}

messageGiveaway::messageGiveaway(object_ptr<giveawayParameters> &&parameters_, int32 winner_count_, object_ptr<GiveawayPrize> &&prize_, object_ptr<sticker> &&sticker_)
  : parameters_(std::move(parameters_))
  , winner_count_(winner_count_)
  , prize_(std::move(prize_))
  , sticker_(std::move(sticker_))
{}

const std::int32_t messageGiveaway::ID;

void messageGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiveaway");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("winner_count", winner_count_);
    s.store_object_field("prize", static_cast<const BaseObject *>(prize_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messageGiveawayCompleted::messageGiveawayCompleted()
  : giveaway_message_id_()
  , winner_count_()
  , is_star_giveaway_()
  , unclaimed_prize_count_()
{}

messageGiveawayCompleted::messageGiveawayCompleted(int53 giveaway_message_id_, int32 winner_count_, bool is_star_giveaway_, int32 unclaimed_prize_count_)
  : giveaway_message_id_(giveaway_message_id_)
  , winner_count_(winner_count_)
  , is_star_giveaway_(is_star_giveaway_)
  , unclaimed_prize_count_(unclaimed_prize_count_)
{}

const std::int32_t messageGiveawayCompleted::ID;

void messageGiveawayCompleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiveawayCompleted");
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_field("winner_count", winner_count_);
    s.store_field("is_star_giveaway", is_star_giveaway_);
    s.store_field("unclaimed_prize_count", unclaimed_prize_count_);
    s.store_class_end();
  }
}

messageGiveawayWinners::messageGiveawayWinners()
  : boosted_chat_id_()
  , giveaway_message_id_()
  , additional_chat_count_()
  , actual_winners_selection_date_()
  , only_new_members_()
  , was_refunded_()
  , prize_()
  , prize_description_()
  , winner_count_()
  , winner_user_ids_()
  , unclaimed_prize_count_()
{}

messageGiveawayWinners::messageGiveawayWinners(int53 boosted_chat_id_, int53 giveaway_message_id_, int32 additional_chat_count_, int32 actual_winners_selection_date_, bool only_new_members_, bool was_refunded_, object_ptr<GiveawayPrize> &&prize_, string const &prize_description_, int32 winner_count_, array<int53> &&winner_user_ids_, int32 unclaimed_prize_count_)
  : boosted_chat_id_(boosted_chat_id_)
  , giveaway_message_id_(giveaway_message_id_)
  , additional_chat_count_(additional_chat_count_)
  , actual_winners_selection_date_(actual_winners_selection_date_)
  , only_new_members_(only_new_members_)
  , was_refunded_(was_refunded_)
  , prize_(std::move(prize_))
  , prize_description_(prize_description_)
  , winner_count_(winner_count_)
  , winner_user_ids_(std::move(winner_user_ids_))
  , unclaimed_prize_count_(unclaimed_prize_count_)
{}

const std::int32_t messageGiveawayWinners::ID;

void messageGiveawayWinners::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiveawayWinners");
    s.store_field("boosted_chat_id", boosted_chat_id_);
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_field("additional_chat_count", additional_chat_count_);
    s.store_field("actual_winners_selection_date", actual_winners_selection_date_);
    s.store_field("only_new_members", only_new_members_);
    s.store_field("was_refunded", was_refunded_);
    s.store_object_field("prize", static_cast<const BaseObject *>(prize_.get()));
    s.store_field("prize_description", prize_description_);
    s.store_field("winner_count", winner_count_);
    { s.store_vector_begin("winner_user_ids", winner_user_ids_.size()); for (const auto &_value : winner_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("unclaimed_prize_count", unclaimed_prize_count_);
    s.store_class_end();
  }
}

messageGiftedStars::messageGiftedStars()
  : gifter_user_id_()
  , receiver_user_id_()
  , currency_()
  , amount_()
  , cryptocurrency_()
  , cryptocurrency_amount_()
  , star_count_()
  , transaction_id_()
  , sticker_()
{}

messageGiftedStars::messageGiftedStars(int53 gifter_user_id_, int53 receiver_user_id_, string const &currency_, int53 amount_, string const &cryptocurrency_, int64 cryptocurrency_amount_, int53 star_count_, string const &transaction_id_, object_ptr<sticker> &&sticker_)
  : gifter_user_id_(gifter_user_id_)
  , receiver_user_id_(receiver_user_id_)
  , currency_(currency_)
  , amount_(amount_)
  , cryptocurrency_(cryptocurrency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , star_count_(star_count_)
  , transaction_id_(transaction_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t messageGiftedStars::ID;

void messageGiftedStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiftedStars");
    s.store_field("gifter_user_id", gifter_user_id_);
    s.store_field("receiver_user_id", receiver_user_id_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_field("star_count", star_count_);
    s.store_field("transaction_id", transaction_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messageGiftedGrams::messageGiftedGrams()
  : gifter_user_id_()
  , receiver_user_id_()
  , gram_amount_()
  , transaction_id_()
  , sticker_()
{}

messageGiftedGrams::messageGiftedGrams(int53 gifter_user_id_, int53 receiver_user_id_, int53 gram_amount_, string const &transaction_id_, object_ptr<sticker> &&sticker_)
  : gifter_user_id_(gifter_user_id_)
  , receiver_user_id_(receiver_user_id_)
  , gram_amount_(gram_amount_)
  , transaction_id_(transaction_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t messageGiftedGrams::ID;

void messageGiftedGrams::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiftedGrams");
    s.store_field("gifter_user_id", gifter_user_id_);
    s.store_field("receiver_user_id", receiver_user_id_);
    s.store_field("gram_amount", gram_amount_);
    s.store_field("transaction_id", transaction_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messageGiveawayPrizeStars::messageGiveawayPrizeStars()
  : star_count_()
  , transaction_id_()
  , boosted_chat_id_()
  , giveaway_message_id_()
  , is_unclaimed_()
  , sticker_()
{}

messageGiveawayPrizeStars::messageGiveawayPrizeStars(int53 star_count_, string const &transaction_id_, int53 boosted_chat_id_, int53 giveaway_message_id_, bool is_unclaimed_, object_ptr<sticker> &&sticker_)
  : star_count_(star_count_)
  , transaction_id_(transaction_id_)
  , boosted_chat_id_(boosted_chat_id_)
  , giveaway_message_id_(giveaway_message_id_)
  , is_unclaimed_(is_unclaimed_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t messageGiveawayPrizeStars::ID;

void messageGiveawayPrizeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiveawayPrizeStars");
    s.store_field("star_count", star_count_);
    s.store_field("transaction_id", transaction_id_);
    s.store_field("boosted_chat_id", boosted_chat_id_);
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_field("is_unclaimed", is_unclaimed_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messageTonWalletTransfer::messageTonWalletTransfer()
  : sender_user_id_()
  , transaction_id_()
  , peer_address_()
  , amount_()
  , comment_()
  , is_comment_encrypted_()
  , on_ramp_provider_name_()
{}

messageTonWalletTransfer::messageTonWalletTransfer(int53 sender_user_id_, string const &transaction_id_, string const &peer_address_, int64 amount_, string const &comment_, bool is_comment_encrypted_, string const &on_ramp_provider_name_)
  : sender_user_id_(sender_user_id_)
  , transaction_id_(transaction_id_)
  , peer_address_(peer_address_)
  , amount_(amount_)
  , comment_(comment_)
  , is_comment_encrypted_(is_comment_encrypted_)
  , on_ramp_provider_name_(on_ramp_provider_name_)
{}

const std::int32_t messageTonWalletTransfer::ID;

void messageTonWalletTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageTonWalletTransfer");
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("transaction_id", transaction_id_);
    s.store_field("peer_address", peer_address_);
    s.store_field("amount", amount_);
    s.store_field("comment", comment_);
    s.store_field("is_comment_encrypted", is_comment_encrypted_);
    s.store_field("on_ramp_provider_name", on_ramp_provider_name_);
    s.store_class_end();
  }
}

messageTonConnectRequest::messageTonConnectRequest()
  : session_id_()
  , state_()
  , dapp_name_()
  , topic_()
  , trace_id_()
{}

messageTonConnectRequest::messageTonConnectRequest(int64 session_id_, object_ptr<TonConnectRequestState> &&state_, string const &dapp_name_, string const &topic_, string const &trace_id_)
  : session_id_(session_id_)
  , state_(std::move(state_))
  , dapp_name_(dapp_name_)
  , topic_(topic_)
  , trace_id_(trace_id_)
{}

const std::int32_t messageTonConnectRequest::ID;

void messageTonConnectRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageTonConnectRequest");
    s.store_field("session_id", session_id_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_field("dapp_name", dapp_name_);
    s.store_field("topic", topic_);
    s.store_field("trace_id", trace_id_);
    s.store_class_end();
  }
}

messageGift::messageGift()
  : gift_()
  , sender_id_()
  , receiver_id_()
  , received_gift_id_()
  , text_()
  , unique_gift_number_()
  , sell_star_count_()
  , prepaid_upgrade_star_count_()
  , is_upgrade_separate_()
  , is_from_auction_()
  , is_private_()
  , is_saved_()
  , is_prepaid_upgrade_()
  , can_be_upgraded_()
  , can_be_deleted_()
  , was_converted_()
  , was_upgraded_()
  , was_refunded_()
  , upgraded_received_gift_id_()
  , prepaid_upgrade_hash_()
{}

messageGift::messageGift(object_ptr<gift> &&gift_, object_ptr<MessageSender> &&sender_id_, object_ptr<MessageSender> &&receiver_id_, string const &received_gift_id_, object_ptr<formattedText> &&text_, int32 unique_gift_number_, int53 sell_star_count_, int53 prepaid_upgrade_star_count_, bool is_upgrade_separate_, bool is_from_auction_, bool is_private_, bool is_saved_, bool is_prepaid_upgrade_, bool can_be_upgraded_, bool can_be_deleted_, bool was_converted_, bool was_upgraded_, bool was_refunded_, string const &upgraded_received_gift_id_, string const &prepaid_upgrade_hash_)
  : gift_(std::move(gift_))
  , sender_id_(std::move(sender_id_))
  , receiver_id_(std::move(receiver_id_))
  , received_gift_id_(received_gift_id_)
  , text_(std::move(text_))
  , unique_gift_number_(unique_gift_number_)
  , sell_star_count_(sell_star_count_)
  , prepaid_upgrade_star_count_(prepaid_upgrade_star_count_)
  , is_upgrade_separate_(is_upgrade_separate_)
  , is_from_auction_(is_from_auction_)
  , is_private_(is_private_)
  , is_saved_(is_saved_)
  , is_prepaid_upgrade_(is_prepaid_upgrade_)
  , can_be_upgraded_(can_be_upgraded_)
  , can_be_deleted_(can_be_deleted_)
  , was_converted_(was_converted_)
  , was_upgraded_(was_upgraded_)
  , was_refunded_(was_refunded_)
  , upgraded_received_gift_id_(upgraded_received_gift_id_)
  , prepaid_upgrade_hash_(prepaid_upgrade_hash_)
{}

const std::int32_t messageGift::ID;

void messageGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_field("received_gift_id", received_gift_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("unique_gift_number", unique_gift_number_);
    s.store_field("sell_star_count", sell_star_count_);
    s.store_field("prepaid_upgrade_star_count", prepaid_upgrade_star_count_);
    s.store_field("is_upgrade_separate", is_upgrade_separate_);
    s.store_field("is_from_auction", is_from_auction_);
    s.store_field("is_private", is_private_);
    s.store_field("is_saved", is_saved_);
    s.store_field("is_prepaid_upgrade", is_prepaid_upgrade_);
    s.store_field("can_be_upgraded", can_be_upgraded_);
    s.store_field("can_be_deleted", can_be_deleted_);
    s.store_field("was_converted", was_converted_);
    s.store_field("was_upgraded", was_upgraded_);
    s.store_field("was_refunded", was_refunded_);
    s.store_field("upgraded_received_gift_id", upgraded_received_gift_id_);
    s.store_field("prepaid_upgrade_hash", prepaid_upgrade_hash_);
    s.store_class_end();
  }
}

messageUpgradedGift::messageUpgradedGift()
  : gift_()
  , sender_id_()
  , receiver_id_()
  , origin_()
  , received_gift_id_()
  , text_()
  , is_private_()
  , is_saved_()
  , can_be_transferred_()
  , was_transferred_()
  , transfer_star_count_()
  , drop_original_details_star_count_()
  , next_transfer_date_()
  , next_resale_date_()
  , mint_date_()
  , craft_date_()
{}

messageUpgradedGift::messageUpgradedGift(object_ptr<upgradedGift> &&gift_, object_ptr<MessageSender> &&sender_id_, object_ptr<MessageSender> &&receiver_id_, object_ptr<UpgradedGiftOrigin> &&origin_, string const &received_gift_id_, object_ptr<formattedText> &&text_, bool is_private_, bool is_saved_, bool can_be_transferred_, bool was_transferred_, int53 transfer_star_count_, int53 drop_original_details_star_count_, int32 next_transfer_date_, int32 next_resale_date_, int32 mint_date_, int32 craft_date_)
  : gift_(std::move(gift_))
  , sender_id_(std::move(sender_id_))
  , receiver_id_(std::move(receiver_id_))
  , origin_(std::move(origin_))
  , received_gift_id_(received_gift_id_)
  , text_(std::move(text_))
  , is_private_(is_private_)
  , is_saved_(is_saved_)
  , can_be_transferred_(can_be_transferred_)
  , was_transferred_(was_transferred_)
  , transfer_star_count_(transfer_star_count_)
  , drop_original_details_star_count_(drop_original_details_star_count_)
  , next_transfer_date_(next_transfer_date_)
  , next_resale_date_(next_resale_date_)
  , mint_date_(mint_date_)
  , craft_date_(craft_date_)
{}

const std::int32_t messageUpgradedGift::ID;

void messageUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUpgradedGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_object_field("origin", static_cast<const BaseObject *>(origin_.get()));
    s.store_field("received_gift_id", received_gift_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_private", is_private_);
    s.store_field("is_saved", is_saved_);
    s.store_field("can_be_transferred", can_be_transferred_);
    s.store_field("was_transferred", was_transferred_);
    s.store_field("transfer_star_count", transfer_star_count_);
    s.store_field("drop_original_details_star_count", drop_original_details_star_count_);
    s.store_field("next_transfer_date", next_transfer_date_);
    s.store_field("next_resale_date", next_resale_date_);
    s.store_field("mint_date", mint_date_);
    s.store_field("craft_date", craft_date_);
    s.store_class_end();
  }
}

messageRefundedUpgradedGift::messageRefundedUpgradedGift()
  : gift_()
  , sender_id_()
  , receiver_id_()
  , origin_()
{}

messageRefundedUpgradedGift::messageRefundedUpgradedGift(object_ptr<gift> &&gift_, object_ptr<MessageSender> &&sender_id_, object_ptr<MessageSender> &&receiver_id_, object_ptr<UpgradedGiftOrigin> &&origin_)
  : gift_(std::move(gift_))
  , sender_id_(std::move(sender_id_))
  , receiver_id_(std::move(receiver_id_))
  , origin_(std::move(origin_))
{}

const std::int32_t messageRefundedUpgradedGift::ID;

void messageRefundedUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageRefundedUpgradedGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_object_field("origin", static_cast<const BaseObject *>(origin_.get()));
    s.store_class_end();
  }
}

messageUpgradedGiftPurchaseOffer::messageUpgradedGiftPurchaseOffer()
  : gift_()
  , state_()
  , price_()
  , expiration_date_()
{}

messageUpgradedGiftPurchaseOffer::messageUpgradedGiftPurchaseOffer(object_ptr<upgradedGift> &&gift_, object_ptr<GiftPurchaseOfferState> &&state_, object_ptr<GiftResalePrice> &&price_, int32 expiration_date_)
  : gift_(std::move(gift_))
  , state_(std::move(state_))
  , price_(std::move(price_))
  , expiration_date_(expiration_date_)
{}

const std::int32_t messageUpgradedGiftPurchaseOffer::ID;

void messageUpgradedGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUpgradedGiftPurchaseOffer");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("expiration_date", expiration_date_);
    s.store_class_end();
  }
}

messageUpgradedGiftPurchaseOfferRejected::messageUpgradedGiftPurchaseOfferRejected()
  : gift_()
  , price_()
  , offer_message_id_()
  , was_expired_()
{}

messageUpgradedGiftPurchaseOfferRejected::messageUpgradedGiftPurchaseOfferRejected(object_ptr<upgradedGift> &&gift_, object_ptr<GiftResalePrice> &&price_, int53 offer_message_id_, bool was_expired_)
  : gift_(std::move(gift_))
  , price_(std::move(price_))
  , offer_message_id_(offer_message_id_)
  , was_expired_(was_expired_)
{}

const std::int32_t messageUpgradedGiftPurchaseOfferRejected::ID;

void messageUpgradedGiftPurchaseOfferRejected::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUpgradedGiftPurchaseOfferRejected");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("offer_message_id", offer_message_id_);
    s.store_field("was_expired", was_expired_);
    s.store_class_end();
  }
}

messageUpgradedGiftOnChainPurchaseOffer::messageUpgradedGiftOnChainPurchaseOffer()
  : gift_()
  , is_buyer_()
  , state_()
  , offer_address_()
  , gram_amount_()
  , fee_basis_points_()
  , expiration_date_()
  , offer_message_id_()
{}

messageUpgradedGiftOnChainPurchaseOffer::messageUpgradedGiftOnChainPurchaseOffer(object_ptr<upgradedGift> &&gift_, bool is_buyer_, object_ptr<GiftOnChainPurchaseOfferState> &&state_, string const &offer_address_, int64 gram_amount_, int32 fee_basis_points_, int32 expiration_date_, int53 offer_message_id_)
  : gift_(std::move(gift_))
  , is_buyer_(is_buyer_)
  , state_(std::move(state_))
  , offer_address_(offer_address_)
  , gram_amount_(gram_amount_)
  , fee_basis_points_(fee_basis_points_)
  , expiration_date_(expiration_date_)
  , offer_message_id_(offer_message_id_)
{}

const std::int32_t messageUpgradedGiftOnChainPurchaseOffer::ID;

void messageUpgradedGiftOnChainPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUpgradedGiftOnChainPurchaseOffer");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("is_buyer", is_buyer_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_field("offer_address", offer_address_);
    s.store_field("gram_amount", gram_amount_);
    s.store_field("fee_basis_points", fee_basis_points_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("offer_message_id", offer_message_id_);
    s.store_class_end();
  }
}

messagePaidMessagesRefunded::messagePaidMessagesRefunded()
  : message_count_()
  , star_count_()
{}

messagePaidMessagesRefunded::messagePaidMessagesRefunded(int32 message_count_, int53 star_count_)
  : message_count_(message_count_)
  , star_count_(star_count_)
{}

const std::int32_t messagePaidMessagesRefunded::ID;

void messagePaidMessagesRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaidMessagesRefunded");
    s.store_field("message_count", message_count_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

messagePaidMessagePriceChanged::messagePaidMessagePriceChanged()
  : paid_message_star_count_()
{}

messagePaidMessagePriceChanged::messagePaidMessagePriceChanged(int53 paid_message_star_count_)
  : paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t messagePaidMessagePriceChanged::ID;

void messagePaidMessagePriceChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaidMessagePriceChanged");
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

messageDirectMessagePriceChanged::messageDirectMessagePriceChanged()
  : is_enabled_()
  , paid_message_star_count_()
{}

messageDirectMessagePriceChanged::messageDirectMessagePriceChanged(bool is_enabled_, int53 paid_message_star_count_)
  : is_enabled_(is_enabled_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t messageDirectMessagePriceChanged::ID;

void messageDirectMessagePriceChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageDirectMessagePriceChanged");
    s.store_field("is_enabled", is_enabled_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

messageUnpaidMessagesAllowedByLink::messageUnpaidMessagesAllowedByLink() {
}

const std::int32_t messageUnpaidMessagesAllowedByLink::ID;

void messageUnpaidMessagesAllowedByLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUnpaidMessagesAllowedByLink");
    s.store_class_end();
  }
}

messageChecklistTasksDone::messageChecklistTasksDone()
  : checklist_message_id_()
  , marked_as_done_task_ids_()
  , marked_as_not_done_task_ids_()
{}

messageChecklistTasksDone::messageChecklistTasksDone(int53 checklist_message_id_, array<int32> &&marked_as_done_task_ids_, array<int32> &&marked_as_not_done_task_ids_)
  : checklist_message_id_(checklist_message_id_)
  , marked_as_done_task_ids_(std::move(marked_as_done_task_ids_))
  , marked_as_not_done_task_ids_(std::move(marked_as_not_done_task_ids_))
{}

const std::int32_t messageChecklistTasksDone::ID;

void messageChecklistTasksDone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChecklistTasksDone");
    s.store_field("checklist_message_id", checklist_message_id_);
    { s.store_vector_begin("marked_as_done_task_ids", marked_as_done_task_ids_.size()); for (const auto &_value : marked_as_done_task_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("marked_as_not_done_task_ids", marked_as_not_done_task_ids_.size()); for (const auto &_value : marked_as_not_done_task_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageChecklistTasksAdded::messageChecklistTasksAdded()
  : checklist_message_id_()
  , tasks_()
{}

messageChecklistTasksAdded::messageChecklistTasksAdded(int53 checklist_message_id_, array<object_ptr<checklistTask>> &&tasks_)
  : checklist_message_id_(checklist_message_id_)
  , tasks_(std::move(tasks_))
{}

const std::int32_t messageChecklistTasksAdded::ID;

void messageChecklistTasksAdded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChecklistTasksAdded");
    s.store_field("checklist_message_id", checklist_message_id_);
    { s.store_vector_begin("tasks", tasks_.size()); for (const auto &_value : tasks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageSuggestedPostApprovalFailed::messageSuggestedPostApprovalFailed()
  : suggested_post_message_id_()
  , price_()
{}

messageSuggestedPostApprovalFailed::messageSuggestedPostApprovalFailed(int53 suggested_post_message_id_, object_ptr<SuggestedPostPrice> &&price_)
  : suggested_post_message_id_(suggested_post_message_id_)
  , price_(std::move(price_))
{}

const std::int32_t messageSuggestedPostApprovalFailed::ID;

void messageSuggestedPostApprovalFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestedPostApprovalFailed");
    s.store_field("suggested_post_message_id", suggested_post_message_id_);
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

messageSuggestedPostApproved::messageSuggestedPostApproved()
  : suggested_post_message_id_()
  , price_()
  , send_date_()
{}

messageSuggestedPostApproved::messageSuggestedPostApproved(int53 suggested_post_message_id_, object_ptr<SuggestedPostPrice> &&price_, int32 send_date_)
  : suggested_post_message_id_(suggested_post_message_id_)
  , price_(std::move(price_))
  , send_date_(send_date_)
{}

const std::int32_t messageSuggestedPostApproved::ID;

void messageSuggestedPostApproved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestedPostApproved");
    s.store_field("suggested_post_message_id", suggested_post_message_id_);
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("send_date", send_date_);
    s.store_class_end();
  }
}

messageSuggestedPostDeclined::messageSuggestedPostDeclined()
  : suggested_post_message_id_()
  , comment_()
{}

messageSuggestedPostDeclined::messageSuggestedPostDeclined(int53 suggested_post_message_id_, string const &comment_)
  : suggested_post_message_id_(suggested_post_message_id_)
  , comment_(comment_)
{}

const std::int32_t messageSuggestedPostDeclined::ID;

void messageSuggestedPostDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestedPostDeclined");
    s.store_field("suggested_post_message_id", suggested_post_message_id_);
    s.store_field("comment", comment_);
    s.store_class_end();
  }
}

messageSuggestedPostPaid::messageSuggestedPostPaid()
  : suggested_post_message_id_()
  , star_amount_()
  , gram_amount_()
{}

messageSuggestedPostPaid::messageSuggestedPostPaid(int53 suggested_post_message_id_, object_ptr<starAmount> &&star_amount_, int53 gram_amount_)
  : suggested_post_message_id_(suggested_post_message_id_)
  , star_amount_(std::move(star_amount_))
  , gram_amount_(gram_amount_)
{}

const std::int32_t messageSuggestedPostPaid::ID;

void messageSuggestedPostPaid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestedPostPaid");
    s.store_field("suggested_post_message_id", suggested_post_message_id_);
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    s.store_field("gram_amount", gram_amount_);
    s.store_class_end();
  }
}

messageSuggestedPostRefunded::messageSuggestedPostRefunded()
  : suggested_post_message_id_()
  , reason_()
{}

messageSuggestedPostRefunded::messageSuggestedPostRefunded(int53 suggested_post_message_id_, object_ptr<SuggestedPostRefundReason> &&reason_)
  : suggested_post_message_id_(suggested_post_message_id_)
  , reason_(std::move(reason_))
{}

const std::int32_t messageSuggestedPostRefunded::ID;

void messageSuggestedPostRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestedPostRefunded");
    s.store_field("suggested_post_message_id", suggested_post_message_id_);
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

messageContactRegistered::messageContactRegistered() {
}

const std::int32_t messageContactRegistered::ID;

void messageContactRegistered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageContactRegistered");
    s.store_class_end();
  }
}

messageUsersShared::messageUsersShared()
  : users_()
  , button_id_()
{}

messageUsersShared::messageUsersShared(array<object_ptr<sharedUser>> &&users_, int32 button_id_)
  : users_(std::move(users_))
  , button_id_(button_id_)
{}

const std::int32_t messageUsersShared::ID;

void messageUsersShared::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUsersShared");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("button_id", button_id_);
    s.store_class_end();
  }
}

messageChatShared::messageChatShared()
  : chat_()
  , button_id_()
{}

messageChatShared::messageChatShared(object_ptr<sharedChat> &&chat_, int32 button_id_)
  : chat_(std::move(chat_))
  , button_id_(button_id_)
{}

const std::int32_t messageChatShared::ID;

void messageChatShared::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatShared");
    s.store_object_field("chat", static_cast<const BaseObject *>(chat_.get()));
    s.store_field("button_id", button_id_);
    s.store_class_end();
  }
}

messageBotWriteAccessAllowed::messageBotWriteAccessAllowed()
  : reason_()
{}

messageBotWriteAccessAllowed::messageBotWriteAccessAllowed(object_ptr<BotWriteAccessAllowReason> &&reason_)
  : reason_(std::move(reason_))
{}

const std::int32_t messageBotWriteAccessAllowed::ID;

void messageBotWriteAccessAllowed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageBotWriteAccessAllowed");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

messageWebAppDataSent::messageWebAppDataSent()
  : button_text_()
{}

messageWebAppDataSent::messageWebAppDataSent(string const &button_text_)
  : button_text_(button_text_)
{}

const std::int32_t messageWebAppDataSent::ID;

void messageWebAppDataSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageWebAppDataSent");
    s.store_field("button_text", button_text_);
    s.store_class_end();
  }
}

messageWebAppDataReceived::messageWebAppDataReceived()
  : button_text_()
  , data_()
{}

messageWebAppDataReceived::messageWebAppDataReceived(string const &button_text_, string const &data_)
  : button_text_(button_text_)
  , data_(data_)
{}

const std::int32_t messageWebAppDataReceived::ID;

void messageWebAppDataReceived::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageWebAppDataReceived");
    s.store_field("button_text", button_text_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

messagePassportDataSent::messagePassportDataSent()
  : types_()
{}

messagePassportDataSent::messagePassportDataSent(array<object_ptr<PassportElementType>> &&types_)
  : types_(std::move(types_))
{}

const std::int32_t messagePassportDataSent::ID;

void messagePassportDataSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePassportDataSent");
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messagePassportDataReceived::messagePassportDataReceived()
  : elements_()
  , credentials_()
{}

messagePassportDataReceived::messagePassportDataReceived(array<object_ptr<encryptedPassportElement>> &&elements_, object_ptr<encryptedCredentials> &&credentials_)
  : elements_(std::move(elements_))
  , credentials_(std::move(credentials_))
{}

const std::int32_t messagePassportDataReceived::ID;

void messagePassportDataReceived::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePassportDataReceived");
    { s.store_vector_begin("elements", elements_.size()); for (const auto &_value : elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    s.store_class_end();
  }
}

messageProximityAlertTriggered::messageProximityAlertTriggered()
  : traveler_id_()
  , watcher_id_()
  , distance_()
{}

messageProximityAlertTriggered::messageProximityAlertTriggered(object_ptr<MessageSender> &&traveler_id_, object_ptr<MessageSender> &&watcher_id_, int32 distance_)
  : traveler_id_(std::move(traveler_id_))
  , watcher_id_(std::move(watcher_id_))
  , distance_(distance_)
{}

const std::int32_t messageProximityAlertTriggered::ID;

void messageProximityAlertTriggered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageProximityAlertTriggered");
    s.store_object_field("traveler_id", static_cast<const BaseObject *>(traveler_id_.get()));
    s.store_object_field("watcher_id", static_cast<const BaseObject *>(watcher_id_.get()));
    s.store_field("distance", distance_);
    s.store_class_end();
  }
}

messageUnsupported::messageUnsupported() {
}

const std::int32_t messageUnsupported::ID;

void messageUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUnsupported");
    s.store_class_end();
  }
}

messageForwardInfo::messageForwardInfo()
  : origin_()
  , date_()
  , source_()
  , public_service_announcement_type_()
{}

messageForwardInfo::messageForwardInfo(object_ptr<MessageOrigin> &&origin_, int32 date_, object_ptr<forwardSource> &&source_, string const &public_service_announcement_type_)
  : origin_(std::move(origin_))
  , date_(date_)
  , source_(std::move(source_))
  , public_service_announcement_type_(public_service_announcement_type_)
{}

const std::int32_t messageForwardInfo::ID;

void messageForwardInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForwardInfo");
    s.store_object_field("origin", static_cast<const BaseObject *>(origin_.get()));
    s.store_field("date", date_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("public_service_announcement_type", public_service_announcement_type_);
    s.store_class_end();
  }
}

messageImportInfo::messageImportInfo()
  : sender_name_()
  , date_()
{}

messageImportInfo::messageImportInfo(string const &sender_name_, int32 date_)
  : sender_name_(sender_name_)
  , date_(date_)
{}

const std::int32_t messageImportInfo::ID;

void messageImportInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageImportInfo");
    s.store_field("sender_name", sender_name_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

messageLinkInfo::messageLinkInfo()
  : is_public_()
  , chat_id_()
  , topic_id_()
  , message_()
  , media_timestamp_()
  , checklist_task_id_()
  , poll_option_id_()
  , for_album_()
{}

messageLinkInfo::messageLinkInfo(bool is_public_, int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<message> &&message_, int32 media_timestamp_, int32 checklist_task_id_, string const &poll_option_id_, bool for_album_)
  : is_public_(is_public_)
  , chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , message_(std::move(message_))
  , media_timestamp_(media_timestamp_)
  , checklist_task_id_(checklist_task_id_)
  , poll_option_id_(poll_option_id_)
  , for_album_(for_album_)
{}

const std::int32_t messageLinkInfo::ID;

void messageLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageLinkInfo");
    s.store_field("is_public", is_public_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("media_timestamp", media_timestamp_);
    s.store_field("checklist_task_id", checklist_task_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_field("for_album", for_album_);
    s.store_class_end();
  }
}

messageSenderUser::messageSenderUser()
  : user_id_()
{}

messageSenderUser::messageSenderUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t messageSenderUser::ID;

void messageSenderUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSenderUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

messageSenderChat::messageSenderChat()
  : chat_id_()
{}

messageSenderChat::messageSenderChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t messageSenderChat::ID;

void messageSenderChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSenderChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

messageSendingStatePending::messageSendingStatePending()
  : sending_id_()
{}

messageSendingStatePending::messageSendingStatePending(int32 sending_id_)
  : sending_id_(sending_id_)
{}

const std::int32_t messageSendingStatePending::ID;

void messageSendingStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSendingStatePending");
    s.store_field("sending_id", sending_id_);
    s.store_class_end();
  }
}

messageSendingStateFailed::messageSendingStateFailed()
  : error_()
  , can_retry_()
  , need_another_sender_()
  , need_another_reply_quote_()
  , need_drop_reply_()
  , required_paid_message_star_count_()
  , retry_after_()
{}

messageSendingStateFailed::messageSendingStateFailed(object_ptr<error> &&error_, bool can_retry_, bool need_another_sender_, bool need_another_reply_quote_, bool need_drop_reply_, int53 required_paid_message_star_count_, double retry_after_)
  : error_(std::move(error_))
  , can_retry_(can_retry_)
  , need_another_sender_(need_another_sender_)
  , need_another_reply_quote_(need_another_reply_quote_)
  , need_drop_reply_(need_drop_reply_)
  , required_paid_message_star_count_(required_paid_message_star_count_)
  , retry_after_(retry_after_)
{}

const std::int32_t messageSendingStateFailed::ID;

void messageSendingStateFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSendingStateFailed");
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_field("can_retry", can_retry_);
    s.store_field("need_another_sender", need_another_sender_);
    s.store_field("need_another_reply_quote", need_another_reply_quote_);
    s.store_field("need_drop_reply", need_drop_reply_);
    s.store_field("required_paid_message_star_count", required_paid_message_star_count_);
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

messageTopicThread::messageTopicThread()
  : message_thread_id_()
{}

messageTopicThread::messageTopicThread(int53 message_thread_id_)
  : message_thread_id_(message_thread_id_)
{}

const std::int32_t messageTopicThread::ID;

void messageTopicThread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageTopicThread");
    s.store_field("message_thread_id", message_thread_id_);
    s.store_class_end();
  }
}

messageTopicForum::messageTopicForum()
  : forum_topic_id_()
{}

messageTopicForum::messageTopicForum(int32 forum_topic_id_)
  : forum_topic_id_(forum_topic_id_)
{}

const std::int32_t messageTopicForum::ID;

void messageTopicForum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageTopicForum");
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

messageTopicDirectMessages::messageTopicDirectMessages()
  : direct_messages_chat_topic_id_()
{}

messageTopicDirectMessages::messageTopicDirectMessages(int53 direct_messages_chat_topic_id_)
  : direct_messages_chat_topic_id_(direct_messages_chat_topic_id_)
{}

const std::int32_t messageTopicDirectMessages::ID;

void messageTopicDirectMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageTopicDirectMessages");
    s.store_field("direct_messages_chat_topic_id", direct_messages_chat_topic_id_);
    s.store_class_end();
  }
}

messageTopicSavedMessages::messageTopicSavedMessages()
  : saved_messages_topic_id_()
{}

messageTopicSavedMessages::messageTopicSavedMessages(int53 saved_messages_topic_id_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
{}

const std::int32_t messageTopicSavedMessages::ID;

void messageTopicSavedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageTopicSavedMessages");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_class_end();
  }
}

notificationSettingsScopePrivateChats::notificationSettingsScopePrivateChats() {
}

const std::int32_t notificationSettingsScopePrivateChats::ID;

void notificationSettingsScopePrivateChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSettingsScopePrivateChats");
    s.store_class_end();
  }
}

notificationSettingsScopeGroupChats::notificationSettingsScopeGroupChats() {
}

const std::int32_t notificationSettingsScopeGroupChats::ID;

void notificationSettingsScopeGroupChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSettingsScopeGroupChats");
    s.store_class_end();
  }
}

notificationSettingsScopeChannelChats::notificationSettingsScopeChannelChats() {
}

const std::int32_t notificationSettingsScopeChannelChats::ID;

void notificationSettingsScopeChannelChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSettingsScopeChannelChats");
    s.store_class_end();
  }
}

orderInfo::orderInfo()
  : name_()
  , phone_number_()
  , email_address_()
  , shipping_address_()
{}

orderInfo::orderInfo(string const &name_, string const &phone_number_, string const &email_address_, object_ptr<address> &&shipping_address_)
  : name_(name_)
  , phone_number_(phone_number_)
  , email_address_(email_address_)
  , shipping_address_(std::move(shipping_address_))
{}

const std::int32_t orderInfo::ID;

void orderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "orderInfo");
    s.store_field("name", name_);
    s.store_field("phone_number", phone_number_);
    s.store_field("email_address", email_address_);
    s.store_object_field("shipping_address", static_cast<const BaseObject *>(shipping_address_.get()));
    s.store_class_end();
  }
}

paymentResult::paymentResult()
  : success_()
  , verification_url_()
{}

paymentResult::paymentResult(bool success_, string const &verification_url_)
  : success_(success_)
  , verification_url_(verification_url_)
{}

const std::int32_t paymentResult::ID;

void paymentResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentResult");
    s.store_field("success", success_);
    s.store_field("verification_url", verification_url_);
    s.store_class_end();
  }
}

personalDocument::personalDocument()
  : files_()
  , translation_()
{}

personalDocument::personalDocument(array<object_ptr<datedFile>> &&files_, array<object_ptr<datedFile>> &&translation_)
  : files_(std::move(files_))
  , translation_(std::move(translation_))
{}

const std::int32_t personalDocument::ID;

void personalDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "personalDocument");
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

premiumGiftPaymentOption::premiumGiftPaymentOption()
  : currency_()
  , amount_()
  , star_count_()
  , discount_percentage_()
  , month_count_()
  , store_product_id_()
  , sticker_()
{}

premiumGiftPaymentOption::premiumGiftPaymentOption(string const &currency_, int53 amount_, int53 star_count_, int32 discount_percentage_, int32 month_count_, string const &store_product_id_, object_ptr<sticker> &&sticker_)
  : currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
  , discount_percentage_(discount_percentage_)
  , month_count_(month_count_)
  , store_product_id_(store_product_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t premiumGiftPaymentOption::ID;

void premiumGiftPaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiftPaymentOption");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_field("discount_percentage", discount_percentage_);
    s.store_field("month_count", month_count_);
    s.store_field("store_product_id", store_product_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

premiumStatePaymentOption::premiumStatePaymentOption()
  : payment_option_()
  , is_current_()
  , is_upgrade_()
  , last_transaction_id_()
{}

premiumStatePaymentOption::premiumStatePaymentOption(object_ptr<premiumPaymentOption> &&payment_option_, bool is_current_, bool is_upgrade_, string const &last_transaction_id_)
  : payment_option_(std::move(payment_option_))
  , is_current_(is_current_)
  , is_upgrade_(is_upgrade_)
  , last_transaction_id_(last_transaction_id_)
{}

const std::int32_t premiumStatePaymentOption::ID;

void premiumStatePaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStatePaymentOption");
    s.store_object_field("payment_option", static_cast<const BaseObject *>(payment_option_.get()));
    s.store_field("is_current", is_current_);
    s.store_field("is_upgrade", is_upgrade_);
    s.store_field("last_transaction_id", last_transaction_id_);
    s.store_class_end();
  }
}

productInfo::productInfo()
  : title_()
  , description_()
  , photo_()
{}

productInfo::productInfo(string const &title_, object_ptr<formattedText> &&description_, object_ptr<photo> &&photo_)
  : title_(title_)
  , description_(std::move(description_))
  , photo_(std::move(photo_))
{}

const std::int32_t productInfo::ID;

void productInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "productInfo");
    s.store_field("title", title_);
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

profilePhoto::profilePhoto()
  : id_()
  , small_()
  , big_()
  , minithumbnail_()
  , has_animation_()
  , is_personal_()
{}

profilePhoto::profilePhoto(int64 id_, object_ptr<file> &&small_, object_ptr<file> &&big_, object_ptr<minithumbnail> &&minithumbnail_, bool has_animation_, bool is_personal_)
  : id_(id_)
  , small_(std::move(small_))
  , big_(std::move(big_))
  , minithumbnail_(std::move(minithumbnail_))
  , has_animation_(has_animation_)
  , is_personal_(is_personal_)
{}

const std::int32_t profilePhoto::ID;

void profilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profilePhoto");
    s.store_field("id", id_);
    s.store_object_field("small", static_cast<const BaseObject *>(small_.get()));
    s.store_object_field("big", static_cast<const BaseObject *>(big_.get()));
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_field("has_animation", has_animation_);
    s.store_field("is_personal", is_personal_);
    s.store_class_end();
  }
}

publicForwardMessage::publicForwardMessage()
  : message_()
{}

publicForwardMessage::publicForwardMessage(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t publicForwardMessage::ID;

void publicForwardMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicForwardMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

publicForwardStory::publicForwardStory()
  : story_()
{}

publicForwardStory::publicForwardStory(object_ptr<story> &&story_)
  : story_(std::move(story_))
{}

const std::int32_t publicForwardStory::ID;

void publicForwardStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicForwardStory");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

publicPostSearchLimits::publicPostSearchLimits()
  : daily_free_query_count_()
  , remaining_free_query_count_()
  , next_free_query_in_()
  , star_count_()
  , is_current_query_free_()
{}

publicPostSearchLimits::publicPostSearchLimits(int32 daily_free_query_count_, int32 remaining_free_query_count_, int32 next_free_query_in_, int53 star_count_, bool is_current_query_free_)
  : daily_free_query_count_(daily_free_query_count_)
  , remaining_free_query_count_(remaining_free_query_count_)
  , next_free_query_in_(next_free_query_in_)
  , star_count_(star_count_)
  , is_current_query_free_(is_current_query_free_)
{}

const std::int32_t publicPostSearchLimits::ID;

void publicPostSearchLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicPostSearchLimits");
    s.store_field("daily_free_query_count", daily_free_query_count_);
    s.store_field("remaining_free_query_count", remaining_free_query_count_);
    s.store_field("next_free_query_in", next_free_query_in_);
    s.store_field("star_count", star_count_);
    s.store_field("is_current_query_free", is_current_query_free_);
    s.store_class_end();
  }
}

receivedGifts::receivedGifts()
  : total_count_()
  , gifts_()
  , are_notifications_enabled_()
  , next_offset_()
{}

receivedGifts::receivedGifts(int32 total_count_, array<object_ptr<receivedGift>> &&gifts_, bool are_notifications_enabled_, string const &next_offset_)
  : total_count_(total_count_)
  , gifts_(std::move(gifts_))
  , are_notifications_enabled_(are_notifications_enabled_)
  , next_offset_(next_offset_)
{}

const std::int32_t receivedGifts::ID;

void receivedGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "receivedGifts");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("are_notifications_enabled", are_notifications_enabled_);
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

remoteFile::remoteFile()
  : id_()
  , unique_id_()
  , is_uploading_active_()
  , is_uploading_completed_()
  , uploaded_size_()
{}

remoteFile::remoteFile(string const &id_, string const &unique_id_, bool is_uploading_active_, bool is_uploading_completed_, int53 uploaded_size_)
  : id_(id_)
  , unique_id_(unique_id_)
  , is_uploading_active_(is_uploading_active_)
  , is_uploading_completed_(is_uploading_completed_)
  , uploaded_size_(uploaded_size_)
{}

const std::int32_t remoteFile::ID;

void remoteFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "remoteFile");
    s.store_field("id", id_);
    s.store_field("unique_id", unique_id_);
    s.store_field("is_uploading_active", is_uploading_active_);
    s.store_field("is_uploading_completed", is_uploading_completed_);
    s.store_field("uploaded_size", uploaded_size_);
    s.store_class_end();
  }
}

richMessage::richMessage()
  : blocks_()
  , is_rtl_()
  , is_full_()
{}

richMessage::richMessage(array<object_ptr<PageBlock>> &&blocks_, bool is_rtl_, bool is_full_)
  : blocks_(std::move(blocks_))
  , is_rtl_(is_rtl_)
  , is_full_(is_full_)
{}

const std::int32_t richMessage::ID;

void richMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richMessage");
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_rtl", is_rtl_);
    s.store_field("is_full", is_full_);
    s.store_class_end();
  }
}

richMessageSourceBlocks::richMessageSourceBlocks()
  : blocks_()
{}

richMessageSourceBlocks::richMessageSourceBlocks(array<object_ptr<InputPageBlock>> &&blocks_)
  : blocks_(std::move(blocks_))
{}

const std::int32_t richMessageSourceBlocks::ID;

void richMessageSourceBlocks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richMessageSourceBlocks");
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

richMessageSourceMarkdown::richMessageSourceMarkdown()
  : text_()
  , media_()
{}

richMessageSourceMarkdown::richMessageSourceMarkdown(string const &text_, array<object_ptr<inputRichMessageMedia>> &&media_)
  : text_(text_)
  , media_(std::move(media_))
{}

const std::int32_t richMessageSourceMarkdown::ID;

void richMessageSourceMarkdown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richMessageSourceMarkdown");
    s.store_field("text", text_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

richMessageSourceHtml::richMessageSourceHtml()
  : text_()
  , media_()
{}

richMessageSourceHtml::richMessageSourceHtml(string const &text_, array<object_ptr<inputRichMessageMedia>> &&media_)
  : text_(text_)
  , media_(std::move(media_))
{}

const std::int32_t richMessageSourceHtml::ID;

void richMessageSourceHtml::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richMessageSourceHtml");
    s.store_field("text", text_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sessionDeviceTypeAndroid::sessionDeviceTypeAndroid() {
}

const std::int32_t sessionDeviceTypeAndroid::ID;

void sessionDeviceTypeAndroid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeAndroid");
    s.store_class_end();
  }
}

sessionDeviceTypeApple::sessionDeviceTypeApple() {
}

const std::int32_t sessionDeviceTypeApple::ID;

void sessionDeviceTypeApple::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeApple");
    s.store_class_end();
  }
}

sessionDeviceTypeBrave::sessionDeviceTypeBrave() {
}

const std::int32_t sessionDeviceTypeBrave::ID;

void sessionDeviceTypeBrave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeBrave");
    s.store_class_end();
  }
}

sessionDeviceTypeChrome::sessionDeviceTypeChrome() {
}

const std::int32_t sessionDeviceTypeChrome::ID;

void sessionDeviceTypeChrome::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeChrome");
    s.store_class_end();
  }
}

sessionDeviceTypeEdge::sessionDeviceTypeEdge() {
}

const std::int32_t sessionDeviceTypeEdge::ID;

void sessionDeviceTypeEdge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeEdge");
    s.store_class_end();
  }
}

sessionDeviceTypeFirefox::sessionDeviceTypeFirefox() {
}

const std::int32_t sessionDeviceTypeFirefox::ID;

void sessionDeviceTypeFirefox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeFirefox");
    s.store_class_end();
  }
}

sessionDeviceTypeIpad::sessionDeviceTypeIpad() {
}

const std::int32_t sessionDeviceTypeIpad::ID;

void sessionDeviceTypeIpad::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeIpad");
    s.store_class_end();
  }
}

sessionDeviceTypeIphone::sessionDeviceTypeIphone() {
}

const std::int32_t sessionDeviceTypeIphone::ID;

void sessionDeviceTypeIphone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeIphone");
    s.store_class_end();
  }
}

sessionDeviceTypeLinux::sessionDeviceTypeLinux() {
}

const std::int32_t sessionDeviceTypeLinux::ID;

void sessionDeviceTypeLinux::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeLinux");
    s.store_class_end();
  }
}

sessionDeviceTypeMac::sessionDeviceTypeMac() {
}

const std::int32_t sessionDeviceTypeMac::ID;

void sessionDeviceTypeMac::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeMac");
    s.store_class_end();
  }
}

sessionDeviceTypeOpera::sessionDeviceTypeOpera() {
}

const std::int32_t sessionDeviceTypeOpera::ID;

void sessionDeviceTypeOpera::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeOpera");
    s.store_class_end();
  }
}

sessionDeviceTypeSafari::sessionDeviceTypeSafari() {
}

const std::int32_t sessionDeviceTypeSafari::ID;

void sessionDeviceTypeSafari::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeSafari");
    s.store_class_end();
  }
}

sessionDeviceTypeUbuntu::sessionDeviceTypeUbuntu() {
}

const std::int32_t sessionDeviceTypeUbuntu::ID;

void sessionDeviceTypeUbuntu::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeUbuntu");
    s.store_class_end();
  }
}

sessionDeviceTypeUnknown::sessionDeviceTypeUnknown() {
}

const std::int32_t sessionDeviceTypeUnknown::ID;

void sessionDeviceTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeUnknown");
    s.store_class_end();
  }
}

sessionDeviceTypeVivaldi::sessionDeviceTypeVivaldi() {
}

const std::int32_t sessionDeviceTypeVivaldi::ID;

void sessionDeviceTypeVivaldi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeVivaldi");
    s.store_class_end();
  }
}

sessionDeviceTypeWindows::sessionDeviceTypeWindows() {
}

const std::int32_t sessionDeviceTypeWindows::ID;

void sessionDeviceTypeWindows::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeWindows");
    s.store_class_end();
  }
}

sessionDeviceTypeXbox::sessionDeviceTypeXbox() {
}

const std::int32_t sessionDeviceTypeXbox::ID;

void sessionDeviceTypeXbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionDeviceTypeXbox");
    s.store_class_end();
  }
}

shippingOption::shippingOption()
  : id_()
  , title_()
  , price_parts_()
{}

shippingOption::shippingOption(string const &id_, string const &title_, array<object_ptr<labeledPricePart>> &&price_parts_)
  : id_(id_)
  , title_(title_)
  , price_parts_(std::move(price_parts_))
{}

const std::int32_t shippingOption::ID;

void shippingOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shippingOption");
    s.store_field("id", id_);
    s.store_field("title", title_);
    { s.store_vector_begin("price_parts", price_parts_.size()); for (const auto &_value : price_parts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

speechRecognitionLanguages::speechRecognitionLanguages()
  : language_codes_()
{}

speechRecognitionLanguages::speechRecognitionLanguages(array<string> &&language_codes_)
  : language_codes_(std::move(language_codes_))
{}

const std::int32_t speechRecognitionLanguages::ID;

void speechRecognitionLanguages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "speechRecognitionLanguages");
    { s.store_vector_begin("language_codes", language_codes_.size()); for (const auto &_value : language_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

starGiveawayPaymentOptions::starGiveawayPaymentOptions()
  : options_()
{}

starGiveawayPaymentOptions::starGiveawayPaymentOptions(array<object_ptr<starGiveawayPaymentOption>> &&options_)
  : options_(std::move(options_))
{}

const std::int32_t starGiveawayPaymentOptions::ID;

void starGiveawayPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiveawayPaymentOptions");
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starTransactionTypePremiumBotDeposit::starTransactionTypePremiumBotDeposit() {
}

const std::int32_t starTransactionTypePremiumBotDeposit::ID;

void starTransactionTypePremiumBotDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePremiumBotDeposit");
    s.store_class_end();
  }
}

starTransactionTypeAppStoreDeposit::starTransactionTypeAppStoreDeposit() {
}

const std::int32_t starTransactionTypeAppStoreDeposit::ID;

void starTransactionTypeAppStoreDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeAppStoreDeposit");
    s.store_class_end();
  }
}

starTransactionTypeGooglePlayDeposit::starTransactionTypeGooglePlayDeposit() {
}

const std::int32_t starTransactionTypeGooglePlayDeposit::ID;

void starTransactionTypeGooglePlayDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGooglePlayDeposit");
    s.store_class_end();
  }
}

starTransactionTypeFragmentDeposit::starTransactionTypeFragmentDeposit() {
}

const std::int32_t starTransactionTypeFragmentDeposit::ID;

void starTransactionTypeFragmentDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeFragmentDeposit");
    s.store_class_end();
  }
}

starTransactionTypeUserDeposit::starTransactionTypeUserDeposit()
  : user_id_()
  , sticker_()
{}

starTransactionTypeUserDeposit::starTransactionTypeUserDeposit(int53 user_id_, object_ptr<sticker> &&sticker_)
  : user_id_(user_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t starTransactionTypeUserDeposit::ID;

void starTransactionTypeUserDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeUserDeposit");
    s.store_field("user_id", user_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiveawayDeposit::starTransactionTypeGiveawayDeposit()
  : chat_id_()
  , giveaway_message_id_()
{}

starTransactionTypeGiveawayDeposit::starTransactionTypeGiveawayDeposit(int53 chat_id_, int53 giveaway_message_id_)
  : chat_id_(chat_id_)
  , giveaway_message_id_(giveaway_message_id_)
{}

const std::int32_t starTransactionTypeGiveawayDeposit::ID;

void starTransactionTypeGiveawayDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiveawayDeposit");
    s.store_field("chat_id", chat_id_);
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_class_end();
  }
}

starTransactionTypeFragmentWithdrawal::starTransactionTypeFragmentWithdrawal()
  : withdrawal_state_()
{}

starTransactionTypeFragmentWithdrawal::starTransactionTypeFragmentWithdrawal(object_ptr<RevenueWithdrawalState> &&withdrawal_state_)
  : withdrawal_state_(std::move(withdrawal_state_))
{}

const std::int32_t starTransactionTypeFragmentWithdrawal::ID;

void starTransactionTypeFragmentWithdrawal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeFragmentWithdrawal");
    s.store_object_field("withdrawal_state", static_cast<const BaseObject *>(withdrawal_state_.get()));
    s.store_class_end();
  }
}

starTransactionTypeTelegramAdsWithdrawal::starTransactionTypeTelegramAdsWithdrawal() {
}

const std::int32_t starTransactionTypeTelegramAdsWithdrawal::ID;

void starTransactionTypeTelegramAdsWithdrawal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeTelegramAdsWithdrawal");
    s.store_class_end();
  }
}

starTransactionTypeTelegramApiUsage::starTransactionTypeTelegramApiUsage()
  : request_count_()
{}

starTransactionTypeTelegramApiUsage::starTransactionTypeTelegramApiUsage(int32 request_count_)
  : request_count_(request_count_)
{}

const std::int32_t starTransactionTypeTelegramApiUsage::ID;

void starTransactionTypeTelegramApiUsage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeTelegramApiUsage");
    s.store_field("request_count", request_count_);
    s.store_class_end();
  }
}

starTransactionTypeBotPaidMediaPurchase::starTransactionTypeBotPaidMediaPurchase()
  : user_id_()
  , media_()
{}

starTransactionTypeBotPaidMediaPurchase::starTransactionTypeBotPaidMediaPurchase(int53 user_id_, array<object_ptr<PaidMedia>> &&media_)
  : user_id_(user_id_)
  , media_(std::move(media_))
{}

const std::int32_t starTransactionTypeBotPaidMediaPurchase::ID;

void starTransactionTypeBotPaidMediaPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotPaidMediaPurchase");
    s.store_field("user_id", user_id_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starTransactionTypeBotPaidMediaSale::starTransactionTypeBotPaidMediaSale()
  : user_id_()
  , media_()
  , payload_()
  , affiliate_()
{}

starTransactionTypeBotPaidMediaSale::starTransactionTypeBotPaidMediaSale(int53 user_id_, array<object_ptr<PaidMedia>> &&media_, string const &payload_, object_ptr<affiliateInfo> &&affiliate_)
  : user_id_(user_id_)
  , media_(std::move(media_))
  , payload_(payload_)
  , affiliate_(std::move(affiliate_))
{}

const std::int32_t starTransactionTypeBotPaidMediaSale::ID;

void starTransactionTypeBotPaidMediaSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotPaidMediaSale");
    s.store_field("user_id", user_id_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("payload", payload_);
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_class_end();
  }
}

starTransactionTypeChannelPaidMediaPurchase::starTransactionTypeChannelPaidMediaPurchase()
  : chat_id_()
  , message_id_()
  , media_()
{}

starTransactionTypeChannelPaidMediaPurchase::starTransactionTypeChannelPaidMediaPurchase(int53 chat_id_, int53 message_id_, array<object_ptr<PaidMedia>> &&media_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , media_(std::move(media_))
{}

const std::int32_t starTransactionTypeChannelPaidMediaPurchase::ID;

void starTransactionTypeChannelPaidMediaPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelPaidMediaPurchase");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starTransactionTypeChannelPaidMediaSale::starTransactionTypeChannelPaidMediaSale()
  : user_id_()
  , message_id_()
  , media_()
{}

starTransactionTypeChannelPaidMediaSale::starTransactionTypeChannelPaidMediaSale(int53 user_id_, int53 message_id_, array<object_ptr<PaidMedia>> &&media_)
  : user_id_(user_id_)
  , message_id_(message_id_)
  , media_(std::move(media_))
{}

const std::int32_t starTransactionTypeChannelPaidMediaSale::ID;

void starTransactionTypeChannelPaidMediaSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelPaidMediaSale");
    s.store_field("user_id", user_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starTransactionTypeBotInvoicePurchase::starTransactionTypeBotInvoicePurchase()
  : user_id_()
  , product_info_()
{}

starTransactionTypeBotInvoicePurchase::starTransactionTypeBotInvoicePurchase(int53 user_id_, object_ptr<productInfo> &&product_info_)
  : user_id_(user_id_)
  , product_info_(std::move(product_info_))
{}

const std::int32_t starTransactionTypeBotInvoicePurchase::ID;

void starTransactionTypeBotInvoicePurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotInvoicePurchase");
    s.store_field("user_id", user_id_);
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_class_end();
  }
}

starTransactionTypeBotInvoiceSale::starTransactionTypeBotInvoiceSale()
  : user_id_()
  , product_info_()
  , invoice_payload_()
  , affiliate_()
{}

starTransactionTypeBotInvoiceSale::starTransactionTypeBotInvoiceSale(int53 user_id_, object_ptr<productInfo> &&product_info_, bytes const &invoice_payload_, object_ptr<affiliateInfo> &&affiliate_)
  : user_id_(user_id_)
  , product_info_(std::move(product_info_))
  , invoice_payload_(std::move(invoice_payload_))
  , affiliate_(std::move(affiliate_))
{}

const std::int32_t starTransactionTypeBotInvoiceSale::ID;

void starTransactionTypeBotInvoiceSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotInvoiceSale");
    s.store_field("user_id", user_id_);
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_class_end();
  }
}

starTransactionTypeBotSubscriptionPurchase::starTransactionTypeBotSubscriptionPurchase()
  : user_id_()
  , subscription_period_()
  , product_info_()
{}

starTransactionTypeBotSubscriptionPurchase::starTransactionTypeBotSubscriptionPurchase(int53 user_id_, int32 subscription_period_, object_ptr<productInfo> &&product_info_)
  : user_id_(user_id_)
  , subscription_period_(subscription_period_)
  , product_info_(std::move(product_info_))
{}

const std::int32_t starTransactionTypeBotSubscriptionPurchase::ID;

void starTransactionTypeBotSubscriptionPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotSubscriptionPurchase");
    s.store_field("user_id", user_id_);
    s.store_field("subscription_period", subscription_period_);
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_class_end();
  }
}

starTransactionTypeBotSubscriptionSale::starTransactionTypeBotSubscriptionSale()
  : user_id_()
  , subscription_period_()
  , product_info_()
  , invoice_payload_()
  , affiliate_()
{}

starTransactionTypeBotSubscriptionSale::starTransactionTypeBotSubscriptionSale(int53 user_id_, int32 subscription_period_, object_ptr<productInfo> &&product_info_, bytes const &invoice_payload_, object_ptr<affiliateInfo> &&affiliate_)
  : user_id_(user_id_)
  , subscription_period_(subscription_period_)
  , product_info_(std::move(product_info_))
  , invoice_payload_(std::move(invoice_payload_))
  , affiliate_(std::move(affiliate_))
{}

const std::int32_t starTransactionTypeBotSubscriptionSale::ID;

void starTransactionTypeBotSubscriptionSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotSubscriptionSale");
    s.store_field("user_id", user_id_);
    s.store_field("subscription_period", subscription_period_);
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_class_end();
  }
}

starTransactionTypeChannelSubscriptionPurchase::starTransactionTypeChannelSubscriptionPurchase()
  : chat_id_()
  , subscription_period_()
{}

starTransactionTypeChannelSubscriptionPurchase::starTransactionTypeChannelSubscriptionPurchase(int53 chat_id_, int32 subscription_period_)
  : chat_id_(chat_id_)
  , subscription_period_(subscription_period_)
{}

const std::int32_t starTransactionTypeChannelSubscriptionPurchase::ID;

void starTransactionTypeChannelSubscriptionPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelSubscriptionPurchase");
    s.store_field("chat_id", chat_id_);
    s.store_field("subscription_period", subscription_period_);
    s.store_class_end();
  }
}

starTransactionTypeChannelSubscriptionSale::starTransactionTypeChannelSubscriptionSale()
  : user_id_()
  , subscription_period_()
{}

starTransactionTypeChannelSubscriptionSale::starTransactionTypeChannelSubscriptionSale(int53 user_id_, int32 subscription_period_)
  : user_id_(user_id_)
  , subscription_period_(subscription_period_)
{}

const std::int32_t starTransactionTypeChannelSubscriptionSale::ID;

void starTransactionTypeChannelSubscriptionSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelSubscriptionSale");
    s.store_field("user_id", user_id_);
    s.store_field("subscription_period", subscription_period_);
    s.store_class_end();
  }
}

starTransactionTypeGiftAuctionBid::starTransactionTypeGiftAuctionBid()
  : owner_id_()
  , gift_()
{}

starTransactionTypeGiftAuctionBid::starTransactionTypeGiftAuctionBid(object_ptr<MessageSender> &&owner_id_, object_ptr<gift> &&gift_)
  : owner_id_(std::move(owner_id_))
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftAuctionBid::ID;

void starTransactionTypeGiftAuctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftAuctionBid");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftPurchase::starTransactionTypeGiftPurchase()
  : owner_id_()
  , gift_()
{}

starTransactionTypeGiftPurchase::starTransactionTypeGiftPurchase(object_ptr<MessageSender> &&owner_id_, object_ptr<gift> &&gift_)
  : owner_id_(std::move(owner_id_))
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftPurchase::ID;

void starTransactionTypeGiftPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftPurchase");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftPurchaseOffer::starTransactionTypeGiftPurchaseOffer()
  : gift_()
{}

starTransactionTypeGiftPurchaseOffer::starTransactionTypeGiftPurchaseOffer(object_ptr<upgradedGift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftPurchaseOffer::ID;

void starTransactionTypeGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftPurchaseOffer");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftTransfer::starTransactionTypeGiftTransfer()
  : owner_id_()
  , gift_()
{}

starTransactionTypeGiftTransfer::starTransactionTypeGiftTransfer(object_ptr<MessageSender> &&owner_id_, object_ptr<upgradedGift> &&gift_)
  : owner_id_(std::move(owner_id_))
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftTransfer::ID;

void starTransactionTypeGiftTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftTransfer");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftOriginalDetailsDrop::starTransactionTypeGiftOriginalDetailsDrop()
  : owner_id_()
  , gift_()
{}

starTransactionTypeGiftOriginalDetailsDrop::starTransactionTypeGiftOriginalDetailsDrop(object_ptr<MessageSender> &&owner_id_, object_ptr<upgradedGift> &&gift_)
  : owner_id_(std::move(owner_id_))
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftOriginalDetailsDrop::ID;

void starTransactionTypeGiftOriginalDetailsDrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftOriginalDetailsDrop");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftSale::starTransactionTypeGiftSale()
  : user_id_()
  , gift_()
{}

starTransactionTypeGiftSale::starTransactionTypeGiftSale(int53 user_id_, object_ptr<gift> &&gift_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftSale::ID;

void starTransactionTypeGiftSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftSale");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftUpgrade::starTransactionTypeGiftUpgrade()
  : user_id_()
  , gift_()
{}

starTransactionTypeGiftUpgrade::starTransactionTypeGiftUpgrade(int53 user_id_, object_ptr<upgradedGift> &&gift_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftUpgrade::ID;

void starTransactionTypeGiftUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftUpgrade");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftUpgradePurchase::starTransactionTypeGiftUpgradePurchase()
  : owner_id_()
  , gift_()
{}

starTransactionTypeGiftUpgradePurchase::starTransactionTypeGiftUpgradePurchase(object_ptr<MessageSender> &&owner_id_, object_ptr<gift> &&gift_)
  : owner_id_(std::move(owner_id_))
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftUpgradePurchase::ID;

void starTransactionTypeGiftUpgradePurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftUpgradePurchase");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeUpgradedGiftPurchase::starTransactionTypeUpgradedGiftPurchase()
  : user_id_()
  , gift_()
{}

starTransactionTypeUpgradedGiftPurchase::starTransactionTypeUpgradedGiftPurchase(int53 user_id_, object_ptr<upgradedGift> &&gift_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeUpgradedGiftPurchase::ID;

void starTransactionTypeUpgradedGiftPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeUpgradedGiftPurchase");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeUpgradedGiftSale::starTransactionTypeUpgradedGiftSale()
  : user_id_()
  , gift_()
  , commission_per_mille_()
  , commission_star_amount_()
  , via_offer_()
{}

starTransactionTypeUpgradedGiftSale::starTransactionTypeUpgradedGiftSale(int53 user_id_, object_ptr<upgradedGift> &&gift_, int32 commission_per_mille_, object_ptr<starAmount> &&commission_star_amount_, bool via_offer_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
  , commission_per_mille_(commission_per_mille_)
  , commission_star_amount_(std::move(commission_star_amount_))
  , via_offer_(via_offer_)
{}

const std::int32_t starTransactionTypeUpgradedGiftSale::ID;

void starTransactionTypeUpgradedGiftSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeUpgradedGiftSale");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_object_field("commission_star_amount", static_cast<const BaseObject *>(commission_star_amount_.get()));
    s.store_field("via_offer", via_offer_);
    s.store_class_end();
  }
}

starTransactionTypeChannelPaidReactionSend::starTransactionTypeChannelPaidReactionSend()
  : chat_id_()
  , message_id_()
{}

starTransactionTypeChannelPaidReactionSend::starTransactionTypeChannelPaidReactionSend(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t starTransactionTypeChannelPaidReactionSend::ID;

void starTransactionTypeChannelPaidReactionSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelPaidReactionSend");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

starTransactionTypeChannelPaidReactionReceive::starTransactionTypeChannelPaidReactionReceive()
  : user_id_()
  , message_id_()
{}

starTransactionTypeChannelPaidReactionReceive::starTransactionTypeChannelPaidReactionReceive(int53 user_id_, int53 message_id_)
  : user_id_(user_id_)
  , message_id_(message_id_)
{}

const std::int32_t starTransactionTypeChannelPaidReactionReceive::ID;

void starTransactionTypeChannelPaidReactionReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelPaidReactionReceive");
    s.store_field("user_id", user_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

starTransactionTypeAffiliateProgramCommission::starTransactionTypeAffiliateProgramCommission()
  : chat_id_()
  , commission_per_mille_()
{}

starTransactionTypeAffiliateProgramCommission::starTransactionTypeAffiliateProgramCommission(int53 chat_id_, int32 commission_per_mille_)
  : chat_id_(chat_id_)
  , commission_per_mille_(commission_per_mille_)
{}

const std::int32_t starTransactionTypeAffiliateProgramCommission::ID;

void starTransactionTypeAffiliateProgramCommission::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeAffiliateProgramCommission");
    s.store_field("chat_id", chat_id_);
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_class_end();
  }
}

starTransactionTypePaidMessageSend::starTransactionTypePaidMessageSend()
  : chat_id_()
  , message_count_()
{}

starTransactionTypePaidMessageSend::starTransactionTypePaidMessageSend(int53 chat_id_, int32 message_count_)
  : chat_id_(chat_id_)
  , message_count_(message_count_)
{}

const std::int32_t starTransactionTypePaidMessageSend::ID;

void starTransactionTypePaidMessageSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidMessageSend");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_count", message_count_);
    s.store_class_end();
  }
}

starTransactionTypePaidMessageReceive::starTransactionTypePaidMessageReceive()
  : sender_id_()
  , message_count_()
  , commission_per_mille_()
  , commission_star_amount_()
{}

starTransactionTypePaidMessageReceive::starTransactionTypePaidMessageReceive(object_ptr<MessageSender> &&sender_id_, int32 message_count_, int32 commission_per_mille_, object_ptr<starAmount> &&commission_star_amount_)
  : sender_id_(std::move(sender_id_))
  , message_count_(message_count_)
  , commission_per_mille_(commission_per_mille_)
  , commission_star_amount_(std::move(commission_star_amount_))
{}

const std::int32_t starTransactionTypePaidMessageReceive::ID;

void starTransactionTypePaidMessageReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidMessageReceive");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("message_count", message_count_);
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_object_field("commission_star_amount", static_cast<const BaseObject *>(commission_star_amount_.get()));
    s.store_class_end();
  }
}

starTransactionTypePaidGroupCallMessageSend::starTransactionTypePaidGroupCallMessageSend()
  : chat_id_()
{}

starTransactionTypePaidGroupCallMessageSend::starTransactionTypePaidGroupCallMessageSend(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t starTransactionTypePaidGroupCallMessageSend::ID;

void starTransactionTypePaidGroupCallMessageSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidGroupCallMessageSend");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

starTransactionTypePaidGroupCallMessageReceive::starTransactionTypePaidGroupCallMessageReceive()
  : sender_id_()
  , commission_per_mille_()
  , commission_star_amount_()
{}

starTransactionTypePaidGroupCallMessageReceive::starTransactionTypePaidGroupCallMessageReceive(object_ptr<MessageSender> &&sender_id_, int32 commission_per_mille_, object_ptr<starAmount> &&commission_star_amount_)
  : sender_id_(std::move(sender_id_))
  , commission_per_mille_(commission_per_mille_)
  , commission_star_amount_(std::move(commission_star_amount_))
{}

const std::int32_t starTransactionTypePaidGroupCallMessageReceive::ID;

void starTransactionTypePaidGroupCallMessageReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidGroupCallMessageReceive");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_object_field("commission_star_amount", static_cast<const BaseObject *>(commission_star_amount_.get()));
    s.store_class_end();
  }
}

starTransactionTypePaidGroupCallReactionSend::starTransactionTypePaidGroupCallReactionSend()
  : chat_id_()
{}

starTransactionTypePaidGroupCallReactionSend::starTransactionTypePaidGroupCallReactionSend(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t starTransactionTypePaidGroupCallReactionSend::ID;

void starTransactionTypePaidGroupCallReactionSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidGroupCallReactionSend");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

starTransactionTypePaidGroupCallReactionReceive::starTransactionTypePaidGroupCallReactionReceive()
  : sender_id_()
  , commission_per_mille_()
  , commission_star_amount_()
{}

starTransactionTypePaidGroupCallReactionReceive::starTransactionTypePaidGroupCallReactionReceive(object_ptr<MessageSender> &&sender_id_, int32 commission_per_mille_, object_ptr<starAmount> &&commission_star_amount_)
  : sender_id_(std::move(sender_id_))
  , commission_per_mille_(commission_per_mille_)
  , commission_star_amount_(std::move(commission_star_amount_))
{}

const std::int32_t starTransactionTypePaidGroupCallReactionReceive::ID;

void starTransactionTypePaidGroupCallReactionReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidGroupCallReactionReceive");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_object_field("commission_star_amount", static_cast<const BaseObject *>(commission_star_amount_.get()));
    s.store_class_end();
  }
}

starTransactionTypeSuggestedPostPaymentSend::starTransactionTypeSuggestedPostPaymentSend()
  : chat_id_()
{}

starTransactionTypeSuggestedPostPaymentSend::starTransactionTypeSuggestedPostPaymentSend(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t starTransactionTypeSuggestedPostPaymentSend::ID;

void starTransactionTypeSuggestedPostPaymentSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeSuggestedPostPaymentSend");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

starTransactionTypeSuggestedPostPaymentReceive::starTransactionTypeSuggestedPostPaymentReceive()
  : user_id_()
{}

starTransactionTypeSuggestedPostPaymentReceive::starTransactionTypeSuggestedPostPaymentReceive(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t starTransactionTypeSuggestedPostPaymentReceive::ID;

void starTransactionTypeSuggestedPostPaymentReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeSuggestedPostPaymentReceive");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

starTransactionTypePremiumPurchase::starTransactionTypePremiumPurchase()
  : user_id_()
  , month_count_()
  , sticker_()
{}

starTransactionTypePremiumPurchase::starTransactionTypePremiumPurchase(int53 user_id_, int32 month_count_, object_ptr<sticker> &&sticker_)
  : user_id_(user_id_)
  , month_count_(month_count_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t starTransactionTypePremiumPurchase::ID;

void starTransactionTypePremiumPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePremiumPurchase");
    s.store_field("user_id", user_id_);
    s.store_field("month_count", month_count_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

starTransactionTypeBusinessBotTransferSend::starTransactionTypeBusinessBotTransferSend()
  : user_id_()
{}

starTransactionTypeBusinessBotTransferSend::starTransactionTypeBusinessBotTransferSend(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t starTransactionTypeBusinessBotTransferSend::ID;

void starTransactionTypeBusinessBotTransferSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBusinessBotTransferSend");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

starTransactionTypeBusinessBotTransferReceive::starTransactionTypeBusinessBotTransferReceive()
  : user_id_()
{}

starTransactionTypeBusinessBotTransferReceive::starTransactionTypeBusinessBotTransferReceive(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t starTransactionTypeBusinessBotTransferReceive::ID;

void starTransactionTypeBusinessBotTransferReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBusinessBotTransferReceive");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

starTransactionTypePublicPostSearch::starTransactionTypePublicPostSearch() {
}

const std::int32_t starTransactionTypePublicPostSearch::ID;

void starTransactionTypePublicPostSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePublicPostSearch");
    s.store_class_end();
  }
}

starTransactionTypeUnsupported::starTransactionTypeUnsupported() {
}

const std::int32_t starTransactionTypeUnsupported::ID;

void starTransactionTypeUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeUnsupported");
    s.store_class_end();
  }
}

storyPrivacySettingsEveryone::storyPrivacySettingsEveryone()
  : except_user_ids_()
{}

storyPrivacySettingsEveryone::storyPrivacySettingsEveryone(array<int53> &&except_user_ids_)
  : except_user_ids_(std::move(except_user_ids_))
{}

const std::int32_t storyPrivacySettingsEveryone::ID;

void storyPrivacySettingsEveryone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyPrivacySettingsEveryone");
    { s.store_vector_begin("except_user_ids", except_user_ids_.size()); for (const auto &_value : except_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyPrivacySettingsContacts::storyPrivacySettingsContacts()
  : except_user_ids_()
{}

storyPrivacySettingsContacts::storyPrivacySettingsContacts(array<int53> &&except_user_ids_)
  : except_user_ids_(std::move(except_user_ids_))
{}

const std::int32_t storyPrivacySettingsContacts::ID;

void storyPrivacySettingsContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyPrivacySettingsContacts");
    { s.store_vector_begin("except_user_ids", except_user_ids_.size()); for (const auto &_value : except_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyPrivacySettingsCloseFriends::storyPrivacySettingsCloseFriends() {
}

const std::int32_t storyPrivacySettingsCloseFriends::ID;

void storyPrivacySettingsCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyPrivacySettingsCloseFriends");
    s.store_class_end();
  }
}

storyPrivacySettingsSelectedUsers::storyPrivacySettingsSelectedUsers()
  : user_ids_()
{}

storyPrivacySettingsSelectedUsers::storyPrivacySettingsSelectedUsers(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t storyPrivacySettingsSelectedUsers::ID;

void storyPrivacySettingsSelectedUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyPrivacySettingsSelectedUsers");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

suggestedPostRefundReasonPostDeleted::suggestedPostRefundReasonPostDeleted() {
}

const std::int32_t suggestedPostRefundReasonPostDeleted::ID;

void suggestedPostRefundReasonPostDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostRefundReasonPostDeleted");
    s.store_class_end();
  }
}

suggestedPostRefundReasonPaymentRefunded::suggestedPostRefundReasonPaymentRefunded() {
}

const std::int32_t suggestedPostRefundReasonPaymentRefunded::ID;

void suggestedPostRefundReasonPaymentRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostRefundReasonPaymentRefunded");
    s.store_class_end();
  }
}

suggestedPostStatePending::suggestedPostStatePending() {
}

const std::int32_t suggestedPostStatePending::ID;

void suggestedPostStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostStatePending");
    s.store_class_end();
  }
}

suggestedPostStateApproved::suggestedPostStateApproved() {
}

const std::int32_t suggestedPostStateApproved::ID;

void suggestedPostStateApproved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostStateApproved");
    s.store_class_end();
  }
}

suggestedPostStateDeclined::suggestedPostStateDeclined() {
}

const std::int32_t suggestedPostStateDeclined::ID;

void suggestedPostStateDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostStateDeclined");
    s.store_class_end();
  }
}

targetChatTypes::targetChatTypes()
  : allow_user_chats_()
  , allow_bot_chats_()
  , allow_group_chats_()
  , allow_channel_chats_()
{}

targetChatTypes::targetChatTypes(bool allow_user_chats_, bool allow_bot_chats_, bool allow_group_chats_, bool allow_channel_chats_)
  : allow_user_chats_(allow_user_chats_)
  , allow_bot_chats_(allow_bot_chats_)
  , allow_group_chats_(allow_group_chats_)
  , allow_channel_chats_(allow_channel_chats_)
{}

const std::int32_t targetChatTypes::ID;

void targetChatTypes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "targetChatTypes");
    s.store_field("allow_user_chats", allow_user_chats_);
    s.store_field("allow_bot_chats", allow_bot_chats_);
    s.store_field("allow_group_chats", allow_group_chats_);
    s.store_field("allow_channel_chats", allow_channel_chats_);
    s.store_class_end();
  }
}

textParseModeMarkdown::textParseModeMarkdown()
  : version_()
{}

textParseModeMarkdown::textParseModeMarkdown(int32 version_)
  : version_(version_)
{}

const std::int32_t textParseModeMarkdown::ID;

void textParseModeMarkdown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textParseModeMarkdown");
    s.store_field("version", version_);
    s.store_class_end();
  }
}

textParseModeHTML::textParseModeHTML() {
}

const std::int32_t textParseModeHTML::ID;

void textParseModeHTML::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textParseModeHTML");
    s.store_class_end();
  }
}

themeParameters::themeParameters()
  : background_color_()
  , secondary_background_color_()
  , header_background_color_()
  , bottom_bar_background_color_()
  , section_background_color_()
  , section_separator_color_()
  , text_color_()
  , accent_text_color_()
  , section_header_text_color_()
  , subtitle_text_color_()
  , destructive_text_color_()
  , hint_color_()
  , link_color_()
  , button_color_()
  , button_text_color_()
{}

themeParameters::themeParameters(int32 background_color_, int32 secondary_background_color_, int32 header_background_color_, int32 bottom_bar_background_color_, int32 section_background_color_, int32 section_separator_color_, int32 text_color_, int32 accent_text_color_, int32 section_header_text_color_, int32 subtitle_text_color_, int32 destructive_text_color_, int32 hint_color_, int32 link_color_, int32 button_color_, int32 button_text_color_)
  : background_color_(background_color_)
  , secondary_background_color_(secondary_background_color_)
  , header_background_color_(header_background_color_)
  , bottom_bar_background_color_(bottom_bar_background_color_)
  , section_background_color_(section_background_color_)
  , section_separator_color_(section_separator_color_)
  , text_color_(text_color_)
  , accent_text_color_(accent_text_color_)
  , section_header_text_color_(section_header_text_color_)
  , subtitle_text_color_(subtitle_text_color_)
  , destructive_text_color_(destructive_text_color_)
  , hint_color_(hint_color_)
  , link_color_(link_color_)
  , button_color_(button_color_)
  , button_text_color_(button_text_color_)
{}

const std::int32_t themeParameters::ID;

void themeParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "themeParameters");
    s.store_field("background_color", background_color_);
    s.store_field("secondary_background_color", secondary_background_color_);
    s.store_field("header_background_color", header_background_color_);
    s.store_field("bottom_bar_background_color", bottom_bar_background_color_);
    s.store_field("section_background_color", section_background_color_);
    s.store_field("section_separator_color", section_separator_color_);
    s.store_field("text_color", text_color_);
    s.store_field("accent_text_color", accent_text_color_);
    s.store_field("section_header_text_color", section_header_text_color_);
    s.store_field("subtitle_text_color", subtitle_text_color_);
    s.store_field("destructive_text_color", destructive_text_color_);
    s.store_field("hint_color", hint_color_);
    s.store_field("link_color", link_color_);
    s.store_field("button_color", button_color_);
    s.store_field("button_text_color", button_text_color_);
    s.store_class_end();
  }
}

thumbnail::thumbnail()
  : format_()
  , width_()
  , height_()
  , file_()
{}

thumbnail::thumbnail(object_ptr<ThumbnailFormat> &&format_, int32 width_, int32 height_, object_ptr<file> &&file_)
  : format_(std::move(format_))
  , width_(width_)
  , height_(height_)
  , file_(std::move(file_))
{}

const std::int32_t thumbnail::ID;

void thumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnail");
    s.store_object_field("format", static_cast<const BaseObject *>(format_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

tonWalletCard::tonWalletCard()
  : address_()
  , gram_amount_()
  , stickers_()
  , background_nft_address_()
{}

tonWalletCard::tonWalletCard(string const &address_, int64 gram_amount_, array<object_ptr<tonWalletCardSticker>> &&stickers_, string const &background_nft_address_)
  : address_(address_)
  , gram_amount_(gram_amount_)
  , stickers_(std::move(stickers_))
  , background_nft_address_(background_nft_address_)
{}

const std::int32_t tonWalletCard::ID;

void tonWalletCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletCard");
    s.store_field("address", address_);
    s.store_field("gram_amount", gram_amount_);
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("background_nft_address", background_nft_address_);
    s.store_class_end();
  }
}

tonWalletCardSticker::tonWalletCardSticker()
  : position_()
  , nft_()
{}

tonWalletCardSticker::tonWalletCardSticker(object_ptr<areaPosition> &&position_, object_ptr<tonNft> &&nft_)
  : position_(std::move(position_))
  , nft_(std::move(nft_))
{}

const std::int32_t tonWalletCardSticker::ID;

void tonWalletCardSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletCardSticker");
    s.store_object_field("position", static_cast<const BaseObject *>(position_.get()));
    s.store_object_field("nft", static_cast<const BaseObject *>(nft_.get()));
    s.store_class_end();
  }
}

tonWalletTransactions::tonWalletTransactions()
  : gram_amount_()
  , transactions_()
  , next_offset_()
{}

tonWalletTransactions::tonWalletTransactions(int64 gram_amount_, array<object_ptr<tonWalletTransaction>> &&transactions_, string const &next_offset_)
  : gram_amount_(gram_amount_)
  , transactions_(std::move(transactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t tonWalletTransactions::ID;

void tonWalletTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransactions");
    s.store_field("gram_amount", gram_amount_);
    { s.store_vector_begin("transactions", transactions_.size()); for (const auto &_value : transactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

updates::updates()
  : updates_()
{}

updates::updates(array<object_ptr<Update>> &&updates_)
  : updates_(std::move(updates_))
{}

const std::int32_t updates::ID;

void updates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates");
    { s.store_vector_begin("updates", updates_.size()); for (const auto &_value : updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

upgradeGiftResult::upgradeGiftResult()
  : gift_()
  , received_gift_id_()
  , is_saved_()
  , can_be_transferred_()
  , transfer_star_count_()
  , drop_original_details_star_count_()
  , next_transfer_date_()
  , next_resale_date_()
  , mint_date_()
{}

upgradeGiftResult::upgradeGiftResult(object_ptr<upgradedGift> &&gift_, string const &received_gift_id_, bool is_saved_, bool can_be_transferred_, int53 transfer_star_count_, int53 drop_original_details_star_count_, int32 next_transfer_date_, int32 next_resale_date_, int32 mint_date_)
  : gift_(std::move(gift_))
  , received_gift_id_(received_gift_id_)
  , is_saved_(is_saved_)
  , can_be_transferred_(can_be_transferred_)
  , transfer_star_count_(transfer_star_count_)
  , drop_original_details_star_count_(drop_original_details_star_count_)
  , next_transfer_date_(next_transfer_date_)
  , next_resale_date_(next_resale_date_)
  , mint_date_(mint_date_)
{}

const std::int32_t upgradeGiftResult::ID;

void upgradeGiftResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradeGiftResult");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("received_gift_id", received_gift_id_);
    s.store_field("is_saved", is_saved_);
    s.store_field("can_be_transferred", can_be_transferred_);
    s.store_field("transfer_star_count", transfer_star_count_);
    s.store_field("drop_original_details_star_count", drop_original_details_star_count_);
    s.store_field("next_transfer_date", next_transfer_date_);
    s.store_field("next_resale_date", next_resale_date_);
    s.store_field("mint_date", mint_date_);
    s.store_class_end();
  }
}

user::user()
  : id_()
  , first_name_()
  , last_name_()
  , usernames_()
  , phone_number_()
  , status_()
  , profile_photo_()
  , accent_color_id_()
  , background_custom_emoji_id_()
  , upgraded_gift_colors_()
  , profile_accent_color_id_()
  , profile_background_custom_emoji_id_()
  , emoji_status_()
  , is_contact_()
  , is_mutual_contact_()
  , is_close_friend_()
  , verification_status_()
  , is_premium_()
  , is_support_()
  , restriction_info_()
  , active_story_state_()
  , restricts_new_chats_()
  , paid_message_star_count_()
  , have_access_()
  , type_()
  , language_code_()
  , added_to_attachment_menu_()
{}

user::user(int53 id_, string const &first_name_, string const &last_name_, object_ptr<usernames> &&usernames_, string const &phone_number_, object_ptr<UserStatus> &&status_, object_ptr<profilePhoto> &&profile_photo_, int32 accent_color_id_, int64 background_custom_emoji_id_, object_ptr<upgradedGiftColors> &&upgraded_gift_colors_, int32 profile_accent_color_id_, int64 profile_background_custom_emoji_id_, object_ptr<emojiStatus> &&emoji_status_, bool is_contact_, bool is_mutual_contact_, bool is_close_friend_, object_ptr<verificationStatus> &&verification_status_, bool is_premium_, bool is_support_, object_ptr<restrictionInfo> &&restriction_info_, object_ptr<ActiveStoryState> &&active_story_state_, bool restricts_new_chats_, int53 paid_message_star_count_, bool have_access_, object_ptr<UserType> &&type_, string const &language_code_, bool added_to_attachment_menu_)
  : id_(id_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , usernames_(std::move(usernames_))
  , phone_number_(phone_number_)
  , status_(std::move(status_))
  , profile_photo_(std::move(profile_photo_))
  , accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
  , upgraded_gift_colors_(std::move(upgraded_gift_colors_))
  , profile_accent_color_id_(profile_accent_color_id_)
  , profile_background_custom_emoji_id_(profile_background_custom_emoji_id_)
  , emoji_status_(std::move(emoji_status_))
  , is_contact_(is_contact_)
  , is_mutual_contact_(is_mutual_contact_)
  , is_close_friend_(is_close_friend_)
  , verification_status_(std::move(verification_status_))
  , is_premium_(is_premium_)
  , is_support_(is_support_)
  , restriction_info_(std::move(restriction_info_))
  , active_story_state_(std::move(active_story_state_))
  , restricts_new_chats_(restricts_new_chats_)
  , paid_message_star_count_(paid_message_star_count_)
  , have_access_(have_access_)
  , type_(std::move(type_))
  , language_code_(language_code_)
  , added_to_attachment_menu_(added_to_attachment_menu_)
{}

const std::int32_t user::ID;

void user::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "user");
    s.store_field("id", id_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_object_field("usernames", static_cast<const BaseObject *>(usernames_.get()));
    s.store_field("phone_number", phone_number_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_object_field("profile_photo", static_cast<const BaseObject *>(profile_photo_.get()));
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_object_field("upgraded_gift_colors", static_cast<const BaseObject *>(upgraded_gift_colors_.get()));
    s.store_field("profile_accent_color_id", profile_accent_color_id_);
    s.store_field("profile_background_custom_emoji_id", profile_background_custom_emoji_id_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_field("is_contact", is_contact_);
    s.store_field("is_mutual_contact", is_mutual_contact_);
    s.store_field("is_close_friend", is_close_friend_);
    s.store_object_field("verification_status", static_cast<const BaseObject *>(verification_status_.get()));
    s.store_field("is_premium", is_premium_);
    s.store_field("is_support", is_support_);
    s.store_object_field("restriction_info", static_cast<const BaseObject *>(restriction_info_.get()));
    s.store_object_field("active_story_state", static_cast<const BaseObject *>(active_story_state_.get()));
    s.store_field("restricts_new_chats", restricts_new_chats_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_field("have_access", have_access_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("language_code", language_code_);
    s.store_field("added_to_attachment_menu", added_to_attachment_menu_);
    s.store_class_end();
  }
}

userTonWalletAddress::userTonWalletAddress()
  : user_id_()
  , wallet_address_()
  , public_key_()
{}

userTonWalletAddress::userTonWalletAddress(int53 user_id_, string const &wallet_address_, bytes const &public_key_)
  : user_id_(user_id_)
  , wallet_address_(wallet_address_)
  , public_key_(std::move(public_key_))
{}

const std::int32_t userTonWalletAddress::ID;

void userTonWalletAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTonWalletAddress");
    s.store_field("user_id", user_id_);
    s.store_field("wallet_address", wallet_address_);
    s.store_bytes_field("public_key", public_key_);
    s.store_class_end();
  }
}

userTypeRegular::userTypeRegular() {
}

const std::int32_t userTypeRegular::ID;

void userTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeRegular");
    s.store_class_end();
  }
}

userTypeDeleted::userTypeDeleted() {
}

const std::int32_t userTypeDeleted::ID;

void userTypeDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeDeleted");
    s.store_class_end();
  }
}

userTypeBot::userTypeBot()
  : can_be_edited_()
  , can_join_groups_()
  , can_read_all_group_messages_()
  , has_main_web_app_()
  , has_topics_()
  , has_topic_sidebar_()
  , allows_users_to_create_topics_()
  , can_manage_bots_()
  , is_inline_()
  , inline_query_placeholder_()
  , supports_guest_queries_()
  , is_guard_()
  , need_location_()
  , can_connect_to_business_()
  , can_be_added_to_attachment_menu_()
  , active_user_count_()
{}

userTypeBot::userTypeBot(bool can_be_edited_, bool can_join_groups_, bool can_read_all_group_messages_, bool has_main_web_app_, bool has_topics_, bool has_topic_sidebar_, bool allows_users_to_create_topics_, bool can_manage_bots_, bool is_inline_, string const &inline_query_placeholder_, bool supports_guest_queries_, bool is_guard_, bool need_location_, bool can_connect_to_business_, bool can_be_added_to_attachment_menu_, int32 active_user_count_)
  : can_be_edited_(can_be_edited_)
  , can_join_groups_(can_join_groups_)
  , can_read_all_group_messages_(can_read_all_group_messages_)
  , has_main_web_app_(has_main_web_app_)
  , has_topics_(has_topics_)
  , has_topic_sidebar_(has_topic_sidebar_)
  , allows_users_to_create_topics_(allows_users_to_create_topics_)
  , can_manage_bots_(can_manage_bots_)
  , is_inline_(is_inline_)
  , inline_query_placeholder_(inline_query_placeholder_)
  , supports_guest_queries_(supports_guest_queries_)
  , is_guard_(is_guard_)
  , need_location_(need_location_)
  , can_connect_to_business_(can_connect_to_business_)
  , can_be_added_to_attachment_menu_(can_be_added_to_attachment_menu_)
  , active_user_count_(active_user_count_)
{}

const std::int32_t userTypeBot::ID;

void userTypeBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeBot");
    s.store_field("can_be_edited", can_be_edited_);
    s.store_field("can_join_groups", can_join_groups_);
    s.store_field("can_read_all_group_messages", can_read_all_group_messages_);
    s.store_field("has_main_web_app", has_main_web_app_);
    s.store_field("has_topics", has_topics_);
    s.store_field("has_topic_sidebar", has_topic_sidebar_);
    s.store_field("allows_users_to_create_topics", allows_users_to_create_topics_);
    s.store_field("can_manage_bots", can_manage_bots_);
    s.store_field("is_inline", is_inline_);
    s.store_field("inline_query_placeholder", inline_query_placeholder_);
    s.store_field("supports_guest_queries", supports_guest_queries_);
    s.store_field("is_guard", is_guard_);
    s.store_field("need_location", need_location_);
    s.store_field("can_connect_to_business", can_connect_to_business_);
    s.store_field("can_be_added_to_attachment_menu", can_be_added_to_attachment_menu_);
    s.store_field("active_user_count", active_user_count_);
    s.store_class_end();
  }
}

userTypeUnknown::userTypeUnknown() {
}

const std::int32_t userTypeUnknown::ID;

void userTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeUnknown");
    s.store_class_end();
  }
}

users::users()
  : total_count_()
  , user_ids_()
{}

users::users(int32 total_count_, array<int53> &&user_ids_)
  : total_count_(total_count_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t users::ID;

void users::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

validatedOrderInfo::validatedOrderInfo()
  : order_info_id_()
  , shipping_options_()
{}

validatedOrderInfo::validatedOrderInfo(string const &order_info_id_, array<object_ptr<shippingOption>> &&shipping_options_)
  : order_info_id_(order_info_id_)
  , shipping_options_(std::move(shipping_options_))
{}

const std::int32_t validatedOrderInfo::ID;

void validatedOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "validatedOrderInfo");
    s.store_field("order_info_id", order_info_id_);
    { s.store_vector_begin("shipping_options", shipping_options_.size()); for (const auto &_value : shipping_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

widgetQueryAnswer::widgetQueryAnswer()
  : data_()
{}

widgetQueryAnswer::widgetQueryAnswer(string const &data_)
  : data_(data_)
{}

const std::int32_t widgetQueryAnswer::ID;

void widgetQueryAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "widgetQueryAnswer");
    s.store_field("data", data_);
    s.store_class_end();
  }
}

addChatFolderByInviteLink::addChatFolderByInviteLink()
  : invite_link_()
  , chat_ids_()
{}

addChatFolderByInviteLink::addChatFolderByInviteLink(string const &invite_link_, array<int53> &&chat_ids_)
  : invite_link_(invite_link_)
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t addChatFolderByInviteLink::ID;

void addChatFolderByInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatFolderByInviteLink");
    s.store_field("invite_link", invite_link_);
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

addChatMembers::addChatMembers()
  : chat_id_()
  , user_ids_()
{}

addChatMembers::addChatMembers(int53 chat_id_, array<int53> &&user_ids_)
  : chat_id_(chat_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t addChatMembers::ID;

void addChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatMembers");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

addPollOption::addPollOption()
  : chat_id_()
  , message_id_()
  , option_()
{}

addPollOption::addPollOption(int53 chat_id_, int53 message_id_, object_ptr<inputPollOption> &&option_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_(std::move(option_))
{}

const std::int32_t addPollOption::ID;

void addPollOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addPollOption");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("option", static_cast<const BaseObject *>(option_.get()));
    s.store_class_end();
  }
}

addProxy::addProxy()
  : proxy_()
  , enable_()
  , comment_()
{}

addProxy::addProxy(object_ptr<proxy> &&proxy_, bool enable_, string const &comment_)
  : proxy_(std::move(proxy_))
  , enable_(enable_)
  , comment_(comment_)
{}

const std::int32_t addProxy::ID;

void addProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addProxy");
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_field("enable", enable_);
    s.store_field("comment", comment_);
    s.store_class_end();
  }
}

addRecentSticker::addRecentSticker()
  : is_attached_()
  , sticker_()
{}

addRecentSticker::addRecentSticker(bool is_attached_, object_ptr<InputFile> &&sticker_)
  : is_attached_(is_attached_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t addRecentSticker::ID;

void addRecentSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addRecentSticker");
    s.store_field("is_attached", is_attached_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

answerInlineQuery::answerInlineQuery()
  : inline_query_id_()
  , is_personal_()
  , button_()
  , results_()
  , cache_time_()
  , next_offset_()
{}

answerInlineQuery::answerInlineQuery(int64 inline_query_id_, bool is_personal_, object_ptr<inlineQueryResultsButton> &&button_, array<object_ptr<InputInlineQueryResult>> &&results_, int32 cache_time_, string const &next_offset_)
  : inline_query_id_(inline_query_id_)
  , is_personal_(is_personal_)
  , button_(std::move(button_))
  , results_(std::move(results_))
  , cache_time_(cache_time_)
  , next_offset_(next_offset_)
{}

const std::int32_t answerInlineQuery::ID;

void answerInlineQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerInlineQuery");
    s.store_field("inline_query_id", inline_query_id_);
    s.store_field("is_personal", is_personal_);
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("cache_time", cache_time_);
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

answerPreCheckoutQuery::answerPreCheckoutQuery()
  : pre_checkout_query_id_()
  , error_message_()
{}

answerPreCheckoutQuery::answerPreCheckoutQuery(int64 pre_checkout_query_id_, string const &error_message_)
  : pre_checkout_query_id_(pre_checkout_query_id_)
  , error_message_(error_message_)
{}

const std::int32_t answerPreCheckoutQuery::ID;

void answerPreCheckoutQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerPreCheckoutQuery");
    s.store_field("pre_checkout_query_id", pre_checkout_query_id_);
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

cancelGiftOnChainPurchaseOffer::cancelGiftOnChainPurchaseOffer()
  : message_id_()
{}

cancelGiftOnChainPurchaseOffer::cancelGiftOnChainPurchaseOffer(int53 message_id_)
  : message_id_(message_id_)
{}

const std::int32_t cancelGiftOnChainPurchaseOffer::ID;

void cancelGiftOnChainPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelGiftOnChainPurchaseOffer");
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

clickChatSponsoredMessage::clickChatSponsoredMessage()
  : chat_id_()
  , message_id_()
  , is_media_click_()
  , from_fullscreen_()
{}

clickChatSponsoredMessage::clickChatSponsoredMessage(int53 chat_id_, int53 message_id_, bool is_media_click_, bool from_fullscreen_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_media_click_(is_media_click_)
  , from_fullscreen_(from_fullscreen_)
{}

const std::int32_t clickChatSponsoredMessage::ID;

void clickChatSponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clickChatSponsoredMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_media_click", is_media_click_);
    s.store_field("from_fullscreen", from_fullscreen_);
    s.store_class_end();
  }
}

createCall::createCall()
  : user_id_()
  , protocol_()
  , is_video_()
{}

createCall::createCall(int53 user_id_, object_ptr<callProtocol> &&protocol_, bool is_video_)
  : user_id_(user_id_)
  , protocol_(std::move(protocol_))
  , is_video_(is_video_)
{}

const std::int32_t createCall::ID;

void createCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createCall");
    s.store_field("user_id", user_id_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_field("is_video", is_video_);
    s.store_class_end();
  }
}

createInvoiceLink::createInvoiceLink()
  : business_connection_id_()
  , invoice_()
{}

createInvoiceLink::createInvoiceLink(string const &business_connection_id_, object_ptr<InputMessageContent> &&invoice_)
  : business_connection_id_(business_connection_id_)
  , invoice_(std::move(invoice_))
{}

const std::int32_t createInvoiceLink::ID;

void createInvoiceLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createInvoiceLink");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_class_end();
  }
}

createSupergroupChat::createSupergroupChat()
  : supergroup_id_()
  , force_()
{}

createSupergroupChat::createSupergroupChat(int53 supergroup_id_, bool force_)
  : supergroup_id_(supergroup_id_)
  , force_(force_)
{}

const std::int32_t createSupergroupChat::ID;

void createSupergroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createSupergroupChat");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

createVideoChat::createVideoChat()
  : chat_id_()
  , title_()
  , start_date_()
  , is_rtmp_stream_()
{}

createVideoChat::createVideoChat(int53 chat_id_, string const &title_, int32 start_date_, bool is_rtmp_stream_)
  : chat_id_(chat_id_)
  , title_(title_)
  , start_date_(start_date_)
  , is_rtmp_stream_(is_rtmp_stream_)
{}

const std::int32_t createVideoChat::ID;

void createVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createVideoChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_field("start_date", start_date_);
    s.store_field("is_rtmp_stream", is_rtmp_stream_);
    s.store_class_end();
  }
}

deleteAllCallMessages::deleteAllCallMessages()
  : revoke_()
{}

deleteAllCallMessages::deleteAllCallMessages(bool revoke_)
  : revoke_(revoke_)
{}

const std::int32_t deleteAllCallMessages::ID;

void deleteAllCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteAllCallMessages");
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

disconnectAffiliateProgram::disconnectAffiliateProgram()
  : affiliate_()
  , url_()
{}

disconnectAffiliateProgram::disconnectAffiliateProgram(object_ptr<AffiliateType> &&affiliate_, string const &url_)
  : affiliate_(std::move(affiliate_))
  , url_(url_)
{}

const std::int32_t disconnectAffiliateProgram::ID;

void disconnectAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disconnectAffiliateProgram");
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_field("url", url_);
    s.store_class_end();
  }
}

editMessageSchedulingState::editMessageSchedulingState()
  : chat_id_()
  , message_id_()
  , scheduling_state_()
{}

editMessageSchedulingState::editMessageSchedulingState(int53 chat_id_, int53 message_id_, object_ptr<MessageSchedulingState> &&scheduling_state_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , scheduling_state_(std::move(scheduling_state_))
{}

const std::int32_t editMessageSchedulingState::ID;

void editMessageSchedulingState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageSchedulingState");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("scheduling_state", static_cast<const BaseObject *>(scheduling_state_.get()));
    s.store_class_end();
  }
}

finishFileGeneration::finishFileGeneration()
  : generation_id_()
  , error_()
{}

finishFileGeneration::finishFileGeneration(int64 generation_id_, object_ptr<error> &&error_)
  : generation_id_(generation_id_)
  , error_(std::move(error_))
{}

const std::int32_t finishFileGeneration::ID;

void finishFileGeneration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "finishFileGeneration");
    s.store_field("generation_id", generation_id_);
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

getArchivedStickerSets::getArchivedStickerSets()
  : sticker_type_()
  , offset_sticker_set_id_()
  , limit_()
{}

getArchivedStickerSets::getArchivedStickerSets(object_ptr<StickerType> &&sticker_type_, int64 offset_sticker_set_id_, int32 limit_)
  : sticker_type_(std::move(sticker_type_))
  , offset_sticker_set_id_(offset_sticker_set_id_)
  , limit_(limit_)
{}

const std::int32_t getArchivedStickerSets::ID;

void getArchivedStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getArchivedStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("offset_sticker_set_id", offset_sticker_set_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getBusinessFeatures::getBusinessFeatures()
  : source_()
{}

getBusinessFeatures::getBusinessFeatures(object_ptr<BusinessFeature> &&source_)
  : source_(std::move(source_))
{}

const std::int32_t getBusinessFeatures::ID;

void getBusinessFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessFeatures");
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

getChatInviteLinks::getChatInviteLinks()
  : chat_id_()
  , creator_user_id_()
  , is_revoked_()
  , offset_date_()
  , offset_invite_link_()
  , limit_()
{}

getChatInviteLinks::getChatInviteLinks(int53 chat_id_, int53 creator_user_id_, bool is_revoked_, int32 offset_date_, string const &offset_invite_link_, int32 limit_)
  : chat_id_(chat_id_)
  , creator_user_id_(creator_user_id_)
  , is_revoked_(is_revoked_)
  , offset_date_(offset_date_)
  , offset_invite_link_(offset_invite_link_)
  , limit_(limit_)
{}

const std::int32_t getChatInviteLinks::ID;

void getChatInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLinks");
    s.store_field("chat_id", chat_id_);
    s.store_field("creator_user_id", creator_user_id_);
    s.store_field("is_revoked", is_revoked_);
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_invite_link", offset_invite_link_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatMessageCounts::getChatMessageCounts()
  : chat_id_()
  , topic_id_()
  , filters_()
  , return_local_()
{}

getChatMessageCounts::getChatMessageCounts(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, array<object_ptr<SearchMessagesFilter>> &&filters_, bool return_local_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , filters_(std::move(filters_))
  , return_local_(return_local_)
{}

const std::int32_t getChatMessageCounts::ID;

void getChatMessageCounts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessageCounts");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    { s.store_vector_begin("filters", filters_.size()); for (const auto &_value : filters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("return_local", return_local_);
    s.store_class_end();
  }
}

getChatsForChatFolderInviteLink::getChatsForChatFolderInviteLink()
  : chat_folder_id_()
{}

getChatsForChatFolderInviteLink::getChatsForChatFolderInviteLink(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t getChatsForChatFolderInviteLink::ID;

void getChatsForChatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatsForChatFolderInviteLink");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

getConnectedAffiliatePrograms::getConnectedAffiliatePrograms()
  : affiliate_()
  , offset_()
  , limit_()
{}

getConnectedAffiliatePrograms::getConnectedAffiliatePrograms(object_ptr<AffiliateType> &&affiliate_, string const &offset_, int32 limit_)
  : affiliate_(std::move(affiliate_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getConnectedAffiliatePrograms::ID;

void getConnectedAffiliatePrograms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getConnectedAffiliatePrograms");
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getConnectedWebsites::getConnectedWebsites() {
}

const std::int32_t getConnectedWebsites::ID;

void getConnectedWebsites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getConnectedWebsites");
    s.store_class_end();
  }
}

getContacts::getContacts() {
}

const std::int32_t getContacts::ID;

void getContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getContacts");
    s.store_class_end();
  }
}

getDatabaseStatistics::getDatabaseStatistics() {
}

const std::int32_t getDatabaseStatistics::ID;

void getDatabaseStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDatabaseStatistics");
    s.store_class_end();
  }
}

getEmojiSuggestionsUrl::getEmojiSuggestionsUrl()
  : language_code_()
{}

getEmojiSuggestionsUrl::getEmojiSuggestionsUrl(string const &language_code_)
  : language_code_(language_code_)
{}

const std::int32_t getEmojiSuggestionsUrl::ID;

void getEmojiSuggestionsUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getEmojiSuggestionsUrl");
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getExternalLinkInfo::getExternalLinkInfo()
  : link_()
{}

getExternalLinkInfo::getExternalLinkInfo(string const &link_)
  : link_(link_)
{}

const std::int32_t getExternalLinkInfo::ID;

void getExternalLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getExternalLinkInfo");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

getFile::getFile()
  : file_id_()
{}

getFile::getFile(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t getFile::ID;

void getFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFile");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

getForumTopics::getForumTopics()
  : chat_id_()
  , query_()
  , icon_custom_emoji_id_()
  , exclude_open_()
  , exclude_closed_()
  , offset_date_()
  , offset_message_id_()
  , offset_forum_topic_id_()
  , limit_()
{}

getForumTopics::getForumTopics(int53 chat_id_, string const &query_, int64 icon_custom_emoji_id_, bool exclude_open_, bool exclude_closed_, int32 offset_date_, int53 offset_message_id_, int32 offset_forum_topic_id_, int32 limit_)
  : chat_id_(chat_id_)
  , query_(query_)
  , icon_custom_emoji_id_(icon_custom_emoji_id_)
  , exclude_open_(exclude_open_)
  , exclude_closed_(exclude_closed_)
  , offset_date_(offset_date_)
  , offset_message_id_(offset_message_id_)
  , offset_forum_topic_id_(offset_forum_topic_id_)
  , limit_(limit_)
{}

const std::int32_t getForumTopics::ID;

void getForumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getForumTopics");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_field("exclude_open", exclude_open_);
    s.store_field("exclude_closed", exclude_closed_);
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_message_id", offset_message_id_);
    s.store_field("offset_forum_topic_id", offset_forum_topic_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getGiftChatThemes::getGiftChatThemes()
  : offset_()
  , limit_()
{}

getGiftChatThemes::getGiftChatThemes(string const &offset_, int32 limit_)
  : offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getGiftChatThemes::ID;

void getGiftChatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftChatThemes");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getGiftUpgradePreview::getGiftUpgradePreview()
  : regular_gift_id_()
{}

getGiftUpgradePreview::getGiftUpgradePreview(int64 regular_gift_id_)
  : regular_gift_id_(regular_gift_id_)
{}

const std::int32_t getGiftUpgradePreview::ID;

void getGiftUpgradePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftUpgradePreview");
    s.store_field("regular_gift_id", regular_gift_id_);
    s.store_class_end();
  }
}

getGrossingWebAppBots::getGrossingWebAppBots()
  : offset_()
  , limit_()
{}

getGrossingWebAppBots::getGrossingWebAppBots(string const &offset_, int32 limit_)
  : offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getGrossingWebAppBots::ID;

void getGrossingWebAppBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGrossingWebAppBots");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getLanguagePackStrings::getLanguagePackStrings()
  : language_pack_id_()
  , keys_()
{}

getLanguagePackStrings::getLanguagePackStrings(string const &language_pack_id_, array<string> &&keys_)
  : language_pack_id_(language_pack_id_)
  , keys_(std::move(keys_))
{}

const std::int32_t getLanguagePackStrings::ID;

void getLanguagePackStrings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLanguagePackStrings");
    s.store_field("language_pack_id", language_pack_id_);
    { s.store_vector_begin("keys", keys_.size()); for (const auto &_value : keys_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getLogStream::getLogStream() {
}

const std::int32_t getLogStream::ID;

void getLogStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogStream");
    s.store_class_end();
  }
}

getLoginUrl::getLoginUrl()
  : chat_id_()
  , message_id_()
  , button_id_()
  , allow_write_access_()
{}

getLoginUrl::getLoginUrl(int53 chat_id_, int53 message_id_, int53 button_id_, bool allow_write_access_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , button_id_(button_id_)
  , allow_write_access_(allow_write_access_)
{}

const std::int32_t getLoginUrl::ID;

void getLoginUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLoginUrl");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("button_id", button_id_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_class_end();
  }
}

getLoginUrlInfo::getLoginUrlInfo()
  : chat_id_()
  , message_id_()
  , button_id_()
{}

getLoginUrlInfo::getLoginUrlInfo(int53 chat_id_, int53 message_id_, int53 button_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , button_id_(button_id_)
{}

const std::int32_t getLoginUrlInfo::ID;

void getLoginUrlInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLoginUrlInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("button_id", button_id_);
    s.store_class_end();
  }
}

getMessageFileType::getMessageFileType()
  : message_file_head_()
{}

getMessageFileType::getMessageFileType(string const &message_file_head_)
  : message_file_head_(message_file_head_)
{}

const std::int32_t getMessageFileType::ID;

void getMessageFileType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageFileType");
    s.store_field("message_file_head", message_file_head_);
    s.store_class_end();
  }
}

getMessageProperties::getMessageProperties()
  : chat_id_()
  , message_id_()
{}

getMessageProperties::getMessageProperties(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageProperties::ID;

void getMessageProperties::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageProperties");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessageViewers::getMessageViewers()
  : chat_id_()
  , message_id_()
{}

getMessageViewers::getMessageViewers(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageViewers::ID;

void getMessageViewers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageViewers");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getOauthLinkInfo::getOauthLinkInfo()
  : url_()
  , in_app_origin_()
{}

getOauthLinkInfo::getOauthLinkInfo(string const &url_, string const &in_app_origin_)
  : url_(url_)
  , in_app_origin_(in_app_origin_)
{}

const std::int32_t getOauthLinkInfo::ID;

void getOauthLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOauthLinkInfo");
    s.store_field("url", url_);
    s.store_field("in_app_origin", in_app_origin_);
    s.store_class_end();
  }
}

getOnRampPaymentAvailability::getOnRampPaymentAvailability()
  : provider_id_()
  , cryptocurrency_()
  , base_currency_()
{}

getOnRampPaymentAvailability::getOnRampPaymentAvailability(string const &provider_id_, string const &cryptocurrency_, string const &base_currency_)
  : provider_id_(provider_id_)
  , cryptocurrency_(cryptocurrency_)
  , base_currency_(base_currency_)
{}

const std::int32_t getOnRampPaymentAvailability::ID;

void getOnRampPaymentAvailability::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOnRampPaymentAvailability");
    s.store_field("provider_id", provider_id_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("base_currency", base_currency_);
    s.store_class_end();
  }
}

getOnRampProviderBaseCurrencies::getOnRampProviderBaseCurrencies()
  : provider_id_()
  , cryptocurrency_()
{}

getOnRampProviderBaseCurrencies::getOnRampProviderBaseCurrencies(string const &provider_id_, string const &cryptocurrency_)
  : provider_id_(provider_id_)
  , cryptocurrency_(cryptocurrency_)
{}

const std::int32_t getOnRampProviderBaseCurrencies::ID;

void getOnRampProviderBaseCurrencies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOnRampProviderBaseCurrencies");
    s.store_field("provider_id", provider_id_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_class_end();
  }
}

getOnRampProviders::getOnRampProviders()
  : cryptocurrency_()
{}

getOnRampProviders::getOnRampProviders(string const &cryptocurrency_)
  : cryptocurrency_(cryptocurrency_)
{}

const std::int32_t getOnRampProviders::ID;

void getOnRampProviders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOnRampProviders");
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_class_end();
  }
}

getPhoneNumberInfoSync::getPhoneNumberInfoSync()
  : language_code_()
  , phone_number_prefix_()
{}

getPhoneNumberInfoSync::getPhoneNumberInfoSync(string const &language_code_, string const &phone_number_prefix_)
  : language_code_(language_code_)
  , phone_number_prefix_(phone_number_prefix_)
{}

const std::int32_t getPhoneNumberInfoSync::ID;

void getPhoneNumberInfoSync::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPhoneNumberInfoSync");
    s.store_field("language_code", language_code_);
    s.store_field("phone_number_prefix", phone_number_prefix_);
    s.store_class_end();
  }
}

getPremiumGiveawayPaymentOptions::getPremiumGiveawayPaymentOptions()
  : boosted_chat_id_()
{}

getPremiumGiveawayPaymentOptions::getPremiumGiveawayPaymentOptions(int53 boosted_chat_id_)
  : boosted_chat_id_(boosted_chat_id_)
{}

const std::int32_t getPremiumGiveawayPaymentOptions::ID;

void getPremiumGiveawayPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumGiveawayPaymentOptions");
    s.store_field("boosted_chat_id", boosted_chat_id_);
    s.store_class_end();
  }
}

getPremiumState::getPremiumState() {
}

const std::int32_t getPremiumState::ID;

void getPremiumState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumState");
    s.store_class_end();
  }
}

getPublicPostSearchLimits::getPublicPostSearchLimits()
  : query_()
{}

getPublicPostSearchLimits::getPublicPostSearchLimits(string const &query_)
  : query_(query_)
{}

const std::int32_t getPublicPostSearchLimits::ID;

void getPublicPostSearchLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPublicPostSearchLimits");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

getReceivedGift::getReceivedGift()
  : received_gift_id_()
{}

getReceivedGift::getReceivedGift(string const &received_gift_id_)
  : received_gift_id_(received_gift_id_)
{}

const std::int32_t getReceivedGift::ID;

void getReceivedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getReceivedGift");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

getRecommendedChatFolders::getRecommendedChatFolders() {
}

const std::int32_t getRecommendedChatFolders::ID;

void getRecommendedChatFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecommendedChatFolders");
    s.store_class_end();
  }
}

getSavedAnimations::getSavedAnimations() {
}

const std::int32_t getSavedAnimations::ID;

void getSavedAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedAnimations");
    s.store_class_end();
  }
}

getSavedMessagesTopicHistory::getSavedMessagesTopicHistory()
  : saved_messages_topic_id_()
  , from_message_id_()
  , offset_()
  , limit_()
{}

getSavedMessagesTopicHistory::getSavedMessagesTopicHistory(int53 saved_messages_topic_id_, int53 from_message_id_, int32 offset_, int32 limit_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getSavedMessagesTopicHistory::ID;

void getSavedMessagesTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedMessagesTopicHistory");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getStarSubscriptions::getStarSubscriptions()
  : only_expiring_()
  , offset_()
{}

getStarSubscriptions::getStarSubscriptions(bool only_expiring_, string const &offset_)
  : only_expiring_(only_expiring_)
  , offset_(offset_)
{}

const std::int32_t getStarSubscriptions::ID;

void getStarSubscriptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarSubscriptions");
    s.store_field("only_expiring", only_expiring_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

getStickerSet::getStickerSet()
  : set_id_()
{}

getStickerSet::getStickerSet(int64 set_id_)
  : set_id_(set_id_)
{}

const std::int32_t getStickerSet::ID;

void getStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerSet");
    s.store_field("set_id", set_id_);
    s.store_class_end();
  }
}

getSuggestedStickerSetName::getSuggestedStickerSetName()
  : title_()
{}

getSuggestedStickerSetName::getSuggestedStickerSetName(string const &title_)
  : title_(title_)
{}

const std::int32_t getSuggestedStickerSetName::ID;

void getSuggestedStickerSetName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuggestedStickerSetName");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

getTonCenterStreamingApiUrl::getTonCenterStreamingApiUrl() {
}

const std::int32_t getTonCenterStreamingApiUrl::ID;

void getTonCenterStreamingApiUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonCenterStreamingApiUrl");
    s.store_class_end();
  }
}

getUserLink::getUserLink()
  : remove_messages_fee_()
  , return_permanent_link_()
  , revoke_previous_links_()
{}

getUserLink::getUserLink(bool remove_messages_fee_, bool return_permanent_link_, bool revoke_previous_links_)
  : remove_messages_fee_(remove_messages_fee_)
  , return_permanent_link_(return_permanent_link_)
  , revoke_previous_links_(revoke_previous_links_)
{}

const std::int32_t getUserLink::ID;

void getUserLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserLink");
    s.store_field("remove_messages_fee", remove_messages_fee_);
    s.store_field("return_permanent_link", return_permanent_link_);
    s.store_field("revoke_previous_links", revoke_previous_links_);
    s.store_class_end();
  }
}

getUserProfileAudios::getUserProfileAudios()
  : user_id_()
  , offset_()
  , limit_()
{}

getUserProfileAudios::getUserProfileAudios(int53 user_id_, int32 offset_, int32 limit_)
  : user_id_(user_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getUserProfileAudios::ID;

void getUserProfileAudios::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserProfileAudios");
    s.store_field("user_id", user_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getUserProfilePhotos::getUserProfilePhotos()
  : user_id_()
  , offset_()
  , limit_()
{}

getUserProfilePhotos::getUserProfilePhotos(int53 user_id_, int32 offset_, int32 limit_)
  : user_id_(user_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getUserProfilePhotos::ID;

void getUserProfilePhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserProfilePhotos");
    s.store_field("user_id", user_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getUserTonWalletAddresses::getUserTonWalletAddresses()
  : user_ids_()
{}

getUserTonWalletAddresses::getUserTonWalletAddresses(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t getUserTonWalletAddresses::ID;

void getUserTonWalletAddresses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserTonWalletAddresses");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getWidgetQueryAnswer::getWidgetQueryAnswer()
  : chat_id_()
  , message_id_()
  , query_type_()
  , data_()
{}

getWidgetQueryAnswer::getWidgetQueryAnswer(int53 chat_id_, int53 message_id_, object_ptr<WidgetQueryType> &&query_type_, bytes const &data_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , query_type_(std::move(query_type_))
  , data_(std::move(data_))
{}

const std::int32_t getWidgetQueryAnswer::ID;

void getWidgetQueryAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWidgetQueryAnswer");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("query_type", static_cast<const BaseObject *>(query_type_.get()));
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

giftPremiumWithStars::giftPremiumWithStars()
  : user_id_()
  , star_count_()
  , month_count_()
  , text_()
{}

giftPremiumWithStars::giftPremiumWithStars(int53 user_id_, int53 star_count_, int32 month_count_, object_ptr<formattedText> &&text_)
  : user_id_(user_id_)
  , star_count_(star_count_)
  , month_count_(month_count_)
  , text_(std::move(text_))
{}

const std::int32_t giftPremiumWithStars::ID;

void giftPremiumWithStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftPremiumWithStars");
    s.store_field("user_id", user_id_);
    s.store_field("star_count", star_count_);
    s.store_field("month_count", month_count_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

parseTextEntities::parseTextEntities()
  : text_()
  , parse_mode_()
{}

parseTextEntities::parseTextEntities(string const &text_, object_ptr<TextParseMode> &&parse_mode_)
  : text_(text_)
  , parse_mode_(std::move(parse_mode_))
{}

const std::int32_t parseTextEntities::ID;

void parseTextEntities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "parseTextEntities");
    s.store_field("text", text_);
    s.store_object_field("parse_mode", static_cast<const BaseObject *>(parse_mode_.get()));
    s.store_class_end();
  }
}

readdQuickReplyShortcutMessages::readdQuickReplyShortcutMessages()
  : shortcut_name_()
  , message_ids_()
{}

readdQuickReplyShortcutMessages::readdQuickReplyShortcutMessages(string const &shortcut_name_, array<int53> &&message_ids_)
  : shortcut_name_(shortcut_name_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t readdQuickReplyShortcutMessages::ID;

void readdQuickReplyShortcutMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readdQuickReplyShortcutMessages");
    s.store_field("shortcut_name", shortcut_name_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

recognizeSpeech::recognizeSpeech()
  : chat_id_()
  , message_id_()
{}

recognizeSpeech::recognizeSpeech(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t recognizeSpeech::ID;

void recognizeSpeech::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recognizeSpeech");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

removeMessageSenderBotVerification::removeMessageSenderBotVerification()
  : bot_user_id_()
  , verified_id_()
{}

removeMessageSenderBotVerification::removeMessageSenderBotVerification(int53 bot_user_id_, object_ptr<MessageSender> &&verified_id_)
  : bot_user_id_(bot_user_id_)
  , verified_id_(std::move(verified_id_))
{}

const std::int32_t removeMessageSenderBotVerification::ID;

void removeMessageSenderBotVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeMessageSenderBotVerification");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("verified_id", static_cast<const BaseObject *>(verified_id_.get()));
    s.store_class_end();
  }
}

removeNotification::removeNotification()
  : notification_group_id_()
  , notification_id_()
{}

removeNotification::removeNotification(int32 notification_group_id_, int32 notification_id_)
  : notification_group_id_(notification_group_id_)
  , notification_id_(notification_id_)
{}

const std::int32_t removeNotification::ID;

void removeNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeNotification");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_field("notification_id", notification_id_);
    s.store_class_end();
  }
}

removeNotificationGroup::removeNotificationGroup()
  : notification_group_id_()
  , max_notification_id_()
{}

removeNotificationGroup::removeNotificationGroup(int32 notification_group_id_, int32 max_notification_id_)
  : notification_group_id_(notification_group_id_)
  , max_notification_id_(max_notification_id_)
{}

const std::int32_t removeNotificationGroup::ID;

void removeNotificationGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeNotificationGroup");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_field("max_notification_id", max_notification_id_);
    s.store_class_end();
  }
}

removeProfileAudio::removeProfileAudio()
  : file_id_()
{}

removeProfileAudio::removeProfileAudio(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t removeProfileAudio::ID;

void removeProfileAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeProfileAudio");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

removeSearchedForTag::removeSearchedForTag()
  : tag_()
{}

removeSearchedForTag::removeSearchedForTag(string const &tag_)
  : tag_(tag_)
{}

const std::int32_t removeSearchedForTag::ID;

void removeSearchedForTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeSearchedForTag");
    s.store_field("tag", tag_);
    s.store_class_end();
  }
}

reorderChatFolders::reorderChatFolders()
  : chat_folder_ids_()
  , main_chat_list_position_()
{}

reorderChatFolders::reorderChatFolders(array<int32> &&chat_folder_ids_, int32 main_chat_list_position_)
  : chat_folder_ids_(std::move(chat_folder_ids_))
  , main_chat_list_position_(main_chat_list_position_)
{}

const std::int32_t reorderChatFolders::ID;

void reorderChatFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderChatFolders");
    { s.store_vector_begin("chat_folder_ids", chat_folder_ids_.size()); for (const auto &_value : chat_folder_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("main_chat_list_position", main_chat_list_position_);
    s.store_class_end();
  }
}

reorderStoryAlbumStories::reorderStoryAlbumStories()
  : chat_id_()
  , story_album_id_()
  , story_ids_()
{}

reorderStoryAlbumStories::reorderStoryAlbumStories(int53 chat_id_, int32 story_album_id_, array<int32> &&story_ids_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
  , story_ids_(std::move(story_ids_))
{}

const std::int32_t reorderStoryAlbumStories::ID;

void reorderStoryAlbumStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderStoryAlbumStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    { s.store_vector_begin("story_ids", story_ids_.size()); for (const auto &_value : story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

replyToCallbackQueryWithEphemeralMessage::replyToCallbackQueryWithEphemeralMessage()
  : callback_query_id_()
  , replace_callback_query_message_()
  , protect_content_()
  , reply_markup_()
  , input_message_content_()
{}

replyToCallbackQueryWithEphemeralMessage::replyToCallbackQueryWithEphemeralMessage(int64 callback_query_id_, bool replace_callback_query_message_, bool protect_content_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : callback_query_id_(callback_query_id_)
  , replace_callback_query_message_(replace_callback_query_message_)
  , protect_content_(protect_content_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t replyToCallbackQueryWithEphemeralMessage::ID;

void replyToCallbackQueryWithEphemeralMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyToCallbackQueryWithEphemeralMessage");
    s.store_field("callback_query_id", callback_query_id_);
    s.store_field("replace_callback_query_message", replace_callback_query_message_);
    s.store_field("protect_content", protect_content_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

reportChatSponsoredMessage::reportChatSponsoredMessage()
  : chat_id_()
  , message_id_()
  , option_id_()
{}

reportChatSponsoredMessage::reportChatSponsoredMessage(int53 chat_id_, int53 message_id_, bytes const &option_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_id_(std::move(option_id_))
{}

const std::int32_t reportChatSponsoredMessage::ID;

void reportChatSponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatSponsoredMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_bytes_field("option_id", option_id_);
    s.store_class_end();
  }
}

requestPasswordRecovery::requestPasswordRecovery() {
}

const std::int32_t requestPasswordRecovery::ID;

void requestPasswordRecovery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestPasswordRecovery");
    s.store_class_end();
  }
}

resendEmailAddressVerificationCode::resendEmailAddressVerificationCode() {
}

const std::int32_t resendEmailAddressVerificationCode::ID;

void resendEmailAddressVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendEmailAddressVerificationCode");
    s.store_class_end();
  }
}

resetAllNotificationSettings::resetAllNotificationSettings() {
}

const std::int32_t resetAllNotificationSettings::ID;

void resetAllNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetAllNotificationSettings");
    s.store_class_end();
  }
}

searchSecretMessages::searchSecretMessages()
  : chat_id_()
  , query_()
  , offset_()
  , limit_()
  , filter_()
{}

searchSecretMessages::searchSecretMessages(int53 chat_id_, string const &query_, string const &offset_, int32 limit_, object_ptr<SearchMessagesFilter> &&filter_)
  : chat_id_(chat_id_)
  , query_(query_)
  , offset_(offset_)
  , limit_(limit_)
  , filter_(std::move(filter_))
{}

const std::int32_t searchSecretMessages::ID;

void searchSecretMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchSecretMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_class_end();
  }
}

searchStringsByPrefix::searchStringsByPrefix()
  : strings_()
  , query_()
  , limit_()
  , return_none_for_empty_query_()
{}

searchStringsByPrefix::searchStringsByPrefix(array<string> &&strings_, string const &query_, int32 limit_, bool return_none_for_empty_query_)
  : strings_(std::move(strings_))
  , query_(query_)
  , limit_(limit_)
  , return_none_for_empty_query_(return_none_for_empty_query_)
{}

const std::int32_t searchStringsByPrefix::ID;

void searchStringsByPrefix::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchStringsByPrefix");
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_field("return_none_for_empty_query", return_none_for_empty_query_);
    s.store_class_end();
  }
}

sendGift::sendGift()
  : gift_id_()
  , owner_id_()
  , text_()
  , is_private_()
  , pay_for_upgrade_()
{}

sendGift::sendGift(int64 gift_id_, object_ptr<MessageSender> &&owner_id_, object_ptr<formattedText> &&text_, bool is_private_, bool pay_for_upgrade_)
  : gift_id_(gift_id_)
  , owner_id_(std::move(owner_id_))
  , text_(std::move(text_))
  , is_private_(is_private_)
  , pay_for_upgrade_(pay_for_upgrade_)
{}

const std::int32_t sendGift::ID;

void sendGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendGift");
    s.store_field("gift_id", gift_id_);
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_private", is_private_);
    s.store_field("pay_for_upgrade", pay_for_upgrade_);
    s.store_class_end();
  }
}

sendMessageViewMetrics::sendMessageViewMetrics()
  : chat_id_()
  , message_id_()
  , time_in_view_ms_()
  , active_time_in_view_ms_()
  , height_to_viewport_ratio_per_mille_()
  , seen_range_ratio_per_mille_()
{}

sendMessageViewMetrics::sendMessageViewMetrics(int53 chat_id_, int53 message_id_, int32 time_in_view_ms_, int32 active_time_in_view_ms_, int32 height_to_viewport_ratio_per_mille_, int32 seen_range_ratio_per_mille_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , time_in_view_ms_(time_in_view_ms_)
  , active_time_in_view_ms_(active_time_in_view_ms_)
  , height_to_viewport_ratio_per_mille_(height_to_viewport_ratio_per_mille_)
  , seen_range_ratio_per_mille_(seen_range_ratio_per_mille_)
{}

const std::int32_t sendMessageViewMetrics::ID;

void sendMessageViewMetrics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageViewMetrics");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("time_in_view_ms", time_in_view_ms_);
    s.store_field("active_time_in_view_ms", active_time_in_view_ms_);
    s.store_field("height_to_viewport_ratio_per_mille", height_to_viewport_ratio_per_mille_);
    s.store_field("seen_range_ratio_per_mille", seen_range_ratio_per_mille_);
    s.store_class_end();
  }
}

sendPassportAuthorizationForm::sendPassportAuthorizationForm()
  : authorization_form_id_()
  , types_()
{}

sendPassportAuthorizationForm::sendPassportAuthorizationForm(int32 authorization_form_id_, array<object_ptr<PassportElementType>> &&types_)
  : authorization_form_id_(authorization_form_id_)
  , types_(std::move(types_))
{}

const std::int32_t sendPassportAuthorizationForm::ID;

void sendPassportAuthorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPassportAuthorizationForm");
    s.store_field("authorization_form_id", authorization_form_id_);
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sendResoldGift::sendResoldGift()
  : gift_name_()
  , owner_id_()
  , price_()
  , text_()
  , is_private_()
{}

sendResoldGift::sendResoldGift(string const &gift_name_, object_ptr<MessageSender> &&owner_id_, object_ptr<GiftResalePrice> &&price_, object_ptr<formattedText> &&text_, bool is_private_)
  : gift_name_(gift_name_)
  , owner_id_(std::move(owner_id_))
  , price_(std::move(price_))
  , text_(std::move(text_))
  , is_private_(is_private_)
{}

const std::int32_t sendResoldGift::ID;

void sendResoldGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendResoldGift");
    s.store_field("gift_name", gift_name_);
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_private", is_private_);
    s.store_class_end();
  }
}

setAutosaveSettings::setAutosaveSettings()
  : scope_()
  , settings_()
{}

setAutosaveSettings::setAutosaveSettings(object_ptr<AutosaveSettingsScope> &&scope_, object_ptr<scopeAutosaveSettings> &&settings_)
  : scope_(std::move(scope_))
  , settings_(std::move(settings_))
{}

const std::int32_t setAutosaveSettings::ID;

void setAutosaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAutosaveSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setBio::setBio()
  : bio_()
{}

setBio::setBio(string const &bio_)
  : bio_(bio_)
{}

const std::int32_t setBio::ID;

void setBio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBio");
    s.store_field("bio", bio_);
    s.store_class_end();
  }
}

setBusinessAwayMessageSettings::setBusinessAwayMessageSettings()
  : away_message_settings_()
{}

setBusinessAwayMessageSettings::setBusinessAwayMessageSettings(object_ptr<businessAwayMessageSettings> &&away_message_settings_)
  : away_message_settings_(std::move(away_message_settings_))
{}

const std::int32_t setBusinessAwayMessageSettings::ID;

void setBusinessAwayMessageSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAwayMessageSettings");
    s.store_object_field("away_message_settings", static_cast<const BaseObject *>(away_message_settings_.get()));
    s.store_class_end();
  }
}

setChatAffiliateProgram::setChatAffiliateProgram()
  : chat_id_()
  , parameters_()
{}

setChatAffiliateProgram::setChatAffiliateProgram(int53 chat_id_, object_ptr<affiliateProgramParameters> &&parameters_)
  : chat_id_(chat_id_)
  , parameters_(std::move(parameters_))
{}

const std::int32_t setChatAffiliateProgram::ID;

void setChatAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatAffiliateProgram");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

setChatTextCompositionParameters::setChatTextCompositionParameters()
  : chat_id_()
  , text_composition_parameters_()
{}

setChatTextCompositionParameters::setChatTextCompositionParameters(int53 chat_id_, object_ptr<textCompositionParameters> &&text_composition_parameters_)
  : chat_id_(chat_id_)
  , text_composition_parameters_(std::move(text_composition_parameters_))
{}

const std::int32_t setChatTextCompositionParameters::ID;

void setChatTextCompositionParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatTextCompositionParameters");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("text_composition_parameters", static_cast<const BaseObject *>(text_composition_parameters_.get()));
    s.store_class_end();
  }
}

setCommunityPhoto::setCommunityPhoto()
  : community_id_()
  , photo_()
{}

setCommunityPhoto::setCommunityPhoto(int53 community_id_, object_ptr<InputChatPhoto> &&photo_)
  : community_id_(community_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t setCommunityPhoto::ID;

void setCommunityPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCommunityPhoto");
    s.store_field("community_id", community_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

setDefaultChannelAdministratorRights::setDefaultChannelAdministratorRights()
  : default_channel_administrator_rights_()
{}

setDefaultChannelAdministratorRights::setDefaultChannelAdministratorRights(object_ptr<chatAdministratorRights> &&default_channel_administrator_rights_)
  : default_channel_administrator_rights_(std::move(default_channel_administrator_rights_))
{}

const std::int32_t setDefaultChannelAdministratorRights::ID;

void setDefaultChannelAdministratorRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultChannelAdministratorRights");
    s.store_object_field("default_channel_administrator_rights", static_cast<const BaseObject *>(default_channel_administrator_rights_.get()));
    s.store_class_end();
  }
}

setDefaultMessageAutoDeleteTime::setDefaultMessageAutoDeleteTime()
  : message_auto_delete_time_()
{}

setDefaultMessageAutoDeleteTime::setDefaultMessageAutoDeleteTime(object_ptr<messageAutoDeleteTime> &&message_auto_delete_time_)
  : message_auto_delete_time_(std::move(message_auto_delete_time_))
{}

const std::int32_t setDefaultMessageAutoDeleteTime::ID;

void setDefaultMessageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultMessageAutoDeleteTime");
    s.store_object_field("message_auto_delete_time", static_cast<const BaseObject *>(message_auto_delete_time_.get()));
    s.store_class_end();
  }
}

setDirectMessagesChatTopicIsMarkedAsUnread::setDirectMessagesChatTopicIsMarkedAsUnread()
  : chat_id_()
  , topic_id_()
  , is_marked_as_unread_()
{}

setDirectMessagesChatTopicIsMarkedAsUnread::setDirectMessagesChatTopicIsMarkedAsUnread(int53 chat_id_, int53 topic_id_, bool is_marked_as_unread_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
  , is_marked_as_unread_(is_marked_as_unread_)
{}

const std::int32_t setDirectMessagesChatTopicIsMarkedAsUnread::ID;

void setDirectMessagesChatTopicIsMarkedAsUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDirectMessagesChatTopicIsMarkedAsUnread");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_class_end();
  }
}

setFileGenerationProgress::setFileGenerationProgress()
  : generation_id_()
  , expected_size_()
  , local_prefix_size_()
{}

setFileGenerationProgress::setFileGenerationProgress(int64 generation_id_, int53 expected_size_, int53 local_prefix_size_)
  : generation_id_(generation_id_)
  , expected_size_(expected_size_)
  , local_prefix_size_(local_prefix_size_)
{}

const std::int32_t setFileGenerationProgress::ID;

void setFileGenerationProgress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setFileGenerationProgress");
    s.store_field("generation_id", generation_id_);
    s.store_field("expected_size", expected_size_);
    s.store_field("local_prefix_size", local_prefix_size_);
    s.store_class_end();
  }
}

setGiftResalePrice::setGiftResalePrice()
  : received_gift_id_()
  , price_()
{}

setGiftResalePrice::setGiftResalePrice(string const &received_gift_id_, object_ptr<GiftResalePrice> &&price_)
  : received_gift_id_(received_gift_id_)
  , price_(std::move(price_))
{}

const std::int32_t setGiftResalePrice::ID;

void setGiftResalePrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGiftResalePrice");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

shareUsersWithBot::shareUsersWithBot()
  : source_()
  , button_id_()
  , shared_user_ids_()
  , only_check_()
{}

shareUsersWithBot::shareUsersWithBot(object_ptr<KeyboardButtonSource> &&source_, int32 button_id_, array<int53> &&shared_user_ids_, bool only_check_)
  : source_(std::move(source_))
  , button_id_(button_id_)
  , shared_user_ids_(std::move(shared_user_ids_))
  , only_check_(only_check_)
{}

const std::int32_t shareUsersWithBot::ID;

void shareUsersWithBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shareUsersWithBot");
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("button_id", button_id_);
    { s.store_vector_begin("shared_user_ids", shared_user_ids_.size()); for (const auto &_value : shared_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("only_check", only_check_);
    s.store_class_end();
  }
}

suggestUserBirthdate::suggestUserBirthdate()
  : user_id_()
  , birthdate_()
{}

suggestUserBirthdate::suggestUserBirthdate(int53 user_id_, object_ptr<birthdate> &&birthdate_)
  : user_id_(user_id_)
  , birthdate_(std::move(birthdate_))
{}

const std::int32_t suggestUserBirthdate::ID;

void suggestUserBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestUserBirthdate");
    s.store_field("user_id", user_id_);
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_class_end();
  }
}

summarizeMessage::summarizeMessage()
  : chat_id_()
  , message_id_()
  , translate_to_language_code_()
  , tone_()
{}

summarizeMessage::summarizeMessage(int53 chat_id_, int53 message_id_, string const &translate_to_language_code_, string const &tone_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , translate_to_language_code_(translate_to_language_code_)
  , tone_(tone_)
{}

const std::int32_t summarizeMessage::ID;

void summarizeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "summarizeMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("translate_to_language_code", translate_to_language_code_);
    s.store_field("tone", tone_);
    s.store_class_end();
  }
}

testCallBytes::testCallBytes()
  : x_()
{}

testCallBytes::testCallBytes(bytes const &x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallBytes::ID;

void testCallBytes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallBytes");
    s.store_bytes_field("x", x_);
    s.store_class_end();
  }
}

toggleBotCanManageEmojiStatus::toggleBotCanManageEmojiStatus()
  : bot_user_id_()
  , can_manage_emoji_status_()
{}

toggleBotCanManageEmojiStatus::toggleBotCanManageEmojiStatus(int53 bot_user_id_, bool can_manage_emoji_status_)
  : bot_user_id_(bot_user_id_)
  , can_manage_emoji_status_(can_manage_emoji_status_)
{}

const std::int32_t toggleBotCanManageEmojiStatus::ID;

void toggleBotCanManageEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleBotCanManageEmojiStatus");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("can_manage_emoji_status", can_manage_emoji_status_);
    s.store_class_end();
  }
}

toggleDirectMessagesChatTopicCanSendUnpaidMessages::toggleDirectMessagesChatTopicCanSendUnpaidMessages()
  : chat_id_()
  , topic_id_()
  , can_send_unpaid_messages_()
  , refund_payments_()
{}

toggleDirectMessagesChatTopicCanSendUnpaidMessages::toggleDirectMessagesChatTopicCanSendUnpaidMessages(int53 chat_id_, int53 topic_id_, bool can_send_unpaid_messages_, bool refund_payments_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
  , can_send_unpaid_messages_(can_send_unpaid_messages_)
  , refund_payments_(refund_payments_)
{}

const std::int32_t toggleDirectMessagesChatTopicCanSendUnpaidMessages::ID;

void toggleDirectMessagesChatTopicCanSendUnpaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleDirectMessagesChatTopicCanSendUnpaidMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_field("can_send_unpaid_messages", can_send_unpaid_messages_);
    s.store_field("refund_payments", refund_payments_);
    s.store_class_end();
  }
}

toggleSessionCanAcceptSecretChats::toggleSessionCanAcceptSecretChats()
  : session_id_()
  , can_accept_secret_chats_()
{}

toggleSessionCanAcceptSecretChats::toggleSessionCanAcceptSecretChats(int64 session_id_, bool can_accept_secret_chats_)
  : session_id_(session_id_)
  , can_accept_secret_chats_(can_accept_secret_chats_)
{}

const std::int32_t toggleSessionCanAcceptSecretChats::ID;

void toggleSessionCanAcceptSecretChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSessionCanAcceptSecretChats");
    s.store_field("session_id", session_id_);
    s.store_field("can_accept_secret_chats", can_accept_secret_chats_);
    s.store_class_end();
  }
}

toggleSupergroupIsForum::toggleSupergroupIsForum()
  : supergroup_id_()
  , is_forum_()
  , has_forum_tabs_()
  , has_forum_sidebar_()
{}

toggleSupergroupIsForum::toggleSupergroupIsForum(int53 supergroup_id_, bool is_forum_, bool has_forum_tabs_, bool has_forum_sidebar_)
  : supergroup_id_(supergroup_id_)
  , is_forum_(is_forum_)
  , has_forum_tabs_(has_forum_tabs_)
  , has_forum_sidebar_(has_forum_sidebar_)
{}

const std::int32_t toggleSupergroupIsForum::ID;

void toggleSupergroupIsForum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupIsForum");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("is_forum", is_forum_);
    s.store_field("has_forum_tabs", has_forum_tabs_);
    s.store_field("has_forum_sidebar", has_forum_sidebar_);
    s.store_class_end();
  }
}

toggleSupergroupJoinByRequest::toggleSupergroupJoinByRequest()
  : supergroup_id_()
  , join_by_request_()
  , guard_bot_user_id_()
  , apply_to_invite_links_()
{}

toggleSupergroupJoinByRequest::toggleSupergroupJoinByRequest(int53 supergroup_id_, bool join_by_request_, int53 guard_bot_user_id_, bool apply_to_invite_links_)
  : supergroup_id_(supergroup_id_)
  , join_by_request_(join_by_request_)
  , guard_bot_user_id_(guard_bot_user_id_)
  , apply_to_invite_links_(apply_to_invite_links_)
{}

const std::int32_t toggleSupergroupJoinByRequest::ID;

void toggleSupergroupJoinByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupJoinByRequest");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("join_by_request", join_by_request_);
    s.store_field("guard_bot_user_id", guard_bot_user_id_);
    s.store_field("apply_to_invite_links", apply_to_invite_links_);
    s.store_class_end();
  }
}

unpinAllDirectMessagesChatTopicMessages::unpinAllDirectMessagesChatTopicMessages()
  : chat_id_()
  , topic_id_()
{}

unpinAllDirectMessagesChatTopicMessages::unpinAllDirectMessagesChatTopicMessages(int53 chat_id_, int53 topic_id_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
{}

const std::int32_t unpinAllDirectMessagesChatTopicMessages::ID;

void unpinAllDirectMessagesChatTopicMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unpinAllDirectMessagesChatTopicMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

upgradeBasicGroupChatToSupergroupChat::upgradeBasicGroupChatToSupergroupChat()
  : chat_id_()
{}

upgradeBasicGroupChatToSupergroupChat::upgradeBasicGroupChatToSupergroupChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t upgradeBasicGroupChatToSupergroupChat::ID;

void upgradeBasicGroupChatToSupergroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradeBasicGroupChatToSupergroupChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

uploadStickerFile::uploadStickerFile()
  : user_id_()
  , sticker_format_()
  , sticker_()
{}

uploadStickerFile::uploadStickerFile(int53 user_id_, object_ptr<StickerFormat> &&sticker_format_, object_ptr<InputFile> &&sticker_)
  : user_id_(user_id_)
  , sticker_format_(std::move(sticker_format_))
  , sticker_(std::move(sticker_))
{}

const std::int32_t uploadStickerFile::ID;

void uploadStickerFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "uploadStickerFile");
    s.store_field("user_id", user_id_);
    s.store_object_field("sticker_format", static_cast<const BaseObject *>(sticker_format_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
