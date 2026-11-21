from collections.abc import Callable

import pytest

from tdlib_oracle.tdutils.algorithm import combine
from tests.support.texts import draw_texts

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# Elements, one byte each, and the `|` that ends the destination's, as in the harness.
_UNITS = (b"a", b"b", b"c", b"|")

# Lists of each length relation: the destination longer, shorter, as long, and either
# one empty.
_FIXED_TEXTS = (b"", b"|", b"ab|c", b"a|bc", b"ab|cd", b"abc", b"|abc", b"a|b|c")


def _combine(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    destination, _, source = text.partition(b"|")
    return (bytes(combine(list(destination), list(source))),)


def test_combine_gives_the_pinned_order(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in draw_texts(seed, count, _UNITS)]
        compare("combine", _combine, cases, seed=seed, by_bytes=True)


def test_combine_gives_the_pinned_order_for_each_length_relation(
    compare: Compare,
) -> None:
    cases = [(tuple(bytes([c]) for c in text), ()) for text in _FIXED_TEXTS]
    compare("combine", _combine, cases, seed=None, by_bytes=True)
