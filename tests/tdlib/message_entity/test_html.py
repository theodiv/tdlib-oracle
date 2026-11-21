from dataclasses import replace

import pytest

from tdlib_oracle.runtime.failure import Failure
from tdlib_oracle.tdlib.message_entity import (
    TYPE,
    FormattedText,
    MessageEntity,
    parse_html,
)

_SURROGATE = Failure(
    400,
    "Text contains invalid Unicode characters after decoding HTML entities, check for"
    " unmatched surrogate code units",
)


def _entities(text: bytes) -> tuple[MessageEntity, ...]:
    result = parse_html(text)
    assert not isinstance(result, Failure), result
    return result.entities


def test_keeps_a_text_without_tags() -> None:
    assert parse_html(b"a b\n") == FormattedText(b"a b\n")


def test_parses_an_empty_text() -> None:
    assert parse_html(b"") == FormattedText(b"")


def test_decodes_the_four_named_references() -> None:
    assert parse_html(b"&lt;&gt;&amp;&quot;") == FormattedText(b'<>&"')


@pytest.mark.parametrize(
    "text", [b"&nbsp;", b"&LT;", b"&ltx;", b"&", b"&;", b"&#;", b"&#x;", b"&#xg;"]
)
def test_keeps_a_reference_it_does_not_decode(text: bytes) -> None:
    assert parse_html(text) == FormattedText(text)


def test_decodes_a_reference_without_its_semicolon() -> None:
    assert parse_html(b"&lt1&#65b&#x41g") == FormattedText(b"<1AbAg")


@pytest.mark.parametrize(
    ("text", "decoded"),
    [
        (b"&#65;", b"A"),
        (b"&#x41;", b"A"),
        (b"&#X41;", b"A"),
        (b"&#x1F600;", "\U0001f600".encode()),
        (b"&#1114110;", "\U0010fffe".encode()),
        (b"&#x10fffe;", "\U0010fffe".encode()),
        (b"&#0000065;", b"A"),
        (b"&#x000041;", b"A"),
    ],
)
def test_decodes_a_numeric_reference(text: bytes, decoded: bytes) -> None:
    assert parse_html(text) == FormattedText(decoded)


@pytest.mark.parametrize(
    "text",
    [
        b"&#0;",
        b"&#1114111;",  # U+10FFFF
        b"&#x10FFFF;",
        b"&#00000065;",  # 10 characters from the ampersand
        b"&#x0000041;",
        b"&#4294967361;",  # 65 once wrapped around 32 bits, but too long
    ],
)
def test_keeps_a_numeric_reference_out_of_range(text: bytes) -> None:
    assert parse_html(text) == FormattedText(text)


def test_counts_a_decoded_astral_character_as_two_utf16_units() -> None:
    assert _entities(b"<b>&#x1f600;</b>") == (MessageEntity(TYPE.BOLD, 0, 2),)


def test_refuses_a_surrogate_decoded_in_the_text() -> None:
    # Each half of a pair is decoded on its own, so a pair is refused too.
    assert parse_html(b"&#xd83d;&#xde00;") == _SURROGATE


def test_keeps_a_surrogate_decoded_in_an_attribute() -> None:
    assert _entities(b'<a href="t.me/&#xd800;">x</a>') == (
        MessageEntity(TYPE.TEXT_URL, 0, 1, b"http://t.me/\xed\xa0\x80"),
    )


def test_keeps_a_surrogate_that_the_text_holds_as_bytes() -> None:
    assert parse_html(b"<b>\xed\xa0\x80</b>") == FormattedText(
        b"\xed\xa0\x80", (MessageEntity(TYPE.BOLD, 0, 1),)
    )


def test_counts_any_byte_from_0xf0_as_a_surrogate_pair() -> None:
    assert parse_html(b"\xff<i>\xc3</i>") == FormattedText(
        b"\xff\xc3", (MessageEntity(TYPE.ITALIC, 2, 1),)
    )


def test_counts_astral_and_combining_characters_in_utf16_units() -> None:
    text = "<b>\U0001f600e\U00000301</b>".encode()
    assert _entities(text) == (MessageEntity(TYPE.BOLD, 0, 4),)


def test_keeps_the_characters_that_cleaning_removes() -> None:
    text = "\x00\U0000200e\U0000202e".encode()
    assert parse_html(b"<b>" + text + b"</b>") == FormattedText(
        text, (MessageEntity(TYPE.BOLD, 0, 3),)
    )


@pytest.mark.parametrize(
    ("tag", "entity_type"),
    [
        (b"i", TYPE.ITALIC),
        (b"em", TYPE.ITALIC),
        (b"b", TYPE.BOLD),
        (b"strong", TYPE.BOLD),
        (b"s", TYPE.STRIKETHROUGH),
        (b"strike", TYPE.STRIKETHROUGH),
        (b"del", TYPE.STRIKETHROUGH),
        (b"u", TYPE.UNDERLINE),
        (b"ins", TYPE.UNDERLINE),
        (b"tg-spoiler", TYPE.SPOILER),
        (b"pre", TYPE.PRE),
        (b"code", TYPE.CODE),
        (b"blockquote", TYPE.BLOCK_QUOTE),
    ],
)
def test_gives_each_tag_its_entity(tag: bytes, entity_type: int) -> None:
    text = b"<" + tag + b">x</" + tag + b">"
    assert parse_html(text) == FormattedText(b"x", (MessageEntity(entity_type, 0, 1),))


def test_gives_a_span_of_the_class_tg_spoiler_a_spoiler() -> None:
    assert _entities(b'<span class="tg-spoiler">x</span>') == (
        MessageEntity(TYPE.SPOILER, 0, 1),
    )


@pytest.mark.parametrize(
    "attribute", [b" expandable", b' expandable="false"', b" expandable=1"]
)
def test_gives_a_blockquote_marked_expandable_its_entity(attribute: bytes) -> None:
    text = b"<blockquote" + attribute + b">x</blockquote>"
    assert _entities(text) == (MessageEntity(TYPE.EXPANDABLE_BLOCK_QUOTE, 0, 1),)


def test_reads_a_tag_name_in_any_case() -> None:
    assert _entities(b"<B>x</b><STRONG>y</Strong>") == (
        MessageEntity(TYPE.BOLD, 0, 1),
        MessageEntity(TYPE.BOLD, 1, 1),
    )


@pytest.mark.parametrize(
    "start_tag",
    [b"<i >", b"<i\n\t>", b"<i x>", b"<i x y>", b'<i x = "1" >', b"<i x\n=\ny>"],
)
def test_reads_spaces_and_attributes_it_ignores_in_a_start_tag(
    start_tag: bytes,
) -> None:
    assert parse_html(start_tag + b"x</i>") == FormattedText(
        b"x", (MessageEntity(TYPE.ITALIC, 0, 1),)
    )


def test_closes_an_element_with_an_empty_end_tag() -> None:
    assert _entities(b"<b>x</>") == (MessageEntity(TYPE.BOLD, 0, 1),)


def test_gives_no_entity_for_an_element_without_text() -> None:
    assert parse_html(b"<b></b>x") == FormattedText(b"x")


@pytest.mark.parametrize(
    "text",
    [
        b'<tg-emoji emoji-id="x"></tg-emoji>',
        b'<tg-time format="q"></tg-time>',
        b'<a href="ftp://x"></a>',
    ],
)
def test_checks_nothing_in_an_element_without_text(text: bytes) -> None:
    assert parse_html(text) == FormattedText(b"")


def test_reads_an_attribute_name_only_in_lowercase() -> None:
    # Without its href, the link is the text, which has no dot.
    assert parse_html(b'<a HREF="https://t.me">x</a>') == FormattedText(b"x")


@pytest.mark.parametrize(
    ("attribute", "language"),
    [(b'"language-PY"', b"PY"), (b"'language-PY'", b"PY"), (b"language-PY", b"py")],
)
def test_lowercases_only_an_unquoted_attribute_value(
    attribute: bytes, language: bytes
) -> None:
    text = b"<pre><code class=" + attribute + b">x</code></pre>"
    assert _entities(text) == (MessageEntity(TYPE.PRE_CODE, 0, 1, language),)


def test_decodes_references_in_a_quoted_attribute_value() -> None:
    assert _entities(b'<a href="t.me/?a=1&amp;b=&lt;">x</a>') == (
        MessageEntity(TYPE.TEXT_URL, 0, 1, b"http://t.me/?a=1&b=<"),
    )


def test_keeps_an_ampersand_that_starts_no_reference_in_an_attribute() -> None:
    assert _entities(b'<a href="t.me/?a&b=1">x</a>') == (
        MessageEntity(TYPE.TEXT_URL, 0, 1, b"http://t.me/?a&b=1"),
    )


def test_takes_the_last_of_repeated_attributes() -> None:
    text = b'<tg-time unix="5" unix="6" format="t" format="d">x</tg-time>'
    assert _entities(text) == (
        MessageEntity(TYPE.FORMATTED_DATE, 0, 1, date=6, date_flags=8),
    )


@pytest.mark.parametrize(
    ("href", "url"),
    [
        (b"https://t.me/x", b"https://t.me/x"),
        (b"HTTP://T.ME", b"http://t.me/"),
        (b"t.me", b"http://t.me/"),
        (b"tg:resolve?domain=a", b"tg://resolve?domain=a"),
        (b"ton://a", b"ton://a/"),
        (b"tonsite://a.ton", b"tonsite://a.ton/"),
        (b"tg://user?id=0", b"tg://user?id=0"),
        (b"tg://user?id=1099511627776", b"tg://user?id=1099511627776"),
    ],
)
def test_keeps_a_link_in_the_form_the_link_check_gives(href: bytes, url: bytes) -> None:
    text = b'<a href="' + href + b'">x</a>'
    assert _entities(text) == (MessageEntity(TYPE.TEXT_URL, 0, 1, url),)


@pytest.mark.parametrize("href", [b"ftp://t.me", b"http://a"])
def test_drops_a_link_the_link_check_refuses(href: bytes) -> None:
    assert parse_html(b'<a href="' + href + b'">x</a>') == FormattedText(b"x")


def test_mentions_the_user_a_tg_user_link_names() -> None:
    assert _entities(b'<a href="tg://user?id=5">x</a>') == (
        MessageEntity(TYPE.MENTION_NAME, 0, 1, user_id=5),
    )


@pytest.mark.parametrize("text", [b"<a>t.me/&lt;</a>", b'<a href="">t.me/&lt;</a>'])
def test_takes_the_text_as_the_link_without_an_href(text: bytes) -> None:
    assert _entities(text) == (MessageEntity(TYPE.TEXT_URL, 0, 6, b"http://t.me/<"),)


def test_takes_the_text_of_each_nested_link_without_an_href() -> None:
    assert _entities(b"<a><a>t.me</a>/x</a>") == (
        MessageEntity(TYPE.TEXT_URL, 0, 6, b"http://t.me/x"),
        MessageEntity(TYPE.TEXT_URL, 0, 4, b"http://t.me/"),
    )


@pytest.mark.parametrize(
    "text",
    [
        b'<pre><code class="language-py">x</code></pre>',
        b'<code class="language-py"><pre>x</pre></code>',
    ],
)
def test_merges_pre_and_code_with_a_language_into_a_code_block(text: bytes) -> None:
    assert _entities(text) == (MessageEntity(TYPE.PRE_CODE, 0, 1, b"py"),)


def test_keeps_pre_and_code_apart_without_a_language() -> None:
    assert _entities(b"<pre><code>x</code></pre>") == (
        MessageEntity(TYPE.PRE, 0, 1),
        MessageEntity(TYPE.CODE, 0, 1),
    )


def test_keeps_pre_and_code_apart_around_different_text() -> None:
    assert _entities(b'<pre>a<code class="language-py">x</code></pre>') == (
        MessageEntity(TYPE.PRE, 0, 2),
        MessageEntity(TYPE.CODE, 1, 1),
    )


def test_drops_the_language_of_code_outside_pre() -> None:
    assert _entities(b'<code class="language-py">x</code>') == (
        MessageEntity(TYPE.CODE, 0, 1),
    )


@pytest.mark.parametrize(
    ("emoji_id", "custom_emoji_id"),
    [(b"5", 5), (b"-5", -5), (b"9223372036854775807", (1 << 63) - 1)],
)
def test_gives_a_custom_emoji_its_id(emoji_id: bytes, custom_emoji_id: int) -> None:
    text = b'<tg-emoji emoji-id="' + emoji_id + b'">x</tg-emoji>'
    assert _entities(text) == (
        MessageEntity(TYPE.CUSTOM_EMOJI, 0, 1, custom_emoji_id=custom_emoji_id),
    )


@pytest.mark.parametrize(
    "emoji_id", [b"0", b"", b"x", b"05", b"+5", b"9223372036854775808"]
)
def test_refuses_a_custom_emoji_id_that_names_no_emoji(emoji_id: bytes) -> None:
    text = b'<tg-emoji emoji-id="' + emoji_id + b'">x</tg-emoji>'
    assert parse_html(text) == Failure(400, "Invalid custom emoji identifier specified")


def test_gives_a_date_its_unix_time_and_format() -> None:
    text = b'<tg-time unix="1700000000" format="wDT">x</tg-time>'
    assert _entities(text) == (
        MessageEntity(TYPE.FORMATTED_DATE, 0, 1, date=1_700_000_000, date_flags=52),
    )


@pytest.mark.parametrize(
    "attributes", [b' format="t"', b' unix="0"', b' unix="-5"', b' unix="x"']
)
def test_gives_no_date_without_a_positive_unix_time(attributes: bytes) -> None:
    assert parse_html(b"<tg-time" + attributes + b">x</tg-time>") == FormattedText(b"x")


def test_refuses_an_invalid_date_format_even_without_a_unix_time() -> None:
    assert parse_html(b'<tg-time format="q">x</tg-time>') == Failure(
        400, "Invalid date format used"
    )


def test_wraps_a_unix_time_around_32_bits() -> None:
    assert _entities(b'<tg-time unix="4294967297">x</tg-time>') == (
        MessageEntity(TYPE.FORMATTED_DATE, 0, 1, date=1),
    )


def test_reads_an_unquoted_format_in_lowercase() -> None:
    assert _entities(b"<tg-time unix=5 format=T>x</tg-time>") == (
        MessageEntity(TYPE.FORMATTED_DATE, 0, 1, date=5, date_flags=2),
    )


@pytest.mark.parametrize(
    ("text", "message"),
    [
        (b"a<b", "Unclosed start tag at byte offset 1"),
        (b"<", "Unclosed start tag at byte offset 0"),
        (b"<b\x00>x</b>", "Unclosed start tag at byte offset 0"),
        (b"<FOO>", 'Unsupported start tag "foo" at byte offset 0'),
        (b"<>", 'Unsupported start tag "" at byte offset 0'),
        (b"<b/>", 'Unsupported start tag "b/" at byte offset 0'),
        (b"<b />", 'Empty attribute name in the tag "b" at byte offset 0'),
        (b'<b "x">', 'Empty attribute name in the tag "b" at byte offset 0'),
        (b"<b x", 'Unclosed start tag "b" at byte offset 0'),
        (b"<b x= ", 'Unclosed start tag "b" at byte offset 0'),
        (b"<b x=y/>", "Unexpected end of name token at byte offset 5"),
        (b'<b x="y', "Unclosed start tag at byte offset 0"),
        (b"<b x=y\x00>", "Unclosed start tag at byte offset 0"),
        (b"<span>x</span>", 'Tag "span" must have class "tg-spoiler" at byte offset 0'),
        (
            b'<span class="TG-spoiler">x</span>',
            'Tag "span" must have class "tg-spoiler" at byte offset 0',
        ),
        (b"</b>", "Unexpected end tag at byte offset 0"),
        (b"<b>x</b", "Unclosed end tag at byte offset 4"),
        (b"<b>x</ b>", "Unclosed end tag at byte offset 4"),
        (
            b"<b>x</i>",
            'Unmatched end tag at byte offset 4, expected "</b>", found "</i>"',
        ),
        (b"<b><i>x</i>", 'Can\'t find end tag corresponding to start tag "b"'),
    ],
)
def test_refuses_malformed_html(text: bytes, message: str) -> None:
    assert parse_html(text) == Failure(400, message)


@pytest.mark.parametrize(
    ("text", "message"),
    [
        (b"<\xff>", b'Unsupported start tag "\xff" at byte offset 0'),
        (
            b"<b>x</\xff>",
            b'Unmatched end tag at byte offset 4, expected "</b>", found "</\xff>"',
        ),
    ],
)
def test_quotes_a_tag_name_that_is_not_utf8_byte_for_byte(
    text: bytes, message: bytes
) -> None:
    result = parse_html(text)
    assert isinstance(result, Failure)
    assert result.message.encode("utf-8", "surrogateescape") == message


def test_parses_a_text_far_over_the_bot_api_cap() -> None:
    text = b"a" * 100_000
    assert parse_html(b"<b>" + text + b"</b>") == FormattedText(
        text, (MessageEntity(TYPE.BOLD, 0, 100_000),)
    )


def test_parses_5000_nested_tags() -> None:
    text = b"<b>" * 5000 + b"x" + b"</b>" * 5000
    assert parse_html(text) == FormattedText(
        b"x", (MessageEntity(TYPE.BOLD, 0, 1),) * 5000
    )


def test_marks_a_tie_of_links_nested_in_a_longer_element() -> None:
    tie = (
        MessageEntity(TYPE.TEXT_URL, 1, 1, b"http://b.com/"),
        MessageEntity(TYPE.TEXT_URL, 1, 1, b"http://a.com/"),
    )
    text = b'<i>y<a href="a.com"><a href="b.com">x</a></a></i>'
    assert _entities(text) == (
        MessageEntity(TYPE.ITALIC, 0, 2),
        *(replace(entity, ties=tie) for entity in tie),
    )
