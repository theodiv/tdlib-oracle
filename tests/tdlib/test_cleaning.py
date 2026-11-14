import pytest

from tdlib_oracle.tdlib.cleaning import (
    clean_input_string,
    is_empty_string,
    strip_empty_characters,
)

_REMOVED = [
    "\U00002028",
    "\U00002029",
    "\U0000202a",
    "\U0000202b",
    "\U0000202c",
    "\U0000202d",
    "\U0000202e",
    "\U0000030a",
    "\U00000333",
    "\U0000033f",
]
_KEPT = ["\x7f", "\x85", "\U00000301", "\U00000332", "\U00002027", "\U0000202f"]


def test_clean_input_string_refuses_invalid_utf8() -> None:
    assert clean_input_string(b"caf\xe9") is None


@pytest.mark.parametrize("control", [c for c in range(32) if c not in (0x0A, 0x0D)])
def test_clean_input_string_turns_a_control_character_into_a_space(
    control: int,
) -> None:
    assert clean_input_string(b"a" + bytes([control]) + b"b") == b"a b"


def test_clean_input_string_keeps_line_feeds_and_drops_carriage_returns() -> None:
    assert clean_input_string(b"a\r\nb\r") == b"a\nb"


@pytest.mark.parametrize("character", _REMOVED)
def test_clean_input_string_drops_a_removed_character(character: str) -> None:
    assert clean_input_string(f"a{character}b".encode()) == b"ab"


@pytest.mark.parametrize("character", _KEPT)
def test_clean_input_string_keeps_characters_next_to_the_removed_ones(
    character: str,
) -> None:
    text = f"a{character}b".encode()
    assert clean_input_string(text) == text


def test_clean_input_string_turns_each_mark_but_the_last_of_a_run_into_u200c() -> None:
    text = "\U0000200e\U0000200f\U0000200ex \U0000200f\U0000200f".encode()
    assert (
        clean_input_string(text)
        == "\U0000200c\U0000200c\U0000200ex \U0000200c\U0000200f".encode()
    )


def test_clean_input_string_keeps_a_lone_mark_at_the_end() -> None:
    # The check for a following mark reads past the end, where the C++ reads the string
    # terminator (td/telegram/misc.cpp, replace_offending_characters()).
    assert clean_input_string("x\U0000200f".encode()) == "x\U0000200f".encode()


@pytest.mark.parametrize(
    ("character", "kept"),
    [("a", 34996), ("\N{EURO SIGN}", 11666), ("\U0001f600", 8749)],
)
def test_clean_input_string_cuts_before_the_character_at_offset_34996(
    character: str, kept: int
) -> None:
    text = (character * (36000 // len(character.encode()))).encode()
    assert clean_input_string(text) == (character * kept).encode()


def test_strip_empty_characters_turns_space_characters_into_spaces() -> None:
    assert strip_empty_characters("a\U00002003b\U000e0041c".encode(), 100) == b"a b c"


def test_strip_empty_characters_keeps_u202e_unless_told_to_strip_it() -> None:
    text = "a\U0000202eb".encode()
    assert strip_empty_characters(text, 100) == text
    assert strip_empty_characters(text, 100, strip_rtlo=True) == b"a b"


def test_strip_empty_characters_keeps_a_non_tag_character_starting_with_0xf3() -> None:
    text = "\U000f0000".encode()
    assert strip_empty_characters(text, 100) == text


def test_strip_empty_characters_trims_and_truncates() -> None:
    assert strip_empty_characters(b" \tabcdef \n", 3) == b"abc"


def test_strip_empty_characters_keeps_blank_characters_before_a_visible_one() -> None:
    text = "\u200b\U000000a0\U0000feffx".encode()
    assert strip_empty_characters(text, 100) == text


@pytest.mark.parametrize(
    "text",
    [
        "",
        " \n",
        "\u200b",
        "\U0000200c\U0000200d",
        "\U0000200e\U0000200f",
        "\U0000202e",
        "\U000000a0",
        "\U0000feff",
        "\U00001680",
        "\U0000180e",
        "\U00002000",
        "\U0000200a",
        "\U0000202f",
        "\U0000205f",
        "\U00002800",
        "\U00003000",
        "\U0000fffc",
        "\U000e0000",
        "\U000e007f",
    ],
)
def test_is_empty_string_finds_blank_characters_only(text: str) -> None:
    assert is_empty_string(text.encode())


@pytest.mark.parametrize("text", ["a", "\u200bx", "\U00002027", "\U000e0080"])
def test_is_empty_string_finds_a_visible_character(text: str) -> None:
    assert not is_empty_string(text.encode())
