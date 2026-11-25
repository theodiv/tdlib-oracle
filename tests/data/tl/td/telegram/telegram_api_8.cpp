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


autoSaveSettings::autoSaveSettings()
  : flags_()
  , photos_()
  , videos_()
  , video_max_size_()
{}

autoSaveSettings::autoSaveSettings(int32 flags_, bool photos_, bool videos_, int64 video_max_size_)
  : flags_(flags_)
  , photos_(photos_)
  , videos_(videos_)
  , video_max_size_(video_max_size_)
{}

const std::int32_t autoSaveSettings::ID;

object_ptr<autoSaveSettings> autoSaveSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<autoSaveSettings> res = make_tl_object<autoSaveSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->photos_ = (var0 & 1) != 0;
  res->videos_ = (var0 & 2) != 0;
  if (var0 & 4) { res->video_max_size_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void autoSaveSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (photos_ << 0) | (videos_ << 1)), s);
  if (var0 & 4) { TlStoreBinary::store(video_max_size_, s); }
}

void autoSaveSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (photos_ << 0) | (videos_ << 1)), s);
  if (var0 & 4) { TlStoreBinary::store(video_max_size_, s); }
}

void autoSaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoSaveSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (photos_ << 0) | (videos_ << 1)));
    if (var0 & 1) { s.store_field("photos", true); }
    if (var0 & 2) { s.store_field("videos", true); }
    if (var0 & 4) { s.store_field("video_max_size", video_max_size_); }
    s.store_class_end();
  }
}

object_ptr<BusinessAwayMessageSchedule> BusinessAwayMessageSchedule::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case businessAwayMessageScheduleAlways::ID:
      return businessAwayMessageScheduleAlways::fetch(p);
    case businessAwayMessageScheduleOutsideWorkHours::ID:
      return businessAwayMessageScheduleOutsideWorkHours::fetch(p);
    case businessAwayMessageScheduleCustom::ID:
      return businessAwayMessageScheduleCustom::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t businessAwayMessageScheduleAlways::ID;

object_ptr<BusinessAwayMessageSchedule> businessAwayMessageScheduleAlways::fetch(TlBufferParser &p) {
  return make_tl_object<businessAwayMessageScheduleAlways>();
}

void businessAwayMessageScheduleAlways::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void businessAwayMessageScheduleAlways::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void businessAwayMessageScheduleAlways::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleAlways");
    s.store_class_end();
  }
}

const std::int32_t businessAwayMessageScheduleOutsideWorkHours::ID;

object_ptr<BusinessAwayMessageSchedule> businessAwayMessageScheduleOutsideWorkHours::fetch(TlBufferParser &p) {
  return make_tl_object<businessAwayMessageScheduleOutsideWorkHours>();
}

void businessAwayMessageScheduleOutsideWorkHours::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void businessAwayMessageScheduleOutsideWorkHours::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void businessAwayMessageScheduleOutsideWorkHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleOutsideWorkHours");
    s.store_class_end();
  }
}

businessAwayMessageScheduleCustom::businessAwayMessageScheduleCustom(int32 start_date_, int32 end_date_)
  : start_date_(start_date_)
  , end_date_(end_date_)
{}

const std::int32_t businessAwayMessageScheduleCustom::ID;

object_ptr<BusinessAwayMessageSchedule> businessAwayMessageScheduleCustom::fetch(TlBufferParser &p) {
  return make_tl_object<businessAwayMessageScheduleCustom>(p);
}

businessAwayMessageScheduleCustom::businessAwayMessageScheduleCustom(TlBufferParser &p)
  : start_date_(TlFetchInt::parse(p))
  , end_date_(TlFetchInt::parse(p))
{}

void businessAwayMessageScheduleCustom::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(start_date_, s);
  TlStoreBinary::store(end_date_, s);
}

void businessAwayMessageScheduleCustom::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(start_date_, s);
  TlStoreBinary::store(end_date_, s);
}

void businessAwayMessageScheduleCustom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleCustom");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_class_end();
  }
}

chatBannedRights::chatBannedRights()
  : flags_()
  , view_messages_()
  , send_messages_()
  , send_media_()
  , send_stickers_()
  , send_gifs_()
  , send_games_()
  , send_inline_()
  , embed_links_()
  , send_polls_()
  , change_info_()
  , invite_users_()
  , pin_messages_()
  , manage_topics_()
  , send_photos_()
  , send_videos_()
  , send_roundvideos_()
  , send_audios_()
  , send_voices_()
  , send_docs_()
  , send_plain_()
  , edit_rank_()
  , send_reactions_()
  , manage_linked_peers_()
  , until_date_()
{}

chatBannedRights::chatBannedRights(int32 flags_, bool view_messages_, bool send_messages_, bool send_media_, bool send_stickers_, bool send_gifs_, bool send_games_, bool send_inline_, bool embed_links_, bool send_polls_, bool change_info_, bool invite_users_, bool pin_messages_, bool manage_topics_, bool send_photos_, bool send_videos_, bool send_roundvideos_, bool send_audios_, bool send_voices_, bool send_docs_, bool send_plain_, bool edit_rank_, bool send_reactions_, bool manage_linked_peers_, int32 until_date_)
  : flags_(flags_)
  , view_messages_(view_messages_)
  , send_messages_(send_messages_)
  , send_media_(send_media_)
  , send_stickers_(send_stickers_)
  , send_gifs_(send_gifs_)
  , send_games_(send_games_)
  , send_inline_(send_inline_)
  , embed_links_(embed_links_)
  , send_polls_(send_polls_)
  , change_info_(change_info_)
  , invite_users_(invite_users_)
  , pin_messages_(pin_messages_)
  , manage_topics_(manage_topics_)
  , send_photos_(send_photos_)
  , send_videos_(send_videos_)
  , send_roundvideos_(send_roundvideos_)
  , send_audios_(send_audios_)
  , send_voices_(send_voices_)
  , send_docs_(send_docs_)
  , send_plain_(send_plain_)
  , edit_rank_(edit_rank_)
  , send_reactions_(send_reactions_)
  , manage_linked_peers_(manage_linked_peers_)
  , until_date_(until_date_)
{}

const std::int32_t chatBannedRights::ID;

object_ptr<chatBannedRights> chatBannedRights::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatBannedRights> res = make_tl_object<chatBannedRights>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->view_messages_ = (var0 & 1) != 0;
  res->send_messages_ = (var0 & 2) != 0;
  res->send_media_ = (var0 & 4) != 0;
  res->send_stickers_ = (var0 & 8) != 0;
  res->send_gifs_ = (var0 & 16) != 0;
  res->send_games_ = (var0 & 32) != 0;
  res->send_inline_ = (var0 & 64) != 0;
  res->embed_links_ = (var0 & 128) != 0;
  res->send_polls_ = (var0 & 256) != 0;
  res->change_info_ = (var0 & 1024) != 0;
  res->invite_users_ = (var0 & 32768) != 0;
  res->pin_messages_ = (var0 & 131072) != 0;
  res->manage_topics_ = (var0 & 262144) != 0;
  res->send_photos_ = (var0 & 524288) != 0;
  res->send_videos_ = (var0 & 1048576) != 0;
  res->send_roundvideos_ = (var0 & 2097152) != 0;
  res->send_audios_ = (var0 & 4194304) != 0;
  res->send_voices_ = (var0 & 8388608) != 0;
  res->send_docs_ = (var0 & 16777216) != 0;
  res->send_plain_ = (var0 & 33554432) != 0;
  res->edit_rank_ = (var0 & 67108864) != 0;
  res->send_reactions_ = (var0 & 134217728) != 0;
  res->manage_linked_peers_ = (var0 & 268435456) != 0;
  res->until_date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void chatBannedRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (view_messages_ << 0) | (send_messages_ << 1) | (send_media_ << 2) | (send_stickers_ << 3) | (send_gifs_ << 4) | (send_games_ << 5) | (send_inline_ << 6) | (embed_links_ << 7) | (send_polls_ << 8) | (change_info_ << 10) | (invite_users_ << 15) | (pin_messages_ << 17) | (manage_topics_ << 18) | (send_photos_ << 19) | (send_videos_ << 20) | (send_roundvideos_ << 21) | (send_audios_ << 22) | (send_voices_ << 23) | (send_docs_ << 24) | (send_plain_ << 25) | (edit_rank_ << 26) | (send_reactions_ << 27) | (manage_linked_peers_ << 28)), s);
  TlStoreBinary::store(until_date_, s);
}

void chatBannedRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (view_messages_ << 0) | (send_messages_ << 1) | (send_media_ << 2) | (send_stickers_ << 3) | (send_gifs_ << 4) | (send_games_ << 5) | (send_inline_ << 6) | (embed_links_ << 7) | (send_polls_ << 8) | (change_info_ << 10) | (invite_users_ << 15) | (pin_messages_ << 17) | (manage_topics_ << 18) | (send_photos_ << 19) | (send_videos_ << 20) | (send_roundvideos_ << 21) | (send_audios_ << 22) | (send_voices_ << 23) | (send_docs_ << 24) | (send_plain_ << 25) | (edit_rank_ << 26) | (send_reactions_ << 27) | (manage_linked_peers_ << 28)), s);
  TlStoreBinary::store(until_date_, s);
}

void chatBannedRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBannedRights");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (view_messages_ << 0) | (send_messages_ << 1) | (send_media_ << 2) | (send_stickers_ << 3) | (send_gifs_ << 4) | (send_games_ << 5) | (send_inline_ << 6) | (embed_links_ << 7) | (send_polls_ << 8) | (change_info_ << 10) | (invite_users_ << 15) | (pin_messages_ << 17) | (manage_topics_ << 18) | (send_photos_ << 19) | (send_videos_ << 20) | (send_roundvideos_ << 21) | (send_audios_ << 22) | (send_voices_ << 23) | (send_docs_ << 24) | (send_plain_ << 25) | (edit_rank_ << 26) | (send_reactions_ << 27) | (manage_linked_peers_ << 28)));
    if (var0 & 1) { s.store_field("view_messages", true); }
    if (var0 & 2) { s.store_field("send_messages", true); }
    if (var0 & 4) { s.store_field("send_media", true); }
    if (var0 & 8) { s.store_field("send_stickers", true); }
    if (var0 & 16) { s.store_field("send_gifs", true); }
    if (var0 & 32) { s.store_field("send_games", true); }
    if (var0 & 64) { s.store_field("send_inline", true); }
    if (var0 & 128) { s.store_field("embed_links", true); }
    if (var0 & 256) { s.store_field("send_polls", true); }
    if (var0 & 1024) { s.store_field("change_info", true); }
    if (var0 & 32768) { s.store_field("invite_users", true); }
    if (var0 & 131072) { s.store_field("pin_messages", true); }
    if (var0 & 262144) { s.store_field("manage_topics", true); }
    if (var0 & 524288) { s.store_field("send_photos", true); }
    if (var0 & 1048576) { s.store_field("send_videos", true); }
    if (var0 & 2097152) { s.store_field("send_roundvideos", true); }
    if (var0 & 4194304) { s.store_field("send_audios", true); }
    if (var0 & 8388608) { s.store_field("send_voices", true); }
    if (var0 & 16777216) { s.store_field("send_docs", true); }
    if (var0 & 33554432) { s.store_field("send_plain", true); }
    if (var0 & 67108864) { s.store_field("edit_rank", true); }
    if (var0 & 134217728) { s.store_field("send_reactions", true); }
    if (var0 & 268435456) { s.store_field("manage_linked_peers", true); }
    s.store_field("until_date", until_date_);
    s.store_class_end();
  }
}

dataJSON::dataJSON(string const &data_)
  : data_(data_)
{}

const std::int32_t dataJSON::ID;

object_ptr<dataJSON> dataJSON::fetch(TlBufferParser &p) {
  return make_tl_object<dataJSON>(p);
}

dataJSON::dataJSON(TlBufferParser &p)
  : data_(TlFetchString<string>::parse(p))
{}

void dataJSON::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
}

void dataJSON::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
}

void dataJSON::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dataJSON");
    s.store_field("data", data_);
    s.store_class_end();
  }
}

object_ptr<EncryptedChat> EncryptedChat::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t encryptedChatEmpty::ID;

object_ptr<EncryptedChat> encryptedChatEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedChatEmpty>(p);
}

encryptedChatEmpty::encryptedChatEmpty(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
{}

void encryptedChatEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedChatEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

encryptedChatWaiting::encryptedChatWaiting(int32 id_, int64 access_hash_, int32 date_, int64 admin_id_, int64 participant_id_)
  : id_(id_)
  , access_hash_(access_hash_)
  , date_(date_)
  , admin_id_(admin_id_)
  , participant_id_(participant_id_)
{}

const std::int32_t encryptedChatWaiting::ID;

object_ptr<EncryptedChat> encryptedChatWaiting::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedChatWaiting>(p);
}

encryptedChatWaiting::encryptedChatWaiting(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
  , admin_id_(TlFetchLong::parse(p))
  , participant_id_(TlFetchLong::parse(p))
{}

void encryptedChatWaiting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedChatWaiting");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_class_end();
  }
}

encryptedChatRequested::encryptedChatRequested()
  : flags_()
  , folder_id_()
  , id_()
  , access_hash_()
  , date_()
  , admin_id_()
  , participant_id_()
  , g_a_()
{}

encryptedChatRequested::encryptedChatRequested(int32 flags_, int32 folder_id_, int32 id_, int64 access_hash_, int32 date_, int64 admin_id_, int64 participant_id_, bytes &&g_a_)
  : flags_(flags_)
  , folder_id_(folder_id_)
  , id_(id_)
  , access_hash_(access_hash_)
  , date_(date_)
  , admin_id_(admin_id_)
  , participant_id_(participant_id_)
  , g_a_(std::move(g_a_))
{}

const std::int32_t encryptedChatRequested::ID;

object_ptr<EncryptedChat> encryptedChatRequested::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<encryptedChatRequested> res = make_tl_object<encryptedChatRequested>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->folder_id_ = TlFetchInt::parse(p); }
  res->id_ = TlFetchInt::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->participant_id_ = TlFetchLong::parse(p);
  res->g_a_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void encryptedChatRequested::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedChatRequested");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("folder_id", folder_id_); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_bytes_field("g_a", g_a_);
    s.store_class_end();
  }
}

encryptedChat::encryptedChat(int32 id_, int64 access_hash_, int32 date_, int64 admin_id_, int64 participant_id_, bytes &&g_a_or_b_, int64 key_fingerprint_)
  : id_(id_)
  , access_hash_(access_hash_)
  , date_(date_)
  , admin_id_(admin_id_)
  , participant_id_(participant_id_)
  , g_a_or_b_(std::move(g_a_or_b_))
  , key_fingerprint_(key_fingerprint_)
{}

const std::int32_t encryptedChat::ID;

object_ptr<EncryptedChat> encryptedChat::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedChat>(p);
}

encryptedChat::encryptedChat(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
  , admin_id_(TlFetchLong::parse(p))
  , participant_id_(TlFetchLong::parse(p))
  , g_a_or_b_(TlFetchBytes<bytes>::parse(p))
  , key_fingerprint_(TlFetchLong::parse(p))
{}

void encryptedChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedChat");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_bytes_field("g_a_or_b", g_a_or_b_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_class_end();
  }
}

encryptedChatDiscarded::encryptedChatDiscarded()
  : flags_()
  , history_deleted_()
  , id_()
{}

const std::int32_t encryptedChatDiscarded::ID;

object_ptr<EncryptedChat> encryptedChatDiscarded::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<encryptedChatDiscarded> res = make_tl_object<encryptedChatDiscarded>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->history_deleted_ = (var0 & 1) != 0;
  res->id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void encryptedChatDiscarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedChatDiscarded");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (history_deleted_ << 0)));
    if (var0 & 1) { s.store_field("history_deleted", true); }
    s.store_field("id", id_);
    s.store_class_end();
  }
}

const std::int32_t exportedContactToken::ID;

object_ptr<exportedContactToken> exportedContactToken::fetch(TlBufferParser &p) {
  return make_tl_object<exportedContactToken>(p);
}

exportedContactToken::exportedContactToken(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , expires_(TlFetchInt::parse(p))
{}

void exportedContactToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "exportedContactToken");
    s.store_field("url", url_);
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

inputBotAppID::inputBotAppID(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputBotAppID::ID;

void inputBotAppID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotAppID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotAppID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotAppID");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputBotAppShortName::inputBotAppShortName(object_ptr<InputUser> &&bot_id_, string const &short_name_)
  : bot_id_(std::move(bot_id_))
  , short_name_(short_name_)
{}

const std::int32_t inputBotAppShortName::ID;

void inputBotAppShortName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_id_, s);
  TlStoreString::store(short_name_, s);
}

void inputBotAppShortName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_id_, s);
  TlStoreString::store(short_name_, s);
}

void inputBotAppShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotAppShortName");
    s.store_object_field("bot_id", static_cast<const BaseObject *>(bot_id_.get()));
    s.store_field("short_name", short_name_);
    s.store_class_end();
  }
}

inputBotInlineResult::inputBotInlineResult(int32 flags_, string const &id_, string const &type_, string const &title_, string const &description_, string const &url_, object_ptr<inputWebDocument> &&thumb_, object_ptr<inputWebDocument> &&content_, object_ptr<InputBotInlineMessage> &&send_message_)
  : flags_(flags_)
  , id_(id_)
  , type_(type_)
  , title_(title_)
  , description_(description_)
  , url_(url_)
  , thumb_(std::move(thumb_))
  , content_(std::move(content_))
  , send_message_(std::move(send_message_))
{}

const std::int32_t inputBotInlineResult::ID;

void inputBotInlineResult::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 1) | ((!description_.empty()) << 2) | ((!url_.empty()) << 3) | ((thumb_ != nullptr) << 4) | ((content_ != nullptr) << 5)), s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreString::store(description_, s); }
  if (var0 & 8) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreObject, -1678949555>::store(thumb_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreObject, -1678949555>::store(content_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResult::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 1) | ((!description_.empty()) << 2) | ((!url_.empty()) << 3) | ((thumb_ != nullptr) << 4) | ((content_ != nullptr) << 5)), s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreString::store(description_, s); }
  if (var0 & 8) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreObject, -1678949555>::store(thumb_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreObject, -1678949555>::store(content_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineResult");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 1) | ((!description_.empty()) << 2) | ((!url_.empty()) << 3) | ((thumb_ != nullptr) << 4) | ((content_ != nullptr) << 5)));
    s.store_field("id", id_);
    s.store_field("type", type_);
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 4) { s.store_field("description", description_); }
    if (var0 & 8) { s.store_field("url", url_); }
    if (var0 & 16) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    if (var0 & 32) { s.store_object_field("content", static_cast<const BaseObject *>(content_.get())); }
    s.store_object_field("send_message", static_cast<const BaseObject *>(send_message_.get()));
    s.store_class_end();
  }
}

inputBotInlineResultPhoto::inputBotInlineResultPhoto(string const &id_, string const &type_, object_ptr<InputPhoto> &&photo_, object_ptr<InputBotInlineMessage> &&send_message_)
  : id_(id_)
  , type_(type_)
  , photo_(std::move(photo_))
  , send_message_(std::move(send_message_))
{}

const std::int32_t inputBotInlineResultPhoto::ID;

void inputBotInlineResultPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineResultPhoto");
    s.store_field("id", id_);
    s.store_field("type", type_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("send_message", static_cast<const BaseObject *>(send_message_.get()));
    s.store_class_end();
  }
}

inputBotInlineResultDocument::inputBotInlineResultDocument(int32 flags_, string const &id_, string const &type_, string const &title_, string const &description_, object_ptr<InputDocument> &&document_, object_ptr<InputBotInlineMessage> &&send_message_)
  : flags_(flags_)
  , id_(id_)
  , type_(type_)
  , title_(title_)
  , description_(description_)
  , document_(std::move(document_))
  , send_message_(std::move(send_message_))
{}

const std::int32_t inputBotInlineResultDocument::ID;

void inputBotInlineResultDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 1) | ((!description_.empty()) << 2)), s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreString::store(description_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 1) | ((!description_.empty()) << 2)), s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreString::store(description_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineResultDocument");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 1) | ((!description_.empty()) << 2)));
    s.store_field("id", id_);
    s.store_field("type", type_);
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 4) { s.store_field("description", description_); }
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("send_message", static_cast<const BaseObject *>(send_message_.get()));
    s.store_class_end();
  }
}

inputBotInlineResultGame::inputBotInlineResultGame(string const &id_, string const &short_name_, object_ptr<InputBotInlineMessage> &&send_message_)
  : id_(id_)
  , short_name_(short_name_)
  , send_message_(std::move(send_message_))
{}

const std::int32_t inputBotInlineResultGame::ID;

void inputBotInlineResultGame::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(short_name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultGame::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(short_name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineResultGame");
    s.store_field("id", id_);
    s.store_field("short_name", short_name_);
    s.store_object_field("send_message", static_cast<const BaseObject *>(send_message_.get()));
    s.store_class_end();
  }
}

inputPeerPhotoFileLocationLegacy::inputPeerPhotoFileLocationLegacy(int32 flags_, bool big_, object_ptr<InputPeer> &&peer_, int64 volume_id_, int32 local_id_)
  : flags_(flags_)
  , big_(big_)
  , peer_(std::move(peer_))
  , volume_id_(volume_id_)
  , local_id_(local_id_)
{}

const std::int32_t inputPeerPhotoFileLocationLegacy::ID;

void inputPeerPhotoFileLocationLegacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (big_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
}

void inputPeerPhotoFileLocationLegacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (big_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
}

void inputPeerPhotoFileLocationLegacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerPhotoFileLocationLegacy");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (big_ << 0)));
    if (var0 & 1) { s.store_field("big", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("volume_id", volume_id_);
    s.store_field("local_id", local_id_);
    s.store_class_end();
  }
}

inputStickerSetThumbLegacy::inputStickerSetThumbLegacy(object_ptr<InputStickerSet> &&stickerset_, int64 volume_id_, int32 local_id_)
  : stickerset_(std::move(stickerset_))
  , volume_id_(volume_id_)
  , local_id_(local_id_)
{}

const std::int32_t inputStickerSetThumbLegacy::ID;

void inputStickerSetThumbLegacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
}

void inputStickerSetThumbLegacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
}

void inputStickerSetThumbLegacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetThumbLegacy");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("volume_id", volume_id_);
    s.store_field("local_id", local_id_);
    s.store_class_end();
  }
}

inputFileLocation::inputFileLocation(int64 volume_id_, int32 local_id_, int64 secret_, bytes &&file_reference_)
  : volume_id_(volume_id_)
  , local_id_(local_id_)
  , secret_(secret_)
  , file_reference_(std::move(file_reference_))
{}

const std::int32_t inputFileLocation::ID;

void inputFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
  TlStoreBinary::store(secret_, s);
  TlStoreString::store(file_reference_, s);
}

void inputFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
  TlStoreBinary::store(secret_, s);
  TlStoreString::store(file_reference_, s);
}

void inputFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileLocation");
    s.store_field("volume_id", volume_id_);
    s.store_field("local_id", local_id_);
    s.store_field("secret", "[REDACTED]");
    s.store_bytes_field("file_reference", file_reference_);
    s.store_class_end();
  }
}

inputEncryptedFileLocation::inputEncryptedFileLocation(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputEncryptedFileLocation::ID;

void inputEncryptedFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedFileLocation");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputDocumentFileLocation::inputDocumentFileLocation(int64 id_, int64 access_hash_, bytes &&file_reference_, string const &thumb_size_)
  : id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
  , thumb_size_(thumb_size_)
{}

const std::int32_t inputDocumentFileLocation::ID;

void inputDocumentFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreString::store(thumb_size_, s);
}

void inputDocumentFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreString::store(thumb_size_, s);
}

void inputDocumentFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDocumentFileLocation");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_field("thumb_size", thumb_size_);
    s.store_class_end();
  }
}

inputSecureFileLocation::inputSecureFileLocation(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputSecureFileLocation::ID;

void inputSecureFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputSecureFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputSecureFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSecureFileLocation");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

const std::int32_t inputTakeoutFileLocation::ID;

void inputTakeoutFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputTakeoutFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputTakeoutFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputTakeoutFileLocation");
    s.store_class_end();
  }
}

inputPhotoFileLocation::inputPhotoFileLocation(int64 id_, int64 access_hash_, bytes &&file_reference_, string const &thumb_size_)
  : id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
  , thumb_size_(thumb_size_)
{}

const std::int32_t inputPhotoFileLocation::ID;

void inputPhotoFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreString::store(thumb_size_, s);
}

void inputPhotoFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreString::store(thumb_size_, s);
}

void inputPhotoFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhotoFileLocation");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_field("thumb_size", thumb_size_);
    s.store_class_end();
  }
}

inputPhotoLegacyFileLocation::inputPhotoLegacyFileLocation(int64 id_, int64 access_hash_, bytes &&file_reference_, int64 volume_id_, int32 local_id_, int64 secret_)
  : id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
  , volume_id_(volume_id_)
  , local_id_(local_id_)
  , secret_(secret_)
{}

const std::int32_t inputPhotoLegacyFileLocation::ID;

void inputPhotoLegacyFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
  TlStoreBinary::store(secret_, s);
}

void inputPhotoLegacyFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
  TlStoreBinary::store(secret_, s);
}

void inputPhotoLegacyFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhotoLegacyFileLocation");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_field("volume_id", volume_id_);
    s.store_field("local_id", local_id_);
    s.store_field("secret", "[REDACTED]");
    s.store_class_end();
  }
}

inputPeerPhotoFileLocation::inputPeerPhotoFileLocation(int32 flags_, bool big_, object_ptr<InputPeer> &&peer_, int64 photo_id_)
  : flags_(flags_)
  , big_(big_)
  , peer_(std::move(peer_))
  , photo_id_(photo_id_)
{}

const std::int32_t inputPeerPhotoFileLocation::ID;

void inputPeerPhotoFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (big_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(photo_id_, s);
}

void inputPeerPhotoFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (big_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(photo_id_, s);
}

void inputPeerPhotoFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerPhotoFileLocation");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (big_ << 0)));
    if (var0 & 1) { s.store_field("big", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("photo_id", photo_id_);
    s.store_class_end();
  }
}

inputStickerSetThumb::inputStickerSetThumb(object_ptr<InputStickerSet> &&stickerset_, int32 thumb_version_)
  : stickerset_(std::move(stickerset_))
  , thumb_version_(thumb_version_)
{}

const std::int32_t inputStickerSetThumb::ID;

void inputStickerSetThumb::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(thumb_version_, s);
}

void inputStickerSetThumb::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(thumb_version_, s);
}

void inputStickerSetThumb::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetThumb");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("thumb_version", thumb_version_);
    s.store_class_end();
  }
}

inputGroupCallStream::inputGroupCallStream(int32 flags_, object_ptr<InputGroupCall> &&call_, int64 time_ms_, int32 scale_, int32 video_channel_, int32 video_quality_)
  : flags_(flags_)
  , call_(std::move(call_))
  , time_ms_(time_ms_)
  , scale_(scale_)
  , video_channel_(video_channel_)
  , video_quality_(video_quality_)
{}

const std::int32_t inputGroupCallStream::ID;

void inputGroupCallStream::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(time_ms_, s);
  TlStoreBinary::store(scale_, s);
  if (var0 & 1) { TlStoreBinary::store(video_channel_, s); }
  if (var0 & 1) { TlStoreBinary::store(video_quality_, s); }
}

void inputGroupCallStream::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(time_ms_, s);
  TlStoreBinary::store(scale_, s);
  if (var0 & 1) { TlStoreBinary::store(video_channel_, s); }
  if (var0 & 1) { TlStoreBinary::store(video_quality_, s); }
}

void inputGroupCallStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCallStream");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("time_ms", time_ms_);
    s.store_field("scale", scale_);
    if (var0 & 1) { s.store_field("video_channel", video_channel_); }
    if (var0 & 1) { s.store_field("video_quality", video_quality_); }
    s.store_class_end();
  }
}

inputPaymentCredentialsSaved::inputPaymentCredentialsSaved(string const &id_, bytes &&tmp_password_)
  : id_(id_)
  , tmp_password_(std::move(tmp_password_))
{}

const std::int32_t inputPaymentCredentialsSaved::ID;

void inputPaymentCredentialsSaved::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(tmp_password_, s);
}

void inputPaymentCredentialsSaved::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(tmp_password_, s);
}

void inputPaymentCredentialsSaved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaymentCredentialsSaved");
    s.store_field("id", id_);
    s.store_field("tmp_password", "[REDACTED]");
    s.store_class_end();
  }
}

inputPaymentCredentials::inputPaymentCredentials(int32 flags_, bool save_, object_ptr<dataJSON> &&data_)
  : flags_(flags_)
  , save_(save_)
  , data_(std::move(data_))
{}

const std::int32_t inputPaymentCredentials::ID;

void inputPaymentCredentials::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (save_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(data_, s);
}

void inputPaymentCredentials::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (save_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(data_, s);
}

void inputPaymentCredentials::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaymentCredentials");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (save_ << 0)));
    if (var0 & 1) { s.store_field("save", true); }
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_class_end();
  }
}

inputPaymentCredentialsApplePay::inputPaymentCredentialsApplePay(object_ptr<dataJSON> &&payment_data_)
  : payment_data_(std::move(payment_data_))
{}

const std::int32_t inputPaymentCredentialsApplePay::ID;

void inputPaymentCredentialsApplePay::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(payment_data_, s);
}

void inputPaymentCredentialsApplePay::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(payment_data_, s);
}

void inputPaymentCredentialsApplePay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaymentCredentialsApplePay");
    s.store_field("payment_data", "[REDACTED]");
    s.store_class_end();
  }
}

inputPaymentCredentialsGooglePay::inputPaymentCredentialsGooglePay(object_ptr<dataJSON> &&payment_token_)
  : payment_token_(std::move(payment_token_))
{}

const std::int32_t inputPaymentCredentialsGooglePay::ID;

void inputPaymentCredentialsGooglePay::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(payment_token_, s);
}

void inputPaymentCredentialsGooglePay::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(payment_token_, s);
}

void inputPaymentCredentialsGooglePay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaymentCredentialsGooglePay");
    s.store_field("payment_token", "[REDACTED]");
    s.store_class_end();
  }
}

object_ptr<InputPeer> InputPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputPeerEmpty::ID;

object_ptr<InputPeer> inputPeerEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerEmpty>();
}

void inputPeerEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPeerEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPeerEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerEmpty");
    s.store_class_end();
  }
}

const std::int32_t inputPeerSelf::ID;

object_ptr<InputPeer> inputPeerSelf::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerSelf>();
}

void inputPeerSelf::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPeerSelf::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPeerSelf::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerSelf");
    s.store_class_end();
  }
}

inputPeerChat::inputPeerChat(int64 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t inputPeerChat::ID;

object_ptr<InputPeer> inputPeerChat::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerChat>(p);
}

inputPeerChat::inputPeerChat(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
{}

void inputPeerChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
}

void inputPeerChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
}

void inputPeerChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

inputPeerUser::inputPeerUser(int64 user_id_, int64 access_hash_)
  : user_id_(user_id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputPeerUser::ID;

object_ptr<InputPeer> inputPeerUser::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerUser>(p);
}

inputPeerUser::inputPeerUser(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputPeerUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPeerUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPeerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerUser");
    s.store_field("user_id", user_id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputPeerChannel::inputPeerChannel(int64 channel_id_, int64 access_hash_)
  : channel_id_(channel_id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputPeerChannel::ID;

object_ptr<InputPeer> inputPeerChannel::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerChannel>(p);
}

inputPeerChannel::inputPeerChannel(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputPeerChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPeerChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPeerChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerChannel");
    s.store_field("channel_id", channel_id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputPeerUserFromMessage::inputPeerUserFromMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 user_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , user_id_(user_id_)
{}

const std::int32_t inputPeerUserFromMessage::ID;

object_ptr<InputPeer> inputPeerUserFromMessage::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerUserFromMessage>(p);
}

inputPeerUserFromMessage::inputPeerUserFromMessage(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , user_id_(TlFetchLong::parse(p))
{}

void inputPeerUserFromMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(user_id_, s);
}

void inputPeerUserFromMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(user_id_, s);
}

void inputPeerUserFromMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerUserFromMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

inputPeerChannelFromMessage::inputPeerChannelFromMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 channel_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , channel_id_(channel_id_)
{}

const std::int32_t inputPeerChannelFromMessage::ID;

object_ptr<InputPeer> inputPeerChannelFromMessage::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerChannelFromMessage>(p);
}

inputPeerChannelFromMessage::inputPeerChannelFromMessage(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , channel_id_(TlFetchLong::parse(p))
{}

void inputPeerChannelFromMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(channel_id_, s);
}

void inputPeerChannelFromMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(channel_id_, s);
}

void inputPeerChannelFromMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerChannelFromMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("channel_id", channel_id_);
    s.store_class_end();
  }
}

inputQuickReplyShortcut::inputQuickReplyShortcut(string const &shortcut_)
  : shortcut_(shortcut_)
{}

const std::int32_t inputQuickReplyShortcut::ID;

void inputQuickReplyShortcut::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(shortcut_, s);
}

void inputQuickReplyShortcut::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(shortcut_, s);
}

void inputQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputQuickReplyShortcut");
    s.store_field("shortcut", shortcut_);
    s.store_class_end();
  }
}

inputQuickReplyShortcutId::inputQuickReplyShortcutId(int32 shortcut_id_)
  : shortcut_id_(shortcut_id_)
{}

const std::int32_t inputQuickReplyShortcutId::ID;

void inputQuickReplyShortcutId::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(shortcut_id_, s);
}

void inputQuickReplyShortcutId::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(shortcut_id_, s);
}

void inputQuickReplyShortcutId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputQuickReplyShortcutId");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

inputSecureValue::inputSecureValue(int32 flags_, object_ptr<SecureValueType> &&type_, object_ptr<secureData> &&data_, object_ptr<InputSecureFile> &&front_side_, object_ptr<InputSecureFile> &&reverse_side_, object_ptr<InputSecureFile> &&selfie_, array<object_ptr<InputSecureFile>> &&translation_, array<object_ptr<InputSecureFile>> &&files_, object_ptr<SecurePlainData> &&plain_data_)
  : flags_(flags_)
  , type_(std::move(type_))
  , data_(std::move(data_))
  , front_side_(std::move(front_side_))
  , reverse_side_(std::move(reverse_side_))
  , selfie_(std::move(selfie_))
  , translation_(std::move(translation_))
  , files_(std::move(files_))
  , plain_data_(std::move(plain_data_))
{}

const std::int32_t inputSecureValue::ID;

void inputSecureValue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((data_ != nullptr) << 0) | ((front_side_ != nullptr) << 1) | ((reverse_side_ != nullptr) << 2) | ((selfie_ != nullptr) << 3) | ((!translation_.empty()) << 6) | ((!files_.empty()) << 4) | ((plain_data_ != nullptr) << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1964327229>::store(data_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(front_side_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reverse_side_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(selfie_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(translation_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(files_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(plain_data_, s); }
}

void inputSecureValue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((data_ != nullptr) << 0) | ((front_side_ != nullptr) << 1) | ((reverse_side_ != nullptr) << 2) | ((selfie_ != nullptr) << 3) | ((!translation_.empty()) << 6) | ((!files_.empty()) << 4) | ((plain_data_ != nullptr) << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1964327229>::store(data_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(front_side_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reverse_side_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(selfie_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(translation_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(files_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(plain_data_, s); }
}

void inputSecureValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSecureValue");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((data_ != nullptr) << 0) | ((front_side_ != nullptr) << 1) | ((reverse_side_ != nullptr) << 2) | ((selfie_ != nullptr) << 3) | ((!translation_.empty()) << 6) | ((!files_.empty()) << 4) | ((plain_data_ != nullptr) << 5)));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    if (var0 & 1) { s.store_object_field("data", static_cast<const BaseObject *>(data_.get())); }
    if (var0 & 2) { s.store_object_field("front_side", static_cast<const BaseObject *>(front_side_.get())); }
    if (var0 & 4) { s.store_object_field("reverse_side", static_cast<const BaseObject *>(reverse_side_.get())); }
    if (var0 & 8) { s.store_object_field("selfie", static_cast<const BaseObject *>(selfie_.get())); }
    if (var0 & 64) { { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32) { s.store_object_field("plain_data", static_cast<const BaseObject *>(plain_data_.get())); }
    s.store_class_end();
  }
}

inputSingleMedia::inputSingleMedia(int32 flags_, object_ptr<InputMedia> &&media_, int64 random_id_, string const &message_, array<object_ptr<MessageEntity>> &&entities_)
  : flags_(flags_)
  , media_(std::move(media_))
  , random_id_(random_id_)
  , message_(message_)
  , entities_(std::move(entities_))
{}

const std::int32_t inputSingleMedia::ID;

void inputSingleMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!entities_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(message_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void inputSingleMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!entities_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(message_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void inputSingleMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSingleMedia");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!entities_.empty()) << 0)));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_field("random_id", random_id_);
    s.store_field("message", message_);
    if (var0 & 1) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

object_ptr<InputStickerSet> InputStickerSet::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputStickerSetEmpty::ID;

object_ptr<InputStickerSet> inputStickerSetEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetEmpty>();
}

void inputStickerSetEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetEmpty");
    s.store_class_end();
  }
}

inputStickerSetID::inputStickerSetID(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputStickerSetID::ID;

object_ptr<InputStickerSet> inputStickerSetID::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetID>(p);
}

inputStickerSetID::inputStickerSetID(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputStickerSetID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputStickerSetID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputStickerSetID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetID");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputStickerSetShortName::inputStickerSetShortName(string const &short_name_)
  : short_name_(short_name_)
{}

const std::int32_t inputStickerSetShortName::ID;

object_ptr<InputStickerSet> inputStickerSetShortName::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetShortName>(p);
}

inputStickerSetShortName::inputStickerSetShortName(TlBufferParser &p)
  : short_name_(TlFetchString<string>::parse(p))
{}

void inputStickerSetShortName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(short_name_, s);
}

void inputStickerSetShortName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(short_name_, s);
}

void inputStickerSetShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetShortName");
    s.store_field("short_name", short_name_);
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetAnimatedEmoji::ID;

object_ptr<InputStickerSet> inputStickerSetAnimatedEmoji::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetAnimatedEmoji>();
}

void inputStickerSetAnimatedEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetAnimatedEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetAnimatedEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetAnimatedEmoji");
    s.store_class_end();
  }
}

inputStickerSetDice::inputStickerSetDice(string const &emoticon_)
  : emoticon_(emoticon_)
{}

const std::int32_t inputStickerSetDice::ID;

object_ptr<InputStickerSet> inputStickerSetDice::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetDice>(p);
}

inputStickerSetDice::inputStickerSetDice(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
{}

void inputStickerSetDice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputStickerSetDice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputStickerSetDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetDice");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetAnimatedEmojiAnimations::ID;

object_ptr<InputStickerSet> inputStickerSetAnimatedEmojiAnimations::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetAnimatedEmojiAnimations>();
}

void inputStickerSetAnimatedEmojiAnimations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetAnimatedEmojiAnimations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetAnimatedEmojiAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetAnimatedEmojiAnimations");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetPremiumGifts::ID;

object_ptr<InputStickerSet> inputStickerSetPremiumGifts::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetPremiumGifts>();
}

void inputStickerSetPremiumGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetPremiumGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetPremiumGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetPremiumGifts");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetEmojiGenericAnimations::ID;

object_ptr<InputStickerSet> inputStickerSetEmojiGenericAnimations::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetEmojiGenericAnimations>();
}

void inputStickerSetEmojiGenericAnimations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiGenericAnimations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiGenericAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetEmojiGenericAnimations");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetEmojiDefaultStatuses::ID;

object_ptr<InputStickerSet> inputStickerSetEmojiDefaultStatuses::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetEmojiDefaultStatuses>();
}

void inputStickerSetEmojiDefaultStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiDefaultStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiDefaultStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetEmojiDefaultStatuses");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetEmojiDefaultTopicIcons::ID;

object_ptr<InputStickerSet> inputStickerSetEmojiDefaultTopicIcons::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetEmojiDefaultTopicIcons>();
}

void inputStickerSetEmojiDefaultTopicIcons::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiDefaultTopicIcons::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiDefaultTopicIcons::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetEmojiDefaultTopicIcons");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetEmojiChannelDefaultStatuses::ID;

object_ptr<InputStickerSet> inputStickerSetEmojiChannelDefaultStatuses::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetEmojiChannelDefaultStatuses>();
}

void inputStickerSetEmojiChannelDefaultStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiChannelDefaultStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiChannelDefaultStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetEmojiChannelDefaultStatuses");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetTonGifts::ID;

object_ptr<InputStickerSet> inputStickerSetTonGifts::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetTonGifts>();
}

void inputStickerSetTonGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetTonGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetTonGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetTonGifts");
    s.store_class_end();
  }
}

keyboardButtonStyle::keyboardButtonStyle()
  : flags_()
  , bg_primary_()
  , bg_danger_()
  , bg_success_()
  , icon_()
{}

keyboardButtonStyle::keyboardButtonStyle(int32 flags_, bool bg_primary_, bool bg_danger_, bool bg_success_, int64 icon_)
  : flags_(flags_)
  , bg_primary_(bg_primary_)
  , bg_danger_(bg_danger_)
  , bg_success_(bg_success_)
  , icon_(icon_)
{}

const std::int32_t keyboardButtonStyle::ID;

object_ptr<keyboardButtonStyle> keyboardButtonStyle::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonStyle> res = make_tl_object<keyboardButtonStyle>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bg_primary_ = (var0 & 1) != 0;
  res->bg_danger_ = (var0 & 2) != 0;
  res->bg_success_ = (var0 & 4) != 0;
  if (var0 & 8) { res->icon_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void keyboardButtonStyle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bg_primary_ << 0) | (bg_danger_ << 1) | (bg_success_ << 2)), s);
  if (var0 & 8) { TlStoreBinary::store(icon_, s); }
}

void keyboardButtonStyle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bg_primary_ << 0) | (bg_danger_ << 1) | (bg_success_ << 2)), s);
  if (var0 & 8) { TlStoreBinary::store(icon_, s); }
}

void keyboardButtonStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonStyle");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (bg_primary_ << 0) | (bg_danger_ << 1) | (bg_success_ << 2)));
    if (var0 & 1) { s.store_field("bg_primary", true); }
    if (var0 & 2) { s.store_field("bg_danger", true); }
    if (var0 & 4) { s.store_field("bg_success", true); }
    if (var0 & 8) { s.store_field("icon", icon_); }
    s.store_class_end();
  }
}

object_ptr<MediaArea> MediaArea::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

mediaAreaVenue::mediaAreaVenue(object_ptr<mediaAreaCoordinates> &&coordinates_, object_ptr<GeoPoint> &&geo_, string const &title_, string const &address_, string const &provider_, string const &venue_id_, string const &venue_type_)
  : coordinates_(std::move(coordinates_))
  , geo_(std::move(geo_))
  , title_(title_)
  , address_(address_)
  , provider_(provider_)
  , venue_id_(venue_id_)
  , venue_type_(venue_type_)
{}

const std::int32_t mediaAreaVenue::ID;

object_ptr<MediaArea> mediaAreaVenue::fetch(TlBufferParser &p) {
  return make_tl_object<mediaAreaVenue>(p);
}

mediaAreaVenue::mediaAreaVenue(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , geo_(TlFetchObject<GeoPoint>::parse(p))
  , title_(TlFetchString<string>::parse(p))
  , address_(TlFetchString<string>::parse(p))
  , provider_(TlFetchString<string>::parse(p))
  , venue_id_(TlFetchString<string>::parse(p))
  , venue_type_(TlFetchString<string>::parse(p))
{}

void mediaAreaVenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void mediaAreaVenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void mediaAreaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaVenue");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("venue_type", venue_type_);
    s.store_class_end();
  }
}

inputMediaAreaVenue::inputMediaAreaVenue(object_ptr<mediaAreaCoordinates> &&coordinates_, int64 query_id_, string const &result_id_)
  : coordinates_(std::move(coordinates_))
  , query_id_(query_id_)
  , result_id_(result_id_)
{}

const std::int32_t inputMediaAreaVenue::ID;

object_ptr<MediaArea> inputMediaAreaVenue::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaAreaVenue>(p);
}

inputMediaAreaVenue::inputMediaAreaVenue(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , query_id_(TlFetchLong::parse(p))
  , result_id_(TlFetchString<string>::parse(p))
{}

void inputMediaAreaVenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(result_id_, s);
}

void inputMediaAreaVenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(result_id_, s);
}

void inputMediaAreaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaAreaVenue");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_field("query_id", query_id_);
    s.store_field("result_id", result_id_);
    s.store_class_end();
  }
}

mediaAreaGeoPoint::mediaAreaGeoPoint()
  : flags_()
  , coordinates_()
  , geo_()
  , address_()
{}

mediaAreaGeoPoint::mediaAreaGeoPoint(int32 flags_, object_ptr<mediaAreaCoordinates> &&coordinates_, object_ptr<GeoPoint> &&geo_, object_ptr<geoPointAddress> &&address_)
  : flags_(flags_)
  , coordinates_(std::move(coordinates_))
  , geo_(std::move(geo_))
  , address_(std::move(address_))
{}

const std::int32_t mediaAreaGeoPoint::ID;

object_ptr<MediaArea> mediaAreaGeoPoint::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<mediaAreaGeoPoint> res = make_tl_object<mediaAreaGeoPoint>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->coordinates_ = TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p);
  res->geo_ = TlFetchObject<GeoPoint>::parse(p);
  if (var0 & 1) { res->address_ = TlFetchBoxed<TlFetchObject<geoPointAddress>, -565420653>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void mediaAreaGeoPoint::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((address_ != nullptr) << 0)), s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -565420653>::store(address_, s); }
}

void mediaAreaGeoPoint::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((address_ != nullptr) << 0)), s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -565420653>::store(address_, s); }
}

void mediaAreaGeoPoint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaGeoPoint");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((address_ != nullptr) << 0)));
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    if (var0 & 1) { s.store_object_field("address", static_cast<const BaseObject *>(address_.get())); }
    s.store_class_end();
  }
}

mediaAreaSuggestedReaction::mediaAreaSuggestedReaction()
  : flags_()
  , dark_()
  , flipped_()
  , coordinates_()
  , reaction_()
{}

mediaAreaSuggestedReaction::mediaAreaSuggestedReaction(int32 flags_, bool dark_, bool flipped_, object_ptr<mediaAreaCoordinates> &&coordinates_, object_ptr<Reaction> &&reaction_)
  : flags_(flags_)
  , dark_(dark_)
  , flipped_(flipped_)
  , coordinates_(std::move(coordinates_))
  , reaction_(std::move(reaction_))
{}

const std::int32_t mediaAreaSuggestedReaction::ID;

object_ptr<MediaArea> mediaAreaSuggestedReaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<mediaAreaSuggestedReaction> res = make_tl_object<mediaAreaSuggestedReaction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->dark_ = (var0 & 1) != 0;
  res->flipped_ = (var0 & 2) != 0;
  res->coordinates_ = TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p);
  res->reaction_ = TlFetchObject<Reaction>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void mediaAreaSuggestedReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0) | (flipped_ << 1)), s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void mediaAreaSuggestedReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0) | (flipped_ << 1)), s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void mediaAreaSuggestedReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaSuggestedReaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (dark_ << 0) | (flipped_ << 1)));
    if (var0 & 1) { s.store_field("dark", true); }
    if (var0 & 2) { s.store_field("flipped", true); }
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

mediaAreaChannelPost::mediaAreaChannelPost(object_ptr<mediaAreaCoordinates> &&coordinates_, int64 channel_id_, int32 msg_id_)
  : coordinates_(std::move(coordinates_))
  , channel_id_(channel_id_)
  , msg_id_(msg_id_)
{}

const std::int32_t mediaAreaChannelPost::ID;

object_ptr<MediaArea> mediaAreaChannelPost::fetch(TlBufferParser &p) {
  return make_tl_object<mediaAreaChannelPost>(p);
}

mediaAreaChannelPost::mediaAreaChannelPost(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , channel_id_(TlFetchLong::parse(p))
  , msg_id_(TlFetchInt::parse(p))
{}

void mediaAreaChannelPost::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(msg_id_, s);
}

void mediaAreaChannelPost::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(msg_id_, s);
}

void mediaAreaChannelPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaChannelPost");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_field("channel_id", channel_id_);
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

inputMediaAreaChannelPost::inputMediaAreaChannelPost(object_ptr<mediaAreaCoordinates> &&coordinates_, object_ptr<InputChannel> &&channel_, int32 msg_id_)
  : coordinates_(std::move(coordinates_))
  , channel_(std::move(channel_))
  , msg_id_(msg_id_)
{}

const std::int32_t inputMediaAreaChannelPost::ID;

object_ptr<MediaArea> inputMediaAreaChannelPost::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaAreaChannelPost>(p);
}

inputMediaAreaChannelPost::inputMediaAreaChannelPost(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , channel_(TlFetchObject<InputChannel>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
{}

void inputMediaAreaChannelPost::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void inputMediaAreaChannelPost::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void inputMediaAreaChannelPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaAreaChannelPost");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

mediaAreaUrl::mediaAreaUrl(object_ptr<mediaAreaCoordinates> &&coordinates_, string const &url_)
  : coordinates_(std::move(coordinates_))
  , url_(url_)
{}

const std::int32_t mediaAreaUrl::ID;

object_ptr<MediaArea> mediaAreaUrl::fetch(TlBufferParser &p) {
  return make_tl_object<mediaAreaUrl>(p);
}

mediaAreaUrl::mediaAreaUrl(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void mediaAreaUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(url_, s);
}

void mediaAreaUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(url_, s);
}

void mediaAreaUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaUrl");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_field("url", url_);
    s.store_class_end();
  }
}

mediaAreaWeather::mediaAreaWeather(object_ptr<mediaAreaCoordinates> &&coordinates_, string const &emoji_, double temperature_c_, int32 color_)
  : coordinates_(std::move(coordinates_))
  , emoji_(emoji_)
  , temperature_c_(temperature_c_)
  , color_(color_)
{}

const std::int32_t mediaAreaWeather::ID;

object_ptr<MediaArea> mediaAreaWeather::fetch(TlBufferParser &p) {
  return make_tl_object<mediaAreaWeather>(p);
}

mediaAreaWeather::mediaAreaWeather(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , emoji_(TlFetchString<string>::parse(p))
  , temperature_c_(TlFetchDouble::parse(p))
  , color_(TlFetchInt::parse(p))
{}

void mediaAreaWeather::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(emoji_, s);
  TlStoreBinary::store(temperature_c_, s);
  TlStoreBinary::store(color_, s);
}

void mediaAreaWeather::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(emoji_, s);
  TlStoreBinary::store(temperature_c_, s);
  TlStoreBinary::store(color_, s);
}

void mediaAreaWeather::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaWeather");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_field("emoji", emoji_);
    s.store_field("temperature_c", temperature_c_);
    s.store_field("color", color_);
    s.store_class_end();
  }
}

mediaAreaStarGift::mediaAreaStarGift(object_ptr<mediaAreaCoordinates> &&coordinates_, string const &slug_)
  : coordinates_(std::move(coordinates_))
  , slug_(slug_)
{}

const std::int32_t mediaAreaStarGift::ID;

object_ptr<MediaArea> mediaAreaStarGift::fetch(TlBufferParser &p) {
  return make_tl_object<mediaAreaStarGift>(p);
}

mediaAreaStarGift::mediaAreaStarGift(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , slug_(TlFetchString<string>::parse(p))
{}

void mediaAreaStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(slug_, s);
}

void mediaAreaStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(slug_, s);
}

void mediaAreaStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaStarGift");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

onrampMethodAvailability::onrampMethodAvailability()
  : flags_()
  , available_()
  , payment_method_()
{}

const std::int32_t onrampMethodAvailability::ID;

object_ptr<onrampMethodAvailability> onrampMethodAvailability::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<onrampMethodAvailability> res = make_tl_object<onrampMethodAvailability>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->available_ = (var0 & 1) != 0;
  res->payment_method_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void onrampMethodAvailability::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onrampMethodAvailability");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (available_ << 0)));
    if (var0 & 1) { s.store_field("available", true); }
    s.store_field("payment_method", payment_method_);
    s.store_class_end();
  }
}

object_ptr<PaidReactionPrivacy> PaidReactionPrivacy::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case paidReactionPrivacyDefault::ID:
      return paidReactionPrivacyDefault::fetch(p);
    case paidReactionPrivacyAnonymous::ID:
      return paidReactionPrivacyAnonymous::fetch(p);
    case paidReactionPrivacyPeer::ID:
      return paidReactionPrivacyPeer::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t paidReactionPrivacyDefault::ID;

object_ptr<PaidReactionPrivacy> paidReactionPrivacyDefault::fetch(TlBufferParser &p) {
  return make_tl_object<paidReactionPrivacyDefault>();
}

void paidReactionPrivacyDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void paidReactionPrivacyDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void paidReactionPrivacyDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionPrivacyDefault");
    s.store_class_end();
  }
}

const std::int32_t paidReactionPrivacyAnonymous::ID;

object_ptr<PaidReactionPrivacy> paidReactionPrivacyAnonymous::fetch(TlBufferParser &p) {
  return make_tl_object<paidReactionPrivacyAnonymous>();
}

void paidReactionPrivacyAnonymous::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void paidReactionPrivacyAnonymous::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void paidReactionPrivacyAnonymous::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionPrivacyAnonymous");
    s.store_class_end();
  }
}

paidReactionPrivacyPeer::paidReactionPrivacyPeer(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t paidReactionPrivacyPeer::ID;

object_ptr<PaidReactionPrivacy> paidReactionPrivacyPeer::fetch(TlBufferParser &p) {
  return make_tl_object<paidReactionPrivacyPeer>(p);
}

paidReactionPrivacyPeer::paidReactionPrivacyPeer(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
{}

void paidReactionPrivacyPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void paidReactionPrivacyPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void paidReactionPrivacyPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionPrivacyPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

const std::int32_t paymentCharge::ID;

object_ptr<paymentCharge> paymentCharge::fetch(TlBufferParser &p) {
  return make_tl_object<paymentCharge>(p);
}

paymentCharge::paymentCharge(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , provider_charge_id_(TlFetchString<string>::parse(p))
{}

void paymentCharge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentCharge");
    s.store_field("id", id_);
    s.store_field("provider_charge_id", provider_charge_id_);
    s.store_class_end();
  }
}

peerStories::peerStories()
  : flags_()
  , peer_()
  , max_read_id_()
  , stories_()
{}

const std::int32_t peerStories::ID;

object_ptr<peerStories> peerStories::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<peerStories> res = make_tl_object<peerStories>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->max_read_id_ = TlFetchInt::parse(p); }
  res->stories_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StoryItem>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void peerStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerStories");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("max_read_id", max_read_id_); }
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t pendingSuggestion::ID;

object_ptr<pendingSuggestion> pendingSuggestion::fetch(TlBufferParser &p) {
  return make_tl_object<pendingSuggestion>(p);
}

pendingSuggestion::pendingSuggestion(TlBufferParser &p)
  : suggestion_(TlFetchString<string>::parse(p))
  , title_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
  , description_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void pendingSuggestion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pendingSuggestion");
    s.store_field("suggestion", suggestion_);
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_field("url", url_);
    s.store_class_end();
  }
}

object_ptr<PostInteractionCounters> PostInteractionCounters::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case postInteractionCountersMessage::ID:
      return postInteractionCountersMessage::fetch(p);
    case postInteractionCountersStory::ID:
      return postInteractionCountersStory::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t postInteractionCountersMessage::ID;

object_ptr<PostInteractionCounters> postInteractionCountersMessage::fetch(TlBufferParser &p) {
  return make_tl_object<postInteractionCountersMessage>(p);
}

postInteractionCountersMessage::postInteractionCountersMessage(TlBufferParser &p)
  : msg_id_(TlFetchInt::parse(p))
  , views_(TlFetchInt::parse(p))
  , forwards_(TlFetchInt::parse(p))
  , reactions_(TlFetchInt::parse(p))
{}

void postInteractionCountersMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "postInteractionCountersMessage");
    s.store_field("msg_id", msg_id_);
    s.store_field("views", views_);
    s.store_field("forwards", forwards_);
    s.store_field("reactions", reactions_);
    s.store_class_end();
  }
}

const std::int32_t postInteractionCountersStory::ID;

object_ptr<PostInteractionCounters> postInteractionCountersStory::fetch(TlBufferParser &p) {
  return make_tl_object<postInteractionCountersStory>(p);
}

postInteractionCountersStory::postInteractionCountersStory(TlBufferParser &p)
  : story_id_(TlFetchInt::parse(p))
  , views_(TlFetchInt::parse(p))
  , forwards_(TlFetchInt::parse(p))
  , reactions_(TlFetchInt::parse(p))
{}

void postInteractionCountersStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "postInteractionCountersStory");
    s.store_field("story_id", story_id_);
    s.store_field("views", views_);
    s.store_field("forwards", forwards_);
    s.store_field("reactions", reactions_);
    s.store_class_end();
  }
}

const std::int32_t quickReply::ID;

object_ptr<quickReply> quickReply::fetch(TlBufferParser &p) {
  return make_tl_object<quickReply>(p);
}

quickReply::quickReply(TlBufferParser &p)
  : shortcut_id_(TlFetchInt::parse(p))
  , shortcut_(TlFetchString<string>::parse(p))
  , top_message_(TlFetchInt::parse(p))
  , count_(TlFetchInt::parse(p))
{}

void quickReply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "quickReply");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_field("shortcut", shortcut_);
    s.store_field("top_message", top_message_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

object_ptr<RichText> RichText::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t textEmpty::ID;

object_ptr<RichText> textEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<textEmpty>();
}

void textEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void textEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void textEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEmpty");
    s.store_class_end();
  }
}

textPlain::textPlain(string const &text_)
  : text_(text_)
{}

const std::int32_t textPlain::ID;

object_ptr<RichText> textPlain::fetch(TlBufferParser &p) {
  return make_tl_object<textPlain>(p);
}

textPlain::textPlain(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
{}

void textPlain::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
}

void textPlain::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
}

void textPlain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textPlain");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

textBold::textBold(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textBold::ID;

object_ptr<RichText> textBold::fetch(TlBufferParser &p) {
  return make_tl_object<textBold>(p);
}

textBold::textBold(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textBold::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textBold::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textBold::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textBold");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textItalic::textItalic(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textItalic::ID;

object_ptr<RichText> textItalic::fetch(TlBufferParser &p) {
  return make_tl_object<textItalic>(p);
}

textItalic::textItalic(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textItalic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textItalic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textItalic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textItalic");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textUnderline::textUnderline(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textUnderline::ID;

object_ptr<RichText> textUnderline::fetch(TlBufferParser &p) {
  return make_tl_object<textUnderline>(p);
}

textUnderline::textUnderline(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textUnderline::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textUnderline::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textUnderline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textUnderline");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textStrike::textStrike(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textStrike::ID;

object_ptr<RichText> textStrike::fetch(TlBufferParser &p) {
  return make_tl_object<textStrike>(p);
}

textStrike::textStrike(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textStrike::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textStrike::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textStrike::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textStrike");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textFixed::textFixed(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textFixed::ID;

object_ptr<RichText> textFixed::fetch(TlBufferParser &p) {
  return make_tl_object<textFixed>(p);
}

textFixed::textFixed(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textFixed::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textFixed::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textFixed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textFixed");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textUrl::textUrl(object_ptr<RichText> &&text_, string const &url_, int64 webpage_id_)
  : text_(std::move(text_))
  , url_(url_)
  , webpage_id_(webpage_id_)
{}

const std::int32_t textUrl::ID;

object_ptr<RichText> textUrl::fetch(TlBufferParser &p) {
  return make_tl_object<textUrl>(p);
}

textUrl::textUrl(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , url_(TlFetchString<string>::parse(p))
  , webpage_id_(TlFetchLong::parse(p))
{}

void textUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
}

void textUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
}

void textUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textUrl");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("url", url_);
    s.store_field("webpage_id", webpage_id_);
    s.store_class_end();
  }
}

textEmail::textEmail(object_ptr<RichText> &&text_, string const &email_)
  : text_(std::move(text_))
  , email_(email_)
{}

const std::int32_t textEmail::ID;

object_ptr<RichText> textEmail::fetch(TlBufferParser &p) {
  return make_tl_object<textEmail>(p);
}

textEmail::textEmail(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , email_(TlFetchString<string>::parse(p))
{}

void textEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(email_, s);
}

void textEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(email_, s);
}

void textEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEmail");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("email", email_);
    s.store_class_end();
  }
}

textConcat::textConcat(array<object_ptr<RichText>> &&texts_)
  : texts_(std::move(texts_))
{}

const std::int32_t textConcat::ID;

object_ptr<RichText> textConcat::fetch(TlBufferParser &p) {
  return make_tl_object<textConcat>(p);
}

textConcat::textConcat(TlBufferParser &p)
  : texts_(TlFetchBoxed<TlFetchVector<TlFetchObject<RichText>>, 481674261>::parse(p))
{}

void textConcat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(texts_, s);
}

void textConcat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(texts_, s);
}

void textConcat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textConcat");
    { s.store_vector_begin("texts", texts_.size()); for (const auto &_value : texts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

textSubscript::textSubscript(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textSubscript::ID;

object_ptr<RichText> textSubscript::fetch(TlBufferParser &p) {
  return make_tl_object<textSubscript>(p);
}

textSubscript::textSubscript(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textSubscript::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textSubscript::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textSubscript::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textSubscript");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textSuperscript::textSuperscript(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textSuperscript::ID;

object_ptr<RichText> textSuperscript::fetch(TlBufferParser &p) {
  return make_tl_object<textSuperscript>(p);
}

textSuperscript::textSuperscript(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textSuperscript::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textSuperscript::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textSuperscript::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textSuperscript");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textMarked::textMarked(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textMarked::ID;

object_ptr<RichText> textMarked::fetch(TlBufferParser &p) {
  return make_tl_object<textMarked>(p);
}

textMarked::textMarked(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textMarked::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textMarked::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textMarked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textMarked");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textPhone::textPhone(object_ptr<RichText> &&text_, string const &phone_)
  : text_(std::move(text_))
  , phone_(phone_)
{}

const std::int32_t textPhone::ID;

object_ptr<RichText> textPhone::fetch(TlBufferParser &p) {
  return make_tl_object<textPhone>(p);
}

textPhone::textPhone(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , phone_(TlFetchString<string>::parse(p))
{}

void textPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(phone_, s);
}

void textPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(phone_, s);
}

void textPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textPhone");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("phone", phone_);
    s.store_class_end();
  }
}

textImage::textImage(int64 document_id_, int32 w_, int32 h_)
  : document_id_(document_id_)
  , w_(w_)
  , h_(h_)
{}

const std::int32_t textImage::ID;

object_ptr<RichText> textImage::fetch(TlBufferParser &p) {
  return make_tl_object<textImage>(p);
}

textImage::textImage(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
  , w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
{}

void textImage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
}

void textImage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
}

void textImage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textImage");
    s.store_field("document_id", document_id_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_class_end();
  }
}

textAnchor::textAnchor(object_ptr<RichText> &&text_, string const &name_)
  : text_(std::move(text_))
  , name_(name_)
{}

const std::int32_t textAnchor::ID;

object_ptr<RichText> textAnchor::fetch(TlBufferParser &p) {
  return make_tl_object<textAnchor>(p);
}

textAnchor::textAnchor(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , name_(TlFetchString<string>::parse(p))
{}

void textAnchor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(name_, s);
}

void textAnchor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(name_, s);
}

void textAnchor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textAnchor");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("name", name_);
    s.store_class_end();
  }
}

textMath::textMath(string const &source_)
  : source_(source_)
{}

const std::int32_t textMath::ID;

object_ptr<RichText> textMath::fetch(TlBufferParser &p) {
  return make_tl_object<textMath>(p);
}

textMath::textMath(TlBufferParser &p)
  : source_(TlFetchString<string>::parse(p))
{}

void textMath::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(source_, s);
}

void textMath::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(source_, s);
}

void textMath::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textMath");
    s.store_field("source", source_);
    s.store_class_end();
  }
}

textCustomEmoji::textCustomEmoji(int64 document_id_, string const &alt_)
  : document_id_(document_id_)
  , alt_(alt_)
{}

const std::int32_t textCustomEmoji::ID;

object_ptr<RichText> textCustomEmoji::fetch(TlBufferParser &p) {
  return make_tl_object<textCustomEmoji>(p);
}

textCustomEmoji::textCustomEmoji(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
  , alt_(TlFetchString<string>::parse(p))
{}

void textCustomEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
  TlStoreString::store(alt_, s);
}

void textCustomEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
  TlStoreString::store(alt_, s);
}

void textCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textCustomEmoji");
    s.store_field("document_id", document_id_);
    s.store_field("alt", alt_);
    s.store_class_end();
  }
}

textSpoiler::textSpoiler(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textSpoiler::ID;

object_ptr<RichText> textSpoiler::fetch(TlBufferParser &p) {
  return make_tl_object<textSpoiler>(p);
}

textSpoiler::textSpoiler(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textSpoiler::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textSpoiler::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textSpoiler::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textSpoiler");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textMention::textMention(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textMention::ID;

object_ptr<RichText> textMention::fetch(TlBufferParser &p) {
  return make_tl_object<textMention>(p);
}

textMention::textMention(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textMention::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textMention::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textMention");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textHashtag::textHashtag(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textHashtag::ID;

object_ptr<RichText> textHashtag::fetch(TlBufferParser &p) {
  return make_tl_object<textHashtag>(p);
}

textHashtag::textHashtag(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textHashtag::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textHashtag::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textHashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textHashtag");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textBotCommand::textBotCommand(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textBotCommand::ID;

object_ptr<RichText> textBotCommand::fetch(TlBufferParser &p) {
  return make_tl_object<textBotCommand>(p);
}

textBotCommand::textBotCommand(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textBotCommand::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textBotCommand::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textBotCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textBotCommand");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textCashtag::textCashtag(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textCashtag::ID;

object_ptr<RichText> textCashtag::fetch(TlBufferParser &p) {
  return make_tl_object<textCashtag>(p);
}

textCashtag::textCashtag(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textCashtag::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textCashtag::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textCashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textCashtag");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textAutoUrl::textAutoUrl(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textAutoUrl::ID;

object_ptr<RichText> textAutoUrl::fetch(TlBufferParser &p) {
  return make_tl_object<textAutoUrl>(p);
}

textAutoUrl::textAutoUrl(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textAutoUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textAutoUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textAutoUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textAutoUrl");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textAutoEmail::textAutoEmail(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textAutoEmail::ID;

object_ptr<RichText> textAutoEmail::fetch(TlBufferParser &p) {
  return make_tl_object<textAutoEmail>(p);
}

textAutoEmail::textAutoEmail(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textAutoEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textAutoEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textAutoEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textAutoEmail");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textAutoPhone::textAutoPhone(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textAutoPhone::ID;

object_ptr<RichText> textAutoPhone::fetch(TlBufferParser &p) {
  return make_tl_object<textAutoPhone>(p);
}

textAutoPhone::textAutoPhone(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textAutoPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textAutoPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textAutoPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textAutoPhone");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textBankCard::textBankCard(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textBankCard::ID;

object_ptr<RichText> textBankCard::fetch(TlBufferParser &p) {
  return make_tl_object<textBankCard>(p);
}

textBankCard::textBankCard(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textBankCard::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textBankCard::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textBankCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textBankCard");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textMentionName::textMentionName(object_ptr<RichText> &&text_, int64 user_id_)
  : text_(std::move(text_))
  , user_id_(user_id_)
{}

const std::int32_t textMentionName::ID;

object_ptr<RichText> textMentionName::fetch(TlBufferParser &p) {
  return make_tl_object<textMentionName>(p);
}

textMentionName::textMentionName(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , user_id_(TlFetchLong::parse(p))
{}

void textMentionName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBinary::store(user_id_, s);
}

void textMentionName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBinary::store(user_id_, s);
}

void textMentionName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textMentionName");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

textDate::textDate()
  : flags_()
  , relative_()
  , short_time_()
  , long_time_()
  , short_date_()
  , long_date_()
  , day_of_week_()
  , text_()
  , date_()
{}

textDate::textDate(int32 flags_, bool relative_, bool short_time_, bool long_time_, bool short_date_, bool long_date_, bool day_of_week_, object_ptr<RichText> &&text_, int32 date_)
  : flags_(flags_)
  , relative_(relative_)
  , short_time_(short_time_)
  , long_time_(long_time_)
  , short_date_(short_date_)
  , long_date_(long_date_)
  , day_of_week_(day_of_week_)
  , text_(std::move(text_))
  , date_(date_)
{}

const std::int32_t textDate::ID;

object_ptr<RichText> textDate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<textDate> res = make_tl_object<textDate>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->relative_ = (var0 & 1) != 0;
  res->short_time_ = (var0 & 2) != 0;
  res->long_time_ = (var0 & 4) != 0;
  res->short_date_ = (var0 & 8) != 0;
  res->long_date_ = (var0 & 16) != 0;
  res->day_of_week_ = (var0 & 32) != 0;
  res->text_ = TlFetchObject<RichText>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void textDate::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (relative_ << 0) | (short_time_ << 1) | (long_time_ << 2) | (short_date_ << 3) | (long_date_ << 4) | (day_of_week_ << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBinary::store(date_, s);
}

void textDate::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (relative_ << 0) | (short_time_ << 1) | (long_time_ << 2) | (short_date_ << 3) | (long_date_ << 4) | (day_of_week_ << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBinary::store(date_, s);
}

void textDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textDate");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (relative_ << 0) | (short_time_ << 1) | (long_time_ << 2) | (short_date_ << 3) | (long_date_ << 4) | (day_of_week_ << 5)));
    if (var0 & 1) { s.store_field("relative", true); }
    if (var0 & 2) { s.store_field("short_time", true); }
    if (var0 & 4) { s.store_field("long_time", true); }
    if (var0 & 8) { s.store_field("short_date", true); }
    if (var0 & 16) { s.store_field("long_date", true); }
    if (var0 & 32) { s.store_field("day_of_week", true); }
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

textDiff::textDiff(object_ptr<RichText> &&text_, object_ptr<RichText> &&old_text_)
  : text_(std::move(text_))
  , old_text_(std::move(old_text_))
{}

const std::int32_t textDiff::ID;

object_ptr<RichText> textDiff::fetch(TlBufferParser &p) {
  return make_tl_object<textDiff>(p);
}

textDiff::textDiff(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , old_text_(TlFetchObject<RichText>::parse(p))
{}

void textDiff::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(old_text_, s);
}

void textDiff::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(old_text_, s);
}

void textDiff::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textDiff");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("old_text", static_cast<const BaseObject *>(old_text_.get()));
    s.store_class_end();
  }
}

textButton::textButton()
  : flags_()
  , text_()
  , type_()
  , style_()
{}

textButton::textButton(int32 flags_, object_ptr<RichText> &&text_, object_ptr<InlineButtonType> &&type_, object_ptr<richButtonStyle> &&style_)
  : flags_(flags_)
  , text_(std::move(text_))
  , type_(std::move(type_))
  , style_(std::move(style_))
{}

const std::int32_t textButton::ID;

object_ptr<RichText> textButton::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<textButton> res = make_tl_object<textButton>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->text_ = TlFetchObject<RichText>::parse(p);
  res->type_ = TlFetchObject<InlineButtonType>::parse(p);
  if (var0 & 1) { res->style_ = TlFetchBoxed<TlFetchObject<richButtonStyle>, 63312061>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void textButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((style_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 63312061>::store(style_, s); }
}

void textButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((style_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 63312061>::store(style_, s); }
}

void textButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textButton");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((style_ != nullptr) << 0)));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    if (var0 & 1) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_class_end();
  }
}

textTonAddress::textTonAddress(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textTonAddress::ID;

object_ptr<RichText> textTonAddress::fetch(TlBufferParser &p) {
  return make_tl_object<textTonAddress>(p);
}

textTonAddress::textTonAddress(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textTonAddress::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textTonAddress::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textTonAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textTonAddress");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

object_ptr<SendMessageAction> SendMessageAction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t sendMessageTypingAction::ID;

object_ptr<SendMessageAction> sendMessageTypingAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageTypingAction>();
}

void sendMessageTypingAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageTypingAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageTypingAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageTypingAction");
    s.store_class_end();
  }
}

const std::int32_t sendMessageCancelAction::ID;

object_ptr<SendMessageAction> sendMessageCancelAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageCancelAction>();
}

void sendMessageCancelAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageCancelAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageCancelAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageCancelAction");
    s.store_class_end();
  }
}

const std::int32_t sendMessageRecordVideoAction::ID;

object_ptr<SendMessageAction> sendMessageRecordVideoAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageRecordVideoAction>();
}

void sendMessageRecordVideoAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageRecordVideoAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageRecordVideoAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageRecordVideoAction");
    s.store_class_end();
  }
}

sendMessageUploadVideoAction::sendMessageUploadVideoAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageUploadVideoAction::ID;

object_ptr<SendMessageAction> sendMessageUploadVideoAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageUploadVideoAction>(p);
}

sendMessageUploadVideoAction::sendMessageUploadVideoAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageUploadVideoAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadVideoAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadVideoAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageUploadVideoAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

const std::int32_t sendMessageRecordAudioAction::ID;

object_ptr<SendMessageAction> sendMessageRecordAudioAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageRecordAudioAction>();
}

void sendMessageRecordAudioAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageRecordAudioAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageRecordAudioAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageRecordAudioAction");
    s.store_class_end();
  }
}

sendMessageUploadAudioAction::sendMessageUploadAudioAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageUploadAudioAction::ID;

object_ptr<SendMessageAction> sendMessageUploadAudioAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageUploadAudioAction>(p);
}

sendMessageUploadAudioAction::sendMessageUploadAudioAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageUploadAudioAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadAudioAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadAudioAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageUploadAudioAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

sendMessageUploadPhotoAction::sendMessageUploadPhotoAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageUploadPhotoAction::ID;

object_ptr<SendMessageAction> sendMessageUploadPhotoAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageUploadPhotoAction>(p);
}

sendMessageUploadPhotoAction::sendMessageUploadPhotoAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageUploadPhotoAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadPhotoAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadPhotoAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageUploadPhotoAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

sendMessageUploadDocumentAction::sendMessageUploadDocumentAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageUploadDocumentAction::ID;

object_ptr<SendMessageAction> sendMessageUploadDocumentAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageUploadDocumentAction>(p);
}

sendMessageUploadDocumentAction::sendMessageUploadDocumentAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageUploadDocumentAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadDocumentAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadDocumentAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageUploadDocumentAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

const std::int32_t sendMessageGeoLocationAction::ID;

object_ptr<SendMessageAction> sendMessageGeoLocationAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageGeoLocationAction>();
}

void sendMessageGeoLocationAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageGeoLocationAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageGeoLocationAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageGeoLocationAction");
    s.store_class_end();
  }
}

const std::int32_t sendMessageChooseContactAction::ID;

object_ptr<SendMessageAction> sendMessageChooseContactAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageChooseContactAction>();
}

void sendMessageChooseContactAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageChooseContactAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageChooseContactAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageChooseContactAction");
    s.store_class_end();
  }
}

const std::int32_t sendMessageGamePlayAction::ID;

object_ptr<SendMessageAction> sendMessageGamePlayAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageGamePlayAction>();
}

void sendMessageGamePlayAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageGamePlayAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageGamePlayAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageGamePlayAction");
    s.store_class_end();
  }
}

const std::int32_t sendMessageRecordRoundAction::ID;

object_ptr<SendMessageAction> sendMessageRecordRoundAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageRecordRoundAction>();
}

void sendMessageRecordRoundAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageRecordRoundAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageRecordRoundAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageRecordRoundAction");
    s.store_class_end();
  }
}

sendMessageUploadRoundAction::sendMessageUploadRoundAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageUploadRoundAction::ID;

object_ptr<SendMessageAction> sendMessageUploadRoundAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageUploadRoundAction>(p);
}

sendMessageUploadRoundAction::sendMessageUploadRoundAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageUploadRoundAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadRoundAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadRoundAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageUploadRoundAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

const std::int32_t speakingInGroupCallAction::ID;

object_ptr<SendMessageAction> speakingInGroupCallAction::fetch(TlBufferParser &p) {
  return make_tl_object<speakingInGroupCallAction>();
}

void speakingInGroupCallAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void speakingInGroupCallAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void speakingInGroupCallAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "speakingInGroupCallAction");
    s.store_class_end();
  }
}

sendMessageHistoryImportAction::sendMessageHistoryImportAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageHistoryImportAction::ID;

object_ptr<SendMessageAction> sendMessageHistoryImportAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageHistoryImportAction>(p);
}

sendMessageHistoryImportAction::sendMessageHistoryImportAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageHistoryImportAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageHistoryImportAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageHistoryImportAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageHistoryImportAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

const std::int32_t sendMessageChooseStickerAction::ID;

object_ptr<SendMessageAction> sendMessageChooseStickerAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageChooseStickerAction>();
}

void sendMessageChooseStickerAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageChooseStickerAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageChooseStickerAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageChooseStickerAction");
    s.store_class_end();
  }
}

sendMessageEmojiInteraction::sendMessageEmojiInteraction(string const &emoticon_, int32 msg_id_, object_ptr<dataJSON> &&interaction_)
  : emoticon_(emoticon_)
  , msg_id_(msg_id_)
  , interaction_(std::move(interaction_))
{}

const std::int32_t sendMessageEmojiInteraction::ID;

object_ptr<SendMessageAction> sendMessageEmojiInteraction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageEmojiInteraction>(p);
}

sendMessageEmojiInteraction::sendMessageEmojiInteraction(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , interaction_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void sendMessageEmojiInteraction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(interaction_, s);
}

void sendMessageEmojiInteraction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(interaction_, s);
}

void sendMessageEmojiInteraction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageEmojiInteraction");
    s.store_field("emoticon", emoticon_);
    s.store_field("msg_id", msg_id_);
    s.store_object_field("interaction", static_cast<const BaseObject *>(interaction_.get()));
    s.store_class_end();
  }
}

sendMessageEmojiInteractionSeen::sendMessageEmojiInteractionSeen(string const &emoticon_)
  : emoticon_(emoticon_)
{}

const std::int32_t sendMessageEmojiInteractionSeen::ID;

object_ptr<SendMessageAction> sendMessageEmojiInteractionSeen::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageEmojiInteractionSeen>(p);
}

sendMessageEmojiInteractionSeen::sendMessageEmojiInteractionSeen(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
{}

void sendMessageEmojiInteractionSeen::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void sendMessageEmojiInteractionSeen::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void sendMessageEmojiInteractionSeen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageEmojiInteractionSeen");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

sendMessageTextDraftAction::sendMessageTextDraftAction()
  : flags_()
  , can_stop_()
  , keep_on_stop_()
  , random_id_()
  , text_()
{}

sendMessageTextDraftAction::sendMessageTextDraftAction(int32 flags_, bool can_stop_, bool keep_on_stop_, int64 random_id_, object_ptr<textWithEntities> &&text_)
  : flags_(flags_)
  , can_stop_(can_stop_)
  , keep_on_stop_(keep_on_stop_)
  , random_id_(random_id_)
  , text_(std::move(text_))
{}

const std::int32_t sendMessageTextDraftAction::ID;

object_ptr<SendMessageAction> sendMessageTextDraftAction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<sendMessageTextDraftAction> res = make_tl_object<sendMessageTextDraftAction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_stop_ = (var0 & 1) != 0;
  res->keep_on_stop_ = (var0 & 2) != 0;
  res->random_id_ = TlFetchLong::parse(p);
  res->text_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void sendMessageTextDraftAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (can_stop_ << 0) | (keep_on_stop_ << 1)), s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
}

void sendMessageTextDraftAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (can_stop_ << 0) | (keep_on_stop_ << 1)), s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
}

void sendMessageTextDraftAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageTextDraftAction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_stop_ << 0) | (keep_on_stop_ << 1)));
    if (var0 & 1) { s.store_field("can_stop", true); }
    if (var0 & 2) { s.store_field("keep_on_stop", true); }
    s.store_field("random_id", random_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

inputSendMessageRichMessageDraftAction::inputSendMessageRichMessageDraftAction()
  : flags_()
  , can_stop_()
  , keep_on_stop_()
  , random_id_()
  , rich_message_()
{}

inputSendMessageRichMessageDraftAction::inputSendMessageRichMessageDraftAction(int32 flags_, bool can_stop_, bool keep_on_stop_, int64 random_id_, object_ptr<InputRichMessage> &&rich_message_)
  : flags_(flags_)
  , can_stop_(can_stop_)
  , keep_on_stop_(keep_on_stop_)
  , random_id_(random_id_)
  , rich_message_(std::move(rich_message_))
{}

const std::int32_t inputSendMessageRichMessageDraftAction::ID;

object_ptr<SendMessageAction> inputSendMessageRichMessageDraftAction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputSendMessageRichMessageDraftAction> res = make_tl_object<inputSendMessageRichMessageDraftAction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_stop_ = (var0 & 1) != 0;
  res->keep_on_stop_ = (var0 & 2) != 0;
  res->random_id_ = TlFetchLong::parse(p);
  res->rich_message_ = TlFetchObject<InputRichMessage>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputSendMessageRichMessageDraftAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (can_stop_ << 0) | (keep_on_stop_ << 1)), s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s);
}

void inputSendMessageRichMessageDraftAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (can_stop_ << 0) | (keep_on_stop_ << 1)), s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s);
}

void inputSendMessageRichMessageDraftAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSendMessageRichMessageDraftAction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_stop_ << 0) | (keep_on_stop_ << 1)));
    if (var0 & 1) { s.store_field("can_stop", true); }
    if (var0 & 2) { s.store_field("keep_on_stop", true); }
    s.store_field("random_id", random_id_);
    s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get()));
    s.store_class_end();
  }
}

sendMessageRichMessageDraftAction::sendMessageRichMessageDraftAction()
  : flags_()
  , can_stop_()
  , keep_on_stop_()
  , random_id_()
  , rich_message_()
{}

sendMessageRichMessageDraftAction::sendMessageRichMessageDraftAction(int32 flags_, bool can_stop_, bool keep_on_stop_, int64 random_id_, object_ptr<richMessage> &&rich_message_)
  : flags_(flags_)
  , can_stop_(can_stop_)
  , keep_on_stop_(keep_on_stop_)
  , random_id_(random_id_)
  , rich_message_(std::move(rich_message_))
{}

const std::int32_t sendMessageRichMessageDraftAction::ID;

object_ptr<SendMessageAction> sendMessageRichMessageDraftAction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<sendMessageRichMessageDraftAction> res = make_tl_object<sendMessageRichMessageDraftAction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_stop_ = (var0 & 1) != 0;
  res->keep_on_stop_ = (var0 & 2) != 0;
  res->random_id_ = TlFetchLong::parse(p);
  res->rich_message_ = TlFetchBoxed<TlFetchObject<richMessage>, -1158439541>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void sendMessageRichMessageDraftAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (can_stop_ << 0) | (keep_on_stop_ << 1)), s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxed<TlStoreObject, -1158439541>::store(rich_message_, s);
}

void sendMessageRichMessageDraftAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (can_stop_ << 0) | (keep_on_stop_ << 1)), s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxed<TlStoreObject, -1158439541>::store(rich_message_, s);
}

void sendMessageRichMessageDraftAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageRichMessageDraftAction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_stop_ << 0) | (keep_on_stop_ << 1)));
    if (var0 & 1) { s.store_field("can_stop", true); }
    if (var0 & 2) { s.store_field("keep_on_stop", true); }
    s.store_field("random_id", random_id_);
    s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get()));
    s.store_class_end();
  }
}

sendMessageStopDraftAction::sendMessageStopDraftAction(int64 random_id_)
  : random_id_(random_id_)
{}

const std::int32_t sendMessageStopDraftAction::ID;

object_ptr<SendMessageAction> sendMessageStopDraftAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageStopDraftAction>(p);
}

sendMessageStopDraftAction::sendMessageStopDraftAction(TlBufferParser &p)
  : random_id_(TlFetchLong::parse(p))
{}

void sendMessageStopDraftAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(random_id_, s);
}

void sendMessageStopDraftAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(random_id_, s);
}

void sendMessageStopDraftAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageStopDraftAction");
    s.store_field("random_id", random_id_);
    s.store_class_end();
  }
}

const std::int32_t starGiftActiveAuctionState::ID;

object_ptr<starGiftActiveAuctionState> starGiftActiveAuctionState::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftActiveAuctionState>(p);
}

starGiftActiveAuctionState::starGiftActiveAuctionState(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
  , state_(TlFetchObject<StarGiftAuctionState>::parse(p))
  , user_state_(TlFetchBoxed<TlFetchObject<starGiftAuctionUserState>, 787403204>::parse(p))
{}

void starGiftActiveAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftActiveAuctionState");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_object_field("user_state", static_cast<const BaseObject *>(user_state_.get()));
    s.store_class_end();
  }
}

const std::int32_t starGiftUpgradePrice::ID;

object_ptr<starGiftUpgradePrice> starGiftUpgradePrice::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftUpgradePrice>(p);
}

starGiftUpgradePrice::starGiftUpgradePrice(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , upgrade_stars_(TlFetchLong::parse(p))
{}

void starGiftUpgradePrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftUpgradePrice");
    s.store_field("date", date_);
    s.store_field("upgrade_stars", upgrade_stars_);
    s.store_class_end();
  }
}

starsGiftOption::starsGiftOption()
  : flags_()
  , extended_()
  , stars_()
  , store_product_()
  , currency_()
  , amount_()
{}

const std::int32_t starsGiftOption::ID;

object_ptr<starsGiftOption> starsGiftOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsGiftOption> res = make_tl_object<starsGiftOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->extended_ = (var0 & 2) != 0;
  res->stars_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->store_product_ = TlFetchString<string>::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsGiftOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsGiftOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (extended_ << 1) | ((!store_product_.empty()) << 0)));
    if (var0 & 2) { s.store_field("extended", true); }
    s.store_field("stars", stars_);
    if (var0 & 1) { s.store_field("store_product", store_product_); }
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

object_ptr<StoryView> StoryView::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case storyView::ID:
      return storyView::fetch(p);
    case storyViewPublicForward::ID:
      return storyViewPublicForward::fetch(p);
    case storyViewPublicRepost::ID:
      return storyViewPublicRepost::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

storyView::storyView()
  : flags_()
  , blocked_()
  , blocked_my_stories_from_()
  , user_id_()
  , date_()
  , reaction_()
{}

const std::int32_t storyView::ID;

object_ptr<StoryView> storyView::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyView> res = make_tl_object<storyView>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blocked_ = (var0 & 1) != 0;
  res->blocked_my_stories_from_ = (var0 & 2) != 0;
  res->user_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->reaction_ = TlFetchObject<Reaction>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void storyView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyView");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (blocked_ << 0) | (blocked_my_stories_from_ << 1) | ((reaction_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("blocked", true); }
    if (var0 & 2) { s.store_field("blocked_my_stories_from", true); }
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    if (var0 & 4) { s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get())); }
    s.store_class_end();
  }
}

storyViewPublicForward::storyViewPublicForward()
  : flags_()
  , blocked_()
  , blocked_my_stories_from_()
  , message_()
{}

const std::int32_t storyViewPublicForward::ID;

object_ptr<StoryView> storyViewPublicForward::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyViewPublicForward> res = make_tl_object<storyViewPublicForward>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blocked_ = (var0 & 1) != 0;
  res->blocked_my_stories_from_ = (var0 & 2) != 0;
  res->message_ = TlFetchObject<Message>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void storyViewPublicForward::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyViewPublicForward");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (blocked_ << 0) | (blocked_my_stories_from_ << 1)));
    if (var0 & 1) { s.store_field("blocked", true); }
    if (var0 & 2) { s.store_field("blocked_my_stories_from", true); }
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

storyViewPublicRepost::storyViewPublicRepost()
  : flags_()
  , blocked_()
  , blocked_my_stories_from_()
  , peer_id_()
  , story_()
{}

const std::int32_t storyViewPublicRepost::ID;

object_ptr<StoryView> storyViewPublicRepost::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyViewPublicRepost> res = make_tl_object<storyViewPublicRepost>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blocked_ = (var0 & 1) != 0;
  res->blocked_my_stories_from_ = (var0 & 2) != 0;
  res->peer_id_ = TlFetchObject<Peer>::parse(p);
  res->story_ = TlFetchObject<StoryItem>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void storyViewPublicRepost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyViewPublicRepost");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (blocked_ << 0) | (blocked_my_stories_from_ << 1)));
    if (var0 & 1) { s.store_field("blocked", true); }
    if (var0 & 2) { s.store_field("blocked_my_stories_from", true); }
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

walletUserAddress::walletUserAddress()
  : flags_()
  , user_id_()
  , address_()
  , public_key_()
{}

const std::int32_t walletUserAddress::ID;

object_ptr<walletUserAddress> walletUserAddress::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<walletUserAddress> res = make_tl_object<walletUserAddress>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->user_id_ = TlFetchLong::parse(p); }
  res->address_ = TlFetchString<string>::parse(p);
  res->public_key_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void walletUserAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "walletUserAddress");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("user_id", user_id_); }
    s.store_field("address", address_);
    s.store_bytes_field("public_key", public_key_);
    s.store_class_end();
  }
}

object_ptr<account_EmojiStatuses> account_EmojiStatuses::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_emojiStatusesNotModified::ID:
      return account_emojiStatusesNotModified::fetch(p);
    case account_emojiStatuses::ID:
      return account_emojiStatuses::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_emojiStatusesNotModified::ID;

object_ptr<account_EmojiStatuses> account_emojiStatusesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_emojiStatusesNotModified>();
}

void account_emojiStatusesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.emojiStatusesNotModified");
    s.store_class_end();
  }
}

const std::int32_t account_emojiStatuses::ID;

object_ptr<account_EmojiStatuses> account_emojiStatuses::fetch(TlBufferParser &p) {
  return make_tl_object<account_emojiStatuses>(p);
}

account_emojiStatuses::account_emojiStatuses(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , statuses_(TlFetchBoxed<TlFetchVector<TlFetchObject<EmojiStatus>>, 481674261>::parse(p))
{}

void account_emojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.emojiStatuses");
    s.store_field("hash", hash_);
    { s.store_vector_begin("statuses", statuses_.size()); for (const auto &_value : statuses_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

bots_popularAppBots::bots_popularAppBots()
  : flags_()
  , next_offset_()
  , users_()
{}

const std::int32_t bots_popularAppBots::ID;

object_ptr<bots_popularAppBots> bots_popularAppBots::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<bots_popularAppBots> res = make_tl_object<bots_popularAppBots>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void bots_popularAppBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.popularAppBots");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_archivedStickers::ID;

object_ptr<messages_archivedStickers> messages_archivedStickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_archivedStickers>(p);
}

messages_archivedStickers::messages_archivedStickers(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , sets_(TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p))
{}

void messages_archivedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.archivedStickers");
    s.store_field("count", count_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_composedRichMessageWithAI::ID;

object_ptr<messages_composedRichMessageWithAI> messages_composedRichMessageWithAI::fetch(TlBufferParser &p) {
  return make_tl_object<messages_composedRichMessageWithAI>(p);
}

messages_composedRichMessageWithAI::messages_composedRichMessageWithAI(TlBufferParser &p)
  : result_(TlFetchBoxed<TlFetchObject<richMessage>, -1158439541>::parse(p))
{}

void messages_composedRichMessageWithAI::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.composedRichMessageWithAI");
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_class_end();
  }
}

messages_dialogFilters::messages_dialogFilters()
  : flags_()
  , tags_enabled_()
  , filters_()
{}

const std::int32_t messages_dialogFilters::ID;

object_ptr<messages_dialogFilters> messages_dialogFilters::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_dialogFilters> res = make_tl_object<messages_dialogFilters>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->tags_enabled_ = (var0 & 1) != 0;
  res->filters_ = TlFetchBoxed<TlFetchVector<TlFetchObject<DialogFilter>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_dialogFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dialogFilters");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (tags_enabled_ << 0)));
    if (var0 & 1) { s.store_field("tags_enabled", true); }
    { s.store_vector_begin("filters", filters_.size()); for (const auto &_value : filters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_EmojiGroups> messages_EmojiGroups::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_emojiGroupsNotModified::ID:
      return messages_emojiGroupsNotModified::fetch(p);
    case messages_emojiGroups::ID:
      return messages_emojiGroups::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_emojiGroupsNotModified::ID;

object_ptr<messages_EmojiGroups> messages_emojiGroupsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_emojiGroupsNotModified>();
}

void messages_emojiGroupsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.emojiGroupsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_emojiGroups::ID;

object_ptr<messages_EmojiGroups> messages_emojiGroups::fetch(TlBufferParser &p) {
  return make_tl_object<messages_emojiGroups>(p);
}

messages_emojiGroups::messages_emojiGroups(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , groups_(TlFetchBoxed<TlFetchVector<TlFetchObject<EmojiGroup>>, 481674261>::parse(p))
{}

void messages_emojiGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.emojiGroups");
    s.store_field("hash", hash_);
    { s.store_vector_begin("groups", groups_.size()); for (const auto &_value : groups_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_searchResultsPositions::ID;

object_ptr<messages_searchResultsPositions> messages_searchResultsPositions::fetch(TlBufferParser &p) {
  return make_tl_object<messages_searchResultsPositions>(p);
}

messages_searchResultsPositions::messages_searchResultsPositions(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , positions_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<searchResultPosition>, 2137295719>>, 481674261>::parse(p))
{}

void messages_searchResultsPositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchResultsPositions");
    s.store_field("count", count_);
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_connectedStarRefBots::ID;

object_ptr<payments_connectedStarRefBots> payments_connectedStarRefBots::fetch(TlBufferParser &p) {
  return make_tl_object<payments_connectedStarRefBots>(p);
}

payments_connectedStarRefBots::payments_connectedStarRefBots(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , connected_bots_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<connectedBotStarRef>, 429997937>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void payments_connectedStarRefBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.connectedStarRefBots");
    s.store_field("count", count_);
    { s.store_vector_begin("connected_bots", connected_bots_.size()); for (const auto &_value : connected_bots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<payments_GiveawayInfo> payments_GiveawayInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_giveawayInfo::ID:
      return payments_giveawayInfo::fetch(p);
    case payments_giveawayInfoResults::ID:
      return payments_giveawayInfoResults::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

payments_giveawayInfo::payments_giveawayInfo()
  : flags_()
  , participating_()
  , preparing_results_()
  , start_date_()
  , joined_too_early_date_()
  , admin_disallowed_chat_id_()
  , disallowed_country_()
{}

const std::int32_t payments_giveawayInfo::ID;

object_ptr<payments_GiveawayInfo> payments_giveawayInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_giveawayInfo> res = make_tl_object<payments_giveawayInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->participating_ = (var0 & 1) != 0;
  res->preparing_results_ = (var0 & 8) != 0;
  res->start_date_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->joined_too_early_date_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->admin_disallowed_chat_id_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->disallowed_country_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_giveawayInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.giveawayInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (participating_ << 0) | (preparing_results_ << 3) | ((!disallowed_country_.empty()) << 4)));
    if (var0 & 1) { s.store_field("participating", true); }
    if (var0 & 8) { s.store_field("preparing_results", true); }
    s.store_field("start_date", start_date_);
    if (var0 & 2) { s.store_field("joined_too_early_date", joined_too_early_date_); }
    if (var0 & 4) { s.store_field("admin_disallowed_chat_id", admin_disallowed_chat_id_); }
    if (var0 & 16) { s.store_field("disallowed_country", disallowed_country_); }
    s.store_class_end();
  }
}

payments_giveawayInfoResults::payments_giveawayInfoResults()
  : flags_()
  , winner_()
  , refunded_()
  , start_date_()
  , gift_code_slug_()
  , stars_prize_()
  , finish_date_()
  , winners_count_()
  , activated_count_()
{}

const std::int32_t payments_giveawayInfoResults::ID;

object_ptr<payments_GiveawayInfo> payments_giveawayInfoResults::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_giveawayInfoResults> res = make_tl_object<payments_giveawayInfoResults>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->winner_ = (var0 & 1) != 0;
  res->refunded_ = (var0 & 2) != 0;
  res->start_date_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->gift_code_slug_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->stars_prize_ = TlFetchLong::parse(p); }
  res->finish_date_ = TlFetchInt::parse(p);
  res->winners_count_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->activated_count_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_giveawayInfoResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.giveawayInfoResults");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (winner_ << 0) | (refunded_ << 1) | ((!gift_code_slug_.empty()) << 3)));
    if (var0 & 1) { s.store_field("winner", true); }
    if (var0 & 2) { s.store_field("refunded", true); }
    s.store_field("start_date", start_date_);
    if (var0 & 8) { s.store_field("gift_code_slug", gift_code_slug_); }
    if (var0 & 16) { s.store_field("stars_prize", stars_prize_); }
    s.store_field("finish_date", finish_date_);
    s.store_field("winners_count", winners_count_);
    if (var0 & 4) { s.store_field("activated_count", activated_count_); }
    s.store_class_end();
  }
}

object_ptr<payments_StarGiftOnchainSalePayload> payments_StarGiftOnchainSalePayload::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_starGiftOnchainSalePayload::ID:
      return payments_starGiftOnchainSalePayload::fetch(p);
    case payments_starGiftOnchainFixedSalePayload::ID:
      return payments_starGiftOnchainFixedSalePayload::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

payments_starGiftOnchainSalePayload::payments_starGiftOnchainSalePayload()
  : flags_()
  , gasless_available_()
  , nft_address_()
  , amount_()
  , payload_()
{}

const std::int32_t payments_starGiftOnchainSalePayload::ID;

object_ptr<payments_StarGiftOnchainSalePayload> payments_starGiftOnchainSalePayload::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_starGiftOnchainSalePayload> res = make_tl_object<payments_starGiftOnchainSalePayload>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->gasless_available_ = (var0 & 1) != 0;
  res->nft_address_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->payload_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_starGiftOnchainSalePayload::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftOnchainSalePayload");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (gasless_available_ << 0)));
    if (var0 & 1) { s.store_field("gasless_available", true); }
    s.store_field("nft_address", nft_address_);
    s.store_field("amount", amount_);
    s.store_bytes_field("payload", payload_);
    s.store_class_end();
  }
}

payments_starGiftOnchainFixedSalePayload::payments_starGiftOnchainFixedSalePayload()
  : flags_()
  , sale_address_()
  , messages_()
  , gasless_messages_()
{}

const std::int32_t payments_starGiftOnchainFixedSalePayload::ID;

object_ptr<payments_StarGiftOnchainSalePayload> payments_starGiftOnchainFixedSalePayload::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_starGiftOnchainFixedSalePayload> res = make_tl_object<payments_starGiftOnchainFixedSalePayload>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->sale_address_ = TlFetchString<string>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<payments_starGiftOnchainOfferTxMessage>, -2003007979>>, 481674261>::parse(p);
  if (var0 & 1) { res->gasless_messages_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<payments_starGiftOnchainOfferTxMessage>, -2003007979>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_starGiftOnchainFixedSalePayload::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftOnchainFixedSalePayload");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!gasless_messages_.empty()) << 0)));
    s.store_field("sale_address", sale_address_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { { s.store_vector_begin("gasless_messages", gasless_messages_.size()); for (const auto &_value : gasless_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftWithdrawalUrl::ID;

object_ptr<payments_starGiftWithdrawalUrl> payments_starGiftWithdrawalUrl::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftWithdrawalUrl>(p);
}

payments_starGiftWithdrawalUrl::payments_starGiftWithdrawalUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void payments_starGiftWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftWithdrawalUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

const std::int32_t payments_starsRevenueAdsAccountUrl::ID;

object_ptr<payments_starsRevenueAdsAccountUrl> payments_starsRevenueAdsAccountUrl::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starsRevenueAdsAccountUrl>(p);
}

payments_starsRevenueAdsAccountUrl::payments_starsRevenueAdsAccountUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void payments_starsRevenueAdsAccountUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starsRevenueAdsAccountUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

payments_starsStatus::payments_starsStatus()
  : flags_()
  , balance_()
  , subscriptions_()
  , subscriptions_next_offset_()
  , subscriptions_missing_balance_()
  , history_()
  , next_offset_()
  , chats_()
  , users_()
{}

const std::int32_t payments_starsStatus::ID;

object_ptr<payments_starsStatus> payments_starsStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_starsStatus> res = make_tl_object<payments_starsStatus>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->balance_ = TlFetchObject<StarsAmount>::parse(p);
  if (var0 & 2) { res->subscriptions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsSubscription>, 779004698>>, 481674261>::parse(p); }
  if (var0 & 4) { res->subscriptions_next_offset_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->subscriptions_missing_balance_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->history_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsTransaction>, 325426864>>, 481674261>::parse(p); }
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_starsStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starsStatus");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!subscriptions_.empty()) << 1) | ((!subscriptions_next_offset_.empty()) << 2) | ((!history_.empty()) << 3) | ((!next_offset_.empty()) << 0)));
    s.store_object_field("balance", static_cast<const BaseObject *>(balance_.get()));
    if (var0 & 2) { { s.store_vector_begin("subscriptions", subscriptions_.size()); for (const auto &_value : subscriptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_field("subscriptions_next_offset", subscriptions_next_offset_); }
    if (var0 & 16) { s.store_field("subscriptions_missing_balance", subscriptions_missing_balance_); }
    if (var0 & 8) { { s.store_vector_begin("history", history_.size()); for (const auto &_value : history_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_suggestedStarRefBots::payments_suggestedStarRefBots()
  : flags_()
  , count_()
  , suggested_bots_()
  , users_()
  , next_offset_()
{}

const std::int32_t payments_suggestedStarRefBots::ID;

object_ptr<payments_suggestedStarRefBots> payments_suggestedStarRefBots::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_suggestedStarRefBots> res = make_tl_object<payments_suggestedStarRefBots>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->suggested_bots_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starRefProgram>, -586389774>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_suggestedStarRefBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.suggestedStarRefBots");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("count", count_);
    { s.store_vector_begin("suggested_bots", suggested_bots_.size()); for (const auto &_value : suggested_bots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

const std::int32_t phone_exportedGroupCallInvite::ID;

object_ptr<phone_exportedGroupCallInvite> phone_exportedGroupCallInvite::fetch(TlBufferParser &p) {
  return make_tl_object<phone_exportedGroupCallInvite>(p);
}

phone_exportedGroupCallInvite::phone_exportedGroupCallInvite(TlBufferParser &p)
  : link_(TlFetchString<string>::parse(p))
{}

void phone_exportedGroupCallInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.exportedGroupCallInvite");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

const std::int32_t phone_groupCall::ID;

object_ptr<phone_groupCall> phone_groupCall::fetch(TlBufferParser &p) {
  return make_tl_object<phone_groupCall>(p);
}

phone_groupCall::phone_groupCall(TlBufferParser &p)
  : call_(TlFetchObject<GroupCall>::parse(p))
  , participants_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>>, 481674261>::parse(p))
  , participants_next_offset_(TlFetchString<string>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void phone_groupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.groupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("participants_next_offset", participants_next_offset_);
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t phone_groupCallStreamChannels::ID;

object_ptr<phone_groupCallStreamChannels> phone_groupCallStreamChannels::fetch(TlBufferParser &p) {
  return make_tl_object<phone_groupCallStreamChannels>(p);
}

phone_groupCallStreamChannels::phone_groupCallStreamChannels(TlBufferParser &p)
  : channels_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallStreamChannel>, -2132064081>>, 481674261>::parse(p))
{}

void phone_groupCallStreamChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.groupCallStreamChannels");
    { s.store_vector_begin("channels", channels_.size()); for (const auto &_value : channels_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_storyReactionsList::stories_storyReactionsList()
  : flags_()
  , count_()
  , reactions_()
  , chats_()
  , users_()
  , next_offset_()
{}

const std::int32_t stories_storyReactionsList::ID;

object_ptr<stories_storyReactionsList> stories_storyReactionsList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_storyReactionsList> res = make_tl_object<stories_storyReactionsList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->reactions_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StoryReaction>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stories_storyReactionsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.storyReactionsList");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("count", count_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

object_ptr<upload_CdnFile> upload_CdnFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case upload_cdnFileReuploadNeeded::ID:
      return upload_cdnFileReuploadNeeded::fetch(p);
    case upload_cdnFile::ID:
      return upload_cdnFile::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t upload_cdnFileReuploadNeeded::ID;

object_ptr<upload_CdnFile> upload_cdnFileReuploadNeeded::fetch(TlBufferParser &p) {
  return make_tl_object<upload_cdnFileReuploadNeeded>(p);
}

upload_cdnFileReuploadNeeded::upload_cdnFileReuploadNeeded(TlBufferParser &p)
  : request_token_(TlFetchBytes<bytes>::parse(p))
{}

void upload_cdnFileReuploadNeeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.cdnFileReuploadNeeded");
    s.store_field("request_token", "[REDACTED]");
    s.store_class_end();
  }
}

const std::int32_t upload_cdnFile::ID;

object_ptr<upload_CdnFile> upload_cdnFile::fetch(TlBufferParser &p) {
  return make_tl_object<upload_cdnFile>(p);
}

upload_cdnFile::upload_cdnFile(TlBufferParser &p)
  : bytes_(TlFetchBytes<bytes>::parse(p))
{}

void upload_cdnFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.cdnFile");
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

wallet_card::wallet_card()
  : flags_()
  , stickers_()
  , bg_nft_item_()
  , address_()
  , balance_()
{}

const std::int32_t wallet_card::ID;

object_ptr<wallet_card> wallet_card::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<wallet_card> res = make_tl_object<wallet_card>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->stickers_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<wallet_cardSticker>, -218035014>>, 481674261>::parse(p); }
  if (var0 & 2) { res->bg_nft_item_ = TlFetchBoxed<TlFetchObject<wallet_nftItem>, 389937907>::parse(p); }
  res->address_ = TlFetchString<string>::parse(p);
  res->balance_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void wallet_card::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.card");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!stickers_.empty()) << 0) | ((bg_nft_item_ != nullptr) << 1)));
    if (var0 & 1) { { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_object_field("bg_nft_item", static_cast<const BaseObject *>(bg_nft_item_.get())); }
    s.store_field("address", address_);
    s.store_field("balance", balance_);
    s.store_class_end();
  }
}

const std::int32_t wallet_tonConnectPending::ID;

object_ptr<wallet_tonConnectPending> wallet_tonConnectPending::fetch(TlBufferParser &p) {
  return make_tl_object<wallet_tonConnectPending>(p);
}

wallet_tonConnectPending::wallet_tonConnectPending(TlBufferParser &p)
  : session_(TlFetchBoxed<TlFetchObject<tonConnectSession>, 308631238>::parse(p))
  , requests_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<tonConnectRequest>, -1587575533>>, 481674261>::parse(p))
{}

void wallet_tonConnectPending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectPending");
    s.store_object_field("session", static_cast<const BaseObject *>(session_.get()));
    { s.store_vector_begin("requests", requests_.size()); for (const auto &_value : requests_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

wallet_transactions::wallet_transactions()
  : flags_()
  , balance_()
  , transactions_()
  , next_offset_()
  , chats_()
  , users_()
{}

const std::int32_t wallet_transactions::ID;

object_ptr<wallet_transactions> wallet_transactions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<wallet_transactions> res = make_tl_object<wallet_transactions>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->balance_ = TlFetchLong::parse(p);
  res->transactions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<walletTransaction>, -1792163517>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void wallet_transactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.transactions");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("balance", balance_);
    { s.store_vector_begin("transactions", transactions_.size()); for (const auto &_value : transactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_checkUsername::account_checkUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t account_checkUsername::ID;

void account_checkUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(655677548);
  TlStoreString::store(username_, s);
}

void account_checkUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(655677548);
  TlStoreString::store(username_, s);
}

void account_checkUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.checkUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

account_checkUsername::ReturnType account_checkUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_confirmBotConnection::account_confirmBotConnection(object_ptr<InputUser> &&bot_id_)
  : bot_id_(std::move(bot_id_))
{}

const std::int32_t account_confirmBotConnection::ID;

void account_confirmBotConnection::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1743593320);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_id_, s);
}

void account_confirmBotConnection::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1743593320);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_id_, s);
}

void account_confirmBotConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.confirmBotConnection");
    s.store_object_field("bot_id", static_cast<const BaseObject *>(bot_id_.get()));
    s.store_class_end();
  }
}

account_confirmBotConnection::ReturnType account_confirmBotConnection::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_confirmPasswordEmail::account_confirmPasswordEmail(string const &code_)
  : code_(code_)
{}

const std::int32_t account_confirmPasswordEmail::ID;

void account_confirmPasswordEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1881204448);
  TlStoreString::store(code_, s);
}

void account_confirmPasswordEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1881204448);
  TlStoreString::store(code_, s);
}

void account_confirmPasswordEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.confirmPasswordEmail");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

account_confirmPasswordEmail::ReturnType account_confirmPasswordEmail::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_deleteSecureValue::account_deleteSecureValue(array<object_ptr<SecureValueType>> &&types_)
  : types_(std::move(types_))
{}

const std::int32_t account_deleteSecureValue::ID;

void account_deleteSecureValue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1199522741);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(types_, s);
}

void account_deleteSecureValue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1199522741);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(types_, s);
}

void account_deleteSecureValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.deleteSecureValue");
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_deleteSecureValue::ReturnType account_deleteSecureValue::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_getAuthorizations::ID;

void account_getAuthorizations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-484392616);
}

void account_getAuthorizations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-484392616);
}

void account_getAuthorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAuthorizations");
    s.store_class_end();
  }
}

account_getAuthorizations::ReturnType account_getAuthorizations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_authorizations>, 1275039392>::parse(p);
#undef FAIL
}

account_getChannelDefaultEmojiStatuses::account_getChannelDefaultEmojiStatuses(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getChannelDefaultEmojiStatuses::ID;

void account_getChannelDefaultEmojiStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1999087573);
  TlStoreBinary::store(hash_, s);
}

void account_getChannelDefaultEmojiStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1999087573);
  TlStoreBinary::store(hash_, s);
}

void account_getChannelDefaultEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getChannelDefaultEmojiStatuses");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getChannelDefaultEmojiStatuses::ReturnType account_getChannelDefaultEmojiStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_EmojiStatuses>::parse(p);
#undef FAIL
}

account_getChatThemes::account_getChatThemes(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getChatThemes::ID;

void account_getChatThemes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-700916087);
  TlStoreBinary::store(hash_, s);
}

void account_getChatThemes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-700916087);
  TlStoreBinary::store(hash_, s);
}

void account_getChatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getChatThemes");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getChatThemes::ReturnType account_getChatThemes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_Themes>::parse(p);
#undef FAIL
}

account_installWallPaper::account_installWallPaper(object_ptr<InputWallPaper> &&wallpaper_, object_ptr<wallPaperSettings> &&settings_)
  : wallpaper_(std::move(wallpaper_))
  , settings_(std::move(settings_))
{}

const std::int32_t account_installWallPaper::ID;

void account_installWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-18000023);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_installWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-18000023);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_installWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.installWallPaper");
    s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_installWallPaper::ReturnType account_installWallPaper::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_resetWebAuthorization::account_resetWebAuthorization(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_resetWebAuthorization::ID;

void account_resetWebAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(755087855);
  TlStoreBinary::store(hash_, s);
}

void account_resetWebAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(755087855);
  TlStoreBinary::store(hash_, s);
}

void account_resetWebAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetWebAuthorization");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_resetWebAuthorization::ReturnType account_resetWebAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_sendVerifyPhoneCode::account_sendVerifyPhoneCode(string const &phone_number_, object_ptr<codeSettings> &&settings_)
  : phone_number_(phone_number_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_sendVerifyPhoneCode::ID;

void account_sendVerifyPhoneCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1516022023);
  TlStoreString::store(phone_number_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendVerifyPhoneCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1516022023);
  TlStoreString::store(phone_number_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendVerifyPhoneCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.sendVerifyPhoneCode");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_sendVerifyPhoneCode::ReturnType account_sendVerifyPhoneCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

account_setAccountTTL::account_setAccountTTL(object_ptr<accountDaysTTL> &&ttl_)
  : ttl_(std::move(ttl_))
{}

const std::int32_t account_setAccountTTL::ID;

void account_setAccountTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(608323678);
  TlStoreBoxed<TlStoreObject, -1194283041>::store(ttl_, s);
}

void account_setAccountTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(608323678);
  TlStoreBoxed<TlStoreObject, -1194283041>::store(ttl_, s);
}

void account_setAccountTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setAccountTTL");
    s.store_object_field("ttl", static_cast<const BaseObject *>(ttl_.get()));
    s.store_class_end();
  }
}

account_setAccountTTL::ReturnType account_setAccountTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_toggleUsername::account_toggleUsername(string const &username_, bool active_)
  : username_(username_)
  , active_(active_)
{}

const std::int32_t account_toggleUsername::ID;

void account_toggleUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1490465654);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void account_toggleUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1490465654);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void account_toggleUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.toggleUsername");
    s.store_field("username", username_);
    s.store_field("active", active_);
    s.store_class_end();
  }
}

account_toggleUsername::ReturnType account_toggleUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateProfile::account_updateProfile(int32 flags_, string const &first_name_, string const &last_name_, string const &about_)
  : flags_(flags_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , about_(about_)
{}

const std::int32_t account_updateProfile::ID;

void account_updateProfile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2018596725);
  TlStoreBinary::store((var0 = flags_ | ((!first_name_.empty()) << 0) | ((!last_name_.empty()) << 1) | ((!about_.empty()) << 2)), s);
  if (var0 & 1) { TlStoreString::store(first_name_, s); }
  if (var0 & 2) { TlStoreString::store(last_name_, s); }
  if (var0 & 4) { TlStoreString::store(about_, s); }
}

void account_updateProfile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2018596725);
  TlStoreBinary::store((var0 = flags_ | ((!first_name_.empty()) << 0) | ((!last_name_.empty()) << 1) | ((!about_.empty()) << 2)), s);
  if (var0 & 1) { TlStoreString::store(first_name_, s); }
  if (var0 & 2) { TlStoreString::store(last_name_, s); }
  if (var0 & 4) { TlStoreString::store(about_, s); }
}

void account_updateProfile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateProfile");
    s.store_field("flags", (var0 = flags_ | ((!first_name_.empty()) << 0) | ((!last_name_.empty()) << 1) | ((!about_.empty()) << 2)));
    if (var0 & 1) { s.store_field("first_name", first_name_); }
    if (var0 & 2) { s.store_field("last_name", last_name_); }
    if (var0 & 4) { s.store_field("about", about_); }
    s.store_class_end();
  }
}

account_updateProfile::ReturnType account_updateProfile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

account_updateTheme::account_updateTheme(int32 flags_, string const &format_, object_ptr<InputTheme> &&theme_, string const &slug_, string const &title_, object_ptr<InputDocument> &&document_, array<object_ptr<inputThemeSettings>> &&settings_)
  : flags_(flags_)
  , format_(format_)
  , theme_(std::move(theme_))
  , slug_(slug_)
  , title_(title_)
  , document_(std::move(document_))
  , settings_(std::move(settings_))
{}

const std::int32_t account_updateTheme::ID;

void account_updateTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(737414348);
  TlStoreBinary::store((var0 = flags_ | ((!slug_.empty()) << 0) | ((!title_.empty()) << 1) | ((document_ != nullptr) << 2) | ((!settings_.empty()) << 3)), s);
  TlStoreString::store(format_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
  if (var0 & 1) { TlStoreString::store(slug_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1881255857>>, 481674261>::store(settings_, s); }
}

void account_updateTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(737414348);
  TlStoreBinary::store((var0 = flags_ | ((!slug_.empty()) << 0) | ((!title_.empty()) << 1) | ((document_ != nullptr) << 2) | ((!settings_.empty()) << 3)), s);
  TlStoreString::store(format_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
  if (var0 & 1) { TlStoreString::store(slug_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1881255857>>, 481674261>::store(settings_, s); }
}

void account_updateTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateTheme");
    s.store_field("flags", (var0 = flags_ | ((!slug_.empty()) << 0) | ((!title_.empty()) << 1) | ((document_ != nullptr) << 2) | ((!settings_.empty()) << 3)));
    s.store_field("format", format_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    if (var0 & 1) { s.store_field("slug", slug_); }
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 4) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 8) { { s.store_vector_begin("settings", settings_.size()); for (const auto &_value : settings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

account_updateTheme::ReturnType account_updateTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<theme>, -1609668650>::parse(p);
#undef FAIL
}

aicompose_updateTone::aicompose_updateTone(int32 flags_, object_ptr<InputAiComposeTone> &&tone_, bool display_author_, int64 emoji_id_, string const &title_, string const &prompt_)
  : flags_(flags_)
  , tone_(std::move(tone_))
  , display_author_(display_author_)
  , emoji_id_(emoji_id_)
  , title_(title_)
  , prompt_(prompt_)
{}

const std::int32_t aicompose_updateTone::ID;

void aicompose_updateTone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1875128487);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 2) | ((!prompt_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s);
  if (var0 & 1) { TlStoreBool::store(display_author_, s); }
  if (var0 & 2) { TlStoreBinary::store(emoji_id_, s); }
  if (var0 & 4) { TlStoreString::store(title_, s); }
  if (var0 & 8) { TlStoreString::store(prompt_, s); }
}

void aicompose_updateTone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1875128487);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 2) | ((!prompt_.empty()) << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s);
  if (var0 & 1) { TlStoreBool::store(display_author_, s); }
  if (var0 & 2) { TlStoreBinary::store(emoji_id_, s); }
  if (var0 & 4) { TlStoreString::store(title_, s); }
  if (var0 & 8) { TlStoreString::store(prompt_, s); }
}

void aicompose_updateTone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aicompose.updateTone");
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 2) | ((!prompt_.empty()) << 3)));
    s.store_object_field("tone", static_cast<const BaseObject *>(tone_.get()));
    if (var0 & 1) { s.store_field("display_author", display_author_); }
    if (var0 & 2) { s.store_field("emoji_id", emoji_id_); }
    if (var0 & 4) { s.store_field("title", title_); }
    if (var0 & 8) { s.store_field("prompt", prompt_); }
    s.store_class_end();
  }
}

aicompose_updateTone::ReturnType aicompose_updateTone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<AiComposeTone>::parse(p);
#undef FAIL
}

auth_bindTempAuthKey::auth_bindTempAuthKey(int64 perm_auth_key_id_, int64 nonce_, int32 expires_at_, bytes &&encrypted_message_)
  : perm_auth_key_id_(perm_auth_key_id_)
  , nonce_(nonce_)
  , expires_at_(expires_at_)
  , encrypted_message_(std::move(encrypted_message_))
{}

const std::int32_t auth_bindTempAuthKey::ID;

void auth_bindTempAuthKey::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-841733627);
  TlStoreBinary::store(perm_auth_key_id_, s);
  TlStoreBinary::store(nonce_, s);
  TlStoreBinary::store(expires_at_, s);
  TlStoreString::store(encrypted_message_, s);
}

void auth_bindTempAuthKey::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-841733627);
  TlStoreBinary::store(perm_auth_key_id_, s);
  TlStoreBinary::store(nonce_, s);
  TlStoreBinary::store(expires_at_, s);
  TlStoreString::store(encrypted_message_, s);
}

void auth_bindTempAuthKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.bindTempAuthKey");
    s.store_field("perm_auth_key_id", perm_auth_key_id_);
    s.store_field("nonce", nonce_);
    s.store_field("expires_at", expires_at_);
    s.store_bytes_field("encrypted_message", encrypted_message_);
    s.store_class_end();
  }
}

auth_bindTempAuthKey::ReturnType auth_bindTempAuthKey::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_importWebTokenAuthorization::auth_importWebTokenAuthorization(int32 api_id_, string const &api_hash_, string const &web_auth_token_)
  : api_id_(api_id_)
  , api_hash_(api_hash_)
  , web_auth_token_(web_auth_token_)
{}

const std::int32_t auth_importWebTokenAuthorization::ID;

void auth_importWebTokenAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(767062953);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreString::store(web_auth_token_, s);
}

void auth_importWebTokenAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(767062953);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreString::store(web_auth_token_, s);
}

void auth_importWebTokenAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.importWebTokenAuthorization");
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", "[REDACTED]");
    s.store_field("web_auth_token", "[REDACTED]");
    s.store_class_end();
  }
}

auth_importWebTokenAuthorization::ReturnType auth_importWebTokenAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

auth_initFirebasePnvLogin::auth_initFirebasePnvLogin(int32 flags_, array<int64> &&except_ids_, int32 api_id_, string const &api_hash_)
  : flags_(flags_)
  , except_ids_(std::move(except_ids_))
  , api_id_(api_id_)
  , api_hash_(api_hash_)
{}

const std::int32_t auth_initFirebasePnvLogin::ID;

void auth_initFirebasePnvLogin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1682904512);
  TlStoreBinary::store((var0 = flags_ | ((!except_ids_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(except_ids_, s); }
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
}

void auth_initFirebasePnvLogin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1682904512);
  TlStoreBinary::store((var0 = flags_ | ((!except_ids_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(except_ids_, s); }
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
}

void auth_initFirebasePnvLogin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.initFirebasePnvLogin");
    s.store_field("flags", (var0 = flags_ | ((!except_ids_.empty()) << 0)));
    if (var0 & 1) { { s.store_vector_begin("except_ids", except_ids_.size()); for (const auto &_value : except_ids_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", "[REDACTED]");
    s.store_class_end();
  }
}

auth_initFirebasePnvLogin::ReturnType auth_initFirebasePnvLogin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<auth_firebasePnvIntent>, -547700724>::parse(p);
#undef FAIL
}

auth_recoverPassword::auth_recoverPassword(int32 flags_, string const &code_, object_ptr<account_passwordInputSettings> &&new_settings_)
  : flags_(flags_)
  , code_(code_)
  , new_settings_(std::move(new_settings_))
{}

const std::int32_t auth_recoverPassword::ID;

void auth_recoverPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(923364464);
  TlStoreBinary::store((var0 = flags_ | ((new_settings_ != nullptr) << 0)), s);
  TlStoreString::store(code_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1036572727>::store(new_settings_, s); }
}

void auth_recoverPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(923364464);
  TlStoreBinary::store((var0 = flags_ | ((new_settings_ != nullptr) << 0)), s);
  TlStoreString::store(code_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1036572727>::store(new_settings_, s); }
}

void auth_recoverPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.recoverPassword");
    s.store_field("flags", (var0 = flags_ | ((new_settings_ != nullptr) << 0)));
    s.store_field("code", code_);
    if (var0 & 1) { s.store_object_field("new_settings", static_cast<const BaseObject *>(new_settings_.get())); }
    s.store_class_end();
  }
}

auth_recoverPassword::ReturnType auth_recoverPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

bots_invokeWebViewCustomMethod::bots_invokeWebViewCustomMethod(object_ptr<InputUser> &&bot_, string const &custom_method_, object_ptr<dataJSON> &&params_)
  : bot_(std::move(bot_))
  , custom_method_(custom_method_)
  , params_(std::move(params_))
{}

const std::int32_t bots_invokeWebViewCustomMethod::ID;

void bots_invokeWebViewCustomMethod::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(142591463);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(custom_method_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void bots_invokeWebViewCustomMethod::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(142591463);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(custom_method_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void bots_invokeWebViewCustomMethod::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.invokeWebViewCustomMethod");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("custom_method", custom_method_);
    s.store_object_field("params", static_cast<const BaseObject *>(params_.get()));
    s.store_class_end();
  }
}

bots_invokeWebViewCustomMethod::ReturnType bots_invokeWebViewCustomMethod::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
#undef FAIL
}

bots_setBotInfo::bots_setBotInfo(int32 flags_, object_ptr<InputUser> &&bot_, string const &lang_code_, string const &name_, string const &about_, string const &description_)
  : flags_(flags_)
  , bot_(std::move(bot_))
  , lang_code_(lang_code_)
  , name_(name_)
  , about_(about_)
  , description_(description_)
{}

const std::int32_t bots_setBotInfo::ID;

void bots_setBotInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(282013987);
  TlStoreBinary::store((var0 = flags_ | ((bot_ != nullptr) << 2) | ((!name_.empty()) << 3) | ((!about_.empty()) << 0) | ((!description_.empty()) << 1)), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreString::store(lang_code_, s);
  if (var0 & 8) { TlStoreString::store(name_, s); }
  if (var0 & 1) { TlStoreString::store(about_, s); }
  if (var0 & 2) { TlStoreString::store(description_, s); }
}

void bots_setBotInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(282013987);
  TlStoreBinary::store((var0 = flags_ | ((bot_ != nullptr) << 2) | ((!name_.empty()) << 3) | ((!about_.empty()) << 0) | ((!description_.empty()) << 1)), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreString::store(lang_code_, s);
  if (var0 & 8) { TlStoreString::store(name_, s); }
  if (var0 & 1) { TlStoreString::store(about_, s); }
  if (var0 & 2) { TlStoreString::store(description_, s); }
}

void bots_setBotInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setBotInfo");
    s.store_field("flags", (var0 = flags_ | ((bot_ != nullptr) << 2) | ((!name_.empty()) << 3) | ((!about_.empty()) << 0) | ((!description_.empty()) << 1)));
    if (var0 & 4) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    s.store_field("lang_code", lang_code_);
    if (var0 & 8) { s.store_field("name", name_); }
    if (var0 & 1) { s.store_field("about", about_); }
    if (var0 & 2) { s.store_field("description", description_); }
    s.store_class_end();
  }
}

bots_setBotInfo::ReturnType bots_setBotInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_setCustomVerification::bots_setCustomVerification(int32 flags_, bool enabled_, object_ptr<InputUser> &&bot_, object_ptr<InputPeer> &&peer_, object_ptr<textWithEntities> &&custom_description_)
  : flags_(flags_)
  , enabled_(enabled_)
  , bot_(std::move(bot_))
  , peer_(std::move(peer_))
  , custom_description_(std::move(custom_description_))
{}

const std::int32_t bots_setCustomVerification::ID;

void bots_setCustomVerification::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-191600809);
  TlStoreBinary::store((var0 = flags_ | (enabled_ << 1) | ((bot_ != nullptr) << 0) | ((custom_description_ != nullptr) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1964978502>::store(custom_description_, s); }
}

void bots_setCustomVerification::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-191600809);
  TlStoreBinary::store((var0 = flags_ | (enabled_ << 1) | ((bot_ != nullptr) << 0) | ((custom_description_ != nullptr) << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1964978502>::store(custom_description_, s); }
}

void bots_setCustomVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setCustomVerification");
    s.store_field("flags", (var0 = flags_ | (enabled_ << 1) | ((bot_ != nullptr) << 0) | ((custom_description_ != nullptr) << 2)));
    if (var0 & 2) { s.store_field("enabled", true); }
    if (var0 & 1) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 4) { s.store_object_field("custom_description", static_cast<const BaseObject *>(custom_description_.get())); }
    s.store_class_end();
  }
}

bots_setCustomVerification::ReturnType bots_setCustomVerification::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_deleteChannel::channels_deleteChannel(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_deleteChannel::ID;

void channels_deleteChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1072619549);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_deleteChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1072619549);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_deleteChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.deleteChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_deleteChannel::ReturnType channels_deleteChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_deleteHistory::channels_deleteHistory(int32 flags_, bool for_everyone_, object_ptr<InputChannel> &&channel_, int32 max_id_)
  : flags_(flags_)
  , for_everyone_(for_everyone_)
  , channel_(std::move(channel_))
  , max_id_(max_id_)
{}

const std::int32_t channels_deleteHistory::ID;

void channels_deleteHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1683319225);
  TlStoreBinary::store((var0 = flags_ | (for_everyone_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(max_id_, s);
}

void channels_deleteHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1683319225);
  TlStoreBinary::store((var0 = flags_ | (for_everyone_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(max_id_, s);
}

void channels_deleteHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.deleteHistory");
    s.store_field("flags", (var0 = flags_ | (for_everyone_ << 0)));
    if (var0 & 1) { s.store_field("for_everyone", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

channels_deleteHistory::ReturnType channels_deleteHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_getAdminLog::channels_getAdminLog(int32 flags_, object_ptr<InputChannel> &&channel_, string const &q_, object_ptr<channelAdminLogEventsFilter> &&events_filter_, array<object_ptr<InputUser>> &&admins_, int64 max_id_, int64 min_id_, int32 limit_)
  : flags_(flags_)
  , channel_(std::move(channel_))
  , q_(q_)
  , events_filter_(std::move(events_filter_))
  , admins_(std::move(admins_))
  , max_id_(max_id_)
  , min_id_(min_id_)
  , limit_(limit_)
{}

const std::int32_t channels_getAdminLog::ID;

void channels_getAdminLog::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(870184064);
  TlStoreBinary::store((var0 = flags_ | ((events_filter_ != nullptr) << 0) | ((!admins_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(q_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -368018716>::store(events_filter_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(admins_, s); }
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(limit_, s);
}

void channels_getAdminLog::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(870184064);
  TlStoreBinary::store((var0 = flags_ | ((events_filter_ != nullptr) << 0) | ((!admins_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(q_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -368018716>::store(events_filter_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(admins_, s); }
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(limit_, s);
}

void channels_getAdminLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getAdminLog");
    s.store_field("flags", (var0 = flags_ | ((events_filter_ != nullptr) << 0) | ((!admins_.empty()) << 1)));
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("q", q_);
    if (var0 & 1) { s.store_object_field("events_filter", static_cast<const BaseObject *>(events_filter_.get())); }
    if (var0 & 2) { { s.store_vector_begin("admins", admins_.size()); for (const auto &_value : admins_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

channels_getAdminLog::ReturnType channels_getAdminLog::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<channels_adminLogResults>, -309659827>::parse(p);
#undef FAIL
}

channels_readHistory::channels_readHistory(object_ptr<InputChannel> &&channel_, int32 max_id_)
  : channel_(std::move(channel_))
  , max_id_(max_id_)
{}

const std::int32_t channels_readHistory::ID;

void channels_readHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-871347913);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(max_id_, s);
}

void channels_readHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-871347913);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(max_id_, s);
}

void channels_readHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.readHistory");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

channels_readHistory::ReturnType channels_readHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_toggleAutotranslation::channels_toggleAutotranslation(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_toggleAutotranslation::ID;

void channels_toggleAutotranslation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(377471137);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleAutotranslation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(377471137);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleAutotranslation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleAutotranslation");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_toggleAutotranslation::ReturnType channels_toggleAutotranslation::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

chatlists_getLeaveChatlistSuggestions::chatlists_getLeaveChatlistSuggestions(object_ptr<inputChatlistDialogFilter> &&chatlist_)
  : chatlist_(std::move(chatlist_))
{}

const std::int32_t chatlists_getLeaveChatlistSuggestions::ID;

void chatlists_getLeaveChatlistSuggestions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-37955820);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getLeaveChatlistSuggestions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-37955820);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getLeaveChatlistSuggestions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.getLeaveChatlistSuggestions");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_class_end();
  }
}

chatlists_getLeaveChatlistSuggestions::ReturnType chatlists_getLeaveChatlistSuggestions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p);
#undef FAIL
}

chatlists_joinChatlistInvite::chatlists_joinChatlistInvite(string const &slug_, array<object_ptr<InputPeer>> &&peers_)
  : slug_(slug_)
  , peers_(std::move(peers_))
{}

const std::int32_t chatlists_joinChatlistInvite::ID;

void chatlists_joinChatlistInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1498291302);
  TlStoreString::store(slug_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_joinChatlistInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1498291302);
  TlStoreString::store(slug_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_joinChatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.joinChatlistInvite");
    s.store_field("slug", slug_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatlists_joinChatlistInvite::ReturnType chatlists_joinChatlistInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

communities_toggleParticipantBanned::communities_toggleParticipantBanned(int32 flags_, bool unban_, object_ptr<InputChannel> &&community_, object_ptr<InputPeer> &&participant_)
  : flags_(flags_)
  , unban_(unban_)
  , community_(std::move(community_))
  , participant_(std::move(participant_))
{}

const std::int32_t communities_toggleParticipantBanned::ID;

void communities_toggleParticipantBanned::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1721258737);
  TlStoreBinary::store((var0 = flags_ | (unban_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void communities_toggleParticipantBanned::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1721258737);
  TlStoreBinary::store((var0 = flags_ | (unban_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void communities_toggleParticipantBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities.toggleParticipantBanned");
    s.store_field("flags", (var0 = flags_ | (unban_ << 0)));
    if (var0 & 1) { s.store_field("unban", true); }
    s.store_object_field("community", static_cast<const BaseObject *>(community_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

communities_toggleParticipantBanned::ReturnType communities_toggleParticipantBanned::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

communities_togglePeerLink::communities_togglePeerLink(int32 flags_, bool visible_, bool hidden_, bool deleted_, object_ptr<InputChannel> &&community_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , visible_(visible_)
  , hidden_(hidden_)
  , deleted_(deleted_)
  , community_(std::move(community_))
  , peer_(std::move(peer_))
{}

const std::int32_t communities_togglePeerLink::ID;

void communities_togglePeerLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1936576490);
  TlStoreBinary::store((var0 = flags_ | (visible_ << 0) | (hidden_ << 1) | (deleted_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void communities_togglePeerLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1936576490);
  TlStoreBinary::store((var0 = flags_ | (visible_ << 0) | (hidden_ << 1) | (deleted_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void communities_togglePeerLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities.togglePeerLink");
    s.store_field("flags", (var0 = flags_ | (visible_ << 0) | (hidden_ << 1) | (deleted_ << 2)));
    if (var0 & 1) { s.store_field("visible", true); }
    if (var0 & 2) { s.store_field("hidden", true); }
    if (var0 & 4) { s.store_field("deleted", true); }
    s.store_object_field("community", static_cast<const BaseObject *>(community_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

communities_togglePeerLink::ReturnType communities_togglePeerLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

contacts_deleteContacts::contacts_deleteContacts(array<object_ptr<InputUser>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t contacts_deleteContacts::ID;

void contacts_deleteContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(157945344);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void contacts_deleteContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(157945344);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void contacts_deleteContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.deleteContacts");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

contacts_deleteContacts::ReturnType contacts_deleteContacts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

contacts_resetTopPeerRating::contacts_resetTopPeerRating(object_ptr<TopPeerCategory> &&category_, object_ptr<InputPeer> &&peer_)
  : category_(std::move(category_))
  , peer_(std::move(peer_))
{}

const std::int32_t contacts_resetTopPeerRating::ID;

void contacts_resetTopPeerRating::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(451113900);
  TlStoreBoxedUnknown<TlStoreObject>::store(category_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void contacts_resetTopPeerRating::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(451113900);
  TlStoreBoxedUnknown<TlStoreObject>::store(category_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void contacts_resetTopPeerRating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.resetTopPeerRating");
    s.store_object_field("category", static_cast<const BaseObject *>(category_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

contacts_resetTopPeerRating::ReturnType contacts_resetTopPeerRating::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

fragment_getCollectibleInfo::fragment_getCollectibleInfo(object_ptr<InputCollectible> &&collectible_)
  : collectible_(std::move(collectible_))
{}

const std::int32_t fragment_getCollectibleInfo::ID;

void fragment_getCollectibleInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1105295942);
  TlStoreBoxedUnknown<TlStoreObject>::store(collectible_, s);
}

void fragment_getCollectibleInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1105295942);
  TlStoreBoxedUnknown<TlStoreObject>::store(collectible_, s);
}

void fragment_getCollectibleInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fragment.getCollectibleInfo");
    s.store_object_field("collectible", static_cast<const BaseObject *>(collectible_.get()));
    s.store_class_end();
  }
}

fragment_getCollectibleInfo::ReturnType fragment_getCollectibleInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<fragment_collectibleInfo>, 1857945489>::parse(p);
#undef FAIL
}

help_dismissSuggestion::help_dismissSuggestion(object_ptr<InputPeer> &&peer_, string const &suggestion_)
  : peer_(std::move(peer_))
  , suggestion_(suggestion_)
{}

const std::int32_t help_dismissSuggestion::ID;

void help_dismissSuggestion::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-183649631);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(suggestion_, s);
}

void help_dismissSuggestion::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-183649631);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(suggestion_, s);
}

void help_dismissSuggestion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.dismissSuggestion");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("suggestion", suggestion_);
    s.store_class_end();
  }
}

help_dismissSuggestion::ReturnType help_dismissSuggestion::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

help_getAppUpdate::help_getAppUpdate(string const &source_)
  : source_(source_)
{}

const std::int32_t help_getAppUpdate::ID;

void help_getAppUpdate::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1378703997);
  TlStoreString::store(source_, s);
}

void help_getAppUpdate::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1378703997);
  TlStoreString::store(source_, s);
}

void help_getAppUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getAppUpdate");
    s.store_field("source", source_);
    s.store_class_end();
  }
}

help_getAppUpdate::ReturnType help_getAppUpdate::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_AppUpdate>::parse(p);
#undef FAIL
}

help_getDeepLinkInfo::help_getDeepLinkInfo(string const &path_)
  : path_(path_)
{}

const std::int32_t help_getDeepLinkInfo::ID;

void help_getDeepLinkInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1072547679);
  TlStoreString::store(path_, s);
}

void help_getDeepLinkInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1072547679);
  TlStoreString::store(path_, s);
}

void help_getDeepLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getDeepLinkInfo");
    s.store_field("path", path_);
    s.store_class_end();
  }
}

help_getDeepLinkInfo::ReturnType help_getDeepLinkInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_DeepLinkInfo>::parse(p);
#undef FAIL
}

help_getPeerColors::help_getPeerColors(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t help_getPeerColors::ID;

void help_getPeerColors::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-629083089);
  TlStoreBinary::store(hash_, s);
}

void help_getPeerColors::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-629083089);
  TlStoreBinary::store(hash_, s);
}

void help_getPeerColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getPeerColors");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getPeerColors::ReturnType help_getPeerColors::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_PeerColors>::parse(p);
#undef FAIL
}

const std::int32_t help_getPromoData::ID;

void help_getPromoData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1063816159);
}

void help_getPromoData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1063816159);
}

void help_getPromoData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getPromoData");
    s.store_class_end();
  }
}

help_getPromoData::ReturnType help_getPromoData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_PromoData>::parse(p);
#undef FAIL
}

help_setBotUpdatesStatus::help_setBotUpdatesStatus(int32 pending_updates_count_, string const &message_)
  : pending_updates_count_(pending_updates_count_)
  , message_(message_)
{}

const std::int32_t help_setBotUpdatesStatus::ID;

void help_setBotUpdatesStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-333262899);
  TlStoreBinary::store(pending_updates_count_, s);
  TlStoreString::store(message_, s);
}

void help_setBotUpdatesStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-333262899);
  TlStoreBinary::store(pending_updates_count_, s);
  TlStoreString::store(message_, s);
}

void help_setBotUpdatesStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.setBotUpdatesStatus");
    s.store_field("pending_updates_count", pending_updates_count_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

help_setBotUpdatesStatus::ReturnType help_setBotUpdatesStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_acceptUrlAuth::messages_acceptUrlAuth(int32 flags_, bool write_allowed_, bool share_phone_number_, object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 button_id_, string const &url_, string const &match_code_, object_ptr<inputTonConnectOauthSession> &&tonconnect_session_)
  : flags_(flags_)
  , write_allowed_(write_allowed_)
  , share_phone_number_(share_phone_number_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , button_id_(button_id_)
  , url_(url_)
  , match_code_(match_code_)
  , tonconnect_session_(std::move(tonconnect_session_))
{}

const std::int32_t messages_acceptUrlAuth::ID;

void messages_acceptUrlAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(417156754);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0) | (share_phone_number_ << 3) | ((peer_ != nullptr) << 1) | ((!url_.empty()) << 2) | ((!match_code_.empty()) << 4) | ((tonconnect_session_ != nullptr) << 5)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 2) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreBinary::store(button_id_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreString::store(match_code_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreObject, 1654613710>::store(tonconnect_session_, s); }
}

void messages_acceptUrlAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(417156754);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0) | (share_phone_number_ << 3) | ((peer_ != nullptr) << 1) | ((!url_.empty()) << 2) | ((!match_code_.empty()) << 4) | ((tonconnect_session_ != nullptr) << 5)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 2) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreBinary::store(button_id_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreString::store(match_code_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreObject, 1654613710>::store(tonconnect_session_, s); }
}

void messages_acceptUrlAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.acceptUrlAuth");
    s.store_field("flags", (var0 = flags_ | (write_allowed_ << 0) | (share_phone_number_ << 3) | ((peer_ != nullptr) << 1) | ((!url_.empty()) << 2) | ((!match_code_.empty()) << 4) | ((tonconnect_session_ != nullptr) << 5)));
    if (var0 & 1) { s.store_field("write_allowed", true); }
    if (var0 & 8) { s.store_field("share_phone_number", true); }
    if (var0 & 2) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 2) { s.store_field("msg_id", msg_id_); }
    if (var0 & 2) { s.store_field("button_id", button_id_); }
    if (var0 & 4) { s.store_field("url", url_); }
    if (var0 & 16) { s.store_field("match_code", match_code_); }
    if (var0 & 32) { s.store_object_field("tonconnect_session", static_cast<const BaseObject *>(tonconnect_session_.get())); }
    s.store_class_end();
  }
}

messages_acceptUrlAuth::ReturnType messages_acceptUrlAuth::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<UrlAuthResult>::parse(p);
#undef FAIL
}

messages_addChatUser::messages_addChatUser(int64 chat_id_, object_ptr<InputUser> &&user_id_, int32 fwd_limit_)
  : chat_id_(chat_id_)
  , user_id_(std::move(user_id_))
  , fwd_limit_(fwd_limit_)
{}

const std::int32_t messages_addChatUser::ID;

void messages_addChatUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-876162809);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(fwd_limit_, s);
}

void messages_addChatUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-876162809);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(fwd_limit_, s);
}

void messages_addChatUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.addChatUser");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("fwd_limit", fwd_limit_);
    s.store_class_end();
  }
}

messages_addChatUser::ReturnType messages_addChatUser::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_invitedUsers>, 2136862630>::parse(p);
#undef FAIL
}

messages_clearRecentStickers::messages_clearRecentStickers(int32 flags_, bool attached_)
  : flags_(flags_)
  , attached_(attached_)
{}

const std::int32_t messages_clearRecentStickers::ID;

void messages_clearRecentStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1986437075);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
}

void messages_clearRecentStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1986437075);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
}

void messages_clearRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.clearRecentStickers");
    s.store_field("flags", (var0 = flags_ | (attached_ << 0)));
    if (var0 & 1) { s.store_field("attached", true); }
    s.store_class_end();
  }
}

messages_clearRecentStickers::ReturnType messages_clearRecentStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deleteChat::messages_deleteChat(int64 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t messages_deleteChat::ID;

void messages_deleteChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1540419152);
  TlStoreBinary::store(chat_id_, s);
}

void messages_deleteChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1540419152);
  TlStoreBinary::store(chat_id_, s);
}

void messages_deleteChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

messages_deleteChat::ReturnType messages_deleteChat::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deleteExportedChatInvite::messages_deleteExportedChatInvite(object_ptr<InputPeer> &&peer_, string const &link_)
  : peer_(std::move(peer_))
  , link_(link_)
{}

const std::int32_t messages_deleteExportedChatInvite::ID;

void messages_deleteExportedChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-731601877);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void messages_deleteExportedChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-731601877);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void messages_deleteExportedChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteExportedChatInvite");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("link", link_);
    s.store_class_end();
  }
}

messages_deleteExportedChatInvite::ReturnType messages_deleteExportedChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deleteHistory::messages_deleteHistory(int32 flags_, bool just_clear_, bool revoke_, object_ptr<InputPeer> &&peer_, int32 max_id_, int32 min_date_, int32 max_date_)
  : flags_(flags_)
  , just_clear_(just_clear_)
  , revoke_(revoke_)
  , peer_(std::move(peer_))
  , max_id_(max_id_)
  , min_date_(min_date_)
  , max_date_(max_date_)
{}

const std::int32_t messages_deleteHistory::ID;

void messages_deleteHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1332768214);
  TlStoreBinary::store((var0 = flags_ | (just_clear_ << 0) | (revoke_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
  if (var0 & 4) { TlStoreBinary::store(min_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(max_date_, s); }
}

void messages_deleteHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1332768214);
  TlStoreBinary::store((var0 = flags_ | (just_clear_ << 0) | (revoke_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
  if (var0 & 4) { TlStoreBinary::store(min_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(max_date_, s); }
}

void messages_deleteHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteHistory");
    s.store_field("flags", (var0 = flags_ | (just_clear_ << 0) | (revoke_ << 1)));
    if (var0 & 1) { s.store_field("just_clear", true); }
    if (var0 & 2) { s.store_field("revoke", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    if (var0 & 4) { s.store_field("min_date", min_date_); }
    if (var0 & 8) { s.store_field("max_date", max_date_); }
    s.store_class_end();
  }
}

messages_deleteHistory::ReturnType messages_deleteHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_editChatAbout::messages_editChatAbout(object_ptr<InputPeer> &&peer_, string const &about_)
  : peer_(std::move(peer_))
  , about_(about_)
{}

const std::int32_t messages_editChatAbout::ID;

void messages_editChatAbout::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-554301545);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(about_, s);
}

void messages_editChatAbout::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-554301545);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(about_, s);
}

void messages_editChatAbout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatAbout");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("about", about_);
    s.store_class_end();
  }
}

messages_editChatAbout::ReturnType messages_editChatAbout::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_editChatTitle::messages_editChatTitle(int64 chat_id_, string const &title_)
  : chat_id_(chat_id_)
  , title_(title_)
{}

const std::int32_t messages_editChatTitle::ID;

void messages_editChatTitle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1937260541);
  TlStoreBinary::store(chat_id_, s);
  TlStoreString::store(title_, s);
}

void messages_editChatTitle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1937260541);
  TlStoreBinary::store(chat_id_, s);
  TlStoreString::store(title_, s);
}

void messages_editChatTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatTitle");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

messages_editChatTitle::ReturnType messages_editChatTitle::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editExportedChatInvite::messages_editExportedChatInvite(int32 flags_, bool revoked_, object_ptr<InputPeer> &&peer_, string const &link_, int32 expire_date_, int32 usage_limit_, bool request_needed_, string const &title_)
  : flags_(flags_)
  , revoked_(revoked_)
  , peer_(std::move(peer_))
  , link_(link_)
  , expire_date_(expire_date_)
  , usage_limit_(usage_limit_)
  , request_needed_(request_needed_)
  , title_(title_)
{}

const std::int32_t messages_editExportedChatInvite::ID;

void messages_editExportedChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1110823051);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 2) | ((!title_.empty()) << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
  if (var0 & 1) { TlStoreBinary::store(expire_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(usage_limit_, s); }
  if (var0 & 8) { TlStoreBool::store(request_needed_, s); }
  if (var0 & 16) { TlStoreString::store(title_, s); }
}

void messages_editExportedChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1110823051);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 2) | ((!title_.empty()) << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
  if (var0 & 1) { TlStoreBinary::store(expire_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(usage_limit_, s); }
  if (var0 & 8) { TlStoreBool::store(request_needed_, s); }
  if (var0 & 16) { TlStoreString::store(title_, s); }
}

void messages_editExportedChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editExportedChatInvite");
    s.store_field("flags", (var0 = flags_ | (revoked_ << 2) | ((!title_.empty()) << 4)));
    if (var0 & 4) { s.store_field("revoked", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("link", link_);
    if (var0 & 1) { s.store_field("expire_date", expire_date_); }
    if (var0 & 2) { s.store_field("usage_limit", usage_limit_); }
    if (var0 & 8) { s.store_field("request_needed", request_needed_); }
    if (var0 & 16) { s.store_field("title", title_); }
    s.store_class_end();
  }
}

messages_editExportedChatInvite::ReturnType messages_editExportedChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_ExportedChatInvite>::parse(p);
#undef FAIL
}

messages_editMessage::messages_editMessage(int32 flags_, bool no_webpage_, bool invert_media_, object_ptr<InputPeer> &&peer_, int32 id_, string const &message_, object_ptr<InputMedia> &&media_, object_ptr<ReplyMarkup> &&reply_markup_, array<object_ptr<MessageEntity>> &&entities_, int32 schedule_date_, int32 schedule_repeat_period_, int32 quick_reply_shortcut_id_, object_ptr<InputRichMessage> &&rich_message_)
  : flags_(flags_)
  , no_webpage_(no_webpage_)
  , invert_media_(invert_media_)
  , peer_(std::move(peer_))
  , id_(id_)
  , message_(message_)
  , media_(std::move(media_))
  , reply_markup_(std::move(reply_markup_))
  , entities_(std::move(entities_))
  , schedule_date_(schedule_date_)
  , schedule_repeat_period_(schedule_repeat_period_)
  , quick_reply_shortcut_id_(quick_reply_shortcut_id_)
  , rich_message_(std::move(rich_message_))
{}

const std::int32_t messages_editMessage::ID;

void messages_editMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1324947860);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16) | ((!message_.empty()) << 11) | ((media_ != nullptr) << 14) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((rich_message_ != nullptr) << 23)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 2048) { TlStoreString::store(message_, s); }
  if (var0 & 16384) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 32768) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 262144) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 131072) { TlStoreBinary::store(quick_reply_shortcut_id_, s); }
  if (var0 & 8388608) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
}

void messages_editMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1324947860);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16) | ((!message_.empty()) << 11) | ((media_ != nullptr) << 14) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((rich_message_ != nullptr) << 23)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 2048) { TlStoreString::store(message_, s); }
  if (var0 & 16384) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 32768) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 262144) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 131072) { TlStoreBinary::store(quick_reply_shortcut_id_, s); }
  if (var0 & 8388608) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
}

void messages_editMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editMessage");
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16) | ((!message_.empty()) << 11) | ((media_ != nullptr) << 14) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((rich_message_ != nullptr) << 23)));
    if (var0 & 2) { s.store_field("no_webpage", true); }
    if (var0 & 65536) { s.store_field("invert_media", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 2048) { s.store_field("message", message_); }
    if (var0 & 16384) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32768) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 262144) { s.store_field("schedule_repeat_period", schedule_repeat_period_); }
    if (var0 & 131072) { s.store_field("quick_reply_shortcut_id", quick_reply_shortcut_id_); }
    if (var0 & 8388608) { s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get())); }
    s.store_class_end();
  }
}

messages_editMessage::ReturnType messages_editMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getChats::messages_getChats(array<int64> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t messages_getChats::ID;

void messages_getChats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1240027791);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getChats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1240027791);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getChats");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getChats::ReturnType messages_getChats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

messages_getCommonChats::messages_getCommonChats(object_ptr<InputUser> &&user_id_, int64 max_id_, int32 limit_)
  : user_id_(std::move(user_id_))
  , max_id_(max_id_)
  , limit_(limit_)
{}

const std::int32_t messages_getCommonChats::ID;

void messages_getCommonChats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-468934396);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getCommonChats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-468934396);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getCommonChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getCommonChats");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("max_id", max_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getCommonChats::ReturnType messages_getCommonChats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

messages_getEmojiKeywords::messages_getEmojiKeywords(string const &lang_code_)
  : lang_code_(lang_code_)
{}

const std::int32_t messages_getEmojiKeywords::ID;

void messages_getEmojiKeywords::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(899735650);
  TlStoreString::store(lang_code_, s);
}

void messages_getEmojiKeywords::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(899735650);
  TlStoreString::store(lang_code_, s);
}

void messages_getEmojiKeywords::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiKeywords");
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

messages_getEmojiKeywords::ReturnType messages_getEmojiKeywords::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<emojiKeywordsDifference>, 1556570557>::parse(p);
#undef FAIL
}

messages_getEmojiStickers::messages_getEmojiStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getEmojiStickers::ID;

void messages_getEmojiStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-67329649);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-67329649);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getEmojiStickers::ReturnType messages_getEmojiStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_AllStickers>::parse(p);
#undef FAIL
}

messages_getExportedChatInvite::messages_getExportedChatInvite(object_ptr<InputPeer> &&peer_, string const &link_)
  : peer_(std::move(peer_))
  , link_(link_)
{}

const std::int32_t messages_getExportedChatInvite::ID;

void messages_getExportedChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1937010524);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void messages_getExportedChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1937010524);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void messages_getExportedChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getExportedChatInvite");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("link", link_);
    s.store_class_end();
  }
}

messages_getExportedChatInvite::ReturnType messages_getExportedChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_ExportedChatInvite>::parse(p);
#undef FAIL
}

messages_getExportedChatInvites::messages_getExportedChatInvites(int32 flags_, bool revoked_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&admin_id_, int32 offset_date_, string const &offset_link_, int32 limit_)
  : flags_(flags_)
  , revoked_(revoked_)
  , peer_(std::move(peer_))
  , admin_id_(std::move(admin_id_))
  , offset_date_(offset_date_)
  , offset_link_(offset_link_)
  , limit_(limit_)
{}

const std::int32_t messages_getExportedChatInvites::ID;

void messages_getExportedChatInvites::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1565154314);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 3) | ((!offset_link_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(admin_id_, s);
  if (var0 & 4) { TlStoreBinary::store(offset_date_, s); }
  if (var0 & 4) { TlStoreString::store(offset_link_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getExportedChatInvites::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1565154314);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 3) | ((!offset_link_.empty()) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(admin_id_, s);
  if (var0 & 4) { TlStoreBinary::store(offset_date_, s); }
  if (var0 & 4) { TlStoreString::store(offset_link_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getExportedChatInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getExportedChatInvites");
    s.store_field("flags", (var0 = flags_ | (revoked_ << 3) | ((!offset_link_.empty()) << 2)));
    if (var0 & 8) { s.store_field("revoked", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("admin_id", static_cast<const BaseObject *>(admin_id_.get()));
    if (var0 & 4) { s.store_field("offset_date", offset_date_); }
    if (var0 & 4) { s.store_field("offset_link", offset_link_); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getExportedChatInvites::ReturnType messages_getExportedChatInvites::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_exportedChatInvites>, -1111085620>::parse(p);
#undef FAIL
}

messages_getFeaturedStickers::messages_getFeaturedStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getFeaturedStickers::ID;

void messages_getFeaturedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1685588756);
  TlStoreBinary::store(hash_, s);
}

void messages_getFeaturedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1685588756);
  TlStoreBinary::store(hash_, s);
}

void messages_getFeaturedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFeaturedStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getFeaturedStickers::ReturnType messages_getFeaturedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FeaturedStickers>::parse(p);
#undef FAIL
}

messages_getGameHighScores::messages_getGameHighScores(object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<InputUser> &&user_id_)
  : peer_(std::move(peer_))
  , id_(id_)
  , user_id_(std::move(user_id_))
{}

const std::int32_t messages_getGameHighScores::ID;

void messages_getGameHighScores::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-400399203);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_getGameHighScores::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-400399203);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_getGameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getGameHighScores");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

messages_getGameHighScores::ReturnType messages_getGameHighScores::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_highScores>, -1707344487>::parse(p);
#undef FAIL
}

messages_getMessageEditData::messages_getMessageEditData(object_ptr<InputPeer> &&peer_, int32 id_)
  : peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t messages_getMessageEditData::ID;

void messages_getMessageEditData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-39416522);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void messages_getMessageEditData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-39416522);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void messages_getMessageEditData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessageEditData");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

messages_getMessageEditData::ReturnType messages_getMessageEditData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_messageEditData>, 649453030>::parse(p);
#undef FAIL
}

messages_getOldFeaturedStickers::messages_getOldFeaturedStickers(int32 offset_, int32 limit_, int64 hash_)
  : offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getOldFeaturedStickers::ID;

void messages_getOldFeaturedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2127598753);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getOldFeaturedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2127598753);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getOldFeaturedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getOldFeaturedStickers");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getOldFeaturedStickers::ReturnType messages_getOldFeaturedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FeaturedStickers>::parse(p);
#undef FAIL
}

messages_getSavedHistory::messages_getSavedHistory(int32 flags_, object_ptr<InputPeer> &&parent_peer_, object_ptr<InputPeer> &&peer_, int32 offset_id_, int32 offset_date_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_, int64 hash_)
  : flags_(flags_)
  , parent_peer_(std::move(parent_peer_))
  , peer_(std::move(peer_))
  , offset_id_(offset_id_)
  , offset_date_(offset_date_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
  , hash_(hash_)
{}

const std::int32_t messages_getSavedHistory::ID;

void messages_getSavedHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1718964215);
  TlStoreBinary::store((var0 = flags_ | ((parent_peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1718964215);
  TlStoreBinary::store((var0 = flags_ | ((parent_peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSavedHistory");
    s.store_field("flags", (var0 = flags_ | ((parent_peer_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("offset_date", offset_date_);
    s.store_field("add_offset", add_offset_);
    s.store_field("limit", limit_);
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getSavedHistory::ReturnType messages_getSavedHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

const std::int32_t messages_getSplitRanges::ID;

void messages_getSplitRanges::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(486505992);
}

void messages_getSplitRanges::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(486505992);
}

void messages_getSplitRanges::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSplitRanges");
    s.store_class_end();
  }
}

messages_getSplitRanges::ReturnType messages_getSplitRanges::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messageRange>, 182649427>>, 481674261>::parse(p);
#undef FAIL
}

messages_getTranscriptionLangs::messages_getTranscriptionLangs(int32 flags_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , peer_(std::move(peer_))
{}

const std::int32_t messages_getTranscriptionLangs::ID;

void messages_getTranscriptionLangs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1167271510);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
}

void messages_getTranscriptionLangs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1167271510);
  TlStoreBinary::store((var0 = flags_ | ((peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
}

void messages_getTranscriptionLangs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getTranscriptionLangs");
    s.store_field("flags", (var0 = flags_ | ((peer_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_class_end();
  }
}

messages_getTranscriptionLangs::ReturnType messages_getTranscriptionLangs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p);
#undef FAIL
}

messages_reorderQuickReplies::messages_reorderQuickReplies(array<int32> &&order_)
  : order_(std::move(order_))
{}

const std::int32_t messages_reorderQuickReplies::ID;

void messages_reorderQuickReplies::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1613961479);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderQuickReplies::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1613961479);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderQuickReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reorderQuickReplies");
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reorderQuickReplies::ReturnType messages_reorderQuickReplies::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_searchStickerSets::messages_searchStickerSets(int32 flags_, bool exclude_featured_, string const &q_, int64 hash_)
  : flags_(flags_)
  , exclude_featured_(exclude_featured_)
  , q_(q_)
  , hash_(hash_)
{}

const std::int32_t messages_searchStickerSets::ID;

void messages_searchStickerSets::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(896555914);
  TlStoreBinary::store((var0 = flags_ | (exclude_featured_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchStickerSets::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(896555914);
  TlStoreBinary::store((var0 = flags_ | (exclude_featured_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchStickerSets");
    s.store_field("flags", (var0 = flags_ | (exclude_featured_ << 0)));
    if (var0 & 1) { s.store_field("exclude_featured", true); }
    s.store_field("q", q_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_searchStickerSets::ReturnType messages_searchStickerSets::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FoundStickerSets>::parse(p);
#undef FAIL
}

messages_sendBotRequestedPeer::messages_sendBotRequestedPeer(int32 flags_, object_ptr<InputPeer> &&peer_, int32 msg_id_, string const &webapp_req_id_, int32 button_id_, array<object_ptr<InputPeer>> &&requested_peers_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , webapp_req_id_(webapp_req_id_)
  , button_id_(button_id_)
  , requested_peers_(std::move(requested_peers_))
{}

const std::int32_t messages_sendBotRequestedPeer::ID;

void messages_sendBotRequestedPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1818030759);
  TlStoreBinary::store((var0 = flags_ | ((!webapp_req_id_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreString::store(webapp_req_id_, s); }
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(requested_peers_, s);
}

void messages_sendBotRequestedPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1818030759);
  TlStoreBinary::store((var0 = flags_ | ((!webapp_req_id_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreString::store(webapp_req_id_, s); }
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(requested_peers_, s);
}

void messages_sendBotRequestedPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendBotRequestedPeer");
    s.store_field("flags", (var0 = flags_ | ((!webapp_req_id_.empty()) << 1)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("msg_id", msg_id_); }
    if (var0 & 2) { s.store_field("webapp_req_id", webapp_req_id_); }
    s.store_field("button_id", button_id_);
    { s.store_vector_begin("requested_peers", requested_peers_.size()); for (const auto &_value : requested_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_sendBotRequestedPeer::ReturnType messages_sendBotRequestedPeer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_sendEncryptedService::messages_sendEncryptedService(object_ptr<inputEncryptedChat> &&peer_, int64 random_id_, bytes &&data_)
  : peer_(std::move(peer_))
  , random_id_(random_id_)
  , data_(std::move(data_))
{}

const std::int32_t messages_sendEncryptedService::ID;

void messages_sendEncryptedService::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(852769188);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
}

void messages_sendEncryptedService::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(852769188);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
}

void messages_sendEncryptedService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendEncryptedService");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("random_id", random_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

messages_sendEncryptedService::ReturnType messages_sendEncryptedService::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SentEncryptedMessage>::parse(p);
#undef FAIL
}

messages_sendWebViewData::messages_sendWebViewData(object_ptr<InputUser> &&bot_, int64 random_id_, string const &button_text_, string const &data_)
  : bot_(std::move(bot_))
  , random_id_(random_id_)
  , button_text_(button_text_)
  , data_(data_)
{}

const std::int32_t messages_sendWebViewData::ID;

void messages_sendWebViewData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-603831608);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(button_text_, s);
  TlStoreString::store(data_, s);
}

void messages_sendWebViewData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-603831608);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(button_text_, s);
  TlStoreString::store(data_, s);
}

void messages_sendWebViewData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendWebViewData");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("random_id", random_id_);
    s.store_field("button_text", button_text_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

messages_sendWebViewData::ReturnType messages_sendWebViewData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setInlineBotResults::messages_setInlineBotResults(int32 flags_, bool gallery_, bool private_, int64 query_id_, array<object_ptr<InputBotInlineResult>> &&results_, int32 cache_time_, string const &next_offset_, object_ptr<inlineBotSwitchPM> &&switch_pm_, object_ptr<inlineBotWebView> &&switch_webview_)
  : flags_(flags_)
  , gallery_(gallery_)
  , private_(private_)
  , query_id_(query_id_)
  , results_(std::move(results_))
  , cache_time_(cache_time_)
  , next_offset_(next_offset_)
  , switch_pm_(std::move(switch_pm_))
  , switch_webview_(std::move(switch_webview_))
{}

const std::int32_t messages_setInlineBotResults::ID;

void messages_setInlineBotResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1156406247);
  TlStoreBinary::store((var0 = flags_ | (gallery_ << 0) | (private_ << 1) | ((!next_offset_.empty()) << 2) | ((switch_pm_ != nullptr) << 3) | ((switch_webview_ != nullptr) << 4)), s);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(results_, s);
  TlStoreBinary::store(cache_time_, s);
  if (var0 & 4) { TlStoreString::store(next_offset_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 1008755359>::store(switch_pm_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreObject, -1250781739>::store(switch_webview_, s); }
}

void messages_setInlineBotResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1156406247);
  TlStoreBinary::store((var0 = flags_ | (gallery_ << 0) | (private_ << 1) | ((!next_offset_.empty()) << 2) | ((switch_pm_ != nullptr) << 3) | ((switch_webview_ != nullptr) << 4)), s);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(results_, s);
  TlStoreBinary::store(cache_time_, s);
  if (var0 & 4) { TlStoreString::store(next_offset_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 1008755359>::store(switch_pm_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreObject, -1250781739>::store(switch_webview_, s); }
}

void messages_setInlineBotResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setInlineBotResults");
    s.store_field("flags", (var0 = flags_ | (gallery_ << 0) | (private_ << 1) | ((!next_offset_.empty()) << 2) | ((switch_pm_ != nullptr) << 3) | ((switch_webview_ != nullptr) << 4)));
    if (var0 & 1) { s.store_field("gallery", true); }
    if (var0 & 2) { s.store_field("private", true); }
    s.store_field("query_id", query_id_);
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("cache_time", cache_time_);
    if (var0 & 4) { s.store_field("next_offset", next_offset_); }
    if (var0 & 8) { s.store_object_field("switch_pm", static_cast<const BaseObject *>(switch_pm_.get())); }
    if (var0 & 16) { s.store_object_field("switch_webview", static_cast<const BaseObject *>(switch_webview_.get())); }
    s.store_class_end();
  }
}

messages_setInlineBotResults::ReturnType messages_setInlineBotResults::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_toggleTodoCompleted::messages_toggleTodoCompleted(object_ptr<InputPeer> &&peer_, int32 msg_id_, array<int32> &&completed_, array<int32> &&incompleted_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , completed_(std::move(completed_))
  , incompleted_(std::move(incompleted_))
{}

const std::int32_t messages_toggleTodoCompleted::ID;

void messages_toggleTodoCompleted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-740282076);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(completed_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(incompleted_, s);
}

void messages_toggleTodoCompleted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-740282076);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(completed_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(incompleted_, s);
}

void messages_toggleTodoCompleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleTodoCompleted");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    { s.store_vector_begin("completed", completed_.size()); for (const auto &_value : completed_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("incompleted", incompleted_.size()); for (const auto &_value : incompleted_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_toggleTodoCompleted::ReturnType messages_toggleTodoCompleted::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_declineStarGiftOnchainOffer::payments_declineStarGiftOnchainOffer(int32 offer_msg_id_)
  : offer_msg_id_(offer_msg_id_)
{}

const std::int32_t payments_declineStarGiftOnchainOffer::ID;

void payments_declineStarGiftOnchainOffer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1511098022);
  TlStoreBinary::store(offer_msg_id_, s);
}

void payments_declineStarGiftOnchainOffer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1511098022);
  TlStoreBinary::store(offer_msg_id_, s);
}

void payments_declineStarGiftOnchainOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.declineStarGiftOnchainOffer");
    s.store_field("offer_msg_id", offer_msg_id_);
    s.store_class_end();
  }
}

payments_declineStarGiftOnchainOffer::ReturnType payments_declineStarGiftOnchainOffer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t payments_getCurrencyRates::ID;

void payments_getCurrencyRates::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-749108248);
}

void payments_getCurrencyRates::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-749108248);
}

void payments_getCurrencyRates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getCurrencyRates");
    s.store_class_end();
  }
}

payments_getCurrencyRates::ReturnType payments_getCurrencyRates::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_currencyRates>, -1144199998>::parse(p);
#undef FAIL
}

payments_getOnrampProviders::payments_getOnrampProviders(int32 flags_, string const &crypto_currency_)
  : flags_(flags_)
  , crypto_currency_(crypto_currency_)
{}

const std::int32_t payments_getOnrampProviders::ID;

void payments_getOnrampProviders::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1061028060);
  TlStoreBinary::store((var0 = flags_ | ((!crypto_currency_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(crypto_currency_, s); }
}

void payments_getOnrampProviders::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1061028060);
  TlStoreBinary::store((var0 = flags_ | ((!crypto_currency_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(crypto_currency_, s); }
}

void payments_getOnrampProviders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getOnrampProviders");
    s.store_field("flags", (var0 = flags_ | ((!crypto_currency_.empty()) << 0)));
    if (var0 & 1) { s.store_field("crypto_currency", crypto_currency_); }
    s.store_class_end();
  }
}

payments_getOnrampProviders::ReturnType payments_getOnrampProviders::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<onrampProviderInfo>, 230847874>>, 481674261>::parse(p);
#undef FAIL
}

payments_getOnrampQuote::payments_getOnrampQuote(int32 flags_, string const &provider_, string const &crypto_currency_, string const &base_currency_, string const &base_amount_, string const &crypto_amount_, string const &payment_method_)
  : flags_(flags_)
  , provider_(provider_)
  , crypto_currency_(crypto_currency_)
  , base_currency_(base_currency_)
  , base_amount_(base_amount_)
  , crypto_amount_(crypto_amount_)
  , payment_method_(payment_method_)
{}

const std::int32_t payments_getOnrampQuote::ID;

void payments_getOnrampQuote::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-530168326);
  TlStoreBinary::store((var0 = flags_ | ((!base_amount_.empty()) << 0) | ((!crypto_amount_.empty()) << 1) | ((!payment_method_.empty()) << 2)), s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(crypto_currency_, s);
  TlStoreString::store(base_currency_, s);
  if (var0 & 1) { TlStoreString::store(base_amount_, s); }
  if (var0 & 2) { TlStoreString::store(crypto_amount_, s); }
  if (var0 & 4) { TlStoreString::store(payment_method_, s); }
}

void payments_getOnrampQuote::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-530168326);
  TlStoreBinary::store((var0 = flags_ | ((!base_amount_.empty()) << 0) | ((!crypto_amount_.empty()) << 1) | ((!payment_method_.empty()) << 2)), s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(crypto_currency_, s);
  TlStoreString::store(base_currency_, s);
  if (var0 & 1) { TlStoreString::store(base_amount_, s); }
  if (var0 & 2) { TlStoreString::store(crypto_amount_, s); }
  if (var0 & 4) { TlStoreString::store(payment_method_, s); }
}

void payments_getOnrampQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getOnrampQuote");
    s.store_field("flags", (var0 = flags_ | ((!base_amount_.empty()) << 0) | ((!crypto_amount_.empty()) << 1) | ((!payment_method_.empty()) << 2)));
    s.store_field("provider", provider_);
    s.store_field("crypto_currency", crypto_currency_);
    s.store_field("base_currency", base_currency_);
    if (var0 & 1) { s.store_field("base_amount", base_amount_); }
    if (var0 & 2) { s.store_field("crypto_amount", crypto_amount_); }
    if (var0 & 4) { s.store_field("payment_method", payment_method_); }
    s.store_class_end();
  }
}

payments_getOnrampQuote::ReturnType payments_getOnrampQuote::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<onrampQuote>, 2055213545>::parse(p);
#undef FAIL
}

payments_getSavedStarGift::payments_getSavedStarGift(array<object_ptr<InputSavedStarGift>> &&stargift_)
  : stargift_(std::move(stargift_))
{}

const std::int32_t payments_getSavedStarGift::ID;

void payments_getSavedStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1269456634);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_getSavedStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1269456634);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_getSavedStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getSavedStarGift");
    { s.store_vector_begin("stargift", stargift_.size()); for (const auto &_value : stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_getSavedStarGift::ReturnType payments_getSavedStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_savedStarGifts>, -1779201615>::parse(p);
#undef FAIL
}

payments_getStarsRevenueAdsAccountUrl::payments_getStarsRevenueAdsAccountUrl(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t payments_getStarsRevenueAdsAccountUrl::ID;

void payments_getStarsRevenueAdsAccountUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-774377531);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsRevenueAdsAccountUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-774377531);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsRevenueAdsAccountUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsRevenueAdsAccountUrl");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

payments_getStarsRevenueAdsAccountUrl::ReturnType payments_getStarsRevenueAdsAccountUrl::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsRevenueAdsAccountUrl>, 961445665>::parse(p);
#undef FAIL
}

payments_getStarsStatus::payments_getStarsStatus(int32 flags_, bool ton_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , ton_(ton_)
  , peer_(std::move(peer_))
{}

const std::int32_t payments_getStarsStatus::ID;

void payments_getStarsStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1319744447);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1319744447);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsStatus");
    s.store_field("flags", (var0 = flags_ | (ton_ << 0)));
    if (var0 & 1) { s.store_field("ton", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

payments_getStarsStatus::ReturnType payments_getStarsStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsStatus>, 1822222573>::parse(p);
#undef FAIL
}

payments_getStarsTransactions::payments_getStarsTransactions(int32 flags_, bool inbound_, bool outbound_, bool ascending_, bool ton_, string const &subscription_id_, object_ptr<InputPeer> &&peer_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , inbound_(inbound_)
  , outbound_(outbound_)
  , ascending_(ascending_)
  , ton_(ton_)
  , subscription_id_(subscription_id_)
  , peer_(std::move(peer_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t payments_getStarsTransactions::ID;

void payments_getStarsTransactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1775912279);
  TlStoreBinary::store((var0 = flags_ | (inbound_ << 0) | (outbound_ << 1) | (ascending_ << 2) | (ton_ << 4) | ((!subscription_id_.empty()) << 3)), s);
  if (var0 & 8) { TlStoreString::store(subscription_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getStarsTransactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1775912279);
  TlStoreBinary::store((var0 = flags_ | (inbound_ << 0) | (outbound_ << 1) | (ascending_ << 2) | (ton_ << 4) | ((!subscription_id_.empty()) << 3)), s);
  if (var0 & 8) { TlStoreString::store(subscription_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getStarsTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsTransactions");
    s.store_field("flags", (var0 = flags_ | (inbound_ << 0) | (outbound_ << 1) | (ascending_ << 2) | (ton_ << 4) | ((!subscription_id_.empty()) << 3)));
    if (var0 & 1) { s.store_field("inbound", true); }
    if (var0 & 2) { s.store_field("outbound", true); }
    if (var0 & 4) { s.store_field("ascending", true); }
    if (var0 & 16) { s.store_field("ton", true); }
    if (var0 & 8) { s.store_field("subscription_id", subscription_id_); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getStarsTransactions::ReturnType payments_getStarsTransactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsStatus>, 1822222573>::parse(p);
#undef FAIL
}

payments_getUniqueStarGiftValueInfo::payments_getUniqueStarGiftValueInfo(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t payments_getUniqueStarGiftValueInfo::ID;

void payments_getUniqueStarGiftValueInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1130737515);
  TlStoreString::store(slug_, s);
}

void payments_getUniqueStarGiftValueInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1130737515);
  TlStoreString::store(slug_, s);
}

void payments_getUniqueStarGiftValueInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getUniqueStarGiftValueInfo");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

payments_getUniqueStarGiftValueInfo::ReturnType payments_getUniqueStarGiftValueInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_uniqueStarGiftValueInfo>, 1362093126>::parse(p);
#undef FAIL
}

phone_editGroupCallParticipant::phone_editGroupCallParticipant(int32 flags_, object_ptr<InputGroupCall> &&call_, object_ptr<InputPeer> &&participant_, bool muted_, int32 volume_, bool raise_hand_, bool video_stopped_, bool video_paused_, bool presentation_paused_)
  : flags_(flags_)
  , call_(std::move(call_))
  , participant_(std::move(participant_))
  , muted_(muted_)
  , volume_(volume_)
  , raise_hand_(raise_hand_)
  , video_stopped_(video_stopped_)
  , video_paused_(video_paused_)
  , presentation_paused_(presentation_paused_)
{}

const std::int32_t phone_editGroupCallParticipant::ID;

void phone_editGroupCallParticipant::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1524155713);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  if (var0 & 1) { TlStoreBool::store(muted_, s); }
  if (var0 & 2) { TlStoreBinary::store(volume_, s); }
  if (var0 & 4) { TlStoreBool::store(raise_hand_, s); }
  if (var0 & 8) { TlStoreBool::store(video_stopped_, s); }
  if (var0 & 16) { TlStoreBool::store(video_paused_, s); }
  if (var0 & 32) { TlStoreBool::store(presentation_paused_, s); }
}

void phone_editGroupCallParticipant::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1524155713);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  if (var0 & 1) { TlStoreBool::store(muted_, s); }
  if (var0 & 2) { TlStoreBinary::store(volume_, s); }
  if (var0 & 4) { TlStoreBool::store(raise_hand_, s); }
  if (var0 & 8) { TlStoreBool::store(video_stopped_, s); }
  if (var0 & 16) { TlStoreBool::store(video_paused_, s); }
  if (var0 & 32) { TlStoreBool::store(presentation_paused_, s); }
}

void phone_editGroupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.editGroupCallParticipant");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    if (var0 & 1) { s.store_field("muted", muted_); }
    if (var0 & 2) { s.store_field("volume", volume_); }
    if (var0 & 4) { s.store_field("raise_hand", raise_hand_); }
    if (var0 & 8) { s.store_field("video_stopped", video_stopped_); }
    if (var0 & 16) { s.store_field("video_paused", video_paused_); }
    if (var0 & 32) { s.store_field("presentation_paused", presentation_paused_); }
    s.store_class_end();
  }
}

phone_editGroupCallParticipant::ReturnType phone_editGroupCallParticipant::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_exportGroupCallInvite::phone_exportGroupCallInvite(int32 flags_, bool can_self_unmute_, object_ptr<InputGroupCall> &&call_)
  : flags_(flags_)
  , can_self_unmute_(can_self_unmute_)
  , call_(std::move(call_))
{}

const std::int32_t phone_exportGroupCallInvite::ID;

void phone_exportGroupCallInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-425040769);
  TlStoreBinary::store((var0 = flags_ | (can_self_unmute_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_exportGroupCallInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-425040769);
  TlStoreBinary::store((var0 = flags_ | (can_self_unmute_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_exportGroupCallInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.exportGroupCallInvite");
    s.store_field("flags", (var0 = flags_ | (can_self_unmute_ << 0)));
    if (var0 & 1) { s.store_field("can_self_unmute", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_exportGroupCallInvite::ReturnType phone_exportGroupCallInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_exportedGroupCallInvite>, 541839704>::parse(p);
#undef FAIL
}

phone_saveCallLog::phone_saveCallLog(object_ptr<inputPhoneCall> &&peer_, object_ptr<InputFile> &&file_)
  : peer_(std::move(peer_))
  , file_(std::move(file_))
{}

const std::int32_t phone_saveCallLog::ID;

void phone_saveCallLog::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1092913030);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void phone_saveCallLog::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1092913030);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void phone_saveCallLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.saveCallLog");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

phone_saveCallLog::ReturnType phone_saveCallLog::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_sendConferenceCallBroadcast::phone_sendConferenceCallBroadcast(object_ptr<InputGroupCall> &&call_, bytes &&block_)
  : call_(std::move(call_))
  , block_(std::move(block_))
{}

const std::int32_t phone_sendConferenceCallBroadcast::ID;

void phone_sendConferenceCallBroadcast::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-965732096);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(block_, s);
}

void phone_sendConferenceCallBroadcast::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-965732096);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(block_, s);
}

void phone_sendConferenceCallBroadcast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.sendConferenceCallBroadcast");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_bytes_field("block", block_);
    s.store_class_end();
  }
}

phone_sendConferenceCallBroadcast::ReturnType phone_sendConferenceCallBroadcast::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

stats_getBroadcastStats::stats_getBroadcastStats(int32 flags_, bool dark_, object_ptr<InputChannel> &&channel_)
  : flags_(flags_)
  , dark_(dark_)
  , channel_(std::move(channel_))
{}

const std::int32_t stats_getBroadcastStats::ID;

void stats_getBroadcastStats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1421720550);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void stats_getBroadcastStats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1421720550);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void stats_getBroadcastStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getBroadcastStats");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0)));
    if (var0 & 1) { s.store_field("dark", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

stats_getBroadcastStats::ReturnType stats_getBroadcastStats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_broadcastStats>, 963421692>::parse(p);
#undef FAIL
}

stickers_changeStickerPosition::stickers_changeStickerPosition(object_ptr<InputDocument> &&sticker_, int32 position_)
  : sticker_(std::move(sticker_))
  , position_(position_)
{}

const std::int32_t stickers_changeStickerPosition::ID;

void stickers_changeStickerPosition::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-4795190);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBinary::store(position_, s);
}

void stickers_changeStickerPosition::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-4795190);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBinary::store(position_, s);
}

void stickers_changeStickerPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.changeStickerPosition");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("position", position_);
    s.store_class_end();
  }
}

stickers_changeStickerPosition::ReturnType stickers_changeStickerPosition::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stories_getPinnedStories::stories_getPinnedStories(object_ptr<InputPeer> &&peer_, int32 offset_id_, int32 limit_)
  : peer_(std::move(peer_))
  , offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t stories_getPinnedStories::ID;

void stories_getPinnedStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1478600156);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getPinnedStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1478600156);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getPinnedStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getPinnedStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_getPinnedStories::ReturnType stories_getPinnedStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_stories>, 1673780490>::parse(p);
#undef FAIL
}

stories_getStoryReactionsList::stories_getStoryReactionsList(int32 flags_, bool forwards_first_, object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<Reaction> &&reaction_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , forwards_first_(forwards_first_)
  , peer_(std::move(peer_))
  , id_(id_)
  , reaction_(std::move(reaction_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stories_getStoryReactionsList::ID;

void stories_getStoryReactionsList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1179482081);
  TlStoreBinary::store((var0 = flags_ | (forwards_first_ << 2) | ((reaction_ != nullptr) << 0) | ((!offset_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void stories_getStoryReactionsList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1179482081);
  TlStoreBinary::store((var0 = flags_ | (forwards_first_ << 2) | ((reaction_ != nullptr) << 0) | ((!offset_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void stories_getStoryReactionsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getStoryReactionsList");
    s.store_field("flags", (var0 = flags_ | (forwards_first_ << 2) | ((reaction_ != nullptr) << 0) | ((!offset_.empty()) << 1)));
    if (var0 & 4) { s.store_field("forwards_first", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get())); }
    if (var0 & 2) { s.store_field("offset", offset_); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_getStoryReactionsList::ReturnType stories_getStoryReactionsList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_storyReactionsList>, -1436583780>::parse(p);
#undef FAIL
}

stories_getStoryViewsList::stories_getStoryViewsList(int32 flags_, bool just_contacts_, bool reactions_first_, bool forwards_first_, object_ptr<InputPeer> &&peer_, string const &q_, int32 id_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , just_contacts_(just_contacts_)
  , reactions_first_(reactions_first_)
  , forwards_first_(forwards_first_)
  , peer_(std::move(peer_))
  , q_(q_)
  , id_(id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stories_getStoryViewsList::ID;

void stories_getStoryViewsList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2127707223);
  TlStoreBinary::store((var0 = flags_ | (just_contacts_ << 0) | (reactions_first_ << 2) | (forwards_first_ << 3) | ((!q_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getStoryViewsList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2127707223);
  TlStoreBinary::store((var0 = flags_ | (just_contacts_ << 0) | (reactions_first_ << 2) | (forwards_first_ << 3) | ((!q_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getStoryViewsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getStoryViewsList");
    s.store_field("flags", (var0 = flags_ | (just_contacts_ << 0) | (reactions_first_ << 2) | (forwards_first_ << 3) | ((!q_.empty()) << 1)));
    if (var0 & 1) { s.store_field("just_contacts", true); }
    if (var0 & 4) { s.store_field("reactions_first", true); }
    if (var0 & 8) { s.store_field("forwards_first", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_field("q", q_); }
    s.store_field("id", id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_getStoryViewsList::ReturnType stories_getStoryViewsList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_storyViewsList>, 1507299269>::parse(p);
#undef FAIL
}

const std::int32_t test_useConfigSimple::ID;

void test_useConfigSimple::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-105401795);
}

void test_useConfigSimple::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-105401795);
}

void test_useConfigSimple::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "test.useConfigSimple");
    s.store_class_end();
  }
}

test_useConfigSimple::ReturnType test_useConfigSimple::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_configSimple>, 1515793004>::parse(p);
#undef FAIL
}

toncenter_performApiRequest::toncenter_performApiRequest(int32 flags_, bool post_, string const &endpoint_, string const &query_, string const &payload_)
  : flags_(flags_)
  , post_(post_)
  , endpoint_(endpoint_)
  , query_(query_)
  , payload_(payload_)
{}

const std::int32_t toncenter_performApiRequest::ID;

void toncenter_performApiRequest::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1921262239);
  TlStoreBinary::store((var0 = flags_ | (post_ << 0) | ((!query_.empty()) << 1) | ((!payload_.empty()) << 2)), s);
  TlStoreString::store(endpoint_, s);
  if (var0 & 2) { TlStoreString::store(query_, s); }
  if (var0 & 4) { TlStoreString::store(payload_, s); }
}

void toncenter_performApiRequest::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1921262239);
  TlStoreBinary::store((var0 = flags_ | (post_ << 0) | ((!query_.empty()) << 1) | ((!payload_.empty()) << 2)), s);
  TlStoreString::store(endpoint_, s);
  if (var0 & 2) { TlStoreString::store(query_, s); }
  if (var0 & 4) { TlStoreString::store(payload_, s); }
}

void toncenter_performApiRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toncenter.performApiRequest");
    s.store_field("flags", (var0 = flags_ | (post_ << 0) | ((!query_.empty()) << 1) | ((!payload_.empty()) << 2)));
    if (var0 & 1) { s.store_field("post", true); }
    s.store_field("endpoint", endpoint_);
    if (var0 & 2) { s.store_field("query", query_); }
    if (var0 & 4) { s.store_field("payload", payload_); }
    s.store_class_end();
  }
}

toncenter_performApiRequest::ReturnType toncenter_performApiRequest::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<toncenter_apiResponse>, -1399980519>::parse(p);
#undef FAIL
}

const std::int32_t updates_getState::ID;

void updates_getState::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-304838614);
}

void updates_getState::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-304838614);
}

void updates_getState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.getState");
    s.store_class_end();
  }
}

updates_getState::ReturnType updates_getState::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<updates_state>, -1519637954>::parse(p);
#undef FAIL
}

users_getFullUser::users_getFullUser(object_ptr<InputUser> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t users_getFullUser::ID;

void users_getFullUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1240508136);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void users_getFullUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1240508136);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void users_getFullUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.getFullUser");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

users_getFullUser::ReturnType users_getFullUser::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<users_userFull>, 997004590>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
