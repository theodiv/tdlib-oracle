import pytest

from tdlib_oracle.text.integers import to_integer, to_integer_safe


@pytest.mark.parametrize(
    ("text", "value"),
    [
        (b"0", 0),
        (b"42", 42),
        (b"-42", -42),
        (b"007", 7),
        (b"12ab", 12),
        (b"1 2", 1),
        (b"", 0),
        (b"-", 0),
        (b"+5", 0),
        (b" 5", 0),
        ("\U00000663".encode(), 0),  # Arabic-Indic digit three
    ],
)
def test_to_integer_reads_the_ascii_digits_after_an_optional_minus_sign(
    text: bytes, value: int
) -> None:
    assert to_integer(text, 32) == value


@pytest.mark.parametrize(
    ("text", "bits", "value"),
    [
        (b"2147483647", 32, 2147483647),
        (b"2147483648", 32, -2147483648),
        (b"-2147483648", 32, -2147483648),
        (b"-2147483649", 32, 2147483647),
        (b"4294967295", 32, -1),
        (b"4294967297", 32, 1),
        (b"-4294967296", 32, 0),
        (b"2147483648", 64, 2147483648),
        (b"9223372036854775808", 64, -9223372036854775808),
        (b"18446744073709551617", 64, 1),
    ],
)
def test_to_integer_wraps_a_number_outside_the_range_of_its_type(
    text: bytes, bits: int, value: int
) -> None:
    assert to_integer(text, bits) == value


@pytest.mark.parametrize(
    ("text", "value"),
    [
        (b"0", 0),
        (b"42", 42),
        (b"-42", -42),
        (b"9223372036854775807", 9223372036854775807),
        (b"-9223372036854775808", -9223372036854775808),
    ],
)
def test_to_integer_safe_reads_a_number_in_its_decimal_form(
    text: bytes, value: int
) -> None:
    assert to_integer_safe(text, 64) == value


@pytest.mark.parametrize(
    "text",
    [
        b"",
        b"-",
        b"-0",
        b"007",
        b"+5",
        b"5 ",
        b"12ab",
        b"2147483648",  # wraps to -2147483648
        b"1" * 21,  # longer than any number prints
    ],
)
def test_to_integer_safe_refuses_any_other_text(text: bytes) -> None:
    assert to_integer_safe(text, 32) is None
