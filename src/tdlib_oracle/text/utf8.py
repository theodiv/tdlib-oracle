# Ported from tdutils/td/utils/utf8.cpp and tdutils/td/utils/utf8.h of TDLib at the
# commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""UTF-8 helpers of tdutils: validity, length in code points, and truncation."""

# Ported from tdutils/td/utils/utf8.cpp, the enum that opens with UTF8_REJECT: the
# states of the shift-based DFA that checks UTF-8 validity. The transitions by one byte
# are packed into one integer, which stores the next state for a state S in the 6 bits
# from bit S.
_UTF8_REJECT = 0  # zero, so that every unspecified transition leads to it
_UTF8_ACCEPT = 6
_UTF8_NEED_1 = 12  # 1 more continuation byte
_UTF8_NEED_2 = 18  # 2 more continuation bytes
_UTF8_NEED_3 = 24  # 3 more continuation bytes
_UTF8_AFTER_E0 = 30  # a continuation byte 0xa0-0xbf, then 1 more
_UTF8_AFTER_ED = 36  # a continuation byte 0x80-0x9f, then 1 more
_UTF8_AFTER_F0 = 42  # a continuation byte 0x90-0xbf, then 2 more
_UTF8_AFTER_F4 = 48  # a continuation byte 0x80-0x8f, then 2 more


# Ported from tdutils/td/utils/utf8.cpp, utf8_transition().
def _utf8_transition(from_state: int, to_state: int) -> int:
    return to_state << from_state


# Ported from tdutils/td/utils/utf8.cpp, get_utf8_transitions().
def _get_utf8_transitions(c: int) -> int:  # noqa: PLR0911, PLR0912  # mirrors upstream
    if c < 0x80:
        return _utf8_transition(_UTF8_ACCEPT, _UTF8_ACCEPT)
    if c < 0xC0:
        result = (
            _utf8_transition(_UTF8_NEED_1, _UTF8_ACCEPT)
            | _utf8_transition(_UTF8_NEED_2, _UTF8_NEED_1)
            | _utf8_transition(_UTF8_NEED_3, _UTF8_NEED_2)
        )
        if c < 0xA0:
            result |= _utf8_transition(_UTF8_AFTER_ED, _UTF8_NEED_1)
        else:
            result |= _utf8_transition(_UTF8_AFTER_E0, _UTF8_NEED_1)
        if c < 0x90:
            result |= _utf8_transition(_UTF8_AFTER_F4, _UTF8_NEED_2)
        else:
            result |= _utf8_transition(_UTF8_AFTER_F0, _UTF8_NEED_2)
        return result
    if c < 0xC2:
        return 0  # overlong encoding
    if c < 0xE0:
        return _utf8_transition(_UTF8_ACCEPT, _UTF8_NEED_1)
    if c == 0xE0:
        # Prevent overlong encoding.
        return _utf8_transition(_UTF8_ACCEPT, _UTF8_AFTER_E0)
    if c == 0xED:
        # Prevent surrogates.
        return _utf8_transition(_UTF8_ACCEPT, _UTF8_AFTER_ED)
    if c < 0xF0:
        return _utf8_transition(_UTF8_ACCEPT, _UTF8_NEED_2)
    if c == 0xF0:
        # Prevent overlong encoding.
        return _utf8_transition(_UTF8_ACCEPT, _UTF8_AFTER_F0)
    if c < 0xF4:
        return _utf8_transition(_UTF8_ACCEPT, _UTF8_NEED_3)
    if c == 0xF4:
        # Prevent code points after U+10FFFF.
        return _utf8_transition(_UTF8_ACCEPT, _UTF8_AFTER_F4)
    return 0


# Ported from tdutils/td/utils/utf8.cpp, Utf8Dfa.
_UTF8_DFA = tuple(_get_utf8_transitions(c) for c in range(256))


# Ported from tdutils/td/utils/utf8.cpp, check_utf8().
def check_utf8(text: bytes) -> bool:
    """Return whether `text` is valid UTF-8.

    Overlong encodings, surrogates, and code points past U+10FFFF are invalid.
    """
    state = _UTF8_ACCEPT
    for byte in text:
        state = _UTF8_DFA[byte] >> (state & 63)
    return (state & 63) == _UTF8_ACCEPT


# Ported from tdutils/td/utils/utf8.h, is_utf8_character_first_code_unit().
def is_utf8_character_first_code_unit(c: int) -> bool:
    """Return whether the byte `c` is the first byte of a UTF-8 character."""
    return (c & 0xC0) != 0x80


# Ported from tdutils/td/utils/utf8.h, utf8_length().
def utf8_length(text: bytes) -> int:
    """Return the length of `text` in code points."""
    return sum(is_utf8_character_first_code_unit(c) for c in text)


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
