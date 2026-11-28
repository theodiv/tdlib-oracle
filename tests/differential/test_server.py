import re
from collections.abc import Callable
from dataclasses import replace

import pytest

from tdlib_oracle import Entity, Refusal, Verdict, check
from tdlib_oracle.botapi.client import get_error_description
from tdlib_oracle.runtime.failure import Failure, decode_quoted
from tests.support.markup import TAGS, draw_html, draw_markdown
from tests.support.texts import INVALID_UNITS, PLAIN_UNITS, draw_texts

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

# The parse modes a bot names, by the index the harness reads them by.
_PARSE_MODES = (None, "HTML", "Markdown", "MarkdownV2")

# The Bot API's name for the type of each object TDLib sends an entity as.
_TYPES = {
    b"messageEntityBold": "bold",
    b"messageEntityItalic": "italic",
    b"messageEntityUnderline": "underline",
    b"messageEntityStrike": "strikethrough",
    b"messageEntitySpoiler": "spoiler",
    b"messageEntityCode": "code",
    b"messageEntityPre": "pre",
    b"messageEntityTextUrl": "text_link",
    b"inputMessageEntityMentionName": "text_mention",
    b"messageEntityCustomEmoji": "custom_emoji",
    b"messageEntityBlockquote": "blockquote",
    b"messageEntityFormattedDate": "date_time",
}

# HTML texts that reach what generated texts may miss: every tag, ties in the sort,
# entities that the entities TDLib finds split, more entities than TDLib sends, kept
# texts at and past 4,096 code points, cleaning and trimming around entities, refusals
# of the markup and of the values of its tags, values that a reference to a surrogate
# leaves invalid, links that cleaning turns into a mention or leaves invalid, and
# languages that cleaning empties or shortens.
_FIXED_HTML = (
    tuple(unit for start, end in TAGS for unit in (start, b"x", end)),
    (b"<i>y", *(b'<a href="t.me/a"><a href="t.me/b">x</a></a>',) * 8, b"</i>"),
    (b"<blockquote><blockquote expandable>x</blockquote></blockquote><b>y</b>",),
    (b"<b>see #tag here</b>",),
    (b"<i>a #b @cccccc /d t.me/e $USD f@g.hi</i> <u>https://t.me/x</u>",),
    (b"<code>x</code> " * 101,),
    (b'<tg-emoji emoji-id="5">x</tg-emoji>' * 120, b"<b>y</b>"),
    (b"<b>x</b> <code>y</code> " * 60,),
    (b"<b>" + b"a" * 4096 + b"</b>",),
    (b"<b>" + b"a" * 4097 + b"</b>",),
    (b"<i>" + "\U0001f600".encode() * 4096 + b"</i>  ",),
    (b"  <b> a </b>  ",),
    (b"\n<i>\n</i>x",),
    ("<b>a\r\nb\x00c\u200e\u200eb</b>".encode(),),
    ("<b>\u200b</b>".encode(),),
    (b"&lt;b&gt;<s>&amp;</s>",),
    (b"<abbr>x</abbr>",),
    (b"<b>x</i>",),
    (b"<b>x",),
    (b'<a href="tg://user?id=5">a</a> <a href="tg://user?id=0">b</a>',),
    (b'<tg-emoji emoji-id="0">x</tg-emoji>',),
    (b'<tg-time unix="0" format="t">x</tg-time>',),
    (b'<pre><code class="language-python">x</code></pre> <pre>y</pre>',),
    (b'<pre><code class="language-&#xd800;">x</code></pre>',),
    (b'<a href="t.me/&#xd800;">x</a>',),
    (b'<a href="tg://user?id=5&#x2028;">x</a>',),
    (b'<a href=".&#x2028;">x</a>',),
    (b'<pre><code class="language-&#x202b;">x</code></pre>',),
    (b'<pre><code class="language-a&#x202b;">x</code></pre>',),
)

# MarkdownV2 texts the same way: every entity, ties in the sort, links without a URL
# nested 40 deep, more entities than TDLib sends, kept texts at and past 4,096 code
# points, cleaning and trimming around entities, each refusal of the markup, a link that
# cleaning turns into a mention, and a language that cleaning empties.
_FIXED_MARKDOWN_V2 = (
    (
        b"*a* _b_ __c__ ~d~ ||e|| `f` ```g``` ```python\nh``` [i](t.me/i)",
        b" [j](tg://user?id=5) ![k](tg://emoji?id=5)",
        b" ![l](tg://time?unix=1700000000&format=wDT)\n>m\n>n||",
    ),
    (b">m\n>n\no",),
    (b"_y", *(b"[[x](t.me/a)](t.me/b)",) * 8, b"_"),
    (b"[" * 40 + b"t\\.me" + b"]" * 40,),
    (b"`x` " * 101,),
    (b"![x](tg://emoji?id=5)" * 120, b"*y*"),
    (b"*" + b"a" * 4096 + b"*",),
    (b"*" + b"a" * 4097 + b"*",),
    (b"  * a *  ",),
    ("*a\r\nb\x00c\u200e\u200eb*".encode(),),
    (b"a.b",),
    (b"*x",),
    (b"[a](t.me",),
    (b"![x]",),
    (b"![x](t.me)",),
    ("[x](tg://user?id=5\u2028)".encode(),),
    ("```\u202b x```".encode(),),
)

# Legacy Markdown texts the same way: every entity, a link without a URL after dropped
# bytes, more entities than TDLib sends, kept texts at and past the limit, cleaning and
# trimming around entities, each refusal of the markup, a link that cleaning turns into
# a mention, and languages that cleaning empties.
_FIXED_MARKDOWN = (
    (
        b"*a* _b_ `c` ```d``` ```python\ne``` [f](t.me/f) [g](tg://user?id=5)",
        b" [t.me]",
    ),
    (b"*a*[b](c)[telegram.org]",),
    (b"`x` " * 101,),
    (b"*" + b"a" * 4096 + b"*",),
    (b"*" + b"a" * 4097 + b"*",),
    (b"  * a *  ",),
    ("*a\r\nb\x00c\u200e\u200eb*".encode(),),
    (b"*x",),
    (b"[x",),
    ("[x](tg://user?id=5\u2028)".encode(),),
    ("```\u202b ```y".encode(),),
    ("`````````\u033f\r|```".encode(),),
)

# Plain texts the same way: tags that stay text, and texts at and past the limit.
_FIXED_PLAIN = (
    (b"<b>x</b>",),
    (b"a" * 4096,),
    (b"a" * 4097,),
    (b" \r\n\t x \n",),
)


def _port(text: bytes, args: tuple[int, ...]) -> Verdict | None:
    """Return the verdict on `text`, or `None` for an empty text.

    The Bot API server refuses an empty text before TDLib sees it, so the harness has no
    answer to hold that verdict against.
    """
    if not text:
        return None
    return check(text, parse_mode=_PARSE_MODES[args[0]])


def _offset(message: bytes) -> int | None:
    """Return the byte offset that a refusal of the markup names, or `None`."""
    if not message.startswith(b"Can't parse entities: "):
        return None
    match = re.search(rb" at byte offset (\d+)", message)
    return None if match is None else int(match[1])


def _date_time_format(flags: int) -> str:
    """Return the Bot API's format of a date that TDLib sends with `flags`."""
    if flags == 0:
        return ""
    if flags & 1:
        return "r"
    date = "d" if flags & 8 else "D" if flags & 16 else ""
    time = "t" if flags & 2 else "T" if flags & 4 else ""
    return ("w" if flags & 32 else "") + date + time


def _entity(fields: tuple[bytes, ...]) -> Entity:
    """Return the entity the Bot API shows for the fields of an object TDLib sends."""
    constructor, offset, length, text, number, flags = fields
    entity = Entity(type=_TYPES[constructor], offset=int(offset), length=int(length))
    value = text.decode("utf-8", "replace")
    match entity.type:
        case "pre":
            return replace(entity, language=value or None)
        case "text_link":
            return replace(entity, url=value)
        case "text_mention":
            return replace(entity, user_id=int(number), depends_on_backend=True)
        case "custom_emoji":
            return replace(
                entity, custom_emoji_id=number.decode(), depends_on_backend=True
            )
        case "blockquote" if flags == b"1":
            return replace(entity, type="expandable_blockquote")
        case "date_time":
            return replace(
                entity,
                unix_time=int(number),
                date_time_format=_date_time_format(int(flags)),
            )
    return entity


def _matches(verdict: Verdict | None, theirs: tuple[bytes, ...]) -> bool:
    """Return whether the harness answered with `verdict`, ties allowed for."""
    if verdict is None:
        return True
    code, message, text, *sent = theirs
    if code != b"0":
        description = get_error_description(Failure(int(code), decode_quoted(message)))
        refused = Verdict(
            accepted=False,
            text=None,
            entities=(),
            refusal=Refusal(description=description, offset=_offset(message)),
            depends_on_backend=False,
        )
        return not sent and verdict == refused

    if verdict.text is None or verdict.text.encode() != text:
        return False
    if verdict.refusal is not None or len(sent) != 6 * len(verdict.entities):
        return False
    entities = [_entity(tuple(sent[i : i + 6])) for i in range(0, len(sent), 6)]
    for ours, pinned in zip(verdict.entities, entities, strict=True):
        if ours.depends_on_build:
            # Another C++ library may keep another entity of the tie, with these bounds.
            if (ours.offset, ours.length) != (pinned.offset, pinned.length):
                return False
        elif ours != pinned:
            return False

    build = any(entity.depends_on_build for entity in verdict.entities)
    marked = verdict.entities if build else tuple(entities)
    return (
        verdict.accepted
        and verdict.depends_on_build == build
        and verdict.depends_on_backend == any(e.depends_on_backend for e in marked)
    )


def _cases(
    texts: list[tuple[bytes, ...]], parse_mode: str | None
) -> list[tuple[tuple[bytes, ...], tuple[int, ...]]]:
    """Return each text, in `parse_mode`, for a bot of one session and of more."""
    mode = _PARSE_MODES.index(parse_mode)
    return [
        (text, (mode, skip_new_entities))
        for text in texts
        for skip_new_entities in (0, 1)
    ]


def test_check_gives_the_pinned_verdict_on_html_texts(
    compare_by: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = _cases(draw_html(seed, count), "HTML")
        compare_by("send_message", _port, _matches, cases, seed=seed, by_bytes=False)


def test_check_gives_the_pinned_verdict_on_markdown_v2_texts(
    compare_by: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = _cases(draw_markdown(seed, count), "MarkdownV2")
        compare_by("send_message", _port, _matches, cases, seed=seed, by_bytes=True)


def test_check_gives_the_pinned_verdict_on_markdown_texts(
    compare_by: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = _cases(draw_markdown(seed, count, legacy=True), "Markdown")
        compare_by("send_message", _port, _matches, cases, seed=seed, by_bytes=True)


def test_check_gives_the_pinned_verdict_on_plain_texts(
    compare_by: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        texts = draw_texts(seed, count, (*PLAIN_UNITS, *INVALID_UNITS))
        compare_by(
            "send_message",
            _port,
            _matches,
            _cases(texts, None),
            seed=seed,
            by_bytes=True,
        )


def test_check_gives_the_pinned_verdict_on_the_fixed_texts(compare_by: Compare) -> None:
    cases = [
        *_cases(list(_FIXED_HTML), "HTML"),
        *_cases(list(_FIXED_MARKDOWN_V2), "MarkdownV2"),
        *_cases(list(_FIXED_MARKDOWN), "Markdown"),
        *_cases(list(_FIXED_PLAIN), None),
    ]
    compare_by("send_message", _port, _matches, cases, seed=None, by_bytes=False)
