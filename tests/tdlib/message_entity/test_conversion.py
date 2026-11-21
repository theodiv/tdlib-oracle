from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.message_entity import get_formatted_text

_NON_EMPTY = Failure(400, "Text must be non-empty")


def test_get_formatted_text_keeps_blanks_only_when_empty_is_allowed() -> None:
    blank = "\u200b".encode()
    assert get_formatted_text(blank, allow_empty=True, skip_trim=False) == blank
    assert get_formatted_text(blank, allow_empty=False, skip_trim=False) == _NON_EMPTY
