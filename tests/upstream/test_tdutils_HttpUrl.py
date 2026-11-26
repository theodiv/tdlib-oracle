# Ported from tdutils/test/HttpUrl.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdutils.http_url import HttpUrl, parse_url

# Ported from tdutils/test/HttpUrl.cpp, test_parse_url(), the queries that each of its
# overloads appends.
_QUERIES = (b"", b"/.com", b"#", b"?t=1")


# Ported from tdutils/test/HttpUrl.cpp,
# test_parse_url(const td::string &url, td::string userinfo, ...).
def _test_parse_url(
    url: bytes,
    userinfo: bytes,
    host: bytes,
    is_ipv6: bool,
    specified_port: int,
    port: int,
) -> None:
    for query in _QUERIES:
        http_url = parse_url(url + query)
        assert isinstance(http_url, HttpUrl), url + query
        assert http_url.userinfo == userinfo
        assert http_url.host == host
        assert http_url.is_ipv6 == is_ipv6
        assert http_url.specified_port == specified_port
        assert http_url.port == port


# Ported from tdutils/test/HttpUrl.cpp,
# test_parse_url(const td::string &url, td::Slice error_message).
def _test_parse_url_error(url: bytes, error_message: str) -> None:
    for query in _QUERIES:
        error = parse_url(url + query)
        assert isinstance(error, Failure), url + query
        assert error.message == error_message


# Ported from tdutils/test/HttpUrl.cpp, TEST(HttpUrl, parse_url).
def test_parse_url() -> None:
    _test_parse_url(b"http://localhost:8080", b"", b"localhost", False, 8080, 8080)
    _test_parse_url(b"http://lOcAlhOsT:8080", b"", b"localhost", False, 8080, 8080)
    _test_parse_url(
        b"http://UsEr:PaSs@lOcAlhOsT:8080",
        b"UsEr:PaSs",
        b"localhost",
        False,
        8080,
        8080,
    )
    _test_parse_url(b"http://example.com", b"", b"example.com", False, 0, 80)
    _test_parse_url(b"https://example.com", b"", b"example.com", False, 0, 443)
    _test_parse_url(
        b"https://example.com:65535", b"", b"example.com", False, 65535, 65535
    )
    _test_parse_url(b"https://example.com:00000071", b"", b"example.com", False, 71, 71)
    _test_parse_url(b"example.com?://", b"", b"example.com", False, 0, 80)
    _test_parse_url(b"example.com/://", b"", b"example.com", False, 0, 80)
    _test_parse_url(b"example.com#://", b"", b"example.com", False, 0, 80)
    _test_parse_url(b"@example.com#://", b"", b"example.com", False, 0, 80)
    _test_parse_url(b"test@example.com#://", b"test", b"example.com", False, 0, 80)
    _test_parse_url(
        b"test:pass@example.com#://", b"test:pass", b"example.com", False, 0, 80
    )
    _test_parse_url(
        b"te%ffst:pa%8Dss@examp%9Ele.com#://",
        b"te%ffst:pa%8Dss",
        b"examp%9ele.com",
        False,
        0,
        80,
    )
    _test_parse_url(
        b"http://[2001:db8:85a3:8d3:1319:8a2e:370:7348]",
        b"",
        b"[2001:db8:85a3:8d3:1319:8a2e:370:7348]",
        True,
        0,
        80,
    )
    _test_parse_url(
        b"https://test@[2001:db8:85a3:8d3:1319:8a2e:370:7348]:443/",
        b"test",
        b"[2001:db8:85a3:8d3:1319:8a2e:370:7348]",
        True,
        443,
        443,
    )
    _test_parse_url(
        b"http://[64:ff9b::255.255.255.255]",
        b"",
        b"[64:ff9b::255.255.255.255]",
        True,
        0,
        80,
    )
    _test_parse_url(b"http://255.255.255.255", b"", b"255.255.255.255", False, 0, 80)
    _test_parse_url(b"http://255.255.255.com", b"", b"255.255.255.com", False, 0, 80)
    _test_parse_url(b"https://exam%00ple.com", b"", b"exam%00ple.com", False, 0, 443)

    _test_parse_url_error(b"example.com://", "Unsupported URL protocol")
    _test_parse_url_error(
        b"https://example.com:65536", "Wrong port number specified in the URL"
    )
    _test_parse_url_error(
        b"https://example.com:0", "Wrong port number specified in the URL"
    )
    _test_parse_url_error(
        b"https://example.com:0x1", "Wrong port number specified in the URL"
    )
    _test_parse_url_error(
        b"https://example.com:", "Wrong port number specified in the URL"
    )
    _test_parse_url_error(
        b"https://example.com:-1", "Wrong port number specified in the URL"
    )
    _test_parse_url_error(b"example.com@://", "Wrong port number specified in the URL")
    _test_parse_url_error(b"example.com@:1//", "URL host is empty")
    _test_parse_url_error(b"example.com@.:1//", "Host is invalid")
    _test_parse_url_error(b"exam%0gple.com", "Wrong percent-encoded symbol in URL host")
    _test_parse_url_error(
        b"a%g0b@example.com", "Wrong percent-encoded symbol in URL userinfo"
    )

    for c in range(1, 256):
        if c == 0x25:  # '%'
            continue
        ch = bytes([c])
        if ch.isalnum() or c >= 128 or ch in b".-_!$,~*'();&+=":
            # allowed character
            _test_parse_url(
                ch + b"a@b" + ch, ch + b"a", b"b" + ch.lower(), False, 0, 80
            )
        elif ch == b":":
            # allowed in userinfo character
            _test_parse_url(ch + b"a@b" + ch + b"1", ch + b"a", b"b", False, 1, 1)
            _test_parse_url_error(
                ch + b"a@b" + ch, "Wrong port number specified in the URL"
            )
            _test_parse_url(ch + b"a@b", ch + b"a", b"b", False, 0, 80)
        elif ch in b"#?/":
            # special disallowed character
            _test_parse_url_error(ch + b"a@b" + ch, "URL host is empty")
        elif ch == b"@":
            # special disallowed character
            _test_parse_url_error(ch + b"a@b" + ch, "URL host is empty")
            _test_parse_url_error(
                ch + b"a@b" + ch + b"1", "Disallowed character in URL userinfo"
            )
        else:
            # generic disallowed character
            _test_parse_url_error(ch + b"a@b" + ch, "Disallowed character in URL host")
            _test_parse_url_error(b"a@b" + ch, "Disallowed character in URL host")
            _test_parse_url_error(ch + b"a@b", "Disallowed character in URL userinfo")
