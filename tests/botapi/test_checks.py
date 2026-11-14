from tdlib_oracle.botapi.checks import get_input_message_text
from tdlib_oracle.text.failure import Failure


def test_refuses_an_empty_text() -> None:
    assert get_input_message_text(b"") == Failure(400, "Message text is empty")


def test_passes_a_text_of_32768_bytes_on_unchanged() -> None:
    # The Bot API server neither cleans nor trims; TDLib does both later.
    text = b" \r\n" * 10922 + b"\r\r"
    assert len(text) == 32768
    assert get_input_message_text(text) == text


def test_refuses_a_text_of_32769_bytes() -> None:
    assert get_input_message_text(b"a" * 32769) == Failure(400, "Text is too long")
