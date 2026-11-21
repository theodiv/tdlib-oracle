import itertools
from collections.abc import Callable

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.formatted_date import (
    get_date_flags,
    get_date_time_formatting_type_object,
    get_formatted_date,
)

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

# The precisions of a part of a date, by the index the harness reads them by: none at
# all, then each one.
_PRECISIONS = (
    None,
    td_api.DateTimePartPrecisionNone(),
    td_api.DateTimePartPrecisionShort(),
    td_api.DateTimePartPrecisionLong(),
)

# Dates on each side of zero and at the ends of a 32-bit integer.
_EDGE_DATES = (0, 1, -1, 1_700_000_000, (1 << 31) - 1, -(1 << 31))

# Every set of the flags of a date, and one past them, which TDLib leaves unread.
_ALL_DATE_FLAGS = range(128)


def _get_formatted_date(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    date_flags = get_date_flags(text)
    if isinstance(date_flags, Failure):
        return (str(date_flags.code).encode(), date_flags.message.encode(), b"")
    return (b"0", b"", f"date {args[0]} with flags {date_flags}".encode())


def _formatting_type(
    args: tuple[int, ...],
) -> td_api.DateTimeFormattingType | None:
    """Return the formatting type that `args` name, as the harness reads them.

    The first names no type, a relative one, or an absolute one, whose precisions of the
    time and of the date the next two name in `_PRECISIONS`, and the last whether the
    day of the week shows.
    """
    kind, time_precision, date_precision, show_day_of_week = args
    match kind:
        case 1:
            return td_api.DateTimeFormattingTypeRelative()
        case 2:
            return td_api.DateTimeFormattingTypeAbsolute(
                _PRECISIONS[time_precision],
                _PRECISIONS[date_precision],
                bool(show_day_of_week),
            )
        case _:
            return None


def _precision_field(precision: td_api.DateTimePartPrecision | None) -> bytes:
    if precision is None:
        return b""
    return (b"none", b"short", b"long")[_PRECISIONS.index(precision) - 1]


def _get_formatted_date_from_type(
    text: bytes, args: tuple[int, ...]
) -> tuple[bytes, ...]:
    result = get_formatted_date(args[0], _formatting_type(args[1:]))
    if isinstance(result, Failure):
        return (str(result.code).encode(), result.message.encode(), b"")
    date, date_flags = result
    return (b"0", b"", f"date {date} with flags {date_flags}".encode())


def _get_date_time_formatting_type_object(
    text: bytes, args: tuple[int, ...]
) -> tuple[bytes, ...]:
    match get_date_time_formatting_type_object(args[0]):
        case td_api.DateTimeFormattingTypeRelative():
            return (b"relative", b"", b"", b"0")
        case td_api.DateTimeFormattingTypeAbsolute() as formatting_type:
            return (
                b"absolute",
                _precision_field(formatting_type.time_precision),
                _precision_field(formatting_type.date_precision),
                b"1" if formatting_type.show_day_of_week else b"0",
            )
        case None:
            return (b"", b"", b"", b"0")


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


def test_get_formatted_date_gives_the_pinned_date_for_every_formatting_type(
    compare: Compare,
) -> None:
    formats = itertools.product(range(3), range(4), range(4), range(2))
    cases = [((), (date, *args)) for args in formats for date in _EDGE_DATES]
    compare(
        "get_formatted_date(td_api)",
        _get_formatted_date_from_type,
        cases,
        seed=None,
        by_bytes=False,
    )


def test_get_date_time_formatting_type_object_gives_the_pinned_type_for_every_flag(
    compare: Compare,
) -> None:
    cases = [((), (date_flags,)) for date_flags in _ALL_DATE_FLAGS]
    compare(
        "get_date_time_formatting_type_object",
        _get_date_time_formatting_type_object,
        cases,
        seed=None,
        by_bytes=False,
    )
