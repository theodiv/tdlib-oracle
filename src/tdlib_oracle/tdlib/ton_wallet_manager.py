# Ported from td/telegram/TonWalletManager.cpp of TDLib at the commit
# in tdlib_oracle.TDLIB_COMMIT.
#
# Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com)
# 2014-2026. Distributed under the Boost Software License, Version 1.0;
# see LICENSES/BSL-1.0.txt.
"""TDLib's check of a TON address."""

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdutils.base64 import base64_decode, base64url_decode
from tdlib_oracle.tdutils.crypto import crc16


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
    decoded = base64url_decode(address)
    if isinstance(decoded, Failure):
        decoded = base64_decode(address)
    if isinstance(decoded, Failure):
        return Failure(400, "Invalid address format")
    actual_crc = crc16(decoded[:34])
    expected_crc = (decoded[34] << 8) | decoded[35]
    if actual_crc != expected_crc:
        return Failure(400, "Invalid address checksum")
    if (decoded[0] & 0x3F) != 0x11:
        return Failure(400, "Invalid address first byte")
    return None
