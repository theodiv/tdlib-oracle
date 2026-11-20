# Ported from td/telegram/MessageEntity.h, td/telegram/MessageEntity.cpp, and
# td/telegram/UserId.h of TDLib at the commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's message entities: their types, user IDs, order, and the sort that keeps it.

The pinned code sorts entities with `std::sort`, which leaves the order of entities that
compare equal to the C++ library, so a server built with another library can keep
another entity of such a tie. The port sorts as `sorted()` does and records on its
entities each tie between entities that differ.
"""

from collections.abc import Sequence
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

# Ported from td/telegram/UserId.h, UserId::MAX_USER_ID.
_MAX_USER_ID = (1 << 40) - 1


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
def _order(entity: MessageEntity) -> tuple[int, int, int]:
    return entity.offset, -entity.length, _PRIORITIES[entity.type]


# Ported from td/telegram/MessageEntity.cpp, sort_entities().
def sort_entities(entities: Sequence[MessageEntity]) -> tuple[MessageEntity, ...]:
    """Return `entities` in TDLib's order, marking each tie of entities that differ.

    Entities already in order come back unchanged, since the pinned code sorts only
    entities out of order. Others come back sorted as `sorted()` sorts them, so entities
    that compare equal, with the same offset, length, and type priority, keep their
    input order; where they differ in type or value, each of them carries the whole tie
    in `ties`.
    """
    keys = [_order(entity) for entity in entities]
    if all(first <= second for first, second in pairwise(keys)):
        return tuple(entities)

    result: list[MessageEntity] = []
    for _, group in groupby(sorted(entities, key=_order), key=_order):
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


# Ported from td/telegram/UserId.h, UserId::is_valid().
def is_valid_user_id(user_id: int) -> bool:
    """Return whether `user_id` lies in the range of user IDs, from 1 to 2^40 - 1."""
    return 0 < user_id <= _MAX_USER_ID
