import random
from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib.misc import (
    clean_input_string,
    is_empty_string,
    replace_offending_characters,
    strip_empty_characters,
)
from tests.support.texts import (
    INVALID_UNITS,
    MARK_ENDINGS,
    PLAIN_UNITS,
    draw_texts,
    texts_around,
)

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# Cleaning stops short of its 35,000-byte limit, at 34,996 bytes at most.
_CUT = 34_996

# Characters of each UTF-8 length, and characters that cleaning drops or replaces.
_CUT_UNITS = tuple(
    character.encode()
    for character in (
        "\U000000e9",
        "\U000020ac",
        "\U0001f600",
        "\r",
        "\U00002028",
        "\x01",
        "\U0000200e",
    )
)


def _clean(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    result = clean_input_string(text)
    return (b"0", b"") if result is None else (b"1", result)


def test_clean_input_string_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        texts = draw_texts(seed, count, PLAIN_UNITS + INVALID_UNITS)
        cases = [(text, ()) for text in texts]
        compare("clean_input_string", _clean, cases, seed=seed, by_bytes=True)


def test_clean_input_string_gives_the_pinned_result_for_a_mark_at_the_end(
    compare: Compare,
) -> None:
    cases = [(text, ()) for text in MARK_ENDINGS]
    compare("clean_input_string", _clean, cases, seed=None, by_bytes=True)


def test_clean_input_string_gives_the_pinned_result_around_its_cut(
    compare: Compare,
) -> None:
    cases = [(text, ()) for text in texts_around(_CUT, _CUT_UNITS)]
    compare("clean_input_string", _clean, cases, seed=None, by_bytes=False)


def test_replace_offending_characters_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        texts = draw_texts(seed, count, PLAIN_UNITS + INVALID_UNITS)
        compare(
            "replace_offending_characters",
            lambda text, args: (replace_offending_characters(text),),
            [(text, ()) for text in texts],
            seed=seed,
            by_bytes=True,
        )


def test_replace_offending_characters_gives_the_pinned_result_for_a_mark_at_the_end(
    compare: Compare,
) -> None:
    compare(
        "replace_offending_characters",
        lambda text, args: (replace_offending_characters(text),),
        [(text, ()) for text in MARK_ENDINGS],
        seed=None,
        by_bytes=True,
    )


def test_strip_empty_characters_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(f"{seed} arguments")
        cases = []
        for text in draw_texts(seed, count, PLAIN_UNITS):
            # PLAIN_UNITS are one character each, so a text's length is its unit count.
            length = len(text)
            max_length = rng.choice((0, 1, length - 1, length, length + 1, 10_000_000))
            cases.append((text, (max(max_length, 0), rng.randint(0, 1))))
        compare(
            "strip_empty_characters",
            lambda text, args: (strip_empty_characters(text, args[0], bool(args[1])),),
            cases,
            seed=seed,
            by_bytes=False,
        )


def test_is_empty_string_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in draw_texts(seed, count, PLAIN_UNITS)]
        compare(
            "is_empty_string",
            lambda text, args: (b"1" if is_empty_string(text) else b"0",),
            cases,
            seed=seed,
            by_bytes=False,
        )
