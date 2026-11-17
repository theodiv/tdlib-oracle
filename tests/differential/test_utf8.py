import random
from collections.abc import Callable
from pathlib import Path

import pytest

from tdlib_oracle.text.utf8 import (
    check_utf8,
    is_utf8_character_first_code_unit,
    utf8_length,
    utf8_truncate,
)
from tests.support.harness import run
from tests.support.texts import INVALID_UNITS, PLAIN_UNITS, draw_texts

pytestmark = pytest.mark.differential

_UNITS = PLAIN_UNITS + INVALID_UNITS

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
