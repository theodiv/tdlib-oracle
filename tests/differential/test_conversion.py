import itertools
import random
from collections.abc import Callable, Sequence
from dataclasses import replace

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api, telegram_api
from tdlib_oracle.tdlib.message_entity import (
    TYPE,
    MessageEntity,
    get_input_message_entities,
    get_message_entities,
    get_server_message_entities,
    get_text_entities_object,
    order,
)
from tdlib_oracle.tdlib.user_id import is_valid_user_id
from tests.support.entities import draw_entities
from tests.support.links import FIXED_LINKS, draw_links

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# The types of API objects that take no value.
_PLAIN_TYPES = (
    td_api.TextEntityTypeMention(),
    td_api.TextEntityTypeHashtag(),
    td_api.TextEntityTypeCashtag(),
    td_api.TextEntityTypeBotCommand(),
    td_api.TextEntityTypeUrl(),
    td_api.TextEntityTypeEmailAddress(),
    td_api.TextEntityTypePhoneNumber(),
    td_api.TextEntityTypeBankCardNumber(),
    td_api.TextEntityTypeTonAddress(),
    td_api.TextEntityTypeBold(),
    td_api.TextEntityTypeItalic(),
    td_api.TextEntityTypeUnderline(),
    td_api.TextEntityTypeStrikethrough(),
    td_api.TextEntityTypeSpoiler(),
    td_api.TextEntityTypeCode(),
    td_api.TextEntityTypePre(),
    td_api.TextEntityTypeBlockQuote(),
    td_api.TextEntityTypeExpandableBlockQuote(),
)

# The constructors of Telegram's API that the port reads back and that take no value.
_PLAIN_OBJECTS: tuple[Callable[[int, int], telegram_api.MessageEntity], ...] = (
    telegram_api.MessageEntityBold,
    telegram_api.MessageEntityItalic,
    telegram_api.MessageEntityUnderline,
    telegram_api.MessageEntityStrike,
    telegram_api.MessageEntitySpoiler,
    telegram_api.MessageEntityCode,
)

# Languages to keep, empty, cleaned, and not UTF-8.
_LANGUAGES = (
    b"python",
    b"python",
    b"",
    b"a\rb",
    b"a\x00b",
    "\U000000e9".encode(),
    b"\xff",
)

# Users a mention names: valid ones only, since the harness passes no user manager,
# which differs from a bot's on the others alone.
_USER_IDS = (1, 5, (1 << 40) - 1)

# Users a mention Telegram returns names: valid ones, and invalid ones on each side of
# the range of user IDs.
_RETURNED_USER_IDS = (5, 5, 1, (1 << 40) - 1, 0, -1, 1 << 40)

# Custom emoji IDs, valid and not, up to the 18 digits the harness reads.
_CUSTOM_EMOJI_IDS = (5, 5, 1, -1, 10**18 - 1, 0)

# Media timestamps on each side of zero, at the ends of a 32-bit integer.
_MEDIA_TIMESTAMPS = (0, 1, (1 << 31) - 1, -1, -(1 << 31))

# Unix times on each side of zero, at the ends of a 32-bit integer.
_UNIX_TIMES = (1_700_000_000, 1_700_000_000, 1, (1 << 31) - 1, 0, -1, -(1 << 31))

# Each precision of a part of a date, and none.
_PRECISIONS = (
    None,
    td_api.DateTimePartPrecisionNone(),
    td_api.DateTimePartPrecisionShort(),
    td_api.DateTimePartPrecisionLong(),
)

# Each formatting type of a date, with every precision of its parts.
_FORMATTING_TYPES: tuple[td_api.DateTimeFormattingType | None, ...] = (
    None,
    td_api.DateTimeFormattingTypeRelative(),
    *(
        td_api.DateTimeFormattingTypeAbsolute(time, date, show_day_of_week)
        for time in _PRECISIONS
        for date in _PRECISIONS
        for show_day_of_week in (False, True)
    ),
)

# Offsets and lengths of the API objects, which the conversion leaves unchecked: small
# ones, mostly, and the ends of a 32-bit integer.
_BOUNDS = (0, 1, 2, 3, 5, 8, 0, 1, 2, 3, 5, 8, -1, (1 << 31) - 1, -(1 << 31))

# The bound that fix_formatted_text() holds an offset and a length to before TDLib sends
# the entities.
_MAX_BOUND = 1_000_000

# More entities than TDLib sends besides custom emoji, the 100 of its limit and one.
_CAP = 101


def _draw_type(rng: random.Random, links: Sequence[bytes]) -> td_api.TextEntityType:
    match rng.randrange(7):
        case 0:
            return td_api.TextEntityTypePreCode(rng.choice(_LANGUAGES))
        case 1:
            return td_api.TextEntityTypeTextUrl(rng.choice(links))
        case 2:
            return td_api.TextEntityTypeMentionName(rng.choice(_USER_IDS))
        case 3:
            return td_api.TextEntityTypeCustomEmoji(rng.choice(_CUSTOM_EMOJI_IDS))
        case 4:
            return td_api.TextEntityTypeMediaTimestamp(rng.choice(_MEDIA_TIMESTAMPS))
        case 5:
            return td_api.TextEntityTypeDateTime(
                rng.choice(_UNIX_TIMES), rng.choice(_FORMATTING_TYPES)
            )
        case _:
            return rng.choice(_PLAIN_TYPES)


def _draw_text_entities(
    seed: int, count: int
) -> list[tuple[td_api.TextEntity | None, ...]]:
    """Return `count` lists of API objects of entities, drawn from `seed`.

    Each type draws values valid and invalid, links among them from
    `tests.support.links`, and now and then an object or its type is null. Half the
    lists hold two objects or fewer, so that a list refuses as a whole less often.
    """
    rng = random.Random(f"{seed} text entities")
    links = [b"".join(units) for units in draw_links(seed, 100)] + list(FIXED_LINKS)
    lists = []
    for _ in range(count):
        entities: list[td_api.TextEntity | None] = []
        for _ in range(rng.randint(0, 8 if rng.random() < 0.5 else 2)):
            roll = rng.random()
            if roll < 0.03:
                entities.append(None)
                continue
            entity_type = None if roll < 0.06 else _draw_type(rng, links)
            entities.append(
                td_api.TextEntity(rng.choice(_BOUNDS), rng.choice(_BOUNDS), entity_type)
            )
        lists.append(tuple(entities))
    return lists


def _formatted_date(
    parts: Sequence[bool], date: int, offset: int = 0, length: int = 1
) -> telegram_api.MessageEntityFormattedDate:
    relative, short_time, long_time, short_date, long_date, day_of_week = parts
    return telegram_api.MessageEntityFormattedDate(
        0,
        relative,
        short_time,
        long_time,
        short_date,
        long_date,
        day_of_week,
        offset,
        length,
        date,
    )


def _draw_returned_entity(
    rng: random.Random, links: Sequence[bytes]
) -> telegram_api.MessageEntity:
    offset = rng.choice(_BOUNDS)
    length = rng.choice(_BOUNDS)
    kind = rng.randrange(len(_PLAIN_OBJECTS) + 6)
    if kind < len(_PLAIN_OBJECTS):
        return _PLAIN_OBJECTS[kind](offset, length)
    match kind - len(_PLAIN_OBJECTS):
        case 0:
            return telegram_api.MessageEntityPre(offset, length, rng.choice(_LANGUAGES))
        case 1:
            return telegram_api.MessageEntityTextUrl(offset, length, rng.choice(links))
        case 2:
            user_id = rng.choice(_RETURNED_USER_IDS)
            return telegram_api.MessageEntityMentionName(offset, length, user_id)
        case 3:
            document_id = rng.choice(_CUSTOM_EMOJI_IDS)
            return telegram_api.MessageEntityCustomEmoji(offset, length, document_id)
        case 4:
            collapsed = rng.random() < 0.5
            return telegram_api.MessageEntityBlockquote(0, collapsed, offset, length)
        case _:
            parts = [rng.random() < 0.5 for _ in range(6)]
            return _formatted_date(parts, rng.choice(_UNIX_TIMES), offset, length)


def _draw_returned_entities(
    seed: int, count: int
) -> list[tuple[telegram_api.MessageEntity, ...]]:
    """Return `count` lists of the objects Telegram may return, drawn from `seed`.

    Every constructor the port reads back comes up, with values valid and invalid: links
    from `tests.support.links`, users on each side of the range of user IDs, dates on
    each side of zero with every set of flags, and languages and custom emoji of
    each kind.
    """
    rng = random.Random(f"{seed} returned entities")
    links = [b"".join(units) for units in draw_links(seed, 100)] + list(FIXED_LINKS)
    return [
        tuple(_draw_returned_entity(rng, links) for _ in range(rng.randint(0, 8)))
        for _ in range(count)
    ]


def _draw_entities_to_send(rng: random.Random) -> tuple[MessageEntity, ...]:
    """Return drawn entities as TDLib holds them when it sends them: sorted and bounded.

    A mention names a valid user, since a bot's user manager refuses the others before,
    and `UserManager::get_input_user_force()` aborts on them. A fifth of the lists hold
    more entities than TDLib sends.
    """
    entities = (
        replace(entity, user_id=5)
        if entity.type == TYPE.MENTION_NAME and not is_valid_user_id(entity.user_id)
        else entity
        for entity in draw_entities(rng, 10, max_count=250)
        if 0 <= entity.offset <= _MAX_BOUND and 0 < entity.length <= _MAX_BOUND
    )
    return tuple(sorted(entities, key=order))


def _get_text_entities_object(
    text: bytes, args: tuple[int, ...], entities: tuple[MessageEntity, ...]
) -> tuple[tuple[bytes, ...], tuple[td_api.TextEntity, ...]]:
    return (), get_text_entities_object(entities)


def _get_message_entities(
    text: bytes, args: tuple[int, ...], entities: tuple[td_api.TextEntity | None, ...]
) -> tuple[tuple[bytes, ...], tuple[MessageEntity, ...]]:
    result = get_message_entities(entities)
    if isinstance(result, Failure):
        return (str(result.code).encode(), result.message.encode()), ()
    return (b"0", b""), result


def _get_server_message_entities(
    text: bytes,
    args: tuple[int, ...],
    entities: tuple[telegram_api.MessageEntity, ...],
) -> tuple[tuple[bytes, ...], tuple[MessageEntity, ...]]:
    return (), get_server_message_entities(entities)


def _get_input_message_entities(
    text: bytes, args: tuple[int, ...], entities: tuple[MessageEntity, ...]
) -> tuple[tuple[bytes, ...], tuple[telegram_api.MessageEntity, ...]]:
    return (), get_input_message_entities(entities)


def test_get_text_entities_object_gives_the_pinned_objects(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(f"{seed} entities to convert")
        cases = [((), (), draw_entities(rng, 10)) for _ in range(count)]
        compare_entities(
            "get_text_entities_object",
            _get_text_entities_object,
            cases,
            seed=seed,
            by_bytes=False,
            answers="api",
        )


def test_get_message_entities_gives_the_pinned_entities(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [((), (), entities) for entities in _draw_text_entities(seed, count)]
        compare_entities(
            "get_message_entities",
            _get_message_entities,
            cases,
            seed=seed,
            by_bytes=False,
            requests="api",
        )


def test_get_message_entities_gives_the_pinned_entities_for_each_type_and_value(
    compare_entities: Compare,
) -> None:
    links = [*FIXED_LINKS, b"t.me/a", b"tg://user?id=5", b"tg://user?id=0", b"\xff"]
    types: list[td_api.TextEntityType] = [
        *_PLAIN_TYPES,
        *(td_api.TextEntityTypePreCode(language) for language in _LANGUAGES),
        *(td_api.TextEntityTypeTextUrl(link) for link in links),
        *(td_api.TextEntityTypeMentionName(user_id) for user_id in _USER_IDS),
        *(td_api.TextEntityTypeCustomEmoji(id_) for id_ in _CUSTOM_EMOJI_IDS),
        *(td_api.TextEntityTypeMediaTimestamp(t) for t in _MEDIA_TIMESTAMPS),
        *(
            td_api.TextEntityTypeDateTime(unix_time, formatting_type)
            for unix_time in _UNIX_TIMES
            for formatting_type in _FORMATTING_TYPES
        ),
    ]
    entities: list[tuple[td_api.TextEntity | None, ...]] = [
        (td_api.TextEntity(0, 1, entity_type),) for entity_type in types
    ]
    entities += [(None,), (td_api.TextEntity(0, 1, None),)]
    cases = [((), (), entity) for entity in entities]
    compare_entities(
        "get_message_entities",
        _get_message_entities,
        cases,
        seed=None,
        by_bytes=False,
        requests="api",
    )


def test_get_server_message_entities_gives_the_pinned_entities(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        drawn = _draw_returned_entities(seed, count)
        cases = [((), (), entities) for entities in drawn]
        compare_entities(
            "get_message_entities(telegram_api)",
            _get_server_message_entities,
            cases,
            seed=seed,
            by_bytes=False,
            requests="sent",
        )


def test_get_server_message_entities_gives_the_pinned_entities_for_each_object(
    compare_entities: Compare,
) -> None:
    links = [*FIXED_LINKS, b"t.me/a", b"tg://user?id=5", b"ftp://t.me", b"\xff", b""]
    objects: list[telegram_api.MessageEntity] = [
        *(constructor(0, 1) for constructor in _PLAIN_OBJECTS),
        *(telegram_api.MessageEntityPre(0, 1, language) for language in _LANGUAGES),
        *(telegram_api.MessageEntityTextUrl(0, 1, link) for link in links),
        *(
            telegram_api.MessageEntityMentionName(0, 1, user_id)
            for user_id in _RETURNED_USER_IDS
        ),
        *(
            telegram_api.MessageEntityCustomEmoji(0, 1, document_id)
            for document_id in _CUSTOM_EMOJI_IDS
        ),
        telegram_api.MessageEntityBlockquote(0, False, 0, 1),
        telegram_api.MessageEntityBlockquote(0, True, 0, 1),
        *(
            _formatted_date(parts, date)
            for parts in itertools.product((False, True), repeat=6)
            for date in (1_700_000_000, 1, 0, -1)
        ),
    ]
    cases = [((), (), (entity,)) for entity in objects]
    compare_entities(
        "get_message_entities(telegram_api)",
        _get_server_message_entities,
        cases,
        seed=None,
        by_bytes=False,
        requests="sent",
    )


def test_get_input_message_entities_gives_the_pinned_entities(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(f"{seed} entities to send")
        cases = [((), (), _draw_entities_to_send(rng)) for _ in range(count)]
        compare_entities(
            "get_input_message_entities",
            _get_input_message_entities,
            cases,
            seed=seed,
            by_bytes=False,
            answers="sent",
        )


def test_get_input_message_entities_gives_the_pinned_entities_past_the_limit(
    compare_entities: Compare,
) -> None:
    codes = [MessageEntity(TYPE.CODE, 2 * index, 1) for index in range(_CAP)]
    custom_emoji = [
        MessageEntity(TYPE.CUSTOM_EMOJI, 2 * index + 1, 1, custom_emoji_id=index + 1)
        for index in range(_CAP)
    ]
    bold = [MessageEntity(TYPE.BOLD, 2 * index, 2) for index in range(_CAP)]
    lists = (
        codes,
        sorted(codes[:-2] + bold[-5:], key=order),
        sorted(codes + custom_emoji, key=order),
        sorted(bold[::2] + custom_emoji, key=order),
    )
    cases = [((), (), tuple(entities)) for entities in lists]
    compare_entities(
        "get_input_message_entities",
        _get_input_message_entities,
        cases,
        seed=None,
        by_bytes=False,
        answers="sent",
    )
