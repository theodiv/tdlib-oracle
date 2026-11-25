# Ported from td/telegram/FormattedDate.h and td/telegram/FormattedDate.cpp of TDLib at
# the commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's formatted dates: their check, and their formats as flags and API objects."""

from typing import Final

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib import td_api, telegram_api


# Ported from td/telegram/FormattedDate.h, FormattedDate::DateFlags.
class DATE_FLAG:
    """The parts of a date that a formatted date shows, as TDLib's flags."""

    RELATIVE: Final = 1
    SHORT_TIME: Final = 2
    LONG_TIME: Final = 4
    SHORT_DATE: Final = 8
    LONG_DATE: Final = 16
    DAY_OF_WEEK: Final = 32


# Ported from td/telegram/FormattedDate.cpp, FormattedDate::FormattedDate(int32 date,
# bool relative, bool short_time, bool long_time, bool short_date, bool long_date, bool
# day_of_week), without its log of a date that is not positive.
def make_formatted_date(
    date: int,
    *,
    relative: bool,
    short_time: bool,
    long_time: bool,
    short_date: bool,
    long_date: bool,
    day_of_week: bool,
) -> tuple[int, int]:
    """Return the date and the flags of a formatted date that shows the parts named.

    A relative date shows no other part, and of a short and a long time, or of a short
    and a long date, only the short one shows. The date stays as it is, valid or not.
    """
    date_flags = 0
    if relative:
        date_flags = DATE_FLAG.RELATIVE
    else:
        if short_time:
            date_flags |= DATE_FLAG.SHORT_TIME
        elif long_time:
            date_flags |= DATE_FLAG.LONG_TIME
        if short_date:
            date_flags |= DATE_FLAG.SHORT_DATE
        elif long_date:
            date_flags |= DATE_FLAG.LONG_DATE
        if day_of_week:
            date_flags |= DATE_FLAG.DAY_OF_WEEK
    return date, date_flags


# Ported from td/telegram/FormattedDate.cpp, FormattedDate::get_formatted_date(int32
# date, const td_api::object_ptr<td_api::DateTimeFormattingType> &type_ptr).
def get_formatted_date(
    date: int, formatting_type: td_api.DateTimeFormattingType | None
) -> tuple[int, int] | Failure:
    """Return the date and the flags `formatting_type` gives it, or a `Failure`.

    The date must be positive. No formatting type shows no part of the date, a relative
    one shows the date relative to the present, and an absolute one shows each part its
    precision names, so a missing precision leaves the part out.
    """
    if date <= 0:
        return Failure(400, "Invalid date specified")

    date_flags = 0
    match formatting_type:
        case td_api.DateTimeFormattingTypeRelative():
            date_flags = DATE_FLAG.RELATIVE
        case td_api.DateTimeFormattingTypeAbsolute():
            match formatting_type.time_precision:
                case td_api.DateTimePartPrecisionShort():
                    date_flags |= DATE_FLAG.SHORT_TIME
                case td_api.DateTimePartPrecisionLong():
                    date_flags |= DATE_FLAG.LONG_TIME
            match formatting_type.date_precision:
                case td_api.DateTimePartPrecisionShort():
                    date_flags |= DATE_FLAG.SHORT_DATE
                case td_api.DateTimePartPrecisionLong():
                    date_flags |= DATE_FLAG.LONG_DATE
            if formatting_type.show_day_of_week:
                date_flags |= DATE_FLAG.DAY_OF_WEEK
    return date, date_flags


# Ported from td/telegram/FormattedDate.cpp, FormattedDate::get_date_flags().
def get_date_flags(date_format: bytes) -> int | Failure:
    """Return the flags of the parts of a date `date_format` shows, or its `Failure`.

    `r` or `R` alone shows the date relative to the present. Otherwise, each character
    adds a part: `t` or `T` the time, short or long, `d` or `D` the date, short or long,
    and `w` or `W` the day of the week, so an empty format shows none. Any other
    character refuses the format.
    """
    if date_format in (b"r", b"R"):
        return DATE_FLAG.RELATIVE

    date_flags = 0
    for c in date_format:
        match c:
            case 0x74:  # 't'
                date_flags |= DATE_FLAG.SHORT_TIME
            case 0x54:  # 'T'
                date_flags |= DATE_FLAG.LONG_TIME
            case 0x64:  # 'd'
                date_flags |= DATE_FLAG.SHORT_DATE
            case 0x44:  # 'D'
                date_flags |= DATE_FLAG.LONG_DATE
            case 0x77 | 0x57:  # 'w', 'W'
                date_flags |= DATE_FLAG.DAY_OF_WEEK
            case _:
                return Failure(400, "Invalid date format used")
    return date_flags


# Ported from td/telegram/FormattedDate.cpp,
# FormattedDate::get_date_time_formatting_type_object().
def get_date_time_formatting_type_object(
    date_flags: int,
) -> td_api.DateTimeFormattingType | None:
    """Return the formatting type that shows the parts of a date `date_flags` name.

    No flag gives `None`, and the flag of a relative date gives a relative type,
    whatever the others. Of a short and a long time, or of a short and a long date, the
    short one shows.
    """
    if date_flags == 0:
        return None
    if (date_flags & DATE_FLAG.RELATIVE) != 0:
        return td_api.DateTimeFormattingTypeRelative()

    time_precision: td_api.DateTimePartPrecision
    if (date_flags & DATE_FLAG.SHORT_TIME) != 0:
        time_precision = td_api.DateTimePartPrecisionShort()
    elif (date_flags & DATE_FLAG.LONG_TIME) != 0:
        time_precision = td_api.DateTimePartPrecisionLong()
    else:
        time_precision = td_api.DateTimePartPrecisionNone()

    date_precision: td_api.DateTimePartPrecision
    if (date_flags & DATE_FLAG.SHORT_DATE) != 0:
        date_precision = td_api.DateTimePartPrecisionShort()
    elif (date_flags & DATE_FLAG.LONG_DATE) != 0:
        date_precision = td_api.DateTimePartPrecisionLong()
    else:
        date_precision = td_api.DateTimePartPrecisionNone()

    show_day_of_week = (date_flags & DATE_FLAG.DAY_OF_WEEK) != 0
    return td_api.DateTimeFormattingTypeAbsolute(
        time_precision, date_precision, show_day_of_week
    )


# Ported from td/telegram/FormattedDate.cpp,
# FormattedDate::get_input_message_entity_formatted_date().
def get_input_message_entity_formatted_date(
    date: int, date_flags: int, offset: int, length: int
) -> telegram_api.MessageEntityFormattedDate:
    """Return the object TDLib sends the date in, with a field for each of its flags.

    The object stands from `offset` for `length` UTF-16 code units, and shows the parts
    of `date` that `date_flags` names.
    """
    return telegram_api.MessageEntityFormattedDate(
        0,
        (date_flags & DATE_FLAG.RELATIVE) != 0,
        (date_flags & DATE_FLAG.SHORT_TIME) != 0,
        (date_flags & DATE_FLAG.LONG_TIME) != 0,
        (date_flags & DATE_FLAG.SHORT_DATE) != 0,
        (date_flags & DATE_FLAG.LONG_DATE) != 0,
        (date_flags & DATE_FLAG.DAY_OF_WEEK) != 0,
        offset,
        length,
        date,
    )


# Ported from td/telegram/FormattedDate.h, FormattedDate::is_valid().
def is_valid_formatted_date(date: int) -> bool:
    """Return whether a formatted date at the Unix time `date` is valid.

    A valid date is positive, since `0`, the default, stands for no date.
    """
    return date > 0
