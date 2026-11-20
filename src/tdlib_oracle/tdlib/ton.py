# Ported from td/telegram/TonWalletManager.cpp, tdutils/td/utils/base64.cpp, and
# tdutils/td/utils/crypto.cpp of TDLib at the commit in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's check of a TON address, with the base64 decoding and CRC-16 it reads."""

from tdlib_oracle.text.failure import Failure


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


# The tables that get_character_table() fills on its first call.
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
def _base64_decode(base64: bytes) -> bytes | Failure:
    return _base64_decode_impl(base64, is_url=False)


# Ported from tdutils/td/utils/base64.cpp, base64url_decode(Slice base64).
def _base64url_decode(base64: bytes) -> bytes | Failure:
    return _base64_decode_impl(base64, is_url=True)


# Ported from tdutils/td/utils/base64.cpp, is_base64any_character().
def is_base64any_character(c: int) -> bool:
    """Return whether the byte `c` belongs to the base64 or the base64url alphabet."""
    return _CHARACTER_TABLE[c] != 64 or _URL_CHARACTER_TABLE[c] != 64


# Ported from tdutils/td/utils/crypto.cpp, crc16_table. Kept in rows, since ruff format
# would give each value a line of its own.
# fmt: off
_CRC16_TABLE = (
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7, 0x8108, 0x9129,
    0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF, 0x1231, 0x0210, 0x3273, 0x2252,
    0x52B5, 0x4294, 0x72F7, 0x62D6, 0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C,
    0xF3FF, 0xE3DE, 0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
    0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D, 0x3653, 0x2672,
    0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4, 0xB75B, 0xA77A, 0x9719, 0x8738,
    0xF7DF, 0xE7FE, 0xD79D, 0xC7BC, 0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861,
    0x2802, 0x3823, 0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
    0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12, 0xDBFD, 0xCBDC,
    0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A, 0x6CA6, 0x7C87, 0x4CE4, 0x5CC5,
    0x2C22, 0x3C03, 0x0C60, 0x1C41, 0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B,
    0x8D68, 0x9D49, 0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
    0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78, 0x9188, 0x81A9,
    0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F, 0x1080, 0x00A1, 0x30C2, 0x20E3,
    0x5004, 0x4025, 0x7046, 0x6067, 0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C,
    0xE37F, 0xF35E, 0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D, 0x34E2, 0x24C3,
    0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405, 0xA7DB, 0xB7FA, 0x8799, 0x97B8,
    0xE75F, 0xF77E, 0xC71D, 0xD73C, 0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676,
    0x4615, 0x5634, 0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3, 0xCB7D, 0xDB5C,
    0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A, 0x4A75, 0x5A54, 0x6A37, 0x7A16,
    0x0AF1, 0x1AD0, 0x2AB3, 0x3A92, 0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B,
    0x9DE8, 0x8DC9, 0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
    0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8, 0x6E17, 0x7E36,
    0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0,
)
# fmt: on


# Ported from tdutils/td/utils/crypto.cpp, crc16().
def _crc16(data: bytes) -> int:
    crc = 0
    for c in data:
        t = (c ^ (crc >> 8)) & 0xFF
        crc = (_CRC16_TABLE[t] ^ (crc << 8)) & 0xFFFFFFFF  # an unsigned 32-bit integer
    return crc & 0xFFFF


# Ported from td/telegram/TonWalletManager.cpp, TonWalletManager::check_ton_address(),
# for allow_raw unset, as match_ton_addresses() in td/telegram/MessageEntity.cpp calls
# it.
def check_ton_address(address: bytes) -> Failure | None:
    """Return the `Failure` that refuses the TON address `address`, or `None` if valid.

    A valid address is 48 characters of base64url or base64 whose first decoded byte
    holds 0x11 in its low 6 bits and whose last 2 bytes are the CRC-16 of the 34 before.
    `address` must not decode with `=` padding: upstream stops at a failed check on such
    an address, and no run that `find_ton_addresses` checks holds `=`.
    """
    if len(address) != 48:
        return Failure(400, "Invalid address length")
    decoded = _base64url_decode(address)
    if isinstance(decoded, Failure):
        decoded = _base64_decode(address)
    if isinstance(decoded, Failure):
        return Failure(400, "Invalid address format")
    actual_crc = _crc16(decoded[:34])
    expected_crc = (decoded[34] << 8) | decoded[35]
    if actual_crc != expected_crc:
        return Failure(400, "Invalid address checksum")
    if (decoded[0] & 0x3F) != 0x11:
        return Failure(400, "Invalid address first byte")
    return None
