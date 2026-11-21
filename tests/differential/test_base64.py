from collections.abc import Callable
from pathlib import Path

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdutils.base64 import (
    base64_decode,
    base64url_decode,
    is_base64any_character,
)
from tests.support.harness import run
from tests.support.texts import draw_texts

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

Port = Callable[[bytes, tuple[int, ...]], tuple[bytes, ...]]

# Characters of both alphabets whose low bits a last group of 2 or 3 leaves over or
# not, the four that one alphabet holds and the other does not, padding, and bytes
# outside both alphabets.
_UNITS = (*(bytes([c]) for c in b"AEQgwBCD+/-_= \x00"), b"\xff", b"AAAA")

# Texts of each length up to a group and a half, with each amount of padding, and
# last groups that leave bits over.
_EDGES = (
    b"",
    b"=",
    b"==",
    b"===",
    b"====",
    b"A",
    b"AA",
    b"AAA",
    b"AAAA",
    b"A===",
    b"AA==",
    b"AAA=",
    b"AB==",
    b"AAB=",
    b"AQ",
    b"AAE",
    b"AAAAB",
    b"AAAAAQ==",
)


def _decode(decode: Callable[[bytes], bytes | Failure]) -> Port:
    def port(text: bytes, args: tuple[int, ...]) -> tuple[bytes, ...]:
        result = decode(text)
        if isinstance(result, Failure):
            return (b"0", str(result.code).encode(), result.message.encode(), b"")
        return (b"1", b"0", b"", result)

    return port


# Each decoder compared, by the name the harness gives it.
_FUNCTIONS: tuple[tuple[str, Port], ...] = (
    ("base64_decode", _decode(base64_decode)),
    ("base64url_decode", _decode(base64url_decode)),
)


@pytest.mark.parametrize(
    ("function", "port"), _FUNCTIONS, ids=[f for f, _ in _FUNCTIONS]
)
def test_decoders_give_the_pinned_result(
    compare: Compare, seeds: tuple[int, ...], count: int, function: str, port: Port
) -> None:
    for seed in seeds:
        cases = [(text, ()) for text in draw_texts(seed, count, _UNITS)]
        compare(function, port, cases, seed=seed, by_bytes=True)


@pytest.mark.parametrize(
    ("function", "port"), _FUNCTIONS, ids=[f for f, _ in _FUNCTIONS]
)
def test_decoders_give_the_pinned_result_at_the_edges(
    compare: Compare, function: str, port: Port
) -> None:
    cases = [(tuple(bytes([c]) for c in text), ()) for text in _EDGES]
    compare(function, port, cases, seed=None, by_bytes=True)


def test_is_base64any_character_gives_the_pinned_result_for_each_byte(
    harness: Path,
) -> None:
    pinned = run(
        harness,
        "is_base64any_character",
        [[bytes([byte])] for byte in range(256)],
        timeout=60,
    )
    flags = [(b"1" if is_base64any_character(c) else b"0",) for c in range(256)]
    assert pinned == flags
