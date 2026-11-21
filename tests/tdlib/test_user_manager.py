import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.user_manager import get_input_user


@pytest.mark.parametrize("user_id", [1, 5, (1 << 40) - 1])
def test_get_input_user_lets_a_bot_name_any_valid_user(user_id: int) -> None:
    assert get_input_user(user_id) is None


@pytest.mark.parametrize("user_id", [0, -1, 1 << 40])
def test_get_input_user_refuses_an_invalid_user_id(user_id: int) -> None:
    assert get_input_user(user_id) == Failure(400, "User not found")
