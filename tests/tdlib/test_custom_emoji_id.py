import pytest

from tdlib_oracle.tdlib.custom_emoji_id import is_valid_custom_emoji_id


@pytest.mark.parametrize("custom_emoji_id", [1, -1, (1 << 63) - 1])
def test_accepts_any_id_but_0(custom_emoji_id: int) -> None:
    assert is_valid_custom_emoji_id(custom_emoji_id)


def test_refuses_0() -> None:
    assert not is_valid_custom_emoji_id(0)
