# Ported from td/telegram/misc.cpp of TDLib at the commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's cleaning of input strings, and its test for a text of blank characters.

HTML cleans the link of each nested link again, so `clean_input_string` passes over a
string a fixed number of times in bytes methods and regular expressions; a Python loop
reads 4 of its bytes at most.
"""

import re

from tdlib_oracle.runtime.cstring import byte_at
from tdlib_oracle.tdutils.misc import trim
from tdlib_oracle.tdutils.utf8 import (
    check_utf8,
    is_utf8_character_first_code_unit,
    utf8_truncate,
)

# Ported from td/telegram/misc.cpp, LENGTH_LIMIT in clean_input_string().
_LENGTH_LIMIT = 35000  # server-side limit

# Ported from td/telegram/misc.cpp, clean_input_string(), the control characters it
# turns into spaces: each byte below 0x20 but the line feed, which it keeps, and the
# carriage return, which it drops.
_CONTROLS_TO_SPACES = bytes.maketrans(
    bytes(c for c in range(0x20) if c not in (0x0A, 0x0D)), b" " * 30
)

# Ported from td/telegram/misc.cpp, clean_input_string(), the characters it drops
# besides the carriage return: U+2028 to U+202E, and the vertical lines U+030A, U+0333,
# and U+033F. Each is a whole character of valid UTF-8, so dropping one never
# forms another.
_DROPPED_CHARACTERS = tuple(
    chr(code_point).encode()
    for code_point in (*range(0x2028, 0x202F), 0x030A, 0x0333, 0x033F)
)

# Ported from td/telegram/misc.cpp, replace_offending_characters(), the marks it
# replaces: each U+200E or U+200F that another follows. A match starts only at 0xE2,
# which no mark holds after its first byte, so the search finds each mark the C++ loop
# finds, in valid UTF-8 or not.
_OFFENDING_MARK = re.compile(rb"\xe2\x80[\x8e\x8f](?=\xe2\x80[\x8e\x8f])")

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


# Ported from td/telegram/misc.cpp, replace_offending_characters().
def replace_offending_characters(text: bytes) -> bytes:
    """Return `text` with each U+200E or U+200F mark that another follows as U+200C.

    Each mark and its replacement take 3 bytes, so the text keeps its length.
    """
    return _OFFENDING_MARK.sub(b"\xe2\x80\x8c", text)  # U+200C


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

    result = text.translate(_CONTROLS_TO_SPACES, b"\r")
    for character in _DROPPED_CHARACTERS:
        result = result.replace(character, b"")

    # The C++ checks the length after each byte it keeps, so it stops before the first
    # character that starts at offset LENGTH_LIMIT - 4 or later.
    end = _LENGTH_LIMIT - 4
    while end < len(result) and not is_utf8_character_first_code_unit(result[end]):
        end += 1

    return replace_offending_characters(result[:end])


# Ported from td/telegram/misc.cpp, strip_empty_characters().
def strip_empty_characters(
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

    trimmed = trim(utf8_truncate(trim(bytes(replaced)), max_length))
    i = 0
    while i < len(trimmed):
        c = trimmed[i]
        if c in (0x20, 0x0A):
            i += 1
            continue
        if c == 0xE2 and byte_at(trimmed, i + 1) == 0x80:
            following = byte_at(trimmed, i + 2)
            if 0x8B <= following <= 0x8F or following == 0xAE:
                i += 3
                continue
        if (
            c == 0xEF
            and byte_at(trimmed, i + 1) == 0xBB
            and byte_at(trimmed, i + 2) == 0xBF
        ):
            i += 3
            continue
        if c == 0xC2 and byte_at(trimmed, i + 1) == 0xA0:
            i += 2
            continue
        return trimmed
    return b""


# Ported from td/telegram/misc.cpp, is_empty_string().
def is_empty_string(text: bytes) -> bool:
    """Return whether `text` holds blank characters only."""
    return not strip_empty_characters(text, len(text))
