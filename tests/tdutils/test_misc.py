import pytest

from tdlib_oracle.tdutils.misc import (
    hex_to_int,
    is_alnum,
    is_alpha,
    is_digit,
    is_hex_digit,
    is_space,
    to_integer,
    to_integer_safe,
    to_lower,
    trim,
)

_SPACES = b" \t\r\n\x00\x0b"


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


def test_to_lower_lowercases_the_ascii_capital_letters_only() -> None:
    lowered = bytes(to_lower(c) for c in range(256))
    assert lowered == bytes(range(256)).lower()


def test_to_lower_leaves_a_code_point_past_ascii() -> None:
    assert to_lower(ord("\U00000410")) == ord("\U00000410")  # Cyrillic capital A


def test_is_space_accepts_the_space_controls_and_nul_only() -> None:
    assert bytes(c for c in range(256) if is_space(c)) == bytes(sorted(_SPACES))


def test_character_tests_accept_ascii_only() -> None:
    letters = b"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    assert bytes(c for c in range(256) if is_alpha(c)) == letters
    assert bytes(c for c in range(256) if is_digit(c)) == b"0123456789"
    assert bytes(c for c in range(256) if is_alnum(c)) == b"0123456789" + letters
    assert bytes(c for c in range(256) if is_hex_digit(c)) == b"0123456789ABCDEFabcdef"


@pytest.mark.parametrize(
    ("c", "value"),
    [(ord("0"), 0), (ord("9"), 9), (ord("a"), 10), (ord("F"), 15)],
)
def test_hex_to_int_reads_a_hex_digit_in_either_case(c: int, value: int) -> None:
    assert hex_to_int(c) == value


@pytest.mark.parametrize("c", [ord("g"), ord("G"), ord("@"), ord("/"), 0, 0xC1])
def test_hex_to_int_gives_16_for_any_other_byte(c: int) -> None:
    assert hex_to_int(c) == 16


@pytest.mark.parametrize(
    ("text", "trimmed"),
    [
        (b"", b""),
        (_SPACES, b""),
        (_SPACES + b"a b" + _SPACES, b"a b"),
        (b"\x0ca\x0c", b"\x0ca\x0c"),  # a form feed is no space to tdutils
        ("\U00002003a".encode(), "\U00002003a".encode()),  # nor is an em space
    ],
)
def test_trim_drops_the_spaces_at_either_end(text: bytes, trimmed: bytes) -> None:
    assert trim(text) == trimmed
