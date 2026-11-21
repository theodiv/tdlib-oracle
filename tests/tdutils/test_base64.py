import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdutils.base64 import (
    base64_decode,
    base64url_decode,
    is_base64any_character,
)


@pytest.mark.parametrize(
    ("text", "expected"),
    [
        (b"", b""),
        (b"aGVsbG8h", b"hello!"),
        (b"aGVsbG8=", b"hello"),
        (b"aGVsbA==", b"hell"),
        (b"+/8=", b"\xfb\xff"),
    ],
)
def test_base64_decode_reads_the_standard_alphabet_with_padding(
    text: bytes, expected: bytes
) -> None:
    assert base64_decode(text) == expected


@pytest.mark.parametrize(
    ("text", "message"),
    [
        (b"aGVsbG8", "Wrong padding length"),
        (b"a===", "Wrong string padding"),
        (b"-_8=", "Wrong character in the string"),
        (b"aGVsbG9=", "Wrong padding in the string"),
        (b"aGVsbB==", "Wrong padding in the string"),
    ],
)
def test_base64_decode_refuses_missing_padding_other_characters_and_bits_left_over(
    text: bytes, message: str
) -> None:
    assert base64_decode(text) == Failure(0, message)


@pytest.mark.parametrize(
    ("text", "expected"),
    [
        (b"", b""),
        (b"aGVsbG8", b"hello"),
        (b"aGVsbG8=", b"hello"),
        (b"YQ", b"a"),
        (b"-_8", b"\xfb\xff"),
    ],
)
def test_base64url_decode_reads_the_url_safe_alphabet_with_padding_or_without(
    text: bytes, expected: bytes
) -> None:
    assert base64url_decode(text) == expected


@pytest.mark.parametrize(
    ("text", "message"),
    [
        (b"a", "Wrong string length"),
        (b"aGVsbG8==", "Wrong padding length"),
        (b"a===", "Wrong string padding"),
        (b"+/8=", "Wrong character in the string"),
        (b"aGVsbG9", "Wrong padding in the string"),
    ],
)
def test_base64url_decode_refuses_a_lone_character_bad_padding_and_bits_left_over(
    text: bytes, message: str
) -> None:
    assert base64url_decode(text) == Failure(0, message)


@pytest.mark.parametrize(
    ("c", "expected"),
    [
        (ord("A"), True),
        (ord("z"), True),
        (ord("0"), True),
        (ord("+"), True),
        (ord("/"), True),
        (ord("-"), True),
        (ord("_"), True),
        (ord("="), False),
        (ord(" "), False),
        (0xFF, False),
    ],
)
def test_is_base64any_character_takes_both_alphabets(c: int, expected: bool) -> None:
    assert is_base64any_character(c) == expected
