from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.message_content import get_input_message_content
from tdlib_oracle.tdlib.message_entity import TYPE, FormattedText, MessageEntity


def _text(text: bytes, *entities: td_api.TextEntity) -> td_api.FormattedText:
    return td_api.FormattedText(text, entities)


def test_keeps_the_cleaned_and_trimmed_text() -> None:
    assert get_input_message_content(_text(b" a\r\nb\t")) == FormattedText(b"a\nb")


def test_keeps_the_entities_of_the_text() -> None:
    italic = td_api.TextEntity(0, 1, td_api.TextEntityTypeItalic())
    assert get_input_message_content(_text(b"ab", italic)) == FormattedText(
        b"ab", (MessageEntity(TYPE.ITALIC, 0, 1),)
    )


def test_accepts_4096_code_points() -> None:
    text = "\U0001f600".encode() * 4096
    assert get_input_message_content(_text(text)) == FormattedText(text)


def test_refuses_4097_code_points() -> None:
    result = get_input_message_content(_text(b"a" * 4097))
    assert result == Failure(400, "Message is too long")


def test_counts_the_length_after_trimming() -> None:
    result = get_input_message_content(_text(b"a" * 4096 + b"\n" * 100))
    assert result == FormattedText(b"a" * 4096)


def test_refuses_a_text_that_trimming_empties() -> None:
    result = get_input_message_content(_text(b" \n"))
    assert result == Failure(400, "Text must be non-empty")


def test_refuses_an_entity_with_a_wrong_value() -> None:
    emoji = td_api.TextEntity(0, 1, td_api.TextEntityTypeCustomEmoji(0))
    result = get_input_message_content(_text(b"a", emoji))
    assert result == Failure(400, "Invalid custom emoji identifier specified")
