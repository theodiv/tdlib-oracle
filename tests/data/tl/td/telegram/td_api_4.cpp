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


accountTtl::accountTtl()
  : days_()
{}

accountTtl::accountTtl(int32 days_)
  : days_(days_)
{}

const std::int32_t accountTtl::ID;

void accountTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accountTtl");
    s.store_field("days", days_);
    s.store_class_end();
  }
}

availableReactions::availableReactions()
  : top_reactions_()
  , recent_reactions_()
  , popular_reactions_()
  , allow_custom_emoji_()
  , are_tags_()
  , unavailability_reason_()
{}

availableReactions::availableReactions(array<object_ptr<availableReaction>> &&top_reactions_, array<object_ptr<availableReaction>> &&recent_reactions_, array<object_ptr<availableReaction>> &&popular_reactions_, bool allow_custom_emoji_, bool are_tags_, object_ptr<ReactionUnavailabilityReason> &&unavailability_reason_)
  : top_reactions_(std::move(top_reactions_))
  , recent_reactions_(std::move(recent_reactions_))
  , popular_reactions_(std::move(popular_reactions_))
  , allow_custom_emoji_(allow_custom_emoji_)
  , are_tags_(are_tags_)
  , unavailability_reason_(std::move(unavailability_reason_))
{}

const std::int32_t availableReactions::ID;

void availableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableReactions");
    { s.store_vector_begin("top_reactions", top_reactions_.size()); for (const auto &_value : top_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("recent_reactions", recent_reactions_.size()); for (const auto &_value : recent_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("popular_reactions", popular_reactions_.size()); for (const auto &_value : popular_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("allow_custom_emoji", allow_custom_emoji_);
    s.store_field("are_tags", are_tags_);
    s.store_object_field("unavailability_reason", static_cast<const BaseObject *>(unavailability_reason_.get()));
    s.store_class_end();
  }
}

backgroundFillSolid::backgroundFillSolid()
  : color_()
{}

backgroundFillSolid::backgroundFillSolid(int32 color_)
  : color_(color_)
{}

const std::int32_t backgroundFillSolid::ID;

void backgroundFillSolid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundFillSolid");
    s.store_field("color", color_);
    s.store_class_end();
  }
}

backgroundFillGradient::backgroundFillGradient()
  : top_color_()
  , bottom_color_()
  , rotation_angle_()
{}

backgroundFillGradient::backgroundFillGradient(int32 top_color_, int32 bottom_color_, int32 rotation_angle_)
  : top_color_(top_color_)
  , bottom_color_(bottom_color_)
  , rotation_angle_(rotation_angle_)
{}

const std::int32_t backgroundFillGradient::ID;

void backgroundFillGradient::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundFillGradient");
    s.store_field("top_color", top_color_);
    s.store_field("bottom_color", bottom_color_);
    s.store_field("rotation_angle", rotation_angle_);
    s.store_class_end();
  }
}

backgroundFillFreeformGradient::backgroundFillFreeformGradient()
  : colors_()
{}

backgroundFillFreeformGradient::backgroundFillFreeformGradient(array<int32> &&colors_)
  : colors_(std::move(colors_))
{}

const std::int32_t backgroundFillFreeformGradient::ID;

void backgroundFillFreeformGradient::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundFillFreeformGradient");
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

bankCardInfo::bankCardInfo()
  : title_()
  , actions_()
{}

bankCardInfo::bankCardInfo(string const &title_, array<object_ptr<bankCardActionOpenUrl>> &&actions_)
  : title_(title_)
  , actions_(std::move(actions_))
{}

const std::int32_t bankCardInfo::ID;

void bankCardInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bankCardInfo");
    s.store_field("title", title_);
    { s.store_vector_begin("actions", actions_.size()); for (const auto &_value : actions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

botMediaPreview::botMediaPreview()
  : date_()
  , content_()
{}

botMediaPreview::botMediaPreview(int32 date_, object_ptr<StoryContent> &&content_)
  : date_(date_)
  , content_(std::move(content_))
{}

const std::int32_t botMediaPreview::ID;

void botMediaPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMediaPreview");
    s.store_field("date", date_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

botMediaPreviews::botMediaPreviews()
  : previews_()
{}

botMediaPreviews::botMediaPreviews(array<object_ptr<botMediaPreview>> &&previews_)
  : previews_(std::move(previews_))
{}

const std::int32_t botMediaPreviews::ID;

void botMediaPreviews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMediaPreviews");
    { s.store_vector_begin("previews", previews_.size()); for (const auto &_value : previews_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessChatLink::businessChatLink()
  : link_()
  , text_()
  , title_()
  , view_count_()
{}

businessChatLink::businessChatLink(string const &link_, object_ptr<formattedText> &&text_, string const &title_, int32 view_count_)
  : link_(link_)
  , text_(std::move(text_))
  , title_(title_)
  , view_count_(view_count_)
{}

const std::int32_t businessChatLink::ID;

void businessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessChatLink");
    s.store_field("link", link_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("title", title_);
    s.store_field("view_count", view_count_);
    s.store_class_end();
  }
}

businessLocation::businessLocation()
  : location_()
  , address_()
{}

businessLocation::businessLocation(object_ptr<location> &&location_, string const &address_)
  : location_(std::move(location_))
  , address_(address_)
{}

const std::int32_t businessLocation::ID;

void businessLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("address", address_);
    s.store_class_end();
  }
}

buttonStyleDefault::buttonStyleDefault() {
}

const std::int32_t buttonStyleDefault::ID;

void buttonStyleDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonStyleDefault");
    s.store_class_end();
  }
}

buttonStylePrimary::buttonStylePrimary() {
}

const std::int32_t buttonStylePrimary::ID;

void buttonStylePrimary::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonStylePrimary");
    s.store_class_end();
  }
}

buttonStyleDanger::buttonStyleDanger() {
}

const std::int32_t buttonStyleDanger::ID;

void buttonStyleDanger::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonStyleDanger");
    s.store_class_end();
  }
}

buttonStyleSuccess::buttonStyleSuccess() {
}

const std::int32_t buttonStyleSuccess::ID;

void buttonStyleSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonStyleSuccess");
    s.store_class_end();
  }
}

buttonStyleLink::buttonStyleLink() {
}

const std::int32_t buttonStyleLink::ID;

void buttonStyleLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonStyleLink");
    s.store_class_end();
  }
}

canSendGiftResultOk::canSendGiftResultOk() {
}

const std::int32_t canSendGiftResultOk::ID;

void canSendGiftResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendGiftResultOk");
    s.store_class_end();
  }
}

canSendGiftResultFail::canSendGiftResultFail()
  : reason_()
{}

canSendGiftResultFail::canSendGiftResultFail(object_ptr<formattedText> &&reason_)
  : reason_(std::move(reason_))
{}

const std::int32_t canSendGiftResultFail::ID;

void canSendGiftResultFail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendGiftResultFail");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

chatBoostSlots::chatBoostSlots()
  : slots_()
{}

chatBoostSlots::chatBoostSlots(array<object_ptr<chatBoostSlot>> &&slots_)
  : slots_(std::move(slots_))
{}

const std::int32_t chatBoostSlots::ID;

void chatBoostSlots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostSlots");
    { s.store_vector_begin("slots", slots_.size()); for (const auto &_value : slots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatInviteLinkMember::chatInviteLinkMember()
  : user_id_()
  , joined_chat_date_()
  , via_chat_folder_invite_link_()
  , approver_user_id_()
{}

chatInviteLinkMember::chatInviteLinkMember(int53 user_id_, int32 joined_chat_date_, bool via_chat_folder_invite_link_, int53 approver_user_id_)
  : user_id_(user_id_)
  , joined_chat_date_(joined_chat_date_)
  , via_chat_folder_invite_link_(via_chat_folder_invite_link_)
  , approver_user_id_(approver_user_id_)
{}

const std::int32_t chatInviteLinkMember::ID;

void chatInviteLinkMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkMember");
    s.store_field("user_id", user_id_);
    s.store_field("joined_chat_date", joined_chat_date_);
    s.store_field("via_chat_folder_invite_link", via_chat_folder_invite_link_);
    s.store_field("approver_user_id", approver_user_id_);
    s.store_class_end();
  }
}

chatPermissions::chatPermissions()
  : can_send_basic_messages_()
  , can_send_audios_()
  , can_send_documents_()
  , can_send_photos_()
  , can_send_videos_()
  , can_send_video_notes_()
  , can_send_voice_notes_()
  , can_send_polls_()
  , can_send_other_messages_()
  , can_add_link_previews_()
  , can_react_to_messages_()
  , can_edit_tag_()
  , can_change_info_()
  , can_invite_users_()
  , can_pin_messages_()
  , can_create_topics_()
{}

chatPermissions::chatPermissions(bool can_send_basic_messages_, bool can_send_audios_, bool can_send_documents_, bool can_send_photos_, bool can_send_videos_, bool can_send_video_notes_, bool can_send_voice_notes_, bool can_send_polls_, bool can_send_other_messages_, bool can_add_link_previews_, bool can_react_to_messages_, bool can_edit_tag_, bool can_change_info_, bool can_invite_users_, bool can_pin_messages_, bool can_create_topics_)
  : can_send_basic_messages_(can_send_basic_messages_)
  , can_send_audios_(can_send_audios_)
  , can_send_documents_(can_send_documents_)
  , can_send_photos_(can_send_photos_)
  , can_send_videos_(can_send_videos_)
  , can_send_video_notes_(can_send_video_notes_)
  , can_send_voice_notes_(can_send_voice_notes_)
  , can_send_polls_(can_send_polls_)
  , can_send_other_messages_(can_send_other_messages_)
  , can_add_link_previews_(can_add_link_previews_)
  , can_react_to_messages_(can_react_to_messages_)
  , can_edit_tag_(can_edit_tag_)
  , can_change_info_(can_change_info_)
  , can_invite_users_(can_invite_users_)
  , can_pin_messages_(can_pin_messages_)
  , can_create_topics_(can_create_topics_)
{}

const std::int32_t chatPermissions::ID;

void chatPermissions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPermissions");
    s.store_field("can_send_basic_messages", can_send_basic_messages_);
    s.store_field("can_send_audios", can_send_audios_);
    s.store_field("can_send_documents", can_send_documents_);
    s.store_field("can_send_photos", can_send_photos_);
    s.store_field("can_send_videos", can_send_videos_);
    s.store_field("can_send_video_notes", can_send_video_notes_);
    s.store_field("can_send_voice_notes", can_send_voice_notes_);
    s.store_field("can_send_polls", can_send_polls_);
    s.store_field("can_send_other_messages", can_send_other_messages_);
    s.store_field("can_add_link_previews", can_add_link_previews_);
    s.store_field("can_react_to_messages", can_react_to_messages_);
    s.store_field("can_edit_tag", can_edit_tag_);
    s.store_field("can_change_info", can_change_info_);
    s.store_field("can_invite_users", can_invite_users_);
    s.store_field("can_pin_messages", can_pin_messages_);
    s.store_field("can_create_topics", can_create_topics_);
    s.store_class_end();
  }
}

chatPhoto::chatPhoto()
  : id_()
  , added_date_()
  , minithumbnail_()
  , sizes_()
  , animation_()
  , small_animation_()
  , sticker_()
{}

chatPhoto::chatPhoto(int64 id_, int32 added_date_, object_ptr<minithumbnail> &&minithumbnail_, array<object_ptr<photoSize>> &&sizes_, object_ptr<animatedChatPhoto> &&animation_, object_ptr<animatedChatPhoto> &&small_animation_, object_ptr<chatPhotoSticker> &&sticker_)
  : id_(id_)
  , added_date_(added_date_)
  , minithumbnail_(std::move(minithumbnail_))
  , sizes_(std::move(sizes_))
  , animation_(std::move(animation_))
  , small_animation_(std::move(small_animation_))
  , sticker_(std::move(sticker_))
{}

const std::int32_t chatPhoto::ID;

void chatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhoto");
    s.store_field("id", id_);
    s.store_field("added_date", added_date_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    { s.store_vector_begin("sizes", sizes_.size()); for (const auto &_value : sizes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("small_animation", static_cast<const BaseObject *>(small_animation_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

chatPhotoSticker::chatPhotoSticker()
  : type_()
  , background_fill_()
{}

chatPhotoSticker::chatPhotoSticker(object_ptr<ChatPhotoStickerType> &&type_, object_ptr<BackgroundFill> &&background_fill_)
  : type_(std::move(type_))
  , background_fill_(std::move(background_fill_))
{}

const std::int32_t chatPhotoSticker::ID;

void chatPhotoSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotoSticker");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("background_fill", static_cast<const BaseObject *>(background_fill_.get()));
    s.store_class_end();
  }
}

chats::chats()
  : total_count_()
  , chat_ids_()
{}

chats::chats(int32 total_count_, array<int53> &&chat_ids_)
  : total_count_(total_count_)
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t chats::ID;

void chats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chats");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

communityPermissions::communityPermissions()
  : can_edit_chat_list_()
{}

communityPermissions::communityPermissions(bool can_edit_chat_list_)
  : can_edit_chat_list_(can_edit_chat_list_)
{}

const std::int32_t communityPermissions::ID;

void communityPermissions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityPermissions");
    s.store_field("can_edit_chat_list", can_edit_chat_list_);
    s.store_class_end();
  }
}

connectedAffiliatePrograms::connectedAffiliatePrograms()
  : total_count_()
  , programs_()
  , next_offset_()
{}

connectedAffiliatePrograms::connectedAffiliatePrograms(int32 total_count_, array<object_ptr<connectedAffiliateProgram>> &&programs_, string const &next_offset_)
  : total_count_(total_count_)
  , programs_(std::move(programs_))
  , next_offset_(next_offset_)
{}

const std::int32_t connectedAffiliatePrograms::ID;

void connectedAffiliatePrograms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedAffiliatePrograms");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("programs", programs_.size()); for (const auto &_value : programs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

contact::contact()
  : phone_number_()
  , first_name_()
  , last_name_()
  , vcard_()
  , user_id_()
{}

contact::contact(string const &phone_number_, string const &first_name_, string const &last_name_, string const &vcard_, int53 user_id_)
  : phone_number_(phone_number_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , vcard_(vcard_)
  , user_id_(user_id_)
{}

const std::int32_t contact::ID;

void contact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contact");
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("vcard", vcard_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

createdBasicGroupChat::createdBasicGroupChat()
  : chat_id_()
  , failed_to_add_members_()
{}

createdBasicGroupChat::createdBasicGroupChat(int53 chat_id_, object_ptr<failedToAddMembers> &&failed_to_add_members_)
  : chat_id_(chat_id_)
  , failed_to_add_members_(std::move(failed_to_add_members_))
{}

const std::int32_t createdBasicGroupChat::ID;

void createdBasicGroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createdBasicGroupChat");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("failed_to_add_members", static_cast<const BaseObject *>(failed_to_add_members_.get()));
    s.store_class_end();
  }
}

diceStickersRegular::diceStickersRegular()
  : sticker_()
{}

diceStickersRegular::diceStickersRegular(object_ptr<sticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t diceStickersRegular::ID;

void diceStickersRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diceStickersRegular");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

diceStickersSlotMachine::diceStickersSlotMachine()
  : background_()
  , lever_()
  , left_reel_()
  , center_reel_()
  , right_reel_()
{}

diceStickersSlotMachine::diceStickersSlotMachine(object_ptr<sticker> &&background_, object_ptr<sticker> &&lever_, object_ptr<sticker> &&left_reel_, object_ptr<sticker> &&center_reel_, object_ptr<sticker> &&right_reel_)
  : background_(std::move(background_))
  , lever_(std::move(lever_))
  , left_reel_(std::move(left_reel_))
  , center_reel_(std::move(center_reel_))
  , right_reel_(std::move(right_reel_))
{}

const std::int32_t diceStickersSlotMachine::ID;

void diceStickersSlotMachine::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diceStickersSlotMachine");
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("lever", static_cast<const BaseObject *>(lever_.get()));
    s.store_object_field("left_reel", static_cast<const BaseObject *>(left_reel_.get()));
    s.store_object_field("center_reel", static_cast<const BaseObject *>(center_reel_.get()));
    s.store_object_field("right_reel", static_cast<const BaseObject *>(right_reel_.get()));
    s.store_class_end();
  }
}

draftMessageContentText::draftMessageContentText()
  : text_()
  , link_preview_options_()
{}

draftMessageContentText::draftMessageContentText(object_ptr<formattedText> &&text_, object_ptr<linkPreviewOptions> &&link_preview_options_)
  : text_(std::move(text_))
  , link_preview_options_(std::move(link_preview_options_))
{}

const std::int32_t draftMessageContentText::ID;

void draftMessageContentText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessageContentText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("link_preview_options", static_cast<const BaseObject *>(link_preview_options_.get()));
    s.store_class_end();
  }
}

draftMessageContentRichMessage::draftMessageContentRichMessage()
  : message_()
{}

draftMessageContentRichMessage::draftMessageContentRichMessage(object_ptr<richMessage> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t draftMessageContentRichMessage::ID;

void draftMessageContentRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessageContentRichMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

draftMessageContentInputRichMessage::draftMessageContentInputRichMessage()
  : message_()
{}

draftMessageContentInputRichMessage::draftMessageContentInputRichMessage(object_ptr<inputRichMessage> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t draftMessageContentInputRichMessage::ID;

void draftMessageContentInputRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessageContentInputRichMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

draftMessageContentVideoNote::draftMessageContentVideoNote()
  : file_path_()
  , duration_()
  , length_()
  , self_destruct_type_()
{}

draftMessageContentVideoNote::draftMessageContentVideoNote(string const &file_path_, int32 duration_, int32 length_, object_ptr<MessageSelfDestructType> &&self_destruct_type_)
  : file_path_(file_path_)
  , duration_(duration_)
  , length_(length_)
  , self_destruct_type_(std::move(self_destruct_type_))
{}

const std::int32_t draftMessageContentVideoNote::ID;

void draftMessageContentVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessageContentVideoNote");
    s.store_field("file_path", file_path_);
    s.store_field("duration", duration_);
    s.store_field("length", length_);
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_class_end();
  }
}

draftMessageContentVoiceNote::draftMessageContentVoiceNote()
  : file_path_()
  , duration_()
  , waveform_()
  , self_destruct_type_()
{}

draftMessageContentVoiceNote::draftMessageContentVoiceNote(string const &file_path_, int32 duration_, bytes const &waveform_, object_ptr<MessageSelfDestructType> &&self_destruct_type_)
  : file_path_(file_path_)
  , duration_(duration_)
  , waveform_(std::move(waveform_))
  , self_destruct_type_(std::move(self_destruct_type_))
{}

const std::int32_t draftMessageContentVoiceNote::ID;

void draftMessageContentVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessageContentVoiceNote");
    s.store_field("file_path", file_path_);
    s.store_field("duration", duration_);
    s.store_bytes_field("waveform", waveform_);
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_class_end();
  }
}

emojiStatusCustomEmojis::emojiStatusCustomEmojis()
  : custom_emoji_ids_()
{}

emojiStatusCustomEmojis::emojiStatusCustomEmojis(array<int64> &&custom_emoji_ids_)
  : custom_emoji_ids_(std::move(custom_emoji_ids_))
{}

const std::int32_t emojiStatusCustomEmojis::ID;

void emojiStatusCustomEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatusCustomEmojis");
    { s.store_vector_begin("custom_emoji_ids", custom_emoji_ids_.size()); for (const auto &_value : custom_emoji_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

fileTypeNone::fileTypeNone() {
}

const std::int32_t fileTypeNone::ID;

void fileTypeNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeNone");
    s.store_class_end();
  }
}

fileTypeAnimation::fileTypeAnimation() {
}

const std::int32_t fileTypeAnimation::ID;

void fileTypeAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeAnimation");
    s.store_class_end();
  }
}

fileTypeAudio::fileTypeAudio() {
}

const std::int32_t fileTypeAudio::ID;

void fileTypeAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeAudio");
    s.store_class_end();
  }
}

fileTypeDocument::fileTypeDocument() {
}

const std::int32_t fileTypeDocument::ID;

void fileTypeDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeDocument");
    s.store_class_end();
  }
}

fileTypeLivePhotoVideo::fileTypeLivePhotoVideo() {
}

const std::int32_t fileTypeLivePhotoVideo::ID;

void fileTypeLivePhotoVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeLivePhotoVideo");
    s.store_class_end();
  }
}

fileTypeNotificationSound::fileTypeNotificationSound() {
}

const std::int32_t fileTypeNotificationSound::ID;

void fileTypeNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeNotificationSound");
    s.store_class_end();
  }
}

fileTypePhoto::fileTypePhoto() {
}

const std::int32_t fileTypePhoto::ID;

void fileTypePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypePhoto");
    s.store_class_end();
  }
}

fileTypePhotoStory::fileTypePhotoStory() {
}

const std::int32_t fileTypePhotoStory::ID;

void fileTypePhotoStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypePhotoStory");
    s.store_class_end();
  }
}

fileTypeProfilePhoto::fileTypeProfilePhoto() {
}

const std::int32_t fileTypeProfilePhoto::ID;

void fileTypeProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeProfilePhoto");
    s.store_class_end();
  }
}

fileTypeSecret::fileTypeSecret() {
}

const std::int32_t fileTypeSecret::ID;

void fileTypeSecret::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSecret");
    s.store_class_end();
  }
}

fileTypeSecretThumbnail::fileTypeSecretThumbnail() {
}

const std::int32_t fileTypeSecretThumbnail::ID;

void fileTypeSecretThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSecretThumbnail");
    s.store_class_end();
  }
}

fileTypeSecure::fileTypeSecure() {
}

const std::int32_t fileTypeSecure::ID;

void fileTypeSecure::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSecure");
    s.store_class_end();
  }
}

fileTypeSelfDestructingLivePhotoVideo::fileTypeSelfDestructingLivePhotoVideo() {
}

const std::int32_t fileTypeSelfDestructingLivePhotoVideo::ID;

void fileTypeSelfDestructingLivePhotoVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSelfDestructingLivePhotoVideo");
    s.store_class_end();
  }
}

fileTypeSelfDestructingPhoto::fileTypeSelfDestructingPhoto() {
}

const std::int32_t fileTypeSelfDestructingPhoto::ID;

void fileTypeSelfDestructingPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSelfDestructingPhoto");
    s.store_class_end();
  }
}

fileTypeSelfDestructingVideo::fileTypeSelfDestructingVideo() {
}

const std::int32_t fileTypeSelfDestructingVideo::ID;

void fileTypeSelfDestructingVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSelfDestructingVideo");
    s.store_class_end();
  }
}

fileTypeSelfDestructingVideoNote::fileTypeSelfDestructingVideoNote() {
}

const std::int32_t fileTypeSelfDestructingVideoNote::ID;

void fileTypeSelfDestructingVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSelfDestructingVideoNote");
    s.store_class_end();
  }
}

fileTypeSelfDestructingVoiceNote::fileTypeSelfDestructingVoiceNote() {
}

const std::int32_t fileTypeSelfDestructingVoiceNote::ID;

void fileTypeSelfDestructingVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSelfDestructingVoiceNote");
    s.store_class_end();
  }
}

fileTypeSticker::fileTypeSticker() {
}

const std::int32_t fileTypeSticker::ID;

void fileTypeSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSticker");
    s.store_class_end();
  }
}

fileTypeThumbnail::fileTypeThumbnail() {
}

const std::int32_t fileTypeThumbnail::ID;

void fileTypeThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeThumbnail");
    s.store_class_end();
  }
}

fileTypeUnknown::fileTypeUnknown() {
}

const std::int32_t fileTypeUnknown::ID;

void fileTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeUnknown");
    s.store_class_end();
  }
}

fileTypeVideo::fileTypeVideo() {
}

const std::int32_t fileTypeVideo::ID;

void fileTypeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeVideo");
    s.store_class_end();
  }
}

fileTypeVideoNote::fileTypeVideoNote() {
}

const std::int32_t fileTypeVideoNote::ID;

void fileTypeVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeVideoNote");
    s.store_class_end();
  }
}

fileTypeVideoStory::fileTypeVideoStory() {
}

const std::int32_t fileTypeVideoStory::ID;

void fileTypeVideoStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeVideoStory");
    s.store_class_end();
  }
}

fileTypeVoiceNote::fileTypeVoiceNote() {
}

const std::int32_t fileTypeVoiceNote::ID;

void fileTypeVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeVoiceNote");
    s.store_class_end();
  }
}

fileTypeWallpaper::fileTypeWallpaper() {
}

const std::int32_t fileTypeWallpaper::ID;

void fileTypeWallpaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeWallpaper");
    s.store_class_end();
  }
}

giftChatThemes::giftChatThemes()
  : themes_()
  , next_offset_()
{}

giftChatThemes::giftChatThemes(array<object_ptr<giftChatTheme>> &&themes_, string const &next_offset_)
  : themes_(std::move(themes_))
  , next_offset_(next_offset_)
{}

const std::int32_t giftChatThemes::ID;

void giftChatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftChatThemes");
    { s.store_vector_begin("themes", themes_.size()); for (const auto &_value : themes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

giftUpgradePrice::giftUpgradePrice()
  : date_()
  , star_count_()
{}

giftUpgradePrice::giftUpgradePrice(int32 date_, int53 star_count_)
  : date_(date_)
  , star_count_(star_count_)
{}

const std::int32_t giftUpgradePrice::ID;

void giftUpgradePrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftUpgradePrice");
    s.store_field("date", date_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

giveawayPrizePremium::giveawayPrizePremium()
  : month_count_()
{}

giveawayPrizePremium::giveawayPrizePremium(int32 month_count_)
  : month_count_(month_count_)
{}

const std::int32_t giveawayPrizePremium::ID;

void giveawayPrizePremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayPrizePremium");
    s.store_field("month_count", month_count_);
    s.store_class_end();
  }
}

giveawayPrizeStars::giveawayPrizeStars()
  : star_count_()
{}

giveawayPrizeStars::giveawayPrizeStars(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t giveawayPrizeStars::ID;

void giveawayPrizeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayPrizeStars");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

gramRevenueStatistics::gramRevenueStatistics()
  : revenue_by_day_graph_()
  , status_()
  , usd_rate_()
{}

gramRevenueStatistics::gramRevenueStatistics(object_ptr<StatisticalGraph> &&revenue_by_day_graph_, object_ptr<gramRevenueStatus> &&status_, double usd_rate_)
  : revenue_by_day_graph_(std::move(revenue_by_day_graph_))
  , status_(std::move(status_))
  , usd_rate_(usd_rate_)
{}

const std::int32_t gramRevenueStatistics::ID;

void gramRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "gramRevenueStatistics");
    s.store_object_field("revenue_by_day_graph", static_cast<const BaseObject *>(revenue_by_day_graph_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("usd_rate", usd_rate_);
    s.store_class_end();
  }
}

groupCallJoinParameters::groupCallJoinParameters()
  : audio_source_id_()
  , payload_()
  , is_muted_()
  , is_my_video_enabled_()
{}

groupCallJoinParameters::groupCallJoinParameters(int32 audio_source_id_, string const &payload_, bool is_muted_, bool is_my_video_enabled_)
  : audio_source_id_(audio_source_id_)
  , payload_(payload_)
  , is_muted_(is_muted_)
  , is_my_video_enabled_(is_my_video_enabled_)
{}

const std::int32_t groupCallJoinParameters::ID;

void groupCallJoinParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallJoinParameters");
    s.store_field("audio_source_id", audio_source_id_);
    s.store_field("payload", payload_);
    s.store_field("is_muted", is_muted_);
    s.store_field("is_my_video_enabled", is_my_video_enabled_);
    s.store_class_end();
  }
}

groupCallParticipantVideoInfo::groupCallParticipantVideoInfo()
  : source_groups_()
  , endpoint_id_()
  , is_paused_()
{}

groupCallParticipantVideoInfo::groupCallParticipantVideoInfo(array<object_ptr<groupCallVideoSourceGroup>> &&source_groups_, string const &endpoint_id_, bool is_paused_)
  : source_groups_(std::move(source_groups_))
  , endpoint_id_(endpoint_id_)
  , is_paused_(is_paused_)
{}

const std::int32_t groupCallParticipantVideoInfo::ID;

void groupCallParticipantVideoInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipantVideoInfo");
    { s.store_vector_begin("source_groups", source_groups_.size()); for (const auto &_value : source_groups_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("endpoint_id", endpoint_id_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

inlineMessageId::inlineMessageId()
  : id_()
{}

inlineMessageId::inlineMessageId(string const &id_)
  : id_(id_)
{}

const std::int32_t inlineMessageId::ID;

void inlineMessageId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineMessageId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputAnimation::inputAnimation()
  : animation_()
  , thumbnail_()
  , added_sticker_file_ids_()
  , duration_()
  , width_()
  , height_()
{}

inputAnimation::inputAnimation(object_ptr<InputFile> &&animation_, object_ptr<inputThumbnail> &&thumbnail_, array<int32> &&added_sticker_file_ids_, int32 duration_, int32 width_, int32 height_)
  : animation_(std::move(animation_))
  , thumbnail_(std::move(thumbnail_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
{}

const std::int32_t inputAnimation::ID;

void inputAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

inputCallDiscarded::inputCallDiscarded()
  : call_id_()
{}

inputCallDiscarded::inputCallDiscarded(int32 call_id_)
  : call_id_(call_id_)
{}

const std::int32_t inputCallDiscarded::ID;

void inputCallDiscarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCallDiscarded");
    s.store_field("call_id", call_id_);
    s.store_class_end();
  }
}

inputCallFromMessage::inputCallFromMessage()
  : chat_id_()
  , message_id_()
{}

inputCallFromMessage::inputCallFromMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t inputCallFromMessage::ID;

void inputCallFromMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCallFromMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

inputPaidMediaTypePhoto::inputPaidMediaTypePhoto()
  : video_()
{}

inputPaidMediaTypePhoto::inputPaidMediaTypePhoto(object_ptr<InputFile> &&video_)
  : video_(std::move(video_))
{}

const std::int32_t inputPaidMediaTypePhoto::ID;

void inputPaidMediaTypePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaidMediaTypePhoto");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

inputPaidMediaTypeVideo::inputPaidMediaTypeVideo()
  : cover_()
  , start_timestamp_()
  , duration_()
  , supports_streaming_()
{}

inputPaidMediaTypeVideo::inputPaidMediaTypeVideo(object_ptr<InputFile> &&cover_, int32 start_timestamp_, int32 duration_, bool supports_streaming_)
  : cover_(std::move(cover_))
  , start_timestamp_(start_timestamp_)
  , duration_(duration_)
  , supports_streaming_(supports_streaming_)
{}

const std::int32_t inputPaidMediaTypeVideo::ID;

void inputPaidMediaTypeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaidMediaTypeVideo");
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_field("start_timestamp", start_timestamp_);
    s.store_field("duration", duration_);
    s.store_field("supports_streaming", supports_streaming_);
    s.store_class_end();
  }
}

inputPollOption::inputPollOption()
  : text_()
  , media_()
{}

inputPollOption::inputPollOption(object_ptr<formattedText> &&text_, object_ptr<InputPollMedia> &&media_)
  : text_(std::move(text_))
  , media_(std::move(media_))
{}

const std::int32_t inputPollOption::ID;

void inputPollOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollOption");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

inputRichMessage::inputRichMessage()
  : source_()
  , is_rtl_()
  , detect_automatic_blocks_()
{}

inputRichMessage::inputRichMessage(object_ptr<RichMessageSource> &&source_, bool is_rtl_, bool detect_automatic_blocks_)
  : source_(std::move(source_))
  , is_rtl_(is_rtl_)
  , detect_automatic_blocks_(detect_automatic_blocks_)
{}

const std::int32_t inputRichMessage::ID;

void inputRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputRichMessage");
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("is_rtl", is_rtl_);
    s.store_field("detect_automatic_blocks", detect_automatic_blocks_);
    s.store_class_end();
  }
}

inputStoryContentPhoto::inputStoryContentPhoto()
  : photo_()
  , added_sticker_file_ids_()
{}

inputStoryContentPhoto::inputStoryContentPhoto(object_ptr<InputFile> &&photo_, array<int32> &&added_sticker_file_ids_)
  : photo_(std::move(photo_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
{}

const std::int32_t inputStoryContentPhoto::ID;

void inputStoryContentPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryContentPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputStoryContentVideo::inputStoryContentVideo()
  : video_()
  , added_sticker_file_ids_()
  , duration_()
  , cover_frame_timestamp_()
  , is_animation_()
{}

inputStoryContentVideo::inputStoryContentVideo(object_ptr<InputFile> &&video_, array<int32> &&added_sticker_file_ids_, double duration_, double cover_frame_timestamp_, bool is_animation_)
  : video_(std::move(video_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , duration_(duration_)
  , cover_frame_timestamp_(cover_frame_timestamp_)
  , is_animation_(is_animation_)
{}

const std::int32_t inputStoryContentVideo::ID;

void inputStoryContentVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryContentVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("duration", duration_);
    s.store_field("cover_frame_timestamp", cover_frame_timestamp_);
    s.store_field("is_animation", is_animation_);
    s.store_class_end();
  }
}

inputThumbnail::inputThumbnail()
  : thumbnail_()
  , width_()
  , height_()
{}

inputThumbnail::inputThumbnail(object_ptr<InputFile> &&thumbnail_, int32 width_, int32 height_)
  : thumbnail_(std::move(thumbnail_))
  , width_(width_)
  , height_(height_)
{}

const std::int32_t inputThumbnail::ID;

void inputThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputThumbnail");
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

inputVideo::inputVideo()
  : video_()
  , thumbnail_()
  , cover_()
  , start_timestamp_()
  , added_sticker_file_ids_()
  , duration_()
  , width_()
  , height_()
  , supports_streaming_()
{}

inputVideo::inputVideo(object_ptr<InputFile> &&video_, object_ptr<inputThumbnail> &&thumbnail_, object_ptr<InputFile> &&cover_, int32 start_timestamp_, array<int32> &&added_sticker_file_ids_, int32 duration_, int32 width_, int32 height_, bool supports_streaming_)
  : video_(std::move(video_))
  , thumbnail_(std::move(thumbnail_))
  , cover_(std::move(cover_))
  , start_timestamp_(start_timestamp_)
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
  , supports_streaming_(supports_streaming_)
{}

const std::int32_t inputVideo::ID;

void inputVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_field("start_timestamp", start_timestamp_);
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("supports_streaming", supports_streaming_);
    s.store_class_end();
  }
}

keyboardButtonSourceMessage::keyboardButtonSourceMessage()
  : chat_id_()
  , message_id_()
{}

keyboardButtonSourceMessage::keyboardButtonSourceMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t keyboardButtonSourceMessage::ID;

void keyboardButtonSourceMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonSourceMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

keyboardButtonSourceWebApp::keyboardButtonSourceWebApp()
  : bot_user_id_()
  , prepared_button_id_()
{}

keyboardButtonSourceWebApp::keyboardButtonSourceWebApp(int53 bot_user_id_, string const &prepared_button_id_)
  : bot_user_id_(bot_user_id_)
  , prepared_button_id_(prepared_button_id_)
{}

const std::int32_t keyboardButtonSourceWebApp::ID;

void keyboardButtonSourceWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonSourceWebApp");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("prepared_button_id", prepared_button_id_);
    s.store_class_end();
  }
}

maskPosition::maskPosition()
  : point_()
  , x_shift_()
  , y_shift_()
  , scale_()
{}

maskPosition::maskPosition(object_ptr<MaskPoint> &&point_, double x_shift_, double y_shift_, double scale_)
  : point_(std::move(point_))
  , x_shift_(x_shift_)
  , y_shift_(y_shift_)
  , scale_(scale_)
{}

const std::int32_t maskPosition::ID;

void maskPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPosition");
    s.store_object_field("point", static_cast<const BaseObject *>(point_.get()));
    s.store_field("x_shift", x_shift_);
    s.store_field("y_shift", y_shift_);
    s.store_field("scale", scale_);
    s.store_class_end();
  }
}

messageFileTypePrivate::messageFileTypePrivate()
  : name_()
{}

messageFileTypePrivate::messageFileTypePrivate(string const &name_)
  : name_(name_)
{}

const std::int32_t messageFileTypePrivate::ID;

void messageFileTypePrivate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageFileTypePrivate");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

messageFileTypeGroup::messageFileTypeGroup()
  : title_()
{}

messageFileTypeGroup::messageFileTypeGroup(string const &title_)
  : title_(title_)
{}

const std::int32_t messageFileTypeGroup::ID;

void messageFileTypeGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageFileTypeGroup");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

messageFileTypeUnknown::messageFileTypeUnknown() {
}

const std::int32_t messageFileTypeUnknown::ID;

void messageFileTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageFileTypeUnknown");
    s.store_class_end();
  }
}

messageReadDateRead::messageReadDateRead()
  : read_date_()
{}

messageReadDateRead::messageReadDateRead(int32 read_date_)
  : read_date_(read_date_)
{}

const std::int32_t messageReadDateRead::ID;

void messageReadDateRead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReadDateRead");
    s.store_field("read_date", read_date_);
    s.store_class_end();
  }
}

messageReadDateUnread::messageReadDateUnread() {
}

const std::int32_t messageReadDateUnread::ID;

void messageReadDateUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReadDateUnread");
    s.store_class_end();
  }
}

messageReadDateTooOld::messageReadDateTooOld() {
}

const std::int32_t messageReadDateTooOld::ID;

void messageReadDateTooOld::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReadDateTooOld");
    s.store_class_end();
  }
}

messageReadDateUserPrivacyRestricted::messageReadDateUserPrivacyRestricted() {
}

const std::int32_t messageReadDateUserPrivacyRestricted::ID;

void messageReadDateUserPrivacyRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReadDateUserPrivacyRestricted");
    s.store_class_end();
  }
}

messageReadDateMyPrivacyRestricted::messageReadDateMyPrivacyRestricted() {
}

const std::int32_t messageReadDateMyPrivacyRestricted::ID;

void messageReadDateMyPrivacyRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReadDateMyPrivacyRestricted");
    s.store_class_end();
  }
}

minithumbnail::minithumbnail()
  : width_()
  , height_()
  , data_()
{}

minithumbnail::minithumbnail(int32 width_, int32 height_, bytes const &data_)
  : width_(width_)
  , height_(height_)
  , data_(std::move(data_))
{}

const std::int32_t minithumbnail::ID;

void minithumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "minithumbnail");
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

onRampPaymentAvailability::onRampPaymentAvailability()
  : is_allowed_()
  , is_purchase_allowed_()
  , methods_()
  , country_code_()
  , state_()
{}

onRampPaymentAvailability::onRampPaymentAvailability(bool is_allowed_, bool is_purchase_allowed_, array<object_ptr<onRampPaymentMethod>> &&methods_, string const &country_code_, string const &state_)
  : is_allowed_(is_allowed_)
  , is_purchase_allowed_(is_purchase_allowed_)
  , methods_(std::move(methods_))
  , country_code_(country_code_)
  , state_(state_)
{}

const std::int32_t onRampPaymentAvailability::ID;

void onRampPaymentAvailability::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onRampPaymentAvailability");
    s.store_field("is_allowed", is_allowed_);
    s.store_field("is_purchase_allowed", is_purchase_allowed_);
    { s.store_vector_begin("methods", methods_.size()); for (const auto &_value : methods_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("country_code", country_code_);
    s.store_field("state", state_);
    s.store_class_end();
  }
}

pageBlockTitle::pageBlockTitle()
  : title_()
{}

pageBlockTitle::pageBlockTitle(object_ptr<RichText> &&title_)
  : title_(std::move(title_))
{}

const std::int32_t pageBlockTitle::ID;

void pageBlockTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTitle");
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    s.store_class_end();
  }
}

pageBlockSubtitle::pageBlockSubtitle()
  : subtitle_()
{}

pageBlockSubtitle::pageBlockSubtitle(object_ptr<RichText> &&subtitle_)
  : subtitle_(std::move(subtitle_))
{}

const std::int32_t pageBlockSubtitle::ID;

void pageBlockSubtitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSubtitle");
    s.store_object_field("subtitle", static_cast<const BaseObject *>(subtitle_.get()));
    s.store_class_end();
  }
}

pageBlockAuthorDate::pageBlockAuthorDate()
  : author_()
  , publish_date_()
{}

pageBlockAuthorDate::pageBlockAuthorDate(object_ptr<RichText> &&author_, int32 publish_date_)
  : author_(std::move(author_))
  , publish_date_(publish_date_)
{}

const std::int32_t pageBlockAuthorDate::ID;

void pageBlockAuthorDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAuthorDate");
    s.store_object_field("author", static_cast<const BaseObject *>(author_.get()));
    s.store_field("publish_date", publish_date_);
    s.store_class_end();
  }
}

pageBlockHeader::pageBlockHeader()
  : header_()
{}

pageBlockHeader::pageBlockHeader(object_ptr<RichText> &&header_)
  : header_(std::move(header_))
{}

const std::int32_t pageBlockHeader::ID;

void pageBlockHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHeader");
    s.store_object_field("header", static_cast<const BaseObject *>(header_.get()));
    s.store_class_end();
  }
}

pageBlockSubheader::pageBlockSubheader()
  : subheader_()
{}

pageBlockSubheader::pageBlockSubheader(object_ptr<RichText> &&subheader_)
  : subheader_(std::move(subheader_))
{}

const std::int32_t pageBlockSubheader::ID;

void pageBlockSubheader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSubheader");
    s.store_object_field("subheader", static_cast<const BaseObject *>(subheader_.get()));
    s.store_class_end();
  }
}

pageBlockSectionHeading::pageBlockSectionHeading()
  : text_()
  , size_()
{}

pageBlockSectionHeading::pageBlockSectionHeading(object_ptr<RichText> &&text_, int32 size_)
  : text_(std::move(text_))
  , size_(size_)
{}

const std::int32_t pageBlockSectionHeading::ID;

void pageBlockSectionHeading::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSectionHeading");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("size", size_);
    s.store_class_end();
  }
}

pageBlockKicker::pageBlockKicker()
  : kicker_()
{}

pageBlockKicker::pageBlockKicker(object_ptr<RichText> &&kicker_)
  : kicker_(std::move(kicker_))
{}

const std::int32_t pageBlockKicker::ID;

void pageBlockKicker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockKicker");
    s.store_object_field("kicker", static_cast<const BaseObject *>(kicker_.get()));
    s.store_class_end();
  }
}

pageBlockParagraph::pageBlockParagraph()
  : text_()
{}

pageBlockParagraph::pageBlockParagraph(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockParagraph::ID;

void pageBlockParagraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockParagraph");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockPreformatted::pageBlockPreformatted()
  : text_()
  , language_()
{}

pageBlockPreformatted::pageBlockPreformatted(object_ptr<RichText> &&text_, string const &language_)
  : text_(std::move(text_))
  , language_(language_)
{}

const std::int32_t pageBlockPreformatted::ID;

void pageBlockPreformatted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPreformatted");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("language", language_);
    s.store_class_end();
  }
}

pageBlockFooter::pageBlockFooter()
  : footer_()
{}

pageBlockFooter::pageBlockFooter(object_ptr<RichText> &&footer_)
  : footer_(std::move(footer_))
{}

const std::int32_t pageBlockFooter::ID;

void pageBlockFooter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockFooter");
    s.store_object_field("footer", static_cast<const BaseObject *>(footer_.get()));
    s.store_class_end();
  }
}

pageBlockThinking::pageBlockThinking()
  : text_()
{}

pageBlockThinking::pageBlockThinking(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockThinking::ID;

void pageBlockThinking::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockThinking");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockDivider::pageBlockDivider() {
}

const std::int32_t pageBlockDivider::ID;

void pageBlockDivider::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDivider");
    s.store_class_end();
  }
}

pageBlockMathematicalExpression::pageBlockMathematicalExpression()
  : expression_()
{}

pageBlockMathematicalExpression::pageBlockMathematicalExpression(string const &expression_)
  : expression_(expression_)
{}

const std::int32_t pageBlockMathematicalExpression::ID;

void pageBlockMathematicalExpression::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockMathematicalExpression");
    s.store_field("expression", expression_);
    s.store_class_end();
  }
}

pageBlockAnchor::pageBlockAnchor()
  : name_()
{}

pageBlockAnchor::pageBlockAnchor(string const &name_)
  : name_(name_)
{}

const std::int32_t pageBlockAnchor::ID;

void pageBlockAnchor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAnchor");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

pageBlockList::pageBlockList()
  : items_()
{}

pageBlockList::pageBlockList(array<object_ptr<pageBlockListItem>> &&items_)
  : items_(std::move(items_))
{}

const std::int32_t pageBlockList::ID;

void pageBlockList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockList");
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockBlockQuote::pageBlockBlockQuote()
  : blocks_()
  , credit_()
{}

pageBlockBlockQuote::pageBlockBlockQuote(array<object_ptr<PageBlock>> &&blocks_, object_ptr<RichText> &&credit_)
  : blocks_(std::move(blocks_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageBlockBlockQuote::ID;

void pageBlockBlockQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockBlockQuote");
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

pageBlockExpandableBlockQuote::pageBlockExpandableBlockQuote()
  : text_()
  , credit_()
{}

pageBlockExpandableBlockQuote::pageBlockExpandableBlockQuote(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageBlockExpandableBlockQuote::ID;

void pageBlockExpandableBlockQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockExpandableBlockQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

pageBlockPullQuote::pageBlockPullQuote()
  : text_()
  , credit_()
{}

pageBlockPullQuote::pageBlockPullQuote(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageBlockPullQuote::ID;

void pageBlockPullQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPullQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

pageBlockAnimation::pageBlockAnimation()
  : animation_()
  , caption_()
  , need_autoplay_()
  , has_spoiler_()
{}

pageBlockAnimation::pageBlockAnimation(object_ptr<animation> &&animation_, object_ptr<pageBlockCaption> &&caption_, bool need_autoplay_, bool has_spoiler_)
  : animation_(std::move(animation_))
  , caption_(std::move(caption_))
  , need_autoplay_(need_autoplay_)
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t pageBlockAnimation::ID;

void pageBlockAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("need_autoplay", need_autoplay_);
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

pageBlockAudio::pageBlockAudio()
  : audio_()
  , caption_()
{}

pageBlockAudio::pageBlockAudio(object_ptr<audio> &&audio_, object_ptr<pageBlockCaption> &&caption_)
  : audio_(std::move(audio_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockAudio::ID;

void pageBlockAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockDocument::pageBlockDocument()
  : document_()
  , caption_()
{}

pageBlockDocument::pageBlockDocument(object_ptr<document> &&document_, object_ptr<pageBlockCaption> &&caption_)
  : document_(std::move(document_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockDocument::ID;

void pageBlockDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockPhoto::pageBlockPhoto()
  : photo_()
  , caption_()
  , url_()
  , has_spoiler_()
{}

pageBlockPhoto::pageBlockPhoto(object_ptr<photo> &&photo_, object_ptr<pageBlockCaption> &&caption_, string const &url_, bool has_spoiler_)
  : photo_(std::move(photo_))
  , caption_(std::move(caption_))
  , url_(url_)
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t pageBlockPhoto::ID;

void pageBlockPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("url", url_);
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

pageBlockVideo::pageBlockVideo()
  : video_()
  , caption_()
  , need_autoplay_()
  , is_looped_()
  , has_spoiler_()
{}

pageBlockVideo::pageBlockVideo(object_ptr<video> &&video_, object_ptr<pageBlockCaption> &&caption_, bool need_autoplay_, bool is_looped_, bool has_spoiler_)
  : video_(std::move(video_))
  , caption_(std::move(caption_))
  , need_autoplay_(need_autoplay_)
  , is_looped_(is_looped_)
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t pageBlockVideo::ID;

void pageBlockVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("need_autoplay", need_autoplay_);
    s.store_field("is_looped", is_looped_);
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

pageBlockVoiceNote::pageBlockVoiceNote()
  : voice_note_()
  , caption_()
{}

pageBlockVoiceNote::pageBlockVoiceNote(object_ptr<voiceNote> &&voice_note_, object_ptr<pageBlockCaption> &&caption_)
  : voice_note_(std::move(voice_note_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockVoiceNote::ID;

void pageBlockVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockCover::pageBlockCover()
  : cover_()
{}

pageBlockCover::pageBlockCover(object_ptr<PageBlock> &&cover_)
  : cover_(std::move(cover_))
{}

const std::int32_t pageBlockCover::ID;

void pageBlockCover::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCover");
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_class_end();
  }
}

pageBlockEmbedded::pageBlockEmbedded()
  : url_()
  , html_()
  , poster_photo_()
  , width_()
  , height_()
  , caption_()
  , is_full_width_()
  , allow_scrolling_()
{}

pageBlockEmbedded::pageBlockEmbedded(string const &url_, string const &html_, object_ptr<photo> &&poster_photo_, int32 width_, int32 height_, object_ptr<pageBlockCaption> &&caption_, bool is_full_width_, bool allow_scrolling_)
  : url_(url_)
  , html_(html_)
  , poster_photo_(std::move(poster_photo_))
  , width_(width_)
  , height_(height_)
  , caption_(std::move(caption_))
  , is_full_width_(is_full_width_)
  , allow_scrolling_(allow_scrolling_)
{}

const std::int32_t pageBlockEmbedded::ID;

void pageBlockEmbedded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockEmbedded");
    s.store_field("url", url_);
    s.store_field("html", html_);
    s.store_object_field("poster_photo", static_cast<const BaseObject *>(poster_photo_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("is_full_width", is_full_width_);
    s.store_field("allow_scrolling", allow_scrolling_);
    s.store_class_end();
  }
}

pageBlockEmbeddedPost::pageBlockEmbeddedPost()
  : url_()
  , author_()
  , author_photo_()
  , date_()
  , blocks_()
  , caption_()
{}

pageBlockEmbeddedPost::pageBlockEmbeddedPost(string const &url_, string const &author_, object_ptr<photo> &&author_photo_, int32 date_, array<object_ptr<PageBlock>> &&blocks_, object_ptr<pageBlockCaption> &&caption_)
  : url_(url_)
  , author_(author_)
  , author_photo_(std::move(author_photo_))
  , date_(date_)
  , blocks_(std::move(blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockEmbeddedPost::ID;

void pageBlockEmbeddedPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockEmbeddedPost");
    s.store_field("url", url_);
    s.store_field("author", author_);
    s.store_object_field("author_photo", static_cast<const BaseObject *>(author_photo_.get()));
    s.store_field("date", date_);
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockCollage::pageBlockCollage()
  : blocks_()
  , caption_()
{}

pageBlockCollage::pageBlockCollage(array<object_ptr<PageBlock>> &&blocks_, object_ptr<pageBlockCaption> &&caption_)
  : blocks_(std::move(blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockCollage::ID;

void pageBlockCollage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCollage");
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockSlideshow::pageBlockSlideshow()
  : blocks_()
  , caption_()
{}

pageBlockSlideshow::pageBlockSlideshow(array<object_ptr<PageBlock>> &&blocks_, object_ptr<pageBlockCaption> &&caption_)
  : blocks_(std::move(blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockSlideshow::ID;

void pageBlockSlideshow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSlideshow");
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockChatLink::pageBlockChatLink()
  : title_()
  , photo_()
  , accent_color_id_()
  , username_()
{}

pageBlockChatLink::pageBlockChatLink(string const &title_, object_ptr<chatPhotoInfo> &&photo_, int32 accent_color_id_, string const &username_)
  : title_(title_)
  , photo_(std::move(photo_))
  , accent_color_id_(accent_color_id_)
  , username_(username_)
{}

const std::int32_t pageBlockChatLink::ID;

void pageBlockChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockChatLink");
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("username", username_);
    s.store_class_end();
  }
}

pageBlockTable::pageBlockTable()
  : caption_()
  , cells_()
  , is_bordered_()
  , is_striped_()
  , is_compact_()
{}

pageBlockTable::pageBlockTable(object_ptr<RichText> &&caption_, array<array<object_ptr<pageBlockTableCell>>> &&cells_, bool is_bordered_, bool is_striped_, bool is_compact_)
  : caption_(std::move(caption_))
  , cells_(std::move(cells_))
  , is_bordered_(is_bordered_)
  , is_striped_(is_striped_)
  , is_compact_(is_compact_)
{}

const std::int32_t pageBlockTable::ID;

void pageBlockTable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTable");
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    { s.store_vector_begin("cells", cells_.size()); for (const auto &_value : cells_) { { s.store_vector_begin("", _value.size()); for (const auto &_value2 : _value) { s.store_object_field("", static_cast<const BaseObject *>(_value2.get())); } s.store_class_end(); } } s.store_class_end(); }
    s.store_field("is_bordered", is_bordered_);
    s.store_field("is_striped", is_striped_);
    s.store_field("is_compact", is_compact_);
    s.store_class_end();
  }
}

pageBlockDetails::pageBlockDetails()
  : header_()
  , blocks_()
  , is_open_()
{}

pageBlockDetails::pageBlockDetails(object_ptr<RichText> &&header_, array<object_ptr<PageBlock>> &&blocks_, bool is_open_)
  : header_(std::move(header_))
  , blocks_(std::move(blocks_))
  , is_open_(is_open_)
{}

const std::int32_t pageBlockDetails::ID;

void pageBlockDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDetails");
    s.store_object_field("header", static_cast<const BaseObject *>(header_.get()));
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_open", is_open_);
    s.store_class_end();
  }
}

pageBlockRelatedArticles::pageBlockRelatedArticles()
  : header_()
  , articles_()
{}

pageBlockRelatedArticles::pageBlockRelatedArticles(object_ptr<RichText> &&header_, array<object_ptr<pageBlockRelatedArticle>> &&articles_)
  : header_(std::move(header_))
  , articles_(std::move(articles_))
{}

const std::int32_t pageBlockRelatedArticles::ID;

void pageBlockRelatedArticles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockRelatedArticles");
    s.store_object_field("header", static_cast<const BaseObject *>(header_.get()));
    { s.store_vector_begin("articles", articles_.size()); for (const auto &_value : articles_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockMap::pageBlockMap()
  : location_()
  , zoom_()
  , width_()
  , height_()
  , caption_()
{}

pageBlockMap::pageBlockMap(object_ptr<location> &&location_, int32 zoom_, int32 width_, int32 height_, object_ptr<pageBlockCaption> &&caption_)
  : location_(std::move(location_))
  , zoom_(zoom_)
  , width_(width_)
  , height_(height_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockMap::ID;

void pageBlockMap::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockMap");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("zoom", zoom_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockButtonRow::pageBlockButtonRow()
  : buttons_()
  , align_()
{}

pageBlockButtonRow::pageBlockButtonRow(array<object_ptr<inlineButton>> &&buttons_, object_ptr<PageBlockHorizontalAlignment> &&align_)
  : buttons_(std::move(buttons_))
  , align_(std::move(align_))
{}

const std::int32_t pageBlockButtonRow::ID;

void pageBlockButtonRow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockButtonRow");
    { s.store_vector_begin("buttons", buttons_.size()); for (const auto &_value : buttons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("align", static_cast<const BaseObject *>(align_.get()));
    s.store_class_end();
  }
}

pageBlockUnsupported::pageBlockUnsupported() {
}

const std::int32_t pageBlockUnsupported::ID;

void pageBlockUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockUnsupported");
    s.store_class_end();
  }
}

pageBlockVerticalAlignmentTop::pageBlockVerticalAlignmentTop() {
}

const std::int32_t pageBlockVerticalAlignmentTop::ID;

void pageBlockVerticalAlignmentTop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVerticalAlignmentTop");
    s.store_class_end();
  }
}

pageBlockVerticalAlignmentMiddle::pageBlockVerticalAlignmentMiddle() {
}

const std::int32_t pageBlockVerticalAlignmentMiddle::ID;

void pageBlockVerticalAlignmentMiddle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVerticalAlignmentMiddle");
    s.store_class_end();
  }
}

pageBlockVerticalAlignmentBottom::pageBlockVerticalAlignmentBottom() {
}

const std::int32_t pageBlockVerticalAlignmentBottom::ID;

void pageBlockVerticalAlignmentBottom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVerticalAlignmentBottom");
    s.store_class_end();
  }
}

paidReactionTypeRegular::paidReactionTypeRegular() {
}

const std::int32_t paidReactionTypeRegular::ID;

void paidReactionTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionTypeRegular");
    s.store_class_end();
  }
}

paidReactionTypeAnonymous::paidReactionTypeAnonymous() {
}

const std::int32_t paidReactionTypeAnonymous::ID;

void paidReactionTypeAnonymous::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionTypeAnonymous");
    s.store_class_end();
  }
}

paidReactionTypeChat::paidReactionTypeChat()
  : chat_id_()
{}

paidReactionTypeChat::paidReactionTypeChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t paidReactionTypeChat::ID;

void paidReactionTypeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionTypeChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

passkeys::passkeys()
  : passkeys_()
{}

passkeys::passkeys(array<object_ptr<passkey>> &&passkeys_)
  : passkeys_(std::move(passkeys_))
{}

const std::int32_t passkeys::ID;

void passkeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passkeys");
    { s.store_vector_begin("passkeys", passkeys_.size()); for (const auto &_value : passkeys_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

passportElementsWithErrors::passportElementsWithErrors()
  : elements_()
  , errors_()
{}

passportElementsWithErrors::passportElementsWithErrors(array<object_ptr<PassportElement>> &&elements_, array<object_ptr<passportElementError>> &&errors_)
  : elements_(std::move(elements_))
  , errors_(std::move(errors_))
{}

const std::int32_t passportElementsWithErrors::ID;

void passportElementsWithErrors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementsWithErrors");
    { s.store_vector_begin("elements", elements_.size()); for (const auto &_value : elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("errors", errors_.size()); for (const auto &_value : errors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pollOption::pollOption()
  : id_()
  , text_()
  , media_()
  , voter_count_()
  , vote_percentage_()
  , recent_voter_ids_()
  , is_chosen_()
  , is_being_chosen_()
  , author_()
  , addition_date_()
{}

pollOption::pollOption(string const &id_, object_ptr<formattedText> &&text_, object_ptr<PollMedia> &&media_, int32 voter_count_, int32 vote_percentage_, array<object_ptr<MessageSender>> &&recent_voter_ids_, bool is_chosen_, bool is_being_chosen_, object_ptr<MessageSender> &&author_, int32 addition_date_)
  : id_(id_)
  , text_(std::move(text_))
  , media_(std::move(media_))
  , voter_count_(voter_count_)
  , vote_percentage_(vote_percentage_)
  , recent_voter_ids_(std::move(recent_voter_ids_))
  , is_chosen_(is_chosen_)
  , is_being_chosen_(is_being_chosen_)
  , author_(std::move(author_))
  , addition_date_(addition_date_)
{}

const std::int32_t pollOption::ID;

void pollOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollOption");
    s.store_field("id", id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_field("voter_count", voter_count_);
    s.store_field("vote_percentage", vote_percentage_);
    { s.store_vector_begin("recent_voter_ids", recent_voter_ids_.size()); for (const auto &_value : recent_voter_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_chosen", is_chosen_);
    s.store_field("is_being_chosen", is_being_chosen_);
    s.store_object_field("author", static_cast<const BaseObject *>(author_.get()));
    s.store_field("addition_date", addition_date_);
    s.store_class_end();
  }
}

premiumGiveawayPaymentOption::premiumGiveawayPaymentOption()
  : currency_()
  , amount_()
  , winner_count_()
  , month_count_()
  , store_product_id_()
  , store_product_quantity_()
{}

premiumGiveawayPaymentOption::premiumGiveawayPaymentOption(string const &currency_, int53 amount_, int32 winner_count_, int32 month_count_, string const &store_product_id_, int32 store_product_quantity_)
  : currency_(currency_)
  , amount_(amount_)
  , winner_count_(winner_count_)
  , month_count_(month_count_)
  , store_product_id_(store_product_id_)
  , store_product_quantity_(store_product_quantity_)
{}

const std::int32_t premiumGiveawayPaymentOption::ID;

void premiumGiveawayPaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiveawayPaymentOption");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("winner_count", winner_count_);
    s.store_field("month_count", month_count_);
    s.store_field("store_product_id", store_product_id_);
    s.store_field("store_product_quantity", store_product_quantity_);
    s.store_class_end();
  }
}

premiumLimitTypeSupergroupCount::premiumLimitTypeSupergroupCount() {
}

const std::int32_t premiumLimitTypeSupergroupCount::ID;

void premiumLimitTypeSupergroupCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeSupergroupCount");
    s.store_class_end();
  }
}

premiumLimitTypePinnedChatCount::premiumLimitTypePinnedChatCount() {
}

const std::int32_t premiumLimitTypePinnedChatCount::ID;

void premiumLimitTypePinnedChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypePinnedChatCount");
    s.store_class_end();
  }
}

premiumLimitTypeCreatedPublicChatCount::premiumLimitTypeCreatedPublicChatCount() {
}

const std::int32_t premiumLimitTypeCreatedPublicChatCount::ID;

void premiumLimitTypeCreatedPublicChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeCreatedPublicChatCount");
    s.store_class_end();
  }
}

premiumLimitTypeSavedAnimationCount::premiumLimitTypeSavedAnimationCount() {
}

const std::int32_t premiumLimitTypeSavedAnimationCount::ID;

void premiumLimitTypeSavedAnimationCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeSavedAnimationCount");
    s.store_class_end();
  }
}

premiumLimitTypeFavoriteStickerCount::premiumLimitTypeFavoriteStickerCount() {
}

const std::int32_t premiumLimitTypeFavoriteStickerCount::ID;

void premiumLimitTypeFavoriteStickerCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeFavoriteStickerCount");
    s.store_class_end();
  }
}

premiumLimitTypeChatFolderCount::premiumLimitTypeChatFolderCount() {
}

const std::int32_t premiumLimitTypeChatFolderCount::ID;

void premiumLimitTypeChatFolderCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeChatFolderCount");
    s.store_class_end();
  }
}

premiumLimitTypeChatFolderChosenChatCount::premiumLimitTypeChatFolderChosenChatCount() {
}

const std::int32_t premiumLimitTypeChatFolderChosenChatCount::ID;

void premiumLimitTypeChatFolderChosenChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeChatFolderChosenChatCount");
    s.store_class_end();
  }
}

premiumLimitTypePinnedArchivedChatCount::premiumLimitTypePinnedArchivedChatCount() {
}

const std::int32_t premiumLimitTypePinnedArchivedChatCount::ID;

void premiumLimitTypePinnedArchivedChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypePinnedArchivedChatCount");
    s.store_class_end();
  }
}

premiumLimitTypePinnedSavedMessagesTopicCount::premiumLimitTypePinnedSavedMessagesTopicCount() {
}

const std::int32_t premiumLimitTypePinnedSavedMessagesTopicCount::ID;

void premiumLimitTypePinnedSavedMessagesTopicCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypePinnedSavedMessagesTopicCount");
    s.store_class_end();
  }
}

premiumLimitTypeMessageTextLength::premiumLimitTypeMessageTextLength() {
}

const std::int32_t premiumLimitTypeMessageTextLength::ID;

void premiumLimitTypeMessageTextLength::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeMessageTextLength");
    s.store_class_end();
  }
}

premiumLimitTypeCaptionLength::premiumLimitTypeCaptionLength() {
}

const std::int32_t premiumLimitTypeCaptionLength::ID;

void premiumLimitTypeCaptionLength::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeCaptionLength");
    s.store_class_end();
  }
}

premiumLimitTypeBioLength::premiumLimitTypeBioLength() {
}

const std::int32_t premiumLimitTypeBioLength::ID;

void premiumLimitTypeBioLength::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeBioLength");
    s.store_class_end();
  }
}

premiumLimitTypeChatFolderInviteLinkCount::premiumLimitTypeChatFolderInviteLinkCount() {
}

const std::int32_t premiumLimitTypeChatFolderInviteLinkCount::ID;

void premiumLimitTypeChatFolderInviteLinkCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeChatFolderInviteLinkCount");
    s.store_class_end();
  }
}

premiumLimitTypeShareableChatFolderCount::premiumLimitTypeShareableChatFolderCount() {
}

const std::int32_t premiumLimitTypeShareableChatFolderCount::ID;

void premiumLimitTypeShareableChatFolderCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeShareableChatFolderCount");
    s.store_class_end();
  }
}

premiumLimitTypeActiveStoryCount::premiumLimitTypeActiveStoryCount() {
}

const std::int32_t premiumLimitTypeActiveStoryCount::ID;

void premiumLimitTypeActiveStoryCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeActiveStoryCount");
    s.store_class_end();
  }
}

premiumLimitTypeWeeklyPostedStoryCount::premiumLimitTypeWeeklyPostedStoryCount() {
}

const std::int32_t premiumLimitTypeWeeklyPostedStoryCount::ID;

void premiumLimitTypeWeeklyPostedStoryCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeWeeklyPostedStoryCount");
    s.store_class_end();
  }
}

premiumLimitTypeMonthlyPostedStoryCount::premiumLimitTypeMonthlyPostedStoryCount() {
}

const std::int32_t premiumLimitTypeMonthlyPostedStoryCount::ID;

void premiumLimitTypeMonthlyPostedStoryCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeMonthlyPostedStoryCount");
    s.store_class_end();
  }
}

premiumLimitTypeStoryCaptionLength::premiumLimitTypeStoryCaptionLength() {
}

const std::int32_t premiumLimitTypeStoryCaptionLength::ID;

void premiumLimitTypeStoryCaptionLength::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeStoryCaptionLength");
    s.store_class_end();
  }
}

premiumLimitTypeStorySuggestedReactionAreaCount::premiumLimitTypeStorySuggestedReactionAreaCount() {
}

const std::int32_t premiumLimitTypeStorySuggestedReactionAreaCount::ID;

void premiumLimitTypeStorySuggestedReactionAreaCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeStorySuggestedReactionAreaCount");
    s.store_class_end();
  }
}

premiumLimitTypeSimilarChatCount::premiumLimitTypeSimilarChatCount() {
}

const std::int32_t premiumLimitTypeSimilarChatCount::ID;

void premiumLimitTypeSimilarChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeSimilarChatCount");
    s.store_class_end();
  }
}

premiumLimitTypeOwnedBotCount::premiumLimitTypeOwnedBotCount() {
}

const std::int32_t premiumLimitTypeOwnedBotCount::ID;

void premiumLimitTypeOwnedBotCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeOwnedBotCount");
    s.store_class_end();
  }
}

premiumLimitTypeCustomTextCompositionStyleCount::premiumLimitTypeCustomTextCompositionStyleCount() {
}

const std::int32_t premiumLimitTypeCustomTextCompositionStyleCount::ID;

void premiumLimitTypeCustomTextCompositionStyleCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeCustomTextCompositionStyleCount");
    s.store_class_end();
  }
}

premiumSourceLimitExceeded::premiumSourceLimitExceeded()
  : limit_type_()
{}

premiumSourceLimitExceeded::premiumSourceLimitExceeded(object_ptr<PremiumLimitType> &&limit_type_)
  : limit_type_(std::move(limit_type_))
{}

const std::int32_t premiumSourceLimitExceeded::ID;

void premiumSourceLimitExceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceLimitExceeded");
    s.store_object_field("limit_type", static_cast<const BaseObject *>(limit_type_.get()));
    s.store_class_end();
  }
}

premiumSourceFeature::premiumSourceFeature()
  : feature_()
{}

premiumSourceFeature::premiumSourceFeature(object_ptr<PremiumFeature> &&feature_)
  : feature_(std::move(feature_))
{}

const std::int32_t premiumSourceFeature::ID;

void premiumSourceFeature::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceFeature");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_class_end();
  }
}

premiumSourceBusinessFeature::premiumSourceBusinessFeature()
  : feature_()
{}

premiumSourceBusinessFeature::premiumSourceBusinessFeature(object_ptr<BusinessFeature> &&feature_)
  : feature_(std::move(feature_))
{}

const std::int32_t premiumSourceBusinessFeature::ID;

void premiumSourceBusinessFeature::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceBusinessFeature");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_class_end();
  }
}

premiumSourceStoryFeature::premiumSourceStoryFeature()
  : feature_()
{}

premiumSourceStoryFeature::premiumSourceStoryFeature(object_ptr<PremiumStoryFeature> &&feature_)
  : feature_(std::move(feature_))
{}

const std::int32_t premiumSourceStoryFeature::ID;

void premiumSourceStoryFeature::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceStoryFeature");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_class_end();
  }
}

premiumSourceLink::premiumSourceLink()
  : referrer_()
{}

premiumSourceLink::premiumSourceLink(string const &referrer_)
  : referrer_(referrer_)
{}

const std::int32_t premiumSourceLink::ID;

void premiumSourceLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceLink");
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

premiumSourceSettings::premiumSourceSettings() {
}

const std::int32_t premiumSourceSettings::ID;

void premiumSourceSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceSettings");
    s.store_class_end();
  }
}

profileAccentColor::profileAccentColor()
  : id_()
  , light_theme_colors_()
  , dark_theme_colors_()
  , min_supergroup_chat_boost_level_()
  , min_channel_chat_boost_level_()
{}

profileAccentColor::profileAccentColor(int32 id_, object_ptr<profileAccentColors> &&light_theme_colors_, object_ptr<profileAccentColors> &&dark_theme_colors_, int32 min_supergroup_chat_boost_level_, int32 min_channel_chat_boost_level_)
  : id_(id_)
  , light_theme_colors_(std::move(light_theme_colors_))
  , dark_theme_colors_(std::move(dark_theme_colors_))
  , min_supergroup_chat_boost_level_(min_supergroup_chat_boost_level_)
  , min_channel_chat_boost_level_(min_channel_chat_boost_level_)
{}

const std::int32_t profileAccentColor::ID;

void profileAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileAccentColor");
    s.store_field("id", id_);
    s.store_object_field("light_theme_colors", static_cast<const BaseObject *>(light_theme_colors_.get()));
    s.store_object_field("dark_theme_colors", static_cast<const BaseObject *>(dark_theme_colors_.get()));
    s.store_field("min_supergroup_chat_boost_level", min_supergroup_chat_boost_level_);
    s.store_field("min_channel_chat_boost_level", min_channel_chat_boost_level_);
    s.store_class_end();
  }
}

proxy::proxy()
  : server_()
  , port_()
  , type_()
{}

proxy::proxy(string const &server_, int32 port_, object_ptr<ProxyType> &&type_)
  : server_(server_)
  , port_(port_)
  , type_(std::move(type_))
{}

const std::int32_t proxy::ID;

void proxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxy");
    s.store_field("server", server_);
    s.store_field("port", port_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

publicChatTypeHasUsername::publicChatTypeHasUsername() {
}

const std::int32_t publicChatTypeHasUsername::ID;

void publicChatTypeHasUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicChatTypeHasUsername");
    s.store_class_end();
  }
}

publicChatTypeIsLocationBased::publicChatTypeIsLocationBased() {
}

const std::int32_t publicChatTypeIsLocationBased::ID;

void publicChatTypeIsLocationBased::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicChatTypeIsLocationBased");
    s.store_class_end();
  }
}

pushReceiverId::pushReceiverId()
  : id_()
{}

pushReceiverId::pushReceiverId(int64 id_)
  : id_(id_)
{}

const std::int32_t pushReceiverId::ID;

void pushReceiverId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushReceiverId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

receivedGift::receivedGift()
  : received_gift_id_()
  , sender_id_()
  , text_()
  , unique_gift_number_()
  , is_private_()
  , is_saved_()
  , is_pinned_()
  , can_be_upgraded_()
  , can_be_transferred_()
  , can_be_deleted_()
  , was_refunded_()
  , date_()
  , gift_()
  , collection_ids_()
  , sell_star_count_()
  , prepaid_upgrade_star_count_()
  , is_upgrade_separate_()
  , transfer_star_count_()
  , drop_original_details_star_count_()
  , next_transfer_date_()
  , next_resale_date_()
  , export_date_()
  , prepaid_upgrade_hash_()
  , craft_date_()
{}

receivedGift::receivedGift(string const &received_gift_id_, object_ptr<MessageSender> &&sender_id_, object_ptr<formattedText> &&text_, int32 unique_gift_number_, bool is_private_, bool is_saved_, bool is_pinned_, bool can_be_upgraded_, bool can_be_transferred_, bool can_be_deleted_, bool was_refunded_, int32 date_, object_ptr<SentGift> &&gift_, array<int32> &&collection_ids_, int53 sell_star_count_, int53 prepaid_upgrade_star_count_, bool is_upgrade_separate_, int53 transfer_star_count_, int53 drop_original_details_star_count_, int32 next_transfer_date_, int32 next_resale_date_, int32 export_date_, string const &prepaid_upgrade_hash_, int32 craft_date_)
  : received_gift_id_(received_gift_id_)
  , sender_id_(std::move(sender_id_))
  , text_(std::move(text_))
  , unique_gift_number_(unique_gift_number_)
  , is_private_(is_private_)
  , is_saved_(is_saved_)
  , is_pinned_(is_pinned_)
  , can_be_upgraded_(can_be_upgraded_)
  , can_be_transferred_(can_be_transferred_)
  , can_be_deleted_(can_be_deleted_)
  , was_refunded_(was_refunded_)
  , date_(date_)
  , gift_(std::move(gift_))
  , collection_ids_(std::move(collection_ids_))
  , sell_star_count_(sell_star_count_)
  , prepaid_upgrade_star_count_(prepaid_upgrade_star_count_)
  , is_upgrade_separate_(is_upgrade_separate_)
  , transfer_star_count_(transfer_star_count_)
  , drop_original_details_star_count_(drop_original_details_star_count_)
  , next_transfer_date_(next_transfer_date_)
  , next_resale_date_(next_resale_date_)
  , export_date_(export_date_)
  , prepaid_upgrade_hash_(prepaid_upgrade_hash_)
  , craft_date_(craft_date_)
{}

const std::int32_t receivedGift::ID;

void receivedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "receivedGift");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("unique_gift_number", unique_gift_number_);
    s.store_field("is_private", is_private_);
    s.store_field("is_saved", is_saved_);
    s.store_field("is_pinned", is_pinned_);
    s.store_field("can_be_upgraded", can_be_upgraded_);
    s.store_field("can_be_transferred", can_be_transferred_);
    s.store_field("can_be_deleted", can_be_deleted_);
    s.store_field("was_refunded", was_refunded_);
    s.store_field("date", date_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    { s.store_vector_begin("collection_ids", collection_ids_.size()); for (const auto &_value : collection_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("sell_star_count", sell_star_count_);
    s.store_field("prepaid_upgrade_star_count", prepaid_upgrade_star_count_);
    s.store_field("is_upgrade_separate", is_upgrade_separate_);
    s.store_field("transfer_star_count", transfer_star_count_);
    s.store_field("drop_original_details_star_count", drop_original_details_star_count_);
    s.store_field("next_transfer_date", next_transfer_date_);
    s.store_field("next_resale_date", next_resale_date_);
    s.store_field("export_date", export_date_);
    s.store_field("prepaid_upgrade_hash", prepaid_upgrade_hash_);
    s.store_field("craft_date", craft_date_);
    s.store_class_end();
  }
}

seconds::seconds()
  : seconds_()
{}

seconds::seconds(double seconds_)
  : seconds_(seconds_)
{}

const std::int32_t seconds::ID;

void seconds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "seconds");
    s.store_field("seconds", seconds_);
    s.store_class_end();
  }
}

secretChatStatePending::secretChatStatePending() {
}

const std::int32_t secretChatStatePending::ID;

void secretChatStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChatStatePending");
    s.store_class_end();
  }
}

secretChatStateReady::secretChatStateReady() {
}

const std::int32_t secretChatStateReady::ID;

void secretChatStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChatStateReady");
    s.store_class_end();
  }
}

secretChatStateClosed::secretChatStateClosed() {
}

const std::int32_t secretChatStateClosed::ID;

void secretChatStateClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChatStateClosed");
    s.store_class_end();
  }
}

sentGiftRegular::sentGiftRegular()
  : gift_()
{}

sentGiftRegular::sentGiftRegular(object_ptr<gift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t sentGiftRegular::ID;

void sentGiftRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sentGiftRegular");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

sentGiftUpgraded::sentGiftUpgraded()
  : gift_()
{}

sentGiftUpgraded::sentGiftUpgraded(object_ptr<upgradedGift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t sentGiftUpgraded::ID;

void sentGiftUpgraded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sentGiftUpgraded");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

sessionTypeDevice::sessionTypeDevice()
  : session_id_()
{}

sessionTypeDevice::sessionTypeDevice(int64 session_id_)
  : session_id_(session_id_)
{}

const std::int32_t sessionTypeDevice::ID;

void sessionTypeDevice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeDevice");
    s.store_field("session_id", session_id_);
    s.store_class_end();
  }
}

sessionTypeConnectedBot::sessionTypeConnectedBot()
  : bot_user_id_()
{}

sessionTypeConnectedBot::sessionTypeConnectedBot(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t sessionTypeConnectedBot::ID;

void sessionTypeConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeConnectedBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

sessions::sessions()
  : sessions_()
  , inactive_session_ttl_days_()
{}

sessions::sessions(array<object_ptr<session>> &&sessions_, int32 inactive_session_ttl_days_)
  : sessions_(std::move(sessions_))
  , inactive_session_ttl_days_(inactive_session_ttl_days_)
{}

const std::int32_t sessions::ID;

void sessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessions");
    { s.store_vector_begin("sessions", sessions_.size()); for (const auto &_value : sessions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("inactive_session_ttl_days", inactive_session_ttl_days_);
    s.store_class_end();
  }
}

stakeDiceState::stakeDiceState()
  : state_hash_()
  , stake_gram_amount_()
  , suggested_stake_gram_amounts_()
  , current_streak_()
  , prize_per_mille_()
  , streak_prize_per_mille_()
{}

stakeDiceState::stakeDiceState(string const &state_hash_, int53 stake_gram_amount_, array<int53> &&suggested_stake_gram_amounts_, int32 current_streak_, array<int32> &&prize_per_mille_, int32 streak_prize_per_mille_)
  : state_hash_(state_hash_)
  , stake_gram_amount_(stake_gram_amount_)
  , suggested_stake_gram_amounts_(std::move(suggested_stake_gram_amounts_))
  , current_streak_(current_streak_)
  , prize_per_mille_(std::move(prize_per_mille_))
  , streak_prize_per_mille_(streak_prize_per_mille_)
{}

const std::int32_t stakeDiceState::ID;

void stakeDiceState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stakeDiceState");
    s.store_field("state_hash", state_hash_);
    s.store_field("stake_gram_amount", stake_gram_amount_);
    { s.store_vector_begin("suggested_stake_gram_amounts", suggested_stake_gram_amounts_.size()); for (const auto &_value : suggested_stake_gram_amounts_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("current_streak", current_streak_);
    { s.store_vector_begin("prize_per_mille", prize_per_mille_.size()); for (const auto &_value : prize_per_mille_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("streak_prize_per_mille", streak_prize_per_mille_);
    s.store_class_end();
  }
}

starCount::starCount()
  : star_count_()
{}

starCount::starCount(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t starCount::ID;

void starCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starCount");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

sticker::sticker()
  : id_()
  , set_id_()
  , width_()
  , height_()
  , emoji_()
  , format_()
  , full_type_()
  , thumbnail_()
  , sticker_()
{}

sticker::sticker(int64 id_, int64 set_id_, int32 width_, int32 height_, string const &emoji_, object_ptr<StickerFormat> &&format_, object_ptr<StickerFullType> &&full_type_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&sticker_)
  : id_(id_)
  , set_id_(set_id_)
  , width_(width_)
  , height_(height_)
  , emoji_(emoji_)
  , format_(std::move(format_))
  , full_type_(std::move(full_type_))
  , thumbnail_(std::move(thumbnail_))
  , sticker_(std::move(sticker_))
{}

const std::int32_t sticker::ID;

void sticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sticker");
    s.store_field("id", id_);
    s.store_field("set_id", set_id_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("emoji", emoji_);
    s.store_object_field("format", static_cast<const BaseObject *>(format_.get()));
    s.store_object_field("full_type", static_cast<const BaseObject *>(full_type_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

storageStatisticsFast::storageStatisticsFast()
  : files_size_()
  , file_count_()
  , database_size_()
  , language_pack_database_size_()
  , log_size_()
{}

storageStatisticsFast::storageStatisticsFast(int53 files_size_, int32 file_count_, int53 database_size_, int53 language_pack_database_size_, int53 log_size_)
  : files_size_(files_size_)
  , file_count_(file_count_)
  , database_size_(database_size_)
  , language_pack_database_size_(language_pack_database_size_)
  , log_size_(log_size_)
{}

const std::int32_t storageStatisticsFast::ID;

void storageStatisticsFast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatisticsFast");
    s.store_field("files_size", files_size_);
    s.store_field("file_count", file_count_);
    s.store_field("database_size", database_size_);
    s.store_field("language_pack_database_size", language_pack_database_size_);
    s.store_field("log_size", log_size_);
    s.store_class_end();
  }
}

storyAlbum::storyAlbum()
  : id_()
  , name_()
  , photo_icon_()
  , video_icon_()
{}

storyAlbum::storyAlbum(int32 id_, string const &name_, object_ptr<photo> &&photo_icon_, object_ptr<video> &&video_icon_)
  : id_(id_)
  , name_(name_)
  , photo_icon_(std::move(photo_icon_))
  , video_icon_(std::move(video_icon_))
{}

const std::int32_t storyAlbum::ID;

void storyAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAlbum");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_object_field("photo_icon", static_cast<const BaseObject *>(photo_icon_.get()));
    s.store_object_field("video_icon", static_cast<const BaseObject *>(video_icon_.get()));
    s.store_class_end();
  }
}

storyOriginPublicStory::storyOriginPublicStory()
  : chat_id_()
  , story_id_()
{}

storyOriginPublicStory::storyOriginPublicStory(int53 chat_id_, int32 story_id_)
  : chat_id_(chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t storyOriginPublicStory::ID;

void storyOriginPublicStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyOriginPublicStory");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

storyOriginHiddenUser::storyOriginHiddenUser()
  : poster_name_()
{}

storyOriginHiddenUser::storyOriginHiddenUser(string const &poster_name_)
  : poster_name_(poster_name_)
{}

const std::int32_t storyOriginHiddenUser::ID;

void storyOriginHiddenUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyOriginHiddenUser");
    s.store_field("poster_name", poster_name_);
    s.store_class_end();
  }
}

tMeUrlTypeUser::tMeUrlTypeUser()
  : user_id_()
{}

tMeUrlTypeUser::tMeUrlTypeUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t tMeUrlTypeUser::ID;

void tMeUrlTypeUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

tMeUrlTypeSupergroup::tMeUrlTypeSupergroup()
  : supergroup_id_()
{}

tMeUrlTypeSupergroup::tMeUrlTypeSupergroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t tMeUrlTypeSupergroup::ID;

void tMeUrlTypeSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeSupergroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

tMeUrlTypeChatInvite::tMeUrlTypeChatInvite()
  : info_()
{}

tMeUrlTypeChatInvite::tMeUrlTypeChatInvite(object_ptr<chatInviteLinkInfo> &&info_)
  : info_(std::move(info_))
{}

const std::int32_t tMeUrlTypeChatInvite::ID;

void tMeUrlTypeChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeChatInvite");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

tMeUrlTypeStickerSet::tMeUrlTypeStickerSet()
  : sticker_set_id_()
{}

tMeUrlTypeStickerSet::tMeUrlTypeStickerSet(int64 sticker_set_id_)
  : sticker_set_id_(sticker_set_id_)
{}

const std::int32_t tMeUrlTypeStickerSet::ID;

void tMeUrlTypeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeStickerSet");
    s.store_field("sticker_set_id", sticker_set_id_);
    s.store_class_end();
  }
}

testVectorStringObject::testVectorStringObject()
  : value_()
{}

testVectorStringObject::testVectorStringObject(array<object_ptr<testString>> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorStringObject::ID;

void testVectorStringObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorStringObject");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

tonTransactions::tonTransactions()
  : gram_amount_()
  , transactions_()
  , next_offset_()
{}

tonTransactions::tonTransactions(int53 gram_amount_, array<object_ptr<tonTransaction>> &&transactions_, string const &next_offset_)
  : gram_amount_(gram_amount_)
  , transactions_(std::move(transactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t tonTransactions::ID;

void tonTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactions");
    s.store_field("gram_amount", gram_amount_);
    { s.store_vector_begin("transactions", transactions_.size()); for (const auto &_value : transactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

tonWalletTransaction::tonWalletTransaction()
  : id_()
  , peer_address_()
  , peer_user_id_()
  , peer_domain_()
  , date_()
  , fee_amount_()
  , state_()
  , type_()
{}

tonWalletTransaction::tonWalletTransaction(string const &id_, string const &peer_address_, int53 peer_user_id_, string const &peer_domain_, int32 date_, int64 fee_amount_, object_ptr<TonWalletTransactionState> &&state_, object_ptr<TonWalletTransactionType> &&type_)
  : id_(id_)
  , peer_address_(peer_address_)
  , peer_user_id_(peer_user_id_)
  , peer_domain_(peer_domain_)
  , date_(date_)
  , fee_amount_(fee_amount_)
  , state_(std::move(state_))
  , type_(std::move(type_))
{}

const std::int32_t tonWalletTransaction::ID;

void tonWalletTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonWalletTransaction");
    s.store_field("id", id_);
    s.store_field("peer_address", peer_address_);
    s.store_field("peer_user_id", peer_user_id_);
    s.store_field("peer_domain", peer_domain_);
    s.store_field("date", date_);
    s.store_field("fee_amount", fee_amount_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

upgradedGift::upgradedGift()
  : id_()
  , regular_gift_id_()
  , publisher_chat_id_()
  , title_()
  , name_()
  , number_()
  , total_upgraded_count_()
  , max_upgraded_count_()
  , is_burned_()
  , is_crafted_()
  , is_premium_()
  , is_theme_available_()
  , used_theme_chat_id_()
  , host_id_()
  , owner_id_()
  , owner_address_()
  , owner_name_()
  , gift_address_()
  , can_be_ton_wallet_card_background_()
  , model_()
  , symbol_()
  , backdrop_()
  , original_details_()
  , colors_()
  , resale_parameters_()
  , can_send_purchase_offer_()
  , craft_probability_per_mille_()
  , value_currency_()
  , value_amount_()
  , value_usd_amount_()
{}

upgradedGift::upgradedGift(int64 id_, int64 regular_gift_id_, int53 publisher_chat_id_, string const &title_, string const &name_, int32 number_, int32 total_upgraded_count_, int32 max_upgraded_count_, bool is_burned_, bool is_crafted_, bool is_premium_, bool is_theme_available_, int53 used_theme_chat_id_, object_ptr<MessageSender> &&host_id_, object_ptr<MessageSender> &&owner_id_, string const &owner_address_, string const &owner_name_, string const &gift_address_, bool can_be_ton_wallet_card_background_, object_ptr<upgradedGiftModel> &&model_, object_ptr<upgradedGiftSymbol> &&symbol_, object_ptr<upgradedGiftBackdrop> &&backdrop_, object_ptr<upgradedGiftOriginalDetails> &&original_details_, object_ptr<upgradedGiftColors> &&colors_, object_ptr<giftResaleParameters> &&resale_parameters_, bool can_send_purchase_offer_, int32 craft_probability_per_mille_, string const &value_currency_, int53 value_amount_, int53 value_usd_amount_)
  : id_(id_)
  , regular_gift_id_(regular_gift_id_)
  , publisher_chat_id_(publisher_chat_id_)
  , title_(title_)
  , name_(name_)
  , number_(number_)
  , total_upgraded_count_(total_upgraded_count_)
  , max_upgraded_count_(max_upgraded_count_)
  , is_burned_(is_burned_)
  , is_crafted_(is_crafted_)
  , is_premium_(is_premium_)
  , is_theme_available_(is_theme_available_)
  , used_theme_chat_id_(used_theme_chat_id_)
  , host_id_(std::move(host_id_))
  , owner_id_(std::move(owner_id_))
  , owner_address_(owner_address_)
  , owner_name_(owner_name_)
  , gift_address_(gift_address_)
  , can_be_ton_wallet_card_background_(can_be_ton_wallet_card_background_)
  , model_(std::move(model_))
  , symbol_(std::move(symbol_))
  , backdrop_(std::move(backdrop_))
  , original_details_(std::move(original_details_))
  , colors_(std::move(colors_))
  , resale_parameters_(std::move(resale_parameters_))
  , can_send_purchase_offer_(can_send_purchase_offer_)
  , craft_probability_per_mille_(craft_probability_per_mille_)
  , value_currency_(value_currency_)
  , value_amount_(value_amount_)
  , value_usd_amount_(value_usd_amount_)
{}

const std::int32_t upgradedGift::ID;

void upgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGift");
    s.store_field("id", id_);
    s.store_field("regular_gift_id", regular_gift_id_);
    s.store_field("publisher_chat_id", publisher_chat_id_);
    s.store_field("title", title_);
    s.store_field("name", name_);
    s.store_field("number", number_);
    s.store_field("total_upgraded_count", total_upgraded_count_);
    s.store_field("max_upgraded_count", max_upgraded_count_);
    s.store_field("is_burned", is_burned_);
    s.store_field("is_crafted", is_crafted_);
    s.store_field("is_premium", is_premium_);
    s.store_field("is_theme_available", is_theme_available_);
    s.store_field("used_theme_chat_id", used_theme_chat_id_);
    s.store_object_field("host_id", static_cast<const BaseObject *>(host_id_.get()));
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("owner_address", owner_address_);
    s.store_field("owner_name", owner_name_);
    s.store_field("gift_address", gift_address_);
    s.store_field("can_be_ton_wallet_card_background", can_be_ton_wallet_card_background_);
    s.store_object_field("model", static_cast<const BaseObject *>(model_.get()));
    s.store_object_field("symbol", static_cast<const BaseObject *>(symbol_.get()));
    s.store_object_field("backdrop", static_cast<const BaseObject *>(backdrop_.get()));
    s.store_object_field("original_details", static_cast<const BaseObject *>(original_details_.get()));
    s.store_object_field("colors", static_cast<const BaseObject *>(colors_.get()));
    s.store_object_field("resale_parameters", static_cast<const BaseObject *>(resale_parameters_.get()));
    s.store_field("can_send_purchase_offer", can_send_purchase_offer_);
    s.store_field("craft_probability_per_mille", craft_probability_per_mille_);
    s.store_field("value_currency", value_currency_);
    s.store_field("value_amount", value_amount_);
    s.store_field("value_usd_amount", value_usd_amount_);
    s.store_class_end();
  }
}

upgradedGiftCollectionNames::upgradedGiftCollectionNames()
  : names_()
{}

upgradedGiftCollectionNames::upgradedGiftCollectionNames(array<string> &&names_)
  : names_(std::move(names_))
{}

const std::int32_t upgradedGiftCollectionNames::ID;

void upgradedGiftCollectionNames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftCollectionNames");
    { s.store_vector_begin("names", names_.size()); for (const auto &_value : names_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

upgradedGiftColors::upgradedGiftColors()
  : id_()
  , model_custom_emoji_id_()
  , symbol_custom_emoji_id_()
  , light_theme_accent_color_()
  , light_theme_colors_()
  , dark_theme_accent_color_()
  , dark_theme_colors_()
{}

upgradedGiftColors::upgradedGiftColors(int64 id_, int64 model_custom_emoji_id_, int64 symbol_custom_emoji_id_, int32 light_theme_accent_color_, array<int32> &&light_theme_colors_, int32 dark_theme_accent_color_, array<int32> &&dark_theme_colors_)
  : id_(id_)
  , model_custom_emoji_id_(model_custom_emoji_id_)
  , symbol_custom_emoji_id_(symbol_custom_emoji_id_)
  , light_theme_accent_color_(light_theme_accent_color_)
  , light_theme_colors_(std::move(light_theme_colors_))
  , dark_theme_accent_color_(dark_theme_accent_color_)
  , dark_theme_colors_(std::move(dark_theme_colors_))
{}

const std::int32_t upgradedGiftColors::ID;

void upgradedGiftColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftColors");
    s.store_field("id", id_);
    s.store_field("model_custom_emoji_id", model_custom_emoji_id_);
    s.store_field("symbol_custom_emoji_id", symbol_custom_emoji_id_);
    s.store_field("light_theme_accent_color", light_theme_accent_color_);
    { s.store_vector_begin("light_theme_colors", light_theme_colors_.size()); for (const auto &_value : light_theme_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("dark_theme_accent_color", dark_theme_accent_color_);
    { s.store_vector_begin("dark_theme_colors", dark_theme_colors_.size()); for (const auto &_value : dark_theme_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

upgradedGiftSymbolCount::upgradedGiftSymbolCount()
  : symbol_()
  , total_count_()
{}

upgradedGiftSymbolCount::upgradedGiftSymbolCount(object_ptr<upgradedGiftSymbol> &&symbol_, int32 total_count_)
  : symbol_(std::move(symbol_))
  , total_count_(total_count_)
{}

const std::int32_t upgradedGiftSymbolCount::ID;

void upgradedGiftSymbolCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftSymbolCount");
    s.store_object_field("symbol", static_cast<const BaseObject *>(symbol_.get()));
    s.store_field("total_count", total_count_);
    s.store_class_end();
  }
}

voiceNote::voiceNote()
  : duration_()
  , waveform_()
  , mime_type_()
  , speech_recognition_result_()
  , voice_()
{}

voiceNote::voiceNote(int32 duration_, bytes const &waveform_, string const &mime_type_, object_ptr<SpeechRecognitionResult> &&speech_recognition_result_, object_ptr<file> &&voice_)
  : duration_(duration_)
  , waveform_(std::move(waveform_))
  , mime_type_(mime_type_)
  , speech_recognition_result_(std::move(speech_recognition_result_))
  , voice_(std::move(voice_))
{}

const std::int32_t voiceNote::ID;

void voiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "voiceNote");
    s.store_field("duration", duration_);
    s.store_bytes_field("waveform", waveform_);
    s.store_field("mime_type", mime_type_);
    s.store_object_field("speech_recognition_result", static_cast<const BaseObject *>(speech_recognition_result_.get()));
    s.store_object_field("voice", static_cast<const BaseObject *>(voice_.get()));
    s.store_class_end();
  }
}

webProxyCarrierErrorUnsupported::webProxyCarrierErrorUnsupported() {
}

const std::int32_t webProxyCarrierErrorUnsupported::ID;

void webProxyCarrierErrorUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webProxyCarrierErrorUnsupported");
    s.store_class_end();
  }
}

webProxyCarrierErrorPaused::webProxyCarrierErrorPaused() {
}

const std::int32_t webProxyCarrierErrorPaused::ID;

void webProxyCarrierErrorPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webProxyCarrierErrorPaused");
    s.store_class_end();
  }
}

webProxyCarrierErrorLoadFailed::webProxyCarrierErrorLoadFailed()
  : message_()
{}

webProxyCarrierErrorLoadFailed::webProxyCarrierErrorLoadFailed(string const &message_)
  : message_(message_)
{}

const std::int32_t webProxyCarrierErrorLoadFailed::ID;

void webProxyCarrierErrorLoadFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webProxyCarrierErrorLoadFailed");
    s.store_field("message", message_);
    s.store_class_end();
  }
}

webProxyCarrierErrorTerminated::webProxyCarrierErrorTerminated() {
}

const std::int32_t webProxyCarrierErrorTerminated::ID;

void webProxyCarrierErrorTerminated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webProxyCarrierErrorTerminated");
    s.store_class_end();
  }
}

webProxyCarrierErrorRefused::webProxyCarrierErrorRefused() {
}

const std::int32_t webProxyCarrierErrorRefused::ID;

void webProxyCarrierErrorRefused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webProxyCarrierErrorRefused");
    s.store_class_end();
  }
}

widgetQueryWallet::widgetQueryWallet()
  : address_()
  , gram_amount_()
  , public_key_()
  , state_init_()
{}

widgetQueryWallet::widgetQueryWallet(string const &address_, int64 gram_amount_, bytes const &public_key_, bytes const &state_init_)
  : address_(address_)
  , gram_amount_(gram_amount_)
  , public_key_(std::move(public_key_))
  , state_init_(std::move(state_init_))
{}

const std::int32_t widgetQueryWallet::ID;

void widgetQueryWallet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "widgetQueryWallet");
    s.store_field("address", address_);
    s.store_field("gram_amount", gram_amount_);
    s.store_bytes_field("public_key", public_key_);
    s.store_bytes_field("state_init", state_init_);
    s.store_class_end();
  }
}

addBotMediaPreview::addBotMediaPreview()
  : bot_user_id_()
  , language_code_()
  , content_()
{}

addBotMediaPreview::addBotMediaPreview(int53 bot_user_id_, string const &language_code_, object_ptr<InputStoryContent> &&content_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , content_(std::move(content_))
{}

const std::int32_t addBotMediaPreview::ID;

void addBotMediaPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addBotMediaPreview");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

addCommunityChat::addCommunityChat()
  : community_id_()
  , chat_id_()
  , is_hidden_()
{}

addCommunityChat::addCommunityChat(int53 community_id_, int53 chat_id_, bool is_hidden_)
  : community_id_(community_id_)
  , chat_id_(chat_id_)
  , is_hidden_(is_hidden_)
{}

const std::int32_t addCommunityChat::ID;

void addCommunityChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addCommunityChat");
    s.store_field("community_id", community_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("is_hidden", is_hidden_);
    s.store_class_end();
  }
}

addCustomServerLanguagePack::addCustomServerLanguagePack()
  : language_pack_id_()
{}

addCustomServerLanguagePack::addCustomServerLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t addCustomServerLanguagePack::ID;

void addCustomServerLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addCustomServerLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

addFavoriteSticker::addFavoriteSticker()
  : sticker_()
{}

addFavoriteSticker::addFavoriteSticker(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t addFavoriteSticker::ID;

void addFavoriteSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addFavoriteSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

addGiftCollectionGifts::addGiftCollectionGifts()
  : owner_id_()
  , collection_id_()
  , received_gift_ids_()
{}

addGiftCollectionGifts::addGiftCollectionGifts(object_ptr<MessageSender> &&owner_id_, int32 collection_id_, array<string> &&received_gift_ids_)
  : owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
  , received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t addGiftCollectionGifts::ID;

void addGiftCollectionGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addGiftCollectionGifts");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

addSavedAnimation::addSavedAnimation()
  : animation_()
{}

addSavedAnimation::addSavedAnimation(object_ptr<InputFile> &&animation_)
  : animation_(std::move(animation_))
{}

const std::int32_t addSavedAnimation::ID;

void addSavedAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addSavedAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

applyUnpaidMessagesToken::applyUnpaidMessagesToken()
  : user_id_()
  , token_()
{}

applyUnpaidMessagesToken::applyUnpaidMessagesToken(int53 user_id_, string const &token_)
  : user_id_(user_id_)
  , token_(token_)
{}

const std::int32_t applyUnpaidMessagesToken::ID;

void applyUnpaidMessagesToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "applyUnpaidMessagesToken");
    s.store_field("user_id", user_id_);
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

assignStoreTransaction::assignStoreTransaction()
  : transaction_()
  , purpose_()
{}

assignStoreTransaction::assignStoreTransaction(object_ptr<StoreTransaction> &&transaction_, object_ptr<StorePaymentPurpose> &&purpose_)
  : transaction_(std::move(transaction_))
  , purpose_(std::move(purpose_))
{}

const std::int32_t assignStoreTransaction::ID;

void assignStoreTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "assignStoreTransaction");
    s.store_object_field("transaction", static_cast<const BaseObject *>(transaction_.get()));
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

changeWebBrowserSettings::changeWebBrowserSettings()
  : open_external_browser_()
  , display_close_button_()
{}

changeWebBrowserSettings::changeWebBrowserSettings(bool open_external_browser_, bool display_close_button_)
  : open_external_browser_(open_external_browser_)
  , display_close_button_(display_close_button_)
{}

const std::int32_t changeWebBrowserSettings::ID;

void changeWebBrowserSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "changeWebBrowserSettings");
    s.store_field("open_external_browser", open_external_browser_);
    s.store_field("display_close_button", display_close_button_);
    s.store_class_end();
  }
}

clearAutosaveSettingsExceptions::clearAutosaveSettingsExceptions() {
}

const std::int32_t clearAutosaveSettingsExceptions::ID;

void clearAutosaveSettingsExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearAutosaveSettingsExceptions");
    s.store_class_end();
  }
}

clearImportedContacts::clearImportedContacts() {
}

const std::int32_t clearImportedContacts::ID;

void clearImportedContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearImportedContacts");
    s.store_class_end();
  }
}

clearRecentStickers::clearRecentStickers()
  : is_attached_()
{}

clearRecentStickers::clearRecentStickers(bool is_attached_)
  : is_attached_(is_attached_)
{}

const std::int32_t clearRecentStickers::ID;

void clearRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearRecentStickers");
    s.store_field("is_attached", is_attached_);
    s.store_class_end();
  }
}

clearRecentlyFoundChats::clearRecentlyFoundChats() {
}

const std::int32_t clearRecentlyFoundChats::ID;

void clearRecentlyFoundChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearRecentlyFoundChats");
    s.store_class_end();
  }
}

clickPremiumSubscriptionButton::clickPremiumSubscriptionButton() {
}

const std::int32_t clickPremiumSubscriptionButton::ID;

void clickPremiumSubscriptionButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clickPremiumSubscriptionButton");
    s.store_class_end();
  }
}

createBot::createBot()
  : manager_bot_user_id_()
  , name_()
  , username_()
  , via_link_()
{}

createBot::createBot(int53 manager_bot_user_id_, string const &name_, string const &username_, bool via_link_)
  : manager_bot_user_id_(manager_bot_user_id_)
  , name_(name_)
  , username_(username_)
  , via_link_(via_link_)
{}

const std::int32_t createBot::ID;

void createBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createBot");
    s.store_field("manager_bot_user_id", manager_bot_user_id_);
    s.store_field("name", name_);
    s.store_field("username", username_);
    s.store_field("via_link", via_link_);
    s.store_class_end();
  }
}

createChatFolderInviteLink::createChatFolderInviteLink()
  : chat_folder_id_()
  , name_()
  , chat_ids_()
{}

createChatFolderInviteLink::createChatFolderInviteLink(int32 chat_folder_id_, string const &name_, array<int53> &&chat_ids_)
  : chat_folder_id_(chat_folder_id_)
  , name_(name_)
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t createChatFolderInviteLink::ID;

void createChatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createChatFolderInviteLink");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_field("name", name_);
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

createNewStickerSet::createNewStickerSet()
  : user_id_()
  , title_()
  , name_()
  , sticker_type_()
  , needs_repainting_()
  , stickers_()
  , source_()
{}

createNewStickerSet::createNewStickerSet(int53 user_id_, string const &title_, string const &name_, object_ptr<StickerType> &&sticker_type_, bool needs_repainting_, array<object_ptr<newSticker>> &&stickers_, string const &source_)
  : user_id_(user_id_)
  , title_(title_)
  , name_(name_)
  , sticker_type_(std::move(sticker_type_))
  , needs_repainting_(needs_repainting_)
  , stickers_(std::move(stickers_))
  , source_(source_)
{}

const std::int32_t createNewStickerSet::ID;

void createNewStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewStickerSet");
    s.store_field("user_id", user_id_);
    s.store_field("title", title_);
    s.store_field("name", name_);
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("needs_repainting", needs_repainting_);
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("source", source_);
    s.store_class_end();
  }
}

deleteDirectMessagesChatTopicHistory::deleteDirectMessagesChatTopicHistory()
  : chat_id_()
  , topic_id_()
{}

deleteDirectMessagesChatTopicHistory::deleteDirectMessagesChatTopicHistory(int53 chat_id_, int53 topic_id_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
{}

const std::int32_t deleteDirectMessagesChatTopicHistory::ID;

void deleteDirectMessagesChatTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteDirectMessagesChatTopicHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

deleteSavedMessagesTopicHistory::deleteSavedMessagesTopicHistory()
  : saved_messages_topic_id_()
{}

deleteSavedMessagesTopicHistory::deleteSavedMessagesTopicHistory(int53 saved_messages_topic_id_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
{}

const std::int32_t deleteSavedMessagesTopicHistory::ID;

void deleteSavedMessagesTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteSavedMessagesTopicHistory");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_class_end();
  }
}

discardCall::discardCall()
  : call_id_()
  , is_disconnected_()
  , invite_link_()
  , duration_()
  , is_video_()
  , connection_id_()
{}

discardCall::discardCall(int32 call_id_, bool is_disconnected_, string const &invite_link_, int32 duration_, bool is_video_, int64 connection_id_)
  : call_id_(call_id_)
  , is_disconnected_(is_disconnected_)
  , invite_link_(invite_link_)
  , duration_(duration_)
  , is_video_(is_video_)
  , connection_id_(connection_id_)
{}

const std::int32_t discardCall::ID;

void discardCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "discardCall");
    s.store_field("call_id", call_id_);
    s.store_field("is_disconnected", is_disconnected_);
    s.store_field("invite_link", invite_link_);
    s.store_field("duration", duration_);
    s.store_field("is_video", is_video_);
    s.store_field("connection_id", connection_id_);
    s.store_class_end();
  }
}

editBusinessStory::editBusinessStory()
  : story_poster_chat_id_()
  , story_id_()
  , content_()
  , areas_()
  , caption_()
  , privacy_settings_()
{}

editBusinessStory::editBusinessStory(int53 story_poster_chat_id_, int32 story_id_, object_ptr<InputStoryContent> &&content_, object_ptr<inputStoryAreas> &&areas_, object_ptr<formattedText> &&caption_, object_ptr<StoryPrivacySettings> &&privacy_settings_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , content_(std::move(content_))
  , areas_(std::move(areas_))
  , caption_(std::move(caption_))
  , privacy_settings_(std::move(privacy_settings_))
{}

const std::int32_t editBusinessStory::ID;

void editBusinessStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("areas", static_cast<const BaseObject *>(areas_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_object_field("privacy_settings", static_cast<const BaseObject *>(privacy_settings_.get()));
    s.store_class_end();
  }
}

editChatInviteLink::editChatInviteLink()
  : chat_id_()
  , invite_link_()
  , name_()
  , expiration_date_()
  , member_limit_()
  , creates_join_request_()
{}

editChatInviteLink::editChatInviteLink(int53 chat_id_, string const &invite_link_, string const &name_, int32 expiration_date_, int32 member_limit_, bool creates_join_request_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , name_(name_)
  , expiration_date_(expiration_date_)
  , member_limit_(member_limit_)
  , creates_join_request_(creates_join_request_)
{}

const std::int32_t editChatInviteLink::ID;

void editChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("member_limit", member_limit_);
    s.store_field("creates_join_request", creates_join_request_);
    s.store_class_end();
  }
}

editInlineMessageReplyMarkup::editInlineMessageReplyMarkup()
  : inline_message_id_()
  , reply_markup_()
{}

editInlineMessageReplyMarkup::editInlineMessageReplyMarkup(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t editInlineMessageReplyMarkup::ID;

void editInlineMessageReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageReplyMarkup");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

editQuickReplyMessage::editQuickReplyMessage()
  : shortcut_id_()
  , message_id_()
  , input_message_content_()
{}

editQuickReplyMessage::editQuickReplyMessage(int32 shortcut_id_, int53 message_id_, object_ptr<InputMessageContent> &&input_message_content_)
  : shortcut_id_(shortcut_id_)
  , message_id_(message_id_)
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editQuickReplyMessage::ID;

void editQuickReplyMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editQuickReplyMessage");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

getArchiveChatListSettings::getArchiveChatListSettings() {
}

const std::int32_t getArchiveChatListSettings::ID;

void getArchiveChatListSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getArchiveChatListSettings");
    s.store_class_end();
  }
}

getAvailableChatBoostSlots::getAvailableChatBoostSlots() {
}

const std::int32_t getAvailableChatBoostSlots::ID;

void getAvailableChatBoostSlots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAvailableChatBoostSlots");
    s.store_class_end();
  }
}

getBotInfoDescription::getBotInfoDescription()
  : bot_user_id_()
  , language_code_()
{}

getBotInfoDescription::getBotInfoDescription(int53 bot_user_id_, string const &language_code_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
{}

const std::int32_t getBotInfoDescription::ID;

void getBotInfoDescription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotInfoDescription");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getBusinessChatLinkInfo::getBusinessChatLinkInfo()
  : link_name_()
{}

getBusinessChatLinkInfo::getBusinessChatLinkInfo(string const &link_name_)
  : link_name_(link_name_)
{}

const std::int32_t getBusinessChatLinkInfo::ID;

void getBusinessChatLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessChatLinkInfo");
    s.store_field("link_name", link_name_);
    s.store_class_end();
  }
}

getChatAdministrators::getChatAdministrators()
  : chat_id_()
{}

getChatAdministrators::getChatAdministrators(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatAdministrators::ID;

void getChatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatAdministrators");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatBoostLink::getChatBoostLink()
  : chat_id_()
{}

getChatBoostLink::getChatBoostLink(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatBoostLink::ID;

void getChatBoostLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoostLink");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatBoostLinkInfo::getChatBoostLinkInfo()
  : url_()
{}

getChatBoostLinkInfo::getChatBoostLinkInfo(string const &url_)
  : url_(url_)
{}

const std::int32_t getChatBoostLinkInfo::ID;

void getChatBoostLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoostLinkInfo");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

getChatsToPostStories::getChatsToPostStories() {
}

const std::int32_t getChatsToPostStories::ID;

void getChatsToPostStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatsToPostStories");
    s.store_class_end();
  }
}

getCommunityAddChatRequests::getCommunityAddChatRequests()
  : community_id_()
  , offset_()
  , limit_()
{}

getCommunityAddChatRequests::getCommunityAddChatRequests(int53 community_id_, string const &offset_, int32 limit_)
  : community_id_(community_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getCommunityAddChatRequests::ID;

void getCommunityAddChatRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCommunityAddChatRequests");
    s.store_field("community_id", community_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getCommunityFullInfo::getCommunityFullInfo()
  : community_id_()
{}

getCommunityFullInfo::getCommunityFullInfo(int53 community_id_)
  : community_id_(community_id_)
{}

const std::int32_t getCommunityFullInfo::ID;

void getCommunityFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCommunityFullInfo");
    s.store_field("community_id", community_id_);
    s.store_class_end();
  }
}

getCountry::getCountry()
  : country_code_()
{}

getCountry::getCountry(string const &country_code_)
  : country_code_(country_code_)
{}

const std::int32_t getCountry::ID;

void getCountry::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCountry");
    s.store_field("country_code", country_code_);
    s.store_class_end();
  }
}

getDefaultBackgroundCustomEmojiStickers::getDefaultBackgroundCustomEmojiStickers() {
}

const std::int32_t getDefaultBackgroundCustomEmojiStickers::ID;

void getDefaultBackgroundCustomEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultBackgroundCustomEmojiStickers");
    s.store_class_end();
  }
}

getDefaultEmojiStatuses::getDefaultEmojiStatuses() {
}

const std::int32_t getDefaultEmojiStatuses::ID;

void getDefaultEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultEmojiStatuses");
    s.store_class_end();
  }
}

getDisallowedChatEmojiStatuses::getDisallowedChatEmojiStatuses() {
}

const std::int32_t getDisallowedChatEmojiStatuses::ID;

void getDisallowedChatEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDisallowedChatEmojiStatuses");
    s.store_class_end();
  }
}

getGiftAuctionAcquiredGifts::getGiftAuctionAcquiredGifts()
  : gift_id_()
{}

getGiftAuctionAcquiredGifts::getGiftAuctionAcquiredGifts(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t getGiftAuctionAcquiredGifts::ID;

void getGiftAuctionAcquiredGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftAuctionAcquiredGifts");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

getPasskeyParameters::getPasskeyParameters() {
}

const std::int32_t getPasskeyParameters::ID;

void getPasskeyParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPasskeyParameters");
    s.store_class_end();
  }
}

getPassportAuthorizationFormAvailableElements::getPassportAuthorizationFormAvailableElements()
  : authorization_form_id_()
  , password_()
{}

getPassportAuthorizationFormAvailableElements::getPassportAuthorizationFormAvailableElements(int32 authorization_form_id_, string const &password_)
  : authorization_form_id_(authorization_form_id_)
  , password_(password_)
{}

const std::int32_t getPassportAuthorizationFormAvailableElements::ID;

void getPassportAuthorizationFormAvailableElements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPassportAuthorizationFormAvailableElements");
    s.store_field("authorization_form_id", authorization_form_id_);
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

getPollVoters::getPollVoters()
  : chat_id_()
  , message_id_()
  , option_id_()
  , offset_()
  , limit_()
{}

getPollVoters::getPollVoters(int53 chat_id_, int53 message_id_, int32 option_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_id_(option_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getPollVoters::ID;

void getPollVoters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPollVoters");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("option_id", option_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getRecentEmojiStatuses::getRecentEmojiStatuses() {
}

const std::int32_t getRecentEmojiStatuses::ID;

void getRecentEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentEmojiStatuses");
    s.store_class_end();
  }
}

getRecentlyOpenedChats::getRecentlyOpenedChats()
  : limit_()
{}

getRecentlyOpenedChats::getRecentlyOpenedChats(int32 limit_)
  : limit_(limit_)
{}

const std::int32_t getRecentlyOpenedChats::ID;

void getRecentlyOpenedChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentlyOpenedChats");
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getRecommendedChats::getRecommendedChats() {
}

const std::int32_t getRecommendedChats::ID;

void getRecommendedChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecommendedChats");
    s.store_class_end();
  }
}

getScopeNotificationSettings::getScopeNotificationSettings()
  : scope_()
{}

getScopeNotificationSettings::getScopeNotificationSettings(object_ptr<NotificationSettingsScope> &&scope_)
  : scope_(std::move(scope_))
{}

const std::int32_t getScopeNotificationSettings::ID;

void getScopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getScopeNotificationSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_class_end();
  }
}

getSearchSponsoredChats::getSearchSponsoredChats()
  : query_()
{}

getSearchSponsoredChats::getSearchSponsoredChats(string const &query_)
  : query_(query_)
{}

const std::int32_t getSearchSponsoredChats::ID;

void getSearchSponsoredChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSearchSponsoredChats");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

getStarGiftPaymentOptions::getStarGiftPaymentOptions()
  : user_id_()
{}

getStarGiftPaymentOptions::getStarGiftPaymentOptions(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getStarGiftPaymentOptions::ID;

void getStarGiftPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarGiftPaymentOptions");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getStatisticalGraph::getStatisticalGraph()
  : chat_id_()
  , token_()
  , x_()
{}

getStatisticalGraph::getStatisticalGraph(int53 chat_id_, string const &token_, int53 x_)
  : chat_id_(chat_id_)
  , token_(token_)
  , x_(x_)
{}

const std::int32_t getStatisticalGraph::ID;

void getStatisticalGraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStatisticalGraph");
    s.store_field("chat_id", chat_id_);
    s.store_field("token", "[REDACTED]");
    s.store_field("x", x_);
    s.store_class_end();
  }
}

getStickerOutline::getStickerOutline()
  : sticker_file_id_()
  , for_animated_emoji_()
  , for_clicked_animated_emoji_message_()
{}

getStickerOutline::getStickerOutline(int32 sticker_file_id_, bool for_animated_emoji_, bool for_clicked_animated_emoji_message_)
  : sticker_file_id_(sticker_file_id_)
  , for_animated_emoji_(for_animated_emoji_)
  , for_clicked_animated_emoji_message_(for_clicked_animated_emoji_message_)
{}

const std::int32_t getStickerOutline::ID;

void getStickerOutline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerOutline");
    s.store_field("sticker_file_id", sticker_file_id_);
    s.store_field("for_animated_emoji", for_animated_emoji_);
    s.store_field("for_clicked_animated_emoji_message", for_clicked_animated_emoji_message_);
    s.store_class_end();
  }
}

getSuitableCommunityChats::getSuitableCommunityChats() {
}

const std::int32_t getSuitableCommunityChats::ID;

void getSuitableCommunityChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuitableCommunityChats");
    s.store_class_end();
  }
}

getSuitableDiscussionChats::getSuitableDiscussionChats() {
}

const std::int32_t getSuitableDiscussionChats::ID;

void getSuitableDiscussionChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuitableDiscussionChats");
    s.store_class_end();
  }
}

getSupergroupMembers::getSupergroupMembers()
  : supergroup_id_()
  , filter_()
  , offset_()
  , limit_()
{}

getSupergroupMembers::getSupergroupMembers(int53 supergroup_id_, object_ptr<SupergroupMembersFilter> &&filter_, int32 offset_, int32 limit_)
  : supergroup_id_(supergroup_id_)
  , filter_(std::move(filter_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getSupergroupMembers::ID;

void getSupergroupMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupergroupMembers");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getTonConnectSessionNextEventId::getTonConnectSessionNextEventId()
  : session_id_()
{}

getTonConnectSessionNextEventId::getTonConnectSessionNextEventId(int64 session_id_)
  : session_id_(session_id_)
{}

const std::int32_t getTonConnectSessionNextEventId::ID;

void getTonConnectSessionNextEventId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonConnectSessionNextEventId");
    s.store_field("session_id", session_id_);
    s.store_class_end();
  }
}

getTonWalletTransaction::getTonWalletTransaction()
  : transaction_id_()
{}

getTonWalletTransaction::getTonWalletTransaction(string const &transaction_id_)
  : transaction_id_(transaction_id_)
{}

const std::int32_t getTonWalletTransaction::ID;

void getTonWalletTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonWalletTransaction");
    s.store_field("transaction_id", transaction_id_);
    s.store_class_end();
  }
}

getVideoChatInviteLink::getVideoChatInviteLink()
  : group_call_id_()
  , can_self_unmute_()
{}

getVideoChatInviteLink::getVideoChatInviteLink(int32 group_call_id_, bool can_self_unmute_)
  : group_call_id_(group_call_id_)
  , can_self_unmute_(can_self_unmute_)
{}

const std::int32_t getVideoChatInviteLink::ID;

void getVideoChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getVideoChatInviteLink");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("can_self_unmute", can_self_unmute_);
    s.store_class_end();
  }
}

importMessages::importMessages()
  : chat_id_()
  , message_file_()
  , attached_files_()
{}

importMessages::importMessages(int53 chat_id_, object_ptr<InputFile> &&message_file_, array<object_ptr<InputFile>> &&attached_files_)
  : chat_id_(chat_id_)
  , message_file_(std::move(message_file_))
  , attached_files_(std::move(attached_files_))
{}

const std::int32_t importMessages::ID;

void importMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importMessages");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("message_file", static_cast<const BaseObject *>(message_file_.get()));
    { s.store_vector_begin("attached_files", attached_files_.size()); for (const auto &_value : attached_files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inviteGroupCallParticipant::inviteGroupCallParticipant()
  : group_call_id_()
  , user_id_()
  , is_video_()
{}

inviteGroupCallParticipant::inviteGroupCallParticipant(int32 group_call_id_, int53 user_id_, bool is_video_)
  : group_call_id_(group_call_id_)
  , user_id_(user_id_)
  , is_video_(is_video_)
{}

const std::int32_t inviteGroupCallParticipant::ID;

void inviteGroupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteGroupCallParticipant");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("user_id", user_id_);
    s.store_field("is_video", is_video_);
    s.store_class_end();
  }
}

inviteVideoChatParticipants::inviteVideoChatParticipants()
  : group_call_id_()
  , user_ids_()
{}

inviteVideoChatParticipants::inviteVideoChatParticipants(int32 group_call_id_, array<int53> &&user_ids_)
  : group_call_id_(group_call_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t inviteVideoChatParticipants::ID;

void inviteVideoChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteVideoChatParticipants");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

loadQuickReplyShortcuts::loadQuickReplyShortcuts() {
}

const std::int32_t loadQuickReplyShortcuts::ID;

void loadQuickReplyShortcuts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadQuickReplyShortcuts");
    s.store_class_end();
  }
}

openBotSimilarBot::openBotSimilarBot()
  : bot_user_id_()
  , opened_bot_user_id_()
{}

openBotSimilarBot::openBotSimilarBot(int53 bot_user_id_, int53 opened_bot_user_id_)
  : bot_user_id_(bot_user_id_)
  , opened_bot_user_id_(opened_bot_user_id_)
{}

const std::int32_t openBotSimilarBot::ID;

void openBotSimilarBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openBotSimilarBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("opened_bot_user_id", opened_bot_user_id_);
    s.store_class_end();
  }
}

pinChatMessage::pinChatMessage()
  : chat_id_()
  , message_id_()
  , disable_notification_()
  , only_for_self_()
{}

pinChatMessage::pinChatMessage(int53 chat_id_, int53 message_id_, bool disable_notification_, bool only_for_self_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , disable_notification_(disable_notification_)
  , only_for_self_(only_for_self_)
{}

const std::int32_t pinChatMessage::ID;

void pinChatMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pinChatMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("disable_notification", disable_notification_);
    s.store_field("only_for_self", only_for_self_);
    s.store_class_end();
  }
}

processGiftPurchaseOffer::processGiftPurchaseOffer()
  : message_id_()
  , accept_()
{}

processGiftPurchaseOffer::processGiftPurchaseOffer(int53 message_id_, bool accept_)
  : message_id_(message_id_)
  , accept_(accept_)
{}

const std::int32_t processGiftPurchaseOffer::ID;

void processGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processGiftPurchaseOffer");
    s.store_field("message_id", message_id_);
    s.store_field("accept", accept_);
    s.store_class_end();
  }
}

processWebProxyCarrierMessage::processWebProxyCarrierMessage()
  : carrier_id_()
  , message_()
{}

processWebProxyCarrierMessage::processWebProxyCarrierMessage(int32 carrier_id_, object_ptr<WebProxyCarrierMessage> &&message_)
  : carrier_id_(carrier_id_)
  , message_(std::move(message_))
{}

const std::int32_t processWebProxyCarrierMessage::ID;

void processWebProxyCarrierMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processWebProxyCarrierMessage");
    s.store_field("carrier_id", carrier_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

readAllChatMentions::readAllChatMentions()
  : chat_id_()
{}

readAllChatMentions::readAllChatMentions(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t readAllChatMentions::ID;

void readAllChatMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllChatMentions");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

readFilePart::readFilePart()
  : file_id_()
  , offset_()
  , count_()
{}

readFilePart::readFilePart(int32 file_id_, int53 offset_, int53 count_)
  : file_id_(file_id_)
  , offset_(offset_)
  , count_(count_)
{}

const std::int32_t readFilePart::ID;

void readFilePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readFilePart");
    s.store_field("file_id", file_id_);
    s.store_field("offset", offset_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

removeProxy::removeProxy()
  : proxy_id_()
{}

removeProxy::removeProxy(int32 proxy_id_)
  : proxy_id_(proxy_id_)
{}

const std::int32_t removeProxy::ID;

void removeProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeProxy");
    s.store_field("proxy_id", proxy_id_);
    s.store_class_end();
  }
}

removeSavedNotificationSound::removeSavedNotificationSound()
  : notification_sound_id_()
{}

removeSavedNotificationSound::removeSavedNotificationSound(int64 notification_sound_id_)
  : notification_sound_id_(notification_sound_id_)
{}

const std::int32_t removeSavedNotificationSound::ID;

void removeSavedNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeSavedNotificationSound");
    s.store_field("notification_sound_id", notification_sound_id_);
    s.store_class_end();
  }
}

reorderInstalledStickerSets::reorderInstalledStickerSets()
  : sticker_type_()
  , sticker_set_ids_()
{}

reorderInstalledStickerSets::reorderInstalledStickerSets(object_ptr<StickerType> &&sticker_type_, array<int64> &&sticker_set_ids_)
  : sticker_type_(std::move(sticker_type_))
  , sticker_set_ids_(std::move(sticker_set_ids_))
{}

const std::int32_t reorderInstalledStickerSets::ID;

void reorderInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderInstalledStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    { s.store_vector_begin("sticker_set_ids", sticker_set_ids_.size()); for (const auto &_value : sticker_set_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reorderStoryAlbums::reorderStoryAlbums()
  : chat_id_()
  , story_album_ids_()
{}

reorderStoryAlbums::reorderStoryAlbums(int53 chat_id_, array<int32> &&story_album_ids_)
  : chat_id_(chat_id_)
  , story_album_ids_(std::move(story_album_ids_))
{}

const std::int32_t reorderStoryAlbums::ID;

void reorderStoryAlbums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderStoryAlbums");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("story_album_ids", story_album_ids_.size()); for (const auto &_value : story_album_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reorderSupergroupActiveUsernames::reorderSupergroupActiveUsernames()
  : supergroup_id_()
  , usernames_()
{}

reorderSupergroupActiveUsernames::reorderSupergroupActiveUsernames(int53 supergroup_id_, array<string> &&usernames_)
  : supergroup_id_(supergroup_id_)
  , usernames_(std::move(usernames_))
{}

const std::int32_t reorderSupergroupActiveUsernames::ID;

void reorderSupergroupActiveUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderSupergroupActiveUsernames");
    s.store_field("supergroup_id", supergroup_id_);
    { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

resendRecoveryEmailAddressCode::resendRecoveryEmailAddressCode() {
}

const std::int32_t resendRecoveryEmailAddressCode::ID;

void resendRecoveryEmailAddressCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendRecoveryEmailAddressCode");
    s.store_class_end();
  }
}

searchBackground::searchBackground()
  : name_()
{}

searchBackground::searchBackground(string const &name_)
  : name_(name_)
{}

const std::int32_t searchBackground::ID;

void searchBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchBackground");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

searchMessages::searchMessages()
  : chat_list_()
  , query_()
  , offset_()
  , limit_()
  , filter_()
  , chat_type_filter_()
  , min_date_()
  , max_date_()
{}

searchMessages::searchMessages(object_ptr<ChatList> &&chat_list_, string const &query_, string const &offset_, int32 limit_, object_ptr<SearchMessagesFilter> &&filter_, object_ptr<SearchMessagesChatTypeFilter> &&chat_type_filter_, int32 min_date_, int32 max_date_)
  : chat_list_(std::move(chat_list_))
  , query_(query_)
  , offset_(offset_)
  , limit_(limit_)
  , filter_(std::move(filter_))
  , chat_type_filter_(std::move(chat_type_filter_))
  , min_date_(min_date_)
  , max_date_(max_date_)
{}

const std::int32_t searchMessages::ID;

void searchMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessages");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_object_field("chat_type_filter", static_cast<const BaseObject *>(chat_type_filter_.get()));
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_class_end();
  }
}

searchQuote::searchQuote()
  : text_()
  , quote_()
  , quote_position_()
{}

searchQuote::searchQuote(object_ptr<formattedText> &&text_, object_ptr<formattedText> &&quote_, int32 quote_position_)
  : text_(std::move(text_))
  , quote_(std::move(quote_))
  , quote_position_(quote_position_)
{}

const std::int32_t searchQuote::ID;

void searchQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("quote", static_cast<const BaseObject *>(quote_.get()));
    s.store_field("quote_position", quote_position_);
    s.store_class_end();
  }
}

searchStickers::searchStickers()
  : sticker_type_()
  , emojis_()
  , query_()
  , input_language_codes_()
  , offset_()
  , limit_()
{}

searchStickers::searchStickers(object_ptr<StickerType> &&sticker_type_, string const &emojis_, string const &query_, array<string> &&input_language_codes_, int32 offset_, int32 limit_)
  : sticker_type_(std::move(sticker_type_))
  , emojis_(emojis_)
  , query_(query_)
  , input_language_codes_(std::move(input_language_codes_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchStickers::ID;

void searchStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchStickers");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("emojis", emojis_);
    s.store_field("query", query_);
    { s.store_vector_begin("input_language_codes", input_language_codes_.size()); for (const auto &_value : input_language_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

sendEmailAddressVerificationCode::sendEmailAddressVerificationCode()
  : email_address_()
{}

sendEmailAddressVerificationCode::sendEmailAddressVerificationCode(string const &email_address_)
  : email_address_(email_address_)
{}

const std::int32_t sendEmailAddressVerificationCode::ID;

void sendEmailAddressVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendEmailAddressVerificationCode");
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

sendTonWalletTransfer::sendTonWalletTransfer()
  : user_id_()
  , address_()
  , amount_()
  , comment_()
  , is_comment_encrypted_()
  , sending_id_()
  , regular_transfer_data_()
  , gasless_transfer_data_()
{}

sendTonWalletTransfer::sendTonWalletTransfer(int53 user_id_, string const &address_, int64 amount_, string const &comment_, bool is_comment_encrypted_, int32 sending_id_, bytes const &regular_transfer_data_, bytes const &gasless_transfer_data_)
  : user_id_(user_id_)
  , address_(address_)
  , amount_(amount_)
  , comment_(comment_)
  , is_comment_encrypted_(is_comment_encrypted_)
  , sending_id_(sending_id_)
  , regular_transfer_data_(std::move(regular_transfer_data_))
  , gasless_transfer_data_(std::move(gasless_transfer_data_))
{}

const std::int32_t sendTonWalletTransfer::ID;

void sendTonWalletTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendTonWalletTransfer");
    s.store_field("user_id", user_id_);
    s.store_field("address", address_);
    s.store_field("amount", amount_);
    s.store_field("comment", comment_);
    s.store_field("is_comment_encrypted", is_comment_encrypted_);
    s.store_field("sending_id", sending_id_);
    s.store_bytes_field("regular_transfer_data", regular_transfer_data_);
    s.store_bytes_field("gasless_transfer_data", gasless_transfer_data_);
    s.store_class_end();
  }
}

setAutoDownloadSettings::setAutoDownloadSettings()
  : settings_()
  , type_()
{}

setAutoDownloadSettings::setAutoDownloadSettings(object_ptr<autoDownloadSettings> &&settings_, object_ptr<NetworkType> &&type_)
  : settings_(std::move(settings_))
  , type_(std::move(type_))
{}

const std::int32_t setAutoDownloadSettings::ID;

void setAutoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAutoDownloadSettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

setBirthdate::setBirthdate()
  : birthdate_()
{}

setBirthdate::setBirthdate(object_ptr<birthdate> &&birthdate_)
  : birthdate_(std::move(birthdate_))
{}

const std::int32_t setBirthdate::ID;

void setBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBirthdate");
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_class_end();
  }
}

setBotName::setBotName()
  : bot_user_id_()
  , language_code_()
  , name_()
{}

setBotName::setBotName(int53 bot_user_id_, string const &language_code_, string const &name_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , name_(name_)
{}

const std::int32_t setBotName::ID;

void setBotName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotName");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

setBusinessAccountName::setBusinessAccountName()
  : business_connection_id_()
  , first_name_()
  , last_name_()
{}

setBusinessAccountName::setBusinessAccountName(string const &business_connection_id_, string const &first_name_, string const &last_name_)
  : business_connection_id_(business_connection_id_)
  , first_name_(first_name_)
  , last_name_(last_name_)
{}

const std::int32_t setBusinessAccountName::ID;

void setBusinessAccountName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAccountName");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_class_end();
  }
}

setBusinessStartPage::setBusinessStartPage()
  : start_page_()
{}

setBusinessStartPage::setBusinessStartPage(object_ptr<inputBusinessStartPage> &&start_page_)
  : start_page_(std::move(start_page_))
{}

const std::int32_t setBusinessStartPage::ID;

void setBusinessStartPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessStartPage");
    s.store_object_field("start_page", static_cast<const BaseObject *>(start_page_.get()));
    s.store_class_end();
  }
}

setChatMemberTag::setChatMemberTag()
  : chat_id_()
  , user_id_()
  , tag_()
{}

setChatMemberTag::setChatMemberTag(int53 chat_id_, int53 user_id_, string const &tag_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
  , tag_(tag_)
{}

const std::int32_t setChatMemberTag::ID;

void setChatMemberTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatMemberTag");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("tag", tag_);
    s.store_class_end();
  }
}

setChatNotificationSettings::setChatNotificationSettings()
  : chat_id_()
  , notification_settings_()
{}

setChatNotificationSettings::setChatNotificationSettings(int53 chat_id_, object_ptr<chatNotificationSettings> &&notification_settings_)
  : chat_id_(chat_id_)
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t setChatNotificationSettings::ID;

void setChatNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatNotificationSettings");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

setCommunityName::setCommunityName()
  : community_id_()
  , name_()
{}

setCommunityName::setCommunityName(int53 community_id_, string const &name_)
  : community_id_(community_id_)
  , name_(name_)
{}

const std::int32_t setCommunityName::ID;

void setCommunityName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCommunityName");
    s.store_field("community_id", community_id_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

setDefaultReactionType::setDefaultReactionType()
  : reaction_type_()
{}

setDefaultReactionType::setDefaultReactionType(object_ptr<ReactionType> &&reaction_type_)
  : reaction_type_(std::move(reaction_type_))
{}

const std::int32_t setDefaultReactionType::ID;

void setDefaultReactionType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultReactionType");
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_class_end();
  }
}

setForumTopicNotificationSettings::setForumTopicNotificationSettings()
  : chat_id_()
  , forum_topic_id_()
  , notification_settings_()
{}

setForumTopicNotificationSettings::setForumTopicNotificationSettings(int53 chat_id_, int32 forum_topic_id_, object_ptr<chatNotificationSettings> &&notification_settings_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t setForumTopicNotificationSettings::ID;

void setForumTopicNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setForumTopicNotificationSettings");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

setLiveStoryMessageSender::setLiveStoryMessageSender()
  : group_call_id_()
  , message_sender_id_()
{}

setLiveStoryMessageSender::setLiveStoryMessageSender(int32 group_call_id_, object_ptr<MessageSender> &&message_sender_id_)
  : group_call_id_(group_call_id_)
  , message_sender_id_(std::move(message_sender_id_))
{}

const std::int32_t setLiveStoryMessageSender::ID;

void setLiveStoryMessageSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLiveStoryMessageSender");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    s.store_class_end();
  }
}

setLogTagVerbosityLevel::setLogTagVerbosityLevel()
  : tag_()
  , new_verbosity_level_()
{}

setLogTagVerbosityLevel::setLogTagVerbosityLevel(string const &tag_, int32 new_verbosity_level_)
  : tag_(tag_)
  , new_verbosity_level_(new_verbosity_level_)
{}

const std::int32_t setLogTagVerbosityLevel::ID;

void setLogTagVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLogTagVerbosityLevel");
    s.store_field("tag", tag_);
    s.store_field("new_verbosity_level", new_verbosity_level_);
    s.store_class_end();
  }
}

setLoginEmailAddress::setLoginEmailAddress()
  : new_login_email_address_()
{}

setLoginEmailAddress::setLoginEmailAddress(string const &new_login_email_address_)
  : new_login_email_address_(new_login_email_address_)
{}

const std::int32_t setLoginEmailAddress::ID;

void setLoginEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLoginEmailAddress");
    s.store_field("new_login_email_address", new_login_email_address_);
    s.store_class_end();
  }
}

setMessageSenderBlockList::setMessageSenderBlockList()
  : sender_id_()
  , block_list_()
{}

setMessageSenderBlockList::setMessageSenderBlockList(object_ptr<MessageSender> &&sender_id_, object_ptr<BlockList> &&block_list_)
  : sender_id_(std::move(sender_id_))
  , block_list_(std::move(block_list_))
{}

const std::int32_t setMessageSenderBlockList::ID;

void setMessageSenderBlockList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMessageSenderBlockList");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_class_end();
  }
}

setPinnedForumTopics::setPinnedForumTopics()
  : chat_id_()
  , forum_topic_ids_()
{}

setPinnedForumTopics::setPinnedForumTopics(int53 chat_id_, array<int32> &&forum_topic_ids_)
  : chat_id_(chat_id_)
  , forum_topic_ids_(std::move(forum_topic_ids_))
{}

const std::int32_t setPinnedForumTopics::ID;

void setPinnedForumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPinnedForumTopics");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("forum_topic_ids", forum_topic_ids_.size()); for (const auto &_value : forum_topic_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setStickerMaskPosition::setStickerMaskPosition()
  : sticker_()
  , mask_position_()
{}

setStickerMaskPosition::setStickerMaskPosition(object_ptr<InputFile> &&sticker_, object_ptr<maskPosition> &&mask_position_)
  : sticker_(std::move(sticker_))
  , mask_position_(std::move(mask_position_))
{}

const std::int32_t setStickerMaskPosition::ID;

void setStickerMaskPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerMaskPosition");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("mask_position", static_cast<const BaseObject *>(mask_position_.get()));
    s.store_class_end();
  }
}

setUsername::setUsername()
  : username_()
{}

setUsername::setUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t setUsername::ID;

void setUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

startGroupCallRecording::startGroupCallRecording()
  : group_call_id_()
  , title_()
  , record_video_()
  , use_portrait_orientation_()
{}

startGroupCallRecording::startGroupCallRecording(int32 group_call_id_, string const &title_, bool record_video_, bool use_portrait_orientation_)
  : group_call_id_(group_call_id_)
  , title_(title_)
  , record_video_(record_video_)
  , use_portrait_orientation_(use_portrait_orientation_)
{}

const std::int32_t startGroupCallRecording::ID;

void startGroupCallRecording::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startGroupCallRecording");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("title", title_);
    s.store_field("record_video", record_video_);
    s.store_field("use_portrait_orientation", use_portrait_orientation_);
    s.store_class_end();
  }
}

toggleChatHasProtectedContent::toggleChatHasProtectedContent()
  : chat_id_()
  , has_protected_content_()
{}

toggleChatHasProtectedContent::toggleChatHasProtectedContent(int53 chat_id_, bool has_protected_content_)
  : chat_id_(chat_id_)
  , has_protected_content_(has_protected_content_)
{}

const std::int32_t toggleChatHasProtectedContent::ID;

void toggleChatHasProtectedContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatHasProtectedContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("has_protected_content", has_protected_content_);
    s.store_class_end();
  }
}

toggleDownloadIsPaused::toggleDownloadIsPaused()
  : file_id_()
  , is_paused_()
{}

toggleDownloadIsPaused::toggleDownloadIsPaused(int32 file_id_, bool is_paused_)
  : file_id_(file_id_)
  , is_paused_(is_paused_)
{}

const std::int32_t toggleDownloadIsPaused::ID;

void toggleDownloadIsPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleDownloadIsPaused");
    s.store_field("file_id", file_id_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

toggleHasSponsoredMessagesEnabled::toggleHasSponsoredMessagesEnabled()
  : has_sponsored_messages_enabled_()
{}

toggleHasSponsoredMessagesEnabled::toggleHasSponsoredMessagesEnabled(bool has_sponsored_messages_enabled_)
  : has_sponsored_messages_enabled_(has_sponsored_messages_enabled_)
{}

const std::int32_t toggleHasSponsoredMessagesEnabled::ID;

void toggleHasSponsoredMessagesEnabled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleHasSponsoredMessagesEnabled");
    s.store_field("has_sponsored_messages_enabled", has_sponsored_messages_enabled_);
    s.store_class_end();
  }
}

toggleSupergroupUsernameIsActive::toggleSupergroupUsernameIsActive()
  : supergroup_id_()
  , username_()
  , is_active_()
{}

toggleSupergroupUsernameIsActive::toggleSupergroupUsernameIsActive(int53 supergroup_id_, string const &username_, bool is_active_)
  : supergroup_id_(supergroup_id_)
  , username_(username_)
  , is_active_(is_active_)
{}

const std::int32_t toggleSupergroupUsernameIsActive::ID;

void toggleSupergroupUsernameIsActive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupUsernameIsActive");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("username", username_);
    s.store_field("is_active", is_active_);
    s.store_class_end();
  }
}

unpinChatMessage::unpinChatMessage()
  : chat_id_()
  , message_id_()
{}

unpinChatMessage::unpinChatMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t unpinChatMessage::ID;

void unpinChatMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unpinChatMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

validateOrderInfo::validateOrderInfo()
  : input_invoice_()
  , order_info_()
  , allow_save_()
{}

validateOrderInfo::validateOrderInfo(object_ptr<InputInvoice> &&input_invoice_, object_ptr<orderInfo> &&order_info_, bool allow_save_)
  : input_invoice_(std::move(input_invoice_))
  , order_info_(std::move(order_info_))
  , allow_save_(allow_save_)
{}

const std::int32_t validateOrderInfo::ID;

void validateOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "validateOrderInfo");
    s.store_object_field("input_invoice", static_cast<const BaseObject *>(input_invoice_.get()));
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_field("allow_save", allow_save_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
