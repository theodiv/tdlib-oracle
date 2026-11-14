import pytest

from tdlib_oracle.text.utf8 import (
    check_utf8,
    is_utf8_character_first_code_unit,
    utf8_length,
    utf8_truncate,
)


@pytest.mark.parametrize(
    "text",
    [
        b"",
        b"plain",
        b"\x00",
        "caf\N{LATIN SMALL LETTER E WITH ACUTE}".encode(),
        "\N{EURO SIGN}".encode(),
        "\U0001f600".encode(),
        "\U0000d7ff\U0000e000".encode(),
        b"\xf4\x8f\xbf\xbf",
    ],
)
def test_check_utf8_accepts_valid_utf8(text: bytes) -> None:
    assert check_utf8(text)


@pytest.mark.parametrize(
    "text",
    [
        b"\x80",  # a continuation byte alone
        b"\xc0\xaf",  # an overlong slash
        b"\xe0\x80\xaf",  # an overlong slash in 3 bytes
        b"\xed\xa0\x80",  # a high surrogate
        b"\xed\xbf\xbf",  # a low surrogate
        b"\xf4\x90\x80\x80",  # past U+10FFFF
        b"\xf5\x80\x80\x80",  # a lead byte no code point uses
        b"\xe2\x82",  # cut short
        b"caf\xe9",  # Latin-1
    ],
)
def test_check_utf8_refuses_invalid_utf8(text: bytes) -> None:
    assert not check_utf8(text)


@pytest.mark.parametrize(
    ("c", "expected"),
    [
        (0x00, True),
        (0x7F, True),
        (0x80, False),
        (0xBF, False),
        (0xC2, True),
        (0xFF, True),
    ],
)
def test_is_utf8_character_first_code_unit(c: int, expected: bool) -> None:
    assert is_utf8_character_first_code_unit(c) == expected


@pytest.mark.parametrize(
    ("text", "length"),
    [
        (b"", 0),
        (b"abc", 3),
        ("caf\N{LATIN SMALL LETTER E WITH ACUTE}".encode(), 4),
        ("a\U0001f600b".encode(), 3),
    ],
)
def test_utf8_length_counts_code_points(text: bytes, length: int) -> None:
    assert utf8_length(text) == length


@pytest.mark.parametrize(
    ("text", "length", "expected"),
    [
        (b"abc", 0, b""),
        (b"abc", 2, b"ab"),
        (b"abc", 3, b"abc"),
        (b"abc", 5, b"abc"),
        (
            "\N{LATIN SMALL LETTER E WITH ACUTE}\U0001f600x".encode(),
            2,
            "\N{LATIN SMALL LETTER E WITH ACUTE}\U0001f600".encode(),
        ),
        ("\U0001f600\U0001f600".encode(), 1, "\U0001f600".encode()),
    ],
)
def test_utf8_truncate_keeps_whole_code_points(
    text: bytes, length: int, expected: bytes
) -> None:
    assert utf8_truncate(text, length) == expected
