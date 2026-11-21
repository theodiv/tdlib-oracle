import pytest

from tdlib_oracle.tdlib.dates import get_date_flags
from tdlib_oracle.text.failure import Failure


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
