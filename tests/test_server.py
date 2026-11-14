from collections.abc import Callable

import pytest

from tdlib_oracle import Entity, Refusal, Verdict, check

_EMPTY = "Bad Request: message text is empty"
_TOO_LONG = "Bad Request: text is too long"
_NOT_UTF8 = "Bad Request: strings must be encoded in UTF-8"
_NON_EMPTY = "Bad Request: text must be non-empty"
_MESSAGE_TOO_LONG = "Bad Request: message is too long"

Sent = Callable[[str], str | bytes]


def _accepted(text: str) -> Verdict:
    return Verdict(
        accepted=True, text=text, entities=(), refusal=None, depends_on_backend=False
    )


def _refused(description: str) -> Verdict:
    return Verdict(
        accepted=False,
        text=None,
        entities=(),
        refusal=Refusal(description=description, offset=None),
        depends_on_backend=False,
    )


@pytest.fixture(params=["str", "bytes"])
def sent(request: pytest.FixtureRequest) -> Sent:
    if request.param == "str":
        return lambda text: text
    return lambda text: text.encode("utf-8", "surrogatepass")


def test_refuses_an_empty_text(sent: Sent) -> None:
    assert check(sent("")) == _refused(_EMPTY)


def test_accepts_32768_bytes_that_trimming_brings_to_4096_code_points(
    sent: Sent,
) -> None:
    assert check(sent("a" * 4096 + " " * (32768 - 4096))) == _accepted("a" * 4096)


@pytest.mark.parametrize("size", [32769, 1 << 20])
def test_refuses_a_text_over_32768_bytes_before_any_other_check(
    sent: Sent, size: int
) -> None:
    assert check(sent(" " * size)) == _refused(_TOO_LONG)


@pytest.mark.parametrize(
    "character",
    ["a", "\N{LATIN SMALL LETTER E WITH ACUTE}", "\N{EURO SIGN}", "\U0001f600"],
)
def test_accepts_4096_code_points_and_refuses_4097(sent: Sent, character: str) -> None:
    assert check(sent(character * 4096)) == _accepted(character * 4096)
    assert check(sent(character * 4097)) == _refused(_MESSAGE_TOO_LONG)


@pytest.mark.parametrize(
    "text",
    [
        b"\xff",
        b"\xc0\xaf",
        b"\xed\xa0\x80",
        b"abc\xe2\x82",
        "caf\N{LATIN SMALL LETTER E WITH ACUTE}".encode("latin-1"),
    ],
)
def test_refuses_bytes_that_are_not_utf8(text: bytes) -> None:
    assert check(text) == _refused(_NOT_UTF8)


@pytest.mark.parametrize("text", ["a\ud800b", "\udfff", "\U0000d83d\U0000de00"])
def test_refuses_surrogates(sent: Sent, text: str) -> None:
    assert check(sent(text)) == _refused(_NOT_UTF8)


@pytest.mark.parametrize(
    "text",
    [" ", "\n", " \n \n", "\r", "\r\n", "\t", "\x00", "\U00002028", "\U0000202e"],
)
def test_refuses_a_text_that_cleaning_and_trimming_empty(sent: Sent, text: str) -> None:
    assert check(sent(text)) == _refused(_NON_EMPTY)


@pytest.mark.parametrize(
    "text",
    [
        "\u200b",
        "\U0000200c",
        "\U0000200d",
        "\U0000200e",
        "\U0000200f",
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
        " \u200b \n\U000000a0 ",
    ],
)
def test_refuses_a_text_of_blank_characters(sent: Sent, text: str) -> None:
    assert check(sent(text)) == _refused(_NON_EMPTY)


@pytest.mark.parametrize("control", [chr(c) for c in range(32) if c not in (10, 13)])
def test_turns_a_control_character_into_a_space(sent: Sent, control: str) -> None:
    assert check(sent(f"a{control}b")) == _accepted("a b")


@pytest.mark.parametrize(
    "character",
    [
        "\r",
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
    ],
)
def test_drops_a_character_that_cleaning_removes(sent: Sent, character: str) -> None:
    assert check(sent(f"a{character}b")) == _accepted("ab")


def test_keeps_a_combining_mark_that_cleaning_leaves(sent: Sent) -> None:
    assert check(sent("e\U00000301")) == _accepted("e\U00000301")


def test_turns_each_mark_but_the_last_of_a_run_into_u200c(sent: Sent) -> None:
    assert check(sent("a\U0000200e\U0000200f\U0000200eb")) == _accepted(
        "a\U0000200c\U0000200c\U0000200eb"
    )


def test_trims_spaces_and_line_feeds_at_both_ends(sent: Sent) -> None:
    assert check(sent(" \n Total:\t42 \r\n")) == _accepted("Total: 42")


def test_keeps_a_realistic_bot_message(sent: Sent) -> None:
    message = (
        "Order #1042 confirmed \N{WHITE HEAVY CHECK MARK}\r\n\r\n"
        "Items: 2 \N{MULTIPLICATION SIGN} flat white\n"
        "Total: \N{EURO SIGN}7.40\n\n"
        "Reply /status for updates.  \n"
    )
    assert check(sent(message)) == _accepted(
        "Order #1042 confirmed \N{WHITE HEAVY CHECK MARK}\n\n"
        "Items: 2 \N{MULTIPLICATION SIGN} flat white\n"
        "Total: \N{EURO SIGN}7.40\n\n"
        "Reply /status for updates."
    )


@pytest.mark.parametrize("text", [bytearray(b"hi"), memoryview(b"hi"), None, 42])
def test_raises_type_error_for_any_other_type(text: object) -> None:
    with pytest.raises(TypeError, match=r"^text must be str or bytes, not "):
        check(text)  # type: ignore[arg-type]  # the wrong type is the point


def test_entity_fields_after_length_default_to_none_and_false() -> None:
    entity = Entity(type="bold", offset=0, length=4)
    optional = (
        entity.url,
        entity.user_id,
        entity.language,
        entity.custom_emoji_id,
        entity.unix_time,
        entity.date_time_format,
    )
    assert optional == (None,) * 6
    assert entity.depends_on_backend is False
