import random
from collections.abc import Callable
from pathlib import Path

import pytest

from tdlib_oracle.text.utf8 import (
    check_utf8,
    is_utf8_character_first_code_unit,
    next_utf8_unsafe,
    prev_utf8_unsafe,
    utf8_length,
    utf8_substr,
    utf8_to_lower,
    utf8_truncate,
    utf8_utf16_length,
)
from tests.support.harness import run
from tests.support.texts import INVALID_UNITS, PLAIN_UNITS, draw_texts

pytestmark = pytest.mark.differential

_UNITS = PLAIN_UNITS + INVALID_UNITS

# Capital letters of each UTF-8 length, among them ones whose lowercase forms have
# another length, and characters that have no lowercase form.
_CASE_UNITS = PLAIN_UNITS + tuple(
    character.encode()
    for character in (
        "A",
        "\U000000c4",  # capital A with diaeresis
        "\U00000130",  # capital I with dot above, whose lowercase form is ASCII
        "\U00000410",  # Cyrillic capital A
        "\U00001e9e",  # capital sharp s, whose lowercase form takes 2 bytes
        "\U00002126",  # ohm sign
        "\U00002c62",  # capital L with middle tilde, whose lowercase form takes 2 bytes
        "\U0000ff21",  # fullwidth capital A
        "\U00010400",  # Deseret capital long I
        "\U0001e900",  # Adlam capital alif
    )
)

# Generous enough for a build with --coverage or the sanitizers.
_TIMEOUT = 300.0

Compare = Callable[..., None]


def _flag(value: bool) -> tuple[bytes, ...]:
    return (b"1" if value else b"0",)


def test_check_utf8_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in draw_texts(seed, count, _UNITS)]
        compare(
            "check_utf8",
            lambda text, args: _flag(check_utf8(text)),
            cases,
            seed=seed,
            by_bytes=True,
        )


def test_utf8_length_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in draw_texts(seed, count, _UNITS)]
        compare(
            "utf8_length",
            lambda text, args: (str(utf8_length(text)).encode(),),
            cases,
            seed=seed,
            by_bytes=True,
        )


def test_utf8_utf16_length_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in draw_texts(seed, count, _UNITS)]
        compare(
            "utf8_utf16_length",
            lambda text, args: (str(utf8_utf16_length(text)).encode(),),
            cases,
            seed=seed,
            by_bytes=True,
        )


def test_utf8_truncate_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(f"{seed} arguments")
        cases = [
            (text, (rng.randint(0, len(b"".join(text)) + 2),))
            for text in draw_texts(seed, count, _UNITS)
        ]
        compare(
            "utf8_truncate",
            lambda text, args: (utf8_truncate(text, args[0]),),
            cases,
            seed=seed,
            by_bytes=True,
        )


def test_is_utf8_character_first_code_unit_gives_the_pinned_result_for_each_byte(
    harness: Path,
) -> None:
    pinned = run(
        harness,
        "is_utf8_character_first_code_unit",
        [[bytes([byte])] for byte in range(256)],
        timeout=60,
    )
    assert pinned == [_flag(is_utf8_character_first_code_unit(c)) for c in range(256)]


def test_next_utf8_unsafe_gives_the_pinned_result_at_each_character(
    harness: Path, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        requests = []
        for units in draw_texts(seed, count, PLAIN_UNITS):
            text = b"".join(units)
            # Each character's start, and the end of the text, where the C++ reads the
            # string terminator.
            for pos in range(len(text) + 1):
                if pos == len(text) or is_utf8_character_first_code_unit(text[pos]):
                    requests.append((text, pos))
        pinned = run(
            harness,
            "next_utf8_unsafe",
            [[text, str(pos).encode()] for text, pos in requests],
            timeout=_TIMEOUT,
        )
        for (text, pos), theirs in zip(requests, pinned, strict=True):
            ours = tuple(str(value).encode() for value in next_utf8_unsafe(text, pos))
            assert ours == theirs, (
                f"next_utf8_unsafe differs on seed {seed}, at {pos} of {text!r}: the"
                f" port gives {ours!r}, the pinned code {theirs!r}"
            )


def test_prev_utf8_unsafe_gives_the_pinned_result_after_each_character(
    harness: Path, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        requests = []
        for units in draw_texts(seed, count, PLAIN_UNITS):
            text = b"".join(units)
            # The start of each character after the first, and the end of the text.
            for pos in range(1, len(text) + 1):
                if pos == len(text) or is_utf8_character_first_code_unit(text[pos]):
                    requests.append((text, pos))
        pinned = run(
            harness,
            "prev_utf8_unsafe",
            [[text, str(pos).encode()] for text, pos in requests],
            timeout=_TIMEOUT,
        )
        for (text, pos), theirs in zip(requests, pinned, strict=True):
            ours = (str(prev_utf8_unsafe(text, pos)).encode(),)
            assert ours == theirs, (
                f"prev_utf8_unsafe differs on seed {seed}, at {pos} of {text!r}: the"
                f" port gives {ours!r}, the pinned code {theirs!r}"
            )


def test_utf8_substr_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(f"{seed} arguments")
        cases = [
            (text, (rng.randint(0, len(text) + 2),))
            for text in draw_texts(seed, count, _UNITS)
        ]
        compare(
            "utf8_substr",
            lambda text, args: (utf8_substr(text, args[0]),),
            cases,
            seed=seed,
            by_bytes=True,
        )


def test_utf8_to_lower_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in draw_texts(seed, count, _CASE_UNITS)]
        compare(
            "utf8_to_lower",
            lambda text, args: (utf8_to_lower(text),),
            cases,
            seed=seed,
            by_bytes=False,
        )
