# Ported from td/telegram/InputMessageText.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's processing of an input message text."""

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api
from tdlib_oracle.tdlib.message_entity import FormattedText, get_formatted_text


# Ported from td/telegram/InputMessageText.cpp, process_input_message_text(), for a text
# without link preview options.
def process_input_message_text(text: td_api.FormattedText) -> FormattedText | Failure:
    """Return a bot's message text as TDLib keeps it, or the `Failure` refusing it."""
    return get_formatted_text(text, allow_empty=False, skip_trim=False)
