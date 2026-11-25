# Ported from td/telegram/UserManager.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's check of a user a bot names, and the object TDLib names that user by.

TDLib lets a bot name a user it has never met by the user's ID alone, so Telegram's
backend, not TDLib, decides whether a valid user can be named.
"""

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import telegram_api
from tdlib_oracle.tdlib.user_id import is_valid_user_id


# Ported from td/telegram/UserManager.cpp, UserManager::get_input_user(), for a bot.
def get_input_user(user_id: int) -> Failure | None:
    """Return the `Failure` refusing a bot's reference to `user_id`, or `None`.

    Only an invalid ID is refused, since no user carries one.
    """
    if is_valid_user_id(user_id):
        return None
    return Failure(400, "User not found")


# Ported from td/telegram/UserManager.cpp, UserManager::get_input_user_force(), for a
# bot and a user other than itself that it has not met.
def get_input_user_force(user_id: int) -> telegram_api.InputUser:
    """Return the object a bot names `user_id` by, with an access hash of `0`."""
    return telegram_api.InputUser(user_id, 0)
