"""The text forms of an IPv6 address that RFC 4291 defines.

TDLib checks a host in brackets with the C library's `inet_pton()`
(tdutils/td/utils/port/IPAddress.cpp, IPAddress::init_ipv6_port()). glibc accepts
exactly the text forms of RFC 4291, section 2.2, held to the `IPv6address` rule of RFC
3986, section 3.2.2, so the check follows those, and no C library's code reaches the
package.
"""

_HEX_DIGITS = frozenset(b"0123456789ABCDEFabcdef")

# No address in these forms is longer than six full groups and an IPv4 address, so a
# longer text is refused before it is split.
_MAX_LENGTH = len(b"ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255")


def _is_group(text: bytes) -> bool:
    """Return whether `text` is one 16-bit group: 1 to 4 hex digits."""
    return 1 <= len(text) <= 4 and all(c in _HEX_DIGITS for c in text)


def _is_octet(text: bytes) -> bool:
    """Return whether `text` is a number from 0 to 255 without a leading zero."""
    return (
        1 <= len(text) <= 3
        and text.isdigit()
        and (len(text) == 1 or text[0] != 0x30)  # '0'
        and int(text) <= 255
    )


def _is_ipv4_address(text: bytes) -> bool:
    """Return whether `text` is an IPv4 address in dotted decimal."""
    octets = text.split(b".")
    return len(octets) == 4 and all(_is_octet(octet) for octet in octets)


def _count_groups(text: bytes, *, allow_ipv4: bool) -> int | None:
    """Return how many 16-bit groups `text` fills, or `None` if it is malformed.

    `text` is groups separated by single colons; with `allow_ipv4`, an IPv4 address may
    stand last, for the two groups it fills.
    """
    if not text:
        return 0
    *groups, last = text.split(b":")
    if not all(_is_group(group) for group in groups):
        return None
    if _is_group(last):
        return len(groups) + 1
    if allow_ipv4 and _is_ipv4_address(last):
        return len(groups) + 2
    return None


def is_ipv6_address(text: bytes) -> bool:
    """Return whether `text` is an IPv6 address in one of RFC 4291's text forms.

    Eight groups of 1 to 4 hex digits are separated by colons; one `::` may stand for
    one or more groups of zeros; and an IPv4 address in dotted decimal, its numbers
    without leading zeros, may fill the last two groups.
    """
    if len(text) > _MAX_LENGTH:
        return False

    head, compressed, tail = text.partition(b"::")
    if not compressed:
        return _count_groups(text, allow_ipv4=True) == 8
    head_groups = _count_groups(head, allow_ipv4=False)
    tail_groups = _count_groups(tail, allow_ipv4=True)
    return (
        head_groups is not None
        and tail_groups is not None
        and head_groups + tail_groups <= 7
    )
