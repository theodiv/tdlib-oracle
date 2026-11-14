# Ported from test/string_cleaning.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.

from tdlib_oracle.tdlib.cleaning import clean_input_string, strip_empty_characters

_CONTROL_CHARACTERS = (
    b"\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13"
    b"\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f\x20\x21"
)


# Ported from test/string_cleaning.cpp, check_clean_input_string().
def _check_clean_input_string(
    text: bytes, expected: bytes, expected_result: bool
) -> None:
    result = clean_input_string(text)
    assert (result is not None) == expected_result
    if result is not None:
        assert result == expected


# Ported from test/string_cleaning.cpp, TEST(StringCleaning, clean_input_string).
def test_clean_input_string() -> None:
    _check_clean_input_string(b"/abc", b"/abc", True)
    _check_clean_input_string(b"a" * 50000, b"a" * 34996, True)
    _check_clean_input_string(b"\xff", b"", False)
    _check_clean_input_string(b"\xc0\x80", b"", False)
    _check_clean_input_string(b"\xd0", b"", False)
    _check_clean_input_string(b"\xe0\xaf", b"", False)
    _check_clean_input_string(b"\xf0\xa6", b"", False)
    _check_clean_input_string(b"\xf0\xa6\x88", b"", False)
    _check_clean_input_string(b"\xf4\x8f\xbf\xbf", b"\xf4\x8f\xbf\xbf", True)
    _check_clean_input_string(b"\xf4\x8f\xbf\xc0", b"", False)
    _check_clean_input_string(b"\r\r\r\r\r\r\r", b"", True)
    _check_clean_input_string(b"\r\n\r\n\r\n\r\n\r\n\r\n\r", b"\n\n\n\n\n\n", True)
    _check_clean_input_string(
        _CONTROL_CHARACTERS, b"          \x0a                     \x21", True
    )
    _check_clean_input_string(
        b"\xe2\x80\xa7\xe2\x80\xa8\xe2\x80\xa9\xe2\x80\xaa\xe2\x80\xab\xe2\x80\xac"
        b"\xe2\x80\xad\xe2\x80\xae\xe2\x80\xaf",
        b"\xe2\x80\xa7\xe2\x80\xaf",
        True,
    )
    _check_clean_input_string(
        b"\xe2\x80\x8f\xe2\x80\x8f  \xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8e\xe2\x80\x8c "
        b"\xe2\x80\x8f\xe2\x80\x8e \xe2\x80\x8f",
        b"\xe2\x80\x8c\xe2\x80\x8f  \xe2\x80\x8c\xe2\x80\x8c\xe2\x80\x8e\xe2\x80\x8c "
        b"\xe2\x80\x8c\xe2\x80\x8e \xe2\x80\x8f",
        True,
    )
    _check_clean_input_string(b"\xcc\xb3\xcc\xbf\xcc\x8a", b"", True)


# Ported from test/string_cleaning.cpp, check_strip_empty_characters().
def _check_strip_empty_characters(
    text: bytes, max_length: int, expected: bytes, strip_rtlo: bool = False
) -> None:
    assert strip_empty_characters(text, max_length, strip_rtlo) == expected


# Ported from test/string_cleaning.cpp, TEST(StringCleaning, strip_empty_characters).
def test_strip_empty_characters() -> None:
    _check_strip_empty_characters(b"/abc", 4, b"/abc")
    _check_strip_empty_characters(b"/abc", 3, b"/ab")
    _check_strip_empty_characters(b"/abc", 0, b"")
    _check_strip_empty_characters(b"/abc", 10000000, b"/abc")
    spaces = (
        "\U00001680\U0000180e\U00002000\U00002001\U00002002\U00002003\U00002004"
        "\U00002005\U00002006\U00002007\U00002008\U00002009\U0000200a\U0000202f"
        "\U0000205f\U00002800\U00003000\U0000fffc\U0000fffc"
    ).encode()
    spaces_replace = b"                   "
    rtlo = "\U0000202e".encode()
    empty = (
        b"\xe2\x80\x8b\xe2\x80\x8c\xe2\x80\x8d\xe2\x80\x8e\xe2\x80\x8f\xe2\x80\xae"
        b"\xc2\xa0\xc2\xa0"
    )

    _check_strip_empty_characters(spaces, 1000000, b"")
    _check_strip_empty_characters(spaces + rtlo, 1000000, b"")
    _check_strip_empty_characters(spaces + rtlo, 1000000, b"", True)
    _check_strip_empty_characters(spaces + rtlo + b"a", 1000000, rtlo + b"a")
    _check_strip_empty_characters(spaces + rtlo + b"a", 1000000, b"a", True)
    _check_strip_empty_characters(empty, 1000000, b"")
    _check_strip_empty_characters(empty + b"a", 1000000, empty + b"a")
    _check_strip_empty_characters(
        spaces + empty + spaces + b"abc" + spaces,
        1000000,
        empty + spaces_replace + b"abc",
    )
    _check_strip_empty_characters(
        spaces + spaces + empty + spaces + spaces + empty + empty, 1000000, b""
    )
    _check_strip_empty_characters(b"\r\r\r\r\r\r\r", 1000000, b"")
    _check_strip_empty_characters(b"\r\n\r\n\r\n\r\n\r\n\r\n\r", 1000000, b"")
    _check_strip_empty_characters(b" \t\r\n\x00\x0ba\x0b\x00\n\r\t ", 1000000, b"a")
    _check_strip_empty_characters(_CONTROL_CHARACTERS, 1000000, _CONTROL_CHARACTERS[1:])
    _check_strip_empty_characters(b"\xcc\xb3\xcc\xbf\xcc\x8a", 2, b"\xcc\xb3\xcc\xbf")
    _check_strip_empty_characters(
        b"\xe2\x80\xa7\xe2\x80\xa8\xe2\x80\xa9\xe2\x80\xaa\xe2\x80\xab\xe2\x80\xac"
        b"\xe2\x80\xad\xe2\x80\xae",
        3,
        b"\xe2\x80\xa7\xe2\x80\xa8\xe2\x80\xa9",
    )
    _check_strip_empty_characters(
        b"\xf3\x9f\xbf\xbf\xf3\xa0\x80\x80\xf3\xa0\x80\x81\xf3\xa0\x80\xbf"
        b"\xf3\xa0\x81\x80\xf3\xa0\x81\x81\xf3\xa0\x81\xbf\xf3\xa0\x82\x80",
        9,
        b"\xf3\x9f\xbf\xbf      \xf3\xa0\x82\x80",
    )
