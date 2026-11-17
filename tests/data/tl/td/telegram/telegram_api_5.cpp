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


object_ptr<AiComposeTone> AiComposeTone::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case aiComposeTone::ID:
      return aiComposeTone::fetch(p);
    case aiComposeToneDefault::ID:
      return aiComposeToneDefault::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

aiComposeTone::aiComposeTone()
  : flags_()
  , creator_()
  , id_()
  , access_hash_()
  , slug_()
  , title_()
  , emoji_id_()
  , prompt_()
  , installs_count_()
  , author_id_()
  , example_english_()
{}

const std::int32_t aiComposeTone::ID;

object_ptr<AiComposeTone> aiComposeTone::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<aiComposeTone> res = make_tl_object<aiComposeTone>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->slug_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->emoji_id_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->prompt_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->installs_count_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->author_id_ = TlFetchLong::parse(p); }
  if (var0 & 32) { res->example_english_ = TlFetchBoxed<TlFetchObject<aiComposeToneExample>, -237623060>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void aiComposeTone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aiComposeTone");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | ((!prompt_.empty()) << 4) | ((example_english_ != nullptr) << 5)));
    if (var0 & 1) { s.store_field("creator", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("slug", slug_);
    s.store_field("title", title_);
    if (var0 & 2) { s.store_field("emoji_id", emoji_id_); }
    if (var0 & 16) { s.store_field("prompt", prompt_); }
    if (var0 & 4) { s.store_field("installs_count", installs_count_); }
    if (var0 & 8) { s.store_field("author_id", author_id_); }
    if (var0 & 32) { s.store_object_field("example_english", static_cast<const BaseObject *>(example_english_.get())); }
    s.store_class_end();
  }
}

const std::int32_t aiComposeToneDefault::ID;

object_ptr<AiComposeTone> aiComposeToneDefault::fetch(TlBufferParser &p) {
  return make_tl_object<aiComposeToneDefault>(p);
}

aiComposeToneDefault::aiComposeToneDefault(TlBufferParser &p)
  : tone_(TlFetchString<string>::parse(p))
  , emoji_id_(TlFetchLong::parse(p))
  , title_(TlFetchString<string>::parse(p))
{}

void aiComposeToneDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aiComposeToneDefault");
    s.store_field("tone", tone_);
    s.store_field("emoji_id", emoji_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

autoDownloadSettings::autoDownloadSettings()
  : flags_()
  , disabled_()
  , video_preload_large_()
  , audio_preload_next_()
  , phonecalls_less_data_()
  , stories_preload_()
  , photo_size_max_()
  , video_size_max_()
  , file_size_max_()
  , video_upload_maxbitrate_()
  , small_queue_active_operations_max_()
  , large_queue_active_operations_max_()
{}

autoDownloadSettings::autoDownloadSettings(int32 flags_, bool disabled_, bool video_preload_large_, bool audio_preload_next_, bool phonecalls_less_data_, bool stories_preload_, int32 photo_size_max_, int64 video_size_max_, int64 file_size_max_, int32 video_upload_maxbitrate_, int32 small_queue_active_operations_max_, int32 large_queue_active_operations_max_)
  : flags_(flags_)
  , disabled_(disabled_)
  , video_preload_large_(video_preload_large_)
  , audio_preload_next_(audio_preload_next_)
  , phonecalls_less_data_(phonecalls_less_data_)
  , stories_preload_(stories_preload_)
  , photo_size_max_(photo_size_max_)
  , video_size_max_(video_size_max_)
  , file_size_max_(file_size_max_)
  , video_upload_maxbitrate_(video_upload_maxbitrate_)
  , small_queue_active_operations_max_(small_queue_active_operations_max_)
  , large_queue_active_operations_max_(large_queue_active_operations_max_)
{}

const std::int32_t autoDownloadSettings::ID;

object_ptr<autoDownloadSettings> autoDownloadSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<autoDownloadSettings> res = make_tl_object<autoDownloadSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->disabled_ = (var0 & 1) != 0;
  res->video_preload_large_ = (var0 & 2) != 0;
  res->audio_preload_next_ = (var0 & 4) != 0;
  res->phonecalls_less_data_ = (var0 & 8) != 0;
  res->stories_preload_ = (var0 & 16) != 0;
  res->photo_size_max_ = TlFetchInt::parse(p);
  res->video_size_max_ = TlFetchLong::parse(p);
  res->file_size_max_ = TlFetchLong::parse(p);
  res->video_upload_maxbitrate_ = TlFetchInt::parse(p);
  res->small_queue_active_operations_max_ = TlFetchInt::parse(p);
  res->large_queue_active_operations_max_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void autoDownloadSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (disabled_ << 0) | (video_preload_large_ << 1) | (audio_preload_next_ << 2) | (phonecalls_less_data_ << 3) | (stories_preload_ << 4)), s);
  TlStoreBinary::store(photo_size_max_, s);
  TlStoreBinary::store(video_size_max_, s);
  TlStoreBinary::store(file_size_max_, s);
  TlStoreBinary::store(video_upload_maxbitrate_, s);
  TlStoreBinary::store(small_queue_active_operations_max_, s);
  TlStoreBinary::store(large_queue_active_operations_max_, s);
}

void autoDownloadSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (disabled_ << 0) | (video_preload_large_ << 1) | (audio_preload_next_ << 2) | (phonecalls_less_data_ << 3) | (stories_preload_ << 4)), s);
  TlStoreBinary::store(photo_size_max_, s);
  TlStoreBinary::store(video_size_max_, s);
  TlStoreBinary::store(file_size_max_, s);
  TlStoreBinary::store(video_upload_maxbitrate_, s);
  TlStoreBinary::store(small_queue_active_operations_max_, s);
  TlStoreBinary::store(large_queue_active_operations_max_, s);
}

void autoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoDownloadSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (disabled_ << 0) | (video_preload_large_ << 1) | (audio_preload_next_ << 2) | (phonecalls_less_data_ << 3) | (stories_preload_ << 4)));
    if (var0 & 1) { s.store_field("disabled", true); }
    if (var0 & 2) { s.store_field("video_preload_large", true); }
    if (var0 & 4) { s.store_field("audio_preload_next", true); }
    if (var0 & 8) { s.store_field("phonecalls_less_data", true); }
    if (var0 & 16) { s.store_field("stories_preload", true); }
    s.store_field("photo_size_max", photo_size_max_);
    s.store_field("video_size_max", video_size_max_);
    s.store_field("file_size_max", file_size_max_);
    s.store_field("video_upload_maxbitrate", video_upload_maxbitrate_);
    s.store_field("small_queue_active_operations_max", small_queue_active_operations_max_);
    s.store_field("large_queue_active_operations_max", large_queue_active_operations_max_);
    s.store_class_end();
  }
}

const std::int32_t bankCardOpenUrl::ID;

object_ptr<bankCardOpenUrl> bankCardOpenUrl::fetch(TlBufferParser &p) {
  return make_tl_object<bankCardOpenUrl>(p);
}

bankCardOpenUrl::bankCardOpenUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , name_(TlFetchString<string>::parse(p))
{}

void bankCardOpenUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bankCardOpenUrl");
    s.store_field("url", url_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

object_ptr<BotApp> BotApp::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case botAppNotModified::ID:
      return botAppNotModified::fetch(p);
    case botApp::ID:
      return botApp::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t botAppNotModified::ID;

object_ptr<BotApp> botAppNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<botAppNotModified>();
}

void botAppNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botAppNotModified");
    s.store_class_end();
  }
}

botApp::botApp()
  : flags_()
  , id_()
  , access_hash_()
  , short_name_()
  , title_()
  , description_()
  , photo_()
  , document_()
  , hash_()
{}

const std::int32_t botApp::ID;

object_ptr<BotApp> botApp::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botApp> res = make_tl_object<botApp>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->short_name_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  res->photo_ = TlFetchObject<Photo>::parse(p);
  if (var0 & 1) { res->document_ = TlFetchObject<Document>::parse(p); }
  res->hash_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botApp");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((document_ != nullptr) << 0)));
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("short_name", short_name_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    if (var0 & 1) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

const std::int32_t botCommandScopeDefault::ID;

void botCommandScopeDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botCommandScopeDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botCommandScopeDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeDefault");
    s.store_class_end();
  }
}

const std::int32_t botCommandScopeUsers::ID;

void botCommandScopeUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botCommandScopeUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botCommandScopeUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeUsers");
    s.store_class_end();
  }
}

const std::int32_t botCommandScopeChats::ID;

void botCommandScopeChats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botCommandScopeChats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botCommandScopeChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChats");
    s.store_class_end();
  }
}

const std::int32_t botCommandScopeChatAdmins::ID;

void botCommandScopeChatAdmins::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botCommandScopeChatAdmins::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botCommandScopeChatAdmins::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChatAdmins");
    s.store_class_end();
  }
}

botCommandScopePeer::botCommandScopePeer(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t botCommandScopePeer::ID;

void botCommandScopePeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void botCommandScopePeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void botCommandScopePeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopePeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

botCommandScopePeerAdmins::botCommandScopePeerAdmins(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t botCommandScopePeerAdmins::ID;

void botCommandScopePeerAdmins::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void botCommandScopePeerAdmins::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void botCommandScopePeerAdmins::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopePeerAdmins");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

botCommandScopePeerUser::botCommandScopePeerUser(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&user_id_)
  : peer_(std::move(peer_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t botCommandScopePeerUser::ID;

void botCommandScopePeerUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void botCommandScopePeerUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void botCommandScopePeerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopePeerUser");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

const std::int32_t defaultHistoryTTL::ID;

object_ptr<defaultHistoryTTL> defaultHistoryTTL::fetch(TlBufferParser &p) {
  return make_tl_object<defaultHistoryTTL>(p);
}

defaultHistoryTTL::defaultHistoryTTL(TlBufferParser &p)
  : period_(TlFetchInt::parse(p))
{}

void defaultHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "defaultHistoryTTL");
    s.store_field("period", period_);
    s.store_class_end();
  }
}

object_ptr<EmojiKeyword> EmojiKeyword::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case emojiKeyword::ID:
      return emojiKeyword::fetch(p);
    case emojiKeywordDeleted::ID:
      return emojiKeywordDeleted::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t emojiKeyword::ID;

object_ptr<EmojiKeyword> emojiKeyword::fetch(TlBufferParser &p) {
  return make_tl_object<emojiKeyword>(p);
}

emojiKeyword::emojiKeyword(TlBufferParser &p)
  : keyword_(TlFetchString<string>::parse(p))
  , emoticons_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void emojiKeyword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiKeyword");
    s.store_field("keyword", keyword_);
    { s.store_vector_begin("emoticons", emoticons_.size()); for (const auto &_value : emoticons_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t emojiKeywordDeleted::ID;

object_ptr<EmojiKeyword> emojiKeywordDeleted::fetch(TlBufferParser &p) {
  return make_tl_object<emojiKeywordDeleted>(p);
}

emojiKeywordDeleted::emojiKeywordDeleted(TlBufferParser &p)
  : keyword_(TlFetchString<string>::parse(p))
  , emoticons_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void emojiKeywordDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiKeywordDeleted");
    s.store_field("keyword", keyword_);
    { s.store_vector_begin("emoticons", emoticons_.size()); for (const auto &_value : emoticons_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

game::game()
  : flags_()
  , id_()
  , access_hash_()
  , short_name_()
  , title_()
  , description_()
  , photo_()
  , document_()
{}

game::game(int32 flags_, int64 id_, int64 access_hash_, string const &short_name_, string const &title_, string const &description_, object_ptr<Photo> &&photo_, object_ptr<Document> &&document_)
  : flags_(flags_)
  , id_(id_)
  , access_hash_(access_hash_)
  , short_name_(short_name_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , document_(std::move(document_))
{}

const std::int32_t game::ID;

object_ptr<game> game::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<game> res = make_tl_object<game>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->short_name_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  res->photo_ = TlFetchObject<Photo>::parse(p);
  if (var0 & 1) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void game::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((document_ != nullptr) << 0)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(short_name_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
}

void game::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((document_ != nullptr) << 0)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(short_name_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
}

void game::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "game");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((document_ != nullptr) << 0)));
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("short_name", short_name_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    if (var0 & 1) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    s.store_class_end();
  }
}

groupCallDonor::groupCallDonor()
  : flags_()
  , top_()
  , my_()
  , peer_id_()
  , stars_()
{}

const std::int32_t groupCallDonor::ID;

object_ptr<groupCallDonor> groupCallDonor::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<groupCallDonor> res = make_tl_object<groupCallDonor>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->top_ = (var0 & 1) != 0;
  res->my_ = (var0 & 2) != 0;
  if (var0 & 8) { res->peer_id_ = TlFetchObject<Peer>::parse(p); }
  res->stars_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void groupCallDonor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallDonor");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (top_ << 0) | (my_ << 1) | ((peer_id_ != nullptr) << 3)));
    if (var0 & 1) { s.store_field("top", true); }
    if (var0 & 2) { s.store_field("my", true); }
    if (var0 & 8) { s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get())); }
    s.store_field("stars", stars_);
    s.store_class_end();
  }
}

inputBusinessGreetingMessage::inputBusinessGreetingMessage(int32 shortcut_id_, object_ptr<inputBusinessRecipients> &&recipients_, int32 no_activity_days_)
  : shortcut_id_(shortcut_id_)
  , recipients_(std::move(recipients_))
  , no_activity_days_(no_activity_days_)
{}

const std::int32_t inputBusinessGreetingMessage::ID;

void inputBusinessGreetingMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreObject, 1871393450>::store(recipients_, s);
  TlStoreBinary::store(no_activity_days_, s);
}

void inputBusinessGreetingMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreObject, 1871393450>::store(recipients_, s);
  TlStoreBinary::store(no_activity_days_, s);
}

void inputBusinessGreetingMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessGreetingMessage");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_field("no_activity_days", no_activity_days_);
    s.store_class_end();
  }
}

const std::int32_t inputCheckPasswordEmpty::ID;

void inputCheckPasswordEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputCheckPasswordEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputCheckPasswordEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCheckPasswordEmpty");
    s.store_class_end();
  }
}

inputCheckPasswordSRP::inputCheckPasswordSRP(int64 srp_id_, bytes &&A_, bytes &&M1_)
  : srp_id_(srp_id_)
  , A_(std::move(A_))
  , M1_(std::move(M1_))
{}

const std::int32_t inputCheckPasswordSRP::ID;

void inputCheckPasswordSRP::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(srp_id_, s);
  TlStoreString::store(A_, s);
  TlStoreString::store(M1_, s);
}

void inputCheckPasswordSRP::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(srp_id_, s);
  TlStoreString::store(A_, s);
  TlStoreString::store(M1_, s);
}

void inputCheckPasswordSRP::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCheckPasswordSRP");
    s.store_field("srp_id", srp_id_);
    s.store_bytes_field("A", A_);
    s.store_bytes_field("M1", M1_);
    s.store_class_end();
  }
}

const std::int32_t inputClientProxy::ID;

void inputClientProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputClientProxy");
    s.store_field("address", address_);
    s.store_field("port", port_);
    s.store_class_end();
  }
}

inputDialogPeer::inputDialogPeer(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t inputDialogPeer::ID;

void inputDialogPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void inputDialogPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void inputDialogPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDialogPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

inputDialogPeerFolder::inputDialogPeerFolder(int32 folder_id_)
  : folder_id_(folder_id_)
{}

const std::int32_t inputDialogPeerFolder::ID;

void inputDialogPeerFolder::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(folder_id_, s);
}

void inputDialogPeerFolder::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(folder_id_, s);
}

void inputDialogPeerFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDialogPeerFolder");
    s.store_field("folder_id", folder_id_);
    s.store_class_end();
  }
}

inputDialogPeerCommunity::inputDialogPeerCommunity(object_ptr<InputChannel> &&community_)
  : community_(std::move(community_))
{}

const std::int32_t inputDialogPeerCommunity::ID;

void inputDialogPeerCommunity::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
}

void inputDialogPeerCommunity::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
}

void inputDialogPeerCommunity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDialogPeerCommunity");
    s.store_object_field("community", static_cast<const BaseObject *>(community_.get()));
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyStatusTimestamp::ID;

void inputPrivacyKeyStatusTimestamp::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyStatusTimestamp::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyStatusTimestamp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyStatusTimestamp");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyChatInvite::ID;

void inputPrivacyKeyChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyChatInvite");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyPhoneCall::ID;

void inputPrivacyKeyPhoneCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyPhoneCall");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyPhoneP2P::ID;

void inputPrivacyKeyPhoneP2P::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneP2P::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneP2P::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyPhoneP2P");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyForwards::ID;

void inputPrivacyKeyForwards::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyForwards::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyForwards");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyProfilePhoto::ID;

void inputPrivacyKeyProfilePhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyProfilePhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyProfilePhoto");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyPhoneNumber::ID;

void inputPrivacyKeyPhoneNumber::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneNumber::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyPhoneNumber");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyAddedByPhone::ID;

void inputPrivacyKeyAddedByPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyAddedByPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyAddedByPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyAddedByPhone");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyVoiceMessages::ID;

void inputPrivacyKeyVoiceMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyVoiceMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyVoiceMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyVoiceMessages");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyAbout::ID;

void inputPrivacyKeyAbout::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyAbout::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyAbout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyAbout");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyBirthday::ID;

void inputPrivacyKeyBirthday::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyBirthday::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyBirthday");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyStarGiftsAutoSave::ID;

void inputPrivacyKeyStarGiftsAutoSave::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyStarGiftsAutoSave::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyStarGiftsAutoSave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyStarGiftsAutoSave");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyNoPaidMessages::ID;

void inputPrivacyKeyNoPaidMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyNoPaidMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyNoPaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyNoPaidMessages");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeySavedMusic::ID;

void inputPrivacyKeySavedMusic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeySavedMusic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeySavedMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeySavedMusic");
    s.store_class_end();
  }
}

object_ptr<InputUser> InputUser::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputUserEmpty::ID:
      return inputUserEmpty::fetch(p);
    case inputUserSelf::ID:
      return inputUserSelf::fetch(p);
    case inputUser::ID:
      return inputUser::fetch(p);
    case inputUserFromMessage::ID:
      return inputUserFromMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputUserEmpty::ID;

object_ptr<InputUser> inputUserEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputUserEmpty>();
}

void inputUserEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputUserEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputUserEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputUserEmpty");
    s.store_class_end();
  }
}

const std::int32_t inputUserSelf::ID;

object_ptr<InputUser> inputUserSelf::fetch(TlBufferParser &p) {
  return make_tl_object<inputUserSelf>();
}

void inputUserSelf::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputUserSelf::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputUserSelf::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputUserSelf");
    s.store_class_end();
  }
}

inputUser::inputUser(int64 user_id_, int64 access_hash_)
  : user_id_(user_id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputUser::ID;

object_ptr<InputUser> inputUser::fetch(TlBufferParser &p) {
  return make_tl_object<inputUser>(p);
}

inputUser::inputUser(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputUser");
    s.store_field("user_id", user_id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputUserFromMessage::inputUserFromMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 user_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , user_id_(user_id_)
{}

const std::int32_t inputUserFromMessage::ID;

object_ptr<InputUser> inputUserFromMessage::fetch(TlBufferParser &p) {
  return make_tl_object<inputUserFromMessage>(p);
}

inputUserFromMessage::inputUserFromMessage(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , user_id_(TlFetchLong::parse(p))
{}

void inputUserFromMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(user_id_, s);
}

void inputUserFromMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(user_id_, s);
}

void inputUserFromMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputUserFromMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

inputWalletCardSticker::inputWalletCardSticker(object_ptr<mediaAreaCoordinates> &&coordinates_, string const &nft_address_)
  : coordinates_(std::move(coordinates_))
  , nft_address_(nft_address_)
{}

const std::int32_t inputWalletCardSticker::ID;

void inputWalletCardSticker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(nft_address_, s);
}

void inputWalletCardSticker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(nft_address_, s);
}

void inputWalletCardSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWalletCardSticker");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_field("nft_address", nft_address_);
    s.store_class_end();
  }
}

invoice::invoice()
  : flags_()
  , test_()
  , name_requested_()
  , phone_requested_()
  , email_requested_()
  , shipping_address_requested_()
  , flexible_()
  , phone_to_provider_()
  , email_to_provider_()
  , recurring_()
  , currency_()
  , prices_()
  , max_tip_amount_()
  , suggested_tip_amounts_()
  , terms_url_()
  , subscription_period_()
{}

invoice::invoice(int32 flags_, bool test_, bool name_requested_, bool phone_requested_, bool email_requested_, bool shipping_address_requested_, bool flexible_, bool phone_to_provider_, bool email_to_provider_, bool recurring_, string const &currency_, array<object_ptr<labeledPrice>> &&prices_, int64 max_tip_amount_, array<int64> &&suggested_tip_amounts_, string const &terms_url_, int32 subscription_period_)
  : flags_(flags_)
  , test_(test_)
  , name_requested_(name_requested_)
  , phone_requested_(phone_requested_)
  , email_requested_(email_requested_)
  , shipping_address_requested_(shipping_address_requested_)
  , flexible_(flexible_)
  , phone_to_provider_(phone_to_provider_)
  , email_to_provider_(email_to_provider_)
  , recurring_(recurring_)
  , currency_(currency_)
  , prices_(std::move(prices_))
  , max_tip_amount_(max_tip_amount_)
  , suggested_tip_amounts_(std::move(suggested_tip_amounts_))
  , terms_url_(terms_url_)
  , subscription_period_(subscription_period_)
{}

const std::int32_t invoice::ID;

object_ptr<invoice> invoice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<invoice> res = make_tl_object<invoice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->test_ = (var0 & 1) != 0;
  res->name_requested_ = (var0 & 2) != 0;
  res->phone_requested_ = (var0 & 4) != 0;
  res->email_requested_ = (var0 & 8) != 0;
  res->shipping_address_requested_ = (var0 & 16) != 0;
  res->flexible_ = (var0 & 32) != 0;
  res->phone_to_provider_ = (var0 & 64) != 0;
  res->email_to_provider_ = (var0 & 128) != 0;
  res->recurring_ = (var0 & 512) != 0;
  res->currency_ = TlFetchString<string>::parse(p);
  res->prices_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<labeledPrice>, -886477832>>, 481674261>::parse(p);
  if (var0 & 256) { res->max_tip_amount_ = TlFetchLong::parse(p); }
  if (var0 & 256) { res->suggested_tip_amounts_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (var0 & 1024) { res->terms_url_ = TlFetchString<string>::parse(p); }
  if (var0 & 2048) { res->subscription_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void invoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (test_ << 0) | (name_requested_ << 1) | (phone_requested_ << 2) | (email_requested_ << 3) | (shipping_address_requested_ << 4) | (flexible_ << 5) | (phone_to_provider_ << 6) | (email_to_provider_ << 7) | (recurring_ << 9) | ((!suggested_tip_amounts_.empty()) << 8) | ((!terms_url_.empty()) << 10)), s);
  TlStoreString::store(currency_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -886477832>>, 481674261>::store(prices_, s);
  if (var0 & 256) { TlStoreBinary::store(max_tip_amount_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(suggested_tip_amounts_, s); }
  if (var0 & 1024) { TlStoreString::store(terms_url_, s); }
  if (var0 & 2048) { TlStoreBinary::store(subscription_period_, s); }
}

void invoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (test_ << 0) | (name_requested_ << 1) | (phone_requested_ << 2) | (email_requested_ << 3) | (shipping_address_requested_ << 4) | (flexible_ << 5) | (phone_to_provider_ << 6) | (email_to_provider_ << 7) | (recurring_ << 9) | ((!suggested_tip_amounts_.empty()) << 8) | ((!terms_url_.empty()) << 10)), s);
  TlStoreString::store(currency_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -886477832>>, 481674261>::store(prices_, s);
  if (var0 & 256) { TlStoreBinary::store(max_tip_amount_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(suggested_tip_amounts_, s); }
  if (var0 & 1024) { TlStoreString::store(terms_url_, s); }
  if (var0 & 2048) { TlStoreBinary::store(subscription_period_, s); }
}

void invoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invoice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (test_ << 0) | (name_requested_ << 1) | (phone_requested_ << 2) | (email_requested_ << 3) | (shipping_address_requested_ << 4) | (flexible_ << 5) | (phone_to_provider_ << 6) | (email_to_provider_ << 7) | (recurring_ << 9) | ((!suggested_tip_amounts_.empty()) << 8) | ((!terms_url_.empty()) << 10)));
    if (var0 & 1) { s.store_field("test", true); }
    if (var0 & 2) { s.store_field("name_requested", true); }
    if (var0 & 4) { s.store_field("phone_requested", true); }
    if (var0 & 8) { s.store_field("email_requested", true); }
    if (var0 & 16) { s.store_field("shipping_address_requested", true); }
    if (var0 & 32) { s.store_field("flexible", true); }
    if (var0 & 64) { s.store_field("phone_to_provider", true); }
    if (var0 & 128) { s.store_field("email_to_provider", true); }
    if (var0 & 512) { s.store_field("recurring", true); }
    s.store_field("currency", currency_);
    { s.store_vector_begin("prices", prices_.size()); for (const auto &_value : prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 256) { s.store_field("max_tip_amount", max_tip_amount_); }
    if (var0 & 256) { { s.store_vector_begin("suggested_tip_amounts", suggested_tip_amounts_.size()); for (const auto &_value : suggested_tip_amounts_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 1024) { s.store_field("terms_url", terms_url_); }
    if (var0 & 2048) { s.store_field("subscription_period", subscription_period_); }
    s.store_class_end();
  }
}

messageReactions::messageReactions()
  : flags_()
  , min_()
  , can_see_list_()
  , reactions_as_tags_()
  , results_()
  , recent_reactions_()
  , top_reactors_()
{}

const std::int32_t messageReactions::ID;

object_ptr<messageReactions> messageReactions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageReactions> res = make_tl_object<messageReactions>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->min_ = (var0 & 1) != 0;
  res->can_see_list_ = (var0 & 4) != 0;
  res->reactions_as_tags_ = (var0 & 8) != 0;
  res->results_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<reactionCount>, -1546531968>>, 481674261>::parse(p);
  if (var0 & 2) { res->recent_reactions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messagePeerReaction>, -1938180548>>, 481674261>::parse(p); }
  if (var0 & 16) { res->top_reactors_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messageReactor>, 1269016922>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReactions");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (min_ << 0) | (can_see_list_ << 2) | (reactions_as_tags_ << 3) | ((!recent_reactions_.empty()) << 1) | ((!top_reactors_.empty()) << 4)));
    if (var0 & 1) { s.store_field("min", true); }
    if (var0 & 4) { s.store_field("can_see_list", true); }
    if (var0 & 8) { s.store_field("reactions_as_tags", true); }
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 2) { { s.store_vector_begin("recent_reactions", recent_reactions_.size()); for (const auto &_value : recent_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { { s.store_vector_begin("top_reactors", top_reactors_.size()); for (const auto &_value : top_reactors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t onrampQuote::ID;

object_ptr<onrampQuote> onrampQuote::fetch(TlBufferParser &p) {
  return make_tl_object<onrampQuote>(p);
}

onrampQuote::onrampQuote(TlBufferParser &p)
  : base_currency_(TlFetchString<string>::parse(p))
  , base_amount_(TlFetchString<string>::parse(p))
  , crypto_currency_(TlFetchString<string>::parse(p))
  , crypto_amount_(TlFetchString<string>::parse(p))
  , crypto_price_(TlFetchString<string>::parse(p))
  , fee_amount_(TlFetchString<string>::parse(p))
  , extra_fee_amount_(TlFetchString<string>::parse(p))
  , network_fee_amount_(TlFetchString<string>::parse(p))
  , total_amount_(TlFetchString<string>::parse(p))
  , payment_method_(TlFetchString<string>::parse(p))
  , expires_date_(TlFetchInt::parse(p))
{}

void onrampQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onrampQuote");
    s.store_field("base_currency", base_currency_);
    s.store_field("base_amount", base_amount_);
    s.store_field("crypto_currency", crypto_currency_);
    s.store_field("crypto_amount", crypto_amount_);
    s.store_field("crypto_price", crypto_price_);
    s.store_field("fee_amount", fee_amount_);
    s.store_field("extra_fee_amount", extra_fee_amount_);
    s.store_field("network_fee_amount", network_fee_amount_);
    s.store_field("total_amount", total_amount_);
    s.store_field("payment_method", payment_method_);
    s.store_field("expires_date", expires_date_);
    s.store_class_end();
  }
}

const std::int32_t onrampSession::ID;

object_ptr<onrampSession> onrampSession::fetch(TlBufferParser &p) {
  return make_tl_object<onrampSession>(p);
}

onrampSession::onrampSession(TlBufferParser &p)
  : provider_(TlFetchString<string>::parse(p))
  , session_id_(TlFetchString<string>::parse(p))
  , url_(TlFetchString<string>::parse(p))
  , expires_date_(TlFetchInt::parse(p))
{}

void onrampSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onrampSession");
    s.store_field("provider", provider_);
    s.store_field("session_id", session_id_);
    s.store_field("url", url_);
    s.store_field("expires_date", expires_date_);
    s.store_class_end();
  }
}

object_ptr<PageListOrderedItem> PageListOrderedItem::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case pageListOrderedItemText::ID:
      return pageListOrderedItemText::fetch(p);
    case pageListOrderedItemBlocks::ID:
      return pageListOrderedItemBlocks::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

pageListOrderedItemText::pageListOrderedItemText()
  : flags_()
  , checkbox_()
  , checked_()
  , num_()
  , text_()
  , value_()
  , type_()
{}

pageListOrderedItemText::pageListOrderedItemText(int32 flags_, bool checkbox_, bool checked_, string const &num_, object_ptr<RichText> &&text_, int32 value_, string const &type_)
  : flags_(flags_)
  , checkbox_(checkbox_)
  , checked_(checked_)
  , num_(num_)
  , text_(std::move(text_))
  , value_(value_)
  , type_(type_)
{}

const std::int32_t pageListOrderedItemText::ID;

object_ptr<PageListOrderedItem> pageListOrderedItemText::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageListOrderedItemText> res = make_tl_object<pageListOrderedItemText>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->checkbox_ = (var0 & 1) != 0;
  res->checked_ = (var0 & 2) != 0;
  if (var0 & 4) { res->num_ = TlFetchString<string>::parse(p); }
  res->text_ = TlFetchObject<RichText>::parse(p);
  if (var0 & 8) { res->value_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->type_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageListOrderedItemText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (checkbox_ << 0) | (checked_ << 1) | ((!num_.empty()) << 2) | ((!type_.empty()) << 4)), s);
  if (var0 & 4) { TlStoreString::store(num_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  if (var0 & 8) { TlStoreBinary::store(value_, s); }
  if (var0 & 16) { TlStoreString::store(type_, s); }
}

void pageListOrderedItemText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (checkbox_ << 0) | (checked_ << 1) | ((!num_.empty()) << 2) | ((!type_.empty()) << 4)), s);
  if (var0 & 4) { TlStoreString::store(num_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  if (var0 & 8) { TlStoreBinary::store(value_, s); }
  if (var0 & 16) { TlStoreString::store(type_, s); }
}

void pageListOrderedItemText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageListOrderedItemText");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (checkbox_ << 0) | (checked_ << 1) | ((!num_.empty()) << 2) | ((!type_.empty()) << 4)));
    if (var0 & 1) { s.store_field("checkbox", true); }
    if (var0 & 2) { s.store_field("checked", true); }
    if (var0 & 4) { s.store_field("num", num_); }
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    if (var0 & 8) { s.store_field("value", value_); }
    if (var0 & 16) { s.store_field("type", type_); }
    s.store_class_end();
  }
}

pageListOrderedItemBlocks::pageListOrderedItemBlocks()
  : flags_()
  , checkbox_()
  , checked_()
  , num_()
  , blocks_()
  , value_()
  , type_()
{}

pageListOrderedItemBlocks::pageListOrderedItemBlocks(int32 flags_, bool checkbox_, bool checked_, string const &num_, array<object_ptr<PageBlock>> &&blocks_, int32 value_, string const &type_)
  : flags_(flags_)
  , checkbox_(checkbox_)
  , checked_(checked_)
  , num_(num_)
  , blocks_(std::move(blocks_))
  , value_(value_)
  , type_(type_)
{}

const std::int32_t pageListOrderedItemBlocks::ID;

object_ptr<PageListOrderedItem> pageListOrderedItemBlocks::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageListOrderedItemBlocks> res = make_tl_object<pageListOrderedItemBlocks>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->checkbox_ = (var0 & 1) != 0;
  res->checked_ = (var0 & 2) != 0;
  if (var0 & 4) { res->num_ = TlFetchString<string>::parse(p); }
  res->blocks_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p);
  if (var0 & 8) { res->value_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->type_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageListOrderedItemBlocks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (checkbox_ << 0) | (checked_ << 1) | ((!num_.empty()) << 2) | ((!type_.empty()) << 4)), s);
  if (var0 & 4) { TlStoreString::store(num_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  if (var0 & 8) { TlStoreBinary::store(value_, s); }
  if (var0 & 16) { TlStoreString::store(type_, s); }
}

void pageListOrderedItemBlocks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (checkbox_ << 0) | (checked_ << 1) | ((!num_.empty()) << 2) | ((!type_.empty()) << 4)), s);
  if (var0 & 4) { TlStoreString::store(num_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  if (var0 & 8) { TlStoreBinary::store(value_, s); }
  if (var0 & 16) { TlStoreString::store(type_, s); }
}

void pageListOrderedItemBlocks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageListOrderedItemBlocks");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (checkbox_ << 0) | (checked_ << 1) | ((!num_.empty()) << 2) | ((!type_.empty()) << 4)));
    if (var0 & 1) { s.store_field("checkbox", true); }
    if (var0 & 2) { s.store_field("checked", true); }
    if (var0 & 4) { s.store_field("num", num_); }
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 8) { s.store_field("value", value_); }
    if (var0 & 16) { s.store_field("type", type_); }
    s.store_class_end();
  }
}

pageTableCell::pageTableCell()
  : flags_()
  , header_()
  , align_center_()
  , align_right_()
  , valign_middle_()
  , valign_bottom_()
  , text_()
  , colspan_()
  , rowspan_()
{}

pageTableCell::pageTableCell(int32 flags_, bool header_, bool align_center_, bool align_right_, bool valign_middle_, bool valign_bottom_, object_ptr<RichText> &&text_, int32 colspan_, int32 rowspan_)
  : flags_(flags_)
  , header_(header_)
  , align_center_(align_center_)
  , align_right_(align_right_)
  , valign_middle_(valign_middle_)
  , valign_bottom_(valign_bottom_)
  , text_(std::move(text_))
  , colspan_(colspan_)
  , rowspan_(rowspan_)
{}

const std::int32_t pageTableCell::ID;

object_ptr<pageTableCell> pageTableCell::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageTableCell> res = make_tl_object<pageTableCell>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->header_ = (var0 & 1) != 0;
  res->align_center_ = (var0 & 8) != 0;
  res->align_right_ = (var0 & 16) != 0;
  res->valign_middle_ = (var0 & 32) != 0;
  res->valign_bottom_ = (var0 & 64) != 0;
  if (var0 & 128) { res->text_ = TlFetchObject<RichText>::parse(p); }
  if (var0 & 2) { res->colspan_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->rowspan_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void pageTableCell::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (header_ << 0) | (align_center_ << 3) | (align_right_ << 4) | (valign_middle_ << 5) | (valign_bottom_ << 6) | ((text_ != nullptr) << 7)), s);
  if (var0 & 128) { TlStoreBoxedUnknown<TlStoreObject>::store(text_, s); }
  if (var0 & 2) { TlStoreBinary::store(colspan_, s); }
  if (var0 & 4) { TlStoreBinary::store(rowspan_, s); }
}

void pageTableCell::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (header_ << 0) | (align_center_ << 3) | (align_right_ << 4) | (valign_middle_ << 5) | (valign_bottom_ << 6) | ((text_ != nullptr) << 7)), s);
  if (var0 & 128) { TlStoreBoxedUnknown<TlStoreObject>::store(text_, s); }
  if (var0 & 2) { TlStoreBinary::store(colspan_, s); }
  if (var0 & 4) { TlStoreBinary::store(rowspan_, s); }
}

void pageTableCell::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageTableCell");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (header_ << 0) | (align_center_ << 3) | (align_right_ << 4) | (valign_middle_ << 5) | (valign_bottom_ << 6) | ((text_ != nullptr) << 7)));
    if (var0 & 1) { s.store_field("header", true); }
    if (var0 & 8) { s.store_field("align_center", true); }
    if (var0 & 16) { s.store_field("align_right", true); }
    if (var0 & 32) { s.store_field("valign_middle", true); }
    if (var0 & 64) { s.store_field("valign_bottom", true); }
    if (var0 & 128) { s.store_object_field("text", static_cast<const BaseObject *>(text_.get())); }
    if (var0 & 2) { s.store_field("colspan", colspan_); }
    if (var0 & 4) { s.store_field("rowspan", rowspan_); }
    s.store_class_end();
  }
}

object_ptr<PhoneCallDiscardReason> PhoneCallDiscardReason::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t phoneCallDiscardReasonMissed::ID;

object_ptr<PhoneCallDiscardReason> phoneCallDiscardReasonMissed::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallDiscardReasonMissed>();
}

void phoneCallDiscardReasonMissed::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonMissed::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonMissed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscardReasonMissed");
    s.store_class_end();
  }
}

const std::int32_t phoneCallDiscardReasonDisconnect::ID;

object_ptr<PhoneCallDiscardReason> phoneCallDiscardReasonDisconnect::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallDiscardReasonDisconnect>();
}

void phoneCallDiscardReasonDisconnect::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonDisconnect::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonDisconnect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscardReasonDisconnect");
    s.store_class_end();
  }
}

const std::int32_t phoneCallDiscardReasonHangup::ID;

object_ptr<PhoneCallDiscardReason> phoneCallDiscardReasonHangup::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallDiscardReasonHangup>();
}

void phoneCallDiscardReasonHangup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonHangup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonHangup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscardReasonHangup");
    s.store_class_end();
  }
}

const std::int32_t phoneCallDiscardReasonBusy::ID;

object_ptr<PhoneCallDiscardReason> phoneCallDiscardReasonBusy::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallDiscardReasonBusy>();
}

void phoneCallDiscardReasonBusy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonBusy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonBusy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscardReasonBusy");
    s.store_class_end();
  }
}

phoneCallDiscardReasonMigrateConferenceCall::phoneCallDiscardReasonMigrateConferenceCall(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t phoneCallDiscardReasonMigrateConferenceCall::ID;

object_ptr<PhoneCallDiscardReason> phoneCallDiscardReasonMigrateConferenceCall::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallDiscardReasonMigrateConferenceCall>(p);
}

phoneCallDiscardReasonMigrateConferenceCall::phoneCallDiscardReasonMigrateConferenceCall(TlBufferParser &p)
  : slug_(TlFetchString<string>::parse(p))
{}

void phoneCallDiscardReasonMigrateConferenceCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void phoneCallDiscardReasonMigrateConferenceCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void phoneCallDiscardReasonMigrateConferenceCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscardReasonMigrateConferenceCall");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

pollResults::pollResults()
  : flags_()
  , min_()
  , has_unread_votes_()
  , can_view_stats_()
  , results_()
  , total_voters_()
  , recent_voters_()
  , solution_()
  , solution_entities_()
  , solution_media_()
{}

pollResults::pollResults(int32 flags_, bool min_, bool has_unread_votes_, bool can_view_stats_, array<object_ptr<pollAnswerVoters>> &&results_, int32 total_voters_, array<object_ptr<Peer>> &&recent_voters_, string const &solution_, array<object_ptr<MessageEntity>> &&solution_entities_, object_ptr<MessageMedia> &&solution_media_)
  : flags_(flags_)
  , min_(min_)
  , has_unread_votes_(has_unread_votes_)
  , can_view_stats_(can_view_stats_)
  , results_(std::move(results_))
  , total_voters_(total_voters_)
  , recent_voters_(std::move(recent_voters_))
  , solution_(solution_)
  , solution_entities_(std::move(solution_entities_))
  , solution_media_(std::move(solution_media_))
{}

const std::int32_t pollResults::ID;

object_ptr<pollResults> pollResults::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pollResults> res = make_tl_object<pollResults>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->min_ = (var0 & 1) != 0;
  res->has_unread_votes_ = (var0 & 64) != 0;
  res->can_view_stats_ = (var0 & 128) != 0;
  if (var0 & 2) { res->results_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<pollAnswerVoters>, 910500618>>, 481674261>::parse(p); }
  if (var0 & 4) { res->total_voters_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->recent_voters_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p); }
  if (var0 & 16) { res->solution_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->solution_entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 32) { res->solution_media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void pollResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (min_ << 0) | (has_unread_votes_ << 6) | (can_view_stats_ << 7) | ((!results_.empty()) << 1) | ((!recent_voters_.empty()) << 3) | ((!solution_.empty()) << 4) | ((!solution_entities_.empty()) << 4) | ((solution_media_ != nullptr) << 5)), s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 910500618>>, 481674261>::store(results_, s); }
  if (var0 & 4) { TlStoreBinary::store(total_voters_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(recent_voters_, s); }
  if (var0 & 16) { TlStoreString::store(solution_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(solution_entities_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(solution_media_, s); }
}

void pollResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (min_ << 0) | (has_unread_votes_ << 6) | (can_view_stats_ << 7) | ((!results_.empty()) << 1) | ((!recent_voters_.empty()) << 3) | ((!solution_.empty()) << 4) | ((!solution_entities_.empty()) << 4) | ((solution_media_ != nullptr) << 5)), s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 910500618>>, 481674261>::store(results_, s); }
  if (var0 & 4) { TlStoreBinary::store(total_voters_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(recent_voters_, s); }
  if (var0 & 16) { TlStoreString::store(solution_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(solution_entities_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(solution_media_, s); }
}

void pollResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollResults");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (min_ << 0) | (has_unread_votes_ << 6) | (can_view_stats_ << 7) | ((!results_.empty()) << 1) | ((!recent_voters_.empty()) << 3) | ((!solution_.empty()) << 4) | ((!solution_entities_.empty()) << 4) | ((solution_media_ != nullptr) << 5)));
    if (var0 & 1) { s.store_field("min", true); }
    if (var0 & 64) { s.store_field("has_unread_votes", true); }
    if (var0 & 128) { s.store_field("can_view_stats", true); }
    if (var0 & 2) { { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_field("total_voters", total_voters_); }
    if (var0 & 8) { { s.store_vector_begin("recent_voters", recent_voters_.size()); for (const auto &_value : recent_voters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("solution", solution_); }
    if (var0 & 16) { { s.store_vector_begin("solution_entities", solution_entities_.size()); for (const auto &_value : solution_entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32) { s.store_object_field("solution_media", static_cast<const BaseObject *>(solution_media_.get())); }
    s.store_class_end();
  }
}

postAddress::postAddress(string const &street_line1_, string const &street_line2_, string const &city_, string const &state_, string const &country_iso2_, string const &post_code_)
  : street_line1_(street_line1_)
  , street_line2_(street_line2_)
  , city_(city_)
  , state_(state_)
  , country_iso2_(country_iso2_)
  , post_code_(post_code_)
{}

const std::int32_t postAddress::ID;

object_ptr<postAddress> postAddress::fetch(TlBufferParser &p) {
  return make_tl_object<postAddress>(p);
}

postAddress::postAddress(TlBufferParser &p)
  : street_line1_(TlFetchString<string>::parse(p))
  , street_line2_(TlFetchString<string>::parse(p))
  , city_(TlFetchString<string>::parse(p))
  , state_(TlFetchString<string>::parse(p))
  , country_iso2_(TlFetchString<string>::parse(p))
  , post_code_(TlFetchString<string>::parse(p))
{}

void postAddress::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(street_line1_, s);
  TlStoreString::store(street_line2_, s);
  TlStoreString::store(city_, s);
  TlStoreString::store(state_, s);
  TlStoreString::store(country_iso2_, s);
  TlStoreString::store(post_code_, s);
}

void postAddress::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(street_line1_, s);
  TlStoreString::store(street_line2_, s);
  TlStoreString::store(city_, s);
  TlStoreString::store(state_, s);
  TlStoreString::store(country_iso2_, s);
  TlStoreString::store(post_code_, s);
}

void postAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "postAddress");
    s.store_field("street_line1", street_line1_);
    s.store_field("street_line2", street_line2_);
    s.store_field("city", city_);
    s.store_field("state", state_);
    s.store_field("country_iso2", country_iso2_);
    s.store_field("post_code", post_code_);
    s.store_class_end();
  }
}

reactionCount::reactionCount()
  : flags_()
  , chosen_order_()
  , reaction_()
  , count_()
{}

reactionCount::reactionCount(int32 flags_, int32 chosen_order_, object_ptr<Reaction> &&reaction_, int32 count_)
  : flags_(flags_)
  , chosen_order_(chosen_order_)
  , reaction_(std::move(reaction_))
  , count_(count_)
{}

const std::int32_t reactionCount::ID;

object_ptr<reactionCount> reactionCount::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<reactionCount> res = make_tl_object<reactionCount>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->chosen_order_ = TlFetchInt::parse(p); }
  res->reaction_ = TlFetchObject<Reaction>::parse(p);
  res->count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void reactionCount::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(chosen_order_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
  TlStoreBinary::store(count_, s);
}

void reactionCount::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(chosen_order_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
  TlStoreBinary::store(count_, s);
}

void reactionCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionCount");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("chosen_order", chosen_order_); }
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_field("count", count_);
    s.store_class_end();
  }
}

secureCredentialsEncrypted::secureCredentialsEncrypted(bytes &&data_, bytes &&hash_, bytes &&secret_)
  : data_(std::move(data_))
  , hash_(std::move(hash_))
  , secret_(std::move(secret_))
{}

const std::int32_t secureCredentialsEncrypted::ID;

object_ptr<secureCredentialsEncrypted> secureCredentialsEncrypted::fetch(TlBufferParser &p) {
  return make_tl_object<secureCredentialsEncrypted>(p);
}

secureCredentialsEncrypted::secureCredentialsEncrypted(TlBufferParser &p)
  : data_(TlFetchBytes<bytes>::parse(p))
  , hash_(TlFetchBytes<bytes>::parse(p))
  , secret_(TlFetchBytes<bytes>::parse(p))
{}

void secureCredentialsEncrypted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
  TlStoreString::store(hash_, s);
  TlStoreString::store(secret_, s);
}

void secureCredentialsEncrypted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
  TlStoreString::store(hash_, s);
  TlStoreString::store(secret_, s);
}

void secureCredentialsEncrypted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureCredentialsEncrypted");
    s.store_bytes_field("data", data_);
    s.store_bytes_field("hash", hash_);
    s.store_field("secret", "[REDACTED]");
    s.store_class_end();
  }
}

sponsoredMessage::sponsoredMessage()
  : flags_()
  , recommended_()
  , can_report_()
  , random_id_()
  , url_()
  , title_()
  , message_()
  , entities_()
  , photo_()
  , media_()
  , color_()
  , button_text_()
  , sponsor_info_()
  , additional_info_()
  , min_display_duration_()
  , max_display_duration_()
{}

const std::int32_t sponsoredMessage::ID;

object_ptr<sponsoredMessage> sponsoredMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<sponsoredMessage> res = make_tl_object<sponsoredMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->recommended_ = (var0 & 32) != 0;
  res->can_report_ = (var0 & 4096) != 0;
  res->random_id_ = TlFetchBytes<bytes>::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 64) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 16384) { res->media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (var0 & 8192) { res->color_ = TlFetchObject<PeerColor>::parse(p); }
  res->button_text_ = TlFetchString<string>::parse(p);
  if (var0 & 128) { res->sponsor_info_ = TlFetchString<string>::parse(p); }
  if (var0 & 256) { res->additional_info_ = TlFetchString<string>::parse(p); }
  if (var0 & 32768) { res->min_display_duration_ = TlFetchInt::parse(p); }
  if (var0 & 32768) { res->max_display_duration_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void sponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (recommended_ << 5) | (can_report_ << 12) | ((!entities_.empty()) << 1) | ((photo_ != nullptr) << 6) | ((media_ != nullptr) << 14) | ((color_ != nullptr) << 13) | ((!sponsor_info_.empty()) << 7) | ((!additional_info_.empty()) << 8)));
    if (var0 & 32) { s.store_field("recommended", true); }
    if (var0 & 4096) { s.store_field("can_report", true); }
    s.store_bytes_field("random_id", random_id_);
    s.store_field("url", url_);
    s.store_field("title", title_);
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 64) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 16384) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 8192) { s.store_object_field("color", static_cast<const BaseObject *>(color_.get())); }
    s.store_field("button_text", button_text_);
    if (var0 & 128) { s.store_field("sponsor_info", sponsor_info_); }
    if (var0 & 256) { s.store_field("additional_info", additional_info_); }
    if (var0 & 32768) { s.store_field("min_display_duration", min_display_duration_); }
    if (var0 & 32768) { s.store_field("max_display_duration", max_display_duration_); }
    s.store_class_end();
  }
}

starGiftAuctionUserState::starGiftAuctionUserState()
  : flags_()
  , returned_()
  , bid_amount_()
  , bid_date_()
  , min_bid_amount_()
  , bid_peer_()
  , acquired_count_()
{}

const std::int32_t starGiftAuctionUserState::ID;

object_ptr<starGiftAuctionUserState> starGiftAuctionUserState::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftAuctionUserState> res = make_tl_object<starGiftAuctionUserState>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->returned_ = (var0 & 2) != 0;
  if (var0 & 1) { res->bid_amount_ = TlFetchLong::parse(p); }
  if (var0 & 1) { res->bid_date_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->min_bid_amount_ = TlFetchLong::parse(p); }
  if (var0 & 1) { res->bid_peer_ = TlFetchObject<Peer>::parse(p); }
  res->acquired_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starGiftAuctionUserState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionUserState");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (returned_ << 1) | ((bid_peer_ != nullptr) << 0)));
    if (var0 & 2) { s.store_field("returned", true); }
    if (var0 & 1) { s.store_field("bid_amount", bid_amount_); }
    if (var0 & 1) { s.store_field("bid_date", bid_date_); }
    if (var0 & 1) { s.store_field("min_bid_amount", min_bid_amount_); }
    if (var0 & 1) { s.store_object_field("bid_peer", static_cast<const BaseObject *>(bid_peer_.get())); }
    s.store_field("acquired_count", acquired_count_);
    s.store_class_end();
  }
}

starRefProgram::starRefProgram()
  : flags_()
  , bot_id_()
  , commission_permille_()
  , duration_months_()
  , end_date_()
  , daily_revenue_per_user_()
{}

const std::int32_t starRefProgram::ID;

object_ptr<starRefProgram> starRefProgram::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starRefProgram> res = make_tl_object<starRefProgram>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bot_id_ = TlFetchLong::parse(p);
  res->commission_permille_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->duration_months_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->end_date_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->daily_revenue_per_user_ = TlFetchObject<StarsAmount>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starRefProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starRefProgram");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((daily_revenue_per_user_ != nullptr) << 2)));
    s.store_field("bot_id", bot_id_);
    s.store_field("commission_permille", commission_permille_);
    if (var0 & 1) { s.store_field("duration_months", duration_months_); }
    if (var0 & 2) { s.store_field("end_date", end_date_); }
    if (var0 & 4) { s.store_object_field("daily_revenue_per_user", static_cast<const BaseObject *>(daily_revenue_per_user_.get())); }
    s.store_class_end();
  }
}

const std::int32_t statsAbsValueAndPrev::ID;

object_ptr<statsAbsValueAndPrev> statsAbsValueAndPrev::fetch(TlBufferParser &p) {
  return make_tl_object<statsAbsValueAndPrev>(p);
}

statsAbsValueAndPrev::statsAbsValueAndPrev(TlBufferParser &p)
  : current_(TlFetchDouble::parse(p))
  , previous_(TlFetchDouble::parse(p))
{}

void statsAbsValueAndPrev::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsAbsValueAndPrev");
    s.store_field("current", current_);
    s.store_field("previous", previous_);
    s.store_class_end();
  }
}

const std::int32_t statsGroupTopInviter::ID;

object_ptr<statsGroupTopInviter> statsGroupTopInviter::fetch(TlBufferParser &p) {
  return make_tl_object<statsGroupTopInviter>(p);
}

statsGroupTopInviter::statsGroupTopInviter(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , invitations_(TlFetchInt::parse(p))
{}

void statsGroupTopInviter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGroupTopInviter");
    s.store_field("user_id", user_id_);
    s.store_field("invitations", invitations_);
    s.store_class_end();
  }
}

object_ptr<StoryItem> StoryItem::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case storyItemDeleted::ID:
      return storyItemDeleted::fetch(p);
    case storyItemSkipped::ID:
      return storyItemSkipped::fetch(p);
    case storyItem::ID:
      return storyItem::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

storyItemDeleted::storyItemDeleted(int32 id_)
  : id_(id_)
{}

const std::int32_t storyItemDeleted::ID;

object_ptr<StoryItem> storyItemDeleted::fetch(TlBufferParser &p) {
  return make_tl_object<storyItemDeleted>(p);
}

storyItemDeleted::storyItemDeleted(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
{}

void storyItemDeleted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void storyItemDeleted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void storyItemDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyItemDeleted");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

storyItemSkipped::storyItemSkipped()
  : flags_()
  , close_friends_()
  , live_()
  , id_()
  , date_()
  , expire_date_()
{}

storyItemSkipped::storyItemSkipped(int32 flags_, bool close_friends_, bool live_, int32 id_, int32 date_, int32 expire_date_)
  : flags_(flags_)
  , close_friends_(close_friends_)
  , live_(live_)
  , id_(id_)
  , date_(date_)
  , expire_date_(expire_date_)
{}

const std::int32_t storyItemSkipped::ID;

object_ptr<StoryItem> storyItemSkipped::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyItemSkipped> res = make_tl_object<storyItemSkipped>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->close_friends_ = (var0 & 256) != 0;
  res->live_ = (var0 & 512) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->expire_date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void storyItemSkipped::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (close_friends_ << 8) | (live_ << 9)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(expire_date_, s);
}

void storyItemSkipped::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (close_friends_ << 8) | (live_ << 9)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(expire_date_, s);
}

void storyItemSkipped::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyItemSkipped");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (close_friends_ << 8) | (live_ << 9)));
    if (var0 & 256) { s.store_field("close_friends", true); }
    if (var0 & 512) { s.store_field("live", true); }
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_field("expire_date", expire_date_);
    s.store_class_end();
  }
}

storyItem::storyItem()
  : flags_()
  , pinned_()
  , public_()
  , close_friends_()
  , min_()
  , noforwards_()
  , edited_()
  , contacts_()
  , selected_contacts_()
  , out_()
  , id_()
  , date_()
  , from_id_()
  , fwd_from_()
  , expire_date_()
  , caption_()
  , entities_()
  , media_()
  , media_areas_()
  , privacy_()
  , views_()
  , sent_reaction_()
  , albums_()
  , music_()
{}

storyItem::storyItem(int32 flags_, bool pinned_, bool public_, bool close_friends_, bool min_, bool noforwards_, bool edited_, bool contacts_, bool selected_contacts_, bool out_, int32 id_, int32 date_, object_ptr<Peer> &&from_id_, object_ptr<storyFwdHeader> &&fwd_from_, int32 expire_date_, string const &caption_, array<object_ptr<MessageEntity>> &&entities_, object_ptr<MessageMedia> &&media_, array<object_ptr<MediaArea>> &&media_areas_, array<object_ptr<PrivacyRule>> &&privacy_, object_ptr<storyViews> &&views_, object_ptr<Reaction> &&sent_reaction_, array<int32> &&albums_, object_ptr<Document> &&music_)
  : flags_(flags_)
  , pinned_(pinned_)
  , public_(public_)
  , close_friends_(close_friends_)
  , min_(min_)
  , noforwards_(noforwards_)
  , edited_(edited_)
  , contacts_(contacts_)
  , selected_contacts_(selected_contacts_)
  , out_(out_)
  , id_(id_)
  , date_(date_)
  , from_id_(std::move(from_id_))
  , fwd_from_(std::move(fwd_from_))
  , expire_date_(expire_date_)
  , caption_(caption_)
  , entities_(std::move(entities_))
  , media_(std::move(media_))
  , media_areas_(std::move(media_areas_))
  , privacy_(std::move(privacy_))
  , views_(std::move(views_))
  , sent_reaction_(std::move(sent_reaction_))
  , albums_(std::move(albums_))
  , music_(std::move(music_))
{}

const std::int32_t storyItem::ID;

object_ptr<StoryItem> storyItem::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyItem> res = make_tl_object<storyItem>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 32) != 0;
  res->public_ = (var0 & 128) != 0;
  res->close_friends_ = (var0 & 256) != 0;
  res->min_ = (var0 & 512) != 0;
  res->noforwards_ = (var0 & 1024) != 0;
  res->edited_ = (var0 & 2048) != 0;
  res->contacts_ = (var0 & 4096) != 0;
  res->selected_contacts_ = (var0 & 8192) != 0;
  res->out_ = (var0 & 65536) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 262144) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 131072) { res->fwd_from_ = TlFetchBoxed<TlFetchObject<storyFwdHeader>, -1205411504>::parse(p); }
  res->expire_date_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->caption_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  res->media_ = TlFetchObject<MessageMedia>::parse(p);
  if (var0 & 16384) { res->media_areas_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MediaArea>>, 481674261>::parse(p); }
  if (var0 & 4) { res->privacy_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PrivacyRule>>, 481674261>::parse(p); }
  if (var0 & 8) { res->views_ = TlFetchBoxed<TlFetchObject<storyViews>, -1923523370>::parse(p); }
  if (var0 & 32768) { res->sent_reaction_ = TlFetchObject<Reaction>::parse(p); }
  if (var0 & 524288) { res->albums_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (var0 & 1048576) { res->music_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void storyItem::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 5) | (public_ << 7) | (close_friends_ << 8) | (min_ << 9) | (noforwards_ << 10) | (edited_ << 11) | (contacts_ << 12) | (selected_contacts_ << 13) | (out_ << 16) | ((from_id_ != nullptr) << 18) | ((fwd_from_ != nullptr) << 17) | ((!caption_.empty()) << 0) | ((!entities_.empty()) << 1) | ((!media_areas_.empty()) << 14) | ((!privacy_.empty()) << 2) | ((views_ != nullptr) << 3) | ((sent_reaction_ != nullptr) << 15) | ((!albums_.empty()) << 19) | ((music_ != nullptr) << 20)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 262144) { TlStoreBoxedUnknown<TlStoreObject>::store(from_id_, s); }
  if (var0 & 131072) { TlStoreBoxed<TlStoreObject, -1205411504>::store(fwd_from_, s); }
  TlStoreBinary::store(expire_date_, s);
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  if (var0 & 16384) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, -1923523370>::store(views_, s); }
  if (var0 & 32768) { TlStoreBoxedUnknown<TlStoreObject>::store(sent_reaction_, s); }
  if (var0 & 524288) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(albums_, s); }
  if (var0 & 1048576) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void storyItem::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 5) | (public_ << 7) | (close_friends_ << 8) | (min_ << 9) | (noforwards_ << 10) | (edited_ << 11) | (contacts_ << 12) | (selected_contacts_ << 13) | (out_ << 16) | ((from_id_ != nullptr) << 18) | ((fwd_from_ != nullptr) << 17) | ((!caption_.empty()) << 0) | ((!entities_.empty()) << 1) | ((!media_areas_.empty()) << 14) | ((!privacy_.empty()) << 2) | ((views_ != nullptr) << 3) | ((sent_reaction_ != nullptr) << 15) | ((!albums_.empty()) << 19) | ((music_ != nullptr) << 20)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 262144) { TlStoreBoxedUnknown<TlStoreObject>::store(from_id_, s); }
  if (var0 & 131072) { TlStoreBoxed<TlStoreObject, -1205411504>::store(fwd_from_, s); }
  TlStoreBinary::store(expire_date_, s);
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  if (var0 & 16384) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, -1923523370>::store(views_, s); }
  if (var0 & 32768) { TlStoreBoxedUnknown<TlStoreObject>::store(sent_reaction_, s); }
  if (var0 & 524288) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(albums_, s); }
  if (var0 & 1048576) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void storyItem::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyItem");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 5) | (public_ << 7) | (close_friends_ << 8) | (min_ << 9) | (noforwards_ << 10) | (edited_ << 11) | (contacts_ << 12) | (selected_contacts_ << 13) | (out_ << 16) | ((from_id_ != nullptr) << 18) | ((fwd_from_ != nullptr) << 17) | ((!caption_.empty()) << 0) | ((!entities_.empty()) << 1) | ((!media_areas_.empty()) << 14) | ((!privacy_.empty()) << 2) | ((views_ != nullptr) << 3) | ((sent_reaction_ != nullptr) << 15) | ((!albums_.empty()) << 19) | ((music_ != nullptr) << 20)));
    if (var0 & 32) { s.store_field("pinned", true); }
    if (var0 & 128) { s.store_field("public", true); }
    if (var0 & 256) { s.store_field("close_friends", true); }
    if (var0 & 512) { s.store_field("min", true); }
    if (var0 & 1024) { s.store_field("noforwards", true); }
    if (var0 & 2048) { s.store_field("edited", true); }
    if (var0 & 4096) { s.store_field("contacts", true); }
    if (var0 & 8192) { s.store_field("selected_contacts", true); }
    if (var0 & 65536) { s.store_field("out", true); }
    s.store_field("id", id_);
    s.store_field("date", date_);
    if (var0 & 262144) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 131072) { s.store_object_field("fwd_from", static_cast<const BaseObject *>(fwd_from_.get())); }
    s.store_field("expire_date", expire_date_);
    if (var0 & 1) { s.store_field("caption", caption_); }
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    if (var0 & 16384) { { s.store_vector_begin("media_areas", media_areas_.size()); for (const auto &_value : media_areas_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("privacy", privacy_.size()); for (const auto &_value : privacy_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 8) { s.store_object_field("views", static_cast<const BaseObject *>(views_.get())); }
    if (var0 & 32768) { s.store_object_field("sent_reaction", static_cast<const BaseObject *>(sent_reaction_.get())); }
    if (var0 & 524288) { { s.store_vector_begin("albums", albums_.size()); for (const auto &_value : albums_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 1048576) { s.store_object_field("music", static_cast<const BaseObject *>(music_.get())); }
    s.store_class_end();
  }
}

themeSettings::themeSettings()
  : flags_()
  , message_colors_animated_()
  , base_theme_()
  , accent_color_()
  , outbox_accent_color_()
  , message_colors_()
  , wallpaper_()
{}

themeSettings::themeSettings(int32 flags_, bool message_colors_animated_, object_ptr<BaseTheme> &&base_theme_, int32 accent_color_, int32 outbox_accent_color_, array<int32> &&message_colors_, object_ptr<WallPaper> &&wallpaper_)
  : flags_(flags_)
  , message_colors_animated_(message_colors_animated_)
  , base_theme_(std::move(base_theme_))
  , accent_color_(accent_color_)
  , outbox_accent_color_(outbox_accent_color_)
  , message_colors_(std::move(message_colors_))
  , wallpaper_(std::move(wallpaper_))
{}

const std::int32_t themeSettings::ID;

object_ptr<themeSettings> themeSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<themeSettings> res = make_tl_object<themeSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->message_colors_animated_ = (var0 & 4) != 0;
  res->base_theme_ = TlFetchObject<BaseTheme>::parse(p);
  res->accent_color_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->outbox_accent_color_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->message_colors_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (var0 & 2) { res->wallpaper_ = TlFetchObject<WallPaper>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void themeSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (message_colors_animated_ << 2) | ((!message_colors_.empty()) << 0) | ((wallpaper_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s);
  TlStoreBinary::store(accent_color_, s);
  if (var0 & 8) { TlStoreBinary::store(outbox_accent_color_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(message_colors_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
}

void themeSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (message_colors_animated_ << 2) | ((!message_colors_.empty()) << 0) | ((wallpaper_ != nullptr) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s);
  TlStoreBinary::store(accent_color_, s);
  if (var0 & 8) { TlStoreBinary::store(outbox_accent_color_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(message_colors_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
}

void themeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "themeSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (message_colors_animated_ << 2) | ((!message_colors_.empty()) << 0) | ((wallpaper_ != nullptr) << 1)));
    if (var0 & 4) { s.store_field("message_colors_animated", true); }
    s.store_object_field("base_theme", static_cast<const BaseObject *>(base_theme_.get()));
    s.store_field("accent_color", accent_color_);
    if (var0 & 8) { s.store_field("outbox_accent_color", outbox_accent_color_); }
    if (var0 & 1) { { s.store_vector_begin("message_colors", message_colors_.size()); for (const auto &_value : message_colors_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 2) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    s.store_class_end();
  }
}

const std::int32_t tonConnectNextEventId::ID;

object_ptr<tonConnectNextEventId> tonConnectNextEventId::fetch(TlBufferParser &p) {
  return make_tl_object<tonConnectNextEventId>(p);
}

tonConnectNextEventId::tonConnectNextEventId(TlBufferParser &p)
  : event_id_(TlFetchLong::parse(p))
{}

void tonConnectNextEventId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectNextEventId");
    s.store_field("event_id", event_id_);
    s.store_class_end();
  }
}

tonConnectRequest::tonConnectRequest()
  : flags_()
  , session_id_()
  , msg_id_()
  , body_()
  , expires_()
  , topic_()
  , trace_id_()
{}

const std::int32_t tonConnectRequest::ID;

object_ptr<tonConnectRequest> tonConnectRequest::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<tonConnectRequest> res = make_tl_object<tonConnectRequest>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->session_id_ = TlFetchLong::parse(p);
  res->msg_id_ = TlFetchInt::parse(p);
  res->body_ = TlFetchBytes<bytes>::parse(p);
  res->expires_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->topic_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->trace_id_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void tonConnectRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectRequest");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!topic_.empty()) << 0) | ((!trace_id_.empty()) << 1)));
    s.store_field("session_id", session_id_);
    s.store_field("msg_id", msg_id_);
    s.store_bytes_field("body", body_);
    s.store_field("expires", expires_);
    if (var0 & 1) { s.store_field("topic", topic_); }
    if (var0 & 2) { s.store_field("trace_id", trace_id_); }
    s.store_class_end();
  }
}

object_ptr<TopPeerCategory> TopPeerCategory::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t topPeerCategoryBotsPM::ID;

object_ptr<TopPeerCategory> topPeerCategoryBotsPM::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryBotsPM>();
}

void topPeerCategoryBotsPM::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsPM::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryBotsPM");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryBotsInline::ID;

object_ptr<TopPeerCategory> topPeerCategoryBotsInline::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryBotsInline>();
}

void topPeerCategoryBotsInline::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsInline::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsInline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryBotsInline");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryCorrespondents::ID;

object_ptr<TopPeerCategory> topPeerCategoryCorrespondents::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryCorrespondents>();
}

void topPeerCategoryCorrespondents::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryCorrespondents::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryCorrespondents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryCorrespondents");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryGroups::ID;

object_ptr<TopPeerCategory> topPeerCategoryGroups::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryGroups>();
}

void topPeerCategoryGroups::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryGroups::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryGroups");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryChannels::ID;

object_ptr<TopPeerCategory> topPeerCategoryChannels::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryChannels>();
}

void topPeerCategoryChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryChannels");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryPhoneCalls::ID;

object_ptr<TopPeerCategory> topPeerCategoryPhoneCalls::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryPhoneCalls>();
}

void topPeerCategoryPhoneCalls::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryPhoneCalls::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryPhoneCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryPhoneCalls");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryForwardUsers::ID;

object_ptr<TopPeerCategory> topPeerCategoryForwardUsers::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryForwardUsers>();
}

void topPeerCategoryForwardUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryForwardUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryForwardUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryForwardUsers");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryForwardChats::ID;

object_ptr<TopPeerCategory> topPeerCategoryForwardChats::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryForwardChats>();
}

void topPeerCategoryForwardChats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryForwardChats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryForwardChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryForwardChats");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryBotsApp::ID;

object_ptr<TopPeerCategory> topPeerCategoryBotsApp::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryBotsApp>();
}

void topPeerCategoryBotsApp::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsApp::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryBotsApp");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryBotsGuestChat::ID;

object_ptr<TopPeerCategory> topPeerCategoryBotsGuestChat::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryBotsGuestChat>();
}

void topPeerCategoryBotsGuestChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsGuestChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsGuestChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryBotsGuestChat");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryPeers::ID;

object_ptr<topPeerCategoryPeers> topPeerCategoryPeers::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryPeers>(p);
}

topPeerCategoryPeers::topPeerCategoryPeers(TlBufferParser &p)
  : category_(TlFetchObject<TopPeerCategory>::parse(p))
  , count_(TlFetchInt::parse(p))
  , peers_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<topPeer>, -305282981>>, 481674261>::parse(p))
{}

void topPeerCategoryPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryPeers");
    s.store_object_field("category", static_cast<const BaseObject *>(category_.get()));
    s.store_field("count", count_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<UserStatus> UserStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t userStatusEmpty::ID;

object_ptr<UserStatus> userStatusEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<userStatusEmpty>();
}

void userStatusEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusEmpty");
    s.store_class_end();
  }
}

const std::int32_t userStatusOnline::ID;

object_ptr<UserStatus> userStatusOnline::fetch(TlBufferParser &p) {
  return make_tl_object<userStatusOnline>(p);
}

userStatusOnline::userStatusOnline(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
{}

void userStatusOnline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusOnline");
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

const std::int32_t userStatusOffline::ID;

object_ptr<UserStatus> userStatusOffline::fetch(TlBufferParser &p) {
  return make_tl_object<userStatusOffline>(p);
}

userStatusOffline::userStatusOffline(TlBufferParser &p)
  : was_online_(TlFetchInt::parse(p))
{}

void userStatusOffline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusOffline");
    s.store_field("was_online", was_online_);
    s.store_class_end();
  }
}

userStatusRecently::userStatusRecently()
  : flags_()
  , by_me_()
{}

const std::int32_t userStatusRecently::ID;

object_ptr<UserStatus> userStatusRecently::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<userStatusRecently> res = make_tl_object<userStatusRecently>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->by_me_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void userStatusRecently::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusRecently");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (by_me_ << 0)));
    if (var0 & 1) { s.store_field("by_me", true); }
    s.store_class_end();
  }
}

userStatusLastWeek::userStatusLastWeek()
  : flags_()
  , by_me_()
{}

const std::int32_t userStatusLastWeek::ID;

object_ptr<UserStatus> userStatusLastWeek::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<userStatusLastWeek> res = make_tl_object<userStatusLastWeek>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->by_me_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void userStatusLastWeek::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusLastWeek");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (by_me_ << 0)));
    if (var0 & 1) { s.store_field("by_me", true); }
    s.store_class_end();
  }
}

userStatusLastMonth::userStatusLastMonth()
  : flags_()
  , by_me_()
{}

const std::int32_t userStatusLastMonth::ID;

object_ptr<UserStatus> userStatusLastMonth::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<userStatusLastMonth> res = make_tl_object<userStatusLastMonth>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->by_me_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void userStatusLastMonth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusLastMonth");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (by_me_ << 0)));
    if (var0 & 1) { s.store_field("by_me", true); }
    s.store_class_end();
  }
}

webDomainException::webDomainException()
  : flags_()
  , domain_()
  , url_()
  , title_()
  , favicon_()
{}

const std::int32_t webDomainException::ID;

object_ptr<webDomainException> webDomainException::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webDomainException> res = make_tl_object<webDomainException>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->domain_ = TlFetchString<string>::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->favicon_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void webDomainException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webDomainException");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("domain", domain_);
    s.store_field("url", url_);
    s.store_field("title", title_);
    if (var0 & 1) { s.store_field("favicon", favicon_); }
    s.store_class_end();
  }
}

const std::int32_t account_autoSaveSettings::ID;

object_ptr<account_autoSaveSettings> account_autoSaveSettings::fetch(TlBufferParser &p) {
  return make_tl_object<account_autoSaveSettings>(p);
}

account_autoSaveSettings::account_autoSaveSettings(TlBufferParser &p)
  : users_settings_(TlFetchBoxed<TlFetchObject<autoSaveSettings>, -934791986>::parse(p))
  , chats_settings_(TlFetchBoxed<TlFetchObject<autoSaveSettings>, -934791986>::parse(p))
  , broadcasts_settings_(TlFetchBoxed<TlFetchObject<autoSaveSettings>, -934791986>::parse(p))
  , exceptions_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<autoSaveException>, -2124403385>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void account_autoSaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.autoSaveSettings");
    s.store_object_field("users_settings", static_cast<const BaseObject *>(users_settings_.get()));
    s.store_object_field("chats_settings", static_cast<const BaseObject *>(chats_settings_.get()));
    s.store_object_field("broadcasts_settings", static_cast<const BaseObject *>(broadcasts_settings_.get()));
    { s.store_vector_begin("exceptions", exceptions_.size()); for (const auto &_value : exceptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_password::account_password()
  : flags_()
  , has_recovery_()
  , has_secure_values_()
  , has_password_()
  , current_algo_()
  , srp_B_()
  , srp_id_()
  , hint_()
  , email_unconfirmed_pattern_()
  , new_algo_()
  , new_secure_algo_()
  , secure_random_()
  , pending_reset_date_()
  , login_email_pattern_()
{}

const std::int32_t account_password::ID;

object_ptr<account_password> account_password::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_password> res = make_tl_object<account_password>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_recovery_ = (var0 & 1) != 0;
  res->has_secure_values_ = (var0 & 2) != 0;
  res->has_password_ = (var0 & 4) != 0;
  if (var0 & 4) { res->current_algo_ = TlFetchObject<PasswordKdfAlgo>::parse(p); }
  if (var0 & 4) { res->srp_B_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 4) { res->srp_id_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->hint_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->email_unconfirmed_pattern_ = TlFetchString<string>::parse(p); }
  res->new_algo_ = TlFetchObject<PasswordKdfAlgo>::parse(p);
  res->new_secure_algo_ = TlFetchObject<SecurePasswordKdfAlgo>::parse(p);
  res->secure_random_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 32) { res->pending_reset_date_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->login_email_pattern_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void account_password::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.password");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_recovery_ << 0) | (has_secure_values_ << 1) | (has_password_ << 2) | ((current_algo_ != nullptr) << 2) | ((!srp_B_.empty()) << 2) | ((!hint_.empty()) << 3) | ((!email_unconfirmed_pattern_.empty()) << 4) | ((!login_email_pattern_.empty()) << 6)));
    if (var0 & 1) { s.store_field("has_recovery", true); }
    if (var0 & 2) { s.store_field("has_secure_values", true); }
    if (var0 & 4) { s.store_field("has_password", true); }
    if (var0 & 4) { s.store_object_field("current_algo", static_cast<const BaseObject *>(current_algo_.get())); }
    if (var0 & 4) { s.store_bytes_field("srp_B", srp_B_); }
    if (var0 & 4) { s.store_field("srp_id", srp_id_); }
    if (var0 & 8) { s.store_field("hint", hint_); }
    if (var0 & 16) { s.store_field("email_unconfirmed_pattern", email_unconfirmed_pattern_); }
    s.store_object_field("new_algo", static_cast<const BaseObject *>(new_algo_.get()));
    s.store_object_field("new_secure_algo", static_cast<const BaseObject *>(new_secure_algo_.get()));
    s.store_bytes_field("secure_random", secure_random_);
    if (var0 & 32) { s.store_field("pending_reset_date", pending_reset_date_); }
    if (var0 & 64) { s.store_field("login_email_pattern", login_email_pattern_); }
    s.store_class_end();
  }
}

const std::int32_t account_privacyRules::ID;

object_ptr<account_privacyRules> account_privacyRules::fetch(TlBufferParser &p) {
  return make_tl_object<account_privacyRules>(p);
}

account_privacyRules::account_privacyRules(TlBufferParser &p)
  : rules_(TlFetchBoxed<TlFetchVector<TlFetchObject<PrivacyRule>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void account_privacyRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.privacyRules");
    { s.store_vector_begin("rules", rules_.size()); for (const auto &_value : rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<account_SavedMusicIds> account_SavedMusicIds::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_savedMusicIdsNotModified::ID:
      return account_savedMusicIdsNotModified::fetch(p);
    case account_savedMusicIds::ID:
      return account_savedMusicIds::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_savedMusicIdsNotModified::ID;

object_ptr<account_SavedMusicIds> account_savedMusicIdsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedMusicIdsNotModified>();
}

void account_savedMusicIdsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedMusicIdsNotModified");
    s.store_class_end();
  }
}

const std::int32_t account_savedMusicIds::ID;

object_ptr<account_SavedMusicIds> account_savedMusicIds::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedMusicIds>(p);
}

account_savedMusicIds::account_savedMusicIds(TlBufferParser &p)
  : ids_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void account_savedMusicIds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedMusicIds");
    { s.store_vector_begin("ids", ids_.size()); for (const auto &_value : ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t account_sentEmailCode::ID;

object_ptr<account_sentEmailCode> account_sentEmailCode::fetch(TlBufferParser &p) {
  return make_tl_object<account_sentEmailCode>(p);
}

account_sentEmailCode::account_sentEmailCode(TlBufferParser &p)
  : email_pattern_(TlFetchString<string>::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void account_sentEmailCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.sentEmailCode");
    s.store_field("email_pattern", email_pattern_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

const std::int32_t auth_firebasePnvIntent::ID;

object_ptr<auth_firebasePnvIntent> auth_firebasePnvIntent::fetch(TlBufferParser &p) {
  return make_tl_object<auth_firebasePnvIntent>(p);
}

auth_firebasePnvIntent::auth_firebasePnvIntent(TlBufferParser &p)
  : nonce_(TlFetchString<string>::parse(p))
  , digital_credential_payload_(TlFetchString<string>::parse(p))
{}

void auth_firebasePnvIntent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.firebasePnvIntent");
    s.store_field("nonce", nonce_);
    s.store_field("digital_credential_payload", digital_credential_payload_);
    s.store_class_end();
  }
}

object_ptr<contacts_TopPeers> contacts_TopPeers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case contacts_topPeersNotModified::ID:
      return contacts_topPeersNotModified::fetch(p);
    case contacts_topPeers::ID:
      return contacts_topPeers::fetch(p);
    case contacts_topPeersDisabled::ID:
      return contacts_topPeersDisabled::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t contacts_topPeersNotModified::ID;

object_ptr<contacts_TopPeers> contacts_topPeersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_topPeersNotModified>();
}

void contacts_topPeersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.topPeersNotModified");
    s.store_class_end();
  }
}

const std::int32_t contacts_topPeers::ID;

object_ptr<contacts_TopPeers> contacts_topPeers::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_topPeers>(p);
}

contacts_topPeers::contacts_topPeers(TlBufferParser &p)
  : categories_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<topPeerCategoryPeers>, -75283823>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_topPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.topPeers");
    { s.store_vector_begin("categories", categories_.size()); for (const auto &_value : categories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t contacts_topPeersDisabled::ID;

object_ptr<contacts_TopPeers> contacts_topPeersDisabled::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_topPeersDisabled>();
}

void contacts_topPeersDisabled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.topPeersDisabled");
    s.store_class_end();
  }
}

object_ptr<help_AppUpdate> help_AppUpdate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_appUpdate::ID:
      return help_appUpdate::fetch(p);
    case help_noAppUpdate::ID:
      return help_noAppUpdate::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

help_appUpdate::help_appUpdate()
  : flags_()
  , can_not_skip_()
  , id_()
  , version_()
  , text_()
  , entities_()
  , document_()
  , url_()
  , sticker_()
{}

const std::int32_t help_appUpdate::ID;

object_ptr<help_AppUpdate> help_appUpdate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_appUpdate> res = make_tl_object<help_appUpdate>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_not_skip_ = (var0 & 1) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->version_ = TlFetchString<string>::parse(p);
  res->text_ = TlFetchString<string>::parse(p);
  res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p);
  if (var0 & 2) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 4) { res->url_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->sticker_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void help_appUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.appUpdate");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_not_skip_ << 0) | ((document_ != nullptr) << 1) | ((!url_.empty()) << 2) | ((sticker_ != nullptr) << 3)));
    if (var0 & 1) { s.store_field("can_not_skip", true); }
    s.store_field("id", id_);
    s.store_field("version", version_);
    s.store_field("text", text_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 2) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 4) { s.store_field("url", url_); }
    if (var0 & 8) { s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get())); }
    s.store_class_end();
  }
}

const std::int32_t help_noAppUpdate::ID;

object_ptr<help_AppUpdate> help_noAppUpdate::fetch(TlBufferParser &p) {
  return make_tl_object<help_noAppUpdate>();
}

void help_noAppUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.noAppUpdate");
    s.store_class_end();
  }
}

object_ptr<help_CountriesList> help_CountriesList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_countriesListNotModified::ID:
      return help_countriesListNotModified::fetch(p);
    case help_countriesList::ID:
      return help_countriesList::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_countriesListNotModified::ID;

object_ptr<help_CountriesList> help_countriesListNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<help_countriesListNotModified>();
}

void help_countriesListNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.countriesListNotModified");
    s.store_class_end();
  }
}

const std::int32_t help_countriesList::ID;

object_ptr<help_CountriesList> help_countriesList::fetch(TlBufferParser &p) {
  return make_tl_object<help_countriesList>(p);
}

help_countriesList::help_countriesList(TlBufferParser &p)
  : countries_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<help_country>, -1014526429>>, 481674261>::parse(p))
  , hash_(TlFetchInt::parse(p))
{}

void help_countriesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.countriesList");
    { s.store_vector_begin("countries", countries_.size()); for (const auto &_value : countries_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_countryCode::help_countryCode()
  : flags_()
  , country_code_()
  , prefixes_()
  , patterns_()
{}

const std::int32_t help_countryCode::ID;

object_ptr<help_countryCode> help_countryCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_countryCode> res = make_tl_object<help_countryCode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->country_code_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->prefixes_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p); }
  if (var0 & 2) { res->patterns_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void help_countryCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.countryCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!prefixes_.empty()) << 0) | ((!patterns_.empty()) << 1)));
    s.store_field("country_code", country_code_);
    if (var0 & 1) { { s.store_vector_begin("prefixes", prefixes_.size()); for (const auto &_value : prefixes_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 2) { { s.store_vector_begin("patterns", patterns_.size()); for (const auto &_value : patterns_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t messages_checkedHistoryImportPeer::ID;

object_ptr<messages_checkedHistoryImportPeer> messages_checkedHistoryImportPeer::fetch(TlBufferParser &p) {
  return make_tl_object<messages_checkedHistoryImportPeer>(p);
}

messages_checkedHistoryImportPeer::messages_checkedHistoryImportPeer(TlBufferParser &p)
  : confirm_text_(TlFetchString<string>::parse(p))
{}

void messages_checkedHistoryImportPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkedHistoryImportPeer");
    s.store_field("confirm_text", confirm_text_);
    s.store_class_end();
  }
}

const std::int32_t messages_exportedChatInvites::ID;

object_ptr<messages_exportedChatInvites> messages_exportedChatInvites::fetch(TlBufferParser &p) {
  return make_tl_object<messages_exportedChatInvites>(p);
}

messages_exportedChatInvites::messages_exportedChatInvites(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , invites_(TlFetchBoxed<TlFetchVector<TlFetchObject<ExportedChatInvite>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_exportedChatInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.exportedChatInvites");
    s.store_field("count", count_);
    { s.store_vector_begin("invites", invites_.size()); for (const auto &_value : invites_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_inactiveChats::ID;

object_ptr<messages_inactiveChats> messages_inactiveChats::fetch(TlBufferParser &p) {
  return make_tl_object<messages_inactiveChats>(p);
}

messages_inactiveChats::messages_inactiveChats(TlBufferParser &p)
  : dates_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_inactiveChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.inactiveChats");
    { s.store_vector_begin("dates", dates_.size()); for (const auto &_value : dates_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_messageEditData::messages_messageEditData()
  : flags_()
  , caption_()
{}

const std::int32_t messages_messageEditData::ID;

object_ptr<messages_messageEditData> messages_messageEditData::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_messageEditData> res = make_tl_object<messages_messageEditData>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->caption_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_messageEditData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messageEditData");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (caption_ << 0)));
    if (var0 & 1) { s.store_field("caption", true); }
    s.store_class_end();
  }
}

object_ptr<messages_RecentStickers> messages_RecentStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_recentStickersNotModified::ID:
      return messages_recentStickersNotModified::fetch(p);
    case messages_recentStickers::ID:
      return messages_recentStickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_recentStickersNotModified::ID;

object_ptr<messages_RecentStickers> messages_recentStickersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_recentStickersNotModified>();
}

void messages_recentStickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.recentStickersNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_recentStickers::ID;

object_ptr<messages_RecentStickers> messages_recentStickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_recentStickers>(p);
}

messages_recentStickers::messages_recentStickers(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , packs_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerPack>, 313694676>>, 481674261>::parse(p))
  , stickers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
  , dates_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void messages_recentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.recentStickers");
    s.store_field("hash", hash_);
    { s.store_vector_begin("packs", packs_.size()); for (const auto &_value : packs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("dates", dates_.size()); for (const auto &_value : dates_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_webPage::ID;

object_ptr<messages_webPage> messages_webPage::fetch(TlBufferParser &p) {
  return make_tl_object<messages_webPage>(p);
}

messages_webPage::messages_webPage(TlBufferParser &p)
  : webpage_(TlFetchObject<WebPage>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_webPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.webPage");
    s.store_object_field("webpage", static_cast<const BaseObject *>(webpage_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_currencyRates::ID;

object_ptr<payments_currencyRates> payments_currencyRates::fetch(TlBufferParser &p) {
  return make_tl_object<payments_currencyRates>(p);
}

payments_currencyRates::payments_currencyRates(TlBufferParser &p)
  : rates_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<currencyRate>, 819557436>>, 481674261>::parse(p))
{}

void payments_currencyRates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.currencyRates");
    { s.store_vector_begin("rates", rates_.size()); for (const auto &_value : rates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_validatedRequestedInfo::payments_validatedRequestedInfo()
  : flags_()
  , id_()
  , shipping_options_()
{}

const std::int32_t payments_validatedRequestedInfo::ID;

object_ptr<payments_validatedRequestedInfo> payments_validatedRequestedInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_validatedRequestedInfo> res = make_tl_object<payments_validatedRequestedInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->id_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->shipping_options_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<shippingOption>, -1239335713>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_validatedRequestedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.validatedRequestedInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!id_.empty()) << 0) | ((!shipping_options_.empty()) << 1)));
    if (var0 & 1) { s.store_field("id", id_); }
    if (var0 & 2) { { s.store_vector_begin("shipping_options", shipping_options_.size()); for (const auto &_value : shipping_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

premium_boostsList::premium_boostsList()
  : flags_()
  , count_()
  , boosts_()
  , next_offset_()
  , users_()
{}

const std::int32_t premium_boostsList::ID;

object_ptr<premium_boostsList> premium_boostsList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<premium_boostsList> res = make_tl_object<premium_boostsList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->boosts_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<boost>, 1262359766>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void premium_boostsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.boostsList");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("count", count_);
    { s.store_vector_begin("boosts", boosts_.size()); for (const auto &_value : boosts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

smsjobs_status::smsjobs_status()
  : flags_()
  , allow_international_()
  , recent_sent_()
  , recent_since_()
  , recent_remains_()
  , total_sent_()
  , total_since_()
  , last_gift_slug_()
  , terms_url_()
{}

const std::int32_t smsjobs_status::ID;

object_ptr<smsjobs_status> smsjobs_status::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<smsjobs_status> res = make_tl_object<smsjobs_status>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->allow_international_ = (var0 & 1) != 0;
  res->recent_sent_ = TlFetchInt::parse(p);
  res->recent_since_ = TlFetchInt::parse(p);
  res->recent_remains_ = TlFetchInt::parse(p);
  res->total_sent_ = TlFetchInt::parse(p);
  res->total_since_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->last_gift_slug_ = TlFetchString<string>::parse(p); }
  res->terms_url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void smsjobs_status::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.status");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (allow_international_ << 0) | ((!last_gift_slug_.empty()) << 1)));
    if (var0 & 1) { s.store_field("allow_international", true); }
    s.store_field("recent_sent", recent_sent_);
    s.store_field("recent_since", recent_since_);
    s.store_field("recent_remains", recent_remains_);
    s.store_field("total_sent", total_sent_);
    s.store_field("total_since", total_since_);
    if (var0 & 2) { s.store_field("last_gift_slug", last_gift_slug_); }
    s.store_field("terms_url", terms_url_);
    s.store_class_end();
  }
}

stats_publicForwards::stats_publicForwards()
  : flags_()
  , count_()
  , forwards_()
  , next_offset_()
  , chats_()
  , users_()
{}

const std::int32_t stats_publicForwards::ID;

object_ptr<stats_publicForwards> stats_publicForwards::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stats_publicForwards> res = make_tl_object<stats_publicForwards>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->forwards_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PublicForward>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stats_publicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.publicForwards");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("count", count_);
    { s.store_vector_begin("forwards", forwards_.size()); for (const auto &_value : forwards_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<storage_FileType> storage_FileType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t storage_fileUnknown::ID;

object_ptr<storage_FileType> storage_fileUnknown::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileUnknown>();
}

void storage_fileUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileUnknown");
    s.store_class_end();
  }
}

const std::int32_t storage_filePartial::ID;

object_ptr<storage_FileType> storage_filePartial::fetch(TlBufferParser &p) {
  return make_tl_object<storage_filePartial>();
}

void storage_filePartial::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.filePartial");
    s.store_class_end();
  }
}

const std::int32_t storage_fileJpeg::ID;

object_ptr<storage_FileType> storage_fileJpeg::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileJpeg>();
}

void storage_fileJpeg::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileJpeg");
    s.store_class_end();
  }
}

const std::int32_t storage_fileGif::ID;

object_ptr<storage_FileType> storage_fileGif::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileGif>();
}

void storage_fileGif::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileGif");
    s.store_class_end();
  }
}

const std::int32_t storage_filePng::ID;

object_ptr<storage_FileType> storage_filePng::fetch(TlBufferParser &p) {
  return make_tl_object<storage_filePng>();
}

void storage_filePng::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.filePng");
    s.store_class_end();
  }
}

const std::int32_t storage_filePdf::ID;

object_ptr<storage_FileType> storage_filePdf::fetch(TlBufferParser &p) {
  return make_tl_object<storage_filePdf>();
}

void storage_filePdf::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.filePdf");
    s.store_class_end();
  }
}

const std::int32_t storage_fileMp3::ID;

object_ptr<storage_FileType> storage_fileMp3::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileMp3>();
}

void storage_fileMp3::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileMp3");
    s.store_class_end();
  }
}

const std::int32_t storage_fileMov::ID;

object_ptr<storage_FileType> storage_fileMov::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileMov>();
}

void storage_fileMov::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileMov");
    s.store_class_end();
  }
}

const std::int32_t storage_fileMp4::ID;

object_ptr<storage_FileType> storage_fileMp4::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileMp4>();
}

void storage_fileMp4::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileMp4");
    s.store_class_end();
  }
}

const std::int32_t storage_fileWebp::ID;

object_ptr<storage_FileType> storage_fileWebp::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileWebp>();
}

void storage_fileWebp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileWebp");
    s.store_class_end();
  }
}

stories_storyViewsList::stories_storyViewsList()
  : flags_()
  , count_()
  , views_count_()
  , forwards_count_()
  , reactions_count_()
  , views_()
  , chats_()
  , users_()
  , next_offset_()
{}

const std::int32_t stories_storyViewsList::ID;

object_ptr<stories_storyViewsList> stories_storyViewsList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_storyViewsList> res = make_tl_object<stories_storyViewsList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->views_count_ = TlFetchInt::parse(p);
  res->forwards_count_ = TlFetchInt::parse(p);
  res->reactions_count_ = TlFetchInt::parse(p);
  res->views_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StoryView>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stories_storyViewsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.storyViewsList");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("count", count_);
    s.store_field("views_count", views_count_);
    s.store_field("forwards_count", forwards_count_);
    s.store_field("reactions_count", reactions_count_);
    { s.store_vector_begin("views", views_.size()); for (const auto &_value : views_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

const std::int32_t toncenter_apiResponse::ID;

object_ptr<toncenter_apiResponse> toncenter_apiResponse::fetch(TlBufferParser &p) {
  return make_tl_object<toncenter_apiResponse>(p);
}

toncenter_apiResponse::toncenter_apiResponse(TlBufferParser &p)
  : response_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void toncenter_apiResponse::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toncenter.apiResponse");
    s.store_object_field("response", static_cast<const BaseObject *>(response_.get()));
    s.store_class_end();
  }
}

object_ptr<upload_File> upload_File::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case upload_file::ID:
      return upload_file::fetch(p);
    case upload_fileCdnRedirect::ID:
      return upload_fileCdnRedirect::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t upload_file::ID;

object_ptr<upload_File> upload_file::fetch(TlBufferParser &p) {
  return make_tl_object<upload_file>(p);
}

upload_file::upload_file(TlBufferParser &p)
  : type_(TlFetchObject<storage_FileType>::parse(p))
  , mtime_(TlFetchInt::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void upload_file::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.file");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("mtime", mtime_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

const std::int32_t upload_fileCdnRedirect::ID;

object_ptr<upload_File> upload_fileCdnRedirect::fetch(TlBufferParser &p) {
  return make_tl_object<upload_fileCdnRedirect>(p);
}

upload_fileCdnRedirect::upload_fileCdnRedirect(TlBufferParser &p)
  : dc_id_(TlFetchInt::parse(p))
  , file_token_(TlFetchBytes<bytes>::parse(p))
  , encryption_key_(TlFetchBytes<bytes>::parse(p))
  , encryption_iv_(TlFetchBytes<bytes>::parse(p))
  , file_hashes_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<fileHash>, -207944868>>, 481674261>::parse(p))
{}

void upload_fileCdnRedirect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.fileCdnRedirect");
    s.store_field("dc_id", dc_id_);
    s.store_field("file_token", "[REDACTED]");
    s.store_field("encryption_key", "[REDACTED]");
    s.store_field("encryption_iv", "[REDACTED]");
    { s.store_vector_begin("file_hashes", file_hashes_.size()); for (const auto &_value : file_hashes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t wallet_proofChallenge::ID;

object_ptr<wallet_proofChallenge> wallet_proofChallenge::fetch(TlBufferParser &p) {
  return make_tl_object<wallet_proofChallenge>(p);
}

wallet_proofChallenge::wallet_proofChallenge(TlBufferParser &p)
  : payload_(TlFetchString<string>::parse(p))
  , expires_(TlFetchInt::parse(p))
  , domain_(TlFetchString<string>::parse(p))
{}

void wallet_proofChallenge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.proofChallenge");
    s.store_field("payload", payload_);
    s.store_field("expires", expires_);
    s.store_field("domain", domain_);
    s.store_class_end();
  }
}

account_acceptAuthorization::account_acceptAuthorization(int64 bot_id_, string const &scope_, string const &public_key_, array<object_ptr<secureValueHash>> &&value_hashes_, object_ptr<secureCredentialsEncrypted> &&credentials_)
  : bot_id_(bot_id_)
  , scope_(scope_)
  , public_key_(public_key_)
  , value_hashes_(std::move(value_hashes_))
  , credentials_(std::move(credentials_))
{}

const std::int32_t account_acceptAuthorization::ID;

void account_acceptAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-202552205);
  TlStoreBinary::store(bot_id_, s);
  TlStoreString::store(scope_, s);
  TlStoreString::store(public_key_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -316748368>>, 481674261>::store(value_hashes_, s);
  TlStoreBoxed<TlStoreObject, 871426631>::store(credentials_, s);
}

void account_acceptAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-202552205);
  TlStoreBinary::store(bot_id_, s);
  TlStoreString::store(scope_, s);
  TlStoreString::store(public_key_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -316748368>>, 481674261>::store(value_hashes_, s);
  TlStoreBoxed<TlStoreObject, 871426631>::store(credentials_, s);
}

void account_acceptAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.acceptAuthorization");
    s.store_field("bot_id", bot_id_);
    s.store_field("scope", scope_);
    s.store_field("public_key", public_key_);
    { s.store_vector_begin("value_hashes", value_hashes_.size()); for (const auto &_value : value_hashes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    s.store_class_end();
  }
}

account_acceptAuthorization::ReturnType account_acceptAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_disablePeerConnectedBot::account_disablePeerConnectedBot(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t account_disablePeerConnectedBot::ID;

void account_disablePeerConnectedBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1581481689);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void account_disablePeerConnectedBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1581481689);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void account_disablePeerConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.disablePeerConnectedBot");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

account_disablePeerConnectedBot::ReturnType account_disablePeerConnectedBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_getContentSettings::ID;

void account_getContentSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1952756306);
}

void account_getContentSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1952756306);
}

void account_getContentSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getContentSettings");
    s.store_class_end();
  }
}

account_getContentSettings::ReturnType account_getContentSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_contentSettings>, 1474462241>::parse(p);
#undef FAIL
}

account_getTmpPassword::account_getTmpPassword(object_ptr<InputCheckPasswordSRP> &&password_, int32 period_)
  : password_(std::move(password_))
  , period_(period_)
{}

const std::int32_t account_getTmpPassword::ID;

void account_getTmpPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1151208273);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
  TlStoreBinary::store(period_, s);
}

void account_getTmpPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1151208273);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
  TlStoreBinary::store(period_, s);
}

void account_getTmpPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getTmpPassword");
    s.store_field("password", "[REDACTED]");
    s.store_field("period", period_);
    s.store_class_end();
  }
}

account_getTmpPassword::ReturnType account_getTmpPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_tmpPassword>, -614138572>::parse(p);
#undef FAIL
}

account_getWallPaper::account_getWallPaper(object_ptr<InputWallPaper> &&wallpaper_)
  : wallpaper_(std::move(wallpaper_))
{}

const std::int32_t account_getWallPaper::ID;

void account_getWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-57811990);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
}

void account_getWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-57811990);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
}

void account_getWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getWallPaper");
    s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get()));
    s.store_class_end();
  }
}

account_getWallPaper::ReturnType account_getWallPaper::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<WallPaper>::parse(p);
#undef FAIL
}

account_getWallPapers::account_getWallPapers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getWallPapers::ID;

void account_getWallPapers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(127302966);
  TlStoreBinary::store(hash_, s);
}

void account_getWallPapers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(127302966);
  TlStoreBinary::store(hash_, s);
}

void account_getWallPapers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getWallPapers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getWallPapers::ReturnType account_getWallPapers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_WallPapers>::parse(p);
#undef FAIL
}

account_reorderUsernames::account_reorderUsernames(array<string> &&order_)
  : order_(std::move(order_))
{}

const std::int32_t account_reorderUsernames::ID;

void account_reorderUsernames::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-279966037);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void account_reorderUsernames::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-279966037);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void account_reorderUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.reorderUsernames");
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_reorderUsernames::ReturnType account_reorderUsernames::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_resetWebAuthorizations::ID;

void account_resetWebAuthorizations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1747789204);
}

void account_resetWebAuthorizations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1747789204);
}

void account_resetWebAuthorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetWebAuthorizations");
    s.store_class_end();
  }
}

account_resetWebAuthorizations::ReturnType account_resetWebAuthorizations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_saveRingtone::account_saveRingtone(object_ptr<InputDocument> &&id_, bool unsave_)
  : id_(std::move(id_))
  , unsave_(unsave_)
{}

const std::int32_t account_saveRingtone::ID;

void account_saveRingtone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1038768899);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void account_saveRingtone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1038768899);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void account_saveRingtone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveRingtone");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("unsave", unsave_);
    s.store_class_end();
  }
}

account_saveRingtone::ReturnType account_saveRingtone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_SavedRingtone>::parse(p);
#undef FAIL
}

account_sendVerifyEmailCode::account_sendVerifyEmailCode(object_ptr<EmailVerifyPurpose> &&purpose_, string const &email_)
  : purpose_(std::move(purpose_))
  , email_(email_)
{}

const std::int32_t account_sendVerifyEmailCode::ID;

void account_sendVerifyEmailCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1730136133);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreString::store(email_, s);
}

void account_sendVerifyEmailCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1730136133);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreString::store(email_, s);
}

void account_sendVerifyEmailCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.sendVerifyEmailCode");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_field("email", email_);
    s.store_class_end();
  }
}

account_sendVerifyEmailCode::ReturnType account_sendVerifyEmailCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_sentEmailCode>, -2128640689>::parse(p);
#undef FAIL
}

account_toggleSponsoredMessages::account_toggleSponsoredMessages(bool enabled_)
  : enabled_(enabled_)
{}

const std::int32_t account_toggleSponsoredMessages::ID;

void account_toggleSponsoredMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1176919155);
  TlStoreBool::store(enabled_, s);
}

void account_toggleSponsoredMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1176919155);
  TlStoreBool::store(enabled_, s);
}

void account_toggleSponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.toggleSponsoredMessages");
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

account_toggleSponsoredMessages::ReturnType account_toggleSponsoredMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateEmojiStatus::account_updateEmojiStatus(object_ptr<EmojiStatus> &&emoji_status_)
  : emoji_status_(std::move(emoji_status_))
{}

const std::int32_t account_updateEmojiStatus::ID;

void account_updateEmojiStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-70001045);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void account_updateEmojiStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-70001045);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void account_updateEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateEmojiStatus");
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

account_updateEmojiStatus::ReturnType account_updateEmojiStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_cancelWebTokenAuthorization::auth_cancelWebTokenAuthorization(string const &web_auth_token_)
  : web_auth_token_(web_auth_token_)
{}

const std::int32_t auth_cancelWebTokenAuthorization::ID;

void auth_cancelWebTokenAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1225633185);
  TlStoreString::store(web_auth_token_, s);
}

void auth_cancelWebTokenAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1225633185);
  TlStoreString::store(web_auth_token_, s);
}

void auth_cancelWebTokenAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.cancelWebTokenAuthorization");
    s.store_field("web_auth_token", "[REDACTED]");
    s.store_class_end();
  }
}

auth_cancelWebTokenAuthorization::ReturnType auth_cancelWebTokenAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_checkPaidAuth::auth_checkPaidAuth(string const &phone_number_, string const &phone_code_hash_, int64 form_id_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , form_id_(form_id_)
{}

const std::int32_t auth_checkPaidAuth::ID;

void auth_checkPaidAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1457889180);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreBinary::store(form_id_, s);
}

void auth_checkPaidAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1457889180);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreBinary::store(form_id_, s);
}

void auth_checkPaidAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.checkPaidAuth");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("form_id", form_id_);
    s.store_class_end();
  }
}

auth_checkPaidAuth::ReturnType auth_checkPaidAuth::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

auth_checkRecoveryPassword::auth_checkRecoveryPassword(string const &code_)
  : code_(code_)
{}

const std::int32_t auth_checkRecoveryPassword::ID;

void auth_checkRecoveryPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(221691769);
  TlStoreString::store(code_, s);
}

void auth_checkRecoveryPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(221691769);
  TlStoreString::store(code_, s);
}

void auth_checkRecoveryPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.checkRecoveryPassword");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

auth_checkRecoveryPassword::ReturnType auth_checkRecoveryPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_dropTempAuthKeys::auth_dropTempAuthKeys(array<int64> &&except_auth_keys_)
  : except_auth_keys_(std::move(except_auth_keys_))
{}

const std::int32_t auth_dropTempAuthKeys::ID;

void auth_dropTempAuthKeys::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1907842680);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(except_auth_keys_, s);
}

void auth_dropTempAuthKeys::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1907842680);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(except_auth_keys_, s);
}

void auth_dropTempAuthKeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.dropTempAuthKeys");
    { s.store_vector_begin("except_auth_keys", except_auth_keys_.size()); for (const auto &_value : except_auth_keys_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

auth_dropTempAuthKeys::ReturnType auth_dropTempAuthKeys::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_finishFirebasePnvLogin::auth_finishFirebasePnvLogin(string const &google_token_)
  : google_token_(google_token_)
{}

const std::int32_t auth_finishFirebasePnvLogin::ID;

void auth_finishFirebasePnvLogin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(746916172);
  TlStoreString::store(google_token_, s);
}

void auth_finishFirebasePnvLogin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(746916172);
  TlStoreString::store(google_token_, s);
}

void auth_finishFirebasePnvLogin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.finishFirebasePnvLogin");
    s.store_field("google_token", "[REDACTED]");
    s.store_class_end();
  }
}

auth_finishFirebasePnvLogin::ReturnType auth_finishFirebasePnvLogin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

auth_importLoginToken::auth_importLoginToken(bytes &&token_)
  : token_(std::move(token_))
{}

const std::int32_t auth_importLoginToken::ID;

void auth_importLoginToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1783866140);
  TlStoreString::store(token_, s);
}

void auth_importLoginToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1783866140);
  TlStoreString::store(token_, s);
}

void auth_importLoginToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.importLoginToken");
    s.store_field("token", "[REDACTED]");
    s.store_class_end();
  }
}

auth_importLoginToken::ReturnType auth_importLoginToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_LoginToken>::parse(p);
#undef FAIL
}

const std::int32_t auth_logOut::ID;

void auth_logOut::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1047706137);
}

void auth_logOut::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1047706137);
}

void auth_logOut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.logOut");
    s.store_class_end();
  }
}

auth_logOut::ReturnType auth_logOut::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<auth_loggedOut>, -1012759713>::parse(p);
#undef FAIL
}

const std::int32_t auth_resetAuthorizations::ID;

void auth_resetAuthorizations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1616179942);
}

void auth_resetAuthorizations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1616179942);
}

void auth_resetAuthorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.resetAuthorizations");
    s.store_class_end();
  }
}

auth_resetAuthorizations::ReturnType auth_resetAuthorizations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_answerWebhookJSONQuery::bots_answerWebhookJSONQuery(int64 query_id_, object_ptr<dataJSON> &&data_)
  : query_id_(query_id_)
  , data_(std::move(data_))
{}

const std::int32_t bots_answerWebhookJSONQuery::ID;

void bots_answerWebhookJSONQuery::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-434028723);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(data_, s);
}

void bots_answerWebhookJSONQuery::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-434028723);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(data_, s);
}

void bots_answerWebhookJSONQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.answerWebhookJSONQuery");
    s.store_field("query_id", query_id_);
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_class_end();
  }
}

bots_answerWebhookJSONQuery::ReturnType bots_answerWebhookJSONQuery::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_getPreviewMedias::bots_getPreviewMedias(object_ptr<InputUser> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t bots_getPreviewMedias::ID;

void bots_getPreviewMedias::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1566222003);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_getPreviewMedias::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1566222003);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_getPreviewMedias::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getPreviewMedias");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

bots_getPreviewMedias::ReturnType bots_getPreviewMedias::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botPreviewMedia>, 602479523>>, 481674261>::parse(p);
#undef FAIL
}

bots_setBotGroupDefaultAdminRights::bots_setBotGroupDefaultAdminRights(object_ptr<chatAdminRights> &&admin_rights_)
  : admin_rights_(std::move(admin_rights_))
{}

const std::int32_t bots_setBotGroupDefaultAdminRights::ID;

void bots_setBotGroupDefaultAdminRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1839281686);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
}

void bots_setBotGroupDefaultAdminRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1839281686);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
}

void bots_setBotGroupDefaultAdminRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setBotGroupDefaultAdminRights");
    s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get()));
    s.store_class_end();
  }
}

bots_setBotGroupDefaultAdminRights::ReturnType bots_setBotGroupDefaultAdminRights::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_updateUserEmojiStatus::bots_updateUserEmojiStatus(object_ptr<InputUser> &&user_id_, object_ptr<EmojiStatus> &&emoji_status_)
  : user_id_(std::move(user_id_))
  , emoji_status_(std::move(emoji_status_))
{}

const std::int32_t bots_updateUserEmojiStatus::ID;

void bots_updateUserEmojiStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-308334395);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void bots_updateUserEmojiStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-308334395);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void bots_updateUserEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.updateUserEmojiStatus");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

bots_updateUserEmojiStatus::ReturnType bots_updateUserEmojiStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_deleteParticipantHistory::channels_deleteParticipantHistory(object_ptr<InputChannel> &&channel_, object_ptr<InputPeer> &&participant_)
  : channel_(std::move(channel_))
  , participant_(std::move(participant_))
{}

const std::int32_t channels_deleteParticipantHistory::ID;

void channels_deleteParticipantHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(913655003);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void channels_deleteParticipantHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(913655003);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void channels_deleteParticipantHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.deleteParticipantHistory");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

channels_deleteParticipantHistory::ReturnType channels_deleteParticipantHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

channels_editTitle::channels_editTitle(object_ptr<InputChannel> &&channel_, string const &title_)
  : channel_(std::move(channel_))
  , title_(title_)
{}

const std::int32_t channels_editTitle::ID;

void channels_editTitle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1450044624);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(title_, s);
}

void channels_editTitle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1450044624);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(title_, s);
}

void channels_editTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.editTitle");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

channels_editTitle::ReturnType channels_editTitle::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_getMessages::channels_getMessages(object_ptr<InputChannel> &&channel_, array<object_ptr<InputMessage>> &&id_)
  : channel_(std::move(channel_))
  , id_(std::move(id_))
{}

const std::int32_t channels_getMessages::ID;

void channels_getMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1383294429);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void channels_getMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1383294429);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void channels_getMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getMessages");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_getMessages::ReturnType channels_getMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

channels_getParticipants::channels_getParticipants(object_ptr<InputChannel> &&channel_, object_ptr<ChannelParticipantsFilter> &&filter_, int32 offset_, int32 limit_, int64 hash_)
  : channel_(std::move(channel_))
  , filter_(std::move(filter_))
  , offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t channels_getParticipants::ID;

void channels_getParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2010044880);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void channels_getParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2010044880);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void channels_getParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getParticipants");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

channels_getParticipants::ReturnType channels_getParticipants::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<channels_ChannelParticipants>::parse(p);
#undef FAIL
}

chatlists_checkChatlistInvite::chatlists_checkChatlistInvite(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t chatlists_checkChatlistInvite::ID;

void chatlists_checkChatlistInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1103171583);
  TlStoreString::store(slug_, s);
}

void chatlists_checkChatlistInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1103171583);
  TlStoreString::store(slug_, s);
}

void chatlists_checkChatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.checkChatlistInvite");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

chatlists_checkChatlistInvite::ReturnType chatlists_checkChatlistInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<chatlists_ChatlistInvite>::parse(p);
#undef FAIL
}

chatlists_getExportedInvites::chatlists_getExportedInvites(object_ptr<inputChatlistDialogFilter> &&chatlist_)
  : chatlist_(std::move(chatlist_))
{}

const std::int32_t chatlists_getExportedInvites::ID;

void chatlists_getExportedInvites::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-838608253);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getExportedInvites::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-838608253);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getExportedInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.getExportedInvites");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_class_end();
  }
}

chatlists_getExportedInvites::ReturnType chatlists_getExportedInvites::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<chatlists_exportedInvites>, 279670215>::parse(p);
#undef FAIL
}

chatlists_hideChatlistUpdates::chatlists_hideChatlistUpdates(object_ptr<inputChatlistDialogFilter> &&chatlist_)
  : chatlist_(std::move(chatlist_))
{}

const std::int32_t chatlists_hideChatlistUpdates::ID;

void chatlists_hideChatlistUpdates::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1726252795);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_hideChatlistUpdates::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1726252795);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_hideChatlistUpdates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.hideChatlistUpdates");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_class_end();
  }
}

chatlists_hideChatlistUpdates::ReturnType chatlists_hideChatlistUpdates::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

communities_getPeerLinkRequests::communities_getPeerLinkRequests(object_ptr<InputChannel> &&community_, string const &offset_, int32 limit_)
  : community_(std::move(community_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t communities_getPeerLinkRequests::ID;

void communities_getPeerLinkRequests::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1820904636);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void communities_getPeerLinkRequests::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1820904636);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void communities_getPeerLinkRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities.getPeerLinkRequests");
    s.store_object_field("community", static_cast<const BaseObject *>(community_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

communities_getPeerLinkRequests::ReturnType communities_getPeerLinkRequests::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<communities_peerLinkRequests>, 574926765>::parse(p);
#undef FAIL
}

communities_toggleAllPeerLinkRequestApproval::communities_toggleAllPeerLinkRequestApproval(int32 flags_, bool reject_, object_ptr<InputChannel> &&community_)
  : flags_(flags_)
  , reject_(reject_)
  , community_(std::move(community_))
{}

const std::int32_t communities_toggleAllPeerLinkRequestApproval::ID;

void communities_toggleAllPeerLinkRequestApproval::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1075585731);
  TlStoreBinary::store((var0 = flags_ | (reject_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
}

void communities_toggleAllPeerLinkRequestApproval::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1075585731);
  TlStoreBinary::store((var0 = flags_ | (reject_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
}

void communities_toggleAllPeerLinkRequestApproval::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities.toggleAllPeerLinkRequestApproval");
    s.store_field("flags", (var0 = flags_ | (reject_ << 0)));
    if (var0 & 1) { s.store_field("reject", true); }
    s.store_object_field("community", static_cast<const BaseObject *>(community_.get()));
    s.store_class_end();
  }
}

communities_toggleAllPeerLinkRequestApproval::ReturnType communities_toggleAllPeerLinkRequestApproval::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

contacts_blockFromReplies::contacts_blockFromReplies(int32 flags_, bool delete_message_, bool delete_history_, bool report_spam_, int32 msg_id_)
  : flags_(flags_)
  , delete_message_(delete_message_)
  , delete_history_(delete_history_)
  , report_spam_(report_spam_)
  , msg_id_(msg_id_)
{}

const std::int32_t contacts_blockFromReplies::ID;

void contacts_blockFromReplies::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(698914348);
  TlStoreBinary::store((var0 = flags_ | (delete_message_ << 0) | (delete_history_ << 1) | (report_spam_ << 2)), s);
  TlStoreBinary::store(msg_id_, s);
}

void contacts_blockFromReplies::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(698914348);
  TlStoreBinary::store((var0 = flags_ | (delete_message_ << 0) | (delete_history_ << 1) | (report_spam_ << 2)), s);
  TlStoreBinary::store(msg_id_, s);
}

void contacts_blockFromReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.blockFromReplies");
    s.store_field("flags", (var0 = flags_ | (delete_message_ << 0) | (delete_history_ << 1) | (report_spam_ << 2)));
    if (var0 & 1) { s.store_field("delete_message", true); }
    if (var0 & 2) { s.store_field("delete_history", true); }
    if (var0 & 4) { s.store_field("report_spam", true); }
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

contacts_blockFromReplies::ReturnType contacts_blockFromReplies::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

ephemeral_editMessage::ephemeral_editMessage(int32 flags_, bool invert_media_, bool welcome_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&receiver_id_, int32 id_, string const &message_, object_ptr<InputMedia> &&media_, array<object_ptr<MessageEntity>> &&entities_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputRichMessage> &&rich_message_)
  : flags_(flags_)
  , invert_media_(invert_media_)
  , welcome_(welcome_)
  , peer_(std::move(peer_))
  , receiver_id_(std::move(receiver_id_))
  , id_(id_)
  , message_(message_)
  , media_(std::move(media_))
  , entities_(std::move(entities_))
  , reply_markup_(std::move(reply_markup_))
  , rich_message_(std::move(rich_message_))
{}

const std::int32_t ephemeral_editMessage::ID;

void ephemeral_editMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-811830693);
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 5) | (welcome_ << 6) | ((peer_ != nullptr) << 7) | ((!message_.empty()) << 0) | ((media_ != nullptr) << 3) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2) | ((rich_message_ != nullptr) << 4)), s);
  if (var0 & 128) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(receiver_id_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(message_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
}

void ephemeral_editMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-811830693);
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 5) | (welcome_ << 6) | ((peer_ != nullptr) << 7) | ((!message_.empty()) << 0) | ((media_ != nullptr) << 3) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2) | ((rich_message_ != nullptr) << 4)), s);
  if (var0 & 128) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(receiver_id_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(message_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
}

void ephemeral_editMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeral.editMessage");
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 5) | (welcome_ << 6) | ((peer_ != nullptr) << 7) | ((!message_.empty()) << 0) | ((media_ != nullptr) << 3) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2) | ((rich_message_ != nullptr) << 4)));
    if (var0 & 32) { s.store_field("invert_media", true); }
    if (var0 & 64) { s.store_field("welcome", true); }
    if (var0 & 128) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("message", message_); }
    if (var0 & 8) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 16) { s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get())); }
    s.store_class_end();
  }
}

ephemeral_editMessage::ReturnType ephemeral_editMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

ephemeral_getWelcomeMessages::ephemeral_getWelcomeMessages(object_ptr<InputPeer> &&peer_, int64 hash_)
  : peer_(std::move(peer_))
  , hash_(hash_)
{}

const std::int32_t ephemeral_getWelcomeMessages::ID;

void ephemeral_getWelcomeMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-610614899);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void ephemeral_getWelcomeMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-610614899);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void ephemeral_getWelcomeMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeral.getWelcomeMessages");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

ephemeral_getWelcomeMessages::ReturnType ephemeral_getWelcomeMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<ephemeral_WelcomeMessages>::parse(p);
#undef FAIL
}

langpack_getLanguage::langpack_getLanguage(string const &lang_pack_, string const &lang_code_)
  : lang_pack_(lang_pack_)
  , lang_code_(lang_code_)
{}

const std::int32_t langpack_getLanguage::ID;

void langpack_getLanguage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1784243458);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
}

void langpack_getLanguage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1784243458);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
}

void langpack_getLanguage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langpack.getLanguage");
    s.store_field("lang_pack", lang_pack_);
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

langpack_getLanguage::ReturnType langpack_getLanguage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<langPackLanguage>, -288727837>::parse(p);
#undef FAIL
}

langpack_getStrings::langpack_getStrings(string const &lang_pack_, string const &lang_code_, array<string> &&keys_)
  : lang_pack_(lang_pack_)
  , lang_code_(lang_code_)
  , keys_(std::move(keys_))
{}

const std::int32_t langpack_getStrings::ID;

void langpack_getStrings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-269862909);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(keys_, s);
}

void langpack_getStrings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-269862909);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(keys_, s);
}

void langpack_getStrings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langpack.getStrings");
    s.store_field("lang_pack", lang_pack_);
    s.store_field("lang_code", lang_code_);
    { s.store_vector_begin("keys", keys_.size()); for (const auto &_value : keys_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

langpack_getStrings::ReturnType langpack_getStrings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<LangPackString>>, 481674261>::parse(p);
#undef FAIL
}

messages_editInlineBotMessage::messages_editInlineBotMessage(int32 flags_, bool no_webpage_, bool invert_media_, object_ptr<InputBotInlineMessageID> &&id_, string const &message_, object_ptr<InputMedia> &&media_, object_ptr<ReplyMarkup> &&reply_markup_, array<object_ptr<MessageEntity>> &&entities_, object_ptr<InputRichMessage> &&rich_message_)
  : flags_(flags_)
  , no_webpage_(no_webpage_)
  , invert_media_(invert_media_)
  , id_(std::move(id_))
  , message_(message_)
  , media_(std::move(media_))
  , reply_markup_(std::move(reply_markup_))
  , entities_(std::move(entities_))
  , rich_message_(std::move(rich_message_))
{}

const std::int32_t messages_editInlineBotMessage::ID;

void messages_editInlineBotMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1541162159);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16) | ((!message_.empty()) << 11) | ((media_ != nullptr) << 14) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((rich_message_ != nullptr) << 23)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 2048) { TlStoreString::store(message_, s); }
  if (var0 & 16384) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 8388608) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
}

void messages_editInlineBotMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1541162159);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16) | ((!message_.empty()) << 11) | ((media_ != nullptr) << 14) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((rich_message_ != nullptr) << 23)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 2048) { TlStoreString::store(message_, s); }
  if (var0 & 16384) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 8388608) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
}

void messages_editInlineBotMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editInlineBotMessage");
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16) | ((!message_.empty()) << 11) | ((media_ != nullptr) << 14) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((rich_message_ != nullptr) << 23)));
    if (var0 & 2) { s.store_field("no_webpage", true); }
    if (var0 & 65536) { s.store_field("invert_media", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    if (var0 & 2048) { s.store_field("message", message_); }
    if (var0 & 16384) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 8388608) { s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get())); }
    s.store_class_end();
  }
}

messages_editInlineBotMessage::ReturnType messages_editInlineBotMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t messages_getDefaultHistoryTTL::ID;

void messages_getDefaultHistoryTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1703637384);
}

void messages_getDefaultHistoryTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1703637384);
}

void messages_getDefaultHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDefaultHistoryTTL");
    s.store_class_end();
  }
}

messages_getDefaultHistoryTTL::ReturnType messages_getDefaultHistoryTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<defaultHistoryTTL>, 1135897376>::parse(p);
#undef FAIL
}

messages_getForumTopicsByID::messages_getForumTopicsByID(object_ptr<InputPeer> &&peer_, array<int32> &&topics_)
  : peer_(std::move(peer_))
  , topics_(std::move(topics_))
{}

const std::int32_t messages_getForumTopicsByID::ID;

void messages_getForumTopicsByID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1358280184);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(topics_, s);
}

void messages_getForumTopicsByID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1358280184);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(topics_, s);
}

void messages_getForumTopicsByID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getForumTopicsByID");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getForumTopicsByID::ReturnType messages_getForumTopicsByID::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_forumTopics>, 913709011>::parse(p);
#undef FAIL
}

messages_getHistory::messages_getHistory(object_ptr<InputPeer> &&peer_, int32 offset_id_, int32 offset_date_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_, int64 hash_)
  : peer_(std::move(peer_))
  , offset_id_(offset_id_)
  , offset_date_(offset_date_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
  , hash_(hash_)
{}

const std::int32_t messages_getHistory::ID;

void messages_getHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1143203525);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1143203525);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getHistory");
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

messages_getHistory::ReturnType messages_getHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getPeerDialogs::messages_getPeerDialogs(array<object_ptr<InputDialogPeer>> &&peers_)
  : peers_(std::move(peers_))
{}

const std::int32_t messages_getPeerDialogs::ID;

void messages_getPeerDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-462373635);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void messages_getPeerDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-462373635);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void messages_getPeerDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPeerDialogs");
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getPeerDialogs::ReturnType messages_getPeerDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_peerDialogs>, 863093588>::parse(p);
#undef FAIL
}

const std::int32_t messages_getPinnedSavedDialogs::ID;

void messages_getPinnedSavedDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-700607264);
}

void messages_getPinnedSavedDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-700607264);
}

void messages_getPinnedSavedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPinnedSavedDialogs");
    s.store_class_end();
  }
}

messages_getPinnedSavedDialogs::ReturnType messages_getPinnedSavedDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SavedDialogs>::parse(p);
#undef FAIL
}

messages_getQuickReplyMessages::messages_getQuickReplyMessages(int32 flags_, int32 shortcut_id_, array<int32> &&id_, int64 hash_)
  : flags_(flags_)
  , shortcut_id_(shortcut_id_)
  , id_(std::move(id_))
  , hash_(hash_)
{}

const std::int32_t messages_getQuickReplyMessages::ID;

void messages_getQuickReplyMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1801153085);
  TlStoreBinary::store((var0 = flags_ | ((!id_.empty()) << 0)), s);
  TlStoreBinary::store(shortcut_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s); }
  TlStoreBinary::store(hash_, s);
}

void messages_getQuickReplyMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1801153085);
  TlStoreBinary::store((var0 = flags_ | ((!id_.empty()) << 0)), s);
  TlStoreBinary::store(shortcut_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s); }
  TlStoreBinary::store(hash_, s);
}

void messages_getQuickReplyMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getQuickReplyMessages");
    s.store_field("flags", (var0 = flags_ | ((!id_.empty()) << 0)));
    s.store_field("shortcut_id", shortcut_id_);
    if (var0 & 1) { { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getQuickReplyMessages::ReturnType messages_getQuickReplyMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getSavedDialogsByID::messages_getSavedDialogsByID(int32 flags_, object_ptr<InputPeer> &&parent_peer_, array<object_ptr<InputPeer>> &&ids_)
  : flags_(flags_)
  , parent_peer_(std::move(parent_peer_))
  , ids_(std::move(ids_))
{}

const std::int32_t messages_getSavedDialogsByID::ID;

void messages_getSavedDialogsByID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1869585558);
  TlStoreBinary::store((var0 = flags_ | ((parent_peer_ != nullptr) << 1)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(ids_, s);
}

void messages_getSavedDialogsByID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1869585558);
  TlStoreBinary::store((var0 = flags_ | ((parent_peer_ != nullptr) << 1)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(ids_, s);
}

void messages_getSavedDialogsByID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSavedDialogsByID");
    s.store_field("flags", (var0 = flags_ | ((parent_peer_ != nullptr) << 1)));
    if (var0 & 2) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    { s.store_vector_begin("ids", ids_.size()); for (const auto &_value : ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getSavedDialogsByID::ReturnType messages_getSavedDialogsByID::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SavedDialogs>::parse(p);
#undef FAIL
}

messages_getSearchCounters::messages_getSearchCounters(int32 flags_, object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&saved_peer_id_, int32 top_msg_id_, array<object_ptr<MessagesFilter>> &&filters_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , saved_peer_id_(std::move(saved_peer_id_))
  , top_msg_id_(top_msg_id_)
  , filters_(std::move(filters_))
{}

const std::int32_t messages_getSearchCounters::ID;

void messages_getSearchCounters::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(465367808);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(filters_, s);
}

void messages_getSearchCounters::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(465367808);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(filters_, s);
}

void messages_getSearchCounters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSearchCounters");
    s.store_field("flags", (var0 = flags_ | ((saved_peer_id_ != nullptr) << 2)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 4) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    { s.store_vector_begin("filters", filters_.size()); for (const auto &_value : filters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getSearchCounters::ReturnType messages_getSearchCounters::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messages_searchCounter>, -398136321>>, 481674261>::parse(p);
#undef FAIL
}

messages_getSearchResultsPositions::messages_getSearchResultsPositions(int32 flags_, object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&saved_peer_id_, object_ptr<MessagesFilter> &&filter_, int32 offset_id_, int32 limit_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , saved_peer_id_(std::move(saved_peer_id_))
  , filter_(std::move(filter_))
  , offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t messages_getSearchResultsPositions::ID;

void messages_getSearchResultsPositions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1669386480);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getSearchResultsPositions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1669386480);
  TlStoreBinary::store((var0 = flags_ | ((saved_peer_id_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getSearchResultsPositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSearchResultsPositions");
    s.store_field("flags", (var0 = flags_ | ((saved_peer_id_ != nullptr) << 2)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 4) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getSearchResultsPositions::ReturnType messages_getSearchResultsPositions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_searchResultsPositions>, 1404185519>::parse(p);
#undef FAIL
}

messages_getSponsoredMessages::messages_getSponsoredMessages(int32 flags_, object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_getSponsoredMessages::ID;

void messages_getSponsoredMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1030547536);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(msg_id_, s); }
}

void messages_getSponsoredMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1030547536);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(msg_id_, s); }
}

void messages_getSponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSponsoredMessages");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("msg_id", msg_id_); }
    s.store_class_end();
  }
}

messages_getSponsoredMessages::ReturnType messages_getSponsoredMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SponsoredMessages>::parse(p);
#undef FAIL
}

messages_getWebPagePreview::messages_getWebPagePreview(int32 flags_, string const &message_, array<object_ptr<MessageEntity>> &&entities_)
  : flags_(flags_)
  , message_(message_)
  , entities_(std::move(entities_))
{}

const std::int32_t messages_getWebPagePreview::ID;

void messages_getWebPagePreview::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1460498287);
  TlStoreBinary::store((var0 = flags_ | ((!entities_.empty()) << 3)), s);
  TlStoreString::store(message_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void messages_getWebPagePreview::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1460498287);
  TlStoreBinary::store((var0 = flags_ | ((!entities_.empty()) << 3)), s);
  TlStoreString::store(message_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void messages_getWebPagePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getWebPagePreview");
    s.store_field("flags", (var0 = flags_ | ((!entities_.empty()) << 3)));
    s.store_field("message", message_);
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messages_getWebPagePreview::ReturnType messages_getWebPagePreview::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_webPagePreview>, -1936029524>::parse(p);
#undef FAIL
}

messages_migrateChat::messages_migrateChat(int64 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t messages_migrateChat::ID;

void messages_migrateChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1568189671);
  TlStoreBinary::store(chat_id_, s);
}

void messages_migrateChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1568189671);
  TlStoreBinary::store(chat_id_, s);
}

void messages_migrateChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.migrateChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

messages_migrateChat::ReturnType messages_migrateChat::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_receivedMessages::messages_receivedMessages(int32 max_id_)
  : max_id_(max_id_)
{}

const std::int32_t messages_receivedMessages::ID;

void messages_receivedMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(94983360);
  TlStoreBinary::store(max_id_, s);
}

void messages_receivedMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(94983360);
  TlStoreBinary::store(max_id_, s);
}

void messages_receivedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.receivedMessages");
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

messages_receivedMessages::ReturnType messages_receivedMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<receivedNotifyMessage>, -1551583367>>, 481674261>::parse(p);
#undef FAIL
}

messages_requestSimpleWebView::messages_requestSimpleWebView(int32 flags_, bool from_switch_webview_, bool from_side_menu_, bool compact_, bool fullscreen_, object_ptr<InputUser> &&bot_, string const &url_, string const &start_param_, object_ptr<dataJSON> &&theme_params_, string const &platform_)
  : flags_(flags_)
  , from_switch_webview_(from_switch_webview_)
  , from_side_menu_(from_side_menu_)
  , compact_(compact_)
  , fullscreen_(fullscreen_)
  , bot_(std::move(bot_))
  , url_(url_)
  , start_param_(start_param_)
  , theme_params_(std::move(theme_params_))
  , platform_(platform_)
{}

const std::int32_t messages_requestSimpleWebView::ID;

void messages_requestSimpleWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1094336115);
  TlStoreBinary::store((var0 = flags_ | (from_switch_webview_ << 1) | (from_side_menu_ << 2) | (compact_ << 7) | (fullscreen_ << 8) | ((!url_.empty()) << 3) | ((!start_param_.empty()) << 4) | ((theme_params_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 8) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreString::store(start_param_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestSimpleWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1094336115);
  TlStoreBinary::store((var0 = flags_ | (from_switch_webview_ << 1) | (from_side_menu_ << 2) | (compact_ << 7) | (fullscreen_ << 8) | ((!url_.empty()) << 3) | ((!start_param_.empty()) << 4) | ((theme_params_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 8) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreString::store(start_param_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestSimpleWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestSimpleWebView");
    s.store_field("flags", (var0 = flags_ | (from_switch_webview_ << 1) | (from_side_menu_ << 2) | (compact_ << 7) | (fullscreen_ << 8) | ((!url_.empty()) << 3) | ((!start_param_.empty()) << 4) | ((theme_params_ != nullptr) << 0)));
    if (var0 & 2) { s.store_field("from_switch_webview", true); }
    if (var0 & 4) { s.store_field("from_side_menu", true); }
    if (var0 & 128) { s.store_field("compact", true); }
    if (var0 & 256) { s.store_field("fullscreen", true); }
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    if (var0 & 8) { s.store_field("url", url_); }
    if (var0 & 16) { s.store_field("start_param", start_param_); }
    if (var0 & 1) { s.store_object_field("theme_params", static_cast<const BaseObject *>(theme_params_.get())); }
    s.store_field("platform", platform_);
    s.store_class_end();
  }
}

messages_requestSimpleWebView::ReturnType messages_requestSimpleWebView::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<webViewResultUrl>, 1294139288>::parse(p);
#undef FAIL
}

messages_sendEncryptedFile::messages_sendEncryptedFile(int32 flags_, bool silent_, object_ptr<inputEncryptedChat> &&peer_, int64 random_id_, bytes &&data_, object_ptr<InputEncryptedFile> &&file_)
  : flags_(flags_)
  , silent_(silent_)
  , peer_(std::move(peer_))
  , random_id_(random_id_)
  , data_(std::move(data_))
  , file_(std::move(file_))
{}

const std::int32_t messages_sendEncryptedFile::ID;

void messages_sendEncryptedFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1431914525);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0)), s);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void messages_sendEncryptedFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1431914525);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0)), s);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void messages_sendEncryptedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendEncryptedFile");
    s.store_field("flags", (var0 = flags_ | (silent_ << 0)));
    if (var0 & 1) { s.store_field("silent", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("random_id", random_id_);
    s.store_bytes_field("data", data_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

messages_sendEncryptedFile::ReturnType messages_sendEncryptedFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SentEncryptedMessage>::parse(p);
#undef FAIL
}

messages_sendPaidReaction::messages_sendPaidReaction(int32 flags_, object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 count_, int64 random_id_, object_ptr<PaidReactionPrivacy> &&private_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , count_(count_)
  , random_id_(random_id_)
  , private_(std::move(private_))
{}

const std::int32_t messages_sendPaidReaction::ID;

void messages_sendPaidReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1488702288);
  TlStoreBinary::store((var0 = flags_ | ((private_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(count_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(private_, s); }
}

void messages_sendPaidReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1488702288);
  TlStoreBinary::store((var0 = flags_ | ((private_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(count_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(private_, s); }
}

void messages_sendPaidReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendPaidReaction");
    s.store_field("flags", (var0 = flags_ | ((private_ != nullptr) << 0)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("count", count_);
    s.store_field("random_id", random_id_);
    if (var0 & 1) { s.store_object_field("private", static_cast<const BaseObject *>(private_.get())); }
    s.store_class_end();
  }
}

messages_sendPaidReaction::ReturnType messages_sendPaidReaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_sendQuickReplyMessages::messages_sendQuickReplyMessages(object_ptr<InputPeer> &&peer_, int32 shortcut_id_, array<int32> &&id_, array<int64> &&random_id_)
  : peer_(std::move(peer_))
  , shortcut_id_(shortcut_id_)
  , id_(std::move(id_))
  , random_id_(std::move(random_id_))
{}

const std::int32_t messages_sendQuickReplyMessages::ID;

void messages_sendQuickReplyMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1819610593);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(random_id_, s);
}

void messages_sendQuickReplyMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1819610593);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(random_id_, s);
}

void messages_sendQuickReplyMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendQuickReplyMessages");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("shortcut_id", shortcut_id_);
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("random_id", random_id_.size()); for (const auto &_value : random_id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_sendQuickReplyMessages::ReturnType messages_sendQuickReplyMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_sendWebViewResultMessage::messages_sendWebViewResultMessage(string const &bot_query_id_, object_ptr<InputBotInlineResult> &&result_)
  : bot_query_id_(bot_query_id_)
  , result_(std::move(result_))
{}

const std::int32_t messages_sendWebViewResultMessage::ID;

void messages_sendWebViewResultMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(172168437);
  TlStoreString::store(bot_query_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
}

void messages_sendWebViewResultMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(172168437);
  TlStoreString::store(bot_query_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
}

void messages_sendWebViewResultMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendWebViewResultMessage");
    s.store_field("bot_query_id", bot_query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_class_end();
  }
}

messages_sendWebViewResultMessage::ReturnType messages_sendWebViewResultMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<webViewMessageSent>, 211046684>::parse(p);
#undef FAIL
}

messages_setBotWidgetQueryAnswer::messages_setBotWidgetQueryAnswer(int32 flags_, int64 query_id_, string const &result_)
  : flags_(flags_)
  , query_id_(query_id_)
  , result_(result_)
{}

const std::int32_t messages_setBotWidgetQueryAnswer::ID;

void messages_setBotWidgetQueryAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-120722326);
  TlStoreBinary::store((var0 = flags_ | ((!result_.empty()) << 0)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(result_, s); }
}

void messages_setBotWidgetQueryAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-120722326);
  TlStoreBinary::store((var0 = flags_ | ((!result_.empty()) << 0)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(result_, s); }
}

void messages_setBotWidgetQueryAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setBotWidgetQueryAnswer");
    s.store_field("flags", (var0 = flags_ | ((!result_.empty()) << 0)));
    s.store_field("query_id", query_id_);
    if (var0 & 1) { s.store_field("result", result_); }
    s.store_class_end();
  }
}

messages_setBotWidgetQueryAnswer::ReturnType messages_setBotWidgetQueryAnswer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_setChatWallPaper::messages_setChatWallPaper(int32 flags_, bool for_both_, bool revert_, object_ptr<InputPeer> &&peer_, object_ptr<InputWallPaper> &&wallpaper_, object_ptr<wallPaperSettings> &&settings_, int32 id_)
  : flags_(flags_)
  , for_both_(for_both_)
  , revert_(revert_)
  , peer_(std::move(peer_))
  , wallpaper_(std::move(wallpaper_))
  , settings_(std::move(settings_))
  , id_(id_)
{}

const std::int32_t messages_setChatWallPaper::ID;

void messages_setChatWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1879389471);
  TlStoreBinary::store((var0 = flags_ | (for_both_ << 3) | (revert_ << 4) | ((wallpaper_ != nullptr) << 0) | ((settings_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
  if (var0 & 2) { TlStoreBinary::store(id_, s); }
}

void messages_setChatWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1879389471);
  TlStoreBinary::store((var0 = flags_ | (for_both_ << 3) | (revert_ << 4) | ((wallpaper_ != nullptr) << 0) | ((settings_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
  if (var0 & 2) { TlStoreBinary::store(id_, s); }
}

void messages_setChatWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setChatWallPaper");
    s.store_field("flags", (var0 = flags_ | (for_both_ << 3) | (revert_ << 4) | ((wallpaper_ != nullptr) << 0) | ((settings_ != nullptr) << 2)));
    if (var0 & 8) { s.store_field("for_both", true); }
    if (var0 & 16) { s.store_field("revert", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    if (var0 & 4) { s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get())); }
    if (var0 & 2) { s.store_field("id", id_); }
    s.store_class_end();
  }
}

messages_setChatWallPaper::ReturnType messages_setChatWallPaper::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setShareTheme::messages_setShareTheme(object_ptr<InputPeer> &&peer_, object_ptr<ShareTheme> &&theme_)
  : peer_(std::move(peer_))
  , theme_(std::move(theme_))
{}

const std::int32_t messages_setShareTheme::ID;

void messages_setShareTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1770691354);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
}

void messages_setShareTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1770691354);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
}

void messages_setShareTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setShareTheme");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

messages_setShareTheme::ReturnType messages_setShareTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_startBot::messages_startBot(object_ptr<InputUser> &&bot_, object_ptr<InputPeer> &&peer_, int64 random_id_, string const &start_param_)
  : bot_(std::move(bot_))
  , peer_(std::move(peer_))
  , random_id_(random_id_)
  , start_param_(start_param_)
{}

const std::int32_t messages_startBot::ID;

void messages_startBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-421563528);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(start_param_, s);
}

void messages_startBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-421563528);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(start_param_, s);
}

void messages_startBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.startBot");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("random_id", random_id_);
    s.store_field("start_param", start_param_);
    s.store_class_end();
  }
}

messages_startBot::ReturnType messages_startBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_toggleNoForwards::messages_toggleNoForwards(int32 flags_, object_ptr<InputPeer> &&peer_, bool enabled_, int32 request_msg_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , enabled_(enabled_)
  , request_msg_id_(request_msg_id_)
{}

const std::int32_t messages_toggleNoForwards::ID;

void messages_toggleNoForwards::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1308091851);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(enabled_, s);
  if (var0 & 1) { TlStoreBinary::store(request_msg_id_, s); }
}

void messages_toggleNoForwards::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1308091851);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(enabled_, s);
  if (var0 & 1) { TlStoreBinary::store(request_msg_id_, s); }
}

void messages_toggleNoForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleNoForwards");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("enabled", enabled_);
    if (var0 & 1) { s.store_field("request_msg_id", request_msg_id_); }
    s.store_class_end();
  }
}

messages_toggleNoForwards::ReturnType messages_toggleNoForwards::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_toggleStickerSets::messages_toggleStickerSets(int32 flags_, bool uninstall_, bool archive_, bool unarchive_, array<object_ptr<InputStickerSet>> &&stickersets_)
  : flags_(flags_)
  , uninstall_(uninstall_)
  , archive_(archive_)
  , unarchive_(unarchive_)
  , stickersets_(std::move(stickersets_))
{}

const std::int32_t messages_toggleStickerSets::ID;

void messages_toggleStickerSets::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1257951254);
  TlStoreBinary::store((var0 = flags_ | (uninstall_ << 0) | (archive_ << 1) | (unarchive_ << 2)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickersets_, s);
}

void messages_toggleStickerSets::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1257951254);
  TlStoreBinary::store((var0 = flags_ | (uninstall_ << 0) | (archive_ << 1) | (unarchive_ << 2)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickersets_, s);
}

void messages_toggleStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleStickerSets");
    s.store_field("flags", (var0 = flags_ | (uninstall_ << 0) | (archive_ << 1) | (unarchive_ << 2)));
    if (var0 & 1) { s.store_field("uninstall", true); }
    if (var0 & 2) { s.store_field("archive", true); }
    if (var0 & 4) { s.store_field("unarchive", true); }
    { s.store_vector_begin("stickersets", stickersets_.size()); for (const auto &_value : stickersets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_toggleStickerSets::ReturnType messages_toggleStickerSets::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_transcribeAudio::messages_transcribeAudio(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_transcribeAudio::ID;

void messages_transcribeAudio::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(647928393);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_transcribeAudio::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(647928393);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_transcribeAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.transcribeAudio");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

messages_transcribeAudio::ReturnType messages_transcribeAudio::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_transcribedAudio>, -809903785>::parse(p);
#undef FAIL
}

messages_transcribeAudioFile::messages_transcribeAudioFile(object_ptr<InputFile> &&file_)
  : file_(std::move(file_))
{}

const std::int32_t messages_transcribeAudioFile::ID;

void messages_transcribeAudioFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(120401655);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void messages_transcribeAudioFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(120401655);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void messages_transcribeAudioFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.transcribeAudioFile");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

messages_transcribeAudioFile::ReturnType messages_transcribeAudioFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_transcribedAudio>, -809903785>::parse(p);
#undef FAIL
}

messages_updatePinnedForumTopic::messages_updatePinnedForumTopic(object_ptr<InputPeer> &&peer_, int32 topic_id_, bool pinned_)
  : peer_(std::move(peer_))
  , topic_id_(topic_id_)
  , pinned_(pinned_)
{}

const std::int32_t messages_updatePinnedForumTopic::ID;

void messages_updatePinnedForumTopic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(392032849);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(topic_id_, s);
  TlStoreBool::store(pinned_, s);
}

void messages_updatePinnedForumTopic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(392032849);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(topic_id_, s);
  TlStoreBool::store(pinned_, s);
}

void messages_updatePinnedForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.updatePinnedForumTopic");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("topic_id", topic_id_);
    s.store_field("pinned", pinned_);
    s.store_class_end();
  }
}

messages_updatePinnedForumTopic::ReturnType messages_updatePinnedForumTopic::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_canPurchaseStore::payments_canPurchaseStore(object_ptr<InputStorePaymentPurpose> &&purpose_)
  : purpose_(std::move(purpose_))
{}

const std::int32_t payments_canPurchaseStore::ID;

void payments_canPurchaseStore::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1339842215);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_canPurchaseStore::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1339842215);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_canPurchaseStore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.canPurchaseStore");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

payments_canPurchaseStore::ReturnType payments_canPurchaseStore::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_checkGiftCode::payments_checkGiftCode(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t payments_checkGiftCode::ID;

void payments_checkGiftCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1907247935);
  TlStoreString::store(slug_, s);
}

void payments_checkGiftCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1907247935);
  TlStoreString::store(slug_, s);
}

void payments_checkGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.checkGiftCode");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

payments_checkGiftCode::ReturnType payments_checkGiftCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_checkedGiftCode>, -342343793>::parse(p);
#undef FAIL
}

payments_convertStarGift::payments_convertStarGift(object_ptr<InputSavedStarGift> &&stargift_)
  : stargift_(std::move(stargift_))
{}

const std::int32_t payments_convertStarGift::ID;

void payments_convertStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1958676331);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_convertStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1958676331);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_convertStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.convertStarGift");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

payments_convertStarGift::ReturnType payments_convertStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_getConnectedStarRefBot::payments_getConnectedStarRefBot(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&bot_)
  : peer_(std::move(peer_))
  , bot_(std::move(bot_))
{}

const std::int32_t payments_getConnectedStarRefBot::ID;

void payments_getConnectedStarRefBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1210476304);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void payments_getConnectedStarRefBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1210476304);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void payments_getConnectedStarRefBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getConnectedStarRefBot");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

payments_getConnectedStarRefBot::ReturnType payments_getConnectedStarRefBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_connectedStarRefBots>, -1730811363>::parse(p);
#undef FAIL
}

payments_getOnrampLimits::payments_getOnrampLimits(int32 flags_, string const &provider_, string const &crypto_currency_, string const &base_currency_, string const &payment_method_)
  : flags_(flags_)
  , provider_(provider_)
  , crypto_currency_(crypto_currency_)
  , base_currency_(base_currency_)
  , payment_method_(payment_method_)
{}

const std::int32_t payments_getOnrampLimits::ID;

void payments_getOnrampLimits::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2132258307);
  TlStoreBinary::store((var0 = flags_ | ((!payment_method_.empty()) << 0)), s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(crypto_currency_, s);
  TlStoreString::store(base_currency_, s);
  if (var0 & 1) { TlStoreString::store(payment_method_, s); }
}

void payments_getOnrampLimits::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2132258307);
  TlStoreBinary::store((var0 = flags_ | ((!payment_method_.empty()) << 0)), s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(crypto_currency_, s);
  TlStoreString::store(base_currency_, s);
  if (var0 & 1) { TlStoreString::store(payment_method_, s); }
}

void payments_getOnrampLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getOnrampLimits");
    s.store_field("flags", (var0 = flags_ | ((!payment_method_.empty()) << 0)));
    s.store_field("provider", provider_);
    s.store_field("crypto_currency", crypto_currency_);
    s.store_field("base_currency", base_currency_);
    if (var0 & 1) { s.store_field("payment_method", payment_method_); }
    s.store_class_end();
  }
}

payments_getOnrampLimits::ReturnType payments_getOnrampLimits::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<onrampLimits>, 2078435198>::parse(p);
#undef FAIL
}

payments_getStarGiftUpgradePreview::payments_getStarGiftUpgradePreview(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t payments_getStarGiftUpgradePreview::ID;

void payments_getStarGiftUpgradePreview::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1667580751);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftUpgradePreview::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1667580751);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftUpgradePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftUpgradePreview");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

payments_getStarGiftUpgradePreview::ReturnType payments_getStarGiftUpgradePreview::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftUpgradePreview>, 1038213101>::parse(p);
#undef FAIL
}

payments_getStarGifts::payments_getStarGifts(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t payments_getStarGifts::ID;

void payments_getStarGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1000983152);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1000983152);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGifts");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

payments_getStarGifts::ReturnType payments_getStarGifts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_StarGifts>::parse(p);
#undef FAIL
}

const std::int32_t payments_getStarsGiveawayOptions::ID;

void payments_getStarsGiveawayOptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1122042562);
}

void payments_getStarsGiveawayOptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1122042562);
}

void payments_getStarsGiveawayOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsGiveawayOptions");
    s.store_class_end();
  }
}

payments_getStarsGiveawayOptions::ReturnType payments_getStarsGiveawayOptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsGiveawayOption>, -1798404822>>, 481674261>::parse(p);
#undef FAIL
}

payments_getStarsRevenueWithdrawalUrl::payments_getStarsRevenueWithdrawalUrl(int32 flags_, bool ton_, object_ptr<InputPeer> &&peer_, int64 amount_, object_ptr<InputCheckPasswordSRP> &&password_)
  : flags_(flags_)
  , ton_(ton_)
  , peer_(std::move(peer_))
  , amount_(amount_)
  , password_(std::move(password_))
{}

const std::int32_t payments_getStarsRevenueWithdrawalUrl::ID;

void payments_getStarsRevenueWithdrawalUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(607378578);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreBinary::store(amount_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void payments_getStarsRevenueWithdrawalUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(607378578);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreBinary::store(amount_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void payments_getStarsRevenueWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsRevenueWithdrawalUrl");
    s.store_field("flags", (var0 = flags_ | (ton_ << 0)));
    if (var0 & 1) { s.store_field("ton", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_field("amount", amount_); }
    s.store_field("password", "[REDACTED]");
    s.store_class_end();
  }
}

payments_getStarsRevenueWithdrawalUrl::ReturnType payments_getStarsRevenueWithdrawalUrl::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsRevenueWithdrawalUrl>, 497778871>::parse(p);
#undef FAIL
}

payments_getStarsTransactionsByID::payments_getStarsTransactionsByID(int32 flags_, bool ton_, object_ptr<InputPeer> &&peer_, array<object_ptr<inputStarsTransaction>> &&id_)
  : flags_(flags_)
  , ton_(ton_)
  , peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t payments_getStarsTransactionsByID::ID;

void payments_getStarsTransactionsByID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(768218808);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 543876817>>, 481674261>::store(id_, s);
}

void payments_getStarsTransactionsByID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(768218808);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 543876817>>, 481674261>::store(id_, s);
}

void payments_getStarsTransactionsByID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsTransactionsByID");
    s.store_field("flags", (var0 = flags_ | (ton_ << 0)));
    if (var0 & 1) { s.store_field("ton", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_getStarsTransactionsByID::ReturnType payments_getStarsTransactionsByID::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsStatus>, 1822222573>::parse(p);
#undef FAIL
}

payments_getUniqueStarGift::payments_getUniqueStarGift(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t payments_getUniqueStarGift::ID;

void payments_getUniqueStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1583919758);
  TlStoreString::store(slug_, s);
}

void payments_getUniqueStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1583919758);
  TlStoreString::store(slug_, s);
}

void payments_getUniqueStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getUniqueStarGift");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

payments_getUniqueStarGift::ReturnType payments_getUniqueStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_uniqueStarGift>, 1097619176>::parse(p);
#undef FAIL
}

phone_declineConferenceCallInvite::phone_declineConferenceCallInvite(int32 msg_id_)
  : msg_id_(msg_id_)
{}

const std::int32_t phone_declineConferenceCallInvite::ID;

void phone_declineConferenceCallInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1011325297);
  TlStoreBinary::store(msg_id_, s);
}

void phone_declineConferenceCallInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1011325297);
  TlStoreBinary::store(msg_id_, s);
}

void phone_declineConferenceCallInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.declineConferenceCallInvite");
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

phone_declineConferenceCallInvite::ReturnType phone_declineConferenceCallInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_deleteGroupCallMessages::phone_deleteGroupCallMessages(int32 flags_, bool report_spam_, object_ptr<InputGroupCall> &&call_, array<int32> &&messages_)
  : flags_(flags_)
  , report_spam_(report_spam_)
  , call_(std::move(call_))
  , messages_(std::move(messages_))
{}

const std::int32_t phone_deleteGroupCallMessages::ID;

void phone_deleteGroupCallMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-162573065);
  TlStoreBinary::store((var0 = flags_ | (report_spam_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(messages_, s);
}

void phone_deleteGroupCallMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-162573065);
  TlStoreBinary::store((var0 = flags_ | (report_spam_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(messages_, s);
}

void phone_deleteGroupCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.deleteGroupCallMessages");
    s.store_field("flags", (var0 = flags_ | (report_spam_ << 0)));
    if (var0 & 1) { s.store_field("report_spam", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

phone_deleteGroupCallMessages::ReturnType phone_deleteGroupCallMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_discardCall::phone_discardCall(int32 flags_, bool video_, object_ptr<inputPhoneCall> &&peer_, int32 duration_, object_ptr<PhoneCallDiscardReason> &&reason_, int64 connection_id_)
  : flags_(flags_)
  , video_(video_)
  , peer_(std::move(peer_))
  , duration_(duration_)
  , reason_(std::move(reason_))
  , connection_id_(connection_id_)
{}

const std::int32_t phone_discardCall::ID;

void phone_discardCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1295269440);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBinary::store(duration_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreBinary::store(connection_id_, s);
}

void phone_discardCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1295269440);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBinary::store(duration_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreBinary::store(connection_id_, s);
}

void phone_discardCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.discardCall");
    s.store_field("flags", (var0 = flags_ | (video_ << 0)));
    if (var0 & 1) { s.store_field("video", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("duration", duration_);
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("connection_id", connection_id_);
    s.store_class_end();
  }
}

phone_discardCall::ReturnType phone_discardCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_toggleGroupCallRecord::phone_toggleGroupCallRecord(int32 flags_, bool start_, bool video_, object_ptr<InputGroupCall> &&call_, string const &title_, bool video_portrait_)
  : flags_(flags_)
  , start_(start_)
  , video_(video_)
  , call_(std::move(call_))
  , title_(title_)
  , video_portrait_(video_portrait_)
{}

const std::int32_t phone_toggleGroupCallRecord::ID;

void phone_toggleGroupCallRecord::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-248985848);
  TlStoreBinary::store((var0 = flags_ | (start_ << 0) | (video_ << 2) | ((!title_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBool::store(video_portrait_, s); }
}

void phone_toggleGroupCallRecord::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-248985848);
  TlStoreBinary::store((var0 = flags_ | (start_ << 0) | (video_ << 2) | ((!title_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBool::store(video_portrait_, s); }
}

void phone_toggleGroupCallRecord::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.toggleGroupCallRecord");
    s.store_field("flags", (var0 = flags_ | (start_ << 0) | (video_ << 2) | ((!title_.empty()) << 1)));
    if (var0 & 1) { s.store_field("start", true); }
    if (var0 & 4) { s.store_field("video", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 4) { s.store_field("video_portrait", video_portrait_); }
    s.store_class_end();
  }
}

phone_toggleGroupCallRecord::ReturnType phone_toggleGroupCallRecord::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

premium_getBoostsStatus::premium_getBoostsStatus(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t premium_getBoostsStatus::ID;

void premium_getBoostsStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(70197089);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void premium_getBoostsStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(70197089);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void premium_getBoostsStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.getBoostsStatus");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

premium_getBoostsStatus::ReturnType premium_getBoostsStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<premium_boostsStatus>, 1230586490>::parse(p);
#undef FAIL
}

smsjobs_finishJob::smsjobs_finishJob(int32 flags_, string const &job_id_, string const &error_)
  : flags_(flags_)
  , job_id_(job_id_)
  , error_(error_)
{}

const std::int32_t smsjobs_finishJob::ID;

void smsjobs_finishJob::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1327415076);
  TlStoreBinary::store((var0 = flags_ | ((!error_.empty()) << 0)), s);
  TlStoreString::store(job_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
}

void smsjobs_finishJob::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1327415076);
  TlStoreBinary::store((var0 = flags_ | ((!error_.empty()) << 0)), s);
  TlStoreString::store(job_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
}

void smsjobs_finishJob::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.finishJob");
    s.store_field("flags", (var0 = flags_ | ((!error_.empty()) << 0)));
    s.store_field("job_id", job_id_);
    if (var0 & 1) { s.store_field("error", error_); }
    s.store_class_end();
  }
}

smsjobs_finishJob::ReturnType smsjobs_finishJob::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stats_loadAsyncGraph::stats_loadAsyncGraph(int32 flags_, string const &token_, int64 x_)
  : flags_(flags_)
  , token_(token_)
  , x_(x_)
{}

const std::int32_t stats_loadAsyncGraph::ID;

void stats_loadAsyncGraph::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1646092192);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(token_, s);
  if (var0 & 1) { TlStoreBinary::store(x_, s); }
}

void stats_loadAsyncGraph::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1646092192);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(token_, s);
  if (var0 & 1) { TlStoreBinary::store(x_, s); }
}

void stats_loadAsyncGraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.loadAsyncGraph");
    s.store_field("flags", (var0 = flags_));
    s.store_field("token", "[REDACTED]");
    if (var0 & 1) { s.store_field("x", x_); }
    s.store_class_end();
  }
}

stats_loadAsyncGraph::ReturnType stats_loadAsyncGraph::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<StatsGraph>::parse(p);
#undef FAIL
}

stickers_deleteStickerSet::stickers_deleteStickerSet(object_ptr<InputStickerSet> &&stickerset_)
  : stickerset_(std::move(stickerset_))
{}

const std::int32_t stickers_deleteStickerSet::ID;

void stickers_deleteStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2022685804);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void stickers_deleteStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2022685804);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void stickers_deleteStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.deleteStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

stickers_deleteStickerSet::ReturnType stickers_deleteStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stickers_renameStickerSet::stickers_renameStickerSet(object_ptr<InputStickerSet> &&stickerset_, string const &title_)
  : stickerset_(std::move(stickerset_))
  , title_(title_)
{}

const std::int32_t stickers_renameStickerSet::ID;

void stickers_renameStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(306912256);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreString::store(title_, s);
}

void stickers_renameStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(306912256);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreString::store(title_, s);
}

void stickers_renameStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.renameStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

stickers_renameStickerSet::ReturnType stickers_renameStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stories_getAlbums::stories_getAlbums(object_ptr<InputPeer> &&peer_, int64 hash_)
  : peer_(std::move(peer_))
  , hash_(hash_)
{}

const std::int32_t stories_getAlbums::ID;

void stories_getAlbums::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(632548039);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void stories_getAlbums::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(632548039);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void stories_getAlbums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getAlbums");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

stories_getAlbums::ReturnType stories_getAlbums::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<stories_Albums>::parse(p);
#undef FAIL
}

stories_getAllStories::stories_getAllStories(int32 flags_, bool next_, bool hidden_, string const &state_)
  : flags_(flags_)
  , next_(next_)
  , hidden_(hidden_)
  , state_(state_)
{}

const std::int32_t stories_getAllStories::ID;

void stories_getAllStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-290400731);
  TlStoreBinary::store((var0 = flags_ | (next_ << 1) | (hidden_ << 2) | ((!state_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(state_, s); }
}

void stories_getAllStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-290400731);
  TlStoreBinary::store((var0 = flags_ | (next_ << 1) | (hidden_ << 2) | ((!state_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(state_, s); }
}

void stories_getAllStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getAllStories");
    s.store_field("flags", (var0 = flags_ | (next_ << 1) | (hidden_ << 2) | ((!state_.empty()) << 0)));
    if (var0 & 2) { s.store_field("next", true); }
    if (var0 & 4) { s.store_field("hidden", true); }
    if (var0 & 1) { s.store_field("state", state_); }
    s.store_class_end();
  }
}

stories_getAllStories::ReturnType stories_getAllStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<stories_AllStories>::parse(p);
#undef FAIL
}

stories_getPeerStories::stories_getPeerStories(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t stories_getPeerStories::ID;

void stories_getPeerStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(743103056);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void stories_getPeerStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(743103056);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void stories_getPeerStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getPeerStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

stories_getPeerStories::ReturnType stories_getPeerStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_peerStories>, -890861720>::parse(p);
#undef FAIL
}

stories_togglePinnedToTop::stories_togglePinnedToTop(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t stories_togglePinnedToTop::ID;

void stories_togglePinnedToTop::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(187268763);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_togglePinnedToTop::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(187268763);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_togglePinnedToTop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.togglePinnedToTop");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_togglePinnedToTop::ReturnType stories_togglePinnedToTop::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

users_suggestBirthday::users_suggestBirthday(object_ptr<InputUser> &&id_, object_ptr<birthday> &&birthday_)
  : id_(std::move(id_))
  , birthday_(std::move(birthday_))
{}

const std::int32_t users_suggestBirthday::ID;

void users_suggestBirthday::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-61656206);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1821253126>::store(birthday_, s);
}

void users_suggestBirthday::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-61656206);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1821253126>::store(birthday_, s);
}

void users_suggestBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.suggestBirthday");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_object_field("birthday", static_cast<const BaseObject *>(birthday_.get()));
    s.store_class_end();
  }
}

users_suggestBirthday::ReturnType users_suggestBirthday::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

wallet_getUserAddresses::wallet_getUserAddresses(int32 flags_, bool force_, array<object_ptr<InputUser>> &&id_, array<string> &&addresses_)
  : flags_(flags_)
  , force_(force_)
  , id_(std::move(id_))
  , addresses_(std::move(addresses_))
{}

const std::int32_t wallet_getUserAddresses::ID;

void wallet_getUserAddresses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1383456733);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(addresses_, s);
}

void wallet_getUserAddresses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1383456733);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(addresses_, s);
}

void wallet_getUserAddresses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.getUserAddresses");
    s.store_field("flags", (var0 = flags_ | (force_ << 0)));
    if (var0 & 1) { s.store_field("force", true); }
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("addresses", addresses_.size()); for (const auto &_value : addresses_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

wallet_getUserAddresses::ReturnType wallet_getUserAddresses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_userAddresses>, -1836156075>::parse(p);
#undef FAIL
}

wallet_tonConnectGetPending::wallet_tonConnectGetPending(int32 flags_, string const &dapp_client_id_, int64 session_id_)
  : flags_(flags_)
  , dapp_client_id_(dapp_client_id_)
  , session_id_(session_id_)
{}

const std::int32_t wallet_tonConnectGetPending::ID;

void wallet_tonConnectGetPending::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(296673381);
  TlStoreBinary::store((var0 = flags_ | ((!dapp_client_id_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(dapp_client_id_, s); }
  if (var0 & 2) { TlStoreBinary::store(session_id_, s); }
}

void wallet_tonConnectGetPending::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(296673381);
  TlStoreBinary::store((var0 = flags_ | ((!dapp_client_id_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(dapp_client_id_, s); }
  if (var0 & 2) { TlStoreBinary::store(session_id_, s); }
}

void wallet_tonConnectGetPending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectGetPending");
    s.store_field("flags", (var0 = flags_ | ((!dapp_client_id_.empty()) << 0)));
    if (var0 & 1) { s.store_field("dapp_client_id", dapp_client_id_); }
    if (var0 & 2) { s.store_field("session_id", session_id_); }
    s.store_class_end();
  }
}

wallet_tonConnectGetPending::ReturnType wallet_tonConnectGetPending::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_tonConnectPending>, -2050952924>::parse(p);
#undef FAIL
}

wallet_tonConnectRegisterKey::wallet_tonConnectRegisterKey(int64 session_id_, string const &client_id_)
  : session_id_(session_id_)
  , client_id_(client_id_)
{}

const std::int32_t wallet_tonConnectRegisterKey::ID;

void wallet_tonConnectRegisterKey::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(864800540);
  TlStoreBinary::store(session_id_, s);
  TlStoreString::store(client_id_, s);
}

void wallet_tonConnectRegisterKey::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(864800540);
  TlStoreBinary::store(session_id_, s);
  TlStoreString::store(client_id_, s);
}

void wallet_tonConnectRegisterKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.tonConnectRegisterKey");
    s.store_field("session_id", session_id_);
    s.store_field("client_id", client_id_);
    s.store_class_end();
  }
}

wallet_tonConnectRegisterKey::ReturnType wallet_tonConnectRegisterKey::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_tonConnectChallenge>, 1271436947>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
