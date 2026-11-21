"""Reads of a string as C++ makes them, with the terminator after its last byte.

The pinned code reads the NUL that ends a C++ string like any other byte, so a port
reads `0` at the end of its input.
"""


def byte_at(text: bytes | bytearray, index: int) -> int:
    """Return the byte at `index` of `text`, or `0` past its end, as the terminator."""
    return text[index] if index < len(text) else 0
