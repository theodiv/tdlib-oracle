from collections.abc import Callable

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdutils.http_url import parse_url
from tests.support.links import FIXED_LINKS, draw_links

pytestmark = pytest.mark.differential

Compare = Callable[..., None]


def _parse_url(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    url = parse_url(text)
    if isinstance(url, Failure):
        return (b"0", str(url.code).encode(), url.message.encode())
    return (
        b"1",
        str(url.protocol).encode(),
        url.userinfo,
        url.host,
        b"1" if url.is_ipv6 else b"0",
        str(url.specified_port).encode(),
        str(url.port).encode(),
        url.query,
        url.get_url(),
    )


def test_parse_url_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(link, ()) for link in draw_links(seed, count)]
        compare("parse_url", _parse_url, cases, seed=seed, by_bytes=True)


def test_parse_url_gives_the_pinned_result_on_the_fixed_links(compare: Compare) -> None:
    cases = [(tuple(bytes([c]) for c in link), ()) for link in FIXED_LINKS]
    compare("parse_url", _parse_url, cases, seed=None, by_bytes=True)
