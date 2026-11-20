import itertools
import random
from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib.entities import TYPE, MessageEntity
from tdlib_oracle.tdlib.fixing import find_entities, fix_formatted_text
from tdlib_oracle.text.failure import Failure
from tests.support.entities import draw_entities
from tests.support.texts import (
    FINDING_UNITS,
    INVALID_UNITS,
    MARK_ENDINGS,
    PLAIN_UNITS,
    draw_texts,
    texts_around,
)

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# The flags, in the order the harness takes them: allow_empty, allow_empty_string,
# skip_new_entities, skip_bot_commands, and skip_trim.
Flags = tuple[int, int, int, int, int]

# skip_new_entities and skip_bot_commands: entities found, found but bot commands, and
# none found, which makes skip_bot_commands no matter.
_FINDING = ((0, 0), (0, 1), (1, 1))

# allow_empty, allow_empty_string, and skip_trim, in every combination, with each way
# of finding entities.
_FLAGS: tuple[Flags, ...] = tuple(
    (allow_empty, allow_empty_string, skip_new_entities, skip_bot_commands, skip_trim)
    for allow_empty, allow_empty_string, skip_trim in itertools.product(
        (0, 1), repeat=3
    )
    for skip_new_entities, skip_bot_commands in _FINDING
)

# Cleaning stops short of its 35,000-byte limit, at 34,996 bytes at most.
_CUT = 34_996

# With entities, cleaning cuts nothing, and the text is cut at 35,000 bytes.
_ENTITY_CUT = 35_000

# Characters that trimming and the emptiness checks treat apart, to land on each side of
# the cut.
_CUT_UNITS = tuple(
    character.encode() for character in (" ", "\n", "\U0000200b", "\U0001f600")
)


def _fix_with_entities(
    text: bytes, args: tuple[int, ...], entities: tuple[MessageEntity, ...]
) -> tuple[tuple[bytes, ...], tuple[MessageEntity, ...]]:
    allow_empty, allow_empty_string, skip_new_entities, skip_bot_commands, skip_trim = (
        bool(arg) for arg in args
    )
    result = fix_formatted_text(
        text,
        entities,
        allow_empty=allow_empty,
        allow_empty_string=allow_empty_string,
        skip_new_entities=skip_new_entities,
        skip_bot_commands=skip_bot_commands,
        skip_trim=skip_trim,
    )
    if isinstance(result, Failure):
        return (str(result.code).encode(), result.message.encode(), b""), ()
    return (b"0", b"", result.text), result.entities


def _find(
    text: bytes, args: tuple[int, ...], entities: tuple[MessageEntity, ...]
) -> tuple[tuple[bytes, ...], tuple[MessageEntity, ...]]:
    return (), find_entities(text, skip_bot_commands=bool(args[0]))


def _draw_flags(rng: random.Random) -> Flags:
    skip_new_entities, skip_bot_commands = rng.choice(_FINDING)
    allow_empty, allow_empty_string, skip_trim = (rng.randint(0, 1) for _ in range(3))
    return (
        allow_empty,
        allow_empty_string,
        skip_new_entities,
        skip_bot_commands,
        skip_trim,
    )


def _combinations(finding: tuple[int, int]) -> list[Flags]:
    """Return allow_empty, allow_empty_string, and skip_trim in every combination.

    The one way of finding entities in `finding` goes with each, so that a text takes
    no more requests than its other flags need.
    """
    return [flags for flags in _FLAGS if (flags[2], flags[3]) == finding]


def _utf16_length(text: bytes) -> int:
    return len(text.decode().encode("utf-16-le")) // 2


def test_fix_formatted_text_gives_the_pinned_result(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(f"{seed} flags")
        texts = draw_texts(seed, count, PLAIN_UNITS + INVALID_UNITS)
        cases = [
            (text, flags, ())
            for text in texts
            for flags in _combinations(rng.choice(_FINDING))
        ]
        compare_entities(
            "fix_formatted_text", _fix_with_entities, cases, seed=seed, by_bytes=True
        )


def test_fix_formatted_text_gives_the_pinned_result_for_entities_to_find(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(f"{seed} flags")
        texts = draw_texts(seed, count, FINDING_UNITS)
        cases = [(text, _draw_flags(rng), ()) for text in texts]
        compare_entities(
            "fix_formatted_text", _fix_with_entities, cases, seed=seed, by_bytes=False
        )


def test_fix_formatted_text_gives_the_pinned_result_for_a_mark_at_the_end(
    compare_entities: Compare,
) -> None:
    cases = [(text, flags, ()) for text in MARK_ENDINGS for flags in _FLAGS]
    compare_entities(
        "fix_formatted_text", _fix_with_entities, cases, seed=None, by_bytes=True
    )


def test_fix_formatted_text_gives_the_pinned_result_around_the_cut(
    compare_entities: Compare,
) -> None:
    # Each text takes one way of finding entities, in turn, since a text of 35,000
    # bytes takes long in the port.
    texts = texts_around(_CUT, _CUT_UNITS)
    cases = [
        (text, flags, ())
        for index, text in enumerate(texts)
        for flags in _combinations(_FINDING[index % len(_FINDING)])
    ]
    compare_entities(
        "fix_formatted_text", _fix_with_entities, cases, seed=None, by_bytes=False
    )


def test_fix_formatted_text_gives_the_pinned_result_with_entities(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(f"{seed} entities")
        cases = []
        for units in draw_texts(seed, count, PLAIN_UNITS):
            entities = draw_entities(rng, _utf16_length(b"".join(units)))
            cases.append((units, _draw_flags(rng), entities))
        compare_entities(
            "fix_formatted_text", _fix_with_entities, cases, seed=seed, by_bytes=False
        )


def test_fix_formatted_text_gives_the_pinned_result_with_entities_to_find(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(f"{seed} entities")
        cases = []
        for units in draw_texts(seed, count, FINDING_UNITS):
            entities = draw_entities(rng, _utf16_length(b"".join(units)))
            cases.append((units, _draw_flags(rng), entities))
        compare_entities(
            "fix_formatted_text", _fix_with_entities, cases, seed=seed, by_bytes=False
        )


def test_fix_formatted_text_gives_the_pinned_result_for_invalid_utf8_with_entities(
    compare_entities: Compare,
) -> None:
    entities = (MessageEntity(TYPE.BOLD, 0, 1),)
    cases = [
        ((b"a", unit), flags, entities) for unit in INVALID_UNITS for flags in _FLAGS
    ]
    compare_entities(
        "fix_formatted_text", _fix_with_entities, cases, seed=None, by_bytes=True
    )


def _entities_around_the_cut(
    units: tuple[bytes, ...],
) -> tuple[tuple[MessageEntity, ...], ...]:
    length = _utf16_length(b"".join(units))
    across = (
        MessageEntity(TYPE.BOLD, 0, length),
        MessageEntity(TYPE.ITALIC, length - 8, 2),
        MessageEntity(TYPE.TEXT_URL, length - 5, 3, b"t.me"),
    )
    before = (MessageEntity(TYPE.ITALIC, 0, 2),)
    return across, before


def test_fix_formatted_text_gives_the_pinned_result_around_the_cut_with_entities(
    compare_entities: Compare,
) -> None:
    # Each text takes one way of finding entities, in turn, as around cleaning's cut.
    cases = [
        (units, flags, entities)
        for index, units in enumerate(texts_around(_ENTITY_CUT, _CUT_UNITS))
        for entities in _entities_around_the_cut(units)
        for flags in _combinations(_FINDING[index % len(_FINDING)])
    ]
    compare_entities(
        "fix_formatted_text", _fix_with_entities, cases, seed=None, by_bytes=False
    )


def test_find_entities_gives_the_pinned_entities(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(f"{seed} flags")
        cases = [
            (text, (rng.randint(0, 1),), ())
            for text in draw_texts(seed, count, FINDING_UNITS)
        ]
        compare_entities("find_entities", _find, cases, seed=seed, by_bytes=False)
