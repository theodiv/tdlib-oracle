import base64
import binascii
import random
from collections.abc import Callable

import pytest

from tdlib_oracle.tdlib.ton_wallet_manager import check_ton_address

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

_BASE64 = b"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
_BASE64URL = b"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_"

# The first bytes of a valid address: 0x11 in the low 6 bits, under each pair of high
# bits.
_TAGS = (0x11, 0x51, 0x91, 0xD1)

# Padded addresses that do not decode, the one kind of padding that upstream checks
# without stopping at a failed check: padding alone, too much padding, and a last group
# of 2 or 3 characters with bits left over.
_PADDED = (
    b"=" * 48,
    b"EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xq===",
    b"EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqB==",
    b"EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqBB=",
    b"EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqB-=",
)


def _check(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
    failure = check_ton_address(text)
    if failure is None:
        return (b"0", b"")
    return (str(failure.code).encode(), failure.message.encode())


def _address(rng: random.Random) -> bytes:
    """Return a valid address, a random payload with its CRC-16, in either alphabet.

    TDLib's CRC-16 is the one `binascii.crc_hqx` computes from 0.
    """
    payload = bytes([rng.choice(_TAGS)]) + rng.randbytes(33)
    data = payload + binascii.crc_hqx(payload, 0).to_bytes(2, "big")
    if rng.random() < 0.5:
        return base64.urlsafe_b64encode(data)
    return base64.standard_b64encode(data)


def _draw_addresses(seed: int, count: int) -> list[tuple[bytes, ...]]:
    """Return `count` addresses drawn from `seed`, each split into its characters.

    Half are valid; the others are valid ones with a character replaced from either
    alphabet, cut short, lengthened, or random characters of either alphabet or both.
    """
    rng = random.Random(f"{seed} addresses")
    addresses = []
    for _ in range(count):
        address = bytearray(_address(rng))
        match rng.randrange(8):
            case 0 | 1 | 2 | 3:
                pass
            case 4:
                address[rng.randrange(48)] = rng.choice(_BASE64 + b"-_")
            case 5:
                del address[rng.randrange(48)]
            case 6:
                address.insert(rng.randrange(49), rng.choice(_BASE64URL))
            case _:
                alphabet = rng.choice((_BASE64, _BASE64URL, _BASE64 + b"-_"))
                address = bytearray(rng.choice(alphabet) for _ in range(48))
        addresses.append(tuple(bytes([c]) for c in address))
    return addresses


def test_check_ton_address_gives_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = [(address, ()) for address in _draw_addresses(seed, count)]
        compare("check_ton_address", _check, cases, seed=seed, by_bytes=False)


def test_check_ton_address_gives_the_pinned_result_for_padding(
    compare: Compare,
) -> None:
    cases = [(tuple(bytes([c]) for c in address), ()) for address in _PADDED]
    compare("check_ton_address", _check, cases, seed=None, by_bytes=False)
