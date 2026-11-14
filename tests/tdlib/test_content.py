from tdlib_oracle.tdlib.content import get_input_message_content
from tdlib_oracle.text.failure import Failure


def test_keeps_the_cleaned_and_trimmed_text() -> None:
    assert get_input_message_content(b" a\r\nb\t") == b"a\nb"


def test_accepts_4096_code_points() -> None:
    text = "\U0001f600".encode() * 4096
    assert get_input_message_content(text) == text


def test_refuses_4097_code_points() -> None:
    assert get_input_message_content(b"a" * 4097) == Failure(400, "Message is too long")


def test_counts_the_length_after_trimming() -> None:
    assert get_input_message_content(b"a" * 4096 + b"\n" * 100) == b"a" * 4096


def test_refuses_a_text_that_trimming_empties() -> None:
    assert get_input_message_content(b" \n") == Failure(400, "Text must be non-empty")
