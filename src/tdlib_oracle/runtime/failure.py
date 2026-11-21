"""The error status a ported function returns instead of raising.

The pinned code refuses a request with an error `Status`: a code and a message. A
message can quote its input, which no exception may carry, so a ported function returns
a `Failure` where the C++ returns such a `Status`, and only `tdlib_oracle.server` turns
one into a refusal. `decode_quoted` gives the text of the input a message quotes.
"""

from dataclasses import dataclass


@dataclass(frozen=True)
class Failure:
    """An error `Status` of the pinned code, as a value.

    Attributes:
        code: The status code, such as `400`.
        message: The error message, worded as the pinned code words it.
    """

    code: int
    message: str


def decode_quoted(data: bytes) -> str:
    """Return `data` decoded as the text of a `Failure` message that quotes it.

    The pinned code quotes some input without checking that it is UTF-8, so each byte
    that does not decode becomes a lone surrogate, which `surrogateescape` turns back
    into that byte: the message encodes to the bytes the pinned code writes.
    """
    return data.decode("utf-8", "surrogateescape")
