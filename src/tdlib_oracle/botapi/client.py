# Ported from telegram-bot-api/Client.cpp of the Telegram Bot API server at the commit
# in tdlib_oracle.BOT_API_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""The Bot API server's checks on a text before TDLib, and its error descriptions."""

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdutils.misc import to_lower

# Ported from telegram-bot-api/Client.cpp, Client::get_formatted_text(), the limit it
# puts on a text.
_MAX_TEXT_SIZE = 1 << 15  # 32,768 bytes


# Ported from telegram-bot-api/Client.cpp, Client::get_formatted_text(), for a text
# without a parse mode or entities.
def get_formatted_text(text: bytes) -> bytes | Failure:
    """Return the text as the Bot API server passes it on, or the `Failure` refusing it.

    Without a parse mode or entities, only the size is checked: the server refuses a
    text over 32,768 bytes.
    """
    if len(text) > _MAX_TEXT_SIZE:
        return Failure(400, "Text is too long")
    return text


# Ported from telegram-bot-api/Client.cpp, Client::get_input_message_text(td::string
# text, ...), for a text without link preview options.
def get_input_message_text(text: bytes) -> bytes | Failure:
    """Return the text as the Bot API server passes it to TDLib, or its `Failure`."""
    if not text:
        return Failure(400, "Message text is empty")
    return get_formatted_text(text)


# Ported from telegram-bot-api/Client.cpp,
# Client::fail_query_with_error(PromisedQueryPtr query, int32 error_code, ...), without
# the rate-limit branch and the table of backend errors, which no check of a
# text reaches.
def get_error_description(failure: Failure) -> str:
    """Return the error description the Bot API server gives a client for `failure`."""
    code = failure.code
    message = failure.message
    if code < 400 or code == 404:
        code = 400
    elif code == 403 and all(
        c == "_" or "A" <= c <= "Z" or "0" <= c <= "9" for c in message
    ):
        code = 400

    match code:
        case 400:
            prefix = "Bad Request"
        case 401:
            prefix = "Unauthorized"
        case 403:
            prefix = "Forbidden"
        case 500:
            prefix = "Internal Server Error"
        case _:
            return f"Bad Request: {message}"

    if message.startswith(prefix):
        return message
    if not message:
        return prefix
    if len(message) >= 2 and (message[1] == "_" or "A" <= message[1] <= "Z"):
        return f"{prefix}: {message}"
    return f"{prefix}: {chr(to_lower(ord(message[0])))}{message[1:]}"
