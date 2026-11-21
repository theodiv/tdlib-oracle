# Ported from td/telegram/MessageEntity.h and td/telegram/MessageEntity.cpp of TDLib at
# the commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's message entities: their types, the classes of types, and their order.

The pinned code sorts entities with `std::sort`, which leaves the order of entities that
compare equal to the C++ library, so a server built with another library can keep
another entity of such a tie. The port sorts as `sorted()` does and records on its
entities each tie between entities that differ.

Finding, fixing, and parsing all sort entities, and finding and fixing also test the
classes of their types and drop entities that intersect, so those operations live here.
"""

from collections.abc import Iterable, Sequence
from dataclasses import dataclass, replace
from itertools import groupby, pairwise
from typing import Final


# Ported from td/telegram/MessageEntity.h, MessageEntity::Type.
class TYPE:
    """The types of message entities, numbered as TDLib numbers them."""

    MENTION: Final = 0
    HASHTAG: Final = 1
    BOT_COMMAND: Final = 2
    URL: Final = 3
    EMAIL_ADDRESS: Final = 4
    BOLD: Final = 5
    ITALIC: Final = 6
    CODE: Final = 7
    PRE: Final = 8
    PRE_CODE: Final = 9
    TEXT_URL: Final = 10
    MENTION_NAME: Final = 11
    CASHTAG: Final = 12
    PHONE_NUMBER: Final = 13
    UNDERLINE: Final = 14
    STRIKETHROUGH: Final = 15
    BLOCK_QUOTE: Final = 16
    BANK_CARD_NUMBER: Final = 17
    MEDIA_TIMESTAMP: Final = 18
    SPOILER: Final = 19
    CUSTOM_EMOJI: Final = 20
    EXPANDABLE_BLOCK_QUOTE: Final = 21
    FORMATTED_DATE: Final = 22
    TON_ADDRESS: Final = 23
    SIZE: Final = 24


# Ported from td/telegram/MessageEntity.cpp, priorities in
# MessageEntity::get_type_priority().
_PRIORITIES = (
    50,  # MENTION
    50,  # HASHTAG
    50,  # BOT_COMMAND
    50,  # URL
    50,  # EMAIL_ADDRESS
    90,  # BOLD
    91,  # ITALIC
    20,  # CODE
    11,  # PRE
    10,  # PRE_CODE
    49,  # TEXT_URL
    49,  # MENTION_NAME
    50,  # CASHTAG
    50,  # PHONE_NUMBER
    92,  # UNDERLINE
    93,  # STRIKETHROUGH
    0,  # BLOCK_QUOTE
    50,  # BANK_CARD_NUMBER
    50,  # MEDIA_TIMESTAMP
    94,  # SPOILER
    99,  # CUSTOM_EMOJI
    0,  # EXPANDABLE_BLOCK_QUOTE
    30,  # FORMATTED_DATE
    50,  # TON_ADDRESS
)


# Ported from td/telegram/MessageEntity.h, MessageEntity, without media_timestamp, which
# no entity of a bot's text carries.
@dataclass(frozen=True)
class MessageEntity:
    """A formatting entity of a text, as TDLib keeps it.

    A type that takes a value keeps it in the field for its kind: a string in
    `argument`, a user in `user_id`, a custom emoji in `custom_emoji_id`, a date in
    `date` and `date_flags`. Two entities are equal when all their fields are, as in
    TDLib, `ties` included.

    Attributes:
        type: The entity type, one of `TYPE`.
        offset: Where the entity starts, in UTF-16 code units.
        length: The length of the entity, in UTF-16 code units.
        argument: The string value, such as the URL of a `TEXT_URL` or the language of a
            `PRE_CODE`.
        user_id: The user a `MENTION_NAME` names.
        custom_emoji_id: The custom emoji a `CUSTOM_EMOJI` shows.
        date: The Unix time a `FORMATTED_DATE` shows.
        date_flags: The parts of the date a `FORMATTED_DATE` shows, as TDLib's flags.
        ties: When a sort met this entity in a tie with entities that differ from it,
            the entities of that tie as they were then, each once; the pinned code may
            keep any of them in this entity's place. Empty otherwise.
    """

    type: int
    offset: int
    length: int
    argument: bytes = b""
    user_id: int = 0
    custom_emoji_id: int = 0
    date: int = 0
    date_flags: int = 0
    ties: tuple["MessageEntity", ...] = ()


# Ported from td/telegram/MessageEntity.h, FormattedText.
@dataclass(frozen=True)
class FormattedText:
    """A text and its formatting entities, as TDLib keeps them.

    Attributes:
        text: The text, in UTF-8.
        entities: The formatting entities of `text`.
    """

    text: bytes
    entities: tuple[MessageEntity, ...] = ()


# Ported from td/telegram/MessageEntity.h, MessageEntity::operator<(), as a sort key.
def order(entity: MessageEntity) -> tuple[int, int, int]:
    """Return the key that puts `entity` in TDLib's order of entities.

    Entities sort by offset, then the longer one first, then by the priority of their
    type, so a blockquote, at priority 0, comes before the entities it starts with.
    """
    return entity.offset, -entity.length, _PRIORITIES[entity.type]


# Ported from td/telegram/MessageEntity.cpp, sort_entities().
def _sort_entities(entities: Sequence[MessageEntity]) -> tuple[MessageEntity, ...]:
    """Return `entities` in TDLib's order, marking each tie of entities that differ.

    Entities already in order come back unchanged, since the pinned code sorts only
    entities out of order. Others come back sorted as `sorted()` sorts them, so entities
    that compare equal, with the same offset, length, and type priority, keep their
    input order; where they differ in type or value, each of them carries the whole tie
    in `ties`.
    """
    keys = [order(entity) for entity in entities]
    if all(first <= second for first, second in pairwise(keys)):
        return tuple(entities)

    result: list[MessageEntity] = []
    for _, group in groupby(sorted(entities, key=order), key=order):
        tie = tuple(group)
        if len(tie) > 1:
            values = tuple(
                dict.fromkeys(
                    replace(entity, ties=()) if entity.ties else entity
                    for entity in tie
                )
            )
            if len(values) > 1:
                tie = tuple(replace(entity, ties=values) for entity in tie)
        result.extend(tie)
    return tuple(result)


# Ported from td/telegram/MessageEntity.cpp, get_entity_type_mask().
def _get_entity_type_mask(entity_type: int) -> int:
    return 1 << entity_type


# Ported from td/telegram/MessageEntity.cpp, get_splittable_entities_mask().
_SPLITTABLE_ENTITIES_MASK = (
    _get_entity_type_mask(TYPE.BOLD)
    | _get_entity_type_mask(TYPE.ITALIC)
    | _get_entity_type_mask(TYPE.UNDERLINE)
    | _get_entity_type_mask(TYPE.STRIKETHROUGH)
    | _get_entity_type_mask(TYPE.SPOILER)
)

# Ported from td/telegram/MessageEntity.cpp, get_blockquote_entities_mask().
_BLOCKQUOTE_ENTITIES_MASK = _get_entity_type_mask(
    TYPE.BLOCK_QUOTE
) | _get_entity_type_mask(TYPE.EXPANDABLE_BLOCK_QUOTE)

# Ported from td/telegram/MessageEntity.cpp, get_continuous_entities_mask().
_CONTINUOUS_ENTITIES_MASK = (
    _get_entity_type_mask(TYPE.MENTION)
    | _get_entity_type_mask(TYPE.HASHTAG)
    | _get_entity_type_mask(TYPE.BOT_COMMAND)
    | _get_entity_type_mask(TYPE.URL)
    | _get_entity_type_mask(TYPE.EMAIL_ADDRESS)
    | _get_entity_type_mask(TYPE.TEXT_URL)
    | _get_entity_type_mask(TYPE.MENTION_NAME)
    | _get_entity_type_mask(TYPE.CASHTAG)
    | _get_entity_type_mask(TYPE.PHONE_NUMBER)
    | _get_entity_type_mask(TYPE.BANK_CARD_NUMBER)
    | _get_entity_type_mask(TYPE.MEDIA_TIMESTAMP)
    | _get_entity_type_mask(TYPE.CUSTOM_EMOJI)
    | _get_entity_type_mask(TYPE.TON_ADDRESS)
)

# Ported from td/telegram/MessageEntity.cpp, get_pre_entities_mask().
_PRE_ENTITIES_MASK = (
    _get_entity_type_mask(TYPE.PRE)
    | _get_entity_type_mask(TYPE.CODE)
    | _get_entity_type_mask(TYPE.PRE_CODE)
    | _get_entity_type_mask(TYPE.FORMATTED_DATE)
)


# Ported from td/telegram/MessageEntity.cpp, is_splittable_entity().
def _is_splittable_entity(entity_type: int) -> bool:
    return (_get_entity_type_mask(entity_type) & _SPLITTABLE_ENTITIES_MASK) != 0


# Ported from td/telegram/MessageEntity.cpp, is_blockquote_entity().
def _is_blockquote_entity(entity_type: int) -> bool:
    return (_get_entity_type_mask(entity_type) & _BLOCKQUOTE_ENTITIES_MASK) != 0


# Ported from td/telegram/MessageEntity.cpp, is_continuous_entity().
def _is_continuous_entity(entity_type: int) -> bool:
    return (_get_entity_type_mask(entity_type) & _CONTINUOUS_ENTITIES_MASK) != 0


# Ported from td/telegram/MessageEntity.cpp, is_pre_entity().
def _is_pre_entity(entity_type: int) -> bool:
    return (_get_entity_type_mask(entity_type) & _PRE_ENTITIES_MASK) != 0


# Ported from td/telegram/MessageEntity.cpp, SPLITTABLE_ENTITY_TYPE_COUNT.
_SPLITTABLE_ENTITY_TYPE_COUNT = 5


# Ported from td/telegram/MessageEntity.cpp, get_splittable_entity_type_index().
def _get_splittable_entity_type_index(entity_type: int) -> int:
    if entity_type <= TYPE.BOLD + 1:  # Bold or Italic
        return entity_type - TYPE.BOLD
    if entity_type <= TYPE.UNDERLINE + 1:  # Underline or Strikethrough
        return entity_type - TYPE.UNDERLINE + 2
    return 4  # Spoiler


# Ported from td/telegram/MessageEntity.cpp, remove_intersecting_entities().
def _remove_intersecting_entities(
    entities: Iterable[MessageEntity],
) -> list[MessageEntity]:
    """Return the sorted `entities` that start no earlier than the last kept one ends.

    An entity nested in another counts as intersecting it.
    """
    last_entity_end = 0
    kept = []
    for entity in entities:
        if entity.offset >= last_entity_end:
            last_entity_end = entity.offset + entity.length
            kept.append(entity)
    return kept


# Ported from td/telegram/MessageEntity.cpp, flush_entities in split_entities(), the
# types it walks, in its order.
_SPLITTABLE_TYPES = (
    TYPE.BOLD,
    TYPE.ITALIC,
    TYPE.UNDERLINE,
    TYPE.STRIKETHROUGH,
    TYPE.SPOILER,
)

# Ported from td/telegram/MessageEntity.cpp, split_entities(), the offset it flushes at
# last, std::numeric_limits<int32>::max().
_INT32_MAX = (1 << 31) - 1


# Ported from td/telegram/MessageEntity.cpp, split_entities().
def _split_entities(
    entities: Sequence[MessageEntity], other_entities: Sequence[MessageEntity]
) -> tuple[MessageEntity, ...]:
    """Return the splittable `entities` merged where they meet, split by the others.

    Both lists must be sorted. Entities of one type that overlap or touch become one,
    each entity is cut where an entity of `other_entities` starts or ends, and the parts
    inside a pre entity are dropped.
    """
    begin_pos = [0] * _SPLITTABLE_ENTITY_TYPE_COUNT
    end_pos = [0] * _SPLITTABLE_ENTITY_TYPE_COUNT
    it = 0
    result: list[MessageEntity] = []

    def flush_entities(offset: int) -> None:
        for entity_type in _SPLITTABLE_TYPES:
            index = _get_splittable_entity_type_index(entity_type)
            if end_pos[index] != 0 and begin_pos[index] < offset:
                if end_pos[index] <= offset:
                    result.append(
                        MessageEntity(
                            entity_type,
                            begin_pos[index],
                            end_pos[index] - begin_pos[index],
                        )
                    )
                    begin_pos[index] = 0
                    end_pos[index] = 0
                else:
                    result.append(
                        MessageEntity(
                            entity_type, begin_pos[index], offset - begin_pos[index]
                        )
                    )
                    begin_pos[index] = offset

    def add_entities(end_offset: int) -> None:
        nonlocal it
        while it < len(entities):
            entity = entities[it]
            if entity.offset >= end_offset:
                break
            index = _get_splittable_entity_type_index(entity.type)
            if entity.offset <= end_pos[index] and end_pos[index] != 0:
                end_pos[index] = max(end_pos[index], entity.offset + entity.length)
            else:
                flush_entities(entity.offset)
                begin_pos[index] = entity.offset
                end_pos[index] = entity.offset + entity.length
            it += 1
        flush_entities(end_offset)

    nested_entities_stack: list[MessageEntity] = []

    def add_offset(offset: int) -> None:
        while nested_entities_stack and offset >= (
            nested_entities_stack[-1].offset + nested_entities_stack[-1].length
        ):
            old_size = len(result)
            add_entities(
                nested_entities_stack[-1].offset + nested_entities_stack[-1].length
            )
            if _is_pre_entity(nested_entities_stack[-1].type):
                del result[old_size:]
            nested_entities_stack.pop()
        add_entities(offset)

    for other_entity in other_entities:
        add_offset(other_entity.offset)
        nested_entities_stack.append(other_entity)
    add_offset(_INT32_MAX)

    # The entities are sorted only by offset now.
    return _sort_entities(result)
