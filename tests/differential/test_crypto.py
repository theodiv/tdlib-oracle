import random
from collections.abc import Callable

import pytest

from tdlib_oracle.tdutils.crypto import crc16

pytestmark = pytest.mark.differential

Compare = Callable[..., None]


def _crc16(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    return (str(crc16(text)).encode(),)


def _draw_data(seed: int, count: int) -> list[tuple[bytes, ...]]:
    """Return `count` runs of up to 64 random bytes drawn from `seed`, a unit each."""
    rng = random.Random(f"{seed} crc16")
    return [
        tuple(bytes([rng.randrange(256)]) for _ in range(rng.randint(0, 64)))
        for _ in range(count)
    ]


def test_crc16_gives_the_pinned_checksum(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(data, ()) for data in _draw_data(seed, count)]
        compare("crc16", _crc16, cases, seed=seed, by_bytes=True)


def test_crc16_gives_the_pinned_checksum_of_nothing_and_of_each_byte(
    compare: Compare,
) -> None:
    cases = [((), ()), *(((bytes([c]),), ()) for c in range(256))]
    compare("crc16", _crc16, cases, seed=None, by_bytes=True)
