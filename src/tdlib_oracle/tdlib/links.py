# Ported from td/telegram/LinkManager.cpp, tdutils/td/utils/HttpUrl.cpp,
# tdutils/td/utils/HttpUrl.h, tdutils/td/utils/misc.h, tdutils/td/utils/Parser.h,
# tdutils/td/utils/port/IPAddress.cpp, and tdutils/td/utils/Status.h of TDLib at the
# commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's checks of a link, with the URL parser of tdutils that they read.

A link survives in the form `check_link()` gives it, and a `tg://user?id=` link names
the user that `get_link_user_id()` reads. HTML checks the text inside each nested link
again, so each check passes over a link a fixed number of times in bytes methods and
regular expressions; a Python loop reads 20 of its bytes at most.
"""

import re
from dataclasses import dataclass
from typing import Final

from tdlib_oracle.tdlib.ipv6 import is_ipv6_address
from tdlib_oracle.text.failure import Failure
from tdlib_oracle.text.utf8 import check_utf8

# Ported from tdutils/td/utils/misc.h, is_space(), the characters it accepts.
_SPACES = b" \t\r\n\x00\x0b"

# Ported from tdutils/td/utils/HttpUrl.cpp, the first character that check_url_part in
# parse_url() refuses in a host: a `%` without two hex digits after it, or a character
# outside the symbols RFC 7230 and RFC 3986 allow, UTF-8 bytes aside. The byte past the
# end is the string terminator, no hex digit.
_REFUSED_IN_HOST = re.compile(
    rb"%(?![0-9A-Fa-f]{2})|[^%0-9A-Za-z.\-_!$,~*'();&+=\x80-\xff]"
)

# Ported from tdutils/td/utils/HttpUrl.cpp, the first character that check_url_part in
# parse_url() refuses in a userinfo, which may also hold colons. The byte past the end
# is the `@` after the userinfo, no hex digit either.
_REFUSED_IN_USERINFO = re.compile(
    rb"%(?![0-9A-Fa-f]{2})|[^%0-9A-Za-z.\-_!$,~*'();&+=:\x80-\xff]"
)

# Ported from tdutils/td/utils/HttpUrl.cpp, the bytes up to 0x20 that parse_url()
# percent-encodes in a query.
_UNSAFE_IN_QUERY = re.compile(rb"[\x00-\x20]")

# Ported from tdutils/td/utils/HttpUrl.cpp, the characters parse_url() allows in an IPv6
# host, between its brackets and in lowercase.
_IPV6_HOST_CHARACTERS = b":.0123456789abcdef"

# Ported from td/telegram/LinkManager.cpp, the characters LinkManager::check_link_impl()
# allows in the host of a tg or ton link; a tonsite link also allows dots.
_TG_HOST_CHARACTERS = (
    b"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_"
)
_TONSITE_HOST_CHARACTERS = _TG_HOST_CHARACTERS + b"."


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


# Ported from tdutils/td/utils/Parser.h, ParserImpl::read_till_nofail(Slice str).
def _read_till(data: bytes, pos: int, characters: bytes) -> int:
    """Return where any of `characters` first lies from `pos`, or the end of `data`."""
    ends = [data.find(c, pos) for c in characters]
    return min((end for end in ends if end != -1), default=len(data))


# Ported from tdutils/td/utils/misc.h, to_integer(Slice str), for a signed type of
# `bits` bits.
def _to_integer(text: bytes, bits: int) -> int:
    mask = (1 << bits) - 1
    maximum = mask >> 1
    is_negative = text[:1] == b"-"
    pos = 1 if is_negative else 0
    value = 0
    while pos < len(text) and 0x30 <= text[pos] <= 0x39:  # '0' to '9'
        value = (value * 10 + text[pos] - 0x30) & mask  # wraps as the unsigned type
        pos += 1

    if value > maximum:
        value = (~value + 1) & mask
        is_negative = not is_negative
        if value > maximum:
            return -maximum - 1
    return -value if is_negative else value


# Ported from tdutils/td/utils/misc.h, to_integer_safe().
def _to_integer_safe(text: bytes, bits: int) -> int | None:
    # A value prints in at most 20 characters, so a longer text never matches it.
    if len(text) > 20:
        return None
    value = _to_integer(text, bits)
    return value if str(value).encode() == text else None


# Ported from tdutils/td/utils/port/IPAddress.cpp, IPAddress::init_ipv6_port(), for the
# port 1 that parse_url() passes.
def _init_ipv6_port(ipv6: bytes) -> bool:
    if len(ipv6) > 2 and ipv6[0] == 0x5B and ipv6[-1] == 0x5D:  # '[' and ']'
        ipv6 = ipv6[1:-1]
    # inet_pton() reads a C string, which ends at the first NUL.
    return is_ipv6_address(ipv6.partition(b"\0")[0])


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
def parse_url(url: bytes) -> HttpUrl | Failure:  # noqa: PLR0912  # mirrors upstream
    """Return `url` parsed as tdutils parses a URL, or the `Failure` that refuses it.

    A URL without `http://` or `https://` takes HTTP. The host is lowercased and
    checked, and so is the userinfo, unless the host is an IPv6 address in brackets; a
    port runs from 1 to 65535; and the query loses its trailing spaces, then has each
    other byte up to 0x20 percent-encoded.
    """
    # url == [https?://][userinfo@]host[:port]
    pos = _read_till(url, 0, b":/?#@[]")
    protocol_str = url[:pos].lower()
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
    end = _read_till(url, pos, b"/?#")
    userinfo_host_port = url[pos:end]

    port = 0
    # Upstream steps back to the last colon, closing bracket, or `@`, but never reads
    # the first character, where it stops.
    colon = max(userinfo_host_port.rfind(c) for c in b":]@")
    if colon > 0 and userinfo_host_port[colon] == 0x3A:  # ':'
        port_slice = userinfo_host_port[colon + 1 :]
        # Leading zeros go, but a last one stays.
        port_slice = port_slice.lstrip(b"0") or port_slice[-1:]
        r_port = _to_integer_safe(port_slice, 32)
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
        if not _init_ipv6_port(host):
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


# Ported from td/telegram/LinkManager.cpp, tolower_begins_with().
def _tolower_begins_with(text: bytes, prefix: bytes) -> bool:
    return text[: len(prefix)].lower() == prefix


# Ported from td/telegram/LinkManager.cpp, LinkManager::check_link_impl(), for http_only
# and https_only unset, as TDLib checks the link of a formatted text.
def _check_link_impl(link: bytes) -> bytes | Failure:
    is_tg = False
    is_ton = False
    is_tonsite = False
    if _tolower_begins_with(link, b"tg:"):
        link = link[3:]
        is_tg = True
    elif _tolower_begins_with(link, b"ton:"):
        link = link[4:]
        is_ton = True
    elif _tolower_begins_with(link, b"tonsite:"):
        link = link[8:]
        is_tonsite = True
    if (is_tg or is_ton or is_tonsite) and link.startswith(b"//"):
        link = link[2:]
    http_url = parse_url(link)
    if isinstance(http_url, Failure):
        return http_url

    if is_tg or is_ton or is_tonsite:
        if (
            _tolower_begins_with(link, b"http://")
            or http_url.protocol == PROTOCOL.HTTPS
            or http_url.userinfo
            or http_url.specified_port != 0
            or http_url.is_ipv6
        ):
            return Failure(0, "Wrong tg URL" if is_tg else "Wrong ton URL")

        query = http_url.query
        if len(query) > 1 and query[1] == 0x3F:  # '?'
            query = query[1:]
        allowed = _TONSITE_HOST_CHARACTERS if is_tonsite else _TG_HOST_CHARACTERS
        if http_url.host.translate(None, allowed):
            return Failure(0, "Unallowed characters in URL host")
        scheme = b"tg" if is_tg else b"tonsite" if is_tonsite else b"ton"
        return scheme + b"://" + http_url.host + query

    if b"." not in http_url.host and not http_url.is_ipv6:
        return Failure(0, "Wrong HTTP URL")
    return http_url.get_url()


# Ported from td/telegram/LinkManager.cpp, LinkManager::check_link(), for http_only and
# https_only unset, as TDLib checks the link of a formatted text.
def check_link(link: bytes) -> bytes | Failure:
    """Return `link` in the form TDLib keeps it, or the `Failure` that refuses it.

    A link starts with `http://`, `https://`, `tg:`, `ton:`, `tonsite:`, or no scheme,
    which stands for HTTP, and an HTTP link needs a dot in its host unless the host is
    an IPv6 address. The refusal quotes the link only when it is valid UTF-8, and then
    only up to its first NUL, where the message ends.
    """
    result = _check_link_impl(link)
    if not isinstance(result, Failure):
        return result
    if check_utf8(link):
        # A Status reads its message as a C string, which ends at the first NUL
        # (tdutils/td/utils/Status.h, Status::message()).
        message = f"URL '{link.decode()}' is invalid: {result.message}"
        return Failure(400, message.partition("\0")[0])
    return Failure(400, f"URL is invalid: {result.message}")


# Ported from td/telegram/LinkManager.cpp, LinkManager::get_checked_link(), for
# http_only and https_only unset, as TDLib checks the link of a formatted text.
def get_checked_link(link: bytes) -> bytes:
    """Return `link` in the form TDLib keeps it, or empty if TDLib refuses it."""
    result = _check_link_impl(link)
    return b"" if isinstance(result, Failure) else result


# Ported from td/telegram/LinkManager.cpp, LinkManager::get_link_user_id().
def get_link_user_id(url: bytes) -> int:
    """Return the user ID that a `tg://user?id=` link names, or `0` if it names none.

    The ID is the first `id` parameter, read as a 64-bit integer; the caller checks that
    it lies in the range of user IDs, as TDLib's callers do.
    """
    url = url.lower()
    if not url.startswith(b"tg:"):
        return 0
    url = url[3:]
    if url.startswith(b"//"):
        url = url[2:]

    if not url.startswith(b"user") or (len(url) > 4 and url[4] not in b"/?#"):
        return 0
    url = url[4:]
    if url.startswith(b"/"):
        url = url[1:]
    if not url.startswith(b"?"):
        return 0
    url = url[1:].partition(b"#")[0]

    # The first parameter named `id` decides, with a value or without. With `&` added at
    # both ends, every parameter lies between two, so that one starts at the first
    # `&id=` or `&id&`, which a search finds without splitting the others.
    parameters = b"&" + url + b"&"
    starts = [parameters.find(b"&id="), parameters.find(b"&id&")]
    start = min((start for start in starts if start != -1), default=-1)
    if start == -1 or parameters[start + 3] != 0x3D:  # '='
        return 0
    value = parameters[start + 4 : parameters.index(b"&", start + 4)]
    user_id = _to_integer_safe(value, 64)
    return 0 if user_id is None else user_id
