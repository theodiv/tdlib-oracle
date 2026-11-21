"""Links for the differential tests of the URL parser and the link checks.

A link is a tuple of parts, such as a scheme, a host, or a port, so a differing link
shrinks by whole parts before it shrinks by bytes.
"""

import random

from tests.support.texts import INVALID_UNITS, draw_texts

# Schemes the link checks tell apart, in either case, and their near misses.
_SCHEMES = (
    b"",
    b"http://",
    b"https://",
    b"HTTP://",
    b"hTtPs://",
    b"ftp://",
    b"httpx://",
    b"://",
    b"http:",
    b"http:/",
    b"tg:",
    b"tg://",
    b"TG:",
    b"Tg://",
    b"ton:",
    b"ton://",
    b"TON:",
    b"tonsite:",
    b"tonsite://",
    b"TonSite://",
    b"tonsit:",
    b"tg:http://",
    b"tg://https://",
    b"ton:HTTP://",
    b"mailto:",
    b"//",
)

# Userinfo before a host: none, plain, with colons and at signs, with every symbol it
# allows, percent escapes good and bad, and characters it refuses or takes as UTF-8.
_USERINFOS = (
    b"",
    b"",
    b"user@",
    b"user:pass@",
    b"@",
    b":@",
    b"a@b@",
    b"!$,~*'();&+=-_.:@",
    b"%41@",
    b"%4@",
    b"a b@",
    b"<@",
    b"\xc3\xa9@",
)

# Hosts: with and without dots, in either case, with every symbol a host allows, of
# other scripts and of bytes that are not UTF-8, with percent escapes good and bad, and
# IPv6 addresses in brackets, valid, malformed, cut by a NUL, or with a bracket on one
# side only.
_HOSTS = (
    b"example.com",
    b"t.me",
    b"EXAMPLE.COM",
    b"a.b.c",
    b"localhost",
    b"a",
    b"_",
    b"-",
    b"a-b_c",
    b"!$,~*'();&+=.a",
    b"user",
    b".",
    b"..",
    b"",
    b"xn--80a.xn--p1ai",
    b"1.2.3.4",
    "\U00000434\U0000043e\U0000043c.\U00000440\U00000444".encode(),
    "\U0001f600.com".encode(),
    b"caf\xe9.com",
    b"\xed\xa0\x80.com",
    b"a%41.com",
    b"a%4.com",
    b"a%.com",
    b"a<b.com",
    b"a b.com",
    b"a\x00b.com",
    b"[::1]",
    b"[2001:db8::ff00:42:8329]",
    b"[::FFFF:1.2.3.4]",
    b"[]",
    b"[",
    b"]",
    b"[::1",
    b"::1]",
    b"[:::]",
    b"[::g]",
    b"[::%0]",
    b"[::1\x00]",
    b"[::1\x00x]",
    b"[1:2:3:4:5:6:7:8:9]",
    b"[1.2.3.4]",
)

# Ports: none, empty, at and past the bounds, with leading zeros, signed, not numbers,
# and past the bounds of a 32-bit integer, which wraps them.
_PORTS = (
    b"",
    b"",
    b":",
    b":0",
    b":1",
    b":80",
    b":00080",
    b":0000000001",
    b":65535",
    b":65536",
    b":-1",
    b":+1",
    b":0x1",
    b":2147483648",
    b":4294967295",
    b":4294967377",
    b":" + b"1" * 24,
)

# What follows the host: paths, queries, and fragments, with controls, spaces, and
# trailing spaces.
_PATHS = (
    b"",
    b"",
    b"/",
    b"?",
    b"#",
    b"/?",
    b"/path",
    b"?a=b",
    b"#frag",
    b"/?q=()",
    b"/ x",
    b"/a b ",
    b" ",
    b"\t",
    b"/\x00\x1f",
    b"/%20",
    b"/\x0c",
    b"?\x0b",
    b"/\xc3\xa9",
)

# How a tg://user link starts, right and in near misses.
_USER_PREFIXES = (
    b"tg://user?",
    b"tg:user?",
    b"TG://USER/?",
    b"tg://user/?",
    b"tg://users?",
    b"tg://user#?",
    b"tg://user",
    b"tg:/user?",
    b"http://user?",
    b"tg://user?x=1&",
)

# Parameters of a tg://user link, and the separators between them.
_USER_PARAMETERS = (b"id=", b"ID=", b"id", b"&", b"=", b"x=1", b"#", b"id=5&")

# IDs at the bounds of a 64-bit integer and of a valid user ID, and texts that read as
# no integer.
_USER_IDS = (
    b"0",
    b"1",
    b"-1",
    b"5",
    b"007",
    b"-0",
    b"+5",
    b"5x",
    b"1099511627775",
    b"1099511627776",
    b"9223372036854775807",
    b"9223372036854775808",
    b"-9223372036854775808",
    b"-9223372036854775809",
    b"18446744073709551621",
    b"1" * 25,
)

# Every unit above, each once, and the byte sequences UTF-8 refuses.
_UNITS = tuple(
    unit
    for unit in dict.fromkeys(
        _SCHEMES
        + _USERINFOS
        + _HOSTS
        + _PORTS
        + _PATHS
        + _USER_PREFIXES
        + _USER_PARAMETERS
        + _USER_IDS
        + INVALID_UNITS
    )
    if unit
)

# Links that reach what generated links may miss, and the ones that differed once.
FIXED_LINKS = (
    b"",
    b"\x00",
    b"http:google.com",
    b"http://:80/x",
    b"tg:///a",
    b"tg://user?id&id=5",
    b"tg://user?" + b"&" * 40 + b"id=5",
)


def _draw_links(seed: int, count: int) -> list[tuple[bytes, ...]]:
    """Return `count` links drawn from `seed`, each split into its parts.

    A link joins a scheme, a userinfo, a host, a port, and a path, then has up to two
    parts inserted from every unit, deleted, or replaced.
    """
    rng = random.Random(f"{seed} links")
    links = []
    for _ in range(count):
        parts = [
            rng.choice(_SCHEMES),
            rng.choice(_USERINFOS),
            rng.choice(_HOSTS),
            rng.choice(_PORTS),
            rng.choice(_PATHS),
        ]
        for _ in range(rng.randint(0, 2)):
            pos = rng.randrange(len(parts) + 1)
            match rng.randrange(3):
                case 0:
                    parts.insert(pos, rng.choice(_UNITS))
                case 1:
                    del parts[pos : pos + 1]
                case _:
                    parts[pos : pos + 1] = [rng.choice(_UNITS)]
        links.append(tuple(part for part in parts if part))
    return links


def _draw_user_links(seed: int, count: int) -> list[tuple[bytes, ...]]:
    """Return `count` tg://user links drawn from `seed`, each split into its parts."""
    rng = random.Random(f"{seed} user links")
    links = []
    for _ in range(count):
        parts = [rng.choice(_USER_PREFIXES)]
        for _ in range(rng.randint(1, 4)):
            parts.append(rng.choice(_USER_PARAMETERS))
            if rng.random() < 0.7:
                parts.append(rng.choice(_USER_IDS))
        links.append(tuple(parts))
    return links


def draw_links(seed: int, count: int) -> list[tuple[bytes, ...]]:
    """Return `count` links of each kind drawn from `seed`: built, `tg://user`, random.

    A built link joins a scheme, a userinfo, a host, a port, and a path, with up to two
    parts changed; a `tg://user` link adds parameters and IDs to a right or near-miss
    start; and a random link joins units of every kind, bytes that UTF-8 refuses
    among them.
    """
    links = _draw_links(seed, count)
    links += _draw_user_links(seed, count)
    links += draw_texts(seed, count, _UNITS)
    return links
