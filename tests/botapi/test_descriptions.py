import pytest

from tdlib_oracle.botapi.descriptions import get_error_description
from tdlib_oracle.text.failure import Failure


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
