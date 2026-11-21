from tdlib_oracle.tdlib.option_manager import get_option_integer


def test_gives_the_default_length_limit_of_a_message_text() -> None:
    assert get_option_integer(b"message_text_length_max") == 4096


def test_gives_0_for_an_option_without_a_default() -> None:
    assert get_option_integer(b"no_such_option") == 0
