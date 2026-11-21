from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.input_message_text import process_input_message_text


def test_keeps_the_cleaned_and_trimmed_text() -> None:
    assert process_input_message_text(b" a\r\nb\t") == b"a\nb"


def test_refuses_a_text_that_trimming_empties() -> None:
    assert process_input_message_text(b" \n") == Failure(400, "Text must be non-empty")


def test_leaves_the_length_limit_to_the_message_content() -> None:
    assert process_input_message_text(b"a" * 4097) == b"a" * 4097
