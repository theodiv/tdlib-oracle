import random
from collections.abc import Callable

import pytest

from tdlib_oracle.tdutils.parser import read_till_nofail
from tests.support.texts import draw_texts

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# The characters that parse_url() reads till, by the index the harness gives each.
_CHARACTER_SETS = (b":/?#@[]", b"/?#")

# Each character of either set; a NUL, which a C string would end at; letters; and
# bytes past ASCII.
_UNITS = (*(bytes([c]) for c in b":/?#@[]"), b"\x00", b"a", b"ab", b"\xc3\xa9", b"\xff")


def _read(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    character_set, pos = args
    # A position past the end stands for the end, as in the harness.
    begin, end = read_till_nofail(
        text, min(pos, len(text)), _CHARACTER_SETS[character_set]
    )
    return (str(begin).encode(), str(end).encode())


def _cases(seed: int, count: int) -> list[tuple[tuple[bytes, ...], tuple[int, ...]]]:
    """Return `count` texts drawn from `seed`, each with a set and a position."""
    rng = random.Random(f"{seed} parser")
    cases: list[tuple[tuple[bytes, ...], tuple[int, ...]]] = []
    for text in draw_texts(seed, count, _UNITS):
        pos = rng.randrange(len(b"".join(text)) + 2)
        cases.append((text, (rng.randrange(len(_CHARACTER_SETS)), pos)))
    return cases


def test_read_till_nofail_gives_the_pinned_span(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = _cases(seed, count)
        compare("read_till_nofail", _read, cases, seed=seed, by_bytes=True)


def test_read_till_nofail_gives_the_pinned_span_of_an_empty_text(
    compare: Compare,
) -> None:
    cases = [((), (character_set, 0)) for character_set in range(2)]
    compare("read_till_nofail", _read, cases, seed=None, by_bytes=True)
