# Ported from td/telegram/MessageContent.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's creation of the content of a message text, through its length check."""

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.input_message_text import process_input_message_text
from tdlib_oracle.tdlib.option_manager import get_option_integer
from tdlib_oracle.tdutils.utf8 import utf8_length


# Ported from td/telegram/MessageContent.cpp, create_input_message_content(), its case
# of a message text.
def _create_input_message_content(text: bytes) -> bytes | Failure:
    result = process_input_message_text(text)
    if isinstance(result, Failure):
        return result
    # The pinned code reads the option through G(), which asks the OptionManager
    # (td/telegram/Global.cpp, Global::get_option_integer()).
    if utf8_length(result) > get_option_integer(b"message_text_length_max"):
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
