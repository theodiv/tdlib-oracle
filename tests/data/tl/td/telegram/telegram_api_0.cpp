#include "telegram_api.h"

#include "td/tl/tl_object_parse.h"
#include "td/tl/tl_object_store.h"

#include "td/utils/common.h"
#include "td/utils/format.h"
#include "td/utils/logging.h"
#include "td/utils/SliceBuilder.h"
#include "td/utils/tl_parsers.h"
#include "td/utils/tl_storers.h"
#include "td/utils/TlStorerToString.h"

namespace td {
namespace telegram_api {

std::string to_string(const BaseObject &value) {
  TlStorerToString storer;
  value.store(storer, "");
  return storer.move_as_string();
}

accountDaysTTL::accountDaysTTL(int32 days_)
  : days_(days_)
{}

const std::int32_t accountDaysTTL::ID;

object_ptr<accountDaysTTL> accountDaysTTL::fetch(TlBufferParser &p) {
  return make_tl_object<accountDaysTTL>(p);
}

accountDaysTTL::accountDaysTTL(TlBufferParser &p)
  : days_(TlFetchInt::parse(p))
{}

void accountDaysTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(days_, s);
}

void accountDaysTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(days_, s);
}

void accountDaysTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accountDaysTTL");
    s.store_field("days", days_);
    s.store_class_end();
  }
}

object_ptr<AttachMenuPeerType> AttachMenuPeerType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case attachMenuPeerTypeSameBotPM::ID:
      return attachMenuPeerTypeSameBotPM::fetch(p);
    case attachMenuPeerTypeBotPM::ID:
      return attachMenuPeerTypeBotPM::fetch(p);
    case attachMenuPeerTypePM::ID:
      return attachMenuPeerTypePM::fetch(p);
    case attachMenuPeerTypeChat::ID:
      return attachMenuPeerTypeChat::fetch(p);
    case attachMenuPeerTypeBroadcast::ID:
      return attachMenuPeerTypeBroadcast::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t attachMenuPeerTypeSameBotPM::ID;

object_ptr<AttachMenuPeerType> attachMenuPeerTypeSameBotPM::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuPeerTypeSameBotPM>();
}

void attachMenuPeerTypeSameBotPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuPeerTypeSameBotPM");
    s.store_class_end();
  }
}

const std::int32_t attachMenuPeerTypeBotPM::ID;

object_ptr<AttachMenuPeerType> attachMenuPeerTypeBotPM::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuPeerTypeBotPM>();
}

void attachMenuPeerTypeBotPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuPeerTypeBotPM");
    s.store_class_end();
  }
}

const std::int32_t attachMenuPeerTypePM::ID;

object_ptr<AttachMenuPeerType> attachMenuPeerTypePM::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuPeerTypePM>();
}

void attachMenuPeerTypePM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuPeerTypePM");
    s.store_class_end();
  }
}

const std::int32_t attachMenuPeerTypeChat::ID;

object_ptr<AttachMenuPeerType> attachMenuPeerTypeChat::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuPeerTypeChat>();
}

void attachMenuPeerTypeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuPeerTypeChat");
    s.store_class_end();
  }
}

const std::int32_t attachMenuPeerTypeBroadcast::ID;

object_ptr<AttachMenuPeerType> attachMenuPeerTypeBroadcast::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuPeerTypeBroadcast>();
}

void attachMenuPeerTypeBroadcast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuPeerTypeBroadcast");
    s.store_class_end();
  }
}

authorization::authorization()
  : flags_()
  , current_()
  , official_app_()
  , password_pending_()
  , encrypted_requests_disabled_()
  , call_requests_disabled_()
  , unconfirmed_()
  , hash_()
  , device_model_()
  , platform_()
  , system_version_()
  , api_id_()
  , app_name_()
  , app_version_()
  , date_created_()
  , date_active_()
  , ip_()
  , country_()
  , region_()
{}

const std::int32_t authorization::ID;

object_ptr<authorization> authorization::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<authorization> res = make_tl_object<authorization>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->current_ = (var0 & 1) != 0;
  res->official_app_ = (var0 & 2) != 0;
  res->password_pending_ = (var0 & 4) != 0;
  res->encrypted_requests_disabled_ = (var0 & 8) != 0;
  res->call_requests_disabled_ = (var0 & 16) != 0;
  res->unconfirmed_ = (var0 & 32) != 0;
  res->hash_ = TlFetchLong::parse(p);
  res->device_model_ = TlFetchString<string>::parse(p);
  res->platform_ = TlFetchString<string>::parse(p);
  res->system_version_ = TlFetchString<string>::parse(p);
  res->api_id_ = TlFetchInt::parse(p);
  res->app_name_ = TlFetchString<string>::parse(p);
  res->app_version_ = TlFetchString<string>::parse(p);
  res->date_created_ = TlFetchInt::parse(p);
  res->date_active_ = TlFetchInt::parse(p);
  res->ip_ = TlFetchString<string>::parse(p);
  res->country_ = TlFetchString<string>::parse(p);
  res->region_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void authorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorization");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (current_ << 0) | (official_app_ << 1) | (password_pending_ << 2) | (encrypted_requests_disabled_ << 3) | (call_requests_disabled_ << 4) | (unconfirmed_ << 5)));
    if (var0 & 1) { s.store_field("current", true); }
    if (var0 & 2) { s.store_field("official_app", true); }
    if (var0 & 4) { s.store_field("password_pending", true); }
    if (var0 & 8) { s.store_field("encrypted_requests_disabled", true); }
    if (var0 & 16) { s.store_field("call_requests_disabled", true); }
    if (var0 & 32) { s.store_field("unconfirmed", true); }
    s.store_field("hash", hash_);
    s.store_field("device_model", device_model_);
    s.store_field("platform", platform_);
    s.store_field("system_version", system_version_);
    s.store_field("api_id", api_id_);
    s.store_field("app_name", app_name_);
    s.store_field("app_version", app_version_);
    s.store_field("date_created", date_created_);
    s.store_field("date_active", date_active_);
    s.store_field("ip", ip_);
    s.store_field("country", country_);
    s.store_field("region", region_);
    s.store_class_end();
  }
}

const std::int32_t autoSaveException::ID;

object_ptr<autoSaveException> autoSaveException::fetch(TlBufferParser &p) {
  return make_tl_object<autoSaveException>(p);
}

autoSaveException::autoSaveException(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , settings_(TlFetchBoxed<TlFetchObject<autoSaveSettings>, -934791986>::parse(p))
{}

void autoSaveException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoSaveException");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

boost::boost()
  : flags_()
  , gift_()
  , giveaway_()
  , unclaimed_()
  , id_()
  , user_id_()
  , giveaway_msg_id_()
  , date_()
  , expires_()
  , used_gift_slug_()
  , multiplier_()
  , stars_()
{}

const std::int32_t boost::ID;

object_ptr<boost> boost::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<boost> res = make_tl_object<boost>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->gift_ = (var0 & 2) != 0;
  res->giveaway_ = (var0 & 4) != 0;
  res->unclaimed_ = (var0 & 8) != 0;
  res->id_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->user_id_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->giveaway_msg_id_ = TlFetchInt::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->expires_ = TlFetchInt::parse(p);
  if (var0 & 16) { res->used_gift_slug_ = TlFetchString<string>::parse(p); }
  if (var0 & 32) { res->multiplier_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->stars_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void boost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "boost");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (gift_ << 1) | (giveaway_ << 2) | (unclaimed_ << 3) | ((!used_gift_slug_.empty()) << 4)));
    if (var0 & 2) { s.store_field("gift", true); }
    if (var0 & 4) { s.store_field("giveaway", true); }
    if (var0 & 8) { s.store_field("unclaimed", true); }
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("user_id", user_id_); }
    if (var0 & 4) { s.store_field("giveaway_msg_id", giveaway_msg_id_); }
    s.store_field("date", date_);
    s.store_field("expires", expires_);
    if (var0 & 16) { s.store_field("used_gift_slug", used_gift_slug_); }
    if (var0 & 32) { s.store_field("multiplier", multiplier_); }
    if (var0 & 64) { s.store_field("stars", stars_); }
    s.store_class_end();
  }
}

botVerifierSettings::botVerifierSettings()
  : flags_()
  , can_modify_custom_description_()
  , icon_()
  , company_()
  , custom_description_()
{}

const std::int32_t botVerifierSettings::ID;

object_ptr<botVerifierSettings> botVerifierSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botVerifierSettings> res = make_tl_object<botVerifierSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_modify_custom_description_ = (var0 & 2) != 0;
  res->icon_ = TlFetchLong::parse(p);
  res->company_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->custom_description_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void botVerifierSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botVerifierSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_modify_custom_description_ << 1) | ((custom_description_ != nullptr) << 0)));
    if (var0 & 2) { s.store_field("can_modify_custom_description", true); }
    s.store_field("icon", icon_);
    s.store_field("company", company_);
    if (var0 & 1) { s.store_object_field("custom_description", static_cast<const BaseObject *>(custom_description_.get())); }
    s.store_class_end();
  }
}

businessAwayMessage::businessAwayMessage()
  : flags_()
  , offline_only_()
  , shortcut_id_()
  , schedule_()
  , recipients_()
{}

const std::int32_t businessAwayMessage::ID;

object_ptr<businessAwayMessage> businessAwayMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessAwayMessage> res = make_tl_object<businessAwayMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->offline_only_ = (var0 & 1) != 0;
  res->shortcut_id_ = TlFetchInt::parse(p);
  res->schedule_ = TlFetchObject<BusinessAwayMessageSchedule>::parse(p);
  res->recipients_ = TlFetchBoxed<TlFetchObject<businessRecipients>, 554733559>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessAwayMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (offline_only_ << 0)));
    if (var0 & 1) { s.store_field("offline_only", true); }
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("schedule", static_cast<const BaseObject *>(schedule_.get()));
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_class_end();
  }
}

businessWorkHours::businessWorkHours()
  : flags_()
  , open_now_()
  , timezone_id_()
  , weekly_open_()
{}

businessWorkHours::businessWorkHours(int32 flags_, bool open_now_, string const &timezone_id_, array<object_ptr<businessWeeklyOpen>> &&weekly_open_)
  : flags_(flags_)
  , open_now_(open_now_)
  , timezone_id_(timezone_id_)
  , weekly_open_(std::move(weekly_open_))
{}

const std::int32_t businessWorkHours::ID;

object_ptr<businessWorkHours> businessWorkHours::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessWorkHours> res = make_tl_object<businessWorkHours>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->open_now_ = (var0 & 1) != 0;
  res->timezone_id_ = TlFetchString<string>::parse(p);
  res->weekly_open_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<businessWeeklyOpen>, 302717625>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessWorkHours::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (open_now_ << 0)), s);
  TlStoreString::store(timezone_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 302717625>>, 481674261>::store(weekly_open_, s);
}

void businessWorkHours::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (open_now_ << 0)), s);
  TlStoreString::store(timezone_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 302717625>>, 481674261>::store(weekly_open_, s);
}

void businessWorkHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessWorkHours");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (open_now_ << 0)));
    if (var0 & 1) { s.store_field("open_now", true); }
    s.store_field("timezone_id", timezone_id_);
    { s.store_vector_begin("weekly_open", weekly_open_.size()); for (const auto &_value : weekly_open_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t cdnConfig::ID;

object_ptr<cdnConfig> cdnConfig::fetch(TlBufferParser &p) {
  return make_tl_object<cdnConfig>(p);
}

cdnConfig::cdnConfig(TlBufferParser &p)
  : public_keys_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<cdnPublicKey>, -914167110>>, 481674261>::parse(p))
{}

void cdnConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cdnConfig");
    { s.store_vector_begin("public_keys", public_keys_.size()); for (const auto &_value : public_keys_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t cdnPublicKey::ID;

object_ptr<cdnPublicKey> cdnPublicKey::fetch(TlBufferParser &p) {
  return make_tl_object<cdnPublicKey>(p);
}

cdnPublicKey::cdnPublicKey(TlBufferParser &p)
  : dc_id_(TlFetchInt::parse(p))
  , public_key_(TlFetchString<string>::parse(p))
{}

void cdnPublicKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cdnPublicKey");
    s.store_field("dc_id", dc_id_);
    s.store_field("public_key", public_key_);
    s.store_class_end();
  }
}

config::config()
  : flags_()
  , default_p2p_contacts_()
  , preload_featured_stickers_()
  , revoke_pm_inbox_()
  , blocked_mode_()
  , force_try_ipv6_()
  , fpnv_allowed_()
  , date_()
  , expires_()
  , test_mode_()
  , this_dc_()
  , dc_options_()
  , dc_txt_domain_name_()
  , chat_size_max_()
  , megagroup_size_max_()
  , forwarded_count_max_()
  , online_update_period_ms_()
  , offline_blur_timeout_ms_()
  , offline_idle_timeout_ms_()
  , online_cloud_timeout_ms_()
  , notify_cloud_delay_ms_()
  , notify_default_delay_ms_()
  , push_chat_period_ms_()
  , push_chat_limit_()
  , edit_time_limit_()
  , revoke_time_limit_()
  , revoke_pm_time_limit_()
  , rating_e_decay_()
  , stickers_recent_limit_()
  , channels_read_media_period_()
  , tmp_sessions_()
  , call_receive_timeout_ms_()
  , call_ring_timeout_ms_()
  , call_connect_timeout_ms_()
  , call_packet_timeout_ms_()
  , me_url_prefix_()
  , autoupdate_url_prefix_()
  , gif_search_username_()
  , venue_search_username_()
  , img_search_username_()
  , static_maps_provider_()
  , caption_length_max_()
  , message_length_max_()
  , webfile_dc_id_()
  , suggested_lang_code_()
  , lang_pack_version_()
  , base_lang_pack_version_()
  , reactions_default_()
  , autologin_token_()
{}

const std::int32_t config::ID;

object_ptr<config> config::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<config> res = make_tl_object<config>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->default_p2p_contacts_ = (var0 & 8) != 0;
  res->preload_featured_stickers_ = (var0 & 16) != 0;
  res->revoke_pm_inbox_ = (var0 & 64) != 0;
  res->blocked_mode_ = (var0 & 256) != 0;
  res->force_try_ipv6_ = (var0 & 16384) != 0;
  res->fpnv_allowed_ = (var0 & 131072) != 0;
  res->date_ = TlFetchInt::parse(p);
  res->expires_ = TlFetchInt::parse(p);
  res->test_mode_ = TlFetchBool::parse(p);
  res->this_dc_ = TlFetchInt::parse(p);
  res->dc_options_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<dcOption>, 414687501>>, 481674261>::parse(p);
  res->dc_txt_domain_name_ = TlFetchString<string>::parse(p);
  res->chat_size_max_ = TlFetchInt::parse(p);
  res->megagroup_size_max_ = TlFetchInt::parse(p);
  res->forwarded_count_max_ = TlFetchInt::parse(p);
  res->online_update_period_ms_ = TlFetchInt::parse(p);
  res->offline_blur_timeout_ms_ = TlFetchInt::parse(p);
  res->offline_idle_timeout_ms_ = TlFetchInt::parse(p);
  res->online_cloud_timeout_ms_ = TlFetchInt::parse(p);
  res->notify_cloud_delay_ms_ = TlFetchInt::parse(p);
  res->notify_default_delay_ms_ = TlFetchInt::parse(p);
  res->push_chat_period_ms_ = TlFetchInt::parse(p);
  res->push_chat_limit_ = TlFetchInt::parse(p);
  res->edit_time_limit_ = TlFetchInt::parse(p);
  res->revoke_time_limit_ = TlFetchInt::parse(p);
  res->revoke_pm_time_limit_ = TlFetchInt::parse(p);
  res->rating_e_decay_ = TlFetchInt::parse(p);
  res->stickers_recent_limit_ = TlFetchInt::parse(p);
  res->channels_read_media_period_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->tmp_sessions_ = TlFetchInt::parse(p); }
  res->call_receive_timeout_ms_ = TlFetchInt::parse(p);
  res->call_ring_timeout_ms_ = TlFetchInt::parse(p);
  res->call_connect_timeout_ms_ = TlFetchInt::parse(p);
  res->call_packet_timeout_ms_ = TlFetchInt::parse(p);
  res->me_url_prefix_ = TlFetchString<string>::parse(p);
  if (var0 & 128) { res->autoupdate_url_prefix_ = TlFetchString<string>::parse(p); }
  if (var0 & 512) { res->gif_search_username_ = TlFetchString<string>::parse(p); }
  if (var0 & 1024) { res->venue_search_username_ = TlFetchString<string>::parse(p); }
  if (var0 & 2048) { res->img_search_username_ = TlFetchString<string>::parse(p); }
  if (var0 & 4096) { res->static_maps_provider_ = TlFetchString<string>::parse(p); }
  res->caption_length_max_ = TlFetchInt::parse(p);
  res->message_length_max_ = TlFetchInt::parse(p);
  res->webfile_dc_id_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->suggested_lang_code_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->lang_pack_version_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->base_lang_pack_version_ = TlFetchInt::parse(p); }
  if (var0 & 32768) { res->reactions_default_ = TlFetchObject<Reaction>::parse(p); }
  if (var0 & 65536) { res->autologin_token_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void config::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "config");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (default_p2p_contacts_ << 3) | (preload_featured_stickers_ << 4) | (revoke_pm_inbox_ << 6) | (blocked_mode_ << 8) | (force_try_ipv6_ << 14) | (fpnv_allowed_ << 17) | ((!autoupdate_url_prefix_.empty()) << 7) | ((!gif_search_username_.empty()) << 9) | ((!venue_search_username_.empty()) << 10) | ((!img_search_username_.empty()) << 11) | ((!static_maps_provider_.empty()) << 12) | ((!suggested_lang_code_.empty()) << 2) | ((reactions_default_ != nullptr) << 15) | ((!autologin_token_.empty()) << 16)));
    if (var0 & 8) { s.store_field("default_p2p_contacts", true); }
    if (var0 & 16) { s.store_field("preload_featured_stickers", true); }
    if (var0 & 64) { s.store_field("revoke_pm_inbox", true); }
    if (var0 & 256) { s.store_field("blocked_mode", true); }
    if (var0 & 16384) { s.store_field("force_try_ipv6", true); }
    if (var0 & 131072) { s.store_field("fpnv_allowed", true); }
    s.store_field("date", date_);
    s.store_field("expires", expires_);
    s.store_field("test_mode", test_mode_);
    s.store_field("this_dc", this_dc_);
    { s.store_vector_begin("dc_options", dc_options_.size()); for (const auto &_value : dc_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("dc_txt_domain_name", dc_txt_domain_name_);
    s.store_field("chat_size_max", chat_size_max_);
    s.store_field("megagroup_size_max", megagroup_size_max_);
    s.store_field("forwarded_count_max", forwarded_count_max_);
    s.store_field("online_update_period_ms", online_update_period_ms_);
    s.store_field("offline_blur_timeout_ms", offline_blur_timeout_ms_);
    s.store_field("offline_idle_timeout_ms", offline_idle_timeout_ms_);
    s.store_field("online_cloud_timeout_ms", online_cloud_timeout_ms_);
    s.store_field("notify_cloud_delay_ms", notify_cloud_delay_ms_);
    s.store_field("notify_default_delay_ms", notify_default_delay_ms_);
    s.store_field("push_chat_period_ms", push_chat_period_ms_);
    s.store_field("push_chat_limit", push_chat_limit_);
    s.store_field("edit_time_limit", edit_time_limit_);
    s.store_field("revoke_time_limit", revoke_time_limit_);
    s.store_field("revoke_pm_time_limit", revoke_pm_time_limit_);
    s.store_field("rating_e_decay", rating_e_decay_);
    s.store_field("stickers_recent_limit", stickers_recent_limit_);
    s.store_field("channels_read_media_period", channels_read_media_period_);
    if (var0 & 1) { s.store_field("tmp_sessions", tmp_sessions_); }
    s.store_field("call_receive_timeout_ms", call_receive_timeout_ms_);
    s.store_field("call_ring_timeout_ms", call_ring_timeout_ms_);
    s.store_field("call_connect_timeout_ms", call_connect_timeout_ms_);
    s.store_field("call_packet_timeout_ms", call_packet_timeout_ms_);
    s.store_field("me_url_prefix", me_url_prefix_);
    if (var0 & 128) { s.store_field("autoupdate_url_prefix", autoupdate_url_prefix_); }
    if (var0 & 512) { s.store_field("gif_search_username", gif_search_username_); }
    if (var0 & 1024) { s.store_field("venue_search_username", venue_search_username_); }
    if (var0 & 2048) { s.store_field("img_search_username", img_search_username_); }
    if (var0 & 4096) { s.store_field("static_maps_provider", static_maps_provider_); }
    s.store_field("caption_length_max", caption_length_max_);
    s.store_field("message_length_max", message_length_max_);
    s.store_field("webfile_dc_id", webfile_dc_id_);
    if (var0 & 4) { s.store_field("suggested_lang_code", suggested_lang_code_); }
    if (var0 & 4) { s.store_field("lang_pack_version", lang_pack_version_); }
    if (var0 & 4) { s.store_field("base_lang_pack_version", base_lang_pack_version_); }
    if (var0 & 32768) { s.store_object_field("reactions_default", static_cast<const BaseObject *>(reactions_default_.get())); }
    if (var0 & 65536) { s.store_field("autologin_token", "[REDACTED]"); }
    s.store_class_end();
  }
}

const std::int32_t contactBirthday::ID;

object_ptr<contactBirthday> contactBirthday::fetch(TlBufferParser &p) {
  return make_tl_object<contactBirthday>(p);
}

contactBirthday::contactBirthday(TlBufferParser &p)
  : contact_id_(TlFetchLong::parse(p))
  , birthday_(TlFetchBoxed<TlFetchObject<birthday>, 1821253126>::parse(p))
{}

void contactBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contactBirthday");
    s.store_field("contact_id", contact_id_);
    s.store_object_field("birthday", static_cast<const BaseObject *>(birthday_.get()));
    s.store_class_end();
  }
}

const std::int32_t contactStatus::ID;

object_ptr<contactStatus> contactStatus::fetch(TlBufferParser &p) {
  return make_tl_object<contactStatus>(p);
}

contactStatus::contactStatus(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , status_(TlFetchObject<UserStatus>::parse(p))
{}

void contactStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contactStatus");
    s.store_field("user_id", user_id_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

object_ptr<DocumentAttribute> DocumentAttribute::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case documentAttributeImageSize::ID:
      return documentAttributeImageSize::fetch(p);
    case documentAttributeAnimated::ID:
      return documentAttributeAnimated::fetch(p);
    case documentAttributeSticker::ID:
      return documentAttributeSticker::fetch(p);
    case documentAttributeVideo::ID:
      return documentAttributeVideo::fetch(p);
    case documentAttributeAudio::ID:
      return documentAttributeAudio::fetch(p);
    case documentAttributeFilename::ID:
      return documentAttributeFilename::fetch(p);
    case documentAttributeHasStickers::ID:
      return documentAttributeHasStickers::fetch(p);
    case documentAttributeCustomEmoji::ID:
      return documentAttributeCustomEmoji::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

documentAttributeImageSize::documentAttributeImageSize(int32 w_, int32 h_)
  : w_(w_)
  , h_(h_)
{}

const std::int32_t documentAttributeImageSize::ID;

object_ptr<DocumentAttribute> documentAttributeImageSize::fetch(TlBufferParser &p) {
  return make_tl_object<documentAttributeImageSize>(p);
}

documentAttributeImageSize::documentAttributeImageSize(TlBufferParser &p)
  : w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
{}

void documentAttributeImageSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
}

void documentAttributeImageSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
}

void documentAttributeImageSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeImageSize");
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_class_end();
  }
}

const std::int32_t documentAttributeAnimated::ID;

object_ptr<DocumentAttribute> documentAttributeAnimated::fetch(TlBufferParser &p) {
  return make_tl_object<documentAttributeAnimated>();
}

void documentAttributeAnimated::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void documentAttributeAnimated::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void documentAttributeAnimated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeAnimated");
    s.store_class_end();
  }
}

documentAttributeSticker::documentAttributeSticker()
  : flags_()
  , mask_()
  , alt_()
  , stickerset_()
  , mask_coords_()
{}

documentAttributeSticker::documentAttributeSticker(int32 flags_, bool mask_, string const &alt_, object_ptr<InputStickerSet> &&stickerset_, object_ptr<maskCoords> &&mask_coords_)
  : flags_(flags_)
  , mask_(mask_)
  , alt_(alt_)
  , stickerset_(std::move(stickerset_))
  , mask_coords_(std::move(mask_coords_))
{}

const std::int32_t documentAttributeSticker::ID;

object_ptr<DocumentAttribute> documentAttributeSticker::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<documentAttributeSticker> res = make_tl_object<documentAttributeSticker>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->mask_ = (var0 & 2) != 0;
  res->alt_ = TlFetchString<string>::parse(p);
  res->stickerset_ = TlFetchObject<InputStickerSet>::parse(p);
  if (var0 & 1) { res->mask_coords_ = TlFetchBoxed<TlFetchObject<maskCoords>, -1361650766>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void documentAttributeSticker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (mask_ << 1) | ((mask_coords_ != nullptr) << 0)), s);
  TlStoreString::store(alt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
}

void documentAttributeSticker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (mask_ << 1) | ((mask_coords_ != nullptr) << 0)), s);
  TlStoreString::store(alt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
}

void documentAttributeSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeSticker");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (mask_ << 1) | ((mask_coords_ != nullptr) << 0)));
    if (var0 & 2) { s.store_field("mask", true); }
    s.store_field("alt", alt_);
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    if (var0 & 1) { s.store_object_field("mask_coords", static_cast<const BaseObject *>(mask_coords_.get())); }
    s.store_class_end();
  }
}

documentAttributeVideo::documentAttributeVideo()
  : flags_()
  , round_message_()
  , supports_streaming_()
  , nosound_()
  , duration_()
  , w_()
  , h_()
  , preload_prefix_size_()
  , video_start_ts_()
  , video_codec_()
{}

documentAttributeVideo::documentAttributeVideo(int32 flags_, bool round_message_, bool supports_streaming_, bool nosound_, double duration_, int32 w_, int32 h_, int32 preload_prefix_size_, double video_start_ts_, string const &video_codec_)
  : flags_(flags_)
  , round_message_(round_message_)
  , supports_streaming_(supports_streaming_)
  , nosound_(nosound_)
  , duration_(duration_)
  , w_(w_)
  , h_(h_)
  , preload_prefix_size_(preload_prefix_size_)
  , video_start_ts_(video_start_ts_)
  , video_codec_(video_codec_)
{}

const std::int32_t documentAttributeVideo::ID;

object_ptr<DocumentAttribute> documentAttributeVideo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<documentAttributeVideo> res = make_tl_object<documentAttributeVideo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->round_message_ = (var0 & 1) != 0;
  res->supports_streaming_ = (var0 & 2) != 0;
  res->nosound_ = (var0 & 8) != 0;
  res->duration_ = TlFetchDouble::parse(p);
  res->w_ = TlFetchInt::parse(p);
  res->h_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->preload_prefix_size_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->video_start_ts_ = TlFetchDouble::parse(p); }
  if (var0 & 32) { res->video_codec_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void documentAttributeVideo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (round_message_ << 0) | (supports_streaming_ << 1) | (nosound_ << 3) | ((!video_codec_.empty()) << 5)), s);
  TlStoreBinary::store(duration_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  if (var0 & 4) { TlStoreBinary::store(preload_prefix_size_, s); }
  if (var0 & 16) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 32) { TlStoreString::store(video_codec_, s); }
}

void documentAttributeVideo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (round_message_ << 0) | (supports_streaming_ << 1) | (nosound_ << 3) | ((!video_codec_.empty()) << 5)), s);
  TlStoreBinary::store(duration_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  if (var0 & 4) { TlStoreBinary::store(preload_prefix_size_, s); }
  if (var0 & 16) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 32) { TlStoreString::store(video_codec_, s); }
}

void documentAttributeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeVideo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (round_message_ << 0) | (supports_streaming_ << 1) | (nosound_ << 3) | ((!video_codec_.empty()) << 5)));
    if (var0 & 1) { s.store_field("round_message", true); }
    if (var0 & 2) { s.store_field("supports_streaming", true); }
    if (var0 & 8) { s.store_field("nosound", true); }
    s.store_field("duration", duration_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    if (var0 & 4) { s.store_field("preload_prefix_size", preload_prefix_size_); }
    if (var0 & 16) { s.store_field("video_start_ts", video_start_ts_); }
    if (var0 & 32) { s.store_field("video_codec", video_codec_); }
    s.store_class_end();
  }
}

documentAttributeAudio::documentAttributeAudio()
  : flags_()
  , voice_()
  , duration_()
  , title_()
  , performer_()
  , waveform_()
{}

documentAttributeAudio::documentAttributeAudio(int32 flags_, bool voice_, int32 duration_, string const &title_, string const &performer_, bytes &&waveform_)
  : flags_(flags_)
  , voice_(voice_)
  , duration_(duration_)
  , title_(title_)
  , performer_(performer_)
  , waveform_(std::move(waveform_))
{}

const std::int32_t documentAttributeAudio::ID;

object_ptr<DocumentAttribute> documentAttributeAudio::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<documentAttributeAudio> res = make_tl_object<documentAttributeAudio>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->voice_ = (var0 & 1024) != 0;
  res->duration_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->performer_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->waveform_ = TlFetchBytes<bytes>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void documentAttributeAudio::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (voice_ << 10) | ((!title_.empty()) << 0) | ((!performer_.empty()) << 1) | ((!waveform_.empty()) << 2)), s);
  TlStoreBinary::store(duration_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(performer_, s); }
  if (var0 & 4) { TlStoreString::store(waveform_, s); }
}

void documentAttributeAudio::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (voice_ << 10) | ((!title_.empty()) << 0) | ((!performer_.empty()) << 1) | ((!waveform_.empty()) << 2)), s);
  TlStoreBinary::store(duration_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(performer_, s); }
  if (var0 & 4) { TlStoreString::store(waveform_, s); }
}

void documentAttributeAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeAudio");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (voice_ << 10) | ((!title_.empty()) << 0) | ((!performer_.empty()) << 1) | ((!waveform_.empty()) << 2)));
    if (var0 & 1024) { s.store_field("voice", true); }
    s.store_field("duration", duration_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("performer", performer_); }
    if (var0 & 4) { s.store_bytes_field("waveform", waveform_); }
    s.store_class_end();
  }
}

documentAttributeFilename::documentAttributeFilename(string const &file_name_)
  : file_name_(file_name_)
{}

const std::int32_t documentAttributeFilename::ID;

object_ptr<DocumentAttribute> documentAttributeFilename::fetch(TlBufferParser &p) {
  return make_tl_object<documentAttributeFilename>(p);
}

documentAttributeFilename::documentAttributeFilename(TlBufferParser &p)
  : file_name_(TlFetchString<string>::parse(p))
{}

void documentAttributeFilename::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(file_name_, s);
}

void documentAttributeFilename::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(file_name_, s);
}

void documentAttributeFilename::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeFilename");
    s.store_field("file_name", file_name_);
    s.store_class_end();
  }
}

const std::int32_t documentAttributeHasStickers::ID;

object_ptr<DocumentAttribute> documentAttributeHasStickers::fetch(TlBufferParser &p) {
  return make_tl_object<documentAttributeHasStickers>();
}

void documentAttributeHasStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void documentAttributeHasStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void documentAttributeHasStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeHasStickers");
    s.store_class_end();
  }
}

documentAttributeCustomEmoji::documentAttributeCustomEmoji()
  : flags_()
  , free_()
  , text_color_()
  , alt_()
  , stickerset_()
{}

documentAttributeCustomEmoji::documentAttributeCustomEmoji(int32 flags_, bool free_, bool text_color_, string const &alt_, object_ptr<InputStickerSet> &&stickerset_)
  : flags_(flags_)
  , free_(free_)
  , text_color_(text_color_)
  , alt_(alt_)
  , stickerset_(std::move(stickerset_))
{}

const std::int32_t documentAttributeCustomEmoji::ID;

object_ptr<DocumentAttribute> documentAttributeCustomEmoji::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<documentAttributeCustomEmoji> res = make_tl_object<documentAttributeCustomEmoji>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->free_ = (var0 & 1) != 0;
  res->text_color_ = (var0 & 2) != 0;
  res->alt_ = TlFetchString<string>::parse(p);
  res->stickerset_ = TlFetchObject<InputStickerSet>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void documentAttributeCustomEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (free_ << 0) | (text_color_ << 1)), s);
  TlStoreString::store(alt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void documentAttributeCustomEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (free_ << 0) | (text_color_ << 1)), s);
  TlStoreString::store(alt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void documentAttributeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeCustomEmoji");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (free_ << 0) | (text_color_ << 1)));
    if (var0 & 1) { s.store_field("free", true); }
    if (var0 & 2) { s.store_field("text_color", true); }
    s.store_field("alt", alt_);
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

emailVerificationCode::emailVerificationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t emailVerificationCode::ID;

void emailVerificationCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(code_, s);
}

void emailVerificationCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(code_, s);
}

void emailVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerificationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

emailVerificationGoogle::emailVerificationGoogle(string const &token_)
  : token_(token_)
{}

const std::int32_t emailVerificationGoogle::ID;

void emailVerificationGoogle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(token_, s);
}

void emailVerificationGoogle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(token_, s);
}

void emailVerificationGoogle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerificationGoogle");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

emailVerificationApple::emailVerificationApple(string const &token_)
  : token_(token_)
{}

const std::int32_t emailVerificationApple::ID;

void emailVerificationApple::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(token_, s);
}

void emailVerificationApple::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(token_, s);
}

void emailVerificationApple::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerificationApple");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

const std::int32_t emojiLanguage::ID;

object_ptr<emojiLanguage> emojiLanguage::fetch(TlBufferParser &p) {
  return make_tl_object<emojiLanguage>(p);
}

emojiLanguage::emojiLanguage(TlBufferParser &p)
  : lang_code_(TlFetchString<string>::parse(p))
{}

void emojiLanguage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiLanguage");
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

exportedChatlistInvite::exportedChatlistInvite()
  : flags_()
  , title_()
  , url_()
  , peers_()
{}

const std::int32_t exportedChatlistInvite::ID;

object_ptr<exportedChatlistInvite> exportedChatlistInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<exportedChatlistInvite> res = make_tl_object<exportedChatlistInvite>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->title_ = TlFetchString<string>::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  res->peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void exportedChatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "exportedChatlistInvite");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("title", title_);
    s.store_field("url", url_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputBusinessBotRecipients::inputBusinessBotRecipients(int32 flags_, bool existing_chats_, bool new_chats_, bool contacts_, bool non_contacts_, bool exclude_selected_, array<object_ptr<InputUser>> &&users_, array<object_ptr<InputUser>> &&exclude_users_)
  : flags_(flags_)
  , existing_chats_(existing_chats_)
  , new_chats_(new_chats_)
  , contacts_(contacts_)
  , non_contacts_(non_contacts_)
  , exclude_selected_(exclude_selected_)
  , users_(std::move(users_))
  , exclude_users_(std::move(exclude_users_))
{}

const std::int32_t inputBusinessBotRecipients::ID;

void inputBusinessBotRecipients::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5) | ((!users_.empty()) << 4) | ((!exclude_users_.empty()) << 6)), s);
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(exclude_users_, s); }
}

void inputBusinessBotRecipients::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5) | ((!users_.empty()) << 4) | ((!exclude_users_.empty()) << 6)), s);
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(exclude_users_, s); }
}

void inputBusinessBotRecipients::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessBotRecipients");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5) | ((!users_.empty()) << 4) | ((!exclude_users_.empty()) << 6)));
    if (var0 & 1) { s.store_field("existing_chats", true); }
    if (var0 & 2) { s.store_field("new_chats", true); }
    if (var0 & 4) { s.store_field("contacts", true); }
    if (var0 & 8) { s.store_field("non_contacts", true); }
    if (var0 & 32) { s.store_field("exclude_selected", true); }
    if (var0 & 16) { { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 64) { { s.store_vector_begin("exclude_users", exclude_users_.size()); for (const auto &_value : exclude_users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t inputChatPhotoEmpty::ID;

void inputChatPhotoEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputChatPhotoEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputChatPhotoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoEmpty");
    s.store_class_end();
  }
}

inputChatUploadedPhoto::inputChatUploadedPhoto(int32 flags_, object_ptr<InputFile> &&file_, object_ptr<InputFile> &&video_, double video_start_ts_, object_ptr<VideoSize> &&video_emoji_markup_)
  : flags_(flags_)
  , file_(std::move(file_))
  , video_(std::move(video_))
  , video_start_ts_(video_start_ts_)
  , video_emoji_markup_(std::move(video_emoji_markup_))
{}

const std::int32_t inputChatUploadedPhoto::ID;

void inputChatUploadedPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((file_ != nullptr) << 0) | ((video_ != nullptr) << 1) | ((video_emoji_markup_ != nullptr) << 3)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void inputChatUploadedPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((file_ != nullptr) << 0) | ((video_ != nullptr) << 1) | ((video_emoji_markup_ != nullptr) << 3)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void inputChatUploadedPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatUploadedPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((file_ != nullptr) << 0) | ((video_ != nullptr) << 1) | ((video_emoji_markup_ != nullptr) << 3)));
    if (var0 & 1) { s.store_object_field("file", static_cast<const BaseObject *>(file_.get())); }
    if (var0 & 2) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    if (var0 & 4) { s.store_field("video_start_ts", video_start_ts_); }
    if (var0 & 8) { s.store_object_field("video_emoji_markup", static_cast<const BaseObject *>(video_emoji_markup_.get())); }
    s.store_class_end();
  }
}

inputChatPhoto::inputChatPhoto(object_ptr<InputPhoto> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t inputChatPhoto::ID;

void inputChatPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputChatPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhoto");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

object_ptr<InputDocument> InputDocument::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputDocumentEmpty::ID:
      return inputDocumentEmpty::fetch(p);
    case inputDocument::ID:
      return inputDocument::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputDocumentEmpty::ID;

object_ptr<InputDocument> inputDocumentEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputDocumentEmpty>();
}

void inputDocumentEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputDocumentEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputDocumentEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDocumentEmpty");
    s.store_class_end();
  }
}

inputDocument::inputDocument(int64 id_, int64 access_hash_, bytes &&file_reference_)
  : id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
{}

const std::int32_t inputDocument::ID;

object_ptr<InputDocument> inputDocument::fetch(TlBufferParser &p) {
  return make_tl_object<inputDocument>(p);
}

inputDocument::inputDocument(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , file_reference_(TlFetchBytes<bytes>::parse(p))
{}

void inputDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
}

void inputDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
}

void inputDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDocument");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_class_end();
  }
}

inputPasskeyResponseRegister::inputPasskeyResponseRegister(object_ptr<dataJSON> &&client_data_, bytes &&attestation_data_)
  : client_data_(std::move(client_data_))
  , attestation_data_(std::move(attestation_data_))
{}

const std::int32_t inputPasskeyResponseRegister::ID;

void inputPasskeyResponseRegister::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(client_data_, s);
  TlStoreString::store(attestation_data_, s);
}

void inputPasskeyResponseRegister::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(client_data_, s);
  TlStoreString::store(attestation_data_, s);
}

void inputPasskeyResponseRegister::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPasskeyResponseRegister");
    s.store_object_field("client_data", static_cast<const BaseObject *>(client_data_.get()));
    s.store_bytes_field("attestation_data", attestation_data_);
    s.store_class_end();
  }
}

inputPasskeyResponseLogin::inputPasskeyResponseLogin(object_ptr<dataJSON> &&client_data_, bytes &&authenticator_data_, bytes &&signature_, string const &user_handle_)
  : client_data_(std::move(client_data_))
  , authenticator_data_(std::move(authenticator_data_))
  , signature_(std::move(signature_))
  , user_handle_(user_handle_)
{}

const std::int32_t inputPasskeyResponseLogin::ID;

void inputPasskeyResponseLogin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(client_data_, s);
  TlStoreString::store(authenticator_data_, s);
  TlStoreString::store(signature_, s);
  TlStoreString::store(user_handle_, s);
}

void inputPasskeyResponseLogin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(client_data_, s);
  TlStoreString::store(authenticator_data_, s);
  TlStoreString::store(signature_, s);
  TlStoreString::store(user_handle_, s);
}

void inputPasskeyResponseLogin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPasskeyResponseLogin");
    s.store_object_field("client_data", static_cast<const BaseObject *>(client_data_.get()));
    s.store_bytes_field("authenticator_data", authenticator_data_);
    s.store_bytes_field("signature", signature_);
    s.store_field("user_handle", user_handle_);
    s.store_class_end();
  }
}

object_ptr<InputReplyTo> InputReplyTo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputReplyToMessage::ID:
      return inputReplyToMessage::fetch(p);
    case inputReplyToStory::ID:
      return inputReplyToStory::fetch(p);
    case inputReplyToMonoForum::ID:
      return inputReplyToMonoForum::fetch(p);
    case inputReplyToEphemeralMessage::ID:
      return inputReplyToEphemeralMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputReplyToMessage::inputReplyToMessage()
  : flags_()
  , reply_to_msg_id_()
  , top_msg_id_()
  , reply_to_peer_id_()
  , quote_text_()
  , quote_entities_()
  , quote_offset_()
  , monoforum_peer_id_()
  , todo_item_id_()
  , poll_option_()
  , quote_rich_()
{}

inputReplyToMessage::inputReplyToMessage(int32 flags_, int32 reply_to_msg_id_, int32 top_msg_id_, object_ptr<InputPeer> &&reply_to_peer_id_, string const &quote_text_, array<object_ptr<MessageEntity>> &&quote_entities_, int32 quote_offset_, object_ptr<InputPeer> &&monoforum_peer_id_, int32 todo_item_id_, bytes &&poll_option_, array<object_ptr<RichText>> &&quote_rich_)
  : flags_(flags_)
  , reply_to_msg_id_(reply_to_msg_id_)
  , top_msg_id_(top_msg_id_)
  , reply_to_peer_id_(std::move(reply_to_peer_id_))
  , quote_text_(quote_text_)
  , quote_entities_(std::move(quote_entities_))
  , quote_offset_(quote_offset_)
  , monoforum_peer_id_(std::move(monoforum_peer_id_))
  , todo_item_id_(todo_item_id_)
  , poll_option_(std::move(poll_option_))
  , quote_rich_(std::move(quote_rich_))
{}

const std::int32_t inputReplyToMessage::ID;

object_ptr<InputReplyTo> inputReplyToMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputReplyToMessage> res = make_tl_object<inputReplyToMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->reply_to_msg_id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->reply_to_peer_id_ = TlFetchObject<InputPeer>::parse(p); }
  if (var0 & 4) { res->quote_text_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->quote_entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 16) { res->quote_offset_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->monoforum_peer_id_ = TlFetchObject<InputPeer>::parse(p); }
  if (var0 & 64) { res->todo_item_id_ = TlFetchInt::parse(p); }
  if (var0 & 128) { res->poll_option_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 256) { res->quote_rich_ = TlFetchBoxed<TlFetchVector<TlFetchObject<RichText>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputReplyToMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_to_peer_id_ != nullptr) << 1) | ((!quote_text_.empty()) << 2) | ((!quote_entities_.empty()) << 3) | ((monoforum_peer_id_ != nullptr) << 5) | ((!poll_option_.empty()) << 7) | ((!quote_rich_.empty()) << 8)), s);
  TlStoreBinary::store(reply_to_msg_id_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_peer_id_, s); }
  if (var0 & 4) { TlStoreString::store(quote_text_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(quote_entities_, s); }
  if (var0 & 16) { TlStoreBinary::store(quote_offset_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(monoforum_peer_id_, s); }
  if (var0 & 64) { TlStoreBinary::store(todo_item_id_, s); }
  if (var0 & 128) { TlStoreString::store(poll_option_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(quote_rich_, s); }
}

void inputReplyToMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_to_peer_id_ != nullptr) << 1) | ((!quote_text_.empty()) << 2) | ((!quote_entities_.empty()) << 3) | ((monoforum_peer_id_ != nullptr) << 5) | ((!poll_option_.empty()) << 7) | ((!quote_rich_.empty()) << 8)), s);
  TlStoreBinary::store(reply_to_msg_id_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_peer_id_, s); }
  if (var0 & 4) { TlStoreString::store(quote_text_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(quote_entities_, s); }
  if (var0 & 16) { TlStoreBinary::store(quote_offset_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(monoforum_peer_id_, s); }
  if (var0 & 64) { TlStoreBinary::store(todo_item_id_, s); }
  if (var0 & 128) { TlStoreString::store(poll_option_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(quote_rich_, s); }
}

void inputReplyToMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReplyToMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_to_peer_id_ != nullptr) << 1) | ((!quote_text_.empty()) << 2) | ((!quote_entities_.empty()) << 3) | ((monoforum_peer_id_ != nullptr) << 5) | ((!poll_option_.empty()) << 7) | ((!quote_rich_.empty()) << 8)));
    s.store_field("reply_to_msg_id", reply_to_msg_id_);
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("reply_to_peer_id", static_cast<const BaseObject *>(reply_to_peer_id_.get())); }
    if (var0 & 4) { s.store_field("quote_text", quote_text_); }
    if (var0 & 8) { { s.store_vector_begin("quote_entities", quote_entities_.size()); for (const auto &_value : quote_entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("quote_offset", quote_offset_); }
    if (var0 & 32) { s.store_object_field("monoforum_peer_id", static_cast<const BaseObject *>(monoforum_peer_id_.get())); }
    if (var0 & 64) { s.store_field("todo_item_id", todo_item_id_); }
    if (var0 & 128) { s.store_bytes_field("poll_option", poll_option_); }
    if (var0 & 256) { { s.store_vector_begin("quote_rich", quote_rich_.size()); for (const auto &_value : quote_rich_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

inputReplyToStory::inputReplyToStory(object_ptr<InputPeer> &&peer_, int32 story_id_)
  : peer_(std::move(peer_))
  , story_id_(story_id_)
{}

const std::int32_t inputReplyToStory::ID;

object_ptr<InputReplyTo> inputReplyToStory::fetch(TlBufferParser &p) {
  return make_tl_object<inputReplyToStory>(p);
}

inputReplyToStory::inputReplyToStory(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , story_id_(TlFetchInt::parse(p))
{}

void inputReplyToStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(story_id_, s);
}

void inputReplyToStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(story_id_, s);
}

void inputReplyToStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReplyToStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

inputReplyToMonoForum::inputReplyToMonoForum(object_ptr<InputPeer> &&monoforum_peer_id_)
  : monoforum_peer_id_(std::move(monoforum_peer_id_))
{}

const std::int32_t inputReplyToMonoForum::ID;

object_ptr<InputReplyTo> inputReplyToMonoForum::fetch(TlBufferParser &p) {
  return make_tl_object<inputReplyToMonoForum>(p);
}

inputReplyToMonoForum::inputReplyToMonoForum(TlBufferParser &p)
  : monoforum_peer_id_(TlFetchObject<InputPeer>::parse(p))
{}

void inputReplyToMonoForum::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(monoforum_peer_id_, s);
}

void inputReplyToMonoForum::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(monoforum_peer_id_, s);
}

void inputReplyToMonoForum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReplyToMonoForum");
    s.store_object_field("monoforum_peer_id", static_cast<const BaseObject *>(monoforum_peer_id_.get()));
    s.store_class_end();
  }
}

inputReplyToEphemeralMessage::inputReplyToEphemeralMessage(int32 id_)
  : id_(id_)
{}

const std::int32_t inputReplyToEphemeralMessage::ID;

object_ptr<InputReplyTo> inputReplyToEphemeralMessage::fetch(TlBufferParser &p) {
  return make_tl_object<inputReplyToEphemeralMessage>(p);
}

inputReplyToEphemeralMessage::inputReplyToEphemeralMessage(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
{}

void inputReplyToEphemeralMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputReplyToEphemeralMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputReplyToEphemeralMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReplyToEphemeralMessage");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

keyboardButton::keyboardButton()
  : flags_()
  , style_()
  , text_()
  , type_()
{}

keyboardButton::keyboardButton(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, object_ptr<ButtonType> &&type_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
  , type_(std::move(type_))
{}

const std::int32_t keyboardButton::ID;

object_ptr<keyboardButton> keyboardButton::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButton> res = make_tl_object<keyboardButton>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->type_ = TlFetchObject<ButtonType>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void keyboardButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((style_ != nullptr) << 10)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
}

void keyboardButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((style_ != nullptr) << 10)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
}

void keyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButton");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((style_ != nullptr) << 10)));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

keyboardInlineButton::keyboardInlineButton()
  : flags_()
  , style_()
  , text_()
  , type_()
{}

keyboardInlineButton::keyboardInlineButton(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, object_ptr<InlineButtonType> &&type_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
  , type_(std::move(type_))
{}

const std::int32_t keyboardInlineButton::ID;

object_ptr<keyboardInlineButton> keyboardInlineButton::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardInlineButton> res = make_tl_object<keyboardInlineButton>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->type_ = TlFetchObject<InlineButtonType>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void keyboardInlineButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((style_ != nullptr) << 10)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
}

void keyboardInlineButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((style_ != nullptr) << 10)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
}

void keyboardInlineButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardInlineButton");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((style_ != nullptr) << 10)));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

mediaAreaCoordinates::mediaAreaCoordinates()
  : flags_()
  , x_()
  , y_()
  , w_()
  , h_()
  , rotation_()
  , radius_()
{}

mediaAreaCoordinates::mediaAreaCoordinates(int32 flags_, double x_, double y_, double w_, double h_, double rotation_, double radius_)
  : flags_(flags_)
  , x_(x_)
  , y_(y_)
  , w_(w_)
  , h_(h_)
  , rotation_(rotation_)
  , radius_(radius_)
{}

const std::int32_t mediaAreaCoordinates::ID;

object_ptr<mediaAreaCoordinates> mediaAreaCoordinates::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<mediaAreaCoordinates> res = make_tl_object<mediaAreaCoordinates>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->x_ = TlFetchDouble::parse(p);
  res->y_ = TlFetchDouble::parse(p);
  res->w_ = TlFetchDouble::parse(p);
  res->h_ = TlFetchDouble::parse(p);
  res->rotation_ = TlFetchDouble::parse(p);
  if (var0 & 1) { res->radius_ = TlFetchDouble::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void mediaAreaCoordinates::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(x_, s);
  TlStoreBinary::store(y_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(rotation_, s);
  if (var0 & 1) { TlStoreBinary::store(radius_, s); }
}

void mediaAreaCoordinates::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(x_, s);
  TlStoreBinary::store(y_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(rotation_, s);
  if (var0 & 1) { TlStoreBinary::store(radius_, s); }
}

void mediaAreaCoordinates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaCoordinates");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("x", x_);
    s.store_field("y", y_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_field("rotation", rotation_);
    if (var0 & 1) { s.store_field("radius", radius_); }
    s.store_class_end();
  }
}

object_ptr<MessageAction> MessageAction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messageActionEmpty::ID:
      return messageActionEmpty::fetch(p);
    case messageActionChatCreate::ID:
      return messageActionChatCreate::fetch(p);
    case messageActionChatEditTitle::ID:
      return messageActionChatEditTitle::fetch(p);
    case messageActionChatEditPhoto::ID:
      return messageActionChatEditPhoto::fetch(p);
    case messageActionChatDeletePhoto::ID:
      return messageActionChatDeletePhoto::fetch(p);
    case messageActionChatAddUser::ID:
      return messageActionChatAddUser::fetch(p);
    case messageActionChatDeleteUser::ID:
      return messageActionChatDeleteUser::fetch(p);
    case messageActionChatJoinedByLink::ID:
      return messageActionChatJoinedByLink::fetch(p);
    case messageActionChannelCreate::ID:
      return messageActionChannelCreate::fetch(p);
    case messageActionChatMigrateTo::ID:
      return messageActionChatMigrateTo::fetch(p);
    case messageActionChannelMigrateFrom::ID:
      return messageActionChannelMigrateFrom::fetch(p);
    case messageActionPinMessage::ID:
      return messageActionPinMessage::fetch(p);
    case messageActionHistoryClear::ID:
      return messageActionHistoryClear::fetch(p);
    case messageActionGameScore::ID:
      return messageActionGameScore::fetch(p);
    case messageActionPaymentSentMe::ID:
      return messageActionPaymentSentMe::fetch(p);
    case messageActionPaymentSent::ID:
      return messageActionPaymentSent::fetch(p);
    case messageActionPhoneCall::ID:
      return messageActionPhoneCall::fetch(p);
    case messageActionScreenshotTaken::ID:
      return messageActionScreenshotTaken::fetch(p);
    case messageActionCustomAction::ID:
      return messageActionCustomAction::fetch(p);
    case messageActionBotAllowed::ID:
      return messageActionBotAllowed::fetch(p);
    case messageActionSecureValuesSentMe::ID:
      return messageActionSecureValuesSentMe::fetch(p);
    case messageActionSecureValuesSent::ID:
      return messageActionSecureValuesSent::fetch(p);
    case messageActionContactSignUp::ID:
      return messageActionContactSignUp::fetch(p);
    case messageActionGeoProximityReached::ID:
      return messageActionGeoProximityReached::fetch(p);
    case messageActionGroupCall::ID:
      return messageActionGroupCall::fetch(p);
    case messageActionInviteToGroupCall::ID:
      return messageActionInviteToGroupCall::fetch(p);
    case messageActionSetMessagesTTL::ID:
      return messageActionSetMessagesTTL::fetch(p);
    case messageActionGroupCallScheduled::ID:
      return messageActionGroupCallScheduled::fetch(p);
    case messageActionSetChatTheme::ID:
      return messageActionSetChatTheme::fetch(p);
    case messageActionChatJoinedByRequest::ID:
      return messageActionChatJoinedByRequest::fetch(p);
    case messageActionWebViewDataSentMe::ID:
      return messageActionWebViewDataSentMe::fetch(p);
    case messageActionWebViewDataSent::ID:
      return messageActionWebViewDataSent::fetch(p);
    case messageActionGiftPremium::ID:
      return messageActionGiftPremium::fetch(p);
    case messageActionTopicCreate::ID:
      return messageActionTopicCreate::fetch(p);
    case messageActionTopicEdit::ID:
      return messageActionTopicEdit::fetch(p);
    case messageActionSuggestProfilePhoto::ID:
      return messageActionSuggestProfilePhoto::fetch(p);
    case messageActionRequestedPeer::ID:
      return messageActionRequestedPeer::fetch(p);
    case messageActionSetChatWallPaper::ID:
      return messageActionSetChatWallPaper::fetch(p);
    case messageActionGiftCode::ID:
      return messageActionGiftCode::fetch(p);
    case messageActionGiveawayLaunch::ID:
      return messageActionGiveawayLaunch::fetch(p);
    case messageActionGiveawayResults::ID:
      return messageActionGiveawayResults::fetch(p);
    case messageActionBoostApply::ID:
      return messageActionBoostApply::fetch(p);
    case messageActionRequestedPeerSentMe::ID:
      return messageActionRequestedPeerSentMe::fetch(p);
    case messageActionPaymentRefunded::ID:
      return messageActionPaymentRefunded::fetch(p);
    case messageActionGiftStars::ID:
      return messageActionGiftStars::fetch(p);
    case messageActionPrizeStars::ID:
      return messageActionPrizeStars::fetch(p);
    case messageActionStarGift::ID:
      return messageActionStarGift::fetch(p);
    case messageActionStarGiftUnique::ID:
      return messageActionStarGiftUnique::fetch(p);
    case messageActionPaidMessagesRefunded::ID:
      return messageActionPaidMessagesRefunded::fetch(p);
    case messageActionPaidMessagesPrice::ID:
      return messageActionPaidMessagesPrice::fetch(p);
    case messageActionConferenceCall::ID:
      return messageActionConferenceCall::fetch(p);
    case messageActionTodoCompletions::ID:
      return messageActionTodoCompletions::fetch(p);
    case messageActionTodoAppendTasks::ID:
      return messageActionTodoAppendTasks::fetch(p);
    case messageActionSuggestedPostApproval::ID:
      return messageActionSuggestedPostApproval::fetch(p);
    case messageActionSuggestedPostSuccess::ID:
      return messageActionSuggestedPostSuccess::fetch(p);
    case messageActionSuggestedPostRefund::ID:
      return messageActionSuggestedPostRefund::fetch(p);
    case messageActionGiftTon::ID:
      return messageActionGiftTon::fetch(p);
    case messageActionSuggestBirthday::ID:
      return messageActionSuggestBirthday::fetch(p);
    case messageActionStarGiftPurchaseOffer::ID:
      return messageActionStarGiftPurchaseOffer::fetch(p);
    case messageActionStarGiftPurchaseOfferDeclined::ID:
      return messageActionStarGiftPurchaseOfferDeclined::fetch(p);
    case messageActionNewCreatorPending::ID:
      return messageActionNewCreatorPending::fetch(p);
    case messageActionChangeCreator::ID:
      return messageActionChangeCreator::fetch(p);
    case messageActionNoForwardsToggle::ID:
      return messageActionNoForwardsToggle::fetch(p);
    case messageActionNoForwardsRequest::ID:
      return messageActionNoForwardsRequest::fetch(p);
    case messageActionPollAppendAnswer::ID:
      return messageActionPollAppendAnswer::fetch(p);
    case messageActionPollDeleteAnswer::ID:
      return messageActionPollDeleteAnswer::fetch(p);
    case messageActionManagedBotCreated::ID:
      return messageActionManagedBotCreated::fetch(p);
    case messageActionChangeCommunity::ID:
      return messageActionChangeCommunity::fetch(p);
    case messageActionChatJoinedViaCommunity::ID:
      return messageActionChatJoinedViaCommunity::fetch(p);
    case messageActionGramTransfer::ID:
      return messageActionGramTransfer::fetch(p);
    case messageActionWalletTonConnectRequest::ID:
      return messageActionWalletTonConnectRequest::fetch(p);
    case messageActionNoPaidMessagesTokenUsed::ID:
      return messageActionNoPaidMessagesTokenUsed::fetch(p);
    case messageActionStarGiftOnchainOffer::ID:
      return messageActionStarGiftOnchainOffer::fetch(p);
    case messageActionBotInvite::ID:
      return messageActionBotInvite::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messageActionEmpty::ID;

object_ptr<MessageAction> messageActionEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionEmpty>();
}

void messageActionEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionEmpty");
    s.store_class_end();
  }
}

const std::int32_t messageActionChatCreate::ID;

object_ptr<MessageAction> messageActionChatCreate::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatCreate>(p);
}

messageActionChatCreate::messageActionChatCreate(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void messageActionChatCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatCreate");
    s.store_field("title", title_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messageActionChatEditTitle::ID;

object_ptr<MessageAction> messageActionChatEditTitle::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatEditTitle>(p);
}

messageActionChatEditTitle::messageActionChatEditTitle(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
{}

void messageActionChatEditTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatEditTitle");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChatEditPhoto::ID;

object_ptr<MessageAction> messageActionChatEditPhoto::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatEditPhoto>(p);
}

messageActionChatEditPhoto::messageActionChatEditPhoto(TlBufferParser &p)
  : photo_(TlFetchObject<Photo>::parse(p))
{}

void messageActionChatEditPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatEditPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionChatDeletePhoto::ID;

object_ptr<MessageAction> messageActionChatDeletePhoto::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatDeletePhoto>();
}

void messageActionChatDeletePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatDeletePhoto");
    s.store_class_end();
  }
}

const std::int32_t messageActionChatAddUser::ID;

object_ptr<MessageAction> messageActionChatAddUser::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatAddUser>(p);
}

messageActionChatAddUser::messageActionChatAddUser(TlBufferParser &p)
  : users_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void messageActionChatAddUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatAddUser");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messageActionChatDeleteUser::ID;

object_ptr<MessageAction> messageActionChatDeleteUser::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatDeleteUser>(p);
}

messageActionChatDeleteUser::messageActionChatDeleteUser(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
{}

void messageActionChatDeleteUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatDeleteUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChatJoinedByLink::ID;

object_ptr<MessageAction> messageActionChatJoinedByLink::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatJoinedByLink>(p);
}

messageActionChatJoinedByLink::messageActionChatJoinedByLink(TlBufferParser &p)
  : inviter_id_(TlFetchLong::parse(p))
{}

void messageActionChatJoinedByLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatJoinedByLink");
    s.store_field("inviter_id", inviter_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChannelCreate::ID;

object_ptr<MessageAction> messageActionChannelCreate::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChannelCreate>(p);
}

messageActionChannelCreate::messageActionChannelCreate(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
{}

void messageActionChannelCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChannelCreate");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChatMigrateTo::ID;

object_ptr<MessageAction> messageActionChatMigrateTo::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatMigrateTo>(p);
}

messageActionChatMigrateTo::messageActionChatMigrateTo(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
{}

void messageActionChatMigrateTo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatMigrateTo");
    s.store_field("channel_id", channel_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChannelMigrateFrom::ID;

object_ptr<MessageAction> messageActionChannelMigrateFrom::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChannelMigrateFrom>(p);
}

messageActionChannelMigrateFrom::messageActionChannelMigrateFrom(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , chat_id_(TlFetchLong::parse(p))
{}

void messageActionChannelMigrateFrom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChannelMigrateFrom");
    s.store_field("title", title_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionPinMessage::ID;

object_ptr<MessageAction> messageActionPinMessage::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionPinMessage>();
}

void messageActionPinMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPinMessage");
    s.store_class_end();
  }
}

const std::int32_t messageActionHistoryClear::ID;

object_ptr<MessageAction> messageActionHistoryClear::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionHistoryClear>();
}

void messageActionHistoryClear::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionHistoryClear");
    s.store_class_end();
  }
}

const std::int32_t messageActionGameScore::ID;

object_ptr<MessageAction> messageActionGameScore::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionGameScore>(p);
}

messageActionGameScore::messageActionGameScore(TlBufferParser &p)
  : game_id_(TlFetchLong::parse(p))
  , score_(TlFetchInt::parse(p))
{}

void messageActionGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGameScore");
    s.store_field("game_id", game_id_);
    s.store_field("score", score_);
    s.store_class_end();
  }
}

messageActionPaymentSentMe::messageActionPaymentSentMe()
  : flags_()
  , recurring_init_()
  , recurring_used_()
  , currency_()
  , total_amount_()
  , payload_()
  , info_()
  , shipping_option_id_()
  , charge_()
  , subscription_until_date_()
{}

const std::int32_t messageActionPaymentSentMe::ID;

object_ptr<MessageAction> messageActionPaymentSentMe::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPaymentSentMe> res = make_tl_object<messageActionPaymentSentMe>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->recurring_init_ = (var0 & 4) != 0;
  res->recurring_used_ = (var0 & 8) != 0;
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  res->payload_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 1) { res->info_ = TlFetchBoxed<TlFetchObject<paymentRequestedInfo>, -1868808300>::parse(p); }
  if (var0 & 2) { res->shipping_option_id_ = TlFetchString<string>::parse(p); }
  res->charge_ = TlFetchBoxed<TlFetchObject<paymentCharge>, -368917890>::parse(p);
  if (var0 & 16) { res->subscription_until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPaymentSentMe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPaymentSentMe");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (recurring_init_ << 2) | (recurring_used_ << 3) | ((info_ != nullptr) << 0) | ((!shipping_option_id_.empty()) << 1)));
    if (var0 & 4) { s.store_field("recurring_init", true); }
    if (var0 & 8) { s.store_field("recurring_used", true); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_bytes_field("payload", payload_);
    if (var0 & 1) { s.store_object_field("info", static_cast<const BaseObject *>(info_.get())); }
    if (var0 & 2) { s.store_field("shipping_option_id", shipping_option_id_); }
    s.store_object_field("charge", static_cast<const BaseObject *>(charge_.get()));
    if (var0 & 16) { s.store_field("subscription_until_date", subscription_until_date_); }
    s.store_class_end();
  }
}

messageActionPaymentSent::messageActionPaymentSent()
  : flags_()
  , recurring_init_()
  , recurring_used_()
  , currency_()
  , total_amount_()
  , invoice_slug_()
  , subscription_until_date_()
{}

const std::int32_t messageActionPaymentSent::ID;

object_ptr<MessageAction> messageActionPaymentSent::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPaymentSent> res = make_tl_object<messageActionPaymentSent>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->recurring_init_ = (var0 & 4) != 0;
  res->recurring_used_ = (var0 & 8) != 0;
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->invoice_slug_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->subscription_until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPaymentSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPaymentSent");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (recurring_init_ << 2) | (recurring_used_ << 3) | ((!invoice_slug_.empty()) << 0)));
    if (var0 & 4) { s.store_field("recurring_init", true); }
    if (var0 & 8) { s.store_field("recurring_used", true); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    if (var0 & 1) { s.store_field("invoice_slug", invoice_slug_); }
    if (var0 & 16) { s.store_field("subscription_until_date", subscription_until_date_); }
    s.store_class_end();
  }
}

messageActionPhoneCall::messageActionPhoneCall()
  : flags_()
  , video_()
  , call_id_()
  , reason_()
  , duration_()
{}

const std::int32_t messageActionPhoneCall::ID;

object_ptr<MessageAction> messageActionPhoneCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPhoneCall> res = make_tl_object<messageActionPhoneCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->video_ = (var0 & 4) != 0;
  res->call_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->reason_ = TlFetchObject<PhoneCallDiscardReason>::parse(p); }
  if (var0 & 2) { res->duration_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPhoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPhoneCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (video_ << 2) | ((reason_ != nullptr) << 0)));
    if (var0 & 4) { s.store_field("video", true); }
    s.store_field("call_id", call_id_);
    if (var0 & 1) { s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get())); }
    if (var0 & 2) { s.store_field("duration", duration_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionScreenshotTaken::ID;

object_ptr<MessageAction> messageActionScreenshotTaken::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionScreenshotTaken>();
}

void messageActionScreenshotTaken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionScreenshotTaken");
    s.store_class_end();
  }
}

const std::int32_t messageActionCustomAction::ID;

object_ptr<MessageAction> messageActionCustomAction::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionCustomAction>(p);
}

messageActionCustomAction::messageActionCustomAction(TlBufferParser &p)
  : message_(TlFetchString<string>::parse(p))
{}

void messageActionCustomAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionCustomAction");
    s.store_field("message", message_);
    s.store_class_end();
  }
}

messageActionBotAllowed::messageActionBotAllowed()
  : flags_()
  , attach_menu_()
  , from_request_()
  , domain_()
  , app_()
{}

const std::int32_t messageActionBotAllowed::ID;

object_ptr<MessageAction> messageActionBotAllowed::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionBotAllowed> res = make_tl_object<messageActionBotAllowed>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->attach_menu_ = (var0 & 2) != 0;
  res->from_request_ = (var0 & 8) != 0;
  if (var0 & 1) { res->domain_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->app_ = TlFetchObject<BotApp>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionBotAllowed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionBotAllowed");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (attach_menu_ << 1) | (from_request_ << 3) | ((!domain_.empty()) << 0) | ((app_ != nullptr) << 2)));
    if (var0 & 2) { s.store_field("attach_menu", true); }
    if (var0 & 8) { s.store_field("from_request", true); }
    if (var0 & 1) { s.store_field("domain", domain_); }
    if (var0 & 4) { s.store_object_field("app", static_cast<const BaseObject *>(app_.get())); }
    s.store_class_end();
  }
}

const std::int32_t messageActionSecureValuesSentMe::ID;

object_ptr<MessageAction> messageActionSecureValuesSentMe::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSecureValuesSentMe>(p);
}

messageActionSecureValuesSentMe::messageActionSecureValuesSentMe(TlBufferParser &p)
  : values_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<secureValue>, 411017418>>, 481674261>::parse(p))
  , credentials_(TlFetchBoxed<TlFetchObject<secureCredentialsEncrypted>, 871426631>::parse(p))
{}

void messageActionSecureValuesSentMe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSecureValuesSentMe");
    { s.store_vector_begin("values", values_.size()); for (const auto &_value : values_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionSecureValuesSent::ID;

object_ptr<MessageAction> messageActionSecureValuesSent::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSecureValuesSent>(p);
}

messageActionSecureValuesSent::messageActionSecureValuesSent(TlBufferParser &p)
  : types_(TlFetchBoxed<TlFetchVector<TlFetchObject<SecureValueType>>, 481674261>::parse(p))
{}

void messageActionSecureValuesSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSecureValuesSent");
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messageActionContactSignUp::ID;

object_ptr<MessageAction> messageActionContactSignUp::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionContactSignUp>();
}

void messageActionContactSignUp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionContactSignUp");
    s.store_class_end();
  }
}

const std::int32_t messageActionGeoProximityReached::ID;

object_ptr<MessageAction> messageActionGeoProximityReached::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionGeoProximityReached>(p);
}

messageActionGeoProximityReached::messageActionGeoProximityReached(TlBufferParser &p)
  : from_id_(TlFetchObject<Peer>::parse(p))
  , to_id_(TlFetchObject<Peer>::parse(p))
  , distance_(TlFetchInt::parse(p))
{}

void messageActionGeoProximityReached::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGeoProximityReached");
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_object_field("to_id", static_cast<const BaseObject *>(to_id_.get()));
    s.store_field("distance", distance_);
    s.store_class_end();
  }
}

messageActionGroupCall::messageActionGroupCall()
  : flags_()
  , call_()
  , duration_()
{}

const std::int32_t messageActionGroupCall::ID;

object_ptr<MessageAction> messageActionGroupCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGroupCall> res = make_tl_object<messageActionGroupCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->call_ = TlFetchObject<InputGroupCall>::parse(p);
  if (var0 & 1) { res->duration_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGroupCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    if (var0 & 1) { s.store_field("duration", duration_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionInviteToGroupCall::ID;

object_ptr<MessageAction> messageActionInviteToGroupCall::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionInviteToGroupCall>(p);
}

messageActionInviteToGroupCall::messageActionInviteToGroupCall(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void messageActionInviteToGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionInviteToGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageActionSetMessagesTTL::messageActionSetMessagesTTL()
  : flags_()
  , period_()
  , auto_setting_from_()
{}

const std::int32_t messageActionSetMessagesTTL::ID;

object_ptr<MessageAction> messageActionSetMessagesTTL::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionSetMessagesTTL> res = make_tl_object<messageActionSetMessagesTTL>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->period_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->auto_setting_from_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionSetMessagesTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSetMessagesTTL");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("period", period_);
    if (var0 & 1) { s.store_field("auto_setting_from", auto_setting_from_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionGroupCallScheduled::ID;

object_ptr<MessageAction> messageActionGroupCallScheduled::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionGroupCallScheduled>(p);
}

messageActionGroupCallScheduled::messageActionGroupCallScheduled(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , schedule_date_(TlFetchInt::parse(p))
{}

void messageActionGroupCallScheduled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGroupCallScheduled");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("schedule_date", schedule_date_);
    s.store_class_end();
  }
}

const std::int32_t messageActionSetChatTheme::ID;

object_ptr<MessageAction> messageActionSetChatTheme::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSetChatTheme>(p);
}

messageActionSetChatTheme::messageActionSetChatTheme(TlBufferParser &p)
  : theme_(TlFetchObject<ChatTheme>::parse(p))
{}

void messageActionSetChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSetChatTheme");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionChatJoinedByRequest::ID;

object_ptr<MessageAction> messageActionChatJoinedByRequest::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatJoinedByRequest>();
}

void messageActionChatJoinedByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatJoinedByRequest");
    s.store_class_end();
  }
}

const std::int32_t messageActionWebViewDataSentMe::ID;

object_ptr<MessageAction> messageActionWebViewDataSentMe::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionWebViewDataSentMe>(p);
}

messageActionWebViewDataSentMe::messageActionWebViewDataSentMe(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , data_(TlFetchString<string>::parse(p))
{}

void messageActionWebViewDataSentMe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionWebViewDataSentMe");
    s.store_field("text", text_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

const std::int32_t messageActionWebViewDataSent::ID;

object_ptr<MessageAction> messageActionWebViewDataSent::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionWebViewDataSent>(p);
}

messageActionWebViewDataSent::messageActionWebViewDataSent(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
{}

void messageActionWebViewDataSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionWebViewDataSent");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

messageActionGiftPremium::messageActionGiftPremium()
  : flags_()
  , currency_()
  , amount_()
  , days_()
  , crypto_currency_()
  , crypto_amount_()
  , message_()
{}

const std::int32_t messageActionGiftPremium::ID;

object_ptr<MessageAction> messageActionGiftPremium::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiftPremium> res = make_tl_object<messageActionGiftPremium>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->days_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->crypto_currency_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->crypto_amount_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiftPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiftPremium");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!crypto_currency_.empty()) << 0) | ((message_ != nullptr) << 1)));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("days", days_);
    if (var0 & 1) { s.store_field("crypto_currency", crypto_currency_); }
    if (var0 & 1) { s.store_field("crypto_amount", crypto_amount_); }
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

messageActionTopicCreate::messageActionTopicCreate()
  : flags_()
  , title_missing_()
  , title_()
  , icon_color_()
  , icon_emoji_id_()
{}

const std::int32_t messageActionTopicCreate::ID;

object_ptr<MessageAction> messageActionTopicCreate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionTopicCreate> res = make_tl_object<messageActionTopicCreate>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->title_missing_ = (var0 & 2) != 0;
  res->title_ = TlFetchString<string>::parse(p);
  res->icon_color_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->icon_emoji_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionTopicCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionTopicCreate");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (title_missing_ << 1)));
    if (var0 & 2) { s.store_field("title_missing", true); }
    s.store_field("title", title_);
    s.store_field("icon_color", icon_color_);
    if (var0 & 1) { s.store_field("icon_emoji_id", icon_emoji_id_); }
    s.store_class_end();
  }
}

messageActionTopicEdit::messageActionTopicEdit()
  : flags_()
  , title_()
  , icon_emoji_id_()
  , closed_()
  , hidden_()
{}

const std::int32_t messageActionTopicEdit::ID;

object_ptr<MessageAction> messageActionTopicEdit::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionTopicEdit> res = make_tl_object<messageActionTopicEdit>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->icon_emoji_id_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->closed_ = TlFetchBool::parse(p); }
  if (var0 & 8) { res->hidden_ = TlFetchBool::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionTopicEdit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionTopicEdit");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 0)));
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("icon_emoji_id", icon_emoji_id_); }
    if (var0 & 4) { s.store_field("closed", closed_); }
    if (var0 & 8) { s.store_field("hidden", hidden_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionSuggestProfilePhoto::ID;

object_ptr<MessageAction> messageActionSuggestProfilePhoto::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSuggestProfilePhoto>(p);
}

messageActionSuggestProfilePhoto::messageActionSuggestProfilePhoto(TlBufferParser &p)
  : photo_(TlFetchObject<Photo>::parse(p))
{}

void messageActionSuggestProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSuggestProfilePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionRequestedPeer::ID;

object_ptr<MessageAction> messageActionRequestedPeer::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionRequestedPeer>(p);
}

messageActionRequestedPeer::messageActionRequestedPeer(TlBufferParser &p)
  : button_id_(TlFetchInt::parse(p))
  , peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
{}

void messageActionRequestedPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionRequestedPeer");
    s.store_field("button_id", button_id_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageActionSetChatWallPaper::messageActionSetChatWallPaper()
  : flags_()
  , same_()
  , for_both_()
  , wallpaper_()
{}

const std::int32_t messageActionSetChatWallPaper::ID;

object_ptr<MessageAction> messageActionSetChatWallPaper::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionSetChatWallPaper> res = make_tl_object<messageActionSetChatWallPaper>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->same_ = (var0 & 1) != 0;
  res->for_both_ = (var0 & 2) != 0;
  res->wallpaper_ = TlFetchObject<WallPaper>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionSetChatWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSetChatWallPaper");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (same_ << 0) | (for_both_ << 1)));
    if (var0 & 1) { s.store_field("same", true); }
    if (var0 & 2) { s.store_field("for_both", true); }
    s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get()));
    s.store_class_end();
  }
}

messageActionGiftCode::messageActionGiftCode()
  : flags_()
  , via_giveaway_()
  , unclaimed_()
  , boost_peer_()
  , days_()
  , slug_()
  , currency_()
  , amount_()
  , crypto_currency_()
  , crypto_amount_()
  , message_()
{}

const std::int32_t messageActionGiftCode::ID;

object_ptr<MessageAction> messageActionGiftCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiftCode> res = make_tl_object<messageActionGiftCode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_giveaway_ = (var0 & 1) != 0;
  res->unclaimed_ = (var0 & 32) != 0;
  if (var0 & 2) { res->boost_peer_ = TlFetchObject<Peer>::parse(p); }
  res->days_ = TlFetchInt::parse(p);
  res->slug_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->currency_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->amount_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->crypto_currency_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->crypto_amount_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiftCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_giveaway_ << 0) | (unclaimed_ << 5) | ((boost_peer_ != nullptr) << 1) | ((!currency_.empty()) << 2) | ((!crypto_currency_.empty()) << 3) | ((message_ != nullptr) << 4)));
    if (var0 & 1) { s.store_field("via_giveaway", true); }
    if (var0 & 32) { s.store_field("unclaimed", true); }
    if (var0 & 2) { s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get())); }
    s.store_field("days", days_);
    s.store_field("slug", slug_);
    if (var0 & 4) { s.store_field("currency", currency_); }
    if (var0 & 4) { s.store_field("amount", amount_); }
    if (var0 & 8) { s.store_field("crypto_currency", crypto_currency_); }
    if (var0 & 8) { s.store_field("crypto_amount", crypto_amount_); }
    if (var0 & 16) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

messageActionGiveawayLaunch::messageActionGiveawayLaunch()
  : flags_()
  , stars_()
{}

const std::int32_t messageActionGiveawayLaunch::ID;

object_ptr<MessageAction> messageActionGiveawayLaunch::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiveawayLaunch> res = make_tl_object<messageActionGiveawayLaunch>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->stars_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiveawayLaunch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiveawayLaunch");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("stars", stars_); }
    s.store_class_end();
  }
}

messageActionGiveawayResults::messageActionGiveawayResults()
  : flags_()
  , stars_()
  , winners_count_()
  , unclaimed_count_()
{}

const std::int32_t messageActionGiveawayResults::ID;

object_ptr<MessageAction> messageActionGiveawayResults::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiveawayResults> res = make_tl_object<messageActionGiveawayResults>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->stars_ = (var0 & 1) != 0;
  res->winners_count_ = TlFetchInt::parse(p);
  res->unclaimed_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiveawayResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiveawayResults");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (stars_ << 0)));
    if (var0 & 1) { s.store_field("stars", true); }
    s.store_field("winners_count", winners_count_);
    s.store_field("unclaimed_count", unclaimed_count_);
    s.store_class_end();
  }
}

const std::int32_t messageActionBoostApply::ID;

object_ptr<MessageAction> messageActionBoostApply::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionBoostApply>(p);
}

messageActionBoostApply::messageActionBoostApply(TlBufferParser &p)
  : boosts_(TlFetchInt::parse(p))
{}

void messageActionBoostApply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionBoostApply");
    s.store_field("boosts", boosts_);
    s.store_class_end();
  }
}

const std::int32_t messageActionRequestedPeerSentMe::ID;

object_ptr<MessageAction> messageActionRequestedPeerSentMe::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionRequestedPeerSentMe>(p);
}

messageActionRequestedPeerSentMe::messageActionRequestedPeerSentMe(TlBufferParser &p)
  : button_id_(TlFetchInt::parse(p))
  , peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<RequestedPeer>>, 481674261>::parse(p))
{}

void messageActionRequestedPeerSentMe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionRequestedPeerSentMe");
    s.store_field("button_id", button_id_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageActionPaymentRefunded::messageActionPaymentRefunded()
  : flags_()
  , peer_()
  , currency_()
  , total_amount_()
  , payload_()
  , charge_()
{}

const std::int32_t messageActionPaymentRefunded::ID;

object_ptr<MessageAction> messageActionPaymentRefunded::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPaymentRefunded> res = make_tl_object<messageActionPaymentRefunded>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->payload_ = TlFetchBytes<bytes>::parse(p); }
  res->charge_ = TlFetchBoxed<TlFetchObject<paymentCharge>, -368917890>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPaymentRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPaymentRefunded");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!payload_.empty()) << 0)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    if (var0 & 1) { s.store_bytes_field("payload", payload_); }
    s.store_object_field("charge", static_cast<const BaseObject *>(charge_.get()));
    s.store_class_end();
  }
}

messageActionGiftStars::messageActionGiftStars()
  : flags_()
  , currency_()
  , amount_()
  , stars_()
  , crypto_currency_()
  , crypto_amount_()
  , transaction_id_()
{}

const std::int32_t messageActionGiftStars::ID;

object_ptr<MessageAction> messageActionGiftStars::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiftStars> res = make_tl_object<messageActionGiftStars>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->stars_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->crypto_currency_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->crypto_amount_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->transaction_id_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiftStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiftStars");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!crypto_currency_.empty()) << 0) | ((!transaction_id_.empty()) << 1)));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("stars", stars_);
    if (var0 & 1) { s.store_field("crypto_currency", crypto_currency_); }
    if (var0 & 1) { s.store_field("crypto_amount", crypto_amount_); }
    if (var0 & 2) { s.store_field("transaction_id", transaction_id_); }
    s.store_class_end();
  }
}

messageActionPrizeStars::messageActionPrizeStars()
  : flags_()
  , unclaimed_()
  , stars_()
  , transaction_id_()
  , boost_peer_()
  , giveaway_msg_id_()
{}

const std::int32_t messageActionPrizeStars::ID;

object_ptr<MessageAction> messageActionPrizeStars::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPrizeStars> res = make_tl_object<messageActionPrizeStars>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->unclaimed_ = (var0 & 1) != 0;
  res->stars_ = TlFetchLong::parse(p);
  res->transaction_id_ = TlFetchString<string>::parse(p);
  res->boost_peer_ = TlFetchObject<Peer>::parse(p);
  res->giveaway_msg_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPrizeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPrizeStars");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (unclaimed_ << 0)));
    if (var0 & 1) { s.store_field("unclaimed", true); }
    s.store_field("stars", stars_);
    s.store_field("transaction_id", transaction_id_);
    s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get()));
    s.store_field("giveaway_msg_id", giveaway_msg_id_);
    s.store_class_end();
  }
}

messageActionStarGift::messageActionStarGift()
  : flags_()
  , name_hidden_()
  , saved_()
  , converted_()
  , upgraded_()
  , refunded_()
  , can_upgrade_()
  , prepaid_upgrade_()
  , upgrade_separate_()
  , auction_acquired_()
  , gift_()
  , message_()
  , convert_stars_()
  , upgrade_msg_id_()
  , upgrade_stars_()
  , from_id_()
  , peer_()
  , saved_id_()
  , prepaid_upgrade_hash_()
  , gift_msg_id_()
  , to_id_()
  , gift_num_()
{}

const std::int32_t messageActionStarGift::ID;

object_ptr<MessageAction> messageActionStarGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionStarGift> res = make_tl_object<messageActionStarGift>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->name_hidden_ = (var0 & 1) != 0;
  res->saved_ = (var0 & 4) != 0;
  res->converted_ = (var0 & 8) != 0;
  res->upgraded_ = (var0 & 32) != 0;
  res->refunded_ = (var0 & 512) != 0;
  res->can_upgrade_ = (var0 & 1024) != 0;
  res->prepaid_upgrade_ = (var0 & 8192) != 0;
  res->upgrade_separate_ = (var0 & 65536) != 0;
  res->auction_acquired_ = (var0 & 131072) != 0;
  res->gift_ = TlFetchObject<StarGift>::parse(p);
  if (var0 & 2) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (var0 & 16) { res->convert_stars_ = TlFetchLong::parse(p); }
  if (var0 & 32) { res->upgrade_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->upgrade_stars_ = TlFetchLong::parse(p); }
  if (var0 & 2048) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 4096) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 4096) { res->saved_id_ = TlFetchLong::parse(p); }
  if (var0 & 16384) { res->prepaid_upgrade_hash_ = TlFetchString<string>::parse(p); }
  if (var0 & 32768) { res->gift_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 262144) { res->to_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 524288) { res->gift_num_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionStarGift");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (name_hidden_ << 0) | (saved_ << 2) | (converted_ << 3) | (upgraded_ << 5) | (refunded_ << 9) | (can_upgrade_ << 10) | (prepaid_upgrade_ << 13) | (upgrade_separate_ << 16) | (auction_acquired_ << 17) | ((message_ != nullptr) << 1) | ((from_id_ != nullptr) << 11) | ((peer_ != nullptr) << 12) | ((!prepaid_upgrade_hash_.empty()) << 14) | ((to_id_ != nullptr) << 18)));
    if (var0 & 1) { s.store_field("name_hidden", true); }
    if (var0 & 4) { s.store_field("saved", true); }
    if (var0 & 8) { s.store_field("converted", true); }
    if (var0 & 32) { s.store_field("upgraded", true); }
    if (var0 & 512) { s.store_field("refunded", true); }
    if (var0 & 1024) { s.store_field("can_upgrade", true); }
    if (var0 & 8192) { s.store_field("prepaid_upgrade", true); }
    if (var0 & 65536) { s.store_field("upgrade_separate", true); }
    if (var0 & 131072) { s.store_field("auction_acquired", true); }
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    if (var0 & 16) { s.store_field("convert_stars", convert_stars_); }
    if (var0 & 32) { s.store_field("upgrade_msg_id", upgrade_msg_id_); }
    if (var0 & 256) { s.store_field("upgrade_stars", upgrade_stars_); }
    if (var0 & 2048) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 4096) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 4096) { s.store_field("saved_id", saved_id_); }
    if (var0 & 16384) { s.store_field("prepaid_upgrade_hash", prepaid_upgrade_hash_); }
    if (var0 & 32768) { s.store_field("gift_msg_id", gift_msg_id_); }
    if (var0 & 262144) { s.store_object_field("to_id", static_cast<const BaseObject *>(to_id_.get())); }
    if (var0 & 524288) { s.store_field("gift_num", gift_num_); }
    s.store_class_end();
  }
}

messageActionStarGiftUnique::messageActionStarGiftUnique()
  : flags_()
  , upgrade_()
  , transferred_()
  , saved_()
  , refunded_()
  , prepaid_upgrade_()
  , assigned_()
  , from_offer_()
  , craft_()
  , name_hidden_()
  , gift_()
  , can_export_at_()
  , transfer_stars_()
  , from_id_()
  , peer_()
  , saved_id_()
  , resale_amount_()
  , can_transfer_at_()
  , can_resell_at_()
  , drop_original_details_stars_()
  , can_craft_at_()
  , message_()
{}

const std::int32_t messageActionStarGiftUnique::ID;

object_ptr<MessageAction> messageActionStarGiftUnique::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionStarGiftUnique> res = make_tl_object<messageActionStarGiftUnique>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->upgrade_ = (var0 & 1) != 0;
  res->transferred_ = (var0 & 2) != 0;
  res->saved_ = (var0 & 4) != 0;
  res->refunded_ = (var0 & 32) != 0;
  res->prepaid_upgrade_ = (var0 & 2048) != 0;
  res->assigned_ = (var0 & 8192) != 0;
  res->from_offer_ = (var0 & 16384) != 0;
  res->craft_ = (var0 & 65536) != 0;
  res->name_hidden_ = (var0 & 131072) != 0;
  res->gift_ = TlFetchObject<StarGift>::parse(p);
  if (var0 & 8) { res->can_export_at_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->transfer_stars_ = TlFetchLong::parse(p); }
  if (var0 & 64) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 128) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 128) { res->saved_id_ = TlFetchLong::parse(p); }
  if (var0 & 256) { res->resale_amount_ = TlFetchObject<StarsAmount>::parse(p); }
  if (var0 & 512) { res->can_transfer_at_ = TlFetchInt::parse(p); }
  if (var0 & 1024) { res->can_resell_at_ = TlFetchInt::parse(p); }
  if (var0 & 4096) { res->drop_original_details_stars_ = TlFetchLong::parse(p); }
  if (var0 & 32768) { res->can_craft_at_ = TlFetchInt::parse(p); }
  if (var0 & 262144) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionStarGiftUnique::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionStarGiftUnique");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (upgrade_ << 0) | (transferred_ << 1) | (saved_ << 2) | (refunded_ << 5) | (prepaid_upgrade_ << 11) | (assigned_ << 13) | (from_offer_ << 14) | (craft_ << 16) | (name_hidden_ << 17) | ((from_id_ != nullptr) << 6) | ((peer_ != nullptr) << 7) | ((resale_amount_ != nullptr) << 8) | ((message_ != nullptr) << 18)));
    if (var0 & 1) { s.store_field("upgrade", true); }
    if (var0 & 2) { s.store_field("transferred", true); }
    if (var0 & 4) { s.store_field("saved", true); }
    if (var0 & 32) { s.store_field("refunded", true); }
    if (var0 & 2048) { s.store_field("prepaid_upgrade", true); }
    if (var0 & 8192) { s.store_field("assigned", true); }
    if (var0 & 16384) { s.store_field("from_offer", true); }
    if (var0 & 65536) { s.store_field("craft", true); }
    if (var0 & 131072) { s.store_field("name_hidden", true); }
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    if (var0 & 8) { s.store_field("can_export_at", can_export_at_); }
    if (var0 & 16) { s.store_field("transfer_stars", transfer_stars_); }
    if (var0 & 64) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 128) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 128) { s.store_field("saved_id", saved_id_); }
    if (var0 & 256) { s.store_object_field("resale_amount", static_cast<const BaseObject *>(resale_amount_.get())); }
    if (var0 & 512) { s.store_field("can_transfer_at", can_transfer_at_); }
    if (var0 & 1024) { s.store_field("can_resell_at", can_resell_at_); }
    if (var0 & 4096) { s.store_field("drop_original_details_stars", drop_original_details_stars_); }
    if (var0 & 32768) { s.store_field("can_craft_at", can_craft_at_); }
    if (var0 & 262144) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

const std::int32_t messageActionPaidMessagesRefunded::ID;

object_ptr<MessageAction> messageActionPaidMessagesRefunded::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionPaidMessagesRefunded>(p);
}

messageActionPaidMessagesRefunded::messageActionPaidMessagesRefunded(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , stars_(TlFetchLong::parse(p))
{}

void messageActionPaidMessagesRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPaidMessagesRefunded");
    s.store_field("count", count_);
    s.store_field("stars", stars_);
    s.store_class_end();
  }
}

messageActionPaidMessagesPrice::messageActionPaidMessagesPrice()
  : flags_()
  , broadcast_messages_allowed_()
  , stars_()
{}

const std::int32_t messageActionPaidMessagesPrice::ID;

object_ptr<MessageAction> messageActionPaidMessagesPrice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPaidMessagesPrice> res = make_tl_object<messageActionPaidMessagesPrice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->broadcast_messages_allowed_ = (var0 & 1) != 0;
  res->stars_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPaidMessagesPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPaidMessagesPrice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (broadcast_messages_allowed_ << 0)));
    if (var0 & 1) { s.store_field("broadcast_messages_allowed", true); }
    s.store_field("stars", stars_);
    s.store_class_end();
  }
}

messageActionConferenceCall::messageActionConferenceCall()
  : flags_()
  , missed_()
  , active_()
  , video_()
  , call_id_()
  , duration_()
  , other_participants_()
{}

const std::int32_t messageActionConferenceCall::ID;

object_ptr<MessageAction> messageActionConferenceCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionConferenceCall> res = make_tl_object<messageActionConferenceCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->missed_ = (var0 & 1) != 0;
  res->active_ = (var0 & 2) != 0;
  res->video_ = (var0 & 16) != 0;
  res->call_id_ = TlFetchLong::parse(p);
  if (var0 & 4) { res->duration_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->other_participants_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionConferenceCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionConferenceCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (missed_ << 0) | (active_ << 1) | (video_ << 4) | ((!other_participants_.empty()) << 3)));
    if (var0 & 1) { s.store_field("missed", true); }
    if (var0 & 2) { s.store_field("active", true); }
    if (var0 & 16) { s.store_field("video", true); }
    s.store_field("call_id", call_id_);
    if (var0 & 4) { s.store_field("duration", duration_); }
    if (var0 & 8) { { s.store_vector_begin("other_participants", other_participants_.size()); for (const auto &_value : other_participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t messageActionTodoCompletions::ID;

object_ptr<MessageAction> messageActionTodoCompletions::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionTodoCompletions>(p);
}

messageActionTodoCompletions::messageActionTodoCompletions(TlBufferParser &p)
  : completed_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , incompleted_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void messageActionTodoCompletions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionTodoCompletions");
    { s.store_vector_begin("completed", completed_.size()); for (const auto &_value : completed_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("incompleted", incompleted_.size()); for (const auto &_value : incompleted_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messageActionTodoAppendTasks::ID;

object_ptr<MessageAction> messageActionTodoAppendTasks::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionTodoAppendTasks>(p);
}

messageActionTodoAppendTasks::messageActionTodoAppendTasks(TlBufferParser &p)
  : list_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<todoItem>, -878074577>>, 481674261>::parse(p))
{}

void messageActionTodoAppendTasks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionTodoAppendTasks");
    { s.store_vector_begin("list", list_.size()); for (const auto &_value : list_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageActionSuggestedPostApproval::messageActionSuggestedPostApproval()
  : flags_()
  , rejected_()
  , balance_too_low_()
  , reject_comment_()
  , schedule_date_()
  , price_()
{}

const std::int32_t messageActionSuggestedPostApproval::ID;

object_ptr<MessageAction> messageActionSuggestedPostApproval::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionSuggestedPostApproval> res = make_tl_object<messageActionSuggestedPostApproval>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->rejected_ = (var0 & 1) != 0;
  res->balance_too_low_ = (var0 & 2) != 0;
  if (var0 & 4) { res->reject_comment_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->schedule_date_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->price_ = TlFetchObject<StarsAmount>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionSuggestedPostApproval::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSuggestedPostApproval");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (rejected_ << 0) | (balance_too_low_ << 1) | ((!reject_comment_.empty()) << 2) | ((price_ != nullptr) << 4)));
    if (var0 & 1) { s.store_field("rejected", true); }
    if (var0 & 2) { s.store_field("balance_too_low", true); }
    if (var0 & 4) { s.store_field("reject_comment", reject_comment_); }
    if (var0 & 8) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 16) { s.store_object_field("price", static_cast<const BaseObject *>(price_.get())); }
    s.store_class_end();
  }
}

const std::int32_t messageActionSuggestedPostSuccess::ID;

object_ptr<MessageAction> messageActionSuggestedPostSuccess::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSuggestedPostSuccess>(p);
}

messageActionSuggestedPostSuccess::messageActionSuggestedPostSuccess(TlBufferParser &p)
  : price_(TlFetchObject<StarsAmount>::parse(p))
{}

void messageActionSuggestedPostSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSuggestedPostSuccess");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

messageActionSuggestedPostRefund::messageActionSuggestedPostRefund()
  : flags_()
  , payer_initiated_()
{}

const std::int32_t messageActionSuggestedPostRefund::ID;

object_ptr<MessageAction> messageActionSuggestedPostRefund::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionSuggestedPostRefund> res = make_tl_object<messageActionSuggestedPostRefund>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->payer_initiated_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionSuggestedPostRefund::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSuggestedPostRefund");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (payer_initiated_ << 0)));
    if (var0 & 1) { s.store_field("payer_initiated", true); }
    s.store_class_end();
  }
}

messageActionGiftTon::messageActionGiftTon()
  : flags_()
  , currency_()
  , amount_()
  , crypto_currency_()
  , crypto_amount_()
  , transaction_id_()
{}

const std::int32_t messageActionGiftTon::ID;

object_ptr<MessageAction> messageActionGiftTon::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiftTon> res = make_tl_object<messageActionGiftTon>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->crypto_currency_ = TlFetchString<string>::parse(p);
  res->crypto_amount_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->transaction_id_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiftTon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiftTon");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!transaction_id_.empty()) << 0)));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("crypto_currency", crypto_currency_);
    s.store_field("crypto_amount", crypto_amount_);
    if (var0 & 1) { s.store_field("transaction_id", transaction_id_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionSuggestBirthday::ID;

object_ptr<MessageAction> messageActionSuggestBirthday::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSuggestBirthday>(p);
}

messageActionSuggestBirthday::messageActionSuggestBirthday(TlBufferParser &p)
  : birthday_(TlFetchBoxed<TlFetchObject<birthday>, 1821253126>::parse(p))
{}

void messageActionSuggestBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSuggestBirthday");
    s.store_object_field("birthday", static_cast<const BaseObject *>(birthday_.get()));
    s.store_class_end();
  }
}

messageActionStarGiftPurchaseOffer::messageActionStarGiftPurchaseOffer()
  : flags_()
  , accepted_()
  , declined_()
  , gift_()
  , price_()
  , expires_at_()
{}

const std::int32_t messageActionStarGiftPurchaseOffer::ID;

object_ptr<MessageAction> messageActionStarGiftPurchaseOffer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionStarGiftPurchaseOffer> res = make_tl_object<messageActionStarGiftPurchaseOffer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->accepted_ = (var0 & 1) != 0;
  res->declined_ = (var0 & 2) != 0;
  res->gift_ = TlFetchObject<StarGift>::parse(p);
  res->price_ = TlFetchObject<StarsAmount>::parse(p);
  res->expires_at_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionStarGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionStarGiftPurchaseOffer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (accepted_ << 0) | (declined_ << 1)));
    if (var0 & 1) { s.store_field("accepted", true); }
    if (var0 & 2) { s.store_field("declined", true); }
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("expires_at", expires_at_);
    s.store_class_end();
  }
}

messageActionStarGiftPurchaseOfferDeclined::messageActionStarGiftPurchaseOfferDeclined()
  : flags_()
  , expired_()
  , gift_()
  , price_()
{}

const std::int32_t messageActionStarGiftPurchaseOfferDeclined::ID;

object_ptr<MessageAction> messageActionStarGiftPurchaseOfferDeclined::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionStarGiftPurchaseOfferDeclined> res = make_tl_object<messageActionStarGiftPurchaseOfferDeclined>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->expired_ = (var0 & 1) != 0;
  res->gift_ = TlFetchObject<StarGift>::parse(p);
  res->price_ = TlFetchObject<StarsAmount>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionStarGiftPurchaseOfferDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionStarGiftPurchaseOfferDeclined");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (expired_ << 0)));
    if (var0 & 1) { s.store_field("expired", true); }
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionNewCreatorPending::ID;

object_ptr<MessageAction> messageActionNewCreatorPending::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionNewCreatorPending>(p);
}

messageActionNewCreatorPending::messageActionNewCreatorPending(TlBufferParser &p)
  : new_creator_id_(TlFetchLong::parse(p))
{}

void messageActionNewCreatorPending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionNewCreatorPending");
    s.store_field("new_creator_id", new_creator_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChangeCreator::ID;

object_ptr<MessageAction> messageActionChangeCreator::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChangeCreator>(p);
}

messageActionChangeCreator::messageActionChangeCreator(TlBufferParser &p)
  : new_creator_id_(TlFetchLong::parse(p))
{}

void messageActionChangeCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChangeCreator");
    s.store_field("new_creator_id", new_creator_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionNoForwardsToggle::ID;

object_ptr<MessageAction> messageActionNoForwardsToggle::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionNoForwardsToggle>(p);
}

messageActionNoForwardsToggle::messageActionNoForwardsToggle(TlBufferParser &p)
  : prev_value_(TlFetchBool::parse(p))
  , new_value_(TlFetchBool::parse(p))
{}

void messageActionNoForwardsToggle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionNoForwardsToggle");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

messageActionNoForwardsRequest::messageActionNoForwardsRequest()
  : flags_()
  , expired_()
  , prev_value_()
  , new_value_()
{}

const std::int32_t messageActionNoForwardsRequest::ID;

object_ptr<MessageAction> messageActionNoForwardsRequest::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionNoForwardsRequest> res = make_tl_object<messageActionNoForwardsRequest>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->expired_ = (var0 & 1) != 0;
  res->prev_value_ = TlFetchBool::parse(p);
  res->new_value_ = TlFetchBool::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionNoForwardsRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionNoForwardsRequest");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (expired_ << 0)));
    if (var0 & 1) { s.store_field("expired", true); }
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t messageActionPollAppendAnswer::ID;

object_ptr<MessageAction> messageActionPollAppendAnswer::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionPollAppendAnswer>(p);
}

messageActionPollAppendAnswer::messageActionPollAppendAnswer(TlBufferParser &p)
  : answer_(TlFetchObject<PollAnswer>::parse(p))
{}

void messageActionPollAppendAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPollAppendAnswer");
    s.store_object_field("answer", static_cast<const BaseObject *>(answer_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionPollDeleteAnswer::ID;

object_ptr<MessageAction> messageActionPollDeleteAnswer::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionPollDeleteAnswer>(p);
}

messageActionPollDeleteAnswer::messageActionPollDeleteAnswer(TlBufferParser &p)
  : answer_(TlFetchObject<PollAnswer>::parse(p))
{}

void messageActionPollDeleteAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPollDeleteAnswer");
    s.store_object_field("answer", static_cast<const BaseObject *>(answer_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionManagedBotCreated::ID;

object_ptr<MessageAction> messageActionManagedBotCreated::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionManagedBotCreated>(p);
}

messageActionManagedBotCreated::messageActionManagedBotCreated(TlBufferParser &p)
  : bot_id_(TlFetchLong::parse(p))
{}

void messageActionManagedBotCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionManagedBotCreated");
    s.store_field("bot_id", bot_id_);
    s.store_class_end();
  }
}

messageActionChangeCommunity::messageActionChangeCommunity()
  : flags_()
  , community_id_()
{}

const std::int32_t messageActionChangeCommunity::ID;

object_ptr<MessageAction> messageActionChangeCommunity::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionChangeCommunity> res = make_tl_object<messageActionChangeCommunity>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->community_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionChangeCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChangeCommunity");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("community_id", community_id_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionChatJoinedViaCommunity::ID;

object_ptr<MessageAction> messageActionChatJoinedViaCommunity::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatJoinedViaCommunity>(p);
}

messageActionChatJoinedViaCommunity::messageActionChatJoinedViaCommunity(TlBufferParser &p)
  : community_id_(TlFetchLong::parse(p))
{}

void messageActionChatJoinedViaCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatJoinedViaCommunity");
    s.store_field("community_id", community_id_);
    s.store_class_end();
  }
}

messageActionGramTransfer::messageActionGramTransfer()
  : flags_()
  , comment_encrypted_()
  , amount_()
  , peer_address_()
  , transaction_id_()
  , comment_()
  , onramp_provider_name_()
{}

const std::int32_t messageActionGramTransfer::ID;

object_ptr<MessageAction> messageActionGramTransfer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGramTransfer> res = make_tl_object<messageActionGramTransfer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->comment_encrypted_ = (var0 & 2) != 0;
  res->amount_ = TlFetchLong::parse(p);
  res->peer_address_ = TlFetchString<string>::parse(p);
  res->transaction_id_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->comment_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->onramp_provider_name_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGramTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGramTransfer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (comment_encrypted_ << 1) | ((!comment_.empty()) << 0) | ((!onramp_provider_name_.empty()) << 2)));
    if (var0 & 2) { s.store_field("comment_encrypted", true); }
    s.store_field("amount", amount_);
    s.store_field("peer_address", peer_address_);
    s.store_field("transaction_id", transaction_id_);
    if (var0 & 1) { s.store_field("comment", comment_); }
    if (var0 & 4) { s.store_field("onramp_provider_name", onramp_provider_name_); }
    s.store_class_end();
  }
}

messageActionWalletTonConnectRequest::messageActionWalletTonConnectRequest()
  : flags_()
  , accepted_()
  , declined_()
  , session_id_()
  , expires_()
  , topic_()
  , trace_id_()
  , dapp_name_()
{}

const std::int32_t messageActionWalletTonConnectRequest::ID;

object_ptr<MessageAction> messageActionWalletTonConnectRequest::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionWalletTonConnectRequest> res = make_tl_object<messageActionWalletTonConnectRequest>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->accepted_ = (var0 & 4) != 0;
  res->declined_ = (var0 & 8) != 0;
  res->session_id_ = TlFetchLong::parse(p);
  res->expires_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->topic_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->trace_id_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->dapp_name_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionWalletTonConnectRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionWalletTonConnectRequest");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (accepted_ << 2) | (declined_ << 3) | ((!topic_.empty()) << 0) | ((!trace_id_.empty()) << 1) | ((!dapp_name_.empty()) << 4)));
    if (var0 & 4) { s.store_field("accepted", true); }
    if (var0 & 8) { s.store_field("declined", true); }
    s.store_field("session_id", session_id_);
    s.store_field("expires", expires_);
    if (var0 & 1) { s.store_field("topic", topic_); }
    if (var0 & 2) { s.store_field("trace_id", trace_id_); }
    if (var0 & 16) { s.store_field("dapp_name", dapp_name_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionNoPaidMessagesTokenUsed::ID;

object_ptr<MessageAction> messageActionNoPaidMessagesTokenUsed::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionNoPaidMessagesTokenUsed>();
}

void messageActionNoPaidMessagesTokenUsed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionNoPaidMessagesTokenUsed");
    s.store_class_end();
  }
}

messageActionStarGiftOnchainOffer::messageActionStarGiftOnchainOffer()
  : flags_()
  , accepted_()
  , declined_()
  , cancelled_()
  , expired_()
  , settled_()
  , buyer_()
  , cancelling_()
  , offer_id_()
  , gift_()
  , amount_()
  , fee_bps_()
  , expires_at_()
  , offer_address_()
  , buyer_refund_()
  , fine_()
{}

const std::int32_t messageActionStarGiftOnchainOffer::ID;

object_ptr<MessageAction> messageActionStarGiftOnchainOffer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionStarGiftOnchainOffer> res = make_tl_object<messageActionStarGiftOnchainOffer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->accepted_ = (var0 & 1) != 0;
  res->declined_ = (var0 & 2) != 0;
  res->cancelled_ = (var0 & 4) != 0;
  res->expired_ = (var0 & 8) != 0;
  res->settled_ = (var0 & 64) != 0;
  res->buyer_ = (var0 & 128) != 0;
  res->cancelling_ = (var0 & 256) != 0;
  res->offer_id_ = TlFetchLong::parse(p);
  res->gift_ = TlFetchObject<StarGift>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->fee_bps_ = TlFetchInt::parse(p);
  res->expires_at_ = TlFetchInt::parse(p);
  res->offer_address_ = TlFetchString<string>::parse(p);
  if (var0 & 16) { res->buyer_refund_ = TlFetchLong::parse(p); }
  if (var0 & 32) { res->fine_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionStarGiftOnchainOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionStarGiftOnchainOffer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (accepted_ << 0) | (declined_ << 1) | (cancelled_ << 2) | (expired_ << 3) | (settled_ << 6) | (buyer_ << 7) | (cancelling_ << 8)));
    if (var0 & 1) { s.store_field("accepted", true); }
    if (var0 & 2) { s.store_field("declined", true); }
    if (var0 & 4) { s.store_field("cancelled", true); }
    if (var0 & 8) { s.store_field("expired", true); }
    if (var0 & 64) { s.store_field("settled", true); }
    if (var0 & 128) { s.store_field("buyer", true); }
    if (var0 & 256) { s.store_field("cancelling", true); }
    s.store_field("offer_id", offer_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("amount", amount_);
    s.store_field("fee_bps", fee_bps_);
    s.store_field("expires_at", expires_at_);
    s.store_field("offer_address", offer_address_);
    if (var0 & 16) { s.store_field("buyer_refund", buyer_refund_); }
    if (var0 & 32) { s.store_field("fine", fine_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionBotInvite::ID;

object_ptr<MessageAction> messageActionBotInvite::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionBotInvite>(p);
}

messageActionBotInvite::messageActionBotInvite(TlBufferParser &p)
  : inviter_id_(TlFetchLong::parse(p))
{}

void messageActionBotInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionBotInvite");
    s.store_field("inviter_id", inviter_id_);
    s.store_class_end();
  }
}

messageFwdHeader::messageFwdHeader()
  : flags_()
  , imported_()
  , saved_out_()
  , from_id_()
  , from_name_()
  , date_()
  , channel_post_()
  , post_author_()
  , saved_from_peer_()
  , saved_from_msg_id_()
  , saved_from_id_()
  , saved_from_name_()
  , saved_date_()
  , psa_type_()
{}

const std::int32_t messageFwdHeader::ID;

object_ptr<messageFwdHeader> messageFwdHeader::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageFwdHeader> res = make_tl_object<messageFwdHeader>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->imported_ = (var0 & 128) != 0;
  res->saved_out_ = (var0 & 2048) != 0;
  if (var0 & 1) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 32) { res->from_name_ = TlFetchString<string>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->channel_post_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->post_author_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->saved_from_peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 16) { res->saved_from_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->saved_from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 512) { res->saved_from_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 1024) { res->saved_date_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->psa_type_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messageFwdHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageFwdHeader");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (imported_ << 7) | (saved_out_ << 11) | ((from_id_ != nullptr) << 0) | ((!from_name_.empty()) << 5) | ((!post_author_.empty()) << 3) | ((saved_from_peer_ != nullptr) << 4) | ((saved_from_id_ != nullptr) << 8) | ((!saved_from_name_.empty()) << 9) | ((!psa_type_.empty()) << 6)));
    if (var0 & 128) { s.store_field("imported", true); }
    if (var0 & 2048) { s.store_field("saved_out", true); }
    if (var0 & 1) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 32) { s.store_field("from_name", from_name_); }
    s.store_field("date", date_);
    if (var0 & 4) { s.store_field("channel_post", channel_post_); }
    if (var0 & 8) { s.store_field("post_author", post_author_); }
    if (var0 & 16) { s.store_object_field("saved_from_peer", static_cast<const BaseObject *>(saved_from_peer_.get())); }
    if (var0 & 16) { s.store_field("saved_from_msg_id", saved_from_msg_id_); }
    if (var0 & 256) { s.store_object_field("saved_from_id", static_cast<const BaseObject *>(saved_from_id_.get())); }
    if (var0 & 512) { s.store_field("saved_from_name", saved_from_name_); }
    if (var0 & 1024) { s.store_field("saved_date", saved_date_); }
    if (var0 & 64) { s.store_field("psa_type", psa_type_); }
    s.store_class_end();
  }
}

messagePeerReaction::messagePeerReaction()
  : flags_()
  , big_()
  , unread_()
  , my_()
  , peer_id_()
  , date_()
  , reaction_()
{}

const std::int32_t messagePeerReaction::ID;

object_ptr<messagePeerReaction> messagePeerReaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messagePeerReaction> res = make_tl_object<messagePeerReaction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->big_ = (var0 & 1) != 0;
  res->unread_ = (var0 & 2) != 0;
  res->my_ = (var0 & 4) != 0;
  res->peer_id_ = TlFetchObject<Peer>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->reaction_ = TlFetchObject<Reaction>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messagePeerReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePeerReaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (big_ << 0) | (unread_ << 1) | (my_ << 2)));
    if (var0 & 1) { s.store_field("big", true); }
    if (var0 & 2) { s.store_field("unread", true); }
    if (var0 & 4) { s.store_field("my", true); }
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_field("date", date_);
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

object_ptr<MessagesFilter> MessagesFilter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputMessagesFilterEmpty::ID:
      return inputMessagesFilterEmpty::fetch(p);
    case inputMessagesFilterPhotos::ID:
      return inputMessagesFilterPhotos::fetch(p);
    case inputMessagesFilterVideo::ID:
      return inputMessagesFilterVideo::fetch(p);
    case inputMessagesFilterPhotoVideo::ID:
      return inputMessagesFilterPhotoVideo::fetch(p);
    case inputMessagesFilterDocument::ID:
      return inputMessagesFilterDocument::fetch(p);
    case inputMessagesFilterUrl::ID:
      return inputMessagesFilterUrl::fetch(p);
    case inputMessagesFilterGif::ID:
      return inputMessagesFilterGif::fetch(p);
    case inputMessagesFilterVoice::ID:
      return inputMessagesFilterVoice::fetch(p);
    case inputMessagesFilterMusic::ID:
      return inputMessagesFilterMusic::fetch(p);
    case inputMessagesFilterChatPhotos::ID:
      return inputMessagesFilterChatPhotos::fetch(p);
    case inputMessagesFilterPhoneCalls::ID:
      return inputMessagesFilterPhoneCalls::fetch(p);
    case inputMessagesFilterRoundVoice::ID:
      return inputMessagesFilterRoundVoice::fetch(p);
    case inputMessagesFilterRoundVideo::ID:
      return inputMessagesFilterRoundVideo::fetch(p);
    case inputMessagesFilterMyMentions::ID:
      return inputMessagesFilterMyMentions::fetch(p);
    case inputMessagesFilterGeo::ID:
      return inputMessagesFilterGeo::fetch(p);
    case inputMessagesFilterContacts::ID:
      return inputMessagesFilterContacts::fetch(p);
    case inputMessagesFilterPinned::ID:
      return inputMessagesFilterPinned::fetch(p);
    case inputMessagesFilterPoll::ID:
      return inputMessagesFilterPoll::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputMessagesFilterEmpty::ID;

object_ptr<MessagesFilter> inputMessagesFilterEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterEmpty>();
}

void inputMessagesFilterEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterEmpty");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterPhotos::ID;

object_ptr<MessagesFilter> inputMessagesFilterPhotos::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterPhotos>();
}

void inputMessagesFilterPhotos::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPhotos::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterPhotos");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterVideo::ID;

object_ptr<MessagesFilter> inputMessagesFilterVideo::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterVideo>();
}

void inputMessagesFilterVideo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterVideo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterVideo");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterPhotoVideo::ID;

object_ptr<MessagesFilter> inputMessagesFilterPhotoVideo::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterPhotoVideo>();
}

void inputMessagesFilterPhotoVideo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPhotoVideo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPhotoVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterPhotoVideo");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterDocument::ID;

object_ptr<MessagesFilter> inputMessagesFilterDocument::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterDocument>();
}

void inputMessagesFilterDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterDocument");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterUrl::ID;

object_ptr<MessagesFilter> inputMessagesFilterUrl::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterUrl>();
}

void inputMessagesFilterUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterUrl");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterGif::ID;

object_ptr<MessagesFilter> inputMessagesFilterGif::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterGif>();
}

void inputMessagesFilterGif::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterGif::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterGif::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterGif");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterVoice::ID;

object_ptr<MessagesFilter> inputMessagesFilterVoice::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterVoice>();
}

void inputMessagesFilterVoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterVoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterVoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterVoice");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterMusic::ID;

object_ptr<MessagesFilter> inputMessagesFilterMusic::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterMusic>();
}

void inputMessagesFilterMusic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterMusic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterMusic");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterChatPhotos::ID;

object_ptr<MessagesFilter> inputMessagesFilterChatPhotos::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterChatPhotos>();
}

void inputMessagesFilterChatPhotos::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterChatPhotos::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterChatPhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterChatPhotos");
    s.store_class_end();
  }
}

inputMessagesFilterPhoneCalls::inputMessagesFilterPhoneCalls()
  : flags_()
  , missed_()
{}

inputMessagesFilterPhoneCalls::inputMessagesFilterPhoneCalls(int32 flags_, bool missed_)
  : flags_(flags_)
  , missed_(missed_)
{}

const std::int32_t inputMessagesFilterPhoneCalls::ID;

object_ptr<MessagesFilter> inputMessagesFilterPhoneCalls::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMessagesFilterPhoneCalls> res = make_tl_object<inputMessagesFilterPhoneCalls>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->missed_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMessagesFilterPhoneCalls::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (missed_ << 0)), s);
}

void inputMessagesFilterPhoneCalls::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (missed_ << 0)), s);
}

void inputMessagesFilterPhoneCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterPhoneCalls");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (missed_ << 0)));
    if (var0 & 1) { s.store_field("missed", true); }
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterRoundVoice::ID;

object_ptr<MessagesFilter> inputMessagesFilterRoundVoice::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterRoundVoice>();
}

void inputMessagesFilterRoundVoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterRoundVoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterRoundVoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterRoundVoice");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterRoundVideo::ID;

object_ptr<MessagesFilter> inputMessagesFilterRoundVideo::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterRoundVideo>();
}

void inputMessagesFilterRoundVideo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterRoundVideo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterRoundVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterRoundVideo");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterMyMentions::ID;

object_ptr<MessagesFilter> inputMessagesFilterMyMentions::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterMyMentions>();
}

void inputMessagesFilterMyMentions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterMyMentions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterMyMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterMyMentions");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterGeo::ID;

object_ptr<MessagesFilter> inputMessagesFilterGeo::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterGeo>();
}

void inputMessagesFilterGeo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterGeo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterGeo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterGeo");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterContacts::ID;

object_ptr<MessagesFilter> inputMessagesFilterContacts::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterContacts>();
}

void inputMessagesFilterContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterContacts");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterPinned::ID;

object_ptr<MessagesFilter> inputMessagesFilterPinned::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterPinned>();
}

void inputMessagesFilterPinned::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPinned::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterPinned");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterPoll::ID;

object_ptr<MessagesFilter> inputMessagesFilterPoll::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterPoll>();
}

void inputMessagesFilterPoll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPoll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterPoll");
    s.store_class_end();
  }
}

onrampAvailability::onrampAvailability()
  : flags_()
  , allowed_()
  , buy_allowed_()
  , country_code_()
  , state_()
  , methods_()
{}

const std::int32_t onrampAvailability::ID;

object_ptr<onrampAvailability> onrampAvailability::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<onrampAvailability> res = make_tl_object<onrampAvailability>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->allowed_ = (var0 & 1) != 0;
  res->buy_allowed_ = (var0 & 2) != 0;
  res->country_code_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->state_ = TlFetchString<string>::parse(p); }
  res->methods_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<onrampMethodAvailability>, -1631009112>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void onrampAvailability::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onrampAvailability");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (allowed_ << 0) | (buy_allowed_ << 1) | ((!state_.empty()) << 2)));
    if (var0 & 1) { s.store_field("allowed", true); }
    if (var0 & 2) { s.store_field("buy_allowed", true); }
    s.store_field("country_code", country_code_);
    if (var0 & 4) { s.store_field("state", state_); }
    { s.store_vector_begin("methods", methods_.size()); for (const auto &_value : methods_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t peerBlocked::ID;

object_ptr<peerBlocked> peerBlocked::fetch(TlBufferParser &p) {
  return make_tl_object<peerBlocked>(p);
}

peerBlocked::peerBlocked(TlBufferParser &p)
  : peer_id_(TlFetchObject<Peer>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void peerBlocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerBlocked");
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<PeerColor> PeerColor::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case peerColor::ID:
      return peerColor::fetch(p);
    case peerColorCollectible::ID:
      return peerColorCollectible::fetch(p);
    case inputPeerColorCollectible::ID:
      return inputPeerColorCollectible::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

peerColor::peerColor()
  : flags_()
  , color_()
  , background_emoji_id_()
{}

peerColor::peerColor(int32 flags_, int32 color_, int64 background_emoji_id_)
  : flags_(flags_)
  , color_(color_)
  , background_emoji_id_(background_emoji_id_)
{}

const std::int32_t peerColor::ID;

object_ptr<PeerColor> peerColor::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<peerColor> res = make_tl_object<peerColor>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->color_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->background_emoji_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void peerColor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(color_, s); }
  if (var0 & 2) { TlStoreBinary::store(background_emoji_id_, s); }
}

void peerColor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(color_, s); }
  if (var0 & 2) { TlStoreBinary::store(background_emoji_id_, s); }
}

void peerColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerColor");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("color", color_); }
    if (var0 & 2) { s.store_field("background_emoji_id", background_emoji_id_); }
    s.store_class_end();
  }
}

peerColorCollectible::peerColorCollectible()
  : flags_()
  , collectible_id_()
  , gift_emoji_id_()
  , background_emoji_id_()
  , accent_color_()
  , colors_()
  , dark_accent_color_()
  , dark_colors_()
{}

peerColorCollectible::peerColorCollectible(int32 flags_, int64 collectible_id_, int64 gift_emoji_id_, int64 background_emoji_id_, int32 accent_color_, array<int32> &&colors_, int32 dark_accent_color_, array<int32> &&dark_colors_)
  : flags_(flags_)
  , collectible_id_(collectible_id_)
  , gift_emoji_id_(gift_emoji_id_)
  , background_emoji_id_(background_emoji_id_)
  , accent_color_(accent_color_)
  , colors_(std::move(colors_))
  , dark_accent_color_(dark_accent_color_)
  , dark_colors_(std::move(dark_colors_))
{}

const std::int32_t peerColorCollectible::ID;

object_ptr<PeerColor> peerColorCollectible::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<peerColorCollectible> res = make_tl_object<peerColorCollectible>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collectible_id_ = TlFetchLong::parse(p);
  res->gift_emoji_id_ = TlFetchLong::parse(p);
  res->background_emoji_id_ = TlFetchLong::parse(p);
  res->accent_color_ = TlFetchInt::parse(p);
  res->colors_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  if (var0 & 1) { res->dark_accent_color_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->dark_colors_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void peerColorCollectible::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!dark_colors_.empty()) << 1)), s);
  TlStoreBinary::store(collectible_id_, s);
  TlStoreBinary::store(gift_emoji_id_, s);
  TlStoreBinary::store(background_emoji_id_, s);
  TlStoreBinary::store(accent_color_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(colors_, s);
  if (var0 & 1) { TlStoreBinary::store(dark_accent_color_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(dark_colors_, s); }
}

void peerColorCollectible::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!dark_colors_.empty()) << 1)), s);
  TlStoreBinary::store(collectible_id_, s);
  TlStoreBinary::store(gift_emoji_id_, s);
  TlStoreBinary::store(background_emoji_id_, s);
  TlStoreBinary::store(accent_color_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(colors_, s);
  if (var0 & 1) { TlStoreBinary::store(dark_accent_color_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(dark_colors_, s); }
}

void peerColorCollectible::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerColorCollectible");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!dark_colors_.empty()) << 1)));
    s.store_field("collectible_id", collectible_id_);
    s.store_field("gift_emoji_id", gift_emoji_id_);
    s.store_field("background_emoji_id", background_emoji_id_);
    s.store_field("accent_color", accent_color_);
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("dark_accent_color", dark_accent_color_); }
    if (var0 & 2) { { s.store_vector_begin("dark_colors", dark_colors_.size()); for (const auto &_value : dark_colors_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

inputPeerColorCollectible::inputPeerColorCollectible(int64 collectible_id_)
  : collectible_id_(collectible_id_)
{}

const std::int32_t inputPeerColorCollectible::ID;

object_ptr<PeerColor> inputPeerColorCollectible::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerColorCollectible>(p);
}

inputPeerColorCollectible::inputPeerColorCollectible(TlBufferParser &p)
  : collectible_id_(TlFetchLong::parse(p))
{}

void inputPeerColorCollectible::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(collectible_id_, s);
}

void inputPeerColorCollectible::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(collectible_id_, s);
}

void inputPeerColorCollectible::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerColorCollectible");
    s.store_field("collectible_id", collectible_id_);
    s.store_class_end();
  }
}

object_ptr<PeerLocated> PeerLocated::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case peerLocated::ID:
      return peerLocated::fetch(p);
    case peerSelfLocated::ID:
      return peerSelfLocated::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t peerLocated::ID;

object_ptr<PeerLocated> peerLocated::fetch(TlBufferParser &p) {
  return make_tl_object<peerLocated>(p);
}

peerLocated::peerLocated(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , expires_(TlFetchInt::parse(p))
  , distance_(TlFetchInt::parse(p))
{}

void peerLocated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerLocated");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("expires", expires_);
    s.store_field("distance", distance_);
    s.store_class_end();
  }
}

const std::int32_t peerSelfLocated::ID;

object_ptr<PeerLocated> peerSelfLocated::fetch(TlBufferParser &p) {
  return make_tl_object<peerSelfLocated>(p);
}

peerSelfLocated::peerSelfLocated(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
{}

void peerSelfLocated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerSelfLocated");
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

peerNotifySettings::peerNotifySettings()
  : flags_()
  , show_previews_()
  , silent_()
  , mute_until_()
  , ios_sound_()
  , android_sound_()
  , other_sound_()
  , stories_muted_()
  , stories_hide_sender_()
  , stories_ios_sound_()
  , stories_android_sound_()
  , stories_other_sound_()
{}

const std::int32_t peerNotifySettings::ID;

object_ptr<peerNotifySettings> peerNotifySettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<peerNotifySettings> res = make_tl_object<peerNotifySettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->show_previews_ = TlFetchBool::parse(p); }
  if (var0 & 2) { res->silent_ = TlFetchBool::parse(p); }
  if (var0 & 4) { res->mute_until_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->ios_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (var0 & 16) { res->android_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (var0 & 32) { res->other_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (var0 & 64) { res->stories_muted_ = TlFetchBool::parse(p); }
  if (var0 & 128) { res->stories_hide_sender_ = TlFetchBool::parse(p); }
  if (var0 & 256) { res->stories_ios_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (var0 & 512) { res->stories_android_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (var0 & 1024) { res->stories_other_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void peerNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerNotifySettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((ios_sound_ != nullptr) << 3) | ((android_sound_ != nullptr) << 4) | ((other_sound_ != nullptr) << 5) | ((stories_ios_sound_ != nullptr) << 8) | ((stories_android_sound_ != nullptr) << 9) | ((stories_other_sound_ != nullptr) << 10)));
    if (var0 & 1) { s.store_field("show_previews", show_previews_); }
    if (var0 & 2) { s.store_field("silent", silent_); }
    if (var0 & 4) { s.store_field("mute_until", mute_until_); }
    if (var0 & 8) { s.store_object_field("ios_sound", static_cast<const BaseObject *>(ios_sound_.get())); }
    if (var0 & 16) { s.store_object_field("android_sound", static_cast<const BaseObject *>(android_sound_.get())); }
    if (var0 & 32) { s.store_object_field("other_sound", static_cast<const BaseObject *>(other_sound_.get())); }
    if (var0 & 64) { s.store_field("stories_muted", stories_muted_); }
    if (var0 & 128) { s.store_field("stories_hide_sender", stories_hide_sender_); }
    if (var0 & 256) { s.store_object_field("stories_ios_sound", static_cast<const BaseObject *>(stories_ios_sound_.get())); }
    if (var0 & 512) { s.store_object_field("stories_android_sound", static_cast<const BaseObject *>(stories_android_sound_.get())); }
    if (var0 & 1024) { s.store_object_field("stories_other_sound", static_cast<const BaseObject *>(stories_other_sound_.get())); }
    s.store_class_end();
  }
}

const std::int32_t popularContact::ID;

object_ptr<popularContact> popularContact::fetch(TlBufferParser &p) {
  return make_tl_object<popularContact>(p);
}

popularContact::popularContact(TlBufferParser &p)
  : client_id_(TlFetchLong::parse(p))
  , importers_(TlFetchInt::parse(p))
{}

void popularContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "popularContact");
    s.store_field("client_id", client_id_);
    s.store_field("importers", importers_);
    s.store_class_end();
  }
}

premiumGiftCodeOption::premiumGiftCodeOption()
  : flags_()
  , users_()
  , months_()
  , store_product_()
  , store_quantity_()
  , currency_()
  , amount_()
{}

premiumGiftCodeOption::premiumGiftCodeOption(int32 flags_, int32 users_, int32 months_, string const &store_product_, int32 store_quantity_, string const &currency_, int64 amount_)
  : flags_(flags_)
  , users_(users_)
  , months_(months_)
  , store_product_(store_product_)
  , store_quantity_(store_quantity_)
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t premiumGiftCodeOption::ID;

object_ptr<premiumGiftCodeOption> premiumGiftCodeOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<premiumGiftCodeOption> res = make_tl_object<premiumGiftCodeOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->users_ = TlFetchInt::parse(p);
  res->months_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->store_product_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->store_quantity_ = TlFetchInt::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void premiumGiftCodeOption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!store_product_.empty()) << 0)), s);
  TlStoreBinary::store(users_, s);
  TlStoreBinary::store(months_, s);
  if (var0 & 1) { TlStoreString::store(store_product_, s); }
  if (var0 & 2) { TlStoreBinary::store(store_quantity_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void premiumGiftCodeOption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!store_product_.empty()) << 0)), s);
  TlStoreBinary::store(users_, s);
  TlStoreBinary::store(months_, s);
  if (var0 & 1) { TlStoreString::store(store_product_, s); }
  if (var0 & 2) { TlStoreBinary::store(store_quantity_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void premiumGiftCodeOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiftCodeOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!store_product_.empty()) << 0)));
    s.store_field("users", users_);
    s.store_field("months", months_);
    if (var0 & 1) { s.store_field("store_product", store_product_); }
    if (var0 & 2) { s.store_field("store_quantity", store_quantity_); }
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

object_ptr<ReactionNotificationsFrom> ReactionNotificationsFrom::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case reactionNotificationsFromContacts::ID:
      return reactionNotificationsFromContacts::fetch(p);
    case reactionNotificationsFromAll::ID:
      return reactionNotificationsFromAll::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t reactionNotificationsFromContacts::ID;

object_ptr<ReactionNotificationsFrom> reactionNotificationsFromContacts::fetch(TlBufferParser &p) {
  return make_tl_object<reactionNotificationsFromContacts>();
}

void reactionNotificationsFromContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void reactionNotificationsFromContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void reactionNotificationsFromContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationsFromContacts");
    s.store_class_end();
  }
}

const std::int32_t reactionNotificationsFromAll::ID;

object_ptr<ReactionNotificationsFrom> reactionNotificationsFromAll::fetch(TlBufferParser &p) {
  return make_tl_object<reactionNotificationsFromAll>();
}

void reactionNotificationsFromAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void reactionNotificationsFromAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void reactionNotificationsFromAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationsFromAll");
    s.store_class_end();
  }
}

const std::int32_t receivedNotifyMessage::ID;

object_ptr<receivedNotifyMessage> receivedNotifyMessage::fetch(TlBufferParser &p) {
  return make_tl_object<receivedNotifyMessage>(p);
}

receivedNotifyMessage::receivedNotifyMessage(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , flags_(TlFetchInt::parse(p))
{}

void receivedNotifyMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "receivedNotifyMessage");
    s.store_field("id", id_);
    s.store_field("flags", flags_);
    s.store_class_end();
  }
}

recentStory::recentStory()
  : flags_()
  , live_()
  , max_id_()
{}

recentStory::recentStory(int32 flags_, bool live_, int32 max_id_)
  : flags_(flags_)
  , live_(live_)
  , max_id_(max_id_)
{}

const std::int32_t recentStory::ID;

object_ptr<recentStory> recentStory::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<recentStory> res = make_tl_object<recentStory>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->live_ = (var0 & 1) != 0;
  if (var0 & 2) { res->max_id_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void recentStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (live_ << 0)), s);
  if (var0 & 2) { TlStoreBinary::store(max_id_, s); }
}

void recentStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (live_ << 0)), s);
  if (var0 & 2) { TlStoreBinary::store(max_id_, s); }
}

void recentStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentStory");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (live_ << 0)));
    if (var0 & 1) { s.store_field("live", true); }
    if (var0 & 2) { s.store_field("max_id", max_id_); }
    s.store_class_end();
  }
}

const std::int32_t shareThemeBackdropOption::ID;

object_ptr<shareThemeBackdropOption> shareThemeBackdropOption::fetch(TlBufferParser &p) {
  return make_tl_object<shareThemeBackdropOption>(p);
}

shareThemeBackdropOption::shareThemeBackdropOption(TlBufferParser &p)
  : backdrop_id_(TlFetchInt::parse(p))
  , name_(TlFetchString<string>::parse(p))
  , center_color_(TlFetchInt::parse(p))
  , edge_color_(TlFetchInt::parse(p))
  , pattern_color_(TlFetchInt::parse(p))
  , text_color_(TlFetchInt::parse(p))
{}

void shareThemeBackdropOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shareThemeBackdropOption");
    s.store_field("backdrop_id", backdrop_id_);
    s.store_field("name", name_);
    s.store_field("center_color", center_color_);
    s.store_field("edge_color", edge_color_);
    s.store_field("pattern_color", pattern_color_);
    s.store_field("text_color", text_color_);
    s.store_class_end();
  }
}

object_ptr<StarGiftAttributeRarity> StarGiftAttributeRarity::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starGiftAttributeRarity::ID:
      return starGiftAttributeRarity::fetch(p);
    case starGiftAttributeRarityUncommon::ID:
      return starGiftAttributeRarityUncommon::fetch(p);
    case starGiftAttributeRarityRare::ID:
      return starGiftAttributeRarityRare::fetch(p);
    case starGiftAttributeRarityEpic::ID:
      return starGiftAttributeRarityEpic::fetch(p);
    case starGiftAttributeRarityLegendary::ID:
      return starGiftAttributeRarityLegendary::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

starGiftAttributeRarity::starGiftAttributeRarity(int32 permille_)
  : permille_(permille_)
{}

const std::int32_t starGiftAttributeRarity::ID;

object_ptr<StarGiftAttributeRarity> starGiftAttributeRarity::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeRarity>(p);
}

starGiftAttributeRarity::starGiftAttributeRarity(TlBufferParser &p)
  : permille_(TlFetchInt::parse(p))
{}

void starGiftAttributeRarity::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(permille_, s);
}

void starGiftAttributeRarity::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(permille_, s);
}

void starGiftAttributeRarity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeRarity");
    s.store_field("permille", permille_);
    s.store_class_end();
  }
}

const std::int32_t starGiftAttributeRarityUncommon::ID;

object_ptr<StarGiftAttributeRarity> starGiftAttributeRarityUncommon::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeRarityUncommon>();
}

void starGiftAttributeRarityUncommon::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityUncommon::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityUncommon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeRarityUncommon");
    s.store_class_end();
  }
}

const std::int32_t starGiftAttributeRarityRare::ID;

object_ptr<StarGiftAttributeRarity> starGiftAttributeRarityRare::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeRarityRare>();
}

void starGiftAttributeRarityRare::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityRare::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityRare::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeRarityRare");
    s.store_class_end();
  }
}

const std::int32_t starGiftAttributeRarityEpic::ID;

object_ptr<StarGiftAttributeRarity> starGiftAttributeRarityEpic::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeRarityEpic>();
}

void starGiftAttributeRarityEpic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityEpic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityEpic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeRarityEpic");
    s.store_class_end();
  }
}

const std::int32_t starGiftAttributeRarityLegendary::ID;

object_ptr<StarGiftAttributeRarity> starGiftAttributeRarityLegendary::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeRarityLegendary>();
}

void starGiftAttributeRarityLegendary::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityLegendary::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityLegendary::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeRarityLegendary");
    s.store_class_end();
  }
}

starGiftAuctionAcquiredGift::starGiftAuctionAcquiredGift()
  : flags_()
  , name_hidden_()
  , peer_()
  , date_()
  , bid_amount_()
  , round_()
  , pos_()
  , message_()
  , gift_num_()
{}

const std::int32_t starGiftAuctionAcquiredGift::ID;

object_ptr<starGiftAuctionAcquiredGift> starGiftAuctionAcquiredGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftAuctionAcquiredGift> res = make_tl_object<starGiftAuctionAcquiredGift>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->name_hidden_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->bid_amount_ = TlFetchLong::parse(p);
  res->round_ = TlFetchInt::parse(p);
  res->pos_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (var0 & 4) { res->gift_num_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starGiftAuctionAcquiredGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionAcquiredGift");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (name_hidden_ << 0) | ((message_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("name_hidden", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("date", date_);
    s.store_field("bid_amount", bid_amount_);
    s.store_field("round", round_);
    s.store_field("pos", pos_);
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    if (var0 & 4) { s.store_field("gift_num", gift_num_); }
    s.store_class_end();
  }
}

starGiftBackground::starGiftBackground(int32 center_color_, int32 edge_color_, int32 text_color_)
  : center_color_(center_color_)
  , edge_color_(edge_color_)
  , text_color_(text_color_)
{}

const std::int32_t starGiftBackground::ID;

object_ptr<starGiftBackground> starGiftBackground::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftBackground>(p);
}

starGiftBackground::starGiftBackground(TlBufferParser &p)
  : center_color_(TlFetchInt::parse(p))
  , edge_color_(TlFetchInt::parse(p))
  , text_color_(TlFetchInt::parse(p))
{}

void starGiftBackground::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(text_color_, s);
}

void starGiftBackground::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(text_color_, s);
}

void starGiftBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftBackground");
    s.store_field("center_color", center_color_);
    s.store_field("edge_color", edge_color_);
    s.store_field("text_color", text_color_);
    s.store_class_end();
  }
}

const std::int32_t stickerKeyword::ID;

object_ptr<stickerKeyword> stickerKeyword::fetch(TlBufferParser &p) {
  return make_tl_object<stickerKeyword>(p);
}

stickerKeyword::stickerKeyword(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
  , keyword_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void stickerKeyword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerKeyword");
    s.store_field("document_id", document_id_);
    { s.store_vector_begin("keyword", keyword_.size()); for (const auto &_value : keyword_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stickerSet::stickerSet()
  : flags_()
  , archived_()
  , official_()
  , masks_()
  , emojis_()
  , text_color_()
  , channel_emoji_status_()
  , creator_()
  , installed_date_()
  , id_()
  , access_hash_()
  , title_()
  , short_name_()
  , thumbs_()
  , thumb_dc_id_()
  , thumb_version_()
  , thumb_document_id_()
  , count_()
  , hash_()
{}

const std::int32_t stickerSet::ID;

object_ptr<stickerSet> stickerSet::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stickerSet> res = make_tl_object<stickerSet>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->archived_ = (var0 & 2) != 0;
  res->official_ = (var0 & 4) != 0;
  res->masks_ = (var0 & 8) != 0;
  res->emojis_ = (var0 & 128) != 0;
  res->text_color_ = (var0 & 512) != 0;
  res->channel_emoji_status_ = (var0 & 1024) != 0;
  res->creator_ = (var0 & 2048) != 0;
  if (var0 & 1) { res->installed_date_ = TlFetchInt::parse(p); }
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->short_name_ = TlFetchString<string>::parse(p);
  if (var0 & 16) { res->thumbs_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PhotoSize>>, 481674261>::parse(p); }
  if (var0 & 16) { res->thumb_dc_id_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->thumb_version_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->thumb_document_id_ = TlFetchLong::parse(p); }
  res->count_ = TlFetchInt::parse(p);
  res->hash_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSet");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (archived_ << 1) | (official_ << 2) | (masks_ << 3) | (emojis_ << 7) | (text_color_ << 9) | (channel_emoji_status_ << 10) | (creator_ << 11) | ((!thumbs_.empty()) << 4)));
    if (var0 & 2) { s.store_field("archived", true); }
    if (var0 & 4) { s.store_field("official", true); }
    if (var0 & 8) { s.store_field("masks", true); }
    if (var0 & 128) { s.store_field("emojis", true); }
    if (var0 & 512) { s.store_field("text_color", true); }
    if (var0 & 1024) { s.store_field("channel_emoji_status", true); }
    if (var0 & 2048) { s.store_field("creator", true); }
    if (var0 & 1) { s.store_field("installed_date", installed_date_); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("title", title_);
    s.store_field("short_name", short_name_);
    if (var0 & 16) { { s.store_vector_begin("thumbs", thumbs_.size()); for (const auto &_value : thumbs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("thumb_dc_id", thumb_dc_id_); }
    if (var0 & 16) { s.store_field("thumb_version", thumb_version_); }
    if (var0 & 256) { s.store_field("thumb_document_id", thumb_document_id_); }
    s.store_field("count", count_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

storyFwdHeader::storyFwdHeader()
  : flags_()
  , modified_()
  , from_()
  , from_name_()
  , story_id_()
{}

storyFwdHeader::storyFwdHeader(int32 flags_, bool modified_, object_ptr<Peer> &&from_, string const &from_name_, int32 story_id_)
  : flags_(flags_)
  , modified_(modified_)
  , from_(std::move(from_))
  , from_name_(from_name_)
  , story_id_(story_id_)
{}

const std::int32_t storyFwdHeader::ID;

object_ptr<storyFwdHeader> storyFwdHeader::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyFwdHeader> res = make_tl_object<storyFwdHeader>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->modified_ = (var0 & 8) != 0;
  if (var0 & 1) { res->from_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2) { res->from_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->story_id_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void storyFwdHeader::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (modified_ << 3) | ((from_ != nullptr) << 0) | ((!from_name_.empty()) << 1)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(from_, s); }
  if (var0 & 2) { TlStoreString::store(from_name_, s); }
  if (var0 & 4) { TlStoreBinary::store(story_id_, s); }
}

void storyFwdHeader::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (modified_ << 3) | ((from_ != nullptr) << 0) | ((!from_name_.empty()) << 1)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(from_, s); }
  if (var0 & 2) { TlStoreString::store(from_name_, s); }
  if (var0 & 4) { TlStoreBinary::store(story_id_, s); }
}

void storyFwdHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyFwdHeader");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (modified_ << 3) | ((from_ != nullptr) << 0) | ((!from_name_.empty()) << 1)));
    if (var0 & 8) { s.store_field("modified", true); }
    if (var0 & 1) { s.store_object_field("from", static_cast<const BaseObject *>(from_.get())); }
    if (var0 & 2) { s.store_field("from_name", from_name_); }
    if (var0 & 4) { s.store_field("story_id", story_id_); }
    s.store_class_end();
  }
}

theme::theme()
  : flags_()
  , creator_()
  , default_()
  , for_chat_()
  , id_()
  , access_hash_()
  , slug_()
  , title_()
  , document_()
  , settings_()
  , emoticon_()
  , installs_count_()
{}

const std::int32_t theme::ID;

object_ptr<theme> theme::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<theme> res = make_tl_object<theme>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->default_ = (var0 & 2) != 0;
  res->for_chat_ = (var0 & 32) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->slug_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 8) { res->settings_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<themeSettings>, -94849324>>, 481674261>::parse(p); }
  if (var0 & 64) { res->emoticon_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->installs_count_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void theme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "theme");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | (default_ << 1) | (for_chat_ << 5) | ((document_ != nullptr) << 2) | ((!settings_.empty()) << 3) | ((!emoticon_.empty()) << 6)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 2) { s.store_field("default", true); }
    if (var0 & 32) { s.store_field("for_chat", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("slug", slug_);
    s.store_field("title", title_);
    if (var0 & 4) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 8) { { s.store_vector_begin("settings", settings_.size()); for (const auto &_value : settings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 64) { s.store_field("emoticon", emoticon_); }
    if (var0 & 16) { s.store_field("installs_count", installs_count_); }
    s.store_class_end();
  }
}

object_ptr<UserProfilePhoto> UserProfilePhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case userProfilePhotoEmpty::ID:
      return userProfilePhotoEmpty::fetch(p);
    case userProfilePhoto::ID:
      return userProfilePhoto::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t userProfilePhotoEmpty::ID;

object_ptr<UserProfilePhoto> userProfilePhotoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<userProfilePhotoEmpty>();
}

void userProfilePhotoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userProfilePhotoEmpty");
    s.store_class_end();
  }
}

userProfilePhoto::userProfilePhoto()
  : flags_()
  , has_video_()
  , personal_()
  , photo_id_()
  , stripped_thumb_()
  , dc_id_()
{}

userProfilePhoto::userProfilePhoto(int32 flags_, bool has_video_, bool personal_, int64 photo_id_, bytes &&stripped_thumb_, int32 dc_id_)
  : flags_(flags_)
  , has_video_(has_video_)
  , personal_(personal_)
  , photo_id_(photo_id_)
  , stripped_thumb_(std::move(stripped_thumb_))
  , dc_id_(dc_id_)
{}

const std::int32_t userProfilePhoto::ID;

object_ptr<UserProfilePhoto> userProfilePhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<userProfilePhoto> res = make_tl_object<userProfilePhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_video_ = (var0 & 1) != 0;
  res->personal_ = (var0 & 4) != 0;
  res->photo_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->stripped_thumb_ = TlFetchBytes<bytes>::parse(p); }
  res->dc_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void userProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userProfilePhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_video_ << 0) | (personal_ << 2) | ((!stripped_thumb_.empty()) << 1)));
    if (var0 & 1) { s.store_field("has_video", true); }
    if (var0 & 4) { s.store_field("personal", true); }
    s.store_field("photo_id", photo_id_);
    if (var0 & 2) { s.store_bytes_field("stripped_thumb", stripped_thumb_); }
    s.store_field("dc_id", dc_id_);
    s.store_class_end();
  }
}

object_ptr<WalletTransactionPeer> WalletTransactionPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case walletTransactionPeerUser::ID:
      return walletTransactionPeerUser::fetch(p);
    case walletTransactionPeerAddress::ID:
      return walletTransactionPeerAddress::fetch(p);
    case walletTransactionPeerOnramp::ID:
      return walletTransactionPeerOnramp::fetch(p);
    case walletTransactionPeerUnsupported::ID:
      return walletTransactionPeerUnsupported::fetch(p);
    case walletTransactionPeerChannel::ID:
      return walletTransactionPeerChannel::fetch(p);
    case walletTransactionPeerTelegramGift::ID:
      return walletTransactionPeerTelegramGift::fetch(p);
    case walletTransactionPeerOnchainGift::ID:
      return walletTransactionPeerOnchainGift::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

walletTransactionPeerUser::walletTransactionPeerUser()
  : flags_()
  , user_id_()
  , address_()
  , domain_()
{}

const std::int32_t walletTransactionPeerUser::ID;

object_ptr<WalletTransactionPeer> walletTransactionPeerUser::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletTransactionPeerUser> res = make_tl_object<walletTransactionPeerUser>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  res->address_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->domain_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletTransactionPeerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletTransactionPeerUser");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!domain_.empty()) << 0)));
    s.store_field("user_id", user_id_);
    s.store_field("address", address_);
    if (var0 & 1) { s.store_field("domain", domain_); }
    s.store_class_end();
  }
}

walletTransactionPeerAddress::walletTransactionPeerAddress()
  : flags_()
  , address_()
  , domain_()
{}

const std::int32_t walletTransactionPeerAddress::ID;

object_ptr<WalletTransactionPeer> walletTransactionPeerAddress::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletTransactionPeerAddress> res = make_tl_object<walletTransactionPeerAddress>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->address_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->domain_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletTransactionPeerAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletTransactionPeerAddress");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!domain_.empty()) << 0)));
    s.store_field("address", address_);
    if (var0 & 1) { s.store_field("domain", domain_); }
    s.store_class_end();
  }
}

walletTransactionPeerOnramp::walletTransactionPeerOnramp()
  : flags_()
  , address_()
  , domain_()
  , provider_name_()
{}

const std::int32_t walletTransactionPeerOnramp::ID;

object_ptr<WalletTransactionPeer> walletTransactionPeerOnramp::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletTransactionPeerOnramp> res = make_tl_object<walletTransactionPeerOnramp>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->address_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->domain_ = TlFetchString<string>::parse(p); }
  res->provider_name_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletTransactionPeerOnramp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletTransactionPeerOnramp");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!domain_.empty()) << 0)));
    s.store_field("address", address_);
    if (var0 & 1) { s.store_field("domain", domain_); }
    s.store_field("provider_name", provider_name_);
    s.store_class_end();
  }
}

const std::int32_t walletTransactionPeerUnsupported::ID;

object_ptr<WalletTransactionPeer> walletTransactionPeerUnsupported::fetch(TlBufferParser &p) {
  return make_tl_object<walletTransactionPeerUnsupported>();
}

void walletTransactionPeerUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletTransactionPeerUnsupported");
    s.store_class_end();
  }
}

walletTransactionPeerChannel::walletTransactionPeerChannel()
  : flags_()
  , channel_id_()
  , address_()
  , domain_()
{}

const std::int32_t walletTransactionPeerChannel::ID;

object_ptr<WalletTransactionPeer> walletTransactionPeerChannel::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletTransactionPeerChannel> res = make_tl_object<walletTransactionPeerChannel>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_id_ = TlFetchLong::parse(p);
  res->address_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->domain_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletTransactionPeerChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletTransactionPeerChannel");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!domain_.empty()) << 0)));
    s.store_field("channel_id", channel_id_);
    s.store_field("address", address_);
    if (var0 & 1) { s.store_field("domain", domain_); }
    s.store_class_end();
  }
}

walletTransactionPeerTelegramGift::walletTransactionPeerTelegramGift()
  : flags_()
  , own_profile_()
{}

const std::int32_t walletTransactionPeerTelegramGift::ID;

object_ptr<WalletTransactionPeer> walletTransactionPeerTelegramGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletTransactionPeerTelegramGift> res = make_tl_object<walletTransactionPeerTelegramGift>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->own_profile_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void walletTransactionPeerTelegramGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletTransactionPeerTelegramGift");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (own_profile_ << 0)));
    if (var0 & 1) { s.store_field("own_profile", true); }
    s.store_class_end();
  }
}

const std::int32_t walletTransactionPeerOnchainGift::ID;

object_ptr<WalletTransactionPeer> walletTransactionPeerOnchainGift::fetch(TlBufferParser &p) {
  return make_tl_object<walletTransactionPeerOnchainGift>(p);
}

walletTransactionPeerOnchainGift::walletTransactionPeerOnchainGift(TlBufferParser &p)
  : action_(TlFetchObject<WalletOnchainGiftAction>::parse(p))
{}

void walletTransactionPeerOnchainGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletTransactionPeerOnchainGift");
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

object_ptr<WidgetQueryType> WidgetQueryType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case widgetQueryTypeData::ID:
      return widgetQueryTypeData::fetch(p);
    case widgetQueryTypeSignData::ID:
      return widgetQueryTypeSignData::fetch(p);
    case widgetQueryTypeSentTransaction::ID:
      return widgetQueryTypeSentTransaction::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

widgetQueryTypeData::widgetQueryTypeData()
  : flags_()
  , with_wallet_()
{}

widgetQueryTypeData::widgetQueryTypeData(int32 flags_, bool with_wallet_)
  : flags_(flags_)
  , with_wallet_(with_wallet_)
{}

const std::int32_t widgetQueryTypeData::ID;

object_ptr<WidgetQueryType> widgetQueryTypeData::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<widgetQueryTypeData> res = make_tl_object<widgetQueryTypeData>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->with_wallet_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void widgetQueryTypeData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (with_wallet_ << 0)), s);
}

void widgetQueryTypeData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (with_wallet_ << 0)), s);
}

void widgetQueryTypeData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "widgetQueryTypeData");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (with_wallet_ << 0)));
    if (var0 & 1) { s.store_field("with_wallet", true); }
    s.store_class_end();
  }
}

widgetQueryTypeSignData::widgetQueryTypeSignData(object_ptr<userWallet> &&wallet_, object_ptr<dataJSON> &&sign_data_)
  : wallet_(std::move(wallet_))
  , sign_data_(std::move(sign_data_))
{}

const std::int32_t widgetQueryTypeSignData::ID;

object_ptr<WidgetQueryType> widgetQueryTypeSignData::fetch(TlBufferParser &p) {
  return make_tl_object<widgetQueryTypeSignData>(p);
}

widgetQueryTypeSignData::widgetQueryTypeSignData(TlBufferParser &p)
  : wallet_(TlFetchBoxed<TlFetchObject<userWallet>, 1162684215>::parse(p))
  , sign_data_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void widgetQueryTypeSignData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 1162684215>::store(wallet_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(sign_data_, s);
}

void widgetQueryTypeSignData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 1162684215>::store(wallet_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(sign_data_, s);
}

void widgetQueryTypeSignData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "widgetQueryTypeSignData");
    s.store_object_field("wallet", static_cast<const BaseObject *>(wallet_.get()));
    s.store_object_field("sign_data", static_cast<const BaseObject *>(sign_data_.get()));
    s.store_class_end();
  }
}

widgetQueryTypeSentTransaction::widgetQueryTypeSentTransaction(object_ptr<userWallet> &&wallet_, string const &msg_hash_)
  : wallet_(std::move(wallet_))
  , msg_hash_(msg_hash_)
{}

const std::int32_t widgetQueryTypeSentTransaction::ID;

object_ptr<WidgetQueryType> widgetQueryTypeSentTransaction::fetch(TlBufferParser &p) {
  return make_tl_object<widgetQueryTypeSentTransaction>(p);
}

widgetQueryTypeSentTransaction::widgetQueryTypeSentTransaction(TlBufferParser &p)
  : wallet_(TlFetchBoxed<TlFetchObject<userWallet>, 1162684215>::parse(p))
  , msg_hash_(TlFetchString<string>::parse(p))
{}

void widgetQueryTypeSentTransaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 1162684215>::store(wallet_, s);
  TlStoreString::store(msg_hash_, s);
}

void widgetQueryTypeSentTransaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 1162684215>::store(wallet_, s);
  TlStoreString::store(msg_hash_, s);
}

void widgetQueryTypeSentTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "widgetQueryTypeSentTransaction");
    s.store_object_field("wallet", static_cast<const BaseObject *>(wallet_.get()));
    s.store_field("msg_hash", msg_hash_);
    s.store_class_end();
  }
}

const std::int32_t account_connectedBots::ID;

object_ptr<account_connectedBots> account_connectedBots::fetch(TlBufferParser &p) {
  return make_tl_object<account_connectedBots>(p);
}

account_connectedBots::account_connectedBots(TlBufferParser &p)
  : connected_bots_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<connectedBot>, 54448129>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void account_connectedBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.connectedBots");
    { s.store_vector_begin("connected_bots", connected_bots_.size()); for (const auto &_value : connected_bots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_contentSettings::account_contentSettings()
  : flags_()
  , sensitive_enabled_()
  , sensitive_can_change_()
{}

const std::int32_t account_contentSettings::ID;

object_ptr<account_contentSettings> account_contentSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_contentSettings> res = make_tl_object<account_contentSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->sensitive_enabled_ = (var0 & 1) != 0;
  res->sensitive_can_change_ = (var0 & 2) != 0;
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void account_contentSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.contentSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (sensitive_enabled_ << 0) | (sensitive_can_change_ << 1)));
    if (var0 & 1) { s.store_field("sensitive_enabled", true); }
    if (var0 & 2) { s.store_field("sensitive_can_change", true); }
    s.store_class_end();
  }
}

object_ptr<account_ResetPasswordResult> account_ResetPasswordResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_resetPasswordFailedWait::ID:
      return account_resetPasswordFailedWait::fetch(p);
    case account_resetPasswordRequestedWait::ID:
      return account_resetPasswordRequestedWait::fetch(p);
    case account_resetPasswordOk::ID:
      return account_resetPasswordOk::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_resetPasswordFailedWait::ID;

object_ptr<account_ResetPasswordResult> account_resetPasswordFailedWait::fetch(TlBufferParser &p) {
  return make_tl_object<account_resetPasswordFailedWait>(p);
}

account_resetPasswordFailedWait::account_resetPasswordFailedWait(TlBufferParser &p)
  : retry_date_(TlFetchInt::parse(p))
{}

void account_resetPasswordFailedWait::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetPasswordFailedWait");
    s.store_field("retry_date", retry_date_);
    s.store_class_end();
  }
}

const std::int32_t account_resetPasswordRequestedWait::ID;

object_ptr<account_ResetPasswordResult> account_resetPasswordRequestedWait::fetch(TlBufferParser &p) {
  return make_tl_object<account_resetPasswordRequestedWait>(p);
}

account_resetPasswordRequestedWait::account_resetPasswordRequestedWait(TlBufferParser &p)
  : until_date_(TlFetchInt::parse(p))
{}

void account_resetPasswordRequestedWait::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetPasswordRequestedWait");
    s.store_field("until_date", until_date_);
    s.store_class_end();
  }
}

const std::int32_t account_resetPasswordOk::ID;

object_ptr<account_ResetPasswordResult> account_resetPasswordOk::fetch(TlBufferParser &p) {
  return make_tl_object<account_resetPasswordOk>();
}

void account_resetPasswordOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetPasswordOk");
    s.store_class_end();
  }
}

object_ptr<account_WebBrowserSettings> account_WebBrowserSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_webBrowserSettingsNotModified::ID:
      return account_webBrowserSettingsNotModified::fetch(p);
    case account_webBrowserSettings::ID:
      return account_webBrowserSettings::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_webBrowserSettingsNotModified::ID;

object_ptr<account_WebBrowserSettings> account_webBrowserSettingsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_webBrowserSettingsNotModified>();
}

void account_webBrowserSettingsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.webBrowserSettingsNotModified");
    s.store_class_end();
  }
}

account_webBrowserSettings::account_webBrowserSettings()
  : flags_()
  , open_external_browser_()
  , display_close_button_()
  , external_exceptions_()
  , inapp_exceptions_()
  , hash_()
{}

const std::int32_t account_webBrowserSettings::ID;

object_ptr<account_WebBrowserSettings> account_webBrowserSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_webBrowserSettings> res = make_tl_object<account_webBrowserSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->open_external_browser_ = (var0 & 1) != 0;
  res->display_close_button_ = (var0 & 2) != 0;
  res->external_exceptions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<webDomainException>, -1824741993>>, 481674261>::parse(p);
  res->inapp_exceptions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<webDomainException>, -1824741993>>, 481674261>::parse(p);
  res->hash_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void account_webBrowserSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.webBrowserSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (open_external_browser_ << 0) | (display_close_button_ << 1)));
    if (var0 & 1) { s.store_field("open_external_browser", true); }
    if (var0 & 2) { s.store_field("display_close_button", true); }
    { s.store_vector_begin("external_exceptions", external_exceptions_.size()); for (const auto &_value : external_exceptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("inapp_exceptions", inapp_exceptions_.size()); for (const auto &_value : inapp_exceptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

const std::int32_t bots_previewInfo::ID;

object_ptr<bots_previewInfo> bots_previewInfo::fetch(TlBufferParser &p) {
  return make_tl_object<bots_previewInfo>(p);
}

bots_previewInfo::bots_previewInfo(TlBufferParser &p)
  : media_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botPreviewMedia>, 602479523>>, 481674261>::parse(p))
  , lang_codes_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void bots_previewInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.previewInfo");
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("lang_codes", lang_codes_.size()); for (const auto &_value : lang_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t channels_adminLogResults::ID;

object_ptr<channels_adminLogResults> channels_adminLogResults::fetch(TlBufferParser &p) {
  return make_tl_object<channels_adminLogResults>(p);
}

channels_adminLogResults::channels_adminLogResults(TlBufferParser &p)
  : events_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<channelAdminLogEvent>, 531458253>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void channels_adminLogResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.adminLogResults");
    { s.store_vector_begin("events", events_.size()); for (const auto &_value : events_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<channels_SponsoredMessageReportResult> channels_SponsoredMessageReportResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case channels_sponsoredMessageReportResultChooseOption::ID:
      return channels_sponsoredMessageReportResultChooseOption::fetch(p);
    case channels_sponsoredMessageReportResultAdsHidden::ID:
      return channels_sponsoredMessageReportResultAdsHidden::fetch(p);
    case channels_sponsoredMessageReportResultReported::ID:
      return channels_sponsoredMessageReportResultReported::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t channels_sponsoredMessageReportResultChooseOption::ID;

object_ptr<channels_SponsoredMessageReportResult> channels_sponsoredMessageReportResultChooseOption::fetch(TlBufferParser &p) {
  return make_tl_object<channels_sponsoredMessageReportResultChooseOption>(p);
}

channels_sponsoredMessageReportResultChooseOption::channels_sponsoredMessageReportResultChooseOption(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , options_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<sponsoredMessageReportOption>, 1124938064>>, 481674261>::parse(p))
{}

void channels_sponsoredMessageReportResultChooseOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.sponsoredMessageReportResultChooseOption");
    s.store_field("title", title_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t channels_sponsoredMessageReportResultAdsHidden::ID;

object_ptr<channels_SponsoredMessageReportResult> channels_sponsoredMessageReportResultAdsHidden::fetch(TlBufferParser &p) {
  return make_tl_object<channels_sponsoredMessageReportResultAdsHidden>();
}

void channels_sponsoredMessageReportResultAdsHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.sponsoredMessageReportResultAdsHidden");
    s.store_class_end();
  }
}

const std::int32_t channels_sponsoredMessageReportResultReported::ID;

object_ptr<channels_SponsoredMessageReportResult> channels_sponsoredMessageReportResultReported::fetch(TlBufferParser &p) {
  return make_tl_object<channels_sponsoredMessageReportResultReported>();
}

void channels_sponsoredMessageReportResultReported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.sponsoredMessageReportResultReported");
    s.store_class_end();
  }
}

communities_peerLinkRequests::communities_peerLinkRequests()
  : flags_()
  , total_count_()
  , requests_()
  , next_offset_()
  , chats_()
  , users_()
{}

const std::int32_t communities_peerLinkRequests::ID;

object_ptr<communities_peerLinkRequests> communities_peerLinkRequests::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<communities_peerLinkRequests> res = make_tl_object<communities_peerLinkRequests>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->total_count_ = TlFetchInt::parse(p);
  res->requests_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<communityPeerRequest>, 2078997125>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void communities_peerLinkRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities.peerLinkRequests");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("requests", requests_.size()); for (const auto &_value : requests_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t help_supportName::ID;

object_ptr<help_supportName> help_supportName::fetch(TlBufferParser &p) {
  return make_tl_object<help_supportName>(p);
}

help_supportName::help_supportName(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
{}

void help_supportName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.supportName");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

object_ptr<help_UserInfo> help_UserInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_userInfoEmpty::ID:
      return help_userInfoEmpty::fetch(p);
    case help_userInfo::ID:
      return help_userInfo::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_userInfoEmpty::ID;

object_ptr<help_UserInfo> help_userInfoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<help_userInfoEmpty>();
}

void help_userInfoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.userInfoEmpty");
    s.store_class_end();
  }
}

const std::int32_t help_userInfo::ID;

object_ptr<help_UserInfo> help_userInfo::fetch(TlBufferParser &p) {
  return make_tl_object<help_userInfo>(p);
}

help_userInfo::help_userInfo(TlBufferParser &p)
  : message_(TlFetchString<string>::parse(p))
  , entities_(TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p))
  , author_(TlFetchString<string>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void help_userInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.userInfo");
    s.store_field("message", message_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("author", author_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

messages_botApp::messages_botApp()
  : flags_()
  , inactive_()
  , request_write_access_()
  , has_settings_()
  , app_()
{}

const std::int32_t messages_botApp::ID;

object_ptr<messages_botApp> messages_botApp::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_botApp> res = make_tl_object<messages_botApp>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inactive_ = (var0 & 1) != 0;
  res->request_write_access_ = (var0 & 2) != 0;
  res->has_settings_ = (var0 & 4) != 0;
  res->app_ = TlFetchObject<BotApp>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_botApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.botApp");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inactive_ << 0) | (request_write_access_ << 1) | (has_settings_ << 2)));
    if (var0 & 1) { s.store_field("inactive", true); }
    if (var0 & 2) { s.store_field("request_write_access", true); }
    if (var0 & 4) { s.store_field("has_settings", true); }
    s.store_object_field("app", static_cast<const BaseObject *>(app_.get()));
    s.store_class_end();
  }
}

object_ptr<messages_DhConfig> messages_DhConfig::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_dhConfigNotModified::ID:
      return messages_dhConfigNotModified::fetch(p);
    case messages_dhConfig::ID:
      return messages_dhConfig::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_dhConfigNotModified::ID;

object_ptr<messages_DhConfig> messages_dhConfigNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_dhConfigNotModified>(p);
}

messages_dhConfigNotModified::messages_dhConfigNotModified(TlBufferParser &p)
  : random_(TlFetchBytes<bytes>::parse(p))
{}

void messages_dhConfigNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dhConfigNotModified");
    s.store_bytes_field("random", random_);
    s.store_class_end();
  }
}

const std::int32_t messages_dhConfig::ID;

object_ptr<messages_DhConfig> messages_dhConfig::fetch(TlBufferParser &p) {
  return make_tl_object<messages_dhConfig>(p);
}

messages_dhConfig::messages_dhConfig(TlBufferParser &p)
  : g_(TlFetchInt::parse(p))
  , p_(TlFetchBytes<bytes>::parse(p))
  , version_(TlFetchInt::parse(p))
  , random_(TlFetchBytes<bytes>::parse(p))
{}

void messages_dhConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dhConfig");
    s.store_field("g", g_);
    s.store_bytes_field("p", p_);
    s.store_field("version", version_);
    s.store_bytes_field("random", random_);
    s.store_class_end();
  }
}

const std::int32_t messages_highScores::ID;

object_ptr<messages_highScores> messages_highScores::fetch(TlBufferParser &p) {
  return make_tl_object<messages_highScores>(p);
}

messages_highScores::messages_highScores(TlBufferParser &p)
  : scores_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<highScore>, 1940093419>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_highScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.highScores");
    { s.store_vector_begin("scores", scores_.size()); for (const auto &_value : scores_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_peerDialogs::messages_peerDialogs()
  : flags_()
  , topics_()
  , dialogs_()
  , messages_()
  , chats_()
  , users_()
  , state_()
{}

const std::int32_t messages_peerDialogs::ID;

object_ptr<messages_peerDialogs> messages_peerDialogs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_peerDialogs> res = make_tl_object<messages_peerDialogs>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p); }
  res->dialogs_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Dialog>>, 481674261>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  res->state_ = TlFetchBoxed<TlFetchObject<updates_state>, -1519637954>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_peerDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.peerDialogs");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!topics_.empty()) << 0)));
    if (var0 & 1) { { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("dialogs", dialogs_.size()); for (const auto &_value : dialogs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

object_ptr<messages_SavedReactionTags> messages_SavedReactionTags::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_savedReactionTagsNotModified::ID:
      return messages_savedReactionTagsNotModified::fetch(p);
    case messages_savedReactionTags::ID:
      return messages_savedReactionTags::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_savedReactionTagsNotModified::ID;

object_ptr<messages_SavedReactionTags> messages_savedReactionTagsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedReactionTagsNotModified>();
}

void messages_savedReactionTagsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedReactionTagsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_savedReactionTags::ID;

object_ptr<messages_SavedReactionTags> messages_savedReactionTags::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedReactionTags>(p);
}

messages_savedReactionTags::messages_savedReactionTags(TlBufferParser &p)
  : tags_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<savedReactionTag>, -881854424>>, 481674261>::parse(p))
  , hash_(TlFetchLong::parse(p))
{}

void messages_savedReactionTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedReactionTags");
    { s.store_vector_begin("tags", tags_.size()); for (const auto &_value : tags_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

object_ptr<messages_SponsoredMessages> messages_SponsoredMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_sponsoredMessages::ID:
      return messages_sponsoredMessages::fetch(p);
    case messages_sponsoredMessagesEmpty::ID:
      return messages_sponsoredMessagesEmpty::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messages_sponsoredMessages::messages_sponsoredMessages()
  : flags_()
  , posts_between_()
  , start_delay_()
  , between_delay_()
  , messages_()
  , chats_()
  , users_()
{}

const std::int32_t messages_sponsoredMessages::ID;

object_ptr<messages_SponsoredMessages> messages_sponsoredMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_sponsoredMessages> res = make_tl_object<messages_sponsoredMessages>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->posts_between_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->start_delay_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->between_delay_ = TlFetchInt::parse(p); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<sponsoredMessage>, 2109703795>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_sponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sponsoredMessages");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("posts_between", posts_between_); }
    if (var0 & 2) { s.store_field("start_delay", start_delay_); }
    if (var0 & 4) { s.store_field("between_delay", between_delay_); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_sponsoredMessagesEmpty::ID;

object_ptr<messages_SponsoredMessages> messages_sponsoredMessagesEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<messages_sponsoredMessagesEmpty>();
}

void messages_sponsoredMessagesEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sponsoredMessagesEmpty");
    s.store_class_end();
  }
}

const std::int32_t messages_translateResult::ID;

object_ptr<messages_translateResult> messages_translateResult::fetch(TlBufferParser &p) {
  return make_tl_object<messages_translateResult>(p);
}

messages_translateResult::messages_translateResult(TlBufferParser &p)
  : result_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>>, 481674261>::parse(p))
{}

void messages_translateResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.translateResult");
    { s.store_vector_begin("result", result_.size()); for (const auto &_value : result_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_savedInfo::payments_savedInfo()
  : flags_()
  , has_saved_credentials_()
  , saved_info_()
{}

const std::int32_t payments_savedInfo::ID;

object_ptr<payments_savedInfo> payments_savedInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_savedInfo> res = make_tl_object<payments_savedInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_saved_credentials_ = (var0 & 2) != 0;
  if (var0 & 1) { res->saved_info_ = TlFetchBoxed<TlFetchObject<paymentRequestedInfo>, -1868808300>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_savedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.savedInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_saved_credentials_ << 1) | ((saved_info_ != nullptr) << 0)));
    if (var0 & 2) { s.store_field("has_saved_credentials", true); }
    if (var0 & 1) { s.store_object_field("saved_info", static_cast<const BaseObject *>(saved_info_.get())); }
    s.store_class_end();
  }
}

object_ptr<updates_Difference> updates_Difference::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case updates_differenceEmpty::ID:
      return updates_differenceEmpty::fetch(p);
    case updates_difference::ID:
      return updates_difference::fetch(p);
    case updates_differenceSlice::ID:
      return updates_differenceSlice::fetch(p);
    case updates_differenceTooLong::ID:
      return updates_differenceTooLong::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t updates_differenceEmpty::ID;

object_ptr<updates_Difference> updates_differenceEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<updates_differenceEmpty>(p);
}

updates_differenceEmpty::updates_differenceEmpty(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , seq_(TlFetchInt::parse(p))
{}

void updates_differenceEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.differenceEmpty");
    s.store_field("date", date_);
    s.store_field("seq", seq_);
    s.store_class_end();
  }
}

updates_difference::updates_difference()
  : flags_()
  , topics_()
  , new_messages_()
  , new_encrypted_messages_()
  , other_updates_()
  , chats_()
  , users_()
  , state_()
{}

const std::int32_t updates_difference::ID;

object_ptr<updates_Difference> updates_difference::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updates_difference> res = make_tl_object<updates_difference>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p); }
  res->new_messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->new_encrypted_messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<EncryptedMessage>>, 481674261>::parse(p);
  res->other_updates_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Update>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  res->state_ = TlFetchBoxed<TlFetchObject<updates_state>, -1519637954>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updates_difference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.difference");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!topics_.empty()) << 0)));
    if (var0 & 1) { { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("new_messages", new_messages_.size()); for (const auto &_value : new_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("new_encrypted_messages", new_encrypted_messages_.size()); for (const auto &_value : new_encrypted_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("other_updates", other_updates_.size()); for (const auto &_value : other_updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

updates_differenceSlice::updates_differenceSlice()
  : flags_()
  , topics_()
  , new_messages_()
  , new_encrypted_messages_()
  , other_updates_()
  , chats_()
  , users_()
  , intermediate_state_()
{}

updates_differenceSlice::updates_differenceSlice(int32 flags_, array<object_ptr<ForumTopic>> &&topics_, array<object_ptr<Message>> &&new_messages_, array<object_ptr<EncryptedMessage>> &&new_encrypted_messages_, array<object_ptr<Update>> &&other_updates_, array<object_ptr<Chat>> &&chats_, array<object_ptr<User>> &&users_, object_ptr<updates_state> &&intermediate_state_)
  : flags_(flags_)
  , topics_(std::move(topics_))
  , new_messages_(std::move(new_messages_))
  , new_encrypted_messages_(std::move(new_encrypted_messages_))
  , other_updates_(std::move(other_updates_))
  , chats_(std::move(chats_))
  , users_(std::move(users_))
  , intermediate_state_(std::move(intermediate_state_))
{}

const std::int32_t updates_differenceSlice::ID;

object_ptr<updates_Difference> updates_differenceSlice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updates_differenceSlice> res = make_tl_object<updates_differenceSlice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p); }
  res->new_messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->new_encrypted_messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<EncryptedMessage>>, 481674261>::parse(p);
  res->other_updates_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Update>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  res->intermediate_state_ = TlFetchBoxed<TlFetchObject<updates_state>, -1519637954>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updates_differenceSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.differenceSlice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!topics_.empty()) << 0)));
    if (var0 & 1) { { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("new_messages", new_messages_.size()); for (const auto &_value : new_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("new_encrypted_messages", new_encrypted_messages_.size()); for (const auto &_value : new_encrypted_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("other_updates", other_updates_.size()); for (const auto &_value : other_updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("intermediate_state", static_cast<const BaseObject *>(intermediate_state_.get()));
    s.store_class_end();
  }
}

const std::int32_t updates_differenceTooLong::ID;

object_ptr<updates_Difference> updates_differenceTooLong::fetch(TlBufferParser &p) {
  return make_tl_object<updates_differenceTooLong>(p);
}

updates_differenceTooLong::updates_differenceTooLong(TlBufferParser &p)
  : pts_(TlFetchInt::parse(p))
{}

void updates_differenceTooLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.differenceTooLong");
    s.store_field("pts", pts_);
    s.store_class_end();
  }
}

object_ptr<users_Users> users_Users::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case users_users::ID:
      return users_users::fetch(p);
    case users_usersSlice::ID:
      return users_usersSlice::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t users_users::ID;

object_ptr<users_Users> users_users::fetch(TlBufferParser &p) {
  return make_tl_object<users_users>(p);
}

users_users::users_users(TlBufferParser &p)
  : users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void users_users::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.users");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t users_usersSlice::ID;

object_ptr<users_Users> users_usersSlice::fetch(TlBufferParser &p) {
  return make_tl_object<users_usersSlice>(p);
}

users_usersSlice::users_usersSlice(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void users_usersSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.usersSlice");
    s.store_field("count", count_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t wallet_nftAttribute::ID;

object_ptr<wallet_nftAttribute> wallet_nftAttribute::fetch(TlBufferParser &p) {
  return make_tl_object<wallet_nftAttribute>(p);
}

wallet_nftAttribute::wallet_nftAttribute(TlBufferParser &p)
  : trait_type_(TlFetchString<string>::parse(p))
  , value_(TlFetchString<string>::parse(p))
{}

void wallet_nftAttribute::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.nftAttribute");
    s.store_field("trait_type", trait_type_);
    s.store_field("value", value_);
    s.store_class_end();
  }
}

account_changePhone::account_changePhone(string const &phone_number_, string const &phone_code_hash_, string const &phone_code_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , phone_code_(phone_code_)
{}

const std::int32_t account_changePhone::ID;

void account_changePhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1891839707);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_changePhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1891839707);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_changePhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.changePhone");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("phone_code", "[REDACTED]");
    s.store_class_end();
  }
}

account_changePhone::ReturnType account_changePhone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

account_editBusinessChatLink::account_editBusinessChatLink(string const &slug_, object_ptr<inputBusinessChatLink> &&link_)
  : slug_(slug_)
  , link_(std::move(link_))
{}

const std::int32_t account_editBusinessChatLink::ID;

void account_editBusinessChatLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1942744913);
  TlStoreString::store(slug_, s);
  TlStoreBoxed<TlStoreObject, 292003751>::store(link_, s);
}

void account_editBusinessChatLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1942744913);
  TlStoreString::store(slug_, s);
  TlStoreBoxed<TlStoreObject, 292003751>::store(link_, s);
}

void account_editBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.editBusinessChatLink");
    s.store_field("slug", slug_);
    s.store_object_field("link", static_cast<const BaseObject *>(link_.get()));
    s.store_class_end();
  }
}

account_editBusinessChatLink::ReturnType account_editBusinessChatLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<businessChatLink>, -1263638929>::parse(p);
#undef FAIL
}

const std::int32_t account_getAllSecureValues::ID;

void account_getAllSecureValues::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1299661699);
}

void account_getAllSecureValues::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1299661699);
}

void account_getAllSecureValues::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAllSecureValues");
    s.store_class_end();
  }
}

account_getAllSecureValues::ReturnType account_getAllSecureValues::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<secureValue>, 411017418>>, 481674261>::parse(p);
#undef FAIL
}

account_getAuthorizationForm::account_getAuthorizationForm(int64 bot_id_, string const &scope_, string const &public_key_)
  : bot_id_(bot_id_)
  , scope_(scope_)
  , public_key_(public_key_)
{}

const std::int32_t account_getAuthorizationForm::ID;

void account_getAuthorizationForm::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1456907910);
  TlStoreBinary::store(bot_id_, s);
  TlStoreString::store(scope_, s);
  TlStoreString::store(public_key_, s);
}

void account_getAuthorizationForm::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1456907910);
  TlStoreBinary::store(bot_id_, s);
  TlStoreString::store(scope_, s);
  TlStoreString::store(public_key_, s);
}

void account_getAuthorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAuthorizationForm");
    s.store_field("bot_id", bot_id_);
    s.store_field("scope", scope_);
    s.store_field("public_key", public_key_);
    s.store_class_end();
  }
}

account_getAuthorizationForm::ReturnType account_getAuthorizationForm::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_authorizationForm>, -1389486888>::parse(p);
#undef FAIL
}

account_getChannelRestrictedStatusEmojis::account_getChannelRestrictedStatusEmojis(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getChannelRestrictedStatusEmojis::ID;

void account_getChannelRestrictedStatusEmojis::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(900325589);
  TlStoreBinary::store(hash_, s);
}

void account_getChannelRestrictedStatusEmojis::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(900325589);
  TlStoreBinary::store(hash_, s);
}

void account_getChannelRestrictedStatusEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getChannelRestrictedStatusEmojis");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getChannelRestrictedStatusEmojis::ReturnType account_getChannelRestrictedStatusEmojis::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EmojiList>::parse(p);
#undef FAIL
}

account_getNotifySettings::account_getNotifySettings(object_ptr<InputNotifyPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t account_getNotifySettings::ID;

void account_getNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(313765169);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void account_getNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(313765169);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void account_getNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getNotifySettings");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

account_getNotifySettings::ReturnType account_getNotifySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
#undef FAIL
}

account_getPasswordSettings::account_getPasswordSettings(object_ptr<InputCheckPasswordSRP> &&password_)
  : password_(std::move(password_))
{}

const std::int32_t account_getPasswordSettings::ID;

void account_getPasswordSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1663767815);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void account_getPasswordSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1663767815);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void account_getPasswordSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getPasswordSettings");
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

account_getPasswordSettings::ReturnType account_getPasswordSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_passwordSettings>, -1705233435>::parse(p);
#undef FAIL
}

const std::int32_t account_getWebAuthorizations::ID;

void account_getWebAuthorizations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(405695855);
}

void account_getWebAuthorizations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(405695855);
}

void account_getWebAuthorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getWebAuthorizations");
    s.store_class_end();
  }
}

account_getWebAuthorizations::ReturnType account_getWebAuthorizations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_webAuthorizations>, -313079300>::parse(p);
#undef FAIL
}

account_initTakeoutSession::account_initTakeoutSession(int32 flags_, bool contacts_, bool message_users_, bool message_chats_, bool message_megagroups_, bool message_channels_, bool files_, int64 file_max_size_)
  : flags_(flags_)
  , contacts_(contacts_)
  , message_users_(message_users_)
  , message_chats_(message_chats_)
  , message_megagroups_(message_megagroups_)
  , message_channels_(message_channels_)
  , files_(files_)
  , file_max_size_(file_max_size_)
{}

const std::int32_t account_initTakeoutSession::ID;

void account_initTakeoutSession::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1896617296);
  TlStoreBinary::store((var0 = flags_ | (contacts_ << 0) | (message_users_ << 1) | (message_chats_ << 2) | (message_megagroups_ << 3) | (message_channels_ << 4) | (files_ << 5)), s);
  if (var0 & 32) { TlStoreBinary::store(file_max_size_, s); }
}

void account_initTakeoutSession::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1896617296);
  TlStoreBinary::store((var0 = flags_ | (contacts_ << 0) | (message_users_ << 1) | (message_chats_ << 2) | (message_megagroups_ << 3) | (message_channels_ << 4) | (files_ << 5)), s);
  if (var0 & 32) { TlStoreBinary::store(file_max_size_, s); }
}

void account_initTakeoutSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.initTakeoutSession");
    s.store_field("flags", (var0 = flags_ | (contacts_ << 0) | (message_users_ << 1) | (message_chats_ << 2) | (message_megagroups_ << 3) | (message_channels_ << 4) | (files_ << 5)));
    if (var0 & 1) { s.store_field("contacts", true); }
    if (var0 & 2) { s.store_field("message_users", true); }
    if (var0 & 4) { s.store_field("message_chats", true); }
    if (var0 & 8) { s.store_field("message_megagroups", true); }
    if (var0 & 16) { s.store_field("message_channels", true); }
    if (var0 & 32) { s.store_field("files", true); }
    if (var0 & 32) { s.store_field("file_max_size", file_max_size_); }
    s.store_class_end();
  }
}

account_initTakeoutSession::ReturnType account_initTakeoutSession::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_takeout>, 1304052993>::parse(p);
#undef FAIL
}

account_installTheme::account_installTheme(int32 flags_, bool dark_, object_ptr<InputTheme> &&theme_, string const &format_, object_ptr<BaseTheme> &&base_theme_)
  : flags_(flags_)
  , dark_(dark_)
  , theme_(std::move(theme_))
  , format_(format_)
  , base_theme_(std::move(base_theme_))
{}

const std::int32_t account_installTheme::ID;

void account_installTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-953697477);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0) | ((theme_ != nullptr) << 1) | ((!format_.empty()) << 2) | ((base_theme_ != nullptr) << 3)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s); }
  if (var0 & 4) { TlStoreString::store(format_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s); }
}

void account_installTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-953697477);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0) | ((theme_ != nullptr) << 1) | ((!format_.empty()) << 2) | ((base_theme_ != nullptr) << 3)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s); }
  if (var0 & 4) { TlStoreString::store(format_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s); }
}

void account_installTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.installTheme");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0) | ((theme_ != nullptr) << 1) | ((!format_.empty()) << 2) | ((base_theme_ != nullptr) << 3)));
    if (var0 & 1) { s.store_field("dark", true); }
    if (var0 & 2) { s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get())); }
    if (var0 & 4) { s.store_field("format", format_); }
    if (var0 & 8) { s.store_object_field("base_theme", static_cast<const BaseObject *>(base_theme_.get())); }
    s.store_class_end();
  }
}

account_installTheme::ReturnType account_installTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_saveSecureValue::account_saveSecureValue(object_ptr<inputSecureValue> &&value_, int64 secure_secret_id_)
  : value_(std::move(value_))
  , secure_secret_id_(secure_secret_id_)
{}

const std::int32_t account_saveSecureValue::ID;

void account_saveSecureValue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1986010339);
  TlStoreBoxed<TlStoreObject, -618540889>::store(value_, s);
  TlStoreBinary::store(secure_secret_id_, s);
}

void account_saveSecureValue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1986010339);
  TlStoreBoxed<TlStoreObject, -618540889>::store(value_, s);
  TlStoreBinary::store(secure_secret_id_, s);
}

void account_saveSecureValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveSecureValue");
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_field("secure_secret_id", secure_secret_id_);
    s.store_class_end();
  }
}

account_saveSecureValue::ReturnType account_saveSecureValue::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<secureValue>, 411017418>::parse(p);
#undef FAIL
}

account_saveTheme::account_saveTheme(object_ptr<InputTheme> &&theme_, bool unsave_)
  : theme_(std::move(theme_))
  , unsave_(unsave_)
{}

const std::int32_t account_saveTheme::ID;

void account_saveTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-229175188);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
  TlStoreBool::store(unsave_, s);
}

void account_saveTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-229175188);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
  TlStoreBool::store(unsave_, s);
}

void account_saveTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveTheme");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_field("unsave", unsave_);
    s.store_class_end();
  }
}

account_saveTheme::ReturnType account_saveTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_setGlobalPrivacySettings::account_setGlobalPrivacySettings(object_ptr<globalPrivacySettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t account_setGlobalPrivacySettings::ID;

void account_setGlobalPrivacySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(517647042);
  TlStoreBoxed<TlStoreObject, -29248689>::store(settings_, s);
}

void account_setGlobalPrivacySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(517647042);
  TlStoreBoxed<TlStoreObject, -29248689>::store(settings_, s);
}

void account_setGlobalPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setGlobalPrivacySettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_setGlobalPrivacySettings::ReturnType account_setGlobalPrivacySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<globalPrivacySettings>, -29248689>::parse(p);
#undef FAIL
}

account_updateBusinessGreetingMessage::account_updateBusinessGreetingMessage(int32 flags_, object_ptr<inputBusinessGreetingMessage> &&message_)
  : flags_(flags_)
  , message_(std::move(message_))
{}

const std::int32_t account_updateBusinessGreetingMessage::ID;

void account_updateBusinessGreetingMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1724755908);
  TlStoreBinary::store((var0 = flags_ | ((message_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 26528571>::store(message_, s); }
}

void account_updateBusinessGreetingMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1724755908);
  TlStoreBinary::store((var0 = flags_ | ((message_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 26528571>::store(message_, s); }
}

void account_updateBusinessGreetingMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBusinessGreetingMessage");
    s.store_field("flags", (var0 = flags_ | ((message_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

account_updateBusinessGreetingMessage::ReturnType account_updateBusinessGreetingMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_uploadRingtone::account_uploadRingtone(object_ptr<InputFile> &&file_, string const &file_name_, string const &mime_type_)
  : file_(std::move(file_))
  , file_name_(file_name_)
  , mime_type_(mime_type_)
{}

const std::int32_t account_uploadRingtone::ID;

void account_uploadRingtone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2095414366);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreString::store(file_name_, s);
  TlStoreString::store(mime_type_, s);
}

void account_uploadRingtone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2095414366);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreString::store(file_name_, s);
  TlStoreString::store(mime_type_, s);
}

void account_uploadRingtone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.uploadRingtone");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_class_end();
  }
}

account_uploadRingtone::ReturnType account_uploadRingtone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Document>::parse(p);
#undef FAIL
}

account_uploadTheme::account_uploadTheme(int32 flags_, object_ptr<InputFile> &&file_, object_ptr<InputFile> &&thumb_, string const &file_name_, string const &mime_type_)
  : flags_(flags_)
  , file_(std::move(file_))
  , thumb_(std::move(thumb_))
  , file_name_(file_name_)
  , mime_type_(mime_type_)
{}

const std::int32_t account_uploadTheme::ID;

void account_uploadTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(473805619);
  TlStoreBinary::store((var0 = flags_ | ((thumb_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreString::store(file_name_, s);
  TlStoreString::store(mime_type_, s);
}

void account_uploadTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(473805619);
  TlStoreBinary::store((var0 = flags_ | ((thumb_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreString::store(file_name_, s);
  TlStoreString::store(mime_type_, s);
}

void account_uploadTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.uploadTheme");
    s.store_field("flags", (var0 = flags_ | ((thumb_ != nullptr) << 0)));
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    if (var0 & 1) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_class_end();
  }
}

account_uploadTheme::ReturnType account_uploadTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Document>::parse(p);
#undef FAIL
}

aicompose_saveTone::aicompose_saveTone(object_ptr<InputAiComposeTone> &&tone_, bool unsave_)
  : tone_(std::move(tone_))
  , unsave_(unsave_)
{}

const std::int32_t aicompose_saveTone::ID;

void aicompose_saveTone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(394447793);
  TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s);
  TlStoreBool::store(unsave_, s);
}

void aicompose_saveTone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(394447793);
  TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s);
  TlStoreBool::store(unsave_, s);
}

void aicompose_saveTone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aicompose.saveTone");
    s.store_object_field("tone", static_cast<const BaseObject *>(tone_.get()));
    s.store_field("unsave", unsave_);
    s.store_class_end();
  }
}

aicompose_saveTone::ReturnType aicompose_saveTone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_finishPasskeyLogin::auth_finishPasskeyLogin(int32 flags_, object_ptr<inputPasskeyCredentialPublicKey> &&credential_, int32 from_dc_id_, int64 from_auth_key_id_)
  : flags_(flags_)
  , credential_(std::move(credential_))
  , from_dc_id_(from_dc_id_)
  , from_auth_key_id_(from_auth_key_id_)
{}

const std::int32_t auth_finishPasskeyLogin::ID;

void auth_finishPasskeyLogin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1739084537);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, 1009235855>::store(credential_, s);
  if (var0 & 1) { TlStoreBinary::store(from_dc_id_, s); }
  if (var0 & 1) { TlStoreBinary::store(from_auth_key_id_, s); }
}

void auth_finishPasskeyLogin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1739084537);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, 1009235855>::store(credential_, s);
  if (var0 & 1) { TlStoreBinary::store(from_dc_id_, s); }
  if (var0 & 1) { TlStoreBinary::store(from_auth_key_id_, s); }
}

void auth_finishPasskeyLogin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.finishPasskeyLogin");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("credential", static_cast<const BaseObject *>(credential_.get()));
    if (var0 & 1) { s.store_field("from_dc_id", from_dc_id_); }
    if (var0 & 1) { s.store_field("from_auth_key_id", from_auth_key_id_); }
    s.store_class_end();
  }
}

auth_finishPasskeyLogin::ReturnType auth_finishPasskeyLogin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

bots_checkUsername::bots_checkUsername(int32 flags_, bool additional_, string const &username_)
  : flags_(flags_)
  , additional_(additional_)
  , username_(username_)
{}

const std::int32_t bots_checkUsername::ID;

void bots_checkUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-475247519);
  TlStoreBinary::store((var0 = flags_ | (additional_ << 0)), s);
  TlStoreString::store(username_, s);
}

void bots_checkUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-475247519);
  TlStoreBinary::store((var0 = flags_ | (additional_ << 0)), s);
  TlStoreString::store(username_, s);
}

void bots_checkUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.checkUsername");
    s.store_field("flags", (var0 = flags_ | (additional_ << 0)));
    if (var0 & 1) { s.store_field("additional", true); }
    s.store_field("username", username_);
    s.store_class_end();
  }
}

bots_checkUsername::ReturnType bots_checkUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_deletePreviewMedia::bots_deletePreviewMedia(object_ptr<InputUser> &&bot_, string const &lang_code_, array<object_ptr<InputMedia>> &&media_)
  : bot_(std::move(bot_))
  , lang_code_(lang_code_)
  , media_(std::move(media_))
{}

const std::int32_t bots_deletePreviewMedia::ID;

void bots_deletePreviewMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(755054003);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_, s);
}

void bots_deletePreviewMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(755054003);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_, s);
}

void bots_deletePreviewMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.deletePreviewMedia");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("lang_code", lang_code_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

bots_deletePreviewMedia::ReturnType bots_deletePreviewMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_exportBotToken::bots_exportBotToken(object_ptr<InputUser> &&bot_, bool revoke_)
  : bot_(std::move(bot_))
  , revoke_(revoke_)
{}

const std::int32_t bots_exportBotToken::ID;

void bots_exportBotToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1123182101);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(revoke_, s);
}

void bots_exportBotToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1123182101);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(revoke_, s);
}

void bots_exportBotToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.exportBotToken");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

bots_exportBotToken::ReturnType bots_exportBotToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<bots_exportedBotToken>, 1012971041>::parse(p);
#undef FAIL
}

const std::int32_t bots_getAdminedBots::ID;

void bots_getAdminedBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1334764157);
}

void bots_getAdminedBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1334764157);
}

void bots_getAdminedBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getAdminedBots");
    s.store_class_end();
  }
}

bots_getAdminedBots::ReturnType bots_getAdminedBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
#undef FAIL
}

channels_editBanned::channels_editBanned(object_ptr<InputChannel> &&channel_, object_ptr<InputPeer> &&participant_, object_ptr<chatBannedRights> &&banned_rights_)
  : channel_(std::move(channel_))
  , participant_(std::move(participant_))
  , banned_rights_(std::move(banned_rights_))
{}

const std::int32_t channels_editBanned::ID;

void channels_editBanned::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1763259007);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s);
}

void channels_editBanned::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1763259007);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s);
}

void channels_editBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.editBanned");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_object_field("banned_rights", static_cast<const BaseObject *>(banned_rights_.get()));
    s.store_class_end();
  }
}

channels_editBanned::ReturnType channels_editBanned::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_getAdminedPublicChannels::channels_getAdminedPublicChannels(int32 flags_, bool by_location_, bool check_limit_, bool for_personal_, bool for_community_peer_)
  : flags_(flags_)
  , by_location_(by_location_)
  , check_limit_(check_limit_)
  , for_personal_(for_personal_)
  , for_community_peer_(for_community_peer_)
{}

const std::int32_t channels_getAdminedPublicChannels::ID;

void channels_getAdminedPublicChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-122669393);
  TlStoreBinary::store((var0 = flags_ | (by_location_ << 0) | (check_limit_ << 1) | (for_personal_ << 2) | (for_community_peer_ << 3)), s);
}

void channels_getAdminedPublicChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-122669393);
  TlStoreBinary::store((var0 = flags_ | (by_location_ << 0) | (check_limit_ << 1) | (for_personal_ << 2) | (for_community_peer_ << 3)), s);
}

void channels_getAdminedPublicChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getAdminedPublicChannels");
    s.store_field("flags", (var0 = flags_ | (by_location_ << 0) | (check_limit_ << 1) | (for_personal_ << 2) | (for_community_peer_ << 3)));
    if (var0 & 1) { s.store_field("by_location", true); }
    if (var0 & 2) { s.store_field("check_limit", true); }
    if (var0 & 4) { s.store_field("for_personal", true); }
    if (var0 & 8) { s.store_field("for_community_peer", true); }
    s.store_class_end();
  }
}

channels_getAdminedPublicChannels::ReturnType channels_getAdminedPublicChannels::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

channels_getMessageAuthor::channels_getMessageAuthor(object_ptr<InputChannel> &&channel_, int32 id_)
  : channel_(std::move(channel_))
  , id_(id_)
{}

const std::int32_t channels_getMessageAuthor::ID;

void channels_getMessageAuthor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-320691994);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(id_, s);
}

void channels_getMessageAuthor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-320691994);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(id_, s);
}

void channels_getMessageAuthor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getMessageAuthor");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

channels_getMessageAuthor::ReturnType channels_getMessageAuthor::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

channels_setEmojiStickers::channels_setEmojiStickers(object_ptr<InputChannel> &&channel_, object_ptr<InputStickerSet> &&stickerset_)
  : channel_(std::move(channel_))
  , stickerset_(std::move(stickerset_))
{}

const std::int32_t channels_setEmojiStickers::ID;

void channels_setEmojiStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1020866743);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void channels_setEmojiStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1020866743);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void channels_setEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.setEmojiStickers");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

channels_setEmojiStickers::ReturnType channels_setEmojiStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

chatlists_deleteExportedInvite::chatlists_deleteExportedInvite(object_ptr<inputChatlistDialogFilter> &&chatlist_, string const &slug_)
  : chatlist_(std::move(chatlist_))
  , slug_(slug_)
{}

const std::int32_t chatlists_deleteExportedInvite::ID;

void chatlists_deleteExportedInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1906072670);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(slug_, s);
}

void chatlists_deleteExportedInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1906072670);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(slug_, s);
}

void chatlists_deleteExportedInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.deleteExportedInvite");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

chatlists_deleteExportedInvite::ReturnType chatlists_deleteExportedInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_composeRichMessageWithAI::messages_composeRichMessageWithAI(int32 flags_, bool proofread_, bool emojify_, object_ptr<InputRichMessage> &&text_, string const &translate_to_lang_, object_ptr<InputAiComposeTone> &&tone_)
  : flags_(flags_)
  , proofread_(proofread_)
  , emojify_(emojify_)
  , text_(std::move(text_))
  , translate_to_lang_(translate_to_lang_)
  , tone_(std::move(tone_))
{}

const std::int32_t messages_composeRichMessageWithAI::ID;

void messages_composeRichMessageWithAI::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1921325393);
  TlStoreBinary::store((var0 = flags_ | (proofread_ << 0) | (emojify_ << 3) | ((text_ != nullptr) << 4) | ((!translate_to_lang_.empty()) << 1) | ((tone_ != nullptr) << 2)), s);
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(text_, s); }
  if (var0 & 2) { TlStoreString::store(translate_to_lang_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s); }
}

void messages_composeRichMessageWithAI::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1921325393);
  TlStoreBinary::store((var0 = flags_ | (proofread_ << 0) | (emojify_ << 3) | ((text_ != nullptr) << 4) | ((!translate_to_lang_.empty()) << 1) | ((tone_ != nullptr) << 2)), s);
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(text_, s); }
  if (var0 & 2) { TlStoreString::store(translate_to_lang_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s); }
}

void messages_composeRichMessageWithAI::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.composeRichMessageWithAI");
    s.store_field("flags", (var0 = flags_ | (proofread_ << 0) | (emojify_ << 3) | ((text_ != nullptr) << 4) | ((!translate_to_lang_.empty()) << 1) | ((tone_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("proofread", true); }
    if (var0 & 8) { s.store_field("emojify", true); }
    if (var0 & 16) { s.store_object_field("text", static_cast<const BaseObject *>(text_.get())); }
    if (var0 & 2) { s.store_field("translate_to_lang", translate_to_lang_); }
    if (var0 & 4) { s.store_object_field("tone", static_cast<const BaseObject *>(tone_.get())); }
    s.store_class_end();
  }
}

messages_composeRichMessageWithAI::ReturnType messages_composeRichMessageWithAI::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_composedRichMessageWithAI>, 1279604680>::parse(p);
#undef FAIL
}

messages_declineUrlAuth::messages_declineUrlAuth(string const &url_)
  : url_(url_)
{}

const std::int32_t messages_declineUrlAuth::ID;

void messages_declineUrlAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(893610940);
  TlStoreString::store(url_, s);
}

void messages_declineUrlAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(893610940);
  TlStoreString::store(url_, s);
}

void messages_declineUrlAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.declineUrlAuth");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

messages_declineUrlAuth::ReturnType messages_declineUrlAuth::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deleteParticipantReactions::messages_deleteParticipantReactions(object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&participant_)
  : peer_(std::move(peer_))
  , participant_(std::move(participant_))
{}

const std::int32_t messages_deleteParticipantReactions::ID;

void messages_deleteParticipantReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1598550792);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void messages_deleteParticipantReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1598550792);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void messages_deleteParticipantReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteParticipantReactions");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

messages_deleteParticipantReactions::ReturnType messages_deleteParticipantReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_discardEncryption::messages_discardEncryption(int32 flags_, bool delete_history_, int32 chat_id_)
  : flags_(flags_)
  , delete_history_(delete_history_)
  , chat_id_(chat_id_)
{}

const std::int32_t messages_discardEncryption::ID;

void messages_discardEncryption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-208425312);
  TlStoreBinary::store((var0 = flags_ | (delete_history_ << 0)), s);
  TlStoreBinary::store(chat_id_, s);
}

void messages_discardEncryption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-208425312);
  TlStoreBinary::store((var0 = flags_ | (delete_history_ << 0)), s);
  TlStoreBinary::store(chat_id_, s);
}

void messages_discardEncryption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.discardEncryption");
    s.store_field("flags", (var0 = flags_ | (delete_history_ << 0)));
    if (var0 & 1) { s.store_field("delete_history", true); }
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

messages_discardEncryption::ReturnType messages_discardEncryption::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_editChatDefaultBannedRights::messages_editChatDefaultBannedRights(object_ptr<InputPeer> &&peer_, object_ptr<chatBannedRights> &&banned_rights_)
  : peer_(std::move(peer_))
  , banned_rights_(std::move(banned_rights_))
{}

const std::int32_t messages_editChatDefaultBannedRights::ID;

void messages_editChatDefaultBannedRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1517917375);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s);
}

void messages_editChatDefaultBannedRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1517917375);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s);
}

void messages_editChatDefaultBannedRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatDefaultBannedRights");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("banned_rights", static_cast<const BaseObject *>(banned_rights_.get()));
    s.store_class_end();
  }
}

messages_editChatDefaultBannedRights::ReturnType messages_editChatDefaultBannedRights::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editChatPhoto::messages_editChatPhoto(int64 chat_id_, object_ptr<InputChatPhoto> &&photo_)
  : chat_id_(chat_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t messages_editChatPhoto::ID;

void messages_editChatPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(903730804);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
}

void messages_editChatPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(903730804);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
}

void messages_editChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatPhoto");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

messages_editChatPhoto::ReturnType messages_editChatPhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getAdminsWithInvites::messages_getAdminsWithInvites(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_getAdminsWithInvites::ID;

void messages_getAdminsWithInvites::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(958457583);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getAdminsWithInvites::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(958457583);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getAdminsWithInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAdminsWithInvites");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_getAdminsWithInvites::ReturnType messages_getAdminsWithInvites::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_chatAdminsWithInvites>, -1231326505>::parse(p);
#undef FAIL
}

messages_getEmojiKeywordsDifference::messages_getEmojiKeywordsDifference(string const &lang_code_, int32 from_version_)
  : lang_code_(lang_code_)
  , from_version_(from_version_)
{}

const std::int32_t messages_getEmojiKeywordsDifference::ID;

void messages_getEmojiKeywordsDifference::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(352892591);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(from_version_, s);
}

void messages_getEmojiKeywordsDifference::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(352892591);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(from_version_, s);
}

void messages_getEmojiKeywordsDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiKeywordsDifference");
    s.store_field("lang_code", lang_code_);
    s.store_field("from_version", from_version_);
    s.store_class_end();
  }
}

messages_getEmojiKeywordsDifference::ReturnType messages_getEmojiKeywordsDifference::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<emojiKeywordsDifference>, 1556570557>::parse(p);
#undef FAIL
}

messages_getMessages::messages_getMessages(array<object_ptr<InputMessage>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t messages_getMessages::ID;

void messages_getMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1673946374);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void messages_getMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1673946374);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void messages_getMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessages");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getMessages::ReturnType messages_getMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getMessagesViews::messages_getMessagesViews(object_ptr<InputPeer> &&peer_, array<int32> &&id_, bool increment_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
  , increment_(increment_)
{}

const std::int32_t messages_getMessagesViews::ID;

void messages_getMessagesViews::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1468322785);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBool::store(increment_, s);
}

void messages_getMessagesViews::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1468322785);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBool::store(increment_, s);
}

void messages_getMessagesViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessagesViews");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("increment", increment_);
    s.store_class_end();
  }
}

messages_getMessagesViews::ReturnType messages_getMessagesViews::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_messageViews>, -1228606141>::parse(p);
#undef FAIL
}

messages_getScheduledHistory::messages_getScheduledHistory(object_ptr<InputPeer> &&peer_, int64 hash_)
  : peer_(std::move(peer_))
  , hash_(hash_)
{}

const std::int32_t messages_getScheduledHistory::ID;

void messages_getScheduledHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-183077365);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getScheduledHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-183077365);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getScheduledHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getScheduledHistory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getScheduledHistory::ReturnType messages_getScheduledHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getScheduledMessages::messages_getScheduledMessages(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_getScheduledMessages::ID;

void messages_getScheduledMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1111817116);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getScheduledMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1111817116);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getScheduledMessages");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getScheduledMessages::ReturnType messages_getScheduledMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

const std::int32_t messages_getSuggestedDialogFilters::ID;

void messages_getSuggestedDialogFilters::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1566780372);
}

void messages_getSuggestedDialogFilters::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1566780372);
}

void messages_getSuggestedDialogFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSuggestedDialogFilters");
    s.store_class_end();
  }
}

messages_getSuggestedDialogFilters::ReturnType messages_getSuggestedDialogFilters::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<dialogFilterSuggested>, 2004110666>>, 481674261>::parse(p);
#undef FAIL
}

messages_hideChatJoinRequest::messages_hideChatJoinRequest(int32 flags_, bool approved_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , approved_(approved_)
  , peer_(std::move(peer_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t messages_hideChatJoinRequest::ID;

void messages_hideChatJoinRequest::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2145904661);
  TlStoreBinary::store((var0 = flags_ | (approved_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_hideChatJoinRequest::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2145904661);
  TlStoreBinary::store((var0 = flags_ | (approved_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_hideChatJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.hideChatJoinRequest");
    s.store_field("flags", (var0 = flags_ | (approved_ << 0)));
    if (var0 & 1) { s.store_field("approved", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

messages_hideChatJoinRequest::ReturnType messages_hideChatJoinRequest::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_initHistoryImport::messages_initHistoryImport(object_ptr<InputPeer> &&peer_, object_ptr<InputFile> &&file_, int32 media_count_)
  : peer_(std::move(peer_))
  , file_(std::move(file_))
  , media_count_(media_count_)
{}

const std::int32_t messages_initHistoryImport::ID;

void messages_initHistoryImport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(873008187);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreBinary::store(media_count_, s);
}

void messages_initHistoryImport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(873008187);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreBinary::store(media_count_, s);
}

void messages_initHistoryImport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.initHistoryImport");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("media_count", media_count_);
    s.store_class_end();
  }
}

messages_initHistoryImport::ReturnType messages_initHistoryImport::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_historyImport>, 375566091>::parse(p);
#undef FAIL
}

messages_readFeaturedStickers::messages_readFeaturedStickers(array<int64> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t messages_readFeaturedStickers::ID;

void messages_readFeaturedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1527873830);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_readFeaturedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1527873830);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_readFeaturedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readFeaturedStickers");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_readFeaturedStickers::ReturnType messages_readFeaturedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_reorderStickerSets::messages_reorderStickerSets(int32 flags_, bool masks_, bool emojis_, array<int64> &&order_)
  : flags_(flags_)
  , masks_(masks_)
  , emojis_(emojis_)
  , order_(std::move(order_))
{}

const std::int32_t messages_reorderStickerSets::ID;

void messages_reorderStickerSets::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2016638777);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderStickerSets::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2016638777);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reorderStickerSets");
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 1)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 2) { s.store_field("emojis", true); }
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reorderStickerSets::ReturnType messages_reorderStickerSets::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_savePreparedInlineMessage::messages_savePreparedInlineMessage(int32 flags_, object_ptr<InputBotInlineResult> &&result_, object_ptr<InputUser> &&user_id_, array<object_ptr<InlineQueryPeerType>> &&peer_types_)
  : flags_(flags_)
  , result_(std::move(result_))
  , user_id_(std::move(user_id_))
  , peer_types_(std::move(peer_types_))
{}

const std::int32_t messages_savePreparedInlineMessage::ID;

void messages_savePreparedInlineMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-232816849);
  TlStoreBinary::store((var0 = flags_ | ((!peer_types_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peer_types_, s); }
}

void messages_savePreparedInlineMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-232816849);
  TlStoreBinary::store((var0 = flags_ | ((!peer_types_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peer_types_, s); }
}

void messages_savePreparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savePreparedInlineMessage");
    s.store_field("flags", (var0 = flags_ | ((!peer_types_.empty()) << 0)));
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    if (var0 & 1) { { s.store_vector_begin("peer_types", peer_types_.size()); for (const auto &_value : peer_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messages_savePreparedInlineMessage::ReturnType messages_savePreparedInlineMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_botPreparedInlineMessage>, -1899035375>::parse(p);
#undef FAIL
}

messages_searchCustomEmoji::messages_searchCustomEmoji(string const &emoticon_, int64 hash_)
  : emoticon_(emoticon_)
  , hash_(hash_)
{}

const std::int32_t messages_searchCustomEmoji::ID;

void messages_searchCustomEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(739360983);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchCustomEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(739360983);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchCustomEmoji");
    s.store_field("emoticon", emoticon_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_searchCustomEmoji::ReturnType messages_searchCustomEmoji::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EmojiList>::parse(p);
#undef FAIL
}

messages_sendEncrypted::messages_sendEncrypted(int32 flags_, bool silent_, object_ptr<inputEncryptedChat> &&peer_, int64 random_id_, bytes &&data_)
  : flags_(flags_)
  , silent_(silent_)
  , peer_(std::move(peer_))
  , random_id_(random_id_)
  , data_(std::move(data_))
{}

const std::int32_t messages_sendEncrypted::ID;

void messages_sendEncrypted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1157265941);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0)), s);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
}

void messages_sendEncrypted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1157265941);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0)), s);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
}

void messages_sendEncrypted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendEncrypted");
    s.store_field("flags", (var0 = flags_ | (silent_ << 0)));
    if (var0 & 1) { s.store_field("silent", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("random_id", random_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

messages_sendEncrypted::ReturnType messages_sendEncrypted::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SentEncryptedMessage>::parse(p);
#undef FAIL
}

messages_setChatAvailableReactions::messages_setChatAvailableReactions(int32 flags_, object_ptr<InputPeer> &&peer_, object_ptr<ChatReactions> &&available_reactions_, int32 reactions_limit_, bool paid_enabled_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , available_reactions_(std::move(available_reactions_))
  , reactions_limit_(reactions_limit_)
  , paid_enabled_(paid_enabled_)
{}

const std::int32_t messages_setChatAvailableReactions::ID;

void messages_setChatAvailableReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2041895551);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(available_reactions_, s);
  if (var0 & 1) { TlStoreBinary::store(reactions_limit_, s); }
  if (var0 & 2) { TlStoreBool::store(paid_enabled_, s); }
}

void messages_setChatAvailableReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2041895551);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(available_reactions_, s);
  if (var0 & 1) { TlStoreBinary::store(reactions_limit_, s); }
  if (var0 & 2) { TlStoreBool::store(paid_enabled_, s); }
}

void messages_setChatAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setChatAvailableReactions");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get()));
    if (var0 & 1) { s.store_field("reactions_limit", reactions_limit_); }
    if (var0 & 2) { s.store_field("paid_enabled", paid_enabled_); }
    s.store_class_end();
  }
}

messages_setChatAvailableReactions::ReturnType messages_setChatAvailableReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setChatTheme::messages_setChatTheme(object_ptr<InputPeer> &&peer_, object_ptr<InputChatTheme> &&theme_)
  : peer_(std::move(peer_))
  , theme_(std::move(theme_))
{}

const std::int32_t messages_setChatTheme::ID;

void messages_setChatTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(135398089);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
}

void messages_setChatTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(135398089);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
}

void messages_setChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setChatTheme");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

messages_setChatTheme::ReturnType messages_setChatTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_toggleDialogPin::messages_toggleDialogPin(int32 flags_, bool pinned_, object_ptr<InputDialogPeer> &&peer_)
  : flags_(flags_)
  , pinned_(pinned_)
  , peer_(std::move(peer_))
{}

const std::int32_t messages_toggleDialogPin::ID;

void messages_toggleDialogPin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1489903017);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_toggleDialogPin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1489903017);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_toggleDialogPin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleDialogPin");
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_toggleDialogPin::ReturnType messages_toggleDialogPin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_translateText::messages_translateText(int32 flags_, object_ptr<InputPeer> &&peer_, array<int32> &&id_, array<object_ptr<textWithEntities>> &&text_, string const &to_lang_, string const &tone_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(std::move(id_))
  , text_(std::move(text_))
  , to_lang_(to_lang_)
  , tone_(tone_)
{}

const std::int32_t messages_translateText::ID;

void messages_translateText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1511079099);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0) | ((!id_.empty()) << 0) | ((!text_.empty()) << 1) | ((!tone_.empty()) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1964978502>>, 481674261>::store(text_, s); }
  TlStoreString::store(to_lang_, s);
  if (var0 & 4) { TlStoreString::store(tone_, s); }
}

void messages_translateText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1511079099);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0) | ((!id_.empty()) << 0) | ((!text_.empty()) << 1) | ((!tone_.empty()) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1964978502>>, 481674261>::store(text_, s); }
  TlStoreString::store(to_lang_, s);
  if (var0 & 4) { TlStoreString::store(tone_, s); }
}

void messages_translateText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.translateText");
    s.store_field("flags", (var0 = flags_ | ((peer_ != nullptr) << 0) | ((!id_.empty()) << 0) | ((!text_.empty()) << 1) | ((!tone_.empty()) << 2)));
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 1) { { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 2) { { s.store_vector_begin("text", text_.size()); for (const auto &_value : text_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("to_lang", to_lang_);
    if (var0 & 4) { s.store_field("tone", tone_); }
    s.store_class_end();
  }
}

messages_translateText::ReturnType messages_translateText::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_translateResult>, 870003448>::parse(p);
#undef FAIL
}

payments_createStarGiftCollection::payments_createStarGiftCollection(object_ptr<InputPeer> &&peer_, string const &title_, array<object_ptr<InputSavedStarGift>> &&stargift_)
  : peer_(std::move(peer_))
  , title_(title_)
  , stargift_(std::move(stargift_))
{}

const std::int32_t payments_createStarGiftCollection::ID;

void payments_createStarGiftCollection::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(524947079);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_createStarGiftCollection::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(524947079);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_createStarGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.createStarGiftCollection");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("title", title_);
    { s.store_vector_begin("stargift", stargift_.size()); for (const auto &_value : stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_createStarGiftCollection::ReturnType payments_createStarGiftCollection::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<starGiftCollection>, -1653926992>::parse(p);
#undef FAIL
}

payments_fulfillStarsSubscription::payments_fulfillStarsSubscription(object_ptr<InputPeer> &&peer_, string const &subscription_id_)
  : peer_(std::move(peer_))
  , subscription_id_(subscription_id_)
{}

const std::int32_t payments_fulfillStarsSubscription::ID;

void payments_fulfillStarsSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-866391117);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(subscription_id_, s);
}

void payments_fulfillStarsSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-866391117);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(subscription_id_, s);
}

void payments_fulfillStarsSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.fulfillStarsSubscription");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("subscription_id", subscription_id_);
    s.store_class_end();
  }
}

payments_fulfillStarsSubscription::ReturnType payments_fulfillStarsSubscription::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_getPaymentForm::payments_getPaymentForm(int32 flags_, object_ptr<InputInvoice> &&invoice_, object_ptr<dataJSON> &&theme_params_)
  : flags_(flags_)
  , invoice_(std::move(invoice_))
  , theme_params_(std::move(theme_params_))
{}

const std::int32_t payments_getPaymentForm::ID;

void payments_getPaymentForm::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(924093883);
  TlStoreBinary::store((var0 = flags_ | ((theme_params_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
}

void payments_getPaymentForm::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(924093883);
  TlStoreBinary::store((var0 = flags_ | ((theme_params_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
}

void payments_getPaymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getPaymentForm");
    s.store_field("flags", (var0 = flags_ | ((theme_params_ != nullptr) << 0)));
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    if (var0 & 1) { s.store_object_field("theme_params", static_cast<const BaseObject *>(theme_params_.get())); }
    s.store_class_end();
  }
}

payments_getPaymentForm::ReturnType payments_getPaymentForm::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_PaymentForm>::parse(p);
#undef FAIL
}

payments_getPaymentReceipt::payments_getPaymentReceipt(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t payments_getPaymentReceipt::ID;

void payments_getPaymentReceipt::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(611897804);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void payments_getPaymentReceipt::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(611897804);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void payments_getPaymentReceipt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getPaymentReceipt");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

payments_getPaymentReceipt::ReturnType payments_getPaymentReceipt::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_PaymentReceipt>::parse(p);
#undef FAIL
}

payments_getStarGiftAuctionAcquiredGifts::payments_getStarGiftAuctionAcquiredGifts(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t payments_getStarGiftAuctionAcquiredGifts::ID;

void payments_getStarGiftAuctionAcquiredGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1805831148);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftAuctionAcquiredGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1805831148);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftAuctionAcquiredGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftAuctionAcquiredGifts");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

payments_getStarGiftAuctionAcquiredGifts::ReturnType payments_getStarGiftAuctionAcquiredGifts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftAuctionAcquiredGifts>, 2103169520>::parse(p);
#undef FAIL
}

payments_getStarGiftAuctionState::payments_getStarGiftAuctionState(object_ptr<InputStarGiftAuction> &&auction_, int32 version_)
  : auction_(std::move(auction_))
  , version_(version_)
{}

const std::int32_t payments_getStarGiftAuctionState::ID;

void payments_getStarGiftAuctionState::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1553986774);
  TlStoreBoxedUnknown<TlStoreObject>::store(auction_, s);
  TlStoreBinary::store(version_, s);
}

void payments_getStarGiftAuctionState::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1553986774);
  TlStoreBoxedUnknown<TlStoreObject>::store(auction_, s);
  TlStoreBinary::store(version_, s);
}

void payments_getStarGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftAuctionState");
    s.store_object_field("auction", static_cast<const BaseObject *>(auction_.get()));
    s.store_field("version", version_);
    s.store_class_end();
  }
}

payments_getStarGiftAuctionState::ReturnType payments_getStarGiftAuctionState::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftAuctionState>, 1798960364>::parse(p);
#undef FAIL
}

payments_getStarGiftUpgradeAttributes::payments_getStarGiftUpgradeAttributes(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t payments_getStarGiftUpgradeAttributes::ID;

void payments_getStarGiftUpgradeAttributes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1828948824);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftUpgradeAttributes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1828948824);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftUpgradeAttributes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftUpgradeAttributes");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

payments_getStarGiftUpgradeAttributes::ReturnType payments_getStarGiftUpgradeAttributes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftUpgradeAttributes>, 1187439471>::parse(p);
#undef FAIL
}

payments_transferStarGift::payments_transferStarGift(object_ptr<InputSavedStarGift> &&stargift_, object_ptr<InputPeer> &&to_id_)
  : stargift_(std::move(stargift_))
  , to_id_(std::move(to_id_))
{}

const std::int32_t payments_transferStarGift::ID;

void payments_transferStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2132285290);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
}

void payments_transferStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2132285290);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
}

void payments_transferStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.transferStarGift");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_object_field("to_id", static_cast<const BaseObject *>(to_id_.get()));
    s.store_class_end();
  }
}

payments_transferStarGift::ReturnType payments_transferStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_updateStarGiftOnchainPrice::payments_updateStarGiftOnchainPrice(string const &slug_, int64 amount_)
  : slug_(slug_)
  , amount_(amount_)
{}

const std::int32_t payments_updateStarGiftOnchainPrice::ID;

void payments_updateStarGiftOnchainPrice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1035934769);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(amount_, s);
}

void payments_updateStarGiftOnchainPrice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1035934769);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(amount_, s);
}

void payments_updateStarGiftOnchainPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.updateStarGiftOnchainPrice");
    s.store_field("slug", slug_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

payments_updateStarGiftOnchainPrice::ReturnType payments_updateStarGiftOnchainPrice::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_StarGiftOnchainSalePayload>::parse(p);
#undef FAIL
}

phone_discardGroupCall::phone_discardGroupCall(object_ptr<InputGroupCall> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t phone_discardGroupCall::ID;

void phone_discardGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2054648117);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_discardGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2054648117);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_discardGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.discardGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_discardGroupCall::ReturnType phone_discardGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_getGroupParticipants::phone_getGroupParticipants(object_ptr<InputGroupCall> &&call_, array<object_ptr<InputPeer>> &&ids_, array<int32> &&sources_, string const &offset_, int32 limit_)
  : call_(std::move(call_))
  , ids_(std::move(ids_))
  , sources_(std::move(sources_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t phone_getGroupParticipants::ID;

void phone_getGroupParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-984033109);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(ids_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sources_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-984033109);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(ids_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sources_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupParticipants");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("ids", ids_.size()); for (const auto &_value : ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("sources", sources_.size()); for (const auto &_value : sources_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

phone_getGroupParticipants::ReturnType phone_getGroupParticipants::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_groupParticipants>, -193506890>::parse(p);
#undef FAIL
}

phone_saveDefaultGroupCallJoinAs::phone_saveDefaultGroupCallJoinAs(object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&join_as_)
  : peer_(std::move(peer_))
  , join_as_(std::move(join_as_))
{}

const std::int32_t phone_saveDefaultGroupCallJoinAs::ID;

void phone_saveDefaultGroupCallJoinAs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1465786252);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(join_as_, s);
}

void phone_saveDefaultGroupCallJoinAs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1465786252);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(join_as_, s);
}

void phone_saveDefaultGroupCallJoinAs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.saveDefaultGroupCallJoinAs");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("join_as", static_cast<const BaseObject *>(join_as_.get()));
    s.store_class_end();
  }
}

phone_saveDefaultGroupCallJoinAs::ReturnType phone_saveDefaultGroupCallJoinAs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_sendGroupCallEncryptedMessage::phone_sendGroupCallEncryptedMessage(object_ptr<InputGroupCall> &&call_, bytes &&encrypted_message_)
  : call_(std::move(call_))
  , encrypted_message_(std::move(encrypted_message_))
{}

const std::int32_t phone_sendGroupCallEncryptedMessage::ID;

void phone_sendGroupCallEncryptedMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-441473683);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(encrypted_message_, s);
}

void phone_sendGroupCallEncryptedMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-441473683);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(encrypted_message_, s);
}

void phone_sendGroupCallEncryptedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.sendGroupCallEncryptedMessage");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_bytes_field("encrypted_message", encrypted_message_);
    s.store_class_end();
  }
}

phone_sendGroupCallEncryptedMessage::ReturnType phone_sendGroupCallEncryptedMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_sendGroupCallMessage::phone_sendGroupCallMessage(int32 flags_, object_ptr<InputGroupCall> &&call_, int64 random_id_, object_ptr<textWithEntities> &&message_, int64 allow_paid_stars_, object_ptr<InputPeer> &&send_as_)
  : flags_(flags_)
  , call_(std::move(call_))
  , random_id_(random_id_)
  , message_(std::move(message_))
  , allow_paid_stars_(allow_paid_stars_)
  , send_as_(std::move(send_as_))
{}

const std::int32_t phone_sendGroupCallMessage::ID;

void phone_sendGroupCallMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1311697904);
  TlStoreBinary::store((var0 = flags_ | ((send_as_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s);
  if (var0 & 1) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void phone_sendGroupCallMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1311697904);
  TlStoreBinary::store((var0 = flags_ | ((send_as_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s);
  if (var0 & 1) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void phone_sendGroupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.sendGroupCallMessage");
    s.store_field("flags", (var0 = flags_ | ((send_as_ != nullptr) << 1)));
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("random_id", random_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    if (var0 & 1) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    if (var0 & 2) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    s.store_class_end();
  }
}

phone_sendGroupCallMessage::ReturnType phone_sendGroupCallMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_sendSignalingData::phone_sendSignalingData(object_ptr<inputPhoneCall> &&peer_, bytes &&data_)
  : peer_(std::move(peer_))
  , data_(std::move(data_))
{}

const std::int32_t phone_sendSignalingData::ID;

void phone_sendSignalingData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-8744061);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(data_, s);
}

void phone_sendSignalingData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-8744061);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(data_, s);
}

void phone_sendSignalingData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.sendSignalingData");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

phone_sendSignalingData::ReturnType phone_sendSignalingData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

premium_getBoostsList::premium_getBoostsList(int32 flags_, bool gifts_, object_ptr<InputPeer> &&peer_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , gifts_(gifts_)
  , peer_(std::move(peer_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t premium_getBoostsList::ID;

void premium_getBoostsList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1626764896);
  TlStoreBinary::store((var0 = flags_ | (gifts_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void premium_getBoostsList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1626764896);
  TlStoreBinary::store((var0 = flags_ | (gifts_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void premium_getBoostsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.getBoostsList");
    s.store_field("flags", (var0 = flags_ | (gifts_ << 0)));
    if (var0 & 1) { s.store_field("gifts", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

premium_getBoostsList::ReturnType premium_getBoostsList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<premium_boostsList>, -2030542532>::parse(p);
#undef FAIL
}

const std::int32_t smsjobs_getStatus::ID;

void smsjobs_getStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(279353576);
}

void smsjobs_getStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(279353576);
}

void smsjobs_getStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.getStatus");
    s.store_class_end();
  }
}

smsjobs_getStatus::ReturnType smsjobs_getStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<smsjobs_status>, 720277905>::parse(p);
#undef FAIL
}

const std::int32_t smsjobs_leave::ID;

void smsjobs_leave::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1734824589);
}

void smsjobs_leave::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1734824589);
}

void smsjobs_leave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.leave");
    s.store_class_end();
  }
}

smsjobs_leave::ReturnType smsjobs_leave::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stickers_addStickerToSet::stickers_addStickerToSet(object_ptr<InputStickerSet> &&stickerset_, object_ptr<inputStickerSetItem> &&sticker_)
  : stickerset_(std::move(stickerset_))
  , sticker_(std::move(sticker_))
{}

const std::int32_t stickers_addStickerToSet::ID;

void stickers_addStickerToSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2041315650);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBoxed<TlStoreObject, 853188252>::store(sticker_, s);
}

void stickers_addStickerToSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2041315650);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBoxed<TlStoreObject, 853188252>::store(sticker_, s);
}

void stickers_addStickerToSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.addStickerToSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

stickers_addStickerToSet::ReturnType stickers_addStickerToSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stickers_removeStickerFromSet::stickers_removeStickerFromSet(object_ptr<InputDocument> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t stickers_removeStickerFromSet::ID;

void stickers_removeStickerFromSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-143257775);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
}

void stickers_removeStickerFromSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-143257775);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
}

void stickers_removeStickerFromSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.removeStickerFromSet");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

stickers_removeStickerFromSet::ReturnType stickers_removeStickerFromSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stories_createAlbum::stories_createAlbum(object_ptr<InputPeer> &&peer_, string const &title_, array<int32> &&stories_)
  : peer_(std::move(peer_))
  , title_(title_)
  , stories_(std::move(stories_))
{}

const std::int32_t stories_createAlbum::ID;

void stories_createAlbum::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1553754395);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(stories_, s);
}

void stories_createAlbum::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1553754395);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(stories_, s);
}

void stories_createAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.createAlbum");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("title", title_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_createAlbum::ReturnType stories_createAlbum::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<storyAlbum>, -1826262950>::parse(p);
#undef FAIL
}

stories_getAlbumStories::stories_getAlbumStories(object_ptr<InputPeer> &&peer_, int32 album_id_, int32 offset_, int32 limit_)
  : peer_(std::move(peer_))
  , album_id_(album_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stories_getAlbumStories::ID;

void stories_getAlbumStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1400869535);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getAlbumStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1400869535);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getAlbumStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getAlbumStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("album_id", album_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_getAlbumStories::ReturnType stories_getAlbumStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_stories>, 1673780490>::parse(p);
#undef FAIL
}

stories_getStoriesByID::stories_getStoriesByID(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t stories_getStoriesByID::ID;

void stories_getStoriesByID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1467271796);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_getStoriesByID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1467271796);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_getStoriesByID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getStoriesByID");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_getStoriesByID::ReturnType stories_getStoriesByID::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_stories>, 1673780490>::parse(p);
#undef FAIL
}

stories_togglePeerStoriesHidden::stories_togglePeerStoriesHidden(object_ptr<InputPeer> &&peer_, bool hidden_)
  : peer_(std::move(peer_))
  , hidden_(hidden_)
{}

const std::int32_t stories_togglePeerStoriesHidden::ID;

void stories_togglePeerStoriesHidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1123805756);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(hidden_, s);
}

void stories_togglePeerStoriesHidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1123805756);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(hidden_, s);
}

void stories_togglePeerStoriesHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.togglePeerStoriesHidden");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("hidden", hidden_);
    s.store_class_end();
  }
}

stories_togglePeerStoriesHidden::ReturnType stories_togglePeerStoriesHidden::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

wallet_enableBackup::wallet_enableBackup(int32 flags_, array<bytes> &&parts_, bytes &&new_public_key_, object_ptr<walletOwnershipProof> &&proof_)
  : flags_(flags_)
  , parts_(std::move(parts_))
  , new_public_key_(std::move(new_public_key_))
  , proof_(std::move(proof_))
{}

const std::int32_t wallet_enableBackup::ID;

void wallet_enableBackup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1157678373);
  TlStoreBinary::store((var0 = flags_ | ((!new_public_key_.empty()) << 1) | ((proof_ != nullptr) << 2)), s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(parts_, s);
  if (var0 & 2) { TlStoreString::store(new_public_key_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1622985485>::store(proof_, s); }
}

void wallet_enableBackup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1157678373);
  TlStoreBinary::store((var0 = flags_ | ((!new_public_key_.empty()) << 1) | ((proof_ != nullptr) << 2)), s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(parts_, s);
  if (var0 & 2) { TlStoreString::store(new_public_key_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1622985485>::store(proof_, s); }
}

void wallet_enableBackup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.enableBackup");
    s.store_field("flags", (var0 = flags_ | ((!new_public_key_.empty()) << 1) | ((proof_ != nullptr) << 2)));
    { s.store_vector_begin("parts", parts_.size()); for (const auto &_value : parts_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    if (var0 & 2) { s.store_bytes_field("new_public_key", new_public_key_); }
    if (var0 & 4) { s.store_object_field("proof", static_cast<const BaseObject *>(proof_.get())); }
    s.store_class_end();
  }
}

wallet_enableBackup::ReturnType wallet_enableBackup::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<WalletState>::parse(p);
#undef FAIL
}

const std::int32_t wallet_getGaslessInfo::ID;

void wallet_getGaslessInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1949167777);
}

void wallet_getGaslessInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1949167777);
}

void wallet_getGaslessInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.getGaslessInfo");
    s.store_class_end();
  }
}

wallet_getGaslessInfo::ReturnType wallet_getGaslessInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t wallet_getProofChallenge::ID;

void wallet_getProofChallenge::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(539354775);
}

void wallet_getProofChallenge::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(539354775);
}

void wallet_getProofChallenge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.getProofChallenge");
    s.store_class_end();
  }
}

wallet_getProofChallenge::ReturnType wallet_getProofChallenge::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_proofChallenge>, -1713105145>::parse(p);
#undef FAIL
}

wallet_tonConnectNextEventId::wallet_tonConnectNextEventId(int64 session_id_)
  : session_id_(session_id_)
{}

const std::int32_t wallet_tonConnectNextEventId::ID;

void wallet_tonConnectNextEventId::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2002612804);
  TlStoreBinary::store(session_id_, s);
}

void wallet_tonConnectNextEventId::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2002612804);
  TlStoreBinary::store(session_id_, s);
}

void wallet_tonConnectNextEventId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectNextEventId");
    s.store_field("session_id", session_id_);
    s.store_class_end();
  }
}

wallet_tonConnectNextEventId::ReturnType wallet_tonConnectNextEventId::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<tonConnectNextEventId>, 1478780131>::parse(p);
#undef FAIL
}

object_ptr<Object> Object::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case accessPointRule::ID:
      return accessPointRule::fetch(p);
    case accountDaysTTL::ID:
      return accountDaysTTL::fetch(p);
    case aiComposeTone::ID:
      return aiComposeTone::fetch(p);
    case aiComposeToneDefault::ID:
      return aiComposeToneDefault::fetch(p);
    case aiComposeToneExample::ID:
      return aiComposeToneExample::fetch(p);
    case attachMenuBot::ID:
      return attachMenuBot::fetch(p);
    case attachMenuBotIcon::ID:
      return attachMenuBotIcon::fetch(p);
    case attachMenuBotIconColor::ID:
      return attachMenuBotIconColor::fetch(p);
    case attachMenuBotsNotModified::ID:
      return attachMenuBotsNotModified::fetch(p);
    case attachMenuBots::ID:
      return attachMenuBots::fetch(p);
    case attachMenuBotsBot::ID:
      return attachMenuBotsBot::fetch(p);
    case attachMenuPeerTypeSameBotPM::ID:
      return attachMenuPeerTypeSameBotPM::fetch(p);
    case attachMenuPeerTypeBotPM::ID:
      return attachMenuPeerTypeBotPM::fetch(p);
    case attachMenuPeerTypePM::ID:
      return attachMenuPeerTypePM::fetch(p);
    case attachMenuPeerTypeChat::ID:
      return attachMenuPeerTypeChat::fetch(p);
    case attachMenuPeerTypeBroadcast::ID:
      return attachMenuPeerTypeBroadcast::fetch(p);
    case auctionBidLevel::ID:
      return auctionBidLevel::fetch(p);
    case authorization::ID:
      return authorization::fetch(p);
    case autoDownloadSettings::ID:
      return autoDownloadSettings::fetch(p);
    case autoSaveException::ID:
      return autoSaveException::fetch(p);
    case autoSaveSettings::ID:
      return autoSaveSettings::fetch(p);
    case availableEffect::ID:
      return availableEffect::fetch(p);
    case availableReaction::ID:
      return availableReaction::fetch(p);
    case bankCardOpenUrl::ID:
      return bankCardOpenUrl::fetch(p);
    case baseThemeClassic::ID:
      return baseThemeClassic::fetch(p);
    case baseThemeDay::ID:
      return baseThemeDay::fetch(p);
    case baseThemeNight::ID:
      return baseThemeNight::fetch(p);
    case baseThemeTinted::ID:
      return baseThemeTinted::fetch(p);
    case baseThemeArctic::ID:
      return baseThemeArctic::fetch(p);
    case birthday::ID:
      return birthday::fetch(p);
    case boost::ID:
      return boost::fetch(p);
    case botAppNotModified::ID:
      return botAppNotModified::fetch(p);
    case botApp::ID:
      return botApp::fetch(p);
    case botAppSettings::ID:
      return botAppSettings::fetch(p);
    case botBusinessConnection::ID:
      return botBusinessConnection::fetch(p);
    case botCommand::ID:
      return botCommand::fetch(p);
    case botInfo::ID:
      return botInfo::fetch(p);
    case botInlineMessageMediaAuto::ID:
      return botInlineMessageMediaAuto::fetch(p);
    case botInlineMessageText::ID:
      return botInlineMessageText::fetch(p);
    case botInlineMessageMediaGeo::ID:
      return botInlineMessageMediaGeo::fetch(p);
    case botInlineMessageMediaVenue::ID:
      return botInlineMessageMediaVenue::fetch(p);
    case botInlineMessageMediaContact::ID:
      return botInlineMessageMediaContact::fetch(p);
    case botInlineMessageMediaInvoice::ID:
      return botInlineMessageMediaInvoice::fetch(p);
    case botInlineMessageMediaWebPage::ID:
      return botInlineMessageMediaWebPage::fetch(p);
    case botInlineMessageRichMessage::ID:
      return botInlineMessageRichMessage::fetch(p);
    case botInlineMessageWidget::ID:
      return botInlineMessageWidget::fetch(p);
    case botInlineResult::ID:
      return botInlineResult::fetch(p);
    case botInlineMediaResult::ID:
      return botInlineMediaResult::fetch(p);
    case botMenuButtonDefault::ID:
      return botMenuButtonDefault::fetch(p);
    case botMenuButtonCommands::ID:
      return botMenuButtonCommands::fetch(p);
    case botMenuButton::ID:
      return botMenuButton::fetch(p);
    case botPreviewMedia::ID:
      return botPreviewMedia::fetch(p);
    case botVerification::ID:
      return botVerification::fetch(p);
    case botVerifierSettings::ID:
      return botVerifierSettings::fetch(p);
    case businessAwayMessage::ID:
      return businessAwayMessage::fetch(p);
    case businessAwayMessageScheduleAlways::ID:
      return businessAwayMessageScheduleAlways::fetch(p);
    case businessAwayMessageScheduleOutsideWorkHours::ID:
      return businessAwayMessageScheduleOutsideWorkHours::fetch(p);
    case businessAwayMessageScheduleCustom::ID:
      return businessAwayMessageScheduleCustom::fetch(p);
    case businessBotRecipients::ID:
      return businessBotRecipients::fetch(p);
    case businessBotRights::ID:
      return businessBotRights::fetch(p);
    case businessChatLink::ID:
      return businessChatLink::fetch(p);
    case businessGreetingMessage::ID:
      return businessGreetingMessage::fetch(p);
    case businessIntro::ID:
      return businessIntro::fetch(p);
    case businessLocation::ID:
      return businessLocation::fetch(p);
    case businessRecipients::ID:
      return businessRecipients::fetch(p);
    case businessWeeklyOpen::ID:
      return businessWeeklyOpen::fetch(p);
    case businessWorkHours::ID:
      return businessWorkHours::fetch(p);
    case buttonTypeDefault::ID:
      return buttonTypeDefault::fetch(p);
    case buttonTypeRequestPhone::ID:
      return buttonTypeRequestPhone::fetch(p);
    case buttonTypeRequestGeoLocation::ID:
      return buttonTypeRequestGeoLocation::fetch(p);
    case buttonTypeRequestPoll::ID:
      return buttonTypeRequestPoll::fetch(p);
    case buttonTypeRequestPeer::ID:
      return buttonTypeRequestPeer::fetch(p);
    case inputButtonTypeRequestPeer::ID:
      return inputButtonTypeRequestPeer::fetch(p);
    case buttonTypeSimpleWebView::ID:
      return buttonTypeSimpleWebView::fetch(p);
    case cdnConfig::ID:
      return cdnConfig::fetch(p);
    case cdnPublicKey::ID:
      return cdnPublicKey::fetch(p);
    case channelAdminLogEvent::ID:
      return channelAdminLogEvent::fetch(p);
    case channelAdminLogEventActionChangeTitle::ID:
      return channelAdminLogEventActionChangeTitle::fetch(p);
    case channelAdminLogEventActionChangeAbout::ID:
      return channelAdminLogEventActionChangeAbout::fetch(p);
    case channelAdminLogEventActionChangeUsername::ID:
      return channelAdminLogEventActionChangeUsername::fetch(p);
    case channelAdminLogEventActionChangePhoto::ID:
      return channelAdminLogEventActionChangePhoto::fetch(p);
    case channelAdminLogEventActionToggleInvites::ID:
      return channelAdminLogEventActionToggleInvites::fetch(p);
    case channelAdminLogEventActionToggleSignatures::ID:
      return channelAdminLogEventActionToggleSignatures::fetch(p);
    case channelAdminLogEventActionUpdatePinned::ID:
      return channelAdminLogEventActionUpdatePinned::fetch(p);
    case channelAdminLogEventActionEditMessage::ID:
      return channelAdminLogEventActionEditMessage::fetch(p);
    case channelAdminLogEventActionDeleteMessage::ID:
      return channelAdminLogEventActionDeleteMessage::fetch(p);
    case channelAdminLogEventActionParticipantJoin::ID:
      return channelAdminLogEventActionParticipantJoin::fetch(p);
    case channelAdminLogEventActionParticipantLeave::ID:
      return channelAdminLogEventActionParticipantLeave::fetch(p);
    case channelAdminLogEventActionParticipantInvite::ID:
      return channelAdminLogEventActionParticipantInvite::fetch(p);
    case channelAdminLogEventActionParticipantToggleBan::ID:
      return channelAdminLogEventActionParticipantToggleBan::fetch(p);
    case channelAdminLogEventActionParticipantToggleAdmin::ID:
      return channelAdminLogEventActionParticipantToggleAdmin::fetch(p);
    case channelAdminLogEventActionChangeStickerSet::ID:
      return channelAdminLogEventActionChangeStickerSet::fetch(p);
    case channelAdminLogEventActionTogglePreHistoryHidden::ID:
      return channelAdminLogEventActionTogglePreHistoryHidden::fetch(p);
    case channelAdminLogEventActionDefaultBannedRights::ID:
      return channelAdminLogEventActionDefaultBannedRights::fetch(p);
    case channelAdminLogEventActionStopPoll::ID:
      return channelAdminLogEventActionStopPoll::fetch(p);
    case channelAdminLogEventActionChangeLinkedChat::ID:
      return channelAdminLogEventActionChangeLinkedChat::fetch(p);
    case channelAdminLogEventActionChangeLocation::ID:
      return channelAdminLogEventActionChangeLocation::fetch(p);
    case channelAdminLogEventActionToggleSlowMode::ID:
      return channelAdminLogEventActionToggleSlowMode::fetch(p);
    case channelAdminLogEventActionStartGroupCall::ID:
      return channelAdminLogEventActionStartGroupCall::fetch(p);
    case channelAdminLogEventActionDiscardGroupCall::ID:
      return channelAdminLogEventActionDiscardGroupCall::fetch(p);
    case channelAdminLogEventActionParticipantMute::ID:
      return channelAdminLogEventActionParticipantMute::fetch(p);
    case channelAdminLogEventActionParticipantUnmute::ID:
      return channelAdminLogEventActionParticipantUnmute::fetch(p);
    case channelAdminLogEventActionToggleGroupCallSetting::ID:
      return channelAdminLogEventActionToggleGroupCallSetting::fetch(p);
    case channelAdminLogEventActionParticipantJoinByInvite::ID:
      return channelAdminLogEventActionParticipantJoinByInvite::fetch(p);
    case channelAdminLogEventActionExportedInviteDelete::ID:
      return channelAdminLogEventActionExportedInviteDelete::fetch(p);
    case channelAdminLogEventActionExportedInviteRevoke::ID:
      return channelAdminLogEventActionExportedInviteRevoke::fetch(p);
    case channelAdminLogEventActionExportedInviteEdit::ID:
      return channelAdminLogEventActionExportedInviteEdit::fetch(p);
    case channelAdminLogEventActionParticipantVolume::ID:
      return channelAdminLogEventActionParticipantVolume::fetch(p);
    case channelAdminLogEventActionChangeHistoryTTL::ID:
      return channelAdminLogEventActionChangeHistoryTTL::fetch(p);
    case channelAdminLogEventActionParticipantJoinByRequest::ID:
      return channelAdminLogEventActionParticipantJoinByRequest::fetch(p);
    case channelAdminLogEventActionToggleNoForwards::ID:
      return channelAdminLogEventActionToggleNoForwards::fetch(p);
    case channelAdminLogEventActionSendMessage::ID:
      return channelAdminLogEventActionSendMessage::fetch(p);
    case channelAdminLogEventActionChangeAvailableReactions::ID:
      return channelAdminLogEventActionChangeAvailableReactions::fetch(p);
    case channelAdminLogEventActionChangeUsernames::ID:
      return channelAdminLogEventActionChangeUsernames::fetch(p);
    case channelAdminLogEventActionToggleForum::ID:
      return channelAdminLogEventActionToggleForum::fetch(p);
    case channelAdminLogEventActionCreateTopic::ID:
      return channelAdminLogEventActionCreateTopic::fetch(p);
    case channelAdminLogEventActionEditTopic::ID:
      return channelAdminLogEventActionEditTopic::fetch(p);
    case channelAdminLogEventActionDeleteTopic::ID:
      return channelAdminLogEventActionDeleteTopic::fetch(p);
    case channelAdminLogEventActionPinTopic::ID:
      return channelAdminLogEventActionPinTopic::fetch(p);
    case channelAdminLogEventActionToggleAntiSpam::ID:
      return channelAdminLogEventActionToggleAntiSpam::fetch(p);
    case channelAdminLogEventActionChangePeerColor::ID:
      return channelAdminLogEventActionChangePeerColor::fetch(p);
    case channelAdminLogEventActionChangeProfilePeerColor::ID:
      return channelAdminLogEventActionChangeProfilePeerColor::fetch(p);
    case channelAdminLogEventActionChangeWallpaper::ID:
      return channelAdminLogEventActionChangeWallpaper::fetch(p);
    case channelAdminLogEventActionChangeEmojiStatus::ID:
      return channelAdminLogEventActionChangeEmojiStatus::fetch(p);
    case channelAdminLogEventActionChangeEmojiStickerSet::ID:
      return channelAdminLogEventActionChangeEmojiStickerSet::fetch(p);
    case channelAdminLogEventActionToggleSignatureProfiles::ID:
      return channelAdminLogEventActionToggleSignatureProfiles::fetch(p);
    case channelAdminLogEventActionParticipantSubExtend::ID:
      return channelAdminLogEventActionParticipantSubExtend::fetch(p);
    case channelAdminLogEventActionToggleAutotranslation::ID:
      return channelAdminLogEventActionToggleAutotranslation::fetch(p);
    case channelAdminLogEventActionParticipantEditRank::ID:
      return channelAdminLogEventActionParticipantEditRank::fetch(p);
    case channelLocationEmpty::ID:
      return channelLocationEmpty::fetch(p);
    case channelLocation::ID:
      return channelLocation::fetch(p);
    case channelParticipant::ID:
      return channelParticipant::fetch(p);
    case channelParticipantSelf::ID:
      return channelParticipantSelf::fetch(p);
    case channelParticipantCreator::ID:
      return channelParticipantCreator::fetch(p);
    case channelParticipantAdmin::ID:
      return channelParticipantAdmin::fetch(p);
    case channelParticipantBanned::ID:
      return channelParticipantBanned::fetch(p);
    case channelParticipantLeft::ID:
      return channelParticipantLeft::fetch(p);
    case chatEmpty::ID:
      return chatEmpty::fetch(p);
    case chat::ID:
      return chat::fetch(p);
    case chatForbidden::ID:
      return chatForbidden::fetch(p);
    case channel::ID:
      return channel::fetch(p);
    case channelForbidden::ID:
      return channelForbidden::fetch(p);
    case communityForbidden::ID:
      return communityForbidden::fetch(p);
    case community::ID:
      return community::fetch(p);
    case chatAdminRights::ID:
      return chatAdminRights::fetch(p);
    case chatAdminWithInvites::ID:
      return chatAdminWithInvites::fetch(p);
    case chatBannedRights::ID:
      return chatBannedRights::fetch(p);
    case chatFull::ID:
      return chatFull::fetch(p);
    case channelFull::ID:
      return channelFull::fetch(p);
    case communityFull::ID:
      return communityFull::fetch(p);
    case chatInviteAlready::ID:
      return chatInviteAlready::fetch(p);
    case chatInvite::ID:
      return chatInvite::fetch(p);
    case chatInvitePeek::ID:
      return chatInvitePeek::fetch(p);
    case chatInviteImporter::ID:
      return chatInviteImporter::fetch(p);
    case chatOnlines::ID:
      return chatOnlines::fetch(p);
    case chatParticipant::ID:
      return chatParticipant::fetch(p);
    case chatParticipantCreator::ID:
      return chatParticipantCreator::fetch(p);
    case chatParticipantAdmin::ID:
      return chatParticipantAdmin::fetch(p);
    case chatParticipantsForbidden::ID:
      return chatParticipantsForbidden::fetch(p);
    case chatParticipants::ID:
      return chatParticipants::fetch(p);
    case chatPhotoEmpty::ID:
      return chatPhotoEmpty::fetch(p);
    case chatPhoto::ID:
      return chatPhoto::fetch(p);
    case chatReactionsNone::ID:
      return chatReactionsNone::fetch(p);
    case chatReactionsAll::ID:
      return chatReactionsAll::fetch(p);
    case chatReactionsSome::ID:
      return chatReactionsSome::fetch(p);
    case chatTheme::ID:
      return chatTheme::fetch(p);
    case chatThemeUniqueGift::ID:
      return chatThemeUniqueGift::fetch(p);
    case communityPeer::ID:
      return communityPeer::fetch(p);
    case communityPeerRequest::ID:
      return communityPeerRequest::fetch(p);
    case config::ID:
      return config::fetch(p);
    case connectedBot::ID:
      return connectedBot::fetch(p);
    case connectedBotStarRef::ID:
      return connectedBotStarRef::fetch(p);
    case contact::ID:
      return contact::fetch(p);
    case contactBirthday::ID:
      return contactBirthday::fetch(p);
    case contactStatus::ID:
      return contactStatus::fetch(p);
    case currencyRate::ID:
      return currencyRate::fetch(p);
    case dataJSON::ID:
      return dataJSON::fetch(p);
    case dcOption::ID:
      return dcOption::fetch(p);
    case defaultHistoryTTL::ID:
      return defaultHistoryTTL::fetch(p);
    case dialog::ID:
      return dialog::fetch(p);
    case dialogFolder::ID:
      return dialogFolder::fetch(p);
    case dialogCommunity::ID:
      return dialogCommunity::fetch(p);
    case dialogFilter::ID:
      return dialogFilter::fetch(p);
    case dialogFilterDefault::ID:
      return dialogFilterDefault::fetch(p);
    case dialogFilterChatlist::ID:
      return dialogFilterChatlist::fetch(p);
    case dialogFilterSuggested::ID:
      return dialogFilterSuggested::fetch(p);
    case dialogPeer::ID:
      return dialogPeer::fetch(p);
    case dialogPeerFolder::ID:
      return dialogPeerFolder::fetch(p);
    case dialogPeerCommunity::ID:
      return dialogPeerCommunity::fetch(p);
    case disallowedGiftsSettings::ID:
      return disallowedGiftsSettings::fetch(p);
    case documentEmpty::ID:
      return documentEmpty::fetch(p);
    case document::ID:
      return document::fetch(p);
    case documentAttributeImageSize::ID:
      return documentAttributeImageSize::fetch(p);
    case documentAttributeAnimated::ID:
      return documentAttributeAnimated::fetch(p);
    case documentAttributeSticker::ID:
      return documentAttributeSticker::fetch(p);
    case documentAttributeVideo::ID:
      return documentAttributeVideo::fetch(p);
    case documentAttributeAudio::ID:
      return documentAttributeAudio::fetch(p);
    case documentAttributeFilename::ID:
      return documentAttributeFilename::fetch(p);
    case documentAttributeHasStickers::ID:
      return documentAttributeHasStickers::fetch(p);
    case documentAttributeCustomEmoji::ID:
      return documentAttributeCustomEmoji::fetch(p);
    case draftMessageEmpty::ID:
      return draftMessageEmpty::fetch(p);
    case draftMessage::ID:
      return draftMessage::fetch(p);
    case emojiGroup::ID:
      return emojiGroup::fetch(p);
    case emojiGroupGreeting::ID:
      return emojiGroupGreeting::fetch(p);
    case emojiGroupPremium::ID:
      return emojiGroupPremium::fetch(p);
    case emojiKeyword::ID:
      return emojiKeyword::fetch(p);
    case emojiKeywordDeleted::ID:
      return emojiKeywordDeleted::fetch(p);
    case emojiKeywordsDifference::ID:
      return emojiKeywordsDifference::fetch(p);
    case emojiLanguage::ID:
      return emojiLanguage::fetch(p);
    case emojiListNotModified::ID:
      return emojiListNotModified::fetch(p);
    case emojiList::ID:
      return emojiList::fetch(p);
    case emojiStatusEmpty::ID:
      return emojiStatusEmpty::fetch(p);
    case emojiStatus::ID:
      return emojiStatus::fetch(p);
    case emojiStatusCollectible::ID:
      return emojiStatusCollectible::fetch(p);
    case inputEmojiStatusCollectible::ID:
      return inputEmojiStatusCollectible::fetch(p);
    case emojiURL::ID:
      return emojiURL::fetch(p);
    case encryptedChatEmpty::ID:
      return encryptedChatEmpty::fetch(p);
    case encryptedChatWaiting::ID:
      return encryptedChatWaiting::fetch(p);
    case encryptedChatRequested::ID:
      return encryptedChatRequested::fetch(p);
    case encryptedChat::ID:
      return encryptedChat::fetch(p);
    case encryptedChatDiscarded::ID:
      return encryptedChatDiscarded::fetch(p);
    case encryptedFileEmpty::ID:
      return encryptedFileEmpty::fetch(p);
    case encryptedFile::ID:
      return encryptedFile::fetch(p);
    case encryptedMessage::ID:
      return encryptedMessage::fetch(p);
    case encryptedMessageService::ID:
      return encryptedMessageService::fetch(p);
    case ephemeralMessage::ID:
      return ephemeralMessage::fetch(p);
    case error::ID:
      return error::fetch(p);
    case chatInviteExported::ID:
      return chatInviteExported::fetch(p);
    case chatInvitePublicJoinRequests::ID:
      return chatInvitePublicJoinRequests::fetch(p);
    case exportedChatlistInvite::ID:
      return exportedChatlistInvite::fetch(p);
    case exportedContactToken::ID:
      return exportedContactToken::fetch(p);
    case exportedMessageLink::ID:
      return exportedMessageLink::fetch(p);
    case exportedNoPaidMessagesToken::ID:
      return exportedNoPaidMessagesToken::fetch(p);
    case exportedStoryLink::ID:
      return exportedStoryLink::fetch(p);
    case factCheck::ID:
      return factCheck::fetch(p);
    case fileHash::ID:
      return fileHash::fetch(p);
    case folder::ID:
      return folder::fetch(p);
    case folderPeer::ID:
      return folderPeer::fetch(p);
    case forumTopicDeleted::ID:
      return forumTopicDeleted::fetch(p);
    case forumTopic::ID:
      return forumTopic::fetch(p);
    case foundStory::ID:
      return foundStory::fetch(p);
    case game::ID:
      return game::fetch(p);
    case geoPointEmpty::ID:
      return geoPointEmpty::fetch(p);
    case geoPoint::ID:
      return geoPoint::fetch(p);
    case geoPointAddress::ID:
      return geoPointAddress::fetch(p);
    case globalPrivacySettings::ID:
      return globalPrivacySettings::fetch(p);
    case groupCallDiscarded::ID:
      return groupCallDiscarded::fetch(p);
    case groupCall::ID:
      return groupCall::fetch(p);
    case groupCallDonor::ID:
      return groupCallDonor::fetch(p);
    case groupCallMessage::ID:
      return groupCallMessage::fetch(p);
    case groupCallParticipant::ID:
      return groupCallParticipant::fetch(p);
    case groupCallParticipantVideo::ID:
      return groupCallParticipantVideo::fetch(p);
    case groupCallParticipantVideoSourceGroup::ID:
      return groupCallParticipantVideoSourceGroup::fetch(p);
    case groupCallStreamChannel::ID:
      return groupCallStreamChannel::fetch(p);
    case highScore::ID:
      return highScore::fetch(p);
    case importedContact::ID:
      return importedContact::fetch(p);
    case inlineBotSwitchPM::ID:
      return inlineBotSwitchPM::fetch(p);
    case inlineBotWebView::ID:
      return inlineBotWebView::fetch(p);
    case inlineButtonTypeUrl::ID:
      return inlineButtonTypeUrl::fetch(p);
    case inlineButtonTypeUrlAuth::ID:
      return inlineButtonTypeUrlAuth::fetch(p);
    case inputInlineButtonTypeUrlAuth::ID:
      return inputInlineButtonTypeUrlAuth::fetch(p);
    case inlineButtonTypeWebView::ID:
      return inlineButtonTypeWebView::fetch(p);
    case inlineButtonTypeCallback::ID:
      return inlineButtonTypeCallback::fetch(p);
    case inlineButtonTypeGame::ID:
      return inlineButtonTypeGame::fetch(p);
    case inlineButtonTypeBuy::ID:
      return inlineButtonTypeBuy::fetch(p);
    case inlineButtonTypeSwitchInline::ID:
      return inlineButtonTypeSwitchInline::fetch(p);
    case inlineButtonTypeUserProfile::ID:
      return inlineButtonTypeUserProfile::fetch(p);
    case inputInlineButtonTypeUserProfile::ID:
      return inputInlineButtonTypeUserProfile::fetch(p);
    case inlineButtonTypeCopy::ID:
      return inlineButtonTypeCopy::fetch(p);
    case inlineButtonTypeDisabled::ID:
      return inlineButtonTypeDisabled::fetch(p);
    case inlineQueryPeerTypeSameBotPM::ID:
      return inlineQueryPeerTypeSameBotPM::fetch(p);
    case inlineQueryPeerTypePM::ID:
      return inlineQueryPeerTypePM::fetch(p);
    case inlineQueryPeerTypeChat::ID:
      return inlineQueryPeerTypeChat::fetch(p);
    case inlineQueryPeerTypeMegagroup::ID:
      return inlineQueryPeerTypeMegagroup::fetch(p);
    case inlineQueryPeerTypeBroadcast::ID:
      return inlineQueryPeerTypeBroadcast::fetch(p);
    case inlineQueryPeerTypeBotPM::ID:
      return inlineQueryPeerTypeBotPM::fetch(p);
    case inputAiComposeStyle::ID:
      return inputAiComposeStyle::fetch(p);
    case inputAiComposeToneDefault::ID:
      return inputAiComposeToneDefault::fetch(p);
    case inputAiComposeToneID::ID:
      return inputAiComposeToneID::fetch(p);
    case inputAiComposeToneSlug::ID:
      return inputAiComposeToneSlug::fetch(p);
    case inputAiComposeToneSingleUse::ID:
      return inputAiComposeToneSingleUse::fetch(p);
    case inputAppEvent::ID:
      return inputAppEvent::fetch(p);
    case inputBotInlineMessageID::ID:
      return inputBotInlineMessageID::fetch(p);
    case inputBotInlineMessageID64::ID:
      return inputBotInlineMessageID64::fetch(p);
    case inputChannelEmpty::ID:
      return inputChannelEmpty::fetch(p);
    case inputChannel::ID:
      return inputChannel::fetch(p);
    case inputChannelFromMessage::ID:
      return inputChannelFromMessage::fetch(p);
    case inputDocumentEmpty::ID:
      return inputDocumentEmpty::fetch(p);
    case inputDocument::ID:
      return inputDocument::fetch(p);
    case inputFile::ID:
      return inputFile::fetch(p);
    case inputFileBig::ID:
      return inputFileBig::fetch(p);
    case inputFileStoryDocument::ID:
      return inputFileStoryDocument::fetch(p);
    case inputGameID::ID:
      return inputGameID::fetch(p);
    case inputGameShortName::ID:
      return inputGameShortName::fetch(p);
    case inputGeoPointEmpty::ID:
      return inputGeoPointEmpty::fetch(p);
    case inputGeoPoint::ID:
      return inputGeoPoint::fetch(p);
    case inputGroupCall::ID:
      return inputGroupCall::fetch(p);
    case inputGroupCallSlug::ID:
      return inputGroupCallSlug::fetch(p);
    case inputGroupCallInviteMessage::ID:
      return inputGroupCallInviteMessage::fetch(p);
    case inputMediaEmpty::ID:
      return inputMediaEmpty::fetch(p);
    case inputMediaUploadedPhoto::ID:
      return inputMediaUploadedPhoto::fetch(p);
    case inputMediaPhoto::ID:
      return inputMediaPhoto::fetch(p);
    case inputMediaGeoPoint::ID:
      return inputMediaGeoPoint::fetch(p);
    case inputMediaContact::ID:
      return inputMediaContact::fetch(p);
    case inputMediaUploadedDocument::ID:
      return inputMediaUploadedDocument::fetch(p);
    case inputMediaDocument::ID:
      return inputMediaDocument::fetch(p);
    case inputMediaVenue::ID:
      return inputMediaVenue::fetch(p);
    case inputMediaPhotoExternal::ID:
      return inputMediaPhotoExternal::fetch(p);
    case inputMediaDocumentExternal::ID:
      return inputMediaDocumentExternal::fetch(p);
    case inputMediaGame::ID:
      return inputMediaGame::fetch(p);
    case inputMediaInvoice::ID:
      return inputMediaInvoice::fetch(p);
    case inputMediaGeoLive::ID:
      return inputMediaGeoLive::fetch(p);
    case inputMediaPoll::ID:
      return inputMediaPoll::fetch(p);
    case inputMediaDice::ID:
      return inputMediaDice::fetch(p);
    case inputMediaStory::ID:
      return inputMediaStory::fetch(p);
    case inputMediaWebPage::ID:
      return inputMediaWebPage::fetch(p);
    case inputMediaPaidMedia::ID:
      return inputMediaPaidMedia::fetch(p);
    case inputMediaTodo::ID:
      return inputMediaTodo::fetch(p);
    case inputMediaStakeDice::ID:
      return inputMediaStakeDice::fetch(p);
    case inputMediaWidget::ID:
      return inputMediaWidget::fetch(p);
    case inputMediaWidgetId::ID:
      return inputMediaWidgetId::fetch(p);
    case inputPeerEmpty::ID:
      return inputPeerEmpty::fetch(p);
    case inputPeerSelf::ID:
      return inputPeerSelf::fetch(p);
    case inputPeerChat::ID:
      return inputPeerChat::fetch(p);
    case inputPeerUser::ID:
      return inputPeerUser::fetch(p);
    case inputPeerChannel::ID:
      return inputPeerChannel::fetch(p);
    case inputPeerUserFromMessage::ID:
      return inputPeerUserFromMessage::fetch(p);
    case inputPeerChannelFromMessage::ID:
      return inputPeerChannelFromMessage::fetch(p);
    case inputPhotoEmpty::ID:
      return inputPhotoEmpty::fetch(p);
    case inputPhoto::ID:
      return inputPhoto::fetch(p);
    case inputReplyToMessage::ID:
      return inputReplyToMessage::fetch(p);
    case inputReplyToStory::ID:
      return inputReplyToStory::fetch(p);
    case inputReplyToMonoForum::ID:
      return inputReplyToMonoForum::fetch(p);
    case inputReplyToEphemeralMessage::ID:
      return inputReplyToEphemeralMessage::fetch(p);
    case inputRichFilePhoto::ID:
      return inputRichFilePhoto::fetch(p);
    case inputRichFileDocument::ID:
      return inputRichFileDocument::fetch(p);
    case inputRichMessage::ID:
      return inputRichMessage::fetch(p);
    case inputRichMessageHTML::ID:
      return inputRichMessageHTML::fetch(p);
    case inputRichMessageMarkdown::ID:
      return inputRichMessageMarkdown::fetch(p);
    case inputSavedStarGiftUser::ID:
      return inputSavedStarGiftUser::fetch(p);
    case inputSavedStarGiftChat::ID:
      return inputSavedStarGiftChat::fetch(p);
    case inputSavedStarGiftSlug::ID:
      return inputSavedStarGiftSlug::fetch(p);
    case inputStickerSetEmpty::ID:
      return inputStickerSetEmpty::fetch(p);
    case inputStickerSetID::ID:
      return inputStickerSetID::fetch(p);
    case inputStickerSetShortName::ID:
      return inputStickerSetShortName::fetch(p);
    case inputStickerSetAnimatedEmoji::ID:
      return inputStickerSetAnimatedEmoji::fetch(p);
    case inputStickerSetDice::ID:
      return inputStickerSetDice::fetch(p);
    case inputStickerSetAnimatedEmojiAnimations::ID:
      return inputStickerSetAnimatedEmojiAnimations::fetch(p);
    case inputStickerSetPremiumGifts::ID:
      return inputStickerSetPremiumGifts::fetch(p);
    case inputStickerSetEmojiGenericAnimations::ID:
      return inputStickerSetEmojiGenericAnimations::fetch(p);
    case inputStickerSetEmojiDefaultStatuses::ID:
      return inputStickerSetEmojiDefaultStatuses::fetch(p);
    case inputStickerSetEmojiDefaultTopicIcons::ID:
      return inputStickerSetEmojiDefaultTopicIcons::fetch(p);
    case inputStickerSetEmojiChannelDefaultStatuses::ID:
      return inputStickerSetEmojiChannelDefaultStatuses::fetch(p);
    case inputStickerSetTonGifts::ID:
      return inputStickerSetTonGifts::fetch(p);
    case inputUserEmpty::ID:
      return inputUserEmpty::fetch(p);
    case inputUserSelf::ID:
      return inputUserSelf::fetch(p);
    case inputUser::ID:
      return inputUser::fetch(p);
    case inputUserFromMessage::ID:
      return inputUserFromMessage::fetch(p);
    case inputWebDocument::ID:
      return inputWebDocument::fetch(p);
    case invoice::ID:
      return invoice::fetch(p);
    case ipPort::ID:
      return ipPort::fetch(p);
    case ipPortSecret::ID:
      return ipPortSecret::fetch(p);
    case jsonObjectValue::ID:
      return jsonObjectValue::fetch(p);
    case jsonNull::ID:
      return jsonNull::fetch(p);
    case jsonBool::ID:
      return jsonBool::fetch(p);
    case jsonNumber::ID:
      return jsonNumber::fetch(p);
    case jsonString::ID:
      return jsonString::fetch(p);
    case jsonArray::ID:
      return jsonArray::fetch(p);
    case jsonObject::ID:
      return jsonObject::fetch(p);
    case joinChatBotResultApproved::ID:
      return joinChatBotResultApproved::fetch(p);
    case joinChatBotResultDeclined::ID:
      return joinChatBotResultDeclined::fetch(p);
    case joinChatBotResultQueued::ID:
      return joinChatBotResultQueued::fetch(p);
    case joinChatBotResultWebView::ID:
      return joinChatBotResultWebView::fetch(p);
    case keyboardButton::ID:
      return keyboardButton::fetch(p);
    case keyboardButtonRow::ID:
      return keyboardButtonRow::fetch(p);
    case keyboardButtonStyle::ID:
      return keyboardButtonStyle::fetch(p);
    case keyboardInlineButton::ID:
      return keyboardInlineButton::fetch(p);
    case keyboardInlineButtonRow::ID:
      return keyboardInlineButtonRow::fetch(p);
    case labeledPrice::ID:
      return labeledPrice::fetch(p);
    case langPackDifference::ID:
      return langPackDifference::fetch(p);
    case langPackLanguage::ID:
      return langPackLanguage::fetch(p);
    case langPackString::ID:
      return langPackString::fetch(p);
    case langPackStringPluralized::ID:
      return langPackStringPluralized::fetch(p);
    case langPackStringDeleted::ID:
      return langPackStringDeleted::fetch(p);
    case maskCoords::ID:
      return maskCoords::fetch(p);
    case mediaAreaVenue::ID:
      return mediaAreaVenue::fetch(p);
    case inputMediaAreaVenue::ID:
      return inputMediaAreaVenue::fetch(p);
    case mediaAreaGeoPoint::ID:
      return mediaAreaGeoPoint::fetch(p);
    case mediaAreaSuggestedReaction::ID:
      return mediaAreaSuggestedReaction::fetch(p);
    case mediaAreaChannelPost::ID:
      return mediaAreaChannelPost::fetch(p);
    case inputMediaAreaChannelPost::ID:
      return inputMediaAreaChannelPost::fetch(p);
    case mediaAreaUrl::ID:
      return mediaAreaUrl::fetch(p);
    case mediaAreaWeather::ID:
      return mediaAreaWeather::fetch(p);
    case mediaAreaStarGift::ID:
      return mediaAreaStarGift::fetch(p);
    case mediaAreaCoordinates::ID:
      return mediaAreaCoordinates::fetch(p);
    case messageEmpty::ID:
      return messageEmpty::fetch(p);
    case message::ID:
      return message::fetch(p);
    case messageService::ID:
      return messageService::fetch(p);
    case messageActionEmpty::ID:
      return messageActionEmpty::fetch(p);
    case messageActionChatCreate::ID:
      return messageActionChatCreate::fetch(p);
    case messageActionChatEditTitle::ID:
      return messageActionChatEditTitle::fetch(p);
    case messageActionChatEditPhoto::ID:
      return messageActionChatEditPhoto::fetch(p);
    case messageActionChatDeletePhoto::ID:
      return messageActionChatDeletePhoto::fetch(p);
    case messageActionChatAddUser::ID:
      return messageActionChatAddUser::fetch(p);
    case messageActionChatDeleteUser::ID:
      return messageActionChatDeleteUser::fetch(p);
    case messageActionChatJoinedByLink::ID:
      return messageActionChatJoinedByLink::fetch(p);
    case messageActionChannelCreate::ID:
      return messageActionChannelCreate::fetch(p);
    case messageActionChatMigrateTo::ID:
      return messageActionChatMigrateTo::fetch(p);
    case messageActionChannelMigrateFrom::ID:
      return messageActionChannelMigrateFrom::fetch(p);
    case messageActionPinMessage::ID:
      return messageActionPinMessage::fetch(p);
    case messageActionHistoryClear::ID:
      return messageActionHistoryClear::fetch(p);
    case messageActionGameScore::ID:
      return messageActionGameScore::fetch(p);
    case messageActionPaymentSentMe::ID:
      return messageActionPaymentSentMe::fetch(p);
    case messageActionPaymentSent::ID:
      return messageActionPaymentSent::fetch(p);
    case messageActionPhoneCall::ID:
      return messageActionPhoneCall::fetch(p);
    case messageActionScreenshotTaken::ID:
      return messageActionScreenshotTaken::fetch(p);
    case messageActionCustomAction::ID:
      return messageActionCustomAction::fetch(p);
    case messageActionBotAllowed::ID:
      return messageActionBotAllowed::fetch(p);
    case messageActionSecureValuesSentMe::ID:
      return messageActionSecureValuesSentMe::fetch(p);
    case messageActionSecureValuesSent::ID:
      return messageActionSecureValuesSent::fetch(p);
    case messageActionContactSignUp::ID:
      return messageActionContactSignUp::fetch(p);
    case messageActionGeoProximityReached::ID:
      return messageActionGeoProximityReached::fetch(p);
    case messageActionGroupCall::ID:
      return messageActionGroupCall::fetch(p);
    case messageActionInviteToGroupCall::ID:
      return messageActionInviteToGroupCall::fetch(p);
    case messageActionSetMessagesTTL::ID:
      return messageActionSetMessagesTTL::fetch(p);
    case messageActionGroupCallScheduled::ID:
      return messageActionGroupCallScheduled::fetch(p);
    case messageActionSetChatTheme::ID:
      return messageActionSetChatTheme::fetch(p);
    case messageActionChatJoinedByRequest::ID:
      return messageActionChatJoinedByRequest::fetch(p);
    case messageActionWebViewDataSentMe::ID:
      return messageActionWebViewDataSentMe::fetch(p);
    case messageActionWebViewDataSent::ID:
      return messageActionWebViewDataSent::fetch(p);
    case messageActionGiftPremium::ID:
      return messageActionGiftPremium::fetch(p);
    case messageActionTopicCreate::ID:
      return messageActionTopicCreate::fetch(p);
    case messageActionTopicEdit::ID:
      return messageActionTopicEdit::fetch(p);
    case messageActionSuggestProfilePhoto::ID:
      return messageActionSuggestProfilePhoto::fetch(p);
    case messageActionRequestedPeer::ID:
      return messageActionRequestedPeer::fetch(p);
    case messageActionSetChatWallPaper::ID:
      return messageActionSetChatWallPaper::fetch(p);
    case messageActionGiftCode::ID:
      return messageActionGiftCode::fetch(p);
    case messageActionGiveawayLaunch::ID:
      return messageActionGiveawayLaunch::fetch(p);
    case messageActionGiveawayResults::ID:
      return messageActionGiveawayResults::fetch(p);
    case messageActionBoostApply::ID:
      return messageActionBoostApply::fetch(p);
    case messageActionRequestedPeerSentMe::ID:
      return messageActionRequestedPeerSentMe::fetch(p);
    case messageActionPaymentRefunded::ID:
      return messageActionPaymentRefunded::fetch(p);
    case messageActionGiftStars::ID:
      return messageActionGiftStars::fetch(p);
    case messageActionPrizeStars::ID:
      return messageActionPrizeStars::fetch(p);
    case messageActionStarGift::ID:
      return messageActionStarGift::fetch(p);
    case messageActionStarGiftUnique::ID:
      return messageActionStarGiftUnique::fetch(p);
    case messageActionPaidMessagesRefunded::ID:
      return messageActionPaidMessagesRefunded::fetch(p);
    case messageActionPaidMessagesPrice::ID:
      return messageActionPaidMessagesPrice::fetch(p);
    case messageActionConferenceCall::ID:
      return messageActionConferenceCall::fetch(p);
    case messageActionTodoCompletions::ID:
      return messageActionTodoCompletions::fetch(p);
    case messageActionTodoAppendTasks::ID:
      return messageActionTodoAppendTasks::fetch(p);
    case messageActionSuggestedPostApproval::ID:
      return messageActionSuggestedPostApproval::fetch(p);
    case messageActionSuggestedPostSuccess::ID:
      return messageActionSuggestedPostSuccess::fetch(p);
    case messageActionSuggestedPostRefund::ID:
      return messageActionSuggestedPostRefund::fetch(p);
    case messageActionGiftTon::ID:
      return messageActionGiftTon::fetch(p);
    case messageActionSuggestBirthday::ID:
      return messageActionSuggestBirthday::fetch(p);
    case messageActionStarGiftPurchaseOffer::ID:
      return messageActionStarGiftPurchaseOffer::fetch(p);
    case messageActionStarGiftPurchaseOfferDeclined::ID:
      return messageActionStarGiftPurchaseOfferDeclined::fetch(p);
    case messageActionNewCreatorPending::ID:
      return messageActionNewCreatorPending::fetch(p);
    case messageActionChangeCreator::ID:
      return messageActionChangeCreator::fetch(p);
    case messageActionNoForwardsToggle::ID:
      return messageActionNoForwardsToggle::fetch(p);
    case messageActionNoForwardsRequest::ID:
      return messageActionNoForwardsRequest::fetch(p);
    case messageActionPollAppendAnswer::ID:
      return messageActionPollAppendAnswer::fetch(p);
    case messageActionPollDeleteAnswer::ID:
      return messageActionPollDeleteAnswer::fetch(p);
    case messageActionManagedBotCreated::ID:
      return messageActionManagedBotCreated::fetch(p);
    case messageActionChangeCommunity::ID:
      return messageActionChangeCommunity::fetch(p);
    case messageActionChatJoinedViaCommunity::ID:
      return messageActionChatJoinedViaCommunity::fetch(p);
    case messageActionGramTransfer::ID:
      return messageActionGramTransfer::fetch(p);
    case messageActionWalletTonConnectRequest::ID:
      return messageActionWalletTonConnectRequest::fetch(p);
    case messageActionNoPaidMessagesTokenUsed::ID:
      return messageActionNoPaidMessagesTokenUsed::fetch(p);
    case messageActionStarGiftOnchainOffer::ID:
      return messageActionStarGiftOnchainOffer::fetch(p);
    case messageActionBotInvite::ID:
      return messageActionBotInvite::fetch(p);
    case messageEntityUnknown::ID:
      return messageEntityUnknown::fetch(p);
    case messageEntityMention::ID:
      return messageEntityMention::fetch(p);
    case messageEntityHashtag::ID:
      return messageEntityHashtag::fetch(p);
    case messageEntityBotCommand::ID:
      return messageEntityBotCommand::fetch(p);
    case messageEntityUrl::ID:
      return messageEntityUrl::fetch(p);
    case messageEntityEmail::ID:
      return messageEntityEmail::fetch(p);
    case messageEntityBold::ID:
      return messageEntityBold::fetch(p);
    case messageEntityItalic::ID:
      return messageEntityItalic::fetch(p);
    case messageEntityCode::ID:
      return messageEntityCode::fetch(p);
    case messageEntityPre::ID:
      return messageEntityPre::fetch(p);
    case messageEntityTextUrl::ID:
      return messageEntityTextUrl::fetch(p);
    case messageEntityMentionName::ID:
      return messageEntityMentionName::fetch(p);
    case inputMessageEntityMentionName::ID:
      return inputMessageEntityMentionName::fetch(p);
    case messageEntityPhone::ID:
      return messageEntityPhone::fetch(p);
    case messageEntityCashtag::ID:
      return messageEntityCashtag::fetch(p);
    case messageEntityUnderline::ID:
      return messageEntityUnderline::fetch(p);
    case messageEntityStrike::ID:
      return messageEntityStrike::fetch(p);
    case messageEntityBankCard::ID:
      return messageEntityBankCard::fetch(p);
    case messageEntitySpoiler::ID:
      return messageEntitySpoiler::fetch(p);
    case messageEntityCustomEmoji::ID:
      return messageEntityCustomEmoji::fetch(p);
    case messageEntityBlockquote::ID:
      return messageEntityBlockquote::fetch(p);
    case messageEntityFormattedDate::ID:
      return messageEntityFormattedDate::fetch(p);
    case messageEntityDiffInsert::ID:
      return messageEntityDiffInsert::fetch(p);
    case messageEntityDiffReplace::ID:
      return messageEntityDiffReplace::fetch(p);
    case messageEntityDiffDelete::ID:
      return messageEntityDiffDelete::fetch(p);
    case messageEntityTonAddress::ID:
      return messageEntityTonAddress::fetch(p);
    case messageExtendedMediaPreview::ID:
      return messageExtendedMediaPreview::fetch(p);
    case messageExtendedMedia::ID:
      return messageExtendedMedia::fetch(p);
    case messageFwdHeader::ID:
      return messageFwdHeader::fetch(p);
    case messageMediaEmpty::ID:
      return messageMediaEmpty::fetch(p);
    case messageMediaPhoto::ID:
      return messageMediaPhoto::fetch(p);
    case messageMediaGeo::ID:
      return messageMediaGeo::fetch(p);
    case messageMediaContact::ID:
      return messageMediaContact::fetch(p);
    case messageMediaUnsupported::ID:
      return messageMediaUnsupported::fetch(p);
    case messageMediaDocument::ID:
      return messageMediaDocument::fetch(p);
    case messageMediaWebPage::ID:
      return messageMediaWebPage::fetch(p);
    case messageMediaVenue::ID:
      return messageMediaVenue::fetch(p);
    case messageMediaGame::ID:
      return messageMediaGame::fetch(p);
    case messageMediaInvoice::ID:
      return messageMediaInvoice::fetch(p);
    case messageMediaGeoLive::ID:
      return messageMediaGeoLive::fetch(p);
    case messageMediaPoll::ID:
      return messageMediaPoll::fetch(p);
    case messageMediaDice::ID:
      return messageMediaDice::fetch(p);
    case messageMediaStory::ID:
      return messageMediaStory::fetch(p);
    case messageMediaGiveaway::ID:
      return messageMediaGiveaway::fetch(p);
    case messageMediaGiveawayResults::ID:
      return messageMediaGiveawayResults::fetch(p);
    case messageMediaPaidMedia::ID:
      return messageMediaPaidMedia::fetch(p);
    case messageMediaToDo::ID:
      return messageMediaToDo::fetch(p);
    case messageMediaVideoStream::ID:
      return messageMediaVideoStream::fetch(p);
    case messageMediaWidget::ID:
      return messageMediaWidget::fetch(p);
    case messagePeerReaction::ID:
      return messagePeerReaction::fetch(p);
    case messagePeerVote::ID:
      return messagePeerVote::fetch(p);
    case messagePeerVoteInputOption::ID:
      return messagePeerVoteInputOption::fetch(p);
    case messagePeerVoteMultiple::ID:
      return messagePeerVoteMultiple::fetch(p);
    case messageRange::ID:
      return messageRange::fetch(p);
    case messageReactions::ID:
      return messageReactions::fetch(p);
    case messageReactor::ID:
      return messageReactor::fetch(p);
    case messageReplies::ID:
      return messageReplies::fetch(p);
    case messageReplyHeader::ID:
      return messageReplyHeader::fetch(p);
    case messageReplyStoryHeader::ID:
      return messageReplyStoryHeader::fetch(p);
    case messageReportOption::ID:
      return messageReportOption::fetch(p);
    case messageViews::ID:
      return messageViews::fetch(p);
    case inputMessagesFilterEmpty::ID:
      return inputMessagesFilterEmpty::fetch(p);
    case inputMessagesFilterPhotos::ID:
      return inputMessagesFilterPhotos::fetch(p);
    case inputMessagesFilterVideo::ID:
      return inputMessagesFilterVideo::fetch(p);
    case inputMessagesFilterPhotoVideo::ID:
      return inputMessagesFilterPhotoVideo::fetch(p);
    case inputMessagesFilterDocument::ID:
      return inputMessagesFilterDocument::fetch(p);
    case inputMessagesFilterUrl::ID:
      return inputMessagesFilterUrl::fetch(p);
    case inputMessagesFilterGif::ID:
      return inputMessagesFilterGif::fetch(p);
    case inputMessagesFilterVoice::ID:
      return inputMessagesFilterVoice::fetch(p);
    case inputMessagesFilterMusic::ID:
      return inputMessagesFilterMusic::fetch(p);
    case inputMessagesFilterChatPhotos::ID:
      return inputMessagesFilterChatPhotos::fetch(p);
    case inputMessagesFilterPhoneCalls::ID:
      return inputMessagesFilterPhoneCalls::fetch(p);
    case inputMessagesFilterRoundVoice::ID:
      return inputMessagesFilterRoundVoice::fetch(p);
    case inputMessagesFilterRoundVideo::ID:
      return inputMessagesFilterRoundVideo::fetch(p);
    case inputMessagesFilterMyMentions::ID:
      return inputMessagesFilterMyMentions::fetch(p);
    case inputMessagesFilterGeo::ID:
      return inputMessagesFilterGeo::fetch(p);
    case inputMessagesFilterContacts::ID:
      return inputMessagesFilterContacts::fetch(p);
    case inputMessagesFilterPinned::ID:
      return inputMessagesFilterPinned::fetch(p);
    case inputMessagesFilterPoll::ID:
      return inputMessagesFilterPoll::fetch(p);
    case missingInvitee::ID:
      return missingInvitee::fetch(p);
    case myBoost::ID:
      return myBoost::fetch(p);
    case nearestDc::ID:
      return nearestDc::fetch(p);
    case notificationSoundDefault::ID:
      return notificationSoundDefault::fetch(p);
    case notificationSoundNone::ID:
      return notificationSoundNone::fetch(p);
    case notificationSoundLocal::ID:
      return notificationSoundLocal::fetch(p);
    case notificationSoundRingtone::ID:
      return notificationSoundRingtone::fetch(p);
    case notifyPeer::ID:
      return notifyPeer::fetch(p);
    case notifyUsers::ID:
      return notifyUsers::fetch(p);
    case notifyChats::ID:
      return notifyChats::fetch(p);
    case notifyBroadcasts::ID:
      return notifyBroadcasts::fetch(p);
    case notifyForumTopic::ID:
      return notifyForumTopic::fetch(p);
    case notifyCommunity::ID:
      return notifyCommunity::fetch(p);
    case onrampAvailability::ID:
      return onrampAvailability::fetch(p);
    case onrampLimits::ID:
      return onrampLimits::fetch(p);
    case onrampMethodAvailability::ID:
      return onrampMethodAvailability::fetch(p);
    case onrampProviderInfo::ID:
      return onrampProviderInfo::fetch(p);
    case onrampQuote::ID:
      return onrampQuote::fetch(p);
    case onrampSession::ID:
      return onrampSession::fetch(p);
    case outboxReadDate::ID:
      return outboxReadDate::fetch(p);
    case page::ID:
      return page::fetch(p);
    case pageBlockUnsupported::ID:
      return pageBlockUnsupported::fetch(p);
    case pageBlockTitle::ID:
      return pageBlockTitle::fetch(p);
    case pageBlockSubtitle::ID:
      return pageBlockSubtitle::fetch(p);
    case pageBlockAuthorDate::ID:
      return pageBlockAuthorDate::fetch(p);
    case pageBlockHeader::ID:
      return pageBlockHeader::fetch(p);
    case pageBlockSubheader::ID:
      return pageBlockSubheader::fetch(p);
    case pageBlockParagraph::ID:
      return pageBlockParagraph::fetch(p);
    case pageBlockPreformatted::ID:
      return pageBlockPreformatted::fetch(p);
    case pageBlockFooter::ID:
      return pageBlockFooter::fetch(p);
    case pageBlockDivider::ID:
      return pageBlockDivider::fetch(p);
    case pageBlockAnchor::ID:
      return pageBlockAnchor::fetch(p);
    case pageBlockList::ID:
      return pageBlockList::fetch(p);
    case pageBlockBlockquote::ID:
      return pageBlockBlockquote::fetch(p);
    case pageBlockPullquote::ID:
      return pageBlockPullquote::fetch(p);
    case pageBlockPhoto::ID:
      return pageBlockPhoto::fetch(p);
    case pageBlockVideo::ID:
      return pageBlockVideo::fetch(p);
    case pageBlockCover::ID:
      return pageBlockCover::fetch(p);
    case pageBlockEmbed::ID:
      return pageBlockEmbed::fetch(p);
    case pageBlockEmbedPost::ID:
      return pageBlockEmbedPost::fetch(p);
    case pageBlockCollage::ID:
      return pageBlockCollage::fetch(p);
    case pageBlockSlideshow::ID:
      return pageBlockSlideshow::fetch(p);
    case pageBlockChannel::ID:
      return pageBlockChannel::fetch(p);
    case pageBlockAudio::ID:
      return pageBlockAudio::fetch(p);
    case pageBlockKicker::ID:
      return pageBlockKicker::fetch(p);
    case pageBlockTable::ID:
      return pageBlockTable::fetch(p);
    case pageBlockOrderedList::ID:
      return pageBlockOrderedList::fetch(p);
    case pageBlockDetails::ID:
      return pageBlockDetails::fetch(p);
    case pageBlockRelatedArticles::ID:
      return pageBlockRelatedArticles::fetch(p);
    case pageBlockMap::ID:
      return pageBlockMap::fetch(p);
    case pageBlockHeading1::ID:
      return pageBlockHeading1::fetch(p);
    case pageBlockHeading2::ID:
      return pageBlockHeading2::fetch(p);
    case pageBlockHeading3::ID:
      return pageBlockHeading3::fetch(p);
    case pageBlockHeading4::ID:
      return pageBlockHeading4::fetch(p);
    case pageBlockHeading5::ID:
      return pageBlockHeading5::fetch(p);
    case pageBlockHeading6::ID:
      return pageBlockHeading6::fetch(p);
    case pageBlockMath::ID:
      return pageBlockMath::fetch(p);
    case pageBlockThinking::ID:
      return pageBlockThinking::fetch(p);
    case inputPageBlockMap::ID:
      return inputPageBlockMap::fetch(p);
    case pageBlockBlockquoteBlocks::ID:
      return pageBlockBlockquoteBlocks::fetch(p);
    case pageBlockButtonRow::ID:
      return pageBlockButtonRow::fetch(p);
    case pageBlockDocument::ID:
      return pageBlockDocument::fetch(p);
    case pageButton::ID:
      return pageButton::fetch(p);
    case pageCaption::ID:
      return pageCaption::fetch(p);
    case pageListItemText::ID:
      return pageListItemText::fetch(p);
    case pageListItemBlocks::ID:
      return pageListItemBlocks::fetch(p);
    case pageListOrderedItemText::ID:
      return pageListOrderedItemText::fetch(p);
    case pageListOrderedItemBlocks::ID:
      return pageListOrderedItemBlocks::fetch(p);
    case pageRelatedArticle::ID:
      return pageRelatedArticle::fetch(p);
    case pageTableCell::ID:
      return pageTableCell::fetch(p);
    case pageTableRow::ID:
      return pageTableRow::fetch(p);
    case paidReactionPrivacyDefault::ID:
      return paidReactionPrivacyDefault::fetch(p);
    case paidReactionPrivacyAnonymous::ID:
      return paidReactionPrivacyAnonymous::fetch(p);
    case paidReactionPrivacyPeer::ID:
      return paidReactionPrivacyPeer::fetch(p);
    case passkey::ID:
      return passkey::fetch(p);
    case passwordKdfAlgoUnknown::ID:
      return passwordKdfAlgoUnknown::fetch(p);
    case passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::ID:
      return passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::fetch(p);
    case paymentCharge::ID:
      return paymentCharge::fetch(p);
    case paymentFormMethod::ID:
      return paymentFormMethod::fetch(p);
    case paymentRequestedInfo::ID:
      return paymentRequestedInfo::fetch(p);
    case paymentSavedCredentialsCard::ID:
      return paymentSavedCredentialsCard::fetch(p);
    case peerUser::ID:
      return peerUser::fetch(p);
    case peerChat::ID:
      return peerChat::fetch(p);
    case peerChannel::ID:
      return peerChannel::fetch(p);
    case peerBlocked::ID:
      return peerBlocked::fetch(p);
    case peerColor::ID:
      return peerColor::fetch(p);
    case peerColorCollectible::ID:
      return peerColorCollectible::fetch(p);
    case inputPeerColorCollectible::ID:
      return inputPeerColorCollectible::fetch(p);
    case peerLocated::ID:
      return peerLocated::fetch(p);
    case peerSelfLocated::ID:
      return peerSelfLocated::fetch(p);
    case peerNotifySettings::ID:
      return peerNotifySettings::fetch(p);
    case peerSettings::ID:
      return peerSettings::fetch(p);
    case peerStories::ID:
      return peerStories::fetch(p);
    case pendingSuggestion::ID:
      return pendingSuggestion::fetch(p);
    case phoneCallEmpty::ID:
      return phoneCallEmpty::fetch(p);
    case phoneCallWaiting::ID:
      return phoneCallWaiting::fetch(p);
    case phoneCallRequested::ID:
      return phoneCallRequested::fetch(p);
    case phoneCallAccepted::ID:
      return phoneCallAccepted::fetch(p);
    case phoneCall::ID:
      return phoneCall::fetch(p);
    case phoneCallDiscarded::ID:
      return phoneCallDiscarded::fetch(p);
    case phoneCallDiscardReasonMissed::ID:
      return phoneCallDiscardReasonMissed::fetch(p);
    case phoneCallDiscardReasonDisconnect::ID:
      return phoneCallDiscardReasonDisconnect::fetch(p);
    case phoneCallDiscardReasonHangup::ID:
      return phoneCallDiscardReasonHangup::fetch(p);
    case phoneCallDiscardReasonBusy::ID:
      return phoneCallDiscardReasonBusy::fetch(p);
    case phoneCallDiscardReasonMigrateConferenceCall::ID:
      return phoneCallDiscardReasonMigrateConferenceCall::fetch(p);
    case phoneCallProtocol::ID:
      return phoneCallProtocol::fetch(p);
    case phoneConnection::ID:
      return phoneConnection::fetch(p);
    case phoneConnectionWebrtc::ID:
      return phoneConnectionWebrtc::fetch(p);
    case photoEmpty::ID:
      return photoEmpty::fetch(p);
    case photo::ID:
      return photo::fetch(p);
    case photoSizeEmpty::ID:
      return photoSizeEmpty::fetch(p);
    case photoSize::ID:
      return photoSize::fetch(p);
    case photoCachedSize::ID:
      return photoCachedSize::fetch(p);
    case photoStrippedSize::ID:
      return photoStrippedSize::fetch(p);
    case photoSizeProgressive::ID:
      return photoSizeProgressive::fetch(p);
    case photoPathSize::ID:
      return photoPathSize::fetch(p);
    case poll::ID:
      return poll::fetch(p);
    case pollAnswer::ID:
      return pollAnswer::fetch(p);
    case inputPollAnswer::ID:
      return inputPollAnswer::fetch(p);
    case pollAnswerVoters::ID:
      return pollAnswerVoters::fetch(p);
    case pollResults::ID:
      return pollResults::fetch(p);
    case popularContact::ID:
      return popularContact::fetch(p);
    case postAddress::ID:
      return postAddress::fetch(p);
    case postInteractionCountersMessage::ID:
      return postInteractionCountersMessage::fetch(p);
    case postInteractionCountersStory::ID:
      return postInteractionCountersStory::fetch(p);
    case premiumGiftCodeOption::ID:
      return premiumGiftCodeOption::fetch(p);
    case premiumSubscriptionOption::ID:
      return premiumSubscriptionOption::fetch(p);
    case prepaidGiveaway::ID:
      return prepaidGiveaway::fetch(p);
    case prepaidStarsGiveaway::ID:
      return prepaidStarsGiveaway::fetch(p);
    case privacyKeyStatusTimestamp::ID:
      return privacyKeyStatusTimestamp::fetch(p);
    case privacyKeyChatInvite::ID:
      return privacyKeyChatInvite::fetch(p);
    case privacyKeyPhoneCall::ID:
      return privacyKeyPhoneCall::fetch(p);
    case privacyKeyPhoneP2P::ID:
      return privacyKeyPhoneP2P::fetch(p);
    case privacyKeyForwards::ID:
      return privacyKeyForwards::fetch(p);
    case privacyKeyProfilePhoto::ID:
      return privacyKeyProfilePhoto::fetch(p);
    case privacyKeyPhoneNumber::ID:
      return privacyKeyPhoneNumber::fetch(p);
    case privacyKeyAddedByPhone::ID:
      return privacyKeyAddedByPhone::fetch(p);
    case privacyKeyVoiceMessages::ID:
      return privacyKeyVoiceMessages::fetch(p);
    case privacyKeyAbout::ID:
      return privacyKeyAbout::fetch(p);
    case privacyKeyBirthday::ID:
      return privacyKeyBirthday::fetch(p);
    case privacyKeyStarGiftsAutoSave::ID:
      return privacyKeyStarGiftsAutoSave::fetch(p);
    case privacyKeyNoPaidMessages::ID:
      return privacyKeyNoPaidMessages::fetch(p);
    case privacyKeySavedMusic::ID:
      return privacyKeySavedMusic::fetch(p);
    case privacyValueAllowContacts::ID:
      return privacyValueAllowContacts::fetch(p);
    case privacyValueAllowAll::ID:
      return privacyValueAllowAll::fetch(p);
    case privacyValueAllowUsers::ID:
      return privacyValueAllowUsers::fetch(p);
    case privacyValueDisallowContacts::ID:
      return privacyValueDisallowContacts::fetch(p);
    case privacyValueDisallowAll::ID:
      return privacyValueDisallowAll::fetch(p);
    case privacyValueDisallowUsers::ID:
      return privacyValueDisallowUsers::fetch(p);
    case privacyValueAllowChatParticipants::ID:
      return privacyValueAllowChatParticipants::fetch(p);
    case privacyValueDisallowChatParticipants::ID:
      return privacyValueDisallowChatParticipants::fetch(p);
    case privacyValueAllowCloseFriends::ID:
      return privacyValueAllowCloseFriends::fetch(p);
    case privacyValueAllowPremium::ID:
      return privacyValueAllowPremium::fetch(p);
    case privacyValueAllowBots::ID:
      return privacyValueAllowBots::fetch(p);
    case privacyValueDisallowBots::ID:
      return privacyValueDisallowBots::fetch(p);
    case profileTabPosts::ID:
      return profileTabPosts::fetch(p);
    case profileTabGifts::ID:
      return profileTabGifts::fetch(p);
    case profileTabMedia::ID:
      return profileTabMedia::fetch(p);
    case profileTabFiles::ID:
      return profileTabFiles::fetch(p);
    case profileTabMusic::ID:
      return profileTabMusic::fetch(p);
    case profileTabVoice::ID:
      return profileTabVoice::fetch(p);
    case profileTabLinks::ID:
      return profileTabLinks::fetch(p);
    case profileTabGifs::ID:
      return profileTabGifs::fetch(p);
    case publicForwardMessage::ID:
      return publicForwardMessage::fetch(p);
    case publicForwardStory::ID:
      return publicForwardStory::fetch(p);
    case quickReply::ID:
      return quickReply::fetch(p);
    case reactionEmpty::ID:
      return reactionEmpty::fetch(p);
    case reactionEmoji::ID:
      return reactionEmoji::fetch(p);
    case reactionCustomEmoji::ID:
      return reactionCustomEmoji::fetch(p);
    case reactionPaid::ID:
      return reactionPaid::fetch(p);
    case reactionCount::ID:
      return reactionCount::fetch(p);
    case reactionNotificationsFromContacts::ID:
      return reactionNotificationsFromContacts::fetch(p);
    case reactionNotificationsFromAll::ID:
      return reactionNotificationsFromAll::fetch(p);
    case reactionsNotifySettings::ID:
      return reactionsNotifySettings::fetch(p);
    case readParticipantDate::ID:
      return readParticipantDate::fetch(p);
    case receivedNotifyMessage::ID:
      return receivedNotifyMessage::fetch(p);
    case recentMeUrlUnknown::ID:
      return recentMeUrlUnknown::fetch(p);
    case recentMeUrlUser::ID:
      return recentMeUrlUser::fetch(p);
    case recentMeUrlChat::ID:
      return recentMeUrlChat::fetch(p);
    case recentMeUrlChatInvite::ID:
      return recentMeUrlChatInvite::fetch(p);
    case recentMeUrlStickerSet::ID:
      return recentMeUrlStickerSet::fetch(p);
    case recentStory::ID:
      return recentStory::fetch(p);
    case replyKeyboardHide::ID:
      return replyKeyboardHide::fetch(p);
    case replyKeyboardForceReply::ID:
      return replyKeyboardForceReply::fetch(p);
    case replyKeyboardMarkup::ID:
      return replyKeyboardMarkup::fetch(p);
    case replyInlineMarkup::ID:
      return replyInlineMarkup::fetch(p);
    case reportResultChooseOption::ID:
      return reportResultChooseOption::fetch(p);
    case reportResultAddComment::ID:
      return reportResultAddComment::fetch(p);
    case reportResultReported::ID:
      return reportResultReported::fetch(p);
    case requestPeerTypeUser::ID:
      return requestPeerTypeUser::fetch(p);
    case requestPeerTypeChat::ID:
      return requestPeerTypeChat::fetch(p);
    case requestPeerTypeBroadcast::ID:
      return requestPeerTypeBroadcast::fetch(p);
    case requestPeerTypeCreateBot::ID:
      return requestPeerTypeCreateBot::fetch(p);
    case requestedPeerUser::ID:
      return requestedPeerUser::fetch(p);
    case requestedPeerChat::ID:
      return requestedPeerChat::fetch(p);
    case requestedPeerChannel::ID:
      return requestedPeerChannel::fetch(p);
    case requirementToContactEmpty::ID:
      return requirementToContactEmpty::fetch(p);
    case requirementToContactPremium::ID:
      return requirementToContactPremium::fetch(p);
    case requirementToContactPaidMessages::ID:
      return requirementToContactPaidMessages::fetch(p);
    case restrictionReason::ID:
      return restrictionReason::fetch(p);
    case richButtonStyle::ID:
      return richButtonStyle::fetch(p);
    case richMessage::ID:
      return richMessage::fetch(p);
    case textEmpty::ID:
      return textEmpty::fetch(p);
    case textPlain::ID:
      return textPlain::fetch(p);
    case textBold::ID:
      return textBold::fetch(p);
    case textItalic::ID:
      return textItalic::fetch(p);
    case textUnderline::ID:
      return textUnderline::fetch(p);
    case textStrike::ID:
      return textStrike::fetch(p);
    case textFixed::ID:
      return textFixed::fetch(p);
    case textUrl::ID:
      return textUrl::fetch(p);
    case textEmail::ID:
      return textEmail::fetch(p);
    case textConcat::ID:
      return textConcat::fetch(p);
    case textSubscript::ID:
      return textSubscript::fetch(p);
    case textSuperscript::ID:
      return textSuperscript::fetch(p);
    case textMarked::ID:
      return textMarked::fetch(p);
    case textPhone::ID:
      return textPhone::fetch(p);
    case textImage::ID:
      return textImage::fetch(p);
    case textAnchor::ID:
      return textAnchor::fetch(p);
    case textMath::ID:
      return textMath::fetch(p);
    case textCustomEmoji::ID:
      return textCustomEmoji::fetch(p);
    case textSpoiler::ID:
      return textSpoiler::fetch(p);
    case textMention::ID:
      return textMention::fetch(p);
    case textHashtag::ID:
      return textHashtag::fetch(p);
    case textBotCommand::ID:
      return textBotCommand::fetch(p);
    case textCashtag::ID:
      return textCashtag::fetch(p);
    case textAutoUrl::ID:
      return textAutoUrl::fetch(p);
    case textAutoEmail::ID:
      return textAutoEmail::fetch(p);
    case textAutoPhone::ID:
      return textAutoPhone::fetch(p);
    case textBankCard::ID:
      return textBankCard::fetch(p);
    case textMentionName::ID:
      return textMentionName::fetch(p);
    case textDate::ID:
      return textDate::fetch(p);
    case textDiff::ID:
      return textDiff::fetch(p);
    case textButton::ID:
      return textButton::fetch(p);
    case textTonAddress::ID:
      return textTonAddress::fetch(p);
    case savedPhoneContact::ID:
      return savedPhoneContact::fetch(p);
    case savedDialog::ID:
      return savedDialog::fetch(p);
    case monoForumDialog::ID:
      return monoForumDialog::fetch(p);
    case savedReactionTag::ID:
      return savedReactionTag::fetch(p);
    case savedStarGift::ID:
      return savedStarGift::fetch(p);
    case searchPostsFlood::ID:
      return searchPostsFlood::fetch(p);
    case searchResultsCalendarPeriod::ID:
      return searchResultsCalendarPeriod::fetch(p);
    case searchResultPosition::ID:
      return searchResultPosition::fetch(p);
    case secureCredentialsEncrypted::ID:
      return secureCredentialsEncrypted::fetch(p);
    case secureData::ID:
      return secureData::fetch(p);
    case secureFileEmpty::ID:
      return secureFileEmpty::fetch(p);
    case secureFile::ID:
      return secureFile::fetch(p);
    case securePasswordKdfAlgoUnknown::ID:
      return securePasswordKdfAlgoUnknown::fetch(p);
    case securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::ID:
      return securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::fetch(p);
    case securePasswordKdfAlgoSHA512::ID:
      return securePasswordKdfAlgoSHA512::fetch(p);
    case securePlainPhone::ID:
      return securePlainPhone::fetch(p);
    case securePlainEmail::ID:
      return securePlainEmail::fetch(p);
    case secureRequiredType::ID:
      return secureRequiredType::fetch(p);
    case secureRequiredTypeOneOf::ID:
      return secureRequiredTypeOneOf::fetch(p);
    case secureSecretSettings::ID:
      return secureSecretSettings::fetch(p);
    case secureValue::ID:
      return secureValue::fetch(p);
    case secureValueErrorData::ID:
      return secureValueErrorData::fetch(p);
    case secureValueErrorFrontSide::ID:
      return secureValueErrorFrontSide::fetch(p);
    case secureValueErrorReverseSide::ID:
      return secureValueErrorReverseSide::fetch(p);
    case secureValueErrorSelfie::ID:
      return secureValueErrorSelfie::fetch(p);
    case secureValueErrorFile::ID:
      return secureValueErrorFile::fetch(p);
    case secureValueErrorFiles::ID:
      return secureValueErrorFiles::fetch(p);
    case secureValueError::ID:
      return secureValueError::fetch(p);
    case secureValueErrorTranslationFile::ID:
      return secureValueErrorTranslationFile::fetch(p);
    case secureValueErrorTranslationFiles::ID:
      return secureValueErrorTranslationFiles::fetch(p);
    case secureValueTypePersonalDetails::ID:
      return secureValueTypePersonalDetails::fetch(p);
    case secureValueTypePassport::ID:
      return secureValueTypePassport::fetch(p);
    case secureValueTypeDriverLicense::ID:
      return secureValueTypeDriverLicense::fetch(p);
    case secureValueTypeIdentityCard::ID:
      return secureValueTypeIdentityCard::fetch(p);
    case secureValueTypeInternalPassport::ID:
      return secureValueTypeInternalPassport::fetch(p);
    case secureValueTypeAddress::ID:
      return secureValueTypeAddress::fetch(p);
    case secureValueTypeUtilityBill::ID:
      return secureValueTypeUtilityBill::fetch(p);
    case secureValueTypeBankStatement::ID:
      return secureValueTypeBankStatement::fetch(p);
    case secureValueTypeRentalAgreement::ID:
      return secureValueTypeRentalAgreement::fetch(p);
    case secureValueTypePassportRegistration::ID:
      return secureValueTypePassportRegistration::fetch(p);
    case secureValueTypeTemporaryRegistration::ID:
      return secureValueTypeTemporaryRegistration::fetch(p);
    case secureValueTypePhone::ID:
      return secureValueTypePhone::fetch(p);
    case secureValueTypeEmail::ID:
      return secureValueTypeEmail::fetch(p);
    case sendAsPeer::ID:
      return sendAsPeer::fetch(p);
    case sendMessageTypingAction::ID:
      return sendMessageTypingAction::fetch(p);
    case sendMessageCancelAction::ID:
      return sendMessageCancelAction::fetch(p);
    case sendMessageRecordVideoAction::ID:
      return sendMessageRecordVideoAction::fetch(p);
    case sendMessageUploadVideoAction::ID:
      return sendMessageUploadVideoAction::fetch(p);
    case sendMessageRecordAudioAction::ID:
      return sendMessageRecordAudioAction::fetch(p);
    case sendMessageUploadAudioAction::ID:
      return sendMessageUploadAudioAction::fetch(p);
    case sendMessageUploadPhotoAction::ID:
      return sendMessageUploadPhotoAction::fetch(p);
    case sendMessageUploadDocumentAction::ID:
      return sendMessageUploadDocumentAction::fetch(p);
    case sendMessageGeoLocationAction::ID:
      return sendMessageGeoLocationAction::fetch(p);
    case sendMessageChooseContactAction::ID:
      return sendMessageChooseContactAction::fetch(p);
    case sendMessageGamePlayAction::ID:
      return sendMessageGamePlayAction::fetch(p);
    case sendMessageRecordRoundAction::ID:
      return sendMessageRecordRoundAction::fetch(p);
    case sendMessageUploadRoundAction::ID:
      return sendMessageUploadRoundAction::fetch(p);
    case speakingInGroupCallAction::ID:
      return speakingInGroupCallAction::fetch(p);
    case sendMessageHistoryImportAction::ID:
      return sendMessageHistoryImportAction::fetch(p);
    case sendMessageChooseStickerAction::ID:
      return sendMessageChooseStickerAction::fetch(p);
    case sendMessageEmojiInteraction::ID:
      return sendMessageEmojiInteraction::fetch(p);
    case sendMessageEmojiInteractionSeen::ID:
      return sendMessageEmojiInteractionSeen::fetch(p);
    case sendMessageTextDraftAction::ID:
      return sendMessageTextDraftAction::fetch(p);
    case inputSendMessageRichMessageDraftAction::ID:
      return inputSendMessageRichMessageDraftAction::fetch(p);
    case sendMessageRichMessageDraftAction::ID:
      return sendMessageRichMessageDraftAction::fetch(p);
    case sendMessageStopDraftAction::ID:
      return sendMessageStopDraftAction::fetch(p);
    case shareThemeDefault::ID:
      return shareThemeDefault::fetch(p);
    case shareThemeEmojiBackdrop::ID:
      return shareThemeEmojiBackdrop::fetch(p);
    case shareThemeGift::ID:
      return shareThemeGift::fetch(p);
    case inputShareThemeGift::ID:
      return inputShareThemeGift::fetch(p);
    case shareThemeBackdropOption::ID:
      return shareThemeBackdropOption::fetch(p);
    case shareThemeBackdropsNotModified::ID:
      return shareThemeBackdropsNotModified::fetch(p);
    case shareThemeBackdrops::ID:
      return shareThemeBackdrops::fetch(p);
    case shippingOption::ID:
      return shippingOption::fetch(p);
    case smsJob::ID:
      return smsJob::fetch(p);
    case sponsoredMessage::ID:
      return sponsoredMessage::fetch(p);
    case sponsoredMessageReportOption::ID:
      return sponsoredMessageReportOption::fetch(p);
    case sponsoredPeer::ID:
      return sponsoredPeer::fetch(p);
    case starGift::ID:
      return starGift::fetch(p);
    case starGiftUnique::ID:
      return starGiftUnique::fetch(p);
    case starGiftActiveAuctionState::ID:
      return starGiftActiveAuctionState::fetch(p);
    case starGiftAttributeModel::ID:
      return starGiftAttributeModel::fetch(p);
    case starGiftAttributePattern::ID:
      return starGiftAttributePattern::fetch(p);
    case starGiftAttributeBackdrop::ID:
      return starGiftAttributeBackdrop::fetch(p);
    case starGiftAttributeOriginalDetails::ID:
      return starGiftAttributeOriginalDetails::fetch(p);
    case starGiftAttributeCounter::ID:
      return starGiftAttributeCounter::fetch(p);
    case starGiftAttributeIdModel::ID:
      return starGiftAttributeIdModel::fetch(p);
    case starGiftAttributeIdPattern::ID:
      return starGiftAttributeIdPattern::fetch(p);
    case starGiftAttributeIdBackdrop::ID:
      return starGiftAttributeIdBackdrop::fetch(p);
    case starGiftAttributeRarity::ID:
      return starGiftAttributeRarity::fetch(p);
    case starGiftAttributeRarityUncommon::ID:
      return starGiftAttributeRarityUncommon::fetch(p);
    case starGiftAttributeRarityRare::ID:
      return starGiftAttributeRarityRare::fetch(p);
    case starGiftAttributeRarityEpic::ID:
      return starGiftAttributeRarityEpic::fetch(p);
    case starGiftAttributeRarityLegendary::ID:
      return starGiftAttributeRarityLegendary::fetch(p);
    case starGiftAuctionAcquiredGift::ID:
      return starGiftAuctionAcquiredGift::fetch(p);
    case starGiftAuctionRound::ID:
      return starGiftAuctionRound::fetch(p);
    case starGiftAuctionRoundExtendable::ID:
      return starGiftAuctionRoundExtendable::fetch(p);
    case starGiftAuctionStateNotModified::ID:
      return starGiftAuctionStateNotModified::fetch(p);
    case starGiftAuctionState::ID:
      return starGiftAuctionState::fetch(p);
    case starGiftAuctionStateFinished::ID:
      return starGiftAuctionStateFinished::fetch(p);
    case starGiftAuctionUserState::ID:
      return starGiftAuctionUserState::fetch(p);
    case starGiftBackground::ID:
      return starGiftBackground::fetch(p);
    case starGiftCollection::ID:
      return starGiftCollection::fetch(p);
    case starGiftUpgradePrice::ID:
      return starGiftUpgradePrice::fetch(p);
    case starRefProgram::ID:
      return starRefProgram::fetch(p);
    case starsAmount::ID:
      return starsAmount::fetch(p);
    case starsTonAmount::ID:
      return starsTonAmount::fetch(p);
    case starsGiftOption::ID:
      return starsGiftOption::fetch(p);
    case starsGiveawayOption::ID:
      return starsGiveawayOption::fetch(p);
    case starsGiveawayWinnersOption::ID:
      return starsGiveawayWinnersOption::fetch(p);
    case starsRating::ID:
      return starsRating::fetch(p);
    case starsRevenueStatus::ID:
      return starsRevenueStatus::fetch(p);
    case starsSubscription::ID:
      return starsSubscription::fetch(p);
    case starsSubscriptionPricing::ID:
      return starsSubscriptionPricing::fetch(p);
    case starsTopupOption::ID:
      return starsTopupOption::fetch(p);
    case starsTransaction::ID:
      return starsTransaction::fetch(p);
    case starsTransactionPeerUnsupported::ID:
      return starsTransactionPeerUnsupported::fetch(p);
    case starsTransactionPeerAppStore::ID:
      return starsTransactionPeerAppStore::fetch(p);
    case starsTransactionPeerPlayMarket::ID:
      return starsTransactionPeerPlayMarket::fetch(p);
    case starsTransactionPeerPremiumBot::ID:
      return starsTransactionPeerPremiumBot::fetch(p);
    case starsTransactionPeerFragment::ID:
      return starsTransactionPeerFragment::fetch(p);
    case starsTransactionPeer::ID:
      return starsTransactionPeer::fetch(p);
    case starsTransactionPeerAds::ID:
      return starsTransactionPeerAds::fetch(p);
    case starsTransactionPeerAPI::ID:
      return starsTransactionPeerAPI::fetch(p);
    case statsAbsValueAndPrev::ID:
      return statsAbsValueAndPrev::fetch(p);
    case statsDateRangeDays::ID:
      return statsDateRangeDays::fetch(p);
    case statsGraphAsync::ID:
      return statsGraphAsync::fetch(p);
    case statsGraphError::ID:
      return statsGraphError::fetch(p);
    case statsGraph::ID:
      return statsGraph::fetch(p);
    case statsGroupTopAdmin::ID:
      return statsGroupTopAdmin::fetch(p);
    case statsGroupTopInviter::ID:
      return statsGroupTopInviter::fetch(p);
    case statsGroupTopPoster::ID:
      return statsGroupTopPoster::fetch(p);
    case statsPercentValue::ID:
      return statsPercentValue::fetch(p);
    case stickerKeyword::ID:
      return stickerKeyword::fetch(p);
    case stickerPack::ID:
      return stickerPack::fetch(p);
    case stickerSet::ID:
      return stickerSet::fetch(p);
    case stickerSetCovered::ID:
      return stickerSetCovered::fetch(p);
    case stickerSetMultiCovered::ID:
      return stickerSetMultiCovered::fetch(p);
    case stickerSetFullCovered::ID:
      return stickerSetFullCovered::fetch(p);
    case stickerSetNoCovered::ID:
      return stickerSetNoCovered::fetch(p);
    case storiesStealthMode::ID:
      return storiesStealthMode::fetch(p);
    case storyAlbum::ID:
      return storyAlbum::fetch(p);
    case storyFwdHeader::ID:
      return storyFwdHeader::fetch(p);
    case storyItemDeleted::ID:
      return storyItemDeleted::fetch(p);
    case storyItemSkipped::ID:
      return storyItemSkipped::fetch(p);
    case storyItem::ID:
      return storyItem::fetch(p);
    case storyReaction::ID:
      return storyReaction::fetch(p);
    case storyReactionPublicForward::ID:
      return storyReactionPublicForward::fetch(p);
    case storyReactionPublicRepost::ID:
      return storyReactionPublicRepost::fetch(p);
    case storyView::ID:
      return storyView::fetch(p);
    case storyViewPublicForward::ID:
      return storyViewPublicForward::fetch(p);
    case storyViewPublicRepost::ID:
      return storyViewPublicRepost::fetch(p);
    case storyViews::ID:
      return storyViews::fetch(p);
    case suggestedPost::ID:
      return suggestedPost::fetch(p);
    case textWithEntities::ID:
      return textWithEntities::fetch(p);
    case theme::ID:
      return theme::fetch(p);
    case themeSettings::ID:
      return themeSettings::fetch(p);
    case timezone::ID:
      return timezone::fetch(p);
    case todoCompletion::ID:
      return todoCompletion::fetch(p);
    case todoItem::ID:
      return todoItem::fetch(p);
    case todoList::ID:
      return todoList::fetch(p);
    case tonConnectManifest::ID:
      return tonConnectManifest::fetch(p);
    case tonConnectNextEventId::ID:
      return tonConnectNextEventId::fetch(p);
    case tonConnectRequest::ID:
      return tonConnectRequest::fetch(p);
    case tonConnectSession::ID:
      return tonConnectSession::fetch(p);
    case topPeer::ID:
      return topPeer::fetch(p);
    case topPeerCategoryBotsPM::ID:
      return topPeerCategoryBotsPM::fetch(p);
    case topPeerCategoryBotsInline::ID:
      return topPeerCategoryBotsInline::fetch(p);
    case topPeerCategoryCorrespondents::ID:
      return topPeerCategoryCorrespondents::fetch(p);
    case topPeerCategoryGroups::ID:
      return topPeerCategoryGroups::fetch(p);
    case topPeerCategoryChannels::ID:
      return topPeerCategoryChannels::fetch(p);
    case topPeerCategoryPhoneCalls::ID:
      return topPeerCategoryPhoneCalls::fetch(p);
    case topPeerCategoryForwardUsers::ID:
      return topPeerCategoryForwardUsers::fetch(p);
    case topPeerCategoryForwardChats::ID:
      return topPeerCategoryForwardChats::fetch(p);
    case topPeerCategoryBotsApp::ID:
      return topPeerCategoryBotsApp::fetch(p);
    case topPeerCategoryBotsGuestChat::ID:
      return topPeerCategoryBotsGuestChat::fetch(p);
    case topPeerCategoryPeers::ID:
      return topPeerCategoryPeers::fetch(p);
    case transcriptionModel::ID:
      return transcriptionModel::fetch(p);
    case updateNewMessage::ID:
      return updateNewMessage::fetch(p);
    case updateMessageID::ID:
      return updateMessageID::fetch(p);
    case updateDeleteMessages::ID:
      return updateDeleteMessages::fetch(p);
    case updateUserTyping::ID:
      return updateUserTyping::fetch(p);
    case updateChatUserTyping::ID:
      return updateChatUserTyping::fetch(p);
    case updateChatParticipants::ID:
      return updateChatParticipants::fetch(p);
    case updateUserStatus::ID:
      return updateUserStatus::fetch(p);
    case updateUserName::ID:
      return updateUserName::fetch(p);
    case updateNewAuthorization::ID:
      return updateNewAuthorization::fetch(p);
    case updateNewEncryptedMessage::ID:
      return updateNewEncryptedMessage::fetch(p);
    case updateEncryptedChatTyping::ID:
      return updateEncryptedChatTyping::fetch(p);
    case updateEncryption::ID:
      return updateEncryption::fetch(p);
    case updateEncryptedMessagesRead::ID:
      return updateEncryptedMessagesRead::fetch(p);
    case updateChatParticipantAdd::ID:
      return updateChatParticipantAdd::fetch(p);
    case updateChatParticipantDelete::ID:
      return updateChatParticipantDelete::fetch(p);
    case updateDcOptions::ID:
      return updateDcOptions::fetch(p);
    case updateNotifySettings::ID:
      return updateNotifySettings::fetch(p);
    case updateServiceNotification::ID:
      return updateServiceNotification::fetch(p);
    case updatePrivacy::ID:
      return updatePrivacy::fetch(p);
    case updateUserPhone::ID:
      return updateUserPhone::fetch(p);
    case updateReadHistoryInbox::ID:
      return updateReadHistoryInbox::fetch(p);
    case updateReadHistoryOutbox::ID:
      return updateReadHistoryOutbox::fetch(p);
    case updateWebPage::ID:
      return updateWebPage::fetch(p);
    case updateReadMessagesContents::ID:
      return updateReadMessagesContents::fetch(p);
    case updateChannelTooLong::ID:
      return updateChannelTooLong::fetch(p);
    case updateChannel::ID:
      return updateChannel::fetch(p);
    case updateNewChannelMessage::ID:
      return updateNewChannelMessage::fetch(p);
    case updateReadChannelInbox::ID:
      return updateReadChannelInbox::fetch(p);
    case updateDeleteChannelMessages::ID:
      return updateDeleteChannelMessages::fetch(p);
    case updateChannelMessageViews::ID:
      return updateChannelMessageViews::fetch(p);
    case updateChatParticipantAdmin::ID:
      return updateChatParticipantAdmin::fetch(p);
    case updateNewStickerSet::ID:
      return updateNewStickerSet::fetch(p);
    case updateStickerSetsOrder::ID:
      return updateStickerSetsOrder::fetch(p);
    case updateStickerSets::ID:
      return updateStickerSets::fetch(p);
    case updateSavedGifs::ID:
      return updateSavedGifs::fetch(p);
    case updateBotInlineQuery::ID:
      return updateBotInlineQuery::fetch(p);
    case updateBotInlineSend::ID:
      return updateBotInlineSend::fetch(p);
    case updateEditChannelMessage::ID:
      return updateEditChannelMessage::fetch(p);
    case updateBotCallbackQuery::ID:
      return updateBotCallbackQuery::fetch(p);
    case updateEditMessage::ID:
      return updateEditMessage::fetch(p);
    case updateInlineBotCallbackQuery::ID:
      return updateInlineBotCallbackQuery::fetch(p);
    case updateReadChannelOutbox::ID:
      return updateReadChannelOutbox::fetch(p);
    case updateDraftMessage::ID:
      return updateDraftMessage::fetch(p);
    case updateReadFeaturedStickers::ID:
      return updateReadFeaturedStickers::fetch(p);
    case updateRecentStickers::ID:
      return updateRecentStickers::fetch(p);
    case updateConfig::ID:
      return updateConfig::fetch(p);
    case updatePtsChanged::ID:
      return updatePtsChanged::fetch(p);
    case updateChannelWebPage::ID:
      return updateChannelWebPage::fetch(p);
    case updateDialogPinned::ID:
      return updateDialogPinned::fetch(p);
    case updatePinnedDialogs::ID:
      return updatePinnedDialogs::fetch(p);
    case updateBotWebhookJSON::ID:
      return updateBotWebhookJSON::fetch(p);
    case updateBotWebhookJSONQuery::ID:
      return updateBotWebhookJSONQuery::fetch(p);
    case updateBotShippingQuery::ID:
      return updateBotShippingQuery::fetch(p);
    case updateBotPrecheckoutQuery::ID:
      return updateBotPrecheckoutQuery::fetch(p);
    case updatePhoneCall::ID:
      return updatePhoneCall::fetch(p);
    case updateLangPackTooLong::ID:
      return updateLangPackTooLong::fetch(p);
    case updateLangPack::ID:
      return updateLangPack::fetch(p);
    case updateFavedStickers::ID:
      return updateFavedStickers::fetch(p);
    case updateChannelReadMessagesContents::ID:
      return updateChannelReadMessagesContents::fetch(p);
    case updateContactsReset::ID:
      return updateContactsReset::fetch(p);
    case updateChannelAvailableMessages::ID:
      return updateChannelAvailableMessages::fetch(p);
    case updateDialogUnreadMark::ID:
      return updateDialogUnreadMark::fetch(p);
    case updateMessagePoll::ID:
      return updateMessagePoll::fetch(p);
    case updateChatDefaultBannedRights::ID:
      return updateChatDefaultBannedRights::fetch(p);
    case updateFolderPeers::ID:
      return updateFolderPeers::fetch(p);
    case updatePeerSettings::ID:
      return updatePeerSettings::fetch(p);
    case updatePeerLocated::ID:
      return updatePeerLocated::fetch(p);
    case updateNewScheduledMessage::ID:
      return updateNewScheduledMessage::fetch(p);
    case updateDeleteScheduledMessages::ID:
      return updateDeleteScheduledMessages::fetch(p);
    case updateTheme::ID:
      return updateTheme::fetch(p);
    case updateGeoLiveViewed::ID:
      return updateGeoLiveViewed::fetch(p);
    case updateLoginToken::ID:
      return updateLoginToken::fetch(p);
    case updateMessagePollVote::ID:
      return updateMessagePollVote::fetch(p);
    case updateDialogFilter::ID:
      return updateDialogFilter::fetch(p);
    case updateDialogFilterOrder::ID:
      return updateDialogFilterOrder::fetch(p);
    case updateDialogFilters::ID:
      return updateDialogFilters::fetch(p);
    case updatePhoneCallSignalingData::ID:
      return updatePhoneCallSignalingData::fetch(p);
    case updateChannelMessageForwards::ID:
      return updateChannelMessageForwards::fetch(p);
    case updateReadChannelDiscussionInbox::ID:
      return updateReadChannelDiscussionInbox::fetch(p);
    case updateReadChannelDiscussionOutbox::ID:
      return updateReadChannelDiscussionOutbox::fetch(p);
    case updatePeerBlocked::ID:
      return updatePeerBlocked::fetch(p);
    case updateChannelUserTyping::ID:
      return updateChannelUserTyping::fetch(p);
    case updatePinnedMessages::ID:
      return updatePinnedMessages::fetch(p);
    case updatePinnedChannelMessages::ID:
      return updatePinnedChannelMessages::fetch(p);
    case updateChat::ID:
      return updateChat::fetch(p);
    case updateGroupCallParticipants::ID:
      return updateGroupCallParticipants::fetch(p);
    case updateGroupCall::ID:
      return updateGroupCall::fetch(p);
    case updatePeerHistoryTTL::ID:
      return updatePeerHistoryTTL::fetch(p);
    case updateChatParticipant::ID:
      return updateChatParticipant::fetch(p);
    case updateChannelParticipant::ID:
      return updateChannelParticipant::fetch(p);
    case updateBotStopped::ID:
      return updateBotStopped::fetch(p);
    case updateGroupCallConnection::ID:
      return updateGroupCallConnection::fetch(p);
    case updateBotCommands::ID:
      return updateBotCommands::fetch(p);
    case updatePendingJoinRequests::ID:
      return updatePendingJoinRequests::fetch(p);
    case updateBotChatInviteRequester::ID:
      return updateBotChatInviteRequester::fetch(p);
    case updateMessageReactions::ID:
      return updateMessageReactions::fetch(p);
    case updateAttachMenuBots::ID:
      return updateAttachMenuBots::fetch(p);
    case updateWebViewResultSent::ID:
      return updateWebViewResultSent::fetch(p);
    case updateBotMenuButton::ID:
      return updateBotMenuButton::fetch(p);
    case updateSavedRingtones::ID:
      return updateSavedRingtones::fetch(p);
    case updateTranscribedAudio::ID:
      return updateTranscribedAudio::fetch(p);
    case updateReadFeaturedEmojiStickers::ID:
      return updateReadFeaturedEmojiStickers::fetch(p);
    case updateUserEmojiStatus::ID:
      return updateUserEmojiStatus::fetch(p);
    case updateRecentEmojiStatuses::ID:
      return updateRecentEmojiStatuses::fetch(p);
    case updateRecentReactions::ID:
      return updateRecentReactions::fetch(p);
    case updateMoveStickerSetToTop::ID:
      return updateMoveStickerSetToTop::fetch(p);
    case updateMessageExtendedMedia::ID:
      return updateMessageExtendedMedia::fetch(p);
    case updateUser::ID:
      return updateUser::fetch(p);
    case updateAutoSaveSettings::ID:
      return updateAutoSaveSettings::fetch(p);
    case updateStory::ID:
      return updateStory::fetch(p);
    case updateReadStories::ID:
      return updateReadStories::fetch(p);
    case updateStoryID::ID:
      return updateStoryID::fetch(p);
    case updateStoriesStealthMode::ID:
      return updateStoriesStealthMode::fetch(p);
    case updateSentStoryReaction::ID:
      return updateSentStoryReaction::fetch(p);
    case updateBotChatBoost::ID:
      return updateBotChatBoost::fetch(p);
    case updateChannelViewForumAsMessages::ID:
      return updateChannelViewForumAsMessages::fetch(p);
    case updatePeerWallpaper::ID:
      return updatePeerWallpaper::fetch(p);
    case updateBotMessageReaction::ID:
      return updateBotMessageReaction::fetch(p);
    case updateBotMessageReactions::ID:
      return updateBotMessageReactions::fetch(p);
    case updateSavedDialogPinned::ID:
      return updateSavedDialogPinned::fetch(p);
    case updatePinnedSavedDialogs::ID:
      return updatePinnedSavedDialogs::fetch(p);
    case updateSavedReactionTags::ID:
      return updateSavedReactionTags::fetch(p);
    case updateSmsJob::ID:
      return updateSmsJob::fetch(p);
    case updateQuickReplies::ID:
      return updateQuickReplies::fetch(p);
    case updateNewQuickReply::ID:
      return updateNewQuickReply::fetch(p);
    case updateDeleteQuickReply::ID:
      return updateDeleteQuickReply::fetch(p);
    case updateQuickReplyMessage::ID:
      return updateQuickReplyMessage::fetch(p);
    case updateDeleteQuickReplyMessages::ID:
      return updateDeleteQuickReplyMessages::fetch(p);
    case updateBotBusinessConnect::ID:
      return updateBotBusinessConnect::fetch(p);
    case updateBotNewBusinessMessage::ID:
      return updateBotNewBusinessMessage::fetch(p);
    case updateBotEditBusinessMessage::ID:
      return updateBotEditBusinessMessage::fetch(p);
    case updateBotDeleteBusinessMessage::ID:
      return updateBotDeleteBusinessMessage::fetch(p);
    case updateNewStoryReaction::ID:
      return updateNewStoryReaction::fetch(p);
    case updateStarsBalance::ID:
      return updateStarsBalance::fetch(p);
    case updateBusinessBotCallbackQuery::ID:
      return updateBusinessBotCallbackQuery::fetch(p);
    case updateStarsRevenueStatus::ID:
      return updateStarsRevenueStatus::fetch(p);
    case updateBotPurchasedPaidMedia::ID:
      return updateBotPurchasedPaidMedia::fetch(p);
    case updatePaidReactionPrivacy::ID:
      return updatePaidReactionPrivacy::fetch(p);
    case updateSentPhoneCode::ID:
      return updateSentPhoneCode::fetch(p);
    case updateGroupCallChainBlocks::ID:
      return updateGroupCallChainBlocks::fetch(p);
    case updateReadMonoForumInbox::ID:
      return updateReadMonoForumInbox::fetch(p);
    case updateReadMonoForumOutbox::ID:
      return updateReadMonoForumOutbox::fetch(p);
    case updateMonoForumNoPaidException::ID:
      return updateMonoForumNoPaidException::fetch(p);
    case updateGroupCallMessage::ID:
      return updateGroupCallMessage::fetch(p);
    case updateGroupCallEncryptedMessage::ID:
      return updateGroupCallEncryptedMessage::fetch(p);
    case updatePinnedForumTopic::ID:
      return updatePinnedForumTopic::fetch(p);
    case updatePinnedForumTopics::ID:
      return updatePinnedForumTopics::fetch(p);
    case updateDeleteGroupCallMessages::ID:
      return updateDeleteGroupCallMessages::fetch(p);
    case updateStarGiftAuctionState::ID:
      return updateStarGiftAuctionState::fetch(p);
    case updateStarGiftAuctionUserState::ID:
      return updateStarGiftAuctionUserState::fetch(p);
    case updateEmojiGameInfo::ID:
      return updateEmojiGameInfo::fetch(p);
    case updateStarGiftCraftFail::ID:
      return updateStarGiftCraftFail::fetch(p);
    case updateChatParticipantRank::ID:
      return updateChatParticipantRank::fetch(p);
    case updateManagedBot::ID:
      return updateManagedBot::fetch(p);
    case updateBotGuestChatQuery::ID:
      return updateBotGuestChatQuery::fetch(p);
    case updateAiComposeTones::ID:
      return updateAiComposeTones::fetch(p);
    case updateJoinChatWebViewDecision::ID:
      return updateJoinChatWebViewDecision::fetch(p);
    case updateNewBotConnection::ID:
      return updateNewBotConnection::fetch(p);
    case updateWebBrowserSettings::ID:
      return updateWebBrowserSettings::fetch(p);
    case updateWebBrowserException::ID:
      return updateWebBrowserException::fetch(p);
    case updateNewEphemeralMessage::ID:
      return updateNewEphemeralMessage::fetch(p);
    case updateDeleteEphemeralMessages::ID:
      return updateDeleteEphemeralMessages::fetch(p);
    case updateEditEphemeralMessage::ID:
      return updateEditEphemeralMessage::fetch(p);
    case updateEphemeralBotCallbackQuery::ID:
      return updateEphemeralBotCallbackQuery::fetch(p);
    case updateBotStarsSubscription::ID:
      return updateBotStarsSubscription::fetch(p);
    case updateWalletState::ID:
      return updateWalletState::fetch(p);
    case updateSentWalletTransaction::ID:
      return updateSentWalletTransaction::fetch(p);
    case updateWalletGaslessInfo::ID:
      return updateWalletGaslessInfo::fetch(p);
    case updateWalletTonConnectSession::ID:
      return updateWalletTonConnectSession::fetch(p);
    case updateWalletTonConnectPendingDisconnect::ID:
      return updateWalletTonConnectPendingDisconnect::fetch(p);
    case updateEditForumTopic::ID:
      return updateEditForumTopic::fetch(p);
    case updateBotWidgetQuery::ID:
      return updateBotWidgetQuery::fetch(p);
    case updateInlineBotWidgetQuery::ID:
      return updateInlineBotWidgetQuery::fetch(p);
    case updateBotWidgetCopyQuery::ID:
      return updateBotWidgetCopyQuery::fetch(p);
    case updateMessageWidgetData::ID:
      return updateMessageWidgetData::fetch(p);
    case updateTranscribedAudioFile::ID:
      return updateTranscribedAudioFile::fetch(p);
    case updatesTooLong::ID:
      return updatesTooLong::fetch(p);
    case updateShortMessage::ID:
      return updateShortMessage::fetch(p);
    case updateShortChatMessage::ID:
      return updateShortChatMessage::fetch(p);
    case updateShort::ID:
      return updateShort::fetch(p);
    case updatesCombined::ID:
      return updatesCombined::fetch(p);
    case updates::ID:
      return updates::fetch(p);
    case updateShortSentMessage::ID:
      return updateShortSentMessage::fetch(p);
    case urlAuthResultRequest::ID:
      return urlAuthResultRequest::fetch(p);
    case urlAuthResultAccepted::ID:
      return urlAuthResultAccepted::fetch(p);
    case urlAuthResultDefault::ID:
      return urlAuthResultDefault::fetch(p);
    case userEmpty::ID:
      return userEmpty::fetch(p);
    case user::ID:
      return user::fetch(p);
    case userFull::ID:
      return userFull::fetch(p);
    case userProfilePhotoEmpty::ID:
      return userProfilePhotoEmpty::fetch(p);
    case userProfilePhoto::ID:
      return userProfilePhoto::fetch(p);
    case userStatusEmpty::ID:
      return userStatusEmpty::fetch(p);
    case userStatusOnline::ID:
      return userStatusOnline::fetch(p);
    case userStatusOffline::ID:
      return userStatusOffline::fetch(p);
    case userStatusRecently::ID:
      return userStatusRecently::fetch(p);
    case userStatusLastWeek::ID:
      return userStatusLastWeek::fetch(p);
    case userStatusLastMonth::ID:
      return userStatusLastMonth::fetch(p);
    case userWallet::ID:
      return userWallet::fetch(p);
    case username::ID:
      return username::fetch(p);
    case videoSize::ID:
      return videoSize::fetch(p);
    case videoSizeEmojiMarkup::ID:
      return videoSizeEmojiMarkup::fetch(p);
    case videoSizeStickerMarkup::ID:
      return videoSizeStickerMarkup::fetch(p);
    case wallPaper::ID:
      return wallPaper::fetch(p);
    case wallPaperNoFile::ID:
      return wallPaperNoFile::fetch(p);
    case wallPaperSettings::ID:
      return wallPaperSettings::fetch(p);
    case walletOnchainGiftActionBuy::ID:
      return walletOnchainGiftActionBuy::fetch(p);
    case walletOnchainGiftActionDelist::ID:
      return walletOnchainGiftActionDelist::fetch(p);
    case walletOnchainGiftActionChangePrice::ID:
      return walletOnchainGiftActionChangePrice::fetch(p);
    case walletOnchainGiftActionOfferCreate::ID:
      return walletOnchainGiftActionOfferCreate::fetch(p);
    case walletOnchainGiftActionOfferAccept::ID:
      return walletOnchainGiftActionOfferAccept::fetch(p);
    case walletOnchainGiftActionOfferCancel::ID:
      return walletOnchainGiftActionOfferCancel::fetch(p);
    case walletOnchainGiftActionOfferDecline::ID:
      return walletOnchainGiftActionOfferDecline::fetch(p);
    case walletOnchainGiftActionOfferExpire::ID:
      return walletOnchainGiftActionOfferExpire::fetch(p);
    case walletStateEmpty::ID:
      return walletStateEmpty::fetch(p);
    case walletState::ID:
      return walletState::fetch(p);
    case walletTransaction::ID:
      return walletTransaction::fetch(p);
    case walletTransactionPeerUser::ID:
      return walletTransactionPeerUser::fetch(p);
    case walletTransactionPeerAddress::ID:
      return walletTransactionPeerAddress::fetch(p);
    case walletTransactionPeerOnramp::ID:
      return walletTransactionPeerOnramp::fetch(p);
    case walletTransactionPeerUnsupported::ID:
      return walletTransactionPeerUnsupported::fetch(p);
    case walletTransactionPeerChannel::ID:
      return walletTransactionPeerChannel::fetch(p);
    case walletTransactionPeerTelegramGift::ID:
      return walletTransactionPeerTelegramGift::fetch(p);
    case walletTransactionPeerOnchainGift::ID:
      return walletTransactionPeerOnchainGift::fetch(p);
    case walletUserAddress::ID:
      return walletUserAddress::fetch(p);
    case webAuthorization::ID:
      return webAuthorization::fetch(p);
    case webDocument::ID:
      return webDocument::fetch(p);
    case webDocumentNoProxy::ID:
      return webDocumentNoProxy::fetch(p);
    case webDomainException::ID:
      return webDomainException::fetch(p);
    case webPageEmpty::ID:
      return webPageEmpty::fetch(p);
    case webPagePending::ID:
      return webPagePending::fetch(p);
    case webPage::ID:
      return webPage::fetch(p);
    case webPageNotModified::ID:
      return webPageNotModified::fetch(p);
    case webPageAttributeTheme::ID:
      return webPageAttributeTheme::fetch(p);
    case webPageAttributeStory::ID:
      return webPageAttributeStory::fetch(p);
    case webPageAttributeStickerSet::ID:
      return webPageAttributeStickerSet::fetch(p);
    case webPageAttributeUniqueStarGift::ID:
      return webPageAttributeUniqueStarGift::fetch(p);
    case webPageAttributeStarGiftCollection::ID:
      return webPageAttributeStarGiftCollection::fetch(p);
    case webPageAttributeStarGiftAuction::ID:
      return webPageAttributeStarGiftAuction::fetch(p);
    case webPageAttributeAiComposeTone::ID:
      return webPageAttributeAiComposeTone::fetch(p);
    case webViewMessageSent::ID:
      return webViewMessageSent::fetch(p);
    case webViewResultUrl::ID:
      return webViewResultUrl::fetch(p);
    case widgetQueryTypeData::ID:
      return widgetQueryTypeData::fetch(p);
    case widgetQueryTypeSignData::ID:
      return widgetQueryTypeSignData::fetch(p);
    case widgetQueryTypeSentTransaction::ID:
      return widgetQueryTypeSentTransaction::fetch(p);
    case account_authorizationForm::ID:
      return account_authorizationForm::fetch(p);
    case account_authorizations::ID:
      return account_authorizations::fetch(p);
    case account_autoDownloadSettings::ID:
      return account_autoDownloadSettings::fetch(p);
    case account_autoSaveSettings::ID:
      return account_autoSaveSettings::fetch(p);
    case account_businessChatLinks::ID:
      return account_businessChatLinks::fetch(p);
    case account_chatThemesNotModified::ID:
      return account_chatThemesNotModified::fetch(p);
    case account_chatThemes::ID:
      return account_chatThemes::fetch(p);
    case account_connectedBots::ID:
      return account_connectedBots::fetch(p);
    case account_contentSettings::ID:
      return account_contentSettings::fetch(p);
    case account_emailVerified::ID:
      return account_emailVerified::fetch(p);
    case account_emailVerifiedLogin::ID:
      return account_emailVerifiedLogin::fetch(p);
    case account_emojiStatusesNotModified::ID:
      return account_emojiStatusesNotModified::fetch(p);
    case account_emojiStatuses::ID:
      return account_emojiStatuses::fetch(p);
    case account_paidMessagesRevenue::ID:
      return account_paidMessagesRevenue::fetch(p);
    case account_passkeyRegistrationOptions::ID:
      return account_passkeyRegistrationOptions::fetch(p);
    case account_passkeys::ID:
      return account_passkeys::fetch(p);
    case account_password::ID:
      return account_password::fetch(p);
    case account_passwordSettings::ID:
      return account_passwordSettings::fetch(p);
    case account_privacyRules::ID:
      return account_privacyRules::fetch(p);
    case account_resetPasswordFailedWait::ID:
      return account_resetPasswordFailedWait::fetch(p);
    case account_resetPasswordRequestedWait::ID:
      return account_resetPasswordRequestedWait::fetch(p);
    case account_resetPasswordOk::ID:
      return account_resetPasswordOk::fetch(p);
    case account_resolvedBusinessChatLinks::ID:
      return account_resolvedBusinessChatLinks::fetch(p);
    case account_savedMusicIdsNotModified::ID:
      return account_savedMusicIdsNotModified::fetch(p);
    case account_savedMusicIds::ID:
      return account_savedMusicIds::fetch(p);
    case account_savedRingtone::ID:
      return account_savedRingtone::fetch(p);
    case account_savedRingtoneConverted::ID:
      return account_savedRingtoneConverted::fetch(p);
    case account_savedRingtonesNotModified::ID:
      return account_savedRingtonesNotModified::fetch(p);
    case account_savedRingtones::ID:
      return account_savedRingtones::fetch(p);
    case account_sentEmailCode::ID:
      return account_sentEmailCode::fetch(p);
    case account_takeout::ID:
      return account_takeout::fetch(p);
    case account_themesNotModified::ID:
      return account_themesNotModified::fetch(p);
    case account_themes::ID:
      return account_themes::fetch(p);
    case account_tmpPassword::ID:
      return account_tmpPassword::fetch(p);
    case account_wallPapersNotModified::ID:
      return account_wallPapersNotModified::fetch(p);
    case account_wallPapers::ID:
      return account_wallPapers::fetch(p);
    case account_webAuthorizations::ID:
      return account_webAuthorizations::fetch(p);
    case account_webBrowserSettingsNotModified::ID:
      return account_webBrowserSettingsNotModified::fetch(p);
    case account_webBrowserSettings::ID:
      return account_webBrowserSettings::fetch(p);
    case aicompose_tonesNotModified::ID:
      return aicompose_tonesNotModified::fetch(p);
    case aicompose_tones::ID:
      return aicompose_tones::fetch(p);
    case auth_authorization::ID:
      return auth_authorization::fetch(p);
    case auth_authorizationSignUpRequired::ID:
      return auth_authorizationSignUpRequired::fetch(p);
    case auth_codeTypeSms::ID:
      return auth_codeTypeSms::fetch(p);
    case auth_codeTypeCall::ID:
      return auth_codeTypeCall::fetch(p);
    case auth_codeTypeFlashCall::ID:
      return auth_codeTypeFlashCall::fetch(p);
    case auth_codeTypeMissedCall::ID:
      return auth_codeTypeMissedCall::fetch(p);
    case auth_codeTypeFragmentSms::ID:
      return auth_codeTypeFragmentSms::fetch(p);
    case auth_exportedAuthorization::ID:
      return auth_exportedAuthorization::fetch(p);
    case auth_firebasePnvIntent::ID:
      return auth_firebasePnvIntent::fetch(p);
    case auth_loggedOut::ID:
      return auth_loggedOut::fetch(p);
    case auth_loginToken::ID:
      return auth_loginToken::fetch(p);
    case auth_loginTokenMigrateTo::ID:
      return auth_loginTokenMigrateTo::fetch(p);
    case auth_loginTokenSuccess::ID:
      return auth_loginTokenSuccess::fetch(p);
    case auth_passkeyLoginOptions::ID:
      return auth_passkeyLoginOptions::fetch(p);
    case auth_passwordRecovery::ID:
      return auth_passwordRecovery::fetch(p);
    case auth_sentCode::ID:
      return auth_sentCode::fetch(p);
    case auth_sentCodeSuccess::ID:
      return auth_sentCodeSuccess::fetch(p);
    case auth_sentCodePaymentRequired::ID:
      return auth_sentCodePaymentRequired::fetch(p);
    case auth_sentCodeTypeApp::ID:
      return auth_sentCodeTypeApp::fetch(p);
    case auth_sentCodeTypeSms::ID:
      return auth_sentCodeTypeSms::fetch(p);
    case auth_sentCodeTypeCall::ID:
      return auth_sentCodeTypeCall::fetch(p);
    case auth_sentCodeTypeFlashCall::ID:
      return auth_sentCodeTypeFlashCall::fetch(p);
    case auth_sentCodeTypeMissedCall::ID:
      return auth_sentCodeTypeMissedCall::fetch(p);
    case auth_sentCodeTypeEmailCode::ID:
      return auth_sentCodeTypeEmailCode::fetch(p);
    case auth_sentCodeTypeSetUpEmailRequired::ID:
      return auth_sentCodeTypeSetUpEmailRequired::fetch(p);
    case auth_sentCodeTypeFragmentSms::ID:
      return auth_sentCodeTypeFragmentSms::fetch(p);
    case auth_sentCodeTypeFirebaseSms::ID:
      return auth_sentCodeTypeFirebaseSms::fetch(p);
    case auth_sentCodeTypeSmsWord::ID:
      return auth_sentCodeTypeSmsWord::fetch(p);
    case auth_sentCodeTypeSmsPhrase::ID:
      return auth_sentCodeTypeSmsPhrase::fetch(p);
    case bots_accessSettings::ID:
      return bots_accessSettings::fetch(p);
    case bots_botInfo::ID:
      return bots_botInfo::fetch(p);
    case bots_exportedBotToken::ID:
      return bots_exportedBotToken::fetch(p);
    case bots_popularAppBots::ID:
      return bots_popularAppBots::fetch(p);
    case bots_previewInfo::ID:
      return bots_previewInfo::fetch(p);
    case bots_requestedButton::ID:
      return bots_requestedButton::fetch(p);
    case channels_adminLogResults::ID:
      return channels_adminLogResults::fetch(p);
    case channels_channelParticipant::ID:
      return channels_channelParticipant::fetch(p);
    case channels_channelParticipants::ID:
      return channels_channelParticipants::fetch(p);
    case channels_channelParticipantsNotModified::ID:
      return channels_channelParticipantsNotModified::fetch(p);
    case channels_sendAsPeers::ID:
      return channels_sendAsPeers::fetch(p);
    case channels_sponsoredMessageReportResultChooseOption::ID:
      return channels_sponsoredMessageReportResultChooseOption::fetch(p);
    case channels_sponsoredMessageReportResultAdsHidden::ID:
      return channels_sponsoredMessageReportResultAdsHidden::fetch(p);
    case channels_sponsoredMessageReportResultReported::ID:
      return channels_sponsoredMessageReportResultReported::fetch(p);
    case chatlists_chatlistInviteAlready::ID:
      return chatlists_chatlistInviteAlready::fetch(p);
    case chatlists_chatlistInvite::ID:
      return chatlists_chatlistInvite::fetch(p);
    case chatlists_chatlistUpdates::ID:
      return chatlists_chatlistUpdates::fetch(p);
    case chatlists_exportedChatlistInvite::ID:
      return chatlists_exportedChatlistInvite::fetch(p);
    case chatlists_exportedInvites::ID:
      return chatlists_exportedInvites::fetch(p);
    case communities_participantJoinedChats::ID:
      return communities_participantJoinedChats::fetch(p);
    case communities_peerLinkRequests::ID:
      return communities_peerLinkRequests::fetch(p);
    case contacts_blocked::ID:
      return contacts_blocked::fetch(p);
    case contacts_blockedSlice::ID:
      return contacts_blockedSlice::fetch(p);
    case contacts_contactBirthdays::ID:
      return contacts_contactBirthdays::fetch(p);
    case contacts_contactsNotModified::ID:
      return contacts_contactsNotModified::fetch(p);
    case contacts_contacts::ID:
      return contacts_contacts::fetch(p);
    case contacts_found::ID:
      return contacts_found::fetch(p);
    case contacts_importedContacts::ID:
      return contacts_importedContacts::fetch(p);
    case contacts_resolvedPeer::ID:
      return contacts_resolvedPeer::fetch(p);
    case contacts_sponsoredPeersEmpty::ID:
      return contacts_sponsoredPeersEmpty::fetch(p);
    case contacts_sponsoredPeers::ID:
      return contacts_sponsoredPeers::fetch(p);
    case contacts_topPeersNotModified::ID:
      return contacts_topPeersNotModified::fetch(p);
    case contacts_topPeers::ID:
      return contacts_topPeers::fetch(p);
    case contacts_topPeersDisabled::ID:
      return contacts_topPeersDisabled::fetch(p);
    case ephemeral_welcomeMessagesNotModified::ID:
      return ephemeral_welcomeMessagesNotModified::fetch(p);
    case ephemeral_welcomeMessages::ID:
      return ephemeral_welcomeMessages::fetch(p);
    case fragment_collectibleInfo::ID:
      return fragment_collectibleInfo::fetch(p);
    case help_appConfigNotModified::ID:
      return help_appConfigNotModified::fetch(p);
    case help_appConfig::ID:
      return help_appConfig::fetch(p);
    case help_appUpdate::ID:
      return help_appUpdate::fetch(p);
    case help_noAppUpdate::ID:
      return help_noAppUpdate::fetch(p);
    case help_configSimple::ID:
      return help_configSimple::fetch(p);
    case help_countriesListNotModified::ID:
      return help_countriesListNotModified::fetch(p);
    case help_countriesList::ID:
      return help_countriesList::fetch(p);
    case help_country::ID:
      return help_country::fetch(p);
    case help_countryCode::ID:
      return help_countryCode::fetch(p);
    case help_deepLinkInfoEmpty::ID:
      return help_deepLinkInfoEmpty::fetch(p);
    case help_deepLinkInfo::ID:
      return help_deepLinkInfo::fetch(p);
    case help_inviteText::ID:
      return help_inviteText::fetch(p);
    case help_passportConfigNotModified::ID:
      return help_passportConfigNotModified::fetch(p);
    case help_passportConfig::ID:
      return help_passportConfig::fetch(p);
    case help_peerColorOption::ID:
      return help_peerColorOption::fetch(p);
    case help_peerColorSet::ID:
      return help_peerColorSet::fetch(p);
    case help_peerColorProfileSet::ID:
      return help_peerColorProfileSet::fetch(p);
    case help_peerColorsNotModified::ID:
      return help_peerColorsNotModified::fetch(p);
    case help_peerColors::ID:
      return help_peerColors::fetch(p);
    case help_premiumPromo::ID:
      return help_premiumPromo::fetch(p);
    case help_promoDataEmpty::ID:
      return help_promoDataEmpty::fetch(p);
    case help_promoData::ID:
      return help_promoData::fetch(p);
    case help_recentMeUrls::ID:
      return help_recentMeUrls::fetch(p);
    case help_support::ID:
      return help_support::fetch(p);
    case help_supportName::ID:
      return help_supportName::fetch(p);
    case help_termsOfService::ID:
      return help_termsOfService::fetch(p);
    case help_termsOfServiceUpdateEmpty::ID:
      return help_termsOfServiceUpdateEmpty::fetch(p);
    case help_termsOfServiceUpdate::ID:
      return help_termsOfServiceUpdate::fetch(p);
    case help_timezonesListNotModified::ID:
      return help_timezonesListNotModified::fetch(p);
    case help_timezonesList::ID:
      return help_timezonesList::fetch(p);
    case help_userInfoEmpty::ID:
      return help_userInfoEmpty::fetch(p);
    case help_userInfo::ID:
      return help_userInfo::fetch(p);
    case messages_affectedFoundMessages::ID:
      return messages_affectedFoundMessages::fetch(p);
    case messages_affectedHistory::ID:
      return messages_affectedHistory::fetch(p);
    case messages_affectedMessages::ID:
      return messages_affectedMessages::fetch(p);
    case messages_allStickersNotModified::ID:
      return messages_allStickersNotModified::fetch(p);
    case messages_allStickers::ID:
      return messages_allStickers::fetch(p);
    case messages_archivedStickers::ID:
      return messages_archivedStickers::fetch(p);
    case messages_availableEffectsNotModified::ID:
      return messages_availableEffectsNotModified::fetch(p);
    case messages_availableEffects::ID:
      return messages_availableEffects::fetch(p);
    case messages_availableReactionsNotModified::ID:
      return messages_availableReactionsNotModified::fetch(p);
    case messages_availableReactions::ID:
      return messages_availableReactions::fetch(p);
    case messages_botApp::ID:
      return messages_botApp::fetch(p);
    case messages_botCallbackAnswer::ID:
      return messages_botCallbackAnswer::fetch(p);
    case messages_botPreparedInlineMessage::ID:
      return messages_botPreparedInlineMessage::fetch(p);
    case messages_botResults::ID:
      return messages_botResults::fetch(p);
    case messages_botWidgetQueryAnswer::ID:
      return messages_botWidgetQueryAnswer::fetch(p);
    case messages_chatAdminsWithInvites::ID:
      return messages_chatAdminsWithInvites::fetch(p);
    case messages_chatFull::ID:
      return messages_chatFull::fetch(p);
    case messages_chatInviteImporters::ID:
      return messages_chatInviteImporters::fetch(p);
    case messages_chatInviteJoinResultOk::ID:
      return messages_chatInviteJoinResultOk::fetch(p);
    case messages_chatInviteJoinResultWebView::ID:
      return messages_chatInviteJoinResultWebView::fetch(p);
    case messages_chats::ID:
      return messages_chats::fetch(p);
    case messages_chatsSlice::ID:
      return messages_chatsSlice::fetch(p);
    case messages_checkedHistoryImportPeer::ID:
      return messages_checkedHistoryImportPeer::fetch(p);
    case messages_composedMessageWithAI::ID:
      return messages_composedMessageWithAI::fetch(p);
    case messages_composedRichMessageWithAI::ID:
      return messages_composedRichMessageWithAI::fetch(p);
    case messages_dhConfigNotModified::ID:
      return messages_dhConfigNotModified::fetch(p);
    case messages_dhConfig::ID:
      return messages_dhConfig::fetch(p);
    case messages_dialogFilters::ID:
      return messages_dialogFilters::fetch(p);
    case messages_dialogs::ID:
      return messages_dialogs::fetch(p);
    case messages_dialogsSlice::ID:
      return messages_dialogsSlice::fetch(p);
    case messages_dialogsNotModified::ID:
      return messages_dialogsNotModified::fetch(p);
    case messages_discussionMessage::ID:
      return messages_discussionMessage::fetch(p);
    case messages_emojiGameUnavailable::ID:
      return messages_emojiGameUnavailable::fetch(p);
    case messages_emojiGameDiceInfo::ID:
      return messages_emojiGameDiceInfo::fetch(p);
    case messages_emojiGameOutcome::ID:
      return messages_emojiGameOutcome::fetch(p);
    case messages_emojiGroupsNotModified::ID:
      return messages_emojiGroupsNotModified::fetch(p);
    case messages_emojiGroups::ID:
      return messages_emojiGroups::fetch(p);
    case messages_exportedChatInvite::ID:
      return messages_exportedChatInvite::fetch(p);
    case messages_exportedChatInviteReplaced::ID:
      return messages_exportedChatInviteReplaced::fetch(p);
    case messages_exportedChatInvites::ID:
      return messages_exportedChatInvites::fetch(p);
    case messages_favedStickersNotModified::ID:
      return messages_favedStickersNotModified::fetch(p);
    case messages_favedStickers::ID:
      return messages_favedStickers::fetch(p);
    case messages_featuredStickersNotModified::ID:
      return messages_featuredStickersNotModified::fetch(p);
    case messages_featuredStickers::ID:
      return messages_featuredStickers::fetch(p);
    case messages_forumTopics::ID:
      return messages_forumTopics::fetch(p);
    case messages_foundStickerSetsNotModified::ID:
      return messages_foundStickerSetsNotModified::fetch(p);
    case messages_foundStickerSets::ID:
      return messages_foundStickerSets::fetch(p);
    case messages_foundStickersNotModified::ID:
      return messages_foundStickersNotModified::fetch(p);
    case messages_foundStickers::ID:
      return messages_foundStickers::fetch(p);
    case messages_highScores::ID:
      return messages_highScores::fetch(p);
    case messages_historyImport::ID:
      return messages_historyImport::fetch(p);
    case messages_historyImportParsed::ID:
      return messages_historyImportParsed::fetch(p);
    case messages_inactiveChats::ID:
      return messages_inactiveChats::fetch(p);
    case messages_invitedUsers::ID:
      return messages_invitedUsers::fetch(p);
    case messages_messageEditData::ID:
      return messages_messageEditData::fetch(p);
    case messages_messageReactionsList::ID:
      return messages_messageReactionsList::fetch(p);
    case messages_messageViews::ID:
      return messages_messageViews::fetch(p);
    case messages_messages::ID:
      return messages_messages::fetch(p);
    case messages_messagesSlice::ID:
      return messages_messagesSlice::fetch(p);
    case messages_channelMessages::ID:
      return messages_channelMessages::fetch(p);
    case messages_messagesNotModified::ID:
      return messages_messagesNotModified::fetch(p);
    case messages_myStickers::ID:
      return messages_myStickers::fetch(p);
    case messages_peerDialogs::ID:
      return messages_peerDialogs::fetch(p);
    case messages_peerSettings::ID:
      return messages_peerSettings::fetch(p);
    case messages_preparedInlineMessage::ID:
      return messages_preparedInlineMessage::fetch(p);
    case messages_quickReplies::ID:
      return messages_quickReplies::fetch(p);
    case messages_quickRepliesNotModified::ID:
      return messages_quickRepliesNotModified::fetch(p);
    case messages_reactionsNotModified::ID:
      return messages_reactionsNotModified::fetch(p);
    case messages_reactions::ID:
      return messages_reactions::fetch(p);
    case messages_recentStickersNotModified::ID:
      return messages_recentStickersNotModified::fetch(p);
    case messages_recentStickers::ID:
      return messages_recentStickers::fetch(p);
    case messages_savedDialogs::ID:
      return messages_savedDialogs::fetch(p);
    case messages_savedDialogsSlice::ID:
      return messages_savedDialogsSlice::fetch(p);
    case messages_savedDialogsNotModified::ID:
      return messages_savedDialogsNotModified::fetch(p);
    case messages_savedGifsNotModified::ID:
      return messages_savedGifsNotModified::fetch(p);
    case messages_savedGifs::ID:
      return messages_savedGifs::fetch(p);
    case messages_savedReactionTagsNotModified::ID:
      return messages_savedReactionTagsNotModified::fetch(p);
    case messages_savedReactionTags::ID:
      return messages_savedReactionTags::fetch(p);
    case messages_searchCounter::ID:
      return messages_searchCounter::fetch(p);
    case messages_searchResultsCalendar::ID:
      return messages_searchResultsCalendar::fetch(p);
    case messages_searchResultsPositions::ID:
      return messages_searchResultsPositions::fetch(p);
    case messages_sentEncryptedMessage::ID:
      return messages_sentEncryptedMessage::fetch(p);
    case messages_sentEncryptedFile::ID:
      return messages_sentEncryptedFile::fetch(p);
    case messages_sponsoredMessages::ID:
      return messages_sponsoredMessages::fetch(p);
    case messages_sponsoredMessagesEmpty::ID:
      return messages_sponsoredMessagesEmpty::fetch(p);
    case messages_stickerSet::ID:
      return messages_stickerSet::fetch(p);
    case messages_stickerSetNotModified::ID:
      return messages_stickerSetNotModified::fetch(p);
    case messages_stickerSetInstallResultSuccess::ID:
      return messages_stickerSetInstallResultSuccess::fetch(p);
    case messages_stickerSetInstallResultArchive::ID:
      return messages_stickerSetInstallResultArchive::fetch(p);
    case messages_stickersNotModified::ID:
      return messages_stickersNotModified::fetch(p);
    case messages_stickers::ID:
      return messages_stickers::fetch(p);
    case messages_transcribedAudio::ID:
      return messages_transcribedAudio::fetch(p);
    case messages_translatedRichMessage::ID:
      return messages_translatedRichMessage::fetch(p);
    case messages_translateResult::ID:
      return messages_translateResult::fetch(p);
    case messages_votesList::ID:
      return messages_votesList::fetch(p);
    case messages_webPage::ID:
      return messages_webPage::fetch(p);
    case messages_webPagePreview::ID:
      return messages_webPagePreview::fetch(p);
    case messages_widgetPublicDataNotModified::ID:
      return messages_widgetPublicDataNotModified::fetch(p);
    case messages_widgetPublicData::ID:
      return messages_widgetPublicData::fetch(p);
    case payments_bankCardData::ID:
      return payments_bankCardData::fetch(p);
    case payments_checkCanSendGiftResultOk::ID:
      return payments_checkCanSendGiftResultOk::fetch(p);
    case payments_checkCanSendGiftResultFail::ID:
      return payments_checkCanSendGiftResultFail::fetch(p);
    case payments_checkedGiftCode::ID:
      return payments_checkedGiftCode::fetch(p);
    case payments_connectedStarRefBots::ID:
      return payments_connectedStarRefBots::fetch(p);
    case payments_currencyRates::ID:
      return payments_currencyRates::fetch(p);
    case payments_exportedInvoice::ID:
      return payments_exportedInvoice::fetch(p);
    case payments_giveawayInfo::ID:
      return payments_giveawayInfo::fetch(p);
    case payments_giveawayInfoResults::ID:
      return payments_giveawayInfoResults::fetch(p);
    case payments_paymentForm::ID:
      return payments_paymentForm::fetch(p);
    case payments_paymentFormStars::ID:
      return payments_paymentFormStars::fetch(p);
    case payments_paymentFormStarGift::ID:
      return payments_paymentFormStarGift::fetch(p);
    case payments_paymentReceipt::ID:
      return payments_paymentReceipt::fetch(p);
    case payments_paymentReceiptStars::ID:
      return payments_paymentReceiptStars::fetch(p);
    case payments_paymentResult::ID:
      return payments_paymentResult::fetch(p);
    case payments_paymentVerificationNeeded::ID:
      return payments_paymentVerificationNeeded::fetch(p);
    case payments_resaleStarGifts::ID:
      return payments_resaleStarGifts::fetch(p);
    case payments_savedInfo::ID:
      return payments_savedInfo::fetch(p);
    case payments_savedStarGifts::ID:
      return payments_savedStarGifts::fetch(p);
    case payments_starGiftActiveAuctionsNotModified::ID:
      return payments_starGiftActiveAuctionsNotModified::fetch(p);
    case payments_starGiftActiveAuctions::ID:
      return payments_starGiftActiveAuctions::fetch(p);
    case payments_starGiftAuctionAcquiredGifts::ID:
      return payments_starGiftAuctionAcquiredGifts::fetch(p);
    case payments_starGiftAuctionState::ID:
      return payments_starGiftAuctionState::fetch(p);
    case payments_starGiftCollectionsNotModified::ID:
      return payments_starGiftCollectionsNotModified::fetch(p);
    case payments_starGiftCollections::ID:
      return payments_starGiftCollections::fetch(p);
    case payments_starGiftDepositPayload::ID:
      return payments_starGiftDepositPayload::fetch(p);
    case payments_starGiftOnchainOfferTx::ID:
      return payments_starGiftOnchainOfferTx::fetch(p);
    case payments_starGiftOnchainOfferTxInitState::ID:
      return payments_starGiftOnchainOfferTxInitState::fetch(p);
    case payments_starGiftOnchainOfferTxMessage::ID:
      return payments_starGiftOnchainOfferTxMessage::fetch(p);
    case payments_starGiftOnchainSalePayload::ID:
      return payments_starGiftOnchainSalePayload::fetch(p);
    case payments_starGiftOnchainFixedSalePayload::ID:
      return payments_starGiftOnchainFixedSalePayload::fetch(p);
    case payments_starGiftUpgradeAttributes::ID:
      return payments_starGiftUpgradeAttributes::fetch(p);
    case payments_starGiftUpgradePreview::ID:
      return payments_starGiftUpgradePreview::fetch(p);
    case payments_starGiftWithdrawalUrl::ID:
      return payments_starGiftWithdrawalUrl::fetch(p);
    case payments_starGiftsNotModified::ID:
      return payments_starGiftsNotModified::fetch(p);
    case payments_starGifts::ID:
      return payments_starGifts::fetch(p);
    case payments_starsRevenueAdsAccountUrl::ID:
      return payments_starsRevenueAdsAccountUrl::fetch(p);
    case payments_starsRevenueStats::ID:
      return payments_starsRevenueStats::fetch(p);
    case payments_starsRevenueWithdrawalUrl::ID:
      return payments_starsRevenueWithdrawalUrl::fetch(p);
    case payments_starsStatus::ID:
      return payments_starsStatus::fetch(p);
    case payments_suggestedStarRefBots::ID:
      return payments_suggestedStarRefBots::fetch(p);
    case payments_uniqueStarGift::ID:
      return payments_uniqueStarGift::fetch(p);
    case payments_uniqueStarGiftValueInfo::ID:
      return payments_uniqueStarGiftValueInfo::fetch(p);
    case payments_validatedRequestedInfo::ID:
      return payments_validatedRequestedInfo::fetch(p);
    case phone_exportedGroupCallInvite::ID:
      return phone_exportedGroupCallInvite::fetch(p);
    case phone_groupCall::ID:
      return phone_groupCall::fetch(p);
    case phone_groupCallStars::ID:
      return phone_groupCallStars::fetch(p);
    case phone_groupCallStreamChannels::ID:
      return phone_groupCallStreamChannels::fetch(p);
    case phone_groupCallStreamRtmpUrl::ID:
      return phone_groupCallStreamRtmpUrl::fetch(p);
    case phone_groupParticipants::ID:
      return phone_groupParticipants::fetch(p);
    case phone_joinAsPeers::ID:
      return phone_joinAsPeers::fetch(p);
    case phone_phoneCall::ID:
      return phone_phoneCall::fetch(p);
    case photos_photo::ID:
      return photos_photo::fetch(p);
    case photos_photos::ID:
      return photos_photos::fetch(p);
    case photos_photosSlice::ID:
      return photos_photosSlice::fetch(p);
    case premium_boostsList::ID:
      return premium_boostsList::fetch(p);
    case premium_boostsStatus::ID:
      return premium_boostsStatus::fetch(p);
    case premium_myBoosts::ID:
      return premium_myBoosts::fetch(p);
    case smsjobs_eligibleToJoin::ID:
      return smsjobs_eligibleToJoin::fetch(p);
    case smsjobs_status::ID:
      return smsjobs_status::fetch(p);
    case stats_broadcastStats::ID:
      return stats_broadcastStats::fetch(p);
    case stats_megagroupStats::ID:
      return stats_megagroupStats::fetch(p);
    case stats_messageStats::ID:
      return stats_messageStats::fetch(p);
    case stats_pollStats::ID:
      return stats_pollStats::fetch(p);
    case stats_publicForwards::ID:
      return stats_publicForwards::fetch(p);
    case stats_storyStats::ID:
      return stats_storyStats::fetch(p);
    case stickers_suggestedShortName::ID:
      return stickers_suggestedShortName::fetch(p);
    case storage_fileUnknown::ID:
      return storage_fileUnknown::fetch(p);
    case storage_filePartial::ID:
      return storage_filePartial::fetch(p);
    case storage_fileJpeg::ID:
      return storage_fileJpeg::fetch(p);
    case storage_fileGif::ID:
      return storage_fileGif::fetch(p);
    case storage_filePng::ID:
      return storage_filePng::fetch(p);
    case storage_filePdf::ID:
      return storage_filePdf::fetch(p);
    case storage_fileMp3::ID:
      return storage_fileMp3::fetch(p);
    case storage_fileMov::ID:
      return storage_fileMov::fetch(p);
    case storage_fileMp4::ID:
      return storage_fileMp4::fetch(p);
    case storage_fileWebp::ID:
      return storage_fileWebp::fetch(p);
    case stories_albumsNotModified::ID:
      return stories_albumsNotModified::fetch(p);
    case stories_albums::ID:
      return stories_albums::fetch(p);
    case stories_allStoriesNotModified::ID:
      return stories_allStoriesNotModified::fetch(p);
    case stories_allStories::ID:
      return stories_allStories::fetch(p);
    case stories_canSendStoryCount::ID:
      return stories_canSendStoryCount::fetch(p);
    case stories_foundStories::ID:
      return stories_foundStories::fetch(p);
    case stories_peerStories::ID:
      return stories_peerStories::fetch(p);
    case stories_stories::ID:
      return stories_stories::fetch(p);
    case stories_storyReactionsList::ID:
      return stories_storyReactionsList::fetch(p);
    case stories_storyViews::ID:
      return stories_storyViews::fetch(p);
    case stories_storyViewsList::ID:
      return stories_storyViewsList::fetch(p);
    case toncenter_apiResponse::ID:
      return toncenter_apiResponse::fetch(p);
    case toncenter_streamingUrl::ID:
      return toncenter_streamingUrl::fetch(p);
    case updates_channelDifferenceEmpty::ID:
      return updates_channelDifferenceEmpty::fetch(p);
    case updates_channelDifferenceTooLong::ID:
      return updates_channelDifferenceTooLong::fetch(p);
    case updates_channelDifference::ID:
      return updates_channelDifference::fetch(p);
    case updates_differenceEmpty::ID:
      return updates_differenceEmpty::fetch(p);
    case updates_difference::ID:
      return updates_difference::fetch(p);
    case updates_differenceSlice::ID:
      return updates_differenceSlice::fetch(p);
    case updates_differenceTooLong::ID:
      return updates_differenceTooLong::fetch(p);
    case updates_state::ID:
      return updates_state::fetch(p);
    case upload_cdnFileReuploadNeeded::ID:
      return upload_cdnFileReuploadNeeded::fetch(p);
    case upload_cdnFile::ID:
      return upload_cdnFile::fetch(p);
    case upload_file::ID:
      return upload_file::fetch(p);
    case upload_fileCdnRedirect::ID:
      return upload_fileCdnRedirect::fetch(p);
    case upload_webFile::ID:
      return upload_webFile::fetch(p);
    case users_savedMusicNotModified::ID:
      return users_savedMusicNotModified::fetch(p);
    case users_savedMusic::ID:
      return users_savedMusic::fetch(p);
    case users_userFull::ID:
      return users_userFull::fetch(p);
    case users_users::ID:
      return users_users::fetch(p);
    case users_usersSlice::ID:
      return users_usersSlice::fetch(p);
    case wallet_card::ID:
      return wallet_card::fetch(p);
    case wallet_cardSticker::ID:
      return wallet_cardSticker::fetch(p);
    case wallet_encryptedSecretPhrasePart::ID:
      return wallet_encryptedSecretPhrasePart::fetch(p);
    case wallet_existingBalance::ID:
      return wallet_existingBalance::fetch(p);
    case wallet_holderDc::ID:
      return wallet_holderDc::fetch(p);
    case wallet_nftAttribute::ID:
      return wallet_nftAttribute::fetch(p);
    case wallet_nftItem::ID:
      return wallet_nftItem::fetch(p);
    case wallet_nftItems::ID:
      return wallet_nftItems::fetch(p);
    case wallet_proofChallenge::ID:
      return wallet_proofChallenge::fetch(p);
    case wallet_secretPhraseParts::ID:
      return wallet_secretPhraseParts::fetch(p);
    case wallet_tonConnectChallenge::ID:
      return wallet_tonConnectChallenge::fetch(p);
    case wallet_tonConnectPending::ID:
      return wallet_tonConnectPending::fetch(p);
    case wallet_tonConnectSessions::ID:
      return wallet_tonConnectSessions::fetch(p);
    case wallet_transactions::ID:
      return wallet_transactions::fetch(p);
    case wallet_userAddresses::ID:
      return wallet_userAddresses::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
