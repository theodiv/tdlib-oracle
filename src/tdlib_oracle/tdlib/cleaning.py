# Ported from td/telegram/misc.cpp and tdutils/td/utils/misc.h of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's cleaning of input strings, and its test for a text of blank characters."""

from tdlib_oracle.text.utf8 import (
    check_utf8,
    is_utf8_character_first_code_unit,
    utf8_truncate,
)

# Ported from td/telegram/misc.cpp, LENGTH_LIMIT in clean_input_string().
_LENGTH_LIMIT = 35000  # server-side limit

# Ported from tdutils/td/utils/misc.h, is_space(), the characters it accepts.
_SPACES = b" \t\r\n\x00\x0b"

# Ported from td/telegram/misc.cpp, space_characters in strip_empty_characters(). Each
# space character takes 3 bytes.
_SPACE_CHARACTERS = tuple(
    chr(code_point).encode()
    for code_point in (
        0x1680,
        0x180E,
        0x2000,
        0x2001,
        0x2002,
        0x2003,
        0x2004,
        0x2005,
        0x2006,
        0x2007,
        0x2008,
        0x2009,
        0x200A,
        0x202E,
        0x202F,
        0x205F,
        0x2800,
        0x3000,
        0xFFFC,
    )
)

# Ported from td/telegram/misc.cpp, can_be_first in strip_empty_characters(). The byte
# 0xF3 can start a tag character, U+E0000 to U+E007F.
_CAN_BE_FIRST = frozenset(character[0] for character in _SPACE_CHARACTERS) | {0xF3}

# Ported from td/telegram/misc.cpp, strip_empty_characters(), its check for U+202E.
_RTLO = chr(0x202E).encode()


def _byte_at(text: bytes | bytearray, index: int) -> int:
    """Return the byte at `index`, or `0` past the end like the C++ terminator."""
    return text[index] if index < len(text) else 0


# Ported from tdutils/td/utils/misc.h, trim().
def _trim(text: bytes) -> bytes:
    return text.strip(_SPACES)


# Ported from td/telegram/misc.cpp, replace_offending_characters().
def _replace_offending_characters(text: bytearray) -> None:
    """Turn each U+200E or U+200F mark that another follows into U+200C, in place."""
    pos = 0
    while pos < len(text):
        if (
            text[pos] == 0xE2
            and _byte_at(text, pos + 1) == 0x80
            and _byte_at(text, pos + 2) in (0x8E, 0x8F)
        ):
            while (
                _byte_at(text, pos + 3) == 0xE2
                and _byte_at(text, pos + 4) == 0x80
                and _byte_at(text, pos + 5) in (0x8E, 0x8F)
            ):
                text[pos + 2] = 0x8C
                pos += 3
            pos += 2
        pos += 1


# Ported from td/telegram/misc.cpp, clean_input_string().
def clean_input_string(text: bytes) -> bytes | None:
    """Return `text` cleaned as TDLib cleans input strings, or `None` if not UTF-8.

    Control characters become spaces, except line feeds, which stay, and carriage
    returns, which are dropped along with U+2028 to U+202E and the combining marks
    U+030A, U+0333, and U+033F. In a run of U+200E and U+200F marks, each but the last
    becomes U+200C. The string is cut before the first character that starts at offset
    34,996 or later, so it stays under the 35,000-byte server-side limit.
    """
    if not check_utf8(text):
        return None

    result = bytearray()
    size = len(text)
    pos = 0
    while pos < size:
        c = text[pos]
        if c <= 0x20 and c not in (0x0A, 0x0D):
            result.append(0x20)
        elif c == 0x0D:
            pass  # a carriage return is dropped
        elif (
            c == 0xE2
            and pos + 2 < size
            and text[pos + 1] == 0x80
            and 0xA8 <= text[pos + 2] <= 0xAE
        ):
            pos += 2
        elif c == 0xCC and pos + 1 < size and text[pos + 1] in (0xB3, 0xBF, 0x8A):
            pos += 1
        else:
            result.append(c)
        if len(result) >= _LENGTH_LIMIT - 3 and (
            is_utf8_character_first_code_unit(result[-1])
        ):
            del result[-1]
            break
        pos += 1

    _replace_offending_characters(result)
    return bytes(result)


# Ported from td/telegram/misc.cpp, strip_empty_characters().
def strip_empty_characters(  # noqa: PLR0912  # mirrors upstream
    text: bytes, max_length: int, strip_rtlo: bool = False
) -> bytes:
    """Return `text` trimmed and cut to `max_length` code points, or empty if blank.

    Unicode spaces and tag characters become spaces first, and so does U+202E with
    `strip_rtlo`. The text is blank when nothing but spaces, line feeds, U+200B to
    U+200F, U+202E, U+FEFF, and U+00A0 is left.
    """
    replaced = bytearray()
    size = len(text)
    i = 0
    while i < size:
        c = text[i]
        if c in _CAN_BE_FIRST and i + 3 <= size:
            if c == 0xF3:
                if (
                    text[i + 1] == 0xA0
                    and (text[i + 2] & 0xFE) == 0x80
                    and i + 4 <= size
                ):
                    replaced.append(0x20)
                    i += 4
                    continue
            else:
                found = False
                for space in _SPACE_CHARACTERS:
                    if text[i : i + 3] == space:
                        found = space != _RTLO or strip_rtlo
                        break
                if found:
                    replaced.append(0x20)
                    i += 3
                    continue
        replaced.append(c)
        i += 1

    trimmed = _trim(utf8_truncate(_trim(bytes(replaced)), max_length))
    i = 0
    while i < len(trimmed):
        c = trimmed[i]
        if c in (0x20, 0x0A):
            i += 1
            continue
        if c == 0xE2 and _byte_at(trimmed, i + 1) == 0x80:
            following = _byte_at(trimmed, i + 2)
            if 0x8B <= following <= 0x8F or following == 0xAE:
                i += 3
                continue
        if (
            c == 0xEF
            and _byte_at(trimmed, i + 1) == 0xBB
            and _byte_at(trimmed, i + 2) == 0xBF
        ):
            i += 3
            continue
        if c == 0xC2 and _byte_at(trimmed, i + 1) == 0xA0:
            i += 2
            continue
        return trimmed
    return b""


# Ported from td/telegram/misc.cpp, is_empty_string().
def is_empty_string(text: bytes) -> bool:
    """Return whether `text` holds blank characters only."""
    return not strip_empty_characters(text, len(text))
