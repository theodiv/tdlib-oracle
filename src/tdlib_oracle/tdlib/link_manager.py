# Ported from td/telegram/LinkManager.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's checks of a link: whether it survives, in what form, and what it names.

HTML and MarkdownV2 check the text inside each nested link again, so `check_link()`,
`get_checked_link()`, and `get_link_user_id()` pass over a link a fixed number of times
in bytes methods and regular expressions, and a Python loop in them reads 20 of its
bytes at most.
"""

from tdlib_oracle.runtime.cstring import Span
from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.formatted_date import get_date_flags
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

    The refusal holds the reason alone, with code `0`.
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
    """Return `link` in the form TDLib keeps it, or the `Failure` that refuses it."""
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

    The ID is not checked against the range of user IDs.
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


# Ported from td/telegram/LinkManager.cpp, LinkManager::check_tg_url_host().
def check_tg_url_host(url: bytes, host: bytes) -> Span | Failure:
    """Return where the parameters of the `tg:` link `url` lie, or its `Failure`."""
    # The C++ lowercases only as many bytes as `tg://`, the host, and one more take, and
    # compares them with `host`, which the caller writes in lowercase.
    lower_cased_url = url[: 3 + 2 + len(host) + 1].lower()

    if not lower_cased_url.startswith(b"tg:"):
        return Failure(400, "URL must have scheme tg")
    lower_cased_url = lower_cased_url[3:]
    begin = 3
    if url.startswith(b"//", begin):
        lower_cased_url = lower_cased_url[2:]
        begin += 2

    if not lower_cased_url.startswith(host) or (
        len(url) - begin > len(host) and url[begin + len(host)] not in b"/?#"
    ):
        return Failure(400, f'URL must have host "{host.decode()}"')
    begin += len(host)
    if url.startswith(b"/", begin):
        begin += 1
    if not url.startswith(b"?", begin):
        return Failure(400, "URL must have parameters")
    begin += 1
    end = url.find(b"#", begin)
    return begin, len(url) if end == -1 else end


# Ported from td/telegram/LinkManager.cpp, LinkManager::get_link_custom_emoji_id().
def get_link_custom_emoji_id(url: bytes) -> int | Failure:
    """Return the custom emoji ID that a `tg://emoji` link names, or its `Failure`."""
    query = check_tg_url_host(url, b"emoji")
    if isinstance(query, Failure):
        return query
    begin, end = query
    for parameter in url[begin:end].split(b"&"):
        key, _, value = parameter.partition(b"=")
        if key == b"id":
            document_id = to_integer_safe(value, 64)
            if document_id is None or document_id == 0:
                return Failure(400, "Invalid custom emoji identifier specified")
            return document_id
    return Failure(400, "Custom emoji URL must have an emoji identifier")


# Ported from td/telegram/LinkManager.cpp, LinkManager::get_link_formatted_date().
def get_link_formatted_date(url: bytes) -> tuple[int, int] | Failure:
    """Return the date and the flags a `tg://time` link names, or its `Failure`."""
    query = check_tg_url_host(url, b"time")
    if isinstance(query, Failure):
        return query
    begin, end = query
    date = 0
    date_format = b""
    for parameter in url[begin:end].split(b"&"):
        key, _, value = parameter.partition(b"=")
        if key == b"unix":
            unix_time = to_integer_safe(value, 32)
            if unix_time is None or unix_time <= 0:
                return Failure(400, "Invalid Unix time specified")
            date = unix_time
        elif key == b"format":
            date_format = value
    if date == 0:
        return Failure(400, "URL must have the corresponding Unix time")

    # Stands in for td/telegram/FormattedDate.cpp,
    # FormattedDate::get_formatted_date(int32 date, const string &date_format).
    date_flags = get_date_flags(date_format)
    if isinstance(date_flags, Failure):
        return date_flags
    return date, date_flags
