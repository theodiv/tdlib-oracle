from collections.abc import Callable

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.links import check_link, get_checked_link, get_link_user_id
from tests.support.links import FIXED_LINKS, draw_links

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

Port = Callable[[bytes, tuple[int, ...]], tuple[bytes, ...]]


def _check_link(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    link = check_link(text)
    if isinstance(link, Failure):
        return (str(link.code).encode(), link.message.encode(), b"")
    return (b"0", b"", link)


def _get_checked_link(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    return (get_checked_link(text),)


def _get_link_user_id(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    return (str(get_link_user_id(text)).encode(),)


# Each function compared, by the name the harness gives it.
_FUNCTIONS: tuple[tuple[str, Port], ...] = (
    ("check_link", _check_link),
    ("get_checked_link", _get_checked_link),
    ("get_link_user_id", _get_link_user_id),
)


@pytest.mark.parametrize(
    ("function", "port"), _FUNCTIONS, ids=[f for f, _ in _FUNCTIONS]
)
def test_link_checks_give_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int, function: str, port: Port
) -> None:
    for seed in seeds:
        cases = [(link, ()) for link in draw_links(seed, count)]
        compare(function, port, cases, seed=seed, by_bytes=True)


@pytest.mark.parametrize(
    ("function", "port"), _FUNCTIONS, ids=[f for f, _ in _FUNCTIONS]
)
def test_link_checks_give_the_pinned_result_on_the_fixed_links(
    compare: Compare, function: str, port: Port
) -> None:
    cases = [(tuple(bytes([c]) for c in link), ()) for link in FIXED_LINKS]
    compare(function, port, cases, seed=None, by_bytes=True)
