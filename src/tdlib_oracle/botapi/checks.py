# Ported from telegram-bot-api/Client.cpp of the Telegram Bot API server at the commit
# in tdlib_oracle.BOT_API_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""The Bot API server's checks on a text field before TDLib sees it."""

from tdlib_oracle.text.failure import Failure

_MAX_TEXT_SIZE = 1 << 15  # 32,768 bytes


# Ported from telegram-bot-api/Client.cpp, Client::get_formatted_text(), for a text
# without a parse mode or entities.
def _get_formatted_text(text: bytes) -> bytes | Failure:
    if len(text) > _MAX_TEXT_SIZE:
        return Failure(400, "Text is too long")
    return text


# Ported from telegram-bot-api/Client.cpp, Client::get_input_message_text(td::string
# text, ...), for a text without link preview options.
def get_input_message_text(text: bytes) -> bytes | Failure:
    """Return the text as the Bot API server passes it to TDLib, or its `Failure`."""
    if not text:
        return Failure(400, "Message text is empty")
    return _get_formatted_text(text)
