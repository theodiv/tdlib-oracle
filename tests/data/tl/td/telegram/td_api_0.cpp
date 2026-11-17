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

std::string to_string(const BaseObject &value) {
  TlStorerToString storer;
  value.store(storer, "");
  return storer.move_as_string();
}

addedProxies::addedProxies()
  : proxies_()
{}

addedProxies::addedProxies(array<object_ptr<addedProxy>> &&proxies_)
  : proxies_(std::move(proxies_))
{}

const std::int32_t addedProxies::ID;

void addedProxies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addedProxies");
    { s.store_vector_begin("proxies", proxies_.size()); for (const auto &_value : proxies_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

address::address()
  : country_code_()
  , state_()
  , city_()
  , street_line1_()
  , street_line2_()
  , postal_code_()
{}

address::address(string const &country_code_, string const &state_, string const &city_, string const &street_line1_, string const &street_line2_, string const &postal_code_)
  : country_code_(country_code_)
  , state_(state_)
  , city_(city_)
  , street_line1_(street_line1_)
  , street_line2_(street_line2_)
  , postal_code_(postal_code_)
{}

const std::int32_t address::ID;

void address::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "address");
    s.store_field("country_code", country_code_);
    s.store_field("state", state_);
    s.store_field("city", city_);
    s.store_field("street_line1", street_line1_);
    s.store_field("street_line2", street_line2_);
    s.store_field("postal_code", postal_code_);
    s.store_class_end();
  }
}

animatedChatPhoto::animatedChatPhoto()
  : length_()
  , file_()
  , main_frame_timestamp_()
{}

animatedChatPhoto::animatedChatPhoto(int32 length_, object_ptr<file> &&file_, double main_frame_timestamp_)
  : length_(length_)
  , file_(std::move(file_))
  , main_frame_timestamp_(main_frame_timestamp_)
{}

const std::int32_t animatedChatPhoto::ID;

void animatedChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animatedChatPhoto");
    s.store_field("length", length_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("main_frame_timestamp", main_frame_timestamp_);
    s.store_class_end();
  }
}

attachmentMenuBotColor::attachmentMenuBotColor()
  : light_color_()
  , dark_color_()
{}

attachmentMenuBotColor::attachmentMenuBotColor(int32 light_color_, int32 dark_color_)
  : light_color_(light_color_)
  , dark_color_(dark_color_)
{}

const std::int32_t attachmentMenuBotColor::ID;

void attachmentMenuBotColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachmentMenuBotColor");
    s.store_field("light_color", light_color_);
    s.store_field("dark_color", dark_color_);
    s.store_class_end();
  }
}

attributeCraftPersistenceProbability::attributeCraftPersistenceProbability()
  : persistence_chance_per_mille_()
{}

attributeCraftPersistenceProbability::attributeCraftPersistenceProbability(array<int32> &&persistence_chance_per_mille_)
  : persistence_chance_per_mille_(std::move(persistence_chance_per_mille_))
{}

const std::int32_t attributeCraftPersistenceProbability::ID;

void attributeCraftPersistenceProbability::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attributeCraftPersistenceProbability");
    { s.store_vector_begin("persistence_chance_per_mille", persistence_chance_per_mille_.size()); for (const auto &_value : persistence_chance_per_mille_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

authenticationCodeTypeTelegramMessage::authenticationCodeTypeTelegramMessage()
  : length_()
{}

authenticationCodeTypeTelegramMessage::authenticationCodeTypeTelegramMessage(int32 length_)
  : length_(length_)
{}

const std::int32_t authenticationCodeTypeTelegramMessage::ID;

void authenticationCodeTypeTelegramMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeTelegramMessage");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeSms::authenticationCodeTypeSms()
  : length_()
{}

authenticationCodeTypeSms::authenticationCodeTypeSms(int32 length_)
  : length_(length_)
{}

const std::int32_t authenticationCodeTypeSms::ID;

void authenticationCodeTypeSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeSms");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeSmsWord::authenticationCodeTypeSmsWord()
  : first_letter_()
{}

authenticationCodeTypeSmsWord::authenticationCodeTypeSmsWord(string const &first_letter_)
  : first_letter_(first_letter_)
{}

const std::int32_t authenticationCodeTypeSmsWord::ID;

void authenticationCodeTypeSmsWord::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeSmsWord");
    s.store_field("first_letter", first_letter_);
    s.store_class_end();
  }
}

authenticationCodeTypeSmsPhrase::authenticationCodeTypeSmsPhrase()
  : first_word_()
{}

authenticationCodeTypeSmsPhrase::authenticationCodeTypeSmsPhrase(string const &first_word_)
  : first_word_(first_word_)
{}

const std::int32_t authenticationCodeTypeSmsPhrase::ID;

void authenticationCodeTypeSmsPhrase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeSmsPhrase");
    s.store_field("first_word", first_word_);
    s.store_class_end();
  }
}

authenticationCodeTypeCall::authenticationCodeTypeCall()
  : length_()
{}

authenticationCodeTypeCall::authenticationCodeTypeCall(int32 length_)
  : length_(length_)
{}

const std::int32_t authenticationCodeTypeCall::ID;

void authenticationCodeTypeCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeCall");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeFlashCall::authenticationCodeTypeFlashCall()
  : pattern_()
{}

authenticationCodeTypeFlashCall::authenticationCodeTypeFlashCall(string const &pattern_)
  : pattern_(pattern_)
{}

const std::int32_t authenticationCodeTypeFlashCall::ID;

void authenticationCodeTypeFlashCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeFlashCall");
    s.store_field("pattern", pattern_);
    s.store_class_end();
  }
}

authenticationCodeTypeMissedCall::authenticationCodeTypeMissedCall()
  : phone_number_prefix_()
  , length_()
{}

authenticationCodeTypeMissedCall::authenticationCodeTypeMissedCall(string const &phone_number_prefix_, int32 length_)
  : phone_number_prefix_(phone_number_prefix_)
  , length_(length_)
{}

const std::int32_t authenticationCodeTypeMissedCall::ID;

void authenticationCodeTypeMissedCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeMissedCall");
    s.store_field("phone_number_prefix", phone_number_prefix_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeFragment::authenticationCodeTypeFragment()
  : url_()
  , length_()
{}

authenticationCodeTypeFragment::authenticationCodeTypeFragment(string const &url_, int32 length_)
  : url_(url_)
  , length_(length_)
{}

const std::int32_t authenticationCodeTypeFragment::ID;

void authenticationCodeTypeFragment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeFragment");
    s.store_field("url", url_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeFirebaseAndroid::authenticationCodeTypeFirebaseAndroid()
  : device_verification_parameters_()
  , length_()
{}

authenticationCodeTypeFirebaseAndroid::authenticationCodeTypeFirebaseAndroid(object_ptr<FirebaseDeviceVerificationParameters> &&device_verification_parameters_, int32 length_)
  : device_verification_parameters_(std::move(device_verification_parameters_))
  , length_(length_)
{}

const std::int32_t authenticationCodeTypeFirebaseAndroid::ID;

void authenticationCodeTypeFirebaseAndroid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeFirebaseAndroid");
    s.store_object_field("device_verification_parameters", static_cast<const BaseObject *>(device_verification_parameters_.get()));
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeFirebaseIos::authenticationCodeTypeFirebaseIos()
  : receipt_()
  , push_timeout_()
  , length_()
{}

authenticationCodeTypeFirebaseIos::authenticationCodeTypeFirebaseIos(string const &receipt_, int32 push_timeout_, int32 length_)
  : receipt_(receipt_)
  , push_timeout_(push_timeout_)
  , length_(length_)
{}

const std::int32_t authenticationCodeTypeFirebaseIos::ID;

void authenticationCodeTypeFirebaseIos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeFirebaseIos");
    s.store_field("receipt", receipt_);
    s.store_field("push_timeout", push_timeout_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authorizationStateWaitTdlibParameters::authorizationStateWaitTdlibParameters() {
}

const std::int32_t authorizationStateWaitTdlibParameters::ID;

void authorizationStateWaitTdlibParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitTdlibParameters");
    s.store_class_end();
  }
}

authorizationStateWaitPhoneNumber::authorizationStateWaitPhoneNumber() {
}

const std::int32_t authorizationStateWaitPhoneNumber::ID;

void authorizationStateWaitPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitPhoneNumber");
    s.store_class_end();
  }
}

authorizationStateWaitPremiumPurchase::authorizationStateWaitPremiumPurchase()
  : store_product_id_()
  , premium_day_count_()
  , support_email_address_()
  , support_email_subject_()
{}

authorizationStateWaitPremiumPurchase::authorizationStateWaitPremiumPurchase(string const &store_product_id_, int32 premium_day_count_, string const &support_email_address_, string const &support_email_subject_)
  : store_product_id_(store_product_id_)
  , premium_day_count_(premium_day_count_)
  , support_email_address_(support_email_address_)
  , support_email_subject_(support_email_subject_)
{}

const std::int32_t authorizationStateWaitPremiumPurchase::ID;

void authorizationStateWaitPremiumPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitPremiumPurchase");
    s.store_field("store_product_id", store_product_id_);
    s.store_field("premium_day_count", premium_day_count_);
    s.store_field("support_email_address", support_email_address_);
    s.store_field("support_email_subject", support_email_subject_);
    s.store_class_end();
  }
}

authorizationStateWaitEmailAddress::authorizationStateWaitEmailAddress()
  : allow_apple_id_()
  , allow_google_id_()
{}

authorizationStateWaitEmailAddress::authorizationStateWaitEmailAddress(bool allow_apple_id_, bool allow_google_id_)
  : allow_apple_id_(allow_apple_id_)
  , allow_google_id_(allow_google_id_)
{}

const std::int32_t authorizationStateWaitEmailAddress::ID;

void authorizationStateWaitEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitEmailAddress");
    s.store_field("allow_apple_id", allow_apple_id_);
    s.store_field("allow_google_id", allow_google_id_);
    s.store_class_end();
  }
}

authorizationStateWaitEmailCode::authorizationStateWaitEmailCode()
  : allow_apple_id_()
  , allow_google_id_()
  , code_info_()
  , email_address_reset_state_()
{}

authorizationStateWaitEmailCode::authorizationStateWaitEmailCode(bool allow_apple_id_, bool allow_google_id_, object_ptr<emailAddressAuthenticationCodeInfo> &&code_info_, object_ptr<EmailAddressResetState> &&email_address_reset_state_)
  : allow_apple_id_(allow_apple_id_)
  , allow_google_id_(allow_google_id_)
  , code_info_(std::move(code_info_))
  , email_address_reset_state_(std::move(email_address_reset_state_))
{}

const std::int32_t authorizationStateWaitEmailCode::ID;

void authorizationStateWaitEmailCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitEmailCode");
    s.store_field("allow_apple_id", allow_apple_id_);
    s.store_field("allow_google_id", allow_google_id_);
    s.store_object_field("code_info", static_cast<const BaseObject *>(code_info_.get()));
    s.store_object_field("email_address_reset_state", static_cast<const BaseObject *>(email_address_reset_state_.get()));
    s.store_class_end();
  }
}

authorizationStateWaitCode::authorizationStateWaitCode()
  : code_info_()
{}

authorizationStateWaitCode::authorizationStateWaitCode(object_ptr<authenticationCodeInfo> &&code_info_)
  : code_info_(std::move(code_info_))
{}

const std::int32_t authorizationStateWaitCode::ID;

void authorizationStateWaitCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitCode");
    s.store_object_field("code_info", static_cast<const BaseObject *>(code_info_.get()));
    s.store_class_end();
  }
}

authorizationStateWaitOtherDeviceConfirmation::authorizationStateWaitOtherDeviceConfirmation()
  : link_()
{}

authorizationStateWaitOtherDeviceConfirmation::authorizationStateWaitOtherDeviceConfirmation(string const &link_)
  : link_(link_)
{}

const std::int32_t authorizationStateWaitOtherDeviceConfirmation::ID;

void authorizationStateWaitOtherDeviceConfirmation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitOtherDeviceConfirmation");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

authorizationStateWaitRegistration::authorizationStateWaitRegistration()
  : terms_of_service_()
{}

authorizationStateWaitRegistration::authorizationStateWaitRegistration(object_ptr<termsOfService> &&terms_of_service_)
  : terms_of_service_(std::move(terms_of_service_))
{}

const std::int32_t authorizationStateWaitRegistration::ID;

void authorizationStateWaitRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitRegistration");
    s.store_object_field("terms_of_service", static_cast<const BaseObject *>(terms_of_service_.get()));
    s.store_class_end();
  }
}

authorizationStateWaitPassword::authorizationStateWaitPassword()
  : password_hint_()
  , has_recovery_email_address_()
  , has_passport_data_()
  , recovery_email_address_pattern_()
{}

authorizationStateWaitPassword::authorizationStateWaitPassword(string const &password_hint_, bool has_recovery_email_address_, bool has_passport_data_, string const &recovery_email_address_pattern_)
  : password_hint_(password_hint_)
  , has_recovery_email_address_(has_recovery_email_address_)
  , has_passport_data_(has_passport_data_)
  , recovery_email_address_pattern_(recovery_email_address_pattern_)
{}

const std::int32_t authorizationStateWaitPassword::ID;

void authorizationStateWaitPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitPassword");
    s.store_field("password_hint", password_hint_);
    s.store_field("has_recovery_email_address", has_recovery_email_address_);
    s.store_field("has_passport_data", has_passport_data_);
    s.store_field("recovery_email_address_pattern", recovery_email_address_pattern_);
    s.store_class_end();
  }
}

authorizationStateReady::authorizationStateReady() {
}

const std::int32_t authorizationStateReady::ID;

void authorizationStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateReady");
    s.store_class_end();
  }
}

authorizationStateLoggingOut::authorizationStateLoggingOut() {
}

const std::int32_t authorizationStateLoggingOut::ID;

void authorizationStateLoggingOut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateLoggingOut");
    s.store_class_end();
  }
}

authorizationStateClosing::authorizationStateClosing() {
}

const std::int32_t authorizationStateClosing::ID;

void authorizationStateClosing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateClosing");
    s.store_class_end();
  }
}

authorizationStateClosed::authorizationStateClosed() {
}

const std::int32_t authorizationStateClosed::ID;

void authorizationStateClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateClosed");
    s.store_class_end();
  }
}

backgroundTypeWallpaper::backgroundTypeWallpaper()
  : is_blurred_()
  , is_moving_()
{}

backgroundTypeWallpaper::backgroundTypeWallpaper(bool is_blurred_, bool is_moving_)
  : is_blurred_(is_blurred_)
  , is_moving_(is_moving_)
{}

const std::int32_t backgroundTypeWallpaper::ID;

void backgroundTypeWallpaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundTypeWallpaper");
    s.store_field("is_blurred", is_blurred_);
    s.store_field("is_moving", is_moving_);
    s.store_class_end();
  }
}

backgroundTypePattern::backgroundTypePattern()
  : fill_()
  , intensity_()
  , is_inverted_()
  , is_moving_()
{}

backgroundTypePattern::backgroundTypePattern(object_ptr<BackgroundFill> &&fill_, int32 intensity_, bool is_inverted_, bool is_moving_)
  : fill_(std::move(fill_))
  , intensity_(intensity_)
  , is_inverted_(is_inverted_)
  , is_moving_(is_moving_)
{}

const std::int32_t backgroundTypePattern::ID;

void backgroundTypePattern::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundTypePattern");
    s.store_object_field("fill", static_cast<const BaseObject *>(fill_.get()));
    s.store_field("intensity", intensity_);
    s.store_field("is_inverted", is_inverted_);
    s.store_field("is_moving", is_moving_);
    s.store_class_end();
  }
}

backgroundTypeFill::backgroundTypeFill()
  : fill_()
{}

backgroundTypeFill::backgroundTypeFill(object_ptr<BackgroundFill> &&fill_)
  : fill_(std::move(fill_))
{}

const std::int32_t backgroundTypeFill::ID;

void backgroundTypeFill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundTypeFill");
    s.store_object_field("fill", static_cast<const BaseObject *>(fill_.get()));
    s.store_class_end();
  }
}

backgroundTypeChatTheme::backgroundTypeChatTheme()
  : theme_name_()
{}

backgroundTypeChatTheme::backgroundTypeChatTheme(string const &theme_name_)
  : theme_name_(theme_name_)
{}

const std::int32_t backgroundTypeChatTheme::ID;

void backgroundTypeChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundTypeChatTheme");
    s.store_field("theme_name", theme_name_);
    s.store_class_end();
  }
}

businessFeatures::businessFeatures()
  : features_()
{}

businessFeatures::businessFeatures(array<object_ptr<BusinessFeature>> &&features_)
  : features_(std::move(features_))
{}

const std::int32_t businessFeatures::ID;

void businessFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatures");
    { s.store_vector_begin("features", features_.size()); for (const auto &_value : features_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

callDiscardReasonEmpty::callDiscardReasonEmpty() {
}

const std::int32_t callDiscardReasonEmpty::ID;

void callDiscardReasonEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonEmpty");
    s.store_class_end();
  }
}

callDiscardReasonMissed::callDiscardReasonMissed() {
}

const std::int32_t callDiscardReasonMissed::ID;

void callDiscardReasonMissed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonMissed");
    s.store_class_end();
  }
}

callDiscardReasonDeclined::callDiscardReasonDeclined() {
}

const std::int32_t callDiscardReasonDeclined::ID;

void callDiscardReasonDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonDeclined");
    s.store_class_end();
  }
}

callDiscardReasonDisconnected::callDiscardReasonDisconnected() {
}

const std::int32_t callDiscardReasonDisconnected::ID;

void callDiscardReasonDisconnected::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonDisconnected");
    s.store_class_end();
  }
}

callDiscardReasonHungUp::callDiscardReasonHungUp() {
}

const std::int32_t callDiscardReasonHungUp::ID;

void callDiscardReasonHungUp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonHungUp");
    s.store_class_end();
  }
}

callDiscardReasonUpgradeToGroupCall::callDiscardReasonUpgradeToGroupCall()
  : invite_link_()
{}

callDiscardReasonUpgradeToGroupCall::callDiscardReasonUpgradeToGroupCall(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t callDiscardReasonUpgradeToGroupCall::ID;

void callDiscardReasonUpgradeToGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonUpgradeToGroupCall");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

callStatePending::callStatePending()
  : is_created_()
  , is_received_()
{}

callStatePending::callStatePending(bool is_created_, bool is_received_)
  : is_created_(is_created_)
  , is_received_(is_received_)
{}

const std::int32_t callStatePending::ID;

void callStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStatePending");
    s.store_field("is_created", is_created_);
    s.store_field("is_received", is_received_);
    s.store_class_end();
  }
}

callStateExchangingKeys::callStateExchangingKeys() {
}

const std::int32_t callStateExchangingKeys::ID;

void callStateExchangingKeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateExchangingKeys");
    s.store_class_end();
  }
}

callStateReady::callStateReady()
  : protocol_()
  , servers_()
  , config_()
  , encryption_key_()
  , emojis_()
  , allow_p2p_()
  , is_group_call_supported_()
  , custom_parameters_()
{}

callStateReady::callStateReady(object_ptr<callProtocol> &&protocol_, array<object_ptr<callServer>> &&servers_, string const &config_, bytes const &encryption_key_, array<string> &&emojis_, bool allow_p2p_, bool is_group_call_supported_, string const &custom_parameters_)
  : protocol_(std::move(protocol_))
  , servers_(std::move(servers_))
  , config_(config_)
  , encryption_key_(std::move(encryption_key_))
  , emojis_(std::move(emojis_))
  , allow_p2p_(allow_p2p_)
  , is_group_call_supported_(is_group_call_supported_)
  , custom_parameters_(custom_parameters_)
{}

const std::int32_t callStateReady::ID;

void callStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateReady");
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    { s.store_vector_begin("servers", servers_.size()); for (const auto &_value : servers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("config", config_);
    s.store_field("encryption_key", "[REDACTED]");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("allow_p2p", allow_p2p_);
    s.store_field("is_group_call_supported", is_group_call_supported_);
    s.store_field("custom_parameters", custom_parameters_);
    s.store_class_end();
  }
}

callStateHangingUp::callStateHangingUp() {
}

const std::int32_t callStateHangingUp::ID;

void callStateHangingUp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateHangingUp");
    s.store_class_end();
  }
}

callStateDiscarded::callStateDiscarded()
  : reason_()
  , need_rating_()
  , need_debug_information_()
  , need_log_()
{}

callStateDiscarded::callStateDiscarded(object_ptr<CallDiscardReason> &&reason_, bool need_rating_, bool need_debug_information_, bool need_log_)
  : reason_(std::move(reason_))
  , need_rating_(need_rating_)
  , need_debug_information_(need_debug_information_)
  , need_log_(need_log_)
{}

const std::int32_t callStateDiscarded::ID;

void callStateDiscarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateDiscarded");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("need_rating", need_rating_);
    s.store_field("need_debug_information", need_debug_information_);
    s.store_field("need_log", need_log_);
    s.store_class_end();
  }
}

callStateError::callStateError()
  : error_()
{}

callStateError::callStateError(object_ptr<error> &&error_)
  : error_(std::move(error_))
{}

const std::int32_t callStateError::ID;

void callStateError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateError");
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

chatEvent::chatEvent()
  : id_()
  , date_()
  , member_id_()
  , action_()
{}

chatEvent::chatEvent(int64 id_, int32 date_, object_ptr<MessageSender> &&member_id_, object_ptr<ChatEventAction> &&action_)
  : id_(id_)
  , date_(date_)
  , member_id_(std::move(member_id_))
  , action_(std::move(action_))
{}

const std::int32_t chatEvent::ID;

void chatEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEvent");
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

chatFolderInviteLinkInfo::chatFolderInviteLinkInfo()
  : chat_folder_info_()
  , missing_chat_ids_()
  , added_chat_ids_()
{}

chatFolderInviteLinkInfo::chatFolderInviteLinkInfo(object_ptr<chatFolderInfo> &&chat_folder_info_, array<int53> &&missing_chat_ids_, array<int53> &&added_chat_ids_)
  : chat_folder_info_(std::move(chat_folder_info_))
  , missing_chat_ids_(std::move(missing_chat_ids_))
  , added_chat_ids_(std::move(added_chat_ids_))
{}

const std::int32_t chatFolderInviteLinkInfo::ID;

void chatFolderInviteLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderInviteLinkInfo");
    s.store_object_field("chat_folder_info", static_cast<const BaseObject *>(chat_folder_info_.get()));
    { s.store_vector_begin("missing_chat_ids", missing_chat_ids_.size()); for (const auto &_value : missing_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("added_chat_ids", added_chat_ids_.size()); for (const auto &_value : added_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatInviteLinkMembers::chatInviteLinkMembers()
  : total_count_()
  , members_()
{}

chatInviteLinkMembers::chatInviteLinkMembers(int32 total_count_, array<object_ptr<chatInviteLinkMember>> &&members_)
  : total_count_(total_count_)
  , members_(std::move(members_))
{}

const std::int32_t chatInviteLinkMembers::ID;

void chatInviteLinkMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkMembers");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatJoinRequestsInfo::chatJoinRequestsInfo()
  : total_count_()
  , user_ids_()
{}

chatJoinRequestsInfo::chatJoinRequestsInfo(int32 total_count_, array<int53> &&user_ids_)
  : total_count_(total_count_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t chatJoinRequestsInfo::ID;

void chatJoinRequestsInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequestsInfo");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatLists::chatLists()
  : chat_lists_()
{}

chatLists::chatLists(array<object_ptr<ChatList>> &&chat_lists_)
  : chat_lists_(std::move(chat_lists_))
{}

const std::int32_t chatLists::ID;

void chatLists::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatLists");
    { s.store_vector_begin("chat_lists", chat_lists_.size()); for (const auto &_value : chat_lists_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatMemberStatusCreator::chatMemberStatusCreator()
  : is_anonymous_()
  , is_member_()
{}

chatMemberStatusCreator::chatMemberStatusCreator(bool is_anonymous_, bool is_member_)
  : is_anonymous_(is_anonymous_)
  , is_member_(is_member_)
{}

const std::int32_t chatMemberStatusCreator::ID;

void chatMemberStatusCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusCreator");
    s.store_field("is_anonymous", is_anonymous_);
    s.store_field("is_member", is_member_);
    s.store_class_end();
  }
}

chatMemberStatusAdministrator::chatMemberStatusAdministrator()
  : can_be_edited_()
  , rights_()
{}

chatMemberStatusAdministrator::chatMemberStatusAdministrator(bool can_be_edited_, object_ptr<chatAdministratorRights> &&rights_)
  : can_be_edited_(can_be_edited_)
  , rights_(std::move(rights_))
{}

const std::int32_t chatMemberStatusAdministrator::ID;

void chatMemberStatusAdministrator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusAdministrator");
    s.store_field("can_be_edited", can_be_edited_);
    s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get()));
    s.store_class_end();
  }
}

chatMemberStatusMember::chatMemberStatusMember()
  : member_until_date_()
{}

chatMemberStatusMember::chatMemberStatusMember(int32 member_until_date_)
  : member_until_date_(member_until_date_)
{}

const std::int32_t chatMemberStatusMember::ID;

void chatMemberStatusMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusMember");
    s.store_field("member_until_date", member_until_date_);
    s.store_class_end();
  }
}

chatMemberStatusRestricted::chatMemberStatusRestricted()
  : is_member_()
  , restricted_until_date_()
  , permissions_()
{}

chatMemberStatusRestricted::chatMemberStatusRestricted(bool is_member_, int32 restricted_until_date_, object_ptr<chatPermissions> &&permissions_)
  : is_member_(is_member_)
  , restricted_until_date_(restricted_until_date_)
  , permissions_(std::move(permissions_))
{}

const std::int32_t chatMemberStatusRestricted::ID;

void chatMemberStatusRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusRestricted");
    s.store_field("is_member", is_member_);
    s.store_field("restricted_until_date", restricted_until_date_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_class_end();
  }
}

chatMemberStatusLeft::chatMemberStatusLeft() {
}

const std::int32_t chatMemberStatusLeft::ID;

void chatMemberStatusLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusLeft");
    s.store_class_end();
  }
}

chatMemberStatusBanned::chatMemberStatusBanned()
  : banned_until_date_()
{}

chatMemberStatusBanned::chatMemberStatusBanned(int32 banned_until_date_)
  : banned_until_date_(banned_until_date_)
{}

const std::int32_t chatMemberStatusBanned::ID;

void chatMemberStatusBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusBanned");
    s.store_field("banned_until_date", banned_until_date_);
    s.store_class_end();
  }
}

chatNotificationSettings::chatNotificationSettings()
  : use_default_mute_for_()
  , mute_for_()
  , use_default_sound_()
  , sound_id_()
  , use_default_show_preview_()
  , show_preview_()
  , use_default_mute_stories_()
  , mute_stories_()
  , use_default_story_sound_()
  , story_sound_id_()
  , use_default_show_story_poster_()
  , show_story_poster_()
  , use_default_disable_pinned_message_notifications_()
  , disable_pinned_message_notifications_()
  , use_default_disable_mention_notifications_()
  , disable_mention_notifications_()
{}

chatNotificationSettings::chatNotificationSettings(bool use_default_mute_for_, int32 mute_for_, bool use_default_sound_, int64 sound_id_, bool use_default_show_preview_, bool show_preview_, bool use_default_mute_stories_, bool mute_stories_, bool use_default_story_sound_, int64 story_sound_id_, bool use_default_show_story_poster_, bool show_story_poster_, bool use_default_disable_pinned_message_notifications_, bool disable_pinned_message_notifications_, bool use_default_disable_mention_notifications_, bool disable_mention_notifications_)
  : use_default_mute_for_(use_default_mute_for_)
  , mute_for_(mute_for_)
  , use_default_sound_(use_default_sound_)
  , sound_id_(sound_id_)
  , use_default_show_preview_(use_default_show_preview_)
  , show_preview_(show_preview_)
  , use_default_mute_stories_(use_default_mute_stories_)
  , mute_stories_(mute_stories_)
  , use_default_story_sound_(use_default_story_sound_)
  , story_sound_id_(story_sound_id_)
  , use_default_show_story_poster_(use_default_show_story_poster_)
  , show_story_poster_(show_story_poster_)
  , use_default_disable_pinned_message_notifications_(use_default_disable_pinned_message_notifications_)
  , disable_pinned_message_notifications_(disable_pinned_message_notifications_)
  , use_default_disable_mention_notifications_(use_default_disable_mention_notifications_)
  , disable_mention_notifications_(disable_mention_notifications_)
{}

const std::int32_t chatNotificationSettings::ID;

void chatNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatNotificationSettings");
    s.store_field("use_default_mute_for", use_default_mute_for_);
    s.store_field("mute_for", mute_for_);
    s.store_field("use_default_sound", use_default_sound_);
    s.store_field("sound_id", sound_id_);
    s.store_field("use_default_show_preview", use_default_show_preview_);
    s.store_field("show_preview", show_preview_);
    s.store_field("use_default_mute_stories", use_default_mute_stories_);
    s.store_field("mute_stories", mute_stories_);
    s.store_field("use_default_story_sound", use_default_story_sound_);
    s.store_field("story_sound_id", story_sound_id_);
    s.store_field("use_default_show_story_poster", use_default_show_story_poster_);
    s.store_field("show_story_poster", show_story_poster_);
    s.store_field("use_default_disable_pinned_message_notifications", use_default_disable_pinned_message_notifications_);
    s.store_field("disable_pinned_message_notifications", disable_pinned_message_notifications_);
    s.store_field("use_default_disable_mention_notifications", use_default_disable_mention_notifications_);
    s.store_field("disable_mention_notifications", disable_mention_notifications_);
    s.store_class_end();
  }
}

chatSourceMtprotoProxy::chatSourceMtprotoProxy() {
}

const std::int32_t chatSourceMtprotoProxy::ID;

void chatSourceMtprotoProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatSourceMtprotoProxy");
    s.store_class_end();
  }
}

chatSourcePublicServiceAnnouncement::chatSourcePublicServiceAnnouncement()
  : type_()
  , text_()
{}

chatSourcePublicServiceAnnouncement::chatSourcePublicServiceAnnouncement(string const &type_, string const &text_)
  : type_(type_)
  , text_(text_)
{}

const std::int32_t chatSourcePublicServiceAnnouncement::ID;

void chatSourcePublicServiceAnnouncement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatSourcePublicServiceAnnouncement");
    s.store_field("type", type_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

chatStatisticsSupergroup::chatStatisticsSupergroup()
  : period_()
  , member_count_()
  , message_count_()
  , viewer_count_()
  , sender_count_()
  , member_count_graph_()
  , join_graph_()
  , join_by_source_graph_()
  , language_graph_()
  , message_content_graph_()
  , action_graph_()
  , day_graph_()
  , week_graph_()
  , top_senders_()
  , top_administrators_()
  , top_inviters_()
{}

chatStatisticsSupergroup::chatStatisticsSupergroup(object_ptr<dateRange> &&period_, object_ptr<statisticalValue> &&member_count_, object_ptr<statisticalValue> &&message_count_, object_ptr<statisticalValue> &&viewer_count_, object_ptr<statisticalValue> &&sender_count_, object_ptr<StatisticalGraph> &&member_count_graph_, object_ptr<StatisticalGraph> &&join_graph_, object_ptr<StatisticalGraph> &&join_by_source_graph_, object_ptr<StatisticalGraph> &&language_graph_, object_ptr<StatisticalGraph> &&message_content_graph_, object_ptr<StatisticalGraph> &&action_graph_, object_ptr<StatisticalGraph> &&day_graph_, object_ptr<StatisticalGraph> &&week_graph_, array<object_ptr<chatStatisticsMessageSenderInfo>> &&top_senders_, array<object_ptr<chatStatisticsAdministratorActionsInfo>> &&top_administrators_, array<object_ptr<chatStatisticsInviterInfo>> &&top_inviters_)
  : period_(std::move(period_))
  , member_count_(std::move(member_count_))
  , message_count_(std::move(message_count_))
  , viewer_count_(std::move(viewer_count_))
  , sender_count_(std::move(sender_count_))
  , member_count_graph_(std::move(member_count_graph_))
  , join_graph_(std::move(join_graph_))
  , join_by_source_graph_(std::move(join_by_source_graph_))
  , language_graph_(std::move(language_graph_))
  , message_content_graph_(std::move(message_content_graph_))
  , action_graph_(std::move(action_graph_))
  , day_graph_(std::move(day_graph_))
  , week_graph_(std::move(week_graph_))
  , top_senders_(std::move(top_senders_))
  , top_administrators_(std::move(top_administrators_))
  , top_inviters_(std::move(top_inviters_))
{}

const std::int32_t chatStatisticsSupergroup::ID;

void chatStatisticsSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsSupergroup");
    s.store_object_field("period", static_cast<const BaseObject *>(period_.get()));
    s.store_object_field("member_count", static_cast<const BaseObject *>(member_count_.get()));
    s.store_object_field("message_count", static_cast<const BaseObject *>(message_count_.get()));
    s.store_object_field("viewer_count", static_cast<const BaseObject *>(viewer_count_.get()));
    s.store_object_field("sender_count", static_cast<const BaseObject *>(sender_count_.get()));
    s.store_object_field("member_count_graph", static_cast<const BaseObject *>(member_count_graph_.get()));
    s.store_object_field("join_graph", static_cast<const BaseObject *>(join_graph_.get()));
    s.store_object_field("join_by_source_graph", static_cast<const BaseObject *>(join_by_source_graph_.get()));
    s.store_object_field("language_graph", static_cast<const BaseObject *>(language_graph_.get()));
    s.store_object_field("message_content_graph", static_cast<const BaseObject *>(message_content_graph_.get()));
    s.store_object_field("action_graph", static_cast<const BaseObject *>(action_graph_.get()));
    s.store_object_field("day_graph", static_cast<const BaseObject *>(day_graph_.get()));
    s.store_object_field("week_graph", static_cast<const BaseObject *>(week_graph_.get()));
    { s.store_vector_begin("top_senders", top_senders_.size()); for (const auto &_value : top_senders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_administrators", top_administrators_.size()); for (const auto &_value : top_administrators_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_inviters", top_inviters_.size()); for (const auto &_value : top_inviters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatStatisticsChannel::chatStatisticsChannel()
  : period_()
  , member_count_()
  , mean_message_view_count_()
  , mean_message_share_count_()
  , mean_message_reaction_count_()
  , mean_story_view_count_()
  , mean_story_share_count_()
  , mean_story_reaction_count_()
  , enabled_notifications_percentage_()
  , member_count_graph_()
  , join_graph_()
  , mute_graph_()
  , view_count_by_hour_graph_()
  , view_count_by_source_graph_()
  , join_by_source_graph_()
  , language_graph_()
  , message_interaction_graph_()
  , message_reaction_graph_()
  , story_interaction_graph_()
  , story_reaction_graph_()
  , instant_view_interaction_graph_()
  , recent_interactions_()
{}

chatStatisticsChannel::chatStatisticsChannel(object_ptr<dateRange> &&period_, object_ptr<statisticalValue> &&member_count_, object_ptr<statisticalValue> &&mean_message_view_count_, object_ptr<statisticalValue> &&mean_message_share_count_, object_ptr<statisticalValue> &&mean_message_reaction_count_, object_ptr<statisticalValue> &&mean_story_view_count_, object_ptr<statisticalValue> &&mean_story_share_count_, object_ptr<statisticalValue> &&mean_story_reaction_count_, double enabled_notifications_percentage_, object_ptr<StatisticalGraph> &&member_count_graph_, object_ptr<StatisticalGraph> &&join_graph_, object_ptr<StatisticalGraph> &&mute_graph_, object_ptr<StatisticalGraph> &&view_count_by_hour_graph_, object_ptr<StatisticalGraph> &&view_count_by_source_graph_, object_ptr<StatisticalGraph> &&join_by_source_graph_, object_ptr<StatisticalGraph> &&language_graph_, object_ptr<StatisticalGraph> &&message_interaction_graph_, object_ptr<StatisticalGraph> &&message_reaction_graph_, object_ptr<StatisticalGraph> &&story_interaction_graph_, object_ptr<StatisticalGraph> &&story_reaction_graph_, object_ptr<StatisticalGraph> &&instant_view_interaction_graph_, array<object_ptr<chatStatisticsInteractionInfo>> &&recent_interactions_)
  : period_(std::move(period_))
  , member_count_(std::move(member_count_))
  , mean_message_view_count_(std::move(mean_message_view_count_))
  , mean_message_share_count_(std::move(mean_message_share_count_))
  , mean_message_reaction_count_(std::move(mean_message_reaction_count_))
  , mean_story_view_count_(std::move(mean_story_view_count_))
  , mean_story_share_count_(std::move(mean_story_share_count_))
  , mean_story_reaction_count_(std::move(mean_story_reaction_count_))
  , enabled_notifications_percentage_(enabled_notifications_percentage_)
  , member_count_graph_(std::move(member_count_graph_))
  , join_graph_(std::move(join_graph_))
  , mute_graph_(std::move(mute_graph_))
  , view_count_by_hour_graph_(std::move(view_count_by_hour_graph_))
  , view_count_by_source_graph_(std::move(view_count_by_source_graph_))
  , join_by_source_graph_(std::move(join_by_source_graph_))
  , language_graph_(std::move(language_graph_))
  , message_interaction_graph_(std::move(message_interaction_graph_))
  , message_reaction_graph_(std::move(message_reaction_graph_))
  , story_interaction_graph_(std::move(story_interaction_graph_))
  , story_reaction_graph_(std::move(story_reaction_graph_))
  , instant_view_interaction_graph_(std::move(instant_view_interaction_graph_))
  , recent_interactions_(std::move(recent_interactions_))
{}

const std::int32_t chatStatisticsChannel::ID;

void chatStatisticsChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsChannel");
    s.store_object_field("period", static_cast<const BaseObject *>(period_.get()));
    s.store_object_field("member_count", static_cast<const BaseObject *>(member_count_.get()));
    s.store_object_field("mean_message_view_count", static_cast<const BaseObject *>(mean_message_view_count_.get()));
    s.store_object_field("mean_message_share_count", static_cast<const BaseObject *>(mean_message_share_count_.get()));
    s.store_object_field("mean_message_reaction_count", static_cast<const BaseObject *>(mean_message_reaction_count_.get()));
    s.store_object_field("mean_story_view_count", static_cast<const BaseObject *>(mean_story_view_count_.get()));
    s.store_object_field("mean_story_share_count", static_cast<const BaseObject *>(mean_story_share_count_.get()));
    s.store_object_field("mean_story_reaction_count", static_cast<const BaseObject *>(mean_story_reaction_count_.get()));
    s.store_field("enabled_notifications_percentage", enabled_notifications_percentage_);
    s.store_object_field("member_count_graph", static_cast<const BaseObject *>(member_count_graph_.get()));
    s.store_object_field("join_graph", static_cast<const BaseObject *>(join_graph_.get()));
    s.store_object_field("mute_graph", static_cast<const BaseObject *>(mute_graph_.get()));
    s.store_object_field("view_count_by_hour_graph", static_cast<const BaseObject *>(view_count_by_hour_graph_.get()));
    s.store_object_field("view_count_by_source_graph", static_cast<const BaseObject *>(view_count_by_source_graph_.get()));
    s.store_object_field("join_by_source_graph", static_cast<const BaseObject *>(join_by_source_graph_.get()));
    s.store_object_field("language_graph", static_cast<const BaseObject *>(language_graph_.get()));
    s.store_object_field("message_interaction_graph", static_cast<const BaseObject *>(message_interaction_graph_.get()));
    s.store_object_field("message_reaction_graph", static_cast<const BaseObject *>(message_reaction_graph_.get()));
    s.store_object_field("story_interaction_graph", static_cast<const BaseObject *>(story_interaction_graph_.get()));
    s.store_object_field("story_reaction_graph", static_cast<const BaseObject *>(story_reaction_graph_.get()));
    s.store_object_field("instant_view_interaction_graph", static_cast<const BaseObject *>(instant_view_interaction_graph_.get()));
    { s.store_vector_begin("recent_interactions", recent_interactions_.size()); for (const auto &_value : recent_interactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatStatisticsInviterInfo::chatStatisticsInviterInfo()
  : user_id_()
  , added_member_count_()
{}

chatStatisticsInviterInfo::chatStatisticsInviterInfo(int53 user_id_, int32 added_member_count_)
  : user_id_(user_id_)
  , added_member_count_(added_member_count_)
{}

const std::int32_t chatStatisticsInviterInfo::ID;

void chatStatisticsInviterInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsInviterInfo");
    s.store_field("user_id", user_id_);
    s.store_field("added_member_count", added_member_count_);
    s.store_class_end();
  }
}

communityFullInfo::communityFullInfo()
  : photo_()
  , chats_()
  , administrator_count_()
  , banned_count_()
  , add_chat_request_count_()
  , notification_settings_()
{}

communityFullInfo::communityFullInfo(object_ptr<chatPhoto> &&photo_, array<object_ptr<communityChat>> &&chats_, int32 administrator_count_, int32 banned_count_, int32 add_chat_request_count_, object_ptr<chatNotificationSettings> &&notification_settings_)
  : photo_(std::move(photo_))
  , chats_(std::move(chats_))
  , administrator_count_(administrator_count_)
  , banned_count_(banned_count_)
  , add_chat_request_count_(add_chat_request_count_)
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t communityFullInfo::ID;

void communityFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityFullInfo");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("administrator_count", administrator_count_);
    s.store_field("banned_count", banned_count_);
    s.store_field("add_chat_request_count", add_chat_request_count_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

communityMemberChats::communityMemberChats()
  : owned_chat_ids_()
  , joined_chat_ids_()
{}

communityMemberChats::communityMemberChats(array<int53> &&owned_chat_ids_, array<int53> &&joined_chat_ids_)
  : owned_chat_ids_(std::move(owned_chat_ids_))
  , joined_chat_ids_(std::move(joined_chat_ids_))
{}

const std::int32_t communityMemberChats::ID;

void communityMemberChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityMemberChats");
    { s.store_vector_begin("owned_chat_ids", owned_chat_ids_.size()); for (const auto &_value : owned_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("joined_chat_ids", joined_chat_ids_.size()); for (const auto &_value : joined_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

dateRange::dateRange()
  : start_date_()
  , end_date_()
{}

dateRange::dateRange(int32 start_date_, int32 end_date_)
  : start_date_(start_date_)
  , end_date_(end_date_)
{}

const std::int32_t dateRange::ID;

void dateRange::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateRange");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_class_end();
  }
}

dateTimeFormattingTypeRelative::dateTimeFormattingTypeRelative() {
}

const std::int32_t dateTimeFormattingTypeRelative::ID;

void dateTimeFormattingTypeRelative::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateTimeFormattingTypeRelative");
    s.store_class_end();
  }
}

dateTimeFormattingTypeAbsolute::dateTimeFormattingTypeAbsolute()
  : time_precision_()
  , date_precision_()
  , show_day_of_week_()
{}

dateTimeFormattingTypeAbsolute::dateTimeFormattingTypeAbsolute(object_ptr<DateTimePartPrecision> &&time_precision_, object_ptr<DateTimePartPrecision> &&date_precision_, bool show_day_of_week_)
  : time_precision_(std::move(time_precision_))
  , date_precision_(std::move(date_precision_))
  , show_day_of_week_(show_day_of_week_)
{}

const std::int32_t dateTimeFormattingTypeAbsolute::ID;

void dateTimeFormattingTypeAbsolute::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateTimeFormattingTypeAbsolute");
    s.store_object_field("time_precision", static_cast<const BaseObject *>(time_precision_.get()));
    s.store_object_field("date_precision", static_cast<const BaseObject *>(date_precision_.get()));
    s.store_field("show_day_of_week", show_day_of_week_);
    s.store_class_end();
  }
}

emailAddressAuthenticationCode::emailAddressAuthenticationCode()
  : code_()
{}

emailAddressAuthenticationCode::emailAddressAuthenticationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t emailAddressAuthenticationCode::ID;

void emailAddressAuthenticationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressAuthenticationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

emailAddressAuthenticationAppleId::emailAddressAuthenticationAppleId()
  : token_()
{}

emailAddressAuthenticationAppleId::emailAddressAuthenticationAppleId(string const &token_)
  : token_(token_)
{}

const std::int32_t emailAddressAuthenticationAppleId::ID;

void emailAddressAuthenticationAppleId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressAuthenticationAppleId");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

emailAddressAuthenticationGoogleId::emailAddressAuthenticationGoogleId()
  : token_()
{}

emailAddressAuthenticationGoogleId::emailAddressAuthenticationGoogleId(string const &token_)
  : token_(token_)
{}

const std::int32_t emailAddressAuthenticationGoogleId::ID;

void emailAddressAuthenticationGoogleId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressAuthenticationGoogleId");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

emojiTypeRegular::emojiTypeRegular()
  : emoji_()
{}

emojiTypeRegular::emojiTypeRegular(string const &emoji_)
  : emoji_(emoji_)
{}

const std::int32_t emojiTypeRegular::ID;

void emojiTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiTypeRegular");
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

emojiTypeCustomEmoji::emojiTypeCustomEmoji()
  : custom_emoji_id_()
{}

emojiTypeCustomEmoji::emojiTypeCustomEmoji(int64 custom_emoji_id_)
  : custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t emojiTypeCustomEmoji::ID;

void emojiTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiTypeCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

encryptedCredentials::encryptedCredentials()
  : data_()
  , hash_()
  , secret_()
{}

encryptedCredentials::encryptedCredentials(bytes const &data_, bytes const &hash_, bytes const &secret_)
  : data_(std::move(data_))
  , hash_(std::move(hash_))
  , secret_(std::move(secret_))
{}

const std::int32_t encryptedCredentials::ID;

void encryptedCredentials::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedCredentials");
    s.store_bytes_field("data", data_);
    s.store_bytes_field("hash", hash_);
    s.store_field("secret", "[REDACTED]");
    s.store_class_end();
  }
}

encryptedPassportElement::encryptedPassportElement()
  : type_()
  , data_()
  , front_side_()
  , reverse_side_()
  , selfie_()
  , translation_()
  , files_()
  , value_()
  , hash_()
{}

encryptedPassportElement::encryptedPassportElement(object_ptr<PassportElementType> &&type_, bytes const &data_, object_ptr<datedFile> &&front_side_, object_ptr<datedFile> &&reverse_side_, object_ptr<datedFile> &&selfie_, array<object_ptr<datedFile>> &&translation_, array<object_ptr<datedFile>> &&files_, string const &value_, string const &hash_)
  : type_(std::move(type_))
  , data_(std::move(data_))
  , front_side_(std::move(front_side_))
  , reverse_side_(std::move(reverse_side_))
  , selfie_(std::move(selfie_))
  , translation_(std::move(translation_))
  , files_(std::move(files_))
  , value_(value_)
  , hash_(hash_)
{}

const std::int32_t encryptedPassportElement::ID;

void encryptedPassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedPassportElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("data", data_);
    s.store_object_field("front_side", static_cast<const BaseObject *>(front_side_.get()));
    s.store_object_field("reverse_side", static_cast<const BaseObject *>(reverse_side_.get()));
    s.store_object_field("selfie", static_cast<const BaseObject *>(selfie_.get()));
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("value", value_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

forumTopics::forumTopics()
  : total_count_()
  , topics_()
  , next_offset_date_()
  , next_offset_message_id_()
  , next_offset_forum_topic_id_()
{}

forumTopics::forumTopics(int32 total_count_, array<object_ptr<forumTopic>> &&topics_, int32 next_offset_date_, int53 next_offset_message_id_, int32 next_offset_forum_topic_id_)
  : total_count_(total_count_)
  , topics_(std::move(topics_))
  , next_offset_date_(next_offset_date_)
  , next_offset_message_id_(next_offset_message_id_)
  , next_offset_forum_topic_id_(next_offset_forum_topic_id_)
{}

const std::int32_t forumTopics::ID;

void forumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopics");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset_date", next_offset_date_);
    s.store_field("next_offset_message_id", next_offset_message_id_);
    s.store_field("next_offset_forum_topic_id", next_offset_forum_topic_id_);
    s.store_class_end();
  }
}

forwardSource::forwardSource()
  : chat_id_()
  , message_id_()
  , sender_id_()
  , sender_name_()
  , date_()
  , is_outgoing_()
{}

forwardSource::forwardSource(int53 chat_id_, int53 message_id_, object_ptr<MessageSender> &&sender_id_, string const &sender_name_, int32 date_, bool is_outgoing_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , sender_id_(std::move(sender_id_))
  , sender_name_(sender_name_)
  , date_(date_)
  , is_outgoing_(is_outgoing_)
{}

const std::int32_t forwardSource::ID;

void forwardSource::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forwardSource");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("sender_name", sender_name_);
    s.store_field("date", date_);
    s.store_field("is_outgoing", is_outgoing_);
    s.store_class_end();
  }
}

foundPublicPosts::foundPublicPosts()
  : messages_()
  , next_offset_()
  , search_limits_()
  , are_limits_exceeded_()
{}

foundPublicPosts::foundPublicPosts(array<object_ptr<message>> &&messages_, string const &next_offset_, object_ptr<publicPostSearchLimits> &&search_limits_, bool are_limits_exceeded_)
  : messages_(std::move(messages_))
  , next_offset_(next_offset_)
  , search_limits_(std::move(search_limits_))
  , are_limits_exceeded_(are_limits_exceeded_)
{}

const std::int32_t foundPublicPosts::ID;

void foundPublicPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundPublicPosts");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_object_field("search_limits", static_cast<const BaseObject *>(search_limits_.get()));
    s.store_field("are_limits_exceeded", are_limits_exceeded_);
    s.store_class_end();
  }
}

foundStories::foundStories()
  : total_count_()
  , stories_()
  , next_offset_()
{}

foundStories::foundStories(int32 total_count_, array<object_ptr<story>> &&stories_, string const &next_offset_)
  : total_count_(total_count_)
  , stories_(std::move(stories_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundStories::ID;

void foundStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundStories");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

gameHighScores::gameHighScores()
  : scores_()
{}

gameHighScores::gameHighScores(array<object_ptr<gameHighScore>> &&scores_)
  : scores_(std::move(scores_))
{}

const std::int32_t gameHighScores::ID;

void gameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "gameHighScores");
    { s.store_vector_begin("scores", scores_.size()); for (const auto &_value : scores_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

giftBackground::giftBackground()
  : center_color_()
  , edge_color_()
  , text_color_()
{}

giftBackground::giftBackground(int32 center_color_, int32 edge_color_, int32 text_color_)
  : center_color_(center_color_)
  , edge_color_(edge_color_)
  , text_color_(text_color_)
{}

const std::int32_t giftBackground::ID;

void giftBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftBackground");
    s.store_field("center_color", center_color_);
    s.store_field("edge_color", edge_color_);
    s.store_field("text_color", text_color_);
    s.store_class_end();
  }
}

giftResaleResultOk::giftResaleResultOk()
  : received_gift_id_()
{}

giftResaleResultOk::giftResaleResultOk(string const &received_gift_id_)
  : received_gift_id_(received_gift_id_)
{}

const std::int32_t giftResaleResultOk::ID;

void giftResaleResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftResaleResultOk");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

giftResaleResultPriceIncreased::giftResaleResultPriceIncreased()
  : price_()
{}

giftResaleResultPriceIncreased::giftResaleResultPriceIncreased(object_ptr<GiftResalePrice> &&price_)
  : price_(std::move(price_))
{}

const std::int32_t giftResaleResultPriceIncreased::ID;

void giftResaleResultPriceIncreased::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftResaleResultPriceIncreased");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

groupCallParticipants::groupCallParticipants()
  : total_count_()
  , participant_ids_()
{}

groupCallParticipants::groupCallParticipants(int32 total_count_, array<object_ptr<MessageSender>> &&participant_ids_)
  : total_count_(total_count_)
  , participant_ids_(std::move(participant_ids_))
{}

const std::int32_t groupCallParticipants::ID;

void groupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipants");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("participant_ids", participant_ids_.size()); for (const auto &_value : participant_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inlineKeyboardButton::inlineKeyboardButton()
  : text_()
  , icon_custom_emoji_id_()
  , style_()
  , type_()
{}

inlineKeyboardButton::inlineKeyboardButton(string const &text_, int64 icon_custom_emoji_id_, object_ptr<ButtonStyle> &&style_, object_ptr<InlineKeyboardButtonType> &&type_)
  : text_(text_)
  , icon_custom_emoji_id_(icon_custom_emoji_id_)
  , style_(std::move(style_))
  , type_(std::move(type_))
{}

const std::int32_t inlineKeyboardButton::ID;

void inlineKeyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButton");
    s.store_field("text", text_);
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_object_field("style", static_cast<const BaseObject *>(style_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

inputChatPhotoPrevious::inputChatPhotoPrevious()
  : chat_photo_id_()
{}

inputChatPhotoPrevious::inputChatPhotoPrevious(int64 chat_photo_id_)
  : chat_photo_id_(chat_photo_id_)
{}

const std::int32_t inputChatPhotoPrevious::ID;

void inputChatPhotoPrevious::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoPrevious");
    s.store_field("chat_photo_id", chat_photo_id_);
    s.store_class_end();
  }
}

inputChatPhotoStatic::inputChatPhotoStatic()
  : photo_()
{}

inputChatPhotoStatic::inputChatPhotoStatic(object_ptr<InputFile> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t inputChatPhotoStatic::ID;

void inputChatPhotoStatic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoStatic");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

inputChatPhotoAnimation::inputChatPhotoAnimation()
  : animation_()
  , main_frame_timestamp_()
{}

inputChatPhotoAnimation::inputChatPhotoAnimation(object_ptr<InputFile> &&animation_, double main_frame_timestamp_)
  : animation_(std::move(animation_))
  , main_frame_timestamp_(main_frame_timestamp_)
{}

const std::int32_t inputChatPhotoAnimation::ID;

void inputChatPhotoAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_field("main_frame_timestamp", main_frame_timestamp_);
    s.store_class_end();
  }
}

inputChatPhotoSticker::inputChatPhotoSticker()
  : sticker_()
{}

inputChatPhotoSticker::inputChatPhotoSticker(object_ptr<chatPhotoSticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t inputChatPhotoSticker::ID;

void inputChatPhotoSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

inputChecklist::inputChecklist()
  : title_()
  , tasks_()
  , others_can_add_tasks_()
  , others_can_mark_tasks_as_done_()
{}

inputChecklist::inputChecklist(object_ptr<formattedText> &&title_, array<object_ptr<inputChecklistTask>> &&tasks_, bool others_can_add_tasks_, bool others_can_mark_tasks_as_done_)
  : title_(std::move(title_))
  , tasks_(std::move(tasks_))
  , others_can_add_tasks_(others_can_add_tasks_)
  , others_can_mark_tasks_as_done_(others_can_mark_tasks_as_done_)
{}

const std::int32_t inputChecklist::ID;

void inputChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChecklist");
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    { s.store_vector_begin("tasks", tasks_.size()); for (const auto &_value : tasks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("others_can_add_tasks", others_can_add_tasks_);
    s.store_field("others_can_mark_tasks_as_done", others_can_mark_tasks_as_done_);
    s.store_class_end();
  }
}

inputInlineQueryResultAnimation::inputInlineQueryResultAnimation()
  : id_()
  , title_()
  , thumbnail_url_()
  , thumbnail_mime_type_()
  , video_url_()
  , video_mime_type_()
  , video_duration_()
  , video_width_()
  , video_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultAnimation::inputInlineQueryResultAnimation(string const &id_, string const &title_, string const &thumbnail_url_, string const &thumbnail_mime_type_, string const &video_url_, string const &video_mime_type_, int32 video_duration_, int32 video_width_, int32 video_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_mime_type_(thumbnail_mime_type_)
  , video_url_(video_url_)
  , video_mime_type_(video_mime_type_)
  , video_duration_(video_duration_)
  , video_width_(video_width_)
  , video_height_(video_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultAnimation::ID;

void inputInlineQueryResultAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultAnimation");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_mime_type", thumbnail_mime_type_);
    s.store_field("video_url", video_url_);
    s.store_field("video_mime_type", video_mime_type_);
    s.store_field("video_duration", video_duration_);
    s.store_field("video_width", video_width_);
    s.store_field("video_height", video_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultArticle::inputInlineQueryResultArticle()
  : id_()
  , url_()
  , title_()
  , description_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultArticle::inputInlineQueryResultArticle(string const &id_, string const &url_, string const &title_, string const &description_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , url_(url_)
  , title_(title_)
  , description_(description_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultArticle::ID;

void inputInlineQueryResultArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultArticle");
    s.store_field("id", id_);
    s.store_field("url", url_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultAudio::inputInlineQueryResultAudio()
  : id_()
  , title_()
  , performer_()
  , audio_url_()
  , audio_duration_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultAudio::inputInlineQueryResultAudio(string const &id_, string const &title_, string const &performer_, string const &audio_url_, int32 audio_duration_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , performer_(performer_)
  , audio_url_(audio_url_)
  , audio_duration_(audio_duration_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultAudio::ID;

void inputInlineQueryResultAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultAudio");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("performer", performer_);
    s.store_field("audio_url", audio_url_);
    s.store_field("audio_duration", audio_duration_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultContact::inputInlineQueryResultContact()
  : id_()
  , contact_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultContact::inputInlineQueryResultContact(string const &id_, object_ptr<contact> &&contact_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , contact_(std::move(contact_))
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultContact::ID;

void inputInlineQueryResultContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultContact");
    s.store_field("id", id_);
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultDocument::inputInlineQueryResultDocument()
  : id_()
  , title_()
  , description_()
  , document_url_()
  , mime_type_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultDocument::inputInlineQueryResultDocument(string const &id_, string const &title_, string const &description_, string const &document_url_, string const &mime_type_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , description_(description_)
  , document_url_(document_url_)
  , mime_type_(mime_type_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultDocument::ID;

void inputInlineQueryResultDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultDocument");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("document_url", document_url_);
    s.store_field("mime_type", mime_type_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultGame::inputInlineQueryResultGame()
  : id_()
  , game_short_name_()
  , reply_markup_()
{}

inputInlineQueryResultGame::inputInlineQueryResultGame(string const &id_, string const &game_short_name_, object_ptr<ReplyMarkup> &&reply_markup_)
  : id_(id_)
  , game_short_name_(game_short_name_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputInlineQueryResultGame::ID;

void inputInlineQueryResultGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultGame");
    s.store_field("id", id_);
    s.store_field("game_short_name", game_short_name_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultLocation::inputInlineQueryResultLocation()
  : id_()
  , location_()
  , live_period_()
  , title_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultLocation::inputInlineQueryResultLocation(string const &id_, object_ptr<location> &&location_, int32 live_period_, string const &title_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , location_(std::move(location_))
  , live_period_(live_period_)
  , title_(title_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultLocation::ID;

void inputInlineQueryResultLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultLocation");
    s.store_field("id", id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("live_period", live_period_);
    s.store_field("title", title_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultPhoto::inputInlineQueryResultPhoto()
  : id_()
  , title_()
  , description_()
  , thumbnail_url_()
  , photo_url_()
  , photo_width_()
  , photo_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultPhoto::inputInlineQueryResultPhoto(string const &id_, string const &title_, string const &description_, string const &thumbnail_url_, string const &photo_url_, int32 photo_width_, int32 photo_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , description_(description_)
  , thumbnail_url_(thumbnail_url_)
  , photo_url_(photo_url_)
  , photo_width_(photo_width_)
  , photo_height_(photo_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultPhoto::ID;

void inputInlineQueryResultPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultPhoto");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("photo_url", photo_url_);
    s.store_field("photo_width", photo_width_);
    s.store_field("photo_height", photo_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultSticker::inputInlineQueryResultSticker()
  : id_()
  , thumbnail_url_()
  , sticker_url_()
  , sticker_width_()
  , sticker_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultSticker::inputInlineQueryResultSticker(string const &id_, string const &thumbnail_url_, string const &sticker_url_, int32 sticker_width_, int32 sticker_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , thumbnail_url_(thumbnail_url_)
  , sticker_url_(sticker_url_)
  , sticker_width_(sticker_width_)
  , sticker_height_(sticker_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultSticker::ID;

void inputInlineQueryResultSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultSticker");
    s.store_field("id", id_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("sticker_url", sticker_url_);
    s.store_field("sticker_width", sticker_width_);
    s.store_field("sticker_height", sticker_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultVenue::inputInlineQueryResultVenue()
  : id_()
  , venue_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultVenue::inputInlineQueryResultVenue(string const &id_, object_ptr<venue> &&venue_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , venue_(std::move(venue_))
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultVenue::ID;

void inputInlineQueryResultVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultVenue");
    s.store_field("id", id_);
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultVideo::inputInlineQueryResultVideo()
  : id_()
  , title_()
  , description_()
  , thumbnail_url_()
  , video_url_()
  , mime_type_()
  , video_width_()
  , video_height_()
  , video_duration_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultVideo::inputInlineQueryResultVideo(string const &id_, string const &title_, string const &description_, string const &thumbnail_url_, string const &video_url_, string const &mime_type_, int32 video_width_, int32 video_height_, int32 video_duration_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , description_(description_)
  , thumbnail_url_(thumbnail_url_)
  , video_url_(video_url_)
  , mime_type_(mime_type_)
  , video_width_(video_width_)
  , video_height_(video_height_)
  , video_duration_(video_duration_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultVideo::ID;

void inputInlineQueryResultVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultVideo");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("video_url", video_url_);
    s.store_field("mime_type", mime_type_);
    s.store_field("video_width", video_width_);
    s.store_field("video_height", video_height_);
    s.store_field("video_duration", video_duration_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultVoiceNote::inputInlineQueryResultVoiceNote()
  : id_()
  , title_()
  , voice_note_url_()
  , voice_note_duration_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultVoiceNote::inputInlineQueryResultVoiceNote(string const &id_, string const &title_, string const &voice_note_url_, int32 voice_note_duration_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , voice_note_url_(voice_note_url_)
  , voice_note_duration_(voice_note_duration_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultVoiceNote::ID;

void inputInlineQueryResultVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultVoiceNote");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("voice_note_url", voice_note_url_);
    s.store_field("voice_note_duration", voice_note_duration_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputMessageReplyToMessage::inputMessageReplyToMessage()
  : message_id_()
  , quote_()
  , checklist_task_id_()
  , poll_option_id_()
{}

inputMessageReplyToMessage::inputMessageReplyToMessage(int53 message_id_, object_ptr<inputTextQuote> &&quote_, int32 checklist_task_id_, string const &poll_option_id_)
  : message_id_(message_id_)
  , quote_(std::move(quote_))
  , checklist_task_id_(checklist_task_id_)
  , poll_option_id_(poll_option_id_)
{}

const std::int32_t inputMessageReplyToMessage::ID;

void inputMessageReplyToMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageReplyToMessage");
    s.store_field("message_id", message_id_);
    s.store_object_field("quote", static_cast<const BaseObject *>(quote_.get()));
    s.store_field("checklist_task_id", checklist_task_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_class_end();
  }
}

inputMessageReplyToExternalMessage::inputMessageReplyToExternalMessage()
  : chat_id_()
  , message_id_()
  , quote_()
  , checklist_task_id_()
  , poll_option_id_()
{}

inputMessageReplyToExternalMessage::inputMessageReplyToExternalMessage(int53 chat_id_, int53 message_id_, object_ptr<inputTextQuote> &&quote_, int32 checklist_task_id_, string const &poll_option_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , quote_(std::move(quote_))
  , checklist_task_id_(checklist_task_id_)
  , poll_option_id_(poll_option_id_)
{}

const std::int32_t inputMessageReplyToExternalMessage::ID;

void inputMessageReplyToExternalMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageReplyToExternalMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("quote", static_cast<const BaseObject *>(quote_.get()));
    s.store_field("checklist_task_id", checklist_task_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_class_end();
  }
}

inputMessageReplyToStory::inputMessageReplyToStory()
  : story_poster_chat_id_()
  , story_id_()
{}

inputMessageReplyToStory::inputMessageReplyToStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t inputMessageReplyToStory::ID;

void inputMessageReplyToStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageReplyToStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

inputMessageReplyToEphemeralMessage::inputMessageReplyToEphemeralMessage()
  : ephemeral_message_id_()
{}

inputMessageReplyToEphemeralMessage::inputMessageReplyToEphemeralMessage(int32 ephemeral_message_id_)
  : ephemeral_message_id_(ephemeral_message_id_)
{}

const std::int32_t inputMessageReplyToEphemeralMessage::ID;

void inputMessageReplyToEphemeralMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageReplyToEphemeralMessage");
    s.store_field("ephemeral_message_id", ephemeral_message_id_);
    s.store_class_end();
  }
}

inputPollTypeRegular::inputPollTypeRegular()
  : allow_adding_options_()
{}

inputPollTypeRegular::inputPollTypeRegular(bool allow_adding_options_)
  : allow_adding_options_(allow_adding_options_)
{}

const std::int32_t inputPollTypeRegular::ID;

void inputPollTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollTypeRegular");
    s.store_field("allow_adding_options", allow_adding_options_);
    s.store_class_end();
  }
}

inputPollTypeQuiz::inputPollTypeQuiz()
  : correct_option_ids_()
  , explanation_()
  , explanation_media_()
{}

inputPollTypeQuiz::inputPollTypeQuiz(array<int32> &&correct_option_ids_, object_ptr<formattedText> &&explanation_, object_ptr<InputPollMedia> &&explanation_media_)
  : correct_option_ids_(std::move(correct_option_ids_))
  , explanation_(std::move(explanation_))
  , explanation_media_(std::move(explanation_media_))
{}

const std::int32_t inputPollTypeQuiz::ID;

void inputPollTypeQuiz::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollTypeQuiz");
    { s.store_vector_begin("correct_option_ids", correct_option_ids_.size()); for (const auto &_value : correct_option_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("explanation", static_cast<const BaseObject *>(explanation_.get()));
    s.store_object_field("explanation_media", static_cast<const BaseObject *>(explanation_media_.get()));
    s.store_class_end();
  }
}

internalLinkTypeAttachmentMenuBot::internalLinkTypeAttachmentMenuBot()
  : target_chat_()
  , bot_username_()
  , url_()
{}

internalLinkTypeAttachmentMenuBot::internalLinkTypeAttachmentMenuBot(object_ptr<TargetChat> &&target_chat_, string const &bot_username_, string const &url_)
  : target_chat_(std::move(target_chat_))
  , bot_username_(bot_username_)
  , url_(url_)
{}

const std::int32_t internalLinkTypeAttachmentMenuBot::ID;

void internalLinkTypeAttachmentMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeAttachmentMenuBot");
    s.store_object_field("target_chat", static_cast<const BaseObject *>(target_chat_.get()));
    s.store_field("bot_username", bot_username_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

internalLinkTypeAuthenticationCode::internalLinkTypeAuthenticationCode()
  : code_()
{}

internalLinkTypeAuthenticationCode::internalLinkTypeAuthenticationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t internalLinkTypeAuthenticationCode::ID;

void internalLinkTypeAuthenticationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeAuthenticationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

internalLinkTypeBackground::internalLinkTypeBackground()
  : background_name_()
{}

internalLinkTypeBackground::internalLinkTypeBackground(string const &background_name_)
  : background_name_(background_name_)
{}

const std::int32_t internalLinkTypeBackground::ID;

void internalLinkTypeBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBackground");
    s.store_field("background_name", background_name_);
    s.store_class_end();
  }
}

internalLinkTypeBotAddToChannel::internalLinkTypeBotAddToChannel()
  : bot_username_()
  , administrator_rights_()
{}

internalLinkTypeBotAddToChannel::internalLinkTypeBotAddToChannel(string const &bot_username_, object_ptr<chatAdministratorRights> &&administrator_rights_)
  : bot_username_(bot_username_)
  , administrator_rights_(std::move(administrator_rights_))
{}

const std::int32_t internalLinkTypeBotAddToChannel::ID;

void internalLinkTypeBotAddToChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBotAddToChannel");
    s.store_field("bot_username", bot_username_);
    s.store_object_field("administrator_rights", static_cast<const BaseObject *>(administrator_rights_.get()));
    s.store_class_end();
  }
}

internalLinkTypeBotStart::internalLinkTypeBotStart()
  : bot_username_()
  , start_parameter_()
  , autostart_()
{}

internalLinkTypeBotStart::internalLinkTypeBotStart(string const &bot_username_, string const &start_parameter_, bool autostart_)
  : bot_username_(bot_username_)
  , start_parameter_(start_parameter_)
  , autostart_(autostart_)
{}

const std::int32_t internalLinkTypeBotStart::ID;

void internalLinkTypeBotStart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBotStart");
    s.store_field("bot_username", bot_username_);
    s.store_field("start_parameter", start_parameter_);
    s.store_field("autostart", autostart_);
    s.store_class_end();
  }
}

internalLinkTypeBotStartInGroup::internalLinkTypeBotStartInGroup()
  : bot_username_()
  , start_parameter_()
  , administrator_rights_()
{}

internalLinkTypeBotStartInGroup::internalLinkTypeBotStartInGroup(string const &bot_username_, string const &start_parameter_, object_ptr<chatAdministratorRights> &&administrator_rights_)
  : bot_username_(bot_username_)
  , start_parameter_(start_parameter_)
  , administrator_rights_(std::move(administrator_rights_))
{}

const std::int32_t internalLinkTypeBotStartInGroup::ID;

void internalLinkTypeBotStartInGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBotStartInGroup");
    s.store_field("bot_username", bot_username_);
    s.store_field("start_parameter", start_parameter_);
    s.store_object_field("administrator_rights", static_cast<const BaseObject *>(administrator_rights_.get()));
    s.store_class_end();
  }
}

internalLinkTypeBusinessChat::internalLinkTypeBusinessChat()
  : link_name_()
{}

internalLinkTypeBusinessChat::internalLinkTypeBusinessChat(string const &link_name_)
  : link_name_(link_name_)
{}

const std::int32_t internalLinkTypeBusinessChat::ID;

void internalLinkTypeBusinessChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBusinessChat");
    s.store_field("link_name", link_name_);
    s.store_class_end();
  }
}

internalLinkTypeCallsPage::internalLinkTypeCallsPage()
  : section_()
{}

internalLinkTypeCallsPage::internalLinkTypeCallsPage(string const &section_)
  : section_(section_)
{}

const std::int32_t internalLinkTypeCallsPage::ID;

void internalLinkTypeCallsPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeCallsPage");
    s.store_field("section", section_);
    s.store_class_end();
  }
}

internalLinkTypeChatAffiliateProgram::internalLinkTypeChatAffiliateProgram()
  : username_()
  , referrer_()
{}

internalLinkTypeChatAffiliateProgram::internalLinkTypeChatAffiliateProgram(string const &username_, string const &referrer_)
  : username_(username_)
  , referrer_(referrer_)
{}

const std::int32_t internalLinkTypeChatAffiliateProgram::ID;

void internalLinkTypeChatAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChatAffiliateProgram");
    s.store_field("username", username_);
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

internalLinkTypeChatBoost::internalLinkTypeChatBoost()
  : url_()
{}

internalLinkTypeChatBoost::internalLinkTypeChatBoost(string const &url_)
  : url_(url_)
{}

const std::int32_t internalLinkTypeChatBoost::ID;

void internalLinkTypeChatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChatBoost");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

internalLinkTypeChatFolderInvite::internalLinkTypeChatFolderInvite()
  : invite_link_()
{}

internalLinkTypeChatFolderInvite::internalLinkTypeChatFolderInvite(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t internalLinkTypeChatFolderInvite::ID;

void internalLinkTypeChatFolderInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChatFolderInvite");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

internalLinkTypeChatInvite::internalLinkTypeChatInvite()
  : invite_link_()
{}

internalLinkTypeChatInvite::internalLinkTypeChatInvite(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t internalLinkTypeChatInvite::ID;

void internalLinkTypeChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChatInvite");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

internalLinkTypeChatSelection::internalLinkTypeChatSelection() {
}

const std::int32_t internalLinkTypeChatSelection::ID;

void internalLinkTypeChatSelection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChatSelection");
    s.store_class_end();
  }
}

internalLinkTypeContactsPage::internalLinkTypeContactsPage()
  : section_()
{}

internalLinkTypeContactsPage::internalLinkTypeContactsPage(string const &section_)
  : section_(section_)
{}

const std::int32_t internalLinkTypeContactsPage::ID;

void internalLinkTypeContactsPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeContactsPage");
    s.store_field("section", section_);
    s.store_class_end();
  }
}

internalLinkTypeDirectMessagesChat::internalLinkTypeDirectMessagesChat()
  : channel_username_()
{}

internalLinkTypeDirectMessagesChat::internalLinkTypeDirectMessagesChat(string const &channel_username_)
  : channel_username_(channel_username_)
{}

const std::int32_t internalLinkTypeDirectMessagesChat::ID;

void internalLinkTypeDirectMessagesChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeDirectMessagesChat");
    s.store_field("channel_username", channel_username_);
    s.store_class_end();
  }
}

internalLinkTypeGame::internalLinkTypeGame()
  : bot_username_()
  , game_short_name_()
{}

internalLinkTypeGame::internalLinkTypeGame(string const &bot_username_, string const &game_short_name_)
  : bot_username_(bot_username_)
  , game_short_name_(game_short_name_)
{}

const std::int32_t internalLinkTypeGame::ID;

void internalLinkTypeGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeGame");
    s.store_field("bot_username", bot_username_);
    s.store_field("game_short_name", game_short_name_);
    s.store_class_end();
  }
}

internalLinkTypeGiftAuction::internalLinkTypeGiftAuction()
  : auction_id_()
{}

internalLinkTypeGiftAuction::internalLinkTypeGiftAuction(string const &auction_id_)
  : auction_id_(auction_id_)
{}

const std::int32_t internalLinkTypeGiftAuction::ID;

void internalLinkTypeGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeGiftAuction");
    s.store_field("auction_id", auction_id_);
    s.store_class_end();
  }
}

internalLinkTypeGiftCollection::internalLinkTypeGiftCollection()
  : gift_owner_username_()
  , collection_id_()
{}

internalLinkTypeGiftCollection::internalLinkTypeGiftCollection(string const &gift_owner_username_, int32 collection_id_)
  : gift_owner_username_(gift_owner_username_)
  , collection_id_(collection_id_)
{}

const std::int32_t internalLinkTypeGiftCollection::ID;

void internalLinkTypeGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeGiftCollection");
    s.store_field("gift_owner_username", gift_owner_username_);
    s.store_field("collection_id", collection_id_);
    s.store_class_end();
  }
}

internalLinkTypeGroupCall::internalLinkTypeGroupCall()
  : invite_link_()
{}

internalLinkTypeGroupCall::internalLinkTypeGroupCall(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t internalLinkTypeGroupCall::ID;

void internalLinkTypeGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeGroupCall");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

internalLinkTypeInstantView::internalLinkTypeInstantView()
  : url_()
  , fallback_url_()
{}

internalLinkTypeInstantView::internalLinkTypeInstantView(string const &url_, string const &fallback_url_)
  : url_(url_)
  , fallback_url_(fallback_url_)
{}

const std::int32_t internalLinkTypeInstantView::ID;

void internalLinkTypeInstantView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeInstantView");
    s.store_field("url", url_);
    s.store_field("fallback_url", fallback_url_);
    s.store_class_end();
  }
}

internalLinkTypeInvoice::internalLinkTypeInvoice()
  : invoice_name_()
{}

internalLinkTypeInvoice::internalLinkTypeInvoice(string const &invoice_name_)
  : invoice_name_(invoice_name_)
{}

const std::int32_t internalLinkTypeInvoice::ID;

void internalLinkTypeInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeInvoice");
    s.store_field("invoice_name", invoice_name_);
    s.store_class_end();
  }
}

internalLinkTypeLanguagePack::internalLinkTypeLanguagePack()
  : language_pack_id_()
{}

internalLinkTypeLanguagePack::internalLinkTypeLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t internalLinkTypeLanguagePack::ID;

void internalLinkTypeLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

internalLinkTypeLiveStory::internalLinkTypeLiveStory()
  : story_poster_username_()
{}

internalLinkTypeLiveStory::internalLinkTypeLiveStory(string const &story_poster_username_)
  : story_poster_username_(story_poster_username_)
{}

const std::int32_t internalLinkTypeLiveStory::ID;

void internalLinkTypeLiveStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeLiveStory");
    s.store_field("story_poster_username", story_poster_username_);
    s.store_class_end();
  }
}

internalLinkTypeMainWebApp::internalLinkTypeMainWebApp()
  : bot_username_()
  , start_parameter_()
  , mode_()
{}

internalLinkTypeMainWebApp::internalLinkTypeMainWebApp(string const &bot_username_, string const &start_parameter_, object_ptr<WebAppOpenMode> &&mode_)
  : bot_username_(bot_username_)
  , start_parameter_(start_parameter_)
  , mode_(std::move(mode_))
{}

const std::int32_t internalLinkTypeMainWebApp::ID;

void internalLinkTypeMainWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeMainWebApp");
    s.store_field("bot_username", bot_username_);
    s.store_field("start_parameter", start_parameter_);
    s.store_object_field("mode", static_cast<const BaseObject *>(mode_.get()));
    s.store_class_end();
  }
}

internalLinkTypeMessage::internalLinkTypeMessage()
  : url_()
{}

internalLinkTypeMessage::internalLinkTypeMessage(string const &url_)
  : url_(url_)
{}

const std::int32_t internalLinkTypeMessage::ID;

void internalLinkTypeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeMessage");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

internalLinkTypeMessageDraft::internalLinkTypeMessageDraft()
  : text_()
  , contains_link_()
{}

internalLinkTypeMessageDraft::internalLinkTypeMessageDraft(object_ptr<formattedText> &&text_, bool contains_link_)
  : text_(std::move(text_))
  , contains_link_(contains_link_)
{}

const std::int32_t internalLinkTypeMessageDraft::ID;

void internalLinkTypeMessageDraft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeMessageDraft");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("contains_link", contains_link_);
    s.store_class_end();
  }
}

internalLinkTypeMyProfilePage::internalLinkTypeMyProfilePage()
  : section_()
{}

internalLinkTypeMyProfilePage::internalLinkTypeMyProfilePage(string const &section_)
  : section_(section_)
{}

const std::int32_t internalLinkTypeMyProfilePage::ID;

void internalLinkTypeMyProfilePage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeMyProfilePage");
    s.store_field("section", section_);
    s.store_class_end();
  }
}

internalLinkTypeNewChannelChat::internalLinkTypeNewChannelChat() {
}

const std::int32_t internalLinkTypeNewChannelChat::ID;

void internalLinkTypeNewChannelChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeNewChannelChat");
    s.store_class_end();
  }
}

internalLinkTypeNewGroupChat::internalLinkTypeNewGroupChat() {
}

const std::int32_t internalLinkTypeNewGroupChat::ID;

void internalLinkTypeNewGroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeNewGroupChat");
    s.store_class_end();
  }
}

internalLinkTypeNewPrivateChat::internalLinkTypeNewPrivateChat() {
}

const std::int32_t internalLinkTypeNewPrivateChat::ID;

void internalLinkTypeNewPrivateChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeNewPrivateChat");
    s.store_class_end();
  }
}

internalLinkTypeNewStory::internalLinkTypeNewStory()
  : content_type_()
{}

internalLinkTypeNewStory::internalLinkTypeNewStory(object_ptr<StoryContentType> &&content_type_)
  : content_type_(std::move(content_type_))
{}

const std::int32_t internalLinkTypeNewStory::ID;

void internalLinkTypeNewStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeNewStory");
    s.store_object_field("content_type", static_cast<const BaseObject *>(content_type_.get()));
    s.store_class_end();
  }
}

internalLinkTypeOauth::internalLinkTypeOauth()
  : url_()
{}

internalLinkTypeOauth::internalLinkTypeOauth(string const &url_)
  : url_(url_)
{}

const std::int32_t internalLinkTypeOauth::ID;

void internalLinkTypeOauth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeOauth");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

internalLinkTypePassportDataRequest::internalLinkTypePassportDataRequest()
  : bot_user_id_()
  , scope_()
  , public_key_()
  , nonce_()
  , callback_url_()
{}

internalLinkTypePassportDataRequest::internalLinkTypePassportDataRequest(int53 bot_user_id_, string const &scope_, string const &public_key_, string const &nonce_, string const &callback_url_)
  : bot_user_id_(bot_user_id_)
  , scope_(scope_)
  , public_key_(public_key_)
  , nonce_(nonce_)
  , callback_url_(callback_url_)
{}

const std::int32_t internalLinkTypePassportDataRequest::ID;

void internalLinkTypePassportDataRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePassportDataRequest");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("scope", scope_);
    s.store_field("public_key", public_key_);
    s.store_field("nonce", nonce_);
    s.store_field("callback_url", callback_url_);
    s.store_class_end();
  }
}

internalLinkTypePhoneNumberConfirmation::internalLinkTypePhoneNumberConfirmation()
  : hash_()
  , phone_number_()
{}

internalLinkTypePhoneNumberConfirmation::internalLinkTypePhoneNumberConfirmation(string const &hash_, string const &phone_number_)
  : hash_(hash_)
  , phone_number_(phone_number_)
{}

const std::int32_t internalLinkTypePhoneNumberConfirmation::ID;

void internalLinkTypePhoneNumberConfirmation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePhoneNumberConfirmation");
    s.store_field("hash", hash_);
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

internalLinkTypePremiumFeaturesPage::internalLinkTypePremiumFeaturesPage()
  : referrer_()
{}

internalLinkTypePremiumFeaturesPage::internalLinkTypePremiumFeaturesPage(string const &referrer_)
  : referrer_(referrer_)
{}

const std::int32_t internalLinkTypePremiumFeaturesPage::ID;

void internalLinkTypePremiumFeaturesPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePremiumFeaturesPage");
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

internalLinkTypePremiumGiftCode::internalLinkTypePremiumGiftCode()
  : code_()
{}

internalLinkTypePremiumGiftCode::internalLinkTypePremiumGiftCode(string const &code_)
  : code_(code_)
{}

const std::int32_t internalLinkTypePremiumGiftCode::ID;

void internalLinkTypePremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePremiumGiftCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

internalLinkTypePremiumGiftPurchase::internalLinkTypePremiumGiftPurchase()
  : referrer_()
{}

internalLinkTypePremiumGiftPurchase::internalLinkTypePremiumGiftPurchase(string const &referrer_)
  : referrer_(referrer_)
{}

const std::int32_t internalLinkTypePremiumGiftPurchase::ID;

void internalLinkTypePremiumGiftPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePremiumGiftPurchase");
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

internalLinkTypeProxy::internalLinkTypeProxy()
  : proxy_()
{}

internalLinkTypeProxy::internalLinkTypeProxy(object_ptr<proxy> &&proxy_)
  : proxy_(std::move(proxy_))
{}

const std::int32_t internalLinkTypeProxy::ID;

void internalLinkTypeProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeProxy");
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_class_end();
  }
}

internalLinkTypePublicChat::internalLinkTypePublicChat()
  : chat_username_()
  , draft_text_()
  , open_profile_()
  , unpaid_messages_token_()
{}

internalLinkTypePublicChat::internalLinkTypePublicChat(string const &chat_username_, string const &draft_text_, bool open_profile_, string const &unpaid_messages_token_)
  : chat_username_(chat_username_)
  , draft_text_(draft_text_)
  , open_profile_(open_profile_)
  , unpaid_messages_token_(unpaid_messages_token_)
{}

const std::int32_t internalLinkTypePublicChat::ID;

void internalLinkTypePublicChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePublicChat");
    s.store_field("chat_username", chat_username_);
    s.store_field("draft_text", draft_text_);
    s.store_field("open_profile", open_profile_);
    s.store_field("unpaid_messages_token", "[REDACTED]");
    s.store_class_end();
  }
}

internalLinkTypeQrCodeAuthentication::internalLinkTypeQrCodeAuthentication() {
}

const std::int32_t internalLinkTypeQrCodeAuthentication::ID;

void internalLinkTypeQrCodeAuthentication::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeQrCodeAuthentication");
    s.store_class_end();
  }
}

internalLinkTypeRequestManagedBot::internalLinkTypeRequestManagedBot()
  : manager_bot_username_()
  , suggested_bot_username_()
  , suggested_bot_name_()
{}

internalLinkTypeRequestManagedBot::internalLinkTypeRequestManagedBot(string const &manager_bot_username_, string const &suggested_bot_username_, string const &suggested_bot_name_)
  : manager_bot_username_(manager_bot_username_)
  , suggested_bot_username_(suggested_bot_username_)
  , suggested_bot_name_(suggested_bot_name_)
{}

const std::int32_t internalLinkTypeRequestManagedBot::ID;

void internalLinkTypeRequestManagedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeRequestManagedBot");
    s.store_field("manager_bot_username", manager_bot_username_);
    s.store_field("suggested_bot_username", suggested_bot_username_);
    s.store_field("suggested_bot_name", suggested_bot_name_);
    s.store_class_end();
  }
}

internalLinkTypeRestorePurchases::internalLinkTypeRestorePurchases() {
}

const std::int32_t internalLinkTypeRestorePurchases::ID;

void internalLinkTypeRestorePurchases::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeRestorePurchases");
    s.store_class_end();
  }
}

internalLinkTypeSavedMessages::internalLinkTypeSavedMessages() {
}

const std::int32_t internalLinkTypeSavedMessages::ID;

void internalLinkTypeSavedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeSavedMessages");
    s.store_class_end();
  }
}

internalLinkTypeSearch::internalLinkTypeSearch() {
}

const std::int32_t internalLinkTypeSearch::ID;

void internalLinkTypeSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeSearch");
    s.store_class_end();
  }
}

internalLinkTypeSettings::internalLinkTypeSettings()
  : section_()
{}

internalLinkTypeSettings::internalLinkTypeSettings(object_ptr<SettingsSection> &&section_)
  : section_(std::move(section_))
{}

const std::int32_t internalLinkTypeSettings::ID;

void internalLinkTypeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeSettings");
    s.store_object_field("section", static_cast<const BaseObject *>(section_.get()));
    s.store_class_end();
  }
}

internalLinkTypeStarPurchase::internalLinkTypeStarPurchase()
  : star_count_()
  , purpose_()
{}

internalLinkTypeStarPurchase::internalLinkTypeStarPurchase(int53 star_count_, string const &purpose_)
  : star_count_(star_count_)
  , purpose_(purpose_)
{}

const std::int32_t internalLinkTypeStarPurchase::ID;

void internalLinkTypeStarPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeStarPurchase");
    s.store_field("star_count", star_count_);
    s.store_field("purpose", purpose_);
    s.store_class_end();
  }
}

internalLinkTypeStickerSet::internalLinkTypeStickerSet()
  : sticker_set_name_()
  , expect_custom_emoji_()
{}

internalLinkTypeStickerSet::internalLinkTypeStickerSet(string const &sticker_set_name_, bool expect_custom_emoji_)
  : sticker_set_name_(sticker_set_name_)
  , expect_custom_emoji_(expect_custom_emoji_)
{}

const std::int32_t internalLinkTypeStickerSet::ID;

void internalLinkTypeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeStickerSet");
    s.store_field("sticker_set_name", sticker_set_name_);
    s.store_field("expect_custom_emoji", expect_custom_emoji_);
    s.store_class_end();
  }
}

internalLinkTypeStory::internalLinkTypeStory()
  : story_poster_username_()
  , story_id_()
{}

internalLinkTypeStory::internalLinkTypeStory(string const &story_poster_username_, int32 story_id_)
  : story_poster_username_(story_poster_username_)
  , story_id_(story_id_)
{}

const std::int32_t internalLinkTypeStory::ID;

void internalLinkTypeStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeStory");
    s.store_field("story_poster_username", story_poster_username_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

internalLinkTypeStoryAlbum::internalLinkTypeStoryAlbum()
  : story_album_owner_username_()
  , story_album_id_()
{}

internalLinkTypeStoryAlbum::internalLinkTypeStoryAlbum(string const &story_album_owner_username_, int32 story_album_id_)
  : story_album_owner_username_(story_album_owner_username_)
  , story_album_id_(story_album_id_)
{}

const std::int32_t internalLinkTypeStoryAlbum::ID;

void internalLinkTypeStoryAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeStoryAlbum");
    s.store_field("story_album_owner_username", story_album_owner_username_);
    s.store_field("story_album_id", story_album_id_);
    s.store_class_end();
  }
}

internalLinkTypeTextCompositionStyle::internalLinkTypeTextCompositionStyle()
  : style_name_()
{}

internalLinkTypeTextCompositionStyle::internalLinkTypeTextCompositionStyle(string const &style_name_)
  : style_name_(style_name_)
{}

const std::int32_t internalLinkTypeTextCompositionStyle::ID;

void internalLinkTypeTextCompositionStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeTextCompositionStyle");
    s.store_field("style_name", style_name_);
    s.store_class_end();
  }
}

internalLinkTypeTheme::internalLinkTypeTheme()
  : theme_name_()
{}

internalLinkTypeTheme::internalLinkTypeTheme(string const &theme_name_)
  : theme_name_(theme_name_)
{}

const std::int32_t internalLinkTypeTheme::ID;

void internalLinkTypeTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeTheme");
    s.store_field("theme_name", theme_name_);
    s.store_class_end();
  }
}

internalLinkTypeTonConnect::internalLinkTypeTonConnect()
  : version_()
  , dapp_client_id_()
  , connect_request_()
  , return_strategy_()
  , rpc_request_()
  , trace_id_()
{}

internalLinkTypeTonConnect::internalLinkTypeTonConnect(int32 version_, string const &dapp_client_id_, object_ptr<tonConnectConnectRequest> &&connect_request_, string const &return_strategy_, string const &rpc_request_, string const &trace_id_)
  : version_(version_)
  , dapp_client_id_(dapp_client_id_)
  , connect_request_(std::move(connect_request_))
  , return_strategy_(return_strategy_)
  , rpc_request_(rpc_request_)
  , trace_id_(trace_id_)
{}

const std::int32_t internalLinkTypeTonConnect::ID;

void internalLinkTypeTonConnect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeTonConnect");
    s.store_field("version", version_);
    s.store_field("dapp_client_id", dapp_client_id_);
    s.store_object_field("connect_request", static_cast<const BaseObject *>(connect_request_.get()));
    s.store_field("return_strategy", return_strategy_);
    s.store_field("rpc_request", rpc_request_);
    s.store_field("trace_id", trace_id_);
    s.store_class_end();
  }
}

internalLinkTypeTonWalletTransfer::internalLinkTypeTonWalletTransfer()
  : receiver_()
  , gram_amount_()
{}

internalLinkTypeTonWalletTransfer::internalLinkTypeTonWalletTransfer(object_ptr<TonWalletTransferReceiver> &&receiver_, int64 gram_amount_)
  : receiver_(std::move(receiver_))
  , gram_amount_(gram_amount_)
{}

const std::int32_t internalLinkTypeTonWalletTransfer::ID;

void internalLinkTypeTonWalletTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeTonWalletTransfer");
    s.store_object_field("receiver", static_cast<const BaseObject *>(receiver_.get()));
    s.store_field("gram_amount", gram_amount_);
    s.store_class_end();
  }
}

internalLinkTypeUnknownDeepLink::internalLinkTypeUnknownDeepLink()
  : link_()
{}

internalLinkTypeUnknownDeepLink::internalLinkTypeUnknownDeepLink(string const &link_)
  : link_(link_)
{}

const std::int32_t internalLinkTypeUnknownDeepLink::ID;

void internalLinkTypeUnknownDeepLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeUnknownDeepLink");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

internalLinkTypeUpgradedGift::internalLinkTypeUpgradedGift()
  : name_()
{}

internalLinkTypeUpgradedGift::internalLinkTypeUpgradedGift(string const &name_)
  : name_(name_)
{}

const std::int32_t internalLinkTypeUpgradedGift::ID;

void internalLinkTypeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeUpgradedGift");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

internalLinkTypeUserPhoneNumber::internalLinkTypeUserPhoneNumber()
  : phone_number_()
  , draft_text_()
  , open_profile_()
  , unpaid_messages_token_()
{}

internalLinkTypeUserPhoneNumber::internalLinkTypeUserPhoneNumber(string const &phone_number_, string const &draft_text_, bool open_profile_, string const &unpaid_messages_token_)
  : phone_number_(phone_number_)
  , draft_text_(draft_text_)
  , open_profile_(open_profile_)
  , unpaid_messages_token_(unpaid_messages_token_)
{}

const std::int32_t internalLinkTypeUserPhoneNumber::ID;

void internalLinkTypeUserPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeUserPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_field("draft_text", draft_text_);
    s.store_field("open_profile", open_profile_);
    s.store_field("unpaid_messages_token", "[REDACTED]");
    s.store_class_end();
  }
}

internalLinkTypeUserToken::internalLinkTypeUserToken()
  : token_()
  , unpaid_messages_token_()
{}

internalLinkTypeUserToken::internalLinkTypeUserToken(string const &token_, string const &unpaid_messages_token_)
  : token_(token_)
  , unpaid_messages_token_(unpaid_messages_token_)
{}

const std::int32_t internalLinkTypeUserToken::ID;

void internalLinkTypeUserToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeUserToken");
    s.store_field("token", "[REDACTED]");
    s.store_field("unpaid_messages_token", "[REDACTED]");
    s.store_class_end();
  }
}

internalLinkTypeVideoChat::internalLinkTypeVideoChat()
  : chat_username_()
  , invite_hash_()
  , is_live_stream_()
{}

internalLinkTypeVideoChat::internalLinkTypeVideoChat(string const &chat_username_, string const &invite_hash_, bool is_live_stream_)
  : chat_username_(chat_username_)
  , invite_hash_(invite_hash_)
  , is_live_stream_(is_live_stream_)
{}

const std::int32_t internalLinkTypeVideoChat::ID;

void internalLinkTypeVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeVideoChat");
    s.store_field("chat_username", chat_username_);
    s.store_field("invite_hash", invite_hash_);
    s.store_field("is_live_stream", is_live_stream_);
    s.store_class_end();
  }
}

internalLinkTypeWebApp::internalLinkTypeWebApp()
  : bot_username_()
  , web_app_short_name_()
  , start_parameter_()
  , mode_()
{}

internalLinkTypeWebApp::internalLinkTypeWebApp(string const &bot_username_, string const &web_app_short_name_, string const &start_parameter_, object_ptr<WebAppOpenMode> &&mode_)
  : bot_username_(bot_username_)
  , web_app_short_name_(web_app_short_name_)
  , start_parameter_(start_parameter_)
  , mode_(std::move(mode_))
{}

const std::int32_t internalLinkTypeWebApp::ID;

void internalLinkTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeWebApp");
    s.store_field("bot_username", bot_username_);
    s.store_field("web_app_short_name", web_app_short_name_);
    s.store_field("start_parameter", start_parameter_);
    s.store_object_field("mode", static_cast<const BaseObject *>(mode_.get()));
    s.store_class_end();
  }
}

jsonObjectMember::jsonObjectMember()
  : key_()
  , value_()
{}

jsonObjectMember::jsonObjectMember(string const &key_, object_ptr<JsonValue> &&value_)
  : key_(key_)
  , value_(std::move(value_))
{}

const std::int32_t jsonObjectMember::ID;

void jsonObjectMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonObjectMember");
    s.store_field("key", key_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

keyboardButton::keyboardButton()
  : text_()
  , icon_custom_emoji_id_()
  , style_()
  , type_()
{}

keyboardButton::keyboardButton(string const &text_, int64 icon_custom_emoji_id_, object_ptr<ButtonStyle> &&style_, object_ptr<KeyboardButtonType> &&type_)
  : text_(text_)
  , icon_custom_emoji_id_(icon_custom_emoji_id_)
  , style_(std::move(style_))
  , type_(std::move(type_))
{}

const std::int32_t keyboardButton::ID;

void keyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButton");
    s.store_field("text", text_);
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_object_field("style", static_cast<const BaseObject *>(style_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

locationAddress::locationAddress()
  : country_code_()
  , state_()
  , city_()
  , street_()
{}

locationAddress::locationAddress(string const &country_code_, string const &state_, string const &city_, string const &street_)
  : country_code_(country_code_)
  , state_(state_)
  , city_(city_)
  , street_(street_)
{}

const std::int32_t locationAddress::ID;

void locationAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "locationAddress");
    s.store_field("country_code", country_code_);
    s.store_field("state", state_);
    s.store_field("city", city_);
    s.store_field("street", street_);
    s.store_class_end();
  }
}

messageCalendarDay::messageCalendarDay()
  : total_count_()
  , message_()
{}

messageCalendarDay::messageCalendarDay(int32 total_count_, object_ptr<message> &&message_)
  : total_count_(total_count_)
  , message_(std::move(message_))
{}

const std::int32_t messageCalendarDay::ID;

void messageCalendarDay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCalendarDay");
    s.store_field("total_count", total_count_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

notification::notification()
  : id_()
  , date_()
  , is_silent_()
  , type_()
{}

notification::notification(int32 id_, int32 date_, bool is_silent_, object_ptr<NotificationType> &&type_)
  : id_(id_)
  , date_(date_)
  , is_silent_(is_silent_)
  , type_(std::move(type_))
{}

const std::int32_t notification::ID;

void notification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notification");
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_field("is_silent", is_silent_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

oauthLinkInfo::oauthLinkInfo()
  : user_id_()
  , url_()
  , domain_()
  , from_app_()
  , verified_app_name_()
  , bot_user_id_()
  , request_write_access_()
  , request_phone_number_access_()
  , request_ton_wallet_access_()
  , dapp_client_id_()
  , ton_connect_manifest_url_()
  , ton_proof_payload_()
  , browser_()
  , platform_()
  , ip_address_()
  , location_()
  , match_code_first_()
  , match_codes_()
{}

oauthLinkInfo::oauthLinkInfo(int53 user_id_, string const &url_, string const &domain_, bool from_app_, string const &verified_app_name_, int53 bot_user_id_, bool request_write_access_, bool request_phone_number_access_, bool request_ton_wallet_access_, string const &dapp_client_id_, string const &ton_connect_manifest_url_, string const &ton_proof_payload_, string const &browser_, string const &platform_, string const &ip_address_, string const &location_, bool match_code_first_, array<string> &&match_codes_)
  : user_id_(user_id_)
  , url_(url_)
  , domain_(domain_)
  , from_app_(from_app_)
  , verified_app_name_(verified_app_name_)
  , bot_user_id_(bot_user_id_)
  , request_write_access_(request_write_access_)
  , request_phone_number_access_(request_phone_number_access_)
  , request_ton_wallet_access_(request_ton_wallet_access_)
  , dapp_client_id_(dapp_client_id_)
  , ton_connect_manifest_url_(ton_connect_manifest_url_)
  , ton_proof_payload_(ton_proof_payload_)
  , browser_(browser_)
  , platform_(platform_)
  , ip_address_(ip_address_)
  , location_(location_)
  , match_code_first_(match_code_first_)
  , match_codes_(std::move(match_codes_))
{}

const std::int32_t oauthLinkInfo::ID;

void oauthLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "oauthLinkInfo");
    s.store_field("user_id", user_id_);
    s.store_field("url", url_);
    s.store_field("domain", domain_);
    s.store_field("from_app", from_app_);
    s.store_field("verified_app_name", verified_app_name_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("request_write_access", request_write_access_);
    s.store_field("request_phone_number_access", request_phone_number_access_);
    s.store_field("request_ton_wallet_access", request_ton_wallet_access_);
    s.store_field("dapp_client_id", dapp_client_id_);
    s.store_field("ton_connect_manifest_url", ton_connect_manifest_url_);
    s.store_field("ton_proof_payload", ton_proof_payload_);
    s.store_field("browser", browser_);
    s.store_field("platform", platform_);
    s.store_field("ip_address", ip_address_);
    s.store_field("location", location_);
    s.store_field("match_code_first", match_code_first_);
    { s.store_vector_begin("match_codes", match_codes_.size()); for (const auto &_value : match_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

onRampPaymentMethod::onRampPaymentMethod()
  : name_()
  , is_available_()
{}

onRampPaymentMethod::onRampPaymentMethod(string const &name_, bool is_available_)
  : name_(name_)
  , is_available_(is_available_)
{}

const std::int32_t onRampPaymentMethod::ID;

void onRampPaymentMethod::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onRampPaymentMethod");
    s.store_field("name", name_);
    s.store_field("is_available", is_available_);
    s.store_class_end();
  }
}

pageBlockHorizontalAlignmentLeft::pageBlockHorizontalAlignmentLeft() {
}

const std::int32_t pageBlockHorizontalAlignmentLeft::ID;

void pageBlockHorizontalAlignmentLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHorizontalAlignmentLeft");
    s.store_class_end();
  }
}

pageBlockHorizontalAlignmentCenter::pageBlockHorizontalAlignmentCenter() {
}

const std::int32_t pageBlockHorizontalAlignmentCenter::ID;

void pageBlockHorizontalAlignmentCenter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHorizontalAlignmentCenter");
    s.store_class_end();
  }
}

pageBlockHorizontalAlignmentRight::pageBlockHorizontalAlignmentRight() {
}

const std::int32_t pageBlockHorizontalAlignmentRight::ID;

void pageBlockHorizontalAlignmentRight::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHorizontalAlignmentRight");
    s.store_class_end();
  }
}

passportAuthorizationForm::passportAuthorizationForm()
  : id_()
  , required_elements_()
  , privacy_policy_url_()
{}

passportAuthorizationForm::passportAuthorizationForm(int32 id_, array<object_ptr<passportRequiredElement>> &&required_elements_, string const &privacy_policy_url_)
  : id_(id_)
  , required_elements_(std::move(required_elements_))
  , privacy_policy_url_(privacy_policy_url_)
{}

const std::int32_t passportAuthorizationForm::ID;

void passportAuthorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportAuthorizationForm");
    s.store_field("id", id_);
    { s.store_vector_begin("required_elements", required_elements_.size()); for (const auto &_value : required_elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("privacy_policy_url", privacy_policy_url_);
    s.store_class_end();
  }
}

passportElementPersonalDetails::passportElementPersonalDetails()
  : personal_details_()
{}

passportElementPersonalDetails::passportElementPersonalDetails(object_ptr<personalDetails> &&personal_details_)
  : personal_details_(std::move(personal_details_))
{}

const std::int32_t passportElementPersonalDetails::ID;

void passportElementPersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPersonalDetails");
    s.store_object_field("personal_details", static_cast<const BaseObject *>(personal_details_.get()));
    s.store_class_end();
  }
}

passportElementPassport::passportElementPassport()
  : passport_()
{}

passportElementPassport::passportElementPassport(object_ptr<identityDocument> &&passport_)
  : passport_(std::move(passport_))
{}

const std::int32_t passportElementPassport::ID;

void passportElementPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPassport");
    s.store_object_field("passport", static_cast<const BaseObject *>(passport_.get()));
    s.store_class_end();
  }
}

passportElementDriverLicense::passportElementDriverLicense()
  : driver_license_()
{}

passportElementDriverLicense::passportElementDriverLicense(object_ptr<identityDocument> &&driver_license_)
  : driver_license_(std::move(driver_license_))
{}

const std::int32_t passportElementDriverLicense::ID;

void passportElementDriverLicense::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementDriverLicense");
    s.store_object_field("driver_license", static_cast<const BaseObject *>(driver_license_.get()));
    s.store_class_end();
  }
}

passportElementIdentityCard::passportElementIdentityCard()
  : identity_card_()
{}

passportElementIdentityCard::passportElementIdentityCard(object_ptr<identityDocument> &&identity_card_)
  : identity_card_(std::move(identity_card_))
{}

const std::int32_t passportElementIdentityCard::ID;

void passportElementIdentityCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementIdentityCard");
    s.store_object_field("identity_card", static_cast<const BaseObject *>(identity_card_.get()));
    s.store_class_end();
  }
}

passportElementInternalPassport::passportElementInternalPassport()
  : internal_passport_()
{}

passportElementInternalPassport::passportElementInternalPassport(object_ptr<identityDocument> &&internal_passport_)
  : internal_passport_(std::move(internal_passport_))
{}

const std::int32_t passportElementInternalPassport::ID;

void passportElementInternalPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementInternalPassport");
    s.store_object_field("internal_passport", static_cast<const BaseObject *>(internal_passport_.get()));
    s.store_class_end();
  }
}

passportElementAddress::passportElementAddress()
  : address_()
{}

passportElementAddress::passportElementAddress(object_ptr<address> &&address_)
  : address_(std::move(address_))
{}

const std::int32_t passportElementAddress::ID;

void passportElementAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementAddress");
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_class_end();
  }
}

passportElementUtilityBill::passportElementUtilityBill()
  : utility_bill_()
{}

passportElementUtilityBill::passportElementUtilityBill(object_ptr<personalDocument> &&utility_bill_)
  : utility_bill_(std::move(utility_bill_))
{}

const std::int32_t passportElementUtilityBill::ID;

void passportElementUtilityBill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementUtilityBill");
    s.store_object_field("utility_bill", static_cast<const BaseObject *>(utility_bill_.get()));
    s.store_class_end();
  }
}

passportElementBankStatement::passportElementBankStatement()
  : bank_statement_()
{}

passportElementBankStatement::passportElementBankStatement(object_ptr<personalDocument> &&bank_statement_)
  : bank_statement_(std::move(bank_statement_))
{}

const std::int32_t passportElementBankStatement::ID;

void passportElementBankStatement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementBankStatement");
    s.store_object_field("bank_statement", static_cast<const BaseObject *>(bank_statement_.get()));
    s.store_class_end();
  }
}

passportElementRentalAgreement::passportElementRentalAgreement()
  : rental_agreement_()
{}

passportElementRentalAgreement::passportElementRentalAgreement(object_ptr<personalDocument> &&rental_agreement_)
  : rental_agreement_(std::move(rental_agreement_))
{}

const std::int32_t passportElementRentalAgreement::ID;

void passportElementRentalAgreement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementRentalAgreement");
    s.store_object_field("rental_agreement", static_cast<const BaseObject *>(rental_agreement_.get()));
    s.store_class_end();
  }
}

passportElementPassportRegistration::passportElementPassportRegistration()
  : passport_registration_()
{}

passportElementPassportRegistration::passportElementPassportRegistration(object_ptr<personalDocument> &&passport_registration_)
  : passport_registration_(std::move(passport_registration_))
{}

const std::int32_t passportElementPassportRegistration::ID;

void passportElementPassportRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPassportRegistration");
    s.store_object_field("passport_registration", static_cast<const BaseObject *>(passport_registration_.get()));
    s.store_class_end();
  }
}

passportElementTemporaryRegistration::passportElementTemporaryRegistration()
  : temporary_registration_()
{}

passportElementTemporaryRegistration::passportElementTemporaryRegistration(object_ptr<personalDocument> &&temporary_registration_)
  : temporary_registration_(std::move(temporary_registration_))
{}

const std::int32_t passportElementTemporaryRegistration::ID;

void passportElementTemporaryRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTemporaryRegistration");
    s.store_object_field("temporary_registration", static_cast<const BaseObject *>(temporary_registration_.get()));
    s.store_class_end();
  }
}

passportElementPhoneNumber::passportElementPhoneNumber()
  : phone_number_()
{}

passportElementPhoneNumber::passportElementPhoneNumber(string const &phone_number_)
  : phone_number_(phone_number_)
{}

const std::int32_t passportElementPhoneNumber::ID;

void passportElementPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

passportElementEmailAddress::passportElementEmailAddress()
  : email_address_()
{}

passportElementEmailAddress::passportElementEmailAddress(string const &email_address_)
  : email_address_(email_address_)
{}

const std::int32_t passportElementEmailAddress::ID;

void passportElementEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementEmailAddress");
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

passportSuitableElement::passportSuitableElement()
  : type_()
  , is_selfie_required_()
  , is_translation_required_()
  , is_native_name_required_()
{}

passportSuitableElement::passportSuitableElement(object_ptr<PassportElementType> &&type_, bool is_selfie_required_, bool is_translation_required_, bool is_native_name_required_)
  : type_(std::move(type_))
  , is_selfie_required_(is_selfie_required_)
  , is_translation_required_(is_translation_required_)
  , is_native_name_required_(is_native_name_required_)
{}

const std::int32_t passportSuitableElement::ID;

void passportSuitableElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportSuitableElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("is_selfie_required", is_selfie_required_);
    s.store_field("is_translation_required", is_translation_required_);
    s.store_field("is_native_name_required", is_native_name_required_);
    s.store_class_end();
  }
}

paymentProviderSmartGlocal::paymentProviderSmartGlocal()
  : public_token_()
  , tokenize_url_()
{}

paymentProviderSmartGlocal::paymentProviderSmartGlocal(string const &public_token_, string const &tokenize_url_)
  : public_token_(public_token_)
  , tokenize_url_(tokenize_url_)
{}

const std::int32_t paymentProviderSmartGlocal::ID;

void paymentProviderSmartGlocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentProviderSmartGlocal");
    s.store_field("public_token", "[REDACTED]");
    s.store_field("tokenize_url", tokenize_url_);
    s.store_class_end();
  }
}

paymentProviderStripe::paymentProviderStripe()
  : publishable_key_()
  , need_country_()
  , need_postal_code_()
  , need_cardholder_name_()
{}

paymentProviderStripe::paymentProviderStripe(string const &publishable_key_, bool need_country_, bool need_postal_code_, bool need_cardholder_name_)
  : publishable_key_(publishable_key_)
  , need_country_(need_country_)
  , need_postal_code_(need_postal_code_)
  , need_cardholder_name_(need_cardholder_name_)
{}

const std::int32_t paymentProviderStripe::ID;

void paymentProviderStripe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentProviderStripe");
    s.store_field("publishable_key", publishable_key_);
    s.store_field("need_country", need_country_);
    s.store_field("need_postal_code", need_postal_code_);
    s.store_field("need_cardholder_name", need_cardholder_name_);
    s.store_class_end();
  }
}

paymentProviderOther::paymentProviderOther()
  : url_()
{}

paymentProviderOther::paymentProviderOther(string const &url_)
  : url_(url_)
{}

const std::int32_t paymentProviderOther::ID;

void paymentProviderOther::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentProviderOther");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

phoneNumberAuthenticationSettings::phoneNumberAuthenticationSettings()
  : allow_flash_call_()
  , allow_missed_call_()
  , is_current_phone_number_()
  , has_unknown_phone_number_()
  , allow_sms_retriever_api_()
  , firebase_authentication_settings_()
  , authentication_tokens_()
{}

phoneNumberAuthenticationSettings::phoneNumberAuthenticationSettings(bool allow_flash_call_, bool allow_missed_call_, bool is_current_phone_number_, bool has_unknown_phone_number_, bool allow_sms_retriever_api_, object_ptr<FirebaseAuthenticationSettings> &&firebase_authentication_settings_, array<string> &&authentication_tokens_)
  : allow_flash_call_(allow_flash_call_)
  , allow_missed_call_(allow_missed_call_)
  , is_current_phone_number_(is_current_phone_number_)
  , has_unknown_phone_number_(has_unknown_phone_number_)
  , allow_sms_retriever_api_(allow_sms_retriever_api_)
  , firebase_authentication_settings_(std::move(firebase_authentication_settings_))
  , authentication_tokens_(std::move(authentication_tokens_))
{}

const std::int32_t phoneNumberAuthenticationSettings::ID;

void phoneNumberAuthenticationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberAuthenticationSettings");
    s.store_field("allow_flash_call", allow_flash_call_);
    s.store_field("allow_missed_call", allow_missed_call_);
    s.store_field("is_current_phone_number", is_current_phone_number_);
    s.store_field("has_unknown_phone_number", has_unknown_phone_number_);
    s.store_field("allow_sms_retriever_api", allow_sms_retriever_api_);
    s.store_object_field("firebase_authentication_settings", static_cast<const BaseObject *>(firebase_authentication_settings_.get()));
    s.store_field("authentication_tokens", "[REDACTED]");
    s.store_class_end();
  }
}

pollVoter::pollVoter()
  : voter_id_()
  , date_()
{}

pollVoter::pollVoter(object_ptr<MessageSender> &&voter_id_, int32 date_)
  : voter_id_(std::move(voter_id_))
  , date_(date_)
{}

const std::int32_t pollVoter::ID;

void pollVoter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollVoter");
    s.store_object_field("voter_id", static_cast<const BaseObject *>(voter_id_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

pollVoters::pollVoters()
  : total_count_()
  , voters_()
{}

pollVoters::pollVoters(int32 total_count_, array<object_ptr<pollVoter>> &&voters_)
  : total_count_(total_count_)
  , voters_(std::move(voters_))
{}

const std::int32_t pollVoters::ID;

void pollVoters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollVoters");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("voters", voters_.size()); for (const auto &_value : voters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

scopeNotificationSettings::scopeNotificationSettings()
  : mute_for_()
  , sound_id_()
  , show_preview_()
  , use_default_mute_stories_()
  , mute_stories_()
  , story_sound_id_()
  , show_story_poster_()
  , disable_pinned_message_notifications_()
  , disable_mention_notifications_()
{}

scopeNotificationSettings::scopeNotificationSettings(int32 mute_for_, int64 sound_id_, bool show_preview_, bool use_default_mute_stories_, bool mute_stories_, int64 story_sound_id_, bool show_story_poster_, bool disable_pinned_message_notifications_, bool disable_mention_notifications_)
  : mute_for_(mute_for_)
  , sound_id_(sound_id_)
  , show_preview_(show_preview_)
  , use_default_mute_stories_(use_default_mute_stories_)
  , mute_stories_(mute_stories_)
  , story_sound_id_(story_sound_id_)
  , show_story_poster_(show_story_poster_)
  , disable_pinned_message_notifications_(disable_pinned_message_notifications_)
  , disable_mention_notifications_(disable_mention_notifications_)
{}

const std::int32_t scopeNotificationSettings::ID;

void scopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "scopeNotificationSettings");
    s.store_field("mute_for", mute_for_);
    s.store_field("sound_id", sound_id_);
    s.store_field("show_preview", show_preview_);
    s.store_field("use_default_mute_stories", use_default_mute_stories_);
    s.store_field("mute_stories", mute_stories_);
    s.store_field("story_sound_id", story_sound_id_);
    s.store_field("show_story_poster", show_story_poster_);
    s.store_field("disable_pinned_message_notifications", disable_pinned_message_notifications_);
    s.store_field("disable_mention_notifications", disable_mention_notifications_);
    s.store_class_end();
  }
}

searchMessagesChatTypeFilterPrivate::searchMessagesChatTypeFilterPrivate() {
}

const std::int32_t searchMessagesChatTypeFilterPrivate::ID;

void searchMessagesChatTypeFilterPrivate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesChatTypeFilterPrivate");
    s.store_class_end();
  }
}

searchMessagesChatTypeFilterGroup::searchMessagesChatTypeFilterGroup() {
}

const std::int32_t searchMessagesChatTypeFilterGroup::ID;

void searchMessagesChatTypeFilterGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesChatTypeFilterGroup");
    s.store_class_end();
  }
}

searchMessagesChatTypeFilterChannel::searchMessagesChatTypeFilterChannel() {
}

const std::int32_t searchMessagesChatTypeFilterChannel::ID;

void searchMessagesChatTypeFilterChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesChatTypeFilterChannel");
    s.store_class_end();
  }
}

searchMessagesChatTypeFilterCommunity::searchMessagesChatTypeFilterCommunity()
  : community_id_()
{}

searchMessagesChatTypeFilterCommunity::searchMessagesChatTypeFilterCommunity(int53 community_id_)
  : community_id_(community_id_)
{}

const std::int32_t searchMessagesChatTypeFilterCommunity::ID;

void searchMessagesChatTypeFilterCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesChatTypeFilterCommunity");
    s.store_field("community_id", community_id_);
    s.store_class_end();
  }
}

sharedChat::sharedChat()
  : chat_id_()
  , title_()
  , username_()
  , photo_()
{}

sharedChat::sharedChat(int53 chat_id_, string const &title_, string const &username_, object_ptr<photo> &&photo_)
  : chat_id_(chat_id_)
  , title_(title_)
  , username_(username_)
  , photo_(std::move(photo_))
{}

const std::int32_t sharedChat::ID;

void sharedChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sharedChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_field("username", username_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

sponsoredChat::sponsoredChat()
  : unique_id_()
  , chat_id_()
  , sponsor_info_()
  , additional_info_()
{}

sponsoredChat::sponsoredChat(int53 unique_id_, int53 chat_id_, string const &sponsor_info_, string const &additional_info_)
  : unique_id_(unique_id_)
  , chat_id_(chat_id_)
  , sponsor_info_(sponsor_info_)
  , additional_info_(additional_info_)
{}

const std::int32_t sponsoredChat::ID;

void sponsoredChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredChat");
    s.store_field("unique_id", unique_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("sponsor_info", sponsor_info_);
    s.store_field("additional_info", additional_info_);
    s.store_class_end();
  }
}

starGiveawayWinnerOption::starGiveawayWinnerOption()
  : winner_count_()
  , won_star_count_()
  , is_default_()
{}

starGiveawayWinnerOption::starGiveawayWinnerOption(int32 winner_count_, int53 won_star_count_, bool is_default_)
  : winner_count_(winner_count_)
  , won_star_count_(won_star_count_)
  , is_default_(is_default_)
{}

const std::int32_t starGiveawayWinnerOption::ID;

void starGiveawayWinnerOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiveawayWinnerOption");
    s.store_field("winner_count", winner_count_);
    s.store_field("won_star_count", won_star_count_);
    s.store_field("is_default", is_default_);
    s.store_class_end();
  }
}

stickerSet::stickerSet()
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
  , stickers_()
  , emojis_()
{}

stickerSet::stickerSet(int64 id_, string const &title_, string const &name_, object_ptr<thumbnail> &&thumbnail_, object_ptr<outline> &&thumbnail_outline_, bool is_owned_, bool is_installed_, bool is_archived_, bool is_official_, object_ptr<StickerType> &&sticker_type_, bool needs_repainting_, bool is_allowed_as_chat_emoji_status_, bool is_viewed_, array<object_ptr<sticker>> &&stickers_, array<object_ptr<emojis>> &&emojis_)
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
  , stickers_(std::move(stickers_))
  , emojis_(std::move(emojis_))
{}

const std::int32_t stickerSet::ID;

void stickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSet");
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
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stickerTypeRegular::stickerTypeRegular() {
}

const std::int32_t stickerTypeRegular::ID;

void stickerTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerTypeRegular");
    s.store_class_end();
  }
}

stickerTypeMask::stickerTypeMask() {
}

const std::int32_t stickerTypeMask::ID;

void stickerTypeMask::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerTypeMask");
    s.store_class_end();
  }
}

stickerTypeCustomEmoji::stickerTypeCustomEmoji() {
}

const std::int32_t stickerTypeCustomEmoji::ID;

void stickerTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerTypeCustomEmoji");
    s.store_class_end();
  }
}

stickers::stickers()
  : stickers_()
{}

stickers::stickers(array<object_ptr<sticker>> &&stickers_)
  : stickers_(std::move(stickers_))
{}

const std::int32_t stickers::ID;

void stickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers");
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storageStatisticsByChat::storageStatisticsByChat()
  : chat_id_()
  , size_()
  , count_()
  , by_file_type_()
{}

storageStatisticsByChat::storageStatisticsByChat(int53 chat_id_, int53 size_, int32 count_, array<object_ptr<storageStatisticsByFileType>> &&by_file_type_)
  : chat_id_(chat_id_)
  , size_(size_)
  , count_(count_)
  , by_file_type_(std::move(by_file_type_))
{}

const std::int32_t storageStatisticsByChat::ID;

void storageStatisticsByChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatisticsByChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("size", size_);
    s.store_field("count", count_);
    { s.store_vector_begin("by_file_type", by_file_type_.size()); for (const auto &_value : by_file_type_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyVideo::storyVideo()
  : duration_()
  , width_()
  , height_()
  , has_stickers_()
  , is_animation_()
  , minithumbnail_()
  , thumbnail_()
  , preload_prefix_size_()
  , cover_frame_timestamp_()
  , video_()
{}

storyVideo::storyVideo(double duration_, int32 width_, int32 height_, bool has_stickers_, bool is_animation_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, int32 preload_prefix_size_, double cover_frame_timestamp_, object_ptr<file> &&video_)
  : duration_(duration_)
  , width_(width_)
  , height_(height_)
  , has_stickers_(has_stickers_)
  , is_animation_(is_animation_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , preload_prefix_size_(preload_prefix_size_)
  , cover_frame_timestamp_(cover_frame_timestamp_)
  , video_(std::move(video_))
{}

const std::int32_t storyVideo::ID;

void storyVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyVideo");
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("has_stickers", has_stickers_);
    s.store_field("is_animation", is_animation_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("preload_prefix_size", preload_prefix_size_);
    s.store_field("cover_frame_timestamp", cover_frame_timestamp_);
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

supergroup::supergroup()
  : id_()
  , usernames_()
  , date_()
  , status_()
  , member_count_()
  , boost_level_()
  , has_automatic_translation_()
  , has_linked_chat_()
  , has_location_()
  , sign_messages_()
  , show_message_sender_()
  , join_to_send_messages_()
  , join_by_request_()
  , is_slow_mode_enabled_()
  , is_channel_()
  , is_broadcast_group_()
  , is_forum_()
  , is_direct_messages_group_()
  , is_administered_direct_messages_group_()
  , verification_status_()
  , has_direct_messages_group_()
  , has_forum_tabs_()
  , has_forum_sidebar_()
  , restriction_info_()
  , paid_message_star_count_()
  , active_story_state_()
{}

supergroup::supergroup(int53 id_, object_ptr<usernames> &&usernames_, int32 date_, object_ptr<ChatMemberStatus> &&status_, int32 member_count_, int32 boost_level_, bool has_automatic_translation_, bool has_linked_chat_, bool has_location_, bool sign_messages_, bool show_message_sender_, bool join_to_send_messages_, bool join_by_request_, bool is_slow_mode_enabled_, bool is_channel_, bool is_broadcast_group_, bool is_forum_, bool is_direct_messages_group_, bool is_administered_direct_messages_group_, object_ptr<verificationStatus> &&verification_status_, bool has_direct_messages_group_, bool has_forum_tabs_, bool has_forum_sidebar_, object_ptr<restrictionInfo> &&restriction_info_, int53 paid_message_star_count_, object_ptr<ActiveStoryState> &&active_story_state_)
  : id_(id_)
  , usernames_(std::move(usernames_))
  , date_(date_)
  , status_(std::move(status_))
  , member_count_(member_count_)
  , boost_level_(boost_level_)
  , has_automatic_translation_(has_automatic_translation_)
  , has_linked_chat_(has_linked_chat_)
  , has_location_(has_location_)
  , sign_messages_(sign_messages_)
  , show_message_sender_(show_message_sender_)
  , join_to_send_messages_(join_to_send_messages_)
  , join_by_request_(join_by_request_)
  , is_slow_mode_enabled_(is_slow_mode_enabled_)
  , is_channel_(is_channel_)
  , is_broadcast_group_(is_broadcast_group_)
  , is_forum_(is_forum_)
  , is_direct_messages_group_(is_direct_messages_group_)
  , is_administered_direct_messages_group_(is_administered_direct_messages_group_)
  , verification_status_(std::move(verification_status_))
  , has_direct_messages_group_(has_direct_messages_group_)
  , has_forum_tabs_(has_forum_tabs_)
  , has_forum_sidebar_(has_forum_sidebar_)
  , restriction_info_(std::move(restriction_info_))
  , paid_message_star_count_(paid_message_star_count_)
  , active_story_state_(std::move(active_story_state_))
{}

const std::int32_t supergroup::ID;

void supergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroup");
    s.store_field("id", id_);
    s.store_object_field("usernames", static_cast<const BaseObject *>(usernames_.get()));
    s.store_field("date", date_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("member_count", member_count_);
    s.store_field("boost_level", boost_level_);
    s.store_field("has_automatic_translation", has_automatic_translation_);
    s.store_field("has_linked_chat", has_linked_chat_);
    s.store_field("has_location", has_location_);
    s.store_field("sign_messages", sign_messages_);
    s.store_field("show_message_sender", show_message_sender_);
    s.store_field("join_to_send_messages", join_to_send_messages_);
    s.store_field("join_by_request", join_by_request_);
    s.store_field("is_slow_mode_enabled", is_slow_mode_enabled_);
    s.store_field("is_channel", is_channel_);
    s.store_field("is_broadcast_group", is_broadcast_group_);
    s.store_field("is_forum", is_forum_);
    s.store_field("is_direct_messages_group", is_direct_messages_group_);
    s.store_field("is_administered_direct_messages_group", is_administered_direct_messages_group_);
    s.store_object_field("verification_status", static_cast<const BaseObject *>(verification_status_.get()));
    s.store_field("has_direct_messages_group", has_direct_messages_group_);
    s.store_field("has_forum_tabs", has_forum_tabs_);
    s.store_field("has_forum_sidebar", has_forum_sidebar_);
    s.store_object_field("restriction_info", static_cast<const BaseObject *>(restriction_info_.get()));
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_object_field("active_story_state", static_cast<const BaseObject *>(active_story_state_.get()));
    s.store_class_end();
  }
}

testInt::testInt()
  : value_()
{}

testInt::testInt(int32 value_)
  : value_(value_)
{}

const std::int32_t testInt::ID;

void testInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testInt");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

testVectorInt::testVectorInt()
  : value_()
{}

testVectorInt::testVectorInt(array<int32> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorInt::ID;

void testVectorInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorInt");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

tonCenterStreamingApiUrl::tonCenterStreamingApiUrl()
  : url_()
  , expires_in_()
{}

tonCenterStreamingApiUrl::tonCenterStreamingApiUrl(string const &url_, int32 expires_in_)
  : url_(url_)
  , expires_in_(expires_in_)
{}

const std::int32_t tonCenterStreamingApiUrl::ID;

void tonCenterStreamingApiUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonCenterStreamingApiUrl");
    s.store_field("url", url_);
    s.store_field("expires_in", expires_in_);
    s.store_class_end();
  }
}

tonConnectRequestStatePending::tonConnectRequestStatePending()
  : expiration_date_()
{}

tonConnectRequestStatePending::tonConnectRequestStatePending(int32 expiration_date_)
  : expiration_date_(expiration_date_)
{}

const std::int32_t tonConnectRequestStatePending::ID;

void tonConnectRequestStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectRequestStatePending");
    s.store_field("expiration_date", expiration_date_);
    s.store_class_end();
  }
}

tonConnectRequestStateAccepted::tonConnectRequestStateAccepted() {
}

const std::int32_t tonConnectRequestStateAccepted::ID;

void tonConnectRequestStateAccepted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectRequestStateAccepted");
    s.store_class_end();
  }
}

tonConnectRequestStateRejected::tonConnectRequestStateRejected() {
}

const std::int32_t tonConnectRequestStateRejected::ID;

void tonConnectRequestStateRejected::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectRequestStateRejected");
    s.store_class_end();
  }
}

tonConnectSessions::tonConnectSessions()
  : sessions_()
{}

tonConnectSessions::tonConnectSessions(array<object_ptr<tonConnectSession>> &&sessions_)
  : sessions_(std::move(sessions_))
{}

const std::int32_t tonConnectSessions::ID;

void tonConnectSessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectSessions");
    { s.store_vector_begin("sessions", sessions_.size()); for (const auto &_value : sessions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

tonNftAttribute::tonNftAttribute()
  : trait_type_()
  , value_()
{}

tonNftAttribute::tonNftAttribute(string const &trait_type_, string const &value_)
  : trait_type_(trait_type_)
  , value_(value_)
{}

const std::int32_t tonNftAttribute::ID;

void tonNftAttribute::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonNftAttribute");
    s.store_field("trait_type", trait_type_);
    s.store_field("value", value_);
    s.store_class_end();
  }
}

unreadReaction::unreadReaction()
  : type_()
  , sender_id_()
  , is_big_()
{}

unreadReaction::unreadReaction(object_ptr<ReactionType> &&type_, object_ptr<MessageSender> &&sender_id_, bool is_big_)
  : type_(std::move(type_))
  , sender_id_(std::move(sender_id_))
  , is_big_(is_big_)
{}

const std::int32_t unreadReaction::ID;

void unreadReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unreadReaction");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("is_big", is_big_);
    s.store_class_end();
  }
}

videoMessageAdvertisements::videoMessageAdvertisements()
  : advertisements_()
  , start_delay_()
  , between_delay_()
{}

videoMessageAdvertisements::videoMessageAdvertisements(array<object_ptr<videoMessageAdvertisement>> &&advertisements_, int32 start_delay_, int32 between_delay_)
  : advertisements_(std::move(advertisements_))
  , start_delay_(start_delay_)
  , between_delay_(between_delay_)
{}

const std::int32_t videoMessageAdvertisements::ID;

void videoMessageAdvertisements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoMessageAdvertisements");
    { s.store_vector_begin("advertisements", advertisements_.size()); for (const auto &_value : advertisements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("start_delay", start_delay_);
    s.store_field("between_delay", between_delay_);
    s.store_class_end();
  }
}

walletBotBalance::walletBotBalance()
  : has_balance_()
  , url_()
{}

walletBotBalance::walletBotBalance(bool has_balance_, string const &url_)
  : has_balance_(has_balance_)
  , url_(url_)
{}

const std::int32_t walletBotBalance::ID;

void walletBotBalance::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletBotBalance");
    s.store_field("has_balance", has_balance_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

webAppOpenModeCompact::webAppOpenModeCompact() {
}

const std::int32_t webAppOpenModeCompact::ID;

void webAppOpenModeCompact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppOpenModeCompact");
    s.store_class_end();
  }
}

webAppOpenModeFullSize::webAppOpenModeFullSize() {
}

const std::int32_t webAppOpenModeFullSize::ID;

void webAppOpenModeFullSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppOpenModeFullSize");
    s.store_class_end();
  }
}

webAppOpenModeFullScreen::webAppOpenModeFullScreen() {
}

const std::int32_t webAppOpenModeFullScreen::ID;

void webAppOpenModeFullScreen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppOpenModeFullScreen");
    s.store_class_end();
  }
}

webBrowserTypeExternal::webBrowserTypeExternal() {
}

const std::int32_t webBrowserTypeExternal::ID;

void webBrowserTypeExternal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webBrowserTypeExternal");
    s.store_class_end();
  }
}

webBrowserTypeInApp::webBrowserTypeInApp() {
}

const std::int32_t webBrowserTypeInApp::ID;

void webBrowserTypeInApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webBrowserTypeInApp");
    s.store_class_end();
  }
}

welcomeMessage::welcomeMessage()
  : id_()
  , content_()
{}

welcomeMessage::welcomeMessage(int32 id_, object_ptr<MessageContent> &&content_)
  : id_(id_)
  , content_(std::move(content_))
{}

const std::int32_t welcomeMessage::ID;

void welcomeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "welcomeMessage");
    s.store_field("id", id_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

widgetQueryTypeData::widgetQueryTypeData()
  : with_wallet_()
{}

widgetQueryTypeData::widgetQueryTypeData(bool with_wallet_)
  : with_wallet_(with_wallet_)
{}

const std::int32_t widgetQueryTypeData::ID;

void widgetQueryTypeData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "widgetQueryTypeData");
    s.store_field("with_wallet", with_wallet_);
    s.store_class_end();
  }
}

widgetQueryTypeSignData::widgetQueryTypeSignData()
  : wallet_()
  , sign_data_()
{}

widgetQueryTypeSignData::widgetQueryTypeSignData(object_ptr<widgetQueryWallet> &&wallet_, string const &sign_data_)
  : wallet_(std::move(wallet_))
  , sign_data_(sign_data_)
{}

const std::int32_t widgetQueryTypeSignData::ID;

void widgetQueryTypeSignData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "widgetQueryTypeSignData");
    s.store_object_field("wallet", static_cast<const BaseObject *>(wallet_.get()));
    s.store_field("sign_data", sign_data_);
    s.store_class_end();
  }
}

widgetQueryTypeSentTransaction::widgetQueryTypeSentTransaction()
  : wallet_()
  , msg_hash_()
{}

widgetQueryTypeSentTransaction::widgetQueryTypeSentTransaction(object_ptr<widgetQueryWallet> &&wallet_, string const &msg_hash_)
  : wallet_(std::move(wallet_))
  , msg_hash_(msg_hash_)
{}

const std::int32_t widgetQueryTypeSentTransaction::ID;

void widgetQueryTypeSentTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "widgetQueryTypeSentTransaction");
    s.store_object_field("wallet", static_cast<const BaseObject *>(wallet_.get()));
    s.store_field("msg_hash", msg_hash_);
    s.store_class_end();
  }
}

addChatMember::addChatMember()
  : chat_id_()
  , user_id_()
  , forward_limit_()
{}

addChatMember::addChatMember(int53 chat_id_, int53 user_id_, int32 forward_limit_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
  , forward_limit_(forward_limit_)
{}

const std::int32_t addChatMember::ID;

void addChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("forward_limit", forward_limit_);
    s.store_class_end();
  }
}

addMessageReaction::addMessageReaction()
  : chat_id_()
  , message_id_()
  , reaction_type_()
  , is_big_()
  , update_recent_reactions_()
{}

addMessageReaction::addMessageReaction(int53 chat_id_, int53 message_id_, object_ptr<ReactionType> &&reaction_type_, bool is_big_, bool update_recent_reactions_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reaction_type_(std::move(reaction_type_))
  , is_big_(is_big_)
  , update_recent_reactions_(update_recent_reactions_)
{}

const std::int32_t addMessageReaction::ID;

void addMessageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addMessageReaction");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("is_big", is_big_);
    s.store_field("update_recent_reactions", update_recent_reactions_);
    s.store_class_end();
  }
}

addNetworkStatistics::addNetworkStatistics()
  : entry_()
{}

addNetworkStatistics::addNetworkStatistics(object_ptr<NetworkStatisticsEntry> &&entry_)
  : entry_(std::move(entry_))
{}

const std::int32_t addNetworkStatistics::ID;

void addNetworkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addNetworkStatistics");
    s.store_object_field("entry", static_cast<const BaseObject *>(entry_.get()));
    s.store_class_end();
  }
}

addWebBrowserSettingsException::addWebBrowserSettingsException()
  : open_external_browser_()
  , url_()
{}

addWebBrowserSettingsException::addWebBrowserSettingsException(bool open_external_browser_, string const &url_)
  : open_external_browser_(open_external_browser_)
  , url_(url_)
{}

const std::int32_t addWebBrowserSettingsException::ID;

void addWebBrowserSettingsException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addWebBrowserSettingsException");
    s.store_field("open_external_browser", open_external_browser_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

answerGuestQuery::answerGuestQuery()
  : guest_query_id_()
  , result_()
{}

answerGuestQuery::answerGuestQuery(int64 guest_query_id_, object_ptr<InputInlineQueryResult> &&result_)
  : guest_query_id_(guest_query_id_)
  , result_(std::move(result_))
{}

const std::int32_t answerGuestQuery::ID;

void answerGuestQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerGuestQuery");
    s.store_field("guest_query_id", guest_query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_class_end();
  }
}

answerTonConnectRequest::answerTonConnectRequest()
  : session_id_()
  , message_id_()
  , trace_id_()
  , body_()
{}

answerTonConnectRequest::answerTonConnectRequest(int64 session_id_, int53 message_id_, string const &trace_id_, bytes const &body_)
  : session_id_(session_id_)
  , message_id_(message_id_)
  , trace_id_(trace_id_)
  , body_(std::move(body_))
{}

const std::int32_t answerTonConnectRequest::ID;

void answerTonConnectRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerTonConnectRequest");
    s.store_field("session_id", session_id_);
    s.store_field("message_id", message_id_);
    s.store_field("trace_id", trace_id_);
    s.store_bytes_field("body", body_);
    s.store_class_end();
  }
}

applyPremiumGiftCode::applyPremiumGiftCode()
  : code_()
{}

applyPremiumGiftCode::applyPremiumGiftCode(string const &code_)
  : code_(code_)
{}

const std::int32_t applyPremiumGiftCode::ID;

void applyPremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "applyPremiumGiftCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

canPostStory::canPostStory()
  : chat_id_()
{}

canPostStory::canPostStory(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t canPostStory::ID;

void canPostStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStory");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

changeImportedContacts::changeImportedContacts()
  : contacts_()
{}

changeImportedContacts::changeImportedContacts(array<object_ptr<importedContact>> &&contacts_)
  : contacts_(std::move(contacts_))
{}

const std::int32_t changeImportedContacts::ID;

void changeImportedContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "changeImportedContacts");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

checkAuthenticationPasswordRecoveryCode::checkAuthenticationPasswordRecoveryCode()
  : recovery_code_()
{}

checkAuthenticationPasswordRecoveryCode::checkAuthenticationPasswordRecoveryCode(string const &recovery_code_)
  : recovery_code_(recovery_code_)
{}

const std::int32_t checkAuthenticationPasswordRecoveryCode::ID;

void checkAuthenticationPasswordRecoveryCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationPasswordRecoveryCode");
    s.store_field("recovery_code", "[REDACTED]");
    s.store_class_end();
  }
}

checkLoginEmailAddressCode::checkLoginEmailAddressCode()
  : code_()
{}

checkLoginEmailAddressCode::checkLoginEmailAddressCode(object_ptr<EmailAddressAuthentication> &&code_)
  : code_(std::move(code_))
{}

const std::int32_t checkLoginEmailAddressCode::ID;

void checkLoginEmailAddressCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkLoginEmailAddressCode");
    s.store_object_field("code", static_cast<const BaseObject *>(code_.get()));
    s.store_class_end();
  }
}

checkPasswordRecoveryCode::checkPasswordRecoveryCode()
  : recovery_code_()
{}

checkPasswordRecoveryCode::checkPasswordRecoveryCode(string const &recovery_code_)
  : recovery_code_(recovery_code_)
{}

const std::int32_t checkPasswordRecoveryCode::ID;

void checkPasswordRecoveryCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkPasswordRecoveryCode");
    s.store_field("recovery_code", "[REDACTED]");
    s.store_class_end();
  }
}

checkWalletBotBalance::checkWalletBotBalance() {
}

const std::int32_t checkWalletBotBalance::ID;

void checkWalletBotBalance::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkWalletBotBalance");
    s.store_class_end();
  }
}

closeChat::closeChat()
  : chat_id_()
{}

closeChat::closeChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t closeChat::ID;

void closeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

confirmBusinessConnectedBot::confirmBusinessConnectedBot()
  : bot_user_id_()
{}

confirmBusinessConnectedBot::confirmBusinessConnectedBot(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t confirmBusinessConnectedBot::ID;

void confirmBusinessConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "confirmBusinessConnectedBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

craftGift::craftGift()
  : received_gift_ids_()
{}

craftGift::craftGift(array<string> &&received_gift_ids_)
  : received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t craftGift::ID;

void craftGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "craftGift");
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

createBusinessChatLink::createBusinessChatLink()
  : link_info_()
{}

createBusinessChatLink::createBusinessChatLink(object_ptr<inputBusinessChatLink> &&link_info_)
  : link_info_(std::move(link_info_))
{}

const std::int32_t createBusinessChatLink::ID;

void createBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createBusinessChatLink");
    s.store_object_field("link_info", static_cast<const BaseObject *>(link_info_.get()));
    s.store_class_end();
  }
}

deleteChatHistory::deleteChatHistory()
  : chat_id_()
  , remove_from_chat_list_()
  , revoke_()
{}

deleteChatHistory::deleteChatHistory(int53 chat_id_, bool remove_from_chat_list_, bool revoke_)
  : chat_id_(chat_id_)
  , remove_from_chat_list_(remove_from_chat_list_)
  , revoke_(revoke_)
{}

const std::int32_t deleteChatHistory::ID;

void deleteChatHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("remove_from_chat_list", remove_from_chat_list_);
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

deleteGift::deleteGift()
  : business_connection_id_()
  , received_gift_id_()
{}

deleteGift::deleteGift(string const &business_connection_id_, string const &received_gift_id_)
  : business_connection_id_(business_connection_id_)
  , received_gift_id_(received_gift_id_)
{}

const std::int32_t deleteGift::ID;

void deleteGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteGift");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

deleteMessageReactionsFromSender::deleteMessageReactionsFromSender()
  : chat_id_()
  , message_id_()
  , sender_id_()
{}

deleteMessageReactionsFromSender::deleteMessageReactionsFromSender(int53 chat_id_, int53 message_id_, object_ptr<MessageSender> &&sender_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , sender_id_(std::move(sender_id_))
{}

const std::int32_t deleteMessageReactionsFromSender::ID;

void deleteMessageReactionsFromSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteMessageReactionsFromSender");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_class_end();
  }
}

deleteProfilePhoto::deleteProfilePhoto()
  : profile_photo_id_()
{}

deleteProfilePhoto::deleteProfilePhoto(int64 profile_photo_id_)
  : profile_photo_id_(profile_photo_id_)
{}

const std::int32_t deleteProfilePhoto::ID;

void deleteProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteProfilePhoto");
    s.store_field("profile_photo_id", profile_photo_id_);
    s.store_class_end();
  }
}

deleteSavedMessagesTopicMessagesByDate::deleteSavedMessagesTopicMessagesByDate()
  : saved_messages_topic_id_()
  , min_date_()
  , max_date_()
{}

deleteSavedMessagesTopicMessagesByDate::deleteSavedMessagesTopicMessagesByDate(int53 saved_messages_topic_id_, int32 min_date_, int32 max_date_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , min_date_(min_date_)
  , max_date_(max_date_)
{}

const std::int32_t deleteSavedMessagesTopicMessagesByDate::ID;

void deleteSavedMessagesTopicMessagesByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteSavedMessagesTopicMessagesByDate");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_class_end();
  }
}

deleteStory::deleteStory()
  : story_poster_chat_id_()
  , story_id_()
{}

deleteStory::deleteStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t deleteStory::ID;

void deleteStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

deleteStoryAlbum::deleteStoryAlbum()
  : chat_id_()
  , story_album_id_()
{}

deleteStoryAlbum::deleteStoryAlbum(int53 chat_id_, int32 story_album_id_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
{}

const std::int32_t deleteStoryAlbum::ID;

void deleteStoryAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteStoryAlbum");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    s.store_class_end();
  }
}

dismissWebToken::dismissWebToken()
  : token_()
{}

dismissWebToken::dismissWebToken(string const &token_)
  : token_(token_)
{}

const std::int32_t dismissWebToken::ID;

void dismissWebToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dismissWebToken");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

editChatSubscriptionInviteLink::editChatSubscriptionInviteLink()
  : chat_id_()
  , invite_link_()
  , name_()
{}

editChatSubscriptionInviteLink::editChatSubscriptionInviteLink(int53 chat_id_, string const &invite_link_, string const &name_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , name_(name_)
{}

const std::int32_t editChatSubscriptionInviteLink::ID;

void editChatSubscriptionInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editChatSubscriptionInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

editChatWelcomeMessage::editChatWelcomeMessage()
  : chat_id_()
  , welcome_message_id_()
  , input_message_content_()
{}

editChatWelcomeMessage::editChatWelcomeMessage(int53 chat_id_, int32 welcome_message_id_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , welcome_message_id_(welcome_message_id_)
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editChatWelcomeMessage::ID;

void editChatWelcomeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editChatWelcomeMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("welcome_message_id", welcome_message_id_);
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editEphemeralMessageCaption::editEphemeralMessageCaption()
  : chat_id_()
  , receiver_user_id_()
  , ephemeral_message_id_()
  , reply_markup_()
  , caption_()
  , show_caption_above_media_()
{}

editEphemeralMessageCaption::editEphemeralMessageCaption(int53 chat_id_, int53 receiver_user_id_, int32 ephemeral_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_)
  : chat_id_(chat_id_)
  , receiver_user_id_(receiver_user_id_)
  , ephemeral_message_id_(ephemeral_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
{}

const std::int32_t editEphemeralMessageCaption::ID;

void editEphemeralMessageCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editEphemeralMessageCaption");
    s.store_field("chat_id", chat_id_);
    s.store_field("receiver_user_id", receiver_user_id_);
    s.store_field("ephemeral_message_id", ephemeral_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_class_end();
  }
}

editMessageLiveLocation::editMessageLiveLocation()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , location_()
{}

editMessageLiveLocation::editMessageLiveLocation(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<liveLocation> &&location_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , location_(std::move(location_))
{}

const std::int32_t editMessageLiveLocation::ID;

void editMessageLiveLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageLiveLocation");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

editMessageWidgetData::editMessageWidgetData()
  : chat_id_()
  , message_id_()
  , edit_public_data_()
  , public_data_()
  , edit_chat_data_()
  , chat_data_()
{}

editMessageWidgetData::editMessageWidgetData(int53 chat_id_, int53 message_id_, bool edit_public_data_, string const &public_data_, bool edit_chat_data_, string const &chat_data_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , edit_public_data_(edit_public_data_)
  , public_data_(public_data_)
  , edit_chat_data_(edit_chat_data_)
  , chat_data_(chat_data_)
{}

const std::int32_t editMessageWidgetData::ID;

void editMessageWidgetData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageWidgetData");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("edit_public_data", edit_public_data_);
    s.store_field("public_data", public_data_);
    s.store_field("edit_chat_data", edit_chat_data_);
    s.store_field("chat_data", chat_data_);
    s.store_class_end();
  }
}

editProxy::editProxy()
  : proxy_id_()
  , proxy_()
  , enable_()
  , comment_()
{}

editProxy::editProxy(int32 proxy_id_, object_ptr<proxy> &&proxy_, bool enable_, string const &comment_)
  : proxy_id_(proxy_id_)
  , proxy_(std::move(proxy_))
  , enable_(enable_)
  , comment_(comment_)
{}

const std::int32_t editProxy::ID;

void editProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editProxy");
    s.store_field("proxy_id", proxy_id_);
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_field("enable", enable_);
    s.store_field("comment", comment_);
    s.store_class_end();
  }
}

editStoryCover::editStoryCover()
  : story_poster_chat_id_()
  , story_id_()
  , cover_frame_timestamp_()
{}

editStoryCover::editStoryCover(int53 story_poster_chat_id_, int32 story_id_, double cover_frame_timestamp_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , cover_frame_timestamp_(cover_frame_timestamp_)
{}

const std::int32_t editStoryCover::ID;

void editStoryCover::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editStoryCover");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("cover_frame_timestamp", cover_frame_timestamp_);
    s.store_class_end();
  }
}

enableProxy::enableProxy()
  : proxy_id_()
{}

enableProxy::enableProxy(int32 proxy_id_)
  : proxy_id_(proxy_id_)
{}

const std::int32_t enableProxy::ID;

void enableProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "enableProxy");
    s.store_field("proxy_id", proxy_id_);
    s.store_class_end();
  }
}

encryptGroupCallData::encryptGroupCallData()
  : group_call_id_()
  , data_channel_()
  , data_()
  , unencrypted_prefix_size_()
{}

encryptGroupCallData::encryptGroupCallData(int32 group_call_id_, object_ptr<GroupCallDataChannel> &&data_channel_, bytes const &data_, int32 unencrypted_prefix_size_)
  : group_call_id_(group_call_id_)
  , data_channel_(std::move(data_channel_))
  , data_(std::move(data_))
  , unencrypted_prefix_size_(unencrypted_prefix_size_)
{}

const std::int32_t encryptGroupCallData::ID;

void encryptGroupCallData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptGroupCallData");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("data_channel", static_cast<const BaseObject *>(data_channel_.get()));
    s.store_bytes_field("data", data_);
    s.store_field("unencrypted_prefix_size", unencrypted_prefix_size_);
    s.store_class_end();
  }
}

getAccountTtl::getAccountTtl() {
}

const std::int32_t getAccountTtl::ID;

void getAccountTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAccountTtl");
    s.store_class_end();
  }
}

getApplicationConfig::getApplicationConfig() {
}

const std::int32_t getApplicationConfig::ID;

void getApplicationConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getApplicationConfig");
    s.store_class_end();
  }
}

getAutosaveSettings::getAutosaveSettings() {
}

const std::int32_t getAutosaveSettings::ID;

void getAutosaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAutosaveSettings");
    s.store_class_end();
  }
}

getCallbackQueryMessage::getCallbackQueryMessage()
  : chat_id_()
  , message_id_()
  , callback_query_id_()
{}

getCallbackQueryMessage::getCallbackQueryMessage(int53 chat_id_, int53 message_id_, int64 callback_query_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , callback_query_id_(callback_query_id_)
{}

const std::int32_t getCallbackQueryMessage::ID;

void getCallbackQueryMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCallbackQueryMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("callback_query_id", callback_query_id_);
    s.store_class_end();
  }
}

getChatAvailableMessageSenders::getChatAvailableMessageSenders()
  : chat_id_()
{}

getChatAvailableMessageSenders::getChatAvailableMessageSenders(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatAvailableMessageSenders::ID;

void getChatAvailableMessageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatAvailableMessageSenders");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatInviteLink::getChatInviteLink()
  : chat_id_()
  , invite_link_()
{}

getChatInviteLink::getChatInviteLink(int53 chat_id_, string const &invite_link_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
{}

const std::int32_t getChatInviteLink::ID;

void getChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

getChatInviteLinkMembers::getChatInviteLinkMembers()
  : chat_id_()
  , invite_link_()
  , only_with_expired_subscription_()
  , offset_member_()
  , limit_()
{}

getChatInviteLinkMembers::getChatInviteLinkMembers(int53 chat_id_, string const &invite_link_, bool only_with_expired_subscription_, object_ptr<chatInviteLinkMember> &&offset_member_, int32 limit_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , only_with_expired_subscription_(only_with_expired_subscription_)
  , offset_member_(std::move(offset_member_))
  , limit_(limit_)
{}

const std::int32_t getChatInviteLinkMembers::ID;

void getChatInviteLinkMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLinkMembers");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("only_with_expired_subscription", only_with_expired_subscription_);
    s.store_object_field("offset_member", static_cast<const BaseObject *>(offset_member_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatMember::getChatMember()
  : chat_id_()
  , member_id_()
{}

getChatMember::getChatMember(int53 chat_id_, object_ptr<MessageSender> &&member_id_)
  : chat_id_(chat_id_)
  , member_id_(std::move(member_id_))
{}

const std::int32_t getChatMember::ID;

void getChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_class_end();
  }
}

getChatSponsoredMessages::getChatSponsoredMessages()
  : chat_id_()
{}

getChatSponsoredMessages::getChatSponsoredMessages(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatSponsoredMessages::ID;

void getChatSponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatSponsoredMessages");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getConnectedAffiliateProgram::getConnectedAffiliateProgram()
  : affiliate_()
  , bot_user_id_()
{}

getConnectedAffiliateProgram::getConnectedAffiliateProgram(object_ptr<AffiliateType> &&affiliate_, int53 bot_user_id_)
  : affiliate_(std::move(affiliate_))
  , bot_user_id_(bot_user_id_)
{}

const std::int32_t getConnectedAffiliateProgram::ID;

void getConnectedAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getConnectedAffiliateProgram");
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

getCurrentWeather::getCurrentWeather()
  : location_()
{}

getCurrentWeather::getCurrentWeather(object_ptr<location> &&location_)
  : location_(std::move(location_))
{}

const std::int32_t getCurrentWeather::ID;

void getCurrentWeather::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCurrentWeather");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

getDeepLinkInfo::getDeepLinkInfo()
  : link_()
{}

getDeepLinkInfo::getDeepLinkInfo(string const &link_)
  : link_(link_)
{}

const std::int32_t getDeepLinkInfo::ID;

void getDeepLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDeepLinkInfo");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

getDefaultChatPhotoCustomEmojiStickers::getDefaultChatPhotoCustomEmojiStickers() {
}

const std::int32_t getDefaultChatPhotoCustomEmojiStickers::ID;

void getDefaultChatPhotoCustomEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultChatPhotoCustomEmojiStickers");
    s.store_class_end();
  }
}

getDefaultMessageAutoDeleteTime::getDefaultMessageAutoDeleteTime() {
}

const std::int32_t getDefaultMessageAutoDeleteTime::ID;

void getDefaultMessageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultMessageAutoDeleteTime");
    s.store_class_end();
  }
}

getDefaultProfilePhotoCustomEmojiStickers::getDefaultProfilePhotoCustomEmojiStickers() {
}

const std::int32_t getDefaultProfilePhotoCustomEmojiStickers::ID;

void getDefaultProfilePhotoCustomEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultProfilePhotoCustomEmojiStickers");
    s.store_class_end();
  }
}

getFullRichMessage::getFullRichMessage()
  : chat_id_()
  , message_id_()
{}

getFullRichMessage::getFullRichMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getFullRichMessage::ID;

void getFullRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFullRichMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getGameHighScores::getGameHighScores()
  : chat_id_()
  , message_id_()
  , user_id_()
{}

getGameHighScores::getGameHighScores(int53 chat_id_, int53 message_id_, int53 user_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , user_id_(user_id_)
{}

const std::int32_t getGameHighScores::ID;

void getGameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGameHighScores");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getGiftCollections::getGiftCollections()
  : owner_id_()
{}

getGiftCollections::getGiftCollections(object_ptr<MessageSender> &&owner_id_)
  : owner_id_(std::move(owner_id_))
{}

const std::int32_t getGiftCollections::ID;

void getGiftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftCollections");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_class_end();
  }
}

getGiftsForCrafting::getGiftsForCrafting()
  : regular_gift_id_()
  , offset_()
  , limit_()
{}

getGiftsForCrafting::getGiftsForCrafting(int64 regular_gift_id_, string const &offset_, int32 limit_)
  : regular_gift_id_(regular_gift_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getGiftsForCrafting::ID;

void getGiftsForCrafting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftsForCrafting");
    s.store_field("regular_gift_id", regular_gift_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getGuardBotWebAppUrl::getGuardBotWebAppUrl()
  : query_id_()
  , parameters_()
{}

getGuardBotWebAppUrl::getGuardBotWebAppUrl(int64 query_id_, object_ptr<webAppOpenParameters> &&parameters_)
  : query_id_(query_id_)
  , parameters_(std::move(parameters_))
{}

const std::int32_t getGuardBotWebAppUrl::ID;

void getGuardBotWebAppUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGuardBotWebAppUrl");
    s.store_field("query_id", query_id_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

getKeywordEmojis::getKeywordEmojis()
  : text_()
  , input_language_codes_()
{}

getKeywordEmojis::getKeywordEmojis(string const &text_, array<string> &&input_language_codes_)
  : text_(text_)
  , input_language_codes_(std::move(input_language_codes_))
{}

const std::int32_t getKeywordEmojis::ID;

void getKeywordEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getKeywordEmojis");
    s.store_field("text", text_);
    { s.store_vector_begin("input_language_codes", input_language_codes_.size()); for (const auto &_value : input_language_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getLanguagePackInfo::getLanguagePackInfo()
  : language_pack_id_()
{}

getLanguagePackInfo::getLanguagePackInfo(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t getLanguagePackInfo::ID;

void getLanguagePackInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLanguagePackInfo");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

getLanguagePackString::getLanguagePackString()
  : language_pack_database_path_()
  , localization_target_()
  , language_pack_id_()
  , key_()
{}

getLanguagePackString::getLanguagePackString(string const &language_pack_database_path_, string const &localization_target_, string const &language_pack_id_, string const &key_)
  : language_pack_database_path_(language_pack_database_path_)
  , localization_target_(localization_target_)
  , language_pack_id_(language_pack_id_)
  , key_(key_)
{}

const std::int32_t getLanguagePackString::ID;

void getLanguagePackString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLanguagePackString");
    s.store_field("language_pack_database_path", language_pack_database_path_);
    s.store_field("localization_target", localization_target_);
    s.store_field("language_pack_id", language_pack_id_);
    s.store_field("key", key_);
    s.store_class_end();
  }
}

getLiveStoryRtmpUrl::getLiveStoryRtmpUrl()
  : chat_id_()
{}

getLiveStoryRtmpUrl::getLiveStoryRtmpUrl(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getLiveStoryRtmpUrl::ID;

void getLiveStoryRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLiveStoryRtmpUrl");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getLiveStoryStreamer::getLiveStoryStreamer()
  : group_call_id_()
{}

getLiveStoryStreamer::getLiveStoryStreamer(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getLiveStoryStreamer::ID;

void getLiveStoryStreamer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLiveStoryStreamer");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getManagedBotToken::getManagedBotToken()
  : bot_user_id_()
  , revoke_()
{}

getManagedBotToken::getManagedBotToken(int53 bot_user_id_, bool revoke_)
  : bot_user_id_(bot_user_id_)
  , revoke_(revoke_)
{}

const std::int32_t getManagedBotToken::ID;

void getManagedBotToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getManagedBotToken");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

getMapThumbnailFile::getMapThumbnailFile()
  : location_()
  , zoom_()
  , width_()
  , height_()
  , scale_()
  , chat_id_()
{}

getMapThumbnailFile::getMapThumbnailFile(object_ptr<location> &&location_, int32 zoom_, int32 width_, int32 height_, int32 scale_, int53 chat_id_)
  : location_(std::move(location_))
  , zoom_(zoom_)
  , width_(width_)
  , height_(height_)
  , scale_(scale_)
  , chat_id_(chat_id_)
{}

const std::int32_t getMapThumbnailFile::ID;

void getMapThumbnailFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMapThumbnailFile");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("zoom", zoom_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("scale", scale_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getMessageAddedReactions::getMessageAddedReactions()
  : chat_id_()
  , message_id_()
  , reaction_type_()
  , offset_()
  , limit_()
{}

getMessageAddedReactions::getMessageAddedReactions(int53 chat_id_, int53 message_id_, object_ptr<ReactionType> &&reaction_type_, string const &offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reaction_type_(std::move(reaction_type_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getMessageAddedReactions::ID;

void getMessageAddedReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageAddedReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getMessageEmbeddingCode::getMessageEmbeddingCode()
  : chat_id_()
  , message_id_()
  , for_album_()
{}

getMessageEmbeddingCode::getMessageEmbeddingCode(int53 chat_id_, int53 message_id_, bool for_album_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , for_album_(for_album_)
{}

const std::int32_t getMessageEmbeddingCode::ID;

void getMessageEmbeddingCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageEmbeddingCode");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("for_album", for_album_);
    s.store_class_end();
  }
}

getMessageReadDate::getMessageReadDate()
  : chat_id_()
  , message_id_()
{}

getMessageReadDate::getMessageReadDate(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageReadDate::ID;

void getMessageReadDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageReadDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getNewChatPrivacySettings::getNewChatPrivacySettings() {
}

const std::int32_t getNewChatPrivacySettings::ID;

void getNewChatPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getNewChatPrivacySettings");
    s.store_class_end();
  }
}

getOnRampPaymentQuote::getOnRampPaymentQuote()
  : provider_id_()
  , cryptocurrency_()
  , base_currency_()
  , cryptocurrency_amount_()
  , base_currency_amount_()
  , payment_method_name_()
{}

getOnRampPaymentQuote::getOnRampPaymentQuote(string const &provider_id_, string const &cryptocurrency_, string const &base_currency_, string const &cryptocurrency_amount_, string const &base_currency_amount_, string const &payment_method_name_)
  : provider_id_(provider_id_)
  , cryptocurrency_(cryptocurrency_)
  , base_currency_(base_currency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , base_currency_amount_(base_currency_amount_)
  , payment_method_name_(payment_method_name_)
{}

const std::int32_t getOnRampPaymentQuote::ID;

void getOnRampPaymentQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOnRampPaymentQuote");
    s.store_field("provider_id", provider_id_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("base_currency", base_currency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_field("base_currency_amount", base_currency_amount_);
    s.store_field("payment_method_name", payment_method_name_);
    s.store_class_end();
  }
}

getPassportAuthorizationForm::getPassportAuthorizationForm()
  : bot_user_id_()
  , scope_()
  , public_key_()
  , nonce_()
{}

getPassportAuthorizationForm::getPassportAuthorizationForm(int53 bot_user_id_, string const &scope_, string const &public_key_, string const &nonce_)
  : bot_user_id_(bot_user_id_)
  , scope_(scope_)
  , public_key_(public_key_)
  , nonce_(nonce_)
{}

const std::int32_t getPassportAuthorizationForm::ID;

void getPassportAuthorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPassportAuthorizationForm");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("scope", scope_);
    s.store_field("public_key", public_key_);
    s.store_field("nonce", nonce_);
    s.store_class_end();
  }
}

getPaymentReceipt::getPaymentReceipt()
  : chat_id_()
  , message_id_()
{}

getPaymentReceipt::getPaymentReceipt(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getPaymentReceipt::ID;

void getPaymentReceipt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPaymentReceipt");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getRecentlyVisitedTMeUrls::getRecentlyVisitedTMeUrls()
  : referrer_()
{}

getRecentlyVisitedTMeUrls::getRecentlyVisitedTMeUrls(string const &referrer_)
  : referrer_(referrer_)
{}

const std::int32_t getRecentlyVisitedTMeUrls::ID;

void getRecentlyVisitedTMeUrls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentlyVisitedTMeUrls");
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

getRecoveryEmailAddress::getRecoveryEmailAddress()
  : password_()
{}

getRecoveryEmailAddress::getRecoveryEmailAddress(string const &password_)
  : password_(password_)
{}

const std::int32_t getRecoveryEmailAddress::ID;

void getRecoveryEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecoveryEmailAddress");
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

getRemoteFile::getRemoteFile()
  : remote_file_id_()
  , file_type_()
{}

getRemoteFile::getRemoteFile(string const &remote_file_id_, object_ptr<FileType> &&file_type_)
  : remote_file_id_(remote_file_id_)
  , file_type_(std::move(file_type_))
{}

const std::int32_t getRemoteFile::ID;

void getRemoteFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRemoteFile");
    s.store_field("remote_file_id", remote_file_id_);
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_class_end();
  }
}

getSavedNotificationSounds::getSavedNotificationSounds() {
}

const std::int32_t getSavedNotificationSounds::ID;

void getSavedNotificationSounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedNotificationSounds");
    s.store_class_end();
  }
}

getSpeechRecognitionLanguages::getSpeechRecognitionLanguages()
  : chat_id_()
{}

getSpeechRecognitionLanguages::getSpeechRecognitionLanguages(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getSpeechRecognitionLanguages::ID;

void getSpeechRecognitionLanguages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSpeechRecognitionLanguages");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getStoryAvailableReactions::getStoryAvailableReactions()
  : row_size_()
{}

getStoryAvailableReactions::getStoryAvailableReactions(int32 row_size_)
  : row_size_(row_size_)
{}

const std::int32_t getStoryAvailableReactions::ID;

void getStoryAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryAvailableReactions");
    s.store_field("row_size", row_size_);
    s.store_class_end();
  }
}

getStoryNotificationSettingsExceptions::getStoryNotificationSettingsExceptions() {
}

const std::int32_t getStoryNotificationSettingsExceptions::ID;

void getStoryNotificationSettingsExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryNotificationSettingsExceptions");
    s.store_class_end();
  }
}

getSuggestedFileName::getSuggestedFileName()
  : file_id_()
  , directory_()
{}

getSuggestedFileName::getSuggestedFileName(int32 file_id_, string const &directory_)
  : file_id_(file_id_)
  , directory_(directory_)
{}

const std::int32_t getSuggestedFileName::ID;

void getSuggestedFileName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuggestedFileName");
    s.store_field("file_id", file_id_);
    s.store_field("directory", directory_);
    s.store_class_end();
  }
}

getSupportUser::getSupportUser() {
}

const std::int32_t getSupportUser::ID;

void getSupportUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupportUser");
    s.store_class_end();
  }
}

getUpgradedGift::getUpgradedGift()
  : name_()
{}

getUpgradedGift::getUpgradedGift(string const &name_)
  : name_(name_)
{}

const std::int32_t getUpgradedGift::ID;

void getUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGift");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

getUserChatBoosts::getUserChatBoosts()
  : chat_id_()
  , user_id_()
{}

getUserChatBoosts::getUserChatBoosts(int53 chat_id_, int53 user_id_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
{}

const std::int32_t getUserChatBoosts::ID;

void getUserChatBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserChatBoosts");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getVideoChatAvailableParticipants::getVideoChatAvailableParticipants()
  : chat_id_()
{}

getVideoChatAvailableParticipants::getVideoChatAvailableParticipants(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getVideoChatAvailableParticipants::ID;

void getVideoChatAvailableParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getVideoChatAvailableParticipants");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getWebAppUrl::getWebAppUrl()
  : bot_user_id_()
  , url_()
  , parameters_()
{}

getWebAppUrl::getWebAppUrl(int53 bot_user_id_, string const &url_, object_ptr<webAppOpenParameters> &&parameters_)
  : bot_user_id_(bot_user_id_)
  , url_(url_)
  , parameters_(std::move(parameters_))
{}

const std::int32_t getWebAppUrl::ID;

void getWebAppUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWebAppUrl");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("url", url_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

importContacts::importContacts()
  : contacts_()
{}

importContacts::importContacts(array<object_ptr<importedContact>> &&contacts_)
  : contacts_(std::move(contacts_))
{}

const std::int32_t importContacts::ID;

void importContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importContacts");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

increaseGiftAuctionBid::increaseGiftAuctionBid()
  : gift_id_()
  , star_count_()
{}

increaseGiftAuctionBid::increaseGiftAuctionBid(int64 gift_id_, int53 star_count_)
  : gift_id_(gift_id_)
  , star_count_(star_count_)
{}

const std::int32_t increaseGiftAuctionBid::ID;

void increaseGiftAuctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "increaseGiftAuctionBid");
    s.store_field("gift_id", gift_id_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

joinGroupCall::joinGroupCall()
  : input_group_call_()
  , join_parameters_()
{}

joinGroupCall::joinGroupCall(object_ptr<InputGroupCall> &&input_group_call_, object_ptr<groupCallJoinParameters> &&join_parameters_)
  : input_group_call_(std::move(input_group_call_))
  , join_parameters_(std::move(join_parameters_))
{}

const std::int32_t joinGroupCall::ID;

void joinGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinGroupCall");
    s.store_object_field("input_group_call", static_cast<const BaseObject *>(input_group_call_.get()));
    s.store_object_field("join_parameters", static_cast<const BaseObject *>(join_parameters_.get()));
    s.store_class_end();
  }
}

openChatSimilarChat::openChatSimilarChat()
  : chat_id_()
  , opened_chat_id_()
{}

openChatSimilarChat::openChatSimilarChat(int53 chat_id_, int53 opened_chat_id_)
  : chat_id_(chat_id_)
  , opened_chat_id_(opened_chat_id_)
{}

const std::int32_t openChatSimilarChat::ID;

void openChatSimilarChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openChatSimilarChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("opened_chat_id", opened_chat_id_);
    s.store_class_end();
  }
}

placeGiftAuctionBid::placeGiftAuctionBid()
  : gift_id_()
  , star_count_()
  , user_id_()
  , text_()
  , is_private_()
{}

placeGiftAuctionBid::placeGiftAuctionBid(int64 gift_id_, int53 star_count_, int53 user_id_, object_ptr<formattedText> &&text_, bool is_private_)
  : gift_id_(gift_id_)
  , star_count_(star_count_)
  , user_id_(user_id_)
  , text_(std::move(text_))
  , is_private_(is_private_)
{}

const std::int32_t placeGiftAuctionBid::ID;

void placeGiftAuctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "placeGiftAuctionBid");
    s.store_field("gift_id", gift_id_);
    s.store_field("star_count", star_count_);
    s.store_field("user_id", user_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_private", is_private_);
    s.store_class_end();
  }
}

processChatHasProtectedContentDisableRequest::processChatHasProtectedContentDisableRequest()
  : chat_id_()
  , request_message_id_()
  , approve_()
{}

processChatHasProtectedContentDisableRequest::processChatHasProtectedContentDisableRequest(int53 chat_id_, int53 request_message_id_, bool approve_)
  : chat_id_(chat_id_)
  , request_message_id_(request_message_id_)
  , approve_(approve_)
{}

const std::int32_t processChatHasProtectedContentDisableRequest::ID;

void processChatHasProtectedContentDisableRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processChatHasProtectedContentDisableRequest");
    s.store_field("chat_id", chat_id_);
    s.store_field("request_message_id", request_message_id_);
    s.store_field("approve", approve_);
    s.store_class_end();
  }
}

readAllDirectMessagesChatTopicReactions::readAllDirectMessagesChatTopicReactions()
  : chat_id_()
  , topic_id_()
{}

readAllDirectMessagesChatTopicReactions::readAllDirectMessagesChatTopicReactions(int53 chat_id_, int53 topic_id_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
{}

const std::int32_t readAllDirectMessagesChatTopicReactions::ID;

void readAllDirectMessagesChatTopicReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllDirectMessagesChatTopicReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

registerDevice::registerDevice()
  : device_token_()
  , other_user_ids_()
{}

registerDevice::registerDevice(object_ptr<DeviceToken> &&device_token_, array<int53> &&other_user_ids_)
  : device_token_(std::move(device_token_))
  , other_user_ids_(std::move(other_user_ids_))
{}

const std::int32_t registerDevice::ID;

void registerDevice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "registerDevice");
    s.store_field("device_token", "[REDACTED]");
    { s.store_vector_begin("other_user_ids", other_user_ids_.size()); for (const auto &_value : other_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

removeAllFilesFromDownloads::removeAllFilesFromDownloads()
  : only_active_()
  , only_completed_()
  , delete_from_cache_()
{}

removeAllFilesFromDownloads::removeAllFilesFromDownloads(bool only_active_, bool only_completed_, bool delete_from_cache_)
  : only_active_(only_active_)
  , only_completed_(only_completed_)
  , delete_from_cache_(delete_from_cache_)
{}

const std::int32_t removeAllFilesFromDownloads::ID;

void removeAllFilesFromDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeAllFilesFromDownloads");
    s.store_field("only_active", only_active_);
    s.store_field("only_completed", only_completed_);
    s.store_field("delete_from_cache", delete_from_cache_);
    s.store_class_end();
  }
}

removeBusinessConnectedBotFromChat::removeBusinessConnectedBotFromChat()
  : chat_id_()
{}

removeBusinessConnectedBotFromChat::removeBusinessConnectedBotFromChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t removeBusinessConnectedBotFromChat::ID;

void removeBusinessConnectedBotFromChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeBusinessConnectedBotFromChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removePendingPaidMessageReactions::removePendingPaidMessageReactions()
  : chat_id_()
  , message_id_()
{}

removePendingPaidMessageReactions::removePendingPaidMessageReactions(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t removePendingPaidMessageReactions::ID;

void removePendingPaidMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removePendingPaidMessageReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

removeRecentlyFoundChat::removeRecentlyFoundChat()
  : chat_id_()
{}

removeRecentlyFoundChat::removeRecentlyFoundChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t removeRecentlyFoundChat::ID;

void removeRecentlyFoundChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeRecentlyFoundChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removeTopChat::removeTopChat()
  : category_()
  , chat_id_()
{}

removeTopChat::removeTopChat(object_ptr<TopChatCategory> &&category_, int53 chat_id_)
  : category_(std::move(category_))
  , chat_id_(chat_id_)
{}

const std::int32_t removeTopChat::ID;

void removeTopChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeTopChat");
    s.store_object_field("category", static_cast<const BaseObject *>(category_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removeWebBrowserSettingsException::removeWebBrowserSettingsException()
  : url_()
{}

removeWebBrowserSettingsException::removeWebBrowserSettingsException(string const &url_)
  : url_(url_)
{}

const std::int32_t removeWebBrowserSettingsException::ID;

void removeWebBrowserSettingsException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeWebBrowserSettingsException");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

reorderGiftCollections::reorderGiftCollections()
  : owner_id_()
  , collection_ids_()
{}

reorderGiftCollections::reorderGiftCollections(object_ptr<MessageSender> &&owner_id_, array<int32> &&collection_ids_)
  : owner_id_(std::move(owner_id_))
  , collection_ids_(std::move(collection_ids_))
{}

const std::int32_t reorderGiftCollections::ID;

void reorderGiftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderGiftCollections");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    { s.store_vector_begin("collection_ids", collection_ids_.size()); for (const auto &_value : collection_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportAuthenticationCodeMissing::reportAuthenticationCodeMissing()
  : mobile_network_code_()
{}

reportAuthenticationCodeMissing::reportAuthenticationCodeMissing(string const &mobile_network_code_)
  : mobile_network_code_(mobile_network_code_)
{}

const std::int32_t reportAuthenticationCodeMissing::ID;

void reportAuthenticationCodeMissing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportAuthenticationCodeMissing");
    s.store_field("mobile_network_code", mobile_network_code_);
    s.store_class_end();
  }
}

reportSponsoredChat::reportSponsoredChat()
  : sponsored_chat_unique_id_()
  , option_id_()
{}

reportSponsoredChat::reportSponsoredChat(int53 sponsored_chat_unique_id_, bytes const &option_id_)
  : sponsored_chat_unique_id_(sponsored_chat_unique_id_)
  , option_id_(std::move(option_id_))
{}

const std::int32_t reportSponsoredChat::ID;

void reportSponsoredChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredChat");
    s.store_field("sponsored_chat_unique_id", sponsored_chat_unique_id_);
    s.store_bytes_field("option_id", option_id_);
    s.store_class_end();
  }
}

resendPhoneNumberCode::resendPhoneNumberCode()
  : reason_()
{}

resendPhoneNumberCode::resendPhoneNumberCode(object_ptr<ResendCodeReason> &&reason_)
  : reason_(std::move(reason_))
{}

const std::int32_t resendPhoneNumberCode::ID;

void resendPhoneNumberCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendPhoneNumberCode");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

resetAuthenticationEmailAddress::resetAuthenticationEmailAddress() {
}

const std::int32_t resetAuthenticationEmailAddress::ID;

void resetAuthenticationEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetAuthenticationEmailAddress");
    s.store_class_end();
  }
}

revokeGroupCallInviteLink::revokeGroupCallInviteLink()
  : group_call_id_()
{}

revokeGroupCallInviteLink::revokeGroupCallInviteLink(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t revokeGroupCallInviteLink::ID;

void revokeGroupCallInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revokeGroupCallInviteLink");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

saveApplicationLogEvent::saveApplicationLogEvent()
  : type_()
  , chat_id_()
  , data_()
{}

saveApplicationLogEvent::saveApplicationLogEvent(string const &type_, int53 chat_id_, object_ptr<JsonValue> &&data_)
  : type_(type_)
  , chat_id_(chat_id_)
  , data_(std::move(data_))
{}

const std::int32_t saveApplicationLogEvent::ID;

void saveApplicationLogEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "saveApplicationLogEvent");
    s.store_field("type", type_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_class_end();
  }
}

searchHashtags::searchHashtags()
  : prefix_()
  , limit_()
{}

searchHashtags::searchHashtags(string const &prefix_, int32 limit_)
  : prefix_(prefix_)
  , limit_(limit_)
{}

const std::int32_t searchHashtags::ID;

void searchHashtags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchHashtags");
    s.store_field("prefix", prefix_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchPublicChat::searchPublicChat()
  : username_()
{}

searchPublicChat::searchPublicChat(string const &username_)
  : username_(username_)
{}

const std::int32_t searchPublicChat::ID;

void searchPublicChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicChat");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

searchUserByPhoneNumber::searchUserByPhoneNumber()
  : phone_number_()
  , only_local_()
{}

searchUserByPhoneNumber::searchUserByPhoneNumber(string const &phone_number_, bool only_local_)
  : phone_number_(phone_number_)
  , only_local_(only_local_)
{}

const std::int32_t searchUserByPhoneNumber::ID;

void searchUserByPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchUserByPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

sellGift::sellGift()
  : business_connection_id_()
  , received_gift_id_()
{}

sellGift::sellGift(string const &business_connection_id_, string const &received_gift_id_)
  : business_connection_id_(business_connection_id_)
  , received_gift_id_(received_gift_id_)
{}

const std::int32_t sellGift::ID;

void sellGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sellGift");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

sendRichMessageDraft::sendRichMessageDraft()
  : chat_id_()
  , forum_topic_id_()
  , draft_id_()
  , can_stop_()
  , keep_on_stop_()
  , message_()
{}

sendRichMessageDraft::sendRichMessageDraft(int53 chat_id_, int32 forum_topic_id_, int64 draft_id_, bool can_stop_, bool keep_on_stop_, object_ptr<inputRichMessage> &&message_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , draft_id_(draft_id_)
  , can_stop_(can_stop_)
  , keep_on_stop_(keep_on_stop_)
  , message_(std::move(message_))
{}

const std::int32_t sendRichMessageDraft::ID;

void sendRichMessageDraft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendRichMessageDraft");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("draft_id", draft_id_);
    s.store_field("can_stop", can_stop_);
    s.store_field("keep_on_stop", keep_on_stop_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

setAccountTtl::setAccountTtl()
  : ttl_()
{}

setAccountTtl::setAccountTtl(object_ptr<accountTtl> &&ttl_)
  : ttl_(std::move(ttl_))
{}

const std::int32_t setAccountTtl::ID;

void setAccountTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAccountTtl");
    s.store_object_field("ttl", static_cast<const BaseObject *>(ttl_.get()));
    s.store_class_end();
  }
}

setChatSlowModeDelay::setChatSlowModeDelay()
  : chat_id_()
  , slow_mode_delay_()
{}

setChatSlowModeDelay::setChatSlowModeDelay(int53 chat_id_, int32 slow_mode_delay_)
  : chat_id_(chat_id_)
  , slow_mode_delay_(slow_mode_delay_)
{}

const std::int32_t setChatSlowModeDelay::ID;

void setChatSlowModeDelay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatSlowModeDelay");
    s.store_field("chat_id", chat_id_);
    s.store_field("slow_mode_delay", slow_mode_delay_);
    s.store_class_end();
  }
}

setCloseFriends::setCloseFriends()
  : user_ids_()
{}

setCloseFriends::setCloseFriends(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t setCloseFriends::ID;

void setCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCloseFriends");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setGroupCallParticipantIsSpeaking::setGroupCallParticipantIsSpeaking()
  : group_call_id_()
  , audio_source_()
  , is_speaking_()
{}

setGroupCallParticipantIsSpeaking::setGroupCallParticipantIsSpeaking(int32 group_call_id_, int32 audio_source_, bool is_speaking_)
  : group_call_id_(group_call_id_)
  , audio_source_(audio_source_)
  , is_speaking_(is_speaking_)
{}

const std::int32_t setGroupCallParticipantIsSpeaking::ID;

void setGroupCallParticipantIsSpeaking::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGroupCallParticipantIsSpeaking");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("audio_source", audio_source_);
    s.store_field("is_speaking", is_speaking_);
    s.store_class_end();
  }
}

setNetworkType::setNetworkType()
  : type_()
{}

setNetworkType::setNetworkType(object_ptr<NetworkType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t setNetworkType::ID;

void setNetworkType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setNetworkType");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

setPinnedGifts::setPinnedGifts()
  : owner_id_()
  , received_gift_ids_()
{}

setPinnedGifts::setPinnedGifts(object_ptr<MessageSender> &&owner_id_, array<string> &&received_gift_ids_)
  : owner_id_(std::move(owner_id_))
  , received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t setPinnedGifts::ID;

void setPinnedGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPinnedGifts");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setStickerKeywords::setStickerKeywords()
  : sticker_()
  , keywords_()
{}

setStickerKeywords::setStickerKeywords(object_ptr<InputFile> &&sticker_, array<string> &&keywords_)
  : sticker_(std::move(sticker_))
  , keywords_(std::move(keywords_))
{}

const std::int32_t setStickerKeywords::ID;

void setStickerKeywords::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerKeywords");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    { s.store_vector_begin("keywords", keywords_.size()); for (const auto &_value : keywords_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setStoryReaction::setStoryReaction()
  : story_poster_chat_id_()
  , story_id_()
  , reaction_type_()
  , update_recent_reactions_()
{}

setStoryReaction::setStoryReaction(int53 story_poster_chat_id_, int32 story_id_, object_ptr<ReactionType> &&reaction_type_, bool update_recent_reactions_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , reaction_type_(std::move(reaction_type_))
  , update_recent_reactions_(update_recent_reactions_)
{}

const std::int32_t setStoryReaction::ID;

void setStoryReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStoryReaction");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("update_recent_reactions", update_recent_reactions_);
    s.store_class_end();
  }
}

setSupergroupUsername::setSupergroupUsername()
  : supergroup_id_()
  , username_()
{}

setSupergroupUsername::setSupergroupUsername(int53 supergroup_id_, string const &username_)
  : supergroup_id_(supergroup_id_)
  , username_(username_)
{}

const std::int32_t setSupergroupUsername::ID;

void setSupergroupUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupUsername");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("username", username_);
    s.store_class_end();
  }
}

setTdlibParameters::setTdlibParameters()
  : use_test_dc_()
  , database_directory_()
  , files_directory_()
  , database_encryption_key_()
  , use_file_database_()
  , use_chat_info_database_()
  , use_message_database_()
  , use_secret_chats_()
  , api_id_()
  , api_hash_()
  , system_language_code_()
  , device_model_()
  , system_version_()
  , application_version_()
{}

setTdlibParameters::setTdlibParameters(bool use_test_dc_, string const &database_directory_, string const &files_directory_, bytes const &database_encryption_key_, bool use_file_database_, bool use_chat_info_database_, bool use_message_database_, bool use_secret_chats_, int32 api_id_, string const &api_hash_, string const &system_language_code_, string const &device_model_, string const &system_version_, string const &application_version_)
  : use_test_dc_(use_test_dc_)
  , database_directory_(database_directory_)
  , files_directory_(files_directory_)
  , database_encryption_key_(std::move(database_encryption_key_))
  , use_file_database_(use_file_database_)
  , use_chat_info_database_(use_chat_info_database_)
  , use_message_database_(use_message_database_)
  , use_secret_chats_(use_secret_chats_)
  , api_id_(api_id_)
  , api_hash_(api_hash_)
  , system_language_code_(system_language_code_)
  , device_model_(device_model_)
  , system_version_(system_version_)
  , application_version_(application_version_)
{}

const std::int32_t setTdlibParameters::ID;

void setTdlibParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setTdlibParameters");
    s.store_field("use_test_dc", use_test_dc_);
    s.store_field("database_directory", database_directory_);
    s.store_field("files_directory", files_directory_);
    s.store_field("database_encryption_key", "[REDACTED]");
    s.store_field("use_file_database", use_file_database_);
    s.store_field("use_chat_info_database", use_chat_info_database_);
    s.store_field("use_message_database", use_message_database_);
    s.store_field("use_secret_chats", use_secret_chats_);
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", "[REDACTED]");
    s.store_field("system_language_code", system_language_code_);
    s.store_field("device_model", device_model_);
    s.store_field("system_version", system_version_);
    s.store_field("application_version", application_version_);
    s.store_class_end();
  }
}

terminateSession::terminateSession()
  : session_id_()
{}

terminateSession::terminateSession(int64 session_id_)
  : session_id_(session_id_)
{}

const std::int32_t terminateSession::ID;

void terminateSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "terminateSession");
    s.store_field("session_id", session_id_);
    s.store_class_end();
  }
}

testNetwork::testNetwork() {
}

const std::int32_t testNetwork::ID;

void testNetwork::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testNetwork");
    s.store_class_end();
  }
}

toggleForumTopicIsPinned::toggleForumTopicIsPinned()
  : chat_id_()
  , forum_topic_id_()
  , is_pinned_()
{}

toggleForumTopicIsPinned::toggleForumTopicIsPinned(int53 chat_id_, int32 forum_topic_id_, bool is_pinned_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t toggleForumTopicIsPinned::ID;

void toggleForumTopicIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleForumTopicIsPinned");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

viewMessages::viewMessages()
  : chat_id_()
  , message_ids_()
  , source_()
  , force_read_()
{}

viewMessages::viewMessages(int53 chat_id_, array<int53> &&message_ids_, object_ptr<MessageSource> &&source_, bool force_read_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
  , source_(std::move(source_))
  , force_read_(force_read_)
{}

const std::int32_t viewMessages::ID;

void viewMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("force_read", force_read_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
