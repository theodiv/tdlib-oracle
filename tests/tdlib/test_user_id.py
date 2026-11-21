import pytest

from tdlib_oracle.tdlib.user_id import is_valid_user_id


@pytest.mark.parametrize("user_id", [1, 777, (1 << 40) - 1])
def test_is_valid_user_id_accepts_ids_from_1_up_to_the_limit(user_id: int) -> None:
    assert is_valid_user_id(user_id)


@pytest.mark.parametrize("user_id", [0, -1, 1 << 40])
def test_is_valid_user_id_refuses_0_negatives_and_ids_past_the_limit(
    user_id: int,
) -> None:
    assert not is_valid_user_id(user_id)
