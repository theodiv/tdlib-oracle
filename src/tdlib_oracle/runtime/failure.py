"""The error status a ported function returns instead of raising."""

from dataclasses import dataclass


@dataclass(frozen=True)
class Failure:
    """An error `Status` of the pinned code, as a value.

    A message can quote its input, which no exception may carry, so a ported function
    returns a `Failure` where the C++ returns an error `Status`.
    """

    code: int
    message: str


def decode_quoted(data: bytes) -> str:
    """Return `data` decoded as the text of a `Failure` message that quotes it.

    The pinned code quotes some input without checking that it is UTF-8, so each byte
    that does not decode becomes a lone surrogate, and the message encodes with
    `surrogateescape` to the bytes the pinned code writes.
    """
    return data.decode("utf-8", "surrogateescape")
