# Ported from td/telegram/MessageEntity.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's conversions of formatted texts and their entities."""

from collections.abc import Sequence
from dataclasses import replace

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api, telegram_api
from tdlib_oracle.tdlib.custom_emoji_id import is_valid_custom_emoji_id
from tdlib_oracle.tdlib.formatted_date import (
    get_date_time_formatting_type_object,
    get_formatted_date,
    get_input_message_entity_formatted_date,
    is_valid_formatted_date,
    make_formatted_date,
)
from tdlib_oracle.tdlib.link_manager import check_link, get_link_user_id
from tdlib_oracle.tdlib.message_entity.entity import (
    TYPE,
    FormattedText,
    MessageEntity,
    _is_splittable_entity,
    _is_user_entity,
    _split_entities,
)
from tdlib_oracle.tdlib.message_entity.fixing import fix_formatted_text
from tdlib_oracle.tdlib.misc import clean_input_string
from tdlib_oracle.tdlib.user_id import is_valid_user_id
from tdlib_oracle.tdlib.user_manager import get_input_user, get_input_user_force


# Ported from td/telegram/MessageEntity.cpp,
# MessageEntity::get_text_entity_type_object(), without a user manager.
def get_text_entity_type_object(entity: MessageEntity) -> td_api.TextEntityType:
    """Return the API object of the type of `entity`, with the value the type takes.

    A media timestamp shows `-1`, the value of an entity built without one, since the
    port's entities carry none.
    """
    match entity.type:
        case TYPE.MENTION:
            return td_api.TextEntityTypeMention()
        case TYPE.HASHTAG:
            return td_api.TextEntityTypeHashtag()
        case TYPE.BOT_COMMAND:
            return td_api.TextEntityTypeBotCommand()
        case TYPE.URL:
            return td_api.TextEntityTypeUrl()
        case TYPE.EMAIL_ADDRESS:
            return td_api.TextEntityTypeEmailAddress()
        case TYPE.BOLD:
            return td_api.TextEntityTypeBold()
        case TYPE.ITALIC:
            return td_api.TextEntityTypeItalic()
        case TYPE.UNDERLINE:
            return td_api.TextEntityTypeUnderline()
        case TYPE.STRIKETHROUGH:
            return td_api.TextEntityTypeStrikethrough()
        case TYPE.BLOCK_QUOTE:
            return td_api.TextEntityTypeBlockQuote()
        case TYPE.CODE:
            return td_api.TextEntityTypeCode()
        case TYPE.PRE:
            return td_api.TextEntityTypePre()
        case TYPE.PRE_CODE:
            return td_api.TextEntityTypePreCode(entity.argument)
        case TYPE.TEXT_URL:
            return td_api.TextEntityTypeTextUrl(entity.argument)
        case TYPE.MENTION_NAME:
            return td_api.TextEntityTypeMentionName(entity.user_id)
        case TYPE.CASHTAG:
            return td_api.TextEntityTypeCashtag()
        case TYPE.PHONE_NUMBER:
            return td_api.TextEntityTypePhoneNumber()
        case TYPE.BANK_CARD_NUMBER:
            return td_api.TextEntityTypeBankCardNumber()
        case TYPE.MEDIA_TIMESTAMP:
            return td_api.TextEntityTypeMediaTimestamp(-1)
        case TYPE.SPOILER:
            return td_api.TextEntityTypeSpoiler()
        case TYPE.CUSTOM_EMOJI:
            return td_api.TextEntityTypeCustomEmoji(entity.custom_emoji_id)
        case TYPE.EXPANDABLE_BLOCK_QUOTE:
            return td_api.TextEntityTypeExpandableBlockQuote()
        case TYPE.FORMATTED_DATE:
            return td_api.TextEntityTypeDateTime(
                entity.date, get_date_time_formatting_type_object(entity.date_flags)
            )
        case _:  # TYPE.TON_ADDRESS, the last type left
            return td_api.TextEntityTypeTonAddress()


# Ported from td/telegram/MessageEntity.cpp, MessageEntity::get_text_entity_object(),
# without a user manager.
def get_text_entity_object(entity: MessageEntity) -> td_api.TextEntity:
    """Return the API object of `entity`."""
    ties = tuple(
        dict.fromkeys(
            td_api.TextEntity(tie.offset, tie.length, get_text_entity_type_object(tie))
            for tie in entity.ties
        )
    )
    return td_api.TextEntity(
        entity.offset,
        entity.length,
        get_text_entity_type_object(entity),
        ties if len(ties) > 1 else (),
    )


# Ported from td/telegram/MessageEntity.cpp, get_text_entities_object(), without a user
# manager and keeping bot commands, as SynchronousRequests::do_request() calls it
# for parseTextEntities.
def get_text_entities_object(
    entities: Sequence[MessageEntity],
) -> tuple[td_api.TextEntity, ...]:
    """Return the API objects of `entities`, in their order.

    Every entity becomes an object, since the port's entities carry no media timestamp
    to leave out.
    """
    return tuple(get_text_entity_object(entity) for entity in entities)


# Ported from td/telegram/MessageEntity.cpp,
# get_message_entities(const UserManager *user_manager,
#     vector<tl_object_ptr<td_api::textEntity>> &&input_entities, bool allow_all),
# with a bot's user manager and allow_all false, as get_formatted_text() calls it.
def get_message_entities(
    input_entities: Sequence[td_api.TextEntity | None],
) -> tuple[MessageEntity, ...] | Failure:
    """Return the entities the API objects `input_entities` give, or a `Failure`."""

    def convert(
        offset: int, length: int, entity_type: td_api.TextEntityType
    ) -> MessageEntity | Failure:
        match entity_type:
            case td_api.TextEntityTypeMention():
                return MessageEntity(TYPE.MENTION, offset, length)
            case td_api.TextEntityTypeHashtag():
                return MessageEntity(TYPE.HASHTAG, offset, length)
            case td_api.TextEntityTypeBotCommand():
                return MessageEntity(TYPE.BOT_COMMAND, offset, length)
            case td_api.TextEntityTypeUrl():
                return MessageEntity(TYPE.URL, offset, length)
            case td_api.TextEntityTypeEmailAddress():
                return MessageEntity(TYPE.EMAIL_ADDRESS, offset, length)
            case td_api.TextEntityTypeCashtag():
                return MessageEntity(TYPE.CASHTAG, offset, length)
            case td_api.TextEntityTypePhoneNumber():
                return MessageEntity(TYPE.PHONE_NUMBER, offset, length)
            case td_api.TextEntityTypeBankCardNumber():
                return MessageEntity(TYPE.BANK_CARD_NUMBER, offset, length)
            case td_api.TextEntityTypeBold():
                return MessageEntity(TYPE.BOLD, offset, length)
            case td_api.TextEntityTypeItalic():
                return MessageEntity(TYPE.ITALIC, offset, length)
            case td_api.TextEntityTypeUnderline():
                return MessageEntity(TYPE.UNDERLINE, offset, length)
            case td_api.TextEntityTypeStrikethrough():
                return MessageEntity(TYPE.STRIKETHROUGH, offset, length)
            case td_api.TextEntityTypeBlockQuote():
                return MessageEntity(TYPE.BLOCK_QUOTE, offset, length)
            case td_api.TextEntityTypeCode():
                return MessageEntity(TYPE.CODE, offset, length)
            case td_api.TextEntityTypePre():
                return MessageEntity(TYPE.PRE, offset, length)
            case td_api.TextEntityTypePreCode(language=language):
                cleaned = clean_input_string(language)
                if cleaned is None:
                    return Failure(
                        400, "MessageEntityPreCode.language must be encoded in UTF-8"
                    )
                return MessageEntity(TYPE.PRE_CODE, offset, length, cleaned)
            case td_api.TextEntityTypeTextUrl(url=url):
                cleaned = clean_input_string(url)
                if cleaned is None:
                    return Failure(
                        400, "MessageEntityTextUrl.url must be encoded in UTF-8"
                    )
                user_id = get_link_user_id(cleaned)
                if is_valid_user_id(user_id):
                    failure = get_input_user(user_id)
                    if failure is not None:
                        return failure
                    return MessageEntity(
                        TYPE.MENTION_NAME, offset, length, user_id=user_id
                    )
                checked = check_link(cleaned)
                if isinstance(checked, Failure):
                    return Failure(400, f"Entity {checked.message}")
                return MessageEntity(TYPE.TEXT_URL, offset, length, checked)
            case td_api.TextEntityTypeMentionName(user_id=user_id):
                failure = get_input_user(user_id)
                if failure is not None:
                    return failure
                return MessageEntity(TYPE.MENTION_NAME, offset, length, user_id=user_id)
            case td_api.TextEntityTypeMediaTimestamp(media_timestamp=media_timestamp):
                if media_timestamp < 0:
                    return Failure(400, "Invalid media timestamp specified")
                # The port's entities carry no media timestamp, and a user cannot set
                # this type, so the entity goes before anything reads its timestamp.
                return MessageEntity(TYPE.MEDIA_TIMESTAMP, offset, length)
            case td_api.TextEntityTypeSpoiler():
                return MessageEntity(TYPE.SPOILER, offset, length)
            case td_api.TextEntityTypeCustomEmoji(custom_emoji_id=custom_emoji_id):
                if not is_valid_custom_emoji_id(custom_emoji_id):
                    return Failure(400, "Invalid custom emoji identifier specified")
                return MessageEntity(
                    TYPE.CUSTOM_EMOJI, offset, length, custom_emoji_id=custom_emoji_id
                )
            case td_api.TextEntityTypeExpandableBlockQuote():
                return MessageEntity(TYPE.EXPANDABLE_BLOCK_QUOTE, offset, length)
            case td_api.TextEntityTypeDateTime(
                unix_time=unix_time, formatting_type=formatting_type
            ):
                date = get_formatted_date(unix_time, formatting_type)
                if isinstance(date, Failure):
                    return date
                return MessageEntity(
                    TYPE.FORMATTED_DATE,
                    offset,
                    length,
                    date=date[0],
                    date_flags=date[1],
                )
            case _:  # td_api.TextEntityTypeTonAddress, the last type left
                return MessageEntity(TYPE.TON_ADDRESS, offset, length)

    entities = []
    for input_entity in input_entities:
        if input_entity is None or input_entity.type is None:
            continue
        entity = convert(input_entity.offset, input_entity.length, input_entity.type)
        if isinstance(entity, Failure):
            return entity
        if not _is_user_entity(entity.type):
            continue

        # Each entity of a tie is among the objects too, so one that fails has already
        # refused them all or does so when its turn comes.
        converted = (
            convert(tie.offset, tie.length, tie.type)
            for tie in input_entity.ties
            if tie.type is not None
        )
        ties = tuple(
            dict.fromkeys(tie for tie in converted if isinstance(tie, MessageEntity))
        )
        entities.append(replace(entity, ties=ties) if len(ties) > 1 else entity)
    return tuple(entities)


# Ported from td/telegram/MessageEntity.cpp,
# get_message_entities(const UserManager *user_manager,
#     vector<tl_object_ptr<telegram_api::MessageEntity>> &&server_entities,
#     const char *source),
# for the objects get_input_message_entities() sends and messageEntityMentionName, with
# a user manager that has met each user a mention names, and without its log.
def get_server_message_entities(
    server_entities: Sequence[telegram_api.MessageEntity],
) -> tuple[MessageEntity, ...]:
    """Return the entities that TDLib reads from the objects Telegram returns."""

    def convert(server_entity: telegram_api.MessageEntity) -> MessageEntity | None:
        match server_entity:
            case telegram_api.MessageEntityBold(offset=offset, length=length):
                return MessageEntity(TYPE.BOLD, offset, length)
            case telegram_api.MessageEntityItalic(offset=offset, length=length):
                return MessageEntity(TYPE.ITALIC, offset, length)
            case telegram_api.MessageEntityUnderline(offset=offset, length=length):
                return MessageEntity(TYPE.UNDERLINE, offset, length)
            case telegram_api.MessageEntityStrike(offset=offset, length=length):
                return MessageEntity(TYPE.STRIKETHROUGH, offset, length)
            case telegram_api.MessageEntitySpoiler(offset=offset, length=length):
                return MessageEntity(TYPE.SPOILER, offset, length)
            case telegram_api.MessageEntityBlockquote(
                collapsed=collapsed, offset=offset, length=length
            ):
                entity_type = (
                    TYPE.EXPANDABLE_BLOCK_QUOTE if collapsed else TYPE.BLOCK_QUOTE
                )
                return MessageEntity(entity_type, offset, length)
            case telegram_api.MessageEntityCode(offset=offset, length=length):
                return MessageEntity(TYPE.CODE, offset, length)
            case telegram_api.MessageEntityPre(
                offset=offset, length=length, language=language
            ):
                if not language:
                    return MessageEntity(TYPE.PRE, offset, length)
                return MessageEntity(TYPE.PRE_CODE, offset, length, language)
            case telegram_api.MessageEntityTextUrl(
                offset=offset, length=length, url=url
            ):
                checked = check_link(url)
                if isinstance(checked, Failure):
                    return None
                return MessageEntity(TYPE.TEXT_URL, offset, length, checked)
            case telegram_api.MessageEntityMentionName(
                offset=offset, length=length, user_id=user_id
            ):
                if not is_valid_user_id(user_id):
                    return None
                # Stands in for td/telegram/UserManager.cpp,
                # UserManager::have_min_user(), for a user TDLib has met.
                return MessageEntity(TYPE.MENTION_NAME, offset, length, user_id=user_id)
            case telegram_api.MessageEntityCustomEmoji(
                offset=offset, length=length, document_id=document_id
            ):
                return MessageEntity(
                    TYPE.CUSTOM_EMOJI, offset, length, custom_emoji_id=document_id
                )
            case telegram_api.MessageEntityFormattedDate():
                date, date_flags = make_formatted_date(
                    server_entity.date,
                    relative=server_entity.relative,
                    short_time=server_entity.short_time,
                    long_time=server_entity.long_time,
                    short_date=server_entity.short_date,
                    long_date=server_entity.long_date,
                    day_of_week=server_entity.day_of_week,
                )
                if not is_valid_formatted_date(date):
                    return None
                return MessageEntity(
                    TYPE.FORMATTED_DATE,
                    server_entity.offset,
                    server_entity.length,
                    date=date,
                    date_flags=date_flags,
                )
            case _:  # telegram_api.InputMessageEntityMentionName, the last type left
                # The pinned code stops at UNREACHABLE() for a mention in the form TDLib
                # sends, which it never expects back.
                return None

    entities = []
    for server_entity in server_entities:
        entity = convert(server_entity)
        if entity is None:
            continue
        converted = (convert(tie) for tie in server_entity.ties)
        ties = tuple(dict.fromkeys(tie for tie in converted if tie is not None))
        entities.append(replace(entity, ties=ties) if len(ties) > 1 else entity)
    return tuple(entities)


# Ported from td/telegram/MessageEntity.cpp, get_formatted_text(const Td *td, ...), for
# a bot's text in a chat that is not secret.
def get_formatted_text(
    text: td_api.FormattedText, *, allow_empty: bool, skip_trim: bool
) -> FormattedText | Failure:
    """Return a bot's `text` as TDLib fixes it, or the `Failure` that refuses it.

    A bot sends the text, so a text of blank characters is kept exactly when an empty
    text is allowed. The Bot API server never sets the `always_parse_markdown` option,
    so no Markdown is parsed. TDLib finds entities of its own in the text of a bot with
    one session; it sends none of them, and the splits they make in other entities merge
    again when it sends those, so the port finds none, as TDLib does for a bot with
    more sessions.
    """
    entities = get_message_entities(text.entities)
    if isinstance(entities, Failure):
        return entities

    # remove_unallowed_entities() comes last, and it removes nothing from a bot's text:
    # a bot has no secret chats and may use any custom emoji.
    return fix_formatted_text(
        text.text,
        entities,
        allow_empty=allow_empty,
        allow_empty_string=allow_empty,
        skip_new_entities=True,
        skip_bot_commands=True,
        skip_trim=skip_trim,
    )


# Ported from td/telegram/MessageEntity.cpp,
# MAX_USER_ENTITY_COUNT in get_input_message_entities().
_MAX_USER_ENTITY_COUNT = 100


# Ported from td/telegram/MessageEntity.cpp,
# get_input_message_entities(const UserManager *user_manager,
#     const vector<MessageEntity> &entities, const char *source),
# with a bot's user manager.
def get_input_message_entities(
    entities: Sequence[MessageEntity],
) -> tuple[telegram_api.MessageEntity, ...]:
    """Return the objects TDLib sends to Telegram for the sorted `entities` it keeps."""

    def convert(entity: MessageEntity) -> telegram_api.MessageEntity:
        offset = entity.offset
        length = entity.length
        match entity.type:
            case TYPE.CUSTOM_EMOJI:
                return telegram_api.MessageEntityCustomEmoji(
                    offset, length, entity.custom_emoji_id
                )
            case TYPE.BLOCK_QUOTE:
                return telegram_api.MessageEntityBlockquote(0, False, offset, length)
            case TYPE.CODE:
                return telegram_api.MessageEntityCode(offset, length)
            case TYPE.PRE:
                return telegram_api.MessageEntityPre(offset, length, b"")
            case TYPE.PRE_CODE:
                return telegram_api.MessageEntityPre(offset, length, entity.argument)
            case TYPE.TEXT_URL:
                return telegram_api.MessageEntityTextUrl(
                    offset, length, entity.argument
                )
            case TYPE.MENTION_NAME:
                input_user = get_input_user_force(entity.user_id)
                return telegram_api.InputMessageEntityMentionName(
                    offset, length, input_user
                )
            case TYPE.EXPANDABLE_BLOCK_QUOTE:
                return telegram_api.MessageEntityBlockquote(0, True, offset, length)
            case TYPE.FORMATTED_DATE:
                return get_input_message_entity_formatted_date(
                    entity.date, entity.date_flags, offset, length
                )
            case TYPE.BOLD:
                return telegram_api.MessageEntityBold(offset, length)
            case TYPE.ITALIC:
                return telegram_api.MessageEntityItalic(offset, length)
            case TYPE.UNDERLINE:
                return telegram_api.MessageEntityUnderline(offset, length)
            case TYPE.STRIKETHROUGH:
                return telegram_api.MessageEntityStrike(offset, length)
            case _:  # TYPE.SPOILER, the last type a user can set
                return telegram_api.MessageEntitySpoiler(offset, length)

    def send(entity: MessageEntity) -> telegram_api.MessageEntity:
        sent = convert(entity)
        ties = tuple(dict.fromkeys(convert(tie) for tie in entity.ties))
        return replace(sent, ties=ties) if len(ties) > 1 else sent

    result: list[telegram_api.MessageEntity] = []
    splittable_entities: list[MessageEntity] = []
    user_entity_count = 0
    for entity in entities:
        if not _is_user_entity(entity.type):
            continue
        if _is_splittable_entity(entity.type):
            splittable_entities.append(entity)
            continue
        if entity.type == TYPE.CUSTOM_EMOJI:
            result.append(send(entity))
            continue
        if user_entity_count >= _MAX_USER_ENTITY_COUNT:
            continue
        user_entity_count += 1
        result.append(send(entity))

    for entity in _split_entities(splittable_entities, ()):
        if user_entity_count >= _MAX_USER_ENTITY_COUNT:
            break
        user_entity_count += 1
        result.append(send(entity))
    return tuple(result)
