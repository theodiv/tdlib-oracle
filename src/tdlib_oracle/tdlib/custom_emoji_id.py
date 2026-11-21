# Ported from td/telegram/CustomEmojiId.h of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's custom emoji IDs: which ones are valid."""


# Ported from td/telegram/CustomEmojiId.h, CustomEmojiId::is_valid().
def is_valid_custom_emoji_id(custom_emoji_id: int) -> bool:
    """Return whether `custom_emoji_id` names a custom emoji: any ID but `0`."""
    return custom_emoji_id != 0
