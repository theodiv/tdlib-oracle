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


accentColor::accentColor()
  : id_()
  , built_in_accent_color_id_()
  , light_theme_colors_()
  , dark_theme_colors_()
  , min_channel_chat_boost_level_()
{}

accentColor::accentColor(int32 id_, int32 built_in_accent_color_id_, array<int32> &&light_theme_colors_, array<int32> &&dark_theme_colors_, int32 min_channel_chat_boost_level_)
  : id_(id_)
  , built_in_accent_color_id_(built_in_accent_color_id_)
  , light_theme_colors_(std::move(light_theme_colors_))
  , dark_theme_colors_(std::move(dark_theme_colors_))
  , min_channel_chat_boost_level_(min_channel_chat_boost_level_)
{}

const std::int32_t accentColor::ID;

void accentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accentColor");
    s.store_field("id", id_);
    s.store_field("built_in_accent_color_id", built_in_accent_color_id_);
    { s.store_vector_begin("light_theme_colors", light_theme_colors_.size()); for (const auto &_value : light_theme_colors_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("dark_theme_colors", dark_theme_colors_.size()); for (const auto &_value : dark_theme_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("min_channel_chat_boost_level", min_channel_chat_boost_level_);
    s.store_class_end();
  }
}

affiliateInfo::affiliateInfo()
  : commission_per_mille_()
  , affiliate_chat_id_()
  , star_amount_()
{}

affiliateInfo::affiliateInfo(int32 commission_per_mille_, int53 affiliate_chat_id_, object_ptr<starAmount> &&star_amount_)
  : commission_per_mille_(commission_per_mille_)
  , affiliate_chat_id_(affiliate_chat_id_)
  , star_amount_(std::move(star_amount_))
{}

const std::int32_t affiliateInfo::ID;

void affiliateInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateInfo");
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_field("affiliate_chat_id", affiliate_chat_id_);
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    s.store_class_end();
  }
}

animatedEmoji::animatedEmoji()
  : sticker_()
  , sticker_width_()
  , sticker_height_()
  , fitzpatrick_type_()
  , sound_()
  , is_regular_emoji_()
{}

animatedEmoji::animatedEmoji(object_ptr<sticker> &&sticker_, int32 sticker_width_, int32 sticker_height_, int32 fitzpatrick_type_, object_ptr<file> &&sound_, bool is_regular_emoji_)
  : sticker_(std::move(sticker_))
  , sticker_width_(sticker_width_)
  , sticker_height_(sticker_height_)
  , fitzpatrick_type_(fitzpatrick_type_)
  , sound_(std::move(sound_))
  , is_regular_emoji_(is_regular_emoji_)
{}

const std::int32_t animatedEmoji::ID;

void animatedEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animatedEmoji");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("sticker_width", sticker_width_);
    s.store_field("sticker_height", sticker_height_);
    s.store_field("fitzpatrick_type", fitzpatrick_type_);
    s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get()));
    s.store_field("is_regular_emoji", is_regular_emoji_);
    s.store_class_end();
  }
}

auctionBid::auctionBid()
  : star_count_()
  , bid_date_()
  , position_()
{}

auctionBid::auctionBid(int53 star_count_, int32 bid_date_, int32 position_)
  : star_count_(star_count_)
  , bid_date_(bid_date_)
  , position_(position_)
{}

const std::int32_t auctionBid::ID;

void auctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auctionBid");
    s.store_field("star_count", star_count_);
    s.store_field("bid_date", bid_date_);
    s.store_field("position", position_);
    s.store_class_end();
  }
}

auctionStateActive::auctionStateActive()
  : start_date_()
  , end_date_()
  , min_bid_()
  , bid_levels_()
  , top_bidder_user_ids_()
  , rounds_()
  , current_round_end_date_()
  , current_round_number_()
  , total_round_count_()
  , distributed_item_count_()
  , left_item_count_()
  , acquired_item_count_()
  , user_bid_()
{}

auctionStateActive::auctionStateActive(int32 start_date_, int32 end_date_, int53 min_bid_, array<object_ptr<auctionBid>> &&bid_levels_, array<int53> &&top_bidder_user_ids_, array<object_ptr<auctionRound>> &&rounds_, int32 current_round_end_date_, int32 current_round_number_, int32 total_round_count_, int32 distributed_item_count_, int32 left_item_count_, int32 acquired_item_count_, object_ptr<userAuctionBid> &&user_bid_)
  : start_date_(start_date_)
  , end_date_(end_date_)
  , min_bid_(min_bid_)
  , bid_levels_(std::move(bid_levels_))
  , top_bidder_user_ids_(std::move(top_bidder_user_ids_))
  , rounds_(std::move(rounds_))
  , current_round_end_date_(current_round_end_date_)
  , current_round_number_(current_round_number_)
  , total_round_count_(total_round_count_)
  , distributed_item_count_(distributed_item_count_)
  , left_item_count_(left_item_count_)
  , acquired_item_count_(acquired_item_count_)
  , user_bid_(std::move(user_bid_))
{}

const std::int32_t auctionStateActive::ID;

void auctionStateActive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auctionStateActive");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_field("min_bid", min_bid_);
    { s.store_vector_begin("bid_levels", bid_levels_.size()); for (const auto &_value : bid_levels_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_bidder_user_ids", top_bidder_user_ids_.size()); for (const auto &_value : top_bidder_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("rounds", rounds_.size()); for (const auto &_value : rounds_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("current_round_end_date", current_round_end_date_);
    s.store_field("current_round_number", current_round_number_);
    s.store_field("total_round_count", total_round_count_);
    s.store_field("distributed_item_count", distributed_item_count_);
    s.store_field("left_item_count", left_item_count_);
    s.store_field("acquired_item_count", acquired_item_count_);
    s.store_object_field("user_bid", static_cast<const BaseObject *>(user_bid_.get()));
    s.store_class_end();
  }
}

auctionStateFinished::auctionStateFinished()
  : start_date_()
  , end_date_()
  , average_price_()
  , acquired_item_count_()
  , telegram_listed_item_count_()
  , fragment_listed_item_count_()
  , fragment_url_()
{}

auctionStateFinished::auctionStateFinished(int32 start_date_, int32 end_date_, int53 average_price_, int32 acquired_item_count_, int32 telegram_listed_item_count_, int32 fragment_listed_item_count_, string const &fragment_url_)
  : start_date_(start_date_)
  , end_date_(end_date_)
  , average_price_(average_price_)
  , acquired_item_count_(acquired_item_count_)
  , telegram_listed_item_count_(telegram_listed_item_count_)
  , fragment_listed_item_count_(fragment_listed_item_count_)
  , fragment_url_(fragment_url_)
{}

const std::int32_t auctionStateFinished::ID;

void auctionStateFinished::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auctionStateFinished");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_field("average_price", average_price_);
    s.store_field("acquired_item_count", acquired_item_count_);
    s.store_field("telegram_listed_item_count", telegram_listed_item_count_);
    s.store_field("fragment_listed_item_count", fragment_listed_item_count_);
    s.store_field("fragment_url", fragment_url_);
    s.store_class_end();
  }
}

botInfo::botInfo()
  : short_description_()
  , description_()
  , photo_()
  , animation_()
  , manager_bot_user_id_()
  , menu_button_()
  , commands_()
  , privacy_policy_url_()
  , default_group_administrator_rights_()
  , default_channel_administrator_rights_()
  , affiliate_program_()
  , web_app_background_light_color_()
  , web_app_background_dark_color_()
  , web_app_header_light_color_()
  , web_app_header_dark_color_()
  , verification_parameters_()
  , can_get_revenue_statistics_()
  , can_manage_emoji_status_()
  , has_media_previews_()
  , edit_commands_link_()
  , edit_description_link_()
  , edit_description_media_link_()
  , edit_settings_link_()
{}

botInfo::botInfo(string const &short_description_, string const &description_, object_ptr<photo> &&photo_, object_ptr<animation> &&animation_, int53 manager_bot_user_id_, object_ptr<botMenuButton> &&menu_button_, array<object_ptr<botCommand>> &&commands_, string const &privacy_policy_url_, object_ptr<chatAdministratorRights> &&default_group_administrator_rights_, object_ptr<chatAdministratorRights> &&default_channel_administrator_rights_, object_ptr<affiliateProgramInfo> &&affiliate_program_, int32 web_app_background_light_color_, int32 web_app_background_dark_color_, int32 web_app_header_light_color_, int32 web_app_header_dark_color_, object_ptr<botVerificationParameters> &&verification_parameters_, bool can_get_revenue_statistics_, bool can_manage_emoji_status_, bool has_media_previews_, object_ptr<InternalLinkType> &&edit_commands_link_, object_ptr<InternalLinkType> &&edit_description_link_, object_ptr<InternalLinkType> &&edit_description_media_link_, object_ptr<InternalLinkType> &&edit_settings_link_)
  : short_description_(short_description_)
  , description_(description_)
  , photo_(std::move(photo_))
  , animation_(std::move(animation_))
  , manager_bot_user_id_(manager_bot_user_id_)
  , menu_button_(std::move(menu_button_))
  , commands_(std::move(commands_))
  , privacy_policy_url_(privacy_policy_url_)
  , default_group_administrator_rights_(std::move(default_group_administrator_rights_))
  , default_channel_administrator_rights_(std::move(default_channel_administrator_rights_))
  , affiliate_program_(std::move(affiliate_program_))
  , web_app_background_light_color_(web_app_background_light_color_)
  , web_app_background_dark_color_(web_app_background_dark_color_)
  , web_app_header_light_color_(web_app_header_light_color_)
  , web_app_header_dark_color_(web_app_header_dark_color_)
  , verification_parameters_(std::move(verification_parameters_))
  , can_get_revenue_statistics_(can_get_revenue_statistics_)
  , can_manage_emoji_status_(can_manage_emoji_status_)
  , has_media_previews_(has_media_previews_)
  , edit_commands_link_(std::move(edit_commands_link_))
  , edit_description_link_(std::move(edit_description_link_))
  , edit_description_media_link_(std::move(edit_description_media_link_))
  , edit_settings_link_(std::move(edit_settings_link_))
{}

const std::int32_t botInfo::ID;

void botInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInfo");
    s.store_field("short_description", short_description_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_field("manager_bot_user_id", manager_bot_user_id_);
    s.store_object_field("menu_button", static_cast<const BaseObject *>(menu_button_.get()));
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("privacy_policy_url", privacy_policy_url_);
    s.store_object_field("default_group_administrator_rights", static_cast<const BaseObject *>(default_group_administrator_rights_.get()));
    s.store_object_field("default_channel_administrator_rights", static_cast<const BaseObject *>(default_channel_administrator_rights_.get()));
    s.store_object_field("affiliate_program", static_cast<const BaseObject *>(affiliate_program_.get()));
    s.store_field("web_app_background_light_color", web_app_background_light_color_);
    s.store_field("web_app_background_dark_color", web_app_background_dark_color_);
    s.store_field("web_app_header_light_color", web_app_header_light_color_);
    s.store_field("web_app_header_dark_color", web_app_header_dark_color_);
    s.store_object_field("verification_parameters", static_cast<const BaseObject *>(verification_parameters_.get()));
    s.store_field("can_get_revenue_statistics", can_get_revenue_statistics_);
    s.store_field("can_manage_emoji_status", can_manage_emoji_status_);
    s.store_field("has_media_previews", has_media_previews_);
    s.store_object_field("edit_commands_link", static_cast<const BaseObject *>(edit_commands_link_.get()));
    s.store_object_field("edit_description_link", static_cast<const BaseObject *>(edit_description_link_.get()));
    s.store_object_field("edit_description_media_link", static_cast<const BaseObject *>(edit_description_media_link_.get()));
    s.store_object_field("edit_settings_link", static_cast<const BaseObject *>(edit_settings_link_.get()));
    s.store_class_end();
  }
}

botVerificationParameters::botVerificationParameters()
  : icon_custom_emoji_id_()
  , organization_name_()
  , default_custom_description_()
  , can_set_custom_description_()
{}

botVerificationParameters::botVerificationParameters(int64 icon_custom_emoji_id_, string const &organization_name_, object_ptr<formattedText> &&default_custom_description_, bool can_set_custom_description_)
  : icon_custom_emoji_id_(icon_custom_emoji_id_)
  , organization_name_(organization_name_)
  , default_custom_description_(std::move(default_custom_description_))
  , can_set_custom_description_(can_set_custom_description_)
{}

const std::int32_t botVerificationParameters::ID;

void botVerificationParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botVerificationParameters");
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_field("organization_name", organization_name_);
    s.store_object_field("default_custom_description", static_cast<const BaseObject *>(default_custom_description_.get()));
    s.store_field("can_set_custom_description", can_set_custom_description_);
    s.store_class_end();
  }
}

businessBotRights::businessBotRights()
  : can_reply_()
  , can_read_messages_()
  , can_delete_sent_messages_()
  , can_delete_all_messages_()
  , can_edit_name_()
  , can_edit_bio_()
  , can_edit_profile_photo_()
  , can_edit_username_()
  , can_view_gifts_and_stars_()
  , can_sell_gifts_()
  , can_change_gift_settings_()
  , can_transfer_and_upgrade_gifts_()
  , can_transfer_stars_()
  , can_manage_stories_()
{}

businessBotRights::businessBotRights(bool can_reply_, bool can_read_messages_, bool can_delete_sent_messages_, bool can_delete_all_messages_, bool can_edit_name_, bool can_edit_bio_, bool can_edit_profile_photo_, bool can_edit_username_, bool can_view_gifts_and_stars_, bool can_sell_gifts_, bool can_change_gift_settings_, bool can_transfer_and_upgrade_gifts_, bool can_transfer_stars_, bool can_manage_stories_)
  : can_reply_(can_reply_)
  , can_read_messages_(can_read_messages_)
  , can_delete_sent_messages_(can_delete_sent_messages_)
  , can_delete_all_messages_(can_delete_all_messages_)
  , can_edit_name_(can_edit_name_)
  , can_edit_bio_(can_edit_bio_)
  , can_edit_profile_photo_(can_edit_profile_photo_)
  , can_edit_username_(can_edit_username_)
  , can_view_gifts_and_stars_(can_view_gifts_and_stars_)
  , can_sell_gifts_(can_sell_gifts_)
  , can_change_gift_settings_(can_change_gift_settings_)
  , can_transfer_and_upgrade_gifts_(can_transfer_and_upgrade_gifts_)
  , can_transfer_stars_(can_transfer_stars_)
  , can_manage_stories_(can_manage_stories_)
{}

const std::int32_t businessBotRights::ID;

void businessBotRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessBotRights");
    s.store_field("can_reply", can_reply_);
    s.store_field("can_read_messages", can_read_messages_);
    s.store_field("can_delete_sent_messages", can_delete_sent_messages_);
    s.store_field("can_delete_all_messages", can_delete_all_messages_);
    s.store_field("can_edit_name", can_edit_name_);
    s.store_field("can_edit_bio", can_edit_bio_);
    s.store_field("can_edit_profile_photo", can_edit_profile_photo_);
    s.store_field("can_edit_username", can_edit_username_);
    s.store_field("can_view_gifts_and_stars", can_view_gifts_and_stars_);
    s.store_field("can_sell_gifts", can_sell_gifts_);
    s.store_field("can_change_gift_settings", can_change_gift_settings_);
    s.store_field("can_transfer_and_upgrade_gifts", can_transfer_and_upgrade_gifts_);
    s.store_field("can_transfer_stars", can_transfer_stars_);
    s.store_field("can_manage_stories", can_manage_stories_);
    s.store_class_end();
  }
}

businessMessages::businessMessages()
  : messages_()
{}

businessMessages::businessMessages(array<object_ptr<businessMessage>> &&messages_)
  : messages_(std::move(messages_))
{}

const std::int32_t businessMessages::ID;

void businessMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessMessages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

callProblemEcho::callProblemEcho() {
}

const std::int32_t callProblemEcho::ID;

void callProblemEcho::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemEcho");
    s.store_class_end();
  }
}

callProblemNoise::callProblemNoise() {
}

const std::int32_t callProblemNoise::ID;

void callProblemNoise::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemNoise");
    s.store_class_end();
  }
}

callProblemInterruptions::callProblemInterruptions() {
}

const std::int32_t callProblemInterruptions::ID;

void callProblemInterruptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemInterruptions");
    s.store_class_end();
  }
}

callProblemDistortedSpeech::callProblemDistortedSpeech() {
}

const std::int32_t callProblemDistortedSpeech::ID;

void callProblemDistortedSpeech::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemDistortedSpeech");
    s.store_class_end();
  }
}

callProblemSilentLocal::callProblemSilentLocal() {
}

const std::int32_t callProblemSilentLocal::ID;

void callProblemSilentLocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemSilentLocal");
    s.store_class_end();
  }
}

callProblemSilentRemote::callProblemSilentRemote() {
}

const std::int32_t callProblemSilentRemote::ID;

void callProblemSilentRemote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemSilentRemote");
    s.store_class_end();
  }
}

callProblemDropped::callProblemDropped() {
}

const std::int32_t callProblemDropped::ID;

void callProblemDropped::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemDropped");
    s.store_class_end();
  }
}

callProblemDistortedVideo::callProblemDistortedVideo() {
}

const std::int32_t callProblemDistortedVideo::ID;

void callProblemDistortedVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemDistortedVideo");
    s.store_class_end();
  }
}

callProblemPixelatedVideo::callProblemPixelatedVideo() {
}

const std::int32_t callProblemPixelatedVideo::ID;

void callProblemPixelatedVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemPixelatedVideo");
    s.store_class_end();
  }
}

callbackQueryAnswer::callbackQueryAnswer()
  : text_()
  , show_alert_()
  , url_()
{}

callbackQueryAnswer::callbackQueryAnswer(string const &text_, bool show_alert_, string const &url_)
  : text_(text_)
  , show_alert_(show_alert_)
  , url_(url_)
{}

const std::int32_t callbackQueryAnswer::ID;

void callbackQueryAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryAnswer");
    s.store_field("text", text_);
    s.store_field("show_alert", show_alert_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

chat::chat()
  : id_()
  , type_()
  , title_()
  , photo_()
  , accent_color_id_()
  , background_custom_emoji_id_()
  , upgraded_gift_colors_()
  , profile_accent_color_id_()
  , profile_background_custom_emoji_id_()
  , permissions_()
  , last_message_()
  , positions_()
  , chat_lists_()
  , message_sender_id_()
  , block_list_()
  , has_protected_content_()
  , is_translatable_()
  , is_marked_as_unread_()
  , view_as_topics_()
  , has_scheduled_messages_()
  , has_welcome_messages_()
  , can_be_deleted_only_for_self_()
  , can_be_deleted_for_all_users_()
  , can_be_reported_()
  , default_disable_notification_()
  , unread_count_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , unread_mention_count_()
  , unread_reaction_count_()
  , unread_poll_vote_count_()
  , notification_settings_()
  , available_reactions_()
  , message_auto_delete_time_()
  , emoji_status_()
  , background_()
  , theme_()
  , action_bar_()
  , business_bot_manage_bar_()
  , video_chat_()
  , pending_join_requests_()
  , reply_markup_message_id_()
  , draft_message_()
  , text_composition_parameters_()
  , client_data_()
{}

chat::chat(int53 id_, object_ptr<ChatType> &&type_, string const &title_, object_ptr<chatPhotoInfo> &&photo_, int32 accent_color_id_, int64 background_custom_emoji_id_, object_ptr<upgradedGiftColors> &&upgraded_gift_colors_, int32 profile_accent_color_id_, int64 profile_background_custom_emoji_id_, object_ptr<chatPermissions> &&permissions_, object_ptr<message> &&last_message_, array<object_ptr<chatPosition>> &&positions_, array<object_ptr<ChatList>> &&chat_lists_, object_ptr<MessageSender> &&message_sender_id_, object_ptr<BlockList> &&block_list_, bool has_protected_content_, bool is_translatable_, bool is_marked_as_unread_, bool view_as_topics_, bool has_scheduled_messages_, bool has_welcome_messages_, bool can_be_deleted_only_for_self_, bool can_be_deleted_for_all_users_, bool can_be_reported_, bool default_disable_notification_, int32 unread_count_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int32 unread_mention_count_, int32 unread_reaction_count_, int32 unread_poll_vote_count_, object_ptr<chatNotificationSettings> &&notification_settings_, object_ptr<ChatAvailableReactions> &&available_reactions_, int32 message_auto_delete_time_, object_ptr<emojiStatus> &&emoji_status_, object_ptr<chatBackground> &&background_, object_ptr<ChatTheme> &&theme_, object_ptr<ChatActionBar> &&action_bar_, object_ptr<businessBotManageBar> &&business_bot_manage_bar_, object_ptr<videoChat> &&video_chat_, object_ptr<chatJoinRequestsInfo> &&pending_join_requests_, int53 reply_markup_message_id_, object_ptr<draftMessage> &&draft_message_, object_ptr<textCompositionParameters> &&text_composition_parameters_, string const &client_data_)
  : id_(id_)
  , type_(std::move(type_))
  , title_(title_)
  , photo_(std::move(photo_))
  , accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
  , upgraded_gift_colors_(std::move(upgraded_gift_colors_))
  , profile_accent_color_id_(profile_accent_color_id_)
  , profile_background_custom_emoji_id_(profile_background_custom_emoji_id_)
  , permissions_(std::move(permissions_))
  , last_message_(std::move(last_message_))
  , positions_(std::move(positions_))
  , chat_lists_(std::move(chat_lists_))
  , message_sender_id_(std::move(message_sender_id_))
  , block_list_(std::move(block_list_))
  , has_protected_content_(has_protected_content_)
  , is_translatable_(is_translatable_)
  , is_marked_as_unread_(is_marked_as_unread_)
  , view_as_topics_(view_as_topics_)
  , has_scheduled_messages_(has_scheduled_messages_)
  , has_welcome_messages_(has_welcome_messages_)
  , can_be_deleted_only_for_self_(can_be_deleted_only_for_self_)
  , can_be_deleted_for_all_users_(can_be_deleted_for_all_users_)
  , can_be_reported_(can_be_reported_)
  , default_disable_notification_(default_disable_notification_)
  , unread_count_(unread_count_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , unread_mention_count_(unread_mention_count_)
  , unread_reaction_count_(unread_reaction_count_)
  , unread_poll_vote_count_(unread_poll_vote_count_)
  , notification_settings_(std::move(notification_settings_))
  , available_reactions_(std::move(available_reactions_))
  , message_auto_delete_time_(message_auto_delete_time_)
  , emoji_status_(std::move(emoji_status_))
  , background_(std::move(background_))
  , theme_(std::move(theme_))
  , action_bar_(std::move(action_bar_))
  , business_bot_manage_bar_(std::move(business_bot_manage_bar_))
  , video_chat_(std::move(video_chat_))
  , pending_join_requests_(std::move(pending_join_requests_))
  , reply_markup_message_id_(reply_markup_message_id_)
  , draft_message_(std::move(draft_message_))
  , text_composition_parameters_(std::move(text_composition_parameters_))
  , client_data_(client_data_)
{}

const std::int32_t chat::ID;

void chat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chat");
    s.store_field("id", id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_object_field("upgraded_gift_colors", static_cast<const BaseObject *>(upgraded_gift_colors_.get()));
    s.store_field("profile_accent_color_id", profile_accent_color_id_);
    s.store_field("profile_background_custom_emoji_id", profile_background_custom_emoji_id_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chat_lists", chat_lists_.size()); for (const auto &_value : chat_lists_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_field("has_protected_content", has_protected_content_);
    s.store_field("is_translatable", is_translatable_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_field("view_as_topics", view_as_topics_);
    s.store_field("has_scheduled_messages", has_scheduled_messages_);
    s.store_field("has_welcome_messages", has_welcome_messages_);
    s.store_field("can_be_deleted_only_for_self", can_be_deleted_only_for_self_);
    s.store_field("can_be_deleted_for_all_users", can_be_deleted_for_all_users_);
    s.store_field("can_be_reported", can_be_reported_);
    s.store_field("default_disable_notification", default_disable_notification_);
    s.store_field("unread_count", unread_count_);
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_field("unread_poll_vote_count", unread_poll_vote_count_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get()));
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_object_field("action_bar", static_cast<const BaseObject *>(action_bar_.get()));
    s.store_object_field("business_bot_manage_bar", static_cast<const BaseObject *>(business_bot_manage_bar_.get()));
    s.store_object_field("video_chat", static_cast<const BaseObject *>(video_chat_.get()));
    s.store_object_field("pending_join_requests", static_cast<const BaseObject *>(pending_join_requests_.get()));
    s.store_field("reply_markup_message_id", reply_markup_message_id_);
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_object_field("text_composition_parameters", static_cast<const BaseObject *>(text_composition_parameters_.get()));
    s.store_field("client_data", client_data_);
    s.store_class_end();
  }
}

chatAdministrators::chatAdministrators()
  : administrators_()
{}

chatAdministrators::chatAdministrators(array<object_ptr<chatAdministrator>> &&administrators_)
  : administrators_(std::move(administrators_))
{}

const std::int32_t chatAdministrators::ID;

void chatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdministrators");
    { s.store_vector_begin("administrators", administrators_.size()); for (const auto &_value : administrators_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatBoostLinkInfo::chatBoostLinkInfo()
  : is_public_()
  , chat_id_()
{}

chatBoostLinkInfo::chatBoostLinkInfo(bool is_public_, int53 chat_id_)
  : is_public_(is_public_)
  , chat_id_(chat_id_)
{}

const std::int32_t chatBoostLinkInfo::ID;

void chatBoostLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostLinkInfo");
    s.store_field("is_public", is_public_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

chatBoostSourceGiftCode::chatBoostSourceGiftCode()
  : user_id_()
  , gift_code_()
{}

chatBoostSourceGiftCode::chatBoostSourceGiftCode(int53 user_id_, string const &gift_code_)
  : user_id_(user_id_)
  , gift_code_(gift_code_)
{}

const std::int32_t chatBoostSourceGiftCode::ID;

void chatBoostSourceGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostSourceGiftCode");
    s.store_field("user_id", user_id_);
    s.store_field("gift_code", gift_code_);
    s.store_class_end();
  }
}

chatBoostSourceGiveaway::chatBoostSourceGiveaway()
  : user_id_()
  , gift_code_()
  , star_count_()
  , giveaway_message_id_()
  , is_unclaimed_()
{}

chatBoostSourceGiveaway::chatBoostSourceGiveaway(int53 user_id_, string const &gift_code_, int53 star_count_, int53 giveaway_message_id_, bool is_unclaimed_)
  : user_id_(user_id_)
  , gift_code_(gift_code_)
  , star_count_(star_count_)
  , giveaway_message_id_(giveaway_message_id_)
  , is_unclaimed_(is_unclaimed_)
{}

const std::int32_t chatBoostSourceGiveaway::ID;

void chatBoostSourceGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostSourceGiveaway");
    s.store_field("user_id", user_id_);
    s.store_field("gift_code", gift_code_);
    s.store_field("star_count", star_count_);
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_field("is_unclaimed", is_unclaimed_);
    s.store_class_end();
  }
}

chatBoostSourcePremium::chatBoostSourcePremium()
  : user_id_()
{}

chatBoostSourcePremium::chatBoostSourcePremium(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t chatBoostSourcePremium::ID;

void chatBoostSourcePremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostSourcePremium");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

chatEvents::chatEvents()
  : events_()
{}

chatEvents::chatEvents(array<object_ptr<chatEvent>> &&events_)
  : events_(std::move(events_))
{}

const std::int32_t chatEvents::ID;

void chatEvents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEvents");
    { s.store_vector_begin("events", events_.size()); for (const auto &_value : events_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatFolderName::chatFolderName()
  : text_()
  , animate_custom_emoji_()
{}

chatFolderName::chatFolderName(object_ptr<formattedText> &&text_, bool animate_custom_emoji_)
  : text_(std::move(text_))
  , animate_custom_emoji_(animate_custom_emoji_)
{}

const std::int32_t chatFolderName::ID;

void chatFolderName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderName");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("animate_custom_emoji", animate_custom_emoji_);
    s.store_class_end();
  }
}

chatJoinRequestResultApproved::chatJoinRequestResultApproved() {
}

const std::int32_t chatJoinRequestResultApproved::ID;

void chatJoinRequestResultApproved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequestResultApproved");
    s.store_class_end();
  }
}

chatJoinRequestResultDeclined::chatJoinRequestResultDeclined() {
}

const std::int32_t chatJoinRequestResultDeclined::ID;

void chatJoinRequestResultDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequestResultDeclined");
    s.store_class_end();
  }
}

chatJoinRequestResultQueued::chatJoinRequestResultQueued() {
}

const std::int32_t chatJoinRequestResultQueued::ID;

void chatJoinRequestResultQueued::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequestResultQueued");
    s.store_class_end();
  }
}

chatJoinRequests::chatJoinRequests()
  : total_count_()
  , requests_()
{}

chatJoinRequests::chatJoinRequests(int32 total_count_, array<object_ptr<chatJoinRequest>> &&requests_)
  : total_count_(total_count_)
  , requests_(std::move(requests_))
{}

const std::int32_t chatJoinRequests::ID;

void chatJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequests");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("requests", requests_.size()); for (const auto &_value : requests_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatMessageSender::chatMessageSender()
  : sender_()
  , needs_premium_()
{}

chatMessageSender::chatMessageSender(object_ptr<MessageSender> &&sender_, bool needs_premium_)
  : sender_(std::move(sender_))
  , needs_premium_(needs_premium_)
{}

const std::int32_t chatMessageSender::ID;

void chatMessageSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMessageSender");
    s.store_object_field("sender", static_cast<const BaseObject *>(sender_.get()));
    s.store_field("needs_premium", needs_premium_);
    s.store_class_end();
  }
}

chatMessageSenders::chatMessageSenders()
  : senders_()
{}

chatMessageSenders::chatMessageSenders(array<object_ptr<chatMessageSender>> &&senders_)
  : senders_(std::move(senders_))
{}

const std::int32_t chatMessageSenders::ID;

void chatMessageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMessageSenders");
    { s.store_vector_begin("senders", senders_.size()); for (const auto &_value : senders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatRevenueTransaction::chatRevenueTransaction()
  : cryptocurrency_()
  , cryptocurrency_amount_()
  , type_()
{}

chatRevenueTransaction::chatRevenueTransaction(string const &cryptocurrency_, int64 cryptocurrency_amount_, object_ptr<ChatRevenueTransactionType> &&type_)
  : cryptocurrency_(cryptocurrency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , type_(std::move(type_))
{}

const std::int32_t chatRevenueTransaction::ID;

void chatRevenueTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransaction");
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

chatThemeEmoji::chatThemeEmoji()
  : name_()
{}

chatThemeEmoji::chatThemeEmoji(string const &name_)
  : name_(name_)
{}

const std::int32_t chatThemeEmoji::ID;

void chatThemeEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatThemeEmoji");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

chatThemeGift::chatThemeGift()
  : gift_theme_()
{}

chatThemeGift::chatThemeGift(object_ptr<giftChatTheme> &&gift_theme_)
  : gift_theme_(std::move(gift_theme_))
{}

const std::int32_t chatThemeGift::ID;

void chatThemeGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatThemeGift");
    s.store_object_field("gift_theme", static_cast<const BaseObject *>(gift_theme_.get()));
    s.store_class_end();
  }
}

checklist::checklist()
  : title_()
  , tasks_()
  , others_can_add_tasks_()
  , can_add_tasks_()
  , others_can_mark_tasks_as_done_()
  , can_mark_tasks_as_done_()
{}

checklist::checklist(object_ptr<formattedText> &&title_, array<object_ptr<checklistTask>> &&tasks_, bool others_can_add_tasks_, bool can_add_tasks_, bool others_can_mark_tasks_as_done_, bool can_mark_tasks_as_done_)
  : title_(std::move(title_))
  , tasks_(std::move(tasks_))
  , others_can_add_tasks_(others_can_add_tasks_)
  , can_add_tasks_(can_add_tasks_)
  , others_can_mark_tasks_as_done_(others_can_mark_tasks_as_done_)
  , can_mark_tasks_as_done_(can_mark_tasks_as_done_)
{}

const std::int32_t checklist::ID;

void checklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checklist");
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    { s.store_vector_begin("tasks", tasks_.size()); for (const auto &_value : tasks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("others_can_add_tasks", others_can_add_tasks_);
    s.store_field("can_add_tasks", can_add_tasks_);
    s.store_field("others_can_mark_tasks_as_done", others_can_mark_tasks_as_done_);
    s.store_field("can_mark_tasks_as_done", can_mark_tasks_as_done_);
    s.store_class_end();
  }
}

closeBirthdayUser::closeBirthdayUser()
  : user_id_()
  , birthdate_()
{}

closeBirthdayUser::closeBirthdayUser(int53 user_id_, object_ptr<birthdate> &&birthdate_)
  : user_id_(user_id_)
  , birthdate_(std::move(birthdate_))
{}

const std::int32_t closeBirthdayUser::ID;

void closeBirthdayUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeBirthdayUser");
    s.store_field("user_id", user_id_);
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_class_end();
  }
}

closedVectorPath::closedVectorPath()
  : commands_()
{}

closedVectorPath::closedVectorPath(array<object_ptr<VectorPathCommand>> &&commands_)
  : commands_(std::move(commands_))
{}

const std::int32_t closedVectorPath::ID;

void closedVectorPath::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closedVectorPath");
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

databaseStatistics::databaseStatistics()
  : statistics_()
{}

databaseStatistics::databaseStatistics(string const &statistics_)
  : statistics_(statistics_)
{}

const std::int32_t databaseStatistics::ID;

void databaseStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "databaseStatistics");
    s.store_field("statistics", statistics_);
    s.store_class_end();
  }
}

date::date()
  : day_()
  , month_()
  , year_()
{}

date::date(int32 day_, int32 month_, int32 year_)
  : day_(day_)
  , month_(month_)
  , year_(year_)
{}

const std::int32_t date::ID;

void date::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "date");
    s.store_field("day", day_);
    s.store_field("month", month_);
    s.store_field("year", year_);
    s.store_class_end();
  }
}

dateTimePartPrecisionNone::dateTimePartPrecisionNone() {
}

const std::int32_t dateTimePartPrecisionNone::ID;

void dateTimePartPrecisionNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateTimePartPrecisionNone");
    s.store_class_end();
  }
}

dateTimePartPrecisionShort::dateTimePartPrecisionShort() {
}

const std::int32_t dateTimePartPrecisionShort::ID;

void dateTimePartPrecisionShort::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateTimePartPrecisionShort");
    s.store_class_end();
  }
}

dateTimePartPrecisionLong::dateTimePartPrecisionLong() {
}

const std::int32_t dateTimePartPrecisionLong::ID;

void dateTimePartPrecisionLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateTimePartPrecisionLong");
    s.store_class_end();
  }
}

directMessagesChatTopic::directMessagesChatTopic()
  : chat_id_()
  , id_()
  , sender_id_()
  , order_()
  , can_send_unpaid_messages_()
  , is_marked_as_unread_()
  , unread_count_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , unread_reaction_count_()
  , last_message_()
  , draft_message_()
{}

directMessagesChatTopic::directMessagesChatTopic(int53 chat_id_, int53 id_, object_ptr<MessageSender> &&sender_id_, int64 order_, bool can_send_unpaid_messages_, bool is_marked_as_unread_, int53 unread_count_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int53 unread_reaction_count_, object_ptr<message> &&last_message_, object_ptr<draftMessage> &&draft_message_)
  : chat_id_(chat_id_)
  , id_(id_)
  , sender_id_(std::move(sender_id_))
  , order_(order_)
  , can_send_unpaid_messages_(can_send_unpaid_messages_)
  , is_marked_as_unread_(is_marked_as_unread_)
  , unread_count_(unread_count_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , unread_reaction_count_(unread_reaction_count_)
  , last_message_(std::move(last_message_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t directMessagesChatTopic::ID;

void directMessagesChatTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "directMessagesChatTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("id", id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("order", order_);
    s.store_field("can_send_unpaid_messages", can_send_unpaid_messages_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_field("unread_count", unread_count_);
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

emailAddressResetStateAvailable::emailAddressResetStateAvailable()
  : wait_period_()
{}

emailAddressResetStateAvailable::emailAddressResetStateAvailable(int32 wait_period_)
  : wait_period_(wait_period_)
{}

const std::int32_t emailAddressResetStateAvailable::ID;

void emailAddressResetStateAvailable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressResetStateAvailable");
    s.store_field("wait_period", wait_period_);
    s.store_class_end();
  }
}

emailAddressResetStatePending::emailAddressResetStatePending()
  : reset_in_()
{}

emailAddressResetStatePending::emailAddressResetStatePending(int32 reset_in_)
  : reset_in_(reset_in_)
{}

const std::int32_t emailAddressResetStatePending::ID;

void emailAddressResetStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressResetStatePending");
    s.store_field("reset_in", reset_in_);
    s.store_class_end();
  }
}

factCheck::factCheck()
  : text_()
  , country_code_()
{}

factCheck::factCheck(object_ptr<formattedText> &&text_, string const &country_code_)
  : text_(std::move(text_))
  , country_code_(country_code_)
{}

const std::int32_t factCheck::ID;

void factCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "factCheck");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("country_code", country_code_);
    s.store_class_end();
  }
}

failedToAddMembers::failedToAddMembers()
  : failed_to_add_members_()
{}

failedToAddMembers::failedToAddMembers(array<object_ptr<failedToAddMember>> &&failed_to_add_members_)
  : failed_to_add_members_(std::move(failed_to_add_members_))
{}

const std::int32_t failedToAddMembers::ID;

void failedToAddMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "failedToAddMembers");
    { s.store_vector_begin("failed_to_add_members", failed_to_add_members_.size()); for (const auto &_value : failed_to_add_members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

file::file()
  : id_()
  , size_()
  , expected_size_()
  , local_()
  , remote_()
{}

file::file(int32 id_, int53 size_, int53 expected_size_, object_ptr<localFile> &&local_, object_ptr<remoteFile> &&remote_)
  : id_(id_)
  , size_(size_)
  , expected_size_(expected_size_)
  , local_(std::move(local_))
  , remote_(std::move(remote_))
{}

const std::int32_t file::ID;

void file::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "file");
    s.store_field("id", id_);
    s.store_field("size", size_);
    s.store_field("expected_size", expected_size_);
    s.store_object_field("local", static_cast<const BaseObject *>(local_.get()));
    s.store_object_field("remote", static_cast<const BaseObject *>(remote_.get()));
    s.store_class_end();
  }
}

foundMessages::foundMessages()
  : total_count_()
  , messages_()
  , next_offset_()
{}

foundMessages::foundMessages(int32 total_count_, array<object_ptr<message>> &&messages_, string const &next_offset_)
  : total_count_(total_count_)
  , messages_(std::move(messages_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundMessages::ID;

void foundMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundMessages");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

foundPosition::foundPosition()
  : position_()
{}

foundPosition::foundPosition(int32 position_)
  : position_(position_)
{}

const std::int32_t foundPosition::ID;

void foundPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundPosition");
    s.store_field("position", position_);
    s.store_class_end();
  }
}

foundUsers::foundUsers()
  : user_ids_()
  , next_offset_()
{}

foundUsers::foundUsers(array<int53> &&user_ids_, string const &next_offset_)
  : user_ids_(std::move(user_ids_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundUsers::ID;

void foundUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundUsers");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

groupCallInfo::groupCallInfo()
  : group_call_id_()
  , join_payload_()
{}

groupCallInfo::groupCallInfo(int32 group_call_id_, string const &join_payload_)
  : group_call_id_(group_call_id_)
  , join_payload_(join_payload_)
{}

const std::int32_t groupCallInfo::ID;

void groupCallInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallInfo");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("join_payload", join_payload_);
    s.store_class_end();
  }
}

groupCallMessage::groupCallMessage()
  : message_id_()
  , sender_id_()
  , date_()
  , text_()
  , paid_message_star_count_()
  , is_from_owner_()
  , can_be_deleted_()
{}

groupCallMessage::groupCallMessage(int32 message_id_, object_ptr<MessageSender> &&sender_id_, int32 date_, object_ptr<formattedText> &&text_, int53 paid_message_star_count_, bool is_from_owner_, bool can_be_deleted_)
  : message_id_(message_id_)
  , sender_id_(std::move(sender_id_))
  , date_(date_)
  , text_(std::move(text_))
  , paid_message_star_count_(paid_message_star_count_)
  , is_from_owner_(is_from_owner_)
  , can_be_deleted_(can_be_deleted_)
{}

const std::int32_t groupCallMessage::ID;

void groupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallMessage");
    s.store_field("message_id", message_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("date", date_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_field("is_from_owner", is_from_owner_);
    s.store_field("can_be_deleted", can_be_deleted_);
    s.store_class_end();
  }
}

identityDocument::identityDocument()
  : number_()
  , expiration_date_()
  , front_side_()
  , reverse_side_()
  , selfie_()
  , translation_()
{}

identityDocument::identityDocument(string const &number_, object_ptr<date> &&expiration_date_, object_ptr<datedFile> &&front_side_, object_ptr<datedFile> &&reverse_side_, object_ptr<datedFile> &&selfie_, array<object_ptr<datedFile>> &&translation_)
  : number_(number_)
  , expiration_date_(std::move(expiration_date_))
  , front_side_(std::move(front_side_))
  , reverse_side_(std::move(reverse_side_))
  , selfie_(std::move(selfie_))
  , translation_(std::move(translation_))
{}

const std::int32_t identityDocument::ID;

void identityDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "identityDocument");
    s.store_field("number", number_);
    s.store_object_field("expiration_date", static_cast<const BaseObject *>(expiration_date_.get()));
    s.store_object_field("front_side", static_cast<const BaseObject *>(front_side_.get()));
    s.store_object_field("reverse_side", static_cast<const BaseObject *>(reverse_side_.get()));
    s.store_object_field("selfie", static_cast<const BaseObject *>(selfie_.get()));
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputBusinessChatLink::inputBusinessChatLink()
  : text_()
  , title_()
{}

inputBusinessChatLink::inputBusinessChatLink(object_ptr<formattedText> &&text_, string const &title_)
  : text_(std::move(text_))
  , title_(title_)
{}

const std::int32_t inputBusinessChatLink::ID;

void inputBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessChatLink");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

inputPassportElementPersonalDetails::inputPassportElementPersonalDetails()
  : personal_details_()
{}

inputPassportElementPersonalDetails::inputPassportElementPersonalDetails(object_ptr<personalDetails> &&personal_details_)
  : personal_details_(std::move(personal_details_))
{}

const std::int32_t inputPassportElementPersonalDetails::ID;

void inputPassportElementPersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPersonalDetails");
    s.store_object_field("personal_details", static_cast<const BaseObject *>(personal_details_.get()));
    s.store_class_end();
  }
}

inputPassportElementPassport::inputPassportElementPassport()
  : passport_()
{}

inputPassportElementPassport::inputPassportElementPassport(object_ptr<inputIdentityDocument> &&passport_)
  : passport_(std::move(passport_))
{}

const std::int32_t inputPassportElementPassport::ID;

void inputPassportElementPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPassport");
    s.store_object_field("passport", static_cast<const BaseObject *>(passport_.get()));
    s.store_class_end();
  }
}

inputPassportElementDriverLicense::inputPassportElementDriverLicense()
  : driver_license_()
{}

inputPassportElementDriverLicense::inputPassportElementDriverLicense(object_ptr<inputIdentityDocument> &&driver_license_)
  : driver_license_(std::move(driver_license_))
{}

const std::int32_t inputPassportElementDriverLicense::ID;

void inputPassportElementDriverLicense::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementDriverLicense");
    s.store_object_field("driver_license", static_cast<const BaseObject *>(driver_license_.get()));
    s.store_class_end();
  }
}

inputPassportElementIdentityCard::inputPassportElementIdentityCard()
  : identity_card_()
{}

inputPassportElementIdentityCard::inputPassportElementIdentityCard(object_ptr<inputIdentityDocument> &&identity_card_)
  : identity_card_(std::move(identity_card_))
{}

const std::int32_t inputPassportElementIdentityCard::ID;

void inputPassportElementIdentityCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementIdentityCard");
    s.store_object_field("identity_card", static_cast<const BaseObject *>(identity_card_.get()));
    s.store_class_end();
  }
}

inputPassportElementInternalPassport::inputPassportElementInternalPassport()
  : internal_passport_()
{}

inputPassportElementInternalPassport::inputPassportElementInternalPassport(object_ptr<inputIdentityDocument> &&internal_passport_)
  : internal_passport_(std::move(internal_passport_))
{}

const std::int32_t inputPassportElementInternalPassport::ID;

void inputPassportElementInternalPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementInternalPassport");
    s.store_object_field("internal_passport", static_cast<const BaseObject *>(internal_passport_.get()));
    s.store_class_end();
  }
}

inputPassportElementAddress::inputPassportElementAddress()
  : address_()
{}

inputPassportElementAddress::inputPassportElementAddress(object_ptr<address> &&address_)
  : address_(std::move(address_))
{}

const std::int32_t inputPassportElementAddress::ID;

void inputPassportElementAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementAddress");
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_class_end();
  }
}

inputPassportElementUtilityBill::inputPassportElementUtilityBill()
  : utility_bill_()
{}

inputPassportElementUtilityBill::inputPassportElementUtilityBill(object_ptr<inputPersonalDocument> &&utility_bill_)
  : utility_bill_(std::move(utility_bill_))
{}

const std::int32_t inputPassportElementUtilityBill::ID;

void inputPassportElementUtilityBill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementUtilityBill");
    s.store_object_field("utility_bill", static_cast<const BaseObject *>(utility_bill_.get()));
    s.store_class_end();
  }
}

inputPassportElementBankStatement::inputPassportElementBankStatement()
  : bank_statement_()
{}

inputPassportElementBankStatement::inputPassportElementBankStatement(object_ptr<inputPersonalDocument> &&bank_statement_)
  : bank_statement_(std::move(bank_statement_))
{}

const std::int32_t inputPassportElementBankStatement::ID;

void inputPassportElementBankStatement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementBankStatement");
    s.store_object_field("bank_statement", static_cast<const BaseObject *>(bank_statement_.get()));
    s.store_class_end();
  }
}

inputPassportElementRentalAgreement::inputPassportElementRentalAgreement()
  : rental_agreement_()
{}

inputPassportElementRentalAgreement::inputPassportElementRentalAgreement(object_ptr<inputPersonalDocument> &&rental_agreement_)
  : rental_agreement_(std::move(rental_agreement_))
{}

const std::int32_t inputPassportElementRentalAgreement::ID;

void inputPassportElementRentalAgreement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementRentalAgreement");
    s.store_object_field("rental_agreement", static_cast<const BaseObject *>(rental_agreement_.get()));
    s.store_class_end();
  }
}

inputPassportElementPassportRegistration::inputPassportElementPassportRegistration()
  : passport_registration_()
{}

inputPassportElementPassportRegistration::inputPassportElementPassportRegistration(object_ptr<inputPersonalDocument> &&passport_registration_)
  : passport_registration_(std::move(passport_registration_))
{}

const std::int32_t inputPassportElementPassportRegistration::ID;

void inputPassportElementPassportRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPassportRegistration");
    s.store_object_field("passport_registration", static_cast<const BaseObject *>(passport_registration_.get()));
    s.store_class_end();
  }
}

inputPassportElementTemporaryRegistration::inputPassportElementTemporaryRegistration()
  : temporary_registration_()
{}

inputPassportElementTemporaryRegistration::inputPassportElementTemporaryRegistration(object_ptr<inputPersonalDocument> &&temporary_registration_)
  : temporary_registration_(std::move(temporary_registration_))
{}

const std::int32_t inputPassportElementTemporaryRegistration::ID;

void inputPassportElementTemporaryRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementTemporaryRegistration");
    s.store_object_field("temporary_registration", static_cast<const BaseObject *>(temporary_registration_.get()));
    s.store_class_end();
  }
}

inputPassportElementPhoneNumber::inputPassportElementPhoneNumber()
  : phone_number_()
{}

inputPassportElementPhoneNumber::inputPassportElementPhoneNumber(string const &phone_number_)
  : phone_number_(phone_number_)
{}

const std::int32_t inputPassportElementPhoneNumber::ID;

void inputPassportElementPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

inputPassportElementEmailAddress::inputPassportElementEmailAddress()
  : email_address_()
{}

inputPassportElementEmailAddress::inputPassportElementEmailAddress(string const &email_address_)
  : email_address_(email_address_)
{}

const std::int32_t inputPassportElementEmailAddress::ID;

void inputPassportElementEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementEmailAddress");
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

inputPersonalDocument::inputPersonalDocument()
  : files_()
  , translation_()
{}

inputPersonalDocument::inputPersonalDocument(array<object_ptr<InputFile>> &&files_, array<object_ptr<InputFile>> &&translation_)
  : files_(std::move(files_))
  , translation_(std::move(translation_))
{}

const std::int32_t inputPersonalDocument::ID;

void inputPersonalDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPersonalDocument");
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPhoto::inputPhoto()
  : photo_()
  , thumbnail_()
  , video_()
  , added_sticker_file_ids_()
  , width_()
  , height_()
{}

inputPhoto::inputPhoto(object_ptr<InputFile> &&photo_, object_ptr<inputThumbnail> &&thumbnail_, object_ptr<InputFile> &&video_, array<int32> &&added_sticker_file_ids_, int32 width_, int32 height_)
  : photo_(std::move(photo_))
  , thumbnail_(std::move(thumbnail_))
  , video_(std::move(video_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , width_(width_)
  , height_(height_)
{}

const std::int32_t inputPhoto::ID;

void inputPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

inputPollMediaAnimation::inputPollMediaAnimation()
  : animation_()
{}

inputPollMediaAnimation::inputPollMediaAnimation(object_ptr<inputAnimation> &&animation_)
  : animation_(std::move(animation_))
{}

const std::int32_t inputPollMediaAnimation::ID;

void inputPollMediaAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollMediaAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

inputPollMediaAudio::inputPollMediaAudio()
  : audio_()
{}

inputPollMediaAudio::inputPollMediaAudio(object_ptr<inputAudio> &&audio_)
  : audio_(std::move(audio_))
{}

const std::int32_t inputPollMediaAudio::ID;

void inputPollMediaAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollMediaAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_class_end();
  }
}

inputPollMediaDocument::inputPollMediaDocument()
  : document_()
{}

inputPollMediaDocument::inputPollMediaDocument(object_ptr<inputDocument> &&document_)
  : document_(std::move(document_))
{}

const std::int32_t inputPollMediaDocument::ID;

void inputPollMediaDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollMediaDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_class_end();
  }
}

inputPollMediaLink::inputPollMediaLink()
  : url_()
{}

inputPollMediaLink::inputPollMediaLink(string const &url_)
  : url_(url_)
{}

const std::int32_t inputPollMediaLink::ID;

void inputPollMediaLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollMediaLink");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inputPollMediaLocation::inputPollMediaLocation()
  : location_()
{}

inputPollMediaLocation::inputPollMediaLocation(object_ptr<location> &&location_)
  : location_(std::move(location_))
{}

const std::int32_t inputPollMediaLocation::ID;

void inputPollMediaLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollMediaLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

inputPollMediaPhoto::inputPollMediaPhoto()
  : photo_()
{}

inputPollMediaPhoto::inputPollMediaPhoto(object_ptr<inputPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t inputPollMediaPhoto::ID;

void inputPollMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollMediaPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

inputPollMediaSticker::inputPollMediaSticker()
  : sticker_()
{}

inputPollMediaSticker::inputPollMediaSticker(object_ptr<inputSticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t inputPollMediaSticker::ID;

void inputPollMediaSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollMediaSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

inputPollMediaVenue::inputPollMediaVenue()
  : venue_()
{}

inputPollMediaVenue::inputPollMediaVenue(object_ptr<venue> &&venue_)
  : venue_(std::move(venue_))
{}

const std::int32_t inputPollMediaVenue::ID;

void inputPollMediaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollMediaVenue");
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_class_end();
  }
}

inputPollMediaVideo::inputPollMediaVideo()
  : video_()
{}

inputPollMediaVideo::inputPollMediaVideo(object_ptr<inputVideo> &&video_)
  : video_(std::move(video_))
{}

const std::int32_t inputPollMediaVideo::ID;

void inputPollMediaVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollMediaVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

inputStoryAreaTypeLocation::inputStoryAreaTypeLocation()
  : location_()
  , address_()
{}

inputStoryAreaTypeLocation::inputStoryAreaTypeLocation(object_ptr<location> &&location_, object_ptr<locationAddress> &&address_)
  : location_(std::move(location_))
  , address_(std::move(address_))
{}

const std::int32_t inputStoryAreaTypeLocation::ID;

void inputStoryAreaTypeLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_class_end();
  }
}

inputStoryAreaTypePreviousVenue::inputStoryAreaTypePreviousVenue()
  : venue_provider_()
  , venue_id_()
{}

inputStoryAreaTypePreviousVenue::inputStoryAreaTypePreviousVenue(string const &venue_provider_, string const &venue_id_)
  : venue_provider_(venue_provider_)
  , venue_id_(venue_id_)
{}

const std::int32_t inputStoryAreaTypePreviousVenue::ID;

void inputStoryAreaTypePreviousVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypePreviousVenue");
    s.store_field("venue_provider", venue_provider_);
    s.store_field("venue_id", venue_id_);
    s.store_class_end();
  }
}

inputStoryAreaTypeSuggestedReaction::inputStoryAreaTypeSuggestedReaction()
  : reaction_type_()
  , is_dark_()
  , is_flipped_()
{}

inputStoryAreaTypeSuggestedReaction::inputStoryAreaTypeSuggestedReaction(object_ptr<ReactionType> &&reaction_type_, bool is_dark_, bool is_flipped_)
  : reaction_type_(std::move(reaction_type_))
  , is_dark_(is_dark_)
  , is_flipped_(is_flipped_)
{}

const std::int32_t inputStoryAreaTypeSuggestedReaction::ID;

void inputStoryAreaTypeSuggestedReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeSuggestedReaction");
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("is_dark", is_dark_);
    s.store_field("is_flipped", is_flipped_);
    s.store_class_end();
  }
}

inputStoryAreaTypeMessage::inputStoryAreaTypeMessage()
  : chat_id_()
  , message_id_()
{}

inputStoryAreaTypeMessage::inputStoryAreaTypeMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t inputStoryAreaTypeMessage::ID;

void inputStoryAreaTypeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

inputStoryAreaTypeLink::inputStoryAreaTypeLink()
  : url_()
{}

inputStoryAreaTypeLink::inputStoryAreaTypeLink(string const &url_)
  : url_(url_)
{}

const std::int32_t inputStoryAreaTypeLink::ID;

void inputStoryAreaTypeLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeLink");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inputStoryAreaTypeWeather::inputStoryAreaTypeWeather()
  : temperature_()
  , emoji_()
  , background_color_()
{}

inputStoryAreaTypeWeather::inputStoryAreaTypeWeather(double temperature_, string const &emoji_, int32 background_color_)
  : temperature_(temperature_)
  , emoji_(emoji_)
  , background_color_(background_color_)
{}

const std::int32_t inputStoryAreaTypeWeather::ID;

void inputStoryAreaTypeWeather::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeWeather");
    s.store_field("temperature", temperature_);
    s.store_field("emoji", emoji_);
    s.store_field("background_color", background_color_);
    s.store_class_end();
  }
}

inputStoryAreaTypeUpgradedGift::inputStoryAreaTypeUpgradedGift()
  : gift_name_()
{}

inputStoryAreaTypeUpgradedGift::inputStoryAreaTypeUpgradedGift(string const &gift_name_)
  : gift_name_(gift_name_)
{}

const std::int32_t inputStoryAreaTypeUpgradedGift::ID;

void inputStoryAreaTypeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeUpgradedGift");
    s.store_field("gift_name", gift_name_);
    s.store_class_end();
  }
}

inputVoiceNote::inputVoiceNote()
  : voice_note_()
  , duration_()
  , waveform_()
{}

inputVoiceNote::inputVoiceNote(object_ptr<InputFile> &&voice_note_, int32 duration_, bytes const &waveform_)
  : voice_note_(std::move(voice_note_))
  , duration_(duration_)
  , waveform_(std::move(waveform_))
{}

const std::int32_t inputVoiceNote::ID;

void inputVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_field("duration", duration_);
    s.store_bytes_field("waveform", waveform_);
    s.store_class_end();
  }
}

languagePackInfo::languagePackInfo()
  : id_()
  , base_language_pack_id_()
  , name_()
  , native_name_()
  , plural_code_()
  , is_official_()
  , is_rtl_()
  , is_beta_()
  , is_installed_()
  , total_string_count_()
  , translated_string_count_()
  , local_string_count_()
  , translation_url_()
{}

languagePackInfo::languagePackInfo(string const &id_, string const &base_language_pack_id_, string const &name_, string const &native_name_, string const &plural_code_, bool is_official_, bool is_rtl_, bool is_beta_, bool is_installed_, int32 total_string_count_, int32 translated_string_count_, int32 local_string_count_, string const &translation_url_)
  : id_(id_)
  , base_language_pack_id_(base_language_pack_id_)
  , name_(name_)
  , native_name_(native_name_)
  , plural_code_(plural_code_)
  , is_official_(is_official_)
  , is_rtl_(is_rtl_)
  , is_beta_(is_beta_)
  , is_installed_(is_installed_)
  , total_string_count_(total_string_count_)
  , translated_string_count_(translated_string_count_)
  , local_string_count_(local_string_count_)
  , translation_url_(translation_url_)
{}

const std::int32_t languagePackInfo::ID;

void languagePackInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackInfo");
    s.store_field("id", id_);
    s.store_field("base_language_pack_id", base_language_pack_id_);
    s.store_field("name", name_);
    s.store_field("native_name", native_name_);
    s.store_field("plural_code", plural_code_);
    s.store_field("is_official", is_official_);
    s.store_field("is_rtl", is_rtl_);
    s.store_field("is_beta", is_beta_);
    s.store_field("is_installed", is_installed_);
    s.store_field("total_string_count", total_string_count_);
    s.store_field("translated_string_count", translated_string_count_);
    s.store_field("local_string_count", local_string_count_);
    s.store_field("translation_url", translation_url_);
    s.store_class_end();
  }
}

messageCopyOptions::messageCopyOptions()
  : send_copy_()
  , replace_caption_()
  , new_caption_()
  , new_show_caption_above_media_()
{}

messageCopyOptions::messageCopyOptions(bool send_copy_, bool replace_caption_, object_ptr<formattedText> &&new_caption_, bool new_show_caption_above_media_)
  : send_copy_(send_copy_)
  , replace_caption_(replace_caption_)
  , new_caption_(std::move(new_caption_))
  , new_show_caption_above_media_(new_show_caption_above_media_)
{}

const std::int32_t messageCopyOptions::ID;

void messageCopyOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCopyOptions");
    s.store_field("send_copy", send_copy_);
    s.store_field("replace_caption", replace_caption_);
    s.store_object_field("new_caption", static_cast<const BaseObject *>(new_caption_.get()));
    s.store_field("new_show_caption_above_media", new_show_caption_above_media_);
    s.store_class_end();
  }
}

messageEffect::messageEffect()
  : id_()
  , static_icon_()
  , emoji_()
  , is_premium_()
  , type_()
{}

messageEffect::messageEffect(int64 id_, object_ptr<sticker> &&static_icon_, string const &emoji_, bool is_premium_, object_ptr<MessageEffectType> &&type_)
  : id_(id_)
  , static_icon_(std::move(static_icon_))
  , emoji_(emoji_)
  , is_premium_(is_premium_)
  , type_(std::move(type_))
{}

const std::int32_t messageEffect::ID;

void messageEffect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEffect");
    s.store_field("id", id_);
    s.store_object_field("static_icon", static_cast<const BaseObject *>(static_icon_.get()));
    s.store_field("emoji", emoji_);
    s.store_field("is_premium", is_premium_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

messageReplyToMessage::messageReplyToMessage()
  : chat_id_()
  , message_id_()
  , quote_()
  , checklist_task_id_()
  , poll_option_id_()
  , origin_()
  , origin_send_date_()
  , content_()
{}

messageReplyToMessage::messageReplyToMessage(int53 chat_id_, int53 message_id_, object_ptr<textQuote> &&quote_, int32 checklist_task_id_, string const &poll_option_id_, object_ptr<MessageOrigin> &&origin_, int32 origin_send_date_, object_ptr<MessageContent> &&content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , quote_(std::move(quote_))
  , checklist_task_id_(checklist_task_id_)
  , poll_option_id_(poll_option_id_)
  , origin_(std::move(origin_))
  , origin_send_date_(origin_send_date_)
  , content_(std::move(content_))
{}

const std::int32_t messageReplyToMessage::ID;

void messageReplyToMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplyToMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("quote", static_cast<const BaseObject *>(quote_.get()));
    s.store_field("checklist_task_id", checklist_task_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_object_field("origin", static_cast<const BaseObject *>(origin_.get()));
    s.store_field("origin_send_date", origin_send_date_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

messageReplyToStory::messageReplyToStory()
  : story_poster_chat_id_()
  , story_id_()
{}

messageReplyToStory::messageReplyToStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t messageReplyToStory::ID;

void messageReplyToStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplyToStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

onRampPaymentLimits::onRampPaymentLimits()
  : payment_method_()
  , base_currency_min_amount_()
  , base_currency_max_amount_()
  , cryptocurrency_min_amount_()
  , cryptocurrency_max_amount_()
{}

onRampPaymentLimits::onRampPaymentLimits(string const &payment_method_, string const &base_currency_min_amount_, string const &base_currency_max_amount_, string const &cryptocurrency_min_amount_, string const &cryptocurrency_max_amount_)
  : payment_method_(payment_method_)
  , base_currency_min_amount_(base_currency_min_amount_)
  , base_currency_max_amount_(base_currency_max_amount_)
  , cryptocurrency_min_amount_(cryptocurrency_min_amount_)
  , cryptocurrency_max_amount_(cryptocurrency_max_amount_)
{}

const std::int32_t onRampPaymentLimits::ID;

void onRampPaymentLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onRampPaymentLimits");
    s.store_field("payment_method", payment_method_);
    s.store_field("base_currency_min_amount", base_currency_min_amount_);
    s.store_field("base_currency_max_amount", base_currency_max_amount_);
    s.store_field("cryptocurrency_min_amount", cryptocurrency_min_amount_);
    s.store_field("cryptocurrency_max_amount", cryptocurrency_max_amount_);
    s.store_class_end();
  }
}

outline::outline()
  : paths_()
{}

outline::outline(array<object_ptr<closedVectorPath>> &&paths_)
  : paths_(std::move(paths_))
{}

const std::int32_t outline::ID;

void outline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "outline");
    { s.store_vector_begin("paths", paths_.size()); for (const auto &_value : paths_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

photo::photo()
  : has_stickers_()
  , minithumbnail_()
  , sizes_()
{}

photo::photo(bool has_stickers_, object_ptr<minithumbnail> &&minithumbnail_, array<object_ptr<photoSize>> &&sizes_)
  : has_stickers_(has_stickers_)
  , minithumbnail_(std::move(minithumbnail_))
  , sizes_(std::move(sizes_))
{}

const std::int32_t photo::ID;

void photo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photo");
    s.store_field("has_stickers", has_stickers_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    { s.store_vector_begin("sizes", sizes_.size()); for (const auto &_value : sizes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pollVoteStatistics::pollVoteStatistics()
  : vote_graph_()
{}

pollVoteStatistics::pollVoteStatistics(object_ptr<StatisticalGraph> &&vote_graph_)
  : vote_graph_(std::move(vote_graph_))
{}

const std::int32_t pollVoteStatistics::ID;

void pollVoteStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollVoteStatistics");
    s.store_object_field("vote_graph", static_cast<const BaseObject *>(vote_graph_.get()));
    s.store_class_end();
  }
}

premiumGiftPaymentOptions::premiumGiftPaymentOptions()
  : options_()
{}

premiumGiftPaymentOptions::premiumGiftPaymentOptions(array<object_ptr<premiumGiftPaymentOption>> &&options_)
  : options_(std::move(options_))
{}

const std::int32_t premiumGiftPaymentOptions::ID;

void premiumGiftPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiftPaymentOptions");
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportOption::reportOption()
  : id_()
  , text_()
{}

reportOption::reportOption(bytes const &id_, string const &text_)
  : id_(std::move(id_))
  , text_(text_)
{}

const std::int32_t reportOption::ID;

void reportOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportOption");
    s.store_bytes_field("id", id_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

restrictionInfo::restrictionInfo()
  : restriction_reason_()
  , has_sensitive_content_()
{}

restrictionInfo::restrictionInfo(string const &restriction_reason_, bool has_sensitive_content_)
  : restriction_reason_(restriction_reason_)
  , has_sensitive_content_(has_sensitive_content_)
{}

const std::int32_t restrictionInfo::ID;

void restrictionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "restrictionInfo");
    s.store_field("restriction_reason", restriction_reason_);
    s.store_field("has_sensitive_content", has_sensitive_content_);
    s.store_class_end();
  }
}

sponsoredMessages::sponsoredMessages()
  : messages_()
  , messages_between_()
{}

sponsoredMessages::sponsoredMessages(array<object_ptr<sponsoredMessage>> &&messages_, int32 messages_between_)
  : messages_(std::move(messages_))
  , messages_between_(messages_between_)
{}

const std::int32_t sponsoredMessages::ID;

void sponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredMessages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("messages_between", messages_between_);
    s.store_class_end();
  }
}

starAmount::starAmount()
  : star_count_()
  , nanostar_count_()
{}

starAmount::starAmount(int53 star_count_, int32 nanostar_count_)
  : star_count_(star_count_)
  , nanostar_count_(nanostar_count_)
{}

const std::int32_t starAmount::ID;

void starAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starAmount");
    s.store_field("star_count", star_count_);
    s.store_field("nanostar_count", nanostar_count_);
    s.store_class_end();
  }
}

starTransaction::starTransaction()
  : id_()
  , star_amount_()
  , is_refund_()
  , date_()
  , type_()
{}

starTransaction::starTransaction(string const &id_, object_ptr<starAmount> &&star_amount_, bool is_refund_, int32 date_, object_ptr<StarTransactionType> &&type_)
  : id_(id_)
  , star_amount_(std::move(star_amount_))
  , is_refund_(is_refund_)
  , date_(date_)
  , type_(std::move(type_))
{}

const std::int32_t starTransaction::ID;

void starTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransaction");
    s.store_field("id", id_);
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    s.store_field("is_refund", is_refund_);
    s.store_field("date", date_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

stickerFormatWebp::stickerFormatWebp() {
}

const std::int32_t stickerFormatWebp::ID;

void stickerFormatWebp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFormatWebp");
    s.store_class_end();
  }
}

stickerFormatTgs::stickerFormatTgs() {
}

const std::int32_t stickerFormatTgs::ID;

void stickerFormatTgs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFormatTgs");
    s.store_class_end();
  }
}

stickerFormatWebm::stickerFormatWebm() {
}

const std::int32_t stickerFormatWebm::ID;

void stickerFormatWebm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFormatWebm");
    s.store_class_end();
  }
}

story::story()
  : id_()
  , poster_chat_id_()
  , poster_id_()
  , date_()
  , is_being_posted_()
  , is_being_edited_()
  , is_edited_()
  , is_posted_to_chat_page_()
  , is_visible_only_for_self_()
  , can_be_added_to_album_()
  , can_be_deleted_()
  , can_be_edited_()
  , can_be_forwarded_()
  , can_be_replied_()
  , can_set_privacy_settings_()
  , can_toggle_is_posted_to_chat_page_()
  , can_get_statistics_()
  , can_get_interactions_()
  , has_expired_viewers_()
  , repost_info_()
  , interaction_info_()
  , chosen_reaction_type_()
  , privacy_settings_()
  , content_()
  , areas_()
  , caption_()
  , music_()
  , album_ids_()
{}

story::story(int32 id_, int53 poster_chat_id_, object_ptr<MessageSender> &&poster_id_, int32 date_, bool is_being_posted_, bool is_being_edited_, bool is_edited_, bool is_posted_to_chat_page_, bool is_visible_only_for_self_, bool can_be_added_to_album_, bool can_be_deleted_, bool can_be_edited_, bool can_be_forwarded_, bool can_be_replied_, bool can_set_privacy_settings_, bool can_toggle_is_posted_to_chat_page_, bool can_get_statistics_, bool can_get_interactions_, bool has_expired_viewers_, object_ptr<storyRepostInfo> &&repost_info_, object_ptr<storyInteractionInfo> &&interaction_info_, object_ptr<ReactionType> &&chosen_reaction_type_, object_ptr<StoryPrivacySettings> &&privacy_settings_, object_ptr<StoryContent> &&content_, array<object_ptr<storyArea>> &&areas_, object_ptr<formattedText> &&caption_, object_ptr<audio> &&music_, array<int32> &&album_ids_)
  : id_(id_)
  , poster_chat_id_(poster_chat_id_)
  , poster_id_(std::move(poster_id_))
  , date_(date_)
  , is_being_posted_(is_being_posted_)
  , is_being_edited_(is_being_edited_)
  , is_edited_(is_edited_)
  , is_posted_to_chat_page_(is_posted_to_chat_page_)
  , is_visible_only_for_self_(is_visible_only_for_self_)
  , can_be_added_to_album_(can_be_added_to_album_)
  , can_be_deleted_(can_be_deleted_)
  , can_be_edited_(can_be_edited_)
  , can_be_forwarded_(can_be_forwarded_)
  , can_be_replied_(can_be_replied_)
  , can_set_privacy_settings_(can_set_privacy_settings_)
  , can_toggle_is_posted_to_chat_page_(can_toggle_is_posted_to_chat_page_)
  , can_get_statistics_(can_get_statistics_)
  , can_get_interactions_(can_get_interactions_)
  , has_expired_viewers_(has_expired_viewers_)
  , repost_info_(std::move(repost_info_))
  , interaction_info_(std::move(interaction_info_))
  , chosen_reaction_type_(std::move(chosen_reaction_type_))
  , privacy_settings_(std::move(privacy_settings_))
  , content_(std::move(content_))
  , areas_(std::move(areas_))
  , caption_(std::move(caption_))
  , music_(std::move(music_))
  , album_ids_(std::move(album_ids_))
{}

const std::int32_t story::ID;

void story::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "story");
    s.store_field("id", id_);
    s.store_field("poster_chat_id", poster_chat_id_);
    s.store_object_field("poster_id", static_cast<const BaseObject *>(poster_id_.get()));
    s.store_field("date", date_);
    s.store_field("is_being_posted", is_being_posted_);
    s.store_field("is_being_edited", is_being_edited_);
    s.store_field("is_edited", is_edited_);
    s.store_field("is_posted_to_chat_page", is_posted_to_chat_page_);
    s.store_field("is_visible_only_for_self", is_visible_only_for_self_);
    s.store_field("can_be_added_to_album", can_be_added_to_album_);
    s.store_field("can_be_deleted", can_be_deleted_);
    s.store_field("can_be_edited", can_be_edited_);
    s.store_field("can_be_forwarded", can_be_forwarded_);
    s.store_field("can_be_replied", can_be_replied_);
    s.store_field("can_set_privacy_settings", can_set_privacy_settings_);
    s.store_field("can_toggle_is_posted_to_chat_page", can_toggle_is_posted_to_chat_page_);
    s.store_field("can_get_statistics", can_get_statistics_);
    s.store_field("can_get_interactions", can_get_interactions_);
    s.store_field("has_expired_viewers", has_expired_viewers_);
    s.store_object_field("repost_info", static_cast<const BaseObject *>(repost_info_.get()));
    s.store_object_field("interaction_info", static_cast<const BaseObject *>(interaction_info_.get()));
    s.store_object_field("chosen_reaction_type", static_cast<const BaseObject *>(chosen_reaction_type_.get()));
    s.store_object_field("privacy_settings", static_cast<const BaseObject *>(privacy_settings_.get()));
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    { s.store_vector_begin("areas", areas_.size()); for (const auto &_value : areas_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_object_field("music", static_cast<const BaseObject *>(music_.get()));
    { s.store_vector_begin("album_ids", album_ids_.size()); for (const auto &_value : album_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyArea::storyArea()
  : position_()
  , type_()
{}

storyArea::storyArea(object_ptr<areaPosition> &&position_, object_ptr<StoryAreaType> &&type_)
  : position_(std::move(position_))
  , type_(std::move(type_))
{}

const std::int32_t storyArea::ID;

void storyArea::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyArea");
    s.store_object_field("position", static_cast<const BaseObject *>(position_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

storyContentPhoto::storyContentPhoto()
  : photo_()
{}

storyContentPhoto::storyContentPhoto(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t storyContentPhoto::ID;

void storyContentPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

storyContentVideo::storyContentVideo()
  : video_()
  , alternative_video_()
{}

storyContentVideo::storyContentVideo(object_ptr<storyVideo> &&video_, object_ptr<storyVideo> &&alternative_video_)
  : video_(std::move(video_))
  , alternative_video_(std::move(alternative_video_))
{}

const std::int32_t storyContentVideo::ID;

void storyContentVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("alternative_video", static_cast<const BaseObject *>(alternative_video_.get()));
    s.store_class_end();
  }
}

storyContentLive::storyContentLive()
  : group_call_id_()
  , is_rtmp_stream_()
{}

storyContentLive::storyContentLive(int32 group_call_id_, bool is_rtmp_stream_)
  : group_call_id_(group_call_id_)
  , is_rtmp_stream_(is_rtmp_stream_)
{}

const std::int32_t storyContentLive::ID;

void storyContentLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentLive");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("is_rtmp_stream", is_rtmp_stream_);
    s.store_class_end();
  }
}

storyContentUnsupported::storyContentUnsupported() {
}

const std::int32_t storyContentUnsupported::ID;

void storyContentUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentUnsupported");
    s.store_class_end();
  }
}

storyRepostInfo::storyRepostInfo()
  : origin_()
  , is_content_modified_()
{}

storyRepostInfo::storyRepostInfo(object_ptr<StoryOrigin> &&origin_, bool is_content_modified_)
  : origin_(std::move(origin_))
  , is_content_modified_(is_content_modified_)
{}

const std::int32_t storyRepostInfo::ID;

void storyRepostInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyRepostInfo");
    s.store_object_field("origin", static_cast<const BaseObject *>(origin_.get()));
    s.store_field("is_content_modified", is_content_modified_);
    s.store_class_end();
  }
}

suggestedActionEnableArchiveAndMuteNewChats::suggestedActionEnableArchiveAndMuteNewChats() {
}

const std::int32_t suggestedActionEnableArchiveAndMuteNewChats::ID;

void suggestedActionEnableArchiveAndMuteNewChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionEnableArchiveAndMuteNewChats");
    s.store_class_end();
  }
}

suggestedActionCheckPassword::suggestedActionCheckPassword() {
}

const std::int32_t suggestedActionCheckPassword::ID;

void suggestedActionCheckPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionCheckPassword");
    s.store_class_end();
  }
}

suggestedActionCheckPhoneNumber::suggestedActionCheckPhoneNumber() {
}

const std::int32_t suggestedActionCheckPhoneNumber::ID;

void suggestedActionCheckPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionCheckPhoneNumber");
    s.store_class_end();
  }
}

suggestedActionViewChecksHint::suggestedActionViewChecksHint() {
}

const std::int32_t suggestedActionViewChecksHint::ID;

void suggestedActionViewChecksHint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionViewChecksHint");
    s.store_class_end();
  }
}

suggestedActionViewFirstTonWalletTransferHint::suggestedActionViewFirstTonWalletTransferHint() {
}

const std::int32_t suggestedActionViewFirstTonWalletTransferHint::ID;

void suggestedActionViewFirstTonWalletTransferHint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionViewFirstTonWalletTransferHint");
    s.store_class_end();
  }
}

suggestedActionConvertToBroadcastGroup::suggestedActionConvertToBroadcastGroup()
  : supergroup_id_()
{}

suggestedActionConvertToBroadcastGroup::suggestedActionConvertToBroadcastGroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t suggestedActionConvertToBroadcastGroup::ID;

void suggestedActionConvertToBroadcastGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionConvertToBroadcastGroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

suggestedActionSetPassword::suggestedActionSetPassword()
  : authorization_delay_()
{}

suggestedActionSetPassword::suggestedActionSetPassword(int32 authorization_delay_)
  : authorization_delay_(authorization_delay_)
{}

const std::int32_t suggestedActionSetPassword::ID;

void suggestedActionSetPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionSetPassword");
    s.store_field("authorization_delay", authorization_delay_);
    s.store_class_end();
  }
}

suggestedActionUpgradePremium::suggestedActionUpgradePremium() {
}

const std::int32_t suggestedActionUpgradePremium::ID;

void suggestedActionUpgradePremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionUpgradePremium");
    s.store_class_end();
  }
}

suggestedActionRestorePremium::suggestedActionRestorePremium() {
}

const std::int32_t suggestedActionRestorePremium::ID;

void suggestedActionRestorePremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionRestorePremium");
    s.store_class_end();
  }
}

suggestedActionSubscribeToAnnualPremium::suggestedActionSubscribeToAnnualPremium() {
}

const std::int32_t suggestedActionSubscribeToAnnualPremium::ID;

void suggestedActionSubscribeToAnnualPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionSubscribeToAnnualPremium");
    s.store_class_end();
  }
}

suggestedActionGiftPremiumForChristmas::suggestedActionGiftPremiumForChristmas() {
}

const std::int32_t suggestedActionGiftPremiumForChristmas::ID;

void suggestedActionGiftPremiumForChristmas::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionGiftPremiumForChristmas");
    s.store_class_end();
  }
}

suggestedActionSetBirthdate::suggestedActionSetBirthdate() {
}

const std::int32_t suggestedActionSetBirthdate::ID;

void suggestedActionSetBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionSetBirthdate");
    s.store_class_end();
  }
}

suggestedActionSetProfilePhoto::suggestedActionSetProfilePhoto() {
}

const std::int32_t suggestedActionSetProfilePhoto::ID;

void suggestedActionSetProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionSetProfilePhoto");
    s.store_class_end();
  }
}

suggestedActionExtendPremium::suggestedActionExtendPremium()
  : manage_premium_subscription_url_()
{}

suggestedActionExtendPremium::suggestedActionExtendPremium(string const &manage_premium_subscription_url_)
  : manage_premium_subscription_url_(manage_premium_subscription_url_)
{}

const std::int32_t suggestedActionExtendPremium::ID;

void suggestedActionExtendPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionExtendPremium");
    s.store_field("manage_premium_subscription_url", manage_premium_subscription_url_);
    s.store_class_end();
  }
}

suggestedActionExtendStarSubscriptions::suggestedActionExtendStarSubscriptions() {
}

const std::int32_t suggestedActionExtendStarSubscriptions::ID;

void suggestedActionExtendStarSubscriptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionExtendStarSubscriptions");
    s.store_class_end();
  }
}

suggestedActionCustom::suggestedActionCustom()
  : name_()
  , title_()
  , description_()
  , url_()
{}

suggestedActionCustom::suggestedActionCustom(string const &name_, object_ptr<formattedText> &&title_, object_ptr<formattedText> &&description_, string const &url_)
  : name_(name_)
  , title_(std::move(title_))
  , description_(std::move(description_))
  , url_(url_)
{}

const std::int32_t suggestedActionCustom::ID;

void suggestedActionCustom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionCustom");
    s.store_field("name", name_);
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_field("url", url_);
    s.store_class_end();
  }
}

suggestedActionSetLoginEmailAddress::suggestedActionSetLoginEmailAddress()
  : can_be_hidden_()
{}

suggestedActionSetLoginEmailAddress::suggestedActionSetLoginEmailAddress(bool can_be_hidden_)
  : can_be_hidden_(can_be_hidden_)
{}

const std::int32_t suggestedActionSetLoginEmailAddress::ID;

void suggestedActionSetLoginEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionSetLoginEmailAddress");
    s.store_field("can_be_hidden", can_be_hidden_);
    s.store_class_end();
  }
}

suggestedActionAddLoginPasskey::suggestedActionAddLoginPasskey() {
}

const std::int32_t suggestedActionAddLoginPasskey::ID;

void suggestedActionAddLoginPasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionAddLoginPasskey");
    s.store_class_end();
  }
}

textEntityTypeMention::textEntityTypeMention() {
}

const std::int32_t textEntityTypeMention::ID;

void textEntityTypeMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeMention");
    s.store_class_end();
  }
}

textEntityTypeHashtag::textEntityTypeHashtag() {
}

const std::int32_t textEntityTypeHashtag::ID;

void textEntityTypeHashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeHashtag");
    s.store_class_end();
  }
}

textEntityTypeCashtag::textEntityTypeCashtag() {
}

const std::int32_t textEntityTypeCashtag::ID;

void textEntityTypeCashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeCashtag");
    s.store_class_end();
  }
}

textEntityTypeBotCommand::textEntityTypeBotCommand() {
}

const std::int32_t textEntityTypeBotCommand::ID;

void textEntityTypeBotCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeBotCommand");
    s.store_class_end();
  }
}

textEntityTypeUrl::textEntityTypeUrl() {
}

const std::int32_t textEntityTypeUrl::ID;

void textEntityTypeUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeUrl");
    s.store_class_end();
  }
}

textEntityTypeEmailAddress::textEntityTypeEmailAddress() {
}

const std::int32_t textEntityTypeEmailAddress::ID;

void textEntityTypeEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeEmailAddress");
    s.store_class_end();
  }
}

textEntityTypePhoneNumber::textEntityTypePhoneNumber() {
}

const std::int32_t textEntityTypePhoneNumber::ID;

void textEntityTypePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypePhoneNumber");
    s.store_class_end();
  }
}

textEntityTypeBankCardNumber::textEntityTypeBankCardNumber() {
}

const std::int32_t textEntityTypeBankCardNumber::ID;

void textEntityTypeBankCardNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeBankCardNumber");
    s.store_class_end();
  }
}

textEntityTypeTonAddress::textEntityTypeTonAddress() {
}

const std::int32_t textEntityTypeTonAddress::ID;

void textEntityTypeTonAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeTonAddress");
    s.store_class_end();
  }
}

textEntityTypeBold::textEntityTypeBold() {
}

const std::int32_t textEntityTypeBold::ID;

void textEntityTypeBold::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeBold");
    s.store_class_end();
  }
}

textEntityTypeItalic::textEntityTypeItalic() {
}

const std::int32_t textEntityTypeItalic::ID;

void textEntityTypeItalic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeItalic");
    s.store_class_end();
  }
}

textEntityTypeUnderline::textEntityTypeUnderline() {
}

const std::int32_t textEntityTypeUnderline::ID;

void textEntityTypeUnderline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeUnderline");
    s.store_class_end();
  }
}

textEntityTypeStrikethrough::textEntityTypeStrikethrough() {
}

const std::int32_t textEntityTypeStrikethrough::ID;

void textEntityTypeStrikethrough::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeStrikethrough");
    s.store_class_end();
  }
}

textEntityTypeSpoiler::textEntityTypeSpoiler() {
}

const std::int32_t textEntityTypeSpoiler::ID;

void textEntityTypeSpoiler::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeSpoiler");
    s.store_class_end();
  }
}

textEntityTypeCode::textEntityTypeCode() {
}

const std::int32_t textEntityTypeCode::ID;

void textEntityTypeCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeCode");
    s.store_class_end();
  }
}

textEntityTypePre::textEntityTypePre() {
}

const std::int32_t textEntityTypePre::ID;

void textEntityTypePre::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypePre");
    s.store_class_end();
  }
}

textEntityTypePreCode::textEntityTypePreCode()
  : language_()
{}

textEntityTypePreCode::textEntityTypePreCode(string const &language_)
  : language_(language_)
{}

const std::int32_t textEntityTypePreCode::ID;

void textEntityTypePreCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypePreCode");
    s.store_field("language", language_);
    s.store_class_end();
  }
}

textEntityTypeBlockQuote::textEntityTypeBlockQuote() {
}

const std::int32_t textEntityTypeBlockQuote::ID;

void textEntityTypeBlockQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeBlockQuote");
    s.store_class_end();
  }
}

textEntityTypeExpandableBlockQuote::textEntityTypeExpandableBlockQuote() {
}

const std::int32_t textEntityTypeExpandableBlockQuote::ID;

void textEntityTypeExpandableBlockQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeExpandableBlockQuote");
    s.store_class_end();
  }
}

textEntityTypeTextUrl::textEntityTypeTextUrl()
  : url_()
{}

textEntityTypeTextUrl::textEntityTypeTextUrl(string const &url_)
  : url_(url_)
{}

const std::int32_t textEntityTypeTextUrl::ID;

void textEntityTypeTextUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeTextUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

textEntityTypeMentionName::textEntityTypeMentionName()
  : user_id_()
{}

textEntityTypeMentionName::textEntityTypeMentionName(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t textEntityTypeMentionName::ID;

void textEntityTypeMentionName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeMentionName");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

textEntityTypeCustomEmoji::textEntityTypeCustomEmoji()
  : custom_emoji_id_()
{}

textEntityTypeCustomEmoji::textEntityTypeCustomEmoji(int64 custom_emoji_id_)
  : custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t textEntityTypeCustomEmoji::ID;

void textEntityTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

textEntityTypeMediaTimestamp::textEntityTypeMediaTimestamp()
  : media_timestamp_()
{}

textEntityTypeMediaTimestamp::textEntityTypeMediaTimestamp(int32 media_timestamp_)
  : media_timestamp_(media_timestamp_)
{}

const std::int32_t textEntityTypeMediaTimestamp::ID;

void textEntityTypeMediaTimestamp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeMediaTimestamp");
    s.store_field("media_timestamp", media_timestamp_);
    s.store_class_end();
  }
}

textEntityTypeDateTime::textEntityTypeDateTime()
  : unix_time_()
  , formatting_type_()
{}

textEntityTypeDateTime::textEntityTypeDateTime(int32 unix_time_, object_ptr<DateTimeFormattingType> &&formatting_type_)
  : unix_time_(unix_time_)
  , formatting_type_(std::move(formatting_type_))
{}

const std::int32_t textEntityTypeDateTime::ID;

void textEntityTypeDateTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeDateTime");
    s.store_field("unix_time", unix_time_);
    s.store_object_field("formatting_type", static_cast<const BaseObject *>(formatting_type_.get()));
    s.store_class_end();
  }
}

timeZone::timeZone()
  : id_()
  , name_()
  , utc_time_offset_()
{}

timeZone::timeZone(string const &id_, string const &name_, int32 utc_time_offset_)
  : id_(id_)
  , name_(name_)
  , utc_time_offset_(utc_time_offset_)
{}

const std::int32_t timeZone::ID;

void timeZone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "timeZone");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_field("utc_time_offset", utc_time_offset_);
    s.store_class_end();
  }
}

tonConnectConnectItemAddress::tonConnectConnectItemAddress()
  : network_()
{}

tonConnectConnectItemAddress::tonConnectConnectItemAddress(string const &network_)
  : network_(network_)
{}

const std::int32_t tonConnectConnectItemAddress::ID;

void tonConnectConnectItemAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectConnectItemAddress");
    s.store_field("network", network_);
    s.store_class_end();
  }
}

tonConnectConnectItemProof::tonConnectConnectItemProof()
  : payload_()
{}

tonConnectConnectItemProof::tonConnectConnectItemProof(string const &payload_)
  : payload_(payload_)
{}

const std::int32_t tonConnectConnectItemProof::ID;

void tonConnectConnectItemProof::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectConnectItemProof");
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

tonWalletOwnershipProof::tonWalletOwnershipProof()
  : public_key_()
  , timestamp_()
  , signature_()
{}

tonWalletOwnershipProof::tonWalletOwnershipProof(bytes const &public_key_, int32 timestamp_, bytes const &signature_)
  : public_key_(std::move(public_key_))
  , timestamp_(timestamp_)
  , signature_(std::move(signature_))
{}

const std::int32_t tonWalletOwnershipProof::ID;

void tonWalletOwnershipProof::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletOwnershipProof");
    s.store_bytes_field("public_key", public_key_);
    s.store_field("timestamp", timestamp_);
    s.store_bytes_field("signature", signature_);
    s.store_class_end();
  }
}

topChatCategoryUsers::topChatCategoryUsers() {
}

const std::int32_t topChatCategoryUsers::ID;

void topChatCategoryUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryUsers");
    s.store_class_end();
  }
}

topChatCategoryBots::topChatCategoryBots() {
}

const std::int32_t topChatCategoryBots::ID;

void topChatCategoryBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryBots");
    s.store_class_end();
  }
}

topChatCategoryGroups::topChatCategoryGroups() {
}

const std::int32_t topChatCategoryGroups::ID;

void topChatCategoryGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryGroups");
    s.store_class_end();
  }
}

topChatCategoryChannels::topChatCategoryChannels() {
}

const std::int32_t topChatCategoryChannels::ID;

void topChatCategoryChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryChannels");
    s.store_class_end();
  }
}

topChatCategoryInlineBots::topChatCategoryInlineBots() {
}

const std::int32_t topChatCategoryInlineBots::ID;

void topChatCategoryInlineBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryInlineBots");
    s.store_class_end();
  }
}

topChatCategoryGuestBots::topChatCategoryGuestBots() {
}

const std::int32_t topChatCategoryGuestBots::ID;

void topChatCategoryGuestBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryGuestBots");
    s.store_class_end();
  }
}

topChatCategoryWebAppBots::topChatCategoryWebAppBots() {
}

const std::int32_t topChatCategoryWebAppBots::ID;

void topChatCategoryWebAppBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryWebAppBots");
    s.store_class_end();
  }
}

topChatCategoryCalls::topChatCategoryCalls() {
}

const std::int32_t topChatCategoryCalls::ID;

void topChatCategoryCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryCalls");
    s.store_class_end();
  }
}

topChatCategoryForwardChats::topChatCategoryForwardChats() {
}

const std::int32_t topChatCategoryForwardChats::ID;

void topChatCategoryForwardChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryForwardChats");
    s.store_class_end();
  }
}

transactionDirectionIncoming::transactionDirectionIncoming() {
}

const std::int32_t transactionDirectionIncoming::ID;

void transactionDirectionIncoming::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "transactionDirectionIncoming");
    s.store_class_end();
  }
}

transactionDirectionOutgoing::transactionDirectionOutgoing() {
}

const std::int32_t transactionDirectionOutgoing::ID;

void transactionDirectionOutgoing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "transactionDirectionOutgoing");
    s.store_class_end();
  }
}

upgradedGiftBackdropCount::upgradedGiftBackdropCount()
  : backdrop_()
  , total_count_()
{}

upgradedGiftBackdropCount::upgradedGiftBackdropCount(object_ptr<upgradedGiftBackdrop> &&backdrop_, int32 total_count_)
  : backdrop_(std::move(backdrop_))
  , total_count_(total_count_)
{}

const std::int32_t upgradedGiftBackdropCount::ID;

void upgradedGiftBackdropCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftBackdropCount");
    s.store_object_field("backdrop", static_cast<const BaseObject *>(backdrop_.get()));
    s.store_field("total_count", total_count_);
    s.store_class_end();
  }
}

verificationStatus::verificationStatus()
  : is_verified_()
  , is_scam_()
  , is_fake_()
  , bot_verification_icon_custom_emoji_id_()
{}

verificationStatus::verificationStatus(bool is_verified_, bool is_scam_, bool is_fake_, int64 bot_verification_icon_custom_emoji_id_)
  : is_verified_(is_verified_)
  , is_scam_(is_scam_)
  , is_fake_(is_fake_)
  , bot_verification_icon_custom_emoji_id_(bot_verification_icon_custom_emoji_id_)
{}

const std::int32_t verificationStatus::ID;

void verificationStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "verificationStatus");
    s.store_field("is_verified", is_verified_);
    s.store_field("is_scam", is_scam_);
    s.store_field("is_fake", is_fake_);
    s.store_field("bot_verification_icon_custom_emoji_id", bot_verification_icon_custom_emoji_id_);
    s.store_class_end();
  }
}

webAppUrl::webAppUrl()
  : url_()
  , require_same_origin_()
{}

webAppUrl::webAppUrl(string const &url_, bool require_same_origin_)
  : url_(url_)
  , require_same_origin_(require_same_origin_)
{}

const std::int32_t webAppUrl::ID;

void webAppUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppUrl");
    s.store_field("url", url_);
    s.store_field("require_same_origin", require_same_origin_);
    s.store_class_end();
  }
}

webProxyCarrierMessageText::webProxyCarrierMessageText()
  : text_()
{}

webProxyCarrierMessageText::webProxyCarrierMessageText(string const &text_)
  : text_(text_)
{}

const std::int32_t webProxyCarrierMessageText::ID;

void webProxyCarrierMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webProxyCarrierMessageText");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

webProxyCarrierMessageBinary::webProxyCarrierMessageBinary()
  : data_()
{}

webProxyCarrierMessageBinary::webProxyCarrierMessageBinary(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t webProxyCarrierMessageBinary::ID;

void webProxyCarrierMessageBinary::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webProxyCarrierMessageBinary");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

acceptGiftOnChainPurchaseOffer::acceptGiftOnChainPurchaseOffer()
  : message_id_()
{}

acceptGiftOnChainPurchaseOffer::acceptGiftOnChainPurchaseOffer(int53 message_id_)
  : message_id_(message_id_)
{}

const std::int32_t acceptGiftOnChainPurchaseOffer::ID;

void acceptGiftOnChainPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "acceptGiftOnChainPurchaseOffer");
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

addChatToList::addChatToList()
  : chat_id_()
  , chat_list_()
{}

addChatToList::addChatToList(int53 chat_id_, object_ptr<ChatList> &&chat_list_)
  : chat_id_(chat_id_)
  , chat_list_(std::move(chat_list_))
{}

const std::int32_t addChatToList::ID;

void addChatToList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatToList");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_class_end();
  }
}

addChecklistTasks::addChecklistTasks()
  : chat_id_()
  , message_id_()
  , tasks_()
{}

addChecklistTasks::addChecklistTasks(int53 chat_id_, int53 message_id_, array<object_ptr<inputChecklistTask>> &&tasks_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , tasks_(std::move(tasks_))
{}

const std::int32_t addChecklistTasks::ID;

void addChecklistTasks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChecklistTasks");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("tasks", tasks_.size()); for (const auto &_value : tasks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

addLocalMessage::addLocalMessage()
  : chat_id_()
  , sender_id_()
  , reply_to_()
  , disable_notification_()
  , input_message_content_()
{}

addLocalMessage::addLocalMessage(int53 chat_id_, object_ptr<MessageSender> &&sender_id_, object_ptr<InputMessageReplyTo> &&reply_to_, bool disable_notification_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , sender_id_(std::move(sender_id_))
  , reply_to_(std::move(reply_to_))
  , disable_notification_(disable_notification_)
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t addLocalMessage::ID;

void addLocalMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addLocalMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_field("disable_notification", disable_notification_);
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

addPendingPaidMessageReaction::addPendingPaidMessageReaction()
  : chat_id_()
  , message_id_()
  , star_count_()
  , type_()
{}

addPendingPaidMessageReaction::addPendingPaidMessageReaction(int53 chat_id_, int53 message_id_, int53 star_count_, object_ptr<PaidReactionType> &&type_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , star_count_(star_count_)
  , type_(std::move(type_))
{}

const std::int32_t addPendingPaidMessageReaction::ID;

void addPendingPaidMessageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addPendingPaidMessageReaction");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("star_count", star_count_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

addQuickReplyShortcutInlineQueryResultMessage::addQuickReplyShortcutInlineQueryResultMessage()
  : shortcut_name_()
  , reply_to_message_id_()
  , query_id_()
  , result_id_()
  , hide_via_bot_()
{}

addQuickReplyShortcutInlineQueryResultMessage::addQuickReplyShortcutInlineQueryResultMessage(string const &shortcut_name_, int53 reply_to_message_id_, int64 query_id_, string const &result_id_, bool hide_via_bot_)
  : shortcut_name_(shortcut_name_)
  , reply_to_message_id_(reply_to_message_id_)
  , query_id_(query_id_)
  , result_id_(result_id_)
  , hide_via_bot_(hide_via_bot_)
{}

const std::int32_t addQuickReplyShortcutInlineQueryResultMessage::ID;

void addQuickReplyShortcutInlineQueryResultMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addQuickReplyShortcutInlineQueryResultMessage");
    s.store_field("shortcut_name", shortcut_name_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_field("query_id", query_id_);
    s.store_field("result_id", result_id_);
    s.store_field("hide_via_bot", hide_via_bot_);
    s.store_class_end();
  }
}

addRecentlyFoundChat::addRecentlyFoundChat()
  : chat_id_()
{}

addRecentlyFoundChat::addRecentlyFoundChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t addRecentlyFoundChat::ID;

void addRecentlyFoundChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addRecentlyFoundChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

allowBotToSendMessages::allowBotToSendMessages()
  : bot_user_id_()
{}

allowBotToSendMessages::allowBotToSendMessages(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t allowBotToSendMessages::ID;

void allowBotToSendMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "allowBotToSendMessages");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

answerWidgetQuery::answerWidgetQuery()
  : widget_query_id_()
  , data_()
{}

answerWidgetQuery::answerWidgetQuery(int64 widget_query_id_, string const &data_)
  : widget_query_id_(widget_query_id_)
  , data_(data_)
{}

const std::int32_t answerWidgetQuery::ID;

void answerWidgetQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerWidgetQuery");
    s.store_field("widget_query_id", widget_query_id_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

blockMessageSenderFromReplies::blockMessageSenderFromReplies()
  : message_id_()
  , delete_message_()
  , delete_all_messages_()
  , report_spam_()
{}

blockMessageSenderFromReplies::blockMessageSenderFromReplies(int53 message_id_, bool delete_message_, bool delete_all_messages_, bool report_spam_)
  : message_id_(message_id_)
  , delete_message_(delete_message_)
  , delete_all_messages_(delete_all_messages_)
  , report_spam_(report_spam_)
{}

const std::int32_t blockMessageSenderFromReplies::ID;

void blockMessageSenderFromReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "blockMessageSenderFromReplies");
    s.store_field("message_id", message_id_);
    s.store_field("delete_message", delete_message_);
    s.store_field("delete_all_messages", delete_all_messages_);
    s.store_field("report_spam", report_spam_);
    s.store_class_end();
  }
}

buyGiftUpgrade::buyGiftUpgrade()
  : owner_id_()
  , prepaid_upgrade_hash_()
  , star_count_()
{}

buyGiftUpgrade::buyGiftUpgrade(object_ptr<MessageSender> &&owner_id_, string const &prepaid_upgrade_hash_, int53 star_count_)
  : owner_id_(std::move(owner_id_))
  , prepaid_upgrade_hash_(prepaid_upgrade_hash_)
  , star_count_(star_count_)
{}

const std::int32_t buyGiftUpgrade::ID;

void buyGiftUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buyGiftUpgrade");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("prepaid_upgrade_hash", prepaid_upgrade_hash_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

canBotSendMessages::canBotSendMessages()
  : bot_user_id_()
{}

canBotSendMessages::canBotSendMessages(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t canBotSendMessages::ID;

void canBotSendMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canBotSendMessages");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

changeStickerSet::changeStickerSet()
  : set_id_()
  , is_installed_()
  , is_archived_()
{}

changeStickerSet::changeStickerSet(int64 set_id_, bool is_installed_, bool is_archived_)
  : set_id_(set_id_)
  , is_installed_(is_installed_)
  , is_archived_(is_archived_)
{}

const std::int32_t changeStickerSet::ID;

void changeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "changeStickerSet");
    s.store_field("set_id", set_id_);
    s.store_field("is_installed", is_installed_);
    s.store_field("is_archived", is_archived_);
    s.store_class_end();
  }
}

checkChatInviteLink::checkChatInviteLink()
  : invite_link_()
{}

checkChatInviteLink::checkChatInviteLink(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t checkChatInviteLink::ID;

void checkChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

checkPhoneNumberCode::checkPhoneNumberCode()
  : code_()
{}

checkPhoneNumberCode::checkPhoneNumberCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkPhoneNumberCode::ID;

void checkPhoneNumberCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkPhoneNumberCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

clearRecentReactions::clearRecentReactions() {
}

const std::int32_t clearRecentReactions::ID;

void clearRecentReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearRecentReactions");
    s.store_class_end();
  }
}

closeWebApp::closeWebApp()
  : web_app_launch_id_()
{}

closeWebApp::closeWebApp(int64 web_app_launch_id_)
  : web_app_launch_id_(web_app_launch_id_)
{}

const std::int32_t closeWebApp::ID;

void closeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeWebApp");
    s.store_field("web_app_launch_id", web_app_launch_id_);
    s.store_class_end();
  }
}

commitPendingPaidMessageReactions::commitPendingPaidMessageReactions()
  : chat_id_()
  , message_id_()
{}

commitPendingPaidMessageReactions::commitPendingPaidMessageReactions(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t commitPendingPaidMessageReactions::ID;

void commitPendingPaidMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "commitPendingPaidMessageReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

connectAffiliateProgram::connectAffiliateProgram()
  : affiliate_()
  , bot_user_id_()
{}

connectAffiliateProgram::connectAffiliateProgram(object_ptr<AffiliateType> &&affiliate_, int53 bot_user_id_)
  : affiliate_(std::move(affiliate_))
  , bot_user_id_(bot_user_id_)
{}

const std::int32_t connectAffiliateProgram::ID;

void connectAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectAffiliateProgram");
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

createChatFolder::createChatFolder()
  : folder_()
{}

createChatFolder::createChatFolder(object_ptr<chatFolder> &&folder_)
  : folder_(std::move(folder_))
{}

const std::int32_t createChatFolder::ID;

void createChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createChatFolder");
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_class_end();
  }
}

createChatSubscriptionInviteLink::createChatSubscriptionInviteLink()
  : chat_id_()
  , name_()
  , subscription_pricing_()
{}

createChatSubscriptionInviteLink::createChatSubscriptionInviteLink(int53 chat_id_, string const &name_, object_ptr<starSubscriptionPricing> &&subscription_pricing_)
  : chat_id_(chat_id_)
  , name_(name_)
  , subscription_pricing_(std::move(subscription_pricing_))
{}

const std::int32_t createChatSubscriptionInviteLink::ID;

void createChatSubscriptionInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createChatSubscriptionInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("name", name_);
    s.store_object_field("subscription_pricing", static_cast<const BaseObject *>(subscription_pricing_.get()));
    s.store_class_end();
  }
}

createCommunity::createCommunity()
  : name_()
  , chat_id_()
  , is_chat_hidden_()
{}

createCommunity::createCommunity(string const &name_, int53 chat_id_, bool is_chat_hidden_)
  : name_(name_)
  , chat_id_(chat_id_)
  , is_chat_hidden_(is_chat_hidden_)
{}

const std::int32_t createCommunity::ID;

void createCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createCommunity");
    s.store_field("name", name_);
    s.store_field("chat_id", chat_id_);
    s.store_field("is_chat_hidden", is_chat_hidden_);
    s.store_class_end();
  }
}

createGiftCollection::createGiftCollection()
  : owner_id_()
  , name_()
  , received_gift_ids_()
{}

createGiftCollection::createGiftCollection(object_ptr<MessageSender> &&owner_id_, string const &name_, array<string> &&received_gift_ids_)
  : owner_id_(std::move(owner_id_))
  , name_(name_)
  , received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t createGiftCollection::ID;

void createGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createGiftCollection");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("name", name_);
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

createNewBasicGroupChat::createNewBasicGroupChat()
  : user_ids_()
  , title_()
  , message_auto_delete_time_()
{}

createNewBasicGroupChat::createNewBasicGroupChat(array<int53> &&user_ids_, string const &title_, int32 message_auto_delete_time_)
  : user_ids_(std::move(user_ids_))
  , title_(title_)
  , message_auto_delete_time_(message_auto_delete_time_)
{}

const std::int32_t createNewBasicGroupChat::ID;

void createNewBasicGroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewBasicGroupChat");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("title", title_);
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_class_end();
  }
}

createTemporaryPassword::createTemporaryPassword()
  : password_()
  , valid_for_()
{}

createTemporaryPassword::createTemporaryPassword(string const &password_, int32 valid_for_)
  : password_(password_)
  , valid_for_(valid_for_)
{}

const std::int32_t createTemporaryPassword::ID;

void createTemporaryPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createTemporaryPassword");
    s.store_field("password", "[REDACTED]");
    s.store_field("valid_for", valid_for_);
    s.store_class_end();
  }
}

createTonConnectSession::createTonConnectSession()
  : dapp_client_id_()
  , manifest_url_()
{}

createTonConnectSession::createTonConnectSession(string const &dapp_client_id_, string const &manifest_url_)
  : dapp_client_id_(dapp_client_id_)
  , manifest_url_(manifest_url_)
{}

const std::int32_t createTonConnectSession::ID;

void createTonConnectSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createTonConnectSession");
    s.store_field("dapp_client_id", dapp_client_id_);
    s.store_field("manifest_url", manifest_url_);
    s.store_class_end();
  }
}

declineSuggestedPost::declineSuggestedPost()
  : chat_id_()
  , message_id_()
  , comment_()
{}

declineSuggestedPost::declineSuggestedPost(int53 chat_id_, int53 message_id_, string const &comment_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , comment_(comment_)
{}

const std::int32_t declineSuggestedPost::ID;

void declineSuggestedPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "declineSuggestedPost");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("comment", comment_);
    s.store_class_end();
  }
}

deleteChatMessagesBySender::deleteChatMessagesBySender()
  : chat_id_()
  , sender_id_()
{}

deleteChatMessagesBySender::deleteChatMessagesBySender(int53 chat_id_, object_ptr<MessageSender> &&sender_id_)
  : chat_id_(chat_id_)
  , sender_id_(std::move(sender_id_))
{}

const std::int32_t deleteChatMessagesBySender::ID;

void deleteChatMessagesBySender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatMessagesBySender");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_class_end();
  }
}

deleteChatWelcomeMessage::deleteChatWelcomeMessage()
  : chat_id_()
  , welcome_message_id_()
{}

deleteChatWelcomeMessage::deleteChatWelcomeMessage(int53 chat_id_, int32 welcome_message_id_)
  : chat_id_(chat_id_)
  , welcome_message_id_(welcome_message_id_)
{}

const std::int32_t deleteChatWelcomeMessage::ID;

void deleteChatWelcomeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatWelcomeMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("welcome_message_id", welcome_message_id_);
    s.store_class_end();
  }
}

deleteGroupCallMessages::deleteGroupCallMessages()
  : group_call_id_()
  , message_ids_()
  , report_spam_()
{}

deleteGroupCallMessages::deleteGroupCallMessages(int32 group_call_id_, array<int32> &&message_ids_, bool report_spam_)
  : group_call_id_(group_call_id_)
  , message_ids_(std::move(message_ids_))
  , report_spam_(report_spam_)
{}

const std::int32_t deleteGroupCallMessages::ID;

void deleteGroupCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteGroupCallMessages");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("report_spam", report_spam_);
    s.store_class_end();
  }
}

deleteGroupCallMessagesBySender::deleteGroupCallMessagesBySender()
  : group_call_id_()
  , sender_id_()
  , report_spam_()
{}

deleteGroupCallMessagesBySender::deleteGroupCallMessagesBySender(int32 group_call_id_, object_ptr<MessageSender> &&sender_id_, bool report_spam_)
  : group_call_id_(group_call_id_)
  , sender_id_(std::move(sender_id_))
  , report_spam_(report_spam_)
{}

const std::int32_t deleteGroupCallMessagesBySender::ID;

void deleteGroupCallMessagesBySender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteGroupCallMessagesBySender");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("report_spam", report_spam_);
    s.store_class_end();
  }
}

deleteLanguagePack::deleteLanguagePack()
  : language_pack_id_()
{}

deleteLanguagePack::deleteLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t deleteLanguagePack::ID;

void deleteLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

deleteMessageEphemeralContent::deleteMessageEphemeralContent()
  : chat_id_()
  , message_id_()
{}

deleteMessageEphemeralContent::deleteMessageEphemeralContent(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t deleteMessageEphemeralContent::ID;

void deleteMessageEphemeralContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteMessageEphemeralContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

deleteTonWallet::deleteTonWallet()
  : password_()
{}

deleteTonWallet::deleteTonWallet(string const &password_)
  : password_(password_)
{}

const std::int32_t deleteTonWallet::ID;

void deleteTonWallet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteTonWallet");
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

disableTonWalletBackup::disableTonWalletBackup()
  : password_()
{}

disableTonWalletBackup::disableTonWalletBackup(string const &password_)
  : password_(password_)
{}

const std::int32_t disableTonWalletBackup::ID;

void disableTonWalletBackup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disableTonWalletBackup");
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

disconnectTonConnectSession::disconnectTonConnectSession()
  : session_id_()
  , body_()
{}

disconnectTonConnectSession::disconnectTonConnectSession(int64 session_id_, bytes const &body_)
  : session_id_(session_id_)
  , body_(std::move(body_))
{}

const std::int32_t disconnectTonConnectSession::ID;

void disconnectTonConnectSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disconnectTonConnectSession");
    s.store_field("session_id", session_id_);
    s.store_bytes_field("body", body_);
    s.store_class_end();
  }
}

downloadFile::downloadFile()
  : file_id_()
  , priority_()
  , offset_()
  , limit_()
  , synchronous_()
{}

downloadFile::downloadFile(int32 file_id_, int32 priority_, int53 offset_, int53 limit_, bool synchronous_)
  : file_id_(file_id_)
  , priority_(priority_)
  , offset_(offset_)
  , limit_(limit_)
  , synchronous_(synchronous_)
{}

const std::int32_t downloadFile::ID;

void downloadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "downloadFile");
    s.store_field("file_id", file_id_);
    s.store_field("priority", priority_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("synchronous", synchronous_);
    s.store_class_end();
  }
}

editBusinessMessageLiveLocation::editBusinessMessageLiveLocation()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
  , location_()
{}

editBusinessMessageLiveLocation::editBusinessMessageLiveLocation(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<liveLocation> &&location_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , location_(std::move(location_))
{}

const std::int32_t editBusinessMessageLiveLocation::ID;

void editBusinessMessageLiveLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageLiveLocation");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

fixRichMessageWithAi::fixRichMessageWithAi()
  : message_()
{}

fixRichMessageWithAi::fixRichMessageWithAi(object_ptr<inputRichMessage> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t fixRichMessageWithAi::ID;

void fixRichMessageWithAi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fixRichMessageWithAi");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

getAddressTonWallet::getAddressTonWallet()
  : address_()
{}

getAddressTonWallet::getAddressTonWallet(string const &address_)
  : address_(address_)
{}

const std::int32_t getAddressTonWallet::ID;

void getAddressTonWallet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAddressTonWallet");
    s.store_field("address", address_);
    s.store_class_end();
  }
}

getBotInfoShortDescription::getBotInfoShortDescription()
  : bot_user_id_()
  , language_code_()
{}

getBotInfoShortDescription::getBotInfoShortDescription(int53 bot_user_id_, string const &language_code_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
{}

const std::int32_t getBotInfoShortDescription::ID;

void getBotInfoShortDescription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotInfoShortDescription");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getChatBoostFeatures::getChatBoostFeatures()
  : is_channel_()
{}

getChatBoostFeatures::getChatBoostFeatures(bool is_channel_)
  : is_channel_(is_channel_)
{}

const std::int32_t getChatBoostFeatures::ID;

void getChatBoostFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoostFeatures");
    s.store_field("is_channel", is_channel_);
    s.store_class_end();
  }
}

getChatFolderChatCount::getChatFolderChatCount()
  : folder_()
{}

getChatFolderChatCount::getChatFolderChatCount(object_ptr<chatFolder> &&folder_)
  : folder_(std::move(folder_))
{}

const std::int32_t getChatFolderChatCount::ID;

void getChatFolderChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolderChatCount");
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_class_end();
  }
}

getChatHistory::getChatHistory()
  : chat_id_()
  , from_message_id_()
  , offset_()
  , limit_()
  , only_local_()
{}

getChatHistory::getChatHistory(int53 chat_id_, int53 from_message_id_, int32 offset_, int32 limit_, bool only_local_)
  : chat_id_(chat_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
  , only_local_(only_local_)
{}

const std::int32_t getChatHistory::ID;

void getChatHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

getChatMessageCount::getChatMessageCount()
  : chat_id_()
  , topic_id_()
  , filter_()
  , return_local_()
{}

getChatMessageCount::getChatMessageCount(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<SearchMessagesFilter> &&filter_, bool return_local_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , filter_(std::move(filter_))
  , return_local_(return_local_)
{}

const std::int32_t getChatMessageCount::ID;

void getChatMessageCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessageCount");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("return_local", return_local_);
    s.store_class_end();
  }
}

getChatRevenueTransactions::getChatRevenueTransactions()
  : chat_id_()
  , offset_()
  , limit_()
{}

getChatRevenueTransactions::getChatRevenueTransactions(int53 chat_id_, string const &offset_, int32 limit_)
  : chat_id_(chat_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getChatRevenueTransactions::ID;

void getChatRevenueTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatRevenueTransactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatRevenueWithdrawalUrl::getChatRevenueWithdrawalUrl()
  : chat_id_()
  , password_()
{}

getChatRevenueWithdrawalUrl::getChatRevenueWithdrawalUrl(int53 chat_id_, string const &password_)
  : chat_id_(chat_id_)
  , password_(password_)
{}

const std::int32_t getChatRevenueWithdrawalUrl::ID;

void getChatRevenueWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatRevenueWithdrawalUrl");
    s.store_field("chat_id", chat_id_);
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

getChatSparseMessagePositions::getChatSparseMessagePositions()
  : chat_id_()
  , filter_()
  , from_message_id_()
  , limit_()
  , saved_messages_topic_id_()
{}

getChatSparseMessagePositions::getChatSparseMessagePositions(int53 chat_id_, object_ptr<SearchMessagesFilter> &&filter_, int53 from_message_id_, int32 limit_, int53 saved_messages_topic_id_)
  : chat_id_(chat_id_)
  , filter_(std::move(filter_))
  , from_message_id_(from_message_id_)
  , limit_(limit_)
  , saved_messages_topic_id_(saved_messages_topic_id_)
{}

const std::int32_t getChatSparseMessagePositions::ID;

void getChatSparseMessagePositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatSparseMessagePositions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("from_message_id", from_message_id_);
    s.store_field("limit", limit_);
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_class_end();
  }
}

getCollectibleItemInfo::getCollectibleItemInfo()
  : type_()
{}

getCollectibleItemInfo::getCollectibleItemInfo(object_ptr<CollectibleItemType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t getCollectibleItemInfo::ID;

void getCollectibleItemInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCollectibleItemInfo");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

getCommands::getCommands()
  : scope_()
  , language_code_()
{}

getCommands::getCommands(object_ptr<BotCommandScope> &&scope_, string const &language_code_)
  : scope_(std::move(scope_))
  , language_code_(language_code_)
{}

const std::int32_t getCommands::ID;

void getCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getCommunityMemberChats::getCommunityMemberChats()
  : community_id_()
  , member_id_()
{}

getCommunityMemberChats::getCommunityMemberChats(int53 community_id_, object_ptr<MessageSender> &&member_id_)
  : community_id_(community_id_)
  , member_id_(std::move(member_id_))
{}

const std::int32_t getCommunityMemberChats::ID;

void getCommunityMemberChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCommunityMemberChats");
    s.store_field("community_id", community_id_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_class_end();
  }
}

getCreatedPublicChats::getCreatedPublicChats()
  : type_()
{}

getCreatedPublicChats::getCreatedPublicChats(object_ptr<PublicChatType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t getCreatedPublicChats::ID;

void getCreatedPublicChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCreatedPublicChats");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

getEmojiReaction::getEmojiReaction()
  : emoji_()
{}

getEmojiReaction::getEmojiReaction(string const &emoji_)
  : emoji_(emoji_)
{}

const std::int32_t getEmojiReaction::ID;

void getEmojiReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getEmojiReaction");
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

getFileMimeType::getFileMimeType()
  : file_name_()
{}

getFileMimeType::getFileMimeType(string const &file_name_)
  : file_name_(file_name_)
{}

const std::int32_t getFileMimeType::ID;

void getFileMimeType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFileMimeType");
    s.store_field("file_name", file_name_);
    s.store_class_end();
  }
}

getGreetingStickers::getGreetingStickers() {
}

const std::int32_t getGreetingStickers::ID;

void getGreetingStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGreetingStickers");
    s.store_class_end();
  }
}

getGroupCall::getGroupCall()
  : group_call_id_()
{}

getGroupCall::getGroupCall(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getGroupCall::ID;

void getGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCall");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getLogTags::getLogTags() {
}

const std::int32_t getLogTags::ID;

void getLogTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogTags");
    s.store_class_end();
  }
}

getMessageLinkInfo::getMessageLinkInfo()
  : url_()
{}

getMessageLinkInfo::getMessageLinkInfo(string const &url_)
  : url_(url_)
{}

const std::int32_t getMessageLinkInfo::ID;

void getMessageLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageLinkInfo");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

getMessagePublicForwards::getMessagePublicForwards()
  : chat_id_()
  , message_id_()
  , offset_()
  , limit_()
{}

getMessagePublicForwards::getMessagePublicForwards(int53 chat_id_, int53 message_id_, string const &offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getMessagePublicForwards::ID;

void getMessagePublicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessagePublicForwards");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getOption::getOption()
  : name_()
{}

getOption::getOption(string const &name_)
  : name_(name_)
{}

const std::int32_t getOption::ID;

void getOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOption");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

getPaymentForm::getPaymentForm()
  : input_invoice_()
  , theme_()
{}

getPaymentForm::getPaymentForm(object_ptr<InputInvoice> &&input_invoice_, object_ptr<themeParameters> &&theme_)
  : input_invoice_(std::move(input_invoice_))
  , theme_(std::move(theme_))
{}

const std::int32_t getPaymentForm::ID;

void getPaymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPaymentForm");
    s.store_object_field("input_invoice", static_cast<const BaseObject *>(input_invoice_.get()));
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

getPollOptionProperties::getPollOptionProperties()
  : chat_id_()
  , message_id_()
  , poll_option_id_()
{}

getPollOptionProperties::getPollOptionProperties(int53 chat_id_, int53 message_id_, string const &poll_option_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , poll_option_id_(poll_option_id_)
{}

const std::int32_t getPollOptionProperties::ID;

void getPollOptionProperties::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPollOptionProperties");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_class_end();
  }
}

getPreferredCountryLanguage::getPreferredCountryLanguage()
  : country_code_()
{}

getPreferredCountryLanguage::getPreferredCountryLanguage(string const &country_code_)
  : country_code_(country_code_)
{}

const std::int32_t getPreferredCountryLanguage::ID;

void getPreferredCountryLanguage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPreferredCountryLanguage");
    s.store_field("country_code", country_code_);
    s.store_class_end();
  }
}

getPreparedKeyboardButton::getPreparedKeyboardButton()
  : bot_user_id_()
  , prepared_button_id_()
{}

getPreparedKeyboardButton::getPreparedKeyboardButton(int53 bot_user_id_, string const &prepared_button_id_)
  : bot_user_id_(bot_user_id_)
  , prepared_button_id_(prepared_button_id_)
{}

const std::int32_t getPreparedKeyboardButton::ID;

void getPreparedKeyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPreparedKeyboardButton");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("prepared_button_id", prepared_button_id_);
    s.store_class_end();
  }
}

getProxies::getProxies() {
}

const std::int32_t getProxies::ID;

void getProxies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getProxies");
    s.store_class_end();
  }
}

getReceivedGifts::getReceivedGifts()
  : business_connection_id_()
  , owner_id_()
  , collection_id_()
  , exclude_unsaved_()
  , exclude_saved_()
  , exclude_unlimited_()
  , exclude_upgradable_()
  , exclude_non_upgradable_()
  , exclude_upgraded_()
  , exclude_without_colors_()
  , exclude_hosted_()
  , sort_by_price_()
  , offset_()
  , limit_()
{}

getReceivedGifts::getReceivedGifts(string const &business_connection_id_, object_ptr<MessageSender> &&owner_id_, int32 collection_id_, bool exclude_unsaved_, bool exclude_saved_, bool exclude_unlimited_, bool exclude_upgradable_, bool exclude_non_upgradable_, bool exclude_upgraded_, bool exclude_without_colors_, bool exclude_hosted_, bool sort_by_price_, string const &offset_, int32 limit_)
  : business_connection_id_(business_connection_id_)
  , owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
  , exclude_unsaved_(exclude_unsaved_)
  , exclude_saved_(exclude_saved_)
  , exclude_unlimited_(exclude_unlimited_)
  , exclude_upgradable_(exclude_upgradable_)
  , exclude_non_upgradable_(exclude_non_upgradable_)
  , exclude_upgraded_(exclude_upgraded_)
  , exclude_without_colors_(exclude_without_colors_)
  , exclude_hosted_(exclude_hosted_)
  , sort_by_price_(sort_by_price_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getReceivedGifts::ID;

void getReceivedGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getReceivedGifts");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    s.store_field("exclude_unsaved", exclude_unsaved_);
    s.store_field("exclude_saved", exclude_saved_);
    s.store_field("exclude_unlimited", exclude_unlimited_);
    s.store_field("exclude_upgradable", exclude_upgradable_);
    s.store_field("exclude_non_upgradable", exclude_non_upgradable_);
    s.store_field("exclude_upgraded", exclude_upgraded_);
    s.store_field("exclude_without_colors", exclude_without_colors_);
    s.store_field("exclude_hosted", exclude_hosted_);
    s.store_field("sort_by_price", sort_by_price_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getRecentInlineBots::getRecentInlineBots() {
}

const std::int32_t getRecentInlineBots::ID;

void getRecentInlineBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentInlineBots");
    s.store_class_end();
  }
}

getStarPaymentOptions::getStarPaymentOptions() {
}

const std::int32_t getStarPaymentOptions::ID;

void getStarPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarPaymentOptions");
    s.store_class_end();
  }
}

getStorageStatistics::getStorageStatistics()
  : chat_limit_()
{}

getStorageStatistics::getStorageStatistics(int32 chat_limit_)
  : chat_limit_(chat_limit_)
{}

const std::int32_t getStorageStatistics::ID;

void getStorageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStorageStatistics");
    s.store_field("chat_limit", chat_limit_);
    s.store_class_end();
  }
}

getSupergroupFullInfo::getSupergroupFullInfo()
  : supergroup_id_()
{}

getSupergroupFullInfo::getSupergroupFullInfo(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t getSupergroupFullInfo::ID;

void getSupergroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupergroupFullInfo");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

getTemporaryPasswordState::getTemporaryPasswordState() {
}

const std::int32_t getTemporaryPasswordState::ID;

void getTemporaryPasswordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTemporaryPasswordState");
    s.store_class_end();
  }
}

getTextEntities::getTextEntities()
  : text_()
{}

getTextEntities::getTextEntities(string const &text_)
  : text_(text_)
{}

const std::int32_t getTextEntities::ID;

void getTextEntities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTextEntities");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

getTonWalletTransactions::getTonWalletTransactions()
  : direction_()
  , offset_()
  , limit_()
{}

getTonWalletTransactions::getTonWalletTransactions(object_ptr<TransactionDirection> &&direction_, string const &offset_, int32 limit_)
  : direction_(std::move(direction_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getTonWalletTransactions::ID;

void getTonWalletTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonWalletTransactions");
    s.store_object_field("direction", static_cast<const BaseObject *>(direction_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getUpgradedGiftDepositInfo::getUpgradedGiftDepositInfo()
  : owner_id_()
  , name_()
  , hide_sender_()
{}

getUpgradedGiftDepositInfo::getUpgradedGiftDepositInfo(object_ptr<MessageSender> &&owner_id_, string const &name_, bool hide_sender_)
  : owner_id_(std::move(owner_id_))
  , name_(name_)
  , hide_sender_(hide_sender_)
{}

const std::int32_t getUpgradedGiftDepositInfo::ID;

void getUpgradedGiftDepositInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGiftDepositInfo");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("name", name_);
    s.store_field("hide_sender", hide_sender_);
    s.store_class_end();
  }
}

leaveChat::leaveChat()
  : chat_id_()
{}

leaveChat::leaveChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t leaveChat::ID;

void leaveChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "leaveChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

listenToAudio::listenToAudio()
  : audio_file_id_()
  , duration_()
{}

listenToAudio::listenToAudio(int32 audio_file_id_, int32 duration_)
  : audio_file_id_(audio_file_id_)
  , duration_(duration_)
{}

const std::int32_t listenToAudio::ID;

void listenToAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "listenToAudio");
    s.store_field("audio_file_id", audio_file_id_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

openMessageContent::openMessageContent()
  : chat_id_()
  , message_id_()
{}

openMessageContent::openMessageContent(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t openMessageContent::ID;

void openMessageContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openMessageContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

optimizeStorage::optimizeStorage()
  : size_()
  , ttl_()
  , count_()
  , immunity_delay_()
  , file_types_()
  , chat_ids_()
  , exclude_chat_ids_()
  , return_deleted_file_statistics_()
  , chat_limit_()
{}

optimizeStorage::optimizeStorage(int53 size_, int32 ttl_, int32 count_, int32 immunity_delay_, array<object_ptr<FileType>> &&file_types_, array<int53> &&chat_ids_, array<int53> &&exclude_chat_ids_, bool return_deleted_file_statistics_, int32 chat_limit_)
  : size_(size_)
  , ttl_(ttl_)
  , count_(count_)
  , immunity_delay_(immunity_delay_)
  , file_types_(std::move(file_types_))
  , chat_ids_(std::move(chat_ids_))
  , exclude_chat_ids_(std::move(exclude_chat_ids_))
  , return_deleted_file_statistics_(return_deleted_file_statistics_)
  , chat_limit_(chat_limit_)
{}

const std::int32_t optimizeStorage::ID;

void optimizeStorage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optimizeStorage");
    s.store_field("size", size_);
    s.store_field("ttl", ttl_);
    s.store_field("count", count_);
    s.store_field("immunity_delay", immunity_delay_);
    { s.store_vector_begin("file_types", file_types_.size()); for (const auto &_value : file_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("exclude_chat_ids", exclude_chat_ids_.size()); for (const auto &_value : exclude_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("return_deleted_file_statistics", return_deleted_file_statistics_);
    s.store_field("chat_limit", chat_limit_);
    s.store_class_end();
  }
}

postStory::postStory()
  : chat_id_()
  , content_()
  , areas_()
  , caption_()
  , music_()
  , privacy_settings_()
  , album_ids_()
  , active_period_()
  , from_story_full_id_()
  , is_posted_to_chat_page_()
  , protect_content_()
{}

postStory::postStory(int53 chat_id_, object_ptr<InputStoryContent> &&content_, object_ptr<inputStoryAreas> &&areas_, object_ptr<formattedText> &&caption_, object_ptr<inputAudio> &&music_, object_ptr<StoryPrivacySettings> &&privacy_settings_, array<int32> &&album_ids_, int32 active_period_, object_ptr<storyFullId> &&from_story_full_id_, bool is_posted_to_chat_page_, bool protect_content_)
  : chat_id_(chat_id_)
  , content_(std::move(content_))
  , areas_(std::move(areas_))
  , caption_(std::move(caption_))
  , music_(std::move(music_))
  , privacy_settings_(std::move(privacy_settings_))
  , album_ids_(std::move(album_ids_))
  , active_period_(active_period_)
  , from_story_full_id_(std::move(from_story_full_id_))
  , is_posted_to_chat_page_(is_posted_to_chat_page_)
  , protect_content_(protect_content_)
{}

const std::int32_t postStory::ID;

void postStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "postStory");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("areas", static_cast<const BaseObject *>(areas_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_object_field("music", static_cast<const BaseObject *>(music_.get()));
    s.store_object_field("privacy_settings", static_cast<const BaseObject *>(privacy_settings_.get()));
    { s.store_vector_begin("album_ids", album_ids_.size()); for (const auto &_value : album_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("active_period", active_period_);
    s.store_object_field("from_story_full_id", static_cast<const BaseObject *>(from_story_full_id_.get()));
    s.store_field("is_posted_to_chat_page", is_posted_to_chat_page_);
    s.store_field("protect_content", protect_content_);
    s.store_class_end();
  }
}

processChatFolderNewChats::processChatFolderNewChats()
  : chat_folder_id_()
  , added_chat_ids_()
{}

processChatFolderNewChats::processChatFolderNewChats(int32 chat_folder_id_, array<int53> &&added_chat_ids_)
  : chat_folder_id_(chat_folder_id_)
  , added_chat_ids_(std::move(added_chat_ids_))
{}

const std::int32_t processChatFolderNewChats::ID;

void processChatFolderNewChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processChatFolderNewChats");
    s.store_field("chat_folder_id", chat_folder_id_);
    { s.store_vector_begin("added_chat_ids", added_chat_ids_.size()); for (const auto &_value : added_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

removeContacts::removeContacts()
  : user_ids_()
{}

removeContacts::removeContacts(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t removeContacts::ID;

void removeContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeContacts");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

removeInstalledBackground::removeInstalledBackground()
  : background_id_()
{}

removeInstalledBackground::removeInstalledBackground(int64 background_id_)
  : background_id_(background_id_)
{}

const std::int32_t removeInstalledBackground::ID;

void removeInstalledBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeInstalledBackground");
    s.store_field("background_id", background_id_);
    s.store_class_end();
  }
}

removeTextCompositionStyle::removeTextCompositionStyle()
  : name_()
{}

removeTextCompositionStyle::removeTextCompositionStyle(string const &name_)
  : name_(name_)
{}

const std::int32_t removeTextCompositionStyle::ID;

void removeTextCompositionStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeTextCompositionStyle");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

reorderBotMediaPreviews::reorderBotMediaPreviews()
  : bot_user_id_()
  , language_code_()
  , file_ids_()
{}

reorderBotMediaPreviews::reorderBotMediaPreviews(int53 bot_user_id_, string const &language_code_, array<int32> &&file_ids_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , file_ids_(std::move(file_ids_))
{}

const std::int32_t reorderBotMediaPreviews::ID;

void reorderBotMediaPreviews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderBotMediaPreviews");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    { s.store_vector_begin("file_ids", file_ids_.size()); for (const auto &_value : file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reorderQuickReplyShortcuts::reorderQuickReplyShortcuts()
  : shortcut_ids_()
{}

reorderQuickReplyShortcuts::reorderQuickReplyShortcuts(array<int32> &&shortcut_ids_)
  : shortcut_ids_(std::move(shortcut_ids_))
{}

const std::int32_t reorderQuickReplyShortcuts::ID;

void reorderQuickReplyShortcuts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderQuickReplyShortcuts");
    { s.store_vector_begin("shortcut_ids", shortcut_ids_.size()); for (const auto &_value : shortcut_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportPhoneNumberCodeMissing::reportPhoneNumberCodeMissing()
  : mobile_network_code_()
{}

reportPhoneNumberCodeMissing::reportPhoneNumberCodeMissing(string const &mobile_network_code_)
  : mobile_network_code_(mobile_network_code_)
{}

const std::int32_t reportPhoneNumberCodeMissing::ID;

void reportPhoneNumberCodeMissing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportPhoneNumberCodeMissing");
    s.store_field("mobile_network_code", mobile_network_code_);
    s.store_class_end();
  }
}

reportWebProxyCarrierError::reportWebProxyCarrierError()
  : carrier_id_()
  , error_()
{}

reportWebProxyCarrierError::reportWebProxyCarrierError(int32 carrier_id_, object_ptr<WebProxyCarrierError> &&error_)
  : carrier_id_(carrier_id_)
  , error_(std::move(error_))
{}

const std::int32_t reportWebProxyCarrierError::ID;

void reportWebProxyCarrierError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportWebProxyCarrierError");
    s.store_field("carrier_id", carrier_id_);
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

searchPublicChats::searchPublicChats()
  : query_()
  , type_filter_()
{}

searchPublicChats::searchPublicChats(string const &query_, object_ptr<SearchChatTypeFilter> &&type_filter_)
  : query_(query_)
  , type_filter_(std::move(type_filter_))
{}

const std::int32_t searchPublicChats::ID;

void searchPublicChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicChats");
    s.store_field("query", query_);
    s.store_object_field("type_filter", static_cast<const BaseObject *>(type_filter_.get()));
    s.store_class_end();
  }
}

sendBusinessMessage::sendBusinessMessage()
  : business_connection_id_()
  , chat_id_()
  , reply_to_()
  , disable_notification_()
  , protect_content_()
  , effect_id_()
  , reply_markup_()
  , input_message_content_()
{}

sendBusinessMessage::sendBusinessMessage(string const &business_connection_id_, int53 chat_id_, object_ptr<InputMessageReplyTo> &&reply_to_, bool disable_notification_, bool protect_content_, int64 effect_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , reply_to_(std::move(reply_to_))
  , disable_notification_(disable_notification_)
  , protect_content_(protect_content_)
  , effect_id_(effect_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t sendBusinessMessage::ID;

void sendBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendBusinessMessage");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_field("disable_notification", disable_notification_);
    s.store_field("protect_content", protect_content_);
    s.store_field("effect_id", effect_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

sendCallRating::sendCallRating()
  : call_id_()
  , rating_()
  , comment_()
  , problems_()
{}

sendCallRating::sendCallRating(object_ptr<InputCall> &&call_id_, int32 rating_, string const &comment_, array<object_ptr<CallProblem>> &&problems_)
  : call_id_(std::move(call_id_))
  , rating_(rating_)
  , comment_(comment_)
  , problems_(std::move(problems_))
{}

const std::int32_t sendCallRating::ID;

void sendCallRating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallRating");
    s.store_object_field("call_id", static_cast<const BaseObject *>(call_id_.get()));
    s.store_field("rating", rating_);
    s.store_field("comment", comment_);
    { s.store_vector_begin("problems", problems_.size()); for (const auto &_value : problems_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

setBotInfoShortDescription::setBotInfoShortDescription()
  : bot_user_id_()
  , language_code_()
  , short_description_()
{}

setBotInfoShortDescription::setBotInfoShortDescription(int53 bot_user_id_, string const &language_code_, string const &short_description_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , short_description_(short_description_)
{}

const std::int32_t setBotInfoShortDescription::ID;

void setBotInfoShortDescription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotInfoShortDescription");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_field("short_description", short_description_);
    s.store_class_end();
  }
}

setGroupCallParticipantVolumeLevel::setGroupCallParticipantVolumeLevel()
  : group_call_id_()
  , participant_id_()
  , volume_level_()
{}

setGroupCallParticipantVolumeLevel::setGroupCallParticipantVolumeLevel(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, int32 volume_level_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , volume_level_(volume_level_)
{}

const std::int32_t setGroupCallParticipantVolumeLevel::ID;

void setGroupCallParticipantVolumeLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGroupCallParticipantVolumeLevel");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("volume_level", volume_level_);
    s.store_class_end();
  }
}

setMessageFactCheck::setMessageFactCheck()
  : chat_id_()
  , message_id_()
  , text_()
{}

setMessageFactCheck::setMessageFactCheck(int53 chat_id_, int53 message_id_, object_ptr<formattedText> &&text_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , text_(std::move(text_))
{}

const std::int32_t setMessageFactCheck::ID;

void setMessageFactCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMessageFactCheck");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

setOption::setOption()
  : name_()
  , value_()
{}

setOption::setOption(string const &name_, object_ptr<OptionValue> &&value_)
  : name_(name_)
  , value_(std::move(value_))
{}

const std::int32_t setOption::ID;

void setOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setOption");
    s.store_field("name", name_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

setPassportElement::setPassportElement()
  : element_()
  , password_()
{}

setPassportElement::setPassportElement(object_ptr<InputPassportElement> &&element_, string const &password_)
  : element_(std::move(element_))
  , password_(password_)
{}

const std::int32_t setPassportElement::ID;

void setPassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPassportElement");
    s.store_object_field("element", static_cast<const BaseObject *>(element_.get()));
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

setPinnedSavedMessagesTopics::setPinnedSavedMessagesTopics()
  : saved_messages_topic_ids_()
{}

setPinnedSavedMessagesTopics::setPinnedSavedMessagesTopics(array<int53> &&saved_messages_topic_ids_)
  : saved_messages_topic_ids_(std::move(saved_messages_topic_ids_))
{}

const std::int32_t setPinnedSavedMessagesTopics::ID;

void setPinnedSavedMessagesTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPinnedSavedMessagesTopics");
    { s.store_vector_begin("saved_messages_topic_ids", saved_messages_topic_ids_.size()); for (const auto &_value : saved_messages_topic_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stopPoll::stopPoll()
  : chat_id_()
  , message_id_()
  , reply_markup_()
{}

stopPoll::stopPoll(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t stopPoll::ID;

void stopPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stopPoll");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

testCallVectorInt::testCallVectorInt()
  : x_()
{}

testCallVectorInt::testCallVectorInt(array<int32> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorInt::ID;

void testCallVectorInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorInt");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

testReturnError::testReturnError()
  : error_()
{}

testReturnError::testReturnError(object_ptr<error> &&error_)
  : error_(std::move(error_))
{}

const std::int32_t testReturnError::ID;

void testReturnError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testReturnError");
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

testUseUpdate::testUseUpdate() {
}

const std::int32_t testUseUpdate::ID;

void testUseUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testUseUpdate");
    s.store_class_end();
  }
}

toggleChatDefaultDisableNotification::toggleChatDefaultDisableNotification()
  : chat_id_()
  , default_disable_notification_()
{}

toggleChatDefaultDisableNotification::toggleChatDefaultDisableNotification(int53 chat_id_, bool default_disable_notification_)
  : chat_id_(chat_id_)
  , default_disable_notification_(default_disable_notification_)
{}

const std::int32_t toggleChatDefaultDisableNotification::ID;

void toggleChatDefaultDisableNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatDefaultDisableNotification");
    s.store_field("chat_id", chat_id_);
    s.store_field("default_disable_notification", default_disable_notification_);
    s.store_class_end();
  }
}

toggleChatGiftNotifications::toggleChatGiftNotifications()
  : chat_id_()
  , are_enabled_()
{}

toggleChatGiftNotifications::toggleChatGiftNotifications(int53 chat_id_, bool are_enabled_)
  : chat_id_(chat_id_)
  , are_enabled_(are_enabled_)
{}

const std::int32_t toggleChatGiftNotifications::ID;

void toggleChatGiftNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatGiftNotifications");
    s.store_field("chat_id", chat_id_);
    s.store_field("are_enabled", are_enabled_);
    s.store_class_end();
  }
}

toggleChatIsMarkedAsUnread::toggleChatIsMarkedAsUnread()
  : chat_id_()
  , is_marked_as_unread_()
{}

toggleChatIsMarkedAsUnread::toggleChatIsMarkedAsUnread(int53 chat_id_, bool is_marked_as_unread_)
  : chat_id_(chat_id_)
  , is_marked_as_unread_(is_marked_as_unread_)
{}

const std::int32_t toggleChatIsMarkedAsUnread::ID;

void toggleChatIsMarkedAsUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatIsMarkedAsUnread");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_class_end();
  }
}

toggleChatIsTranslatable::toggleChatIsTranslatable()
  : chat_id_()
  , is_translatable_()
{}

toggleChatIsTranslatable::toggleChatIsTranslatable(int53 chat_id_, bool is_translatable_)
  : chat_id_(chat_id_)
  , is_translatable_(is_translatable_)
{}

const std::int32_t toggleChatIsTranslatable::ID;

void toggleChatIsTranslatable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatIsTranslatable");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_translatable", is_translatable_);
    s.store_class_end();
  }
}

toggleForumTopicIsClosed::toggleForumTopicIsClosed()
  : chat_id_()
  , forum_topic_id_()
  , is_closed_()
{}

toggleForumTopicIsClosed::toggleForumTopicIsClosed(int53 chat_id_, int32 forum_topic_id_, bool is_closed_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , is_closed_(is_closed_)
{}

const std::int32_t toggleForumTopicIsClosed::ID;

void toggleForumTopicIsClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleForumTopicIsClosed");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("is_closed", is_closed_);
    s.store_class_end();
  }
}

toggleSupergroupIsAllHistoryAvailable::toggleSupergroupIsAllHistoryAvailable()
  : supergroup_id_()
  , is_all_history_available_()
{}

toggleSupergroupIsAllHistoryAvailable::toggleSupergroupIsAllHistoryAvailable(int53 supergroup_id_, bool is_all_history_available_)
  : supergroup_id_(supergroup_id_)
  , is_all_history_available_(is_all_history_available_)
{}

const std::int32_t toggleSupergroupIsAllHistoryAvailable::ID;

void toggleSupergroupIsAllHistoryAvailable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupIsAllHistoryAvailable");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("is_all_history_available", is_all_history_available_);
    s.store_class_end();
  }
}

toggleVideoChatEnabledStartNotification::toggleVideoChatEnabledStartNotification()
  : group_call_id_()
  , enabled_start_notification_()
{}

toggleVideoChatEnabledStartNotification::toggleVideoChatEnabledStartNotification(int32 group_call_id_, bool enabled_start_notification_)
  : group_call_id_(group_call_id_)
  , enabled_start_notification_(enabled_start_notification_)
{}

const std::int32_t toggleVideoChatEnabledStartNotification::ID;

void toggleVideoChatEnabledStartNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleVideoChatEnabledStartNotification");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("enabled_start_notification", enabled_start_notification_);
    s.store_class_end();
  }
}

transferBusinessAccountStars::transferBusinessAccountStars()
  : business_connection_id_()
  , star_count_()
{}

transferBusinessAccountStars::transferBusinessAccountStars(string const &business_connection_id_, int53 star_count_)
  : business_connection_id_(business_connection_id_)
  , star_count_(star_count_)
{}

const std::int32_t transferBusinessAccountStars::ID;

void transferBusinessAccountStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "transferBusinessAccountStars");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

translateMessageRichMessage::translateMessageRichMessage()
  : chat_id_()
  , message_id_()
  , to_language_code_()
  , tone_()
{}

translateMessageRichMessage::translateMessageRichMessage(int53 chat_id_, int53 message_id_, string const &to_language_code_, string const &tone_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , to_language_code_(to_language_code_)
  , tone_(tone_)
{}

const std::int32_t translateMessageRichMessage::ID;

void translateMessageRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "translateMessageRichMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("to_language_code", to_language_code_);
    s.store_field("tone", tone_);
    s.store_class_end();
  }
}

unpinAllForumTopicMessages::unpinAllForumTopicMessages()
  : chat_id_()
  , forum_topic_id_()
{}

unpinAllForumTopicMessages::unpinAllForumTopicMessages(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t unpinAllForumTopicMessages::ID;

void unpinAllForumTopicMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unpinAllForumTopicMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

viewVideoMessageAdvertisement::viewVideoMessageAdvertisement()
  : advertisement_unique_id_()
{}

viewVideoMessageAdvertisement::viewVideoMessageAdvertisement(int53 advertisement_unique_id_)
  : advertisement_unique_id_(advertisement_unique_id_)
{}

const std::int32_t viewVideoMessageAdvertisement::ID;

void viewVideoMessageAdvertisement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewVideoMessageAdvertisement");
    s.store_field("advertisement_unique_id", advertisement_unique_id_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
