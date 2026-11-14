"""The error status a ported function returns instead of raising.

The pinned code refuses a request with an error `Status`: a code and a message. A
message can quote its input, which no exception may carry, so a ported function returns
a `Failure` where the C++ returns such a `Status`, and only the composition module turns
one into a refusal.
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
