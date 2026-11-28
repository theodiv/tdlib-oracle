"""Texts for the differential tests: drawn from a seed, and shrunk."""

import random
from collections.abc import Callable, Sequence

# The characters that the plain-text path treats each in its own way, and their
# neighbors, which it treats differently: controls, spaces, and line feeds; the marks
# and formatting characters that cleaning drops or replaces; the characters the
# emptiness check counts as blank, tag characters among them; and characters of every
# UTF-8 length.
PLAIN_UNITS = tuple(
    character.encode()
    for character in (
        "a",
        "Z",
        "0",
        "#",
        "/",
        "@",
        ".",
        " ",
        "\n",
        "\r",
        "\t",
        "\x00",
        "\x01",
        "\x0b",
        "\x0c",
        "\x1f",
        "\x7f",
        "\x85",
        "\U000000a0",
        "\U000000e9",
        "\U00000430",
        "\U00000301",
        "\U0000030a",
        "\U00000332",
        "\U00000333",
        "\U00000334",
        "\U0000033f",
        "\U00001680",
        "\U0000180e",
        "\U00002000",
        "\U00002005",
        "\U0000200a",
        "\U0000200b",
        "\U0000200c",
        "\U0000200d",
        "\U0000200e",
        "\U0000200f",
        "\U00002027",
        "\U00002028",
        "\U00002029",
        "\U0000202a",
        "\U0000202b",
        "\U0000202c",
        "\U0000202d",
        "\U0000202e",
        "\U0000202f",
        "\U0000205f",
        "\U000020ac",
        "\U00002800",
        "\U00003000",
        "\U0000e000",
        "\U0000fefe",
        "\U0000feff",
        "\U0000fffc",
        "\U0000fffd",
        "\U0001f600",
        "\U000e0000",
        "\U000e0020",
        "\U000e007f",
        "\U000e0080",
        "\U000f0000",
        "\U0010ffff",
    )
)

# Byte sequences that UTF-8 refuses: stray continuation bytes, sequences cut short,
# overlong forms, surrogates, a code point past U+10FFFF, and bytes no code point uses.
INVALID_UNITS = (
    b"\x80",
    b"\xbf",
    b"\xc3",
    b"\xe2\x80",
    b"\xf0\x9f\x98",
    b"\xc0\x80",
    b"\xc1\xbf",
    b"\xe0\x80\x80",
    b"\xf0\x80\x80\x80",
    b"\xed\xa0\x80",
    b"\xed\xbf\xbf",
    b"\xf4\x90\x80\x80",
    b"\xf5",
    b"\xfe",
    b"\xff",
)


# The characters and pieces that the search for mentions, bot commands, hashtags, and
# cashtags tells apart: their marks and the characters on each side of their bounds;
# letters and numbers of other scripts and of 4 bytes; the characters a hashtag takes
# besides letters and digits, and their neighbors; usernames, short and long; and runs
# at the length limits.
TAG_UNITS = tuple(
    piece.encode()
    for piece in (
        "@",
        "#",
        "$",
        "/",
        "<",
        ">",
        "_",
        "-",
        ".",
        " ",
        "\n",
        "a",
        "Z",
        "0",
        "ab",
        "gif",
        "GIF",
        "nft",
        "bot",
        "ABC",
        "ABCDEFGH",
        "1INCH",
        "1inch",
        "$ABC",
        "@bot",
        "@ab",
        "@" + "u" * 33,
        "a" * 31,
        "1" * 64,
        "b" * 128,
        "\U00000430",  # Cyrillic small a, a letter
        "\U00000663",  # Arabic-Indic digit three, a decimal number
        "\U000000b2",  # superscript two, a number
        "\U000000b7",  # middle dot
        "\U0000200c",  # zero width non-joiner
        "\U0000200d",  # zero width joiner
        "\U00000d7f",  # the Malayalam letter before the Sinhala block
        "\U00000d81",  # a Sinhala sign
        "\U00000dff",  # the last code point of the Sinhala block
        "\U00000e01",  # a Thai letter
        "\U00000e3f",  # the Thai currency sign
        "\U00002122",  # trade mark sign
        "\U00000301",  # combining acute accent
        "\U000000a0",  # no-break space
        "\U0001d49c",  # mathematical script capital A
        "\U0001f600",  # an emoji
    )
)

# The pieces that the search for links and email addresses tells apart: the protocols
# it keeps or refuses; whole domains, IPv4 addresses, and email addresses; labels and
# top level domains in their cases and scripts; ports at their bounds; user data; path
# characters, brackets, and the punctuation a link does not end with; and separators.
LINK_UNITS = tuple(
    piece.encode()
    for piece in (
        "http://",
        "https://",
        "ftp://",
        "tonsite://",
        "tg://",
        "ton://",
        "TG://",
        "HtTpS://",
        "shttp://",
        "sftp://",
        "tftp://",
        "xhttp://",
        "tonsXte://",
        "tonsiXe://",
        "a://",
        "://",
        "mailto:",
        "telegram.org",
        "t.me",
        "a.b.c.com",
        "telegram.ton",
        "TELEGRAM.ORG",
        "Telegram.Org",
        "teiegram.org",
        "TeIegram.org",
        "test_.com",
        "_.test.com",
        "a-.com",
        "xn--80a.xn--p1ai",
        "xn--a.com",
        "a.xn--",
        "\U00000434\U0000043e\U0000043c.\U00000440\U00000444",
        "\U00000434.\U00000420\U00000444",
        "www.\U0001f919.tk",
        "1.2.3.4",
        "255.255.255.255",
        "256.1.1.1",
        "01.2.3.4",
        "240.1.1.1",
        "260.1.1.1",
        "1.2.3",
        "a@b.com",
        "mailto:a@b.com",
        "a@_b.cd",
        "a.b+c@d.ef",
        "x@y.z",
        "user:pass@",
        "a",
        "t",
        "telegram",
        "my-site",
        "_",
        "-",
        "~",
        "org",
        "com",
        "Org",
        "museum",
        "abcdefgh",
        "\U00004e2d\U000056fd",  # China, in Chinese
        "1",
        "127",
        "256",
        "0",
        "x" * 27,
        "y" * 36,
        "z" * 64,
        ".",
        "..",
        ":",
        ":80",
        ":0",
        ":00080",
        ":65535",
        ":65536",
        ":123456",
        "/",
        "?",
        "#",
        "/path",
        "?q=()",
        "@",
        "(",
        ")",
        "[",
        "]",
        "{",
        "}",
        "'",
        "`",
        "!",
        ";",
        ",",
        '"',
        "<",
        ">",
        " ",
        "\n",
        "\U000000ab",  # left-pointing double angle quotation mark
        "\U000000bb",  # right-pointing double angle quotation mark
        "\U00002010",  # hyphen
        "\U00002016",  # double vertical line
        "\U0000200b",  # zero width space
        "\U00002060",  # word joiner
        "\U000000a0",  # no-break space
        "\U00003000",  # ideographic space
        "\U00000430",  # Cyrillic small a
        "\U00001a89",  # Tai Tham Tham digit nine, a digit outside ASCII
    )
)

# The pieces that the search for bank card numbers tells apart: numbers that pass the
# Luhn check for each brand and length rule, and ones that fail it; digits, the spaces
# and hyphens between them, and the characters on each side of a number.
CARD_UNITS = tuple(
    piece.encode()
    for piece in (
        "4000000000006",  # Visa, 13 digits
        "4111111111111111",  # Visa, 16 digits
        "40000000000002",  # Visa, 14 digits
        "5500000000000004",  # Mastercard
        "2221000000000009",  # Mastercard of the 2 series
        "272000000000001",  # Mastercard, 15 digits
        "340000000000009",  # American Express, 15 digits
        "3700000000000007",  # American Express, 16 digits
        "6200000000000005",  # UnionPay, 16 digits
        "8100000000000002",  # UnionPay of prefix 81, 16 digits
        "620000000000000",  # UnionPay, 15 digits
        "2200000000000004",  # MIR, 16 digits
        "22040000000000006",  # MIR, 17 digits
        "9000000000001",  # no brand
        "4111111111111112",  # a wrong check digit
        "4111 1111 1111 1111",
        "4111-1111-1111-1111",
        "1" * 20,
        "0",
        "4",
        "5",
        "9",
        " ",
        "-",
        "  ",
        ".",
        ",",
        "+",
        "_",
        "a",
        "/",
        '"',
        "\U00000430",  # Cyrillic small a
        "\U00000663",  # Arabic-Indic digit three
    )
)

# The pieces that the search for TON addresses tells apart: valid addresses in both
# alphabets, and ones of a wrong checksum, of mixed alphabets, of a wrong first byte, or
# a character short; base64 characters, which lengthen a run, and other characters,
# which end one.
TON_UNITS = tuple(
    piece.encode()
    for piece in (
        "EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqB2N",
        "UQDqgkqefbZu_fZ7-8eib6h3vLubZxQfu-KRi829HBBUGzWm",
        "UQDqgkqefbZu/fZ7+8eib6h3vLubZxQfu+KRi829HBBUGzWm",
        "kQABAgMEBQYHCAkKCwwNDg8QERITFBUWFxgZGhscHR4fIESL",
        "Ef___________________________________________7Sg",
        "UQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqEBJ",
        "UQDqgkqefbZu_fZ7+8eib6h3vLubZxQfu+KRi829HBBUGzWm",
        "A" * 48,
        "EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqB2",
        "A",
        "_",
        "-",
        "+",
        "/",
        "0",
        "=",
        " ",
        ".",
        "#",
        ":",
    )
)

# Every unit that some kind of entity's search tells apart, each once.
FINDING_UNITS = tuple(dict.fromkeys(TAG_UNITS + LINK_UNITS + CARD_UNITS + TON_UNITS))


# Texts that end with a left-to-right or a right-to-left mark, where cleaning reads the
# string's terminator in place of a next mark.
MARK_ENDINGS = tuple(
    tuple(character.encode() for character in text)
    for text in (
        "a\U0000200e",
        "a\U0000200f",
        "a\U0000200e\U0000200f",
        "\U0000200f",
        "\U0000200e\U0000200e",
        "a \U0000200f",
    )
)


def texts_around(limit: int, units: Sequence[bytes]) -> list[tuple[bytes, ...]]:
    """Return texts in which each of `units` ends within four bytes of `limit`.

    A text is a run of `a` as one unit, then one of `units`, then `bbb`, so it shrinks
    by whole runs only and keeps the length that reaches `limit`.
    """
    return [
        (b"a" * (limit + offset - len(unit)), unit, b"bbb")
        for unit in units
        for offset in range(-4, 5)
    ]


def draw_texts(
    seed: int, count: int, units: Sequence[bytes], *, max_units: int = 40
) -> list[tuple[bytes, ...]]:
    """Return `count` texts of up to `max_units` units, drawn from `units` with `seed`.

    Each text draws from a few of `units` only, so texts of blank characters alone, or
    of one character repeated, come up as often as mixed ones.
    """
    rng = random.Random(seed)
    texts = []
    for _ in range(count):
        palette = rng.sample(units, rng.randint(1, min(6, len(units))))
        size = rng.randint(0, max_units if rng.random() < 0.5 else 4)
        texts.append(tuple(rng.choice(palette) for _ in range(size)))
    return texts


def _remove_runs(
    text: tuple[bytes, ...],
    fails: Callable[[list[tuple[bytes, ...]]], list[bool]],
) -> tuple[bytes, ...]:
    """Return `text` without each run of units whose removal `fails` still flags."""
    run = max(len(text) // 2, 1)
    while text:
        candidates = [
            text[:start] + text[start + run :] for start in range(0, len(text), run)
        ]
        flagged = [
            candidate
            for candidate, failed in zip(candidates, fails(candidates), strict=True)
            if failed
        ]
        if flagged:
            text = flagged[0]
            run = min(run, max(len(text) // 2, 1))
        elif run > 1:
            run //= 2
        else:
            break
    return text


def shrink(
    text: tuple[bytes, ...],
    fails: Callable[[list[tuple[bytes, ...]]], list[bool]],
    *,
    by_bytes: bool,
) -> tuple[bytes, ...]:
    """Return the shortest text found from `text` that `fails` still flags.

    It passes `fails` a whole batch of candidate texts at once, so a caller can run the
    compiled code on each batch in one process. Whole units go first, which keeps a text
    of characters valid UTF-8; with `by_bytes`, the units left are split into bytes, and
    those go too.
    """
    text = _remove_runs(text, fails)
    if by_bytes:
        text = _remove_runs(
            tuple(bytes([byte]) for unit in text for byte in unit), fails
        )
    return text
