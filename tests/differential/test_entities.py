import random
from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib.entities import (
    TYPE,
    MessageEntity,
    is_valid_user_id,
    sort_entities,
)
from tests.support.entities import draw_entities

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# Twenty tied links: more than libstdc++'s insertion sort keeps in order.
_TIED_LINKS = tuple(
    MessageEntity(TYPE.TEXT_URL, 0, 1, str(index).encode()) for index in range(20)
)

# The largest user ID, and the largest number of either sign that the harness reads, at
# 18 digits.
_MAX_USER_ID = (1 << 40) - 1
_MAX_READ = 10**18 - 1

# User IDs drawn around each end of the valid range and across all the harness reads.
_USER_ID_BANDS = (
    (-100, 100),
    (_MAX_USER_ID - 100, _MAX_USER_ID + 100),
    (-_MAX_READ, _MAX_READ),
)

# User IDs at each end of the valid range and one past it, and the extremes the
# harness reads.
_USER_ID_EDGES = (
    -1,
    0,
    1,
    _MAX_USER_ID,
    _MAX_USER_ID + 1,
    -_MAX_USER_ID,
    _MAX_READ,
    -_MAX_READ,
)


def _sort(
    text: bytes, args: tuple[int, ...], entities: tuple[MessageEntity, ...]
) -> tuple[tuple[bytes, ...], tuple[MessageEntity, ...]]:
    return (), sort_entities(entities)


def _check_user_id(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    return (b"1" if is_valid_user_id(args[0]) else b"0",)


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


def test_is_valid_user_id_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        rng = random.Random(f"{seed} user IDs")
        cases = [
            ((), (rng.randint(*rng.choice(_USER_ID_BANDS)),)) for _ in range(count)
        ]
        compare("is_valid_user_id", _check_user_id, cases, seed=seed, by_bytes=False)


def test_is_valid_user_id_gives_the_pinned_result_at_the_edges(
    compare: Compare,
) -> None:
    cases = [((), (user_id,)) for user_id in _USER_ID_EDGES]
    compare("is_valid_user_id", _check_user_id, cases, seed=None, by_bytes=False)
