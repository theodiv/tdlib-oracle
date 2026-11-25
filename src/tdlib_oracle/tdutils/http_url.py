# Ported from tdutils/td/utils/HttpUrl.cpp and tdutils/td/utils/HttpUrl.h of TDLib at
# the commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""The URL parser of tdutils: a URL's parts, checked, and the URL they write back.

TDLib's HTML and MarkdownV2 parsers check the text inside each nested link again, so
`parse_url` passes over a URL a fixed number of times in bytes methods and regular
expressions; a Python loop reads 20 of its bytes at most.
"""

import re
from dataclasses import dataclass
from typing import Final

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdutils.ip_address import init_ipv6_port
from tdlib_oracle.tdutils.misc import is_space, to_integer_safe
from tdlib_oracle.tdutils.parser import read_till_nofail

# Ported from tdutils/td/utils/HttpUrl.cpp, parse_url(), the characters its calls of
# is_space() accept, for the bytes method that strips them all at once.
_SPACES = bytes(c for c in range(256) if is_space(c))

# Ported from tdutils/td/utils/HttpUrl.cpp, check_url_part in parse_url(), the first
# character it refuses in a host: a `%` without two hex digits after it, or a character
# outside the symbols RFC 7230 and RFC 3986 allow, UTF-8 bytes aside. The byte past the
# end is the string terminator, no hex digit.
_REFUSED_IN_HOST = re.compile(
    rb"%(?![0-9A-Fa-f]{2})|[^%0-9A-Za-z.\-_!$,~*'();&+=\x80-\xff]"
)

# Ported from tdutils/td/utils/HttpUrl.cpp, check_url_part in parse_url(), the first
# character it refuses in a userinfo, which may also hold colons. The byte past the end
# is the `@` after the userinfo, no hex digit either.
_REFUSED_IN_USERINFO = re.compile(
    rb"%(?![0-9A-Fa-f]{2})|[^%0-9A-Za-z.\-_!$,~*'();&+=:\x80-\xff]"
)

# Ported from tdutils/td/utils/HttpUrl.cpp, parse_url(), the bytes up to 0x20 it
# percent-encodes in a query.
_UNSAFE_IN_QUERY = re.compile(rb"[\x00-\x20]")

# Ported from tdutils/td/utils/HttpUrl.cpp, parse_url(), the characters it allows in an
# IPv6 host, between its brackets and in lowercase.
_IPV6_HOST_CHARACTERS = b":.0123456789abcdef"


# Ported from tdutils/td/utils/HttpUrl.h, HttpUrl::Protocol.
class PROTOCOL:
    """The protocols of a URL, numbered as tdutils numbers them."""

    HTTP: Final = 0
    HTTPS: Final = 1


# Ported from tdutils/td/utils/HttpUrl.h, HttpUrl.
@dataclass(frozen=True)
class HttpUrl:
    """A URL as tdutils parses it.

    Attributes:
        protocol: The protocol, one of `PROTOCOL`.
        userinfo: The user information before the host, as the URL writes it.
        host: The host in lowercase; an IPv6 address keeps its brackets.
        is_ipv6: Whether the host is an IPv6 address.
        specified_port: The port the URL names, or `0` when it names none.
        port: The port the URL names, or else the default port of `protocol`.
        query: The path, query, and fragment, from a leading `/`, with each byte up to
            0x20 percent-encoded.
    """

    protocol: int
    userinfo: bytes
    host: bytes
    is_ipv6: bool
    specified_port: int
    port: int
    query: bytes

    # Ported from tdutils/td/utils/HttpUrl.cpp, HttpUrl::get_url().
    def get_url(self) -> bytes:
        """Return the URL written back from its parts, as TDLib keeps it."""
        scheme = b"https://" if self.protocol == PROTOCOL.HTTPS else b"http://"
        userinfo = self.userinfo + b"@" if self.userinfo else b""
        port = b":%d" % self.specified_port if self.specified_port > 0 else b""
        return scheme + userinfo + self.host + port + self.query


# Ported from tdutils/td/utils/HttpUrl.cpp, check_url_part in parse_url().
def _check_url_part(
    part: bytes, name: str, refused: re.Pattern[bytes]
) -> Failure | None:
    match = refused.search(part)
    if match is None:
        return None
    if match[0] == b"%":
        return Failure(0, f"Wrong percent-encoded symbol in URL {name}")
    return Failure(0, f"Disallowed character in URL {name}")


# Ported from tdutils/td/utils/HttpUrl.cpp, parse_url(), for the default protocol HTTP.
def parse_url(url: bytes) -> HttpUrl | Failure:
    """Return `url` parsed as tdutils parses a URL, or the `Failure` that refuses it.

    A URL without `http://` or `https://` takes HTTP. The host is lowercased and
    checked, and so is the userinfo, unless the host is an IPv6 address in brackets; a
    port runs from 1 to 65535; and the query loses its trailing spaces, then has each
    other byte up to 0x20 percent-encoded.
    """
    # url == [https?://][userinfo@]host[:port]
    begin, pos = read_till_nofail(url, 0, b":/?#@[]")
    protocol_str = url[begin:pos].lower()
    if url.startswith(b"://", pos):
        if protocol_str == b"http":
            protocol = PROTOCOL.HTTP
        elif protocol_str == b"https":
            protocol = PROTOCOL.HTTPS
        else:
            return Failure(0, "Unsupported URL protocol")
        pos += 3
    else:
        pos = 0
        protocol = PROTOCOL.HTTP
    begin, end = read_till_nofail(url, pos, b"/?#")
    userinfo_host_port = url[begin:end]

    port = 0
    # Upstream steps back to the last colon, closing bracket, or `@`, but never reads
    # the first character, where it stops.
    colon = max(userinfo_host_port.rfind(c) for c in b":]@")
    if colon > 0 and userinfo_host_port[colon] == 0x3A:  # ':'
        port_slice = userinfo_host_port[colon + 1 :]
        # Leading zeros go, but a last one stays.
        port_slice = port_slice.lstrip(b"0") or port_slice[-1:]
        r_port = to_integer_safe(port_slice, 32)
        port = -1 if r_port is None or r_port == 0 else r_port
        userinfo_host = userinfo_host_port[:colon]
    else:
        userinfo_host = userinfo_host_port
    if port < 0 or port > 65535:
        return Failure(0, "Wrong port number specified in the URL")

    at_pos = userinfo_host.rfind(b"@")
    userinfo = b"" if at_pos == -1 else userinfo_host[:at_pos]
    host = userinfo_host[at_pos + 1 :]

    is_ipv6 = False
    if host[:1] == b"[" and host[-1:] == b"]":
        if not init_ipv6_port(host):
            return Failure(0, "Wrong IPv6 address specified in the URL")
        is_ipv6 = True
    if not host:
        return Failure(0, "URL host is empty")
    if host == b".":
        return Failure(0, "Host is invalid")

    specified_port = port
    if port == 0:
        port = 80 if protocol == PROTOCOL.HTTP else 443

    query = url[end:].rstrip(_SPACES) or b"/"
    query_str = query if query[0] == 0x2F else b"/" + query  # '/'
    if _UNSAFE_IN_QUERY.search(query_str):
        # No escape holds a byte up to 0x20, so replacing one byte value at a time
        # encodes each byte once.
        for c in range(0x21):
            query_str = query_str.replace(bytes((c,)), b"%%%02X" % c)

    host_str = host.lower()
    if is_ipv6:
        if host_str[1:-1].translate(None, _IPV6_HOST_CHARACTERS):
            return Failure(0, "Wrong IPv6 URL host")
    else:
        failure = _check_url_part(host_str, "host", _REFUSED_IN_HOST)
        if failure is None:
            failure = _check_url_part(userinfo, "userinfo", _REFUSED_IN_USERINFO)
        if failure is not None:
            return failure

    return HttpUrl(
        protocol, userinfo, host_str, is_ipv6, specified_port, port, query_str
    )
