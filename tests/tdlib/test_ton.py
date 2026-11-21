import base64
import binascii

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.ton import check_ton_address

# A valid address, among TDLib's own (test/message_entities.cpp,
# TEST(MessageEntities, ton_address)).
_VALID = b"EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqB2N"


def _address(payload: bytes) -> bytes:
    """Return `payload` with its CRC-16, as base64url: an address with a right checksum.

    TDLib's CRC-16 is the one `binascii.crc_hqx` computes from 0.
    """
    checksum = binascii.crc_hqx(payload, 0).to_bytes(2, "big")
    return base64.urlsafe_b64encode(payload + checksum)


@pytest.mark.parametrize(
    "address",
    [
        _VALID,
        b"UQDqgkqefbZu_fZ7-8eib6h3vLubZxQfu-KRi829HBBUGzWm",
        b"UQDqgkqefbZu/fZ7+8eib6h3vLubZxQfu+KRi829HBBUGzWm",
        _address(b"\x51" + b"\x00" * 33),
    ],
)
def test_accepts_a_valid_address_in_either_alphabet(address: bytes) -> None:
    assert check_ton_address(address) is None


@pytest.mark.parametrize("address", [_VALID[:-1], _VALID + b"A", b""])
def test_refuses_an_address_of_another_length(address: bytes) -> None:
    assert check_ton_address(address) == Failure(400, "Invalid address length")


@pytest.mark.parametrize(
    "address",
    [
        _VALID[:45] + b"===",  # too much padding
        _VALID[:45] + b"B==",  # a last group of 2 with bits left over
        _VALID[:46] + b"B=",  # a last group of 3 with bits left over
    ],
)
def test_refuses_a_padded_address_that_does_not_decode(address: bytes) -> None:
    assert check_ton_address(address) == Failure(400, "Invalid address format")


def test_refuses_an_address_that_mixes_the_alphabets() -> None:
    address = b"UQDqgkqefbZu_fZ7+8eib6h3vLubZxQfu+KRi829HBBUGzWm"
    assert check_ton_address(address) == Failure(400, "Invalid address format")


def test_refuses_an_address_whose_checksum_differs() -> None:
    address = b"UQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqEBJ"
    assert check_ton_address(address) == Failure(400, "Invalid address checksum")


def test_refuses_an_address_whose_first_byte_lacks_the_tag() -> None:
    address = _address(b"\x00" * 34)
    assert check_ton_address(address) == Failure(400, "Invalid address first byte")
