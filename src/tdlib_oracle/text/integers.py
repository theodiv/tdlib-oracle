# Ported from tdutils/td/utils/misc.h of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""Integer conversions of tdutils: the number a decimal string writes.

Python's `int()` takes a plus sign, spaces, underscores, and digits of other scripts,
and keeps a number of any size. tdutils reads only ASCII digits after an optional minus
sign, into a C++ type whose range a larger number wraps around, and so does the port.
"""


# Ported from tdutils/td/utils/misc.h, to_integer(Slice str), for a signed type of
# `bits` bits.
def to_integer(text: bytes, bits: int) -> int:
    """Return the number `text` starts with, in a signed integer type of `bits` bits.

    The digits after an optional minus sign are read up to the first other byte, so a
    text without them reads 0, and a number outside the type's range wraps around it as
    in two's complement arithmetic.
    """
    mask = (1 << bits) - 1
    maximum = mask >> 1
    is_negative = text[:1] == b"-"
    pos = 1 if is_negative else 0
    value = 0
    while pos < len(text) and 0x30 <= text[pos] <= 0x39:  # '0' to '9'
        value = (value * 10 + text[pos] - 0x30) & mask  # wraps as the unsigned type
        pos += 1

    if value > maximum:
        value = (~value + 1) & mask
        is_negative = not is_negative
        if value > maximum:
            return -maximum - 1
    return -value if is_negative else value


# Ported from tdutils/td/utils/misc.h, to_integer_safe(), without its error message.
def to_integer_safe(text: bytes, bits: int) -> int | None:
    """Return the number `text` writes, or `None` unless `text` is its decimal form.

    The number is read as `to_integer` reads it at `bits` bits and printed back, so a
    plus sign, `-0`, a leading zero, any other byte, and a number past the type's range,
    which wraps to another value, each give `None` where the C++ returns an error.
    """
    # A value prints in at most 20 characters, so a longer text never matches it.
    if len(text) > 20:
        return None
    value = to_integer(text, bits)
    return value if str(value).encode() == text else None
