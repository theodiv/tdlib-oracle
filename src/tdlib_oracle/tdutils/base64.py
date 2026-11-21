# Ported from tdutils/td/utils/base64.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""Base64 decoding of tdutils, in the standard alphabet and the URL-safe one."""

from tdlib_oracle.runtime.failure import Failure


# Ported from tdutils/td/utils/base64.cpp, get_characters().
def _get_characters(*, is_url: bool) -> bytes:
    if is_url:
        return b"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_"
    return b"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"


# Ported from tdutils/td/utils/base64.cpp, get_character_table().
def _get_character_table(*, is_url: bool) -> tuple[int, ...]:
    """Return the value of each byte in its alphabet, or 64 for a byte outside it."""
    char_to_value = [64] * 256
    for value, c in enumerate(_get_characters(is_url=is_url)):
        char_to_value[c] = value
    return tuple(char_to_value)


# Ported from tdutils/td/utils/base64.cpp, char_to_value in get_character_table(), the
# table each alphabet fills on its first call.
_CHARACTER_TABLE = _get_character_table(is_url=False)
_URL_CHARACTER_TABLE = _get_character_table(is_url=True)


# Ported from tdutils/td/utils/base64.cpp, base64_drop_padding().
def _base64_drop_padding(base64: bytes, *, is_url: bool) -> bytes | Failure:
    stripped = base64.rstrip(b"=")
    padding_length = len(base64) - len(stripped)
    if padding_length >= 3:
        return Failure(0, "Wrong string padding")
    if (not is_url or padding_length > 0) and (
        (len(stripped) + padding_length) & 3
    ) != 0:
        return Failure(0, "Wrong padding length")
    if is_url and (len(stripped) & 3) == 1:
        return Failure(0, "Wrong string length")
    return stripped


# Ported from tdutils/td/utils/base64.cpp, do_base64_decode_impl().
def _do_base64_decode_impl(base64: bytes, table: tuple[int, ...]) -> bytes | Failure:
    result = bytearray()
    i = 0
    while i < len(base64):
        left = min(len(base64) - i, 4)
        c = 0
        for t in range(left):
            value = table[base64[i]]
            i += 1
            if value == 64:
                return Failure(0, "Wrong character in the string")
            c |= value << ((3 - t) * 6)
        result.append((c >> 16) & 0xFF)
        if left == 2:
            if (c & ((1 << 16) - 1)) != 0:
                return Failure(0, "Wrong padding in the string")
        else:
            result.append((c >> 8) & 0xFF)
            if left == 3:
                if (c & ((1 << 8) - 1)) != 0:
                    return Failure(0, "Wrong padding in the string")
            else:
                result.append(c & 0xFF)
    return bytes(result)


# Ported from tdutils/td/utils/base64.cpp, base64_decode_impl().
def _base64_decode_impl(base64: bytes, *, is_url: bool) -> bytes | Failure:
    dropped = _base64_drop_padding(base64, is_url=is_url)
    if isinstance(dropped, Failure):
        return dropped
    return _do_base64_decode_impl(
        dropped, _URL_CHARACTER_TABLE if is_url else _CHARACTER_TABLE
    )


# Ported from tdutils/td/utils/base64.cpp, base64_decode(Slice base64).
def base64_decode(base64: bytes) -> bytes | Failure:
    """Return what `base64` encodes in the standard alphabet, or its `Failure`.

    `base64` needs `=` padding to a multiple of 4 characters, two `=` at most, and a
    last group that leaves no bits over.
    """
    return _base64_decode_impl(base64, is_url=False)


# Ported from tdutils/td/utils/base64.cpp, base64url_decode(Slice base64).
def base64url_decode(base64: bytes) -> bytes | Failure:
    """Return what `base64` encodes in the URL-safe alphabet, or its `Failure`.

    Padding is optional, but `=` must then fill the last group to 4 characters; a last
    group of one character, or one that leaves bits over, refuses `base64`.
    """
    return _base64_decode_impl(base64, is_url=True)


# Ported from tdutils/td/utils/base64.cpp, is_base64any_character().
def is_base64any_character(c: int) -> bool:
    """Return whether the byte `c` belongs to the base64 or the base64url alphabet."""
    return _CHARACTER_TABLE[c] != 64 or _URL_CHARACTER_TABLE[c] != 64
