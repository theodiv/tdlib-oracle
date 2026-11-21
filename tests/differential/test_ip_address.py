from collections.abc import Callable

import pytest

from tdlib_oracle.tdutils.ip_address import init_ipv6_port
from tests.support.texts import draw_texts

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# Pieces of a host in brackets: brackets, addresses, NULs, at which the C string that
# inet_pton() reads ends, and characters no address holds.
_UNITS = (
    b"[",
    b"]",
    b"::1",
    b"1:2:3:4:5:6:7:8",
    b"::ffff:1.2.3.4",
    b"\x00",
    b":",
    b"1",
    b"g",
    b"x",
)

# Hosts that generated ones may miss: brackets alone, nested, on one side, around a NUL
# or after one, and an address cut by a NUL.
_FIXED_HOSTS = (
    b"",
    b"[]",
    b"[",
    b"]",
    b"[[::1]]",
    b"[::1",
    b"::1]",
    b"[\x00]",
    b"\x00::1",
    b"[::1\x00x]",
    b"::1\x00x",
)


def _check(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    return (b"1" if init_ipv6_port(text) else b"0",)


def test_init_ipv6_port_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in draw_texts(seed, count, _UNITS)]
        compare("init_ipv6_port", _check, cases, seed=seed, by_bytes=True)


def test_init_ipv6_port_gives_the_pinned_result_at_the_bounds(
    compare: Compare,
) -> None:
    cases = [(tuple(bytes([c]) for c in host), ()) for host in _FIXED_HOSTS]
    compare("init_ipv6_port", _check, cases, seed=None, by_bytes=True)
