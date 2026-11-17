"""Texts for the differential tests: drawn from a seed, and shrunk.

A text is a tuple of units, each one character in UTF-8 or one byte sequence that UTF-8
refuses, so a text of valid units stays valid UTF-8 as it shrinks.
"""

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
    of one character repeated, come up as often as mixed ones, and half the texts hold
    four units or fewer.
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

    `fails` flags a whole batch of candidate texts at once, so a caller can run the
    compiled code on each batch in one process. Whole units go first, which keeps a
    text of characters valid UTF-8; with `by_bytes`, the units left are split into
    bytes, and those go too.
    """
    text = _remove_runs(text, fails)
    if by_bytes:
        text = _remove_runs(
            tuple(bytes([byte]) for unit in text for byte in unit), fails
        )
    return text
