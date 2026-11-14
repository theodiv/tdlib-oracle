from tdlib_oracle.tdlib.fixing import fix_formatted_text, get_formatted_text
from tdlib_oracle.text.failure import Failure

_NON_EMPTY = Failure(400, "Text must be non-empty")


def _fix(
    text: bytes,
    *,
    allow_empty: bool = False,
    allow_empty_string: bool = False,
    skip_trim: bool = False,
) -> bytes | Failure:
    return fix_formatted_text(
        text,
        allow_empty=allow_empty,
        allow_empty_string=allow_empty_string,
        skip_trim=skip_trim,
    )


def test_refuses_invalid_utf8() -> None:
    assert _fix(b"\xff", allow_empty=True) == Failure(
        400, "Strings must be encoded in UTF-8"
    )


def test_refuses_nothing_but_spaces_and_line_feeds_unless_empty_is_allowed() -> None:
    assert _fix(b" \n ") == _NON_EMPTY
    assert _fix(b" \n ", allow_empty=True) == b""


def test_refuses_a_text_that_cleaning_empties() -> None:
    assert _fix(b"\r\r") == _NON_EMPTY


def test_trims_spaces_and_line_feeds_at_both_ends() -> None:
    assert _fix(b" \n a b \n ") == b"a b"


def test_keeps_both_ends_when_trimming_is_skipped() -> None:
    assert _fix(b" \n a b \n ", skip_trim=True) == b" \n a b \n "


def test_keeps_a_multibyte_character_at_the_end_whole() -> None:
    assert _fix("a\U0001f600 ".encode()) == "a\U0001f600".encode()


def test_refuses_blank_characters_unless_empty_is_allowed() -> None:
    blank = " \u200b\U000000a0 ".encode()
    assert _fix(blank) == _NON_EMPTY
    assert _fix(blank, allow_empty=True) == b""
    assert _fix(blank, allow_empty=True, allow_empty_string=True) == blank.strip()


def test_get_formatted_text_keeps_blanks_only_when_empty_is_allowed() -> None:
    blank = "\u200b".encode()
    assert get_formatted_text(blank, allow_empty=True, skip_trim=False) == blank
    assert get_formatted_text(blank, allow_empty=False, skip_trim=False) == _NON_EMPTY
