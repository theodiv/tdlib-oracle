# Ported from test/link.cpp of TDLib at the commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.

from tdlib_oracle.tdlib.finding import find_tg_urls, find_urls
from tdlib_oracle.tdlib.links import check_link
from tdlib_oracle.text.failure import Failure


# Ported from test/link.cpp, check_find_urls().
def _check_find_urls(url: bytes, is_valid: bool) -> None:
    url_lower = url.lower()
    tg_urls = [url[begin:end] for begin, end in find_tg_urls(url)]
    if is_valid and url_lower.startswith((b"tg://", b"ton://")):
        assert tg_urls == [url]
    else:
        assert not tg_urls or tg_urls[0] != url

    if (
        is_valid
        and url_lower.startswith((b"http", b"t.me"))
        and b"." in url
        and b" " not in url
        and url != b"http://.."
        and b"ra.ph" not in url
        and b"Aph" not in url
    ):
        urls = [url[begin:end] for (begin, end), _ in find_urls(url)]
        assert urls == [url]


# Ported from test/link.cpp, check_link().
def _check_link(url: bytes, expected: bytes) -> None:
    result = check_link(url)
    if isinstance(result, Failure):
        assert not expected, url
    else:
        assert result == expected, url

    _check_find_urls(url, not isinstance(result, Failure))


# Ported from test/link.cpp, TEST(Link, check_link).
def test_check_link() -> None:
    _check_link(b"sftp://google.com", b"")
    _check_link(b"tg://google_com", b"tg://google_com/")
    _check_link(b"tOn://google", b"ton://google/")
    _check_link(b"httP://google.com?1#tes", b"http://google.com/?1#tes")
    _check_link(b"httPs://google.com/?1#tes", b"https://google.com/?1#tes")
    _check_link(b"http://google.com:0", b"")
    _check_link(b"http://google.com:0000000001", b"http://google.com:1/")
    _check_link(b"http://google.com:-1", b"")
    _check_link(b"tg://google?1#tes", b"tg://google?1#tes")
    _check_link(b"tg://google/?1#tes", b"tg://google?1#tes")
    _check_link(b"TG:_", b"tg://_/")
    _check_link(b"sftp://google.com", b"")
    _check_link(b"sftp://google.com", b"")
    _check_link(b"http:google.com", b"")
    _check_link(b"tg://http://google.com", b"")
    _check_link(b"tg:http://google.com", b"")
    _check_link(b"tg:https://google.com", b"")
    _check_link(b"tg:test@google.com", b"")
    _check_link(b"tg:google.com:80", b"")
    _check_link(b"tg:google-com", b"tg://google-com/")
    _check_link(b"tg:google.com", b"")
    _check_link(b"tg:google.com:0", b"")
    _check_link(b"tg:google.com:a", b"")
    _check_link(b"tg:[2001:db8:0:0:0:ff00:42:8329]", b"")
    _check_link(b"tg:127.0.0.1", b"")
    _check_link(
        b"http://[2001:db8:0:0:0:ff00:42:8329]",
        b"http://[2001:db8:0:0:0:ff00:42:8329]/",
    )
    _check_link(b"http://localhost", b"")
    _check_link(b"http://..", b"http://../")
    _check_link(b"..", b"http://../")
    _check_link(b"https://.", b"")
    _check_link(b"tOnSiTe://google", b"tonsite://google/")
    _check_link(b"tOnSiTe://google.ton?t=1#we", b"tonsite://google.ton?t=1#we")
