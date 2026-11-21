import pytest

from tdlib_oracle.botapi.client import (
    get_error_description,
    get_formatted_text,
    get_input_message_text,
)
from tdlib_oracle.runtime.failure import Failure


def test_refuses_an_empty_text() -> None:
    assert get_input_message_text(b"") == Failure(400, "Message text is empty")


def test_passes_a_text_of_32768_bytes_on_unchanged() -> None:
    # The Bot API server neither cleans nor trims; TDLib does both later.
    text = b" \r\n" * 10922 + b"\r\r"
    assert len(text) == 32768
    assert get_input_message_text(text) == text


def test_refuses_a_text_of_32769_bytes() -> None:
    assert get_input_message_text(b"a" * 32769) == Failure(400, "Text is too long")


def test_get_formatted_text_checks_the_size_alone() -> None:
    # An empty text is refused before, by get_input_message_text().
    assert get_formatted_text(b"") == b""
    assert get_formatted_text(b"a" * 32769) == Failure(400, "Text is too long")


@pytest.mark.parametrize(
    ("failure", "description"),
    [
        (Failure(400, "Message text is empty"), "Bad Request: message text is empty"),
        (Failure(400, "MESSAGE_TOO_LONG"), "Bad Request: MESSAGE_TOO_LONG"),
        (Failure(400, "Bad Request: chat not found"), "Bad Request: chat not found"),
        (Failure(400, ""), "Bad Request"),
        (Failure(400, "X"), "Bad Request: x"),
        (
            Failure(400, "\N{LATIN CAPITAL LETTER E WITH ACUTE}lan"),
            "Bad Request: \N{LATIN CAPITAL LETTER E WITH ACUTE}lan",
        ),
        (Failure(200, "Some error"), "Bad Request: some error"),
        (Failure(404, "Not Found"), "Bad Request: not Found"),
        (Failure(403, "CHAT_WRITE_FORBIDDEN"), "Bad Request: CHAT_WRITE_FORBIDDEN"),
        (Failure(403, ""), "Bad Request"),
        (Failure(403, "Bot was blocked"), "Forbidden: bot was blocked"),
        (Failure(401, "Unauthorized"), "Unauthorized"),
        (Failure(500, "Request aborted"), "Internal Server Error: request aborted"),
        (Failure(406, "Some Error"), "Bad Request: Some Error"),
    ],
)
def test_describes_a_failure_as_the_bot_api_server_does(
    failure: Failure, description: str
) -> None:
    assert get_error_description(failure) == description
