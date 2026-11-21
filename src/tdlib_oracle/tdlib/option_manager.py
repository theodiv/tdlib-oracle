# Ported from td/telegram/OptionManager.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's options, at the defaults it gives them."""

# Ported from td/telegram/OptionManager.cpp, OptionManager::OptionManager(), its default
# for the option message_text_length_max, which Telegram's configuration may raise.
_MESSAGE_TEXT_LENGTH_MAX = 4096


# Ported from td/telegram/OptionManager.cpp, OptionManager::get_option_integer(), for
# the options a bot's text reads, without default_value, which their reads leave at 0.
def get_option_integer(name: bytes) -> int:
    """Return the integer option `name` at the default TDLib gives it, or `0` if none.

    Telegram's configuration may raise an option above its default, which nothing in a
    request shows, so the default stands for it.
    """
    if name == b"message_text_length_max":
        return _MESSAGE_TEXT_LENGTH_MAX
    return 0
