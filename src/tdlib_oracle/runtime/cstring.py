"""Strings as C++ reads them: with a terminator after the last byte, and in slices."""

# Where a slice of a text starts and ends, in bytes, which a port returns where the C++
# returns a Slice of its input.
Span = tuple[int, int]


def byte_at(text: bytes | bytearray, index: int) -> int:
    """Return the byte at `index` of `text`, or `0` past its end, as the terminator."""
    return text[index] if index < len(text) else 0
