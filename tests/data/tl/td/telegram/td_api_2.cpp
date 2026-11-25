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


activeStoryStateLive::activeStoryStateLive()
  : story_id_()
{}

activeStoryStateLive::activeStoryStateLive(int32 story_id_)
  : story_id_(story_id_)
{}

const std::int32_t activeStoryStateLive::ID;

void activeStoryStateLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "activeStoryStateLive");
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

activeStoryStateUnread::activeStoryStateUnread() {
}

const std::int32_t activeStoryStateUnread::ID;

void activeStoryStateUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "activeStoryStateUnread");
    s.store_class_end();
  }
}

activeStoryStateRead::activeStoryStateRead() {
}

const std::int32_t activeStoryStateRead::ID;

void activeStoryStateRead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "activeStoryStateRead");
    s.store_class_end();
  }
}

archiveChatListSettings::archiveChatListSettings()
  : archive_and_mute_new_chats_from_unknown_users_()
  , keep_unmuted_chats_archived_()
  , keep_chats_from_folders_archived_()
{}

archiveChatListSettings::archiveChatListSettings(bool archive_and_mute_new_chats_from_unknown_users_, bool keep_unmuted_chats_archived_, bool keep_chats_from_folders_archived_)
  : archive_and_mute_new_chats_from_unknown_users_(archive_and_mute_new_chats_from_unknown_users_)
  , keep_unmuted_chats_archived_(keep_unmuted_chats_archived_)
  , keep_chats_from_folders_archived_(keep_chats_from_folders_archived_)
{}

const std::int32_t archiveChatListSettings::ID;

void archiveChatListSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "archiveChatListSettings");
    s.store_field("archive_and_mute_new_chats_from_unknown_users", archive_and_mute_new_chats_from_unknown_users_);
    s.store_field("keep_unmuted_chats_archived", keep_unmuted_chats_archived_);
    s.store_field("keep_chats_from_folders_archived", keep_chats_from_folders_archived_);
    s.store_class_end();
  }
}

audio::audio()
  : duration_()
  , title_()
  , performer_()
  , file_name_()
  , mime_type_()
  , album_cover_minithumbnail_()
  , album_cover_thumbnail_()
  , external_album_covers_()
  , audio_()
{}

audio::audio(int32 duration_, string const &title_, string const &performer_, string const &file_name_, string const &mime_type_, object_ptr<minithumbnail> &&album_cover_minithumbnail_, object_ptr<thumbnail> &&album_cover_thumbnail_, array<object_ptr<thumbnail>> &&external_album_covers_, object_ptr<file> &&audio_)
  : duration_(duration_)
  , title_(title_)
  , performer_(performer_)
  , file_name_(file_name_)
  , mime_type_(mime_type_)
  , album_cover_minithumbnail_(std::move(album_cover_minithumbnail_))
  , album_cover_thumbnail_(std::move(album_cover_thumbnail_))
  , external_album_covers_(std::move(external_album_covers_))
  , audio_(std::move(audio_))
{}

const std::int32_t audio::ID;

void audio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "audio");
    s.store_field("duration", duration_);
    s.store_field("title", title_);
    s.store_field("performer", performer_);
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_object_field("album_cover_minithumbnail", static_cast<const BaseObject *>(album_cover_minithumbnail_.get()));
    s.store_object_field("album_cover_thumbnail", static_cast<const BaseObject *>(album_cover_thumbnail_.get()));
    { s.store_vector_begin("external_album_covers", external_album_covers_.size()); for (const auto &_value : external_album_covers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_class_end();
  }
}

availableReaction::availableReaction()
  : type_()
  , needs_premium_()
{}

availableReaction::availableReaction(object_ptr<ReactionType> &&type_, bool needs_premium_)
  : type_(std::move(type_))
  , needs_premium_(needs_premium_)
{}

const std::int32_t availableReaction::ID;

void availableReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableReaction");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("needs_premium", needs_premium_);
    s.store_class_end();
  }
}

background::background()
  : id_()
  , is_default_()
  , is_dark_()
  , name_()
  , document_()
  , type_()
{}

background::background(int64 id_, bool is_default_, bool is_dark_, string const &name_, object_ptr<document> &&document_, object_ptr<BackgroundType> &&type_)
  : id_(id_)
  , is_default_(is_default_)
  , is_dark_(is_dark_)
  , name_(name_)
  , document_(std::move(document_))
  , type_(std::move(type_))
{}

const std::int32_t background::ID;

void background::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "background");
    s.store_field("id", id_);
    s.store_field("is_default", is_default_);
    s.store_field("is_dark", is_dark_);
    s.store_field("name", name_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

basicGroupFullInfo::basicGroupFullInfo()
  : photo_()
  , description_()
  , creator_user_id_()
  , members_()
  , can_hide_members_()
  , can_toggle_aggressive_anti_spam_()
  , invite_link_()
  , bot_commands_()
{}

basicGroupFullInfo::basicGroupFullInfo(object_ptr<chatPhoto> &&photo_, string const &description_, int53 creator_user_id_, array<object_ptr<chatMember>> &&members_, bool can_hide_members_, bool can_toggle_aggressive_anti_spam_, object_ptr<chatInviteLink> &&invite_link_, array<object_ptr<botCommands>> &&bot_commands_)
  : photo_(std::move(photo_))
  , description_(description_)
  , creator_user_id_(creator_user_id_)
  , members_(std::move(members_))
  , can_hide_members_(can_hide_members_)
  , can_toggle_aggressive_anti_spam_(can_toggle_aggressive_anti_spam_)
  , invite_link_(std::move(invite_link_))
  , bot_commands_(std::move(bot_commands_))
{}

const std::int32_t basicGroupFullInfo::ID;

void basicGroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "basicGroupFullInfo");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("description", description_);
    s.store_field("creator_user_id", creator_user_id_);
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("can_hide_members", can_hide_members_);
    s.store_field("can_toggle_aggressive_anti_spam", can_toggle_aggressive_anti_spam_);
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    { s.store_vector_begin("bot_commands", bot_commands_.size()); for (const auto &_value : bot_commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

botCallbackQueryModeDefault::botCallbackQueryModeDefault() {
}

const std::int32_t botCallbackQueryModeDefault::ID;

void botCallbackQueryModeDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCallbackQueryModeDefault");
    s.store_class_end();
  }
}

botCallbackQueryModeAuto::botCallbackQueryModeAuto() {
}

const std::int32_t botCallbackQueryModeAuto::ID;

void botCallbackQueryModeAuto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCallbackQueryModeAuto");
    s.store_class_end();
  }
}

botCallbackQueryModeInline::botCallbackQueryModeInline() {
}

const std::int32_t botCallbackQueryModeInline::ID;

void botCallbackQueryModeInline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCallbackQueryModeInline");
    s.store_class_end();
  }
}

botCommands::botCommands()
  : bot_user_id_()
  , commands_()
{}

botCommands::botCommands(int53 bot_user_id_, array<object_ptr<botCommand>> &&commands_)
  : bot_user_id_(bot_user_id_)
  , commands_(std::move(commands_))
{}

const std::int32_t botCommands::ID;

void botCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommands");
    s.store_field("bot_user_id", bot_user_id_);
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessChatLinks::businessChatLinks()
  : links_()
{}

businessChatLinks::businessChatLinks(array<object_ptr<businessChatLink>> &&links_)
  : links_(std::move(links_))
{}

const std::int32_t businessChatLinks::ID;

void businessChatLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessChatLinks");
    { s.store_vector_begin("links", links_.size()); for (const auto &_value : links_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessFeaturePromotionAnimation::businessFeaturePromotionAnimation()
  : feature_()
  , animation_()
{}

businessFeaturePromotionAnimation::businessFeaturePromotionAnimation(object_ptr<BusinessFeature> &&feature_, object_ptr<animation> &&animation_)
  : feature_(std::move(feature_))
  , animation_(std::move(animation_))
{}

const std::int32_t businessFeaturePromotionAnimation::ID;

void businessFeaturePromotionAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeaturePromotionAnimation");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

businessGreetingMessageSettings::businessGreetingMessageSettings()
  : shortcut_id_()
  , recipients_()
  , inactivity_days_()
{}

businessGreetingMessageSettings::businessGreetingMessageSettings(int32 shortcut_id_, object_ptr<businessRecipients> &&recipients_, int32 inactivity_days_)
  : shortcut_id_(shortcut_id_)
  , recipients_(std::move(recipients_))
  , inactivity_days_(inactivity_days_)
{}

const std::int32_t businessGreetingMessageSettings::ID;

void businessGreetingMessageSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessGreetingMessageSettings");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_field("inactivity_days", inactivity_days_);
    s.store_class_end();
  }
}

businessStartPage::businessStartPage()
  : title_()
  , message_()
  , sticker_()
{}

businessStartPage::businessStartPage(string const &title_, string const &message_, object_ptr<sticker> &&sticker_)
  : title_(title_)
  , message_(message_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t businessStartPage::ID;

void businessStartPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessStartPage");
    s.store_field("title", title_);
    s.store_field("message", message_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

chatBoost::chatBoost()
  : id_()
  , count_()
  , source_()
  , start_date_()
  , expiration_date_()
{}

chatBoost::chatBoost(string const &id_, int32 count_, object_ptr<ChatBoostSource> &&source_, int32 start_date_, int32 expiration_date_)
  : id_(id_)
  , count_(count_)
  , source_(std::move(source_))
  , start_date_(start_date_)
  , expiration_date_(expiration_date_)
{}

const std::int32_t chatBoost::ID;

void chatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoost");
    s.store_field("id", id_);
    s.store_field("count", count_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("start_date", start_date_);
    s.store_field("expiration_date", expiration_date_);
    s.store_class_end();
  }
}

chatBoostSlot::chatBoostSlot()
  : slot_id_()
  , currently_boosted_chat_id_()
  , start_date_()
  , expiration_date_()
  , cooldown_until_date_()
{}

chatBoostSlot::chatBoostSlot(int32 slot_id_, int53 currently_boosted_chat_id_, int32 start_date_, int32 expiration_date_, int32 cooldown_until_date_)
  : slot_id_(slot_id_)
  , currently_boosted_chat_id_(currently_boosted_chat_id_)
  , start_date_(start_date_)
  , expiration_date_(expiration_date_)
  , cooldown_until_date_(cooldown_until_date_)
{}

const std::int32_t chatBoostSlot::ID;

void chatBoostSlot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostSlot");
    s.store_field("slot_id", slot_id_);
    s.store_field("currently_boosted_chat_id", currently_boosted_chat_id_);
    s.store_field("start_date", start_date_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("cooldown_until_date", cooldown_until_date_);
    s.store_class_end();
  }
}

chatFolderIcon::chatFolderIcon()
  : name_()
{}

chatFolderIcon::chatFolderIcon(string const &name_)
  : name_(name_)
{}

const std::int32_t chatFolderIcon::ID;

void chatFolderIcon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderIcon");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

chatMembersFilterContacts::chatMembersFilterContacts() {
}

const std::int32_t chatMembersFilterContacts::ID;

void chatMembersFilterContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterContacts");
    s.store_class_end();
  }
}

chatMembersFilterAdministrators::chatMembersFilterAdministrators() {
}

const std::int32_t chatMembersFilterAdministrators::ID;

void chatMembersFilterAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterAdministrators");
    s.store_class_end();
  }
}

chatMembersFilterMembers::chatMembersFilterMembers() {
}

const std::int32_t chatMembersFilterMembers::ID;

void chatMembersFilterMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterMembers");
    s.store_class_end();
  }
}

chatMembersFilterMention::chatMembersFilterMention()
  : topic_id_()
{}

chatMembersFilterMention::chatMembersFilterMention(object_ptr<MessageTopic> &&topic_id_)
  : topic_id_(std::move(topic_id_))
{}

const std::int32_t chatMembersFilterMention::ID;

void chatMembersFilterMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterMention");
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_class_end();
  }
}

chatMembersFilterRestricted::chatMembersFilterRestricted() {
}

const std::int32_t chatMembersFilterRestricted::ID;

void chatMembersFilterRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterRestricted");
    s.store_class_end();
  }
}

chatMembersFilterBanned::chatMembersFilterBanned() {
}

const std::int32_t chatMembersFilterBanned::ID;

void chatMembersFilterBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterBanned");
    s.store_class_end();
  }
}

chatMembersFilterBots::chatMembersFilterBots() {
}

const std::int32_t chatMembersFilterBots::ID;

void chatMembersFilterBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterBots");
    s.store_class_end();
  }
}

connectedAffiliateProgram::connectedAffiliateProgram()
  : url_()
  , bot_user_id_()
  , parameters_()
  , connection_date_()
  , is_disconnected_()
  , user_count_()
  , revenue_star_count_()
{}

connectedAffiliateProgram::connectedAffiliateProgram(string const &url_, int53 bot_user_id_, object_ptr<affiliateProgramParameters> &&parameters_, int32 connection_date_, bool is_disconnected_, int64 user_count_, int53 revenue_star_count_)
  : url_(url_)
  , bot_user_id_(bot_user_id_)
  , parameters_(std::move(parameters_))
  , connection_date_(connection_date_)
  , is_disconnected_(is_disconnected_)
  , user_count_(user_count_)
  , revenue_star_count_(revenue_star_count_)
{}

const std::int32_t connectedAffiliateProgram::ID;

void connectedAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedAffiliateProgram");
    s.store_field("url", url_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("connection_date", connection_date_);
    s.store_field("is_disconnected", is_disconnected_);
    s.store_field("user_count", user_count_);
    s.store_field("revenue_star_count", revenue_star_count_);
    s.store_class_end();
  }
}

currencies::currencies()
  : currencies_()
{}

currencies::currencies(array<string> &&currencies_)
  : currencies_(std::move(currencies_))
{}

const std::int32_t currencies::ID;

void currencies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "currencies");
    { s.store_vector_begin("currencies", currencies_.size()); for (const auto &_value : currencies_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

currentWeather::currentWeather()
  : temperature_()
  , emoji_()
{}

currentWeather::currentWeather(double temperature_, string const &emoji_)
  : temperature_(temperature_)
  , emoji_(emoji_)
{}

const std::int32_t currentWeather::ID;

void currentWeather::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "currentWeather");
    s.store_field("temperature", temperature_);
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

diffEntity::diffEntity()
  : offset_()
  , length_()
  , type_()
{}

diffEntity::diffEntity(int32 offset_, int32 length_, object_ptr<DiffEntityType> &&type_)
  : offset_(offset_)
  , length_(length_)
  , type_(std::move(type_))
{}

const std::int32_t diffEntity::ID;

void diffEntity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diffEntity");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

document::document()
  : file_name_()
  , mime_type_()
  , minithumbnail_()
  , thumbnail_()
  , document_()
{}

document::document(string const &file_name_, string const &mime_type_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&document_)
  : file_name_(file_name_)
  , mime_type_(mime_type_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , document_(std::move(document_))
{}

const std::int32_t document::ID;

void document::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "document");
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_class_end();
  }
}

emojiKeywords::emojiKeywords()
  : emoji_keywords_()
{}

emojiKeywords::emojiKeywords(array<object_ptr<emojiKeyword>> &&emoji_keywords_)
  : emoji_keywords_(std::move(emoji_keywords_))
{}

const std::int32_t emojiKeywords::ID;

void emojiKeywords::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiKeywords");
    { s.store_vector_begin("emoji_keywords", emoji_keywords_.size()); for (const auto &_value : emoji_keywords_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

emojis::emojis()
  : emojis_()
{}

emojis::emojis(array<string> &&emojis_)
  : emojis_(std::move(emojis_))
{}

const std::int32_t emojis::ID;

void emojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojis");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

error::error()
  : code_()
  , message_()
{}

error::error(int32 code_, string const &message_)
  : code_(code_)
  , message_(message_)
{}

const std::int32_t error::ID;

void error::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "error");
    s.store_field("code", code_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

fileDownload::fileDownload()
  : file_id_()
  , message_()
  , add_date_()
  , complete_date_()
  , is_paused_()
{}

fileDownload::fileDownload(int32 file_id_, object_ptr<message> &&message_, int32 add_date_, int32 complete_date_, bool is_paused_)
  : file_id_(file_id_)
  , message_(std::move(message_))
  , add_date_(add_date_)
  , complete_date_(complete_date_)
  , is_paused_(is_paused_)
{}

const std::int32_t fileDownload::ID;

void fileDownload::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileDownload");
    s.store_field("file_id", file_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("add_date", add_date_);
    s.store_field("complete_date", complete_date_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

firebaseAuthenticationSettingsAndroid::firebaseAuthenticationSettingsAndroid() {
}

const std::int32_t firebaseAuthenticationSettingsAndroid::ID;

void firebaseAuthenticationSettingsAndroid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "firebaseAuthenticationSettingsAndroid");
    s.store_class_end();
  }
}

firebaseAuthenticationSettingsIos::firebaseAuthenticationSettingsIos()
  : device_token_()
  , is_app_sandbox_()
{}

firebaseAuthenticationSettingsIos::firebaseAuthenticationSettingsIos(string const &device_token_, bool is_app_sandbox_)
  : device_token_(device_token_)
  , is_app_sandbox_(is_app_sandbox_)
{}

const std::int32_t firebaseAuthenticationSettingsIos::ID;

void firebaseAuthenticationSettingsIos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "firebaseAuthenticationSettingsIos");
    s.store_field("device_token", "[REDACTED]");
    s.store_field("is_app_sandbox", is_app_sandbox_);
    s.store_class_end();
  }
}

forumTopic::forumTopic()
  : info_()
  , last_message_()
  , order_()
  , is_pinned_()
  , unread_count_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , unread_mention_count_()
  , unread_reaction_count_()
  , unread_poll_vote_count_()
  , notification_settings_()
  , draft_message_()
{}

forumTopic::forumTopic(object_ptr<forumTopicInfo> &&info_, object_ptr<message> &&last_message_, int64 order_, bool is_pinned_, int32 unread_count_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int32 unread_mention_count_, int32 unread_reaction_count_, int32 unread_poll_vote_count_, object_ptr<chatNotificationSettings> &&notification_settings_, object_ptr<draftMessage> &&draft_message_)
  : info_(std::move(info_))
  , last_message_(std::move(last_message_))
  , order_(order_)
  , is_pinned_(is_pinned_)
  , unread_count_(unread_count_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , unread_mention_count_(unread_mention_count_)
  , unread_reaction_count_(unread_reaction_count_)
  , unread_poll_vote_count_(unread_poll_vote_count_)
  , notification_settings_(std::move(notification_settings_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t forumTopic::ID;

void forumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopic");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    s.store_field("order", order_);
    s.store_field("is_pinned", is_pinned_);
    s.store_field("unread_count", unread_count_);
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

forumTopicIcon::forumTopicIcon()
  : color_()
  , custom_emoji_id_()
{}

forumTopicIcon::forumTopicIcon(int32 color_, int64 custom_emoji_id_)
  : color_(color_)
  , custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t forumTopicIcon::ID;

void forumTopicIcon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopicIcon");
    s.store_field("color", color_);
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

gameHighScore::gameHighScore()
  : position_()
  , user_id_()
  , score_()
{}

gameHighScore::gameHighScore(int32 position_, int53 user_id_, int32 score_)
  : position_(position_)
  , user_id_(user_id_)
  , score_(score_)
{}

const std::int32_t gameHighScore::ID;

void gameHighScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "gameHighScore");
    s.store_field("position", position_);
    s.store_field("user_id", user_id_);
    s.store_field("score", score_);
    s.store_class_end();
  }
}

giftChatTheme::giftChatTheme()
  : gift_()
  , light_settings_()
  , dark_settings_()
{}

giftChatTheme::giftChatTheme(object_ptr<upgradedGift> &&gift_, object_ptr<themeSettings> &&light_settings_, object_ptr<themeSettings> &&dark_settings_)
  : gift_(std::move(gift_))
  , light_settings_(std::move(light_settings_))
  , dark_settings_(std::move(dark_settings_))
{}

const std::int32_t giftChatTheme::ID;

void giftChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftChatTheme");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("light_settings", static_cast<const BaseObject *>(light_settings_.get()));
    s.store_object_field("dark_settings", static_cast<const BaseObject *>(dark_settings_.get()));
    s.store_class_end();
  }
}

giftUpgradeVariants::giftUpgradeVariants()
  : models_()
  , symbols_()
  , backdrops_()
{}

giftUpgradeVariants::giftUpgradeVariants(array<object_ptr<upgradedGiftModel>> &&models_, array<object_ptr<upgradedGiftSymbol>> &&symbols_, array<object_ptr<upgradedGiftBackdrop>> &&backdrops_)
  : models_(std::move(models_))
  , symbols_(std::move(symbols_))
  , backdrops_(std::move(backdrops_))
{}

const std::int32_t giftUpgradeVariants::ID;

void giftUpgradeVariants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftUpgradeVariants");
    { s.store_vector_begin("models", models_.size()); for (const auto &_value : models_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("symbols", symbols_.size()); for (const auto &_value : symbols_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("backdrops", backdrops_.size()); for (const auto &_value : backdrops_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

giftsForCrafting::giftsForCrafting()
  : total_count_()
  , gifts_()
  , attribute_persistence_probabilities_()
  , next_offset_()
{}

giftsForCrafting::giftsForCrafting(int32 total_count_, array<object_ptr<receivedGift>> &&gifts_, array<object_ptr<attributeCraftPersistenceProbability>> &&attribute_persistence_probabilities_, string const &next_offset_)
  : total_count_(total_count_)
  , gifts_(std::move(gifts_))
  , attribute_persistence_probabilities_(std::move(attribute_persistence_probabilities_))
  , next_offset_(next_offset_)
{}

const std::int32_t giftsForCrafting::ID;

void giftsForCrafting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftsForCrafting");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("attribute_persistence_probabilities", attribute_persistence_probabilities_.size()); for (const auto &_value : attribute_persistence_probabilities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

giveawayInfoOngoing::giveawayInfoOngoing()
  : creation_date_()
  , status_()
  , is_ended_()
{}

giveawayInfoOngoing::giveawayInfoOngoing(int32 creation_date_, object_ptr<GiveawayParticipantStatus> &&status_, bool is_ended_)
  : creation_date_(creation_date_)
  , status_(std::move(status_))
  , is_ended_(is_ended_)
{}

const std::int32_t giveawayInfoOngoing::ID;

void giveawayInfoOngoing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayInfoOngoing");
    s.store_field("creation_date", creation_date_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("is_ended", is_ended_);
    s.store_class_end();
  }
}

giveawayInfoCompleted::giveawayInfoCompleted()
  : creation_date_()
  , actual_winners_selection_date_()
  , was_refunded_()
  , is_winner_()
  , winner_count_()
  , activation_count_()
  , gift_code_()
  , won_star_count_()
{}

giveawayInfoCompleted::giveawayInfoCompleted(int32 creation_date_, int32 actual_winners_selection_date_, bool was_refunded_, bool is_winner_, int32 winner_count_, int32 activation_count_, string const &gift_code_, int53 won_star_count_)
  : creation_date_(creation_date_)
  , actual_winners_selection_date_(actual_winners_selection_date_)
  , was_refunded_(was_refunded_)
  , is_winner_(is_winner_)
  , winner_count_(winner_count_)
  , activation_count_(activation_count_)
  , gift_code_(gift_code_)
  , won_star_count_(won_star_count_)
{}

const std::int32_t giveawayInfoCompleted::ID;

void giveawayInfoCompleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayInfoCompleted");
    s.store_field("creation_date", creation_date_);
    s.store_field("actual_winners_selection_date", actual_winners_selection_date_);
    s.store_field("was_refunded", was_refunded_);
    s.store_field("is_winner", is_winner_);
    s.store_field("winner_count", winner_count_);
    s.store_field("activation_count", activation_count_);
    s.store_field("gift_code", gift_code_);
    s.store_field("won_star_count", won_star_count_);
    s.store_class_end();
  }
}

giveawayParameters::giveawayParameters()
  : boosted_chat_id_()
  , additional_chat_ids_()
  , winners_selection_date_()
  , only_new_members_()
  , has_public_winners_()
  , country_codes_()
  , prize_description_()
{}

giveawayParameters::giveawayParameters(int53 boosted_chat_id_, array<int53> &&additional_chat_ids_, int32 winners_selection_date_, bool only_new_members_, bool has_public_winners_, array<string> &&country_codes_, string const &prize_description_)
  : boosted_chat_id_(boosted_chat_id_)
  , additional_chat_ids_(std::move(additional_chat_ids_))
  , winners_selection_date_(winners_selection_date_)
  , only_new_members_(only_new_members_)
  , has_public_winners_(has_public_winners_)
  , country_codes_(std::move(country_codes_))
  , prize_description_(prize_description_)
{}

const std::int32_t giveawayParameters::ID;

void giveawayParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParameters");
    s.store_field("boosted_chat_id", boosted_chat_id_);
    { s.store_vector_begin("additional_chat_ids", additional_chat_ids_.size()); for (const auto &_value : additional_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("winners_selection_date", winners_selection_date_);
    s.store_field("only_new_members", only_new_members_);
    s.store_field("has_public_winners", has_public_winners_);
    { s.store_vector_begin("country_codes", country_codes_.size()); for (const auto &_value : country_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("prize_description", prize_description_);
    s.store_class_end();
  }
}

groupCall::groupCall()
  : id_()
  , unique_id_()
  , title_()
  , invite_link_()
  , paid_message_star_count_()
  , scheduled_start_date_()
  , enabled_start_notification_()
  , is_active_()
  , is_video_chat_()
  , is_live_story_()
  , is_rtmp_stream_()
  , is_joined_()
  , need_rejoin_()
  , is_owned_()
  , can_be_managed_()
  , participant_count_()
  , has_hidden_listeners_()
  , loaded_all_participants_()
  , message_sender_id_()
  , recent_speakers_()
  , is_my_video_enabled_()
  , is_my_video_paused_()
  , can_enable_video_()
  , mute_new_participants_()
  , can_toggle_mute_new_participants_()
  , can_send_messages_()
  , are_messages_allowed_()
  , can_toggle_are_messages_allowed_()
  , can_delete_messages_()
  , record_duration_()
  , is_video_recorded_()
  , duration_()
{}

groupCall::groupCall(int32 id_, int64 unique_id_, string const &title_, string const &invite_link_, int53 paid_message_star_count_, int32 scheduled_start_date_, bool enabled_start_notification_, bool is_active_, bool is_video_chat_, bool is_live_story_, bool is_rtmp_stream_, bool is_joined_, bool need_rejoin_, bool is_owned_, bool can_be_managed_, int32 participant_count_, bool has_hidden_listeners_, bool loaded_all_participants_, object_ptr<MessageSender> &&message_sender_id_, array<object_ptr<groupCallRecentSpeaker>> &&recent_speakers_, bool is_my_video_enabled_, bool is_my_video_paused_, bool can_enable_video_, bool mute_new_participants_, bool can_toggle_mute_new_participants_, bool can_send_messages_, bool are_messages_allowed_, bool can_toggle_are_messages_allowed_, bool can_delete_messages_, int32 record_duration_, bool is_video_recorded_, int32 duration_)
  : id_(id_)
  , unique_id_(unique_id_)
  , title_(title_)
  , invite_link_(invite_link_)
  , paid_message_star_count_(paid_message_star_count_)
  , scheduled_start_date_(scheduled_start_date_)
  , enabled_start_notification_(enabled_start_notification_)
  , is_active_(is_active_)
  , is_video_chat_(is_video_chat_)
  , is_live_story_(is_live_story_)
  , is_rtmp_stream_(is_rtmp_stream_)
  , is_joined_(is_joined_)
  , need_rejoin_(need_rejoin_)
  , is_owned_(is_owned_)
  , can_be_managed_(can_be_managed_)
  , participant_count_(participant_count_)
  , has_hidden_listeners_(has_hidden_listeners_)
  , loaded_all_participants_(loaded_all_participants_)
  , message_sender_id_(std::move(message_sender_id_))
  , recent_speakers_(std::move(recent_speakers_))
  , is_my_video_enabled_(is_my_video_enabled_)
  , is_my_video_paused_(is_my_video_paused_)
  , can_enable_video_(can_enable_video_)
  , mute_new_participants_(mute_new_participants_)
  , can_toggle_mute_new_participants_(can_toggle_mute_new_participants_)
  , can_send_messages_(can_send_messages_)
  , are_messages_allowed_(are_messages_allowed_)
  , can_toggle_are_messages_allowed_(can_toggle_are_messages_allowed_)
  , can_delete_messages_(can_delete_messages_)
  , record_duration_(record_duration_)
  , is_video_recorded_(is_video_recorded_)
  , duration_(duration_)
{}

const std::int32_t groupCall::ID;

void groupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCall");
    s.store_field("id", id_);
    s.store_field("unique_id", unique_id_);
    s.store_field("title", title_);
    s.store_field("invite_link", invite_link_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_field("scheduled_start_date", scheduled_start_date_);
    s.store_field("enabled_start_notification", enabled_start_notification_);
    s.store_field("is_active", is_active_);
    s.store_field("is_video_chat", is_video_chat_);
    s.store_field("is_live_story", is_live_story_);
    s.store_field("is_rtmp_stream", is_rtmp_stream_);
    s.store_field("is_joined", is_joined_);
    s.store_field("need_rejoin", need_rejoin_);
    s.store_field("is_owned", is_owned_);
    s.store_field("can_be_managed", can_be_managed_);
    s.store_field("participant_count", participant_count_);
    s.store_field("has_hidden_listeners", has_hidden_listeners_);
    s.store_field("loaded_all_participants", loaded_all_participants_);
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    { s.store_vector_begin("recent_speakers", recent_speakers_.size()); for (const auto &_value : recent_speakers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_my_video_enabled", is_my_video_enabled_);
    s.store_field("is_my_video_paused", is_my_video_paused_);
    s.store_field("can_enable_video", can_enable_video_);
    s.store_field("mute_new_participants", mute_new_participants_);
    s.store_field("can_toggle_mute_new_participants", can_toggle_mute_new_participants_);
    s.store_field("can_send_messages", can_send_messages_);
    s.store_field("are_messages_allowed", are_messages_allowed_);
    s.store_field("can_toggle_are_messages_allowed", can_toggle_are_messages_allowed_);
    s.store_field("can_delete_messages", can_delete_messages_);
    s.store_field("record_duration", record_duration_);
    s.store_field("is_video_recorded", is_video_recorded_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

groupCallParticipant::groupCallParticipant()
  : participant_id_()
  , audio_source_id_()
  , screen_sharing_audio_source_id_()
  , video_info_()
  , screen_sharing_video_info_()
  , bio_()
  , is_current_user_()
  , is_speaking_()
  , is_hand_raised_()
  , can_be_muted_for_all_users_()
  , can_be_unmuted_for_all_users_()
  , can_be_muted_for_current_user_()
  , can_be_unmuted_for_current_user_()
  , is_muted_for_all_users_()
  , is_muted_for_current_user_()
  , can_unmute_self_()
  , volume_level_()
  , order_()
{}

groupCallParticipant::groupCallParticipant(object_ptr<MessageSender> &&participant_id_, int32 audio_source_id_, int32 screen_sharing_audio_source_id_, object_ptr<groupCallParticipantVideoInfo> &&video_info_, object_ptr<groupCallParticipantVideoInfo> &&screen_sharing_video_info_, string const &bio_, bool is_current_user_, bool is_speaking_, bool is_hand_raised_, bool can_be_muted_for_all_users_, bool can_be_unmuted_for_all_users_, bool can_be_muted_for_current_user_, bool can_be_unmuted_for_current_user_, bool is_muted_for_all_users_, bool is_muted_for_current_user_, bool can_unmute_self_, int32 volume_level_, string const &order_)
  : participant_id_(std::move(participant_id_))
  , audio_source_id_(audio_source_id_)
  , screen_sharing_audio_source_id_(screen_sharing_audio_source_id_)
  , video_info_(std::move(video_info_))
  , screen_sharing_video_info_(std::move(screen_sharing_video_info_))
  , bio_(bio_)
  , is_current_user_(is_current_user_)
  , is_speaking_(is_speaking_)
  , is_hand_raised_(is_hand_raised_)
  , can_be_muted_for_all_users_(can_be_muted_for_all_users_)
  , can_be_unmuted_for_all_users_(can_be_unmuted_for_all_users_)
  , can_be_muted_for_current_user_(can_be_muted_for_current_user_)
  , can_be_unmuted_for_current_user_(can_be_unmuted_for_current_user_)
  , is_muted_for_all_users_(is_muted_for_all_users_)
  , is_muted_for_current_user_(is_muted_for_current_user_)
  , can_unmute_self_(can_unmute_self_)
  , volume_level_(volume_level_)
  , order_(order_)
{}

const std::int32_t groupCallParticipant::ID;

void groupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipant");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("audio_source_id", audio_source_id_);
    s.store_field("screen_sharing_audio_source_id", screen_sharing_audio_source_id_);
    s.store_object_field("video_info", static_cast<const BaseObject *>(video_info_.get()));
    s.store_object_field("screen_sharing_video_info", static_cast<const BaseObject *>(screen_sharing_video_info_.get()));
    s.store_field("bio", bio_);
    s.store_field("is_current_user", is_current_user_);
    s.store_field("is_speaking", is_speaking_);
    s.store_field("is_hand_raised", is_hand_raised_);
    s.store_field("can_be_muted_for_all_users", can_be_muted_for_all_users_);
    s.store_field("can_be_unmuted_for_all_users", can_be_unmuted_for_all_users_);
    s.store_field("can_be_muted_for_current_user", can_be_muted_for_current_user_);
    s.store_field("can_be_unmuted_for_current_user", can_be_unmuted_for_current_user_);
    s.store_field("is_muted_for_all_users", is_muted_for_all_users_);
    s.store_field("is_muted_for_current_user", is_muted_for_current_user_);
    s.store_field("can_unmute_self", can_unmute_self_);
    s.store_field("volume_level", volume_level_);
    s.store_field("order", order_);
    s.store_class_end();
  }
}

groupCallStreams::groupCallStreams()
  : streams_()
{}

groupCallStreams::groupCallStreams(array<object_ptr<groupCallStream>> &&streams_)
  : streams_(std::move(streams_))
{}

const std::int32_t groupCallStreams::ID;

void groupCallStreams::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallStreams");
    { s.store_vector_begin("streams", streams_.size()); for (const auto &_value : streams_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputAudio::inputAudio()
  : audio_()
  , album_cover_thumbnail_()
  , duration_()
  , title_()
  , performer_()
{}

inputAudio::inputAudio(object_ptr<InputFile> &&audio_, object_ptr<inputThumbnail> &&album_cover_thumbnail_, int32 duration_, string const &title_, string const &performer_)
  : audio_(std::move(audio_))
  , album_cover_thumbnail_(std::move(album_cover_thumbnail_))
  , duration_(duration_)
  , title_(title_)
  , performer_(performer_)
{}

const std::int32_t inputAudio::ID;

void inputAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("album_cover_thumbnail", static_cast<const BaseObject *>(album_cover_thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("title", title_);
    s.store_field("performer", performer_);
    s.store_class_end();
  }
}

inputBackgroundLocal::inputBackgroundLocal()
  : background_()
{}

inputBackgroundLocal::inputBackgroundLocal(object_ptr<InputFile> &&background_)
  : background_(std::move(background_))
{}

const std::int32_t inputBackgroundLocal::ID;

void inputBackgroundLocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBackgroundLocal");
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_class_end();
  }
}

inputBackgroundRemote::inputBackgroundRemote()
  : background_id_()
{}

inputBackgroundRemote::inputBackgroundRemote(int64 background_id_)
  : background_id_(background_id_)
{}

const std::int32_t inputBackgroundRemote::ID;

void inputBackgroundRemote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBackgroundRemote");
    s.store_field("background_id", background_id_);
    s.store_class_end();
  }
}

inputBackgroundPrevious::inputBackgroundPrevious()
  : message_id_()
{}

inputBackgroundPrevious::inputBackgroundPrevious(int53 message_id_)
  : message_id_(message_id_)
{}

const std::int32_t inputBackgroundPrevious::ID;

void inputBackgroundPrevious::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBackgroundPrevious");
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

inputBusinessStartPage::inputBusinessStartPage()
  : title_()
  , message_()
  , sticker_()
{}

inputBusinessStartPage::inputBusinessStartPage(string const &title_, string const &message_, object_ptr<InputFile> &&sticker_)
  : title_(title_)
  , message_(message_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t inputBusinessStartPage::ID;

void inputBusinessStartPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessStartPage");
    s.store_field("title", title_);
    s.store_field("message", message_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

inputChatThemeEmoji::inputChatThemeEmoji()
  : name_()
{}

inputChatThemeEmoji::inputChatThemeEmoji(string const &name_)
  : name_(name_)
{}

const std::int32_t inputChatThemeEmoji::ID;

void inputChatThemeEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatThemeEmoji");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

inputChatThemeGift::inputChatThemeGift()
  : name_()
{}

inputChatThemeGift::inputChatThemeGift(string const &name_)
  : name_(name_)
{}

const std::int32_t inputChatThemeGift::ID;

void inputChatThemeGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatThemeGift");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

inputIdentityDocument::inputIdentityDocument()
  : number_()
  , expiration_date_()
  , front_side_()
  , reverse_side_()
  , selfie_()
  , translation_()
{}

inputIdentityDocument::inputIdentityDocument(string const &number_, object_ptr<date> &&expiration_date_, object_ptr<InputFile> &&front_side_, object_ptr<InputFile> &&reverse_side_, object_ptr<InputFile> &&selfie_, array<object_ptr<InputFile>> &&translation_)
  : number_(number_)
  , expiration_date_(std::move(expiration_date_))
  , front_side_(std::move(front_side_))
  , reverse_side_(std::move(reverse_side_))
  , selfie_(std::move(selfie_))
  , translation_(std::move(translation_))
{}

const std::int32_t inputIdentityDocument::ID;

void inputIdentityDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputIdentityDocument");
    s.store_field("number", number_);
    s.store_object_field("expiration_date", static_cast<const BaseObject *>(expiration_date_.get()));
    s.store_object_field("front_side", static_cast<const BaseObject *>(front_side_.get()));
    s.store_object_field("reverse_side", static_cast<const BaseObject *>(reverse_side_.get()));
    s.store_object_field("selfie", static_cast<const BaseObject *>(selfie_.get()));
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputStoryAreas::inputStoryAreas()
  : areas_()
{}

inputStoryAreas::inputStoryAreas(array<object_ptr<inputStoryArea>> &&areas_)
  : areas_(std::move(areas_))
{}

const std::int32_t inputStoryAreas::ID;

void inputStoryAreas::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreas");
    { s.store_vector_begin("areas", areas_.size()); for (const auto &_value : areas_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

keyboardButtonTypeText::keyboardButtonTypeText() {
}

const std::int32_t keyboardButtonTypeText::ID;

void keyboardButtonTypeText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeText");
    s.store_class_end();
  }
}

keyboardButtonTypeRequestPhoneNumber::keyboardButtonTypeRequestPhoneNumber() {
}

const std::int32_t keyboardButtonTypeRequestPhoneNumber::ID;

void keyboardButtonTypeRequestPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestPhoneNumber");
    s.store_class_end();
  }
}

keyboardButtonTypeRequestLocation::keyboardButtonTypeRequestLocation() {
}

const std::int32_t keyboardButtonTypeRequestLocation::ID;

void keyboardButtonTypeRequestLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestLocation");
    s.store_class_end();
  }
}

keyboardButtonTypeRequestPoll::keyboardButtonTypeRequestPoll()
  : force_regular_()
  , force_quiz_()
{}

keyboardButtonTypeRequestPoll::keyboardButtonTypeRequestPoll(bool force_regular_, bool force_quiz_)
  : force_regular_(force_regular_)
  , force_quiz_(force_quiz_)
{}

const std::int32_t keyboardButtonTypeRequestPoll::ID;

void keyboardButtonTypeRequestPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestPoll");
    s.store_field("force_regular", force_regular_);
    s.store_field("force_quiz", force_quiz_);
    s.store_class_end();
  }
}

keyboardButtonTypeRequestUsers::keyboardButtonTypeRequestUsers()
  : id_()
  , restrict_user_is_bot_()
  , user_is_bot_()
  , restrict_user_is_premium_()
  , user_is_premium_()
  , max_quantity_()
  , request_name_()
  , request_username_()
  , request_photo_()
{}

keyboardButtonTypeRequestUsers::keyboardButtonTypeRequestUsers(int32 id_, bool restrict_user_is_bot_, bool user_is_bot_, bool restrict_user_is_premium_, bool user_is_premium_, int32 max_quantity_, bool request_name_, bool request_username_, bool request_photo_)
  : id_(id_)
  , restrict_user_is_bot_(restrict_user_is_bot_)
  , user_is_bot_(user_is_bot_)
  , restrict_user_is_premium_(restrict_user_is_premium_)
  , user_is_premium_(user_is_premium_)
  , max_quantity_(max_quantity_)
  , request_name_(request_name_)
  , request_username_(request_username_)
  , request_photo_(request_photo_)
{}

const std::int32_t keyboardButtonTypeRequestUsers::ID;

void keyboardButtonTypeRequestUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestUsers");
    s.store_field("id", id_);
    s.store_field("restrict_user_is_bot", restrict_user_is_bot_);
    s.store_field("user_is_bot", user_is_bot_);
    s.store_field("restrict_user_is_premium", restrict_user_is_premium_);
    s.store_field("user_is_premium", user_is_premium_);
    s.store_field("max_quantity", max_quantity_);
    s.store_field("request_name", request_name_);
    s.store_field("request_username", request_username_);
    s.store_field("request_photo", request_photo_);
    s.store_class_end();
  }
}

keyboardButtonTypeRequestChat::keyboardButtonTypeRequestChat()
  : id_()
  , chat_is_channel_()
  , restrict_chat_is_forum_()
  , chat_is_forum_()
  , restrict_chat_has_username_()
  , chat_has_username_()
  , chat_is_created_()
  , user_administrator_rights_()
  , bot_administrator_rights_()
  , bot_is_member_()
  , request_title_()
  , request_username_()
  , request_photo_()
{}

keyboardButtonTypeRequestChat::keyboardButtonTypeRequestChat(int32 id_, bool chat_is_channel_, bool restrict_chat_is_forum_, bool chat_is_forum_, bool restrict_chat_has_username_, bool chat_has_username_, bool chat_is_created_, object_ptr<chatAdministratorRights> &&user_administrator_rights_, object_ptr<chatAdministratorRights> &&bot_administrator_rights_, bool bot_is_member_, bool request_title_, bool request_username_, bool request_photo_)
  : id_(id_)
  , chat_is_channel_(chat_is_channel_)
  , restrict_chat_is_forum_(restrict_chat_is_forum_)
  , chat_is_forum_(chat_is_forum_)
  , restrict_chat_has_username_(restrict_chat_has_username_)
  , chat_has_username_(chat_has_username_)
  , chat_is_created_(chat_is_created_)
  , user_administrator_rights_(std::move(user_administrator_rights_))
  , bot_administrator_rights_(std::move(bot_administrator_rights_))
  , bot_is_member_(bot_is_member_)
  , request_title_(request_title_)
  , request_username_(request_username_)
  , request_photo_(request_photo_)
{}

const std::int32_t keyboardButtonTypeRequestChat::ID;

void keyboardButtonTypeRequestChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestChat");
    s.store_field("id", id_);
    s.store_field("chat_is_channel", chat_is_channel_);
    s.store_field("restrict_chat_is_forum", restrict_chat_is_forum_);
    s.store_field("chat_is_forum", chat_is_forum_);
    s.store_field("restrict_chat_has_username", restrict_chat_has_username_);
    s.store_field("chat_has_username", chat_has_username_);
    s.store_field("chat_is_created", chat_is_created_);
    s.store_object_field("user_administrator_rights", static_cast<const BaseObject *>(user_administrator_rights_.get()));
    s.store_object_field("bot_administrator_rights", static_cast<const BaseObject *>(bot_administrator_rights_.get()));
    s.store_field("bot_is_member", bot_is_member_);
    s.store_field("request_title", request_title_);
    s.store_field("request_username", request_username_);
    s.store_field("request_photo", request_photo_);
    s.store_class_end();
  }
}

keyboardButtonTypeRequestManagedBot::keyboardButtonTypeRequestManagedBot()
  : id_()
  , suggested_name_()
  , suggested_username_()
{}

keyboardButtonTypeRequestManagedBot::keyboardButtonTypeRequestManagedBot(int32 id_, string const &suggested_name_, string const &suggested_username_)
  : id_(id_)
  , suggested_name_(suggested_name_)
  , suggested_username_(suggested_username_)
{}

const std::int32_t keyboardButtonTypeRequestManagedBot::ID;

void keyboardButtonTypeRequestManagedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestManagedBot");
    s.store_field("id", id_);
    s.store_field("suggested_name", suggested_name_);
    s.store_field("suggested_username", suggested_username_);
    s.store_class_end();
  }
}

keyboardButtonTypeWebApp::keyboardButtonTypeWebApp()
  : url_()
{}

keyboardButtonTypeWebApp::keyboardButtonTypeWebApp(string const &url_)
  : url_(url_)
{}

const std::int32_t keyboardButtonTypeWebApp::ID;

void keyboardButtonTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeWebApp");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

linkPreview::linkPreview()
  : url_()
  , display_url_()
  , site_name_()
  , title_()
  , description_()
  , author_()
  , type_()
  , has_large_media_()
  , show_large_media_()
  , show_media_above_description_()
  , skip_confirmation_()
  , show_above_text_()
  , instant_view_version_()
{}

linkPreview::linkPreview(string const &url_, string const &display_url_, string const &site_name_, string const &title_, object_ptr<formattedText> &&description_, string const &author_, object_ptr<LinkPreviewType> &&type_, bool has_large_media_, bool show_large_media_, bool show_media_above_description_, bool skip_confirmation_, bool show_above_text_, int32 instant_view_version_)
  : url_(url_)
  , display_url_(display_url_)
  , site_name_(site_name_)
  , title_(title_)
  , description_(std::move(description_))
  , author_(author_)
  , type_(std::move(type_))
  , has_large_media_(has_large_media_)
  , show_large_media_(show_large_media_)
  , show_media_above_description_(show_media_above_description_)
  , skip_confirmation_(skip_confirmation_)
  , show_above_text_(show_above_text_)
  , instant_view_version_(instant_view_version_)
{}

const std::int32_t linkPreview::ID;

void linkPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreview");
    s.store_field("url", url_);
    s.store_field("display_url", display_url_);
    s.store_field("site_name", site_name_);
    s.store_field("title", title_);
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_field("author", author_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("has_large_media", has_large_media_);
    s.store_field("show_large_media", show_large_media_);
    s.store_field("show_media_above_description", show_media_above_description_);
    s.store_field("skip_confirmation", skip_confirmation_);
    s.store_field("show_above_text", show_above_text_);
    s.store_field("instant_view_version", instant_view_version_);
    s.store_class_end();
  }
}

logStreamDefault::logStreamDefault() {
}

const std::int32_t logStreamDefault::ID;

void logStreamDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logStreamDefault");
    s.store_class_end();
  }
}

logStreamFile::logStreamFile()
  : path_()
  , max_file_size_()
  , redirect_stderr_()
{}

logStreamFile::logStreamFile(string const &path_, int53 max_file_size_, bool redirect_stderr_)
  : path_(path_)
  , max_file_size_(max_file_size_)
  , redirect_stderr_(redirect_stderr_)
{}

const std::int32_t logStreamFile::ID;

void logStreamFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logStreamFile");
    s.store_field("path", path_);
    s.store_field("max_file_size", max_file_size_);
    s.store_field("redirect_stderr", redirect_stderr_);
    s.store_class_end();
  }
}

logStreamEmpty::logStreamEmpty() {
}

const std::int32_t logStreamEmpty::ID;

void logStreamEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logStreamEmpty");
    s.store_class_end();
  }
}

messageEffectTypeEmojiReaction::messageEffectTypeEmojiReaction()
  : select_animation_()
  , effect_animation_()
{}

messageEffectTypeEmojiReaction::messageEffectTypeEmojiReaction(object_ptr<sticker> &&select_animation_, object_ptr<sticker> &&effect_animation_)
  : select_animation_(std::move(select_animation_))
  , effect_animation_(std::move(effect_animation_))
{}

const std::int32_t messageEffectTypeEmojiReaction::ID;

void messageEffectTypeEmojiReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEffectTypeEmojiReaction");
    s.store_object_field("select_animation", static_cast<const BaseObject *>(select_animation_.get()));
    s.store_object_field("effect_animation", static_cast<const BaseObject *>(effect_animation_.get()));
    s.store_class_end();
  }
}

messageEffectTypePremiumSticker::messageEffectTypePremiumSticker()
  : sticker_()
{}

messageEffectTypePremiumSticker::messageEffectTypePremiumSticker(object_ptr<sticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t messageEffectTypePremiumSticker::ID;

void messageEffectTypePremiumSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEffectTypePremiumSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messageSourceChatHistory::messageSourceChatHistory() {
}

const std::int32_t messageSourceChatHistory::ID;

void messageSourceChatHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceChatHistory");
    s.store_class_end();
  }
}

messageSourceMessageThreadHistory::messageSourceMessageThreadHistory() {
}

const std::int32_t messageSourceMessageThreadHistory::ID;

void messageSourceMessageThreadHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceMessageThreadHistory");
    s.store_class_end();
  }
}

messageSourceForumTopicHistory::messageSourceForumTopicHistory() {
}

const std::int32_t messageSourceForumTopicHistory::ID;

void messageSourceForumTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceForumTopicHistory");
    s.store_class_end();
  }
}

messageSourceDirectMessagesChatTopicHistory::messageSourceDirectMessagesChatTopicHistory() {
}

const std::int32_t messageSourceDirectMessagesChatTopicHistory::ID;

void messageSourceDirectMessagesChatTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceDirectMessagesChatTopicHistory");
    s.store_class_end();
  }
}

messageSourceHistoryPreview::messageSourceHistoryPreview() {
}

const std::int32_t messageSourceHistoryPreview::ID;

void messageSourceHistoryPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceHistoryPreview");
    s.store_class_end();
  }
}

messageSourceChatList::messageSourceChatList() {
}

const std::int32_t messageSourceChatList::ID;

void messageSourceChatList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceChatList");
    s.store_class_end();
  }
}

messageSourceSearch::messageSourceSearch() {
}

const std::int32_t messageSourceSearch::ID;

void messageSourceSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceSearch");
    s.store_class_end();
  }
}

messageSourceChatEventLog::messageSourceChatEventLog() {
}

const std::int32_t messageSourceChatEventLog::ID;

void messageSourceChatEventLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceChatEventLog");
    s.store_class_end();
  }
}

messageSourceNotification::messageSourceNotification() {
}

const std::int32_t messageSourceNotification::ID;

void messageSourceNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceNotification");
    s.store_class_end();
  }
}

messageSourceScreenshot::messageSourceScreenshot() {
}

const std::int32_t messageSourceScreenshot::ID;

void messageSourceScreenshot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceScreenshot");
    s.store_class_end();
  }
}

messageSourceOther::messageSourceOther() {
}

const std::int32_t messageSourceOther::ID;

void messageSourceOther::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceOther");
    s.store_class_end();
  }
}

networkStatistics::networkStatistics()
  : since_date_()
  , entries_()
{}

networkStatistics::networkStatistics(int32 since_date_, array<object_ptr<NetworkStatisticsEntry>> &&entries_)
  : since_date_(since_date_)
  , entries_(std::move(entries_))
{}

const std::int32_t networkStatistics::ID;

void networkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkStatistics");
    s.store_field("since_date", since_date_);
    { s.store_vector_begin("entries", entries_.size()); for (const auto &_value : entries_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

newChatPrivacySettings::newChatPrivacySettings()
  : allow_new_chats_from_unknown_users_()
  , incoming_paid_message_star_count_()
{}

newChatPrivacySettings::newChatPrivacySettings(bool allow_new_chats_from_unknown_users_, int53 incoming_paid_message_star_count_)
  : allow_new_chats_from_unknown_users_(allow_new_chats_from_unknown_users_)
  , incoming_paid_message_star_count_(incoming_paid_message_star_count_)
{}

const std::int32_t newChatPrivacySettings::ID;

void newChatPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "newChatPrivacySettings");
    s.store_field("allow_new_chats_from_unknown_users", allow_new_chats_from_unknown_users_);
    s.store_field("incoming_paid_message_star_count", incoming_paid_message_star_count_);
    s.store_class_end();
  }
}

notificationSounds::notificationSounds()
  : notification_sounds_()
{}

notificationSounds::notificationSounds(array<object_ptr<notificationSound>> &&notification_sounds_)
  : notification_sounds_(std::move(notification_sounds_))
{}

const std::int32_t notificationSounds::ID;

void notificationSounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSounds");
    { s.store_vector_begin("notification_sounds", notification_sounds_.size()); for (const auto &_value : notification_sounds_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

onRampProvider::onRampProvider()
  : id_()
  , name_()
  , cryptocurrencies_()
  , supports_base_currencies_()
  , supports_limits_()
  , supports_quote_()
{}

onRampProvider::onRampProvider(string const &id_, string const &name_, array<string> &&cryptocurrencies_, bool supports_base_currencies_, bool supports_limits_, bool supports_quote_)
  : id_(id_)
  , name_(name_)
  , cryptocurrencies_(std::move(cryptocurrencies_))
  , supports_base_currencies_(supports_base_currencies_)
  , supports_limits_(supports_limits_)
  , supports_quote_(supports_quote_)
{}

const std::int32_t onRampProvider::ID;

void onRampProvider::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onRampProvider");
    s.store_field("id", id_);
    s.store_field("name", name_);
    { s.store_vector_begin("cryptocurrencies", cryptocurrencies_.size()); for (const auto &_value : cryptocurrencies_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("supports_base_currencies", supports_base_currencies_);
    s.store_field("supports_limits", supports_limits_);
    s.store_field("supports_quote", supports_quote_);
    s.store_class_end();
  }
}

passkey::passkey()
  : id_()
  , name_()
  , addition_date_()
  , last_usage_date_()
  , software_icon_custom_emoji_id_()
{}

passkey::passkey(string const &id_, string const &name_, int32 addition_date_, int32 last_usage_date_, int64 software_icon_custom_emoji_id_)
  : id_(id_)
  , name_(name_)
  , addition_date_(addition_date_)
  , last_usage_date_(last_usage_date_)
  , software_icon_custom_emoji_id_(software_icon_custom_emoji_id_)
{}

const std::int32_t passkey::ID;

void passkey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passkey");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_field("addition_date", addition_date_);
    s.store_field("last_usage_date", last_usage_date_);
    s.store_field("software_icon_custom_emoji_id", software_icon_custom_emoji_id_);
    s.store_class_end();
  }
}

passportElements::passportElements()
  : elements_()
{}

passportElements::passportElements(array<object_ptr<PassportElement>> &&elements_)
  : elements_(std::move(elements_))
{}

const std::int32_t passportElements::ID;

void passportElements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElements");
    { s.store_vector_begin("elements", elements_.size()); for (const auto &_value : elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

passportRequiredElement::passportRequiredElement()
  : suitable_elements_()
{}

passportRequiredElement::passportRequiredElement(array<object_ptr<passportSuitableElement>> &&suitable_elements_)
  : suitable_elements_(std::move(suitable_elements_))
{}

const std::int32_t passportRequiredElement::ID;

void passportRequiredElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportRequiredElement");
    { s.store_vector_begin("suitable_elements", suitable_elements_.size()); for (const auto &_value : suitable_elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

passwordState::passwordState()
  : has_password_()
  , password_hint_()
  , has_recovery_email_address_()
  , has_passport_data_()
  , recovery_email_address_code_info_()
  , login_email_address_pattern_()
  , pending_reset_date_()
{}

passwordState::passwordState(bool has_password_, string const &password_hint_, bool has_recovery_email_address_, bool has_passport_data_, object_ptr<emailAddressAuthenticationCodeInfo> &&recovery_email_address_code_info_, string const &login_email_address_pattern_, int32 pending_reset_date_)
  : has_password_(has_password_)
  , password_hint_(password_hint_)
  , has_recovery_email_address_(has_recovery_email_address_)
  , has_passport_data_(has_passport_data_)
  , recovery_email_address_code_info_(std::move(recovery_email_address_code_info_))
  , login_email_address_pattern_(login_email_address_pattern_)
  , pending_reset_date_(pending_reset_date_)
{}

const std::int32_t passwordState::ID;

void passwordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passwordState");
    s.store_field("has_password", has_password_);
    s.store_field("password_hint", password_hint_);
    s.store_field("has_recovery_email_address", has_recovery_email_address_);
    s.store_field("has_passport_data", has_passport_data_);
    s.store_object_field("recovery_email_address_code_info", static_cast<const BaseObject *>(recovery_email_address_code_info_.get()));
    s.store_field("login_email_address_pattern", login_email_address_pattern_);
    s.store_field("pending_reset_date", pending_reset_date_);
    s.store_class_end();
  }
}

point::point()
  : x_()
  , y_()
{}

point::point(double x_, double y_)
  : x_(x_)
  , y_(y_)
{}

const std::int32_t point::ID;

void point::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "point");
    s.store_field("x", x_);
    s.store_field("y", y_);
    s.store_class_end();
  }
}

premiumGiveawayPaymentOptions::premiumGiveawayPaymentOptions()
  : options_()
{}

premiumGiveawayPaymentOptions::premiumGiveawayPaymentOptions(array<object_ptr<premiumGiveawayPaymentOption>> &&options_)
  : options_(std::move(options_))
{}

const std::int32_t premiumGiveawayPaymentOptions::ID;

void premiumGiveawayPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiveawayPaymentOptions");
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

profileTabPosts::profileTabPosts() {
}

const std::int32_t profileTabPosts::ID;

void profileTabPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabPosts");
    s.store_class_end();
  }
}

profileTabGifts::profileTabGifts() {
}

const std::int32_t profileTabGifts::ID;

void profileTabGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabGifts");
    s.store_class_end();
  }
}

profileTabMedia::profileTabMedia() {
}

const std::int32_t profileTabMedia::ID;

void profileTabMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabMedia");
    s.store_class_end();
  }
}

profileTabFiles::profileTabFiles() {
}

const std::int32_t profileTabFiles::ID;

void profileTabFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabFiles");
    s.store_class_end();
  }
}

profileTabLinks::profileTabLinks() {
}

const std::int32_t profileTabLinks::ID;

void profileTabLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabLinks");
    s.store_class_end();
  }
}

profileTabMusic::profileTabMusic() {
}

const std::int32_t profileTabMusic::ID;

void profileTabMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabMusic");
    s.store_class_end();
  }
}

profileTabVoice::profileTabVoice() {
}

const std::int32_t profileTabVoice::ID;

void profileTabVoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabVoice");
    s.store_class_end();
  }
}

profileTabGifs::profileTabGifs() {
}

const std::int32_t profileTabGifs::ID;

void profileTabGifs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabGifs");
    s.store_class_end();
  }
}

quickReplyMessages::quickReplyMessages()
  : messages_()
{}

quickReplyMessages::quickReplyMessages(array<object_ptr<quickReplyMessage>> &&messages_)
  : messages_(std::move(messages_))
{}

const std::int32_t quickReplyMessages::ID;

void quickReplyMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "quickReplyMessages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reactionNotificationSettings::reactionNotificationSettings()
  : message_reaction_source_()
  , story_reaction_source_()
  , poll_vote_source_()
  , sound_id_()
  , show_preview_()
{}

reactionNotificationSettings::reactionNotificationSettings(object_ptr<ReactionNotificationSource> &&message_reaction_source_, object_ptr<ReactionNotificationSource> &&story_reaction_source_, object_ptr<ReactionNotificationSource> &&poll_vote_source_, int64 sound_id_, bool show_preview_)
  : message_reaction_source_(std::move(message_reaction_source_))
  , story_reaction_source_(std::move(story_reaction_source_))
  , poll_vote_source_(std::move(poll_vote_source_))
  , sound_id_(sound_id_)
  , show_preview_(show_preview_)
{}

const std::int32_t reactionNotificationSettings::ID;

void reactionNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationSettings");
    s.store_object_field("message_reaction_source", static_cast<const BaseObject *>(message_reaction_source_.get()));
    s.store_object_field("story_reaction_source", static_cast<const BaseObject *>(story_reaction_source_.get()));
    s.store_object_field("poll_vote_source", static_cast<const BaseObject *>(poll_vote_source_.get()));
    s.store_field("sound_id", sound_id_);
    s.store_field("show_preview", show_preview_);
    s.store_class_end();
  }
}

resetPasswordResultOk::resetPasswordResultOk() {
}

const std::int32_t resetPasswordResultOk::ID;

void resetPasswordResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPasswordResultOk");
    s.store_class_end();
  }
}

resetPasswordResultPending::resetPasswordResultPending()
  : pending_reset_date_()
{}

resetPasswordResultPending::resetPasswordResultPending(int32 pending_reset_date_)
  : pending_reset_date_(pending_reset_date_)
{}

const std::int32_t resetPasswordResultPending::ID;

void resetPasswordResultPending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPasswordResultPending");
    s.store_field("pending_reset_date", pending_reset_date_);
    s.store_class_end();
  }
}

resetPasswordResultDeclined::resetPasswordResultDeclined()
  : retry_date_()
{}

resetPasswordResultDeclined::resetPasswordResultDeclined(int32 retry_date_)
  : retry_date_(retry_date_)
{}

const std::int32_t resetPasswordResultDeclined::ID;

void resetPasswordResultDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPasswordResultDeclined");
    s.store_field("retry_date", retry_date_);
    s.store_class_end();
  }
}

savedCredentials::savedCredentials()
  : id_()
  , title_()
{}

savedCredentials::savedCredentials(string const &id_, string const &title_)
  : id_(id_)
  , title_(title_)
{}

const std::int32_t savedCredentials::ID;

void savedCredentials::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedCredentials");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

searchChatTypeFilterBot::searchChatTypeFilterBot() {
}

const std::int32_t searchChatTypeFilterBot::ID;

void searchChatTypeFilterBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatTypeFilterBot");
    s.store_class_end();
  }
}

searchChatTypeFilterChannel::searchChatTypeFilterChannel() {
}

const std::int32_t searchChatTypeFilterChannel::ID;

void searchChatTypeFilterChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatTypeFilterChannel");
    s.store_class_end();
  }
}

settingsSectionAppearance::settingsSectionAppearance()
  : subsection_()
{}

settingsSectionAppearance::settingsSectionAppearance(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionAppearance::ID;

void settingsSectionAppearance::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionAppearance");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionAskQuestion::settingsSectionAskQuestion() {
}

const std::int32_t settingsSectionAskQuestion::ID;

void settingsSectionAskQuestion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionAskQuestion");
    s.store_class_end();
  }
}

settingsSectionBusiness::settingsSectionBusiness()
  : subsection_()
{}

settingsSectionBusiness::settingsSectionBusiness(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionBusiness::ID;

void settingsSectionBusiness::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionBusiness");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionChatFolders::settingsSectionChatFolders()
  : subsection_()
{}

settingsSectionChatFolders::settingsSectionChatFolders(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionChatFolders::ID;

void settingsSectionChatFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionChatFolders");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionDataAndStorage::settingsSectionDataAndStorage()
  : subsection_()
{}

settingsSectionDataAndStorage::settingsSectionDataAndStorage(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionDataAndStorage::ID;

void settingsSectionDataAndStorage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionDataAndStorage");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionDevices::settingsSectionDevices()
  : subsection_()
{}

settingsSectionDevices::settingsSectionDevices(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionDevices::ID;

void settingsSectionDevices::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionDevices");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionEditProfile::settingsSectionEditProfile()
  : subsection_()
{}

settingsSectionEditProfile::settingsSectionEditProfile(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionEditProfile::ID;

void settingsSectionEditProfile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionEditProfile");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionFaq::settingsSectionFaq() {
}

const std::int32_t settingsSectionFaq::ID;

void settingsSectionFaq::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionFaq");
    s.store_class_end();
  }
}

settingsSectionFeatures::settingsSectionFeatures() {
}

const std::int32_t settingsSectionFeatures::ID;

void settingsSectionFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionFeatures");
    s.store_class_end();
  }
}

settingsSectionInAppBrowser::settingsSectionInAppBrowser()
  : subsection_()
{}

settingsSectionInAppBrowser::settingsSectionInAppBrowser(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionInAppBrowser::ID;

void settingsSectionInAppBrowser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionInAppBrowser");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionLanguage::settingsSectionLanguage()
  : subsection_()
{}

settingsSectionLanguage::settingsSectionLanguage(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionLanguage::ID;

void settingsSectionLanguage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionLanguage");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionMyStars::settingsSectionMyStars()
  : subsection_()
{}

settingsSectionMyStars::settingsSectionMyStars(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionMyStars::ID;

void settingsSectionMyStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionMyStars");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionMyGrams::settingsSectionMyGrams() {
}

const std::int32_t settingsSectionMyGrams::ID;

void settingsSectionMyGrams::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionMyGrams");
    s.store_class_end();
  }
}

settingsSectionNotifications::settingsSectionNotifications()
  : subsection_()
{}

settingsSectionNotifications::settingsSectionNotifications(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionNotifications::ID;

void settingsSectionNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionNotifications");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionPowerSaving::settingsSectionPowerSaving()
  : subsection_()
{}

settingsSectionPowerSaving::settingsSectionPowerSaving(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionPowerSaving::ID;

void settingsSectionPowerSaving::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionPowerSaving");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionPremium::settingsSectionPremium() {
}

const std::int32_t settingsSectionPremium::ID;

void settingsSectionPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionPremium");
    s.store_class_end();
  }
}

settingsSectionPrivacyAndSecurity::settingsSectionPrivacyAndSecurity()
  : subsection_()
{}

settingsSectionPrivacyAndSecurity::settingsSectionPrivacyAndSecurity(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionPrivacyAndSecurity::ID;

void settingsSectionPrivacyAndSecurity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionPrivacyAndSecurity");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionPrivacyPolicy::settingsSectionPrivacyPolicy() {
}

const std::int32_t settingsSectionPrivacyPolicy::ID;

void settingsSectionPrivacyPolicy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionPrivacyPolicy");
    s.store_class_end();
  }
}

settingsSectionQrCode::settingsSectionQrCode()
  : subsection_()
{}

settingsSectionQrCode::settingsSectionQrCode(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionQrCode::ID;

void settingsSectionQrCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionQrCode");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionSearch::settingsSectionSearch() {
}

const std::int32_t settingsSectionSearch::ID;

void settingsSectionSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionSearch");
    s.store_class_end();
  }
}

settingsSectionSendGift::settingsSectionSendGift()
  : subsection_()
{}

settingsSectionSendGift::settingsSectionSendGift(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionSendGift::ID;

void settingsSectionSendGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionSendGift");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

sponsoredChats::sponsoredChats()
  : chats_()
{}

sponsoredChats::sponsoredChats(array<object_ptr<sponsoredChat>> &&chats_)
  : chats_(std::move(chats_))
{}

const std::int32_t sponsoredChats::ID;

void sponsoredChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredChats");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starSubscriptionTypeChannel::starSubscriptionTypeChannel()
  : can_reuse_()
  , invite_link_()
{}

starSubscriptionTypeChannel::starSubscriptionTypeChannel(bool can_reuse_, string const &invite_link_)
  : can_reuse_(can_reuse_)
  , invite_link_(invite_link_)
{}

const std::int32_t starSubscriptionTypeChannel::ID;

void starSubscriptionTypeChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starSubscriptionTypeChannel");
    s.store_field("can_reuse", can_reuse_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

starSubscriptionTypeBot::starSubscriptionTypeBot()
  : is_canceled_by_bot_()
  , title_()
  , photo_()
  , invoice_link_()
{}

starSubscriptionTypeBot::starSubscriptionTypeBot(bool is_canceled_by_bot_, string const &title_, object_ptr<photo> &&photo_, string const &invoice_link_)
  : is_canceled_by_bot_(is_canceled_by_bot_)
  , title_(title_)
  , photo_(std::move(photo_))
  , invoice_link_(invoice_link_)
{}

const std::int32_t starSubscriptionTypeBot::ID;

void starSubscriptionTypeBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starSubscriptionTypeBot");
    s.store_field("is_canceled_by_bot", is_canceled_by_bot_);
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("invoice_link", invoice_link_);
    s.store_class_end();
  }
}

starSubscriptions::starSubscriptions()
  : star_amount_()
  , subscriptions_()
  , required_star_count_()
  , next_offset_()
{}

starSubscriptions::starSubscriptions(object_ptr<starAmount> &&star_amount_, array<object_ptr<starSubscription>> &&subscriptions_, int53 required_star_count_, string const &next_offset_)
  : star_amount_(std::move(star_amount_))
  , subscriptions_(std::move(subscriptions_))
  , required_star_count_(required_star_count_)
  , next_offset_(next_offset_)
{}

const std::int32_t starSubscriptions::ID;

void starSubscriptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starSubscriptions");
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    { s.store_vector_begin("subscriptions", subscriptions_.size()); for (const auto &_value : subscriptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("required_star_count", required_star_count_);
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

statisticalValue::statisticalValue()
  : value_()
  , previous_value_()
  , growth_rate_percentage_()
{}

statisticalValue::statisticalValue(double value_, double previous_value_, double growth_rate_percentage_)
  : value_(value_)
  , previous_value_(previous_value_)
  , growth_rate_percentage_(growth_rate_percentage_)
{}

const std::int32_t statisticalValue::ID;

void statisticalValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalValue");
    s.store_field("value", value_);
    s.store_field("previous_value", previous_value_);
    s.store_field("growth_rate_percentage", growth_rate_percentage_);
    s.store_class_end();
  }
}

storeTransactionAppStore::storeTransactionAppStore()
  : receipt_()
{}

storeTransactionAppStore::storeTransactionAppStore(bytes const &receipt_)
  : receipt_(std::move(receipt_))
{}

const std::int32_t storeTransactionAppStore::ID;

void storeTransactionAppStore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storeTransactionAppStore");
    s.store_bytes_field("receipt", receipt_);
    s.store_class_end();
  }
}

storeTransactionGooglePlay::storeTransactionGooglePlay()
  : package_name_()
  , store_product_id_()
  , purchase_token_()
{}

storeTransactionGooglePlay::storeTransactionGooglePlay(string const &package_name_, string const &store_product_id_, string const &purchase_token_)
  : package_name_(package_name_)
  , store_product_id_(store_product_id_)
  , purchase_token_(purchase_token_)
{}

const std::int32_t storeTransactionGooglePlay::ID;

void storeTransactionGooglePlay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storeTransactionGooglePlay");
    s.store_field("package_name", package_name_);
    s.store_field("store_product_id", store_product_id_);
    s.store_field("purchase_token", "[REDACTED]");
    s.store_class_end();
  }
}

storyContentTypePhoto::storyContentTypePhoto() {
}

const std::int32_t storyContentTypePhoto::ID;

void storyContentTypePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentTypePhoto");
    s.store_class_end();
  }
}

storyContentTypeVideo::storyContentTypeVideo() {
}

const std::int32_t storyContentTypeVideo::ID;

void storyContentTypeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentTypeVideo");
    s.store_class_end();
  }
}

storyContentTypeLive::storyContentTypeLive() {
}

const std::int32_t storyContentTypeLive::ID;

void storyContentTypeLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentTypeLive");
    s.store_class_end();
  }
}

storyContentTypeUnsupported::storyContentTypeUnsupported() {
}

const std::int32_t storyContentTypeUnsupported::ID;

void storyContentTypeUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentTypeUnsupported");
    s.store_class_end();
  }
}

textEntities::textEntities()
  : entities_()
{}

textEntities::textEntities(array<object_ptr<textEntity>> &&entities_)
  : entities_(std::move(entities_))
{}

const std::int32_t textEntities::ID;

void textEntities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntities");
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

textQuote::textQuote()
  : text_()
  , rich_texts_()
  , position_()
  , is_manual_()
{}

textQuote::textQuote(object_ptr<formattedText> &&text_, array<object_ptr<RichText>> &&rich_texts_, int32 position_, bool is_manual_)
  : text_(std::move(text_))
  , rich_texts_(std::move(rich_texts_))
  , position_(position_)
  , is_manual_(is_manual_)
{}

const std::int32_t textQuote::ID;

void textQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    { s.store_vector_begin("rich_texts", rich_texts_.size()); for (const auto &_value : rich_texts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("position", position_);
    s.store_field("is_manual", is_manual_);
    s.store_class_end();
  }
}

tonConnectManifestPending::tonConnectManifestPending() {
}

const std::int32_t tonConnectManifestPending::ID;

void tonConnectManifestPending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectManifestPending");
    s.store_class_end();
  }
}

tonConnectManifestInfo::tonConnectManifestInfo()
  : url_()
  , name_()
  , icon_()
{}

tonConnectManifestInfo::tonConnectManifestInfo(string const &url_, string const &name_, object_ptr<document> &&icon_)
  : url_(url_)
  , name_(name_)
  , icon_(std::move(icon_))
{}

const std::int32_t tonConnectManifestInfo::ID;

void tonConnectManifestInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectManifestInfo");
    s.store_field("url", url_);
    s.store_field("name", name_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_class_end();
  }
}

tonConnectManifestFailed::tonConnectManifestFailed() {
}

const std::int32_t tonConnectManifestFailed::ID;

void tonConnectManifestFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectManifestFailed");
    s.store_class_end();
  }
}

tonConnectManifestInvalid::tonConnectManifestInvalid() {
}

const std::int32_t tonConnectManifestInvalid::ID;

void tonConnectManifestInvalid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectManifestInvalid");
    s.store_class_end();
  }
}

tonConnectSession::tonConnectSession()
  : id_()
  , dapp_client_id_()
  , wallet_client_id_()
  , creation_date_()
  , manifest_()
  , nonce_()
  , state_()
{}

tonConnectSession::tonConnectSession(int64 id_, string const &dapp_client_id_, string const &wallet_client_id_, int32 creation_date_, object_ptr<TonConnectManifest> &&manifest_, bytes const &nonce_, object_ptr<TonConnectSessionState> &&state_)
  : id_(id_)
  , dapp_client_id_(dapp_client_id_)
  , wallet_client_id_(wallet_client_id_)
  , creation_date_(creation_date_)
  , manifest_(std::move(manifest_))
  , nonce_(std::move(nonce_))
  , state_(std::move(state_))
{}

const std::int32_t tonConnectSession::ID;

void tonConnectSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectSession");
    s.store_field("id", id_);
    s.store_field("dapp_client_id", dapp_client_id_);
    s.store_field("wallet_client_id", wallet_client_id_);
    s.store_field("creation_date", creation_date_);
    s.store_object_field("manifest", static_cast<const BaseObject *>(manifest_.get()));
    s.store_bytes_field("nonce", nonce_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

tonNft::tonNft()
  : collection_address_()
  , address_()
  , owner_address_()
  , index_()
  , name_()
  , description_()
  , image_()
  , thumbnail_()
  , content_()
  , sticker_()
  , attributes_()
  , extra_()
  , gift_()
{}

tonNft::tonNft(string const &collection_address_, string const &address_, string const &owner_address_, string const &index_, string const &name_, string const &description_, object_ptr<photoSize> &&image_, object_ptr<photoSize> &&thumbnail_, object_ptr<document> &&content_, object_ptr<sticker> &&sticker_, array<object_ptr<tonNftAttribute>> &&attributes_, object_ptr<JsonValue> &&extra_, object_ptr<upgradedGift> &&gift_)
  : collection_address_(collection_address_)
  , address_(address_)
  , owner_address_(owner_address_)
  , index_(index_)
  , name_(name_)
  , description_(description_)
  , image_(std::move(image_))
  , thumbnail_(std::move(thumbnail_))
  , content_(std::move(content_))
  , sticker_(std::move(sticker_))
  , attributes_(std::move(attributes_))
  , extra_(std::move(extra_))
  , gift_(std::move(gift_))
{}

const std::int32_t tonNft::ID;

void tonNft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonNft");
    s.store_field("collection_address", collection_address_);
    s.store_field("address", address_);
    s.store_field("owner_address", owner_address_);
    s.store_field("index", index_);
    s.store_field("name", name_);
    s.store_field("description", description_);
    s.store_object_field("image", static_cast<const BaseObject *>(image_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("extra", static_cast<const BaseObject *>(extra_.get()));
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

tonNfts::tonNfts()
  : nfts_()
  , next_offset_()
{}

tonNfts::tonNfts(array<object_ptr<tonNft>> &&nfts_, string const &next_offset_)
  : nfts_(std::move(nfts_))
  , next_offset_(next_offset_)
{}

const std::int32_t tonNfts::ID;

void tonNfts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonNfts");
    { s.store_vector_begin("nfts", nfts_.size()); for (const auto &_value : nfts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

tonSmartContractInitialState::tonSmartContractInitialState()
  : code_()
  , data_()
{}

tonSmartContractInitialState::tonSmartContractInitialState(bytes const &code_, bytes const &data_)
  : code_(std::move(code_))
  , data_(std::move(data_))
{}

const std::int32_t tonSmartContractInitialState::ID;

void tonSmartContractInitialState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonSmartContractInitialState");
    s.store_bytes_field("code", code_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

tonWalletGaslessTransfersInfo::tonWalletGaslessTransfersInfo()
  : left_count_()
  , reset_date_()
  , relayer_address_()
{}

tonWalletGaslessTransfersInfo::tonWalletGaslessTransfersInfo(int32 left_count_, int32 reset_date_, string const &relayer_address_)
  : left_count_(left_count_)
  , reset_date_(reset_date_)
  , relayer_address_(relayer_address_)
{}

const std::int32_t tonWalletGaslessTransfersInfo::ID;

void tonWalletGaslessTransfersInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletGaslessTransfersInfo");
    s.store_field("left_count", left_count_);
    s.store_field("reset_date", reset_date_);
    s.store_field("relayer_address", relayer_address_);
    s.store_class_end();
  }
}

trendingStickerSets::trendingStickerSets()
  : total_count_()
  , sets_()
  , is_premium_()
{}

trendingStickerSets::trendingStickerSets(int32 total_count_, array<object_ptr<stickerSetInfo>> &&sets_, bool is_premium_)
  : total_count_(total_count_)
  , sets_(std::move(sets_))
  , is_premium_(is_premium_)
{}

const std::int32_t trendingStickerSets::ID;

void trendingStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "trendingStickerSets");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_premium", is_premium_);
    s.store_class_end();
  }
}

upgradedGiftOriginUpgrade::upgradedGiftOriginUpgrade()
  : gift_message_id_()
{}

upgradedGiftOriginUpgrade::upgradedGiftOriginUpgrade(int53 gift_message_id_)
  : gift_message_id_(gift_message_id_)
{}

const std::int32_t upgradedGiftOriginUpgrade::ID;

void upgradedGiftOriginUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginUpgrade");
    s.store_field("gift_message_id", gift_message_id_);
    s.store_class_end();
  }
}

upgradedGiftOriginTransfer::upgradedGiftOriginTransfer() {
}

const std::int32_t upgradedGiftOriginTransfer::ID;

void upgradedGiftOriginTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginTransfer");
    s.store_class_end();
  }
}

upgradedGiftOriginResale::upgradedGiftOriginResale()
  : price_()
{}

upgradedGiftOriginResale::upgradedGiftOriginResale(object_ptr<GiftResalePrice> &&price_)
  : price_(std::move(price_))
{}

const std::int32_t upgradedGiftOriginResale::ID;

void upgradedGiftOriginResale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginResale");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

upgradedGiftOriginBlockchain::upgradedGiftOriginBlockchain() {
}

const std::int32_t upgradedGiftOriginBlockchain::ID;

void upgradedGiftOriginBlockchain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginBlockchain");
    s.store_class_end();
  }
}

upgradedGiftOriginPrepaidUpgrade::upgradedGiftOriginPrepaidUpgrade() {
}

const std::int32_t upgradedGiftOriginPrepaidUpgrade::ID;

void upgradedGiftOriginPrepaidUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginPrepaidUpgrade");
    s.store_class_end();
  }
}

upgradedGiftOriginOffer::upgradedGiftOriginOffer()
  : price_()
{}

upgradedGiftOriginOffer::upgradedGiftOriginOffer(object_ptr<GiftResalePrice> &&price_)
  : price_(std::move(price_))
{}

const std::int32_t upgradedGiftOriginOffer::ID;

void upgradedGiftOriginOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginOffer");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

upgradedGiftOriginCraft::upgradedGiftOriginCraft() {
}

const std::int32_t upgradedGiftOriginCraft::ID;

void upgradedGiftOriginCraft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginCraft");
    s.store_class_end();
  }
}

upgradedGiftOriginOnChainResale::upgradedGiftOriginOnChainResale()
  : gram_amount_()
{}

upgradedGiftOriginOnChainResale::upgradedGiftOriginOnChainResale(int64 gram_amount_)
  : gram_amount_(gram_amount_)
{}

const std::int32_t upgradedGiftOriginOnChainResale::ID;

void upgradedGiftOriginOnChainResale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginOnChainResale");
    s.store_field("gram_amount", gram_amount_);
    s.store_class_end();
  }
}

upgradedGiftOriginOnChainOffer::upgradedGiftOriginOnChainOffer()
  : gram_amount_()
{}

upgradedGiftOriginOnChainOffer::upgradedGiftOriginOnChainOffer(int64 gram_amount_)
  : gram_amount_(gram_amount_)
{}

const std::int32_t upgradedGiftOriginOnChainOffer::ID;

void upgradedGiftOriginOnChainOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginOnChainOffer");
    s.store_field("gram_amount", gram_amount_);
    s.store_class_end();
  }
}

userSupportInfo::userSupportInfo()
  : message_()
  , author_()
  , date_()
{}

userSupportInfo::userSupportInfo(object_ptr<formattedText> &&message_, string const &author_, int32 date_)
  : message_(std::move(message_))
  , author_(author_)
  , date_(date_)
{}

const std::int32_t userSupportInfo::ID;

void userSupportInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userSupportInfo");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("author", author_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

webApp::webApp()
  : short_name_()
  , title_()
  , description_()
  , photo_()
  , animation_()
{}

webApp::webApp(string const &short_name_, string const &title_, string const &description_, object_ptr<photo> &&photo_, object_ptr<animation> &&animation_)
  : short_name_(short_name_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , animation_(std::move(animation_))
{}

const std::int32_t webApp::ID;

void webApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webApp");
    s.store_field("short_name", short_name_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

widgetPublicData::widgetPublicData()
  : data_()
  , poll_period_()
{}

widgetPublicData::widgetPublicData(string const &data_, int32 poll_period_)
  : data_(data_)
  , poll_period_(poll_period_)
{}

const std::int32_t widgetPublicData::ID;

void widgetPublicData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "widgetPublicData");
    s.store_field("data", data_);
    s.store_field("poll_period", poll_period_);
    s.store_class_end();
  }
}

addContact::addContact()
  : user_id_()
  , contact_()
  , share_phone_number_()
{}

addContact::addContact(int53 user_id_, object_ptr<importedContact> &&contact_, bool share_phone_number_)
  : user_id_(user_id_)
  , contact_(std::move(contact_))
  , share_phone_number_(share_phone_number_)
{}

const std::int32_t addContact::ID;

void addContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addContact");
    s.store_field("user_id", user_id_);
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_field("share_phone_number", share_phone_number_);
    s.store_class_end();
  }
}

addOffer::addOffer()
  : chat_id_()
  , message_id_()
  , options_()
{}

addOffer::addOffer(int53 chat_id_, int53 message_id_, object_ptr<messageSendOptions> &&options_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , options_(std::move(options_))
{}

const std::int32_t addOffer::ID;

void addOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addOffer");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_class_end();
  }
}

addPendingLiveStoryReaction::addPendingLiveStoryReaction()
  : group_call_id_()
  , star_count_()
{}

addPendingLiveStoryReaction::addPendingLiveStoryReaction(int32 group_call_id_, int53 star_count_)
  : group_call_id_(group_call_id_)
  , star_count_(star_count_)
{}

const std::int32_t addPendingLiveStoryReaction::ID;

void addPendingLiveStoryReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addPendingLiveStoryReaction");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

addStickerToSet::addStickerToSet()
  : user_id_()
  , name_()
  , sticker_()
{}

addStickerToSet::addStickerToSet(int53 user_id_, string const &name_, object_ptr<newSticker> &&sticker_)
  : user_id_(user_id_)
  , name_(name_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t addStickerToSet::ID;

void addStickerToSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addStickerToSet");
    s.store_field("user_id", user_id_);
    s.store_field("name", name_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

banChatMember::banChatMember()
  : chat_id_()
  , member_id_()
  , banned_until_date_()
  , revoke_messages_()
{}

banChatMember::banChatMember(int53 chat_id_, object_ptr<MessageSender> &&member_id_, int32 banned_until_date_, bool revoke_messages_)
  : chat_id_(chat_id_)
  , member_id_(std::move(member_id_))
  , banned_until_date_(banned_until_date_)
  , revoke_messages_(revoke_messages_)
{}

const std::int32_t banChatMember::ID;

void banChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "banChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_field("banned_until_date", banned_until_date_);
    s.store_field("revoke_messages", revoke_messages_);
    s.store_class_end();
  }
}

boostChat::boostChat()
  : chat_id_()
  , slot_ids_()
{}

boostChat::boostChat(int53 chat_id_, array<int32> &&slot_ids_)
  : chat_id_(chat_id_)
  , slot_ids_(std::move(slot_ids_))
{}

const std::int32_t boostChat::ID;

void boostChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "boostChat");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("slot_ids", slot_ids_.size()); for (const auto &_value : slot_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

canSendGift::canSendGift()
  : gift_id_()
{}

canSendGift::canSendGift(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t canSendGift::ID;

void canSendGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendGift");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

cancelRecoveryEmailAddressVerification::cancelRecoveryEmailAddressVerification() {
}

const std::int32_t cancelRecoveryEmailAddressVerification::ID;

void cancelRecoveryEmailAddressVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelRecoveryEmailAddressVerification");
    s.store_class_end();
  }
}

checkBotUsername::checkBotUsername()
  : username_()
  , is_secondary_()
{}

checkBotUsername::checkBotUsername(string const &username_, bool is_secondary_)
  : username_(username_)
  , is_secondary_(is_secondary_)
{}

const std::int32_t checkBotUsername::ID;

void checkBotUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkBotUsername");
    s.store_field("username", username_);
    s.store_field("is_secondary", is_secondary_);
    s.store_class_end();
  }
}

checkCreatedPublicChatsLimit::checkCreatedPublicChatsLimit()
  : type_()
{}

checkCreatedPublicChatsLimit::checkCreatedPublicChatsLimit(object_ptr<PublicChatType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t checkCreatedPublicChatsLimit::ID;

void checkCreatedPublicChatsLimit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkCreatedPublicChatsLimit");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

checkQuickReplyShortcutName::checkQuickReplyShortcutName()
  : name_()
{}

checkQuickReplyShortcutName::checkQuickReplyShortcutName(string const &name_)
  : name_(name_)
{}

const std::int32_t checkQuickReplyShortcutName::ID;

void checkQuickReplyShortcutName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkQuickReplyShortcutName");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

claimTonConnectRequest::claimTonConnectRequest()
  : session_id_()
  , message_id_()
  , dapp_request_id_()
  , is_rejected_()
{}

claimTonConnectRequest::claimTonConnectRequest(int64 session_id_, int53 message_id_, string const &dapp_request_id_, bool is_rejected_)
  : session_id_(session_id_)
  , message_id_(message_id_)
  , dapp_request_id_(dapp_request_id_)
  , is_rejected_(is_rejected_)
{}

const std::int32_t claimTonConnectRequest::ID;

void claimTonConnectRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "claimTonConnectRequest");
    s.store_field("session_id", session_id_);
    s.store_field("message_id", message_id_);
    s.store_field("dapp_request_id", dapp_request_id_);
    s.store_field("is_rejected", is_rejected_);
    s.store_class_end();
  }
}

clearSearchedForTags::clearSearchedForTags()
  : clear_cashtags_()
{}

clearSearchedForTags::clearSearchedForTags(bool clear_cashtags_)
  : clear_cashtags_(clear_cashtags_)
{}

const std::int32_t clearSearchedForTags::ID;

void clearSearchedForTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearSearchedForTags");
    s.store_field("clear_cashtags", clear_cashtags_);
    s.store_class_end();
  }
}

closeGiftAuction::closeGiftAuction()
  : gift_id_()
{}

closeGiftAuction::closeGiftAuction(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t closeGiftAuction::ID;

void closeGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeGiftAuction");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

createOnRampPaymentSession::createOnRampPaymentSession()
  : provider_id_()
  , cryptocurrency_()
  , address_()
  , payment_method_name_()
  , base_currency_()
  , cryptocurrency_amount_()
  , base_currency_amount_()
  , memo_()
  , theme_()
  , success_return_url_()
  , fail_return_url_()
{}

createOnRampPaymentSession::createOnRampPaymentSession(string const &provider_id_, string const &cryptocurrency_, string const &address_, string const &payment_method_name_, string const &base_currency_, string const &cryptocurrency_amount_, string const &base_currency_amount_, string const &memo_, string const &theme_, string const &success_return_url_, string const &fail_return_url_)
  : provider_id_(provider_id_)
  , cryptocurrency_(cryptocurrency_)
  , address_(address_)
  , payment_method_name_(payment_method_name_)
  , base_currency_(base_currency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , base_currency_amount_(base_currency_amount_)
  , memo_(memo_)
  , theme_(theme_)
  , success_return_url_(success_return_url_)
  , fail_return_url_(fail_return_url_)
{}

const std::int32_t createOnRampPaymentSession::ID;

void createOnRampPaymentSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createOnRampPaymentSession");
    s.store_field("provider_id", provider_id_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("address", address_);
    s.store_field("payment_method_name", payment_method_name_);
    s.store_field("base_currency", base_currency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_field("base_currency_amount", base_currency_amount_);
    s.store_field("memo", memo_);
    s.store_field("theme", theme_);
    s.store_field("success_return_url", success_return_url_);
    s.store_field("fail_return_url", fail_return_url_);
    s.store_class_end();
  }
}

createStoryAlbum::createStoryAlbum()
  : story_poster_chat_id_()
  , name_()
  , story_ids_()
{}

createStoryAlbum::createStoryAlbum(int53 story_poster_chat_id_, string const &name_, array<int32> &&story_ids_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , name_(name_)
  , story_ids_(std::move(story_ids_))
{}

const std::int32_t createStoryAlbum::ID;

void createStoryAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createStoryAlbum");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("name", name_);
    { s.store_vector_begin("story_ids", story_ids_.size()); for (const auto &_value : story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

deleteBotMediaPreviews::deleteBotMediaPreviews()
  : bot_user_id_()
  , language_code_()
  , file_ids_()
{}

deleteBotMediaPreviews::deleteBotMediaPreviews(int53 bot_user_id_, string const &language_code_, array<int32> &&file_ids_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , file_ids_(std::move(file_ids_))
{}

const std::int32_t deleteBotMediaPreviews::ID;

void deleteBotMediaPreviews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteBotMediaPreviews");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    { s.store_vector_begin("file_ids", file_ids_.size()); for (const auto &_value : file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

deleteChatBackground::deleteChatBackground()
  : chat_id_()
  , restore_previous_()
{}

deleteChatBackground::deleteChatBackground(int53 chat_id_, bool restore_previous_)
  : chat_id_(chat_id_)
  , restore_previous_(restore_previous_)
{}

const std::int32_t deleteChatBackground::ID;

void deleteChatBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatBackground");
    s.store_field("chat_id", chat_id_);
    s.store_field("restore_previous", restore_previous_);
    s.store_class_end();
  }
}

deleteCommands::deleteCommands()
  : scope_()
  , language_code_()
{}

deleteCommands::deleteCommands(object_ptr<BotCommandScope> &&scope_, string const &language_code_)
  : scope_(std::move(scope_))
  , language_code_(language_code_)
{}

const std::int32_t deleteCommands::ID;

void deleteCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

deleteQuickReplyShortcut::deleteQuickReplyShortcut()
  : shortcut_id_()
{}

deleteQuickReplyShortcut::deleteQuickReplyShortcut(int32 shortcut_id_)
  : shortcut_id_(shortcut_id_)
{}

const std::int32_t deleteQuickReplyShortcut::ID;

void deleteQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteQuickReplyShortcut");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

deleteSavedCredentials::deleteSavedCredentials() {
}

const std::int32_t deleteSavedCredentials::ID;

void deleteSavedCredentials::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteSavedCredentials");
    s.store_class_end();
  }
}

disableTonWalletBackupWithProof::disableTonWalletBackupWithProof()
  : proof_()
{}

disableTonWalletBackupWithProof::disableTonWalletBackupWithProof(object_ptr<tonWalletOwnershipProof> &&proof_)
  : proof_(std::move(proof_))
{}

const std::int32_t disableTonWalletBackupWithProof::ID;

void disableTonWalletBackupWithProof::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disableTonWalletBackupWithProof");
    s.store_object_field("proof", static_cast<const BaseObject *>(proof_.get()));
    s.store_class_end();
  }
}

disconnectAllWebsites::disconnectAllWebsites() {
}

const std::int32_t disconnectAllWebsites::ID;

void disconnectAllWebsites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disconnectAllWebsites");
    s.store_class_end();
  }
}

editBusinessMessageReplyMarkup::editBusinessMessageReplyMarkup()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
{}

editBusinessMessageReplyMarkup::editBusinessMessageReplyMarkup(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t editBusinessMessageReplyMarkup::ID;

void editBusinessMessageReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageReplyMarkup");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

editCustomLanguagePackInfo::editCustomLanguagePackInfo()
  : info_()
{}

editCustomLanguagePackInfo::editCustomLanguagePackInfo(object_ptr<languagePackInfo> &&info_)
  : info_(std::move(info_))
{}

const std::int32_t editCustomLanguagePackInfo::ID;

void editCustomLanguagePackInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editCustomLanguagePackInfo");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

editInlineMessageLiveLocation::editInlineMessageLiveLocation()
  : inline_message_id_()
  , reply_markup_()
  , location_()
{}

editInlineMessageLiveLocation::editInlineMessageLiveLocation(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<liveLocation> &&location_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , location_(std::move(location_))
{}

const std::int32_t editInlineMessageLiveLocation::ID;

void editInlineMessageLiveLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageLiveLocation");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

editInlineMessageMedia::editInlineMessageMedia()
  : inline_message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editInlineMessageMedia::editInlineMessageMedia(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editInlineMessageMedia::ID;

void editInlineMessageMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageMedia");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editInlineMessageWidgetData::editInlineMessageWidgetData()
  : inline_message_id_()
  , edit_public_data_()
  , public_data_()
  , edit_chat_data_()
  , chat_data_()
{}

editInlineMessageWidgetData::editInlineMessageWidgetData(string const &inline_message_id_, bool edit_public_data_, string const &public_data_, bool edit_chat_data_, string const &chat_data_)
  : inline_message_id_(inline_message_id_)
  , edit_public_data_(edit_public_data_)
  , public_data_(public_data_)
  , edit_chat_data_(edit_chat_data_)
  , chat_data_(chat_data_)
{}

const std::int32_t editInlineMessageWidgetData::ID;

void editInlineMessageWidgetData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageWidgetData");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_field("edit_public_data", edit_public_data_);
    s.store_field("public_data", public_data_);
    s.store_field("edit_chat_data", edit_chat_data_);
    s.store_field("chat_data", chat_data_);
    s.store_class_end();
  }
}

endGroupCallRecording::endGroupCallRecording()
  : group_call_id_()
{}

endGroupCallRecording::endGroupCallRecording(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t endGroupCallRecording::ID;

void endGroupCallRecording::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "endGroupCallRecording");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

fixRecognizedRichMessageWithAi::fixRecognizedRichMessageWithAi()
  : message_()
{}

fixRecognizedRichMessageWithAi::fixRecognizedRichMessageWithAi(object_ptr<inputRichMessage> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t fixRecognizedRichMessageWithAi::ID;

void fixRecognizedRichMessageWithAi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fixRecognizedRichMessageWithAi");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

getApplicationDownloadLink::getApplicationDownloadLink() {
}

const std::int32_t getApplicationDownloadLink::ID;

void getApplicationDownloadLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getApplicationDownloadLink");
    s.store_class_end();
  }
}

getAuthorizationState::getAuthorizationState() {
}

const std::int32_t getAuthorizationState::ID;

void getAuthorizationState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAuthorizationState");
    s.store_class_end();
  }
}

getChat::getChat()
  : chat_id_()
{}

getChat::getChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChat::ID;

void getChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatFolderDefaultIconName::getChatFolderDefaultIconName()
  : folder_()
{}

getChatFolderDefaultIconName::getChatFolderDefaultIconName(object_ptr<chatFolder> &&folder_)
  : folder_(std::move(folder_))
{}

const std::int32_t getChatFolderDefaultIconName::ID;

void getChatFolderDefaultIconName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolderDefaultIconName");
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_class_end();
  }
}

getChatJoinRequests::getChatJoinRequests()
  : chat_id_()
  , invite_link_()
  , query_()
  , offset_request_()
  , limit_()
{}

getChatJoinRequests::getChatJoinRequests(int53 chat_id_, string const &invite_link_, string const &query_, object_ptr<chatJoinRequest> &&offset_request_, int32 limit_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , query_(query_)
  , offset_request_(std::move(offset_request_))
  , limit_(limit_)
{}

const std::int32_t getChatJoinRequests::ID;

void getChatJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatJoinRequests");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("query", query_);
    s.store_object_field("offset_request", static_cast<const BaseObject *>(offset_request_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getCloseFriends::getCloseFriends() {
}

const std::int32_t getCloseFriends::ID;

void getCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCloseFriends");
    s.store_class_end();
  }
}

getCustomEmojiReactionAnimations::getCustomEmojiReactionAnimations() {
}

const std::int32_t getCustomEmojiReactionAnimations::ID;

void getCustomEmojiReactionAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCustomEmojiReactionAnimations");
    s.store_class_end();
  }
}

getForumTopicLink::getForumTopicLink()
  : chat_id_()
  , forum_topic_id_()
{}

getForumTopicLink::getForumTopicLink(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t getForumTopicLink::ID;

void getForumTopicLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getForumTopicLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

getGramWithdrawalUrl::getGramWithdrawalUrl()
  : password_()
{}

getGramWithdrawalUrl::getGramWithdrawalUrl(string const &password_)
  : password_(password_)
{}

const std::int32_t getGramWithdrawalUrl::ID;

void getGramWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGramWithdrawalUrl");
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

getGroupCallStreamSegment::getGroupCallStreamSegment()
  : group_call_id_()
  , time_offset_()
  , scale_()
  , channel_id_()
  , video_quality_()
{}

getGroupCallStreamSegment::getGroupCallStreamSegment(int32 group_call_id_, int53 time_offset_, int32 scale_, int32 channel_id_, object_ptr<GroupCallVideoQuality> &&video_quality_)
  : group_call_id_(group_call_id_)
  , time_offset_(time_offset_)
  , scale_(scale_)
  , channel_id_(channel_id_)
  , video_quality_(std::move(video_quality_))
{}

const std::int32_t getGroupCallStreamSegment::ID;

void getGroupCallStreamSegment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCallStreamSegment");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("time_offset", time_offset_);
    s.store_field("scale", scale_);
    s.store_field("channel_id", channel_id_);
    s.store_object_field("video_quality", static_cast<const BaseObject *>(video_quality_.get()));
    s.store_class_end();
  }
}

getJoinedCommunities::getJoinedCommunities() {
}

const std::int32_t getJoinedCommunities::ID;

void getJoinedCommunities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getJoinedCommunities");
    s.store_class_end();
  }
}

getLiveStoryTopDonors::getLiveStoryTopDonors()
  : group_call_id_()
{}

getLiveStoryTopDonors::getLiveStoryTopDonors(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getLiveStoryTopDonors::ID;

void getLiveStoryTopDonors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLiveStoryTopDonors");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getLogTagVerbosityLevel::getLogTagVerbosityLevel()
  : tag_()
{}

getLogTagVerbosityLevel::getLogTagVerbosityLevel(string const &tag_)
  : tag_(tag_)
{}

const std::int32_t getLogTagVerbosityLevel::ID;

void getLogTagVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogTagVerbosityLevel");
    s.store_field("tag", tag_);
    s.store_class_end();
  }
}

getLogVerbosityLevel::getLogVerbosityLevel() {
}

const std::int32_t getLogVerbosityLevel::ID;

void getLogVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogVerbosityLevel");
    s.store_class_end();
  }
}

getMenuButton::getMenuButton()
  : user_id_()
{}

getMenuButton::getMenuButton(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getMenuButton::ID;

void getMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMenuButton");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getMessages::getMessages()
  : chat_id_()
  , message_ids_()
{}

getMessages::getMessages(int53 chat_id_, array<int53> &&message_ids_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t getMessages::ID;

void getMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getNetworkStatistics::getNetworkStatistics()
  : only_current_()
{}

getNetworkStatistics::getNetworkStatistics(bool only_current_)
  : only_current_(only_current_)
{}

const std::int32_t getNetworkStatistics::ID;

void getNetworkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getNetworkStatistics");
    s.store_field("only_current", only_current_);
    s.store_class_end();
  }
}

getPaidMessageRevenue::getPaidMessageRevenue()
  : user_id_()
{}

getPaidMessageRevenue::getPaidMessageRevenue(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getPaidMessageRevenue::ID;

void getPaidMessageRevenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPaidMessageRevenue");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getPremiumLimit::getPremiumLimit()
  : limit_type_()
{}

getPremiumLimit::getPremiumLimit(object_ptr<PremiumLimitType> &&limit_type_)
  : limit_type_(std::move(limit_type_))
{}

const std::int32_t getPremiumLimit::ID;

void getPremiumLimit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumLimit");
    s.store_object_field("limit_type", static_cast<const BaseObject *>(limit_type_.get()));
    s.store_class_end();
  }
}

getSearchedForTags::getSearchedForTags()
  : tag_prefix_()
  , limit_()
{}

getSearchedForTags::getSearchedForTags(string const &tag_prefix_, int32 limit_)
  : tag_prefix_(tag_prefix_)
  , limit_(limit_)
{}

const std::int32_t getSearchedForTags::ID;

void getSearchedForTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSearchedForTags");
    s.store_field("tag_prefix", tag_prefix_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getSpeechRecognitionModels::getSpeechRecognitionModels()
  : version_()
{}

getSpeechRecognitionModels::getSpeechRecognitionModels(int32 version_)
  : version_(version_)
{}

const std::int32_t getSpeechRecognitionModels::ID;

void getSpeechRecognitionModels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSpeechRecognitionModels");
    s.store_field("version", version_);
    s.store_class_end();
  }
}

getThemedChatEmojiStatuses::getThemedChatEmojiStatuses() {
}

const std::int32_t getThemedChatEmojiStatuses::ID;

void getThemedChatEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getThemedChatEmojiStatuses");
    s.store_class_end();
  }
}

getThemedEmojiStatuses::getThemedEmojiStatuses() {
}

const std::int32_t getThemedEmojiStatuses::ID;

void getThemedEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getThemedEmojiStatuses");
    s.store_class_end();
  }
}

getTonTransactions::getTonTransactions()
  : direction_()
  , offset_()
  , limit_()
{}

getTonTransactions::getTonTransactions(object_ptr<TransactionDirection> &&direction_, string const &offset_, int32 limit_)
  : direction_(std::move(direction_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getTonTransactions::ID;

void getTonTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonTransactions");
    s.store_object_field("direction", static_cast<const BaseObject *>(direction_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getUserFullInfo::getUserFullInfo()
  : user_id_()
{}

getUserFullInfo::getUserFullInfo(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getUserFullInfo::ID;

void getUserFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserFullInfo");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getUserSupportInfo::getUserSupportInfo()
  : user_id_()
{}

getUserSupportInfo::getUserSupportInfo(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getUserSupportInfo::ID;

void getUserSupportInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserSupportInfo");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getVideoChatRtmpUrl::getVideoChatRtmpUrl()
  : chat_id_()
{}

getVideoChatRtmpUrl::getVideoChatRtmpUrl(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getVideoChatRtmpUrl::ID;

void getVideoChatRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getVideoChatRtmpUrl");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

processChatJoinRequest::processChatJoinRequest()
  : chat_id_()
  , user_id_()
  , approve_()
{}

processChatJoinRequest::processChatJoinRequest(int53 chat_id_, int53 user_id_, bool approve_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
  , approve_(approve_)
{}

const std::int32_t processChatJoinRequest::ID;

void processChatJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processChatJoinRequest");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("approve", approve_);
    s.store_class_end();
  }
}

rateSpeechRecognition::rateSpeechRecognition()
  : chat_id_()
  , message_id_()
  , is_good_()
{}

rateSpeechRecognition::rateSpeechRecognition(int53 chat_id_, int53 message_id_, bool is_good_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_good_(is_good_)
{}

const std::int32_t rateSpeechRecognition::ID;

void rateSpeechRecognition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "rateSpeechRecognition");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_good", is_good_);
    s.store_class_end();
  }
}

readAllChatReactions::readAllChatReactions()
  : chat_id_()
{}

readAllChatReactions::readAllChatReactions(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t readAllChatReactions::ID;

void readAllChatReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllChatReactions");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

readBusinessMessage::readBusinessMessage()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
{}

readBusinessMessage::readBusinessMessage(string const &business_connection_id_, int53 chat_id_, int53 message_id_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t readBusinessMessage::ID;

void readBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readBusinessMessage");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

readChatList::readChatList()
  : chat_list_()
{}

readChatList::readChatList(object_ptr<ChatList> &&chat_list_)
  : chat_list_(std::move(chat_list_))
{}

const std::int32_t readChatList::ID;

void readChatList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readChatList");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_class_end();
  }
}

recoverAuthenticationPassword::recoverAuthenticationPassword()
  : recovery_code_()
  , new_password_()
  , new_hint_()
{}

recoverAuthenticationPassword::recoverAuthenticationPassword(string const &recovery_code_, string const &new_password_, string const &new_hint_)
  : recovery_code_(recovery_code_)
  , new_password_(new_password_)
  , new_hint_(new_hint_)
{}

const std::int32_t recoverAuthenticationPassword::ID;

void recoverAuthenticationPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recoverAuthenticationPassword");
    s.store_field("recovery_code", "[REDACTED]");
    s.store_field("new_password", "[REDACTED]");
    s.store_field("new_hint", new_hint_);
    s.store_class_end();
  }
}

removeFileFromDownloads::removeFileFromDownloads()
  : file_id_()
  , delete_from_cache_()
{}

removeFileFromDownloads::removeFileFromDownloads(int32 file_id_, bool delete_from_cache_)
  : file_id_(file_id_)
  , delete_from_cache_(delete_from_cache_)
{}

const std::int32_t removeFileFromDownloads::ID;

void removeFileFromDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeFileFromDownloads");
    s.store_field("file_id", file_id_);
    s.store_field("delete_from_cache", delete_from_cache_);
    s.store_class_end();
  }
}

replaceLiveStoryRtmpUrl::replaceLiveStoryRtmpUrl()
  : chat_id_()
{}

replaceLiveStoryRtmpUrl::replaceLiveStoryRtmpUrl(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t replaceLiveStoryRtmpUrl::ID;

void replaceLiveStoryRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replaceLiveStoryRtmpUrl");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

reportVideoMessageAdvertisement::reportVideoMessageAdvertisement()
  : advertisement_unique_id_()
  , option_id_()
{}

reportVideoMessageAdvertisement::reportVideoMessageAdvertisement(int53 advertisement_unique_id_, bytes const &option_id_)
  : advertisement_unique_id_(advertisement_unique_id_)
  , option_id_(std::move(option_id_))
{}

const std::int32_t reportVideoMessageAdvertisement::ID;

void reportVideoMessageAdvertisement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportVideoMessageAdvertisement");
    s.store_field("advertisement_unique_id", advertisement_unique_id_);
    s.store_bytes_field("option_id", option_id_);
    s.store_class_end();
  }
}

requestAuthenticationPasswordRecovery::requestAuthenticationPasswordRecovery() {
}

const std::int32_t requestAuthenticationPasswordRecovery::ID;

void requestAuthenticationPasswordRecovery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestAuthenticationPasswordRecovery");
    s.store_class_end();
  }
}

resetNetworkStatistics::resetNetworkStatistics() {
}

const std::int32_t resetNetworkStatistics::ID;

void resetNetworkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetNetworkStatistics");
    s.store_class_end();
  }
}

searchChats::searchChats()
  : query_()
  , type_filter_()
  , limit_()
{}

searchChats::searchChats(string const &query_, object_ptr<SearchChatTypeFilter> &&type_filter_, int32 limit_)
  : query_(query_)
  , type_filter_(std::move(type_filter_))
  , limit_(limit_)
{}

const std::int32_t searchChats::ID;

void searchChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChats");
    s.store_field("query", query_);
    s.store_object_field("type_filter", static_cast<const BaseObject *>(type_filter_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchContacts::searchContacts()
  : query_()
  , limit_()
{}

searchContacts::searchContacts(string const &query_, int32 limit_)
  : query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchContacts::ID;

void searchContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchContacts");
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchInstalledStickerSets::searchInstalledStickerSets()
  : sticker_type_()
  , query_()
  , limit_()
{}

searchInstalledStickerSets::searchInstalledStickerSets(object_ptr<StickerType> &&sticker_type_, string const &query_, int32 limit_)
  : sticker_type_(std::move(sticker_type_))
  , query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchInstalledStickerSets::ID;

void searchInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchInstalledStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchPublicStoriesByVenue::searchPublicStoriesByVenue()
  : venue_provider_()
  , venue_id_()
  , offset_()
  , limit_()
{}

searchPublicStoriesByVenue::searchPublicStoriesByVenue(string const &venue_provider_, string const &venue_id_, string const &offset_, int32 limit_)
  : venue_provider_(venue_provider_)
  , venue_id_(venue_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchPublicStoriesByVenue::ID;

void searchPublicStoriesByVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicStoriesByVenue");
    s.store_field("venue_provider", venue_provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

sendCallSignalingData::sendCallSignalingData()
  : call_id_()
  , data_()
{}

sendCallSignalingData::sendCallSignalingData(int32 call_id_, bytes const &data_)
  : call_id_(call_id_)
  , data_(std::move(data_))
{}

const std::int32_t sendCallSignalingData::ID;

void sendCallSignalingData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallSignalingData");
    s.store_field("call_id", call_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

sendInlineQueryResultMessage::sendInlineQueryResultMessage()
  : chat_id_()
  , topic_id_()
  , reply_to_()
  , options_()
  , query_id_()
  , result_id_()
  , hide_via_bot_()
{}

sendInlineQueryResultMessage::sendInlineQueryResultMessage(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<InputMessageReplyTo> &&reply_to_, object_ptr<messageSendOptions> &&options_, int64 query_id_, string const &result_id_, bool hide_via_bot_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , reply_to_(std::move(reply_to_))
  , options_(std::move(options_))
  , query_id_(query_id_)
  , result_id_(result_id_)
  , hide_via_bot_(hide_via_bot_)
{}

const std::int32_t sendInlineQueryResultMessage::ID;

void sendInlineQueryResultMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendInlineQueryResultMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_field("query_id", query_id_);
    s.store_field("result_id", result_id_);
    s.store_field("hide_via_bot", hide_via_bot_);
    s.store_class_end();
  }
}

sendPaymentForm::sendPaymentForm()
  : input_invoice_()
  , payment_form_id_()
  , order_info_id_()
  , shipping_option_id_()
  , credentials_()
  , tip_amount_()
{}

sendPaymentForm::sendPaymentForm(object_ptr<InputInvoice> &&input_invoice_, int64 payment_form_id_, string const &order_info_id_, string const &shipping_option_id_, object_ptr<InputCredentials> &&credentials_, int53 tip_amount_)
  : input_invoice_(std::move(input_invoice_))
  , payment_form_id_(payment_form_id_)
  , order_info_id_(order_info_id_)
  , shipping_option_id_(shipping_option_id_)
  , credentials_(std::move(credentials_))
  , tip_amount_(tip_amount_)
{}

const std::int32_t sendPaymentForm::ID;

void sendPaymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPaymentForm");
    s.store_object_field("input_invoice", static_cast<const BaseObject *>(input_invoice_.get()));
    s.store_field("payment_form_id", payment_form_id_);
    s.store_field("order_info_id", order_info_id_);
    s.store_field("shipping_option_id", shipping_option_id_);
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    s.store_field("tip_amount", tip_amount_);
    s.store_class_end();
  }
}

sendTonWalletTransaction::sendTonWalletTransaction()
  : regular_transaction_data_()
  , gasless_transaction_data_()
{}

sendTonWalletTransaction::sendTonWalletTransaction(bytes const &regular_transaction_data_, bytes const &gasless_transaction_data_)
  : regular_transaction_data_(std::move(regular_transaction_data_))
  , gasless_transaction_data_(std::move(gasless_transaction_data_))
{}

const std::int32_t sendTonWalletTransaction::ID;

void sendTonWalletTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendTonWalletTransaction");
    s.store_bytes_field("regular_transaction_data", regular_transaction_data_);
    s.store_bytes_field("gasless_transaction_data", gasless_transaction_data_);
    s.store_class_end();
  }
}

setBotSettings::setBotSettings()
  : bot_user_id_()
  , settings_()
{}

setBotSettings::setBotSettings(int53 bot_user_id_, array<object_ptr<BotSetting>> &&settings_)
  : bot_user_id_(bot_user_id_)
  , settings_(std::move(settings_))
{}

const std::int32_t setBotSettings::ID;

void setBotSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotSettings");
    s.store_field("bot_user_id", bot_user_id_);
    { s.store_vector_begin("settings", settings_.size()); for (const auto &_value : settings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

setBusinessAccountGiftSettings::setBusinessAccountGiftSettings()
  : business_connection_id_()
  , settings_()
{}

setBusinessAccountGiftSettings::setBusinessAccountGiftSettings(string const &business_connection_id_, object_ptr<giftSettings> &&settings_)
  : business_connection_id_(business_connection_id_)
  , settings_(std::move(settings_))
{}

const std::int32_t setBusinessAccountGiftSettings::ID;

void setBusinessAccountGiftSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAccountGiftSettings");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setBusinessGreetingMessageSettings::setBusinessGreetingMessageSettings()
  : greeting_message_settings_()
{}

setBusinessGreetingMessageSettings::setBusinessGreetingMessageSettings(object_ptr<businessGreetingMessageSettings> &&greeting_message_settings_)
  : greeting_message_settings_(std::move(greeting_message_settings_))
{}

const std::int32_t setBusinessGreetingMessageSettings::ID;

void setBusinessGreetingMessageSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessGreetingMessageSettings");
    s.store_object_field("greeting_message_settings", static_cast<const BaseObject *>(greeting_message_settings_.get()));
    s.store_class_end();
  }
}

setBusinessLocation::setBusinessLocation()
  : location_()
{}

setBusinessLocation::setBusinessLocation(object_ptr<businessLocation> &&location_)
  : location_(std::move(location_))
{}

const std::int32_t setBusinessLocation::ID;

void setBusinessLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

setChatBackground::setChatBackground()
  : chat_id_()
  , background_()
  , type_()
  , dark_theme_dimming_()
  , only_for_self_()
{}

setChatBackground::setChatBackground(int53 chat_id_, object_ptr<InputBackground> &&background_, object_ptr<BackgroundType> &&type_, int32 dark_theme_dimming_, bool only_for_self_)
  : chat_id_(chat_id_)
  , background_(std::move(background_))
  , type_(std::move(type_))
  , dark_theme_dimming_(dark_theme_dimming_)
  , only_for_self_(only_for_self_)
{}

const std::int32_t setChatBackground::ID;

void setChatBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatBackground");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("dark_theme_dimming", dark_theme_dimming_);
    s.store_field("only_for_self", only_for_self_);
    s.store_class_end();
  }
}

setChatMessageAutoDeleteTime::setChatMessageAutoDeleteTime()
  : chat_id_()
  , message_auto_delete_time_()
{}

setChatMessageAutoDeleteTime::setChatMessageAutoDeleteTime(int53 chat_id_, int32 message_auto_delete_time_)
  : chat_id_(chat_id_)
  , message_auto_delete_time_(message_auto_delete_time_)
{}

const std::int32_t setChatMessageAutoDeleteTime::ID;

void setChatMessageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatMessageAutoDeleteTime");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_class_end();
  }
}

setChatPermissions::setChatPermissions()
  : chat_id_()
  , permissions_()
{}

setChatPermissions::setChatPermissions(int53 chat_id_, object_ptr<chatPermissions> &&permissions_)
  : chat_id_(chat_id_)
  , permissions_(std::move(permissions_))
{}

const std::int32_t setChatPermissions::ID;

void setChatPermissions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatPermissions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_class_end();
  }
}

setChatTheme::setChatTheme()
  : chat_id_()
  , theme_()
{}

setChatTheme::setChatTheme(int53 chat_id_, object_ptr<InputChatTheme> &&theme_)
  : chat_id_(chat_id_)
  , theme_(std::move(theme_))
{}

const std::int32_t setChatTheme::ID;

void setChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatTheme");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

setInactiveSessionTtl::setInactiveSessionTtl()
  : inactive_session_ttl_days_()
{}

setInactiveSessionTtl::setInactiveSessionTtl(int32 inactive_session_ttl_days_)
  : inactive_session_ttl_days_(inactive_session_ttl_days_)
{}

const std::int32_t setInactiveSessionTtl::ID;

void setInactiveSessionTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setInactiveSessionTtl");
    s.store_field("inactive_session_ttl_days", inactive_session_ttl_days_);
    s.store_class_end();
  }
}

setManagedBotAccessSettings::setManagedBotAccessSettings()
  : bot_user_id_()
  , settings_()
{}

setManagedBotAccessSettings::setManagedBotAccessSettings(int53 bot_user_id_, object_ptr<botAccessSettings> &&settings_)
  : bot_user_id_(bot_user_id_)
  , settings_(std::move(settings_))
{}

const std::int32_t setManagedBotAccessSettings::ID;

void setManagedBotAccessSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setManagedBotAccessSettings");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setPassportElementErrors::setPassportElementErrors()
  : user_id_()
  , errors_()
{}

setPassportElementErrors::setPassportElementErrors(int53 user_id_, array<object_ptr<inputPassportElementError>> &&errors_)
  : user_id_(user_id_)
  , errors_(std::move(errors_))
{}

const std::int32_t setPassportElementErrors::ID;

void setPassportElementErrors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPassportElementErrors");
    s.store_field("user_id", user_id_);
    { s.store_vector_begin("errors", errors_.size()); for (const auto &_value : errors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

setProfileAccentColor::setProfileAccentColor()
  : profile_accent_color_id_()
  , profile_background_custom_emoji_id_()
{}

setProfileAccentColor::setProfileAccentColor(int32 profile_accent_color_id_, int64 profile_background_custom_emoji_id_)
  : profile_accent_color_id_(profile_accent_color_id_)
  , profile_background_custom_emoji_id_(profile_background_custom_emoji_id_)
{}

const std::int32_t setProfileAccentColor::ID;

void setProfileAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setProfileAccentColor");
    s.store_field("profile_accent_color_id", profile_accent_color_id_);
    s.store_field("profile_background_custom_emoji_id", profile_background_custom_emoji_id_);
    s.store_class_end();
  }
}

setStickerPositionInSet::setStickerPositionInSet()
  : sticker_()
  , position_()
{}

setStickerPositionInSet::setStickerPositionInSet(object_ptr<InputFile> &&sticker_, int32 position_)
  : sticker_(std::move(sticker_))
  , position_(position_)
{}

const std::int32_t setStickerPositionInSet::ID;

void setStickerPositionInSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerPositionInSet");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("position", position_);
    s.store_class_end();
  }
}

setStickerSetThumbnail::setStickerSetThumbnail()
  : user_id_()
  , name_()
  , thumbnail_()
  , format_()
{}

setStickerSetThumbnail::setStickerSetThumbnail(int53 user_id_, string const &name_, object_ptr<InputFile> &&thumbnail_, object_ptr<StickerFormat> &&format_)
  : user_id_(user_id_)
  , name_(name_)
  , thumbnail_(std::move(thumbnail_))
  , format_(std::move(format_))
{}

const std::int32_t setStickerSetThumbnail::ID;

void setStickerSetThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerSetThumbnail");
    s.store_field("user_id", user_id_);
    s.store_field("name", name_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("format", static_cast<const BaseObject *>(format_.get()));
    s.store_class_end();
  }
}

setSupergroupStickerSet::setSupergroupStickerSet()
  : supergroup_id_()
  , sticker_set_id_()
{}

setSupergroupStickerSet::setSupergroupStickerSet(int53 supergroup_id_, int64 sticker_set_id_)
  : supergroup_id_(supergroup_id_)
  , sticker_set_id_(sticker_set_id_)
{}

const std::int32_t setSupergroupStickerSet::ID;

void setSupergroupStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupStickerSet");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("sticker_set_id", sticker_set_id_);
    s.store_class_end();
  }
}

testCallVectorStringObject::testCallVectorStringObject()
  : x_()
{}

testCallVectorStringObject::testCallVectorStringObject(array<object_ptr<testString>> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorStringObject::ID;

void testCallVectorStringObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorStringObject");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

toggleAllDownloadsArePaused::toggleAllDownloadsArePaused()
  : are_paused_()
{}

toggleAllDownloadsArePaused::toggleAllDownloadsArePaused(bool are_paused_)
  : are_paused_(are_paused_)
{}

const std::int32_t toggleAllDownloadsArePaused::ID;

void toggleAllDownloadsArePaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleAllDownloadsArePaused");
    s.store_field("are_paused", are_paused_);
    s.store_class_end();
  }
}

toggleBotUsernameIsActive::toggleBotUsernameIsActive()
  : bot_user_id_()
  , username_()
  , is_active_()
{}

toggleBotUsernameIsActive::toggleBotUsernameIsActive(int53 bot_user_id_, string const &username_, bool is_active_)
  : bot_user_id_(bot_user_id_)
  , username_(username_)
  , is_active_(is_active_)
{}

const std::int32_t toggleBotUsernameIsActive::ID;

void toggleBotUsernameIsActive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleBotUsernameIsActive");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("username", username_);
    s.store_field("is_active", is_active_);
    s.store_class_end();
  }
}

toggleChatFolderTags::toggleChatFolderTags()
  : are_tags_enabled_()
{}

toggleChatFolderTags::toggleChatFolderTags(bool are_tags_enabled_)
  : are_tags_enabled_(are_tags_enabled_)
{}

const std::int32_t toggleChatFolderTags::ID;

void toggleChatFolderTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatFolderTags");
    s.store_field("are_tags_enabled", are_tags_enabled_);
    s.store_class_end();
  }
}

toggleGroupCallIsMyVideoEnabled::toggleGroupCallIsMyVideoEnabled()
  : group_call_id_()
  , is_my_video_enabled_()
{}

toggleGroupCallIsMyVideoEnabled::toggleGroupCallIsMyVideoEnabled(int32 group_call_id_, bool is_my_video_enabled_)
  : group_call_id_(group_call_id_)
  , is_my_video_enabled_(is_my_video_enabled_)
{}

const std::int32_t toggleGroupCallIsMyVideoEnabled::ID;

void toggleGroupCallIsMyVideoEnabled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallIsMyVideoEnabled");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("is_my_video_enabled", is_my_video_enabled_);
    s.store_class_end();
  }
}

toggleSessionCanAcceptCalls::toggleSessionCanAcceptCalls()
  : session_id_()
  , can_accept_calls_()
{}

toggleSessionCanAcceptCalls::toggleSessionCanAcceptCalls(int64 session_id_, bool can_accept_calls_)
  : session_id_(session_id_)
  , can_accept_calls_(can_accept_calls_)
{}

const std::int32_t toggleSessionCanAcceptCalls::ID;

void toggleSessionCanAcceptCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSessionCanAcceptCalls");
    s.store_field("session_id", session_id_);
    s.store_field("can_accept_calls", can_accept_calls_);
    s.store_class_end();
  }
}

toggleUsernameIsActive::toggleUsernameIsActive()
  : username_()
  , is_active_()
{}

toggleUsernameIsActive::toggleUsernameIsActive(string const &username_, bool is_active_)
  : username_(username_)
  , is_active_(is_active_)
{}

const std::int32_t toggleUsernameIsActive::ID;

void toggleUsernameIsActive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleUsernameIsActive");
    s.store_field("username", username_);
    s.store_field("is_active", is_active_);
    s.store_class_end();
  }
}

toggleVideoChatMuteNewParticipants::toggleVideoChatMuteNewParticipants()
  : group_call_id_()
  , mute_new_participants_()
{}

toggleVideoChatMuteNewParticipants::toggleVideoChatMuteNewParticipants(int32 group_call_id_, bool mute_new_participants_)
  : group_call_id_(group_call_id_)
  , mute_new_participants_(mute_new_participants_)
{}

const std::int32_t toggleVideoChatMuteNewParticipants::ID;

void toggleVideoChatMuteNewParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleVideoChatMuteNewParticipants");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("mute_new_participants", mute_new_participants_);
    s.store_class_end();
  }
}

transferChatOwnership::transferChatOwnership()
  : chat_id_()
  , user_id_()
  , password_()
{}

transferChatOwnership::transferChatOwnership(int53 chat_id_, int53 user_id_, string const &password_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
  , password_(password_)
{}

const std::int32_t transferChatOwnership::ID;

void transferChatOwnership::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "transferChatOwnership");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

transferGift::transferGift()
  : business_connection_id_()
  , received_gift_id_()
  , new_owner_id_()
  , star_count_()
{}

transferGift::transferGift(string const &business_connection_id_, string const &received_gift_id_, object_ptr<MessageSender> &&new_owner_id_, int53 star_count_)
  : business_connection_id_(business_connection_id_)
  , received_gift_id_(received_gift_id_)
  , new_owner_id_(std::move(new_owner_id_))
  , star_count_(star_count_)
{}

const std::int32_t transferGift::ID;

void transferGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "transferGift");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("received_gift_id", received_gift_id_);
    s.store_object_field("new_owner_id", static_cast<const BaseObject *>(new_owner_id_.get()));
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

translateText::translateText()
  : text_()
  , to_language_code_()
  , tone_()
{}

translateText::translateText(object_ptr<formattedText> &&text_, string const &to_language_code_, string const &tone_)
  : text_(std::move(text_))
  , to_language_code_(to_language_code_)
  , tone_(tone_)
{}

const std::int32_t translateText::ID;

void translateText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "translateText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("to_language_code", to_language_code_);
    s.store_field("tone", tone_);
    s.store_class_end();
  }
}

upgradeGift::upgradeGift()
  : business_connection_id_()
  , received_gift_id_()
  , keep_original_details_()
  , star_count_()
{}

upgradeGift::upgradeGift(string const &business_connection_id_, string const &received_gift_id_, bool keep_original_details_, int53 star_count_)
  : business_connection_id_(business_connection_id_)
  , received_gift_id_(received_gift_id_)
  , keep_original_details_(keep_original_details_)
  , star_count_(star_count_)
{}

const std::int32_t upgradeGift::ID;

void upgradeGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradeGift");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("received_gift_id", received_gift_id_);
    s.store_field("keep_original_details", keep_original_details_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

writeGeneratedFilePart::writeGeneratedFilePart()
  : generation_id_()
  , offset_()
  , data_()
{}

writeGeneratedFilePart::writeGeneratedFilePart(int64 generation_id_, int53 offset_, bytes const &data_)
  : generation_id_(generation_id_)
  , offset_(offset_)
  , data_(std::move(data_))
{}

const std::int32_t writeGeneratedFilePart::ID;

void writeGeneratedFilePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "writeGeneratedFilePart");
    s.store_field("generation_id", generation_id_);
    s.store_field("offset", offset_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
