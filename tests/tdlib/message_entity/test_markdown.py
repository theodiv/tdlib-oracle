from dataclasses import replace

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.message_entity import (
    TYPE,
    FormattedText,
    MessageEntity,
    parse_markdown,
    parse_markdown_v2,
)


def _entities(text: bytes) -> tuple[MessageEntity, ...]:
    result = parse_markdown_v2(text)
    assert not isinstance(result, Failure), result
    return result.entities


@pytest.mark.parametrize("character", [b"_", b"*", b"`", b"["])
def test_parse_markdown_keeps_a_character_a_backslash_escapes_as_text(
    character: bytes,
) -> None:
    assert parse_markdown(b"\\" + character) == FormattedText(character)


@pytest.mark.parametrize("text", [b"\\]", b"\\\\", b"\\a", b"\\\x00", b"\\"])
def test_parse_markdown_keeps_a_backslash_before_any_other_byte(text: bytes) -> None:
    assert parse_markdown(text) == FormattedText(text)


def test_parse_markdown_escapes_nothing_inside_an_entity() -> None:
    assert parse_markdown(b"*a\\*") == FormattedText(
        b"a\\", (MessageEntity(TYPE.BOLD, 0, 2),)
    )


@pytest.mark.parametrize(
    ("text", "result"),
    [
        (
            b"*a _b_ [c](t.me) `d`*",
            FormattedText(b"a _b_ [c](t.me) `d`", (MessageEntity(TYPE.BOLD, 0, 19),)),
        ),
        (
            b"`*a* _b_ [c]`",
            FormattedText(b"*a* _b_ [c]", (MessageEntity(TYPE.CODE, 0, 11),)),
        ),
    ],
)
def test_parse_markdown_keeps_the_markup_inside_an_entity_as_text(
    text: bytes, result: FormattedText
) -> None:
    assert parse_markdown(text) == result


@pytest.mark.parametrize(
    ("text", "offset"),
    [
        (b"ab*cd", 2),
        (b"[a", 0),
        (b"`", 0),
        (b"x```", 1),
        (b"```a```b`", 8),
        (b"_a\\_b_", 5),
    ],
)
def test_parse_markdown_refuses_an_entity_that_nothing_closes(
    text: bytes, offset: int
) -> None:
    assert parse_markdown(text) == Failure(
        400, f"Can't find end of the entity starting at byte offset {offset}"
    )


@pytest.mark.parametrize(
    ("text", "result"),
    [
        (b"", FormattedText(b"")),
        (b"**", FormattedText(b"")),
        (b"``````", FormattedText(b"")),
        (b"[](t.me)", FormattedText(b"(t.me)")),
    ],
)
def test_parse_markdown_gives_no_entity_around_no_text(
    text: bytes, result: FormattedText
) -> None:
    assert parse_markdown(text) == result


@pytest.mark.parametrize(
    ("text", "result"),
    [
        (
            b"[a](t.me/b)c",
            FormattedText(
                b"ac", (MessageEntity(TYPE.TEXT_URL, 0, 1, b"http://t.me/b"),)
            ),
        ),
        (
            b"[a](t.me",
            FormattedText(b"a", (MessageEntity(TYPE.TEXT_URL, 0, 1, b"http://t.me/"),)),
        ),
    ],
)
def test_parse_markdown_takes_a_url_up_to_the_next_parenthesis_or_the_end(
    text: bytes, result: FormattedText
) -> None:
    assert parse_markdown(text) == result


@pytest.mark.parametrize(
    ("text", "result"),
    [
        (
            b"[telegram.org]",
            FormattedText(
                b"telegram.org",
                (MessageEntity(TYPE.TEXT_URL, 0, 12, b"http://elegram.orgg/"),),
            ),
        ),
        (
            b"\\_\\_\\_[telegram.org]",
            FormattedText(
                b"___telegram.org",
                (MessageEntity(TYPE.TEXT_URL, 3, 12, b"http://gram.org.org/"),),
            ),
        ),
        (
            b"****[t.me]",
            FormattedText(
                b"t.me", (MessageEntity(TYPE.TEXT_URL, 0, 4, b"http://t.me/"),)
            ),
        ),
        (
            b"[ttg://user?id=55]",
            FormattedText(
                b"ttg://user?id=55",
                (MessageEntity(TYPE.MENTION_NAME, 0, 16, user_id=555),),
            ),
        ),
    ],
)
def test_parse_markdown_takes_the_text_shifted_by_the_dropped_bytes_as_a_url(
    text: bytes, result: FormattedText
) -> None:
    assert parse_markdown(text) == result


@pytest.mark.parametrize(
    ("url", "entities"),
    [
        (b"tg://user?id=5", (MessageEntity(TYPE.MENTION_NAME, 0, 1, user_id=5),)),
        (b"tg://user?id=0", (MessageEntity(TYPE.TEXT_URL, 0, 1, b"tg://user?id=0"),)),
        (b"a b", ()),
    ],
)
def test_parse_markdown_names_a_user_or_keeps_a_checked_link(
    url: bytes, entities: tuple[MessageEntity, ...]
) -> None:
    assert parse_markdown(b"[a](" + url + b")") == FormattedText(b"a", entities)


@pytest.mark.parametrize(
    ("text", "result"),
    [
        (
            b"```python code```",
            FormattedText(b" code", (MessageEntity(TYPE.PRE_CODE, 0, 5, b"python"),)),
        ),
        (
            b"```a\x00b```",
            FormattedText(b"\x00b", (MessageEntity(TYPE.PRE_CODE, 0, 2, b"a"),)),
        ),
        (b"```abc```", FormattedText(b"abc", (MessageEntity(TYPE.PRE, 0, 3),))),
        (
            b"```ab`\nc```",
            FormattedText(b"ab`\nc", (MessageEntity(TYPE.PRE, 0, 5),)),
        ),
    ],
)
def test_parse_markdown_names_the_language_of_a_code_block_up_to_a_space(
    text: bytes, result: FormattedText
) -> None:
    assert parse_markdown(text) == result


@pytest.mark.parametrize(
    ("line_break", "kept"),
    [(b"\n", b"x"), (b"\r", b"x"), (b"\r\n", b"x"), (b"\n\r", b"x"), (b"\n\n", b"\nx")],
)
def test_parse_markdown_drops_one_line_break_at_the_start_of_a_code_block(
    line_break: bytes, kept: bytes
) -> None:
    assert parse_markdown(b"```" + line_break + b"x```") == FormattedText(
        kept, (MessageEntity(TYPE.PRE, 0, len(kept)),)
    )


def test_parse_markdown_counts_any_byte_from_0xf0_as_a_surrogate_pair() -> None:
    assert parse_markdown(b"\xff_\xc3_") == FormattedText(
        b"\xff\xc3", (MessageEntity(TYPE.ITALIC, 2, 1),)
    )


def test_parse_markdown_keeps_a_surrogate_that_the_text_holds_as_bytes() -> None:
    assert parse_markdown(b"*\xed\xa0\x80*") == FormattedText(
        b"\xed\xa0\x80", (MessageEntity(TYPE.BOLD, 0, 1),)
    )


def test_parse_markdown_counts_astral_and_combining_characters_in_utf16_units() -> None:
    text = "\U0001f600e\U00000301".encode()
    assert parse_markdown(text + b"*" + text + b"*") == FormattedText(
        text * 2, (MessageEntity(TYPE.BOLD, 4, 4),)
    )


def test_parse_markdown_keeps_the_characters_that_cleaning_removes() -> None:
    text = "\x00\U0000200e\U0000202e".encode()
    assert parse_markdown(b"*" + text + b"*") == FormattedText(
        text, (MessageEntity(TYPE.BOLD, 0, 3),)
    )


def test_parse_markdown_parses_a_text_far_over_the_bot_api_cap() -> None:
    text = b"a" * 100_000
    assert parse_markdown(b"_" + text + b"_") == FormattedText(
        text, (MessageEntity(TYPE.ITALIC, 0, 100_000),)
    )


def test_parse_markdown_opens_one_link_at_5000_brackets() -> None:
    # The URL the text gives starts with brackets, which the link check refuses.
    text = b"[" * 5000 + b"t.me" + b"]" * 5000
    assert parse_markdown(text) == FormattedText(text[1:-1])


def test_parse_markdown_parses_5000_links() -> None:
    # From the third link on, the bytes dropped up to and including a link's `[`
    # outnumber those of its text, so each takes its own text as its URL.
    urls = (b"http://.mee/", b"http://e.me/", *(b"http://t.me/",) * 4998)
    assert parse_markdown(b"[t.me]" * 5000) == FormattedText(
        b"t.me" * 5000,
        tuple(
            MessageEntity(TYPE.TEXT_URL, 4 * index, 4, url)
            for index, url in enumerate(urls)
        ),
    )


@pytest.mark.parametrize("text", [b"\\\x00", b"\\\x7f"])
def test_parse_markdown_v2_keeps_a_backslash_before_nul_or_del_which_it_escapes_not(
    text: bytes,
) -> None:
    assert parse_markdown_v2(text) == FormattedText(text)


def test_parse_markdown_v2_counts_any_byte_from_0xf0_as_a_surrogate_pair() -> None:
    assert parse_markdown_v2(b"\xff_\xc3_") == FormattedText(
        b"\xff\xc3", (MessageEntity(TYPE.ITALIC, 2, 1),)
    )


def test_parse_markdown_v2_keeps_a_surrogate_that_the_text_holds_as_bytes() -> None:
    assert parse_markdown_v2(b"*\xed\xa0\x80*") == FormattedText(
        b"\xed\xa0\x80", (MessageEntity(TYPE.BOLD, 0, 1),)
    )


def test_parse_markdown_v2_counts_astral_and_combining_characters_in_utf16() -> None:
    text = "*\U0001f600e\U00000301*".encode()
    assert _entities(text) == (MessageEntity(TYPE.BOLD, 0, 4),)


def test_parse_markdown_v2_keeps_the_characters_that_cleaning_removes() -> None:
    text = "\x00\U0000200e\U0000202e".encode()
    assert parse_markdown_v2(b"*" + text + b"*") == FormattedText(
        text, (MessageEntity(TYPE.BOLD, 0, 3),)
    )


def test_parse_markdown_v2_reserves_only_a_backtick_inside_code() -> None:
    assert parse_markdown_v2(b"`*_[]()~>#+-=|{}.!`") == FormattedText(
        b"*_[]()~>#+-=|{}.!", (MessageEntity(TYPE.CODE, 0, 17),)
    )


def test_parse_markdown_v2_keeps_the_language_of_a_code_block_as_written() -> None:
    assert parse_markdown_v2(b"```a\\_b c```") == FormattedText(
        b" c", (MessageEntity(TYPE.PRE_CODE, 0, 2, b"a\\_b"),)
    )


@pytest.mark.parametrize("line_break", [b"\n", b"\r", b"\r\n", b"\n\r"])
def test_parse_markdown_v2_drops_one_line_break_at_the_start_of_a_code_block(
    line_break: bytes,
) -> None:
    assert parse_markdown_v2(b"```" + line_break + b"x```") == FormattedText(
        b"x", (MessageEntity(TYPE.PRE, 0, 1),)
    )


def test_parse_markdown_v2_takes_the_text_of_each_nested_link_without_a_url() -> None:
    assert parse_markdown_v2(b"[a[t\\.me]]") == FormattedText(
        b"at.me",
        (
            MessageEntity(TYPE.TEXT_URL, 0, 5, b"http://at.me/"),
            MessageEntity(TYPE.TEXT_URL, 1, 4, b"http://t.me/"),
        ),
    )


def test_parse_markdown_v2_keeps_a_link_to_an_invalid_user_as_a_link() -> None:
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
def test_parse_markdown_v2_checks_the_url_of_an_entity_around_no_text(
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
def test_parse_markdown_v2_reads_an_escaped_line_break_as_one_for_a_blockquote(
    text: bytes, result: FormattedText | Failure
) -> None:
    assert parse_markdown_v2(text) == result


@pytest.mark.parametrize("text", [b">*a", b">*a||", b">*a||\n"])
def test_parse_markdown_v2_refuses_an_entity_left_open_in_a_blockquote(
    text: bytes,
) -> None:
    assert parse_markdown_v2(text) == Failure(
        400, "Can't find end of Bold entity at byte offset 1"
    )


def test_parse_markdown_v2_marks_a_tie_of_links_nested_in_a_longer_entity() -> None:
    tie = (
        MessageEntity(TYPE.TEXT_URL, 1, 1, b"http://a.com/"),
        MessageEntity(TYPE.TEXT_URL, 1, 1, b"http://b.com/"),
    )
    assert _entities(b"_y[[x](a.com)](b.com)_") == (
        MessageEntity(TYPE.ITALIC, 0, 2),
        *(replace(entity, ties=tie) for entity in tie),
    )


def test_parse_markdown_v2_parses_a_text_far_over_the_bot_api_cap() -> None:
    text = b"a" * 100_000
    assert parse_markdown_v2(b"*" + text + b"*") == FormattedText(
        text, (MessageEntity(TYPE.BOLD, 0, 100_000),)
    )


def test_parse_markdown_v2_parses_5000_nested_links() -> None:
    text = b"[" * 5000 + b"t\\.me" + b"]" * 5000
    assert parse_markdown_v2(text) == FormattedText(
        b"t.me", (MessageEntity(TYPE.TEXT_URL, 0, 4, b"http://t.me/"),) * 5000
    )
