import pytest

from tdlib_oracle.text.utf8 import (
    append_utf8_character,
    check_utf8,
    is_utf8_character_first_code_unit,
    next_utf8_unsafe,
    prev_utf8_unsafe,
    utf8_length,
    utf8_substr,
    utf8_to_lower,
    utf8_truncate,
    utf8_utf16_length,
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
    ("text", "length"),
    [
        (b"", 0),
        (b"abc", 3),
        ("caf\N{LATIN SMALL LETTER E WITH ACUTE}\N{EURO SIGN}".encode(), 5),
        ("a\U0001f600b".encode(), 4),
        (b"\x80", 0),  # a continuation byte alone
        (b"\xf5", 2),  # a lead byte no code point uses, read as one of 4 bytes
        (b"\xf8", 1),
    ],
)
def test_utf8_utf16_length_counts_utf16_code_units(text: bytes, length: int) -> None:
    assert utf8_utf16_length(text) == length


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


@pytest.mark.parametrize(
    ("character", "code"),
    [
        (b"a", 0x61),
        ("\N{LATIN SMALL LETTER E WITH ACUTE}".encode(), 0xE9),
        ("\N{EURO SIGN}".encode(), 0x20AC),
        ("\U0001f600".encode(), 0x1F600),
    ],
)
def test_next_utf8_unsafe_steps_over_one_character(character: bytes, code: int) -> None:
    text = b"<" + character + b">"
    assert next_utf8_unsafe(text, 1) == (1 + len(character), code)


def test_next_utf8_unsafe_reads_the_terminator_at_the_end() -> None:
    assert next_utf8_unsafe(b"ab", 2) == (3, 0)


def test_next_utf8_unsafe_stops_at_a_byte_no_character_starts_with() -> None:
    assert next_utf8_unsafe(b"\xf8", 0) == (0, 0)


def test_prev_utf8_unsafe_steps_back_over_one_character() -> None:
    text = "a\N{EURO SIGN}\U0001f600".encode()
    assert prev_utf8_unsafe(text, len(text)) == 4
    assert prev_utf8_unsafe(text, 4) == 1
    assert prev_utf8_unsafe(text, 1) == 0


@pytest.mark.parametrize(
    ("offset", "expected"),
    [
        (0, "a\N{EURO SIGN}\U0001f600"),
        (1, "\N{EURO SIGN}\U0001f600"),
        (2, "\U0001f600"),
        (3, ""),
        (4, ""),
    ],
)
def test_utf8_substr_drops_the_first_code_points(offset: int, expected: str) -> None:
    text = "a\N{EURO SIGN}\U0001f600".encode()
    assert utf8_substr(text, offset) == expected.encode()


def test_utf8_to_lower_lowers_each_code_point() -> None:
    text = "AbC \U00000410\U00000130\U00001e00\U00010400\U0001f600".encode()
    lowered = "abc \U00000430i\U00001e01\U00010428\U0001f600".encode()
    assert utf8_to_lower(text) == lowered


@pytest.mark.parametrize(
    ("code", "encoded"),
    [
        (0x00, b"\x00"),
        (0x7F, b"\x7f"),
        (0x80, b"\xc2\x80"),
        (0x7FF, b"\xdf\xbf"),
        (0x800, b"\xe0\xa0\x80"),
        (0xFFFF, b"\xef\xbf\xbf"),
        (0x10000, b"\xf0\x90\x80\x80"),
        (0x10FFFF, b"\xf4\x8f\xbf\xbf"),
        (0xD800, b"\xed\xa0\x80"),  # a surrogate, in the form UTF-8 refuses
    ],
)
def test_append_utf8_character_appends_the_utf8_form_of_a_code_point(
    code: int, encoded: bytes
) -> None:
    result = bytearray(b"x")
    append_utf8_character(result, code)
    assert result == b"x" + encoded
