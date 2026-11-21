"""Strings as C++ reads them: with a terminator after the last byte, and in slices.

The pinned code reads the NUL that ends a C++ string like any other byte, so a port
reads `0` at the end of its input. Where the C++ returns a `Slice` of its input, a port
returns where the slice starts and ends, as a `Span`.
"""

# Where a slice of a text starts and ends, in bytes.
Span = tuple[int, int]


def byte_at(text: bytes | bytearray, index: int) -> int:
    """Return the byte at `index` of `text`, or `0` past its end, as the terminator."""
    return text[index] if index < len(text) else 0
