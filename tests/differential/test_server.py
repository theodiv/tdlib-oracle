import re
from collections.abc import Callable
from dataclasses import replace

import pytest

from tdlib_oracle import Entity, Refusal, Verdict, check
from tdlib_oracle.botapi.client import get_error_description
from tdlib_oracle.runtime.failure import Failure, decode_quoted
from tests.support.markup import TAGS, draw_html
from tests.support.texts import INVALID_UNITS, PLAIN_UNITS, draw_texts

pytestmark = pytest.mark.differential

Compare = Callable[..., None]

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
    return check(text, parse_mode="HTML" if args[0] else None)


def _offset(message: bytes) -> int | None:
    """Return the byte offset that a refusal of the markup names, or `None`."""
    if not message.startswith(b"Can't parse entities: "):
        return None
    match = re.search(rb" at byte offset (\d+)", message)
    return None if match is None else int(match[1])


def _date_time_format(flags: int) -> str:
    """Return the Bot API's format of a date that TDLib sends with `flags`.

    A relative date shows `r`, whatever the other flags; of a short and a long date or
    time, the short one shows.
    """
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
    texts: list[tuple[bytes, ...]], html: int
) -> list[tuple[tuple[bytes, ...], tuple[int, ...]]]:
    """Return each text with a bot of one session and with a bot of more."""
    return [
        (text, (html, skip_new_entities))
        for text in texts
        for skip_new_entities in (0, 1)
    ]


def test_check_gives_the_pinned_verdict_on_html_texts(
    compare_by: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        cases = _cases(draw_html(seed, count), 1)
        compare_by("send_message", _port, _matches, cases, seed=seed, by_bytes=False)


def test_check_gives_the_pinned_verdict_on_plain_texts(
    compare_by: Compare, seeds: tuple[int, ...], count: int
) -> None:
    for seed in seeds:
        texts = draw_texts(seed, count, (*PLAIN_UNITS, *INVALID_UNITS))
        compare_by(
            "send_message", _port, _matches, _cases(texts, 0), seed=seed, by_bytes=True
        )


def test_check_gives_the_pinned_verdict_on_the_fixed_texts(compare_by: Compare) -> None:
    cases = [*_cases(list(_FIXED_HTML), 1), *_cases(list(_FIXED_PLAIN), 0)]
    compare_by("send_message", _port, _matches, cases, seed=None, by_bytes=False)
