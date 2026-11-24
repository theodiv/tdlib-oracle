from dataclasses import replace

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.message_entity import (
    TYPE,
    FormattedText,
    MessageEntity,
    parse_markdown_v2,
)


def _entities(text: bytes) -> tuple[MessageEntity, ...]:
    result = parse_markdown_v2(text)
    assert not isinstance(result, Failure), result
    return result.entities


@pytest.mark.parametrize("text", [b"\\\x00", b"\\\x7f"])
def test_keeps_a_backslash_before_nul_or_del_which_it_escapes_not(text: bytes) -> None:
    assert parse_markdown_v2(text) == FormattedText(text)


def test_counts_any_byte_from_0xf0_as_a_surrogate_pair() -> None:
    assert parse_markdown_v2(b"\xff_\xc3_") == FormattedText(
        b"\xff\xc3", (MessageEntity(TYPE.ITALIC, 2, 1),)
    )


def test_keeps_a_surrogate_that_the_text_holds_as_bytes() -> None:
    assert parse_markdown_v2(b"*\xed\xa0\x80*") == FormattedText(
        b"\xed\xa0\x80", (MessageEntity(TYPE.BOLD, 0, 1),)
    )


def test_counts_astral_and_combining_characters_in_utf16_units() -> None:
    text = "*\U0001f600e\U00000301*".encode()
    assert _entities(text) == (MessageEntity(TYPE.BOLD, 0, 4),)


def test_keeps_the_characters_that_cleaning_removes() -> None:
    text = "\x00\U0000200e\U0000202e".encode()
    assert parse_markdown_v2(b"*" + text + b"*") == FormattedText(
        text, (MessageEntity(TYPE.BOLD, 0, 3),)
    )


def test_reserves_only_a_backtick_inside_code() -> None:
    assert parse_markdown_v2(b"`*_[]()~>#+-=|{}.!`") == FormattedText(
        b"*_[]()~>#+-=|{}.!", (MessageEntity(TYPE.CODE, 0, 17),)
    )


def test_keeps_the_language_of_a_code_block_as_written() -> None:
    assert parse_markdown_v2(b"```a\\_b c```") == FormattedText(
        b" c", (MessageEntity(TYPE.PRE_CODE, 0, 2, b"a\\_b"),)
    )


@pytest.mark.parametrize("line_break", [b"\n", b"\r", b"\r\n", b"\n\r"])
def test_drops_one_line_break_at_the_start_of_a_code_block(line_break: bytes) -> None:
    assert parse_markdown_v2(b"```" + line_break + b"x```") == FormattedText(
        b"x", (MessageEntity(TYPE.PRE, 0, 1),)
    )


def test_takes_the_text_of_each_nested_link_without_a_url() -> None:
    assert parse_markdown_v2(b"[a[t\\.me]]") == FormattedText(
        b"at.me",
        (
            MessageEntity(TYPE.TEXT_URL, 0, 5, b"http://at.me/"),
            MessageEntity(TYPE.TEXT_URL, 1, 4, b"http://t.me/"),
        ),
    )


def test_keeps_a_link_to_an_invalid_user_as_a_link() -> None:
    assert _entities(b"[a](tg://user?id=0)") == (
        MessageEntity(TYPE.TEXT_URL, 0, 1, b"tg://user?id=0"),
    )


@pytest.mark.parametrize(
    ("text", "result"),
    [
        (b"![](tg://emoji?id=5)", FormattedText(b"")),
        (b"![](tg://time?unix=5)", FormattedText(b"")),
        (b"![](t.me)", Failure(400, "Invalid tg://emoji or tg://time URL specified")),
        (
            b"![](tg://emoji?id=5",
            Failure(400, "Can't find end of a URL at byte offset 4"),
        ),
        (b"[](tg://user?id=5)", FormattedText(b"")),
        (b"[](t.me", Failure(400, "Can't find end of a URL at byte offset 3")),
    ],
)
def test_checks_the_url_of_an_entity_around_no_text(
    text: bytes, result: FormattedText | Failure
) -> None:
    assert parse_markdown_v2(text) == result


@pytest.mark.parametrize(
    ("text", "result"),
    [
        (b"\\\n>a", FormattedText(b"\na", (MessageEntity(TYPE.BLOCK_QUOTE, 1, 1),))),
        (
            b"\n\\\r>a",
            FormattedText(b"\n\ra", (MessageEntity(TYPE.BLOCK_QUOTE, 2, 1),)),
        ),
        (
            b"\n\\a>b",
            Failure(
                400,
                "Character '>' is reserved and must be escaped with the preceding '\\'",
            ),
        ),
    ],
)
def test_reads_an_escaped_line_break_as_one_for_a_blockquote(
    text: bytes, result: FormattedText | Failure
) -> None:
    assert parse_markdown_v2(text) == result


@pytest.mark.parametrize("text", [b">*a", b">*a||", b">*a||\n"])
def test_refuses_an_entity_left_open_in_a_blockquote(text: bytes) -> None:
    assert parse_markdown_v2(text) == Failure(
        400, "Can't find end of Bold entity at byte offset 1"
    )


def test_marks_a_tie_of_links_nested_in_a_longer_entity() -> None:
    tie = (
        MessageEntity(TYPE.TEXT_URL, 1, 1, b"http://a.com/"),
        MessageEntity(TYPE.TEXT_URL, 1, 1, b"http://b.com/"),
    )
    assert _entities(b"_y[[x](a.com)](b.com)_") == (
        MessageEntity(TYPE.ITALIC, 0, 2),
        *(replace(entity, ties=tie) for entity in tie),
    )


def test_parses_a_text_far_over_the_bot_api_cap() -> None:
    text = b"a" * 100_000
    assert parse_markdown_v2(b"*" + text + b"*") == FormattedText(
        text, (MessageEntity(TYPE.BOLD, 0, 100_000),)
    )


def test_parses_5000_nested_links() -> None:
    text = b"[" * 5000 + b"t\\.me" + b"]" * 5000
    assert parse_markdown_v2(text) == FormattedText(
        b"t.me", (MessageEntity(TYPE.TEXT_URL, 0, 4, b"http://t.me/"),) * 5000
    )
