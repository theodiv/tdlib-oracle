import dataclasses

import pytest

from tdlib_oracle.text.failure import Failure


def test_failures_compare_by_code_and_message() -> None:
    assert Failure(400, "Text is too long") == Failure(400, "Text is too long")
    assert Failure(400, "Text is too long") != Failure(400, "Message is too long")
    assert Failure(400, "Text is too long") != Failure(403, "Text is too long")


def test_failure_is_immutable() -> None:
    failure = Failure(400, "Text is too long")
    with pytest.raises(dataclasses.FrozenInstanceError):
        failure.code = 403  # type: ignore[misc]  # frozen dataclass assignment
