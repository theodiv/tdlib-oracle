# Ported from td/telegram/MessageEntity.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's conversions of formatted texts and their entities.

Entities become TDLib's API objects and come back from them, the text a bot sends
becomes the text TDLib keeps, and the entities it keeps become the ones it sends to
Telegram. The tie an entity is in travels with it through each conversion, converted as
the entity is, since the pinned code may hold any entity of the tie in its place.
"""

from collections.abc import Sequence
from dataclasses import replace

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.custom_emoji_id import is_valid_custom_emoji_id
from tdlib_oracle.tdlib.formatted_date import (
    get_date_time_formatting_type_object,
    get_formatted_date,
)
from tdlib_oracle.tdlib.link_manager import check_link, get_link_user_id
from tdlib_oracle.tdlib.message_entity.entity import (
    TYPE,
    MessageEntity,
    _is_splittable_entity,
    _is_user_entity,
    _split_entities,
)
from tdlib_oracle.tdlib.message_entity.fixing import fix_formatted_text
from tdlib_oracle.tdlib.misc import clean_input_string
from tdlib_oracle.tdlib.user_id import is_valid_user_id
from tdlib_oracle.tdlib.user_manager import get_input_user


# Ported from td/telegram/MessageEntity.cpp,
# MessageEntity::get_text_entity_type_object(), without a user manager.
def get_text_entity_type_object(  # noqa: PLR0911, PLR0912  # mirrors upstream
    entity: MessageEntity,
) -> td_api.TextEntityType:
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
    """Return the API object of `entity`.

    The entities of the tie `entity` is in become objects the same way, and the tie ends
    when they all become one object.
    """
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

    Every entity becomes an object, since the request keeps bot commands and the port's
    entities carry no media timestamp to leave out.
    """
    return tuple(get_text_entity_object(entity) for entity in entities)


# Ported from td/telegram/MessageEntity.cpp, get_message_entities(const UserManager
# *user_manager, vector<tl_object_ptr<td_api::textEntity>> &&input_entities, bool
# allow_all), with a bot's user manager and allow_all false, as get_formatted_text()
# calls it.
def get_message_entities(  # noqa: PLR0915  # mirrors upstream
    input_entities: Sequence[td_api.TextEntity | None],
) -> tuple[MessageEntity, ...] | Failure:
    """Return the entities that the API objects `input_entities` give, or a `Failure`.

    A null object, or one of a null type, gives nothing, and only the types a user can
    set stay, but every value is checked first, and the first that fails refuses them
    all: a language or a link must be UTF-8, and is cleaned; a link to a valid user
    mentions that user, and any other must pass `check_link()`; a mentioned user must be
    one a bot can name; a media timestamp must not be negative, a custom emoji ID must
    be valid, and a date must be positive. The objects of the tie an object is in become
    entities the same way, and the tie ends when they all become one entity.
    """

    def convert(  # noqa: PLR0911, PLR0912  # mirrors upstream
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


# Ported from td/telegram/MessageEntity.cpp, get_formatted_text(const Td *td, ...), for
# a bot's text without entities.
def get_formatted_text(
    text: bytes, *, allow_empty: bool, skip_trim: bool
) -> bytes | Failure:
    """Return a bot's `text` as TDLib fixes it, or the `Failure` that refuses it.

    A bot sends the text, so a text of blank characters is kept exactly when an empty
    text is allowed. The Bot API server never sets the `always_parse_markdown` option,
    so no Markdown is parsed. The entities TDLib finds in the text leave the text as it
    is, and only the text comes back, so none are looked for, as for a bot with more
    than one session.
    """
    result = fix_formatted_text(
        text,
        (),
        allow_empty=allow_empty,
        allow_empty_string=allow_empty,
        skip_new_entities=True,
        skip_bot_commands=True,
        skip_trim=skip_trim,
    )
    if isinstance(result, Failure):
        return result
    return result.text


# Ported from td/telegram/MessageEntity.cpp, MAX_USER_ENTITY_COUNT
# in get_input_message_entities().
_MAX_USER_ENTITY_COUNT = 100


# Ported from td/telegram/MessageEntity.cpp, get_input_message_entities(const
# UserManager *user_manager, const vector<MessageEntity> &entities, const char *source),
# as the entities it sends.
def get_input_message_entities(
    entities: Sequence[MessageEntity],
) -> tuple[MessageEntity, ...]:
    """Return the entities TDLib sends to Telegram for the sorted `entities` it keeps.

    Only the types a user can set go. Custom emoji go however many there are, and the
    other types up to 100 entities in all: first those that are not splittable, in their
    order, then the splittable ones, merged where they overlap or touch and cut where
    another splittable type starts. Each goes as TDLib keeps it, though TDLib sends only
    the value its type takes.
    """
    result: list[MessageEntity] = []
    splittable_entities: list[MessageEntity] = []
    user_entity_count = 0
    for entity in entities:
        if not _is_user_entity(entity.type):
            continue
        if _is_splittable_entity(entity.type):
            splittable_entities.append(entity)
            continue
        if entity.type == TYPE.CUSTOM_EMOJI:
            result.append(entity)
            continue
        if user_entity_count >= _MAX_USER_ENTITY_COUNT:
            continue
        user_entity_count += 1
        result.append(entity)

    for entity in _split_entities(splittable_entities, ()):
        if user_entity_count >= _MAX_USER_ENTITY_COUNT:
            break
        user_entity_count += 1
        result.append(entity)
    return tuple(result)
