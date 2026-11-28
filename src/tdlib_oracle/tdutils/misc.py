# Ported from tdutils/td/utils/misc.h of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""Character tests, ASCII lowercasing, trimming, and integer conversions of tdutils."""

# Ported from tdutils/td/utils/misc.h, is_space(), the characters it accepts.
_SPACES = b" \t\r\n\x00\x0b"


# Ported from tdutils/td/utils/misc.h, to_lower(char c).
def to_lower(c: int) -> int:
    """Return the character `c` in lowercase if it is an ASCII capital letter."""
    if 0x41 <= c <= 0x5A:  # 'A' to 'Z'
        return c - 0x41 + 0x61
    return c


# Ported from tdutils/td/utils/misc.h, is_space().
def is_space(c: int) -> bool:
    """Return whether the byte `c` is a space, a tab, CR, LF, NUL, or a vertical tab."""
    return c in _SPACES


# Ported from tdutils/td/utils/misc.h, is_alpha().
def is_alpha(c: int) -> bool:
    """Return whether the byte `c` is an ASCII letter."""
    return 0x61 <= (c | 0x20) <= 0x7A  # 'a' to 'z', in either case


# Ported from tdutils/td/utils/misc.h, is_digit().
def is_digit(c: int) -> bool:
    """Return whether the byte `c` is an ASCII digit."""
    return 0x30 <= c <= 0x39  # '0' to '9'


# Ported from tdutils/td/utils/misc.h, is_alnum().
def is_alnum(c: int) -> bool:
    """Return whether the byte `c` is an ASCII letter or digit."""
    return is_alpha(c) or is_digit(c)


# Ported from tdutils/td/utils/misc.h, is_hex_digit().
def is_hex_digit(c: int) -> bool:
    """Return whether the byte `c` is a hex digit, in either case."""
    return is_digit(c) or 0x61 <= (c | 0x20) <= 0x66  # 'a' to 'f', in either case


# Ported from tdutils/td/utils/misc.h, trim().
def trim(text: bytes) -> bytes:
    """Return `text` without the bytes `is_space` accepts at either end."""
    return text.strip(_SPACES)


# Ported from tdutils/td/utils/misc.h, to_integer(Slice str), for a signed type of
# `bits` bits.
def to_integer(text: bytes, bits: int) -> int:
    """Return the number `text` starts with, in a signed integer type of `bits` bits.

    It reads the ASCII digits after an optional minus sign up to the first other byte,
    so a text without them reads 0, and a number outside the type's range wraps around
    it as in two's complement arithmetic. Python's `int()` would also take a plus sign,
    spaces, underscores, and digits of other scripts, and keep a number of any size.
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

    A number outside the range of a signed integer of `bits` bits also gives `None`.
    """
    # A value prints in at most 20 characters, so a longer text never matches it.
    if len(text) > 20:
        return None
    value = to_integer(text, bits)
    return value if str(value).encode() == text else None


# Ported from tdutils/td/utils/misc.h, hex_to_int().
def hex_to_int(c: int) -> int:
    """Return the value of the hex digit `c`, or 16 if `c` is not one."""
    if is_digit(c):
        return c - 0x30
    c |= 0x20
    if 0x61 <= c <= 0x66:  # 'a' to 'f'
        return c - 0x61 + 10
    return 16
