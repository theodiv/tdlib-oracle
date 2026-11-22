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
    assert entity.depends_on_build is False


def test_verdict_depends_on_no_build_by_default() -> None:
    assert _accepted("a").depends_on_build is False


def test_parses_html_into_the_entities_tdlib_sends(sent: Sent) -> None:
    verdict = check(sent("<b>bold</b> and <i>it</i>"), parse_mode="HTML")
    assert verdict == Verdict(
        accepted=True,
        text="bold and it",
        entities=(
            Entity(type="bold", offset=0, length=4),
            Entity(type="italic", offset=9, length=2),
        ),
        refusal=None,
        depends_on_backend=False,
    )


@pytest.mark.parametrize("parse_mode", ["HTML", "html", "hTmL"])
def test_reads_the_html_parse_mode_in_any_letter_case(parse_mode: str) -> None:
    verdict = check("<s>x</s>", parse_mode=parse_mode)
    assert verdict.entities == (Entity(type="strikethrough", offset=0, length=1),)


@pytest.mark.parametrize("parse_mode", [None, "", "none", "NONE"])
def test_parses_nothing_without_a_parse_mode(parse_mode: str | None) -> None:
    assert check("<b>x</b>", parse_mode=parse_mode) == _accepted("<b>x</b>")


@pytest.mark.parametrize("parse_mode", ["BBCode", "htm", " HTML", "MarkdownV3"])
def test_refuses_any_other_parse_mode(parse_mode: str) -> None:
    verdict = check("<b>x</b>", parse_mode=parse_mode)
    assert verdict == _refused("Bad Request: unsupported parse_mode")


def test_checks_emptiness_and_size_before_the_parse_mode() -> None:
    assert check("", parse_mode="BBCode") == _refused(_EMPTY)
    assert check("a" * 32769, parse_mode="BBCode") == _refused(_TOO_LONG)


def test_refuses_html_that_is_not_utf8() -> None:
    verdict = check(b"\xff<b>x</b>", parse_mode="HTML")
    assert verdict == _refused("Bad Request: text must be encoded in UTF-8")


@pytest.mark.parametrize(
    ("text", "message", "offset"),
    [
        ("<abbr>x</abbr>", 'Unsupported start tag "abbr" at byte offset 0', 0),
        (
            "\N{EURO SIGN}<b>x</i>",
            'Unmatched end tag at byte offset 7, expected "</b>", found "</i>"',
            7,
        ),
        ("<b>x", 'Can\'t find end tag corresponding to start tag "b"', None),
    ],
)
def test_refuses_markup_naming_the_byte_offset_the_description_names(
    text: str, message: str, offset: int | None
) -> None:
    description = f"Bad Request: can't parse entities: {message}"
    verdict = check(text, parse_mode="HTML")
    assert verdict.refusal == Refusal(description=description, offset=offset)


def test_keeps_the_value_of_each_type_in_the_bot_apis_form() -> None:
    text = (
        '<pre><code class="language-python">p</code></pre>'
        '<a href="https://t.me/x">l</a>'
        '<tg-time unix="1700000000" format="wDT">d</tg-time>'
        "<blockquote expandable>q</blockquote>"
    )
    assert check(text, parse_mode="HTML").entities == (
        Entity(type="pre", offset=0, length=1, language="python"),
        Entity(type="text_link", offset=1, length=1, url="https://t.me/x"),
        Entity(
            type="date_time",
            offset=2,
            length=1,
            unix_time=1700000000,
            date_time_format="wDT",
        ),
        Entity(type="expandable_blockquote", offset=3, length=1),
    )


def test_marks_the_entities_whose_survival_telegrams_backend_decides() -> None:
    text = (
        '<tg-emoji emoji-id="5368324170671202286">\N{THUMBS UP SIGN}</tg-emoji>'
        ' <a href="tg://user?id=123">Bob</a> <b>!</b>'
    )
    verdict = check(text, parse_mode="HTML")
    assert verdict.entities == (
        Entity(
            type="custom_emoji",
            offset=0,
            length=2,
            custom_emoji_id="5368324170671202286",
            depends_on_backend=True,
        ),
        Entity(
            type="text_mention",
            offset=3,
            length=3,
            user_id=123,
            depends_on_backend=True,
        ),
        Entity(type="bold", offset=7, length=1),
    )
    assert verdict.depends_on_backend is True
    assert verdict.depends_on_build is False


def test_marks_the_entity_a_sort_keeps_of_a_tie() -> None:
    # Closing <i> last leaves the entities out of order, so std::sort meets the two
    # links, which tie, and the C++ library decides which comes first.
    verdict = check(
        '<i>y<a href="t.me/a"><a href="t.me/b">x</a></a></i>', parse_mode="HTML"
    )
    assert verdict.entities == (
        Entity(
            type="text_link",
            offset=1,
            length=1,
            url="http://t.me/b",
            depends_on_build=True,
        ),
        Entity(type="italic", offset=0, length=2),
    )
    assert verdict.depends_on_build is True
    assert verdict.depends_on_backend is False


def test_leaves_a_tie_unmarked_where_no_sort_meets_it() -> None:
    verdict = check('<a href="t.me/a"><a href="t.me/b">x</a></a>', parse_mode="HTML")
    assert verdict.entities == (
        Entity(type="text_link", offset=0, length=1, url="http://t.me/b"),
    )
    assert verdict.depends_on_build is False


def test_sends_splittable_entities_whole_and_last() -> None:
    verdict = check("<b>a</b><b>#b</b> <code>c</code>", parse_mode="HTML")
    assert verdict.entities == (
        Entity(type="code", offset=4, length=1),
        Entity(type="bold", offset=0, length=3),
    )


def test_sends_at_most_100_entities_besides_custom_emoji() -> None:
    text = "<code>x</code> " * 101 + '<tg-emoji emoji-id="5">y</tg-emoji>'
    types = [entity.type for entity in check(text, parse_mode="HTML").entities]
    assert types.count("code") == 100
    assert types.count("custom_emoji") == 1


@pytest.mark.parametrize("parse_mode", ["Markdown", "MarkdownV2", "markdownv2"])
def test_raises_value_error_for_a_markdown_parse_mode(parse_mode: str) -> None:
    with pytest.raises(ValueError, match=r"^parse_mode '\w+' is not supported yet$"):
        check("*x*", parse_mode=parse_mode)


@pytest.mark.parametrize("parse_mode", [b"HTML", 1, ["HTML"]])
def test_raises_type_error_for_a_parse_mode_of_another_type(parse_mode: object) -> None:
    with pytest.raises(TypeError, match=r"^parse_mode must be str or None, not "):
        check("x", parse_mode=parse_mode)  # type: ignore[arg-type]  # the wrong type is the point


@pytest.mark.parametrize(
    ("text", "description"),
    [
        (
            '<pre><code class="language-&#xd800;">x</code></pre>',
            "Bad Request: messageEntityPreCode.language must be encoded in UTF-8",
        ),
        (
            '<a href="t.me/&#xd800;">x</a>',
            "Bad Request: messageEntityTextUrl.url must be encoded in UTF-8",
        ),
    ],
)
def test_refuses_a_value_that_a_reference_to_a_surrogate_leaves_invalid(
    text: str, description: str
) -> None:
    assert check(text, parse_mode="HTML") == _refused(description)


def test_turns_a_link_that_cleaning_makes_a_user_link_into_a_mention() -> None:
    # The parser keeps the link as it is; TDLib cleans it before it reads the user.
    verdict = check('<a href="tg://user?id=5&#x2028;">x</a>', parse_mode="HTML")
    assert verdict.entities == (
        Entity(
            type="text_mention",
            offset=0,
            length=1,
            user_id=5,
            depends_on_backend=True,
        ),
    )
