# Ported from td/telegram/FormattedDate.h and td/telegram/FormattedDate.cpp of TDLib at
# the commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's formatted dates: the parts of a date that a format string shows."""

from typing import Final

from tdlib_oracle.runtime.failure import Failure


# Ported from td/telegram/FormattedDate.h, FormattedDate::DateFlags.
class _DATE_FLAG:
    RELATIVE: Final = 1
    SHORT_TIME: Final = 2
    LONG_TIME: Final = 4
    SHORT_DATE: Final = 8
    LONG_DATE: Final = 16
    DAY_OF_WEEK: Final = 32


# Ported from td/telegram/FormattedDate.cpp, FormattedDate::get_date_flags().
def get_date_flags(date_format: bytes) -> int | Failure:
    """Return the flags of the parts of a date `date_format` shows, or its `Failure`.

    `r` or `R` alone shows the date relative to the present. Otherwise, each character
    adds a part: `t` or `T` the time, short or long, `d` or `D` the date, short or long,
    and `w` or `W` the day of the week, so an empty format shows none. Any other
    character refuses the format.
    """
    if date_format in (b"r", b"R"):
        return _DATE_FLAG.RELATIVE

    date_flags = 0
    for c in date_format:
        match c:
            case 0x74:  # 't'
                date_flags |= _DATE_FLAG.SHORT_TIME
            case 0x54:  # 'T'
                date_flags |= _DATE_FLAG.LONG_TIME
            case 0x64:  # 'd'
                date_flags |= _DATE_FLAG.SHORT_DATE
            case 0x44:  # 'D'
                date_flags |= _DATE_FLAG.LONG_DATE
            case 0x77 | 0x57:  # 'w', 'W'
                date_flags |= _DATE_FLAG.DAY_OF_WEEK
            case _:
                return Failure(400, "Invalid date format used")
    return date_flags
