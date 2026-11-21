import random
from collections.abc import Callable

import pytest

from tdlib_oracle.runtime.ipv6 import is_ipv6_address

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# Pieces of IPv6 text: groups of each length and case and one too long, separators, IPv4
# addresses and numbers at the octet bounds, and characters no address holds. No NUL,
# where the C string that inet_pton() reads would end, and no bracket, which
# IPAddress::init_ipv6_port() strips.
_UNITS = (
    b"0",
    b"1",
    b"9",
    b"a",
    b"f",
    b"F",
    b"00",
    b"0000",
    b"abcd",
    b"ffff",
    b"FFFF",
    b"12345",
    b":",
    b"::",
    b":::",
    b".",
    b"1.2.3.4",
    b"0.0.0.0",
    b"255.255.255.255",
    b"255",
    b"256",
    b"01",
    b"g",
    b"G",
    b"%",
    b"%0",
    b" ",
    b"-",
    b"\xc3\xa9",
    b"\xff",
)

# One address of each form, which mutations change a character at a time.
_ADDRESSES = (
    b"1:2:3:4:5:6:7:8",
    b"2001:db8:85a3:8d3:1319:8a2e:370:7348",
    b"::",
    b"::1",
    b"1::",
    b"1::8",
    b"1:2:3:4:5:6:7::",
    b"::2:3:4:5:6:7:8",
    b"1:2:3:4:5:6:1.2.3.4",
    b"::1.2.3.4",
    b"::ffff:255.255.255.255",
    b"1:2:3:4:5::1.2.3.4",
    b"ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255",
)

# The characters a mutation inserts or puts in place of another.
_EDITS = b"0159afF:.g%"

# Texts at the bounds that generated texts may miss: the longest address and one
# character more, the scope ID that Python's ipaddress accepts, and a bracket opened but
# not closed, which IPAddress::init_ipv6_port() keeps.
_FIXED_TEXTS = (
    b"ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255",
    b"ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.2550",
    b"ffff:ffff:ffff:ffff:ffff:fffff:255.255.255.255",
    b"::%0",
    b"[::1",
    b"",
)


def _check(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    return (b"1" if is_ipv6_address(text) else b"0",)


def _draw_texts(seed: int, count: int) -> list[tuple[bytes, ...]]:
    """Return `count` texts drawn from `seed`, each split into its units.

    Half are addresses of each form with up to three characters inserted, deleted, or
    replaced; the others join random units.
    """
    rng = random.Random(f"{seed} ipv6")
    texts = []
    for _ in range(count):
        if rng.random() < 0.5:
            text = bytearray(rng.choice(_ADDRESSES))
            for _ in range(rng.randint(0, 3)):
                pos = rng.randrange(len(text) + 1)
                match rng.randrange(3):
                    case 0:
                        text.insert(pos, rng.choice(_EDITS))
                    case 1:
                        del text[pos : pos + 1]
                    case _:
                        text[pos : pos + 1] = bytes([rng.choice(_EDITS)])
            texts.append(tuple(bytes([c]) for c in text))
        else:
            size = rng.randint(0, 12)
            texts.append(tuple(rng.choice(_UNITS) for _ in range(size)))
    return texts


def test_is_ipv6_address_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in _draw_texts(seed, count)]
        compare("init_ipv6_port", _check, cases, seed=seed, by_bytes=True)


def test_is_ipv6_address_gives_the_pinned_result_at_the_bounds(
    compare: Compare,
) -> None:
    cases = [(tuple(bytes([c]) for c in text), ()) for text in _FIXED_TEXTS]
    compare("init_ipv6_port", _check, cases, seed=None, by_bytes=True)
