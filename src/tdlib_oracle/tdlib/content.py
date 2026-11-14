# Ported from td/telegram/InputMessageText.cpp, td/telegram/MessageContent.cpp, and
# td/telegram/OptionManager.cpp of TDLib at the commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's processing of an input message text, through its length check."""

from tdlib_oracle.tdlib.fixing import get_formatted_text
from tdlib_oracle.text.failure import Failure
from tdlib_oracle.text.utf8 import utf8_length

# Ported from td/telegram/OptionManager.cpp, OptionManager::OptionManager(), its default
# for the option message_text_length_max, which Telegram's configuration may raise.
_MESSAGE_TEXT_LENGTH_MAX = 4096


# Ported from td/telegram/InputMessageText.cpp, process_input_message_text(), for a text
# without link preview options.
def _process_input_message_text(text: bytes) -> bytes | Failure:
    # Without a link preview URL, an empty text is refused and the text is trimmed.
    return get_formatted_text(text, allow_empty=False, skip_trim=False)


# Ported from td/telegram/MessageContent.cpp, create_input_message_content(), its case
# of a message text.
def _create_input_message_content(text: bytes) -> bytes | Failure:
    result = _process_input_message_text(text)
    if isinstance(result, Failure):
        return result
    if utf8_length(result) > _MESSAGE_TEXT_LENGTH_MAX:
        return Failure(400, "Message is too long")
    return result


# Ported from td/telegram/MessageContent.cpp, get_input_message_content(), for a
# message text.
def get_input_message_content(text: bytes) -> bytes | Failure:
    """Return the text TDLib keeps of a bot's message text, or its `Failure`.

    A message text has no file and no caption, so none of the steps before the content
    is created applies to it.
    """
    return _create_input_message_content(text)
