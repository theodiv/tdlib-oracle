from collections.abc import Callable
from pathlib import Path

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
from tests.support.harness import run
from tests.support.texts import draw_texts

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

Port = Callable[[bytes, tuple[int, ...]], tuple[bytes, ...]]

# The widths of the signed types the pinned code reads numbers into.
_WIDTHS = (32, 64)

# The pieces that reading a number tells apart: each digit; the minus sign it reads, and
# the plus sign, space, dot, letter, and NUL that end a number; a digit outside ASCII;
# and numbers at and past the bounds of each width.
_NUMBER_UNITS = tuple(
    piece.encode()
    for piece in (
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "-",
        "+",
        " ",
        ".",
        "a",
        "\x00",
        "\U00000663",  # Arabic-Indic digit three
        "2147483647",
        "2147483648",
        "4294967295",
        "4294967296",
        "9223372036854775807",
        "9223372036854775808",
        "18446744073709551615",
        "18446744073709551616",
    )
)

# Numbers at each bound of both widths and one past it, with either sign; numbers that
# wrap to small values; a lone or doubled sign, leading zeros, and stray characters;
# bytes that UTF-8 refuses, which get another error message from the C++; and runs of
# digits longer than any number prints.
_EDGES = (
    b"",
    b"-",
    b"+1",
    b"--1",
    b"0",
    b"-0",
    b"007",
    b"12a",
    b"1 2",
    b"\xff",
    b"12\xc3",
    b"2147483647",
    b"2147483648",
    b"-2147483648",
    b"-2147483649",
    b"4294967295",
    b"4294967296",
    b"4294967297",
    b"-4294967296",
    b"9223372036854775807",
    b"9223372036854775808",
    b"-9223372036854775808",
    b"-9223372036854775809",
    b"18446744073709551615",
    b"18446744073709551616",
    b"18446744073709551617",
    b"1" * 40,
    b"-" + b"9" * 30,
)


def _read(bits: int) -> Port:
    return lambda text, args: (str(to_integer(text, bits)).encode(),)


def _read_safely(bits: int) -> Port:
    def port(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
        value = to_integer_safe(text, bits)
        if value is None:
            return (b"0", b"")
        return (b"1", str(value).encode())

    return port


@pytest.mark.parametrize("bits", _WIDTHS)
def test_to_integer_gives_the_pinned_number(
    compare: Compare, seeds: tuple[int, ...], count: int, bits: int
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in draw_texts(seed, count, _NUMBER_UNITS)]
        compare(f"to_integer<int{bits}>", _read(bits), cases, seed=seed, by_bytes=True)


@pytest.mark.parametrize("bits", _WIDTHS)
def test_to_integer_gives_the_pinned_number_at_the_edges(
    compare: Compare, bits: int
) -> None:
    cases = [((text,), ()) for text in _EDGES]
    compare(f"to_integer<int{bits}>", _read(bits), cases, seed=None, by_bytes=True)


@pytest.mark.parametrize("bits", _WIDTHS)
def test_to_integer_safe_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int, bits: int
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in draw_texts(seed, count, _NUMBER_UNITS)]
        compare(
            f"to_integer_safe<int{bits}>",
            _read_safely(bits),
            cases,
            seed=seed,
            by_bytes=True,
        )


@pytest.mark.parametrize("bits", _WIDTHS)
def test_to_integer_safe_gives_the_pinned_result_at_the_edges(
    compare: Compare, bits: int
) -> None:
    cases = [((text,), ()) for text in _EDGES]
    compare(
        f"to_integer_safe<int{bits}>",
        _read_safely(bits),
        cases,
        seed=None,
        by_bytes=True,
    )


def _flag(value: bool) -> bytes:
    return b"1" if value else b"0"


# Each function of a byte compared, by the name the harness gives it, with the field the
# port answers it with.
_CODE_UNIT_FUNCTIONS: tuple[tuple[str, Callable[[int], bytes]], ...] = (
    ("is_space", lambda c: _flag(is_space(c))),
    ("is_alpha", lambda c: _flag(is_alpha(c))),
    ("is_digit", lambda c: _flag(is_digit(c))),
    ("is_alnum", lambda c: _flag(is_alnum(c))),
    ("is_hex_digit", lambda c: _flag(is_hex_digit(c))),
    ("hex_to_int", lambda c: str(hex_to_int(c)).encode()),
    ("to_lower", lambda c: bytes([to_lower(c)])),
)

# The bytes trimming tells apart: each space tdutils trims; a form feed, a no-break
# space, and an em space, which it keeps; and other characters and bytes.
_TRIM_UNITS = (
    *(bytes([c]) for c in b" \t\r\n\x00\x0b\x0c"),
    b"a",
    "\U000000a0".encode(),
    "\U00002003".encode(),
    b"\xff",
)

# An empty text, spaces alone, and spaces around a text at both ends.
_TRIM_EDGES = (b"", b" \t\r\n\x00\x0b", b" \x00a b\x0b\n")


@pytest.mark.parametrize(
    ("function", "port"), _CODE_UNIT_FUNCTIONS, ids=[f for f, _ in _CODE_UNIT_FUNCTIONS]
)
def test_byte_functions_give_the_pinned_result_for_each_byte(
    harness: Path, function: str, port: Callable[[int], bytes]
) -> None:
    pinned = run(harness, function, [[bytes([c])] for c in range(256)], timeout=60)
    assert pinned == [(port(c),) for c in range(256)]


def _trim(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    return (trim(text),)


def test_trim_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in draw_texts(seed, count, _TRIM_UNITS)]
        compare("trim", _trim, cases, seed=seed, by_bytes=True)


def test_trim_gives_the_pinned_result_at_the_edges(compare: Compare) -> None:
    cases = [(tuple(bytes([c]) for c in text), ()) for text in _TRIM_EDGES]
    compare("trim", _trim, cases, seed=None, by_bytes=True)
