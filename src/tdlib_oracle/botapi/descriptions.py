# Ported from telegram-bot-api/Client.cpp of the Telegram Bot API server at the commit
# in tdlib_oracle.BOT_API_COMMIT, and from tdutils/td/utils/misc.h of TDLib at the
# commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""The Bot API server's error descriptions."""

from tdlib_oracle.text.failure import Failure


# Ported from tdutils/td/utils/misc.h, to_lower(char c).
def _to_lower(c: str) -> str:
    if "A" <= c <= "Z":
        return chr(ord(c) - ord("A") + ord("a"))
    return c


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
    return f"{prefix}: {_to_lower(message[0])}{message[1:]}"
