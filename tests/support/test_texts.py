from collections.abc import Callable

import pytest

from tests.support.texts import (
    INVALID_UNITS,
    MARK_ENDINGS,
    PLAIN_UNITS,
    draw_texts,
    shrink,
    texts_around,
)

Fails = Callable[[list[tuple[bytes, ...]]], list[bool]]


def _fails_while_holding(*needles: bytes) -> Fails:
    def fails(candidates: list[tuple[bytes, ...]]) -> list[bool]:
        texts = [b"".join(candidate) for candidate in candidates]
        return [all(needle in text for needle in needles) for text in texts]

    return fails


def test_a_seed_draws_the_same_texts_each_time() -> None:
    assert draw_texts(7, 50, PLAIN_UNITS) == draw_texts(7, 50, PLAIN_UNITS)
    assert draw_texts(7, 50, PLAIN_UNITS) != draw_texts(8, 50, PLAIN_UNITS)


def test_drawn_texts_hold_only_the_given_units_up_to_the_given_count() -> None:
    texts = draw_texts(7, 500, INVALID_UNITS, max_units=12)
    assert len(texts) == 500
    assert all(len(text) <= 12 for text in texts)
    assert all(unit in INVALID_UNITS for text in texts for unit in text)


def test_every_plain_unit_is_one_character_in_utf8() -> None:
    assert all(len(unit.decode()) == 1 for unit in PLAIN_UNITS)


@pytest.mark.parametrize("unit", INVALID_UNITS)
def test_every_invalid_unit_is_refused_by_utf8(unit: bytes) -> None:
    with pytest.raises(UnicodeDecodeError):
        unit.decode()


def test_shrinking_keeps_only_the_units_the_failure_needs() -> None:
    mark = "\U0000200e".encode()
    text = (b"x", mark, b"y", b"z", "\U0000200f".encode(), b"x")
    assert shrink(text, _fails_while_holding(mark, b"z"), by_bytes=False) == (
        mark,
        b"z",
    )


def test_shrinking_by_bytes_splits_the_units_left() -> None:
    text = (b"ab", "\U0000200e".encode(), b"cd")
    assert shrink(text, _fails_while_holding(b"\x80"), by_bytes=True) == (b"\x80",)


def test_shrinking_keeps_a_text_that_nothing_shorter_fails() -> None:
    text = (b"a", b"b")
    assert shrink(text, _fails_while_holding(b"ab"), by_bytes=False) == text


def test_every_mark_ending_ends_with_a_left_to_right_or_a_right_to_left_mark() -> None:
    marks = ("\U0000200e".encode(), "\U0000200f".encode())
    assert all(text[-1] in marks for text in MARK_ENDINGS)


def test_texts_around_a_limit_end_each_unit_within_four_bytes_of_it() -> None:
    texts = texts_around(100, (b"x", "\U0001f600".encode()))
    ends = [len(text[0]) + len(text[1]) for text in texts]
    assert ends == [*range(96, 105), *range(96, 105)]
