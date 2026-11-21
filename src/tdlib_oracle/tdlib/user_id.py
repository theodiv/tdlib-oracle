# Ported from td/telegram/UserId.h of TDLib at the commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's user IDs: the range a valid one lies in."""

# Ported from td/telegram/UserId.h, UserId::MAX_USER_ID.
MAX_USER_ID = (1 << 40) - 1


# Ported from td/telegram/UserId.h, UserId::is_valid().
def is_valid_user_id(user_id: int) -> bool:
    """Return whether `user_id` lies in the range of user IDs, from 1 to 2^40 - 1."""
    return 0 < user_id <= MAX_USER_ID
