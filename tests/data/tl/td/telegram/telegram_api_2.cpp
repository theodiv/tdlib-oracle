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


availableReaction::availableReaction()
  : flags_()
  , inactive_()
  , premium_()
  , reaction_()
  , title_()
  , static_icon_()
  , appear_animation_()
  , select_animation_()
  , activate_animation_()
  , effect_animation_()
  , around_animation_()
  , center_icon_()
{}

const std::int32_t availableReaction::ID;

object_ptr<availableReaction> availableReaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<availableReaction> res = make_tl_object<availableReaction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inactive_ = (var0 & 1) != 0;
  res->premium_ = (var0 & 4) != 0;
  res->reaction_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->static_icon_ = TlFetchObject<Document>::parse(p);
  res->appear_animation_ = TlFetchObject<Document>::parse(p);
  res->select_animation_ = TlFetchObject<Document>::parse(p);
  res->activate_animation_ = TlFetchObject<Document>::parse(p);
  res->effect_animation_ = TlFetchObject<Document>::parse(p);
  if (var0 & 2) { res->around_animation_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 2) { res->center_icon_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void availableReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableReaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inactive_ << 0) | (premium_ << 2) | ((around_animation_ != nullptr) << 1) | ((center_icon_ != nullptr) << 1)));
    if (var0 & 1) { s.store_field("inactive", true); }
    if (var0 & 4) { s.store_field("premium", true); }
    s.store_field("reaction", reaction_);
    s.store_field("title", title_);
    s.store_object_field("static_icon", static_cast<const BaseObject *>(static_icon_.get()));
    s.store_object_field("appear_animation", static_cast<const BaseObject *>(appear_animation_.get()));
    s.store_object_field("select_animation", static_cast<const BaseObject *>(select_animation_.get()));
    s.store_object_field("activate_animation", static_cast<const BaseObject *>(activate_animation_.get()));
    s.store_object_field("effect_animation", static_cast<const BaseObject *>(effect_animation_.get()));
    if (var0 & 2) { s.store_object_field("around_animation", static_cast<const BaseObject *>(around_animation_.get())); }
    if (var0 & 2) { s.store_object_field("center_icon", static_cast<const BaseObject *>(center_icon_.get())); }
    s.store_class_end();
  }
}

object_ptr<BaseTheme> BaseTheme::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t baseThemeClassic::ID;

object_ptr<BaseTheme> baseThemeClassic::fetch(TlBufferParser &p) {
  return make_tl_object<baseThemeClassic>();
}

void baseThemeClassic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void baseThemeClassic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void baseThemeClassic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "baseThemeClassic");
    s.store_class_end();
  }
}

const std::int32_t baseThemeDay::ID;

object_ptr<BaseTheme> baseThemeDay::fetch(TlBufferParser &p) {
  return make_tl_object<baseThemeDay>();
}

void baseThemeDay::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void baseThemeDay::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void baseThemeDay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "baseThemeDay");
    s.store_class_end();
  }
}

const std::int32_t baseThemeNight::ID;

object_ptr<BaseTheme> baseThemeNight::fetch(TlBufferParser &p) {
  return make_tl_object<baseThemeNight>();
}

void baseThemeNight::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void baseThemeNight::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void baseThemeNight::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "baseThemeNight");
    s.store_class_end();
  }
}

const std::int32_t baseThemeTinted::ID;

object_ptr<BaseTheme> baseThemeTinted::fetch(TlBufferParser &p) {
  return make_tl_object<baseThemeTinted>();
}

void baseThemeTinted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void baseThemeTinted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void baseThemeTinted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "baseThemeTinted");
    s.store_class_end();
  }
}

const std::int32_t baseThemeArctic::ID;

object_ptr<BaseTheme> baseThemeArctic::fetch(TlBufferParser &p) {
  return make_tl_object<baseThemeArctic>();
}

void baseThemeArctic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void baseThemeArctic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void baseThemeArctic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "baseThemeArctic");
    s.store_class_end();
  }
}

object_ptr<BotInlineResult> BotInlineResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case botInlineResult::ID:
      return botInlineResult::fetch(p);
    case botInlineMediaResult::ID:
      return botInlineMediaResult::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

botInlineResult::botInlineResult()
  : flags_()
  , id_()
  , type_()
  , title_()
  , description_()
  , url_()
  , thumb_()
  , content_()
  , send_message_()
{}

const std::int32_t botInlineResult::ID;

object_ptr<BotInlineResult> botInlineResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineResult> res = make_tl_object<botInlineResult>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchString<string>::parse(p);
  res->type_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->description_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->url_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->thumb_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 32) { res->content_ = TlFetchObject<WebDocument>::parse(p); }
  res->send_message_ = TlFetchObject<BotInlineMessage>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineResult");
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

botInlineMediaResult::botInlineMediaResult()
  : flags_()
  , id_()
  , type_()
  , photo_()
  , document_()
  , title_()
  , description_()
  , send_message_()
{}

const std::int32_t botInlineMediaResult::ID;

object_ptr<BotInlineResult> botInlineMediaResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMediaResult> res = make_tl_object<botInlineMediaResult>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchString<string>::parse(p);
  res->type_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 2) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 4) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->description_ = TlFetchString<string>::parse(p); }
  res->send_message_ = TlFetchObject<BotInlineMessage>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMediaResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMediaResult");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((photo_ != nullptr) << 0) | ((document_ != nullptr) << 1) | ((!title_.empty()) << 2) | ((!description_.empty()) << 3)));
    s.store_field("id", id_);
    s.store_field("type", type_);
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 2) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 4) { s.store_field("title", title_); }
    if (var0 & 8) { s.store_field("description", description_); }
    s.store_object_field("send_message", static_cast<const BaseObject *>(send_message_.get()));
    s.store_class_end();
  }
}

channelAdminLogEventsFilter::channelAdminLogEventsFilter(int32 flags_, bool join_, bool leave_, bool invite_, bool ban_, bool unban_, bool kick_, bool unkick_, bool promote_, bool demote_, bool info_, bool settings_, bool pinned_, bool edit_, bool delete_, bool group_call_, bool invites_, bool send_, bool forums_, bool sub_extend_, bool edit_rank_)
  : flags_(flags_)
  , join_(join_)
  , leave_(leave_)
  , invite_(invite_)
  , ban_(ban_)
  , unban_(unban_)
  , kick_(kick_)
  , unkick_(unkick_)
  , promote_(promote_)
  , demote_(demote_)
  , info_(info_)
  , settings_(settings_)
  , pinned_(pinned_)
  , edit_(edit_)
  , delete_(delete_)
  , group_call_(group_call_)
  , invites_(invites_)
  , send_(send_)
  , forums_(forums_)
  , sub_extend_(sub_extend_)
  , edit_rank_(edit_rank_)
{}

const std::int32_t channelAdminLogEventsFilter::ID;

void channelAdminLogEventsFilter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (join_ << 0) | (leave_ << 1) | (invite_ << 2) | (ban_ << 3) | (unban_ << 4) | (kick_ << 5) | (unkick_ << 6) | (promote_ << 7) | (demote_ << 8) | (info_ << 9) | (settings_ << 10) | (pinned_ << 11) | (edit_ << 12) | (delete_ << 13) | (group_call_ << 14) | (invites_ << 15) | (send_ << 16) | (forums_ << 17) | (sub_extend_ << 18) | (edit_rank_ << 19)), s);
}

void channelAdminLogEventsFilter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (join_ << 0) | (leave_ << 1) | (invite_ << 2) | (ban_ << 3) | (unban_ << 4) | (kick_ << 5) | (unkick_ << 6) | (promote_ << 7) | (demote_ << 8) | (info_ << 9) | (settings_ << 10) | (pinned_ << 11) | (edit_ << 12) | (delete_ << 13) | (group_call_ << 14) | (invites_ << 15) | (send_ << 16) | (forums_ << 17) | (sub_extend_ << 18) | (edit_rank_ << 19)), s);
}

void channelAdminLogEventsFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventsFilter");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (join_ << 0) | (leave_ << 1) | (invite_ << 2) | (ban_ << 3) | (unban_ << 4) | (kick_ << 5) | (unkick_ << 6) | (promote_ << 7) | (demote_ << 8) | (info_ << 9) | (settings_ << 10) | (pinned_ << 11) | (edit_ << 12) | (delete_ << 13) | (group_call_ << 14) | (invites_ << 15) | (send_ << 16) | (forums_ << 17) | (sub_extend_ << 18) | (edit_rank_ << 19)));
    if (var0 & 1) { s.store_field("join", true); }
    if (var0 & 2) { s.store_field("leave", true); }
    if (var0 & 4) { s.store_field("invite", true); }
    if (var0 & 8) { s.store_field("ban", true); }
    if (var0 & 16) { s.store_field("unban", true); }
    if (var0 & 32) { s.store_field("kick", true); }
    if (var0 & 64) { s.store_field("unkick", true); }
    if (var0 & 128) { s.store_field("promote", true); }
    if (var0 & 256) { s.store_field("demote", true); }
    if (var0 & 512) { s.store_field("info", true); }
    if (var0 & 1024) { s.store_field("settings", true); }
    if (var0 & 2048) { s.store_field("pinned", true); }
    if (var0 & 4096) { s.store_field("edit", true); }
    if (var0 & 8192) { s.store_field("delete", true); }
    if (var0 & 16384) { s.store_field("group_call", true); }
    if (var0 & 32768) { s.store_field("invites", true); }
    if (var0 & 65536) { s.store_field("send", true); }
    if (var0 & 131072) { s.store_field("forums", true); }
    if (var0 & 262144) { s.store_field("sub_extend", true); }
    if (var0 & 524288) { s.store_field("edit_rank", true); }
    s.store_class_end();
  }
}

object_ptr<ChannelParticipant> ChannelParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

channelParticipant::channelParticipant()
  : flags_()
  , user_id_()
  , date_()
  , subscription_until_date_()
  , rank_()
{}

const std::int32_t channelParticipant::ID;

object_ptr<ChannelParticipant> channelParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelParticipant> res = make_tl_object<channelParticipant>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->subscription_until_date_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipant");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!rank_.empty()) << 2)));
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    if (var0 & 1) { s.store_field("subscription_until_date", subscription_until_date_); }
    if (var0 & 4) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

channelParticipantSelf::channelParticipantSelf()
  : flags_()
  , via_request_()
  , user_id_()
  , inviter_id_()
  , date_()
  , subscription_until_date_()
  , rank_()
{}

const std::int32_t channelParticipantSelf::ID;

object_ptr<ChannelParticipant> channelParticipantSelf::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelParticipantSelf> res = make_tl_object<channelParticipantSelf>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_request_ = (var0 & 1) != 0;
  res->user_id_ = TlFetchLong::parse(p);
  res->inviter_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->subscription_until_date_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelParticipantSelf::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantSelf");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_request_ << 0) | ((!rank_.empty()) << 2)));
    if (var0 & 1) { s.store_field("via_request", true); }
    s.store_field("user_id", user_id_);
    s.store_field("inviter_id", inviter_id_);
    s.store_field("date", date_);
    if (var0 & 2) { s.store_field("subscription_until_date", subscription_until_date_); }
    if (var0 & 4) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

channelParticipantCreator::channelParticipantCreator()
  : flags_()
  , user_id_()
  , admin_rights_()
  , rank_()
{}

const std::int32_t channelParticipantCreator::ID;

object_ptr<ChannelParticipant> channelParticipantCreator::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelParticipantCreator> res = make_tl_object<channelParticipantCreator>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  res->admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p);
  if (var0 & 1) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelParticipantCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantCreator");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!rank_.empty()) << 0)));
    s.store_field("user_id", user_id_);
    s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get()));
    if (var0 & 1) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

channelParticipantAdmin::channelParticipantAdmin()
  : flags_()
  , can_edit_()
  , self_()
  , user_id_()
  , inviter_id_()
  , promoted_by_()
  , date_()
  , admin_rights_()
  , rank_()
{}

const std::int32_t channelParticipantAdmin::ID;

object_ptr<ChannelParticipant> channelParticipantAdmin::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelParticipantAdmin> res = make_tl_object<channelParticipantAdmin>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_edit_ = (var0 & 1) != 0;
  res->self_ = (var0 & 2) != 0;
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->inviter_id_ = TlFetchLong::parse(p); }
  res->promoted_by_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p);
  if (var0 & 4) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelParticipantAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantAdmin");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_edit_ << 0) | (self_ << 1) | ((!rank_.empty()) << 2)));
    if (var0 & 1) { s.store_field("can_edit", true); }
    if (var0 & 2) { s.store_field("self", true); }
    s.store_field("user_id", user_id_);
    if (var0 & 2) { s.store_field("inviter_id", inviter_id_); }
    s.store_field("promoted_by", promoted_by_);
    s.store_field("date", date_);
    s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get()));
    if (var0 & 4) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

channelParticipantBanned::channelParticipantBanned()
  : flags_()
  , left_()
  , peer_()
  , kicked_by_()
  , date_()
  , banned_rights_()
  , rank_()
{}

const std::int32_t channelParticipantBanned::ID;

object_ptr<ChannelParticipant> channelParticipantBanned::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelParticipantBanned> res = make_tl_object<channelParticipantBanned>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->left_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->kicked_by_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->banned_rights_ = TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p);
  if (var0 & 4) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelParticipantBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantBanned");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (left_ << 0) | ((!rank_.empty()) << 2)));
    if (var0 & 1) { s.store_field("left", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("kicked_by", kicked_by_);
    s.store_field("date", date_);
    s.store_object_field("banned_rights", static_cast<const BaseObject *>(banned_rights_.get()));
    if (var0 & 4) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

const std::int32_t channelParticipantLeft::ID;

object_ptr<ChannelParticipant> channelParticipantLeft::fetch(TlBufferParser &p) {
  return make_tl_object<channelParticipantLeft>(p);
}

channelParticipantLeft::channelParticipantLeft(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
{}

void channelParticipantLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantLeft");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelParticipantsRecent::ID;

void channelParticipantsRecent::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void channelParticipantsRecent::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void channelParticipantsRecent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsRecent");
    s.store_class_end();
  }
}

const std::int32_t channelParticipantsAdmins::ID;

void channelParticipantsAdmins::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void channelParticipantsAdmins::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void channelParticipantsAdmins::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsAdmins");
    s.store_class_end();
  }
}

channelParticipantsKicked::channelParticipantsKicked(string const &q_)
  : q_(q_)
{}

const std::int32_t channelParticipantsKicked::ID;

void channelParticipantsKicked::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsKicked::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsKicked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsKicked");
    s.store_field("q", q_);
    s.store_class_end();
  }
}

const std::int32_t channelParticipantsBots::ID;

void channelParticipantsBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void channelParticipantsBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void channelParticipantsBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsBots");
    s.store_class_end();
  }
}

channelParticipantsBanned::channelParticipantsBanned(string const &q_)
  : q_(q_)
{}

const std::int32_t channelParticipantsBanned::ID;

void channelParticipantsBanned::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsBanned::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsBanned");
    s.store_field("q", q_);
    s.store_class_end();
  }
}

channelParticipantsSearch::channelParticipantsSearch(string const &q_)
  : q_(q_)
{}

const std::int32_t channelParticipantsSearch::ID;

void channelParticipantsSearch::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsSearch::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsSearch");
    s.store_field("q", q_);
    s.store_class_end();
  }
}

channelParticipantsContacts::channelParticipantsContacts(string const &q_)
  : q_(q_)
{}

const std::int32_t channelParticipantsContacts::ID;

void channelParticipantsContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsContacts");
    s.store_field("q", q_);
    s.store_class_end();
  }
}

channelParticipantsMentions::channelParticipantsMentions(int32 flags_, string const &q_, int32 top_msg_id_)
  : flags_(flags_)
  , q_(q_)
  , top_msg_id_(top_msg_id_)
{}

const std::int32_t channelParticipantsMentions::ID;

void channelParticipantsMentions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!q_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(q_, s); }
  if (var0 & 2) { TlStoreBinary::store(top_msg_id_, s); }
}

void channelParticipantsMentions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!q_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(q_, s); }
  if (var0 & 2) { TlStoreBinary::store(top_msg_id_, s); }
}

void channelParticipantsMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsMentions");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!q_.empty()) << 0)));
    if (var0 & 1) { s.store_field("q", q_); }
    if (var0 & 2) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_class_end();
  }
}

object_ptr<Chat> Chat::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

chatEmpty::chatEmpty(int64 id_)
  : id_(id_)
{}

const std::int32_t chatEmpty::ID;

object_ptr<Chat> chatEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<chatEmpty>(p);
}

chatEmpty::chatEmpty(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void chatEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void chatEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void chatEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

chat::chat()
  : flags_()
  , creator_()
  , left_()
  , deactivated_()
  , call_active_()
  , call_not_empty_()
  , noforwards_()
  , id_()
  , title_()
  , photo_()
  , participants_count_()
  , date_()
  , version_()
  , migrated_to_()
  , admin_rights_()
  , default_banned_rights_()
{}

chat::chat(int32 flags_, bool creator_, bool left_, bool deactivated_, bool call_active_, bool call_not_empty_, bool noforwards_, int64 id_, string const &title_, object_ptr<ChatPhoto> &&photo_, int32 participants_count_, int32 date_, int32 version_, object_ptr<InputChannel> &&migrated_to_, object_ptr<chatAdminRights> &&admin_rights_, object_ptr<chatBannedRights> &&default_banned_rights_)
  : flags_(flags_)
  , creator_(creator_)
  , left_(left_)
  , deactivated_(deactivated_)
  , call_active_(call_active_)
  , call_not_empty_(call_not_empty_)
  , noforwards_(noforwards_)
  , id_(id_)
  , title_(title_)
  , photo_(std::move(photo_))
  , participants_count_(participants_count_)
  , date_(date_)
  , version_(version_)
  , migrated_to_(std::move(migrated_to_))
  , admin_rights_(std::move(admin_rights_))
  , default_banned_rights_(std::move(default_banned_rights_))
{}

const std::int32_t chat::ID;

object_ptr<Chat> chat::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chat> res = make_tl_object<chat>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->left_ = (var0 & 4) != 0;
  res->deactivated_ = (var0 & 32) != 0;
  res->call_active_ = (var0 & 8388608) != 0;
  res->call_not_empty_ = (var0 & 16777216) != 0;
  res->noforwards_ = (var0 & 33554432) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->photo_ = TlFetchObject<ChatPhoto>::parse(p);
  res->participants_count_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->version_ = TlFetchInt::parse(p);
  if (var0 & 64) { res->migrated_to_ = TlFetchObject<InputChannel>::parse(p); }
  if (var0 & 16384) { res->admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 262144) { res->default_banned_rights_ = TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (left_ << 2) | (deactivated_ << 5) | (call_active_ << 23) | (call_not_empty_ << 24) | (noforwards_ << 25) | ((migrated_to_ != nullptr) << 6) | ((admin_rights_ != nullptr) << 14) | ((default_banned_rights_ != nullptr) << 18)), s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBinary::store(participants_count_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(version_, s);
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(migrated_to_, s); }
  if (var0 & 16384) { TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s); }
  if (var0 & 262144) { TlStoreBoxed<TlStoreObject, -1626209256>::store(default_banned_rights_, s); }
}

void chat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (left_ << 2) | (deactivated_ << 5) | (call_active_ << 23) | (call_not_empty_ << 24) | (noforwards_ << 25) | ((migrated_to_ != nullptr) << 6) | ((admin_rights_ != nullptr) << 14) | ((default_banned_rights_ != nullptr) << 18)), s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBinary::store(participants_count_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(version_, s);
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(migrated_to_, s); }
  if (var0 & 16384) { TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s); }
  if (var0 & 262144) { TlStoreBoxed<TlStoreObject, -1626209256>::store(default_banned_rights_, s); }
}

void chat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chat");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | (left_ << 2) | (deactivated_ << 5) | (call_active_ << 23) | (call_not_empty_ << 24) | (noforwards_ << 25) | ((migrated_to_ != nullptr) << 6) | ((admin_rights_ != nullptr) << 14) | ((default_banned_rights_ != nullptr) << 18)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 4) { s.store_field("left", true); }
    if (var0 & 32) { s.store_field("deactivated", true); }
    if (var0 & 8388608) { s.store_field("call_active", true); }
    if (var0 & 16777216) { s.store_field("call_not_empty", true); }
    if (var0 & 33554432) { s.store_field("noforwards", true); }
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("participants_count", participants_count_);
    s.store_field("date", date_);
    s.store_field("version", version_);
    if (var0 & 64) { s.store_object_field("migrated_to", static_cast<const BaseObject *>(migrated_to_.get())); }
    if (var0 & 16384) { s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get())); }
    if (var0 & 262144) { s.store_object_field("default_banned_rights", static_cast<const BaseObject *>(default_banned_rights_.get())); }
    s.store_class_end();
  }
}

chatForbidden::chatForbidden(int64 id_, string const &title_)
  : id_(id_)
  , title_(title_)
{}

const std::int32_t chatForbidden::ID;

object_ptr<Chat> chatForbidden::fetch(TlBufferParser &p) {
  return make_tl_object<chatForbidden>(p);
}

chatForbidden::chatForbidden(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , title_(TlFetchString<string>::parse(p))
{}

void chatForbidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(title_, s);
}

void chatForbidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(title_, s);
}

void chatForbidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatForbidden");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

channel::channel()
  : flags_()
  , creator_()
  , left_()
  , broadcast_()
  , verified_()
  , megagroup_()
  , restricted_()
  , signatures_()
  , min_()
  , scam_()
  , has_link_()
  , has_geo_()
  , slowmode_enabled_()
  , call_active_()
  , call_not_empty_()
  , fake_()
  , gigagroup_()
  , noforwards_()
  , join_to_send_()
  , join_request_()
  , forum_()
  , flags2_()
  , stories_hidden_()
  , stories_hidden_min_()
  , stories_unavailable_()
  , signature_profiles_()
  , autotranslation_()
  , broadcast_messages_allowed_()
  , monoforum_()
  , forum_tabs_()
  , in_news_()
  , forum_sidebar_()
  , id_()
  , access_hash_()
  , title_()
  , username_()
  , photo_()
  , date_()
  , restriction_reason_()
  , admin_rights_()
  , banned_rights_()
  , default_banned_rights_()
  , participants_count_()
  , usernames_()
  , stories_max_id_()
  , color_()
  , profile_color_()
  , emoji_status_()
  , level_()
  , subscription_until_date_()
  , bot_verification_icon_()
  , send_paid_messages_stars_()
  , linked_monoforum_id_()
  , linked_community_id_()
  , pinned_msg_id_()
{}

channel::channel(int32 flags_, bool creator_, bool left_, bool broadcast_, bool verified_, bool megagroup_, bool restricted_, bool signatures_, bool min_, bool scam_, bool has_link_, bool has_geo_, bool slowmode_enabled_, bool call_active_, bool call_not_empty_, bool fake_, bool gigagroup_, bool noforwards_, bool join_to_send_, bool join_request_, bool forum_, int32 flags2_, bool stories_hidden_, bool stories_hidden_min_, bool stories_unavailable_, bool signature_profiles_, bool autotranslation_, bool broadcast_messages_allowed_, bool monoforum_, bool forum_tabs_, bool in_news_, bool forum_sidebar_, int64 id_, int64 access_hash_, string const &title_, string const &username_, object_ptr<ChatPhoto> &&photo_, int32 date_, array<object_ptr<restrictionReason>> &&restriction_reason_, object_ptr<chatAdminRights> &&admin_rights_, object_ptr<chatBannedRights> &&banned_rights_, object_ptr<chatBannedRights> &&default_banned_rights_, int32 participants_count_, array<object_ptr<username>> &&usernames_, object_ptr<recentStory> &&stories_max_id_, object_ptr<PeerColor> &&color_, object_ptr<PeerColor> &&profile_color_, object_ptr<EmojiStatus> &&emoji_status_, int32 level_, int32 subscription_until_date_, int64 bot_verification_icon_, int64 send_paid_messages_stars_, int64 linked_monoforum_id_, int64 linked_community_id_, int32 pinned_msg_id_)
  : flags_(flags_)
  , creator_(creator_)
  , left_(left_)
  , broadcast_(broadcast_)
  , verified_(verified_)
  , megagroup_(megagroup_)
  , restricted_(restricted_)
  , signatures_(signatures_)
  , min_(min_)
  , scam_(scam_)
  , has_link_(has_link_)
  , has_geo_(has_geo_)
  , slowmode_enabled_(slowmode_enabled_)
  , call_active_(call_active_)
  , call_not_empty_(call_not_empty_)
  , fake_(fake_)
  , gigagroup_(gigagroup_)
  , noforwards_(noforwards_)
  , join_to_send_(join_to_send_)
  , join_request_(join_request_)
  , forum_(forum_)
  , flags2_(flags2_)
  , stories_hidden_(stories_hidden_)
  , stories_hidden_min_(stories_hidden_min_)
  , stories_unavailable_(stories_unavailable_)
  , signature_profiles_(signature_profiles_)
  , autotranslation_(autotranslation_)
  , broadcast_messages_allowed_(broadcast_messages_allowed_)
  , monoforum_(monoforum_)
  , forum_tabs_(forum_tabs_)
  , in_news_(in_news_)
  , forum_sidebar_(forum_sidebar_)
  , id_(id_)
  , access_hash_(access_hash_)
  , title_(title_)
  , username_(username_)
  , photo_(std::move(photo_))
  , date_(date_)
  , restriction_reason_(std::move(restriction_reason_))
  , admin_rights_(std::move(admin_rights_))
  , banned_rights_(std::move(banned_rights_))
  , default_banned_rights_(std::move(default_banned_rights_))
  , participants_count_(participants_count_)
  , usernames_(std::move(usernames_))
  , stories_max_id_(std::move(stories_max_id_))
  , color_(std::move(color_))
  , profile_color_(std::move(profile_color_))
  , emoji_status_(std::move(emoji_status_))
  , level_(level_)
  , subscription_until_date_(subscription_until_date_)
  , bot_verification_icon_(bot_verification_icon_)
  , send_paid_messages_stars_(send_paid_messages_stars_)
  , linked_monoforum_id_(linked_monoforum_id_)
  , linked_community_id_(linked_community_id_)
  , pinned_msg_id_(pinned_msg_id_)
{}

const std::int32_t channel::ID;

object_ptr<Chat> channel::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channel> res = make_tl_object<channel>();
  int32 var0;
  int32 var1;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->left_ = (var0 & 4) != 0;
  res->broadcast_ = (var0 & 32) != 0;
  res->verified_ = (var0 & 128) != 0;
  res->megagroup_ = (var0 & 256) != 0;
  res->restricted_ = (var0 & 512) != 0;
  res->signatures_ = (var0 & 2048) != 0;
  res->min_ = (var0 & 4096) != 0;
  res->scam_ = (var0 & 524288) != 0;
  res->has_link_ = (var0 & 1048576) != 0;
  res->has_geo_ = (var0 & 2097152) != 0;
  res->slowmode_enabled_ = (var0 & 4194304) != 0;
  res->call_active_ = (var0 & 8388608) != 0;
  res->call_not_empty_ = (var0 & 16777216) != 0;
  res->fake_ = (var0 & 33554432) != 0;
  res->gigagroup_ = (var0 & 67108864) != 0;
  res->noforwards_ = (var0 & 134217728) != 0;
  res->join_to_send_ = (var0 & 268435456) != 0;
  res->join_request_ = (var0 & 536870912) != 0;
  res->forum_ = (var0 & 1073741824) != 0;
  if ((var1 = res->flags2_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->stories_hidden_ = (var1 & 2) != 0;
  res->stories_hidden_min_ = (var1 & 4) != 0;
  res->stories_unavailable_ = (var1 & 8) != 0;
  res->signature_profiles_ = (var1 & 4096) != 0;
  res->autotranslation_ = (var1 & 32768) != 0;
  res->broadcast_messages_allowed_ = (var1 & 65536) != 0;
  res->monoforum_ = (var1 & 131072) != 0;
  res->forum_tabs_ = (var1 & 524288) != 0;
  res->in_news_ = (var1 & 2097152) != 0;
  res->forum_sidebar_ = (var1 & 8388608) != 0;
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 8192) { res->access_hash_ = TlFetchLong::parse(p); }
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 64) { res->username_ = TlFetchString<string>::parse(p); }
  res->photo_ = TlFetchObject<ChatPhoto>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 512) { res->restriction_reason_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<restrictionReason>, -797791052>>, 481674261>::parse(p); }
  if (var0 & 16384) { res->admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 32768) { res->banned_rights_ = TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p); }
  if (var0 & 262144) { res->default_banned_rights_ = TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p); }
  if (var0 & 131072) { res->participants_count_ = TlFetchInt::parse(p); }
  if (var1 & 1) { res->usernames_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<username>, -1274595769>>, 481674261>::parse(p); }
  if (var1 & 16) { res->stories_max_id_ = TlFetchBoxed<TlFetchObject<recentStory>, 1897752877>::parse(p); }
  if (var1 & 128) { res->color_ = TlFetchObject<PeerColor>::parse(p); }
  if (var1 & 256) { res->profile_color_ = TlFetchObject<PeerColor>::parse(p); }
  if (var1 & 512) { res->emoji_status_ = TlFetchObject<EmojiStatus>::parse(p); }
  if (var1 & 1024) { res->level_ = TlFetchInt::parse(p); }
  if (var1 & 2048) { res->subscription_until_date_ = TlFetchInt::parse(p); }
  if (var1 & 8192) { res->bot_verification_icon_ = TlFetchLong::parse(p); }
  if (var1 & 16384) { res->send_paid_messages_stars_ = TlFetchLong::parse(p); }
  if (var1 & 262144) { res->linked_monoforum_id_ = TlFetchLong::parse(p); }
  if (var1 & 1048576) { res->linked_community_id_ = TlFetchLong::parse(p); }
  if (var1 & 4194304) { res->pinned_msg_id_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  int32 var1;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (left_ << 2) | (broadcast_ << 5) | (verified_ << 7) | (megagroup_ << 8) | (restricted_ << 9) | (signatures_ << 11) | (min_ << 12) | (scam_ << 19) | (has_link_ << 20) | (has_geo_ << 21) | (slowmode_enabled_ << 22) | (call_active_ << 23) | (call_not_empty_ << 24) | (fake_ << 25) | (gigagroup_ << 26) | (noforwards_ << 27) | (join_to_send_ << 28) | (join_request_ << 29) | (forum_ << 30) | ((!username_.empty()) << 6) | ((!restriction_reason_.empty()) << 9) | ((admin_rights_ != nullptr) << 14) | ((banned_rights_ != nullptr) << 15) | ((default_banned_rights_ != nullptr) << 18)), s);
  TlStoreBinary::store((var1 = flags2_ | (stories_hidden_ << 1) | (stories_hidden_min_ << 2) | (stories_unavailable_ << 3) | (signature_profiles_ << 12) | (autotranslation_ << 15) | (broadcast_messages_allowed_ << 16) | (monoforum_ << 17) | (forum_tabs_ << 19) | (in_news_ << 21) | (forum_sidebar_ << 23) | ((!usernames_.empty()) << 0) | ((stories_max_id_ != nullptr) << 4) | ((color_ != nullptr) << 7) | ((profile_color_ != nullptr) << 8) | ((emoji_status_ != nullptr) << 9)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 8192) { TlStoreBinary::store(access_hash_, s); }
  TlStoreString::store(title_, s);
  if (var0 & 64) { TlStoreString::store(username_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 512) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -797791052>>, 481674261>::store(restriction_reason_, s); }
  if (var0 & 16384) { TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s); }
  if (var0 & 32768) { TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s); }
  if (var0 & 262144) { TlStoreBoxed<TlStoreObject, -1626209256>::store(default_banned_rights_, s); }
  if (var0 & 131072) { TlStoreBinary::store(participants_count_, s); }
  if (var1 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1274595769>>, 481674261>::store(usernames_, s); }
  if (var1 & 16) { TlStoreBoxed<TlStoreObject, 1897752877>::store(stories_max_id_, s); }
  if (var1 & 128) { TlStoreBoxedUnknown<TlStoreObject>::store(color_, s); }
  if (var1 & 256) { TlStoreBoxedUnknown<TlStoreObject>::store(profile_color_, s); }
  if (var1 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s); }
  if (var1 & 1024) { TlStoreBinary::store(level_, s); }
  if (var1 & 2048) { TlStoreBinary::store(subscription_until_date_, s); }
  if (var1 & 8192) { TlStoreBinary::store(bot_verification_icon_, s); }
  if (var1 & 16384) { TlStoreBinary::store(send_paid_messages_stars_, s); }
  if (var1 & 262144) { TlStoreBinary::store(linked_monoforum_id_, s); }
  if (var1 & 1048576) { TlStoreBinary::store(linked_community_id_, s); }
  if (var1 & 4194304) { TlStoreBinary::store(pinned_msg_id_, s); }
}

void channel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  int32 var1;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (left_ << 2) | (broadcast_ << 5) | (verified_ << 7) | (megagroup_ << 8) | (restricted_ << 9) | (signatures_ << 11) | (min_ << 12) | (scam_ << 19) | (has_link_ << 20) | (has_geo_ << 21) | (slowmode_enabled_ << 22) | (call_active_ << 23) | (call_not_empty_ << 24) | (fake_ << 25) | (gigagroup_ << 26) | (noforwards_ << 27) | (join_to_send_ << 28) | (join_request_ << 29) | (forum_ << 30) | ((!username_.empty()) << 6) | ((!restriction_reason_.empty()) << 9) | ((admin_rights_ != nullptr) << 14) | ((banned_rights_ != nullptr) << 15) | ((default_banned_rights_ != nullptr) << 18)), s);
  TlStoreBinary::store((var1 = flags2_ | (stories_hidden_ << 1) | (stories_hidden_min_ << 2) | (stories_unavailable_ << 3) | (signature_profiles_ << 12) | (autotranslation_ << 15) | (broadcast_messages_allowed_ << 16) | (monoforum_ << 17) | (forum_tabs_ << 19) | (in_news_ << 21) | (forum_sidebar_ << 23) | ((!usernames_.empty()) << 0) | ((stories_max_id_ != nullptr) << 4) | ((color_ != nullptr) << 7) | ((profile_color_ != nullptr) << 8) | ((emoji_status_ != nullptr) << 9)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 8192) { TlStoreBinary::store(access_hash_, s); }
  TlStoreString::store(title_, s);
  if (var0 & 64) { TlStoreString::store(username_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 512) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -797791052>>, 481674261>::store(restriction_reason_, s); }
  if (var0 & 16384) { TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s); }
  if (var0 & 32768) { TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s); }
  if (var0 & 262144) { TlStoreBoxed<TlStoreObject, -1626209256>::store(default_banned_rights_, s); }
  if (var0 & 131072) { TlStoreBinary::store(participants_count_, s); }
  if (var1 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1274595769>>, 481674261>::store(usernames_, s); }
  if (var1 & 16) { TlStoreBoxed<TlStoreObject, 1897752877>::store(stories_max_id_, s); }
  if (var1 & 128) { TlStoreBoxedUnknown<TlStoreObject>::store(color_, s); }
  if (var1 & 256) { TlStoreBoxedUnknown<TlStoreObject>::store(profile_color_, s); }
  if (var1 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s); }
  if (var1 & 1024) { TlStoreBinary::store(level_, s); }
  if (var1 & 2048) { TlStoreBinary::store(subscription_until_date_, s); }
  if (var1 & 8192) { TlStoreBinary::store(bot_verification_icon_, s); }
  if (var1 & 16384) { TlStoreBinary::store(send_paid_messages_stars_, s); }
  if (var1 & 262144) { TlStoreBinary::store(linked_monoforum_id_, s); }
  if (var1 & 1048576) { TlStoreBinary::store(linked_community_id_, s); }
  if (var1 & 4194304) { TlStoreBinary::store(pinned_msg_id_, s); }
}

void channel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channel");
  int32 var0;
  int32 var1;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | (left_ << 2) | (broadcast_ << 5) | (verified_ << 7) | (megagroup_ << 8) | (restricted_ << 9) | (signatures_ << 11) | (min_ << 12) | (scam_ << 19) | (has_link_ << 20) | (has_geo_ << 21) | (slowmode_enabled_ << 22) | (call_active_ << 23) | (call_not_empty_ << 24) | (fake_ << 25) | (gigagroup_ << 26) | (noforwards_ << 27) | (join_to_send_ << 28) | (join_request_ << 29) | (forum_ << 30) | ((!username_.empty()) << 6) | ((!restriction_reason_.empty()) << 9) | ((admin_rights_ != nullptr) << 14) | ((banned_rights_ != nullptr) << 15) | ((default_banned_rights_ != nullptr) << 18)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 4) { s.store_field("left", true); }
    if (var0 & 32) { s.store_field("broadcast", true); }
    if (var0 & 128) { s.store_field("verified", true); }
    if (var0 & 256) { s.store_field("megagroup", true); }
    if (var0 & 512) { s.store_field("restricted", true); }
    if (var0 & 2048) { s.store_field("signatures", true); }
    if (var0 & 4096) { s.store_field("min", true); }
    if (var0 & 524288) { s.store_field("scam", true); }
    if (var0 & 1048576) { s.store_field("has_link", true); }
    if (var0 & 2097152) { s.store_field("has_geo", true); }
    if (var0 & 4194304) { s.store_field("slowmode_enabled", true); }
    if (var0 & 8388608) { s.store_field("call_active", true); }
    if (var0 & 16777216) { s.store_field("call_not_empty", true); }
    if (var0 & 33554432) { s.store_field("fake", true); }
    if (var0 & 67108864) { s.store_field("gigagroup", true); }
    if (var0 & 134217728) { s.store_field("noforwards", true); }
    if (var0 & 268435456) { s.store_field("join_to_send", true); }
    if (var0 & 536870912) { s.store_field("join_request", true); }
    if (var0 & 1073741824) { s.store_field("forum", true); }
    s.store_field("flags2", (var1 = flags2_ | (stories_hidden_ << 1) | (stories_hidden_min_ << 2) | (stories_unavailable_ << 3) | (signature_profiles_ << 12) | (autotranslation_ << 15) | (broadcast_messages_allowed_ << 16) | (monoforum_ << 17) | (forum_tabs_ << 19) | (in_news_ << 21) | (forum_sidebar_ << 23) | ((!usernames_.empty()) << 0) | ((stories_max_id_ != nullptr) << 4) | ((color_ != nullptr) << 7) | ((profile_color_ != nullptr) << 8) | ((emoji_status_ != nullptr) << 9)));
    if (var1 & 2) { s.store_field("stories_hidden", true); }
    if (var1 & 4) { s.store_field("stories_hidden_min", true); }
    if (var1 & 8) { s.store_field("stories_unavailable", true); }
    if (var1 & 4096) { s.store_field("signature_profiles", true); }
    if (var1 & 32768) { s.store_field("autotranslation", true); }
    if (var1 & 65536) { s.store_field("broadcast_messages_allowed", true); }
    if (var1 & 131072) { s.store_field("monoforum", true); }
    if (var1 & 524288) { s.store_field("forum_tabs", true); }
    if (var1 & 2097152) { s.store_field("in_news", true); }
    if (var1 & 8388608) { s.store_field("forum_sidebar", true); }
    s.store_field("id", id_);
    if (var0 & 8192) { s.store_field("access_hash", access_hash_); }
    s.store_field("title", title_);
    if (var0 & 64) { s.store_field("username", username_); }
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("date", date_);
    if (var0 & 512) { { s.store_vector_begin("restriction_reason", restriction_reason_.size()); for (const auto &_value : restriction_reason_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16384) { s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get())); }
    if (var0 & 32768) { s.store_object_field("banned_rights", static_cast<const BaseObject *>(banned_rights_.get())); }
    if (var0 & 262144) { s.store_object_field("default_banned_rights", static_cast<const BaseObject *>(default_banned_rights_.get())); }
    if (var0 & 131072) { s.store_field("participants_count", participants_count_); }
    if (var1 & 1) { { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var1 & 16) { s.store_object_field("stories_max_id", static_cast<const BaseObject *>(stories_max_id_.get())); }
    if (var1 & 128) { s.store_object_field("color", static_cast<const BaseObject *>(color_.get())); }
    if (var1 & 256) { s.store_object_field("profile_color", static_cast<const BaseObject *>(profile_color_.get())); }
    if (var1 & 512) { s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get())); }
    if (var1 & 1024) { s.store_field("level", level_); }
    if (var1 & 2048) { s.store_field("subscription_until_date", subscription_until_date_); }
    if (var1 & 8192) { s.store_field("bot_verification_icon", bot_verification_icon_); }
    if (var1 & 16384) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    if (var1 & 262144) { s.store_field("linked_monoforum_id", linked_monoforum_id_); }
    if (var1 & 1048576) { s.store_field("linked_community_id", linked_community_id_); }
    if (var1 & 4194304) { s.store_field("pinned_msg_id", pinned_msg_id_); }
    s.store_class_end();
  }
}

channelForbidden::channelForbidden()
  : flags_()
  , broadcast_()
  , megagroup_()
  , monoforum_()
  , id_()
  , access_hash_()
  , title_()
  , until_date_()
{}

channelForbidden::channelForbidden(int32 flags_, bool broadcast_, bool megagroup_, bool monoforum_, int64 id_, int64 access_hash_, string const &title_, int32 until_date_)
  : flags_(flags_)
  , broadcast_(broadcast_)
  , megagroup_(megagroup_)
  , monoforum_(monoforum_)
  , id_(id_)
  , access_hash_(access_hash_)
  , title_(title_)
  , until_date_(until_date_)
{}

const std::int32_t channelForbidden::ID;

object_ptr<Chat> channelForbidden::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelForbidden> res = make_tl_object<channelForbidden>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->broadcast_ = (var0 & 32) != 0;
  res->megagroup_ = (var0 & 256) != 0;
  res->monoforum_ = (var0 & 1024) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 65536) { res->until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelForbidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (broadcast_ << 5) | (megagroup_ << 8) | (monoforum_ << 10)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(title_, s);
  if (var0 & 65536) { TlStoreBinary::store(until_date_, s); }
}

void channelForbidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (broadcast_ << 5) | (megagroup_ << 8) | (monoforum_ << 10)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(title_, s);
  if (var0 & 65536) { TlStoreBinary::store(until_date_, s); }
}

void channelForbidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelForbidden");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (broadcast_ << 5) | (megagroup_ << 8) | (monoforum_ << 10)));
    if (var0 & 32) { s.store_field("broadcast", true); }
    if (var0 & 256) { s.store_field("megagroup", true); }
    if (var0 & 1024) { s.store_field("monoforum", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("title", title_);
    if (var0 & 65536) { s.store_field("until_date", until_date_); }
    s.store_class_end();
  }
}

communityForbidden::communityForbidden()
  : flags_()
  , id_()
  , access_hash_()
  , title_()
{}

communityForbidden::communityForbidden(int32 flags_, int64 id_, int64 access_hash_, string const &title_)
  : flags_(flags_)
  , id_(id_)
  , access_hash_(access_hash_)
  , title_(title_)
{}

const std::int32_t communityForbidden::ID;

object_ptr<Chat> communityForbidden::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<communityForbidden> res = make_tl_object<communityForbidden>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 8192) { res->access_hash_ = TlFetchLong::parse(p); }
  res->title_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void communityForbidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 8192) { TlStoreBinary::store(access_hash_, s); }
  TlStoreString::store(title_, s);
}

void communityForbidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 8192) { TlStoreBinary::store(access_hash_, s); }
  TlStoreString::store(title_, s);
}

void communityForbidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communityForbidden");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    if (var0 & 8192) { s.store_field("access_hash", access_hash_); }
    s.store_field("title", title_);
    s.store_class_end();
  }
}

community::community()
  : flags_()
  , creator_()
  , left_()
  , min_()
  , flags2_()
  , collapsed_in_dialogs_()
  , id_()
  , access_hash_()
  , title_()
  , photo_()
  , date_()
  , admin_rights_()
  , default_banned_rights_()
{}

community::community(int32 flags_, bool creator_, bool left_, bool min_, int32 flags2_, bool collapsed_in_dialogs_, int64 id_, int64 access_hash_, string const &title_, object_ptr<ChatPhoto> &&photo_, int32 date_, object_ptr<chatAdminRights> &&admin_rights_, object_ptr<chatBannedRights> &&default_banned_rights_)
  : flags_(flags_)
  , creator_(creator_)
  , left_(left_)
  , min_(min_)
  , flags2_(flags2_)
  , collapsed_in_dialogs_(collapsed_in_dialogs_)
  , id_(id_)
  , access_hash_(access_hash_)
  , title_(title_)
  , photo_(std::move(photo_))
  , date_(date_)
  , admin_rights_(std::move(admin_rights_))
  , default_banned_rights_(std::move(default_banned_rights_))
{}

const std::int32_t community::ID;

object_ptr<Chat> community::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<community> res = make_tl_object<community>();
  int32 var0;
  int32 var1;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->left_ = (var0 & 4) != 0;
  res->min_ = (var0 & 4096) != 0;
  if ((var1 = res->flags2_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collapsed_in_dialogs_ = (var1 & 1048576) != 0;
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 8192) { res->access_hash_ = TlFetchLong::parse(p); }
  res->title_ = TlFetchString<string>::parse(p);
  res->photo_ = TlFetchObject<ChatPhoto>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 16384) { res->admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 262144) { res->default_banned_rights_ = TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void community::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  int32 var1;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (left_ << 2) | (min_ << 12) | ((admin_rights_ != nullptr) << 14) | ((default_banned_rights_ != nullptr) << 18)), s);
  TlStoreBinary::store((var1 = flags2_ | (collapsed_in_dialogs_ << 20)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 8192) { TlStoreBinary::store(access_hash_, s); }
  TlStoreString::store(title_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 16384) { TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s); }
  if (var0 & 262144) { TlStoreBoxed<TlStoreObject, -1626209256>::store(default_banned_rights_, s); }
}

void community::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  int32 var1;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (left_ << 2) | (min_ << 12) | ((admin_rights_ != nullptr) << 14) | ((default_banned_rights_ != nullptr) << 18)), s);
  TlStoreBinary::store((var1 = flags2_ | (collapsed_in_dialogs_ << 20)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 8192) { TlStoreBinary::store(access_hash_, s); }
  TlStoreString::store(title_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 16384) { TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s); }
  if (var0 & 262144) { TlStoreBoxed<TlStoreObject, -1626209256>::store(default_banned_rights_, s); }
}

void community::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "community");
  int32 var0;
  int32 var1;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | (left_ << 2) | (min_ << 12) | ((admin_rights_ != nullptr) << 14) | ((default_banned_rights_ != nullptr) << 18)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 4) { s.store_field("left", true); }
    if (var0 & 4096) { s.store_field("min", true); }
    s.store_field("flags2", (var1 = flags2_ | (collapsed_in_dialogs_ << 20)));
    if (var1 & 1048576) { s.store_field("collapsed_in_dialogs", true); }
    s.store_field("id", id_);
    if (var0 & 8192) { s.store_field("access_hash", access_hash_); }
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("date", date_);
    if (var0 & 16384) { s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get())); }
    if (var0 & 262144) { s.store_object_field("default_banned_rights", static_cast<const BaseObject *>(default_banned_rights_.get())); }
    s.store_class_end();
  }
}

chatInviteImporter::chatInviteImporter()
  : flags_()
  , requested_()
  , via_chatlist_()
  , user_id_()
  , date_()
  , about_()
  , approved_by_()
{}

const std::int32_t chatInviteImporter::ID;

object_ptr<chatInviteImporter> chatInviteImporter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatInviteImporter> res = make_tl_object<chatInviteImporter>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->requested_ = (var0 & 1) != 0;
  res->via_chatlist_ = (var0 & 8) != 0;
  res->user_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->about_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->approved_by_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void chatInviteImporter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteImporter");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (requested_ << 0) | (via_chatlist_ << 3) | ((!about_.empty()) << 2)));
    if (var0 & 1) { s.store_field("requested", true); }
    if (var0 & 8) { s.store_field("via_chatlist", true); }
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    if (var0 & 4) { s.store_field("about", about_); }
    if (var0 & 2) { s.store_field("approved_by", approved_by_); }
    s.store_class_end();
  }
}

codeSettings::codeSettings(int32 flags_, bool allow_flashcall_, bool current_number_, bool allow_app_hash_, bool allow_missed_call_, bool allow_firebase_, bool unknown_number_, array<bytes> &&logout_tokens_, string const &token_, bool app_sandbox_)
  : flags_(flags_)
  , allow_flashcall_(allow_flashcall_)
  , current_number_(current_number_)
  , allow_app_hash_(allow_app_hash_)
  , allow_missed_call_(allow_missed_call_)
  , allow_firebase_(allow_firebase_)
  , unknown_number_(unknown_number_)
  , logout_tokens_(std::move(logout_tokens_))
  , token_(token_)
  , app_sandbox_(app_sandbox_)
{}

const std::int32_t codeSettings::ID;

void codeSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_flashcall_ << 0) | (current_number_ << 1) | (allow_app_hash_ << 4) | (allow_missed_call_ << 5) | (allow_firebase_ << 7) | (unknown_number_ << 9) | ((!logout_tokens_.empty()) << 6) | ((!token_.empty()) << 8)), s);
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(logout_tokens_, s); }
  if (var0 & 256) { TlStoreString::store(token_, s); }
  if (var0 & 256) { TlStoreBool::store(app_sandbox_, s); }
}

void codeSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_flashcall_ << 0) | (current_number_ << 1) | (allow_app_hash_ << 4) | (allow_missed_call_ << 5) | (allow_firebase_ << 7) | (unknown_number_ << 9) | ((!logout_tokens_.empty()) << 6) | ((!token_.empty()) << 8)), s);
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(logout_tokens_, s); }
  if (var0 & 256) { TlStoreString::store(token_, s); }
  if (var0 & 256) { TlStoreBool::store(app_sandbox_, s); }
}

void codeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "codeSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (allow_flashcall_ << 0) | (current_number_ << 1) | (allow_app_hash_ << 4) | (allow_missed_call_ << 5) | (allow_firebase_ << 7) | (unknown_number_ << 9) | ((!logout_tokens_.empty()) << 6) | ((!token_.empty()) << 8)));
    if (var0 & 1) { s.store_field("allow_flashcall", true); }
    if (var0 & 2) { s.store_field("current_number", true); }
    if (var0 & 16) { s.store_field("allow_app_hash", true); }
    if (var0 & 32) { s.store_field("allow_missed_call", true); }
    if (var0 & 128) { s.store_field("allow_firebase", true); }
    if (var0 & 512) { s.store_field("unknown_number", true); }
    if (var0 & 64) { s.store_field("logout_tokens", "[REDACTED]"); }
    if (var0 & 256) { s.store_field("token", "[REDACTED]"); }
    if (var0 & 256) { s.store_field("app_sandbox", app_sandbox_); }
    s.store_class_end();
  }
}

const std::int32_t error::ID;

object_ptr<error> error::fetch(TlBufferParser &p) {
  return make_tl_object<error>(p);
}

error::error(TlBufferParser &p)
  : code_(TlFetchInt::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void error::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "error");
    s.store_field("code", code_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

const std::int32_t fileHash::ID;

object_ptr<fileHash> fileHash::fetch(TlBufferParser &p) {
  return make_tl_object<fileHash>(p);
}

fileHash::fileHash(TlBufferParser &p)
  : offset_(TlFetchLong::parse(p))
  , limit_(TlFetchInt::parse(p))
  , hash_(TlFetchBytes<bytes>::parse(p))
{}

void fileHash::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileHash");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_bytes_field("hash", hash_);
    s.store_class_end();
  }
}

const std::int32_t foundStory::ID;

object_ptr<foundStory> foundStory::fetch(TlBufferParser &p) {
  return make_tl_object<foundStory>(p);
}

foundStory::foundStory(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , story_(TlFetchObject<StoryItem>::parse(p))
{}

void foundStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

groupCallParticipant::groupCallParticipant()
  : flags_()
  , muted_()
  , left_()
  , can_self_unmute_()
  , just_joined_()
  , versioned_()
  , min_()
  , muted_by_you_()
  , volume_by_admin_()
  , self_()
  , video_joined_()
  , peer_()
  , date_()
  , active_date_()
  , source_()
  , volume_()
  , about_()
  , raise_hand_rating_()
  , video_()
  , presentation_()
  , paid_stars_total_()
{}

const std::int32_t groupCallParticipant::ID;

object_ptr<groupCallParticipant> groupCallParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<groupCallParticipant> res = make_tl_object<groupCallParticipant>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->muted_ = (var0 & 1) != 0;
  res->left_ = (var0 & 2) != 0;
  res->can_self_unmute_ = (var0 & 4) != 0;
  res->just_joined_ = (var0 & 16) != 0;
  res->versioned_ = (var0 & 32) != 0;
  res->min_ = (var0 & 256) != 0;
  res->muted_by_you_ = (var0 & 512) != 0;
  res->volume_by_admin_ = (var0 & 1024) != 0;
  res->self_ = (var0 & 4096) != 0;
  res->video_joined_ = (var0 & 32768) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->active_date_ = TlFetchInt::parse(p); }
  res->source_ = TlFetchInt::parse(p);
  if (var0 & 128) { res->volume_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->about_ = TlFetchString<string>::parse(p); }
  if (var0 & 8192) { res->raise_hand_rating_ = TlFetchLong::parse(p); }
  if (var0 & 64) { res->video_ = TlFetchBoxed<TlFetchObject<groupCallParticipantVideo>, 1735736008>::parse(p); }
  if (var0 & 16384) { res->presentation_ = TlFetchBoxed<TlFetchObject<groupCallParticipantVideo>, 1735736008>::parse(p); }
  if (var0 & 65536) { res->paid_stars_total_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void groupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipant");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (muted_ << 0) | (left_ << 1) | (can_self_unmute_ << 2) | (just_joined_ << 4) | (versioned_ << 5) | (min_ << 8) | (muted_by_you_ << 9) | (volume_by_admin_ << 10) | (self_ << 12) | (video_joined_ << 15) | ((!about_.empty()) << 11) | ((video_ != nullptr) << 6) | ((presentation_ != nullptr) << 14)));
    if (var0 & 1) { s.store_field("muted", true); }
    if (var0 & 2) { s.store_field("left", true); }
    if (var0 & 4) { s.store_field("can_self_unmute", true); }
    if (var0 & 16) { s.store_field("just_joined", true); }
    if (var0 & 32) { s.store_field("versioned", true); }
    if (var0 & 256) { s.store_field("min", true); }
    if (var0 & 512) { s.store_field("muted_by_you", true); }
    if (var0 & 1024) { s.store_field("volume_by_admin", true); }
    if (var0 & 4096) { s.store_field("self", true); }
    if (var0 & 32768) { s.store_field("video_joined", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("date", date_);
    if (var0 & 8) { s.store_field("active_date", active_date_); }
    s.store_field("source", source_);
    if (var0 & 128) { s.store_field("volume", volume_); }
    if (var0 & 2048) { s.store_field("about", about_); }
    if (var0 & 8192) { s.store_field("raise_hand_rating", raise_hand_rating_); }
    if (var0 & 64) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    if (var0 & 16384) { s.store_object_field("presentation", static_cast<const BaseObject *>(presentation_.get())); }
    if (var0 & 65536) { s.store_field("paid_stars_total", paid_stars_total_); }
    s.store_class_end();
  }
}

groupCallParticipantVideo::groupCallParticipantVideo()
  : flags_()
  , paused_()
  , endpoint_()
  , source_groups_()
  , audio_source_()
{}

const std::int32_t groupCallParticipantVideo::ID;

object_ptr<groupCallParticipantVideo> groupCallParticipantVideo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<groupCallParticipantVideo> res = make_tl_object<groupCallParticipantVideo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->paused_ = (var0 & 1) != 0;
  res->endpoint_ = TlFetchString<string>::parse(p);
  res->source_groups_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallParticipantVideoSourceGroup>, -592373577>>, 481674261>::parse(p);
  if (var0 & 2) { res->audio_source_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void groupCallParticipantVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipantVideo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (paused_ << 0)));
    if (var0 & 1) { s.store_field("paused", true); }
    s.store_field("endpoint", endpoint_);
    { s.store_vector_begin("source_groups", source_groups_.size()); for (const auto &_value : source_groups_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 2) { s.store_field("audio_source", audio_source_); }
    s.store_class_end();
  }
}

object_ptr<InlineButtonType> InlineButtonType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inlineButtonTypeUrl::inlineButtonTypeUrl(string const &url_)
  : url_(url_)
{}

const std::int32_t inlineButtonTypeUrl::ID;

object_ptr<InlineButtonType> inlineButtonTypeUrl::fetch(TlBufferParser &p) {
  return make_tl_object<inlineButtonTypeUrl>(p);
}

inlineButtonTypeUrl::inlineButtonTypeUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void inlineButtonTypeUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
}

void inlineButtonTypeUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
}

void inlineButtonTypeUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineButtonTypeUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inlineButtonTypeUrlAuth::inlineButtonTypeUrlAuth()
  : flags_()
  , fwd_text_()
  , url_()
  , button_id_()
{}

inlineButtonTypeUrlAuth::inlineButtonTypeUrlAuth(int32 flags_, string const &fwd_text_, string const &url_, int32 button_id_)
  : flags_(flags_)
  , fwd_text_(fwd_text_)
  , url_(url_)
  , button_id_(button_id_)
{}

const std::int32_t inlineButtonTypeUrlAuth::ID;

object_ptr<InlineButtonType> inlineButtonTypeUrlAuth::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inlineButtonTypeUrlAuth> res = make_tl_object<inlineButtonTypeUrlAuth>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->fwd_text_ = TlFetchString<string>::parse(p); }
  res->url_ = TlFetchString<string>::parse(p);
  res->button_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inlineButtonTypeUrlAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!fwd_text_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(fwd_text_, s); }
  TlStoreString::store(url_, s);
  TlStoreBinary::store(button_id_, s);
}

void inlineButtonTypeUrlAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!fwd_text_.empty()) << 0)), s);
  if (var0 & 1) { TlStoreString::store(fwd_text_, s); }
  TlStoreString::store(url_, s);
  TlStoreBinary::store(button_id_, s);
}

void inlineButtonTypeUrlAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineButtonTypeUrlAuth");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!fwd_text_.empty()) << 0)));
    if (var0 & 1) { s.store_field("fwd_text", fwd_text_); }
    s.store_field("url", url_);
    s.store_field("button_id", button_id_);
    s.store_class_end();
  }
}

inputInlineButtonTypeUrlAuth::inputInlineButtonTypeUrlAuth()
  : flags_()
  , request_write_access_()
  , fwd_text_()
  , url_()
  , bot_()
{}

inputInlineButtonTypeUrlAuth::inputInlineButtonTypeUrlAuth(int32 flags_, bool request_write_access_, string const &fwd_text_, string const &url_, object_ptr<InputUser> &&bot_)
  : flags_(flags_)
  , request_write_access_(request_write_access_)
  , fwd_text_(fwd_text_)
  , url_(url_)
  , bot_(std::move(bot_))
{}

const std::int32_t inputInlineButtonTypeUrlAuth::ID;

object_ptr<InlineButtonType> inputInlineButtonTypeUrlAuth::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputInlineButtonTypeUrlAuth> res = make_tl_object<inputInlineButtonTypeUrlAuth>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->request_write_access_ = (var0 & 1) != 0;
  if (var0 & 2) { res->fwd_text_ = TlFetchString<string>::parse(p); }
  res->url_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->bot_ = TlFetchObject<InputUser>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputInlineButtonTypeUrlAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (request_write_access_ << 0) | ((!fwd_text_.empty()) << 1) | ((bot_ != nullptr) << 2)), s);
  if (var0 & 2) { TlStoreString::store(fwd_text_, s); }
  TlStoreString::store(url_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
}

void inputInlineButtonTypeUrlAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (request_write_access_ << 0) | ((!fwd_text_.empty()) << 1) | ((bot_ != nullptr) << 2)), s);
  if (var0 & 2) { TlStoreString::store(fwd_text_, s); }
  TlStoreString::store(url_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
}

void inputInlineButtonTypeUrlAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineButtonTypeUrlAuth");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (request_write_access_ << 0) | ((!fwd_text_.empty()) << 1) | ((bot_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("request_write_access", true); }
    if (var0 & 2) { s.store_field("fwd_text", fwd_text_); }
    s.store_field("url", url_);
    if (var0 & 4) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    s.store_class_end();
  }
}

inlineButtonTypeWebView::inlineButtonTypeWebView(string const &url_)
  : url_(url_)
{}

const std::int32_t inlineButtonTypeWebView::ID;

object_ptr<InlineButtonType> inlineButtonTypeWebView::fetch(TlBufferParser &p) {
  return make_tl_object<inlineButtonTypeWebView>(p);
}

inlineButtonTypeWebView::inlineButtonTypeWebView(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void inlineButtonTypeWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
}

void inlineButtonTypeWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
}

void inlineButtonTypeWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineButtonTypeWebView");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inlineButtonTypeCallback::inlineButtonTypeCallback()
  : flags_()
  , requires_password_()
  , data_()
{}

inlineButtonTypeCallback::inlineButtonTypeCallback(int32 flags_, bool requires_password_, bytes &&data_)
  : flags_(flags_)
  , requires_password_(requires_password_)
  , data_(std::move(data_))
{}

const std::int32_t inlineButtonTypeCallback::ID;

object_ptr<InlineButtonType> inlineButtonTypeCallback::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inlineButtonTypeCallback> res = make_tl_object<inlineButtonTypeCallback>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->requires_password_ = (var0 & 1) != 0;
  res->data_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inlineButtonTypeCallback::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (requires_password_ << 0)), s);
  TlStoreString::store(data_, s);
}

void inlineButtonTypeCallback::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (requires_password_ << 0)), s);
  TlStoreString::store(data_, s);
}

void inlineButtonTypeCallback::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineButtonTypeCallback");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (requires_password_ << 0)));
    if (var0 & 1) { s.store_field("requires_password", true); }
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

const std::int32_t inlineButtonTypeGame::ID;

object_ptr<InlineButtonType> inlineButtonTypeGame::fetch(TlBufferParser &p) {
  return make_tl_object<inlineButtonTypeGame>();
}

void inlineButtonTypeGame::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineButtonTypeGame::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineButtonTypeGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineButtonTypeGame");
    s.store_class_end();
  }
}

const std::int32_t inlineButtonTypeBuy::ID;

object_ptr<InlineButtonType> inlineButtonTypeBuy::fetch(TlBufferParser &p) {
  return make_tl_object<inlineButtonTypeBuy>();
}

void inlineButtonTypeBuy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineButtonTypeBuy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineButtonTypeBuy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineButtonTypeBuy");
    s.store_class_end();
  }
}

inlineButtonTypeSwitchInline::inlineButtonTypeSwitchInline()
  : flags_()
  , same_peer_()
  , query_()
  , peer_types_()
{}

inlineButtonTypeSwitchInline::inlineButtonTypeSwitchInline(int32 flags_, bool same_peer_, string const &query_, array<object_ptr<InlineQueryPeerType>> &&peer_types_)
  : flags_(flags_)
  , same_peer_(same_peer_)
  , query_(query_)
  , peer_types_(std::move(peer_types_))
{}

const std::int32_t inlineButtonTypeSwitchInline::ID;

object_ptr<InlineButtonType> inlineButtonTypeSwitchInline::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inlineButtonTypeSwitchInline> res = make_tl_object<inlineButtonTypeSwitchInline>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->same_peer_ = (var0 & 1) != 0;
  res->query_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->peer_types_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InlineQueryPeerType>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inlineButtonTypeSwitchInline::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (same_peer_ << 0) | ((!peer_types_.empty()) << 1)), s);
  TlStoreString::store(query_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peer_types_, s); }
}

void inlineButtonTypeSwitchInline::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (same_peer_ << 0) | ((!peer_types_.empty()) << 1)), s);
  TlStoreString::store(query_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peer_types_, s); }
}

void inlineButtonTypeSwitchInline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineButtonTypeSwitchInline");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (same_peer_ << 0) | ((!peer_types_.empty()) << 1)));
    if (var0 & 1) { s.store_field("same_peer", true); }
    s.store_field("query", query_);
    if (var0 & 2) { { s.store_vector_begin("peer_types", peer_types_.size()); for (const auto &_value : peer_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

inlineButtonTypeUserProfile::inlineButtonTypeUserProfile(int64 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t inlineButtonTypeUserProfile::ID;

object_ptr<InlineButtonType> inlineButtonTypeUserProfile::fetch(TlBufferParser &p) {
  return make_tl_object<inlineButtonTypeUserProfile>(p);
}

inlineButtonTypeUserProfile::inlineButtonTypeUserProfile(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
{}

void inlineButtonTypeUserProfile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
}

void inlineButtonTypeUserProfile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
}

void inlineButtonTypeUserProfile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineButtonTypeUserProfile");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

inputInlineButtonTypeUserProfile::inputInlineButtonTypeUserProfile(object_ptr<InputUser> &&user_id_)
  : user_id_(std::move(user_id_))
{}

const std::int32_t inputInlineButtonTypeUserProfile::ID;

object_ptr<InlineButtonType> inputInlineButtonTypeUserProfile::fetch(TlBufferParser &p) {
  return make_tl_object<inputInlineButtonTypeUserProfile>(p);
}

inputInlineButtonTypeUserProfile::inputInlineButtonTypeUserProfile(TlBufferParser &p)
  : user_id_(TlFetchObject<InputUser>::parse(p))
{}

void inputInlineButtonTypeUserProfile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void inputInlineButtonTypeUserProfile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void inputInlineButtonTypeUserProfile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineButtonTypeUserProfile");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

inlineButtonTypeCopy::inlineButtonTypeCopy(string const &copy_text_)
  : copy_text_(copy_text_)
{}

const std::int32_t inlineButtonTypeCopy::ID;

object_ptr<InlineButtonType> inlineButtonTypeCopy::fetch(TlBufferParser &p) {
  return make_tl_object<inlineButtonTypeCopy>(p);
}

inlineButtonTypeCopy::inlineButtonTypeCopy(TlBufferParser &p)
  : copy_text_(TlFetchString<string>::parse(p))
{}

void inlineButtonTypeCopy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(copy_text_, s);
}

void inlineButtonTypeCopy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(copy_text_, s);
}

void inlineButtonTypeCopy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineButtonTypeCopy");
    s.store_field("copy_text", copy_text_);
    s.store_class_end();
  }
}

const std::int32_t inlineButtonTypeDisabled::ID;

object_ptr<InlineButtonType> inlineButtonTypeDisabled::fetch(TlBufferParser &p) {
  return make_tl_object<inlineButtonTypeDisabled>();
}

void inlineButtonTypeDisabled::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineButtonTypeDisabled::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineButtonTypeDisabled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineButtonTypeDisabled");
    s.store_class_end();
  }
}

inputBotInlineMessageMediaAuto::inputBotInlineMessageMediaAuto(int32 flags_, bool invert_media_, string const &message_, array<object_ptr<MessageEntity>> &&entities_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , invert_media_(invert_media_)
  , message_(message_)
  , entities_(std::move(entities_))
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaAuto::ID;

void inputBotInlineMessageMediaAuto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 3) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaAuto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 3) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaAuto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaAuto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 3) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)));
    if (var0 & 8) { s.store_field("invert_media", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageText::inputBotInlineMessageText(int32 flags_, bool no_webpage_, bool invert_media_, string const &message_, array<object_ptr<MessageEntity>> &&entities_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , no_webpage_(no_webpage_)
  , invert_media_(invert_media_)
  , message_(message_)
  , entities_(std::move(entities_))
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageText::ID;

void inputBotInlineMessageText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 0) | (invert_media_ << 3) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 0) | (invert_media_ << 3) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageText");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 0) | (invert_media_ << 3) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("no_webpage", true); }
    if (var0 & 8) { s.store_field("invert_media", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageMediaGeo::inputBotInlineMessageMediaGeo(int32 flags_, object_ptr<InputGeoPoint> &&geo_point_, int32 heading_, int32 period_, int32 proximity_notification_radius_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , geo_point_(std::move(geo_point_))
  , heading_(heading_)
  , period_(period_)
  , proximity_notification_radius_(proximity_notification_radius_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaGeo::ID;

void inputBotInlineMessageMediaGeo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 1) { TlStoreBinary::store(heading_, s); }
  if (var0 & 2) { TlStoreBinary::store(period_, s); }
  if (var0 & 8) { TlStoreBinary::store(proximity_notification_radius_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaGeo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 1) { TlStoreBinary::store(heading_, s); }
  if (var0 & 2) { TlStoreBinary::store(period_, s); }
  if (var0 & 8) { TlStoreBinary::store(proximity_notification_radius_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaGeo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaGeo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_markup_ != nullptr) << 2)));
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    if (var0 & 1) { s.store_field("heading", heading_); }
    if (var0 & 2) { s.store_field("period", period_); }
    if (var0 & 8) { s.store_field("proximity_notification_radius", proximity_notification_radius_); }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageMediaVenue::inputBotInlineMessageMediaVenue(int32 flags_, object_ptr<InputGeoPoint> &&geo_point_, string const &title_, string const &address_, string const &provider_, string const &venue_id_, string const &venue_type_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , geo_point_(std::move(geo_point_))
  , title_(title_)
  , address_(address_)
  , provider_(provider_)
  , venue_id_(venue_id_)
  , venue_type_(venue_type_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaVenue::ID;

void inputBotInlineMessageMediaVenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaVenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaVenue");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_markup_ != nullptr) << 2)));
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("venue_type", venue_type_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageMediaContact::inputBotInlineMessageMediaContact(int32 flags_, string const &phone_number_, string const &first_name_, string const &last_name_, string const &vcard_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , phone_number_(phone_number_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , vcard_(vcard_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaContact::ID;

void inputBotInlineMessageMediaContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaContact");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_markup_ != nullptr) << 2)));
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("vcard", vcard_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageGame::inputBotInlineMessageGame(int32 flags_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageGame::ID;

void inputBotInlineMessageGame::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_markup_ != nullptr) << 2)), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageGame::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_markup_ != nullptr) << 2)), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageGame");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_markup_ != nullptr) << 2)));
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageMediaInvoice::inputBotInlineMessageMediaInvoice(int32 flags_, string const &title_, string const &description_, object_ptr<inputWebDocument> &&photo_, object_ptr<invoice> &&invoice_, bytes &&payload_, string const &provider_, object_ptr<dataJSON> &&provider_data_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , invoice_(std::move(invoice_))
  , payload_(std::move(payload_))
  , provider_(provider_)
  , provider_data_(std::move(provider_data_))
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaInvoice::ID;

void inputBotInlineMessageMediaInvoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((photo_ != nullptr) << 0) | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1678949555>::store(photo_, s); }
  TlStoreBoxed<TlStoreObject, 77522308>::store(invoice_, s);
  TlStoreString::store(payload_, s);
  TlStoreString::store(provider_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(provider_data_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaInvoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((photo_ != nullptr) << 0) | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1678949555>::store(photo_, s); }
  TlStoreBoxed<TlStoreObject, 77522308>::store(invoice_, s);
  TlStoreString::store(payload_, s);
  TlStoreString::store(provider_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(provider_data_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaInvoice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((photo_ != nullptr) << 0) | ((reply_markup_ != nullptr) << 2)));
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_bytes_field("payload", payload_);
    s.store_field("provider", provider_);
    s.store_object_field("provider_data", static_cast<const BaseObject *>(provider_data_.get()));
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageMediaWebPage::inputBotInlineMessageMediaWebPage(int32 flags_, bool invert_media_, bool force_large_media_, bool force_small_media_, bool optional_, string const &message_, array<object_ptr<MessageEntity>> &&entities_, string const &url_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , invert_media_(invert_media_)
  , force_large_media_(force_large_media_)
  , force_small_media_(force_small_media_)
  , optional_(optional_)
  , message_(message_)
  , entities_(std::move(entities_))
  , url_(url_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaWebPage::ID;

void inputBotInlineMessageMediaWebPage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 3) | (force_large_media_ << 4) | (force_small_media_ << 5) | (optional_ << 6) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreString::store(url_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaWebPage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 3) | (force_large_media_ << 4) | (force_small_media_ << 5) | (optional_ << 6) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreString::store(url_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaWebPage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 3) | (force_large_media_ << 4) | (force_small_media_ << 5) | (optional_ << 6) | ((!entities_.empty()) << 1) | ((reply_markup_ != nullptr) << 2)));
    if (var0 & 8) { s.store_field("invert_media", true); }
    if (var0 & 16) { s.store_field("force_large_media", true); }
    if (var0 & 32) { s.store_field("force_small_media", true); }
    if (var0 & 64) { s.store_field("optional", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("url", url_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageRichMessage::inputBotInlineMessageRichMessage(int32 flags_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputRichMessage> &&rich_message_)
  : flags_(flags_)
  , reply_markup_(std::move(reply_markup_))
  , rich_message_(std::move(rich_message_))
{}

const std::int32_t inputBotInlineMessageRichMessage::ID;

void inputBotInlineMessageRichMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_markup_ != nullptr) << 2)), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s);
}

void inputBotInlineMessageRichMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((reply_markup_ != nullptr) << 2)), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s);
}

void inputBotInlineMessageRichMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageRichMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((reply_markup_ != nullptr) << 2)));
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get()));
    s.store_class_end();
  }
}

inputBotInlineMessageWidget::inputBotInlineMessageWidget(int32 flags_, bool allow_queries_, bool shared_widget_, bool invert_media_, int32 width_, int32 height_, string const &html_, string const &public_data_, string const &chat_data_, object_ptr<ReplyMarkup> &&reply_markup_, string const &message_, array<object_ptr<MessageEntity>> &&entities_)
  : flags_(flags_)
  , allow_queries_(allow_queries_)
  , shared_widget_(shared_widget_)
  , invert_media_(invert_media_)
  , width_(width_)
  , height_(height_)
  , html_(html_)
  , public_data_(public_data_)
  , chat_data_(chat_data_)
  , reply_markup_(std::move(reply_markup_))
  , message_(message_)
  , entities_(std::move(entities_))
{}

const std::int32_t inputBotInlineMessageWidget::ID;

void inputBotInlineMessageWidget::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_queries_ << 0) | (shared_widget_ << 1) | (invert_media_ << 6) | ((!public_data_.empty()) << 2) | ((!chat_data_.empty()) << 3) | ((reply_markup_ != nullptr) << 4) | ((!entities_.empty()) << 5)), s);
  TlStoreBinary::store(width_, s);
  TlStoreBinary::store(height_, s);
  TlStoreString::store(html_, s);
  if (var0 & 4) { TlStoreString::store(public_data_, s); }
  if (var0 & 8) { TlStoreString::store(chat_data_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  TlStoreString::store(message_, s);
  if (var0 & 32) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void inputBotInlineMessageWidget::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_queries_ << 0) | (shared_widget_ << 1) | (invert_media_ << 6) | ((!public_data_.empty()) << 2) | ((!chat_data_.empty()) << 3) | ((reply_markup_ != nullptr) << 4) | ((!entities_.empty()) << 5)), s);
  TlStoreBinary::store(width_, s);
  TlStoreBinary::store(height_, s);
  TlStoreString::store(html_, s);
  if (var0 & 4) { TlStoreString::store(public_data_, s); }
  if (var0 & 8) { TlStoreString::store(chat_data_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  TlStoreString::store(message_, s);
  if (var0 & 32) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void inputBotInlineMessageWidget::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageWidget");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (allow_queries_ << 0) | (shared_widget_ << 1) | (invert_media_ << 6) | ((!public_data_.empty()) << 2) | ((!chat_data_.empty()) << 3) | ((reply_markup_ != nullptr) << 4) | ((!entities_.empty()) << 5)));
    if (var0 & 1) { s.store_field("allow_queries", true); }
    if (var0 & 2) { s.store_field("shared_widget", true); }
    if (var0 & 64) { s.store_field("invert_media", true); }
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("html", html_);
    if (var0 & 4) { s.store_field("public_data", public_data_); }
    if (var0 & 8) { s.store_field("chat_data", chat_data_); }
    if (var0 & 16) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_field("message", message_);
    if (var0 & 32) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

inputBotInlineMessageWidgetId::inputBotInlineMessageWidgetId(int32 flags_, bool invert_media_, int64 widget_id_, string const &chat_data_, object_ptr<ReplyMarkup> &&reply_markup_, string const &message_, array<object_ptr<MessageEntity>> &&entities_)
  : flags_(flags_)
  , invert_media_(invert_media_)
  , widget_id_(widget_id_)
  , chat_data_(chat_data_)
  , reply_markup_(std::move(reply_markup_))
  , message_(message_)
  , entities_(std::move(entities_))
{}

const std::int32_t inputBotInlineMessageWidgetId::ID;

void inputBotInlineMessageWidgetId::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 3) | ((!chat_data_.empty()) << 0) | ((reply_markup_ != nullptr) << 1) | ((!entities_.empty()) << 2)), s);
  TlStoreBinary::store(widget_id_, s);
  if (var0 & 1) { TlStoreString::store(chat_data_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  TlStoreString::store(message_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void inputBotInlineMessageWidgetId::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 3) | ((!chat_data_.empty()) << 0) | ((reply_markup_ != nullptr) << 1) | ((!entities_.empty()) << 2)), s);
  TlStoreBinary::store(widget_id_, s);
  if (var0 & 1) { TlStoreString::store(chat_data_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  TlStoreString::store(message_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void inputBotInlineMessageWidgetId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageWidgetId");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 3) | ((!chat_data_.empty()) << 0) | ((reply_markup_ != nullptr) << 1) | ((!entities_.empty()) << 2)));
    if (var0 & 8) { s.store_field("invert_media", true); }
    s.store_field("widget_id", widget_id_);
    if (var0 & 1) { s.store_field("chat_data", chat_data_); }
    if (var0 & 2) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_field("message", message_);
    if (var0 & 4) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t inputChatThemeEmpty::ID;

void inputChatThemeEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputChatThemeEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputChatThemeEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatThemeEmpty");
    s.store_class_end();
  }
}

inputChatTheme::inputChatTheme(string const &emoticon_)
  : emoticon_(emoticon_)
{}

const std::int32_t inputChatTheme::ID;

void inputChatTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputChatTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatTheme");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

inputChatThemeUniqueGift::inputChatThemeUniqueGift(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputChatThemeUniqueGift::ID;

void inputChatThemeUniqueGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputChatThemeUniqueGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputChatThemeUniqueGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatThemeUniqueGift");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

object_ptr<InputGeoPoint> InputGeoPoint::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputGeoPointEmpty::ID:
      return inputGeoPointEmpty::fetch(p);
    case inputGeoPoint::ID:
      return inputGeoPoint::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputGeoPointEmpty::ID;

object_ptr<InputGeoPoint> inputGeoPointEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputGeoPointEmpty>();
}

void inputGeoPointEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputGeoPointEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputGeoPointEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGeoPointEmpty");
    s.store_class_end();
  }
}

inputGeoPoint::inputGeoPoint()
  : flags_()
  , lat_()
  , long_()
  , accuracy_radius_()
{}

inputGeoPoint::inputGeoPoint(int32 flags_, double lat_, double long_, int32 accuracy_radius_)
  : flags_(flags_)
  , lat_(lat_)
  , long_(long_)
  , accuracy_radius_(accuracy_radius_)
{}

const std::int32_t inputGeoPoint::ID;

object_ptr<InputGeoPoint> inputGeoPoint::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputGeoPoint> res = make_tl_object<inputGeoPoint>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->lat_ = TlFetchDouble::parse(p);
  res->long_ = TlFetchDouble::parse(p);
  if (var0 & 1) { res->accuracy_radius_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputGeoPoint::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(lat_, s);
  TlStoreBinary::store(long_, s);
  if (var0 & 1) { TlStoreBinary::store(accuracy_radius_, s); }
}

void inputGeoPoint::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(lat_, s);
  TlStoreBinary::store(long_, s);
  if (var0 & 1) { TlStoreBinary::store(accuracy_radius_, s); }
}

void inputGeoPoint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGeoPoint");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("lat", lat_);
    s.store_field("long", long_);
    if (var0 & 1) { s.store_field("accuracy_radius", accuracy_radius_); }
    s.store_class_end();
  }
}

object_ptr<InputRichFile> InputRichFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputRichFilePhoto::ID:
      return inputRichFilePhoto::fetch(p);
    case inputRichFileDocument::ID:
      return inputRichFileDocument::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputRichFilePhoto::inputRichFilePhoto(string const &id_, object_ptr<InputPhoto> &&photo_)
  : id_(id_)
  , photo_(std::move(photo_))
{}

const std::int32_t inputRichFilePhoto::ID;

object_ptr<InputRichFile> inputRichFilePhoto::fetch(TlBufferParser &p) {
  return make_tl_object<inputRichFilePhoto>(p);
}

inputRichFilePhoto::inputRichFilePhoto(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , photo_(TlFetchObject<InputPhoto>::parse(p))
{}

void inputRichFilePhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
}

void inputRichFilePhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
}

void inputRichFilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputRichFilePhoto");
    s.store_field("id", id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

inputRichFileDocument::inputRichFileDocument(string const &id_, object_ptr<InputDocument> &&document_)
  : id_(id_)
  , document_(std::move(document_))
{}

const std::int32_t inputRichFileDocument::ID;

object_ptr<InputRichFile> inputRichFileDocument::fetch(TlBufferParser &p) {
  return make_tl_object<inputRichFileDocument>(p);
}

inputRichFileDocument::inputRichFileDocument(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , document_(TlFetchObject<InputDocument>::parse(p))
{}

void inputRichFileDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
}

void inputRichFileDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
}

void inputRichFileDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputRichFileDocument");
    s.store_field("id", id_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_class_end();
  }
}

inputSecureFileUploaded::inputSecureFileUploaded(int64 id_, int32 parts_, string const &md5_checksum_, bytes &&file_hash_, bytes &&secret_)
  : id_(id_)
  , parts_(parts_)
  , md5_checksum_(md5_checksum_)
  , file_hash_(std::move(file_hash_))
  , secret_(std::move(secret_))
{}

const std::int32_t inputSecureFileUploaded::ID;

void inputSecureFileUploaded::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(md5_checksum_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(secret_, s);
}

void inputSecureFileUploaded::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(md5_checksum_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(secret_, s);
}

void inputSecureFileUploaded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSecureFileUploaded");
    s.store_field("id", id_);
    s.store_field("parts", parts_);
    s.store_field("md5_checksum", md5_checksum_);
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("secret", "[REDACTED]");
    s.store_class_end();
  }
}

inputSecureFile::inputSecureFile(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputSecureFile::ID;

void inputSecureFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputSecureFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputSecureFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSecureFile");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputStorePaymentPremiumSubscription::inputStorePaymentPremiumSubscription(int32 flags_, bool restore_, bool upgrade_)
  : flags_(flags_)
  , restore_(restore_)
  , upgrade_(upgrade_)
{}

const std::int32_t inputStorePaymentPremiumSubscription::ID;

void inputStorePaymentPremiumSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0) | (upgrade_ << 1)), s);
}

void inputStorePaymentPremiumSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0) | (upgrade_ << 1)), s);
}

void inputStorePaymentPremiumSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentPremiumSubscription");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (restore_ << 0) | (upgrade_ << 1)));
    if (var0 & 1) { s.store_field("restore", true); }
    if (var0 & 2) { s.store_field("upgrade", true); }
    s.store_class_end();
  }
}

inputStorePaymentGiftPremium::inputStorePaymentGiftPremium(object_ptr<InputUser> &&user_id_, string const &currency_, int64 amount_)
  : user_id_(std::move(user_id_))
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t inputStorePaymentGiftPremium::ID;

void inputStorePaymentGiftPremium::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentGiftPremium::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentGiftPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentGiftPremium");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

inputStorePaymentPremiumGiftCode::inputStorePaymentPremiumGiftCode(int32 flags_, array<object_ptr<InputUser>> &&users_, object_ptr<InputPeer> &&boost_peer_, string const &currency_, int64 amount_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , users_(std::move(users_))
  , boost_peer_(std::move(boost_peer_))
  , currency_(currency_)
  , amount_(amount_)
  , message_(std::move(message_))
{}

const std::int32_t inputStorePaymentPremiumGiftCode::ID;

void inputStorePaymentPremiumGiftCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((boost_peer_ != nullptr) << 0) | ((message_ != nullptr) << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputStorePaymentPremiumGiftCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((boost_peer_ != nullptr) << 0) | ((message_ != nullptr) << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputStorePaymentPremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentPremiumGiftCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((boost_peer_ != nullptr) << 0) | ((message_ != nullptr) << 1)));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get())); }
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

inputStorePaymentPremiumGiveaway::inputStorePaymentPremiumGiveaway(int32 flags_, bool only_new_subscribers_, bool winners_are_visible_, object_ptr<InputPeer> &&boost_peer_, array<object_ptr<InputPeer>> &&additional_peers_, array<string> &&countries_iso2_, string const &prize_description_, int64 random_id_, int32 until_date_, string const &currency_, int64 amount_)
  : flags_(flags_)
  , only_new_subscribers_(only_new_subscribers_)
  , winners_are_visible_(winners_are_visible_)
  , boost_peer_(std::move(boost_peer_))
  , additional_peers_(std::move(additional_peers_))
  , countries_iso2_(std::move(countries_iso2_))
  , prize_description_(prize_description_)
  , random_id_(random_id_)
  , until_date_(until_date_)
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t inputStorePaymentPremiumGiveaway::ID;

void inputStorePaymentPremiumGiveaway::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3) | ((!additional_peers_.empty()) << 1) | ((!countries_iso2_.empty()) << 2) | ((!prize_description_.empty()) << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(additional_peers_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 16) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(until_date_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentPremiumGiveaway::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3) | ((!additional_peers_.empty()) << 1) | ((!countries_iso2_.empty()) << 2) | ((!prize_description_.empty()) << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(additional_peers_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 16) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(until_date_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentPremiumGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentPremiumGiveaway");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3) | ((!additional_peers_.empty()) << 1) | ((!countries_iso2_.empty()) << 2) | ((!prize_description_.empty()) << 4)));
    if (var0 & 1) { s.store_field("only_new_subscribers", true); }
    if (var0 & 8) { s.store_field("winners_are_visible", true); }
    s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get()));
    if (var0 & 2) { { s.store_vector_begin("additional_peers", additional_peers_.size()); for (const auto &_value : additional_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("countries_iso2", countries_iso2_.size()); for (const auto &_value : countries_iso2_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("prize_description", prize_description_); }
    s.store_field("random_id", random_id_);
    s.store_field("until_date", until_date_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

inputStorePaymentStarsTopup::inputStorePaymentStarsTopup(int32 flags_, int64 stars_, string const &currency_, int64 amount_, object_ptr<InputPeer> &&spend_purpose_peer_)
  : flags_(flags_)
  , stars_(stars_)
  , currency_(currency_)
  , amount_(amount_)
  , spend_purpose_peer_(std::move(spend_purpose_peer_))
{}

const std::int32_t inputStorePaymentStarsTopup::ID;

void inputStorePaymentStarsTopup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((spend_purpose_peer_ != nullptr) << 0)), s);
  TlStoreBinary::store(stars_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(spend_purpose_peer_, s); }
}

void inputStorePaymentStarsTopup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((spend_purpose_peer_ != nullptr) << 0)), s);
  TlStoreBinary::store(stars_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(spend_purpose_peer_, s); }
}

void inputStorePaymentStarsTopup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentStarsTopup");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((spend_purpose_peer_ != nullptr) << 0)));
    s.store_field("stars", stars_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    if (var0 & 1) { s.store_object_field("spend_purpose_peer", static_cast<const BaseObject *>(spend_purpose_peer_.get())); }
    s.store_class_end();
  }
}

inputStorePaymentStarsGift::inputStorePaymentStarsGift(object_ptr<InputUser> &&user_id_, int64 stars_, string const &currency_, int64 amount_)
  : user_id_(std::move(user_id_))
  , stars_(stars_)
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t inputStorePaymentStarsGift::ID;

void inputStorePaymentStarsGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(stars_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentStarsGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(stars_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentStarsGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentStarsGift");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("stars", stars_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

inputStorePaymentStarsGiveaway::inputStorePaymentStarsGiveaway(int32 flags_, bool only_new_subscribers_, bool winners_are_visible_, int64 stars_, object_ptr<InputPeer> &&boost_peer_, array<object_ptr<InputPeer>> &&additional_peers_, array<string> &&countries_iso2_, string const &prize_description_, int64 random_id_, int32 until_date_, string const &currency_, int64 amount_, int32 users_)
  : flags_(flags_)
  , only_new_subscribers_(only_new_subscribers_)
  , winners_are_visible_(winners_are_visible_)
  , stars_(stars_)
  , boost_peer_(std::move(boost_peer_))
  , additional_peers_(std::move(additional_peers_))
  , countries_iso2_(std::move(countries_iso2_))
  , prize_description_(prize_description_)
  , random_id_(random_id_)
  , until_date_(until_date_)
  , currency_(currency_)
  , amount_(amount_)
  , users_(users_)
{}

const std::int32_t inputStorePaymentStarsGiveaway::ID;

void inputStorePaymentStarsGiveaway::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3) | ((!additional_peers_.empty()) << 1) | ((!countries_iso2_.empty()) << 2) | ((!prize_description_.empty()) << 4)), s);
  TlStoreBinary::store(stars_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(additional_peers_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 16) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(until_date_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  TlStoreBinary::store(users_, s);
}

void inputStorePaymentStarsGiveaway::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3) | ((!additional_peers_.empty()) << 1) | ((!countries_iso2_.empty()) << 2) | ((!prize_description_.empty()) << 4)), s);
  TlStoreBinary::store(stars_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(additional_peers_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 16) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(until_date_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  TlStoreBinary::store(users_, s);
}

void inputStorePaymentStarsGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentStarsGiveaway");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3) | ((!additional_peers_.empty()) << 1) | ((!countries_iso2_.empty()) << 2) | ((!prize_description_.empty()) << 4)));
    if (var0 & 1) { s.store_field("only_new_subscribers", true); }
    if (var0 & 8) { s.store_field("winners_are_visible", true); }
    s.store_field("stars", stars_);
    s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get()));
    if (var0 & 2) { { s.store_vector_begin("additional_peers", additional_peers_.size()); for (const auto &_value : additional_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("countries_iso2", countries_iso2_.size()); for (const auto &_value : countries_iso2_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("prize_description", prize_description_); }
    s.store_field("random_id", random_id_);
    s.store_field("until_date", until_date_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("users", users_);
    s.store_class_end();
  }
}

inputStorePaymentAuthCode::inputStorePaymentAuthCode(int32 flags_, bool restore_, string const &phone_number_, string const &phone_code_hash_, int32 premium_days_, string const &currency_, int64 amount_)
  : flags_(flags_)
  , restore_(restore_)
  , phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , premium_days_(premium_days_)
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t inputStorePaymentAuthCode::ID;

void inputStorePaymentAuthCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreBinary::store(premium_days_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentAuthCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreBinary::store(premium_days_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentAuthCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentAuthCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (restore_ << 0)));
    if (var0 & 1) { s.store_field("restore", true); }
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("premium_days", premium_days_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

object_ptr<MessageMedia> MessageMedia::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messageMediaEmpty::ID;

object_ptr<MessageMedia> messageMediaEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaEmpty>();
}

void messageMediaEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void messageMediaEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void messageMediaEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaEmpty");
    s.store_class_end();
  }
}

messageMediaPhoto::messageMediaPhoto()
  : flags_()
  , spoiler_()
  , live_photo_()
  , photo_()
  , ttl_seconds_()
  , video_()
{}

messageMediaPhoto::messageMediaPhoto(int32 flags_, bool spoiler_, bool live_photo_, object_ptr<Photo> &&photo_, int32 ttl_seconds_, object_ptr<Document> &&video_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , live_photo_(live_photo_)
  , photo_(std::move(photo_))
  , ttl_seconds_(ttl_seconds_)
  , video_(std::move(video_))
{}

const std::int32_t messageMediaPhoto::ID;

object_ptr<MessageMedia> messageMediaPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaPhoto> res = make_tl_object<messageMediaPhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 8) != 0;
  res->live_photo_ = (var0 & 16) != 0;
  if (var0 & 1) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 4) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->video_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 3) | (live_photo_ << 4) | ((photo_ != nullptr) << 0) | ((video_ != nullptr) << 4)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 4) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void messageMediaPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 3) | (live_photo_ << 4) | ((photo_ != nullptr) << 0) | ((video_ != nullptr) << 4)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 4) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void messageMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 3) | (live_photo_ << 4) | ((photo_ != nullptr) << 0) | ((video_ != nullptr) << 4)));
    if (var0 & 8) { s.store_field("spoiler", true); }
    if (var0 & 16) { s.store_field("live_photo", true); }
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 4) { s.store_field("ttl_seconds", ttl_seconds_); }
    if (var0 & 16) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    s.store_class_end();
  }
}

messageMediaGeo::messageMediaGeo(object_ptr<GeoPoint> &&geo_)
  : geo_(std::move(geo_))
{}

const std::int32_t messageMediaGeo::ID;

object_ptr<MessageMedia> messageMediaGeo::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaGeo>(p);
}

messageMediaGeo::messageMediaGeo(TlBufferParser &p)
  : geo_(TlFetchObject<GeoPoint>::parse(p))
{}

void messageMediaGeo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
}

void messageMediaGeo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
}

void messageMediaGeo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaGeo");
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    s.store_class_end();
  }
}

messageMediaContact::messageMediaContact(string const &phone_number_, string const &first_name_, string const &last_name_, string const &vcard_, int64 user_id_)
  : phone_number_(phone_number_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , vcard_(vcard_)
  , user_id_(user_id_)
{}

const std::int32_t messageMediaContact::ID;

object_ptr<MessageMedia> messageMediaContact::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaContact>(p);
}

messageMediaContact::messageMediaContact(TlBufferParser &p)
  : phone_number_(TlFetchString<string>::parse(p))
  , first_name_(TlFetchString<string>::parse(p))
  , last_name_(TlFetchString<string>::parse(p))
  , vcard_(TlFetchString<string>::parse(p))
  , user_id_(TlFetchLong::parse(p))
{}

void messageMediaContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
  TlStoreBinary::store(user_id_, s);
}

void messageMediaContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
  TlStoreBinary::store(user_id_, s);
}

void messageMediaContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaContact");
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("vcard", vcard_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

const std::int32_t messageMediaUnsupported::ID;

object_ptr<MessageMedia> messageMediaUnsupported::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaUnsupported>();
}

void messageMediaUnsupported::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void messageMediaUnsupported::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void messageMediaUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaUnsupported");
    s.store_class_end();
  }
}

messageMediaDocument::messageMediaDocument()
  : flags_()
  , nopremium_()
  , spoiler_()
  , video_()
  , round_()
  , voice_()
  , document_()
  , alt_documents_()
  , video_cover_()
  , video_timestamp_()
  , ttl_seconds_()
{}

messageMediaDocument::messageMediaDocument(int32 flags_, bool nopremium_, bool spoiler_, bool video_, bool round_, bool voice_, object_ptr<Document> &&document_, array<object_ptr<Document>> &&alt_documents_, object_ptr<Photo> &&video_cover_, int32 video_timestamp_, int32 ttl_seconds_)
  : flags_(flags_)
  , nopremium_(nopremium_)
  , spoiler_(spoiler_)
  , video_(video_)
  , round_(round_)
  , voice_(voice_)
  , document_(std::move(document_))
  , alt_documents_(std::move(alt_documents_))
  , video_cover_(std::move(video_cover_))
  , video_timestamp_(video_timestamp_)
  , ttl_seconds_(ttl_seconds_)
{}

const std::int32_t messageMediaDocument::ID;

object_ptr<MessageMedia> messageMediaDocument::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaDocument> res = make_tl_object<messageMediaDocument>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->nopremium_ = (var0 & 8) != 0;
  res->spoiler_ = (var0 & 16) != 0;
  res->video_ = (var0 & 64) != 0;
  res->round_ = (var0 & 128) != 0;
  res->voice_ = (var0 & 256) != 0;
  if (var0 & 1) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 32) { res->alt_documents_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p); }
  if (var0 & 512) { res->video_cover_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 1024) { res->video_timestamp_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (nopremium_ << 3) | (spoiler_ << 4) | (video_ << 6) | (round_ << 7) | (voice_ << 8) | ((document_ != nullptr) << 0) | ((!alt_documents_.empty()) << 5) | ((video_cover_ != nullptr) << 9)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(alt_documents_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 1024) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 4) { TlStoreBinary::store(ttl_seconds_, s); }
}

void messageMediaDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (nopremium_ << 3) | (spoiler_ << 4) | (video_ << 6) | (round_ << 7) | (voice_ << 8) | ((document_ != nullptr) << 0) | ((!alt_documents_.empty()) << 5) | ((video_cover_ != nullptr) << 9)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(alt_documents_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 1024) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 4) { TlStoreBinary::store(ttl_seconds_, s); }
}

void messageMediaDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaDocument");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (nopremium_ << 3) | (spoiler_ << 4) | (video_ << 6) | (round_ << 7) | (voice_ << 8) | ((document_ != nullptr) << 0) | ((!alt_documents_.empty()) << 5) | ((video_cover_ != nullptr) << 9)));
    if (var0 & 8) { s.store_field("nopremium", true); }
    if (var0 & 16) { s.store_field("spoiler", true); }
    if (var0 & 64) { s.store_field("video", true); }
    if (var0 & 128) { s.store_field("round", true); }
    if (var0 & 256) { s.store_field("voice", true); }
    if (var0 & 1) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 32) { { s.store_vector_begin("alt_documents", alt_documents_.size()); for (const auto &_value : alt_documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 512) { s.store_object_field("video_cover", static_cast<const BaseObject *>(video_cover_.get())); }
    if (var0 & 1024) { s.store_field("video_timestamp", video_timestamp_); }
    if (var0 & 4) { s.store_field("ttl_seconds", ttl_seconds_); }
    s.store_class_end();
  }
}

messageMediaWebPage::messageMediaWebPage()
  : flags_()
  , force_large_media_()
  , force_small_media_()
  , manual_()
  , safe_()
  , webpage_()
{}

messageMediaWebPage::messageMediaWebPage(int32 flags_, bool force_large_media_, bool force_small_media_, bool manual_, bool safe_, object_ptr<WebPage> &&webpage_)
  : flags_(flags_)
  , force_large_media_(force_large_media_)
  , force_small_media_(force_small_media_)
  , manual_(manual_)
  , safe_(safe_)
  , webpage_(std::move(webpage_))
{}

const std::int32_t messageMediaWebPage::ID;

object_ptr<MessageMedia> messageMediaWebPage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaWebPage> res = make_tl_object<messageMediaWebPage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->force_large_media_ = (var0 & 1) != 0;
  res->force_small_media_ = (var0 & 2) != 0;
  res->manual_ = (var0 & 8) != 0;
  res->safe_ = (var0 & 16) != 0;
  res->webpage_ = TlFetchObject<WebPage>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaWebPage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (manual_ << 3) | (safe_ << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(webpage_, s);
}

void messageMediaWebPage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (manual_ << 3) | (safe_ << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(webpage_, s);
}

void messageMediaWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaWebPage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (manual_ << 3) | (safe_ << 4)));
    if (var0 & 1) { s.store_field("force_large_media", true); }
    if (var0 & 2) { s.store_field("force_small_media", true); }
    if (var0 & 8) { s.store_field("manual", true); }
    if (var0 & 16) { s.store_field("safe", true); }
    s.store_object_field("webpage", static_cast<const BaseObject *>(webpage_.get()));
    s.store_class_end();
  }
}

messageMediaVenue::messageMediaVenue(object_ptr<GeoPoint> &&geo_, string const &title_, string const &address_, string const &provider_, string const &venue_id_, string const &venue_type_)
  : geo_(std::move(geo_))
  , title_(title_)
  , address_(address_)
  , provider_(provider_)
  , venue_id_(venue_id_)
  , venue_type_(venue_type_)
{}

const std::int32_t messageMediaVenue::ID;

object_ptr<MessageMedia> messageMediaVenue::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaVenue>(p);
}

messageMediaVenue::messageMediaVenue(TlBufferParser &p)
  : geo_(TlFetchObject<GeoPoint>::parse(p))
  , title_(TlFetchString<string>::parse(p))
  , address_(TlFetchString<string>::parse(p))
  , provider_(TlFetchString<string>::parse(p))
  , venue_id_(TlFetchString<string>::parse(p))
  , venue_type_(TlFetchString<string>::parse(p))
{}

void messageMediaVenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void messageMediaVenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void messageMediaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaVenue");
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("venue_type", venue_type_);
    s.store_class_end();
  }
}

messageMediaGame::messageMediaGame(object_ptr<game> &&game_)
  : game_(std::move(game_))
{}

const std::int32_t messageMediaGame::ID;

object_ptr<MessageMedia> messageMediaGame::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaGame>(p);
}

messageMediaGame::messageMediaGame(TlBufferParser &p)
  : game_(TlFetchBoxed<TlFetchObject<game>, -1107729093>::parse(p))
{}

void messageMediaGame::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -1107729093>::store(game_, s);
}

void messageMediaGame::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -1107729093>::store(game_, s);
}

void messageMediaGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaGame");
    s.store_object_field("game", static_cast<const BaseObject *>(game_.get()));
    s.store_class_end();
  }
}

messageMediaInvoice::messageMediaInvoice()
  : flags_()
  , shipping_address_requested_()
  , test_()
  , title_()
  , description_()
  , photo_()
  , receipt_msg_id_()
  , currency_()
  , total_amount_()
  , start_param_()
  , extended_media_()
{}

messageMediaInvoice::messageMediaInvoice(int32 flags_, bool shipping_address_requested_, bool test_, string const &title_, string const &description_, object_ptr<WebDocument> &&photo_, int32 receipt_msg_id_, string const &currency_, int64 total_amount_, string const &start_param_, object_ptr<MessageExtendedMedia> &&extended_media_)
  : flags_(flags_)
  , shipping_address_requested_(shipping_address_requested_)
  , test_(test_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , receipt_msg_id_(receipt_msg_id_)
  , currency_(currency_)
  , total_amount_(total_amount_)
  , start_param_(start_param_)
  , extended_media_(std::move(extended_media_))
{}

const std::int32_t messageMediaInvoice::ID;

object_ptr<MessageMedia> messageMediaInvoice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaInvoice> res = make_tl_object<messageMediaInvoice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->shipping_address_requested_ = (var0 & 2) != 0;
  res->test_ = (var0 & 8) != 0;
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 4) { res->receipt_msg_id_ = TlFetchInt::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  res->start_param_ = TlFetchString<string>::parse(p);
  if (var0 & 16) { res->extended_media_ = TlFetchObject<MessageExtendedMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaInvoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (shipping_address_requested_ << 1) | (test_ << 3) | ((photo_ != nullptr) << 0) | ((extended_media_ != nullptr) << 4)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 4) { TlStoreBinary::store(receipt_msg_id_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(total_amount_, s);
  TlStoreString::store(start_param_, s);
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(extended_media_, s); }
}

void messageMediaInvoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (shipping_address_requested_ << 1) | (test_ << 3) | ((photo_ != nullptr) << 0) | ((extended_media_ != nullptr) << 4)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 4) { TlStoreBinary::store(receipt_msg_id_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(total_amount_, s);
  TlStoreString::store(start_param_, s);
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(extended_media_, s); }
}

void messageMediaInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaInvoice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (shipping_address_requested_ << 1) | (test_ << 3) | ((photo_ != nullptr) << 0) | ((extended_media_ != nullptr) << 4)));
    if (var0 & 2) { s.store_field("shipping_address_requested", true); }
    if (var0 & 8) { s.store_field("test", true); }
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 4) { s.store_field("receipt_msg_id", receipt_msg_id_); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("start_param", start_param_);
    if (var0 & 16) { s.store_object_field("extended_media", static_cast<const BaseObject *>(extended_media_.get())); }
    s.store_class_end();
  }
}

messageMediaGeoLive::messageMediaGeoLive()
  : flags_()
  , geo_()
  , heading_()
  , period_()
  , proximity_notification_radius_()
{}

messageMediaGeoLive::messageMediaGeoLive(int32 flags_, object_ptr<GeoPoint> &&geo_, int32 heading_, int32 period_, int32 proximity_notification_radius_)
  : flags_(flags_)
  , geo_(std::move(geo_))
  , heading_(heading_)
  , period_(period_)
  , proximity_notification_radius_(proximity_notification_radius_)
{}

const std::int32_t messageMediaGeoLive::ID;

object_ptr<MessageMedia> messageMediaGeoLive::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaGeoLive> res = make_tl_object<messageMediaGeoLive>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->geo_ = TlFetchObject<GeoPoint>::parse(p);
  if (var0 & 1) { res->heading_ = TlFetchInt::parse(p); }
  res->period_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->proximity_notification_radius_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaGeoLive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  if (var0 & 1) { TlStoreBinary::store(heading_, s); }
  TlStoreBinary::store(period_, s);
  if (var0 & 2) { TlStoreBinary::store(proximity_notification_radius_, s); }
}

void messageMediaGeoLive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  if (var0 & 1) { TlStoreBinary::store(heading_, s); }
  TlStoreBinary::store(period_, s);
  if (var0 & 2) { TlStoreBinary::store(proximity_notification_radius_, s); }
}

void messageMediaGeoLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaGeoLive");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    if (var0 & 1) { s.store_field("heading", heading_); }
    s.store_field("period", period_);
    if (var0 & 2) { s.store_field("proximity_notification_radius", proximity_notification_radius_); }
    s.store_class_end();
  }
}

messageMediaPoll::messageMediaPoll()
  : flags_()
  , poll_()
  , results_()
  , attached_media_()
{}

messageMediaPoll::messageMediaPoll(int32 flags_, object_ptr<poll> &&poll_, object_ptr<pollResults> &&results_, object_ptr<MessageMedia> &&attached_media_)
  : flags_(flags_)
  , poll_(std::move(poll_))
  , results_(std::move(results_))
  , attached_media_(std::move(attached_media_))
{}

const std::int32_t messageMediaPoll::ID;

object_ptr<MessageMedia> messageMediaPoll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaPoll> res = make_tl_object<messageMediaPoll>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->poll_ = TlFetchBoxed<TlFetchObject<poll>, -1771164225>::parse(p);
  res->results_ = TlFetchBoxed<TlFetchObject<pollResults>, -1166298786>::parse(p);
  if (var0 & 1) { res->attached_media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaPoll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((attached_media_ != nullptr) << 0)), s);
  TlStoreBoxed<TlStoreObject, -1771164225>::store(poll_, s);
  TlStoreBoxed<TlStoreObject, -1166298786>::store(results_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(attached_media_, s); }
}

void messageMediaPoll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((attached_media_ != nullptr) << 0)), s);
  TlStoreBoxed<TlStoreObject, -1771164225>::store(poll_, s);
  TlStoreBoxed<TlStoreObject, -1166298786>::store(results_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(attached_media_, s); }
}

void messageMediaPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaPoll");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((attached_media_ != nullptr) << 0)));
    s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get()));
    s.store_object_field("results", static_cast<const BaseObject *>(results_.get()));
    if (var0 & 1) { s.store_object_field("attached_media", static_cast<const BaseObject *>(attached_media_.get())); }
    s.store_class_end();
  }
}

messageMediaDice::messageMediaDice()
  : flags_()
  , value_()
  , emoticon_()
  , game_outcome_()
{}

messageMediaDice::messageMediaDice(int32 flags_, int32 value_, string const &emoticon_, object_ptr<messages_emojiGameOutcome> &&game_outcome_)
  : flags_(flags_)
  , value_(value_)
  , emoticon_(emoticon_)
  , game_outcome_(std::move(game_outcome_))
{}

const std::int32_t messageMediaDice::ID;

object_ptr<MessageMedia> messageMediaDice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaDice> res = make_tl_object<messageMediaDice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->value_ = TlFetchInt::parse(p);
  res->emoticon_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->game_outcome_ = TlFetchBoxed<TlFetchObject<messages_emojiGameOutcome>, -634726841>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaDice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((game_outcome_ != nullptr) << 0)), s);
  TlStoreBinary::store(value_, s);
  TlStoreString::store(emoticon_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -634726841>::store(game_outcome_, s); }
}

void messageMediaDice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((game_outcome_ != nullptr) << 0)), s);
  TlStoreBinary::store(value_, s);
  TlStoreString::store(emoticon_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -634726841>::store(game_outcome_, s); }
}

void messageMediaDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaDice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((game_outcome_ != nullptr) << 0)));
    s.store_field("value", value_);
    s.store_field("emoticon", emoticon_);
    if (var0 & 1) { s.store_object_field("game_outcome", static_cast<const BaseObject *>(game_outcome_.get())); }
    s.store_class_end();
  }
}

messageMediaStory::messageMediaStory()
  : flags_()
  , via_mention_()
  , peer_()
  , id_()
  , story_()
{}

messageMediaStory::messageMediaStory(int32 flags_, bool via_mention_, object_ptr<Peer> &&peer_, int32 id_, object_ptr<StoryItem> &&story_)
  : flags_(flags_)
  , via_mention_(via_mention_)
  , peer_(std::move(peer_))
  , id_(id_)
  , story_(std::move(story_))
{}

const std::int32_t messageMediaStory::ID;

object_ptr<MessageMedia> messageMediaStory::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaStory> res = make_tl_object<messageMediaStory>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_mention_ = (var0 & 2) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->story_ = TlFetchObject<StoryItem>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (via_mention_ << 1) | ((story_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(story_, s); }
}

void messageMediaStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (via_mention_ << 1) | ((story_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(story_, s); }
}

void messageMediaStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaStory");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_mention_ << 1) | ((story_ != nullptr) << 0)));
    if (var0 & 2) { s.store_field("via_mention", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("story", static_cast<const BaseObject *>(story_.get())); }
    s.store_class_end();
  }
}

messageMediaGiveaway::messageMediaGiveaway()
  : flags_()
  , only_new_subscribers_()
  , winners_are_visible_()
  , channels_()
  , countries_iso2_()
  , prize_description_()
  , quantity_()
  , months_()
  , stars_()
  , until_date_()
{}

messageMediaGiveaway::messageMediaGiveaway(int32 flags_, bool only_new_subscribers_, bool winners_are_visible_, array<int64> &&channels_, array<string> &&countries_iso2_, string const &prize_description_, int32 quantity_, int32 months_, int64 stars_, int32 until_date_)
  : flags_(flags_)
  , only_new_subscribers_(only_new_subscribers_)
  , winners_are_visible_(winners_are_visible_)
  , channels_(std::move(channels_))
  , countries_iso2_(std::move(countries_iso2_))
  , prize_description_(prize_description_)
  , quantity_(quantity_)
  , months_(months_)
  , stars_(stars_)
  , until_date_(until_date_)
{}

const std::int32_t messageMediaGiveaway::ID;

object_ptr<MessageMedia> messageMediaGiveaway::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaGiveaway> res = make_tl_object<messageMediaGiveaway>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->only_new_subscribers_ = (var0 & 1) != 0;
  res->winners_are_visible_ = (var0 & 4) != 0;
  res->channels_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
  if (var0 & 2) { res->countries_iso2_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p); }
  if (var0 & 8) { res->prize_description_ = TlFetchString<string>::parse(p); }
  res->quantity_ = TlFetchInt::parse(p);
  if (var0 & 16) { res->months_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->stars_ = TlFetchLong::parse(p); }
  res->until_date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaGiveaway::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 2) | ((!countries_iso2_.empty()) << 1) | ((!prize_description_.empty()) << 3)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(channels_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 8) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(quantity_, s);
  if (var0 & 16) { TlStoreBinary::store(months_, s); }
  if (var0 & 32) { TlStoreBinary::store(stars_, s); }
  TlStoreBinary::store(until_date_, s);
}

void messageMediaGiveaway::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 2) | ((!countries_iso2_.empty()) << 1) | ((!prize_description_.empty()) << 3)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(channels_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 8) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(quantity_, s);
  if (var0 & 16) { TlStoreBinary::store(months_, s); }
  if (var0 & 32) { TlStoreBinary::store(stars_, s); }
  TlStoreBinary::store(until_date_, s);
}

void messageMediaGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaGiveaway");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 2) | ((!countries_iso2_.empty()) << 1) | ((!prize_description_.empty()) << 3)));
    if (var0 & 1) { s.store_field("only_new_subscribers", true); }
    if (var0 & 4) { s.store_field("winners_are_visible", true); }
    { s.store_vector_begin("channels", channels_.size()); for (const auto &_value : channels_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 2) { { s.store_vector_begin("countries_iso2", countries_iso2_.size()); for (const auto &_value : countries_iso2_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 8) { s.store_field("prize_description", prize_description_); }
    s.store_field("quantity", quantity_);
    if (var0 & 16) { s.store_field("months", months_); }
    if (var0 & 32) { s.store_field("stars", stars_); }
    s.store_field("until_date", until_date_);
    s.store_class_end();
  }
}

messageMediaGiveawayResults::messageMediaGiveawayResults()
  : flags_()
  , only_new_subscribers_()
  , refunded_()
  , channel_id_()
  , additional_peers_count_()
  , launch_msg_id_()
  , winners_count_()
  , unclaimed_count_()
  , winners_()
  , months_()
  , stars_()
  , prize_description_()
  , until_date_()
{}

messageMediaGiveawayResults::messageMediaGiveawayResults(int32 flags_, bool only_new_subscribers_, bool refunded_, int64 channel_id_, int32 additional_peers_count_, int32 launch_msg_id_, int32 winners_count_, int32 unclaimed_count_, array<int64> &&winners_, int32 months_, int64 stars_, string const &prize_description_, int32 until_date_)
  : flags_(flags_)
  , only_new_subscribers_(only_new_subscribers_)
  , refunded_(refunded_)
  , channel_id_(channel_id_)
  , additional_peers_count_(additional_peers_count_)
  , launch_msg_id_(launch_msg_id_)
  , winners_count_(winners_count_)
  , unclaimed_count_(unclaimed_count_)
  , winners_(std::move(winners_))
  , months_(months_)
  , stars_(stars_)
  , prize_description_(prize_description_)
  , until_date_(until_date_)
{}

const std::int32_t messageMediaGiveawayResults::ID;

object_ptr<MessageMedia> messageMediaGiveawayResults::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaGiveawayResults> res = make_tl_object<messageMediaGiveawayResults>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->only_new_subscribers_ = (var0 & 1) != 0;
  res->refunded_ = (var0 & 4) != 0;
  res->channel_id_ = TlFetchLong::parse(p);
  if (var0 & 8) { res->additional_peers_count_ = TlFetchInt::parse(p); }
  res->launch_msg_id_ = TlFetchInt::parse(p);
  res->winners_count_ = TlFetchInt::parse(p);
  res->unclaimed_count_ = TlFetchInt::parse(p);
  res->winners_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
  if (var0 & 16) { res->months_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->stars_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->prize_description_ = TlFetchString<string>::parse(p); }
  res->until_date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaGiveawayResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (refunded_ << 2) | ((!prize_description_.empty()) << 1)), s);
  TlStoreBinary::store(channel_id_, s);
  if (var0 & 8) { TlStoreBinary::store(additional_peers_count_, s); }
  TlStoreBinary::store(launch_msg_id_, s);
  TlStoreBinary::store(winners_count_, s);
  TlStoreBinary::store(unclaimed_count_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(winners_, s);
  if (var0 & 16) { TlStoreBinary::store(months_, s); }
  if (var0 & 32) { TlStoreBinary::store(stars_, s); }
  if (var0 & 2) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(until_date_, s);
}

void messageMediaGiveawayResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (refunded_ << 2) | ((!prize_description_.empty()) << 1)), s);
  TlStoreBinary::store(channel_id_, s);
  if (var0 & 8) { TlStoreBinary::store(additional_peers_count_, s); }
  TlStoreBinary::store(launch_msg_id_, s);
  TlStoreBinary::store(winners_count_, s);
  TlStoreBinary::store(unclaimed_count_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(winners_, s);
  if (var0 & 16) { TlStoreBinary::store(months_, s); }
  if (var0 & 32) { TlStoreBinary::store(stars_, s); }
  if (var0 & 2) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(until_date_, s);
}

void messageMediaGiveawayResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaGiveawayResults");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (only_new_subscribers_ << 0) | (refunded_ << 2) | ((!prize_description_.empty()) << 1)));
    if (var0 & 1) { s.store_field("only_new_subscribers", true); }
    if (var0 & 4) { s.store_field("refunded", true); }
    s.store_field("channel_id", channel_id_);
    if (var0 & 8) { s.store_field("additional_peers_count", additional_peers_count_); }
    s.store_field("launch_msg_id", launch_msg_id_);
    s.store_field("winners_count", winners_count_);
    s.store_field("unclaimed_count", unclaimed_count_);
    { s.store_vector_begin("winners", winners_.size()); for (const auto &_value : winners_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 16) { s.store_field("months", months_); }
    if (var0 & 32) { s.store_field("stars", stars_); }
    if (var0 & 2) { s.store_field("prize_description", prize_description_); }
    s.store_field("until_date", until_date_);
    s.store_class_end();
  }
}

messageMediaPaidMedia::messageMediaPaidMedia(int64 stars_amount_, array<object_ptr<MessageExtendedMedia>> &&extended_media_)
  : stars_amount_(stars_amount_)
  , extended_media_(std::move(extended_media_))
{}

const std::int32_t messageMediaPaidMedia::ID;

object_ptr<MessageMedia> messageMediaPaidMedia::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaPaidMedia>(p);
}

messageMediaPaidMedia::messageMediaPaidMedia(TlBufferParser &p)
  : stars_amount_(TlFetchLong::parse(p))
  , extended_media_(TlFetchBoxed<TlFetchVector<TlFetchObject<MessageExtendedMedia>>, 481674261>::parse(p))
{}

void messageMediaPaidMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(stars_amount_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(extended_media_, s);
}

void messageMediaPaidMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(stars_amount_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(extended_media_, s);
}

void messageMediaPaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaPaidMedia");
    s.store_field("stars_amount", stars_amount_);
    { s.store_vector_begin("extended_media", extended_media_.size()); for (const auto &_value : extended_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageMediaToDo::messageMediaToDo()
  : flags_()
  , todo_()
  , completions_()
{}

messageMediaToDo::messageMediaToDo(int32 flags_, object_ptr<todoList> &&todo_, array<object_ptr<todoCompletion>> &&completions_)
  : flags_(flags_)
  , todo_(std::move(todo_))
  , completions_(std::move(completions_))
{}

const std::int32_t messageMediaToDo::ID;

object_ptr<MessageMedia> messageMediaToDo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaToDo> res = make_tl_object<messageMediaToDo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->todo_ = TlFetchBoxed<TlFetchObject<todoList>, 1236871718>::parse(p);
  if (var0 & 1) { res->completions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<todoCompletion>, 572241380>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaToDo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!completions_.empty()) << 0)), s);
  TlStoreBoxed<TlStoreObject, 1236871718>::store(todo_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 572241380>>, 481674261>::store(completions_, s); }
}

void messageMediaToDo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!completions_.empty()) << 0)), s);
  TlStoreBoxed<TlStoreObject, 1236871718>::store(todo_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 572241380>>, 481674261>::store(completions_, s); }
}

void messageMediaToDo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaToDo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!completions_.empty()) << 0)));
    s.store_object_field("todo", static_cast<const BaseObject *>(todo_.get()));
    if (var0 & 1) { { s.store_vector_begin("completions", completions_.size()); for (const auto &_value : completions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messageMediaVideoStream::messageMediaVideoStream()
  : flags_()
  , rtmp_stream_()
  , call_()
{}

messageMediaVideoStream::messageMediaVideoStream(int32 flags_, bool rtmp_stream_, object_ptr<InputGroupCall> &&call_)
  : flags_(flags_)
  , rtmp_stream_(rtmp_stream_)
  , call_(std::move(call_))
{}

const std::int32_t messageMediaVideoStream::ID;

object_ptr<MessageMedia> messageMediaVideoStream::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaVideoStream> res = make_tl_object<messageMediaVideoStream>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->rtmp_stream_ = (var0 & 1) != 0;
  res->call_ = TlFetchObject<InputGroupCall>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaVideoStream::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtmp_stream_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void messageMediaVideoStream::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtmp_stream_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void messageMediaVideoStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaVideoStream");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (rtmp_stream_ << 0)));
    if (var0 & 1) { s.store_field("rtmp_stream", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

messageMediaWidget::messageMediaWidget()
  : flags_()
  , is_copy_()
  , can_query_()
  , background_query_()
  , width_()
  , height_()
  , payload_()
  , public_data_()
  , public_data_hash_()
  , chat_data_()
  , widget_id_()
{}

messageMediaWidget::messageMediaWidget(int32 flags_, bool is_copy_, bool can_query_, bool background_query_, int32 width_, int32 height_, bytes &&payload_, string const &public_data_, int64 public_data_hash_, string const &chat_data_, int64 widget_id_)
  : flags_(flags_)
  , is_copy_(is_copy_)
  , can_query_(can_query_)
  , background_query_(background_query_)
  , width_(width_)
  , height_(height_)
  , payload_(std::move(payload_))
  , public_data_(public_data_)
  , public_data_hash_(public_data_hash_)
  , chat_data_(chat_data_)
  , widget_id_(widget_id_)
{}

const std::int32_t messageMediaWidget::ID;

object_ptr<MessageMedia> messageMediaWidget::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaWidget> res = make_tl_object<messageMediaWidget>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->is_copy_ = (var0 & 1) != 0;
  res->can_query_ = (var0 & 2) != 0;
  res->background_query_ = (var0 & 4) != 0;
  res->width_ = TlFetchInt::parse(p);
  res->height_ = TlFetchInt::parse(p);
  res->payload_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 8) { res->public_data_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->public_data_hash_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->chat_data_ = TlFetchString<string>::parse(p); }
  if (var0 & 32) { res->widget_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaWidget::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (is_copy_ << 0) | (can_query_ << 1) | (background_query_ << 2) | ((!public_data_.empty()) << 3) | ((!chat_data_.empty()) << 4)), s);
  TlStoreBinary::store(width_, s);
  TlStoreBinary::store(height_, s);
  TlStoreString::store(payload_, s);
  if (var0 & 8) { TlStoreString::store(public_data_, s); }
  if (var0 & 8) { TlStoreBinary::store(public_data_hash_, s); }
  if (var0 & 16) { TlStoreString::store(chat_data_, s); }
  if (var0 & 32) { TlStoreBinary::store(widget_id_, s); }
}

void messageMediaWidget::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (is_copy_ << 0) | (can_query_ << 1) | (background_query_ << 2) | ((!public_data_.empty()) << 3) | ((!chat_data_.empty()) << 4)), s);
  TlStoreBinary::store(width_, s);
  TlStoreBinary::store(height_, s);
  TlStoreString::store(payload_, s);
  if (var0 & 8) { TlStoreString::store(public_data_, s); }
  if (var0 & 8) { TlStoreBinary::store(public_data_hash_, s); }
  if (var0 & 16) { TlStoreString::store(chat_data_, s); }
  if (var0 & 32) { TlStoreBinary::store(widget_id_, s); }
}

void messageMediaWidget::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaWidget");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (is_copy_ << 0) | (can_query_ << 1) | (background_query_ << 2) | ((!public_data_.empty()) << 3) | ((!chat_data_.empty()) << 4)));
    if (var0 & 1) { s.store_field("is_copy", true); }
    if (var0 & 2) { s.store_field("can_query", true); }
    if (var0 & 4) { s.store_field("background_query", true); }
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_bytes_field("payload", payload_);
    if (var0 & 8) { s.store_field("public_data", public_data_); }
    if (var0 & 8) { s.store_field("public_data_hash", public_data_hash_); }
    if (var0 & 16) { s.store_field("chat_data", chat_data_); }
    if (var0 & 32) { s.store_field("widget_id", widget_id_); }
    s.store_class_end();
  }
}

object_ptr<MessagePeerVote> MessagePeerVote::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messagePeerVote::ID:
      return messagePeerVote::fetch(p);
    case messagePeerVoteInputOption::ID:
      return messagePeerVoteInputOption::fetch(p);
    case messagePeerVoteMultiple::ID:
      return messagePeerVoteMultiple::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messagePeerVote::ID;

object_ptr<MessagePeerVote> messagePeerVote::fetch(TlBufferParser &p) {
  return make_tl_object<messagePeerVote>(p);
}

messagePeerVote::messagePeerVote(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , option_(TlFetchBytes<bytes>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void messagePeerVote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePeerVote");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_bytes_field("option", option_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t messagePeerVoteInputOption::ID;

object_ptr<MessagePeerVote> messagePeerVoteInputOption::fetch(TlBufferParser &p) {
  return make_tl_object<messagePeerVoteInputOption>(p);
}

messagePeerVoteInputOption::messagePeerVoteInputOption(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void messagePeerVoteInputOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePeerVoteInputOption");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t messagePeerVoteMultiple::ID;

object_ptr<MessagePeerVote> messagePeerVoteMultiple::fetch(TlBufferParser &p) {
  return make_tl_object<messagePeerVoteMultiple>(p);
}

messagePeerVoteMultiple::messagePeerVoteMultiple(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , options_(TlFetchBoxed<TlFetchVector<TlFetchBytes<bytes>>, 481674261>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void messagePeerVoteMultiple::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePeerVoteMultiple");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t onrampLimits::ID;

object_ptr<onrampLimits> onrampLimits::fetch(TlBufferParser &p) {
  return make_tl_object<onrampLimits>(p);
}

onrampLimits::onrampLimits(TlBufferParser &p)
  : base_currency_(TlFetchString<string>::parse(p))
  , base_min_amount_(TlFetchString<string>::parse(p))
  , base_max_amount_(TlFetchString<string>::parse(p))
  , crypto_min_amount_(TlFetchString<string>::parse(p))
  , crypto_max_amount_(TlFetchString<string>::parse(p))
  , payment_method_(TlFetchString<string>::parse(p))
{}

void onrampLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onrampLimits");
    s.store_field("base_currency", base_currency_);
    s.store_field("base_min_amount", base_min_amount_);
    s.store_field("base_max_amount", base_max_amount_);
    s.store_field("crypto_min_amount", crypto_min_amount_);
    s.store_field("crypto_max_amount", crypto_max_amount_);
    s.store_field("payment_method", payment_method_);
    s.store_class_end();
  }
}

onrampProviderInfo::onrampProviderInfo()
  : flags_()
  , supports_base_currencies_()
  , supports_limits_()
  , supports_quote_()
  , id_()
  , name_()
  , crypto_currencies_()
{}

const std::int32_t onrampProviderInfo::ID;

object_ptr<onrampProviderInfo> onrampProviderInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<onrampProviderInfo> res = make_tl_object<onrampProviderInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->supports_base_currencies_ = (var0 & 1) != 0;
  res->supports_limits_ = (var0 & 2) != 0;
  res->supports_quote_ = (var0 & 4) != 0;
  res->id_ = TlFetchString<string>::parse(p);
  res->name_ = TlFetchString<string>::parse(p);
  res->crypto_currencies_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void onrampProviderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "onrampProviderInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (supports_base_currencies_ << 0) | (supports_limits_ << 1) | (supports_quote_ << 2)));
    if (var0 & 1) { s.store_field("supports_base_currencies", true); }
    if (var0 & 2) { s.store_field("supports_limits", true); }
    if (var0 & 4) { s.store_field("supports_quote", true); }
    s.store_field("id", id_);
    s.store_field("name", name_);
    { s.store_vector_begin("crypto_currencies", crypto_currencies_.size()); for (const auto &_value : crypto_currencies_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageCaption::pageCaption(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageCaption::ID;

object_ptr<pageCaption> pageCaption::fetch(TlBufferParser &p) {
  return make_tl_object<pageCaption>(p);
}

pageCaption::pageCaption(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , credit_(TlFetchObject<RichText>::parse(p))
{}

void pageCaption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(credit_, s);
}

void pageCaption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(credit_, s);
}

void pageCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageCaption");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

passkey::passkey()
  : flags_()
  , id_()
  , name_()
  , date_()
  , software_emoji_id_()
  , last_usage_date_()
{}

const std::int32_t passkey::ID;

object_ptr<passkey> passkey::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<passkey> res = make_tl_object<passkey>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchString<string>::parse(p);
  res->name_ = TlFetchString<string>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->software_emoji_id_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->last_usage_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void passkey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passkey");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_field("date", date_);
    if (var0 & 1) { s.store_field("software_emoji_id", software_emoji_id_); }
    if (var0 & 2) { s.store_field("last_usage_date", last_usage_date_); }
    s.store_class_end();
  }
}

const std::int32_t paymentFormMethod::ID;

object_ptr<paymentFormMethod> paymentFormMethod::fetch(TlBufferParser &p) {
  return make_tl_object<paymentFormMethod>(p);
}

paymentFormMethod::paymentFormMethod(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , title_(TlFetchString<string>::parse(p))
{}

void paymentFormMethod::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentFormMethod");
    s.store_field("url", url_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

peerSettings::peerSettings()
  : flags_()
  , report_spam_()
  , add_contact_()
  , block_contact_()
  , share_contact_()
  , need_contacts_exception_()
  , report_geo_()
  , autoarchived_()
  , invite_members_()
  , request_chat_broadcast_()
  , business_bot_paused_()
  , business_bot_can_reply_()
  , geo_distance_()
  , request_chat_title_()
  , request_chat_date_()
  , business_bot_id_()
  , business_bot_manage_url_()
  , charge_paid_message_stars_()
  , registration_month_()
  , phone_country_()
  , name_change_date_()
  , photo_change_date_()
  , bot_inviter_id_()
  , bot_owner_id_()
{}

const std::int32_t peerSettings::ID;

object_ptr<peerSettings> peerSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<peerSettings> res = make_tl_object<peerSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->report_spam_ = (var0 & 1) != 0;
  res->add_contact_ = (var0 & 2) != 0;
  res->block_contact_ = (var0 & 4) != 0;
  res->share_contact_ = (var0 & 8) != 0;
  res->need_contacts_exception_ = (var0 & 16) != 0;
  res->report_geo_ = (var0 & 32) != 0;
  res->autoarchived_ = (var0 & 128) != 0;
  res->invite_members_ = (var0 & 256) != 0;
  res->request_chat_broadcast_ = (var0 & 1024) != 0;
  res->business_bot_paused_ = (var0 & 2048) != 0;
  res->business_bot_can_reply_ = (var0 & 4096) != 0;
  if (var0 & 64) { res->geo_distance_ = TlFetchInt::parse(p); }
  if (var0 & 512) { res->request_chat_title_ = TlFetchString<string>::parse(p); }
  if (var0 & 512) { res->request_chat_date_ = TlFetchInt::parse(p); }
  if (var0 & 8192) { res->business_bot_id_ = TlFetchLong::parse(p); }
  if (var0 & 8192) { res->business_bot_manage_url_ = TlFetchString<string>::parse(p); }
  if (var0 & 16384) { res->charge_paid_message_stars_ = TlFetchLong::parse(p); }
  if (var0 & 32768) { res->registration_month_ = TlFetchString<string>::parse(p); }
  if (var0 & 65536) { res->phone_country_ = TlFetchString<string>::parse(p); }
  if (var0 & 131072) { res->name_change_date_ = TlFetchInt::parse(p); }
  if (var0 & 262144) { res->photo_change_date_ = TlFetchInt::parse(p); }
  if (var0 & 524288) { res->bot_inviter_id_ = TlFetchLong::parse(p); }
  if (var0 & 1048576) { res->bot_owner_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void peerSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (report_spam_ << 0) | (add_contact_ << 1) | (block_contact_ << 2) | (share_contact_ << 3) | (need_contacts_exception_ << 4) | (report_geo_ << 5) | (autoarchived_ << 7) | (invite_members_ << 8) | (request_chat_broadcast_ << 10) | (business_bot_paused_ << 11) | (business_bot_can_reply_ << 12) | ((!request_chat_title_.empty()) << 9) | ((!business_bot_manage_url_.empty()) << 13) | ((!registration_month_.empty()) << 15) | ((!phone_country_.empty()) << 16)));
    if (var0 & 1) { s.store_field("report_spam", true); }
    if (var0 & 2) { s.store_field("add_contact", true); }
    if (var0 & 4) { s.store_field("block_contact", true); }
    if (var0 & 8) { s.store_field("share_contact", true); }
    if (var0 & 16) { s.store_field("need_contacts_exception", true); }
    if (var0 & 32) { s.store_field("report_geo", true); }
    if (var0 & 128) { s.store_field("autoarchived", true); }
    if (var0 & 256) { s.store_field("invite_members", true); }
    if (var0 & 1024) { s.store_field("request_chat_broadcast", true); }
    if (var0 & 2048) { s.store_field("business_bot_paused", true); }
    if (var0 & 4096) { s.store_field("business_bot_can_reply", true); }
    if (var0 & 64) { s.store_field("geo_distance", geo_distance_); }
    if (var0 & 512) { s.store_field("request_chat_title", request_chat_title_); }
    if (var0 & 512) { s.store_field("request_chat_date", request_chat_date_); }
    if (var0 & 8192) { s.store_field("business_bot_id", business_bot_id_); }
    if (var0 & 8192) { s.store_field("business_bot_manage_url", business_bot_manage_url_); }
    if (var0 & 16384) { s.store_field("charge_paid_message_stars", charge_paid_message_stars_); }
    if (var0 & 32768) { s.store_field("registration_month", registration_month_); }
    if (var0 & 65536) { s.store_field("phone_country", phone_country_); }
    if (var0 & 131072) { s.store_field("name_change_date", name_change_date_); }
    if (var0 & 262144) { s.store_field("photo_change_date", photo_change_date_); }
    if (var0 & 524288) { s.store_field("bot_inviter_id", bot_inviter_id_); }
    if (var0 & 1048576) { s.store_field("bot_owner_id", bot_owner_id_); }
    s.store_class_end();
  }
}

object_ptr<Photo> Photo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case photoEmpty::ID:
      return photoEmpty::fetch(p);
    case photo::ID:
      return photo::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

photoEmpty::photoEmpty(int64 id_)
  : id_(id_)
{}

const std::int32_t photoEmpty::ID;

object_ptr<Photo> photoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<photoEmpty>(p);
}

photoEmpty::photoEmpty(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void photoEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void photoEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void photoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

photo::photo()
  : flags_()
  , has_stickers_()
  , id_()
  , access_hash_()
  , file_reference_()
  , date_()
  , sizes_()
  , video_sizes_()
  , dc_id_()
{}

photo::photo(int32 flags_, bool has_stickers_, int64 id_, int64 access_hash_, bytes &&file_reference_, int32 date_, array<object_ptr<PhotoSize>> &&sizes_, array<object_ptr<VideoSize>> &&video_sizes_, int32 dc_id_)
  : flags_(flags_)
  , has_stickers_(has_stickers_)
  , id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
  , date_(date_)
  , sizes_(std::move(sizes_))
  , video_sizes_(std::move(video_sizes_))
  , dc_id_(dc_id_)
{}

const std::int32_t photo::ID;

object_ptr<Photo> photo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<photo> res = make_tl_object<photo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_stickers_ = (var0 & 1) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->file_reference_ = TlFetchBytes<bytes>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->sizes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PhotoSize>>, 481674261>::parse(p);
  if (var0 & 2) { res->video_sizes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<VideoSize>>, 481674261>::parse(p); }
  res->dc_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void photo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_stickers_ << 0) | ((!video_sizes_.empty()) << 1)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(sizes_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(video_sizes_, s); }
  TlStoreBinary::store(dc_id_, s);
}

void photo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_stickers_ << 0) | ((!video_sizes_.empty()) << 1)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(sizes_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(video_sizes_, s); }
  TlStoreBinary::store(dc_id_, s);
}

void photo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_stickers_ << 0) | ((!video_sizes_.empty()) << 1)));
    if (var0 & 1) { s.store_field("has_stickers", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_field("date", date_);
    { s.store_vector_begin("sizes", sizes_.size()); for (const auto &_value : sizes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 2) { { s.store_vector_begin("video_sizes", video_sizes_.size()); for (const auto &_value : video_sizes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("dc_id", dc_id_);
    s.store_class_end();
  }
}

object_ptr<PrivacyRule> PrivacyRule::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t privacyValueAllowContacts::ID;

object_ptr<PrivacyRule> privacyValueAllowContacts::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowContacts>();
}

void privacyValueAllowContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueAllowContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueAllowContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowContacts");
    s.store_class_end();
  }
}

const std::int32_t privacyValueAllowAll::ID;

object_ptr<PrivacyRule> privacyValueAllowAll::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowAll>();
}

void privacyValueAllowAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueAllowAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueAllowAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowAll");
    s.store_class_end();
  }
}

privacyValueAllowUsers::privacyValueAllowUsers(array<int64> &&users_)
  : users_(std::move(users_))
{}

const std::int32_t privacyValueAllowUsers::ID;

object_ptr<PrivacyRule> privacyValueAllowUsers::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowUsers>(p);
}

privacyValueAllowUsers::privacyValueAllowUsers(TlBufferParser &p)
  : users_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void privacyValueAllowUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(users_, s);
}

void privacyValueAllowUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(users_, s);
}

void privacyValueAllowUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowUsers");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t privacyValueDisallowContacts::ID;

object_ptr<PrivacyRule> privacyValueDisallowContacts::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueDisallowContacts>();
}

void privacyValueDisallowContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueDisallowContacts");
    s.store_class_end();
  }
}

const std::int32_t privacyValueDisallowAll::ID;

object_ptr<PrivacyRule> privacyValueDisallowAll::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueDisallowAll>();
}

void privacyValueDisallowAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueDisallowAll");
    s.store_class_end();
  }
}

privacyValueDisallowUsers::privacyValueDisallowUsers(array<int64> &&users_)
  : users_(std::move(users_))
{}

const std::int32_t privacyValueDisallowUsers::ID;

object_ptr<PrivacyRule> privacyValueDisallowUsers::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueDisallowUsers>(p);
}

privacyValueDisallowUsers::privacyValueDisallowUsers(TlBufferParser &p)
  : users_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void privacyValueDisallowUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(users_, s);
}

void privacyValueDisallowUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(users_, s);
}

void privacyValueDisallowUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueDisallowUsers");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

privacyValueAllowChatParticipants::privacyValueAllowChatParticipants(array<int64> &&chats_)
  : chats_(std::move(chats_))
{}

const std::int32_t privacyValueAllowChatParticipants::ID;

object_ptr<PrivacyRule> privacyValueAllowChatParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowChatParticipants>(p);
}

privacyValueAllowChatParticipants::privacyValueAllowChatParticipants(TlBufferParser &p)
  : chats_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void privacyValueAllowChatParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void privacyValueAllowChatParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void privacyValueAllowChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowChatParticipants");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

privacyValueDisallowChatParticipants::privacyValueDisallowChatParticipants(array<int64> &&chats_)
  : chats_(std::move(chats_))
{}

const std::int32_t privacyValueDisallowChatParticipants::ID;

object_ptr<PrivacyRule> privacyValueDisallowChatParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueDisallowChatParticipants>(p);
}

privacyValueDisallowChatParticipants::privacyValueDisallowChatParticipants(TlBufferParser &p)
  : chats_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void privacyValueDisallowChatParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void privacyValueDisallowChatParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void privacyValueDisallowChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueDisallowChatParticipants");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t privacyValueAllowCloseFriends::ID;

object_ptr<PrivacyRule> privacyValueAllowCloseFriends::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowCloseFriends>();
}

void privacyValueAllowCloseFriends::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueAllowCloseFriends::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueAllowCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowCloseFriends");
    s.store_class_end();
  }
}

const std::int32_t privacyValueAllowPremium::ID;

object_ptr<PrivacyRule> privacyValueAllowPremium::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowPremium>();
}

void privacyValueAllowPremium::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueAllowPremium::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueAllowPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowPremium");
    s.store_class_end();
  }
}

const std::int32_t privacyValueAllowBots::ID;

object_ptr<PrivacyRule> privacyValueAllowBots::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowBots>();
}

void privacyValueAllowBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueAllowBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueAllowBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowBots");
    s.store_class_end();
  }
}

const std::int32_t privacyValueDisallowBots::ID;

object_ptr<PrivacyRule> privacyValueDisallowBots::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueDisallowBots>();
}

void privacyValueDisallowBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueDisallowBots");
    s.store_class_end();
  }
}

object_ptr<ProfileTab> ProfileTab::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t profileTabPosts::ID;

object_ptr<ProfileTab> profileTabPosts::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabPosts>();
}

void profileTabPosts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabPosts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabPosts");
    s.store_class_end();
  }
}

const std::int32_t profileTabGifts::ID;

object_ptr<ProfileTab> profileTabGifts::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabGifts>();
}

void profileTabGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabGifts");
    s.store_class_end();
  }
}

const std::int32_t profileTabMedia::ID;

object_ptr<ProfileTab> profileTabMedia::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabMedia>();
}

void profileTabMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabMedia");
    s.store_class_end();
  }
}

const std::int32_t profileTabFiles::ID;

object_ptr<ProfileTab> profileTabFiles::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabFiles>();
}

void profileTabFiles::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabFiles::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabFiles");
    s.store_class_end();
  }
}

const std::int32_t profileTabMusic::ID;

object_ptr<ProfileTab> profileTabMusic::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabMusic>();
}

void profileTabMusic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabMusic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabMusic");
    s.store_class_end();
  }
}

const std::int32_t profileTabVoice::ID;

object_ptr<ProfileTab> profileTabVoice::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabVoice>();
}

void profileTabVoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabVoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabVoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabVoice");
    s.store_class_end();
  }
}

const std::int32_t profileTabLinks::ID;

object_ptr<ProfileTab> profileTabLinks::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabLinks>();
}

void profileTabLinks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabLinks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabLinks");
    s.store_class_end();
  }
}

const std::int32_t profileTabGifs::ID;

object_ptr<ProfileTab> profileTabGifs::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabGifs>();
}

void profileTabGifs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabGifs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabGifs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabGifs");
    s.store_class_end();
  }
}

savedReactionTag::savedReactionTag()
  : flags_()
  , reaction_()
  , title_()
  , count_()
{}

const std::int32_t savedReactionTag::ID;

object_ptr<savedReactionTag> savedReactionTag::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<savedReactionTag> res = make_tl_object<savedReactionTag>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->reaction_ = TlFetchObject<Reaction>::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  res->count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void savedReactionTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedReactionTag");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 0)));
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    if (var0 & 1) { s.store_field("title", title_); }
    s.store_field("count", count_);
    s.store_class_end();
  }
}

savedStarGift::savedStarGift()
  : flags_()
  , name_hidden_()
  , unsaved_()
  , refunded_()
  , can_upgrade_()
  , pinned_to_top_()
  , upgrade_separate_()
  , from_id_()
  , date_()
  , gift_()
  , message_()
  , msg_id_()
  , saved_id_()
  , convert_stars_()
  , upgrade_stars_()
  , can_export_at_()
  , transfer_stars_()
  , can_transfer_at_()
  , can_resell_at_()
  , collection_id_()
  , prepaid_upgrade_hash_()
  , drop_original_details_stars_()
  , gift_num_()
  , can_craft_at_()
{}

const std::int32_t savedStarGift::ID;

object_ptr<savedStarGift> savedStarGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<savedStarGift> res = make_tl_object<savedStarGift>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->name_hidden_ = (var0 & 1) != 0;
  res->unsaved_ = (var0 & 32) != 0;
  res->refunded_ = (var0 & 512) != 0;
  res->can_upgrade_ = (var0 & 1024) != 0;
  res->pinned_to_top_ = (var0 & 4096) != 0;
  res->upgrade_separate_ = (var0 & 131072) != 0;
  if (var0 & 2) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->gift_ = TlFetchObject<StarGift>::parse(p);
  if (var0 & 4) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (var0 & 8) { res->msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->saved_id_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->convert_stars_ = TlFetchLong::parse(p); }
  if (var0 & 64) { res->upgrade_stars_ = TlFetchLong::parse(p); }
  if (var0 & 128) { res->can_export_at_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->transfer_stars_ = TlFetchLong::parse(p); }
  if (var0 & 8192) { res->can_transfer_at_ = TlFetchInt::parse(p); }
  if (var0 & 16384) { res->can_resell_at_ = TlFetchInt::parse(p); }
  if (var0 & 32768) { res->collection_id_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (var0 & 65536) { res->prepaid_upgrade_hash_ = TlFetchString<string>::parse(p); }
  if (var0 & 262144) { res->drop_original_details_stars_ = TlFetchLong::parse(p); }
  if (var0 & 524288) { res->gift_num_ = TlFetchInt::parse(p); }
  if (var0 & 1048576) { res->can_craft_at_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void savedStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedStarGift");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (name_hidden_ << 0) | (unsaved_ << 5) | (refunded_ << 9) | (can_upgrade_ << 10) | (pinned_to_top_ << 12) | (upgrade_separate_ << 17) | ((from_id_ != nullptr) << 1) | ((message_ != nullptr) << 2) | ((!collection_id_.empty()) << 15) | ((!prepaid_upgrade_hash_.empty()) << 16)));
    if (var0 & 1) { s.store_field("name_hidden", true); }
    if (var0 & 32) { s.store_field("unsaved", true); }
    if (var0 & 512) { s.store_field("refunded", true); }
    if (var0 & 1024) { s.store_field("can_upgrade", true); }
    if (var0 & 4096) { s.store_field("pinned_to_top", true); }
    if (var0 & 131072) { s.store_field("upgrade_separate", true); }
    if (var0 & 2) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    s.store_field("date", date_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    if (var0 & 4) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    if (var0 & 8) { s.store_field("msg_id", msg_id_); }
    if (var0 & 2048) { s.store_field("saved_id", saved_id_); }
    if (var0 & 16) { s.store_field("convert_stars", convert_stars_); }
    if (var0 & 64) { s.store_field("upgrade_stars", upgrade_stars_); }
    if (var0 & 128) { s.store_field("can_export_at", can_export_at_); }
    if (var0 & 256) { s.store_field("transfer_stars", transfer_stars_); }
    if (var0 & 8192) { s.store_field("can_transfer_at", can_transfer_at_); }
    if (var0 & 16384) { s.store_field("can_resell_at", can_resell_at_); }
    if (var0 & 32768) { { s.store_vector_begin("collection_id", collection_id_.size()); for (const auto &_value : collection_id_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 65536) { s.store_field("prepaid_upgrade_hash", prepaid_upgrade_hash_); }
    if (var0 & 262144) { s.store_field("drop_original_details_stars", drop_original_details_stars_); }
    if (var0 & 524288) { s.store_field("gift_num", gift_num_); }
    if (var0 & 1048576) { s.store_field("can_craft_at", can_craft_at_); }
    s.store_class_end();
  }
}

const std::int32_t searchResultsCalendarPeriod::ID;

object_ptr<searchResultsCalendarPeriod> searchResultsCalendarPeriod::fetch(TlBufferParser &p) {
  return make_tl_object<searchResultsCalendarPeriod>(p);
}

searchResultsCalendarPeriod::searchResultsCalendarPeriod(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , min_msg_id_(TlFetchInt::parse(p))
  , max_msg_id_(TlFetchInt::parse(p))
  , count_(TlFetchInt::parse(p))
{}

void searchResultsCalendarPeriod::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchResultsCalendarPeriod");
    s.store_field("date", date_);
    s.store_field("min_msg_id", min_msg_id_);
    s.store_field("max_msg_id", max_msg_id_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

object_ptr<SecureFile> SecureFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case secureFileEmpty::ID:
      return secureFileEmpty::fetch(p);
    case secureFile::ID:
      return secureFile::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t secureFileEmpty::ID;

object_ptr<SecureFile> secureFileEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<secureFileEmpty>();
}

void secureFileEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureFileEmpty");
    s.store_class_end();
  }
}

const std::int32_t secureFile::ID;

object_ptr<SecureFile> secureFile::fetch(TlBufferParser &p) {
  return make_tl_object<secureFile>(p);
}

secureFile::secureFile(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , size_(TlFetchLong::parse(p))
  , dc_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , secret_(TlFetchBytes<bytes>::parse(p))
{}

void secureFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureFile");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("size", size_);
    s.store_field("dc_id", dc_id_);
    s.store_field("date", date_);
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("secret", "[REDACTED]");
    s.store_class_end();
  }
}

object_ptr<SecurePlainData> SecurePlainData::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case securePlainPhone::ID:
      return securePlainPhone::fetch(p);
    case securePlainEmail::ID:
      return securePlainEmail::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

securePlainPhone::securePlainPhone(string const &phone_)
  : phone_(phone_)
{}

const std::int32_t securePlainPhone::ID;

object_ptr<SecurePlainData> securePlainPhone::fetch(TlBufferParser &p) {
  return make_tl_object<securePlainPhone>(p);
}

securePlainPhone::securePlainPhone(TlBufferParser &p)
  : phone_(TlFetchString<string>::parse(p))
{}

void securePlainPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_, s);
}

void securePlainPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_, s);
}

void securePlainPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "securePlainPhone");
    s.store_field("phone", phone_);
    s.store_class_end();
  }
}

securePlainEmail::securePlainEmail(string const &email_)
  : email_(email_)
{}

const std::int32_t securePlainEmail::ID;

object_ptr<SecurePlainData> securePlainEmail::fetch(TlBufferParser &p) {
  return make_tl_object<securePlainEmail>(p);
}

securePlainEmail::securePlainEmail(TlBufferParser &p)
  : email_(TlFetchString<string>::parse(p))
{}

void securePlainEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(email_, s);
}

void securePlainEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(email_, s);
}

void securePlainEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "securePlainEmail");
    s.store_field("email", email_);
    s.store_class_end();
  }
}

secureValue::secureValue()
  : flags_()
  , type_()
  , data_()
  , front_side_()
  , reverse_side_()
  , selfie_()
  , translation_()
  , files_()
  , plain_data_()
  , hash_()
{}

const std::int32_t secureValue::ID;

object_ptr<secureValue> secureValue::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<secureValue> res = make_tl_object<secureValue>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->type_ = TlFetchObject<SecureValueType>::parse(p);
  if (var0 & 1) { res->data_ = TlFetchBoxed<TlFetchObject<secureData>, -1964327229>::parse(p); }
  if (var0 & 2) { res->front_side_ = TlFetchObject<SecureFile>::parse(p); }
  if (var0 & 4) { res->reverse_side_ = TlFetchObject<SecureFile>::parse(p); }
  if (var0 & 8) { res->selfie_ = TlFetchObject<SecureFile>::parse(p); }
  if (var0 & 64) { res->translation_ = TlFetchBoxed<TlFetchVector<TlFetchObject<SecureFile>>, 481674261>::parse(p); }
  if (var0 & 16) { res->files_ = TlFetchBoxed<TlFetchVector<TlFetchObject<SecureFile>>, 481674261>::parse(p); }
  if (var0 & 32) { res->plain_data_ = TlFetchObject<SecurePlainData>::parse(p); }
  res->hash_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void secureValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValue");
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
    s.store_bytes_field("hash", hash_);
    s.store_class_end();
  }
}

sponsoredPeer::sponsoredPeer()
  : flags_()
  , random_id_()
  , peer_()
  , sponsor_info_()
  , additional_info_()
{}

const std::int32_t sponsoredPeer::ID;

object_ptr<sponsoredPeer> sponsoredPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<sponsoredPeer> res = make_tl_object<sponsoredPeer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->random_id_ = TlFetchBytes<bytes>::parse(p);
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->sponsor_info_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->additional_info_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void sponsoredPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredPeer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!sponsor_info_.empty()) << 0) | ((!additional_info_.empty()) << 1)));
    s.store_bytes_field("random_id", random_id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("sponsor_info", sponsor_info_); }
    if (var0 & 2) { s.store_field("additional_info", additional_info_); }
    s.store_class_end();
  }
}

object_ptr<StarGiftAttribute> StarGiftAttribute::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starGiftAttributeModel::ID:
      return starGiftAttributeModel::fetch(p);
    case starGiftAttributePattern::ID:
      return starGiftAttributePattern::fetch(p);
    case starGiftAttributeBackdrop::ID:
      return starGiftAttributeBackdrop::fetch(p);
    case starGiftAttributeOriginalDetails::ID:
      return starGiftAttributeOriginalDetails::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

starGiftAttributeModel::starGiftAttributeModel()
  : flags_()
  , crafted_()
  , name_()
  , document_()
  , rarity_()
{}

starGiftAttributeModel::starGiftAttributeModel(int32 flags_, bool crafted_, string const &name_, object_ptr<Document> &&document_, object_ptr<StarGiftAttributeRarity> &&rarity_)
  : flags_(flags_)
  , crafted_(crafted_)
  , name_(name_)
  , document_(std::move(document_))
  , rarity_(std::move(rarity_))
{}

const std::int32_t starGiftAttributeModel::ID;

object_ptr<StarGiftAttribute> starGiftAttributeModel::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftAttributeModel> res = make_tl_object<starGiftAttributeModel>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->crafted_ = (var0 & 1) != 0;
  res->name_ = TlFetchString<string>::parse(p);
  res->document_ = TlFetchObject<Document>::parse(p);
  res->rarity_ = TlFetchObject<StarGiftAttributeRarity>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void starGiftAttributeModel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (crafted_ << 0)), s);
  TlStoreString::store(name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributeModel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (crafted_ << 0)), s);
  TlStoreString::store(name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributeModel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeModel");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (crafted_ << 0)));
    if (var0 & 1) { s.store_field("crafted", true); }
    s.store_field("name", name_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_class_end();
  }
}

starGiftAttributePattern::starGiftAttributePattern(string const &name_, object_ptr<Document> &&document_, object_ptr<StarGiftAttributeRarity> &&rarity_)
  : name_(name_)
  , document_(std::move(document_))
  , rarity_(std::move(rarity_))
{}

const std::int32_t starGiftAttributePattern::ID;

object_ptr<StarGiftAttribute> starGiftAttributePattern::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributePattern>(p);
}

starGiftAttributePattern::starGiftAttributePattern(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
  , document_(TlFetchObject<Document>::parse(p))
  , rarity_(TlFetchObject<StarGiftAttributeRarity>::parse(p))
{}

void starGiftAttributePattern::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributePattern::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributePattern::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributePattern");
    s.store_field("name", name_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_class_end();
  }
}

starGiftAttributeBackdrop::starGiftAttributeBackdrop(string const &name_, int32 backdrop_id_, int32 center_color_, int32 edge_color_, int32 pattern_color_, int32 text_color_, object_ptr<StarGiftAttributeRarity> &&rarity_)
  : name_(name_)
  , backdrop_id_(backdrop_id_)
  , center_color_(center_color_)
  , edge_color_(edge_color_)
  , pattern_color_(pattern_color_)
  , text_color_(text_color_)
  , rarity_(std::move(rarity_))
{}

const std::int32_t starGiftAttributeBackdrop::ID;

object_ptr<StarGiftAttribute> starGiftAttributeBackdrop::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeBackdrop>(p);
}

starGiftAttributeBackdrop::starGiftAttributeBackdrop(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
  , backdrop_id_(TlFetchInt::parse(p))
  , center_color_(TlFetchInt::parse(p))
  , edge_color_(TlFetchInt::parse(p))
  , pattern_color_(TlFetchInt::parse(p))
  , text_color_(TlFetchInt::parse(p))
  , rarity_(TlFetchObject<StarGiftAttributeRarity>::parse(p))
{}

void starGiftAttributeBackdrop::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
  TlStoreBinary::store(backdrop_id_, s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(pattern_color_, s);
  TlStoreBinary::store(text_color_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributeBackdrop::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
  TlStoreBinary::store(backdrop_id_, s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(pattern_color_, s);
  TlStoreBinary::store(text_color_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributeBackdrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeBackdrop");
    s.store_field("name", name_);
    s.store_field("backdrop_id", backdrop_id_);
    s.store_field("center_color", center_color_);
    s.store_field("edge_color", edge_color_);
    s.store_field("pattern_color", pattern_color_);
    s.store_field("text_color", text_color_);
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_class_end();
  }
}

starGiftAttributeOriginalDetails::starGiftAttributeOriginalDetails()
  : flags_()
  , sender_id_()
  , recipient_id_()
  , date_()
  , message_()
{}

starGiftAttributeOriginalDetails::starGiftAttributeOriginalDetails(int32 flags_, object_ptr<Peer> &&sender_id_, object_ptr<Peer> &&recipient_id_, int32 date_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , sender_id_(std::move(sender_id_))
  , recipient_id_(std::move(recipient_id_))
  , date_(date_)
  , message_(std::move(message_))
{}

const std::int32_t starGiftAttributeOriginalDetails::ID;

object_ptr<StarGiftAttribute> starGiftAttributeOriginalDetails::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftAttributeOriginalDetails> res = make_tl_object<starGiftAttributeOriginalDetails>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->sender_id_ = TlFetchObject<Peer>::parse(p); }
  res->recipient_id_ = TlFetchObject<Peer>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void starGiftAttributeOriginalDetails::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((sender_id_ != nullptr) << 0) | ((message_ != nullptr) << 1)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(sender_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(recipient_id_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void starGiftAttributeOriginalDetails::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((sender_id_ != nullptr) << 0) | ((message_ != nullptr) << 1)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(sender_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(recipient_id_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void starGiftAttributeOriginalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeOriginalDetails");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((sender_id_ != nullptr) << 0) | ((message_ != nullptr) << 1)));
    if (var0 & 1) { s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get())); }
    s.store_object_field("recipient_id", static_cast<const BaseObject *>(recipient_id_.get()));
    s.store_field("date", date_);
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

const std::int32_t starGiftAttributeCounter::ID;

object_ptr<starGiftAttributeCounter> starGiftAttributeCounter::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeCounter>(p);
}

starGiftAttributeCounter::starGiftAttributeCounter(TlBufferParser &p)
  : attribute_(TlFetchObject<StarGiftAttributeId>::parse(p))
  , count_(TlFetchInt::parse(p))
{}

void starGiftAttributeCounter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeCounter");
    s.store_object_field("attribute", static_cast<const BaseObject *>(attribute_.get()));
    s.store_field("count", count_);
    s.store_class_end();
  }
}

starsGiveawayOption::starsGiveawayOption()
  : flags_()
  , extended_()
  , default_()
  , stars_()
  , yearly_boosts_()
  , store_product_()
  , currency_()
  , amount_()
  , winners_()
{}

const std::int32_t starsGiveawayOption::ID;

object_ptr<starsGiveawayOption> starsGiveawayOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsGiveawayOption> res = make_tl_object<starsGiveawayOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->extended_ = (var0 & 1) != 0;
  res->default_ = (var0 & 2) != 0;
  res->stars_ = TlFetchLong::parse(p);
  res->yearly_boosts_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->store_product_ = TlFetchString<string>::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->winners_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsGiveawayWinnersOption>, 1411605001>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsGiveawayOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsGiveawayOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (extended_ << 0) | (default_ << 1) | ((!store_product_.empty()) << 2)));
    if (var0 & 1) { s.store_field("extended", true); }
    if (var0 & 2) { s.store_field("default", true); }
    s.store_field("stars", stars_);
    s.store_field("yearly_boosts", yearly_boosts_);
    if (var0 & 4) { s.store_field("store_product", store_product_); }
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    { s.store_vector_begin("winners", winners_.size()); for (const auto &_value : winners_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

tonConnectSession::tonConnectSession()
  : flags_()
  , pending_()
  , closing_()
  , closed_()
  , id_()
  , dapp_client_id_()
  , client_id_()
  , nonce_()
  , manifest_()
  , manifest_error_()
  , date_()
{}

const std::int32_t tonConnectSession::ID;

object_ptr<tonConnectSession> tonConnectSession::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<tonConnectSession> res = make_tl_object<tonConnectSession>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pending_ = (var0 & 1) != 0;
  res->closing_ = (var0 & 2) != 0;
  res->closed_ = (var0 & 4) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->dapp_client_id_ = TlFetchString<string>::parse(p);
  if (var0 & 8) { res->client_id_ = TlFetchString<string>::parse(p); }
  res->nonce_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 16) { res->manifest_ = TlFetchBoxed<TlFetchObject<tonConnectManifest>, 304255588>::parse(p); }
  if (var0 & 32) { res->manifest_error_ = TlFetchInt::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void tonConnectSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonConnectSession");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pending_ << 0) | (closing_ << 1) | (closed_ << 2) | ((!client_id_.empty()) << 3) | ((manifest_ != nullptr) << 4)));
    if (var0 & 1) { s.store_field("pending", true); }
    if (var0 & 2) { s.store_field("closing", true); }
    if (var0 & 4) { s.store_field("closed", true); }
    s.store_field("id", id_);
    s.store_field("dapp_client_id", dapp_client_id_);
    if (var0 & 8) { s.store_field("client_id", client_id_); }
    s.store_bytes_field("nonce", nonce_);
    if (var0 & 16) { s.store_object_field("manifest", static_cast<const BaseObject *>(manifest_.get())); }
    if (var0 & 32) { s.store_field("manifest_error", manifest_error_); }
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<WebPage> WebPage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case webPageEmpty::ID:
      return webPageEmpty::fetch(p);
    case webPagePending::ID:
      return webPagePending::fetch(p);
    case webPage::ID:
      return webPage::fetch(p);
    case webPageNotModified::ID:
      return webPageNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

webPageEmpty::webPageEmpty()
  : flags_()
  , id_()
  , url_()
{}

webPageEmpty::webPageEmpty(int32 flags_, int64 id_, string const &url_)
  : flags_(flags_)
  , id_(id_)
  , url_(url_)
{}

const std::int32_t webPageEmpty::ID;

object_ptr<WebPage> webPageEmpty::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPageEmpty> res = make_tl_object<webPageEmpty>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->url_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPageEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!url_.empty()) << 0)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
}

void webPageEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!url_.empty()) << 0)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
}

void webPageEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageEmpty");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!url_.empty()) << 0)));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("url", url_); }
    s.store_class_end();
  }
}

webPagePending::webPagePending()
  : flags_()
  , id_()
  , url_()
  , date_()
{}

webPagePending::webPagePending(int32 flags_, int64 id_, string const &url_, int32 date_)
  : flags_(flags_)
  , id_(id_)
  , url_(url_)
  , date_(date_)
{}

const std::int32_t webPagePending::ID;

object_ptr<WebPage> webPagePending::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPagePending> res = make_tl_object<webPagePending>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->url_ = TlFetchString<string>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPagePending::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!url_.empty()) << 0)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
  TlStoreBinary::store(date_, s);
}

void webPagePending::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!url_.empty()) << 0)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
  TlStoreBinary::store(date_, s);
}

void webPagePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPagePending");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!url_.empty()) << 0)));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("url", url_); }
    s.store_field("date", date_);
    s.store_class_end();
  }
}

webPage::webPage()
  : flags_()
  , has_large_media_()
  , video_cover_photo_()
  , id_()
  , url_()
  , display_url_()
  , hash_()
  , type_()
  , site_name_()
  , title_()
  , description_()
  , photo_()
  , embed_url_()
  , embed_type_()
  , embed_width_()
  , embed_height_()
  , duration_()
  , author_()
  , document_()
  , cached_page_()
  , attributes_()
{}

webPage::webPage(int32 flags_, bool has_large_media_, bool video_cover_photo_, int64 id_, string const &url_, string const &display_url_, int32 hash_, string const &type_, string const &site_name_, string const &title_, string const &description_, object_ptr<Photo> &&photo_, string const &embed_url_, string const &embed_type_, int32 embed_width_, int32 embed_height_, int32 duration_, string const &author_, object_ptr<Document> &&document_, object_ptr<page> &&cached_page_, array<object_ptr<WebPageAttribute>> &&attributes_)
  : flags_(flags_)
  , has_large_media_(has_large_media_)
  , video_cover_photo_(video_cover_photo_)
  , id_(id_)
  , url_(url_)
  , display_url_(display_url_)
  , hash_(hash_)
  , type_(type_)
  , site_name_(site_name_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , embed_url_(embed_url_)
  , embed_type_(embed_type_)
  , embed_width_(embed_width_)
  , embed_height_(embed_height_)
  , duration_(duration_)
  , author_(author_)
  , document_(std::move(document_))
  , cached_page_(std::move(cached_page_))
  , attributes_(std::move(attributes_))
{}

const std::int32_t webPage::ID;

object_ptr<WebPage> webPage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPage> res = make_tl_object<webPage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_large_media_ = (var0 & 8192) != 0;
  res->video_cover_photo_ = (var0 & 16384) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  res->display_url_ = TlFetchString<string>::parse(p);
  res->hash_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->type_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->site_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->description_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 32) { res->embed_url_ = TlFetchString<string>::parse(p); }
  if (var0 & 32) { res->embed_type_ = TlFetchString<string>::parse(p); }
  if (var0 & 64) { res->embed_width_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->embed_height_ = TlFetchInt::parse(p); }
  if (var0 & 128) { res->duration_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->author_ = TlFetchString<string>::parse(p); }
  if (var0 & 512) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 1024) { res->cached_page_ = TlFetchBoxed<TlFetchObject<page>, -1738178803>::parse(p); }
  if (var0 & 4096) { res->attributes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<WebPageAttribute>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_large_media_ << 13) | (video_cover_photo_ << 14) | ((!type_.empty()) << 0) | ((!site_name_.empty()) << 1) | ((!title_.empty()) << 2) | ((!description_.empty()) << 3) | ((photo_ != nullptr) << 4) | ((!embed_url_.empty()) << 5) | ((!embed_type_.empty()) << 5) | ((!author_.empty()) << 8) | ((document_ != nullptr) << 9) | ((cached_page_ != nullptr) << 10) | ((!attributes_.empty()) << 12)), s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(url_, s);
  TlStoreString::store(display_url_, s);
  TlStoreBinary::store(hash_, s);
  if (var0 & 1) { TlStoreString::store(type_, s); }
  if (var0 & 2) { TlStoreString::store(site_name_, s); }
  if (var0 & 4) { TlStoreString::store(title_, s); }
  if (var0 & 8) { TlStoreString::store(description_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 32) { TlStoreString::store(embed_url_, s); }
  if (var0 & 32) { TlStoreString::store(embed_type_, s); }
  if (var0 & 64) { TlStoreBinary::store(embed_width_, s); }
  if (var0 & 64) { TlStoreBinary::store(embed_height_, s); }
  if (var0 & 128) { TlStoreBinary::store(duration_, s); }
  if (var0 & 256) { TlStoreString::store(author_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, -1738178803>::store(cached_page_, s); }
  if (var0 & 4096) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s); }
}

void webPage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_large_media_ << 13) | (video_cover_photo_ << 14) | ((!type_.empty()) << 0) | ((!site_name_.empty()) << 1) | ((!title_.empty()) << 2) | ((!description_.empty()) << 3) | ((photo_ != nullptr) << 4) | ((!embed_url_.empty()) << 5) | ((!embed_type_.empty()) << 5) | ((!author_.empty()) << 8) | ((document_ != nullptr) << 9) | ((cached_page_ != nullptr) << 10) | ((!attributes_.empty()) << 12)), s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(url_, s);
  TlStoreString::store(display_url_, s);
  TlStoreBinary::store(hash_, s);
  if (var0 & 1) { TlStoreString::store(type_, s); }
  if (var0 & 2) { TlStoreString::store(site_name_, s); }
  if (var0 & 4) { TlStoreString::store(title_, s); }
  if (var0 & 8) { TlStoreString::store(description_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 32) { TlStoreString::store(embed_url_, s); }
  if (var0 & 32) { TlStoreString::store(embed_type_, s); }
  if (var0 & 64) { TlStoreBinary::store(embed_width_, s); }
  if (var0 & 64) { TlStoreBinary::store(embed_height_, s); }
  if (var0 & 128) { TlStoreBinary::store(duration_, s); }
  if (var0 & 256) { TlStoreString::store(author_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, -1738178803>::store(cached_page_, s); }
  if (var0 & 4096) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s); }
}

void webPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_large_media_ << 13) | (video_cover_photo_ << 14) | ((!type_.empty()) << 0) | ((!site_name_.empty()) << 1) | ((!title_.empty()) << 2) | ((!description_.empty()) << 3) | ((photo_ != nullptr) << 4) | ((!embed_url_.empty()) << 5) | ((!embed_type_.empty()) << 5) | ((!author_.empty()) << 8) | ((document_ != nullptr) << 9) | ((cached_page_ != nullptr) << 10) | ((!attributes_.empty()) << 12)));
    if (var0 & 8192) { s.store_field("has_large_media", true); }
    if (var0 & 16384) { s.store_field("video_cover_photo", true); }
    s.store_field("id", id_);
    s.store_field("url", url_);
    s.store_field("display_url", display_url_);
    s.store_field("hash", hash_);
    if (var0 & 1) { s.store_field("type", type_); }
    if (var0 & 2) { s.store_field("site_name", site_name_); }
    if (var0 & 4) { s.store_field("title", title_); }
    if (var0 & 8) { s.store_field("description", description_); }
    if (var0 & 16) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 32) { s.store_field("embed_url", embed_url_); }
    if (var0 & 32) { s.store_field("embed_type", embed_type_); }
    if (var0 & 64) { s.store_field("embed_width", embed_width_); }
    if (var0 & 64) { s.store_field("embed_height", embed_height_); }
    if (var0 & 128) { s.store_field("duration", duration_); }
    if (var0 & 256) { s.store_field("author", author_); }
    if (var0 & 512) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 1024) { s.store_object_field("cached_page", static_cast<const BaseObject *>(cached_page_.get())); }
    if (var0 & 4096) { { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

webPageNotModified::webPageNotModified()
  : flags_()
  , cached_page_views_()
{}

webPageNotModified::webPageNotModified(int32 flags_, int32 cached_page_views_)
  : flags_(flags_)
  , cached_page_views_(cached_page_views_)
{}

const std::int32_t webPageNotModified::ID;

object_ptr<WebPage> webPageNotModified::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPageNotModified> res = make_tl_object<webPageNotModified>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->cached_page_views_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPageNotModified::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(cached_page_views_, s); }
}

void webPageNotModified::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(cached_page_views_, s); }
}

void webPageNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageNotModified");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("cached_page_views", cached_page_views_); }
    s.store_class_end();
  }
}

object_ptr<WebPageAttribute> WebPageAttribute::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

webPageAttributeTheme::webPageAttributeTheme()
  : flags_()
  , documents_()
  , settings_()
{}

webPageAttributeTheme::webPageAttributeTheme(int32 flags_, array<object_ptr<Document>> &&documents_, object_ptr<themeSettings> &&settings_)
  : flags_(flags_)
  , documents_(std::move(documents_))
  , settings_(std::move(settings_))
{}

const std::int32_t webPageAttributeTheme::ID;

object_ptr<WebPageAttribute> webPageAttributeTheme::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPageAttributeTheme> res = make_tl_object<webPageAttributeTheme>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->documents_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p); }
  if (var0 & 2) { res->settings_ = TlFetchBoxed<TlFetchObject<themeSettings>, -94849324>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPageAttributeTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!documents_.empty()) << 0) | ((settings_ != nullptr) << 1)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, -94849324>::store(settings_, s); }
}

void webPageAttributeTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((!documents_.empty()) << 0) | ((settings_ != nullptr) << 1)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, -94849324>::store(settings_, s); }
}

void webPageAttributeTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeTheme");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!documents_.empty()) << 0) | ((settings_ != nullptr) << 1)));
    if (var0 & 1) { { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get())); }
    s.store_class_end();
  }
}

webPageAttributeStory::webPageAttributeStory()
  : flags_()
  , peer_()
  , id_()
  , story_()
{}

webPageAttributeStory::webPageAttributeStory(int32 flags_, object_ptr<Peer> &&peer_, int32 id_, object_ptr<StoryItem> &&story_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , story_(std::move(story_))
{}

const std::int32_t webPageAttributeStory::ID;

object_ptr<WebPageAttribute> webPageAttributeStory::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPageAttributeStory> res = make_tl_object<webPageAttributeStory>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->story_ = TlFetchObject<StoryItem>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPageAttributeStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((story_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(story_, s); }
}

void webPageAttributeStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | ((story_ != nullptr) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(story_, s); }
}

void webPageAttributeStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeStory");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((story_ != nullptr) << 0)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("story", static_cast<const BaseObject *>(story_.get())); }
    s.store_class_end();
  }
}

webPageAttributeStickerSet::webPageAttributeStickerSet()
  : flags_()
  , emojis_()
  , text_color_()
  , stickers_()
{}

webPageAttributeStickerSet::webPageAttributeStickerSet(int32 flags_, bool emojis_, bool text_color_, array<object_ptr<Document>> &&stickers_)
  : flags_(flags_)
  , emojis_(emojis_)
  , text_color_(text_color_)
  , stickers_(std::move(stickers_))
{}

const std::int32_t webPageAttributeStickerSet::ID;

object_ptr<WebPageAttribute> webPageAttributeStickerSet::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPageAttributeStickerSet> res = make_tl_object<webPageAttributeStickerSet>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->emojis_ = (var0 & 1) != 0;
  res->text_color_ = (var0 & 2) != 0;
  res->stickers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPageAttributeStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (emojis_ << 0) | (text_color_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s);
}

void webPageAttributeStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (emojis_ << 0) | (text_color_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s);
}

void webPageAttributeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeStickerSet");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (emojis_ << 0) | (text_color_ << 1)));
    if (var0 & 1) { s.store_field("emojis", true); }
    if (var0 & 2) { s.store_field("text_color", true); }
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

webPageAttributeUniqueStarGift::webPageAttributeUniqueStarGift(object_ptr<StarGift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t webPageAttributeUniqueStarGift::ID;

object_ptr<WebPageAttribute> webPageAttributeUniqueStarGift::fetch(TlBufferParser &p) {
  return make_tl_object<webPageAttributeUniqueStarGift>(p);
}

webPageAttributeUniqueStarGift::webPageAttributeUniqueStarGift(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
{}

void webPageAttributeUniqueStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(gift_, s);
}

void webPageAttributeUniqueStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(gift_, s);
}

void webPageAttributeUniqueStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeUniqueStarGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

webPageAttributeStarGiftCollection::webPageAttributeStarGiftCollection(array<object_ptr<Document>> &&icons_)
  : icons_(std::move(icons_))
{}

const std::int32_t webPageAttributeStarGiftCollection::ID;

object_ptr<WebPageAttribute> webPageAttributeStarGiftCollection::fetch(TlBufferParser &p) {
  return make_tl_object<webPageAttributeStarGiftCollection>(p);
}

webPageAttributeStarGiftCollection::webPageAttributeStarGiftCollection(TlBufferParser &p)
  : icons_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void webPageAttributeStarGiftCollection::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(icons_, s);
}

void webPageAttributeStarGiftCollection::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(icons_, s);
}

void webPageAttributeStarGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeStarGiftCollection");
    { s.store_vector_begin("icons", icons_.size()); for (const auto &_value : icons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

webPageAttributeStarGiftAuction::webPageAttributeStarGiftAuction(object_ptr<StarGift> &&gift_, int32 end_date_)
  : gift_(std::move(gift_))
  , end_date_(end_date_)
{}

const std::int32_t webPageAttributeStarGiftAuction::ID;

object_ptr<WebPageAttribute> webPageAttributeStarGiftAuction::fetch(TlBufferParser &p) {
  return make_tl_object<webPageAttributeStarGiftAuction>(p);
}

webPageAttributeStarGiftAuction::webPageAttributeStarGiftAuction(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
  , end_date_(TlFetchInt::parse(p))
{}

void webPageAttributeStarGiftAuction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(gift_, s);
  TlStoreBinary::store(end_date_, s);
}

void webPageAttributeStarGiftAuction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(gift_, s);
  TlStoreBinary::store(end_date_, s);
}

void webPageAttributeStarGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeStarGiftAuction");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("end_date", end_date_);
    s.store_class_end();
  }
}

webPageAttributeAiComposeTone::webPageAttributeAiComposeTone(int64 emoji_id_)
  : emoji_id_(emoji_id_)
{}

const std::int32_t webPageAttributeAiComposeTone::ID;

object_ptr<WebPageAttribute> webPageAttributeAiComposeTone::fetch(TlBufferParser &p) {
  return make_tl_object<webPageAttributeAiComposeTone>(p);
}

webPageAttributeAiComposeTone::webPageAttributeAiComposeTone(TlBufferParser &p)
  : emoji_id_(TlFetchLong::parse(p))
{}

void webPageAttributeAiComposeTone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(emoji_id_, s);
}

void webPageAttributeAiComposeTone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(emoji_id_, s);
}

void webPageAttributeAiComposeTone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeAiComposeTone");
    s.store_field("emoji_id", emoji_id_);
    s.store_class_end();
  }
}

account_authorizationForm::account_authorizationForm()
  : flags_()
  , required_types_()
  , values_()
  , errors_()
  , users_()
  , privacy_policy_url_()
{}

const std::int32_t account_authorizationForm::ID;

object_ptr<account_authorizationForm> account_authorizationForm::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_authorizationForm> res = make_tl_object<account_authorizationForm>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->required_types_ = TlFetchBoxed<TlFetchVector<TlFetchObject<SecureRequiredType>>, 481674261>::parse(p);
  res->values_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<secureValue>, 411017418>>, 481674261>::parse(p);
  res->errors_ = TlFetchBoxed<TlFetchVector<TlFetchObject<SecureValueError>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->privacy_policy_url_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void account_authorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.authorizationForm");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!privacy_policy_url_.empty()) << 0)));
    { s.store_vector_begin("required_types", required_types_.size()); for (const auto &_value : required_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("values", values_.size()); for (const auto &_value : values_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("errors", errors_.size()); for (const auto &_value : errors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("privacy_policy_url", privacy_policy_url_); }
    s.store_class_end();
  }
}

account_resolvedBusinessChatLinks::account_resolvedBusinessChatLinks()
  : flags_()
  , peer_()
  , message_()
  , entities_()
  , chats_()
  , users_()
{}

const std::int32_t account_resolvedBusinessChatLinks::ID;

object_ptr<account_resolvedBusinessChatLinks> account_resolvedBusinessChatLinks::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_resolvedBusinessChatLinks> res = make_tl_object<account_resolvedBusinessChatLinks>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void account_resolvedBusinessChatLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resolvedBusinessChatLinks");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!entities_.empty()) << 0)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("message", message_);
    if (var0 & 1) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<aicompose_Tones> aicompose_Tones::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case aicompose_tonesNotModified::ID:
      return aicompose_tonesNotModified::fetch(p);
    case aicompose_tones::ID:
      return aicompose_tones::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t aicompose_tonesNotModified::ID;

object_ptr<aicompose_Tones> aicompose_tonesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<aicompose_tonesNotModified>();
}

void aicompose_tonesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aicompose.tonesNotModified");
    s.store_class_end();
  }
}

const std::int32_t aicompose_tones::ID;

object_ptr<aicompose_Tones> aicompose_tones::fetch(TlBufferParser &p) {
  return make_tl_object<aicompose_tones>(p);
}

aicompose_tones::aicompose_tones(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , tones_(TlFetchBoxed<TlFetchVector<TlFetchObject<AiComposeTone>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void aicompose_tones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aicompose.tones");
    s.store_field("hash", hash_);
    { s.store_vector_begin("tones", tones_.size()); for (const auto &_value : tones_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

bots_accessSettings::bots_accessSettings()
  : flags_()
  , restricted_()
  , add_users_()
{}

const std::int32_t bots_accessSettings::ID;

object_ptr<bots_accessSettings> bots_accessSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<bots_accessSettings> res = make_tl_object<bots_accessSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->restricted_ = (var0 & 1) != 0;
  if (var0 & 2) { res->add_users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void bots_accessSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.accessSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (restricted_ << 0) | ((!add_users_.empty()) << 1)));
    if (var0 & 1) { s.store_field("restricted", true); }
    if (var0 & 2) { { s.store_vector_begin("add_users", add_users_.size()); for (const auto &_value : add_users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t bots_requestedButton::ID;

object_ptr<bots_requestedButton> bots_requestedButton::fetch(TlBufferParser &p) {
  return make_tl_object<bots_requestedButton>(p);
}

bots_requestedButton::bots_requestedButton(TlBufferParser &p)
  : webapp_req_id_(TlFetchString<string>::parse(p))
{}

void bots_requestedButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.requestedButton");
    s.store_field("webapp_req_id", webapp_req_id_);
    s.store_class_end();
  }
}

object_ptr<chatlists_ChatlistInvite> chatlists_ChatlistInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatlists_chatlistInviteAlready::ID:
      return chatlists_chatlistInviteAlready::fetch(p);
    case chatlists_chatlistInvite::ID:
      return chatlists_chatlistInvite::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t chatlists_chatlistInviteAlready::ID;

object_ptr<chatlists_ChatlistInvite> chatlists_chatlistInviteAlready::fetch(TlBufferParser &p) {
  return make_tl_object<chatlists_chatlistInviteAlready>(p);
}

chatlists_chatlistInviteAlready::chatlists_chatlistInviteAlready(TlBufferParser &p)
  : filter_id_(TlFetchInt::parse(p))
  , missing_peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , already_peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void chatlists_chatlistInviteAlready::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.chatlistInviteAlready");
    s.store_field("filter_id", filter_id_);
    { s.store_vector_begin("missing_peers", missing_peers_.size()); for (const auto &_value : missing_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("already_peers", already_peers_.size()); for (const auto &_value : already_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatlists_chatlistInvite::chatlists_chatlistInvite()
  : flags_()
  , title_noanimate_()
  , title_()
  , emoticon_()
  , peers_()
  , chats_()
  , users_()
{}

const std::int32_t chatlists_chatlistInvite::ID;

object_ptr<chatlists_ChatlistInvite> chatlists_chatlistInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatlists_chatlistInvite> res = make_tl_object<chatlists_chatlistInvite>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->title_noanimate_ = (var0 & 2) != 0;
  res->title_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 1) { res->emoticon_ = TlFetchString<string>::parse(p); }
  res->peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatlists_chatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.chatlistInvite");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (title_noanimate_ << 1) | ((!emoticon_.empty()) << 0)));
    if (var0 & 2) { s.store_field("title_noanimate", true); }
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    if (var0 & 1) { s.store_field("emoticon", emoticon_); }
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t chatlists_exportedInvites::ID;

object_ptr<chatlists_exportedInvites> chatlists_exportedInvites::fetch(TlBufferParser &p) {
  return make_tl_object<chatlists_exportedInvites>(p);
}

chatlists_exportedInvites::chatlists_exportedInvites(TlBufferParser &p)
  : invites_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<exportedChatlistInvite>, 206668204>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void chatlists_exportedInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.exportedInvites");
    { s.store_vector_begin("invites", invites_.size()); for (const auto &_value : invites_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t contacts_importedContacts::ID;

object_ptr<contacts_importedContacts> contacts_importedContacts::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_importedContacts>(p);
}

contacts_importedContacts::contacts_importedContacts(TlBufferParser &p)
  : imported_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<importedContact>, -1052885936>>, 481674261>::parse(p))
  , popular_invites_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<popularContact>, 1558266229>>, 481674261>::parse(p))
  , retry_contacts_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_importedContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.importedContacts");
    { s.store_vector_begin("imported", imported_.size()); for (const auto &_value : imported_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("popular_invites", popular_invites_.size()); for (const auto &_value : popular_invites_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("retry_contacts", retry_contacts_.size()); for (const auto &_value : retry_contacts_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t help_premiumPromo::ID;

object_ptr<help_premiumPromo> help_premiumPromo::fetch(TlBufferParser &p) {
  return make_tl_object<help_premiumPromo>(p);
}

help_premiumPromo::help_premiumPromo(TlBufferParser &p)
  : status_text_(TlFetchString<string>::parse(p))
  , status_entities_(TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p))
  , video_sections_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
  , videos_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
  , period_options_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<premiumSubscriptionOption>, 1596792306>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void help_premiumPromo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.premiumPromo");
    s.store_field("status_text", status_text_);
    { s.store_vector_begin("status_entities", status_entities_.size()); for (const auto &_value : status_entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("video_sections", video_sections_.size()); for (const auto &_value : video_sections_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("videos", videos_.size()); for (const auto &_value : videos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("period_options", period_options_.size()); for (const auto &_value : period_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_AvailableEffects> messages_AvailableEffects::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_availableEffectsNotModified::ID:
      return messages_availableEffectsNotModified::fetch(p);
    case messages_availableEffects::ID:
      return messages_availableEffects::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_availableEffectsNotModified::ID;

object_ptr<messages_AvailableEffects> messages_availableEffectsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_availableEffectsNotModified>();
}

void messages_availableEffectsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.availableEffectsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_availableEffects::ID;

object_ptr<messages_AvailableEffects> messages_availableEffects::fetch(TlBufferParser &p) {
  return make_tl_object<messages_availableEffects>(p);
}

messages_availableEffects::messages_availableEffects(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , effects_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<availableEffect>, -1815879042>>, 481674261>::parse(p))
  , documents_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void messages_availableEffects::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.availableEffects");
    s.store_field("hash", hash_);
    { s.store_vector_begin("effects", effects_.size()); for (const auto &_value : effects_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_botCallbackAnswer::messages_botCallbackAnswer()
  : flags_()
  , alert_()
  , has_url_()
  , native_ui_()
  , message_()
  , url_()
  , cache_time_()
{}

const std::int32_t messages_botCallbackAnswer::ID;

object_ptr<messages_botCallbackAnswer> messages_botCallbackAnswer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_botCallbackAnswer> res = make_tl_object<messages_botCallbackAnswer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->alert_ = (var0 & 2) != 0;
  res->has_url_ = (var0 & 8) != 0;
  res->native_ui_ = (var0 & 16) != 0;
  if (var0 & 1) { res->message_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->url_ = TlFetchString<string>::parse(p); }
  res->cache_time_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_botCallbackAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.botCallbackAnswer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (alert_ << 1) | (has_url_ << 3) | (native_ui_ << 4) | ((!message_.empty()) << 0) | ((!url_.empty()) << 2)));
    if (var0 & 2) { s.store_field("alert", true); }
    if (var0 & 8) { s.store_field("has_url", true); }
    if (var0 & 16) { s.store_field("native_ui", true); }
    if (var0 & 1) { s.store_field("message", message_); }
    if (var0 & 4) { s.store_field("url", url_); }
    s.store_field("cache_time", cache_time_);
    s.store_class_end();
  }
}

const std::int32_t messages_botPreparedInlineMessage::ID;

object_ptr<messages_botPreparedInlineMessage> messages_botPreparedInlineMessage::fetch(TlBufferParser &p) {
  return make_tl_object<messages_botPreparedInlineMessage>(p);
}

messages_botPreparedInlineMessage::messages_botPreparedInlineMessage(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , expire_date_(TlFetchInt::parse(p))
{}

void messages_botPreparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.botPreparedInlineMessage");
    s.store_field("id", id_);
    s.store_field("expire_date", expire_date_);
    s.store_class_end();
  }
}

object_ptr<messages_ChatInviteJoinResult> messages_ChatInviteJoinResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_chatInviteJoinResultOk::ID:
      return messages_chatInviteJoinResultOk::fetch(p);
    case messages_chatInviteJoinResultWebView::ID:
      return messages_chatInviteJoinResultWebView::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_chatInviteJoinResultOk::ID;

object_ptr<messages_ChatInviteJoinResult> messages_chatInviteJoinResultOk::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chatInviteJoinResultOk>(p);
}

messages_chatInviteJoinResultOk::messages_chatInviteJoinResultOk(TlBufferParser &p)
  : updates_(TlFetchObject<Updates>::parse(p))
{}

void messages_chatInviteJoinResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chatInviteJoinResultOk");
    s.store_object_field("updates", static_cast<const BaseObject *>(updates_.get()));
    s.store_class_end();
  }
}

const std::int32_t messages_chatInviteJoinResultWebView::ID;

object_ptr<messages_ChatInviteJoinResult> messages_chatInviteJoinResultWebView::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chatInviteJoinResultWebView>(p);
}

messages_chatInviteJoinResultWebView::messages_chatInviteJoinResultWebView(TlBufferParser &p)
  : bot_id_(TlFetchLong::parse(p))
  , query_id_(TlFetchLong::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_chatInviteJoinResultWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chatInviteJoinResultWebView");
    s.store_field("bot_id", bot_id_);
    s.store_field("query_id", query_id_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_Chats> messages_Chats::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_chats::ID:
      return messages_chats::fetch(p);
    case messages_chatsSlice::ID:
      return messages_chatsSlice::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_chats::ID;

object_ptr<messages_Chats> messages_chats::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chats>(p);
}

messages_chats::messages_chats(TlBufferParser &p)
  : chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
{}

void messages_chats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chats");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_chatsSlice::ID;

object_ptr<messages_Chats> messages_chatsSlice::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chatsSlice>(p);
}

messages_chatsSlice::messages_chatsSlice(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
{}

void messages_chatsSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chatsSlice");
    s.store_field("count", count_);
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_Dialogs> messages_Dialogs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_dialogs::ID:
      return messages_dialogs::fetch(p);
    case messages_dialogsSlice::ID:
      return messages_dialogsSlice::fetch(p);
    case messages_dialogsNotModified::ID:
      return messages_dialogsNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messages_dialogs::messages_dialogs()
  : flags_()
  , topics_()
  , dialogs_()
  , messages_()
  , chats_()
  , users_()
{}

const std::int32_t messages_dialogs::ID;

object_ptr<messages_Dialogs> messages_dialogs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_dialogs> res = make_tl_object<messages_dialogs>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p); }
  res->dialogs_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Dialog>>, 481674261>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_dialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dialogs");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!topics_.empty()) << 0)));
    if (var0 & 1) { { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("dialogs", dialogs_.size()); for (const auto &_value : dialogs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_dialogsSlice::messages_dialogsSlice()
  : flags_()
  , count_()
  , topics_()
  , dialogs_()
  , messages_()
  , chats_()
  , users_()
{}

const std::int32_t messages_dialogsSlice::ID;

object_ptr<messages_Dialogs> messages_dialogsSlice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_dialogsSlice> res = make_tl_object<messages_dialogsSlice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p); }
  res->dialogs_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Dialog>>, 481674261>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_dialogsSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dialogsSlice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!topics_.empty()) << 0)));
    s.store_field("count", count_);
    if (var0 & 1) { { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("dialogs", dialogs_.size()); for (const auto &_value : dialogs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_dialogsNotModified::ID;

object_ptr<messages_Dialogs> messages_dialogsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_dialogsNotModified>(p);
}

messages_dialogsNotModified::messages_dialogsNotModified(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
{}

void messages_dialogsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dialogsNotModified");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

messages_forumTopics::messages_forumTopics()
  : flags_()
  , order_by_create_date_()
  , top_icons_()
  , count_()
  , topics_()
  , messages_()
  , chats_()
  , users_()
  , pts_()
{}

const std::int32_t messages_forumTopics::ID;

object_ptr<messages_forumTopics> messages_forumTopics::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_forumTopics> res = make_tl_object<messages_forumTopics>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->order_by_create_date_ = (var0 & 1) != 0;
  if (var0 & 2) { res->top_icons_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  res->count_ = TlFetchInt::parse(p);
  res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_forumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.forumTopics");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (order_by_create_date_ << 0) | ((!top_icons_.empty()) << 1)));
    if (var0 & 1) { s.store_field("order_by_create_date", true); }
    if (var0 & 2) { { s.store_vector_begin("top_icons", top_icons_.size()); for (const auto &_value : top_icons_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_field("count", count_);
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_class_end();
  }
}

messages_votesList::messages_votesList()
  : flags_()
  , count_()
  , votes_()
  , chats_()
  , users_()
  , next_offset_()
{}

const std::int32_t messages_votesList::ID;

object_ptr<messages_votesList> messages_votesList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_votesList> res = make_tl_object<messages_votesList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->votes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessagePeerVote>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_votesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.votesList");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("count", count_);
    { s.store_vector_begin("votes", votes_.size()); for (const auto &_value : votes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

payments_savedStarGifts::payments_savedStarGifts()
  : flags_()
  , count_()
  , chat_notifications_enabled_()
  , gifts_()
  , next_offset_()
  , chats_()
  , users_()
{}

const std::int32_t payments_savedStarGifts::ID;

object_ptr<payments_savedStarGifts> payments_savedStarGifts::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_savedStarGifts> res = make_tl_object<payments_savedStarGifts>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->chat_notifications_enabled_ = TlFetchBool::parse(p); }
  res->gifts_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<savedStarGift>, 1105150972>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_savedStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.savedStarGifts");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | ((!next_offset_.empty()) << 0)));
    s.store_field("count", count_);
    if (var0 & 2) { s.store_field("chat_notifications_enabled", chat_notifications_enabled_); }
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<payments_StarGiftActiveAuctions> payments_StarGiftActiveAuctions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_starGiftActiveAuctionsNotModified::ID:
      return payments_starGiftActiveAuctionsNotModified::fetch(p);
    case payments_starGiftActiveAuctions::ID:
      return payments_starGiftActiveAuctions::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t payments_starGiftActiveAuctionsNotModified::ID;

object_ptr<payments_StarGiftActiveAuctions> payments_starGiftActiveAuctionsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftActiveAuctionsNotModified>();
}

void payments_starGiftActiveAuctionsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftActiveAuctionsNotModified");
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftActiveAuctions::ID;

object_ptr<payments_StarGiftActiveAuctions> payments_starGiftActiveAuctions::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftActiveAuctions>(p);
}

payments_starGiftActiveAuctions::payments_starGiftActiveAuctions(TlBufferParser &p)
  : auctions_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftActiveAuctionState>, -753154979>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
{}

void payments_starGiftActiveAuctions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftActiveAuctions");
    { s.store_vector_begin("auctions", auctions_.size()); for (const auto &_value : auctions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftDepositPayload::ID;

object_ptr<payments_starGiftDepositPayload> payments_starGiftDepositPayload::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftDepositPayload>(p);
}

payments_starGiftDepositPayload::payments_starGiftDepositPayload(TlBufferParser &p)
  : nft_address_(TlFetchString<string>::parse(p))
  , payload_(TlFetchBytes<bytes>::parse(p))
  , amount_(TlFetchLong::parse(p))
{}

void payments_starGiftDepositPayload::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftDepositPayload");
    s.store_field("nft_address", nft_address_);
    s.store_bytes_field("payload", payload_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

object_ptr<payments_StarGifts> payments_StarGifts::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_starGiftsNotModified::ID:
      return payments_starGiftsNotModified::fetch(p);
    case payments_starGifts::ID:
      return payments_starGifts::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t payments_starGiftsNotModified::ID;

object_ptr<payments_StarGifts> payments_starGiftsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftsNotModified>();
}

void payments_starGiftsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftsNotModified");
    s.store_class_end();
  }
}

const std::int32_t payments_starGifts::ID;

object_ptr<payments_StarGifts> payments_starGifts::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGifts>(p);
}

payments_starGifts::payments_starGifts(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , gifts_(TlFetchBoxed<TlFetchVector<TlFetchObject<StarGift>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void payments_starGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGifts");
    s.store_field("hash", hash_);
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stories_canSendStoryCount::ID;

object_ptr<stories_canSendStoryCount> stories_canSendStoryCount::fetch(TlBufferParser &p) {
  return make_tl_object<stories_canSendStoryCount>(p);
}

stories_canSendStoryCount::stories_canSendStoryCount(TlBufferParser &p)
  : count_remains_(TlFetchInt::parse(p))
{}

void stories_canSendStoryCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.canSendStoryCount");
    s.store_field("count_remains", count_remains_);
    s.store_class_end();
  }
}

object_ptr<updates_ChannelDifference> updates_ChannelDifference::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case updates_channelDifferenceEmpty::ID:
      return updates_channelDifferenceEmpty::fetch(p);
    case updates_channelDifferenceTooLong::ID:
      return updates_channelDifferenceTooLong::fetch(p);
    case updates_channelDifference::ID:
      return updates_channelDifference::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

updates_channelDifferenceEmpty::updates_channelDifferenceEmpty()
  : flags_()
  , final_()
  , pts_()
  , timeout_()
{}

const std::int32_t updates_channelDifferenceEmpty::ID;

object_ptr<updates_ChannelDifference> updates_channelDifferenceEmpty::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updates_channelDifferenceEmpty> res = make_tl_object<updates_channelDifferenceEmpty>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->final_ = (var0 & 1) != 0;
  res->pts_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->timeout_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updates_channelDifferenceEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.channelDifferenceEmpty");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (final_ << 0)));
    if (var0 & 1) { s.store_field("final", true); }
    s.store_field("pts", pts_);
    if (var0 & 2) { s.store_field("timeout", timeout_); }
    s.store_class_end();
  }
}

updates_channelDifferenceTooLong::updates_channelDifferenceTooLong()
  : flags_()
  , final_()
  , timeout_()
  , topics_()
  , dialog_()
  , messages_()
  , chats_()
  , users_()
{}

const std::int32_t updates_channelDifferenceTooLong::ID;

object_ptr<updates_ChannelDifference> updates_channelDifferenceTooLong::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updates_channelDifferenceTooLong> res = make_tl_object<updates_channelDifferenceTooLong>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->final_ = (var0 & 1) != 0;
  if (var0 & 2) { res->timeout_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p); }
  res->dialog_ = TlFetchObject<Dialog>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updates_channelDifferenceTooLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.channelDifferenceTooLong");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (final_ << 0) | ((!topics_.empty()) << 2)));
    if (var0 & 1) { s.store_field("final", true); }
    if (var0 & 2) { s.store_field("timeout", timeout_); }
    if (var0 & 4) { { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_object_field("dialog", static_cast<const BaseObject *>(dialog_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updates_channelDifference::updates_channelDifference()
  : flags_()
  , final_()
  , pts_()
  , timeout_()
  , topics_()
  , new_messages_()
  , other_updates_()
  , chats_()
  , users_()
{}

const std::int32_t updates_channelDifference::ID;

object_ptr<updates_ChannelDifference> updates_channelDifference::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updates_channelDifference> res = make_tl_object<updates_channelDifference>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->final_ = (var0 & 1) != 0;
  res->pts_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->timeout_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p); }
  res->new_messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->other_updates_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Update>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updates_channelDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.channelDifference");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (final_ << 0) | ((!topics_.empty()) << 2)));
    if (var0 & 1) { s.store_field("final", true); }
    s.store_field("pts", pts_);
    if (var0 & 2) { s.store_field("timeout", timeout_); }
    if (var0 & 4) { { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("new_messages", new_messages_.size()); for (const auto &_value : new_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("other_updates", other_updates_.size()); for (const auto &_value : other_updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t upload_webFile::ID;

object_ptr<upload_webFile> upload_webFile::fetch(TlBufferParser &p) {
  return make_tl_object<upload_webFile>(p);
}

upload_webFile::upload_webFile(TlBufferParser &p)
  : size_(TlFetchInt::parse(p))
  , mime_type_(TlFetchString<string>::parse(p))
  , file_type_(TlFetchObject<storage_FileType>::parse(p))
  , mtime_(TlFetchInt::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void upload_webFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.webFile");
    s.store_field("size", size_);
    s.store_field("mime_type", mime_type_);
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_field("mtime", mtime_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

object_ptr<users_SavedMusic> users_SavedMusic::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case users_savedMusicNotModified::ID:
      return users_savedMusicNotModified::fetch(p);
    case users_savedMusic::ID:
      return users_savedMusic::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t users_savedMusicNotModified::ID;

object_ptr<users_SavedMusic> users_savedMusicNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<users_savedMusicNotModified>(p);
}

users_savedMusicNotModified::users_savedMusicNotModified(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
{}

void users_savedMusicNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.savedMusicNotModified");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

const std::int32_t users_savedMusic::ID;

object_ptr<users_SavedMusic> users_savedMusic::fetch(TlBufferParser &p) {
  return make_tl_object<users_savedMusic>(p);
}

users_savedMusic::users_savedMusic(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , documents_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void users_savedMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.savedMusic");
    s.store_field("count", count_);
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t wallet_encryptedSecretPhrasePart::ID;

object_ptr<wallet_encryptedSecretPhrasePart> wallet_encryptedSecretPhrasePart::fetch(TlBufferParser &p) {
  return make_tl_object<wallet_encryptedSecretPhrasePart>(p);
}

wallet_encryptedSecretPhrasePart::wallet_encryptedSecretPhrasePart(TlBufferParser &p)
  : data_(TlFetchBytes<bytes>::parse(p))
{}

void wallet_encryptedSecretPhrasePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.encryptedSecretPhrasePart");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

const std::int32_t wallet_secretPhraseParts::ID;

object_ptr<wallet_secretPhraseParts> wallet_secretPhraseParts::fetch(TlBufferParser &p) {
  return make_tl_object<wallet_secretPhraseParts>(p);
}

wallet_secretPhraseParts::wallet_secretPhraseParts(TlBufferParser &p)
  : token_(TlFetchString<string>::parse(p))
  , dcs_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void wallet_secretPhraseParts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.secretPhraseParts");
    s.store_field("token", "[REDACTED]");
    { s.store_vector_begin("dcs", dcs_.size()); for (const auto &_value : dcs_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t account_declinePasswordReset::ID;

void account_declinePasswordReset::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1284770294);
}

void account_declinePasswordReset::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1284770294);
}

void account_declinePasswordReset::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.declinePasswordReset");
    s.store_class_end();
  }
}

account_declinePasswordReset::ReturnType account_declinePasswordReset::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_getAutoDownloadSettings::ID;

void account_getAutoDownloadSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1457130303);
}

void account_getAutoDownloadSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1457130303);
}

void account_getAutoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAutoDownloadSettings");
    s.store_class_end();
  }
}

account_getAutoDownloadSettings::ReturnType account_getAutoDownloadSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_autoDownloadSettings>, 1674235686>::parse(p);
#undef FAIL
}

account_getWebBrowserSettings::account_getWebBrowserSettings(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getWebBrowserSettings::ID;

void account_getWebBrowserSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1449482088);
  TlStoreBinary::store(hash_, s);
}

void account_getWebBrowserSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1449482088);
  TlStoreBinary::store(hash_, s);
}

void account_getWebBrowserSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getWebBrowserSettings");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getWebBrowserSettings::ReturnType account_getWebBrowserSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_WebBrowserSettings>::parse(p);
#undef FAIL
}

account_reportPeer::account_reportPeer(object_ptr<InputPeer> &&peer_, object_ptr<ReportReason> &&reason_, string const &message_)
  : peer_(std::move(peer_))
  , reason_(std::move(reason_))
  , message_(message_)
{}

const std::int32_t account_reportPeer::ID;

void account_reportPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-977650298);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreString::store(message_, s);
}

void account_reportPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-977650298);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreString::store(message_, s);
}

void account_reportPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.reportPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("message", message_);
    s.store_class_end();
  }
}

account_reportPeer::ReturnType account_reportPeer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_saveWallPaper::account_saveWallPaper(object_ptr<InputWallPaper> &&wallpaper_, bool unsave_, object_ptr<wallPaperSettings> &&settings_)
  : wallpaper_(std::move(wallpaper_))
  , unsave_(unsave_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_saveWallPaper::ID;

void account_saveWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1817860919);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
  TlStoreBool::store(unsave_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_saveWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1817860919);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
  TlStoreBool::store(unsave_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_saveWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveWallPaper");
    s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get()));
    s.store_field("unsave", unsave_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_saveWallPaper::ReturnType account_saveWallPaper::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_toggleWebBrowserSettingsException::account_toggleWebBrowserSettingsException(int32 flags_, bool delete_, bool open_external_browser_, string const &url_)
  : flags_(flags_)
  , delete_(delete_)
  , open_external_browser_(open_external_browser_)
  , url_(url_)
{}

const std::int32_t account_toggleWebBrowserSettingsException::ID;

void account_toggleWebBrowserSettingsException::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1626161705);
  TlStoreBinary::store((var0 = flags_ | (delete_ << 1)), s);
  if (var0 & 1) { TlStoreBool::store(open_external_browser_, s); }
  TlStoreString::store(url_, s);
}

void account_toggleWebBrowserSettingsException::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1626161705);
  TlStoreBinary::store((var0 = flags_ | (delete_ << 1)), s);
  if (var0 & 1) { TlStoreBool::store(open_external_browser_, s); }
  TlStoreString::store(url_, s);
}

void account_toggleWebBrowserSettingsException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.toggleWebBrowserSettingsException");
    s.store_field("flags", (var0 = flags_ | (delete_ << 1)));
    if (var0 & 2) { s.store_field("delete", true); }
    if (var0 & 1) { s.store_field("open_external_browser", open_external_browser_); }
    s.store_field("url", url_);
    s.store_class_end();
  }
}

account_toggleWebBrowserSettingsException::ReturnType account_toggleWebBrowserSettingsException::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

account_updateBirthday::account_updateBirthday(int32 flags_, object_ptr<birthday> &&birthday_)
  : flags_(flags_)
  , birthday_(std::move(birthday_))
{}

const std::int32_t account_updateBirthday::ID;

void account_updateBirthday::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-865203183);
  TlStoreBinary::store((var0 = flags_ | ((birthday_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1821253126>::store(birthday_, s); }
}

void account_updateBirthday::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-865203183);
  TlStoreBinary::store((var0 = flags_ | ((birthday_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1821253126>::store(birthday_, s); }
}

void account_updateBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBirthday");
    s.store_field("flags", (var0 = flags_ | ((birthday_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("birthday", static_cast<const BaseObject *>(birthday_.get())); }
    s.store_class_end();
  }
}

account_updateBirthday::ReturnType account_updateBirthday::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateBusinessIntro::account_updateBusinessIntro(int32 flags_, object_ptr<inputBusinessIntro> &&intro_)
  : flags_(flags_)
  , intro_(std::move(intro_))
{}

const std::int32_t account_updateBusinessIntro::ID;

void account_updateBusinessIntro::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1508585420);
  TlStoreBinary::store((var0 = flags_ | ((intro_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 163867085>::store(intro_, s); }
}

void account_updateBusinessIntro::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1508585420);
  TlStoreBinary::store((var0 = flags_ | ((intro_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 163867085>::store(intro_, s); }
}

void account_updateBusinessIntro::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBusinessIntro");
    s.store_field("flags", (var0 = flags_ | ((intro_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("intro", static_cast<const BaseObject *>(intro_.get())); }
    s.store_class_end();
  }
}

account_updateBusinessIntro::ReturnType account_updateBusinessIntro::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateConnectedBot::account_updateConnectedBot(int32 flags_, bool deleted_, object_ptr<businessBotRights> &&rights_, object_ptr<InputUser> &&bot_, object_ptr<inputBusinessBotRecipients> &&recipients_)
  : flags_(flags_)
  , deleted_(deleted_)
  , rights_(std::move(rights_))
  , bot_(std::move(bot_))
  , recipients_(std::move(recipients_))
{}

const std::int32_t account_updateConnectedBot::ID;

void account_updateConnectedBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1721797758);
  TlStoreBinary::store((var0 = flags_ | (deleted_ << 1) | ((rights_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1604170505>::store(rights_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxed<TlStoreObject, -991587810>::store(recipients_, s);
}

void account_updateConnectedBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1721797758);
  TlStoreBinary::store((var0 = flags_ | (deleted_ << 1) | ((rights_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1604170505>::store(rights_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxed<TlStoreObject, -991587810>::store(recipients_, s);
}

void account_updateConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateConnectedBot");
    s.store_field("flags", (var0 = flags_ | (deleted_ << 1) | ((rights_ != nullptr) << 0)));
    if (var0 & 2) { s.store_field("deleted", true); }
    if (var0 & 1) { s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get())); }
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_class_end();
  }
}

account_updateConnectedBot::ReturnType account_updateConnectedBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

account_updateUsername::account_updateUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t account_updateUsername::ID;

void account_updateUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1040964988);
  TlStoreString::store(username_, s);
}

void account_updateUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1040964988);
  TlStoreString::store(username_, s);
}

void account_updateUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

account_updateUsername::ReturnType account_updateUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

account_updateWebBrowserSettings::account_updateWebBrowserSettings(int32 flags_, bool open_external_browser_, bool display_close_button_)
  : flags_(flags_)
  , open_external_browser_(open_external_browser_)
  , display_close_button_(display_close_button_)
{}

const std::int32_t account_updateWebBrowserSettings::ID;

void account_updateWebBrowserSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1696627970);
  TlStoreBinary::store((var0 = flags_ | (open_external_browser_ << 0) | (display_close_button_ << 1)), s);
}

void account_updateWebBrowserSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1696627970);
  TlStoreBinary::store((var0 = flags_ | (open_external_browser_ << 0) | (display_close_button_ << 1)), s);
}

void account_updateWebBrowserSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateWebBrowserSettings");
    s.store_field("flags", (var0 = flags_ | (open_external_browser_ << 0) | (display_close_button_ << 1)));
    if (var0 & 1) { s.store_field("open_external_browser", true); }
    if (var0 & 2) { s.store_field("display_close_button", true); }
    s.store_class_end();
  }
}

account_updateWebBrowserSettings::ReturnType account_updateWebBrowserSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_WebBrowserSettings>::parse(p);
#undef FAIL
}

aicompose_createTone::aicompose_createTone(int32 flags_, bool display_author_, int64 emoji_id_, string const &title_, string const &prompt_)
  : flags_(flags_)
  , display_author_(display_author_)
  , emoji_id_(emoji_id_)
  , title_(title_)
  , prompt_(prompt_)
{}

const std::int32_t aicompose_createTone::ID;

void aicompose_createTone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1252538643);
  TlStoreBinary::store((var0 = flags_ | (display_author_ << 0)), s);
  TlStoreBinary::store(emoji_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(prompt_, s);
}

void aicompose_createTone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1252538643);
  TlStoreBinary::store((var0 = flags_ | (display_author_ << 0)), s);
  TlStoreBinary::store(emoji_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(prompt_, s);
}

void aicompose_createTone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aicompose.createTone");
    s.store_field("flags", (var0 = flags_ | (display_author_ << 0)));
    if (var0 & 1) { s.store_field("display_author", true); }
    s.store_field("emoji_id", emoji_id_);
    s.store_field("title", title_);
    s.store_field("prompt", prompt_);
    s.store_class_end();
  }
}

aicompose_createTone::ReturnType aicompose_createTone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<AiComposeTone>::parse(p);
#undef FAIL
}

aicompose_deleteTone::aicompose_deleteTone(object_ptr<InputAiComposeTone> &&tone_)
  : tone_(std::move(tone_))
{}

const std::int32_t aicompose_deleteTone::ID;

void aicompose_deleteTone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-583454358);
  TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s);
}

void aicompose_deleteTone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-583454358);
  TlStoreBoxedUnknown<TlStoreObject>::store(tone_, s);
}

void aicompose_deleteTone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "aicompose.deleteTone");
    s.store_object_field("tone", static_cast<const BaseObject *>(tone_.get()));
    s.store_class_end();
  }
}

aicompose_deleteTone::ReturnType aicompose_deleteTone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_importBotAuthorization::auth_importBotAuthorization(int32 flags_, int32 api_id_, string const &api_hash_, string const &bot_auth_token_)
  : flags_(flags_)
  , api_id_(api_id_)
  , api_hash_(api_hash_)
  , bot_auth_token_(bot_auth_token_)
{}

const std::int32_t auth_importBotAuthorization::ID;

void auth_importBotAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1738800940);
  TlStoreBinary::store(flags_, s);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreString::store(bot_auth_token_, s);
}

void auth_importBotAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1738800940);
  TlStoreBinary::store(flags_, s);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreString::store(bot_auth_token_, s);
}

void auth_importBotAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.importBotAuthorization");
    s.store_field("flags", flags_);
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", "[REDACTED]");
    s.store_field("bot_auth_token", "[REDACTED]");
    s.store_class_end();
  }
}

auth_importBotAuthorization::ReturnType auth_importBotAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

auth_reportMissingCode::auth_reportMissingCode(string const &phone_number_, string const &phone_code_hash_, string const &mnc_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , mnc_(mnc_)
{}

const std::int32_t auth_reportMissingCode::ID;

void auth_reportMissingCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-878841866);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(mnc_, s);
}

void auth_reportMissingCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-878841866);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(mnc_, s);
}

void auth_reportMissingCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.reportMissingCode");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("mnc", mnc_);
    s.store_class_end();
  }
}

auth_reportMissingCode::ReturnType auth_reportMissingCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t auth_requestPasswordRecovery::ID;

void auth_requestPasswordRecovery::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-661144474);
}

void auth_requestPasswordRecovery::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-661144474);
}

void auth_requestPasswordRecovery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.requestPasswordRecovery");
    s.store_class_end();
  }
}

auth_requestPasswordRecovery::ReturnType auth_requestPasswordRecovery::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<auth_passwordRecovery>, 326715557>::parse(p);
#undef FAIL
}

auth_sendCode::auth_sendCode(string const &phone_number_, int32 api_id_, string const &api_hash_, object_ptr<codeSettings> &&settings_)
  : phone_number_(phone_number_)
  , api_id_(api_id_)
  , api_hash_(api_hash_)
  , settings_(std::move(settings_))
{}

const std::int32_t auth_sendCode::ID;

void auth_sendCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1502141361);
  TlStoreString::store(phone_number_, s);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void auth_sendCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1502141361);
  TlStoreString::store(phone_number_, s);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void auth_sendCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sendCode");
    s.store_field("phone_number", phone_number_);
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", "[REDACTED]");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

auth_sendCode::ReturnType auth_sendCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

bots_addPreviewMedia::bots_addPreviewMedia(object_ptr<InputUser> &&bot_, string const &lang_code_, object_ptr<InputMedia> &&media_)
  : bot_(std::move(bot_))
  , lang_code_(lang_code_)
  , media_(std::move(media_))
{}

const std::int32_t bots_addPreviewMedia::ID;

void bots_addPreviewMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(397326170);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void bots_addPreviewMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(397326170);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void bots_addPreviewMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.addPreviewMedia");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("lang_code", lang_code_);
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

bots_addPreviewMedia::ReturnType bots_addPreviewMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<botPreviewMedia>, 602479523>::parse(p);
#undef FAIL
}

bots_allowSendMessage::bots_allowSendMessage(object_ptr<InputUser> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t bots_allowSendMessage::ID;

void bots_allowSendMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-248323089);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_allowSendMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-248323089);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_allowSendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.allowSendMessage");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

bots_allowSendMessage::ReturnType bots_allowSendMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

bots_editAccessSettings::bots_editAccessSettings(int32 flags_, bool restricted_, object_ptr<InputUser> &&bot_, array<object_ptr<InputUser>> &&add_users_)
  : flags_(flags_)
  , restricted_(restricted_)
  , bot_(std::move(bot_))
  , add_users_(std::move(add_users_))
{}

const std::int32_t bots_editAccessSettings::ID;

void bots_editAccessSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(830553304);
  TlStoreBinary::store((var0 = flags_ | (restricted_ << 0) | ((!add_users_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(add_users_, s); }
}

void bots_editAccessSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(830553304);
  TlStoreBinary::store((var0 = flags_ | (restricted_ << 0) | ((!add_users_.empty()) << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(add_users_, s); }
}

void bots_editAccessSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.editAccessSettings");
    s.store_field("flags", (var0 = flags_ | (restricted_ << 0) | ((!add_users_.empty()) << 1)));
    if (var0 & 1) { s.store_field("restricted", true); }
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    if (var0 & 2) { { s.store_vector_begin("add_users", add_users_.size()); for (const auto &_value : add_users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

bots_editAccessSettings::ReturnType bots_editAccessSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_removeUsername::bots_removeUsername(object_ptr<InputUser> &&bot_, string const &username_)
  : bot_(std::move(bot_))
  , username_(username_)
{}

const std::int32_t bots_removeUsername::ID;

void bots_removeUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-956033923);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(username_, s);
}

void bots_removeUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-956033923);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(username_, s);
}

void bots_removeUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.removeUsername");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("username", username_);
    s.store_class_end();
  }
}

bots_removeUsername::ReturnType bots_removeUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_requestWebViewButton::bots_requestWebViewButton(object_ptr<InputUser> &&user_id_, object_ptr<keyboardButton> &&button_)
  : user_id_(std::move(user_id_))
  , button_(std::move(button_))
{}

const std::int32_t bots_requestWebViewButton::ID;

void bots_requestWebViewButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(832742238);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxed<TlStoreObject, 795322159>::store(button_, s);
}

void bots_requestWebViewButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(832742238);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxed<TlStoreObject, 795322159>::store(button_, s);
}

void bots_requestWebViewButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.requestWebViewButton");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    s.store_class_end();
  }
}

bots_requestWebViewButton::ReturnType bots_requestWebViewButton::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<bots_requestedButton>, -247743273>::parse(p);
#undef FAIL
}

channels_deleteMessages::channels_deleteMessages(object_ptr<InputChannel> &&channel_, array<int32> &&id_)
  : channel_(std::move(channel_))
  , id_(std::move(id_))
{}

const std::int32_t channels_deleteMessages::ID;

void channels_deleteMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2067661490);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_deleteMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2067661490);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_deleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.deleteMessages");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_deleteMessages::ReturnType channels_deleteMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedMessages>, -2066640507>::parse(p);
#undef FAIL
}

channels_exportMessageLink::channels_exportMessageLink(int32 flags_, bool grouped_, bool thread_, object_ptr<InputChannel> &&channel_, int32 id_)
  : flags_(flags_)
  , grouped_(grouped_)
  , thread_(thread_)
  , channel_(std::move(channel_))
  , id_(id_)
{}

const std::int32_t channels_exportMessageLink::ID;

void channels_exportMessageLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-432034325);
  TlStoreBinary::store((var0 = flags_ | (grouped_ << 0) | (thread_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(id_, s);
}

void channels_exportMessageLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-432034325);
  TlStoreBinary::store((var0 = flags_ | (grouped_ << 0) | (thread_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(id_, s);
}

void channels_exportMessageLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.exportMessageLink");
    s.store_field("flags", (var0 = flags_ | (grouped_ << 0) | (thread_ << 1)));
    if (var0 & 1) { s.store_field("grouped", true); }
    if (var0 & 2) { s.store_field("thread", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

channels_exportMessageLink::ReturnType channels_exportMessageLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<exportedMessageLink>, 1571494644>::parse(p);
#undef FAIL
}

channels_joinChannel::channels_joinChannel(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_joinChannel::ID;

void channels_joinChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2137660962);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_joinChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2137660962);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_joinChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.joinChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_joinChannel::ReturnType channels_joinChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_ChatInviteJoinResult>::parse(p);
#undef FAIL
}

channels_togglePreHistoryHidden::channels_togglePreHistoryHidden(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_togglePreHistoryHidden::ID;

void channels_togglePreHistoryHidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-356796084);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_togglePreHistoryHidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-356796084);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_togglePreHistoryHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.togglePreHistoryHidden");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_togglePreHistoryHidden::ReturnType channels_togglePreHistoryHidden::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_toggleSignatures::channels_toggleSignatures(int32 flags_, bool signatures_enabled_, bool profiles_enabled_, object_ptr<InputChannel> &&channel_)
  : flags_(flags_)
  , signatures_enabled_(signatures_enabled_)
  , profiles_enabled_(profiles_enabled_)
  , channel_(std::move(channel_))
{}

const std::int32_t channels_toggleSignatures::ID;

void channels_toggleSignatures::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1099781276);
  TlStoreBinary::store((var0 = flags_ | (signatures_enabled_ << 0) | (profiles_enabled_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_toggleSignatures::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1099781276);
  TlStoreBinary::store((var0 = flags_ | (signatures_enabled_ << 0) | (profiles_enabled_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_toggleSignatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleSignatures");
    s.store_field("flags", (var0 = flags_ | (signatures_enabled_ << 0) | (profiles_enabled_ << 1)));
    if (var0 & 1) { s.store_field("signatures_enabled", true); }
    if (var0 & 2) { s.store_field("profiles_enabled", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_toggleSignatures::ReturnType channels_toggleSignatures::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_toggleViewForumAsMessages::channels_toggleViewForumAsMessages(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_toggleViewForumAsMessages::ID;

void channels_toggleViewForumAsMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1757889771);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleViewForumAsMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1757889771);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleViewForumAsMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleViewForumAsMessages");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_toggleViewForumAsMessages::ReturnType channels_toggleViewForumAsMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_updateEmojiStatus::channels_updateEmojiStatus(object_ptr<InputChannel> &&channel_, object_ptr<EmojiStatus> &&emoji_status_)
  : channel_(std::move(channel_))
  , emoji_status_(std::move(emoji_status_))
{}

const std::int32_t channels_updateEmojiStatus::ID;

void channels_updateEmojiStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-254548312);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void channels_updateEmojiStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-254548312);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void channels_updateEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.updateEmojiStatus");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

channels_updateEmojiStatus::ReturnType channels_updateEmojiStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

communities_getParticipantJoinedChats::communities_getParticipantJoinedChats(object_ptr<InputChannel> &&community_, object_ptr<InputPeer> &&participant_)
  : community_(std::move(community_))
  , participant_(std::move(participant_))
{}

const std::int32_t communities_getParticipantJoinedChats::ID;

void communities_getParticipantJoinedChats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-125916245);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void communities_getParticipantJoinedChats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-125916245);
  TlStoreBoxedUnknown<TlStoreObject>::store(community_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void communities_getParticipantJoinedChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "communities.getParticipantJoinedChats");
    s.store_object_field("community", static_cast<const BaseObject *>(community_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

communities_getParticipantJoinedChats::ReturnType communities_getParticipantJoinedChats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<communities_participantJoinedChats>, -1921494742>::parse(p);
#undef FAIL
}

contacts_acceptContact::contacts_acceptContact(object_ptr<InputUser> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t contacts_acceptContact::ID;

void contacts_acceptContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-130964977);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_acceptContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-130964977);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_acceptContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.acceptContact");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

contacts_acceptContact::ReturnType contacts_acceptContact::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t contacts_exportContactToken::ID;

void contacts_exportContactToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-127582169);
}

void contacts_exportContactToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-127582169);
}

void contacts_exportContactToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.exportContactToken");
    s.store_class_end();
  }
}

contacts_exportContactToken::ReturnType contacts_exportContactToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<exportedContactToken>, 1103040667>::parse(p);
#undef FAIL
}

contacts_getContactIDs::contacts_getContactIDs(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t contacts_getContactIDs::ID;

void contacts_getContactIDs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2061264541);
  TlStoreBinary::store(hash_, s);
}

void contacts_getContactIDs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2061264541);
  TlStoreBinary::store(hash_, s);
}

void contacts_getContactIDs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getContactIDs");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

contacts_getContactIDs::ReturnType contacts_getContactIDs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
#undef FAIL
}

contacts_resolvePhone::contacts_resolvePhone(string const &phone_)
  : phone_(phone_)
{}

const std::int32_t contacts_resolvePhone::ID;

void contacts_resolvePhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1963375804);
  TlStoreString::store(phone_, s);
}

void contacts_resolvePhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1963375804);
  TlStoreString::store(phone_, s);
}

void contacts_resolvePhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.resolvePhone");
    s.store_field("phone", phone_);
    s.store_class_end();
  }
}

contacts_resolvePhone::ReturnType contacts_resolvePhone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<contacts_resolvedPeer>, 2131196633>::parse(p);
#undef FAIL
}

contacts_resolveUsername::contacts_resolveUsername(int32 flags_, string const &username_, string const &referer_)
  : flags_(flags_)
  , username_(username_)
  , referer_(referer_)
{}

const std::int32_t contacts_resolveUsername::ID;

void contacts_resolveUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1918565308);
  TlStoreBinary::store((var0 = flags_ | ((!referer_.empty()) << 0)), s);
  TlStoreString::store(username_, s);
  if (var0 & 1) { TlStoreString::store(referer_, s); }
}

void contacts_resolveUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1918565308);
  TlStoreBinary::store((var0 = flags_ | ((!referer_.empty()) << 0)), s);
  TlStoreString::store(username_, s);
  if (var0 & 1) { TlStoreString::store(referer_, s); }
}

void contacts_resolveUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.resolveUsername");
    s.store_field("flags", (var0 = flags_ | ((!referer_.empty()) << 0)));
    s.store_field("username", username_);
    if (var0 & 1) { s.store_field("referer", referer_); }
    s.store_class_end();
  }
}

contacts_resolveUsername::ReturnType contacts_resolveUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<contacts_resolvedPeer>, 2131196633>::parse(p);
#undef FAIL
}

contacts_unblock::contacts_unblock(int32 flags_, bool my_stories_from_, object_ptr<InputPeer> &&id_)
  : flags_(flags_)
  , my_stories_from_(my_stories_from_)
  , id_(std::move(id_))
{}

const std::int32_t contacts_unblock::ID;

void contacts_unblock::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1252994264);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_unblock::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1252994264);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_unblock::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.unblock");
    s.store_field("flags", (var0 = flags_ | (my_stories_from_ << 0)));
    if (var0 & 1) { s.store_field("my_stories_from", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

contacts_unblock::ReturnType contacts_unblock::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

contacts_updateContactNote::contacts_updateContactNote(object_ptr<InputUser> &&id_, object_ptr<textWithEntities> &&note_)
  : id_(std::move(id_))
  , note_(std::move(note_))
{}

const std::int32_t contacts_updateContactNote::ID;

void contacts_updateContactNote::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(329212923);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s);
}

void contacts_updateContactNote::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(329212923);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s);
}

void contacts_updateContactNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.updateContactNote");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_object_field("note", static_cast<const BaseObject *>(note_.get()));
    s.store_class_end();
  }
}

contacts_updateContactNote::ReturnType contacts_updateContactNote::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

ephemeral_deleteWelcomeMessage::ephemeral_deleteWelcomeMessage(object_ptr<InputPeer> &&peer_, int32 id_)
  : peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t ephemeral_deleteWelcomeMessage::ID;

void ephemeral_deleteWelcomeMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-394090015);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void ephemeral_deleteWelcomeMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-394090015);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void ephemeral_deleteWelcomeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ephemeral.deleteWelcomeMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

ephemeral_deleteWelcomeMessage::ReturnType ephemeral_deleteWelcomeMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

help_editUserInfo::help_editUserInfo(object_ptr<InputUser> &&user_id_, string const &message_, array<object_ptr<MessageEntity>> &&entities_)
  : user_id_(std::move(user_id_))
  , message_(message_)
  , entities_(std::move(entities_))
{}

const std::int32_t help_editUserInfo::ID;

void help_editUserInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1723407216);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(message_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s);
}

void help_editUserInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1723407216);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(message_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s);
}

void help_editUserInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.editUserInfo");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("message", message_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

help_editUserInfo::ReturnType help_editUserInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_UserInfo>::parse(p);
#undef FAIL
}

help_getCountriesList::help_getCountriesList(string const &lang_code_, int32 hash_)
  : lang_code_(lang_code_)
  , hash_(hash_)
{}

const std::int32_t help_getCountriesList::ID;

void help_getCountriesList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1935116200);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(hash_, s);
}

void help_getCountriesList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1935116200);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(hash_, s);
}

void help_getCountriesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getCountriesList");
    s.store_field("lang_code", lang_code_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getCountriesList::ReturnType help_getCountriesList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_CountriesList>::parse(p);
#undef FAIL
}

help_getTimezonesList::help_getTimezonesList(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t help_getTimezonesList::ID;

void help_getTimezonesList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1236468288);
  TlStoreBinary::store(hash_, s);
}

void help_getTimezonesList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1236468288);
  TlStoreBinary::store(hash_, s);
}

void help_getTimezonesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getTimezonesList");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getTimezonesList::ReturnType help_getTimezonesList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_TimezonesList>::parse(p);
#undef FAIL
}

langpack_getDifference::langpack_getDifference(string const &lang_pack_, string const &lang_code_, int32 from_version_)
  : lang_pack_(lang_pack_)
  , lang_code_(lang_code_)
  , from_version_(from_version_)
{}

const std::int32_t langpack_getDifference::ID;

void langpack_getDifference::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-845657435);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(from_version_, s);
}

void langpack_getDifference::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-845657435);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(from_version_, s);
}

void langpack_getDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langpack.getDifference");
    s.store_field("lang_pack", lang_pack_);
    s.store_field("lang_code", lang_code_);
    s.store_field("from_version", from_version_);
    s.store_class_end();
  }
}

langpack_getDifference::ReturnType langpack_getDifference::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<langPackDifference>, -209337866>::parse(p);
#undef FAIL
}

messages_appendTodoList::messages_appendTodoList(object_ptr<InputPeer> &&peer_, int32 msg_id_, array<object_ptr<todoItem>> &&list_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , list_(std::move(list_))
{}

const std::int32_t messages_appendTodoList::ID;

void messages_appendTodoList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(564531287);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -878074577>>, 481674261>::store(list_, s);
}

void messages_appendTodoList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(564531287);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -878074577>>, 481674261>::store(list_, s);
}

void messages_appendTodoList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.appendTodoList");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    { s.store_vector_begin("list", list_.size()); for (const auto &_value : list_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_appendTodoList::ReturnType messages_appendTodoList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_checkChatInvite::messages_checkChatInvite(string const &hash_)
  : hash_(hash_)
{}

const std::int32_t messages_checkChatInvite::ID;

void messages_checkChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1051570619);
  TlStoreString::store(hash_, s);
}

void messages_checkChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1051570619);
  TlStoreString::store(hash_, s);
}

void messages_checkChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkChatInvite");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_checkChatInvite::ReturnType messages_checkChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<ChatInvite>::parse(p);
#undef FAIL
}

messages_checkUrlAuthMatchCode::messages_checkUrlAuthMatchCode(string const &url_, string const &match_code_)
  : url_(url_)
  , match_code_(match_code_)
{}

const std::int32_t messages_checkUrlAuthMatchCode::ID;

void messages_checkUrlAuthMatchCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-911967477);
  TlStoreString::store(url_, s);
  TlStoreString::store(match_code_, s);
}

void messages_checkUrlAuthMatchCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-911967477);
  TlStoreString::store(url_, s);
  TlStoreString::store(match_code_, s);
}

void messages_checkUrlAuthMatchCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkUrlAuthMatchCode");
    s.store_field("url", url_);
    s.store_field("match_code", match_code_);
    s.store_class_end();
  }
}

messages_checkUrlAuthMatchCode::ReturnType messages_checkUrlAuthMatchCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deleteFactCheck::messages_deleteFactCheck(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_deleteFactCheck::ID;

void messages_deleteFactCheck::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-774204404);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_deleteFactCheck::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-774204404);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_deleteFactCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteFactCheck");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

messages_deleteFactCheck::ReturnType messages_deleteFactCheck::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editChatAdmin::messages_editChatAdmin(int64 chat_id_, object_ptr<InputUser> &&user_id_, bool is_admin_)
  : chat_id_(chat_id_)
  , user_id_(std::move(user_id_))
  , is_admin_(is_admin_)
{}

const std::int32_t messages_editChatAdmin::ID;

void messages_editChatAdmin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1470377534);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBool::store(is_admin_, s);
}

void messages_editChatAdmin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1470377534);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBool::store(is_admin_, s);
}

void messages_editChatAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatAdmin");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("is_admin", is_admin_);
    s.store_class_end();
  }
}

messages_editChatAdmin::ReturnType messages_editChatAdmin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_exportChatInvite::messages_exportChatInvite(int32 flags_, bool legacy_revoke_permanent_, bool request_needed_, object_ptr<InputPeer> &&peer_, int32 expire_date_, int32 usage_limit_, string const &title_, object_ptr<starsSubscriptionPricing> &&subscription_pricing_)
  : flags_(flags_)
  , legacy_revoke_permanent_(legacy_revoke_permanent_)
  , request_needed_(request_needed_)
  , peer_(std::move(peer_))
  , expire_date_(expire_date_)
  , usage_limit_(usage_limit_)
  , title_(title_)
  , subscription_pricing_(std::move(subscription_pricing_))
{}

const std::int32_t messages_exportChatInvite::ID;

void messages_exportChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1537876336);
  TlStoreBinary::store((var0 = flags_ | (legacy_revoke_permanent_ << 2) | (request_needed_ << 3) | ((!title_.empty()) << 4) | ((subscription_pricing_ != nullptr) << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(expire_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(usage_limit_, s); }
  if (var0 & 16) { TlStoreString::store(title_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreObject, 88173912>::store(subscription_pricing_, s); }
}

void messages_exportChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1537876336);
  TlStoreBinary::store((var0 = flags_ | (legacy_revoke_permanent_ << 2) | (request_needed_ << 3) | ((!title_.empty()) << 4) | ((subscription_pricing_ != nullptr) << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(expire_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(usage_limit_, s); }
  if (var0 & 16) { TlStoreString::store(title_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreObject, 88173912>::store(subscription_pricing_, s); }
}

void messages_exportChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.exportChatInvite");
    s.store_field("flags", (var0 = flags_ | (legacy_revoke_permanent_ << 2) | (request_needed_ << 3) | ((!title_.empty()) << 4) | ((subscription_pricing_ != nullptr) << 5)));
    if (var0 & 4) { s.store_field("legacy_revoke_permanent", true); }
    if (var0 & 8) { s.store_field("request_needed", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("expire_date", expire_date_); }
    if (var0 & 2) { s.store_field("usage_limit", usage_limit_); }
    if (var0 & 16) { s.store_field("title", title_); }
    if (var0 & 32) { s.store_object_field("subscription_pricing", static_cast<const BaseObject *>(subscription_pricing_.get())); }
    s.store_class_end();
  }
}

messages_exportChatInvite::ReturnType messages_exportChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<ExportedChatInvite>::parse(p);
#undef FAIL
}

messages_getAttachMenuBots::messages_getAttachMenuBots(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getAttachMenuBots::ID;

void messages_getAttachMenuBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(385663691);
  TlStoreBinary::store(hash_, s);
}

void messages_getAttachMenuBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(385663691);
  TlStoreBinary::store(hash_, s);
}

void messages_getAttachMenuBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAttachMenuBots");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getAttachMenuBots::ReturnType messages_getAttachMenuBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<AttachMenuBots>::parse(p);
#undef FAIL
}

messages_getDefaultTagReactions::messages_getDefaultTagReactions(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getDefaultTagReactions::ID;

void messages_getDefaultTagReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1107741656);
  TlStoreBinary::store(hash_, s);
}

void messages_getDefaultTagReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1107741656);
  TlStoreBinary::store(hash_, s);
}

void messages_getDefaultTagReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDefaultTagReactions");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getDefaultTagReactions::ReturnType messages_getDefaultTagReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Reactions>::parse(p);
#undef FAIL
}

messages_getDialogUnreadMarks::messages_getDialogUnreadMarks(int32 flags_, object_ptr<InputPeer> &&parent_peer_)
  : flags_(flags_)
  , parent_peer_(std::move(parent_peer_))
{}

const std::int32_t messages_getDialogUnreadMarks::ID;

void messages_getDialogUnreadMarks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(555754018);
  TlStoreBinary::store((var0 = flags_ | ((parent_peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
}

void messages_getDialogUnreadMarks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(555754018);
  TlStoreBinary::store((var0 = flags_ | ((parent_peer_ != nullptr) << 0)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
}

void messages_getDialogUnreadMarks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDialogUnreadMarks");
    s.store_field("flags", (var0 = flags_ | ((parent_peer_ != nullptr) << 0)));
    if (var0 & 1) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_class_end();
  }
}

messages_getDialogUnreadMarks::ReturnType messages_getDialogUnreadMarks::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<DialogPeer>>, 481674261>::parse(p);
#undef FAIL
}

const std::int32_t messages_getEmojiGameInfo::ID;

void messages_getEmojiGameInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-75592537);
}

void messages_getEmojiGameInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-75592537);
}

void messages_getEmojiGameInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiGameInfo");
    s.store_class_end();
  }
}

messages_getEmojiGameInfo::ReturnType messages_getEmojiGameInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_EmojiGameInfo>::parse(p);
#undef FAIL
}

messages_getMaskStickers::messages_getMaskStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getMaskStickers::ID;

void messages_getMaskStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1678738104);
  TlStoreBinary::store(hash_, s);
}

void messages_getMaskStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1678738104);
  TlStoreBinary::store(hash_, s);
}

void messages_getMaskStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMaskStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getMaskStickers::ReturnType messages_getMaskStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_AllStickers>::parse(p);
#undef FAIL
}

messages_getMessageReadParticipants::messages_getMessageReadParticipants(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_getMessageReadParticipants::ID;

void messages_getMessageReadParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(834782287);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getMessageReadParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(834782287);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getMessageReadParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessageReadParticipants");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

messages_getMessageReadParticipants::ReturnType messages_getMessageReadParticipants::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<readParticipantDate>, 1246753138>>, 481674261>::parse(p);
#undef FAIL
}

messages_getPeerSettings::messages_getPeerSettings(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_getPeerSettings::ID;

void messages_getPeerSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-270948702);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getPeerSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-270948702);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getPeerSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPeerSettings");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_getPeerSettings::ReturnType messages_getPeerSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_peerSettings>, 1753266509>::parse(p);
#undef FAIL
}

messages_getPersonalChannelHistory::messages_getPersonalChannelHistory(object_ptr<InputUser> &&user_id_, int32 limit_, int32 max_id_, int32 min_id_, int64 hash_)
  : user_id_(std::move(user_id_))
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
  , hash_(hash_)
{}

const std::int32_t messages_getPersonalChannelHistory::ID;

void messages_getPersonalChannelHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1442515350);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getPersonalChannelHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1442515350);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getPersonalChannelHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPersonalChannelHistory");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("limit", limit_);
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getPersonalChannelHistory::ReturnType messages_getPersonalChannelHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getPreparedInlineMessage::messages_getPreparedInlineMessage(object_ptr<InputUser> &&bot_, string const &id_)
  : bot_(std::move(bot_))
  , id_(id_)
{}

const std::int32_t messages_getPreparedInlineMessage::ID;

void messages_getPreparedInlineMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2055291464);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(id_, s);
}

void messages_getPreparedInlineMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2055291464);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(id_, s);
}

void messages_getPreparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPreparedInlineMessage");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

messages_getPreparedInlineMessage::ReturnType messages_getPreparedInlineMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_preparedInlineMessage>, -11046771>::parse(p);
#undef FAIL
}

messages_getRecentReactions::messages_getRecentReactions(int32 limit_, int64 hash_)
  : limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getRecentReactions::ID;

void messages_getRecentReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(960896434);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(960896434);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getRecentReactions");
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getRecentReactions::ReturnType messages_getRecentReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Reactions>::parse(p);
#undef FAIL
}

messages_hidePeerSettingsBar::messages_hidePeerSettingsBar(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_hidePeerSettingsBar::ID;

void messages_hidePeerSettingsBar::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1336717624);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_hidePeerSettingsBar::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1336717624);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_hidePeerSettingsBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.hidePeerSettingsBar");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_hidePeerSettingsBar::ReturnType messages_hidePeerSettingsBar::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_readDiscussion::messages_readDiscussion(object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 read_max_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , read_max_id_(read_max_id_)
{}

const std::int32_t messages_readDiscussion::ID;

void messages_readDiscussion::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-147740172);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(read_max_id_, s);
}

void messages_readDiscussion::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-147740172);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(read_max_id_, s);
}

void messages_readDiscussion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readDiscussion");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("read_max_id", read_max_id_);
    s.store_class_end();
  }
}

messages_readDiscussion::ReturnType messages_readDiscussion::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_report::messages_report(object_ptr<InputPeer> &&peer_, array<int32> &&id_, bytes &&option_, string const &message_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
  , option_(std::move(option_))
  , message_(message_)
{}

const std::int32_t messages_report::ID;

void messages_report::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-59199589);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreString::store(option_, s);
  TlStoreString::store(message_, s);
}

void messages_report::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-59199589);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreString::store(option_, s);
  TlStoreString::store(message_, s);
}

void messages_report::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.report");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_bytes_field("option", option_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

messages_report::ReturnType messages_report::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<ReportResult>::parse(p);
#undef FAIL
}

messages_searchStickers::messages_searchStickers(int32 flags_, bool emojis_, string const &q_, string const &emoticon_, array<string> &&lang_code_, int32 offset_, int32 limit_, int64 hash_)
  : flags_(flags_)
  , emojis_(emojis_)
  , q_(q_)
  , emoticon_(emoticon_)
  , lang_code_(std::move(lang_code_))
  , offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_searchStickers::ID;

void messages_searchStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(699516522);
  TlStoreBinary::store((var0 = flags_ | (emojis_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreString::store(emoticon_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(lang_code_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(699516522);
  TlStoreBinary::store((var0 = flags_ | (emojis_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreString::store(emoticon_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(lang_code_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchStickers");
    s.store_field("flags", (var0 = flags_ | (emojis_ << 0)));
    if (var0 & 1) { s.store_field("emojis", true); }
    s.store_field("q", q_);
    s.store_field("emoticon", emoticon_);
    { s.store_vector_begin("lang_code", lang_code_.size()); for (const auto &_value : lang_code_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_searchStickers::ReturnType messages_searchStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FoundStickers>::parse(p);
#undef FAIL
}

messages_sendMessage::messages_sendMessage(int32 flags_, bool no_webpage_, bool silent_, bool background_, bool clear_draft_, bool noforwards_, bool update_stickersets_order_, bool invert_media_, bool allow_paid_floodskip_, object_ptr<InputPeer> &&peer_, object_ptr<InputReplyTo> &&reply_to_, string const &message_, int64 random_id_, object_ptr<ReplyMarkup> &&reply_markup_, array<object_ptr<MessageEntity>> &&entities_, int32 schedule_date_, int32 schedule_repeat_period_, object_ptr<InputPeer> &&send_as_, object_ptr<InputQuickReplyShortcut> &&quick_reply_shortcut_, int64 effect_, int64 allow_paid_stars_, object_ptr<suggestedPost> &&suggested_post_, object_ptr<InputRichMessage> &&rich_message_)
  : flags_(flags_)
  , no_webpage_(no_webpage_)
  , silent_(silent_)
  , background_(background_)
  , clear_draft_(clear_draft_)
  , noforwards_(noforwards_)
  , update_stickersets_order_(update_stickersets_order_)
  , invert_media_(invert_media_)
  , allow_paid_floodskip_(allow_paid_floodskip_)
  , peer_(std::move(peer_))
  , reply_to_(std::move(reply_to_))
  , message_(message_)
  , random_id_(random_id_)
  , reply_markup_(std::move(reply_markup_))
  , entities_(std::move(entities_))
  , schedule_date_(schedule_date_)
  , schedule_repeat_period_(schedule_repeat_period_)
  , send_as_(std::move(send_as_))
  , quick_reply_shortcut_(std::move(quick_reply_shortcut_))
  , effect_(effect_)
  , allow_paid_stars_(allow_paid_stars_)
  , suggested_post_(std::move(suggested_post_))
  , rich_message_(std::move(rich_message_))
{}

const std::int32_t messages_sendMessage::ID;

void messages_sendMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-17526942);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19) | ((reply_to_ != nullptr) << 0) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17) | ((suggested_post_ != nullptr) << 22) | ((rich_message_ != nullptr) << 23)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreString::store(message_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 4194304) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
  if (var0 & 8388608) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
}

void messages_sendMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-17526942);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19) | ((reply_to_ != nullptr) << 0) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17) | ((suggested_post_ != nullptr) << 22) | ((rich_message_ != nullptr) << 23)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreString::store(message_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 4194304) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
  if (var0 & 8388608) { TlStoreBoxedUnknown<TlStoreObject>::store(rich_message_, s); }
}

void messages_sendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendMessage");
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 1) | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19) | ((reply_to_ != nullptr) << 0) | ((reply_markup_ != nullptr) << 2) | ((!entities_.empty()) << 3) | ((send_as_ != nullptr) << 13) | ((quick_reply_shortcut_ != nullptr) << 17) | ((suggested_post_ != nullptr) << 22) | ((rich_message_ != nullptr) << 23)));
    if (var0 & 2) { s.store_field("no_webpage", true); }
    if (var0 & 32) { s.store_field("silent", true); }
    if (var0 & 64) { s.store_field("background", true); }
    if (var0 & 128) { s.store_field("clear_draft", true); }
    if (var0 & 16384) { s.store_field("noforwards", true); }
    if (var0 & 32768) { s.store_field("update_stickersets_order", true); }
    if (var0 & 65536) { s.store_field("invert_media", true); }
    if (var0 & 524288) { s.store_field("allow_paid_floodskip", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_field("message", message_);
    s.store_field("random_id", random_id_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1024) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 16777216) { s.store_field("schedule_repeat_period", schedule_repeat_period_); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    if (var0 & 131072) { s.store_object_field("quick_reply_shortcut", static_cast<const BaseObject *>(quick_reply_shortcut_.get())); }
    if (var0 & 262144) { s.store_field("effect", effect_); }
    if (var0 & 2097152) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    if (var0 & 4194304) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    if (var0 & 8388608) { s.store_object_field("rich_message", static_cast<const BaseObject *>(rich_message_.get())); }
    s.store_class_end();
  }
}

messages_sendMessage::ReturnType messages_sendMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_sendScheduledMessages::messages_sendScheduledMessages(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_sendScheduledMessages::ID;

void messages_sendScheduledMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1120369398);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_sendScheduledMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1120369398);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_sendScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendScheduledMessages");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_sendScheduledMessages::ReturnType messages_sendScheduledMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setBotCallbackAnswer::messages_setBotCallbackAnswer(int32 flags_, bool alert_, int64 query_id_, string const &message_, string const &url_, int32 cache_time_)
  : flags_(flags_)
  , alert_(alert_)
  , query_id_(query_id_)
  , message_(message_)
  , url_(url_)
  , cache_time_(cache_time_)
{}

const std::int32_t messages_setBotCallbackAnswer::ID;

void messages_setBotCallbackAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-712043766);
  TlStoreBinary::store((var0 = flags_ | (alert_ << 1) | ((!message_.empty()) << 0) | ((!url_.empty()) << 2)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(message_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  TlStoreBinary::store(cache_time_, s);
}

void messages_setBotCallbackAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-712043766);
  TlStoreBinary::store((var0 = flags_ | (alert_ << 1) | ((!message_.empty()) << 0) | ((!url_.empty()) << 2)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(message_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  TlStoreBinary::store(cache_time_, s);
}

void messages_setBotCallbackAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setBotCallbackAnswer");
    s.store_field("flags", (var0 = flags_ | (alert_ << 1) | ((!message_.empty()) << 0) | ((!url_.empty()) << 2)));
    if (var0 & 2) { s.store_field("alert", true); }
    s.store_field("query_id", query_id_);
    if (var0 & 1) { s.store_field("message", message_); }
    if (var0 & 4) { s.store_field("url", url_); }
    s.store_field("cache_time", cache_time_);
    s.store_class_end();
  }
}

messages_setBotCallbackAnswer::ReturnType messages_setBotCallbackAnswer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_toggleBotInAttachMenu::messages_toggleBotInAttachMenu(int32 flags_, bool write_allowed_, object_ptr<InputUser> &&bot_, bool enabled_)
  : flags_(flags_)
  , write_allowed_(write_allowed_)
  , bot_(std::move(bot_))
  , enabled_(enabled_)
{}

const std::int32_t messages_toggleBotInAttachMenu::ID;

void messages_toggleBotInAttachMenu::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1777704297);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(enabled_, s);
}

void messages_toggleBotInAttachMenu::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1777704297);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(enabled_, s);
}

void messages_toggleBotInAttachMenu::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleBotInAttachMenu");
    s.store_field("flags", (var0 = flags_ | (write_allowed_ << 0)));
    if (var0 & 1) { s.store_field("write_allowed", true); }
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

messages_toggleBotInAttachMenu::ReturnType messages_toggleBotInAttachMenu::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_toggleDialogFilterTags::messages_toggleDialogFilterTags(bool enabled_)
  : enabled_(enabled_)
{}

const std::int32_t messages_toggleDialogFilterTags::ID;

void messages_toggleDialogFilterTags::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-47326647);
  TlStoreBool::store(enabled_, s);
}

void messages_toggleDialogFilterTags::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-47326647);
  TlStoreBool::store(enabled_, s);
}

void messages_toggleDialogFilterTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleDialogFilterTags");
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

messages_toggleDialogFilterTags::ReturnType messages_toggleDialogFilterTags::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_togglePaidReactionPrivacy::messages_togglePaidReactionPrivacy(object_ptr<InputPeer> &&peer_, int32 msg_id_, object_ptr<PaidReactionPrivacy> &&private_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , private_(std::move(private_))
{}

const std::int32_t messages_togglePaidReactionPrivacy::ID;

void messages_togglePaidReactionPrivacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1129874869);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(private_, s);
}

void messages_togglePaidReactionPrivacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1129874869);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(private_, s);
}

void messages_togglePaidReactionPrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.togglePaidReactionPrivacy");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_object_field("private", static_cast<const BaseObject *>(private_.get()));
    s.store_class_end();
  }
}

messages_togglePaidReactionPrivacy::ReturnType messages_togglePaidReactionPrivacy::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_updateSavedReactionTag::messages_updateSavedReactionTag(int32 flags_, object_ptr<Reaction> &&reaction_, string const &title_)
  : flags_(flags_)
  , reaction_(std::move(reaction_))
  , title_(title_)
{}

const std::int32_t messages_updateSavedReactionTag::ID;

void messages_updateSavedReactionTag::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1613331948);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
}

void messages_updateSavedReactionTag::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1613331948);
  TlStoreBinary::store((var0 = flags_ | ((!title_.empty()) << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
}

void messages_updateSavedReactionTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.updateSavedReactionTag");
    s.store_field("flags", (var0 = flags_ | ((!title_.empty()) << 0)));
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    if (var0 & 1) { s.store_field("title", title_); }
    s.store_class_end();
  }
}

messages_updateSavedReactionTag::ReturnType messages_updateSavedReactionTag::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_assignAppStoreTransaction::payments_assignAppStoreTransaction(bytes &&receipt_, object_ptr<InputStorePaymentPurpose> &&purpose_)
  : receipt_(std::move(receipt_))
  , purpose_(std::move(purpose_))
{}

const std::int32_t payments_assignAppStoreTransaction::ID;

void payments_assignAppStoreTransaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2131921795);
  TlStoreString::store(receipt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_assignAppStoreTransaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2131921795);
  TlStoreString::store(receipt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_assignAppStoreTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.assignAppStoreTransaction");
    s.store_bytes_field("receipt", receipt_);
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

payments_assignAppStoreTransaction::ReturnType payments_assignAppStoreTransaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_checkCanSendGift::payments_checkCanSendGift(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t payments_checkCanSendGift::ID;

void payments_checkCanSendGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1060835895);
  TlStoreBinary::store(gift_id_, s);
}

void payments_checkCanSendGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1060835895);
  TlStoreBinary::store(gift_id_, s);
}

void payments_checkCanSendGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.checkCanSendGift");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

payments_checkCanSendGift::ReturnType payments_checkCanSendGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_CheckCanSendGiftResult>::parse(p);
#undef FAIL
}

payments_createOnrampSession::payments_createOnrampSession(int32 flags_, string const &provider_, string const &crypto_currency_, string const &address_, string const &payment_method_, string const &base_currency_, string const &base_amount_, string const &memo_, string const &theme_, string const &success_return_url_, string const &fail_return_url_, string const &crypto_amount_)
  : flags_(flags_)
  , provider_(provider_)
  , crypto_currency_(crypto_currency_)
  , address_(address_)
  , payment_method_(payment_method_)
  , base_currency_(base_currency_)
  , base_amount_(base_amount_)
  , memo_(memo_)
  , theme_(theme_)
  , success_return_url_(success_return_url_)
  , fail_return_url_(fail_return_url_)
  , crypto_amount_(crypto_amount_)
{}

const std::int32_t payments_createOnrampSession::ID;

void payments_createOnrampSession::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1575387914);
  TlStoreBinary::store((var0 = flags_ | ((!payment_method_.empty()) << 0) | ((!base_currency_.empty()) << 1) | ((!base_amount_.empty()) << 2) | ((!memo_.empty()) << 3) | ((!theme_.empty()) << 4) | ((!success_return_url_.empty()) << 5) | ((!fail_return_url_.empty()) << 6) | ((!crypto_amount_.empty()) << 7)), s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(crypto_currency_, s);
  TlStoreString::store(address_, s);
  if (var0 & 1) { TlStoreString::store(payment_method_, s); }
  if (var0 & 2) { TlStoreString::store(base_currency_, s); }
  if (var0 & 4) { TlStoreString::store(base_amount_, s); }
  if (var0 & 8) { TlStoreString::store(memo_, s); }
  if (var0 & 16) { TlStoreString::store(theme_, s); }
  if (var0 & 32) { TlStoreString::store(success_return_url_, s); }
  if (var0 & 64) { TlStoreString::store(fail_return_url_, s); }
  if (var0 & 128) { TlStoreString::store(crypto_amount_, s); }
}

void payments_createOnrampSession::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1575387914);
  TlStoreBinary::store((var0 = flags_ | ((!payment_method_.empty()) << 0) | ((!base_currency_.empty()) << 1) | ((!base_amount_.empty()) << 2) | ((!memo_.empty()) << 3) | ((!theme_.empty()) << 4) | ((!success_return_url_.empty()) << 5) | ((!fail_return_url_.empty()) << 6) | ((!crypto_amount_.empty()) << 7)), s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(crypto_currency_, s);
  TlStoreString::store(address_, s);
  if (var0 & 1) { TlStoreString::store(payment_method_, s); }
  if (var0 & 2) { TlStoreString::store(base_currency_, s); }
  if (var0 & 4) { TlStoreString::store(base_amount_, s); }
  if (var0 & 8) { TlStoreString::store(memo_, s); }
  if (var0 & 16) { TlStoreString::store(theme_, s); }
  if (var0 & 32) { TlStoreString::store(success_return_url_, s); }
  if (var0 & 64) { TlStoreString::store(fail_return_url_, s); }
  if (var0 & 128) { TlStoreString::store(crypto_amount_, s); }
}

void payments_createOnrampSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.createOnrampSession");
    s.store_field("flags", (var0 = flags_ | ((!payment_method_.empty()) << 0) | ((!base_currency_.empty()) << 1) | ((!base_amount_.empty()) << 2) | ((!memo_.empty()) << 3) | ((!theme_.empty()) << 4) | ((!success_return_url_.empty()) << 5) | ((!fail_return_url_.empty()) << 6) | ((!crypto_amount_.empty()) << 7)));
    s.store_field("provider", provider_);
    s.store_field("crypto_currency", crypto_currency_);
    s.store_field("address", address_);
    if (var0 & 1) { s.store_field("payment_method", payment_method_); }
    if (var0 & 2) { s.store_field("base_currency", base_currency_); }
    if (var0 & 4) { s.store_field("base_amount", base_amount_); }
    if (var0 & 8) { s.store_field("memo", memo_); }
    if (var0 & 16) { s.store_field("theme", theme_); }
    if (var0 & 32) { s.store_field("success_return_url", success_return_url_); }
    if (var0 & 64) { s.store_field("fail_return_url", fail_return_url_); }
    if (var0 & 128) { s.store_field("crypto_amount", crypto_amount_); }
    s.store_class_end();
  }
}

payments_createOnrampSession::ReturnType payments_createOnrampSession::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<onrampSession>, -773575132>::parse(p);
#undef FAIL
}

payments_exportInvoice::payments_exportInvoice(object_ptr<InputMedia> &&invoice_media_)
  : invoice_media_(std::move(invoice_media_))
{}

const std::int32_t payments_exportInvoice::ID;

void payments_exportInvoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(261206117);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_media_, s);
}

void payments_exportInvoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(261206117);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_media_, s);
}

void payments_exportInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.exportInvoice");
    s.store_object_field("invoice_media", static_cast<const BaseObject *>(invoice_media_.get()));
    s.store_class_end();
  }
}

payments_exportInvoice::ReturnType payments_exportInvoice::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_exportedInvoice>, -1362048039>::parse(p);
#undef FAIL
}

payments_getStarsSubscriptions::payments_getStarsSubscriptions(int32 flags_, bool missing_balance_, object_ptr<InputPeer> &&peer_, string const &offset_)
  : flags_(flags_)
  , missing_balance_(missing_balance_)
  , peer_(std::move(peer_))
  , offset_(offset_)
{}

const std::int32_t payments_getStarsSubscriptions::ID;

void payments_getStarsSubscriptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(52761285);
  TlStoreBinary::store((var0 = flags_ | (missing_balance_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
}

void payments_getStarsSubscriptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(52761285);
  TlStoreBinary::store((var0 = flags_ | (missing_balance_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
}

void payments_getStarsSubscriptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsSubscriptions");
    s.store_field("flags", (var0 = flags_ | (missing_balance_ << 0)));
    if (var0 & 1) { s.store_field("missing_balance", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

payments_getStarsSubscriptions::ReturnType payments_getStarsSubscriptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsStatus>, 1822222573>::parse(p);
#undef FAIL
}

payments_sendStarGiftOnchainOffer::payments_sendStarGiftOnchainOffer(string const &slug_, int64 amount_, int32 duration_, int64 random_id_)
  : slug_(slug_)
  , amount_(amount_)
  , duration_(duration_)
  , random_id_(random_id_)
{}

const std::int32_t payments_sendStarGiftOnchainOffer::ID;

void payments_sendStarGiftOnchainOffer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1250062274);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(amount_, s);
  TlStoreBinary::store(duration_, s);
  TlStoreBinary::store(random_id_, s);
}

void payments_sendStarGiftOnchainOffer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1250062274);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(amount_, s);
  TlStoreBinary::store(duration_, s);
  TlStoreBinary::store(random_id_, s);
}

void payments_sendStarGiftOnchainOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.sendStarGiftOnchainOffer");
    s.store_field("slug", slug_);
    s.store_field("amount", amount_);
    s.store_field("duration", duration_);
    s.store_field("random_id", random_id_);
    s.store_class_end();
  }
}

payments_sendStarGiftOnchainOffer::ReturnType payments_sendStarGiftOnchainOffer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftOnchainOfferTx>, -27885105>::parse(p);
#undef FAIL
}

payments_toggleStarGiftsPinnedToTop::payments_toggleStarGiftsPinnedToTop(object_ptr<InputPeer> &&peer_, array<object_ptr<InputSavedStarGift>> &&stargift_)
  : peer_(std::move(peer_))
  , stargift_(std::move(stargift_))
{}

const std::int32_t payments_toggleStarGiftsPinnedToTop::ID;

void payments_toggleStarGiftsPinnedToTop::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(353626032);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_toggleStarGiftsPinnedToTop::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(353626032);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_toggleStarGiftsPinnedToTop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.toggleStarGiftsPinnedToTop");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("stargift", stargift_.size()); for (const auto &_value : stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_toggleStarGiftsPinnedToTop::ReturnType payments_toggleStarGiftsPinnedToTop::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_getGroupCallStars::phone_getGroupCallStars(object_ptr<InputGroupCall> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t phone_getGroupCallStars::ID;

void phone_getGroupCallStars::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1868784386);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_getGroupCallStars::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1868784386);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_getGroupCallStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCallStars");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_getGroupCallStars::ReturnType phone_getGroupCallStars::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_groupCallStars>, -1658995418>::parse(p);
#undef FAIL
}

phone_inviteToGroupCall::phone_inviteToGroupCall(object_ptr<InputGroupCall> &&call_, array<object_ptr<InputUser>> &&users_)
  : call_(std::move(call_))
  , users_(std::move(users_))
{}

const std::int32_t phone_inviteToGroupCall::ID;

void phone_inviteToGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2067345760);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void phone_inviteToGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2067345760);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void phone_inviteToGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.inviteToGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

phone_inviteToGroupCall::ReturnType phone_inviteToGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_requestCall::phone_requestCall(int32 flags_, bool video_, object_ptr<InputUser> &&user_id_, int32 random_id_, bytes &&g_a_hash_, object_ptr<phoneCallProtocol> &&protocol_)
  : flags_(flags_)
  , video_(video_)
  , user_id_(std::move(user_id_))
  , random_id_(random_id_)
  , g_a_hash_(std::move(g_a_hash_))
  , protocol_(std::move(protocol_))
{}

const std::int32_t phone_requestCall::ID;

void phone_requestCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1124046573);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(g_a_hash_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_requestCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1124046573);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(g_a_hash_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_requestCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.requestCall");
    s.store_field("flags", (var0 = flags_ | (video_ << 0)));
    if (var0 & 1) { s.store_field("video", true); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("random_id", random_id_);
    s.store_bytes_field("g_a_hash", g_a_hash_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

phone_requestCall::ReturnType phone_requestCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_phoneCall>, -326966976>::parse(p);
#undef FAIL
}

phone_setCallRating::phone_setCallRating(int32 flags_, bool user_initiative_, object_ptr<inputPhoneCall> &&peer_, int32 rating_, string const &comment_)
  : flags_(flags_)
  , user_initiative_(user_initiative_)
  , peer_(std::move(peer_))
  , rating_(rating_)
  , comment_(comment_)
{}

const std::int32_t phone_setCallRating::ID;

void phone_setCallRating::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1508562471);
  TlStoreBinary::store((var0 = flags_ | (user_initiative_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBinary::store(rating_, s);
  TlStoreString::store(comment_, s);
}

void phone_setCallRating::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1508562471);
  TlStoreBinary::store((var0 = flags_ | (user_initiative_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBinary::store(rating_, s);
  TlStoreString::store(comment_, s);
}

void phone_setCallRating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.setCallRating");
    s.store_field("flags", (var0 = flags_ | (user_initiative_ << 0)));
    if (var0 & 1) { s.store_field("user_initiative", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("rating", rating_);
    s.store_field("comment", comment_);
    s.store_class_end();
  }
}

phone_setCallRating::ReturnType phone_setCallRating::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

stories_deleteStories::stories_deleteStories(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t stories_deleteStories::ID;

void stories_deleteStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1369842849);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_deleteStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1369842849);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_deleteStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.deleteStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_deleteStories::ReturnType stories_deleteStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
#undef FAIL
}

stories_editStory::stories_editStory(int32 flags_, object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<InputMedia> &&media_, array<object_ptr<MediaArea>> &&media_areas_, string const &caption_, array<object_ptr<MessageEntity>> &&entities_, array<object_ptr<InputPrivacyRule>> &&privacy_rules_, object_ptr<InputDocument> &&music_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , media_(std::move(media_))
  , media_areas_(std::move(media_areas_))
  , caption_(caption_)
  , entities_(std::move(entities_))
  , privacy_rules_(std::move(privacy_rules_))
  , music_(std::move(music_))
{}

const std::int32_t stories_editStory::ID;

void stories_editStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(744728363);
  TlStoreBinary::store((var0 = flags_ | ((media_ != nullptr) << 0) | ((!media_areas_.empty()) << 3) | ((!caption_.empty()) << 1) | ((!entities_.empty()) << 1) | ((!privacy_rules_.empty()) << 2) | ((music_ != nullptr) << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 2) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void stories_editStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(744728363);
  TlStoreBinary::store((var0 = flags_ | ((media_ != nullptr) << 0) | ((!media_areas_.empty()) << 3) | ((!caption_.empty()) << 1) | ((!entities_.empty()) << 1) | ((!privacy_rules_.empty()) << 2) | ((music_ != nullptr) << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 2) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void stories_editStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.editStory");
    s.store_field("flags", (var0 = flags_ | ((media_ != nullptr) << 0) | ((!media_areas_.empty()) << 3) | ((!caption_.empty()) << 1) | ((!entities_.empty()) << 1) | ((!privacy_rules_.empty()) << 2) | ((music_ != nullptr) << 4)));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 8) { { s.store_vector_begin("media_areas", media_areas_.size()); for (const auto &_value : media_areas_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("caption", caption_); }
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("privacy_rules", privacy_rules_.size()); for (const auto &_value : privacy_rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { s.store_object_field("music", static_cast<const BaseObject *>(music_.get())); }
    s.store_class_end();
  }
}

stories_editStory::ReturnType stories_editStory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

stories_getPeerMaxIDs::stories_getPeerMaxIDs(array<object_ptr<InputPeer>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t stories_getPeerMaxIDs::ID;

void stories_getPeerMaxIDs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2018087280);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void stories_getPeerMaxIDs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2018087280);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void stories_getPeerMaxIDs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getPeerMaxIDs");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_getPeerMaxIDs::ReturnType stories_getPeerMaxIDs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<recentStory>, 1897752877>>, 481674261>::parse(p);
#undef FAIL
}

stories_searchPosts::stories_searchPosts(int32 flags_, string const &hashtag_, object_ptr<MediaArea> &&area_, object_ptr<InputPeer> &&peer_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , hashtag_(hashtag_)
  , area_(std::move(area_))
  , peer_(std::move(peer_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stories_searchPosts::ID;

void stories_searchPosts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-780072697);
  TlStoreBinary::store((var0 = flags_ | ((!hashtag_.empty()) << 0) | ((area_ != nullptr) << 1) | ((peer_ != nullptr) << 2)), s);
  if (var0 & 1) { TlStoreString::store(hashtag_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(area_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_searchPosts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-780072697);
  TlStoreBinary::store((var0 = flags_ | ((!hashtag_.empty()) << 0) | ((area_ != nullptr) << 1) | ((peer_ != nullptr) << 2)), s);
  if (var0 & 1) { TlStoreString::store(hashtag_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(area_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_searchPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.searchPosts");
    s.store_field("flags", (var0 = flags_ | ((!hashtag_.empty()) << 0) | ((area_ != nullptr) << 1) | ((peer_ != nullptr) << 2)));
    if (var0 & 1) { s.store_field("hashtag", hashtag_); }
    if (var0 & 2) { s.store_object_field("area", static_cast<const BaseObject *>(area_.get())); }
    if (var0 & 4) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_searchPosts::ReturnType stories_searchPosts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_foundStories>, -488736969>::parse(p);
#undef FAIL
}

const std::int32_t toncenter_getStreamingUrl::ID;

void toncenter_getStreamingUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-844143673);
}

void toncenter_getStreamingUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-844143673);
}

void toncenter_getStreamingUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toncenter.getStreamingUrl");
    s.store_class_end();
  }
}

toncenter_getStreamingUrl::ReturnType toncenter_getStreamingUrl::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<toncenter_streamingUrl>, 428373505>::parse(p);
#undef FAIL
}

upload_reuploadCdnFile::upload_reuploadCdnFile(bytes &&file_token_, bytes &&request_token_)
  : file_token_(std::move(file_token_))
  , request_token_(std::move(request_token_))
{}

const std::int32_t upload_reuploadCdnFile::ID;

void upload_reuploadCdnFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1691921240);
  TlStoreString::store(file_token_, s);
  TlStoreString::store(request_token_, s);
}

void upload_reuploadCdnFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1691921240);
  TlStoreString::store(file_token_, s);
  TlStoreString::store(request_token_, s);
}

void upload_reuploadCdnFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.reuploadCdnFile");
    s.store_field("file_token", "[REDACTED]");
    s.store_field("request_token", "[REDACTED]");
    s.store_class_end();
  }
}

upload_reuploadCdnFile::ReturnType upload_reuploadCdnFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<fileHash>, -207944868>>, 481674261>::parse(p);
#undef FAIL
}

users_setSecureValueErrors::users_setSecureValueErrors(object_ptr<InputUser> &&id_, array<object_ptr<SecureValueError>> &&errors_)
  : id_(std::move(id_))
  , errors_(std::move(errors_))
{}

const std::int32_t users_setSecureValueErrors::ID;

void users_setSecureValueErrors::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1865902923);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(errors_, s);
}

void users_setSecureValueErrors::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1865902923);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(errors_, s);
}

void users_setSecureValueErrors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.setSecureValueErrors");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    { s.store_vector_begin("errors", errors_.size()); for (const auto &_value : errors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

users_setSecureValueErrors::ReturnType users_setSecureValueErrors::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

wallet_getTransactionsByMsgHash::wallet_getTransactionsByMsgHash(array<string> &&msg_hash_)
  : msg_hash_(std::move(msg_hash_))
{}

const std::int32_t wallet_getTransactionsByMsgHash::ID;

void wallet_getTransactionsByMsgHash::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1497663139);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(msg_hash_, s);
}

void wallet_getTransactionsByMsgHash::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1497663139);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(msg_hash_, s);
}

void wallet_getTransactionsByMsgHash::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.getTransactionsByMsgHash");
    { s.store_vector_begin("msg_hash", msg_hash_.size()); for (const auto &_value : msg_hash_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

wallet_getTransactionsByMsgHash::ReturnType wallet_getTransactionsByMsgHash::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<wallet_transactions>, 1126356389>::parse(p);
#undef FAIL
}

wallet_sendTransfer::wallet_sendTransfer(int32 flags_, bytes &&data_normal_, bytes &&data_gasless_, object_ptr<InputUser> &&user_id_, int64 random_id_)
  : flags_(flags_)
  , data_normal_(std::move(data_normal_))
  , data_gasless_(std::move(data_gasless_))
  , user_id_(std::move(user_id_))
  , random_id_(random_id_)
{}

const std::int32_t wallet_sendTransfer::ID;

void wallet_sendTransfer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-639247902);
  TlStoreBinary::store((var0 = flags_ | ((!data_gasless_.empty()) << 0)), s);
  TlStoreString::store(data_normal_, s);
  if (var0 & 1) { TlStoreString::store(data_gasless_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(random_id_, s);
}

void wallet_sendTransfer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-639247902);
  TlStoreBinary::store((var0 = flags_ | ((!data_gasless_.empty()) << 0)), s);
  TlStoreString::store(data_normal_, s);
  if (var0 & 1) { TlStoreString::store(data_gasless_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(random_id_, s);
}

void wallet_sendTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallet.sendTransfer");
    s.store_field("flags", (var0 = flags_ | ((!data_gasless_.empty()) << 0)));
    s.store_bytes_field("data_normal", data_normal_);
    if (var0 & 1) { s.store_bytes_field("data_gasless", data_gasless_); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("random_id", random_id_);
    s.store_class_end();
  }
}

wallet_sendTransfer::ReturnType wallet_sendTransfer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
