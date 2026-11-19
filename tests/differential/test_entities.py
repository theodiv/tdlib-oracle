import random
from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib.entities import TYPE, MessageEntity, sort_entities
from tests.support.entities import draw_entities

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# Twenty tied links: more than libstdc++'s insertion sort keeps in order.
_TIED_LINKS = tuple(
    MessageEntity(TYPE.TEXT_URL, 0, 1, str(index).encode()) for index in range(20)
)


def _sort(
    text: bytes, args: tuple[int, ...], entities: tuple[MessageEntity, ...]
) -> tuple[tuple[bytes, ...], tuple[MessageEntity, ...]]:
    return (), sort_entities(entities)


def test_sort_entities_gives_the_pinned_order(
    compare_entities: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(seed)
        cases = [((), (), draw_entities(rng, 10)) for _ in range(count)]
        compare_entities("sort_entities", _sort, cases, seed=seed, by_bytes=False)


def test_sort_entities_gives_the_pinned_order_for_ties_already_in_order(
    compare_entities: Compare,
) -> None:
    cases = [((), (), _TIED_LINKS)]
    compare_entities("sort_entities", _sort, cases, seed=None, by_bytes=False)


def test_sort_entities_gives_the_pinned_order_for_ties_it_sorts(
    compare_entities: Compare,
) -> None:
    cases = [((), (), (MessageEntity(TYPE.BOLD, 1, 1), *_TIED_LINKS))]
    compare_entities("sort_entities", _sort, cases, seed=None, by_bytes=False)
