import binascii

import pytest

from tdlib_oracle.tdutils.crypto import crc16


def test_crc16_gives_the_check_value_of_crc_16_xmodem() -> None:
    assert crc16(b"123456789") == 0x31C3


@pytest.mark.parametrize("data", [b"", b"\x00", b"\xff" * 34, bytes(range(256))])
def test_crc16_matches_crc_hqx_from_zero(data: bytes) -> None:
    assert crc16(data) == binascii.crc_hqx(data, 0)
