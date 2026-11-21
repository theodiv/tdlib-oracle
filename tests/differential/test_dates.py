import itertools
from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib.dates import get_date_flags
from tdlib_oracle.text.failure import Failure

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# The characters a format tells apart: the letter of each part in both cases, the letter
# of a relative date, and characters it refuses: another letter, a space, a NUL, and the
# first byte of a character of 2 bytes.
_SYMBOLS = (
    b"r",
    b"R",
    b"t",
    b"T",
    b"d",
    b"D",
    b"w",
    b"W",
    b"x",
    b" ",
    b"\x00",
    b"\xc3",
)

# Dates on each side of zero, which the format leaves as they are.
_DATES = (0, 1, -1, 1_700_000_000)


def _get_formatted_date(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    date_flags = get_date_flags(text)
    if isinstance(date_flags, Failure):
        return (str(date_flags.code).encode(), date_flags.message.encode(), b"")
    return (b"0", b"", f"date {args[0]} with flags {date_flags}".encode())


def test_get_date_flags_gives_the_pinned_flags_for_every_short_format(
    compare: Compare,
) -> None:
    formats = [
        units
        for length in range(4)
        for units in itertools.product(_SYMBOLS, repeat=length)
    ]
    cases = [
        (units, (_DATES[index % len(_DATES)],)) for index, units in enumerate(formats)
    ]
    compare("get_formatted_date", _get_formatted_date, cases, seed=None, by_bytes=True)
