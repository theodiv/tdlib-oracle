import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.formatted_date import (
    get_date_flags,
    get_date_time_formatting_type_object,
    get_formatted_date,
    is_valid_formatted_date,
)

_NONE = td_api.DateTimePartPrecisionNone()
_SHORT = td_api.DateTimePartPrecisionShort()
_LONG = td_api.DateTimePartPrecisionLong()


@pytest.mark.parametrize(
    ("date_format", "date_flags"),
    [(b"t", 2), (b"T", 4), (b"d", 8), (b"D", 16), (b"w", 32), (b"W", 32)],
)
def test_reads_the_part_each_character_shows(
    date_format: bytes, date_flags: int
) -> None:
    assert get_date_flags(date_format) == date_flags


@pytest.mark.parametrize("date_format", [b"r", b"R"])
def test_reads_r_alone_as_a_relative_date(date_format: bytes) -> None:
    assert get_date_flags(date_format) == 1


def test_adds_up_the_parts_of_every_character() -> None:
    assert get_date_flags(b"tttTTdDwW") == 62


def test_shows_no_part_for_an_empty_format() -> None:
    assert get_date_flags(b"") == 0


@pytest.mark.parametrize(
    "date_format",
    [b"rt", b"rr", b"Rr", b"x", b"ts", b" ", b"\x00", b"t\x00", "\U000000e9".encode()],
)
def test_refuses_any_other_character(date_format: bytes) -> None:
    assert get_date_flags(date_format) == Failure(400, "Invalid date format used")


@pytest.mark.parametrize("date", [1, 1_700_000_000])
def test_is_valid_formatted_date_accepts_a_positive_date(date: int) -> None:
    assert is_valid_formatted_date(date)


@pytest.mark.parametrize("date", [0, -1])
def test_is_valid_formatted_date_refuses_0_and_negatives(date: int) -> None:
    assert not is_valid_formatted_date(date)


@pytest.mark.parametrize("date", [0, -1])
def test_get_formatted_date_refuses_a_date_that_is_not_positive(date: int) -> None:
    assert get_formatted_date(date, None) == Failure(400, "Invalid date specified")


def test_get_formatted_date_shows_no_part_without_a_formatting_type() -> None:
    assert get_formatted_date(1, None) == (1, 0)


def test_get_formatted_date_reads_a_relative_type() -> None:
    relative = td_api.DateTimeFormattingTypeRelative()
    assert get_formatted_date(1_700_000_000, relative) == (1_700_000_000, 1)


@pytest.mark.parametrize(
    ("time_precision", "date_precision", "show_day_of_week", "date_flags"),
    [
        (_SHORT, _LONG, True, 2 | 16 | 32),
        (_LONG, _SHORT, False, 4 | 8),
        (_NONE, None, False, 0),
        (None, _NONE, True, 32),
    ],
)
def test_get_formatted_date_reads_each_part_of_an_absolute_type(
    time_precision: td_api.DateTimePartPrecision | None,
    date_precision: td_api.DateTimePartPrecision | None,
    show_day_of_week: bool,
    date_flags: int,
) -> None:
    absolute = td_api.DateTimeFormattingTypeAbsolute(
        time_precision, date_precision, show_day_of_week
    )
    assert get_formatted_date(1, absolute) == (1, date_flags)


def test_get_date_time_formatting_type_object_gives_no_type_without_flags() -> None:
    assert get_date_time_formatting_type_object(0) is None


def test_get_date_time_formatting_type_object_lets_relative_hide_the_others() -> None:
    relative = td_api.DateTimeFormattingTypeRelative()
    assert get_date_time_formatting_type_object(1 | 2 | 16 | 32) == relative


@pytest.mark.parametrize(
    ("date_flags", "formatting_type"),
    [
        (2 | 4 | 8 | 16, td_api.DateTimeFormattingTypeAbsolute(_SHORT, _SHORT, False)),
        (4 | 16 | 32, td_api.DateTimeFormattingTypeAbsolute(_LONG, _LONG, True)),
        (32, td_api.DateTimeFormattingTypeAbsolute(_NONE, _NONE, True)),
    ],
)
def test_get_date_time_formatting_type_object_shows_the_short_form_over_the_long(
    date_flags: int, formatting_type: td_api.DateTimeFormattingType
) -> None:
    assert get_date_time_formatting_type_object(date_flags) == formatting_type


def test_a_round_trip_keeps_only_the_short_time_of_a_short_and_a_long_one() -> None:
    formatting_type = get_date_time_formatting_type_object(2 | 4)
    assert get_formatted_date(1, formatting_type) == (1, 2)
