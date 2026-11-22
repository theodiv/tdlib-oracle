from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.input_message_text import process_input_message_text
from tdlib_oracle.tdlib.message_entity import TYPE, FormattedText, MessageEntity


def test_keeps_the_cleaned_and_trimmed_text() -> None:
    text = td_api.FormattedText(b" a\r\nb\t", ())
    assert process_input_message_text(text) == FormattedText(b"a\nb")


def test_moves_the_entities_with_the_trimmed_text() -> None:
    bold = td_api.TextEntity(1, 2, td_api.TextEntityTypeBold())
    text = td_api.FormattedText(b" ab ", (bold,))
    assert process_input_message_text(text) == FormattedText(
        b"ab", (MessageEntity(TYPE.BOLD, 0, 2),)
    )


def test_refuses_a_text_that_trimming_empties() -> None:
    text = td_api.FormattedText(b" \n", ())
    assert process_input_message_text(text) == Failure(400, "Text must be non-empty")


def test_leaves_the_length_limit_to_the_message_content() -> None:
    text = td_api.FormattedText(b"a" * 4097, ())
    assert process_input_message_text(text) == FormattedText(b"a" * 4097)
