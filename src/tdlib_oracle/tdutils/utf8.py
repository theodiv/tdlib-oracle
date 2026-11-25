# Ported from tdutils/td/utils/utf8.cpp and tdutils/td/utils/utf8.h of TDLib at the
# commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""UTF-8 helpers: validity, stepping, length, truncation, appending, and lowercasing."""

from tdlib_oracle.tdutils.unicode import unicode_to_lower


# Ported from tdutils/td/utils/utf8.cpp, check_utf8().
def check_utf8(text: bytes) -> bool:
    """Return whether `text` is valid UTF-8.

    Overlong encodings, surrogates, and code points past U+10FFFF are invalid.
    """
    # TDLib runs a DFA built from these transitions; Python's UTF-8 codec refuses
    # exactly the bytes it refuses, in one pass in C, which HTML and MarkdownV2 make for
    # the link of each nested link.
    # Stands in for tdutils/td/utils/utf8.cpp, get_utf8_transitions().
    try:
        text.decode()
    except UnicodeDecodeError:
        return False
    return True


# Ported from tdutils/td/utils/utf8.h, is_utf8_character_first_code_unit().
def is_utf8_character_first_code_unit(c: int) -> bool:
    """Return whether the byte `c` is the first byte of a UTF-8 character."""
    return (c & 0xC0) != 0x80


# Ported from tdutils/td/utils/utf8.h, utf8_length().
def utf8_length(text: bytes) -> int:
    """Return the length of `text` in code points."""
    return sum(is_utf8_character_first_code_unit(c) for c in text)


# Ported from tdutils/td/utils/utf8.cpp, utf8_utf16_length().
def utf8_utf16_length(text: bytes) -> int:
    """Return the length of `text` in UTF-16 code units.

    A byte from 0xF0 to 0xF7, which leads a 4-byte sequence, counts twice, for the
    surrogate pair that sequence takes in UTF-16.
    """
    return sum(
        is_utf8_character_first_code_unit(c) + ((c & 0xF8) == 0xF0) for c in text
    )


# Ported from tdutils/td/utils/utf8.h, utf8_truncate().
def utf8_truncate(text: bytes, length: int) -> bytes:
    """Return the first `length` code points of `text`."""
    if len(text) > length:
        for i, c in enumerate(text):
            if is_utf8_character_first_code_unit(c):
                if length == 0:
                    return text[:i]
                length -= 1
    return text


# Ported from tdutils/td/utils/utf8.cpp, next_utf8_unsafe().
def next_utf8_unsafe(text: bytes, pos: int) -> tuple[int, int]:
    """Return where the character at `pos` of `text` ends, and its code point.

    `text` must be valid UTF-8 and `pos` the start of a character, or the end of `text`,
    where the C++ reads the string terminator, a code point of 0.
    """
    a = text[pos] if pos < len(text) else 0
    if (a & 0x80) == 0:
        return pos + 1, a
    if (a & 0x20) == 0:
        return pos + 2, ((a & 0x1F) << 6) | (text[pos + 1] & 0x3F)
    if (a & 0x10) == 0:
        return pos + 3, (
            ((a & 0x0F) << 12) | ((text[pos + 1] & 0x3F) << 6) | (text[pos + 2] & 0x3F)
        )
    if (a & 0x08) == 0:
        return pos + 4, (
            ((a & 0x07) << 18)
            | ((text[pos + 1] & 0x3F) << 12)
            | ((text[pos + 2] & 0x3F) << 6)
            | (text[pos + 3] & 0x3F)
        )
    # Upstream stops at UNREACHABLE() here, which valid UTF-8 never reaches.
    return pos, 0


# Ported from tdutils/td/utils/utf8.h, prev_utf8_unsafe().
def prev_utf8_unsafe(text: bytes, pos: int) -> int:
    """Return where the character before `pos` of `text` starts.

    `text` must be valid UTF-8 and `pos` the start of a character after the first, or
    the end of `text`.
    """
    pos -= 1
    while not is_utf8_character_first_code_unit(text[pos]):
        pos -= 1
    return pos


# Ported from tdutils/td/utils/utf8.h, utf8_substr(T str, size_t offset).
def utf8_substr(text: bytes, offset: int) -> bytes:
    """Return `text` without its first `offset` code points."""
    if offset == 0:
        return text
    offset_pos = len(utf8_truncate(text, offset))
    return text[offset_pos:]


# Ported from tdutils/td/utils/utf8.h, append_utf8_character().
def append_utf8_character(result: bytearray, code: int) -> None:
    """Append the code point `code` to `result` in UTF-8.

    A code point takes 1 to 4 bytes, and a surrogate the 3-byte form that UTF-8 refuses.
    `code` must be a code point, at most U+10FFFF.
    """
    if code <= 0x7F:
        result.append(code)
    elif code <= 0x7FF:
        result += bytes((0xC0 | (code >> 6), 0x80 | (code & 0x3F)))
    elif code <= 0xFFFF:
        result += bytes(
            (0xE0 | (code >> 12), 0x80 | ((code >> 6) & 0x3F), 0x80 | (code & 0x3F))
        )
    else:
        result += bytes(
            (
                0xF0 | (code >> 18),
                0x80 | ((code >> 12) & 0x3F),
                0x80 | ((code >> 6) & 0x3F),
                0x80 | (code & 0x3F),
            )
        )


# Ported from tdutils/td/utils/utf8.cpp, utf8_to_lower().
def utf8_to_lower(text: bytes) -> bytes:
    """Return `text` with each code point in its lowercase form.

    `text` must be valid UTF-8.
    """
    result = bytearray()
    pos = 0
    while pos < len(text):
        pos, code = next_utf8_unsafe(text, pos)
        append_utf8_character(result, unicode_to_lower(code))
    return bytes(result)
