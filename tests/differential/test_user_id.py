import random
from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib.user_id import is_valid_user_id

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

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


def _check_user_id(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    return (b"1" if is_valid_user_id(args[0]) else b"0",)


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
