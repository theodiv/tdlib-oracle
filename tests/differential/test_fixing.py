import itertools
from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib.fixing import fix_formatted_text
from tdlib_oracle.text.failure import Failure
from tests.support.texts import (
    INVALID_UNITS,
    MARK_ENDINGS,
    PLAIN_UNITS,
    draw_texts,
    texts_around,
)

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# allow_empty, allow_empty_string, and skip_trim, in every combination.
_FLAGS = tuple(itertools.product((0, 1), repeat=3))

# Cleaning stops short of its 35,000-byte limit, at 34,996 bytes at most.
_CUT = 34_996

# Characters that trimming and the emptiness checks treat apart, to land on each side of
# the cut.
_CUT_UNITS = tuple(
    character.encode() for character in (" ", "\n", "\U0000200b", "\U0001f600")
)


def _fix(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    allow_empty, allow_empty_string, skip_trim = (bool(arg) for arg in args)
    result = fix_formatted_text(
        text,
        allow_empty=allow_empty,
        allow_empty_string=allow_empty_string,
        skip_trim=skip_trim,
    )
    if isinstance(result, Failure):
        return (str(result.code).encode(), result.message.encode(), b"")
    return (b"0", b"", result)


def test_fix_formatted_text_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        texts = draw_texts(seed, count, PLAIN_UNITS + INVALID_UNITS)
        cases = [(text, flags) for text in texts for flags in _FLAGS]
        compare("fix_formatted_text", _fix, cases, seed=seed, by_bytes=True)


def test_fix_formatted_text_gives_the_pinned_result_for_a_mark_at_the_end(
    compare: Compare,
) -> None:
    cases = [(text, flags) for text in MARK_ENDINGS for flags in _FLAGS]
    compare("fix_formatted_text", _fix, cases, seed=None, by_bytes=True)


def test_fix_formatted_text_gives_the_pinned_result_around_the_cut(
    compare: Compare,
) -> None:
    texts = texts_around(_CUT, _CUT_UNITS)
    cases = [(text, flags) for text in texts for flags in _FLAGS]
    compare("fix_formatted_text", _fix, cases, seed=None, by_bytes=False)
