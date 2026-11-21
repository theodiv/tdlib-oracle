# Ported from td/telegram/LinkManager.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's checks of a link: whether it survives, and in what form.

A link survives in the form `check_link()` gives it, and a `tg://user?id=` link names
the user that `get_link_user_id()` reads. HTML checks the text inside each nested link
again, so each check passes over a link a fixed number of times in bytes methods and
regular expressions; a Python loop reads 20 of its bytes at most.
"""

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdutils.http_url import PROTOCOL, parse_url
from tdlib_oracle.tdutils.misc import to_integer_safe
from tdlib_oracle.tdutils.utf8 import check_utf8

# Ported from td/telegram/LinkManager.cpp, LinkManager::check_link_impl(), the
# characters it allows in the host of a tg or ton link; a tonsite link also allows dots.
_TG_HOST_CHARACTERS = (
    b"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_"
)
_TONSITE_HOST_CHARACTERS = _TG_HOST_CHARACTERS + b"."


# Ported from td/telegram/LinkManager.cpp, tolower_begins_with().
def _tolower_begins_with(text: bytes, prefix: bytes) -> bool:
    return text[: len(prefix)].lower() == prefix


# Ported from td/telegram/LinkManager.cpp, LinkManager::check_link_impl(), for http_only
# and https_only unset, as TDLib checks the link of a formatted text.
def check_link_impl(link: bytes) -> bytes | Failure:
    """Return `link` in the form TDLib keeps it, or the `Failure` that refuses it.

    The refusal holds the reason alone, with code `0`: `check_link` words it for the
    caller, and `get_checked_link` drops it.
    """
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
    result = check_link_impl(link)
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
    result = check_link_impl(link)
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
    user_id = to_integer_safe(value, 64)
    return 0 if user_id is None else user_id
